#ifndef SLOP_main_H
#define SLOP_main_H

#include "../runtime/slop_runtime.h"
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

#ifndef SLOP_OPTION_TERMSTORE_ENCODED_PTR_DEFINED
#define SLOP_OPTION_TERMSTORE_ENCODED_PTR_DEFINED
SLOP_OPTION_DEFINE(termstore_Encoded*, slop_option_termstore_Encoded_ptr)
#endif

#ifndef SLOP_OPTION_RESULT_PROBE_PROBING_TYPES_FAULT_DEFINED
#define SLOP_OPTION_RESULT_PROBE_PROBING_TYPES_FAULT_DEFINED
SLOP_OPTION_DEFINE(slop_result_probe_Probing_types_Fault, slop_option_result_probe_Probing_types_Fault)
#endif

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_LIST_PROBE_QUERY_DEFINED
#define SLOP_LIST_PROBE_QUERY_DEFINED
#define SLOP_LIST_PROBE_QUERY_IMPL_DEFINED
SLOP_LIST_DEFINE(probe_Query, slop_list_probe_Query)
#endif

#ifndef SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Omission, slop_list_types_Omission)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_PROBE_QUERY_DEFINED
#define SLOP_OPTION_PROBE_QUERY_DEFINED
SLOP_OPTION_DEFINE(probe_Query, slop_option_probe_Query)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

#ifndef SLOP_RESULT_TYPES_OUTCOME_TYPES_FAULT_DEFINED
#define SLOP_RESULT_TYPES_OUTCOME_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { types_Outcome ok; types_Fault err; } data; } slop_result_types_Outcome_types_Fault;
#endif

#ifndef SLOP_RESULT_NORMALIZE_DECODED_TYPES_FAULT_DEFINED
#define SLOP_RESULT_NORMALIZE_DECODED_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { normalize_Decoded ok; types_Fault err; } data; } slop_result_normalize_Decoded_types_Fault;
#endif

#ifndef SLOP_RESULT_HOWL_PREPARED_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_PREPARED_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_Prepared ok; types_Fault err; } data; } slop_result_howl_Prepared_types_Fault;
#endif

#ifndef SLOP_RESULT_PROBE_PROBING_TYPES_FAULT_DEFINED
#define SLOP_RESULT_PROBE_PROBING_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { probe_Probing ok; types_Fault err; } data; } slop_result_probe_Probing_types_Fault;
#endif

int64_t main_exit_code_for(slop_result_types_Outcome_types_Fault r);
uint8_t main_parse_into(slop_arena* arena, termstore_Encoded* enc, slop_string path);
slop_option_rdf_IRI main_ontology_iri_from(termstore_Encoded e, int64_t from);
slop_string main_argv_to_string(uint8_t** argv, int64_t index);
uint8_t main_is_version_request(int64_t argc, uint8_t** argv);
void main_print_usage(void);
void main_eprint(slop_string s);
void main_print_timings(slop_arena* arena, int64_t t0, int64_t t1, int64_t t2, int64_t t3, int64_t t4);
int64_t main_peak_mb(void);
void main_print_memory(slop_arena* arena, int64_t m1, int64_t m2, int64_t m3, int64_t m4, int64_t m5);
uint8_t main_all_digits(slop_string s);
slop_result_normalize_Decoded_types_Fault main_decode_held(slop_arena* held, slop_arena* front, termstore_Encoded doc, slop_list_rdf_IRI resolved);
slop_result_howl_Prepared_types_Fault main_prepare_from(slop_arena* arena, slop_arena* held, slop_result_normalize_Decoded_types_Fault d, types_ReasonerConfig config);
slop_result_types_Outcome_types_Fault main_reason_prepared(slop_arena* arena, slop_result_howl_Prepared_types_Fault p, types_ReasonerConfig config);
probe_Query main_cli_query(slop_arena* arena, probe_QueryKind kind, slop_string sub, slop_string sup);
slop_option_termstore_Encoded_ptr main_probe_input(slop_arena* arena, termstore_Encoded main, termstore_Encoded probes, slop_list_probe_Query queries);
slop_option_result_probe_Probing_types_Fault main_probe_of(slop_arena* arena, slop_option_termstore_Encoded_ptr doc, slop_list_rdf_IRI resolved, slop_list_probe_Query queries, types_ReasonerConfig config, slop_result_types_Outcome_types_Fault main);
slop_result_types_Outcome_types_Fault main_with_probe(slop_arena* arena, slop_result_types_Outcome_types_Fault main, slop_option_result_probe_Probing_types_Fault probed);
void main_print_probes(slop_arena* arena, slop_option_result_probe_Probing_types_Fault probed);
uint8_t main_operand(slop_string s);
void main_print_omissions(slop_arena* arena, slop_list_types_Omission os);
int main(int argc, char** _c_argv);

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_PROBE_QUERY_DEFINED
#define SLOP_OPTION_PROBE_QUERY_DEFINED
SLOP_OPTION_DEFINE(probe_Query, slop_option_probe_Query)
#endif

#ifndef SLOP_OPTION_TERMSTORE_ENCODED_PTR_DEFINED
#define SLOP_OPTION_TERMSTORE_ENCODED_PTR_DEFINED
SLOP_OPTION_DEFINE(termstore_Encoded*, slop_option_termstore_Encoded_ptr)
#endif

#ifndef SLOP_OPTION_RESULT_PROBE_PROBING_TYPES_FAULT_DEFINED
#define SLOP_OPTION_RESULT_PROBE_PROBING_TYPES_FAULT_DEFINED
SLOP_OPTION_DEFINE(slop_result_probe_Probing_types_Fault, slop_option_result_probe_Probing_types_Fault)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif


#endif
