#ifndef SLOP_normalize_H
#define SLOP_normalize_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"

typedef struct normalize_NormResult normalize_NormResult;

#ifndef SLOP_LIST_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_TYPES_NORMAXIOM_DEFINED
SLOP_LIST_DEFINE(types_NormAxiom, slop_list_types_NormAxiom)
#endif

#ifndef SLOP_LIST_RDF_TRIPLE_DEFINED
#define SLOP_LIST_RDF_TRIPLE_DEFINED
SLOP_LIST_DEFINE(rdf_Triple, slop_list_rdf_Triple)
#endif

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

struct normalize_NormResult {
    slop_list_types_NormAxiom axioms;
    types_Saturation saturation;
    types_Coverage coverage;
};
typedef struct normalize_NormResult normalize_NormResult;

#ifndef SLOP_OPTION_NORMALIZE_NORMRESULT_DEFINED
#define SLOP_OPTION_NORMALIZE_NORMRESULT_DEFINED
SLOP_OPTION_DEFINE(normalize_NormResult, slop_option_normalize_NormResult)
#endif

#ifndef SLOP_RESULT_NORMALIZE_NORMRESULT_TYPES_FAULT_DEFINED
#define SLOP_RESULT_NORMALIZE_NORMRESULT_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { normalize_NormResult ok; types_Fault err; } data; } slop_result_normalize_NormResult_types_Fault;
#endif

slop_result_normalize_NormResult_types_Fault normalize_normalize_input(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_NORMALIZE_NORMRESULT_DEFINED
#define SLOP_OPTION_NORMALIZE_NORMRESULT_DEFINED
SLOP_OPTION_DEFINE(normalize_NormResult, slop_option_normalize_NormResult)
#endif

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif


#endif
