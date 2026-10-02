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
typedef struct kscsat_KStore kscsat_KStore;
typedef struct kscsat_Base kscsat_Base;
typedef struct kscsat_RunResult kscsat_RunResult;
typedef struct kscsat_RoleLegs kscsat_RoleLegs;
typedef struct kscsat_Under kscsat_Under;
typedef struct kscsat_Match kscsat_Match;
typedef struct kscsat_RoundOut kscsat_RoundOut;

typedef enum {
    kscsat_Field_fd_insts,
    kscsat_Field_fd_noms,
    kscsat_Field_fd_holders
} kscsat_Field;

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

struct kscsat_KStore {
    kscids_KscIds ids;
    slop_map* seen;
    slop_map* insts;
    slop_map* noms;
    slop_map* holders;
    slop_map* outs;
    slop_map* ins;
    slop_map* noms_at;
    slop_map* bots;
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

kscsat_KStore kscsat_new_store(slop_arena* arena, kscids_KscIds ids);
uint8_t kscsat_il_push(slop_arena* arena, slop_map* m, uint32_t k, uint32_t i);
uint8_t kscsat_ri_push(slop_arena* arena, slop_map* m, uint32_t k, uint32_t v, uint32_t i);
types_KElem kscsat_fact_subject(types_KFact f);
uint8_t kscsat_is_safe(kscsat_Base b, types_KElem x);
uint8_t kscsat_store_holds(kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f);
uint8_t kscsat_commit(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f);
slop_option_list_u32 kscsat_id_items(slop_map* m, uint32_t k);
slop_map* kscsat_field_map(kscsat_KStore st, kscsat_Field fd);
uint8_t kscsat_keyed_by_subject(kscsat_Field fd);
slop_list_types_KFact kscsat_field_items(slop_arena* arena, kscsat_KStore st, kscsat_Field fd, types_KElem k);
slop_list_types_KFact kscsat_safe_facts(slop_arena* arena, kscsat_Base b, slop_list_types_KFact xs);
slop_list_types_KFact kscsat_w_items(slop_arena* arena, kscsat_Base b, uint8_t by_subject, types_KElem k, slop_list_types_KFact xs);
slop_list_list_types_KFact kscsat_partners(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, kscsat_Field fd, types_KElem k);
slop_list_types_KFact kscsat_leg_facts(slop_arena* arena, kscids_KscIds ids, uint8_t outward, types_KElem k, uint32_t e, slop_list_u32 is);
slop_list_list_types_KFact kscsat_all_ins(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KElem k);
slop_map* kscsat_side_map(kscsat_KStore st, uint8_t outward);
slop_list_kscsat_RoleLegs kscsat_legs_in_store(slop_arena* arena, kscsat_KStore st, uint8_t outward, types_KElem k, slop_option_kscsat_Under under);
slop_list_kscsat_RoleLegs kscsat_role_legs(slop_arena* arena, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, uint8_t outward, types_KElem k, types_RoleId v);
slop_list_list_u32 kscsat_inst_id_lists(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KElem x);
slop_list_kscsat_Match kscsat_partner_matches(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KElem x, kscpremise_KPartners p);
slop_list_types_KFact kscsat_derive(slop_arena* arena, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f);
types_RoleId kscsat_ksc_dummy_role(void);
uint8_t kscsat_is_bottom_fact(types_KFact f);
uint8_t kscsat_reaches_bottom(slop_option_kscsat_Base base, types_KFact f);
slop_list_types_KFact kscsat_delta_push(slop_arena* na, slop_list_types_KFact l, types_KFact c);
kscsat_RoundOut kscsat_ksc_round(slop_arena* arena, slop_arena* na, slop_arena* ra, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, slop_list_types_KFact delta, uint8_t stop_at_bottom, uint8_t unsat0);
kscsat_RunResult kscsat_run_ksc(slop_arena* arena, kscpremise_KscIndex idx, kscids_KscIds ids, slop_option_kscsat_Base base, slop_list_types_KFact seeds, uint8_t stop_at_bottom, int64_t budget, int64_t cancel);
kscsat_RoundOut kscsat_seed_run(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, slop_list_types_KFact seeds);
slop_list_types_KName kscsat_answer_subsumers(slop_arena* arena, kscsat_KStore st, types_KName q);
slop_map* kscsat_backward_closure(slop_arena* arena, kscsat_KStore w, slop_list_types_KElem start);
slop_option_types_ClassAnswer kscsat_class_run(slop_arena* arena, kscpremise_KscIndex idx, kscsat_Base base, uint8_t g_unsat, int64_t budget, int64_t cancel, types_KName q);
types_ClassAnswer kscsat_shared_answer(slop_arena* arena, kscsat_Base base, uint8_t g_unsat, types_KName q);
slop_option_types_ClassAnswer kscsat_class_answer(slop_arena* arena, kscpremise_KscIndex idx, kscsat_Base base, uint8_t g_unsat, int64_t budget, int64_t cancel, types_KName q);
slop_result_types_KscResult_types_Fault kscsat_classify_renamed(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, types_ReasonerConfig config);
slop_result_types_KscResult_types_Fault kscsat_ksc_classify(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, types_ReasonerConfig config);
types_KscResult kscsat_unrename_result(slop_arena* arena, kscnames_KscNames nm, types_KscResult r);
types_KscResult kscsat_g_only(slop_arena* arena, kscsat_RunResult g, uint8_t inconsistent);
types_ClassAnswer kscsat_copy_answer(slop_arena* arena, types_ClassAnswer a);
int64_t kscsat_run_chunk(slop_arena* wa, kscpremise_KscIndex idx, kscsat_Base base, int64_t budget, int64_t cancel, slop_list_types_KName classes, slop_list_int todo, slop_map* out);
slop_list_int kscsat_index_chunk(slop_arena* arena, slop_list_int xs, int64_t lo, int64_t hi);
int64_t kscsat_worker_count_for(int64_t workers, int64_t jobs);
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

#ifndef SLOP_OPTION_LIST_U32_DEFINED
#define SLOP_OPTION_LIST_U32_DEFINED
SLOP_OPTION_DEFINE(slop_list_u32, slop_option_list_u32)
#endif

#ifndef SLOP_OPTION_TYPES_KFACT_DEFINED
#define SLOP_OPTION_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(types_KFact, slop_option_types_KFact)
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

#ifndef SLOP_OPTION_KSCSAT_MATCH_DEFINED
#define SLOP_OPTION_KSCSAT_MATCH_DEFINED
SLOP_OPTION_DEFINE(kscsat_Match, slop_option_kscsat_Match)
#endif

#ifndef SLOP_OPTION_KSCSAT_ROUNDOUT_DEFINED
#define SLOP_OPTION_KSCSAT_ROUNDOUT_DEFINED
SLOP_OPTION_DEFINE(kscsat_RoundOut, slop_option_kscsat_RoundOut)
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

#ifndef SLOP_OPTION_KSCPREMISE_KLIST_DEFINED
#define SLOP_OPTION_KSCPREMISE_KLIST_DEFINED
SLOP_OPTION_DEFINE(kscpremise_KList, slop_option_kscpremise_KList)
#endif

#ifndef SLOP_OPTION_ARENA_PTR_DEFINED
#define SLOP_OPTION_ARENA_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_arena*, slop_option_arena_ptr)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_OPTION_THREAD_INT_PTR_DEFINED
#define SLOP_OPTION_THREAD_INT_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_thread_int*, slop_option_thread_int_ptr)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

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
