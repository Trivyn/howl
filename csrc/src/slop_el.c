#include "../runtime/slop_runtime.h"
#include "slop_el.h"

slop_list_types_Addressed el_apply_el_rules(slop_arena* arena, types_Context ctx, types_Derived incoming, slop_list_types_NormAxiom axioms);

slop_list_types_Addressed el_apply_el_rules(slop_arena* arena, types_Context ctx, types_Derived incoming, slop_list_types_NormAxiom axioms) {
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = (types_Addressed*)slop_arena_alloc(arena, 16 * sizeof(types_Addressed)), .len = 0, .cap = 16 });
        return result;
    }
}

