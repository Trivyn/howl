#ifndef SLOP_sriqsat_H
#define SLOP_sriqsat_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_sriqclauses.h"
#include "slop_sriqsubsume.h"
#include "slop_sriqctx.h"
#include "slop_canon.h"
#include "slop_sriq.h"
#include "slop_sriqref.h"

typedef struct sriqsat_SatConfig sriqsat_SatConfig;
typedef struct sriqsat_Counts sriqsat_Counts;
typedef struct sriqsat_SatResult sriqsat_SatResult;
typedef struct sriqsat_Delta sriqsat_Delta;
typedef struct sriqsat_Step sriqsat_Step;
typedef struct sriqsat_Here sriqsat_Here;
typedef struct sriqsat_Adj sriqsat_Adj;
typedef struct sriqsat_Bucket sriqsat_Bucket;
typedef struct sriqsat_Cut sriqsat_Cut;
typedef struct sriqsat_Run sriqsat_Run;

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

#ifndef SLOP_OPTION_SRIQCTX_CTXSET_DEFINED
#define SLOP_OPTION_SRIQCTX_CTXSET_DEFINED
SLOP_OPTION_DEFINE(sriqctx_CtxSet, slop_option_sriqctx_CtxSet)
#endif

#ifndef SLOP_OPTION_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Edge, slop_option_sriqctx_Edge)
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

struct sriqsat_SatConfig {
    sriqref_RefConfig base;
    int64_t perm;
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
};
typedef struct sriqsat_Counts sriqsat_Counts;

#ifndef SLOP_OPTION_SRIQSAT_COUNTS_DEFINED
#define SLOP_OPTION_SRIQSAT_COUNTS_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Counts, slop_option_sriqsat_Counts)
#endif

struct sriqsat_SatResult {
    sriqref_RefResult res;
    sriqsat_Counts counts;
};
typedef struct sriqsat_SatResult sriqsat_SatResult;

#ifndef SLOP_OPTION_SRIQSAT_SATRESULT_DEFINED
#define SLOP_OPTION_SRIQSAT_SATRESULT_DEFINED
SLOP_OPTION_DEFINE(sriqsat_SatResult, slop_option_sriqsat_SatResult)
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

struct sriqsat_Step {
    sriqctx_Structure st;
    sriqsat_Delta dl;
    uint8_t changed;
};
typedef struct sriqsat_Step sriqsat_Step;

#ifndef SLOP_OPTION_SRIQSAT_STEP_DEFINED
#define SLOP_OPTION_SRIQSAT_STEP_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Step, slop_option_sriqsat_Step)
#endif

struct sriqsat_Here {
    uint32_t v;
    uint8_t root;
    slop_list_types_Clause all;
    slop_list_types_Clause news;
    slop_list_types_Clause olds;
    slop_list_sriq_Premise aps;
    slop_list_sriq_Premise dps;
    slop_list_sriq_Premise ops;
};
typedef struct sriqsat_Here sriqsat_Here;

#ifndef SLOP_OPTION_SRIQSAT_HERE_DEFINED
#define SLOP_OPTION_SRIQSAT_HERE_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Here, slop_option_sriqsat_Here)
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

struct sriqsat_Cut {
    slop_list_sriqctx_Edge es;
    int64_t k;
};
typedef struct sriqsat_Cut sriqsat_Cut;

#ifndef SLOP_OPTION_SRIQSAT_CUT_DEFINED
#define SLOP_OPTION_SRIQSAT_CUT_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Cut, slop_option_sriqsat_Cut)
#endif

struct sriqsat_Run {
    sriqctx_Structure st;
    sriqsat_Delta dl;
    sriqref_RefStatus status;
    int64_t rounds;
    uint8_t going;
    sriqsat_Counts counts;
};
typedef struct sriqsat_Run sriqsat_Run;

#ifndef SLOP_OPTION_SRIQSAT_RUN_DEFINED
#define SLOP_OPTION_SRIQSAT_RUN_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Run, slop_option_sriqsat_Run)
#endif

slop_list_types_Clause sriqsat_cs_at(slop_list_sriqctx_CtxSet xs, int64_t v, slop_list_types_Clause nobody);
slop_list_types_Clause sriqsat_permuted(slop_arena* arena, slop_list_types_Clause xs, int64_t perm);
slop_list_int sriqsat_ctx_order(slop_arena* arena, int64_t n, int64_t perm);
sriqsat_Here sriqsat_here_of(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, int64_t v, int64_t perm);
slop_list_sriq_Premise sriqsat_pick(int64_t j, int64_t i, slop_list_sriq_Premise dps, slop_list_sriq_Premise ops, slop_list_sriq_Premise aps);
uint8_t sriqsat_edge_new(sriqsat_Delta dl, sriqctx_Edge e);
uint8_t sriqsat_consts_new(sriqctx_Structure st, sriqsat_Delta dl);
sriqref_Out sriqsat_hyper_anchor(slop_arena* arena, sriqref_Env env, sriqsat_Here h, sriq_HState start, types_Clause oc, int64_t i);
sriqref_Out sriqsat_hyper_clause(slop_arena* arena, sriqref_Env env, sriqsat_Here h, types_Clause oc);
slop_list_sriqref_Cand sriqsat_hyper_new_consts(slop_arena* arena, sriqctx_Structure st, sriqsat_Delta dl, uint32_t v, types_Clause oc);
sriqref_Out sriqsat_sat_hyper(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h);
slop_list_sriqref_Cand sriqsat_eq_pairs(slop_arena* arena, sriqctx_Structure st, sriqsat_Here h, slop_list_sriq_Premise p1s, slop_list_sriq_Premise p2s);
sriqref_Out sriqsat_sat_table2(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h);
sriqref_Round sriqsat_nom_pairs(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriqref_Dl4 d, slop_list_sriq_Premise p1s, slop_list_sriq_Premise p2s);
sriqref_Round sriqsat_sat_nom(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h);
slop_list_sriqref_Round sriqsat_two_rounds(slop_arena* arena, sriqref_Round a, sriqref_Round b);
uint8_t sriqsat_k2_touched(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriq_Premise p);
slop_list_sriq_Premise sriqsat_succ_premises(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h);
sriqref_Out sriqsat_pred_anchored(slop_arena* arena, sriqref_Env env, sriqref_PJob job, slop_list_sriq_Premise dws, slop_list_sriq_Premise ows, slop_list_sriq_Premise aws);
sriqref_Out sriqsat_pred_anchor(slop_arena* arena, sriqref_Env env, sriqref_PJob job, slop_list_sriq_Premise dws, slop_list_sriq_Premise ows, slop_list_sriq_Premise aws, int64_t i);
sriqref_Out sriqsat_pred_side(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, sriqctx_Edge e);
slop_list_sriqref_PJob sriqsat_side_jobs(slop_arena* arena, sriqctx_Structure st, sriq_PredView view, slop_list_sriq_PSlot slots, sriqctx_Edge e, uint8_t toroot);
sriqref_Out sriqsat_sat_pred(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, slop_list_sriqctx_Edge ins);
slop_list_sriqref_Out sriqsat_pred_over(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, sriqctx_Edge e);
uint8_t sriqsat_rpred_edge_new(sriqsat_Delta dl, uint32_t v);
sriqref_Out sriqsat_sat_rpred(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h);
sriqctx_Structure sriqsat_local(sriqctx_Structure st, sriqsat_Adj a, slop_arena* arena);
sriqref_Round sriqsat_sat_ctx(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Adj a, int64_t v, int64_t perm);
sriqref_Round sriqsat_sat_old(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, slop_list_sriqctx_Edge ins, sriqsat_Here h);
sriqctx_Edge sriqsat_edge_at(slop_list_sriqctx_Edge es, int64_t k, sriqctx_Edge fallback);
slop_list_sriqsat_Adj sriqsat_adjacency(slop_arena* arena, sriqctx_Structure st);
slop_list_sriqctx_Edge sriqsat_edges_at(slop_arena* arena, slop_list_sriqsat_Bucket bs, int64_t v);
int64_t sriqsat_u32_cmp(uint32_t a, uint32_t b);
sriqsat_Cut sriqsat_cut_at(slop_arena* arena, slop_list_sriqctx_Edge es, slop_list_int idx, int64_t k, int64_t v, uint8_t by_to, sriqctx_Edge e0);
slop_list_sriqsat_Bucket sriqsat_buckets(slop_arena* arena, slop_list_sriqctx_Edge es, slop_list_int idx, int64_t n, uint8_t by_to, sriqctx_Edge e0);
int64_t sriqsat_idx_at(slop_list_int idx, int64_t k);
sriqref_Round sriqsat_sat_round(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, int64_t perm);
slop_list_sriqref_Cand sriqsat_new_cores(slop_arena* arena, sriqctx_Structure st, int64_t from);
sriqsat_Step sriqsat_sat_apply(slop_arena* arena, sriqctx_Structure st, sriqref_Round r);
sriqsat_Step sriqsat_commit_all(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_Cand cands, int64_t c0, int64_t e0, int64_t n0);
slop_list_types_Clause sriqsat_run_of(slop_arena* arena, slop_list_sriqref_Cand cands, slop_list_int idx, int64_t k, uint32_t v, sriqref_Cand none_such);
sriqsubsume_Committed sriqsat_commit_one(slop_arena* arena, slop_list_types_Clause ws, slop_list_types_Clause cs);
slop_list_types_Clause sriqsat_minus_sorted(slop_arena* arena, slop_list_types_Clause xs, slop_list_types_Clause ys);
slop_list_sriqctx_Edge sriqsat_edges_from(slop_arena* arena, slop_list_sriqctx_Edge es, int64_t k);
sriqsat_Delta sriqsat_first_delta(slop_arena* arena, sriqctx_Structure st);
sriqsat_Delta sriqsat_copy_delta(slop_arena* arena, sriqsat_Delta dl);
int64_t sriqsat_into_v(slop_list_sriqref_Cand cs, uint32_t v);
int64_t sriqsat_sum_added(sriqsat_Delta dl);
sriqsat_Counts sriqsat_tally(sriqsat_Counts c, sriqref_Round r, sriqsat_Delta dl);
sriqsat_Run sriqsat_sat_once(slop_arena* next, slop_arena* scratch, sriqref_Env env, sriqsat_SatConfig cfg, sriqsat_Run run);
sriqsat_SatResult sriqsat_sat_run(slop_arena* arena, sriqref_RefIn in, sriqsat_SatConfig cfg);

#ifndef SLOP_OPTION_SRIQSAT_SATCONFIG_DEFINED
#define SLOP_OPTION_SRIQSAT_SATCONFIG_DEFINED
SLOP_OPTION_DEFINE(sriqsat_SatConfig, slop_option_sriqsat_SatConfig)
#endif

#ifndef SLOP_OPTION_SRIQSAT_COUNTS_DEFINED
#define SLOP_OPTION_SRIQSAT_COUNTS_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Counts, slop_option_sriqsat_Counts)
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

#ifndef SLOP_OPTION_SRIQREF_ROUND_DEFINED
#define SLOP_OPTION_SRIQREF_ROUND_DEFINED
SLOP_OPTION_DEFINE(sriqref_Round, slop_option_sriqref_Round)
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

#ifndef SLOP_OPTION_SRIQSAT_CUT_DEFINED
#define SLOP_OPTION_SRIQSAT_CUT_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Cut, slop_option_sriqsat_Cut)
#endif

#ifndef SLOP_OPTION_SRIQSAT_RUN_DEFINED
#define SLOP_OPTION_SRIQSAT_RUN_DEFINED
SLOP_OPTION_DEFINE(sriqsat_Run, slop_option_sriqsat_Run)
#endif

#ifndef SLOP_OPTION_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_LIST_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(slop_list_sriq_Premise, slop_option_list_sriq_Premise)
#endif

#ifndef SLOP_OPTION_SRIQREF_NOMACT_DEFINED
#define SLOP_OPTION_SRIQREF_NOMACT_DEFINED
SLOP_OPTION_DEFINE(sriqref_NomAct, slop_option_sriqref_NomAct)
#endif

#ifndef SLOP_OPTION_SRIQREF_SUCCACT_DEFINED
#define SLOP_OPTION_SRIQREF_SUCCACT_DEFINED
SLOP_OPTION_DEFINE(sriqref_SuccAct, slop_option_sriqref_SuccAct)
#endif

#ifndef SLOP_OPTION_SRIQREF_RSUCCACT_DEFINED
#define SLOP_OPTION_SRIQREF_RSUCCACT_DEFINED
SLOP_OPTION_DEFINE(sriqref_RSuccAct, slop_option_sriqref_RSuccAct)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

#ifndef SLOP_LIST_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_LIST_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_list_sriq_Premise, slop_list_list_sriq_Premise)
#endif

#ifndef SLOP_LIST_SRIQREF_NOMACT_DEFINED
#define SLOP_LIST_SRIQREF_NOMACT_DEFINED
#define SLOP_LIST_SRIQREF_NOMACT_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqref_NomAct, slop_list_sriqref_NomAct)
#endif

#ifndef SLOP_LIST_SRIQREF_SUCCACT_DEFINED
#define SLOP_LIST_SRIQREF_SUCCACT_DEFINED
#define SLOP_LIST_SRIQREF_SUCCACT_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqref_SuccAct, slop_list_sriqref_SuccAct)
#endif

#ifndef SLOP_LIST_SRIQREF_RSUCCACT_DEFINED
#define SLOP_LIST_SRIQREF_RSUCCACT_DEFINED
#define SLOP_LIST_SRIQREF_RSUCCACT_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqref_RSuccAct, slop_list_sriqref_RSuccAct)
#endif

#ifndef SLOP_LIST_TYPES_LIT_DEFINED
#define SLOP_LIST_TYPES_LIT_DEFINED
#define SLOP_LIST_TYPES_LIT_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Lit, slop_list_types_Lit)
#endif


#endif
