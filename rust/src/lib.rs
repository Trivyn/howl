//! Rust bindings for HOWL, a consequence-based description-logic reasoner.
//!
//! HOWL classifies a description logic — the complete subsumption
//! hierarchy and coherence of a TBox — including the defined-class
//! entailments that OWL 2 RL materialization structurally cannot see.
//!
//! ```no_run
//! use howl::{Input, Reasoner, Verdict};
//!
//! let mut input = Input::new();
//! input.add_turtle(&std::fs::read_to_string("ontology.ttl").unwrap()).unwrap();
//! let report = Reasoner::new().classify(&input).unwrap();
//! match report.verdict {
//!     Verdict::Coherent => println!("coherent"),
//!     Verdict::Incoherent => println!("unsatisfiable: {:?}", report.unsatisfiable),
//!     // NOT a pass: something was omitted or the run stopped early.
//!     Verdict::Inconclusive => println!("omitted: {:?}", report.omissions),
//! }
//! ```
//!
//! # What crosses the FFI
//!
//! HOWL's first consumer calls it through an FFI behind a reasoner
//! port, so **the port, not the CLI, is the deliverable** (SPEC §8.4).
//! This crate binds HOWL's public C API, which is written in SLOP (the
//! `:c-name` functions in `src/howl.slop`) and whose header slop
//! generates (`include/howl.h`). The engine's results never cross as
//! structs: they stay behind an opaque run handle, and this crate copies
//! what it needs out through the API's accessors. Only the API's small
//! value types are mirrored, and the layout guards in [`ffi`] assert them
//! against the header — see that module for the GROWL 0.6.0 regression
//! they exist to prevent.
//!
//! An [`Input`] is encoded exactly as the `howl` CLI encodes its files,
//! and classified by the same engine path, so the CLI's committed golden
//! reports certify this crate's [`Report::lines`] byte for byte.

pub mod ffi;

// The engine's C references slop-rdf and the slop runtime; these keep
// their native archives on the link line.
extern crate slop_rdf_sys as _;
extern crate slop_std_sys as _;

use std::collections::HashMap;
use std::fmt;
use std::os::raw::c_int;
use std::sync::atomic::{AtomicU32, Ordering};
use std::sync::Arc;

/// How a run failed to produce a report.
///
/// Distinct from a report with no findings: these produce no result to
/// read a verdict from.
#[derive(Debug, Clone, PartialEq, Eq)]
pub enum Fault {
    /// Cancellation was observed at a round boundary.
    ///
    /// Carries no payload: a cancelled run stops at a
    /// scheduler-dependent point, so its partial state is not
    /// reproducible and must never be serialized or hashed.
    Cancelled,
    /// Unparseable or structurally malformed input.
    InputError(String),
    /// An explicit request for a profile whose calculus is not built
    /// yet, or that was dropped from the ladder. Refused, never quietly
    /// run as another profile: that would classify a smaller theory than
    /// asked for, under the wrong name.
    ProfileUnavailable(Profile),
    /// A [`Config`] field outside the range the engine accepts.
    InvalidConfig(String),
}

impl fmt::Display for Fault {
    #[allow(deprecated)]
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Fault::Cancelled => write!(f, "cancelled"),
            Fault::InputError(m) => write!(f, "input error: {m}"),
            // The engine's own texts (select.slop, `unavailable-message`),
            // pinned on both sides.
            Fault::ProfileUnavailable(Profile::HornSriq) => {
                write!(f, "profile horn-sriq was dropped; sriq covers its language")
            }
            Fault::ProfileUnavailable(p) => {
                write!(f, "profile {} is not implemented yet (implemented: el, el++)", p.name())
            }
            Fault::InvalidConfig(m) => write!(f, "invalid config: {m}"),
        }
    }
}

impl std::error::Error for Fault {}

/// The verdict a completed run licenses (SPEC §6.2).
///
/// The mapping from a report to a verdict is asymmetric, and the
/// asymmetry falls out of monotonicity rather than being a compromise:
/// restoring an omitted axiom can only *add* conclusions, never retract
/// one, so a contradiction derived from a subset of the ontology is a
/// contradiction in the whole ontology. A finding is definitive
/// whatever the coverage; it is the *absence* of a finding that carries
/// no information.
///
/// The engine computes it; this crate never recomputes it.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Verdict {
    /// Checked completely, nothing found.
    Coherent,
    /// Inconsistent, or at least one unsatisfiable named class.
    /// Definitive even under partial coverage.
    Incoherent,
    /// Could not check completely. **Not a pass.**
    Inconclusive,
}

impl Verdict {
    /// The `howl` CLI's exit code for this verdict: 0, 1 or 2.
    pub fn exit_code(self) -> i32 {
        match self {
            Verdict::Coherent => 0,
            Verdict::Incoherent => 1,
            Verdict::Inconclusive => 2,
        }
    }
}

/// A rung of the profile ladder (SPEC §5.1): each is complete for
/// exactly the logic it names, and no wider label.
///
/// | Profile | Logic | Worst case | Built |
/// |---|---|---|---|
/// | [`El`](Profile::El) | ELH⊥R+ + domain/range + ABox | PTIME | yes |
/// | [`ElPlusPlus`](Profile::ElPlusPlus) | the OWL 2 EL object fragment | PTIME | yes |
/// | [`Sriq`](Profile::Sriq) | SRIQ object fragment with ABox (SPEC §5.5) | 2ExpTime without an ABox; with one, a triple-exponential bound | not yet |
///
/// Asking for an unbuilt rung is [`Fault::ProfileUnavailable`].
/// [`HornSriq`](Profile::HornSriq) was dropped from the ladder (SPEC §5);
/// it keeps its place so the C enum is not renumbered, and is always
/// refused. The enum is `#[non_exhaustive]`: a later rung (`sroiq`) is
/// added at the end.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
#[non_exhaustive]
pub enum Profile {
    El,
    ElPlusPlus,
    #[deprecated(
        since = "0.2.0",
        note = "dropped from the ladder (SPEC §5): always Fault::ProfileUnavailable; Sriq covers its language"
    )]
    HornSriq,
    Sriq,
}

#[allow(deprecated)]
impl Profile {
    /// The name the CLI flag and the report use.
    pub fn name(self) -> &'static str {
        match self {
            Profile::El => "el",
            Profile::ElPlusPlus => "el++",
            Profile::HornSriq => "horn-sriq",
            Profile::Sriq => "sriq",
        }
    }

    fn to_ffi(self) -> c_int {
        match self {
            Profile::El => ffi::PROFILE_EL,
            Profile::ElPlusPlus => ffi::PROFILE_EL_PLUS_PLUS,
            Profile::HornSriq => ffi::PROFILE_HORN_SRIQ,
            Profile::Sriq => ffi::PROFILE_SRIQ,
        }
    }

    /// From a C `types_Profile`, as an accessor returns it.
    fn from_ffi(d: c_int) -> Self {
        match d {
            ffi::PROFILE_EL => Profile::El,
            ffi::PROFILE_EL_PLUS_PLUS => Profile::ElPlusPlus,
            ffi::PROFILE_HORN_SRIQ => Profile::HornSriq,
            ffi::PROFILE_SRIQ => Profile::Sriq,
            d => panic!("the engine returned profile {d}"),
        }
    }
}

/// Which calculus a run uses.
///
/// The default is `Explicit(Profile::El)`, not `Auto`: a default run
/// keeps one cost class and one theory across upgrades. `Auto` picks
/// the cheapest built profile containing the whole ontology; the
/// [`Report`] names the one that ran.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum ProfileSelection {
    Auto,
    Explicit(Profile),
}

/// Reasoner configuration.
///
/// Mirrors the engine's own defaults rather than inventing new ones, so
/// the two cannot drift. There is deliberately no `strict` field: the
/// library always runs non-strict — an omission is a report, not a
/// refusal (SPEC §8.4). The engine checks the ranges; a value outside
/// one is [`Fault::InvalidConfig`].
#[derive(Debug, Clone, Copy)]
pub struct Config {
    /// Worker threads, `1..=64`. The report is identical at every count.
    pub worker_count: u8,
    /// Permits `n` **completed global rounds**, `0..=10000`. The
    /// fixpoint check happens at a round boundary *before* consuming
    /// budget for the next round, so reaching the answer exactly on
    /// budget is success. `0` performs no rounds and always yields an
    /// incomplete run.
    pub max_iterations: u16,
    /// The calculus.
    pub selection: ProfileSelection,
}

impl Default for Config {
    fn default() -> Self {
        // Read the defaults across the FFI rather than restating them,
        // so a change on the engine side cannot silently disagree with
        // this crate.
        let o = unsafe { ffi::howl_default_options() };
        Config {
            worker_count: o.workers as u8,
            max_iterations: o.max_iterations as u16,
            selection: if o.auto_select != 0 {
                ProfileSelection::Auto
            } else {
                ProfileSelection::Explicit(Profile::from_ffi(o.profile))
            },
        }
    }
}

impl Config {
    fn to_ffi(self, cancel: i64) -> ffi::Options {
        let (profile, auto_select) = match self.selection {
            ProfileSelection::Auto => (ffi::PROFILE_EL, 1),
            ProfileSelection::Explicit(p) => (p.to_ffi(), 0),
        };
        ffi::Options {
            workers: self.worker_count as i64,
            max_iterations: self.max_iterations as i64,
            profile,
            auto_select,
            cancel,
        }
    }
}

/// An RDF term.
///
/// Blank-node labels are scoped to the document they are added in, as
/// in Turtle: `_:b` in two documents names two nodes.
#[derive(Debug, Clone, PartialEq, Eq, Hash)]
pub enum Term {
    Iri(String),
    Blank(String),
    Literal {
        value: String,
        datatype: Option<String>,
        lang: Option<String>,
    },
}

impl Term {
    pub fn iri(s: impl Into<String>) -> Term {
        Term::Iri(s.into())
    }

    pub fn blank(label: impl Into<String>) -> Term {
        Term::Blank(label.into())
    }

    pub fn literal(value: impl Into<String>) -> Term {
        Term::Literal { value: value.into(), datatype: None, lang: None }
    }
}

/// The ontology to classify: one or more documents, plus the caller's
/// attestation of which `owl:imports` they resolve.
///
/// Each `add_*` call is one document. Every document after the first
/// has its blank nodes standardized apart from the ones before it, as
/// `howl validate ROOT -I IMPORT` does.
pub struct Input {
    raw: ffi::Input,
}

// The handle owns its arena outright and the engine keeps no thread
// affinity, so it may move between threads. It is not `Sync`: adding a
// document mutates it.
unsafe impl Send for Input {}

impl Input {
    pub fn new() -> Self {
        Input { raw: unsafe { ffi::howl_input_new() } }
    }

    /// Add one document given as triples.
    pub fn add_triples(&mut self, triples: &[(Term, Term, Term)]) {
        let mut blanks: HashMap<&str, i64> = HashMap::new();
        unsafe { ffi::howl_input_begin_document(self.raw) };
        for (s, p, o) in triples {
            let (s, p, o) = (term_in(s, &mut blanks), term_in(p, &mut blanks), term_in(o, &mut blanks));
            // Every Term this crate can build is one HOWL takes, so this
            // never refuses; were it to, the engine refuses the input and
            // classify says so.
            unsafe { ffi::howl_input_add_triple(self.raw, s, p, o) };
        }
    }

    /// Add one document given as Turtle.
    ///
    /// A document that does not parse is an [`Fault::InputError`], and
    /// so is every later [`Reasoner::classify`] of this input: the
    /// triples before the error were already added.
    pub fn add_turtle(&mut self, text: &str) -> Result<(), Fault> {
        let r = unsafe { ffi::howl_input_add_turtle(self.raw, ffi::SlopString::borrow(text)) };
        if r.ok != 0 {
            return Ok(());
        }
        Err(Fault::InputError(format!(
            "Turtle does not parse at line {}, column {}: {}",
            r.line,
            r.column,
            unsafe { owned(r.message) }
        )))
    }

    /// Attest that `iri`, an `owl:imports` target, is resolved: its
    /// document has been added.
    ///
    /// HOWL is network-free and cannot resolve imports itself, so a
    /// declared import missing from the attestation is a coverage
    /// omission and the run is inconclusive. Be precise about what that
    /// catches: **forgetting, not lying.** Nothing ties an IRI to any
    /// content once documents are merged, so attesting an import whose
    /// triples were never added passes silently. The attestation is a
    /// trust boundary, not a proof.
    pub fn attest_import(&mut self, iri: &str) {
        unsafe { ffi::howl_input_attest_import(self.raw, ffi::SlopString::borrow(iri)) }
    }
}

impl Default for Input {
    fn default() -> Self {
        Self::new()
    }
}

impl Drop for Input {
    fn drop(&mut self) {
        unsafe { ffi::howl_input_free(self.raw) }
    }
}

fn term_in<'a>(t: &'a Term, blanks: &mut HashMap<&'a str, i64>) -> ffi::TermIn {
    let empty = ffi::SlopString::borrow("");
    match t {
        Term::Iri(v) => ffi::TermIn {
            kind: ffi::TERM_IRI,
            blank: 0,
            value: ffi::SlopString::borrow(v),
            datatype: empty,
            lang: empty,
        },
        Term::Blank(label) => {
            let next = blanks.len() as i64;
            let id = *blanks.entry(label.as_str()).or_insert(next);
            ffi::TermIn { kind: ffi::TERM_BLANK, blank: id, value: empty, datatype: empty, lang: empty }
        }
        Term::Literal { value, datatype, lang } => ffi::TermIn {
            kind: ffi::TERM_LITERAL,
            blank: 0,
            value: ffi::SlopString::borrow(value),
            datatype: ffi::SlopString::borrow(datatype.as_deref().unwrap_or("")),
            lang: ffi::SlopString::borrow(lang.as_deref().unwrap_or("")),
        },
    }
}

/// A flag a host sets to stop a run.
///
/// The engine reads it at round boundaries — HOWL never consults a
/// clock, so a timeout is the host's watchdog setting this — and a run
/// that sees it set returns [`Fault::Cancelled`].
#[derive(Debug, Clone, Default)]
pub struct CancelToken {
    flag: Arc<AtomicU32>,
}

impl CancelToken {
    pub fn new() -> Self {
        Self::default()
    }

    pub fn cancel(&self) {
        self.flag.store(1, Ordering::Relaxed);
    }

    pub fn is_cancelled(&self) -> bool {
        self.flag.load(Ordering::Relaxed) != 0
    }

    /// The address the engine's `cancel-requested` loads a `uint32_t`
    /// from. `AtomicU32` has `u32`'s in-memory representation.
    fn as_cancel_ptr(&self) -> i64 {
        Arc::as_ptr(&self.flag) as usize as i64
    }
}

/// How a run ended.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Termination {
    /// Saturation reached its fixpoint.
    Fixpoint,
    /// The round budget ran out after this many rounds. The run is
    /// incomplete, so its verdict is never `Coherent`.
    ResourceLimit(u64),
}

/// A completed run, copied out of the engine.
///
/// Every list is in the engine's canonical order, which the report
/// prints; nothing here is re-sorted or re-rendered in Rust.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Report {
    /// The rung that ran (the one `Auto` chose, if it was `Auto`).
    pub profile: Profile,
    pub verdict: Verdict,
    pub inconsistent: bool,
    /// Unsatisfiable named classes, by IRI.
    pub unsatisfiable: Vec<String>,
    /// The taxonomy as (sub, super) pairs, rendered as the report's
    /// `sub` lines render them.
    pub subsumptions: Vec<(String, String)>,
    /// Everything the run did not cover, rendered as the report's
    /// `omission` lines render them. Never dropped: a non-empty list
    /// makes an otherwise clean run inconclusive.
    pub omissions: Vec<String>,
    pub termination: Termination,
    pub rounds: u64,
    lines: Vec<String>,
}

impl Report {
    /// The canonical report (SPEC §6.7), one line per element: the
    /// bytes `howl validate --report` prints, and the ones a run is
    /// compared by. It holds no worker count, timing or path, so it is
    /// identical at every worker count.
    pub fn lines(&self) -> &[String] {
        &self.lines
    }
}

/// A HOWL reasoner instance.
#[derive(Debug, Clone, Copy, Default)]
pub struct Reasoner {
    config: Config,
}

impl Reasoner {
    pub fn new() -> Self {
        Reasoner { config: Config::default() }
    }

    pub fn with_config(config: Config) -> Self {
        Reasoner { config }
    }

    pub fn config(&self) -> &Config {
        &self.config
    }

    /// Classify an input: coherence, unsatisfiable classes, and the
    /// subsumption hierarchy.
    pub fn classify(&self, input: &Input) -> Result<Report, Fault> {
        self.run(input, 0)
    }

    /// [`classify`](Self::classify), stopping with [`Fault::Cancelled`]
    /// at the first round boundary after `cancel` is set.
    pub fn classify_cancellable(&self, input: &Input, cancel: &CancelToken) -> Result<Report, Fault> {
        self.run(input, cancel.as_cancel_ptr())
    }

    fn run(&self, input: &Input, cancel: i64) -> Result<Report, Fault> {
        let run = Run(unsafe { ffi::howl_run_classify(input.raw, self.config.to_ffi(cancel)) });
        run.result()
    }
}

/// A finished run; frees the engine's arenas when dropped.
struct Run(ffi::Run);

impl Drop for Run {
    fn drop(&mut self) {
        unsafe { ffi::howl_run_free(self.0) }
    }
}

impl Run {
    fn result(&self) -> Result<Report, Fault> {
        let r = self.0;
        unsafe {
            if ffi::howl_run_ok(r) == 0 {
                return Err(match ffi::howl_run_fault(r) {
                    ffi::FAULT_CANCELLED => Fault::Cancelled,
                    ffi::FAULT_INPUT_ERROR => Fault::InputError(owned(ffi::howl_run_fault_message(r))),
                    ffi::FAULT_UNAVAILABLE => Fault::ProfileUnavailable(Profile::from_ffi(ffi::howl_run_fault_profile(r))),
                    ffi::FAULT_INVALID_OPTIONS => Fault::InvalidConfig(owned(ffi::howl_run_fault_message(r))),
                    f => panic!("the engine returned fault {f} for a run with no result"),
                });
            }
            let t = ffi::howl_run_termination(r);
            let termination = match t.tag {
                ffi::TERMINATION_FIXPOINT => Termination::Fixpoint,
                ffi::TERMINATION_RESOURCE_LIMIT => Termination::ResourceLimit(t.resource_limit as u64),
                t => panic!("the engine returned termination {t}"),
            };
            Ok(Report {
                profile: Profile::from_ffi(ffi::howl_run_profile(r)),
                verdict: match ffi::howl_run_verdict(r) {
                    ffi::VERDICT_COHERENT => Verdict::Coherent,
                    ffi::VERDICT_INCOHERENT => Verdict::Incoherent,
                    ffi::VERDICT_INCONCLUSIVE => Verdict::Inconclusive,
                    v => panic!("the engine returned verdict {v}"),
                },
                inconsistent: ffi::howl_run_inconsistent(r) != 0,
                unsatisfiable: (0..ffi::howl_run_unsat_len(r)).map(|i| owned(ffi::howl_run_unsat(r, i))).collect(),
                subsumptions: (0..ffi::howl_run_sub_len(r))
                    .map(|i| (owned(ffi::howl_run_sub(r, i)), owned(ffi::howl_run_super(r, i))))
                    .collect(),
                omissions: (0..ffi::howl_run_omission_len(r)).map(|i| owned(ffi::howl_run_omission(r, i))).collect(),
                termination,
                rounds: ffi::howl_run_rounds(r) as u64,
                lines: (0..ffi::howl_run_report_len(r)).map(|i| owned(ffi::howl_run_report_line(r, i))).collect(),
            })
        }
    }
}

/// Copy a string out of an engine arena.
unsafe fn owned(s: ffi::SlopString) -> String {
    if s.len == 0 {
        return String::new();
    }
    let bytes = std::slice::from_raw_parts(s.data as *const u8, s.len);
    String::from_utf8_lossy(bytes).into_owned()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn defaults_come_from_the_engine() {
        let c = Config::default();
        assert_eq!(c.worker_count, 4);
        assert_eq!(c.max_iterations, 1000);
        assert_eq!(c.selection, ProfileSelection::Explicit(Profile::El));
    }

    #[test]
    #[allow(deprecated)]
    fn selections_survive_the_crossing() {
        for s in [
            ProfileSelection::Auto,
            ProfileSelection::Explicit(Profile::El),
            ProfileSelection::Explicit(Profile::ElPlusPlus),
            ProfileSelection::Explicit(Profile::HornSriq),
            ProfileSelection::Explicit(Profile::Sriq),
        ] {
            let o = Config { selection: s, ..Config::default() }.to_ffi(0);
            let back = if o.auto_select != 0 {
                ProfileSelection::Auto
            } else {
                ProfileSelection::Explicit(Profile::from_ffi(o.profile))
            };
            assert_eq!(back, s);
        }
    }

    #[test]
    fn unavailable_names_the_profile() {
        let f = Fault::ProfileUnavailable(Profile::Sriq);
        assert_eq!(f.to_string(), "profile sriq is not implemented yet (implemented: el, el++)");
    }

    #[test]
    #[allow(deprecated)]
    fn the_dropped_profile_says_what_replaces_it() {
        let f = Fault::ProfileUnavailable(Profile::HornSriq);
        assert_eq!(f.to_string(), "profile horn-sriq was dropped; sriq covers its language");
    }

    #[test]
    fn out_of_range_config_is_refused_by_name() {
        for c in [
            Config { worker_count: 0, ..Config::default() },
            Config { worker_count: 65, ..Config::default() },
            Config { max_iterations: 10001, ..Config::default() },
        ] {
            match Reasoner::with_config(c).classify(&Input::new()) {
                Err(Fault::InvalidConfig(_)) => {}
                other => panic!("expected InvalidConfig, got {other:?}"),
            }
        }
    }
}
