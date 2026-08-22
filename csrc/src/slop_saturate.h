#ifndef SLOP_saturate_H
#define SLOP_saturate_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_el.h"

typedef struct saturate_RoundResult saturate_RoundResult;
typedef struct saturate_RoundDelta saturate_RoundDelta;

#ifndef SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Node, slop_list_types_Node)
#endif

#ifndef SLOP_LIST_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_TYPES_NORMAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_NormAxiom, slop_list_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_TYPES_CONTEXT_DEFINED
#define SLOP_OPTION_TYPES_CONTEXT_DEFINED
SLOP_OPTION_DEFINE(types_Context, slop_option_types_Context)
#endif

#ifndef SLOP_OPTION_TYPES_QUEUE_DEFINED
#define SLOP_OPTION_TYPES_QUEUE_DEFINED
SLOP_OPTION_DEFINE(types_Queue, slop_option_types_Queue)
#endif

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

struct saturate_RoundResult {
    types_Saturation saturation;
    types_Termination termination;
};
typedef struct saturate_RoundResult saturate_RoundResult;

#ifndef SLOP_OPTION_SATURATE_ROUNDRESULT_DEFINED
#define SLOP_OPTION_SATURATE_ROUNDRESULT_DEFINED
SLOP_OPTION_DEFINE(saturate_RoundResult, slop_option_saturate_RoundResult)
#endif

struct saturate_RoundDelta {
    slop_map* pending;
};
typedef struct saturate_RoundDelta saturate_RoundDelta;

#ifndef SLOP_OPTION_SATURATE_ROUNDDELTA_DEFINED
#define SLOP_OPTION_SATURATE_ROUNDDELTA_DEFINED
SLOP_OPTION_DEFINE(saturate_RoundDelta, slop_option_saturate_RoundDelta)
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
        && slop_eq_string(&_a->value, &_b->value)
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
        && slop_eq_string(&_a->value, &_b->value)
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

#ifndef SLOP_RESULT_SATURATE_ROUNDRESULT_TYPES_FAULT_DEFINED
#define SLOP_RESULT_SATURATE_ROUNDRESULT_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { saturate_RoundResult ok; types_Fault err; } data; } slop_result_saturate_RoundResult_types_Fault;
#endif

slop_option_types_Context saturate_context_of(types_Saturation sat, types_Node n);
slop_option_types_Queue saturate_queue_of(types_Saturation sat, types_Node n);
uint8_t saturate_store_has_sub(types_Saturation sat, types_Node x, types_Node b);
uint8_t saturate_store_has_succ(types_Saturation sat, types_Node x, types_RoleId r, types_Node y);
types_Context saturate_delta_context(slop_arena* arena, saturate_RoundDelta delta, types_Node x);
void saturate_add_succ(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node y);
void saturate_add_pred(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node x);
void saturate_admit_sub(slop_arena* arena, types_Saturation sat, saturate_RoundDelta delta, types_Node x, types_Node b);
void saturate_admit_edge(slop_arena* arena, types_Saturation sat, saturate_RoundDelta delta, types_LogicalEdge e);
void saturate_admit(slop_arena* arena, types_Saturation sat, saturate_RoundDelta delta, types_Addressed m);
void saturate_round_join(slop_arena* arena, types_Saturation sat, slop_list_types_NormAxiom axioms, saturate_RoundDelta delta);
types_Context saturate_ensure_context(slop_arena* arena, types_Saturation sat, types_Node n);
types_Saturation saturate_round_commit(slop_arena* arena, types_Saturation sat, saturate_RoundDelta delta);
types_Saturation saturate_advance_round(slop_arena* arena, types_Saturation sat, slop_list_types_NormAxiom axioms, types_ReasonerConfig config);
uint8_t saturate_seed_node(slop_arena* arena, types_Saturation sat, types_Node n);
types_Saturation saturate_make_initial_saturation(slop_arena* arena, slop_list_types_Node signature);
uint8_t saturate_frontier_is_empty(types_Saturation sat);
uint8_t saturate_budget_exhausted(types_Saturation sat, types_ReasonerConfig config);
slop_result_saturate_RoundResult_types_Fault saturate_saturate(slop_arena* arena, types_Saturation sat, slop_list_types_NormAxiom axioms, types_ReasonerConfig config);

#ifndef SLOP_OPTION_SATURATE_ROUNDRESULT_DEFINED
#define SLOP_OPTION_SATURATE_ROUNDRESULT_DEFINED
SLOP_OPTION_DEFINE(saturate_RoundResult, slop_option_saturate_RoundResult)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_TYPES_CONTEXT_DEFINED
#define SLOP_OPTION_TYPES_CONTEXT_DEFINED
SLOP_OPTION_DEFINE(types_Context, slop_option_types_Context)
#endif

#ifndef SLOP_OPTION_SATURATE_ROUNDDELTA_DEFINED
#define SLOP_OPTION_SATURATE_ROUNDDELTA_DEFINED
SLOP_OPTION_DEFINE(saturate_RoundDelta, slop_option_saturate_RoundDelta)
#endif

#ifndef SLOP_OPTION_TYPES_QUEUE_DEFINED
#define SLOP_OPTION_TYPES_QUEUE_DEFINED
SLOP_OPTION_DEFINE(types_Queue, slop_option_types_Queue)
#endif

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif


#endif
