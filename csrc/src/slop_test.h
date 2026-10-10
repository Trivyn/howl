#ifndef SLOP_test_H
#define SLOP_test_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_termstore.h"
#include "slop_vocab.h"
#include "slop_decode.h"
#include "slop_gate.h"
#include "slop_normalize.h"
#include "slop_owl2.h"
#include "slop_ttl.h"
#include "slop_sroiq.h"
#include "slop_sriqnormal.h"
#include "slop_sriqelim.h"
#include "slop_sriqnames.h"
#include "slop_sroiqfss.h"
#include "slop_file.h"
#include "slop_types.h"
#include "slop_canon.h"
#include "slop_saturate.h"
#include "slop_classify.h"
#include "slop_howl.h"
#include "slop_el.h"
#include "slop_premise.h"
#include "slop_report.h"
#include "slop_strlib.h"
#include "slop_select.h"
#include "slop_kscnormal.h"
#include "slop_kscsat.h"
#include "slop_ksc.h"
#include "slop_kscids.h"
#include "slop_kscpremise.h"
#include "slop_kscnames.h"
#include <string.h>

typedef struct test_KscFixture test_KscFixture;
typedef struct test_RunAs test_RunAs;

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Node, slop_list_types_Node)
#endif

#ifndef SLOP_LIST_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_TYPES_NORMAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_NormAxiom, slop_list_types_NormAxiom)
#endif

#ifndef SLOP_LIST_RDF_TRIPLE_DEFINED
#define SLOP_LIST_RDF_TRIPLE_DEFINED
#define SLOP_LIST_RDF_TRIPLE_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_Triple, slop_list_rdf_Triple)
#endif

#ifndef SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawAxiom, slop_list_owl2_RawAxiom)
#endif

#ifndef SLOP_LIST_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_TYPES_AXIOMREF_IMPL_DEFINED
SLOP_LIST_DEFINE(types_AxiomRef, slop_list_types_AxiomRef)
#endif

#ifndef SLOP_LIST_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_SROIQ_SAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(sroiq_SAxiom, slop_list_sroiq_SAxiom)
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

#ifndef SLOP_LIST_TYPES_KFACT_DEFINED
#define SLOP_LIST_TYPES_KFACT_DEFINED
#define SLOP_LIST_TYPES_KFACT_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KFact, slop_list_types_KFact)
#endif

#ifndef SLOP_LIST_TYPES_ADDRESSED_DEFINED
#define SLOP_LIST_TYPES_ADDRESSED_DEFINED
#define SLOP_LIST_TYPES_ADDRESSED_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Addressed, slop_list_types_Addressed)
#endif

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Omission, slop_list_types_Omission)
#endif

#ifndef SLOP_OPTION_TYPES_OUTCOME_DEFINED
#define SLOP_OPTION_TYPES_OUTCOME_DEFINED
SLOP_OPTION_DEFINE(types_Outcome, slop_option_types_Outcome)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_DECODE_STAGE1_DEFINED
#define SLOP_OPTION_DECODE_STAGE1_DEFINED
SLOP_OPTION_DEFINE(decode_Stage1, slop_option_decode_Stage1)
#endif

#ifndef SLOP_OPTION_TYPES_AXIOMREF_DEFINED
#define SLOP_OPTION_TYPES_AXIOMREF_DEFINED
SLOP_OPTION_DEFINE(types_AxiomRef, slop_option_types_AxiomRef)
#endif

#ifndef SLOP_OPTION_GATE_GATERESULT_DEFINED
#define SLOP_OPTION_GATE_GATERESULT_DEFINED
SLOP_OPTION_DEFINE(gate_GateResult, slop_option_gate_GateResult)
#endif

#ifndef SLOP_OPTION_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(sroiq_SAxiom, slop_option_sroiq_SAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_KNAME_DEFINED
#define SLOP_OPTION_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(types_KName, slop_option_types_KName)
#endif

#ifndef SLOP_OPTION_TYPES_KFACT_DEFINED
#define SLOP_OPTION_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(types_KFact, slop_option_types_KFact)
#endif

#ifndef SLOP_OPTION_NORMALIZE_NORMOUTPUT_DEFINED
#define SLOP_OPTION_NORMALIZE_NORMOUTPUT_DEFINED
SLOP_OPTION_DEFINE(normalize_NormOutput, slop_option_normalize_NormOutput)
#endif

#ifndef SLOP_OPTION_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(types_Addressed, slop_option_types_Addressed)
#endif

#ifndef SLOP_OPTION_OWL2_SIGNATURE_DEFINED
#define SLOP_OPTION_OWL2_SIGNATURE_DEFINED
SLOP_OPTION_DEFINE(owl2_Signature, slop_option_owl2_Signature)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

struct test_KscFixture {
    slop_list_types_KscAxiom axioms;
    slop_list_types_KName classes;
};
typedef struct test_KscFixture test_KscFixture;

#ifndef SLOP_OPTION_TEST_KSCFIXTURE_DEFINED
#define SLOP_OPTION_TEST_KSCFIXTURE_DEFINED
SLOP_OPTION_DEFINE(test_KscFixture, slop_option_test_KscFixture)
#endif

typedef enum {
    test_RunAs_ran,
    test_RunAs_refused,
    test_RunAs_failed
} test_RunAs_tag;

struct test_RunAs {
    test_RunAs_tag tag;
    union {
        types_Profile ran;
        types_Profile refused;
    } data;
};
typedef struct test_RunAs test_RunAs;

#ifndef SLOP_OPTION_TEST_RUNAS_DEFINED
#define SLOP_OPTION_TEST_RUNAS_DEFINED
SLOP_OPTION_DEFINE(test_RunAs, slop_option_test_RunAs)
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

#ifndef TYPES_KFACT_HASH_EQ_DEFINED
#define TYPES_KFACT_HASH_EQ_DEFINED
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
        case types_RoleId_inverse_role:
            return slop_hash_rdf_IRI(&_k->data.inverse_role);
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
        case types_RoleId_inverse_role:
            return slop_eq_rdf_IRI(&_a->data.inverse_role, &_b->data.inverse_role);
    }
    return false;
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
        case types_RoleId_inverse_role:
            return slop_hash_rdf_IRI(&_k->data.inverse_role);
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
        case types_RoleId_inverse_role:
            return slop_eq_rdf_IRI(&_a->data.inverse_role, &_b->data.inverse_role);
    }
    return false;
}
#endif
static inline uint64_t slop_hash_types_KFact(const void* key) {
    const types_KFact* _k = (const types_KFact*)key;
    switch (_k->tag) {
        case types_KFact_f_inst:
            {
                uint64_t hash = 14695981039346656037ULL;
                hash ^= slop_hash_types_KElem(&_k->data.f_inst.f0); hash *= 1099511628211ULL;
                hash ^= slop_hash_types_KTerm(&_k->data.f_inst.f1); hash *= 1099511628211ULL;
                return hash;
            }
        case types_KFact_f_triple:
            {
                uint64_t hash = 14695981039346656037ULL;
                hash ^= slop_hash_types_KElem(&_k->data.f_triple.f0); hash *= 1099511628211ULL;
                hash ^= slop_hash_types_RoleId(&_k->data.f_triple.f1); hash *= 1099511628211ULL;
                hash ^= slop_hash_types_KElem(&_k->data.f_triple.f2); hash *= 1099511628211ULL;
                return hash;
            }
        case types_KFact_f_self:
            {
                uint64_t hash = 14695981039346656037ULL;
                hash ^= slop_hash_types_KElem(&_k->data.f_self.f0); hash *= 1099511628211ULL;
                hash ^= slop_hash_types_RoleId(&_k->data.f_self.f1); hash *= 1099511628211ULL;
                return hash;
            }
    }
    return 0;
}
static inline bool slop_eq_types_KFact(const void* a, const void* b) {
    const types_KFact* _a = (const types_KFact*)a;
    const types_KFact* _b = (const types_KFact*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case types_KFact_f_inst:
            return true
                && slop_eq_types_KElem(&_a->data.f_inst.f0, &_b->data.f_inst.f0)
                && slop_eq_types_KTerm(&_a->data.f_inst.f1, &_b->data.f_inst.f1)
            ;
        case types_KFact_f_triple:
            return true
                && slop_eq_types_KElem(&_a->data.f_triple.f0, &_b->data.f_triple.f0)
                && slop_eq_types_RoleId(&_a->data.f_triple.f1, &_b->data.f_triple.f1)
                && slop_eq_types_KElem(&_a->data.f_triple.f2, &_b->data.f_triple.f2)
            ;
        case types_KFact_f_self:
            return true
                && slop_eq_types_KElem(&_a->data.f_self.f0, &_b->data.f_self.f0)
                && slop_eq_types_RoleId(&_a->data.f_self.f1, &_b->data.f_self.f1)
            ;
    }
    return false;
}
#endif

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
#ifndef SLOP_LIST_KSCIDS_CFACT_DEFINED
#define SLOP_LIST_KSCIDS_CFACT_DEFINED
#define SLOP_LIST_KSCIDS_CFACT_IMPL_DEFINED
SLOP_LIST_DEFINE(kscids_CFact, slop_list_kscids_CFact)
#endif
#endif

#ifndef SLOP_RESULT_SATURATE_ROUNDRESULT_TYPES_FAULT_DEFINED
#define SLOP_RESULT_SATURATE_ROUNDRESULT_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { saturate_RoundResult ok; types_Fault err; } data; } slop_result_saturate_RoundResult_types_Fault;
#endif

#ifndef SLOP_RESULT_DECODE_STAGE1_TYPES_FAULT_DEFINED
#define SLOP_RESULT_DECODE_STAGE1_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { decode_Stage1 ok; types_Fault err; } data; } slop_result_decode_Stage1_types_Fault;
#endif

#ifndef SLOP_RESULT_SRIQNORMAL_S2_STRING_DEFINED
#define SLOP_RESULT_SRIQNORMAL_S2_STRING_DEFINED
typedef struct { bool is_ok; union { sriqnormal_S2 ok; slop_string err; } data; } slop_result_sriqnormal_S2_string;
#endif

#ifndef SLOP_RESULT_SRIQELIM_S1_STRING_DEFINED
#define SLOP_RESULT_SRIQELIM_S1_STRING_DEFINED
typedef struct { bool is_ok; union { sriqelim_S1 ok; slop_string err; } data; } slop_result_sriqelim_S1_string;
#endif

#ifndef SLOP_RESULT_SRIQNORMAL_S0_STRING_DEFINED
#define SLOP_RESULT_SRIQNORMAL_S0_STRING_DEFINED
typedef struct { bool is_ok; union { sriqnormal_S0 ok; slop_string err; } data; } slop_result_sriqnormal_S0_string;
#endif

#ifndef SLOP_RESULT_SRIQNAMES_SRIQNORMAL_STRING_DEFINED
#define SLOP_RESULT_SRIQNAMES_SRIQNORMAL_STRING_DEFINED
typedef struct { bool is_ok; union { sriqnames_SriqNormal ok; slop_string err; } data; } slop_result_sriqnames_SriqNormal_string;
#endif

types_Saturation test_empty_saturation(slop_arena* arena);
types_Saturation test_outcome_saturation(slop_arena* arena, types_Outcome o);
howl_ElWork test_prepared_el_work(slop_arena* arena, howl_Prepared p);
types_Findings test_make_findings(slop_arena* arena, uint8_t inconsistent, int64_t unsat_count);
types_Outcome test_make_outcome(slop_arena* arena, uint8_t inconsistent, int64_t unsat_count, int64_t omitted_count, uint8_t reached_fixpoint);
uint8_t test_verdict_eq(types_Verdict a, types_Verdict b);
uint8_t test_test_coherent_requires_complete(slop_arena* arena);
uint8_t test_test_omission_blocks_coherent(slop_arena* arena);
uint8_t test_test_cap_blocks_coherent(slop_arena* arena);
uint8_t test_test_finding_beats_partial_coverage(slop_arena* arena);
uint8_t test_test_consistent_but_incoherent(slop_arena* arena);
uint8_t test_test_context_starts_with_empty_store(slop_arena* arena);
slop_string test_node_iri(types_Node n);
uint8_t test_test_emit_edge_addresses_both_halves(slop_arena* arena);
slop_option_types_Outcome test_classify_fixture(slop_arena* arena, slop_string path);
slop_option_types_Outcome test_classify_fixture_with(slop_arena* arena, slop_string path, int64_t workers, int64_t cap);
uint8_t test_workers_agree(slop_arena* arena, slop_string path, int64_t cap);
uint8_t test_test_worker_count_does_not_change_the_report(slop_arena* arena);
types_Context test_edge_context(slop_arena* arena, types_Node n, types_RoleId r, types_Node m, uint8_t succ);
uint8_t test_queue_has(types_Saturation sat, types_Node n, types_Derived d);
uint8_t test_stored_edge(types_Saturation sat, types_Node x, types_RoleId r, types_Node y);
int64_t test_queue_len(types_Saturation sat, types_Node n);
uint8_t test_test_commit_dedups_across_deltas(slop_arena* arena);
uint8_t test_test_names_round_trip(slop_arena* arena);
uint8_t test_same_renamed(types_Names names, types_Node n, types_Node expect);
uint8_t test_test_litmus_end_to_end(slop_arena* arena);
uint8_t test_test_role_hierarchy_carries_edges(slop_arena* arena);
uint8_t test_test_role_closure_deep(slop_arena* arena);
uint8_t test_test_smaller_side_joins(slop_arena* arena);
uint8_t test_test_unattested_import_is_inconclusive(slop_arena* arena);
uint8_t test_test_declared_unused_class_gets_a_context(slop_arena* arena);
uint8_t test_test_abox_disjoint_range_is_incoherent(slop_arena* arena);
int64_t test_omitted_count(types_Outcome o);
uint8_t test_test_undeclared_individual_is_reasoned_over(slop_arena* arena);
uint8_t test_test_anonymous_class_assertion_is_read(slop_arena* arena);
uint8_t test_test_annotation_on_annotation_is_consumed(slop_arena* arena);
uint8_t test_test_logical_triple_on_header_node_is_not_swallowed(slop_arena* arena);
uint8_t test_test_repeated_disjoint_member_is_positional(slop_arena* arena);
uint8_t test_report_entails(types_Findings f, types_Node a, types_Node b);
uint8_t test_probe_agrees_with_report(slop_arena* arena, slop_string path);
uint8_t test_test_entails_sub_agrees_with_report(slop_arena* arena);
types_Node test_cls(slop_string name);
types_RoleId test_rol(slop_string name);
slop_result_saturate_RoundResult_types_Fault test_run_fixture(slop_arena* arena, slop_list_types_Node signature, slop_list_types_NormAxiom axioms);
slop_list_types_Node test_litmus_signature(slop_arena* arena);
slop_list_types_NormAxiom test_litmus_axioms(slop_arena* arena, uint8_t correct_polarity);
uint8_t test_litmus_derives_parent(slop_arena* arena, uint8_t correct_polarity);
uint8_t test_test_litmus(slop_arena* arena);
uint8_t test_test_polarity_guard(slop_arena* arena);
uint8_t test_test_cyclic_hierarchy_terminates(slop_arena* arena);
uint8_t test_test_same_round_co_arrival(slop_arena* arena);
uint8_t test_test_late_subsumer_still_concludes(slop_arena* arena);
slop_result_saturate_RoundResult_types_Fault test_unsat_fixture(slop_arena* arena);
uint8_t test_test_unsatisfiable_class_detected(slop_arena* arena);
uint8_t test_test_bottom_compression(slop_arena* arena);
uint8_t test_test_inconsistency_suppresses_both_lists(slop_arena* arena);
uint8_t test_test_derived_eq_compares_both_payloads(slop_arena* arena);
uint8_t test_test_order_independence(slop_arena* arena);
rdf_IRI test_mk_iri(slop_string v);
uint8_t test_test_string_cmp_is_length_safe(slop_arena* arena);
uint8_t test_test_node_cmp_separates_punned_iris(slop_arena* arena);
uint8_t test_test_sort_orders_and_is_input_determined(slop_arena* arena);
rdf_Term test_ex_iri(slop_arena* arena, slop_string local);
int64_t test_count_subclass_triples(slop_list_rdf_Triple ts, rdf_Term pred);
uint8_t test_test_unattested_import_yields_an_omission(slop_arena* arena);
uint8_t test_test_attested_import_yields_none(slop_arena* arena);
uint8_t test_test_term_store_by_content(slop_arena* arena);
uint8_t test_test_term_store_quoted_and_tagged(slop_arena* arena);
slop_list_rdf_Triple test_stage0_triples(slop_arena* arena, decode_Stage0 s0);
slop_list_string test_decode_rendered(slop_arena* arena, slop_result_decode_Stage1_types_Fault r);
uint8_t test_decode_store_agrees(slop_arena* arena, slop_string path);
uint8_t test_test_decode_store_answers_as_the_full_store(slop_arena* arena);
slop_string test_stage0_fault_of(slop_arena* arena, slop_list_rdf_Triple ts);
uint8_t test_test_stage0_fault_follows_the_document(slop_arena* arena);
uint8_t test_test_stage0_rebuild_checks_the_whole_input(slop_arena* arena);
uint8_t test_test_header_and_reification_are_consumed(slop_arena* arena);
int64_t test_count_out_of_profile(slop_list_owl2_RawAxiom axs);
int64_t test_count_disposition(slop_list_owl2_RawAxiom axs, owl2_Disposition want);
slop_option_decode_Stage1 test_decode_fixture(slop_arena* arena, slop_string path);
int64_t test_nary_disjoint_member_count(slop_list_owl2_RawAxiom axs);
uint8_t test_test_nary_disjointness_keeps_its_members(slop_arena* arena);
int64_t test_out_of_profile_count_of(slop_arena* arena, slop_string path);
uint8_t test_test_v0_corpus_decodes_clean(slop_arena* arena);
uint8_t test_test_out_of_profile_corpus_is_caught(slop_arena* arena);
uint8_t test_test_annotation_heavy_decodes_clean(slop_arena* arena);
uint8_t test_test_litmus_decodes_clean(slop_arena* arena);
uint8_t test_test_missing_class_declaration_is_reported(slop_arena* arena);
slop_string test_cites_lines(slop_arena* arena, slop_list_types_AxiomRef refs);
slop_string test_cited_text(slop_arena* arena, gate_GateResult gr, slop_string iri);
uint8_t test_test_missing_declaration_cites_its_axioms(slop_arena* arena);
uint8_t test_test_undeclared_individual_is_not_reported(slop_arena* arena);
int64_t test_accepted_count_of_ttl(slop_arena* arena, slop_string ttl);
uint8_t test_test_reserved_iri_as_individual_is_out_of_profile(slop_arena* arena);
uint8_t test_test_annotation_property_axioms_are_inert(slop_arena* arena);
uint8_t test_decodes_ok(slop_arena* arena, slop_string ttl);
uint8_t test_test_undeclared_property_is_an_input_error(slop_arena* arena);
uint8_t test_test_unknown_owl_vocabulary_still_decodes(slop_arena* arena);
uint8_t test_test_conflicting_declarations_are_an_input_error(slop_arena* arena);
slop_option_gate_GateResult test_gate_ttl(slop_arena* arena, slop_string ttl);
slop_option_gate_GateResult test_gate_ttl_in(slop_arena* arena, slop_string ttl, types_Profile p);
int64_t test_gate_omissions_of_ttl(slop_arena* arena, slop_string ttl);
slop_string test_gate_accepted_of_ttl(slop_arena* arena, slop_string ttl);
slop_string test_rc_prefix(void);
uint8_t test_test_range_composition_table(slop_arena* arena);
slop_string test_rung_prefix(void);
int64_t test_omissions_under(slop_arena* arena, slop_string ttl, types_Profile p);
int64_t test_accepted_under(slop_arena* arena, slop_string ttl, types_Profile p);
uint8_t test_gate_alike_under(slop_arena* arena, slop_string label, slop_string a, slop_string b, types_Profile p);
uint8_t test_rungs_gate_alike(slop_arena* arena, slop_string label, slop_string ttl_a, slop_string ttl_b);
uint8_t test_rungs_omit(slop_arena* arena, slop_string label, slop_string ttl, int64_t el_want, int64_t elpp_want);
uint8_t test_test_data_lemma(slop_arena* arena);
slop_string test_inv_decls(void);
uint8_t test_test_inverses_decode_whole(slop_arena* arena);
uint8_t test_test_data_constructs_decode_as_data(slop_arena* arena);
uint8_t test_test_concept_order_is_total(slop_arena* arena);
owl2_RawConcept* test_box_test_concept(slop_arena* arena, owl2_RawConcept c);
uint8_t test_rungs3_omit(slop_arena* arena, slop_string label, slop_string ttl, int64_t el_want, int64_t elpp_want, int64_t sriq_want);
slop_string test_s0_prefix(void);
slop_string test_render_saxioms(slop_arena* arena, slop_list_sroiq_SAxiom axs);
slop_string test_s0_of(slop_arena* arena, slop_string ttl, uint8_t through_s1);
uint8_t test_s0_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
uint8_t test_s1_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
uint8_t test_test_sriq_s0_rows(slop_arena* arena);
slop_list_string test_sort_strings(slop_arena* arena, slop_list_string xs);
slop_string test_str_at_t(slop_list_string xs, int64_t i);
slop_string test_refusal_line(slop_arena* arena, slop_string m);
slop_string test_s2_text(slop_arena* arena, slop_result_sriqnormal_S2_string r);
slop_string test_s2_after_s1(slop_arena* arena, slop_result_sriqelim_S1_string r);
slop_string test_s2_after_s0(slop_arena* arena, slop_result_sriqnormal_S0_string r);
slop_string test_s2_of(slop_arena* arena, slop_string ttl);
uint8_t test_s2_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
slop_list_string test_sriq_fixtures(slop_arena* arena);
slop_option_gate_GateResult test_gate_triples_in(slop_arena* arena, slop_list_rdf_Triple ts, types_Profile p);
slop_list_owl2_RawAxiom test_reversed_raw(slop_arena* arena, slop_list_owl2_RawAxiom xs);
slop_list_sroiq_SAxiom test_reversed_saxioms(slop_arena* arena, slop_list_sroiq_SAxiom xs);
slop_result_sriqnames_SriqNormal_string test_s2_to_names(slop_arena* arena, gate_GateResult gr, sriqelim_S1 s1, uint8_t flip);
sriqnormal_S0 test_reversed_s0(slop_arena* arena, sriqnormal_S0 s0);
slop_result_sriqnames_SriqNormal_string test_sriq_nf(slop_arena* arena, gate_GateResult gr, uint8_t flip_accepted, uint8_t flip_s0, uint8_t flip_s2);
slop_list_string test_nf_lines(slop_arena* arena, slop_result_sriqnames_SriqNormal_string r);
uint8_t test_nf_invariants_hold(slop_arena* arena, slop_string path, slop_result_sriqnames_SriqNormal_string r);
uint8_t test_sriq_order_independent(slop_arena* arena, slop_string path);
uint8_t test_test_sriq_ids_row(slop_arena* arena);
uint8_t test_test_sriq_one_clause_from_two_axioms(slop_arena* arena);
uint8_t test_test_sriq_ids_from_content(slop_arena* arena);
uint8_t test_yields_nothing_by_design(owl2_RawAxiom a);
slop_list_owl2_RawAxiom test_one_raw(slop_arena* arena, owl2_RawAxiom a);
uint8_t test_print_alone(slop_arena* arena, owl2_RawAxiom a);
uint8_t test_is_chain_axiom(owl2_RawAxiom a);
int64_t test_yield_kind(slop_arena* arena, owl2_RawAxiom a, owl2_Signature sig);
uint8_t test_every_axiom_yields(slop_arena* arena, slop_string path);
uint8_t test_test_sriq_every_axiom_yields(slop_arena* arena);
slop_string test_s1_text(slop_arena* arena, sriqelim_S1 s1);
slop_string test_s1_bounded_of(slop_arena* arena, slop_string ttl, int64_t bound);
uint8_t test_s1_bounded_is(slop_arena* arena, slop_string label, slop_string ttl, int64_t bound, slop_string want);
uint8_t test_test_sriq_guard_witnesses(slop_arena* arena);
uint8_t test_test_sriq_s1_rows(slop_arena* arena);
uint8_t test_s1_invariants_hold(slop_arena* arena, slop_string path);
uint8_t test_print_problems(slop_string path, slop_list_string bad);
uint8_t test_test_sriq_s1_invariants(slop_arena* arena);
uint8_t test_test_sriq_s2_refuses_a_count_past_the_bound(slop_arena* arena);
uint8_t test_test_sriq_s2_rows(slop_arena* arena);
uint8_t test_test_sriq_gate_table(slop_arena* arena);
uint8_t test_test_el_plus_plus_gate_table(slop_arena* arena);
uint8_t test_test_top_role_tautology_is_dropped(slop_arena* arena);
slop_string test_ksc_form_of_ttl(slop_arena* arena, slop_string ttl);
uint8_t test_ksc_form_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
slop_option_test_KscFixture test_ksc_fixture(slop_arena* arena, slop_string path);
slop_string test_kname_label(slop_arena* arena, types_KName n);
uint8_t test_ksc_engine_matches_reference(slop_arena* arena, slop_string label, slop_string ttl);
int64_t test_ksc_holds(slop_arena* arena, slop_string ttl, slop_string a, slop_string b);
int64_t test_ksc_inconsistent(slop_arena* arena, slop_string ttl);
int64_t test_ksc_fixture_count(void);
slop_string test_ksc_fixture_at(int64_t i);
uint8_t test_test_ksc_engine_matches_reference(slop_arena* arena);
uint8_t test_test_ksc_entailments(slop_arena* arena);
slop_option_types_Outcome test_classify_fixture_in(slop_arena* arena, slop_string path, types_Profile profile);
slop_list_string test_rung_neutral_lines(slop_arena* arena, types_Outcome o);
uint8_t test_rungs_agree_on(slop_arena* arena, slop_string path);
uint8_t test_test_el_and_el_plus_plus_agree(slop_arena* arena);
types_KscResult test_ksc_run(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, types_ReasonerConfig config);
int64_t test_cancel_flag_set(void);
uint8_t test_test_ksc_cancelled(slop_arena* arena);
uint8_t test_cancelled_under(slop_arena* arena, types_ReasonerConfig base_cfg);
uint8_t test_ids_round_trip(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes);
uint8_t test_test_ksc_ids_round_trip(slop_arena* arena);
uint8_t test_holds_under(kscpremise_KscIndex idx, slop_list_types_KFact fs, types_KElem x, types_RoleId v, types_KElem y);
uint8_t test_g_matches_reference(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes);
uint8_t test_test_ksc_g_matches_reference(slop_arena* arena);
uint8_t test_commit_agrees(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, uint8_t stop, uint8_t with_classes);
uint8_t test_test_ksc_commit_identical(slop_arena* arena);
types_ReasonerConfig test_ksc_config(int64_t workers, int64_t cap);
uint8_t test_answers_equal(types_KscResult a, types_KscResult b);
uint8_t test_test_ksc_workers_agree(slop_arena* arena);
uint8_t test_same_run(types_KscResult a, types_KscResult b);
slop_list_int test_workers_under_test(slop_arena* arena);
uint8_t test_test_ksc_seed_unsat_counts_no_round(slop_arena* arena);
int64_t test_nothing_run_rounds(types_KscResult r);
int64_t test_max_run_rounds(types_KscResult r);
uint8_t test_test_ksc_cap(slop_arena* arena);
uint8_t test_test_ksc_normal_form_rows(slop_arena* arena);
slop_string test_omissions_of_ttl(slop_arena* arena, slop_string ttl);
uint8_t test_omits_exactly(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
slop_string test_eq_prefix(void);
uint8_t test_test_equality_never_drops_an_operand(slop_arena* arena);
uint8_t test_test_anonymous_members_are_omissions_not_faults(slop_arena* arena);
uint8_t test_test_negative_assertion_decodes_whole(slop_arena* arena);
uint8_t test_test_literal_has_value_is_data(slop_arena* arena);
slop_string test_neg_prefix(void);
uint8_t test_accepts_exactly(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
uint8_t test_test_negation_rewrites_to_bottom_gcis(slop_arena* arena);
uint8_t test_test_negation_rewrites_whole_axioms_or_none(slop_arena* arena);
uint8_t test_test_negative_range_normalizes_to_bottom(slop_arena* arena);
uint8_t test_norm_eq(types_NormAxiom a, types_NormAxiom b);
uint8_t test_norm_contains(slop_list_types_NormAxiom xs, types_NormAxiom a);
slop_option_normalize_NormOutput test_normalize_fixture(slop_arena* arena, slop_string path);
uint8_t test_test_litmus_reproduces_the_m1_normal_form(slop_arena* arena);
uint8_t test_test_normalization_polarity_is_negative_on_the_left(slop_arena* arena);
uint8_t test_test_range_elimination_introduces_a_shared_filler(slop_arena* arena);
uint8_t test_test_asserted_edges_seed_their_range(slop_arena* arena);
uint8_t test_test_range_complex_fillers_stay_apart(slop_arena* arena);
uint8_t test_complex_range_fillers_distinct(slop_arena* arena, slop_string path);
uint8_t test_test_inverse_expressions_are_omissions(slop_arena* arena);
slop_list_string test_m0_fixture_paths(slop_arena* arena);
uint8_t test_accounting_exempt(owl2_RawAxiom ax);
uint8_t test_axiom_accounted(slop_arena* arena, owl2_RawAxiom ax);
uint8_t test_test_accounting_holds(slop_arena* arena);
uint8_t test_same_rendering(slop_arena* arena, slop_list_owl2_RawAxiom xs, slop_list_owl2_RawAxiom ys);
uint8_t test_test_canonicalization_is_idempotent(slop_arena* arena);
slop_list_types_Node test_norm_nodes(slop_arena* arena, types_NormAxiom ax);
uint8_t test_fresh_ids_dense(slop_arena* arena, normalize_NormOutput no);
uint8_t test_test_fresh_nodes_are_fresh(slop_arena* arena);
slop_list_rdf_Triple test_reversed_triples(slop_arena* arena, slop_list_rdf_Triple ts);
slop_option_normalize_NormOutput test_normalize_triples(slop_arena* arena, slop_list_rdf_Triple ts);
uint8_t test_same_normal_form(normalize_NormOutput a, normalize_NormOutput b);
uint8_t test_same_report(types_Outcome a, types_Outcome b);
uint8_t test_same_lines(slop_list_string a, slop_list_string b);
uint8_t test_encoded_agrees(slop_arena* arena, slop_string path, types_ProfileSelection selection);
uint8_t test_test_classify_encoded_is_classify(slop_arena* arena);
slop_option_string test_file_text(slop_arena* arena, slop_string path);
slop_list_string test_api_lines(slop_arena* arena, howl_Run r);
uint8_t test_api_agrees(slop_arena* arena, slop_string path, types_Profile profile);
howl_FaultKind test_api_fault(howl_Options o);
uint8_t test_test_public_api(slop_arena* arena);
uint8_t test_order_independent(slop_arena* arena, slop_string path);
uint8_t test_test_triple_order_independence(slop_arena* arena);
uint8_t test_addressed_subset(slop_list_types_Addressed xs, slop_list_types_Addressed ys);
uint8_t test_same_conclusions(slop_arena* arena, types_Context ctx, types_Derived d, premise_RuleIndex idx, slop_list_types_NormAxiom axioms);
uint8_t test_dispatch_agrees(slop_arena* arena, slop_string path);
uint8_t test_test_indexed_dispatch_matches_reference(slop_arena* arena);
uint8_t test_test_quoted_triple_header_subjects(slop_arena* arena);
int64_t test_strict_outcome(slop_arena* arena, slop_string path);
test_RunAs test_profile_run(slop_arena* arena, slop_string path, types_ProfileSelection selection);
uint8_t test_ran_as(test_RunAs r, types_Profile want);
uint8_t test_refused_as(test_RunAs r, types_Profile want);
uint8_t test_test_profile_selection(slop_arena* arena);
uint8_t test_test_profile_names_round_trip(slop_arena* arena);
uint8_t test_test_dropped_rung_refusal(slop_arena* arena);
uint8_t test_name_round_trips(types_Profile p);
uint8_t test_test_strict_refuses_past_omissions(slop_arena* arena);
uint8_t test_test_nary_chain_decomposes_left_associated(slop_arena* arena);
slop_option_u8 test_regularity_of(slop_arena* arena, slop_string path);
uint8_t test_test_regularity_rejects_mutual_recursion(slop_arena* arena);
uint8_t test_test_regularity_accepts_equivalence_and_transitivity(slop_arena* arena);
uint8_t test_test_regularity_accepts_plain_subproperty(slop_arena* arena);
uint8_t test_test_regularity_accepts_nary_chain(slop_arena* arena);
uint8_t test_test_irregular_rbox_is_omitted_whole(slop_arena* arena);
slop_option_gate_GateResult test_gate_fixture(slop_arena* arena, slop_string path);
slop_option_gate_GateResult test_gate_fixture_in(slop_arena* arena, slop_string path, types_Profile p);
int64_t test_count_variant_chain(slop_list_owl2_RawAxiom axs);
int64_t test_count_variant_disjoint(slop_list_owl2_RawAxiom axs);
int64_t test_count_variant_subclass(slop_list_owl2_RawAxiom axs);
uint8_t test_test_gate_annotation_heavy_is_clean(slop_arena* arena);
uint8_t test_test_gate_carries_import_omissions(slop_arena* arena);
uint8_t test_test_sugar_transitivity_becomes_a_chain(slop_arena* arena);
uint8_t test_test_sugar_nary_disjointness_becomes_pairs(slop_arena* arena);
uint8_t test_test_sugar_equivalence_is_a_star_not_all_pairs(slop_arena* arena);
int64_t test_gate_omission_count(slop_arena* arena, slop_string path);
uint8_t test_test_gate_accepts_every_v0_fixture(slop_arena* arena);
uint8_t test_test_gate_rejects_every_out_of_profile_fixture(slop_arena* arena);
slop_option_owl2_Signature test_signature_of_fixture(slop_arena* arena, slop_string path);
uint8_t test_test_declared_unused_class_reaches_the_signature(slop_arena* arena);
uint8_t test_test_builtins_are_declared(slop_arena* arena);
uint8_t test_test_custom_annotation_property_is_recognized(slop_arena* arena);
uint8_t test_is_named_class(owl2_RawConcept c, slop_string iri);
uint8_t test_is_some_person(owl2_RawConcept c, slop_string role_iri, slop_string filler_iri);
uint8_t test_test_decode_litmus_class_expression(slop_arena* arena);
uint8_t test_test_decode_represents_out_of_profile_rather_than_failing(slop_arena* arena);
uint8_t test_test_decode_blank_node_cycle_is_bounded(slop_arena* arena);
uint8_t test_test_rdf_list_well_formed(slop_arena* arena);
uint8_t test_test_rdf_list_truncation_is_a_fault(slop_arena* arena);
uint8_t test_test_rdf_list_cycle_terminates(slop_arena* arena);
uint8_t test_test_rdf_list_branching_is_a_fault(slop_arena* arena);
slop_list_rdf_Triple test_rest_forked(slop_arena* arena);
uint8_t test_list_branches(slop_arena* arena, slop_list_rdf_Triple ts, rdf_Term head);
slop_string test_decode_prefix(void);
slop_string test_decoded_text(slop_arena* arena, slop_string ttl);
uint8_t test_decodes_exactly(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
uint8_t test_test_decode_rows(slop_arena* arena);
uint8_t test_test_sort_is_stable(slop_arena* arena);
uint8_t test_test_sort_is_a_permutation(slop_arena* arena);
void test_print_test_result(slop_string name, uint8_t passed);
slop_string test_arg_text(uint8_t** argv, int64_t i);
slop_list_rdf_IRI test_dump_classes(slop_arena* arena, owl2_Signature sig);
int64_t test_print_lines(slop_list_string ls);
int64_t test_dump_refused(slop_string m);
int64_t test_dump_s1(slop_arena* arena, gate_GateResult gr, slop_result_sriqnormal_S0_string r, int64_t bound);
int64_t test_dump_s1_invariants(slop_arena* arena, gate_GateResult gr, int64_t bound);
uint8_t test_s1_guarded(slop_arena* arena, gate_GateResult gr, int64_t bound);
uint8_t test_uses_reserved(slop_arena* arena, owl2_Signature sig);
int64_t test_dump_stage(slop_arena* arena, slop_string stage, gate_GateResult gr, int64_t bound);
int64_t test_sriq_dump(slop_arena* arena, slop_string stage, slop_string path, int64_t bound);
int64_t test_bound_arg(slop_string s);
int64_t test_dump_tagged(slop_string tag, slop_string text);
int64_t test_dump_axiom_list(slop_arena* arena, slop_string tag, slop_list_owl2_RawAxiom axs);
int64_t test_dump_axiom_ref(slop_string tag, types_AxiomRef r);
int64_t test_dump_cited(slop_string tag, types_Omission o);
int64_t test_dump_omission_list(slop_arena* arena, slop_string tag, slop_list_types_Omission os);
int64_t test_dump_fault(slop_arena* arena, types_Fault f);
int64_t test_dump_signature(slop_arena* arena, owl2_Signature sig);
int64_t test_dump_triple(slop_arena* arena, termstore_IdTriple t);
int64_t test_dump_stage0(slop_arena* arena, decode_Stage0 s0);
int64_t test_dump_regularity(slop_arena* arena, slop_list_owl2_RawAxiom axs);
int64_t test_dump_rung(slop_arena* arena, decode_Stage0 s0, decode_Stage1 s1, types_Profile p, slop_string tag);
int64_t test_dump_decoded(slop_arena* arena, decode_Stage0 s0, decode_Stage1 s1);
int64_t test_front_dump(slop_arena* arena, slop_string path);
int main(int argc, char** _c_argv);
int64_t test_run_suite(void);

#ifndef SLOP_OPTION_TYPES_OUTCOME_DEFINED
#define SLOP_OPTION_TYPES_OUTCOME_DEFINED
SLOP_OPTION_DEFINE(types_Outcome, slop_option_types_Outcome)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_DECODE_STAGE1_DEFINED
#define SLOP_OPTION_DECODE_STAGE1_DEFINED
SLOP_OPTION_DEFINE(decode_Stage1, slop_option_decode_Stage1)
#endif

#ifndef SLOP_OPTION_TYPES_AXIOMREF_DEFINED
#define SLOP_OPTION_TYPES_AXIOMREF_DEFINED
SLOP_OPTION_DEFINE(types_AxiomRef, slop_option_types_AxiomRef)
#endif

#ifndef SLOP_OPTION_GATE_GATERESULT_DEFINED
#define SLOP_OPTION_GATE_GATERESULT_DEFINED
SLOP_OPTION_DEFINE(gate_GateResult, slop_option_gate_GateResult)
#endif

#ifndef SLOP_OPTION_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(sroiq_SAxiom, slop_option_sroiq_SAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_KNAME_DEFINED
#define SLOP_OPTION_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(types_KName, slop_option_types_KName)
#endif

#ifndef SLOP_OPTION_TEST_KSCFIXTURE_DEFINED
#define SLOP_OPTION_TEST_KSCFIXTURE_DEFINED
SLOP_OPTION_DEFINE(test_KscFixture, slop_option_test_KscFixture)
#endif

#ifndef SLOP_OPTION_TYPES_KFACT_DEFINED
#define SLOP_OPTION_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(types_KFact, slop_option_types_KFact)
#endif

#ifndef SLOP_OPTION_NORMALIZE_NORMOUTPUT_DEFINED
#define SLOP_OPTION_NORMALIZE_NORMOUTPUT_DEFINED
SLOP_OPTION_DEFINE(normalize_NormOutput, slop_option_normalize_NormOutput)
#endif

#ifndef SLOP_OPTION_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(types_Addressed, slop_option_types_Addressed)
#endif

#ifndef SLOP_OPTION_TEST_RUNAS_DEFINED
#define SLOP_OPTION_TEST_RUNAS_DEFINED
SLOP_OPTION_DEFINE(test_RunAs, slop_option_test_RunAs)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_OWL2_SIGNATURE_DEFINED
#define SLOP_OPTION_OWL2_SIGNATURE_DEFINED
SLOP_OPTION_DEFINE(owl2_Signature, slop_option_owl2_Signature)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

#ifndef SLOP_OPTION_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(types_SubPair, slop_option_types_SubPair)
#endif

#ifndef SLOP_OPTION_ARENA_PTR_DEFINED
#define SLOP_OPTION_ARENA_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_arena*, slop_option_arena_ptr)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_OPTION_SATURATE_ROUNDDELTA_DEFINED
#define SLOP_OPTION_SATURATE_ROUNDDELTA_DEFINED
SLOP_OPTION_DEFINE(saturate_RoundDelta, slop_option_saturate_RoundDelta)
#endif

#ifndef SLOP_OPTION_TYPES_CLASSANSWER_DEFINED
#define SLOP_OPTION_TYPES_CLASSANSWER_DEFINED
SLOP_OPTION_DEFINE(types_ClassAnswer, slop_option_types_ClassAnswer)
#endif

#ifndef SLOP_LIST_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_TYPES_SUBPAIR_IMPL_DEFINED
SLOP_LIST_DEFINE(types_SubPair, slop_list_types_SubPair)
#endif

#ifndef SLOP_LIST_ARENA_PTR_DEFINED
#define SLOP_LIST_ARENA_PTR_DEFINED
#define SLOP_LIST_ARENA_PTR_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_arena*, slop_list_arena_ptr)
#endif

#ifndef SLOP_LIST_SATURATE_ROUNDDELTA_DEFINED
#define SLOP_LIST_SATURATE_ROUNDDELTA_DEFINED
#define SLOP_LIST_SATURATE_ROUNDDELTA_IMPL_DEFINED
SLOP_LIST_DEFINE(saturate_RoundDelta, slop_list_saturate_RoundDelta)
#endif

#ifndef SLOP_LIST_TYPES_CLASSANSWER_DEFINED
#define SLOP_LIST_TYPES_CLASSANSWER_DEFINED
#define SLOP_LIST_TYPES_CLASSANSWER_IMPL_DEFINED
SLOP_LIST_DEFINE(types_ClassAnswer, slop_list_types_ClassAnswer)
#endif

#ifndef SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_IMPL_DEFINED
SLOP_LIST_DEFINE(uint8_t, slop_list_u8)
#endif


#endif
