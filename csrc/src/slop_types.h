#ifndef SLOP_types_H
#define SLOP_types_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"

typedef struct types_Node types_Node;
typedef struct types_RoleId types_RoleId;
typedef struct types_Concept types_Concept;
typedef struct types_NormAxiom types_NormAxiom;
typedef struct types_KName types_KName;
typedef struct types_KTerm types_KTerm;
typedef struct types_KscAxiom types_KscAxiom;
typedef struct types_KElem types_KElem;
typedef struct types_KFact types_KFact;
typedef struct types_Derived types_Derived;
typedef struct types_Addressed types_Addressed;
typedef struct types_LogicalEdge types_LogicalEdge;
typedef struct types_EdgePair types_EdgePair;
typedef struct types_Context types_Context;
typedef struct types_Queue types_Queue;
typedef struct types_Saturation types_Saturation;
typedef struct types_AxiomRef types_AxiomRef;
typedef struct types_InputRef types_InputRef;
typedef struct types_MissingDeclaration types_MissingDeclaration;
typedef struct types_Omission types_Omission;
typedef struct types_Coverage types_Coverage;
typedef struct types_Termination types_Termination;
typedef struct types_SubPair types_SubPair;
typedef struct types_Findings types_Findings;
typedef struct types_ClassAnswer types_ClassAnswer;
typedef struct types_KscResult types_KscResult;
typedef struct types_Evidence types_Evidence;
typedef struct types_Outcome types_Outcome;
typedef struct types_Fault types_Fault;
typedef struct types_ProfileSelection types_ProfileSelection;
typedef struct types_ReasonerConfig types_ReasonerConfig;
typedef struct types_Names types_Names;

typedef enum {
    types_EntityKind_entity_class,
    types_EntityKind_entity_object_property,
    types_EntityKind_entity_data_property,
    types_EntityKind_entity_annotation_property,
    types_EntityKind_entity_individual,
    types_EntityKind_entity_datatype
} types_EntityKind;

typedef enum {
    types_Profile_profile_el,
    types_Profile_profile_el_plus_plus,
    types_Profile_profile_horn_sriq,
    types_Profile_profile_sriq
} types_Profile;

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

typedef enum {
    types_Node_class_node,
    types_Node_individual_node,
    types_Node_fresh_node
} types_Node_tag;

struct types_Node {
    types_Node_tag tag;
    union {
        rdf_IRI class_node;
        rdf_IRI individual_node;
        int64_t fresh_node;
    } data;
};
typedef struct types_Node types_Node;

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Node, slop_list_types_Node)
#endif

typedef enum {
    types_RoleId_named_role,
    types_RoleId_fresh_role
} types_RoleId_tag;

struct types_RoleId {
    types_RoleId_tag tag;
    union {
        rdf_IRI named_role;
        int64_t fresh_role;
    } data;
};
typedef struct types_RoleId types_RoleId;

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(types_RoleId, slop_list_types_RoleId)
#endif

typedef enum {
    types_NormAxiom_sub_name,
    types_NormAxiom_sub_and,
    types_NormAxiom_sub_some_rhs,
    types_NormAxiom_sub_some_lhs,
    types_NormAxiom_sub_role,
    types_NormAxiom_role_chain
} types_NormAxiom_tag;

struct types_NormAxiom {
    types_NormAxiom_tag tag;
    union {
        struct {
            types_Node f0;
            types_Node f1;
        } sub_name;
        struct {
            types_Node f0;
            types_Node f1;
            types_Node f2;
        } sub_and;
        struct {
            types_Node f0;
            types_RoleId f1;
            types_Node f2;
        } sub_some_rhs;
        struct {
            types_RoleId f0;
            types_Node f1;
            types_Node f2;
        } sub_some_lhs;
        struct {
            types_RoleId f0;
            types_RoleId f1;
        } sub_role;
        struct {
            types_RoleId f0;
            types_RoleId f1;
            types_RoleId f2;
        } role_chain;
    } data;
};
typedef struct types_NormAxiom types_NormAxiom;

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

typedef enum {
    types_KName_k_class,
    types_KName_k_fresh
} types_KName_tag;

struct types_KName {
    types_KName_tag tag;
    union {
        rdf_IRI k_class;
        int64_t k_fresh;
    } data;
};
typedef struct types_KName types_KName;

#ifndef SLOP_OPTION_TYPES_KNAME_DEFINED
#define SLOP_OPTION_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(types_KName, slop_option_types_KName)
#endif

#ifndef SLOP_LIST_TYPES_KNAME_DEFINED
#define SLOP_LIST_TYPES_KNAME_DEFINED
#define SLOP_LIST_TYPES_KNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KName, slop_list_types_KName)
#endif

typedef enum {
    types_KTerm_k_name,
    types_KTerm_k_nominal
} types_KTerm_tag;

struct types_KTerm {
    types_KTerm_tag tag;
    union {
        types_KName k_name;
        rdf_IRI k_nominal;
    } data;
};
typedef struct types_KTerm types_KTerm;

#ifndef SLOP_OPTION_TYPES_KTERM_DEFINED
#define SLOP_OPTION_TYPES_KTERM_DEFINED
SLOP_OPTION_DEFINE(types_KTerm, slop_option_types_KTerm)
#endif

typedef enum {
    types_KscAxiom_k_sub,
    types_KscAxiom_k_and,
    types_KscAxiom_k_some_lhs,
    types_KscAxiom_k_some_rhs,
    types_KscAxiom_k_self_lhs,
    types_KscAxiom_k_self_rhs,
    types_KscAxiom_k_role,
    types_KscAxiom_k_chain,
    types_KscAxiom_k_range,
    types_KscAxiom_k_role_assert
} types_KscAxiom_tag;

struct types_KscAxiom {
    types_KscAxiom_tag tag;
    union {
        struct {
            types_KTerm f0;
            types_KTerm f1;
        } k_sub;
        struct {
            types_KName f0;
            types_KName f1;
            types_KName f2;
        } k_and;
        struct {
            types_RoleId f0;
            types_KName f1;
            types_KName f2;
        } k_some_lhs;
        struct {
            types_KName f0;
            types_RoleId f1;
            types_KName f2;
            int64_t f3;
        } k_some_rhs;
        struct {
            types_RoleId f0;
            types_KName f1;
        } k_self_lhs;
        struct {
            types_KName f0;
            types_RoleId f1;
        } k_self_rhs;
        struct {
            types_RoleId f0;
            types_RoleId f1;
        } k_role;
        struct {
            types_RoleId f0;
            types_RoleId f1;
            types_RoleId f2;
        } k_chain;
        struct {
            types_RoleId f0;
            types_KName f1;
        } k_range;
        struct {
            rdf_IRI f0;
            types_RoleId f1;
            rdf_IRI f2;
        } k_role_assert;
    } data;
};
typedef struct types_KscAxiom types_KscAxiom;

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

typedef enum {
    types_KElem_e_ind,
    types_KElem_e_aux,
    types_KElem_e_class
} types_KElem_tag;

struct types_KElem {
    types_KElem_tag tag;
    union {
        rdf_IRI e_ind;
        int64_t e_aux;
        types_KName e_class;
    } data;
};
typedef struct types_KElem types_KElem;

#ifndef SLOP_OPTION_TYPES_KELEM_DEFINED
#define SLOP_OPTION_TYPES_KELEM_DEFINED
SLOP_OPTION_DEFINE(types_KElem, slop_option_types_KElem)
#endif

typedef enum {
    types_KFact_f_inst,
    types_KFact_f_triple,
    types_KFact_f_self
} types_KFact_tag;

struct types_KFact {
    types_KFact_tag tag;
    union {
        struct {
            types_KElem f0;
            types_KTerm f1;
        } f_inst;
        struct {
            types_KElem f0;
            types_RoleId f1;
            types_KElem f2;
        } f_triple;
        struct {
            types_KElem f0;
            types_RoleId f1;
        } f_self;
    } data;
};
typedef struct types_KFact types_KFact;

#ifndef SLOP_OPTION_TYPES_KFACT_DEFINED
#define SLOP_OPTION_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(types_KFact, slop_option_types_KFact)
#endif

typedef enum {
    types_Derived_derived_sub,
    types_Derived_derived_succ,
    types_Derived_derived_pred
} types_Derived_tag;

struct types_Derived {
    types_Derived_tag tag;
    union {
        types_Node derived_sub;
        struct {
            types_RoleId f0;
            types_Node f1;
        } derived_succ;
        struct {
            types_RoleId f0;
            types_Node f1;
        } derived_pred;
    } data;
};
typedef struct types_Derived types_Derived;

#ifndef SLOP_OPTION_TYPES_DERIVED_DEFINED
#define SLOP_OPTION_TYPES_DERIVED_DEFINED
SLOP_OPTION_DEFINE(types_Derived, slop_option_types_Derived)
#endif

#ifndef SLOP_LIST_TYPES_DERIVED_DEFINED
#define SLOP_LIST_TYPES_DERIVED_DEFINED
#define SLOP_LIST_TYPES_DERIVED_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Derived, slop_list_types_Derived)
#endif

struct types_Addressed {
    types_Node to;
    types_Derived what;
};
typedef struct types_Addressed types_Addressed;

#ifndef SLOP_OPTION_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(types_Addressed, slop_option_types_Addressed)
#endif

struct types_LogicalEdge {
    types_Node from;
    types_RoleId role;
    types_Node to;
};
typedef struct types_LogicalEdge types_LogicalEdge;

#ifndef SLOP_OPTION_TYPES_LOGICALEDGE_DEFINED
#define SLOP_OPTION_TYPES_LOGICALEDGE_DEFINED
SLOP_OPTION_DEFINE(types_LogicalEdge, slop_option_types_LogicalEdge)
#endif

struct types_EdgePair {
    types_Addressed succ_half;
    types_Addressed pred_half;
};
typedef struct types_EdgePair types_EdgePair;

#ifndef SLOP_OPTION_TYPES_EDGEPAIR_DEFINED
#define SLOP_OPTION_TYPES_EDGEPAIR_DEFINED
SLOP_OPTION_DEFINE(types_EdgePair, slop_option_types_EdgePair)
#endif

struct types_Context {
    types_Node root;
    slop_map* subsumers;
    slop_map* succs;
    slop_map* preds;
};
typedef struct types_Context types_Context;

#ifndef SLOP_OPTION_TYPES_CONTEXT_DEFINED
#define SLOP_OPTION_TYPES_CONTEXT_DEFINED
SLOP_OPTION_DEFINE(types_Context, slop_option_types_Context)
#endif

struct types_Queue {
    slop_list_types_Derived items;
};
typedef struct types_Queue types_Queue;

#ifndef SLOP_OPTION_TYPES_QUEUE_DEFINED
#define SLOP_OPTION_TYPES_QUEUE_DEFINED
SLOP_OPTION_DEFINE(types_Queue, slop_option_types_Queue)
#endif

struct types_Saturation {
    slop_map* contexts;
    slop_map* queues;
    slop_map* active;
    int64_t active_count;
    int64_t iteration;
};
typedef struct types_Saturation types_Saturation;

#ifndef SLOP_OPTION_TYPES_SATURATION_DEFINED
#define SLOP_OPTION_TYPES_SATURATION_DEFINED
SLOP_OPTION_DEFINE(types_Saturation, slop_option_types_Saturation)
#endif

struct types_AxiomRef {
    slop_option_rdf_IRI source;
    slop_string text;
};
typedef struct types_AxiomRef types_AxiomRef;

#ifndef SLOP_OPTION_TYPES_AXIOMREF_DEFINED
#define SLOP_OPTION_TYPES_AXIOMREF_DEFINED
SLOP_OPTION_DEFINE(types_AxiomRef, slop_option_types_AxiomRef)
#endif

#ifndef SLOP_LIST_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_TYPES_AXIOMREF_IMPL_DEFINED
SLOP_LIST_DEFINE(types_AxiomRef, slop_list_types_AxiomRef)
#endif

typedef enum {
    types_InputRef_owl_axiom,
    types_InputRef_rdf_fragment,
    types_InputRef_synthetic
} types_InputRef_tag;

struct types_InputRef {
    types_InputRef_tag tag;
    union {
        types_AxiomRef owl_axiom;
        slop_string rdf_fragment;
        slop_string synthetic;
    } data;
};
typedef struct types_InputRef types_InputRef;

#ifndef SLOP_OPTION_TYPES_INPUTREF_DEFINED
#define SLOP_OPTION_TYPES_INPUTREF_DEFINED
SLOP_OPTION_DEFINE(types_InputRef, slop_option_types_InputRef)
#endif

struct types_MissingDeclaration {
    types_EntityKind kind;
    rdf_IRI entity;
    slop_list_types_AxiomRef referring;
};
typedef struct types_MissingDeclaration types_MissingDeclaration;

#ifndef SLOP_OPTION_TYPES_MISSINGDECLARATION_DEFINED
#define SLOP_OPTION_TYPES_MISSINGDECLARATION_DEFINED
SLOP_OPTION_DEFINE(types_MissingDeclaration, slop_option_types_MissingDeclaration)
#endif

typedef enum {
    types_Omission_out_of_profile,
    types_Omission_unresolved_import,
    types_Omission_missing_declaration
} types_Omission_tag;

struct types_Omission {
    types_Omission_tag tag;
    union {
        types_InputRef out_of_profile;
        rdf_IRI unresolved_import;
        types_MissingDeclaration missing_declaration;
    } data;
};
typedef struct types_Omission types_Omission;

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

#ifndef SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Omission, slop_list_types_Omission)
#endif

struct types_Coverage {
    slop_list_types_Omission omitted;
};
typedef struct types_Coverage types_Coverage;

#ifndef SLOP_OPTION_TYPES_COVERAGE_DEFINED
#define SLOP_OPTION_TYPES_COVERAGE_DEFINED
SLOP_OPTION_DEFINE(types_Coverage, slop_option_types_Coverage)
#endif

typedef enum {
    types_Termination_fixpoint,
    types_Termination_resource_limit
} types_Termination_tag;

struct types_Termination {
    types_Termination_tag tag;
    union {
        int64_t resource_limit;
    } data;
};
typedef struct types_Termination types_Termination;

#ifndef SLOP_OPTION_TYPES_TERMINATION_DEFINED
#define SLOP_OPTION_TYPES_TERMINATION_DEFINED
SLOP_OPTION_DEFINE(types_Termination, slop_option_types_Termination)
#endif

struct types_SubPair {
    types_Node sub;
    types_Node super;
};
typedef struct types_SubPair types_SubPair;

#ifndef SLOP_OPTION_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(types_SubPair, slop_option_types_SubPair)
#endif

#ifndef SLOP_LIST_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_TYPES_SUBPAIR_IMPL_DEFINED
SLOP_LIST_DEFINE(types_SubPair, slop_list_types_SubPair)
#endif

struct types_Findings {
    uint8_t inconsistent;
    slop_list_rdf_IRI unsatisfiable;
    slop_list_types_SubPair subsumptions;
    slop_list_rdf_IRI imports_seen;
};
typedef struct types_Findings types_Findings;

#ifndef SLOP_OPTION_TYPES_FINDINGS_DEFINED
#define SLOP_OPTION_TYPES_FINDINGS_DEFINED
SLOP_OPTION_DEFINE(types_Findings, slop_option_types_Findings)
#endif

struct types_ClassAnswer {
    types_KName cls;
    uint8_t shared;
    uint8_t unsat;
    slop_list_types_KName subsumers;
    uint8_t complete;
    int64_t rounds;
    int64_t facts;
};
typedef struct types_ClassAnswer types_ClassAnswer;

#ifndef SLOP_OPTION_TYPES_CLASSANSWER_DEFINED
#define SLOP_OPTION_TYPES_CLASSANSWER_DEFINED
SLOP_OPTION_DEFINE(types_ClassAnswer, slop_option_types_ClassAnswer)
#endif

#ifndef SLOP_LIST_TYPES_CLASSANSWER_DEFINED
#define SLOP_LIST_TYPES_CLASSANSWER_DEFINED
#define SLOP_LIST_TYPES_CLASSANSWER_IMPL_DEFINED
SLOP_LIST_DEFINE(types_ClassAnswer, slop_list_types_ClassAnswer)
#endif

struct types_KscResult {
    uint8_t inconsistent;
    types_Termination termination;
    int64_t rounds;
    int64_t g_rounds;
    int64_t g_facts;
    int64_t w_rounds;
    int64_t w_facts;
    int64_t unsafe_count;
    slop_list_types_ClassAnswer answers;
};
typedef struct types_KscResult types_KscResult;

#ifndef SLOP_OPTION_TYPES_KSCRESULT_DEFINED
#define SLOP_OPTION_TYPES_KSCRESULT_DEFINED
SLOP_OPTION_DEFINE(types_KscResult, slop_option_types_KscResult)
#endif

typedef enum {
    types_Evidence_el_evidence,
    types_Evidence_ksc_evidence
} types_Evidence_tag;

struct types_Evidence {
    types_Evidence_tag tag;
    union {
        types_Saturation el_evidence;
        types_KscResult ksc_evidence;
    } data;
};
typedef struct types_Evidence types_Evidence;

#ifndef SLOP_OPTION_TYPES_EVIDENCE_DEFINED
#define SLOP_OPTION_TYPES_EVIDENCE_DEFINED
SLOP_OPTION_DEFINE(types_Evidence, slop_option_types_Evidence)
#endif

typedef enum {
    types_Fault_cancelled,
    types_Fault_input_error,
    types_Fault_refused,
    types_Fault_unavailable
} types_Fault_tag;

struct types_Fault {
    types_Fault_tag tag;
    union {
        slop_string input_error;
        slop_list_types_Omission refused;
        types_Profile unavailable;
    } data;
};
typedef struct types_Fault types_Fault;

#ifndef SLOP_OPTION_TYPES_FAULT_DEFINED
#define SLOP_OPTION_TYPES_FAULT_DEFINED
SLOP_OPTION_DEFINE(types_Fault, slop_option_types_Fault)
#endif

typedef enum {
    types_ProfileSelection_slop_auto,
    types_ProfileSelection_explicit
} types_ProfileSelection_tag;

struct types_ProfileSelection {
    types_ProfileSelection_tag tag;
    union {
        types_Profile explicit;
    } data;
};
typedef struct types_ProfileSelection types_ProfileSelection;

#ifndef SLOP_OPTION_TYPES_PROFILESELECTION_DEFINED
#define SLOP_OPTION_TYPES_PROFILESELECTION_DEFINED
SLOP_OPTION_DEFINE(types_ProfileSelection, slop_option_types_ProfileSelection)
#endif

struct types_ReasonerConfig {
    uint8_t worker_count;
    uint16_t channel_buffer;
    uint16_t max_iterations;
    types_ProfileSelection selection;
    uint8_t strict_profile;
    int64_t cancel_ptr;
    uint8_t verbose;
};
typedef struct types_ReasonerConfig types_ReasonerConfig;

#ifndef SLOP_OPTION_TYPES_REASONERCONFIG_DEFINED
#define SLOP_OPTION_TYPES_REASONERCONFIG_DEFINED
SLOP_OPTION_DEFINE(types_ReasonerConfig, slop_option_types_ReasonerConfig)
#endif

struct types_Names {
    slop_map* node_ids;
    slop_map* nodes;
    slop_map* role_ids;
    slop_map* roles;
};
typedef struct types_Names types_Names;

#ifndef SLOP_OPTION_TYPES_NAMES_DEFINED
#define SLOP_OPTION_TYPES_NAMES_DEFINED
SLOP_OPTION_DEFINE(types_Names, slop_option_types_Names)
#endif

struct types_Outcome {
    types_Profile profile;
    types_Coverage coverage;
    types_Termination termination;
    types_Findings findings;
    types_Evidence evidence;
    int64_t rounds;
    types_Names names;
};
typedef struct types_Outcome types_Outcome;

#ifndef SLOP_OPTION_TYPES_OUTCOME_DEFINED
#define SLOP_OPTION_TYPES_OUTCOME_DEFINED
SLOP_OPTION_DEFINE(types_Outcome, slop_option_types_Outcome)
#endif

#ifndef SLOP_LIST_TYPES_CONCEPT_DEFINED
#define SLOP_LIST_TYPES_CONCEPT_DEFINED
SLOP_LIST_DECLARE(types_Concept, slop_list_types_Concept)
#endif

typedef enum {
    types_Concept_top,
    types_Concept_bottom,
    types_Concept_atom,
    types_Concept_and,
    types_Concept_exists
} types_Concept_tag;

struct types_Concept {
    types_Concept_tag tag;
    union {
        types_Node atom;
        slop_list_types_Concept and;
        struct {
            types_RoleId f0;
            types_Concept* f1;
        } exists;
    } data;
};
typedef struct types_Concept types_Concept;

#ifndef SLOP_OPTION_TYPES_CONCEPT_DEFINED
#define SLOP_OPTION_TYPES_CONCEPT_DEFINED
SLOP_OPTION_DEFINE(types_Concept, slop_option_types_Concept)
#endif

#ifndef SLOP_LIST_TYPES_CONCEPT_IMPL_DEFINED
#define SLOP_LIST_TYPES_CONCEPT_IMPL_DEFINED
SLOP_LIST_IMPL(types_Concept, slop_list_types_Concept)
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

types_ReasonerConfig howl_default_config(void);
uint8_t types_cancel_requested(int64_t cancel);
types_Node types_node_top(void);
types_Node types_node_bottom(void);
uint8_t types_node_eq(types_Node a, types_Node b);
uint8_t types_role_eq(types_RoleId a, types_RoleId b);
uint8_t types_kname_eq(types_KName a, types_KName b);
uint8_t types_kterm_eq(types_KTerm a, types_KTerm b);
uint8_t types_kelem_eq(types_KElem a, types_KElem b);
uint8_t types_kfact_eq(types_KFact a, types_KFact b);
types_KTerm types_name_term(types_KName n);
types_KTerm types_nominal_term(rdf_IRI a);
types_KElem types_ind_elem(rdf_IRI a);
types_KElem types_aux_elem(int64_t w);
types_KElem types_class_elem(types_KName q);
types_KTerm types_thing_term(void);
types_KTerm types_nothing_term(void);
types_Names types_empty_names(slop_arena* arena);
types_Node types_intern_node(slop_arena* arena, types_Names names, types_Node n);
types_RoleId types_intern_role(slop_arena* arena, types_Names names, types_RoleId r);
slop_string types_copy_string(slop_arena* arena, slop_string s);
rdf_IRI types_copy_iri(slop_arena* arena, rdf_IRI i);
types_Node types_copy_node(slop_arena* arena, types_Node n);
types_RoleId types_copy_role(slop_arena* arena, types_RoleId r);
types_AxiomRef types_copy_axiom_ref(slop_arena* arena, types_AxiomRef a);
types_InputRef types_copy_input_ref(slop_arena* arena, types_InputRef r);
types_Omission types_copy_omission(slop_arena* arena, types_Omission o);
slop_list_types_Omission types_copy_omissions(slop_arena* arena, slop_list_types_Omission os);
types_Fault types_copy_fault(slop_arena* arena, types_Fault f);
slop_option_types_Node types_renamed_node(types_Names names, types_Node n);
types_Node types_original_node(types_Names names, types_Node n);
types_RoleId types_original_role(types_Names names, types_RoleId r);
types_Context types_make_context(slop_arena* arena, types_Node root);
types_Queue types_make_queue(slop_arena* arena);
uint8_t types_queue_is_active(types_Queue q);
uint8_t types_derived_eq(types_Derived a, types_Derived b);
uint8_t types_addressed_eq(types_Addressed a, types_Addressed b);
types_EdgePair types_emit_edge(slop_arena* arena, types_LogicalEdge e);
uint8_t types_outcome_is_complete(types_Outcome o);
uint8_t types_findings_are_incoherent(types_Findings f);

/* Function name aliases for C interop */
#define types_default_config howl_default_config

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_TYPES_CONCEPT_DEFINED
#define SLOP_OPTION_TYPES_CONCEPT_DEFINED
SLOP_OPTION_DEFINE(types_Concept, slop_option_types_Concept)
#endif

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_KNAME_DEFINED
#define SLOP_OPTION_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(types_KName, slop_option_types_KName)
#endif

#ifndef SLOP_OPTION_TYPES_KTERM_DEFINED
#define SLOP_OPTION_TYPES_KTERM_DEFINED
SLOP_OPTION_DEFINE(types_KTerm, slop_option_types_KTerm)
#endif

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_KELEM_DEFINED
#define SLOP_OPTION_TYPES_KELEM_DEFINED
SLOP_OPTION_DEFINE(types_KElem, slop_option_types_KElem)
#endif

#ifndef SLOP_OPTION_TYPES_KFACT_DEFINED
#define SLOP_OPTION_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(types_KFact, slop_option_types_KFact)
#endif

#ifndef SLOP_OPTION_TYPES_DERIVED_DEFINED
#define SLOP_OPTION_TYPES_DERIVED_DEFINED
SLOP_OPTION_DEFINE(types_Derived, slop_option_types_Derived)
#endif

#ifndef SLOP_OPTION_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(types_Addressed, slop_option_types_Addressed)
#endif

#ifndef SLOP_OPTION_TYPES_LOGICALEDGE_DEFINED
#define SLOP_OPTION_TYPES_LOGICALEDGE_DEFINED
SLOP_OPTION_DEFINE(types_LogicalEdge, slop_option_types_LogicalEdge)
#endif

#ifndef SLOP_OPTION_TYPES_EDGEPAIR_DEFINED
#define SLOP_OPTION_TYPES_EDGEPAIR_DEFINED
SLOP_OPTION_DEFINE(types_EdgePair, slop_option_types_EdgePair)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_OPTION_TYPES_CONTEXT_DEFINED
#define SLOP_OPTION_TYPES_CONTEXT_DEFINED
SLOP_OPTION_DEFINE(types_Context, slop_option_types_Context)
#endif

#ifndef SLOP_OPTION_TYPES_QUEUE_DEFINED
#define SLOP_OPTION_TYPES_QUEUE_DEFINED
SLOP_OPTION_DEFINE(types_Queue, slop_option_types_Queue)
#endif

#ifndef SLOP_OPTION_TYPES_SATURATION_DEFINED
#define SLOP_OPTION_TYPES_SATURATION_DEFINED
SLOP_OPTION_DEFINE(types_Saturation, slop_option_types_Saturation)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_AXIOMREF_DEFINED
#define SLOP_OPTION_TYPES_AXIOMREF_DEFINED
SLOP_OPTION_DEFINE(types_AxiomRef, slop_option_types_AxiomRef)
#endif

#ifndef SLOP_OPTION_TYPES_INPUTREF_DEFINED
#define SLOP_OPTION_TYPES_INPUTREF_DEFINED
SLOP_OPTION_DEFINE(types_InputRef, slop_option_types_InputRef)
#endif

#ifndef SLOP_OPTION_TYPES_MISSINGDECLARATION_DEFINED
#define SLOP_OPTION_TYPES_MISSINGDECLARATION_DEFINED
SLOP_OPTION_DEFINE(types_MissingDeclaration, slop_option_types_MissingDeclaration)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

#ifndef SLOP_OPTION_TYPES_COVERAGE_DEFINED
#define SLOP_OPTION_TYPES_COVERAGE_DEFINED
SLOP_OPTION_DEFINE(types_Coverage, slop_option_types_Coverage)
#endif

#ifndef SLOP_OPTION_TYPES_TERMINATION_DEFINED
#define SLOP_OPTION_TYPES_TERMINATION_DEFINED
SLOP_OPTION_DEFINE(types_Termination, slop_option_types_Termination)
#endif

#ifndef SLOP_OPTION_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(types_SubPair, slop_option_types_SubPair)
#endif

#ifndef SLOP_OPTION_TYPES_FINDINGS_DEFINED
#define SLOP_OPTION_TYPES_FINDINGS_DEFINED
SLOP_OPTION_DEFINE(types_Findings, slop_option_types_Findings)
#endif

#ifndef SLOP_OPTION_TYPES_CLASSANSWER_DEFINED
#define SLOP_OPTION_TYPES_CLASSANSWER_DEFINED
SLOP_OPTION_DEFINE(types_ClassAnswer, slop_option_types_ClassAnswer)
#endif

#ifndef SLOP_OPTION_TYPES_KSCRESULT_DEFINED
#define SLOP_OPTION_TYPES_KSCRESULT_DEFINED
SLOP_OPTION_DEFINE(types_KscResult, slop_option_types_KscResult)
#endif

#ifndef SLOP_OPTION_TYPES_EVIDENCE_DEFINED
#define SLOP_OPTION_TYPES_EVIDENCE_DEFINED
SLOP_OPTION_DEFINE(types_Evidence, slop_option_types_Evidence)
#endif

#ifndef SLOP_OPTION_TYPES_OUTCOME_DEFINED
#define SLOP_OPTION_TYPES_OUTCOME_DEFINED
SLOP_OPTION_DEFINE(types_Outcome, slop_option_types_Outcome)
#endif

#ifndef SLOP_OPTION_TYPES_FAULT_DEFINED
#define SLOP_OPTION_TYPES_FAULT_DEFINED
SLOP_OPTION_DEFINE(types_Fault, slop_option_types_Fault)
#endif

#ifndef SLOP_OPTION_TYPES_PROFILESELECTION_DEFINED
#define SLOP_OPTION_TYPES_PROFILESELECTION_DEFINED
SLOP_OPTION_DEFINE(types_ProfileSelection, slop_option_types_ProfileSelection)
#endif

#ifndef SLOP_OPTION_TYPES_REASONERCONFIG_DEFINED
#define SLOP_OPTION_TYPES_REASONERCONFIG_DEFINED
SLOP_OPTION_DEFINE(types_ReasonerConfig, slop_option_types_ReasonerConfig)
#endif

#ifndef SLOP_OPTION_TYPES_NAMES_DEFINED
#define SLOP_OPTION_TYPES_NAMES_DEFINED
SLOP_OPTION_DEFINE(types_Names, slop_option_types_Names)
#endif

#ifndef SLOP_LIST_TYPES_CONCEPT_IMPL_DEFINED
#define SLOP_LIST_TYPES_CONCEPT_IMPL_DEFINED
SLOP_LIST_IMPL(types_Concept, slop_list_types_Concept)
#endif


#endif
