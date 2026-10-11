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
uint32_t sriq_other_arg(uint32_t k);
types_ATerm sriq_arg_term(types_Lit l, uint32_t k);
uint8_t sriq_has_arg(types_Lit l, uint32_t k);
slop_option_types_ATerm sriq_inner_of(types_ATerm a);
slop_option_types_ATerm sriq_subterm_at(types_Lit l, sriq_Pos p);
types_ATerm sriq_with_inner(types_ATerm a, types_ATerm t);
types_Lit sriq_with_arg(types_Lit l, uint32_t k, types_ATerm t);
types_Lit sriq_replace_at(types_Lit l, sriq_Pos p, types_ATerm t);
types_ATerm sriq_replace_const(types_ATerm a, types_ATerm s, types_ATerm t);
types_Lit sriq_replace_all(types_Lit l, sriq_Pos p, types_ATerm s, types_ATerm t);
uint8_t sriq_side_ok(sriqorder_SriqOrder ord, types_Lit l, uint32_t k);
uint8_t sriq_kinds_are(types_ATerm a, types_ATerm b, types_AKind p, types_AKind q);
uint8_t sriq_eq_usable(types_ATerm s1, types_ATerm t1);
uint8_t sriq_plain(types_ATerm a);
uint8_t sriq_s2_plain(types_Lit l, sriq_Pos p);
uint8_t sriq_x_ok(types_Lit l, sriq_Pos p, types_ATerm s1);
uint8_t sriq_at_is(slop_option_types_ATerm o, types_ATerm s);
sriq_RConcl sriq_eq_rule(slop_arena* arena, sriqorder_SriqOrder ord, uint8_t root, sriq_Premise p1, uint32_t k1, sriq_Premise p2, sriq_Pos p);
sriq_BodyView sriq_body_at(slop_arena* arena, types_Clause c, int64_t i);
uint8_t sriq_ground(types_ATerm a);
uint8_t sriq_joinable(types_Lit a);
sriq_RConcl sriq_join_rule(slop_arena* arena, sriq_Premise p1, sriq_BodyView b);
uint8_t sriq_kid_ok(sriqorder_SriqOrder ord, uint32_t o, uint32_t sb2, uint32_t i, uint32_t k);
uint8_t sriq_kids_ok(sriqorder_SriqOrder ord, uint32_t o, uint32_t sb2, uint32_t n, slop_list_u32 kids);
slop_list_types_Lit sriq_nom_head(slop_arena* arena, slop_list_u32 kids);
uint8_t sriq_nom_premises(sriq_Premise p1, sriq_Premise p2, uint32_t b1, uint32_t sb2);
sriq_RConcl sriq_nom_rule(slop_arena* arena, sriqorder_SriqOrder ord, int64_t lam, uint32_t b1, uint32_t sb2, uint32_t n, sriq_Premise p1, sriq_Premise p2, slop_list_u32 kids);
int64_t sriq_depth_limit(int64_t tsu, int64_t tpr, int64_t omega, int64_t omega_d);
uint8_t sriq_lits_same(slop_list_types_Lit a, slop_list_types_Lit b);
uint8_t sriq_rconcl_eq(sriq_RConcl a, sriq_RConcl b);
uint8_t sriq_fires_is(sriq_RConcl a, sriq_RConcl b);
uint8_t sriq_hstate_eq(sriq_HState a, sriq_HState b);
types_ATerm sriq_ex_fx(int64_t f);
types_ATerm sriq_ex_u(int64_t u);
types_Lit sriq_ex_a1(int64_t b, types_ATerm t);
types_Lit sriq_ex_a2(int64_t r, types_ATerm a, types_ATerm b);
sriq_Pos sriq_ex_pos(int64_t k, uint8_t inner);
uint32_t sriq_ex_side(types_Lit l, types_ATerm s);
slop_list_types_Lit sriq_ex_l0(slop_arena* arena);
slop_list_types_Lit sriq_ex_l1(slop_arena* arena, types_Lit a);
slop_list_types_Lit sriq_ex_l2(slop_arena* arena, types_Lit a, types_Lit b);
slop_list_types_Lit sriq_ex_l3(slop_arena* arena, types_Lit a, types_Lit b, types_Lit c);
sriqorder_SriqOrder sriq_ex_ord(slop_arena* arena);
sriq_Premise sriq_ex_sel(slop_arena* arena, slop_list_types_Lit head, types_Lit l);
sriq_Premise sriq_ex_fac(slop_arena* arena);
sriq_BodyView sriq_ex_body(slop_arena* arena, slop_list_types_Lit body, slop_list_types_Lit head, types_Lit l);
sriq_RConcl sriq_ex_rc(slop_arena* arena, uint8_t fires, slop_list_types_Lit body, slop_list_types_Lit head);
sriq_HState sriq_ex_hs(slop_arena* arena, uint8_t fires, slop_list_types_Lit body, slop_list_types_Lit head);
sriqorder_SriqOrder sriq_ex_kids_ord(slop_arena* arena);
slop_list_u32 sriq_ex_ids(slop_arena* arena, int64_t k);

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
    SLOP_PRE((((i >= 0) && (i < ((int64_t)(((int64_t)((c.head).len))))))), "(and (>= i 0) (< i (cast Int (list-len (. c head)))))");
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
    types_ATerm _retval = {0};
    if (types_aterm_eq(l.t1, s)) {
        _retval = l.t2;
        goto _slop_post;
    } else {
        _retval = l.t1;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((({ types_ATerm _eq_l_1365 = (_retval); types_ATerm _eq_r_1366 = (l.t1); slop_eq_types_ATerm(&_eq_l_1365, &_eq_r_1366); }) || ({ types_ATerm _eq_l_1367 = (_retval); types_ATerm _eq_r_1368 = (l.t2); slop_eq_types_ATerm(&_eq_l_1367, &_eq_r_1368); }))), "(or (== $result (. l t1)) (== $result (. l t2)))");
    return _retval;
}

uint8_t sriq_holds_lit(slop_list_types_Lit ls, types_Lit l) {
    uint8_t _retval = {0};
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
        _retval = found;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

slop_list_types_Lit sriq_without_lit(slop_arena* arena, slop_list_types_Lit ls, types_Lit l) {
    slop_list_types_Lit _retval = {0};
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
        _retval = out;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
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
                    __auto_type _mv_1369 = ({ __auto_type _lst = sub.ts; size_t _idx = (size_t)k; slop_option_types_ATerm _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_1369.has_value) {
                        __auto_type t = _mv_1369.value;
                        found = (slop_option_types_ATerm){.has_value = 1, .value = t};
                    } else if (!_mv_1369.has_value) {
                    }
                }
                k = (k + 1);
            }
        }
        return found;
    }
}

uint8_t sriq_term_matches(sriq_Subst sub, types_ATerm a, types_ATerm l) {
    __auto_type _mv_1370 = a.kind;
    if (_mv_1370 == types_AKind_ak_x) {
        if (sub.xbound) {
            return types_aterm_eq(sub.x, l);
        } else {
            return (l.kind == types_AKind_ak_u);
        }
    } else if (_mv_1370 == types_AKind_ak_z) {
        __auto_type _mv_1371 = sriq_z_image(sub, ((int64_t)(a.zi)));
        if (_mv_1371.has_value) {
            __auto_type t = _mv_1371.value;
            return types_aterm_eq(t, l);
        } else if (!_mv_1371.has_value) {
            return 1;
        }
        SLOP_UNREACHABLE();
    } else if (_mv_1370 == types_AKind_ak_y) {
        return 0;
    } else if (_mv_1370 == types_AKind_ak_fx) {
        return 0;
    } else if (_mv_1370 == types_AKind_ak_u) {
        return 0;
    } else if (_mv_1370 == types_AKind_ak_fu) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

sriq_Subst sriq_bind_term(slop_arena* arena, sriq_Subst sub, types_ATerm a, types_ATerm l) {
    __auto_type _mv_1372 = a.kind;
    if (_mv_1372 == types_AKind_ak_x) {
        return ((sriq_Subst){.x = l, .xbound = 1, .zs = sub.zs, .ts = sub.ts});
    } else if (_mv_1372 == types_AKind_ak_z) {
        __auto_type _mv_1373 = sriq_z_image(sub, ((int64_t)(a.zi)));
        if (_mv_1373.has_value) {
            __auto_type _ = _mv_1373.value;
            return sub;
        } else if (!_mv_1373.has_value) {
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
    } else if (_mv_1372 == types_AKind_ak_y) {
        return sub;
    } else if (_mv_1372 == types_AKind_ak_fx) {
        return sub;
    } else if (_mv_1372 == types_AKind_ak_u) {
        return sub;
    } else if (_mv_1372 == types_AKind_ak_fu) {
        return sub;
    }
    SLOP_UNREACHABLE();
}

uint8_t sriq_atom_matches(sriq_Subst sub, types_Lit a, types_Lit l) {
    uint8_t _retval = {0};
    _retval = (((a.form == l.form)) && ((a.pred == l.pred)) && (((a.form == types_LitForm_lf_unary) || (a.form == types_LitForm_lf_binary))) && (sriq_term_matches(sub, a.t1, l.t1)) && (((a.form == types_LitForm_lf_unary) || (sriq_term_matches(sub, a.t2, l.t2) && (!(types_aterm_eq(a.t1, a.t2)) || types_aterm_eq(l.t1, l.t2))))));
    goto _slop_post;
    _slop_post: ;
    return _retval;
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
    sriq_HState _retval = {0};
    _retval = ((sriq_HState){.fires = 1, .sub = ((sriq_Subst){.x = x, .xbound = bound, .zs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .ts = ((slop_list_types_ATerm){ .data = NULL, .len = 0, .cap = 0, .arena = arena })}), .body = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .head = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST((((_retval.fires) && (({ types_ATerm _eq_l_1374 = (_retval.sub.x); types_ATerm _eq_r_1375 = (x); slop_eq_types_ATerm(&_eq_l_1374, &_eq_r_1375); })) && ((_retval.sub.xbound == bound)))), "(and (. $result fires) (== (. (. $result sub) x) x) (== (. (. $result sub) xbound) bound))");
    return _retval;
}

sriq_HState sriq_hyper_step(slop_arena* arena, sriq_HState st, types_Lit a, sriq_Premise p) {
    return ((sriq_HState){.fires = ((st.fires) && (p.maxed) && (sriq_atom_matches(st.sub, a, p.sel))), .sub = sriq_bind_atom(arena, st.sub, a, p.sel), .body = sriq_appended(arena, st.body, p.body), .head = sriq_appended(arena, st.head, p.rest)});
}

types_ATerm sriq_apply_term(sriq_Subst sub, types_ATerm t) {
    types_ATerm _retval = {0};
    __auto_type _mv_1376 = t.kind;
    if (_mv_1376 == types_AKind_ak_x) {
        _retval = sub.x;
        goto _slop_post;
    } else if (_mv_1376 == types_AKind_ak_z) {
        __auto_type _mv_1377 = sriq_z_image(sub, ((int64_t)(t.zi)));
        if (_mv_1377.has_value) {
            __auto_type v = _mv_1377.value;
            _retval = v;
            goto _slop_post;
        } else if (!_mv_1377.has_value) {
            _retval = t;
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    } else if (_mv_1376 == types_AKind_ak_fx) {
        if (sub.x.kind == types_AKind_ak_u) {
            _retval = types_at_fu(t.fsym, sub.x.cst);
            goto _slop_post;
        } else {
            _retval = t;
            goto _slop_post;
        }
    } else if (_mv_1376 == types_AKind_ak_y) {
        _retval = t;
        goto _slop_post;
    } else if (_mv_1376 == types_AKind_ak_u) {
        _retval = t;
        goto _slop_post;
    } else if (_mv_1376 == types_AKind_ak_fu) {
        _retval = t;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

types_Lit sriq_apply_lit(sriq_Subst sub, types_Lit l) {
    types_Lit _retval = {0};
    {
        __auto_type a = sriq_apply_term(sub, l.t1);
        __auto_type b = sriq_apply_term(sub, l.t2);
        __auto_type _mv_1378 = l.form;
        if (_mv_1378 == types_LitForm_lf_unary) {
            _retval = types_atom1(l.pred, a);
            goto _slop_post;
        } else if (_mv_1378 == types_LitForm_lf_binary) {
            _retval = types_atom2(l.pred, a, b);
            goto _slop_post;
        } else if (_mv_1378 == types_LitForm_lf_eq) {
            _retval = types_eq_lit(a, b);
            goto _slop_post;
        } else if (_mv_1378 == types_LitForm_lf_neq) {
            _retval = types_neq_lit(a, b);
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    }
    _slop_post: ;
    SLOP_POST(((_retval.form == l.form)), "(== (. $result form) (. l form))");
    return _retval;
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
                __auto_type _mv_1379 = ({ __auto_type _lst = cands; size_t _idx = (size_t)i; slop_option_sriq_Cands _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1379.has_value) {
                    __auto_type c = _mv_1379.value;
                    sts = sriq_extend_all(arena, sts, a, c.ps);
                } else if (!_mv_1379.has_value) {
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

uint32_t sriq_other_arg(uint32_t k) {
    uint32_t _retval = {0};
    if (k == ((uint32_t)(1))) {
        _retval = ((uint32_t)(2));
        goto _slop_post;
    } else {
        _retval = ((uint32_t)(1));
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((_retval == ((uint32_t)(1))) || (_retval == ((uint32_t)(2)))) && (_retval != k))), "(and (or (== $result (cast U32 1)) (== $result (cast U32 2))) (!= $result k))");
    return _retval;
}

types_ATerm sriq_arg_term(types_Lit l, uint32_t k) {
    types_ATerm _retval = {0};
    if (k == ((uint32_t)(1))) {
        _retval = l.t1;
        goto _slop_post;
    } else {
        _retval = l.t2;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((({ types_ATerm _eq_l_1380 = (_retval); types_ATerm _eq_r_1381 = (l.t1); slop_eq_types_ATerm(&_eq_l_1380, &_eq_r_1381); }) || ({ types_ATerm _eq_l_1382 = (_retval); types_ATerm _eq_r_1383 = (l.t2); slop_eq_types_ATerm(&_eq_l_1382, &_eq_r_1383); }))), "(or (== $result (. l t1)) (== $result (. l t2)))");
    return _retval;
}

uint8_t sriq_has_arg(types_Lit l, uint32_t k) {
    return ((k == ((uint32_t)(1))) || ((k == ((uint32_t)(2))) && !((l.form == types_LitForm_lf_unary))));
}

slop_option_types_ATerm sriq_inner_of(types_ATerm a) {
    __auto_type _mv_1384 = a.kind;
    if (_mv_1384 == types_AKind_ak_fx) {
        return (slop_option_types_ATerm){.has_value = 1, .value = types_at_x()};
    } else if (_mv_1384 == types_AKind_ak_fu) {
        return (slop_option_types_ATerm){.has_value = 1, .value = types_at_u(a.cst)};
    } else if (_mv_1384 == types_AKind_ak_x) {
        return (slop_option_types_ATerm){.has_value = false};
    } else if (_mv_1384 == types_AKind_ak_y) {
        return (slop_option_types_ATerm){.has_value = false};
    } else if (_mv_1384 == types_AKind_ak_z) {
        return (slop_option_types_ATerm){.has_value = false};
    } else if (_mv_1384 == types_AKind_ak_u) {
        return (slop_option_types_ATerm){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

slop_option_types_ATerm sriq_subterm_at(types_Lit l, sriq_Pos p) {
    if (!(sriq_has_arg(l, p.arg))) {
        return (slop_option_types_ATerm){.has_value = false};
    } else if (p.inner) {
        return sriq_inner_of(sriq_arg_term(l, p.arg));
    } else {
        return (slop_option_types_ATerm){.has_value = 1, .value = sriq_arg_term(l, p.arg)};
    }
}

types_ATerm sriq_with_inner(types_ATerm a, types_ATerm t) {
    if (!(((a.kind == types_AKind_ak_fx) || (a.kind == types_AKind_ak_fu)))) {
        return a;
    } else if (t.kind == types_AKind_ak_x) {
        return types_at_fx(a.fsym);
    } else if (t.kind == types_AKind_ak_u) {
        return types_at_fu(a.fsym, t.cst);
    } else {
        return a;
    }
}

types_Lit sriq_with_arg(types_Lit l, uint32_t k, types_ATerm t) {
    types_Lit _retval = {0};
    {
        __auto_type a = (((k == ((uint32_t)(1)))) ? t : l.t1);
        __auto_type b = (((k == ((uint32_t)(1)))) ? l.t2 : t);
        __auto_type _mv_1385 = l.form;
        if (_mv_1385 == types_LitForm_lf_unary) {
            _retval = types_atom1(l.pred, a);
            goto _slop_post;
        } else if (_mv_1385 == types_LitForm_lf_binary) {
            _retval = types_atom2(l.pred, a, b);
            goto _slop_post;
        } else if (_mv_1385 == types_LitForm_lf_eq) {
            _retval = types_eq_lit(a, b);
            goto _slop_post;
        } else if (_mv_1385 == types_LitForm_lf_neq) {
            _retval = types_neq_lit(a, b);
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    }
    _slop_post: ;
    SLOP_POST(((_retval.form == l.form)), "(== (. $result form) (. l form))");
    return _retval;
}

types_Lit sriq_replace_at(types_Lit l, sriq_Pos p, types_ATerm t) {
    types_Lit _retval = {0};
    {
        __auto_type a = sriq_arg_term(l, p.arg);
        _retval = sriq_with_arg(l, p.arg, ((p.inner) ? sriq_with_inner(a, t) : t));
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((_retval.form == l.form)), "(== (. $result form) (. l form))");
    return _retval;
}

types_ATerm sriq_replace_const(types_ATerm a, types_ATerm s, types_ATerm t) {
    types_ATerm _retval = {0};
    if (types_aterm_eq(a, s)) {
        _retval = t;
        goto _slop_post;
    } else if ((a.kind == types_AKind_ak_fu) && (a.cst == s.cst)) {
        _retval = sriq_with_inner(a, t);
        goto _slop_post;
    } else {
        _retval = a;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

types_Lit sriq_replace_all(types_Lit l, sriq_Pos p, types_ATerm s, types_ATerm t) {
    types_Lit _retval = {0};
    __auto_type _mv_1386 = l.form;
    if (_mv_1386 == types_LitForm_lf_unary) {
        _retval = types_atom1(l.pred, sriq_replace_const(l.t1, s, t));
        goto _slop_post;
    } else if (_mv_1386 == types_LitForm_lf_binary) {
        _retval = types_atom2(l.pred, sriq_replace_const(l.t1, s, t), sriq_replace_const(l.t2, s, t));
        goto _slop_post;
    } else if (_mv_1386 == types_LitForm_lf_eq) {
        _retval = sriq_with_arg(l, p.arg, sriq_replace_const(sriq_arg_term(l, p.arg), s, t));
        goto _slop_post;
    } else if (_mv_1386 == types_LitForm_lf_neq) {
        _retval = sriq_with_arg(l, p.arg, sriq_replace_const(sriq_arg_term(l, p.arg), s, t));
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST(((_retval.form == l.form)), "(== (. $result form) (. l form))");
    return _retval;
}

uint8_t sriq_side_ok(sriqorder_SriqOrder ord, types_Lit l, uint32_t k) {
    return (((l.form == types_LitForm_lf_unary)) || ((l.form == types_LitForm_lf_binary)) || (!(sriqorder_aterm_gt(ord, sriq_arg_term(l, sriq_other_arg(k)), sriq_arg_term(l, k)))));
}

uint8_t sriq_kinds_are(types_ATerm a, types_ATerm b, types_AKind p, types_AKind q) {
    return (((a.kind == p) && (b.kind == q)) || ((a.kind == q) && (b.kind == p)));
}

uint8_t sriq_eq_usable(types_ATerm s1, types_ATerm t1) {
    return !((sriq_kinds_are(s1, t1, types_AKind_ak_x, types_AKind_ak_y) || sriq_kinds_are(s1, t1, types_AKind_ak_y, types_AKind_ak_u)));
}

uint8_t sriq_plain(types_ATerm a) {
    return !((((a.kind == types_AKind_ak_fx)) || ((a.kind == types_AKind_ak_fu)) || ((a.kind == types_AKind_ak_y))));
}

uint8_t sriq_s2_plain(types_Lit l, sriq_Pos p) {
    __auto_type _mv_1387 = l.form;
    if (_mv_1387 == types_LitForm_lf_unary) {
        return sriq_plain(l.t1);
    } else if (_mv_1387 == types_LitForm_lf_binary) {
        return (sriq_plain(l.t1) && sriq_plain(l.t2));
    } else if (_mv_1387 == types_LitForm_lf_eq) {
        return sriq_plain(sriq_arg_term(l, p.arg));
    } else if (_mv_1387 == types_LitForm_lf_neq) {
        return sriq_plain(sriq_arg_term(l, p.arg));
    }
    SLOP_UNREACHABLE();
}

uint8_t sriq_x_ok(types_Lit l, sriq_Pos p, types_ATerm s1) {
    return (!((s1.kind == types_AKind_ak_x)) || sriq_s2_plain(l, p));
}

uint8_t sriq_at_is(slop_option_types_ATerm o, types_ATerm s) {
    __auto_type _mv_1388 = o;
    if (_mv_1388.has_value) {
        __auto_type t = _mv_1388.value;
        return types_aterm_eq(t, s);
    } else if (!_mv_1388.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

sriq_RConcl sriq_eq_rule(slop_arena* arena, sriqorder_SriqOrder ord, uint8_t root, sriq_Premise p1, uint32_t k1, sriq_Premise p2, sriq_Pos p) {
    SLOP_PRE(((((k1 == ((uint32_t)(1))) || (k1 == ((uint32_t)(2)))) && ((p.arg == ((uint32_t)(1))) || (p.arg == ((uint32_t)(2)))))), "(and (or (== k1 (cast U32 1)) (== k1 (cast U32 2))) (or (== (. p arg) (cast U32 1)) (== (. p arg) (cast U32 2))))");
    {
        __auto_type s1 = sriq_arg_term(p1.sel, k1);
        __auto_type t1 = sriq_arg_term(p1.sel, sriq_other_arg(k1));
        __auto_type l2 = p2.sel;
        __auto_type lit = (((root && (s1.kind == types_AKind_ak_u))) ? sriq_replace_all(l2, p, s1, t1) : sriq_replace_at(l2, p, t1));
        __auto_type h = sriq_appended(arena, p1.rest, p2.rest);
        ({ __auto_type _lst_p = &(h); __auto_type _item = (lit); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((sriq_RConcl){.fires = ((p1.maxed) && ((p1.sel.form == types_LitForm_lf_eq)) && (sriq_side_ok(ord, p1.sel, k1)) && (sriq_eq_usable(s1, t1)) && (p2.maxed) && (sriq_side_ok(ord, l2, p.arg)) && (sriq_at_is(sriq_subterm_at(l2, p), s1)) && (sriq_x_ok(l2, p, s1))), .body = sriq_appended(arena, p1.body, p2.body), .head = h});
    }
}

sriq_BodyView sriq_body_at(slop_arena* arena, types_Clause c, int64_t i) {
    SLOP_PRE((((i >= 0) && (i < ((int64_t)(((int64_t)((c.body).len))))))), "(and (>= i 0) (< i (cast Int (list-len (. c body)))))");
    return ((sriq_BodyView){.lit = sriq_lit_at(c.body, i), .rest = sriq_without_at(arena, c.body, i), .head = c.head});
}

uint8_t sriq_ground(types_ATerm a) {
    return ((a.kind == types_AKind_ak_u) || (a.kind == types_AKind_ak_fu));
}

uint8_t sriq_joinable(types_Lit a) {
    __auto_type _mv_1389 = a.form;
    if (_mv_1389 == types_LitForm_lf_unary) {
        return sriq_ground(a.t1);
    } else if (_mv_1389 == types_LitForm_lf_binary) {
        return (sriq_ground(a.t1) && sriq_ground(a.t2));
    } else if (_mv_1389 == types_LitForm_lf_eq) {
        return (((a.t1.kind == types_AKind_ak_u)) && ((a.t2.kind == types_AKind_ak_u)) && (!(types_aterm_eq(a.t1, a.t2))));
    } else if (_mv_1389 == types_LitForm_lf_neq) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

sriq_RConcl sriq_join_rule(slop_arena* arena, sriq_Premise p1, sriq_BodyView b) {
    return ((sriq_RConcl){.fires = ((p1.maxed) && (types_lit_eq(p1.sel, b.lit)) && (sriq_joinable(b.lit))), .body = sriq_appended(arena, p1.body, b.rest), .head = sriq_appended(arena, p1.rest, b.head)});
}

uint8_t sriq_kid_ok(sriqorder_SriqOrder ord, uint32_t o, uint32_t sb2, uint32_t i, uint32_t k) {
    {
        __auto_type e = sriqorder_const_entry(ord, k);
        return (((e.parent == o)) && ((e.srole == sb2)) && ((e.i == i)));
    }
}

uint8_t sriq_kids_ok(sriqorder_SriqOrder ord, uint32_t o, uint32_t sb2, uint32_t n, slop_list_u32 kids) {
    uint8_t _retval = {0};
    {
        uint32_t i = ((uint32_t)(1));
        uint8_t ok = (((int64_t)(((int64_t)((kids).len)))) == ((int64_t)(n)));
        {
            __auto_type _coll = kids;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                if (!(sriq_kid_ok(ord, o, sb2, i, k))) {
                    ok = 0;
                }
                i = (i + ((uint32_t)(1)));
            }
        }
        _retval = ok;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

slop_list_types_Lit sriq_nom_head(slop_arena* arena, slop_list_u32 kids) {
    slop_list_types_Lit _retval = {0};
    {
        __auto_type out = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = kids;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (types_eq_lit(types_at_x(), types_at_u(k))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        _retval = out;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

uint8_t sriq_nom_premises(sriq_Premise p1, sriq_Premise p2, uint32_t b1, uint32_t sb2) {
    {
        __auto_type a = p1.sel;
        __auto_type r = p2.sel;
        return (((a.form == types_LitForm_lf_unary)) && ((a.pred == b1)) && ((a.t1.kind == types_AKind_ak_u)) && ((r.form == types_LitForm_lf_binary)) && ((r.pred == sb2)) && (types_aterm_eq(r.t1, a.t1)) && ((r.t2.kind == types_AKind_ak_x)));
    }
}

sriq_RConcl sriq_nom_rule(slop_arena* arena, sriqorder_SriqOrder ord, int64_t lam, uint32_t b1, uint32_t sb2, uint32_t n, sriq_Premise p1, sriq_Premise p2, slop_list_u32 kids) {
    SLOP_PRE(((lam >= 0)), "(>= lam 0)");
    {
        __auto_type o = p1.sel.t1.cst;
        __auto_type h = sriq_appended(arena, p1.rest, p2.rest);
        {
            __auto_type _coll = sriq_nom_head(arena, kids);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                ({ __auto_type _lst_p = &(h); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((sriq_RConcl){.fires = ((p1.maxed) && (p2.maxed) && (sriq_nom_premises(p1, p2, b1, sb2)) && ((((int64_t)(sriqorder_const_entry(ord, o).len)) < lam)) && (sriq_kids_ok(ord, o, sb2, n, kids))), .body = sriq_appended(arena, p1.body, p2.body), .head = h});
    }
}

int64_t sriq_depth_limit(int64_t tsu, int64_t tpr, int64_t omega, int64_t omega_d) {
    SLOP_PRE(((((tsu >= 0)) && ((tsu <= 2147483648)) && ((tpr >= 0)) && ((tpr <= 2147483648)) && ((omega >= 0)) && ((omega <= 4611686018427387904)) && ((omega_d >= 1)) && ((omega_d <= 2147483648)))), "(and (>= tsu 0) (<= tsu 2147483648) (>= tpr 0) (<= tpr 2147483648) (>= omega 0) (<= omega 4611686018427387904) (>= omega-d 1) (<= omega-d 2147483648))");
    int64_t _retval = {0};
    {
        __auto_type k = (tsu + tpr);
        __auto_type m = (omega + omega_d);
        if (k >= 62) {
            _retval = 4611686018427387904;
            goto _slop_post;
        } else if (m > (4611686018427387904 >> k)) {
            _retval = 4611686018427387904;
            goto _slop_post;
        } else {
            _retval = (m << k);
            goto _slop_post;
        }
    }
    _slop_post: ;
    return _retval;
}

uint8_t sriq_lits_same(slop_list_types_Lit a, slop_list_types_Lit b) {
    {
        uint8_t ok = (((int64_t)((a).len)) == ((int64_t)((b).len)));
        int64_t i = 0;
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(types_lit_eq(l, sriq_lit_at(b, i)))) {
                    ok = 0;
                }
                i = (i + 1);
            }
        }
        return ok;
    }
}

uint8_t sriq_rconcl_eq(sriq_RConcl a, sriq_RConcl b) {
    if (a.fires == b.fires) {
        if (sriq_lits_same(a.body, b.body)) {
            return sriq_lits_same(a.head, b.head);
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

uint8_t sriq_fires_is(sriq_RConcl a, sriq_RConcl b) {
    return (a.fires == b.fires);
}

uint8_t sriq_hstate_eq(sriq_HState a, sriq_HState b) {
    if (a.fires == b.fires) {
        if (sriq_lits_same(a.body, b.body)) {
            return sriq_lits_same(a.head, b.head);
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

types_ATerm sriq_ex_fx(int64_t f) {
    return types_at_fx(((uint32_t)(f)));
}

types_ATerm sriq_ex_u(int64_t u) {
    return types_at_u(((uint32_t)(u)));
}

types_Lit sriq_ex_a1(int64_t b, types_ATerm t) {
    return types_atom1(((uint32_t)(b)), t);
}

types_Lit sriq_ex_a2(int64_t r, types_ATerm a, types_ATerm b) {
    return types_atom2(((uint32_t)(r)), a, b);
}

sriq_Pos sriq_ex_pos(int64_t k, uint8_t inner) {
    return ((sriq_Pos){.arg = ((uint32_t)(k)), .inner = inner});
}

uint32_t sriq_ex_side(types_Lit l, types_ATerm s) {
    if (types_aterm_eq(l.t1, s)) {
        return ((uint32_t)(1));
    } else {
        return ((uint32_t)(2));
    }
}

slop_list_types_Lit sriq_ex_l0(slop_arena* arena) {
    return ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
}

slop_list_types_Lit sriq_ex_l1(slop_arena* arena, types_Lit a) {
    {
        __auto_type out = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

slop_list_types_Lit sriq_ex_l2(slop_arena* arena, types_Lit a, types_Lit b) {
    {
        __auto_type out = sriq_ex_l1(arena, a);
        ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

slop_list_types_Lit sriq_ex_l3(slop_arena* arena, types_Lit a, types_Lit b, types_Lit c) {
    {
        __auto_type out = sriq_ex_l2(arena, a, b);
        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

sriqorder_SriqOrder sriq_ex_ord(slop_arena* arena) {
    return sriqorder_named_consts(arena, 3);
}

sriq_Premise sriq_ex_sel(slop_arena* arena, slop_list_types_Lit head, types_Lit l) {
    {
        __auto_type c = sriqclauses_make_clause(arena, ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), head);
        int64_t at = 0;
        int64_t i = 0;
        {
            __auto_type _coll = c.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type h = _coll.data[_i];
                if (types_lit_eq(h, l)) {
                    at = i;
                }
                i = (i + 1);
            }
        }
        return sriq_select(arena, sriq_ex_ord(arena), c, at);
    }
}

sriq_Premise sriq_ex_fac(slop_arena* arena) {
    return sriq_ex_sel(arena, sriq_ex_l2(arena, types_eq_lit(sriq_ex_fx(1), types_at_y()), types_eq_lit(sriq_ex_fx(1), sriq_ex_fx(0))), types_eq_lit(sriq_ex_fx(1), sriq_ex_fx(0)));
}

sriq_BodyView sriq_ex_body(slop_arena* arena, slop_list_types_Lit body, slop_list_types_Lit head, types_Lit l) {
    {
        __auto_type c = sriqclauses_make_clause(arena, body, head);
        int64_t at = 0;
        int64_t i = 0;
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                if (types_lit_eq(b, l)) {
                    at = i;
                }
                i = (i + 1);
            }
        }
        return sriq_body_at(arena, c, at);
    }
}

sriq_RConcl sriq_ex_rc(slop_arena* arena, uint8_t fires, slop_list_types_Lit body, slop_list_types_Lit head) {
    return ((sriq_RConcl){.fires = fires, .body = body, .head = head});
}

sriq_HState sriq_ex_hs(slop_arena* arena, uint8_t fires, slop_list_types_Lit body, slop_list_types_Lit head) {
    return ((sriq_HState){.fires = fires, .sub = sriq_hyper_start(arena, types_at_x(), 1).sub, .body = body, .head = head});
}

sriqorder_SriqOrder sriq_ex_kids_ord(slop_arena* arena) {
    {
        __auto_type base = sriqorder_named_consts(arena, 2);
        __auto_type cs = ((slop_list_sriqorder_ConstEntry){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = base.consts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                ({ __auto_type _lst_p = &(cs); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        ({ __auto_type _lst_p = &(cs); __auto_type _item = (sriqorder_aux_const(sriqorder_const_entry(base, ((uint32_t)(0))), ((uint32_t)(0)), ((uint32_t)(2)), ((uint32_t)(1)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((sriqorder_SriqOrder){.consts = cs});
    }
}

slop_list_u32 sriq_ex_ids(slop_arena* arena, int64_t k) {
    {
        __auto_type out = ((slop_list_u32){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (((uint32_t)(k))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

