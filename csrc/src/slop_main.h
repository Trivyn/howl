#ifndef SLOP_main_H
#define SLOP_main_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"
#include "slop_owl2.h"
#include "slop_howl.h"
#include "slop_probe.h"
#include "slop_termstore.h"
#include "slop_report.h"
#include "slop_select.h"
#include "slop_strlib.h"
#include "slop_ttl.h"
#include "slop_vocab.h"
#include "slop_canon.h"
#include <string.h>
#include <sys/resource.h>

#ifndef SLOP_OPTION_HOWL_TERMSTORE_ENCODED_PTR_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_ENCODED_PTR_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_Encoded*, slop_option_howl_termstore_Encoded_ptr)
#endif

#ifndef SLOP_OPTION_RESULT_HOWL_PROBE_PROBING_HOWL_TYPES_FAULT_DEFINED
#define SLOP_OPTION_RESULT_HOWL_PROBE_PROBING_HOWL_TYPES_FAULT_DEFINED
SLOP_OPTION_DEFINE(slop_result_howl_probe_Probing_howl_types_Fault, slop_option_result_howl_probe_Probing_howl_types_Fault)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_LIST_HOWL_PROBE_QUERY_DEFINED
#define SLOP_LIST_HOWL_PROBE_QUERY_DEFINED
#define SLOP_LIST_HOWL_PROBE_QUERY_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_probe_Query, slop_list_howl_probe_Query)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Omission, slop_list_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_PROBE_QUERY_DEFINED
#define SLOP_OPTION_HOWL_PROBE_QUERY_DEFINED
SLOP_OPTION_DEFINE(howl_probe_Query, slop_option_howl_probe_Query)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

#ifndef SLOP_RESULT_HOWL_TYPES_OUTCOME_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_TYPES_OUTCOME_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_types_Outcome ok; howl_types_Fault err; } data; } slop_result_howl_types_Outcome_howl_types_Fault;
#endif

#ifndef SLOP_RESULT_HOWL_NORMALIZE_DECODED_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_NORMALIZE_DECODED_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_normalize_Decoded ok; howl_types_Fault err; } data; } slop_result_howl_normalize_Decoded_howl_types_Fault;
#endif

#ifndef SLOP_RESULT_HOWL_PREPARED_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_PREPARED_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_Prepared ok; howl_types_Fault err; } data; } slop_result_howl_Prepared_howl_types_Fault;
#endif

#ifndef SLOP_RESULT_HOWL_PROBE_PROBING_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_PROBE_PROBING_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_probe_Probing ok; howl_types_Fault err; } data; } slop_result_howl_probe_Probing_howl_types_Fault;
#endif

int64_t howl_cli_main_exit_code_for(slop_result_howl_types_Outcome_howl_types_Fault r);
uint8_t howl_cli_main_parse_into(slop_arena* arena, howl_termstore_Encoded* enc, slop_string path);
slop_option_slop_rdf_rdf_IRI howl_cli_main_ontology_iri_from(howl_termstore_Encoded e, int64_t from);
slop_string howl_cli_main_argv_to_string(uint8_t** argv, int64_t index);
uint8_t howl_cli_main_is_version_request(int64_t argc, uint8_t** argv);
void howl_cli_main_print_usage(void);
void howl_cli_main_print_step_down(slop_arena* arena, slop_result_howl_types_Outcome_howl_types_Fault r);
void howl_cli_main_eprint(slop_string s);
void howl_cli_main_print_timings(slop_arena* arena, int64_t t0, int64_t t1, int64_t t2, int64_t t3, int64_t t4);
int64_t howl_cli_main_peak_mb(void);
void howl_cli_main_print_memory(slop_arena* arena, int64_t m1, int64_t m2, int64_t m3, int64_t m4, int64_t m5);
uint8_t howl_cli_main_all_digits(slop_string s);
slop_result_howl_normalize_Decoded_howl_types_Fault howl_cli_main_decode_held(slop_arena* held, slop_arena* front, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI resolved);
slop_result_howl_Prepared_howl_types_Fault howl_cli_main_prepare_from(slop_arena* arena, slop_arena* held, slop_result_howl_normalize_Decoded_howl_types_Fault d, howl_types_ReasonerConfig config);
slop_result_howl_types_Outcome_howl_types_Fault howl_cli_main_reason_prepared(slop_arena* arena, slop_result_howl_Prepared_howl_types_Fault p, howl_types_ReasonerConfig config);
howl_probe_Query howl_cli_main_cli_query(slop_arena* arena, howl_probe_QueryKind kind, slop_string sub, slop_string sup);
slop_option_howl_termstore_Encoded_ptr howl_cli_main_probe_input(slop_arena* arena, howl_termstore_Encoded main, howl_termstore_Encoded probes, slop_list_howl_probe_Query queries);
slop_option_result_howl_probe_Probing_howl_types_Fault howl_cli_main_probe_of(slop_arena* arena, slop_option_howl_termstore_Encoded_ptr doc, slop_list_slop_rdf_rdf_IRI resolved, slop_list_howl_probe_Query queries, howl_types_ReasonerConfig config, slop_result_howl_types_Outcome_howl_types_Fault main);
slop_result_howl_types_Outcome_howl_types_Fault howl_cli_main_with_probe(slop_arena* arena, slop_result_howl_types_Outcome_howl_types_Fault main, slop_option_result_howl_probe_Probing_howl_types_Fault probed);
void howl_cli_main_print_probes(slop_arena* arena, slop_option_result_howl_probe_Probing_howl_types_Fault probed);
uint8_t howl_cli_main_operand(slop_string s);
void howl_cli_main_print_omissions(slop_arena* arena, slop_list_howl_types_Omission os);
int64_t howl_cli_main_validate_run(slop_arena* arena, slop_arena* front, howl_termstore_Encoded* enc, slop_arena* pfront, howl_termstore_Encoded* penc, slop_list_slop_rdf_rdf_IRI resolved, slop_list_howl_probe_Query queries, howl_types_ReasonerConfig cfg, uint8_t report_mode, uint8_t timings, int64_t t_start);
int64_t howl_cli_main_ask_run(slop_arena* arena, slop_arena* front, howl_termstore_Encoded* enc, slop_arena* pfront, howl_termstore_Encoded* penc, slop_list_slop_rdf_rdf_IRI resolved, slop_list_howl_probe_Query queries, howl_types_ReasonerConfig cfg);
void howl_cli_main_print_ask_fault(slop_arena* arena, howl_types_Fault f);
int64_t howl_cli_main_ask_exit_code(slop_result_howl_probe_Probing_howl_types_Fault r);
int main(int argc, char** _c_argv);

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_PROBE_QUERY_DEFINED
#define SLOP_OPTION_HOWL_PROBE_QUERY_DEFINED
SLOP_OPTION_DEFINE(howl_probe_Query, slop_option_howl_probe_Query)
#endif

#ifndef SLOP_OPTION_HOWL_TERMSTORE_ENCODED_PTR_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_ENCODED_PTR_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_Encoded*, slop_option_howl_termstore_Encoded_ptr)
#endif

#ifndef SLOP_OPTION_RESULT_HOWL_PROBE_PROBING_HOWL_TYPES_FAULT_DEFINED
#define SLOP_OPTION_RESULT_HOWL_PROBE_PROBING_HOWL_TYPES_FAULT_DEFINED
SLOP_OPTION_DEFINE(slop_result_howl_probe_Probing_howl_types_Fault, slop_option_result_howl_probe_Probing_howl_types_Fault)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif


#endif
