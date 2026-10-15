#ifndef SLOP_sriqground_H
#define SLOP_sriqground_H

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
#include "slop_sriqindex.h"
#include "slop_sriqctx.h"
#include "slop_sriqorder.h"
#include "slop_sriq.h"
#include "slop_canon.h"

typedef struct howl_sriqground_Post howl_sriqground_Post;
typedef struct howl_sriqground_Hides howl_sriqground_Hides;
typedef struct howl_sriqground_Ground howl_sriqground_Ground;
typedef struct howl_sriqground_PIdx howl_sriqground_PIdx;

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

#ifndef SLOP_LIST_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Clause, slop_list_howl_types_Clause)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_Premise, slop_list_howl_sriq_Premise)
#endif

#ifndef SLOP_LIST_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_EDGE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqctx_Edge, slop_list_howl_sriqctx_Edge)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Premise, slop_option_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Edge, slop_option_howl_sriqctx_Edge)
#endif

struct howl_sriqground_Post {
    int64_t side;
    howl_types_Lit lit;
    int64_t i;
};
typedef struct howl_sriqground_Post howl_sriqground_Post;

#ifndef SLOP_OPTION_HOWL_SRIQGROUND_POST_DEFINED
#define SLOP_OPTION_HOWL_SRIQGROUND_POST_DEFINED
SLOP_OPTION_DEFINE(howl_sriqground_Post, slop_option_howl_sriqground_Post)
#endif

#ifndef SLOP_LIST_HOWL_SRIQGROUND_POST_DEFINED
#define SLOP_LIST_HOWL_SRIQGROUND_POST_DEFINED
#define SLOP_LIST_HOWL_SRIQGROUND_POST_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqground_Post, slop_list_howl_sriqground_Post)
#endif

struct howl_sriqground_Hides {
    uint8_t all;
    slop_list_int ids;
};
typedef struct howl_sriqground_Hides howl_sriqground_Hides;

#ifndef SLOP_OPTION_HOWL_SRIQGROUND_HIDES_DEFINED
#define SLOP_OPTION_HOWL_SRIQGROUND_HIDES_DEFINED
SLOP_OPTION_DEFINE(howl_sriqground_Hides, slop_option_howl_sriqground_Hides)
#endif

#ifndef SLOP_LIST_HOWL_SRIQGROUND_HIDES_DEFINED
#define SLOP_LIST_HOWL_SRIQGROUND_HIDES_DEFINED
#define SLOP_LIST_HOWL_SRIQGROUND_HIDES_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqground_Hides, slop_list_howl_sriqground_Hides)
#endif

struct howl_sriqground_Ground {
    slop_list_howl_types_Clause gs;
    slop_list_u8 fresh;
    howl_sriqindex_SubIndex ix;
    slop_list_howl_sriqground_Post posts;
    slop_list_howl_sriqground_Hides hides;
    slop_list_u8 shown;
    slop_list_howl_sriq_Premise ps;
    slop_list_int pm;
    slop_list_int bysel;
};
typedef struct howl_sriqground_Ground howl_sriqground_Ground;

#ifndef SLOP_OPTION_HOWL_SRIQGROUND_GROUND_DEFINED
#define SLOP_OPTION_HOWL_SRIQGROUND_GROUND_DEFINED
SLOP_OPTION_DEFINE(howl_sriqground_Ground, slop_option_howl_sriqground_Ground)
#endif

struct howl_sriqground_PIdx {
    slop_list_howl_sriq_Premise ps;
    slop_list_int bysel;
};
typedef struct howl_sriqground_PIdx howl_sriqground_PIdx;

#ifndef SLOP_OPTION_HOWL_SRIQGROUND_PIDX_DEFINED
#define SLOP_OPTION_HOWL_SRIQGROUND_PIDX_DEFINED
SLOP_OPTION_DEFINE(howl_sriqground_PIdx, slop_option_howl_sriqground_PIdx)
#endif

uint8_t howl_sriqground_lit_gf(howl_types_Lit l);
uint8_t howl_sriqground_ground_clause(howl_types_Clause c);
slop_list_howl_types_Clause howl_sriqground_set_at(howl_sriqctx_Structure st, int64_t v, slop_list_howl_types_Clause nobody);
uint8_t howl_sriqground_ctx_root(howl_sriqctx_Structure st, int64_t v);
slop_list_howl_types_Clause howl_sriqground_ground_part(slop_arena* arena, slop_list_howl_types_Clause cs);
slop_list_u8 howl_sriqground_fresh_flags(slop_arena* arena, slop_list_howl_types_Clause gs, slop_list_howl_types_Clause news);
howl_types_Clause howl_sriqground_clause_at(slop_list_howl_types_Clause cs, int64_t k, howl_types_Clause fallback);
uint8_t howl_sriqground_sorted_has(slop_list_howl_types_Clause cs, howl_types_Clause c);
int64_t howl_sriqground_post_cmp(howl_sriqground_Post a, howl_sriqground_Post b);
howl_sriqground_Post howl_sriqground_post_at(slop_list_howl_sriqground_Post ps, int64_t k, howl_sriqground_Post fallback);
slop_list_howl_sriqground_Post howl_sriqground_postings(slop_arena* arena, slop_list_howl_types_Clause gs);
int64_t howl_sriqground_post_key_cmp(howl_sriqground_Post p, int64_t side, howl_types_Lit l);
int64_t howl_sriqground_post_lower(slop_list_howl_sriqground_Post ps, int64_t side, howl_types_Lit l, howl_sriqground_Post fallback);
slop_list_int howl_sriqground_subsumed_by(slop_arena* arena, slop_list_howl_types_Clause gs, slop_list_howl_sriqground_Post ps, howl_types_Clause c);
slop_list_int howl_sriqground_subsumed_from(slop_arena* arena, slop_list_howl_types_Clause gs, slop_list_howl_sriqground_Post ps, howl_types_Clause c, howl_sriqground_Post kp, howl_sriqground_Post p0);
slop_option_howl_sriqground_Post howl_sriqground_key_lit(howl_types_Clause c);
uint8_t howl_sriqground_member_subsumed(slop_list_howl_types_Clause gs, int64_t i, howl_types_Clause c);
howl_sriqground_Hides howl_sriqground_hides_of(slop_arena* arena, slop_list_howl_types_Clause gs, slop_list_howl_sriqground_Post ps, slop_list_howl_types_Clause cs);
int64_t howl_sriqground_int_at(slop_list_int xs, int64_t k);
slop_list_int howl_sriqground_int_set(slop_arena* arena, slop_list_int xs);
uint8_t howl_sriqground_int_has(slop_list_int xs, int64_t x);
slop_list_howl_sriqground_Hides howl_sriqground_all_hides(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_types_Clause gs, slop_list_howl_sriqground_Post ps);
slop_list_u8 howl_sriqground_shown_flags(slop_arena* arena, howl_sriqctx_Structure st, int64_t n, slop_list_howl_sriqground_Hides hs);
void howl_sriqground_bump_ids(slop_list_int counts, slop_list_int ids);
void howl_sriqground_bump_all(slop_list_int counts, int64_t n);
howl_sriq_Premise howl_sriqground_prem_at(slop_list_howl_sriq_Premise ps, int64_t k, howl_sriq_Premise fallback);
slop_list_int howl_sriqground_sel_sorted(slop_arena* arena, slop_list_howl_sriq_Premise ps);
howl_types_Clause howl_sriqground_unit_of(slop_arena* arena, howl_types_Lit a);
uint8_t howl_sriqground_held_in(slop_arena* arena, howl_sriqindex_SubIndex ix, howl_types_Lit a);
slop_list_howl_sriq_Premise howl_sriqground_member_premises(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Clause gs);
slop_list_int howl_sriqground_premise_members(slop_arena* arena, slop_list_howl_types_Clause gs);
howl_sriqground_Ground howl_sriqground_ground_of(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqctx_Structure st, slop_list_howl_types_Clause root_news);
howl_sriqground_PIdx howl_sriqground_pidx_of(slop_arena* arena, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriq_Premise howl_sriqground_pidx_find(slop_arena* arena, howl_sriqground_PIdx ix, howl_types_Lit l);
int64_t howl_sriqground_form_rank(howl_types_LitForm f);
int64_t howl_sriqground_key_cmp_lit(howl_types_Lit l, int64_t rank, uint32_t pred);
slop_list_howl_sriq_Premise howl_sriqground_pidx_key_range(slop_arena* arena, howl_sriqground_PIdx ix, int64_t rank, uint32_t pred);
int64_t howl_sriqground_key_lower(howl_sriqground_PIdx ix, int64_t rank, uint32_t pred, howl_sriq_Premise p0);
howl_sriqground_PIdx howl_sriqground_pick_ix(int64_t j, int64_t i, howl_sriqground_PIdx dix, howl_sriqground_PIdx oix, howl_sriqground_PIdx aix);
howl_types_Lit howl_sriqground_idx_sel(howl_sriqground_PIdx ix, int64_t k, howl_sriq_Premise p0);
int64_t howl_sriqground_idx_lower(howl_sriqground_PIdx ix, howl_types_Lit l, howl_sriq_Premise p0);
uint8_t howl_sriqground_g_visible(howl_sriqground_Ground gd, int64_t v, int64_t i);
uint8_t howl_sriqground_g_fresh(howl_sriqground_Ground gd, int64_t i);
uint8_t howl_sriqground_g_in_hat(howl_sriqground_Ground gd, howl_types_Clause c);
uint8_t howl_sriqground_g_held(slop_arena* arena, howl_sriqground_Ground gd, howl_types_Lit a);
howl_sriq_Premise howl_sriqground_g_premise_at(howl_sriqground_Ground gd, int64_t k, howl_sriq_Premise fallback);
int64_t howl_sriqground_g_member_of(howl_sriqground_Ground gd, int64_t k);
slop_list_int howl_sriqground_g_sel_range(slop_arena* arena, howl_sriqground_Ground gd, howl_types_Lit l);
howl_types_Lit howl_sriqground_sel_of(howl_sriqground_Ground gd, int64_t k, howl_sriq_Premise p0);
int64_t howl_sriqground_sel_lower(howl_sriqground_Ground gd, howl_types_Lit l, howl_sriq_Premise p0);
slop_list_int howl_sriqground_g_body_members(slop_arena* arena, howl_sriqground_Ground gd, howl_types_Lit l);
howl_types_Clause howl_sriqground_g_member(howl_sriqground_Ground gd, int64_t i, howl_types_Clause fallback);
uint8_t howl_sriqground_g_shown(howl_sriqground_Ground gd, int64_t i);
slop_list_howl_types_Clause howl_sriqground_g_root_units(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqground_Ground gd);
int64_t howl_sriqground_view_total(howl_sriqctx_Structure st);
uint8_t howl_sriqground_has_empty(slop_list_howl_types_Clause cs);
howl_sriqctx_Structure howl_sriqground_materialise(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqctx_Structure st);
slop_list_howl_types_Clause howl_sriqground_min_with(slop_arena* arena, slop_list_howl_types_Clause ws, slop_list_howl_types_Clause cs);
slop_list_howl_types_Clause howl_sriqground_visible_of(slop_arena* arena, howl_sriqground_Ground gd, int64_t v);
slop_list_howl_sriqctx_Edge howl_sriqground_eg_edges(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqground_Ground gd, int64_t v);
slop_list_u32 howl_sriqground_consts_in(slop_arena* arena, howl_types_Lit l);
uint8_t howl_sriqground_edge_in(slop_list_howl_sriqctx_Edge es, howl_sriqctx_Edge e);

#ifndef SLOP_OPTION_HOWL_SRIQGROUND_POST_DEFINED
#define SLOP_OPTION_HOWL_SRIQGROUND_POST_DEFINED
SLOP_OPTION_DEFINE(howl_sriqground_Post, slop_option_howl_sriqground_Post)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQGROUND_HIDES_DEFINED
#define SLOP_OPTION_HOWL_SRIQGROUND_HIDES_DEFINED
SLOP_OPTION_DEFINE(howl_sriqground_Hides, slop_option_howl_sriqground_Hides)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Premise, slop_option_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQGROUND_GROUND_DEFINED
#define SLOP_OPTION_HOWL_SRIQGROUND_GROUND_DEFINED
SLOP_OPTION_DEFINE(howl_sriqground_Ground, slop_option_howl_sriqground_Ground)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQGROUND_PIDX_DEFINED
#define SLOP_OPTION_HOWL_SRIQGROUND_PIDX_DEFINED
SLOP_OPTION_DEFINE(howl_sriqground_PIdx, slop_option_howl_sriqground_PIdx)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Edge, slop_option_howl_sriqctx_Edge)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_CTXSET_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_CTXSET_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_CtxSet, slop_option_howl_sriqctx_CtxSet)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_HOWL_TYPES_LIT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Lit, slop_list_howl_types_Lit)
#endif

#ifndef SLOP_LIST_HOWL_SRIQCTX_CTXSET_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_CTXSET_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_CTXSET_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqctx_CtxSet, slop_list_howl_sriqctx_CtxSet)
#endif


#endif
