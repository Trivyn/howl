#ifndef SLOP_sriqref_H
#define SLOP_sriqref_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_sriqclauses.h"
#include "slop_sriqorder.h"
#include "slop_sriqsubsume.h"
#include "slop_sriqctx.h"
#include "slop_canon.h"
#include "slop_sriq.h"

typedef struct sriqref_RefConfig sriqref_RefConfig;
typedef struct sriqref_Env sriqref_Env;
typedef struct sriqref_Cand sriqref_Cand;
typedef struct sriqref_SuccAct sriqref_SuccAct;
typedef struct sriqref_RSuccAct sriqref_RSuccAct;
typedef struct sriqref_NomAct sriqref_NomAct;
typedef struct sriqref_Out sriqref_Out;
typedef struct sriqref_Round sriqref_Round;
typedef struct sriqref_Dl4 sriqref_Dl4;
typedef struct sriqref_PJob sriqref_PJob;
typedef struct sriqref_Committing sriqref_Committing;
typedef struct sriqref_Grown sriqref_Grown;
typedef struct sriqref_RefIn sriqref_RefIn;
typedef struct sriqref_RefResult sriqref_RefResult;

typedef enum {
    sriqref_RefStatus_rs_fixpoint,
    sriqref_RefStatus_rs_inconsistent,
    sriqref_RefStatus_rs_fuel,
    sriqref_RefStatus_rs_contexts,
    sriqref_RefStatus_rs_clauses,
    sriqref_RefStatus_rs_product,
    sriqref_RefStatus_rs_constants
} sriqref_RefStatus;

#ifndef SLOP_LIST_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_LIST_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_list_sriq_Premise, slop_list_list_sriq_Premise)
#endif

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

#ifndef SLOP_LIST_LIST_TYPES_LIT_DEFINED
#define SLOP_LIST_LIST_TYPES_LIT_DEFINED
#define SLOP_LIST_LIST_TYPES_LIT_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_list_types_Lit, slop_list_list_types_Lit)
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

#ifndef SLOP_LIST_TYPES_LIT_DEFINED
#define SLOP_LIST_TYPES_LIT_DEFINED
#define SLOP_LIST_TYPES_LIT_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Lit, slop_list_types_Lit)
#endif

#ifndef SLOP_OPTION_LIST_TYPES_LIT_DEFINED
#define SLOP_OPTION_LIST_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(slop_list_types_Lit, slop_option_list_types_Lit)
#endif

#ifndef SLOP_LIST_SRIQ_PSLOT_DEFINED
#define SLOP_LIST_SRIQ_PSLOT_DEFINED
#define SLOP_LIST_SRIQ_PSLOT_IMPL_DEFINED
SLOP_LIST_DEFINE(sriq_PSlot, slop_list_sriq_PSlot)
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

#ifndef SLOP_LIST_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_SRIQCTX_EDGE_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqctx_Edge, slop_list_sriqctx_Edge)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

#ifndef SLOP_OPTION_SRIQ_PSLOT_DEFINED
#define SLOP_OPTION_SRIQ_PSLOT_DEFINED
SLOP_OPTION_DEFINE(sriq_PSlot, slop_option_sriq_PSlot)
#endif

#ifndef SLOP_OPTION_SRIQCTX_CTX_DEFINED
#define SLOP_OPTION_SRIQCTX_CTX_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Ctx, slop_option_sriqctx_Ctx)
#endif

#ifndef SLOP_OPTION_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(sriq_Premise, slop_option_sriq_Premise)
#endif

#ifndef SLOP_OPTION_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Edge, slop_option_sriqctx_Edge)
#endif

struct sriqref_RefConfig {
    sriqctx_Strategy strat;
    int64_t fuel;
    int64_t lam;
    int64_t ctxs;
    int64_t cls;
    int64_t prod;
    int64_t cnst;
};
typedef struct sriqref_RefConfig sriqref_RefConfig;

#ifndef SLOP_OPTION_SRIQREF_REFCONFIG_DEFINED
#define SLOP_OPTION_SRIQREF_REFCONFIG_DEFINED
SLOP_OPTION_DEFINE(sriqref_RefConfig, slop_option_sriqref_RefConfig)
#endif

struct sriqref_Env {
    slop_list_types_Clause onto;
    sriqctx_Triggers tr;
    sriqctx_Strategy strat;
    int64_t lam;
    int64_t prod;
    int64_t nconst;
    slop_list_types_Clause nobody;
};
typedef struct sriqref_Env sriqref_Env;

#ifndef SLOP_OPTION_SRIQREF_ENV_DEFINED
#define SLOP_OPTION_SRIQREF_ENV_DEFINED
SLOP_OPTION_DEFINE(sriqref_Env, slop_option_sriqref_Env)
#endif

struct sriqref_Cand {
    uint32_t ctx;
    types_Clause c;
};
typedef struct sriqref_Cand sriqref_Cand;

#ifndef SLOP_OPTION_SRIQREF_CAND_DEFINED
#define SLOP_OPTION_SRIQREF_CAND_DEFINED
SLOP_OPTION_DEFINE(sriqref_Cand, slop_option_sriqref_Cand)
#endif

#ifndef SLOP_LIST_SRIQREF_CAND_DEFINED
#define SLOP_LIST_SRIQREF_CAND_DEFINED
#define SLOP_LIST_SRIQREF_CAND_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqref_Cand, slop_list_sriqref_Cand)
#endif

struct sriqref_SuccAct {
    uint32_t from;
    sriq_SuccSig sg;
    slop_list_types_Lit core;
    slop_list_types_Lit adds;
};
typedef struct sriqref_SuccAct sriqref_SuccAct;

#ifndef SLOP_OPTION_SRIQREF_SUCCACT_DEFINED
#define SLOP_OPTION_SRIQREF_SUCCACT_DEFINED
SLOP_OPTION_DEFINE(sriqref_SuccAct, slop_option_sriqref_SuccAct)
#endif

#ifndef SLOP_LIST_SRIQREF_SUCCACT_DEFINED
#define SLOP_LIST_SRIQREF_SUCCACT_DEFINED
#define SLOP_LIST_SRIQREF_SUCCACT_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqref_SuccAct, slop_list_sriqref_SuccAct)
#endif

struct sriqref_RSuccAct {
    uint32_t from;
    uint32_t u;
    types_Lit lit;
};
typedef struct sriqref_RSuccAct sriqref_RSuccAct;

#ifndef SLOP_OPTION_SRIQREF_RSUCCACT_DEFINED
#define SLOP_OPTION_SRIQREF_RSUCCACT_DEFINED
SLOP_OPTION_DEFINE(sriqref_RSuccAct, slop_option_sriqref_RSuccAct)
#endif

#ifndef SLOP_LIST_SRIQREF_RSUCCACT_DEFINED
#define SLOP_LIST_SRIQREF_RSUCCACT_DEFINED
#define SLOP_LIST_SRIQREF_RSUCCACT_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqref_RSuccAct, slop_list_sriqref_RSuccAct)
#endif

struct sriqref_NomAct {
    uint32_t o;
    uint32_t sb2;
    uint32_t i;
};
typedef struct sriqref_NomAct sriqref_NomAct;

#ifndef SLOP_OPTION_SRIQREF_NOMACT_DEFINED
#define SLOP_OPTION_SRIQREF_NOMACT_DEFINED
SLOP_OPTION_DEFINE(sriqref_NomAct, slop_option_sriqref_NomAct)
#endif

#ifndef SLOP_LIST_SRIQREF_NOMACT_DEFINED
#define SLOP_LIST_SRIQREF_NOMACT_DEFINED
#define SLOP_LIST_SRIQREF_NOMACT_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqref_NomAct, slop_list_sriqref_NomAct)
#endif

struct sriqref_Out {
    slop_list_sriqref_Cand cands;
    uint8_t over;
};
typedef struct sriqref_Out sriqref_Out;

#ifndef SLOP_OPTION_SRIQREF_OUT_DEFINED
#define SLOP_OPTION_SRIQREF_OUT_DEFINED
SLOP_OPTION_DEFINE(sriqref_Out, slop_option_sriqref_Out)
#endif

struct sriqref_Round {
    slop_list_sriqref_Cand cands;
    slop_list_sriqref_SuccAct succs;
    slop_list_sriqref_RSuccAct rsuccs;
    slop_list_sriqref_NomAct noms;
    uint8_t over;
};
typedef struct sriqref_Round sriqref_Round;

#ifndef SLOP_OPTION_SRIQREF_ROUND_DEFINED
#define SLOP_OPTION_SRIQREF_ROUND_DEFINED
SLOP_OPTION_DEFINE(sriqref_Round, slop_option_sriqref_Round)
#endif

struct sriqref_Dl4 {
    uint8_t ok;
    uint32_t b1;
    uint32_t sb2;
    uint32_t n;
};
typedef struct sriqref_Dl4 sriqref_Dl4;

#ifndef SLOP_OPTION_SRIQREF_DL4_DEFINED
#define SLOP_OPTION_SRIQREF_DL4_DEFINED
SLOP_OPTION_DEFINE(sriqref_Dl4, slop_option_sriqref_Dl4)
#endif

struct sriqref_PJob {
    sriq_PredView view;
    sriq_CSub s;
    slop_list_sriq_PSlot slots;
    uint32_t to;
    uint8_t rpred;
    uint8_t toroot;
};
typedef struct sriqref_PJob sriqref_PJob;

#ifndef SLOP_OPTION_SRIQREF_PJOB_DEFINED
#define SLOP_OPTION_SRIQREF_PJOB_DEFINED
SLOP_OPTION_DEFINE(sriqref_PJob, slop_option_sriqref_PJob)
#endif

struct sriqref_Committing {
    sriqctx_Structure st;
    uint8_t changed;
};
typedef struct sriqref_Committing sriqref_Committing;

#ifndef SLOP_OPTION_SRIQREF_COMMITTING_DEFINED
#define SLOP_OPTION_SRIQREF_COMMITTING_DEFINED
SLOP_OPTION_DEFINE(sriqref_Committing, slop_option_sriqref_Committing)
#endif

struct sriqref_Grown {
    slop_list_types_Clause cs;
    uint8_t grew;
};
typedef struct sriqref_Grown sriqref_Grown;

#ifndef SLOP_OPTION_SRIQREF_GROWN_DEFINED
#define SLOP_OPTION_SRIQREF_GROWN_DEFINED
SLOP_OPTION_DEFINE(sriqref_Grown, slop_option_sriqref_Grown)
#endif

struct sriqref_RefIn {
    slop_list_types_Clause onto;
    int64_t nclass;
    int64_t nquery;
    int64_t nrole;
    int64_t nfn;
    int64_t nconst;
};
typedef struct sriqref_RefIn sriqref_RefIn;

#ifndef SLOP_OPTION_SRIQREF_REFIN_DEFINED
#define SLOP_OPTION_SRIQREF_REFIN_DEFINED
SLOP_OPTION_DEFINE(sriqref_RefIn, slop_option_sriqref_RefIn)
#endif

struct sriqref_RefResult {
    sriqref_RefStatus status;
    int64_t rounds;
    sriqctx_Structure st;
};
typedef struct sriqref_RefResult sriqref_RefResult;

#ifndef SLOP_OPTION_SRIQREF_REFRESULT_DEFINED
#define SLOP_OPTION_SRIQREF_REFRESULT_DEFINED
SLOP_OPTION_DEFINE(sriqref_RefResult, slop_option_sriqref_RefResult)
#endif

slop_list_types_Clause sriqref_set_of(sriqref_Env env, sriqctx_Structure st, int64_t v);
slop_option_sriqctx_Ctx sriqref_ctx_of(sriqctx_Structure st, int64_t v);
uint8_t sriqref_is_root(sriqctx_Structure st, int64_t v);
slop_list_types_Lit sriqref_core_at(sriqref_Env env, sriqctx_Structure st, slop_arena* arena, int64_t v);
slop_list_sriqref_Cand sriqref_one_cand(slop_arena* arena, uint32_t v, types_Clause c);
sriqref_Out sriqref_out_of(slop_list_sriqref_Cand cands, uint8_t over);
slop_list_sriq_Premise sriqref_premises_of(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Clause cs);
int64_t sriqref_consts_of(sriqctx_Structure st);
slop_list_sriqref_Cand sriqref_conclusion(slop_arena* arena, uint32_t v, sriq_RConcl r);
slop_list_sriqref_Cand sriqref_append_cands(slop_arena* arena, slop_list_sriqref_Cand a, slop_list_sriqref_Cand b);
sriq_Premise sriqref_prem_at(slop_list_sriq_Premise ps, int64_t k, sriq_Premise fallback);
int64_t sriqref_product(slop_list_list_sriq_Premise cs, int64_t cap);
slop_list_sriqref_Cand sriqref_ref_core(slop_arena* arena, uint32_t v, slop_list_types_Lit core);
uint8_t sriqref_x_fits(uint8_t root, types_ATerm a, types_ATerm t);
slop_list_sriq_Premise sriqref_slot_cands(slop_arena* arena, uint8_t root, types_Lit a, slop_list_sriq_Premise ps);
sriq_HState sriqref_hyper_choice(slop_arena* arena, sriq_HState start, slop_list_types_Lit atoms, slop_list_list_sriq_Premise cs, int64_t t, sriq_Premise fallback);
sriqref_Out sriqref_hyper_with(slop_arena* arena, sriqref_Env env, uint32_t v, uint8_t root, sriq_HState start, types_Clause oc, slop_list_sriq_Premise ps);
slop_list_sriqref_Cand sriqref_hyper_choices(slop_arena* arena, uint32_t v, sriq_HState start, types_Clause oc, slop_list_list_sriq_Premise cs, int64_t n, sriq_Premise p0);
slop_list_sriqref_Cand sriqref_hyper_bodiless(slop_arena* arena, sriqctx_Structure st, uint32_t v, uint8_t root, types_Clause oc);
slop_list_sriqref_Cand sriqref_hyper_consts(slop_arena* arena, sriqctx_Structure st, uint32_t v, types_Clause oc);
sriqref_Out sriqref_ref_hyper(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, uint8_t root, slop_list_sriq_Premise ps);
slop_list_sriqref_Cand sriqref_eq_positions(slop_arena* arena, sriqorder_SriqOrder ord, uint32_t v, uint8_t root, sriq_Premise p1, uint32_t k1, sriq_Premise p2);
slop_list_sriqref_Cand sriqref_eq_at(slop_arena* arena, sriqorder_SriqOrder ord, uint32_t v, uint8_t root, sriq_Premise p1, uint32_t k1, sriq_Premise p2, uint32_t a);
slop_list_u8 sriqref_bools(slop_arena* arena);
slop_list_sriqref_Cand sriqref_ref_eq(slop_arena* arena, sriqorder_SriqOrder ord, uint32_t v, uint8_t root, slop_list_sriq_Premise ps);
slop_list_sriqref_Cand sriqref_ref_ineq(slop_arena* arena, uint32_t v, slop_list_sriq_Premise ps);
slop_list_sriqref_Cand sriqref_factor_of(slop_arena* arena, sriqorder_SriqOrder ord, uint32_t v, sriq_Premise p);
slop_list_sriqref_Cand sriqref_ref_factor(slop_arena* arena, sriqorder_SriqOrder ord, uint32_t v, slop_list_sriq_Premise ps);
slop_list_sriqref_Cand sriqref_join_into(slop_arena* arena, uint32_t v, sriq_Premise p1, types_Clause c2);
slop_list_sriqref_Cand sriqref_ref_join(slop_arena* arena, uint32_t v, slop_list_sriq_Premise ps, slop_list_types_Clause cs);
sriqref_Dl4 sriqref_dl4_of(types_Clause oc);
uint8_t sriqref_at_most_head(slop_list_types_Lit head, int64_t m);
slop_option_u32 sriqref_child_of(sriqorder_SriqOrder ord, uint32_t o, uint32_t sb2, uint32_t i);
sriqref_Round sriqref_nom_pair(slop_arena* arena, sriqref_Env env, sriqorder_SriqOrder ord, uint32_t v, sriqref_Dl4 d, sriq_Premise p1, sriq_Premise p2);
uint8_t sriqref_nom_first(sriq_Premise p, sriqref_Dl4 d);
uint8_t sriqref_nom_second(sriq_Premise p, sriqref_Dl4 d, uint32_t o);
sriqref_Round sriqref_nom_clause(slop_arena* arena, sriqref_Env env, sriqorder_SriqOrder ord, uint32_t v, sriqref_Dl4 d, slop_list_sriq_Premise ps);
sriqref_Round sriqref_ref_nom(slop_arena* arena, sriqref_Env env, sriqorder_SriqOrder ord, uint32_t v, slop_list_sriq_Premise ps);
sriqref_Round sriqref_round_of(slop_list_sriqref_Cand cands, slop_list_sriqref_SuccAct succs, slop_list_sriqref_RSuccAct rsuccs, slop_list_sriqref_NomAct noms, uint8_t over);
uint8_t sriqref_edge_is(sriqctx_Edge e, uint32_t from, uint32_t to, sriqctx_EdgeLabel lk, uint32_t label);
uint8_t sriqref_has_edge(sriqctx_Structure st, uint32_t from, uint32_t to, sriqctx_EdgeLabel lk, uint32_t label);
uint8_t sriqref_covered(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, uint32_t f, slop_list_types_Lit k2);
slop_list_sriqref_SuccAct sriqref_succ_of(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, uint8_t root, slop_list_types_Clause cs, sriq_Premise p);
slop_list_sriqref_SuccAct sriqref_succ_with(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, slop_list_types_Clause cs, sriq_Premise p, sriq_SuccSig sg);
slop_list_sriqref_SuccAct sriqref_ref_succ(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, uint8_t root, slop_list_types_Clause cs, slop_list_sriq_Premise ps);
slop_list_u32 sriqref_lit_consts(slop_arena* arena, types_Lit l);
slop_list_sriqref_RSuccAct sriqref_ref_rsucc(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, slop_list_sriq_Premise ps);
slop_list_sriqref_RSuccAct sriqref_rsucc_of(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, slop_list_types_Clause root_set, sriq_Premise p);
slop_list_sriq_Premise sriqref_pslot_cands(slop_arena* arena, sriq_CSub s, sriq_PSlot slot, slop_list_sriq_Premise ps);
sriq_PState sriqref_pred_choice(slop_arena* arena, sriq_PState start, sriq_CSub s, slop_list_sriq_PSlot slots, slop_list_list_sriq_Premise cs, int64_t t, sriq_Premise fallback);
sriqref_Out sriqref_pred_run(slop_arena* arena, sriqref_Env env, sriqref_PJob job, slop_list_sriq_Premise ps);
slop_list_sriqref_Cand sriqref_pred_one(slop_arena* arena, sriqref_Env env, sriqref_PJob job, slop_list_list_sriq_Premise cs, int64_t t, slop_list_sriq_Premise ps);
sriq_Premise sriqref_prem_or(slop_list_sriq_Premise ps, sriq_PredView v);
slop_list_sriq_PSlot sriqref_slots_of(slop_arena* arena, slop_list_types_Lit lits);
sriqref_Out sriqref_pred_edge(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, sriqctx_Edge e, slop_list_types_Clause cs);
sriqref_Out sriqref_pred_clause(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqctx_Edge e, uint32_t w, uint8_t toroot, slop_list_types_Lit core, slop_list_sriq_Premise ws, types_Clause c);
sriqref_PJob sriqref_away_job(sriq_PredView view, slop_list_sriq_PSlot slots, uint32_t f, uint32_t w);
sriqref_Out sriqref_pred_root(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriq_PredView view, slop_list_sriq_PSlot slots, uint32_t w, uint32_t f, slop_list_sriq_Premise ws);
sriqref_PJob sriqref_root_job(sriq_PredView view, slop_list_sriq_PSlot slots, uint32_t w, uint32_t f, uint32_t u);
sriq_SuccSig sriqref_sig_away(uint32_t f);
sriq_SuccSig sriqref_sig_at(uint32_t f, uint32_t u);
sriqref_Out sriqref_ref_pred(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, slop_list_types_Clause cs);
uint32_t sriqref_slot_const(types_Lit l);
slop_list_sriq_PSlot sriqref_rslots(slop_arena* arena, sriqctx_Structure st, uint32_t v, slop_list_types_Lit lits);
sriqref_Out sriqref_ref_rpred(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, slop_list_sriq_Premise ps);
sriqref_PJob sriqref_rpred_job(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, types_Clause c);
sriqref_Out sriqref_ctx_table2(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, uint8_t root, slop_list_types_Clause cs, slop_list_sriq_Premise ps);
sriqref_Round sriqref_ctx_round(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v);
sriqref_Round sriqref_ref_round(slop_arena* arena, sriqref_Env env, sriqctx_Structure st);
int64_t sriqref_nom_cmp(sriqref_NomAct a, sriqref_NomAct b);
sriqref_NomAct sriqref_nom_at(slop_list_sriqref_NomAct xs, int64_t k, sriqref_NomAct fallback);
sriqorder_SriqOrder sriqref_add_consts(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_sriqref_NomAct noms);
sriqorder_SriqOrder sriqref_with_child(slop_arena* arena, sriqorder_SriqOrder ord, sriqref_NomAct a);
sriqorder_SriqOrder sriqref_push_const(slop_arena* arena, sriqorder_SriqOrder ord, sriqorder_ConstEntry e);
int64_t sriqref_lits_cmp(slop_list_types_Lit a, slop_list_types_Lit b);
uint8_t sriqref_core_in(slop_list_list_types_Lit cores, slop_list_types_Lit c);
slop_list_types_Lit sriqref_core_at_k(slop_list_list_types_Lit xs, int64_t k, slop_list_types_Lit fallback);
sriqctx_Structure sriqref_add_contexts(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_SuccAct succs);
sriqctx_Structure sriqref_with_contexts(slop_arena* arena, sriqctx_Structure st, slop_list_list_types_Lit fresh, slop_list_types_Lit f0);
sriqctx_Structure sriqref_add_edges(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_SuccAct succs, slop_list_sriqref_RSuccAct rsuccs);
slop_list_sriqctx_Edge sriqref_succ_edges(slop_arena* arena, sriqctx_Structure st, slop_list_sriqctx_Edge es, sriqref_SuccAct a);
slop_list_sriqctx_Edge sriqref_with_edge(slop_arena* arena, slop_list_sriqctx_Edge es, sriqctx_Edge e);
types_Clause sriqref_unit_clause(slop_arena* arena, types_Lit a);
slop_list_sriqref_Cand sriqref_action_cands(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_SuccAct succs, slop_list_sriqref_RSuccAct rsuccs);
sriqref_Cand sriqref_cand_at(slop_list_sriqref_Cand xs, int64_t k, sriqref_Cand fallback);
int64_t sriqref_cand_cmp(sriqref_Cand a, sriqref_Cand b);
sriqref_Committing sriqref_commit_sets(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_Cand cands);
sriqref_Committing sriqref_commit_sorted(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_Cand cands, sriqref_Cand c0);
sriqref_Grown sriqref_grow(slop_arena* arena, slop_list_types_Clause cs, slop_list_sriqref_Cand cands, slop_list_int idx, uint32_t v, sriqref_Cand c0);
sriqref_Committing sriqref_ref_apply(slop_arena* arena, sriqctx_Structure st, sriqref_Round r);
int64_t sriqref_total_clauses(sriqctx_Structure st);
uint8_t sriqref_inconsistent_now(slop_arena* arena, sriqref_Env env, sriqctx_Structure st);
sriqctx_Structure sriqref_ref_elim(slop_arena* arena, sriqctx_Structure st);
int64_t sriqref_ref_lambda(sriqctx_Triggers tr, sriqctx_Strategy s, int64_t nquery);
sriqref_RefIn sriqref_ref_input(slop_arena* arena, sriqclauses_SriqClauses sc);
sriqref_RefResult sriqref_ref_run(slop_arena* arena, sriqref_RefIn in, sriqref_RefConfig cfg);
slop_list_types_Lit sriqref_copy_lits(slop_arena* arena, slop_list_types_Lit ls);
slop_list_types_Clause sriqref_copy_clauses(slop_arena* arena, slop_list_types_Clause cs);
sriqctx_Structure sriqref_copy_structure(slop_arena* arena, sriqctx_Structure st);
sriqref_Env sriqref_env_of(slop_arena* arena, sriqref_RefIn in, sriqref_RefConfig cfg, sriqctx_Triggers tr, int64_t lam);
sriqref_Env sriqref_env_for(slop_arena* arena, sriqref_RefIn in, sriqref_RefConfig cfg);
uint8_t sriqref_ref_stable(slop_arena* arena, sriqref_RefIn in, sriqref_RefConfig cfg, sriqctx_Structure st);
sriqref_RefStatus sriqref_stop_status(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqref_Committing cm, sriqref_RefConfig cfg);
slop_list_types_Clause sriqref_ref_set(slop_arena* arena, sriqctx_Structure st, int64_t v);
uint8_t sriqref_clause_in(slop_list_types_Clause xs, types_Clause c);
uint8_t sriqref_same_clauses(slop_list_types_Clause a, slop_list_types_Clause b);
slop_list_types_Clause sriqref_cand_clauses(slop_arena* arena, slop_list_sriqref_Cand cs);
uint8_t sriqref_hyper_agrees(slop_arena* arena, sriqref_Env env, uint32_t v, uint8_t root, types_Clause oc, slop_list_sriq_Premise ps);
uint8_t sriqref_pred_agrees(slop_arena* arena, sriqref_Env env, sriqref_PJob job, slop_list_sriq_Premise ps);
uint8_t sriqref_ctx_agrees(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v);
uint8_t sriqref_edge_agrees(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, sriqctx_Edge e, slop_list_types_Clause cs);
uint8_t sriqref_combinators_agree(slop_arena* arena, sriqref_RefIn in, sriqref_RefConfig cfg, sriqctx_Structure st);

#ifndef SLOP_OPTION_SRIQREF_REFCONFIG_DEFINED
#define SLOP_OPTION_SRIQREF_REFCONFIG_DEFINED
SLOP_OPTION_DEFINE(sriqref_RefConfig, slop_option_sriqref_RefConfig)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_SRIQREF_ENV_DEFINED
#define SLOP_OPTION_SRIQREF_ENV_DEFINED
SLOP_OPTION_DEFINE(sriqref_Env, slop_option_sriqref_Env)
#endif

#ifndef SLOP_OPTION_SRIQREF_CAND_DEFINED
#define SLOP_OPTION_SRIQREF_CAND_DEFINED
SLOP_OPTION_DEFINE(sriqref_Cand, slop_option_sriqref_Cand)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

#ifndef SLOP_OPTION_SRIQREF_SUCCACT_DEFINED
#define SLOP_OPTION_SRIQREF_SUCCACT_DEFINED
SLOP_OPTION_DEFINE(sriqref_SuccAct, slop_option_sriqref_SuccAct)
#endif

#ifndef SLOP_OPTION_SRIQREF_RSUCCACT_DEFINED
#define SLOP_OPTION_SRIQREF_RSUCCACT_DEFINED
SLOP_OPTION_DEFINE(sriqref_RSuccAct, slop_option_sriqref_RSuccAct)
#endif

#ifndef SLOP_OPTION_SRIQREF_NOMACT_DEFINED
#define SLOP_OPTION_SRIQREF_NOMACT_DEFINED
SLOP_OPTION_DEFINE(sriqref_NomAct, slop_option_sriqref_NomAct)
#endif

#ifndef SLOP_OPTION_SRIQREF_OUT_DEFINED
#define SLOP_OPTION_SRIQREF_OUT_DEFINED
SLOP_OPTION_DEFINE(sriqref_Out, slop_option_sriqref_Out)
#endif

#ifndef SLOP_OPTION_SRIQREF_ROUND_DEFINED
#define SLOP_OPTION_SRIQREF_ROUND_DEFINED
SLOP_OPTION_DEFINE(sriqref_Round, slop_option_sriqref_Round)
#endif

#ifndef SLOP_OPTION_SRIQREF_DL4_DEFINED
#define SLOP_OPTION_SRIQREF_DL4_DEFINED
SLOP_OPTION_DEFINE(sriqref_Dl4, slop_option_sriqref_Dl4)
#endif

#ifndef SLOP_OPTION_SRIQ_PSLOT_DEFINED
#define SLOP_OPTION_SRIQ_PSLOT_DEFINED
SLOP_OPTION_DEFINE(sriq_PSlot, slop_option_sriq_PSlot)
#endif

#ifndef SLOP_OPTION_SRIQREF_PJOB_DEFINED
#define SLOP_OPTION_SRIQREF_PJOB_DEFINED
SLOP_OPTION_DEFINE(sriqref_PJob, slop_option_sriqref_PJob)
#endif

#ifndef SLOP_OPTION_SRIQREF_COMMITTING_DEFINED
#define SLOP_OPTION_SRIQREF_COMMITTING_DEFINED
SLOP_OPTION_DEFINE(sriqref_Committing, slop_option_sriqref_Committing)
#endif

#ifndef SLOP_OPTION_SRIQREF_GROWN_DEFINED
#define SLOP_OPTION_SRIQREF_GROWN_DEFINED
SLOP_OPTION_DEFINE(sriqref_Grown, slop_option_sriqref_Grown)
#endif

#ifndef SLOP_OPTION_SRIQREF_REFIN_DEFINED
#define SLOP_OPTION_SRIQREF_REFIN_DEFINED
SLOP_OPTION_DEFINE(sriqref_RefIn, slop_option_sriqref_RefIn)
#endif

#ifndef SLOP_OPTION_SRIQREF_REFRESULT_DEFINED
#define SLOP_OPTION_SRIQREF_REFRESULT_DEFINED
SLOP_OPTION_DEFINE(sriqref_RefResult, slop_option_sriqref_RefResult)
#endif

#ifndef SLOP_OPTION_SRIQCTX_CTX_DEFINED
#define SLOP_OPTION_SRIQCTX_CTX_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Ctx, slop_option_sriqctx_Ctx)
#endif

#ifndef SLOP_OPTION_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(sriq_Premise, slop_option_sriq_Premise)
#endif

#ifndef SLOP_OPTION_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_LIST_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(slop_list_sriq_Premise, slop_option_list_sriq_Premise)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_LIST_TYPES_LIT_DEFINED
#define SLOP_OPTION_LIST_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(slop_list_types_Lit, slop_option_list_types_Lit)
#endif

#ifndef SLOP_OPTION_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(sriqctx_Edge, slop_option_sriqctx_Edge)
#endif

#ifndef SLOP_OPTION_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_OPTION_SRIQORDER_CONSTENTRY_DEFINED
SLOP_OPTION_DEFINE(sriqorder_ConstEntry, slop_option_sriqorder_ConstEntry)
#endif

#ifndef SLOP_OPTION_SRIQCTX_CTXSET_DEFINED
#define SLOP_OPTION_SRIQCTX_CTXSET_DEFINED
SLOP_OPTION_DEFINE(sriqctx_CtxSet, slop_option_sriqctx_CtxSet)
#endif

#ifndef SLOP_OPTION_SRIQ_CANDS_DEFINED
#define SLOP_OPTION_SRIQ_CANDS_DEFINED
SLOP_OPTION_DEFINE(sriq_Cands, slop_option_sriq_Cands)
#endif

#ifndef SLOP_OPTION_SRIQ_PCANDS_DEFINED
#define SLOP_OPTION_SRIQ_PCANDS_DEFINED
SLOP_OPTION_DEFINE(sriq_PCands, slop_option_sriq_PCands)
#endif

#ifndef SLOP_LIST_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_LIST_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_LIST_SRIQORDER_CONSTENTRY_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqorder_ConstEntry, slop_list_sriqorder_ConstEntry)
#endif

#ifndef SLOP_LIST_SRIQCTX_CTX_DEFINED
#define SLOP_LIST_SRIQCTX_CTX_DEFINED
#define SLOP_LIST_SRIQCTX_CTX_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqctx_Ctx, slop_list_sriqctx_Ctx)
#endif

#ifndef SLOP_LIST_SRIQCTX_CTXSET_DEFINED
#define SLOP_LIST_SRIQCTX_CTXSET_DEFINED
#define SLOP_LIST_SRIQCTX_CTXSET_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqctx_CtxSet, slop_list_sriqctx_CtxSet)
#endif

#ifndef SLOP_LIST_SRIQ_CANDS_DEFINED
#define SLOP_LIST_SRIQ_CANDS_DEFINED
#define SLOP_LIST_SRIQ_CANDS_IMPL_DEFINED
SLOP_LIST_DEFINE(sriq_Cands, slop_list_sriq_Cands)
#endif

#ifndef SLOP_LIST_SRIQ_PCANDS_DEFINED
#define SLOP_LIST_SRIQ_PCANDS_DEFINED
#define SLOP_LIST_SRIQ_PCANDS_IMPL_DEFINED
SLOP_LIST_DEFINE(sriq_PCands, slop_list_sriq_PCands)
#endif


#endif
