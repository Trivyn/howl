#include "../runtime/slop_runtime.h"
#include "slop_sriqsubsume.h"

howl_types_Lit howl_sriqsubsume_no_lit(void);
howl_types_Lit howl_sriqsubsume_lit_at(slop_list_howl_types_Lit xs, int64_t i);
uint8_t howl_sriqsubsume_lits_subset(slop_list_howl_types_Lit a, slop_list_howl_types_Lit b);
uint8_t howl_sriqsubsume_subsumes(howl_types_Clause c, howl_types_Clause d);
uint8_t howl_sriqsubsume_reflexive_eq(howl_types_Lit l);
uint8_t howl_sriqsubsume_eq_of(howl_types_Lit n, howl_types_Lit e);
uint8_t howl_sriqsubsume_has_eq_of(slop_list_howl_types_Lit head, howl_types_Lit n);
uint8_t howl_sriqsubsume_taut_lit(slop_list_howl_types_Lit head, howl_types_Lit l);
uint8_t howl_sriqsubsume_tautology(howl_types_Clause c);
uint8_t howl_sriqsubsume_taut_in(slop_list_howl_types_Lit head);
uint8_t howl_sriqsubsume_in_hat(howl_types_Clause c, slop_list_howl_types_Clause ws);
howl_types_Clause howl_sriqsubsume_clause_at(slop_list_howl_types_Clause xs, int64_t i, howl_types_Clause fallback);
slop_list_howl_types_Clause howl_sriqsubsume_by_content(slop_arena* arena, slop_list_howl_types_Clause xs);
slop_list_howl_types_Clause howl_sriqsubsume_without_subsumed(slop_arena* arena, slop_list_howl_types_Clause ws, howl_types_Clause c);
uint8_t howl_sriqsubsume_holds_clause(slop_list_howl_types_Clause xs, howl_types_Clause c);
howl_sriqsubsume_Committed howl_sriqsubsume_commit_min(slop_arena* arena, slop_list_howl_types_Clause ws, slop_list_howl_types_Clause cs);

typedef struct { slop_list_howl_types_Clause xs; howl_types_Clause none_such; } howl_sriqsubsume__lambda_446_env_t;

static int64_t howl_sriqsubsume__lambda_446(howl_sriqsubsume__lambda_446_env_t* _env, int64_t i, int64_t j) { return howl_sriqclauses_clause_cmp(howl_sriqsubsume_clause_at(_env->xs, i, _env->none_such), howl_sriqsubsume_clause_at(_env->xs, j, _env->none_such)); }

howl_types_Lit howl_sriqsubsume_no_lit(void) {
    return howl_types_atom1(((uint32_t)(0)), howl_types_at_x());
}

howl_types_Lit howl_sriqsubsume_lit_at(slop_list_howl_types_Lit xs, int64_t i) {
    __auto_type _mv_444 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_444.has_value) {
        __auto_type l = _mv_444.value;
        return l;
    } else if (!_mv_444.has_value) {
        return howl_sriqsubsume_no_lit();
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqsubsume_lits_subset(slop_list_howl_types_Lit a, slop_list_howl_types_Lit b) {
    {
        __auto_type na = ((int64_t)(((int64_t)((a).len))));
        __auto_type nb = ((int64_t)(((int64_t)((b).len))));
        int64_t i = 0;
        int64_t j = 0;
        uint8_t ok = 1;
        while (ok && (i < na)) {
            {
                __auto_type l = howl_sriqsubsume_lit_at(a, i);
                while ((j < nb) && (howl_types_lit_cmp(howl_sriqsubsume_lit_at(b, j), l) < 0)) {
                    j = (j + 1);
                }
                if ((j < nb) && howl_types_lit_eq(howl_sriqsubsume_lit_at(b, j), l)) {
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

uint8_t howl_sriqsubsume_subsumes(howl_types_Clause c, howl_types_Clause d) {
    return (howl_sriqsubsume_lits_subset(c.body, d.body) && howl_sriqsubsume_lits_subset(c.head, d.head));
}

uint8_t howl_sriqsubsume_reflexive_eq(howl_types_Lit l) {
    return ((l.form == howl_types_LitForm_lf_eq) && howl_types_aterm_eq(l.t1, l.t2));
}

uint8_t howl_sriqsubsume_eq_of(howl_types_Lit n, howl_types_Lit e) {
    return (((n.form == howl_types_LitForm_lf_neq)) && ((e.form == howl_types_LitForm_lf_eq)) && (howl_types_aterm_eq(n.t1, e.t1)) && (howl_types_aterm_eq(n.t2, e.t2)));
}

uint8_t howl_sriqsubsume_has_eq_of(slop_list_howl_types_Lit head, howl_types_Lit n) {
    uint8_t _retval = {0};
    {
        uint8_t found = 0;
        {
            __auto_type _coll = head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (howl_sriqsubsume_eq_of(n, e)) {
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

uint8_t howl_sriqsubsume_taut_lit(slop_list_howl_types_Lit head, howl_types_Lit l) {
    return (howl_sriqsubsume_reflexive_eq(l) || howl_sriqsubsume_has_eq_of(head, l));
}

uint8_t howl_sriqsubsume_tautology(howl_types_Clause c) {
    return howl_sriqsubsume_taut_in(c.head);
}

uint8_t howl_sriqsubsume_taut_in(slop_list_howl_types_Lit head) {
    uint8_t _retval = {0};
    {
        uint8_t found = 0;
        {
            __auto_type _coll = head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (howl_sriqsubsume_taut_lit(head, l)) {
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

uint8_t howl_sriqsubsume_in_hat(howl_types_Clause c, slop_list_howl_types_Clause ws) {
    uint8_t _retval = {0};
    {
        uint8_t found = ((howl_sriqsubsume_tautology(c)) ? 1 : 0);
        {
            __auto_type _coll = ws;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type w = _coll.data[_i];
                if (howl_sriqsubsume_subsumes(w, c)) {
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

howl_types_Clause howl_sriqsubsume_clause_at(slop_list_howl_types_Clause xs, int64_t i, howl_types_Clause fallback) {
    __auto_type _mv_445 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_445.has_value) {
        __auto_type c = _mv_445.value;
        return c;
    } else if (!_mv_445.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Clause howl_sriqsubsume_by_content(slop_arena* arena, slop_list_howl_types_Clause xs) {
    {
        __auto_type none_such = ((howl_types_Clause){.body = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .head = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ howl_sriqsubsume__lambda_446_env_t* howl_sriqsubsume__lambda_446_env = (howl_sriqsubsume__lambda_446_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqsubsume__lambda_446_env_t)); *howl_sriqsubsume__lambda_446_env = (howl_sriqsubsume__lambda_446_env_t){ .xs = xs, .none_such = none_such }; (slop_closure_t){ (void*)howl_sriqsubsume__lambda_446, (void*)howl_sriqsubsume__lambda_446_env }; }));
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqsubsume_clause_at(xs, k, none_such)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_types_Clause howl_sriqsubsume_without_subsumed(slop_arena* arena, slop_list_howl_types_Clause ws, howl_types_Clause c) {
    slop_list_howl_types_Clause _retval = {0};
    {
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ws;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type w = _coll.data[_i];
                if (!(howl_sriqsubsume_subsumes(c, w))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (w); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        _retval = out;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriqsubsume_holds_clause(slop_list_howl_types_Clause xs, howl_types_Clause c) {
    uint8_t _retval = {0};
    {
        uint8_t found = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (howl_sriqclauses_clause_eq(x, c)) {
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

howl_sriqsubsume_Committed howl_sriqsubsume_commit_min(slop_arena* arena, slop_list_howl_types_Clause ws, slop_list_howl_types_Clause cs) {
    {
        __auto_type w = ws;
        __auto_type added = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(howl_sriqsubsume_in_hat(c, w))) {
                    w = howl_sriqsubsume_without_subsumed(arena, w, c);
                    (void)(({ __auto_type _lst_p = &(w); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type _coll = w;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (!(howl_sriqsubsume_holds_clause(ws, x))) {
                    (void)(({ __auto_type _lst_p = &(added); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return ((howl_sriqsubsume_Committed){.set = howl_sriqsubsume_by_content(arena, w), .added = howl_sriqsubsume_by_content(arena, added)});
    }
}

