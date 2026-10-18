#include "../runtime/slop_runtime.h"
#include "slop_sriqctx.h"

uint32_t howl_sriqctx_no_id(void);
uint8_t howl_sriqctx_flag_at(slop_list_u8 xs, uint32_t i);
uint32_t howl_sriqctx_u32_at(slop_list_u32 xs, uint32_t i);
slop_list_u8 howl_sriqctx_falses(slop_arena* arena, int64_t n);
slop_list_u32 howl_sriqctx_no_ids(slop_arena* arena, int64_t n);
uint8_t howl_sriqctx_raise(slop_list_u8 xs, uint32_t i);
int64_t howl_sriqctx_count_true(slop_list_u8 xs);
uint8_t howl_sriqctx_is_kind(howl_types_ATerm t, howl_types_AKind k);
uint8_t howl_sriqctx_has_lit(slop_list_howl_types_Lit ls, howl_types_Lit l);
uint8_t howl_sriqctx_note_body_lit(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_note_role_sides(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_note_any_lit(howl_sriqctx_Triggers tr, slop_list_u8 many, howl_types_Lit l);
uint8_t howl_sriqctx_note_sole(howl_sriqctx_Triggers tr, slop_list_u8 many, howl_types_Lit l);
uint8_t howl_sriqctx_note_clause(howl_sriqctx_Triggers tr, slop_list_u8 many, howl_types_Clause c);
uint8_t howl_sriqctx_drop_many(howl_sriqctx_Triggers tr, slop_list_u8 many);
howl_sriqctx_Triggers howl_sriqctx_build_triggers(slop_arena* arena, slop_list_howl_types_Clause clauses, int64_t nc, int64_t nr, int64_t nf);
howl_sriqctx_Triggers howl_sriqctx_triggers_of(slop_arena* arena, howl_sriqclauses_SriqClauses sc);
uint32_t howl_sriqctx_sole_at(howl_sriqctx_Triggers tr, uint32_t f);
uint8_t howl_sriqctx_both_kinds(howl_types_Lit l, howl_types_AKind a, howl_types_AKind b);
uint8_t howl_sriqctx_pair_kinds(howl_types_Lit l, howl_types_AKind a, howl_types_AKind b);
uint8_t howl_sriqctx_su_unary(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_su_binary(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_in_su(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_pr_unary(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_pr_binary(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_pr_eq(howl_types_Lit l);
uint8_t howl_sriqctx_in_pr(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_sur_binary(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_in_sur(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_in_prr(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriqctx_aterm_ground(howl_types_ATerm t);
uint8_t howl_sriqctx_lit_ground(howl_types_Lit l);
uint8_t howl_sriqctx_aterm_has_x(howl_types_ATerm t);
uint8_t howl_sriqctx_mentions_x(howl_types_Lit l);
int64_t howl_sriqctx_tau_su(howl_sriqctx_Triggers tr);
int64_t howl_sriqctx_tau_pr(howl_sriqctx_Triggers tr);
int64_t howl_sriqctx_pow2_sat(int64_t k);
int64_t howl_sriqctx_omega(howl_sriqctx_Strategy s, howl_sriqctx_Triggers tr);
int64_t howl_sriqctx_omega_d(int64_t nquery);
howl_sriqctx_CoreChoice howl_sriqctx_choice_of(howl_sriqctx_CoreKind k, uint32_t b);
howl_sriqctx_CoreChoice howl_sriqctx_cautious_choice(howl_sriqctx_Triggers tr, uint32_t f, slop_list_howl_types_Lit k1);
howl_sriqctx_CoreChoice howl_sriqctx_strat_choice(howl_sriqctx_Strategy s, howl_sriqctx_Triggers tr, uint32_t f, slop_list_howl_types_Lit k1);
slop_list_howl_types_Lit howl_sriqctx_core_of(slop_arena* arena, howl_sriqctx_CoreChoice cc, slop_list_howl_types_Lit k1);
howl_sriqctx_Structure howl_sriqctx_init_structure(slop_arena* arena, int64_t nquery, int64_t nconst);
howl_sriqctx_Structure howl_sriqctx_with_hidden(slop_arena* arena, howl_sriqctx_Structure st, slop_list_u32 hidden);
int64_t howl_sriqctx_ctx_count(howl_sriqctx_Structure st);
slop_option_howl_sriqctx_Ctx howl_sriqctx_ctx_at(howl_sriqctx_Structure st, int64_t v);
slop_option_howl_sriqctx_CtxSet howl_sriqctx_set_at(howl_sriqctx_Structure st, int64_t v);
uint8_t howl_sriqctx_lits_same(slop_list_howl_types_Lit a, slop_list_howl_types_Lit b);
uint8_t howl_sriqctx_core_matches(howl_sriqctx_Ctx c, slop_list_howl_types_Lit core);
uint32_t howl_sriqctx_ctx_by_core(howl_sriqctx_Structure st, slop_list_howl_types_Lit core);
uint8_t howl_sriqctx_var_ok(howl_types_ATerm t, uint8_t root);
uint8_t howl_sriqctx_side_x(howl_types_ATerm s, howl_types_ATerm t);
uint8_t howl_sriqctx_side_u(howl_types_ATerm s, howl_types_ATerm t);
uint8_t howl_sriqctx_binary_ok(howl_types_Lit l);
uint8_t howl_sriqctx_lit_ok(howl_types_Lit l, uint8_t root);
uint8_t howl_sriqctx_body_lit_ok(howl_types_Lit l, uint8_t root);
uint8_t howl_sriqctx_ctx_clause_ok(uint8_t root, howl_types_Clause c);
slop_list_howl_types_Clause howl_sriqctx_set_or_none(slop_arena* arena, howl_sriqctx_Structure st, int64_t v);
uint8_t howl_sriqctx_q_of(slop_arena* arena, howl_sriqctx_Structure st, int64_t v, slop_list_howl_types_Lit body, slop_list_howl_types_Lit head);
slop_list_howl_types_Lit howl_sriqctx_atom_x(slop_arena* arena, uint32_t b);
uint8_t howl_sriqctx_q_inconsistent(slop_arena* arena, howl_sriqctx_Structure st);
uint8_t howl_sriqctx_q_unsat(slop_arena* arena, howl_sriqctx_Structure st, uint32_t b);
uint8_t howl_sriqctx_q_hidden_unsat(slop_arena* arena, howl_sriqctx_Structure st, int64_t nquery, slop_list_u32 hidden);
uint8_t howl_sriqctx_q_holds(slop_arena* arena, howl_sriqctx_Structure st, uint32_t b, uint32_t a);
uint8_t howl_sriqctx_q_thing(slop_arena* arena, howl_sriqctx_Structure st, uint32_t a);

uint32_t howl_sriqctx_no_id(void) {
    return ((uint32_t)(4294967295));
}

uint8_t howl_sriqctx_flag_at(slop_list_u8 xs, uint32_t i) {
    __auto_type _mv_452 = ({ __auto_type _lst = xs; size_t _idx = (size_t)((int64_t)(i)); slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_452.has_value) {
        __auto_type v = _mv_452.value;
        return v;
    } else if (!_mv_452.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint32_t howl_sriqctx_u32_at(slop_list_u32 xs, uint32_t i) {
    __auto_type _mv_453 = ({ __auto_type _lst = xs; size_t _idx = (size_t)((int64_t)(i)); slop_option_u32 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_453.has_value) {
        __auto_type v = _mv_453.value;
        return v;
    } else if (!_mv_453.has_value) {
        return howl_sriqctx_no_id();
    }
    SLOP_UNREACHABLE();
}

slop_list_u8 howl_sriqctx_falses(slop_arena* arena, int64_t n) {
    {
        __auto_type out = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        while (k < n) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            k = (k + 1);
        }
        return out;
    }
}

slop_list_u32 howl_sriqctx_no_ids(slop_arena* arena, int64_t n) {
    {
        __auto_type out = ((slop_list_u32){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        while (k < n) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqctx_no_id()); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            k = (k + 1);
        }
        return out;
    }
}

uint8_t howl_sriqctx_raise(slop_list_u8 xs, uint32_t i) {
    return ({ __auto_type _set_lst = &(xs); size_t _set_idx = (size_t)(((int64_t)(i))); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
}

int64_t howl_sriqctx_count_true(slop_list_u8 xs) {
    int64_t _retval = {0};
    {
        int64_t n = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                if (b) {
                    n = (n + 1);
                }
            }
        }
        _retval = n;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    return _retval;
}

uint8_t howl_sriqctx_is_kind(howl_types_ATerm t, howl_types_AKind k) {
    return (t.kind == k);
}

uint8_t howl_sriqctx_has_lit(slop_list_howl_types_Lit ls, howl_types_Lit l) {
    uint8_t _retval = {0};
    {
        uint8_t found = 0;
        {
            __auto_type _coll = ls;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (howl_types_lit_eq(x, l)) {
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

uint8_t howl_sriqctx_note_body_lit(howl_sriqctx_Triggers tr, howl_types_Lit l) {
    __auto_type _mv_454 = l.form;
    if (_mv_454 == howl_types_LitForm_lf_unary) {
        if (howl_sriqctx_is_kind(l.t1, howl_types_AKind_ak_x)) {
            return howl_sriqctx_raise(tr.unary, l.pred);
        } else {
            return 0;
        }
    } else if (_mv_454 == howl_types_LitForm_lf_binary) {
        howl_sriqctx_raise(tr.body, l.pred);
        return howl_sriqctx_note_role_sides(tr, l);
    } else if (_mv_454 == howl_types_LitForm_lf_eq) {
        return 0;
    } else if (_mv_454 == howl_types_LitForm_lf_neq) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqctx_note_role_sides(howl_sriqctx_Triggers tr, howl_types_Lit l) {
    if (howl_sriqctx_is_kind(l.t1, howl_types_AKind_ak_x) && howl_sriqctx_is_kind(l.t2, howl_types_AKind_ak_z)) {
        return howl_sriqctx_raise(tr.out, l.pred);
    } else if (howl_sriqctx_is_kind(l.t1, howl_types_AKind_ak_z) && howl_sriqctx_is_kind(l.t2, howl_types_AKind_ak_x)) {
        return howl_sriqctx_raise(tr.in, l.pred);
    } else {
        return 0;
    }
}

uint8_t howl_sriqctx_note_any_lit(howl_sriqctx_Triggers tr, slop_list_u8 many, howl_types_Lit l) {
    __auto_type _mv_455 = l.form;
    if (_mv_455 == howl_types_LitForm_lf_unary) {
        howl_sriqctx_raise(tr.cls, l.pred);
        return howl_sriqctx_note_sole(tr, many, l);
    } else if (_mv_455 == howl_types_LitForm_lf_binary) {
        return howl_sriqctx_raise(tr.role, l.pred);
    } else if (_mv_455 == howl_types_LitForm_lf_eq) {
        return 0;
    } else if (_mv_455 == howl_types_LitForm_lf_neq) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqctx_note_sole(howl_sriqctx_Triggers tr, slop_list_u8 many, howl_types_Lit l) {
    if (!(howl_sriqctx_is_kind(l.t1, howl_types_AKind_ak_fx))) {
        return 0;
    } else {
        {
            __auto_type f = l.t1.fsym;
            __auto_type b = howl_sriqctx_u32_at(tr.sole, f);
            if (b == howl_sriqctx_no_id()) {
                return ({ __auto_type _set_lst = &(tr.sole); size_t _set_idx = (size_t)(((int64_t)(f))); __auto_type _set_val = (l.pred); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
            } else if (b != l.pred) {
                return howl_sriqctx_raise(many, f);
            } else {
                return 0;
            }
        }
    }
}

uint8_t howl_sriqctx_note_clause(howl_sriqctx_Triggers tr, slop_list_u8 many, howl_types_Clause c) {
    {
        __auto_type _coll = c.body;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type l = _coll.data[_i];
            howl_sriqctx_note_body_lit(tr, l);
            howl_sriqctx_note_any_lit(tr, many, l);
        }
    }
    {
        __auto_type _coll = c.head;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type l = _coll.data[_i];
            howl_sriqctx_note_any_lit(tr, many, l);
        }
    }
    return 1;
}

uint8_t howl_sriqctx_drop_many(howl_sriqctx_Triggers tr, slop_list_u8 many) {
    {
        int64_t f = 0;
        {
            __auto_type _coll = many;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type m = _coll.data[_i];
                if (m) {
                    (void)(({ __auto_type _set_lst = &(tr.sole); size_t _set_idx = (size_t)(f); __auto_type _set_val = (howl_sriqctx_no_id()); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
                }
                f = (f + 1);
            }
        }
        return 1;
    }
}

howl_sriqctx_Triggers howl_sriqctx_build_triggers(slop_arena* arena, slop_list_howl_types_Clause clauses, int64_t nc, int64_t nr, int64_t nf) {
    {
        __auto_type tr = ((howl_sriqctx_Triggers){.unary = howl_sriqctx_falses(arena, nc), .out = howl_sriqctx_falses(arena, nr), .in = howl_sriqctx_falses(arena, nr), .body = howl_sriqctx_falses(arena, nr), .cls = howl_sriqctx_falses(arena, nc), .role = howl_sriqctx_falses(arena, nr), .sole = howl_sriqctx_no_ids(arena, nf)});
        __auto_type many = howl_sriqctx_falses(arena, nf);
        {
            __auto_type _coll = clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                howl_sriqctx_note_clause(tr, many, c);
            }
        }
        howl_sriqctx_drop_many(tr, many);
        return tr;
    }
}

howl_sriqctx_Triggers howl_sriqctx_triggers_of(slop_arena* arena, howl_sriqclauses_SriqClauses sc) {
    {
        __auto_type ids = sc.ids;
        return howl_sriqctx_build_triggers(arena, sc.clauses, ((int64_t)(((int64_t)((ids.class_of).len)))), ((int64_t)(((int64_t)((ids.role_of).len)))), ids.nfns);
    }
}

uint32_t howl_sriqctx_sole_at(howl_sriqctx_Triggers tr, uint32_t f) {
    return howl_sriqctx_u32_at(tr.sole, f);
}

uint8_t howl_sriqctx_both_kinds(howl_types_Lit l, howl_types_AKind a, howl_types_AKind b) {
    return (howl_sriqctx_is_kind(l.t1, a) && howl_sriqctx_is_kind(l.t2, b));
}

uint8_t howl_sriqctx_pair_kinds(howl_types_Lit l, howl_types_AKind a, howl_types_AKind b) {
    return (howl_sriqctx_both_kinds(l, a, b) || howl_sriqctx_both_kinds(l, b, a));
}

uint8_t howl_sriqctx_su_unary(howl_sriqctx_Triggers tr, howl_types_Lit l) {
    return ((howl_sriqctx_is_kind(l.t1, howl_types_AKind_ak_x) || howl_sriqctx_is_kind(l.t1, howl_types_AKind_ak_u)) && howl_sriqctx_flag_at(tr.unary, l.pred));
}

uint8_t howl_sriqctx_su_binary(howl_sriqctx_Triggers tr, howl_types_Lit l) {
    if (howl_sriqctx_both_kinds(l, howl_types_AKind_ak_x, howl_types_AKind_ak_y)) {
        return howl_sriqctx_flag_at(tr.out, l.pred);
    } else if (howl_sriqctx_both_kinds(l, howl_types_AKind_ak_y, howl_types_AKind_ak_x)) {
        return howl_sriqctx_flag_at(tr.in, l.pred);
    } else if (howl_sriqctx_both_kinds(l, howl_types_AKind_ak_u, howl_types_AKind_ak_u)) {
        return howl_sriqctx_flag_at(tr.body, l.pred);
    } else {
        return 0;
    }
}

uint8_t howl_sriqctx_in_su(howl_sriqctx_Triggers tr, howl_types_Lit l) {
    uint8_t _retval = {0};
    __auto_type _mv_456 = l.form;
    if (_mv_456 == howl_types_LitForm_lf_unary) {
        _retval = howl_sriqctx_su_unary(tr, l);
        goto _slop_post;
    } else if (_mv_456 == howl_types_LitForm_lf_binary) {
        _retval = howl_sriqctx_su_binary(tr, l);
        goto _slop_post;
    } else if (_mv_456 == howl_types_LitForm_lf_eq) {
        _retval = howl_sriqctx_both_kinds(l, howl_types_AKind_ak_u, howl_types_AKind_ak_u);
        goto _slop_post;
    } else if (_mv_456 == howl_types_LitForm_lf_neq) {
        _retval = 0;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriqctx_pr_unary(howl_sriqctx_Triggers tr, howl_types_Lit l) {
    return ((howl_sriqctx_is_kind(l.t1, howl_types_AKind_ak_y) || howl_sriqctx_is_kind(l.t1, howl_types_AKind_ak_u)) && howl_sriqctx_flag_at(tr.cls, l.pred));
}

uint8_t howl_sriqctx_pr_binary(howl_sriqctx_Triggers tr, howl_types_Lit l) {
    if (howl_sriqctx_both_kinds(l, howl_types_AKind_ak_x, howl_types_AKind_ak_y)) {
        return howl_sriqctx_flag_at(tr.in, l.pred);
    } else if (howl_sriqctx_both_kinds(l, howl_types_AKind_ak_y, howl_types_AKind_ak_x)) {
        return howl_sriqctx_flag_at(tr.out, l.pred);
    } else if (howl_sriqctx_both_kinds(l, howl_types_AKind_ak_u, howl_types_AKind_ak_u)) {
        return howl_sriqctx_flag_at(tr.body, l.pred);
    } else {
        return 0;
    }
}

uint8_t howl_sriqctx_pr_eq(howl_types_Lit l) {
    return ((howl_sriqctx_pair_kinds(l, howl_types_AKind_ak_x, howl_types_AKind_ak_y)) || (howl_sriqctx_pair_kinds(l, howl_types_AKind_ak_x, howl_types_AKind_ak_u)) || (howl_sriqctx_pair_kinds(l, howl_types_AKind_ak_y, howl_types_AKind_ak_u)) || (howl_sriqctx_both_kinds(l, howl_types_AKind_ak_u, howl_types_AKind_ak_u)));
}

uint8_t howl_sriqctx_in_pr(howl_sriqctx_Triggers tr, howl_types_Lit l) {
    uint8_t _retval = {0};
    __auto_type _mv_457 = l.form;
    if (_mv_457 == howl_types_LitForm_lf_unary) {
        _retval = howl_sriqctx_pr_unary(tr, l);
        goto _slop_post;
    } else if (_mv_457 == howl_types_LitForm_lf_binary) {
        _retval = howl_sriqctx_pr_binary(tr, l);
        goto _slop_post;
    } else if (_mv_457 == howl_types_LitForm_lf_eq) {
        _retval = howl_sriqctx_pr_eq(l);
        goto _slop_post;
    } else if (_mv_457 == howl_types_LitForm_lf_neq) {
        _retval = 0;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriqctx_sur_binary(howl_sriqctx_Triggers tr, howl_types_Lit l) {
    return ((howl_sriqctx_pair_kinds(l, howl_types_AKind_ak_y, howl_types_AKind_ak_u) || howl_sriqctx_both_kinds(l, howl_types_AKind_ak_u, howl_types_AKind_ak_u)) && howl_sriqctx_flag_at(tr.role, l.pred));
}

uint8_t howl_sriqctx_in_sur(howl_sriqctx_Triggers tr, howl_types_Lit l) {
    uint8_t _retval = {0};
    __auto_type _mv_458 = l.form;
    if (_mv_458 == howl_types_LitForm_lf_unary) {
        _retval = (howl_sriqctx_is_kind(l.t1, howl_types_AKind_ak_u) && howl_sriqctx_flag_at(tr.cls, l.pred));
        goto _slop_post;
    } else if (_mv_458 == howl_types_LitForm_lf_binary) {
        _retval = howl_sriqctx_sur_binary(tr, l);
        goto _slop_post;
    } else if (_mv_458 == howl_types_LitForm_lf_eq) {
        _retval = howl_sriqctx_both_kinds(l, howl_types_AKind_ak_u, howl_types_AKind_ak_u);
        goto _slop_post;
    } else if (_mv_458 == howl_types_LitForm_lf_neq) {
        _retval = 0;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriqctx_in_prr(howl_sriqctx_Triggers tr, howl_types_Lit l) {
    uint8_t _retval = {0};
    _retval = ((howl_sriqctx_in_sur(tr, l)) || ((((l.form == howl_types_LitForm_lf_unary)) && (howl_sriqctx_is_kind(l.t1, howl_types_AKind_ak_y)) && (howl_sriqctx_flag_at(tr.cls, l.pred)))) || (((l.form == howl_types_LitForm_lf_eq) && howl_sriqctx_pair_kinds(l, howl_types_AKind_ak_y, howl_types_AKind_ak_u))));
    goto _slop_post;
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriqctx_aterm_ground(howl_types_ATerm t) {
    return (howl_sriqctx_is_kind(t, howl_types_AKind_ak_u) || howl_sriqctx_is_kind(t, howl_types_AKind_ak_fu));
}

uint8_t howl_sriqctx_lit_ground(howl_types_Lit l) {
    if (l.form == howl_types_LitForm_lf_unary) {
        return howl_sriqctx_aterm_ground(l.t1);
    } else {
        return (howl_sriqctx_aterm_ground(l.t1) && howl_sriqctx_aterm_ground(l.t2));
    }
}

uint8_t howl_sriqctx_aterm_has_x(howl_types_ATerm t) {
    return (howl_sriqctx_is_kind(t, howl_types_AKind_ak_x) || howl_sriqctx_is_kind(t, howl_types_AKind_ak_fx));
}

uint8_t howl_sriqctx_mentions_x(howl_types_Lit l) {
    if (l.form == howl_types_LitForm_lf_unary) {
        return howl_sriqctx_aterm_has_x(l.t1);
    } else {
        return (howl_sriqctx_aterm_has_x(l.t1) || howl_sriqctx_aterm_has_x(l.t2));
    }
}

int64_t howl_sriqctx_tau_su(howl_sriqctx_Triggers tr) {
    int64_t _retval = {0};
    _retval = ((howl_sriqctx_count_true(tr.unary)) + (howl_sriqctx_count_true(tr.out)) + (howl_sriqctx_count_true(tr.in)));
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    return _retval;
}

int64_t howl_sriqctx_tau_pr(howl_sriqctx_Triggers tr) {
    int64_t _retval = {0};
    _retval = ((howl_sriqctx_count_true(tr.cls)) + (howl_sriqctx_count_true(tr.out)) + (howl_sriqctx_count_true(tr.in)));
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    return _retval;
}

int64_t howl_sriqctx_pow2_sat(int64_t k) {
    SLOP_PRE(((k >= 0)), "(>= k 0)");
    int64_t _retval = {0};
    if (k >= 62) {
        _retval = 4611686018427387904;
        goto _slop_post;
    } else {
        _retval = (1 << k);
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

int64_t howl_sriqctx_omega(howl_sriqctx_Strategy s, howl_sriqctx_Triggers tr) {
    int64_t _retval = {0};
    __auto_type _mv_459 = s;
    if (_mv_459 == howl_sriqctx_Strategy_st_trivial) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_459 == howl_sriqctx_Strategy_st_cautious) {
        _retval = howl_sriqctx_count_true(tr.cls);
        goto _slop_post;
    } else if (_mv_459 == howl_sriqctx_Strategy_st_eager) {
        _retval = howl_sriqctx_pow2_sat(((howl_sriqctx_count_true(tr.cls)) + (howl_sriqctx_count_true(tr.role)) + (1)));
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

int64_t howl_sriqctx_omega_d(int64_t nquery) {
    int64_t _retval = {0};
    _retval = (nquery + 2);
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval == (nquery + 2))), "(== $result (+ nquery 2))");
    return _retval;
}

howl_sriqctx_CoreChoice howl_sriqctx_choice_of(howl_sriqctx_CoreKind k, uint32_t b) {
    howl_sriqctx_CoreChoice _retval = {0};
    _retval = ((howl_sriqctx_CoreChoice){.kind = k, .cls = b});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.kind == k)), "(== (. $result kind) k)");
    SLOP_POST(((_retval.cls == b)), "(== (. $result cls) b)");
    return _retval;
}

howl_sriqctx_CoreChoice howl_sriqctx_cautious_choice(howl_sriqctx_Triggers tr, uint32_t f, slop_list_howl_types_Lit k1) {
    howl_sriqctx_CoreChoice _retval = {0};
    {
        __auto_type b = howl_sriqctx_sole_at(tr, f);
        if ((b != howl_sriqctx_no_id()) && howl_sriqctx_has_lit(k1, howl_types_atom1(b, howl_types_at_x()))) {
            _retval = howl_sriqctx_choice_of(howl_sriqctx_CoreKind_cc_unary, b);
            goto _slop_post;
        } else {
            _retval = howl_sriqctx_choice_of(howl_sriqctx_CoreKind_cc_empty, howl_sriqctx_no_id());
            goto _slop_post;
        }
    }
    _slop_post: ;
    SLOP_POST((((_retval.kind == howl_sriqctx_CoreKind_cc_empty) || (_retval.kind == howl_sriqctx_CoreKind_cc_unary))), "(or (== (. $result kind) (quote cc-empty)) (== (. $result kind) (quote cc-unary)))");
    return _retval;
}

howl_sriqctx_CoreChoice howl_sriqctx_strat_choice(howl_sriqctx_Strategy s, howl_sriqctx_Triggers tr, uint32_t f, slop_list_howl_types_Lit k1) {
    howl_sriqctx_CoreChoice _retval = {0};
    __auto_type _mv_460 = s;
    if (_mv_460 == howl_sriqctx_Strategy_st_trivial) {
        _retval = howl_sriqctx_choice_of(howl_sriqctx_CoreKind_cc_empty, howl_sriqctx_no_id());
        goto _slop_post;
    } else if (_mv_460 == howl_sriqctx_Strategy_st_eager) {
        _retval = howl_sriqctx_choice_of(howl_sriqctx_CoreKind_cc_k1, howl_sriqctx_no_id());
        goto _slop_post;
    } else if (_mv_460 == howl_sriqctx_Strategy_st_cautious) {
        _retval = howl_sriqctx_cautious_choice(tr, f, k1);
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

slop_list_howl_types_Lit howl_sriqctx_core_of(slop_arena* arena, howl_sriqctx_CoreChoice cc, slop_list_howl_types_Lit k1) {
    if (cc.kind == howl_sriqctx_CoreKind_cc_k1) {
        return k1;
    } else {
        if (cc.kind == howl_sriqctx_CoreKind_cc_unary) {
            {
                __auto_type one = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                (void)(({ __auto_type _lst_p = &(one); __auto_type _item = (howl_types_atom1(cc.cls, howl_types_at_x())); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                return one;
            }
        } else {
            {
                __auto_type none_such = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                return none_such;
            }
        }
    }
}

howl_sriqctx_Structure howl_sriqctx_init_structure(slop_arena* arena, int64_t nquery, int64_t nconst) {
    SLOP_PRE((((nquery >= 0) && (nconst >= 0))), "(and (>= nquery 0) (>= nconst 0))");
    {
        __auto_type ctxs = ((slop_list_howl_sriqctx_Ctx){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type sets = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t b = 0;
        (void)(({ __auto_type _lst_p = &(ctxs); __auto_type _item = (((howl_sriqctx_Ctx){.core = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .root = 1})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ctxs); __auto_type _item = (((howl_sriqctx_Ctx){.core = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .root = 0})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        while (b < nquery) {
            {
                __auto_type core = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                (void)(({ __auto_type _lst_p = &(core); __auto_type _item = (howl_types_atom1(((uint32_t)(b)), howl_types_at_x())); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(ctxs); __auto_type _item = (((howl_sriqctx_Ctx){.core = core, .root = 0})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                b = (b + 1);
            }
        }
        b = 0;
        while (b < (nquery + 2)) {
            (void)(({ __auto_type _lst_p = &(sets); __auto_type _item = (((howl_sriqctx_CtxSet){.cs = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            b = (b + 1);
        }
        return ((howl_sriqctx_Structure){.ctxs = ctxs, .sets = sets, .edges = ((slop_list_howl_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .ord = howl_sriqorder_named_consts(arena, nconst)});
    }
}

howl_sriqctx_Structure howl_sriqctx_with_hidden(slop_arena* arena, howl_sriqctx_Structure st, slop_list_u32 hidden) {
    if (((int64_t)((hidden).len)) == 0) {
        return st;
    } else {
        {
            __auto_type ctxs = ((slop_list_howl_sriqctx_Ctx){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            __auto_type sets = ((slop_list_howl_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = st.ctxs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(ctxs); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
            {
                __auto_type _coll = st.sets;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type s = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(sets); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
            {
                __auto_type _coll = hidden;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    {
                        __auto_type core = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                        (void)(({ __auto_type _lst_p = &(core); __auto_type _item = (howl_types_atom1(a, howl_types_at_x())); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        (void)(({ __auto_type _lst_p = &(ctxs); __auto_type _item = (((howl_sriqctx_Ctx){.core = core, .root = 0})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        (void)(({ __auto_type _lst_p = &(sets); __auto_type _item = (((howl_sriqctx_CtxSet){.cs = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
            return ((howl_sriqctx_Structure){.ctxs = ctxs, .sets = sets, .edges = st.edges, .ord = st.ord});
        }
    }
}

int64_t howl_sriqctx_ctx_count(howl_sriqctx_Structure st) {
    return ((int64_t)(((int64_t)((st.ctxs).len))));
}

slop_option_howl_sriqctx_Ctx howl_sriqctx_ctx_at(howl_sriqctx_Structure st, int64_t v) {
    return ({ __auto_type _lst = st.ctxs; size_t _idx = (size_t)v; slop_option_howl_sriqctx_Ctx _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
}

slop_option_howl_sriqctx_CtxSet howl_sriqctx_set_at(howl_sriqctx_Structure st, int64_t v) {
    return ({ __auto_type _lst = st.sets; size_t _idx = (size_t)v; slop_option_howl_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
}

uint8_t howl_sriqctx_lits_same(slop_list_howl_types_Lit a, slop_list_howl_types_Lit b) {
    {
        uint8_t ok = (((int64_t)((a).len)) == ((int64_t)((b).len)));
        int64_t i = 0;
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                __auto_type _mv_461 = ({ __auto_type _lst = b; size_t _idx = (size_t)i; slop_option_howl_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_461.has_value) {
                    __auto_type m = _mv_461.value;
                    if (!(howl_types_lit_eq(l, m))) {
                        ok = 0;
                    }
                } else if (!_mv_461.has_value) {
                    ok = 0;
                }
                i = (i + 1);
            }
        }
        return ok;
    }
}

uint8_t howl_sriqctx_core_matches(howl_sriqctx_Ctx c, slop_list_howl_types_Lit core) {
    return (!(c.root) && howl_sriqctx_lits_same(c.core, core));
}

uint32_t howl_sriqctx_ctx_by_core(howl_sriqctx_Structure st, slop_list_howl_types_Lit core) {
    uint32_t _retval = {0};
    {
        uint32_t v = ((uint32_t)(0));
        uint32_t found = howl_sriqctx_no_id();
        {
            __auto_type _coll = st.ctxs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (((v > ((uint32_t)(0)))) && ((found == howl_sriqctx_no_id())) && (howl_sriqctx_core_matches(c, core))) {
                    found = v;
                }
                v = (v + ((uint32_t)(1)));
            }
        }
        _retval = found;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((_retval != ((uint32_t)(0)))), "(!= $result (cast U32 0))");
    return _retval;
}

uint8_t howl_sriqctx_var_ok(howl_types_ATerm t, uint8_t root) {
    __auto_type _mv_462 = t.kind;
    if (_mv_462 == howl_types_AKind_ak_x) {
        return !(root);
    } else if (_mv_462 == howl_types_AKind_ak_fx) {
        return !(root);
    } else if (_mv_462 == howl_types_AKind_ak_fu) {
        return root;
    } else if (_mv_462 == howl_types_AKind_ak_y) {
        return 1;
    } else if (_mv_462 == howl_types_AKind_ak_u) {
        return 1;
    } else if (_mv_462 == howl_types_AKind_ak_z) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqctx_side_x(howl_types_ATerm s, howl_types_ATerm t) {
    return (howl_sriqctx_is_kind(s, howl_types_AKind_ak_x) && !(howl_sriqctx_is_kind(t, howl_types_AKind_ak_z)));
}

uint8_t howl_sriqctx_side_u(howl_types_ATerm s, howl_types_ATerm t) {
    return (howl_sriqctx_is_kind(s, howl_types_AKind_ak_u) && ((howl_sriqctx_is_kind(t, howl_types_AKind_ak_y)) || (howl_sriqctx_is_kind(t, howl_types_AKind_ak_u)) || (howl_sriqctx_is_kind(t, howl_types_AKind_ak_fu))));
}

uint8_t howl_sriqctx_binary_ok(howl_types_Lit l) {
    {
        __auto_type s = l.t1;
        __auto_type t = l.t2;
        return ((howl_sriqctx_side_x(s, t)) || (howl_sriqctx_side_x(t, s)) || (howl_sriqctx_side_u(s, t)) || (howl_sriqctx_side_u(t, s)));
    }
}

uint8_t howl_sriqctx_lit_ok(howl_types_Lit l, uint8_t root) {
    if (l.form == howl_types_LitForm_lf_unary) {
        return howl_sriqctx_var_ok(l.t1, root);
    } else {
        return ((howl_sriqctx_var_ok(l.t1, root)) && (howl_sriqctx_var_ok(l.t2, root)) && ((!((l.form == howl_types_LitForm_lf_binary)) || howl_sriqctx_binary_ok(l))));
    }
}

uint8_t howl_sriqctx_body_lit_ok(howl_types_Lit l, uint8_t root) {
    return (howl_sriqctx_lit_ok(l, root) && (((l.form == howl_types_LitForm_lf_unary)) || ((l.form == howl_types_LitForm_lf_binary)) || (((l.form == howl_types_LitForm_lf_eq) && howl_sriqctx_both_kinds(l, howl_types_AKind_ak_u, howl_types_AKind_ak_u)))));
}

uint8_t howl_sriqctx_ctx_clause_ok(uint8_t root, howl_types_Clause c) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(howl_sriqctx_body_lit_ok(l, root))) {
                    ok = 0;
                }
            }
        }
        {
            __auto_type _coll = c.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(howl_sriqctx_lit_ok(l, root))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

slop_list_howl_types_Clause howl_sriqctx_set_or_none(slop_arena* arena, howl_sriqctx_Structure st, int64_t v) {
    __auto_type _mv_463 = ({ __auto_type _lst = st.sets; size_t _idx = (size_t)v; slop_option_howl_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_463.has_value) {
        __auto_type s = _mv_463.value;
        return s.cs;
    } else if (!_mv_463.has_value) {
        return ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqctx_q_of(slop_arena* arena, howl_sriqctx_Structure st, int64_t v, slop_list_howl_types_Lit body, slop_list_howl_types_Lit head) {
    return howl_sriqsubsume_in_hat(howl_sriqclauses_make_clause(arena, body, head), howl_sriqctx_set_or_none(arena, st, v));
}

slop_list_howl_types_Lit howl_sriqctx_atom_x(slop_arena* arena, uint32_t b) {
    {
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_types_atom1(b, howl_types_at_x())); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

uint8_t howl_sriqctx_q_inconsistent(slop_arena* arena, howl_sriqctx_Structure st) {
    return howl_sriqctx_q_of(arena, st, 1, ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
}

uint8_t howl_sriqctx_q_unsat(slop_arena* arena, howl_sriqctx_Structure st, uint32_t b) {
    return howl_sriqctx_q_of(arena, st, (2 + ((int64_t)(b))), howl_sriqctx_atom_x(arena, b), ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
}

uint8_t howl_sriqctx_q_hidden_unsat(slop_arena* arena, howl_sriqctx_Structure st, int64_t nquery, slop_list_u32 hidden) {
    {
        uint8_t found = 0;
        int64_t k = 0;
        {
            __auto_type _coll = hidden;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (howl_sriqctx_q_of(arena, st, ((2 + nquery) + k), howl_sriqctx_atom_x(arena, a), ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }))) {
                    found = 1;
                }
                k = (k + 1);
            }
        }
        return found;
    }
}

uint8_t howl_sriqctx_q_holds(slop_arena* arena, howl_sriqctx_Structure st, uint32_t b, uint32_t a) {
    return howl_sriqctx_q_of(arena, st, (2 + ((int64_t)(b))), howl_sriqctx_atom_x(arena, b), howl_sriqctx_atom_x(arena, a));
}

uint8_t howl_sriqctx_q_thing(slop_arena* arena, howl_sriqctx_Structure st, uint32_t a) {
    return howl_sriqctx_q_of(arena, st, 1, ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), howl_sriqctx_atom_x(arena, a));
}

