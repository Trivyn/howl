#include "../runtime/slop_runtime.h"
#include "slop_sriqsat.h"

#define howl_sriqsat_ROOM_OFF (2147483647)

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

typedef struct { slop_list_howl_sriqsat_JoinSite raw; howl_sriqsat_JoinSite s0; } howl_sriqsat__lambda_1356_env_t;

static int64_t howl_sriqsat__lambda_1356(howl_sriqsat__lambda_1356_env_t* _env, int64_t a, int64_t b) { return howl_types_lit_cmp(howl_sriqsat_site_key(howl_sriqsat_site_at(_env->raw, a, _env->s0)), howl_sriqsat_site_key(howl_sriqsat_site_at(_env->raw, b, _env->s0))); }

typedef struct { slop_list_howl_sriqsat_Trig raw; howl_sriqsat_Trig t0; } howl_sriqsat__lambda_1365_env_t;

static int64_t howl_sriqsat__lambda_1365(howl_sriqsat__lambda_1365_env_t* _env, int64_t a, int64_t b) { return howl_sriqsat_sg_cmp(howl_sriqsat_trig_at(_env->raw, a, _env->t0).sg, howl_sriqsat_trig_at(_env->raw, b, _env->t0).sg); }

typedef struct { slop_list_howl_sriqctx_Edge es; howl_sriqctx_Edge e0; } howl_sriqsat__lambda_1368_env_t;

static int64_t howl_sriqsat__lambda_1368(howl_sriqsat__lambda_1368_env_t* _env, int64_t i, int64_t j) { return howl_sriqsat_u32_cmp(howl_sriqsat_edge_at(_env->es, i, _env->e0).to, howl_sriqsat_edge_at(_env->es, j, _env->e0).to); }

typedef struct { slop_list_howl_sriqctx_Edge es; howl_sriqctx_Edge e0; } howl_sriqsat__lambda_1369_env_t;

static int64_t howl_sriqsat__lambda_1369(howl_sriqsat__lambda_1369_env_t* _env, int64_t i, int64_t j) { return howl_sriqsat_u32_cmp(howl_sriqsat_edge_at(_env->es, i, _env->e0).from, howl_sriqsat_edge_at(_env->es, j, _env->e0).from); }

typedef struct { slop_list_howl_sriqctx_Edge old; howl_sriqctx_Edge e0; } howl_sriqsat__lambda_1374_env_t;

static int64_t howl_sriqsat__lambda_1374(howl_sriqsat__lambda_1374_env_t* _env, int64_t i, int64_t j) { return howl_sriqsat_edge_cmp(howl_sriqsat_edge_at(_env->old, i, _env->e0), howl_sriqsat_edge_at(_env->old, j, _env->e0)); }

typedef struct { slop_list_howl_sriqctx_Edge news; howl_sriqctx_Edge e0; } howl_sriqsat__lambda_1375_env_t;

static int64_t howl_sriqsat__lambda_1375(howl_sriqsat__lambda_1375_env_t* _env, int64_t i, int64_t j) { return howl_sriqsat_edge_cmp(howl_sriqsat_edge_at(_env->news, i, _env->e0), howl_sriqsat_edge_at(_env->news, j, _env->e0)); }

typedef struct { slop_list_int keep; } howl_sriqsat__lambda_1376_env_t;

static int64_t howl_sriqsat__lambda_1376(howl_sriqsat__lambda_1376_env_t* _env, int64_t i, int64_t j) { return howl_sriqsat_int_cmp(howl_sriqsat_idx_at(_env->keep, i), howl_sriqsat_idx_at(_env->keep, j)); }

typedef struct { slop_list_howl_sriqref_Cand cands; howl_sriqref_Cand none_such; } howl_sriqsat__lambda_1378_env_t;

static int64_t howl_sriqsat__lambda_1378(howl_sriqsat__lambda_1378_env_t* _env, int64_t i, int64_t j) { return howl_sriqref_cand_cmp(howl_sriqref_cand_at(_env->cands, i, _env->none_such), howl_sriqref_cand_at(_env->cands, j, _env->none_such)); }

typedef struct { slop_list_howl_sriqsat_Supply raw; howl_sriqsat_Supply s0; } howl_sriqsat__lambda_1394_env_t;

static int64_t howl_sriqsat__lambda_1394(howl_sriqsat__lambda_1394_env_t* _env, int64_t i, int64_t j) { return howl_sriqsat_supply_cmp(howl_sriqsat_supply_at(_env->raw, i, _env->s0), howl_sriqsat_supply_at(_env->raw, j, _env->s0)); }

typedef struct { slop_list_howl_types_Clause raw; howl_types_Clause c0; } howl_sriqsat__lambda_1405_env_t;

static int64_t howl_sriqsat__lambda_1405(howl_sriqsat__lambda_1405_env_t* _env, int64_t a, int64_t b) { return howl_sriqclauses_clause_cmp(howl_sriqsat_clause_of_l(_env->raw, a, _env->c0), howl_sriqsat_clause_of_l(_env->raw, b, _env->c0)); }

slop_list_howl_types_Clause howl_sriqsat_cs_at(slop_list_howl_sriqctx_CtxSet xs, int64_t v, slop_list_howl_types_Clause nobody) {
    __auto_type _mv_1350 = ({ __auto_type _lst = xs; size_t _idx = (size_t)v; slop_option_howl_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1350.has_value) {
        __auto_type s = _mv_1350.value;
        return s.cs;
    } else if (!_mv_1350.has_value) {
        return nobody;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Clause howl_sriqsat_permuted(slop_arena* arena, slop_list_howl_types_Clause xs, int64_t perm) {
    {
        __auto_type n = ((int64_t)(((int64_t)((xs).len))));
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < n) {
            {
                __auto_type k = ((perm == 1) ? ((n - 1) - i) : ((perm == 2) ? ((i + (n / 2)) % n) : i));
                __auto_type _mv_1351 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1351.has_value) {
                    __auto_type c = _mv_1351.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1351.has_value) {
                }
                i = (i + 1);
            }
        }
        return out;
    }
}

slop_list_int howl_sriqsat_ctx_order(slop_arena* arena, int64_t n, int64_t perm) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < n) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((perm == 1) ? ((n - 1) - i) : ((perm == 2) ? ((i + (n / 2)) % n) : i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            i = (i + 1);
        }
        return out;
    }
}

howl_sriqsat_CIdx howl_sriqsat_ctx_ix(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, int64_t v, int64_t perm, slop_list_howl_sriqsat_View vw) {
    {
        __auto_type all = howl_sriqref_set_of(env, st, v);
        __auto_type fresh = (v >= dl.nctx);
        __auto_type news = howl_sriqsat_permuted(arena, ((fresh) ? all : howl_sriqsat_cs_at(dl.news, v, env.nobody)), perm);
        __auto_type olds = ((fresh) ? env.nobody : howl_sriqsat_cs_at(dl.olds, v, env.nobody));
        __auto_type aps = howl_sriqsat_premises_in(arena, st, vw, v, all);
        __auto_type dps = howl_sriqsat_premises_in(arena, st, vw, v, news);
        __auto_type ops = howl_sriqsat_premises_in(arena, st, vw, v, olds);
        return ((howl_sriqsat_CIdx){.aps = aps, .dps = dps, .ops = ops, .aix = howl_sriqground_pidx_of(arena, aps), .dix = howl_sriqground_pidx_of(arena, dps), .oix = howl_sriqground_pidx_of(arena, ops)});
    }
}

slop_list_howl_sriqsat_CIdx howl_sriqsat_all_ixs(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, int64_t perm, slop_list_howl_sriqsat_View vw) {
    {
        __auto_type out = ((slop_list_howl_sriqsat_CIdx){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        {
            __auto_type _coll = st.ctxs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqsat_ctx_ix(arena, env, st, dl, v, perm, vw)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                v = (v + 1);
            }
        }
        return out;
    }
}

howl_sriqsat_CIdx howl_sriqsat_cix_at(slop_arena* arena, slop_list_howl_sriqsat_CIdx ixs, int64_t v) {
    __auto_type _mv_1352 = ({ __auto_type _lst = ixs; size_t _idx = (size_t)v; slop_option_howl_sriqsat_CIdx _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1352.has_value) {
        __auto_type x = _mv_1352.value;
        return x;
    } else if (!_mv_1352.has_value) {
        {
            __auto_type e = ((slop_list_howl_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            return ((howl_sriqsat_CIdx){.aps = e, .dps = e, .ops = e, .aix = howl_sriqground_pidx_of(arena, e), .dix = howl_sriqground_pidx_of(arena, e), .oix = howl_sriqground_pidx_of(arena, e)});
        }
    }
    SLOP_UNREACHABLE();
}

howl_sriqsat_Here howl_sriqsat_here_of(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqground_Ground gd, howl_sriqhyper_HIdx hx, slop_list_howl_sriqsat_CIdx ixs, howl_sriqsat_RSrcs rs, int64_t v, int64_t perm, uint8_t dfr, uint8_t views) {
    {
        __auto_type all = howl_sriqref_set_of(env, st, v);
        __auto_type fresh = (v >= dl.nctx);
        __auto_type news = howl_sriqsat_permuted(arena, ((fresh) ? all : howl_sriqsat_cs_at(dl.news, v, env.nobody)), perm);
        __auto_type olds = ((fresh) ? env.nobody : howl_sriqsat_cs_at(dl.olds, v, env.nobody));
        __auto_type x = howl_sriqsat_cix_at(arena, ixs, v);
        return ((howl_sriqsat_Here){.v = ((uint32_t)(v)), .root = howl_sriqref_is_root(st, v), .fresh = fresh, .all = all, .news = news, .olds = olds, .aps = x.aps, .dps = x.dps, .ops = x.ops, .dix = x.dix, .aix = x.aix, .oix = x.oix, .hx = hx, .ixs = ixs, .gd = gd, .rs = rs, .dfr = dfr, .views = views, .room = howl_sriqsat_ROOM_OFF});
    }
}

howl_sriqsat_Here howl_sriqsat_here_room(howl_sriqsat_Here h, int64_t room) {
    return ((howl_sriqsat_Here){.v = h.v, .root = h.root, .fresh = h.fresh, .all = h.all, .news = h.news, .olds = h.olds, .aps = h.aps, .dps = h.dps, .ops = h.ops, .dix = h.dix, .aix = h.aix, .oix = h.oix, .hx = h.hx, .ixs = h.ixs, .gd = h.gd, .rs = h.rs, .dfr = h.dfr, .views = h.views, .room = room});
}

uint8_t howl_sriqsat_roomy(slop_list_howl_sriqref_Cand out, howl_sriqsat_Here h) {
    return (((int64_t)(((int64_t)((out).len)))) <= h.room);
}

uint8_t howl_sriqsat_edge_new(howl_sriqsat_Delta dl, howl_sriqctx_Edge e) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = dl.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (howl_sriqref_edge_is(x, e.from, e.to, e.lk, e.label)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t howl_sriqsat_consts_new(howl_sriqctx_Structure st, howl_sriqsat_Delta dl) {
    return (howl_sriqref_consts_of(st) > dl.ncst);
}

slop_list_howl_sriqref_Cand howl_sriqsat_hyper_new_consts(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, uint32_t v, howl_types_Clause oc) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t u = dl.ncst;
        while (u < howl_sriqref_consts_of(st)) {
            {
                __auto_type _coll = howl_sriqref_conclusion(arena, v, howl_sriq_hyper_finish(arena, howl_sriq_hyper_start(arena, howl_types_at_u(((uint32_t)(u))), 1), oc.head));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
            u = (u + 1);
        }
        return out;
    }
}

slop_list_howl_sriqref_Cand howl_sriqsat_hyper_bodiless(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqsat_Here h, howl_types_Clause oc) {
    if (h.root) {
        return howl_sriqsat_hyper_new_consts(arena, st, dl, h.v, oc);
    } else if (h.fresh && !(howl_sriqsat_dl10(oc))) {
        return howl_sriqref_conclusion(arena, h.v, howl_sriq_hyper_finish(arena, howl_sriq_hyper_start(arena, howl_types_at_x(), 1), oc.head));
    } else {
        return ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
}

uint8_t howl_sriqsat_dl10(howl_types_Clause oc) {
    return (((((int64_t)((oc.body).len)) == 0)) && ((((int64_t)((oc.head).len)) > 0)) && (howl_sriqground_ground_clause(oc)));
}

howl_sriqhyper_HCtx howl_sriqsat_hctx_of(howl_sriqsat_Here h) {
    return ((howl_sriqhyper_HCtx){.v = h.v, .root = h.root, .dps = h.dps, .aps = h.aps, .dix = h.dix, .oix = h.oix, .aix = h.aix});
}

howl_sriqhyper_HOut howl_sriqsat_sat_hyper(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqsat_Here h, int64_t room) {
    {
        __auto_type hy = howl_sriqhyper_hyper_indexed(arena, env, h.hx, howl_sriqsat_hctx_of(h), room);
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = h.hx.bodiless;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type oc = _coll.data[_i];
                if ((((int64_t)((out).len)) + ((int64_t)((hy.out.cands).len))) <= room) {
                    {
                        __auto_type _coll = howl_sriqsat_hyper_bodiless(arena, st, dl, h, oc);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        {
            __auto_type _coll = hy.out.cands;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ((howl_sriqhyper_HOut){.out = howl_sriqref_out_of(out, hy.out.over), .tried = hy.tried});
    }
}

slop_list_howl_sriqref_Cand howl_sriqsat_eq_pairs(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqsat_Here h, slop_list_howl_sriq_Premise p1s, slop_list_howl_sriq_Premise p2s) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = p1s;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p1 = _coll.data[_i];
                if ((howl_sriqsat_roomy(out, h)) && (p1.maxed) && ((p1.sel.form == howl_types_LitForm_lf_eq))) {
                    {
                        __auto_type _coll = p2s;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type p2 = _coll.data[_i];
                            if (p2.maxed) {
                                {
                                    __auto_type _coll = howl_sriqsat_eq_side(arena, st, h, p1, ((uint32_t)(1)), p2);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type c = _coll.data[_i];
                                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                    }
                                }
                                {
                                    __auto_type _coll = howl_sriqsat_eq_side(arena, st, h, p1, ((uint32_t)(2)), p2);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type c = _coll.data[_i];
                                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_sriqref_Cand howl_sriqsat_eq_side(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqsat_Here h, howl_sriq_Premise p1, uint32_t k1, howl_sriq_Premise p2) {
    if (howl_sriqsat_holds_term(p2.sel, (((k1 == ((uint32_t)(1)))) ? p1.sel.t1 : p1.sel.t2))) {
        {
            __auto_type tmp = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(65536); _new_arena; });
            __auto_type out = howl_sriqsat_copy_cands(arena, howl_sriqref_eq_positions(tmp, st.ord, h.v, h.root, p1, k1, p2));
            (void)(({ slop_arena_free(tmp); free(tmp); }));
            return out;
        }
    } else {
        return ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
}

slop_list_howl_sriqref_Cand howl_sriqsat_join_kept(slop_arena* arena, uint32_t v, howl_sriq_Premise p1, howl_types_Clause c, int64_t j) {
    {
        __auto_type tmp = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16384); _new_arena; });
        __auto_type out = howl_sriqsat_copy_cands(arena, howl_sriqref_conclusion(tmp, v, howl_sriq_join_rule(tmp, p1, howl_sriq_body_at(tmp, c, j))));
        (void)(({ slop_arena_free(tmp); free(tmp); }));
        return out;
    }
}

slop_list_howl_sriqref_Cand howl_sriqsat_copy_cands(slop_arena* arena, slop_list_howl_sriqref_Cand cs) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqref_copy_cand(arena, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

uint8_t howl_sriqsat_holds_term(howl_types_Lit l, howl_types_ATerm s) {
    return ((howl_sriqsat_term_at(l, ((uint32_t)(1)), 0, s)) || (howl_sriqsat_term_at(l, ((uint32_t)(1)), 1, s)) || (howl_sriqsat_term_at(l, ((uint32_t)(2)), 0, s)) || (howl_sriqsat_term_at(l, ((uint32_t)(2)), 1, s)));
}

uint8_t howl_sriqsat_term_at(howl_types_Lit l, uint32_t a, uint8_t inner, howl_types_ATerm s) {
    __auto_type _mv_1353 = howl_sriq_subterm_at(l, ((howl_sriq_Pos){.arg = a, .inner = inner}));
    if (_mv_1353.has_value) {
        __auto_type t = _mv_1353.value;
        return howl_types_aterm_eq(t, s);
    } else if (!_mv_1353.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

howl_sriqhyper_HOut howl_sriqsat_sat_table2(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqsat_Here h, int64_t room) {
    {
        __auto_type hy = howl_sriqsat_sat_hyper(arena, env, st, dl, h, room);
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (h.fresh) {
            {
                __auto_type _coll = howl_sriqref_ref_core(arena, h.v, howl_sriqref_core_at(env, st, arena, ((int64_t)(h.v))));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        if (!(h.root) && howl_sriqsat_within(out, hy.out.cands, room)) {
            {
                __auto_type _coll = howl_sriqsat_eq_ground(arena, st, h);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
            if (howl_sriqsat_within(out, hy.out.cands, room)) {
                {
                    __auto_type _coll = howl_sriqsat_join_ground(arena, h);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        {
            __auto_type _coll = hy.out.cands;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        if (((int64_t)(((int64_t)((out).len)))) <= room) {
            out = howl_sriqsat_t2_rest(arena, st, h, out, room);
        }
        return ((howl_sriqhyper_HOut){.out = howl_sriqref_out_of(out, hy.out.over), .tried = hy.tried});
    }
}

uint8_t howl_sriqsat_within(slop_list_howl_sriqref_Cand a, slop_list_howl_sriqref_Cand b, int64_t room) {
    return ((((int64_t)(((int64_t)((a).len)))) + ((int64_t)(((int64_t)((b).len))))) <= room);
}

slop_list_howl_sriqref_Cand howl_sriqsat_t2_rest(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqsat_Here h, slop_list_howl_sriqref_Cand sofar, int64_t room) {
    {
        __auto_type out = sofar;
        {
            __auto_type _coll = howl_sriqsat_eq_pairs(arena, st, h, h.dps, h.aps);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        if (((int64_t)(((int64_t)((out).len)))) <= room) {
            {
                __auto_type _coll = howl_sriqsat_eq_pairs(arena, st, h, h.ops, h.dps);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        if (((int64_t)(((int64_t)((out).len)))) <= room) {
            {
                __auto_type _coll = howl_sriqref_ref_ineq(arena, h.v, h.dps);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        if (((int64_t)(((int64_t)((out).len)))) <= room) {
            {
                __auto_type _coll = howl_sriqref_ref_factor(arena, st.ord, h.v, h.dps);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        if (((int64_t)(((int64_t)((out).len)))) <= room) {
            {
                __auto_type _coll = howl_sriqsat_sat_join(arena, h.v, h.dps, howl_sriqsat_join_sites(arena, h.all), room);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        if (((int64_t)(((int64_t)((out).len)))) <= room) {
            {
                __auto_type _coll = howl_sriqsat_sat_join(arena, h.v, h.ops, howl_sriqsat_join_sites(arena, h.news), room);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

uint8_t howl_sriqsat_g_counts(howl_sriqsat_Here h, int64_t i, int64_t which) {
    {
        __auto_type new = (!(h.fresh) && howl_sriqground_g_fresh(h.gd, i));
        return (howl_sriqground_g_visible(h.gd, ((int64_t)(h.v)), i) && ((which == 1) ? new : ((which == 2) ? !(new) : 1)));
    }
}

uint8_t howl_sriqsat_g_picks(howl_sriqsat_Here h, int64_t k, int64_t which) {
    return howl_sriqsat_g_counts(h, howl_sriqground_g_member_of(h.gd, k), which);
}

slop_list_howl_sriq_Premise howl_sriqsat_g_prems(slop_arena* arena, howl_sriqsat_Here h, int64_t which, uint8_t eqs) {
    {
        __auto_type out = ((slop_list_howl_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = h.gd.ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if ((p.maxed) && ((!(eqs) || (p.sel.form == howl_types_LitForm_lf_eq))) && (howl_sriqsat_g_picks(h, k, which))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                k = (k + 1);
            }
        }
        return out;
    }
}

slop_list_howl_sriqref_Cand howl_sriqsat_join_into_g(slop_arena* arena, howl_sriqsat_Here h, slop_list_howl_sriq_Premise p1s, int64_t which) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = p1s;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p1 = _coll.data[_i];
                if ((howl_sriqsat_roomy(out, h)) && (p1.maxed) && (howl_sriq_joinable(p1.sel))) {
                    {
                        __auto_type _coll = howl_sriqground_g_body_members(arena, h.gd, p1.sel);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type i = _coll.data[_i];
                            if (howl_sriqsat_roomy(out, h) && howl_sriqsat_g_counts(h, i, which)) {
                                {
                                    __auto_type _coll = howl_sriqsat_join_into_member(arena, h, p1, howl_sriqground_g_member(h.gd, i, howl_sriqsat_empty_clause(arena)));
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type c = _coll.data[_i];
                                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_sriqref_Cand howl_sriqsat_join_into_member(slop_arena* arena, howl_sriqsat_Here h, howl_sriq_Premise p1, howl_types_Clause g) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        {
            __auto_type _coll = g.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (howl_types_lit_eq(l, p1.sel)) {
                    {
                        __auto_type _coll = howl_sriqsat_join_kept(arena, h.v, p1, g, j);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
                j = (j + 1);
            }
        }
        return out;
    }
}

howl_types_Clause howl_sriqsat_empty_clause(slop_arena* arena) {
    return ((howl_types_Clause){.body = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .head = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
}

uint8_t howl_sriqsat_has_eq(slop_list_howl_sriq_Premise ps) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (p.maxed && (p.sel.form == howl_types_LitForm_lf_eq)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_list_howl_sriqref_Cand howl_sriqsat_eq_ground(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqsat_Here h) {
    {
        __auto_type gn = howl_sriqsat_g_prems(arena, h, 1, 1);
        __auto_type go = howl_sriqsat_g_prems(arena, h, 2, 1);
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (howl_sriqsat_has_eq(h.dps)) {
            {
                __auto_type _coll = howl_sriqsat_eq_pairs(arena, st, h, h.dps, howl_sriqsat_g_prems(arena, h, 0, 0));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        if (howl_sriqsat_roomy(out, h) && howl_sriqsat_has_eq(h.ops)) {
            {
                __auto_type _coll = howl_sriqsat_eq_pairs(arena, st, h, h.ops, howl_sriqsat_g_prems(arena, h, 1, 0));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        if (howl_sriqsat_roomy(out, h)) {
            {
                __auto_type _coll = howl_sriqsat_eq_pairs(arena, st, h, gn, h.aps);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        if (howl_sriqsat_roomy(out, h)) {
            {
                __auto_type _coll = howl_sriqsat_eq_pairs(arena, st, h, go, h.dps);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        if (howl_sriqsat_roomy(out, h) && (((int64_t)((gn).len)) > 0)) {
            {
                __auto_type _coll = howl_sriqsat_eq_pairs(arena, st, h, gn, howl_sriqsat_g_prems(arena, h, 0, 0));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        if (howl_sriqsat_roomy(out, h) && (((int64_t)((go).len)) > 0)) {
            {
                __auto_type _coll = howl_sriqsat_eq_pairs(arena, st, h, go, howl_sriqsat_g_prems(arena, h, ((h.fresh) ? 0 : 1), 0));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

slop_list_howl_sriqref_Cand howl_sriqsat_join_ground(slop_arena* arena, howl_sriqsat_Here h) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = howl_sriqsat_join_into_g(arena, h, h.dps, 0);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        if (howl_sriqsat_roomy(out, h)) {
            {
                __auto_type _coll = howl_sriqsat_join_into_g(arena, h, h.ops, 1);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        if (howl_sriqsat_roomy(out, h)) {
            {
                __auto_type _coll = howl_sriqsat_join_from_g(arena, h, howl_sriqsat_join_sites(arena, h.all), 1);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        if (howl_sriqsat_roomy(out, h)) {
            {
                __auto_type _coll = howl_sriqsat_join_from_g(arena, h, howl_sriqsat_join_sites(arena, h.news), 2);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

slop_list_howl_sriqref_Cand howl_sriqsat_join_from_g(slop_arena* arena, howl_sriqsat_Here h, slop_list_howl_sriqsat_JoinSite sites, int64_t which) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = sites;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                __auto_type _mv_1354 = howl_sriqsat_site_lit(s);
                if (!_mv_1354.has_value) {
                } else if (_mv_1354.has_value) {
                    __auto_type l = _mv_1354.value;
                    if (howl_sriqsat_roomy(out, h)) {
                        {
                            __auto_type _coll = howl_sriqsat_join_site_g(arena, h, s, l, which);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type c = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_sriqref_Cand howl_sriqsat_join_site_g(slop_arena* arena, howl_sriqsat_Here h, howl_sriqsat_JoinSite s, howl_types_Lit l, int64_t which) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = howl_sriqground_g_sel_range(arena, h.gd, l);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                if (howl_sriqsat_roomy(out, h) && howl_sriqsat_g_picks(h, k, which)) {
                    {
                        __auto_type _coll = howl_sriqsat_join_g_one(arena, h, s, howl_sriqground_g_premise_at(h.gd, k, howl_sriqsat_fallback_premise(arena)));
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_sriqref_Cand howl_sriqsat_join_g_one(slop_arena* arena, howl_sriqsat_Here h, howl_sriqsat_JoinSite s, howl_sriq_Premise p1) {
    if (p1.maxed) {
        return howl_sriqsat_join_kept(arena, h.v, p1, s.c, s.j);
    } else {
        return ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
}

howl_sriq_Premise howl_sriqsat_fallback_premise(slop_arena* arena) {
    return ((howl_sriq_Premise){.body = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .sel = howl_types_atom1(((uint32_t)(0)), howl_types_at_x()), .rest = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .maxed = 0});
}

slop_list_howl_sriqsat_JoinSite howl_sriqsat_join_sites(slop_arena* arena, slop_list_howl_types_Clause cs) {
    {
        __auto_type raw = ((slop_list_howl_sriqsat_JoinSite){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    int64_t j = 0;
                    {
                        __auto_type _coll = c.body;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type l = _coll.data[_i];
                            if (howl_sriq_joinable(l)) {
                                (void)(({ __auto_type _lst_p = &(raw); __auto_type _item = (((howl_sriqsat_JoinSite){.c = c, .j = j})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                            j = (j + 1);
                        }
                    }
                }
            }
        }
        __auto_type _mv_1355 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_howl_sriqsat_JoinSite _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1355.has_value) {
            return raw;
        } else if (_mv_1355.has_value) {
            __auto_type s0 = _mv_1355.value;
            return howl_sriqsat_sites_sorted(arena, raw, s0);
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_howl_sriqsat_JoinSite howl_sriqsat_sites_sorted(slop_arena* arena, slop_list_howl_sriqsat_JoinSite raw, howl_sriqsat_JoinSite s0) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ howl_sriqsat__lambda_1356_env_t* howl_sriqsat__lambda_1356_env = (howl_sriqsat__lambda_1356_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqsat__lambda_1356_env_t)); *howl_sriqsat__lambda_1356_env = (howl_sriqsat__lambda_1356_env_t){ .raw = raw, .s0 = s0 }; (slop_closure_t){ (void*)howl_sriqsat__lambda_1356, (void*)howl_sriqsat__lambda_1356_env }; }));
        __auto_type out = ((slop_list_howl_sriqsat_JoinSite){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqsat_site_at(raw, k, s0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_sriqsat_JoinSite howl_sriqsat_site_at(slop_list_howl_sriqsat_JoinSite ss, int64_t k, howl_sriqsat_JoinSite fallback) {
    __auto_type _mv_1357 = ({ __auto_type _lst = ss; size_t _idx = (size_t)k; slop_option_howl_sriqsat_JoinSite _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1357.has_value) {
        __auto_type x = _mv_1357.value;
        return x;
    } else if (!_mv_1357.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

howl_types_Lit howl_sriqsat_site_key(howl_sriqsat_JoinSite s) {
    __auto_type _mv_1358 = howl_sriqsat_site_lit(s);
    if (_mv_1358.has_value) {
        __auto_type l = _mv_1358.value;
        return l;
    } else if (!_mv_1358.has_value) {
        return howl_types_atom1(((uint32_t)(0)), howl_types_at_x());
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqsat_site_lower(slop_list_howl_sriqsat_JoinSite ss, howl_types_Lit l, howl_sriqsat_JoinSite fallback) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((ss).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                if (howl_types_lit_cmp(howl_sriqsat_site_key(howl_sriqsat_site_at(ss, mid, fallback)), l) < 0) {
                    lo = (mid + 1);
                } else {
                    hi = mid;
                }
            }
        }
        return lo;
    }
}

slop_option_howl_types_Lit howl_sriqsat_site_lit(howl_sriqsat_JoinSite s) {
    return ({ __auto_type _lst = s.c.body; size_t _idx = (size_t)s.j; slop_option_howl_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
}

slop_list_howl_sriqref_Cand howl_sriqsat_sat_join(slop_arena* arena, uint32_t v, slop_list_howl_sriq_Premise p1s, slop_list_howl_sriqsat_JoinSite sites, int64_t room) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = p1s;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p1 = _coll.data[_i];
                if (((((int64_t)(((int64_t)((out).len)))) <= room)) && (p1.maxed) && (howl_sriq_joinable(p1.sel))) {
                    {
                        __auto_type _coll = howl_sriqsat_join_one(arena, v, p1, sites);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_sriqref_Cand howl_sriqsat_join_one(slop_arena* arena, uint32_t v, howl_sriq_Premise p1, slop_list_howl_sriqsat_JoinSite sites) {
    __auto_type _mv_1359 = ({ __auto_type _lst = sites; size_t _idx = (size_t)0; slop_option_howl_sriqsat_JoinSite _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1359.has_value) {
        return ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    } else if (_mv_1359.has_value) {
        __auto_type s0 = _mv_1359.value;
        return howl_sriqsat_join_from(arena, v, p1, sites, howl_sriqsat_site_lower(sites, p1.sel, s0), s0);
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_sriqref_Cand howl_sriqsat_join_from(slop_arena* arena, uint32_t v, howl_sriq_Premise p1, slop_list_howl_sriqsat_JoinSite sites, int64_t k0, howl_sriqsat_JoinSite s0) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = k0;
        while ((k < ((int64_t)(((int64_t)((sites).len))))) && howl_sriqsat_site_holds(howl_sriqsat_site_at(sites, k, s0), p1.sel)) {
            {
                __auto_type s = howl_sriqsat_site_at(sites, k, s0);
                {
                    __auto_type _coll = howl_sriqsat_join_kept(arena, v, p1, s.c, s.j);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
                k = (k + 1);
            }
        }
        return out;
    }
}

uint8_t howl_sriqsat_site_holds(howl_sriqsat_JoinSite s, howl_types_Lit l) {
    __auto_type _mv_1360 = howl_sriqsat_site_lit(s);
    if (_mv_1360.has_value) {
        __auto_type m = _mv_1360.value;
        return howl_types_lit_eq(m, l);
    } else if (!_mv_1360.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

howl_sriqref_Round howl_sriqsat_nom_pairs(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, howl_sriqref_Dl4 d, slop_list_howl_sriq_Premise p1s, slop_list_howl_sriq_Premise p2s) {
    {
        __auto_type cands = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type noms = ((slop_list_howl_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = p1s;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p1 = _coll.data[_i];
                if (howl_sriqref_nom_first(p1, d)) {
                    {
                        __auto_type _coll = p2s;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type p2 = _coll.data[_i];
                            if (howl_sriqref_nom_second(p2, d, p1.sel.t1.cst)) {
                                {
                                    __auto_type r = howl_sriqref_nom_pair(arena, env, st.ord, h.v, d, p1, p2);
                                    {
                                        __auto_type _coll = r.cands;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type c = _coll.data[_i];
                                            (void)(({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                        }
                                    }
                                    {
                                        __auto_type _coll = r.noms;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type a = _coll.data[_i];
                                            (void)(({ __auto_type _lst_p = &(noms); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return howl_sriqref_round_of(cands, ((slop_list_howl_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_howl_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), noms, 0);
    }
}

howl_sriqref_Round howl_sriqsat_sat_nom(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqsat_Here h) {
    {
        __auto_type all = howl_sriqsat_consts_new(st, dl);
        __auto_type mine = howl_sriqsat_nom_own(arena, env, st, h, all);
        __auto_type cands = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type noms = ((slop_list_howl_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = mine.cands;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = mine.noms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(noms); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        if (!(h.root)) {
            {
                __auto_type _coll = h.hx.dl4s;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type d = _coll.data[_i];
                    {
                        __auto_type _coll = howl_sriqsat_nom_ground(arena, env, st, h, d, all);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            {
                                __auto_type _coll = r.cands;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type c = _coll.data[_i];
                                    (void)(({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                }
                            }
                            {
                                __auto_type _coll = r.noms;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type a = _coll.data[_i];
                                    (void)(({ __auto_type _lst_p = &(noms); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                }
                            }
                        }
                    }
                }
            }
        }
        return howl_sriqref_round_of(cands, ((slop_list_howl_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_howl_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), noms, 0);
    }
}

slop_list_howl_sriqref_Round howl_sriqsat_nom_ground(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, howl_sriqref_Dl4 d, uint8_t all) {
    if (!(d.ok)) {
        return ((slop_list_howl_sriqref_Round){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    } else if (all) {
        return howl_sriqsat_one_round(arena, howl_sriqsat_nom_from_g(arena, env, st, h, d, h.aps, 0));
    } else {
        return howl_sriqsat_two_rounds(arena, howl_sriqsat_nom_from_g(arena, env, st, h, d, h.aps, 1), howl_sriqsat_nom_from_g(arena, env, st, h, d, h.dps, 2));
    }
}

howl_sriqref_Round howl_sriqsat_nom_own(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, uint8_t all) {
    {
        __auto_type cands = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type noms = ((slop_list_howl_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = h.hx.dl4s;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type d = _coll.data[_i];
                {
                    __auto_type _coll = ((all) ? howl_sriqsat_one_round(arena, howl_sriqsat_nom_pairs(arena, env, st, h, d, h.aps, h.aps)) : howl_sriqsat_two_rounds(arena, howl_sriqsat_nom_pairs(arena, env, st, h, d, h.dps, h.aps), howl_sriqsat_nom_pairs(arena, env, st, h, d, h.ops, h.dps)));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        {
                            __auto_type _coll = r.cands;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type c = _coll.data[_i];
                                (void)(({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                        }
                        {
                            __auto_type _coll = r.noms;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type a = _coll.data[_i];
                                (void)(({ __auto_type _lst_p = &(noms); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                        }
                    }
                }
            }
        }
        return howl_sriqref_round_of(cands, ((slop_list_howl_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_howl_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), noms, 0);
    }
}

slop_list_howl_sriqref_Round howl_sriqsat_one_round(slop_arena* arena, howl_sriqref_Round a) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Round){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

howl_sriqref_Round howl_sriqsat_nom_from_g(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, howl_sriqref_Dl4 d, slop_list_howl_sriq_Premise p2s, int64_t which) {
    {
        __auto_type cands = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type noms = ((slop_list_howl_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = p2s;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p2 = _coll.data[_i];
                if ((p2.maxed) && ((p2.sel.form == howl_types_LitForm_lf_binary)) && ((p2.sel.t1.kind == howl_types_AKind_ak_u))) {
                    {
                        __auto_type r = howl_sriqsat_nom_g_one(arena, env, st, h, d, p2, p2.sel.t1.cst, which);
                        {
                            __auto_type _coll = r.cands;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type c = _coll.data[_i];
                                (void)(({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                        }
                        {
                            __auto_type _coll = r.noms;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type a = _coll.data[_i];
                                (void)(({ __auto_type _lst_p = &(noms); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                        }
                    }
                }
            }
        }
        return howl_sriqref_round_of(cands, ((slop_list_howl_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_howl_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), noms, 0);
    }
}

howl_sriqref_Round howl_sriqsat_nom_g_one(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, howl_sriqref_Dl4 d, howl_sriq_Premise p2, uint32_t o, int64_t which) {
    {
        __auto_type cands = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type noms = ((slop_list_howl_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = howl_sriqground_g_sel_range(arena, h.gd, howl_types_atom1(d.b1, howl_types_at_u(o)));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type p1 = howl_sriqground_g_premise_at(h.gd, k, howl_sriqsat_fallback_premise(arena));
                    if ((howl_sriqsat_g_picks(h, k, which)) && (howl_sriqref_nom_first(p1, d)) && (howl_sriqref_nom_second(p2, d, o))) {
                        {
                            __auto_type r = howl_sriqref_nom_pair(arena, env, st.ord, h.v, d, p1, p2);
                            {
                                __auto_type _coll = r.cands;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type c = _coll.data[_i];
                                    (void)(({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                }
                            }
                            {
                                __auto_type _coll = r.noms;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type a = _coll.data[_i];
                                    (void)(({ __auto_type _lst_p = &(noms); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                }
                            }
                        }
                    }
                }
            }
        }
        return howl_sriqref_round_of(cands, ((slop_list_howl_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_howl_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), noms, 0);
    }
}

slop_list_howl_sriqref_Round howl_sriqsat_two_rounds(slop_arena* arena, howl_sriqref_Round a, howl_sriqref_Round b) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Round){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

uint8_t howl_sriqsat_k2_touched(slop_arena* arena, howl_sriqref_Env env, howl_sriqsat_Here h, howl_sriqindex_KIdx kn, howl_sriq_Premise p) {
    __auto_type _mv_1361 = howl_sriq_succ_sig(h.root, p.sel);
    if (!_mv_1361.has_value) {
        return 0;
    } else if (_mv_1361.has_value) {
        __auto_type sg = _mv_1361.value;
        return (((int64_t)((howl_sriqindex_k_query(arena, env.tr, kn, sg).k2).len)) > 0);
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_sriq_Premise howl_sriqsat_succ_premises(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h) {
    {
        __auto_type kn = ((h.views) ? howl_sriqindex_k_index_premises(arena, env.tr, h.dps) : howl_sriqindex_k_index(arena, st.ord, env.tr, h.news));
        __auto_type gnew = (((int64_t)((kn.ground).len)) > 0);
        __auto_type out = ((slop_list_howl_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = h.dps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        if (gnew || (((int64_t)((kn.fparts).len)) > 0)) {
            {
                __auto_type _coll = h.ops;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type p = _coll.data[_i];
                    if (p.maxed && (gnew || howl_sriqsat_k2_touched_apart(env, h, kn, p))) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

uint8_t howl_sriqsat_k2_touched_apart(howl_sriqref_Env env, howl_sriqsat_Here h, howl_sriqindex_KIdx kn, howl_sriq_Premise p) {
    {
        __auto_type tmp = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(65536); _new_arena; });
        __auto_type touched = howl_sriqsat_k2_touched(tmp, env, h, kn, p);
        (void)(({ slop_arena_free(tmp); free(tmp); }));
        return touched;
    }
}

slop_list_howl_sriqref_SuccAct howl_sriqsat_sat_succ(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, slop_list_howl_sriq_Premise ps) {
    {
        __auto_type kx = ((h.views) ? howl_sriqindex_k_index_premises(arena, env.tr, h.aps) : howl_sriqindex_k_index(arena, st.ord, env.tr, h.all));
        __auto_type base = howl_sriqsat_unheld(arena, h.gd, kx.ground);
        __auto_type bare = ((howl_sriqindex_KIdx){.ground = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .fparts = kx.fparts});
        __auto_type ts = howl_sriqsat_triggers_of(arena, h, ps);
        __auto_type out = ((slop_list_howl_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1362 = ({ __auto_type _lst = ts; size_t _idx = (size_t)0; slop_option_howl_sriqsat_Trig _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1362.has_value) {
            return out;
        } else if (_mv_1362.has_value) {
            __auto_type t0 = _mv_1362.value;
            return howl_sriqsat_succ_trigs(arena, env, st, h, bare, base, ts, t0);
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_howl_sriqref_SuccAct howl_sriqsat_succ_trigs(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, howl_sriqindex_KIdx bare, slop_list_howl_types_Lit base, slop_list_howl_sriqsat_Trig ts, howl_sriqsat_Trig t0) {
    {
        __auto_type sv = howl_sriqsat_succ_view(arena, env, st, h, bare, base, t0.sg);
        __auto_type last = t0.sg;
        __auto_type out = ((slop_list_howl_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (h.dfr) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqsat_succ_eval(arena, env, h, sv, t0.sg)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        {
            __auto_type _coll = ts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (howl_sriqsat_sg_cmp(t.sg, last) != 0) {
                    sv = howl_sriqsat_succ_view(arena, env, st, h, bare, base, t.sg);
                    last = t.sg;
                    if (h.dfr) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqsat_succ_eval(arena, env, h, sv, t.sg)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
                if (!(h.dfr)) {
                    {
                        __auto_type _coll = howl_sriqsat_succ_on(arena, env, h, sv, t);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type a = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        return out;
    }
}

howl_sriqref_SuccAct howl_sriqsat_succ_eval(slop_arena* arena, howl_sriqref_Env env, howl_sriqsat_Here h, howl_sriqsat_SuccView sv, howl_sriq_SuccSig sg) {
    {
        __auto_type k1 = sv.ks.k1;
        return ((howl_sriqref_SuccAct){.from = h.v, .sg = sg, .core = howl_sriqctx_core_of(arena, howl_sriqctx_strat_choice(env.strat, env.tr, sg.f, k1), k1), .adds = sv.ks.k2});
    }
}

slop_list_howl_sriqsat_Trig howl_sriqsat_triggers_of(slop_arena* arena, howl_sriqsat_Here h, slop_list_howl_sriq_Premise ps) {
    {
        __auto_type raw = ((slop_list_howl_sriqsat_Trig){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (p.maxed) {
                    __auto_type _mv_1363 = howl_sriq_succ_sig(h.root, p.sel);
                    if (!_mv_1363.has_value) {
                    } else if (_mv_1363.has_value) {
                        __auto_type sg = _mv_1363.value;
                        ({ __auto_type _lst_p = &(raw); __auto_type _item = (((howl_sriqsat_Trig){.p = p, .sg = sg})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        __auto_type _mv_1364 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_howl_sriqsat_Trig _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1364.has_value) {
            return raw;
        } else if (_mv_1364.has_value) {
            __auto_type t0 = _mv_1364.value;
            return howl_sriqsat_trigs_sorted(arena, raw, t0);
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_howl_sriqsat_Trig howl_sriqsat_trigs_sorted(slop_arena* arena, slop_list_howl_sriqsat_Trig raw, howl_sriqsat_Trig t0) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ howl_sriqsat__lambda_1365_env_t* howl_sriqsat__lambda_1365_env = (howl_sriqsat__lambda_1365_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqsat__lambda_1365_env_t)); *howl_sriqsat__lambda_1365_env = (howl_sriqsat__lambda_1365_env_t){ .raw = raw, .t0 = t0 }; (slop_closure_t){ (void*)howl_sriqsat__lambda_1365, (void*)howl_sriqsat__lambda_1365_env }; }));
        __auto_type out = ((slop_list_howl_sriqsat_Trig){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqsat_trig_at(raw, k, t0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_sriqsat_Trig howl_sriqsat_trig_at(slop_list_howl_sriqsat_Trig ts, int64_t k, howl_sriqsat_Trig fallback) {
    __auto_type _mv_1366 = ({ __auto_type _lst = ts; size_t _idx = (size_t)k; slop_option_howl_sriqsat_Trig _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1366.has_value) {
        __auto_type t = _mv_1366.value;
        return t;
    } else if (!_mv_1366.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqsat_sg_cmp(howl_sriq_SuccSig a, howl_sriq_SuccSig b) {
    if (a.f < b.f) {
        return -1;
    } else if (a.f > b.f) {
        return 1;
    } else if (a.u < b.u) {
        return -1;
    } else if (a.u > b.u) {
        return 1;
    } else if (a.root == b.root) {
        return 0;
    } else if (a.root) {
        return 1;
    } else {
        return -1;
    }
}

howl_sriqsat_SuccView howl_sriqsat_succ_view(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, howl_sriqindex_KIdx bare, slop_list_howl_types_Lit base, howl_sriq_SuccSig sg) {
    {
        __auto_type ks = howl_sriqindex_k_query(arena, env.tr, bare, sg);
        __auto_type k2 = howl_sriqsat_merged_lits(arena, base, howl_sriqsat_unheld(arena, h.gd, ks.k2));
        return ((howl_sriqsat_SuccView){.ks = ((howl_sriq_KSets){.k1 = ks.k1, .k2 = k2}), .covered = (!(h.dfr) && howl_sriqsat_covered_view(arena, env, st, h.v, sg.f, k2))});
    }
}

slop_list_howl_sriqref_SuccAct howl_sriqsat_succ_on(slop_arena* arena, howl_sriqref_Env env, howl_sriqsat_Here h, howl_sriqsat_SuccView sv, howl_sriqsat_Trig t) {
    {
        __auto_type r = howl_sriq_succ_step(arena, env.strat, env.tr, t.sg, t.p, sv.ks, sv.covered);
        __auto_type out = ((slop_list_howl_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (r.fires) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqref_SuccAct){.from = h.v, .sg = t.sg, .core = howl_sriqctx_core_of(arena, r.choice, sv.ks.k1), .adds = r.adds})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        return out;
    }
}

slop_list_howl_types_Lit howl_sriqsat_merged_lits(slop_arena* arena, slop_list_howl_types_Lit a, slop_list_howl_types_Lit b) {
    if (((int64_t)((b).len)) == 0) {
        return a;
    } else {
        {
            __auto_type xs = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = a;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type l = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(xs); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
            {
                __auto_type _coll = b;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type l = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(xs); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
            return howl_sriqclauses_lit_set(arena, xs);
        }
    }
}

slop_list_howl_types_Lit howl_sriqsat_unheld(slop_arena* arena, howl_sriqground_Ground gd, slop_list_howl_types_Lit k2) {
    {
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = k2;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (!(howl_sriqground_g_held(arena, gd, a))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

uint8_t howl_sriqsat_covered_view(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint32_t v, uint32_t f, slop_list_howl_types_Lit k2) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = st.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (((e.from == v)) && ((e.lk == howl_sriqctx_EdgeLabel_el_fn)) && ((e.label == f)) && (howl_sriq_covers(k2, howl_sriqref_core_at(env, st, arena, ((int64_t)(e.to))), howl_sriqref_set_of(env, st, ((int64_t)(e.to)))))) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

howl_sriqref_Out howl_sriqsat_pred_anchored(slop_arena* arena, howl_sriqref_Env env, howl_sriqref_PJob job, howl_sriqground_PIdx dix, howl_sriqground_PIdx oix, howl_sriqground_PIdx aix, int64_t room) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        int64_t i = 0;
        while ((i < ((int64_t)(((int64_t)((job.slots).len))))) && (((int64_t)(((int64_t)((out).len)))) <= room)) {
            {
                __auto_type o = howl_sriqsat_pred_anchor(arena, env, job, dix, oix, aix, i, room);
                {
                    __auto_type _coll = o.cands;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
                if (o.over) {
                    over = 1;
                }
                i = (i + 1);
            }
        }
        return howl_sriqref_out_of(out, over);
    }
}

slop_list_howl_sriq_Premise howl_sriqsat_slot_ix(slop_arena* arena, howl_sriq_CSub s, howl_sriq_PSlot slot, howl_sriqground_PIdx ix) {
    return howl_sriqground_pidx_find(arena, ix, howl_sriq_csub_lit(s, slot.lit));
}

howl_sriqref_Out howl_sriqsat_pred_anchor(slop_arena* arena, howl_sriqref_Env env, howl_sriqref_PJob job, howl_sriqground_PIdx dix, howl_sriqground_PIdx oix, howl_sriqground_PIdx aix, int64_t i, int64_t room) {
    {
        __auto_type cs = ((slop_list_list_howl_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        {
            __auto_type _coll = job.slots;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type slot = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(cs); __auto_type _item = (howl_sriqsat_slot_ix(arena, job.s, slot, howl_sriqground_pick_ix(j, i, dix, oix, aix))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                j = (j + 1);
            }
        }
        return howl_sriqsat_pred_choices(arena, env, job, cs, aix.ps, room);
    }
}

howl_sriqref_Out howl_sriqsat_pred_run_ix(slop_arena* arena, howl_sriqref_Env env, howl_sriqref_PJob job, howl_sriqground_PIdx aix, int64_t room) {
    {
        __auto_type cs = ((slop_list_list_howl_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = job.slots;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type slot = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(cs); __auto_type _item = (howl_sriqsat_slot_ix(arena, job.s, slot, aix)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return howl_sriqsat_pred_choices(arena, env, job, cs, aix.ps, room);
    }
}

howl_sriqref_Out howl_sriqsat_pred_choices(slop_arena* arena, howl_sriqref_Env env, howl_sriqref_PJob job, slop_list_list_howl_sriq_Premise cs, slop_list_howl_sriq_Premise ps, int64_t room) {
    {
        __auto_type n = howl_sriqref_product(cs, env.prod);
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t t = 0;
        if (n > env.prod) {
            return howl_sriqref_out_of(out, 1);
        } else {
            {
                __auto_type tmp = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(65536); _new_arena; });
                while ((t < n) && (((int64_t)(((int64_t)((out).len)))) <= room)) {
                    {
                        __auto_type _coll = howl_sriqref_pred_one(tmp, env, job, cs, t, ps);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqref_copy_cand(arena, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                    howl_saturate_reuse_arena(tmp);
                    t = (t + 1);
                }
                (void)(({ slop_arena_free(tmp); free(tmp); }));
                return howl_sriqref_out_of(out, 0);
            }
        }
    }
}

howl_sriqground_PIdx howl_sriqsat_w_ix(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, int64_t w, slop_list_howl_types_Clause cs, int64_t which) {
    {
        __auto_type x = howl_sriqsat_cix_at(arena, h.ixs, w);
        if (which == 1) {
            return x.dix;
        } else if (which == 2) {
            return x.oix;
        } else {
            return x.aix;
        }
    }
}

howl_sriqref_Out howl_sriqsat_pred_side(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqsat_Here h, howl_sriqctx_Edge e) {
    {
        __auto_type w = ((int64_t)(e.from));
        __auto_type toroot = howl_sriqref_is_root(st, ((int64_t)(e.from)));
        __auto_type aix = howl_sriqsat_w_ix(arena, env, st, h, w, howl_sriqref_set_of(env, st, w), 0);
        __auto_type dix = howl_sriqsat_w_ix(arena, env, st, h, w, howl_sriqsat_cs_at(dl.news, w, env.nobody), 1);
        __auto_type oix = howl_sriqsat_w_ix(arena, env, st, h, w, howl_sriqsat_cs_at(dl.olds, w, env.nobody), 2);
        __auto_type core = howl_sriqref_core_at(env, st, arena, ((int64_t)(h.v)));
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        {
            __auto_type _coll = h.olds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type view = howl_sriq_pred_view(arena, c, core, toroot);
                    __auto_type slots = howl_sriqref_slots_of(arena, view.slots);
                    {
                        __auto_type _coll = howl_sriqsat_side_jobs(arena, st, view, slots, e, toroot);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type job = _coll.data[_i];
                            {
                                __auto_type o = ((howl_sriqsat_roomy(out, h)) ? howl_sriqsat_pred_anchored(arena, env, job, dix, oix, aix, h.room) : howl_sriqsat_no_out(arena));
                                {
                                    __auto_type _coll = o.cands;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type x = _coll.data[_i];
                                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                    }
                                }
                                if (o.over) {
                                    over = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        return howl_sriqref_out_of(out, over);
    }
}

howl_sriqref_Out howl_sriqsat_pred_edge_ix(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, howl_sriqctx_Edge e, slop_list_howl_types_Clause cs) {
    {
        __auto_type w = ((int64_t)(e.from));
        __auto_type toroot = howl_sriqref_is_root(st, ((int64_t)(e.from)));
        __auto_type aix = howl_sriqsat_w_ix(arena, env, st, h, w, howl_sriqref_set_of(env, st, w), 0);
        __auto_type core = howl_sriqref_core_at(env, st, arena, ((int64_t)(h.v)));
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type view = howl_sriq_pred_view(arena, c, core, toroot);
                    __auto_type slots = howl_sriqref_slots_of(arena, view.slots);
                    {
                        __auto_type _coll = howl_sriqsat_side_jobs(arena, st, view, slots, e, toroot);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type job = _coll.data[_i];
                            {
                                __auto_type o = ((howl_sriqsat_roomy(out, h)) ? howl_sriqsat_pred_run_ix(arena, env, job, aix, h.room) : howl_sriqsat_no_out(arena));
                                {
                                    __auto_type _coll = o.cands;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type x = _coll.data[_i];
                                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                    }
                                }
                                if (o.over) {
                                    over = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        return howl_sriqref_out_of(out, over);
    }
}

slop_list_howl_sriqref_PJob howl_sriqsat_side_jobs(slop_arena* arena, howl_sriqctx_Structure st, howl_sriq_PredView view, slop_list_howl_sriq_PSlot slots, howl_sriqctx_Edge e, uint8_t toroot) {
    {
        __auto_type out = ((slop_list_howl_sriqref_PJob){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t u = 0;
        if (!(toroot)) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqref_away_job(view, slots, e.label, e.from)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        } else {
            while (u < howl_sriqref_consts_of(st)) {
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqref_root_job(view, slots, e.from, e.label, ((uint32_t)(u)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                u = (u + 1);
            }
        }
        return out;
    }
}

howl_sriqref_Out howl_sriqsat_no_out(slop_arena* arena) {
    return howl_sriqref_out_of(((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0);
}

howl_sriqref_Out howl_sriqsat_sat_pred(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqsat_Here h, slop_list_howl_sriqctx_Edge ins) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        {
            __auto_type _coll = ins;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if ((e.lk == howl_sriqctx_EdgeLabel_el_fn) && howl_sriqsat_roomy(out, h)) {
                    {
                        __auto_type _coll = howl_sriqsat_pred_over(arena, env, st, dl, h, e);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type o = _coll.data[_i];
                            {
                                __auto_type _coll = o.cands;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type x = _coll.data[_i];
                                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                }
                            }
                            if (o.over) {
                                over = 1;
                            }
                        }
                    }
                }
            }
        }
        return howl_sriqref_out_of(out, over);
    }
}

slop_list_howl_sriqref_Out howl_sriqsat_pred_over(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqsat_Here h, howl_sriqctx_Edge e) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Out){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type w = ((int64_t)(e.from));
        if (howl_sriqsat_edge_new(dl, e) || (howl_sriqref_is_root(st, w) && howl_sriqsat_consts_new(st, dl))) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqsat_pred_edge_ix(arena, env, st, h, e, h.all)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        } else {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqsat_pred_edge_ix(arena, env, st, h, e, h.news)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            if (((int64_t)((howl_sriqsat_cs_at(dl.news, w, env.nobody)).len)) > 0) {
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqsat_pred_side(arena, env, st, dl, h, e)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

uint8_t howl_sriqsat_rpred_edge_new(howl_sriqsat_Delta dl, uint32_t v) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = dl.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (((e.from == v)) && ((e.to == ((uint32_t)(0)))) && ((e.lk == howl_sriqctx_EdgeLabel_el_const))) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

howl_sriqref_Out howl_sriqsat_sat_rpred(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqsat_Here h) {
    if (h.fresh || howl_sriqsat_rpred_edge_new(dl, h.v)) {
        return howl_sriqsat_rpred_from(arena, env, st, h, h.rs.all, h.aps, 0);
    } else {
        {
            __auto_type a = howl_sriqsat_rpred_from(arena, env, st, h, h.rs.news, h.aps, 0);
            __auto_type b = (((((int64_t)((h.news).len)) > 0)) ? howl_sriqsat_rpred_from(arena, env, st, h, h.rs.olds, h.aps, 1) : howl_sriqref_out_of(((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0));
            return howl_sriqref_out_of(howl_sriqref_append_cands(arena, a.cands, b.cands), (a.over || b.over));
        }
    }
}

howl_sriqref_Out howl_sriqsat_rpred_from(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Here h, slop_list_howl_sriqsat_RSrc rs, slop_list_howl_sriq_Premise aps, uint8_t anchored) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                {
                    __auto_type job = howl_sriqsat_rsrc_job(arena, st, h.v, r);
                    __auto_type o = (!(howl_sriqsat_roomy(out, h)) ? howl_sriqsat_no_out(arena) : (anchored ? howl_sriqsat_pred_anchored(arena, env, job, h.dix, h.oix, h.aix, h.room) : howl_sriqsat_pred_run_ix(arena, env, job, h.aix, h.room)));
                    {
                        __auto_type _coll = o.cands;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type x = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                    if (o.over) {
                        over = 1;
                    }
                }
            }
        }
        return howl_sriqref_out_of(out, over);
    }
}

uint8_t howl_sriqsat_rpred_able(howl_sriqctx_Triggers tr, howl_sriq_PredView v) {
    uint8_t _retval = {0};
    _retval = (v.ok && howl_sriq_rpred_heads_ok(tr, v.head));
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval == (v.ok && howl_sriq_rpred_heads_ok(tr, v.head)))), "(== $result (and (. v ok) (rpred-heads-ok tr (. v head))))");
    return _retval;
}

slop_list_howl_sriqsat_RSrc howl_sriqsat_rsrcs_in(slop_arena* arena, howl_sriqctx_Triggers tr, slop_list_howl_types_Clause cs) {
    {
        __auto_type out = ((slop_list_howl_sriqsat_RSrc){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(howl_sriqground_ground_clause(c))) {
                    {
                        __auto_type v = howl_sriq_rpred_view(arena, tr, c);
                        if (howl_sriqsat_rpred_able(tr, v)) {
                            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqsat_RSrc){.c = c, .view = v})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        return out;
    }
}

howl_sriqsat_RSrcs howl_sriqsat_rsrcs_of(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl) {
    return ((howl_sriqsat_RSrcs){.all = howl_sriqsat_rsrcs_in(arena, env.tr, howl_sriqref_set_of(env, st, 0)), .news = howl_sriqsat_rsrcs_in(arena, env.tr, howl_sriqsat_cs_at(dl.news, 0, env.nobody)), .olds = howl_sriqsat_rsrcs_in(arena, env.tr, howl_sriqsat_cs_at(dl.olds, 0, env.nobody))});
}

howl_sriqref_PJob howl_sriqsat_rsrc_job(slop_arena* arena, howl_sriqctx_Structure st, uint32_t v, howl_sriqsat_RSrc r) {
    return ((howl_sriqref_PJob){.view = r.view, .s = ((howl_sriq_CSub){.x = howl_types_at_x(), .y = howl_types_at_x()}), .slots = howl_sriqref_rslots(arena, st, v, r.view.slots), .to = v, .rpred = 1, .toroot = 0});
}

howl_sriqctx_Structure howl_sriqsat_local(howl_sriqctx_Structure st, howl_sriqsat_Adj a, slop_arena* arena) {
    {
        __auto_type es = ((slop_list_howl_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = a.outs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(es); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = a.ins;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(es); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ((howl_sriqctx_Structure){.ctxs = st.ctxs, .sets = st.sets, .edges = es, .ord = st.ord});
    }
}

howl_sriqsat_CRound howl_sriqsat_sat_ctx(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HIdx hx, slop_list_howl_sriqsat_CIdx ixs, howl_sriqsat_RSrcs rs, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqground_Ground gd, howl_sriqsat_Adj a, int64_t v, int64_t perm, uint8_t dfr, uint8_t views, int64_t room) {
    {
        __auto_type lst = howl_sriqsat_local(st, a, arena);
        if ((v >= dl.nctx) && howl_sriqref_is_root(st, v)) {
            {
                __auto_type r = howl_sriqref_ctx_round(arena, howl_sriqref_with_room(env, room), lst, ((uint32_t)(v)));
                return ((howl_sriqsat_CRound){.r = r, .tried = 0, .big = (((int64_t)(((int64_t)((r.cands).len)))) > room)});
            }
        } else {
            return howl_sriqsat_sat_old(arena, env, lst, dl, a.ins, howl_sriqsat_here_room(howl_sriqsat_here_of(arena, env, lst, dl, gd, hx, ixs, rs, v, perm, dfr, views), room), room);
        }
    }
}

howl_sriqsat_CRound howl_sriqsat_sat_old(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, slop_list_howl_sriqctx_Edge ins, howl_sriqsat_Here h, int64_t room) {
    {
        __auto_type t2 = howl_sriqsat_sat_table2(arena, env, st, dl, h, room);
        if (((int64_t)(((int64_t)((t2.out.cands).len)))) > room) {
            return ((howl_sriqsat_CRound){.r = howl_sriqref_round_of(t2.out.cands, ((slop_list_howl_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_howl_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_howl_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), t2.out.over), .tried = t2.tried, .big = 1});
        } else {
            return howl_sriqsat_sat_old_rest(arena, env, st, dl, ins, h, room, t2);
        }
    }
}

howl_sriqsat_CRound howl_sriqsat_sat_old_rest(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, slop_list_howl_sriqctx_Edge ins, howl_sriqsat_Here h, int64_t room, howl_sriqhyper_HOut t2) {
    {
        __auto_type t2c = t2.out.cands;
        __auto_type nom = howl_sriqsat_sat_nom(arena, env, st, dl, h);
        __auto_type skip = howl_sriqref_out_of(((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0);
        __auto_type pr = (((h.root || !(howl_sriqsat_within(t2c, nom.cands, room)))) ? skip : howl_sriqsat_sat_pred(arena, env, st, dl, h, ins));
        __auto_type rp = (((h.root || !(howl_sriqsat_within(t2c, howl_sriqref_append_cands(arena, nom.cands, pr.cands), room)))) ? skip : howl_sriqsat_sat_rpred(arena, env, st, dl, h));
        __auto_type cands = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = t2c;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = nom.cands;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = pr.cands;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = rp.cands;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type big = (((int64_t)(((int64_t)((cands).len)))) > room);
            return ((howl_sriqsat_CRound){.r = howl_sriqref_round_of(cands, ((big) ? ((slop_list_howl_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) : howl_sriqsat_sat_succ(arena, env, st, h, howl_sriqsat_succ_premises(arena, env, st, h))), (((big || h.root)) ? ((slop_list_howl_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) : howl_sriqref_ref_rsucc(arena, env, st, h.v, h.dps)), nom.noms, ((t2.out.over) || (pr.over) || (rp.over))), .tried = t2.tried, .big = big});
        }
    }
}

howl_sriqctx_Edge howl_sriqsat_edge_at(slop_list_howl_sriqctx_Edge es, int64_t k, howl_sriqctx_Edge fallback) {
    __auto_type _mv_1367 = ({ __auto_type _lst = es; size_t _idx = (size_t)k; slop_option_howl_sriqctx_Edge _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1367.has_value) {
        __auto_type e = _mv_1367.value;
        return e;
    } else if (!_mv_1367.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_sriqsat_Adj howl_sriqsat_adjacency(slop_arena* arena, howl_sriqctx_Structure st) {
    {
        __auto_type es = st.edges;
        __auto_type n = ((int64_t)(((int64_t)((st.ctxs).len))));
        __auto_type e0 = ((howl_sriqctx_Edge){.from = ((uint32_t)(0)), .to = ((uint32_t)(0)), .lk = howl_sriqctx_EdgeLabel_el_fn, .label = ((uint32_t)(0))});
        __auto_type by_to = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((st.edges).len)))), ({ howl_sriqsat__lambda_1368_env_t* howl_sriqsat__lambda_1368_env = (howl_sriqsat__lambda_1368_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqsat__lambda_1368_env_t)); *howl_sriqsat__lambda_1368_env = (howl_sriqsat__lambda_1368_env_t){ .es = es, .e0 = e0 }; (slop_closure_t){ (void*)howl_sriqsat__lambda_1368, (void*)howl_sriqsat__lambda_1368_env }; }));
        __auto_type by_from = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((st.edges).len)))), ({ howl_sriqsat__lambda_1369_env_t* howl_sriqsat__lambda_1369_env = (howl_sriqsat__lambda_1369_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqsat__lambda_1369_env_t)); *howl_sriqsat__lambda_1369_env = (howl_sriqsat__lambda_1369_env_t){ .es = es, .e0 = e0 }; (slop_closure_t){ (void*)howl_sriqsat__lambda_1369, (void*)howl_sriqsat__lambda_1369_env }; }));
        __auto_type ins = howl_sriqsat_buckets(arena, es, by_to, n, 1, e0);
        __auto_type outs = howl_sriqsat_buckets(arena, es, by_from, n, 0, e0);
        __auto_type out = ((slop_list_howl_sriqsat_Adj){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        while (v < n) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqsat_Adj){.ins = howl_sriqsat_edges_at(arena, ins, v), .outs = howl_sriqsat_edges_at(arena, outs, v)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            v = (v + 1);
        }
        return out;
    }
}

slop_list_howl_sriqctx_Edge howl_sriqsat_edges_at(slop_arena* arena, slop_list_howl_sriqsat_Bucket bs, int64_t v) {
    __auto_type _mv_1370 = ({ __auto_type _lst = bs; size_t _idx = (size_t)v; slop_option_howl_sriqsat_Bucket _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1370.has_value) {
        __auto_type b = _mv_1370.value;
        return b.es;
    } else if (!_mv_1370.has_value) {
        return ((slop_list_howl_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqsat_u32_cmp(uint32_t a, uint32_t b) {
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    } else {
        return 0;
    }
}

howl_sriqsat_Cut howl_sriqsat_cut_at(slop_arena* arena, slop_list_howl_sriqctx_Edge es, slop_list_int idx, int64_t k, int64_t v, uint8_t by_to, howl_sriqctx_Edge e0) {
    {
        __auto_type cur = ((slop_list_howl_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = k;
        uint8_t going = 1;
        while (going && (i < ((int64_t)(((int64_t)((idx).len)))))) {
            {
                __auto_type e = howl_sriqsat_edge_at(es, howl_sriqsat_idx_at(idx, i), e0);
                if (((int64_t)(((by_to) ? e.to : e.from))) == v) {
                    (void)(({ __auto_type _lst_p = &(cur); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    i = (i + 1);
                } else {
                    going = 0;
                }
            }
        }
        return ((howl_sriqsat_Cut){.es = cur, .k = i});
    }
}

slop_list_howl_sriqsat_Bucket howl_sriqsat_buckets(slop_arena* arena, slop_list_howl_sriqctx_Edge es, slop_list_int idx, int64_t n, uint8_t by_to, howl_sriqctx_Edge e0) {
    {
        __auto_type out = ((slop_list_howl_sriqsat_Bucket){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        int64_t v = 0;
        while (v < n) {
            {
                __auto_type c = howl_sriqsat_cut_at(arena, es, idx, k, v, by_to, e0);
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqsat_Bucket){.es = c.es})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                k = c.k;
                v = (v + 1);
            }
        }
        return out;
    }
}

int64_t howl_sriqsat_idx_at(slop_list_int idx, int64_t k) {
    __auto_type _mv_1371 = ({ __auto_type _lst = idx; size_t _idx = (size_t)k; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1371.has_value) {
        __auto_type i = _mv_1371.value;
        return i;
    } else if (!_mv_1371.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqsat_passes(howl_sriqsat_CRound cr, slop_list_howl_sriqref_Cand cands, int64_t room) {
    return (cr.big || (((int64_t)(((int64_t)((cands).len)))) > room));
}

howl_sriqsat_CRound howl_sriqsat_sat_round(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HIdx hx, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, howl_sriqground_Ground gd, int64_t perm, uint8_t dfr, slop_list_howl_sriqsat_View vw, int64_t room) {
    {
        __auto_type adj = howl_sriqsat_adjacency(arena, st);
        __auto_type views = (((int64_t)((vw).len)) > 0);
        __auto_type ixs = howl_sriqsat_all_ixs(arena, env, st, dl, perm, vw);
        __auto_type rs = howl_sriqsat_rsrcs_of(arena, env, st, dl);
        __auto_type cands = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type succs = ((slop_list_howl_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type rsuccs = ((slop_list_howl_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type noms = ((slop_list_howl_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        int64_t tried = 0;
        uint8_t big = 0;
        {
            __auto_type _coll = howl_sriqsat_ctx_order(arena, ((int64_t)(((int64_t)((st.ctxs).len)))), perm);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type v = _coll.data[_i];
                __auto_type _mv_1372 = ({ __auto_type _lst = adj; size_t _idx = (size_t)v; slop_option_howl_sriqsat_Adj _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (!_mv_1372.has_value) {
                } else if (_mv_1372.has_value) {
                    __auto_type a = _mv_1372.value;
                    if (!(big)) {
                        {
                            __auto_type cr = howl_sriqsat_sat_ctx(arena, env, hx, ixs, rs, st, dl, gd, a, v, perm, dfr, views, (room - ((int64_t)(((int64_t)((cands).len))))));
                            __auto_type r = cr.r;
                            tried = (tried + cr.tried);
                            {
                                __auto_type _coll = r.cands;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type x = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(cands); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                            {
                                __auto_type _coll = r.succs;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type x = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(succs); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                            {
                                __auto_type _coll = r.rsuccs;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type x = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(rsuccs); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                            {
                                __auto_type _coll = r.noms;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type x = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(noms); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                            if (r.over) {
                                over = 1;
                            }
                            if (howl_sriqsat_passes(cr, cands, room)) {
                                big = 1;
                            }
                        }
                    }
                }
            }
        }
        return ((howl_sriqsat_CRound){.r = howl_sriqref_round_of(cands, succs, rsuccs, noms, over), .tried = tried, .big = big});
    }
}

slop_list_howl_sriqref_Cand howl_sriqsat_new_cores(slop_arena* arena, howl_sriqctx_Structure st, int64_t from) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        {
            __auto_type _coll = st.ctxs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (v >= from) {
                    {
                        __auto_type _coll = howl_sriqref_ref_core(arena, ((uint32_t)(v)), c.core);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type x = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
                v = (v + 1);
            }
        }
        return out;
    }
}

howl_sriqsat_Step howl_sriqsat_sat_apply(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqground_Ground gd, howl_sriqref_Round r, uint8_t scan, uint8_t dfr, slop_list_howl_sriqsat_Supply trig, slop_list_howl_sriqsat_Flags fl) {
    {
        __auto_type sup = ((dfr) ? howl_sriqsat_supplied(arena, trig, r.succs) : ((howl_sriqsat_Supplied){.trig = trig, .evals = ((slop_list_howl_sriqsat_Supply){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .grew = 0}));
        __auto_type n0 = howl_sriqref_consts_of(st);
        __auto_type c0 = ((int64_t)(((int64_t)((st.ctxs).len))));
        __auto_type e0 = ((int64_t)(((int64_t)((st.edges).len))));
        __auto_type s1 = ((howl_sriqctx_Structure){.ctxs = st.ctxs, .sets = st.sets, .edges = st.edges, .ord = howl_sriqref_add_consts(arena, st.ord, r.noms)});
        __auto_type s2 = howl_sriqref_add_contexts(arena, s1, r.succs);
        __auto_type s3 = ((scan) ? howl_sriqref_add_edges(arena, s2, r.succs, r.rsuccs) : howl_sriqsat_edges_added(arena, s2, r.succs, r.rsuccs));
        __auto_type cands = howl_sriqref_append_cands(arena, howl_sriqref_append_cands(arena, r.cands, howl_sriqsat_succ_cands(arena, s3, r, sup, dfr)), howl_sriqsat_new_cores(arena, s3, c0));
        __auto_type sp = howl_sriqsat_commit_all(arena, s3, howl_sriqsat_outside_view(arena, s3, gd, cands), c0, e0, n0, scan, fl);
        if (dfr) {
            return howl_sriqsat_deferred_step(arena, sp, e0, trig, sup);
        } else {
            return sp;
        }
    }
}

slop_list_howl_sriqref_Cand howl_sriqsat_succ_cands(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqref_Round r, howl_sriqsat_Supplied sup, uint8_t dfr) {
    if (dfr) {
        return howl_sriqref_append_cands(arena, howl_sriqref_action_cands(arena, st, ((slop_list_howl_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), r.rsuccs), howl_sriqsat_pushed(arena, st, sup.evals));
    } else {
        return howl_sriqref_action_cands(arena, st, r.succs, r.rsuccs);
    }
}

howl_sriqctx_Structure howl_sriqsat_edges_added(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqref_SuccAct succs, slop_list_howl_sriqref_RSuccAct rsuccs) {
    {
        __auto_type news = howl_sriqsat_action_edges(arena, st, succs, rsuccs);
        __auto_type es = ((slop_list_howl_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(es); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = howl_sriqsat_first_new(arena, st.edges, news);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(es); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ((howl_sriqctx_Structure){.ctxs = st.ctxs, .sets = st.sets, .edges = es, .ord = st.ord});
    }
}

slop_list_howl_sriqctx_Edge howl_sriqsat_action_edges(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqref_SuccAct succs, slop_list_howl_sriqref_RSuccAct rsuccs) {
    {
        __auto_type out = ((slop_list_howl_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = succs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    __auto_type w = howl_sriqctx_ctx_by_core(st, a.core);
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqctx_Edge){.from = a.from, .to = w, .lk = howl_sriqctx_EdgeLabel_el_fn, .label = a.sg.f})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    if (a.sg.root) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqctx_Edge){.from = a.from, .to = w, .lk = howl_sriqctx_EdgeLabel_el_const, .label = a.sg.u})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        {
            __auto_type _coll = rsuccs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqctx_Edge){.from = a.from, .to = ((uint32_t)(0)), .lk = howl_sriqctx_EdgeLabel_el_const, .label = a.u})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_sriqctx_Edge howl_sriqsat_first_new(slop_arena* arena, slop_list_howl_sriqctx_Edge old, slop_list_howl_sriqctx_Edge news) {
    __auto_type _mv_1373 = ({ __auto_type _lst = news; size_t _idx = (size_t)0; slop_option_howl_sriqctx_Edge _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1373.has_value) {
        return ((slop_list_howl_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    } else if (_mv_1373.has_value) {
        __auto_type e0 = _mv_1373.value;
        return howl_sriqsat_in_news_order(arena, news, howl_sriqsat_kept_positions(arena, old, news, e0), e0);
    }
    SLOP_UNREACHABLE();
}

slop_list_int howl_sriqsat_kept_positions(slop_arena* arena, slop_list_howl_sriqctx_Edge old, slop_list_howl_sriqctx_Edge news, howl_sriqctx_Edge e0) {
    {
        __auto_type oidx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((old).len)))), ({ howl_sriqsat__lambda_1374_env_t* howl_sriqsat__lambda_1374_env = (howl_sriqsat__lambda_1374_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqsat__lambda_1374_env_t)); *howl_sriqsat__lambda_1374_env = (howl_sriqsat__lambda_1374_env_t){ .old = old, .e0 = e0 }; (slop_closure_t){ (void*)howl_sriqsat__lambda_1374, (void*)howl_sriqsat__lambda_1374_env }; }));
        __auto_type nidx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((news).len)))), ({ howl_sriqsat__lambda_1375_env_t* howl_sriqsat__lambda_1375_env = (howl_sriqsat__lambda_1375_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqsat__lambda_1375_env_t)); *howl_sriqsat__lambda_1375_env = (howl_sriqsat__lambda_1375_env_t){ .news = news, .e0 = e0 }; (slop_closure_t){ (void*)howl_sriqsat__lambda_1375, (void*)howl_sriqsat__lambda_1375_env }; }));
        __auto_type keep = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t prev = -1;
        {
            __auto_type _coll = nidx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                if (howl_sriqsat_run_first_new(old, oidx, news, prev, k, e0)) {
                    (void)(({ __auto_type _lst_p = &(keep); __auto_type _item = (k); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                prev = k;
            }
        }
        return keep;
    }
}

uint8_t howl_sriqsat_run_first_new(slop_list_howl_sriqctx_Edge old, slop_list_int oidx, slop_list_howl_sriqctx_Edge news, int64_t prev, int64_t k, howl_sriqctx_Edge e0) {
    {
        __auto_type e = howl_sriqsat_edge_at(news, k, e0);
        return (((prev < 0) || (howl_sriqsat_edge_cmp(howl_sriqsat_edge_at(news, prev, e0), e) != 0)) && !(howl_sriqsat_edge_in(old, oidx, e, e0)));
    }
}

slop_list_howl_sriqctx_Edge howl_sriqsat_in_news_order(slop_arena* arena, slop_list_howl_sriqctx_Edge news, slop_list_int keep, howl_sriqctx_Edge e0) {
    {
        __auto_type out = ((slop_list_howl_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((keep).len)))), ({ howl_sriqsat__lambda_1376_env_t* howl_sriqsat__lambda_1376_env = (howl_sriqsat__lambda_1376_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqsat__lambda_1376_env_t)); *howl_sriqsat__lambda_1376_env = (howl_sriqsat__lambda_1376_env_t){ .keep = keep }; (slop_closure_t){ (void*)howl_sriqsat__lambda_1376, (void*)howl_sriqsat__lambda_1376_env }; }));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqsat_edge_at(news, howl_sriqsat_idx_at(keep, k), e0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

uint8_t howl_sriqsat_edge_in(slop_list_howl_sriqctx_Edge es, slop_list_int idx, howl_sriqctx_Edge e, howl_sriqctx_Edge e0) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((idx).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                if (howl_sriqsat_edge_cmp(howl_sriqsat_edge_at(es, howl_sriqsat_idx_at(idx, mid), e0), e) < 0) {
                    lo = (mid + 1);
                } else {
                    hi = mid;
                }
            }
        }
        return ((lo < ((int64_t)(((int64_t)((idx).len))))) && (howl_sriqsat_edge_cmp(howl_sriqsat_edge_at(es, howl_sriqsat_idx_at(idx, lo), e0), e) == 0));
    }
}

int64_t howl_sriqsat_edge_cmp(howl_sriqctx_Edge a, howl_sriqctx_Edge b) {
    if (a.from != b.from) {
        return howl_sriqsat_u32_cmp(a.from, b.from);
    } else if (a.to != b.to) {
        return howl_sriqsat_u32_cmp(a.to, b.to);
    } else if (howl_sriqsat_lk_rank(a.lk) != howl_sriqsat_lk_rank(b.lk)) {
        return howl_sriqsat_int_cmp(howl_sriqsat_lk_rank(a.lk), howl_sriqsat_lk_rank(b.lk));
    } else {
        return howl_sriqsat_u32_cmp(a.label, b.label);
    }
}

int64_t howl_sriqsat_lk_rank(howl_sriqctx_EdgeLabel lk) {
    __auto_type _mv_1377 = lk;
    if (_mv_1377 == howl_sriqctx_EdgeLabel_el_fn) {
        return 0;
    } else if (_mv_1377 == howl_sriqctx_EdgeLabel_el_const) {
        return 1;
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqsat_int_cmp(int64_t a, int64_t b) {
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    } else {
        return 0;
    }
}

slop_list_howl_sriqref_Cand howl_sriqsat_outside_view(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqground_Ground gd, slop_list_howl_sriqref_Cand cands) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cands;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (howl_sriqref_is_root(st, ((int64_t)(c.ctx))) || !(howl_sriqground_g_in_hat(gd, c.c))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

howl_sriqsat_Step howl_sriqsat_commit_all(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqref_Cand cands, int64_t c0, int64_t e0, int64_t n0, uint8_t scan, slop_list_howl_sriqsat_Flags fl) {
    {
        __auto_type none_such = ((howl_sriqref_Cand){.ctx = ((uint32_t)(0)), .c = ((howl_types_Clause){.body = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .head = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })})});
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((cands).len)))), ({ howl_sriqsat__lambda_1378_env_t* howl_sriqsat__lambda_1378_env = (howl_sriqsat__lambda_1378_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqsat__lambda_1378_env_t)); *howl_sriqsat__lambda_1378_env = (howl_sriqsat__lambda_1378_env_t){ .cands = cands, .none_such = none_such }; (slop_closure_t){ (void*)howl_sriqsat__lambda_1378, (void*)howl_sriqsat__lambda_1378_env }; }));
        __auto_type sets = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type news = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type olds = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type nfl = ((slop_list_howl_sriqsat_Flags){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type none_fs = ((slop_list_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        int64_t v = 0;
        uint8_t grew = 0;
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                {
                    __auto_type mine = howl_sriqsat_run_of(arena, cands, idx, k, ((uint32_t)(v)), none_such);
                    {
                        __auto_type cm = howl_sriqsat_commit_one(arena, s.cs, mine, scan);
                        (void)(({ __auto_type _lst_p = &(sets); __auto_type _item = (((howl_sriqctx_CtxSet){.cs = cm.set})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        (void)(({ __auto_type _lst_p = &(nfl); __auto_type _item = (((howl_sriqsat_Flags){.fs = howl_sriqsat_new_flags(arena, st.ord, s.cs, howl_sriqsat_fs_at(fl, v, none_fs), cm, ((int64_t)((mine).len)))})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        (void)(({ __auto_type _lst_p = &(news); __auto_type _item = (((howl_sriqctx_CtxSet){.cs = cm.added})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        (void)(({ __auto_type _lst_p = &(olds); __auto_type _item = (((howl_sriqctx_CtxSet){.cs = howl_sriqsat_minus_sorted(arena, cm.set, cm.added)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        if (((int64_t)((cm.added).len)) > 0) {
                            grew = 1;
                        }
                        k = (k + ((int64_t)(((int64_t)((mine).len)))));
                        v = (v + 1);
                    }
                }
            }
        }
        return ((howl_sriqsat_Step){.st = ((howl_sriqctx_Structure){.ctxs = st.ctxs, .sets = sets, .edges = st.edges, .ord = st.ord}), .dl = ((howl_sriqsat_Delta){.news = news, .olds = olds, .edges = howl_sriqsat_edges_from(arena, st.edges, e0), .nctx = c0, .ncst = n0}), .changed = ((grew) || ((((int64_t)(((int64_t)((st.ctxs).len)))) != c0)) || ((((int64_t)(((int64_t)((st.edges).len)))) != e0)) || ((howl_sriqref_consts_of(st) != n0))), .trig = ((slop_list_howl_sriqsat_Supply){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .acts = 0, .flags = nfl});
    }
}

slop_list_list_u8 howl_sriqsat_new_flags(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Clause ws, slop_list_list_u8 wf, howl_sriqsubsume_Committed cm, int64_t ncands) {
    if (ncands == 0) {
        return wf;
    } else {
        return howl_sriqsat_walked_flags(arena, ord, ws, wf, cm.set);
    }
}

slop_list_howl_types_Clause howl_sriqsat_run_of(slop_arena* arena, slop_list_howl_sriqref_Cand cands, slop_list_int idx, int64_t k, uint32_t v, howl_sriqref_Cand none_such) {
    {
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = k;
        uint8_t going = 1;
        while (going && (i < ((int64_t)(((int64_t)((idx).len)))))) {
            {
                __auto_type x = howl_sriqref_cand_at(cands, howl_sriqsat_idx_at(idx, i), none_such);
                if (x.ctx == v) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x.c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    i = (i + 1);
                } else {
                    going = 0;
                }
            }
        }
        return out;
    }
}

howl_sriqsubsume_Committed howl_sriqsat_commit_one(slop_arena* arena, slop_list_howl_types_Clause ws, slop_list_howl_types_Clause cs, uint8_t scan) {
    if (((int64_t)((cs).len)) == 0) {
        return ((howl_sriqsubsume_Committed){.set = ws, .added = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
    } else if (scan) {
        return howl_sriqsubsume_commit_min(arena, ws, cs);
    } else {
        return howl_sriqindex_commit_indexed(arena, ws, cs);
    }
}

slop_list_howl_types_Clause howl_sriqsat_minus_sorted(slop_arena* arena, slop_list_howl_types_Clause xs, slop_list_howl_types_Clause ys) {
    {
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                __auto_type _mv_1379 = ({ __auto_type _lst = ys; size_t _idx = (size_t)j; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1379.has_value) {
                    __auto_type y = _mv_1379.value;
                    if (howl_sriqclauses_clause_cmp(x, y) == 0) {
                        j = (j + 1);
                    } else {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                } else if (!_mv_1379.has_value) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

slop_list_howl_sriqctx_Edge howl_sriqsat_edges_from(slop_arena* arena, slop_list_howl_sriqctx_Edge es, int64_t k) {
    {
        __auto_type out = ((slop_list_howl_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = es;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (i >= k) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                i = (i + 1);
            }
        }
        return out;
    }
}

slop_list_howl_sriqsat_View howl_sriqsat_views_of(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqsat_Flags fl) {
    {
        __auto_type out = ((slop_list_howl_sriqsat_View){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        __auto_type none_fs = ((slop_list_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqsat_View){.cs = x.cs, .fs = ({ __auto_type _mv = ({ __auto_type _lst = fl; size_t _idx = (size_t)v; slop_option_howl_sriqsat_Flags _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type f = _mv.value; f.fs; }) : (none_fs); })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                v = (v + 1);
            }
        }
        return out;
    }
}

slop_list_howl_sriq_Premise howl_sriqsat_premises_in(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqsat_View vw, int64_t v, slop_list_howl_types_Clause cs) {
    __auto_type _mv_1380 = ({ __auto_type _lst = vw; size_t _idx = (size_t)v; slop_option_howl_sriqsat_View _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1380.has_value) {
        return howl_sriqref_premises_of(arena, st.ord, cs);
    } else if (_mv_1380.has_value) {
        __auto_type w = _mv_1380.value;
        {
            __auto_type out = ((slop_list_howl_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = cs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    {
                        __auto_type _coll = howl_sriqsat_clause_premises(arena, c, howl_sriqsat_flags_of(arena, st.ord, w, c));
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type p = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
            return out;
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_sriq_Premise howl_sriqsat_clause_premises(slop_arena* arena, howl_types_Clause c, slop_list_u8 fs) {
    {
        __auto_type out = ((slop_list_howl_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = c.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriq_Premise){.body = c.body, .sel = l, .rest = howl_sriqsat_head_without(arena, c.head, i), .maxed = howl_sriqsat_flag_at(fs, i)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                i = (i + 1);
            }
        }
        return out;
    }
}

slop_list_howl_types_Lit howl_sriqsat_head_without(slop_arena* arena, slop_list_howl_types_Lit xs, int64_t i) {
    {
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (k != i) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                k = (k + 1);
            }
        }
        return out;
    }
}

uint8_t howl_sriqsat_flag_at(slop_list_u8 fs, int64_t i) {
    __auto_type _mv_1381 = ({ __auto_type _lst = fs; size_t _idx = (size_t)i; slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1381.has_value) {
        __auto_type b = _mv_1381.value;
        return b;
    } else if (!_mv_1381.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_list_u8 howl_sriqsat_flags_of(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriqsat_View w, howl_types_Clause c) {
    {
        __auto_type k = howl_sriqsat_clause_pos(w.cs, c);
        __auto_type _mv_1382 = ({ __auto_type _lst = w.fs; size_t _idx = (size_t)k; slop_option_list_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1382.has_value) {
            __auto_type fs = _mv_1382.value;
            if (howl_sriqsat_sorted_at(w.cs, k, c)) {
                return fs;
            } else {
                return howl_sriqorder_max_flags(arena, ord, c.head);
            }
        } else if (!_mv_1382.has_value) {
            return howl_sriqorder_max_flags(arena, ord, c.head);
        }
        SLOP_UNREACHABLE();
    }
}

int64_t howl_sriqsat_clause_pos(slop_list_howl_types_Clause cs, howl_types_Clause c) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((cs).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                __auto_type _mv_1383 = ({ __auto_type _lst = cs; size_t _idx = (size_t)mid; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1383.has_value) {
                    __auto_type x = _mv_1383.value;
                    if (howl_sriqclauses_clause_cmp(x, c) < 0) {
                        lo = (mid + 1);
                    } else {
                        hi = mid;
                    }
                } else if (!_mv_1383.has_value) {
                    hi = mid;
                }
            }
        }
        return lo;
    }
}

uint8_t howl_sriqsat_sorted_at(slop_list_howl_types_Clause cs, int64_t k, howl_types_Clause c) {
    __auto_type _mv_1384 = ({ __auto_type _lst = cs; size_t _idx = (size_t)k; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1384.has_value) {
        __auto_type x = _mv_1384.value;
        return (howl_sriqclauses_clause_cmp(x, c) == 0);
    } else if (!_mv_1384.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_list_list_u8 howl_sriqsat_walked_flags(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Clause ws, slop_list_list_u8 wf, slop_list_howl_types_Clause set) {
    {
        __auto_type out = ((slop_list_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        {
            __auto_type _coll = set;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                while (howl_sriqsat_below_at(ws, j, c)) {
                    j = (j + 1);
                }
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqsat_sorted_at(ws, j, c)) ? ({ __auto_type _mv = ({ __auto_type _lst = wf; size_t _idx = (size_t)j; slop_option_list_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type f = _mv.value; f; }) : (howl_sriqorder_max_flags(arena, ord, c.head)); }) : howl_sriqorder_max_flags(arena, ord, c.head))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

uint8_t howl_sriqsat_below_at(slop_list_howl_types_Clause cs, int64_t j, howl_types_Clause c) {
    __auto_type _mv_1385 = ({ __auto_type _lst = cs; size_t _idx = (size_t)j; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1385.has_value) {
        __auto_type w = _mv_1385.value;
        return (howl_sriqclauses_clause_cmp(w, c) < 0);
    } else if (!_mv_1385.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_list_list_u8 howl_sriqsat_fs_at(slop_list_howl_sriqsat_Flags fl, int64_t v, slop_list_list_u8 none_fs) {
    __auto_type _mv_1386 = ({ __auto_type _lst = fl; size_t _idx = (size_t)v; slop_option_howl_sriqsat_Flags _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1386.has_value) {
        __auto_type f = _mv_1386.value;
        return f.fs;
    } else if (!_mv_1386.has_value) {
        return none_fs;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_sriqsat_Flags howl_sriqsat_empty_flags(slop_arena* arena, howl_sriqctx_Structure st) {
    {
        __auto_type out = ((slop_list_howl_sriqsat_Flags){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqsat_Flags){.fs = howl_sriqsat_walked_flags(arena, st.ord, ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), x.cs)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_sriqsat_Flags howl_sriqsat_copy_flags(slop_arena* arena, slop_list_howl_sriqsat_Flags fl) {
    {
        __auto_type out = ((slop_list_howl_sriqsat_Flags){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = fl;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                {
                    __auto_type fs = ((slop_list_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    {
                        __auto_type _coll = f.fs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type x = _coll.data[_i];
                            {
                                __auto_type b = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                                {
                                    __auto_type _coll = x;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type y = _coll.data[_i];
                                        (void)(({ __auto_type _lst_p = &(b); __auto_type _item = (y); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                    }
                                }
                                (void)(({ __auto_type _lst_p = &(fs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                        }
                    }
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqsat_Flags){.fs = fs})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

int64_t howl_sriqsat_stale_flags(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqsat_Flags fl) {
    {
        int64_t n = 0;
        int64_t v = 0;
        __auto_type none_fs = ((slop_list_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                n = (n + howl_sriqsat_stale_in(arena, st.ord, x.cs, howl_sriqsat_fs_at(fl, v, none_fs)));
                v = (v + 1);
            }
        }
        return n;
    }
}

int64_t howl_sriqsat_stale_in(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Clause cs, slop_list_list_u8 fs) {
    {
        int64_t n = (((((int64_t)((fs).len)) == ((int64_t)((cs).len)))) ? 0 : 1);
        int64_t k = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(howl_sriqsat_same_flags(({ __auto_type _mv = ({ __auto_type _lst = fs; size_t _idx = (size_t)k; slop_option_list_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type f = _mv.value; f; }) : (((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena })); }), howl_sriqorder_max_flags(arena, ord, c.head)))) {
                    n = (n + 1);
                }
                k = (k + 1);
            }
        }
        return n;
    }
}

uint8_t howl_sriqsat_same_flags(slop_list_u8 a, slop_list_u8 b) {
    {
        uint8_t ok = (((int64_t)((a).len)) == ((int64_t)((b).len)));
        int64_t i = 0;
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (x != howl_sriqsat_flag_at(b, i)) {
                    ok = 0;
                }
                i = (i + 1);
            }
        }
        return ok;
    }
}

uint8_t howl_sriqsat_defer_on(howl_sriqsat_SatConfig cfg, howl_sriqref_RefIn in) {
    return ((cfg.defer) && ((in.nconst == 0)) && (!((cfg.base.strat == howl_sriqctx_Strategy_st_eager))));
}

int64_t howl_sriqsat_key_cmp(uint32_t w1, uint32_t f1, uint32_t w2, uint32_t f2) {
    if (w1 != w2) {
        return howl_sriqsat_u32_cmp(w1, w2);
    } else {
        return howl_sriqsat_u32_cmp(f1, f2);
    }
}

int64_t howl_sriqsat_supply_cmp(howl_sriqsat_Supply a, howl_sriqsat_Supply b) {
    return howl_sriqsat_key_cmp(a.from, a.f, b.from, b.f);
}

howl_sriqsat_Supply howl_sriqsat_supply_at(slop_list_howl_sriqsat_Supply xs, int64_t k, howl_sriqsat_Supply fallback) {
    __auto_type _mv_1387 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_howl_sriqsat_Supply _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1387.has_value) {
        __auto_type x = _mv_1387.value;
        return x;
    } else if (!_mv_1387.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Lit howl_sriqsat_supply_of(slop_list_howl_sriqsat_Supply trig, uint32_t w, uint32_t f, slop_list_howl_types_Lit nolits) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((trig).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                __auto_type _mv_1388 = ({ __auto_type _lst = trig; size_t _idx = (size_t)mid; slop_option_howl_sriqsat_Supply _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1388.has_value) {
                    __auto_type x = _mv_1388.value;
                    if (howl_sriqsat_key_cmp(x.from, x.f, w, f) < 0) {
                        lo = (mid + 1);
                    } else {
                        hi = mid;
                    }
                } else if (!_mv_1388.has_value) {
                    hi = mid;
                }
            }
        }
        __auto_type _mv_1389 = ({ __auto_type _lst = trig; size_t _idx = (size_t)lo; slop_option_howl_sriqsat_Supply _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1389.has_value) {
            __auto_type x = _mv_1389.value;
            if (howl_sriqsat_key_cmp(x.from, x.f, w, f) == 0) {
                return x.lits;
            } else {
                return nolits;
            }
        } else if (!_mv_1389.has_value) {
            return nolits;
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t howl_sriqsat_lit_member(slop_list_howl_types_Lit ls, howl_types_Lit l) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((ls).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                __auto_type _mv_1390 = ({ __auto_type _lst = ls; size_t _idx = (size_t)mid; slop_option_howl_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1390.has_value) {
                    __auto_type x = _mv_1390.value;
                    if (howl_types_lit_cmp(x, l) < 0) {
                        lo = (mid + 1);
                    } else {
                        hi = mid;
                    }
                } else if (!_mv_1390.has_value) {
                    hi = mid;
                }
            }
        }
        __auto_type _mv_1391 = ({ __auto_type _lst = ls; size_t _idx = (size_t)lo; slop_option_howl_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1391.has_value) {
            __auto_type x = _mv_1391.value;
            return (howl_types_lit_cmp(x, l) == 0);
        } else if (!_mv_1391.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t howl_sriqsat_body_within(howl_types_Clause c, slop_list_howl_types_Lit core, slop_list_howl_types_Lit lits) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!((howl_sriqsat_lit_member(core, l) || howl_sriqsat_lit_member(lits, l)))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t howl_sriqsat_supported(howl_types_Clause c, slop_list_howl_types_Lit core, slop_list_howl_sriqctx_Edge ins, slop_list_howl_sriqsat_Supply trig, slop_list_howl_types_Lit nolits) {
    {
        uint8_t ok = howl_sriqsat_body_within(c, core, nolits);
        {
            __auto_type _coll = ins;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if ((!(ok)) && ((e.lk == howl_sriqctx_EdgeLabel_el_fn)) && (howl_sriqsat_body_within(c, core, howl_sriqsat_supply_of(trig, e.from, e.label, nolits)))) {
                    ok = 1;
                }
            }
        }
        return ok;
    }
}

slop_list_howl_sriqctx_Edge howl_sriqsat_ins_at(slop_arena* arena, slop_list_howl_sriqsat_Adj adj, int64_t v) {
    __auto_type _mv_1392 = ({ __auto_type _lst = adj; size_t _idx = (size_t)v; slop_option_howl_sriqsat_Adj _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1392.has_value) {
        __auto_type a = _mv_1392.value;
        return a.ins;
    } else if (!_mv_1392.has_value) {
        return ((slop_list_howl_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

howl_sriqsat_Seen howl_sriqsat_projected(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, slop_list_howl_sriqsat_Supply trig) {
    {
        __auto_type adj = howl_sriqsat_adjacency(arena, st);
        __auto_type nolits = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type nobody = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type sets = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type news = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type olds = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        {
            __auto_type _coll = st.ctxs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type ins = howl_sriqsat_ins_at(arena, adj, v);
                    (void)(({ __auto_type _lst_p = &(sets); __auto_type _item = (howl_sriqsat_narrowed(arena, howl_sriqsat_cs_at(st.sets, v, nobody), c, ins, trig, nolits)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    (void)(({ __auto_type _lst_p = &(news); __auto_type _item = (howl_sriqsat_narrowed(arena, howl_sriqsat_cs_at(dl.news, v, nobody), c, ins, trig, nolits)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    (void)(({ __auto_type _lst_p = &(olds); __auto_type _item = (howl_sriqsat_narrowed(arena, howl_sriqsat_cs_at(dl.olds, v, nobody), c, ins, trig, nolits)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    v = (v + 1);
                }
            }
        }
        return ((howl_sriqsat_Seen){.st = ((howl_sriqctx_Structure){.ctxs = st.ctxs, .sets = sets, .edges = st.edges, .ord = st.ord}), .dl = ((howl_sriqsat_Delta){.news = news, .olds = olds, .edges = dl.edges, .nctx = dl.nctx, .ncst = dl.ncst})});
    }
}

howl_sriqctx_CtxSet howl_sriqsat_narrowed(slop_arena* arena, slop_list_howl_types_Clause cs, howl_sriqctx_Ctx c, slop_list_howl_sriqctx_Edge ins, slop_list_howl_sriqsat_Supply trig, slop_list_howl_types_Lit nolits) {
    if (c.root) {
        return ((howl_sriqctx_CtxSet){.cs = cs});
    } else {
        {
            __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = cs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type x = _coll.data[_i];
                    if (howl_sriqsat_supported(x, c.core, ins, trig, nolits)) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
            return ((howl_sriqctx_CtxSet){.cs = out});
        }
    }
}

howl_sriqsat_Supplied howl_sriqsat_supplied(slop_arena* arena, slop_list_howl_sriqsat_Supply trig, slop_list_howl_sriqref_SuccAct succs) {
    {
        __auto_type raw = ((slop_list_howl_sriqsat_Supply){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = trig;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(raw); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = succs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(raw); __auto_type _item = (((howl_sriqsat_Supply){.from = a.from, .f = a.sg.f, .lits = a.adds})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        __auto_type _mv_1393 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_howl_sriqsat_Supply _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1393.has_value) {
            return ((howl_sriqsat_Supplied){.trig = trig, .evals = ((slop_list_howl_sriqsat_Supply){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .grew = 0});
        } else if (_mv_1393.has_value) {
            __auto_type s0 = _mv_1393.value;
            return howl_sriqsat_supplies_merged(arena, raw, ((int64_t)(((int64_t)((trig).len)))), s0);
        }
        SLOP_UNREACHABLE();
    }
}

howl_sriqsat_Supplied howl_sriqsat_supplies_merged(slop_arena* arena, slop_list_howl_sriqsat_Supply raw, int64_t nold, howl_sriqsat_Supply s0) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ howl_sriqsat__lambda_1394_env_t* howl_sriqsat__lambda_1394_env = (howl_sriqsat__lambda_1394_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqsat__lambda_1394_env_t)); *howl_sriqsat__lambda_1394_env = (howl_sriqsat__lambda_1394_env_t){ .raw = raw, .s0 = s0 }; (slop_closure_t){ (void*)howl_sriqsat__lambda_1394, (void*)howl_sriqsat__lambda_1394_env }; }));
        __auto_type trig = ((slop_list_howl_sriqsat_Supply){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type evals = ((slop_list_howl_sriqsat_Supply){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t grew = 0;
        int64_t k = 0;
        while (k < ((int64_t)(((int64_t)((idx).len))))) {
            {
                __auto_type g = howl_sriqsat_supply_group(arena, raw, idx, k, nold, s0);
                (void)(({ __auto_type _lst_p = &(trig); __auto_type _item = (g.s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                if (g.evald) {
                    (void)(({ __auto_type _lst_p = &(evals); __auto_type _item = (g.s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                if (g.grew) {
                    grew = 1;
                }
                k = g.next;
            }
        }
        return ((howl_sriqsat_Supplied){.trig = trig, .evals = evals, .grew = grew});
    }
}

howl_sriqsat_Group howl_sriqsat_supply_group(slop_arena* arena, slop_list_howl_sriqsat_Supply raw, slop_list_int idx, int64_t k, int64_t nold, howl_sriqsat_Supply s0) {
    {
        __auto_type first = howl_sriqsat_supply_at(raw, howl_sriqsat_idx_at(idx, k), s0);
        __auto_type lits = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t before = 0;
        uint8_t evald = 0;
        int64_t i = k;
        uint8_t going = 1;
        while (going && (i < ((int64_t)(((int64_t)((idx).len)))))) {
            {
                __auto_type j = howl_sriqsat_idx_at(idx, i);
                __auto_type x = howl_sriqsat_supply_at(raw, howl_sriqsat_idx_at(idx, i), s0);
                if (howl_sriqsat_supply_cmp(x, first) == 0) {
                    {
                        __auto_type _coll = x.lits;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type l = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(lits); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                    if (j < nold) {
                        before = ((int64_t)(((int64_t)((x.lits).len))));
                    } else {
                        evald = 1;
                    }
                    i = (i + 1);
                } else {
                    going = 0;
                }
            }
        }
        {
            __auto_type u = howl_sriqclauses_lit_set(arena, lits);
            return ((howl_sriqsat_Group){.s = ((howl_sriqsat_Supply){.from = first.from, .f = first.f, .lits = u}), .evald = evald, .grew = (((int64_t)(((int64_t)((u).len)))) > before), .next = i});
        }
    }
}

slop_list_howl_types_Lit howl_sriqsat_ctx_core(slop_arena* arena, howl_sriqctx_Structure st, uint32_t v) {
    __auto_type _mv_1395 = ({ __auto_type _lst = st.ctxs; size_t _idx = (size_t)((int64_t)(v)); slop_option_howl_sriqctx_Ctx _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1395.has_value) {
        __auto_type c = _mv_1395.value;
        return c.core;
    } else if (!_mv_1395.has_value) {
        return ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_sriqref_Cand howl_sriqsat_pushed(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqsat_Supply evals) {
    {
        __auto_type nolits = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (e.lk == howl_sriqctx_EdgeLabel_el_fn) {
                    {
                        __auto_type core = howl_sriqsat_ctx_core(arena, st, e.to);
                        {
                            __auto_type _coll = howl_sriqsat_supply_of(evals, e.from, e.label, nolits);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type a = _coll.data[_i];
                                if (!(howl_sriqsat_lit_member(core, a))) {
                                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqref_Cand){.ctx = e.to, .c = howl_sriqref_unit_clause(arena, a)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                }
                            }
                        }
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_sriqctx_Edge howl_sriqsat_edges_before(slop_arena* arena, slop_list_howl_sriqctx_Edge es, int64_t k) {
    {
        __auto_type out = ((slop_list_howl_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = es;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (i < k) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                i = (i + 1);
            }
        }
        return out;
    }
}

howl_sriqsat_Step howl_sriqsat_deferred_step(slop_arena* arena, howl_sriqsat_Step sp, int64_t e0, slop_list_howl_sriqsat_Supply old, howl_sriqsat_Supplied sup) {
    {
        __auto_type a = howl_sriqsat_activated(arena, sp.st, sp.dl, e0, old, sup.trig);
        return ((howl_sriqsat_Step){.st = sp.st, .dl = a.dl, .changed = (sp.changed || sup.grew), .trig = sup.trig, .acts = a.n, .flags = sp.flags});
    }
}

howl_sriqsat_Acted howl_sriqsat_activated(slop_arena* arena, howl_sriqctx_Structure st, howl_sriqsat_Delta dl, int64_t e0, slop_list_howl_sriqsat_Supply old, slop_list_howl_sriqsat_Supply trig) {
    {
        __auto_type was = ((howl_sriqctx_Structure){.ctxs = st.ctxs, .sets = st.sets, .edges = howl_sriqsat_edges_before(arena, st.edges, e0), .ord = st.ord});
        __auto_type adj = howl_sriqsat_adjacency(arena, st);
        __auto_type adj0 = howl_sriqsat_adjacency(arena, was);
        __auto_type nolits = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type nobody = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type news = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type olds = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t n = 0;
        int64_t v = 0;
        {
            __auto_type _coll = st.ctxs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type m = howl_sriqsat_acted_in(arena, c, howl_sriqsat_cs_at(dl.news, v, nobody), howl_sriqsat_cs_at(dl.olds, v, nobody), howl_sriqsat_ins_at(arena, adj, v), howl_sriqsat_ins_at(arena, adj0, v), old, trig, nolits);
                    (void)(({ __auto_type _lst_p = &(news); __auto_type _item = (((howl_sriqctx_CtxSet){.cs = m.news})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    (void)(({ __auto_type _lst_p = &(olds); __auto_type _item = (((howl_sriqctx_CtxSet){.cs = m.olds})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    n = (n + m.n);
                    v = (v + 1);
                }
            }
        }
        return ((howl_sriqsat_Acted){.dl = ((howl_sriqsat_Delta){.news = news, .olds = olds, .edges = dl.edges, .nctx = dl.nctx, .ncst = dl.ncst}), .n = n});
    }
}

howl_sriqsat_Moved howl_sriqsat_acted_in(slop_arena* arena, howl_sriqctx_Ctx c, slop_list_howl_types_Clause news, slop_list_howl_types_Clause olds, slop_list_howl_sriqctx_Edge ins, slop_list_howl_sriqctx_Edge ins0, slop_list_howl_sriqsat_Supply old, slop_list_howl_sriqsat_Supply trig, slop_list_howl_types_Lit nolits) {
    if (c.root || !(howl_sriqsat_ins_grew(ins, ins0, old, trig, nolits))) {
        return ((howl_sriqsat_Moved){.news = news, .olds = olds, .n = 0});
    } else {
        {
            __auto_type up = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            __auto_type rest = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = olds;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type x = _coll.data[_i];
                    if (howl_sriqsat_supported(x, c.core, ins, trig, nolits) && !(howl_sriqsat_supported(x, c.core, ins0, old, nolits))) {
                        (void)(({ __auto_type _lst_p = &(up); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    } else {
                        (void)(({ __auto_type _lst_p = &(rest); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
            return ((howl_sriqsat_Moved){.news = howl_sriqsat_merged_sorted(arena, news, up), .olds = rest, .n = ((int64_t)(((int64_t)((up).len))))});
        }
    }
}

uint8_t howl_sriqsat_ins_grew(slop_list_howl_sriqctx_Edge ins, slop_list_howl_sriqctx_Edge ins0, slop_list_howl_sriqsat_Supply old, slop_list_howl_sriqsat_Supply trig, slop_list_howl_types_Lit nolits) {
    {
        uint8_t grew = (((int64_t)((ins).len)) != ((int64_t)((ins0).len)));
        {
            __auto_type _coll = ins;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (((int64_t)((howl_sriqsat_supply_of(trig, e.from, e.label, nolits)).len)) > ((int64_t)((howl_sriqsat_supply_of(old, e.from, e.label, nolits)).len))) {
                    grew = 1;
                }
            }
        }
        return grew;
    }
}

slop_list_howl_types_Clause howl_sriqsat_merged_sorted(slop_arena* arena, slop_list_howl_types_Clause xs, slop_list_howl_types_Clause ys) {
    {
        __auto_type n = (((int64_t)(((int64_t)((xs).len)))) + ((int64_t)(((int64_t)((ys).len)))));
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        int64_t j = 0;
        while ((i + j) < n) {
            if (howl_sriqsat_y_first(xs, ys, i, j)) {
                __auto_type _mv_1396 = ({ __auto_type _lst = ys; size_t _idx = (size_t)j; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1396.has_value) {
                    __auto_type y = _mv_1396.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (y); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1396.has_value) {
                }
                j = (j + 1);
            } else {
                __auto_type _mv_1397 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1397.has_value) {
                    __auto_type x = _mv_1397.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1397.has_value) {
                }
                i = (i + 1);
            }
        }
        return out;
    }
}

uint8_t howl_sriqsat_y_first(slop_list_howl_types_Clause xs, slop_list_howl_types_Clause ys, int64_t i, int64_t j) {
    __auto_type _mv_1398 = ({ __auto_type _lst = ys; size_t _idx = (size_t)j; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1398.has_value) {
        return 0;
    } else if (_mv_1398.has_value) {
        __auto_type y = _mv_1398.value;
        __auto_type _mv_1399 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1399.has_value) {
            __auto_type x = _mv_1399.value;
            return (howl_sriqclauses_clause_cmp(y, x) < 0);
        } else if (!_mv_1399.has_value) {
            return 1;
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_sriqsat_Supply howl_sriqsat_copy_trig(slop_arena* arena, slop_list_howl_sriqsat_Supply trig) {
    {
        __auto_type out = ((slop_list_howl_sriqsat_Supply){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = trig;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                {
                    __auto_type ls = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    {
                        __auto_type _coll = x.lits;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type l = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(ls); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqsat_Supply){.from = x.from, .f = x.f, .lits = ls})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

howl_sriqsat_Delta howl_sriqsat_first_delta(slop_arena* arena, howl_sriqctx_Structure st) {
    {
        __auto_type news = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type olds = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(news); __auto_type _item = (((howl_sriqctx_CtxSet){.cs = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(olds); __auto_type _item = (((howl_sriqctx_CtxSet){.cs = s.cs})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ((howl_sriqsat_Delta){.news = news, .olds = olds, .edges = ((slop_list_howl_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .nctx = 0, .ncst = 0});
    }
}

howl_sriqsat_Delta howl_sriqsat_copy_delta(slop_arena* arena, howl_sriqsat_Delta dl) {
    {
        __auto_type news = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type olds = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type es = ((slop_list_howl_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = dl.news;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(news); __auto_type _item = (((howl_sriqctx_CtxSet){.cs = howl_sriqref_copy_clauses(arena, s.cs)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = dl.olds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(olds); __auto_type _item = (((howl_sriqctx_CtxSet){.cs = howl_sriqref_copy_clauses(arena, s.cs)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = dl.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(es); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ((howl_sriqsat_Delta){.news = news, .olds = olds, .edges = es, .nctx = dl.nctx, .ncst = dl.ncst});
    }
}

int64_t howl_sriqsat_into_v(slop_list_howl_sriqref_Cand cs, uint32_t v) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (c.ctx == v) {
                    n = (n + 1);
                }
            }
        }
        return n;
    }
}

int64_t howl_sriqsat_sum_added(howl_sriqsat_Delta dl) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = dl.news;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                n = (n + ((int64_t)(((int64_t)((s.cs).len)))));
            }
        }
        return n;
    }
}

howl_sriqsat_Counts howl_sriqsat_tally(howl_sriqsat_Counts c, howl_sriqref_Round r, howl_sriqsat_Delta dl, int64_t tried, int64_t acts, int64_t stale) {
    return ((howl_sriqsat_Counts){.cands = (c.cands + ((int64_t)(((int64_t)((r.cands).len))))), .rcands = (c.rcands + howl_sriqsat_into_v(r.cands, ((uint32_t)(0)))), .succs = (c.succs + ((int64_t)(((int64_t)((r.succs).len))))), .rsuccs = (c.rsuccs + ((int64_t)(((int64_t)((r.rsuccs).len))))), .noms = (c.noms + ((int64_t)(((int64_t)((r.noms).len))))), .added = (c.added + (howl_sriqsat_sum_added(dl) - acts)), .acts = (c.acts + acts), .hyper = (c.hyper + tried), .stale = (c.stale + stale)});
}

howl_sriqsat_Step howl_sriqsat_with_units(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqsat_Step sp) {
    {
        __auto_type st = sp.st;
        __auto_type dl = sp.dl;
        __auto_type nobody = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type gd = howl_sriqground_ground_of(arena, tr, st, howl_sriqsat_cs_at(dl.news, 0, nobody));
        __auto_type units = howl_sriqground_g_root_units(arena, tr, gd);
        if (((int64_t)((units).len)) == 0) {
            return sp;
        } else {
            {
                __auto_type cm = howl_sriqindex_commit_indexed(arena, howl_sriqsat_cs_at(st.sets, 0, nobody), units);
                if (((int64_t)((cm.added).len)) == 0) {
                    return sp;
                } else {
                    return ((howl_sriqsat_Step){.st = howl_sriqsat_with_root_set(arena, st, cm.set), .dl = howl_sriqsat_with_root_news(arena, dl, cm.set, cm.added, nobody), .changed = 1, .trig = sp.trig, .acts = sp.acts, .flags = howl_sriqsat_with_root_flags(arena, st.ord, howl_sriqsat_cs_at(st.sets, 0, nobody), sp.flags, cm.set)});
                }
            }
        }
    }
}

slop_list_howl_sriqsat_Flags howl_sriqsat_with_root_flags(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Clause ws, slop_list_howl_sriqsat_Flags fl, slop_list_howl_types_Clause set) {
    {
        __auto_type none_fs = ((slop_list_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type out = ((slop_list_howl_sriqsat_Flags){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        {
            __auto_type _coll = fl;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = ((((v == 0)) ? ((howl_sriqsat_Flags){.fs = howl_sriqsat_walked_flags(arena, ord, ws, howl_sriqsat_fs_at(fl, 0, none_fs), set)}) : f)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                v = (v + 1);
            }
        }
        return out;
    }
}

howl_sriqctx_Structure howl_sriqsat_with_root_set(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_types_Clause cs) {
    {
        __auto_type sets = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(sets); __auto_type _item = ((((v == 0)) ? ((howl_sriqctx_CtxSet){.cs = cs}) : s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                v = (v + 1);
            }
        }
        return ((howl_sriqctx_Structure){.ctxs = st.ctxs, .sets = sets, .edges = st.edges, .ord = st.ord});
    }
}

howl_sriqsat_Delta howl_sriqsat_with_root_news(slop_arena* arena, howl_sriqsat_Delta dl, slop_list_howl_types_Clause set, slop_list_howl_types_Clause added, slop_list_howl_types_Clause nobody) {
    {
        __auto_type was = howl_sriqsat_cs_at(dl.news, 0, nobody);
        __auto_type news = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type olds = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = set;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (howl_sriqsat_sorted_in(was, c) || howl_sriqsat_sorted_in(added, c)) {
                    (void)(({ __auto_type _lst_p = &(news); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                } else {
                    (void)(({ __auto_type _lst_p = &(olds); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return ((howl_sriqsat_Delta){.news = howl_sriqsat_with_first(arena, dl.news, news), .olds = howl_sriqsat_with_first(arena, dl.olds, olds), .edges = dl.edges, .nctx = dl.nctx, .ncst = dl.ncst});
    }
}

slop_list_howl_sriqctx_CtxSet howl_sriqsat_with_first(slop_arena* arena, slop_list_howl_sriqctx_CtxSet xs, slop_list_howl_types_Clause cs) {
    {
        __auto_type out = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = ((((v == 0)) ? ((howl_sriqctx_CtxSet){.cs = cs}) : x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                v = (v + 1);
            }
        }
        return out;
    }
}

uint8_t howl_sriqsat_sorted_in(slop_list_howl_types_Clause cs, howl_types_Clause c) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((cs).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                __auto_type _mv_1400 = ({ __auto_type _lst = cs; size_t _idx = (size_t)mid; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1400.has_value) {
                    __auto_type x = _mv_1400.value;
                    if (howl_sriqclauses_clause_cmp(x, c) < 0) {
                        lo = (mid + 1);
                    } else {
                        hi = mid;
                    }
                } else if (!_mv_1400.has_value) {
                    hi = mid;
                }
            }
        }
        __auto_type _mv_1401 = ({ __auto_type _lst = cs; size_t _idx = (size_t)lo; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1401.has_value) {
            __auto_type x = _mv_1401.value;
            return (howl_sriqclauses_clause_cmp(x, c) == 0);
        } else if (!_mv_1401.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

howl_sriqref_RefStatus howl_sriqsat_sat_stop(slop_arena* arena, howl_sriqref_Env env, howl_sriqctx_Structure st, uint8_t changed, howl_sriqref_RefConfig cfg) {
    if (!(changed)) {
        return howl_sriqref_RefStatus_rs_fixpoint;
    } else if (howl_sriqsat_holds_bot(arena, st, 1) || howl_sriqsat_holds_bot(arena, st, 0)) {
        return howl_sriqref_RefStatus_rs_inconsistent;
    } else if (((int64_t)(((int64_t)((st.ctxs).len)))) > cfg.ctxs) {
        return howl_sriqref_RefStatus_rs_contexts;
    } else if (howl_sriqground_view_total(st) > cfg.cls) {
        return howl_sriqref_RefStatus_rs_clauses;
    } else if ((howl_sriqref_consts_of(st) - env.nconst) > cfg.cnst) {
        return howl_sriqref_RefStatus_rs_constants;
    } else {
        return howl_sriqref_RefStatus_rs_fuel;
    }
}

uint8_t howl_sriqsat_holds_bot(slop_arena* arena, howl_sriqctx_Structure st, int64_t v) {
    __auto_type _mv_1402 = ({ __auto_type _lst = st.sets; size_t _idx = (size_t)v; slop_option_howl_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1402.has_value) {
        __auto_type s = _mv_1402.value;
        return howl_sriqsubsume_in_hat(howl_sriqclauses_make_clause(arena, ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })), s.cs);
    } else if (!_mv_1402.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

howl_sriqsat_Run howl_sriqsat_sat_once(slop_arena* next, slop_arena* scratch, howl_sriqref_Env env, howl_sriqhyper_HIdx hx, howl_sriqsat_SatConfig cfg, uint8_t dfr, howl_sriqsat_Run run) {
    {
        __auto_type gd = howl_sriqground_ground_of(scratch, env.tr, run.st, howl_sriqsat_cs_at(run.dl.news, 0, env.nobody));
        __auto_type seen = ((dfr) ? howl_sriqsat_projected(scratch, run.st, run.dl, run.trig) : ((howl_sriqsat_Seen){.st = run.st, .dl = run.dl}));
        __auto_type vw = ((cfg.views) ? howl_sriqsat_views_of(scratch, run.st, run.flags) : ((slop_list_howl_sriqsat_View){ .data = NULL, .len = 0, .cap = 0, .arena = scratch }));
        __auto_type sr = howl_sriqsat_sat_round(scratch, env, hx, seen.st, seen.dl, gd, cfg.perm, dfr, vw, (cfg.base.cls - howl_sriqground_view_total(run.st)));
        __auto_type r = sr.r;
        if (r.over || sr.big) {
            return ((howl_sriqsat_Run){.st = run.st, .dl = run.dl, .status = ((sr.big) ? howl_sriqref_RefStatus_rs_clauses : howl_sriqref_RefStatus_rs_product), .rounds = run.rounds, .going = 0, .trig = run.trig, .flags = run.flags, .counts = run.counts});
        } else {
            {
                __auto_type sp = howl_sriqsat_with_units(scratch, env.tr, howl_sriqsat_sat_apply(scratch, run.st, gd, r, cfg.scan, dfr, run.trig, run.flags));
                __auto_type st = howl_sriqref_copy_structure(next, sp.st);
                __auto_type stale = ((cfg.check) ? howl_sriqsat_stale_flags(scratch, sp.st, sp.flags) : 0);
                __auto_type status = howl_sriqsat_sat_stop(scratch, env, st, sp.changed, cfg.base);
                return ((howl_sriqsat_Run){.st = st, .dl = howl_sriqsat_copy_delta(next, sp.dl), .status = status, .rounds = (run.rounds + 1), .going = (status == howl_sriqref_RefStatus_rs_fuel), .trig = howl_sriqsat_copy_trig(next, sp.trig), .flags = howl_sriqsat_copy_flags(next, sp.flags), .counts = howl_sriqsat_tally(run.counts, r, sp.dl, sr.tried, sp.acts, stale)});
            }
        }
    }
}

howl_sriqctx_Structure howl_sriqsat_read_view(slop_arena* arena, howl_sriqctx_Structure st) {
    if (!(howl_sriqsat_holds_bot(arena, st, 0))) {
        return st;
    } else {
        {
            __auto_type sets = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            int64_t v = 0;
            {
                __auto_type _coll = st.sets;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type s = _coll.data[_i];
                    if (howl_sriqref_is_root(st, v)) {
                        (void)(({ __auto_type _lst_p = &(sets); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    } else {
                        {
                            __auto_type one = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                            (void)(({ __auto_type _lst_p = &(one); __auto_type _item = (howl_sriqclauses_make_clause(arena, ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            (void)(({ __auto_type _lst_p = &(sets); __auto_type _item = (((howl_sriqctx_CtxSet){.cs = one})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                    v = (v + 1);
                }
            }
            return ((howl_sriqctx_Structure){.ctxs = st.ctxs, .sets = sets, .edges = st.edges, .ord = st.ord});
        }
    }
}

howl_sriqctx_Structure howl_sriqsat_sat_materialise(slop_arena* arena, howl_sriqref_RefIn in, howl_sriqctx_Structure st) {
    return howl_sriqground_materialise(arena, howl_sriqctx_build_triggers(arena, in.onto, in.nclass, in.nrole, in.nfn), st);
}

uint8_t howl_sriqsat_defer_stable(slop_arena* arena, howl_sriqref_RefIn in, howl_sriqsat_SatConfig cfg, howl_sriqsat_SatResult p) {
    {
        __auto_type base = cfg.base;
        __auto_type tr = howl_sriqctx_build_triggers(arena, in.onto, in.nclass, in.nrole, in.nfn);
        __auto_type env = howl_sriqref_env_of(arena, in, base, tr, (((base.lam >= 0)) ? base.lam : howl_sriqref_ref_lambda(tr, base.strat, howl_sriqref_initial_queries(in))));
        __auto_type st = p.res.st;
        __auto_type r = howl_sriqref_ref_round(arena, env, howl_sriqsat_projected(arena, st, howl_sriqsat_first_delta(arena, st), p.trig).st);
        return ((!(r.over)) && (!(howl_sriqref_ref_apply(arena, st, r).changed)) && (howl_sriqsat_units_pushed(arena, st, p.trig)));
    }
}

uint8_t howl_sriqsat_units_pushed(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_sriqsat_Supply trig) {
    {
        __auto_type nolits = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type nobody = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t ok = 1;
        {
            __auto_type _coll = st.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (e.lk == howl_sriqctx_EdgeLabel_el_fn) {
                    {
                        __auto_type core = howl_sriqsat_ctx_core(arena, st, e.to);
                        __auto_type cs = howl_sriqsat_cs_at(st.sets, ((int64_t)(e.to)), nobody);
                        {
                            __auto_type _coll = howl_sriqsat_supply_of(trig, e.from, e.label, nolits);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type a = _coll.data[_i];
                                if (!((howl_sriqsat_lit_member(core, a) || howl_sriqsubsume_in_hat(howl_sriqref_unit_clause(arena, a), cs)))) {
                                    ok = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        return ok;
    }
}

uint8_t howl_sriqsat_hyper_ix_agrees(slop_arena* arena, howl_sriqref_RefIn in, howl_sriqsat_SatConfig cfg, howl_sriqctx_Structure st) {
    {
        __auto_type base = cfg.base;
        __auto_type tr = howl_sriqctx_build_triggers(arena, in.onto, in.nclass, in.nrole, in.nfn);
        __auto_type env = howl_sriqref_env_of(arena, in, base, tr, howl_sriqref_ref_lambda(tr, base.strat, howl_sriqref_initial_queries(in)));
        __auto_type hx = howl_sriqhyper_h_index(arena, in.onto);
        __auto_type gd = howl_sriqground_ground_of(arena, tr, st, env.nobody);
        __auto_type dl = howl_sriqsat_first_delta(arena, st);
        __auto_type ixs = howl_sriqsat_all_ixs(arena, env, st, dl, 0, ((slop_list_howl_sriqsat_View){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        __auto_type rs = howl_sriqsat_rsrcs_of(arena, env, st, dl);
        uint8_t ok = 1;
        int64_t v = 0;
        {
            __auto_type _coll = st.ctxs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(howl_sriqsat_hyper_ix_one(arena, env, hx, howl_sriqsat_here_of(arena, env, st, dl, gd, hx, ixs, rs, v, 0, 0, 0)))) {
                    ok = 0;
                }
                v = (v + 1);
            }
        }
        return ok;
    }
}

uint8_t howl_sriqsat_hyper_ix_one(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HIdx hx, howl_sriqsat_Here h) {
    {
        __auto_type mine = howl_sriqhyper_hyper_indexed(arena, env, hx, howl_sriqsat_hctx_of(h), howl_sriqsat_ROOM_OFF);
        __auto_type start = howl_sriq_hyper_start(arena, howl_types_at_x(), !(h.root));
        __auto_type theirs = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = mine.out.over;
        {
            __auto_type _coll = hx.bodied;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type oc = _coll.data[_i];
                {
                    __auto_type o = howl_sriqref_hyper_with(arena, env, h.v, h.root, start, oc, h.aps);
                    {
                        __auto_type _coll = o.cands;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(theirs); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                    if (o.over) {
                        over = 1;
                    }
                }
            }
        }
        return (over || howl_sriqsat_same_cands(arena, mine.out.cands, theirs));
    }
}

uint8_t howl_sriqsat_same_cands(slop_arena* arena, slop_list_howl_sriqref_Cand a, slop_list_howl_sriqref_Cand b) {
    {
        __auto_type x = howl_sriqsat_distinct_clauses(arena, a);
        __auto_type y = howl_sriqsat_distinct_clauses(arena, b);
        uint8_t ok = 1;
        int64_t i = 0;
        if (((int64_t)((x).len)) != ((int64_t)((y).len))) {
            ok = 0;
        }
        {
            __auto_type _coll = x;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                __auto_type _mv_1403 = ({ __auto_type _lst = y; size_t _idx = (size_t)i; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1403.has_value) {
                    __auto_type d = _mv_1403.value;
                    if (howl_sriqclauses_clause_cmp(c, d) != 0) {
                        ok = 0;
                    }
                } else if (!_mv_1403.has_value) {
                    ok = 0;
                }
                i = (i + 1);
            }
        }
        return ok;
    }
}

slop_list_howl_types_Clause howl_sriqsat_distinct_clauses(slop_arena* arena, slop_list_howl_sriqref_Cand cs) {
    {
        __auto_type raw = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(raw); __auto_type _item = (c.c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        __auto_type _mv_1404 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1404.has_value) {
            return raw;
        } else if (_mv_1404.has_value) {
            __auto_type c0 = _mv_1404.value;
            return howl_sriqsat_sorted_distinct(arena, raw, c0);
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_howl_types_Clause howl_sriqsat_sorted_distinct(slop_arena* arena, slop_list_howl_types_Clause raw, howl_types_Clause c0) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ howl_sriqsat__lambda_1405_env_t* howl_sriqsat__lambda_1405_env = (howl_sriqsat__lambda_1405_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqsat__lambda_1405_env_t)); *howl_sriqsat__lambda_1405_env = (howl_sriqsat__lambda_1405_env_t){ .raw = raw, .c0 = c0 }; (slop_closure_t){ (void*)howl_sriqsat__lambda_1405, (void*)howl_sriqsat__lambda_1405_env }; }));
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type c = howl_sriqsat_clause_of_l(raw, k, c0);
                    __auto_type _mv_1406 = ({ __auto_type _lst = out; size_t _idx = (size_t)(((int64_t)(((int64_t)((out).len)))) - 1); slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_1406.has_value) {
                        __auto_type last = _mv_1406.value;
                        if (howl_sriqclauses_clause_cmp(last, c) != 0) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    } else if (!_mv_1406.has_value) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

howl_types_Clause howl_sriqsat_clause_of_l(slop_list_howl_types_Clause cs, int64_t k, howl_types_Clause fallback) {
    __auto_type _mv_1407 = ({ __auto_type _lst = cs; size_t _idx = (size_t)k; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1407.has_value) {
        __auto_type c = _mv_1407.value;
        return c;
    } else if (!_mv_1407.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

howl_sriqctx_Structure howl_sriqsat_ranked_structure(howl_sriqctx_Structure st, int64_t nquery) {
    SLOP_PRE(((nquery >= 0)), "(>= nquery 0)");
    return ((howl_sriqctx_Structure){.ctxs = st.ctxs, .sets = st.sets, .edges = st.edges, .ord = howl_sriqorder_ranked(st.ord, nquery)});
}

howl_sriqsat_SatResult howl_sriqsat_sat_run(slop_arena* arena, howl_sriqref_RefIn in, howl_sriqsat_SatConfig cfg) {
    {
        __auto_type base = cfg.base;
        __auto_type tr = howl_sriqctx_build_triggers(arena, in.onto, in.nclass, in.nrole, in.nfn);
        __auto_type lam = (((base.lam >= 0)) ? base.lam : howl_sriqref_ref_lambda(tr, base.strat, howl_sriqref_initial_queries(in)));
        __auto_type env = howl_sriqref_env_of(arena, in, base, tr, lam);
        __auto_type hx = howl_sriqhyper_h_index(arena, in.onto);
        __auto_type st0 = howl_sriqsat_ranked_structure(howl_sriqref_init_of(arena, in), in.nquery);
        __auto_type dfr = howl_sriqsat_defer_on(cfg, in);
        __auto_type held = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        uint8_t cancelled = 0;
        uint8_t capped = 0;
        __auto_type run = ((howl_sriqsat_Run){.st = st0, .dl = howl_sriqsat_first_delta(arena, st0), .status = howl_sriqref_RefStatus_rs_fuel, .rounds = 0, .going = 1, .trig = ((slop_list_howl_sriqsat_Supply){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .flags = howl_sriqsat_empty_flags(arena, st0), .counts = ((howl_sriqsat_Counts){.cands = 0, .rcands = 0, .succs = 0, .rsuccs = 0, .noms = 0, .added = 0, .acts = 0, .hyper = 0, .stale = 0})});
        while ((run.going) && (!(cancelled)) && (!(capped))) {
            if (howl_types_cancel_requested(cfg.cancel)) {
                cancelled = 1;
            } else if (run.rounds >= base.fuel) {
                capped = 1;
            } else {
                {
                    __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                    __auto_type next = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                    __auto_type nr = howl_sriqsat_sat_once(next, scratch, env, hx, cfg, dfr, run);
                    if (nr.rounds == run.rounds) {
                        (void)(({ slop_arena_free(next); free(next); }));
                    } else {
                        (void)(({ slop_arena_free(held); free(held); }));
                        held = next;
                    }
                    (void)(({ slop_arena_free(scratch); free(scratch); }));
                    run = nr;
                }
            }
        }
        {
            __auto_type done = howl_sriqref_copy_structure(arena, howl_sriqsat_read_view(arena, run.st));
            __auto_type trig = howl_sriqsat_copy_trig(arena, run.trig);
            (void)(({ slop_arena_free(held); free(held); }));
            return ((howl_sriqsat_SatResult){.res = ((howl_sriqref_RefResult){.status = run.status, .rounds = run.rounds, .st = done}), .counts = run.counts, .trig = trig, .cancelled = cancelled});
        }
    }
}

