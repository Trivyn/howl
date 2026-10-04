#ifndef SLOP_saturate_H
#define SLOP_saturate_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_el.h"
#include "slop_premise.h"
#include "slop_thread.h"

typedef struct saturate_RoundResult saturate_RoundResult;
typedef struct saturate_RoundDelta saturate_RoundDelta;
typedef struct saturate_Touched saturate_Touched;
typedef struct saturate_Bucket saturate_Bucket;
typedef struct saturate_Queues saturate_Queues;
typedef struct saturate_Partition saturate_Partition;
typedef struct saturate_Joined saturate_Joined;
typedef struct saturate_Advanced saturate_Advanced;

#ifndef SLOP_LIST_ARENA_PTR_DEFINED
#define SLOP_LIST_ARENA_PTR_DEFINED
#define SLOP_LIST_ARENA_PTR_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_arena*, slop_list_arena_ptr)
#endif

#ifndef SLOP_OPTION_ARENA_PTR_DEFINED
#define SLOP_OPTION_ARENA_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_arena*, slop_option_arena_ptr)
#endif

#ifndef SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Node, slop_list_types_Node)
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

#ifndef SLOP_LIST_SATURATE_ROUNDDELTA_DEFINED
#define SLOP_LIST_SATURATE_ROUNDDELTA_DEFINED
#define SLOP_LIST_SATURATE_ROUNDDELTA_IMPL_DEFINED
SLOP_LIST_DEFINE(saturate_RoundDelta, slop_list_saturate_RoundDelta)
#endif

struct saturate_Touched {
    types_Node node;
    types_Context pending;
};
typedef struct saturate_Touched saturate_Touched;

#ifndef SLOP_OPTION_SATURATE_TOUCHED_DEFINED
#define SLOP_OPTION_SATURATE_TOUCHED_DEFINED
SLOP_OPTION_DEFINE(saturate_Touched, slop_option_saturate_Touched)
#endif

#ifndef SLOP_LIST_SATURATE_TOUCHED_DEFINED
#define SLOP_LIST_SATURATE_TOUCHED_DEFINED
#define SLOP_LIST_SATURATE_TOUCHED_IMPL_DEFINED
SLOP_LIST_DEFINE(saturate_Touched, slop_list_saturate_Touched)
#endif

struct saturate_Bucket {
    slop_list_saturate_Touched items;
};
typedef struct saturate_Bucket saturate_Bucket;

#ifndef SLOP_OPTION_SATURATE_BUCKET_DEFINED
#define SLOP_OPTION_SATURATE_BUCKET_DEFINED
SLOP_OPTION_DEFINE(saturate_Bucket, slop_option_saturate_Bucket)
#endif

struct saturate_Queues {
    slop_map* by_node;
};
typedef struct saturate_Queues saturate_Queues;

#ifndef SLOP_OPTION_SATURATE_QUEUES_DEFINED
#define SLOP_OPTION_SATURATE_QUEUES_DEFINED
SLOP_OPTION_DEFINE(saturate_Queues, slop_option_saturate_Queues)
#endif

struct saturate_Partition {
    slop_map* owner;
    slop_map* by_owner;
};
typedef struct saturate_Partition saturate_Partition;

#ifndef SLOP_OPTION_SATURATE_PARTITION_DEFINED
#define SLOP_OPTION_SATURATE_PARTITION_DEFINED
SLOP_OPTION_DEFINE(saturate_Partition, slop_option_saturate_Partition)
#endif

struct saturate_Joined {
    slop_list_saturate_RoundDelta deltas;
    slop_list_arena_ptr arenas;
};
typedef struct saturate_Joined saturate_Joined;

#ifndef SLOP_OPTION_SATURATE_JOINED_DEFINED
#define SLOP_OPTION_SATURATE_JOINED_DEFINED
SLOP_OPTION_DEFINE(saturate_Joined, slop_option_saturate_Joined)
#endif

struct saturate_Advanced {
    types_Saturation saturation;
    slop_list_arena_ptr arenas;
};
typedef struct saturate_Advanced saturate_Advanced;

#ifndef SLOP_OPTION_SATURATE_ADVANCED_DEFINED
#define SLOP_OPTION_SATURATE_ADVANCED_DEFINED
SLOP_OPTION_DEFINE(saturate_Advanced, slop_option_saturate_Advanced)
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
void saturate_round_join(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, saturate_RoundDelta delta);
int64_t saturate_round_join_part(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, saturate_RoundDelta delta, slop_list_types_Node part);
void saturate_reuse_arena(slop_arena* a);
void saturate_join_context(slop_arena* arena, slop_arena* ra, types_Saturation sat, premise_RuleIndex idx, saturate_RoundDelta delta, types_Node n);
types_Context saturate_ensure_context(slop_arena* arena, types_Saturation sat, types_Node n);
saturate_Bucket saturate_bucketed(slop_arena* arena, slop_option_saturate_Bucket found, saturate_Touched e);
int64_t saturate_partition_one(slop_arena* arena, slop_arena* run, types_Saturation sat, saturate_Partition part, types_Node x, types_Context dc, int64_t turn, int64_t w);
int64_t saturate_partition_delta(slop_arena* arena, slop_arena* run, types_Saturation sat, saturate_RoundDelta d, saturate_Partition part, int64_t turn, int64_t w);
slop_list_saturate_Touched saturate_bucket_items(slop_arena* arena, slop_option_saturate_Bucket found);
saturate_Partition saturate_partition_round(slop_arena* arena, slop_arena* run, types_Saturation sat, slop_list_saturate_RoundDelta deltas, int64_t w);
uint8_t saturate_commit_succ(slop_arena* arena, types_Context store, types_RoleId r, types_Node y);
uint8_t saturate_commit_pred(slop_arena* arena, types_Context store, types_RoleId r, types_Node x);
uint8_t saturate_commit_sub(slop_arena* arena, types_Context store, types_Node b);
void saturate_commit_entry(slop_arena* arena, slop_arena* ca, types_Saturation sat, saturate_Touched e, saturate_Queues qs);
int64_t saturate_commit_bucket(slop_arena* arena, slop_arena* ca, types_Saturation sat, slop_list_saturate_Touched entries, saturate_Queues qs);
types_Saturation saturate_commit_round(slop_arena* arena, slop_arena* run, slop_arena* scratch, types_Saturation sat, slop_list_saturate_RoundDelta deltas, slop_list_arena_ptr cas, slop_list_arena_ptr qas);
slop_list_arena_ptr saturate_generation_arenas(slop_arena* arena, int64_t w);
slop_list_arena_ptr saturate_committer_arenas(slop_arena* arena, slop_list_arena_ptr gen);
saturate_Advanced saturate_advance_round(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, types_ReasonerConfig config, slop_list_arena_ptr cas);
saturate_Joined saturate_parallel_join(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, int64_t w);
uint8_t saturate_seed_node(slop_arena* arena, types_Saturation sat, types_Node n);
types_Saturation saturate_make_initial_saturation(slop_arena* arena, slop_list_types_Node signature);
uint8_t saturate_frontier_is_empty(types_Saturation sat);
uint8_t saturate_budget_exhausted(int64_t iteration, int64_t max_iterations);
slop_list_arena_ptr saturate_commit_arenas(slop_arena* arena, int64_t w);
slop_result_saturate_RoundResult_types_Fault saturate_saturate(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, types_ReasonerConfig config);
uint8_t saturate_deliver_seed(slop_arena* arena, types_Saturation sat, types_Node to, types_Derived d);

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

#ifndef SLOP_OPTION_SATURATE_TOUCHED_DEFINED
#define SLOP_OPTION_SATURATE_TOUCHED_DEFINED
SLOP_OPTION_DEFINE(saturate_Touched, slop_option_saturate_Touched)
#endif

#ifndef SLOP_OPTION_SATURATE_BUCKET_DEFINED
#define SLOP_OPTION_SATURATE_BUCKET_DEFINED
SLOP_OPTION_DEFINE(saturate_Bucket, slop_option_saturate_Bucket)
#endif

#ifndef SLOP_OPTION_SATURATE_QUEUES_DEFINED
#define SLOP_OPTION_SATURATE_QUEUES_DEFINED
SLOP_OPTION_DEFINE(saturate_Queues, slop_option_saturate_Queues)
#endif

#ifndef SLOP_OPTION_SATURATE_PARTITION_DEFINED
#define SLOP_OPTION_SATURATE_PARTITION_DEFINED
SLOP_OPTION_DEFINE(saturate_Partition, slop_option_saturate_Partition)
#endif

#ifndef SLOP_OPTION_ARENA_PTR_DEFINED
#define SLOP_OPTION_ARENA_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_arena*, slop_option_arena_ptr)
#endif

#ifndef SLOP_OPTION_SATURATE_JOINED_DEFINED
#define SLOP_OPTION_SATURATE_JOINED_DEFINED
SLOP_OPTION_DEFINE(saturate_Joined, slop_option_saturate_Joined)
#endif

#ifndef SLOP_OPTION_SATURATE_ADVANCED_DEFINED
#define SLOP_OPTION_SATURATE_ADVANCED_DEFINED
SLOP_OPTION_DEFINE(saturate_Advanced, slop_option_saturate_Advanced)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_OPTION_THREAD_INT_PTR_DEFINED
#define SLOP_OPTION_THREAD_INT_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_thread_int*, slop_option_thread_int_ptr)
#endif

#ifndef SLOP_LIST_SATURATE_QUEUES_DEFINED
#define SLOP_LIST_SATURATE_QUEUES_DEFINED
#define SLOP_LIST_SATURATE_QUEUES_IMPL_DEFINED
SLOP_LIST_DEFINE(saturate_Queues, slop_list_saturate_Queues)
#endif

#ifndef SLOP_LIST_THREAD_INT_PTR_DEFINED
#define SLOP_LIST_THREAD_INT_PTR_DEFINED
#define SLOP_LIST_THREAD_INT_PTR_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_thread_int*, slop_list_thread_int_ptr)
#endif


#endif
