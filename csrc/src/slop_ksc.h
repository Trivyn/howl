#ifndef SLOP_ksc_H
#define SLOP_ksc_H

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
#include "slop_vocab.h"

typedef struct howl_ksc_Concl howl_ksc_Concl;

typedef enum {
    howl_ksc_JoinRule_j7_inst,
    howl_ksc_JoinRule_j15_first,
    howl_ksc_JoinRule_j15_second,
    howl_ksc_JoinRule_j16_self,
    howl_ksc_JoinRule_j17_self,
    howl_ksc_JoinRule_j27_nom,
    howl_ksc_JoinRule_j27_other,
    howl_ksc_JoinRule_j28_nom,
    howl_ksc_JoinRule_j28_ind,
    howl_ksc_JoinRule_j29_nom,
    howl_ksc_JoinRule_j29_triple
} howl_ksc_JoinRule;

#ifndef SLOP_LIST_HOWL_TYPES_KFACT_DEFINED
#define SLOP_LIST_HOWL_TYPES_KFACT_DEFINED
#define SLOP_LIST_HOWL_TYPES_KFACT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KFact, slop_list_howl_types_KFact)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KSCAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KscAxiom, slop_list_howl_types_KscAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_KNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_KNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_KNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KName, slop_list_howl_types_KName)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KFACT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(howl_types_KFact, slop_option_howl_types_KFact)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscAxiom, slop_option_howl_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_KName, slop_option_howl_types_KName)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

struct howl_ksc_Concl {
    uint8_t fires;
    howl_types_KFact fact;
};
typedef struct howl_ksc_Concl howl_ksc_Concl;

#ifndef SLOP_OPTION_HOWL_KSC_CONCL_DEFINED
#define SLOP_OPTION_HOWL_KSC_CONCL_DEFINED
SLOP_OPTION_DEFINE(howl_ksc_Concl, slop_option_howl_ksc_Concl)
#endif

#ifndef SLOP_LIST_HOWL_KSC_CONCL_DEFINED
#define SLOP_LIST_HOWL_KSC_CONCL_DEFINED
#define SLOP_LIST_HOWL_KSC_CONCL_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_ksc_Concl, slop_list_howl_ksc_Concl)
#endif


/* Hash/eq functions and list types for struct map/set keys */
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

#ifndef HOWL_TYPES_KFACT_HASH_EQ_DEFINED
#define HOWL_TYPES_KFACT_HASH_EQ_DEFINED
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
static inline uint64_t slop_hash_howl_types_KFact(const void* key) {
    const howl_types_KFact* _k = (const howl_types_KFact*)key;
    switch (_k->tag) {
        case howl_types_KFact_f_inst:
            {
                uint64_t hash = 14695981039346656037ULL;
                hash ^= slop_hash_howl_types_KElem(&_k->data.f_inst.f0); hash *= 1099511628211ULL;
                hash ^= slop_hash_howl_types_KTerm(&_k->data.f_inst.f1); hash *= 1099511628211ULL;
                return hash;
            }
        case howl_types_KFact_f_triple:
            {
                uint64_t hash = 14695981039346656037ULL;
                hash ^= slop_hash_howl_types_KElem(&_k->data.f_triple.f0); hash *= 1099511628211ULL;
                hash ^= slop_hash_howl_types_RoleId(&_k->data.f_triple.f1); hash *= 1099511628211ULL;
                hash ^= slop_hash_howl_types_KElem(&_k->data.f_triple.f2); hash *= 1099511628211ULL;
                return hash;
            }
        case howl_types_KFact_f_self:
            {
                uint64_t hash = 14695981039346656037ULL;
                hash ^= slop_hash_howl_types_KElem(&_k->data.f_self.f0); hash *= 1099511628211ULL;
                hash ^= slop_hash_howl_types_RoleId(&_k->data.f_self.f1); hash *= 1099511628211ULL;
                return hash;
            }
    }
    return 0;
}
static inline bool slop_eq_howl_types_KFact(const void* a, const void* b) {
    const howl_types_KFact* _a = (const howl_types_KFact*)a;
    const howl_types_KFact* _b = (const howl_types_KFact*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_KFact_f_inst:
            return true
                && slop_eq_howl_types_KElem(&_a->data.f_inst.f0, &_b->data.f_inst.f0)
                && slop_eq_howl_types_KTerm(&_a->data.f_inst.f1, &_b->data.f_inst.f1)
            ;
        case howl_types_KFact_f_triple:
            return true
                && slop_eq_howl_types_KElem(&_a->data.f_triple.f0, &_b->data.f_triple.f0)
                && slop_eq_howl_types_RoleId(&_a->data.f_triple.f1, &_b->data.f_triple.f1)
                && slop_eq_howl_types_KElem(&_a->data.f_triple.f2, &_b->data.f_triple.f2)
            ;
        case howl_types_KFact_f_self:
            return true
                && slop_eq_howl_types_KElem(&_a->data.f_self.f0, &_b->data.f_self.f0)
                && slop_eq_howl_types_RoleId(&_a->data.f_self.f1, &_b->data.f_self.f1)
            ;
    }
    return false;
}
#endif

uint8_t howl_ksc_is_name(howl_types_KTerm t, howl_types_KName n);
uint8_t howl_ksc_is_nominal(howl_types_KTerm t);
uint8_t howl_ksc_is_individual(howl_types_KElem x);
howl_types_KElem howl_ksc_term_elem(howl_types_KTerm t);
uint8_t howl_ksc_concl_eq(howl_ksc_Concl a, howl_ksc_Concl b);
slop_rdf_rdf_IRI howl_ksc_ex_a(void);
slop_rdf_rdf_IRI howl_ksc_ex_b(void);
howl_types_KName howl_ksc_ex_A(void);
howl_types_KName howl_ksc_ex_B(void);
howl_types_KName howl_ksc_ex_C(void);
howl_types_RoleId howl_ksc_ex_r(void);
howl_types_RoleId howl_ksc_ex_s(void);
howl_types_RoleId howl_ksc_ex_t(void);
howl_types_KElem howl_ksc_ex_x(void);
howl_types_KElem howl_ksc_ex_w(void);
howl_types_KElem howl_ksc_ex_ia(void);
howl_types_KTerm howl_ksc_ex_tA(void);
howl_types_KTerm howl_ksc_ex_tB(void);
howl_types_KTerm howl_ksc_ex_tC(void);
howl_types_KTerm howl_ksc_ex_na(void);
howl_ksc_Concl howl_ksc_ksc_1(slop_rdf_rdf_IRI a);
howl_ksc_Concl howl_ksc_ksc_q(howl_types_KName q);
howl_ksc_Concl howl_ksc_ksc_2(howl_types_KElem x, howl_types_RoleId v, howl_types_KElem x1);
howl_ksc_Concl howl_ksc_ksc_3(howl_types_KElem x, howl_types_KTerm y);
uint8_t howl_ksc_ksc_4(howl_types_KElem u, howl_types_KTerm z);
howl_ksc_Concl howl_ksc_ksc_5(howl_types_KTerm sy, howl_types_KTerm sz, howl_types_KElem x, howl_types_KTerm y);
howl_ksc_Concl howl_ksc_ksc_6(howl_types_KName a, howl_types_KName b, howl_types_KName z, howl_types_KElem x, howl_types_KTerm y1, howl_types_KElem x2, howl_types_KTerm y2);
howl_ksc_Concl howl_ksc_ksc_7(howl_types_RoleId v, howl_types_KName a, howl_types_KName z, howl_types_KElem x, howl_types_RoleId v1, howl_types_KElem x1, howl_types_KElem x2, howl_types_KTerm y);
howl_ksc_Concl howl_ksc_ksc_8(howl_types_RoleId v, howl_types_KName a, howl_types_KName z, howl_types_KElem x, howl_types_RoleId v1, howl_types_KElem x2, howl_types_KTerm y);
howl_ksc_Concl howl_ksc_ksc_9(howl_types_KName a, howl_types_RoleId v, howl_types_KName b, int64_t w, howl_types_KElem x, howl_types_KTerm y);
howl_ksc_Concl howl_ksc_ksc_9_assert(slop_rdf_rdf_IRI a, howl_types_RoleId v, slop_rdf_rdf_IRI b, howl_types_KElem x, howl_types_KTerm y);
howl_ksc_Concl howl_ksc_ksc_10(howl_types_KName a, howl_types_RoleId v, howl_types_KName b, int64_t w, howl_types_KElem x, howl_types_KTerm y);
howl_ksc_Concl howl_ksc_ksc_10_assert(slop_rdf_rdf_IRI a, howl_types_RoleId v, slop_rdf_rdf_IRI b, howl_types_KElem x, howl_types_KTerm y);
howl_ksc_Concl howl_ksc_ksc_11(howl_types_RoleId v, howl_types_KName z, howl_types_KElem x, howl_types_RoleId v1);
howl_ksc_Concl howl_ksc_ksc_12(howl_types_KName a, howl_types_RoleId v, howl_types_KElem x, howl_types_KTerm y);
howl_ksc_Concl howl_ksc_ksc_13(howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId v1, howl_types_KElem x1);
howl_ksc_Concl howl_ksc_ksc_14(howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId v1);
howl_ksc_Concl howl_ksc_ksc_15(howl_types_RoleId u, howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId u1, howl_types_KElem x1, howl_types_KElem x2, howl_types_RoleId v1, howl_types_KElem x3);
howl_ksc_Concl howl_ksc_ksc_16(howl_types_RoleId u, howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId u1, howl_types_KElem x2, howl_types_RoleId v1, howl_types_KElem x3);
howl_ksc_Concl howl_ksc_ksc_17(howl_types_RoleId u, howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId u1, howl_types_KElem x1, howl_types_KElem x2, howl_types_RoleId v1);
howl_ksc_Concl howl_ksc_ksc_18(howl_types_RoleId u, howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId u1, howl_types_KElem x2, howl_types_RoleId v1);
howl_ksc_Concl howl_ksc_ksc_23(howl_types_RoleId v, howl_types_KName d, howl_types_KElem x, howl_types_RoleId v1, howl_types_KElem x1);
howl_ksc_Concl howl_ksc_ksc_24(howl_types_RoleId v, howl_types_KName d, howl_types_KElem x, howl_types_RoleId v1);
howl_ksc_Concl howl_ksc_ksc_25(howl_types_RoleId v, howl_types_KName d, howl_types_KElem x, howl_types_RoleId v1, howl_types_KElem x1);
howl_ksc_Concl howl_ksc_ksc_26(howl_types_RoleId v, howl_types_KName d, howl_types_KElem x, howl_types_RoleId v1);
howl_ksc_Concl howl_ksc_ksc_27(howl_types_KElem x, howl_types_KTerm y, howl_types_KElem x2, howl_types_KTerm z);
howl_ksc_Concl howl_ksc_ksc_28(howl_types_KElem x, howl_types_KTerm y, howl_types_KElem x2, howl_types_KTerm z);
howl_ksc_Concl howl_ksc_ksc_29(howl_types_KElem x, howl_types_KTerm y, howl_types_KElem z, howl_types_RoleId u, howl_types_KElem x2);
howl_ksc_Concl howl_ksc_join_trigger_fails(howl_types_KFact t);
howl_ksc_Concl howl_ksc_join_instance(howl_ksc_JoinRule tag, howl_types_KFact t, howl_types_KFact p, howl_types_KscAxiom ax);
slop_option_howl_types_KFact howl_ksc_join_conclusion(howl_ksc_JoinRule tag, howl_types_KFact t, howl_types_KFact p, howl_types_KscAxiom ax);
slop_list_howl_types_KFact howl_ksc_ksc_join(slop_arena* arena, howl_ksc_JoinRule tag, howl_types_KFact t, slop_list_howl_types_KFact ps, howl_types_KscAxiom ax);
uint8_t howl_ksc_ref_add(slop_arena* arena, slop_map* seen, howl_ksc_Concl c);
slop_list_howl_types_KName howl_ksc_ref_names(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes);
slop_list_howl_types_KName howl_ksc_axiom_names(slop_arena* arena, howl_types_KscAxiom ax);
slop_list_slop_rdf_rdf_IRI howl_ksc_ref_individuals(slop_arena* arena, slop_list_howl_types_KscAxiom axioms);
slop_list_howl_ksc_Concl howl_ksc_ref_unary(slop_arena* arena, howl_types_KFact f, howl_types_KscAxiom ax);
slop_list_howl_ksc_Concl howl_ksc_ref_binary(slop_arena* arena, howl_types_KFact f1, howl_types_KFact f2, howl_types_KscAxiom ax);
slop_list_howl_ksc_Concl howl_ksc_ref_equality(slop_arena* arena, howl_types_KFact f1, howl_types_KFact f2);
slop_list_howl_types_KFact howl_ksc_reference_closure(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_option_howl_types_KName q, slop_list_howl_types_KName classes);
uint8_t howl_ksc_reference_answer(slop_list_howl_types_KFact facts, howl_types_KName q, howl_types_KName b);

#ifndef SLOP_OPTION_HOWL_KSC_CONCL_DEFINED
#define SLOP_OPTION_HOWL_KSC_CONCL_DEFINED
SLOP_OPTION_DEFINE(howl_ksc_Concl, slop_option_howl_ksc_Concl)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KFACT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(howl_types_KFact, slop_option_howl_types_KFact)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscAxiom, slop_option_howl_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_KName, slop_option_howl_types_KName)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif


#endif
