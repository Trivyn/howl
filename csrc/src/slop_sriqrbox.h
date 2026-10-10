#ifndef SLOP_sriqrbox_H
#define SLOP_sriqrbox_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"
#include "slop_owl2.h"
#include "slop_canon.h"

typedef struct sriqrbox_Ria sriqrbox_Ria;
typedef struct sriqrbox_Csr sriqrbox_Csr;
typedef struct sriqrbox_SriqRbox sriqrbox_SriqRbox;
typedef struct sriqrbox_Edges sriqrbox_Edges;

#ifndef SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_IMPL_DEFINED
SLOP_LIST_DEFINE(uint8_t, slop_list_u8)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(types_RoleId, slop_list_types_RoleId)
#endif

#ifndef SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawAxiom, slop_list_owl2_RawAxiom)
#endif

#ifndef SLOP_LIST_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawConcept, slop_list_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

struct sriqrbox_Ria {
    slop_list_int word;
    int64_t super;
};
typedef struct sriqrbox_Ria sriqrbox_Ria;

#ifndef SLOP_OPTION_SRIQRBOX_RIA_DEFINED
#define SLOP_OPTION_SRIQRBOX_RIA_DEFINED
SLOP_OPTION_DEFINE(sriqrbox_Ria, slop_option_sriqrbox_Ria)
#endif

#ifndef SLOP_LIST_SRIQRBOX_RIA_DEFINED
#define SLOP_LIST_SRIQRBOX_RIA_DEFINED
#define SLOP_LIST_SRIQRBOX_RIA_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqrbox_Ria, slop_list_sriqrbox_Ria)
#endif

struct sriqrbox_Csr {
    slop_list_int off;
    slop_list_int adj;
};
typedef struct sriqrbox_Csr sriqrbox_Csr;

#ifndef SLOP_OPTION_SRIQRBOX_CSR_DEFINED
#define SLOP_OPTION_SRIQRBOX_CSR_DEFINED
SLOP_OPTION_DEFINE(sriqrbox_Csr, slop_option_sriqrbox_Csr)
#endif

struct sriqrbox_SriqRbox {
    slop_list_types_RoleId props;
    slop_list_u8 nonsimple;
    slop_list_int rep;
    slop_list_sriqrbox_Ria rias;
    uint8_t regular;
};
typedef struct sriqrbox_SriqRbox sriqrbox_SriqRbox;

#ifndef SLOP_OPTION_SRIQRBOX_SRIQRBOX_DEFINED
#define SLOP_OPTION_SRIQRBOX_SRIQRBOX_DEFINED
SLOP_OPTION_DEFINE(sriqrbox_SriqRbox, slop_option_sriqrbox_SriqRbox)
#endif

struct sriqrbox_Edges {
    slop_list_int src;
    slop_list_int dst;
};
typedef struct sriqrbox_Edges sriqrbox_Edges;

#ifndef SLOP_OPTION_SRIQRBOX_EDGES_DEFINED
#define SLOP_OPTION_SRIQRBOX_EDGES_DEFINED
SLOP_OPTION_DEFINE(sriqrbox_Edges, slop_option_sriqrbox_Edges)
#endif

int64_t sriqrbox_prop_idx(slop_list_types_RoleId props, types_RoleId r);
uint8_t sriqrbox_prop_new(slop_list_types_RoleId props, types_RoleId r);
types_RoleId sriqrbox_prop_at(slop_list_types_RoleId xs, int64_t i);
slop_list_types_RoleId sriqrbox_sort_props(slop_arena* arena, slop_list_types_RoleId xs);
slop_list_u8 sriqrbox_bools_new(slop_arena* arena, int64_t n);
uint8_t sriqrbox_bool_at(slop_list_u8 m, int64_t i);
types_RoleId sriqrbox_node_role(slop_list_types_RoleId props, int64_t n);
slop_list_int sriqrbox_ints_new(slop_arena* arena, int64_t n, int64_t v);
int64_t sriqrbox_int_at(slop_list_int xs, int64_t i);
int64_t sriqrbox_inv_node(int64_t n);
int64_t sriqrbox_sriq_node(slop_list_types_RoleId props, types_RoleId r);
slop_option_types_RoleId sriqrbox_property_of(types_RoleId r);
slop_list_types_RoleId sriqrbox_ria_roles(slop_arena* arena, owl2_RawAxiom ax);
uint8_t sriqrbox_is_sriq_ria(owl2_RawAxiom ax);
slop_list_types_RoleId sriqrbox_sriq_props(slop_arena* arena, slop_list_owl2_RawAxiom axs);
sriqrbox_Ria sriqrbox_ria_of(slop_arena* arena, int64_t x, int64_t y);
slop_list_sriqrbox_Ria sriqrbox_no_rias(slop_arena* arena);
slop_list_sriqrbox_Ria sriqrbox_rias_sub(slop_arena* arena, slop_list_types_RoleId props, types_RoleId a, types_RoleId b);
slop_list_sriqrbox_Ria sriqrbox_rias_chain(slop_arena* arena, slop_list_types_RoleId props, owl2_RawChain ch);
slop_list_sriqrbox_Ria sriqrbox_rias_equivalent(slop_arena* arena, slop_list_types_RoleId props, slop_list_types_RoleId rs);
slop_list_sriqrbox_Ria sriqrbox_rias_inverse(slop_arena* arena, slop_list_types_RoleId props, types_RoleId a, types_RoleId b);
slop_list_sriqrbox_Ria sriqrbox_rias_symmetric(slop_arena* arena, slop_list_types_RoleId props, owl2_PropCharacteristic c, types_RoleId r);
slop_list_sriqrbox_Ria sriqrbox_rias_of(slop_arena* arena, slop_list_types_RoleId props, owl2_RawAxiom ax);
slop_list_sriqrbox_Ria sriqrbox_sriq_rias(slop_arena* arena, slop_list_types_RoleId props, slop_list_owl2_RawAxiom axs);
slop_list_int sriqrbox_sriq_nodes(slop_arena* arena, slop_list_types_RoleId props, slop_list_types_RoleId rs);
uint8_t sriqrbox_all_nodes(slop_list_int ns);
sriqrbox_Csr sriqrbox_csr_build(slop_arena* arena, int64_t n, slop_list_int src, slop_list_int dst);
slop_list_int sriqrbox_targets(slop_arena* arena, sriqrbox_Csr g, int64_t v);
slop_list_u8 sriqrbox_csr_reach(slop_arena* arena, sriqrbox_Csr g, int64_t n, slop_list_int starts);
uint8_t sriqrbox_in_both(slop_list_u8 f, slop_list_u8 b, int64_t u);
int64_t sriqrbox_least_prop_in(slop_list_u8 f, slop_list_u8 b, int64_t n);
int64_t sriqrbox_component_rep(slop_list_u8 f, slop_list_u8 b, int64_t m);
uint8_t sriqrbox_mark_component(slop_list_int rep, slop_list_u8 f, slop_list_u8 b, int64_t n, int64_t r);
uint8_t sriqrbox_rep_component(slop_arena* arena, sriqrbox_Csr fwd, sriqrbox_Csr bwd, int64_t n, slop_list_int rep, int64_t v);
slop_list_int sriqrbox_sriq_reps(slop_arena* arena, sriqrbox_Csr fwd, sriqrbox_Csr bwd, int64_t n);
slop_list_int sriqrbox_word_slice(slop_arena* arena, slop_list_int w, int64_t from, int64_t upto);
uint8_t sriqrbox_ints_subset(slop_list_int a, slop_list_int b);
slop_list_int sriqrbox_ria_constraints(slop_arena* arena, slop_list_int w, int64_t s);
slop_list_int sriqrbox_inv_word(slop_arena* arena, slop_list_int w);
slop_list_int sriqrbox_rep_word(slop_arena* arena, slop_list_int w, slop_list_int rep);
slop_list_int sriqrbox_indegrees(slop_arena* arena, sriqrbox_Csr g, int64_t n);
uint8_t sriqrbox_csr_acyclic(slop_arena* arena, sriqrbox_Csr g, int64_t n);
sriqrbox_SriqRbox sriqrbox_sriq_rbox_none(slop_arena* arena);
sriqrbox_Edges sriqrbox_hierarchy_edges(slop_arena* arena, slop_list_sriqrbox_Ria rias);
slop_list_int sriqrbox_composite_seeds(slop_arena* arena, slop_list_types_RoleId props, slop_list_sriqrbox_Ria rias);
sriqrbox_Edges sriqrbox_constraint_edges(slop_arena* arena, slop_list_sriqrbox_Ria rias, slop_list_u8 nonsimple, slop_list_int rep);
sriqrbox_SriqRbox sriqrbox_sriq_rbox(slop_arena* arena, slop_list_owl2_RawAxiom axs);
uint8_t sriqrbox_sriq_role_simple(sriqrbox_SriqRbox rb, types_RoleId r);
uint8_t sriqrbox_is_bottom_role(types_RoleId r);
uint8_t sriqrbox_sriq_concept_simple(sriqrbox_SriqRbox rb, owl2_RawConcept c);
uint8_t sriqrbox_sriq_concepts_simple(sriqrbox_SriqRbox rb, slop_list_owl2_RawConcept cs);
uint8_t sriqrbox_sriq_axiom_simple(sriqrbox_SriqRbox rb, owl2_RawAxiom ax);

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_SRIQRBOX_RIA_DEFINED
#define SLOP_OPTION_SRIQRBOX_RIA_DEFINED
SLOP_OPTION_DEFINE(sriqrbox_Ria, slop_option_sriqrbox_Ria)
#endif

#ifndef SLOP_OPTION_SRIQRBOX_CSR_DEFINED
#define SLOP_OPTION_SRIQRBOX_CSR_DEFINED
SLOP_OPTION_DEFINE(sriqrbox_Csr, slop_option_sriqrbox_Csr)
#endif

#ifndef SLOP_OPTION_SRIQRBOX_SRIQRBOX_DEFINED
#define SLOP_OPTION_SRIQRBOX_SRIQRBOX_DEFINED
SLOP_OPTION_DEFINE(sriqrbox_SriqRbox, slop_option_sriqrbox_SriqRbox)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_SRIQRBOX_EDGES_DEFINED
#define SLOP_OPTION_SRIQRBOX_EDGES_DEFINED
SLOP_OPTION_DEFINE(sriqrbox_Edges, slop_option_sriqrbox_Edges)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif


#endif
