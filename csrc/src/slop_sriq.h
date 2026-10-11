#ifndef SLOP_sriq_H
#define SLOP_sriq_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_sriqclauses.h"
#include "slop_sriqctx.h"
#include "slop_sriqorder.h"

typedef struct sriq_Premise sriq_Premise;
typedef struct sriq_RConcl sriq_RConcl;
typedef struct sriq_Subst sriq_Subst;
typedef struct sriq_Cands sriq_Cands;
typedef struct sriq_Pos sriq_Pos;
typedef struct sriq_BodyView sriq_BodyView;
typedef struct sriq_HState sriq_HState;
typedef struct sriq_CSub sriq_CSub;
typedef struct sriq_SuccSig sriq_SuccSig;
typedef struct sriq_PreLit sriq_PreLit;
typedef struct sriq_KSets sriq_KSets;
typedef struct sriq_SuccConcl sriq_SuccConcl;
typedef struct sriq_RSuccConcl sriq_RSuccConcl;
typedef struct sriq_PredView sriq_PredView;
typedef struct sriq_PSlot sriq_PSlot;
typedef struct sriq_PState sriq_PState;
typedef struct sriq_PCands sriq_PCands;

#ifndef SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_IMPL_DEFINED
SLOP_LIST_DEFINE(uint32_t, slop_list_u32)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

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

#ifndef SLOP_LIST_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_TYPES_CLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Clause, slop_list_types_Clause)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

#ifndef SLOP_OPTION_TYPES_ATERM_DEFINED
#define SLOP_OPTION_TYPES_ATERM_DEFINED
SLOP_OPTION_DEFINE(types_ATerm, slop_option_types_ATerm)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
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

struct sriq_Pos {
    uint32_t arg;
    uint8_t inner;
};
typedef struct sriq_Pos sriq_Pos;

#ifndef SLOP_OPTION_SRIQ_POS_DEFINED
#define SLOP_OPTION_SRIQ_POS_DEFINED
SLOP_OPTION_DEFINE(sriq_Pos, slop_option_sriq_Pos)
#endif

struct sriq_BodyView {
    types_Lit lit;
    slop_list_types_Lit rest;
    slop_list_types_Lit head;
};
typedef struct sriq_BodyView sriq_BodyView;

#ifndef SLOP_OPTION_SRIQ_BODYVIEW_DEFINED
#define SLOP_OPTION_SRIQ_BODYVIEW_DEFINED
SLOP_OPTION_DEFINE(sriq_BodyView, slop_option_sriq_BodyView)
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

struct sriq_CSub {
    types_ATerm x;
    types_ATerm y;
};
typedef struct sriq_CSub sriq_CSub;

#ifndef SLOP_OPTION_SRIQ_CSUB_DEFINED
#define SLOP_OPTION_SRIQ_CSUB_DEFINED
SLOP_OPTION_DEFINE(sriq_CSub, slop_option_sriq_CSub)
#endif

struct sriq_SuccSig {
    uint32_t f;
    uint8_t root;
    uint32_t u;
};
typedef struct sriq_SuccSig sriq_SuccSig;

#ifndef SLOP_OPTION_SRIQ_SUCCSIG_DEFINED
#define SLOP_OPTION_SRIQ_SUCCSIG_DEFINED
SLOP_OPTION_DEFINE(sriq_SuccSig, slop_option_sriq_SuccSig)
#endif

struct sriq_PreLit {
    uint8_t ok;
    types_Lit lit;
};
typedef struct sriq_PreLit sriq_PreLit;

#ifndef SLOP_OPTION_SRIQ_PRELIT_DEFINED
#define SLOP_OPTION_SRIQ_PRELIT_DEFINED
SLOP_OPTION_DEFINE(sriq_PreLit, slop_option_sriq_PreLit)
#endif

struct sriq_KSets {
    slop_list_types_Lit k1;
    slop_list_types_Lit k2;
};
typedef struct sriq_KSets sriq_KSets;

#ifndef SLOP_OPTION_SRIQ_KSETS_DEFINED
#define SLOP_OPTION_SRIQ_KSETS_DEFINED
SLOP_OPTION_DEFINE(sriq_KSets, slop_option_sriq_KSets)
#endif

struct sriq_SuccConcl {
    uint8_t fires;
    sriqctx_CoreChoice choice;
    slop_list_types_Lit adds;
};
typedef struct sriq_SuccConcl sriq_SuccConcl;

#ifndef SLOP_OPTION_SRIQ_SUCCCONCL_DEFINED
#define SLOP_OPTION_SRIQ_SUCCCONCL_DEFINED
SLOP_OPTION_DEFINE(sriq_SuccConcl, slop_option_sriq_SuccConcl)
#endif

struct sriq_RSuccConcl {
    uint8_t fires;
    types_Lit lit;
};
typedef struct sriq_RSuccConcl sriq_RSuccConcl;

#ifndef SLOP_OPTION_SRIQ_RSUCCCONCL_DEFINED
#define SLOP_OPTION_SRIQ_RSUCCCONCL_DEFINED
SLOP_OPTION_DEFINE(sriq_RSuccConcl, slop_option_sriq_RSuccConcl)
#endif

struct sriq_PredView {
    slop_list_types_Lit ground;
    slop_list_types_Lit slots;
    slop_list_types_Lit head;
    uint8_t ok;
};
typedef struct sriq_PredView sriq_PredView;

#ifndef SLOP_OPTION_SRIQ_PREDVIEW_DEFINED
#define SLOP_OPTION_SRIQ_PREDVIEW_DEFINED
SLOP_OPTION_DEFINE(sriq_PredView, slop_option_sriq_PredView)
#endif

struct sriq_PSlot {
    types_Lit lit;
    uint8_t edge;
};
typedef struct sriq_PSlot sriq_PSlot;

#ifndef SLOP_OPTION_SRIQ_PSLOT_DEFINED
#define SLOP_OPTION_SRIQ_PSLOT_DEFINED
SLOP_OPTION_DEFINE(sriq_PSlot, slop_option_sriq_PSlot)
#endif

struct sriq_PState {
    uint8_t fires;
    slop_list_types_Lit body;
    slop_list_types_Lit head;
};
typedef struct sriq_PState sriq_PState;

#ifndef SLOP_OPTION_SRIQ_PSTATE_DEFINED
#define SLOP_OPTION_SRIQ_PSTATE_DEFINED
SLOP_OPTION_DEFINE(sriq_PState, slop_option_sriq_PState)
#endif

#ifndef SLOP_LIST_SRIQ_PSTATE_DEFINED
#define SLOP_LIST_SRIQ_PSTATE_DEFINED
#define SLOP_LIST_SRIQ_PSTATE_IMPL_DEFINED
SLOP_LIST_DEFINE(sriq_PState, slop_list_sriq_PState)
#endif

struct sriq_PCands {
    sriq_PSlot slot;
    slop_list_sriq_Premise ps;
};
typedef struct sriq_PCands sriq_PCands;

#ifndef SLOP_OPTION_SRIQ_PCANDS_DEFINED
#define SLOP_OPTION_SRIQ_PCANDS_DEFINED
SLOP_OPTION_DEFINE(sriq_PCands, slop_option_sriq_PCands)
#endif

#ifndef SLOP_LIST_SRIQ_PCANDS_DEFINED
#define SLOP_LIST_SRIQ_PCANDS_DEFINED
#define SLOP_LIST_SRIQ_PCANDS_IMPL_DEFINED
SLOP_LIST_DEFINE(sriq_PCands, slop_list_sriq_PCands)
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
uint32_t sriq_other_arg(uint32_t k);
types_ATerm sriq_arg_term(types_Lit l, uint32_t k);
uint8_t sriq_has_arg(types_Lit l, uint32_t k);
slop_option_types_ATerm sriq_inner_of(types_ATerm a);
slop_option_types_ATerm sriq_subterm_at(types_Lit l, sriq_Pos p);
types_ATerm sriq_with_inner(types_ATerm a, types_ATerm t);
types_Lit sriq_with_arg(types_Lit l, uint32_t k, types_ATerm t);
types_Lit sriq_replace_at(types_Lit l, sriq_Pos p, types_ATerm t);
types_ATerm sriq_replace_const(types_ATerm a, types_ATerm s, types_ATerm t);
types_Lit sriq_replace_all(types_Lit l, sriq_Pos p, types_ATerm s, types_ATerm t);
uint8_t sriq_side_ok(sriqorder_SriqOrder ord, types_Lit l, uint32_t k);
uint8_t sriq_kinds_are(types_ATerm a, types_ATerm b, types_AKind p, types_AKind q);
uint8_t sriq_eq_usable(types_ATerm s1, types_ATerm t1);
uint8_t sriq_plain(types_ATerm a);
uint8_t sriq_s2_plain(types_Lit l, sriq_Pos p);
uint8_t sriq_x_ok(types_Lit l, sriq_Pos p, types_ATerm s1);
uint8_t sriq_at_is(slop_option_types_ATerm o, types_ATerm s);
sriq_RConcl sriq_eq_rule(slop_arena* arena, sriqorder_SriqOrder ord, uint8_t root, sriq_Premise p1, uint32_t k1, sriq_Premise p2, sriq_Pos p);
sriq_BodyView sriq_body_at(slop_arena* arena, types_Clause c, int64_t i);
uint8_t sriq_ground(types_ATerm a);
uint8_t sriq_joinable(types_Lit a);
sriq_RConcl sriq_join_rule(slop_arena* arena, sriq_Premise p1, sriq_BodyView b);
uint8_t sriq_kid_ok(sriqorder_SriqOrder ord, uint32_t o, uint32_t sb2, uint32_t i, uint32_t k);
uint8_t sriq_kids_ok(sriqorder_SriqOrder ord, uint32_t o, uint32_t sb2, uint32_t n, slop_list_u32 kids);
slop_list_types_Lit sriq_nom_head(slop_arena* arena, slop_list_u32 kids);
uint8_t sriq_nom_premises(sriq_Premise p1, sriq_Premise p2, uint32_t b1, uint32_t sb2);
sriq_RConcl sriq_nom_rule(slop_arena* arena, sriqorder_SriqOrder ord, int64_t lam, uint32_t b1, uint32_t sb2, uint32_t n, sriq_Premise p1, sriq_Premise p2, slop_list_u32 kids);
types_ATerm sriq_csub_term(sriq_CSub s, types_ATerm t);
types_Lit sriq_csub_lit(sriq_CSub s, types_Lit l);
sriq_CSub sriq_succ_csub(sriq_SuccSig sg);
uint8_t sriq_is_succ_term(sriq_SuccSig sg, types_ATerm t);
uint8_t sriq_is_atom(types_Lit l);
uint8_t sriq_succ_mentions(sriq_SuccSig sg, types_Lit l);
slop_option_sriq_SuccSig sriq_sig_of_term(uint8_t root, types_ATerm t);
slop_option_sriq_SuccSig sriq_succ_sig(uint8_t root, types_Lit l);
sriq_PreLit sriq_pre_none(types_Lit l);
sriq_PreLit sriq_pre_some(types_Lit a);
sriq_PreLit sriq_pre_binary(sriq_SuccSig sg, types_Lit l);
sriq_PreLit sriq_succ_pre(sriq_SuccSig sg, types_Lit l);
uint8_t sriq_has_fterm(types_Lit l);
sriq_PreLit sriq_k_of_lit(sriqctx_Triggers tr, sriq_SuccSig sg, types_Lit l);
sriq_KSets sriq_k_of_clause(slop_arena* arena, sriqorder_SriqOrder ord, sriqctx_Triggers tr, sriq_SuccSig sg, types_Clause c);
sriq_KSets sriq_k_sets(slop_arena* arena, sriqorder_SriqOrder ord, sriqctx_Triggers tr, sriq_SuccSig sg, slop_list_types_Clause cs);
uint8_t sriq_within_one(slop_list_types_Lit ls, types_Lit a);
uint8_t sriq_unit_held(types_Lit a, slop_list_types_Clause ws);
uint8_t sriq_covers(slop_list_types_Lit k2, slop_list_types_Lit core, slop_list_types_Clause ws);
sriq_SuccConcl sriq_succ_step(slop_arena* arena, sriqctx_Strategy s, sriqctx_Triggers tr, sriq_SuccSig sg, sriq_Premise p, sriq_KSets ks, uint8_t covered);
types_ATerm sriq_x_to_y(types_ATerm t);
types_Lit sriq_rsucc_lit(types_Lit l);
uint8_t sriq_has_y(types_Lit l);
uint8_t sriq_has_const(types_Lit l, uint32_t u);
sriq_RSuccConcl sriq_rsucc_rule(sriqctx_Triggers tr, uint8_t root, sriq_Premise p, uint32_t u, uint8_t held);
sriq_PredView sriq_pred_view(slop_arena* arena, types_Clause c, slop_list_types_Lit core, uint8_t to_root);
sriq_PredView sriq_rpred_view(slop_arena* arena, sriqctx_Triggers tr, types_Clause c);
sriq_PState sriq_pred_start(slop_arena* arena, uint8_t edge);
sriq_PState sriq_pred_step(slop_arena* arena, sriq_PState st, sriq_CSub s, sriq_PSlot slot, sriq_Premise p);
uint8_t sriq_is_xu(types_Lit l);
uint8_t sriq_pred_head_ok(sriqctx_Triggers tr, uint8_t to_root, types_Lit l);
uint8_t sriq_pred_heads_ok(sriqctx_Triggers tr, uint8_t to_root, slop_list_types_Lit ls);
uint8_t sriq_rpred_head_ok(sriqctx_Triggers tr, types_Lit l);
uint8_t sriq_rpred_heads_ok(sriqctx_Triggers tr, slop_list_types_Lit ls);
slop_list_types_Lit sriq_mapped(slop_arena* arena, sriq_CSub s, slop_list_types_Lit ls);
sriq_RConcl sriq_pred_finish(slop_arena* arena, sriq_PState st, sriq_CSub s, sriqctx_Triggers tr, uint8_t to_root, sriq_PredView v);
sriq_RConcl sriq_rpred_finish(slop_arena* arena, sriq_PState st, sriqctx_Triggers tr, sriq_PredView v);
slop_list_sriq_PState sriq_pred_extend_one(slop_arena* arena, sriq_PState st, sriq_CSub s, sriq_PSlot slot, slop_list_sriq_Premise ps);
slop_list_sriq_PState sriq_pred_join(slop_arena* arena, sriq_PState start, sriq_CSub s, slop_list_sriq_PCands cs);
int64_t sriq_depth_limit(int64_t tsu, int64_t tpr, int64_t omega, int64_t omega_d);
int64_t sriq_stored_lambda(int64_t tsu, int64_t tpr, int64_t omega, int64_t omega_d);
uint8_t sriq_lits_same(slop_list_types_Lit a, slop_list_types_Lit b);
uint8_t sriq_rconcl_eq(sriq_RConcl a, sriq_RConcl b);
uint8_t sriq_fires_is(sriq_RConcl a, sriq_RConcl b);
uint8_t sriq_hstate_eq(sriq_HState a, sriq_HState b);
types_ATerm sriq_ex_fx(int64_t f);
types_ATerm sriq_ex_u(int64_t u);
types_Lit sriq_ex_a1(int64_t b, types_ATerm t);
types_Lit sriq_ex_a2(int64_t r, types_ATerm a, types_ATerm b);
sriq_Pos sriq_ex_pos(int64_t k, uint8_t inner);
uint32_t sriq_ex_side(types_Lit l, types_ATerm s);
slop_list_types_Lit sriq_ex_l0(slop_arena* arena);
slop_list_types_Lit sriq_ex_l1(slop_arena* arena, types_Lit a);
slop_list_types_Lit sriq_ex_l2(slop_arena* arena, types_Lit a, types_Lit b);
slop_list_types_Lit sriq_ex_l3(slop_arena* arena, types_Lit a, types_Lit b, types_Lit c);
sriqorder_SriqOrder sriq_ex_ord(slop_arena* arena);
sriq_Premise sriq_ex_sel(slop_arena* arena, slop_list_types_Lit head, types_Lit l);
sriq_Premise sriq_ex_fac(slop_arena* arena);
sriq_BodyView sriq_ex_body(slop_arena* arena, slop_list_types_Lit body, slop_list_types_Lit head, types_Lit l);
sriq_RConcl sriq_ex_rc(slop_arena* arena, uint8_t fires, slop_list_types_Lit body, slop_list_types_Lit head);
sriq_HState sriq_ex_hs(slop_arena* arena, uint8_t fires, slop_list_types_Lit body, slop_list_types_Lit head);
sriqorder_SriqOrder sriq_ex_kids_ord(slop_arena* arena);
slop_list_u32 sriq_ex_ids(slop_arena* arena, int64_t k);

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

#ifndef SLOP_OPTION_SRIQ_POS_DEFINED
#define SLOP_OPTION_SRIQ_POS_DEFINED
SLOP_OPTION_DEFINE(sriq_Pos, slop_option_sriq_Pos)
#endif

#ifndef SLOP_OPTION_SRIQ_BODYVIEW_DEFINED
#define SLOP_OPTION_SRIQ_BODYVIEW_DEFINED
SLOP_OPTION_DEFINE(sriq_BodyView, slop_option_sriq_BodyView)
#endif

#ifndef SLOP_OPTION_SRIQ_HSTATE_DEFINED
#define SLOP_OPTION_SRIQ_HSTATE_DEFINED
SLOP_OPTION_DEFINE(sriq_HState, slop_option_sriq_HState)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_SRIQ_CSUB_DEFINED
#define SLOP_OPTION_SRIQ_CSUB_DEFINED
SLOP_OPTION_DEFINE(sriq_CSub, slop_option_sriq_CSub)
#endif

#ifndef SLOP_OPTION_SRIQ_SUCCSIG_DEFINED
#define SLOP_OPTION_SRIQ_SUCCSIG_DEFINED
SLOP_OPTION_DEFINE(sriq_SuccSig, slop_option_sriq_SuccSig)
#endif

#ifndef SLOP_OPTION_SRIQ_PRELIT_DEFINED
#define SLOP_OPTION_SRIQ_PRELIT_DEFINED
SLOP_OPTION_DEFINE(sriq_PreLit, slop_option_sriq_PreLit)
#endif

#ifndef SLOP_OPTION_SRIQ_KSETS_DEFINED
#define SLOP_OPTION_SRIQ_KSETS_DEFINED
SLOP_OPTION_DEFINE(sriq_KSets, slop_option_sriq_KSets)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_SRIQ_SUCCCONCL_DEFINED
#define SLOP_OPTION_SRIQ_SUCCCONCL_DEFINED
SLOP_OPTION_DEFINE(sriq_SuccConcl, slop_option_sriq_SuccConcl)
#endif

#ifndef SLOP_OPTION_SRIQ_RSUCCCONCL_DEFINED
#define SLOP_OPTION_SRIQ_RSUCCCONCL_DEFINED
SLOP_OPTION_DEFINE(sriq_RSuccConcl, slop_option_sriq_RSuccConcl)
#endif

#ifndef SLOP_OPTION_SRIQ_PREDVIEW_DEFINED
#define SLOP_OPTION_SRIQ_PREDVIEW_DEFINED
SLOP_OPTION_DEFINE(sriq_PredView, slop_option_sriq_PredView)
#endif

#ifndef SLOP_OPTION_SRIQ_PSLOT_DEFINED
#define SLOP_OPTION_SRIQ_PSLOT_DEFINED
SLOP_OPTION_DEFINE(sriq_PSlot, slop_option_sriq_PSlot)
#endif

#ifndef SLOP_OPTION_SRIQ_PSTATE_DEFINED
#define SLOP_OPTION_SRIQ_PSTATE_DEFINED
SLOP_OPTION_DEFINE(sriq_PState, slop_option_sriq_PState)
#endif

#ifndef SLOP_OPTION_SRIQ_PCANDS_DEFINED
#define SLOP_OPTION_SRIQ_PCANDS_DEFINED
SLOP_OPTION_DEFINE(sriq_PCands, slop_option_sriq_PCands)
#endif

#ifndef SLOP_OPTION_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_OPTION_SRIQORDER_CONSTENTRY_DEFINED
SLOP_OPTION_DEFINE(sriqorder_ConstEntry, slop_option_sriqorder_ConstEntry)
#endif

#ifndef SLOP_LIST_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_LIST_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_LIST_SRIQORDER_CONSTENTRY_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqorder_ConstEntry, slop_list_sriqorder_ConstEntry)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef TYPES_ATERM_HASH_EQ_DEFINED
#define TYPES_ATERM_HASH_EQ_DEFINED
static inline uint64_t slop_hash_types_ATerm(const void* key) {
    const types_ATerm* _k = (const types_ATerm*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&(int64_t){ (int64_t)_k->kind }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->fsym }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->cst }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->zi }); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_types_ATerm(const void* a, const void* b) {
    const types_ATerm* _a = (const types_ATerm*)a;
    const types_ATerm* _b = (const types_ATerm*)b;
    return true
        && (_a->kind == _b->kind)
        && (_a->fsym == _b->fsym)
        && (_a->cst == _b->cst)
        && (_a->zi == _b->zi)
    ;
}
#endif

#ifndef TYPES_LIT_HASH_EQ_DEFINED
#define TYPES_LIT_HASH_EQ_DEFINED
#ifndef TYPES_ATERM_HASH_EQ_DEFINED
#define TYPES_ATERM_HASH_EQ_DEFINED
static inline uint64_t slop_hash_types_ATerm(const void* key) {
    const types_ATerm* _k = (const types_ATerm*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&(int64_t){ (int64_t)_k->kind }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->fsym }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->cst }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->zi }); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_types_ATerm(const void* a, const void* b) {
    const types_ATerm* _a = (const types_ATerm*)a;
    const types_ATerm* _b = (const types_ATerm*)b;
    return true
        && (_a->kind == _b->kind)
        && (_a->fsym == _b->fsym)
        && (_a->cst == _b->cst)
        && (_a->zi == _b->zi)
    ;
}
#endif
#ifndef TYPES_ATERM_HASH_EQ_DEFINED
#define TYPES_ATERM_HASH_EQ_DEFINED
static inline uint64_t slop_hash_types_ATerm(const void* key) {
    const types_ATerm* _k = (const types_ATerm*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&(int64_t){ (int64_t)_k->kind }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->fsym }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->cst }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->zi }); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_types_ATerm(const void* a, const void* b) {
    const types_ATerm* _a = (const types_ATerm*)a;
    const types_ATerm* _b = (const types_ATerm*)b;
    return true
        && (_a->kind == _b->kind)
        && (_a->fsym == _b->fsym)
        && (_a->cst == _b->cst)
        && (_a->zi == _b->zi)
    ;
}
#endif
static inline uint64_t slop_hash_types_Lit(const void* key) {
    const types_Lit* _k = (const types_Lit*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&(int64_t){ (int64_t)_k->form }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->pred }); hash *= 1099511628211ULL;
    hash ^= slop_hash_types_ATerm(&_k->t1); hash *= 1099511628211ULL;
    hash ^= slop_hash_types_ATerm(&_k->t2); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_types_Lit(const void* a, const void* b) {
    const types_Lit* _a = (const types_Lit*)a;
    const types_Lit* _b = (const types_Lit*)b;
    return true
        && (_a->form == _b->form)
        && (_a->pred == _b->pred)
        && (slop_eq_types_ATerm(&_a->t1, &_b->t1))
        && (slop_eq_types_ATerm(&_a->t2, &_b->t2))
    ;
}
#endif


#endif
