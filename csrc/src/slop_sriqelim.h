#ifndef SLOP_sriqelim_H
#define SLOP_sriqelim_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_canon.h"
#include "slop_sroiq.h"
#include "slop_sriqrbox.h"
#include "slop_sriqnormal.h"

typedef struct howl_sriqelim_S1 howl_sriqelim_S1;
typedef struct howl_sriqelim_Pending howl_sriqelim_Pending;
typedef struct howl_sriqelim_S1State howl_sriqelim_S1State;

#ifndef SLOP_LIST_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sroiq_SAxiom, slop_list_howl_sroiq_SAxiom)
#endif

#ifndef SLOP_LIST_HOWL_SROIQ_SRIA_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SRIA_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SRIA_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sroiq_SRia, slop_list_howl_sroiq_SRia)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_RoleId, slop_list_howl_types_RoleId)
#endif

#ifndef SLOP_LIST_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sroiq_SConcept, slop_list_howl_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SAxiom, slop_option_howl_sroiq_SAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SRIA_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SRIA_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SRia, slop_option_howl_sroiq_SRia)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SConcept, slop_option_howl_sroiq_SConcept)
#endif

struct howl_sriqelim_S1 {
    slop_list_howl_sroiq_SAxiom axioms;
    slop_list_howl_sroiq_SAxiom omitted;
    int64_t expansions;
};
typedef struct howl_sriqelim_S1 howl_sriqelim_S1;

#ifndef SLOP_OPTION_HOWL_SRIQELIM_S1_DEFINED
#define SLOP_OPTION_HOWL_SRIQELIM_S1_DEFINED
SLOP_OPTION_DEFINE(howl_sriqelim_S1, slop_option_howl_sriqelim_S1)
#endif

struct howl_sriqelim_Pending {
    uint8_t forall;
    howl_types_RoleId role;
    howl_sroiq_SConcept filler;
};
typedef struct howl_sriqelim_Pending howl_sriqelim_Pending;

#ifndef SLOP_OPTION_HOWL_SRIQELIM_PENDING_DEFINED
#define SLOP_OPTION_HOWL_SRIQELIM_PENDING_DEFINED
SLOP_OPTION_DEFINE(howl_sriqelim_Pending, slop_option_howl_sriqelim_Pending)
#endif

#ifndef SLOP_LIST_HOWL_SRIQELIM_PENDING_DEFINED
#define SLOP_LIST_HOWL_SRIQELIM_PENDING_DEFINED
#define SLOP_LIST_HOWL_SRIQELIM_PENDING_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqelim_Pending, slop_list_howl_sriqelim_Pending)
#endif

struct howl_sriqelim_S1State {
    howl_sriqrbox_SriqRbox rb;
    slop_list_howl_sroiq_SRia rc;
    slop_list_howl_sroiq_SAxiom out;
    slop_map* seen;
    slop_list_howl_sriqelim_Pending queue;
    int64_t count;
    int64_t bound;
    slop_option_string fault;
};
typedef struct howl_sriqelim_S1State howl_sriqelim_S1State;

#ifndef SLOP_OPTION_HOWL_SRIQELIM_S1STATE_DEFINED
#define SLOP_OPTION_HOWL_SRIQELIM_S1STATE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqelim_S1State, slop_option_howl_sriqelim_S1State)
#endif

#ifndef SLOP_RESULT_HOWL_SRIQELIM_S1_STRING_DEFINED
#define SLOP_RESULT_HOWL_SRIQELIM_S1_STRING_DEFINED
typedef struct { bool is_ok; union { howl_sriqelim_S1 ok; slop_string err; } data; } slop_result_howl_sriqelim_S1_string;
#endif

uint8_t howl_sriqelim_nonsimple(howl_sriqrbox_SriqRbox rb, howl_types_RoleId r);
uint8_t howl_sriqelim_role_eq(howl_types_RoleId a, howl_types_RoleId b);
uint8_t howl_sriqelim_ria_complex(howl_sriqrbox_SriqRbox rb, howl_sroiq_SRia x);
howl_types_RoleId howl_sriqelim_role_at(slop_list_howl_types_RoleId w, int64_t i);
slop_list_howl_types_RoleId howl_sriqelim_slice(slop_arena* arena, slop_list_howl_types_RoleId w, int64_t from, int64_t upto);
slop_list_howl_types_RoleId howl_sriqelim_inv_word(slop_arena* arena, slop_list_howl_types_RoleId w);
slop_list_howl_sroiq_SRia howl_sriqelim_rc_of(slop_arena* arena, howl_sriqrbox_SriqRbox rb, howl_sroiq_SAxiom a);
slop_list_howl_sroiq_SRia howl_sriqelim_build_rc(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SAxiom axs);
uint8_t howl_sriqelim_symmetric(slop_list_howl_sroiq_SRia rc, howl_types_RoleId s);
uint8_t howl_sriqelim_holds_role(slop_list_howl_types_RoleId w, howl_types_RoleId s);
howl_sriqelim_S1State* howl_sriqelim_new_s1(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SRia rc, int64_t bound);
uint8_t howl_sriqelim_emit(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SAxiom a);
uint8_t howl_sriqelim_emit_gci(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept l, howl_sroiq_SConcept r);
uint8_t howl_sriqelim_fail(howl_sriqelim_S1State* p, slop_string m);
uint8_t howl_sriqelim_going(howl_sriqelim_S1State* p);
howl_sroiq_SConcept howl_sriqelim_atom(slop_arena* arena, howl_sroiq_ElimKind k, howl_types_RoleId r, howl_sroiq_SConcept f);
howl_sroiq_SConcept howl_sriqelim_label_name(slop_arena* arena, uint8_t forall, howl_types_RoleId r, howl_sroiq_SConcept f);
howl_sroiq_SConcept howl_sriqelim_label(slop_arena* arena, howl_sriqelim_S1State* p, uint8_t forall, howl_types_RoleId r, howl_sroiq_SConcept f);
howl_sroiq_SConcept howl_sriqelim_rewrite(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept c, uint8_t pos);
slop_list_howl_sroiq_SConcept howl_sriqelim_rewrite_each(slop_arena* arena, howl_sriqelim_S1State* p, slop_list_howl_sroiq_SConcept xs, uint8_t pos);
howl_sroiq_SConcept howl_sriqelim_rewrite_all(slop_arena* arena, howl_sriqelim_S1State* p, howl_types_RoleId r, howl_sroiq_SConcept f, uint8_t pos);
howl_sroiq_SConcept howl_sriqelim_rewrite_some(slop_arena* arena, howl_sriqelim_S1State* p, howl_types_RoleId r, howl_sroiq_SConcept f, uint8_t pos);
howl_sroiq_SConcept howl_sriqelim_chain_all(slop_arena* arena, slop_list_howl_types_RoleId w, howl_sroiq_SConcept x);
uint8_t howl_sriqelim_item(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept lhs, slop_list_howl_types_RoleId w, howl_sroiq_SConcept x, howl_types_RoleId s);
uint8_t howl_sriqelim_expand_ria(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept i, howl_types_RoleId s, howl_sroiq_SConcept f, slop_list_howl_types_RoleId w);
uint8_t howl_sriqelim_expand1(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept i, howl_types_RoleId s, howl_sroiq_SConcept f);
uint8_t howl_sriqelim_expand(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept i, howl_types_RoleId s, howl_sroiq_SConcept f);
uint8_t howl_sriqelim_expand_key(slop_arena* arena, howl_sriqelim_S1State* p, howl_sriqelim_Pending e);
howl_sriqelim_Pending howl_sriqelim_pending_at(slop_list_howl_sriqelim_Pending xs, int64_t i);
uint8_t howl_sriqelim_drain(slop_arena* arena, howl_sriqelim_S1State* p);
uint8_t howl_sriqelim_s1_init(slop_arena* arena, howl_sriqelim_S1State* p, slop_list_howl_sroiq_SAxiom axs);
uint8_t howl_sriqelim_is_chain(howl_sroiq_SAxiom a);
howl_sriqelim_S1 howl_sriqelim_guarded(slop_arena* arena, slop_list_howl_sroiq_SAxiom axs, int64_t count);
slop_result_howl_sriqelim_S1_string howl_sriqelim_s1_result(slop_arena* arena, howl_sriqnormal_S0 s0, howl_sriqelim_S1State* p);
slop_result_howl_sriqelim_S1_string howl_sriqelim_sriq_s1(slop_arena* arena, howl_sriqnormal_S0 s0, int64_t bound);
uint8_t howl_sriqelim_is_atom(howl_sroiq_SConcept c);
uint8_t howl_sriqelim_item1_p(howl_sroiq_SConcept l, howl_sroiq_SConcept r);
uint8_t howl_sriqelim_labelled_left(howl_sriqrbox_SriqRbox rb, howl_sroiq_SConcept c, uint8_t pos);
uint8_t howl_sriqelim_labelled_any(howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SConcept cs, uint8_t pos);
uint8_t howl_sriqelim_has_axiom(slop_list_howl_sroiq_SAxiom axs, howl_sroiq_SAxiom a);
howl_sroiq_SAxiom howl_sriqelim_def_gci(slop_arena* arena, howl_sroiq_SConcept l, howl_sroiq_SConcept r);
slop_list_howl_sroiq_SAxiom howl_sriqelim_all_axioms(slop_arena* arena, howl_sroiq_SConcept i, howl_types_RoleId r, howl_sroiq_SConcept c);
slop_list_howl_sroiq_SAxiom howl_sriqelim_some_axioms(slop_arena* arena, howl_sroiq_SConcept f, howl_types_RoleId r, howl_sroiq_SConcept c);
slop_list_howl_sroiq_SAxiom howl_sriqelim_atom_axioms(slop_arena* arena, howl_sroiq_SConcept c);
slop_list_howl_sroiq_SConcept howl_sriqelim_atoms_of(slop_arena* arena, howl_sroiq_SConcept c);
slop_list_howl_sroiq_SConcept howl_sriqelim_append_atoms(slop_arena* arena, slop_list_howl_sroiq_SConcept a, slop_list_howl_sroiq_SConcept b);
slop_list_string howl_sriqelim_axiom_problems(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SAxiom axs, howl_sroiq_SAxiom a);
uint8_t howl_sriqelim_same_axioms(slop_list_howl_sroiq_SAxiom a, slop_list_howl_sroiq_SAxiom b);
slop_list_string howl_sriqelim_guarded_problems(slop_arena* arena, slop_list_howl_sroiq_SAxiom s0_axioms, howl_sriqelim_S1 s1);
slop_list_string howl_sriqelim_sriq_s1_invariants(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SAxiom s0_axioms, howl_sriqelim_S1 s1);

#define howl_sriqelim_S1_BOUND (100000)

#ifndef SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SAxiom, slop_option_howl_sroiq_SAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQELIM_S1_DEFINED
#define SLOP_OPTION_HOWL_SRIQELIM_S1_DEFINED
SLOP_OPTION_DEFINE(howl_sriqelim_S1, slop_option_howl_sriqelim_S1)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQELIM_PENDING_DEFINED
#define SLOP_OPTION_HOWL_SRIQELIM_PENDING_DEFINED
SLOP_OPTION_DEFINE(howl_sriqelim_Pending, slop_option_howl_sriqelim_Pending)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SRIA_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SRIA_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SRia, slop_option_howl_sroiq_SRia)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQELIM_S1STATE_DEFINED
#define SLOP_OPTION_HOWL_SRIQELIM_S1STATE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqelim_S1State, slop_option_howl_sriqelim_S1State)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SConcept, slop_option_howl_sroiq_SConcept)
#endif


#endif
