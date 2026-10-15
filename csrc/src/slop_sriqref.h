#ifndef SLOP_sriqref_H
#define SLOP_sriqref_H

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
#include "slop_sriqorder.h"
#include "slop_sriqsubsume.h"
#include "slop_sriqctx.h"
#include "slop_canon.h"
#include "slop_sriq.h"

typedef struct howl_sriqref_RefConfig howl_sriqref_RefConfig;
typedef struct howl_sriqref_Env howl_sriqref_Env;
typedef struct howl_sriqref_Cand howl_sriqref_Cand;
typedef struct howl_sriqref_SuccAct howl_sriqref_SuccAct;
typedef struct howl_sriqref_RSuccAct howl_sriqref_RSuccAct;
typedef struct howl_sriqref_NomAct howl_sriqref_NomAct;
typedef struct howl_sriqref_Out howl_sriqref_Out;
typedef struct howl_sriqref_Round howl_sriqref_Round;
typedef struct howl_sriqref_Dl4 howl_sriqref_Dl4;
typedef struct howl_sriqref_PJob howl_sriqref_PJob;
typedef struct howl_sriqref_Committing howl_sriqref_Committing;
typedef struct howl_sriqref_Grown howl_sriqref_Grown;
typedef struct howl_sriqref_RefIn howl_sriqref_RefIn;
typedef struct howl_sriqref_RefResult howl_sriqref_RefResult;

typedef enum {
    howl_sriqref_RefStatus_rs_fixpoint,
    howl_sriqref_RefStatus_rs_inconsistent,
    howl_sriqref_RefStatus_rs_fuel,
    howl_sriqref_RefStatus_rs_contexts,
    howl_sriqref_RefStatus_rs_clauses,
    howl_sriqref_RefStatus_rs_product,
    howl_sriqref_RefStatus_rs_constants
} howl_sriqref_RefStatus;

#ifndef SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_IMPL_DEFINED
SLOP_LIST_DEFINE(uint32_t, slop_list_u32)
#endif

#ifndef SLOP_LIST_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_LIST_HOWL_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_list_howl_sriq_Premise, slop_list_list_howl_sriq_Premise)
#endif

#ifndef SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_IMPL_DEFINED
SLOP_LIST_DEFINE(uint8_t, slop_list_u8)
#endif

#ifndef SLOP_LIST_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_LIST_HOWL_TYPES_LIT_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_list_howl_types_Lit, slop_list_list_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Clause, slop_list_howl_types_Clause)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_HOWL_TYPES_LIT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Lit, slop_list_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_LIST_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(slop_list_howl_types_Lit, slop_option_list_howl_types_Lit)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_PSLOT_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PSLOT_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PSLOT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_PSlot, slop_list_howl_sriq_PSlot)
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

#ifndef SLOP_LIST_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_EDGE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqctx_Edge, slop_list_howl_sriqctx_Edge)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PSLOT_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PSLOT_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_PSlot, slop_option_howl_sriq_PSlot)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_CTX_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_CTX_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Ctx, slop_option_howl_sriqctx_Ctx)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Premise, slop_option_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Edge, slop_option_howl_sriqctx_Edge)
#endif

struct howl_sriqref_RefConfig {
    howl_sriqctx_Strategy strat;
    int64_t fuel;
    int64_t lam;
    int64_t ctxs;
    int64_t cls;
    int64_t prod;
    int64_t cnst;
};
typedef struct howl_sriqref_RefConfig howl_sriqref_RefConfig;

#ifndef SLOP_OPTION_HOWL_SRIQREF_REFCONFIG_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_REFCONFIG_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_RefConfig, slop_option_howl_sriqref_RefConfig)
#endif

struct howl_sriqref_Env {
    slop_list_howl_types_Clause onto;
    howl_sriqctx_Triggers tr;
    howl_sriqctx_Strategy strat;
    int64_t lam;
    int64_t prod;
    int64_t nconst;
    slop_list_howl_types_Clause nobody;
    int64_t room;
};
typedef struct howl_sriqref_Env howl_sriqref_Env;

#ifndef SLOP_OPTION_HOWL_SRIQREF_ENV_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_ENV_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Env, slop_option_howl_sriqref_Env)
#endif

struct howl_sriqref_Cand {
    uint32_t ctx;
    howl_types_Clause c;
};
typedef struct howl_sriqref_Cand howl_sriqref_Cand;

#ifndef SLOP_OPTION_HOWL_SRIQREF_CAND_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_CAND_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Cand, slop_option_howl_sriqref_Cand)
#endif

#ifndef SLOP_LIST_HOWL_SRIQREF_CAND_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_CAND_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_CAND_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqref_Cand, slop_list_howl_sriqref_Cand)
#endif

struct howl_sriqref_SuccAct {
    uint32_t from;
    howl_sriq_SuccSig sg;
    slop_list_howl_types_Lit core;
    slop_list_howl_types_Lit adds;
};
typedef struct howl_sriqref_SuccAct howl_sriqref_SuccAct;

#ifndef SLOP_OPTION_HOWL_SRIQREF_SUCCACT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_SUCCACT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_SuccAct, slop_option_howl_sriqref_SuccAct)
#endif

#ifndef SLOP_LIST_HOWL_SRIQREF_SUCCACT_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_SUCCACT_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_SUCCACT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqref_SuccAct, slop_list_howl_sriqref_SuccAct)
#endif

struct howl_sriqref_RSuccAct {
    uint32_t from;
    uint32_t u;
    howl_types_Lit lit;
};
typedef struct howl_sriqref_RSuccAct howl_sriqref_RSuccAct;

#ifndef SLOP_OPTION_HOWL_SRIQREF_RSUCCACT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_RSUCCACT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_RSuccAct, slop_option_howl_sriqref_RSuccAct)
#endif

#ifndef SLOP_LIST_HOWL_SRIQREF_RSUCCACT_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_RSUCCACT_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_RSUCCACT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqref_RSuccAct, slop_list_howl_sriqref_RSuccAct)
#endif

struct howl_sriqref_NomAct {
    uint32_t o;
    uint32_t sb2;
    uint32_t i;
};
typedef struct howl_sriqref_NomAct howl_sriqref_NomAct;

#ifndef SLOP_OPTION_HOWL_SRIQREF_NOMACT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_NOMACT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_NomAct, slop_option_howl_sriqref_NomAct)
#endif

#ifndef SLOP_LIST_HOWL_SRIQREF_NOMACT_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_NOMACT_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_NOMACT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqref_NomAct, slop_list_howl_sriqref_NomAct)
#endif

struct howl_sriqref_Out {
    slop_list_howl_sriqref_Cand cands;
    uint8_t over;
};
typedef struct howl_sriqref_Out howl_sriqref_Out;

#ifndef SLOP_OPTION_HOWL_SRIQREF_OUT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_OUT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Out, slop_option_howl_sriqref_Out)
#endif

struct howl_sriqref_Round {
    slop_list_howl_sriqref_Cand cands;
    slop_list_howl_sriqref_SuccAct succs;
    slop_list_howl_sriqref_RSuccAct rsuccs;
    slop_list_howl_sriqref_NomAct noms;
    uint8_t over;
};
typedef struct howl_sriqref_Round howl_sriqref_Round;

#ifndef SLOP_OPTION_HOWL_SRIQREF_ROUND_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_ROUND_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Round, slop_option_howl_sriqref_Round)
#endif

struct howl_sriqref_Dl4 {
    uint8_t ok;
    uint32_t b1;
    uint32_t sb2;
    uint32_t n;
};
typedef struct howl_sriqref_Dl4 howl_sriqref_Dl4;

#ifndef SLOP_OPTION_HOWL_SRIQREF_DL4_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_DL4_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Dl4, slop_option_howl_sriqref_Dl4)
#endif

struct howl_sriqref_PJob {
    howl_sriq_PredView view;
    howl_sriq_CSub s;
    slop_list_howl_sriq_PSlot slots;
    uint32_t to;
    uint8_t rpred;
    uint8_t toroot;
};
typedef struct howl_sriqref_PJob howl_sriqref_PJob;

#ifndef SLOP_OPTION_HOWL_SRIQREF_PJOB_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_PJOB_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_PJob, slop_option_howl_sriqref_PJob)
#endif

struct howl_sriqref_Committing {
    howl_sriqctx_Structure st;
    uint8_t changed;
};
typedef struct howl_sriqref_Committing howl_sriqref_Committing;

#ifndef SLOP_OPTION_HOWL_SRIQREF_COMMITTING_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_COMMITTING_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Committing, slop_option_howl_sriqref_Committing)
#endif

struct howl_sriqref_Grown {
    slop_list_howl_types_Clause cs;
    uint8_t grew;
};
typedef struct howl_sriqref_Grown howl_sriqref_Grown;

#ifndef SLOP_OPTION_HOWL_SRIQREF_GROWN_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_GROWN_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Grown, slop_option_howl_sriqref_Grown)
#endif

struct howl_sriqref_RefIn {
    slop_list_howl_types_Clause onto;
    int64_t nclass;
    int64_t nquery;
    int64_t nrole;
    int64_t nfn;
    int64_t nconst;
    slop_list_u32 hidden;
};
typedef struct howl_sriqref_RefIn howl_sriqref_RefIn;

#ifndef SLOP_OPTION_HOWL_SRIQREF_REFIN_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_REFIN_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_RefIn, slop_option_howl_sriqref_RefIn)
#endif

struct howl_sriqref_RefResult {
    howl_sriqref_RefStatus status;
    int64_t rounds;
    howl_sriqctx_Structure st;
};
typedef struct howl_sriqref_RefResult howl_sriqref_RefResult;

#ifndef SLOP_OPTION_HOWL_SRIQREF_REFRESULT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_REFRESULT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_RefResult, slop_option_howl_sriqref_RefResult)
#endif

slop_list_howl_types_Clause howl_sriqref_set_of(howl_sriqref_Env env, howl_sriqctx_Structure st, int64_t v);
slop_option_howl_sriqctx_Ctx howl_sriqref_ctx_of(howl_sriqctx_Structure st, int64_t v);
uint8_t howl_sriqref_is_root(howl_sriqctx_Structure st, int64_t v);
slop_list_howl_types_Lit howl_sriqref_core_at(howl_sriqref_Env env, howl_sriqctx_Structure st, slop_arena* arena, int64_t v);
slop_list_howl_sriqref_Cand howl_sriqref_one_cand(slop_arena* arena, uint32_t v, howl_types_Clause c);
howl_sriqref_Out howl_sriqref_out_of(slop_list_howl_sriqref_Cand cands, uint8_t over);
slop_list_howl_sriq_Premise howl_sriqref_premises_of(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Clause cs);
int64_t howl_sriqref_consts_of(howl_sriqctx_Structure st);
slop_list_howl_sriqref_Cand howl_sriqref_conclusion(slop_arena* arena, uint32_t v, howl_sriq_RConcl r);
slop_list_howl_sriqref_Cand howl_sriqref_append_cands(slop_arena* arena, slop_list_howl_sriqref_Cand a, slop_list_howl_sriqref_Cand b);
howl_sriq_Premise howl_sriqref_prem_at(slop_list_howl_sriq_Premise ps, int64_t k, howl_sriq_Premise fallback);
int64_t howl_sriqref_product(slop_list_list_howl_sriq_Premise cs, int64_t cap);
slop_list_howl_sriqref_Cand howl_sriqref_ref_core(slop_arena* arena, uint32_t v, slop_list_howl_types_Lit core);
uint8_t howl_sriqref_x_fits(uint8_t root, howl_types_ATerm a, howl_types_ATerm t);
slop_list_howl_sriq_Premise howl_sriqref_slot_cands(slop_arena* arena, uint8_t root, howl_types_Lit a, slop_list_howl_sriq_Premise ps);
howl_sriq_HState howl_sriqref_hyper_choice(slop_arena* arena, howl_sriq_HState start, slop_list_howl_types_Lit atoms, slop_list_list_howl_sriq_Premise cs, int64_t t, howl_sriq_Premise fallback);
howl_sriqref_Out howl_sriqref_hyper_with(slop_arena* arena, howl_sriqref_Env env, uint32_t v, uint8_t root, howl_sriq_HState start, howl_types_Clause oc, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriqref_Cand howl_sriqref_hyper_choices(slop_arena* arena, uint32_t v, howl_sriq_HState start, howl_types_Clause oc, slop_list_list_howl_sriq_Premise cs, int64_t n, howl_sriq_Premise p0);
howl_sriqref_Cand howl_sriqref_copy_cand(slop_arena* arena, howl_sriqref_Cand c);
slop_list_howl_sriqref_Cand howl_sriqref_hyper_bodiless(slop_arena* arena, howl_sriqctx_Structure st, uint32_t v, uint8_t root, howl_types_Clause oc);
slop_list_howl_sriqref_Cand howl_sriqref_hyper_consts(slop_arena* arena, howl_sriqctx_Structure st, uint32_t v, howl_types_Clause oc);
howl_sriqref_Out howl_sriqref_ref_hyper(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, uint8_t root, slop_list_howl_sriq_Premise ps);
howl_sriqref_Out howl_sriqref_hyper_one(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, uint8_t root, howl_types_Clause oc, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriqref_Cand howl_sriqref_eq_positions(slop_arena* arena, howl_sriqorder_SriqOrder ord, uint32_t v, uint8_t root, howl_sriq_Premise p1, uint32_t k1, howl_sriq_Premise p2);
slop_list_howl_sriqref_Cand howl_sriqref_eq_at(slop_arena* arena, howl_sriqorder_SriqOrder ord, uint32_t v, uint8_t root, howl_sriq_Premise p1, uint32_t k1, howl_sriq_Premise p2, uint32_t a);
slop_list_u8 howl_sriqref_bools(slop_arena* arena);
slop_list_howl_sriqref_Cand howl_sriqref_ref_eq(slop_arena* arena, howl_sriqorder_SriqOrder ord, uint32_t v, uint8_t root, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriqref_Cand howl_sriqref_ref_ineq(slop_arena* arena, uint32_t v, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriqref_Cand howl_sriqref_factor_of(slop_arena* arena, howl_sriqorder_SriqOrder ord, uint32_t v, howl_sriq_Premise p);
slop_list_howl_sriqref_Cand howl_sriqref_ref_factor(slop_arena* arena, howl_sriqorder_SriqOrder ord, uint32_t v, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriqref_Cand howl_sriqref_join_into(slop_arena* arena, uint32_t v, howl_sriq_Premise p1, howl_types_Clause c2);
slop_list_howl_sriqref_Cand howl_sriqref_ref_join(slop_arena* arena, uint32_t v, slop_list_howl_sriq_Premise ps, slop_list_howl_types_Clause cs);
howl_sriqref_Dl4 howl_sriqref_dl4_of(howl_types_Clause oc);
uint8_t howl_sriqref_at_most_head(slop_list_howl_types_Lit head, int64_t m);
slop_option_u32 howl_sriqref_child_of(howl_sriqorder_SriqOrder ord, uint32_t o, uint32_t sb2, uint32_t i);
howl_sriqref_Round howl_sriqref_nom_pair(slop_arena* arena, howl_sriqref_Env env, howl_sriqorder_SriqOrder ord, uint32_t v, howl_sriqref_Dl4 d, howl_sriq_Premise p1, howl_sriq_Premise p2);
uint8_t howl_sriqref_nom_first(howl_sriq_Premise p, howl_sriqref_Dl4 d);
uint8_t howl_sriqref_nom_second(howl_sriq_Premise p, howl_sriqref_Dl4 d, uint32_t o);
howl_sriqref_Round howl_sriqref_nom_clause(slop_arena* arena, howl_sriqref_Env env, howl_sriqorder_SriqOrder ord, uint32_t v, howl_sriqref_Dl4 d, slop_list_howl_sriq_Premise ps);
howl_sriqref_Round howl_sriqref_ref_nom(slop_arena* arena, howl_sriqref_Env env, howl_sriqorder_SriqOrder ord, uint32_t v, slop_list_howl_sriq_Premise ps);
howl_sriqref_Round howl_sriqref_round_of(slop_list_howl_sriqref_Cand cands, slop_list_howl_sriqref_SuccAct succs, slop_list_howl_sriqref_RSuccAct rsuccs, slop_list_howl_sriqref_NomAct noms, uint8_t over);
uint8_t howl_sriqref_edge_is(howl_sriqctx_Edge e, uint32_t from, uint32_t to, howl_sriqctx_EdgeLabel lk, uint32_t label);
uint8_t howl_sriqref_has_edge(howl_sriqctx_Structure st, uint32_t from, uint32_t to, howl_sriqctx_EdgeLabel lk, uint32_t label);
uint8_t howl_sriqref_covered(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, uint32_t f, slop_list_howl_types_Lit k2);
slop_list_howl_sriqref_SuccAct howl_sriqref_succ_of(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, uint8_t root, slop_list_howl_types_Clause cs, howl_sriq_Premise p);
slop_list_howl_sriqref_SuccAct howl_sriqref_succ_with(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, slop_list_howl_types_Clause cs, howl_sriq_Premise p, howl_sriq_SuccSig sg);
slop_list_howl_sriqref_SuccAct howl_sriqref_ref_succ(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, uint8_t root, slop_list_howl_types_Clause cs, slop_list_howl_sriq_Premise ps);
slop_list_u32 howl_sriqref_lit_consts(slop_arena* arena, howl_types_Lit l);
slop_list_howl_sriqref_RSuccAct howl_sriqref_ref_rsucc(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriqref_RSuccAct howl_sriqref_rsucc_of(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, slop_list_howl_types_Clause root_set, howl_sriq_Premise p);
slop_list_howl_sriq_Premise howl_sriqref_pslot_cands(slop_arena* arena, howl_sriq_CSub s, howl_sriq_PSlot slot, slop_list_howl_sriq_Premise ps);
howl_sriq_PState howl_sriqref_pred_choice(slop_arena* arena, howl_sriq_PState start, howl_sriq_CSub s, slop_list_howl_sriq_PSlot slots, slop_list_list_howl_sriq_Premise cs, int64_t t, howl_sriq_Premise fallback);
howl_sriqref_Out howl_sriqref_pred_run(slop_arena* arena, howl_sriqref_Env env, howl_sriqref_PJob job, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriqref_Cand howl_sriqref_pred_one(slop_arena* arena, howl_sriqref_Env env, howl_sriqref_PJob job, slop_list_list_howl_sriq_Premise cs, int64_t t, slop_list_howl_sriq_Premise ps);
howl_sriq_Premise howl_sriqref_prem_or(slop_list_howl_sriq_Premise ps, howl_sriq_PredView v);
slop_list_howl_sriq_PSlot howl_sriqref_slots_of(slop_arena* arena, slop_list_howl_types_Lit lits);
howl_sriqref_Out howl_sriqref_pred_edge(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, howl_sriqctx_Edge e, slop_list_howl_types_Clause cs);
howl_sriqref_Out howl_sriqref_pred_clause(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqctx_Edge e, uint32_t w, uint8_t toroot, slop_list_howl_types_Lit core, slop_list_howl_sriq_Premise ws, howl_types_Clause c);
howl_sriqref_PJob howl_sriqref_away_job(howl_sriq_PredView view, slop_list_howl_sriq_PSlot slots, uint32_t f, uint32_t w);
howl_sriqref_Out howl_sriqref_pred_root(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriq_PredView view, slop_list_howl_sriq_PSlot slots, uint32_t w, uint32_t f, slop_list_howl_sriq_Premise ws);
howl_sriqref_PJob howl_sriqref_root_job(howl_sriq_PredView view, slop_list_howl_sriq_PSlot slots, uint32_t w, uint32_t f, uint32_t u);
howl_sriq_SuccSig howl_sriqref_sig_away(uint32_t f);
howl_sriq_SuccSig howl_sriqref_sig_at(uint32_t f, uint32_t u);
howl_sriqref_Out howl_sriqref_ref_pred(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, slop_list_howl_types_Clause cs);
uint32_t howl_sriqref_slot_const(howl_types_Lit l);
slop_list_howl_sriq_PSlot howl_sriqref_rslots(slop_arena* arena, howl_sriqctx_Structure st, uint32_t v, slop_list_howl_types_Lit lits);
howl_sriqref_Out howl_sriqref_ref_rpred(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, slop_list_howl_sriq_Premise ps);
howl_sriqref_PJob howl_sriqref_rpred_job(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, howl_types_Clause c);
howl_sriqref_Out howl_sriqref_ctx_table2(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, uint8_t root, slop_list_howl_types_Clause cs, slop_list_howl_sriq_Premise ps);
howl_sriqref_Round howl_sriqref_ctx_round(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v);
howl_sriqref_Round howl_sriqref_ctx_round_rest(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, uint8_t root, slop_list_howl_types_Clause cs, slop_list_howl_sriq_Premise ps, howl_sriqref_Out t2);
howl_sriqref_Round howl_sriqref_ref_round(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st);
int64_t howl_sriqref_nom_cmp(howl_sriqref_NomAct a, howl_sriqref_NomAct b);
howl_sriqref_NomAct howl_sriqref_nom_at(slop_list_howl_sriqref_NomAct xs, int64_t k, howl_sriqref_NomAct fallback);
howl_sriqorder_SriqOrder howl_sriqref_add_consts(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_sriqref_NomAct noms);
howl_sriqorder_SriqOrder howl_sriqref_with_child(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriqref_NomAct a);
howl_sriqorder_SriqOrder howl_sriqref_push_const(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriqorder_ConstEntry e);
int64_t howl_sriqref_lits_cmp(slop_list_howl_types_Lit a, slop_list_howl_types_Lit b);
uint8_t howl_sriqref_core_in(slop_list_list_howl_types_Lit cores, slop_list_howl_types_Lit c);
slop_list_howl_types_Lit howl_sriqref_core_at_k(slop_list_list_howl_types_Lit xs, int64_t k, slop_list_howl_types_Lit fallback);
howl_sriqctx_Structure howl_sriqref_add_contexts(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqref_SuccAct succs);
howl_sriqctx_Structure howl_sriqref_with_contexts(slop_arena* arena, howl_sriqctx_Structure st, slop_list_list_howl_types_Lit fresh, slop_list_howl_types_Lit f0);
howl_sriqctx_Structure howl_sriqref_add_edges(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqref_SuccAct succs, slop_list_howl_sriqref_RSuccAct rsuccs);
slop_list_howl_sriqctx_Edge howl_sriqref_succ_edges(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqctx_Edge es, howl_sriqref_SuccAct a);
slop_list_howl_sriqctx_Edge howl_sriqref_with_edge(slop_arena* arena, slop_list_howl_sriqctx_Edge es, howl_sriqctx_Edge e);
howl_types_Clause howl_sriqref_unit_clause(slop_arena* arena, howl_types_Lit a);
slop_list_howl_sriqref_Cand howl_sriqref_action_cands(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqref_SuccAct succs, slop_list_howl_sriqref_RSuccAct rsuccs);
howl_sriqref_Cand howl_sriqref_cand_at(slop_list_howl_sriqref_Cand xs, int64_t k, howl_sriqref_Cand fallback);
int64_t howl_sriqref_cand_cmp(howl_sriqref_Cand a, howl_sriqref_Cand b);
howl_sriqref_Committing howl_sriqref_commit_sets(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqref_Cand cands);
howl_sriqref_Committing howl_sriqref_commit_sorted(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqref_Cand cands, howl_sriqref_Cand c0);
howl_sriqref_Grown howl_sriqref_grow(slop_arena* arena, slop_list_howl_types_Clause cs, slop_list_howl_sriqref_Cand cands, slop_list_int idx, uint32_t v, howl_sriqref_Cand c0);
howl_sriqref_Committing howl_sriqref_ref_apply(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqref_Round r);
int64_t howl_sriqref_total_clauses(howl_sriqctx_Structure st);
uint8_t howl_sriqref_inconsistent_now(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st);
howl_sriqctx_Structure howl_sriqref_ref_elim(slop_arena* arena, howl_sriqctx_Structure st);
int64_t howl_sriqref_initial_queries(howl_sriqref_RefIn in);
howl_sriqctx_Structure howl_sriqref_init_of(slop_arena* arena, howl_sriqref_RefIn in);
int64_t howl_sriqref_ref_lambda(howl_sriqctx_Triggers tr, howl_sriqctx_Strategy s, int64_t nquery);
howl_sriqref_RefIn howl_sriqref_ref_input(slop_arena* arena, howl_sriqclauses_SriqClauses sc);
howl_sriqref_RefResult howl_sriqref_ref_run(slop_arena* arena, howl_sriqref_RefIn in, howl_sriqref_RefConfig cfg);
slop_list_howl_types_Lit howl_sriqref_copy_lits(slop_arena* arena, slop_list_howl_types_Lit ls);
slop_list_howl_types_Clause howl_sriqref_copy_clauses(slop_arena* arena, slop_list_howl_types_Clause cs);
howl_sriqctx_Structure howl_sriqref_copy_structure(slop_arena* arena, howl_sriqctx_Structure st);
howl_sriqref_Env howl_sriqref_env_of(slop_arena* arena, howl_sriqref_RefIn in, howl_sriqref_RefConfig cfg, howl_sriqctx_Triggers tr, int64_t lam);
howl_sriqref_Env howl_sriqref_with_room(howl_sriqref_Env env, int64_t room);
howl_sriqref_Env howl_sriqref_env_for(slop_arena* arena, howl_sriqref_RefIn in, howl_sriqref_RefConfig cfg);
uint8_t howl_sriqref_ref_stable(slop_arena* arena, howl_sriqref_RefIn in, howl_sriqref_RefConfig cfg, howl_sriqctx_Structure st);
howl_sriqref_RefStatus howl_sriqref_stop_status(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqref_Committing cm, howl_sriqref_RefConfig cfg);
slop_list_howl_types_Clause howl_sriqref_ref_set(slop_arena* arena, howl_sriqctx_Structure st, int64_t v);
uint8_t howl_sriqref_clause_in(slop_list_howl_types_Clause xs, howl_types_Clause c);
uint8_t howl_sriqref_same_clauses(slop_list_howl_types_Clause a, slop_list_howl_types_Clause b);
slop_list_howl_types_Clause howl_sriqref_cand_clauses(slop_arena* arena, slop_list_howl_sriqref_Cand cs);
uint8_t howl_sriqref_hyper_agrees(slop_arena* arena, howl_sriqref_Env env, uint32_t v, uint8_t root, howl_types_Clause oc, slop_list_howl_sriq_Premise ps);
uint8_t howl_sriqref_pred_agrees(slop_arena* arena, howl_sriqref_Env env, howl_sriqref_PJob job, slop_list_howl_sriq_Premise ps);
uint8_t howl_sriqref_ctx_agrees(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v);
uint8_t howl_sriqref_edge_agrees(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, howl_sriqctx_Edge e, slop_list_howl_types_Clause cs);
uint8_t howl_sriqref_combinators_agree(slop_arena* arena, howl_sriqref_RefIn in, howl_sriqref_RefConfig cfg, howl_sriqctx_Structure st);

#ifndef SLOP_OPTION_HOWL_SRIQREF_REFCONFIG_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_REFCONFIG_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_RefConfig, slop_option_howl_sriqref_RefConfig)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_ENV_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_ENV_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Env, slop_option_howl_sriqref_Env)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_CAND_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_CAND_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Cand, slop_option_howl_sriqref_Cand)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_SUCCACT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_SUCCACT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_SuccAct, slop_option_howl_sriqref_SuccAct)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_RSUCCACT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_RSUCCACT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_RSuccAct, slop_option_howl_sriqref_RSuccAct)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_NOMACT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_NOMACT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_NomAct, slop_option_howl_sriqref_NomAct)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_OUT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_OUT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Out, slop_option_howl_sriqref_Out)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_ROUND_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_ROUND_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Round, slop_option_howl_sriqref_Round)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_DL4_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_DL4_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Dl4, slop_option_howl_sriqref_Dl4)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PSLOT_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PSLOT_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_PSlot, slop_option_howl_sriq_PSlot)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_PJOB_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_PJOB_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_PJob, slop_option_howl_sriqref_PJob)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_COMMITTING_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_COMMITTING_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Committing, slop_option_howl_sriqref_Committing)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_GROWN_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_GROWN_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Grown, slop_option_howl_sriqref_Grown)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_REFIN_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_REFIN_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_RefIn, slop_option_howl_sriqref_RefIn)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_REFRESULT_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_REFRESULT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_RefResult, slop_option_howl_sriqref_RefResult)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_CTX_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_CTX_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Ctx, slop_option_howl_sriqctx_Ctx)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Premise, slop_option_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_LIST_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(slop_list_howl_sriq_Premise, slop_option_list_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_LIST_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(slop_list_howl_types_Lit, slop_option_list_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Edge, slop_option_howl_sriqctx_Edge)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_OPTION_HOWL_SRIQORDER_CONSTENTRY_DEFINED
SLOP_OPTION_DEFINE(howl_sriqorder_ConstEntry, slop_option_howl_sriqorder_ConstEntry)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_CTXSET_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_CTXSET_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_CtxSet, slop_option_howl_sriqctx_CtxSet)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_CANDS_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_CANDS_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Cands, slop_option_howl_sriq_Cands)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PCANDS_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PCANDS_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_PCands, slop_option_howl_sriq_PCands)
#endif

#ifndef SLOP_LIST_HOWL_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_LIST_HOWL_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_LIST_HOWL_SRIQORDER_CONSTENTRY_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqorder_ConstEntry, slop_list_howl_sriqorder_ConstEntry)
#endif

#ifndef SLOP_LIST_HOWL_SRIQCTX_CTX_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_CTX_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_CTX_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqctx_Ctx, slop_list_howl_sriqctx_Ctx)
#endif

#ifndef SLOP_LIST_HOWL_SRIQCTX_CTXSET_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_CTXSET_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_CTXSET_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqctx_CtxSet, slop_list_howl_sriqctx_CtxSet)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_CANDS_DEFINED
#define SLOP_LIST_HOWL_SRIQ_CANDS_DEFINED
#define SLOP_LIST_HOWL_SRIQ_CANDS_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_Cands, slop_list_howl_sriq_Cands)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_PCANDS_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PCANDS_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PCANDS_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_PCands, slop_list_howl_sriq_PCands)
#endif


#endif
