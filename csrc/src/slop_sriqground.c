#include "../runtime/slop_runtime.h"
#include "slop_sriqground.h"

uint8_t howl_sriqground_lit_gf(howl_types_Lit l);
uint8_t howl_sriqground_ground_clause(howl_types_Clause c);
slop_list_howl_types_Clause howl_sriqground_set_at(howl_sriqctx_Structure st, int64_t v, slop_list_howl_types_Clause nobody);
uint8_t howl_sriqground_ctx_root(howl_sriqctx_Structure st, int64_t v);
slop_list_howl_types_Clause howl_sriqground_ground_part(slop_arena* arena, slop_list_howl_types_Clause cs);
slop_list_u8 howl_sriqground_fresh_flags(slop_arena* arena, slop_list_howl_types_Clause gs, slop_list_howl_types_Clause news);
howl_types_Clause howl_sriqground_clause_at(slop_list_howl_types_Clause cs, int64_t k, howl_types_Clause fallback);
uint8_t howl_sriqground_sorted_has(slop_list_howl_types_Clause cs, howl_types_Clause c);
int64_t howl_sriqground_post_cmp(howl_sriqground_Post a, howl_sriqground_Post b);
howl_sriqground_Post howl_sriqground_post_at(slop_list_howl_sriqground_Post ps, int64_t k, howl_sriqground_Post fallback);
slop_list_howl_sriqground_Post howl_sriqground_postings(slop_arena* arena, slop_list_howl_types_Clause gs);
int64_t howl_sriqground_post_key_cmp(howl_sriqground_Post p, int64_t side, howl_types_Lit l);
int64_t howl_sriqground_post_lower(slop_list_howl_sriqground_Post ps, int64_t side, howl_types_Lit l, howl_sriqground_Post fallback);
slop_list_int howl_sriqground_subsumed_by(slop_arena* arena, slop_list_howl_types_Clause gs, slop_list_howl_sriqground_Post ps, howl_types_Clause c);
slop_list_int howl_sriqground_subsumed_from(slop_arena* arena, slop_list_howl_types_Clause gs, slop_list_howl_sriqground_Post ps, howl_types_Clause c, howl_sriqground_Post kp, howl_sriqground_Post p0);
slop_option_howl_sriqground_Post howl_sriqground_key_lit(howl_types_Clause c);
uint8_t howl_sriqground_member_subsumed(slop_list_howl_types_Clause gs, int64_t i, howl_types_Clause c);
howl_sriqground_Hides howl_sriqground_hides_of(slop_arena* arena, slop_list_howl_types_Clause gs, slop_list_howl_sriqground_Post ps, slop_list_howl_types_Clause cs);
int64_t howl_sriqground_int_at(slop_list_int xs, int64_t k);
slop_list_int howl_sriqground_int_set(slop_arena* arena, slop_list_int xs);
uint8_t howl_sriqground_int_has(slop_list_int xs, int64_t x);
slop_list_howl_sriqground_Hides howl_sriqground_all_hides(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_types_Clause gs, slop_list_howl_sriqground_Post ps);
slop_list_u8 howl_sriqground_shown_flags(slop_arena* arena, howl_sriqctx_Structure st, int64_t n, slop_list_howl_sriqground_Hides hs);
void howl_sriqground_bump_ids(slop_list_int counts, slop_list_int ids);
void howl_sriqground_bump_all(slop_list_int counts, int64_t n);
howl_sriq_Premise howl_sriqground_prem_at(slop_list_howl_sriq_Premise ps, int64_t k, howl_sriq_Premise fallback);
slop_list_int howl_sriqground_sel_sorted(slop_arena* arena, slop_list_howl_sriq_Premise ps);
howl_types_Clause howl_sriqground_unit_of(slop_arena* arena, howl_types_Lit a);
uint8_t howl_sriqground_held_in(slop_arena* arena, howl_sriqindex_SubIndex ix, howl_types_Lit a);
slop_list_howl_sriq_Premise howl_sriqground_member_premises(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Clause gs);
slop_list_int howl_sriqground_premise_members(slop_arena* arena, slop_list_howl_types_Clause gs);
howl_sriqground_Ground howl_sriqground_ground_of(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqctx_Structure st, slop_list_howl_types_Clause root_news);
howl_sriqground_PIdx howl_sriqground_pidx_of(slop_arena* arena, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriq_Premise howl_sriqground_pidx_find(slop_arena* arena, howl_sriqground_PIdx ix, howl_types_Lit l);
int64_t howl_sriqground_form_rank(howl_types_LitForm f);
int64_t howl_sriqground_key_cmp_lit(howl_types_Lit l, int64_t rank, uint32_t pred);
slop_list_howl_sriq_Premise howl_sriqground_pidx_key_range(slop_arena* arena, howl_sriqground_PIdx ix, int64_t rank, uint32_t pred);
int64_t howl_sriqground_key_lower(howl_sriqground_PIdx ix, int64_t rank, uint32_t pred, howl_sriq_Premise p0);
howl_sriqground_PIdx howl_sriqground_pick_ix(int64_t j, int64_t i, howl_sriqground_PIdx dix, howl_sriqground_PIdx oix, howl_sriqground_PIdx aix);
howl_types_Lit howl_sriqground_idx_sel(howl_sriqground_PIdx ix, int64_t k, howl_sriq_Premise p0);
int64_t howl_sriqground_idx_lower(howl_sriqground_PIdx ix, howl_types_Lit l, howl_sriq_Premise p0);
uint8_t howl_sriqground_g_visible(howl_sriqground_Ground gd, int64_t v, int64_t i);
uint8_t howl_sriqground_g_fresh(howl_sriqground_Ground gd, int64_t i);
uint8_t howl_sriqground_g_in_hat(howl_sriqground_Ground gd, howl_types_Clause c);
uint8_t howl_sriqground_g_held(slop_arena* arena, howl_sriqground_Ground gd, howl_types_Lit a);
howl_sriq_Premise howl_sriqground_g_premise_at(howl_sriqground_Ground gd, int64_t k, howl_sriq_Premise fallback);
int64_t howl_sriqground_g_member_of(howl_sriqground_Ground gd, int64_t k);
slop_list_int howl_sriqground_g_sel_range(slop_arena* arena, howl_sriqground_Ground gd, howl_types_Lit l);
howl_types_Lit howl_sriqground_sel_of(howl_sriqground_Ground gd, int64_t k, howl_sriq_Premise p0);
int64_t howl_sriqground_sel_lower(howl_sriqground_Ground gd, howl_types_Lit l, howl_sriq_Premise p0);
slop_list_int howl_sriqground_g_body_members(slop_arena* arena, howl_sriqground_Ground gd, howl_types_Lit l);
howl_types_Clause howl_sriqground_g_member(howl_sriqground_Ground gd, int64_t i, howl_types_Clause fallback);
uint8_t howl_sriqground_g_shown(howl_sriqground_Ground gd, int64_t i);
slop_list_howl_types_Clause howl_sriqground_g_root_units(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqground_Ground gd);
int64_t howl_sriqground_view_total(howl_sriqctx_Structure st);
uint8_t howl_sriqground_has_empty(slop_list_howl_types_Clause cs);
howl_sriqctx_Structure howl_sriqground_materialise(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqctx_Structure st);
slop_list_howl_types_Clause howl_sriqground_min_with(slop_arena* arena, slop_list_howl_types_Clause ws, slop_list_howl_types_Clause cs);
slop_list_howl_types_Clause howl_sriqground_visible_of(slop_arena* arena, howl_sriqground_Ground gd, int64_t v);
slop_list_howl_sriqctx_Edge howl_sriqground_eg_edges(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqground_Ground gd, int64_t v);
slop_list_u32 howl_sriqground_consts_in(slop_arena* arena, howl_types_Lit l);
uint8_t howl_sriqground_edge_in(slop_list_howl_sriqctx_Edge es, howl_sriqctx_Edge e);

typedef struct { slop_list_howl_sriqground_Post* raw; howl_sriqground_Post p0; } howl_sriqground__lambda_551_env_t;

static int64_t howl_sriqground__lambda_551(howl_sriqground__lambda_551_env_t* _env, int64_t a, int64_t b) { return howl_sriqground_post_cmp(howl_sriqground_post_at((*_env->raw), a, _env->p0), howl_sriqground_post_at((*_env->raw), b, _env->p0)); }

typedef struct { slop_list_int xs; } howl_sriqground__lambda_558_env_t;

static int64_t howl_sriqground__lambda_558(howl_sriqground__lambda_558_env_t* _env, int64_t a, int64_t b) { return ((howl_sriqground_int_at(_env->xs, a) < howl_sriqground_int_at(_env->xs, b)) ? -1 : ((howl_sriqground_int_at(_env->xs, a) > howl_sriqground_int_at(_env->xs, b)) ? 1 : 0)); }

typedef struct { slop_list_howl_sriq_Premise ps; howl_sriq_Premise p0; } howl_sriqground__lambda_561_env_t;

static int64_t howl_sriqground__lambda_561(howl_sriqground__lambda_561_env_t* _env, int64_t a, int64_t b) { return howl_types_lit_cmp(howl_sriqground_prem_at(_env->ps, a, _env->p0).sel, howl_sriqground_prem_at(_env->ps, b, _env->p0).sel); }

uint8_t howl_sriqground_lit_gf(howl_types_Lit l) {
    return (howl_sriqctx_lit_ground(l) && !(howl_sriq_has_fterm(l)));
}

uint8_t howl_sriqground_ground_clause(howl_types_Clause c) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(howl_sriqground_lit_gf(l))) {
                    ok = 0;
                }
            }
        }
        {
            __auto_type _coll = c.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(howl_sriqground_lit_gf(l))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

slop_list_howl_types_Clause howl_sriqground_set_at(howl_sriqctx_Structure st, int64_t v, slop_list_howl_types_Clause nobody) {
    __auto_type _mv_546 = ({ __auto_type _lst = st.sets; size_t _idx = (size_t)v; slop_option_howl_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_546.has_value) {
        __auto_type s = _mv_546.value;
        return s.cs;
    } else if (!_mv_546.has_value) {
        return nobody;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqground_ctx_root(howl_sriqctx_Structure st, int64_t v) {
    __auto_type _mv_547 = ({ __auto_type _lst = st.ctxs; size_t _idx = (size_t)v; slop_option_howl_sriqctx_Ctx _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_547.has_value) {
        __auto_type c = _mv_547.value;
        return c.root;
    } else if (!_mv_547.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Clause howl_sriqground_ground_part(slop_arena* arena, slop_list_howl_types_Clause cs) {
    {
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (howl_sriqground_ground_clause(c)) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

slop_list_u8 howl_sriqground_fresh_flags(slop_arena* arena, slop_list_howl_types_Clause gs, slop_list_howl_types_Clause news) {
    {
        __auto_type out = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = gs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type g = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqground_sorted_has(news, g)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_types_Clause howl_sriqground_clause_at(slop_list_howl_types_Clause cs, int64_t k, howl_types_Clause fallback) {
    __auto_type _mv_548 = ({ __auto_type _lst = cs; size_t _idx = (size_t)k; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_548.has_value) {
        __auto_type c = _mv_548.value;
        return c;
    } else if (!_mv_548.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqground_sorted_has(slop_list_howl_types_Clause cs, howl_types_Clause c) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((cs).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                if (howl_sriqclauses_clause_cmp(howl_sriqground_clause_at(cs, mid, c), c) < 0) {
                    lo = (mid + 1);
                } else {
                    hi = mid;
                }
            }
        }
        return ((lo < ((int64_t)(((int64_t)((cs).len))))) && (howl_sriqclauses_clause_cmp(howl_sriqground_clause_at(cs, lo, c), c) == 0));
    }
}

int64_t howl_sriqground_post_cmp(howl_sriqground_Post a, howl_sriqground_Post b) {
    if (a.side < b.side) {
        return -1;
    } else if (a.side > b.side) {
        return 1;
    } else {
        return howl_types_lit_cmp(a.lit, b.lit);
    }
}

howl_sriqground_Post howl_sriqground_post_at(slop_list_howl_sriqground_Post ps, int64_t k, howl_sriqground_Post fallback) {
    __auto_type _mv_549 = ({ __auto_type _lst = ps; size_t _idx = (size_t)k; slop_option_howl_sriqground_Post _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_549.has_value) {
        __auto_type p = _mv_549.value;
        return p;
    } else if (!_mv_549.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_sriqground_Post howl_sriqground_postings(slop_arena* arena, slop_list_howl_types_Clause gs) {
    {
        __auto_type raw = ((slop_list_howl_sriqground_Post){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = gs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type g = _coll.data[_i];
                {
                    __auto_type _coll = g.body;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type l = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(raw); __auto_type _item = (((howl_sriqground_Post){.side = 0, .lit = l, .i = i})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
                {
                    __auto_type _coll = g.head;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type l = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(raw); __auto_type _item = (((howl_sriqground_Post){.side = 1, .lit = l, .i = i})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
                i = (i + 1);
            }
        }
        __auto_type _mv_550 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_howl_sriqground_Post _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_550.has_value) {
            return raw;
        } else if (_mv_550.has_value) {
            __auto_type p0 = _mv_550.value;
            {
                __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ howl_sriqground__lambda_551_env_t* howl_sriqground__lambda_551_env = (howl_sriqground__lambda_551_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqground__lambda_551_env_t)); *howl_sriqground__lambda_551_env = (howl_sriqground__lambda_551_env_t){ .raw = &(raw), .p0 = p0 }; (slop_closure_t){ (void*)howl_sriqground__lambda_551, (void*)howl_sriqground__lambda_551_env }; }));
                __auto_type out = ((slop_list_howl_sriqground_Post){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                {
                    __auto_type _coll = idx;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type k = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqground_post_at(raw, k, p0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                return out;
            }
        }
        SLOP_UNREACHABLE();
    }
}

int64_t howl_sriqground_post_key_cmp(howl_sriqground_Post p, int64_t side, howl_types_Lit l) {
    if (p.side < side) {
        return -1;
    } else if (p.side > side) {
        return 1;
    } else {
        return howl_types_lit_cmp(p.lit, l);
    }
}

int64_t howl_sriqground_post_lower(slop_list_howl_sriqground_Post ps, int64_t side, howl_types_Lit l, howl_sriqground_Post fallback) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((ps).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                if (howl_sriqground_post_key_cmp(howl_sriqground_post_at(ps, mid, fallback), side, l) < 0) {
                    lo = (mid + 1);
                } else {
                    hi = mid;
                }
            }
        }
        return lo;
    }
}

slop_list_int howl_sriqground_subsumed_by(slop_arena* arena, slop_list_howl_types_Clause gs, slop_list_howl_sriqground_Post ps, howl_types_Clause c) {
    __auto_type _mv_552 = howl_sriqground_key_lit(c);
    if (!_mv_552.has_value) {
        return ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    } else if (_mv_552.has_value) {
        __auto_type kp = _mv_552.value;
        __auto_type _mv_553 = ({ __auto_type _lst = ps; size_t _idx = (size_t)0; slop_option_howl_sriqground_Post _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_553.has_value) {
            return ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        } else if (_mv_553.has_value) {
            __auto_type p0 = _mv_553.value;
            return howl_sriqground_subsumed_from(arena, gs, ps, c, kp, p0);
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_list_int howl_sriqground_subsumed_from(slop_arena* arena, slop_list_howl_types_Clause gs, slop_list_howl_sriqground_Post ps, howl_types_Clause c, howl_sriqground_Post kp, howl_sriqground_Post p0) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = howl_sriqground_post_lower(ps, kp.side, kp.lit, p0);
        uint8_t going = 1;
        while (going && (k < ((int64_t)(((int64_t)((ps).len)))))) {
            {
                __auto_type p = howl_sriqground_post_at(ps, k, p0);
                going = (howl_sriqground_post_key_cmp(p, kp.side, kp.lit) == 0);
                if (going && howl_sriqground_member_subsumed(gs, p.i, c)) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (p.i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                k = (k + 1);
            }
        }
        return out;
    }
}

slop_option_howl_sriqground_Post howl_sriqground_key_lit(howl_types_Clause c) {
    __auto_type _mv_554 = ({ __auto_type _lst = c.body; size_t _idx = (size_t)0; slop_option_howl_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_554.has_value) {
        __auto_type l = _mv_554.value;
        return (slop_option_howl_sriqground_Post){.has_value = 1, .value = ((howl_sriqground_Post){.side = 0, .lit = l, .i = 0})};
    } else if (!_mv_554.has_value) {
        __auto_type _mv_555 = ({ __auto_type _lst = c.head; size_t _idx = (size_t)0; slop_option_howl_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_555.has_value) {
            __auto_type l = _mv_555.value;
            return (slop_option_howl_sriqground_Post){.has_value = 1, .value = ((howl_sriqground_Post){.side = 1, .lit = l, .i = 0})};
        } else if (!_mv_555.has_value) {
            return (slop_option_howl_sriqground_Post){.has_value = false};
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqground_member_subsumed(slop_list_howl_types_Clause gs, int64_t i, howl_types_Clause c) {
    __auto_type _mv_556 = ({ __auto_type _lst = gs; size_t _idx = (size_t)i; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_556.has_value) {
        __auto_type g = _mv_556.value;
        return howl_sriqsubsume_subsumes(c, g);
    } else if (!_mv_556.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

howl_sriqground_Hides howl_sriqground_hides_of(slop_arena* arena, slop_list_howl_types_Clause gs, slop_list_howl_sriqground_Post ps, slop_list_howl_types_Clause cs) {
    {
        uint8_t all = 0;
        __auto_type raw = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (howl_sriqground_ground_clause(c)) {
                    if ((((int64_t)((c.body).len)) == 0) && (((int64_t)((c.head).len)) == 0)) {
                        all = 1;
                    } else {
                        {
                            __auto_type _coll = howl_sriqground_subsumed_by(arena, gs, ps, c);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type i = _coll.data[_i];
                                (void)(({ __auto_type _lst_p = &(raw); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                        }
                    }
                }
            }
        }
        return ((howl_sriqground_Hides){.all = all, .ids = howl_sriqground_int_set(arena, raw)});
    }
}

int64_t howl_sriqground_int_at(slop_list_int xs, int64_t k) {
    __auto_type _mv_557 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_557.has_value) {
        __auto_type x = _mv_557.value;
        return x;
    } else if (!_mv_557.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

slop_list_int howl_sriqground_int_set(slop_arena* arena, slop_list_int xs) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ howl_sriqground__lambda_558_env_t* howl_sriqground__lambda_558_env = (howl_sriqground__lambda_558_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqground__lambda_558_env_t)); *howl_sriqground__lambda_558_env = (howl_sriqground__lambda_558_env_t){ .xs = xs }; (slop_closure_t){ (void*)howl_sriqground__lambda_558, (void*)howl_sriqground__lambda_558_env }; }));
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t last = -1;
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type x = howl_sriqground_int_at(xs, k);
                    if (x != last) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        last = x;
                    }
                }
            }
        }
        return out;
    }
}

uint8_t howl_sriqground_int_has(slop_list_int xs, int64_t x) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((xs).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                if (howl_sriqground_int_at(xs, mid) < x) {
                    lo = (mid + 1);
                } else {
                    hi = mid;
                }
            }
        }
        return (howl_sriqground_int_at(xs, lo) == x);
    }
}

slop_list_howl_sriqground_Hides howl_sriqground_all_hides(slop_arena* arena, howl_sriqctx_Structure st, slop_list_howl_types_Clause gs, slop_list_howl_sriqground_Post ps) {
    {
        __auto_type out = ((slop_list_howl_sriqground_Hides){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        __auto_type nobody = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                if (howl_sriqground_ctx_root(st, v)) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqground_Hides){.all = 0, .ids = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                } else {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqground_hides_of(arena, gs, ps, s.cs)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                v = (v + 1);
            }
        }
        return out;
    }
}

slop_list_u8 howl_sriqground_shown_flags(slop_arena* arena, howl_sriqctx_Structure st, int64_t n, slop_list_howl_sriqground_Hides hs) {
    {
        __auto_type counts = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t others = 0;
        int64_t v = 0;
        int64_t i = 0;
        __auto_type out = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        while (i < n) {
            (void)(({ __auto_type _lst_p = &(counts); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            i = (i + 1);
        }
        {
            __auto_type _coll = hs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type h = _coll.data[_i];
                if (!(howl_sriqground_ctx_root(st, v))) {
                    others = (others + 1);
                    if (h.all) {
                        howl_sriqground_bump_all(counts, n);
                    } else {
                        howl_sriqground_bump_ids(counts, h.ids);
                    }
                }
                v = (v + 1);
            }
        }
        i = 0;
        while (i < n) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = ((howl_sriqground_int_at(counts, i) < others)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            i = (i + 1);
        }
        return out;
    }
}

void howl_sriqground_bump_ids(slop_list_int counts, slop_list_int ids) {
    {
        __auto_type _coll = ids;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type k = _coll.data[_i];
            (void)(({ __auto_type _set_lst = &(counts); size_t _set_idx = (size_t)(k); __auto_type _set_val = ((howl_sriqground_int_at(counts, k) + 1)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
        }
    }
}

void howl_sriqground_bump_all(slop_list_int counts, int64_t n) {
    {
        int64_t i = 0;
        while (i < n) {
            (void)(({ __auto_type _set_lst = &(counts); size_t _set_idx = (size_t)(i); __auto_type _set_val = ((howl_sriqground_int_at(counts, i) + 1)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
            i = (i + 1);
        }
    }
}

howl_sriq_Premise howl_sriqground_prem_at(slop_list_howl_sriq_Premise ps, int64_t k, howl_sriq_Premise fallback) {
    __auto_type _mv_559 = ({ __auto_type _lst = ps; size_t _idx = (size_t)k; slop_option_howl_sriq_Premise _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_559.has_value) {
        __auto_type p = _mv_559.value;
        return p;
    } else if (!_mv_559.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_list_int howl_sriqground_sel_sorted(slop_arena* arena, slop_list_howl_sriq_Premise ps) {
    __auto_type _mv_560 = ({ __auto_type _lst = ps; size_t _idx = (size_t)0; slop_option_howl_sriq_Premise _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_560.has_value) {
        return ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    } else if (_mv_560.has_value) {
        __auto_type p0 = _mv_560.value;
        return howl_canon_sort_range(arena, ((int64_t)(((int64_t)((ps).len)))), ({ howl_sriqground__lambda_561_env_t* howl_sriqground__lambda_561_env = (howl_sriqground__lambda_561_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqground__lambda_561_env_t)); *howl_sriqground__lambda_561_env = (howl_sriqground__lambda_561_env_t){ .ps = ps, .p0 = p0 }; (slop_closure_t){ (void*)howl_sriqground__lambda_561, (void*)howl_sriqground__lambda_561_env }; }));
    }
    SLOP_UNREACHABLE();
}

howl_types_Clause howl_sriqground_unit_of(slop_arena* arena, howl_types_Lit a) {
    {
        __auto_type b = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type h = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(b); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(h); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return howl_sriqclauses_make_clause(arena, b, h);
    }
}

uint8_t howl_sriqground_held_in(slop_arena* arena, howl_sriqindex_SubIndex ix, howl_types_Lit a) {
    return howl_sriqindex_some_subsumes(ix, howl_sriqground_unit_of(arena, a), -1);
}

slop_list_howl_sriq_Premise howl_sriqground_member_premises(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Clause gs) {
    {
        __auto_type out = ((slop_list_howl_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = gs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type g = _coll.data[_i];
                {
                    int64_t i = 0;
                    while (i < ((int64_t)(((int64_t)((g.head).len))))) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriq_select(arena, ord, g, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        i = (i + 1);
                    }
                }
            }
        }
        return out;
    }
}

slop_list_int howl_sriqground_premise_members(slop_arena* arena, slop_list_howl_types_Clause gs) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = gs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type g = _coll.data[_i];
                {
                    __auto_type _coll = g.head;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type l = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (k); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
                k = (k + 1);
            }
        }
        return out;
    }
}

howl_sriqground_Ground howl_sriqground_ground_of(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqctx_Structure st, slop_list_howl_types_Clause root_news) {
    {
        __auto_type nobody = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type gs = howl_sriqground_ground_part(arena, howl_sriqground_set_at(st, 0, nobody));
        __auto_type ix = howl_sriqindex_sub_index(arena, gs);
        __auto_type posts = howl_sriqground_postings(arena, gs);
        __auto_type hides = howl_sriqground_all_hides(arena, st, gs, posts);
        __auto_type ps = howl_sriqground_member_premises(arena, st.ord, gs);
        __auto_type pm = howl_sriqground_premise_members(arena, gs);
        return ((howl_sriqground_Ground){.gs = gs, .fresh = howl_sriqground_fresh_flags(arena, gs, root_news), .ix = ix, .posts = posts, .hides = hides, .shown = howl_sriqground_shown_flags(arena, st, ((int64_t)(((int64_t)((gs).len)))), hides), .ps = ps, .pm = pm, .bysel = howl_sriqground_sel_sorted(arena, ps)});
    }
}

howl_sriqground_PIdx howl_sriqground_pidx_of(slop_arena* arena, slop_list_howl_sriq_Premise ps) {
    return ((howl_sriqground_PIdx){.ps = ps, .bysel = howl_sriqground_sel_sorted(arena, ps)});
}

slop_list_howl_sriq_Premise howl_sriqground_pidx_find(slop_arena* arena, howl_sriqground_PIdx ix, howl_types_Lit l) {
    {
        __auto_type out = ((slop_list_howl_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_562 = ({ __auto_type _lst = ix.ps; size_t _idx = (size_t)0; slop_option_howl_sriq_Premise _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_562.has_value) {
            return out;
        } else if (_mv_562.has_value) {
            __auto_type p0 = _mv_562.value;
            {
                __auto_type bs = ix.bysel;
                int64_t k = howl_sriqground_idx_lower(ix, l, p0);
                while ((k < ((int64_t)(((int64_t)((bs).len))))) && (howl_types_lit_cmp(howl_sriqground_idx_sel(ix, howl_sriqground_int_at(bs, k), p0), l) == 0)) {
                    if (howl_sriqground_prem_at(ix.ps, howl_sriqground_int_at(bs, k), p0).maxed) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqground_prem_at(ix.ps, howl_sriqground_int_at(bs, k), p0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                    k = (k + 1);
                }
                return out;
            }
        }
        SLOP_UNREACHABLE();
    }
}

int64_t howl_sriqground_form_rank(howl_types_LitForm f) {
    __auto_type _mv_563 = f;
    if (_mv_563 == howl_types_LitForm_lf_unary) {
        return 0;
    } else if (_mv_563 == howl_types_LitForm_lf_binary) {
        return 1;
    } else if (_mv_563 == howl_types_LitForm_lf_eq) {
        return 2;
    } else if (_mv_563 == howl_types_LitForm_lf_neq) {
        return 3;
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqground_key_cmp_lit(howl_types_Lit l, int64_t rank, uint32_t pred) {
    {
        __auto_type r = howl_sriqground_form_rank(l.form);
        if (r < rank) {
            return -1;
        } else if (r > rank) {
            return 1;
        } else if (l.pred < pred) {
            return -1;
        } else if (l.pred > pred) {
            return 1;
        } else {
            return 0;
        }
    }
}

slop_list_howl_sriq_Premise howl_sriqground_pidx_key_range(slop_arena* arena, howl_sriqground_PIdx ix, int64_t rank, uint32_t pred) {
    {
        __auto_type out = ((slop_list_howl_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_564 = ({ __auto_type _lst = ix.ps; size_t _idx = (size_t)0; slop_option_howl_sriq_Premise _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_564.has_value) {
            return out;
        } else if (_mv_564.has_value) {
            __auto_type p0 = _mv_564.value;
            {
                __auto_type bs = ix.bysel;
                int64_t k = howl_sriqground_key_lower(ix, rank, pred, p0);
                while ((k < ((int64_t)(((int64_t)((bs).len))))) && (howl_sriqground_key_cmp_lit(howl_sriqground_idx_sel(ix, howl_sriqground_int_at(bs, k), p0), rank, pred) == 0)) {
                    if (howl_sriqground_prem_at(ix.ps, howl_sriqground_int_at(bs, k), p0).maxed) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqground_prem_at(ix.ps, howl_sriqground_int_at(bs, k), p0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                    k = (k + 1);
                }
                return out;
            }
        }
        SLOP_UNREACHABLE();
    }
}

int64_t howl_sriqground_key_lower(howl_sriqground_PIdx ix, int64_t rank, uint32_t pred, howl_sriq_Premise p0) {
    {
        __auto_type bs = ix.bysel;
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((ix.bysel).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                if (howl_sriqground_key_cmp_lit(howl_sriqground_idx_sel(ix, howl_sriqground_int_at(bs, mid), p0), rank, pred) < 0) {
                    lo = (mid + 1);
                } else {
                    hi = mid;
                }
            }
        }
        return lo;
    }
}

howl_sriqground_PIdx howl_sriqground_pick_ix(int64_t j, int64_t i, howl_sriqground_PIdx dix, howl_sriqground_PIdx oix, howl_sriqground_PIdx aix) {
    if (j < i) {
        return oix;
    } else if (j == i) {
        return dix;
    } else {
        return aix;
    }
}

howl_types_Lit howl_sriqground_idx_sel(howl_sriqground_PIdx ix, int64_t k, howl_sriq_Premise p0) {
    return howl_sriqground_prem_at(ix.ps, k, p0).sel;
}

int64_t howl_sriqground_idx_lower(howl_sriqground_PIdx ix, howl_types_Lit l, howl_sriq_Premise p0) {
    {
        __auto_type bs = ix.bysel;
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((ix.bysel).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                if (howl_types_lit_cmp(howl_sriqground_idx_sel(ix, howl_sriqground_int_at(bs, mid), p0), l) < 0) {
                    lo = (mid + 1);
                } else {
                    hi = mid;
                }
            }
        }
        return lo;
    }
}

uint8_t howl_sriqground_g_visible(howl_sriqground_Ground gd, int64_t v, int64_t i) {
    __auto_type _mv_565 = ({ __auto_type _lst = gd.hides; size_t _idx = (size_t)v; slop_option_howl_sriqground_Hides _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_565.has_value) {
        __auto_type h = _mv_565.value;
        return (!(h.all) && !(howl_sriqground_int_has(h.ids, i)));
    } else if (!_mv_565.has_value) {
        return 1;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqground_g_fresh(howl_sriqground_Ground gd, int64_t i) {
    __auto_type _mv_566 = ({ __auto_type _lst = gd.fresh; size_t _idx = (size_t)i; slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_566.has_value) {
        __auto_type b = _mv_566.value;
        return b;
    } else if (!_mv_566.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqground_g_in_hat(howl_sriqground_Ground gd, howl_types_Clause c) {
    return howl_sriqindex_some_subsumes(gd.ix, c, -1);
}

uint8_t howl_sriqground_g_held(slop_arena* arena, howl_sriqground_Ground gd, howl_types_Lit a) {
    return howl_sriqground_held_in(arena, gd.ix, a);
}

howl_sriq_Premise howl_sriqground_g_premise_at(howl_sriqground_Ground gd, int64_t k, howl_sriq_Premise fallback) {
    return howl_sriqground_prem_at(gd.ps, k, fallback);
}

int64_t howl_sriqground_g_member_of(howl_sriqground_Ground gd, int64_t k) {
    return howl_sriqground_int_at(gd.pm, k);
}

slop_list_int howl_sriqground_g_sel_range(slop_arena* arena, howl_sriqground_Ground gd, howl_types_Lit l) {
    __auto_type _mv_567 = ({ __auto_type _lst = gd.ps; size_t _idx = (size_t)0; slop_option_howl_sriq_Premise _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_567.has_value) {
        return ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    } else if (_mv_567.has_value) {
        __auto_type p0 = _mv_567.value;
        {
            __auto_type bs = gd.bysel;
            __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            int64_t k = howl_sriqground_sel_lower(gd, l, p0);
            while ((k < ((int64_t)(((int64_t)((bs).len))))) && (howl_types_lit_cmp(howl_sriqground_sel_of(gd, howl_sriqground_int_at(bs, k), p0), l) == 0)) {
                ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqground_int_at(bs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                k = (k + 1);
            }
            return out;
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_Lit howl_sriqground_sel_of(howl_sriqground_Ground gd, int64_t k, howl_sriq_Premise p0) {
    return howl_sriqground_prem_at(gd.ps, k, p0).sel;
}

int64_t howl_sriqground_sel_lower(howl_sriqground_Ground gd, howl_types_Lit l, howl_sriq_Premise p0) {
    {
        __auto_type bs = gd.bysel;
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((gd.bysel).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                if (howl_types_lit_cmp(howl_sriqground_sel_of(gd, howl_sriqground_int_at(bs, mid), p0), l) < 0) {
                    lo = (mid + 1);
                } else {
                    hi = mid;
                }
            }
        }
        return lo;
    }
}

slop_list_int howl_sriqground_g_body_members(slop_arena* arena, howl_sriqground_Ground gd, howl_types_Lit l) {
    {
        __auto_type ps = gd.posts;
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_568 = ({ __auto_type _lst = ps; size_t _idx = (size_t)0; slop_option_howl_sriqground_Post _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_568.has_value) {
            return out;
        } else if (_mv_568.has_value) {
            __auto_type p0 = _mv_568.value;
            {
                int64_t k = howl_sriqground_post_lower(ps, 0, l, p0);
                while ((k < ((int64_t)(((int64_t)((ps).len))))) && (howl_sriqground_post_key_cmp(howl_sriqground_post_at(ps, k, p0), 0, l) == 0)) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqground_post_at(ps, k, p0).i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    k = (k + 1);
                }
                return out;
            }
        }
        SLOP_UNREACHABLE();
    }
}

howl_types_Clause howl_sriqground_g_member(howl_sriqground_Ground gd, int64_t i, howl_types_Clause fallback) {
    __auto_type _mv_569 = ({ __auto_type _lst = gd.gs; size_t _idx = (size_t)i; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_569.has_value) {
        __auto_type g = _mv_569.value;
        return g;
    } else if (!_mv_569.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqground_g_shown(howl_sriqground_Ground gd, int64_t i) {
    __auto_type _mv_570 = ({ __auto_type _lst = gd.shown; size_t _idx = (size_t)i; slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_570.has_value) {
        __auto_type b = _mv_570.value;
        return b;
    } else if (!_mv_570.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Clause howl_sriqground_g_root_units(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqground_Ground gd) {
    {
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = gd.ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if ((p.maxed) && (howl_sriqground_g_shown(gd, howl_sriqground_g_member_of(gd, k))) && (howl_sriqctx_in_sur(tr, p.sel)) && (!(howl_sriqground_g_held(arena, gd, p.sel)))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqground_unit_of(arena, p.sel)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                k = (k + 1);
            }
        }
        return out;
    }
}

int64_t howl_sriqground_view_total(howl_sriqctx_Structure st) {
    {
        int64_t g = 0;
        int64_t n = 0;
        int64_t v = 0;
        __auto_type _mv_571 = ({ __auto_type _lst = st.sets; size_t _idx = (size_t)0; slop_option_howl_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_571.has_value) {
            __auto_type r = _mv_571.value;
            {
                __auto_type _coll = r.cs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    if (howl_sriqground_ground_clause(c)) {
                        g = (g + 1);
                    }
                }
            }
        } else if (!_mv_571.has_value) {
            g = 0;
        }
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                n = (n + ((int64_t)(((int64_t)((s.cs).len)))));
                if (!(howl_sriqground_ctx_root(st, v)) && !(howl_sriqground_has_empty(s.cs))) {
                    n = (n + g);
                }
                v = (v + 1);
            }
        }
        return n;
    }
}

uint8_t howl_sriqground_has_empty(slop_list_howl_types_Clause cs) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if ((((int64_t)((c.body).len)) == 0) && (((int64_t)((c.head).len)) == 0)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

howl_sriqctx_Structure howl_sriqground_materialise(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqctx_Structure st) {
    {
        __auto_type gd = howl_sriqground_ground_of(arena, tr, st, ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        __auto_type sets = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type es = ((slop_list_howl_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t v = 0;
        {
            __auto_type _coll = st.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(es); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = st.sets;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                if (howl_sriqground_ctx_root(st, v)) {
                    (void)(({ __auto_type _lst_p = &(sets); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                } else {
                    (void)(({ __auto_type _lst_p = &(sets); __auto_type _item = (((howl_sriqctx_CtxSet){.cs = howl_sriqground_min_with(arena, s.cs, howl_sriqground_visible_of(arena, gd, v))})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    {
                        __auto_type _coll = howl_sriqground_eg_edges(arena, tr, gd, v);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type e = _coll.data[_i];
                            if (!(howl_sriqground_edge_in(es, e))) {
                                (void)(({ __auto_type _lst_p = &(es); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                        }
                    }
                }
                v = (v + 1);
            }
        }
        return ((howl_sriqctx_Structure){.ctxs = st.ctxs, .sets = sets, .edges = es, .ord = st.ord});
    }
}

slop_list_howl_types_Clause howl_sriqground_min_with(slop_arena* arena, slop_list_howl_types_Clause ws, slop_list_howl_types_Clause cs) {
    if (((int64_t)((cs).len)) == 0) {
        return ws;
    } else {
        return howl_sriqindex_commit_indexed(arena, ws, cs).set;
    }
}

slop_list_howl_types_Clause howl_sriqground_visible_of(slop_arena* arena, howl_sriqground_Ground gd, int64_t v) {
    {
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = gd.gs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type g = _coll.data[_i];
                if (howl_sriqground_g_visible(gd, v, i)) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                i = (i + 1);
            }
        }
        return out;
    }
}

slop_list_howl_sriqctx_Edge howl_sriqground_eg_edges(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqground_Ground gd, int64_t v) {
    {
        __auto_type out = ((slop_list_howl_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = gd.ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if ((p.maxed) && (howl_sriqground_g_visible(gd, v, howl_sriqground_g_member_of(gd, k))) && (howl_sriqctx_in_sur(tr, p.sel))) {
                    {
                        __auto_type _coll = howl_sriqground_consts_in(arena, p.sel);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type u = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqctx_Edge){.from = ((uint32_t)(v)), .to = ((uint32_t)(0)), .lk = howl_sriqctx_EdgeLabel_el_const, .label = u})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
                k = (k + 1);
            }
        }
        return out;
    }
}

slop_list_u32 howl_sriqground_consts_in(slop_arena* arena, howl_types_Lit l) {
    {
        __auto_type out = ((slop_list_u32){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (l.t1.kind == howl_types_AKind_ak_u) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (l.t1.cst); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        if (!((l.form == howl_types_LitForm_lf_unary)) && (l.t2.kind == howl_types_AKind_ak_u)) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (l.t2.cst); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        return out;
    }
}

uint8_t howl_sriqground_edge_in(slop_list_howl_sriqctx_Edge es, howl_sriqctx_Edge e) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = es;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (((x.from == e.from)) && ((x.to == e.to)) && ((x.lk == e.lk)) && ((x.label == e.label))) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

