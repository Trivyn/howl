#include "../runtime/slop_runtime.h"
#include "slop_sriqindex.h"

int64_t sriqindex_entry_cmp(sriqindex_Entry a, sriqindex_Entry b);
int64_t sriqindex_key_cmp(sriqindex_Entry e, int64_t side, types_Lit l);
sriqindex_Entry sriqindex_entry_at(slop_list_sriqindex_Entry es, int64_t k, sriqindex_Entry fallback);
slop_option_sriqindex_Entry sriqindex_key_of(types_Clause c, int64_t i);
sriqindex_SubIndex sriqindex_sub_index(slop_arena* arena, slop_list_types_Clause xs);
slop_list_sriqindex_Entry sriqindex_sorted_entries(slop_arena* arena, slop_list_sriqindex_Entry raw);
int64_t sriqindex_lower_bound(slop_list_sriqindex_Entry es, int64_t side, types_Lit l, sriqindex_Entry fallback);
uint8_t sriqindex_probe(sriqindex_SubIndex ix, int64_t side, types_Lit l, types_Clause c, int64_t skip);
uint8_t sriqindex_hit(sriqindex_SubIndex ix, sriqindex_Entry e, types_Clause c, int64_t skip);
uint8_t sriqindex_x_subsumes(sriqindex_SubIndex ix, int64_t i, types_Clause c);
uint8_t sriqindex_some_subsumes(sriqindex_SubIndex ix, types_Clause c, int64_t skip);
slop_list_types_Clause sriqindex_distinct(slop_arena* arena, slop_list_types_Clause cs);
types_Clause sriqindex_clause_of(slop_list_types_Clause cs, int64_t k, types_Clause fallback);
slop_list_types_Clause sriqindex_merged(slop_arena* arena, slop_list_types_Clause a, slop_list_types_Clause b);
sriqsubsume_Committed sriqindex_commit_indexed(slop_arena* arena, slop_list_types_Clause ws, slop_list_types_Clause cs);

typedef struct { slop_list_sriqindex_Entry raw; sriqindex_Entry e0; } sriqindex__lambda_1406_env_t;

static int64_t sriqindex__lambda_1406(sriqindex__lambda_1406_env_t* _env, int64_t a, int64_t b) { return sriqindex_entry_cmp(sriqindex_entry_at(_env->raw, a, _env->e0), sriqindex_entry_at(_env->raw, b, _env->e0)); }

typedef struct { slop_list_types_Clause cs; types_Clause c0; } sriqindex__lambda_1410_env_t;

static int64_t sriqindex__lambda_1410(sriqindex__lambda_1410_env_t* _env, int64_t a, int64_t b) { return sriqclauses_clause_cmp(sriqindex_clause_of(_env->cs, a, _env->c0), sriqindex_clause_of(_env->cs, b, _env->c0)); }

int64_t sriqindex_entry_cmp(sriqindex_Entry a, sriqindex_Entry b) {
    if (a.side < b.side) {
        return -1;
    } else if (a.side > b.side) {
        return 1;
    } else {
        return types_lit_cmp(a.lit, b.lit);
    }
}

int64_t sriqindex_key_cmp(sriqindex_Entry e, int64_t side, types_Lit l) {
    if (e.side < side) {
        return -1;
    } else if (e.side > side) {
        return 1;
    } else {
        return types_lit_cmp(e.lit, l);
    }
}

sriqindex_Entry sriqindex_entry_at(slop_list_sriqindex_Entry es, int64_t k, sriqindex_Entry fallback) {
    __auto_type _mv_1401 = ({ __auto_type _lst = es; size_t _idx = (size_t)k; slop_option_sriqindex_Entry _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1401.has_value) {
        __auto_type e = _mv_1401.value;
        return e;
    } else if (!_mv_1401.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_option_sriqindex_Entry sriqindex_key_of(types_Clause c, int64_t i) {
    __auto_type _mv_1402 = ({ __auto_type _lst = c.body; size_t _idx = (size_t)0; slop_option_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1402.has_value) {
        __auto_type l = _mv_1402.value;
        return (slop_option_sriqindex_Entry){.has_value = 1, .value = ((sriqindex_Entry){.side = 0, .lit = l, .i = i})};
    } else if (!_mv_1402.has_value) {
        __auto_type _mv_1403 = ({ __auto_type _lst = c.head; size_t _idx = (size_t)0; slop_option_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1403.has_value) {
            __auto_type l = _mv_1403.value;
            return (slop_option_sriqindex_Entry){.has_value = 1, .value = ((sriqindex_Entry){.side = 1, .lit = l, .i = i})};
        } else if (!_mv_1403.has_value) {
            return (slop_option_sriqindex_Entry){.has_value = false};
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

sriqindex_SubIndex sriqindex_sub_index(slop_arena* arena, slop_list_types_Clause xs) {
    {
        __auto_type raw = ((slop_list_sriqindex_Entry){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t empty = -1;
        int64_t i = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                __auto_type _mv_1404 = sriqindex_key_of(c, i);
                if (_mv_1404.has_value) {
                    __auto_type e = _mv_1404.value;
                    ({ __auto_type _lst_p = &(raw); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1404.has_value) {
                    empty = i;
                }
                i = (i + 1);
            }
        }
        return ((sriqindex_SubIndex){.xs = xs, .entries = sriqindex_sorted_entries(arena, raw), .empty = empty});
    }
}

slop_list_sriqindex_Entry sriqindex_sorted_entries(slop_arena* arena, slop_list_sriqindex_Entry raw) {
    __auto_type _mv_1405 = ({ __auto_type _lst = raw; size_t _idx = (size_t)0; slop_option_sriqindex_Entry _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1405.has_value) {
        return raw;
    } else if (_mv_1405.has_value) {
        __auto_type e0 = _mv_1405.value;
        {
            __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ sriqindex__lambda_1406_env_t* sriqindex__lambda_1406_env = (sriqindex__lambda_1406_env_t*)slop_arena_alloc(arena, sizeof(sriqindex__lambda_1406_env_t)); *sriqindex__lambda_1406_env = (sriqindex__lambda_1406_env_t){ .raw = raw, .e0 = e0 }; (slop_closure_t){ (void*)sriqindex__lambda_1406, (void*)sriqindex__lambda_1406_env }; }));
            __auto_type out = ((slop_list_sriqindex_Entry){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = idx;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type k = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqindex_entry_at(raw, k, e0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            return out;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t sriqindex_lower_bound(slop_list_sriqindex_Entry es, int64_t side, types_Lit l, sriqindex_Entry fallback) {
    {
        int64_t lo = 0;
        int64_t hi = ((int64_t)(((int64_t)((es).len))));
        while (lo < hi) {
            {
                __auto_type mid = ((lo + hi) / 2);
                if (sriqindex_key_cmp(sriqindex_entry_at(es, mid, fallback), side, l) < 0) {
                    lo = (mid + 1);
                } else {
                    hi = mid;
                }
            }
        }
        return lo;
    }
}

uint8_t sriqindex_probe(sriqindex_SubIndex ix, int64_t side, types_Lit l, types_Clause c, int64_t skip) {
    __auto_type _mv_1407 = ({ __auto_type _lst = ix.entries; size_t _idx = (size_t)0; slop_option_sriqindex_Entry _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1407.has_value) {
        return 0;
    } else if (_mv_1407.has_value) {
        __auto_type e0 = _mv_1407.value;
        {
            __auto_type es = ix.entries;
            int64_t k = sriqindex_lower_bound(ix.entries, side, l, e0);
            uint8_t found = 0;
            uint8_t going = 1;
            while ((going) && (!(found)) && ((k < ((int64_t)(((int64_t)((es).len))))))) {
                {
                    __auto_type e = sriqindex_entry_at(es, k, e0);
                    going = (sriqindex_key_cmp(e, side, l) == 0);
                    found = (going && sriqindex_hit(ix, e, c, skip));
                    k = (k + 1);
                }
            }
            return found;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqindex_hit(sriqindex_SubIndex ix, sriqindex_Entry e, types_Clause c, int64_t skip) {
    return ((e.i != skip) && sriqindex_x_subsumes(ix, e.i, c));
}

uint8_t sriqindex_x_subsumes(sriqindex_SubIndex ix, int64_t i, types_Clause c) {
    __auto_type _mv_1408 = ({ __auto_type _lst = ix.xs; size_t _idx = (size_t)i; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1408.has_value) {
        __auto_type x = _mv_1408.value;
        return sriqsubsume_subsumes(x, c);
    } else if (!_mv_1408.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqindex_some_subsumes(sriqindex_SubIndex ix, types_Clause c, int64_t skip) {
    {
        uint8_t found = ((ix.empty >= 0) && (ix.empty != skip));
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(found) && sriqindex_probe(ix, 0, l, c, skip)) {
                    found = 1;
                }
            }
        }
        {
            __auto_type _coll = c.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(found) && sriqindex_probe(ix, 1, l, c, skip)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_list_types_Clause sriqindex_distinct(slop_arena* arena, slop_list_types_Clause cs) {
    __auto_type _mv_1409 = ({ __auto_type _lst = cs; size_t _idx = (size_t)0; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1409.has_value) {
        return cs;
    } else if (_mv_1409.has_value) {
        __auto_type c0 = _mv_1409.value;
        {
            __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((cs).len)))), ({ sriqindex__lambda_1410_env_t* sriqindex__lambda_1410_env = (sriqindex__lambda_1410_env_t*)slop_arena_alloc(arena, sizeof(sriqindex__lambda_1410_env_t)); *sriqindex__lambda_1410_env = (sriqindex__lambda_1410_env_t){ .cs = cs, .c0 = c0 }; (slop_closure_t){ (void*)sriqindex__lambda_1410, (void*)sriqindex__lambda_1410_env }; }));
            __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            uint8_t have = 0;
            __auto_type last = c0;
            {
                __auto_type _coll = idx;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type k = _coll.data[_i];
                    {
                        __auto_type c = sriqindex_clause_of(cs, k, c0);
                        if (!((have && sriqclauses_clause_eq(c, last)))) {
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

types_Clause sriqindex_clause_of(slop_list_types_Clause cs, int64_t k, types_Clause fallback) {
    __auto_type _mv_1411 = ({ __auto_type _lst = cs; size_t _idx = (size_t)k; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1411.has_value) {
        __auto_type c = _mv_1411.value;
        return c;
    } else if (!_mv_1411.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_list_types_Clause sriqindex_merged(slop_arena* arena, slop_list_types_Clause a, slop_list_types_Clause b) {
    {
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = 0;
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                while (({ __auto_type _mv = ({ __auto_type _lst = b; size_t _idx = (size_t)j; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type y = _mv.value; (sriqclauses_clause_cmp(y, x) < 0); }) : (0); })) {
                    __auto_type _mv_1412 = ({ __auto_type _lst = b; size_t _idx = (size_t)j; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_1412.has_value) {
                        __auto_type y = _mv_1412.value;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (y); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_1412.has_value) {
                    }
                    j = (j + 1);
                }
                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        while (j < ((int64_t)(((int64_t)((b).len))))) {
            __auto_type _mv_1413 = ({ __auto_type _lst = b; size_t _idx = (size_t)j; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1413.has_value) {
                __auto_type y = _mv_1413.value;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (y); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_1413.has_value) {
            }
            j = (j + 1);
        }
        return out;
    }
}

sriqsubsume_Committed sriqindex_commit_indexed(slop_arena* arena, slop_list_types_Clause ws, slop_list_types_Clause cs) {
    {
        __auto_type wix = sriqindex_sub_index(arena, ws);
        __auto_type c1 = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = sriqindex_distinct(arena, cs);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!((sriqsubsume_tautology(c) || sriqindex_some_subsumes(wix, c, -1)))) {
                    ({ __auto_type _lst_p = &(c1); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type c1ix = sriqindex_sub_index(arena, c1);
            __auto_type c2 = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            int64_t i = 0;
            {
                __auto_type _coll = c1;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    if (!(sriqindex_some_subsumes(c1ix, c, i))) {
                        ({ __auto_type _lst_p = &(c2); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                    i = (i + 1);
                }
            }
            {
                __auto_type c2ix = sriqindex_sub_index(arena, c2);
                __auto_type kept = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                {
                    __auto_type _coll = ws;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type w = _coll.data[_i];
                        if (!(sriqindex_some_subsumes(c2ix, w, -1))) {
                            ({ __auto_type _lst_p = &(kept); __auto_type _item = (w); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                return ((sriqsubsume_Committed){.set = sriqindex_merged(arena, kept, c2), .added = c2});
            }
        }
    }
}

