#include "../runtime/slop_runtime.h"
#include "slop_sriqref.h"

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

typedef struct { slop_list_sriqref_NomAct noms; sriqref_NomAct n0; } sriqref__lambda_1308_env_t;

static int64_t sriqref__lambda_1308(sriqref__lambda_1308_env_t* _env, int64_t i, int64_t j) { return sriqref_nom_cmp(sriqref_nom_at(_env->noms, i, _env->n0), sriqref_nom_at(_env->noms, j, _env->n0)); }

typedef struct { slop_list_list_types_Lit fresh; slop_list_types_Lit f0; } sriqref__lambda_1313_env_t;

static int64_t sriqref__lambda_1313(sriqref__lambda_1313_env_t* _env, int64_t i, int64_t j) { return sriqref_lits_cmp(sriqref_core_at_k(_env->fresh, i, _env->f0), sriqref_core_at_k(_env->fresh, j, _env->f0)); }

typedef struct { slop_list_sriqref_Cand cands; sriqref_Cand c0; } sriqref__lambda_1316_env_t;

static int64_t sriqref__lambda_1316(sriqref__lambda_1316_env_t* _env, int64_t i, int64_t j) { return sriqref_cand_cmp(sriqref_cand_at(_env->cands, i, _env->c0), sriqref_cand_at(_env->cands, j, _env->c0)); }

slop_list_types_Clause sriqref_set_of(sriqref_Env env, sriqctx_Structure st, int64_t v) {
    __auto_type _mv_1296 = ({ __auto_type _lst = st.sets; size_t _idx = (size_t)v; slop_option_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1296.has_value) {
        __auto_type s = _mv_1296.value;
        return s.cs;
    } else if (!_mv_1296.has_value) {
        return env.nobody;
    }
    SLOP_UNREACHABLE();
}

slop_option_sriqctx_Ctx sriqref_ctx_of(sriqctx_Structure st, int64_t v) {
    return ({ __auto_type _lst = st.ctxs; size_t _idx = (size_t)v; slop_option_sriqctx_Ctx _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
}

uint8_t sriqref_is_root(sriqctx_Structure st, int64_t v) {
    __auto_type _mv_1297 = sriqref_ctx_of(st, v);
    if (_mv_1297.has_value) {
        __auto_type c = _mv_1297.value;
        return c.root;
    } else if (!_mv_1297.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_list_types_Lit sriqref_core_at(sriqref_Env env, sriqctx_Structure st, slop_arena* arena, int64_t v) {
    __auto_type _mv_1298 = sriqref_ctx_of(st, v);
    if (_mv_1298.has_value) {
        __auto_type c = _mv_1298.value;
        return c.core;
    } else if (!_mv_1298.has_value) {
        return ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

slop_list_sriqref_Cand sriqref_one_cand(slop_arena* arena, uint32_t v, types_Clause c) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqref_Cand){.ctx = v, .c = c})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

sriqref_Out sriqref_out_of(slop_list_sriqref_Cand cands, uint8_t over) {
    return ((sriqref_Out){.cands = cands, .over = over});
}

slop_list_sriq_Premise sriqref_premises_of(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Clause cs) {
    {
        __auto_type out = ((slop_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    int64_t i = 0;
                    while (i < ((int64_t)(((int64_t)((c.head).len))))) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (sriq_select(arena, ord, c, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        i = (i + 1);
                    }
                }
            }
        }
        return out;
    }
}

int64_t sriqref_consts_of(sriqctx_Structure st) {
    return ((int64_t)(((int64_t)((st.ord.consts).len))));
}

slop_list_sriqref_Cand sriqref_conclusion(slop_arena* arena, uint32_t v, sriq_RConcl r) {
    if (r.fires) {
        return sriqref_one_cand(arena, v, sriq_assemble(arena, r));
    } else {
        return ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
}

slop_list_sriqref_Cand sriqref_append_cands(slop_arena* arena, slop_list_sriqref_Cand a, slop_list_sriqref_Cand b) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = b;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

sriq_Premise sriqref_prem_at(slop_list_sriq_Premise ps, int64_t k, sriq_Premise fallback) {
    __auto_type _mv_1299 = ({ __auto_type _lst = ps; size_t _idx = (size_t)k; slop_option_sriq_Premise _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1299.has_value) {
        __auto_type p = _mv_1299.value;
        return p;
    } else if (!_mv_1299.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

int64_t sriqref_product(slop_list_list_sriq_Premise cs, int64_t cap) {
    {
        int64_t n = 1;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                n = ((((n * ((int64_t)(((int64_t)((c).len))))) > cap)) ? (cap + 1) : (n * ((int64_t)(((int64_t)((c).len))))));
            }
        }
        return n;
    }
}

slop_list_sriqref_Cand sriqref_ref_core(slop_arena* arena, uint32_t v, slop_list_types_Lit core) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = core;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    __auto_type _coll = sriqref_conclusion(arena, v, sriq_core_rule(arena, a));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

uint8_t sriqref_x_fits(uint8_t root, types_ATerm a, types_ATerm t) {
    return ((root) || (!((a.kind == types_AKind_ak_x))) || ((t.kind == types_AKind_ak_x)));
}

slop_list_sriq_Premise sriqref_slot_cands(slop_arena* arena, uint8_t root, types_Lit a, slop_list_sriq_Premise ps) {
    {
        __auto_type out = ((slop_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if ((p.maxed) && ((p.sel.form == a.form)) && ((p.sel.pred == a.pred)) && (sriqref_x_fits(root, a.t1, p.sel.t1)) && (((a.form == types_LitForm_lf_unary) || sriqref_x_fits(root, a.t2, p.sel.t2)))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

sriq_HState sriqref_hyper_choice(slop_arena* arena, sriq_HState start, slop_list_types_Lit atoms, slop_list_list_sriq_Premise cs, int64_t t, sriq_Premise fallback) {
    {
        __auto_type st = start;
        int64_t r = t;
        int64_t j = 0;
        {
            __auto_type _coll = atoms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_1300 = ({ __auto_type _lst = cs; size_t _idx = (size_t)j; slop_option_list_sriq_Premise _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1300.has_value) {
                    __auto_type c = _mv_1300.value;
                    {
                        __auto_type n = ((int64_t)(((int64_t)((c).len))));
                        st = sriq_hyper_step(arena, st, a, sriqref_prem_at(c, (r % n), fallback));
                        r = (r / n);
                    }
                } else if (!_mv_1300.has_value) {
                }
                j = (j + 1);
            }
        }
        return st;
    }
}

sriqref_Out sriqref_hyper_with(slop_arena* arena, sriqref_Env env, uint32_t v, uint8_t root, sriq_HState start, types_Clause oc, slop_list_sriq_Premise ps) {
    {
        __auto_type cs = ((slop_list_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = oc.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(cs); __auto_type _item = (sriqref_slot_cands(arena, root, a, ps)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type n = sriqref_product(cs, env.prod);
            if (n > env.prod) {
                return sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 1);
            } else {
                __auto_type _mv_1301 = ({ __auto_type _lst = ps; size_t _idx = (size_t)0; slop_option_sriq_Premise _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (!_mv_1301.has_value) {
                    return sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0);
                } else if (_mv_1301.has_value) {
                    __auto_type p0 = _mv_1301.value;
                    return sriqref_out_of(sriqref_hyper_choices(arena, v, start, oc, cs, n, p0), 0);
                }
                SLOP_UNREACHABLE();
            }
        }
    }
}

slop_list_sriqref_Cand sriqref_hyper_choices(slop_arena* arena, uint32_t v, sriq_HState start, types_Clause oc, slop_list_list_sriq_Premise cs, int64_t n, sriq_Premise p0) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t t = 0;
        while (t < n) {
            {
                __auto_type _coll = sriqref_conclusion(arena, v, sriq_hyper_finish(arena, sriqref_hyper_choice(arena, start, oc.body, cs, t, p0), oc.head));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            t = (t + 1);
        }
        return out;
    }
}

slop_list_sriqref_Cand sriqref_hyper_bodiless(slop_arena* arena, sriqctx_Structure st, uint32_t v, uint8_t root, types_Clause oc) {
    if (!(root)) {
        return sriqref_conclusion(arena, v, sriq_hyper_finish(arena, sriq_hyper_start(arena, types_at_x(), 1), oc.head));
    } else {
        return sriqref_hyper_consts(arena, st, v, oc);
    }
}

slop_list_sriqref_Cand sriqref_hyper_consts(slop_arena* arena, sriqctx_Structure st, uint32_t v, types_Clause oc) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t u = 0;
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

sriqref_Out sriqref_ref_hyper(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, uint8_t root, slop_list_sriq_Premise ps) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        {
            __auto_type _coll = env.onto;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type oc = _coll.data[_i];
                if (((int64_t)((oc.body).len)) == 0) {
                    {
                        __auto_type _coll = sriqref_hyper_bodiless(arena, st, v, root, oc);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                } else {
                    {
                        __auto_type o = sriqref_hyper_with(arena, env, v, root, sriq_hyper_start(arena, types_at_x(), !(root)), oc, ps);
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

slop_list_sriqref_Cand sriqref_eq_positions(slop_arena* arena, sriqorder_SriqOrder ord, uint32_t v, uint8_t root, sriq_Premise p1, uint32_t k1, sriq_Premise p2) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t a = 1;
        while (a <= 2) {
            {
                __auto_type _coll = sriqref_eq_at(arena, ord, v, root, p1, k1, p2, ((uint32_t)(a)));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            a = (a + 1);
        }
        return out;
    }
}

slop_list_sriqref_Cand sriqref_eq_at(slop_arena* arena, sriqorder_SriqOrder ord, uint32_t v, uint8_t root, sriq_Premise p1, uint32_t k1, sriq_Premise p2, uint32_t a) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = sriqref_bools(arena);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type inner = _coll.data[_i];
                {
                    __auto_type _coll = sriqref_conclusion(arena, v, sriq_eq_rule(arena, ord, root, p1, k1, p2, ((sriq_Pos){.arg = a, .inner = inner})));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

slop_list_u8 sriqref_bools(slop_arena* arena) {
    {
        __auto_type out = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (1); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

slop_list_sriqref_Cand sriqref_ref_eq(slop_arena* arena, sriqorder_SriqOrder ord, uint32_t v, uint8_t root, slop_list_sriq_Premise ps) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p1 = _coll.data[_i];
                if (p1.maxed && (p1.sel.form == types_LitForm_lf_eq)) {
                    {
                        __auto_type _coll = ps;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type p2 = _coll.data[_i];
                            if (p2.maxed) {
                                {
                                    __auto_type _coll = sriqref_eq_positions(arena, ord, v, root, p1, ((uint32_t)(1)), p2);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type c = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                {
                                    __auto_type _coll = sriqref_eq_positions(arena, ord, v, root, p1, ((uint32_t)(2)), p2);
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

slop_list_sriqref_Cand sriqref_ref_ineq(slop_arena* arena, uint32_t v, slop_list_sriq_Premise ps) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                {
                    __auto_type _coll = sriqref_conclusion(arena, v, sriq_ineq_rule(p));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

slop_list_sriqref_Cand sriqref_factor_of(slop_arena* arena, sriqorder_SriqOrder ord, uint32_t v, sriq_Premise p) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = p.rest;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l1 = _coll.data[_i];
                if (l1.form == types_LitForm_lf_eq) {
                    {
                        __auto_type _coll = sriqref_conclusion(arena, v, sriq_factor_rule(arena, ord, p, l1, p.sel.t1));
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                    {
                        __auto_type _coll = sriqref_conclusion(arena, v, sriq_factor_rule(arena, ord, p, l1, p.sel.t2));
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

slop_list_sriqref_Cand sriqref_ref_factor(slop_arena* arena, sriqorder_SriqOrder ord, uint32_t v, slop_list_sriq_Premise ps) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (p.maxed && (p.sel.form == types_LitForm_lf_eq)) {
                    {
                        __auto_type _coll = sriqref_factor_of(arena, ord, v, p);
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

slop_list_sriqref_Cand sriqref_join_into(slop_arena* arena, uint32_t v, sriq_Premise p1, types_Clause c2) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        while (j < ((int64_t)(((int64_t)((c2.body).len))))) {
            {
                __auto_type _coll = sriqref_conclusion(arena, v, sriq_join_rule(arena, p1, sriq_body_at(arena, c2, j)));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            j = (j + 1);
        }
        return out;
    }
}

slop_list_sriqref_Cand sriqref_ref_join(slop_arena* arena, uint32_t v, slop_list_sriq_Premise ps, slop_list_types_Clause cs) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p1 = _coll.data[_i];
                if (p1.maxed) {
                    {
                        __auto_type _coll = cs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c2 = _coll.data[_i];
                            {
                                __auto_type _coll = sriqref_join_into(arena, v, p1, c2);
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
        return out;
    }
}

sriqref_Dl4 sriqref_dl4_of(types_Clause oc) {
    {
        uint32_t b1 = ((uint32_t)(0));
        int64_t nb = 0;
        uint32_t sb2 = ((uint32_t)(0));
        int64_t nr = 0;
        uint8_t roles_ok = 1;
        {
            __auto_type _coll = oc.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (l.form == types_LitForm_lf_unary) {
                    b1 = l.pred;
                    nb = (nb + 1);
                } else if (((l.form == types_LitForm_lf_binary)) && ((l.t1.kind == types_AKind_ak_x)) && ((l.t2.kind == types_AKind_ak_z))) {
                    if ((nr > 0) && (l.pred != sb2)) {
                        roles_ok = 0;
                    }
                    sb2 = l.pred;
                    nr = (nr + 1);
                } else {
                    nb = (nb + 2);
                }
            }
        }
        return ((sriqref_Dl4){.ok = (((nb == 1)) && ((nr > 0)) && (roles_ok) && (sriqref_at_most_head(oc.head, nr))), .b1 = b1, .sb2 = sb2, .n = ((uint32_t)((nr - 1)))});
    }
}

uint8_t sriqref_at_most_head(slop_list_types_Lit head, int64_t m) {
    {
        uint8_t ok = (((int64_t)(((int64_t)((head).len)))) == ((m * (m - 1)) / 2));
        {
            __auto_type _coll = head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!((((l.form == types_LitForm_lf_eq)) && ((l.t1.kind == types_AKind_ak_z)) && ((l.t2.kind == types_AKind_ak_z))))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

slop_option_u32 sriqref_child_of(sriqorder_SriqOrder ord, uint32_t o, uint32_t sb2, uint32_t i) {
    {
        int64_t k = 0;
        slop_option_u32 found = (slop_option_u32){.has_value = false};
        {
            __auto_type _coll = ord.consts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (((e.parent == o)) && ((e.srole == sb2)) && ((e.i == i)) && ((e.len > ((uint32_t)(0))))) {
                    found = (slop_option_u32){.has_value = 1, .value = ((uint32_t)(k))};
                }
                k = (k + 1);
            }
        }
        return found;
    }
}

sriqref_Round sriqref_nom_pair(slop_arena* arena, sriqref_Env env, sriqorder_SriqOrder ord, uint32_t v, sriqref_Dl4 d, sriq_Premise p1, sriq_Premise p2) {
    {
        __auto_type o = p1.sel.t1.cst;
        __auto_type kids = ((slop_list_u32){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type missing = ((slop_list_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint32_t i = ((uint32_t)(1));
        while (i <= d.n) {
            __auto_type _mv_1302 = sriqref_child_of(ord, o, d.sb2, i);
            if (_mv_1302.has_value) {
                __auto_type k = _mv_1302.value;
                ({ __auto_type _lst_p = &(kids); __auto_type _item = (k); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_1302.has_value) {
                ({ __auto_type _lst_p = &(missing); __auto_type _item = (((sriqref_NomAct){.o = o, .sb2 = d.sb2, .i = i})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
            i = (i + ((uint32_t)(1)));
        }
        if (((int64_t)((missing).len)) == 0) {
            return sriqref_round_of(sriqref_conclusion(arena, v, sriq_nom_rule(arena, ord, env.lam, d.b1, d.sb2, d.n, p1, p2, kids)), ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0);
        } else if (((int64_t)(sriqorder_const_entry(ord, o).len)) < env.lam) {
            return sriqref_round_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), missing, 0);
        } else {
            return sriqref_round_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0);
        }
    }
}

uint8_t sriqref_nom_first(sriq_Premise p, sriqref_Dl4 d) {
    {
        __auto_type a = p.sel;
        return ((p.maxed) && ((a.form == types_LitForm_lf_unary)) && ((a.pred == d.b1)) && ((a.t1.kind == types_AKind_ak_u)));
    }
}

uint8_t sriqref_nom_second(sriq_Premise p, sriqref_Dl4 d, uint32_t o) {
    {
        __auto_type r = p.sel;
        return ((p.maxed) && ((r.form == types_LitForm_lf_binary)) && ((r.pred == d.sb2)) && ((r.t1.kind == types_AKind_ak_u)) && ((r.t1.cst == o)) && ((r.t2.kind == types_AKind_ak_x)));
    }
}

sriqref_Round sriqref_nom_clause(slop_arena* arena, sriqref_Env env, sriqorder_SriqOrder ord, uint32_t v, sriqref_Dl4 d, slop_list_sriq_Premise ps) {
    {
        __auto_type cands = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type noms = ((slop_list_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p1 = _coll.data[_i];
                if (sriqref_nom_first(p1, d)) {
                    {
                        __auto_type _coll = ps;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type p2 = _coll.data[_i];
                            if (sriqref_nom_second(p2, d, p1.sel.t1.cst)) {
                                {
                                    __auto_type r = sriqref_nom_pair(arena, env, ord, v, d, p1, p2);
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

sriqref_Round sriqref_ref_nom(slop_arena* arena, sriqref_Env env, sriqorder_SriqOrder ord, uint32_t v, slop_list_sriq_Premise ps) {
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
                            __auto_type r = sriqref_nom_clause(arena, env, ord, v, d, ps);
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

sriqref_Round sriqref_round_of(slop_list_sriqref_Cand cands, slop_list_sriqref_SuccAct succs, slop_list_sriqref_RSuccAct rsuccs, slop_list_sriqref_NomAct noms, uint8_t over) {
    return ((sriqref_Round){.cands = cands, .succs = succs, .rsuccs = rsuccs, .noms = noms, .over = over});
}

uint8_t sriqref_edge_is(sriqctx_Edge e, uint32_t from, uint32_t to, sriqctx_EdgeLabel lk, uint32_t label) {
    return (((e.from == from)) && ((e.to == to)) && ((e.lk == lk)) && ((e.label == label)));
}

uint8_t sriqref_has_edge(sriqctx_Structure st, uint32_t from, uint32_t to, sriqctx_EdgeLabel lk, uint32_t label) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = st.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (sriqref_edge_is(e, from, to, lk, label)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t sriqref_covered(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, uint32_t f, slop_list_types_Lit k2) {
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

slop_list_sriqref_SuccAct sriqref_succ_of(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, uint8_t root, slop_list_types_Clause cs, sriq_Premise p) {
    __auto_type _mv_1303 = sriq_succ_sig(root, p.sel);
    if (!_mv_1303.has_value) {
        return ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    } else if (_mv_1303.has_value) {
        __auto_type sg = _mv_1303.value;
        return sriqref_succ_with(arena, env, st, v, cs, p, sg);
    }
    SLOP_UNREACHABLE();
}

slop_list_sriqref_SuccAct sriqref_succ_with(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, slop_list_types_Clause cs, sriq_Premise p, sriq_SuccSig sg) {
    {
        __auto_type out = ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type ks = sriq_k_sets(arena, st.ord, env.tr, sg, cs);
        __auto_type r = sriq_succ_step(arena, env.strat, env.tr, sg, p, ks, sriqref_covered(arena, env, st, v, sg.f, ks.k2));
        if (r.fires) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqref_SuccAct){.from = v, .sg = sg, .core = sriqctx_core_of(arena, r.choice, ks.k1), .adds = r.adds})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return out;
    }
}

slop_list_sriqref_SuccAct sriqref_ref_succ(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, uint8_t root, slop_list_types_Clause cs, slop_list_sriq_Premise ps) {
    {
        __auto_type out = ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (p.maxed) {
                    {
                        __auto_type _coll = sriqref_succ_of(arena, env, st, v, root, cs, p);
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

slop_list_u32 sriqref_lit_consts(slop_arena* arena, types_Lit l) {
    {
        __auto_type out = ((slop_list_u32){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (l.t1.kind == types_AKind_ak_u) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (l.t1.cst); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        if ((!((l.form == types_LitForm_lf_unary))) && ((l.t2.kind == types_AKind_ak_u)) && (!(((l.t1.kind == types_AKind_ak_u) && (l.t1.cst == l.t2.cst))))) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (l.t2.cst); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return out;
    }
}

slop_list_sriqref_RSuccAct sriqref_ref_rsucc(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, slop_list_sriq_Premise ps) {
    {
        __auto_type out = ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type root_set = sriqref_set_of(env, st, 0);
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (p.maxed) {
                    {
                        __auto_type _coll = sriqref_rsucc_of(arena, env, st, v, root_set, p);
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

slop_list_sriqref_RSuccAct sriqref_rsucc_of(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, slop_list_types_Clause root_set, sriq_Premise p) {
    {
        __auto_type out = ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = sriqref_lit_consts(arena, sriq_rsucc_lit(p.sel));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type u = _coll.data[_i];
                {
                    __auto_type r = sriq_rsucc_rule(env.tr, 0, p, u, (sriqref_has_edge(st, v, ((uint32_t)(0)), sriqctx_EdgeLabel_el_const, u) && sriq_unit_held(sriq_rsucc_lit(p.sel), root_set)));
                    if (r.fires) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqref_RSuccAct){.from = v, .u = u, .lit = r.lit})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

slop_list_sriq_Premise sriqref_pslot_cands(slop_arena* arena, sriq_CSub s, sriq_PSlot slot, slop_list_sriq_Premise ps) {
    {
        __auto_type want = sriq_csub_lit(s, slot.lit);
        __auto_type out = ((slop_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (p.maxed && types_lit_eq(p.sel, want)) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

sriq_PState sriqref_pred_choice(slop_arena* arena, sriq_PState start, sriq_CSub s, slop_list_sriq_PSlot slots, slop_list_list_sriq_Premise cs, int64_t t, sriq_Premise fallback) {
    {
        __auto_type st = start;
        int64_t r = t;
        int64_t j = 0;
        {
            __auto_type _coll = slots;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type slot = _coll.data[_i];
                __auto_type _mv_1304 = ({ __auto_type _lst = cs; size_t _idx = (size_t)j; slop_option_list_sriq_Premise _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1304.has_value) {
                    __auto_type c = _mv_1304.value;
                    {
                        __auto_type n = ((int64_t)(((int64_t)((c).len))));
                        st = sriq_pred_step(arena, st, s, slot, sriqref_prem_at(c, (r % n), fallback));
                        r = (r / n);
                    }
                } else if (!_mv_1304.has_value) {
                }
                j = (j + 1);
            }
        }
        return st;
    }
}

sriqref_Out sriqref_pred_run(slop_arena* arena, sriqref_Env env, sriqref_PJob job, slop_list_sriq_Premise ps) {
    {
        __auto_type cs = ((slop_list_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = job.slots;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type slot = _coll.data[_i];
                ({ __auto_type _lst_p = &(cs); __auto_type _item = (sriqref_pslot_cands(arena, job.s, slot, ps)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type n = sriqref_product(cs, env.prod);
            if (n > env.prod) {
                return sriqref_out_of(out, 1);
            } else {
                {
                    int64_t t = 0;
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
    }
}

slop_list_sriqref_Cand sriqref_pred_one(slop_arena* arena, sriqref_Env env, sriqref_PJob job, slop_list_list_sriq_Premise cs, int64_t t, slop_list_sriq_Premise ps) {
    {
        __auto_type fallback = sriqref_prem_or(ps, job.view);
        __auto_type st = sriqref_pred_choice(arena, sriq_pred_start(arena, 1), job.s, job.slots, cs, t, fallback);
        if (job.rpred) {
            return sriqref_conclusion(arena, job.to, sriq_rpred_finish(arena, st, env.tr, job.view));
        } else {
            return sriqref_conclusion(arena, job.to, sriq_pred_finish(arena, st, job.s, env.tr, job.toroot, job.view));
        }
    }
}

sriq_Premise sriqref_prem_or(slop_list_sriq_Premise ps, sriq_PredView v) {
    __auto_type _mv_1305 = ({ __auto_type _lst = ps; size_t _idx = (size_t)0; slop_option_sriq_Premise _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1305.has_value) {
        __auto_type p = _mv_1305.value;
        return p;
    } else if (!_mv_1305.has_value) {
        return ((sriq_Premise){.body = v.ground, .sel = types_atom1(((uint32_t)(0)), types_at_x()), .rest = v.head, .maxed = 0});
    }
    SLOP_UNREACHABLE();
}

slop_list_sriq_PSlot sriqref_slots_of(slop_arena* arena, slop_list_types_Lit lits) {
    {
        __auto_type out = ((slop_list_sriq_PSlot){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = lits;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriq_PSlot){.lit = l, .edge = 1})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

sriqref_Out sriqref_pred_edge(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, sriqctx_Edge e, slop_list_types_Clause cs) {
    {
        __auto_type w = e.from;
        __auto_type toroot = sriqref_is_root(st, ((int64_t)(e.from)));
        __auto_type ws = sriqref_premises_of(arena, st.ord, sriqref_set_of(env, st, ((int64_t)(e.from))));
        __auto_type core = sriqref_core_at(env, st, arena, ((int64_t)(v)));
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type o = sriqref_pred_clause(arena, env, st, e, w, toroot, core, ws, c);
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

sriqref_Out sriqref_pred_clause(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqctx_Edge e, uint32_t w, uint8_t toroot, slop_list_types_Lit core, slop_list_sriq_Premise ws, types_Clause c) {
    {
        __auto_type view = sriq_pred_view(arena, c, core, toroot);
        __auto_type slots = sriqref_slots_of(arena, view.slots);
        if (!(toroot)) {
            return sriqref_pred_run(arena, env, sriqref_away_job(view, slots, e.label, w), ws);
        } else {
            return sriqref_pred_root(arena, env, st, view, slots, w, e.label, ws);
        }
    }
}

sriqref_PJob sriqref_away_job(sriq_PredView view, slop_list_sriq_PSlot slots, uint32_t f, uint32_t w) {
    return ((sriqref_PJob){.view = view, .s = sriq_succ_csub(sriqref_sig_away(f)), .slots = slots, .to = w, .rpred = 0, .toroot = 0});
}

sriqref_Out sriqref_pred_root(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriq_PredView view, slop_list_sriq_PSlot slots, uint32_t w, uint32_t f, slop_list_sriq_Premise ws) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        int64_t u = 0;
        while (u < sriqref_consts_of(st)) {
            {
                __auto_type o = sriqref_pred_run(arena, env, sriqref_root_job(view, slots, w, f, ((uint32_t)(u))), ws);
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
                u = (u + 1);
            }
        }
        return sriqref_out_of(out, over);
    }
}

sriqref_PJob sriqref_root_job(sriq_PredView view, slop_list_sriq_PSlot slots, uint32_t w, uint32_t f, uint32_t u) {
    return ((sriqref_PJob){.view = view, .s = sriq_succ_csub(sriqref_sig_at(f, u)), .slots = slots, .to = w, .rpred = 0, .toroot = 1});
}

sriq_SuccSig sriqref_sig_away(uint32_t f) {
    return ((sriq_SuccSig){.f = f, .root = 0, .u = ((uint32_t)(0))});
}

sriq_SuccSig sriqref_sig_at(uint32_t f, uint32_t u) {
    return ((sriq_SuccSig){.f = f, .root = 1, .u = u});
}

sriqref_Out sriqref_ref_pred(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, slop_list_types_Clause cs) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        {
            __auto_type _coll = st.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if ((e.to == v) && (e.lk == sriqctx_EdgeLabel_el_fn)) {
                    {
                        __auto_type o = sriqref_pred_edge(arena, env, st, v, e, cs);
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

uint32_t sriqref_slot_const(types_Lit l) {
    if (l.t1.kind == types_AKind_ak_u) {
        return l.t1.cst;
    } else {
        return l.t2.cst;
    }
}

slop_list_sriq_PSlot sriqref_rslots(slop_arena* arena, sriqctx_Structure st, uint32_t v, slop_list_types_Lit lits) {
    {
        __auto_type out = ((slop_list_sriq_PSlot){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = lits;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriq_PSlot){.lit = l, .edge = sriqref_has_edge(st, v, ((uint32_t)(0)), sriqctx_EdgeLabel_el_const, sriqref_slot_const(l))})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

sriqref_Out sriqref_ref_rpred(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, slop_list_sriq_Premise ps) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        {
            __auto_type _coll = sriqref_set_of(env, st, 0);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type o = sriqref_pred_run(arena, env, sriqref_rpred_job(arena, env, st, v, c), ps);
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

sriqref_PJob sriqref_rpred_job(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, types_Clause c) {
    {
        __auto_type view = sriq_rpred_view(arena, env.tr, c);
        return ((sriqref_PJob){.view = view, .s = ((sriq_CSub){.x = types_at_x(), .y = types_at_x()}), .slots = sriqref_rslots(arena, st, v, view.slots), .to = v, .rpred = 1, .toroot = 0});
    }
}

sriqref_Out sriqref_ctx_table2(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, uint8_t root, slop_list_types_Clause cs, slop_list_sriq_Premise ps) {
    {
        __auto_type ord = st.ord;
        __auto_type h = sriqref_ref_hyper(arena, env, st, v, root, ps);
        __auto_type out = sriqref_ref_core(arena, v, sriqref_core_at(env, st, arena, ((int64_t)(v))));
        {
            __auto_type _coll = h.cands;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqref_ref_eq(arena, ord, v, root, ps);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqref_ref_ineq(arena, v, ps);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqref_ref_factor(arena, ord, v, ps);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqref_ref_join(arena, v, ps, cs);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return sriqref_out_of(out, h.over);
    }
}

sriqref_Round sriqref_ctx_round(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v) {
    {
        __auto_type root = sriqref_is_root(st, ((int64_t)(v)));
        __auto_type cs = sriqref_set_of(env, st, ((int64_t)(v)));
        __auto_type ps = sriqref_premises_of(arena, st.ord, sriqref_set_of(env, st, ((int64_t)(v))));
        __auto_type t2 = sriqref_ctx_table2(arena, env, st, v, root, cs, ps);
        __auto_type nom = sriqref_ref_nom(arena, env, st.ord, v, ps);
        __auto_type pr = ((root) ? sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0) : sriqref_ref_pred(arena, env, st, v, cs));
        __auto_type rp = ((root) ? sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0) : sriqref_ref_rpred(arena, env, st, v, ps));
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
        return sriqref_round_of(cands, sriqref_ref_succ(arena, env, st, v, root, cs, ps), ((root) ? ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) : sriqref_ref_rsucc(arena, env, st, v, ps)), nom.noms, ((t2.over) || (pr.over) || (rp.over)));
    }
}

sriqref_Round sriqref_ref_round(slop_arena* arena, sriqref_Env env, sriqctx_Structure st) {
    {
        __auto_type cands = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type succs = ((slop_list_sriqref_SuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type rsuccs = ((slop_list_sriqref_RSuccAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type noms = ((slop_list_sriqref_NomAct){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        int64_t v = 0;
        while (v < ((int64_t)(((int64_t)((st.ctxs).len))))) {
            {
                __auto_type r = sriqref_ctx_round(arena, env, st, ((uint32_t)(v)));
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
                v = (v + 1);
            }
        }
        return sriqref_round_of(cands, succs, rsuccs, noms, over);
    }
}

int64_t sriqref_nom_cmp(sriqref_NomAct a, sriqref_NomAct b) {
    if (a.o < b.o) {
        return -1;
    } else if (a.o > b.o) {
        return 1;
    } else if (a.sb2 < b.sb2) {
        return -1;
    } else if (a.sb2 > b.sb2) {
        return 1;
    } else if (a.i < b.i) {
        return -1;
    } else if (a.i > b.i) {
        return 1;
    } else {
        return 0;
    }
}

sriqref_NomAct sriqref_nom_at(slop_list_sriqref_NomAct xs, int64_t k, sriqref_NomAct fallback) {
    __auto_type _mv_1306 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_sriqref_NomAct _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1306.has_value) {
        __auto_type x = _mv_1306.value;
        return x;
    } else if (!_mv_1306.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

sriqorder_SriqOrder sriqref_add_consts(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_sriqref_NomAct noms) {
    __auto_type _mv_1307 = ({ __auto_type _lst = noms; size_t _idx = (size_t)0; slop_option_sriqref_NomAct _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1307.has_value) {
        return ord;
    } else if (_mv_1307.has_value) {
        __auto_type n0 = _mv_1307.value;
        {
            __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((noms).len)))), ({ sriqref__lambda_1308_env_t* sriqref__lambda_1308_env = (sriqref__lambda_1308_env_t*)slop_arena_alloc(arena, sizeof(sriqref__lambda_1308_env_t)); *sriqref__lambda_1308_env = (sriqref__lambda_1308_env_t){ .noms = noms, .n0 = n0 }; (slop_closure_t){ (void*)sriqref__lambda_1308, (void*)sriqref__lambda_1308_env }; }));
            __auto_type cur = ord;
            {
                __auto_type _coll = idx;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type k = _coll.data[_i];
                    cur = sriqref_with_child(arena, cur, sriqref_nom_at(noms, k, n0));
                }
            }
            return cur;
        }
    }
    SLOP_UNREACHABLE();
}

sriqorder_SriqOrder sriqref_with_child(slop_arena* arena, sriqorder_SriqOrder ord, sriqref_NomAct a) {
    __auto_type _mv_1309 = sriqref_child_of(ord, a.o, a.sb2, a.i);
    if (_mv_1309.has_value) {
        __auto_type _ = _mv_1309.value;
        return ord;
    } else if (!_mv_1309.has_value) {
        return sriqref_push_const(arena, ord, sriqorder_aux_const(sriqorder_const_entry(ord, a.o), a.o, a.sb2, a.i));
    }
    SLOP_UNREACHABLE();
}

sriqorder_SriqOrder sriqref_push_const(slop_arena* arena, sriqorder_SriqOrder ord, sriqorder_ConstEntry e) {
    {
        __auto_type cs = ((slop_list_sriqorder_ConstEntry){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ord.consts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(cs); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        ({ __auto_type _lst_p = &(cs); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((sriqorder_SriqOrder){.consts = cs, .rank = ord.rank});
    }
}

int64_t sriqref_lits_cmp(slop_list_types_Lit a, slop_list_types_Lit b) {
    {
        __auto_type na = ((int64_t)(((int64_t)((a).len))));
        __auto_type nb = ((int64_t)(((int64_t)((b).len))));
        int64_t r = 0;
        int64_t i = 0;
        if (na < nb) {
            r = -1;
        } else if (na > nb) {
            r = 1;
        } else {
            r = 0;
        }
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (r == 0) {
                    __auto_type _mv_1310 = ({ __auto_type _lst = b; size_t _idx = (size_t)i; slop_option_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_1310.has_value) {
                        __auto_type m = _mv_1310.value;
                        r = types_lit_cmp(l, m);
                    } else if (!_mv_1310.has_value) {
                        r = 1;
                    }
                }
                i = (i + 1);
            }
        }
        return r;
    }
}

uint8_t sriqref_core_in(slop_list_list_types_Lit cores, slop_list_types_Lit c) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = cores;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (sriqref_lits_cmp(x, c) == 0) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_list_types_Lit sriqref_core_at_k(slop_list_list_types_Lit xs, int64_t k, slop_list_types_Lit fallback) {
    __auto_type _mv_1311 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_list_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1311.has_value) {
        __auto_type x = _mv_1311.value;
        return x;
    } else if (!_mv_1311.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

sriqctx_Structure sriqref_add_contexts(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_SuccAct succs) {
    {
        __auto_type fresh = ((slop_list_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = succs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if ((sriqctx_ctx_by_core(st, a.core) == ((uint32_t)(4294967295))) && !(sriqref_core_in(fresh, a.core))) {
                    ({ __auto_type _lst_p = &(fresh); __auto_type _item = (a.core); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        __auto_type _mv_1312 = ({ __auto_type _lst = fresh; size_t _idx = (size_t)0; slop_option_list_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1312.has_value) {
            return st;
        } else if (_mv_1312.has_value) {
            __auto_type f0 = _mv_1312.value;
            return sriqref_with_contexts(arena, st, fresh, f0);
        }
        SLOP_UNREACHABLE();
    }
}

sriqctx_Structure sriqref_with_contexts(slop_arena* arena, sriqctx_Structure st, slop_list_list_types_Lit fresh, slop_list_types_Lit f0) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((fresh).len)))), ({ sriqref__lambda_1313_env_t* sriqref__lambda_1313_env = (sriqref__lambda_1313_env_t*)slop_arena_alloc(arena, sizeof(sriqref__lambda_1313_env_t)); *sriqref__lambda_1313_env = (sriqref__lambda_1313_env_t){ .fresh = fresh, .f0 = f0 }; (slop_closure_t){ (void*)sriqref__lambda_1313, (void*)sriqref__lambda_1313_env }; }));
        __auto_type ctxs = ((slop_list_sriqctx_Ctx){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type sets = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.ctxs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(ctxs); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                ({ __auto_type _lst_p = &(sets); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(ctxs); __auto_type _item = (((sriqctx_Ctx){.core = sriqref_core_at_k(fresh, k, f0), .root = 0})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(sets); __auto_type _item = (((sriqctx_CtxSet){.cs = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((sriqctx_Structure){.ctxs = ctxs, .sets = sets, .edges = st.edges, .ord = st.ord});
    }
}

sriqctx_Structure sriqref_add_edges(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_SuccAct succs, slop_list_sriqref_RSuccAct rsuccs) {
    {
        __auto_type es = ((slop_list_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                ({ __auto_type _lst_p = &(es); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = succs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                es = sriqref_succ_edges(arena, st, es, a);
            }
        }
        {
            __auto_type _coll = rsuccs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                es = sriqref_with_edge(arena, es, ((sriqctx_Edge){.from = a.from, .to = ((uint32_t)(0)), .lk = sriqctx_EdgeLabel_el_const, .label = a.u}));
            }
        }
        return ((sriqctx_Structure){.ctxs = st.ctxs, .sets = st.sets, .edges = es, .ord = st.ord});
    }
}

slop_list_sriqctx_Edge sriqref_succ_edges(slop_arena* arena, sriqctx_Structure st, slop_list_sriqctx_Edge es, sriqref_SuccAct a) {
    {
        __auto_type w = sriqctx_ctx_by_core(st, a.core);
        __auto_type fe = sriqref_with_edge(arena, es, ((sriqctx_Edge){.from = a.from, .to = w, .lk = sriqctx_EdgeLabel_el_fn, .label = a.sg.f}));
        if (a.sg.root) {
            return sriqref_with_edge(arena, fe, ((sriqctx_Edge){.from = a.from, .to = w, .lk = sriqctx_EdgeLabel_el_const, .label = a.sg.u}));
        } else {
            return fe;
        }
    }
}

slop_list_sriqctx_Edge sriqref_with_edge(slop_arena* arena, slop_list_sriqctx_Edge es, sriqctx_Edge e) {
    {
        uint8_t found = 0;
        __auto_type out = ((slop_list_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = es;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (sriqref_edge_is(x, e.from, e.to, e.lk, e.label)) {
                    found = 1;
                }
                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        if (!(found)) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return out;
    }
}

types_Clause sriqref_unit_clause(slop_arena* arena, types_Lit a) {
    {
        __auto_type b = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type h = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(b); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(h); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return sriqclauses_make_clause(arena, b, h);
    }
}

slop_list_sriqref_Cand sriqref_action_cands(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_SuccAct succs, slop_list_sriqref_RSuccAct rsuccs) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = succs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    __auto_type w = sriqctx_ctx_by_core(st, a.core);
                    {
                        __auto_type _coll = a.adds;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type l = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqref_Cand){.ctx = w, .c = sriqref_unit_clause(arena, l)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        {
            __auto_type _coll = rsuccs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqref_Cand){.ctx = ((uint32_t)(0)), .c = sriqref_unit_clause(arena, a.lit)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

sriqref_Cand sriqref_cand_at(slop_list_sriqref_Cand xs, int64_t k, sriqref_Cand fallback) {
    __auto_type _mv_1314 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_sriqref_Cand _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1314.has_value) {
        __auto_type x = _mv_1314.value;
        return x;
    } else if (!_mv_1314.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

int64_t sriqref_cand_cmp(sriqref_Cand a, sriqref_Cand b) {
    if (a.ctx < b.ctx) {
        return -1;
    } else if (a.ctx > b.ctx) {
        return 1;
    } else {
        return sriqclauses_clause_cmp(a.c, b.c);
    }
}

sriqref_Committing sriqref_commit_sets(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_Cand cands) {
    __auto_type _mv_1315 = ({ __auto_type _lst = cands; size_t _idx = (size_t)0; slop_option_sriqref_Cand _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1315.has_value) {
        return ((sriqref_Committing){.st = st, .changed = 0});
    } else if (_mv_1315.has_value) {
        __auto_type c0 = _mv_1315.value;
        return sriqref_commit_sorted(arena, st, cands, c0);
    }
    SLOP_UNREACHABLE();
}

sriqref_Committing sriqref_commit_sorted(slop_arena* arena, sriqctx_Structure st, slop_list_sriqref_Cand cands, sriqref_Cand c0) {
    {
        __auto_type sets = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t changed = 0;
        int64_t v = 0;
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((cands).len)))), ({ sriqref__lambda_1316_env_t* sriqref__lambda_1316_env = (sriqref__lambda_1316_env_t*)slop_arena_alloc(arena, sizeof(sriqref__lambda_1316_env_t)); *sriqref__lambda_1316_env = (sriqref__lambda_1316_env_t){ .cands = cands, .c0 = c0 }; (slop_closure_t){ (void*)sriqref__lambda_1316, (void*)sriqref__lambda_1316_env }; }));
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                {
                    __auto_type r = sriqref_grow(arena, s.cs, cands, idx, ((uint32_t)(v)), c0);
                    ({ __auto_type _lst_p = &(sets); __auto_type _item = (((sriqctx_CtxSet){.cs = r.cs})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    if (r.grew) {
                        changed = 1;
                    }
                    v = (v + 1);
                }
            }
        }
        return ((sriqref_Committing){.st = ((sriqctx_Structure){.ctxs = st.ctxs, .sets = sets, .edges = st.edges, .ord = st.ord}), .changed = changed});
    }
}

sriqref_Grown sriqref_grow(slop_arena* arena, slop_list_types_Clause cs, slop_list_sriqref_Cand cands, slop_list_int idx, uint32_t v, sriqref_Cand c0) {
    {
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t grew = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type x = sriqref_cand_at(cands, k, c0);
                    if ((x.ctx == v) && !(sriqsubsume_in_hat(x.c, out))) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x.c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        grew = 1;
                    }
                }
            }
        }
        return ((sriqref_Grown){.cs = out, .grew = grew});
    }
}

sriqref_Committing sriqref_ref_apply(slop_arena* arena, sriqctx_Structure st, sriqref_Round r) {
    {
        __auto_type n0 = ((int64_t)((st.ord.consts).len));
        __auto_type s1 = ((sriqctx_Structure){.ctxs = st.ctxs, .sets = st.sets, .edges = st.edges, .ord = sriqref_add_consts(arena, st.ord, r.noms)});
        __auto_type s2 = sriqref_add_contexts(arena, s1, r.succs);
        __auto_type s3 = sriqref_add_edges(arena, s2, r.succs, r.rsuccs);
        __auto_type cm = sriqref_commit_sets(arena, s3, sriqref_append_cands(arena, r.cands, sriqref_action_cands(arena, s3, r.succs, r.rsuccs)));
        return ((sriqref_Committing){.st = cm.st, .changed = ((cm.changed) || ((((int64_t)((s3.ord.consts).len)) != n0)) || ((((int64_t)((s3.ctxs).len)) != ((int64_t)((st.ctxs).len)))) || ((((int64_t)((s3.edges).len)) != ((int64_t)((st.edges).len)))))});
    }
}

int64_t sriqref_total_clauses(sriqctx_Structure st) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                n = (n + ((int64_t)(((int64_t)((s.cs).len)))));
            }
        }
        return n;
    }
}

uint8_t sriqref_inconsistent_now(slop_arena* arena, sriqref_Env env, sriqctx_Structure st) {
    return sriqsubsume_in_hat(sriqclauses_make_clause(arena, ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })), sriqref_set_of(env, st, 1));
}

sriqctx_Structure sriqref_ref_elim(slop_arena* arena, sriqctx_Structure st) {
    {
        __auto_type sets = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                ({ __auto_type _lst_p = &(sets); __auto_type _item = (((sriqctx_CtxSet){.cs = sriqsubsume_commit_min(arena, ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), s.cs).set})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((sriqctx_Structure){.ctxs = st.ctxs, .sets = sets, .edges = st.edges, .ord = st.ord});
    }
}

int64_t sriqref_ref_lambda(sriqctx_Triggers tr, sriqctx_Strategy s, int64_t nquery) {
    return sriq_stored_lambda(sriqctx_tau_su(tr), sriqctx_tau_pr(tr), sriqctx_omega(s, tr), sriqctx_omega_d(nquery));
}

sriqref_RefIn sriqref_ref_input(slop_arena* arena, sriqclauses_SriqClauses sc) {
    {
        __auto_type ids = sc.ids;
        return ((sriqref_RefIn){.onto = sc.clauses, .nclass = ((int64_t)(((int64_t)((ids.class_of).len)))), .nquery = ids.nclass, .nrole = ((int64_t)(((int64_t)((ids.role_of).len)))), .nfn = ids.nfns, .nconst = ((int64_t)(((int64_t)((ids.const_of).len))))});
    }
}

sriqref_RefResult sriqref_ref_run(slop_arena* arena, sriqref_RefIn in, sriqref_RefConfig cfg) {
    {
        __auto_type tr = sriqctx_build_triggers(arena, in.onto, in.nclass, in.nrole, in.nfn);
        __auto_type lam = (((cfg.lam >= 0)) ? cfg.lam : sriqref_ref_lambda(tr, cfg.strat, in.nquery));
        __auto_type env = sriqref_env_of(arena, in, cfg, tr, lam);
        __auto_type held = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        __auto_type st = sriqctx_init_structure(arena, in.nquery, in.nconst);
        sriqref_RefStatus status = sriqref_RefStatus_rs_fuel;
        int64_t rounds = 0;
        uint8_t going = 1;
        while (going && (rounds < cfg.fuel)) {
            {
                __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                __auto_type r = sriqref_ref_round(scratch, env, st);
                if (r.over) {
                    status = sriqref_RefStatus_rs_product;
                    going = 0;
                } else {
                    {
                        __auto_type cm = sriqref_ref_apply(scratch, st, r);
                        __auto_type next = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                        st = sriqref_copy_structure(next, cm.st);
                        ({ slop_arena_free(held); free(held); });
                        held = next;
                        rounds = (rounds + 1);
                        status = sriqref_stop_status(scratch, env, st, cm, cfg);
                        going = (status == sriqref_RefStatus_rs_fuel);
                    }
                }
                ({ slop_arena_free(scratch); free(scratch); });
            }
        }
        {
            __auto_type done = sriqref_ref_elim(arena, sriqref_copy_structure(arena, st));
            ({ slop_arena_free(held); free(held); });
            return ((sriqref_RefResult){.status = status, .rounds = rounds, .st = done});
        }
    }
}

slop_list_types_Lit sriqref_copy_lits(slop_arena* arena, slop_list_types_Lit ls) {
    {
        __auto_type out = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ls;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_Clause sriqref_copy_clauses(slop_arena* arena, slop_list_types_Clause cs) {
    {
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_Clause){.body = sriqref_copy_lits(arena, c.body), .head = sriqref_copy_lits(arena, c.head)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

sriqctx_Structure sriqref_copy_structure(slop_arena* arena, sriqctx_Structure st) {
    {
        __auto_type ctxs = ((slop_list_sriqctx_Ctx){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type sets = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type edges = ((slop_list_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type consts = ((slop_list_sriqorder_ConstEntry){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.ctxs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(ctxs); __auto_type _item = (((sriqctx_Ctx){.core = sriqref_copy_lits(arena, c.core), .root = c.root})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(sets); __auto_type _item = (((sriqctx_CtxSet){.cs = sriqref_copy_clauses(arena, x.cs)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = st.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                ({ __auto_type _lst_p = &(edges); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = st.ord.consts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                ({ __auto_type _lst_p = &(consts); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((sriqctx_Structure){.ctxs = ctxs, .sets = sets, .edges = edges, .ord = ((sriqorder_SriqOrder){.consts = consts, .rank = st.ord.rank})});
    }
}

sriqref_Env sriqref_env_of(slop_arena* arena, sriqref_RefIn in, sriqref_RefConfig cfg, sriqctx_Triggers tr, int64_t lam) {
    return ((sriqref_Env){.onto = in.onto, .tr = tr, .strat = cfg.strat, .lam = lam, .prod = cfg.prod, .nconst = in.nconst, .nobody = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
}

sriqref_Env sriqref_env_for(slop_arena* arena, sriqref_RefIn in, sriqref_RefConfig cfg) {
    {
        __auto_type tr = sriqctx_build_triggers(arena, in.onto, in.nclass, in.nrole, in.nfn);
        return sriqref_env_of(arena, in, cfg, tr, (((cfg.lam >= 0)) ? cfg.lam : sriqref_ref_lambda(tr, cfg.strat, in.nquery)));
    }
}

uint8_t sriqref_ref_stable(slop_arena* arena, sriqref_RefIn in, sriqref_RefConfig cfg, sriqctx_Structure st) {
    {
        __auto_type r = sriqref_ref_round(arena, sriqref_env_for(arena, in, cfg), st);
        return (!(r.over) && !(sriqref_ref_apply(arena, st, r).changed));
    }
}

sriqref_RefStatus sriqref_stop_status(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, sriqref_Committing cm, sriqref_RefConfig cfg) {
    if (!(cm.changed)) {
        return sriqref_RefStatus_rs_fixpoint;
    } else if (sriqref_inconsistent_now(arena, env, st)) {
        return sriqref_RefStatus_rs_inconsistent;
    } else if (((int64_t)(((int64_t)((st.ctxs).len)))) > cfg.ctxs) {
        return sriqref_RefStatus_rs_contexts;
    } else if (sriqref_total_clauses(st) > cfg.cls) {
        return sriqref_RefStatus_rs_clauses;
    } else if ((((int64_t)(((int64_t)((st.ord.consts).len)))) - env.nconst) > cfg.cnst) {
        return sriqref_RefStatus_rs_constants;
    } else {
        return sriqref_RefStatus_rs_fuel;
    }
}

slop_list_types_Clause sriqref_ref_set(slop_arena* arena, sriqctx_Structure st, int64_t v) {
    __auto_type _mv_1317 = ({ __auto_type _lst = st.sets; size_t _idx = (size_t)v; slop_option_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1317.has_value) {
        __auto_type s = _mv_1317.value;
        return s.cs;
    } else if (!_mv_1317.has_value) {
        return ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqref_clause_in(slop_list_types_Clause xs, types_Clause c) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (sriqclauses_clause_eq(x, c)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t sriqref_same_clauses(slop_list_types_Clause a, slop_list_types_Clause b) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (!(sriqref_clause_in(b, x))) {
                    ok = 0;
                }
            }
        }
        {
            __auto_type _coll = b;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (!(sriqref_clause_in(a, x))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

slop_list_types_Clause sriqref_cand_clauses(slop_arena* arena, slop_list_sriqref_Cand cs) {
    {
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c.c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

uint8_t sriqref_hyper_agrees(slop_arena* arena, sriqref_Env env, uint32_t v, uint8_t root, types_Clause oc, slop_list_sriq_Premise ps) {
    {
        __auto_type start = sriq_hyper_start(arena, types_at_x(), !(root));
        __auto_type cands = ((slop_list_sriq_Cands){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type joined = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = oc.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(cands); __auto_type _item = (((sriq_Cands){.ps = sriqref_slot_cands(arena, root, a, ps)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriq_hyper_join(arena, start, oc.body, cands, oc.head);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                ({ __auto_type _lst_p = &(joined); __auto_type _item = (sriq_assemble(arena, r)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type o = sriqref_hyper_with(arena, env, v, root, start, oc, ps);
            return (o.over || sriqref_same_clauses(joined, sriqref_cand_clauses(arena, o.cands)));
        }
    }
}

uint8_t sriqref_pred_agrees(slop_arena* arena, sriqref_Env env, sriqref_PJob job, slop_list_sriq_Premise ps) {
    {
        __auto_type cands = ((slop_list_sriq_PCands){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type joined = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = job.slots;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type slot = _coll.data[_i];
                ({ __auto_type _lst_p = &(cands); __auto_type _item = (((sriq_PCands){.slot = slot, .ps = sriqref_pslot_cands(arena, job.s, slot, ps)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriq_pred_join(arena, sriq_pred_start(arena, 1), job.s, cands);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type st = _coll.data[_i];
                {
                    __auto_type r = ((job.rpred) ? sriq_rpred_finish(arena, st, env.tr, job.view) : sriq_pred_finish(arena, st, job.s, env.tr, job.toroot, job.view));
                    if (r.fires) {
                        ({ __auto_type _lst_p = &(joined); __auto_type _item = (sriq_assemble(arena, r)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type o = sriqref_pred_run(arena, env, job, ps);
            return (o.over || sriqref_same_clauses(joined, sriqref_cand_clauses(arena, o.cands)));
        }
    }
}

uint8_t sriqref_ctx_agrees(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v) {
    {
        __auto_type root = sriqref_is_root(st, ((int64_t)(v)));
        __auto_type cs = sriqref_set_of(env, st, ((int64_t)(v)));
        __auto_type ps = sriqref_premises_of(arena, st.ord, sriqref_set_of(env, st, ((int64_t)(v))));
        uint8_t ok = 1;
        {
            __auto_type _coll = env.onto;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type oc = _coll.data[_i];
                if ((((int64_t)((oc.body).len)) > 0) && !(sriqref_hyper_agrees(arena, env, v, root, oc, ps))) {
                    ok = 0;
                }
            }
        }
        if (!(root)) {
            {
                __auto_type _coll = st.edges;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type e = _coll.data[_i];
                    if (((e.to == v)) && ((e.lk == sriqctx_EdgeLabel_el_fn)) && (!(sriqref_is_root(st, ((int64_t)(e.from)))))) {
                        if (!(sriqref_edge_agrees(arena, env, st, v, e, cs))) {
                            ok = 0;
                        }
                    }
                }
            }
            {
                __auto_type _coll = sriqref_set_of(env, st, 0);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    if (!(sriqref_pred_agrees(arena, env, sriqref_rpred_job(arena, env, st, v, c), ps))) {
                        ok = 0;
                    }
                }
            }
        }
        return ok;
    }
}

uint8_t sriqref_edge_agrees(slop_arena* arena, sriqref_Env env, sriqctx_Structure st, uint32_t v, sriqctx_Edge e, slop_list_types_Clause cs) {
    {
        __auto_type ws = sriqref_premises_of(arena, st.ord, sriqref_set_of(env, st, ((int64_t)(e.from))));
        __auto_type core = sriqref_core_at(env, st, arena, ((int64_t)(v)));
        uint8_t ok = 1;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type view = sriq_pred_view(arena, c, core, 0);
                    if (!(sriqref_pred_agrees(arena, env, sriqref_away_job(view, sriqref_slots_of(arena, view.slots), e.label, e.from), ws))) {
                        ok = 0;
                    }
                }
            }
        }
        return ok;
    }
}

uint8_t sriqref_combinators_agree(slop_arena* arena, sriqref_RefIn in, sriqref_RefConfig cfg, sriqctx_Structure st) {
    {
        __auto_type env = sriqref_env_for(arena, in, cfg);
        uint8_t ok = 1;
        int64_t v = 0;
        while (v < ((int64_t)(((int64_t)((st.ctxs).len))))) {
            if (!(sriqref_ctx_agrees(arena, env, st, ((uint32_t)(v))))) {
                ok = 0;
            }
            v = (v + 1);
        }
        return ok;
    }
}

