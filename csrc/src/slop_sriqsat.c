#include "../runtime/slop_runtime.h"
#include "slop_sriqsat.h"

slop_list_types_Clause sriqsat_cs_at(slop_list_sriqctx_CtxSet xs, int64_t v, slop_list_types_Clause nobody);
slop_list_types_Clause sriqsat_permuted(slop_arena* arena, slop_list_types_Clause xs, int64_t perm);
slop_list_int sriqsat_ctx_order(slop_arena* arena, int64_t n, int64_t perm);
sriqsat_CIdx sriqsat_ctx_ix(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, int64_t v, int64_t perm);
slop_list_sriqsat_CIdx sriqsat_all_ixs(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, int64_t perm);
sriqsat_CIdx sriqsat_cix_at(slop_arena* arena, slop_list_sriqsat_CIdx ixs, int64_t v);
sriqsat_Here sriqsat_here_of(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqground_Ground gd, sriqhyper_HIdx hx, slop_list_sriqsat_CIdx ixs, int64_t v, int64_t perm);
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
sriqref_Out sriqsat_rpred_from(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, slop_list_types_Clause cs, slop_list_sriq_Premise aps, uint8_t anchored);
sriqctx_Structure sriqsat_local(sriqctx_Structure st, sriqsat_Adj a, slop_arena* arena);
sriqsat_CRound sriqsat_sat_ctx(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, slop_list_sriqsat_CIdx ixs, sriqctx_Structure st, sriqsat_Delta dl, sriqground_Ground gd, sriqsat_Adj a, int64_t v, int64_t perm);
sriqsat_CRound sriqsat_sat_old(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, slop_list_sriqctx_Edge ins, sriqsat_Here h);
sriqctx_Edge sriqsat_edge_at(slop_list_sriqctx_Edge es, int64_t k, sriqctx_Edge fallback);
slop_list_sriqsat_Adj sriqsat_adjacency(slop_arena* arena, sriqctx_Structure st);
slop_list_sriqctx_Edge sriqsat_edges_at(slop_arena* arena, slop_list_sriqsat_Bucket bs, int64_t v);
int64_t sriqsat_u32_cmp(uint32_t a, uint32_t b);
sriqsat_Cut sriqsat_cut_at(slop_arena* arena, slop_list_sriqctx_Edge es, slop_list_int idx, int64_t k, int64_t v, uint8_t by_to, sriqctx_Edge e0);
slop_list_sriqsat_Bucket sriqsat_buckets(slop_arena* arena, slop_list_sriqctx_Edge es, slop_list_int idx, int64_t n, uint8_t by_to, sriqctx_Edge e0);
int64_t sriqsat_idx_at(slop_list_int idx, int64_t k);
sriqsat_CRound sriqsat_sat_round(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, sriqctx_Structure st, sriqsat_Delta dl, sriqground_Ground gd, int64_t perm);
slop_list_sriqref_Cand sriqsat_new_cores(slop_arena* arena, sriqctx_Structure st, int64_t from);
sriqsat_Step sriqsat_sat_apply(slop_arena* arena, sriqctx_Structure st, sriqground_Ground gd, sriqref_Round r, uint8_t scan);
slop_list_sriqref_Cand sriqsat_outside_view(slop_arena* arena, sriqctx_Structure st, sriqground_Ground gd, slop_list_sriqref_Cand cands);
sriqsat_Step sriqsat_commit_all(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_Cand cands, int64_t c0, int64_t e0, int64_t n0, uint8_t scan);
slop_list_types_Clause sriqsat_run_of(slop_arena* arena, slop_list_sriqref_Cand cands, slop_list_int idx, int64_t k, uint32_t v, sriqref_Cand none_such);
sriqsubsume_Committed sriqsat_commit_one(slop_arena* arena, slop_list_types_Clause ws, slop_list_types_Clause cs, uint8_t scan);
slop_list_types_Clause sriqsat_minus_sorted(slop_arena* arena, slop_list_types_Clause xs, slop_list_types_Clause ys);
slop_list_sriqctx_Edge sriqsat_edges_from(slop_arena* arena, slop_list_sriqctx_Edge es, int64_t k);
sriqsat_Delta sriqsat_first_delta(slop_arena* arena, sriqctx_Structure st);
sriqsat_Delta sriqsat_copy_delta(slop_arena* arena, sriqsat_Delta dl);
int64_t sriqsat_into_v(slop_list_sriqref_Cand cs, uint32_t v);
int64_t sriqsat_sum_added(sriqsat_Delta dl);
sriqsat_Counts sriqsat_tally(sriqsat_Counts c, sriqref_Round r, sriqsat_Delta dl, int64_t tried);
sriqsat_Step sriqsat_with_units(slop_arena* arena, sriqctx_Triggers tr, sriqsat_Step sp);
sriqctx_Structure sriqsat_with_root_set(slop_arena* arena, sriqctx_Structure st, slop_list_types_Clause cs);
sriqsat_Delta sriqsat_with_root_news(slop_arena* arena, sriqsat_Delta dl, slop_list_types_Clause set, slop_list_types_Clause added, slop_list_types_Clause nobody);
slop_list_sriqctx_CtxSet sriqsat_with_first(slop_arena* arena, slop_list_sriqctx_CtxSet xs, slop_list_types_Clause cs);
uint8_t sriqsat_sorted_in(slop_list_types_Clause cs, types_Clause c);
sriqref_RefStatus sriqsat_sat_stop(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint8_t changed, sriqref_RefConfig cfg);
uint8_t sriqsat_holds_bot(slop_arena* arena, sriqctx_Structure st, int64_t v);
sriqsat_Run sriqsat_sat_once(slop_arena* next, slop_arena* scratch, sriqref_Env env, sriqhyper_HIdx hx, sriqsat_SatConfig cfg, sriqsat_Run run);
sriqctx_Structure sriqsat_read_view(slop_arena* arena, sriqctx_Structure st);
sriqctx_Structure sriqsat_sat_materialise(slop_arena* arena, sriqref_RefIn in, sriqctx_Structure st);
uint8_t sriqsat_hyper_ix_agrees(slop_arena* arena, sriqref_RefIn in, sriqsat_SatConfig cfg, sriqctx_Structure st);
uint8_t sriqsat_hyper_ix_one(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, sriqsat_Here h);
uint8_t sriqsat_same_cands(slop_arena* arena, slop_list_sriqref_Cand a, slop_list_sriqref_Cand b);
slop_list_types_Clause sriqsat_distinct_clauses(slop_arena* arena, slop_list_sriqref_Cand cs);
slop_list_types_Clause sriqsat_sorted_distinct(slop_arena* arena, slop_list_types_Clause raw, types_Clause c0);
types_Clause sriqsat_clause_of_l(slop_list_types_Clause cs, int64_t k, types_Clause fallback);
sriqsat_SatResult sriqsat_sat_run(slop_arena* arena, sriqref_RefIn in, sriqsat_SatConfig cfg);

typedef struct { slop_list_sriqsat_JoinSite raw; sriqsat_JoinSite s0; } sriqsat__lambda_1531_env_t;

static int64_t sriqsat__lambda_1531(sriqsat__lambda_1531_env_t* _env, int64_t a, int64_t b) { return types_lit_cmp(sriqsat_site_key(sriqsat_site_at(_env->raw, a, _env->s0)), sriqsat_site_key(sriqsat_site_at(_env->raw, b, _env->s0))); }

typedef struct { slop_list_sriqsat_Trig raw; sriqsat_Trig t0; } sriqsat__lambda_1540_env_t;

static int64_t sriqsat__lambda_1540(sriqsat__lambda_1540_env_t* _env, int64_t a, int64_t b) { return sriqsat_sg_cmp(sriqsat_trig_at(_env->raw, a, _env->t0).sg, sriqsat_trig_at(_env->raw, b, _env->t0).sg); }

typedef struct { slop_list_sriqctx_Edge es; sriqctx_Edge e0; } sriqsat__lambda_1543_env_t;

static int64_t sriqsat__lambda_1543(sriqsat__lambda_1543_env_t* _env, int64_t i, int64_t j) { return sriqsat_u32_cmp(sriqsat_edge_at(_env->es, i, _env->e0).to, sriqsat_edge_at(_env->es, j, _env->e0).to); }

typedef struct { slop_list_sriqctx_Edge es; sriqctx_Edge e0; } sriqsat__lambda_1544_env_t;

static int64_t sriqsat__lambda_1544(sriqsat__lambda_1544_env_t* _env, int64_t i, int64_t j) { return sriqsat_u32_cmp(sriqsat_edge_at(_env->es, i, _env->e0).from, sriqsat_edge_at(_env->es, j, _env->e0).from); }

typedef struct { slop_list_sriqref_Cand cands; sriqref_Cand none_such; } sriqsat__lambda_1548_env_t;

static int64_t sriqsat__lambda_1548(sriqsat__lambda_1548_env_t* _env, int64_t i, int64_t j) { return sriqref_cand_cmp(sriqref_cand_at(_env->cands, i, _env->none_such), sriqref_cand_at(_env->cands, j, _env->none_such)); }

typedef struct { slop_list_types_Clause raw; types_Clause c0; } sriqsat__lambda_1555_env_t;

static int64_t sriqsat__lambda_1555(sriqsat__lambda_1555_env_t* _env, int64_t a, int64_t b) { return sriqclauses_clause_cmp(sriqsat_clause_of_l(_env->raw, a, _env->c0), sriqsat_clause_of_l(_env->raw, b, _env->c0)); }

slop_list_types_Clause sriqsat_cs_at(slop_list_sriqctx_CtxSet xs, int64_t v, slop_list_types_Clause nobody) {
    __auto_type _mv_1525 = ({ __auto_type _lst = xs; size_t _idx = (size_t)v; slop_option_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1525.has_value) {
        __auto_type s = _mv_1525.value;
        return s.cs;
    } else if (!_mv_1525.has_value) {
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
                __auto_type _mv_1526 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1526.has_value) {
                    __auto_type c = _mv_1526.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1526.has_value) {
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

sriqsat_CIdx sriqsat_ctx_ix(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, int64_t v, int64_t perm) {
    {
        __auto_type all = sriqref_set_of(env, st, v);
        __auto_type fresh = (v >= dl.nctx);
        __auto_type news = sriqsat_permuted(arena, ((fresh) ? all : sriqsat_cs_at(dl.news, v, env.nobody)), perm);
        __auto_type olds = ((fresh) ? env.nobody : sriqsat_cs_at(dl.olds, v, env.nobody));
        __auto_type aps = sriqref_premises_of(arena, st.ord, all);
        __auto_type dps = sriqref_premises_of(arena, st.ord, news);
        __auto_type ops = sriqref_premises_of(arena, st.ord, olds);
        return ((sriqsat_CIdx){.aps = aps, .dps = dps, .ops = ops, .aix = sriqground_pidx_of(arena, aps), .dix = sriqground_pidx_of(arena, dps), .oix = sriqground_pidx_of(arena, ops)});
    }
}

slop_list_sriqsat_CIdx sriqsat_all_ixs(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, int64_t perm) {
    {
        __auto_type out = ((slop_list_sriqsat_CIdx){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        {
            __auto_type _coll = st.ctxs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqsat_ctx_ix(arena, env, st, dl, v, perm)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                v = (v + 1);
            }
        }
        return out;
    }
}

sriqsat_CIdx sriqsat_cix_at(slop_arena* arena, slop_list_sriqsat_CIdx ixs, int64_t v) {
    __auto_type _mv_1527 = ({ __auto_type _lst = ixs; size_t _idx = (size_t)v; slop_option_sriqsat_CIdx _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1527.has_value) {
        __auto_type x = _mv_1527.value;
        return x;
    } else if (!_mv_1527.has_value) {
        {
            __auto_type e = ((slop_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            return ((sriqsat_CIdx){.aps = e, .dps = e, .ops = e, .aix = sriqground_pidx_of(arena, e), .dix = sriqground_pidx_of(arena, e), .oix = sriqground_pidx_of(arena, e)});
        }
    }
    SLOP_UNREACHABLE();
}

sriqsat_Here sriqsat_here_of(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqground_Ground gd, sriqhyper_HIdx hx, slop_list_sriqsat_CIdx ixs, int64_t v, int64_t perm) {
    {
        __auto_type all = sriqref_set_of(env, st, v);
        __auto_type fresh = (v >= dl.nctx);
        __auto_type news = sriqsat_permuted(arena, ((fresh) ? all : sriqsat_cs_at(dl.news, v, env.nobody)), perm);
        __auto_type olds = ((fresh) ? env.nobody : sriqsat_cs_at(dl.olds, v, env.nobody));
        __auto_type x = sriqsat_cix_at(arena, ixs, v);
        return ((sriqsat_Here){.v = ((uint32_t)(v)), .root = sriqref_is_root(st, v), .fresh = fresh, .all = all, .news = news, .olds = olds, .aps = x.aps, .dps = x.dps, .ops = x.ops, .dix = x.dix, .aix = x.aix, .oix = x.oix, .hx = hx, .ixs = ixs, .gd = gd});
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

sriqhyper_HOut sriqsat_sat_hyper(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h) {
    {
        __auto_type hy = sriqhyper_hyper_indexed(arena, env, h.hx, sriqsat_hctx_of(h));
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = h.hx.bodiless;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type oc = _coll.data[_i];
                {
                    __auto_type _coll = sriqsat_hyper_bodiless(arena, st, dl, h, oc);
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
    __auto_type _mv_1528 = sriq_subterm_at(l, ((sriq_Pos){.arg = a, .inner = inner}));
    if (_mv_1528.has_value) {
        __auto_type t = _mv_1528.value;
        return types_aterm_eq(t, s);
    } else if (!_mv_1528.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

sriqhyper_HOut sriqsat_sat_table2(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h) {
    {
        __auto_type hy = sriqsat_sat_hyper(arena, env, st, dl, h);
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
        if (!(h.root)) {
            {
                __auto_type _coll = sriqsat_eq_ground(arena, st, h);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            {
                __auto_type _coll = sriqsat_join_ground(arena, h);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        {
            __auto_type _coll = sriqsat_eq_pairs(arena, st, h, h.dps, h.aps);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqsat_eq_pairs(arena, st, h, h.ops, h.dps);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqref_ref_ineq(arena, h.v, h.dps);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqref_ref_factor(arena, st.ord, h.v, h.dps);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqsat_sat_join(arena, h.v, h.dps, sriqsat_join_sites(arena, h.all));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqsat_sat_join(arena, h.v, h.ops, sriqsat_join_sites(arena, h.news));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((sriqhyper_HOut){.out = sriqref_out_of(out, hy.out.over), .tried = hy.tried});
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
                __auto_type _mv_1529 = sriqsat_site_lit(s);
                if (!_mv_1529.has_value) {
                } else if (_mv_1529.has_value) {
                    __auto_type l = _mv_1529.value;
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
        __auto_type _mv_1530 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_sriqsat_JoinSite _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1530.has_value) {
            return raw;
        } else if (_mv_1530.has_value) {
            __auto_type s0 = _mv_1530.value;
            return sriqsat_sites_sorted(arena, raw, s0);
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_sriqsat_JoinSite sriqsat_sites_sorted(slop_arena* arena, slop_list_sriqsat_JoinSite raw, sriqsat_JoinSite s0) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ sriqsat__lambda_1531_env_t* sriqsat__lambda_1531_env = (sriqsat__lambda_1531_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1531_env_t)); *sriqsat__lambda_1531_env = (sriqsat__lambda_1531_env_t){ .raw = raw, .s0 = s0 }; (slop_closure_t){ (void*)sriqsat__lambda_1531, (void*)sriqsat__lambda_1531_env }; }));
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
    __auto_type _mv_1532 = ({ __auto_type _lst = ss; size_t _idx = (size_t)k; slop_option_sriqsat_JoinSite _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1532.has_value) {
        __auto_type x = _mv_1532.value;
        return x;
    } else if (!_mv_1532.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

types_Lit sriqsat_site_key(sriqsat_JoinSite s) {
    __auto_type _mv_1533 = sriqsat_site_lit(s);
    if (_mv_1533.has_value) {
        __auto_type l = _mv_1533.value;
        return l;
    } else if (!_mv_1533.has_value) {
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
    __auto_type _mv_1534 = ({ __auto_type _lst = sites; size_t _idx = (size_t)0; slop_option_sriqsat_JoinSite _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1534.has_value) {
        return ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    } else if (_mv_1534.has_value) {
        __auto_type s0 = _mv_1534.value;
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
    __auto_type _mv_1535 = sriqsat_site_lit(s);
    if (_mv_1535.has_value) {
        __auto_type m = _mv_1535.value;
        return types_lit_eq(m, l);
    } else if (!_mv_1535.has_value) {
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
    __auto_type _mv_1536 = sriq_succ_sig(h.root, p.sel);
    if (!_mv_1536.has_value) {
        return 0;
    } else if (_mv_1536.has_value) {
        __auto_type sg = _mv_1536.value;
        return (((int64_t)((sriqindex_k_query(arena, env.tr, kn, sg).k2).len)) > 0);
    }
    SLOP_UNREACHABLE();
}

slop_list_sriq_Premise sriqsat_succ_premises(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h) {
    {
        __auto_type kn = sriqindex_k_index(arena, st.ord, env.tr, h.news);
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
        __auto_type kx = sriqindex_k_index(arena, st.ord, env.tr, h.all);
        __auto_type base = sriqsat_unheld(arena, h.gd, kx.ground);
        __auto_type bare = ((sriqindex_KIdx){.ground = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .fparts = kx.fparts});
        __auto_type ts = sriqsat_triggers_of(arena, h, ps);
        __auto_type out = ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1537 = ({ __auto_type _lst = ts; size_t _idx = (size_t)0; slop_option_sriqsat_Trig _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1537.has_value) {
            return out;
        } else if (_mv_1537.has_value) {
            __auto_type t0 = _mv_1537.value;
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
        {
            __auto_type _coll = ts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (sriqsat_sg_cmp(t.sg, last) != 0) {
                    sv = sriqsat_succ_view(arena, env, st, h, bare, base, t.sg);
                    last = t.sg;
                }
                {
                    __auto_type _coll = sriqsat_succ_on(arena, env, h, sv, t);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type a = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
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
                    __auto_type _mv_1538 = sriq_succ_sig(h.root, p.sel);
                    if (!_mv_1538.has_value) {
                    } else if (_mv_1538.has_value) {
                        __auto_type sg = _mv_1538.value;
                        ({ __auto_type _lst_p = &(raw); __auto_type _item = (((sriqsat_Trig){.p = p, .sg = sg})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        __auto_type _mv_1539 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_sriqsat_Trig _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1539.has_value) {
            return raw;
        } else if (_mv_1539.has_value) {
            __auto_type t0 = _mv_1539.value;
            return sriqsat_trigs_sorted(arena, raw, t0);
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_sriqsat_Trig sriqsat_trigs_sorted(slop_arena* arena, slop_list_sriqsat_Trig raw, sriqsat_Trig t0) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ sriqsat__lambda_1540_env_t* sriqsat__lambda_1540_env = (sriqsat__lambda_1540_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1540_env_t)); *sriqsat__lambda_1540_env = (sriqsat__lambda_1540_env_t){ .raw = raw, .t0 = t0 }; (slop_closure_t){ (void*)sriqsat__lambda_1540, (void*)sriqsat__lambda_1540_env }; }));
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
    __auto_type _mv_1541 = ({ __auto_type _lst = ts; size_t _idx = (size_t)k; slop_option_sriqsat_Trig _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1541.has_value) {
        __auto_type t = _mv_1541.value;
        return t;
    } else if (!_mv_1541.has_value) {
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
        return ((sriqsat_SuccView){.ks = ((sriq_KSets){.k1 = ks.k1, .k2 = k2}), .covered = sriqsat_covered_view(arena, env, st, h.v, sg.f, k2)});
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
        return sriqsat_rpred_from(arena, env, st, h, sriqref_set_of(env, st, 0), h.aps, 0);
    } else {
        {
            __auto_type a = sriqsat_rpred_from(arena, env, st, h, sriqsat_cs_at(dl.news, 0, env.nobody), h.aps, 0);
            __auto_type b = (((((int64_t)((h.news).len)) > 0)) ? sriqsat_rpred_from(arena, env, st, h, sriqsat_cs_at(dl.olds, 0, env.nobody), h.aps, 1) : sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0));
            return sriqref_out_of(sriqref_append_cands(arena, a.cands, b.cands), (a.over || b.over));
        }
    }
}

sriqref_Out sriqsat_rpred_from(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, slop_list_types_Clause cs, slop_list_sriq_Premise aps, uint8_t anchored) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(sriqground_ground_clause(c))) {
                    {
                        __auto_type job = sriqref_rpred_job(arena, env, st, h.v, c);
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
        }
        return sriqref_out_of(out, over);
    }
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

sriqsat_CRound sriqsat_sat_ctx(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, slop_list_sriqsat_CIdx ixs, sriqctx_Structure st, sriqsat_Delta dl, sriqground_Ground gd, sriqsat_Adj a, int64_t v, int64_t perm) {
    {
        __auto_type lst = sriqsat_local(st, a, arena);
        if ((v >= dl.nctx) && sriqref_is_root(st, v)) {
            return ((sriqsat_CRound){.r = sriqref_ctx_round(arena, env, lst, ((uint32_t)(v))), .tried = 0});
        } else {
            return sriqsat_sat_old(arena, env, lst, dl, a.ins, sriqsat_here_of(arena, env, lst, dl, gd, hx, ixs, v, perm));
        }
    }
}

sriqsat_CRound sriqsat_sat_old(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, slop_list_sriqctx_Edge ins, sriqsat_Here h) {
    {
        __auto_type t2 = sriqsat_sat_table2(arena, env, st, dl, h);
        __auto_type nom = sriqsat_sat_nom(arena, env, st, dl, h);
        __auto_type pr = ((h.root) ? sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0) : sriqsat_sat_pred(arena, env, st, dl, h, ins));
        __auto_type rp = ((h.root) ? sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0) : sriqsat_sat_rpred(arena, env, st, dl, h));
        __auto_type cands = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = t2.out.cands;
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
        return ((sriqsat_CRound){.r = sriqref_round_of(cands, sriqsat_sat_succ(arena, env, st, h, sriqsat_succ_premises(arena, env, st, h)), ((h.root) ? ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) : sriqref_ref_rsucc(arena, env, st, h.v, h.dps)), nom.noms, ((t2.out.over) || (pr.over) || (rp.over))), .tried = t2.tried});
    }
}

sriqctx_Edge sriqsat_edge_at(slop_list_sriqctx_Edge es, int64_t k, sriqctx_Edge fallback) {
    __auto_type _mv_1542 = ({ __auto_type _lst = es; size_t _idx = (size_t)k; slop_option_sriqctx_Edge _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1542.has_value) {
        __auto_type e = _mv_1542.value;
        return e;
    } else if (!_mv_1542.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_list_sriqsat_Adj sriqsat_adjacency(slop_arena* arena, sriqctx_Structure st) {
    {
        __auto_type es = st.edges;
        __auto_type n = ((int64_t)(((int64_t)((st.ctxs).len))));
        __auto_type e0 = ((sriqctx_Edge){.from = ((uint32_t)(0)), .to = ((uint32_t)(0)), .lk = sriqctx_EdgeLabel_el_fn, .label = ((uint32_t)(0))});
        __auto_type by_to = canon_sort_range(arena, ((int64_t)(((int64_t)((st.edges).len)))), ({ sriqsat__lambda_1543_env_t* sriqsat__lambda_1543_env = (sriqsat__lambda_1543_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1543_env_t)); *sriqsat__lambda_1543_env = (sriqsat__lambda_1543_env_t){ .es = es, .e0 = e0 }; (slop_closure_t){ (void*)sriqsat__lambda_1543, (void*)sriqsat__lambda_1543_env }; }));
        __auto_type by_from = canon_sort_range(arena, ((int64_t)(((int64_t)((st.edges).len)))), ({ sriqsat__lambda_1544_env_t* sriqsat__lambda_1544_env = (sriqsat__lambda_1544_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1544_env_t)); *sriqsat__lambda_1544_env = (sriqsat__lambda_1544_env_t){ .es = es, .e0 = e0 }; (slop_closure_t){ (void*)sriqsat__lambda_1544, (void*)sriqsat__lambda_1544_env }; }));
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
    __auto_type _mv_1545 = ({ __auto_type _lst = bs; size_t _idx = (size_t)v; slop_option_sriqsat_Bucket _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1545.has_value) {
        __auto_type b = _mv_1545.value;
        return b.es;
    } else if (!_mv_1545.has_value) {
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
    __auto_type _mv_1546 = ({ __auto_type _lst = idx; size_t _idx = (size_t)k; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1546.has_value) {
        __auto_type i = _mv_1546.value;
        return i;
    } else if (!_mv_1546.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

sriqsat_CRound sriqsat_sat_round(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, sriqctx_Structure st, sriqsat_Delta dl, sriqground_Ground gd, int64_t perm) {
    {
        __auto_type adj = sriqsat_adjacency(arena, st);
        __auto_type ixs = sriqsat_all_ixs(arena, env, st, dl, perm);
        __auto_type cands = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type succs = ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type rsuccs = ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type noms = ((slop_list_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        int64_t tried = 0;
        {
            __auto_type _coll = sriqsat_ctx_order(arena, ((int64_t)(((int64_t)((st.ctxs).len)))), perm);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type v = _coll.data[_i];
                __auto_type _mv_1547 = ({ __auto_type _lst = adj; size_t _idx = (size_t)v; slop_option_sriqsat_Adj _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (!_mv_1547.has_value) {
                } else if (_mv_1547.has_value) {
                    __auto_type a = _mv_1547.value;
                    {
                        __auto_type cr = sriqsat_sat_ctx(arena, env, hx, ixs, st, dl, gd, a, v, perm);
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
                    }
                }
            }
        }
        return ((sriqsat_CRound){.r = sriqref_round_of(cands, succs, rsuccs, noms, over), .tried = tried});
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

sriqsat_Step sriqsat_sat_apply(slop_arena* arena, sriqctx_Structure st, sriqground_Ground gd, sriqref_Round r, uint8_t scan) {
    {
        __auto_type n0 = sriqref_consts_of(st);
        __auto_type c0 = ((int64_t)(((int64_t)((st.ctxs).len))));
        __auto_type e0 = ((int64_t)(((int64_t)((st.edges).len))));
        __auto_type s1 = ((sriqctx_Structure){.ctxs = st.ctxs, .sets = st.sets, .edges = st.edges, .ord = sriqref_add_consts(arena, st.ord, r.noms)});
        __auto_type s2 = sriqref_add_contexts(arena, s1, r.succs);
        __auto_type s3 = sriqref_add_edges(arena, s2, r.succs, r.rsuccs);
        __auto_type cands = sriqref_append_cands(arena, sriqref_append_cands(arena, r.cands, sriqref_action_cands(arena, s3, r.succs, r.rsuccs)), sriqsat_new_cores(arena, s3, c0));
        return sriqsat_commit_all(arena, s3, sriqsat_outside_view(arena, s3, gd, cands), c0, e0, n0, scan);
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

sriqsat_Step sriqsat_commit_all(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_Cand cands, int64_t c0, int64_t e0, int64_t n0, uint8_t scan) {
    {
        __auto_type none_such = ((sriqref_Cand){.ctx = ((uint32_t)(0)), .c = ((types_Clause){.body = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .head = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })})});
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((cands).len)))), ({ sriqsat__lambda_1548_env_t* sriqsat__lambda_1548_env = (sriqsat__lambda_1548_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1548_env_t)); *sriqsat__lambda_1548_env = (sriqsat__lambda_1548_env_t){ .cands = cands, .none_such = none_such }; (slop_closure_t){ (void*)sriqsat__lambda_1548, (void*)sriqsat__lambda_1548_env }; }));
        __auto_type sets = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type news = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type olds = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
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
        return ((sriqsat_Step){.st = ((sriqctx_Structure){.ctxs = st.ctxs, .sets = sets, .edges = st.edges, .ord = st.ord}), .dl = ((sriqsat_Delta){.news = news, .olds = olds, .edges = sriqsat_edges_from(arena, st.edges, e0), .nctx = c0, .ncst = n0}), .changed = ((grew) || ((((int64_t)(((int64_t)((st.ctxs).len)))) != c0)) || ((((int64_t)(((int64_t)((st.edges).len)))) != e0)) || ((sriqref_consts_of(st) != n0)))});
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
                __auto_type _mv_1549 = ({ __auto_type _lst = ys; size_t _idx = (size_t)j; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1549.has_value) {
                    __auto_type y = _mv_1549.value;
                    if (sriqclauses_clause_cmp(x, y) == 0) {
                        j = (j + 1);
                    } else {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                } else if (!_mv_1549.has_value) {
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

sriqsat_Counts sriqsat_tally(sriqsat_Counts c, sriqref_Round r, sriqsat_Delta dl, int64_t tried) {
    return ((sriqsat_Counts){.cands = (c.cands + ((int64_t)(((int64_t)((r.cands).len))))), .rcands = (c.rcands + sriqsat_into_v(r.cands, ((uint32_t)(0)))), .succs = (c.succs + ((int64_t)(((int64_t)((r.succs).len))))), .rsuccs = (c.rsuccs + ((int64_t)(((int64_t)((r.rsuccs).len))))), .noms = (c.noms + ((int64_t)(((int64_t)((r.noms).len))))), .added = (c.added + sriqsat_sum_added(dl)), .hyper = (c.hyper + tried)});
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
                    return ((sriqsat_Step){.st = sriqsat_with_root_set(arena, st, cm.set), .dl = sriqsat_with_root_news(arena, dl, cm.set, cm.added, nobody), .changed = 1});
                }
            }
        }
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
                __auto_type _mv_1550 = ({ __auto_type _lst = cs; size_t _idx = (size_t)mid; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1550.has_value) {
                    __auto_type x = _mv_1550.value;
                    if (sriqclauses_clause_cmp(x, c) < 0) {
                        lo = (mid + 1);
                    } else {
                        hi = mid;
                    }
                } else if (!_mv_1550.has_value) {
                    hi = mid;
                }
            }
        }
        __auto_type _mv_1551 = ({ __auto_type _lst = cs; size_t _idx = (size_t)lo; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1551.has_value) {
            __auto_type x = _mv_1551.value;
            return (sriqclauses_clause_cmp(x, c) == 0);
        } else if (!_mv_1551.has_value) {
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
    __auto_type _mv_1552 = ({ __auto_type _lst = st.sets; size_t _idx = (size_t)v; slop_option_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1552.has_value) {
        __auto_type s = _mv_1552.value;
        return sriqsubsume_in_hat(sriqclauses_make_clause(arena, ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })), s.cs);
    } else if (!_mv_1552.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

sriqsat_Run sriqsat_sat_once(slop_arena* next, slop_arena* scratch, sriqref_Env env, sriqhyper_HIdx hx, sriqsat_SatConfig cfg, sriqsat_Run run) {
    {
        __auto_type gd = sriqground_ground_of(scratch, env.tr, run.st, sriqsat_cs_at(run.dl.news, 0, env.nobody));
        __auto_type sr = sriqsat_sat_round(scratch, env, hx, run.st, run.dl, gd, cfg.perm);
        __auto_type r = sr.r;
        if (r.over) {
            return ((sriqsat_Run){.st = run.st, .dl = run.dl, .status = sriqref_RefStatus_rs_product, .rounds = run.rounds, .going = 0, .counts = run.counts});
        } else {
            {
                __auto_type sp = sriqsat_with_units(scratch, env.tr, sriqsat_sat_apply(scratch, run.st, gd, r, cfg.scan));
                __auto_type st = sriqref_copy_structure(next, sp.st);
                __auto_type status = sriqsat_sat_stop(scratch, env, st, sp.changed, cfg.base);
                return ((sriqsat_Run){.st = st, .dl = sriqsat_copy_delta(next, sp.dl), .status = status, .rounds = (run.rounds + 1), .going = (status == sriqref_RefStatus_rs_fuel), .counts = sriqsat_tally(run.counts, r, sp.dl, sr.tried)});
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

uint8_t sriqsat_hyper_ix_agrees(slop_arena* arena, sriqref_RefIn in, sriqsat_SatConfig cfg, sriqctx_Structure st) {
    {
        __auto_type base = cfg.base;
        __auto_type tr = sriqctx_build_triggers(arena, in.onto, in.nclass, in.nrole, in.nfn);
        __auto_type env = sriqref_env_of(arena, in, base, tr, sriqref_ref_lambda(tr, base.strat, in.nquery));
        __auto_type hx = sriqhyper_h_index(arena, in.onto);
        __auto_type gd = sriqground_ground_of(arena, tr, st, env.nobody);
        __auto_type dl = sriqsat_first_delta(arena, st);
        __auto_type ixs = sriqsat_all_ixs(arena, env, st, dl, 0);
        uint8_t ok = 1;
        int64_t v = 0;
        {
            __auto_type _coll = st.ctxs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(sriqsat_hyper_ix_one(arena, env, hx, sriqsat_here_of(arena, env, st, dl, gd, hx, ixs, v, 0)))) {
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
        __auto_type mine = sriqhyper_hyper_indexed(arena, env, hx, sriqsat_hctx_of(h));
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
                __auto_type _mv_1553 = ({ __auto_type _lst = y; size_t _idx = (size_t)i; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1553.has_value) {
                    __auto_type d = _mv_1553.value;
                    if (sriqclauses_clause_cmp(c, d) != 0) {
                        ok = 0;
                    }
                } else if (!_mv_1553.has_value) {
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
        __auto_type _mv_1554 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1554.has_value) {
            return raw;
        } else if (_mv_1554.has_value) {
            __auto_type c0 = _mv_1554.value;
            return sriqsat_sorted_distinct(arena, raw, c0);
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_types_Clause sriqsat_sorted_distinct(slop_arena* arena, slop_list_types_Clause raw, types_Clause c0) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ sriqsat__lambda_1555_env_t* sriqsat__lambda_1555_env = (sriqsat__lambda_1555_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1555_env_t)); *sriqsat__lambda_1555_env = (sriqsat__lambda_1555_env_t){ .raw = raw, .c0 = c0 }; (slop_closure_t){ (void*)sriqsat__lambda_1555, (void*)sriqsat__lambda_1555_env }; }));
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type c = sriqsat_clause_of_l(raw, k, c0);
                    __auto_type _mv_1556 = ({ __auto_type _lst = out; size_t _idx = (size_t)(((int64_t)(((int64_t)((out).len)))) - 1); slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_1556.has_value) {
                        __auto_type last = _mv_1556.value;
                        if (sriqclauses_clause_cmp(last, c) != 0) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    } else if (!_mv_1556.has_value) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

types_Clause sriqsat_clause_of_l(slop_list_types_Clause cs, int64_t k, types_Clause fallback) {
    __auto_type _mv_1557 = ({ __auto_type _lst = cs; size_t _idx = (size_t)k; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1557.has_value) {
        __auto_type c = _mv_1557.value;
        return c;
    } else if (!_mv_1557.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

sriqsat_SatResult sriqsat_sat_run(slop_arena* arena, sriqref_RefIn in, sriqsat_SatConfig cfg) {
    {
        __auto_type base = cfg.base;
        __auto_type tr = sriqctx_build_triggers(arena, in.onto, in.nclass, in.nrole, in.nfn);
        __auto_type lam = (((base.lam >= 0)) ? base.lam : sriqref_ref_lambda(tr, base.strat, in.nquery));
        __auto_type env = sriqref_env_of(arena, in, base, tr, lam);
        __auto_type hx = sriqhyper_h_index(arena, in.onto);
        __auto_type st0 = sriqctx_init_structure(arena, in.nquery, in.nconst);
        __auto_type held = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        __auto_type run = ((sriqsat_Run){.st = st0, .dl = sriqsat_first_delta(arena, st0), .status = sriqref_RefStatus_rs_fuel, .rounds = 0, .going = 1, .counts = ((sriqsat_Counts){.cands = 0, .rcands = 0, .succs = 0, .rsuccs = 0, .noms = 0, .added = 0, .hyper = 0})});
        while (run.going && (run.rounds < base.fuel)) {
            {
                __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                __auto_type next = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                __auto_type nr = sriqsat_sat_once(next, scratch, env, hx, cfg, run);
                if (nr.status == sriqref_RefStatus_rs_product) {
                    ({ slop_arena_free(next); free(next); });
                } else {
                    ({ slop_arena_free(held); free(held); });
                    held = next;
                }
                ({ slop_arena_free(scratch); free(scratch); });
                run = nr;
            }
        }
        {
            __auto_type done = sriqref_copy_structure(arena, sriqsat_read_view(arena, run.st));
            ({ slop_arena_free(held); free(held); });
            return ((sriqsat_SatResult){.res = ((sriqref_RefResult){.status = run.status, .rounds = run.rounds, .st = done}), .counts = run.counts});
        }
    }
}

