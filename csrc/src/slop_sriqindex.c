#include "../runtime/slop_runtime.h"
#include "slop_sriqindex.h"

int64_t howl_sriqindex_entry_cmp(howl_sriqindex_Entry a, howl_sriqindex_Entry b);
int64_t howl_sriqindex_key_cmp(howl_sriqindex_Entry e, int64_t side, howl_types_Lit l);
howl_sriqindex_Entry howl_sriqindex_entry_at(slop_list_howl_sriqindex_Entry es, int64_t k, howl_sriqindex_Entry fallback);
slop_option_howl_sriqindex_Entry howl_sriqindex_key_of(howl_types_Clause c, int64_t i);
howl_sriqindex_SubIndex howl_sriqindex_sub_index(slop_arena* arena, slop_list_howl_types_Clause xs);
int64_t howl_sriqindex_clause_sig(howl_types_Clause c);
int64_t howl_sriqindex_lit_bit(int64_t side, howl_types_Lit l);
int64_t howl_sriqindex_term_mix(howl_types_ATerm t);
int64_t howl_sriqindex_sig_at(howl_sriqindex_SubIndex ix, int64_t i);
slop_list_howl_sriqindex_Entry howl_sriqindex_sorted_entries(slop_arena* arena, slop_list_howl_sriqindex_Entry raw);
int64_t howl_sriqindex_lower_bound(slop_list_howl_sriqindex_Entry es, int64_t side, howl_types_Lit l, howl_sriqindex_Entry fallback);
uint8_t howl_sriqindex_probe(howl_sriqindex_SubIndex ix, int64_t side, howl_types_Lit l, howl_types_Clause c, int64_t csig, int64_t skip);
uint8_t howl_sriqindex_hit(howl_sriqindex_SubIndex ix, howl_sriqindex_Entry e, howl_types_Clause c, int64_t csig, int64_t skip);
uint8_t howl_sriqindex_x_subsumes(howl_sriqindex_SubIndex ix, int64_t i, howl_types_Clause c);
uint8_t howl_sriqindex_some_subsumes(howl_sriqindex_SubIndex ix, howl_types_Clause c, int64_t skip);
slop_list_howl_types_Clause howl_sriqindex_distinct(slop_arena* arena, slop_list_howl_types_Clause cs);
howl_types_Clause howl_sriqindex_clause_of(slop_list_howl_types_Clause cs, int64_t k, howl_types_Clause fallback);
slop_list_howl_types_Clause howl_sriqindex_merged(slop_arena* arena, slop_list_howl_types_Clause a, slop_list_howl_types_Clause b);
howl_sriqsubsume_Committed howl_sriqindex_commit_indexed(slop_arena* arena, slop_list_howl_types_Clause ws, slop_list_howl_types_Clause cs);
slop_option_howl_types_ATerm howl_sriqindex_fterm_key(howl_types_ATerm t);
howl_sriqindex_FPart howl_sriqindex_fpart_at(slop_list_howl_sriqindex_FPart ps, int64_t k, howl_sriqindex_FPart fallback);
howl_sriqindex_KIdx howl_sriqindex_k_index(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriqctx_Triggers tr, slop_list_howl_types_Clause cs);
howl_sriqindex_KIdx howl_sriqindex_k_index_premises(slop_arena* arena, howl_sriqctx_Triggers tr, slop_list_howl_sriq_Premise ps);
uint8_t howl_sriqindex_unit_premise(howl_sriq_Premise p);
slop_list_howl_types_Lit howl_sriqindex_ground_k2(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriq_SuccSig any, howl_types_Lit l);
uint8_t howl_sriqindex_no_fterm(howl_types_Lit l);
slop_list_howl_sriqindex_FPart howl_sriqindex_fparts_of(slop_arena* arena, howl_types_Lit l, uint8_t single);
uint8_t howl_sriqindex_first_is(slop_list_howl_sriqindex_FPart ps, howl_types_ATerm t);
slop_list_howl_sriqindex_FPart howl_sriqindex_fparts_sorted(slop_arena* arena, slop_list_howl_sriqindex_FPart raw);
int64_t howl_sriqindex_fpart_lower(slop_list_howl_sriqindex_FPart ps, howl_types_ATerm t, howl_sriqindex_FPart fallback);
howl_sriq_KSets howl_sriqindex_k_query(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqindex_KIdx kx, howl_sriq_SuccSig sg);
howl_sriqindex_KPair howl_sriqindex_k_walk(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqindex_KIdx kx, howl_sriq_SuccSig sg, howl_types_ATerm t, howl_sriqindex_FPart p0);

typedef struct { slop_list_howl_sriqindex_Entry raw; howl_sriqindex_Entry e0; } howl_sriqindex__lambda_502_env_t;

static int64_t howl_sriqindex__lambda_502(howl_sriqindex__lambda_502_env_t* _env, int64_t a, int64_t b) { return howl_sriqindex_entry_cmp(howl_sriqindex_entry_at(_env->raw, a, _env->e0), howl_sriqindex_entry_at(_env->raw, b, _env->e0)); }

typedef struct { slop_list_howl_types_Clause cs; howl_types_Clause c0; } howl_sriqindex__lambda_506_env_t;

static int64_t howl_sriqindex__lambda_506(howl_sriqindex__lambda_506_env_t* _env, int64_t a, int64_t b) { return howl_sriqclauses_clause_cmp(howl_sriqindex_clause_of(_env->cs, a, _env->c0), howl_sriqindex_clause_of(_env->cs, b, _env->c0)); }

typedef struct { slop_list_howl_sriqindex_FPart raw; howl_sriqindex_FPart p0; } howl_sriqindex__lambda_515_env_t;

static int64_t howl_sriqindex__lambda_515(howl_sriqindex__lambda_515_env_t* _env, int64_t a, int64_t b) { return howl_types_aterm_cmp(howl_sriqindex_fpart_at(_env->raw, a, _env->p0).t, howl_sriqindex_fpart_at(_env->raw, b, _env->p0).t); }

int64_t howl_sriqindex_entry_cmp(howl_sriqindex_Entry a, howl_sriqindex_Entry b) {
    if (a.side < b.side) {
        return -1;
    } else if (a.side > b.side) {
        return 1;
    } else {
        return howl_types_lit_cmp(a.lit, b.lit);
    }
}

int64_t howl_sriqindex_key_cmp(howl_sriqindex_Entry e, int64_t side, howl_types_Lit l) {
    if (e.side < side) {
        return -1;
    } else if (e.side > side) {
        return 1;
    } else {
        return howl_types_lit_cmp(e.lit, l);
    }
}

howl_sriqindex_Entry howl_sriqindex_entry_at(slop_list_howl_sriqindex_Entry es, int64_t k, howl_sriqindex_Entry fallback) {
    __auto_type _mv_496 = ({ __auto_type _lst = es; size_t _idx = (size_t)k; slop_option_howl_sriqindex_Entry _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_496.has_value) {
        __auto_type e = _mv_496.value;
        return e;
    } else if (!_mv_496.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_option_howl_sriqindex_Entry howl_sriqindex_key_of(howl_types_Clause c, int64_t i) {
    __auto_type _mv_497 = ({ __auto_type _lst = c.body; size_t _idx = (size_t)0; slop_option_howl_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_497.has_value) {
        __auto_type l = _mv_497.value;
        return (slop_option_howl_sriqindex_Entry){.has_value = 1, .value = ((howl_sriqindex_Entry){.side = 0, .lit = l, .i = i})};
    } else if (!_mv_497.has_value) {
        __auto_type _mv_498 = ({ __auto_type _lst = c.head; size_t _idx = (size_t)0; slop_option_howl_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_498.has_value) {
            __auto_type l = _mv_498.value;
            return (slop_option_howl_sriqindex_Entry){.has_value = 1, .value = ((howl_sriqindex_Entry){.side = 1, .lit = l, .i = i})};
        } else if (!_mv_498.has_value) {
            return (slop_option_howl_sriqindex_Entry){.has_value = false};
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

howl_sriqindex_SubIndex howl_sriqindex_sub_index(slop_arena* arena, slop_list_howl_types_Clause xs) {
    {
        __auto_type raw = ((slop_list_howl_sriqindex_Entry){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type sigs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t empty = -1;
        int64_t i = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                __auto_type _mv_499 = howl_sriqindex_key_of(c, i);
                if (_mv_499.has_value) {
                    __auto_type e = _mv_499.value;
                    ({ __auto_type _lst_p = &(raw); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_499.has_value) {
                    empty = i;
                }
                (void)(({ __auto_type _lst_p = &(sigs); __auto_type _item = (howl_sriqindex_clause_sig(c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                i = (i + 1);
            }
        }
        return ((howl_sriqindex_SubIndex){.xs = xs, .sigs = sigs, .entries = howl_sriqindex_sorted_entries(arena, raw), .empty = empty});
    }
}

int64_t howl_sriqindex_clause_sig(howl_types_Clause c) {
    {
        int64_t sg = 0;
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                sg = (sg | howl_sriqindex_lit_bit(0, l));
            }
        }
        {
            __auto_type _coll = c.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                sg = (sg | howl_sriqindex_lit_bit(1, l));
            }
        }
        return sg;
    }
}

int64_t howl_sriqindex_lit_bit(int64_t side, howl_types_Lit l) {
    {
        __auto_type h = (((side * 37) + (((int64_t)(l.pred)) * 131)) + ((howl_sriqindex_term_mix(l.t1) * 7) + howl_sriqindex_term_mix(l.t2)));
        return (((int64_t)(1)) << (h % 63));
    }
}

int64_t howl_sriqindex_term_mix(howl_types_ATerm t) {
    return ((((int64_t)(t.fsym)) * 17) + ((((int64_t)(t.cst)) * 29) + ((int64_t)(t.zi))));
}

int64_t howl_sriqindex_sig_at(howl_sriqindex_SubIndex ix, int64_t i) {
    __auto_type _mv_500 = ({ __auto_type _lst = ix.sigs; size_t _idx = (size_t)i; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_500.has_value) {
        __auto_type x = _mv_500.value;
        return x;
    } else if (!_mv_500.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_sriqindex_Entry howl_sriqindex_sorted_entries(slop_arena* arena, slop_list_howl_sriqindex_Entry raw) {
    __auto_type _mv_501 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_howl_sriqindex_Entry _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_501.has_value) {
        return raw;
    } else if (_mv_501.has_value) {
        __auto_type e0 = _mv_501.value;
        {
            __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ howl_sriqindex__lambda_502_env_t* howl_sriqindex__lambda_502_env = (howl_sriqindex__lambda_502_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqindex__lambda_502_env_t)); *howl_sriqindex__lambda_502_env = (howl_sriqindex__lambda_502_env_t){ .raw = raw, .e0 = e0 }; (slop_closure_t){ (void*)howl_sriqindex__lambda_502, (void*)howl_sriqindex__lambda_502_env }; }));
            __auto_type out = ((slop_list_howl_sriqindex_Entry){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = idx;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type k = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqindex_entry_at(raw, k, e0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            return out;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqindex_lower_bound(slop_list_howl_sriqindex_Entry es, int64_t side, howl_types_Lit l, howl_sriqindex_Entry fallback) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((es).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                if (howl_sriqindex_key_cmp(howl_sriqindex_entry_at(es, mid, fallback), side, l) < 0) {
                    lo = (mid + 1);
                } else {
                    hi = mid;
                }
            }
        }
        return lo;
    }
}

uint8_t howl_sriqindex_probe(howl_sriqindex_SubIndex ix, int64_t side, howl_types_Lit l, howl_types_Clause c, int64_t csig, int64_t skip) {
    __auto_type _mv_503 = ({ __auto_type _lst = ix.entries; size_t _idx = (size_t)0; slop_option_howl_sriqindex_Entry _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_503.has_value) {
        return 0;
    } else if (_mv_503.has_value) {
        __auto_type e0 = _mv_503.value;
        {
            __auto_type es = ix.entries;
            int64_t k = howl_sriqindex_lower_bound(ix.entries, side, l, e0);
            uint8_t found = 0;
            uint8_t going = 1;
            while ((going) && (!(found)) && ((k < ((int64_t)(((int64_t)((es).len))))))) {
                {
                    __auto_type e = howl_sriqindex_entry_at(es, k, e0);
                    going = (howl_sriqindex_key_cmp(e, side, l) == 0);
                    found = (going && howl_sriqindex_hit(ix, e, c, csig, skip));
                    k = (k + 1);
                }
            }
            return found;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqindex_hit(howl_sriqindex_SubIndex ix, howl_sriqindex_Entry e, howl_types_Clause c, int64_t csig, int64_t skip) {
    return (((e.i != skip)) && (((howl_sriqindex_sig_at(ix, e.i) & (csig ^ -1)) == 0)) && (howl_sriqindex_x_subsumes(ix, e.i, c)));
}

uint8_t howl_sriqindex_x_subsumes(howl_sriqindex_SubIndex ix, int64_t i, howl_types_Clause c) {
    __auto_type _mv_504 = ({ __auto_type _lst = ix.xs; size_t _idx = (size_t)i; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_504.has_value) {
        __auto_type x = _mv_504.value;
        return howl_sriqsubsume_subsumes(x, c);
    } else if (!_mv_504.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqindex_some_subsumes(howl_sriqindex_SubIndex ix, howl_types_Clause c, int64_t skip) {
    {
        __auto_type csig = howl_sriqindex_clause_sig(c);
        uint8_t found = ((ix.empty >= 0) && (ix.empty != skip));
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(found) && howl_sriqindex_probe(ix, 0, l, c, csig, skip)) {
                    found = 1;
                }
            }
        }
        {
            __auto_type _coll = c.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(found) && howl_sriqindex_probe(ix, 1, l, c, csig, skip)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_list_howl_types_Clause howl_sriqindex_distinct(slop_arena* arena, slop_list_howl_types_Clause cs) {
    __auto_type _mv_505 = ({ __auto_type _lst = cs; size_t _idx = (size_t)0; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_505.has_value) {
        return cs;
    } else if (_mv_505.has_value) {
        __auto_type c0 = _mv_505.value;
        {
            __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((cs).len)))), ({ howl_sriqindex__lambda_506_env_t* howl_sriqindex__lambda_506_env = (howl_sriqindex__lambda_506_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqindex__lambda_506_env_t)); *howl_sriqindex__lambda_506_env = (howl_sriqindex__lambda_506_env_t){ .cs = cs, .c0 = c0 }; (slop_closure_t){ (void*)howl_sriqindex__lambda_506, (void*)howl_sriqindex__lambda_506_env }; }));
            __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            uint8_t have = 0;
            __auto_type last = c0;
            {
                __auto_type _coll = idx;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type k = _coll.data[_i];
                    {
                        __auto_type c = howl_sriqindex_clause_of(cs, k, c0);
                        if (!((have && howl_sriqclauses_clause_eq(c, last)))) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            last = c;
                            have = 1;
                        }
                    }
                }
            }
            return out;
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_Clause howl_sriqindex_clause_of(slop_list_howl_types_Clause cs, int64_t k, howl_types_Clause fallback) {
    __auto_type _mv_507 = ({ __auto_type _lst = cs; size_t _idx = (size_t)k; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_507.has_value) {
        __auto_type c = _mv_507.value;
        return c;
    } else if (!_mv_507.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Clause howl_sriqindex_merged(slop_arena* arena, slop_list_howl_types_Clause a, slop_list_howl_types_Clause b) {
    {
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                while (({ __auto_type _mv = ({ __auto_type _lst = b; size_t _idx = (size_t)j; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type y = _mv.value; (howl_sriqclauses_clause_cmp(y, x) < 0); }) : (0); })) {
                    __auto_type _mv_508 = ({ __auto_type _lst = b; size_t _idx = (size_t)j; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_508.has_value) {
                        __auto_type y = _mv_508.value;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (y); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_508.has_value) {
                    }
                    j = (j + 1);
                }
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        while (j < ((int64_t)(((int64_t)((b).len))))) {
            __auto_type _mv_509 = ({ __auto_type _lst = b; size_t _idx = (size_t)j; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_509.has_value) {
                __auto_type y = _mv_509.value;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (y); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_509.has_value) {
            }
            j = (j + 1);
        }
        return out;
    }
}

howl_sriqsubsume_Committed howl_sriqindex_commit_indexed(slop_arena* arena, slop_list_howl_types_Clause ws, slop_list_howl_types_Clause cs) {
    {
        __auto_type wix = howl_sriqindex_sub_index(arena, ws);
        __auto_type c1 = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = howl_sriqindex_distinct(arena, cs);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!((howl_sriqsubsume_tautology(c) || howl_sriqindex_some_subsumes(wix, c, -1)))) {
                    (void)(({ __auto_type _lst_p = &(c1); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type c1ix = howl_sriqindex_sub_index(arena, c1);
            __auto_type c2 = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            int64_t i = 0;
            {
                __auto_type _coll = c1;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    if (!(howl_sriqindex_some_subsumes(c1ix, c, i))) {
                        (void)(({ __auto_type _lst_p = &(c2); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                    i = (i + 1);
                }
            }
            {
                __auto_type c2ix = howl_sriqindex_sub_index(arena, c2);
                __auto_type kept = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                {
                    __auto_type _coll = ws;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type w = _coll.data[_i];
                        if (!(howl_sriqindex_some_subsumes(c2ix, w, -1))) {
                            (void)(({ __auto_type _lst_p = &(kept); __auto_type _item = (w); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
                return ((howl_sriqsubsume_Committed){.set = howl_sriqindex_merged(arena, kept, c2), .added = c2});
            }
        }
    }
}

slop_option_howl_types_ATerm howl_sriqindex_fterm_key(howl_types_ATerm t) {
    if (t.kind == howl_types_AKind_ak_fx) {
        return (slop_option_howl_types_ATerm){.has_value = 1, .value = howl_types_at_fx(t.fsym)};
    } else if (t.kind == howl_types_AKind_ak_fu) {
        return (slop_option_howl_types_ATerm){.has_value = 1, .value = howl_types_at_fu(t.fsym, t.cst)};
    } else {
        return (slop_option_howl_types_ATerm){.has_value = false};
    }
}

howl_sriqindex_FPart howl_sriqindex_fpart_at(slop_list_howl_sriqindex_FPart ps, int64_t k, howl_sriqindex_FPart fallback) {
    __auto_type _mv_510 = ({ __auto_type _lst = ps; size_t _idx = (size_t)k; slop_option_howl_sriqindex_FPart _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_510.has_value) {
        __auto_type p = _mv_510.value;
        return p;
    } else if (!_mv_510.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

howl_sriqindex_KIdx howl_sriqindex_k_index(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriqctx_Triggers tr, slop_list_howl_types_Clause cs) {
    {
        __auto_type any = ((howl_sriq_SuccSig){.f = ((uint32_t)(0)), .root = 0, .u = ((uint32_t)(0))});
        __auto_type ground = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type raw = ((slop_list_howl_sriqindex_FPart){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type single = ((((int64_t)((c.body).len)) == 0) && (((int64_t)((c.head).len)) == 1));
                    int64_t i = 0;
                    {
                        __auto_type _coll = c.head;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type l = _coll.data[_i];
                            if (howl_sriqorder_maximal_at(arena, ord, c.head, i)) {
                                {
                                    __auto_type _coll = howl_sriqindex_fparts_of(arena, l, single);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type p = _coll.data[_i];
                                        (void)(({ __auto_type _lst_p = &(raw); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                    }
                                }
                                {
                                    __auto_type _coll = howl_sriqindex_ground_k2(arena, tr, any, l);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type a = _coll.data[_i];
                                        (void)(({ __auto_type _lst_p = &(ground); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                    }
                                }
                            }
                            i = (i + 1);
                        }
                    }
                }
            }
        }
        return ((howl_sriqindex_KIdx){.ground = howl_sriqclauses_lit_set(arena, ground), .fparts = howl_sriqindex_fparts_sorted(arena, raw)});
    }
}

howl_sriqindex_KIdx howl_sriqindex_k_index_premises(slop_arena* arena, howl_sriqctx_Triggers tr, slop_list_howl_sriq_Premise ps) {
    {
        __auto_type any = ((howl_sriq_SuccSig){.f = ((uint32_t)(0)), .root = 0, .u = ((uint32_t)(0))});
        __auto_type ground = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type raw = ((slop_list_howl_sriqindex_FPart){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (p.maxed) {
                    {
                        __auto_type _coll = howl_sriqindex_fparts_of(arena, p.sel, howl_sriqindex_unit_premise(p));
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type x = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(raw); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                    {
                        __auto_type _coll = howl_sriqindex_ground_k2(arena, tr, any, p.sel);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type a = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(ground); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        return ((howl_sriqindex_KIdx){.ground = howl_sriqclauses_lit_set(arena, ground), .fparts = howl_sriqindex_fparts_sorted(arena, raw)});
    }
}

uint8_t howl_sriqindex_unit_premise(howl_sriq_Premise p) {
    return ((((int64_t)((p.body).len)) == 0) && (((int64_t)((p.rest).len)) == 0));
}

slop_list_howl_types_Lit howl_sriqindex_ground_k2(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriq_SuccSig any, howl_types_Lit l) {
    {
        __auto_type a = howl_sriq_succ_pre(any, l);
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if ((howl_sriqindex_no_fterm(l)) && (a.ok) && (howl_sriqctx_in_su(tr, a.lit))) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (a.lit); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        return out;
    }
}

uint8_t howl_sriqindex_no_fterm(howl_types_Lit l) {
    return ((!((howl_sriqindex_fterm_key(l.t1)).has_value)) && ((l.form == howl_types_LitForm_lf_unary) || (!((howl_sriqindex_fterm_key(l.t2)).has_value))));
}

slop_list_howl_sriqindex_FPart howl_sriqindex_fparts_of(slop_arena* arena, howl_types_Lit l, uint8_t single) {
    {
        __auto_type out = ((slop_list_howl_sriqindex_FPart){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_511 = howl_sriqindex_fterm_key(l.t1);
        if (_mv_511.has_value) {
            __auto_type t = _mv_511.value;
            ({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqindex_FPart){.t = t, .lit = l, .single = single})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (!_mv_511.has_value) {
        }
        if (!((l.form == howl_types_LitForm_lf_unary))) {
            __auto_type _mv_512 = howl_sriqindex_fterm_key(l.t2);
            if (_mv_512.has_value) {
                __auto_type t = _mv_512.value;
                if (!(howl_sriqindex_first_is(out, t))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqindex_FPart){.t = t, .lit = l, .single = single})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            } else if (!_mv_512.has_value) {
            }
        }
        return out;
    }
}

uint8_t howl_sriqindex_first_is(slop_list_howl_sriqindex_FPart ps, howl_types_ATerm t) {
    __auto_type _mv_513 = ({ __auto_type _lst = ps; size_t _idx = (size_t)0; slop_option_howl_sriqindex_FPart _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_513.has_value) {
        __auto_type p = _mv_513.value;
        return (howl_types_aterm_cmp(p.t, t) == 0);
    } else if (!_mv_513.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_sriqindex_FPart howl_sriqindex_fparts_sorted(slop_arena* arena, slop_list_howl_sriqindex_FPart raw) {
    __auto_type _mv_514 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_howl_sriqindex_FPart _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_514.has_value) {
        return raw;
    } else if (_mv_514.has_value) {
        __auto_type p0 = _mv_514.value;
        {
            __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ howl_sriqindex__lambda_515_env_t* howl_sriqindex__lambda_515_env = (howl_sriqindex__lambda_515_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqindex__lambda_515_env_t)); *howl_sriqindex__lambda_515_env = (howl_sriqindex__lambda_515_env_t){ .raw = raw, .p0 = p0 }; (slop_closure_t){ (void*)howl_sriqindex__lambda_515, (void*)howl_sriqindex__lambda_515_env }; }));
            __auto_type out = ((slop_list_howl_sriqindex_FPart){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = idx;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type k = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqindex_fpart_at(raw, k, p0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            return out;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqindex_fpart_lower(slop_list_howl_sriqindex_FPart ps, howl_types_ATerm t, howl_sriqindex_FPart fallback) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((ps).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                if (howl_types_aterm_cmp(howl_sriqindex_fpart_at(ps, mid, fallback).t, t) < 0) {
                    lo = (mid + 1);
                } else {
                    hi = mid;
                }
            }
        }
        return lo;
    }
}

howl_sriq_KSets howl_sriqindex_k_query(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqindex_KIdx kx, howl_sriq_SuccSig sg) {
    {
        __auto_type t = ((sg.root) ? howl_types_at_fu(sg.f, sg.u) : howl_types_at_fx(sg.f));
        __auto_type fp = ({ __auto_type _mv = ({ __auto_type _lst = kx.fparts; size_t _idx = (size_t)0; slop_option_howl_sriqindex_FPart _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type p0 = _mv.value; howl_sriqindex_k_walk(arena, tr, kx, sg, t, p0); }) : (((howl_sriqindex_KPair){.k1 = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .k2 = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })})); });
        __auto_type k2 = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = kx.ground;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(k2); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = fp.k2;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(k2); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ((howl_sriq_KSets){.k1 = howl_sriqclauses_lit_set(arena, fp.k1), .k2 = howl_sriqclauses_lit_set(arena, k2)});
    }
}

howl_sriqindex_KPair howl_sriqindex_k_walk(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqindex_KIdx kx, howl_sriq_SuccSig sg, howl_types_ATerm t, howl_sriqindex_FPart p0) {
    {
        __auto_type ps = kx.fparts;
        int64_t k = howl_sriqindex_fpart_lower(kx.fparts, t, p0);
        __auto_type k1 = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type k2 = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        while ((k < ((int64_t)(((int64_t)((ps).len))))) && (howl_types_aterm_cmp(howl_sriqindex_fpart_at(ps, k, p0).t, t) == 0)) {
            {
                __auto_type p = howl_sriqindex_fpart_at(ps, k, p0);
                __auto_type a = howl_sriq_succ_pre(sg, howl_sriqindex_fpart_at(ps, k, p0).lit);
                if (a.ok && howl_sriqctx_in_su(tr, a.lit)) {
                    (void)(({ __auto_type _lst_p = &(k2); __auto_type _item = (a.lit); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    if (p.single && howl_sriqctx_mentions_x(a.lit)) {
                        (void)(({ __auto_type _lst_p = &(k1); __auto_type _item = (a.lit); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
                k = (k + 1);
            }
        }
        return ((howl_sriqindex_KPair){.k1 = k1, .k2 = k2});
    }
}

