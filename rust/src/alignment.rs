//! Ontology alignment and mapping repair (SPEC §12 M4).

use crate::{ffi, owned, CancelToken, Fault, Input, Reasoner, Report, Run, Term};

/// A collection of fixed ontologies and removable mapping documents.
///
/// Each document has a unique, absolute source IRI. Removing a mapping
/// removes the logical axiom identified by its source and canonical text;
/// fixed ontology axioms are never repair choices.
pub struct AlignmentInput {
    input: Input,
    documents: i64,
}

impl AlignmentInput {
    pub fn new() -> Self {
        Self {
            input: Input::new(),
            documents: 0,
        }
    }

    pub fn add_fixed_turtle(&mut self, source_iri: &str, turtle: &str) -> Result<(), Fault> {
        self.add_turtle(source_iri, turtle, false)
    }

    pub fn add_mapping_turtle(&mut self, source_iri: &str, turtle: &str) -> Result<(), Fault> {
        self.add_turtle(source_iri, turtle, true)
    }

    pub fn add_fixed_triples(
        &mut self,
        source_iri: &str,
        triples: &[(Term, Term, Term)],
    ) -> Result<(), Fault> {
        self.add_triples(source_iri, triples, false)
    }

    pub fn add_mapping_triples(
        &mut self,
        source_iri: &str,
        triples: &[(Term, Term, Term)],
    ) -> Result<(), Fault> {
        self.add_triples(source_iri, triples, true)
    }

    /// Attest an `owl:imports` target resolved by an added document.
    pub fn attest_import(&mut self, iri: &str) {
        self.input.attest_import(iri);
    }

    fn add_turtle(&mut self, source_iri: &str, turtle: &str, mapping: bool) -> Result<(), Fault> {
        self.input.add_turtle(turtle)?;
        self.set_document(source_iri, mapping)
    }

    fn add_triples(
        &mut self,
        source_iri: &str,
        triples: &[(Term, Term, Term)],
        mapping: bool,
    ) -> Result<(), Fault> {
        self.input.add_triples(triples);
        self.set_document(source_iri, mapping)
    }

    fn set_document(&mut self, source_iri: &str, mapping: bool) -> Result<(), Fault> {
        let accepted = unsafe {
            ffi::howl_input_set_document(
                self.input.raw,
                self.documents,
                ffi::SlopString::borrow(source_iri),
                mapping as u8,
            )
        };
        if accepted == 0 {
            return Err(Fault::InputError(format!(
                "invalid or duplicate alignment source IRI: {source_iri}"
            )));
        }
        self.documents += 1;
        Ok(())
    }
}

impl Default for AlignmentInput {
    fn default() -> Self {
        Self::new()
    }
}

/// Work limits for repair search. A cap leaves the search incomplete.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct RepairOptions {
    pub conflict_calls: i64,
    pub conflict_nodes: i64,
    pub hitting_nodes: i64,
    pub verification_calls: i64,
}

impl Default for RepairOptions {
    fn default() -> Self {
        let o = unsafe { ffi::howl_default_repair_options() };
        Self {
            conflict_calls: o.conflict_calls,
            conflict_nodes: o.conflict_nodes,
            hitting_nodes: o.hitting_nodes,
            verification_calls: o.verification_calls,
        }
    }
}

impl RepairOptions {
    fn to_ffi(self) -> ffi::RepairOptions {
        ffi::RepairOptions {
            conflict_calls: self.conflict_calls,
            conflict_nodes: self.conflict_nodes,
            hitting_nodes: self.hitting_nodes,
            verification_calls: self.verification_calls,
        }
    }
}

/// One mapping axiom's canonical identity.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct AxiomRef {
    pub source: String,
    pub text: String,
}

/// A candidate that has not yet passed complete coherence and minimality checks.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct RepairCandidate {
    pub mappings: Vec<AxiomRef>,
    pub reason: String,
}

/// Whether one search phase exhausted its work, reached its cap, or remains unresolved.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct SearchPhase {
    pub exhausted: bool,
    pub capped: bool,
    pub unresolved: bool,
}

/// The conflict, hitting-set, and verification phases, in that order.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct SearchPhases {
    pub conflicts: SearchPhase,
    pub hitting_sets: SearchPhase,
    pub verification: SearchPhase,
}

/// Search work counts. They describe effort, not proof of completeness.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct SearchCounts {
    pub preflight: u64,
    pub conflict_calls: u64,
    pub conflict_nodes: u64,
    pub hitting_nodes: u64,
    pub verification_calls: u64,
    pub cache_hits: u64,
}

/// Mapping repairs are guaranteed inclusion-minimal only in `repairs`.
/// An incomplete search may still have verified repairs, but only a complete
/// search has enumerated the entire family.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct RepairSearch {
    pub complete: bool,
    pub already_coherent: bool,
    pub unrepairable_by_mappings: bool,
    pub mappings: Vec<AxiomRef>,
    pub repairs: Vec<Vec<AxiomRef>>,
    pub candidates: Vec<RepairCandidate>,
    pub omissions: Vec<String>,
    pub phases: SearchPhases,
    pub counts: SearchCounts,
}

/// The original merged classification and, if requested, mapping repair.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct AlignmentReport {
    pub merged: Report,
    pub repair: Option<RepairSearch>,
}

impl Reasoner {
    /// Classify the merge. Pass repair options to search for all minimal
    /// mapping repairs; `None` only checks merged coherence.
    pub fn align(
        &self,
        input: &AlignmentInput,
        repair: Option<RepairOptions>,
    ) -> Result<AlignmentReport, Fault> {
        self.align_run(input, repair, 0)
    }

    /// [`align`](Self::align), observing cancellation at engine boundaries.
    pub fn align_cancellable(
        &self,
        input: &AlignmentInput,
        repair: Option<RepairOptions>,
        cancel: &CancelToken,
    ) -> Result<AlignmentReport, Fault> {
        self.align_run(input, repair, cancel.as_cancel_ptr())
    }

    fn align_run(
        &self,
        input: &AlignmentInput,
        repair: Option<RepairOptions>,
        cancel: i64,
    ) -> Result<AlignmentReport, Fault> {
        let requested = repair.is_some();
        let options = repair.unwrap_or_default().to_ffi();
        let run = Run(unsafe {
            ffi::howl_run_align(
                input.input.raw,
                self.config.to_ffi(cancel),
                requested as u8,
                options,
            )
        });
        let merged = run.result()?;
        let search = if requested {
            Some(read_repair(&run))
        } else {
            None
        };
        Ok(AlignmentReport {
            merged,
            repair: search,
        })
    }
}

fn read_repair(run: &Run) -> RepairSearch {
    let r = run.0;
    unsafe {
        assert_ne!(
            ffi::howl_run_repair_requested(r),
            0,
            "the engine omitted a requested repair search"
        );
        let mappings: Vec<AxiomRef> = (0..ffi::howl_run_mapping_len(r))
            .map(|i| AxiomRef {
                source: owned(ffi::howl_run_mapping_source(r, i)),
                text: owned(ffi::howl_run_mapping_text(r, i)),
            })
            .collect();
        let repair_mappings = |i: i64| {
            (0..ffi::howl_run_repair_size(r, i))
                .map(|j| mapping_at(&mappings, ffi::howl_run_repair_mapping(r, i, j)))
                .collect()
        };
        let candidate_mappings = |i: i64| {
            (0..ffi::howl_run_candidate_size(r, i))
                .map(|j| mapping_at(&mappings, ffi::howl_run_candidate_mapping(r, i, j)))
                .collect()
        };
        let phase = |i| SearchPhase {
            exhausted: ffi::howl_run_search_phase_exhausted(r, i) != 0,
            capped: ffi::howl_run_search_phase_capped(r, i) != 0,
            unresolved: ffi::howl_run_search_phase_unresolved(r, i) != 0,
        };
        let repairs = (0..ffi::howl_run_repair_len(r))
            .map(repair_mappings)
            .collect();
        let candidates = (0..ffi::howl_run_candidate_len(r))
            .map(|i| RepairCandidate {
                mappings: candidate_mappings(i),
                reason: owned(ffi::howl_run_candidate_reason(r, i)),
            })
            .collect();
        RepairSearch {
            complete: ffi::howl_run_repair_complete(r) != 0,
            already_coherent: ffi::howl_run_already_coherent(r) != 0,
            unrepairable_by_mappings: ffi::howl_run_unrepairable(r) != 0,
            mappings,
            repairs,
            candidates,
            omissions: (0..ffi::howl_run_search_omission_len(r))
                .map(|i| owned(ffi::howl_run_search_omission(r, i)))
                .collect(),
            phases: SearchPhases {
                conflicts: phase(0),
                hitting_sets: phase(1),
                verification: phase(2),
            },
            counts: SearchCounts {
                preflight: ffi::howl_run_search_count(r, 0) as u64,
                conflict_calls: ffi::howl_run_search_count(r, 1) as u64,
                conflict_nodes: ffi::howl_run_search_count(r, 2) as u64,
                hitting_nodes: ffi::howl_run_search_count(r, 3) as u64,
                verification_calls: ffi::howl_run_search_count(r, 4) as u64,
                cache_hits: ffi::howl_run_search_count(r, 5) as u64,
            },
        }
    }
}

fn mapping_at(mappings: &[AxiomRef], index: i64) -> AxiomRef {
    mappings
        .get(index as usize)
        .unwrap_or_else(|| panic!("the engine returned mapping index {index}"))
        .clone()
}
