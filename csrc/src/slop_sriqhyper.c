#include "../runtime/slop_runtime.h"
#include "slop_sriqhyper.h"

howl_sriqhyper_OKey howl_sriqhyper_okey_at(slop_list_howl_sriqhyper_OKey ks, int64_t k, howl_sriqhyper_OKey fallback);
int64_t howl_sriqhyper_okey_cmp(howl_sriqhyper_OKey a, howl_sriqhyper_OKey b);
howl_sriqhyper_HIdx howl_sriqhyper_h_index(slop_arena* arena, slop_list_howl_types_Clause onto);
int64_t howl_sriqhyper_widest(slop_list_howl_types_Clause onto);
slop_list_howl_sriqref_Dl4 howl_sriqhyper_dl4s_of(slop_arena* arena, slop_list_howl_types_Clause onto);
slop_list_howl_sriqhyper_OKey howl_sriqhyper_okeys_of(slop_arena* arena, howl_types_Clause oc, int64_t n);
slop_list_howl_sriqhyper_OKey howl_sriqhyper_okeys_sorted(slop_arena* arena, slop_list_howl_sriqhyper_OKey raw);
int64_t howl_sriqhyper_okey_lower(slop_list_howl_sriqhyper_OKey ks, howl_sriqhyper_OKey key, howl_sriqhyper_OKey fallback);
int64_t howl_sriqhyper_pair_code(howl_sriqhyper_HIdx hx, howl_sriqhyper_OKey k);
slop_list_int howl_sriqhyper_hyper_pairs(slop_arena* arena, howl_sriqhyper_HIdx hx, slop_list_howl_sriq_Premise ps);
slop_list_int howl_sriqhyper_pairs_of(slop_arena* arena, howl_sriqhyper_HIdx hx, slop_list_howl_sriq_Premise ps, howl_sriqhyper_OKey k0);
slop_list_int howl_sriqhyper_pairs_under(slop_arena* arena, howl_sriqhyper_HIdx hx, int64_t rank, uint32_t pred, howl_sriqhyper_OKey k0);
slop_list_int howl_sriqhyper_codes_set(slop_arena* arena, slop_list_int xs);
int64_t howl_sriqhyper_code_at(slop_list_int xs, int64_t k);
slop_list_howl_sriq_Premise howl_sriqhyper_slot_ix_cands(slop_arena* arena, uint8_t root, howl_types_Lit a, howl_sriqground_PIdx ix);
howl_sriqhyper_HOut howl_sriqhyper_hyper_anchor(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HCtx hc, howl_sriq_HState start, howl_types_Clause oc, int64_t i);
slop_list_howl_sriq_Premise howl_sriqhyper_slot_at(slop_arena* arena, howl_sriqhyper_HCtx hc, howl_types_Clause oc, int64_t i, int64_t j);
howl_sriqhyper_HOut howl_sriqhyper_hyper_product(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HCtx hc, howl_sriq_HState start, howl_types_Clause oc, slop_list_list_howl_sriq_Premise cs);
slop_option_u32 howl_sriqhyper_x_const(howl_types_Lit a, howl_sriq_Premise p);
howl_sriqhyper_CPrem howl_sriqhyper_cprem_at(slop_list_howl_sriqhyper_CPrem xs, int64_t k, howl_sriqhyper_CPrem fallback);
slop_list_howl_sriqhyper_CPrem howl_sriqhyper_by_const(slop_arena* arena, howl_types_Lit a, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriqhyper_CPrem howl_sriqhyper_cprems_sorted(slop_arena* arena, slop_list_howl_sriqhyper_CPrem raw, howl_sriqhyper_CPrem c0);
slop_list_howl_sriq_Premise howl_sriqhyper_with_const(slop_arena* arena, slop_list_howl_sriqhyper_CPrem xs, uint32_t u);
howl_sriqhyper_HOut howl_sriqhyper_hyper_root_groups(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HCtx hc, howl_sriq_HState start, howl_types_Clause oc, slop_list_list_howl_sriq_Premise cs);
howl_sriqhyper_HOut howl_sriqhyper_root_by_const(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HCtx hc, howl_sriq_HState start, howl_types_Clause oc, slop_list_howl_sriqhyper_Group groups, slop_list_howl_sriqhyper_CPrem g0);
slop_list_list_howl_sriq_Premise howl_sriqhyper_slots_for(slop_arena* arena, slop_list_howl_sriqhyper_Group groups, uint32_t u);
howl_sriqhyper_HOut howl_sriqhyper_hyper_indexed(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HIdx hx, howl_sriqhyper_HCtx hc, int64_t room);
howl_sriqhyper_HOut howl_sriqhyper_hyper_code(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HIdx hx, howl_sriqhyper_HCtx hc, howl_sriq_HState start, int64_t code);

typedef struct { slop_list_howl_sriqhyper_OKey raw; howl_sriqhyper_OKey k0; } howl_sriqhyper__lambda_739_env_t;

static int64_t howl_sriqhyper__lambda_739(howl_sriqhyper__lambda_739_env_t* _env, int64_t a, int64_t b) { return howl_sriqhyper_okey_cmp(howl_sriqhyper_okey_at(_env->raw, a, _env->k0), howl_sriqhyper_okey_at(_env->raw, b, _env->k0)); }

typedef struct { slop_list_int xs; } howl_sriqhyper__lambda_741_env_t;

static int64_t howl_sriqhyper__lambda_741(howl_sriqhyper__lambda_741_env_t* _env, int64_t a, int64_t b) { return ((howl_sriqhyper_code_at(_env->xs, a) < howl_sriqhyper_code_at(_env->xs, b)) ? -1 : ((howl_sriqhyper_code_at(_env->xs, a) > howl_sriqhyper_code_at(_env->xs, b)) ? 1 : 0)); }

typedef struct { slop_list_howl_sriqhyper_CPrem raw; howl_sriqhyper_CPrem c0; } howl_sriqhyper__lambda_748_env_t;

static int64_t howl_sriqhyper__lambda_748(howl_sriqhyper__lambda_748_env_t* _env, int64_t i, int64_t j) { return ((howl_sriqhyper_cprem_at(_env->raw, i, _env->c0).u < howl_sriqhyper_cprem_at(_env->raw, j, _env->c0).u) ? -1 : ((howl_sriqhyper_cprem_at(_env->raw, i, _env->c0).u > howl_sriqhyper_cprem_at(_env->raw, j, _env->c0).u) ? 1 : 0)); }

howl_sriqhyper_OKey howl_sriqhyper_okey_at(slop_list_howl_sriqhyper_OKey ks, int64_t k, howl_sriqhyper_OKey fallback) {
    __auto_type _mv_737 = ({ __auto_type _lst = ks; size_t _idx = (size_t)k; slop_option_howl_sriqhyper_OKey _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_737.has_value) {
        __auto_type x = _mv_737.value;
        return x;
    } else if (!_mv_737.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqhyper_okey_cmp(howl_sriqhyper_OKey a, howl_sriqhyper_OKey b) {
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

howl_sriqhyper_HIdx howl_sriqhyper_h_index(slop_arena* arena, slop_list_howl_types_Clause onto) {
    {
        __auto_type bodied = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type bodiless = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type raw = ((slop_list_howl_sriqhyper_OKey){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = onto;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type oc = _coll.data[_i];
                if (((int64_t)((oc.body).len)) == 0) {
                    (void)(({ __auto_type _lst_p = &(bodiless); __auto_type _item = (oc); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                } else {
                    {
                        __auto_type _coll = howl_sriqhyper_okeys_of(arena, oc, ((int64_t)(((int64_t)((bodied).len)))));
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type k = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(raw); __auto_type _item = (k); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                    (void)(({ __auto_type _lst_p = &(bodied); __auto_type _item = (oc); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return ((howl_sriqhyper_HIdx){.bodied = bodied, .bodiless = bodiless, .keys = howl_sriqhyper_okeys_sorted(arena, raw), .width = howl_sriqhyper_widest(onto), .dl4s = howl_sriqhyper_dl4s_of(arena, onto)});
    }
}

int64_t howl_sriqhyper_widest(slop_list_howl_types_Clause onto) {
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

slop_list_howl_sriqref_Dl4 howl_sriqhyper_dl4s_of(slop_arena* arena, slop_list_howl_types_Clause onto) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Dl4){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = onto;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type oc = _coll.data[_i];
                {
                    __auto_type d = howl_sriqref_dl4_of(oc);
                    if (d.ok) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (d); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_sriqhyper_OKey howl_sriqhyper_okeys_of(slop_arena* arena, howl_types_Clause oc, int64_t n) {
    {
        __auto_type out = ((slop_list_howl_sriqhyper_OKey){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = oc.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqhyper_OKey){.rank = howl_sriqground_form_rank(a.form), .pred = a.pred, .oc = n, .i = i})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                i = (i + 1);
            }
        }
        return out;
    }
}

slop_list_howl_sriqhyper_OKey howl_sriqhyper_okeys_sorted(slop_arena* arena, slop_list_howl_sriqhyper_OKey raw) {
    __auto_type _mv_738 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_howl_sriqhyper_OKey _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_738.has_value) {
        return raw;
    } else if (_mv_738.has_value) {
        __auto_type k0 = _mv_738.value;
        {
            __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ howl_sriqhyper__lambda_739_env_t* howl_sriqhyper__lambda_739_env = (howl_sriqhyper__lambda_739_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqhyper__lambda_739_env_t)); *howl_sriqhyper__lambda_739_env = (howl_sriqhyper__lambda_739_env_t){ .raw = raw, .k0 = k0 }; (slop_closure_t){ (void*)howl_sriqhyper__lambda_739, (void*)howl_sriqhyper__lambda_739_env }; }));
            __auto_type out = ((slop_list_howl_sriqhyper_OKey){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = idx;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type k = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqhyper_okey_at(raw, k, k0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            return out;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqhyper_okey_lower(slop_list_howl_sriqhyper_OKey ks, howl_sriqhyper_OKey key, howl_sriqhyper_OKey fallback) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((ks).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                if (howl_sriqhyper_okey_cmp(howl_sriqhyper_okey_at(ks, mid, fallback), key) < 0) {
                    lo = (mid + 1);
                } else {
                    hi = mid;
                }
            }
        }
        return lo;
    }
}

int64_t howl_sriqhyper_pair_code(howl_sriqhyper_HIdx hx, howl_sriqhyper_OKey k) {
    return ((k.oc * hx.width) + k.i);
}

slop_list_int howl_sriqhyper_hyper_pairs(slop_arena* arena, howl_sriqhyper_HIdx hx, slop_list_howl_sriq_Premise ps) {
    __auto_type _mv_740 = ({ __auto_type _lst = hx.keys; size_t _idx = (size_t)0; slop_option_howl_sriqhyper_OKey _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_740.has_value) {
        return ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    } else if (_mv_740.has_value) {
        __auto_type k0 = _mv_740.value;
        return howl_sriqhyper_codes_set(arena, howl_sriqhyper_pairs_of(arena, hx, ps, k0));
    }
    SLOP_UNREACHABLE();
}

slop_list_int howl_sriqhyper_pairs_of(slop_arena* arena, howl_sriqhyper_HIdx hx, slop_list_howl_sriq_Premise ps, howl_sriqhyper_OKey k0) {
    {
        __auto_type raw = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (p.maxed) {
                    {
                        __auto_type _coll = howl_sriqhyper_pairs_under(arena, hx, howl_sriqground_form_rank(p.sel.form), p.sel.pred, k0);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(raw); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        return raw;
    }
}

slop_list_int howl_sriqhyper_pairs_under(slop_arena* arena, howl_sriqhyper_HIdx hx, int64_t rank, uint32_t pred, howl_sriqhyper_OKey k0) {
    {
        __auto_type ks = hx.keys;
        __auto_type key = ((howl_sriqhyper_OKey){.rank = rank, .pred = pred, .oc = 0, .i = 0});
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = howl_sriqhyper_okey_lower(ks, key, k0);
        while ((k < ((int64_t)(((int64_t)((ks).len))))) && (howl_sriqhyper_okey_cmp(howl_sriqhyper_okey_at(ks, k, k0), key) == 0)) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqhyper_pair_code(hx, howl_sriqhyper_okey_at(ks, k, k0))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            k = (k + 1);
        }
        return out;
    }
}

slop_list_int howl_sriqhyper_codes_set(slop_arena* arena, slop_list_int xs) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ howl_sriqhyper__lambda_741_env_t* howl_sriqhyper__lambda_741_env = (howl_sriqhyper__lambda_741_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqhyper__lambda_741_env_t)); *howl_sriqhyper__lambda_741_env = (howl_sriqhyper__lambda_741_env_t){ .xs = xs }; (slop_closure_t){ (void*)howl_sriqhyper__lambda_741, (void*)howl_sriqhyper__lambda_741_env }; }));
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t last = -1;
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type x = howl_sriqhyper_code_at(xs, k);
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

int64_t howl_sriqhyper_code_at(slop_list_int xs, int64_t k) {
    __auto_type _mv_742 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_742.has_value) {
        __auto_type x = _mv_742.value;
        return x;
    } else if (!_mv_742.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_sriq_Premise howl_sriqhyper_slot_ix_cands(slop_arena* arena, uint8_t root, howl_types_Lit a, howl_sriqground_PIdx ix) {
    {
        __auto_type out = ((slop_list_howl_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = howl_sriqground_pidx_key_range(arena, ix, howl_sriqground_form_rank(a.form), a.pred);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (howl_sriqref_x_fits(root, a.t1, p.sel.t1) && ((a.form == howl_types_LitForm_lf_unary) || howl_sriqref_x_fits(root, a.t2, p.sel.t2))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

howl_sriqhyper_HOut howl_sriqhyper_hyper_anchor(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HCtx hc, howl_sriq_HState start, howl_types_Clause oc, int64_t i) {
    {
        __auto_type anchor = ({ __auto_type _mv = ({ __auto_type _lst = oc.body; size_t _idx = (size_t)i; slop_option_howl_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type a = _mv.value; howl_sriqhyper_slot_ix_cands(arena, hc.root, a, hc.dix); }) : (((slop_list_howl_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena })); });
        __auto_type cs = ((slop_list_list_howl_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        uint8_t empty = (((int64_t)((anchor).len)) == 0);
        while (!(empty) && (j < ((int64_t)(((int64_t)((oc.body).len)))))) {
            {
                __auto_type c = (((j == i)) ? anchor : howl_sriqhyper_slot_at(arena, hc, oc, i, j));
                (void)(({ __auto_type _lst_p = &(cs); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                if (((int64_t)((c).len)) == 0) {
                    empty = 1;
                }
                j = (j + 1);
            }
        }
        if (empty) {
            return ((howl_sriqhyper_HOut){.out = howl_sriqref_out_of(((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0), .tried = 0});
        } else if (hc.root) {
            return howl_sriqhyper_hyper_root_groups(arena, env, hc, start, oc, cs);
        } else {
            return howl_sriqhyper_hyper_product(arena, env, hc, start, oc, cs);
        }
    }
}

slop_list_howl_sriq_Premise howl_sriqhyper_slot_at(slop_arena* arena, howl_sriqhyper_HCtx hc, howl_types_Clause oc, int64_t i, int64_t j) {
    __auto_type _mv_743 = ({ __auto_type _lst = oc.body; size_t _idx = (size_t)j; slop_option_howl_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_743.has_value) {
        __auto_type a = _mv_743.value;
        return howl_sriqhyper_slot_ix_cands(arena, hc.root, a, howl_sriqground_pick_ix(j, i, hc.dix, hc.oix, hc.aix));
    } else if (!_mv_743.has_value) {
        return ((slop_list_howl_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

howl_sriqhyper_HOut howl_sriqhyper_hyper_product(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HCtx hc, howl_sriq_HState start, howl_types_Clause oc, slop_list_list_howl_sriq_Premise cs) {
    {
        __auto_type n = howl_sriqref_product(cs, env.prod);
        if (n > env.prod) {
            return ((howl_sriqhyper_HOut){.out = howl_sriqref_out_of(((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 1), .tried = 0});
        } else if (n == 0) {
            return ((howl_sriqhyper_HOut){.out = howl_sriqref_out_of(((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0), .tried = 0});
        } else {
            __auto_type _mv_744 = ({ __auto_type _lst = hc.aps; size_t _idx = (size_t)0; slop_option_howl_sriq_Premise _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (!_mv_744.has_value) {
                return ((howl_sriqhyper_HOut){.out = howl_sriqref_out_of(((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0), .tried = 0});
            } else if (_mv_744.has_value) {
                __auto_type p0 = _mv_744.value;
                return ((howl_sriqhyper_HOut){.out = howl_sriqref_out_of(howl_sriqref_hyper_choices(arena, hc.v, start, oc, cs, n, p0), 0), .tried = n});
            }
            SLOP_UNREACHABLE();
        }
    }
}

slop_option_u32 howl_sriqhyper_x_const(howl_types_Lit a, howl_sriq_Premise p) {
    {
        __auto_type t = (((a.t1.kind == howl_types_AKind_ak_x)) ? p.sel.t1 : p.sel.t2);
        if (t.kind == howl_types_AKind_ak_u) {
            return (slop_option_u32){.has_value = 1, .value = t.cst};
        } else {
            return (slop_option_u32){.has_value = false};
        }
    }
}

howl_sriqhyper_CPrem howl_sriqhyper_cprem_at(slop_list_howl_sriqhyper_CPrem xs, int64_t k, howl_sriqhyper_CPrem fallback) {
    __auto_type _mv_745 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_howl_sriqhyper_CPrem _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_745.has_value) {
        __auto_type x = _mv_745.value;
        return x;
    } else if (!_mv_745.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_sriqhyper_CPrem howl_sriqhyper_by_const(slop_arena* arena, howl_types_Lit a, slop_list_howl_sriq_Premise ps) {
    {
        __auto_type raw = ((slop_list_howl_sriqhyper_CPrem){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                __auto_type _mv_746 = howl_sriqhyper_x_const(a, p);
                if (_mv_746.has_value) {
                    __auto_type u = _mv_746.value;
                    ({ __auto_type _lst_p = &(raw); __auto_type _item = (((howl_sriqhyper_CPrem){.u = u, .p = p})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_746.has_value) {
                }
            }
        }
        __auto_type _mv_747 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_howl_sriqhyper_CPrem _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_747.has_value) {
            return raw;
        } else if (_mv_747.has_value) {
            __auto_type c0 = _mv_747.value;
            return howl_sriqhyper_cprems_sorted(arena, raw, c0);
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_howl_sriqhyper_CPrem howl_sriqhyper_cprems_sorted(slop_arena* arena, slop_list_howl_sriqhyper_CPrem raw, howl_sriqhyper_CPrem c0) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ howl_sriqhyper__lambda_748_env_t* howl_sriqhyper__lambda_748_env = (howl_sriqhyper__lambda_748_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqhyper__lambda_748_env_t)); *howl_sriqhyper__lambda_748_env = (howl_sriqhyper__lambda_748_env_t){ .raw = raw, .c0 = c0 }; (slop_closure_t){ (void*)howl_sriqhyper__lambda_748, (void*)howl_sriqhyper__lambda_748_env }; }));
        __auto_type out = ((slop_list_howl_sriqhyper_CPrem){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqhyper_cprem_at(raw, k, c0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_sriq_Premise howl_sriqhyper_with_const(slop_arena* arena, slop_list_howl_sriqhyper_CPrem xs, uint32_t u) {
    {
        __auto_type out = ((slop_list_howl_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((xs).len))));
        __auto_type _mv_749 = ({ __auto_type _lst = xs; size_t _idx = (size_t)0; slop_option_howl_sriqhyper_CPrem _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_749.has_value) {
            return out;
        } else if (_mv_749.has_value) {
            __auto_type c0 = _mv_749.value;
            while (lo < hi) {
                {
                    __auto_type mid = ((lo + hi) / 2);
                    if (howl_sriqhyper_cprem_at(xs, mid, c0).u < u) {
                        lo = (mid + 1);
                    } else {
                        hi = mid;
                    }
                }
            }
            while ((lo < ((int64_t)(((int64_t)((xs).len))))) && (howl_sriqhyper_cprem_at(xs, lo, c0).u == u)) {
                ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqhyper_cprem_at(xs, lo, c0).p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                lo = (lo + 1);
            }
            return out;
        }
        SLOP_UNREACHABLE();
    }
}

howl_sriqhyper_HOut howl_sriqhyper_hyper_root_groups(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HCtx hc, howl_sriq_HState start, howl_types_Clause oc, slop_list_list_howl_sriq_Premise cs) {
    {
        __auto_type groups = ((slop_list_howl_sriqhyper_Group){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        {
            __auto_type _coll = oc.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_750 = ({ __auto_type _lst = cs; size_t _idx = (size_t)j; slop_option_list_howl_sriq_Premise _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_750.has_value) {
                    __auto_type ps = _mv_750.value;
                    ({ __auto_type _lst_p = &(groups); __auto_type _item = (((howl_sriqhyper_Group){.cps = howl_sriqhyper_by_const(arena, a, ps)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_750.has_value) {
                }
                j = (j + 1);
            }
        }
        __auto_type _mv_751 = ({ __auto_type _lst = groups; size_t _idx = (size_t)0; slop_option_howl_sriqhyper_Group _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_751.has_value) {
            return ((howl_sriqhyper_HOut){.out = howl_sriqref_out_of(((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0), .tried = 0});
        } else if (_mv_751.has_value) {
            __auto_type g0 = _mv_751.value;
            return howl_sriqhyper_root_by_const(arena, env, hc, start, oc, groups, g0.cps);
        }
        SLOP_UNREACHABLE();
    }
}

howl_sriqhyper_HOut howl_sriqhyper_root_by_const(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HCtx hc, howl_sriq_HState start, howl_types_Clause oc, slop_list_howl_sriqhyper_Group groups, slop_list_howl_sriqhyper_CPrem g0) {
    {
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        int64_t tried = 0;
        int64_t last = -1;
        {
            __auto_type _coll = g0;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (((int64_t)(c.u)) != last) {
                    {
                        __auto_type o = howl_sriqhyper_hyper_product(arena, env, hc, start, oc, howl_sriqhyper_slots_for(arena, groups, c.u));
                        last = ((int64_t)(c.u));
                        {
                            __auto_type _coll = o.out.cands;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type x = _coll.data[_i];
                                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
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
        return ((howl_sriqhyper_HOut){.out = howl_sriqref_out_of(out, over), .tried = tried});
    }
}

slop_list_list_howl_sriq_Premise howl_sriqhyper_slots_for(slop_arena* arena, slop_list_howl_sriqhyper_Group groups, uint32_t u) {
    {
        __auto_type out = ((slop_list_list_howl_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = groups;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type g = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqhyper_with_const(arena, g.cps, u)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_sriqhyper_HOut howl_sriqhyper_hyper_indexed(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HIdx hx, howl_sriqhyper_HCtx hc, int64_t room) {
    {
        __auto_type start = howl_sriq_hyper_start(arena, howl_types_at_x(), !(hc.root));
        __auto_type out = ((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t over = 0;
        int64_t tried = 0;
        {
            __auto_type _coll = howl_sriqhyper_hyper_pairs(arena, hx, hc.dps);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type code = _coll.data[_i];
                if (((int64_t)(((int64_t)((out).len)))) <= room) {
                    {
                        __auto_type o = howl_sriqhyper_hyper_code(arena, env, hx, hc, start, code);
                        {
                            __auto_type _coll = o.out.cands;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type c = _coll.data[_i];
                                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
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
        return ((howl_sriqhyper_HOut){.out = howl_sriqref_out_of(out, over), .tried = tried});
    }
}

howl_sriqhyper_HOut howl_sriqhyper_hyper_code(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HIdx hx, howl_sriqhyper_HCtx hc, howl_sriq_HState start, int64_t code) {
    __auto_type _mv_752 = ({ __auto_type _lst = hx.bodied; size_t _idx = (size_t)(code / hx.width); slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_752.has_value) {
        __auto_type oc = _mv_752.value;
        return howl_sriqhyper_hyper_anchor(arena, env, hc, start, oc, (code % hx.width));
    } else if (!_mv_752.has_value) {
        return ((howl_sriqhyper_HOut){.out = howl_sriqref_out_of(((slop_list_howl_sriqref_Cand){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), 0), .tried = 0});
    }
    SLOP_UNREACHABLE();
}

