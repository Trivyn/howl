#include "../runtime/slop_runtime.h"
#include "slop_sriqorder.h"

howl_sriqorder_SriqOrder howl_sriqorder_named_consts(slop_arena* arena, int64_t n);
howl_sriqorder_SriqOrder howl_sriqorder_ranked(howl_sriqorder_SriqOrder ord, int64_t nquery);
howl_sriqorder_ConstEntry howl_sriqorder_aux_const(howl_sriqorder_ConstEntry p, uint32_t pid, uint32_t s, uint32_t i);
howl_sriqorder_ConstEntry howl_sriqorder_const_entry(howl_sriqorder_SriqOrder ord, uint32_t u);
uint8_t howl_sriqorder_fn_gt(uint32_t f, uint32_t g);
int64_t howl_sriqorder_cmp_u32(uint32_t a, uint32_t b);
int64_t howl_sriqorder_letter_cmp(howl_sriqorder_ConstEntry a, howl_sriqorder_ConstEntry b);
int64_t howl_sriqorder_label_cmp(howl_sriqorder_SriqOrder ord, uint32_t a, uint32_t b);
uint8_t howl_sriqorder_const_gt(howl_sriqorder_SriqOrder ord, uint32_t a, uint32_t b);
uint8_t howl_sriqorder_fx_over(howl_sriqorder_SriqOrder ord, uint32_t f, howl_types_ATerm b);
uint8_t howl_sriqorder_fu_over(howl_sriqorder_SriqOrder ord, uint32_t f, uint32_t u, howl_types_ATerm b);
uint8_t howl_sriqorder_aterm_gt(howl_sriqorder_SriqOrder ord, howl_types_ATerm a, howl_types_ATerm b);
uint8_t howl_sriqorder_aterm_same(howl_types_ATerm a, howl_types_ATerm b);
uint8_t howl_sriqorder_aterm_ge(howl_sriqorder_SriqOrder ord, howl_types_ATerm a, howl_types_ATerm b);
uint8_t howl_sriqorder_rank_gt(howl_sriqorder_SriqOrder ord, uint32_t p, uint32_t q);
uint8_t howl_sriqorder_ranked_unary_gt(howl_sriqorder_SriqOrder ord, howl_types_Lit a, howl_types_Lit b);
uint8_t howl_sriqorder_pterm_gt(howl_sriqorder_SriqOrder ord, howl_types_Lit a, howl_types_Lit b);
uint8_t howl_sriqorder_pterm_over_aterm(howl_sriqorder_SriqOrder ord, howl_types_Lit a, howl_types_ATerm s);
howl_sriqorder_CTerm howl_sriqorder_ct_true(void);
howl_sriqorder_CTerm howl_sriqorder_ct_a(howl_types_ATerm s);
howl_sriqorder_CTerm howl_sriqorder_ct_p(howl_types_Lit l);
uint8_t howl_sriqorder_cterm_gt(howl_sriqorder_SriqOrder ord, howl_sriqorder_CTerm s, howl_sriqorder_CTerm t);
uint8_t howl_sriqorder_cterm_same(howl_sriqorder_CTerm s, howl_sriqorder_CTerm t);
slop_list_howl_sriqorder_CTerm howl_sriqorder_lit_ms(slop_arena* arena, howl_types_Lit l);
slop_list_howl_sriqorder_CTerm howl_sriqorder_take_one(slop_arena* arena, slop_list_howl_sriqorder_CTerm xs, howl_sriqorder_CTerm y);
slop_list_howl_sriqorder_CTerm howl_sriqorder_ms_minus(slop_arena* arena, slop_list_howl_sriqorder_CTerm xs, slop_list_howl_sriqorder_CTerm ys);
uint8_t howl_sriqorder_dominated(howl_sriqorder_SriqOrder ord, slop_list_howl_sriqorder_CTerm bs, howl_sriqorder_CTerm a);
uint8_t howl_sriqorder_mul_gt(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_sriqorder_CTerm m1, slop_list_howl_sriqorder_CTerm m2);
uint8_t howl_sriqorder_lit_gt(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_types_Lit l1, howl_types_Lit l2);
uint8_t howl_sriqorder_maximal_at(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Lit ls, int64_t i);
slop_list_u8 howl_sriqorder_max_flags(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Lit ls);

howl_sriqorder_SriqOrder howl_sriqorder_named_consts(slop_arena* arena, int64_t n) {
    {
        __auto_type cs = ((slop_list_howl_sriqorder_ConstEntry){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        while (k < n) {
            (void)(({ __auto_type _lst_p = &(cs); __auto_type _item = (((howl_sriqorder_ConstEntry){.base = ((uint32_t)(k)), .parent = ((uint32_t)(k)), .srole = ((uint32_t)(0)), .i = ((uint32_t)(0)), .len = ((uint32_t)(0))})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            k = (k + 1);
        }
        return ((howl_sriqorder_SriqOrder){.consts = cs, .rank = -1});
    }
}

howl_sriqorder_SriqOrder howl_sriqorder_ranked(howl_sriqorder_SriqOrder ord, int64_t nquery) {
    SLOP_PRE(((nquery >= 0)), "(>= nquery 0)");
    howl_sriqorder_SriqOrder _retval = {0};
    _retval = ((howl_sriqorder_SriqOrder){.consts = ord.consts, .rank = nquery});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.rank == nquery)), "(== (. $result rank) nquery)");
    return _retval;
}

howl_sriqorder_ConstEntry howl_sriqorder_aux_const(howl_sriqorder_ConstEntry p, uint32_t pid, uint32_t s, uint32_t i) {
    return ((howl_sriqorder_ConstEntry){.base = p.base, .parent = pid, .srole = s, .i = i, .len = (p.len + ((uint32_t)(1)))});
}

howl_sriqorder_ConstEntry howl_sriqorder_const_entry(howl_sriqorder_SriqOrder ord, uint32_t u) {
    __auto_type _mv_440 = ({ __auto_type _lst = ord.consts; size_t _idx = (size_t)((int64_t)(u)); slop_option_howl_sriqorder_ConstEntry _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_440.has_value) {
        __auto_type e = _mv_440.value;
        return e;
    } else if (!_mv_440.has_value) {
        return ((howl_sriqorder_ConstEntry){.base = u, .parent = u, .srole = ((uint32_t)(0)), .i = ((uint32_t)(0)), .len = ((uint32_t)(0))});
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqorder_fn_gt(uint32_t f, uint32_t g) {
    uint8_t _retval = {0};
    _retval = (f > g);
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval == (f > g))), "(== $result (> f g))");
    return _retval;
}

int64_t howl_sriqorder_cmp_u32(uint32_t a, uint32_t b) {
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

int64_t howl_sriqorder_letter_cmp(howl_sriqorder_ConstEntry a, howl_sriqorder_ConstEntry b) {
    if (a.srole != b.srole) {
        return howl_sriqorder_cmp_u32(a.srole, b.srole);
    } else {
        return howl_sriqorder_cmp_u32(a.i, b.i);
    }
}

int64_t howl_sriqorder_label_cmp(howl_sriqorder_SriqOrder ord, uint32_t a, uint32_t b) {
    {
        uint32_t x = a;
        uint32_t y = b;
        int64_t r = 0;
        int64_t k = ((int64_t)(howl_sriqorder_const_entry(ord, a).len));
        while (k > 0) {
            {
                __auto_type ex = howl_sriqorder_const_entry(ord, x);
                __auto_type ey = howl_sriqorder_const_entry(ord, y);
                __auto_type c = howl_sriqorder_letter_cmp(ex, ey);
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

uint8_t howl_sriqorder_const_gt(howl_sriqorder_SriqOrder ord, uint32_t a, uint32_t b) {
    uint8_t _retval = {0};
    if (a == b) {
        _retval = 0;
        goto _slop_post;
    } else {
        {
            __auto_type ea = howl_sriqorder_const_entry(ord, a);
            __auto_type eb = howl_sriqorder_const_entry(ord, b);
            if (ea.len != eb.len) {
                _retval = (ea.len > eb.len);
                goto _slop_post;
            } else if (ea.base != eb.base) {
                _retval = (ea.base > eb.base);
                goto _slop_post;
            } else {
                _retval = (howl_sriqorder_label_cmp(ord, a, b) > 0);
                goto _slop_post;
            }
        }
    }
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriqorder_fx_over(howl_sriqorder_SriqOrder ord, uint32_t f, howl_types_ATerm b) {
    uint8_t _retval = {0};
    __auto_type _mv_441 = b.kind;
    if (_mv_441 == howl_types_AKind_ak_x) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_441 == howl_types_AKind_ak_y) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_441 == howl_types_AKind_ak_z) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_441 == howl_types_AKind_ak_fx) {
        _retval = howl_sriqorder_fn_gt(f, b.fsym);
        goto _slop_post;
    } else if (_mv_441 == howl_types_AKind_ak_u) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_441 == howl_types_AKind_ak_fu) {
        _retval = howl_sriqorder_fn_gt(f, b.fsym);
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriqorder_fu_over(howl_sriqorder_SriqOrder ord, uint32_t f, uint32_t u, howl_types_ATerm b) {
    uint8_t _retval = {0};
    __auto_type _mv_442 = b.kind;
    if (_mv_442 == howl_types_AKind_ak_x) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_442 == howl_types_AKind_ak_y) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_442 == howl_types_AKind_ak_z) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_442 == howl_types_AKind_ak_fx) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_442 == howl_types_AKind_ak_u) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_442 == howl_types_AKind_ak_fu) {
        _retval = (howl_sriqorder_fn_gt(f, b.fsym) || ((f == b.fsym) && howl_sriqorder_const_gt(ord, u, b.cst)));
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriqorder_aterm_gt(howl_sriqorder_SriqOrder ord, howl_types_ATerm a, howl_types_ATerm b) {
    uint8_t _retval = {0};
    __auto_type _mv_443 = a.kind;
    if (_mv_443 == howl_types_AKind_ak_x) {
        _retval = (b.kind == howl_types_AKind_ak_y);
        goto _slop_post;
    } else if (_mv_443 == howl_types_AKind_ak_y) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_443 == howl_types_AKind_ak_z) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_443 == howl_types_AKind_ak_fx) {
        _retval = howl_sriqorder_fx_over(ord, a.fsym, b);
        goto _slop_post;
    } else if (_mv_443 == howl_types_AKind_ak_u) {
        _retval = ((b.kind == howl_types_AKind_ak_u) && howl_sriqorder_const_gt(ord, a.cst, b.cst));
        goto _slop_post;
    } else if (_mv_443 == howl_types_AKind_ak_fu) {
        _retval = howl_sriqorder_fu_over(ord, a.fsym, a.cst, b);
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriqorder_aterm_same(howl_types_ATerm a, howl_types_ATerm b) {
    return (((a.kind == b.kind)) && ((a.fsym == b.fsym)) && ((a.cst == b.cst)) && ((a.zi == b.zi)));
}

uint8_t howl_sriqorder_aterm_ge(howl_sriqorder_SriqOrder ord, howl_types_ATerm a, howl_types_ATerm b) {
    return (howl_sriqorder_aterm_same(a, b) || howl_sriqorder_aterm_gt(ord, a, b));
}

uint8_t howl_sriqorder_rank_gt(howl_sriqorder_SriqOrder ord, uint32_t p, uint32_t q) {
    uint8_t _retval = {0};
    _retval = (((ord.rank >= 0)) && ((((int64_t)(p)) >= ord.rank)) && (((((int64_t)(q)) < ord.rank) || (p > q))));
    goto _slop_post;
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriqorder_ranked_unary_gt(howl_sriqorder_SriqOrder ord, howl_types_Lit a, howl_types_Lit b) {
    uint8_t _retval = {0};
    _retval = ((howl_sriqorder_rank_gt(ord, a.pred, b.pred)) && (((a.t1.kind == howl_types_AKind_ak_x) || (a.t1.kind == howl_types_AKind_ak_fx))) && (((b.t1.kind == howl_types_AKind_ak_x) || (b.t1.kind == howl_types_AKind_ak_y))));
    goto _slop_post;
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriqorder_pterm_gt(howl_sriqorder_SriqOrder ord, howl_types_Lit a, howl_types_Lit b) {
    uint8_t _retval = {0};
    if (a.form != b.form) {
        _retval = 0;
        goto _slop_post;
    } else if (a.pred != b.pred) {
        _retval = ((a.form == howl_types_LitForm_lf_unary) && howl_sriqorder_ranked_unary_gt(ord, a, b));
        goto _slop_post;
    } else if (a.form == howl_types_LitForm_lf_unary) {
        _retval = howl_sriqorder_aterm_gt(ord, a.t1, b.t1);
        goto _slop_post;
    } else {
        _retval = ((howl_sriqorder_aterm_ge(ord, a.t1, b.t1)) && (howl_sriqorder_aterm_ge(ord, a.t2, b.t2)) && (!((howl_sriqorder_aterm_same(a.t1, b.t1) && howl_sriqorder_aterm_same(a.t2, b.t2)))));
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriqorder_pterm_over_aterm(howl_sriqorder_SriqOrder ord, howl_types_Lit a, howl_types_ATerm s) {
    uint8_t _retval = {0};
    _retval = (((s.kind == howl_types_AKind_ak_x)) || ((s.kind == howl_types_AKind_ak_y)) || (howl_sriqorder_aterm_ge(ord, a.t1, s)) || (((a.form == howl_types_LitForm_lf_binary) && howl_sriqorder_aterm_ge(ord, a.t2, s))));
    goto _slop_post;
    _slop_post: ;
    return _retval;
}

howl_sriqorder_CTerm howl_sriqorder_ct_true(void) {
    return ((howl_sriqorder_CTerm){.ck = howl_sriqorder_CKind_ck_true, .a = howl_types_at_x(), .p = howl_types_atom1(((uint32_t)(0)), howl_types_at_x())});
}

howl_sriqorder_CTerm howl_sriqorder_ct_a(howl_types_ATerm s) {
    return ((howl_sriqorder_CTerm){.ck = howl_sriqorder_CKind_ck_a, .a = s, .p = howl_types_atom1(((uint32_t)(0)), howl_types_at_x())});
}

howl_sriqorder_CTerm howl_sriqorder_ct_p(howl_types_Lit l) {
    return ((howl_sriqorder_CTerm){.ck = howl_sriqorder_CKind_ck_p, .a = howl_types_at_x(), .p = l});
}

uint8_t howl_sriqorder_cterm_gt(howl_sriqorder_SriqOrder ord, howl_sriqorder_CTerm s, howl_sriqorder_CTerm t) {
    uint8_t _retval = {0};
    __auto_type _mv_444 = s.ck;
    if (_mv_444 == howl_sriqorder_CKind_ck_true) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_444 == howl_sriqorder_CKind_ck_a) {
        __auto_type _mv_445 = t.ck;
        if (_mv_445 == howl_sriqorder_CKind_ck_true) {
            _retval = 1;
            goto _slop_post;
        } else if (_mv_445 == howl_sriqorder_CKind_ck_a) {
            _retval = howl_sriqorder_aterm_gt(ord, s.a, t.a);
            goto _slop_post;
        } else if (_mv_445 == howl_sriqorder_CKind_ck_p) {
            _retval = 0;
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    } else if (_mv_444 == howl_sriqorder_CKind_ck_p) {
        __auto_type _mv_446 = t.ck;
        if (_mv_446 == howl_sriqorder_CKind_ck_true) {
            _retval = 1;
            goto _slop_post;
        } else if (_mv_446 == howl_sriqorder_CKind_ck_a) {
            _retval = howl_sriqorder_pterm_over_aterm(ord, s.p, t.a);
            goto _slop_post;
        } else if (_mv_446 == howl_sriqorder_CKind_ck_p) {
            _retval = howl_sriqorder_pterm_gt(ord, s.p, t.p);
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriqorder_cterm_same(howl_sriqorder_CTerm s, howl_sriqorder_CTerm t) {
    return ((s.ck == t.ck) && ({ __auto_type _mv = s.ck; int _mi = (_mv == howl_sriqorder_CKind_ck_true) ? 1 : (_mv == howl_sriqorder_CKind_ck_a) ? 2 : (_mv == howl_sriqorder_CKind_ck_p) ? 3 : 0; if (!_mi) { SLOP_UNREACHABLE(); } _mi == 1 ? (1) : _mi == 2 ? (howl_sriqorder_aterm_same(s.a, t.a)) : ((((s.p.form == t.p.form)) && ((s.p.pred == t.p.pred)) && (howl_sriqorder_aterm_same(s.p.t1, t.p.t1)) && (howl_sriqorder_aterm_same(s.p.t2, t.p.t2)))); }));
}

slop_list_howl_sriqorder_CTerm howl_sriqorder_lit_ms(slop_arena* arena, howl_types_Lit l) {
    {
        __auto_type out = ((slop_list_howl_sriqorder_CTerm){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_447 = l.form;
        if (_mv_447 == howl_types_LitForm_lf_unary) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqorder_ct_p(l)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqorder_ct_true()); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (_mv_447 == howl_types_LitForm_lf_binary) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqorder_ct_p(l)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqorder_ct_true()); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (_mv_447 == howl_types_LitForm_lf_eq) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqorder_ct_a(l.t1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqorder_ct_a(l.t2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (_mv_447 == howl_types_LitForm_lf_neq) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqorder_ct_a(l.t1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqorder_ct_a(l.t1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqorder_ct_a(l.t2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqorder_ct_a(l.t2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return out;
    }
}

slop_list_howl_sriqorder_CTerm howl_sriqorder_take_one(slop_arena* arena, slop_list_howl_sriqorder_CTerm xs, howl_sriqorder_CTerm y) {
    {
        __auto_type out = ((slop_list_howl_sriqorder_CTerm){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t taken = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (!(taken) && howl_sriqorder_cterm_same(x, y)) {
                    taken = 1;
                } else {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

slop_list_howl_sriqorder_CTerm howl_sriqorder_ms_minus(slop_arena* arena, slop_list_howl_sriqorder_CTerm xs, slop_list_howl_sriqorder_CTerm ys) {
    {
        __auto_type out = xs;
        {
            __auto_type _coll = ys;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type y = _coll.data[_i];
                out = howl_sriqorder_take_one(arena, out, y);
            }
        }
        return out;
    }
}

uint8_t howl_sriqorder_dominated(howl_sriqorder_SriqOrder ord, slop_list_howl_sriqorder_CTerm bs, howl_sriqorder_CTerm a) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = bs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                if (howl_sriqorder_cterm_gt(ord, b, a)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t howl_sriqorder_mul_gt(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_sriqorder_CTerm m1, slop_list_howl_sriqorder_CTerm m2) {
    {
        __auto_type d1 = howl_sriqorder_ms_minus(arena, m1, m2);
        __auto_type d2 = howl_sriqorder_ms_minus(arena, m2, m1);
        uint8_t ok = ((((int64_t)((d1).len)) > 0) || (((int64_t)((d2).len)) > 0));
        {
            __auto_type _coll = d2;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (!(howl_sriqorder_dominated(ord, d1, a))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t howl_sriqorder_lit_gt(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_types_Lit l1, howl_types_Lit l2) {
    return howl_sriqorder_mul_gt(arena, ord, howl_sriqorder_lit_ms(arena, l1), howl_sriqorder_lit_ms(arena, l2));
}

uint8_t howl_sriqorder_maximal_at(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Lit ls, int64_t i) {
    __auto_type _mv_448 = ({ __auto_type _lst = ls; size_t _idx = (size_t)i; slop_option_howl_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_448.has_value) {
        return 0;
    } else if (_mv_448.has_value) {
        __auto_type l = _mv_448.value;
        {
            uint8_t ok = 1;
            int64_t j = 0;
            {
                __auto_type _coll = ls;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type m = _coll.data[_i];
                    if ((j != i) && howl_sriqorder_lit_gt(arena, ord, m, l)) {
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

slop_list_u8 howl_sriqorder_max_flags(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Lit ls) {
    {
        __auto_type out = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = ls;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqorder_maximal_at(arena, ord, ls, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                i = (i + 1);
            }
        }
        return out;
    }
}

