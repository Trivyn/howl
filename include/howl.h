/* howl.h - Auto-generated FFI header. Do not edit. */
#ifndef HOWL_H
#define HOWL_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Opaque runtime types */
typedef struct slop_arena slop_arena;
typedef struct slop_map slop_map;

/* Runtime value types */
typedef struct { size_t len; const char* data; } slop_string;
typedef struct { bool has_value; slop_string value; } slop_option_string;
typedef struct { void* fn; void* env; } slop_closure_t;

/* Type definitions */
typedef enum {
    howl_FaultKind_fault_none,
    howl_FaultKind_fault_cancelled,
    howl_FaultKind_fault_input_error,
    howl_FaultKind_fault_unavailable,
    howl_FaultKind_fault_invalid_options
} howl_FaultKind;

struct howl_Input {
    void* p;
};
typedef struct howl_Input howl_Input;

struct howl_Run {
    void* p;
};
typedef struct howl_Run howl_Run;

struct howl_TurtleResult {
    uint8_t ok;
    slop_string message;
    int64_t line;
    int64_t column;
};
typedef struct howl_TurtleResult howl_TurtleResult;

typedef enum {
    rdf_TermKind_iri,
    rdf_TermKind_blank,
    rdf_TermKind_literal,
    rdf_TermKind_triple
} rdf_TermKind;

struct howl_TermIn {
    rdf_TermKind kind;
    int64_t blank;
    slop_string value;
    slop_string datatype;
    slop_string lang;
};
typedef struct howl_TermIn howl_TermIn;

typedef enum {
    types_Profile_profile_el,
    types_Profile_profile_el_plus_plus,
    types_Profile_profile_horn_sriq,
    types_Profile_profile_sriq
} types_Profile;

struct howl_Options {
    int64_t workers;
    int64_t max_iterations;
    types_Profile profile;
    uint8_t auto_select;
    int64_t cancel;
};
typedef struct howl_Options howl_Options;

typedef enum {
    types_Termination_fixpoint,
    types_Termination_resource_limit
} types_Termination_tag;

struct types_Termination {
    types_Termination_tag tag;
    union {
        int64_t resource_limit;
    } data;
};
typedef struct types_Termination types_Termination;

typedef enum {
    types_Verdict_verdict_coherent,
    types_Verdict_verdict_incoherent,
    types_Verdict_verdict_inconclusive
} types_Verdict;

/* Public API */
howl_Options howl_default_options(void);
uint8_t howl_input_add_triple(howl_Input in, howl_TermIn s, howl_TermIn p, howl_TermIn o);
howl_TurtleResult howl_input_add_turtle(howl_Input in, slop_string text);
void howl_input_attest_import(howl_Input in, slop_string iri);
void howl_input_begin_document(howl_Input in);
void howl_input_free(howl_Input in);
howl_Input howl_input_new(void);
howl_Run howl_run_classify(howl_Input in, howl_Options o);
howl_FaultKind howl_run_fault(howl_Run r);
slop_string howl_run_fault_message(howl_Run r);
types_Profile howl_run_fault_profile(howl_Run r);
void howl_run_free(howl_Run r);
uint8_t howl_run_inconsistent(howl_Run r);
uint8_t howl_run_ok(howl_Run r);
slop_string howl_run_omission(howl_Run r, int64_t i);
int64_t howl_run_omission_len(howl_Run r);
types_Profile howl_run_profile(howl_Run r);
int64_t howl_run_report_len(howl_Run r);
slop_string howl_run_report_line(howl_Run r, int64_t i);
int64_t howl_run_rounds(howl_Run r);
slop_string howl_run_sub(howl_Run r, int64_t i);
int64_t howl_run_sub_len(howl_Run r);
slop_string howl_run_super(howl_Run r, int64_t i);
types_Termination howl_run_termination(howl_Run r);
slop_string howl_run_unsat(howl_Run r, int64_t i);
int64_t howl_run_unsat_len(howl_Run r);
types_Verdict howl_run_verdict(howl_Run r);

#ifdef __cplusplus
}
#endif

#endif /* HOWL_H */
