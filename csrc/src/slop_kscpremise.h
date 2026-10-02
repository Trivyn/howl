#ifndef SLOP_kscpremise_H
#define SLOP_kscpremise_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"

typedef struct kscpremise_KList kscpremise_KList;
typedef struct kscpremise_KPartners kscpremise_KPartners;
typedef struct kscpremise_RoleList kscpremise_RoleList;
typedef struct kscpremise_RolePair kscpremise_RolePair;
typedef struct kscpremise_KscIndex kscpremise_KscIndex;

#ifndef SLOP_LIST_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_TYPES_KSCAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KscAxiom, slop_list_types_KscAxiom)
#endif

#ifndef SLOP_LIST_TYPES_KTERM_DEFINED
#define SLOP_LIST_TYPES_KTERM_DEFINED
#define SLOP_LIST_TYPES_KTERM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KTerm, slop_list_types_KTerm)
#endif

#ifndef SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(types_RoleId, slop_list_types_RoleId)
#endif

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_KTERM_DEFINED
#define SLOP_OPTION_TYPES_KTERM_DEFINED
SLOP_OPTION_DEFINE(types_KTerm, slop_option_types_KTerm)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

struct kscpremise_KList {
    slop_list_types_KscAxiom items;
};
typedef struct kscpremise_KList kscpremise_KList;

#ifndef SLOP_OPTION_KSCPREMISE_KLIST_DEFINED
#define SLOP_OPTION_KSCPREMISE_KLIST_DEFINED
SLOP_OPTION_DEFINE(kscpremise_KList, slop_option_kscpremise_KList)
#endif

struct kscpremise_KPartners {
    slop_map* by_other;
    int64_t count;
};
typedef struct kscpremise_KPartners kscpremise_KPartners;

#ifndef SLOP_OPTION_KSCPREMISE_KPARTNERS_DEFINED
#define SLOP_OPTION_KSCPREMISE_KPARTNERS_DEFINED
SLOP_OPTION_DEFINE(kscpremise_KPartners, slop_option_kscpremise_KPartners)
#endif

struct kscpremise_RoleList {
    slop_list_types_RoleId items;
};
typedef struct kscpremise_RoleList kscpremise_RoleList;

#ifndef SLOP_OPTION_KSCPREMISE_ROLELIST_DEFINED
#define SLOP_OPTION_KSCPREMISE_ROLELIST_DEFINED
SLOP_OPTION_DEFINE(kscpremise_RoleList, slop_option_kscpremise_RoleList)
#endif

struct kscpremise_RolePair {
    types_RoleId sub;
    types_RoleId sup;
};
typedef struct kscpremise_RolePair kscpremise_RolePair;

#ifndef SLOP_OPTION_KSCPREMISE_ROLEPAIR_DEFINED
#define SLOP_OPTION_KSCPREMISE_ROLEPAIR_DEFINED
SLOP_OPTION_DEFINE(kscpremise_RolePair, slop_option_kscpremise_RolePair)
#endif

#ifndef SLOP_LIST_KSCPREMISE_ROLEPAIR_DEFINED
#define SLOP_LIST_KSCPREMISE_ROLEPAIR_DEFINED
#define SLOP_LIST_KSCPREMISE_ROLEPAIR_IMPL_DEFINED
SLOP_LIST_DEFINE(kscpremise_RolePair, slop_list_kscpremise_RolePair)
#endif

struct kscpremise_KscIndex {
    slop_map* sups;
    slop_map* subs;
    slop_map* below;
    slop_map* on_term;
    slop_map* on_role;
    slop_map* and_pairs;
    slop_map* ex_by_role;
    slop_list_rdf_IRI individuals;
};
typedef struct kscpremise_KscIndex kscpremise_KscIndex;

#ifndef SLOP_OPTION_KSCPREMISE_KSCINDEX_DEFINED
#define SLOP_OPTION_KSCPREMISE_KSCINDEX_DEFINED
SLOP_OPTION_DEFINE(kscpremise_KscIndex, slop_option_kscpremise_KscIndex)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef TYPES_KTERM_HASH_EQ_DEFINED
#define TYPES_KTERM_HASH_EQ_DEFINED
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
static inline uint64_t slop_hash_types_KTerm(const void* key) {
    const types_KTerm* _k = (const types_KTerm*)key;
    switch (_k->tag) {
        case types_KTerm_k_name:
            return slop_hash_types_KName(&_k->data.k_name);
        case types_KTerm_k_nominal:
            return slop_hash_rdf_IRI(&_k->data.k_nominal);
    }
    return 0;
}
static inline bool slop_eq_types_KTerm(const void* a, const void* b) {
    const types_KTerm* _a = (const types_KTerm*)a;
    const types_KTerm* _b = (const types_KTerm*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case types_KTerm_k_name:
            return slop_eq_types_KName(&_a->data.k_name, &_b->data.k_name);
        case types_KTerm_k_nominal:
            return slop_eq_rdf_IRI(&_a->data.k_nominal, &_b->data.k_nominal);
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
static inline uint64_t slop_hash_types_RoleId(const void* key) {
    const types_RoleId* _k = (const types_RoleId*)key;
    switch (_k->tag) {
        case types_RoleId_named_role:
            return slop_hash_rdf_IRI(&_k->data.named_role);
        case types_RoleId_fresh_role:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.fresh_role });
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
    }
    return false;
}
#endif

#ifndef KSCPREMISE_ROLEPAIR_HASH_EQ_DEFINED
#define KSCPREMISE_ROLEPAIR_HASH_EQ_DEFINED
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
static inline uint64_t slop_hash_types_RoleId(const void* key) {
    const types_RoleId* _k = (const types_RoleId*)key;
    switch (_k->tag) {
        case types_RoleId_named_role:
            return slop_hash_rdf_IRI(&_k->data.named_role);
        case types_RoleId_fresh_role:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.fresh_role });
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
static inline uint64_t slop_hash_types_RoleId(const void* key) {
    const types_RoleId* _k = (const types_RoleId*)key;
    switch (_k->tag) {
        case types_RoleId_named_role:
            return slop_hash_rdf_IRI(&_k->data.named_role);
        case types_RoleId_fresh_role:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.fresh_role });
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
    }
    return false;
}
#endif
static inline uint64_t slop_hash_kscpremise_RolePair(const void* key) {
    const kscpremise_RolePair* _k = (const kscpremise_RolePair*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_types_RoleId(&_k->sub); hash *= 1099511628211ULL;
    hash ^= slop_hash_types_RoleId(&_k->sup); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_kscpremise_RolePair(const void* a, const void* b) {
    const kscpremise_RolePair* _a = (const kscpremise_RolePair*)a;
    const kscpremise_RolePair* _b = (const kscpremise_RolePair*)b;
    return true
        && (slop_eq_types_RoleId(&_a->sub, &_b->sub))
        && (slop_eq_types_RoleId(&_a->sup, &_b->sup))
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

kscpremise_KList kscpremise_k_pushed(slop_arena* arena, slop_option_kscpremise_KList found, types_KscAxiom ax);
uint8_t kscpremise_k_partnered(slop_arena* arena, slop_map* m, types_KTerm key, types_KTerm other, types_KscAxiom ax);
uint8_t kscpremise_r_partnered(slop_arena* arena, slop_map* m, types_RoleId key, types_KTerm other, types_KscAxiom ax);
uint8_t kscpremise_file_term(slop_arena* arena, slop_map* m, types_KTerm y, types_KscAxiom ax);
uint8_t kscpremise_file_role(slop_arena* arena, slop_map* m, types_RoleId v, types_KscAxiom ax);
uint8_t kscpremise_first_mention(slop_arena* arena, slop_map* seen, rdf_IRI a);
slop_option_rdf_IRI kscpremise_term_individual(types_KTerm t);
kscpremise_KscIndex kscpremise_build_ksc_index(slop_arena* arena, slop_list_types_KscAxiom axioms);
slop_option_kscpremise_KList kscpremise_term_bucket(kscpremise_KscIndex idx, types_KTerm y);
slop_option_kscpremise_KList kscpremise_role_bucket(kscpremise_KscIndex idx, types_RoleId v);
slop_option_kscpremise_KPartners kscpremise_and_partners(kscpremise_KscIndex idx, types_KTerm y);
slop_option_kscpremise_KPartners kscpremise_ex_partners(kscpremise_KscIndex idx, types_RoleId v);
kscpremise_RoleList kscpremise_role_pushed(slop_arena* arena, slop_option_kscpremise_RoleList found, types_RoleId r);
kscpremise_RoleList kscpremise_role_walk(slop_arena* arena, slop_map* edges, types_RoleId r);
slop_list_types_RoleId kscpremise_role_sups(slop_arena* arena, kscpremise_KscIndex idx, types_RoleId e);
slop_list_types_RoleId kscpremise_role_subs(slop_arena* arena, kscpremise_KscIndex idx, types_RoleId v);
uint8_t kscpremise_role_under(kscpremise_KscIndex idx, types_RoleId e, types_RoleId v);

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_KSCPREMISE_KLIST_DEFINED
#define SLOP_OPTION_KSCPREMISE_KLIST_DEFINED
SLOP_OPTION_DEFINE(kscpremise_KList, slop_option_kscpremise_KList)
#endif

#ifndef SLOP_OPTION_TYPES_KTERM_DEFINED
#define SLOP_OPTION_TYPES_KTERM_DEFINED
SLOP_OPTION_DEFINE(types_KTerm, slop_option_types_KTerm)
#endif

#ifndef SLOP_OPTION_KSCPREMISE_KPARTNERS_DEFINED
#define SLOP_OPTION_KSCPREMISE_KPARTNERS_DEFINED
SLOP_OPTION_DEFINE(kscpremise_KPartners, slop_option_kscpremise_KPartners)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_KSCPREMISE_ROLELIST_DEFINED
#define SLOP_OPTION_KSCPREMISE_ROLELIST_DEFINED
SLOP_OPTION_DEFINE(kscpremise_RoleList, slop_option_kscpremise_RoleList)
#endif

#ifndef SLOP_OPTION_KSCPREMISE_ROLEPAIR_DEFINED
#define SLOP_OPTION_KSCPREMISE_ROLEPAIR_DEFINED
SLOP_OPTION_DEFINE(kscpremise_RolePair, slop_option_kscpremise_RolePair)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_KSCPREMISE_KSCINDEX_DEFINED
#define SLOP_OPTION_KSCPREMISE_KSCINDEX_DEFINED
SLOP_OPTION_DEFINE(kscpremise_KscIndex, slop_option_kscpremise_KscIndex)
#endif


#endif
