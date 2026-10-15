#ifndef SLOP_el_H
#define SLOP_el_H

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
#include "slop_premise.h"

#ifndef SLOP_LIST_HOWL_TYPES_ADDRESSED_DEFINED
#define SLOP_LIST_HOWL_TYPES_ADDRESSED_DEFINED
#define SLOP_LIST_HOWL_TYPES_ADDRESSED_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Addressed, slop_list_howl_types_Addressed)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_RoleId, slop_list_howl_types_RoleId)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_NORMAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_NormAxiom, slop_list_howl_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(howl_types_Addressed, slop_option_howl_types_Addressed)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_NormAxiom, slop_option_howl_types_NormAxiom)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef HOWL_TYPES_ROLEID_HASH_EQ_DEFINED
#define HOWL_TYPES_ROLEID_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
static inline uint64_t slop_hash_howl_types_RoleId(const void* key) {
    const howl_types_RoleId* _k = (const howl_types_RoleId*)key;
    switch (_k->tag) {
        case howl_types_RoleId_named_role:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.named_role);
        case howl_types_RoleId_fresh_role:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.fresh_role });
        case howl_types_RoleId_inverse_role:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.inverse_role);
    }
    return 0;
}
static inline bool slop_eq_howl_types_RoleId(const void* a, const void* b) {
    const howl_types_RoleId* _a = (const howl_types_RoleId*)a;
    const howl_types_RoleId* _b = (const howl_types_RoleId*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_RoleId_named_role:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.named_role, &_b->data.named_role);
        case howl_types_RoleId_fresh_role:
            return _a->data.fresh_role == _b->data.fresh_role;
        case howl_types_RoleId_inverse_role:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.inverse_role, &_b->data.inverse_role);
    }
    return false;
}
#endif

howl_types_Node howl_el_ex_x(void);
howl_types_Node howl_el_ex_a(void);
howl_types_Node howl_el_ex_b(void);
howl_types_Node howl_el_ex_c(void);
howl_types_RoleId howl_el_ex_r(void);
howl_types_Context howl_el_ex_ctx(slop_arena* arena);
howl_types_Context howl_el_ex_ctx_bottom(slop_arena* arena);
slop_list_howl_types_Addressed howl_el_cr_sub_name_on_sub(slop_arena* arena, howl_types_Context ctx, howl_types_Node b, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_cr_and_on_sub(slop_arena* arena, howl_types_Context ctx, howl_types_Node b, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_cr_some_rhs_on_sub(slop_arena* arena, howl_types_Context ctx, howl_types_Node b, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_cr_exists_lhs_on_sub(slop_arena* arena, howl_types_Context ctx, howl_types_Node b, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_cr_exists_lhs_on_pred(slop_arena* arena, howl_types_Context ctx, howl_types_RoleId r, howl_types_Node x, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_cr_bottom_on_sub(slop_arena* arena, howl_types_Context ctx, howl_types_Node b);
slop_list_howl_types_Addressed howl_el_cr_bottom_on_pred(slop_arena* arena, howl_types_Context ctx, howl_types_Node x);
slop_list_howl_types_Addressed howl_el_cr_chain_on_pred(slop_arena* arena, howl_types_Context ctx, howl_types_RoleId r, howl_types_Node x, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_cr_chain_on_succ(slop_arena* arena, howl_types_Context ctx, howl_types_RoleId s, howl_types_Node z, howl_types_NormAxiom ax);
slop_list_howl_types_RoleId howl_el_sups_of(slop_arena* arena, howl_premise_RoleClosure rc, howl_types_RoleId e);
slop_list_howl_types_Addressed howl_el_cr4_on_sub_through(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_Node b, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_cr7_on_pred_through(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_RoleId r, howl_types_Node x, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_cr7_on_succ_through(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_RoleId s, howl_types_Node z, howl_types_NormAxiom ax);
howl_premise_RoleClosure howl_el_role_closure_naive(slop_arena* arena, slop_list_howl_types_NormAxiom axioms);
uint8_t howl_el_in_sups(howl_premise_RoleClosure rc, howl_types_RoleId e, howl_types_RoleId r);
slop_list_howl_types_Addressed howl_el_ref_cr4_on_sub(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_Node b, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_ref_cr7_on_pred(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_RoleId r, howl_types_Node x, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_ref_cr7_on_succ(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_RoleId s, howl_types_Node z, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_apply_el_rules(slop_arena* arena, howl_types_Context ctx, howl_types_Derived incoming, howl_premise_RuleIndex idx);
slop_list_howl_types_Addressed howl_el_apply_el_rules_reference(slop_arena* arena, howl_types_Context ctx, howl_types_Derived incoming, slop_list_howl_types_NormAxiom axioms);

#ifndef SLOP_OPTION_HOWL_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(howl_types_Addressed, slop_option_howl_types_Addressed)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_NormAxiom, slop_option_howl_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_OPTION_HOWL_PREMISE_ROLELIST_DEFINED
#define SLOP_OPTION_HOWL_PREMISE_ROLELIST_DEFINED
SLOP_OPTION_DEFINE(howl_premise_RoleList, slop_option_howl_premise_RoleList)
#endif

#ifndef SLOP_OPTION_HOWL_PREMISE_AXLIST_DEFINED
#define SLOP_OPTION_HOWL_PREMISE_AXLIST_DEFINED
SLOP_OPTION_DEFINE(howl_premise_AxList, slop_option_howl_premise_AxList)
#endif

#ifndef SLOP_OPTION_HOWL_PREMISE_PARTNERS_DEFINED
#define SLOP_OPTION_HOWL_PREMISE_PARTNERS_DEFINED
SLOP_OPTION_DEFINE(howl_premise_Partners, slop_option_howl_premise_Partners)
#endif


#endif
