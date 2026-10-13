#ifndef SLOP_sriqsat_H
#define SLOP_sriqsat_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_sriqclauses.h"
#include "slop_sriqsubsume.h"
#include "slop_sriqindex.h"
#include "slop_sriqctx.h"
#include "slop_canon.h"
#include "slop_sriqorder.h"
#include "slop_sriq.h"
#include "slop_sriqhyper.h"
#include "slop_sriqground.h"
#include "slop_sriqref.h"

typedef struct sriqsat_SatConfig sriqsat_SatConfig;
typedef struct sriqsat_Counts sriqsat_Counts;
typedef struct sriqsat_SatResult sriqsat_SatResult;
typedef struct sriqsat_Delta sriqsat_Delta;
typedef struct sriqsat_Supply sriqsat_Supply;
typedef struct sriqsat_Step sriqsat_Step;
typedef struct sriqsat_Here sriqsat_Here;
typedef struct sriqsat_Adj sriqsat_Adj;
typedef struct sriqsat_Bucket sriqsat_Bucket;
typedef struct sriqsat_CIdx sriqsat_CIdx;
typedef struct sriqsat_JoinSite sriqsat_JoinSite;
typedef struct sriqsat_Trig sriqsat_Trig;
typedef struct sriqsat_SuccView sriqsat_SuccView;
typedef struct sriqsat_RSrc sriqsat_RSrc;
typedef struct sriqsat_RSrcs sriqsat_RSrcs;
typedef struct sriqsat_Cut sriqsat_Cut;
typedef struct sriqsat_CRound sriqsat_CRound;
typedef struct sriqsat_Seen sriqsat_Seen;
typedef struct sriqsat_Supplied sriqsat_Supplied;
typedef struct sriqsat_Group sriqsat_Group;
typedef struct sriqsat_Acted sriqsat_Acted;
typedef struct sriqsat_Moved sriqsat_Moved;
typedef struct sriqsat_Run sriqsat_Run;

#ifndef SLOP_LIST_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_LIST_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_list_sriq_Premise, slop_list_list_sriq_Premise)
#endif

#ifndef SLOP_LIST_SRIQCTX_CTXSET_DEFINED
#define SLOP_LIST_SRIQCTX_CTXSET_DEFINED
#define SLOP_LIST_SRIQCTX_CTXSET_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqctx_CtxSet, slop_list_sriqctx_CtxSet)
#endif

#ifndef SLOP_LIST_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_SRIQCTX_EDGE_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqctx_Edge, slop_list_sriqctx_Edge)
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

#ifndef SLOP_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(sriq_Premise, slop_list_sriq_Premise)
#endif

#ifndef SLOP_OPTION_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_LIST_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(slop_list_sriq_Premise, slop_option_list_sriq_Premise)
#endif

#ifndef SLOP_LIST_SRIQREF_CAND_DEFINED
#define SLOP_LIST_SRIQREF_CAND_DEFINED
#define SLOP_LIST_SRIQREF_CAND_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqref_Cand, slop_list_sriqref_Cand)
#endif

#ifndef SLOP_LIST_SRIQREF_ROUND_DEFINED
#define SLOP_LIST_SRIQREF_ROUND_DEFINED
#define SLOP_LIST_SRIQREF_ROUND_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqref_Round, slop_list_sriqref_Round)
#endif

#ifndef SLOP_LIST_SRIQREF_SUCCACT_DEFINED
#define SLOP_LIST_SRIQREF_SUCCACT_DEFINED
#define SLOP_LIST_SRIQREF_SUCCACT_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqref_SuccAct, slop_list_sriqref_SuccAct)
#endif

#ifndef SLOP_LIST_SRIQ_PSLOT_DEFINED
#define SLOP_LIST_SRIQ_PSLOT_DEFINED
#define SLOP_LIST_SRIQ_PSLOT_IMPL_DEFINED
SLOP_LIST_DEFINE(sriq_PSlot, slop_list_sriq_PSlot)
#endif

#ifndef SLOP_LIST_SRIQREF_PJOB_DEFINED
#define SLOP_LIST_SRIQREF_PJOB_DEFINED
#define SLOP_LIST_SRIQREF_PJOB_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqref_PJob, slop_list_sriqref_PJob)
#endif

#ifndef SLOP_LIST_SRIQREF_OUT_DEFINED
#define SLOP_LIST_SRIQREF_OUT_DEFINED
#define SLOP_LIST_SRIQREF_OUT_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqref_Out, slop_list_sriqref_Out)
#endif

#ifndef SLOP_LIST_SRIQREF_RSUCCACT_DEFINED
#define SLOP_LIST_SRIQREF_RSUCCACT_DEFINED
#define SLOP_LIST_SRIQREF_RSUCCACT_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqref_RSuccAct, slop_list_sriqref_RSuccAct)
#endif

#ifndef SLOP_OPTION_SRIQCTX_CTXSET_DEFINED
#define SLOP_OPTION_SRIQCTX_CTXSET_DEFINED
SLOP_OPTION_DEFINE(sriqctx_CtxSet, slop_option_sriqctx_CtxSet)
#endif

#ifndef SLOP_OPTION_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Edge, slop_option_sriqctx_Edge)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(sriq_Premise, slop_option_sriq_Premise)
#endif

#ifndef SLOP_OPTION_SRIQREF_CAND_DEFINED
#define SLOP_OPTION_SRIQREF_CAND_DEFINED
SLOP_OPTION_DEFINE(sriqref_Cand, slop_option_sriqref_Cand)
#endif

#ifndef SLOP_OPTION_SRIQREF_ROUND_DEFINED
#define SLOP_OPTION_SRIQREF_ROUND_DEFINED
SLOP_OPTION_DEFINE(sriqref_Round, slop_option_sriqref_Round)
#endif

#ifndef SLOP_OPTION_SRIQREF_SUCCACT_DEFINED
#define SLOP_OPTION_SRIQREF_SUCCACT_DEFINED
SLOP_OPTION_DEFINE(sriqref_SuccAct, slop_option_sriqref_SuccAct)
#endif

#ifndef SLOP_OPTION_SRIQ_PSLOT_DEFINED
#define SLOP_OPTION_SRIQ_PSLOT_DEFINED
SLOP_OPTION_DEFINE(sriq_PSlot, slop_option_sriq_PSlot)
#endif

#ifndef SLOP_OPTION_SRIQREF_PJOB_DEFINED
#define SLOP_OPTION_SRIQREF_PJOB_DEFINED
SLOP_OPTION_DEFINE(sriqref_PJob, slop_option_sriqref_PJob)
#endif

#ifndef SLOP_OPTION_SRIQREF_OUT_DEFINED
#define SLOP_OPTION_SRIQREF_OUT_DEFINED
SLOP_OPTION_DEFINE(sriqref_Out, slop_option_sriqref_Out)
#endif

#ifndef SLOP_OPTION_SRIQREF_RSUCCACT_DEFINED
#define SLOP_OPTION_SRIQREF_RSUCCACT_DEFINED
SLOP_OPTION_DEFINE(sriqref_RSuccAct, slop_option_sriqref_RSuccAct)
#endif

struct sriqsat_SatConfig {
    sriqref_RefConfig base;
    int64_t perm;
    uint8_t scan;
    uint8_t defer;
};
typedef struct sriqsat_SatConfig sriqsat_SatConfig;

#ifndef SLOP_OPTION_SRIQSAT_SATCONFIG_DEFINED
#define SLOP_OPTION_SRIQSAT_SATCONFIG_DEFINED
SLOP_OPTION_DEFINE(sriqsat_SatConfig, slop_option_sriqsat_SatConfig)
#endif

struct sriqsat_Counts {
    int64_t cands;
    int64_t rcands;
    int64_t succs;
    int64_t rsuccs;
    int64_t noms;
    int64_t added;
    int64_t acts;
    int64_t hyper;
};
typedef struct sriqsat_Counts sriqsat_Counts;

#ifndef SLOP_OPTION_SRIQSAT_COUNTS_DEFINED
#define SLOP_OPTION_SRIQSAT_COUNTS_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Counts, slop_option_sriqsat_Counts)
#endif

struct sriqsat_Delta {
    slop_list_sriqctx_CtxSet news;
    slop_list_sriqctx_CtxSet olds;
    slop_list_sriqctx_Edge edges;
    int64_t nctx;
    int64_t ncst;
};
typedef struct sriqsat_Delta sriqsat_Delta;

#ifndef SLOP_OPTION_SRIQSAT_DELTA_DEFINED
#define SLOP_OPTION_SRIQSAT_DELTA_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Delta, slop_option_sriqsat_Delta)
#endif

struct sriqsat_Supply {
    uint32_t from;
    uint32_t f;
    slop_list_types_Lit lits;
};
typedef struct sriqsat_Supply sriqsat_Supply;

#ifndef SLOP_OPTION_SRIQSAT_SUPPLY_DEFINED
#define SLOP_OPTION_SRIQSAT_SUPPLY_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Supply, slop_option_sriqsat_Supply)
#endif

#ifndef SLOP_LIST_SRIQSAT_SUPPLY_DEFINED
#define SLOP_LIST_SRIQSAT_SUPPLY_DEFINED
#define SLOP_LIST_SRIQSAT_SUPPLY_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqsat_Supply, slop_list_sriqsat_Supply)
#endif

struct sriqsat_Step {
    sriqctx_Structure st;
    sriqsat_Delta dl;
    uint8_t changed;
    slop_list_sriqsat_Supply trig;
    int64_t acts;
};
typedef struct sriqsat_Step sriqsat_Step;

#ifndef SLOP_OPTION_SRIQSAT_STEP_DEFINED
#define SLOP_OPTION_SRIQSAT_STEP_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Step, slop_option_sriqsat_Step)
#endif

struct sriqsat_Adj {
    slop_list_sriqctx_Edge ins;
    slop_list_sriqctx_Edge outs;
};
typedef struct sriqsat_Adj sriqsat_Adj;

#ifndef SLOP_OPTION_SRIQSAT_ADJ_DEFINED
#define SLOP_OPTION_SRIQSAT_ADJ_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Adj, slop_option_sriqsat_Adj)
#endif

#ifndef SLOP_LIST_SRIQSAT_ADJ_DEFINED
#define SLOP_LIST_SRIQSAT_ADJ_DEFINED
#define SLOP_LIST_SRIQSAT_ADJ_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqsat_Adj, slop_list_sriqsat_Adj)
#endif

struct sriqsat_Bucket {
    slop_list_sriqctx_Edge es;
};
typedef struct sriqsat_Bucket sriqsat_Bucket;

#ifndef SLOP_OPTION_SRIQSAT_BUCKET_DEFINED
#define SLOP_OPTION_SRIQSAT_BUCKET_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Bucket, slop_option_sriqsat_Bucket)
#endif

#ifndef SLOP_LIST_SRIQSAT_BUCKET_DEFINED
#define SLOP_LIST_SRIQSAT_BUCKET_DEFINED
#define SLOP_LIST_SRIQSAT_BUCKET_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqsat_Bucket, slop_list_sriqsat_Bucket)
#endif

struct sriqsat_CIdx {
    slop_list_sriq_Premise aps;
    slop_list_sriq_Premise dps;
    slop_list_sriq_Premise ops;
    sriqground_PIdx aix;
    sriqground_PIdx dix;
    sriqground_PIdx oix;
};
typedef struct sriqsat_CIdx sriqsat_CIdx;

#ifndef SLOP_OPTION_SRIQSAT_CIDX_DEFINED
#define SLOP_OPTION_SRIQSAT_CIDX_DEFINED
SLOP_OPTION_DEFINE(sriqsat_CIdx, slop_option_sriqsat_CIdx)
#endif

#ifndef SLOP_LIST_SRIQSAT_CIDX_DEFINED
#define SLOP_LIST_SRIQSAT_CIDX_DEFINED
#define SLOP_LIST_SRIQSAT_CIDX_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqsat_CIdx, slop_list_sriqsat_CIdx)
#endif

struct sriqsat_JoinSite {
    types_Clause c;
    int64_t j;
};
typedef struct sriqsat_JoinSite sriqsat_JoinSite;

#ifndef SLOP_OPTION_SRIQSAT_JOINSITE_DEFINED
#define SLOP_OPTION_SRIQSAT_JOINSITE_DEFINED
SLOP_OPTION_DEFINE(sriqsat_JoinSite, slop_option_sriqsat_JoinSite)
#endif

#ifndef SLOP_LIST_SRIQSAT_JOINSITE_DEFINED
#define SLOP_LIST_SRIQSAT_JOINSITE_DEFINED
#define SLOP_LIST_SRIQSAT_JOINSITE_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqsat_JoinSite, slop_list_sriqsat_JoinSite)
#endif

struct sriqsat_Trig {
    sriq_Premise p;
    sriq_SuccSig sg;
};
typedef struct sriqsat_Trig sriqsat_Trig;

#ifndef SLOP_OPTION_SRIQSAT_TRIG_DEFINED
#define SLOP_OPTION_SRIQSAT_TRIG_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Trig, slop_option_sriqsat_Trig)
#endif

#ifndef SLOP_LIST_SRIQSAT_TRIG_DEFINED
#define SLOP_LIST_SRIQSAT_TRIG_DEFINED
#define SLOP_LIST_SRIQSAT_TRIG_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqsat_Trig, slop_list_sriqsat_Trig)
#endif

struct sriqsat_SuccView {
    sriq_KSets ks;
    uint8_t covered;
};
typedef struct sriqsat_SuccView sriqsat_SuccView;

#ifndef SLOP_OPTION_SRIQSAT_SUCCVIEW_DEFINED
#define SLOP_OPTION_SRIQSAT_SUCCVIEW_DEFINED
SLOP_OPTION_DEFINE(sriqsat_SuccView, slop_option_sriqsat_SuccView)
#endif

struct sriqsat_RSrc {
    types_Clause c;
    sriq_PredView view;
};
typedef struct sriqsat_RSrc sriqsat_RSrc;

#ifndef SLOP_OPTION_SRIQSAT_RSRC_DEFINED
#define SLOP_OPTION_SRIQSAT_RSRC_DEFINED
SLOP_OPTION_DEFINE(sriqsat_RSrc, slop_option_sriqsat_RSrc)
#endif

#ifndef SLOP_LIST_SRIQSAT_RSRC_DEFINED
#define SLOP_LIST_SRIQSAT_RSRC_DEFINED
#define SLOP_LIST_SRIQSAT_RSRC_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqsat_RSrc, slop_list_sriqsat_RSrc)
#endif

struct sriqsat_RSrcs {
    slop_list_sriqsat_RSrc all;
    slop_list_sriqsat_RSrc news;
    slop_list_sriqsat_RSrc olds;
};
typedef struct sriqsat_RSrcs sriqsat_RSrcs;

#ifndef SLOP_OPTION_SRIQSAT_RSRCS_DEFINED
#define SLOP_OPTION_SRIQSAT_RSRCS_DEFINED
SLOP_OPTION_DEFINE(sriqsat_RSrcs, slop_option_sriqsat_RSrcs)
#endif

struct sriqsat_Cut {
    slop_list_sriqctx_Edge es;
    int64_t k;
};
typedef struct sriqsat_Cut sriqsat_Cut;

#ifndef SLOP_OPTION_SRIQSAT_CUT_DEFINED
#define SLOP_OPTION_SRIQSAT_CUT_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Cut, slop_option_sriqsat_Cut)
#endif

struct sriqsat_CRound {
    sriqref_Round r;
    int64_t tried;
};
typedef struct sriqsat_CRound sriqsat_CRound;

#ifndef SLOP_OPTION_SRIQSAT_CROUND_DEFINED
#define SLOP_OPTION_SRIQSAT_CROUND_DEFINED
SLOP_OPTION_DEFINE(sriqsat_CRound, slop_option_sriqsat_CRound)
#endif

struct sriqsat_Seen {
    sriqctx_Structure st;
    sriqsat_Delta dl;
};
typedef struct sriqsat_Seen sriqsat_Seen;

#ifndef SLOP_OPTION_SRIQSAT_SEEN_DEFINED
#define SLOP_OPTION_SRIQSAT_SEEN_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Seen, slop_option_sriqsat_Seen)
#endif

struct sriqsat_Supplied {
    slop_list_sriqsat_Supply trig;
    slop_list_sriqsat_Supply evals;
    uint8_t grew;
};
typedef struct sriqsat_Supplied sriqsat_Supplied;

#ifndef SLOP_OPTION_SRIQSAT_SUPPLIED_DEFINED
#define SLOP_OPTION_SRIQSAT_SUPPLIED_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Supplied, slop_option_sriqsat_Supplied)
#endif

struct sriqsat_Group {
    sriqsat_Supply s;
    uint8_t evald;
    uint8_t grew;
    int64_t next;
};
typedef struct sriqsat_Group sriqsat_Group;

#ifndef SLOP_OPTION_SRIQSAT_GROUP_DEFINED
#define SLOP_OPTION_SRIQSAT_GROUP_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Group, slop_option_sriqsat_Group)
#endif

struct sriqsat_Acted {
    sriqsat_Delta dl;
    int64_t n;
};
typedef struct sriqsat_Acted sriqsat_Acted;

#ifndef SLOP_OPTION_SRIQSAT_ACTED_DEFINED
#define SLOP_OPTION_SRIQSAT_ACTED_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Acted, slop_option_sriqsat_Acted)
#endif

struct sriqsat_Moved {
    slop_list_types_Clause news;
    slop_list_types_Clause olds;
    int64_t n;
};
typedef struct sriqsat_Moved sriqsat_Moved;

#ifndef SLOP_OPTION_SRIQSAT_MOVED_DEFINED
#define SLOP_OPTION_SRIQSAT_MOVED_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Moved, slop_option_sriqsat_Moved)
#endif

struct sriqsat_Run {
    sriqctx_Structure st;
    sriqsat_Delta dl;
    sriqref_RefStatus status;
    int64_t rounds;
    uint8_t going;
    slop_list_sriqsat_Supply trig;
    sriqsat_Counts counts;
};
typedef struct sriqsat_Run sriqsat_Run;

#ifndef SLOP_OPTION_SRIQSAT_RUN_DEFINED
#define SLOP_OPTION_SRIQSAT_RUN_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Run, slop_option_sriqsat_Run)
#endif

struct sriqsat_SatResult {
    sriqref_RefResult res;
    sriqsat_Counts counts;
    slop_list_sriqsat_Supply trig;
};
typedef struct sriqsat_SatResult sriqsat_SatResult;

#ifndef SLOP_OPTION_SRIQSAT_SATRESULT_DEFINED
#define SLOP_OPTION_SRIQSAT_SATRESULT_DEFINED
SLOP_OPTION_DEFINE(sriqsat_SatResult, slop_option_sriqsat_SatResult)
#endif

struct sriqsat_Here {
    uint32_t v;
    uint8_t root;
    uint8_t fresh;
    slop_list_types_Clause all;
    slop_list_types_Clause news;
    slop_list_types_Clause olds;
    slop_list_sriq_Premise aps;
    slop_list_sriq_Premise dps;
    slop_list_sriq_Premise ops;
    sriqground_PIdx dix;
    sriqground_PIdx aix;
    sriqground_PIdx oix;
    sriqhyper_HIdx hx;
    slop_list_sriqsat_CIdx ixs;
    sriqground_Ground gd;
    sriqsat_RSrcs rs;
    uint8_t dfr;
};
typedef struct sriqsat_Here sriqsat_Here;

#ifndef SLOP_OPTION_SRIQSAT_HERE_DEFINED
#define SLOP_OPTION_SRIQSAT_HERE_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Here, slop_option_sriqsat_Here)
#endif

slop_list_types_Clause sriqsat_cs_at(slop_list_sriqctx_CtxSet xs, int64_t v, slop_list_types_Clause nobody);
slop_list_types_Clause sriqsat_permuted(slop_arena* arena, slop_list_types_Clause xs, int64_t perm);
slop_list_int sriqsat_ctx_order(slop_arena* arena, int64_t n, int64_t perm);
sriqsat_CIdx sriqsat_ctx_ix(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, int64_t v, int64_t perm);
slop_list_sriqsat_CIdx sriqsat_all_ixs(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, int64_t perm);
sriqsat_CIdx sriqsat_cix_at(slop_arena* arena, slop_list_sriqsat_CIdx ixs, int64_t v);
sriqsat_Here sriqsat_here_of(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqground_Ground gd, sriqhyper_HIdx hx, slop_list_sriqsat_CIdx ixs, sriqsat_RSrcs rs, int64_t v, int64_t perm, uint8_t dfr);
uint8_t sriqsat_edge_new(sriqsat_Delta dl, sriqctx_Edge e);
uint8_t sriqsat_consts_new(sriqctx_Structure st, sriqsat_Delta dl);
slop_list_sriqref_Cand sriqsat_hyper_new_consts(slop_arena* arena, sriqctx_Structure st, sriqsat_Delta dl, uint32_t v, types_Clause oc);
slop_list_sriqref_Cand sriqsat_hyper_bodiless(slop_arena* arena, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, types_Clause oc);
uint8_t sriqsat_dl10(types_Clause oc);
sriqhyper_HCtx sriqsat_hctx_of(sriqsat_Here h);
sriqhyper_HOut sriqsat_sat_hyper(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h);
slop_list_sriqref_Cand sriqsat_eq_pairs(slop_arena* arena, sriqctx_Structure st, sriqsat_Here h, slop_list_sriq_Premise p1s, slop_list_sriq_Premise p2s);
slop_list_sriqref_Cand sriqsat_eq_side(slop_arena* arena, sriqctx_Structure st, sriqsat_Here h, sriq_Premise p1, uint32_t k1, sriq_Premise p2);
uint8_t sriqsat_holds_term(types_Lit l, types_ATerm s);
uint8_t sriqsat_term_at(types_Lit l, uint32_t a, uint8_t inner, types_ATerm s);
sriqhyper_HOut sriqsat_sat_table2(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h);
uint8_t sriqsat_g_counts(sriqsat_Here h, int64_t i, int64_t which);
uint8_t sriqsat_g_picks(sriqsat_Here h, int64_t k, int64_t which);
slop_list_sriq_Premise sriqsat_g_prems(slop_arena* arena, sriqsat_Here h, int64_t which, uint8_t eqs);
slop_list_sriqref_Cand sriqsat_join_into_g(slop_arena* arena, sriqsat_Here h, slop_list_sriq_Premise p1s, int64_t which);
slop_list_sriqref_Cand sriqsat_join_into_member(slop_arena* arena, sriqsat_Here h, sriq_Premise p1, types_Clause g);
types_Clause sriqsat_empty_clause(slop_arena* arena);
uint8_t sriqsat_has_eq(slop_list_sriq_Premise ps);
slop_list_sriqref_Cand sriqsat_eq_ground(slop_arena* arena, sriqctx_Structure st, sriqsat_Here h);
slop_list_sriqref_Cand sriqsat_join_ground(slop_arena* arena, sriqsat_Here h);
slop_list_sriqref_Cand sriqsat_join_from_g(slop_arena* arena, sriqsat_Here h, slop_list_sriqsat_JoinSite sites, int64_t which);
slop_list_sriqref_Cand sriqsat_join_site_g(slop_arena* arena, sriqsat_Here h, sriqsat_JoinSite s, types_Lit l, int64_t which);
slop_list_sriqref_Cand sriqsat_join_g_one(slop_arena* arena, sriqsat_Here h, sriqsat_JoinSite s, sriq_Premise p1);
sriq_Premise sriqsat_fallback_premise(slop_arena* arena);
slop_list_sriqsat_JoinSite sriqsat_join_sites(slop_arena* arena, slop_list_types_Clause cs);
slop_list_sriqsat_JoinSite sriqsat_sites_sorted(slop_arena* arena, slop_list_sriqsat_JoinSite raw, sriqsat_JoinSite s0);
sriqsat_JoinSite sriqsat_site_at(slop_list_sriqsat_JoinSite ss, int64_t k, sriqsat_JoinSite fallback);
types_Lit sriqsat_site_key(sriqsat_JoinSite s);
int64_t sriqsat_site_lower(slop_list_sriqsat_JoinSite ss, types_Lit l, sriqsat_JoinSite fallback);
slop_option_types_Lit sriqsat_site_lit(sriqsat_JoinSite s);
slop_list_sriqref_Cand sriqsat_sat_join(slop_arena* arena, uint32_t v, slop_list_sriq_Premise p1s, slop_list_sriqsat_JoinSite sites);
slop_list_sriqref_Cand sriqsat_join_one(slop_arena* arena, uint32_t v, sriq_Premise p1, slop_list_sriqsat_JoinSite sites);
slop_list_sriqref_Cand sriqsat_join_from(slop_arena* arena, uint32_t v, sriq_Premise p1, slop_list_sriqsat_JoinSite sites, int64_t k0, sriqsat_JoinSite s0);
uint8_t sriqsat_site_holds(sriqsat_JoinSite s, types_Lit l);
sriqref_Round sriqsat_nom_pairs(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriqref_Dl4 d, slop_list_sriq_Premise p1s, slop_list_sriq_Premise p2s);
sriqref_Round sriqsat_sat_nom(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h);
slop_list_sriqref_Round sriqsat_nom_ground(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriqref_Dl4 d, uint8_t all);
sriqref_Round sriqsat_nom_own(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, uint8_t all);
slop_list_sriqref_Round sriqsat_one_round(slop_arena* arena, sriqref_Round a);
sriqref_Round sriqsat_nom_from_g(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriqref_Dl4 d, slop_list_sriq_Premise p2s, int64_t which);
sriqref_Round sriqsat_nom_g_one(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriqref_Dl4 d, sriq_Premise p2, uint32_t o, int64_t which);
slop_list_sriqref_Round sriqsat_two_rounds(slop_arena* arena, sriqref_Round a, sriqref_Round b);
uint8_t sriqsat_k2_touched(slop_arena* arena, sriqref_Env env, sriqsat_Here h, sriqindex_KIdx kn, sriq_Premise p);
slop_list_sriq_Premise sriqsat_succ_premises(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h);
slop_list_sriqref_SuccAct sriqsat_sat_succ(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, slop_list_sriq_Premise ps);
slop_list_sriqref_SuccAct sriqsat_succ_trigs(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriqindex_KIdx bare, slop_list_types_Lit base, slop_list_sriqsat_Trig ts, sriqsat_Trig t0);
sriqref_SuccAct sriqsat_succ_eval(slop_arena* arena, sriqref_Env env, sriqsat_Here h, sriqsat_SuccView sv, sriq_SuccSig sg);
slop_list_sriqsat_Trig sriqsat_triggers_of(slop_arena* arena, sriqsat_Here h, slop_list_sriq_Premise ps);
slop_list_sriqsat_Trig sriqsat_trigs_sorted(slop_arena* arena, slop_list_sriqsat_Trig raw, sriqsat_Trig t0);
sriqsat_Trig sriqsat_trig_at(slop_list_sriqsat_Trig ts, int64_t k, sriqsat_Trig fallback);
int64_t sriqsat_sg_cmp(sriq_SuccSig a, sriq_SuccSig b);
sriqsat_SuccView sriqsat_succ_view(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriqindex_KIdx bare, slop_list_types_Lit base, sriq_SuccSig sg);
slop_list_sriqref_SuccAct sriqsat_succ_on(slop_arena* arena, sriqref_Env env, sriqsat_Here h, sriqsat_SuccView sv, sriqsat_Trig t);
slop_list_types_Lit sriqsat_merged_lits(slop_arena* arena, slop_list_types_Lit a, slop_list_types_Lit b);
slop_list_types_Lit sriqsat_unheld(slop_arena* arena, sriqground_Ground gd, slop_list_types_Lit k2);
uint8_t sriqsat_covered_view(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, uint32_t f, slop_list_types_Lit k2);
sriqref_Out sriqsat_pred_anchored(slop_arena* arena, sriqref_Env env, sriqref_PJob job, sriqground_PIdx dix, sriqground_PIdx oix, sriqground_PIdx aix);
slop_list_sriq_Premise sriqsat_slot_ix(slop_arena* arena, sriq_CSub s, sriq_PSlot slot, sriqground_PIdx ix);
sriqref_Out sriqsat_pred_anchor(slop_arena* arena, sriqref_Env env, sriqref_PJob job, sriqground_PIdx dix, sriqground_PIdx oix, sriqground_PIdx aix, int64_t i);
sriqref_Out sriqsat_pred_run_ix(slop_arena* arena, sriqref_Env env, sriqref_PJob job, sriqground_PIdx aix);
sriqref_Out sriqsat_pred_choices(slop_arena* arena, sriqref_Env env, sriqref_PJob job, slop_list_list_sriq_Premise cs, slop_list_sriq_Premise ps);
sriqground_PIdx sriqsat_w_ix(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, int64_t w, slop_list_types_Clause cs, int64_t which);
sriqref_Out sriqsat_pred_side(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, sriqctx_Edge e);
sriqref_Out sriqsat_pred_edge_ix(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriqctx_Edge e, slop_list_types_Clause cs);
slop_list_sriqref_PJob sriqsat_side_jobs(slop_arena* arena, sriqctx_Structure st, sriq_PredView view, slop_list_sriq_PSlot slots, sriqctx_Edge e, uint8_t toroot);
sriqref_Out sriqsat_sat_pred(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, slop_list_sriqctx_Edge ins);
slop_list_sriqref_Out sriqsat_pred_over(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, sriqctx_Edge e);
uint8_t sriqsat_rpred_edge_new(sriqsat_Delta dl, uint32_t v);
sriqref_Out sriqsat_sat_rpred(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h);
sriqref_Out sriqsat_rpred_from(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, slop_list_sriqsat_RSrc rs, slop_list_sriq_Premise aps, uint8_t anchored);
uint8_t sriqsat_rpred_able(sriqctx_Triggers tr, sriq_PredView v);
slop_list_sriqsat_RSrc sriqsat_rsrcs_in(slop_arena* arena, sriqctx_Triggers tr, slop_list_types_Clause cs);
sriqsat_RSrcs sriqsat_rsrcs_of(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl);
sriqref_PJob sriqsat_rsrc_job(slop_arena* arena, sriqctx_Structure st, uint32_t v, sriqsat_RSrc r);
sriqctx_Structure sriqsat_local(sriqctx_Structure st, sriqsat_Adj a, slop_arena* arena);
sriqsat_CRound sriqsat_sat_ctx(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, slop_list_sriqsat_CIdx ixs, sriqsat_RSrcs rs, sriqctx_Structure st, sriqsat_Delta dl, sriqground_Ground gd, sriqsat_Adj a, int64_t v, int64_t perm, uint8_t dfr);
sriqsat_CRound sriqsat_sat_old(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, slop_list_sriqctx_Edge ins, sriqsat_Here h);
sriqctx_Edge sriqsat_edge_at(slop_list_sriqctx_Edge es, int64_t k, sriqctx_Edge fallback);
slop_list_sriqsat_Adj sriqsat_adjacency(slop_arena* arena, sriqctx_Structure st);
slop_list_sriqctx_Edge sriqsat_edges_at(slop_arena* arena, slop_list_sriqsat_Bucket bs, int64_t v);
int64_t sriqsat_u32_cmp(uint32_t a, uint32_t b);
sriqsat_Cut sriqsat_cut_at(slop_arena* arena, slop_list_sriqctx_Edge es, slop_list_int idx, int64_t k, int64_t v, uint8_t by_to, sriqctx_Edge e0);
slop_list_sriqsat_Bucket sriqsat_buckets(slop_arena* arena, slop_list_sriqctx_Edge es, slop_list_int idx, int64_t n, uint8_t by_to, sriqctx_Edge e0);
int64_t sriqsat_idx_at(slop_list_int idx, int64_t k);
sriqsat_CRound sriqsat_sat_round(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, sriqctx_Structure st, sriqsat_Delta dl, sriqground_Ground gd, int64_t perm, uint8_t dfr);
slop_list_sriqref_Cand sriqsat_new_cores(slop_arena* arena, sriqctx_Structure st, int64_t from);
sriqsat_Step sriqsat_sat_apply(slop_arena* arena, sriqctx_Structure st, sriqground_Ground gd, sriqref_Round r, uint8_t scan, uint8_t dfr, slop_list_sriqsat_Supply trig);
slop_list_sriqref_Cand sriqsat_succ_cands(slop_arena* arena, sriqctx_Structure st, sriqref_Round r, sriqsat_Supplied sup, uint8_t dfr);
sriqctx_Structure sriqsat_edges_added(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_SuccAct succs, slop_list_sriqref_RSuccAct rsuccs);
slop_list_sriqctx_Edge sriqsat_action_edges(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_SuccAct succs, slop_list_sriqref_RSuccAct rsuccs);
slop_list_sriqctx_Edge sriqsat_first_new(slop_arena* arena, slop_list_sriqctx_Edge old, slop_list_sriqctx_Edge news);
slop_list_int sriqsat_kept_positions(slop_arena* arena, slop_list_sriqctx_Edge old, slop_list_sriqctx_Edge news, sriqctx_Edge e0);
uint8_t sriqsat_run_first_new(slop_list_sriqctx_Edge old, slop_list_int oidx, slop_list_sriqctx_Edge news, int64_t prev, int64_t k, sriqctx_Edge e0);
slop_list_sriqctx_Edge sriqsat_in_news_order(slop_arena* arena, slop_list_sriqctx_Edge news, slop_list_int keep, sriqctx_Edge e0);
uint8_t sriqsat_edge_in(slop_list_sriqctx_Edge es, slop_list_int idx, sriqctx_Edge e, sriqctx_Edge e0);
int64_t sriqsat_edge_cmp(sriqctx_Edge a, sriqctx_Edge b);
int64_t sriqsat_lk_rank(sriqctx_EdgeLabel lk);
int64_t sriqsat_int_cmp(int64_t a, int64_t b);
slop_list_sriqref_Cand sriqsat_outside_view(slop_arena* arena, sriqctx_Structure st, sriqground_Ground gd, slop_list_sriqref_Cand cands);
sriqsat_Step sriqsat_commit_all(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_Cand cands, int64_t c0, int64_t e0, int64_t n0, uint8_t scan);
slop_list_types_Clause sriqsat_run_of(slop_arena* arena, slop_list_sriqref_Cand cands, slop_list_int idx, int64_t k, uint32_t v, sriqref_Cand none_such);
sriqsubsume_Committed sriqsat_commit_one(slop_arena* arena, slop_list_types_Clause ws, slop_list_types_Clause cs, uint8_t scan);
slop_list_types_Clause sriqsat_minus_sorted(slop_arena* arena, slop_list_types_Clause xs, slop_list_types_Clause ys);
slop_list_sriqctx_Edge sriqsat_edges_from(slop_arena* arena, slop_list_sriqctx_Edge es, int64_t k);
uint8_t sriqsat_defer_on(sriqsat_SatConfig cfg, sriqref_RefIn in);
int64_t sriqsat_key_cmp(uint32_t w1, uint32_t f1, uint32_t w2, uint32_t f2);
int64_t sriqsat_supply_cmp(sriqsat_Supply a, sriqsat_Supply b);
sriqsat_Supply sriqsat_supply_at(slop_list_sriqsat_Supply xs, int64_t k, sriqsat_Supply fallback);
slop_list_types_Lit sriqsat_supply_of(slop_list_sriqsat_Supply trig, uint32_t w, uint32_t f, slop_list_types_Lit nolits);
uint8_t sriqsat_lit_member(slop_list_types_Lit ls, types_Lit l);
uint8_t sriqsat_body_within(types_Clause c, slop_list_types_Lit core, slop_list_types_Lit lits);
uint8_t sriqsat_supported(types_Clause c, slop_list_types_Lit core, slop_list_sriqctx_Edge ins, slop_list_sriqsat_Supply trig, slop_list_types_Lit nolits);
slop_list_sriqctx_Edge sriqsat_ins_at(slop_arena* arena, slop_list_sriqsat_Adj adj, int64_t v);
sriqsat_Seen sriqsat_projected(slop_arena* arena, sriqctx_Structure st, sriqsat_Delta dl, slop_list_sriqsat_Supply trig);
sriqctx_CtxSet sriqsat_narrowed(slop_arena* arena, slop_list_types_Clause cs, sriqctx_Ctx c, slop_list_sriqctx_Edge ins, slop_list_sriqsat_Supply trig, slop_list_types_Lit nolits);
sriqsat_Supplied sriqsat_supplied(slop_arena* arena, slop_list_sriqsat_Supply trig, slop_list_sriqref_SuccAct succs);
sriqsat_Supplied sriqsat_supplies_merged(slop_arena* arena, slop_list_sriqsat_Supply raw, int64_t nold, sriqsat_Supply s0);
sriqsat_Group sriqsat_supply_group(slop_arena* arena, slop_list_sriqsat_Supply raw, slop_list_int idx, int64_t k, int64_t nold, sriqsat_Supply s0);
slop_list_types_Lit sriqsat_ctx_core(slop_arena* arena, sriqctx_Structure st, uint32_t v);
slop_list_sriqref_Cand sriqsat_pushed(slop_arena* arena, sriqctx_Structure st, slop_list_sriqsat_Supply evals);
slop_list_sriqctx_Edge sriqsat_edges_before(slop_arena* arena, slop_list_sriqctx_Edge es, int64_t k);
sriqsat_Step sriqsat_deferred_step(slop_arena* arena, sriqsat_Step sp, int64_t e0, slop_list_sriqsat_Supply old, sriqsat_Supplied sup);
sriqsat_Acted sriqsat_activated(slop_arena* arena, sriqctx_Structure st, sriqsat_Delta dl, int64_t e0, slop_list_sriqsat_Supply old, slop_list_sriqsat_Supply trig);
sriqsat_Moved sriqsat_acted_in(slop_arena* arena, sriqctx_Ctx c, slop_list_types_Clause news, slop_list_types_Clause olds, slop_list_sriqctx_Edge ins, slop_list_sriqctx_Edge ins0, slop_list_sriqsat_Supply old, slop_list_sriqsat_Supply trig, slop_list_types_Lit nolits);
uint8_t sriqsat_ins_grew(slop_list_sriqctx_Edge ins, slop_list_sriqctx_Edge ins0, slop_list_sriqsat_Supply old, slop_list_sriqsat_Supply trig, slop_list_types_Lit nolits);
slop_list_types_Clause sriqsat_merged_sorted(slop_arena* arena, slop_list_types_Clause xs, slop_list_types_Clause ys);
uint8_t sriqsat_y_first(slop_list_types_Clause xs, slop_list_types_Clause ys, int64_t i, int64_t j);
slop_list_sriqsat_Supply sriqsat_copy_trig(slop_arena* arena, slop_list_sriqsat_Supply trig);
sriqsat_Delta sriqsat_first_delta(slop_arena* arena, sriqctx_Structure st);
sriqsat_Delta sriqsat_copy_delta(slop_arena* arena, sriqsat_Delta dl);
int64_t sriqsat_into_v(slop_list_sriqref_Cand cs, uint32_t v);
int64_t sriqsat_sum_added(sriqsat_Delta dl);
sriqsat_Counts sriqsat_tally(sriqsat_Counts c, sriqref_Round r, sriqsat_Delta dl, int64_t tried, int64_t acts);
sriqsat_Step sriqsat_with_units(slop_arena* arena, sriqctx_Triggers tr, sriqsat_Step sp);
sriqctx_Structure sriqsat_with_root_set(slop_arena* arena, sriqctx_Structure st, slop_list_types_Clause cs);
sriqsat_Delta sriqsat_with_root_news(slop_arena* arena, sriqsat_Delta dl, slop_list_types_Clause set, slop_list_types_Clause added, slop_list_types_Clause nobody);
slop_list_sriqctx_CtxSet sriqsat_with_first(slop_arena* arena, slop_list_sriqctx_CtxSet xs, slop_list_types_Clause cs);
uint8_t sriqsat_sorted_in(slop_list_types_Clause cs, types_Clause c);
sriqref_RefStatus sriqsat_sat_stop(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint8_t changed, sriqref_RefConfig cfg);
uint8_t sriqsat_holds_bot(slop_arena* arena, sriqctx_Structure st, int64_t v);
sriqsat_Run sriqsat_sat_once(slop_arena* next, slop_arena* scratch, sriqref_Env env, sriqhyper_HIdx hx, sriqsat_SatConfig cfg, uint8_t dfr, sriqsat_Run run);
sriqctx_Structure sriqsat_read_view(slop_arena* arena, sriqctx_Structure st);
sriqctx_Structure sriqsat_sat_materialise(slop_arena* arena, sriqref_RefIn in, sriqctx_Structure st);
uint8_t sriqsat_defer_stable(slop_arena* arena, sriqref_RefIn in, sriqsat_SatConfig cfg, sriqsat_SatResult p);
uint8_t sriqsat_units_pushed(slop_arena* arena, sriqctx_Structure st, slop_list_sriqsat_Supply trig);
uint8_t sriqsat_hyper_ix_agrees(slop_arena* arena, sriqref_RefIn in, sriqsat_SatConfig cfg, sriqctx_Structure st);
uint8_t sriqsat_hyper_ix_one(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, sriqsat_Here h);
uint8_t sriqsat_same_cands(slop_arena* arena, slop_list_sriqref_Cand a, slop_list_sriqref_Cand b);
slop_list_types_Clause sriqsat_distinct_clauses(slop_arena* arena, slop_list_sriqref_Cand cs);
slop_list_types_Clause sriqsat_sorted_distinct(slop_arena* arena, slop_list_types_Clause raw, types_Clause c0);
types_Clause sriqsat_clause_of_l(slop_list_types_Clause cs, int64_t k, types_Clause fallback);
sriqctx_Structure sriqsat_ranked_structure(sriqctx_Structure st, int64_t nquery);
sriqsat_SatResult sriqsat_sat_run(slop_arena* arena, sriqref_RefIn in, sriqsat_SatConfig cfg);

#ifndef SLOP_OPTION_SRIQSAT_SATCONFIG_DEFINED
#define SLOP_OPTION_SRIQSAT_SATCONFIG_DEFINED
SLOP_OPTION_DEFINE(sriqsat_SatConfig, slop_option_sriqsat_SatConfig)
#endif

#ifndef SLOP_OPTION_SRIQSAT_COUNTS_DEFINED
#define SLOP_OPTION_SRIQSAT_COUNTS_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Counts, slop_option_sriqsat_Counts)
#endif

#ifndef SLOP_OPTION_SRIQSAT_SUPPLY_DEFINED
#define SLOP_OPTION_SRIQSAT_SUPPLY_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Supply, slop_option_sriqsat_Supply)
#endif

#ifndef SLOP_OPTION_SRIQSAT_SATRESULT_DEFINED
#define SLOP_OPTION_SRIQSAT_SATRESULT_DEFINED
SLOP_OPTION_DEFINE(sriqsat_SatResult, slop_option_sriqsat_SatResult)
#endif

#ifndef SLOP_OPTION_SRIQCTX_CTXSET_DEFINED
#define SLOP_OPTION_SRIQCTX_CTXSET_DEFINED
SLOP_OPTION_DEFINE(sriqctx_CtxSet, slop_option_sriqctx_CtxSet)
#endif

#ifndef SLOP_OPTION_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Edge, slop_option_sriqctx_Edge)
#endif

#ifndef SLOP_OPTION_SRIQSAT_DELTA_DEFINED
#define SLOP_OPTION_SRIQSAT_DELTA_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Delta, slop_option_sriqsat_Delta)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

#ifndef SLOP_OPTION_SRIQSAT_STEP_DEFINED
#define SLOP_OPTION_SRIQSAT_STEP_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Step, slop_option_sriqsat_Step)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(sriq_Premise, slop_option_sriq_Premise)
#endif

#ifndef SLOP_OPTION_SRIQSAT_CIDX_DEFINED
#define SLOP_OPTION_SRIQSAT_CIDX_DEFINED
SLOP_OPTION_DEFINE(sriqsat_CIdx, slop_option_sriqsat_CIdx)
#endif

#ifndef SLOP_OPTION_SRIQSAT_HERE_DEFINED
#define SLOP_OPTION_SRIQSAT_HERE_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Here, slop_option_sriqsat_Here)
#endif

#ifndef SLOP_OPTION_SRIQSAT_ADJ_DEFINED
#define SLOP_OPTION_SRIQSAT_ADJ_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Adj, slop_option_sriqsat_Adj)
#endif

#ifndef SLOP_OPTION_SRIQSAT_BUCKET_DEFINED
#define SLOP_OPTION_SRIQSAT_BUCKET_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Bucket, slop_option_sriqsat_Bucket)
#endif

#ifndef SLOP_OPTION_SRIQREF_CAND_DEFINED
#define SLOP_OPTION_SRIQREF_CAND_DEFINED
SLOP_OPTION_DEFINE(sriqref_Cand, slop_option_sriqref_Cand)
#endif

#ifndef SLOP_OPTION_SRIQSAT_JOINSITE_DEFINED
#define SLOP_OPTION_SRIQSAT_JOINSITE_DEFINED
SLOP_OPTION_DEFINE(sriqsat_JoinSite, slop_option_sriqsat_JoinSite)
#endif

#ifndef SLOP_OPTION_SRIQREF_ROUND_DEFINED
#define SLOP_OPTION_SRIQREF_ROUND_DEFINED
SLOP_OPTION_DEFINE(sriqref_Round, slop_option_sriqref_Round)
#endif

#ifndef SLOP_OPTION_SRIQSAT_TRIG_DEFINED
#define SLOP_OPTION_SRIQSAT_TRIG_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Trig, slop_option_sriqsat_Trig)
#endif

#ifndef SLOP_OPTION_SRIQSAT_SUCCVIEW_DEFINED
#define SLOP_OPTION_SRIQSAT_SUCCVIEW_DEFINED
SLOP_OPTION_DEFINE(sriqsat_SuccView, slop_option_sriqsat_SuccView)
#endif

#ifndef SLOP_OPTION_SRIQREF_SUCCACT_DEFINED
#define SLOP_OPTION_SRIQREF_SUCCACT_DEFINED
SLOP_OPTION_DEFINE(sriqref_SuccAct, slop_option_sriqref_SuccAct)
#endif

#ifndef SLOP_OPTION_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_LIST_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(slop_list_sriq_Premise, slop_option_list_sriq_Premise)
#endif

#ifndef SLOP_OPTION_SRIQ_PSLOT_DEFINED
#define SLOP_OPTION_SRIQ_PSLOT_DEFINED
SLOP_OPTION_DEFINE(sriq_PSlot, slop_option_sriq_PSlot)
#endif

#ifndef SLOP_OPTION_SRIQREF_PJOB_DEFINED
#define SLOP_OPTION_SRIQREF_PJOB_DEFINED
SLOP_OPTION_DEFINE(sriqref_PJob, slop_option_sriqref_PJob)
#endif

#ifndef SLOP_OPTION_SRIQREF_OUT_DEFINED
#define SLOP_OPTION_SRIQREF_OUT_DEFINED
SLOP_OPTION_DEFINE(sriqref_Out, slop_option_sriqref_Out)
#endif

#ifndef SLOP_OPTION_SRIQSAT_RSRC_DEFINED
#define SLOP_OPTION_SRIQSAT_RSRC_DEFINED
SLOP_OPTION_DEFINE(sriqsat_RSrc, slop_option_sriqsat_RSrc)
#endif

#ifndef SLOP_OPTION_SRIQSAT_RSRCS_DEFINED
#define SLOP_OPTION_SRIQSAT_RSRCS_DEFINED
SLOP_OPTION_DEFINE(sriqsat_RSrcs, slop_option_sriqsat_RSrcs)
#endif

#ifndef SLOP_OPTION_SRIQSAT_CUT_DEFINED
#define SLOP_OPTION_SRIQSAT_CUT_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Cut, slop_option_sriqsat_Cut)
#endif

#ifndef SLOP_OPTION_SRIQSAT_CROUND_DEFINED
#define SLOP_OPTION_SRIQSAT_CROUND_DEFINED
SLOP_OPTION_DEFINE(sriqsat_CRound, slop_option_sriqsat_CRound)
#endif

#ifndef SLOP_OPTION_SRIQREF_RSUCCACT_DEFINED
#define SLOP_OPTION_SRIQREF_RSUCCACT_DEFINED
SLOP_OPTION_DEFINE(sriqref_RSuccAct, slop_option_sriqref_RSuccAct)
#endif

#ifndef SLOP_OPTION_SRIQSAT_SEEN_DEFINED
#define SLOP_OPTION_SRIQSAT_SEEN_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Seen, slop_option_sriqsat_Seen)
#endif

#ifndef SLOP_OPTION_SRIQSAT_SUPPLIED_DEFINED
#define SLOP_OPTION_SRIQSAT_SUPPLIED_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Supplied, slop_option_sriqsat_Supplied)
#endif

#ifndef SLOP_OPTION_SRIQSAT_GROUP_DEFINED
#define SLOP_OPTION_SRIQSAT_GROUP_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Group, slop_option_sriqsat_Group)
#endif

#ifndef SLOP_OPTION_SRIQSAT_ACTED_DEFINED
#define SLOP_OPTION_SRIQSAT_ACTED_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Acted, slop_option_sriqsat_Acted)
#endif

#ifndef SLOP_OPTION_SRIQSAT_MOVED_DEFINED
#define SLOP_OPTION_SRIQSAT_MOVED_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Moved, slop_option_sriqsat_Moved)
#endif

#ifndef SLOP_OPTION_SRIQSAT_RUN_DEFINED
#define SLOP_OPTION_SRIQSAT_RUN_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Run, slop_option_sriqsat_Run)
#endif

#ifndef SLOP_OPTION_SRIQREF_NOMACT_DEFINED
#define SLOP_OPTION_SRIQREF_NOMACT_DEFINED
SLOP_OPTION_DEFINE(sriqref_NomAct, slop_option_sriqref_NomAct)
#endif

#ifndef SLOP_LIST_SRIQREF_NOMACT_DEFINED
#define SLOP_LIST_SRIQREF_NOMACT_DEFINED
#define SLOP_LIST_SRIQREF_NOMACT_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqref_NomAct, slop_list_sriqref_NomAct)
#endif


#endif
