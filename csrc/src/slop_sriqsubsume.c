#include "../runtime/slop_runtime.h"
#include "slop_sriqsubsume.h"

types_Lit sriqsubsume_no_lit(void);
types_Lit sriqsubsume_lit_at(slop_list_types_Lit xs, int64_t i);
uint8_t sriqsubsume_lits_subset(slop_list_types_Lit a, slop_list_types_Lit b);
uint8_t sriqsubsume_subsumes(types_Clause c, types_Clause d);
uint8_t sriqsubsume_reflexive_eq(types_Lit l);
uint8_t sriqsubsume_eq_of(types_Lit n, types_Lit e);
uint8_t sriqsubsume_has_eq_of(slop_list_types_Lit head, types_Lit n);
uint8_t sriqsubsume_tautology(types_Clause c);
uint8_t sriqsubsume_in_hat(types_Clause c, slop_list_types_Clause ws);
types_Clause sriqsubsume_clause_at(slop_list_types_Clause xs, int64_t i, types_Clause fallback);
slop_list_types_Clause sriqsubsume_by_content(slop_arena* arena, slop_list_types_Clause xs);
slop_list_types_Clause sriqsubsume_without_subsumed(slop_arena* arena, slop_list_types_Clause ws, types_Clause c);
uint8_t sriqsubsume_holds_clause(slop_list_types_Clause xs, types_Clause c);
sriqsubsume_Committed sriqsubsume_commit_min(slop_arena* arena, slop_list_types_Clause ws, slop_list_types_Clause cs);

typedef struct { slop_list_types_Clause xs; types_Clause none_such; } sriqsubsume__lambda_1376_env_t;

static int64_t sriqsubsume__lambda_1376(sriqsubsume__lambda_1376_env_t* _env, int64_t i, int64_t j) { return sriqclauses_clause_cmp(sriqsubsume_clause_at(_env->xs, i, _env->none_such), sriqsubsume_clause_at(_env->xs, j, _env->none_such)); }

types_Lit sriqsubsume_no_lit(void) {
    return types_atom1(((uint32_t)(0)), types_at_x());
}

types_Lit sriqsubsume_lit_at(slop_list_types_Lit xs, int64_t i) {
    __auto_type _mv_1374 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1374.has_value) {
        __auto_type l = _mv_1374.value;
        return l;
    } else if (!_mv_1374.has_value) {
        return sriqsubsume_no_lit();
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqsubsume_lits_subset(slop_list_types_Lit a, slop_list_types_Lit b) {
    {
        __auto_type na = ((int64_t)(((int64_t)((a).len))));
        __auto_type nb = ((int64_t)(((int64_t)((b).len))));
        int64_t i = 0;
        int64_t j = 0;
        uint8_t ok = 1;
        while (ok && (i < na)) {
            {
                __auto_type l = sriqsubsume_lit_at(a, i);
                while ((j < nb) && (types_lit_cmp(sriqsubsume_lit_at(b, j), l) < 0)) {
                    j = (j + 1);
                }
                if ((j < nb) && types_lit_eq(sriqsubsume_lit_at(b, j), l)) {
                    i = (i + 1);
                    j = (j + 1);
                } else {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t sriqsubsume_subsumes(types_Clause c, types_Clause d) {
    return (sriqsubsume_lits_subset(c.body, d.body) && sriqsubsume_lits_subset(c.head, d.head));
}

uint8_t sriqsubsume_reflexive_eq(types_Lit l) {
    return ((l.form == types_LitForm_lf_eq) && types_aterm_eq(l.t1, l.t2));
}

uint8_t sriqsubsume_eq_of(types_Lit n, types_Lit e) {
    return (((n.form == types_LitForm_lf_neq)) && ((e.form == types_LitForm_lf_eq)) && (types_aterm_eq(n.t1, e.t1)) && (types_aterm_eq(n.t2, e.t2)));
}

uint8_t sriqsubsume_has_eq_of(slop_list_types_Lit head, types_Lit n) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (sriqsubsume_eq_of(n, e)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t sriqsubsume_tautology(types_Clause c) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = c.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (sriqsubsume_reflexive_eq(l) || sriqsubsume_has_eq_of(c.head, l)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t sriqsubsume_in_hat(types_Clause c, slop_list_types_Clause ws) {
    uint8_t _retval = {0};
    {
        uint8_t found = ((sriqsubsume_tautology(c)) ? 1 : 0);
        {
            __auto_type _coll = ws;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type w = _coll.data[_i];
                if (sriqsubsume_subsumes(w, c)) {
                    found = 1;
                }
            }
        }
        _retval = found;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

types_Clause sriqsubsume_clause_at(slop_list_types_Clause xs, int64_t i, types_Clause fallback) {
    __auto_type _mv_1375 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1375.has_value) {
        __auto_type c = _mv_1375.value;
        return c;
    } else if (!_mv_1375.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_list_types_Clause sriqsubsume_by_content(slop_arena* arena, slop_list_types_Clause xs) {
    {
        __auto_type none_such = ((types_Clause){.body = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .head = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ sriqsubsume__lambda_1376_env_t* sriqsubsume__lambda_1376_env = (sriqsubsume__lambda_1376_env_t*)slop_arena_alloc(arena, sizeof(sriqsubsume__lambda_1376_env_t)); *sriqsubsume__lambda_1376_env = (sriqsubsume__lambda_1376_env_t){ .xs = xs, .none_such = none_such }; (slop_closure_t){ (void*)sriqsubsume__lambda_1376, (void*)sriqsubsume__lambda_1376_env }; }));
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqsubsume_clause_at(xs, k, none_such)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_Clause sriqsubsume_without_subsumed(slop_arena* arena, slop_list_types_Clause ws, types_Clause c) {
    {
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ws;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type w = _coll.data[_i];
                if (!(sriqsubsume_subsumes(c, w))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (w); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

uint8_t sriqsubsume_holds_clause(slop_list_types_Clause xs, types_Clause c) {
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

sriqsubsume_Committed sriqsubsume_commit_min(slop_arena* arena, slop_list_types_Clause ws, slop_list_types_Clause cs) {
    {
        __auto_type w = ws;
        __auto_type added = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(sriqsubsume_in_hat(c, w))) {
                    w = sriqsubsume_without_subsumed(arena, w, c);
                    ({ __auto_type _lst_p = &(w); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type _coll = w;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (!(sriqsubsume_holds_clause(ws, x))) {
                    ({ __auto_type _lst_p = &(added); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return ((sriqsubsume_Committed){.set = sriqsubsume_by_content(arena, w), .added = sriqsubsume_by_content(arena, added)});
    }
}

