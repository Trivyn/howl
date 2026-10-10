#include "../runtime/slop_runtime.h"
#include "slop_sriqorder.h"

sriqorder_SriqOrder sriqorder_named_consts(slop_arena* arena, int64_t n);
sriqorder_ConstEntry sriqorder_aux_const(sriqorder_ConstEntry p, uint32_t pid, uint32_t s, uint32_t i);
sriqorder_ConstEntry sriqorder_const_entry(sriqorder_SriqOrder ord, uint32_t u);
uint8_t sriqorder_fn_gt(uint32_t f, uint32_t g);
int64_t sriqorder_cmp_u32(uint32_t a, uint32_t b);
int64_t sriqorder_letter_cmp(sriqorder_ConstEntry a, sriqorder_ConstEntry b);
int64_t sriqorder_label_cmp(sriqorder_SriqOrder ord, uint32_t a, uint32_t b);
uint8_t sriqorder_const_gt(sriqorder_SriqOrder ord, uint32_t a, uint32_t b);
uint8_t sriqorder_fx_over(sriqorder_SriqOrder ord, uint32_t f, types_ATerm b);
uint8_t sriqorder_fu_over(sriqorder_SriqOrder ord, uint32_t f, uint32_t u, types_ATerm b);
uint8_t sriqorder_aterm_gt(sriqorder_SriqOrder ord, types_ATerm a, types_ATerm b);
uint8_t sriqorder_aterm_same(types_ATerm a, types_ATerm b);
uint8_t sriqorder_aterm_ge(sriqorder_SriqOrder ord, types_ATerm a, types_ATerm b);
uint8_t sriqorder_pterm_gt(sriqorder_SriqOrder ord, types_Lit a, types_Lit b);
uint8_t sriqorder_pterm_over_aterm(sriqorder_SriqOrder ord, types_Lit a, types_ATerm s);
sriqorder_CTerm sriqorder_ct_true(void);
sriqorder_CTerm sriqorder_ct_a(types_ATerm s);
sriqorder_CTerm sriqorder_ct_p(types_Lit l);
uint8_t sriqorder_cterm_gt(sriqorder_SriqOrder ord, sriqorder_CTerm s, sriqorder_CTerm t);
uint8_t sriqorder_cterm_same(sriqorder_CTerm s, sriqorder_CTerm t);
slop_list_sriqorder_CTerm sriqorder_lit_ms(slop_arena* arena, types_Lit l);
slop_list_sriqorder_CTerm sriqorder_take_one(slop_arena* arena, slop_list_sriqorder_CTerm xs, sriqorder_CTerm y);
slop_list_sriqorder_CTerm sriqorder_ms_minus(slop_arena* arena, slop_list_sriqorder_CTerm xs, slop_list_sriqorder_CTerm ys);
uint8_t sriqorder_dominated(sriqorder_SriqOrder ord, slop_list_sriqorder_CTerm bs, sriqorder_CTerm a);
uint8_t sriqorder_mul_gt(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_sriqorder_CTerm m1, slop_list_sriqorder_CTerm m2);
uint8_t sriqorder_lit_gt(slop_arena* arena, sriqorder_SriqOrder ord, types_Lit l1, types_Lit l2);
uint8_t sriqorder_maximal_at(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Lit ls, int64_t i);
slop_list_u8 sriqorder_max_flags(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Lit ls);

sriqorder_SriqOrder sriqorder_named_consts(slop_arena* arena, int64_t n) {
    {
        __auto_type cs = ((slop_list_sriqorder_ConstEntry){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        while (k < n) {
            ({ __auto_type _lst_p = &(cs); __auto_type _item = (((sriqorder_ConstEntry){.base = ((uint32_t)(k)), .parent = ((uint32_t)(k)), .srole = ((uint32_t)(0)), .i = ((uint32_t)(0)), .len = ((uint32_t)(0))})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            k = (k + 1);
        }
        return ((sriqorder_SriqOrder){.consts = cs});
    }
}

sriqorder_ConstEntry sriqorder_aux_const(sriqorder_ConstEntry p, uint32_t pid, uint32_t s, uint32_t i) {
    return ((sriqorder_ConstEntry){.base = p.base, .parent = pid, .srole = s, .i = i, .len = (p.len + ((uint32_t)(1)))});
}

sriqorder_ConstEntry sriqorder_const_entry(sriqorder_SriqOrder ord, uint32_t u) {
    __auto_type _mv_1355 = ({ __auto_type _lst = ord.consts; size_t _idx = (size_t)((int64_t)(u)); slop_option_sriqorder_ConstEntry _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1355.has_value) {
        __auto_type e = _mv_1355.value;
        return e;
    } else if (!_mv_1355.has_value) {
        return ((sriqorder_ConstEntry){.base = u, .parent = u, .srole = ((uint32_t)(0)), .i = ((uint32_t)(0)), .len = ((uint32_t)(0))});
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqorder_fn_gt(uint32_t f, uint32_t g) {
    uint8_t _retval = {0};
    _retval = (f > g);
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval == (f > g))), "(== $result (> f g))");
    return _retval;
}

int64_t sriqorder_cmp_u32(uint32_t a, uint32_t b) {
    int64_t _retval = {0};
    if (a < b) {
        _retval = -1;
        goto _slop_post;
    } else if (a > b) {
        _retval = 1;
        goto _slop_post;
    } else {
        _retval = 0;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((_retval >= -1)), "(>= $result -1)");
    SLOP_POST(((_retval <= 1)), "(<= $result 1)");
    return _retval;
}

int64_t sriqorder_letter_cmp(sriqorder_ConstEntry a, sriqorder_ConstEntry b) {
    if (a.srole != b.srole) {
        return sriqorder_cmp_u32(a.srole, b.srole);
    } else {
        return sriqorder_cmp_u32(a.i, b.i);
    }
}

int64_t sriqorder_label_cmp(sriqorder_SriqOrder ord, uint32_t a, uint32_t b) {
    {
        uint32_t x = a;
        uint32_t y = b;
        int64_t r = 0;
        int64_t k = ((int64_t)(sriqorder_const_entry(ord, a).len));
        while (k > 0) {
            {
                __auto_type ex = sriqorder_const_entry(ord, x);
                __auto_type ey = sriqorder_const_entry(ord, y);
                __auto_type c = sriqorder_letter_cmp(ex, ey);
                if (c != 0) {
                    r = c;
                }
                x = ex.parent;
                y = ey.parent;
                k = (k - 1);
            }
        }
        return r;
    }
}

uint8_t sriqorder_const_gt(sriqorder_SriqOrder ord, uint32_t a, uint32_t b) {
    uint8_t _retval = {0};
    if (a == b) {
        _retval = 0;
        goto _slop_post;
    } else {
        {
            __auto_type ea = sriqorder_const_entry(ord, a);
            __auto_type eb = sriqorder_const_entry(ord, b);
            if (ea.len != eb.len) {
                _retval = (ea.len > eb.len);
                goto _slop_post;
            } else if (ea.base != eb.base) {
                _retval = (ea.base > eb.base);
                goto _slop_post;
            } else {
                _retval = (sriqorder_label_cmp(ord, a, b) > 0);
                goto _slop_post;
            }
        }
    }
    _slop_post: ;
    return _retval;
}

uint8_t sriqorder_fx_over(sriqorder_SriqOrder ord, uint32_t f, types_ATerm b) {
    uint8_t _retval = {0};
    __auto_type _mv_1356 = b.kind;
    if (_mv_1356 == types_AKind_ak_x) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_1356 == types_AKind_ak_y) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_1356 == types_AKind_ak_z) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_1356 == types_AKind_ak_fx) {
        _retval = sriqorder_fn_gt(f, b.fsym);
        goto _slop_post;
    } else if (_mv_1356 == types_AKind_ak_u) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_1356 == types_AKind_ak_fu) {
        _retval = sriqorder_fn_gt(f, b.fsym);
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

uint8_t sriqorder_fu_over(sriqorder_SriqOrder ord, uint32_t f, uint32_t u, types_ATerm b) {
    uint8_t _retval = {0};
    __auto_type _mv_1357 = b.kind;
    if (_mv_1357 == types_AKind_ak_x) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_1357 == types_AKind_ak_y) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_1357 == types_AKind_ak_z) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_1357 == types_AKind_ak_fx) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_1357 == types_AKind_ak_u) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_1357 == types_AKind_ak_fu) {
        _retval = (sriqorder_fn_gt(f, b.fsym) || ((f == b.fsym) && sriqorder_const_gt(ord, u, b.cst)));
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

uint8_t sriqorder_aterm_gt(sriqorder_SriqOrder ord, types_ATerm a, types_ATerm b) {
    uint8_t _retval = {0};
    __auto_type _mv_1358 = a.kind;
    if (_mv_1358 == types_AKind_ak_x) {
        _retval = (b.kind == types_AKind_ak_y);
        goto _slop_post;
    } else if (_mv_1358 == types_AKind_ak_y) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_1358 == types_AKind_ak_z) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_1358 == types_AKind_ak_fx) {
        _retval = sriqorder_fx_over(ord, a.fsym, b);
        goto _slop_post;
    } else if (_mv_1358 == types_AKind_ak_u) {
        _retval = ((b.kind == types_AKind_ak_u) && sriqorder_const_gt(ord, a.cst, b.cst));
        goto _slop_post;
    } else if (_mv_1358 == types_AKind_ak_fu) {
        _retval = sriqorder_fu_over(ord, a.fsym, a.cst, b);
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

uint8_t sriqorder_aterm_same(types_ATerm a, types_ATerm b) {
    return (((a.kind == b.kind)) && ((a.fsym == b.fsym)) && ((a.cst == b.cst)) && ((a.zi == b.zi)));
}

uint8_t sriqorder_aterm_ge(sriqorder_SriqOrder ord, types_ATerm a, types_ATerm b) {
    return (sriqorder_aterm_same(a, b) || sriqorder_aterm_gt(ord, a, b));
}

uint8_t sriqorder_pterm_gt(sriqorder_SriqOrder ord, types_Lit a, types_Lit b) {
    uint8_t _retval = {0};
    if ((a.form != b.form) || (a.pred != b.pred)) {
        _retval = 0;
        goto _slop_post;
    } else if (a.form == types_LitForm_lf_unary) {
        _retval = sriqorder_aterm_gt(ord, a.t1, b.t1);
        goto _slop_post;
    } else {
        _retval = ((sriqorder_aterm_ge(ord, a.t1, b.t1)) && (sriqorder_aterm_ge(ord, a.t2, b.t2)) && (!((sriqorder_aterm_same(a.t1, b.t1) && sriqorder_aterm_same(a.t2, b.t2)))));
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

uint8_t sriqorder_pterm_over_aterm(sriqorder_SriqOrder ord, types_Lit a, types_ATerm s) {
    uint8_t _retval = {0};
    _retval = (((s.kind == types_AKind_ak_x)) || ((s.kind == types_AKind_ak_y)) || (sriqorder_aterm_ge(ord, a.t1, s)) || (((a.form == types_LitForm_lf_binary) && sriqorder_aterm_ge(ord, a.t2, s))));
    goto _slop_post;
    _slop_post: ;
    return _retval;
}

sriqorder_CTerm sriqorder_ct_true(void) {
    return ((sriqorder_CTerm){.ck = sriqorder_CKind_ck_true, .a = types_at_x(), .p = types_atom1(((uint32_t)(0)), types_at_x())});
}

sriqorder_CTerm sriqorder_ct_a(types_ATerm s) {
    return ((sriqorder_CTerm){.ck = sriqorder_CKind_ck_a, .a = s, .p = types_atom1(((uint32_t)(0)), types_at_x())});
}

sriqorder_CTerm sriqorder_ct_p(types_Lit l) {
    return ((sriqorder_CTerm){.ck = sriqorder_CKind_ck_p, .a = types_at_x(), .p = l});
}

uint8_t sriqorder_cterm_gt(sriqorder_SriqOrder ord, sriqorder_CTerm s, sriqorder_CTerm t) {
    uint8_t _retval = {0};
    __auto_type _mv_1359 = s.ck;
    if (_mv_1359 == sriqorder_CKind_ck_true) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_1359 == sriqorder_CKind_ck_a) {
        __auto_type _mv_1360 = t.ck;
        if (_mv_1360 == sriqorder_CKind_ck_true) {
            _retval = 1;
            goto _slop_post;
        } else if (_mv_1360 == sriqorder_CKind_ck_a) {
            _retval = sriqorder_aterm_gt(ord, s.a, t.a);
            goto _slop_post;
        } else if (_mv_1360 == sriqorder_CKind_ck_p) {
            _retval = 0;
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    } else if (_mv_1359 == sriqorder_CKind_ck_p) {
        __auto_type _mv_1361 = t.ck;
        if (_mv_1361 == sriqorder_CKind_ck_true) {
            _retval = 1;
            goto _slop_post;
        } else if (_mv_1361 == sriqorder_CKind_ck_a) {
            _retval = sriqorder_pterm_over_aterm(ord, s.p, t.a);
            goto _slop_post;
        } else if (_mv_1361 == sriqorder_CKind_ck_p) {
            _retval = sriqorder_pterm_gt(ord, s.p, t.p);
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

uint8_t sriqorder_cterm_same(sriqorder_CTerm s, sriqorder_CTerm t) {
    return ((s.ck == t.ck) && ({ __auto_type _mv = s.ck; int _mi = (_mv == sriqorder_CKind_ck_true) ? 1 : (_mv == sriqorder_CKind_ck_a) ? 2 : (_mv == sriqorder_CKind_ck_p) ? 3 : 0; if (!_mi) { SLOP_UNREACHABLE(); } _mi == 1 ? (1) : _mi == 2 ? (sriqorder_aterm_same(s.a, t.a)) : ((((s.p.form == t.p.form)) && ((s.p.pred == t.p.pred)) && (sriqorder_aterm_same(s.p.t1, t.p.t1)) && (sriqorder_aterm_same(s.p.t2, t.p.t2)))); }));
}

slop_list_sriqorder_CTerm sriqorder_lit_ms(slop_arena* arena, types_Lit l) {
    {
        __auto_type out = ((slop_list_sriqorder_CTerm){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1362 = l.form;
        if (_mv_1362 == types_LitForm_lf_unary) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqorder_ct_p(l)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqorder_ct_true()); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (_mv_1362 == types_LitForm_lf_binary) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqorder_ct_p(l)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqorder_ct_true()); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (_mv_1362 == types_LitForm_lf_eq) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqorder_ct_a(l.t1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqorder_ct_a(l.t2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (_mv_1362 == types_LitForm_lf_neq) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqorder_ct_a(l.t1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqorder_ct_a(l.t1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqorder_ct_a(l.t2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqorder_ct_a(l.t2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return out;
    }
}

slop_list_sriqorder_CTerm sriqorder_take_one(slop_arena* arena, slop_list_sriqorder_CTerm xs, sriqorder_CTerm y) {
    {
        __auto_type out = ((slop_list_sriqorder_CTerm){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t taken = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (!(taken) && sriqorder_cterm_same(x, y)) {
                    taken = 1;
                } else {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

slop_list_sriqorder_CTerm sriqorder_ms_minus(slop_arena* arena, slop_list_sriqorder_CTerm xs, slop_list_sriqorder_CTerm ys) {
    {
        __auto_type out = xs;
        {
            __auto_type _coll = ys;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type y = _coll.data[_i];
                out = sriqorder_take_one(arena, out, y);
            }
        }
        return out;
    }
}

uint8_t sriqorder_dominated(sriqorder_SriqOrder ord, slop_list_sriqorder_CTerm bs, sriqorder_CTerm a) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = bs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                if (sriqorder_cterm_gt(ord, b, a)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t sriqorder_mul_gt(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_sriqorder_CTerm m1, slop_list_sriqorder_CTerm m2) {
    {
        __auto_type d1 = sriqorder_ms_minus(arena, m1, m2);
        __auto_type d2 = sriqorder_ms_minus(arena, m2, m1);
        uint8_t ok = ((((int64_t)((d1).len)) > 0) || (((int64_t)((d2).len)) > 0));
        {
            __auto_type _coll = d2;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (!(sriqorder_dominated(ord, d1, a))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t sriqorder_lit_gt(slop_arena* arena, sriqorder_SriqOrder ord, types_Lit l1, types_Lit l2) {
    return sriqorder_mul_gt(arena, ord, sriqorder_lit_ms(arena, l1), sriqorder_lit_ms(arena, l2));
}

uint8_t sriqorder_maximal_at(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Lit ls, int64_t i) {
    __auto_type _mv_1363 = ({ __auto_type _lst = ls; size_t _idx = (size_t)i; slop_option_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1363.has_value) {
        return 0;
    } else if (_mv_1363.has_value) {
        __auto_type l = _mv_1363.value;
        {
            uint8_t ok = 1;
            int64_t j = 0;
            {
                __auto_type _coll = ls;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type m = _coll.data[_i];
                    if ((j != i) && sriqorder_lit_gt(arena, ord, m, l)) {
                        ok = 0;
                    }
                    j = (j + 1);
                }
            }
            return ok;
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_u8 sriqorder_max_flags(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Lit ls) {
    {
        __auto_type out = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = ls;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqorder_maximal_at(arena, ord, ls, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                i = (i + 1);
            }
        }
        return out;
    }
}

