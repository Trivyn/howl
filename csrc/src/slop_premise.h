#ifndef SLOP_premise_H
#define SLOP_premise_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"

typedef struct howl_premise_AxList howl_premise_AxList;
typedef struct howl_premise_Partners howl_premise_Partners;
typedef struct howl_premise_RoleList howl_premise_RoleList;
typedef struct howl_premise_RoleGraph howl_premise_RoleGraph;
typedef struct howl_premise_RoleClosure howl_premise_RoleClosure;
typedef struct howl_premise_RuleIndex howl_premise_RuleIndex;

#ifndef SLOP_LIST_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_NORMAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_NormAxiom, slop_list_howl_types_NormAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Node, slop_list_howl_types_Node)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_RoleId, slop_list_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_NormAxiom, slop_option_howl_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

struct howl_premise_AxList {
    slop_list_howl_types_NormAxiom items;
};
typedef struct howl_premise_AxList howl_premise_AxList;

#ifndef SLOP_OPTION_HOWL_PREMISE_AXLIST_DEFINED
#define SLOP_OPTION_HOWL_PREMISE_AXLIST_DEFINED
SLOP_OPTION_DEFINE(howl_premise_AxList, slop_option_howl_premise_AxList)
#endif

struct howl_premise_Partners {
    slop_map* by_other;
    int64_t count;
};
typedef struct howl_premise_Partners howl_premise_Partners;

#ifndef SLOP_OPTION_HOWL_PREMISE_PARTNERS_DEFINED
#define SLOP_OPTION_HOWL_PREMISE_PARTNERS_DEFINED
SLOP_OPTION_DEFINE(howl_premise_Partners, slop_option_howl_premise_Partners)
#endif

struct howl_premise_RoleList {
    slop_list_howl_types_RoleId items;
};
typedef struct howl_premise_RoleList howl_premise_RoleList;

#ifndef SLOP_OPTION_HOWL_PREMISE_ROLELIST_DEFINED
#define SLOP_OPTION_HOWL_PREMISE_ROLELIST_DEFINED
SLOP_OPTION_DEFINE(howl_premise_RoleList, slop_option_howl_premise_RoleList)
#endif

struct howl_premise_RoleGraph {
    slop_map* up;
};
typedef struct howl_premise_RoleGraph howl_premise_RoleGraph;

#ifndef SLOP_OPTION_HOWL_PREMISE_ROLEGRAPH_DEFINED
#define SLOP_OPTION_HOWL_PREMISE_ROLEGRAPH_DEFINED
SLOP_OPTION_DEFINE(howl_premise_RoleGraph, slop_option_howl_premise_RoleGraph)
#endif

struct howl_premise_RoleClosure {
    slop_map* sups;
    slop_map* subs;
};
typedef struct howl_premise_RoleClosure howl_premise_RoleClosure;

#ifndef SLOP_OPTION_HOWL_PREMISE_ROLECLOSURE_DEFINED
#define SLOP_OPTION_HOWL_PREMISE_ROLECLOSURE_DEFINED
SLOP_OPTION_DEFINE(howl_premise_RoleClosure, slop_option_howl_premise_RoleClosure)
#endif

struct howl_premise_RuleIndex {
    slop_map* sub_by_lhs;
    slop_map* and_by_pair;
    slop_map* rhs_by_lhs;
    slop_map* lhs_by_filler;
    slop_map* lhs_by_role;
    slop_map* chain_by_first;
    slop_map* chain_by_second;
    howl_premise_RoleClosure roles;
};
typedef struct howl_premise_RuleIndex howl_premise_RuleIndex;

#ifndef SLOP_OPTION_HOWL_PREMISE_RULEINDEX_DEFINED
#define SLOP_OPTION_HOWL_PREMISE_RULEINDEX_DEFINED
SLOP_OPTION_DEFINE(howl_premise_RuleIndex, slop_option_howl_premise_RuleIndex)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef HOWL_TYPES_NODE_HASH_EQ_DEFINED
#define HOWL_TYPES_NODE_HASH_EQ_DEFINED
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
static inline uint64_t slop_hash_howl_types_Node(const void* key) {
    const howl_types_Node* _k = (const howl_types_Node*)key;
    switch (_k->tag) {
        case howl_types_Node_class_node:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.class_node);
        case howl_types_Node_individual_node:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.individual_node);
        case howl_types_Node_fresh_node:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.fresh_node });
    }
    return 0;
}
static inline bool slop_eq_howl_types_Node(const void* a, const void* b) {
    const howl_types_Node* _a = (const howl_types_Node*)a;
    const howl_types_Node* _b = (const howl_types_Node*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_Node_class_node:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.class_node, &_b->data.class_node);
        case howl_types_Node_individual_node:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.individual_node, &_b->data.individual_node);
        case howl_types_Node_fresh_node:
            return _a->data.fresh_node == _b->data.fresh_node;
    }
    return false;
}
#endif

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

howl_premise_AxList howl_premise_pushed(slop_arena* arena, slop_option_howl_premise_AxList found, howl_types_NormAxiom ax);
howl_premise_Partners howl_premise_partnered(slop_arena* arena, slop_option_howl_premise_Partners found, howl_types_Node other, howl_types_NormAxiom ax);
howl_premise_RoleList howl_premise_role_pushed(slop_arena* arena, slop_option_howl_premise_RoleList found, howl_types_RoleId r);
slop_list_howl_types_RoleId howl_premise_axiom_roles(slop_arena* arena, howl_types_NormAxiom ax);
howl_premise_RoleList howl_premise_role_closure(slop_arena* arena, howl_premise_RoleGraph g, howl_types_RoleId r);
howl_premise_RuleIndex howl_premise_build_rule_index(slop_arena* arena, slop_list_howl_types_NormAxiom axioms);

#ifndef SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_NormAxiom, slop_option_howl_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_PREMISE_AXLIST_DEFINED
#define SLOP_OPTION_HOWL_PREMISE_AXLIST_DEFINED
SLOP_OPTION_DEFINE(howl_premise_AxList, slop_option_howl_premise_AxList)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_PREMISE_PARTNERS_DEFINED
#define SLOP_OPTION_HOWL_PREMISE_PARTNERS_DEFINED
SLOP_OPTION_DEFINE(howl_premise_Partners, slop_option_howl_premise_Partners)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_PREMISE_ROLELIST_DEFINED
#define SLOP_OPTION_HOWL_PREMISE_ROLELIST_DEFINED
SLOP_OPTION_DEFINE(howl_premise_RoleList, slop_option_howl_premise_RoleList)
#endif

#ifndef SLOP_OPTION_HOWL_PREMISE_ROLEGRAPH_DEFINED
#define SLOP_OPTION_HOWL_PREMISE_ROLEGRAPH_DEFINED
SLOP_OPTION_DEFINE(howl_premise_RoleGraph, slop_option_howl_premise_RoleGraph)
#endif

#ifndef SLOP_OPTION_HOWL_PREMISE_ROLECLOSURE_DEFINED
#define SLOP_OPTION_HOWL_PREMISE_ROLECLOSURE_DEFINED
SLOP_OPTION_DEFINE(howl_premise_RoleClosure, slop_option_howl_premise_RoleClosure)
#endif

#ifndef SLOP_OPTION_HOWL_PREMISE_RULEINDEX_DEFINED
#define SLOP_OPTION_HOWL_PREMISE_RULEINDEX_DEFINED
SLOP_OPTION_DEFINE(howl_premise_RuleIndex, slop_option_howl_premise_RuleIndex)
#endif


#endif
