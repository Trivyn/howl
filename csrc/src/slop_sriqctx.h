#ifndef SLOP_sriqctx_H
#define SLOP_sriqctx_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_sriqclauses.h"
#include "slop_sriqorder.h"

typedef struct sriqctx_Triggers sriqctx_Triggers;
typedef struct sriqctx_CoreChoice sriqctx_CoreChoice;
typedef struct sriqctx_Edge sriqctx_Edge;
typedef struct sriqctx_Ctx sriqctx_Ctx;
typedef struct sriqctx_CtxSet sriqctx_CtxSet;
typedef struct sriqctx_Structure sriqctx_Structure;

typedef enum {
    sriqctx_Strategy_st_trivial,
    sriqctx_Strategy_st_eager,
    sriqctx_Strategy_st_cautious
} sriqctx_Strategy;

typedef enum {
    sriqctx_CoreKind_cc_empty,
    sriqctx_CoreKind_cc_k1,
    sriqctx_CoreKind_cc_unary
} sriqctx_CoreKind;

typedef enum {
    sriqctx_EdgeLabel_el_fn,
    sriqctx_EdgeLabel_el_const
} sriqctx_EdgeLabel;

#ifndef SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_IMPL_DEFINED
SLOP_LIST_DEFINE(uint8_t, slop_list_u8)
#endif

#ifndef SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_IMPL_DEFINED
SLOP_LIST_DEFINE(uint32_t, slop_list_u32)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
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

#ifndef SLOP_LIST_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_TYPES_CLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Clause, slop_list_types_Clause)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

struct sriqctx_Triggers {
    slop_list_u8 unary;
    slop_list_u8 out;
    slop_list_u8 in;
    slop_list_u8 body;
    slop_list_u8 cls;
    slop_list_u8 role;
    slop_list_u32 sole;
};
typedef struct sriqctx_Triggers sriqctx_Triggers;

#ifndef SLOP_OPTION_SRIQCTX_TRIGGERS_DEFINED
#define SLOP_OPTION_SRIQCTX_TRIGGERS_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Triggers, slop_option_sriqctx_Triggers)
#endif

struct sriqctx_CoreChoice {
    sriqctx_CoreKind kind;
    uint32_t cls;
};
typedef struct sriqctx_CoreChoice sriqctx_CoreChoice;

#ifndef SLOP_OPTION_SRIQCTX_CORECHOICE_DEFINED
#define SLOP_OPTION_SRIQCTX_CORECHOICE_DEFINED
SLOP_OPTION_DEFINE(sriqctx_CoreChoice, slop_option_sriqctx_CoreChoice)
#endif

struct sriqctx_Edge {
    uint32_t from;
    uint32_t to;
    sriqctx_EdgeLabel lk;
    uint32_t label;
};
typedef struct sriqctx_Edge sriqctx_Edge;

#ifndef SLOP_OPTION_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Edge, slop_option_sriqctx_Edge)
#endif

#ifndef SLOP_LIST_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_SRIQCTX_EDGE_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqctx_Edge, slop_list_sriqctx_Edge)
#endif

struct sriqctx_Ctx {
    slop_list_types_Lit core;
    uint8_t root;
};
typedef struct sriqctx_Ctx sriqctx_Ctx;

#ifndef SLOP_OPTION_SRIQCTX_CTX_DEFINED
#define SLOP_OPTION_SRIQCTX_CTX_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Ctx, slop_option_sriqctx_Ctx)
#endif

#ifndef SLOP_LIST_SRIQCTX_CTX_DEFINED
#define SLOP_LIST_SRIQCTX_CTX_DEFINED
#define SLOP_LIST_SRIQCTX_CTX_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqctx_Ctx, slop_list_sriqctx_Ctx)
#endif

struct sriqctx_CtxSet {
    slop_list_types_Clause cs;
};
typedef struct sriqctx_CtxSet sriqctx_CtxSet;

#ifndef SLOP_OPTION_SRIQCTX_CTXSET_DEFINED
#define SLOP_OPTION_SRIQCTX_CTXSET_DEFINED
SLOP_OPTION_DEFINE(sriqctx_CtxSet, slop_option_sriqctx_CtxSet)
#endif

#ifndef SLOP_LIST_SRIQCTX_CTXSET_DEFINED
#define SLOP_LIST_SRIQCTX_CTXSET_DEFINED
#define SLOP_LIST_SRIQCTX_CTXSET_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqctx_CtxSet, slop_list_sriqctx_CtxSet)
#endif

struct sriqctx_Structure {
    slop_list_sriqctx_Ctx ctxs;
    slop_list_sriqctx_CtxSet sets;
    slop_list_sriqctx_Edge edges;
    sriqorder_SriqOrder ord;
};
typedef struct sriqctx_Structure sriqctx_Structure;

#ifndef SLOP_OPTION_SRIQCTX_STRUCTURE_DEFINED
#define SLOP_OPTION_SRIQCTX_STRUCTURE_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Structure, slop_option_sriqctx_Structure)
#endif

uint32_t sriqctx_no_id(void);
uint8_t sriqctx_flag_at(slop_list_u8 xs, uint32_t i);
uint32_t sriqctx_u32_at(slop_list_u32 xs, uint32_t i);
slop_list_u8 sriqctx_falses(slop_arena* arena, int64_t n);
slop_list_u32 sriqctx_no_ids(slop_arena* arena, int64_t n);
uint8_t sriqctx_raise(slop_list_u8 xs, uint32_t i);
int64_t sriqctx_count_true(slop_list_u8 xs);
uint8_t sriqctx_is_kind(types_ATerm t, types_AKind k);
uint8_t sriqctx_has_lit(slop_list_types_Lit ls, types_Lit l);
uint8_t sriqctx_note_body_lit(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_note_role_sides(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_note_any_lit(sriqctx_Triggers tr, slop_list_u8 many, types_Lit l);
uint8_t sriqctx_note_sole(sriqctx_Triggers tr, slop_list_u8 many, types_Lit l);
uint8_t sriqctx_note_clause(sriqctx_Triggers tr, slop_list_u8 many, types_Clause c);
uint8_t sriqctx_drop_many(sriqctx_Triggers tr, slop_list_u8 many);
sriqctx_Triggers sriqctx_build_triggers(slop_arena* arena, slop_list_types_Clause clauses, int64_t nc, int64_t nr, int64_t nf);
sriqctx_Triggers sriqctx_triggers_of(slop_arena* arena, sriqclauses_SriqClauses sc);
uint32_t sriqctx_sole_at(sriqctx_Triggers tr, uint32_t f);
uint8_t sriqctx_both_kinds(types_Lit l, types_AKind a, types_AKind b);
uint8_t sriqctx_pair_kinds(types_Lit l, types_AKind a, types_AKind b);
uint8_t sriqctx_su_unary(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_su_binary(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_in_su(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_pr_unary(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_pr_binary(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_pr_eq(types_Lit l);
uint8_t sriqctx_in_pr(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_sur_binary(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_in_sur(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_in_prr(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_aterm_ground(types_ATerm t);
uint8_t sriqctx_lit_ground(types_Lit l);
uint8_t sriqctx_aterm_has_x(types_ATerm t);
uint8_t sriqctx_mentions_x(types_Lit l);
int64_t sriqctx_tau_su(sriqctx_Triggers tr);
int64_t sriqctx_tau_pr(sriqctx_Triggers tr);
int64_t sriqctx_pow2_sat(int64_t k);
int64_t sriqctx_omega(sriqctx_Strategy s, sriqctx_Triggers tr);
int64_t sriqctx_omega_d(int64_t nquery);
sriqctx_CoreChoice sriqctx_choice_of(sriqctx_CoreKind k, uint32_t b);
sriqctx_CoreChoice sriqctx_cautious_choice(sriqctx_Triggers tr, uint32_t f, slop_list_types_Lit k1);
sriqctx_CoreChoice sriqctx_strat_choice(sriqctx_Strategy s, sriqctx_Triggers tr, uint32_t f, slop_list_types_Lit k1);
slop_list_types_Lit sriqctx_core_of(slop_arena* arena, sriqctx_CoreChoice cc, slop_list_types_Lit k1);
sriqctx_Structure sriqctx_init_structure(slop_arena* arena, int64_t nquery, int64_t nconst);
int64_t sriqctx_ctx_count(sriqctx_Structure st);
slop_option_sriqctx_Ctx sriqctx_ctx_at(sriqctx_Structure st, int64_t v);
slop_option_sriqctx_CtxSet sriqctx_set_at(sriqctx_Structure st, int64_t v);
uint8_t sriqctx_lits_same(slop_list_types_Lit a, slop_list_types_Lit b);
uint8_t sriqctx_core_matches(sriqctx_Ctx c, slop_list_types_Lit core);
uint32_t sriqctx_ctx_by_core(sriqctx_Structure st, slop_list_types_Lit core);
uint8_t sriqctx_var_ok(types_ATerm t, uint8_t root);
uint8_t sriqctx_side_x(types_ATerm s, types_ATerm t);
uint8_t sriqctx_side_u(types_ATerm s, types_ATerm t);
uint8_t sriqctx_binary_ok(types_Lit l);
uint8_t sriqctx_lit_ok(types_Lit l, uint8_t root);
uint8_t sriqctx_body_lit_ok(types_Lit l, uint8_t root);
uint8_t sriqctx_ctx_clause_ok(uint8_t root, types_Clause c);

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_SRIQCTX_TRIGGERS_DEFINED
#define SLOP_OPTION_SRIQCTX_TRIGGERS_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Triggers, slop_option_sriqctx_Triggers)
#endif

#ifndef SLOP_OPTION_SRIQCTX_CORECHOICE_DEFINED
#define SLOP_OPTION_SRIQCTX_CORECHOICE_DEFINED
SLOP_OPTION_DEFINE(sriqctx_CoreChoice, slop_option_sriqctx_CoreChoice)
#endif

#ifndef SLOP_OPTION_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Edge, slop_option_sriqctx_Edge)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

#ifndef SLOP_OPTION_SRIQCTX_CTX_DEFINED
#define SLOP_OPTION_SRIQCTX_CTX_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Ctx, slop_option_sriqctx_Ctx)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_SRIQCTX_CTXSET_DEFINED
#define SLOP_OPTION_SRIQCTX_CTXSET_DEFINED
SLOP_OPTION_DEFINE(sriqctx_CtxSet, slop_option_sriqctx_CtxSet)
#endif

#ifndef SLOP_OPTION_SRIQCTX_STRUCTURE_DEFINED
#define SLOP_OPTION_SRIQCTX_STRUCTURE_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Structure, slop_option_sriqctx_Structure)
#endif


#endif
