#ifndef SLOP_howl_H
#define SLOP_howl_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_ttl.h"
#include "slop_report.h"
#include "slop_probe.h"
#include "slop_owl2.h"
#include "slop_types.h"
#include "slop_normalize.h"
#include "slop_termstore.h"
#include "slop_select.h"
#include "slop_saturate.h"
#include "slop_classify.h"
#include "slop_gate.h"
#include "slop_canon.h"
#include "slop_sriqclauses.h"
#include "slop_sriqref.h"
#include "slop_sriqabox.h"
#include "slop_kscnormal.h"
#include "slop_kscsat.h"
#include "slop_premise.h"

typedef struct howl_ElWork howl_ElWork;
typedef struct howl_KscWork howl_KscWork;
typedef struct howl_SriqWork howl_SriqWork;
typedef struct howl_Work howl_Work;
typedef struct howl_Prepared howl_Prepared;
typedef struct howl_Input howl_Input;
typedef struct howl_Run howl_Run;
typedef struct howl_InputState howl_InputState;
typedef struct howl_Options howl_Options;
typedef struct howl_TermIn howl_TermIn;
typedef struct howl_TurtleResult howl_TurtleResult;
typedef struct howl_RunState howl_RunState;

typedef enum {
    howl_FaultKind_fault_none,
    howl_FaultKind_fault_cancelled,
    howl_FaultKind_fault_input_error,
    howl_FaultKind_fault_unavailable,
    howl_FaultKind_fault_invalid_options
} howl_FaultKind;

#ifndef SLOP_LIST_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_TYPES_NORMAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_NormAxiom, slop_list_types_NormAxiom)
#endif

#ifndef SLOP_LIST_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_TYPES_KSCAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KscAxiom, slop_list_types_KscAxiom)
#endif

#ifndef SLOP_LIST_TYPES_KNAME_DEFINED
#define SLOP_LIST_TYPES_KNAME_DEFINED
#define SLOP_LIST_TYPES_KNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KName, slop_list_types_KName)
#endif

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_LIST_RDF_TRIPLE_DEFINED
#define SLOP_LIST_RDF_TRIPLE_DEFINED
#define SLOP_LIST_RDF_TRIPLE_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_Triple, slop_list_rdf_Triple)
#endif

#ifndef SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Omission, slop_list_types_Omission)
#endif

#ifndef SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawAxiom, slop_list_owl2_RawAxiom)
#endif

#ifndef SLOP_LIST_PROBE_QUERY_DEFINED
#define SLOP_LIST_PROBE_QUERY_DEFINED
#define SLOP_LIST_PROBE_QUERY_IMPL_DEFINED
SLOP_LIST_DEFINE(probe_Query, slop_list_probe_Query)
#endif

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_KNAME_DEFINED
#define SLOP_OPTION_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(types_KName, slop_option_types_KName)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_PROBE_QUERY_DEFINED
#define SLOP_OPTION_PROBE_QUERY_DEFINED
SLOP_OPTION_DEFINE(probe_Query, slop_option_probe_Query)
#endif

#ifndef SLOP_OPTION_TYPES_OUTCOME_DEFINED
#define SLOP_OPTION_TYPES_OUTCOME_DEFINED
SLOP_OPTION_DEFINE(types_Outcome, slop_option_types_Outcome)
#endif

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

#ifndef SLOP_OPTION_PROBE_ANSWERED_DEFINED
#define SLOP_OPTION_PROBE_ANSWERED_DEFINED
SLOP_OPTION_DEFINE(probe_Answered, slop_option_probe_Answered)
#endif

struct howl_ElWork {
    slop_list_types_NormAxiom axioms;
    premise_RuleIndex index;
    types_Saturation saturation;
};
typedef struct howl_ElWork howl_ElWork;

#ifndef SLOP_OPTION_HOWL_ELWORK_DEFINED
#define SLOP_OPTION_HOWL_ELWORK_DEFINED
SLOP_OPTION_DEFINE(howl_ElWork, slop_option_howl_ElWork)
#endif

struct howl_KscWork {
    slop_list_types_KscAxiom axioms;
    slop_list_types_KName classes;
};
typedef struct howl_KscWork howl_KscWork;

#ifndef SLOP_OPTION_HOWL_KSCWORK_DEFINED
#define SLOP_OPTION_HOWL_KSCWORK_DEFINED
SLOP_OPTION_DEFINE(howl_KscWork, slop_option_howl_KscWork)
#endif

struct howl_SriqWork {
    sriqref_RefIn h;
    sriqref_RefIn c;
    uint8_t has_c;
    slop_list_rdf_IRI classes;
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
    types_Profile profile;
    howl_Work work;
    types_Coverage coverage;
    types_Names names;
};
typedef struct howl_Prepared howl_Prepared;

#ifndef SLOP_OPTION_HOWL_PREPARED_DEFINED
#define SLOP_OPTION_HOWL_PREPARED_DEFINED
SLOP_OPTION_DEFINE(howl_Prepared, slop_option_howl_Prepared)
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
    termstore_Encoded* enc;
    slop_list_rdf_IRI imports;
    int64_t documents;
    termstore_Encoded* probes;
    int64_t probe_docs;
    slop_list_probe_Query queries;
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
    types_Profile profile;
    uint8_t auto_select;
    int64_t cancel;
};
typedef struct howl_Options howl_Options;

#ifndef SLOP_OPTION_HOWL_OPTIONS_DEFINED
#define SLOP_OPTION_HOWL_OPTIONS_DEFINED
SLOP_OPTION_DEFINE(howl_Options, slop_option_howl_Options)
#endif

struct howl_TermIn {
    rdf_TermKind kind;
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
    slop_option_types_Outcome outcome;
    howl_FaultKind fault;
    slop_string message;
    types_Profile fault_profile;
    types_Verdict verdict;
    probe_Probing probing;
    slop_list_string lines;
};
typedef struct howl_RunState howl_RunState;

#ifndef SLOP_OPTION_HOWL_RUNSTATE_DEFINED
#define SLOP_OPTION_HOWL_RUNSTATE_DEFINED
SLOP_OPTION_DEFINE(howl_RunState, slop_option_howl_RunState)
#endif

#ifndef SLOP_RESULT_NORMALIZE_DECODED_TYPES_FAULT_DEFINED
#define SLOP_RESULT_NORMALIZE_DECODED_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { normalize_Decoded ok; types_Fault err; } data; } slop_result_normalize_Decoded_types_Fault;
#endif

#ifndef SLOP_RESULT_HOWL_PREPARED_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_PREPARED_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_Prepared ok; types_Fault err; } data; } slop_result_howl_Prepared_types_Fault;
#endif

#ifndef SLOP_RESULT_TYPES_OUTCOME_TYPES_FAULT_DEFINED
#define SLOP_RESULT_TYPES_OUTCOME_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { types_Outcome ok; types_Fault err; } data; } slop_result_types_Outcome_types_Fault;
#endif

#ifndef SLOP_RESULT_PROBE_PROBING_TYPES_FAULT_DEFINED
#define SLOP_RESULT_PROBE_PROBING_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { probe_Probing ok; types_Fault err; } data; } slop_result_probe_Probing_types_Fault;
#endif

slop_result_normalize_Decoded_types_Fault howl_decode(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved);
slop_result_normalize_Decoded_types_Fault howl_decode_from(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved);
slop_result_normalize_Decoded_types_Fault howl_own_decoded(slop_arena* arena, slop_result_normalize_Decoded_types_Fault r);
slop_result_normalize_Decoded_types_Fault howl_decode_owned(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved);
slop_result_howl_Prepared_types_Fault howl_prepare_decoded(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config);
int64_t howl_out_of_profile_count(slop_list_types_Omission oms);
types_Profile howl_auto_profile(normalize_Decoded d);
slop_result_howl_Prepared_types_Fault howl_prepare_in_profile(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config, types_Profile profile);
uint8_t howl_strict_refuses(types_ReasonerConfig config, types_Coverage cov);
slop_result_howl_Prepared_types_Fault howl_prepare_el(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config, types_Profile profile);
slop_result_howl_Prepared_types_Fault howl_prepare_ksc(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config, types_Profile profile);
slop_result_howl_Prepared_types_Fault howl_prepare_sriq(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config, types_Profile profile);
slop_result_howl_Prepared_types_Fault howl_sriq_prepared(slop_arena* arena, types_ReasonerConfig config, types_Profile profile, slop_list_types_Omission gate_oms, sriqabox_Inputs in);
slop_list_types_Omission howl_sriq_omissions(slop_arena* arena, slop_list_types_Omission gate_oms, slop_list_owl2_RawAxiom s1);
slop_list_types_Omission howl_distinct_omissions(slop_arena* arena, slop_list_types_Omission os);
sriqref_RefIn howl_copy_refin(slop_arena* arena, sriqref_RefIn in);
slop_list_rdf_IRI howl_query_iris(slop_arena* arena, sriqclauses_SriqIds ids);
slop_list_types_KName howl_copy_knames(slop_arena* arena, slop_list_types_KName ns);
slop_result_howl_Prepared_types_Fault howl_prepare(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);
slop_result_types_Outcome_types_Fault howl_reason(slop_arena* arena, howl_Prepared p, types_ReasonerConfig config);
slop_result_types_Outcome_types_Fault howl_sriq_reason(slop_arena* arena, howl_Prepared p, howl_SriqWork w, types_ReasonerConfig config);
types_Outcome howl_sriq_outcome(slop_arena* arena, howl_Prepared p, howl_SriqWork w, sriqabox_SplitRun sp);
slop_result_types_Outcome_types_Fault howl_classify(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);
void howl_release_outcome(types_Outcome o);
slop_result_howl_Prepared_types_Fault howl_prepare_encoded(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);
slop_result_types_Outcome_types_Fault howl_classify_encoded(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);
slop_result_probe_Probing_types_Fault howl_probe_encoded(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved, slop_list_probe_Query queries, types_ReasonerConfig config);
slop_result_probe_Probing_types_Fault howl_probe_outcome(slop_arena* arena, slop_result_types_Outcome_types_Fault r, slop_list_probe_Query queries);
probe_Probing howl_probing_of(slop_arena* arena, types_Outcome o, slop_list_probe_Query queries);
probe_Probing howl_no_probing(slop_arena* arena);
howl_InputState* howl_input_state(howl_Input in);
howl_RunState howl_run_state(howl_Run r);
howl_Input howl_input_new(void);
void howl_input_free(howl_Input in);
void howl_input_begin_document(howl_Input in);
void howl_input_begin_probe_document(howl_Input in);
termstore_Encoded* howl_target(howl_InputState st, uint8_t probe);
void howl_begin_in(howl_Input in, uint8_t probe);
slop_option_string howl_optional_string(slop_string s);
slop_option_rdf_Term howl_make_term(slop_arena* arena, howl_TermIn t);
uint8_t howl_input_add_triple(howl_Input in, howl_TermIn s, howl_TermIn p, howl_TermIn o);
uint8_t howl_input_add_probe_triple(howl_Input in, howl_TermIn s, howl_TermIn p, howl_TermIn o);
uint8_t howl_add_triple_to(howl_Input in, uint8_t probe, howl_TermIn s, howl_TermIn p, howl_TermIn o);
howl_TurtleResult howl_input_add_turtle(howl_Input in, slop_string text);
howl_TurtleResult howl_input_add_probe_turtle(howl_Input in, slop_string text);
howl_TurtleResult howl_add_turtle_to(howl_Input in, uint8_t probe, slop_string text);
void howl_input_attest_import(howl_Input in, slop_string iri);
void howl_input_ask_unsatisfiable(howl_Input in, slop_string cls);
void howl_input_ask_subsumed(howl_Input in, slop_string sub, slop_string sup);
void howl_ask(howl_Input in, probe_QueryKind kind, slop_string sub, slop_string sup);
howl_Options howl_default_options(void);
slop_option_string howl_options_problem(howl_Options o);
types_ReasonerConfig howl_options_config(howl_Options o);
howl_Run howl_new_run(slop_arena* a, howl_RunState st);
howl_Run howl_faulted(slop_arena* a, howl_FaultKind kind, slop_string message, types_Profile profile);
howl_Run howl_run_classify(howl_Input in, howl_Options o);
howl_Run howl_run_faulted(slop_arena* a, types_Fault f, slop_string prefix, types_Profile profile);
howl_Run howl_with_probes(slop_arena* a, howl_InputState st, types_Outcome out, howl_Options o);
howl_Run howl_finished(slop_arena* a, types_Outcome out, probe_Probing p, uint8_t asked);
void howl_run_free(howl_Run r);
uint8_t howl_run_ok(howl_Run r);
howl_FaultKind howl_run_fault(howl_Run r);
slop_string howl_run_fault_message(howl_Run r);
types_Profile howl_run_fault_profile(howl_Run r);
types_Profile howl_run_profile(howl_Run r);
types_Verdict howl_run_verdict(howl_Run r);
uint8_t howl_run_inconsistent(howl_Run r);
types_Termination howl_run_termination(howl_Run r);
int64_t howl_run_rounds(howl_Run r);
int64_t howl_run_unsat_len(howl_Run r);
slop_string howl_run_unsat(howl_Run r, int64_t i);
int64_t howl_run_sub_len(howl_Run r);
slop_string howl_run_sub(howl_Run r, int64_t i);
slop_string howl_run_super(howl_Run r, int64_t i);
int64_t howl_run_omission_len(howl_Run r);
slop_string howl_run_omission(howl_Run r, int64_t i);
int64_t howl_run_probe_len(howl_Run r);
slop_option_probe_Answered howl_probe_at(howl_Run r, int64_t i);
probe_QueryKind howl_run_probe_kind(howl_Run r, int64_t i);
slop_string howl_run_probe_sub(howl_Run r, int64_t i);
slop_string howl_run_probe_sup(howl_Run r, int64_t i);
probe_ProbeAnswer howl_run_probe_answer(howl_Run r, int64_t i);
uint8_t howl_run_probe_inconsistent(howl_Run r);
int64_t howl_run_probe_omission_len(howl_Run r);
slop_string howl_run_probe_omission(howl_Run r, int64_t i);
int64_t howl_run_report_len(howl_Run r);
slop_string howl_run_report_line(howl_Run r, int64_t i);

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_ELWORK_DEFINED
#define SLOP_OPTION_HOWL_ELWORK_DEFINED
SLOP_OPTION_DEFINE(howl_ElWork, slop_option_howl_ElWork)
#endif

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_KNAME_DEFINED
#define SLOP_OPTION_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(types_KName, slop_option_types_KName)
#endif

#ifndef SLOP_OPTION_HOWL_KSCWORK_DEFINED
#define SLOP_OPTION_HOWL_KSCWORK_DEFINED
SLOP_OPTION_DEFINE(howl_KscWork, slop_option_howl_KscWork)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQWORK_DEFINED
#define SLOP_OPTION_HOWL_SRIQWORK_DEFINED
SLOP_OPTION_DEFINE(howl_SriqWork, slop_option_howl_SriqWork)
#endif

#ifndef SLOP_OPTION_HOWL_WORK_DEFINED
#define SLOP_OPTION_HOWL_WORK_DEFINED
SLOP_OPTION_DEFINE(howl_Work, slop_option_howl_Work)
#endif

#ifndef SLOP_OPTION_HOWL_PREPARED_DEFINED
#define SLOP_OPTION_HOWL_PREPARED_DEFINED
SLOP_OPTION_DEFINE(howl_Prepared, slop_option_howl_Prepared)
#endif

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_PROBE_QUERY_DEFINED
#define SLOP_OPTION_PROBE_QUERY_DEFINED
SLOP_OPTION_DEFINE(probe_Query, slop_option_probe_Query)
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

#ifndef SLOP_OPTION_TYPES_OUTCOME_DEFINED
#define SLOP_OPTION_TYPES_OUTCOME_DEFINED
SLOP_OPTION_DEFINE(types_Outcome, slop_option_types_Outcome)
#endif

#ifndef SLOP_OPTION_HOWL_RUNSTATE_DEFINED
#define SLOP_OPTION_HOWL_RUNSTATE_DEFINED
SLOP_OPTION_DEFINE(howl_RunState, slop_option_howl_RunState)
#endif

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

#ifndef SLOP_OPTION_PROBE_ANSWERED_DEFINED
#define SLOP_OPTION_PROBE_ANSWERED_DEFINED
SLOP_OPTION_DEFINE(probe_Answered, slop_option_probe_Answered)
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

#ifndef SLOP_LIST_PROBE_ANSWERED_DEFINED
#define SLOP_LIST_PROBE_ANSWERED_DEFINED
#define SLOP_LIST_PROBE_ANSWERED_IMPL_DEFINED
SLOP_LIST_DEFINE(probe_Answered, slop_list_probe_Answered)
#endif


#endif
