#ifndef SLOP_kscnormal_H
#define SLOP_kscnormal_H

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
#include "slop_naming.h"

typedef struct howl_kscnormal_KscOutput howl_kscnormal_KscOutput;
typedef struct howl_kscnormal_KscState howl_kscnormal_KscState;

#ifndef SLOP_LIST_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KSCAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KscAxiom, slop_list_howl_types_KscAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Node, slop_list_howl_types_Node)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawConcept, slop_list_howl_owl2_RawConcept)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawAxiom, slop_list_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscAxiom, slop_option_howl_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

struct howl_kscnormal_KscOutput {
    slop_list_howl_types_KscAxiom axioms;
    int64_t fresh_count;
    int64_t fresh_role_count;
};
typedef struct howl_kscnormal_KscOutput howl_kscnormal_KscOutput;

#ifndef SLOP_OPTION_HOWL_KSCNORMAL_KSCOUTPUT_DEFINED
#define SLOP_OPTION_HOWL_KSCNORMAL_KSCOUTPUT_DEFINED
SLOP_OPTION_DEFINE(howl_kscnormal_KscOutput, slop_option_howl_kscnormal_KscOutput)
#endif

struct howl_kscnormal_KscState {
    slop_list_howl_types_KscAxiom axioms;
    howl_naming_Registry* registry;
};
typedef struct howl_kscnormal_KscState howl_kscnormal_KscState;

#ifndef SLOP_OPTION_HOWL_KSCNORMAL_KSCSTATE_DEFINED
#define SLOP_OPTION_HOWL_KSCNORMAL_KSCSTATE_DEFINED
SLOP_OPTION_DEFINE(howl_kscnormal_KscState, slop_option_howl_kscnormal_KscState)
#endif

howl_kscnormal_KscState* howl_kscnormal_new_ksc_state(slop_arena* arena);
uint8_t howl_kscnormal_k_emit(slop_arena* arena, howl_kscnormal_KscState* p, howl_types_KscAxiom ax);
howl_types_KName howl_kscnormal_mint(slop_arena* arena, howl_kscnormal_KscState* p, slop_string key);
howl_types_KName howl_kscnormal_top_name(void);
howl_types_KName howl_kscnormal_bottom_name(void);
howl_types_KTerm howl_kscnormal_as_term(howl_types_KName k);
slop_rdf_rdf_IRI howl_kscnormal_node_iri(howl_types_Node n);
howl_types_KTerm howl_kscnormal_node_term(howl_types_Node n);
slop_string howl_kscnormal_name_key(slop_arena* arena, howl_types_KName k);
slop_string howl_kscnormal_term_key(slop_arena* arena, howl_types_KTerm t);
howl_owl2_RawConcept* howl_kscnormal_box(slop_arena* arena, howl_owl2_RawConcept c);
howl_owl2_RawConcept howl_kscnormal_node_of(howl_types_Node n);
howl_types_KName howl_kscnormal_nominal_neg(slop_arena* arena, howl_kscnormal_KscState* p, slop_rdf_rdf_IRI a);
howl_types_KName howl_kscnormal_nominal_pos(slop_arena* arena, howl_kscnormal_KscState* p, slop_rdf_rdf_IRI a);
slop_option_howl_types_Node howl_kscnormal_single_individual(slop_list_howl_types_Node ns);
howl_types_KName howl_kscnormal_neg_name(slop_arena* arena, howl_kscnormal_KscState* p, howl_types_Node n);
howl_types_KName howl_kscnormal_pos_name(slop_arena* arena, howl_kscnormal_KscState* p, howl_types_Node n);
howl_types_KName howl_kscnormal_neg_atom(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawConcept c);
howl_types_KName howl_kscnormal_fold_conjuncts(slop_arena* arena, howl_kscnormal_KscState* p, slop_list_howl_owl2_RawConcept conj, int64_t n);
howl_types_KName howl_kscnormal_pos_atom(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawConcept c);
howl_owl2_RawConcept howl_kscnormal_name_concept(howl_types_KName k);
howl_types_KName howl_kscnormal_lhs_name(slop_arena* arena, howl_kscnormal_KscState* p, slop_list_howl_owl2_RawConcept conj, int64_t n);
howl_types_KTerm howl_kscnormal_sub_lhs(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawConcept c);
howl_types_KName howl_kscnormal_class_target(slop_arena* arena, howl_kscnormal_KscState* p, howl_types_KTerm t);
uint8_t howl_kscnormal_emit_inclusion(slop_arena* arena, howl_kscnormal_KscState* p, slop_list_howl_owl2_RawConcept conj, int64_t n, howl_types_KTerm target);
int64_t howl_kscnormal_witness(slop_arena* arena, howl_kscnormal_KscState* p, howl_types_KName a, howl_types_RoleId r, howl_types_KName b);
uint8_t howl_kscnormal_normalize_gci(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawConcept lhs, howl_owl2_RawConcept rhs);
uint8_t howl_kscnormal_decompose_chain(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawChain ch);
uint8_t howl_kscnormal_normalize_axiom(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawAxiom ax);
howl_types_Node howl_kscnormal_node_at_or_top(slop_list_howl_types_Node ns, int64_t i);
howl_types_RoleId howl_kscnormal_bottom_role(void);
uint8_t howl_kscnormal_axiom_mentions_role(howl_types_KscAxiom ax, howl_types_RoleId r);
uint8_t howl_kscnormal_mentions_bottom_role(slop_list_howl_types_KscAxiom axs);
howl_kscnormal_KscOutput howl_kscnormal_normalize_ksc(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
slop_string howl_kscnormal_render_ksc_axiom(slop_arena* arena, howl_types_KscAxiom ax);
slop_string howl_kscnormal_fact2(slop_arena* arena, slop_string name, slop_string x, slop_string y);
slop_string howl_kscnormal_fact3(slop_arena* arena, slop_string name, slop_string x, slop_string y, slop_string z);
slop_string howl_kscnormal_fact4(slop_arena* arena, slop_string name, slop_string x, slop_string y, slop_string z, slop_string w);
howl_types_KName howl_kscnormal_copy_kname(slop_arena* arena, howl_types_KName n);
howl_types_KTerm howl_kscnormal_copy_kterm(slop_arena* arena, howl_types_KTerm t);
howl_types_KscAxiom howl_kscnormal_copy_ksc_axiom(slop_arena* arena, howl_types_KscAxiom ax);
slop_list_howl_types_KscAxiom howl_kscnormal_copy_ksc_axioms(slop_arena* arena, slop_list_howl_types_KscAxiom axs);

#ifndef SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscAxiom, slop_option_howl_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_KSCNORMAL_KSCOUTPUT_DEFINED
#define SLOP_OPTION_HOWL_KSCNORMAL_KSCOUTPUT_DEFINED
SLOP_OPTION_DEFINE(howl_kscnormal_KscOutput, slop_option_howl_kscnormal_KscOutput)
#endif

#ifndef SLOP_OPTION_HOWL_KSCNORMAL_KSCSTATE_DEFINED
#define SLOP_OPTION_HOWL_KSCNORMAL_KSCSTATE_DEFINED
SLOP_OPTION_DEFINE(howl_kscnormal_KscState, slop_option_howl_kscnormal_KscState)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif


#endif
