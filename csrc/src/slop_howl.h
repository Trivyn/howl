#ifndef SLOP_howl_H
#define SLOP_howl_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_ttl.h"
#include "slop_report.h"
#include "slop_probe.h"
#include "slop_locality.h"
#include "slop_owl2.h"
#include "slop_types.h"
#include "slop_normalize.h"
#include "slop_termstore.h"
#include "slop_select.h"
#include "slop_saturate.h"
#include "slop_classify.h"
#include "slop_gate.h"
#include "slop_canon.h"
#include "slop_strlib.h"
#include "slop_sriqclauses.h"
#include "slop_sriqref.h"
#include "slop_sriqabox.h"
#include "slop_kscnormal.h"
#include "slop_kscsat.h"
#include "slop_premise.h"

typedef struct howl_ElWork howl_ElWork;
typedef struct howl_KscWork howl_KscWork;
typedef struct howl_SriqWork howl_SriqWork;
typedef struct howl_StepDown howl_StepDown;
typedef struct howl_AutoChoice howl_AutoChoice;
typedef struct howl_Work howl_Work;
typedef struct howl_Prepared howl_Prepared;
typedef struct howl_ModulePrepared howl_ModulePrepared;
typedef struct howl_Input howl_Input;
typedef struct howl_Run howl_Run;
typedef struct howl_InputState howl_InputState;
typedef struct howl_Options howl_Options;
typedef struct howl_TermIn howl_TermIn;
typedef struct howl_TurtleResult howl_TurtleResult;
typedef struct howl_RunState howl_RunState;

typedef enum {
    howl_DocumentSource_document_none,
    howl_DocumentSource_document_input,
    howl_DocumentSource_document_probe
} howl_DocumentSource;

typedef enum {
    howl_FaultKind_fault_none,
    howl_FaultKind_fault_cancelled,
    howl_FaultKind_fault_input_error,
    howl_FaultKind_fault_unavailable,
    howl_FaultKind_fault_invalid_options
} howl_FaultKind;

#ifndef SLOP_OPTION_LIST_STRING_DEFINED
#define SLOP_OPTION_LIST_STRING_DEFINED
SLOP_OPTION_DEFINE(slop_list_string, slop_option_list_string)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_NORMAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_NormAxiom, slop_list_howl_types_NormAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KSCAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KscAxiom, slop_list_howl_types_KscAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_KNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_KNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_KNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KName, slop_list_howl_types_KName)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TRIPLE_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_Triple, slop_list_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Omission, slop_list_howl_types_Omission)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_OMISSIONCAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSIONCAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSIONCAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_OmissionCause, slop_list_howl_types_OmissionCause)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawAxiom, slop_list_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_PROFILE_DEFINED
#define SLOP_LIST_HOWL_TYPES_PROFILE_DEFINED
#define SLOP_LIST_HOWL_TYPES_PROFILE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Profile, slop_list_howl_types_Profile)
#endif

#ifndef SLOP_LIST_HOWL_PROBE_QUERY_DEFINED
#define SLOP_LIST_HOWL_PROBE_QUERY_DEFINED
#define SLOP_LIST_HOWL_PROBE_QUERY_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_probe_Query, slop_list_howl_probe_Query)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_NormAxiom, slop_option_howl_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscAxiom, slop_option_howl_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_KName, slop_option_howl_types_KName)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Triple, slop_option_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSIONCAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSIONCAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_OmissionCause, slop_option_howl_types_OmissionCause)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_PROFILE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_PROFILE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Profile, slop_option_howl_types_Profile)
#endif

#ifndef SLOP_OPTION_HOWL_PROBE_QUERY_DEFINED
#define SLOP_OPTION_HOWL_PROBE_QUERY_DEFINED
SLOP_OPTION_DEFINE(howl_probe_Query, slop_option_howl_probe_Query)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OUTCOME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OUTCOME_DEFINED
SLOP_OPTION_DEFINE(howl_types_Outcome, slop_option_howl_types_Outcome)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_HOWL_PROBE_ANSWERED_DEFINED
#define SLOP_OPTION_HOWL_PROBE_ANSWERED_DEFINED
SLOP_OPTION_DEFINE(howl_probe_Answered, slop_option_howl_probe_Answered)
#endif

struct howl_ElWork {
    slop_list_howl_types_NormAxiom axioms;
    howl_premise_RuleIndex index;
    howl_types_Saturation saturation;
};
typedef struct howl_ElWork howl_ElWork;

#ifndef SLOP_OPTION_HOWL_ELWORK_DEFINED
#define SLOP_OPTION_HOWL_ELWORK_DEFINED
SLOP_OPTION_DEFINE(howl_ElWork, slop_option_howl_ElWork)
#endif

struct howl_KscWork {
    slop_list_howl_types_KscAxiom axioms;
    slop_list_howl_types_KName classes;
};
typedef struct howl_KscWork howl_KscWork;

#ifndef SLOP_OPTION_HOWL_KSCWORK_DEFINED
#define SLOP_OPTION_HOWL_KSCWORK_DEFINED
SLOP_OPTION_DEFINE(howl_KscWork, slop_option_howl_KscWork)
#endif

struct howl_StepDown {
    howl_types_Profile profile;
    howl_normalize_Decoded decoded;
};
typedef struct howl_StepDown howl_StepDown;

#ifndef SLOP_OPTION_HOWL_STEPDOWN_DEFINED
#define SLOP_OPTION_HOWL_STEPDOWN_DEFINED
SLOP_OPTION_DEFINE(howl_StepDown, slop_option_howl_StepDown)
#endif

struct howl_AutoChoice {
    howl_types_Profile profile;
    howl_types_Profile low;
};
typedef struct howl_AutoChoice howl_AutoChoice;

#ifndef SLOP_OPTION_HOWL_AUTOCHOICE_DEFINED
#define SLOP_OPTION_HOWL_AUTOCHOICE_DEFINED
SLOP_OPTION_DEFINE(howl_AutoChoice, slop_option_howl_AutoChoice)
#endif

struct howl_Input {
    void* p;
};
typedef struct howl_Input howl_Input;

#ifndef SLOP_OPTION_HOWL_INPUT_DEFINED
#define SLOP_OPTION_HOWL_INPUT_DEFINED
SLOP_OPTION_DEFINE(howl_Input, slop_option_howl_Input)
#endif

struct howl_Run {
    void* p;
};
typedef struct howl_Run howl_Run;

#ifndef SLOP_OPTION_HOWL_RUN_DEFINED
#define SLOP_OPTION_HOWL_RUN_DEFINED
SLOP_OPTION_DEFINE(howl_Run, slop_option_howl_Run)
#endif

struct howl_InputState {
    slop_arena* arena;
    slop_arena* scratch;
    howl_termstore_Encoded* enc;
    slop_list_slop_rdf_rdf_IRI imports;
    int64_t documents;
    howl_termstore_Encoded* probes;
    int64_t probe_docs;
    slop_list_howl_probe_Query queries;
    slop_option_string failed;
};
typedef struct howl_InputState howl_InputState;

#ifndef SLOP_OPTION_HOWL_INPUTSTATE_DEFINED
#define SLOP_OPTION_HOWL_INPUTSTATE_DEFINED
SLOP_OPTION_DEFINE(howl_InputState, slop_option_howl_InputState)
#endif

struct howl_Options {
    int64_t workers;
    int64_t max_iterations;
    howl_types_Profile profile;
    uint8_t auto_select;
    int64_t cancel;
};
typedef struct howl_Options howl_Options;

#ifndef SLOP_OPTION_HOWL_OPTIONS_DEFINED
#define SLOP_OPTION_HOWL_OPTIONS_DEFINED
SLOP_OPTION_DEFINE(howl_Options, slop_option_howl_Options)
#endif

struct howl_TermIn {
    slop_rdf_rdf_TermKind kind;
    int64_t blank;
    slop_string value;
    slop_string datatype;
    slop_string lang;
};
typedef struct howl_TermIn howl_TermIn;

#ifndef SLOP_OPTION_HOWL_TERMIN_DEFINED
#define SLOP_OPTION_HOWL_TERMIN_DEFINED
SLOP_OPTION_DEFINE(howl_TermIn, slop_option_howl_TermIn)
#endif

struct howl_TurtleResult {
    uint8_t ok;
    slop_string message;
    int64_t line;
    int64_t column;
};
typedef struct howl_TurtleResult howl_TurtleResult;

#ifndef SLOP_OPTION_HOWL_TURTLERESULT_DEFINED
#define SLOP_OPTION_HOWL_TURTLERESULT_DEFINED
SLOP_OPTION_DEFINE(howl_TurtleResult, slop_option_howl_TurtleResult)
#endif

struct howl_RunState {
    slop_arena* arena;
    slop_option_howl_types_Outcome outcome;
    howl_FaultKind fault;
    slop_string message;
    howl_types_Profile fault_profile;
    howl_types_Verdict verdict;
    howl_probe_Probing probing;
    slop_list_string lines;
};
typedef struct howl_RunState howl_RunState;

#ifndef SLOP_OPTION_HOWL_RUNSTATE_DEFINED
#define SLOP_OPTION_HOWL_RUNSTATE_DEFINED
SLOP_OPTION_DEFINE(howl_RunState, slop_option_howl_RunState)
#endif

struct howl_SriqWork {
    howl_sriqref_RefIn h;
    howl_sriqref_RefIn c;
    uint8_t has_c;
    slop_list_slop_rdf_rdf_IRI classes;
    slop_option_howl_StepDown step;
};
typedef struct howl_SriqWork howl_SriqWork;

#ifndef SLOP_OPTION_HOWL_SRIQWORK_DEFINED
#define SLOP_OPTION_HOWL_SRIQWORK_DEFINED
SLOP_OPTION_DEFINE(howl_SriqWork, slop_option_howl_SriqWork)
#endif

typedef enum {
    howl_Work_el_work,
    howl_Work_ksc_work,
    howl_Work_sriq_work
} howl_Work_tag;

struct howl_Work {
    howl_Work_tag tag;
    union {
        howl_ElWork el_work;
        howl_KscWork ksc_work;
        howl_SriqWork sriq_work;
    } data;
};
typedef struct howl_Work howl_Work;

#ifndef SLOP_OPTION_HOWL_WORK_DEFINED
#define SLOP_OPTION_HOWL_WORK_DEFINED
SLOP_OPTION_DEFINE(howl_Work, slop_option_howl_Work)
#endif

struct howl_Prepared {
    howl_types_Profile profile;
    howl_Work work;
    howl_types_Coverage coverage;
    howl_types_Names names;
};
typedef struct howl_Prepared howl_Prepared;

#ifndef SLOP_OPTION_HOWL_PREPARED_DEFINED
#define SLOP_OPTION_HOWL_PREPARED_DEFINED
SLOP_OPTION_DEFINE(howl_Prepared, slop_option_howl_Prepared)
#endif

struct howl_ModulePrepared {
    howl_Prepared prepared;
    uint8_t shared;
};
typedef struct howl_ModulePrepared howl_ModulePrepared;

#ifndef SLOP_OPTION_HOWL_MODULEPREPARED_DEFINED
#define SLOP_OPTION_HOWL_MODULEPREPARED_DEFINED
SLOP_OPTION_DEFINE(howl_ModulePrepared, slop_option_howl_ModulePrepared)
#endif

#ifndef SLOP_RESULT_HOWL_NORMALIZE_DECODED_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_NORMALIZE_DECODED_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_normalize_Decoded ok; howl_types_Fault err; } data; } slop_result_howl_normalize_Decoded_howl_types_Fault;
#endif

#ifndef SLOP_RESULT_HOWL_PREPARED_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_PREPARED_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_Prepared ok; howl_types_Fault err; } data; } slop_result_howl_Prepared_howl_types_Fault;
#endif

#ifndef SLOP_RESULT_HOWL_TYPES_OUTCOME_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_TYPES_OUTCOME_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_types_Outcome ok; howl_types_Fault err; } data; } slop_result_howl_types_Outcome_howl_types_Fault;
#endif

#ifndef SLOP_RESULT_HOWL_MODULEPREPARED_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_MODULEPREPARED_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_ModulePrepared ok; howl_types_Fault err; } data; } slop_result_howl_ModulePrepared_howl_types_Fault;
#endif

#ifndef SLOP_RESULT_HOWL_PROBE_PROBING_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_PROBE_PROBING_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_probe_Probing ok; howl_types_Fault err; } data; } slop_result_howl_probe_Probing_howl_types_Fault;
#endif

slop_result_howl_normalize_Decoded_howl_types_Fault howl_decode(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved);
slop_result_howl_normalize_Decoded_howl_types_Fault howl_decode_from(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved);
slop_result_howl_normalize_Decoded_howl_types_Fault howl_own_decoded(slop_arena* arena, slop_result_howl_normalize_Decoded_howl_types_Fault r);
slop_result_howl_normalize_Decoded_howl_types_Fault howl_decode_owned(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved);
slop_result_howl_Prepared_howl_types_Fault howl_prepare_decoded(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config);
howl_Prepared howl_with_step_down(slop_arena* arena, howl_Prepared p, howl_normalize_Decoded d, howl_types_Profile low);
int64_t howl_out_of_profile_count(slop_list_howl_types_Omission oms);
howl_AutoChoice howl_auto_profile(howl_normalize_Decoded d);
int64_t howl_rung_count(slop_arena* scratch, howl_normalize_Decoded d, howl_types_Profile p);
slop_result_howl_Prepared_howl_types_Fault howl_prepare_in_profile(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config, howl_types_Profile profile);
slop_result_howl_Prepared_howl_types_Fault howl_prepare_sourced(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config, howl_types_Profile profile);
uint8_t howl_strict_refuses(howl_types_ReasonerConfig config, howl_types_Coverage cov);
slop_result_howl_Prepared_howl_types_Fault howl_prepare_el(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config, howl_types_Profile profile);
slop_result_howl_Prepared_howl_types_Fault howl_prepare_ksc(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config, howl_types_Profile profile);
slop_result_howl_Prepared_howl_types_Fault howl_prepare_sriq(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config, howl_types_Profile profile);
slop_result_howl_Prepared_howl_types_Fault howl_sriq_prepared(slop_arena* arena, howl_types_ReasonerConfig config, howl_types_Profile profile, slop_list_howl_types_Omission gate_oms, slop_list_howl_types_OmissionCause gate_causes, slop_list_string gate_witness, howl_sriqabox_Inputs in);
howl_types_Coverage howl_sriq_coverage(slop_arena* arena, slop_list_howl_types_Omission gate_oms, slop_list_howl_types_OmissionCause gate_causes, slop_list_string gate_witness, slop_list_howl_owl2_RawAxiom s1);
howl_sriqref_RefIn howl_copy_refin(slop_arena* arena, howl_sriqref_RefIn in);
slop_list_slop_rdf_rdf_IRI howl_query_iris(slop_arena* arena, howl_sriqclauses_SriqIds ids);
slop_list_howl_types_KName howl_copy_knames(slop_arena* arena, slop_list_howl_types_KName ns);
slop_result_howl_Prepared_howl_types_Fault howl_prepare(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config);
slop_result_howl_types_Outcome_howl_types_Fault howl_reason(slop_arena* arena, howl_Prepared p, howl_types_ReasonerConfig config);
slop_result_howl_types_Outcome_howl_types_Fault howl_sriq_reason(slop_arena* arena, howl_Prepared p, howl_SriqWork w, howl_types_ReasonerConfig config);
uint8_t howl_steps_down(howl_sriqabox_SplitRun sp, howl_types_Outcome o);
uint8_t howl_over_budget(howl_sriqref_RefStatus s);
slop_result_howl_types_Outcome_howl_types_Fault howl_step_down(slop_arena* arena, howl_StepDown s, howl_types_ReasonerConfig config);
howl_types_Outcome howl_stepped(slop_arena* arena, howl_types_Outcome o);
howl_types_Outcome howl_sriq_outcome(slop_arena* arena, howl_Prepared p, howl_SriqWork w, howl_sriqabox_SplitRun sp);
slop_result_howl_types_Outcome_howl_types_Fault howl_classify(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config);
void howl_release_outcome(howl_types_Outcome o);
slop_result_howl_Prepared_howl_types_Fault howl_prepare_encoded(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config);
slop_result_howl_ModulePrepared_howl_types_Fault howl_prepare_encoded_within(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config, uint8_t modular, slop_list_slop_rdf_rdf_IRI seed);
slop_result_howl_ModulePrepared_howl_types_Fault howl_prepare_module(slop_arena* arena, slop_arena* held, howl_normalize_Decoded m, howl_types_ReasonerConfig config, uint8_t modular);
slop_list_howl_types_Profile howl_answer_rungs(slop_arena* arena, howl_types_ProfileSelection selection);
howl_normalize_Decoded howl_within_seed(slop_arena* held, howl_normalize_Decoded d, uint8_t modular, slop_list_slop_rdf_rdf_IRI seed);
slop_result_howl_types_Outcome_howl_types_Fault howl_classify_encoded(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config);
slop_result_howl_probe_Probing_howl_types_Fault howl_probe_encoded(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, slop_list_howl_probe_Query queries, howl_types_ReasonerConfig config, uint8_t modular);
slop_result_howl_types_Outcome_howl_types_Fault howl_probe_classified(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config, uint8_t modular, slop_list_howl_probe_Query queries);
howl_types_ReasonerConfig howl_module_budget(howl_types_ReasonerConfig config, uint8_t omits);
slop_result_howl_types_Outcome_howl_types_Fault howl_module_or_whole(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config, int64_t gated, slop_result_howl_types_Outcome_howl_types_Fault m);
uint8_t howl_at_fixpoint(howl_types_Termination t);
slop_result_howl_types_Outcome_howl_types_Fault howl_classify_within(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config, uint8_t modular, slop_list_slop_rdf_rdf_IRI seed);
slop_list_slop_rdf_rdf_IRI howl_query_seed(slop_arena* arena, slop_list_howl_probe_Query queries);
slop_result_howl_probe_Probing_howl_types_Fault howl_probe_outcome(slop_arena* arena, slop_result_howl_types_Outcome_howl_types_Fault r, slop_list_howl_probe_Query queries);
howl_probe_Probing howl_probing_of(slop_arena* arena, howl_types_Outcome o, slop_list_howl_probe_Query queries);
howl_probe_Probing howl_no_probing(slop_arena* arena);
slop_list_int howl_copy_origins(slop_arena* arena, slop_list_int xs);
howl_InputState* howl_input_state(howl_Input in);
howl_RunState howl_run_state(howl_Run r);
howl_Input howl_input_new(void);
void howl_input_free(howl_Input in);
void howl_input_begin_document(howl_Input in);
void howl_input_begin_probe_document(howl_Input in);
howl_termstore_Encoded* howl_target(howl_InputState st, uint8_t probe);
void howl_begin_in(howl_Input in, uint8_t probe);
slop_option_string howl_optional_string(slop_string s);
slop_option_slop_rdf_rdf_Term howl_make_term(slop_arena* arena, howl_TermIn t);
uint8_t howl_input_add_triple(howl_Input in, howl_TermIn s, howl_TermIn p, howl_TermIn o);
uint8_t howl_input_add_probe_triple(howl_Input in, howl_TermIn s, howl_TermIn p, howl_TermIn o);
uint8_t howl_add_triple_to(howl_Input in, uint8_t probe, howl_TermIn s, howl_TermIn p, howl_TermIn o);
howl_TurtleResult howl_input_add_turtle(howl_Input in, slop_string text);
howl_TurtleResult howl_input_add_probe_turtle(howl_Input in, slop_string text);
howl_TurtleResult howl_add_turtle_to(howl_Input in, uint8_t probe, slop_string text);
void howl_input_attest_import(howl_Input in, slop_string iri);
void howl_input_ask_unsatisfiable(howl_Input in, slop_string cls);
void howl_input_ask_subsumed(howl_Input in, slop_string sub, slop_string sup);
void howl_ask(howl_Input in, howl_probe_QueryKind kind, slop_string sub, slop_string sup);
howl_Options howl_default_options(void);
slop_option_string howl_options_problem(howl_Options o);
howl_types_ReasonerConfig howl_options_config(howl_Options o);
howl_Run howl_new_run(slop_arena* a, howl_RunState st);
howl_Run howl_faulted(slop_arena* a, howl_FaultKind kind, slop_string message, howl_types_Profile profile);
howl_Run howl_run_classify(howl_Input in, howl_Options o);
howl_Run howl_run_faulted(slop_arena* a, howl_types_Fault f, slop_string prefix, howl_types_Profile profile);
slop_result_howl_probe_Probing_howl_types_Fault howl_probe_run(slop_arena* a, howl_InputState st, howl_Options o, uint8_t modular);
howl_Run howl_with_probes(slop_arena* a, howl_InputState st, howl_types_Outcome out, howl_Options o);
howl_Run howl_run_answer(howl_Input in, howl_Options o);
howl_Run howl_answer_of_input(slop_arena* a, howl_InputState st, howl_Options o);
howl_Run howl_answered(slop_arena* a, howl_probe_Probing p, uint8_t ran);
howl_Run howl_finished(slop_arena* a, howl_types_Outcome out, howl_probe_Probing p, uint8_t asked);
void howl_run_free(howl_Run r);
uint8_t howl_run_ok(howl_Run r);
howl_FaultKind howl_run_fault(howl_Run r);
slop_string howl_run_fault_message(howl_Run r);
howl_types_Profile howl_run_fault_profile(howl_Run r);
howl_types_Profile howl_run_profile(howl_Run r);
howl_types_Verdict howl_run_verdict(howl_Run r);
uint8_t howl_run_inconsistent(howl_Run r);
howl_types_Termination howl_run_termination(howl_Run r);
int64_t howl_run_rounds(howl_Run r);
int64_t howl_run_unsat_len(howl_Run r);
slop_string howl_run_unsat(howl_Run r, int64_t i);
int64_t howl_run_sub_len(howl_Run r);
slop_string howl_run_sub(howl_Run r, int64_t i);
slop_string howl_run_super(howl_Run r, int64_t i);
int64_t howl_run_omission_len(howl_Run r);
slop_string howl_run_omission(howl_Run r, int64_t i);
slop_string howl_omission_kind(slop_arena* arena, howl_types_Omission om);
howl_types_EntityKind howl_omission_entity_kind(howl_types_Omission om);
int64_t howl_origin_at(slop_list_int origins, int64_t i);
slop_string howl_run_omission_kind(howl_Run r, int64_t i);
howl_types_EntityKind howl_run_omission_entity_kind(howl_Run r, int64_t i);
int64_t howl_run_omission_document(howl_Run r, int64_t i);
howl_types_OmissionCause howl_omission_cause(slop_list_howl_types_Omission oms, slop_list_howl_types_OmissionCause causes, int64_t i);
howl_types_OmissionReason howl_run_omission_reason(howl_Run r, int64_t i);
slop_string howl_run_omission_reason_role(howl_Run r, int64_t i);
slop_option_list_string howl_omission_witness(slop_list_howl_types_Omission oms, slop_list_howl_types_OmissionCause causes, slop_list_string witness, int64_t i);
int64_t howl_witness_len(slop_option_list_string w);
slop_string howl_witness_at(slop_option_list_string w, int64_t k);
int64_t howl_run_omission_witness_len(howl_Run r, int64_t i);
slop_string howl_run_omission_witness(howl_Run r, int64_t i, int64_t k);
int64_t howl_run_probe_len(howl_Run r);
slop_option_howl_probe_Answered howl_probe_at(howl_Run r, int64_t i);
howl_probe_QueryKind howl_run_probe_kind(howl_Run r, int64_t i);
slop_string howl_run_probe_sub(howl_Run r, int64_t i);
slop_string howl_run_probe_sup(howl_Run r, int64_t i);
howl_probe_ProbeAnswer howl_run_probe_answer(howl_Run r, int64_t i);
uint8_t howl_run_probe_inconsistent(howl_Run r);
int64_t howl_run_probe_omission_len(howl_Run r);
slop_string howl_run_probe_omission(howl_Run r, int64_t i);
slop_string howl_run_probe_omission_kind(howl_Run r, int64_t i);
howl_types_EntityKind howl_run_probe_omission_entity_kind(howl_Run r, int64_t i);
howl_types_OmissionReason howl_run_probe_omission_reason(howl_Run r, int64_t i);
slop_string howl_run_probe_omission_reason_role(howl_Run r, int64_t i);
int64_t howl_run_probe_omission_witness_len(howl_Run r, int64_t i);
slop_string howl_run_probe_omission_witness(howl_Run r, int64_t i, int64_t k);
int64_t howl_probe_origin(howl_probe_Probing p, int64_t i);
howl_DocumentSource howl_run_probe_omission_source(howl_Run r, int64_t i);
int64_t howl_run_probe_omission_document(howl_Run r, int64_t i);
int64_t howl_run_report_len(howl_Run r);
slop_string howl_run_report_line(howl_Run r, int64_t i);

#ifndef SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_NormAxiom, slop_option_howl_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_ELWORK_DEFINED
#define SLOP_OPTION_HOWL_ELWORK_DEFINED
SLOP_OPTION_DEFINE(howl_ElWork, slop_option_howl_ElWork)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscAxiom, slop_option_howl_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_KName, slop_option_howl_types_KName)
#endif

#ifndef SLOP_OPTION_HOWL_KSCWORK_DEFINED
#define SLOP_OPTION_HOWL_KSCWORK_DEFINED
SLOP_OPTION_DEFINE(howl_KscWork, slop_option_howl_KscWork)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_STEPDOWN_DEFINED
#define SLOP_OPTION_HOWL_STEPDOWN_DEFINED
SLOP_OPTION_DEFINE(howl_StepDown, slop_option_howl_StepDown)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQWORK_DEFINED
#define SLOP_OPTION_HOWL_SRIQWORK_DEFINED
SLOP_OPTION_DEFINE(howl_SriqWork, slop_option_howl_SriqWork)
#endif

#ifndef SLOP_OPTION_HOWL_AUTOCHOICE_DEFINED
#define SLOP_OPTION_HOWL_AUTOCHOICE_DEFINED
SLOP_OPTION_DEFINE(howl_AutoChoice, slop_option_howl_AutoChoice)
#endif

#ifndef SLOP_OPTION_HOWL_WORK_DEFINED
#define SLOP_OPTION_HOWL_WORK_DEFINED
SLOP_OPTION_DEFINE(howl_Work, slop_option_howl_Work)
#endif

#ifndef SLOP_OPTION_HOWL_PREPARED_DEFINED
#define SLOP_OPTION_HOWL_PREPARED_DEFINED
SLOP_OPTION_DEFINE(howl_Prepared, slop_option_howl_Prepared)
#endif

#ifndef SLOP_OPTION_HOWL_MODULEPREPARED_DEFINED
#define SLOP_OPTION_HOWL_MODULEPREPARED_DEFINED
SLOP_OPTION_DEFINE(howl_ModulePrepared, slop_option_howl_ModulePrepared)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Triple, slop_option_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSIONCAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSIONCAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_OmissionCause, slop_option_howl_types_OmissionCause)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_PROFILE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_PROFILE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Profile, slop_option_howl_types_Profile)
#endif

#ifndef SLOP_OPTION_HOWL_PROBE_QUERY_DEFINED
#define SLOP_OPTION_HOWL_PROBE_QUERY_DEFINED
SLOP_OPTION_DEFINE(howl_probe_Query, slop_option_howl_probe_Query)
#endif

#ifndef SLOP_OPTION_HOWL_INPUT_DEFINED
#define SLOP_OPTION_HOWL_INPUT_DEFINED
SLOP_OPTION_DEFINE(howl_Input, slop_option_howl_Input)
#endif

#ifndef SLOP_OPTION_HOWL_RUN_DEFINED
#define SLOP_OPTION_HOWL_RUN_DEFINED
SLOP_OPTION_DEFINE(howl_Run, slop_option_howl_Run)
#endif

#ifndef SLOP_OPTION_HOWL_INPUTSTATE_DEFINED
#define SLOP_OPTION_HOWL_INPUTSTATE_DEFINED
SLOP_OPTION_DEFINE(howl_InputState, slop_option_howl_InputState)
#endif

#ifndef SLOP_OPTION_HOWL_OPTIONS_DEFINED
#define SLOP_OPTION_HOWL_OPTIONS_DEFINED
SLOP_OPTION_DEFINE(howl_Options, slop_option_howl_Options)
#endif

#ifndef SLOP_OPTION_HOWL_TERMIN_DEFINED
#define SLOP_OPTION_HOWL_TERMIN_DEFINED
SLOP_OPTION_DEFINE(howl_TermIn, slop_option_howl_TermIn)
#endif

#ifndef SLOP_OPTION_HOWL_TURTLERESULT_DEFINED
#define SLOP_OPTION_HOWL_TURTLERESULT_DEFINED
SLOP_OPTION_DEFINE(howl_TurtleResult, slop_option_howl_TurtleResult)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OUTCOME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OUTCOME_DEFINED
SLOP_OPTION_DEFINE(howl_types_Outcome, slop_option_howl_types_Outcome)
#endif

#ifndef SLOP_OPTION_HOWL_RUNSTATE_DEFINED
#define SLOP_OPTION_HOWL_RUNSTATE_DEFINED
SLOP_OPTION_DEFINE(howl_RunState, slop_option_howl_RunState)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_LIST_STRING_DEFINED
#define SLOP_OPTION_LIST_STRING_DEFINED
SLOP_OPTION_DEFINE(slop_list_string, slop_option_list_string)
#endif

#ifndef SLOP_OPTION_HOWL_PROBE_ANSWERED_DEFINED
#define SLOP_OPTION_HOWL_PROBE_ANSWERED_DEFINED
SLOP_OPTION_DEFINE(howl_probe_Answered, slop_option_howl_probe_Answered)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_ARENA_PTR_DEFINED
#define SLOP_OPTION_ARENA_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_arena*, slop_option_arena_ptr)
#endif

#ifndef SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_IMPL_DEFINED
SLOP_LIST_DEFINE(uint32_t, slop_list_u32)
#endif

#ifndef SLOP_LIST_ARENA_PTR_DEFINED
#define SLOP_LIST_ARENA_PTR_DEFINED
#define SLOP_LIST_ARENA_PTR_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_arena*, slop_list_arena_ptr)
#endif

#ifndef SLOP_LIST_HOWL_PROBE_ANSWERED_DEFINED
#define SLOP_LIST_HOWL_PROBE_ANSWERED_DEFINED
#define SLOP_LIST_HOWL_PROBE_ANSWERED_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_probe_Answered, slop_list_howl_probe_Answered)
#endif


#endif
