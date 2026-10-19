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
                write!(f, "profile {} is not implemented yet (implemented: el, el++, sriq)", p.name())
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
/// | [`Sriq`](Profile::Sriq) | SRIQ object fragment with ABox (SPEC §5.5) | 2ExpTime without an ABox; with one, a triple-exponential bound | yes, single-threaded, under a clause budget |
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

    /// From a C `howl_types_Profile`, as an accessor returns it.
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
/// the cheapest built profile containing the whole ontology (else the
/// one omitting fewest axioms). When that is `Sriq` and its run passes
/// the engine's clause budget with nothing definitive, `Auto` steps
/// down to `El` or `ElPlusPlus` (SPEC §5.1). The [`Report`] names the
/// one that ran.
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
        self.add(triples, ffi::howl_input_begin_document, ffi::howl_input_add_triple)
    }

    /// Add one document given as Turtle.
    ///
    /// A document that does not parse is an [`Fault::InputError`], and
    /// so is every later [`Reasoner::classify`] of this input: the
    /// triples before the error were already added.
    pub fn add_turtle(&mut self, text: &str) -> Result<(), Fault> {
        turtle_result(unsafe { ffi::howl_input_add_turtle(self.raw, ffi::SlopString::borrow(text)) })
    }

    /// Add one probe document given as triples: read only by the probe
    /// run that answers this input's queries, never by the main run.
    ///
    /// A probe document is where a query's classes are defined, e.g.
    /// `urn:probe:1 rdfs:subClassOf [ owl:onProperty :p ; owl:someValuesFrom owl:Thing ]`
    /// to ask whether `:p` can have a value. Each is standardized apart
    /// from the input and from the other probe documents.
    pub fn add_probe_triples(&mut self, triples: &[(Term, Term, Term)]) {
        self.add(triples, ffi::howl_input_begin_probe_document, ffi::howl_input_add_probe_triple)
    }

    /// Add one probe document given as Turtle; see
    /// [`add_probe_triples`](Self::add_probe_triples). One that does not
    /// parse refuses the input, as [`add_turtle`](Self::add_turtle) does.
    pub fn add_probe_turtle(&mut self, text: &str) -> Result<(), Fault> {
        turtle_result(unsafe { ffi::howl_input_add_probe_turtle(self.raw, ffi::SlopString::borrow(text)) })
    }

    /// Ask whether a named class is unsatisfiable. Answered in
    /// [`Report::probes`] by a probe run; the main report is unchanged.
    pub fn ask_unsatisfiable(&mut self, class: &str) {
        unsafe { ffi::howl_input_ask_unsatisfiable(self.raw, ffi::SlopString::borrow(class)) }
    }

    /// Ask whether `sub` is subsumed by `sup`, both named classes.
    /// Answered in [`Report::probes`] by a probe run; the main report is
    /// unchanged.
    pub fn ask_subsumed(&mut self, sub: &str, sup: &str) {
        unsafe {
            ffi::howl_input_ask_subsumed(self.raw, ffi::SlopString::borrow(sub), ffi::SlopString::borrow(sup))
        }
    }

    fn add(
        &mut self,
        triples: &[(Term, Term, Term)],
        begin: unsafe extern "C" fn(ffi::Input),
        add: unsafe extern "C" fn(ffi::Input, ffi::TermIn, ffi::TermIn, ffi::TermIn) -> u8,
    ) {
        let mut blanks: HashMap<&str, i64> = HashMap::new();
        unsafe { begin(self.raw) };
        for (s, p, o) in triples {
            let (s, p, o) = (term_in(s, &mut blanks), term_in(p, &mut blanks), term_in(o, &mut blanks));
            // Every Term this crate can build is one HOWL takes, so this
            // never refuses; were it to, the engine refuses the input and
            // classify says so.
            unsafe { add(self.raw, s, p, o) };
        }
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
    ///
    /// OWL 2 lets an import name an ontology's IRI or its version IRI.
    /// Attest the ontology IRI: an import naming its `owl:versionIRI`
    /// resolves too, when an added document declares that version.
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

fn turtle_result(r: ffi::TurtleResult) -> Result<(), Fault> {
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

/// A probe query: does the probe run entail this inclusion?
#[derive(Debug, Clone, PartialEq, Eq, Hash)]
#[non_exhaustive]
pub enum Query {
    /// Is the class unsatisfiable (`C ⊑ owl:Nothing`)?
    Unsatisfiable(String),
    /// Is `.0` subsumed by `.1`?
    Subsumed(String, String),
}

/// A probe query's answer.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
#[non_exhaustive]
pub enum Answer {
    /// Entailed. Sound whatever the probe run's coverage or budget, since
    /// covering more only adds conclusions.
    Yes,
    /// Not entailed, by a probe run that was complete: no omission, and
    /// a fixpoint.
    No,
    /// Not shown entailed, by a probe run that was not complete.
    Unknown,
}

/// The kind of entity a `MissingDeclaration` omission names.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
#[non_exhaustive]
pub enum EntityKind {
    Class,
    ObjectProperty,
    DataProperty,
    AnnotationProperty,
    NamedIndividual,
    Datatype,
}

impl EntityKind {
    /// From a C `howl_types_EntityKind`, as an accessor returns it.
    fn from_ffi(k: c_int) -> Self {
        match k {
            ffi::ENTITY_CLASS => EntityKind::Class,
            ffi::ENTITY_OBJECT_PROPERTY => EntityKind::ObjectProperty,
            ffi::ENTITY_DATA_PROPERTY => EntityKind::DataProperty,
            ffi::ENTITY_ANNOTATION_PROPERTY => EntityKind::AnnotationProperty,
            ffi::ENTITY_INDIVIDUAL => EntityKind::NamedIndividual,
            ffi::ENTITY_DATATYPE => EntityKind::Datatype,
            k => panic!("the engine returned entity kind {k}"),
        }
    }
}

/// The document an omission came from, by index in the order the
/// documents were added: each `add_turtle` / `add_triples` call is one
/// input document, and each `add_probe_*` call one probe document,
/// numbered from 0 among their own.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
#[non_exhaustive]
pub enum Document {
    Input(usize),
    Probe(usize),
}

/// Why an axiom was omitted. When an axiom fails several of the gate's
/// conditions, the first in this order decides.
#[derive(Debug, Clone, PartialEq, Eq, Hash)]
#[non_exhaustive]
pub enum OmissionReason {
    /// The construct is not in the run's profile.
    OutOfProfile,
    /// An RBox axiom, omitted because the RBox is not regular (OWL 2
    /// §11.2 under `el` and `el++`, ≺-regularity under `sriq`).
    /// `witness` is SPEC §5.2's witness: the axioms that make it so,
    /// rendered as their omissions are, canonically sorted, each once. It
    /// is the union over every failure, so every `IrregularRbox` omission
    /// of a run carries the same one.
    IrregularRbox { witness: Vec<String> },
    /// An axiom or restriction only a simple role may carry, over a role
    /// the RBox makes non-simple: a chain's head, a super-property of
    /// one, or a transitive role. `role` is that role in functional
    /// syntax (an IRI, or `ObjectInverseOf(IRI)`); when several are, the
    /// canonically least.
    NonSimpleRole { role: String },
    /// An `el` / `el++` property chain that breaks the range condition:
    /// its target has a range the chain's last role does not share.
    RangeCondition,
    /// One of `sriq`'s resource guards: a number restriction above 16, or
    /// a property chain set aside by chain elimination's size guard.
    ResourceGuard,
    /// A `MissingDeclaration` or an `UndeclaredProperty`.
    Undeclared,
    /// An `owl:imports` the caller did not attest to.
    UnresolvedImport,
    /// Input HOWL cannot read as an axiom.
    Unrecognized,
}

impl OmissionReason {
    /// From a C `howl_types_OmissionReason` and the role and witness
    /// accessors' values.
    fn from_ffi(k: c_int, role: String, witness: Vec<String>) -> Self {
        match k {
            ffi::REASON_OUT_OF_PROFILE => OmissionReason::OutOfProfile,
            ffi::REASON_IRREGULAR_RBOX => OmissionReason::IrregularRbox { witness },
            ffi::REASON_NON_SIMPLE_ROLE => OmissionReason::NonSimpleRole { role },
            ffi::REASON_RANGE_CONDITION => OmissionReason::RangeCondition,
            ffi::REASON_RESOURCE_GUARD => OmissionReason::ResourceGuard,
            ffi::REASON_UNDECLARED => OmissionReason::Undeclared,
            ffi::REASON_UNRESOLVED_IMPORT => OmissionReason::UnresolvedImport,
            ffi::REASON_UNRECOGNIZED => OmissionReason::Unrecognized,
            k => panic!("the engine returned omission reason {k}"),
        }
    }
}

/// One omission, with what the engine knows about it.
#[derive(Debug, Clone, PartialEq, Eq)]
#[non_exhaustive]
pub struct Omission {
    /// The head token of `text`: `MissingDeclaration`,
    /// `UndeclaredProperty`, `UnresolvedImport`, or an out-of-profile
    /// axiom's form (`SubClassOf`, `DataAxiom`, `Unrecognized`, ...).
    pub kind: String,
    /// For a `MissingDeclaration`, the kind of entity it names.
    pub entity_kind: Option<EntityKind>,
    /// The document it came from. `None` when no one document is it: a
    /// `MissingDeclaration` whose referring axioms, or an
    /// `UndeclaredProperty` whose triples, come from more than one.
    pub document: Option<Document>,
    /// Rendered exactly as the matching entry of the plain omission list.
    pub text: String,
    /// Why it was omitted.
    pub reason: OmissionReason,
}

/// One query and its answer.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct ProbeAnswer {
    pub query: Query,
    pub answer: Answer,
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
    /// The input's queries, each once, in canonical order (unsatisfiable
    /// before subsumed, then by class), answered by a probe run of the
    /// input plus its probe documents. Empty when nothing was asked.
    /// Nothing above comes from the probe run.
    pub probes: Vec<ProbeAnswer>,
    /// Whether the probe run was inconsistent: every answer is then a
    /// vacuous `Yes`.
    pub probe_inconsistent: bool,
    /// What the probe run did not cover, rendered as `omissions` are. Any
    /// rules out a `No`.
    pub probe_omissions: Vec<String>,
    lines: Vec<String>,
    details: Vec<Omission>,
    probe_details: Vec<Omission>,
}

impl Report {
    /// [`omissions`](Self::omissions), each with its kind and the input
    /// document it came from. The same list, in the same order: entry `i`
    /// has `omissions[i]` as its `text`.
    pub fn omission_details(&self) -> &[Omission] {
        &self.details
    }

    /// [`probe_omissions`](Self::probe_omissions), each with its kind and
    /// document: one of the input's, or one of the probe documents.
    pub fn probe_omission_details(&self) -> &[Omission] {
        &self.probe_details
    }

    /// The canonical report (SPEC §6.7), one line per element: the
    /// bytes `howl validate --report` prints, and the ones a run is
    /// compared by. It holds no worker count, timing or path, so it is
    /// identical at every worker count.
    pub fn lines(&self) -> &[String] {
        &self.lines
    }
}

/// The input's probe queries, answered by a probe run alone
/// ([`Reasoner::answer`]): no main classification, so no report.
///
/// The probe run is over the queries' ⊥-locality module (SPEC §8.4), so it
/// gives every `Yes` and `No` that [`Reasoner::classify`] gives in
/// [`Report::probes`] for the same input and configuration. Where an
/// omission outside the module held that run back, it may answer `Yes` or
/// `No` instead of `Unknown`.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Answers {
    /// The rung the run that answered ran: under `Auto`, the one chosen for
    /// the queries' module, or for the input plus its probe documents when
    /// the whole input was classified instead (a cap, the budget, or an
    /// omission another rung could read). `None` when nothing was asked, so
    /// nothing ran.
    pub profile: Option<Profile>,
    /// Each query once, in canonical order (unsatisfiable before
    /// subsumed, then by class).
    pub probes: Vec<ProbeAnswer>,
    /// Whether the probe run was inconsistent: every answer is then a
    /// vacuous `Yes`.
    pub inconsistent: bool,
    /// What the run that answered did not cover, rendered as
    /// [`Report::omissions`] are: the module's own when the module
    /// answered. Any rules out a `No`.
    pub omissions: Vec<String>,
    lines: Vec<String>,
    details: Vec<Omission>,
}

impl Answers {
    /// [`omissions`](Self::omissions), each with its kind and document:
    /// one of the input's, or one of the probe documents.
    pub fn omission_details(&self) -> &[Omission] {
        &self.details
    }

    /// The lines `howl ask` prints: `profile P` when a probe run ran, then
    /// the probe lines.
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

    /// Answer the input's probe queries alone (SPEC §8.4): one probe
    /// run, and no main classification. Cheaper than
    /// [`classify`](Self::classify) by that classification, with the same
    /// answers.
    pub fn answer(&self, input: &Input) -> Result<Answers, Fault> {
        self.answer_run(input, 0)
    }

    /// [`answer`](Self::answer), stopping with [`Fault::Cancelled`] at the
    /// first round boundary after `cancel` is set.
    pub fn answer_cancellable(&self, input: &Input, cancel: &CancelToken) -> Result<Answers, Fault> {
        self.answer_run(input, cancel.as_cancel_ptr())
    }

    fn run(&self, input: &Input, cancel: i64) -> Result<Report, Fault> {
        let run = Run(unsafe { ffi::howl_run_classify(input.raw, self.config.to_ffi(cancel)) });
        run.result()
    }

    fn answer_run(&self, input: &Input, cancel: i64) -> Result<Answers, Fault> {
        let run = Run(unsafe { ffi::howl_run_answer(input.raw, self.config.to_ffi(cancel)) });
        run.answers()
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
    /// The run's fault, if it has no result.
    fn fault(&self) -> Option<Fault> {
        let r = self.0;
        unsafe {
            if ffi::howl_run_ok(r) != 0 {
                return None;
            }
            Some(match ffi::howl_run_fault(r) {
                ffi::FAULT_CANCELLED => Fault::Cancelled,
                ffi::FAULT_INPUT_ERROR => Fault::InputError(owned(ffi::howl_run_fault_message(r))),
                ffi::FAULT_UNAVAILABLE => Fault::ProfileUnavailable(Profile::from_ffi(ffi::howl_run_fault_profile(r))),
                ffi::FAULT_INVALID_OPTIONS => Fault::InvalidConfig(owned(ffi::howl_run_fault_message(r))),
                f => panic!("the engine returned fault {f} for a run with no result"),
            })
        }
    }

    fn answers(&self) -> Result<Answers, Fault> {
        if let Some(f) = self.fault() {
            return Err(f);
        }
        let r = self.0;
        unsafe {
            let n = ffi::howl_run_probe_len(r);
            Ok(Answers {
                profile: if n == 0 { None } else { Some(Profile::from_ffi(ffi::howl_run_profile(r))) },
                probes: (0..n).map(|i| probe_answer(r, i)).collect(),
                inconsistent: ffi::howl_run_probe_inconsistent(r) != 0,
                omissions: (0..ffi::howl_run_probe_omission_len(r))
                    .map(|i| owned(ffi::howl_run_probe_omission(r, i)))
                    .collect(),
                lines: (0..ffi::howl_run_report_len(r)).map(|i| owned(ffi::howl_run_report_line(r, i))).collect(),
                details: (0..ffi::howl_run_probe_omission_len(r)).map(|i| probe_omission(r, i)).collect(),
            })
        }
    }

    fn result(&self) -> Result<Report, Fault> {
        if let Some(f) = self.fault() {
            return Err(f);
        }
        let r = self.0;
        unsafe {
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
                probes: (0..ffi::howl_run_probe_len(r)).map(|i| probe_answer(r, i)).collect(),
                probe_inconsistent: ffi::howl_run_probe_inconsistent(r) != 0,
                probe_omissions: (0..ffi::howl_run_probe_omission_len(r))
                    .map(|i| owned(ffi::howl_run_probe_omission(r, i)))
                    .collect(),
                lines: (0..ffi::howl_run_report_len(r)).map(|i| owned(ffi::howl_run_report_line(r, i))).collect(),
                details: (0..ffi::howl_run_omission_len(r)).map(|i| omission(r, i)).collect(),
                probe_details: (0..ffi::howl_run_probe_omission_len(r)).map(|i| probe_omission(r, i)).collect(),
            })
        }
    }
}

/// A `MissingDeclaration`'s entity kind, from the accessor's value.
fn entity_kind(kind: &str, k: c_int) -> Option<EntityKind> {
    (kind == "MissingDeclaration").then(|| EntityKind::from_ffi(k))
}

/// The run's i-th omission.
unsafe fn omission(r: ffi::Run, i: i64) -> Omission {
    let kind = owned(ffi::howl_run_omission_kind(r, i));
    let d = ffi::howl_run_omission_document(r, i);
    Omission {
        entity_kind: entity_kind(&kind, ffi::howl_run_omission_entity_kind(r, i)),
        kind,
        document: (d >= 0).then(|| Document::Input(d as usize)),
        text: owned(ffi::howl_run_omission(r, i)),
        reason: OmissionReason::from_ffi(
            ffi::howl_run_omission_reason(r, i),
            owned(ffi::howl_run_omission_reason_role(r, i)),
            (0..ffi::howl_run_omission_witness_len(r, i)).map(|k| owned(ffi::howl_run_omission_witness(r, i, k))).collect(),
        ),
    }
}

/// The probe run's i-th omission.
unsafe fn probe_omission(r: ffi::Run, i: i64) -> Omission {
    let kind = owned(ffi::howl_run_probe_omission_kind(r, i));
    let d = ffi::howl_run_probe_omission_document(r, i) as usize;
    Omission {
        entity_kind: entity_kind(&kind, ffi::howl_run_probe_omission_entity_kind(r, i)),
        kind,
        document: match ffi::howl_run_probe_omission_source(r, i) {
            ffi::DOCUMENT_NONE => None,
            ffi::DOCUMENT_INPUT => Some(Document::Input(d)),
            ffi::DOCUMENT_PROBE => Some(Document::Probe(d)),
            s => panic!("the engine returned document source {s}"),
        },
        text: owned(ffi::howl_run_probe_omission(r, i)),
        reason: OmissionReason::from_ffi(
            ffi::howl_run_probe_omission_reason(r, i),
            owned(ffi::howl_run_probe_omission_reason_role(r, i)),
            (0..ffi::howl_run_probe_omission_witness_len(r, i))
                .map(|k| owned(ffi::howl_run_probe_omission_witness(r, i, k)))
                .collect(),
        ),
    }
}

/// The run's i-th probe answer.
unsafe fn probe_answer(r: ffi::Run, i: i64) -> ProbeAnswer {
    let sub = owned(ffi::howl_run_probe_sub(r, i));
    let query = match ffi::howl_run_probe_kind(r, i) {
        ffi::QUERY_UNSATISFIABLE => Query::Unsatisfiable(sub),
        ffi::QUERY_SUBSUMED => Query::Subsumed(sub, owned(ffi::howl_run_probe_sup(r, i))),
        k => panic!("the engine returned query kind {k}"),
    };
    let answer = match ffi::howl_run_probe_answer(r, i) {
        ffi::ANSWER_YES => Answer::Yes,
        ffi::ANSWER_NO => Answer::No,
        ffi::ANSWER_UNKNOWN => Answer::Unknown,
        a => panic!("the engine returned answer {a}"),
    };
    ProbeAnswer { query, answer }
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
        assert_eq!(f.to_string(), "profile sriq is not implemented yet (implemented: el, el++, sriq)");
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
