#include "../runtime/slop_runtime.h"
#include "slop_classify.h"

uint8_t classify_entails_sub(slop_arena* arena, types_Saturation sat, uint8_t inconsistent, types_Node a, types_Node b);
types_Findings classify_extract_findings(slop_arena* arena, types_Saturation sat);

uint8_t classify_entails_sub(slop_arena* arena, types_Saturation sat, uint8_t inconsistent, types_Node a, types_Node b) {
    return 0;
}

types_Findings classify_extract_findings(slop_arena* arena, types_Saturation sat) {
    types_Findings _retval = {0};
    _retval = ((types_Findings){.inconsistent = 0, .unsatisfiable = ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 }), .subsumptions = ((slop_list_types_SubPair){ .data = (types_SubPair*)slop_arena_alloc(arena, 16 * sizeof(types_SubPair)), .len = 0, .cap = 16 }), .imports_seen = ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 })});
    return _retval;
}

