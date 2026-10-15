#ifndef SLOP_classify_H
#define SLOP_classify_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"
#include "slop_canon.h"

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_HOWL_TYPES_SUBPAIR_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_SubPair, slop_list_howl_types_SubPair)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_types_SubPair, slop_option_howl_types_SubPair)
#endif

uint8_t howl_classify_context_has_bottom(howl_types_Saturation sat, howl_types_Node n);
uint8_t howl_classify_detect_inconsistent(howl_types_Saturation sat, howl_types_Names names);
uint8_t howl_classify_is_individual(howl_types_Names names, howl_types_Node n);
uint8_t howl_classify_entails_sub(howl_types_Saturation sat, howl_types_Names names, uint8_t inconsistent, howl_types_Node a, howl_types_Node b);
uint8_t howl_classify_is_bottom_iri(slop_rdf_rdf_IRI iri);
slop_list_slop_rdf_rdf_IRI howl_classify_collect_unsatisfiable(slop_arena* arena, howl_types_Saturation sat, howl_types_Names names);
slop_list_howl_types_SubPair howl_classify_collect_taxonomy(slop_arena* arena, howl_types_Saturation sat, howl_types_Names names);
howl_types_Findings howl_classify_extract_findings(slop_arena* arena, howl_types_Saturation sat, howl_types_Names names);
slop_list_slop_rdf_rdf_IRI howl_classify_ksc_unsatisfiable(slop_arena* arena, howl_types_KscResult r);
slop_list_howl_types_SubPair howl_classify_ksc_taxonomy(slop_arena* arena, howl_types_KscResult r);
howl_types_Findings howl_classify_extract_ksc_findings(slop_arena* arena, howl_types_KscResult r);
uint8_t howl_classify_ksc_answer_holds(howl_types_ClassAnswer a, howl_types_KName b);
uint8_t howl_classify_ksc_entails_sub(howl_types_KscResult r, howl_types_KName a, howl_types_KName b);

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_types_SubPair, slop_option_howl_types_SubPair)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CONTEXT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CONTEXT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Context, slop_option_howl_types_Context)
#endif


#endif
