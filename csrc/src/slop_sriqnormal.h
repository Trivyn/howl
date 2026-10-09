#ifndef SLOP_sriqnormal_H
#define SLOP_sriqnormal_H

#include "../runtime/slop_runtime.h"
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

typedef struct sriqnormal_S0 sriqnormal_S0;
typedef struct sriqnormal_S2State sriqnormal_S2State;
typedef struct sriqnormal_S2 sriqnormal_S2;

#ifndef SLOP_LIST_OPTION_TYPES_DNAME_DEFINED
#define SLOP_LIST_OPTION_TYPES_DNAME_DEFINED
#define SLOP_LIST_OPTION_TYPES_DNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_option_types_DName, slop_list_option_types_DName)
#endif

#ifndef SLOP_OPTION_OPTION_TYPES_DNAME_DEFINED
#define SLOP_OPTION_OPTION_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(slop_option_types_DName, slop_option_option_types_DName)
#endif

#ifndef SLOP_LIST_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_SROIQ_SAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(sroiq_SAxiom, slop_list_sroiq_SAxiom)
#endif

#ifndef SLOP_LIST_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawConcept, slop_list_owl2_RawConcept)
#endif

#ifndef SLOP_LIST_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_SROIQ_SCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(sroiq_SConcept, slop_list_sroiq_SConcept)
#endif

#ifndef SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(types_RoleId, slop_list_types_RoleId)
#endif

#ifndef SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Node, slop_list_types_Node)
#endif

#ifndef SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawAxiom, slop_list_owl2_RawAxiom)
#endif

#ifndef SLOP_LIST_TYPES_DLCLAUSE_DEFINED
#define SLOP_LIST_TYPES_DLCLAUSE_DEFINED
#define SLOP_LIST_TYPES_DLCLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_DlClause, slop_list_types_DlClause)
#endif

#ifndef SLOP_LIST_TYPES_DROLE_DEFINED
#define SLOP_LIST_TYPES_DROLE_DEFINED
#define SLOP_LIST_TYPES_DROLE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_DRole, slop_list_types_DRole)
#endif

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_LIST_TYPES_DNAME_DEFINED
#define SLOP_LIST_TYPES_DNAME_DEFINED
#define SLOP_LIST_TYPES_DNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(types_DName, slop_list_types_DName)
#endif

#ifndef SLOP_OPTION_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(sroiq_SAxiom, slop_option_sroiq_SAxiom)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(sroiq_SConcept, slop_option_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_DLCLAUSE_DEFINED
#define SLOP_OPTION_TYPES_DLCLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_DlClause, slop_option_types_DlClause)
#endif

#ifndef SLOP_OPTION_TYPES_DROLE_DEFINED
#define SLOP_OPTION_TYPES_DROLE_DEFINED
SLOP_OPTION_DEFINE(types_DRole, slop_option_types_DRole)
#endif

#ifndef SLOP_OPTION_TYPES_DNAME_DEFINED
#define SLOP_OPTION_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(types_DName, slop_option_types_DName)
#endif

struct sriqnormal_S0 {
    slop_list_sroiq_SAxiom axioms;
    sriqrbox_SriqRbox rbox;
};
typedef struct sriqnormal_S0 sriqnormal_S0;

#ifndef SLOP_OPTION_SRIQNORMAL_S0_DEFINED
#define SLOP_OPTION_SRIQNORMAL_S0_DEFINED
SLOP_OPTION_DEFINE(sriqnormal_S0, slop_option_sriqnormal_S0)
#endif

struct sriqnormal_S2State {
    slop_list_types_DlClause out;
    naming_Registry* registry;
    slop_list_sroiq_SConcept concepts;
    slop_list_types_DRole sroles;
    slop_list_option_types_DName sfills;
    slop_list_rdf_IRI bars;
    slop_map* barset;
    slop_list_string fnkeys;
    slop_map* fnindex;
};
typedef struct sriqnormal_S2State sriqnormal_S2State;

#ifndef SLOP_OPTION_SRIQNORMAL_S2STATE_DEFINED
#define SLOP_OPTION_SRIQNORMAL_S2STATE_DEFINED
SLOP_OPTION_DEFINE(sriqnormal_S2State, slop_option_sriqnormal_S2State)
#endif

struct sriqnormal_S2 {
    slop_list_types_DlClause clauses;
    slop_list_sroiq_SConcept concepts;
    slop_list_types_DRole sroles;
    slop_list_option_types_DName sfills;
    slop_list_rdf_IRI bars;
    slop_list_string fnkeys;
};
typedef struct sriqnormal_S2 sriqnormal_S2;

#ifndef SLOP_OPTION_SRIQNORMAL_S2_DEFINED
#define SLOP_OPTION_SRIQNORMAL_S2_DEFINED
SLOP_OPTION_DEFINE(sriqnormal_S2, slop_option_sriqnormal_S2)
#endif

#ifndef SLOP_RESULT_LIST_SROIQ_SCONCEPT_STRING_DEFINED
#define SLOP_RESULT_LIST_SROIQ_SCONCEPT_STRING_DEFINED
typedef struct { bool is_ok; union { slop_list_sroiq_SConcept ok; slop_string err; } data; } slop_result_list_sroiq_SConcept_string;
#endif

#ifndef SLOP_RESULT_SROIQ_SCONCEPT_STRING_DEFINED
#define SLOP_RESULT_SROIQ_SCONCEPT_STRING_DEFINED
typedef struct { bool is_ok; union { sroiq_SConcept ok; slop_string err; } data; } slop_result_sroiq_SConcept_string;
#endif

#ifndef SLOP_RESULT_LIST_SROIQ_SAXIOM_STRING_DEFINED
#define SLOP_RESULT_LIST_SROIQ_SAXIOM_STRING_DEFINED
typedef struct { bool is_ok; union { slop_list_sroiq_SAxiom ok; slop_string err; } data; } slop_result_list_sroiq_SAxiom_string;
#endif

#ifndef SLOP_RESULT_SRIQNORMAL_S0_STRING_DEFINED
#define SLOP_RESULT_SRIQNORMAL_S0_STRING_DEFINED
typedef struct { bool is_ok; union { sriqnormal_S0 ok; slop_string err; } data; } slop_result_sriqnormal_S0_string;
#endif

#ifndef SLOP_RESULT_U8_STRING_DEFINED
#define SLOP_RESULT_U8_STRING_DEFINED
typedef struct { bool is_ok; union { uint8_t ok; slop_string err; } data; } slop_result_u8_string;
#endif

#ifndef SLOP_RESULT_SRIQNORMAL_S2_STRING_DEFINED
#define SLOP_RESULT_SRIQNORMAL_S2_STRING_DEFINED
typedef struct { bool is_ok; union { sriqnormal_S2 ok; slop_string err; } data; } slop_result_sriqnormal_S2_string;
#endif

sroiq_SConcept* sriqnormal_sc(slop_arena* arena, sroiq_SConcept c);
slop_result_list_sroiq_SConcept_string sriqnormal_s0_concepts(slop_arena* arena, slop_list_owl2_RawConcept cs);
slop_result_sroiq_SConcept_string sriqnormal_s0_filler(slop_arena* arena, owl2_RawConcept* f);
sroiq_SConcept sriqnormal_s0_count(slop_arena* arena, owl2_CardKind k, types_RoleId r, int64_t n, sroiq_SConcept f);
slop_result_sroiq_SConcept_string sriqnormal_s0_concept(slop_arena* arena, owl2_RawConcept c);
sroiq_SAxiom sriqnormal_gci(slop_arena* arena, sroiq_SConcept l, sroiq_SConcept r);
sroiq_SAxiom sriqnormal_ria(slop_arena* arena, slop_list_types_RoleId w, types_RoleId s);
sroiq_SAxiom sriqnormal_ria1(slop_arena* arena, types_RoleId r, types_RoleId s);
slop_option_sroiq_SConcept sriqnormal_nominal(types_Node n);
slop_option_rdf_IRI sriqnormal_least_individual(slop_list_types_Node ns);
sroiq_SConcept sriqnormal_top_sc(void);
slop_list_sroiq_SAxiom sriqnormal_one_axiom(slop_arena* arena, sroiq_SAxiom a);
slop_list_sroiq_SAxiom sriqnormal_two_axioms(slop_arena* arena, sroiq_SAxiom a, sroiq_SAxiom b);
sroiq_SAxiom sriqnormal_meet_empty(slop_arena* arena, sroiq_SConcept a, sroiq_SConcept b);
slop_list_sroiq_SAxiom sriqnormal_pairwise_disjoint(slop_arena* arena, slop_list_sroiq_SConcept xs);
slop_list_sroiq_SAxiom sriqnormal_pairwise_dis(slop_arena* arena, slop_list_types_RoleId rs);
slop_list_sroiq_SAxiom sriqnormal_mutual_gcis(slop_arena* arena, slop_list_sroiq_SConcept xs);
slop_list_sroiq_SAxiom sriqnormal_mutual_rias(slop_arena* arena, slop_list_types_RoleId rs);
slop_list_sroiq_SAxiom sriqnormal_around_hub(slop_arena* arena, sroiq_SConcept hub, slop_list_sroiq_SConcept xs);
slop_result_list_sroiq_SConcept_string sriqnormal_s0_nominals(slop_arena* arena, slop_list_types_Node ns, slop_string what);
sroiq_SAxiom sriqnormal_transitivity(slop_arena* arena, types_RoleId r);
sroiq_SAxiom sriqnormal_characteristic(slop_arena* arena, owl2_PropCharacteristic c, types_RoleId r);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_sub_class(slop_arena* arena, owl2_RawConcept* l, owl2_RawConcept* r);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_equivalent_classes(slop_arena* arena, slop_list_owl2_RawConcept cs);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_disjoint_classes(slop_arena* arena, slop_list_owl2_RawConcept cs);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_domain(slop_arena* arena, types_RoleId r, owl2_RawConcept* c);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_range(slop_arena* arena, types_RoleId r, owl2_RawConcept* c);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_class_assertion(slop_arena* arena, owl2_RawClassAssertion ca);
sroiq_SConcept sriqnormal_edge_filler(slop_arena* arena, types_RoleId r, sroiq_SConcept b, uint8_t negative);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_assertion(slop_arena* arena, owl2_RawEdge e, slop_string what, uint8_t negative);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_same_individual(slop_arena* arena, slop_list_types_Node ns);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_different_individuals(slop_arena* arena, slop_list_types_Node ns);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_disjoint_union(slop_arena* arena, owl2_RawDisjointUnion du);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_axiom(slop_arena* arena, owl2_RawAxiom ax);
int64_t sriqnormal_rep_at(sriqrbox_SriqRbox rb, int64_t n);
types_RoleId sriqnormal_collapse_role(sriqrbox_SriqRbox rb, types_RoleId r);
slop_list_types_RoleId sriqnormal_collapse_word(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_types_RoleId w);
slop_list_sroiq_SConcept sriqnormal_collapse_concepts(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_sroiq_SConcept cs);
sroiq_SConcept sriqnormal_collapse_concept(slop_arena* arena, sriqrbox_SriqRbox rb, sroiq_SConcept c);
uint8_t sriqnormal_trivial_ria(slop_list_types_RoleId w, types_RoleId s);
uint8_t sriqnormal_role_eq_p(types_RoleId a, types_RoleId b);
slop_option_sroiq_SAxiom sriqnormal_collapse_axiom(slop_arena* arena, sriqrbox_SriqRbox rb, sroiq_SAxiom a);
types_RoleId sriqnormal_bottom_role(void);
uint8_t sriqnormal_is_bottom(types_RoleId r);
uint8_t sriqnormal_concept_bottom_p(sroiq_SConcept c);
uint8_t sriqnormal_concepts_bottom_p(slop_list_sroiq_SConcept cs);
uint8_t sriqnormal_axiom_bottom_p(sroiq_SAxiom a);
slop_result_sriqnormal_S0_string sriqnormal_sriq_s0(slop_arena* arena, slop_list_owl2_RawAxiom accepted);
uint8_t sriqnormal_ria_complex(sriqrbox_SriqRbox rb, sroiq_SRia x);
slop_result_list_sroiq_SAxiom_string sriqnormal_sriq_s1(slop_arena* arena, sriqnormal_S0 s0);
sriqnormal_S2State* sriqnormal_new_s2(slop_arena* arena);
uint8_t sriqnormal_emit(slop_arena* arena, sriqnormal_S2State* p, types_DlClause c);
int64_t sriqnormal_fresh_name(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept c);
sroiq_SConcept sriqnormal_concept_of(sriqnormal_S2State* p, int64_t k);
types_DRole sriqnormal_role_name(slop_arena* arena, sriqnormal_S2State* p, types_RoleId r);
slop_string sriqnormal_dname_key(slop_arena* arena, sriqnormal_S2State* p, types_DName n);
slop_string sriqnormal_filler_key(slop_arena* arena, sriqnormal_S2State* p, slop_option_types_DName b);
slop_string sriqnormal_drole_key(slop_arena* arena, sriqnormal_S2State* p, types_DRole r);
types_DRole sriqnormal_srole_of(slop_arena* arena, sriqnormal_S2State* p, types_DRole s, slop_option_types_DName b);
slop_list_int sriqnormal_fn_ids(slop_arena* arena, sriqnormal_S2State* p, slop_string axkey, int64_t n);
slop_list_sroiq_SConcept sriqnormal_nnf_list(slop_arena* arena, slop_list_sroiq_SConcept xs, uint8_t pos);
sroiq_SConcept sriqnormal_nnf(slop_arena* arena, sroiq_SConcept c, uint8_t pos);
slop_option_types_DName sriqnormal_pos_name(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept c);
slop_option_types_DName sriqnormal_neg_name(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept c);
slop_option_types_DName sriqnormal_neg_literal_name(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept lit);
slop_list_sroiq_SConcept sriqnormal_singleton_sc(slop_arena* arena, sroiq_SConcept c);
uint8_t sriqnormal_disjunction(slop_arena* arena, sriqnormal_S2State* p, slop_option_types_DName lhs, slop_option_types_DName extra, sroiq_SConcept e);
uint8_t sriqnormal_define_pos(slop_arena* arena, sriqnormal_S2State* p, types_DName x, sroiq_SConcept e);
uint8_t sriqnormal_define_dl2(slop_arena* arena, sriqnormal_S2State* p, types_DName x, types_RoleId r, int64_t n, sroiq_SConcept f);
uint8_t sriqnormal_s2_gci(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept l, sroiq_SConcept r);
uint8_t sriqnormal_assert_top(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept e);
slop_result_u8_string sriqnormal_s2_ria(slop_arena* arena, sriqnormal_S2State* p, sroiq_SRia x);
uint8_t sriqnormal_s2_dis(slop_arena* arena, sriqnormal_S2State* p, types_RoleId r, types_RoleId s);
uint8_t sriqnormal_counts_ok(sroiq_SConcept c);
uint8_t sriqnormal_counts_list_ok(slop_list_sroiq_SConcept cs);
slop_result_sriqnormal_S2_string sriqnormal_sriq_s2(slop_arena* arena, slop_list_sroiq_SAxiom axs);
slop_string sriqnormal_render_dname(slop_arena* arena, sriqnormal_S2 s2, types_DName n);
slop_string sriqnormal_render_dfiller(slop_arena* arena, sriqnormal_S2 s2, slop_option_types_DName b);
slop_string sriqnormal_render_drole(slop_arena* arena, sriqnormal_S2 s2, types_DRole r);
slop_string sriqnormal_render_dnames(slop_arena* arena, sriqnormal_S2 s2, slop_list_types_DName ns, slop_string sep, slop_string empty);
slop_string sriqnormal_render_dl(slop_arena* arena, sriqnormal_S2 s2, types_DlClause c);

#ifndef SLOP_OPTION_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(sroiq_SAxiom, slop_option_sroiq_SAxiom)
#endif

#ifndef SLOP_OPTION_SRIQNORMAL_S0_DEFINED
#define SLOP_OPTION_SRIQNORMAL_S0_DEFINED
SLOP_OPTION_DEFINE(sriqnormal_S0, slop_option_sriqnormal_S0)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(sroiq_SConcept, slop_option_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_DLCLAUSE_DEFINED
#define SLOP_OPTION_TYPES_DLCLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_DlClause, slop_option_types_DlClause)
#endif

#ifndef SLOP_OPTION_TYPES_DROLE_DEFINED
#define SLOP_OPTION_TYPES_DROLE_DEFINED
SLOP_OPTION_DEFINE(types_DRole, slop_option_types_DRole)
#endif

#ifndef SLOP_OPTION_OPTION_TYPES_DNAME_DEFINED
#define SLOP_OPTION_OPTION_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(slop_option_types_DName, slop_option_option_types_DName)
#endif

#ifndef SLOP_OPTION_TYPES_DNAME_DEFINED
#define SLOP_OPTION_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(types_DName, slop_option_types_DName)
#endif

#ifndef SLOP_OPTION_SRIQNORMAL_S2STATE_DEFINED
#define SLOP_OPTION_SRIQNORMAL_S2STATE_DEFINED
SLOP_OPTION_DEFINE(sriqnormal_S2State, slop_option_sriqnormal_S2State)
#endif

#ifndef SLOP_OPTION_SRIQNORMAL_S2_DEFINED
#define SLOP_OPTION_SRIQNORMAL_S2_DEFINED
SLOP_OPTION_DEFINE(sriqnormal_S2, slop_option_sriqnormal_S2)
#endif


#endif
