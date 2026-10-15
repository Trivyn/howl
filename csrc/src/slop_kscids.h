#ifndef SLOP_kscids_H
#define SLOP_kscids_H

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

typedef struct howl_kscids_KscIds howl_kscids_KscIds;
typedef struct howl_kscids_CFact howl_kscids_CFact;

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_KELEM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KELEM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KELEM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KElem, slop_list_howl_types_KElem)
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

#ifndef SLOP_OPTION_HOWL_TYPES_KELEM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KELEM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KElem, slop_option_howl_types_KElem)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KTERM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KTERM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KTerm, slop_option_howl_types_KTerm)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
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

struct howl_kscids_KscIds {
    slop_map* elems;
    slop_list_howl_types_KElem elem_of;
    slop_map* terms;
    slop_list_howl_types_KTerm term_of;
    slop_map* roles;
    slop_list_howl_types_RoleId role_of;
};
typedef struct howl_kscids_KscIds howl_kscids_KscIds;

#ifndef SLOP_OPTION_HOWL_KSCIDS_KSCIDS_DEFINED
#define SLOP_OPTION_HOWL_KSCIDS_KSCIDS_DEFINED
SLOP_OPTION_DEFINE(howl_kscids_KscIds, slop_option_howl_kscids_KscIds)
#endif

struct howl_kscids_CFact {
    uint8_t kind;
    uint32_t a;
    uint32_t b;
    uint32_t c;
};
typedef struct howl_kscids_CFact howl_kscids_CFact;

#ifndef SLOP_OPTION_HOWL_KSCIDS_CFACT_DEFINED
#define SLOP_OPTION_HOWL_KSCIDS_CFACT_DEFINED
SLOP_OPTION_DEFINE(howl_kscids_CFact, slop_option_howl_kscids_CFact)
#endif


/* Hash/eq functions and list types for struct map/set keys */
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

uint8_t howl_kscids_inst_kind(void);
uint8_t howl_kscids_triple_kind(void);
uint8_t howl_kscids_self_kind(void);
int64_t howl_kscids_max_n(int64_t k, int64_t tag);
uint8_t howl_kscids_is_thing(slop_rdf_rdf_IRI i);
uint8_t howl_kscids_is_nothing(slop_rdf_rdf_IRI i);
uint8_t howl_kscids_elem_in_table(howl_types_KElem e);
uint8_t howl_kscids_term_in_table(howl_types_KTerm t);
uint8_t howl_kscids_role_in_table(howl_types_RoleId r);
howl_kscids_KscIds howl_kscids_with_elem(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KElem e);
howl_kscids_KscIds howl_kscids_with_term(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KTerm t);
howl_kscids_KscIds howl_kscids_with_role(slop_arena* arena, howl_kscids_KscIds ids, howl_types_RoleId r);
howl_kscids_KscIds howl_kscids_with_name(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KName n);
howl_kscids_KscIds howl_kscids_with_kterm(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KTerm t);
howl_kscids_KscIds howl_kscids_build_ksc_ids(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes, slop_list_slop_rdf_rdf_IRI individuals);
uint8_t howl_kscids_outside(slop_string what);
uint32_t howl_kscids_arith(int64_t n, int64_t k, int64_t tag);
uint32_t howl_kscids_table_id(slop_option_u32 found, int64_t k, int64_t tag, slop_string what);
uint32_t howl_kscids_elem_id(howl_kscids_KscIds ids, howl_types_KElem e);
uint32_t howl_kscids_term_id(howl_kscids_KscIds ids, howl_types_KTerm t);
uint32_t howl_kscids_role_id(howl_kscids_KscIds ids, howl_types_RoleId r);
howl_types_KElem howl_kscids_id_elem(howl_kscids_KscIds ids, uint32_t i);
howl_types_KTerm howl_kscids_id_term(howl_kscids_KscIds ids, uint32_t i);
howl_types_RoleId howl_kscids_id_role(howl_kscids_KscIds ids, uint32_t i);
howl_kscids_CFact howl_kscids_encode_fact(howl_kscids_KscIds ids, howl_types_KFact f);
howl_types_KFact howl_kscids_decode_fact(howl_kscids_KscIds ids, howl_kscids_CFact c);

#ifndef SLOP_OPTION_HOWL_TYPES_KELEM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KELEM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KElem, slop_option_howl_types_KElem)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KTERM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KTERM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KTerm, slop_option_howl_types_KTerm)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_KSCIDS_KSCIDS_DEFINED
#define SLOP_OPTION_HOWL_KSCIDS_KSCIDS_DEFINED
SLOP_OPTION_DEFINE(howl_kscids_KscIds, slop_option_howl_kscids_KscIds)
#endif

#ifndef SLOP_OPTION_HOWL_KSCIDS_CFACT_DEFINED
#define SLOP_OPTION_HOWL_KSCIDS_CFACT_DEFINED
SLOP_OPTION_DEFINE(howl_kscids_CFact, slop_option_howl_kscids_CFact)
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
