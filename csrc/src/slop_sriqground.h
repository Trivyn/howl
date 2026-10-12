#ifndef SLOP_sriqground_H
#define SLOP_sriqground_H

#include "../runtime/slop_runtime.h"
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

typedef struct sriqground_Post sriqground_Post;
typedef struct sriqground_Hides sriqground_Hides;
typedef struct sriqground_Ground sriqground_Ground;
typedef struct sriqground_PIdx sriqground_PIdx;

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

#ifndef SLOP_LIST_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_TYPES_CLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Clause, slop_list_types_Clause)
#endif

#ifndef SLOP_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(sriq_Premise, slop_list_sriq_Premise)
#endif

#ifndef SLOP_LIST_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_SRIQCTX_EDGE_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqctx_Edge, slop_list_sriqctx_Edge)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(sriq_Premise, slop_option_sriq_Premise)
#endif

#ifndef SLOP_OPTION_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Edge, slop_option_sriqctx_Edge)
#endif

struct sriqground_Post {
    int64_t side;
    types_Lit lit;
    int64_t i;
};
typedef struct sriqground_Post sriqground_Post;

#ifndef SLOP_OPTION_SRIQGROUND_POST_DEFINED
#define SLOP_OPTION_SRIQGROUND_POST_DEFINED
SLOP_OPTION_DEFINE(sriqground_Post, slop_option_sriqground_Post)
#endif

#ifndef SLOP_LIST_SRIQGROUND_POST_DEFINED
#define SLOP_LIST_SRIQGROUND_POST_DEFINED
#define SLOP_LIST_SRIQGROUND_POST_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqground_Post, slop_list_sriqground_Post)
#endif

struct sriqground_Hides {
    uint8_t all;
    slop_list_int ids;
};
typedef struct sriqground_Hides sriqground_Hides;

#ifndef SLOP_OPTION_SRIQGROUND_HIDES_DEFINED
#define SLOP_OPTION_SRIQGROUND_HIDES_DEFINED
SLOP_OPTION_DEFINE(sriqground_Hides, slop_option_sriqground_Hides)
#endif

#ifndef SLOP_LIST_SRIQGROUND_HIDES_DEFINED
#define SLOP_LIST_SRIQGROUND_HIDES_DEFINED
#define SLOP_LIST_SRIQGROUND_HIDES_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqground_Hides, slop_list_sriqground_Hides)
#endif

struct sriqground_Ground {
    slop_list_types_Clause gs;
    slop_list_u8 fresh;
    sriqindex_SubIndex ix;
    slop_list_sriqground_Post posts;
    slop_list_sriqground_Hides hides;
    slop_list_u8 shown;
    slop_list_sriq_Premise ps;
    slop_list_int pm;
    slop_list_int bysel;
};
typedef struct sriqground_Ground sriqground_Ground;

#ifndef SLOP_OPTION_SRIQGROUND_GROUND_DEFINED
#define SLOP_OPTION_SRIQGROUND_GROUND_DEFINED
SLOP_OPTION_DEFINE(sriqground_Ground, slop_option_sriqground_Ground)
#endif

struct sriqground_PIdx {
    slop_list_sriq_Premise ps;
    slop_list_int bysel;
};
typedef struct sriqground_PIdx sriqground_PIdx;

#ifndef SLOP_OPTION_SRIQGROUND_PIDX_DEFINED
#define SLOP_OPTION_SRIQGROUND_PIDX_DEFINED
SLOP_OPTION_DEFINE(sriqground_PIdx, slop_option_sriqground_PIdx)
#endif

uint8_t sriqground_lit_gf(types_Lit l);
uint8_t sriqground_ground_clause(types_Clause c);
slop_list_types_Clause sriqground_set_at(sriqctx_Structure st, int64_t v, slop_list_types_Clause nobody);
uint8_t sriqground_ctx_root(sriqctx_Structure st, int64_t v);
slop_list_types_Clause sriqground_ground_part(slop_arena* arena, slop_list_types_Clause cs);
slop_list_u8 sriqground_fresh_flags(slop_arena* arena, slop_list_types_Clause gs, slop_list_types_Clause news);
types_Clause sriqground_clause_at(slop_list_types_Clause cs, int64_t k, types_Clause fallback);
uint8_t sriqground_sorted_has(slop_list_types_Clause cs, types_Clause c);
int64_t sriqground_post_cmp(sriqground_Post a, sriqground_Post b);
sriqground_Post sriqground_post_at(slop_list_sriqground_Post ps, int64_t k, sriqground_Post fallback);
slop_list_sriqground_Post sriqground_postings(slop_arena* arena, slop_list_types_Clause gs);
int64_t sriqground_post_key_cmp(sriqground_Post p, int64_t side, types_Lit l);
int64_t sriqground_post_lower(slop_list_sriqground_Post ps, int64_t side, types_Lit l, sriqground_Post fallback);
slop_list_int sriqground_subsumed_by(slop_arena* arena, slop_list_types_Clause gs, slop_list_sriqground_Post ps, types_Clause c);
slop_list_int sriqground_subsumed_from(slop_arena* arena, slop_list_types_Clause gs, slop_list_sriqground_Post ps, types_Clause c, sriqground_Post kp, sriqground_Post p0);
slop_option_sriqground_Post sriqground_key_lit(types_Clause c);
uint8_t sriqground_member_subsumed(slop_list_types_Clause gs, int64_t i, types_Clause c);
sriqground_Hides sriqground_hides_of(slop_arena* arena, slop_list_types_Clause gs, slop_list_sriqground_Post ps, slop_list_types_Clause cs);
int64_t sriqground_int_at(slop_list_int xs, int64_t k);
slop_list_int sriqground_int_set(slop_arena* arena, slop_list_int xs);
uint8_t sriqground_int_has(slop_list_int xs, int64_t x);
slop_list_sriqground_Hides sriqground_all_hides(slop_arena* arena, sriqctx_Structure st, slop_list_types_Clause gs, slop_list_sriqground_Post ps);
slop_list_u8 sriqground_shown_flags(slop_arena* arena, sriqctx_Structure st, int64_t n, slop_list_sriqground_Hides hs);
void sriqground_bump_ids(slop_list_int counts, slop_list_int ids);
void sriqground_bump_all(slop_list_int counts, int64_t n);
sriq_Premise sriqground_prem_at(slop_list_sriq_Premise ps, int64_t k, sriq_Premise fallback);
slop_list_int sriqground_sel_sorted(slop_arena* arena, slop_list_sriq_Premise ps);
types_Clause sriqground_unit_of(slop_arena* arena, types_Lit a);
uint8_t sriqground_held_in(slop_arena* arena, sriqindex_SubIndex ix, types_Lit a);
slop_list_sriq_Premise sriqground_member_premises(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Clause gs);
slop_list_int sriqground_premise_members(slop_arena* arena, slop_list_types_Clause gs);
sriqground_Ground sriqground_ground_of(slop_arena* arena, sriqctx_Triggers tr, sriqctx_Structure st, slop_list_types_Clause root_news);
sriqground_PIdx sriqground_pidx_of(slop_arena* arena, slop_list_sriq_Premise ps);
slop_list_sriq_Premise sriqground_pidx_find(slop_arena* arena, sriqground_PIdx ix, types_Lit l);
int64_t sriqground_form_rank(types_LitForm f);
int64_t sriqground_key_cmp_lit(types_Lit l, int64_t rank, uint32_t pred);
slop_list_sriq_Premise sriqground_pidx_key_range(slop_arena* arena, sriqground_PIdx ix, int64_t rank, uint32_t pred);
int64_t sriqground_key_lower(sriqground_PIdx ix, int64_t rank, uint32_t pred, sriq_Premise p0);
sriqground_PIdx sriqground_pick_ix(int64_t j, int64_t i, sriqground_PIdx dix, sriqground_PIdx oix, sriqground_PIdx aix);
types_Lit sriqground_idx_sel(sriqground_PIdx ix, int64_t k, sriq_Premise p0);
int64_t sriqground_idx_lower(sriqground_PIdx ix, types_Lit l, sriq_Premise p0);
uint8_t sriqground_g_visible(sriqground_Ground gd, int64_t v, int64_t i);
uint8_t sriqground_g_fresh(sriqground_Ground gd, int64_t i);
uint8_t sriqground_g_in_hat(sriqground_Ground gd, types_Clause c);
uint8_t sriqground_g_held(slop_arena* arena, sriqground_Ground gd, types_Lit a);
sriq_Premise sriqground_g_premise_at(sriqground_Ground gd, int64_t k, sriq_Premise fallback);
int64_t sriqground_g_member_of(sriqground_Ground gd, int64_t k);
slop_list_int sriqground_g_sel_range(slop_arena* arena, sriqground_Ground gd, types_Lit l);
types_Lit sriqground_sel_of(sriqground_Ground gd, int64_t k, sriq_Premise p0);
int64_t sriqground_sel_lower(sriqground_Ground gd, types_Lit l, sriq_Premise p0);
slop_list_int sriqground_g_body_members(slop_arena* arena, sriqground_Ground gd, types_Lit l);
types_Clause sriqground_g_member(sriqground_Ground gd, int64_t i, types_Clause fallback);
uint8_t sriqground_g_shown(sriqground_Ground gd, int64_t i);
slop_list_types_Clause sriqground_g_root_units(slop_arena* arena, sriqctx_Triggers tr, sriqground_Ground gd);
int64_t sriqground_view_total(sriqctx_Structure st);
uint8_t sriqground_has_empty(slop_list_types_Clause cs);
sriqctx_Structure sriqground_materialise(slop_arena* arena, sriqctx_Triggers tr, sriqctx_Structure st);
slop_list_types_Clause sriqground_min_with(slop_arena* arena, slop_list_types_Clause ws, slop_list_types_Clause cs);
slop_list_types_Clause sriqground_visible_of(slop_arena* arena, sriqground_Ground gd, int64_t v);
slop_list_sriqctx_Edge sriqground_eg_edges(slop_arena* arena, sriqctx_Triggers tr, sriqground_Ground gd, int64_t v);
slop_list_u32 sriqground_consts_in(slop_arena* arena, types_Lit l);
uint8_t sriqground_edge_in(slop_list_sriqctx_Edge es, sriqctx_Edge e);

#ifndef SLOP_OPTION_SRIQGROUND_POST_DEFINED
#define SLOP_OPTION_SRIQGROUND_POST_DEFINED
SLOP_OPTION_DEFINE(sriqground_Post, slop_option_sriqground_Post)
#endif

#ifndef SLOP_OPTION_SRIQGROUND_HIDES_DEFINED
#define SLOP_OPTION_SRIQGROUND_HIDES_DEFINED
SLOP_OPTION_DEFINE(sriqground_Hides, slop_option_sriqground_Hides)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(sriq_Premise, slop_option_sriq_Premise)
#endif

#ifndef SLOP_OPTION_SRIQGROUND_GROUND_DEFINED
#define SLOP_OPTION_SRIQGROUND_GROUND_DEFINED
SLOP_OPTION_DEFINE(sriqground_Ground, slop_option_sriqground_Ground)
#endif

#ifndef SLOP_OPTION_SRIQGROUND_PIDX_DEFINED
#define SLOP_OPTION_SRIQGROUND_PIDX_DEFINED
SLOP_OPTION_DEFINE(sriqground_PIdx, slop_option_sriqground_PIdx)
#endif

#ifndef SLOP_OPTION_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Edge, slop_option_sriqctx_Edge)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

#ifndef SLOP_OPTION_SRIQCTX_CTXSET_DEFINED
#define SLOP_OPTION_SRIQCTX_CTXSET_DEFINED
SLOP_OPTION_DEFINE(sriqctx_CtxSet, slop_option_sriqctx_CtxSet)
#endif

#ifndef SLOP_LIST_TYPES_LIT_DEFINED
#define SLOP_LIST_TYPES_LIT_DEFINED
#define SLOP_LIST_TYPES_LIT_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Lit, slop_list_types_Lit)
#endif

#ifndef SLOP_LIST_SRIQCTX_CTXSET_DEFINED
#define SLOP_LIST_SRIQCTX_CTXSET_DEFINED
#define SLOP_LIST_SRIQCTX_CTXSET_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqctx_CtxSet, slop_list_sriqctx_CtxSet)
#endif


#endif
