#ifndef SLOP_kscsat_H
#define SLOP_kscsat_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"
#include "slop_ksc.h"
#include "slop_kscpremise.h"
#include "slop_owl2.h"
#include "slop_canon.h"
#include "slop_saturate.h"
#include "slop_thread.h"
#include "slop_kscnormal.h"
#include "slop_kscnames.h"
#include "slop_kscids.h"

typedef struct kscsat_IdList kscsat_IdList;
typedef struct kscsat_RoleIds kscsat_RoleIds;
typedef struct kscsat_Shard kscsat_Shard;
typedef struct kscsat_KStore kscsat_KStore;
typedef struct kscsat_Base kscsat_Base;
typedef struct kscsat_RunResult kscsat_RunResult;
typedef struct kscsat_RoleLegs kscsat_RoleLegs;
typedef struct kscsat_Under kscsat_Under;
typedef struct kscsat_Match kscsat_Match;
typedef struct kscsat_Deriving kscsat_Deriving;
typedef struct kscsat_RoundOut kscsat_RoundOut;
typedef struct kscsat_CFactList kscsat_CFactList;
typedef struct kscsat_Derived kscsat_Derived;
typedef struct kscsat_Fresh kscsat_Fresh;
typedef struct kscsat_Held kscsat_Held;
typedef struct kscsat_Merged kscsat_Merged;
typedef struct kscsat_Merging kscsat_Merging;
typedef struct kscsat_QRuns kscsat_QRuns;
typedef struct kscsat_QAnswers kscsat_QAnswers;

typedef enum {
    kscsat_Field_fd_insts,
    kscsat_Field_fd_noms,
    kscsat_Field_fd_holders
} kscsat_Field;

#ifndef SLOP_LIST_ARENA_PTR_DEFINED
#define SLOP_LIST_ARENA_PTR_DEFINED
#define SLOP_LIST_ARENA_PTR_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_arena*, slop_list_arena_ptr)
#endif

#ifndef SLOP_LIST_MAP_PTR_DEFINED
#define SLOP_LIST_MAP_PTR_DEFINED
#define SLOP_LIST_MAP_PTR_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_map*, slop_list_map_ptr)
#endif

#ifndef SLOP_OPTION_ARENA_PTR_DEFINED
#define SLOP_OPTION_ARENA_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_arena*, slop_option_arena_ptr)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_IMPL_DEFINED
SLOP_LIST_DEFINE(uint32_t, slop_list_u32)
#endif

#ifndef SLOP_OPTION_LIST_U32_DEFINED
#define SLOP_OPTION_LIST_U32_DEFINED
SLOP_OPTION_DEFINE(slop_list_u32, slop_option_list_u32)
#endif

#ifndef SLOP_LIST_LIST_TYPES_KFACT_DEFINED
#define SLOP_LIST_LIST_TYPES_KFACT_DEFINED
#define SLOP_LIST_LIST_TYPES_KFACT_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_list_types_KFact, slop_list_list_types_KFact)
#endif

#ifndef SLOP_LIST_LIST_U32_DEFINED
#define SLOP_LIST_LIST_U32_DEFINED
#define SLOP_LIST_LIST_U32_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_list_u32, slop_list_list_u32)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_LIST_KSCIDS_CFACT_DEFINED
#define SLOP_LIST_KSCIDS_CFACT_DEFINED
#define SLOP_LIST_KSCIDS_CFACT_IMPL_DEFINED
SLOP_LIST_DEFINE(kscids_CFact, slop_list_kscids_CFact)
#endif

#ifndef SLOP_LIST_TYPES_KELEM_DEFINED
#define SLOP_LIST_TYPES_KELEM_DEFINED
#define SLOP_LIST_TYPES_KELEM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KElem, slop_list_types_KElem)
#endif

#ifndef SLOP_LIST_TYPES_KFACT_DEFINED
#define SLOP_LIST_TYPES_KFACT_DEFINED
#define SLOP_LIST_TYPES_KFACT_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KFact, slop_list_types_KFact)
#endif

#ifndef SLOP_OPTION_LIST_TYPES_KFACT_DEFINED
#define SLOP_OPTION_LIST_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(slop_list_types_KFact, slop_option_list_types_KFact)
#endif

#ifndef SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(types_RoleId, slop_list_types_RoleId)
#endif

#ifndef SLOP_LIST_TYPES_KNAME_DEFINED
#define SLOP_LIST_TYPES_KNAME_DEFINED
#define SLOP_LIST_TYPES_KNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KName, slop_list_types_KName)
#endif

#ifndef SLOP_LIST_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_TYPES_KSCAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KscAxiom, slop_list_types_KscAxiom)
#endif

#ifndef SLOP_LIST_TYPES_CLASSANSWER_DEFINED
#define SLOP_LIST_TYPES_CLASSANSWER_DEFINED
#define SLOP_LIST_TYPES_CLASSANSWER_IMPL_DEFINED
SLOP_LIST_DEFINE(types_ClassAnswer, slop_list_types_ClassAnswer)
#endif

#ifndef SLOP_OPTION_KSCIDS_CFACT_DEFINED
#define SLOP_OPTION_KSCIDS_CFACT_DEFINED
SLOP_OPTION_DEFINE(kscids_CFact, slop_option_kscids_CFact)
#endif

#ifndef SLOP_OPTION_TYPES_KELEM_DEFINED
#define SLOP_OPTION_TYPES_KELEM_DEFINED
SLOP_OPTION_DEFINE(types_KElem, slop_option_types_KElem)
#endif

#ifndef SLOP_OPTION_TYPES_KFACT_DEFINED
#define SLOP_OPTION_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(types_KFact, slop_option_types_KFact)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_TYPES_KNAME_DEFINED
#define SLOP_OPTION_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(types_KName, slop_option_types_KName)
#endif

#ifndef SLOP_OPTION_TYPES_CLASSANSWER_DEFINED
#define SLOP_OPTION_TYPES_CLASSANSWER_DEFINED
SLOP_OPTION_DEFINE(types_ClassAnswer, slop_option_types_ClassAnswer)
#endif

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

struct kscsat_IdList {
    slop_list_u32 items;
};
typedef struct kscsat_IdList kscsat_IdList;

#ifndef SLOP_OPTION_KSCSAT_IDLIST_DEFINED
#define SLOP_OPTION_KSCSAT_IDLIST_DEFINED
SLOP_OPTION_DEFINE(kscsat_IdList, slop_option_kscsat_IdList)
#endif

struct kscsat_RoleIds {
    slop_map* by_role;
};
typedef struct kscsat_RoleIds kscsat_RoleIds;

#ifndef SLOP_OPTION_KSCSAT_ROLEIDS_DEFINED
#define SLOP_OPTION_KSCSAT_ROLEIDS_DEFINED
SLOP_OPTION_DEFINE(kscsat_RoleIds, slop_option_kscsat_RoleIds)
#endif

struct kscsat_Shard {
    slop_map* seen;
    slop_map* insts;
    slop_map* noms;
    slop_map* holders;
    slop_map* outs;
    slop_map* ins;
    slop_map* noms_at;
    slop_map* bots;
};
typedef struct kscsat_Shard kscsat_Shard;

#ifndef SLOP_OPTION_KSCSAT_SHARD_DEFINED
#define SLOP_OPTION_KSCSAT_SHARD_DEFINED
SLOP_OPTION_DEFINE(kscsat_Shard, slop_option_kscsat_Shard)
#endif

#ifndef SLOP_LIST_KSCSAT_SHARD_DEFINED
#define SLOP_LIST_KSCSAT_SHARD_DEFINED
#define SLOP_LIST_KSCSAT_SHARD_IMPL_DEFINED
SLOP_LIST_DEFINE(kscsat_Shard, slop_list_kscsat_Shard)
#endif

struct kscsat_KStore {
    kscids_KscIds ids;
    kscsat_Shard home;
    slop_list_kscsat_Shard shards;
};
typedef struct kscsat_KStore kscsat_KStore;

#ifndef SLOP_OPTION_KSCSAT_KSTORE_DEFINED
#define SLOP_OPTION_KSCSAT_KSTORE_DEFINED
SLOP_OPTION_DEFINE(kscsat_KStore, slop_option_kscsat_KStore)
#endif

struct kscsat_Base {
    kscsat_KStore g;
    kscsat_KStore w;
    slop_map* unsafe;
    slop_map* botreach;
};
typedef struct kscsat_Base kscsat_Base;

#ifndef SLOP_OPTION_KSCSAT_BASE_DEFINED
#define SLOP_OPTION_KSCSAT_BASE_DEFINED
SLOP_OPTION_DEFINE(kscsat_Base, slop_option_kscsat_Base)
#endif

struct kscsat_RunResult {
    kscsat_KStore store;
    int64_t rounds;
    uint8_t unsat;
    uint8_t capped;
    uint8_t cancelled;
    int64_t facts;
};
typedef struct kscsat_RunResult kscsat_RunResult;

#ifndef SLOP_OPTION_KSCSAT_RUNRESULT_DEFINED
#define SLOP_OPTION_KSCSAT_RUNRESULT_DEFINED
SLOP_OPTION_DEFINE(kscsat_RunResult, slop_option_kscsat_RunResult)
#endif

struct kscsat_RoleLegs {
    types_RoleId role;
    slop_list_types_KFact facts;
};
typedef struct kscsat_RoleLegs kscsat_RoleLegs;

#ifndef SLOP_OPTION_KSCSAT_ROLELEGS_DEFINED
#define SLOP_OPTION_KSCSAT_ROLELEGS_DEFINED
SLOP_OPTION_DEFINE(kscsat_RoleLegs, slop_option_kscsat_RoleLegs)
#endif

#ifndef SLOP_LIST_KSCSAT_ROLELEGS_DEFINED
#define SLOP_LIST_KSCSAT_ROLELEGS_DEFINED
#define SLOP_LIST_KSCSAT_ROLELEGS_IMPL_DEFINED
SLOP_LIST_DEFINE(kscsat_RoleLegs, slop_list_kscsat_RoleLegs)
#endif

struct kscsat_Under {
    kscpremise_KscIndex idx;
    types_RoleId v;
};
typedef struct kscsat_Under kscsat_Under;

#ifndef SLOP_OPTION_KSCSAT_UNDER_DEFINED
#define SLOP_OPTION_KSCSAT_UNDER_DEFINED
SLOP_OPTION_DEFINE(kscsat_Under, slop_option_kscsat_Under)
#endif

struct kscsat_Match {
    types_KTerm other;
    kscpremise_KList axioms;
};
typedef struct kscsat_Match kscsat_Match;

#ifndef SLOP_OPTION_KSCSAT_MATCH_DEFINED
#define SLOP_OPTION_KSCSAT_MATCH_DEFINED
SLOP_OPTION_DEFINE(kscsat_Match, slop_option_kscsat_Match)
#endif

#ifndef SLOP_LIST_KSCSAT_MATCH_DEFINED
#define SLOP_LIST_KSCSAT_MATCH_DEFINED
#define SLOP_LIST_KSCSAT_MATCH_IMPL_DEFINED
SLOP_LIST_DEFINE(kscsat_Match, slop_list_kscsat_Match)
#endif

struct kscsat_Deriving {
    kscpremise_KscIndex idx;
    kscsat_KStore st;
    slop_option_kscsat_Base base;
    slop_list_types_KFact out;
};
typedef struct kscsat_Deriving kscsat_Deriving;

#ifndef SLOP_OPTION_KSCSAT_DERIVING_DEFINED
#define SLOP_OPTION_KSCSAT_DERIVING_DEFINED
SLOP_OPTION_DEFINE(kscsat_Deriving, slop_option_kscsat_Deriving)
#endif

struct kscsat_RoundOut {
    slop_list_types_KFact next;
    int64_t added;
    uint8_t unsat;
};
typedef struct kscsat_RoundOut kscsat_RoundOut;

#ifndef SLOP_OPTION_KSCSAT_ROUNDOUT_DEFINED
#define SLOP_OPTION_KSCSAT_ROUNDOUT_DEFINED
SLOP_OPTION_DEFINE(kscsat_RoundOut, slop_option_kscsat_RoundOut)
#endif

struct kscsat_CFactList {
    slop_list_kscids_CFact items;
};
typedef struct kscsat_CFactList kscsat_CFactList;

#ifndef SLOP_OPTION_KSCSAT_CFACTLIST_DEFINED
#define SLOP_OPTION_KSCSAT_CFACTLIST_DEFINED
SLOP_OPTION_DEFINE(kscsat_CFactList, slop_option_kscsat_CFactList)
#endif

struct kscsat_Derived {
    slop_list_arena_ptr arenas;
    slop_list_map_ptr outs;
};
typedef struct kscsat_Derived kscsat_Derived;

#ifndef SLOP_OPTION_KSCSAT_DERIVED_DEFINED
#define SLOP_OPTION_KSCSAT_DERIVED_DEFINED
SLOP_OPTION_DEFINE(kscsat_Derived, slop_option_kscsat_Derived)
#endif

struct kscsat_Fresh {
    slop_list_int pos;
    slop_list_types_KFact facts;
};
typedef struct kscsat_Fresh kscsat_Fresh;

#ifndef SLOP_OPTION_KSCSAT_FRESH_DEFINED
#define SLOP_OPTION_KSCSAT_FRESH_DEFINED
SLOP_OPTION_DEFINE(kscsat_Fresh, slop_option_kscsat_Fresh)
#endif

#ifndef SLOP_LIST_KSCSAT_FRESH_DEFINED
#define SLOP_LIST_KSCSAT_FRESH_DEFINED
#define SLOP_LIST_KSCSAT_FRESH_IMPL_DEFINED
SLOP_LIST_DEFINE(kscsat_Fresh, slop_list_kscsat_Fresh)
#endif

struct kscsat_Held {
    uint32_t key;
    kscids_CFact c;
};
typedef struct kscsat_Held kscsat_Held;

#ifndef SLOP_OPTION_KSCSAT_HELD_DEFINED
#define SLOP_OPTION_KSCSAT_HELD_DEFINED
SLOP_OPTION_DEFINE(kscsat_Held, slop_option_kscsat_Held)
#endif

#ifndef SLOP_LIST_KSCSAT_HELD_DEFINED
#define SLOP_LIST_KSCSAT_HELD_DEFINED
#define SLOP_LIST_KSCSAT_HELD_IMPL_DEFINED
SLOP_LIST_DEFINE(kscsat_Held, slop_list_kscsat_Held)
#endif

struct kscsat_Merged {
    kscsat_RoundOut out;
    slop_list_kscsat_Held held;
};
typedef struct kscsat_Merged kscsat_Merged;

#ifndef SLOP_OPTION_KSCSAT_MERGED_DEFINED
#define SLOP_OPTION_KSCSAT_MERGED_DEFINED
SLOP_OPTION_DEFINE(kscsat_Merged, slop_option_kscsat_Merged)
#endif

struct kscsat_Merging {
    kscsat_KStore st;
    slop_option_kscsat_Base base;
    int64_t nc;
    slop_list_kscsat_Fresh frs;
    slop_list_int cur;
    slop_list_types_KFact next;
    slop_list_kscsat_Held held;
    int64_t added;
    uint8_t unsat;
    int64_t p;
};
typedef struct kscsat_Merging kscsat_Merging;

#ifndef SLOP_OPTION_KSCSAT_MERGING_DEFINED
#define SLOP_OPTION_KSCSAT_MERGING_DEFINED
SLOP_OPTION_DEFINE(kscsat_Merging, slop_option_kscsat_Merging)
#endif

struct kscsat_QRuns {
    slop_list_arena_ptr was;
    slop_list_map_ptr outs;
    int64_t cancelled;
};
typedef struct kscsat_QRuns kscsat_QRuns;

#ifndef SLOP_OPTION_KSCSAT_QRUNS_DEFINED
#define SLOP_OPTION_KSCSAT_QRUNS_DEFINED
SLOP_OPTION_DEFINE(kscsat_QRuns, slop_option_kscsat_QRuns)
#endif

struct kscsat_QAnswers {
    slop_list_types_ClassAnswer answers;
    uint8_t complete;
};
typedef struct kscsat_QAnswers kscsat_QAnswers;

#ifndef SLOP_OPTION_KSCSAT_QANSWERS_DEFINED
#define SLOP_OPTION_KSCSAT_QANSWERS_DEFINED
SLOP_OPTION_DEFINE(kscsat_QAnswers, slop_option_kscsat_QAnswers)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef KSCIDS_CFACT_HASH_EQ_DEFINED
#define KSCIDS_CFACT_HASH_EQ_DEFINED
static inline uint64_t slop_hash_kscids_CFact(const void* key) {
    const kscids_CFact* _k = (const kscids_CFact*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->kind }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->a }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->b }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->c }); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_kscids_CFact(const void* a, const void* b) {
    const kscids_CFact* _a = (const kscids_CFact*)a;
    const kscids_CFact* _b = (const kscids_CFact*)b;
    return true
        && (_a->kind == _b->kind)
        && (_a->a == _b->a)
        && (_a->b == _b->b)
        && (_a->c == _b->c)
    ;
}
#endif

#ifndef TYPES_KELEM_HASH_EQ_DEFINED
#define TYPES_KELEM_HASH_EQ_DEFINED
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
#ifndef TYPES_KNAME_HASH_EQ_DEFINED
#define TYPES_KNAME_HASH_EQ_DEFINED
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
static inline uint64_t slop_hash_types_KName(const void* key) {
    const types_KName* _k = (const types_KName*)key;
    switch (_k->tag) {
        case types_KName_k_class:
            return slop_hash_rdf_IRI(&_k->data.k_class);
        case types_KName_k_fresh:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.k_fresh });
    }
    return 0;
}
static inline bool slop_eq_types_KName(const void* a, const void* b) {
    const types_KName* _a = (const types_KName*)a;
    const types_KName* _b = (const types_KName*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case types_KName_k_class:
            return slop_eq_rdf_IRI(&_a->data.k_class, &_b->data.k_class);
        case types_KName_k_fresh:
            return _a->data.k_fresh == _b->data.k_fresh;
    }
    return false;
}
#endif
static inline uint64_t slop_hash_types_KElem(const void* key) {
    const types_KElem* _k = (const types_KElem*)key;
    switch (_k->tag) {
        case types_KElem_e_ind:
            return slop_hash_rdf_IRI(&_k->data.e_ind);
        case types_KElem_e_aux:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.e_aux });
        case types_KElem_e_class:
            return slop_hash_types_KName(&_k->data.e_class);
    }
    return 0;
}
static inline bool slop_eq_types_KElem(const void* a, const void* b) {
    const types_KElem* _a = (const types_KElem*)a;
    const types_KElem* _b = (const types_KElem*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case types_KElem_e_ind:
            return slop_eq_rdf_IRI(&_a->data.e_ind, &_b->data.e_ind);
        case types_KElem_e_aux:
            return _a->data.e_aux == _b->data.e_aux;
        case types_KElem_e_class:
            return slop_eq_types_KName(&_a->data.e_class, &_b->data.e_class);
    }
    return false;
}
#endif

#ifndef SLOP_RESULT_TYPES_KSCRESULT_TYPES_FAULT_DEFINED
#define SLOP_RESULT_TYPES_KSCRESULT_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { types_KscResult ok; types_Fault err; } data; } slop_result_types_KscResult_types_Fault;
#endif

kscsat_Shard kscsat_new_shard(slop_arena* arena);
kscsat_KStore kscsat_new_store(slop_arena* arena, kscids_KscIds ids, int64_t nshards);
int64_t kscsat_shard_count(kscsat_KStore st);
int64_t kscsat_shard_index(uint32_t k, int64_t n);
kscsat_Shard kscsat_shard_at(kscsat_KStore st, uint32_t k);
slop_list_types_KElem kscsat_store_bots(slop_arena* arena, kscsat_KStore st);
slop_list_kscids_CFact kscsat_store_facts(slop_arena* arena, kscsat_KStore st);
uint8_t kscsat_il_push(slop_arena* arena, slop_map* m, uint32_t k, uint32_t i);
uint8_t kscsat_ri_push(slop_arena* arena, slop_map* m, uint32_t k, uint32_t v, uint32_t i);
types_KElem kscsat_fact_subject(types_KFact f);
uint8_t kscsat_is_safe(kscsat_Base b, types_KElem x);
uint8_t kscsat_holds_coded(kscsat_KStore st, kscids_CFact c);
uint8_t kscsat_store_holds(kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f);
uint8_t kscsat_commit(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f);
slop_option_types_KFact kscsat_commit_coded(slop_arena* arena, kscsat_KStore st, kscids_CFact c);
uint8_t kscsat_file_new(slop_arena* arena, kscsat_KStore st, types_KFact f, kscids_CFact c);
uint8_t kscsat_file_subject(slop_arena* arena, kscsat_Shard sh, types_KFact f, kscids_CFact c);
slop_option_u32 kscsat_other_end(kscsat_KStore st, types_KFact f, kscids_CFact c);
uint8_t kscsat_file_other(slop_arena* arena, kscsat_KStore st, kscids_CFact c, uint32_t h);
slop_option_list_u32 kscsat_id_items(slop_map* m, uint32_t k);
slop_map* kscsat_field_map(kscsat_Shard sh, kscsat_Field fd);
uint8_t kscsat_keyed_by_subject(kscsat_Field fd);
slop_list_types_KFact kscsat_subject_items(slop_arena* arena, kscids_KscIds ids, types_KElem k, slop_list_u32 is);
slop_list_types_KFact kscsat_holder_items(slop_arena* arena, kscids_KscIds ids, types_KElem k, slop_list_u32 is);
slop_list_types_KFact kscsat_field_items(slop_arena* arena, kscsat_KStore st, kscsat_Field fd, types_KElem k);
slop_list_types_KFact kscsat_safe_facts(slop_arena* arena, kscsat_Base b, slop_list_types_KFact xs);
slop_list_types_KFact kscsat_w_items(slop_arena* arena, kscsat_Base b, uint8_t by_subject, types_KElem k, slop_list_types_KFact xs);
slop_list_list_types_KFact kscsat_partners(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, kscsat_Field fd, types_KElem k);
slop_list_types_KFact kscsat_leg_facts(slop_arena* arena, kscids_KscIds ids, uint8_t outward, types_KElem k, uint32_t e, slop_list_u32 is);
slop_list_list_types_KFact kscsat_all_ins(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KElem k);
slop_map* kscsat_side_map(kscsat_Shard sh, uint8_t outward);
slop_list_kscsat_RoleLegs kscsat_legs_every_role(slop_arena* arena, kscids_KscIds ids, uint8_t outward, types_KElem k, kscsat_RoleIds rf);
slop_list_kscsat_RoleLegs kscsat_legs_stored_under(slop_arena* arena, kscids_KscIds ids, uint8_t outward, types_KElem k, kscsat_RoleIds rf, kscsat_Under u);
slop_list_kscsat_RoleLegs kscsat_legs_of_subs(slop_arena* arena, kscids_KscIds ids, uint8_t outward, types_KElem k, kscsat_RoleIds rf, slop_list_types_RoleId subs);
slop_list_kscsat_RoleLegs kscsat_legs_under(slop_arena* arena, kscids_KscIds ids, uint8_t outward, types_KElem k, kscsat_RoleIds rf, kscsat_Under u);
slop_list_kscsat_RoleLegs kscsat_legs_in_store(slop_arena* arena, kscsat_KStore st, uint8_t outward, types_KElem k, slop_option_kscsat_Under under);
slop_list_kscsat_RoleLegs kscsat_push_w_legs(slop_arena* arena, slop_list_kscsat_RoleLegs out, kscsat_Base b, uint8_t outward, types_KElem k, slop_option_kscsat_Under u);
slop_list_kscsat_RoleLegs kscsat_role_legs(slop_arena* arena, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, uint8_t outward, types_KElem k, types_RoleId v);
slop_list_list_u32 kscsat_inst_id_lists(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KElem x);
slop_list_kscsat_Match kscsat_partner_matches(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KElem x, kscpremise_KPartners p);
uint8_t kscsat_emit_concl(kscsat_Deriving* d, ksc_Concl c);
uint8_t kscsat_emit_facts(kscsat_Deriving* d, slop_list_types_KFact xs);
uint8_t kscsat_emit_joins(slop_arena* arena, kscsat_Deriving* d, ksc_JoinRule j, types_KFact f, slop_list_list_types_KFact pss, types_KscAxiom ax);
slop_list_kscsat_RoleLegs kscsat_legs_at(slop_arena* arena, kscsat_Deriving* d, uint8_t outward, types_KElem k, types_RoleId v);
uint8_t kscsat_holds_now(kscsat_Deriving* d, types_KFact f);
slop_list_list_types_KFact kscsat_partners_at(slop_arena* arena, kscsat_Deriving* d, kscsat_Field fd, types_KElem k);
slop_list_kscsat_Match kscsat_matches_at(slop_arena* arena, kscsat_Deriving* d, types_KElem x, kscpremise_KPartners p);
types_KscAxiom kscsat_no_axiom(void);
uint8_t kscsat_inst_some_lhs(slop_arena* arena, kscsat_Deriving* d, types_KFact f, types_KElem x, types_KTerm y, types_RoleId v, types_KName a, types_KName z);
uint8_t kscsat_inst_and_pairs(slop_arena* arena, kscsat_Deriving* d, types_KElem x, types_KTerm y, kscpremise_KPartners p);
uint8_t kscsat_inst_equality(slop_arena* arena, kscsat_Deriving* d, types_KFact f, types_KElem x, types_KTerm y);
uint8_t kscsat_derive_inst(slop_arena* arena, kscsat_Deriving* d, types_KFact f, types_KElem x, types_KTerm y);
uint8_t kscsat_chain_first(slop_arena* arena, kscsat_Deriving* d, types_KFact fv, types_KElem x, types_RoleId v, types_KElem x1, types_RoleId u, types_RoleId v2, types_RoleId w);
uint8_t kscsat_chain_second(slop_arena* arena, kscsat_Deriving* d, types_KFact fv, types_KElem x, types_RoleId v, types_KElem x1, types_RoleId u, types_RoleId v2, types_RoleId w);
uint8_t kscsat_triple_under(slop_arena* arena, kscsat_Deriving* d, types_KElem x, types_RoleId v, types_KElem x1);
uint8_t kscsat_derive_triple(slop_arena* arena, kscsat_Deriving* d, types_KFact f, types_KElem x, types_RoleId e, types_KElem x1);
uint8_t kscsat_self_chain_first(slop_arena* arena, kscsat_Deriving* d, types_KFact f, types_KElem x, types_RoleId v, types_RoleId u, types_RoleId v2, types_RoleId w);
uint8_t kscsat_self_chain_second(slop_arena* arena, kscsat_Deriving* d, types_KFact f, types_KElem x, types_RoleId v, types_RoleId u, types_RoleId v2, types_RoleId w);
uint8_t kscsat_derive_self(slop_arena* arena, kscsat_Deriving* d, types_KFact f, types_KElem x, types_RoleId v);
slop_list_types_KFact kscsat_derive(slop_arena* arena, kscsat_Deriving* d, types_KFact f);
types_RoleId kscsat_ksc_dummy_role(void);
uint8_t kscsat_is_bottom_fact(types_KFact f);
uint8_t kscsat_reaches_bottom(slop_option_kscsat_Base base, types_KFact f);
int64_t kscsat_derive_chunk(slop_arena* wa, slop_arena* ra, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, slop_list_types_KFact delta, int64_t lo, int64_t hi, slop_map* out);
int64_t kscsat_round_workers(int64_t workers, int64_t n);
kscsat_Derived kscsat_derive_round(slop_arena* arena, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, slop_list_types_KFact delta, int64_t workers);
kscsat_RoundOut kscsat_ksc_round(slop_arena* arena, slop_arena* na, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, slop_list_types_KFact delta, uint8_t stop_at_bottom, uint8_t unsat0, int64_t workers, slop_list_arena_ptr cas);
int64_t kscsat_conclusion_count(kscsat_Derived d);
slop_list_kscids_CFact kscsat_chunk_items(slop_arena* arena, slop_map* out);
kscsat_RoundOut kscsat_commit_serial(slop_arena* arena, slop_arena* na, kscsat_KStore st, slop_option_kscsat_Base base, kscsat_Derived d, uint8_t stop_at_bottom, uint8_t unsat0);
uint8_t kscsat_parallel_commit_ok(kscsat_KStore st, slop_option_kscsat_Base base, kscsat_Derived d, uint8_t stop_at_bottom, uint8_t unsat0, int64_t nc);
uint8_t kscsat_any_bottom_coded(kscsat_KStore st, kscsat_Derived d);
int64_t kscsat_committer_of(kscsat_KStore st, uint32_t k, int64_t nc);
uint8_t kscsat_seen_in(kscsat_KStore st, kscids_CFact c);
int64_t kscsat_commit_subjects(slop_arena* ca, slop_arena* sa, kscsat_KStore st, kscsat_Derived d, int64_t k, int64_t nc, slop_map* res);
int64_t kscsat_commit_others(slop_arena* ca, kscsat_KStore st, slop_list_kscsat_Held held, int64_t k, int64_t nc);
kscsat_RoundOut kscsat_commit_parallel(slop_arena* scratch, slop_arena* na, kscsat_KStore st, slop_option_kscsat_Base base, kscsat_Derived d, slop_list_arena_ptr cas, int64_t nc, uint8_t unsat0);
slop_arena* kscsat_committer_arena(slop_list_arena_ptr cas, int64_t k);
slop_option_types_KFact kscsat_kept_at(kscsat_Merging* m, int64_t k);
int64_t kscsat_cursor_at(slop_list_int cur, int64_t k);
uint8_t kscsat_take_fact(kscsat_Merging* m, types_KFact f, kscids_CFact c);
uint8_t kscsat_merge_step(kscsat_Merging* m, kscids_CFact c);
kscsat_Merged kscsat_merge_fresh(slop_arena* scratch, slop_arena* na, kscsat_KStore st, slop_option_kscsat_Base base, kscsat_Derived d, slop_list_map_ptr ress, int64_t nc, uint8_t unsat0);
kscsat_RunResult kscsat_run_ksc(slop_arena* arena, kscpremise_KscIndex idx, kscids_KscIds ids, slop_option_kscsat_Base base, slop_list_types_KFact seeds, uint8_t stop_at_bottom, int64_t budget, int64_t cancel, int64_t workers, slop_list_arena_ptr cas);
kscsat_RunResult kscsat_run_result(kscsat_KStore st, int64_t rounds, uint8_t unsat, uint8_t capped, uint8_t cancelled, int64_t facts);
kscsat_RoundOut kscsat_seed_run(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, slop_list_types_KFact seeds);
slop_list_types_KName kscsat_answer_subsumers(slop_arena* arena, kscsat_KStore st, types_KName q);
slop_list_u32 kscsat_queue_ins(kscsat_KStore w, slop_map* seen, slop_map* out, slop_list_u32 work, uint32_t xi);
slop_map* kscsat_backward_closure(slop_arena* arena, kscsat_KStore w, slop_list_types_KElem start);
slop_option_types_ClassAnswer kscsat_class_run(slop_arena* arena, kscpremise_KscIndex idx, kscsat_Base base, uint8_t g_unsat, int64_t budget, int64_t cancel, types_KName q);
types_ClassAnswer kscsat_shared_answer(slop_arena* arena, kscsat_Base base, uint8_t g_unsat, types_KName q);
slop_option_types_ClassAnswer kscsat_class_answer(slop_arena* arena, kscpremise_KscIndex idx, kscsat_Base base, uint8_t g_unsat, int64_t budget, int64_t cancel, types_KName q);
slop_result_types_KscResult_types_Fault kscsat_classify_renamed(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, types_ReasonerConfig config);
slop_list_arena_ptr kscsat_ksc_commit_arenas(slop_arena* arena, int64_t w);
types_KscResult kscsat_w_capped(slop_arena* arena, kscsat_RunResult g, kscsat_RunResult w, int64_t n);
slop_result_types_KscResult_types_Fault kscsat_phase_w(slop_arena* arena, kscpremise_KscIndex idx, kscids_KscIds ids, kscsat_RunResult g, slop_list_types_KFact wseeds, slop_list_types_KElem tainted, types_KName thing, slop_list_types_KName classes, types_ReasonerConfig config, slop_list_arena_ptr cas, int64_t n);
slop_result_types_KscResult_types_Fault kscsat_classify_phases(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, types_ReasonerConfig config, slop_list_arena_ptr cas);
slop_result_types_KscResult_types_Fault kscsat_ksc_classify(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, types_ReasonerConfig config);
types_KscResult kscsat_unrename_result(slop_arena* arena, kscnames_KscNames nm, types_KscResult r);
types_KscResult kscsat_g_only(slop_arena* arena, kscsat_RunResult g, uint8_t inconsistent);
types_ClassAnswer kscsat_copy_answer(slop_arena* arena, types_ClassAnswer a);
int64_t kscsat_run_chunk(slop_arena* wa, kscpremise_KscIndex idx, kscsat_Base base, int64_t budget, int64_t cancel, slop_list_types_KName classes, slop_list_int todo, slop_map* out);
slop_list_int kscsat_index_chunk(slop_arena* arena, slop_list_int xs, int64_t lo, int64_t hi);
int64_t kscsat_worker_count_for(int64_t workers, int64_t jobs);
kscsat_Base kscsat_over_w_base(slop_arena* arena, kscsat_RunResult g, kscsat_RunResult w, slop_list_types_KElem tainted);
slop_list_int kscsat_split_safe(slop_arena* arena, kscsat_Base base, slop_list_types_KName classes, slop_map* shared);
kscsat_QRuns kscsat_run_unsafe(slop_arena* arena, kscpremise_KscIndex idx, kscsat_Base base, int64_t budget, int64_t cancel, slop_list_types_KName classes, slop_list_int todo, int64_t workers);
kscsat_QAnswers kscsat_copy_unsafe(slop_arena* arena, kscsat_QAnswers qa, slop_list_map_ptr outs, int64_t i);
kscsat_QAnswers kscsat_collect_answers(slop_arena* arena, slop_list_types_KName classes, slop_map* shared, slop_list_map_ptr outs, uint8_t complete0);
types_KscResult kscsat_over_w_result(kscsat_RunResult g, kscsat_RunResult w, types_ClassAnswer thing_answer, kscsat_QAnswers qa, int64_t jobs);
slop_result_types_KscResult_types_Fault kscsat_answer_over_w(slop_arena* arena, kscpremise_KscIndex idx, kscsat_RunResult g, kscsat_RunResult w, kscsat_Base base, types_ClassAnswer thing_answer, slop_list_types_KName classes, int64_t budget, int64_t workers, int64_t cancel);
slop_result_types_KscResult_types_Fault kscsat_classify_over_w(slop_arena* arena, kscpremise_KscIndex idx, kscsat_RunResult g, kscsat_RunResult w, slop_list_types_KElem tainted, types_KName thing, slop_list_types_KName classes, int64_t budget, int64_t workers, int64_t cancel);
int64_t kscsat_max_rounds(slop_list_types_ClassAnswer answers);
uint8_t kscsat_answer_holds(types_ClassAnswer a, types_KName b);
slop_list_types_KName kscsat_input_classes(slop_arena* arena, owl2_Signature sig);

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_KSCSAT_IDLIST_DEFINED
#define SLOP_OPTION_KSCSAT_IDLIST_DEFINED
SLOP_OPTION_DEFINE(kscsat_IdList, slop_option_kscsat_IdList)
#endif

#ifndef SLOP_OPTION_KSCSAT_ROLEIDS_DEFINED
#define SLOP_OPTION_KSCSAT_ROLEIDS_DEFINED
SLOP_OPTION_DEFINE(kscsat_RoleIds, slop_option_kscsat_RoleIds)
#endif

#ifndef SLOP_OPTION_KSCIDS_CFACT_DEFINED
#define SLOP_OPTION_KSCIDS_CFACT_DEFINED
SLOP_OPTION_DEFINE(kscids_CFact, slop_option_kscids_CFact)
#endif

#ifndef SLOP_OPTION_TYPES_KELEM_DEFINED
#define SLOP_OPTION_TYPES_KELEM_DEFINED
SLOP_OPTION_DEFINE(types_KElem, slop_option_types_KElem)
#endif

#ifndef SLOP_OPTION_KSCSAT_SHARD_DEFINED
#define SLOP_OPTION_KSCSAT_SHARD_DEFINED
SLOP_OPTION_DEFINE(kscsat_Shard, slop_option_kscsat_Shard)
#endif

#ifndef SLOP_OPTION_KSCSAT_KSTORE_DEFINED
#define SLOP_OPTION_KSCSAT_KSTORE_DEFINED
SLOP_OPTION_DEFINE(kscsat_KStore, slop_option_kscsat_KStore)
#endif

#ifndef SLOP_OPTION_KSCSAT_BASE_DEFINED
#define SLOP_OPTION_KSCSAT_BASE_DEFINED
SLOP_OPTION_DEFINE(kscsat_Base, slop_option_kscsat_Base)
#endif

#ifndef SLOP_OPTION_KSCSAT_RUNRESULT_DEFINED
#define SLOP_OPTION_KSCSAT_RUNRESULT_DEFINED
SLOP_OPTION_DEFINE(kscsat_RunResult, slop_option_kscsat_RunResult)
#endif

#ifndef SLOP_OPTION_TYPES_KFACT_DEFINED
#define SLOP_OPTION_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(types_KFact, slop_option_types_KFact)
#endif

#ifndef SLOP_OPTION_LIST_U32_DEFINED
#define SLOP_OPTION_LIST_U32_DEFINED
SLOP_OPTION_DEFINE(slop_list_u32, slop_option_list_u32)
#endif

#ifndef SLOP_OPTION_LIST_TYPES_KFACT_DEFINED
#define SLOP_OPTION_LIST_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(slop_list_types_KFact, slop_option_list_types_KFact)
#endif

#ifndef SLOP_OPTION_KSCSAT_ROLELEGS_DEFINED
#define SLOP_OPTION_KSCSAT_ROLELEGS_DEFINED
SLOP_OPTION_DEFINE(kscsat_RoleLegs, slop_option_kscsat_RoleLegs)
#endif

#ifndef SLOP_OPTION_KSCSAT_UNDER_DEFINED
#define SLOP_OPTION_KSCSAT_UNDER_DEFINED
SLOP_OPTION_DEFINE(kscsat_Under, slop_option_kscsat_Under)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_KSCSAT_MATCH_DEFINED
#define SLOP_OPTION_KSCSAT_MATCH_DEFINED
SLOP_OPTION_DEFINE(kscsat_Match, slop_option_kscsat_Match)
#endif

#ifndef SLOP_OPTION_KSCSAT_DERIVING_DEFINED
#define SLOP_OPTION_KSCSAT_DERIVING_DEFINED
SLOP_OPTION_DEFINE(kscsat_Deriving, slop_option_kscsat_Deriving)
#endif

#ifndef SLOP_OPTION_KSCSAT_ROUNDOUT_DEFINED
#define SLOP_OPTION_KSCSAT_ROUNDOUT_DEFINED
SLOP_OPTION_DEFINE(kscsat_RoundOut, slop_option_kscsat_RoundOut)
#endif

#ifndef SLOP_OPTION_KSCSAT_CFACTLIST_DEFINED
#define SLOP_OPTION_KSCSAT_CFACTLIST_DEFINED
SLOP_OPTION_DEFINE(kscsat_CFactList, slop_option_kscsat_CFactList)
#endif

#ifndef SLOP_OPTION_ARENA_PTR_DEFINED
#define SLOP_OPTION_ARENA_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_arena*, slop_option_arena_ptr)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_OPTION_KSCSAT_DERIVED_DEFINED
#define SLOP_OPTION_KSCSAT_DERIVED_DEFINED
SLOP_OPTION_DEFINE(kscsat_Derived, slop_option_kscsat_Derived)
#endif

#ifndef SLOP_OPTION_KSCSAT_FRESH_DEFINED
#define SLOP_OPTION_KSCSAT_FRESH_DEFINED
SLOP_OPTION_DEFINE(kscsat_Fresh, slop_option_kscsat_Fresh)
#endif

#ifndef SLOP_OPTION_KSCSAT_HELD_DEFINED
#define SLOP_OPTION_KSCSAT_HELD_DEFINED
SLOP_OPTION_DEFINE(kscsat_Held, slop_option_kscsat_Held)
#endif

#ifndef SLOP_OPTION_KSCSAT_MERGED_DEFINED
#define SLOP_OPTION_KSCSAT_MERGED_DEFINED
SLOP_OPTION_DEFINE(kscsat_Merged, slop_option_kscsat_Merged)
#endif

#ifndef SLOP_OPTION_KSCSAT_MERGING_DEFINED
#define SLOP_OPTION_KSCSAT_MERGING_DEFINED
SLOP_OPTION_DEFINE(kscsat_Merging, slop_option_kscsat_Merging)
#endif

#ifndef SLOP_OPTION_TYPES_KNAME_DEFINED
#define SLOP_OPTION_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(types_KName, slop_option_types_KName)
#endif

#ifndef SLOP_OPTION_TYPES_CLASSANSWER_DEFINED
#define SLOP_OPTION_TYPES_CLASSANSWER_DEFINED
SLOP_OPTION_DEFINE(types_ClassAnswer, slop_option_types_ClassAnswer)
#endif

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_KSCSAT_QRUNS_DEFINED
#define SLOP_OPTION_KSCSAT_QRUNS_DEFINED
SLOP_OPTION_DEFINE(kscsat_QRuns, slop_option_kscsat_QRuns)
#endif

#ifndef SLOP_OPTION_KSCSAT_QANSWERS_DEFINED
#define SLOP_OPTION_KSCSAT_QANSWERS_DEFINED
SLOP_OPTION_DEFINE(kscsat_QAnswers, slop_option_kscsat_QAnswers)
#endif

#ifndef SLOP_OPTION_KSCPREMISE_KLIST_DEFINED
#define SLOP_OPTION_KSCPREMISE_KLIST_DEFINED
SLOP_OPTION_DEFINE(kscpremise_KList, slop_option_kscpremise_KList)
#endif

#ifndef SLOP_OPTION_THREAD_INT_PTR_DEFINED
#define SLOP_OPTION_THREAD_INT_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_thread_int*, slop_option_thread_int_ptr)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_LIST_THREAD_INT_PTR_DEFINED
#define SLOP_LIST_THREAD_INT_PTR_DEFINED
#define SLOP_LIST_THREAD_INT_PTR_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_thread_int*, slop_list_thread_int_ptr)
#endif

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif


#endif
