#ifndef SLOP_sriq_H
#define SLOP_sriq_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_sriqclauses.h"
#include "slop_sriqorder.h"

typedef struct sriq_Premise sriq_Premise;
typedef struct sriq_RConcl sriq_RConcl;
typedef struct sriq_Subst sriq_Subst;
typedef struct sriq_Cands sriq_Cands;
typedef struct sriq_HState sriq_HState;

#ifndef SLOP_LIST_TYPES_LIT_DEFINED
#define SLOP_LIST_TYPES_LIT_DEFINED
#define SLOP_LIST_TYPES_LIT_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Lit, slop_list_types_Lit)
#endif

#ifndef SLOP_LIST_TYPES_ATERM_DEFINED
#define SLOP_LIST_TYPES_ATERM_DEFINED
#define SLOP_LIST_TYPES_ATERM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_ATerm, slop_list_types_ATerm)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

#ifndef SLOP_OPTION_TYPES_ATERM_DEFINED
#define SLOP_OPTION_TYPES_ATERM_DEFINED
SLOP_OPTION_DEFINE(types_ATerm, slop_option_types_ATerm)
#endif

struct sriq_Premise {
    slop_list_types_Lit body;
    types_Lit sel;
    slop_list_types_Lit rest;
    uint8_t maxed;
};
typedef struct sriq_Premise sriq_Premise;

#ifndef SLOP_OPTION_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(sriq_Premise, slop_option_sriq_Premise)
#endif

#ifndef SLOP_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(sriq_Premise, slop_list_sriq_Premise)
#endif

struct sriq_RConcl {
    uint8_t fires;
    slop_list_types_Lit body;
    slop_list_types_Lit head;
};
typedef struct sriq_RConcl sriq_RConcl;

#ifndef SLOP_OPTION_SRIQ_RCONCL_DEFINED
#define SLOP_OPTION_SRIQ_RCONCL_DEFINED
SLOP_OPTION_DEFINE(sriq_RConcl, slop_option_sriq_RConcl)
#endif

#ifndef SLOP_LIST_SRIQ_RCONCL_DEFINED
#define SLOP_LIST_SRIQ_RCONCL_DEFINED
#define SLOP_LIST_SRIQ_RCONCL_IMPL_DEFINED
SLOP_LIST_DEFINE(sriq_RConcl, slop_list_sriq_RConcl)
#endif

struct sriq_Subst {
    types_ATerm x;
    uint8_t xbound;
    slop_list_int zs;
    slop_list_types_ATerm ts;
};
typedef struct sriq_Subst sriq_Subst;

#ifndef SLOP_OPTION_SRIQ_SUBST_DEFINED
#define SLOP_OPTION_SRIQ_SUBST_DEFINED
SLOP_OPTION_DEFINE(sriq_Subst, slop_option_sriq_Subst)
#endif

struct sriq_Cands {
    slop_list_sriq_Premise ps;
};
typedef struct sriq_Cands sriq_Cands;

#ifndef SLOP_OPTION_SRIQ_CANDS_DEFINED
#define SLOP_OPTION_SRIQ_CANDS_DEFINED
SLOP_OPTION_DEFINE(sriq_Cands, slop_option_sriq_Cands)
#endif

#ifndef SLOP_LIST_SRIQ_CANDS_DEFINED
#define SLOP_LIST_SRIQ_CANDS_DEFINED
#define SLOP_LIST_SRIQ_CANDS_IMPL_DEFINED
SLOP_LIST_DEFINE(sriq_Cands, slop_list_sriq_Cands)
#endif

struct sriq_HState {
    uint8_t fires;
    sriq_Subst sub;
    slop_list_types_Lit body;
    slop_list_types_Lit head;
};
typedef struct sriq_HState sriq_HState;

#ifndef SLOP_OPTION_SRIQ_HSTATE_DEFINED
#define SLOP_OPTION_SRIQ_HSTATE_DEFINED
SLOP_OPTION_DEFINE(sriq_HState, slop_option_sriq_HState)
#endif

#ifndef SLOP_LIST_SRIQ_HSTATE_DEFINED
#define SLOP_LIST_SRIQ_HSTATE_DEFINED
#define SLOP_LIST_SRIQ_HSTATE_IMPL_DEFINED
SLOP_LIST_DEFINE(sriq_HState, slop_list_sriq_HState)
#endif

types_Lit sriq_lit_at(slop_list_types_Lit xs, int64_t i);
slop_list_types_Lit sriq_without_at(slop_arena* arena, slop_list_types_Lit xs, int64_t i);
sriq_Premise sriq_select(slop_arena* arena, sriqorder_SriqOrder ord, types_Clause c, int64_t i);
types_Clause sriq_assemble(slop_arena* arena, sriq_RConcl r);
slop_list_types_Lit sriq_appended(slop_arena* arena, slop_list_types_Lit a, slop_list_types_Lit b);
sriq_RConcl sriq_core_rule(slop_arena* arena, types_Lit a);
sriq_RConcl sriq_ineq_rule(sriq_Premise p);
uint8_t sriq_has_side(types_Lit l, types_ATerm s);
types_ATerm sriq_other_side(types_Lit l, types_ATerm s);
uint8_t sriq_holds_lit(slop_list_types_Lit ls, types_Lit l);
slop_list_types_Lit sriq_without_lit(slop_arena* arena, slop_list_types_Lit ls, types_Lit l);
sriq_RConcl sriq_factor_rule(slop_arena* arena, sriqorder_SriqOrder ord, sriq_Premise p, types_Lit l1, types_ATerm s);
slop_option_types_ATerm sriq_z_image(sriq_Subst sub, int64_t i);
uint8_t sriq_term_matches(sriq_Subst sub, types_ATerm a, types_ATerm l);
sriq_Subst sriq_bind_term(slop_arena* arena, sriq_Subst sub, types_ATerm a, types_ATerm l);
uint8_t sriq_atom_matches(sriq_Subst sub, types_Lit a, types_Lit l);
sriq_Subst sriq_bind_atom(slop_arena* arena, sriq_Subst sub, types_Lit a, types_Lit l);
sriq_HState sriq_hyper_start(slop_arena* arena, types_ATerm x, uint8_t bound);
sriq_HState sriq_hyper_step(slop_arena* arena, sriq_HState st, types_Lit a, sriq_Premise p);
types_ATerm sriq_apply_term(sriq_Subst sub, types_ATerm t);
types_Lit sriq_apply_lit(sriq_Subst sub, types_Lit l);
sriq_RConcl sriq_hyper_finish(slop_arena* arena, sriq_HState st, slop_list_types_Lit delta);
slop_list_sriq_HState sriq_extend_one(slop_arena* arena, sriq_HState st, types_Lit a, slop_list_sriq_Premise ps);
slop_list_sriq_HState sriq_extend_all(slop_arena* arena, slop_list_sriq_HState sts, types_Lit a, slop_list_sriq_Premise ps);
slop_list_sriq_RConcl sriq_hyper_join(slop_arena* arena, sriq_HState start, slop_list_types_Lit atoms, slop_list_sriq_Cands cands, slop_list_types_Lit delta);

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

#ifndef SLOP_OPTION_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(sriq_Premise, slop_option_sriq_Premise)
#endif

#ifndef SLOP_OPTION_SRIQ_RCONCL_DEFINED
#define SLOP_OPTION_SRIQ_RCONCL_DEFINED
SLOP_OPTION_DEFINE(sriq_RConcl, slop_option_sriq_RConcl)
#endif

#ifndef SLOP_OPTION_TYPES_ATERM_DEFINED
#define SLOP_OPTION_TYPES_ATERM_DEFINED
SLOP_OPTION_DEFINE(types_ATerm, slop_option_types_ATerm)
#endif

#ifndef SLOP_OPTION_SRIQ_SUBST_DEFINED
#define SLOP_OPTION_SRIQ_SUBST_DEFINED
SLOP_OPTION_DEFINE(sriq_Subst, slop_option_sriq_Subst)
#endif

#ifndef SLOP_OPTION_SRIQ_CANDS_DEFINED
#define SLOP_OPTION_SRIQ_CANDS_DEFINED
SLOP_OPTION_DEFINE(sriq_Cands, slop_option_sriq_Cands)
#endif

#ifndef SLOP_OPTION_SRIQ_HSTATE_DEFINED
#define SLOP_OPTION_SRIQ_HSTATE_DEFINED
SLOP_OPTION_DEFINE(sriq_HState, slop_option_sriq_HState)
#endif


#endif
