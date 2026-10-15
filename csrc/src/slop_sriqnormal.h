#ifndef SLOP_sriqnormal_H
#define SLOP_sriqnormal_H

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
#include "slop_owl2.h"
#include "slop_canon.h"
#include "slop_sroiq.h"
#include "slop_naming.h"
#include "slop_sriqrbox.h"

typedef struct howl_sriqnormal_S0 howl_sriqnormal_S0;
typedef struct howl_sriqnormal_S2State howl_sriqnormal_S2State;
typedef struct howl_sriqnormal_S2 howl_sriqnormal_S2;

#ifndef SLOP_LIST_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_OPTION_HOWL_TYPES_DNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_option_howl_types_DName, slop_list_option_howl_types_DName)
#endif

#ifndef SLOP_OPTION_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(slop_option_howl_types_DName, slop_option_option_howl_types_DName)
#endif

#ifndef SLOP_LIST_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sroiq_SAxiom, slop_list_howl_sroiq_SAxiom)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawConcept, slop_list_howl_owl2_RawConcept)
#endif

#ifndef SLOP_LIST_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sroiq_SConcept, slop_list_howl_sroiq_SConcept)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_RoleId, slop_list_howl_types_RoleId)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Node, slop_list_howl_types_Node)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawAxiom, slop_list_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_DLCLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_DlClause, slop_list_howl_types_DlClause)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_DROLE_DEFINED
#define SLOP_LIST_HOWL_TYPES_DROLE_DEFINED
#define SLOP_LIST_HOWL_TYPES_DROLE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_DRole, slop_list_howl_types_DRole)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_DNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_DName, slop_list_howl_types_DName)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SAxiom, slop_option_howl_sroiq_SAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SConcept, slop_option_howl_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DlClause, slop_option_howl_types_DlClause)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DROLE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DROLE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DRole, slop_option_howl_types_DRole)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_DName, slop_option_howl_types_DName)
#endif

struct howl_sriqnormal_S0 {
    slop_list_howl_sroiq_SAxiom axioms;
    howl_sriqrbox_SriqRbox rbox;
};
typedef struct howl_sriqnormal_S0 howl_sriqnormal_S0;

#ifndef SLOP_OPTION_HOWL_SRIQNORMAL_S0_DEFINED
#define SLOP_OPTION_HOWL_SRIQNORMAL_S0_DEFINED
SLOP_OPTION_DEFINE(howl_sriqnormal_S0, slop_option_howl_sriqnormal_S0)
#endif

struct howl_sriqnormal_S2State {
    slop_list_howl_types_DlClause out;
    howl_naming_Registry* registry;
    slop_list_howl_sroiq_SConcept concepts;
    slop_list_howl_types_DRole sroles;
    slop_list_option_howl_types_DName sfills;
    slop_list_slop_rdf_rdf_IRI bars;
    slop_map* barset;
    slop_list_string fnkeys;
    slop_map* fnindex;
};
typedef struct howl_sriqnormal_S2State howl_sriqnormal_S2State;

#ifndef SLOP_OPTION_HOWL_SRIQNORMAL_S2STATE_DEFINED
#define SLOP_OPTION_HOWL_SRIQNORMAL_S2STATE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqnormal_S2State, slop_option_howl_sriqnormal_S2State)
#endif

struct howl_sriqnormal_S2 {
    slop_list_howl_types_DlClause clauses;
    slop_list_howl_sroiq_SConcept concepts;
    slop_list_howl_types_DRole sroles;
    slop_list_option_howl_types_DName sfills;
    slop_list_slop_rdf_rdf_IRI bars;
    slop_list_string fnkeys;
};
typedef struct howl_sriqnormal_S2 howl_sriqnormal_S2;

#ifndef SLOP_OPTION_HOWL_SRIQNORMAL_S2_DEFINED
#define SLOP_OPTION_HOWL_SRIQNORMAL_S2_DEFINED
SLOP_OPTION_DEFINE(howl_sriqnormal_S2, slop_option_howl_sriqnormal_S2)
#endif

#ifndef SLOP_RESULT_LIST_HOWL_SROIQ_SCONCEPT_STRING_DEFINED
#define SLOP_RESULT_LIST_HOWL_SROIQ_SCONCEPT_STRING_DEFINED
typedef struct { bool is_ok; union { slop_list_howl_sroiq_SConcept ok; slop_string err; } data; } slop_result_list_howl_sroiq_SConcept_string;
#endif

#ifndef SLOP_RESULT_HOWL_SROIQ_SCONCEPT_STRING_DEFINED
#define SLOP_RESULT_HOWL_SROIQ_SCONCEPT_STRING_DEFINED
typedef struct { bool is_ok; union { howl_sroiq_SConcept ok; slop_string err; } data; } slop_result_howl_sroiq_SConcept_string;
#endif

#ifndef SLOP_RESULT_LIST_HOWL_SROIQ_SAXIOM_STRING_DEFINED
#define SLOP_RESULT_LIST_HOWL_SROIQ_SAXIOM_STRING_DEFINED
typedef struct { bool is_ok; union { slop_list_howl_sroiq_SAxiom ok; slop_string err; } data; } slop_result_list_howl_sroiq_SAxiom_string;
#endif

#ifndef SLOP_RESULT_HOWL_SRIQNORMAL_S0_STRING_DEFINED
#define SLOP_RESULT_HOWL_SRIQNORMAL_S0_STRING_DEFINED
typedef struct { bool is_ok; union { howl_sriqnormal_S0 ok; slop_string err; } data; } slop_result_howl_sriqnormal_S0_string;
#endif

#ifndef SLOP_RESULT_U8_STRING_DEFINED
#define SLOP_RESULT_U8_STRING_DEFINED
typedef struct { bool is_ok; union { uint8_t ok; slop_string err; } data; } slop_result_u8_string;
#endif

#ifndef SLOP_RESULT_HOWL_SRIQNORMAL_S2_STRING_DEFINED
#define SLOP_RESULT_HOWL_SRIQNORMAL_S2_STRING_DEFINED
typedef struct { bool is_ok; union { howl_sriqnormal_S2 ok; slop_string err; } data; } slop_result_howl_sriqnormal_S2_string;
#endif

howl_sroiq_SConcept* howl_sriqnormal_sc(slop_arena* arena, howl_sroiq_SConcept c);
slop_result_list_howl_sroiq_SConcept_string howl_sriqnormal_s0_concepts(slop_arena* arena, slop_list_howl_owl2_RawConcept cs);
slop_result_howl_sroiq_SConcept_string howl_sriqnormal_s0_filler(slop_arena* arena, howl_owl2_RawConcept* f);
howl_sroiq_SConcept howl_sriqnormal_s0_count(slop_arena* arena, howl_owl2_CardKind k, howl_types_RoleId r, int64_t n, howl_sroiq_SConcept f);
slop_result_howl_sroiq_SConcept_string howl_sriqnormal_s0_concept(slop_arena* arena, howl_owl2_RawConcept c);
howl_sroiq_SAxiom howl_sriqnormal_gci(slop_arena* arena, howl_sroiq_SConcept l, howl_sroiq_SConcept r);
howl_sroiq_SAxiom howl_sriqnormal_ria(slop_arena* arena, slop_list_howl_types_RoleId w, howl_types_RoleId s);
howl_sroiq_SAxiom howl_sriqnormal_ria1(slop_arena* arena, howl_types_RoleId r, howl_types_RoleId s);
slop_option_howl_sroiq_SConcept howl_sriqnormal_nominal(howl_types_Node n);
slop_option_slop_rdf_rdf_IRI howl_sriqnormal_least_individual(slop_list_howl_types_Node ns);
howl_sroiq_SConcept howl_sriqnormal_top_sc(void);
slop_list_howl_sroiq_SAxiom howl_sriqnormal_one_axiom(slop_arena* arena, howl_sroiq_SAxiom a);
slop_list_howl_sroiq_SAxiom howl_sriqnormal_two_axioms(slop_arena* arena, howl_sroiq_SAxiom a, howl_sroiq_SAxiom b);
howl_sroiq_SAxiom howl_sriqnormal_meet_empty(slop_arena* arena, howl_sroiq_SConcept a, howl_sroiq_SConcept b);
slop_list_howl_sroiq_SAxiom howl_sriqnormal_pairwise_disjoint(slop_arena* arena, slop_list_howl_sroiq_SConcept xs);
slop_list_howl_sroiq_SAxiom howl_sriqnormal_pairwise_dis(slop_arena* arena, slop_list_howl_types_RoleId rs);
slop_list_howl_sroiq_SAxiom howl_sriqnormal_mutual_gcis(slop_arena* arena, slop_list_howl_sroiq_SConcept xs);
slop_list_howl_sroiq_SAxiom howl_sriqnormal_mutual_rias(slop_arena* arena, slop_list_howl_types_RoleId rs);
slop_list_howl_sroiq_SAxiom howl_sriqnormal_around_hub(slop_arena* arena, howl_sroiq_SConcept hub, slop_list_howl_sroiq_SConcept xs);
slop_result_list_howl_sroiq_SConcept_string howl_sriqnormal_s0_nominals(slop_arena* arena, slop_list_howl_types_Node ns, slop_string what);
howl_sroiq_SAxiom howl_sriqnormal_transitivity(slop_arena* arena, howl_types_RoleId r);
howl_sroiq_SAxiom howl_sriqnormal_characteristic(slop_arena* arena, howl_owl2_PropCharacteristic c, howl_types_RoleId r);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_sub_class(slop_arena* arena, howl_owl2_RawConcept* l, howl_owl2_RawConcept* r);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_equivalent_classes(slop_arena* arena, slop_list_howl_owl2_RawConcept cs);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_disjoint_classes(slop_arena* arena, slop_list_howl_owl2_RawConcept cs);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_domain(slop_arena* arena, howl_types_RoleId r, howl_owl2_RawConcept* c);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_range(slop_arena* arena, howl_types_RoleId r, howl_owl2_RawConcept* c);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_class_assertion(slop_arena* arena, howl_owl2_RawClassAssertion ca);
howl_sroiq_SConcept howl_sriqnormal_edge_filler(slop_arena* arena, howl_types_RoleId r, howl_sroiq_SConcept b, uint8_t negative);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_assertion(slop_arena* arena, howl_owl2_RawEdge e, slop_string what, uint8_t negative);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_same_individual(slop_arena* arena, slop_list_howl_types_Node ns);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_different_individuals(slop_arena* arena, slop_list_howl_types_Node ns);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_disjoint_union(slop_arena* arena, howl_owl2_RawDisjointUnion du);
howl_sroiq_SConcept howl_sriqnormal_named_class(slop_rdf_rdf_IRI i);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_axiom(slop_arena* arena, howl_owl2_RawAxiom ax);
int64_t howl_sriqnormal_rep_at(howl_sriqrbox_SriqRbox rb, int64_t n);
howl_types_RoleId howl_sriqnormal_collapse_role(howl_sriqrbox_SriqRbox rb, howl_types_RoleId r);
slop_list_howl_types_RoleId howl_sriqnormal_collapse_word(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_types_RoleId w);
slop_list_howl_sroiq_SConcept howl_sriqnormal_collapse_concepts(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SConcept cs);
howl_sroiq_SConcept howl_sriqnormal_collapse_concept(slop_arena* arena, howl_sriqrbox_SriqRbox rb, howl_sroiq_SConcept c);
uint8_t howl_sriqnormal_trivial_ria(slop_list_howl_types_RoleId w, howl_types_RoleId s);
uint8_t howl_sriqnormal_role_eq_p(howl_types_RoleId a, howl_types_RoleId b);
slop_option_howl_sroiq_SAxiom howl_sriqnormal_collapse_axiom(slop_arena* arena, howl_sriqrbox_SriqRbox rb, howl_sroiq_SAxiom a);
howl_types_RoleId howl_sriqnormal_bottom_role(void);
uint8_t howl_sriqnormal_is_bottom(howl_types_RoleId r);
uint8_t howl_sriqnormal_concept_bottom_p(howl_sroiq_SConcept c);
uint8_t howl_sriqnormal_concepts_bottom_p(slop_list_howl_sroiq_SConcept cs);
uint8_t howl_sriqnormal_axiom_bottom_p(howl_sroiq_SAxiom a);
slop_result_howl_sriqnormal_S0_string howl_sriqnormal_sriq_s0(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted);
howl_sriqnormal_S2State* howl_sriqnormal_new_s2(slop_arena* arena);
uint8_t howl_sriqnormal_emit(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DlClause c);
int64_t howl_sriqnormal_fresh_name(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept c);
howl_sroiq_SConcept howl_sriqnormal_concept_of(howl_sriqnormal_S2State* p, int64_t k);
howl_types_DRole howl_sriqnormal_role_name(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_RoleId r);
slop_string howl_sriqnormal_dname_key(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DName n);
slop_string howl_sriqnormal_filler_key(slop_arena* arena, howl_sriqnormal_S2State* p, slop_option_howl_types_DName b);
slop_string howl_sriqnormal_drole_key(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DRole r);
slop_string howl_sriqnormal_key_of(slop_arena* arena, slop_string tag, slop_list_string parts);
slop_string howl_sriqnormal_srole_key(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DRole s, slop_option_howl_types_DName b);
howl_types_DRole howl_sriqnormal_srole_of(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DRole s, slop_option_howl_types_DName b);
int64_t howl_sriqnormal_fn_id(slop_arena* arena, howl_sriqnormal_S2State* p, slop_string key);
slop_list_int howl_sriqnormal_fn_ids(slop_arena* arena, howl_sriqnormal_S2State* p, slop_string axkey, int64_t n);
slop_list_howl_sroiq_SConcept howl_sriqnormal_nnf_list(slop_arena* arena, slop_list_howl_sroiq_SConcept xs, uint8_t pos);
howl_sroiq_SConcept howl_sriqnormal_nnf(slop_arena* arena, howl_sroiq_SConcept c, uint8_t pos);
slop_option_howl_types_DName howl_sriqnormal_pos_name(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept c);
slop_option_howl_types_DName howl_sriqnormal_neg_name(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept c);
slop_option_howl_types_DName howl_sriqnormal_neg_literal_name(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept lit);
slop_list_howl_sroiq_SConcept howl_sriqnormal_singleton_sc(slop_arena* arena, howl_sroiq_SConcept c);
uint8_t howl_sriqnormal_disjunction(slop_arena* arena, howl_sriqnormal_S2State* p, slop_option_howl_types_DName lhs, slop_option_howl_types_DName extra, howl_sroiq_SConcept e);
uint8_t howl_sriqnormal_define_pos(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DName x, howl_sroiq_SConcept e);
uint8_t howl_sriqnormal_define_dl2(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DName x, howl_types_RoleId r, int64_t n, howl_sroiq_SConcept f);
uint8_t howl_sriqnormal_s2_gci(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept l, howl_sroiq_SConcept r);
uint8_t howl_sriqnormal_gci_nnf(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept l, howl_sroiq_SConcept r);
uint8_t howl_sriqnormal_assert_top(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept e, uint8_t ranges);
uint8_t howl_sriqnormal_sc_is_top(howl_sroiq_SConcept c);
uint8_t howl_sriqnormal_sc_is_bottom(howl_sroiq_SConcept c);
howl_types_DName howl_sriqnormal_top_name(slop_arena* arena, howl_sriqnormal_S2State* p);
slop_list_howl_types_DName howl_sriqnormal_one_name(slop_arena* arena, howl_types_DName n);
uint8_t howl_sriqnormal_gci_dl3(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_RoleId r, howl_sroiq_SConcept c, howl_sroiq_SConcept d);
uint8_t howl_sriqnormal_dl3_of(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_RoleId r, slop_option_howl_types_DName b1, howl_sroiq_SConcept d);
slop_option_slop_rdf_rdf_IRI howl_sriqnormal_role_prop(howl_types_RoleId r);
uint8_t howl_sriqnormal_role_inverted(howl_types_RoleId r);
slop_result_u8_string howl_sriqnormal_s2_inclusion(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_RoleId r, howl_types_RoleId s);
slop_result_u8_string howl_sriqnormal_s2_ria(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SRia x);
uint8_t howl_sriqnormal_s2_dis(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_RoleId r, howl_types_RoleId s);
uint8_t howl_sriqnormal_counts_ok(howl_sroiq_SConcept c);
uint8_t howl_sriqnormal_counts_list_ok(slop_list_howl_sroiq_SConcept cs);
slop_result_howl_sriqnormal_S2_string howl_sriqnormal_sriq_s2(slop_arena* arena, slop_list_howl_sroiq_SAxiom axs);
slop_string howl_sriqnormal_render_dname(slop_arena* arena, howl_sriqnormal_S2 s2, howl_types_DName n);
slop_string howl_sriqnormal_render_fresh(slop_arena* arena, howl_sroiq_SConcept c);
slop_string howl_sriqnormal_render_dfiller(slop_arena* arena, howl_sriqnormal_S2 s2, slop_option_howl_types_DName b);
slop_string howl_sriqnormal_render_drole(slop_arena* arena, howl_sriqnormal_S2 s2, howl_types_DRole r);
slop_string howl_sriqnormal_render_dnames(slop_arena* arena, howl_sriqnormal_S2 s2, slop_list_howl_types_DName ns, slop_string sep, slop_string empty);
slop_string howl_sriqnormal_inclusion(slop_arena* arena, slop_string form, slop_string lhs, slop_string rhs);
slop_string howl_sriqnormal_restriction_text(slop_arena* arena, slop_string op, slop_string role, slop_string filler);
slop_string howl_sriqnormal_count_op(slop_arena* arena, slop_string op, int64_t n);
slop_string howl_sriqnormal_braces(slop_arena* arena, slop_rdf_rdf_IRI o);
slop_string howl_sriqnormal_render_dl(slop_arena* arena, howl_sriqnormal_S2 s2, howl_types_DlClause c);

#ifndef SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SAxiom, slop_option_howl_sroiq_SAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQNORMAL_S0_DEFINED
#define SLOP_OPTION_HOWL_SRIQNORMAL_S0_DEFINED
SLOP_OPTION_DEFINE(howl_sriqnormal_S0, slop_option_howl_sriqnormal_S0)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SConcept, slop_option_howl_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DlClause, slop_option_howl_types_DlClause)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DROLE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DROLE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DRole, slop_option_howl_types_DRole)
#endif

#ifndef SLOP_OPTION_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(slop_option_howl_types_DName, slop_option_option_howl_types_DName)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_DName, slop_option_howl_types_DName)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQNORMAL_S2STATE_DEFINED
#define SLOP_OPTION_HOWL_SRIQNORMAL_S2STATE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqnormal_S2State, slop_option_howl_sriqnormal_S2State)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQNORMAL_S2_DEFINED
#define SLOP_OPTION_HOWL_SRIQNORMAL_S2_DEFINED
SLOP_OPTION_DEFINE(howl_sriqnormal_S2, slop_option_howl_sriqnormal_S2)
#endif


#endif
