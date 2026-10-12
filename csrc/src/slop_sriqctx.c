#include "../runtime/slop_runtime.h"
#include "slop_sriqctx.h"

uint32_t sriqctx_no_id(void);
uint8_t sriqctx_flag_at(slop_list_u8 xs, uint32_t i);
uint32_t sriqctx_u32_at(slop_list_u32 xs, uint32_t i);
slop_list_u8 sriqctx_falses(slop_arena* arena, int64_t n);
slop_list_u32 sriqctx_no_ids(slop_arena* arena, int64_t n);
uint8_t sriqctx_raise(slop_list_u8 xs, uint32_t i);
int64_t sriqctx_count_true(slop_list_u8 xs);
uint8_t sriqctx_is_kind(types_ATerm t, types_AKind k);
uint8_t sriqctx_has_lit(slop_list_types_Lit ls, types_Lit l);
uint8_t sriqctx_note_body_lit(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_note_role_sides(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_note_any_lit(sriqctx_Triggers tr, slop_list_u8 many, types_Lit l);
uint8_t sriqctx_note_sole(sriqctx_Triggers tr, slop_list_u8 many, types_Lit l);
uint8_t sriqctx_note_clause(sriqctx_Triggers tr, slop_list_u8 many, types_Clause c);
uint8_t sriqctx_drop_many(sriqctx_Triggers tr, slop_list_u8 many);
sriqctx_Triggers sriqctx_build_triggers(slop_arena* arena, slop_list_types_Clause clauses, int64_t nc, int64_t nr, int64_t nf);
sriqctx_Triggers sriqctx_triggers_of(slop_arena* arena, sriqclauses_SriqClauses sc);
uint32_t sriqctx_sole_at(sriqctx_Triggers tr, uint32_t f);
uint8_t sriqctx_both_kinds(types_Lit l, types_AKind a, types_AKind b);
uint8_t sriqctx_pair_kinds(types_Lit l, types_AKind a, types_AKind b);
uint8_t sriqctx_su_unary(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_su_binary(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_in_su(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_pr_unary(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_pr_binary(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_pr_eq(types_Lit l);
uint8_t sriqctx_in_pr(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_sur_binary(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_in_sur(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_in_prr(sriqctx_Triggers tr, types_Lit l);
uint8_t sriqctx_aterm_ground(types_ATerm t);
uint8_t sriqctx_lit_ground(types_Lit l);
uint8_t sriqctx_aterm_has_x(types_ATerm t);
uint8_t sriqctx_mentions_x(types_Lit l);
int64_t sriqctx_tau_su(sriqctx_Triggers tr);
int64_t sriqctx_tau_pr(sriqctx_Triggers tr);
int64_t sriqctx_pow2_sat(int64_t k);
int64_t sriqctx_omega(sriqctx_Strategy s, sriqctx_Triggers tr);
int64_t sriqctx_omega_d(int64_t nquery);
sriqctx_CoreChoice sriqctx_choice_of(sriqctx_CoreKind k, uint32_t b);
sriqctx_CoreChoice sriqctx_cautious_choice(sriqctx_Triggers tr, uint32_t f, slop_list_types_Lit k1);
sriqctx_CoreChoice sriqctx_strat_choice(sriqctx_Strategy s, sriqctx_Triggers tr, uint32_t f, slop_list_types_Lit k1);
slop_list_types_Lit sriqctx_core_of(slop_arena* arena, sriqctx_CoreChoice cc, slop_list_types_Lit k1);
sriqctx_Structure sriqctx_init_structure(slop_arena* arena, int64_t nquery, int64_t nconst);
int64_t sriqctx_ctx_count(sriqctx_Structure st);
slop_option_sriqctx_Ctx sriqctx_ctx_at(sriqctx_Structure st, int64_t v);
slop_option_sriqctx_CtxSet sriqctx_set_at(sriqctx_Structure st, int64_t v);
uint8_t sriqctx_lits_same(slop_list_types_Lit a, slop_list_types_Lit b);
uint8_t sriqctx_core_matches(sriqctx_Ctx c, slop_list_types_Lit core);
uint32_t sriqctx_ctx_by_core(sriqctx_Structure st, slop_list_types_Lit core);
uint8_t sriqctx_var_ok(types_ATerm t, uint8_t root);
uint8_t sriqctx_side_x(types_ATerm s, types_ATerm t);
uint8_t sriqctx_side_u(types_ATerm s, types_ATerm t);
uint8_t sriqctx_binary_ok(types_Lit l);
uint8_t sriqctx_lit_ok(types_Lit l, uint8_t root);
uint8_t sriqctx_body_lit_ok(types_Lit l, uint8_t root);
uint8_t sriqctx_ctx_clause_ok(uint8_t root, types_Clause c);
slop_list_types_Clause sriqctx_set_or_none(slop_arena* arena, sriqctx_Structure st, int64_t v);
uint8_t sriqctx_q_of(slop_arena* arena, sriqctx_Structure st, int64_t v, slop_list_types_Lit body, slop_list_types_Lit head);
slop_list_types_Lit sriqctx_atom_x(slop_arena* arena, uint32_t b);
uint8_t sriqctx_q_inconsistent(slop_arena* arena, sriqctx_Structure st);
uint8_t sriqctx_q_unsat(slop_arena* arena, sriqctx_Structure st, uint32_t b);
uint8_t sriqctx_q_holds(slop_arena* arena, sriqctx_Structure st, uint32_t b, uint32_t a);
uint8_t sriqctx_q_thing(slop_arena* arena, sriqctx_Structure st, uint32_t a);

uint32_t sriqctx_no_id(void) {
    return ((uint32_t)(4294967295));
}

uint8_t sriqctx_flag_at(slop_list_u8 xs, uint32_t i) {
    __auto_type _mv_618 = ({ __auto_type _lst = xs; size_t _idx = (size_t)((int64_t)(i)); slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_618.has_value) {
        __auto_type v = _mv_618.value;
        return v;
    } else if (!_mv_618.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint32_t sriqctx_u32_at(slop_list_u32 xs, uint32_t i) {
    __auto_type _mv_619 = ({ __auto_type _lst = xs; size_t _idx = (size_t)((int64_t)(i)); slop_option_u32 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_619.has_value) {
        __auto_type v = _mv_619.value;
        return v;
    } else if (!_mv_619.has_value) {
        return sriqctx_no_id();
    }
    SLOP_UNREACHABLE();
}

slop_list_u8 sriqctx_falses(slop_arena* arena, int64_t n) {
    {
        __auto_type out = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        while (k < n) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            k = (k + 1);
        }
        return out;
    }
}

slop_list_u32 sriqctx_no_ids(slop_arena* arena, int64_t n) {
    {
        __auto_type out = ((slop_list_u32){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        while (k < n) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqctx_no_id()); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            k = (k + 1);
        }
        return out;
    }
}

uint8_t sriqctx_raise(slop_list_u8 xs, uint32_t i) {
    return ({ __auto_type _set_lst = &(xs); size_t _set_idx = (size_t)(((int64_t)(i))); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
}

int64_t sriqctx_count_true(slop_list_u8 xs) {
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

uint8_t sriqctx_is_kind(types_ATerm t, types_AKind k) {
    return (t.kind == k);
}

uint8_t sriqctx_has_lit(slop_list_types_Lit ls, types_Lit l) {
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

uint8_t sriqctx_note_body_lit(sriqctx_Triggers tr, types_Lit l) {
    __auto_type _mv_620 = l.form;
    if (_mv_620 == types_LitForm_lf_unary) {
        if (sriqctx_is_kind(l.t1, types_AKind_ak_x)) {
            return sriqctx_raise(tr.unary, l.pred);
        } else {
            return 0;
        }
    } else if (_mv_620 == types_LitForm_lf_binary) {
        sriqctx_raise(tr.body, l.pred);
        return sriqctx_note_role_sides(tr, l);
    } else if (_mv_620 == types_LitForm_lf_eq) {
        return 0;
    } else if (_mv_620 == types_LitForm_lf_neq) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqctx_note_role_sides(sriqctx_Triggers tr, types_Lit l) {
    if (sriqctx_is_kind(l.t1, types_AKind_ak_x) && sriqctx_is_kind(l.t2, types_AKind_ak_z)) {
        return sriqctx_raise(tr.out, l.pred);
    } else if (sriqctx_is_kind(l.t1, types_AKind_ak_z) && sriqctx_is_kind(l.t2, types_AKind_ak_x)) {
        return sriqctx_raise(tr.in, l.pred);
    } else {
        return 0;
    }
}

uint8_t sriqctx_note_any_lit(sriqctx_Triggers tr, slop_list_u8 many, types_Lit l) {
    __auto_type _mv_621 = l.form;
    if (_mv_621 == types_LitForm_lf_unary) {
        sriqctx_raise(tr.cls, l.pred);
        return sriqctx_note_sole(tr, many, l);
    } else if (_mv_621 == types_LitForm_lf_binary) {
        return sriqctx_raise(tr.role, l.pred);
    } else if (_mv_621 == types_LitForm_lf_eq) {
        return 0;
    } else if (_mv_621 == types_LitForm_lf_neq) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqctx_note_sole(sriqctx_Triggers tr, slop_list_u8 many, types_Lit l) {
    if (!(sriqctx_is_kind(l.t1, types_AKind_ak_fx))) {
        return 0;
    } else {
        {
            __auto_type f = l.t1.fsym;
            __auto_type b = sriqctx_u32_at(tr.sole, f);
            if (b == sriqctx_no_id()) {
                return ({ __auto_type _set_lst = &(tr.sole); size_t _set_idx = (size_t)(((int64_t)(f))); __auto_type _set_val = (l.pred); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
            } else if (b != l.pred) {
                return sriqctx_raise(many, f);
            } else {
                return 0;
            }
        }
    }
}

uint8_t sriqctx_note_clause(sriqctx_Triggers tr, slop_list_u8 many, types_Clause c) {
    {
        __auto_type _coll = c.body;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type l = _coll.data[_i];
            sriqctx_note_body_lit(tr, l);
            sriqctx_note_any_lit(tr, many, l);
        }
    }
    {
        __auto_type _coll = c.head;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type l = _coll.data[_i];
            sriqctx_note_any_lit(tr, many, l);
        }
    }
    return 1;
}

uint8_t sriqctx_drop_many(sriqctx_Triggers tr, slop_list_u8 many) {
    {
        int64_t f = 0;
        {
            __auto_type _coll = many;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type m = _coll.data[_i];
                if (m) {
                    ({ __auto_type _set_lst = &(tr.sole); size_t _set_idx = (size_t)(f); __auto_type _set_val = (sriqctx_no_id()); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
                }
                f = (f + 1);
            }
        }
        return 1;
    }
}

sriqctx_Triggers sriqctx_build_triggers(slop_arena* arena, slop_list_types_Clause clauses, int64_t nc, int64_t nr, int64_t nf) {
    {
        __auto_type tr = ((sriqctx_Triggers){.unary = sriqctx_falses(arena, nc), .out = sriqctx_falses(arena, nr), .in = sriqctx_falses(arena, nr), .body = sriqctx_falses(arena, nr), .cls = sriqctx_falses(arena, nc), .role = sriqctx_falses(arena, nr), .sole = sriqctx_no_ids(arena, nf)});
        __auto_type many = sriqctx_falses(arena, nf);
        {
            __auto_type _coll = clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                sriqctx_note_clause(tr, many, c);
            }
        }
        sriqctx_drop_many(tr, many);
        return tr;
    }
}

sriqctx_Triggers sriqctx_triggers_of(slop_arena* arena, sriqclauses_SriqClauses sc) {
    {
        __auto_type ids = sc.ids;
        return sriqctx_build_triggers(arena, sc.clauses, ((int64_t)(((int64_t)((ids.class_of).len)))), ((int64_t)(((int64_t)((ids.role_of).len)))), ids.nfns);
    }
}

uint32_t sriqctx_sole_at(sriqctx_Triggers tr, uint32_t f) {
    return sriqctx_u32_at(tr.sole, f);
}

uint8_t sriqctx_both_kinds(types_Lit l, types_AKind a, types_AKind b) {
    return (sriqctx_is_kind(l.t1, a) && sriqctx_is_kind(l.t2, b));
}

uint8_t sriqctx_pair_kinds(types_Lit l, types_AKind a, types_AKind b) {
    return (sriqctx_both_kinds(l, a, b) || sriqctx_both_kinds(l, b, a));
}

uint8_t sriqctx_su_unary(sriqctx_Triggers tr, types_Lit l) {
    return ((sriqctx_is_kind(l.t1, types_AKind_ak_x) || sriqctx_is_kind(l.t1, types_AKind_ak_u)) && sriqctx_flag_at(tr.unary, l.pred));
}

uint8_t sriqctx_su_binary(sriqctx_Triggers tr, types_Lit l) {
    if (sriqctx_both_kinds(l, types_AKind_ak_x, types_AKind_ak_y)) {
        return sriqctx_flag_at(tr.out, l.pred);
    } else if (sriqctx_both_kinds(l, types_AKind_ak_y, types_AKind_ak_x)) {
        return sriqctx_flag_at(tr.in, l.pred);
    } else if (sriqctx_both_kinds(l, types_AKind_ak_u, types_AKind_ak_u)) {
        return sriqctx_flag_at(tr.body, l.pred);
    } else {
        return 0;
    }
}

uint8_t sriqctx_in_su(sriqctx_Triggers tr, types_Lit l) {
    uint8_t _retval = {0};
    __auto_type _mv_622 = l.form;
    if (_mv_622 == types_LitForm_lf_unary) {
        _retval = sriqctx_su_unary(tr, l);
        goto _slop_post;
    } else if (_mv_622 == types_LitForm_lf_binary) {
        _retval = sriqctx_su_binary(tr, l);
        goto _slop_post;
    } else if (_mv_622 == types_LitForm_lf_eq) {
        _retval = sriqctx_both_kinds(l, types_AKind_ak_u, types_AKind_ak_u);
        goto _slop_post;
    } else if (_mv_622 == types_LitForm_lf_neq) {
        _retval = 0;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

uint8_t sriqctx_pr_unary(sriqctx_Triggers tr, types_Lit l) {
    return ((sriqctx_is_kind(l.t1, types_AKind_ak_y) || sriqctx_is_kind(l.t1, types_AKind_ak_u)) && sriqctx_flag_at(tr.cls, l.pred));
}

uint8_t sriqctx_pr_binary(sriqctx_Triggers tr, types_Lit l) {
    if (sriqctx_both_kinds(l, types_AKind_ak_x, types_AKind_ak_y)) {
        return sriqctx_flag_at(tr.in, l.pred);
    } else if (sriqctx_both_kinds(l, types_AKind_ak_y, types_AKind_ak_x)) {
        return sriqctx_flag_at(tr.out, l.pred);
    } else if (sriqctx_both_kinds(l, types_AKind_ak_u, types_AKind_ak_u)) {
        return sriqctx_flag_at(tr.body, l.pred);
    } else {
        return 0;
    }
}

uint8_t sriqctx_pr_eq(types_Lit l) {
    return ((sriqctx_pair_kinds(l, types_AKind_ak_x, types_AKind_ak_y)) || (sriqctx_pair_kinds(l, types_AKind_ak_x, types_AKind_ak_u)) || (sriqctx_pair_kinds(l, types_AKind_ak_y, types_AKind_ak_u)) || (sriqctx_both_kinds(l, types_AKind_ak_u, types_AKind_ak_u)));
}

uint8_t sriqctx_in_pr(sriqctx_Triggers tr, types_Lit l) {
    uint8_t _retval = {0};
    __auto_type _mv_623 = l.form;
    if (_mv_623 == types_LitForm_lf_unary) {
        _retval = sriqctx_pr_unary(tr, l);
        goto _slop_post;
    } else if (_mv_623 == types_LitForm_lf_binary) {
        _retval = sriqctx_pr_binary(tr, l);
        goto _slop_post;
    } else if (_mv_623 == types_LitForm_lf_eq) {
        _retval = sriqctx_pr_eq(l);
        goto _slop_post;
    } else if (_mv_623 == types_LitForm_lf_neq) {
        _retval = 0;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

uint8_t sriqctx_sur_binary(sriqctx_Triggers tr, types_Lit l) {
    return ((sriqctx_pair_kinds(l, types_AKind_ak_y, types_AKind_ak_u) || sriqctx_both_kinds(l, types_AKind_ak_u, types_AKind_ak_u)) && sriqctx_flag_at(tr.role, l.pred));
}

uint8_t sriqctx_in_sur(sriqctx_Triggers tr, types_Lit l) {
    uint8_t _retval = {0};
    __auto_type _mv_624 = l.form;
    if (_mv_624 == types_LitForm_lf_unary) {
        _retval = (sriqctx_is_kind(l.t1, types_AKind_ak_u) && sriqctx_flag_at(tr.cls, l.pred));
        goto _slop_post;
    } else if (_mv_624 == types_LitForm_lf_binary) {
        _retval = sriqctx_sur_binary(tr, l);
        goto _slop_post;
    } else if (_mv_624 == types_LitForm_lf_eq) {
        _retval = sriqctx_both_kinds(l, types_AKind_ak_u, types_AKind_ak_u);
        goto _slop_post;
    } else if (_mv_624 == types_LitForm_lf_neq) {
        _retval = 0;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

uint8_t sriqctx_in_prr(sriqctx_Triggers tr, types_Lit l) {
    uint8_t _retval = {0};
    _retval = ((sriqctx_in_sur(tr, l)) || ((((l.form == types_LitForm_lf_unary)) && (sriqctx_is_kind(l.t1, types_AKind_ak_y)) && (sriqctx_flag_at(tr.cls, l.pred)))) || (((l.form == types_LitForm_lf_eq) && sriqctx_pair_kinds(l, types_AKind_ak_y, types_AKind_ak_u))));
    goto _slop_post;
    _slop_post: ;
    return _retval;
}

uint8_t sriqctx_aterm_ground(types_ATerm t) {
    return (sriqctx_is_kind(t, types_AKind_ak_u) || sriqctx_is_kind(t, types_AKind_ak_fu));
}

uint8_t sriqctx_lit_ground(types_Lit l) {
    if (l.form == types_LitForm_lf_unary) {
        return sriqctx_aterm_ground(l.t1);
    } else {
        return (sriqctx_aterm_ground(l.t1) && sriqctx_aterm_ground(l.t2));
    }
}

uint8_t sriqctx_aterm_has_x(types_ATerm t) {
    return (sriqctx_is_kind(t, types_AKind_ak_x) || sriqctx_is_kind(t, types_AKind_ak_fx));
}

uint8_t sriqctx_mentions_x(types_Lit l) {
    if (l.form == types_LitForm_lf_unary) {
        return sriqctx_aterm_has_x(l.t1);
    } else {
        return (sriqctx_aterm_has_x(l.t1) || sriqctx_aterm_has_x(l.t2));
    }
}

int64_t sriqctx_tau_su(sriqctx_Triggers tr) {
    int64_t _retval = {0};
    _retval = ((sriqctx_count_true(tr.unary)) + (sriqctx_count_true(tr.out)) + (sriqctx_count_true(tr.in)));
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    return _retval;
}

int64_t sriqctx_tau_pr(sriqctx_Triggers tr) {
    int64_t _retval = {0};
    _retval = ((sriqctx_count_true(tr.cls)) + (sriqctx_count_true(tr.out)) + (sriqctx_count_true(tr.in)));
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    return _retval;
}

int64_t sriqctx_pow2_sat(int64_t k) {
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

int64_t sriqctx_omega(sriqctx_Strategy s, sriqctx_Triggers tr) {
    int64_t _retval = {0};
    __auto_type _mv_625 = s;
    if (_mv_625 == sriqctx_Strategy_st_trivial) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_625 == sriqctx_Strategy_st_cautious) {
        _retval = sriqctx_count_true(tr.cls);
        goto _slop_post;
    } else if (_mv_625 == sriqctx_Strategy_st_eager) {
        _retval = sriqctx_pow2_sat(((sriqctx_count_true(tr.cls)) + (sriqctx_count_true(tr.role)) + (1)));
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

int64_t sriqctx_omega_d(int64_t nquery) {
    int64_t _retval = {0};
    _retval = (nquery + 2);
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval == (nquery + 2))), "(== $result (+ nquery 2))");
    return _retval;
}

sriqctx_CoreChoice sriqctx_choice_of(sriqctx_CoreKind k, uint32_t b) {
    sriqctx_CoreChoice _retval = {0};
    _retval = ((sriqctx_CoreChoice){.kind = k, .cls = b});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.kind == k)), "(== (. $result kind) k)");
    SLOP_POST(((_retval.cls == b)), "(== (. $result cls) b)");
    return _retval;
}

sriqctx_CoreChoice sriqctx_cautious_choice(sriqctx_Triggers tr, uint32_t f, slop_list_types_Lit k1) {
    sriqctx_CoreChoice _retval = {0};
    {
        __auto_type b = sriqctx_sole_at(tr, f);
        if ((b != sriqctx_no_id()) && sriqctx_has_lit(k1, types_atom1(b, types_at_x()))) {
            _retval = sriqctx_choice_of(sriqctx_CoreKind_cc_unary, b);
            goto _slop_post;
        } else {
            _retval = sriqctx_choice_of(sriqctx_CoreKind_cc_empty, sriqctx_no_id());
            goto _slop_post;
        }
    }
    _slop_post: ;
    SLOP_POST((((_retval.kind == sriqctx_CoreKind_cc_empty) || (_retval.kind == sriqctx_CoreKind_cc_unary))), "(or (== (. $result kind) (quote cc-empty)) (== (. $result kind) (quote cc-unary)))");
    return _retval;
}

sriqctx_CoreChoice sriqctx_strat_choice(sriqctx_Strategy s, sriqctx_Triggers tr, uint32_t f, slop_list_types_Lit k1) {
    sriqctx_CoreChoice _retval = {0};
    __auto_type _mv_626 = s;
    if (_mv_626 == sriqctx_Strategy_st_trivial) {
        _retval = sriqctx_choice_of(sriqctx_CoreKind_cc_empty, sriqctx_no_id());
        goto _slop_post;
    } else if (_mv_626 == sriqctx_Strategy_st_eager) {
        _retval = sriqctx_choice_of(sriqctx_CoreKind_cc_k1, sriqctx_no_id());
        goto _slop_post;
    } else if (_mv_626 == sriqctx_Strategy_st_cautious) {
        _retval = sriqctx_cautious_choice(tr, f, k1);
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

slop_list_types_Lit sriqctx_core_of(slop_arena* arena, sriqctx_CoreChoice cc, slop_list_types_Lit k1) {
    if (cc.kind == sriqctx_CoreKind_cc_k1) {
        return k1;
    } else {
        if (cc.kind == sriqctx_CoreKind_cc_unary) {
            {
                __auto_type one = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                ({ __auto_type _lst_p = &(one); __auto_type _item = (types_atom1(cc.cls, types_at_x())); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                return one;
            }
        } else {
            {
                __auto_type none_such = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                return none_such;
            }
        }
    }
}

sriqctx_Structure sriqctx_init_structure(slop_arena* arena, int64_t nquery, int64_t nconst) {
    SLOP_PRE((((nquery >= 0) && (nconst >= 0))), "(and (>= nquery 0) (>= nconst 0))");
    {
        __auto_type ctxs = ((slop_list_sriqctx_Ctx){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type sets = ((slop_list_sriqctx_CtxSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t b = 0;
        ({ __auto_type _lst_p = &(ctxs); __auto_type _item = (((sriqctx_Ctx){.core = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .root = 1})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ctxs); __auto_type _item = (((sriqctx_Ctx){.core = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .root = 0})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        while (b < nquery) {
            {
                __auto_type core = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                ({ __auto_type _lst_p = &(core); __auto_type _item = (types_atom1(((uint32_t)(b)), types_at_x())); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ctxs); __auto_type _item = (((sriqctx_Ctx){.core = core, .root = 0})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                b = (b + 1);
            }
        }
        b = 0;
        while (b < (nquery + 2)) {
            ({ __auto_type _lst_p = &(sets); __auto_type _item = (((sriqctx_CtxSet){.cs = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            b = (b + 1);
        }
        return ((sriqctx_Structure){.ctxs = ctxs, .sets = sets, .edges = ((slop_list_sriqctx_Edge){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .ord = sriqorder_named_consts(arena, nconst)});
    }
}

int64_t sriqctx_ctx_count(sriqctx_Structure st) {
    return ((int64_t)(((int64_t)((st.ctxs).len))));
}

slop_option_sriqctx_Ctx sriqctx_ctx_at(sriqctx_Structure st, int64_t v) {
    return ({ __auto_type _lst = st.ctxs; size_t _idx = (size_t)v; slop_option_sriqctx_Ctx _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
}

slop_option_sriqctx_CtxSet sriqctx_set_at(sriqctx_Structure st, int64_t v) {
    return ({ __auto_type _lst = st.sets; size_t _idx = (size_t)v; slop_option_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
}

uint8_t sriqctx_lits_same(slop_list_types_Lit a, slop_list_types_Lit b) {
    {
        uint8_t ok = (((int64_t)((a).len)) == ((int64_t)((b).len)));
        int64_t i = 0;
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                __auto_type _mv_627 = ({ __auto_type _lst = b; size_t _idx = (size_t)i; slop_option_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_627.has_value) {
                    __auto_type m = _mv_627.value;
                    if (!(types_lit_eq(l, m))) {
                        ok = 0;
                    }
                } else if (!_mv_627.has_value) {
                    ok = 0;
                }
                i = (i + 1);
            }
        }
        return ok;
    }
}

uint8_t sriqctx_core_matches(sriqctx_Ctx c, slop_list_types_Lit core) {
    return (!(c.root) && sriqctx_lits_same(c.core, core));
}

uint32_t sriqctx_ctx_by_core(sriqctx_Structure st, slop_list_types_Lit core) {
    uint32_t _retval = {0};
    {
        uint32_t v = ((uint32_t)(0));
        uint32_t found = sriqctx_no_id();
        {
            __auto_type _coll = st.ctxs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (((v > ((uint32_t)(0)))) && ((found == sriqctx_no_id())) && (sriqctx_core_matches(c, core))) {
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

uint8_t sriqctx_var_ok(types_ATerm t, uint8_t root) {
    __auto_type _mv_628 = t.kind;
    if (_mv_628 == types_AKind_ak_x) {
        return !(root);
    } else if (_mv_628 == types_AKind_ak_fx) {
        return !(root);
    } else if (_mv_628 == types_AKind_ak_fu) {
        return root;
    } else if (_mv_628 == types_AKind_ak_y) {
        return 1;
    } else if (_mv_628 == types_AKind_ak_u) {
        return 1;
    } else if (_mv_628 == types_AKind_ak_z) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqctx_side_x(types_ATerm s, types_ATerm t) {
    return (sriqctx_is_kind(s, types_AKind_ak_x) && !(sriqctx_is_kind(t, types_AKind_ak_z)));
}

uint8_t sriqctx_side_u(types_ATerm s, types_ATerm t) {
    return (sriqctx_is_kind(s, types_AKind_ak_u) && ((sriqctx_is_kind(t, types_AKind_ak_y)) || (sriqctx_is_kind(t, types_AKind_ak_u)) || (sriqctx_is_kind(t, types_AKind_ak_fu))));
}

uint8_t sriqctx_binary_ok(types_Lit l) {
    {
        __auto_type s = l.t1;
        __auto_type t = l.t2;
        return ((sriqctx_side_x(s, t)) || (sriqctx_side_x(t, s)) || (sriqctx_side_u(s, t)) || (sriqctx_side_u(t, s)));
    }
}

uint8_t sriqctx_lit_ok(types_Lit l, uint8_t root) {
    if (l.form == types_LitForm_lf_unary) {
        return sriqctx_var_ok(l.t1, root);
    } else {
        return ((sriqctx_var_ok(l.t1, root)) && (sriqctx_var_ok(l.t2, root)) && ((!((l.form == types_LitForm_lf_binary)) || sriqctx_binary_ok(l))));
    }
}

uint8_t sriqctx_body_lit_ok(types_Lit l, uint8_t root) {
    return (sriqctx_lit_ok(l, root) && (((l.form == types_LitForm_lf_unary)) || ((l.form == types_LitForm_lf_binary)) || (((l.form == types_LitForm_lf_eq) && sriqctx_both_kinds(l, types_AKind_ak_u, types_AKind_ak_u)))));
}

uint8_t sriqctx_ctx_clause_ok(uint8_t root, types_Clause c) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(sriqctx_body_lit_ok(l, root))) {
                    ok = 0;
                }
            }
        }
        {
            __auto_type _coll = c.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(sriqctx_lit_ok(l, root))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

slop_list_types_Clause sriqctx_set_or_none(slop_arena* arena, sriqctx_Structure st, int64_t v) {
    __auto_type _mv_629 = ({ __auto_type _lst = st.sets; size_t _idx = (size_t)v; slop_option_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_629.has_value) {
        __auto_type s = _mv_629.value;
        return s.cs;
    } else if (!_mv_629.has_value) {
        return ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqctx_q_of(slop_arena* arena, sriqctx_Structure st, int64_t v, slop_list_types_Lit body, slop_list_types_Lit head) {
    return sriqsubsume_in_hat(sriqclauses_make_clause(arena, body, head), sriqctx_set_or_none(arena, st, v));
}

slop_list_types_Lit sriqctx_atom_x(slop_arena* arena, uint32_t b) {
    {
        __auto_type out = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_atom1(b, types_at_x())); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

uint8_t sriqctx_q_inconsistent(slop_arena* arena, sriqctx_Structure st) {
    return sriqctx_q_of(arena, st, 1, ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
}

uint8_t sriqctx_q_unsat(slop_arena* arena, sriqctx_Structure st, uint32_t b) {
    return sriqctx_q_of(arena, st, (2 + ((int64_t)(b))), sriqctx_atom_x(arena, b), ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
}

uint8_t sriqctx_q_holds(slop_arena* arena, sriqctx_Structure st, uint32_t b, uint32_t a) {
    return sriqctx_q_of(arena, st, (2 + ((int64_t)(b))), sriqctx_atom_x(arena, b), sriqctx_atom_x(arena, a));
}

uint8_t sriqctx_q_thing(slop_arena* arena, sriqctx_Structure st, uint32_t a) {
    return sriqctx_q_of(arena, st, 1, ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), sriqctx_atom_x(arena, a));
}

