#ifndef SLOP_sriq_H
#define SLOP_sriq_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_sriqclauses.h"
#include "slop_sriqctx.h"
#include "slop_sriqorder.h"

typedef struct howl_sriq_Premise howl_sriq_Premise;
typedef struct howl_sriq_RConcl howl_sriq_RConcl;
typedef struct howl_sriq_Subst howl_sriq_Subst;
typedef struct howl_sriq_Cands howl_sriq_Cands;
typedef struct howl_sriq_Pos howl_sriq_Pos;
typedef struct howl_sriq_BodyView howl_sriq_BodyView;
typedef struct howl_sriq_HState howl_sriq_HState;
typedef struct howl_sriq_CSub howl_sriq_CSub;
typedef struct howl_sriq_SuccSig howl_sriq_SuccSig;
typedef struct howl_sriq_PreLit howl_sriq_PreLit;
typedef struct howl_sriq_KSets howl_sriq_KSets;
typedef struct howl_sriq_SuccConcl howl_sriq_SuccConcl;
typedef struct howl_sriq_RSuccConcl howl_sriq_RSuccConcl;
typedef struct howl_sriq_PredView howl_sriq_PredView;
typedef struct howl_sriq_PSlot howl_sriq_PSlot;
typedef struct howl_sriq_PState howl_sriq_PState;
typedef struct howl_sriq_PCands howl_sriq_PCands;

#ifndef SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_IMPL_DEFINED
SLOP_LIST_DEFINE(uint32_t, slop_list_u32)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_HOWL_TYPES_LIT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Lit, slop_list_howl_types_Lit)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ATERM_DEFINED
#define SLOP_LIST_HOWL_TYPES_ATERM_DEFINED
#define SLOP_LIST_HOWL_TYPES_ATERM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_ATerm, slop_list_howl_types_ATerm)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Clause, slop_list_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ATERM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ATERM_DEFINED
SLOP_OPTION_DEFINE(howl_types_ATerm, slop_option_howl_types_ATerm)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

struct howl_sriq_Premise {
    slop_list_howl_types_Lit body;
    howl_types_Lit sel;
    slop_list_howl_types_Lit rest;
    uint8_t maxed;
};
typedef struct howl_sriq_Premise howl_sriq_Premise;

#ifndef SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Premise, slop_option_howl_sriq_Premise)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_Premise, slop_list_howl_sriq_Premise)
#endif

struct howl_sriq_RConcl {
    uint8_t fires;
    slop_list_howl_types_Lit body;
    slop_list_howl_types_Lit head;
};
typedef struct howl_sriq_RConcl howl_sriq_RConcl;

#ifndef SLOP_OPTION_HOWL_SRIQ_RCONCL_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_RCONCL_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_RConcl, slop_option_howl_sriq_RConcl)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_RCONCL_DEFINED
#define SLOP_LIST_HOWL_SRIQ_RCONCL_DEFINED
#define SLOP_LIST_HOWL_SRIQ_RCONCL_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_RConcl, slop_list_howl_sriq_RConcl)
#endif

struct howl_sriq_Subst {
    howl_types_ATerm x;
    uint8_t xbound;
    slop_list_int zs;
    slop_list_howl_types_ATerm ts;
};
typedef struct howl_sriq_Subst howl_sriq_Subst;

#ifndef SLOP_OPTION_HOWL_SRIQ_SUBST_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_SUBST_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Subst, slop_option_howl_sriq_Subst)
#endif

struct howl_sriq_Cands {
    slop_list_howl_sriq_Premise ps;
};
typedef struct howl_sriq_Cands howl_sriq_Cands;

#ifndef SLOP_OPTION_HOWL_SRIQ_CANDS_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_CANDS_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Cands, slop_option_howl_sriq_Cands)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_CANDS_DEFINED
#define SLOP_LIST_HOWL_SRIQ_CANDS_DEFINED
#define SLOP_LIST_HOWL_SRIQ_CANDS_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_Cands, slop_list_howl_sriq_Cands)
#endif

struct howl_sriq_Pos {
    uint32_t arg;
    uint8_t inner;
};
typedef struct howl_sriq_Pos howl_sriq_Pos;

#ifndef SLOP_OPTION_HOWL_SRIQ_POS_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_POS_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Pos, slop_option_howl_sriq_Pos)
#endif

struct howl_sriq_BodyView {
    howl_types_Lit lit;
    slop_list_howl_types_Lit rest;
    slop_list_howl_types_Lit head;
};
typedef struct howl_sriq_BodyView howl_sriq_BodyView;

#ifndef SLOP_OPTION_HOWL_SRIQ_BODYVIEW_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_BODYVIEW_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_BodyView, slop_option_howl_sriq_BodyView)
#endif

struct howl_sriq_HState {
    uint8_t fires;
    howl_sriq_Subst sub;
    slop_list_howl_types_Lit body;
    slop_list_howl_types_Lit head;
};
typedef struct howl_sriq_HState howl_sriq_HState;

#ifndef SLOP_OPTION_HOWL_SRIQ_HSTATE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_HSTATE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_HState, slop_option_howl_sriq_HState)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_HSTATE_DEFINED
#define SLOP_LIST_HOWL_SRIQ_HSTATE_DEFINED
#define SLOP_LIST_HOWL_SRIQ_HSTATE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_HState, slop_list_howl_sriq_HState)
#endif

struct howl_sriq_CSub {
    howl_types_ATerm x;
    howl_types_ATerm y;
};
typedef struct howl_sriq_CSub howl_sriq_CSub;

#ifndef SLOP_OPTION_HOWL_SRIQ_CSUB_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_CSUB_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_CSub, slop_option_howl_sriq_CSub)
#endif

struct howl_sriq_SuccSig {
    uint32_t f;
    uint8_t root;
    uint32_t u;
};
typedef struct howl_sriq_SuccSig howl_sriq_SuccSig;

#ifndef SLOP_OPTION_HOWL_SRIQ_SUCCSIG_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_SUCCSIG_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_SuccSig, slop_option_howl_sriq_SuccSig)
#endif

struct howl_sriq_PreLit {
    uint8_t ok;
    howl_types_Lit lit;
};
typedef struct howl_sriq_PreLit howl_sriq_PreLit;

#ifndef SLOP_OPTION_HOWL_SRIQ_PRELIT_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PRELIT_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_PreLit, slop_option_howl_sriq_PreLit)
#endif

struct howl_sriq_KSets {
    slop_list_howl_types_Lit k1;
    slop_list_howl_types_Lit k2;
};
typedef struct howl_sriq_KSets howl_sriq_KSets;

#ifndef SLOP_OPTION_HOWL_SRIQ_KSETS_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_KSETS_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_KSets, slop_option_howl_sriq_KSets)
#endif

struct howl_sriq_SuccConcl {
    uint8_t fires;
    howl_sriqctx_CoreChoice choice;
    slop_list_howl_types_Lit adds;
};
typedef struct howl_sriq_SuccConcl howl_sriq_SuccConcl;

#ifndef SLOP_OPTION_HOWL_SRIQ_SUCCCONCL_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_SUCCCONCL_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_SuccConcl, slop_option_howl_sriq_SuccConcl)
#endif

struct howl_sriq_RSuccConcl {
    uint8_t fires;
    howl_types_Lit lit;
};
typedef struct howl_sriq_RSuccConcl howl_sriq_RSuccConcl;

#ifndef SLOP_OPTION_HOWL_SRIQ_RSUCCCONCL_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_RSUCCCONCL_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_RSuccConcl, slop_option_howl_sriq_RSuccConcl)
#endif

struct howl_sriq_PredView {
    slop_list_howl_types_Lit ground;
    slop_list_howl_types_Lit slots;
    slop_list_howl_types_Lit head;
    uint8_t ok;
};
typedef struct howl_sriq_PredView howl_sriq_PredView;

#ifndef SLOP_OPTION_HOWL_SRIQ_PREDVIEW_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PREDVIEW_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_PredView, slop_option_howl_sriq_PredView)
#endif

struct howl_sriq_PSlot {
    howl_types_Lit lit;
    uint8_t edge;
};
typedef struct howl_sriq_PSlot howl_sriq_PSlot;

#ifndef SLOP_OPTION_HOWL_SRIQ_PSLOT_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PSLOT_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_PSlot, slop_option_howl_sriq_PSlot)
#endif

struct howl_sriq_PState {
    uint8_t fires;
    slop_list_howl_types_Lit body;
    slop_list_howl_types_Lit head;
};
typedef struct howl_sriq_PState howl_sriq_PState;

#ifndef SLOP_OPTION_HOWL_SRIQ_PSTATE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PSTATE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_PState, slop_option_howl_sriq_PState)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_PSTATE_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PSTATE_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PSTATE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_PState, slop_list_howl_sriq_PState)
#endif

struct howl_sriq_PCands {
    howl_sriq_PSlot slot;
    slop_list_howl_sriq_Premise ps;
};
typedef struct howl_sriq_PCands howl_sriq_PCands;

#ifndef SLOP_OPTION_HOWL_SRIQ_PCANDS_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PCANDS_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_PCands, slop_option_howl_sriq_PCands)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_PCANDS_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PCANDS_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PCANDS_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_PCands, slop_list_howl_sriq_PCands)
#endif

howl_types_Lit howl_sriq_lit_at(slop_list_howl_types_Lit xs, int64_t i);
slop_list_howl_types_Lit howl_sriq_without_at(slop_arena* arena, slop_list_howl_types_Lit xs, int64_t i);
howl_sriq_Premise howl_sriq_select(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_types_Clause c, int64_t i);
howl_types_Clause howl_sriq_assemble(slop_arena* arena, howl_sriq_RConcl r);
slop_list_howl_types_Lit howl_sriq_appended(slop_arena* arena, slop_list_howl_types_Lit a, slop_list_howl_types_Lit b);
howl_sriq_RConcl howl_sriq_core_rule(slop_arena* arena, howl_types_Lit a);
howl_sriq_RConcl howl_sriq_ineq_rule(howl_sriq_Premise p);
uint8_t howl_sriq_has_side(howl_types_Lit l, howl_types_ATerm s);
howl_types_ATerm howl_sriq_other_side(howl_types_Lit l, howl_types_ATerm s);
uint8_t howl_sriq_holds_lit(slop_list_howl_types_Lit ls, howl_types_Lit l);
slop_list_howl_types_Lit howl_sriq_without_lit(slop_arena* arena, slop_list_howl_types_Lit ls, howl_types_Lit l);
howl_sriq_RConcl howl_sriq_factor_rule(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriq_Premise p, howl_types_Lit l1, howl_types_ATerm s);
slop_option_howl_types_ATerm howl_sriq_z_image(howl_sriq_Subst sub, int64_t i);
uint8_t howl_sriq_term_matches(howl_sriq_Subst sub, howl_types_ATerm a, howl_types_ATerm l);
howl_sriq_Subst howl_sriq_bind_term(slop_arena* arena, howl_sriq_Subst sub, howl_types_ATerm a, howl_types_ATerm l);
uint8_t howl_sriq_atom_matches(howl_sriq_Subst sub, howl_types_Lit a, howl_types_Lit l);
howl_sriq_Subst howl_sriq_bind_atom(slop_arena* arena, howl_sriq_Subst sub, howl_types_Lit a, howl_types_Lit l);
howl_sriq_HState howl_sriq_hyper_start(slop_arena* arena, howl_types_ATerm x, uint8_t bound);
howl_sriq_HState howl_sriq_hyper_step(slop_arena* arena, howl_sriq_HState st, howl_types_Lit a, howl_sriq_Premise p);
howl_types_ATerm howl_sriq_apply_term(howl_sriq_Subst sub, howl_types_ATerm t);
howl_types_Lit howl_sriq_apply_lit(howl_sriq_Subst sub, howl_types_Lit l);
howl_sriq_RConcl howl_sriq_hyper_finish(slop_arena* arena, howl_sriq_HState st, slop_list_howl_types_Lit delta);
slop_list_howl_sriq_HState howl_sriq_extend_one(slop_arena* arena, howl_sriq_HState st, howl_types_Lit a, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriq_HState howl_sriq_extend_all(slop_arena* arena, slop_list_howl_sriq_HState sts, howl_types_Lit a, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriq_RConcl howl_sriq_hyper_join(slop_arena* arena, howl_sriq_HState start, slop_list_howl_types_Lit atoms, slop_list_howl_sriq_Cands cands, slop_list_howl_types_Lit delta);
uint32_t howl_sriq_other_arg(uint32_t k);
howl_types_ATerm howl_sriq_arg_term(howl_types_Lit l, uint32_t k);
uint8_t howl_sriq_has_arg(howl_types_Lit l, uint32_t k);
slop_option_howl_types_ATerm howl_sriq_inner_of(howl_types_ATerm a);
slop_option_howl_types_ATerm howl_sriq_subterm_at(howl_types_Lit l, howl_sriq_Pos p);
howl_types_ATerm howl_sriq_with_inner(howl_types_ATerm a, howl_types_ATerm t);
howl_types_Lit howl_sriq_with_arg(howl_types_Lit l, uint32_t k, howl_types_ATerm t);
howl_types_Lit howl_sriq_replace_at(howl_types_Lit l, howl_sriq_Pos p, howl_types_ATerm t);
howl_types_ATerm howl_sriq_replace_const(howl_types_ATerm a, howl_types_ATerm s, howl_types_ATerm t);
howl_types_Lit howl_sriq_replace_all(howl_types_Lit l, howl_sriq_Pos p, howl_types_ATerm s, howl_types_ATerm t);
uint8_t howl_sriq_side_ok(howl_sriqorder_SriqOrder ord, howl_types_Lit l, uint32_t k);
uint8_t howl_sriq_kinds_are(howl_types_ATerm a, howl_types_ATerm b, howl_types_AKind p, howl_types_AKind q);
uint8_t howl_sriq_eq_usable(howl_types_ATerm s1, howl_types_ATerm t1);
uint8_t howl_sriq_plain(howl_types_ATerm a);
uint8_t howl_sriq_s2_plain(howl_types_Lit l, howl_sriq_Pos p);
uint8_t howl_sriq_x_ok(howl_types_Lit l, howl_sriq_Pos p, howl_types_ATerm s1);
uint8_t howl_sriq_at_is(slop_option_howl_types_ATerm o, howl_types_ATerm s);
howl_sriq_RConcl howl_sriq_eq_rule(slop_arena* arena, howl_sriqorder_SriqOrder ord, uint8_t root, howl_sriq_Premise p1, uint32_t k1, howl_sriq_Premise p2, howl_sriq_Pos p);
howl_sriq_BodyView howl_sriq_body_at(slop_arena* arena, howl_types_Clause c, int64_t i);
uint8_t howl_sriq_ground(howl_types_ATerm a);
uint8_t howl_sriq_joinable(howl_types_Lit a);
howl_sriq_RConcl howl_sriq_join_rule(slop_arena* arena, howl_sriq_Premise p1, howl_sriq_BodyView b);
uint8_t howl_sriq_kid_ok(howl_sriqorder_SriqOrder ord, uint32_t o, uint32_t sb2, uint32_t i, uint32_t k);
uint8_t howl_sriq_kids_ok(howl_sriqorder_SriqOrder ord, uint32_t o, uint32_t sb2, uint32_t n, slop_list_u32 kids);
slop_list_howl_types_Lit howl_sriq_nom_head(slop_arena* arena, slop_list_u32 kids);
uint8_t howl_sriq_nom_premises(howl_sriq_Premise p1, howl_sriq_Premise p2, uint32_t b1, uint32_t sb2);
howl_sriq_RConcl howl_sriq_nom_rule(slop_arena* arena, howl_sriqorder_SriqOrder ord, int64_t lam, uint32_t b1, uint32_t sb2, uint32_t n, howl_sriq_Premise p1, howl_sriq_Premise p2, slop_list_u32 kids);
howl_types_ATerm howl_sriq_csub_term(howl_sriq_CSub s, howl_types_ATerm t);
howl_types_Lit howl_sriq_csub_lit(howl_sriq_CSub s, howl_types_Lit l);
howl_sriq_CSub howl_sriq_succ_csub(howl_sriq_SuccSig sg);
uint8_t howl_sriq_is_succ_term(howl_sriq_SuccSig sg, howl_types_ATerm t);
uint8_t howl_sriq_is_atom(howl_types_Lit l);
uint8_t howl_sriq_succ_mentions(howl_sriq_SuccSig sg, howl_types_Lit l);
slop_option_howl_sriq_SuccSig howl_sriq_sig_of_term(uint8_t root, howl_types_ATerm t);
slop_option_howl_sriq_SuccSig howl_sriq_succ_sig(uint8_t root, howl_types_Lit l);
howl_sriq_PreLit howl_sriq_pre_none(howl_types_Lit l);
howl_sriq_PreLit howl_sriq_pre_some(howl_types_Lit a);
howl_sriq_PreLit howl_sriq_pre_binary(howl_sriq_SuccSig sg, howl_types_Lit l);
howl_sriq_PreLit howl_sriq_succ_pre(howl_sriq_SuccSig sg, howl_types_Lit l);
uint8_t howl_sriq_has_fterm(howl_types_Lit l);
howl_sriq_PreLit howl_sriq_k_of_lit(howl_sriqctx_Triggers tr, howl_sriq_SuccSig sg, howl_types_Lit l);
howl_sriq_KSets howl_sriq_k_of_clause(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriqctx_Triggers tr, howl_sriq_SuccSig sg, howl_types_Clause c);
howl_sriq_KSets howl_sriq_k_sets(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriqctx_Triggers tr, howl_sriq_SuccSig sg, slop_list_howl_types_Clause cs);
uint8_t howl_sriq_within_one(slop_list_howl_types_Lit ls, howl_types_Lit a);
uint8_t howl_sriq_unit_held(howl_types_Lit a, slop_list_howl_types_Clause ws);
uint8_t howl_sriq_covers(slop_list_howl_types_Lit k2, slop_list_howl_types_Lit core, slop_list_howl_types_Clause ws);
howl_sriq_SuccConcl howl_sriq_succ_step(slop_arena* arena, howl_sriqctx_Strategy s, howl_sriqctx_Triggers tr, howl_sriq_SuccSig sg, howl_sriq_Premise p, howl_sriq_KSets ks, uint8_t covered);
howl_types_ATerm howl_sriq_x_to_y(howl_types_ATerm t);
howl_types_Lit howl_sriq_rsucc_lit(howl_types_Lit l);
uint8_t howl_sriq_has_y(howl_types_Lit l);
uint8_t howl_sriq_has_const(howl_types_Lit l, uint32_t u);
howl_sriq_RSuccConcl howl_sriq_rsucc_rule(howl_sriqctx_Triggers tr, uint8_t root, howl_sriq_Premise p, uint32_t u, uint8_t held);
howl_sriq_PredView howl_sriq_pred_view(slop_arena* arena, howl_types_Clause c, slop_list_howl_types_Lit core, uint8_t to_root);
howl_sriq_PredView howl_sriq_rpred_view(slop_arena* arena, howl_sriqctx_Triggers tr, howl_types_Clause c);
howl_sriq_PState howl_sriq_pred_start(slop_arena* arena, uint8_t edge);
howl_sriq_PState howl_sriq_pred_step(slop_arena* arena, howl_sriq_PState st, howl_sriq_CSub s, howl_sriq_PSlot slot, howl_sriq_Premise p);
uint8_t howl_sriq_is_xu(howl_types_Lit l);
uint8_t howl_sriq_pred_head_ok(howl_sriqctx_Triggers tr, uint8_t to_root, howl_types_Lit l);
uint8_t howl_sriq_pred_heads_ok(howl_sriqctx_Triggers tr, uint8_t to_root, slop_list_howl_types_Lit ls);
uint8_t howl_sriq_rpred_head_ok(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriq_rpred_heads_ok(howl_sriqctx_Triggers tr, slop_list_howl_types_Lit ls);
slop_list_howl_types_Lit howl_sriq_mapped(slop_arena* arena, howl_sriq_CSub s, slop_list_howl_types_Lit ls);
howl_sriq_RConcl howl_sriq_pred_finish(slop_arena* arena, howl_sriq_PState st, howl_sriq_CSub s, howl_sriqctx_Triggers tr, uint8_t to_root, howl_sriq_PredView v);
howl_sriq_RConcl howl_sriq_rpred_finish(slop_arena* arena, howl_sriq_PState st, howl_sriqctx_Triggers tr, howl_sriq_PredView v);
slop_list_howl_sriq_PState howl_sriq_pred_extend_one(slop_arena* arena, howl_sriq_PState st, howl_sriq_CSub s, howl_sriq_PSlot slot, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriq_PState howl_sriq_pred_join(slop_arena* arena, howl_sriq_PState start, howl_sriq_CSub s, slop_list_howl_sriq_PCands cs);
int64_t howl_sriq_depth_limit(int64_t tsu, int64_t tpr, int64_t omega, int64_t omega_d);
int64_t howl_sriq_stored_lambda(int64_t tsu, int64_t tpr, int64_t omega, int64_t omega_d);
uint8_t howl_sriq_lits_same(slop_list_howl_types_Lit a, slop_list_howl_types_Lit b);
uint8_t howl_sriq_rconcl_eq(howl_sriq_RConcl a, howl_sriq_RConcl b);
uint8_t howl_sriq_fires_is(howl_sriq_RConcl a, howl_sriq_RConcl b);
uint8_t howl_sriq_hstate_eq(howl_sriq_HState a, howl_sriq_HState b);
howl_types_ATerm howl_sriq_ex_fx(int64_t f);
howl_types_ATerm howl_sriq_ex_u(int64_t u);
howl_types_Lit howl_sriq_ex_a1(int64_t b, howl_types_ATerm t);
howl_types_Lit howl_sriq_ex_a2(int64_t r, howl_types_ATerm a, howl_types_ATerm b);
howl_sriq_Pos howl_sriq_ex_pos(int64_t k, uint8_t inner);
uint32_t howl_sriq_ex_side(howl_types_Lit l, howl_types_ATerm s);
slop_list_howl_types_Lit howl_sriq_ex_l0(slop_arena* arena);
slop_list_howl_types_Lit howl_sriq_ex_l1(slop_arena* arena, howl_types_Lit a);
slop_list_howl_types_Lit howl_sriq_ex_l2(slop_arena* arena, howl_types_Lit a, howl_types_Lit b);
slop_list_howl_types_Lit howl_sriq_ex_l3(slop_arena* arena, howl_types_Lit a, howl_types_Lit b, howl_types_Lit c);
howl_sriqorder_SriqOrder howl_sriq_ex_ord(slop_arena* arena);
howl_sriq_Premise howl_sriq_ex_sel(slop_arena* arena, slop_list_howl_types_Lit head, howl_types_Lit l);
howl_sriq_Premise howl_sriq_ex_fac(slop_arena* arena);
howl_sriq_BodyView howl_sriq_ex_body(slop_arena* arena, slop_list_howl_types_Lit body, slop_list_howl_types_Lit head, howl_types_Lit l);
howl_sriq_RConcl howl_sriq_ex_rc(slop_arena* arena, uint8_t fires, slop_list_howl_types_Lit body, slop_list_howl_types_Lit head);
howl_sriq_HState howl_sriq_ex_hs(slop_arena* arena, uint8_t fires, slop_list_howl_types_Lit body, slop_list_howl_types_Lit head);
howl_sriqorder_SriqOrder howl_sriq_ex_kids_ord(slop_arena* arena);
slop_list_u32 howl_sriq_ex_ids(slop_arena* arena, int64_t k);

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Premise, slop_option_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_RCONCL_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_RCONCL_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_RConcl, slop_option_howl_sriq_RConcl)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ATERM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ATERM_DEFINED
SLOP_OPTION_DEFINE(howl_types_ATerm, slop_option_howl_types_ATerm)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_SUBST_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_SUBST_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Subst, slop_option_howl_sriq_Subst)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_CANDS_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_CANDS_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Cands, slop_option_howl_sriq_Cands)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_POS_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_POS_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Pos, slop_option_howl_sriq_Pos)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_BODYVIEW_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_BODYVIEW_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_BodyView, slop_option_howl_sriq_BodyView)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_HSTATE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_HSTATE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_HState, slop_option_howl_sriq_HState)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_CSUB_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_CSUB_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_CSub, slop_option_howl_sriq_CSub)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_SUCCSIG_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_SUCCSIG_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_SuccSig, slop_option_howl_sriq_SuccSig)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PRELIT_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PRELIT_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_PreLit, slop_option_howl_sriq_PreLit)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_KSETS_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_KSETS_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_KSets, slop_option_howl_sriq_KSets)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_SUCCCONCL_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_SUCCCONCL_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_SuccConcl, slop_option_howl_sriq_SuccConcl)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_RSUCCCONCL_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_RSUCCCONCL_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_RSuccConcl, slop_option_howl_sriq_RSuccConcl)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PREDVIEW_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PREDVIEW_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_PredView, slop_option_howl_sriq_PredView)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PSLOT_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PSLOT_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_PSlot, slop_option_howl_sriq_PSlot)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PSTATE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PSTATE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_PState, slop_option_howl_sriq_PState)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PCANDS_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PCANDS_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_PCands, slop_option_howl_sriq_PCands)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_OPTION_HOWL_SRIQORDER_CONSTENTRY_DEFINED
SLOP_OPTION_DEFINE(howl_sriqorder_ConstEntry, slop_option_howl_sriqorder_ConstEntry)
#endif

#ifndef SLOP_LIST_HOWL_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_LIST_HOWL_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_LIST_HOWL_SRIQORDER_CONSTENTRY_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqorder_ConstEntry, slop_list_howl_sriqorder_ConstEntry)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef HOWL_TYPES_ATERM_HASH_EQ_DEFINED
#define HOWL_TYPES_ATERM_HASH_EQ_DEFINED
static inline uint64_t slop_hash_howl_types_ATerm(const void* key) {
    const howl_types_ATerm* _k = (const howl_types_ATerm*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&(int64_t){ (int64_t)_k->kind }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->fsym }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->cst }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->zi }); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_howl_types_ATerm(const void* a, const void* b) {
    const howl_types_ATerm* _a = (const howl_types_ATerm*)a;
    const howl_types_ATerm* _b = (const howl_types_ATerm*)b;
    return true
        && (_a->kind == _b->kind)
        && (_a->fsym == _b->fsym)
        && (_a->cst == _b->cst)
        && (_a->zi == _b->zi)
    ;
}
#endif

#ifndef HOWL_TYPES_LIT_HASH_EQ_DEFINED
#define HOWL_TYPES_LIT_HASH_EQ_DEFINED
#ifndef HOWL_TYPES_ATERM_HASH_EQ_DEFINED
#define HOWL_TYPES_ATERM_HASH_EQ_DEFINED
static inline uint64_t slop_hash_howl_types_ATerm(const void* key) {
    const howl_types_ATerm* _k = (const howl_types_ATerm*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&(int64_t){ (int64_t)_k->kind }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->fsym }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->cst }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->zi }); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_howl_types_ATerm(const void* a, const void* b) {
    const howl_types_ATerm* _a = (const howl_types_ATerm*)a;
    const howl_types_ATerm* _b = (const howl_types_ATerm*)b;
    return true
        && (_a->kind == _b->kind)
        && (_a->fsym == _b->fsym)
        && (_a->cst == _b->cst)
        && (_a->zi == _b->zi)
    ;
}
#endif
#ifndef HOWL_TYPES_ATERM_HASH_EQ_DEFINED
#define HOWL_TYPES_ATERM_HASH_EQ_DEFINED
static inline uint64_t slop_hash_howl_types_ATerm(const void* key) {
    const howl_types_ATerm* _k = (const howl_types_ATerm*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&(int64_t){ (int64_t)_k->kind }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->fsym }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->cst }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->zi }); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_howl_types_ATerm(const void* a, const void* b) {
    const howl_types_ATerm* _a = (const howl_types_ATerm*)a;
    const howl_types_ATerm* _b = (const howl_types_ATerm*)b;
    return true
        && (_a->kind == _b->kind)
        && (_a->fsym == _b->fsym)
        && (_a->cst == _b->cst)
        && (_a->zi == _b->zi)
    ;
}
#endif
static inline uint64_t slop_hash_howl_types_Lit(const void* key) {
    const howl_types_Lit* _k = (const howl_types_Lit*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&(int64_t){ (int64_t)_k->form }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->pred }); hash *= 1099511628211ULL;
    hash ^= slop_hash_howl_types_ATerm(&_k->t1); hash *= 1099511628211ULL;
    hash ^= slop_hash_howl_types_ATerm(&_k->t2); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_howl_types_Lit(const void* a, const void* b) {
    const howl_types_Lit* _a = (const howl_types_Lit*)a;
    const howl_types_Lit* _b = (const howl_types_Lit*)b;
    return true
        && (_a->form == _b->form)
        && (_a->pred == _b->pred)
        && (slop_eq_howl_types_ATerm(&_a->t1, &_b->t1))
        && (slop_eq_howl_types_ATerm(&_a->t2, &_b->t2))
    ;
}
#endif


#endif
