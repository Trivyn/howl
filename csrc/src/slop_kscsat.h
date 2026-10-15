#ifndef SLOP_kscsat_H
#define SLOP_kscsat_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
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

typedef struct howl_kscsat_IdList howl_kscsat_IdList;
typedef struct howl_kscsat_RoleIds howl_kscsat_RoleIds;
typedef struct howl_kscsat_Shard howl_kscsat_Shard;
typedef struct howl_kscsat_KStore howl_kscsat_KStore;
typedef struct howl_kscsat_Base howl_kscsat_Base;
typedef struct howl_kscsat_RunResult howl_kscsat_RunResult;
typedef struct howl_kscsat_RoleLegs howl_kscsat_RoleLegs;
typedef struct howl_kscsat_Under howl_kscsat_Under;
typedef struct howl_kscsat_Match howl_kscsat_Match;
typedef struct howl_kscsat_Deriving howl_kscsat_Deriving;
typedef struct howl_kscsat_RoundOut howl_kscsat_RoundOut;
typedef struct howl_kscsat_CFactList howl_kscsat_CFactList;
typedef struct howl_kscsat_Derived howl_kscsat_Derived;
typedef struct howl_kscsat_Fresh howl_kscsat_Fresh;
typedef struct howl_kscsat_Held howl_kscsat_Held;
typedef struct howl_kscsat_Merged howl_kscsat_Merged;
typedef struct howl_kscsat_Merging howl_kscsat_Merging;
typedef struct howl_kscsat_QRuns howl_kscsat_QRuns;
typedef struct howl_kscsat_QAnswers howl_kscsat_QAnswers;

typedef enum {
    howl_kscsat_Field_fd_insts,
    howl_kscsat_Field_fd_noms,
    howl_kscsat_Field_fd_holders
} howl_kscsat_Field;

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

#ifndef SLOP_LIST_LIST_HOWL_TYPES_KFACT_DEFINED
#define SLOP_LIST_LIST_HOWL_TYPES_KFACT_DEFINED
#define SLOP_LIST_LIST_HOWL_TYPES_KFACT_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_list_howl_types_KFact, slop_list_list_howl_types_KFact)
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

#ifndef SLOP_LIST_HOWL_KSCIDS_CFACT_DEFINED
#define SLOP_LIST_HOWL_KSCIDS_CFACT_DEFINED
#define SLOP_LIST_HOWL_KSCIDS_CFACT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_kscids_CFact, slop_list_howl_kscids_CFact)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_KELEM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KELEM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KELEM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KElem, slop_list_howl_types_KElem)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_KFACT_DEFINED
#define SLOP_LIST_HOWL_TYPES_KFACT_DEFINED
#define SLOP_LIST_HOWL_TYPES_KFACT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KFact, slop_list_howl_types_KFact)
#endif

#ifndef SLOP_OPTION_LIST_HOWL_TYPES_KFACT_DEFINED
#define SLOP_OPTION_LIST_HOWL_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(slop_list_howl_types_KFact, slop_option_list_howl_types_KFact)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_RoleId, slop_list_howl_types_RoleId)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_KNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_KNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_KNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KName, slop_list_howl_types_KName)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KSCAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KscAxiom, slop_list_howl_types_KscAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_CLASSANSWER_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLASSANSWER_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLASSANSWER_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_ClassAnswer, slop_list_howl_types_ClassAnswer)
#endif

#ifndef SLOP_OPTION_HOWL_KSCIDS_CFACT_DEFINED
#define SLOP_OPTION_HOWL_KSCIDS_CFACT_DEFINED
SLOP_OPTION_DEFINE(howl_kscids_CFact, slop_option_howl_kscids_CFact)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KELEM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KELEM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KElem, slop_option_howl_types_KElem)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KFACT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(howl_types_KFact, slop_option_howl_types_KFact)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_KName, slop_option_howl_types_KName)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLASSANSWER_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLASSANSWER_DEFINED
SLOP_OPTION_DEFINE(howl_types_ClassAnswer, slop_option_howl_types_ClassAnswer)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscAxiom, slop_option_howl_types_KscAxiom)
#endif

struct howl_kscsat_IdList {
    slop_list_u32 items;
};
typedef struct howl_kscsat_IdList howl_kscsat_IdList;

#ifndef SLOP_OPTION_HOWL_KSCSAT_IDLIST_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_IDLIST_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_IdList, slop_option_howl_kscsat_IdList)
#endif

struct howl_kscsat_RoleIds {
    slop_map* by_role;
};
typedef struct howl_kscsat_RoleIds howl_kscsat_RoleIds;

#ifndef SLOP_OPTION_HOWL_KSCSAT_ROLEIDS_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_ROLEIDS_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_RoleIds, slop_option_howl_kscsat_RoleIds)
#endif

struct howl_kscsat_Shard {
    slop_map* seen;
    slop_map* insts;
    slop_map* noms;
    slop_map* holders;
    slop_map* outs;
    slop_map* ins;
    slop_map* noms_at;
    slop_map* bots;
};
typedef struct howl_kscsat_Shard howl_kscsat_Shard;

#ifndef SLOP_OPTION_HOWL_KSCSAT_SHARD_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_SHARD_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Shard, slop_option_howl_kscsat_Shard)
#endif

#ifndef SLOP_LIST_HOWL_KSCSAT_SHARD_DEFINED
#define SLOP_LIST_HOWL_KSCSAT_SHARD_DEFINED
#define SLOP_LIST_HOWL_KSCSAT_SHARD_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_kscsat_Shard, slop_list_howl_kscsat_Shard)
#endif

struct howl_kscsat_KStore {
    howl_kscids_KscIds ids;
    howl_kscsat_Shard home;
    slop_list_howl_kscsat_Shard shards;
};
typedef struct howl_kscsat_KStore howl_kscsat_KStore;

#ifndef SLOP_OPTION_HOWL_KSCSAT_KSTORE_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_KSTORE_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_KStore, slop_option_howl_kscsat_KStore)
#endif

struct howl_kscsat_Base {
    howl_kscsat_KStore g;
    howl_kscsat_KStore w;
    slop_map* unsafe;
    slop_map* botreach;
};
typedef struct howl_kscsat_Base howl_kscsat_Base;

#ifndef SLOP_OPTION_HOWL_KSCSAT_BASE_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_BASE_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Base, slop_option_howl_kscsat_Base)
#endif

struct howl_kscsat_RunResult {
    howl_kscsat_KStore store;
    int64_t rounds;
    uint8_t unsat;
    uint8_t capped;
    uint8_t cancelled;
    int64_t facts;
};
typedef struct howl_kscsat_RunResult howl_kscsat_RunResult;

#ifndef SLOP_OPTION_HOWL_KSCSAT_RUNRESULT_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_RUNRESULT_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_RunResult, slop_option_howl_kscsat_RunResult)
#endif

struct howl_kscsat_RoleLegs {
    howl_types_RoleId role;
    slop_list_howl_types_KFact facts;
};
typedef struct howl_kscsat_RoleLegs howl_kscsat_RoleLegs;

#ifndef SLOP_OPTION_HOWL_KSCSAT_ROLELEGS_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_ROLELEGS_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_RoleLegs, slop_option_howl_kscsat_RoleLegs)
#endif

#ifndef SLOP_LIST_HOWL_KSCSAT_ROLELEGS_DEFINED
#define SLOP_LIST_HOWL_KSCSAT_ROLELEGS_DEFINED
#define SLOP_LIST_HOWL_KSCSAT_ROLELEGS_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_kscsat_RoleLegs, slop_list_howl_kscsat_RoleLegs)
#endif

struct howl_kscsat_Under {
    howl_kscpremise_KscIndex idx;
    howl_types_RoleId v;
};
typedef struct howl_kscsat_Under howl_kscsat_Under;

#ifndef SLOP_OPTION_HOWL_KSCSAT_UNDER_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_UNDER_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Under, slop_option_howl_kscsat_Under)
#endif

struct howl_kscsat_Match {
    howl_types_KTerm other;
    howl_kscpremise_KList axioms;
};
typedef struct howl_kscsat_Match howl_kscsat_Match;

#ifndef SLOP_OPTION_HOWL_KSCSAT_MATCH_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_MATCH_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Match, slop_option_howl_kscsat_Match)
#endif

#ifndef SLOP_LIST_HOWL_KSCSAT_MATCH_DEFINED
#define SLOP_LIST_HOWL_KSCSAT_MATCH_DEFINED
#define SLOP_LIST_HOWL_KSCSAT_MATCH_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_kscsat_Match, slop_list_howl_kscsat_Match)
#endif

struct howl_kscsat_Deriving {
    howl_kscpremise_KscIndex idx;
    howl_kscsat_KStore st;
    slop_option_howl_kscsat_Base base;
    slop_list_howl_types_KFact out;
};
typedef struct howl_kscsat_Deriving howl_kscsat_Deriving;

#ifndef SLOP_OPTION_HOWL_KSCSAT_DERIVING_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_DERIVING_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Deriving, slop_option_howl_kscsat_Deriving)
#endif

struct howl_kscsat_RoundOut {
    slop_list_howl_types_KFact next;
    int64_t added;
    uint8_t unsat;
};
typedef struct howl_kscsat_RoundOut howl_kscsat_RoundOut;

#ifndef SLOP_OPTION_HOWL_KSCSAT_ROUNDOUT_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_ROUNDOUT_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_RoundOut, slop_option_howl_kscsat_RoundOut)
#endif

struct howl_kscsat_CFactList {
    slop_list_howl_kscids_CFact items;
};
typedef struct howl_kscsat_CFactList howl_kscsat_CFactList;

#ifndef SLOP_OPTION_HOWL_KSCSAT_CFACTLIST_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_CFACTLIST_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_CFactList, slop_option_howl_kscsat_CFactList)
#endif

struct howl_kscsat_Derived {
    slop_list_arena_ptr arenas;
    slop_list_map_ptr outs;
};
typedef struct howl_kscsat_Derived howl_kscsat_Derived;

#ifndef SLOP_OPTION_HOWL_KSCSAT_DERIVED_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_DERIVED_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Derived, slop_option_howl_kscsat_Derived)
#endif

struct howl_kscsat_Fresh {
    slop_list_int pos;
    slop_list_howl_types_KFact facts;
};
typedef struct howl_kscsat_Fresh howl_kscsat_Fresh;

#ifndef SLOP_OPTION_HOWL_KSCSAT_FRESH_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_FRESH_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Fresh, slop_option_howl_kscsat_Fresh)
#endif

#ifndef SLOP_LIST_HOWL_KSCSAT_FRESH_DEFINED
#define SLOP_LIST_HOWL_KSCSAT_FRESH_DEFINED
#define SLOP_LIST_HOWL_KSCSAT_FRESH_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_kscsat_Fresh, slop_list_howl_kscsat_Fresh)
#endif

struct howl_kscsat_Held {
    uint32_t key;
    howl_kscids_CFact c;
};
typedef struct howl_kscsat_Held howl_kscsat_Held;

#ifndef SLOP_OPTION_HOWL_KSCSAT_HELD_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_HELD_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Held, slop_option_howl_kscsat_Held)
#endif

#ifndef SLOP_LIST_HOWL_KSCSAT_HELD_DEFINED
#define SLOP_LIST_HOWL_KSCSAT_HELD_DEFINED
#define SLOP_LIST_HOWL_KSCSAT_HELD_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_kscsat_Held, slop_list_howl_kscsat_Held)
#endif

struct howl_kscsat_Merged {
    howl_kscsat_RoundOut out;
    slop_list_howl_kscsat_Held held;
};
typedef struct howl_kscsat_Merged howl_kscsat_Merged;

#ifndef SLOP_OPTION_HOWL_KSCSAT_MERGED_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_MERGED_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Merged, slop_option_howl_kscsat_Merged)
#endif

struct howl_kscsat_Merging {
    howl_kscsat_KStore st;
    slop_option_howl_kscsat_Base base;
    int64_t nc;
    slop_list_howl_kscsat_Fresh frs;
    slop_list_int cur;
    slop_list_howl_types_KFact next;
    slop_list_howl_kscsat_Held held;
    int64_t added;
    uint8_t unsat;
    int64_t p;
};
typedef struct howl_kscsat_Merging howl_kscsat_Merging;

#ifndef SLOP_OPTION_HOWL_KSCSAT_MERGING_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_MERGING_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Merging, slop_option_howl_kscsat_Merging)
#endif

struct howl_kscsat_QRuns {
    slop_list_arena_ptr was;
    slop_list_map_ptr outs;
    int64_t cancelled;
};
typedef struct howl_kscsat_QRuns howl_kscsat_QRuns;

#ifndef SLOP_OPTION_HOWL_KSCSAT_QRUNS_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_QRUNS_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_QRuns, slop_option_howl_kscsat_QRuns)
#endif

struct howl_kscsat_QAnswers {
    slop_list_howl_types_ClassAnswer answers;
    uint8_t complete;
};
typedef struct howl_kscsat_QAnswers howl_kscsat_QAnswers;

#ifndef SLOP_OPTION_HOWL_KSCSAT_QANSWERS_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_QANSWERS_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_QAnswers, slop_option_howl_kscsat_QAnswers)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef HOWL_KSCIDS_CFACT_HASH_EQ_DEFINED
#define HOWL_KSCIDS_CFACT_HASH_EQ_DEFINED
static inline uint64_t slop_hash_howl_kscids_CFact(const void* key) {
    const howl_kscids_CFact* _k = (const howl_kscids_CFact*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->kind }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->a }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->b }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->c }); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_howl_kscids_CFact(const void* a, const void* b) {
    const howl_kscids_CFact* _a = (const howl_kscids_CFact*)a;
    const howl_kscids_CFact* _b = (const howl_kscids_CFact*)b;
    return true
        && (_a->kind == _b->kind)
        && (_a->a == _b->a)
        && (_a->b == _b->b)
        && (_a->c == _b->c)
    ;
}
#endif

#ifndef HOWL_TYPES_KELEM_HASH_EQ_DEFINED
#define HOWL_TYPES_KELEM_HASH_EQ_DEFINED
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
#ifndef HOWL_TYPES_KNAME_HASH_EQ_DEFINED
#define HOWL_TYPES_KNAME_HASH_EQ_DEFINED
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
static inline uint64_t slop_hash_howl_types_KName(const void* key) {
    const howl_types_KName* _k = (const howl_types_KName*)key;
    switch (_k->tag) {
        case howl_types_KName_k_class:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.k_class);
        case howl_types_KName_k_fresh:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.k_fresh });
    }
    return 0;
}
static inline bool slop_eq_howl_types_KName(const void* a, const void* b) {
    const howl_types_KName* _a = (const howl_types_KName*)a;
    const howl_types_KName* _b = (const howl_types_KName*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_KName_k_class:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.k_class, &_b->data.k_class);
        case howl_types_KName_k_fresh:
            return _a->data.k_fresh == _b->data.k_fresh;
    }
    return false;
}
#endif
static inline uint64_t slop_hash_howl_types_KElem(const void* key) {
    const howl_types_KElem* _k = (const howl_types_KElem*)key;
    switch (_k->tag) {
        case howl_types_KElem_e_ind:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.e_ind);
        case howl_types_KElem_e_aux:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.e_aux });
        case howl_types_KElem_e_class:
            return slop_hash_howl_types_KName(&_k->data.e_class);
    }
    return 0;
}
static inline bool slop_eq_howl_types_KElem(const void* a, const void* b) {
    const howl_types_KElem* _a = (const howl_types_KElem*)a;
    const howl_types_KElem* _b = (const howl_types_KElem*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_KElem_e_ind:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.e_ind, &_b->data.e_ind);
        case howl_types_KElem_e_aux:
            return _a->data.e_aux == _b->data.e_aux;
        case howl_types_KElem_e_class:
            return slop_eq_howl_types_KName(&_a->data.e_class, &_b->data.e_class);
    }
    return false;
}
#endif

#ifndef SLOP_RESULT_HOWL_TYPES_KSCRESULT_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_TYPES_KSCRESULT_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_types_KscResult ok; howl_types_Fault err; } data; } slop_result_howl_types_KscResult_howl_types_Fault;
#endif

howl_kscsat_Shard howl_kscsat_new_shard(slop_arena* arena);
howl_kscsat_KStore howl_kscsat_new_store(slop_arena* arena, howl_kscids_KscIds ids, int64_t nshards);
int64_t howl_kscsat_shard_count(howl_kscsat_KStore st);
int64_t howl_kscsat_shard_index(uint32_t k, int64_t n);
howl_kscsat_Shard howl_kscsat_shard_at(howl_kscsat_KStore st, uint32_t k);
slop_list_howl_types_KElem howl_kscsat_store_bots(slop_arena* arena, howl_kscsat_KStore st);
slop_list_howl_kscids_CFact howl_kscsat_store_facts(slop_arena* arena, howl_kscsat_KStore st);
uint8_t howl_kscsat_il_push(slop_arena* arena, slop_map* m, uint32_t k, uint32_t i);
uint8_t howl_kscsat_ri_push(slop_arena* arena, slop_map* m, uint32_t k, uint32_t v, uint32_t i);
howl_types_KElem howl_kscsat_fact_subject(howl_types_KFact f);
uint8_t howl_kscsat_is_safe(howl_kscsat_Base b, howl_types_KElem x);
uint8_t howl_kscsat_holds_coded(howl_kscsat_KStore st, howl_kscids_CFact c);
uint8_t howl_kscsat_store_holds(howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_types_KFact f);
uint8_t howl_kscsat_commit(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_types_KFact f);
slop_option_howl_types_KFact howl_kscsat_commit_coded(slop_arena* arena, howl_kscsat_KStore st, howl_kscids_CFact c);
uint8_t howl_kscsat_file_new(slop_arena* arena, howl_kscsat_KStore st, howl_types_KFact f, howl_kscids_CFact c);
uint8_t howl_kscsat_file_subject(slop_arena* arena, howl_kscsat_Shard sh, howl_types_KFact f, howl_kscids_CFact c);
slop_option_u32 howl_kscsat_other_end(howl_kscsat_KStore st, howl_types_KFact f, howl_kscids_CFact c);
uint8_t howl_kscsat_file_other(slop_arena* arena, howl_kscsat_KStore st, howl_kscids_CFact c, uint32_t h);
slop_option_list_u32 howl_kscsat_id_items(slop_map* m, uint32_t k);
slop_map* howl_kscsat_field_map(howl_kscsat_Shard sh, howl_kscsat_Field fd);
uint8_t howl_kscsat_keyed_by_subject(howl_kscsat_Field fd);
slop_list_howl_types_KFact howl_kscsat_subject_items(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KElem k, slop_list_u32 is);
slop_list_howl_types_KFact howl_kscsat_holder_items(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KElem k, slop_list_u32 is);
slop_list_howl_types_KFact howl_kscsat_field_items(slop_arena* arena, howl_kscsat_KStore st, howl_kscsat_Field fd, howl_types_KElem k);
slop_list_howl_types_KFact howl_kscsat_safe_facts(slop_arena* arena, howl_kscsat_Base b, slop_list_howl_types_KFact xs);
slop_list_howl_types_KFact howl_kscsat_w_items(slop_arena* arena, howl_kscsat_Base b, uint8_t by_subject, howl_types_KElem k, slop_list_howl_types_KFact xs);
slop_list_list_howl_types_KFact howl_kscsat_partners(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_kscsat_Field fd, howl_types_KElem k);
slop_list_howl_types_KFact howl_kscsat_leg_facts(slop_arena* arena, howl_kscids_KscIds ids, uint8_t outward, howl_types_KElem k, uint32_t e, slop_list_u32 is);
slop_list_list_howl_types_KFact howl_kscsat_all_ins(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_types_KElem k);
slop_map* howl_kscsat_side_map(howl_kscsat_Shard sh, uint8_t outward);
slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_every_role(slop_arena* arena, howl_kscids_KscIds ids, uint8_t outward, howl_types_KElem k, howl_kscsat_RoleIds rf);
slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_stored_under(slop_arena* arena, howl_kscids_KscIds ids, uint8_t outward, howl_types_KElem k, howl_kscsat_RoleIds rf, howl_kscsat_Under u);
slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_of_subs(slop_arena* arena, howl_kscids_KscIds ids, uint8_t outward, howl_types_KElem k, howl_kscsat_RoleIds rf, slop_list_howl_types_RoleId subs);
slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_under(slop_arena* arena, howl_kscids_KscIds ids, uint8_t outward, howl_types_KElem k, howl_kscsat_RoleIds rf, howl_kscsat_Under u);
slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_in_store(slop_arena* arena, howl_kscsat_KStore st, uint8_t outward, howl_types_KElem k, slop_option_howl_kscsat_Under under);
slop_list_howl_kscsat_RoleLegs howl_kscsat_push_w_legs(slop_arena* arena, slop_list_howl_kscsat_RoleLegs out, howl_kscsat_Base b, uint8_t outward, howl_types_KElem k, slop_option_howl_kscsat_Under u);
slop_list_howl_kscsat_RoleLegs howl_kscsat_role_legs(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, uint8_t outward, howl_types_KElem k, howl_types_RoleId v);
slop_list_list_u32 howl_kscsat_inst_id_lists(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_types_KElem x);
slop_list_howl_kscsat_Match howl_kscsat_partner_matches(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_types_KElem x, howl_kscpremise_KPartners p);
uint8_t howl_kscsat_emit_concl(howl_kscsat_Deriving* d, howl_ksc_Concl c);
uint8_t howl_kscsat_emit_facts(howl_kscsat_Deriving* d, slop_list_howl_types_KFact xs);
uint8_t howl_kscsat_emit_joins(slop_arena* arena, howl_kscsat_Deriving* d, howl_ksc_JoinRule j, howl_types_KFact f, slop_list_list_howl_types_KFact pss, howl_types_KscAxiom ax);
slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_at(slop_arena* arena, howl_kscsat_Deriving* d, uint8_t outward, howl_types_KElem k, howl_types_RoleId v);
uint8_t howl_kscsat_holds_now(howl_kscsat_Deriving* d, howl_types_KFact f);
slop_list_list_howl_types_KFact howl_kscsat_partners_at(slop_arena* arena, howl_kscsat_Deriving* d, howl_kscsat_Field fd, howl_types_KElem k);
slop_list_howl_kscsat_Match howl_kscsat_matches_at(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KElem x, howl_kscpremise_KPartners p);
howl_types_KscAxiom howl_kscsat_no_axiom(void);
uint8_t howl_kscsat_inst_some_lhs(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_KTerm y, howl_types_RoleId v, howl_types_KName a, howl_types_KName z);
uint8_t howl_kscsat_inst_and_pairs(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KElem x, howl_types_KTerm y, howl_kscpremise_KPartners p);
uint8_t howl_kscsat_inst_equality(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_KTerm y);
uint8_t howl_kscsat_derive_inst(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_KTerm y);
uint8_t howl_kscsat_chain_first(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact fv, howl_types_KElem x, howl_types_RoleId v, howl_types_KElem x1, howl_types_RoleId u, howl_types_RoleId v2, howl_types_RoleId w);
uint8_t howl_kscsat_chain_second(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact fv, howl_types_KElem x, howl_types_RoleId v, howl_types_KElem x1, howl_types_RoleId u, howl_types_RoleId v2, howl_types_RoleId w);
uint8_t howl_kscsat_triple_under(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KElem x, howl_types_RoleId v, howl_types_KElem x1);
uint8_t howl_kscsat_derive_triple(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_RoleId e, howl_types_KElem x1);
uint8_t howl_kscsat_self_chain_first(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_RoleId v, howl_types_RoleId u, howl_types_RoleId v2, howl_types_RoleId w);
uint8_t howl_kscsat_self_chain_second(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_RoleId v, howl_types_RoleId u, howl_types_RoleId v2, howl_types_RoleId w);
uint8_t howl_kscsat_derive_self(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_RoleId v);
slop_list_howl_types_KFact howl_kscsat_derive(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f);
howl_types_RoleId howl_kscsat_ksc_dummy_role(void);
uint8_t howl_kscsat_is_bottom_fact(howl_types_KFact f);
uint8_t howl_kscsat_reaches_bottom(slop_option_howl_kscsat_Base base, howl_types_KFact f);
int64_t howl_kscsat_derive_chunk(slop_arena* wa, slop_arena* ra, howl_kscpremise_KscIndex idx, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, slop_list_howl_types_KFact delta, int64_t lo, int64_t hi, slop_map* out);
int64_t howl_kscsat_round_workers(int64_t workers, int64_t n);
howl_kscsat_Derived howl_kscsat_derive_round(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, slop_list_howl_types_KFact delta, int64_t workers);
howl_kscsat_RoundOut howl_kscsat_ksc_round(slop_arena* arena, slop_arena* na, howl_kscpremise_KscIndex idx, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, slop_list_howl_types_KFact delta, uint8_t stop_at_bottom, uint8_t unsat0, int64_t workers, slop_list_arena_ptr cas);
int64_t howl_kscsat_conclusion_count(howl_kscsat_Derived d);
slop_list_howl_kscids_CFact howl_kscsat_chunk_items(slop_arena* arena, slop_map* out);
howl_kscsat_RoundOut howl_kscsat_commit_serial(slop_arena* arena, slop_arena* na, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_kscsat_Derived d, uint8_t stop_at_bottom, uint8_t unsat0);
uint8_t howl_kscsat_parallel_commit_ok(howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_kscsat_Derived d, uint8_t stop_at_bottom, uint8_t unsat0, int64_t nc);
uint8_t howl_kscsat_any_bottom_coded(howl_kscsat_KStore st, howl_kscsat_Derived d);
int64_t howl_kscsat_committer_of(howl_kscsat_KStore st, uint32_t k, int64_t nc);
uint8_t howl_kscsat_seen_in(howl_kscsat_KStore st, howl_kscids_CFact c);
int64_t howl_kscsat_commit_subjects(slop_arena* ca, slop_arena* sa, howl_kscsat_KStore st, howl_kscsat_Derived d, int64_t k, int64_t nc, slop_map* res);
int64_t howl_kscsat_commit_others(slop_arena* ca, howl_kscsat_KStore st, slop_list_howl_kscsat_Held held, int64_t k, int64_t nc);
howl_kscsat_RoundOut howl_kscsat_commit_parallel(slop_arena* scratch, slop_arena* na, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_kscsat_Derived d, slop_list_arena_ptr cas, int64_t nc, uint8_t unsat0);
slop_arena* howl_kscsat_committer_arena(slop_list_arena_ptr cas, int64_t k);
slop_option_howl_types_KFact howl_kscsat_kept_at(howl_kscsat_Merging* m, int64_t k);
int64_t howl_kscsat_cursor_at(slop_list_int cur, int64_t k);
uint8_t howl_kscsat_take_fact(howl_kscsat_Merging* m, howl_types_KFact f, howl_kscids_CFact c);
uint8_t howl_kscsat_merge_step(howl_kscsat_Merging* m, howl_kscids_CFact c);
howl_kscsat_Merged howl_kscsat_merge_fresh(slop_arena* scratch, slop_arena* na, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_kscsat_Derived d, slop_list_map_ptr ress, int64_t nc, uint8_t unsat0);
howl_kscsat_RunResult howl_kscsat_run_ksc(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscids_KscIds ids, slop_option_howl_kscsat_Base base, slop_list_howl_types_KFact seeds, uint8_t stop_at_bottom, int64_t budget, int64_t cancel, int64_t workers, slop_list_arena_ptr cas);
howl_kscsat_RunResult howl_kscsat_run_result(howl_kscsat_KStore st, int64_t rounds, uint8_t unsat, uint8_t capped, uint8_t cancelled, int64_t facts);
howl_kscsat_RoundOut howl_kscsat_seed_run(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, slop_list_howl_types_KFact seeds);
slop_list_howl_types_KName howl_kscsat_answer_subsumers(slop_arena* arena, howl_kscsat_KStore st, howl_types_KName q);
slop_list_u32 howl_kscsat_queue_ins(howl_kscsat_KStore w, slop_map* seen, slop_map* out, slop_list_u32 work, uint32_t xi);
slop_map* howl_kscsat_backward_closure(slop_arena* arena, howl_kscsat_KStore w, slop_list_howl_types_KElem start);
slop_option_howl_types_ClassAnswer howl_kscsat_class_run(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_Base base, uint8_t g_unsat, int64_t budget, int64_t cancel, howl_types_KName q);
howl_types_ClassAnswer howl_kscsat_shared_answer(slop_arena* arena, howl_kscsat_Base base, uint8_t g_unsat, howl_types_KName q);
slop_option_howl_types_ClassAnswer howl_kscsat_class_answer(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_Base base, uint8_t g_unsat, int64_t budget, int64_t cancel, howl_types_KName q);
slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_classify_renamed(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes, howl_types_ReasonerConfig config);
slop_list_arena_ptr howl_kscsat_ksc_commit_arenas(slop_arena* arena, int64_t w);
howl_types_KscResult howl_kscsat_w_capped(slop_arena* arena, howl_kscsat_RunResult g, howl_kscsat_RunResult w, int64_t n);
slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_phase_w(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscids_KscIds ids, howl_kscsat_RunResult g, slop_list_howl_types_KFact wseeds, slop_list_howl_types_KElem tainted, howl_types_KName thing, slop_list_howl_types_KName classes, howl_types_ReasonerConfig config, slop_list_arena_ptr cas, int64_t n);
slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_classify_phases(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes, howl_types_ReasonerConfig config, slop_list_arena_ptr cas);
slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_ksc_classify(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes, howl_types_ReasonerConfig config);
howl_types_KscResult howl_kscsat_unrename_result(slop_arena* arena, howl_kscnames_KscNames nm, howl_types_KscResult r);
howl_types_KscResult howl_kscsat_g_only(slop_arena* arena, howl_kscsat_RunResult g, uint8_t inconsistent);
howl_types_ClassAnswer howl_kscsat_copy_answer(slop_arena* arena, howl_types_ClassAnswer a);
int64_t howl_kscsat_run_chunk(slop_arena* wa, howl_kscpremise_KscIndex idx, howl_kscsat_Base base, int64_t budget, int64_t cancel, slop_list_howl_types_KName classes, slop_list_int todo, slop_map* out);
slop_list_int howl_kscsat_index_chunk(slop_arena* arena, slop_list_int xs, int64_t lo, int64_t hi);
int64_t howl_kscsat_worker_count_for(int64_t workers, int64_t jobs);
howl_kscsat_Base howl_kscsat_over_w_base(slop_arena* arena, howl_kscsat_RunResult g, howl_kscsat_RunResult w, slop_list_howl_types_KElem tainted);
slop_list_int howl_kscsat_split_safe(slop_arena* arena, howl_kscsat_Base base, slop_list_howl_types_KName classes, slop_map* shared);
howl_kscsat_QRuns howl_kscsat_run_unsafe(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_Base base, int64_t budget, int64_t cancel, slop_list_howl_types_KName classes, slop_list_int todo, int64_t workers);
howl_kscsat_QAnswers howl_kscsat_copy_unsafe(slop_arena* arena, howl_kscsat_QAnswers qa, slop_list_map_ptr outs, int64_t i);
howl_kscsat_QAnswers howl_kscsat_collect_answers(slop_arena* arena, slop_list_howl_types_KName classes, slop_map* shared, slop_list_map_ptr outs, uint8_t complete0);
howl_types_KscResult howl_kscsat_over_w_result(howl_kscsat_RunResult g, howl_kscsat_RunResult w, howl_types_ClassAnswer thing_answer, howl_kscsat_QAnswers qa, int64_t jobs);
slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_answer_over_w(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_RunResult g, howl_kscsat_RunResult w, howl_kscsat_Base base, howl_types_ClassAnswer thing_answer, slop_list_howl_types_KName classes, int64_t budget, int64_t workers, int64_t cancel);
slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_classify_over_w(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_RunResult g, howl_kscsat_RunResult w, slop_list_howl_types_KElem tainted, howl_types_KName thing, slop_list_howl_types_KName classes, int64_t budget, int64_t workers, int64_t cancel);
int64_t howl_kscsat_max_rounds(slop_list_howl_types_ClassAnswer answers);
uint8_t howl_kscsat_answer_holds(howl_types_ClassAnswer a, howl_types_KName b);
slop_list_howl_types_KName howl_kscsat_input_classes(slop_arena* arena, howl_owl2_Signature sig);

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_IDLIST_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_IDLIST_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_IdList, slop_option_howl_kscsat_IdList)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_ROLEIDS_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_ROLEIDS_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_RoleIds, slop_option_howl_kscsat_RoleIds)
#endif

#ifndef SLOP_OPTION_HOWL_KSCIDS_CFACT_DEFINED
#define SLOP_OPTION_HOWL_KSCIDS_CFACT_DEFINED
SLOP_OPTION_DEFINE(howl_kscids_CFact, slop_option_howl_kscids_CFact)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KELEM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KELEM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KElem, slop_option_howl_types_KElem)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_SHARD_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_SHARD_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Shard, slop_option_howl_kscsat_Shard)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_KSTORE_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_KSTORE_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_KStore, slop_option_howl_kscsat_KStore)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_BASE_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_BASE_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Base, slop_option_howl_kscsat_Base)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_RUNRESULT_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_RUNRESULT_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_RunResult, slop_option_howl_kscsat_RunResult)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KFACT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(howl_types_KFact, slop_option_howl_types_KFact)
#endif

#ifndef SLOP_OPTION_LIST_U32_DEFINED
#define SLOP_OPTION_LIST_U32_DEFINED
SLOP_OPTION_DEFINE(slop_list_u32, slop_option_list_u32)
#endif

#ifndef SLOP_OPTION_LIST_HOWL_TYPES_KFACT_DEFINED
#define SLOP_OPTION_LIST_HOWL_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(slop_list_howl_types_KFact, slop_option_list_howl_types_KFact)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_ROLELEGS_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_ROLELEGS_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_RoleLegs, slop_option_howl_kscsat_RoleLegs)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_UNDER_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_UNDER_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Under, slop_option_howl_kscsat_Under)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_MATCH_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_MATCH_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Match, slop_option_howl_kscsat_Match)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_DERIVING_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_DERIVING_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Deriving, slop_option_howl_kscsat_Deriving)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_ROUNDOUT_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_ROUNDOUT_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_RoundOut, slop_option_howl_kscsat_RoundOut)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_CFACTLIST_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_CFACTLIST_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_CFactList, slop_option_howl_kscsat_CFactList)
#endif

#ifndef SLOP_OPTION_ARENA_PTR_DEFINED
#define SLOP_OPTION_ARENA_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_arena*, slop_option_arena_ptr)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_DERIVED_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_DERIVED_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Derived, slop_option_howl_kscsat_Derived)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_FRESH_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_FRESH_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Fresh, slop_option_howl_kscsat_Fresh)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_HELD_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_HELD_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Held, slop_option_howl_kscsat_Held)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_MERGED_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_MERGED_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Merged, slop_option_howl_kscsat_Merged)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_MERGING_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_MERGING_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_Merging, slop_option_howl_kscsat_Merging)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_KName, slop_option_howl_types_KName)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLASSANSWER_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLASSANSWER_DEFINED
SLOP_OPTION_DEFINE(howl_types_ClassAnswer, slop_option_howl_types_ClassAnswer)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscAxiom, slop_option_howl_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_QRUNS_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_QRUNS_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_QRuns, slop_option_howl_kscsat_QRuns)
#endif

#ifndef SLOP_OPTION_HOWL_KSCSAT_QANSWERS_DEFINED
#define SLOP_OPTION_HOWL_KSCSAT_QANSWERS_DEFINED
SLOP_OPTION_DEFINE(howl_kscsat_QAnswers, slop_option_howl_kscsat_QAnswers)
#endif

#ifndef SLOP_OPTION_HOWL_KSCPREMISE_KLIST_DEFINED
#define SLOP_OPTION_HOWL_KSCPREMISE_KLIST_DEFINED
SLOP_OPTION_DEFINE(howl_kscpremise_KList, slop_option_howl_kscpremise_KList)
#endif

#ifndef SLOP_OPTION_THREAD_INT_PTR_DEFINED
#define SLOP_OPTION_THREAD_INT_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_thread_int*, slop_option_thread_int_ptr)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_LIST_THREAD_INT_PTR_DEFINED
#define SLOP_LIST_THREAD_INT_PTR_DEFINED
#define SLOP_LIST_THREAD_INT_PTR_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_thread_int*, slop_list_thread_int_ptr)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif


#endif
