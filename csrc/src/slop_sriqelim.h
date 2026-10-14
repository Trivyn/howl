#ifndef SLOP_sriqelim_H
#define SLOP_sriqelim_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_canon.h"
#include "slop_sroiq.h"
#include "slop_sriqrbox.h"
#include "slop_sriqnormal.h"

typedef struct sriqelim_S1 sriqelim_S1;
typedef struct sriqelim_Pending sriqelim_Pending;
typedef struct sriqelim_S1State sriqelim_S1State;

#ifndef SLOP_LIST_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_SROIQ_SAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(sroiq_SAxiom, slop_list_sroiq_SAxiom)
#endif

#ifndef SLOP_LIST_SROIQ_SRIA_DEFINED
#define SLOP_LIST_SROIQ_SRIA_DEFINED
#define SLOP_LIST_SROIQ_SRIA_IMPL_DEFINED
SLOP_LIST_DEFINE(sroiq_SRia, slop_list_sroiq_SRia)
#endif

#ifndef SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(types_RoleId, slop_list_types_RoleId)
#endif

#ifndef SLOP_LIST_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_SROIQ_SCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(sroiq_SConcept, slop_list_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(sroiq_SAxiom, slop_option_sroiq_SAxiom)
#endif

#ifndef SLOP_OPTION_SROIQ_SRIA_DEFINED
#define SLOP_OPTION_SROIQ_SRIA_DEFINED
SLOP_OPTION_DEFINE(sroiq_SRia, slop_option_sroiq_SRia)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(sroiq_SConcept, slop_option_sroiq_SConcept)
#endif

struct sriqelim_S1 {
    slop_list_sroiq_SAxiom axioms;
    slop_list_sroiq_SAxiom omitted;
    int64_t expansions;
};
typedef struct sriqelim_S1 sriqelim_S1;

#ifndef SLOP_OPTION_SRIQELIM_S1_DEFINED
#define SLOP_OPTION_SRIQELIM_S1_DEFINED
SLOP_OPTION_DEFINE(sriqelim_S1, slop_option_sriqelim_S1)
#endif

struct sriqelim_Pending {
    uint8_t forall;
    types_RoleId role;
    sroiq_SConcept filler;
};
typedef struct sriqelim_Pending sriqelim_Pending;

#ifndef SLOP_OPTION_SRIQELIM_PENDING_DEFINED
#define SLOP_OPTION_SRIQELIM_PENDING_DEFINED
SLOP_OPTION_DEFINE(sriqelim_Pending, slop_option_sriqelim_Pending)
#endif

#ifndef SLOP_LIST_SRIQELIM_PENDING_DEFINED
#define SLOP_LIST_SRIQELIM_PENDING_DEFINED
#define SLOP_LIST_SRIQELIM_PENDING_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqelim_Pending, slop_list_sriqelim_Pending)
#endif

struct sriqelim_S1State {
    sriqrbox_SriqRbox rb;
    slop_list_sroiq_SRia rc;
    slop_list_sroiq_SAxiom out;
    slop_map* seen;
    slop_list_sriqelim_Pending queue;
    int64_t count;
    int64_t bound;
    slop_option_string fault;
};
typedef struct sriqelim_S1State sriqelim_S1State;

#ifndef SLOP_OPTION_SRIQELIM_S1STATE_DEFINED
#define SLOP_OPTION_SRIQELIM_S1STATE_DEFINED
SLOP_OPTION_DEFINE(sriqelim_S1State, slop_option_sriqelim_S1State)
#endif

#ifndef SLOP_RESULT_SRIQELIM_S1_STRING_DEFINED
#define SLOP_RESULT_SRIQELIM_S1_STRING_DEFINED
typedef struct { bool is_ok; union { sriqelim_S1 ok; slop_string err; } data; } slop_result_sriqelim_S1_string;
#endif

uint8_t sriqelim_nonsimple(sriqrbox_SriqRbox rb, types_RoleId r);
uint8_t sriqelim_role_eq(types_RoleId a, types_RoleId b);
uint8_t sriqelim_ria_complex(sriqrbox_SriqRbox rb, sroiq_SRia x);
types_RoleId sriqelim_role_at(slop_list_types_RoleId w, int64_t i);
slop_list_types_RoleId sriqelim_slice(slop_arena* arena, slop_list_types_RoleId w, int64_t from, int64_t upto);
slop_list_types_RoleId sriqelim_inv_word(slop_arena* arena, slop_list_types_RoleId w);
slop_list_sroiq_SRia sriqelim_rc_of(slop_arena* arena, sriqrbox_SriqRbox rb, sroiq_SAxiom a);
slop_list_sroiq_SRia sriqelim_build_rc(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_sroiq_SAxiom axs);
uint8_t sriqelim_symmetric(slop_list_sroiq_SRia rc, types_RoleId s);
uint8_t sriqelim_holds_role(slop_list_types_RoleId w, types_RoleId s);
sriqelim_S1State* sriqelim_new_s1(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_sroiq_SRia rc, int64_t bound);
uint8_t sriqelim_emit(slop_arena* arena, sriqelim_S1State* p, sroiq_SAxiom a);
uint8_t sriqelim_emit_gci(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept l, sroiq_SConcept r);
uint8_t sriqelim_fail(sriqelim_S1State* p, slop_string m);
uint8_t sriqelim_going(sriqelim_S1State* p);
sroiq_SConcept sriqelim_atom(slop_arena* arena, sroiq_ElimKind k, types_RoleId r, sroiq_SConcept f);
sroiq_SConcept sriqelim_label_name(slop_arena* arena, uint8_t forall, types_RoleId r, sroiq_SConcept f);
sroiq_SConcept sriqelim_label(slop_arena* arena, sriqelim_S1State* p, uint8_t forall, types_RoleId r, sroiq_SConcept f);
sroiq_SConcept sriqelim_rewrite(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept c, uint8_t pos);
slop_list_sroiq_SConcept sriqelim_rewrite_each(slop_arena* arena, sriqelim_S1State* p, slop_list_sroiq_SConcept xs, uint8_t pos);
sroiq_SConcept sriqelim_rewrite_all(slop_arena* arena, sriqelim_S1State* p, types_RoleId r, sroiq_SConcept f, uint8_t pos);
sroiq_SConcept sriqelim_rewrite_some(slop_arena* arena, sriqelim_S1State* p, types_RoleId r, sroiq_SConcept f, uint8_t pos);
sroiq_SConcept sriqelim_chain_all(slop_arena* arena, slop_list_types_RoleId w, sroiq_SConcept x);
uint8_t sriqelim_item(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept lhs, slop_list_types_RoleId w, sroiq_SConcept x, types_RoleId s);
uint8_t sriqelim_expand_ria(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept i, types_RoleId s, sroiq_SConcept f, slop_list_types_RoleId w);
uint8_t sriqelim_expand1(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept i, types_RoleId s, sroiq_SConcept f);
uint8_t sriqelim_expand(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept i, types_RoleId s, sroiq_SConcept f);
uint8_t sriqelim_expand_key(slop_arena* arena, sriqelim_S1State* p, sriqelim_Pending e);
sriqelim_Pending sriqelim_pending_at(slop_list_sriqelim_Pending xs, int64_t i);
uint8_t sriqelim_drain(slop_arena* arena, sriqelim_S1State* p);
uint8_t sriqelim_s1_init(slop_arena* arena, sriqelim_S1State* p, slop_list_sroiq_SAxiom axs);
uint8_t sriqelim_is_chain(sroiq_SAxiom a);
sriqelim_S1 sriqelim_guarded(slop_arena* arena, slop_list_sroiq_SAxiom axs, int64_t count);
slop_result_sriqelim_S1_string sriqelim_s1_result(slop_arena* arena, sriqnormal_S0 s0, sriqelim_S1State* p);
slop_result_sriqelim_S1_string sriqelim_sriq_s1(slop_arena* arena, sriqnormal_S0 s0, int64_t bound);
uint8_t sriqelim_is_atom(sroiq_SConcept c);
uint8_t sriqelim_item1_p(sroiq_SConcept l, sroiq_SConcept r);
uint8_t sriqelim_labelled_left(sriqrbox_SriqRbox rb, sroiq_SConcept c, uint8_t pos);
uint8_t sriqelim_labelled_any(sriqrbox_SriqRbox rb, slop_list_sroiq_SConcept cs, uint8_t pos);
uint8_t sriqelim_has_axiom(slop_list_sroiq_SAxiom axs, sroiq_SAxiom a);
sroiq_SAxiom sriqelim_def_gci(slop_arena* arena, sroiq_SConcept l, sroiq_SConcept r);
slop_list_sroiq_SAxiom sriqelim_all_axioms(slop_arena* arena, sroiq_SConcept i, types_RoleId r, sroiq_SConcept c);
slop_list_sroiq_SAxiom sriqelim_some_axioms(slop_arena* arena, sroiq_SConcept f, types_RoleId r, sroiq_SConcept c);
slop_list_sroiq_SAxiom sriqelim_atom_axioms(slop_arena* arena, sroiq_SConcept c);
slop_list_sroiq_SConcept sriqelim_atoms_of(slop_arena* arena, sroiq_SConcept c);
slop_list_sroiq_SConcept sriqelim_append_atoms(slop_arena* arena, slop_list_sroiq_SConcept a, slop_list_sroiq_SConcept b);
slop_list_string sriqelim_axiom_problems(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_sroiq_SAxiom axs, sroiq_SAxiom a);
uint8_t sriqelim_same_axioms(slop_list_sroiq_SAxiom a, slop_list_sroiq_SAxiom b);
slop_list_string sriqelim_guarded_problems(slop_arena* arena, slop_list_sroiq_SAxiom s0_axioms, sriqelim_S1 s1);
slop_list_string sriqelim_sriq_s1_invariants(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_sroiq_SAxiom s0_axioms, sriqelim_S1 s1);

#define sriqelim_S1_BOUND (100000)

#ifndef SLOP_OPTION_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(sroiq_SAxiom, slop_option_sroiq_SAxiom)
#endif

#ifndef SLOP_OPTION_SRIQELIM_S1_DEFINED
#define SLOP_OPTION_SRIQELIM_S1_DEFINED
SLOP_OPTION_DEFINE(sriqelim_S1, slop_option_sriqelim_S1)
#endif

#ifndef SLOP_OPTION_SRIQELIM_PENDING_DEFINED
#define SLOP_OPTION_SRIQELIM_PENDING_DEFINED
SLOP_OPTION_DEFINE(sriqelim_Pending, slop_option_sriqelim_Pending)
#endif

#ifndef SLOP_OPTION_SROIQ_SRIA_DEFINED
#define SLOP_OPTION_SROIQ_SRIA_DEFINED
SLOP_OPTION_DEFINE(sroiq_SRia, slop_option_sroiq_SRia)
#endif

#ifndef SLOP_OPTION_SRIQELIM_S1STATE_DEFINED
#define SLOP_OPTION_SRIQELIM_S1STATE_DEFINED
SLOP_OPTION_DEFINE(sriqelim_S1State, slop_option_sriqelim_S1State)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(sroiq_SConcept, slop_option_sroiq_SConcept)
#endif


#endif
