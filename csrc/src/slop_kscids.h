#ifndef SLOP_kscids_H
#define SLOP_kscids_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"

typedef struct kscids_KscIds kscids_KscIds;
typedef struct kscids_CFact kscids_CFact;

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_LIST_TYPES_KELEM_DEFINED
#define SLOP_LIST_TYPES_KELEM_DEFINED
#define SLOP_LIST_TYPES_KELEM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KElem, slop_list_types_KElem)
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

#ifndef SLOP_LIST_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_TYPES_KSCAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KscAxiom, slop_list_types_KscAxiom)
#endif

#ifndef SLOP_LIST_TYPES_KNAME_DEFINED
#define SLOP_LIST_TYPES_KNAME_DEFINED
#define SLOP_LIST_TYPES_KNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KName, slop_list_types_KName)
#endif

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_KELEM_DEFINED
#define SLOP_OPTION_TYPES_KELEM_DEFINED
SLOP_OPTION_DEFINE(types_KElem, slop_option_types_KElem)
#endif

#ifndef SLOP_OPTION_TYPES_KTERM_DEFINED
#define SLOP_OPTION_TYPES_KTERM_DEFINED
SLOP_OPTION_DEFINE(types_KTerm, slop_option_types_KTerm)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_KNAME_DEFINED
#define SLOP_OPTION_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(types_KName, slop_option_types_KName)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

struct kscids_KscIds {
    slop_map* elems;
    slop_list_types_KElem elem_of;
    slop_map* terms;
    slop_list_types_KTerm term_of;
    slop_map* roles;
    slop_list_types_RoleId role_of;
};
typedef struct kscids_KscIds kscids_KscIds;

#ifndef SLOP_OPTION_KSCIDS_KSCIDS_DEFINED
#define SLOP_OPTION_KSCIDS_KSCIDS_DEFINED
SLOP_OPTION_DEFINE(kscids_KscIds, slop_option_kscids_KscIds)
#endif

struct kscids_CFact {
    uint8_t kind;
    uint32_t a;
    uint32_t b;
    uint32_t c;
};
typedef struct kscids_CFact kscids_CFact;

#ifndef SLOP_OPTION_KSCIDS_CFACT_DEFINED
#define SLOP_OPTION_KSCIDS_CFACT_DEFINED
SLOP_OPTION_DEFINE(kscids_CFact, slop_option_kscids_CFact)
#endif


/* Hash/eq functions and list types for struct map/set keys */
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

uint8_t kscids_inst_kind(void);
uint8_t kscids_triple_kind(void);
uint8_t kscids_self_kind(void);
int64_t kscids_max_n(int64_t k, int64_t tag);
uint8_t kscids_is_thing(rdf_IRI i);
uint8_t kscids_is_nothing(rdf_IRI i);
uint8_t kscids_elem_in_table(types_KElem e);
uint8_t kscids_term_in_table(types_KTerm t);
uint8_t kscids_role_in_table(types_RoleId r);
kscids_KscIds kscids_with_elem(slop_arena* arena, kscids_KscIds ids, types_KElem e);
kscids_KscIds kscids_with_term(slop_arena* arena, kscids_KscIds ids, types_KTerm t);
kscids_KscIds kscids_with_role(slop_arena* arena, kscids_KscIds ids, types_RoleId r);
kscids_KscIds kscids_with_name(slop_arena* arena, kscids_KscIds ids, types_KName n);
kscids_KscIds kscids_with_kterm(slop_arena* arena, kscids_KscIds ids, types_KTerm t);
kscids_KscIds kscids_build_ksc_ids(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, slop_list_rdf_IRI individuals);
uint8_t kscids_outside(slop_string what);
uint32_t kscids_arith(int64_t n, int64_t k, int64_t tag);
uint32_t kscids_table_id(slop_option_u32 found, int64_t k, int64_t tag, slop_string what);
uint32_t kscids_elem_id(kscids_KscIds ids, types_KElem e);
uint32_t kscids_term_id(kscids_KscIds ids, types_KTerm t);
uint32_t kscids_role_id(kscids_KscIds ids, types_RoleId r);
types_KElem kscids_id_elem(kscids_KscIds ids, uint32_t i);
types_KTerm kscids_id_term(kscids_KscIds ids, uint32_t i);
types_RoleId kscids_id_role(kscids_KscIds ids, uint32_t i);
kscids_CFact kscids_encode_fact(kscids_KscIds ids, types_KFact f);
types_KFact kscids_decode_fact(kscids_KscIds ids, kscids_CFact c);

#ifndef SLOP_OPTION_TYPES_KELEM_DEFINED
#define SLOP_OPTION_TYPES_KELEM_DEFINED
SLOP_OPTION_DEFINE(types_KElem, slop_option_types_KElem)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_TYPES_KTERM_DEFINED
#define SLOP_OPTION_TYPES_KTERM_DEFINED
SLOP_OPTION_DEFINE(types_KTerm, slop_option_types_KTerm)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_KSCIDS_KSCIDS_DEFINED
#define SLOP_OPTION_KSCIDS_KSCIDS_DEFINED
SLOP_OPTION_DEFINE(kscids_KscIds, slop_option_kscids_KscIds)
#endif

#ifndef SLOP_OPTION_KSCIDS_CFACT_DEFINED
#define SLOP_OPTION_KSCIDS_CFACT_DEFINED
SLOP_OPTION_DEFINE(kscids_CFact, slop_option_kscids_CFact)
#endif

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_KNAME_DEFINED
#define SLOP_OPTION_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(types_KName, slop_option_types_KName)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif


#endif
