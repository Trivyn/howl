//! Rust bindings for HOWL, a consequence-based description-logic reasoner.
//!
//! HOWL classifies a description logic — the complete subsumption
//! hierarchy and coherence of a TBox — including the defined-class
//! entailments that OWL 2 RL materialization structurally cannot see.
//!
//! # Status
//!
//! **The reasoning pipeline is not implemented (M0/M1).** [`Reasoner::classify`]
//! returns [`Fault::NotImplemented`] rather than a report. That is
//! deliberate and it is the safety-relevant choice: a stub that
//! returned an empty-but-well-formed report would read as `coherent`
//! at every interface, which is precisely the silent false pass the
//! whole design exists to prevent. Until the rules land, the engine
//! must be unable to express a verdict at all.
//!
//! # Why this crate exists before the engine does
//!
//! HOWL's first consumer calls it through an FFI behind a reasoner
//! port, so **the port, not the CLI, is the deliverable**. The layout
//! guards in [`ffi`] therefore ship from the first commit rather than
//! after an incident — see that module for the GROWL 0.6.0 regression
//! they exist to prevent.

pub mod ffi;

use std::fmt;

/// How a run failed to produce a report.
///
/// Distinct from a report with no findings: these produce no result to
/// read a verdict from.
#[derive(Debug, Clone, PartialEq, Eq)]
pub enum Fault {
    /// The pipeline is not implemented yet (M0/M1).
    NotImplemented(String),
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
}

impl fmt::Display for Fault {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Fault::NotImplemented(m) => write!(f, "not implemented: {m}"),
            Fault::Cancelled => write!(f, "cancelled"),
            Fault::InputError(m) => write!(f, "input error: {m}"),
            Fault::ProfileUnavailable(p) => {
                write!(f, "profile {} is not implemented yet (implemented: el, el++)", p.name())
            }
        }
    }
}

impl std::error::Error for Fault {}

/// The verdict a completed run licenses.
///
/// The mapping from a report to a verdict is asymmetric, and the
/// asymmetry falls out of monotonicity rather than being a compromise:
/// restoring an omitted axiom can only *add* conclusions, never retract
/// one, so a contradiction derived from a subset of the ontology is a
/// contradiction in the whole ontology. A finding is definitive
/// whatever the coverage; it is the *absence* of a finding that carries
/// no information.
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

/// A rung of the profile ladder (SPEC §5.1): each is complete for
/// exactly the logic it names, and no wider label.
///
/// "Built" is the engine (the C library and the `howl` CLI). This crate
/// does not bind `classify` yet ([`Reasoner::classify`] returns
/// [`Fault::NotImplemented`]), so from Rust no profile runs today.
///
/// | Profile | Logic | Worst case | Built |
/// |---|---|---|---|
/// | [`El`](Profile::El) | ELH⊥R+ + domain/range + ABox | PTIME | yes |
/// | [`ElPlusPlus`](Profile::ElPlusPlus) | the OWL 2 EL object fragment | PTIME | yes |
/// | [`HornSriq`](Profile::HornSriq) | Horn-SRIQ | ExpTime | no |
/// | [`Sriq`](Profile::Sriq) | SRIQ object fragment (non-Horn) | 2ExpTime | no |
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
}

/// Which calculus a run uses.
///
/// The default is `Explicit(Profile::El)`, not `Auto`: a default run
/// keeps one cost class and one theory across upgrades. `Auto` picks
/// the cheapest built profile containing the whole ontology.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum ProfileSelection {
    Auto,
    Explicit(Profile),
}

impl ProfileSelection {
    #[allow(dead_code)] // used once `classify` crosses the FFI (M2b)
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
/// the two cannot drift.
#[derive(Debug, Clone, Copy)]
pub struct Config {
    pub worker_count: u8,
    pub channel_buffer: u16,
    /// Permits `n` **completed global rounds**. The fixpoint check
    /// happens at a round boundary *before* consuming budget for the
    /// next round, so reaching the answer exactly on budget is success.
    /// `0` performs no rounds and always yields an incomplete run.
    pub max_iterations: u16,
    pub cancel_ptr: i64,
    /// The calculus. There is deliberately no `strict` field: the
    /// library always runs non-strict — an omission is a report, not a
    /// refusal (SPEC §8.4).
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
            cancel_ptr: c.cancel_ptr,
            selection: ProfileSelection::from_ffi(c.selection),
        }
    }
}

/// A HOWL reasoner instance.
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

    /// Classify a TBox.
    ///
    /// `imports_resolved` is the caller's **closure attestation** — the
    /// set of `owl:imports` IRIs it resolved and merged into `triples`.
    /// HOWL is network-free and cannot resolve imports itself, so a
    /// declared import missing from this list becomes a coverage
    /// omission and the run is structurally incomplete.
    ///
    /// Be precise about what that catches: **forgetting, not lying.**
    /// Nothing ties an import IRI to any content once documents are
    /// flattened, so a caller that lists an IRI while supplying none of
    /// its triples passes silently. The attestation is a trust
    /// boundary, not a proof.
    ///
    /// # Status
    ///
    /// Always returns [`Fault::NotImplemented`] — see the module docs.
    /// NOT YET WIRED TO THE ENGINE — and as of M0 that is a statement
    /// about THIS BINDING, not about HOWL. The C library classifies:
    /// `howl validate` reads Turtle, gates, normalizes, saturates and
    /// exits 0/1/2 (see `make acceptance`). What is missing here is the
    /// marshalling of triples across the FFI boundary and back, which
    /// is M2 scope along with the frozen port's amendments.
    ///
    /// It refuses rather than returning a Verdict for the same reason
    /// the engine stub did: a `Verdict` has a reading that can be
    /// mistaken for success, and `NotImplemented` has none.
    pub fn classify(
        &self,
        _triples: &[ffi::RdfTriple],
        _imports_resolved: &[String],
    ) -> Result<Verdict, Fault> {
        Err(Fault::NotImplemented(
            "Rust binding not wired to the engine yet (M2); the C library is implemented".into(),
        ))
    }
}

impl Default for Reasoner {
    fn default() -> Self {
        Self::new()
    }
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

    /// The stub must not be able to express a pass. This is the same
    /// guard the SLOP test harness applies to `classify`, restated at
    /// the boundary a consumer actually calls.
    #[test]
    /// Pins the BINDING's refusal, not the engine's. The engine stopped
    /// refusing in M0; if this test is ever read as evidence that the
    /// pipeline is unimplemented, it is being read wrong.
    fn binding_refuses_rather_than_passing() {
        let r = Reasoner::new();
        match r.classify(&[], &[]) {
            Ok(v) => panic!("binding returned a verdict ({v:?}) instead of refusing"),
            Err(Fault::NotImplemented(_)) => {}
            Err(e) => panic!("unexpected fault: {e}"),
        }
    }
}
