#ifndef SLOP_types_H
#define SLOP_types_H

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

typedef struct howl_types_Node howl_types_Node;
typedef struct howl_types_RoleId howl_types_RoleId;
typedef struct howl_types_Concept howl_types_Concept;
typedef struct howl_types_NormAxiom howl_types_NormAxiom;
typedef struct howl_types_KName howl_types_KName;
typedef struct howl_types_KTerm howl_types_KTerm;
typedef struct howl_types_KscAxiom howl_types_KscAxiom;
typedef struct howl_types_DName howl_types_DName;
typedef struct howl_types_DRole howl_types_DRole;
typedef struct howl_types_Dl1 howl_types_Dl1;
typedef struct howl_types_Dl2 howl_types_Dl2;
typedef struct howl_types_Dl4 howl_types_Dl4;
typedef struct howl_types_DlClause howl_types_DlClause;
typedef struct howl_types_ATerm howl_types_ATerm;
typedef struct howl_types_Lit howl_types_Lit;
typedef struct howl_types_Clause howl_types_Clause;
typedef struct howl_types_KElem howl_types_KElem;
typedef struct howl_types_KFact howl_types_KFact;
typedef struct howl_types_Derived howl_types_Derived;
typedef struct howl_types_Addressed howl_types_Addressed;
typedef struct howl_types_LogicalEdge howl_types_LogicalEdge;
typedef struct howl_types_EdgePair howl_types_EdgePair;
typedef struct howl_types_Context howl_types_Context;
typedef struct howl_types_Queue howl_types_Queue;
typedef struct howl_types_Saturation howl_types_Saturation;
typedef struct howl_types_AxiomRef howl_types_AxiomRef;
typedef struct howl_types_InputRef howl_types_InputRef;
typedef struct howl_types_MissingDeclaration howl_types_MissingDeclaration;
typedef struct howl_types_UndeclaredProperty howl_types_UndeclaredProperty;
typedef struct howl_types_Omission howl_types_Omission;
typedef struct howl_types_Coverage howl_types_Coverage;
typedef struct howl_types_Termination howl_types_Termination;
typedef struct howl_types_SubPair howl_types_SubPair;
typedef struct howl_types_Findings howl_types_Findings;
typedef struct howl_types_ClassAnswer howl_types_ClassAnswer;
typedef struct howl_types_KscResult howl_types_KscResult;
typedef struct howl_types_SriqEvidence howl_types_SriqEvidence;
typedef struct howl_types_Evidence howl_types_Evidence;
typedef struct howl_types_Outcome howl_types_Outcome;
typedef struct howl_types_Fault howl_types_Fault;
typedef struct howl_types_ProfileSelection howl_types_ProfileSelection;
typedef struct howl_types_ReasonerConfig howl_types_ReasonerConfig;
typedef struct howl_types_Names howl_types_Names;

typedef enum {
    howl_types_AKind_ak_x,
    howl_types_AKind_ak_y,
    howl_types_AKind_ak_z,
    howl_types_AKind_ak_fx,
    howl_types_AKind_ak_u,
    howl_types_AKind_ak_fu
} howl_types_AKind;

typedef enum {
    howl_types_LitForm_lf_unary,
    howl_types_LitForm_lf_binary,
    howl_types_LitForm_lf_eq,
    howl_types_LitForm_lf_neq
} howl_types_LitForm;

typedef enum {
    howl_types_EntityKind_entity_class,
    howl_types_EntityKind_entity_object_property,
    howl_types_EntityKind_entity_data_property,
    howl_types_EntityKind_entity_annotation_property,
    howl_types_EntityKind_entity_individual,
    howl_types_EntityKind_entity_datatype
} howl_types_EntityKind;

typedef enum {
    howl_types_Profile_profile_el,
    howl_types_Profile_profile_el_plus_plus,
    howl_types_Profile_profile_horn_sriq,
    howl_types_Profile_profile_sriq
} howl_types_Profile;

typedef enum {
    howl_types_Verdict_verdict_coherent,
    howl_types_Verdict_verdict_incoherent,
    howl_types_Verdict_verdict_inconclusive
} howl_types_Verdict;

#ifndef SLOP_LIST_ARENA_PTR_DEFINED
#define SLOP_LIST_ARENA_PTR_DEFINED
#define SLOP_LIST_ARENA_PTR_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_arena*, slop_list_arena_ptr)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_OPTION_ARENA_PTR_DEFINED
#define SLOP_OPTION_ARENA_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_arena*, slop_option_arena_ptr)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

typedef enum {
    howl_types_Node_class_node,
    howl_types_Node_individual_node,
    howl_types_Node_fresh_node
} howl_types_Node_tag;

struct howl_types_Node {
    howl_types_Node_tag tag;
    union {
        slop_rdf_rdf_IRI class_node;
        slop_rdf_rdf_IRI individual_node;
        int64_t fresh_node;
    } data;
};
typedef struct howl_types_Node howl_types_Node;

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Node, slop_list_howl_types_Node)
#endif

typedef enum {
    howl_types_RoleId_named_role,
    howl_types_RoleId_fresh_role,
    howl_types_RoleId_inverse_role
} howl_types_RoleId_tag;

struct howl_types_RoleId {
    howl_types_RoleId_tag tag;
    union {
        slop_rdf_rdf_IRI named_role;
        int64_t fresh_role;
        slop_rdf_rdf_IRI inverse_role;
    } data;
};
typedef struct howl_types_RoleId howl_types_RoleId;

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_RoleId, slop_list_howl_types_RoleId)
#endif

typedef enum {
    howl_types_NormAxiom_sub_name,
    howl_types_NormAxiom_sub_and,
    howl_types_NormAxiom_sub_some_rhs,
    howl_types_NormAxiom_sub_some_lhs,
    howl_types_NormAxiom_sub_role,
    howl_types_NormAxiom_role_chain
} howl_types_NormAxiom_tag;

struct howl_types_NormAxiom {
    howl_types_NormAxiom_tag tag;
    union {
        struct {
            howl_types_Node f0;
            howl_types_Node f1;
        } sub_name;
        struct {
            howl_types_Node f0;
            howl_types_Node f1;
            howl_types_Node f2;
        } sub_and;
        struct {
            howl_types_Node f0;
            howl_types_RoleId f1;
            howl_types_Node f2;
        } sub_some_rhs;
        struct {
            howl_types_RoleId f0;
            howl_types_Node f1;
            howl_types_Node f2;
        } sub_some_lhs;
        struct {
            howl_types_RoleId f0;
            howl_types_RoleId f1;
        } sub_role;
        struct {
            howl_types_RoleId f0;
            howl_types_RoleId f1;
            howl_types_RoleId f2;
        } role_chain;
    } data;
};
typedef struct howl_types_NormAxiom howl_types_NormAxiom;

#ifndef SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_NormAxiom, slop_option_howl_types_NormAxiom)
#endif

typedef enum {
    howl_types_KName_k_class,
    howl_types_KName_k_fresh
} howl_types_KName_tag;

struct howl_types_KName {
    howl_types_KName_tag tag;
    union {
        slop_rdf_rdf_IRI k_class;
        int64_t k_fresh;
    } data;
};
typedef struct howl_types_KName howl_types_KName;

#ifndef SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_KName, slop_option_howl_types_KName)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_KNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_KNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_KNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KName, slop_list_howl_types_KName)
#endif

typedef enum {
    howl_types_KTerm_k_name,
    howl_types_KTerm_k_nominal
} howl_types_KTerm_tag;

struct howl_types_KTerm {
    howl_types_KTerm_tag tag;
    union {
        howl_types_KName k_name;
        slop_rdf_rdf_IRI k_nominal;
    } data;
};
typedef struct howl_types_KTerm howl_types_KTerm;

#ifndef SLOP_OPTION_HOWL_TYPES_KTERM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KTERM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KTerm, slop_option_howl_types_KTerm)
#endif

typedef enum {
    howl_types_KscAxiom_k_sub,
    howl_types_KscAxiom_k_and,
    howl_types_KscAxiom_k_some_lhs,
    howl_types_KscAxiom_k_some_rhs,
    howl_types_KscAxiom_k_self_lhs,
    howl_types_KscAxiom_k_self_rhs,
    howl_types_KscAxiom_k_role,
    howl_types_KscAxiom_k_chain,
    howl_types_KscAxiom_k_range,
    howl_types_KscAxiom_k_role_assert
} howl_types_KscAxiom_tag;

struct howl_types_KscAxiom {
    howl_types_KscAxiom_tag tag;
    union {
        struct {
            howl_types_KTerm f0;
            howl_types_KTerm f1;
        } k_sub;
        struct {
            howl_types_KName f0;
            howl_types_KName f1;
            howl_types_KName f2;
        } k_and;
        struct {
            howl_types_RoleId f0;
            howl_types_KName f1;
            howl_types_KName f2;
        } k_some_lhs;
        struct {
            howl_types_KName f0;
            howl_types_RoleId f1;
            howl_types_KName f2;
            int64_t f3;
        } k_some_rhs;
        struct {
            howl_types_RoleId f0;
            howl_types_KName f1;
        } k_self_lhs;
        struct {
            howl_types_KName f0;
            howl_types_RoleId f1;
        } k_self_rhs;
        struct {
            howl_types_RoleId f0;
            howl_types_RoleId f1;
        } k_role;
        struct {
            howl_types_RoleId f0;
            howl_types_RoleId f1;
            howl_types_RoleId f2;
        } k_chain;
        struct {
            howl_types_RoleId f0;
            howl_types_KName f1;
        } k_range;
        struct {
            slop_rdf_rdf_IRI f0;
            howl_types_RoleId f1;
            slop_rdf_rdf_IRI f2;
        } k_role_assert;
    } data;
};
typedef struct howl_types_KscAxiom howl_types_KscAxiom;

#ifndef SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscAxiom, slop_option_howl_types_KscAxiom)
#endif

typedef enum {
    howl_types_DName_dn_class,
    howl_types_DName_dn_fresh
} howl_types_DName_tag;

struct howl_types_DName {
    howl_types_DName_tag tag;
    union {
        slop_rdf_rdf_IRI dn_class;
        int64_t dn_fresh;
    } data;
};
typedef struct howl_types_DName howl_types_DName;

#ifndef SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_DName, slop_option_howl_types_DName)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_DNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_DName, slop_list_howl_types_DName)
#endif

typedef enum {
    howl_types_DRole_dr_prop,
    howl_types_DRole_dr_bar,
    howl_types_DRole_dr_sub
} howl_types_DRole_tag;

struct howl_types_DRole {
    howl_types_DRole_tag tag;
    union {
        slop_rdf_rdf_IRI dr_prop;
        slop_rdf_rdf_IRI dr_bar;
        int64_t dr_sub;
    } data;
};
typedef struct howl_types_DRole howl_types_DRole;

#ifndef SLOP_OPTION_HOWL_TYPES_DROLE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DROLE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DRole, slop_option_howl_types_DRole)
#endif

struct howl_types_Dl1 {
    slop_list_howl_types_DName body;
    slop_list_howl_types_DName head;
};
typedef struct howl_types_Dl1 howl_types_Dl1;

#ifndef SLOP_OPTION_HOWL_TYPES_DL1_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DL1_DEFINED
SLOP_OPTION_DEFINE(howl_types_Dl1, slop_option_howl_types_Dl1)
#endif

struct howl_types_Dl2 {
    howl_types_DName sub;
    howl_types_DRole role;
    int64_t count;
    slop_option_howl_types_DName filler;
    slop_list_int fns;
};
typedef struct howl_types_Dl2 howl_types_Dl2;

#ifndef SLOP_OPTION_HOWL_TYPES_DL2_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DL2_DEFINED
SLOP_OPTION_DEFINE(howl_types_Dl2, slop_option_howl_types_Dl2)
#endif

struct howl_types_Dl4 {
    howl_types_DName sub;
    howl_types_DRole role;
    int64_t count;
    slop_option_howl_types_DName filler;
    howl_types_DRole srole;
};
typedef struct howl_types_Dl4 howl_types_Dl4;

#ifndef SLOP_OPTION_HOWL_TYPES_DL4_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DL4_DEFINED
SLOP_OPTION_DEFINE(howl_types_Dl4, slop_option_howl_types_Dl4)
#endif

typedef enum {
    howl_types_DlClause_dl1,
    howl_types_DlClause_dl2,
    howl_types_DlClause_dl3,
    howl_types_DlClause_dl4,
    howl_types_DlClause_dl5,
    howl_types_DlClause_dl6,
    howl_types_DlClause_dl7,
    howl_types_DlClause_dl8,
    howl_types_DlClause_dl9,
    howl_types_DlClause_dl10,
    howl_types_DlClause_dl11
} howl_types_DlClause_tag;

struct howl_types_DlClause {
    howl_types_DlClause_tag tag;
    union {
        howl_types_Dl1 dl1;
        howl_types_Dl2 dl2;
        struct {
            howl_types_DRole f0;
            howl_types_DName f1;
            howl_types_DName f2;
        } dl3;
        howl_types_Dl4 dl4;
        struct {
            howl_types_DName f0;
            howl_types_DRole f1;
        } dl5;
        struct {
            howl_types_DRole f0;
            howl_types_DName f1;
        } dl6;
        struct {
            howl_types_DRole f0;
            howl_types_DRole f1;
        } dl7;
        struct {
            howl_types_DRole f0;
            howl_types_DRole f1;
        } dl8;
        struct {
            howl_types_DRole f0;
            howl_types_DRole f1;
        } dl9;
        struct {
            slop_rdf_rdf_IRI f0;
            howl_types_DName f1;
        } dl10;
        struct {
            howl_types_DName f0;
            slop_rdf_rdf_IRI f1;
        } dl11;
    } data;
};
typedef struct howl_types_DlClause howl_types_DlClause;

#ifndef SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DlClause, slop_option_howl_types_DlClause)
#endif

struct howl_types_ATerm {
    howl_types_AKind kind;
    uint32_t fsym;
    uint32_t cst;
    uint32_t zi;
};
typedef struct howl_types_ATerm howl_types_ATerm;

#ifndef SLOP_OPTION_HOWL_TYPES_ATERM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ATERM_DEFINED
SLOP_OPTION_DEFINE(howl_types_ATerm, slop_option_howl_types_ATerm)
#endif

struct howl_types_Lit {
    howl_types_LitForm form;
    uint32_t pred;
    howl_types_ATerm t1;
    howl_types_ATerm t2;
};
typedef struct howl_types_Lit howl_types_Lit;

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_HOWL_TYPES_LIT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Lit, slop_list_howl_types_Lit)
#endif

struct howl_types_Clause {
    slop_list_howl_types_Lit body;
    slop_list_howl_types_Lit head;
};
typedef struct howl_types_Clause howl_types_Clause;

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

typedef enum {
    howl_types_KElem_e_ind,
    howl_types_KElem_e_aux,
    howl_types_KElem_e_class
} howl_types_KElem_tag;

struct howl_types_KElem {
    howl_types_KElem_tag tag;
    union {
        slop_rdf_rdf_IRI e_ind;
        int64_t e_aux;
        howl_types_KName e_class;
    } data;
};
typedef struct howl_types_KElem howl_types_KElem;

#ifndef SLOP_OPTION_HOWL_TYPES_KELEM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KELEM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KElem, slop_option_howl_types_KElem)
#endif

typedef enum {
    howl_types_KFact_f_inst,
    howl_types_KFact_f_triple,
    howl_types_KFact_f_self
} howl_types_KFact_tag;

struct howl_types_KFact {
    howl_types_KFact_tag tag;
    union {
        struct {
            howl_types_KElem f0;
            howl_types_KTerm f1;
        } f_inst;
        struct {
            howl_types_KElem f0;
            howl_types_RoleId f1;
            howl_types_KElem f2;
        } f_triple;
        struct {
            howl_types_KElem f0;
            howl_types_RoleId f1;
        } f_self;
    } data;
};
typedef struct howl_types_KFact howl_types_KFact;

#ifndef SLOP_OPTION_HOWL_TYPES_KFACT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(howl_types_KFact, slop_option_howl_types_KFact)
#endif

typedef enum {
    howl_types_Derived_derived_sub,
    howl_types_Derived_derived_succ,
    howl_types_Derived_derived_pred
} howl_types_Derived_tag;

struct howl_types_Derived {
    howl_types_Derived_tag tag;
    union {
        howl_types_Node derived_sub;
        struct {
            howl_types_RoleId f0;
            howl_types_Node f1;
        } derived_succ;
        struct {
            howl_types_RoleId f0;
            howl_types_Node f1;
        } derived_pred;
    } data;
};
typedef struct howl_types_Derived howl_types_Derived;

#ifndef SLOP_OPTION_HOWL_TYPES_DERIVED_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DERIVED_DEFINED
SLOP_OPTION_DEFINE(howl_types_Derived, slop_option_howl_types_Derived)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_DERIVED_DEFINED
#define SLOP_LIST_HOWL_TYPES_DERIVED_DEFINED
#define SLOP_LIST_HOWL_TYPES_DERIVED_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Derived, slop_list_howl_types_Derived)
#endif

struct howl_types_Addressed {
    howl_types_Node to;
    howl_types_Derived what;
};
typedef struct howl_types_Addressed howl_types_Addressed;

#ifndef SLOP_OPTION_HOWL_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(howl_types_Addressed, slop_option_howl_types_Addressed)
#endif

struct howl_types_LogicalEdge {
    howl_types_Node from;
    howl_types_RoleId role;
    howl_types_Node to;
};
typedef struct howl_types_LogicalEdge howl_types_LogicalEdge;

#ifndef SLOP_OPTION_HOWL_TYPES_LOGICALEDGE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LOGICALEDGE_DEFINED
SLOP_OPTION_DEFINE(howl_types_LogicalEdge, slop_option_howl_types_LogicalEdge)
#endif

struct howl_types_EdgePair {
    howl_types_Addressed succ_half;
    howl_types_Addressed pred_half;
};
typedef struct howl_types_EdgePair howl_types_EdgePair;

#ifndef SLOP_OPTION_HOWL_TYPES_EDGEPAIR_DEFINED
#define SLOP_OPTION_HOWL_TYPES_EDGEPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_types_EdgePair, slop_option_howl_types_EdgePair)
#endif

struct howl_types_Context {
    howl_types_Node root;
    slop_map* subsumers;
    slop_map* succs;
    slop_map* preds;
};
typedef struct howl_types_Context howl_types_Context;

#ifndef SLOP_OPTION_HOWL_TYPES_CONTEXT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CONTEXT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Context, slop_option_howl_types_Context)
#endif

struct howl_types_Queue {
    slop_list_howl_types_Derived items;
};
typedef struct howl_types_Queue howl_types_Queue;

#ifndef SLOP_OPTION_HOWL_TYPES_QUEUE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_QUEUE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Queue, slop_option_howl_types_Queue)
#endif

struct howl_types_Saturation {
    slop_map* contexts;
    slop_map* queues;
    slop_map* active;
    int64_t active_count;
    int64_t iteration;
};
typedef struct howl_types_Saturation howl_types_Saturation;

#ifndef SLOP_OPTION_HOWL_TYPES_SATURATION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_SATURATION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Saturation, slop_option_howl_types_Saturation)
#endif

struct howl_types_AxiomRef {
    slop_option_slop_rdf_rdf_IRI source;
    slop_string text;
};
typedef struct howl_types_AxiomRef howl_types_AxiomRef;

#ifndef SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
SLOP_OPTION_DEFINE(howl_types_AxiomRef, slop_option_howl_types_AxiomRef)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_HOWL_TYPES_AXIOMREF_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_AxiomRef, slop_list_howl_types_AxiomRef)
#endif

typedef enum {
    howl_types_InputRef_owl_axiom,
    howl_types_InputRef_rdf_fragment,
    howl_types_InputRef_synthetic
} howl_types_InputRef_tag;

struct howl_types_InputRef {
    howl_types_InputRef_tag tag;
    union {
        howl_types_AxiomRef owl_axiom;
        slop_string rdf_fragment;
        slop_string synthetic;
    } data;
};
typedef struct howl_types_InputRef howl_types_InputRef;

#ifndef SLOP_OPTION_HOWL_TYPES_INPUTREF_DEFINED
#define SLOP_OPTION_HOWL_TYPES_INPUTREF_DEFINED
SLOP_OPTION_DEFINE(howl_types_InputRef, slop_option_howl_types_InputRef)
#endif

struct howl_types_MissingDeclaration {
    howl_types_EntityKind kind;
    slop_rdf_rdf_IRI entity;
    slop_list_howl_types_AxiomRef referring;
};
typedef struct howl_types_MissingDeclaration howl_types_MissingDeclaration;

#ifndef SLOP_OPTION_HOWL_TYPES_MISSINGDECLARATION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_MISSINGDECLARATION_DEFINED
SLOP_OPTION_DEFINE(howl_types_MissingDeclaration, slop_option_howl_types_MissingDeclaration)
#endif

struct howl_types_UndeclaredProperty {
    slop_rdf_rdf_IRI property;
    slop_list_string referring;
};
typedef struct howl_types_UndeclaredProperty howl_types_UndeclaredProperty;

#ifndef SLOP_OPTION_HOWL_TYPES_UNDECLAREDPROPERTY_DEFINED
#define SLOP_OPTION_HOWL_TYPES_UNDECLAREDPROPERTY_DEFINED
SLOP_OPTION_DEFINE(howl_types_UndeclaredProperty, slop_option_howl_types_UndeclaredProperty)
#endif

typedef enum {
    howl_types_Omission_out_of_profile,
    howl_types_Omission_unresolved_import,
    howl_types_Omission_missing_declaration,
    howl_types_Omission_undeclared_property
} howl_types_Omission_tag;

struct howl_types_Omission {
    howl_types_Omission_tag tag;
    union {
        howl_types_InputRef out_of_profile;
        slop_rdf_rdf_IRI unresolved_import;
        howl_types_MissingDeclaration missing_declaration;
        howl_types_UndeclaredProperty undeclared_property;
    } data;
};
typedef struct howl_types_Omission howl_types_Omission;

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Omission, slop_list_howl_types_Omission)
#endif

struct howl_types_Coverage {
    slop_list_howl_types_Omission omitted;
};
typedef struct howl_types_Coverage howl_types_Coverage;

#ifndef SLOP_OPTION_HOWL_TYPES_COVERAGE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_COVERAGE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Coverage, slop_option_howl_types_Coverage)
#endif

typedef enum {
    howl_types_Termination_fixpoint,
    howl_types_Termination_resource_limit
} howl_types_Termination_tag;

struct howl_types_Termination {
    howl_types_Termination_tag tag;
    union {
        int64_t resource_limit;
    } data;
};
typedef struct howl_types_Termination howl_types_Termination;

#ifndef SLOP_OPTION_HOWL_TYPES_TERMINATION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_TERMINATION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Termination, slop_option_howl_types_Termination)
#endif

struct howl_types_SubPair {
    howl_types_Node sub;
    howl_types_Node super;
};
typedef struct howl_types_SubPair howl_types_SubPair;

#ifndef SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_types_SubPair, slop_option_howl_types_SubPair)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_HOWL_TYPES_SUBPAIR_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_SubPair, slop_list_howl_types_SubPair)
#endif

struct howl_types_Findings {
    uint8_t inconsistent;
    slop_list_slop_rdf_rdf_IRI unsatisfiable;
    slop_list_howl_types_SubPair subsumptions;
    slop_list_slop_rdf_rdf_IRI imports_seen;
};
typedef struct howl_types_Findings howl_types_Findings;

#ifndef SLOP_OPTION_HOWL_TYPES_FINDINGS_DEFINED
#define SLOP_OPTION_HOWL_TYPES_FINDINGS_DEFINED
SLOP_OPTION_DEFINE(howl_types_Findings, slop_option_howl_types_Findings)
#endif

struct howl_types_ClassAnswer {
    howl_types_KName cls;
    uint8_t shared;
    uint8_t unsat;
    slop_list_howl_types_KName subsumers;
    uint8_t complete;
    int64_t rounds;
    int64_t facts;
};
typedef struct howl_types_ClassAnswer howl_types_ClassAnswer;

#ifndef SLOP_OPTION_HOWL_TYPES_CLASSANSWER_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLASSANSWER_DEFINED
SLOP_OPTION_DEFINE(howl_types_ClassAnswer, slop_option_howl_types_ClassAnswer)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_CLASSANSWER_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLASSANSWER_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLASSANSWER_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_ClassAnswer, slop_list_howl_types_ClassAnswer)
#endif

struct howl_types_KscResult {
    uint8_t inconsistent;
    howl_types_Termination termination;
    int64_t rounds;
    int64_t g_rounds;
    int64_t g_facts;
    int64_t w_rounds;
    int64_t w_facts;
    int64_t unsafe_count;
    slop_list_howl_types_ClassAnswer answers;
};
typedef struct howl_types_KscResult howl_types_KscResult;

#ifndef SLOP_OPTION_HOWL_TYPES_KSCRESULT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCRESULT_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscResult, slop_option_howl_types_KscResult)
#endif

struct howl_types_SriqEvidence {
    int64_t h_rounds;
    int64_t c_rounds;
    uint8_t ran_c;
};
typedef struct howl_types_SriqEvidence howl_types_SriqEvidence;

#ifndef SLOP_OPTION_HOWL_TYPES_SRIQEVIDENCE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_SRIQEVIDENCE_DEFINED
SLOP_OPTION_DEFINE(howl_types_SriqEvidence, slop_option_howl_types_SriqEvidence)
#endif

typedef enum {
    howl_types_Evidence_el_evidence,
    howl_types_Evidence_ksc_evidence,
    howl_types_Evidence_sriq_evidence
} howl_types_Evidence_tag;

struct howl_types_Evidence {
    howl_types_Evidence_tag tag;
    union {
        howl_types_Saturation el_evidence;
        howl_types_KscResult ksc_evidence;
        howl_types_SriqEvidence sriq_evidence;
    } data;
};
typedef struct howl_types_Evidence howl_types_Evidence;

#ifndef SLOP_OPTION_HOWL_TYPES_EVIDENCE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_EVIDENCE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Evidence, slop_option_howl_types_Evidence)
#endif

typedef enum {
    howl_types_Fault_cancelled,
    howl_types_Fault_input_error,
    howl_types_Fault_refused,
    howl_types_Fault_unavailable
} howl_types_Fault_tag;

struct howl_types_Fault {
    howl_types_Fault_tag tag;
    union {
        slop_string input_error;
        slop_list_howl_types_Omission refused;
        howl_types_Profile unavailable;
    } data;
};
typedef struct howl_types_Fault howl_types_Fault;

#ifndef SLOP_OPTION_HOWL_TYPES_FAULT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_FAULT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Fault, slop_option_howl_types_Fault)
#endif

typedef enum {
    howl_types_ProfileSelection_slop_auto,
    howl_types_ProfileSelection_explicit
} howl_types_ProfileSelection_tag;

struct howl_types_ProfileSelection {
    howl_types_ProfileSelection_tag tag;
    union {
        howl_types_Profile explicit;
    } data;
};
typedef struct howl_types_ProfileSelection howl_types_ProfileSelection;

#ifndef SLOP_OPTION_HOWL_TYPES_PROFILESELECTION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_PROFILESELECTION_DEFINED
SLOP_OPTION_DEFINE(howl_types_ProfileSelection, slop_option_howl_types_ProfileSelection)
#endif

struct howl_types_ReasonerConfig {
    uint8_t worker_count;
    uint16_t channel_buffer;
    uint16_t max_iterations;
    howl_types_ProfileSelection selection;
    uint8_t strict_profile;
    int64_t cancel_ptr;
    uint8_t verbose;
    int64_t clause_budget;
};
typedef struct howl_types_ReasonerConfig howl_types_ReasonerConfig;

#ifndef SLOP_OPTION_HOWL_TYPES_REASONERCONFIG_DEFINED
#define SLOP_OPTION_HOWL_TYPES_REASONERCONFIG_DEFINED
SLOP_OPTION_DEFINE(howl_types_ReasonerConfig, slop_option_howl_types_ReasonerConfig)
#endif

struct howl_types_Names {
    slop_map* node_ids;
    slop_map* nodes;
    slop_map* role_ids;
    slop_map* roles;
};
typedef struct howl_types_Names howl_types_Names;

#ifndef SLOP_OPTION_HOWL_TYPES_NAMES_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NAMES_DEFINED
SLOP_OPTION_DEFINE(howl_types_Names, slop_option_howl_types_Names)
#endif

struct howl_types_Outcome {
    howl_types_Profile profile;
    howl_types_Coverage coverage;
    howl_types_Termination termination;
    howl_types_Findings findings;
    howl_types_Evidence evidence;
    int64_t rounds;
    howl_types_Names names;
    slop_list_arena_ptr owned;
    uint8_t stepped_down;
};
typedef struct howl_types_Outcome howl_types_Outcome;

#ifndef SLOP_OPTION_HOWL_TYPES_OUTCOME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OUTCOME_DEFINED
SLOP_OPTION_DEFINE(howl_types_Outcome, slop_option_howl_types_Outcome)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_CONCEPT_DEFINED
#define SLOP_LIST_HOWL_TYPES_CONCEPT_DEFINED
SLOP_LIST_DECLARE(howl_types_Concept, slop_list_howl_types_Concept)
#endif

typedef enum {
    howl_types_Concept_top,
    howl_types_Concept_bottom,
    howl_types_Concept_atom,
    howl_types_Concept_and,
    howl_types_Concept_exists
} howl_types_Concept_tag;

struct howl_types_Concept {
    howl_types_Concept_tag tag;
    union {
        howl_types_Node atom;
        slop_list_howl_types_Concept and;
        struct {
            howl_types_RoleId f0;
            howl_types_Concept* f1;
        } exists;
    } data;
};
typedef struct howl_types_Concept howl_types_Concept;

#ifndef SLOP_OPTION_HOWL_TYPES_CONCEPT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Concept, slop_option_howl_types_Concept)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_CONCEPT_IMPL_DEFINED
#define SLOP_LIST_HOWL_TYPES_CONCEPT_IMPL_DEFINED
SLOP_LIST_IMPL(howl_types_Concept, slop_list_howl_types_Concept)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef HOWL_TYPES_NODE_HASH_EQ_DEFINED
#define HOWL_TYPES_NODE_HASH_EQ_DEFINED
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
static inline uint64_t slop_hash_howl_types_Node(const void* key) {
    const howl_types_Node* _k = (const howl_types_Node*)key;
    switch (_k->tag) {
        case howl_types_Node_class_node:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.class_node);
        case howl_types_Node_individual_node:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.individual_node);
        case howl_types_Node_fresh_node:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.fresh_node });
    }
    return 0;
}
static inline bool slop_eq_howl_types_Node(const void* a, const void* b) {
    const howl_types_Node* _a = (const howl_types_Node*)a;
    const howl_types_Node* _b = (const howl_types_Node*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_Node_class_node:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.class_node, &_b->data.class_node);
        case howl_types_Node_individual_node:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.individual_node, &_b->data.individual_node);
        case howl_types_Node_fresh_node:
            return _a->data.fresh_node == _b->data.fresh_node;
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

howl_types_ReasonerConfig howl_types_default_config(void);
uint8_t howl_types_cancel_requested(int64_t cancel);
howl_types_Node howl_types_node_top(void);
howl_types_Node howl_types_node_bottom(void);
uint8_t howl_types_node_eq(howl_types_Node a, howl_types_Node b);
uint8_t howl_types_role_eq(howl_types_RoleId a, howl_types_RoleId b);
uint8_t howl_types_kname_eq(howl_types_KName a, howl_types_KName b);
uint8_t howl_types_kterm_eq(howl_types_KTerm a, howl_types_KTerm b);
uint8_t howl_types_kelem_eq(howl_types_KElem a, howl_types_KElem b);
uint8_t howl_types_kfact_eq(howl_types_KFact a, howl_types_KFact b);
howl_types_KTerm howl_types_name_term(howl_types_KName n);
howl_types_KTerm howl_types_nominal_term(slop_rdf_rdf_IRI a);
howl_types_KElem howl_types_ind_elem(slop_rdf_rdf_IRI a);
howl_types_KElem howl_types_aux_elem(int64_t w);
howl_types_KElem howl_types_class_elem(howl_types_KName q);
howl_types_KTerm howl_types_thing_term(void);
howl_types_KTerm howl_types_nothing_term(void);
howl_types_ATerm howl_types_at_x(void);
howl_types_ATerm howl_types_at_y(void);
howl_types_ATerm howl_types_at_z(uint32_t i);
howl_types_ATerm howl_types_at_fx(uint32_t f);
howl_types_ATerm howl_types_at_u(uint32_t u);
howl_types_ATerm howl_types_at_fu(uint32_t f, uint32_t u);
int64_t howl_types_ord_int(int64_t a, int64_t b);
int64_t howl_types_akind_rank(howl_types_AKind k);
int64_t howl_types_aterm_cmp(howl_types_ATerm a, howl_types_ATerm b);
uint8_t howl_types_aterm_eq(howl_types_ATerm a, howl_types_ATerm b);
howl_types_Lit howl_types_atom1(uint32_t b, howl_types_ATerm t);
howl_types_Lit howl_types_atom2(uint32_t s, howl_types_ATerm l, howl_types_ATerm r);
howl_types_Lit howl_types_oriented(howl_types_LitForm form, howl_types_ATerm s, howl_types_ATerm t);
howl_types_Lit howl_types_eq_lit(howl_types_ATerm s, howl_types_ATerm t);
howl_types_Lit howl_types_neq_lit(howl_types_ATerm s, howl_types_ATerm t);
int64_t howl_types_lit_form_rank(howl_types_LitForm f);
int64_t howl_types_lit_cmp(howl_types_Lit a, howl_types_Lit b);
uint8_t howl_types_lit_eq(howl_types_Lit a, howl_types_Lit b);
howl_types_Names howl_types_empty_names(slop_arena* arena);
howl_types_Node howl_types_intern_node(slop_arena* arena, howl_types_Names names, howl_types_Node n);
howl_types_RoleId howl_types_intern_role(slop_arena* arena, howl_types_Names names, howl_types_RoleId r);
slop_string howl_types_copy_string(slop_arena* arena, slop_string s);
slop_rdf_rdf_IRI howl_types_copy_iri(slop_arena* arena, slop_rdf_rdf_IRI i);
howl_types_Node howl_types_copy_node(slop_arena* arena, howl_types_Node n);
howl_types_RoleId howl_types_copy_role(slop_arena* arena, howl_types_RoleId r);
howl_types_AxiomRef howl_types_copy_axiom_ref(slop_arena* arena, howl_types_AxiomRef a);
howl_types_InputRef howl_types_copy_input_ref(slop_arena* arena, howl_types_InputRef r);
howl_types_Omission howl_types_copy_omission(slop_arena* arena, howl_types_Omission o);
slop_list_howl_types_Omission howl_types_copy_omissions(slop_arena* arena, slop_list_howl_types_Omission os);
howl_types_Fault howl_types_copy_fault(slop_arena* arena, howl_types_Fault f);
slop_option_howl_types_Node howl_types_renamed_node(howl_types_Names names, howl_types_Node n);
howl_types_Node howl_types_original_node(howl_types_Names names, howl_types_Node n);
howl_types_RoleId howl_types_original_role(howl_types_Names names, howl_types_RoleId r);
howl_types_Context howl_types_make_context(slop_arena* arena, howl_types_Node root);
howl_types_Queue howl_types_make_queue(slop_arena* arena);
uint8_t howl_types_queue_is_active(howl_types_Queue q);
uint8_t howl_types_derived_eq(howl_types_Derived a, howl_types_Derived b);
uint8_t howl_types_addressed_eq(howl_types_Addressed a, howl_types_Addressed b);
howl_types_EdgePair howl_types_emit_edge(slop_arena* arena, howl_types_LogicalEdge e);
uint8_t howl_types_outcome_is_complete(howl_types_Outcome o);
uint8_t howl_types_findings_are_incoherent(howl_types_Findings f);
howl_types_Verdict howl_types_verdict(howl_types_Outcome o);

#define howl_types_SRIQ_CLAUSE_BUDGET (500000)

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CONCEPT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Concept, slop_option_howl_types_Concept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_NormAxiom, slop_option_howl_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_KName, slop_option_howl_types_KName)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KTERM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KTERM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KTerm, slop_option_howl_types_KTerm)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscAxiom, slop_option_howl_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_DName, slop_option_howl_types_DName)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DROLE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DROLE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DRole, slop_option_howl_types_DRole)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DL1_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DL1_DEFINED
SLOP_OPTION_DEFINE(howl_types_Dl1, slop_option_howl_types_Dl1)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DL2_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DL2_DEFINED
SLOP_OPTION_DEFINE(howl_types_Dl2, slop_option_howl_types_Dl2)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DL4_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DL4_DEFINED
SLOP_OPTION_DEFINE(howl_types_Dl4, slop_option_howl_types_Dl4)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DlClause, slop_option_howl_types_DlClause)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ATERM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ATERM_DEFINED
SLOP_OPTION_DEFINE(howl_types_ATerm, slop_option_howl_types_ATerm)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KELEM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KELEM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KElem, slop_option_howl_types_KElem)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KFACT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(howl_types_KFact, slop_option_howl_types_KFact)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DERIVED_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DERIVED_DEFINED
SLOP_OPTION_DEFINE(howl_types_Derived, slop_option_howl_types_Derived)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(howl_types_Addressed, slop_option_howl_types_Addressed)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LOGICALEDGE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LOGICALEDGE_DEFINED
SLOP_OPTION_DEFINE(howl_types_LogicalEdge, slop_option_howl_types_LogicalEdge)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_EDGEPAIR_DEFINED
#define SLOP_OPTION_HOWL_TYPES_EDGEPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_types_EdgePair, slop_option_howl_types_EdgePair)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CONTEXT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CONTEXT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Context, slop_option_howl_types_Context)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_QUEUE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_QUEUE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Queue, slop_option_howl_types_Queue)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_SATURATION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_SATURATION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Saturation, slop_option_howl_types_Saturation)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
SLOP_OPTION_DEFINE(howl_types_AxiomRef, slop_option_howl_types_AxiomRef)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_INPUTREF_DEFINED
#define SLOP_OPTION_HOWL_TYPES_INPUTREF_DEFINED
SLOP_OPTION_DEFINE(howl_types_InputRef, slop_option_howl_types_InputRef)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_MISSINGDECLARATION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_MISSINGDECLARATION_DEFINED
SLOP_OPTION_DEFINE(howl_types_MissingDeclaration, slop_option_howl_types_MissingDeclaration)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_UNDECLAREDPROPERTY_DEFINED
#define SLOP_OPTION_HOWL_TYPES_UNDECLAREDPROPERTY_DEFINED
SLOP_OPTION_DEFINE(howl_types_UndeclaredProperty, slop_option_howl_types_UndeclaredProperty)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_COVERAGE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_COVERAGE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Coverage, slop_option_howl_types_Coverage)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_TERMINATION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_TERMINATION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Termination, slop_option_howl_types_Termination)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_types_SubPair, slop_option_howl_types_SubPair)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_FINDINGS_DEFINED
#define SLOP_OPTION_HOWL_TYPES_FINDINGS_DEFINED
SLOP_OPTION_DEFINE(howl_types_Findings, slop_option_howl_types_Findings)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLASSANSWER_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLASSANSWER_DEFINED
SLOP_OPTION_DEFINE(howl_types_ClassAnswer, slop_option_howl_types_ClassAnswer)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KSCRESULT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCRESULT_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscResult, slop_option_howl_types_KscResult)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_SRIQEVIDENCE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_SRIQEVIDENCE_DEFINED
SLOP_OPTION_DEFINE(howl_types_SriqEvidence, slop_option_howl_types_SriqEvidence)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_EVIDENCE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_EVIDENCE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Evidence, slop_option_howl_types_Evidence)
#endif

#ifndef SLOP_OPTION_ARENA_PTR_DEFINED
#define SLOP_OPTION_ARENA_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_arena*, slop_option_arena_ptr)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OUTCOME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OUTCOME_DEFINED
SLOP_OPTION_DEFINE(howl_types_Outcome, slop_option_howl_types_Outcome)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_FAULT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_FAULT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Fault, slop_option_howl_types_Fault)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_PROFILESELECTION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_PROFILESELECTION_DEFINED
SLOP_OPTION_DEFINE(howl_types_ProfileSelection, slop_option_howl_types_ProfileSelection)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_REASONERCONFIG_DEFINED
#define SLOP_OPTION_HOWL_TYPES_REASONERCONFIG_DEFINED
SLOP_OPTION_DEFINE(howl_types_ReasonerConfig, slop_option_howl_types_ReasonerConfig)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NAMES_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NAMES_DEFINED
SLOP_OPTION_DEFINE(howl_types_Names, slop_option_howl_types_Names)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_CONCEPT_IMPL_DEFINED
#define SLOP_LIST_HOWL_TYPES_CONCEPT_IMPL_DEFINED
SLOP_LIST_IMPL(howl_types_Concept, slop_list_howl_types_Concept)
#endif


#endif
