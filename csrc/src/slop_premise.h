#ifndef SLOP_premise_H
#define SLOP_premise_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"

typedef struct premise_AxList premise_AxList;
typedef struct premise_Partners premise_Partners;
typedef struct premise_RoleList premise_RoleList;
typedef struct premise_RoleGraph premise_RoleGraph;
typedef struct premise_RoleClosure premise_RoleClosure;
typedef struct premise_RuleIndex premise_RuleIndex;

#ifndef SLOP_LIST_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_TYPES_NORMAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_NormAxiom, slop_list_types_NormAxiom)
#endif

#ifndef SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Node, slop_list_types_Node)
#endif

#ifndef SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(types_RoleId, slop_list_types_RoleId)
#endif

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

struct premise_AxList {
    slop_list_types_NormAxiom items;
};
typedef struct premise_AxList premise_AxList;

#ifndef SLOP_OPTION_PREMISE_AXLIST_DEFINED
#define SLOP_OPTION_PREMISE_AXLIST_DEFINED
SLOP_OPTION_DEFINE(premise_AxList, slop_option_premise_AxList)
#endif

struct premise_Partners {
    slop_map* by_other;
    int64_t count;
};
typedef struct premise_Partners premise_Partners;

#ifndef SLOP_OPTION_PREMISE_PARTNERS_DEFINED
#define SLOP_OPTION_PREMISE_PARTNERS_DEFINED
SLOP_OPTION_DEFINE(premise_Partners, slop_option_premise_Partners)
#endif

struct premise_RoleList {
    slop_list_types_RoleId items;
};
typedef struct premise_RoleList premise_RoleList;

#ifndef SLOP_OPTION_PREMISE_ROLELIST_DEFINED
#define SLOP_OPTION_PREMISE_ROLELIST_DEFINED
SLOP_OPTION_DEFINE(premise_RoleList, slop_option_premise_RoleList)
#endif

struct premise_RoleGraph {
    slop_map* up;
};
typedef struct premise_RoleGraph premise_RoleGraph;

#ifndef SLOP_OPTION_PREMISE_ROLEGRAPH_DEFINED
#define SLOP_OPTION_PREMISE_ROLEGRAPH_DEFINED
SLOP_OPTION_DEFINE(premise_RoleGraph, slop_option_premise_RoleGraph)
#endif

struct premise_RoleClosure {
    slop_map* sups;
    slop_map* subs;
};
typedef struct premise_RoleClosure premise_RoleClosure;

#ifndef SLOP_OPTION_PREMISE_ROLECLOSURE_DEFINED
#define SLOP_OPTION_PREMISE_ROLECLOSURE_DEFINED
SLOP_OPTION_DEFINE(premise_RoleClosure, slop_option_premise_RoleClosure)
#endif

struct premise_RuleIndex {
    slop_map* sub_by_lhs;
    slop_map* and_by_pair;
    slop_map* rhs_by_lhs;
    slop_map* lhs_by_filler;
    slop_map* lhs_by_role;
    slop_map* chain_by_first;
    slop_map* chain_by_second;
    premise_RoleClosure roles;
};
typedef struct premise_RuleIndex premise_RuleIndex;

#ifndef SLOP_OPTION_PREMISE_RULEINDEX_DEFINED
#define SLOP_OPTION_PREMISE_RULEINDEX_DEFINED
SLOP_OPTION_DEFINE(premise_RuleIndex, slop_option_premise_RuleIndex)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef TYPES_NODE_HASH_EQ_DEFINED
#define TYPES_NODE_HASH_EQ_DEFINED
#ifndef RDF_IRI_HASH_EQ_DEFINED
#define RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_rdf_IRI(const void* key) {
    const rdf_IRI* _k = (const rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_rdf_IRI(const void* a, const void* b) {
    const rdf_IRI* _a = (const rdf_IRI*)a;
    const rdf_IRI* _b = (const rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
#ifndef RDF_IRI_HASH_EQ_DEFINED
#define RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_rdf_IRI(const void* key) {
    const rdf_IRI* _k = (const rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_rdf_IRI(const void* a, const void* b) {
    const rdf_IRI* _a = (const rdf_IRI*)a;
    const rdf_IRI* _b = (const rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
static inline uint64_t slop_hash_types_Node(const void* key) {
    const types_Node* _k = (const types_Node*)key;
    switch (_k->tag) {
        case types_Node_class_node:
            return slop_hash_rdf_IRI(&_k->data.class_node);
        case types_Node_individual_node:
            return slop_hash_rdf_IRI(&_k->data.individual_node);
        case types_Node_fresh_node:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.fresh_node });
    }
    return 0;
}
static inline bool slop_eq_types_Node(const void* a, const void* b) {
    const types_Node* _a = (const types_Node*)a;
    const types_Node* _b = (const types_Node*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case types_Node_class_node:
            return slop_eq_rdf_IRI(&_a->data.class_node, &_b->data.class_node);
        case types_Node_individual_node:
            return slop_eq_rdf_IRI(&_a->data.individual_node, &_b->data.individual_node);
        case types_Node_fresh_node:
            return _a->data.fresh_node == _b->data.fresh_node;
    }
    return false;
}
#endif

#ifndef TYPES_ROLEID_HASH_EQ_DEFINED
#define TYPES_ROLEID_HASH_EQ_DEFINED
#ifndef RDF_IRI_HASH_EQ_DEFINED
#define RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_rdf_IRI(const void* key) {
    const rdf_IRI* _k = (const rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_rdf_IRI(const void* a, const void* b) {
    const rdf_IRI* _a = (const rdf_IRI*)a;
    const rdf_IRI* _b = (const rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
#ifndef RDF_IRI_HASH_EQ_DEFINED
#define RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_rdf_IRI(const void* key) {
    const rdf_IRI* _k = (const rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_rdf_IRI(const void* a, const void* b) {
    const rdf_IRI* _a = (const rdf_IRI*)a;
    const rdf_IRI* _b = (const rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
static inline uint64_t slop_hash_types_RoleId(const void* key) {
    const types_RoleId* _k = (const types_RoleId*)key;
    switch (_k->tag) {
        case types_RoleId_named_role:
            return slop_hash_rdf_IRI(&_k->data.named_role);
        case types_RoleId_fresh_role:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.fresh_role });
        case types_RoleId_inverse_role:
            return slop_hash_rdf_IRI(&_k->data.inverse_role);
    }
    return 0;
}
static inline bool slop_eq_types_RoleId(const void* a, const void* b) {
    const types_RoleId* _a = (const types_RoleId*)a;
    const types_RoleId* _b = (const types_RoleId*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case types_RoleId_named_role:
            return slop_eq_rdf_IRI(&_a->data.named_role, &_b->data.named_role);
        case types_RoleId_fresh_role:
            return _a->data.fresh_role == _b->data.fresh_role;
        case types_RoleId_inverse_role:
            return slop_eq_rdf_IRI(&_a->data.inverse_role, &_b->data.inverse_role);
    }
    return false;
}
#endif

premise_AxList premise_pushed(slop_arena* arena, slop_option_premise_AxList found, types_NormAxiom ax);
premise_Partners premise_partnered(slop_arena* arena, slop_option_premise_Partners found, types_Node other, types_NormAxiom ax);
premise_RoleList premise_role_pushed(slop_arena* arena, slop_option_premise_RoleList found, types_RoleId r);
slop_list_types_RoleId premise_axiom_roles(slop_arena* arena, types_NormAxiom ax);
premise_RoleList premise_role_closure(slop_arena* arena, premise_RoleGraph g, types_RoleId r);
premise_RuleIndex premise_build_rule_index(slop_arena* arena, slop_list_types_NormAxiom axioms);

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_PREMISE_AXLIST_DEFINED
#define SLOP_OPTION_PREMISE_AXLIST_DEFINED
SLOP_OPTION_DEFINE(premise_AxList, slop_option_premise_AxList)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_PREMISE_PARTNERS_DEFINED
#define SLOP_OPTION_PREMISE_PARTNERS_DEFINED
SLOP_OPTION_DEFINE(premise_Partners, slop_option_premise_Partners)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_PREMISE_ROLELIST_DEFINED
#define SLOP_OPTION_PREMISE_ROLELIST_DEFINED
SLOP_OPTION_DEFINE(premise_RoleList, slop_option_premise_RoleList)
#endif

#ifndef SLOP_OPTION_PREMISE_ROLEGRAPH_DEFINED
#define SLOP_OPTION_PREMISE_ROLEGRAPH_DEFINED
SLOP_OPTION_DEFINE(premise_RoleGraph, slop_option_premise_RoleGraph)
#endif

#ifndef SLOP_OPTION_PREMISE_ROLECLOSURE_DEFINED
#define SLOP_OPTION_PREMISE_ROLECLOSURE_DEFINED
SLOP_OPTION_DEFINE(premise_RoleClosure, slop_option_premise_RoleClosure)
#endif

#ifndef SLOP_OPTION_PREMISE_RULEINDEX_DEFINED
#define SLOP_OPTION_PREMISE_RULEINDEX_DEFINED
SLOP_OPTION_DEFINE(premise_RuleIndex, slop_option_premise_RuleIndex)
#endif


#endif
