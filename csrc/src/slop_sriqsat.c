#include "../runtime/slop_runtime.h"
#include "slop_sriqsat.h"

#define sriqsat_ROOM_OFF (2147483647)

slop_list_types_Clause sriqsat_cs_at(slop_list_sriqctx_CtxSet xs, int64_t v, slop_list_types_Clause nobody);
slop_list_types_Clause sriqsat_permuted(slop_arena* arena, slop_list_types_Clause xs, int64_t perm);
slop_list_int sriqsat_ctx_order(slop_arena* arena, int64_t n, int64_t perm);
sriqsat_CIdx sriqsat_ctx_ix(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, int64_t v, int64_t perm, slop_list_sriqsat_View vw);
slop_list_sriqsat_CIdx sriqsat_all_ixs(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, int64_t perm, slop_list_sriqsat_View vw);
sriqsat_CIdx sriqsat_cix_at(slop_arena* arena, slop_list_sriqsat_CIdx ixs, int64_t v);
sriqsat_Here sriqsat_here_of(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqground_Ground gd, sriqhyper_HIdx hx, slop_list_sriqsat_CIdx ixs, sriqsat_RSrcs rs, int64_t v, int64_t perm, uint8_t dfr, uint8_t views);
uint8_t sriqsat_edge_new(sriqsat_Delta dl, sriqctx_Edge e);
uint8_t sriqsat_consts_new(sriqctx_Structure st, sriqsat_Delta dl);
slop_list_sriqref_Cand sriqsat_hyper_new_consts(slop_arena* arena, sriqctx_Structure st, sriqsat_Delta dl, uint32_t v, types_Clause oc);
slop_list_sriqref_Cand sriqsat_hyper_bodiless(slop_arena* arena, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, types_Clause oc);
uint8_t sriqsat_dl10(types_Clause oc);
sriqhyper_HCtx sriqsat_hctx_of(sriqsat_Here h);
sriqhyper_HOut sriqsat_sat_hyper(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, int64_t room);
slop_list_sriqref_Cand sriqsat_eq_pairs(slop_arena* arena, sriqctx_Structure st, sriqsat_Here h, slop_list_sriq_Premise p1s, slop_list_sriq_Premise p2s);
slop_list_sriqref_Cand sriqsat_eq_side(slop_arena* arena, sriqctx_Structure st, sriqsat_Here h, sriq_Premise p1, uint32_t k1, sriq_Premise p2);
uint8_t sriqsat_holds_term(types_Lit l, types_ATerm s);
uint8_t sriqsat_term_at(types_Lit l, uint32_t a, uint8_t inner, types_ATerm s);
sriqhyper_HOut sriqsat_sat_table2(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, int64_t room);
uint8_t sriqsat_within(slop_list_sriqref_Cand a, slop_list_sriqref_Cand b, int64_t room);
slop_list_sriqref_Cand sriqsat_t2_rest(slop_arena* arena, sriqctx_Structure st, sriqsat_Here h, slop_list_sriqref_Cand sofar, int64_t room);
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
sriqsat_CRound sriqsat_sat_ctx(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, slop_list_sriqsat_CIdx ixs, sriqsat_RSrcs rs, sriqctx_Structure st, sriqsat_Delta dl, sriqground_Ground gd, sriqsat_Adj a, int64_t v, int64_t perm, uint8_t dfr, uint8_t views, int64_t room);
sriqsat_CRound sriqsat_sat_old(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, slop_list_sriqctx_Edge ins, sriqsat_Here h, int64_t room);
sriqsat_CRound sriqsat_sat_old_rest(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, slop_list_sriqctx_Edge ins, sriqsat_Here h, int64_t room, sriqhyper_HOut t2);
sriqctx_Edge sriqsat_edge_at(slop_list_sriqctx_Edge es, int64_t k, sriqctx_Edge fallback);
slop_list_sriqsat_Adj sriqsat_adjacency(slop_arena* arena, sriqctx_Structure st);
slop_list_sriqctx_Edge sriqsat_edges_at(slop_arena* arena, slop_list_sriqsat_Bucket bs, int64_t v);
int64_t sriqsat_u32_cmp(uint32_t a, uint32_t b);
sriqsat_Cut sriqsat_cut_at(slop_arena* arena, slop_list_sriqctx_Edge es, slop_list_int idx, int64_t k, int64_t v, uint8_t by_to, sriqctx_Edge e0);
slop_list_sriqsat_Bucket sriqsat_buckets(slop_arena* arena, slop_list_sriqctx_Edge es, slop_list_int idx, int64_t n, uint8_t by_to, sriqctx_Edge e0);
int64_t sriqsat_idx_at(slop_list_int idx, int64_t k);
uint8_t sriqsat_passes(sriqsat_CRound cr, slop_list_sriqref_Cand cands, int64_t room);
sriqsat_CRound sriqsat_sat_round(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, sriqctx_Structure st, sriqsat_Delta dl, sriqground_Ground gd, int64_t perm, uint8_t dfr, slop_list_sriqsat_View vw, int64_t room);
slop_list_sriqref_Cand sriqsat_new_cores(slop_arena* arena, sriqctx_Structure st, int64_t from);
sriqsat_Step sriqsat_sat_apply(slop_arena* arena, sriqctx_Structure st, sriqground_Ground gd, sriqref_Round r, uint8_t scan, uint8_t dfr, slop_list_sriqsat_Supply trig, slop_list_sriqsat_Flags fl);
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
sriqsat_Step sriqsat_commit_all(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_Cand cands, int64_t c0, int64_t e0, int64_t n0, uint8_t scan, slop_list_sriqsat_Flags fl);
slop_list_list_u8 sriqsat_new_flags(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Clause ws, slop_list_list_u8 wf, sriqsubsume_Committed cm, int64_t ncands);
slop_list_types_Clause sriqsat_run_of(slop_arena* arena, slop_list_sriqref_Cand cands, slop_list_int idx, int64_t k, uint32_t v, sriqref_Cand none_such);
sriqsubsume_Committed sriqsat_commit_one(slop_arena* arena, slop_list_types_Clause ws, slop_list_types_Clause cs, uint8_t scan);
slop_list_types_Clause sriqsat_minus_sorted(slop_arena* arena, slop_list_types_Clause xs, slop_list_types_Clause ys);
slop_list_sriqctx_Edge sriqsat_edges_from(slop_arena* arena, slop_list_sriqctx_Edge es, int64_t k);
slop_list_sriqsat_View sriqsat_views_of(slop_arena* arena, sriqctx_Structure st, slop_list_sriqsat_Flags fl);
slop_list_sriq_Premise sriqsat_premises_in(slop_arena* arena, sriqctx_Structure st, slop_list_sriqsat_View vw, int64_t v, slop_list_types_Clause cs);
slop_list_sriq_Premise sriqsat_clause_premises(slop_arena* arena, types_Clause c, slop_list_u8 fs);
slop_list_types_Lit sriqsat_head_without(slop_arena* arena, slop_list_types_Lit xs, int64_t i);
uint8_t sriqsat_flag_at(slop_list_u8 fs, int64_t i);
slop_list_u8 sriqsat_flags_of(slop_arena* arena, sriqorder_SriqOrder ord, sriqsat_View w, types_Clause c);
int64_t sriqsat_clause_pos(slop_list_types_Clause cs, types_Clause c);
uint8_t sriqsat_sorted_at(slop_list_types_Clause cs, int64_t k, types_Clause c);
slop_list_list_u8 sriqsat_walked_flags(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Clause ws, slop_list_list_u8 wf, slop_list_types_Clause set);
uint8_t sriqsat_below_at(slop_list_types_Clause cs, int64_t j, types_Clause c);
slop_list_list_u8 sriqsat_fs_at(slop_list_sriqsat_Flags fl, int64_t v, slop_list_list_u8 none_fs);
slop_list_sriqsat_Flags sriqsat_empty_flags(slop_arena* arena, sriqctx_Structure st);
slop_list_sriqsat_Flags sriqsat_copy_flags(slop_arena* arena, slop_list_sriqsat_Flags fl);
int64_t sriqsat_stale_flags(slop_arena* arena, sriqctx_Structure st, slop_list_sriqsat_Flags fl);
int64_t sriqsat_stale_in(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Clause cs, slop_list_list_u8 fs);
uint8_t sriqsat_same_flags(slop_list_u8 a, slop_list_u8 b);
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
sriqsat_Counts sriqsat_tally(sriqsat_Counts c, sriqref_Round r, sriqsat_Delta dl, int64_t tried, int64_t acts, int64_t stale);
sriqsat_Step sriqsat_with_units(slop_arena* arena, sriqctx_Triggers tr, sriqsat_Step sp);
slop_list_sriqsat_Flags sriqsat_with_root_flags(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Clause ws, slop_list_sriqsat_Flags fl, slop_list_types_Clause set);
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

typedef struct { slop_list_sriqsat_JoinSite raw; sriqsat_JoinSite s0; } sriqsat__lambda_1056_env_t;

static int64_t sriqsat__lambda_1056(sriqsat__lambda_1056_env_t* _env, int64_t a, int64_t b) { return types_lit_cmp(sriqsat_site_key(sriqsat_site_at(_env->raw, a, _env->s0)), sriqsat_site_key(sriqsat_site_at(_env->raw, b, _env->s0))); }

typedef struct { slop_list_sriqsat_Trig raw; sriqsat_Trig t0; } sriqsat__lambda_1065_env_t;

static int64_t sriqsat__lambda_1065(sriqsat__lambda_1065_env_t* _env, int64_t a, int64_t b) { return sriqsat_sg_cmp(sriqsat_trig_at(_env->raw, a, _env->t0).sg, sriqsat_trig_at(_env->raw, b, _env->t0).sg); }

typedef struct { slop_list_sriqctx_Edge es; sriqctx_Edge e0; } sriqsat__lambda_1068_env_t;

static int64_t sriqsat__lambda_1068(sriqsat__lambda_1068_env_t* _env, int64_t i, int64_t j) { return sriqsat_u32_cmp(sriqsat_edge_at(_env->es, i, _env->e0).to, sriqsat_edge_at(_env->es, j, _env->e0).to); }

typedef struct { slop_list_sriqctx_Edge es; sriqctx_Edge e0; } sriqsat__lambda_1069_env_t;

static int64_t sriqsat__lambda_1069(sriqsat__lambda_1069_env_t* _env, int64_t i, int64_t j) { return sriqsat_u32_cmp(sriqsat_edge_at(_env->es, i, _env->e0).from, sriqsat_edge_at(_env->es, j, _env->e0).from); }

typedef struct { slop_list_sriqctx_Edge old; sriqctx_Edge e0; } sriqsat__lambda_1074_env_t;

static int64_t sriqsat__lambda_1074(sriqsat__lambda_1074_env_t* _env, int64_t i, int64_t j) { return sriqsat_edge_cmp(sriqsat_edge_at(_env->old, i, _env->e0), sriqsat_edge_at(_env->old, j, _env->e0)); }

typedef struct { slop_list_sriqctx_Edge news; sriqctx_Edge e0; } sriqsat__lambda_1075_env_t;

static int64_t sriqsat__lambda_1075(sriqsat__lambda_1075_env_t* _env, int64_t i, int64_t j) { return sriqsat_edge_cmp(sriqsat_edge_at(_env->news, i, _env->e0), sriqsat_edge_at(_env->news, j, _env->e0)); }

typedef struct { slop_list_int keep; } sriqsat__lambda_1076_env_t;

static int64_t sriqsat__lambda_1076(sriqsat__lambda_1076_env_t* _env, int64_t i, int64_t j) { return sriqsat_int_cmp(sriqsat_idx_at(_env->keep, i), sriqsat_idx_at(_env->keep, j)); }

typedef struct { slop_list_sriqref_Cand cands; sriqref_Cand none_such; } sriqsat__lambda_1078_env_t;

static int64_t sriqsat__lambda_1078(sriqsat__lambda_1078_env_t* _env, int64_t i, int64_t j) { return sriqref_cand_cmp(sriqref_cand_at(_env->cands, i, _env->none_such), sriqref_cand_at(_env->cands, j, _env->none_such)); }

typedef struct { slop_list_sriqsat_Supply raw; sriqsat_Supply s0; } sriqsat__lambda_1094_env_t;

static int64_t sriqsat__lambda_1094(sriqsat__lambda_1094_env_t* _env, int64_t i, int64_t j) { return sriqsat_supply_cmp(sriqsat_supply_at(_env->raw, i, _env->s0), sriqsat_supply_at(_env->raw, j, _env->s0)); }

typedef struct { slop_list_types_Clause raw; types_Clause c0; } sriqsat__lambda_1105_env_t;

static int64_t sriqsat__lambda_1105(sriqsat__lambda_1105_env_t* _env, int64_t a, int64_t b) { return sriqclauses_clause_cmp(sriqsat_clause_of_l(_env->raw, a, _env->c0), sriqsat_clause_of_l(_env->raw, b, _env->c0)); }

slop_list_types_Clause sriqsat_cs_at(slop_list_sriqctx_CtxSet xs, int64_t v, slop_list_types_Clause nobody) {
    __auto_type _mv_1050 = ({ __auto_type _lst = xs; size_t _idx = (size_t)v; slop_option_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1050.has_value) {
        __auto_type s = _mv_1050.value;
        return s.cs;
    } else if (!_mv_1050.has_value) {
        return nobody;
    }
    SLOP_UNREACHABLE();
}

slop_list_types_Clause sriqsat_permuted(slop_arena* arena, slop_list_types_Clause xs, int64_t perm) {
    {
        __auto_type n = ((int64_t)(((int64_t)((xs).len))));
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < n) {
            {
                __auto_type k = ((perm == 1) ? ((n - 1) - i) : ((perm == 2) ? ((i + (n / 2)) % n) : i));
                __auto_type _mv_1051 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1051.has_value) {
                    __auto_type c = _mv_1051.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1051.has_value) {
                }
                i = (i + 1);
            }
        }
        return out;
    }
}

slop_list_int sriqsat_ctx_order(slop_arena* arena, int64_t n, int64_t perm) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < n) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (((perm == 1) ? ((n - 1) - i) : ((perm == 2) ? ((i + (n / 2)) % n) : i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        return out;
    }
}

sriqsat_CIdx sriqsat_ctx_ix(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, int64_t v, int64_t perm, slop_list_sriqsat_View vw) {
    {
        __auto_type all = sriqref_set_of(env, st, v);
        __auto_type fresh = (v >= dl.nctx);
        __auto_type news = sriqsat_permuted(arena, ((fresh) ? all : sriqsat_cs_at(dl.news, v, env.nobody)), perm);
        __auto_type olds = ((fresh) ? env.nobody : sriqsat_cs_at(dl.olds, v, env.nobody));
        __auto_type aps = sriqsat_premises_in(arena, st, vw, v, all);
        __auto_type dps = sriqsat_premises_in(arena, st, vw, v, news);
        __auto_type ops = sriqsat_premises_in(arena, st, vw, v, olds);
        return ((sriqsat_CIdx){.aps = aps, .dps = dps, .ops = ops, .aix = sriqground_pidx_of(arena, aps), .dix = sriqground_pidx_of(arena, dps), .oix = sriqground_pidx_of(arena, ops)});
    }
}

slop_list_sriqsat_CIdx sriqsat_all_ixs(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, int64_t perm, slop_list_sriqsat_View vw) {
    {
        __auto_type out = ((slop_list_sriqsat_CIdx){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        {
            __auto_type _coll = st.ctxs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqsat_ctx_ix(arena, env, st, dl, v, perm, vw)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                v = (v + 1);
            }
        }
        return out;
    }
}

sriqsat_CIdx sriqsat_cix_at(slop_arena* arena, slop_list_sriqsat_CIdx ixs, int64_t v) {
    __auto_type _mv_1052 = ({ __auto_type _lst = ixs; size_t _idx = (size_t)v; slop_option_sriqsat_CIdx _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1052.has_value) {
        __auto_type x = _mv_1052.value;
        return x;
    } else if (!_mv_1052.has_value) {
        {
            __auto_type e = ((slop_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            return ((sriqsat_CIdx){.aps = e, .dps = e, .ops = e, .aix = sriqground_pidx_of(arena, e), .dix = sriqground_pidx_of(arena, e), .oix = sriqground_pidx_of(arena, e)});
        }
    }
    SLOP_UNREACHABLE();
}

sriqsat_Here sriqsat_here_of(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqground_Ground gd, sriqhyper_HIdx hx, slop_list_sriqsat_CIdx ixs, sriqsat_RSrcs rs, int64_t v, int64_t perm, uint8_t dfr, uint8_t views) {
    {
        __auto_type all = sriqref_set_of(env, st, v);
        __auto_type fresh = (v >= dl.nctx);
        __auto_type news = sriqsat_permuted(arena, ((fresh) ? all : sriqsat_cs_at(dl.news, v, env.nobody)), perm);
        __auto_type olds = ((fresh) ? env.nobody : sriqsat_cs_at(dl.olds, v, env.nobody));
        __auto_type x = sriqsat_cix_at(arena, ixs, v);
        return ((sriqsat_Here){.v = ((uint32_t)(v)), .root = sriqref_is_root(st, v), .fresh = fresh, .all = all, .news = news, .olds = olds, .aps = x.aps, .dps = x.dps, .ops = x.ops, .dix = x.dix, .aix = x.aix, .oix = x.oix, .hx = hx, .ixs = ixs, .gd = gd, .rs = rs, .dfr = dfr, .views = views});
    }
}

uint8_t sriqsat_edge_new(sriqsat_Delta dl, sriqctx_Edge e) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = dl.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (sriqref_edge_is(x, e.from, e.to, e.lk, e.label)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t sriqsat_consts_new(sriqctx_Structure st, sriqsat_Delta dl) {
    return (sriqref_consts_of(st) > dl.ncst);
}

slop_list_sriqref_Cand sriqsat_hyper_new_consts(slop_arena* arena, sriqctx_Structure st, sriqsat_Delta dl, uint32_t v, types_Clause oc) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t u = dl.ncst;
        while (u < sriqref_consts_of(st)) {
            {
                __auto_type _coll = sriqref_conclusion(arena, v, sriq_hyper_finish(arena, sriq_hyper_start(arena, types_at_u(((uint32_t)(u))), 1), oc.head));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            u = (u + 1);
        }
        return out;
    }
}

slop_list_sriqref_Cand sriqsat_hyper_bodiless(slop_arena* arena, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, types_Clause oc) {
    if (h.root) {
        return sriqsat_hyper_new_consts(arena, st, dl, h.v, oc);
    } else if (h.fresh && !(sriqsat_dl10(oc))) {
        return sriqref_conclusion(arena, h.v, sriq_hyper_finish(arena, sriq_hyper_start(arena, types_at_x(), 1), oc.head));
    } else {
        return ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
}

uint8_t sriqsat_dl10(types_Clause oc) {
    return (((((int64_t)((oc.body).len)) == 0)) && ((((int64_t)((oc.head).len)) > 0)) && (sriqground_ground_clause(oc)));
}

sriqhyper_HCtx sriqsat_hctx_of(sriqsat_Here h) {
    return ((sriqhyper_HCtx){.v = h.v, .root = h.root, .dps = h.dps, .aps = h.aps, .dix = h.dix, .oix = h.oix, .aix = h.aix});
}

sriqhyper_HOut sriqsat_sat_hyper(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, int64_t room) {
    {
        __auto_type hy = sriqhyper_hyper_indexed(arena, env, h.hx, sriqsat_hctx_of(h), room);
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = h.hx.bodiless;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type oc = _coll.data[_i];
                if ((((int64_t)((out).len)) + ((int64_t)((hy.out.cands).len))) <= room) {
                    {
                        __auto_type _coll = sriqsat_hyper_bodiless(arena, st, dl, h, oc);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        {
            __auto_type _coll = hy.out.cands;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((sriqhyper_HOut){.out = sriqref_out_of(out, hy.out.over), .tried = hy.tried});
    }
}

slop_list_sriqref_Cand sriqsat_eq_pairs(slop_arena* arena, sriqctx_Structure st, sriqsat_Here h, slop_list_sriq_Premise p1s, slop_list_sriq_Premise p2s) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = p1s;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p1 = _coll.data[_i];
                if (p1.maxed && (p1.sel.form == types_LitForm_lf_eq)) {
                    {
                        __auto_type _coll = p2s;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type p2 = _coll.data[_i];
                            if (p2.maxed) {
                                {
                                    __auto_type _coll = sriqsat_eq_side(arena, st, h, p1, ((uint32_t)(1)), p2);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type c = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                {
                                    __auto_type _coll = sriqsat_eq_side(arena, st, h, p1, ((uint32_t)(2)), p2);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type c = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

slop_list_sriqref_Cand sriqsat_eq_side(slop_arena* arena, sriqctx_Structure st, sriqsat_Here h, sriq_Premise p1, uint32_t k1, sriq_Premise p2) {
    if (sriqsat_holds_term(p2.sel, (((k1 == ((uint32_t)(1)))) ? p1.sel.t1 : p1.sel.t2))) {
        return sriqref_eq_positions(arena, st.ord, h.v, h.root, p1, k1, p2);
    } else {
        return ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
}

uint8_t sriqsat_holds_term(types_Lit l, types_ATerm s) {
    return ((sriqsat_term_at(l, ((uint32_t)(1)), 0, s)) || (sriqsat_term_at(l, ((uint32_t)(1)), 1, s)) || (sriqsat_term_at(l, ((uint32_t)(2)), 0, s)) || (sriqsat_term_at(l, ((uint32_t)(2)), 1, s)));
}

uint8_t sriqsat_term_at(types_Lit l, uint32_t a, uint8_t inner, types_ATerm s) {
    __auto_type _mv_1053 = sriq_subterm_at(l, ((sriq_Pos){.arg = a, .inner = inner}));
    if (_mv_1053.has_value) {
        __auto_type t = _mv_1053.value;
        return types_aterm_eq(t, s);
    } else if (!_mv_1053.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

sriqhyper_HOut sriqsat_sat_table2(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, int64_t room) {
    {
        __auto_type hy = sriqsat_sat_hyper(arena, env, st, dl, h, room);
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (h.fresh) {
            {
                __auto_type _coll = sriqref_ref_core(arena, h.v, sriqref_core_at(env, st, arena, ((int64_t)(h.v))));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        if (!(h.root) && sriqsat_within(out, hy.out.cands, room)) {
            {
                __auto_type _coll = sriqsat_eq_ground(arena, st, h);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            if (sriqsat_within(out, hy.out.cands, room)) {
                {
                    __auto_type _coll = sriqsat_join_ground(arena, h);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type _coll = hy.out.cands;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        if (((int64_t)(((int64_t)((out).len)))) <= room) {
            out = sriqsat_t2_rest(arena, st, h, out, room);
        }
        return ((sriqhyper_HOut){.out = sriqref_out_of(out, hy.out.over), .tried = hy.tried});
    }
}

uint8_t sriqsat_within(slop_list_sriqref_Cand a, slop_list_sriqref_Cand b, int64_t room) {
    return ((((int64_t)(((int64_t)((a).len)))) + ((int64_t)(((int64_t)((b).len))))) <= room);
}

slop_list_sriqref_Cand sriqsat_t2_rest(slop_arena* arena, sriqctx_Structure st, sriqsat_Here h, slop_list_sriqref_Cand sofar, int64_t room) {
    {
        __auto_type out = sofar;
        {
            __auto_type _coll = sriqsat_eq_pairs(arena, st, h, h.dps, h.aps);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        if (((int64_t)(((int64_t)((out).len)))) <= room) {
            {
                __auto_type _coll = sriqsat_eq_pairs(arena, st, h, h.ops, h.dps);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        if (((int64_t)(((int64_t)((out).len)))) <= room) {
            {
                __auto_type _coll = sriqref_ref_ineq(arena, h.v, h.dps);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        if (((int64_t)(((int64_t)((out).len)))) <= room) {
            {
                __auto_type _coll = sriqref_ref_factor(arena, st.ord, h.v, h.dps);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        if (((int64_t)(((int64_t)((out).len)))) <= room) {
            {
                __auto_type _coll = sriqsat_sat_join(arena, h.v, h.dps, sriqsat_join_sites(arena, h.all));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        if (((int64_t)(((int64_t)((out).len)))) <= room) {
            {
                __auto_type _coll = sriqsat_sat_join(arena, h.v, h.ops, sriqsat_join_sites(arena, h.news));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

uint8_t sriqsat_g_counts(sriqsat_Here h, int64_t i, int64_t which) {
    {
        __auto_type new = (!(h.fresh) && sriqground_g_fresh(h.gd, i));
        return (sriqground_g_visible(h.gd, ((int64_t)(h.v)), i) && ((which == 1) ? new : ((which == 2) ? !(new) : 1)));
    }
}

uint8_t sriqsat_g_picks(sriqsat_Here h, int64_t k, int64_t which) {
    return sriqsat_g_counts(h, sriqground_g_member_of(h.gd, k), which);
}

slop_list_sriq_Premise sriqsat_g_prems(slop_arena* arena, sriqsat_Here h, int64_t which, uint8_t eqs) {
    {
        __auto_type out = ((slop_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = h.gd.ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if ((p.maxed) && ((!(eqs) || (p.sel.form == types_LitForm_lf_eq))) && (sriqsat_g_picks(h, k, which))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                k = (k + 1);
            }
        }
        return out;
    }
}

slop_list_sriqref_Cand sriqsat_join_into_g(slop_arena* arena, sriqsat_Here h, slop_list_sriq_Premise p1s, int64_t which) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = p1s;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p1 = _coll.data[_i];
                if (p1.maxed && sriq_joinable(p1.sel)) {
                    {
                        __auto_type _coll = sriqground_g_body_members(arena, h.gd, p1.sel);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type i = _coll.data[_i];
                            if (sriqsat_g_counts(h, i, which)) {
                                {
                                    __auto_type _coll = sriqsat_join_into_member(arena, h, p1, sriqground_g_member(h.gd, i, sriqsat_empty_clause(arena)));
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type c = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

slop_list_sriqref_Cand sriqsat_join_into_member(slop_arena* arena, sriqsat_Here h, sriq_Premise p1, types_Clause g) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        {
            __auto_type _coll = g.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (types_lit_eq(l, p1.sel)) {
                    {
                        __auto_type _coll = sriqref_conclusion(arena, h.v, sriq_join_rule(arena, p1, sriq_body_at(arena, g, j)));
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                j = (j + 1);
            }
        }
        return out;
    }
}

types_Clause sriqsat_empty_clause(slop_arena* arena) {
    return ((types_Clause){.body = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .head = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
}

uint8_t sriqsat_has_eq(slop_list_sriq_Premise ps) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (p.maxed && (p.sel.form == types_LitForm_lf_eq)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_list_sriqref_Cand sriqsat_eq_ground(slop_arena* arena, sriqctx_Structure st, sriqsat_Here h) {
    {
        __auto_type gn = sriqsat_g_prems(arena, h, 1, 1);
        __auto_type go = sriqsat_g_prems(arena, h, 2, 1);
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (sriqsat_has_eq(h.dps)) {
            {
                __auto_type _coll = sriqsat_eq_pairs(arena, st, h, h.dps, sriqsat_g_prems(arena, h, 0, 0));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        if (sriqsat_has_eq(h.ops)) {
            {
                __auto_type _coll = sriqsat_eq_pairs(arena, st, h, h.ops, sriqsat_g_prems(arena, h, 1, 0));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type _coll = sriqsat_eq_pairs(arena, st, h, gn, h.aps);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqsat_eq_pairs(arena, st, h, go, h.dps);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        if (((int64_t)((gn).len)) > 0) {
            {
                __auto_type _coll = sriqsat_eq_pairs(arena, st, h, gn, sriqsat_g_prems(arena, h, 0, 0));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        if (((int64_t)((go).len)) > 0) {
            {
                __auto_type _coll = sriqsat_eq_pairs(arena, st, h, go, sriqsat_g_prems(arena, h, ((h.fresh) ? 0 : 1), 0));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

slop_list_sriqref_Cand sriqsat_join_ground(slop_arena* arena, sriqsat_Here h) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = sriqsat_join_into_g(arena, h, h.dps, 0);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqsat_join_into_g(arena, h, h.ops, 1);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqsat_join_from_g(arena, h, sriqsat_join_sites(arena, h.all), 1);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqsat_join_from_g(arena, h, sriqsat_join_sites(arena, h.news), 2);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_sriqref_Cand sriqsat_join_from_g(slop_arena* arena, sriqsat_Here h, slop_list_sriqsat_JoinSite sites, int64_t which) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = sites;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                __auto_type _mv_1054 = sriqsat_site_lit(s);
                if (!_mv_1054.has_value) {
                } else if (_mv_1054.has_value) {
                    __auto_type l = _mv_1054.value;
                    {
                        __auto_type _coll = sriqsat_join_site_g(arena, h, s, l, which);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        return out;
    }
}

slop_list_sriqref_Cand sriqsat_join_site_g(slop_arena* arena, sriqsat_Here h, sriqsat_JoinSite s, types_Lit l, int64_t which) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = sriqground_g_sel_range(arena, h.gd, l);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                if (sriqsat_g_picks(h, k, which)) {
                    {
                        __auto_type _coll = sriqsat_join_g_one(arena, h, s, sriqground_g_premise_at(h.gd, k, sriqsat_fallback_premise(arena)));
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        return out;
    }
}

slop_list_sriqref_Cand sriqsat_join_g_one(slop_arena* arena, sriqsat_Here h, sriqsat_JoinSite s, sriq_Premise p1) {
    if (p1.maxed) {
        return sriqref_conclusion(arena, h.v, sriq_join_rule(arena, p1, sriq_body_at(arena, s.c, s.j)));
    } else {
        return ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
}

sriq_Premise sriqsat_fallback_premise(slop_arena* arena) {
    return ((sriq_Premise){.body = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .sel = types_atom1(((uint32_t)(0)), types_at_x()), .rest = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .maxed = 0});
}

slop_list_sriqsat_JoinSite sriqsat_join_sites(slop_arena* arena, slop_list_types_Clause cs) {
    {
        __auto_type raw = ((slop_list_sriqsat_JoinSite){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
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
                            if (sriq_joinable(l)) {
                                ({ __auto_type _lst_p = &(raw); __auto_type _item = (((sriqsat_JoinSite){.c = c, .j = j})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                            j = (j + 1);
                        }
                    }
                }
            }
        }
        __auto_type _mv_1055 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_sriqsat_JoinSite _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1055.has_value) {
            return raw;
        } else if (_mv_1055.has_value) {
            __auto_type s0 = _mv_1055.value;
            return sriqsat_sites_sorted(arena, raw, s0);
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_sriqsat_JoinSite sriqsat_sites_sorted(slop_arena* arena, slop_list_sriqsat_JoinSite raw, sriqsat_JoinSite s0) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ sriqsat__lambda_1056_env_t* sriqsat__lambda_1056_env = (sriqsat__lambda_1056_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1056_env_t)); *sriqsat__lambda_1056_env = (sriqsat__lambda_1056_env_t){ .raw = raw, .s0 = s0 }; (slop_closure_t){ (void*)sriqsat__lambda_1056, (void*)sriqsat__lambda_1056_env }; }));
        __auto_type out = ((slop_list_sriqsat_JoinSite){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqsat_site_at(raw, k, s0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

sriqsat_JoinSite sriqsat_site_at(slop_list_sriqsat_JoinSite ss, int64_t k, sriqsat_JoinSite fallback) {
    __auto_type _mv_1057 = ({ __auto_type _lst = ss; size_t _idx = (size_t)k; slop_option_sriqsat_JoinSite _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1057.has_value) {
        __auto_type x = _mv_1057.value;
        return x;
    } else if (!_mv_1057.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

types_Lit sriqsat_site_key(sriqsat_JoinSite s) {
    __auto_type _mv_1058 = sriqsat_site_lit(s);
    if (_mv_1058.has_value) {
        __auto_type l = _mv_1058.value;
        return l;
    } else if (!_mv_1058.has_value) {
        return types_atom1(((uint32_t)(0)), types_at_x());
    }
    SLOP_UNREACHABLE();
}

int64_t sriqsat_site_lower(slop_list_sriqsat_JoinSite ss, types_Lit l, sriqsat_JoinSite fallback) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((ss).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                if (types_lit_cmp(sriqsat_site_key(sriqsat_site_at(ss, mid, fallback)), l) < 0) {
                    lo = (mid + 1);
                } else {
                    hi = mid;
                }
            }
        }
        return lo;
    }
}

slop_option_types_Lit sriqsat_site_lit(sriqsat_JoinSite s) {
    return ({ __auto_type _lst = s.c.body; size_t _idx = (size_t)s.j; slop_option_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
}

slop_list_sriqref_Cand sriqsat_sat_join(slop_arena* arena, uint32_t v, slop_list_sriq_Premise p1s, slop_list_sriqsat_JoinSite sites) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = p1s;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p1 = _coll.data[_i];
                if (p1.maxed && sriq_joinable(p1.sel)) {
                    {
                        __auto_type _coll = sriqsat_join_one(arena, v, p1, sites);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        return out;
    }
}

slop_list_sriqref_Cand sriqsat_join_one(slop_arena* arena, uint32_t v, sriq_Premise p1, slop_list_sriqsat_JoinSite sites) {
    __auto_type _mv_1059 = ({ __auto_type _lst = sites; size_t _idx = (size_t)0; slop_option_sriqsat_JoinSite _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1059.has_value) {
        return ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    } else if (_mv_1059.has_value) {
        __auto_type s0 = _mv_1059.value;
        return sriqsat_join_from(arena, v, p1, sites, sriqsat_site_lower(sites, p1.sel, s0), s0);
    }
    SLOP_UNREACHABLE();
}

slop_list_sriqref_Cand sriqsat_join_from(slop_arena* arena, uint32_t v, sriq_Premise p1, slop_list_sriqsat_JoinSite sites, int64_t k0, sriqsat_JoinSite s0) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = k0;
        while ((k < ((int64_t)(((int64_t)((sites).len))))) && sriqsat_site_holds(sriqsat_site_at(sites, k, s0), p1.sel)) {
            {
                __auto_type s = sriqsat_site_at(sites, k, s0);
                {
                    __auto_type _coll = sriqref_conclusion(arena, v, sriq_join_rule(arena, p1, sriq_body_at(arena, s.c, s.j)));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                k = (k + 1);
            }
        }
        return out;
    }
}

uint8_t sriqsat_site_holds(sriqsat_JoinSite s, types_Lit l) {
    __auto_type _mv_1060 = sriqsat_site_lit(s);
    if (_mv_1060.has_value) {
        __auto_type m = _mv_1060.value;
        return types_lit_eq(m, l);
    } else if (!_mv_1060.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

sriqref_Round sriqsat_nom_pairs(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriqref_Dl4 d, slop_list_sriq_Premise p1s, slop_list_sriq_Premise p2s) {
    {
        __auto_type cands = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type noms = ((slop_list_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = p1s;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p1 = _coll.data[_i];
                if (sriqref_nom_first(p1, d)) {
                    {
                        __auto_type _coll = p2s;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type p2 = _coll.data[_i];
                            if (sriqref_nom_second(p2, d, p1.sel.t1.cst)) {
                                {
                                    __auto_type r = sriqref_nom_pair(arena, env, st.ord, h.v, d, p1, p2);
                                    {
                                        __auto_type _coll = r.cands;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type c = _coll.data[_i];
                                            ({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                    {
                                        __auto_type _coll = r.noms;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type a = _coll.data[_i];
                                            ({ __auto_type _lst_p = &(noms); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return sriqref_round_of(cands, ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), noms, 0);
    }
}

sriqref_Round sriqsat_sat_nom(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h) {
    {
        __auto_type all = sriqsat_consts_new(st, dl);
        __auto_type mine = sriqsat_nom_own(arena, env, st, h, all);
        __auto_type cands = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type noms = ((slop_list_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = mine.cands;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = mine.noms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(noms); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        if (!(h.root)) {
            {
                __auto_type _coll = h.hx.dl4s;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type d = _coll.data[_i];
                    {
                        __auto_type _coll = sriqsat_nom_ground(arena, env, st, h, d, all);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type r = _coll.data[_i];
                            {
                                __auto_type _coll = r.cands;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type c = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                            {
                                __auto_type _coll = r.noms;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type a = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(noms); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                }
            }
        }
        return sriqref_round_of(cands, ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), noms, 0);
    }
}

slop_list_sriqref_Round sriqsat_nom_ground(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriqref_Dl4 d, uint8_t all) {
    if (!(d.ok)) {
        return ((slop_list_sriqref_Round){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    } else if (all) {
        return sriqsat_one_round(arena, sriqsat_nom_from_g(arena, env, st, h, d, h.aps, 0));
    } else {
        return sriqsat_two_rounds(arena, sriqsat_nom_from_g(arena, env, st, h, d, h.aps, 1), sriqsat_nom_from_g(arena, env, st, h, d, h.dps, 2));
    }
}

sriqref_Round sriqsat_nom_own(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, uint8_t all) {
    {
        __auto_type cands = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type noms = ((slop_list_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = h.hx.dl4s;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type d = _coll.data[_i];
                {
                    __auto_type _coll = ((all) ? sriqsat_one_round(arena, sriqsat_nom_pairs(arena, env, st, h, d, h.aps, h.aps)) : sriqsat_two_rounds(arena, sriqsat_nom_pairs(arena, env, st, h, d, h.dps, h.aps), sriqsat_nom_pairs(arena, env, st, h, d, h.ops, h.dps)));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        {
                            __auto_type _coll = r.cands;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type c = _coll.data[_i];
                                ({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            __auto_type _coll = r.noms;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type a = _coll.data[_i];
                                ({ __auto_type _lst_p = &(noms); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
            }
        }
        return sriqref_round_of(cands, ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), noms, 0);
    }
}

slop_list_sriqref_Round sriqsat_one_round(slop_arena* arena, sriqref_Round a) {
    {
        __auto_type out = ((slop_list_sriqref_Round){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

sriqref_Round sriqsat_nom_from_g(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriqref_Dl4 d, slop_list_sriq_Premise p2s, int64_t which) {
    {
        __auto_type cands = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type noms = ((slop_list_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = p2s;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p2 = _coll.data[_i];
                if ((p2.maxed) && ((p2.sel.form == types_LitForm_lf_binary)) && ((p2.sel.t1.kind == types_AKind_ak_u))) {
                    {
                        __auto_type r = sriqsat_nom_g_one(arena, env, st, h, d, p2, p2.sel.t1.cst, which);
                        {
                            __auto_type _coll = r.cands;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type c = _coll.data[_i];
                                ({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            __auto_type _coll = r.noms;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type a = _coll.data[_i];
                                ({ __auto_type _lst_p = &(noms); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
            }
        }
        return sriqref_round_of(cands, ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), noms, 0);
    }
}

sriqref_Round sriqsat_nom_g_one(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriqref_Dl4 d, sriq_Premise p2, uint32_t o, int64_t which) {
    {
        __auto_type cands = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type noms = ((slop_list_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = sriqground_g_sel_range(arena, h.gd, types_atom1(d.b1, types_at_u(o)));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type p1 = sriqground_g_premise_at(h.gd, k, sriqsat_fallback_premise(arena));
                    if ((sriqsat_g_picks(h, k, which)) && (sriqref_nom_first(p1, d)) && (sriqref_nom_second(p2, d, o))) {
                        {
                            __auto_type r = sriqref_nom_pair(arena, env, st.ord, h.v, d, p1, p2);
                            {
                                __auto_type _coll = r.cands;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type c = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                            {
                                __auto_type _coll = r.noms;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type a = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(noms); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                }
            }
        }
        return sriqref_round_of(cands, ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), noms, 0);
    }
}

slop_list_sriqref_Round sriqsat_two_rounds(slop_arena* arena, sriqref_Round a, sriqref_Round b) {
    {
        __auto_type out = ((slop_list_sriqref_Round){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

uint8_t sriqsat_k2_touched(slop_arena* arena, sriqref_Env env, sriqsat_Here h, sriqindex_KIdx kn, sriq_Premise p) {
    __auto_type _mv_1061 = sriq_succ_sig(h.root, p.sel);
    if (!_mv_1061.has_value) {
        return 0;
    } else if (_mv_1061.has_value) {
        __auto_type sg = _mv_1061.value;
        return (((int64_t)((sriqindex_k_query(arena, env.tr, kn, sg).k2).len)) > 0);
    }
    SLOP_UNREACHABLE();
}

slop_list_sriq_Premise sriqsat_succ_premises(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h) {
    {
        __auto_type kn = ((h.views) ? sriqindex_k_index_premises(arena, env.tr, h.dps) : sriqindex_k_index(arena, st.ord, env.tr, h.news));
        __auto_type gnew = (((int64_t)((kn.ground).len)) > 0);
        __auto_type out = ((slop_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = h.dps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        if (gnew || (((int64_t)((kn.fparts).len)) > 0)) {
            {
                __auto_type _coll = h.ops;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type p = _coll.data[_i];
                    if (p.maxed && (gnew || sriqsat_k2_touched(arena, env, h, kn, p))) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

slop_list_sriqref_SuccAct sriqsat_sat_succ(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, slop_list_sriq_Premise ps) {
    {
        __auto_type kx = ((h.views) ? sriqindex_k_index_premises(arena, env.tr, h.aps) : sriqindex_k_index(arena, st.ord, env.tr, h.all));
        __auto_type base = sriqsat_unheld(arena, h.gd, kx.ground);
        __auto_type bare = ((sriqindex_KIdx){.ground = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .fparts = kx.fparts});
        __auto_type ts = sriqsat_triggers_of(arena, h, ps);
        __auto_type out = ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1062 = ({ __auto_type _lst = ts; size_t _idx = (size_t)0; slop_option_sriqsat_Trig _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1062.has_value) {
            return out;
        } else if (_mv_1062.has_value) {
            __auto_type t0 = _mv_1062.value;
            return sriqsat_succ_trigs(arena, env, st, h, bare, base, ts, t0);
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_sriqref_SuccAct sriqsat_succ_trigs(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriqindex_KIdx bare, slop_list_types_Lit base, slop_list_sriqsat_Trig ts, sriqsat_Trig t0) {
    {
        __auto_type sv = sriqsat_succ_view(arena, env, st, h, bare, base, t0.sg);
        __auto_type last = t0.sg;
        __auto_type out = ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (h.dfr) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqsat_succ_eval(arena, env, h, sv, t0.sg)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        {
            __auto_type _coll = ts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (sriqsat_sg_cmp(t.sg, last) != 0) {
                    sv = sriqsat_succ_view(arena, env, st, h, bare, base, t.sg);
                    last = t.sg;
                    if (h.dfr) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqsat_succ_eval(arena, env, h, sv, t.sg)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                if (!(h.dfr)) {
                    {
                        __auto_type _coll = sriqsat_succ_on(arena, env, h, sv, t);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type a = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        return out;
    }
}

sriqref_SuccAct sriqsat_succ_eval(slop_arena* arena, sriqref_Env env, sriqsat_Here h, sriqsat_SuccView sv, sriq_SuccSig sg) {
    {
        __auto_type k1 = sv.ks.k1;
        return ((sriqref_SuccAct){.from = h.v, .sg = sg, .core = sriqctx_core_of(arena, sriqctx_strat_choice(env.strat, env.tr, sg.f, k1), k1), .adds = sv.ks.k2});
    }
}

slop_list_sriqsat_Trig sriqsat_triggers_of(slop_arena* arena, sriqsat_Here h, slop_list_sriq_Premise ps) {
    {
        __auto_type raw = ((slop_list_sriqsat_Trig){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (p.maxed) {
                    __auto_type _mv_1063 = sriq_succ_sig(h.root, p.sel);
                    if (!_mv_1063.has_value) {
                    } else if (_mv_1063.has_value) {
                        __auto_type sg = _mv_1063.value;
                        ({ __auto_type _lst_p = &(raw); __auto_type _item = (((sriqsat_Trig){.p = p, .sg = sg})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        __auto_type _mv_1064 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_sriqsat_Trig _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1064.has_value) {
            return raw;
        } else if (_mv_1064.has_value) {
            __auto_type t0 = _mv_1064.value;
            return sriqsat_trigs_sorted(arena, raw, t0);
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_sriqsat_Trig sriqsat_trigs_sorted(slop_arena* arena, slop_list_sriqsat_Trig raw, sriqsat_Trig t0) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ sriqsat__lambda_1065_env_t* sriqsat__lambda_1065_env = (sriqsat__lambda_1065_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1065_env_t)); *sriqsat__lambda_1065_env = (sriqsat__lambda_1065_env_t){ .raw = raw, .t0 = t0 }; (slop_closure_t){ (void*)sriqsat__lambda_1065, (void*)sriqsat__lambda_1065_env }; }));
        __auto_type out = ((slop_list_sriqsat_Trig){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqsat_trig_at(raw, k, t0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

sriqsat_Trig sriqsat_trig_at(slop_list_sriqsat_Trig ts, int64_t k, sriqsat_Trig fallback) {
    __auto_type _mv_1066 = ({ __auto_type _lst = ts; size_t _idx = (size_t)k; slop_option_sriqsat_Trig _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1066.has_value) {
        __auto_type t = _mv_1066.value;
        return t;
    } else if (!_mv_1066.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

int64_t sriqsat_sg_cmp(sriq_SuccSig a, sriq_SuccSig b) {
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

sriqsat_SuccView sriqsat_succ_view(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriqindex_KIdx bare, slop_list_types_Lit base, sriq_SuccSig sg) {
    {
        __auto_type ks = sriqindex_k_query(arena, env.tr, bare, sg);
        __auto_type k2 = sriqsat_merged_lits(arena, base, sriqsat_unheld(arena, h.gd, ks.k2));
        return ((sriqsat_SuccView){.ks = ((sriq_KSets){.k1 = ks.k1, .k2 = k2}), .covered = (!(h.dfr) && sriqsat_covered_view(arena, env, st, h.v, sg.f, k2))});
    }
}

slop_list_sriqref_SuccAct sriqsat_succ_on(slop_arena* arena, sriqref_Env env, sriqsat_Here h, sriqsat_SuccView sv, sriqsat_Trig t) {
    {
        __auto_type r = sriq_succ_step(arena, env.strat, env.tr, t.sg, t.p, sv.ks, sv.covered);
        __auto_type out = ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (r.fires) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqref_SuccAct){.from = h.v, .sg = t.sg, .core = sriqctx_core_of(arena, r.choice, sv.ks.k1), .adds = r.adds})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return out;
    }
}

slop_list_types_Lit sriqsat_merged_lits(slop_arena* arena, slop_list_types_Lit a, slop_list_types_Lit b) {
    if (((int64_t)((b).len)) == 0) {
        return a;
    } else {
        {
            __auto_type xs = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = a;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type l = _coll.data[_i];
                    ({ __auto_type _lst_p = &(xs); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            {
                __auto_type _coll = b;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type l = _coll.data[_i];
                    ({ __auto_type _lst_p = &(xs); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            return sriqclauses_lit_set(arena, xs);
        }
    }
}

slop_list_types_Lit sriqsat_unheld(slop_arena* arena, sriqground_Ground gd, slop_list_types_Lit k2) {
    {
        __auto_type out = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = k2;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (!(sriqground_g_held(arena, gd, a))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

uint8_t sriqsat_covered_view(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, uint32_t f, slop_list_types_Lit k2) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = st.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (((e.from == v)) && ((e.lk == sriqctx_EdgeLabel_el_fn)) && ((e.label == f)) && (sriq_covers(k2, sriqref_core_at(env, st, arena, ((int64_t)(e.to))), sriqref_set_of(env, st, ((int64_t)(e.to)))))) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

sriqref_Out sriqsat_pred_anchored(slop_arena* arena, sriqref_Env env, sriqref_PJob job, sriqground_PIdx dix, sriqground_PIdx oix, sriqground_PIdx aix) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        int64_t i = 0;
        while (i < ((int64_t)(((int64_t)((job.slots).len))))) {
            {
                __auto_type o = sriqsat_pred_anchor(arena, env, job, dix, oix, aix, i);
                {
                    __auto_type _coll = o.cands;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                if (o.over) {
                    over = 1;
                }
                i = (i + 1);
            }
        }
        return sriqref_out_of(out, over);
    }
}

slop_list_sriq_Premise sriqsat_slot_ix(slop_arena* arena, sriq_CSub s, sriq_PSlot slot, sriqground_PIdx ix) {
    return sriqground_pidx_find(arena, ix, sriq_csub_lit(s, slot.lit));
}

sriqref_Out sriqsat_pred_anchor(slop_arena* arena, sriqref_Env env, sriqref_PJob job, sriqground_PIdx dix, sriqground_PIdx oix, sriqground_PIdx aix, int64_t i) {
    {
        __auto_type cs = ((slop_list_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        {
            __auto_type _coll = job.slots;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type slot = _coll.data[_i];
                ({ __auto_type _lst_p = &(cs); __auto_type _item = (sriqsat_slot_ix(arena, job.s, slot, sriqground_pick_ix(j, i, dix, oix, aix))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                j = (j + 1);
            }
        }
        return sriqsat_pred_choices(arena, env, job, cs, aix.ps);
    }
}

sriqref_Out sriqsat_pred_run_ix(slop_arena* arena, sriqref_Env env, sriqref_PJob job, sriqground_PIdx aix) {
    {
        __auto_type cs = ((slop_list_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = job.slots;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type slot = _coll.data[_i];
                ({ __auto_type _lst_p = &(cs); __auto_type _item = (sriqsat_slot_ix(arena, job.s, slot, aix)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return sriqsat_pred_choices(arena, env, job, cs, aix.ps);
    }
}

sriqref_Out sriqsat_pred_choices(slop_arena* arena, sriqref_Env env, sriqref_PJob job, slop_list_list_sriq_Premise cs, slop_list_sriq_Premise ps) {
    {
        __auto_type n = sriqref_product(cs, env.prod);
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t t = 0;
        if (n > env.prod) {
            return sriqref_out_of(out, 1);
        } else {
            while (t < n) {
                {
                    __auto_type _coll = sriqref_pred_one(arena, env, job, cs, t, ps);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                t = (t + 1);
            }
            return sriqref_out_of(out, 0);
        }
    }
}

sriqground_PIdx sriqsat_w_ix(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, int64_t w, slop_list_types_Clause cs, int64_t which) {
    {
        __auto_type x = sriqsat_cix_at(arena, h.ixs, w);
        if (which == 1) {
            return x.dix;
        } else if (which == 2) {
            return x.oix;
        } else {
            return x.aix;
        }
    }
}

sriqref_Out sriqsat_pred_side(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, sriqctx_Edge e) {
    {
        __auto_type w = ((int64_t)(e.from));
        __auto_type toroot = sriqref_is_root(st, ((int64_t)(e.from)));
        __auto_type aix = sriqsat_w_ix(arena, env, st, h, w, sriqref_set_of(env, st, w), 0);
        __auto_type dix = sriqsat_w_ix(arena, env, st, h, w, sriqsat_cs_at(dl.news, w, env.nobody), 1);
        __auto_type oix = sriqsat_w_ix(arena, env, st, h, w, sriqsat_cs_at(dl.olds, w, env.nobody), 2);
        __auto_type core = sriqref_core_at(env, st, arena, ((int64_t)(h.v)));
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        {
            __auto_type _coll = h.olds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type view = sriq_pred_view(arena, c, core, toroot);
                    __auto_type slots = sriqref_slots_of(arena, view.slots);
                    {
                        __auto_type _coll = sriqsat_side_jobs(arena, st, view, slots, e, toroot);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type job = _coll.data[_i];
                            {
                                __auto_type o = sriqsat_pred_anchored(arena, env, job, dix, oix, aix);
                                {
                                    __auto_type _coll = o.cands;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type x = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        return sriqref_out_of(out, over);
    }
}

sriqref_Out sriqsat_pred_edge_ix(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriqctx_Edge e, slop_list_types_Clause cs) {
    {
        __auto_type w = ((int64_t)(e.from));
        __auto_type toroot = sriqref_is_root(st, ((int64_t)(e.from)));
        __auto_type aix = sriqsat_w_ix(arena, env, st, h, w, sriqref_set_of(env, st, w), 0);
        __auto_type core = sriqref_core_at(env, st, arena, ((int64_t)(h.v)));
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type view = sriq_pred_view(arena, c, core, toroot);
                    __auto_type slots = sriqref_slots_of(arena, view.slots);
                    {
                        __auto_type _coll = sriqsat_side_jobs(arena, st, view, slots, e, toroot);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type job = _coll.data[_i];
                            {
                                __auto_type o = sriqsat_pred_run_ix(arena, env, job, aix);
                                {
                                    __auto_type _coll = o.cands;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type x = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        return sriqref_out_of(out, over);
    }
}

slop_list_sriqref_PJob sriqsat_side_jobs(slop_arena* arena, sriqctx_Structure st, sriq_PredView view, slop_list_sriq_PSlot slots, sriqctx_Edge e, uint8_t toroot) {
    {
        __auto_type out = ((slop_list_sriqref_PJob){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t u = 0;
        if (!(toroot)) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqref_away_job(view, slots, e.label, e.from)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else {
            while (u < sriqref_consts_of(st)) {
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqref_root_job(view, slots, e.from, e.label, ((uint32_t)(u)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                u = (u + 1);
            }
        }
        return out;
    }
}

sriqref_Out sriqsat_sat_pred(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, slop_list_sriqctx_Edge ins) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        {
            __auto_type _coll = ins;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (e.lk == sriqctx_EdgeLabel_el_fn) {
                    {
                        __auto_type _coll = sriqsat_pred_over(arena, env, st, dl, h, e);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type o = _coll.data[_i];
                            {
                                __auto_type _coll = o.cands;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type x = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        return sriqref_out_of(out, over);
    }
}

slop_list_sriqref_Out sriqsat_pred_over(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, sriqctx_Edge e) {
    {
        __auto_type out = ((slop_list_sriqref_Out){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type w = ((int64_t)(e.from));
        if (sriqsat_edge_new(dl, e) || (sriqref_is_root(st, w) && sriqsat_consts_new(st, dl))) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqsat_pred_edge_ix(arena, env, st, h, e, h.all)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqsat_pred_edge_ix(arena, env, st, h, e, h.news)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            if (((int64_t)((sriqsat_cs_at(dl.news, w, env.nobody)).len)) > 0) {
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqsat_pred_side(arena, env, st, dl, h, e)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

uint8_t sriqsat_rpred_edge_new(sriqsat_Delta dl, uint32_t v) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = dl.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (((e.from == v)) && ((e.to == ((uint32_t)(0)))) && ((e.lk == sriqctx_EdgeLabel_el_const))) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

sriqref_Out sriqsat_sat_rpred(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h) {
    if (h.fresh || sriqsat_rpred_edge_new(dl, h.v)) {
        return sriqsat_rpred_from(arena, env, st, h, h.rs.all, h.aps, 0);
    } else {
        {
            __auto_type a = sriqsat_rpred_from(arena, env, st, h, h.rs.news, h.aps, 0);
            __auto_type b = (((((int64_t)((h.news).len)) > 0)) ? sriqsat_rpred_from(arena, env, st, h, h.rs.olds, h.aps, 1) : sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0));
            return sriqref_out_of(sriqref_append_cands(arena, a.cands, b.cands), (a.over || b.over));
        }
    }
}

sriqref_Out sriqsat_rpred_from(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, slop_list_sriqsat_RSrc rs, slop_list_sriq_Premise aps, uint8_t anchored) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                {
                    __auto_type job = sriqsat_rsrc_job(arena, st, h.v, r);
                    __auto_type o = ((anchored) ? sriqsat_pred_anchored(arena, env, job, h.dix, h.oix, h.aix) : sriqsat_pred_run_ix(arena, env, job, h.aix));
                    {
                        __auto_type _coll = o.cands;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type x = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                    if (o.over) {
                        over = 1;
                    }
                }
            }
        }
        return sriqref_out_of(out, over);
    }
}

uint8_t sriqsat_rpred_able(sriqctx_Triggers tr, sriq_PredView v) {
    uint8_t _retval = {0};
    _retval = (v.ok && sriq_rpred_heads_ok(tr, v.head));
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval == (v.ok && sriq_rpred_heads_ok(tr, v.head)))), "(== $result (and (. v ok) (rpred-heads-ok tr (. v head))))");
    return _retval;
}

slop_list_sriqsat_RSrc sriqsat_rsrcs_in(slop_arena* arena, sriqctx_Triggers tr, slop_list_types_Clause cs) {
    {
        __auto_type out = ((slop_list_sriqsat_RSrc){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(sriqground_ground_clause(c))) {
                    {
                        __auto_type v = sriq_rpred_view(arena, tr, c);
                        if (sriqsat_rpred_able(tr, v)) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqsat_RSrc){.c = c, .view = v})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        return out;
    }
}

sriqsat_RSrcs sriqsat_rsrcs_of(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl) {
    return ((sriqsat_RSrcs){.all = sriqsat_rsrcs_in(arena, env.tr, sriqref_set_of(env, st, 0)), .news = sriqsat_rsrcs_in(arena, env.tr, sriqsat_cs_at(dl.news, 0, env.nobody)), .olds = sriqsat_rsrcs_in(arena, env.tr, sriqsat_cs_at(dl.olds, 0, env.nobody))});
}

sriqref_PJob sriqsat_rsrc_job(slop_arena* arena, sriqctx_Structure st, uint32_t v, sriqsat_RSrc r) {
    return ((sriqref_PJob){.view = r.view, .s = ((sriq_CSub){.x = types_at_x(), .y = types_at_x()}), .slots = sriqref_rslots(arena, st, v, r.view.slots), .to = v, .rpred = 1, .toroot = 0});
}

sriqctx_Structure sriqsat_local(sriqctx_Structure st, sriqsat_Adj a, slop_arena* arena) {
    {
        __auto_type es = ((slop_list_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = a.outs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                ({ __auto_type _lst_p = &(es); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = a.ins;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                ({ __auto_type _lst_p = &(es); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((sriqctx_Structure){.ctxs = st.ctxs, .sets = st.sets, .edges = es, .ord = st.ord});
    }
}

sriqsat_CRound sriqsat_sat_ctx(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, slop_list_sriqsat_CIdx ixs, sriqsat_RSrcs rs, sriqctx_Structure st, sriqsat_Delta dl, sriqground_Ground gd, sriqsat_Adj a, int64_t v, int64_t perm, uint8_t dfr, uint8_t views, int64_t room) {
    {
        __auto_type lst = sriqsat_local(st, a, arena);
        if ((v >= dl.nctx) && sriqref_is_root(st, v)) {
            {
                __auto_type r = sriqref_ctx_round(arena, sriqref_with_room(env, room), lst, ((uint32_t)(v)));
                return ((sriqsat_CRound){.r = r, .tried = 0, .big = (((int64_t)(((int64_t)((r.cands).len)))) > room)});
            }
        } else {
            return sriqsat_sat_old(arena, env, lst, dl, a.ins, sriqsat_here_of(arena, env, lst, dl, gd, hx, ixs, rs, v, perm, dfr, views), room);
        }
    }
}

sriqsat_CRound sriqsat_sat_old(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, slop_list_sriqctx_Edge ins, sriqsat_Here h, int64_t room) {
    {
        __auto_type t2 = sriqsat_sat_table2(arena, env, st, dl, h, room);
        if (((int64_t)(((int64_t)((t2.out.cands).len)))) > room) {
            return ((sriqsat_CRound){.r = sriqref_round_of(t2.out.cands, ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), t2.out.over), .tried = t2.tried, .big = 1});
        } else {
            return sriqsat_sat_old_rest(arena, env, st, dl, ins, h, room, t2);
        }
    }
}

sriqsat_CRound sriqsat_sat_old_rest(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, slop_list_sriqctx_Edge ins, sriqsat_Here h, int64_t room, sriqhyper_HOut t2) {
    {
        __auto_type t2c = t2.out.cands;
        __auto_type nom = sriqsat_sat_nom(arena, env, st, dl, h);
        __auto_type skip = sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0);
        __auto_type pr = (((h.root || !(sriqsat_within(t2c, nom.cands, room)))) ? skip : sriqsat_sat_pred(arena, env, st, dl, h, ins));
        __auto_type rp = (((h.root || !(sriqsat_within(t2c, sriqref_append_cands(arena, nom.cands, pr.cands), room)))) ? skip : sriqsat_sat_rpred(arena, env, st, dl, h));
        __auto_type cands = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = t2c;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = nom.cands;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = pr.cands;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = rp.cands;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(cands); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type big = (((int64_t)(((int64_t)((cands).len)))) > room);
            return ((sriqsat_CRound){.r = sriqref_round_of(cands, ((big) ? ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) : sriqsat_sat_succ(arena, env, st, h, sriqsat_succ_premises(arena, env, st, h))), (((big || h.root)) ? ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) : sriqref_ref_rsucc(arena, env, st, h.v, h.dps)), nom.noms, ((t2.out.over) || (pr.over) || (rp.over))), .tried = t2.tried, .big = big});
        }
    }
}

sriqctx_Edge sriqsat_edge_at(slop_list_sriqctx_Edge es, int64_t k, sriqctx_Edge fallback) {
    __auto_type _mv_1067 = ({ __auto_type _lst = es; size_t _idx = (size_t)k; slop_option_sriqctx_Edge _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1067.has_value) {
        __auto_type e = _mv_1067.value;
        return e;
    } else if (!_mv_1067.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_list_sriqsat_Adj sriqsat_adjacency(slop_arena* arena, sriqctx_Structure st) {
    {
        __auto_type es = st.edges;
        __auto_type n = ((int64_t)(((int64_t)((st.ctxs).len))));
        __auto_type e0 = ((sriqctx_Edge){.from = ((uint32_t)(0)), .to = ((uint32_t)(0)), .lk = sriqctx_EdgeLabel_el_fn, .label = ((uint32_t)(0))});
        __auto_type by_to = canon_sort_range(arena, ((int64_t)(((int64_t)((st.edges).len)))), ({ sriqsat__lambda_1068_env_t* sriqsat__lambda_1068_env = (sriqsat__lambda_1068_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1068_env_t)); *sriqsat__lambda_1068_env = (sriqsat__lambda_1068_env_t){ .es = es, .e0 = e0 }; (slop_closure_t){ (void*)sriqsat__lambda_1068, (void*)sriqsat__lambda_1068_env }; }));
        __auto_type by_from = canon_sort_range(arena, ((int64_t)(((int64_t)((st.edges).len)))), ({ sriqsat__lambda_1069_env_t* sriqsat__lambda_1069_env = (sriqsat__lambda_1069_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1069_env_t)); *sriqsat__lambda_1069_env = (sriqsat__lambda_1069_env_t){ .es = es, .e0 = e0 }; (slop_closure_t){ (void*)sriqsat__lambda_1069, (void*)sriqsat__lambda_1069_env }; }));
        __auto_type ins = sriqsat_buckets(arena, es, by_to, n, 1, e0);
        __auto_type outs = sriqsat_buckets(arena, es, by_from, n, 0, e0);
        __auto_type out = ((slop_list_sriqsat_Adj){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        while (v < n) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqsat_Adj){.ins = sriqsat_edges_at(arena, ins, v), .outs = sriqsat_edges_at(arena, outs, v)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            v = (v + 1);
        }
        return out;
    }
}

slop_list_sriqctx_Edge sriqsat_edges_at(slop_arena* arena, slop_list_sriqsat_Bucket bs, int64_t v) {
    __auto_type _mv_1070 = ({ __auto_type _lst = bs; size_t _idx = (size_t)v; slop_option_sriqsat_Bucket _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1070.has_value) {
        __auto_type b = _mv_1070.value;
        return b.es;
    } else if (!_mv_1070.has_value) {
        return ((slop_list_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

int64_t sriqsat_u32_cmp(uint32_t a, uint32_t b) {
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    } else {
        return 0;
    }
}

sriqsat_Cut sriqsat_cut_at(slop_arena* arena, slop_list_sriqctx_Edge es, slop_list_int idx, int64_t k, int64_t v, uint8_t by_to, sriqctx_Edge e0) {
    {
        __auto_type cur = ((slop_list_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = k;
        uint8_t going = 1;
        while (going && (i < ((int64_t)(((int64_t)((idx).len)))))) {
            {
                __auto_type e = sriqsat_edge_at(es, sriqsat_idx_at(idx, i), e0);
                if (((int64_t)(((by_to) ? e.to : e.from))) == v) {
                    ({ __auto_type _lst_p = &(cur); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    i = (i + 1);
                } else {
                    going = 0;
                }
            }
        }
        return ((sriqsat_Cut){.es = cur, .k = i});
    }
}

slop_list_sriqsat_Bucket sriqsat_buckets(slop_arena* arena, slop_list_sriqctx_Edge es, slop_list_int idx, int64_t n, uint8_t by_to, sriqctx_Edge e0) {
    {
        __auto_type out = ((slop_list_sriqsat_Bucket){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        int64_t v = 0;
        while (v < n) {
            {
                __auto_type c = sriqsat_cut_at(arena, es, idx, k, v, by_to, e0);
                ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqsat_Bucket){.es = c.es})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                k = c.k;
                v = (v + 1);
            }
        }
        return out;
    }
}

int64_t sriqsat_idx_at(slop_list_int idx, int64_t k) {
    __auto_type _mv_1071 = ({ __auto_type _lst = idx; size_t _idx = (size_t)k; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1071.has_value) {
        __auto_type i = _mv_1071.value;
        return i;
    } else if (!_mv_1071.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqsat_passes(sriqsat_CRound cr, slop_list_sriqref_Cand cands, int64_t room) {
    return (cr.big || (((int64_t)(((int64_t)((cands).len)))) > room));
}

sriqsat_CRound sriqsat_sat_round(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, sriqctx_Structure st, sriqsat_Delta dl, sriqground_Ground gd, int64_t perm, uint8_t dfr, slop_list_sriqsat_View vw, int64_t room) {
    {
        __auto_type adj = sriqsat_adjacency(arena, st);
        __auto_type views = (((int64_t)((vw).len)) > 0);
        __auto_type ixs = sriqsat_all_ixs(arena, env, st, dl, perm, vw);
        __auto_type rs = sriqsat_rsrcs_of(arena, env, st, dl);
        __auto_type cands = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type succs = ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type rsuccs = ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type noms = ((slop_list_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        int64_t tried = 0;
        uint8_t big = 0;
        {
            __auto_type _coll = sriqsat_ctx_order(arena, ((int64_t)(((int64_t)((st.ctxs).len)))), perm);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type v = _coll.data[_i];
                __auto_type _mv_1072 = ({ __auto_type _lst = adj; size_t _idx = (size_t)v; slop_option_sriqsat_Adj _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (!_mv_1072.has_value) {
                } else if (_mv_1072.has_value) {
                    __auto_type a = _mv_1072.value;
                    if (!(big)) {
                        {
                            __auto_type cr = sriqsat_sat_ctx(arena, env, hx, ixs, rs, st, dl, gd, a, v, perm, dfr, views, (room - ((int64_t)(((int64_t)((cands).len))))));
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
                            if (sriqsat_passes(cr, cands, room)) {
                                big = 1;
                            }
                        }
                    }
                }
            }
        }
        return ((sriqsat_CRound){.r = sriqref_round_of(cands, succs, rsuccs, noms, over), .tried = tried, .big = big});
    }
}

slop_list_sriqref_Cand sriqsat_new_cores(slop_arena* arena, sriqctx_Structure st, int64_t from) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        {
            __auto_type _coll = st.ctxs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (v >= from) {
                    {
                        __auto_type _coll = sriqref_ref_core(arena, ((uint32_t)(v)), c.core);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type x = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                v = (v + 1);
            }
        }
        return out;
    }
}

sriqsat_Step sriqsat_sat_apply(slop_arena* arena, sriqctx_Structure st, sriqground_Ground gd, sriqref_Round r, uint8_t scan, uint8_t dfr, slop_list_sriqsat_Supply trig, slop_list_sriqsat_Flags fl) {
    {
        __auto_type sup = ((dfr) ? sriqsat_supplied(arena, trig, r.succs) : ((sriqsat_Supplied){.trig = trig, .evals = ((slop_list_sriqsat_Supply){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .grew = 0}));
        __auto_type n0 = sriqref_consts_of(st);
        __auto_type c0 = ((int64_t)(((int64_t)((st.ctxs).len))));
        __auto_type e0 = ((int64_t)(((int64_t)((st.edges).len))));
        __auto_type s1 = ((sriqctx_Structure){.ctxs = st.ctxs, .sets = st.sets, .edges = st.edges, .ord = sriqref_add_consts(arena, st.ord, r.noms)});
        __auto_type s2 = sriqref_add_contexts(arena, s1, r.succs);
        __auto_type s3 = ((scan) ? sriqref_add_edges(arena, s2, r.succs, r.rsuccs) : sriqsat_edges_added(arena, s2, r.succs, r.rsuccs));
        __auto_type cands = sriqref_append_cands(arena, sriqref_append_cands(arena, r.cands, sriqsat_succ_cands(arena, s3, r, sup, dfr)), sriqsat_new_cores(arena, s3, c0));
        __auto_type sp = sriqsat_commit_all(arena, s3, sriqsat_outside_view(arena, s3, gd, cands), c0, e0, n0, scan, fl);
        if (dfr) {
            return sriqsat_deferred_step(arena, sp, e0, trig, sup);
        } else {
            return sp;
        }
    }
}

slop_list_sriqref_Cand sriqsat_succ_cands(slop_arena* arena, sriqctx_Structure st, sriqref_Round r, sriqsat_Supplied sup, uint8_t dfr) {
    if (dfr) {
        return sriqref_append_cands(arena, sriqref_action_cands(arena, st, ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), r.rsuccs), sriqsat_pushed(arena, st, sup.evals));
    } else {
        return sriqref_action_cands(arena, st, r.succs, r.rsuccs);
    }
}

sriqctx_Structure sriqsat_edges_added(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_SuccAct succs, slop_list_sriqref_RSuccAct rsuccs) {
    {
        __auto_type news = sriqsat_action_edges(arena, st, succs, rsuccs);
        __auto_type es = ((slop_list_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                ({ __auto_type _lst_p = &(es); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqsat_first_new(arena, st.edges, news);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                ({ __auto_type _lst_p = &(es); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((sriqctx_Structure){.ctxs = st.ctxs, .sets = st.sets, .edges = es, .ord = st.ord});
    }
}

slop_list_sriqctx_Edge sriqsat_action_edges(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_SuccAct succs, slop_list_sriqref_RSuccAct rsuccs) {
    {
        __auto_type out = ((slop_list_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = succs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    __auto_type w = sriqctx_ctx_by_core(st, a.core);
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqctx_Edge){.from = a.from, .to = w, .lk = sriqctx_EdgeLabel_el_fn, .label = a.sg.f})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    if (a.sg.root) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqctx_Edge){.from = a.from, .to = w, .lk = sriqctx_EdgeLabel_el_const, .label = a.sg.u})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type _coll = rsuccs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqctx_Edge){.from = a.from, .to = ((uint32_t)(0)), .lk = sriqctx_EdgeLabel_el_const, .label = a.u})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_sriqctx_Edge sriqsat_first_new(slop_arena* arena, slop_list_sriqctx_Edge old, slop_list_sriqctx_Edge news) {
    __auto_type _mv_1073 = ({ __auto_type _lst = news; size_t _idx = (size_t)0; slop_option_sriqctx_Edge _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1073.has_value) {
        return ((slop_list_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    } else if (_mv_1073.has_value) {
        __auto_type e0 = _mv_1073.value;
        return sriqsat_in_news_order(arena, news, sriqsat_kept_positions(arena, old, news, e0), e0);
    }
    SLOP_UNREACHABLE();
}

slop_list_int sriqsat_kept_positions(slop_arena* arena, slop_list_sriqctx_Edge old, slop_list_sriqctx_Edge news, sriqctx_Edge e0) {
    {
        __auto_type oidx = canon_sort_range(arena, ((int64_t)(((int64_t)((old).len)))), ({ sriqsat__lambda_1074_env_t* sriqsat__lambda_1074_env = (sriqsat__lambda_1074_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1074_env_t)); *sriqsat__lambda_1074_env = (sriqsat__lambda_1074_env_t){ .old = old, .e0 = e0 }; (slop_closure_t){ (void*)sriqsat__lambda_1074, (void*)sriqsat__lambda_1074_env }; }));
        __auto_type nidx = canon_sort_range(arena, ((int64_t)(((int64_t)((news).len)))), ({ sriqsat__lambda_1075_env_t* sriqsat__lambda_1075_env = (sriqsat__lambda_1075_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1075_env_t)); *sriqsat__lambda_1075_env = (sriqsat__lambda_1075_env_t){ .news = news, .e0 = e0 }; (slop_closure_t){ (void*)sriqsat__lambda_1075, (void*)sriqsat__lambda_1075_env }; }));
        __auto_type keep = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t prev = -1;
        {
            __auto_type _coll = nidx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                if (sriqsat_run_first_new(old, oidx, news, prev, k, e0)) {
                    ({ __auto_type _lst_p = &(keep); __auto_type _item = (k); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                prev = k;
            }
        }
        return keep;
    }
}

uint8_t sriqsat_run_first_new(slop_list_sriqctx_Edge old, slop_list_int oidx, slop_list_sriqctx_Edge news, int64_t prev, int64_t k, sriqctx_Edge e0) {
    {
        __auto_type e = sriqsat_edge_at(news, k, e0);
        return (((prev < 0) || (sriqsat_edge_cmp(sriqsat_edge_at(news, prev, e0), e) != 0)) && !(sriqsat_edge_in(old, oidx, e, e0)));
    }
}

slop_list_sriqctx_Edge sriqsat_in_news_order(slop_arena* arena, slop_list_sriqctx_Edge news, slop_list_int keep, sriqctx_Edge e0) {
    {
        __auto_type out = ((slop_list_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = canon_sort_range(arena, ((int64_t)(((int64_t)((keep).len)))), ({ sriqsat__lambda_1076_env_t* sriqsat__lambda_1076_env = (sriqsat__lambda_1076_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1076_env_t)); *sriqsat__lambda_1076_env = (sriqsat__lambda_1076_env_t){ .keep = keep }; (slop_closure_t){ (void*)sriqsat__lambda_1076, (void*)sriqsat__lambda_1076_env }; }));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqsat_edge_at(news, sriqsat_idx_at(keep, k), e0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

uint8_t sriqsat_edge_in(slop_list_sriqctx_Edge es, slop_list_int idx, sriqctx_Edge e, sriqctx_Edge e0) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((idx).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                if (sriqsat_edge_cmp(sriqsat_edge_at(es, sriqsat_idx_at(idx, mid), e0), e) < 0) {
                    lo = (mid + 1);
                } else {
                    hi = mid;
                }
            }
        }
        return ((lo < ((int64_t)(((int64_t)((idx).len))))) && (sriqsat_edge_cmp(sriqsat_edge_at(es, sriqsat_idx_at(idx, lo), e0), e) == 0));
    }
}

int64_t sriqsat_edge_cmp(sriqctx_Edge a, sriqctx_Edge b) {
    if (a.from != b.from) {
        return sriqsat_u32_cmp(a.from, b.from);
    } else if (a.to != b.to) {
        return sriqsat_u32_cmp(a.to, b.to);
    } else if (sriqsat_lk_rank(a.lk) != sriqsat_lk_rank(b.lk)) {
        return sriqsat_int_cmp(sriqsat_lk_rank(a.lk), sriqsat_lk_rank(b.lk));
    } else {
        return sriqsat_u32_cmp(a.label, b.label);
    }
}

int64_t sriqsat_lk_rank(sriqctx_EdgeLabel lk) {
    __auto_type _mv_1077 = lk;
    if (_mv_1077 == sriqctx_EdgeLabel_el_fn) {
        return 0;
    } else if (_mv_1077 == sriqctx_EdgeLabel_el_const) {
        return 1;
    }
    SLOP_UNREACHABLE();
}

int64_t sriqsat_int_cmp(int64_t a, int64_t b) {
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    } else {
        return 0;
    }
}

slop_list_sriqref_Cand sriqsat_outside_view(slop_arena* arena, sriqctx_Structure st, sriqground_Ground gd, slop_list_sriqref_Cand cands) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cands;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (sriqref_is_root(st, ((int64_t)(c.ctx))) || !(sriqground_g_in_hat(gd, c.c))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

sriqsat_Step sriqsat_commit_all(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_Cand cands, int64_t c0, int64_t e0, int64_t n0, uint8_t scan, slop_list_sriqsat_Flags fl) {
    {
        __auto_type none_such = ((sriqref_Cand){.ctx = ((uint32_t)(0)), .c = ((types_Clause){.body = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .head = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })})});
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((cands).len)))), ({ sriqsat__lambda_1078_env_t* sriqsat__lambda_1078_env = (sriqsat__lambda_1078_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1078_env_t)); *sriqsat__lambda_1078_env = (sriqsat__lambda_1078_env_t){ .cands = cands, .none_such = none_such }; (slop_closure_t){ (void*)sriqsat__lambda_1078, (void*)sriqsat__lambda_1078_env }; }));
        __auto_type sets = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type news = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type olds = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type nfl = ((slop_list_sriqsat_Flags){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type none_fs = ((slop_list_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        int64_t v = 0;
        uint8_t grew = 0;
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                {
                    __auto_type mine = sriqsat_run_of(arena, cands, idx, k, ((uint32_t)(v)), none_such);
                    {
                        __auto_type cm = sriqsat_commit_one(arena, s.cs, mine, scan);
                        ({ __auto_type _lst_p = &(sets); __auto_type _item = (((sriqctx_CtxSet){.cs = cm.set})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(nfl); __auto_type _item = (((sriqsat_Flags){.fs = sriqsat_new_flags(arena, st.ord, s.cs, sriqsat_fs_at(fl, v, none_fs), cm, ((int64_t)((mine).len)))})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(news); __auto_type _item = (((sriqctx_CtxSet){.cs = cm.added})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(olds); __auto_type _item = (((sriqctx_CtxSet){.cs = sriqsat_minus_sorted(arena, cm.set, cm.added)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        if (((int64_t)((cm.added).len)) > 0) {
                            grew = 1;
                        }
                        k = (k + ((int64_t)(((int64_t)((mine).len)))));
                        v = (v + 1);
                    }
                }
            }
        }
        return ((sriqsat_Step){.st = ((sriqctx_Structure){.ctxs = st.ctxs, .sets = sets, .edges = st.edges, .ord = st.ord}), .dl = ((sriqsat_Delta){.news = news, .olds = olds, .edges = sriqsat_edges_from(arena, st.edges, e0), .nctx = c0, .ncst = n0}), .changed = ((grew) || ((((int64_t)(((int64_t)((st.ctxs).len)))) != c0)) || ((((int64_t)(((int64_t)((st.edges).len)))) != e0)) || ((sriqref_consts_of(st) != n0))), .trig = ((slop_list_sriqsat_Supply){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .acts = 0, .flags = nfl});
    }
}

slop_list_list_u8 sriqsat_new_flags(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Clause ws, slop_list_list_u8 wf, sriqsubsume_Committed cm, int64_t ncands) {
    if (ncands == 0) {
        return wf;
    } else {
        return sriqsat_walked_flags(arena, ord, ws, wf, cm.set);
    }
}

slop_list_types_Clause sriqsat_run_of(slop_arena* arena, slop_list_sriqref_Cand cands, slop_list_int idx, int64_t k, uint32_t v, sriqref_Cand none_such) {
    {
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = k;
        uint8_t going = 1;
        while (going && (i < ((int64_t)(((int64_t)((idx).len)))))) {
            {
                __auto_type x = sriqref_cand_at(cands, sriqsat_idx_at(idx, i), none_such);
                if (x.ctx == v) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x.c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    i = (i + 1);
                } else {
                    going = 0;
                }
            }
        }
        return out;
    }
}

sriqsubsume_Committed sriqsat_commit_one(slop_arena* arena, slop_list_types_Clause ws, slop_list_types_Clause cs, uint8_t scan) {
    if (((int64_t)((cs).len)) == 0) {
        return ((sriqsubsume_Committed){.set = ws, .added = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
    } else if (scan) {
        return sriqsubsume_commit_min(arena, ws, cs);
    } else {
        return sriqindex_commit_indexed(arena, ws, cs);
    }
}

slop_list_types_Clause sriqsat_minus_sorted(slop_arena* arena, slop_list_types_Clause xs, slop_list_types_Clause ys) {
    {
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                __auto_type _mv_1079 = ({ __auto_type _lst = ys; size_t _idx = (size_t)j; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1079.has_value) {
                    __auto_type y = _mv_1079.value;
                    if (sriqclauses_clause_cmp(x, y) == 0) {
                        j = (j + 1);
                    } else {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                } else if (!_mv_1079.has_value) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

slop_list_sriqctx_Edge sriqsat_edges_from(slop_arena* arena, slop_list_sriqctx_Edge es, int64_t k) {
    {
        __auto_type out = ((slop_list_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = es;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (i >= k) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                i = (i + 1);
            }
        }
        return out;
    }
}

slop_list_sriqsat_View sriqsat_views_of(slop_arena* arena, sriqctx_Structure st, slop_list_sriqsat_Flags fl) {
    {
        __auto_type out = ((slop_list_sriqsat_View){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        __auto_type none_fs = ((slop_list_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqsat_View){.cs = x.cs, .fs = ({ __auto_type _mv = ({ __auto_type _lst = fl; size_t _idx = (size_t)v; slop_option_sriqsat_Flags _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type f = _mv.value; f.fs; }) : (none_fs); })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                v = (v + 1);
            }
        }
        return out;
    }
}

slop_list_sriq_Premise sriqsat_premises_in(slop_arena* arena, sriqctx_Structure st, slop_list_sriqsat_View vw, int64_t v, slop_list_types_Clause cs) {
    __auto_type _mv_1080 = ({ __auto_type _lst = vw; size_t _idx = (size_t)v; slop_option_sriqsat_View _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1080.has_value) {
        return sriqref_premises_of(arena, st.ord, cs);
    } else if (_mv_1080.has_value) {
        __auto_type w = _mv_1080.value;
        {
            __auto_type out = ((slop_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = cs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    {
                        __auto_type _coll = sriqsat_clause_premises(arena, c, sriqsat_flags_of(arena, st.ord, w, c));
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

slop_list_sriq_Premise sriqsat_clause_premises(slop_arena* arena, types_Clause c, slop_list_u8 fs) {
    {
        __auto_type out = ((slop_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = c.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriq_Premise){.body = c.body, .sel = l, .rest = sriqsat_head_without(arena, c.head, i), .maxed = sriqsat_flag_at(fs, i)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                i = (i + 1);
            }
        }
        return out;
    }
}

slop_list_types_Lit sriqsat_head_without(slop_arena* arena, slop_list_types_Lit xs, int64_t i) {
    {
        __auto_type out = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (k != i) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                k = (k + 1);
            }
        }
        return out;
    }
}

uint8_t sriqsat_flag_at(slop_list_u8 fs, int64_t i) {
    __auto_type _mv_1081 = ({ __auto_type _lst = fs; size_t _idx = (size_t)i; slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1081.has_value) {
        __auto_type b = _mv_1081.value;
        return b;
    } else if (!_mv_1081.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_list_u8 sriqsat_flags_of(slop_arena* arena, sriqorder_SriqOrder ord, sriqsat_View w, types_Clause c) {
    {
        __auto_type k = sriqsat_clause_pos(w.cs, c);
        __auto_type _mv_1082 = ({ __auto_type _lst = w.fs; size_t _idx = (size_t)k; slop_option_list_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1082.has_value) {
            __auto_type fs = _mv_1082.value;
            if (sriqsat_sorted_at(w.cs, k, c)) {
                return fs;
            } else {
                return sriqorder_max_flags(arena, ord, c.head);
            }
        } else if (!_mv_1082.has_value) {
            return sriqorder_max_flags(arena, ord, c.head);
        }
        SLOP_UNREACHABLE();
    }
}

int64_t sriqsat_clause_pos(slop_list_types_Clause cs, types_Clause c) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((cs).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                __auto_type _mv_1083 = ({ __auto_type _lst = cs; size_t _idx = (size_t)mid; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1083.has_value) {
                    __auto_type x = _mv_1083.value;
                    if (sriqclauses_clause_cmp(x, c) < 0) {
                        lo = (mid + 1);
                    } else {
                        hi = mid;
                    }
                } else if (!_mv_1083.has_value) {
                    hi = mid;
                }
            }
        }
        return lo;
    }
}

uint8_t sriqsat_sorted_at(slop_list_types_Clause cs, int64_t k, types_Clause c) {
    __auto_type _mv_1084 = ({ __auto_type _lst = cs; size_t _idx = (size_t)k; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1084.has_value) {
        __auto_type x = _mv_1084.value;
        return (sriqclauses_clause_cmp(x, c) == 0);
    } else if (!_mv_1084.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_list_list_u8 sriqsat_walked_flags(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Clause ws, slop_list_list_u8 wf, slop_list_types_Clause set) {
    {
        __auto_type out = ((slop_list_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        {
            __auto_type _coll = set;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                while (sriqsat_below_at(ws, j, c)) {
                    j = (j + 1);
                }
                ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqsat_sorted_at(ws, j, c)) ? ({ __auto_type _mv = ({ __auto_type _lst = wf; size_t _idx = (size_t)j; slop_option_list_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type f = _mv.value; f; }) : (sriqorder_max_flags(arena, ord, c.head)); }) : sriqorder_max_flags(arena, ord, c.head))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

uint8_t sriqsat_below_at(slop_list_types_Clause cs, int64_t j, types_Clause c) {
    __auto_type _mv_1085 = ({ __auto_type _lst = cs; size_t _idx = (size_t)j; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1085.has_value) {
        __auto_type w = _mv_1085.value;
        return (sriqclauses_clause_cmp(w, c) < 0);
    } else if (!_mv_1085.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_list_list_u8 sriqsat_fs_at(slop_list_sriqsat_Flags fl, int64_t v, slop_list_list_u8 none_fs) {
    __auto_type _mv_1086 = ({ __auto_type _lst = fl; size_t _idx = (size_t)v; slop_option_sriqsat_Flags _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1086.has_value) {
        __auto_type f = _mv_1086.value;
        return f.fs;
    } else if (!_mv_1086.has_value) {
        return none_fs;
    }
    SLOP_UNREACHABLE();
}

slop_list_sriqsat_Flags sriqsat_empty_flags(slop_arena* arena, sriqctx_Structure st) {
    {
        __auto_type out = ((slop_list_sriqsat_Flags){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqsat_Flags){.fs = sriqsat_walked_flags(arena, st.ord, ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), x.cs)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_sriqsat_Flags sriqsat_copy_flags(slop_arena* arena, slop_list_sriqsat_Flags fl) {
    {
        __auto_type out = ((slop_list_sriqsat_Flags){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
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
                                        ({ __auto_type _lst_p = &(b); __auto_type _item = (y); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                ({ __auto_type _lst_p = &(fs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqsat_Flags){.fs = fs})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

int64_t sriqsat_stale_flags(slop_arena* arena, sriqctx_Structure st, slop_list_sriqsat_Flags fl) {
    {
        int64_t n = 0;
        int64_t v = 0;
        __auto_type none_fs = ((slop_list_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                n = (n + sriqsat_stale_in(arena, st.ord, x.cs, sriqsat_fs_at(fl, v, none_fs)));
                v = (v + 1);
            }
        }
        return n;
    }
}

int64_t sriqsat_stale_in(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Clause cs, slop_list_list_u8 fs) {
    {
        int64_t n = (((((int64_t)((fs).len)) == ((int64_t)((cs).len)))) ? 0 : 1);
        int64_t k = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(sriqsat_same_flags(({ __auto_type _mv = ({ __auto_type _lst = fs; size_t _idx = (size_t)k; slop_option_list_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type f = _mv.value; f; }) : (((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena })); }), sriqorder_max_flags(arena, ord, c.head)))) {
                    n = (n + 1);
                }
                k = (k + 1);
            }
        }
        return n;
    }
}

uint8_t sriqsat_same_flags(slop_list_u8 a, slop_list_u8 b) {
    {
        uint8_t ok = (((int64_t)((a).len)) == ((int64_t)((b).len)));
        int64_t i = 0;
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (x != sriqsat_flag_at(b, i)) {
                    ok = 0;
                }
                i = (i + 1);
            }
        }
        return ok;
    }
}

uint8_t sriqsat_defer_on(sriqsat_SatConfig cfg, sriqref_RefIn in) {
    return ((cfg.defer) && ((in.nconst == 0)) && (!((cfg.base.strat == sriqctx_Strategy_st_eager))));
}

int64_t sriqsat_key_cmp(uint32_t w1, uint32_t f1, uint32_t w2, uint32_t f2) {
    if (w1 != w2) {
        return sriqsat_u32_cmp(w1, w2);
    } else {
        return sriqsat_u32_cmp(f1, f2);
    }
}

int64_t sriqsat_supply_cmp(sriqsat_Supply a, sriqsat_Supply b) {
    return sriqsat_key_cmp(a.from, a.f, b.from, b.f);
}

sriqsat_Supply sriqsat_supply_at(slop_list_sriqsat_Supply xs, int64_t k, sriqsat_Supply fallback) {
    __auto_type _mv_1087 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_sriqsat_Supply _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1087.has_value) {
        __auto_type x = _mv_1087.value;
        return x;
    } else if (!_mv_1087.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_list_types_Lit sriqsat_supply_of(slop_list_sriqsat_Supply trig, uint32_t w, uint32_t f, slop_list_types_Lit nolits) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((trig).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                __auto_type _mv_1088 = ({ __auto_type _lst = trig; size_t _idx = (size_t)mid; slop_option_sriqsat_Supply _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1088.has_value) {
                    __auto_type x = _mv_1088.value;
                    if (sriqsat_key_cmp(x.from, x.f, w, f) < 0) {
                        lo = (mid + 1);
                    } else {
                        hi = mid;
                    }
                } else if (!_mv_1088.has_value) {
                    hi = mid;
                }
            }
        }
        __auto_type _mv_1089 = ({ __auto_type _lst = trig; size_t _idx = (size_t)lo; slop_option_sriqsat_Supply _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1089.has_value) {
            __auto_type x = _mv_1089.value;
            if (sriqsat_key_cmp(x.from, x.f, w, f) == 0) {
                return x.lits;
            } else {
                return nolits;
            }
        } else if (!_mv_1089.has_value) {
            return nolits;
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t sriqsat_lit_member(slop_list_types_Lit ls, types_Lit l) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((ls).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                __auto_type _mv_1090 = ({ __auto_type _lst = ls; size_t _idx = (size_t)mid; slop_option_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1090.has_value) {
                    __auto_type x = _mv_1090.value;
                    if (types_lit_cmp(x, l) < 0) {
                        lo = (mid + 1);
                    } else {
                        hi = mid;
                    }
                } else if (!_mv_1090.has_value) {
                    hi = mid;
                }
            }
        }
        __auto_type _mv_1091 = ({ __auto_type _lst = ls; size_t _idx = (size_t)lo; slop_option_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1091.has_value) {
            __auto_type x = _mv_1091.value;
            return (types_lit_cmp(x, l) == 0);
        } else if (!_mv_1091.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t sriqsat_body_within(types_Clause c, slop_list_types_Lit core, slop_list_types_Lit lits) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!((sriqsat_lit_member(core, l) || sriqsat_lit_member(lits, l)))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t sriqsat_supported(types_Clause c, slop_list_types_Lit core, slop_list_sriqctx_Edge ins, slop_list_sriqsat_Supply trig, slop_list_types_Lit nolits) {
    {
        uint8_t ok = sriqsat_body_within(c, core, nolits);
        {
            __auto_type _coll = ins;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if ((!(ok)) && ((e.lk == sriqctx_EdgeLabel_el_fn)) && (sriqsat_body_within(c, core, sriqsat_supply_of(trig, e.from, e.label, nolits)))) {
                    ok = 1;
                }
            }
        }
        return ok;
    }
}

slop_list_sriqctx_Edge sriqsat_ins_at(slop_arena* arena, slop_list_sriqsat_Adj adj, int64_t v) {
    __auto_type _mv_1092 = ({ __auto_type _lst = adj; size_t _idx = (size_t)v; slop_option_sriqsat_Adj _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1092.has_value) {
        __auto_type a = _mv_1092.value;
        return a.ins;
    } else if (!_mv_1092.has_value) {
        return ((slop_list_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

sriqsat_Seen sriqsat_projected(slop_arena* arena, sriqctx_Structure st, sriqsat_Delta dl, slop_list_sriqsat_Supply trig) {
    {
        __auto_type adj = sriqsat_adjacency(arena, st);
        __auto_type nolits = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type nobody = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type sets = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type news = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type olds = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        {
            __auto_type _coll = st.ctxs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type ins = sriqsat_ins_at(arena, adj, v);
                    ({ __auto_type _lst_p = &(sets); __auto_type _item = (sriqsat_narrowed(arena, sriqsat_cs_at(st.sets, v, nobody), c, ins, trig, nolits)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(news); __auto_type _item = (sriqsat_narrowed(arena, sriqsat_cs_at(dl.news, v, nobody), c, ins, trig, nolits)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(olds); __auto_type _item = (sriqsat_narrowed(arena, sriqsat_cs_at(dl.olds, v, nobody), c, ins, trig, nolits)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    v = (v + 1);
                }
            }
        }
        return ((sriqsat_Seen){.st = ((sriqctx_Structure){.ctxs = st.ctxs, .sets = sets, .edges = st.edges, .ord = st.ord}), .dl = ((sriqsat_Delta){.news = news, .olds = olds, .edges = dl.edges, .nctx = dl.nctx, .ncst = dl.ncst})});
    }
}

sriqctx_CtxSet sriqsat_narrowed(slop_arena* arena, slop_list_types_Clause cs, sriqctx_Ctx c, slop_list_sriqctx_Edge ins, slop_list_sriqsat_Supply trig, slop_list_types_Lit nolits) {
    if (c.root) {
        return ((sriqctx_CtxSet){.cs = cs});
    } else {
        {
            __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = cs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type x = _coll.data[_i];
                    if (sriqsat_supported(x, c.core, ins, trig, nolits)) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
            return ((sriqctx_CtxSet){.cs = out});
        }
    }
}

sriqsat_Supplied sriqsat_supplied(slop_arena* arena, slop_list_sriqsat_Supply trig, slop_list_sriqref_SuccAct succs) {
    {
        __auto_type raw = ((slop_list_sriqsat_Supply){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = trig;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(raw); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = succs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(raw); __auto_type _item = (((sriqsat_Supply){.from = a.from, .f = a.sg.f, .lits = a.adds})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        __auto_type _mv_1093 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_sriqsat_Supply _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1093.has_value) {
            return ((sriqsat_Supplied){.trig = trig, .evals = ((slop_list_sriqsat_Supply){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .grew = 0});
        } else if (_mv_1093.has_value) {
            __auto_type s0 = _mv_1093.value;
            return sriqsat_supplies_merged(arena, raw, ((int64_t)(((int64_t)((trig).len)))), s0);
        }
        SLOP_UNREACHABLE();
    }
}

sriqsat_Supplied sriqsat_supplies_merged(slop_arena* arena, slop_list_sriqsat_Supply raw, int64_t nold, sriqsat_Supply s0) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ sriqsat__lambda_1094_env_t* sriqsat__lambda_1094_env = (sriqsat__lambda_1094_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1094_env_t)); *sriqsat__lambda_1094_env = (sriqsat__lambda_1094_env_t){ .raw = raw, .s0 = s0 }; (slop_closure_t){ (void*)sriqsat__lambda_1094, (void*)sriqsat__lambda_1094_env }; }));
        __auto_type trig = ((slop_list_sriqsat_Supply){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type evals = ((slop_list_sriqsat_Supply){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t grew = 0;
        int64_t k = 0;
        while (k < ((int64_t)(((int64_t)((idx).len))))) {
            {
                __auto_type g = sriqsat_supply_group(arena, raw, idx, k, nold, s0);
                ({ __auto_type _lst_p = &(trig); __auto_type _item = (g.s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                if (g.evald) {
                    ({ __auto_type _lst_p = &(evals); __auto_type _item = (g.s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                if (g.grew) {
                    grew = 1;
                }
                k = g.next;
            }
        }
        return ((sriqsat_Supplied){.trig = trig, .evals = evals, .grew = grew});
    }
}

sriqsat_Group sriqsat_supply_group(slop_arena* arena, slop_list_sriqsat_Supply raw, slop_list_int idx, int64_t k, int64_t nold, sriqsat_Supply s0) {
    {
        __auto_type first = sriqsat_supply_at(raw, sriqsat_idx_at(idx, k), s0);
        __auto_type lits = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t before = 0;
        uint8_t evald = 0;
        int64_t i = k;
        uint8_t going = 1;
        while (going && (i < ((int64_t)(((int64_t)((idx).len)))))) {
            {
                __auto_type j = sriqsat_idx_at(idx, i);
                __auto_type x = sriqsat_supply_at(raw, sriqsat_idx_at(idx, i), s0);
                if (sriqsat_supply_cmp(x, first) == 0) {
                    {
                        __auto_type _coll = x.lits;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type l = _coll.data[_i];
                            ({ __auto_type _lst_p = &(lits); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
            __auto_type u = sriqclauses_lit_set(arena, lits);
            return ((sriqsat_Group){.s = ((sriqsat_Supply){.from = first.from, .f = first.f, .lits = u}), .evald = evald, .grew = (((int64_t)(((int64_t)((u).len)))) > before), .next = i});
        }
    }
}

slop_list_types_Lit sriqsat_ctx_core(slop_arena* arena, sriqctx_Structure st, uint32_t v) {
    __auto_type _mv_1095 = ({ __auto_type _lst = st.ctxs; size_t _idx = (size_t)((int64_t)(v)); slop_option_sriqctx_Ctx _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1095.has_value) {
        __auto_type c = _mv_1095.value;
        return c.core;
    } else if (!_mv_1095.has_value) {
        return ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

slop_list_sriqref_Cand sriqsat_pushed(slop_arena* arena, sriqctx_Structure st, slop_list_sriqsat_Supply evals) {
    {
        __auto_type nolits = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (e.lk == sriqctx_EdgeLabel_el_fn) {
                    {
                        __auto_type core = sriqsat_ctx_core(arena, st, e.to);
                        {
                            __auto_type _coll = sriqsat_supply_of(evals, e.from, e.label, nolits);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type a = _coll.data[_i];
                                if (!(sriqsat_lit_member(core, a))) {
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqref_Cand){.ctx = e.to, .c = sriqref_unit_clause(arena, a)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

slop_list_sriqctx_Edge sriqsat_edges_before(slop_arena* arena, slop_list_sriqctx_Edge es, int64_t k) {
    {
        __auto_type out = ((slop_list_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = es;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (i < k) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                i = (i + 1);
            }
        }
        return out;
    }
}

sriqsat_Step sriqsat_deferred_step(slop_arena* arena, sriqsat_Step sp, int64_t e0, slop_list_sriqsat_Supply old, sriqsat_Supplied sup) {
    {
        __auto_type a = sriqsat_activated(arena, sp.st, sp.dl, e0, old, sup.trig);
        return ((sriqsat_Step){.st = sp.st, .dl = a.dl, .changed = (sp.changed || sup.grew), .trig = sup.trig, .acts = a.n, .flags = sp.flags});
    }
}

sriqsat_Acted sriqsat_activated(slop_arena* arena, sriqctx_Structure st, sriqsat_Delta dl, int64_t e0, slop_list_sriqsat_Supply old, slop_list_sriqsat_Supply trig) {
    {
        __auto_type was = ((sriqctx_Structure){.ctxs = st.ctxs, .sets = st.sets, .edges = sriqsat_edges_before(arena, st.edges, e0), .ord = st.ord});
        __auto_type adj = sriqsat_adjacency(arena, st);
        __auto_type adj0 = sriqsat_adjacency(arena, was);
        __auto_type nolits = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type nobody = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type news = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type olds = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t n = 0;
        int64_t v = 0;
        {
            __auto_type _coll = st.ctxs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type m = sriqsat_acted_in(arena, c, sriqsat_cs_at(dl.news, v, nobody), sriqsat_cs_at(dl.olds, v, nobody), sriqsat_ins_at(arena, adj, v), sriqsat_ins_at(arena, adj0, v), old, trig, nolits);
                    ({ __auto_type _lst_p = &(news); __auto_type _item = (((sriqctx_CtxSet){.cs = m.news})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(olds); __auto_type _item = (((sriqctx_CtxSet){.cs = m.olds})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    n = (n + m.n);
                    v = (v + 1);
                }
            }
        }
        return ((sriqsat_Acted){.dl = ((sriqsat_Delta){.news = news, .olds = olds, .edges = dl.edges, .nctx = dl.nctx, .ncst = dl.ncst}), .n = n});
    }
}

sriqsat_Moved sriqsat_acted_in(slop_arena* arena, sriqctx_Ctx c, slop_list_types_Clause news, slop_list_types_Clause olds, slop_list_sriqctx_Edge ins, slop_list_sriqctx_Edge ins0, slop_list_sriqsat_Supply old, slop_list_sriqsat_Supply trig, slop_list_types_Lit nolits) {
    if (c.root || !(sriqsat_ins_grew(ins, ins0, old, trig, nolits))) {
        return ((sriqsat_Moved){.news = news, .olds = olds, .n = 0});
    } else {
        {
            __auto_type up = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            __auto_type rest = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = olds;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type x = _coll.data[_i];
                    if (sriqsat_supported(x, c.core, ins, trig, nolits) && !(sriqsat_supported(x, c.core, ins0, old, nolits))) {
                        ({ __auto_type _lst_p = &(up); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else {
                        ({ __auto_type _lst_p = &(rest); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
            return ((sriqsat_Moved){.news = sriqsat_merged_sorted(arena, news, up), .olds = rest, .n = ((int64_t)(((int64_t)((up).len))))});
        }
    }
}

uint8_t sriqsat_ins_grew(slop_list_sriqctx_Edge ins, slop_list_sriqctx_Edge ins0, slop_list_sriqsat_Supply old, slop_list_sriqsat_Supply trig, slop_list_types_Lit nolits) {
    {
        uint8_t grew = (((int64_t)((ins).len)) != ((int64_t)((ins0).len)));
        {
            __auto_type _coll = ins;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (((int64_t)((sriqsat_supply_of(trig, e.from, e.label, nolits)).len)) > ((int64_t)((sriqsat_supply_of(old, e.from, e.label, nolits)).len))) {
                    grew = 1;
                }
            }
        }
        return grew;
    }
}

slop_list_types_Clause sriqsat_merged_sorted(slop_arena* arena, slop_list_types_Clause xs, slop_list_types_Clause ys) {
    {
        __auto_type n = (((int64_t)(((int64_t)((xs).len)))) + ((int64_t)(((int64_t)((ys).len)))));
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        int64_t j = 0;
        while ((i + j) < n) {
            if (sriqsat_y_first(xs, ys, i, j)) {
                __auto_type _mv_1096 = ({ __auto_type _lst = ys; size_t _idx = (size_t)j; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1096.has_value) {
                    __auto_type y = _mv_1096.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (y); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1096.has_value) {
                }
                j = (j + 1);
            } else {
                __auto_type _mv_1097 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1097.has_value) {
                    __auto_type x = _mv_1097.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1097.has_value) {
                }
                i = (i + 1);
            }
        }
        return out;
    }
}

uint8_t sriqsat_y_first(slop_list_types_Clause xs, slop_list_types_Clause ys, int64_t i, int64_t j) {
    __auto_type _mv_1098 = ({ __auto_type _lst = ys; size_t _idx = (size_t)j; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1098.has_value) {
        return 0;
    } else if (_mv_1098.has_value) {
        __auto_type y = _mv_1098.value;
        __auto_type _mv_1099 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1099.has_value) {
            __auto_type x = _mv_1099.value;
            return (sriqclauses_clause_cmp(y, x) < 0);
        } else if (!_mv_1099.has_value) {
            return 1;
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_list_sriqsat_Supply sriqsat_copy_trig(slop_arena* arena, slop_list_sriqsat_Supply trig) {
    {
        __auto_type out = ((slop_list_sriqsat_Supply){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = trig;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                {
                    __auto_type ls = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    {
                        __auto_type _coll = x.lits;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type l = _coll.data[_i];
                            ({ __auto_type _lst_p = &(ls); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqsat_Supply){.from = x.from, .f = x.f, .lits = ls})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

sriqsat_Delta sriqsat_first_delta(slop_arena* arena, sriqctx_Structure st) {
    {
        __auto_type news = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type olds = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                ({ __auto_type _lst_p = &(news); __auto_type _item = (((sriqctx_CtxSet){.cs = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(olds); __auto_type _item = (((sriqctx_CtxSet){.cs = s.cs})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((sriqsat_Delta){.news = news, .olds = olds, .edges = ((slop_list_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .nctx = 0, .ncst = 0});
    }
}

sriqsat_Delta sriqsat_copy_delta(slop_arena* arena, sriqsat_Delta dl) {
    {
        __auto_type news = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type olds = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type es = ((slop_list_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = dl.news;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                ({ __auto_type _lst_p = &(news); __auto_type _item = (((sriqctx_CtxSet){.cs = sriqref_copy_clauses(arena, s.cs)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = dl.olds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                ({ __auto_type _lst_p = &(olds); __auto_type _item = (((sriqctx_CtxSet){.cs = sriqref_copy_clauses(arena, s.cs)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = dl.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                ({ __auto_type _lst_p = &(es); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((sriqsat_Delta){.news = news, .olds = olds, .edges = es, .nctx = dl.nctx, .ncst = dl.ncst});
    }
}

int64_t sriqsat_into_v(slop_list_sriqref_Cand cs, uint32_t v) {
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

int64_t sriqsat_sum_added(sriqsat_Delta dl) {
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

sriqsat_Counts sriqsat_tally(sriqsat_Counts c, sriqref_Round r, sriqsat_Delta dl, int64_t tried, int64_t acts, int64_t stale) {
    return ((sriqsat_Counts){.cands = (c.cands + ((int64_t)(((int64_t)((r.cands).len))))), .rcands = (c.rcands + sriqsat_into_v(r.cands, ((uint32_t)(0)))), .succs = (c.succs + ((int64_t)(((int64_t)((r.succs).len))))), .rsuccs = (c.rsuccs + ((int64_t)(((int64_t)((r.rsuccs).len))))), .noms = (c.noms + ((int64_t)(((int64_t)((r.noms).len))))), .added = (c.added + (sriqsat_sum_added(dl) - acts)), .acts = (c.acts + acts), .hyper = (c.hyper + tried), .stale = (c.stale + stale)});
}

sriqsat_Step sriqsat_with_units(slop_arena* arena, sriqctx_Triggers tr, sriqsat_Step sp) {
    {
        __auto_type st = sp.st;
        __auto_type dl = sp.dl;
        __auto_type nobody = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type gd = sriqground_ground_of(arena, tr, st, sriqsat_cs_at(dl.news, 0, nobody));
        __auto_type units = sriqground_g_root_units(arena, tr, gd);
        if (((int64_t)((units).len)) == 0) {
            return sp;
        } else {
            {
                __auto_type cm = sriqindex_commit_indexed(arena, sriqsat_cs_at(st.sets, 0, nobody), units);
                if (((int64_t)((cm.added).len)) == 0) {
                    return sp;
                } else {
                    return ((sriqsat_Step){.st = sriqsat_with_root_set(arena, st, cm.set), .dl = sriqsat_with_root_news(arena, dl, cm.set, cm.added, nobody), .changed = 1, .trig = sp.trig, .acts = sp.acts, .flags = sriqsat_with_root_flags(arena, st.ord, sriqsat_cs_at(st.sets, 0, nobody), sp.flags, cm.set)});
                }
            }
        }
    }
}

slop_list_sriqsat_Flags sriqsat_with_root_flags(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Clause ws, slop_list_sriqsat_Flags fl, slop_list_types_Clause set) {
    {
        __auto_type none_fs = ((slop_list_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type out = ((slop_list_sriqsat_Flags){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        {
            __auto_type _coll = fl;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = ((((v == 0)) ? ((sriqsat_Flags){.fs = sriqsat_walked_flags(arena, ord, ws, sriqsat_fs_at(fl, 0, none_fs), set)}) : f)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                v = (v + 1);
            }
        }
        return out;
    }
}

sriqctx_Structure sriqsat_with_root_set(slop_arena* arena, sriqctx_Structure st, slop_list_types_Clause cs) {
    {
        __auto_type sets = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                ({ __auto_type _lst_p = &(sets); __auto_type _item = ((((v == 0)) ? ((sriqctx_CtxSet){.cs = cs}) : s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                v = (v + 1);
            }
        }
        return ((sriqctx_Structure){.ctxs = st.ctxs, .sets = sets, .edges = st.edges, .ord = st.ord});
    }
}

sriqsat_Delta sriqsat_with_root_news(slop_arena* arena, sriqsat_Delta dl, slop_list_types_Clause set, slop_list_types_Clause added, slop_list_types_Clause nobody) {
    {
        __auto_type was = sriqsat_cs_at(dl.news, 0, nobody);
        __auto_type news = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type olds = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = set;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (sriqsat_sorted_in(was, c) || sriqsat_sorted_in(added, c)) {
                    ({ __auto_type _lst_p = &(news); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else {
                    ({ __auto_type _lst_p = &(olds); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return ((sriqsat_Delta){.news = sriqsat_with_first(arena, dl.news, news), .olds = sriqsat_with_first(arena, dl.olds, olds), .edges = dl.edges, .nctx = dl.nctx, .ncst = dl.ncst});
    }
}

slop_list_sriqctx_CtxSet sriqsat_with_first(slop_arena* arena, slop_list_sriqctx_CtxSet xs, slop_list_types_Clause cs) {
    {
        __auto_type out = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = ((((v == 0)) ? ((sriqctx_CtxSet){.cs = cs}) : x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                v = (v + 1);
            }
        }
        return out;
    }
}

uint8_t sriqsat_sorted_in(slop_list_types_Clause cs, types_Clause c) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((cs).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                __auto_type _mv_1100 = ({ __auto_type _lst = cs; size_t _idx = (size_t)mid; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1100.has_value) {
                    __auto_type x = _mv_1100.value;
                    if (sriqclauses_clause_cmp(x, c) < 0) {
                        lo = (mid + 1);
                    } else {
                        hi = mid;
                    }
                } else if (!_mv_1100.has_value) {
                    hi = mid;
                }
            }
        }
        __auto_type _mv_1101 = ({ __auto_type _lst = cs; size_t _idx = (size_t)lo; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1101.has_value) {
            __auto_type x = _mv_1101.value;
            return (sriqclauses_clause_cmp(x, c) == 0);
        } else if (!_mv_1101.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

sriqref_RefStatus sriqsat_sat_stop(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint8_t changed, sriqref_RefConfig cfg) {
    if (!(changed)) {
        return sriqref_RefStatus_rs_fixpoint;
    } else if (sriqsat_holds_bot(arena, st, 1) || sriqsat_holds_bot(arena, st, 0)) {
        return sriqref_RefStatus_rs_inconsistent;
    } else if (((int64_t)(((int64_t)((st.ctxs).len)))) > cfg.ctxs) {
        return sriqref_RefStatus_rs_contexts;
    } else if (sriqground_view_total(st) > cfg.cls) {
        return sriqref_RefStatus_rs_clauses;
    } else if ((sriqref_consts_of(st) - env.nconst) > cfg.cnst) {
        return sriqref_RefStatus_rs_constants;
    } else {
        return sriqref_RefStatus_rs_fuel;
    }
}

uint8_t sriqsat_holds_bot(slop_arena* arena, sriqctx_Structure st, int64_t v) {
    __auto_type _mv_1102 = ({ __auto_type _lst = st.sets; size_t _idx = (size_t)v; slop_option_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1102.has_value) {
        __auto_type s = _mv_1102.value;
        return sriqsubsume_in_hat(sriqclauses_make_clause(arena, ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })), s.cs);
    } else if (!_mv_1102.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

sriqsat_Run sriqsat_sat_once(slop_arena* next, slop_arena* scratch, sriqref_Env env, sriqhyper_HIdx hx, sriqsat_SatConfig cfg, uint8_t dfr, sriqsat_Run run) {
    {
        __auto_type gd = sriqground_ground_of(scratch, env.tr, run.st, sriqsat_cs_at(run.dl.news, 0, env.nobody));
        __auto_type seen = ((dfr) ? sriqsat_projected(scratch, run.st, run.dl, run.trig) : ((sriqsat_Seen){.st = run.st, .dl = run.dl}));
        __auto_type vw = ((cfg.views) ? sriqsat_views_of(scratch, run.st, run.flags) : ((slop_list_sriqsat_View){ .data = NULL, .len = 0, .cap = 0, .arena = scratch }));
        __auto_type sr = sriqsat_sat_round(scratch, env, hx, seen.st, seen.dl, gd, cfg.perm, dfr, vw, (cfg.base.cls - sriqground_view_total(run.st)));
        __auto_type r = sr.r;
        if (r.over || sr.big) {
            return ((sriqsat_Run){.st = run.st, .dl = run.dl, .status = ((sr.big) ? sriqref_RefStatus_rs_clauses : sriqref_RefStatus_rs_product), .rounds = run.rounds, .going = 0, .trig = run.trig, .flags = run.flags, .counts = run.counts});
        } else {
            {
                __auto_type sp = sriqsat_with_units(scratch, env.tr, sriqsat_sat_apply(scratch, run.st, gd, r, cfg.scan, dfr, run.trig, run.flags));
                __auto_type st = sriqref_copy_structure(next, sp.st);
                __auto_type stale = ((cfg.check) ? sriqsat_stale_flags(scratch, sp.st, sp.flags) : 0);
                __auto_type status = sriqsat_sat_stop(scratch, env, st, sp.changed, cfg.base);
                return ((sriqsat_Run){.st = st, .dl = sriqsat_copy_delta(next, sp.dl), .status = status, .rounds = (run.rounds + 1), .going = (status == sriqref_RefStatus_rs_fuel), .trig = sriqsat_copy_trig(next, sp.trig), .flags = sriqsat_copy_flags(next, sp.flags), .counts = sriqsat_tally(run.counts, r, sp.dl, sr.tried, sp.acts, stale)});
            }
        }
    }
}

sriqctx_Structure sriqsat_read_view(slop_arena* arena, sriqctx_Structure st) {
    if (!(sriqsat_holds_bot(arena, st, 0))) {
        return st;
    } else {
        {
            __auto_type sets = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            int64_t v = 0;
            {
                __auto_type _coll = st.sets;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type s = _coll.data[_i];
                    if (sriqref_is_root(st, v)) {
                        ({ __auto_type _lst_p = &(sets); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else {
                        {
                            __auto_type one = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                            ({ __auto_type _lst_p = &(one); __auto_type _item = (sriqclauses_make_clause(arena, ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(sets); __auto_type _item = (((sriqctx_CtxSet){.cs = one})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                    v = (v + 1);
                }
            }
            return ((sriqctx_Structure){.ctxs = st.ctxs, .sets = sets, .edges = st.edges, .ord = st.ord});
        }
    }
}

sriqctx_Structure sriqsat_sat_materialise(slop_arena* arena, sriqref_RefIn in, sriqctx_Structure st) {
    return sriqground_materialise(arena, sriqctx_build_triggers(arena, in.onto, in.nclass, in.nrole, in.nfn), st);
}

uint8_t sriqsat_defer_stable(slop_arena* arena, sriqref_RefIn in, sriqsat_SatConfig cfg, sriqsat_SatResult p) {
    {
        __auto_type base = cfg.base;
        __auto_type tr = sriqctx_build_triggers(arena, in.onto, in.nclass, in.nrole, in.nfn);
        __auto_type env = sriqref_env_of(arena, in, base, tr, (((base.lam >= 0)) ? base.lam : sriqref_ref_lambda(tr, base.strat, sriqref_initial_queries(in))));
        __auto_type st = p.res.st;
        __auto_type r = sriqref_ref_round(arena, env, sriqsat_projected(arena, st, sriqsat_first_delta(arena, st), p.trig).st);
        return ((!(r.over)) && (!(sriqref_ref_apply(arena, st, r).changed)) && (sriqsat_units_pushed(arena, st, p.trig)));
    }
}

uint8_t sriqsat_units_pushed(slop_arena* arena, sriqctx_Structure st, slop_list_sriqsat_Supply trig) {
    {
        __auto_type nolits = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type nobody = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t ok = 1;
        {
            __auto_type _coll = st.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (e.lk == sriqctx_EdgeLabel_el_fn) {
                    {
                        __auto_type core = sriqsat_ctx_core(arena, st, e.to);
                        __auto_type cs = sriqsat_cs_at(st.sets, ((int64_t)(e.to)), nobody);
                        {
                            __auto_type _coll = sriqsat_supply_of(trig, e.from, e.label, nolits);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type a = _coll.data[_i];
                                if (!((sriqsat_lit_member(core, a) || sriqsubsume_in_hat(sriqref_unit_clause(arena, a), cs)))) {
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

uint8_t sriqsat_hyper_ix_agrees(slop_arena* arena, sriqref_RefIn in, sriqsat_SatConfig cfg, sriqctx_Structure st) {
    {
        __auto_type base = cfg.base;
        __auto_type tr = sriqctx_build_triggers(arena, in.onto, in.nclass, in.nrole, in.nfn);
        __auto_type env = sriqref_env_of(arena, in, base, tr, sriqref_ref_lambda(tr, base.strat, sriqref_initial_queries(in)));
        __auto_type hx = sriqhyper_h_index(arena, in.onto);
        __auto_type gd = sriqground_ground_of(arena, tr, st, env.nobody);
        __auto_type dl = sriqsat_first_delta(arena, st);
        __auto_type ixs = sriqsat_all_ixs(arena, env, st, dl, 0, ((slop_list_sriqsat_View){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        __auto_type rs = sriqsat_rsrcs_of(arena, env, st, dl);
        uint8_t ok = 1;
        int64_t v = 0;
        {
            __auto_type _coll = st.ctxs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(sriqsat_hyper_ix_one(arena, env, hx, sriqsat_here_of(arena, env, st, dl, gd, hx, ixs, rs, v, 0, 0, 0)))) {
                    ok = 0;
                }
                v = (v + 1);
            }
        }
        return ok;
    }
}

uint8_t sriqsat_hyper_ix_one(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, sriqsat_Here h) {
    {
        __auto_type mine = sriqhyper_hyper_indexed(arena, env, hx, sriqsat_hctx_of(h), sriqsat_ROOM_OFF);
        __auto_type start = sriq_hyper_start(arena, types_at_x(), !(h.root));
        __auto_type theirs = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = mine.out.over;
        {
            __auto_type _coll = hx.bodied;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type oc = _coll.data[_i];
                {
                    __auto_type o = sriqref_hyper_with(arena, env, h.v, h.root, start, oc, h.aps);
                    {
                        __auto_type _coll = o.cands;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            ({ __auto_type _lst_p = &(theirs); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                    if (o.over) {
                        over = 1;
                    }
                }
            }
        }
        return (over || sriqsat_same_cands(arena, mine.out.cands, theirs));
    }
}

uint8_t sriqsat_same_cands(slop_arena* arena, slop_list_sriqref_Cand a, slop_list_sriqref_Cand b) {
    {
        __auto_type x = sriqsat_distinct_clauses(arena, a);
        __auto_type y = sriqsat_distinct_clauses(arena, b);
        uint8_t ok = 1;
        int64_t i = 0;
        if (((int64_t)((x).len)) != ((int64_t)((y).len))) {
            ok = 0;
        }
        {
            __auto_type _coll = x;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                __auto_type _mv_1103 = ({ __auto_type _lst = y; size_t _idx = (size_t)i; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1103.has_value) {
                    __auto_type d = _mv_1103.value;
                    if (sriqclauses_clause_cmp(c, d) != 0) {
                        ok = 0;
                    }
                } else if (!_mv_1103.has_value) {
                    ok = 0;
                }
                i = (i + 1);
            }
        }
        return ok;
    }
}

slop_list_types_Clause sriqsat_distinct_clauses(slop_arena* arena, slop_list_sriqref_Cand cs) {
    {
        __auto_type raw = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(raw); __auto_type _item = (c.c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        __auto_type _mv_1104 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1104.has_value) {
            return raw;
        } else if (_mv_1104.has_value) {
            __auto_type c0 = _mv_1104.value;
            return sriqsat_sorted_distinct(arena, raw, c0);
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_types_Clause sriqsat_sorted_distinct(slop_arena* arena, slop_list_types_Clause raw, types_Clause c0) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ sriqsat__lambda_1105_env_t* sriqsat__lambda_1105_env = (sriqsat__lambda_1105_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1105_env_t)); *sriqsat__lambda_1105_env = (sriqsat__lambda_1105_env_t){ .raw = raw, .c0 = c0 }; (slop_closure_t){ (void*)sriqsat__lambda_1105, (void*)sriqsat__lambda_1105_env }; }));
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type c = sriqsat_clause_of_l(raw, k, c0);
                    __auto_type _mv_1106 = ({ __auto_type _lst = out; size_t _idx = (size_t)(((int64_t)(((int64_t)((out).len)))) - 1); slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_1106.has_value) {
                        __auto_type last = _mv_1106.value;
                        if (sriqclauses_clause_cmp(last, c) != 0) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    } else if (!_mv_1106.has_value) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

types_Clause sriqsat_clause_of_l(slop_list_types_Clause cs, int64_t k, types_Clause fallback) {
    __auto_type _mv_1107 = ({ __auto_type _lst = cs; size_t _idx = (size_t)k; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1107.has_value) {
        __auto_type c = _mv_1107.value;
        return c;
    } else if (!_mv_1107.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

sriqctx_Structure sriqsat_ranked_structure(sriqctx_Structure st, int64_t nquery) {
    SLOP_PRE(((nquery >= 0)), "(>= nquery 0)");
    return ((sriqctx_Structure){.ctxs = st.ctxs, .sets = st.sets, .edges = st.edges, .ord = sriqorder_ranked(st.ord, nquery)});
}

sriqsat_SatResult sriqsat_sat_run(slop_arena* arena, sriqref_RefIn in, sriqsat_SatConfig cfg) {
    {
        __auto_type base = cfg.base;
        __auto_type tr = sriqctx_build_triggers(arena, in.onto, in.nclass, in.nrole, in.nfn);
        __auto_type lam = (((base.lam >= 0)) ? base.lam : sriqref_ref_lambda(tr, base.strat, sriqref_initial_queries(in)));
        __auto_type env = sriqref_env_of(arena, in, base, tr, lam);
        __auto_type hx = sriqhyper_h_index(arena, in.onto);
        __auto_type st0 = sriqsat_ranked_structure(sriqref_init_of(arena, in), in.nquery);
        __auto_type dfr = sriqsat_defer_on(cfg, in);
        __auto_type held = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        uint8_t cancelled = 0;
        uint8_t capped = 0;
        __auto_type run = ((sriqsat_Run){.st = st0, .dl = sriqsat_first_delta(arena, st0), .status = sriqref_RefStatus_rs_fuel, .rounds = 0, .going = 1, .trig = ((slop_list_sriqsat_Supply){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .flags = sriqsat_empty_flags(arena, st0), .counts = ((sriqsat_Counts){.cands = 0, .rcands = 0, .succs = 0, .rsuccs = 0, .noms = 0, .added = 0, .acts = 0, .hyper = 0, .stale = 0})});
        while ((run.going) && (!(cancelled)) && (!(capped))) {
            if (types_cancel_requested(cfg.cancel)) {
                cancelled = 1;
            } else if (run.rounds >= base.fuel) {
                capped = 1;
            } else {
                {
                    __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                    __auto_type next = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                    __auto_type nr = sriqsat_sat_once(next, scratch, env, hx, cfg, dfr, run);
                    if (nr.rounds == run.rounds) {
                        ({ slop_arena_free(next); free(next); });
                    } else {
                        ({ slop_arena_free(held); free(held); });
                        held = next;
                    }
                    ({ slop_arena_free(scratch); free(scratch); });
                    run = nr;
                }
            }
        }
        {
            __auto_type done = sriqref_copy_structure(arena, sriqsat_read_view(arena, run.st));
            __auto_type trig = sriqsat_copy_trig(arena, run.trig);
            ({ slop_arena_free(held); free(held); });
            return ((sriqsat_SatResult){.res = ((sriqref_RefResult){.status = run.status, .rounds = run.rounds, .st = done}), .counts = run.counts, .trig = trig, .cancelled = cancelled});
        }
    }
}

