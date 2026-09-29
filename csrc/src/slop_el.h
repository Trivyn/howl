#ifndef SLOP_el_H
#define SLOP_el_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"
#include "slop_premise.h"

#ifndef SLOP_LIST_TYPES_ADDRESSED_DEFINED
#define SLOP_LIST_TYPES_ADDRESSED_DEFINED
#define SLOP_LIST_TYPES_ADDRESSED_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Addressed, slop_list_types_Addressed)
#endif

#ifndef SLOP_LIST_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_TYPES_NORMAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_NormAxiom, slop_list_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(types_Addressed, slop_option_types_Addressed)
#endif

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

types_Node el_ex_x(void);
types_Node el_ex_a(void);
types_Node el_ex_b(void);
types_Node el_ex_c(void);
types_RoleId el_ex_r(void);
types_Context el_ex_ctx(slop_arena* arena);
types_Context el_ex_ctx_bottom(slop_arena* arena);
slop_list_types_Addressed el_cr_sub_name_on_sub(slop_arena* arena, types_Context ctx, types_Node b, types_NormAxiom ax);
slop_list_types_Addressed el_cr_and_on_sub(slop_arena* arena, types_Context ctx, types_Node b, types_NormAxiom ax);
slop_list_types_Addressed el_cr_some_rhs_on_sub(slop_arena* arena, types_Context ctx, types_Node b, types_NormAxiom ax);
slop_list_types_Addressed el_cr_exists_lhs_on_sub(slop_arena* arena, types_Context ctx, types_Node b, types_NormAxiom ax);
slop_list_types_Addressed el_cr_exists_lhs_on_pred(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node x, types_NormAxiom ax);
slop_list_types_Addressed el_cr_bottom_on_sub(slop_arena* arena, types_Context ctx, types_Node b);
slop_list_types_Addressed el_cr_bottom_on_pred(slop_arena* arena, types_Context ctx, types_Node x);
slop_list_types_Addressed el_cr_role_incl_on_succ(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node y, types_NormAxiom ax);
slop_list_types_Addressed el_cr_chain_on_pred(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node x, types_NormAxiom ax);
slop_list_types_Addressed el_cr_chain_on_succ(slop_arena* arena, types_Context ctx, types_RoleId s, types_Node z, types_NormAxiom ax);
slop_list_types_Addressed el_apply_el_rules(slop_arena* arena, types_Context ctx, types_Derived incoming, premise_RuleIndex idx);
slop_list_types_Addressed el_apply_el_rules_reference(slop_arena* arena, types_Context ctx, types_Derived incoming, slop_list_types_NormAxiom axioms);

#ifndef SLOP_OPTION_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(types_Addressed, slop_option_types_Addressed)
#endif

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_OPTION_PREMISE_AXLIST_DEFINED
#define SLOP_OPTION_PREMISE_AXLIST_DEFINED
SLOP_OPTION_DEFINE(premise_AxList, slop_option_premise_AxList)
#endif

#ifndef SLOP_OPTION_PREMISE_PARTNERS_DEFINED
#define SLOP_OPTION_PREMISE_PARTNERS_DEFINED
SLOP_OPTION_DEFINE(premise_Partners, slop_option_premise_Partners)
#endif


#endif
