#ifndef SLOP_classify_H
#define SLOP_classify_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"
#include "slop_canon.h"

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_LIST_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_TYPES_SUBPAIR_IMPL_DEFINED
SLOP_LIST_DEFINE(types_SubPair, slop_list_types_SubPair)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(types_SubPair, slop_option_types_SubPair)
#endif

uint8_t classify_context_has_bottom(types_Saturation sat, types_Node n);
uint8_t classify_detect_inconsistent(types_Saturation sat);
uint8_t classify_entails_sub(types_Saturation sat, uint8_t inconsistent, types_Node a, types_Node b);
uint8_t classify_is_bottom_iri(rdf_IRI iri);
slop_list_rdf_IRI classify_collect_unsatisfiable(slop_arena* arena, types_Saturation sat);
slop_list_types_SubPair classify_collect_taxonomy(slop_arena* arena, types_Saturation sat);
types_Findings classify_extract_findings(slop_arena* arena, types_Saturation sat);

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(types_SubPair, slop_option_types_SubPair)
#endif

#ifndef SLOP_OPTION_TYPES_CONTEXT_DEFINED
#define SLOP_OPTION_TYPES_CONTEXT_DEFINED
SLOP_OPTION_DEFINE(types_Context, slop_option_types_Context)
#endif


#endif
