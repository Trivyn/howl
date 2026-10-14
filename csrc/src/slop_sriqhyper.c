#include "../runtime/slop_runtime.h"
#include "slop_sriqhyper.h"

sriqhyper_OKey sriqhyper_okey_at(slop_list_sriqhyper_OKey ks, int64_t k, sriqhyper_OKey fallback);
int64_t sriqhyper_okey_cmp(sriqhyper_OKey a, sriqhyper_OKey b);
sriqhyper_HIdx sriqhyper_h_index(slop_arena* arena, slop_list_types_Clause onto);
int64_t sriqhyper_widest(slop_list_types_Clause onto);
slop_list_sriqref_Dl4 sriqhyper_dl4s_of(slop_arena* arena, slop_list_types_Clause onto);
slop_list_sriqhyper_OKey sriqhyper_okeys_of(slop_arena* arena, types_Clause oc, int64_t n);
slop_list_sriqhyper_OKey sriqhyper_okeys_sorted(slop_arena* arena, slop_list_sriqhyper_OKey raw);
int64_t sriqhyper_okey_lower(slop_list_sriqhyper_OKey ks, sriqhyper_OKey key, sriqhyper_OKey fallback);
int64_t sriqhyper_pair_code(sriqhyper_HIdx hx, sriqhyper_OKey k);
slop_list_int sriqhyper_hyper_pairs(slop_arena* arena, sriqhyper_HIdx hx, slop_list_sriq_Premise ps);
slop_list_int sriqhyper_pairs_of(slop_arena* arena, sriqhyper_HIdx hx, slop_list_sriq_Premise ps, sriqhyper_OKey k0);
slop_list_int sriqhyper_pairs_under(slop_arena* arena, sriqhyper_HIdx hx, int64_t rank, uint32_t pred, sriqhyper_OKey k0);
slop_list_int sriqhyper_codes_set(slop_arena* arena, slop_list_int xs);
int64_t sriqhyper_code_at(slop_list_int xs, int64_t k);
slop_list_sriq_Premise sriqhyper_slot_ix_cands(slop_arena* arena, uint8_t root, types_Lit a, sriqground_PIdx ix);
sriqhyper_HOut sriqhyper_hyper_anchor(slop_arena* arena, sriqref_Env env, sriqhyper_HCtx hc, sriq_HState start, types_Clause oc, int64_t i);
slop_list_sriq_Premise sriqhyper_slot_at(slop_arena* arena, sriqhyper_HCtx hc, types_Clause oc, int64_t i, int64_t j);
sriqhyper_HOut sriqhyper_hyper_product(slop_arena* arena, sriqref_Env env, sriqhyper_HCtx hc, sriq_HState start, types_Clause oc, slop_list_list_sriq_Premise cs);
slop_option_u32 sriqhyper_x_const(types_Lit a, sriq_Premise p);
sriqhyper_CPrem sriqhyper_cprem_at(slop_list_sriqhyper_CPrem xs, int64_t k, sriqhyper_CPrem fallback);
slop_list_sriqhyper_CPrem sriqhyper_by_const(slop_arena* arena, types_Lit a, slop_list_sriq_Premise ps);
slop_list_sriqhyper_CPrem sriqhyper_cprems_sorted(slop_arena* arena, slop_list_sriqhyper_CPrem raw, sriqhyper_CPrem c0);
slop_list_sriq_Premise sriqhyper_with_const(slop_arena* arena, slop_list_sriqhyper_CPrem xs, uint32_t u);
sriqhyper_HOut sriqhyper_hyper_root_groups(slop_arena* arena, sriqref_Env env, sriqhyper_HCtx hc, sriq_HState start, types_Clause oc, slop_list_list_sriq_Premise cs);
sriqhyper_HOut sriqhyper_root_by_const(slop_arena* arena, sriqref_Env env, sriqhyper_HCtx hc, sriq_HState start, types_Clause oc, slop_list_sriqhyper_Group groups, slop_list_sriqhyper_CPrem g0);
slop_list_list_sriq_Premise sriqhyper_slots_for(slop_arena* arena, slop_list_sriqhyper_Group groups, uint32_t u);
sriqhyper_HOut sriqhyper_hyper_indexed(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, sriqhyper_HCtx hc, int64_t room);
sriqhyper_HOut sriqhyper_hyper_code(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, sriqhyper_HCtx hc, sriq_HState start, int64_t code);

typedef struct { slop_list_sriqhyper_OKey raw; sriqhyper_OKey k0; } sriqhyper__lambda_739_env_t;

static int64_t sriqhyper__lambda_739(sriqhyper__lambda_739_env_t* _env, int64_t a, int64_t b) { return sriqhyper_okey_cmp(sriqhyper_okey_at(_env->raw, a, _env->k0), sriqhyper_okey_at(_env->raw, b, _env->k0)); }

typedef struct { slop_list_int xs; } sriqhyper__lambda_741_env_t;

static int64_t sriqhyper__lambda_741(sriqhyper__lambda_741_env_t* _env, int64_t a, int64_t b) { return ((sriqhyper_code_at(_env->xs, a) < sriqhyper_code_at(_env->xs, b)) ? -1 : ((sriqhyper_code_at(_env->xs, a) > sriqhyper_code_at(_env->xs, b)) ? 1 : 0)); }

typedef struct { slop_list_sriqhyper_CPrem raw; sriqhyper_CPrem c0; } sriqhyper__lambda_748_env_t;

static int64_t sriqhyper__lambda_748(sriqhyper__lambda_748_env_t* _env, int64_t i, int64_t j) { return ((sriqhyper_cprem_at(_env->raw, i, _env->c0).u < sriqhyper_cprem_at(_env->raw, j, _env->c0).u) ? -1 : ((sriqhyper_cprem_at(_env->raw, i, _env->c0).u > sriqhyper_cprem_at(_env->raw, j, _env->c0).u) ? 1 : 0)); }

sriqhyper_OKey sriqhyper_okey_at(slop_list_sriqhyper_OKey ks, int64_t k, sriqhyper_OKey fallback) {
    __auto_type _mv_737 = ({ __auto_type _lst = ks; size_t _idx = (size_t)k; slop_option_sriqhyper_OKey _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_737.has_value) {
        __auto_type x = _mv_737.value;
        return x;
    } else if (!_mv_737.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

int64_t sriqhyper_okey_cmp(sriqhyper_OKey a, sriqhyper_OKey b) {
    if (a.rank < b.rank) {
        return -1;
    } else if (a.rank > b.rank) {
        return 1;
    } else if (a.pred < b.pred) {
        return -1;
    } else if (a.pred > b.pred) {
        return 1;
    } else {
        return 0;
    }
}

sriqhyper_HIdx sriqhyper_h_index(slop_arena* arena, slop_list_types_Clause onto) {
    {
        __auto_type bodied = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type bodiless = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type raw = ((slop_list_sriqhyper_OKey){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = onto;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type oc = _coll.data[_i];
                if (((int64_t)((oc.body).len)) == 0) {
                    ({ __auto_type _lst_p = &(bodiless); __auto_type _item = (oc); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else {
                    {
                        __auto_type _coll = sriqhyper_okeys_of(arena, oc, ((int64_t)(((int64_t)((bodied).len)))));
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type k = _coll.data[_i];
                            ({ __auto_type _lst_p = &(raw); __auto_type _item = (k); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                    ({ __auto_type _lst_p = &(bodied); __auto_type _item = (oc); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return ((sriqhyper_HIdx){.bodied = bodied, .bodiless = bodiless, .keys = sriqhyper_okeys_sorted(arena, raw), .width = sriqhyper_widest(onto), .dl4s = sriqhyper_dl4s_of(arena, onto)});
    }
}

int64_t sriqhyper_widest(slop_list_types_Clause onto) {
    {
        int64_t w = 1;
        {
            __auto_type _coll = onto;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type oc = _coll.data[_i];
                if (((int64_t)(((int64_t)((oc.body).len)))) > w) {
                    w = ((int64_t)(((int64_t)((oc.body).len))));
                }
            }
        }
        return w;
    }
}

slop_list_sriqref_Dl4 sriqhyper_dl4s_of(slop_arena* arena, slop_list_types_Clause onto) {
    {
        __auto_type out = ((slop_list_sriqref_Dl4){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = onto;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type oc = _coll.data[_i];
                {
                    __auto_type d = sriqref_dl4_of(oc);
                    if (d.ok) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (d); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

slop_list_sriqhyper_OKey sriqhyper_okeys_of(slop_arena* arena, types_Clause oc, int64_t n) {
    {
        __auto_type out = ((slop_list_sriqhyper_OKey){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = oc.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqhyper_OKey){.rank = sriqground_form_rank(a.form), .pred = a.pred, .oc = n, .i = i})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                i = (i + 1);
            }
        }
        return out;
    }
}

slop_list_sriqhyper_OKey sriqhyper_okeys_sorted(slop_arena* arena, slop_list_sriqhyper_OKey raw) {
    __auto_type _mv_738 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_sriqhyper_OKey _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_738.has_value) {
        return raw;
    } else if (_mv_738.has_value) {
        __auto_type k0 = _mv_738.value;
        {
            __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ sriqhyper__lambda_739_env_t* sriqhyper__lambda_739_env = (sriqhyper__lambda_739_env_t*)slop_arena_alloc(arena, sizeof(sriqhyper__lambda_739_env_t)); *sriqhyper__lambda_739_env = (sriqhyper__lambda_739_env_t){ .raw = raw, .k0 = k0 }; (slop_closure_t){ (void*)sriqhyper__lambda_739, (void*)sriqhyper__lambda_739_env }; }));
            __auto_type out = ((slop_list_sriqhyper_OKey){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = idx;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type k = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqhyper_okey_at(raw, k, k0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            return out;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t sriqhyper_okey_lower(slop_list_sriqhyper_OKey ks, sriqhyper_OKey key, sriqhyper_OKey fallback) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((ks).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                if (sriqhyper_okey_cmp(sriqhyper_okey_at(ks, mid, fallback), key) < 0) {
                    lo = (mid + 1);
                } else {
                    hi = mid;
                }
            }
        }
        return lo;
    }
}

int64_t sriqhyper_pair_code(sriqhyper_HIdx hx, sriqhyper_OKey k) {
    return ((k.oc * hx.width) + k.i);
}

slop_list_int sriqhyper_hyper_pairs(slop_arena* arena, sriqhyper_HIdx hx, slop_list_sriq_Premise ps) {
    __auto_type _mv_740 = ({ __auto_type _lst = hx.keys; size_t _idx = (size_t)0; slop_option_sriqhyper_OKey _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_740.has_value) {
        return ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    } else if (_mv_740.has_value) {
        __auto_type k0 = _mv_740.value;
        return sriqhyper_codes_set(arena, sriqhyper_pairs_of(arena, hx, ps, k0));
    }
    SLOP_UNREACHABLE();
}

slop_list_int sriqhyper_pairs_of(slop_arena* arena, sriqhyper_HIdx hx, slop_list_sriq_Premise ps, sriqhyper_OKey k0) {
    {
        __auto_type raw = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (p.maxed) {
                    {
                        __auto_type _coll = sriqhyper_pairs_under(arena, hx, sriqground_form_rank(p.sel.form), p.sel.pred, k0);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            ({ __auto_type _lst_p = &(raw); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        return raw;
    }
}

slop_list_int sriqhyper_pairs_under(slop_arena* arena, sriqhyper_HIdx hx, int64_t rank, uint32_t pred, sriqhyper_OKey k0) {
    {
        __auto_type ks = hx.keys;
        __auto_type key = ((sriqhyper_OKey){.rank = rank, .pred = pred, .oc = 0, .i = 0});
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = sriqhyper_okey_lower(ks, key, k0);
        while ((k < ((int64_t)(((int64_t)((ks).len))))) && (sriqhyper_okey_cmp(sriqhyper_okey_at(ks, k, k0), key) == 0)) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqhyper_pair_code(hx, sriqhyper_okey_at(ks, k, k0))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            k = (k + 1);
        }
        return out;
    }
}

slop_list_int sriqhyper_codes_set(slop_arena* arena, slop_list_int xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ sriqhyper__lambda_741_env_t* sriqhyper__lambda_741_env = (sriqhyper__lambda_741_env_t*)slop_arena_alloc(arena, sizeof(sriqhyper__lambda_741_env_t)); *sriqhyper__lambda_741_env = (sriqhyper__lambda_741_env_t){ .xs = xs }; (slop_closure_t){ (void*)sriqhyper__lambda_741, (void*)sriqhyper__lambda_741_env }; }));
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t last = -1;
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type x = sriqhyper_code_at(xs, k);
                    if (x != last) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        last = x;
                    }
                }
            }
        }
        return out;
    }
}

int64_t sriqhyper_code_at(slop_list_int xs, int64_t k) {
    __auto_type _mv_742 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_742.has_value) {
        __auto_type x = _mv_742.value;
        return x;
    } else if (!_mv_742.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

slop_list_sriq_Premise sriqhyper_slot_ix_cands(slop_arena* arena, uint8_t root, types_Lit a, sriqground_PIdx ix) {
    {
        __auto_type out = ((slop_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = sriqground_pidx_key_range(arena, ix, sriqground_form_rank(a.form), a.pred);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (sriqref_x_fits(root, a.t1, p.sel.t1) && ((a.form == types_LitForm_lf_unary) || sriqref_x_fits(root, a.t2, p.sel.t2))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

sriqhyper_HOut sriqhyper_hyper_anchor(slop_arena* arena, sriqref_Env env, sriqhyper_HCtx hc, sriq_HState start, types_Clause oc, int64_t i) {
    {
        __auto_type anchor = ({ __auto_type _mv = ({ __auto_type _lst = oc.body; size_t _idx = (size_t)i; slop_option_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type a = _mv.value; sriqhyper_slot_ix_cands(arena, hc.root, a, hc.dix); }) : (((slop_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena })); });
        __auto_type cs = ((slop_list_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        uint8_t empty = (((int64_t)((anchor).len)) == 0);
        while (!(empty) && (j < ((int64_t)(((int64_t)((oc.body).len)))))) {
            {
                __auto_type c = (((j == i)) ? anchor : sriqhyper_slot_at(arena, hc, oc, i, j));
                ({ __auto_type _lst_p = &(cs); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                if (((int64_t)((c).len)) == 0) {
                    empty = 1;
                }
                j = (j + 1);
            }
        }
        if (empty) {
            return ((sriqhyper_HOut){.out = sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0), .tried = 0});
        } else if (hc.root) {
            return sriqhyper_hyper_root_groups(arena, env, hc, start, oc, cs);
        } else {
            return sriqhyper_hyper_product(arena, env, hc, start, oc, cs);
        }
    }
}

slop_list_sriq_Premise sriqhyper_slot_at(slop_arena* arena, sriqhyper_HCtx hc, types_Clause oc, int64_t i, int64_t j) {
    __auto_type _mv_743 = ({ __auto_type _lst = oc.body; size_t _idx = (size_t)j; slop_option_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_743.has_value) {
        __auto_type a = _mv_743.value;
        return sriqhyper_slot_ix_cands(arena, hc.root, a, sriqground_pick_ix(j, i, hc.dix, hc.oix, hc.aix));
    } else if (!_mv_743.has_value) {
        return ((slop_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

sriqhyper_HOut sriqhyper_hyper_product(slop_arena* arena, sriqref_Env env, sriqhyper_HCtx hc, sriq_HState start, types_Clause oc, slop_list_list_sriq_Premise cs) {
    {
        __auto_type n = sriqref_product(cs, env.prod);
        if (n > env.prod) {
            return ((sriqhyper_HOut){.out = sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 1), .tried = 0});
        } else if (n == 0) {
            return ((sriqhyper_HOut){.out = sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0), .tried = 0});
        } else {
            __auto_type _mv_744 = ({ __auto_type _lst = hc.aps; size_t _idx = (size_t)0; slop_option_sriq_Premise _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (!_mv_744.has_value) {
                return ((sriqhyper_HOut){.out = sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0), .tried = 0});
            } else if (_mv_744.has_value) {
                __auto_type p0 = _mv_744.value;
                return ((sriqhyper_HOut){.out = sriqref_out_of(sriqref_hyper_choices(arena, hc.v, start, oc, cs, n, p0), 0), .tried = n});
            }
            SLOP_UNREACHABLE();
        }
    }
}

slop_option_u32 sriqhyper_x_const(types_Lit a, sriq_Premise p) {
    {
        __auto_type t = (((a.t1.kind == types_AKind_ak_x)) ? p.sel.t1 : p.sel.t2);
        if (t.kind == types_AKind_ak_u) {
            return (slop_option_u32){.has_value = 1, .value = t.cst};
        } else {
            return (slop_option_u32){.has_value = false};
        }
    }
}

sriqhyper_CPrem sriqhyper_cprem_at(slop_list_sriqhyper_CPrem xs, int64_t k, sriqhyper_CPrem fallback) {
    __auto_type _mv_745 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_sriqhyper_CPrem _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_745.has_value) {
        __auto_type x = _mv_745.value;
        return x;
    } else if (!_mv_745.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_list_sriqhyper_CPrem sriqhyper_by_const(slop_arena* arena, types_Lit a, slop_list_sriq_Premise ps) {
    {
        __auto_type raw = ((slop_list_sriqhyper_CPrem){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                __auto_type _mv_746 = sriqhyper_x_const(a, p);
                if (_mv_746.has_value) {
                    __auto_type u = _mv_746.value;
                    ({ __auto_type _lst_p = &(raw); __auto_type _item = (((sriqhyper_CPrem){.u = u, .p = p})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_746.has_value) {
                }
            }
        }
        __auto_type _mv_747 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_sriqhyper_CPrem _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_747.has_value) {
            return raw;
        } else if (_mv_747.has_value) {
            __auto_type c0 = _mv_747.value;
            return sriqhyper_cprems_sorted(arena, raw, c0);
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_sriqhyper_CPrem sriqhyper_cprems_sorted(slop_arena* arena, slop_list_sriqhyper_CPrem raw, sriqhyper_CPrem c0) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ sriqhyper__lambda_748_env_t* sriqhyper__lambda_748_env = (sriqhyper__lambda_748_env_t*)slop_arena_alloc(arena, sizeof(sriqhyper__lambda_748_env_t)); *sriqhyper__lambda_748_env = (sriqhyper__lambda_748_env_t){ .raw = raw, .c0 = c0 }; (slop_closure_t){ (void*)sriqhyper__lambda_748, (void*)sriqhyper__lambda_748_env }; }));
        __auto_type out = ((slop_list_sriqhyper_CPrem){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqhyper_cprem_at(raw, k, c0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_sriq_Premise sriqhyper_with_const(slop_arena* arena, slop_list_sriqhyper_CPrem xs, uint32_t u) {
    {
        __auto_type out = ((slop_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((xs).len))));
        __auto_type _mv_749 = ({ __auto_type _lst = xs; size_t _idx = (size_t)0; slop_option_sriqhyper_CPrem _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_749.has_value) {
            return out;
        } else if (_mv_749.has_value) {
            __auto_type c0 = _mv_749.value;
            while (lo < hi) {
                {
                    __auto_type mid = ((lo + hi) / 2);
                    if (sriqhyper_cprem_at(xs, mid, c0).u < u) {
                        lo = (mid + 1);
                    } else {
                        hi = mid;
                    }
                }
            }
            while ((lo < ((int64_t)(((int64_t)((xs).len))))) && (sriqhyper_cprem_at(xs, lo, c0).u == u)) {
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqhyper_cprem_at(xs, lo, c0).p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                lo = (lo + 1);
            }
            return out;
        }
        SLOP_UNREACHABLE();
    }
}

sriqhyper_HOut sriqhyper_hyper_root_groups(slop_arena* arena, sriqref_Env env, sriqhyper_HCtx hc, sriq_HState start, types_Clause oc, slop_list_list_sriq_Premise cs) {
    {
        __auto_type groups = ((slop_list_sriqhyper_Group){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        {
            __auto_type _coll = oc.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_750 = ({ __auto_type _lst = cs; size_t _idx = (size_t)j; slop_option_list_sriq_Premise _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_750.has_value) {
                    __auto_type ps = _mv_750.value;
                    ({ __auto_type _lst_p = &(groups); __auto_type _item = (((sriqhyper_Group){.cps = sriqhyper_by_const(arena, a, ps)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_750.has_value) {
                }
                j = (j + 1);
            }
        }
        __auto_type _mv_751 = ({ __auto_type _lst = groups; size_t _idx = (size_t)0; slop_option_sriqhyper_Group _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_751.has_value) {
            return ((sriqhyper_HOut){.out = sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0), .tried = 0});
        } else if (_mv_751.has_value) {
            __auto_type g0 = _mv_751.value;
            return sriqhyper_root_by_const(arena, env, hc, start, oc, groups, g0.cps);
        }
        SLOP_UNREACHABLE();
    }
}

sriqhyper_HOut sriqhyper_root_by_const(slop_arena* arena, sriqref_Env env, sriqhyper_HCtx hc, sriq_HState start, types_Clause oc, slop_list_sriqhyper_Group groups, slop_list_sriqhyper_CPrem g0) {
    {
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        int64_t tried = 0;
        int64_t last = -1;
        {
            __auto_type _coll = g0;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (((int64_t)(c.u)) != last) {
                    {
                        __auto_type o = sriqhyper_hyper_product(arena, env, hc, start, oc, sriqhyper_slots_for(arena, groups, c.u));
                        last = ((int64_t)(c.u));
                        {
                            __auto_type _coll = o.out.cands;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type x = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        if (o.out.over) {
                            over = 1;
                        }
                        tried = (tried + o.tried);
                    }
                }
            }
        }
        return ((sriqhyper_HOut){.out = sriqref_out_of(out, over), .tried = tried});
    }
}

slop_list_list_sriq_Premise sriqhyper_slots_for(slop_arena* arena, slop_list_sriqhyper_Group groups, uint32_t u) {
    {
        __auto_type out = ((slop_list_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = groups;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type g = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqhyper_with_const(arena, g.cps, u)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

sriqhyper_HOut sriqhyper_hyper_indexed(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, sriqhyper_HCtx hc, int64_t room) {
    {
        __auto_type start = sriq_hyper_start(arena, types_at_x(), !(hc.root));
        __auto_type out = ((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        int64_t tried = 0;
        {
            __auto_type _coll = sriqhyper_hyper_pairs(arena, hx, hc.dps);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type code = _coll.data[_i];
                if (((int64_t)(((int64_t)((out).len)))) <= room) {
                    {
                        __auto_type o = sriqhyper_hyper_code(arena, env, hx, hc, start, code);
                        {
                            __auto_type _coll = o.out.cands;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type c = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        if (o.out.over) {
                            over = 1;
                        }
                        tried = (tried + o.tried);
                    }
                }
            }
        }
        return ((sriqhyper_HOut){.out = sriqref_out_of(out, over), .tried = tried});
    }
}

sriqhyper_HOut sriqhyper_hyper_code(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, sriqhyper_HCtx hc, sriq_HState start, int64_t code) {
    __auto_type _mv_752 = ({ __auto_type _lst = hx.bodied; size_t _idx = (size_t)(code / hx.width); slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_752.has_value) {
        __auto_type oc = _mv_752.value;
        return sriqhyper_hyper_anchor(arena, env, hc, start, oc, (code % hx.width));
    } else if (!_mv_752.has_value) {
        return ((sriqhyper_HOut){.out = sriqref_out_of(((slop_list_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0), .tried = 0});
    }
    SLOP_UNREACHABLE();
}

