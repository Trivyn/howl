#ifndef SLOP_saturate_H
#define SLOP_saturate_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_el.h"
#include "slop_premise.h"
#include "slop_thread.h"

typedef struct howl_saturate_RoundResult howl_saturate_RoundResult;
typedef struct howl_saturate_RoundDelta howl_saturate_RoundDelta;
typedef struct howl_saturate_Touched howl_saturate_Touched;
typedef struct howl_saturate_Bucket howl_saturate_Bucket;
typedef struct howl_saturate_Queues howl_saturate_Queues;
typedef struct howl_saturate_Partition howl_saturate_Partition;
typedef struct howl_saturate_Joined howl_saturate_Joined;
typedef struct howl_saturate_Advanced howl_saturate_Advanced;

#ifndef SLOP_LIST_ARENA_PTR_DEFINED
#define SLOP_LIST_ARENA_PTR_DEFINED
#define SLOP_LIST_ARENA_PTR_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_arena*, slop_list_arena_ptr)
#endif

#ifndef SLOP_OPTION_ARENA_PTR_DEFINED
#define SLOP_OPTION_ARENA_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_arena*, slop_option_arena_ptr)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Node, slop_list_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CONTEXT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CONTEXT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Context, slop_option_howl_types_Context)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_QUEUE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_QUEUE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Queue, slop_option_howl_types_Queue)
#endif

struct howl_saturate_RoundResult {
    howl_types_Saturation saturation;
    howl_types_Termination termination;
    slop_list_arena_ptr arenas;
};
typedef struct howl_saturate_RoundResult howl_saturate_RoundResult;

#ifndef SLOP_OPTION_HOWL_SATURATE_ROUNDRESULT_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_ROUNDRESULT_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_RoundResult, slop_option_howl_saturate_RoundResult)
#endif

struct howl_saturate_RoundDelta {
    slop_map* pending;
};
typedef struct howl_saturate_RoundDelta howl_saturate_RoundDelta;

#ifndef SLOP_OPTION_HOWL_SATURATE_ROUNDDELTA_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_ROUNDDELTA_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_RoundDelta, slop_option_howl_saturate_RoundDelta)
#endif

#ifndef SLOP_LIST_HOWL_SATURATE_ROUNDDELTA_DEFINED
#define SLOP_LIST_HOWL_SATURATE_ROUNDDELTA_DEFINED
#define SLOP_LIST_HOWL_SATURATE_ROUNDDELTA_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_saturate_RoundDelta, slop_list_howl_saturate_RoundDelta)
#endif

struct howl_saturate_Touched {
    howl_types_Node node;
    howl_types_Context pending;
};
typedef struct howl_saturate_Touched howl_saturate_Touched;

#ifndef SLOP_OPTION_HOWL_SATURATE_TOUCHED_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_TOUCHED_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_Touched, slop_option_howl_saturate_Touched)
#endif

#ifndef SLOP_LIST_HOWL_SATURATE_TOUCHED_DEFINED
#define SLOP_LIST_HOWL_SATURATE_TOUCHED_DEFINED
#define SLOP_LIST_HOWL_SATURATE_TOUCHED_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_saturate_Touched, slop_list_howl_saturate_Touched)
#endif

struct howl_saturate_Bucket {
    slop_list_howl_saturate_Touched items;
};
typedef struct howl_saturate_Bucket howl_saturate_Bucket;

#ifndef SLOP_OPTION_HOWL_SATURATE_BUCKET_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_BUCKET_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_Bucket, slop_option_howl_saturate_Bucket)
#endif

struct howl_saturate_Queues {
    slop_map* by_node;
};
typedef struct howl_saturate_Queues howl_saturate_Queues;

#ifndef SLOP_OPTION_HOWL_SATURATE_QUEUES_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_QUEUES_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_Queues, slop_option_howl_saturate_Queues)
#endif

struct howl_saturate_Partition {
    slop_map* owner;
    slop_map* by_owner;
};
typedef struct howl_saturate_Partition howl_saturate_Partition;

#ifndef SLOP_OPTION_HOWL_SATURATE_PARTITION_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_PARTITION_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_Partition, slop_option_howl_saturate_Partition)
#endif

struct howl_saturate_Joined {
    slop_list_howl_saturate_RoundDelta deltas;
    slop_list_arena_ptr arenas;
};
typedef struct howl_saturate_Joined howl_saturate_Joined;

#ifndef SLOP_OPTION_HOWL_SATURATE_JOINED_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_JOINED_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_Joined, slop_option_howl_saturate_Joined)
#endif

struct howl_saturate_Advanced {
    howl_types_Saturation saturation;
    slop_list_arena_ptr arenas;
};
typedef struct howl_saturate_Advanced howl_saturate_Advanced;

#ifndef SLOP_OPTION_HOWL_SATURATE_ADVANCED_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_ADVANCED_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_Advanced, slop_option_howl_saturate_Advanced)
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

#ifndef SLOP_RESULT_HOWL_SATURATE_ROUNDRESULT_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_SATURATE_ROUNDRESULT_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_saturate_RoundResult ok; howl_types_Fault err; } data; } slop_result_howl_saturate_RoundResult_howl_types_Fault;
#endif

slop_option_howl_types_Context howl_saturate_context_of(howl_types_Saturation sat, howl_types_Node n);
slop_option_howl_types_Queue howl_saturate_queue_of(howl_types_Saturation sat, howl_types_Node n);
uint8_t howl_saturate_store_has_sub(howl_types_Saturation sat, howl_types_Node x, howl_types_Node b);
uint8_t howl_saturate_store_has_succ(howl_types_Saturation sat, howl_types_Node x, howl_types_RoleId r, howl_types_Node y);
howl_types_Context howl_saturate_delta_context(slop_arena* arena, howl_saturate_RoundDelta delta, howl_types_Node x);
void howl_saturate_add_succ(slop_arena* arena, howl_types_Context ctx, howl_types_RoleId r, howl_types_Node y);
void howl_saturate_add_pred(slop_arena* arena, howl_types_Context ctx, howl_types_RoleId r, howl_types_Node x);
void howl_saturate_admit_sub(slop_arena* arena, howl_types_Saturation sat, howl_saturate_RoundDelta delta, howl_types_Node x, howl_types_Node b);
void howl_saturate_admit_edge(slop_arena* arena, howl_types_Saturation sat, howl_saturate_RoundDelta delta, howl_types_LogicalEdge e);
void howl_saturate_admit(slop_arena* arena, howl_types_Saturation sat, howl_saturate_RoundDelta delta, howl_types_Addressed m);
void howl_saturate_round_join(slop_arena* arena, howl_types_Saturation sat, howl_premise_RuleIndex idx, howl_saturate_RoundDelta delta);
int64_t howl_saturate_round_join_part(slop_arena* arena, howl_types_Saturation sat, howl_premise_RuleIndex idx, howl_saturate_RoundDelta delta, slop_list_howl_types_Node part);
void howl_saturate_reuse_arena(slop_arena* a);
void howl_saturate_join_context(slop_arena* arena, slop_arena* ra, howl_types_Saturation sat, howl_premise_RuleIndex idx, howl_saturate_RoundDelta delta, howl_types_Node n);
howl_types_Context howl_saturate_ensure_context(slop_arena* arena, howl_types_Saturation sat, howl_types_Node n);
howl_saturate_Bucket howl_saturate_bucketed(slop_arena* arena, slop_option_howl_saturate_Bucket found, howl_saturate_Touched e);
int64_t howl_saturate_partition_one(slop_arena* arena, slop_arena* run, howl_types_Saturation sat, howl_saturate_Partition part, howl_types_Node x, howl_types_Context dc, int64_t turn, int64_t w);
int64_t howl_saturate_partition_delta(slop_arena* arena, slop_arena* run, howl_types_Saturation sat, howl_saturate_RoundDelta d, howl_saturate_Partition part, int64_t turn, int64_t w);
slop_list_howl_saturate_Touched howl_saturate_bucket_items(slop_arena* arena, slop_option_howl_saturate_Bucket found);
howl_saturate_Partition howl_saturate_partition_round(slop_arena* arena, slop_arena* run, howl_types_Saturation sat, slop_list_howl_saturate_RoundDelta deltas, int64_t w);
uint8_t howl_saturate_commit_succ(slop_arena* arena, howl_types_Context store, howl_types_RoleId r, howl_types_Node y);
uint8_t howl_saturate_commit_pred(slop_arena* arena, howl_types_Context store, howl_types_RoleId r, howl_types_Node x);
uint8_t howl_saturate_commit_sub(slop_arena* arena, howl_types_Context store, howl_types_Node b);
void howl_saturate_commit_entry(slop_arena* arena, slop_arena* ca, howl_types_Saturation sat, howl_saturate_Touched e, howl_saturate_Queues qs);
int64_t howl_saturate_commit_bucket(slop_arena* arena, slop_arena* ca, howl_types_Saturation sat, slop_list_howl_saturate_Touched entries, howl_saturate_Queues qs);
howl_types_Saturation howl_saturate_commit_round(slop_arena* arena, slop_arena* run, slop_arena* scratch, howl_types_Saturation sat, slop_list_howl_saturate_RoundDelta deltas, slop_list_arena_ptr cas, slop_list_arena_ptr qas);
slop_list_arena_ptr howl_saturate_generation_arenas(slop_arena* arena, int64_t w);
slop_list_arena_ptr howl_saturate_committer_arenas(slop_arena* arena, slop_list_arena_ptr gen);
howl_saturate_Advanced howl_saturate_advance_round(slop_arena* arena, howl_types_Saturation sat, howl_premise_RuleIndex idx, howl_types_ReasonerConfig config, slop_list_arena_ptr cas);
howl_saturate_Joined howl_saturate_parallel_join(slop_arena* arena, howl_types_Saturation sat, howl_premise_RuleIndex idx, int64_t w);
uint8_t howl_saturate_seed_node(slop_arena* arena, howl_types_Saturation sat, howl_types_Node n);
howl_types_Saturation howl_saturate_make_initial_saturation(slop_arena* arena, slop_list_howl_types_Node signature);
uint8_t howl_saturate_frontier_is_empty(howl_types_Saturation sat);
uint8_t howl_saturate_budget_exhausted(int64_t iteration, int64_t max_iterations);
slop_list_arena_ptr howl_saturate_commit_arenas(slop_arena* arena, int64_t w);
slop_result_howl_saturate_RoundResult_howl_types_Fault howl_saturate_saturate(slop_arena* arena, howl_types_Saturation sat, howl_premise_RuleIndex idx, howl_types_ReasonerConfig config);
uint8_t howl_saturate_deliver_seed(slop_arena* arena, howl_types_Saturation sat, howl_types_Node to, howl_types_Derived d);

#ifndef SLOP_OPTION_ARENA_PTR_DEFINED
#define SLOP_OPTION_ARENA_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_arena*, slop_option_arena_ptr)
#endif

#ifndef SLOP_OPTION_HOWL_SATURATE_ROUNDRESULT_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_ROUNDRESULT_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_RoundResult, slop_option_howl_saturate_RoundResult)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CONTEXT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CONTEXT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Context, slop_option_howl_types_Context)
#endif

#ifndef SLOP_OPTION_HOWL_SATURATE_ROUNDDELTA_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_ROUNDDELTA_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_RoundDelta, slop_option_howl_saturate_RoundDelta)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_QUEUE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_QUEUE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Queue, slop_option_howl_types_Queue)
#endif

#ifndef SLOP_OPTION_HOWL_SATURATE_TOUCHED_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_TOUCHED_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_Touched, slop_option_howl_saturate_Touched)
#endif

#ifndef SLOP_OPTION_HOWL_SATURATE_BUCKET_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_BUCKET_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_Bucket, slop_option_howl_saturate_Bucket)
#endif

#ifndef SLOP_OPTION_HOWL_SATURATE_QUEUES_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_QUEUES_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_Queues, slop_option_howl_saturate_Queues)
#endif

#ifndef SLOP_OPTION_HOWL_SATURATE_PARTITION_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_PARTITION_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_Partition, slop_option_howl_saturate_Partition)
#endif

#ifndef SLOP_OPTION_HOWL_SATURATE_JOINED_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_JOINED_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_Joined, slop_option_howl_saturate_Joined)
#endif

#ifndef SLOP_OPTION_HOWL_SATURATE_ADVANCED_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_ADVANCED_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_Advanced, slop_option_howl_saturate_Advanced)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_OPTION_THREAD_INT_PTR_DEFINED
#define SLOP_OPTION_THREAD_INT_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_thread_int*, slop_option_thread_int_ptr)
#endif

#ifndef SLOP_LIST_HOWL_SATURATE_QUEUES_DEFINED
#define SLOP_LIST_HOWL_SATURATE_QUEUES_DEFINED
#define SLOP_LIST_HOWL_SATURATE_QUEUES_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_saturate_Queues, slop_list_howl_saturate_Queues)
#endif

#ifndef SLOP_LIST_THREAD_INT_PTR_DEFINED
#define SLOP_LIST_THREAD_INT_PTR_DEFINED
#define SLOP_LIST_THREAD_INT_PTR_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_thread_int*, slop_list_thread_int_ptr)
#endif


#endif
