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
//! The engine's result never crosses as a struct: it stays in C behind
//! an opaque handle, and this crate copies what it needs out through
//! accessors compiled against the real headers. Only `ReasonerConfig`
//! and the shim's own term struct are mirrored, and the layout guards
//! in [`ffi`] assert both against the C ABI — see that module for the
//! GROWL 0.6.0 regression they exist to prevent.
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
use std::os::raw::{c_char, c_int};
use std::ptr::NonNull;
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
    /// yet. Refused, never quietly run as another profile: that would
    /// classify a smaller theory than asked for, under the wrong name.
    ProfileUnavailable(Profile),
    /// A [`Config`] field outside the range the engine accepts.
    InvalidConfig(String),
}

impl fmt::Display for Fault {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Fault::Cancelled => write!(f, "cancelled"),
            Fault::InputError(m) => write!(f, "input error: {m}"),
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
/// | [`HornSriq`](Profile::HornSriq) | Horn-SRIQ | ExpTime | no |
/// | [`Sriq`](Profile::Sriq) | SRIQ object fragment (non-Horn) | 2ExpTime | no |
///
/// Asking for an unbuilt rung is [`Fault::ProfileUnavailable`].
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum Profile {
    El,
    ElPlusPlus,
    HornSriq,
    Sriq,
}

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

    fn to_ffi(self) -> ffi::Profile {
        match self {
            Profile::El => ffi::Profile::El,
            Profile::ElPlusPlus => ffi::Profile::ElPlusPlus,
            Profile::HornSriq => ffi::Profile::HornSriq,
            Profile::Sriq => ffi::Profile::Sriq,
        }
    }

    fn from_ffi(p: ffi::Profile) -> Self {
        match p {
            ffi::Profile::El => Profile::El,
            ffi::Profile::ElPlusPlus => Profile::ElPlusPlus,
            ffi::Profile::HornSriq => Profile::HornSriq,
            ffi::Profile::Sriq => Profile::Sriq,
        }
    }

    /// From a C discriminant, as an accessor returns it.
    fn from_c(d: c_int) -> Self {
        [Profile::El, Profile::ElPlusPlus, Profile::HornSriq, Profile::Sriq]
            .into_iter()
            .find(|p| p.to_ffi() as c_int == d)
            .unwrap_or_else(|| panic!("the engine returned profile discriminant {d}"))
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

impl ProfileSelection {
    fn to_ffi(self) -> ffi::ProfileSelection {
        match self {
            ProfileSelection::Auto => ffi::ProfileSelection {
                tag: ffi::ProfileSelectionTag::Auto,
                data: ffi::ProfileSelectionData { explicit: ffi::Profile::El },
            },
            ProfileSelection::Explicit(p) => ffi::ProfileSelection {
                tag: ffi::ProfileSelectionTag::Explicit,
                data: ffi::ProfileSelectionData { explicit: p.to_ffi() },
            },
        }
    }

    fn from_ffi(s: ffi::ProfileSelection) -> Self {
        match s.tag {
            ffi::ProfileSelectionTag::Auto => ProfileSelection::Auto,
            // SAFETY: the tag says the `explicit` arm is the live one.
            ffi::ProfileSelectionTag::Explicit => {
                ProfileSelection::Explicit(Profile::from_ffi(unsafe { s.data.explicit }))
            }
        }
    }
}

/// Reasoner configuration.
///
/// Mirrors the engine's own defaults rather than inventing new ones, so
/// the two cannot drift. There is deliberately no `strict` field: the
/// library always runs non-strict — an omission is a report, not a
/// refusal (SPEC §8.4).
#[derive(Debug, Clone, Copy)]
pub struct Config {
    /// Worker threads, `1..=64`. The report is identical at every count.
    pub worker_count: u8,
    /// `64..=4096`.
    pub channel_buffer: u16,
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
        let c = unsafe { ffi::howl_default_config() };
        Config {
            worker_count: c.worker_count,
            channel_buffer: c.channel_buffer,
            max_iterations: c.max_iterations,
            selection: ProfileSelection::from_ffi(c.selection),
        }
    }
}

impl Config {
    /// The engine's config with this one's fields. The SLOP range types
    /// are checked here: the C struct holds whatever it is handed.
    fn to_ffi(self, cancel_ptr: i64) -> Result<ffi::ReasonerConfig, Fault> {
        if !(1..=64).contains(&self.worker_count) {
            return Err(Fault::InvalidConfig(format!("worker_count {} is not in 1..=64", self.worker_count)));
        }
        if !(64..=4096).contains(&self.channel_buffer) {
            return Err(Fault::InvalidConfig(format!("channel_buffer {} is not in 64..=4096", self.channel_buffer)));
        }
        if self.max_iterations > 10000 {
            return Err(Fault::InvalidConfig(format!("max_iterations {} is not in 0..=10000", self.max_iterations)));
        }
        let mut c = unsafe { ffi::howl_default_config() };
        c.worker_count = self.worker_count;
        c.channel_buffer = self.channel_buffer;
        c.max_iterations = self.max_iterations;
        c.selection = self.selection.to_ffi();
        c.cancel_ptr = cancel_ptr;
        Ok(c)
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
    raw: NonNull<ffi::HowlInput>,
    /// A document that failed to parse leaves its earlier triples
    /// encoded, so the input can no longer be classified.
    poisoned: Option<String>,
}

// The handle owns its arena outright and the C side keeps no thread
// affinity, so it may move between threads. It is not `Sync`: adding a
// document mutates it.
unsafe impl Send for Input {}

impl Input {
    pub fn new() -> Self {
        let raw = unsafe { ffi::howl_input_new() };
        Input {
            raw: NonNull::new(raw).expect("howl: cannot allocate an input arena"),
            poisoned: None,
        }
    }

    /// Add one document given as triples.
    pub fn add_triples(&mut self, triples: &[(Term, Term, Term)]) {
        let mut blanks: HashMap<&str, i64> = HashMap::new();
        let mut terms = Vec::with_capacity(triples.len() * 3);
        for (s, p, o) in triples {
            for t in [s, p, o] {
                terms.push(howl_term(t, &mut blanks));
            }
        }
        unsafe {
            ffi::howl_input_begin_document(self.raw.as_ptr());
            ffi::howl_input_add_triples(self.raw.as_ptr(), terms.as_ptr(), triples.len());
        }
    }

    /// Add one document given as Turtle.
    ///
    /// A document that does not parse is an [`Fault::InputError`], and
    /// so is every later [`Reasoner::classify`] of this input: the
    /// triples before the error were already added.
    pub fn add_turtle(&mut self, text: &str) -> Result<(), Fault> {
        let mut message = ffi::SlopString { len: 0, data: std::ptr::null() };
        let (mut line, mut column) = (0i64, 0i64);
        let ok = unsafe {
            ffi::howl_input_begin_document(self.raw.as_ptr());
            ffi::howl_input_add_turtle(
                self.raw.as_ptr(),
                text.as_ptr() as *const c_char,
                text.len(),
                &mut message,
                &mut line,
                &mut column,
            )
        };
        if ok != 0 {
            return Ok(());
        }
        let m = format!("Turtle does not parse at line {line}, column {column}: {}", unsafe { owned(message) });
        self.poisoned = Some(m.clone());
        Err(Fault::InputError(m))
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
        unsafe { ffi::howl_input_attest_import(self.raw.as_ptr(), iri.as_ptr() as *const c_char, iri.len()) }
    }
}

impl Default for Input {
    fn default() -> Self {
        Self::new()
    }
}

impl Drop for Input {
    fn drop(&mut self) {
        unsafe { ffi::howl_input_free(self.raw.as_ptr()) }
    }
}

fn howl_term<'a>(t: &'a Term, blanks: &mut HashMap<&'a str, i64>) -> ffi::HowlTerm {
    let none = (std::ptr::null(), 0usize);
    let str_of = |s: &str| (s.as_ptr() as *const c_char, s.len());
    let (kind, blank, value, datatype, lang) = match t {
        Term::Iri(v) => (ffi::HOWL_TERM_IRI, 0, str_of(v), none, none),
        Term::Blank(label) => {
            let next = blanks.len() as i64;
            let id = *blanks.entry(label.as_str()).or_insert(next);
            (ffi::HOWL_TERM_BLANK, id, none, none, none)
        }
        Term::Literal { value, datatype, lang } => (
            ffi::HOWL_TERM_LITERAL,
            0,
            str_of(value),
            datatype.as_deref().map_or(none, str_of),
            lang.as_deref().map_or(none, str_of),
        ),
    };
    ffi::HowlTerm {
        kind,
        blank,
        value: value.0,
        value_len: value.1,
        datatype: datatype.0,
        datatype_len: datatype.1,
        lang: lang.0,
        lang_len: lang.1,
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

    fn run(&self, input: &Input, cancel_ptr: i64) -> Result<Report, Fault> {
        if let Some(m) = &input.poisoned {
            return Err(Fault::InputError(m.clone()));
        }
        let config = self.config.to_ffi(cancel_ptr)?;
        let raw = unsafe { ffi::howl_run_classify(input.raw.as_ptr(), config) };
        let run = Run(NonNull::new(raw).expect("howl: cannot allocate a run arena"));
        run.result()
    }
}

/// A finished run; frees the engine's arena when dropped.
struct Run(NonNull<ffi::HowlRun>);

impl Drop for Run {
    fn drop(&mut self) {
        unsafe { ffi::howl_run_free(self.0.as_ptr()) }
    }
}

impl Run {
    fn result(&self) -> Result<Report, Fault> {
        let r = self.0.as_ptr();
        unsafe {
            if ffi::howl_run_ok(r) == 0 {
                return Err(fault(r));
            }
            let termination = match ffi::howl_run_termination_tag(r) {
                ffi::TERMINATION_FIXPOINT => Termination::Fixpoint,
                ffi::TERMINATION_RESOURCE_LIMIT => {
                    Termination::ResourceLimit(ffi::howl_run_resource_limit(r) as u64)
                }
                t => panic!("the engine returned termination tag {t}"),
            };
            Ok(Report {
                profile: Profile::from_c(ffi::howl_run_profile(r)),
                verdict: match ffi::howl_run_verdict(r) {
                    ffi::VERDICT_COHERENT => Verdict::Coherent,
                    ffi::VERDICT_INCOHERENT => Verdict::Incoherent,
                    ffi::VERDICT_INCONCLUSIVE => Verdict::Inconclusive,
                    v => panic!("the engine returned verdict discriminant {v}"),
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

unsafe fn fault(r: *mut ffi::HowlRun) -> Fault {
    match ffi::howl_run_fault_tag(r) {
        ffi::FAULT_CANCELLED => Fault::Cancelled,
        ffi::FAULT_INPUT_ERROR => Fault::InputError(owned(ffi::howl_run_fault_message(r))),
        ffi::FAULT_UNAVAILABLE => Fault::ProfileUnavailable(Profile::from_c(ffi::howl_run_fault_profile(r))),
        // Only a strict run refuses, and the shim never runs strict. Should
        // it happen anyway, the omissions are named rather than dropped.
        ffi::FAULT_REFUSED => {
            let oms: Vec<String> = (0..ffi::howl_run_refused_len(r)).map(|i| owned(ffi::howl_run_refused(r, i))).collect();
            Fault::InputError(format!("refused under a strict profile: {}", oms.join("; ")))
        }
        t => panic!("the engine returned fault tag {t}"),
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
    fn selections_survive_the_crossing() {
        for s in [
            ProfileSelection::Auto,
            ProfileSelection::Explicit(Profile::El),
            ProfileSelection::Explicit(Profile::ElPlusPlus),
            ProfileSelection::Explicit(Profile::HornSriq),
            ProfileSelection::Explicit(Profile::Sriq),
        ] {
            assert_eq!(ProfileSelection::from_ffi(s.to_ffi()), s);
        }
    }

    #[test]
    fn unavailable_names_the_profile() {
        let f = Fault::ProfileUnavailable(Profile::HornSriq);
        assert_eq!(f.to_string(), "profile horn-sriq is not implemented yet (implemented: el, el++)");
    }

    #[test]
    fn out_of_range_config_is_refused_before_the_engine() {
        for c in [
            Config { worker_count: 0, ..Config::default() },
            Config { worker_count: 65, ..Config::default() },
            Config { channel_buffer: 63, ..Config::default() },
            Config { max_iterations: 10001, ..Config::default() },
        ] {
            match Reasoner::with_config(c).classify(&Input::new()) {
                Err(Fault::InvalidConfig(_)) => {}
                other => panic!("expected InvalidConfig, got {other:?}"),
            }
        }
    }
}
