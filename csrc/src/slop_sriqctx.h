#ifndef SLOP_sriqctx_H
#define SLOP_sriqctx_H

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
#include "slop_sriqsubsume.h"
#include "slop_sriqorder.h"

typedef struct howl_sriqctx_Triggers howl_sriqctx_Triggers;
typedef struct howl_sriqctx_CoreChoice howl_sriqctx_CoreChoice;
typedef struct howl_sriqctx_Edge howl_sriqctx_Edge;
typedef struct howl_sriqctx_Ctx howl_sriqctx_Ctx;
typedef struct howl_sriqctx_CtxSet howl_sriqctx_CtxSet;
typedef struct howl_sriqctx_Structure howl_sriqctx_Structure;

typedef enum {
    howl_sriqctx_Strategy_st_trivial,
    howl_sriqctx_Strategy_st_eager,
    howl_sriqctx_Strategy_st_cautious
} howl_sriqctx_Strategy;

typedef enum {
    howl_sriqctx_CoreKind_cc_empty,
    howl_sriqctx_CoreKind_cc_k1,
    howl_sriqctx_CoreKind_cc_unary
} howl_sriqctx_CoreKind;

typedef enum {
    howl_sriqctx_EdgeLabel_el_fn,
    howl_sriqctx_EdgeLabel_el_const
} howl_sriqctx_EdgeLabel;

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

#ifndef SLOP_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_HOWL_TYPES_LIT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Lit, slop_list_howl_types_Lit)
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

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

struct howl_sriqctx_Triggers {
    slop_list_u8 unary;
    slop_list_u8 out;
    slop_list_u8 in;
    slop_list_u8 body;
    slop_list_u8 cls;
    slop_list_u8 role;
    slop_list_u32 sole;
};
typedef struct howl_sriqctx_Triggers howl_sriqctx_Triggers;

#ifndef SLOP_OPTION_HOWL_SRIQCTX_TRIGGERS_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_TRIGGERS_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Triggers, slop_option_howl_sriqctx_Triggers)
#endif

struct howl_sriqctx_CoreChoice {
    howl_sriqctx_CoreKind kind;
    uint32_t cls;
};
typedef struct howl_sriqctx_CoreChoice howl_sriqctx_CoreChoice;

#ifndef SLOP_OPTION_HOWL_SRIQCTX_CORECHOICE_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_CORECHOICE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_CoreChoice, slop_option_howl_sriqctx_CoreChoice)
#endif

struct howl_sriqctx_Edge {
    uint32_t from;
    uint32_t to;
    howl_sriqctx_EdgeLabel lk;
    uint32_t label;
};
typedef struct howl_sriqctx_Edge howl_sriqctx_Edge;

#ifndef SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Edge, slop_option_howl_sriqctx_Edge)
#endif

#ifndef SLOP_LIST_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_EDGE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqctx_Edge, slop_list_howl_sriqctx_Edge)
#endif

struct howl_sriqctx_Ctx {
    slop_list_howl_types_Lit core;
    uint8_t root;
};
typedef struct howl_sriqctx_Ctx howl_sriqctx_Ctx;

#ifndef SLOP_OPTION_HOWL_SRIQCTX_CTX_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_CTX_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Ctx, slop_option_howl_sriqctx_Ctx)
#endif

#ifndef SLOP_LIST_HOWL_SRIQCTX_CTX_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_CTX_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_CTX_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqctx_Ctx, slop_list_howl_sriqctx_Ctx)
#endif

struct howl_sriqctx_CtxSet {
    slop_list_howl_types_Clause cs;
};
typedef struct howl_sriqctx_CtxSet howl_sriqctx_CtxSet;

#ifndef SLOP_OPTION_HOWL_SRIQCTX_CTXSET_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_CTXSET_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_CtxSet, slop_option_howl_sriqctx_CtxSet)
#endif

#ifndef SLOP_LIST_HOWL_SRIQCTX_CTXSET_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_CTXSET_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_CTXSET_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqctx_CtxSet, slop_list_howl_sriqctx_CtxSet)
#endif

struct howl_sriqctx_Structure {
    slop_list_howl_sriqctx_Ctx ctxs;
    slop_list_howl_sriqctx_CtxSet sets;
    slop_list_howl_sriqctx_Edge edges;
    howl_sriqorder_SriqOrder ord;
};
typedef struct howl_sriqctx_Structure howl_sriqctx_Structure;

#ifndef SLOP_OPTION_HOWL_SRIQCTX_STRUCTURE_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_STRUCTURE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Structure, slop_option_howl_sriqctx_Structure)
#endif

uint32_t howl_sriqctx_no_id(void);
uint8_t howl_sriqctx_flag_at(slop_list_u8 xs, uint32_t i);
uint32_t howl_sriqctx_u32_at(slop_list_u32 xs, uint32_t i);
slop_list_u8 howl_sriqctx_falses(slop_arena* arena, int64_t n);
slop_list_u32 howl_sriqctx_no_ids(slop_arena* arena, int64_t n);
uint8_t howl_sriqctx_raise(slop_list_u8 xs, uint32_t i);
int64_t howl_sriqctx_count_true(slop_list_u8 xs);
uint8_t howl_sriqctx_is_kind(howl_types_ATerm t, howl_types_AKind k);
uint8_t howl_sriqctx_has_lit(slop_list_howl_types_Lit ls, howl_types_Lit l);
uint8_t howl_sriqctx_note_body_lit(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_note_role_sides(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_note_any_lit(howl_sriqctx_Triggers tr, slop_list_u8 many, howl_types_Lit l);
uint8_t howl_sriqctx_note_sole(howl_sriqctx_Triggers tr, slop_list_u8 many, howl_types_Lit l);
uint8_t howl_sriqctx_note_clause(howl_sriqctx_Triggers tr, slop_list_u8 many, howl_types_Clause c);
uint8_t howl_sriqctx_drop_many(howl_sriqctx_Triggers tr, slop_list_u8 many);
howl_sriqctx_Triggers howl_sriqctx_build_triggers(slop_arena* arena, slop_list_howl_types_Clause clauses, int64_t nc, int64_t nr, int64_t nf);
howl_sriqctx_Triggers howl_sriqctx_triggers_of(slop_arena* arena, howl_sriqclauses_SriqClauses sc);
uint32_t howl_sriqctx_sole_at(howl_sriqctx_Triggers tr, uint32_t f);
uint8_t howl_sriqctx_both_kinds(howl_types_Lit l, howl_types_AKind a, howl_types_AKind b);
uint8_t howl_sriqctx_pair_kinds(howl_types_Lit l, howl_types_AKind a, howl_types_AKind b);
uint8_t howl_sriqctx_su_unary(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_su_binary(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_in_su(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_pr_unary(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_pr_binary(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_pr_eq(howl_types_Lit l);
uint8_t howl_sriqctx_in_pr(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_sur_binary(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_in_sur(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_in_prr(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_aterm_ground(howl_types_ATerm t);
uint8_t howl_sriqctx_lit_ground(howl_types_Lit l);
uint8_t howl_sriqctx_aterm_has_x(howl_types_ATerm t);
uint8_t howl_sriqctx_mentions_x(howl_types_Lit l);
int64_t howl_sriqctx_tau_su(howl_sriqctx_Triggers tr);
int64_t howl_sriqctx_tau_pr(howl_sriqctx_Triggers tr);
int64_t howl_sriqctx_pow2_sat(int64_t k);
int64_t howl_sriqctx_omega(howl_sriqctx_Strategy s, howl_sriqctx_Triggers tr);
int64_t howl_sriqctx_omega_d(int64_t nquery);
howl_sriqctx_CoreChoice howl_sriqctx_choice_of(howl_sriqctx_CoreKind k, uint32_t b);
howl_sriqctx_CoreChoice howl_sriqctx_cautious_choice(howl_sriqctx_Triggers tr, uint32_t f, slop_list_howl_types_Lit k1);
howl_sriqctx_CoreChoice howl_sriqctx_strat_choice(howl_sriqctx_Strategy s, howl_sriqctx_Triggers tr, uint32_t f, slop_list_howl_types_Lit k1);
slop_list_howl_types_Lit howl_sriqctx_core_of(slop_arena* arena, howl_sriqctx_CoreChoice cc, slop_list_howl_types_Lit k1);
howl_sriqctx_Structure howl_sriqctx_init_structure(slop_arena* arena, int64_t nquery, int64_t nconst);
howl_sriqctx_Structure howl_sriqctx_with_hidden(slop_arena* arena, howl_sriqctx_Structure st, slop_list_u32 hidden);
int64_t howl_sriqctx_ctx_count(howl_sriqctx_Structure st);
slop_option_howl_sriqctx_Ctx howl_sriqctx_ctx_at(howl_sriqctx_Structure st, int64_t v);
slop_option_howl_sriqctx_CtxSet howl_sriqctx_set_at(howl_sriqctx_Structure st, int64_t v);
uint8_t howl_sriqctx_lits_same(slop_list_howl_types_Lit a, slop_list_howl_types_Lit b);
uint8_t howl_sriqctx_core_matches(howl_sriqctx_Ctx c, slop_list_howl_types_Lit core);
uint32_t howl_sriqctx_ctx_by_core(howl_sriqctx_Structure st, slop_list_howl_types_Lit core);
uint8_t howl_sriqctx_var_ok(howl_types_ATerm t, uint8_t root);
uint8_t howl_sriqctx_side_x(howl_types_ATerm s, howl_types_ATerm t);
uint8_t howl_sriqctx_side_u(howl_types_ATerm s, howl_types_ATerm t);
uint8_t howl_sriqctx_binary_ok(howl_types_Lit l);
uint8_t howl_sriqctx_lit_ok(howl_types_Lit l, uint8_t root);
uint8_t howl_sriqctx_body_lit_ok(howl_types_Lit l, uint8_t root);
uint8_t howl_sriqctx_ctx_clause_ok(uint8_t root, howl_types_Clause c);
slop_list_howl_types_Clause howl_sriqctx_set_or_none(slop_arena* arena, howl_sriqctx_Structure st, int64_t v);
uint8_t howl_sriqctx_q_of(slop_arena* arena, howl_sriqctx_Structure st, int64_t v, slop_list_howl_types_Lit body, slop_list_howl_types_Lit head);
slop_list_howl_types_Lit howl_sriqctx_atom_x(slop_arena* arena, uint32_t b);
uint8_t howl_sriqctx_q_inconsistent(slop_arena* arena, howl_sriqctx_Structure st);
uint8_t howl_sriqctx_q_unsat(slop_arena* arena, howl_sriqctx_Structure st, uint32_t b);
uint8_t howl_sriqctx_q_hidden_unsat(slop_arena* arena, howl_sriqctx_Structure st, int64_t nquery, slop_list_u32 hidden);
uint8_t howl_sriqctx_q_holds(slop_arena* arena, howl_sriqctx_Structure st, uint32_t b, uint32_t a);
uint8_t howl_sriqctx_q_thing(slop_arena* arena, howl_sriqctx_Structure st, uint32_t a);

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_TRIGGERS_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_TRIGGERS_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Triggers, slop_option_howl_sriqctx_Triggers)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_CORECHOICE_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_CORECHOICE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_CoreChoice, slop_option_howl_sriqctx_CoreChoice)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Edge, slop_option_howl_sriqctx_Edge)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_CTX_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_CTX_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Ctx, slop_option_howl_sriqctx_Ctx)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_CTXSET_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_CTXSET_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_CtxSet, slop_option_howl_sriqctx_CtxSet)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_STRUCTURE_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_STRUCTURE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Structure, slop_option_howl_sriqctx_Structure)
#endif


#endif
