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
#include "slop_sriqrbox.h"

typedef struct sriqnormal_S0 sriqnormal_S0;

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

struct sriqnormal_S0 {
    slop_list_sroiq_SAxiom axioms;
    sriqrbox_SriqRbox rbox;
};
typedef struct sriqnormal_S0 sriqnormal_S0;

#ifndef SLOP_OPTION_SRIQNORMAL_S0_DEFINED
#define SLOP_OPTION_SRIQNORMAL_S0_DEFINED
SLOP_OPTION_DEFINE(sriqnormal_S0, slop_option_sriqnormal_S0)
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


#endif
