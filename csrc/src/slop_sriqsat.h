#ifndef SLOP_sriqsat_H
#define SLOP_sriqsat_H

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
#include "slop_canon.h"
#include "slop_saturate.h"
#include "slop_sriqorder.h"
#include "slop_sriq.h"
#include "slop_sriqhyper.h"
#include "slop_sriqground.h"
#include "slop_sriqref.h"

typedef struct howl_sriqsat_SatConfig howl_sriqsat_SatConfig;
typedef struct howl_sriqsat_Counts howl_sriqsat_Counts;
typedef struct howl_sriqsat_SatResult howl_sriqsat_SatResult;
typedef struct howl_sriqsat_Delta howl_sriqsat_Delta;
typedef struct howl_sriqsat_Supply howl_sriqsat_Supply;
typedef struct howl_sriqsat_Flags howl_sriqsat_Flags;
typedef struct howl_sriqsat_View howl_sriqsat_View;
typedef struct howl_sriqsat_Step howl_sriqsat_Step;
typedef struct howl_sriqsat_Here howl_sriqsat_Here;
typedef struct howl_sriqsat_Adj howl_sriqsat_Adj;
typedef struct howl_sriqsat_Bucket howl_sriqsat_Bucket;
typedef struct howl_sriqsat_CIdx howl_sriqsat_CIdx;
typedef struct howl_sriqsat_JoinSite howl_sriqsat_JoinSite;
typedef struct howl_sriqsat_Trig howl_sriqsat_Trig;
typedef struct howl_sriqsat_SuccView howl_sriqsat_SuccView;
typedef struct howl_sriqsat_RSrc howl_sriqsat_RSrc;
typedef struct howl_sriqsat_RSrcs howl_sriqsat_RSrcs;
typedef struct howl_sriqsat_Cut howl_sriqsat_Cut;
typedef struct howl_sriqsat_CRound howl_sriqsat_CRound;
typedef struct howl_sriqsat_Seen howl_sriqsat_Seen;
typedef struct howl_sriqsat_Supplied howl_sriqsat_Supplied;
typedef struct howl_sriqsat_Group howl_sriqsat_Group;
typedef struct howl_sriqsat_Acted howl_sriqsat_Acted;
typedef struct howl_sriqsat_Moved howl_sriqsat_Moved;
typedef struct howl_sriqsat_Run howl_sriqsat_Run;

#ifndef SLOP_LIST_LIST_U8_DEFINED
#define SLOP_LIST_LIST_U8_DEFINED
#define SLOP_LIST_LIST_U8_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_list_u8, slop_list_list_u8)
#endif

#ifndef SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_IMPL_DEFINED
SLOP_LIST_DEFINE(uint8_t, slop_list_u8)
#endif

#ifndef SLOP_OPTION_LIST_U8_DEFINED
#define SLOP_OPTION_LIST_U8_DEFINED
SLOP_OPTION_DEFINE(slop_list_u8, slop_option_list_u8)
#endif

#ifndef SLOP_LIST_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_LIST_HOWL_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_list_howl_sriq_Premise, slop_list_list_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_LIST_HOWL_SRIQCTX_CTXSET_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_CTXSET_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_CTXSET_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqctx_CtxSet, slop_list_howl_sriqctx_CtxSet)
#endif

#ifndef SLOP_LIST_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_EDGE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqctx_Edge, slop_list_howl_sriqctx_Edge)
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

#ifndef SLOP_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_Premise, slop_list_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_LIST_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(slop_list_howl_sriq_Premise, slop_option_list_howl_sriq_Premise)
#endif

#ifndef SLOP_LIST_HOWL_SRIQREF_CAND_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_CAND_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_CAND_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqref_Cand, slop_list_howl_sriqref_Cand)
#endif

#ifndef SLOP_LIST_HOWL_SRIQREF_ROUND_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_ROUND_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_ROUND_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqref_Round, slop_list_howl_sriqref_Round)
#endif

#ifndef SLOP_LIST_HOWL_SRIQREF_SUCCACT_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_SUCCACT_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_SUCCACT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqref_SuccAct, slop_list_howl_sriqref_SuccAct)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_PSLOT_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PSLOT_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PSLOT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_PSlot, slop_list_howl_sriq_PSlot)
#endif

#ifndef SLOP_LIST_HOWL_SRIQREF_PJOB_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_PJOB_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_PJOB_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqref_PJob, slop_list_howl_sriqref_PJob)
#endif

#ifndef SLOP_LIST_HOWL_SRIQREF_OUT_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_OUT_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_OUT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqref_Out, slop_list_howl_sriqref_Out)
#endif

#ifndef SLOP_LIST_HOWL_SRIQREF_RSUCCACT_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_RSUCCACT_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_RSUCCACT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqref_RSuccAct, slop_list_howl_sriqref_RSuccAct)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_CTXSET_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_CTXSET_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_CtxSet, slop_option_howl_sriqctx_CtxSet)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Edge, slop_option_howl_sriqctx_Edge)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Premise, slop_option_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_CAND_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_CAND_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Cand, slop_option_howl_sriqref_Cand)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_ROUND_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_ROUND_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Round, slop_option_howl_sriqref_Round)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_SUCCACT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_SUCCACT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_SuccAct, slop_option_howl_sriqref_SuccAct)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PSLOT_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PSLOT_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_PSlot, slop_option_howl_sriq_PSlot)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_PJOB_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_PJOB_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_PJob, slop_option_howl_sriqref_PJob)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_OUT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_OUT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Out, slop_option_howl_sriqref_Out)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_RSUCCACT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_RSUCCACT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_RSuccAct, slop_option_howl_sriqref_RSuccAct)
#endif

struct howl_sriqsat_SatConfig {
    howl_sriqref_RefConfig base;
    int64_t perm;
    uint8_t scan;
    uint8_t defer;
    uint8_t views;
    uint8_t check;
    int64_t cancel;
};
typedef struct howl_sriqsat_SatConfig howl_sriqsat_SatConfig;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_SATCONFIG_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_SATCONFIG_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_SatConfig, slop_option_howl_sriqsat_SatConfig)
#endif

struct howl_sriqsat_Counts {
    int64_t cands;
    int64_t rcands;
    int64_t succs;
    int64_t rsuccs;
    int64_t noms;
    int64_t added;
    int64_t acts;
    int64_t hyper;
    int64_t stale;
};
typedef struct howl_sriqsat_Counts howl_sriqsat_Counts;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_COUNTS_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_COUNTS_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Counts, slop_option_howl_sriqsat_Counts)
#endif

struct howl_sriqsat_Delta {
    slop_list_howl_sriqctx_CtxSet news;
    slop_list_howl_sriqctx_CtxSet olds;
    slop_list_howl_sriqctx_Edge edges;
    int64_t nctx;
    int64_t ncst;
};
typedef struct howl_sriqsat_Delta howl_sriqsat_Delta;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_DELTA_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_DELTA_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Delta, slop_option_howl_sriqsat_Delta)
#endif

struct howl_sriqsat_Supply {
    uint32_t from;
    uint32_t f;
    slop_list_howl_types_Lit lits;
};
typedef struct howl_sriqsat_Supply howl_sriqsat_Supply;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_SUPPLY_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_SUPPLY_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Supply, slop_option_howl_sriqsat_Supply)
#endif

#ifndef SLOP_LIST_HOWL_SRIQSAT_SUPPLY_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_SUPPLY_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_SUPPLY_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqsat_Supply, slop_list_howl_sriqsat_Supply)
#endif

struct howl_sriqsat_Flags {
    slop_list_list_u8 fs;
};
typedef struct howl_sriqsat_Flags howl_sriqsat_Flags;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_FLAGS_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_FLAGS_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Flags, slop_option_howl_sriqsat_Flags)
#endif

#ifndef SLOP_LIST_HOWL_SRIQSAT_FLAGS_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_FLAGS_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_FLAGS_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqsat_Flags, slop_list_howl_sriqsat_Flags)
#endif

struct howl_sriqsat_View {
    slop_list_howl_types_Clause cs;
    slop_list_list_u8 fs;
};
typedef struct howl_sriqsat_View howl_sriqsat_View;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_VIEW_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_VIEW_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_View, slop_option_howl_sriqsat_View)
#endif

#ifndef SLOP_LIST_HOWL_SRIQSAT_VIEW_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_VIEW_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_VIEW_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqsat_View, slop_list_howl_sriqsat_View)
#endif

struct howl_sriqsat_Step {
    howl_sriqctx_Structure st;
    howl_sriqsat_Delta dl;
    uint8_t changed;
    slop_list_howl_sriqsat_Supply trig;
    int64_t acts;
    slop_list_howl_sriqsat_Flags flags;
};
typedef struct howl_sriqsat_Step howl_sriqsat_Step;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_STEP_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_STEP_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Step, slop_option_howl_sriqsat_Step)
#endif

struct howl_sriqsat_Adj {
    slop_list_howl_sriqctx_Edge ins;
    slop_list_howl_sriqctx_Edge outs;
};
typedef struct howl_sriqsat_Adj howl_sriqsat_Adj;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_ADJ_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_ADJ_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Adj, slop_option_howl_sriqsat_Adj)
#endif

#ifndef SLOP_LIST_HOWL_SRIQSAT_ADJ_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_ADJ_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_ADJ_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqsat_Adj, slop_list_howl_sriqsat_Adj)
#endif

struct howl_sriqsat_Bucket {
    slop_list_howl_sriqctx_Edge es;
};
typedef struct howl_sriqsat_Bucket howl_sriqsat_Bucket;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_BUCKET_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_BUCKET_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Bucket, slop_option_howl_sriqsat_Bucket)
#endif

#ifndef SLOP_LIST_HOWL_SRIQSAT_BUCKET_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_BUCKET_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_BUCKET_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqsat_Bucket, slop_list_howl_sriqsat_Bucket)
#endif

struct howl_sriqsat_CIdx {
    slop_list_howl_sriq_Premise aps;
    slop_list_howl_sriq_Premise dps;
    slop_list_howl_sriq_Premise ops;
    howl_sriqground_PIdx aix;
    howl_sriqground_PIdx dix;
    howl_sriqground_PIdx oix;
};
typedef struct howl_sriqsat_CIdx howl_sriqsat_CIdx;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_CIDX_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_CIDX_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_CIdx, slop_option_howl_sriqsat_CIdx)
#endif

#ifndef SLOP_LIST_HOWL_SRIQSAT_CIDX_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_CIDX_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_CIDX_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqsat_CIdx, slop_list_howl_sriqsat_CIdx)
#endif

struct howl_sriqsat_JoinSite {
    howl_types_Clause c;
    int64_t j;
};
typedef struct howl_sriqsat_JoinSite howl_sriqsat_JoinSite;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_JOINSITE_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_JOINSITE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_JoinSite, slop_option_howl_sriqsat_JoinSite)
#endif

#ifndef SLOP_LIST_HOWL_SRIQSAT_JOINSITE_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_JOINSITE_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_JOINSITE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqsat_JoinSite, slop_list_howl_sriqsat_JoinSite)
#endif

struct howl_sriqsat_Trig {
    howl_sriq_Premise p;
    howl_sriq_SuccSig sg;
};
typedef struct howl_sriqsat_Trig howl_sriqsat_Trig;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_TRIG_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_TRIG_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Trig, slop_option_howl_sriqsat_Trig)
#endif

#ifndef SLOP_LIST_HOWL_SRIQSAT_TRIG_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_TRIG_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_TRIG_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqsat_Trig, slop_list_howl_sriqsat_Trig)
#endif

struct howl_sriqsat_SuccView {
    howl_sriq_KSets ks;
    uint8_t covered;
};
typedef struct howl_sriqsat_SuccView howl_sriqsat_SuccView;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_SUCCVIEW_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_SUCCVIEW_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_SuccView, slop_option_howl_sriqsat_SuccView)
#endif

struct howl_sriqsat_RSrc {
    howl_types_Clause c;
    howl_sriq_PredView view;
};
typedef struct howl_sriqsat_RSrc howl_sriqsat_RSrc;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_RSRC_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_RSRC_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_RSrc, slop_option_howl_sriqsat_RSrc)
#endif

#ifndef SLOP_LIST_HOWL_SRIQSAT_RSRC_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_RSRC_DEFINED
#define SLOP_LIST_HOWL_SRIQSAT_RSRC_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqsat_RSrc, slop_list_howl_sriqsat_RSrc)
#endif

struct howl_sriqsat_RSrcs {
    slop_list_howl_sriqsat_RSrc all;
    slop_list_howl_sriqsat_RSrc news;
    slop_list_howl_sriqsat_RSrc olds;
};
typedef struct howl_sriqsat_RSrcs howl_sriqsat_RSrcs;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_RSRCS_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_RSRCS_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_RSrcs, slop_option_howl_sriqsat_RSrcs)
#endif

struct howl_sriqsat_Cut {
    slop_list_howl_sriqctx_Edge es;
    int64_t k;
};
typedef struct howl_sriqsat_Cut howl_sriqsat_Cut;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_CUT_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_CUT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Cut, slop_option_howl_sriqsat_Cut)
#endif

struct howl_sriqsat_CRound {
    howl_sriqref_Round r;
    int64_t tried;
    uint8_t big;
};
typedef struct howl_sriqsat_CRound howl_sriqsat_CRound;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_CROUND_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_CROUND_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_CRound, slop_option_howl_sriqsat_CRound)
#endif

struct howl_sriqsat_Seen {
    howl_sriqctx_Structure st;
    howl_sriqsat_Delta dl;
};
typedef struct howl_sriqsat_Seen howl_sriqsat_Seen;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_SEEN_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_SEEN_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Seen, slop_option_howl_sriqsat_Seen)
#endif

struct howl_sriqsat_Supplied {
    slop_list_howl_sriqsat_Supply trig;
    slop_list_howl_sriqsat_Supply evals;
    uint8_t grew;
};
typedef struct howl_sriqsat_Supplied howl_sriqsat_Supplied;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_SUPPLIED_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_SUPPLIED_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Supplied, slop_option_howl_sriqsat_Supplied)
#endif

struct howl_sriqsat_Group {
    howl_sriqsat_Supply s;
    uint8_t evald;
    uint8_t grew;
    int64_t next;
};
typedef struct howl_sriqsat_Group howl_sriqsat_Group;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_GROUP_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_GROUP_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Group, slop_option_howl_sriqsat_Group)
#endif

struct howl_sriqsat_Acted {
    howl_sriqsat_Delta dl;
    int64_t n;
};
typedef struct howl_sriqsat_Acted howl_sriqsat_Acted;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_ACTED_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_ACTED_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Acted, slop_option_howl_sriqsat_Acted)
#endif

struct howl_sriqsat_Moved {
    slop_list_howl_types_Clause news;
    slop_list_howl_types_Clause olds;
    int64_t n;
};
typedef struct howl_sriqsat_Moved howl_sriqsat_Moved;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_MOVED_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_MOVED_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Moved, slop_option_howl_sriqsat_Moved)
#endif

struct howl_sriqsat_Run {
    howl_sriqctx_Structure st;
    howl_sriqsat_Delta dl;
    howl_sriqref_RefStatus status;
    int64_t rounds;
    uint8_t going;
    slop_list_howl_sriqsat_Supply trig;
    slop_list_howl_sriqsat_Flags flags;
    howl_sriqsat_Counts counts;
};
typedef struct howl_sriqsat_Run howl_sriqsat_Run;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_RUN_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_RUN_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Run, slop_option_howl_sriqsat_Run)
#endif

struct howl_sriqsat_SatResult {
    howl_sriqref_RefResult res;
    howl_sriqsat_Counts counts;
    slop_list_howl_sriqsat_Supply trig;
    uint8_t cancelled;
};
typedef struct howl_sriqsat_SatResult howl_sriqsat_SatResult;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_SATRESULT_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_SATRESULT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_SatResult, slop_option_howl_sriqsat_SatResult)
#endif

struct howl_sriqsat_Here {
    uint32_t v;
    uint8_t root;
    uint8_t fresh;
    slop_list_howl_types_Clause all;
    slop_list_howl_types_Clause news;
    slop_list_howl_types_Clause olds;
    slop_list_howl_sriq_Premise aps;
    slop_list_howl_sriq_Premise dps;
    slop_list_howl_sriq_Premise ops;
    howl_sriqground_PIdx dix;
    howl_sriqground_PIdx aix;
    howl_sriqground_PIdx oix;
    howl_sriqhyper_HIdx hx;
    slop_list_howl_sriqsat_CIdx ixs;
    howl_sriqground_Ground gd;
    howl_sriqsat_RSrcs rs;
    uint8_t dfr;
    uint8_t views;
    int64_t room;
};
typedef struct howl_sriqsat_Here howl_sriqsat_Here;

#ifndef SLOP_OPTION_HOWL_SRIQSAT_HERE_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_HERE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Here, slop_option_howl_sriqsat_Here)
#endif

slop_list_howl_types_Clause howl_sriqsat_cs_at(slop_list_howl_sriqctx_CtxSet xs, int64_t v, slop_list_howl_types_Clause nobody);
slop_list_howl_types_Clause howl_sriqsat_permuted(slop_arena* arena, slop_list_howl_types_Clause xs, int64_t perm);
slop_list_int howl_sriqsat_ctx_order(slop_arena* arena, int64_t n, int64_t perm);
howl_sriqsat_CIdx howl_sriqsat_ctx_ix(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, int64_t v, int64_t perm, slop_list_howl_sriqsat_View vw);
slop_list_howl_sriqsat_CIdx howl_sriqsat_all_ixs(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, int64_t perm, slop_list_howl_sriqsat_View vw);
howl_sriqsat_CIdx howl_sriqsat_cix_at(slop_arena* arena, slop_list_howl_sriqsat_CIdx ixs, int64_t v);
howl_sriqsat_Here howl_sriqsat_here_of(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqground_Ground gd, howl_sriqhyper_HIdx hx, slop_list_howl_sriqsat_CIdx ixs, howl_sriqsat_RSrcs rs, int64_t v, int64_t perm, uint8_t dfr, uint8_t views);
howl_sriqsat_Here howl_sriqsat_here_room(howl_sriqsat_Here h, int64_t room);
uint8_t howl_sriqsat_roomy(slop_list_howl_sriqref_Cand out, howl_sriqsat_Here h);
uint8_t howl_sriqsat_edge_new(howl_sriqsat_Delta dl, howl_sriqctx_Edge e);
uint8_t howl_sriqsat_consts_new(howl_sriqctx_Structure st, howl_sriqsat_Delta dl);
slop_list_howl_sriqref_Cand howl_sriqsat_hyper_new_consts(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, uint32_t v, howl_types_Clause oc);
slop_list_howl_sriqref_Cand howl_sriqsat_hyper_bodiless(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqsat_Here h, howl_types_Clause oc);
uint8_t howl_sriqsat_dl10(howl_types_Clause oc);
howl_sriqhyper_HCtx howl_sriqsat_hctx_of(howl_sriqsat_Here h);
howl_sriqhyper_HOut howl_sriqsat_sat_hyper(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqsat_Here h, int64_t room);
slop_list_howl_sriqref_Cand howl_sriqsat_eq_pairs(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqsat_Here h, slop_list_howl_sriq_Premise p1s, slop_list_howl_sriq_Premise p2s);
slop_list_howl_sriqref_Cand howl_sriqsat_eq_side(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqsat_Here h, howl_sriq_Premise p1, uint32_t k1, howl_sriq_Premise p2);
slop_list_howl_sriqref_Cand howl_sriqsat_join_kept(slop_arena* arena, uint32_t v, howl_sriq_Premise p1, howl_types_Clause c, int64_t j);
slop_list_howl_sriqref_Cand howl_sriqsat_copy_cands(slop_arena* arena, slop_list_howl_sriqref_Cand cs);
uint8_t howl_sriqsat_holds_term(howl_types_Lit l, howl_types_ATerm s);
uint8_t howl_sriqsat_term_at(howl_types_Lit l, uint32_t a, uint8_t inner, howl_types_ATerm s);
howl_sriqhyper_HOut howl_sriqsat_sat_table2(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqsat_Here h, int64_t room);
uint8_t howl_sriqsat_within(slop_list_howl_sriqref_Cand a, slop_list_howl_sriqref_Cand b, int64_t room);
slop_list_howl_sriqref_Cand howl_sriqsat_t2_rest(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqsat_Here h, slop_list_howl_sriqref_Cand sofar, int64_t room);
uint8_t howl_sriqsat_g_counts(howl_sriqsat_Here h, int64_t i, int64_t which);
uint8_t howl_sriqsat_g_picks(howl_sriqsat_Here h, int64_t k, int64_t which);
slop_list_howl_sriq_Premise howl_sriqsat_g_prems(slop_arena* arena, howl_sriqsat_Here h, int64_t which, uint8_t eqs);
slop_list_howl_sriqref_Cand howl_sriqsat_join_into_g(slop_arena* arena, howl_sriqsat_Here h, slop_list_howl_sriq_Premise p1s, int64_t which);
slop_list_howl_sriqref_Cand howl_sriqsat_join_into_member(slop_arena* arena, howl_sriqsat_Here h, howl_sriq_Premise p1, howl_types_Clause g);
howl_types_Clause howl_sriqsat_empty_clause(slop_arena* arena);
uint8_t howl_sriqsat_has_eq(slop_list_howl_sriq_Premise ps);
slop_list_howl_sriqref_Cand howl_sriqsat_eq_ground(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqsat_Here h);
slop_list_howl_sriqref_Cand howl_sriqsat_join_ground(slop_arena* arena, howl_sriqsat_Here h);
slop_list_howl_sriqref_Cand howl_sriqsat_join_from_g(slop_arena* arena, howl_sriqsat_Here h, slop_list_howl_sriqsat_JoinSite sites, int64_t which);
slop_list_howl_sriqref_Cand howl_sriqsat_join_site_g(slop_arena* arena, howl_sriqsat_Here h, howl_sriqsat_JoinSite s, howl_types_Lit l, int64_t which);
slop_list_howl_sriqref_Cand howl_sriqsat_join_g_one(slop_arena* arena, howl_sriqsat_Here h, howl_sriqsat_JoinSite s, howl_sriq_Premise p1);
howl_sriq_Premise howl_sriqsat_fallback_premise(slop_arena* arena);
slop_list_howl_sriqsat_JoinSite howl_sriqsat_join_sites(slop_arena* arena, slop_list_howl_types_Clause cs);
slop_list_howl_sriqsat_JoinSite howl_sriqsat_sites_sorted(slop_arena* arena, slop_list_howl_sriqsat_JoinSite raw, howl_sriqsat_JoinSite s0);
howl_sriqsat_JoinSite howl_sriqsat_site_at(slop_list_howl_sriqsat_JoinSite ss, int64_t k, howl_sriqsat_JoinSite fallback);
howl_types_Lit howl_sriqsat_site_key(howl_sriqsat_JoinSite s);
int64_t howl_sriqsat_site_lower(slop_list_howl_sriqsat_JoinSite ss, howl_types_Lit l, howl_sriqsat_JoinSite fallback);
slop_option_howl_types_Lit howl_sriqsat_site_lit(howl_sriqsat_JoinSite s);
slop_list_howl_sriqref_Cand howl_sriqsat_sat_join(slop_arena* arena, uint32_t v, slop_list_howl_sriq_Premise p1s, slop_list_howl_sriqsat_JoinSite sites, int64_t room);
slop_list_howl_sriqref_Cand howl_sriqsat_join_one(slop_arena* arena, uint32_t v, howl_sriq_Premise p1, slop_list_howl_sriqsat_JoinSite sites);
slop_list_howl_sriqref_Cand howl_sriqsat_join_from(slop_arena* arena, uint32_t v, howl_sriq_Premise p1, slop_list_howl_sriqsat_JoinSite sites, int64_t k0, howl_sriqsat_JoinSite s0);
uint8_t howl_sriqsat_site_holds(howl_sriqsat_JoinSite s, howl_types_Lit l);
howl_sriqref_Round howl_sriqsat_nom_pairs(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, howl_sriqref_Dl4 d, slop_list_howl_sriq_Premise p1s, slop_list_howl_sriq_Premise p2s);
howl_sriqref_Round howl_sriqsat_sat_nom(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqsat_Here h);
slop_list_howl_sriqref_Round howl_sriqsat_nom_ground(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, howl_sriqref_Dl4 d, uint8_t all);
howl_sriqref_Round howl_sriqsat_nom_own(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, uint8_t all);
slop_list_howl_sriqref_Round howl_sriqsat_one_round(slop_arena* arena, howl_sriqref_Round a);
howl_sriqref_Round howl_sriqsat_nom_from_g(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, howl_sriqref_Dl4 d, slop_list_howl_sriq_Premise p2s, int64_t which);
howl_sriqref_Round howl_sriqsat_nom_g_one(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, howl_sriqref_Dl4 d, howl_sriq_Premise p2, uint32_t o, int64_t which);
slop_list_howl_sriqref_Round howl_sriqsat_two_rounds(slop_arena* arena, howl_sriqref_Round a, howl_sriqref_Round b);
uint8_t howl_sriqsat_k2_touched(slop_arena* arena, howl_sriqref_Env env, howl_sriqsat_Here h, howl_sriqindex_KIdx kn, howl_sriq_Premise p);
slop_list_howl_sriq_Premise howl_sriqsat_succ_premises(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h);
uint8_t howl_sriqsat_k2_touched_apart(howl_sriqref_Env env, howl_sriqsat_Here h, howl_sriqindex_KIdx kn, howl_sriq_Premise p);
slop_list_howl_sriqref_SuccAct howl_sriqsat_sat_succ(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriqref_SuccAct howl_sriqsat_succ_trigs(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, howl_sriqindex_KIdx bare, slop_list_howl_types_Lit base, slop_list_howl_sriqsat_Trig ts, howl_sriqsat_Trig t0);
howl_sriqref_SuccAct howl_sriqsat_succ_eval(slop_arena* arena, howl_sriqref_Env env, howl_sriqsat_Here h, howl_sriqsat_SuccView sv, howl_sriq_SuccSig sg);
slop_list_howl_sriqsat_Trig howl_sriqsat_triggers_of(slop_arena* arena, howl_sriqsat_Here h, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriqsat_Trig howl_sriqsat_trigs_sorted(slop_arena* arena, slop_list_howl_sriqsat_Trig raw, howl_sriqsat_Trig t0);
howl_sriqsat_Trig howl_sriqsat_trig_at(slop_list_howl_sriqsat_Trig ts, int64_t k, howl_sriqsat_Trig fallback);
int64_t howl_sriqsat_sg_cmp(howl_sriq_SuccSig a, howl_sriq_SuccSig b);
howl_sriqsat_SuccView howl_sriqsat_succ_view(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, howl_sriqindex_KIdx bare, slop_list_howl_types_Lit base, howl_sriq_SuccSig sg);
slop_list_howl_sriqref_SuccAct howl_sriqsat_succ_on(slop_arena* arena, howl_sriqref_Env env, howl_sriqsat_Here h, howl_sriqsat_SuccView sv, howl_sriqsat_Trig t);
slop_list_howl_types_Lit howl_sriqsat_merged_lits(slop_arena* arena, slop_list_howl_types_Lit a, slop_list_howl_types_Lit b);
slop_list_howl_types_Lit howl_sriqsat_unheld(slop_arena* arena, howl_sriqground_Ground gd, slop_list_howl_types_Lit k2);
uint8_t howl_sriqsat_covered_view(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, uint32_t f, slop_list_howl_types_Lit k2);
howl_sriqref_Out howl_sriqsat_pred_anchored(slop_arena* arena, howl_sriqref_Env env, howl_sriqref_PJob job, howl_sriqground_PIdx dix, howl_sriqground_PIdx oix, howl_sriqground_PIdx aix, int64_t room);
slop_list_howl_sriq_Premise howl_sriqsat_slot_ix(slop_arena* arena, howl_sriq_CSub s, howl_sriq_PSlot slot, howl_sriqground_PIdx ix);
howl_sriqref_Out howl_sriqsat_pred_anchor(slop_arena* arena, howl_sriqref_Env env, howl_sriqref_PJob job, howl_sriqground_PIdx dix, howl_sriqground_PIdx oix, howl_sriqground_PIdx aix, int64_t i, int64_t room);
howl_sriqref_Out howl_sriqsat_pred_run_ix(slop_arena* arena, howl_sriqref_Env env, howl_sriqref_PJob job, howl_sriqground_PIdx aix, int64_t room);
howl_sriqref_Out howl_sriqsat_pred_choices(slop_arena* arena, howl_sriqref_Env env, howl_sriqref_PJob job, slop_list_list_howl_sriq_Premise cs, slop_list_howl_sriq_Premise ps, int64_t room);
howl_sriqground_PIdx howl_sriqsat_w_ix(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, int64_t w, slop_list_howl_types_Clause cs, int64_t which);
howl_sriqref_Out howl_sriqsat_pred_side(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqsat_Here h, howl_sriqctx_Edge e);
howl_sriqref_Out howl_sriqsat_pred_edge_ix(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, howl_sriqctx_Edge e, slop_list_howl_types_Clause cs);
slop_list_howl_sriqref_PJob howl_sriqsat_side_jobs(slop_arena* arena, howl_sriqctx_Structure st, howl_sriq_PredView view, slop_list_howl_sriq_PSlot slots, howl_sriqctx_Edge e, uint8_t toroot);
howl_sriqref_Out howl_sriqsat_no_out(slop_arena* arena);
howl_sriqref_Out howl_sriqsat_sat_pred(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqsat_Here h, slop_list_howl_sriqctx_Edge ins);
slop_list_howl_sriqref_Out howl_sriqsat_pred_over(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqsat_Here h, howl_sriqctx_Edge e);
uint8_t howl_sriqsat_rpred_edge_new(howl_sriqsat_Delta dl, uint32_t v);
howl_sriqref_Out howl_sriqsat_sat_rpred(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqsat_Here h);
howl_sriqref_Out howl_sriqsat_rpred_from(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, slop_list_howl_sriqsat_RSrc rs, slop_list_howl_sriq_Premise aps, uint8_t anchored);
uint8_t howl_sriqsat_rpred_able(howl_sriqctx_Triggers tr, howl_sriq_PredView v);
slop_list_howl_sriqsat_RSrc howl_sriqsat_rsrcs_in(slop_arena* arena, howl_sriqctx_Triggers tr, slop_list_howl_types_Clause cs);
howl_sriqsat_RSrcs howl_sriqsat_rsrcs_of(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl);
howl_sriqref_PJob howl_sriqsat_rsrc_job(slop_arena* arena, howl_sriqctx_Structure st, uint32_t v, howl_sriqsat_RSrc r);
howl_sriqctx_Structure howl_sriqsat_local(howl_sriqctx_Structure st, howl_sriqsat_Adj a, slop_arena* arena);
howl_sriqsat_CRound howl_sriqsat_sat_ctx(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HIdx hx, slop_list_howl_sriqsat_CIdx ixs, howl_sriqsat_RSrcs rs, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqground_Ground gd, howl_sriqsat_Adj a, int64_t v, int64_t perm, uint8_t dfr, uint8_t views, int64_t room);
howl_sriqsat_CRound howl_sriqsat_sat_old(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, slop_list_howl_sriqctx_Edge ins, howl_sriqsat_Here h, int64_t room);
howl_sriqsat_CRound howl_sriqsat_sat_old_rest(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, slop_list_howl_sriqctx_Edge ins, howl_sriqsat_Here h, int64_t room, howl_sriqhyper_HOut t2);
howl_sriqctx_Edge howl_sriqsat_edge_at(slop_list_howl_sriqctx_Edge es, int64_t k, howl_sriqctx_Edge fallback);
slop_list_howl_sriqsat_Adj howl_sriqsat_adjacency(slop_arena* arena, howl_sriqctx_Structure st);
slop_list_howl_sriqctx_Edge howl_sriqsat_edges_at(slop_arena* arena, slop_list_howl_sriqsat_Bucket bs, int64_t v);
int64_t howl_sriqsat_u32_cmp(uint32_t a, uint32_t b);
howl_sriqsat_Cut howl_sriqsat_cut_at(slop_arena* arena, slop_list_howl_sriqctx_Edge es, slop_list_int idx, int64_t k, int64_t v, uint8_t by_to, howl_sriqctx_Edge e0);
slop_list_howl_sriqsat_Bucket howl_sriqsat_buckets(slop_arena* arena, slop_list_howl_sriqctx_Edge es, slop_list_int idx, int64_t n, uint8_t by_to, howl_sriqctx_Edge e0);
int64_t howl_sriqsat_idx_at(slop_list_int idx, int64_t k);
uint8_t howl_sriqsat_passes(howl_sriqsat_CRound cr, slop_list_howl_sriqref_Cand cands, int64_t room);
howl_sriqsat_CRound howl_sriqsat_sat_round(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HIdx hx, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqground_Ground gd, int64_t perm, uint8_t dfr, slop_list_howl_sriqsat_View vw, int64_t room);
slop_list_howl_sriqref_Cand howl_sriqsat_new_cores(slop_arena* arena, howl_sriqctx_Structure st, int64_t from);
howl_sriqsat_Step howl_sriqsat_sat_apply(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqground_Ground gd, howl_sriqref_Round r, uint8_t scan, uint8_t dfr, slop_list_howl_sriqsat_Supply trig, slop_list_howl_sriqsat_Flags fl);
slop_list_howl_sriqref_Cand howl_sriqsat_succ_cands(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqref_Round r, howl_sriqsat_Supplied sup, uint8_t dfr);
howl_sriqctx_Structure howl_sriqsat_edges_added(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqref_SuccAct succs, slop_list_howl_sriqref_RSuccAct rsuccs);
slop_list_howl_sriqctx_Edge howl_sriqsat_action_edges(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqref_SuccAct succs, slop_list_howl_sriqref_RSuccAct rsuccs);
slop_list_howl_sriqctx_Edge howl_sriqsat_first_new(slop_arena* arena, slop_list_howl_sriqctx_Edge old, slop_list_howl_sriqctx_Edge news);
slop_list_int howl_sriqsat_kept_positions(slop_arena* arena, slop_list_howl_sriqctx_Edge old, slop_list_howl_sriqctx_Edge news, howl_sriqctx_Edge e0);
uint8_t howl_sriqsat_run_first_new(slop_list_howl_sriqctx_Edge old, slop_list_int oidx, slop_list_howl_sriqctx_Edge news, int64_t prev, int64_t k, howl_sriqctx_Edge e0);
slop_list_howl_sriqctx_Edge howl_sriqsat_in_news_order(slop_arena* arena, slop_list_howl_sriqctx_Edge news, slop_list_int keep, howl_sriqctx_Edge e0);
uint8_t howl_sriqsat_edge_in(slop_list_howl_sriqctx_Edge es, slop_list_int idx, howl_sriqctx_Edge e, howl_sriqctx_Edge e0);
int64_t howl_sriqsat_edge_cmp(howl_sriqctx_Edge a, howl_sriqctx_Edge b);
int64_t howl_sriqsat_lk_rank(howl_sriqctx_EdgeLabel lk);
int64_t howl_sriqsat_int_cmp(int64_t a, int64_t b);
slop_list_howl_sriqref_Cand howl_sriqsat_outside_view(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqground_Ground gd, slop_list_howl_sriqref_Cand cands);
howl_sriqsat_Step howl_sriqsat_commit_all(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqref_Cand cands, int64_t c0, int64_t e0, int64_t n0, uint8_t scan, slop_list_howl_sriqsat_Flags fl);
slop_list_list_u8 howl_sriqsat_new_flags(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Clause ws, slop_list_list_u8 wf, howl_sriqsubsume_Committed cm, int64_t ncands);
slop_list_howl_types_Clause howl_sriqsat_run_of(slop_arena* arena, slop_list_howl_sriqref_Cand cands, slop_list_int idx, int64_t k, uint32_t v, howl_sriqref_Cand none_such);
howl_sriqsubsume_Committed howl_sriqsat_commit_one(slop_arena* arena, slop_list_howl_types_Clause ws, slop_list_howl_types_Clause cs, uint8_t scan);
slop_list_howl_types_Clause howl_sriqsat_minus_sorted(slop_arena* arena, slop_list_howl_types_Clause xs, slop_list_howl_types_Clause ys);
slop_list_howl_sriqctx_Edge howl_sriqsat_edges_from(slop_arena* arena, slop_list_howl_sriqctx_Edge es, int64_t k);
slop_list_howl_sriqsat_View howl_sriqsat_views_of(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqsat_Flags fl);
slop_list_howl_sriq_Premise howl_sriqsat_premises_in(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqsat_View vw, int64_t v, slop_list_howl_types_Clause cs);
slop_list_howl_sriq_Premise howl_sriqsat_clause_premises(slop_arena* arena, howl_types_Clause c, slop_list_u8 fs);
slop_list_howl_types_Lit howl_sriqsat_head_without(slop_arena* arena, slop_list_howl_types_Lit xs, int64_t i);
uint8_t howl_sriqsat_flag_at(slop_list_u8 fs, int64_t i);
slop_list_u8 howl_sriqsat_flags_of(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriqsat_View w, howl_types_Clause c);
int64_t howl_sriqsat_clause_pos(slop_list_howl_types_Clause cs, howl_types_Clause c);
uint8_t howl_sriqsat_sorted_at(slop_list_howl_types_Clause cs, int64_t k, howl_types_Clause c);
slop_list_list_u8 howl_sriqsat_walked_flags(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Clause ws, slop_list_list_u8 wf, slop_list_howl_types_Clause set);
uint8_t howl_sriqsat_below_at(slop_list_howl_types_Clause cs, int64_t j, howl_types_Clause c);
slop_list_list_u8 howl_sriqsat_fs_at(slop_list_howl_sriqsat_Flags fl, int64_t v, slop_list_list_u8 none_fs);
slop_list_howl_sriqsat_Flags howl_sriqsat_empty_flags(slop_arena* arena, howl_sriqctx_Structure st);
slop_list_howl_sriqsat_Flags howl_sriqsat_copy_flags(slop_arena* arena, slop_list_howl_sriqsat_Flags fl);
int64_t howl_sriqsat_stale_flags(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqsat_Flags fl);
int64_t howl_sriqsat_stale_in(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Clause cs, slop_list_list_u8 fs);
uint8_t howl_sriqsat_same_flags(slop_list_u8 a, slop_list_u8 b);
uint8_t howl_sriqsat_defer_on(howl_sriqsat_SatConfig cfg, howl_sriqref_RefIn in);
int64_t howl_sriqsat_key_cmp(uint32_t w1, uint32_t f1, uint32_t w2, uint32_t f2);
int64_t howl_sriqsat_supply_cmp(howl_sriqsat_Supply a, howl_sriqsat_Supply b);
howl_sriqsat_Supply howl_sriqsat_supply_at(slop_list_howl_sriqsat_Supply xs, int64_t k, howl_sriqsat_Supply fallback);
slop_list_howl_types_Lit howl_sriqsat_supply_of(slop_list_howl_sriqsat_Supply trig, uint32_t w, uint32_t f, slop_list_howl_types_Lit nolits);
uint8_t howl_sriqsat_lit_member(slop_list_howl_types_Lit ls, howl_types_Lit l);
uint8_t howl_sriqsat_body_within(howl_types_Clause c, slop_list_howl_types_Lit core, slop_list_howl_types_Lit lits);
uint8_t howl_sriqsat_supported(howl_types_Clause c, slop_list_howl_types_Lit core, slop_list_howl_sriqctx_Edge ins, slop_list_howl_sriqsat_Supply trig, slop_list_howl_types_Lit nolits);
slop_list_howl_sriqctx_Edge howl_sriqsat_ins_at(slop_arena* arena, slop_list_howl_sriqsat_Adj adj, int64_t v);
howl_sriqsat_Seen howl_sriqsat_projected(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, slop_list_howl_sriqsat_Supply trig);
howl_sriqctx_CtxSet howl_sriqsat_narrowed(slop_arena* arena, slop_list_howl_types_Clause cs, howl_sriqctx_Ctx c, slop_list_howl_sriqctx_Edge ins, slop_list_howl_sriqsat_Supply trig, slop_list_howl_types_Lit nolits);
howl_sriqsat_Supplied howl_sriqsat_supplied(slop_arena* arena, slop_list_howl_sriqsat_Supply trig, slop_list_howl_sriqref_SuccAct succs);
howl_sriqsat_Supplied howl_sriqsat_supplies_merged(slop_arena* arena, slop_list_howl_sriqsat_Supply raw, int64_t nold, howl_sriqsat_Supply s0);
howl_sriqsat_Group howl_sriqsat_supply_group(slop_arena* arena, slop_list_howl_sriqsat_Supply raw, slop_list_int idx, int64_t k, int64_t nold, howl_sriqsat_Supply s0);
slop_list_howl_types_Lit howl_sriqsat_ctx_core(slop_arena* arena, howl_sriqctx_Structure st, uint32_t v);
slop_list_howl_sriqref_Cand howl_sriqsat_pushed(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqsat_Supply evals);
slop_list_howl_sriqctx_Edge howl_sriqsat_edges_before(slop_arena* arena, slop_list_howl_sriqctx_Edge es, int64_t k);
howl_sriqsat_Step howl_sriqsat_deferred_step(slop_arena* arena, howl_sriqsat_Step sp, int64_t e0, slop_list_howl_sriqsat_Supply old, howl_sriqsat_Supplied sup);
howl_sriqsat_Acted howl_sriqsat_activated(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, int64_t e0, slop_list_howl_sriqsat_Supply old, slop_list_howl_sriqsat_Supply trig);
howl_sriqsat_Moved howl_sriqsat_acted_in(slop_arena* arena, howl_sriqctx_Ctx c, slop_list_howl_types_Clause news, slop_list_howl_types_Clause olds, slop_list_howl_sriqctx_Edge ins, slop_list_howl_sriqctx_Edge ins0, slop_list_howl_sriqsat_Supply old, slop_list_howl_sriqsat_Supply trig, slop_list_howl_types_Lit nolits);
uint8_t howl_sriqsat_ins_grew(slop_list_howl_sriqctx_Edge ins, slop_list_howl_sriqctx_Edge ins0, slop_list_howl_sriqsat_Supply old, slop_list_howl_sriqsat_Supply trig, slop_list_howl_types_Lit nolits);
slop_list_howl_types_Clause howl_sriqsat_merged_sorted(slop_arena* arena, slop_list_howl_types_Clause xs, slop_list_howl_types_Clause ys);
uint8_t howl_sriqsat_y_first(slop_list_howl_types_Clause xs, slop_list_howl_types_Clause ys, int64_t i, int64_t j);
slop_list_howl_sriqsat_Supply howl_sriqsat_copy_trig(slop_arena* arena, slop_list_howl_sriqsat_Supply trig);
howl_sriqsat_Delta howl_sriqsat_first_delta(slop_arena* arena, howl_sriqctx_Structure st);
howl_sriqsat_Delta howl_sriqsat_copy_delta(slop_arena* arena, howl_sriqsat_Delta dl);
int64_t howl_sriqsat_into_v(slop_list_howl_sriqref_Cand cs, uint32_t v);
int64_t howl_sriqsat_sum_added(howl_sriqsat_Delta dl);
howl_sriqsat_Counts howl_sriqsat_tally(howl_sriqsat_Counts c, howl_sriqref_Round r, howl_sriqsat_Delta dl, int64_t tried, int64_t acts, int64_t stale);
howl_sriqsat_Step howl_sriqsat_with_units(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqsat_Step sp);
slop_list_howl_sriqsat_Flags howl_sriqsat_with_root_flags(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Clause ws, slop_list_howl_sriqsat_Flags fl, slop_list_howl_types_Clause set);
howl_sriqctx_Structure howl_sriqsat_with_root_set(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_types_Clause cs);
howl_sriqsat_Delta howl_sriqsat_with_root_news(slop_arena* arena, howl_sriqsat_Delta dl, slop_list_howl_types_Clause set, slop_list_howl_types_Clause added, slop_list_howl_types_Clause nobody);
slop_list_howl_sriqctx_CtxSet howl_sriqsat_with_first(slop_arena* arena, slop_list_howl_sriqctx_CtxSet xs, slop_list_howl_types_Clause cs);
uint8_t howl_sriqsat_sorted_in(slop_list_howl_types_Clause cs, howl_types_Clause c);
howl_sriqref_RefStatus howl_sriqsat_sat_stop(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint8_t changed, howl_sriqref_RefConfig cfg);
uint8_t howl_sriqsat_holds_bot(slop_arena* arena, howl_sriqctx_Structure st, int64_t v);
howl_sriqsat_Run howl_sriqsat_sat_once(slop_arena* next, slop_arena* scratch, howl_sriqref_Env env, howl_sriqhyper_HIdx hx, howl_sriqsat_SatConfig cfg, uint8_t dfr, howl_sriqsat_Run run);
howl_sriqctx_Structure howl_sriqsat_read_view(slop_arena* arena, howl_sriqctx_Structure st);
howl_sriqctx_Structure howl_sriqsat_sat_materialise(slop_arena* arena, howl_sriqref_RefIn in, howl_sriqctx_Structure st);
uint8_t howl_sriqsat_defer_stable(slop_arena* arena, howl_sriqref_RefIn in, howl_sriqsat_SatConfig cfg, howl_sriqsat_SatResult p);
uint8_t howl_sriqsat_units_pushed(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqsat_Supply trig);
uint8_t howl_sriqsat_hyper_ix_agrees(slop_arena* arena, howl_sriqref_RefIn in, howl_sriqsat_SatConfig cfg, howl_sriqctx_Structure st);
uint8_t howl_sriqsat_hyper_ix_one(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HIdx hx, howl_sriqsat_Here h);
uint8_t howl_sriqsat_same_cands(slop_arena* arena, slop_list_howl_sriqref_Cand a, slop_list_howl_sriqref_Cand b);
slop_list_howl_types_Clause howl_sriqsat_distinct_clauses(slop_arena* arena, slop_list_howl_sriqref_Cand cs);
slop_list_howl_types_Clause howl_sriqsat_sorted_distinct(slop_arena* arena, slop_list_howl_types_Clause raw, howl_types_Clause c0);
howl_types_Clause howl_sriqsat_clause_of_l(slop_list_howl_types_Clause cs, int64_t k, howl_types_Clause fallback);
howl_sriqctx_Structure howl_sriqsat_ranked_structure(howl_sriqctx_Structure st, int64_t nquery);
howl_sriqsat_SatResult howl_sriqsat_sat_run(slop_arena* arena, howl_sriqref_RefIn in, howl_sriqsat_SatConfig cfg);

#ifndef SLOP_OPTION_HOWL_SRIQSAT_SATCONFIG_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_SATCONFIG_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_SatConfig, slop_option_howl_sriqsat_SatConfig)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_COUNTS_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_COUNTS_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Counts, slop_option_howl_sriqsat_Counts)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_SUPPLY_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_SUPPLY_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Supply, slop_option_howl_sriqsat_Supply)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_SATRESULT_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_SATRESULT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_SatResult, slop_option_howl_sriqsat_SatResult)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_CTXSET_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_CTXSET_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_CtxSet, slop_option_howl_sriqctx_CtxSet)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Edge, slop_option_howl_sriqctx_Edge)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_DELTA_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_DELTA_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Delta, slop_option_howl_sriqsat_Delta)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_LIST_U8_DEFINED
#define SLOP_OPTION_LIST_U8_DEFINED
SLOP_OPTION_DEFINE(slop_list_u8, slop_option_list_u8)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_FLAGS_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_FLAGS_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Flags, slop_option_howl_sriqsat_Flags)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_VIEW_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_VIEW_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_View, slop_option_howl_sriqsat_View)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_STEP_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_STEP_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Step, slop_option_howl_sriqsat_Step)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Premise, slop_option_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_CIDX_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_CIDX_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_CIdx, slop_option_howl_sriqsat_CIdx)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_HERE_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_HERE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Here, slop_option_howl_sriqsat_Here)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_ADJ_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_ADJ_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Adj, slop_option_howl_sriqsat_Adj)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_BUCKET_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_BUCKET_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Bucket, slop_option_howl_sriqsat_Bucket)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_CAND_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_CAND_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Cand, slop_option_howl_sriqref_Cand)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_JOINSITE_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_JOINSITE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_JoinSite, slop_option_howl_sriqsat_JoinSite)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_ROUND_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_ROUND_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Round, slop_option_howl_sriqref_Round)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_TRIG_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_TRIG_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Trig, slop_option_howl_sriqsat_Trig)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_SUCCVIEW_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_SUCCVIEW_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_SuccView, slop_option_howl_sriqsat_SuccView)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_SUCCACT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_SUCCACT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_SuccAct, slop_option_howl_sriqref_SuccAct)
#endif

#ifndef SLOP_OPTION_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_LIST_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(slop_list_howl_sriq_Premise, slop_option_list_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PSLOT_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PSLOT_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_PSlot, slop_option_howl_sriq_PSlot)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_PJOB_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_PJOB_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_PJob, slop_option_howl_sriqref_PJob)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_OUT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_OUT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Out, slop_option_howl_sriqref_Out)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_RSRC_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_RSRC_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_RSrc, slop_option_howl_sriqsat_RSrc)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_RSRCS_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_RSRCS_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_RSrcs, slop_option_howl_sriqsat_RSrcs)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_CUT_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_CUT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Cut, slop_option_howl_sriqsat_Cut)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_CROUND_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_CROUND_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_CRound, slop_option_howl_sriqsat_CRound)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_RSUCCACT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_RSUCCACT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_RSuccAct, slop_option_howl_sriqref_RSuccAct)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_SEEN_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_SEEN_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Seen, slop_option_howl_sriqsat_Seen)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_SUPPLIED_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_SUPPLIED_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Supplied, slop_option_howl_sriqsat_Supplied)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_GROUP_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_GROUP_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Group, slop_option_howl_sriqsat_Group)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_ACTED_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_ACTED_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Acted, slop_option_howl_sriqsat_Acted)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_MOVED_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_MOVED_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Moved, slop_option_howl_sriqsat_Moved)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSAT_RUN_DEFINED
#define SLOP_OPTION_HOWL_SRIQSAT_RUN_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsat_Run, slop_option_howl_sriqsat_Run)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_NOMACT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_NOMACT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_NomAct, slop_option_howl_sriqref_NomAct)
#endif

#ifndef SLOP_LIST_HOWL_SRIQREF_NOMACT_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_NOMACT_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_NOMACT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqref_NomAct, slop_list_howl_sriqref_NomAct)
#endif


#endif
