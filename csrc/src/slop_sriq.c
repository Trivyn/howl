#include "../runtime/slop_runtime.h"
#include "slop_sriq.h"

types_Lit sriq_lit_at(slop_list_types_Lit xs, int64_t i);
slop_list_types_Lit sriq_without_at(slop_arena* arena, slop_list_types_Lit xs, int64_t i);
sriq_Premise sriq_select(slop_arena* arena, sriqorder_SriqOrder ord, types_Clause c, int64_t i);
types_Clause sriq_assemble(slop_arena* arena, sriq_RConcl r);
slop_list_types_Lit sriq_appended(slop_arena* arena, slop_list_types_Lit a, slop_list_types_Lit b);
sriq_RConcl sriq_core_rule(slop_arena* arena, types_Lit a);
sriq_RConcl sriq_ineq_rule(sriq_Premise p);
uint8_t sriq_has_side(types_Lit l, types_ATerm s);
types_ATerm sriq_other_side(types_Lit l, types_ATerm s);
uint8_t sriq_holds_lit(slop_list_types_Lit ls, types_Lit l);
slop_list_types_Lit sriq_without_lit(slop_arena* arena, slop_list_types_Lit ls, types_Lit l);
sriq_RConcl sriq_factor_rule(slop_arena* arena, sriqorder_SriqOrder ord, sriq_Premise p, types_Lit l1, types_ATerm s);
slop_option_types_ATerm sriq_z_image(sriq_Subst sub, int64_t i);
uint8_t sriq_term_matches(sriq_Subst sub, types_ATerm a, types_ATerm l);
sriq_Subst sriq_bind_term(slop_arena* arena, sriq_Subst sub, types_ATerm a, types_ATerm l);
uint8_t sriq_atom_matches(sriq_Subst sub, types_Lit a, types_Lit l);
sriq_Subst sriq_bind_atom(slop_arena* arena, sriq_Subst sub, types_Lit a, types_Lit l);
sriq_HState sriq_hyper_start(slop_arena* arena, types_ATerm x, uint8_t bound);
sriq_HState sriq_hyper_step(slop_arena* arena, sriq_HState st, types_Lit a, sriq_Premise p);
types_ATerm sriq_apply_term(sriq_Subst sub, types_ATerm t);
types_Lit sriq_apply_lit(sriq_Subst sub, types_Lit l);
sriq_RConcl sriq_hyper_finish(slop_arena* arena, sriq_HState st, slop_list_types_Lit delta);
slop_list_sriq_HState sriq_extend_one(slop_arena* arena, sriq_HState st, types_Lit a, slop_list_sriq_Premise ps);
slop_list_sriq_HState sriq_extend_all(slop_arena* arena, slop_list_sriq_HState sts, types_Lit a, slop_list_sriq_Premise ps);
slop_list_sriq_RConcl sriq_hyper_join(slop_arena* arena, sriq_HState start, slop_list_types_Lit atoms, slop_list_sriq_Cands cands, slop_list_types_Lit delta);

types_Lit sriq_lit_at(slop_list_types_Lit xs, int64_t i) {
    __auto_type _mv_1364 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1364.has_value) {
        __auto_type l = _mv_1364.value;
        return l;
    } else if (!_mv_1364.has_value) {
        return types_atom1(((uint32_t)(0)), types_at_x());
    }
    SLOP_UNREACHABLE();
}

slop_list_types_Lit sriq_without_at(slop_arena* arena, slop_list_types_Lit xs, int64_t i) {
    {
        __auto_type out = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (k != i) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                k = (k + 1);
            }
        }
        return out;
    }
}

sriq_Premise sriq_select(slop_arena* arena, sriqorder_SriqOrder ord, types_Clause c, int64_t i) {
    return ((sriq_Premise){.body = c.body, .sel = sriq_lit_at(c.head, i), .rest = sriq_without_at(arena, c.head, i), .maxed = sriqorder_maximal_at(arena, ord, c.head, i)});
}

types_Clause sriq_assemble(slop_arena* arena, sriq_RConcl r) {
    return sriqclauses_make_clause(arena, r.body, r.head);
}

slop_list_types_Lit sriq_appended(slop_arena* arena, slop_list_types_Lit a, slop_list_types_Lit b) {
    {
        __auto_type out = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = b;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

sriq_RConcl sriq_core_rule(slop_arena* arena, types_Lit a) {
    {
        __auto_type h = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(h); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((sriq_RConcl){.fires = 1, .body = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .head = h});
    }
}

sriq_RConcl sriq_ineq_rule(sriq_Premise p) {
    {
        __auto_type l = p.sel;
        return ((sriq_RConcl){.fires = ((l.form == types_LitForm_lf_neq) && types_aterm_eq(l.t1, l.t2)), .body = p.body, .head = p.rest});
    }
}

uint8_t sriq_has_side(types_Lit l, types_ATerm s) {
    return ((l.form == types_LitForm_lf_eq) && (types_aterm_eq(l.t1, s) || types_aterm_eq(l.t2, s)));
}

types_ATerm sriq_other_side(types_Lit l, types_ATerm s) {
    if (types_aterm_eq(l.t1, s)) {
        return l.t2;
    } else {
        return l.t1;
    }
}

uint8_t sriq_holds_lit(slop_list_types_Lit ls, types_Lit l) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = ls;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (types_lit_eq(x, l)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_list_types_Lit sriq_without_lit(slop_arena* arena, slop_list_types_Lit ls, types_Lit l) {
    {
        __auto_type out = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ls;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (!(types_lit_eq(x, l))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

sriq_RConcl sriq_factor_rule(slop_arena* arena, sriqorder_SriqOrder ord, sriq_Premise p, types_Lit l1, types_ATerm s) {
    {
        __auto_type t1 = sriq_other_side(l1, s);
        __auto_type t2 = sriq_other_side(p.sel, s);
        __auto_type h = sriq_without_lit(arena, p.rest, l1);
        ({ __auto_type _lst_p = &(h); __auto_type _item = (types_neq_lit(t1, t2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(h); __auto_type _item = (p.sel); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((sriq_RConcl){.fires = ((p.maxed) && (sriq_has_side(p.sel, s)) && (sriq_has_side(l1, s)) && (sriq_holds_lit(p.rest, l1)) && (!(sriqorder_aterm_gt(ord, t2, s)))), .body = p.body, .head = h});
    }
}

slop_option_types_ATerm sriq_z_image(sriq_Subst sub, int64_t i) {
    {
        int64_t k = 0;
        slop_option_types_ATerm found = (slop_option_types_ATerm){.has_value = false};
        {
            __auto_type _coll = sub.zs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type j = _coll.data[_i];
                if (j == i) {
                    __auto_type _mv_1365 = ({ __auto_type _lst = sub.ts; size_t _idx = (size_t)k; slop_option_types_ATerm _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_1365.has_value) {
                        __auto_type t = _mv_1365.value;
                        found = (slop_option_types_ATerm){.has_value = 1, .value = t};
                    } else if (!_mv_1365.has_value) {
                    }
                }
                k = (k + 1);
            }
        }
        return found;
    }
}

uint8_t sriq_term_matches(sriq_Subst sub, types_ATerm a, types_ATerm l) {
    __auto_type _mv_1366 = a.kind;
    if (_mv_1366 == types_AKind_ak_x) {
        if (sub.xbound) {
            return types_aterm_eq(sub.x, l);
        } else {
            return (l.kind == types_AKind_ak_u);
        }
    } else if (_mv_1366 == types_AKind_ak_z) {
        __auto_type _mv_1367 = sriq_z_image(sub, ((int64_t)(a.zi)));
        if (_mv_1367.has_value) {
            __auto_type t = _mv_1367.value;
            return types_aterm_eq(t, l);
        } else if (!_mv_1367.has_value) {
            return 1;
        }
        SLOP_UNREACHABLE();
    } else if (_mv_1366 == types_AKind_ak_y) {
        return 0;
    } else if (_mv_1366 == types_AKind_ak_fx) {
        return 0;
    } else if (_mv_1366 == types_AKind_ak_u) {
        return 0;
    } else if (_mv_1366 == types_AKind_ak_fu) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

sriq_Subst sriq_bind_term(slop_arena* arena, sriq_Subst sub, types_ATerm a, types_ATerm l) {
    __auto_type _mv_1368 = a.kind;
    if (_mv_1368 == types_AKind_ak_x) {
        return ((sriq_Subst){.x = l, .xbound = 1, .zs = sub.zs, .ts = sub.ts});
    } else if (_mv_1368 == types_AKind_ak_z) {
        __auto_type _mv_1369 = sriq_z_image(sub, ((int64_t)(a.zi)));
        if (_mv_1369.has_value) {
            __auto_type _ = _mv_1369.value;
            return sub;
        } else if (!_mv_1369.has_value) {
            {
                __auto_type zs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                __auto_type ts = ((slop_list_types_ATerm){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                {
                    __auto_type _coll = sub.zs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type j = _coll.data[_i];
                        ({ __auto_type _lst_p = &(zs); __auto_type _item = (j); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                {
                    __auto_type _coll = sub.ts;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type t = _coll.data[_i];
                        ({ __auto_type _lst_p = &(ts); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                ({ __auto_type _lst_p = &(zs); __auto_type _item = (((int64_t)(a.zi))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ts); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                return ((sriq_Subst){.x = sub.x, .xbound = sub.xbound, .zs = zs, .ts = ts});
            }
        }
        SLOP_UNREACHABLE();
    } else if (_mv_1368 == types_AKind_ak_y) {
        return sub;
    } else if (_mv_1368 == types_AKind_ak_fx) {
        return sub;
    } else if (_mv_1368 == types_AKind_ak_u) {
        return sub;
    } else if (_mv_1368 == types_AKind_ak_fu) {
        return sub;
    }
    SLOP_UNREACHABLE();
}

uint8_t sriq_atom_matches(sriq_Subst sub, types_Lit a, types_Lit l) {
    return (((a.form == l.form)) && ((a.pred == l.pred)) && (((a.form == types_LitForm_lf_unary) || (a.form == types_LitForm_lf_binary))) && (sriq_term_matches(sub, a.t1, l.t1)) && (((a.form == types_LitForm_lf_unary) || (sriq_term_matches(sub, a.t2, l.t2) && (!(types_aterm_eq(a.t1, a.t2)) || types_aterm_eq(l.t1, l.t2))))));
}

sriq_Subst sriq_bind_atom(slop_arena* arena, sriq_Subst sub, types_Lit a, types_Lit l) {
    {
        __auto_type s1 = sriq_bind_term(arena, sub, a.t1, l.t1);
        if (a.form == types_LitForm_lf_binary) {
            return sriq_bind_term(arena, s1, a.t2, l.t2);
        } else {
            return s1;
        }
    }
}

sriq_HState sriq_hyper_start(slop_arena* arena, types_ATerm x, uint8_t bound) {
    return ((sriq_HState){.fires = 1, .sub = ((sriq_Subst){.x = x, .xbound = bound, .zs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .ts = ((slop_list_types_ATerm){ .data = NULL, .len = 0, .cap = 0, .arena = arena })}), .body = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .head = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
}

sriq_HState sriq_hyper_step(slop_arena* arena, sriq_HState st, types_Lit a, sriq_Premise p) {
    return ((sriq_HState){.fires = ((st.fires) && (p.maxed) && (sriq_atom_matches(st.sub, a, p.sel))), .sub = sriq_bind_atom(arena, st.sub, a, p.sel), .body = sriq_appended(arena, st.body, p.body), .head = sriq_appended(arena, st.head, p.rest)});
}

types_ATerm sriq_apply_term(sriq_Subst sub, types_ATerm t) {
    __auto_type _mv_1370 = t.kind;
    if (_mv_1370 == types_AKind_ak_x) {
        return sub.x;
    } else if (_mv_1370 == types_AKind_ak_z) {
        __auto_type _mv_1371 = sriq_z_image(sub, ((int64_t)(t.zi)));
        if (_mv_1371.has_value) {
            __auto_type v = _mv_1371.value;
            return v;
        } else if (!_mv_1371.has_value) {
            return t;
        }
        SLOP_UNREACHABLE();
    } else if (_mv_1370 == types_AKind_ak_fx) {
        if (sub.x.kind == types_AKind_ak_u) {
            return types_at_fu(t.fsym, sub.x.cst);
        } else {
            return t;
        }
    } else if (_mv_1370 == types_AKind_ak_y) {
        return t;
    } else if (_mv_1370 == types_AKind_ak_u) {
        return t;
    } else if (_mv_1370 == types_AKind_ak_fu) {
        return t;
    }
    SLOP_UNREACHABLE();
}

types_Lit sriq_apply_lit(sriq_Subst sub, types_Lit l) {
    {
        __auto_type a = sriq_apply_term(sub, l.t1);
        __auto_type b = sriq_apply_term(sub, l.t2);
        __auto_type _mv_1372 = l.form;
        if (_mv_1372 == types_LitForm_lf_unary) {
            return types_atom1(l.pred, a);
        } else if (_mv_1372 == types_LitForm_lf_binary) {
            return types_atom2(l.pred, a, b);
        } else if (_mv_1372 == types_LitForm_lf_eq) {
            return types_eq_lit(a, b);
        } else if (_mv_1372 == types_LitForm_lf_neq) {
            return types_neq_lit(a, b);
        }
        SLOP_UNREACHABLE();
    }
}

sriq_RConcl sriq_hyper_finish(slop_arena* arena, sriq_HState st, slop_list_types_Lit delta) {
    {
        __auto_type h = sriq_appended(arena, st.head, ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        {
            __auto_type _coll = delta;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                ({ __auto_type _lst_p = &(h); __auto_type _item = (sriq_apply_lit(st.sub, l)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((sriq_RConcl){.fires = st.fires, .body = st.body, .head = h});
    }
}

slop_list_sriq_HState sriq_extend_one(slop_arena* arena, sriq_HState st, types_Lit a, slop_list_sriq_Premise ps) {
    slop_list_sriq_HState _retval = {0};
    {
        __auto_type out = ((slop_list_sriq_HState){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                {
                    __auto_type n = sriq_hyper_step(arena, st, a, p);
                    if (n.fires) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        _retval = out;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

slop_list_sriq_HState sriq_extend_all(slop_arena* arena, slop_list_sriq_HState sts, types_Lit a, slop_list_sriq_Premise ps) {
    {
        __auto_type out = ((slop_list_sriq_HState){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = sts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type st = _coll.data[_i];
                {
                    __auto_type _coll = sriq_extend_one(arena, st, a, ps);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type n = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

slop_list_sriq_RConcl sriq_hyper_join(slop_arena* arena, sriq_HState start, slop_list_types_Lit atoms, slop_list_sriq_Cands cands, slop_list_types_Lit delta) {
    {
        __auto_type sts = ((slop_list_sriq_HState){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        __auto_type out = ((slop_list_sriq_RConcl){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(sts); __auto_type _item = (start); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = atoms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_1373 = ({ __auto_type _lst = cands; size_t _idx = (size_t)i; slop_option_sriq_Cands _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1373.has_value) {
                    __auto_type c = _mv_1373.value;
                    sts = sriq_extend_all(arena, sts, a, c.ps);
                } else if (!_mv_1373.has_value) {
                    sts = ((slop_list_sriq_HState){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                }
                i = (i + 1);
            }
        }
        {
            __auto_type _coll = sts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type st = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriq_hyper_finish(arena, st, delta)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

