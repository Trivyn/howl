#include "../runtime/slop_runtime.h"
#include "slop_sriqsat.h"

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

typedef struct { slop_list_sriqctx_Edge es; sriqctx_Edge e0; } sriqsat__lambda_1438_env_t;

static int64_t sriqsat__lambda_1438(sriqsat__lambda_1438_env_t* _env, int64_t i, int64_t j) { return sriqsat_u32_cmp(sriqsat_edge_at(_env->es, i, _env->e0).to, sriqsat_edge_at(_env->es, j, _env->e0).to); }

typedef struct { slop_list_sriqctx_Edge es; sriqctx_Edge e0; } sriqsat__lambda_1439_env_t;

static int64_t sriqsat__lambda_1439(sriqsat__lambda_1439_env_t* _env, int64_t i, int64_t j) { return sriqsat_u32_cmp(sriqsat_edge_at(_env->es, i, _env->e0).from, sriqsat_edge_at(_env->es, j, _env->e0).from); }

typedef struct { slop_list_sriqref_Cand cands; sriqref_Cand none_such; } sriqsat__lambda_1443_env_t;

static int64_t sriqsat__lambda_1443(sriqsat__lambda_1443_env_t* _env, int64_t i, int64_t j) { return sriqref_cand_cmp(sriqref_cand_at(_env->cands, i, _env->none_such), sriqref_cand_at(_env->cands, j, _env->none_such)); }

slop_list_types_Clause sriqsat_cs_at(slop_list_sriqctx_CtxSet xs, int64_t v, slop_list_types_Clause nobody) {
    __auto_type _mv_1433 = ({ __auto_type _lst = xs; size_t _idx = (size_t)v; slop_option_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1433.has_value) {
        __auto_type s = _mv_1433.value;
        return s.cs;
    } else if (!_mv_1433.has_value) {
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
                __auto_type _mv_1434 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1434.has_value) {
                    __auto_type c = _mv_1434.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1434.has_value) {
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

sriqsat_Here sriqsat_here_of(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, int64_t v, int64_t perm) {
    {
        __auto_type all = sriqref_set_of(env, st, v);
        __auto_type news = sriqsat_permuted(arena, sriqsat_cs_at(dl.news, v, env.nobody), perm);
        __auto_type olds = sriqsat_cs_at(dl.olds, v, env.nobody);
        return ((sriqsat_Here){.v = ((uint32_t)(v)), .root = sriqref_is_root(st, v), .all = all, .news = news, .olds = olds, .aps = sriqref_premises_of(arena, st.ord, all), .dps = sriqref_premises_of(arena, st.ord, news), .ops = sriqref_premises_of(arena, st.ord, olds)});
    }
}

slop_list_sriq_Premise sriqsat_pick(int64_t j, int64_t i, slop_list_sriq_Premise dps, slop_list_sriq_Premise ops, slop_list_sriq_Premise aps) {
    if (j < i) {
        return ops;
    } else if (j == i) {
        return dps;
    } else {
        return aps;
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

sriqref_Out sriqsat_hyper_anchor(slop_arena* arena, sriqref_Env env, sriqsat_Here h, sriq_HState start, types_Clause oc, int64_t i) {
    {
        __auto_type cs = ((slop_list_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        {
            __auto_type _coll = oc.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(cs); __auto_type _item = (sriqref_slot_cands(arena, h.root, a, sriqsat_pick(j, i, h.dps, h.ops, h.aps))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                j = (j + 1);
            }
        }
        {
            __auto_type n = sriqref_product(cs, env.prod);
            if (n > env.prod) {
                return sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 1);
            } else if (n == 0) {
                return sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0);
            } else {
                __auto_type _mv_1435 = ({ __auto_type _lst = h.aps; size_t _idx = (size_t)0; slop_option_sriq_Premise _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (!_mv_1435.has_value) {
                    return sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0);
                } else if (_mv_1435.has_value) {
                    __auto_type p0 = _mv_1435.value;
                    return sriqref_out_of(sriqref_hyper_choices(arena, h.v, start, oc, cs, n, p0), 0);
                }
                SLOP_UNREACHABLE();
            }
        }
    }
}

sriqref_Out sriqsat_hyper_clause(slop_arena* arena, sriqref_Env env, sriqsat_Here h, types_Clause oc) {
    {
        __auto_type start = sriq_hyper_start(arena, types_at_x(), !(h.root));
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        int64_t i = 0;
        while (i < ((int64_t)(((int64_t)((oc.body).len))))) {
            {
                __auto_type o = sriqsat_hyper_anchor(arena, env, h, start, oc, i);
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

sriqref_Out sriqsat_sat_hyper(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        {
            __auto_type _coll = env.onto;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type oc = _coll.data[_i];
                if (((int64_t)((oc.body).len)) == 0) {
                    if (h.root) {
                        {
                            __auto_type _coll = sriqsat_hyper_new_consts(arena, st, dl, h.v, oc);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type c = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                } else {
                    {
                        __auto_type o = sriqsat_hyper_clause(arena, env, h, oc);
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
                    }
                }
            }
        }
        return sriqref_out_of(out, over);
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
                                    __auto_type _coll = sriqref_eq_positions(arena, st.ord, h.v, h.root, p1, ((uint32_t)(1)), p2);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type c = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                {
                                    __auto_type _coll = sriqref_eq_positions(arena, st.ord, h.v, h.root, p1, ((uint32_t)(2)), p2);
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

sriqref_Out sriqsat_sat_table2(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h) {
    {
        __auto_type hy = sriqsat_sat_hyper(arena, env, st, dl, h);
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = hy.cands;
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
            __auto_type _coll = sriqref_ref_join(arena, h.v, h.dps, h.all);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqref_ref_join(arena, h.v, h.ops, h.news);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return sriqref_out_of(out, hy.over);
    }
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
    if (sriqsat_consts_new(st, dl)) {
        return sriqref_ref_nom(arena, env, st.ord, h.v, h.aps);
    } else {
        {
            __auto_type cands = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            __auto_type noms = ((slop_list_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = env.onto;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type oc = _coll.data[_i];
                    {
                        __auto_type d = sriqref_dl4_of(oc);
                        if (d.ok) {
                            {
                                __auto_type _coll = sriqsat_two_rounds(arena, sriqsat_nom_pairs(arena, env, st, h, d, h.dps, h.aps), sriqsat_nom_pairs(arena, env, st, h, d, h.ops, h.dps));
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
            }
            return sriqref_round_of(cands, ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), noms, 0);
        }
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

uint8_t sriqsat_k2_touched(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h, sriq_Premise p) {
    __auto_type _mv_1436 = sriq_succ_sig(h.root, p.sel);
    if (!_mv_1436.has_value) {
        return 0;
    } else if (_mv_1436.has_value) {
        __auto_type sg = _mv_1436.value;
        return (((int64_t)((sriq_k_sets(arena, st.ord, env.tr, sg, h.news).k2).len)) > 0);
    }
    SLOP_UNREACHABLE();
}

slop_list_sriq_Premise sriqsat_succ_premises(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Here h) {
    {
        __auto_type out = ((slop_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = h.dps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        if (((int64_t)((h.news).len)) > 0) {
            {
                __auto_type _coll = h.ops;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type p = _coll.data[_i];
                    if (p.maxed && sriqsat_k2_touched(arena, env, st, h, p)) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

sriqref_Out sriqsat_pred_anchored(slop_arena* arena, sriqref_Env env, sriqref_PJob job, slop_list_sriq_Premise dws, slop_list_sriq_Premise ows, slop_list_sriq_Premise aws) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        int64_t i = 0;
        while (i < ((int64_t)(((int64_t)((job.slots).len))))) {
            {
                __auto_type o = sriqsat_pred_anchor(arena, env, job, dws, ows, aws, i);
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

sriqref_Out sriqsat_pred_anchor(slop_arena* arena, sriqref_Env env, sriqref_PJob job, slop_list_sriq_Premise dws, slop_list_sriq_Premise ows, slop_list_sriq_Premise aws, int64_t i) {
    {
        __auto_type cs = ((slop_list_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        {
            __auto_type _coll = job.slots;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type slot = _coll.data[_i];
                ({ __auto_type _lst_p = &(cs); __auto_type _item = (sriqref_pslot_cands(arena, job.s, slot, sriqsat_pick(j, i, dws, ows, aws))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                j = (j + 1);
            }
        }
        {
            __auto_type n = sriqref_product(cs, env.prod);
            int64_t t = 0;
            if (n > env.prod) {
                return sriqref_out_of(out, 1);
            } else {
                while (t < n) {
                    {
                        __auto_type _coll = sriqref_pred_one(arena, env, job, cs, t, aws);
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
}

sriqref_Out sriqsat_pred_side(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Here h, sriqctx_Edge e) {
    {
        __auto_type w = ((int64_t)(e.from));
        __auto_type toroot = sriqref_is_root(st, ((int64_t)(e.from)));
        __auto_type aws = sriqref_premises_of(arena, st.ord, sriqref_set_of(env, st, w));
        __auto_type dws = sriqref_premises_of(arena, st.ord, sriqsat_cs_at(dl.news, w, env.nobody));
        __auto_type ows = sriqref_premises_of(arena, st.ord, sriqsat_cs_at(dl.olds, w, env.nobody));
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
                                __auto_type o = sriqsat_pred_anchored(arena, env, job, dws, ows, aws);
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
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqref_pred_edge(arena, env, st, h.v, e, h.all)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqref_pred_edge(arena, env, st, h.v, e, h.news)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    if (sriqsat_rpred_edge_new(dl, h.v)) {
        return sriqref_ref_rpred(arena, env, st, h.v, h.aps);
    } else {
        {
            __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            uint8_t over = 0;
            {
                __auto_type _coll = sriqsat_cs_at(dl.news, 0, env.nobody);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    {
                        __auto_type o = sriqref_pred_run(arena, env, sriqref_rpred_job(arena, env, st, h.v, c), h.aps);
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
            if (((int64_t)((h.news).len)) > 0) {
                {
                    __auto_type _coll = sriqsat_cs_at(dl.olds, 0, env.nobody);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        {
                            __auto_type o = sriqsat_pred_anchored(arena, env, sriqref_rpred_job(arena, env, st, h.v, c), h.dps, h.ops, h.aps);
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

sriqref_Round sriqsat_sat_ctx(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, sriqsat_Adj a, int64_t v, int64_t perm) {
    {
        __auto_type lst = sriqsat_local(st, a, arena);
        if (v >= dl.nctx) {
            return sriqref_ctx_round(arena, env, lst, ((uint32_t)(v)));
        } else {
            return sriqsat_sat_old(arena, env, lst, dl, a.ins, sriqsat_here_of(arena, env, lst, dl, v, perm));
        }
    }
}

sriqref_Round sriqsat_sat_old(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, slop_list_sriqctx_Edge ins, sriqsat_Here h) {
    {
        __auto_type t2 = sriqsat_sat_table2(arena, env, st, dl, h);
        __auto_type nom = sriqsat_sat_nom(arena, env, st, dl, h);
        __auto_type pr = ((h.root) ? sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0) : sriqsat_sat_pred(arena, env, st, dl, h, ins));
        __auto_type rp = ((h.root) ? sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0) : sriqsat_sat_rpred(arena, env, st, dl, h));
        __auto_type cands = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = t2.cands;
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
        return sriqref_round_of(cands, sriqref_ref_succ(arena, env, st, h.v, h.root, h.all, sriqsat_succ_premises(arena, env, st, h)), ((h.root) ? ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) : sriqref_ref_rsucc(arena, env, st, h.v, h.dps)), nom.noms, ((t2.over) || (pr.over) || (rp.over)));
    }
}

sriqctx_Edge sriqsat_edge_at(slop_list_sriqctx_Edge es, int64_t k, sriqctx_Edge fallback) {
    __auto_type _mv_1437 = ({ __auto_type _lst = es; size_t _idx = (size_t)k; slop_option_sriqctx_Edge _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1437.has_value) {
        __auto_type e = _mv_1437.value;
        return e;
    } else if (!_mv_1437.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_list_sriqsat_Adj sriqsat_adjacency(slop_arena* arena, sriqctx_Structure st) {
    {
        __auto_type es = st.edges;
        __auto_type n = ((int64_t)(((int64_t)((st.ctxs).len))));
        __auto_type e0 = ((sriqctx_Edge){.from = ((uint32_t)(0)), .to = ((uint32_t)(0)), .lk = sriqctx_EdgeLabel_el_fn, .label = ((uint32_t)(0))});
        __auto_type by_to = canon_sort_range(arena, ((int64_t)(((int64_t)((st.edges).len)))), ({ sriqsat__lambda_1438_env_t* sriqsat__lambda_1438_env = (sriqsat__lambda_1438_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1438_env_t)); *sriqsat__lambda_1438_env = (sriqsat__lambda_1438_env_t){ .es = es, .e0 = e0 }; (slop_closure_t){ (void*)sriqsat__lambda_1438, (void*)sriqsat__lambda_1438_env }; }));
        __auto_type by_from = canon_sort_range(arena, ((int64_t)(((int64_t)((st.edges).len)))), ({ sriqsat__lambda_1439_env_t* sriqsat__lambda_1439_env = (sriqsat__lambda_1439_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1439_env_t)); *sriqsat__lambda_1439_env = (sriqsat__lambda_1439_env_t){ .es = es, .e0 = e0 }; (slop_closure_t){ (void*)sriqsat__lambda_1439, (void*)sriqsat__lambda_1439_env }; }));
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
    __auto_type _mv_1440 = ({ __auto_type _lst = bs; size_t _idx = (size_t)v; slop_option_sriqsat_Bucket _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1440.has_value) {
        __auto_type b = _mv_1440.value;
        return b.es;
    } else if (!_mv_1440.has_value) {
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
    __auto_type _mv_1441 = ({ __auto_type _lst = idx; size_t _idx = (size_t)k; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1441.has_value) {
        __auto_type i = _mv_1441.value;
        return i;
    } else if (!_mv_1441.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

sriqref_Round sriqsat_sat_round(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqsat_Delta dl, int64_t perm) {
    {
        __auto_type adj = sriqsat_adjacency(arena, st);
        __auto_type cands = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type succs = ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type rsuccs = ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type noms = ((slop_list_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        {
            __auto_type _coll = sriqsat_ctx_order(arena, ((int64_t)(((int64_t)((st.ctxs).len)))), perm);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type v = _coll.data[_i];
                __auto_type _mv_1442 = ({ __auto_type _lst = adj; size_t _idx = (size_t)v; slop_option_sriqsat_Adj _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (!_mv_1442.has_value) {
                } else if (_mv_1442.has_value) {
                    __auto_type a = _mv_1442.value;
                    {
                        __auto_type r = sriqsat_sat_ctx(arena, env, st, dl, a, v, perm);
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
        return sriqref_round_of(cands, succs, rsuccs, noms, over);
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

sriqsat_Step sriqsat_sat_apply(slop_arena* arena, sriqctx_Structure st, sriqref_Round r) {
    {
        __auto_type n0 = sriqref_consts_of(st);
        __auto_type c0 = ((int64_t)(((int64_t)((st.ctxs).len))));
        __auto_type e0 = ((int64_t)(((int64_t)((st.edges).len))));
        __auto_type s1 = ((sriqctx_Structure){.ctxs = st.ctxs, .sets = st.sets, .edges = st.edges, .ord = sriqref_add_consts(arena, st.ord, r.noms)});
        __auto_type s2 = sriqref_add_contexts(arena, s1, r.succs);
        __auto_type s3 = sriqref_add_edges(arena, s2, r.succs, r.rsuccs);
        __auto_type cands = sriqref_append_cands(arena, sriqref_append_cands(arena, r.cands, sriqref_action_cands(arena, s3, r.succs, r.rsuccs)), sriqsat_new_cores(arena, s3, c0));
        return sriqsat_commit_all(arena, s3, cands, c0, e0, n0);
    }
}

sriqsat_Step sriqsat_commit_all(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_Cand cands, int64_t c0, int64_t e0, int64_t n0) {
    {
        __auto_type none_such = ((sriqref_Cand){.ctx = ((uint32_t)(0)), .c = ((types_Clause){.body = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .head = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })})});
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((cands).len)))), ({ sriqsat__lambda_1443_env_t* sriqsat__lambda_1443_env = (sriqsat__lambda_1443_env_t*)slop_arena_alloc(arena, sizeof(sriqsat__lambda_1443_env_t)); *sriqsat__lambda_1443_env = (sriqsat__lambda_1443_env_t){ .cands = cands, .none_such = none_such }; (slop_closure_t){ (void*)sriqsat__lambda_1443, (void*)sriqsat__lambda_1443_env }; }));
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
                        __auto_type cm = sriqsat_commit_one(arena, s.cs, mine);
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

sriqsubsume_Committed sriqsat_commit_one(slop_arena* arena, slop_list_types_Clause ws, slop_list_types_Clause cs) {
    if (((int64_t)((cs).len)) == 0) {
        return ((sriqsubsume_Committed){.set = ws, .added = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
    } else {
        return sriqsubsume_commit_min(arena, ws, cs);
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
                __auto_type _mv_1444 = ({ __auto_type _lst = ys; size_t _idx = (size_t)j; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1444.has_value) {
                    __auto_type y = _mv_1444.value;
                    if (sriqclauses_clause_cmp(x, y) == 0) {
                        j = (j + 1);
                    } else {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                } else if (!_mv_1444.has_value) {
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

sriqsat_Counts sriqsat_tally(sriqsat_Counts c, sriqref_Round r, sriqsat_Delta dl) {
    return ((sriqsat_Counts){.cands = (c.cands + ((int64_t)(((int64_t)((r.cands).len))))), .rcands = (c.rcands + sriqsat_into_v(r.cands, ((uint32_t)(0)))), .succs = (c.succs + ((int64_t)(((int64_t)((r.succs).len))))), .rsuccs = (c.rsuccs + ((int64_t)(((int64_t)((r.rsuccs).len))))), .noms = (c.noms + ((int64_t)(((int64_t)((r.noms).len))))), .added = (c.added + sriqsat_sum_added(dl))});
}

sriqsat_Run sriqsat_sat_once(slop_arena* next, slop_arena* scratch, sriqref_Env env, sriqsat_SatConfig cfg, sriqsat_Run run) {
    {
        __auto_type r = sriqsat_sat_round(scratch, env, run.st, run.dl, cfg.perm);
        if (r.over) {
            return ((sriqsat_Run){.st = run.st, .dl = run.dl, .status = sriqref_RefStatus_rs_product, .rounds = run.rounds, .going = 0, .counts = run.counts});
        } else {
            {
                __auto_type sp = sriqsat_sat_apply(scratch, run.st, r);
                __auto_type st = sriqref_copy_structure(next, sp.st);
                __auto_type status = sriqref_stop_status(scratch, env, st, ((sriqref_Committing){.st = st, .changed = sp.changed}), cfg.base);
                return ((sriqsat_Run){.st = st, .dl = sriqsat_copy_delta(next, sp.dl), .status = status, .rounds = (run.rounds + 1), .going = (status == sriqref_RefStatus_rs_fuel), .counts = sriqsat_tally(run.counts, r, sp.dl)});
            }
        }
    }
}

sriqsat_SatResult sriqsat_sat_run(slop_arena* arena, sriqref_RefIn in, sriqsat_SatConfig cfg) {
    {
        __auto_type base = cfg.base;
        __auto_type tr = sriqctx_build_triggers(arena, in.onto, in.nclass, in.nrole, in.nfn);
        __auto_type lam = (((base.lam >= 0)) ? base.lam : sriqref_ref_lambda(tr, base.strat, in.nquery));
        __auto_type env = sriqref_env_of(arena, in, base, tr, lam);
        __auto_type st0 = sriqctx_init_structure(arena, in.nquery, in.nconst);
        __auto_type held = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        __auto_type run = ((sriqsat_Run){.st = st0, .dl = sriqsat_first_delta(arena, st0), .status = sriqref_RefStatus_rs_fuel, .rounds = 0, .going = 1, .counts = ((sriqsat_Counts){.cands = 0, .rcands = 0, .succs = 0, .rsuccs = 0, .noms = 0, .added = 0})});
        while (run.going && (run.rounds < base.fuel)) {
            {
                __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                __auto_type next = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                __auto_type nr = sriqsat_sat_once(next, scratch, env, cfg, run);
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
            __auto_type done = sriqref_copy_structure(arena, run.st);
            ({ slop_arena_free(held); free(held); });
            return ((sriqsat_SatResult){.res = ((sriqref_RefResult){.status = run.status, .rounds = run.rounds, .st = done}), .counts = run.counts});
        }
    }
}

