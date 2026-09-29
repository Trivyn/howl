#ifndef SLOP_main_H
#define SLOP_main_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"
#include "slop_owl2.h"
#include "slop_howl.h"
#include "slop_report.h"
#include "slop_strlib.h"
#include "slop_ttl.h"
#include "slop_vocab.h"
#include "slop_canon.h"
#include <string.h>

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

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
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

int64_t main_exit_code_for(slop_result_types_Outcome_types_Fault r);
int64_t main_max_blank_in_term(rdf_Term t);
int64_t main_max_blank_id(slop_list_rdf_Triple ts);
rdf_Term main_remap_blank(slop_arena* arena, rdf_Term t, int64_t offset);
slop_option_rdf_IRI main_ontology_iri_of(slop_list_rdf_Triple ts);
slop_string main_argv_to_string(uint8_t** argv, int64_t index);
void main_print_usage(void);
void main_eprint(slop_string s);
void main_print_timings(slop_arena* arena, int64_t t0, int64_t t1, int64_t t2, int64_t t3, int64_t t4);
uint8_t main_all_digits(slop_string s);
slop_result_howl_Prepared_types_Fault main_prepare_from(slop_arena* arena, slop_result_normalize_Decoded_types_Fault d, types_ReasonerConfig config);
slop_result_types_Outcome_types_Fault main_reason_prepared(slop_arena* arena, slop_result_howl_Prepared_types_Fault p, types_ReasonerConfig config);
void main_print_omissions(slop_arena* arena, slop_list_types_Omission os);
int main(int argc, char** _c_argv);

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif


#endif
