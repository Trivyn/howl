#ifndef SLOP_kscnormal_H
#define SLOP_kscnormal_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"
#include "slop_owl2.h"
#include "slop_naming.h"

typedef struct kscnormal_KscOutput kscnormal_KscOutput;
typedef struct kscnormal_KscState kscnormal_KscState;

#ifndef SLOP_LIST_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_TYPES_KSCAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KscAxiom, slop_list_types_KscAxiom)
#endif

#ifndef SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Node, slop_list_types_Node)
#endif

#ifndef SLOP_LIST_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawConcept, slop_list_owl2_RawConcept)
#endif

#ifndef SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawAxiom, slop_list_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

struct kscnormal_KscOutput {
    slop_list_types_KscAxiom axioms;
    int64_t fresh_count;
    int64_t fresh_role_count;
};
typedef struct kscnormal_KscOutput kscnormal_KscOutput;

#ifndef SLOP_OPTION_KSCNORMAL_KSCOUTPUT_DEFINED
#define SLOP_OPTION_KSCNORMAL_KSCOUTPUT_DEFINED
SLOP_OPTION_DEFINE(kscnormal_KscOutput, slop_option_kscnormal_KscOutput)
#endif

struct kscnormal_KscState {
    slop_list_types_KscAxiom axioms;
    naming_Registry* registry;
};
typedef struct kscnormal_KscState kscnormal_KscState;

#ifndef SLOP_OPTION_KSCNORMAL_KSCSTATE_DEFINED
#define SLOP_OPTION_KSCNORMAL_KSCSTATE_DEFINED
SLOP_OPTION_DEFINE(kscnormal_KscState, slop_option_kscnormal_KscState)
#endif

kscnormal_KscState* kscnormal_new_ksc_state(slop_arena* arena);
uint8_t kscnormal_k_emit(slop_arena* arena, kscnormal_KscState* p, types_KscAxiom ax);
types_KName kscnormal_mint(slop_arena* arena, kscnormal_KscState* p, slop_string key);
types_KName kscnormal_top_name(void);
types_KName kscnormal_bottom_name(void);
types_KTerm kscnormal_as_term(types_KName k);
rdf_IRI kscnormal_node_iri(types_Node n);
types_KTerm kscnormal_node_term(types_Node n);
slop_string kscnormal_name_key(slop_arena* arena, types_KName k);
slop_string kscnormal_term_key(slop_arena* arena, types_KTerm t);
owl2_RawConcept* kscnormal_box(slop_arena* arena, owl2_RawConcept c);
owl2_RawConcept kscnormal_node_of(types_Node n);
types_KName kscnormal_nominal_neg(slop_arena* arena, kscnormal_KscState* p, rdf_IRI a);
types_KName kscnormal_nominal_pos(slop_arena* arena, kscnormal_KscState* p, rdf_IRI a);
slop_option_types_Node kscnormal_single_individual(slop_list_types_Node ns);
types_KName kscnormal_neg_name(slop_arena* arena, kscnormal_KscState* p, types_Node n);
types_KName kscnormal_pos_name(slop_arena* arena, kscnormal_KscState* p, types_Node n);
types_KName kscnormal_neg_atom(slop_arena* arena, kscnormal_KscState* p, owl2_RawConcept c);
types_KName kscnormal_fold_conjuncts(slop_arena* arena, kscnormal_KscState* p, slop_list_owl2_RawConcept conj, int64_t n);
types_KName kscnormal_pos_atom(slop_arena* arena, kscnormal_KscState* p, owl2_RawConcept c);
owl2_RawConcept kscnormal_name_concept(types_KName k);
types_KName kscnormal_lhs_name(slop_arena* arena, kscnormal_KscState* p, slop_list_owl2_RawConcept conj, int64_t n);
types_KTerm kscnormal_sub_lhs(slop_arena* arena, kscnormal_KscState* p, owl2_RawConcept c);
types_KName kscnormal_class_target(slop_arena* arena, kscnormal_KscState* p, types_KTerm t);
uint8_t kscnormal_emit_inclusion(slop_arena* arena, kscnormal_KscState* p, slop_list_owl2_RawConcept conj, int64_t n, types_KTerm target);
int64_t kscnormal_witness(slop_arena* arena, kscnormal_KscState* p, types_KName a, types_RoleId r, types_KName b);
uint8_t kscnormal_normalize_gci(slop_arena* arena, kscnormal_KscState* p, owl2_RawConcept lhs, owl2_RawConcept rhs);
uint8_t kscnormal_decompose_chain(slop_arena* arena, kscnormal_KscState* p, owl2_RawChain ch);
uint8_t kscnormal_normalize_axiom(slop_arena* arena, kscnormal_KscState* p, owl2_RawAxiom ax);
types_Node kscnormal_node_at_or_top(slop_list_types_Node ns, int64_t i);
types_RoleId kscnormal_bottom_role(void);
uint8_t kscnormal_axiom_mentions_role(types_KscAxiom ax, types_RoleId r);
uint8_t kscnormal_mentions_bottom_role(slop_list_types_KscAxiom axs);
kscnormal_KscOutput kscnormal_normalize_ksc(slop_arena* arena, slop_list_owl2_RawAxiom axs);
slop_string kscnormal_render_ksc_axiom(slop_arena* arena, types_KscAxiom ax);
slop_string kscnormal_fact2(slop_arena* arena, slop_string name, slop_string x, slop_string y);
slop_string kscnormal_fact3(slop_arena* arena, slop_string name, slop_string x, slop_string y, slop_string z);
slop_string kscnormal_fact4(slop_arena* arena, slop_string name, slop_string x, slop_string y, slop_string z, slop_string w);
types_KName kscnormal_copy_kname(slop_arena* arena, types_KName n);
types_KTerm kscnormal_copy_kterm(slop_arena* arena, types_KTerm t);
types_KscAxiom kscnormal_copy_ksc_axiom(slop_arena* arena, types_KscAxiom ax);
slop_list_types_KscAxiom kscnormal_copy_ksc_axioms(slop_arena* arena, slop_list_types_KscAxiom axs);

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_KSCNORMAL_KSCOUTPUT_DEFINED
#define SLOP_OPTION_KSCNORMAL_KSCOUTPUT_DEFINED
SLOP_OPTION_DEFINE(kscnormal_KscOutput, slop_option_kscnormal_KscOutput)
#endif

#ifndef SLOP_OPTION_KSCNORMAL_KSCSTATE_DEFINED
#define SLOP_OPTION_KSCNORMAL_KSCSTATE_DEFINED
SLOP_OPTION_DEFINE(kscnormal_KscState, slop_option_kscnormal_KscState)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif


#endif
