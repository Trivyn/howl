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
}

impl fmt::Display for Fault {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Fault::NotImplemented(m) => write!(f, "not implemented: {m}"),
            Fault::Cancelled => write!(f, "cancelled"),
            Fault::InputError(m) => write!(f, "input error: {m}"),
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
    pub fn classify(
        &self,
        _triples: &[ffi::RdfTriple],
        _imports_resolved: &[String],
    ) -> Result<Verdict, Fault> {
        Err(Fault::NotImplemented(
            "HOWL v0 pipeline not implemented (M0/M1)".into(),
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
    }

    /// The stub must not be able to express a pass. This is the same
    /// guard the SLOP test harness applies to `classify`, restated at
    /// the boundary a consumer actually calls.
    #[test]
    fn stub_refuses_rather_than_passing() {
        let r = Reasoner::new();
        match r.classify(&[], &[]) {
            Ok(v) => panic!("stub returned a verdict ({v:?}) instead of refusing"),
            Err(Fault::NotImplemented(_)) => {}
            Err(e) => panic!("unexpected fault: {e}"),
        }
    }
}
