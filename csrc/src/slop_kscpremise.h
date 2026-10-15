#ifndef SLOP_kscpremise_H
#define SLOP_kscpremise_H

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

typedef struct howl_kscpremise_KList howl_kscpremise_KList;
typedef struct howl_kscpremise_KPartners howl_kscpremise_KPartners;
typedef struct howl_kscpremise_RoleList howl_kscpremise_RoleList;
typedef struct howl_kscpremise_RolePair howl_kscpremise_RolePair;
typedef struct howl_kscpremise_KscIndex howl_kscpremise_KscIndex;

#ifndef SLOP_LIST_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KSCAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KscAxiom, slop_list_howl_types_KscAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_KTERM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KTERM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KTERM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KTerm, slop_list_howl_types_KTerm)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_RoleId, slop_list_howl_types_RoleId)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscAxiom, slop_option_howl_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KTERM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KTERM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KTerm, slop_option_howl_types_KTerm)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

struct howl_kscpremise_KList {
    slop_list_howl_types_KscAxiom items;
};
typedef struct howl_kscpremise_KList howl_kscpremise_KList;

#ifndef SLOP_OPTION_HOWL_KSCPREMISE_KLIST_DEFINED
#define SLOP_OPTION_HOWL_KSCPREMISE_KLIST_DEFINED
SLOP_OPTION_DEFINE(howl_kscpremise_KList, slop_option_howl_kscpremise_KList)
#endif

struct howl_kscpremise_KPartners {
    slop_map* by_other;
    int64_t count;
};
typedef struct howl_kscpremise_KPartners howl_kscpremise_KPartners;

#ifndef SLOP_OPTION_HOWL_KSCPREMISE_KPARTNERS_DEFINED
#define SLOP_OPTION_HOWL_KSCPREMISE_KPARTNERS_DEFINED
SLOP_OPTION_DEFINE(howl_kscpremise_KPartners, slop_option_howl_kscpremise_KPartners)
#endif

struct howl_kscpremise_RoleList {
    slop_list_howl_types_RoleId items;
};
typedef struct howl_kscpremise_RoleList howl_kscpremise_RoleList;

#ifndef SLOP_OPTION_HOWL_KSCPREMISE_ROLELIST_DEFINED
#define SLOP_OPTION_HOWL_KSCPREMISE_ROLELIST_DEFINED
SLOP_OPTION_DEFINE(howl_kscpremise_RoleList, slop_option_howl_kscpremise_RoleList)
#endif

struct howl_kscpremise_RolePair {
    howl_types_RoleId sub;
    howl_types_RoleId sup;
};
typedef struct howl_kscpremise_RolePair howl_kscpremise_RolePair;

#ifndef SLOP_OPTION_HOWL_KSCPREMISE_ROLEPAIR_DEFINED
#define SLOP_OPTION_HOWL_KSCPREMISE_ROLEPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_kscpremise_RolePair, slop_option_howl_kscpremise_RolePair)
#endif

#ifndef SLOP_LIST_HOWL_KSCPREMISE_ROLEPAIR_DEFINED
#define SLOP_LIST_HOWL_KSCPREMISE_ROLEPAIR_DEFINED
#define SLOP_LIST_HOWL_KSCPREMISE_ROLEPAIR_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_kscpremise_RolePair, slop_list_howl_kscpremise_RolePair)
#endif

struct howl_kscpremise_KscIndex {
    slop_map* sups;
    slop_map* subs;
    slop_map* below;
    slop_map* on_term;
    slop_map* on_role;
    slop_map* and_pairs;
    slop_map* ex_by_role;
    slop_list_slop_rdf_rdf_IRI individuals;
};
typedef struct howl_kscpremise_KscIndex howl_kscpremise_KscIndex;

#ifndef SLOP_OPTION_HOWL_KSCPREMISE_KSCINDEX_DEFINED
#define SLOP_OPTION_HOWL_KSCPREMISE_KSCINDEX_DEFINED
SLOP_OPTION_DEFINE(howl_kscpremise_KscIndex, slop_option_howl_kscpremise_KscIndex)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef HOWL_TYPES_KTERM_HASH_EQ_DEFINED
#define HOWL_TYPES_KTERM_HASH_EQ_DEFINED
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
static inline uint64_t slop_hash_howl_types_KTerm(const void* key) {
    const howl_types_KTerm* _k = (const howl_types_KTerm*)key;
    switch (_k->tag) {
        case howl_types_KTerm_k_name:
            return slop_hash_howl_types_KName(&_k->data.k_name);
        case howl_types_KTerm_k_nominal:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.k_nominal);
    }
    return 0;
}
static inline bool slop_eq_howl_types_KTerm(const void* a, const void* b) {
    const howl_types_KTerm* _a = (const howl_types_KTerm*)a;
    const howl_types_KTerm* _b = (const howl_types_KTerm*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_KTerm_k_name:
            return slop_eq_howl_types_KName(&_a->data.k_name, &_b->data.k_name);
        case howl_types_KTerm_k_nominal:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.k_nominal, &_b->data.k_nominal);
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

#ifndef HOWL_KSCPREMISE_ROLEPAIR_HASH_EQ_DEFINED
#define HOWL_KSCPREMISE_ROLEPAIR_HASH_EQ_DEFINED
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
static inline uint64_t slop_hash_howl_kscpremise_RolePair(const void* key) {
    const howl_kscpremise_RolePair* _k = (const howl_kscpremise_RolePair*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_howl_types_RoleId(&_k->sub); hash *= 1099511628211ULL;
    hash ^= slop_hash_howl_types_RoleId(&_k->sup); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_howl_kscpremise_RolePair(const void* a, const void* b) {
    const howl_kscpremise_RolePair* _a = (const howl_kscpremise_RolePair*)a;
    const howl_kscpremise_RolePair* _b = (const howl_kscpremise_RolePair*)b;
    return true
        && (slop_eq_howl_types_RoleId(&_a->sub, &_b->sub))
        && (slop_eq_howl_types_RoleId(&_a->sup, &_b->sup))
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

howl_kscpremise_KList howl_kscpremise_k_pushed(slop_arena* arena, slop_option_howl_kscpremise_KList found, howl_types_KscAxiom ax);
uint8_t howl_kscpremise_k_partnered(slop_arena* arena, slop_map* m, howl_types_KTerm key, howl_types_KTerm other, howl_types_KscAxiom ax);
uint8_t howl_kscpremise_r_partnered(slop_arena* arena, slop_map* m, howl_types_RoleId key, howl_types_KTerm other, howl_types_KscAxiom ax);
uint8_t howl_kscpremise_file_term(slop_arena* arena, slop_map* m, howl_types_KTerm y, howl_types_KscAxiom ax);
uint8_t howl_kscpremise_file_role(slop_arena* arena, slop_map* m, howl_types_RoleId v, howl_types_KscAxiom ax);
uint8_t howl_kscpremise_first_mention(slop_arena* arena, slop_map* seen, slop_rdf_rdf_IRI a);
slop_option_slop_rdf_rdf_IRI howl_kscpremise_term_individual(howl_types_KTerm t);
howl_kscpremise_KscIndex howl_kscpremise_build_ksc_index(slop_arena* arena, slop_list_howl_types_KscAxiom axioms);
slop_option_howl_kscpremise_KList howl_kscpremise_term_bucket(howl_kscpremise_KscIndex idx, howl_types_KTerm y);
slop_option_howl_kscpremise_KList howl_kscpremise_role_bucket(howl_kscpremise_KscIndex idx, howl_types_RoleId v);
slop_option_howl_kscpremise_KPartners howl_kscpremise_and_partners(howl_kscpremise_KscIndex idx, howl_types_KTerm y);
slop_option_howl_kscpremise_KPartners howl_kscpremise_ex_partners(howl_kscpremise_KscIndex idx, howl_types_RoleId v);
howl_kscpremise_RoleList howl_kscpremise_role_pushed(slop_arena* arena, slop_option_howl_kscpremise_RoleList found, howl_types_RoleId r);
howl_kscpremise_RoleList howl_kscpremise_role_walk(slop_arena* arena, slop_map* edges, howl_types_RoleId r);
slop_list_howl_types_RoleId howl_kscpremise_role_sups(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_types_RoleId e);
slop_list_howl_types_RoleId howl_kscpremise_role_subs(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_types_RoleId v);
uint8_t howl_kscpremise_role_under(howl_kscpremise_KscIndex idx, howl_types_RoleId e, howl_types_RoleId v);

#ifndef SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscAxiom, slop_option_howl_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_KSCPREMISE_KLIST_DEFINED
#define SLOP_OPTION_HOWL_KSCPREMISE_KLIST_DEFINED
SLOP_OPTION_DEFINE(howl_kscpremise_KList, slop_option_howl_kscpremise_KList)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KTERM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KTERM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KTerm, slop_option_howl_types_KTerm)
#endif

#ifndef SLOP_OPTION_HOWL_KSCPREMISE_KPARTNERS_DEFINED
#define SLOP_OPTION_HOWL_KSCPREMISE_KPARTNERS_DEFINED
SLOP_OPTION_DEFINE(howl_kscpremise_KPartners, slop_option_howl_kscpremise_KPartners)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_KSCPREMISE_ROLELIST_DEFINED
#define SLOP_OPTION_HOWL_KSCPREMISE_ROLELIST_DEFINED
SLOP_OPTION_DEFINE(howl_kscpremise_RoleList, slop_option_howl_kscpremise_RoleList)
#endif

#ifndef SLOP_OPTION_HOWL_KSCPREMISE_ROLEPAIR_DEFINED
#define SLOP_OPTION_HOWL_KSCPREMISE_ROLEPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_kscpremise_RolePair, slop_option_howl_kscpremise_RolePair)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_KSCPREMISE_KSCINDEX_DEFINED
#define SLOP_OPTION_HOWL_KSCPREMISE_KSCINDEX_DEFINED
SLOP_OPTION_DEFINE(howl_kscpremise_KscIndex, slop_option_howl_kscpremise_KscIndex)
#endif


#endif
