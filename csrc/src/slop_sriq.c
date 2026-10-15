#include "../runtime/slop_runtime.h"
#include "slop_sriq.h"

howl_types_Lit howl_sriq_lit_at(slop_list_howl_types_Lit xs, int64_t i);
slop_list_howl_types_Lit howl_sriq_without_at(slop_arena* arena, slop_list_howl_types_Lit xs, int64_t i);
howl_sriq_Premise howl_sriq_select(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_types_Clause c, int64_t i);
howl_types_Clause howl_sriq_assemble(slop_arena* arena, howl_sriq_RConcl r);
slop_list_howl_types_Lit howl_sriq_appended(slop_arena* arena, slop_list_howl_types_Lit a, slop_list_howl_types_Lit b);
howl_sriq_RConcl howl_sriq_core_rule(slop_arena* arena, howl_types_Lit a);
howl_sriq_RConcl howl_sriq_ineq_rule(howl_sriq_Premise p);
uint8_t howl_sriq_has_side(howl_types_Lit l, howl_types_ATerm s);
howl_types_ATerm howl_sriq_other_side(howl_types_Lit l, howl_types_ATerm s);
uint8_t howl_sriq_holds_lit(slop_list_howl_types_Lit ls, howl_types_Lit l);
slop_list_howl_types_Lit howl_sriq_without_lit(slop_arena* arena, slop_list_howl_types_Lit ls, howl_types_Lit l);
howl_sriq_RConcl howl_sriq_factor_rule(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriq_Premise p, howl_types_Lit l1, howl_types_ATerm s);
slop_option_howl_types_ATerm howl_sriq_z_image(howl_sriq_Subst sub, int64_t i);
uint8_t howl_sriq_term_matches(howl_sriq_Subst sub, howl_types_ATerm a, howl_types_ATerm l);
howl_sriq_Subst howl_sriq_bind_term(slop_arena* arena, howl_sriq_Subst sub, howl_types_ATerm a, howl_types_ATerm l);
uint8_t howl_sriq_atom_matches(howl_sriq_Subst sub, howl_types_Lit a, howl_types_Lit l);
howl_sriq_Subst howl_sriq_bind_atom(slop_arena* arena, howl_sriq_Subst sub, howl_types_Lit a, howl_types_Lit l);
howl_sriq_HState howl_sriq_hyper_start(slop_arena* arena, howl_types_ATerm x, uint8_t bound);
howl_sriq_HState howl_sriq_hyper_step(slop_arena* arena, howl_sriq_HState st, howl_types_Lit a, howl_sriq_Premise p);
howl_types_ATerm howl_sriq_apply_term(howl_sriq_Subst sub, howl_types_ATerm t);
howl_types_Lit howl_sriq_apply_lit(howl_sriq_Subst sub, howl_types_Lit l);
howl_sriq_RConcl howl_sriq_hyper_finish(slop_arena* arena, howl_sriq_HState st, slop_list_howl_types_Lit delta);
slop_list_howl_sriq_HState howl_sriq_extend_one(slop_arena* arena, howl_sriq_HState st, howl_types_Lit a, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriq_HState howl_sriq_extend_all(slop_arena* arena, slop_list_howl_sriq_HState sts, howl_types_Lit a, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriq_RConcl howl_sriq_hyper_join(slop_arena* arena, howl_sriq_HState start, slop_list_howl_types_Lit atoms, slop_list_howl_sriq_Cands cands, slop_list_howl_types_Lit delta);
uint32_t howl_sriq_other_arg(uint32_t k);
howl_types_ATerm howl_sriq_arg_term(howl_types_Lit l, uint32_t k);
uint8_t howl_sriq_has_arg(howl_types_Lit l, uint32_t k);
slop_option_howl_types_ATerm howl_sriq_inner_of(howl_types_ATerm a);
slop_option_howl_types_ATerm howl_sriq_subterm_at(howl_types_Lit l, howl_sriq_Pos p);
howl_types_ATerm howl_sriq_with_inner(howl_types_ATerm a, howl_types_ATerm t);
howl_types_Lit howl_sriq_with_arg(howl_types_Lit l, uint32_t k, howl_types_ATerm t);
howl_types_Lit howl_sriq_replace_at(howl_types_Lit l, howl_sriq_Pos p, howl_types_ATerm t);
howl_types_ATerm howl_sriq_replace_const(howl_types_ATerm a, howl_types_ATerm s, howl_types_ATerm t);
howl_types_Lit howl_sriq_replace_all(howl_types_Lit l, howl_sriq_Pos p, howl_types_ATerm s, howl_types_ATerm t);
uint8_t howl_sriq_side_ok(howl_sriqorder_SriqOrder ord, howl_types_Lit l, uint32_t k);
uint8_t howl_sriq_kinds_are(howl_types_ATerm a, howl_types_ATerm b, howl_types_AKind p, howl_types_AKind q);
uint8_t howl_sriq_eq_usable(howl_types_ATerm s1, howl_types_ATerm t1);
uint8_t howl_sriq_plain(howl_types_ATerm a);
uint8_t howl_sriq_s2_plain(howl_types_Lit l, howl_sriq_Pos p);
uint8_t howl_sriq_x_ok(howl_types_Lit l, howl_sriq_Pos p, howl_types_ATerm s1);
uint8_t howl_sriq_at_is(slop_option_howl_types_ATerm o, howl_types_ATerm s);
howl_sriq_RConcl howl_sriq_eq_rule(slop_arena* arena, howl_sriqorder_SriqOrder ord, uint8_t root, howl_sriq_Premise p1, uint32_t k1, howl_sriq_Premise p2, howl_sriq_Pos p);
howl_sriq_BodyView howl_sriq_body_at(slop_arena* arena, howl_types_Clause c, int64_t i);
uint8_t howl_sriq_ground(howl_types_ATerm a);
uint8_t howl_sriq_joinable(howl_types_Lit a);
howl_sriq_RConcl howl_sriq_join_rule(slop_arena* arena, howl_sriq_Premise p1, howl_sriq_BodyView b);
uint8_t howl_sriq_kid_ok(howl_sriqorder_SriqOrder ord, uint32_t o, uint32_t sb2, uint32_t i, uint32_t k);
uint8_t howl_sriq_kids_ok(howl_sriqorder_SriqOrder ord, uint32_t o, uint32_t sb2, uint32_t n, slop_list_u32 kids);
slop_list_howl_types_Lit howl_sriq_nom_head(slop_arena* arena, slop_list_u32 kids);
uint8_t howl_sriq_nom_premises(howl_sriq_Premise p1, howl_sriq_Premise p2, uint32_t b1, uint32_t sb2);
howl_sriq_RConcl howl_sriq_nom_rule(slop_arena* arena, howl_sriqorder_SriqOrder ord, int64_t lam, uint32_t b1, uint32_t sb2, uint32_t n, howl_sriq_Premise p1, howl_sriq_Premise p2, slop_list_u32 kids);
howl_types_ATerm howl_sriq_csub_term(howl_sriq_CSub s, howl_types_ATerm t);
howl_types_Lit howl_sriq_csub_lit(howl_sriq_CSub s, howl_types_Lit l);
howl_sriq_CSub howl_sriq_succ_csub(howl_sriq_SuccSig sg);
uint8_t howl_sriq_is_succ_term(howl_sriq_SuccSig sg, howl_types_ATerm t);
uint8_t howl_sriq_is_atom(howl_types_Lit l);
uint8_t howl_sriq_succ_mentions(howl_sriq_SuccSig sg, howl_types_Lit l);
slop_option_howl_sriq_SuccSig howl_sriq_sig_of_term(uint8_t root, howl_types_ATerm t);
slop_option_howl_sriq_SuccSig howl_sriq_succ_sig(uint8_t root, howl_types_Lit l);
howl_sriq_PreLit howl_sriq_pre_none(howl_types_Lit l);
howl_sriq_PreLit howl_sriq_pre_some(howl_types_Lit a);
howl_sriq_PreLit howl_sriq_pre_binary(howl_sriq_SuccSig sg, howl_types_Lit l);
howl_sriq_PreLit howl_sriq_succ_pre(howl_sriq_SuccSig sg, howl_types_Lit l);
uint8_t howl_sriq_has_fterm(howl_types_Lit l);
howl_sriq_PreLit howl_sriq_k_of_lit(howl_sriqctx_Triggers tr, howl_sriq_SuccSig sg, howl_types_Lit l);
howl_sriq_KSets howl_sriq_k_of_clause(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriqctx_Triggers tr, howl_sriq_SuccSig sg, howl_types_Clause c);
howl_sriq_KSets howl_sriq_k_sets(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriqctx_Triggers tr, howl_sriq_SuccSig sg, slop_list_howl_types_Clause cs);
uint8_t howl_sriq_within_one(slop_list_howl_types_Lit ls, howl_types_Lit a);
uint8_t howl_sriq_unit_held(howl_types_Lit a, slop_list_howl_types_Clause ws);
uint8_t howl_sriq_covers(slop_list_howl_types_Lit k2, slop_list_howl_types_Lit core, slop_list_howl_types_Clause ws);
howl_sriq_SuccConcl howl_sriq_succ_step(slop_arena* arena, howl_sriqctx_Strategy s, howl_sriqctx_Triggers tr, howl_sriq_SuccSig sg, howl_sriq_Premise p, howl_sriq_KSets ks, uint8_t covered);
howl_types_ATerm howl_sriq_x_to_y(howl_types_ATerm t);
howl_types_Lit howl_sriq_rsucc_lit(howl_types_Lit l);
uint8_t howl_sriq_has_y(howl_types_Lit l);
uint8_t howl_sriq_has_const(howl_types_Lit l, uint32_t u);
howl_sriq_RSuccConcl howl_sriq_rsucc_rule(howl_sriqctx_Triggers tr, uint8_t root, howl_sriq_Premise p, uint32_t u, uint8_t held);
howl_sriq_PredView howl_sriq_pred_view(slop_arena* arena, howl_types_Clause c, slop_list_howl_types_Lit core, uint8_t to_root);
howl_sriq_PredView howl_sriq_rpred_view(slop_arena* arena, howl_sriqctx_Triggers tr, howl_types_Clause c);
howl_sriq_PState howl_sriq_pred_start(slop_arena* arena, uint8_t edge);
howl_sriq_PState howl_sriq_pred_step(slop_arena* arena, howl_sriq_PState st, howl_sriq_CSub s, howl_sriq_PSlot slot, howl_sriq_Premise p);
uint8_t howl_sriq_is_xu(howl_types_Lit l);
uint8_t howl_sriq_pred_head_ok(howl_sriqctx_Triggers tr, uint8_t to_root, howl_types_Lit l);
uint8_t howl_sriq_pred_heads_ok(howl_sriqctx_Triggers tr, uint8_t to_root, slop_list_howl_types_Lit ls);
uint8_t howl_sriq_rpred_head_ok(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_sriq_rpred_heads_ok(howl_sriqctx_Triggers tr, slop_list_howl_types_Lit ls);
slop_list_howl_types_Lit howl_sriq_mapped(slop_arena* arena, howl_sriq_CSub s, slop_list_howl_types_Lit ls);
howl_sriq_RConcl howl_sriq_pred_finish(slop_arena* arena, howl_sriq_PState st, howl_sriq_CSub s, howl_sriqctx_Triggers tr, uint8_t to_root, howl_sriq_PredView v);
howl_sriq_RConcl howl_sriq_rpred_finish(slop_arena* arena, howl_sriq_PState st, howl_sriqctx_Triggers tr, howl_sriq_PredView v);
slop_list_howl_sriq_PState howl_sriq_pred_extend_one(slop_arena* arena, howl_sriq_PState st, howl_sriq_CSub s, howl_sriq_PSlot slot, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriq_PState howl_sriq_pred_join(slop_arena* arena, howl_sriq_PState start, howl_sriq_CSub s, slop_list_howl_sriq_PCands cs);
int64_t howl_sriq_depth_limit(int64_t tsu, int64_t tpr, int64_t omega, int64_t omega_d);
int64_t howl_sriq_stored_lambda(int64_t tsu, int64_t tpr, int64_t omega, int64_t omega_d);
uint8_t howl_sriq_lits_same(slop_list_howl_types_Lit a, slop_list_howl_types_Lit b);
uint8_t howl_sriq_rconcl_eq(howl_sriq_RConcl a, howl_sriq_RConcl b);
uint8_t howl_sriq_fires_is(howl_sriq_RConcl a, howl_sriq_RConcl b);
uint8_t howl_sriq_hstate_eq(howl_sriq_HState a, howl_sriq_HState b);
howl_types_ATerm howl_sriq_ex_fx(int64_t f);
howl_types_ATerm howl_sriq_ex_u(int64_t u);
howl_types_Lit howl_sriq_ex_a1(int64_t b, howl_types_ATerm t);
howl_types_Lit howl_sriq_ex_a2(int64_t r, howl_types_ATerm a, howl_types_ATerm b);
howl_sriq_Pos howl_sriq_ex_pos(int64_t k, uint8_t inner);
uint32_t howl_sriq_ex_side(howl_types_Lit l, howl_types_ATerm s);
slop_list_howl_types_Lit howl_sriq_ex_l0(slop_arena* arena);
slop_list_howl_types_Lit howl_sriq_ex_l1(slop_arena* arena, howl_types_Lit a);
slop_list_howl_types_Lit howl_sriq_ex_l2(slop_arena* arena, howl_types_Lit a, howl_types_Lit b);
slop_list_howl_types_Lit howl_sriq_ex_l3(slop_arena* arena, howl_types_Lit a, howl_types_Lit b, howl_types_Lit c);
howl_sriqorder_SriqOrder howl_sriq_ex_ord(slop_arena* arena);
howl_sriq_Premise howl_sriq_ex_sel(slop_arena* arena, slop_list_howl_types_Lit head, howl_types_Lit l);
howl_sriq_Premise howl_sriq_ex_fac(slop_arena* arena);
howl_sriq_BodyView howl_sriq_ex_body(slop_arena* arena, slop_list_howl_types_Lit body, slop_list_howl_types_Lit head, howl_types_Lit l);
howl_sriq_RConcl howl_sriq_ex_rc(slop_arena* arena, uint8_t fires, slop_list_howl_types_Lit body, slop_list_howl_types_Lit head);
howl_sriq_HState howl_sriq_ex_hs(slop_arena* arena, uint8_t fires, slop_list_howl_types_Lit body, slop_list_howl_types_Lit head);
howl_sriqorder_SriqOrder howl_sriq_ex_kids_ord(slop_arena* arena);
slop_list_u32 howl_sriq_ex_ids(slop_arena* arena, int64_t k);

howl_types_Lit howl_sriq_lit_at(slop_list_howl_types_Lit xs, int64_t i) {
    __auto_type _mv_459 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_459.has_value) {
        __auto_type l = _mv_459.value;
        return l;
    } else if (!_mv_459.has_value) {
        return howl_types_atom1(((uint32_t)(0)), howl_types_at_x());
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Lit howl_sriq_without_at(slop_arena* arena, slop_list_howl_types_Lit xs, int64_t i) {
    {
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (k != i) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                k = (k + 1);
            }
        }
        return out;
    }
}

howl_sriq_Premise howl_sriq_select(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_types_Clause c, int64_t i) {
    SLOP_PRE((((i >= 0) && (i < ((int64_t)(((int64_t)((c.head).len))))))), "(and (>= i 0) (< i (cast Int (list-len (. c head)))))");
    return ((howl_sriq_Premise){.body = c.body, .sel = howl_sriq_lit_at(c.head, i), .rest = howl_sriq_without_at(arena, c.head, i), .maxed = howl_sriqorder_maximal_at(arena, ord, c.head, i)});
}

howl_types_Clause howl_sriq_assemble(slop_arena* arena, howl_sriq_RConcl r) {
    return howl_sriqclauses_make_clause(arena, r.body, r.head);
}

slop_list_howl_types_Lit howl_sriq_appended(slop_arena* arena, slop_list_howl_types_Lit a, slop_list_howl_types_Lit b) {
    {
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = b;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_sriq_RConcl howl_sriq_core_rule(slop_arena* arena, howl_types_Lit a) {
    {
        __auto_type h = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(h); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return ((howl_sriq_RConcl){.fires = 1, .body = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .head = h});
    }
}

howl_sriq_RConcl howl_sriq_ineq_rule(howl_sriq_Premise p) {
    {
        __auto_type l = p.sel;
        return ((howl_sriq_RConcl){.fires = ((l.form == howl_types_LitForm_lf_neq) && howl_types_aterm_eq(l.t1, l.t2)), .body = p.body, .head = p.rest});
    }
}

uint8_t howl_sriq_has_side(howl_types_Lit l, howl_types_ATerm s) {
    return ((l.form == howl_types_LitForm_lf_eq) && (howl_types_aterm_eq(l.t1, s) || howl_types_aterm_eq(l.t2, s)));
}

howl_types_ATerm howl_sriq_other_side(howl_types_Lit l, howl_types_ATerm s) {
    howl_types_ATerm _retval = {0};
    if (howl_types_aterm_eq(l.t1, s)) {
        _retval = l.t2;
        goto _slop_post;
    } else {
        _retval = l.t1;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((({ howl_types_ATerm _eq_l_460 = (_retval); howl_types_ATerm _eq_r_461 = (l.t1); slop_eq_howl_types_ATerm(&_eq_l_460, &_eq_r_461); }) || ({ howl_types_ATerm _eq_l_462 = (_retval); howl_types_ATerm _eq_r_463 = (l.t2); slop_eq_howl_types_ATerm(&_eq_l_462, &_eq_r_463); }))), "(or (== $result (. l t1)) (== $result (. l t2)))");
    return _retval;
}

uint8_t howl_sriq_holds_lit(slop_list_howl_types_Lit ls, howl_types_Lit l) {
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

slop_list_howl_types_Lit howl_sriq_without_lit(slop_arena* arena, slop_list_howl_types_Lit ls, howl_types_Lit l) {
    slop_list_howl_types_Lit _retval = {0};
    {
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ls;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (!(howl_types_lit_eq(x, l))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        _retval = out;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

howl_sriq_RConcl howl_sriq_factor_rule(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriq_Premise p, howl_types_Lit l1, howl_types_ATerm s) {
    {
        __auto_type t1 = howl_sriq_other_side(l1, s);
        __auto_type t2 = howl_sriq_other_side(p.sel, s);
        __auto_type h = howl_sriq_without_lit(arena, p.rest, l1);
        (void)(({ __auto_type _lst_p = &(h); __auto_type _item = (howl_types_neq_lit(t1, t2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(h); __auto_type _item = (p.sel); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return ((howl_sriq_RConcl){.fires = ((p.maxed) && (howl_sriq_has_side(p.sel, s)) && (howl_sriq_has_side(l1, s)) && (howl_sriq_holds_lit(p.rest, l1)) && (!(howl_sriqorder_aterm_gt(ord, t2, s)))), .body = p.body, .head = h});
    }
}

slop_option_howl_types_ATerm howl_sriq_z_image(howl_sriq_Subst sub, int64_t i) {
    {
        int64_t k = 0;
        slop_option_howl_types_ATerm found = (slop_option_howl_types_ATerm){.has_value = false};
        {
            __auto_type _coll = sub.zs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type j = _coll.data[_i];
                if (j == i) {
                    __auto_type _mv_464 = ({ __auto_type _lst = sub.ts; size_t _idx = (size_t)k; slop_option_howl_types_ATerm _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_464.has_value) {
                        __auto_type t = _mv_464.value;
                        found = (slop_option_howl_types_ATerm){.has_value = 1, .value = t};
                    } else if (!_mv_464.has_value) {
                    }
                }
                k = (k + 1);
            }
        }
        return found;
    }
}

uint8_t howl_sriq_term_matches(howl_sriq_Subst sub, howl_types_ATerm a, howl_types_ATerm l) {
    __auto_type _mv_465 = a.kind;
    if (_mv_465 == howl_types_AKind_ak_x) {
        if (sub.xbound) {
            return howl_types_aterm_eq(sub.x, l);
        } else {
            return (l.kind == howl_types_AKind_ak_u);
        }
    } else if (_mv_465 == howl_types_AKind_ak_z) {
        __auto_type _mv_466 = howl_sriq_z_image(sub, ((int64_t)(a.zi)));
        if (_mv_466.has_value) {
            __auto_type t = _mv_466.value;
            return howl_types_aterm_eq(t, l);
        } else if (!_mv_466.has_value) {
            return 1;
        }
        SLOP_UNREACHABLE();
    } else if (_mv_465 == howl_types_AKind_ak_y) {
        return 0;
    } else if (_mv_465 == howl_types_AKind_ak_fx) {
        return 0;
    } else if (_mv_465 == howl_types_AKind_ak_u) {
        return 0;
    } else if (_mv_465 == howl_types_AKind_ak_fu) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

howl_sriq_Subst howl_sriq_bind_term(slop_arena* arena, howl_sriq_Subst sub, howl_types_ATerm a, howl_types_ATerm l) {
    __auto_type _mv_467 = a.kind;
    if (_mv_467 == howl_types_AKind_ak_x) {
        return ((howl_sriq_Subst){.x = l, .xbound = 1, .zs = sub.zs, .ts = sub.ts});
    } else if (_mv_467 == howl_types_AKind_ak_z) {
        __auto_type _mv_468 = howl_sriq_z_image(sub, ((int64_t)(a.zi)));
        if (_mv_468.has_value) {
            __auto_type _ = _mv_468.value;
            return sub;
        } else if (!_mv_468.has_value) {
            {
                __auto_type zs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                __auto_type ts = ((slop_list_howl_types_ATerm){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
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
                return ((howl_sriq_Subst){.x = sub.x, .xbound = sub.xbound, .zs = zs, .ts = ts});
            }
        }
        SLOP_UNREACHABLE();
    } else if (_mv_467 == howl_types_AKind_ak_y) {
        return sub;
    } else if (_mv_467 == howl_types_AKind_ak_fx) {
        return sub;
    } else if (_mv_467 == howl_types_AKind_ak_u) {
        return sub;
    } else if (_mv_467 == howl_types_AKind_ak_fu) {
        return sub;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriq_atom_matches(howl_sriq_Subst sub, howl_types_Lit a, howl_types_Lit l) {
    uint8_t _retval = {0};
    _retval = (((a.form == l.form)) && ((a.pred == l.pred)) && (((a.form == howl_types_LitForm_lf_unary) || (a.form == howl_types_LitForm_lf_binary))) && (howl_sriq_term_matches(sub, a.t1, l.t1)) && (((a.form == howl_types_LitForm_lf_unary) || (howl_sriq_term_matches(sub, a.t2, l.t2) && (!(howl_types_aterm_eq(a.t1, a.t2)) || howl_types_aterm_eq(l.t1, l.t2))))));
    goto _slop_post;
    _slop_post: ;
    return _retval;
}

howl_sriq_Subst howl_sriq_bind_atom(slop_arena* arena, howl_sriq_Subst sub, howl_types_Lit a, howl_types_Lit l) {
    {
        __auto_type s1 = howl_sriq_bind_term(arena, sub, a.t1, l.t1);
        if (a.form == howl_types_LitForm_lf_binary) {
            return howl_sriq_bind_term(arena, s1, a.t2, l.t2);
        } else {
            return s1;
        }
    }
}

howl_sriq_HState howl_sriq_hyper_start(slop_arena* arena, howl_types_ATerm x, uint8_t bound) {
    howl_sriq_HState _retval = {0};
    _retval = ((howl_sriq_HState){.fires = 1, .sub = ((howl_sriq_Subst){.x = x, .xbound = bound, .zs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .ts = ((slop_list_howl_types_ATerm){ .data = NULL, .len = 0, .cap = 0, .arena = arena })}), .body = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .head = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST((((_retval.fires) && (({ howl_types_ATerm _eq_l_469 = (_retval.sub.x); howl_types_ATerm _eq_r_470 = (x); slop_eq_howl_types_ATerm(&_eq_l_469, &_eq_r_470); })) && ((_retval.sub.xbound == bound)))), "(and (. $result fires) (== (. (. $result sub) x) x) (== (. (. $result sub) xbound) bound))");
    return _retval;
}

howl_sriq_HState howl_sriq_hyper_step(slop_arena* arena, howl_sriq_HState st, howl_types_Lit a, howl_sriq_Premise p) {
    return ((howl_sriq_HState){.fires = ((st.fires) && (p.maxed) && (howl_sriq_atom_matches(st.sub, a, p.sel))), .sub = howl_sriq_bind_atom(arena, st.sub, a, p.sel), .body = howl_sriq_appended(arena, st.body, p.body), .head = howl_sriq_appended(arena, st.head, p.rest)});
}

howl_types_ATerm howl_sriq_apply_term(howl_sriq_Subst sub, howl_types_ATerm t) {
    howl_types_ATerm _retval = {0};
    __auto_type _mv_471 = t.kind;
    if (_mv_471 == howl_types_AKind_ak_x) {
        _retval = sub.x;
        goto _slop_post;
    } else if (_mv_471 == howl_types_AKind_ak_z) {
        __auto_type _mv_472 = howl_sriq_z_image(sub, ((int64_t)(t.zi)));
        if (_mv_472.has_value) {
            __auto_type v = _mv_472.value;
            _retval = v;
            goto _slop_post;
        } else if (!_mv_472.has_value) {
            _retval = t;
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    } else if (_mv_471 == howl_types_AKind_ak_fx) {
        if (sub.x.kind == howl_types_AKind_ak_u) {
            _retval = howl_types_at_fu(t.fsym, sub.x.cst);
            goto _slop_post;
        } else {
            _retval = t;
            goto _slop_post;
        }
    } else if (_mv_471 == howl_types_AKind_ak_y) {
        _retval = t;
        goto _slop_post;
    } else if (_mv_471 == howl_types_AKind_ak_u) {
        _retval = t;
        goto _slop_post;
    } else if (_mv_471 == howl_types_AKind_ak_fu) {
        _retval = t;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

howl_types_Lit howl_sriq_apply_lit(howl_sriq_Subst sub, howl_types_Lit l) {
    howl_types_Lit _retval = {0};
    {
        __auto_type a = howl_sriq_apply_term(sub, l.t1);
        __auto_type b = howl_sriq_apply_term(sub, l.t2);
        __auto_type _mv_473 = l.form;
        if (_mv_473 == howl_types_LitForm_lf_unary) {
            _retval = howl_types_atom1(l.pred, a);
            goto _slop_post;
        } else if (_mv_473 == howl_types_LitForm_lf_binary) {
            _retval = howl_types_atom2(l.pred, a, b);
            goto _slop_post;
        } else if (_mv_473 == howl_types_LitForm_lf_eq) {
            _retval = howl_types_eq_lit(a, b);
            goto _slop_post;
        } else if (_mv_473 == howl_types_LitForm_lf_neq) {
            _retval = howl_types_neq_lit(a, b);
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    }
    _slop_post: ;
    SLOP_POST(((_retval.form == l.form)), "(== (. $result form) (. l form))");
    return _retval;
}

howl_sriq_RConcl howl_sriq_hyper_finish(slop_arena* arena, howl_sriq_HState st, slop_list_howl_types_Lit delta) {
    {
        __auto_type h = howl_sriq_appended(arena, st.head, ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        {
            __auto_type _coll = delta;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(h); __auto_type _item = (howl_sriq_apply_lit(st.sub, l)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ((howl_sriq_RConcl){.fires = st.fires, .body = st.body, .head = h});
    }
}

slop_list_howl_sriq_HState howl_sriq_extend_one(slop_arena* arena, howl_sriq_HState st, howl_types_Lit a, slop_list_howl_sriq_Premise ps) {
    slop_list_howl_sriq_HState _retval = {0};
    {
        __auto_type out = ((slop_list_howl_sriq_HState){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                {
                    __auto_type n = howl_sriq_hyper_step(arena, st, a, p);
                    if (n.fires) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
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

slop_list_howl_sriq_HState howl_sriq_extend_all(slop_arena* arena, slop_list_howl_sriq_HState sts, howl_types_Lit a, slop_list_howl_sriq_Premise ps) {
    {
        __auto_type out = ((slop_list_howl_sriq_HState){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = sts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type st = _coll.data[_i];
                {
                    __auto_type _coll = howl_sriq_extend_one(arena, st, a, ps);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type n = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_sriq_RConcl howl_sriq_hyper_join(slop_arena* arena, howl_sriq_HState start, slop_list_howl_types_Lit atoms, slop_list_howl_sriq_Cands cands, slop_list_howl_types_Lit delta) {
    {
        __auto_type sts = ((slop_list_howl_sriq_HState){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        __auto_type out = ((slop_list_howl_sriq_RConcl){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(sts); __auto_type _item = (start); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        {
            __auto_type _coll = atoms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_474 = ({ __auto_type _lst = cands; size_t _idx = (size_t)i; slop_option_howl_sriq_Cands _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_474.has_value) {
                    __auto_type c = _mv_474.value;
                    sts = howl_sriq_extend_all(arena, sts, a, c.ps);
                } else if (!_mv_474.has_value) {
                    sts = ((slop_list_howl_sriq_HState){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                }
                i = (i + 1);
            }
        }
        {
            __auto_type _coll = sts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type st = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriq_hyper_finish(arena, st, delta)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

uint32_t howl_sriq_other_arg(uint32_t k) {
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

howl_types_ATerm howl_sriq_arg_term(howl_types_Lit l, uint32_t k) {
    howl_types_ATerm _retval = {0};
    if (k == ((uint32_t)(1))) {
        _retval = l.t1;
        goto _slop_post;
    } else {
        _retval = l.t2;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((({ howl_types_ATerm _eq_l_475 = (_retval); howl_types_ATerm _eq_r_476 = (l.t1); slop_eq_howl_types_ATerm(&_eq_l_475, &_eq_r_476); }) || ({ howl_types_ATerm _eq_l_477 = (_retval); howl_types_ATerm _eq_r_478 = (l.t2); slop_eq_howl_types_ATerm(&_eq_l_477, &_eq_r_478); }))), "(or (== $result (. l t1)) (== $result (. l t2)))");
    return _retval;
}

uint8_t howl_sriq_has_arg(howl_types_Lit l, uint32_t k) {
    return ((k == ((uint32_t)(1))) || ((k == ((uint32_t)(2))) && !((l.form == howl_types_LitForm_lf_unary))));
}

slop_option_howl_types_ATerm howl_sriq_inner_of(howl_types_ATerm a) {
    __auto_type _mv_479 = a.kind;
    if (_mv_479 == howl_types_AKind_ak_fx) {
        return (slop_option_howl_types_ATerm){.has_value = 1, .value = howl_types_at_x()};
    } else if (_mv_479 == howl_types_AKind_ak_fu) {
        return (slop_option_howl_types_ATerm){.has_value = 1, .value = howl_types_at_u(a.cst)};
    } else if (_mv_479 == howl_types_AKind_ak_x) {
        return (slop_option_howl_types_ATerm){.has_value = false};
    } else if (_mv_479 == howl_types_AKind_ak_y) {
        return (slop_option_howl_types_ATerm){.has_value = false};
    } else if (_mv_479 == howl_types_AKind_ak_z) {
        return (slop_option_howl_types_ATerm){.has_value = false};
    } else if (_mv_479 == howl_types_AKind_ak_u) {
        return (slop_option_howl_types_ATerm){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

slop_option_howl_types_ATerm howl_sriq_subterm_at(howl_types_Lit l, howl_sriq_Pos p) {
    if (!(howl_sriq_has_arg(l, p.arg))) {
        return (slop_option_howl_types_ATerm){.has_value = false};
    } else if (p.inner) {
        return howl_sriq_inner_of(howl_sriq_arg_term(l, p.arg));
    } else {
        return (slop_option_howl_types_ATerm){.has_value = 1, .value = howl_sriq_arg_term(l, p.arg)};
    }
}

howl_types_ATerm howl_sriq_with_inner(howl_types_ATerm a, howl_types_ATerm t) {
    if (!(((a.kind == howl_types_AKind_ak_fx) || (a.kind == howl_types_AKind_ak_fu)))) {
        return a;
    } else if (t.kind == howl_types_AKind_ak_x) {
        return howl_types_at_fx(a.fsym);
    } else if (t.kind == howl_types_AKind_ak_u) {
        return howl_types_at_fu(a.fsym, t.cst);
    } else {
        return a;
    }
}

howl_types_Lit howl_sriq_with_arg(howl_types_Lit l, uint32_t k, howl_types_ATerm t) {
    howl_types_Lit _retval = {0};
    {
        __auto_type a = (((k == ((uint32_t)(1)))) ? t : l.t1);
        __auto_type b = (((k == ((uint32_t)(1)))) ? l.t2 : t);
        __auto_type _mv_480 = l.form;
        if (_mv_480 == howl_types_LitForm_lf_unary) {
            _retval = howl_types_atom1(l.pred, a);
            goto _slop_post;
        } else if (_mv_480 == howl_types_LitForm_lf_binary) {
            _retval = howl_types_atom2(l.pred, a, b);
            goto _slop_post;
        } else if (_mv_480 == howl_types_LitForm_lf_eq) {
            _retval = howl_types_eq_lit(a, b);
            goto _slop_post;
        } else if (_mv_480 == howl_types_LitForm_lf_neq) {
            _retval = howl_types_neq_lit(a, b);
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    }
    _slop_post: ;
    SLOP_POST(((_retval.form == l.form)), "(== (. $result form) (. l form))");
    return _retval;
}

howl_types_Lit howl_sriq_replace_at(howl_types_Lit l, howl_sriq_Pos p, howl_types_ATerm t) {
    howl_types_Lit _retval = {0};
    {
        __auto_type a = howl_sriq_arg_term(l, p.arg);
        _retval = howl_sriq_with_arg(l, p.arg, ((p.inner) ? howl_sriq_with_inner(a, t) : t));
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((_retval.form == l.form)), "(== (. $result form) (. l form))");
    return _retval;
}

howl_types_ATerm howl_sriq_replace_const(howl_types_ATerm a, howl_types_ATerm s, howl_types_ATerm t) {
    howl_types_ATerm _retval = {0};
    if (howl_types_aterm_eq(a, s)) {
        _retval = t;
        goto _slop_post;
    } else if ((a.kind == howl_types_AKind_ak_fu) && (a.cst == s.cst)) {
        _retval = howl_sriq_with_inner(a, t);
        goto _slop_post;
    } else {
        _retval = a;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

howl_types_Lit howl_sriq_replace_all(howl_types_Lit l, howl_sriq_Pos p, howl_types_ATerm s, howl_types_ATerm t) {
    howl_types_Lit _retval = {0};
    __auto_type _mv_481 = l.form;
    if (_mv_481 == howl_types_LitForm_lf_unary) {
        _retval = howl_types_atom1(l.pred, howl_sriq_replace_const(l.t1, s, t));
        goto _slop_post;
    } else if (_mv_481 == howl_types_LitForm_lf_binary) {
        _retval = howl_types_atom2(l.pred, howl_sriq_replace_const(l.t1, s, t), howl_sriq_replace_const(l.t2, s, t));
        goto _slop_post;
    } else if (_mv_481 == howl_types_LitForm_lf_eq) {
        _retval = howl_sriq_with_arg(l, p.arg, howl_sriq_replace_const(howl_sriq_arg_term(l, p.arg), s, t));
        goto _slop_post;
    } else if (_mv_481 == howl_types_LitForm_lf_neq) {
        _retval = howl_sriq_with_arg(l, p.arg, howl_sriq_replace_const(howl_sriq_arg_term(l, p.arg), s, t));
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST(((_retval.form == l.form)), "(== (. $result form) (. l form))");
    return _retval;
}

uint8_t howl_sriq_side_ok(howl_sriqorder_SriqOrder ord, howl_types_Lit l, uint32_t k) {
    return (((l.form == howl_types_LitForm_lf_unary)) || ((l.form == howl_types_LitForm_lf_binary)) || (!(howl_sriqorder_aterm_gt(ord, howl_sriq_arg_term(l, howl_sriq_other_arg(k)), howl_sriq_arg_term(l, k)))));
}

uint8_t howl_sriq_kinds_are(howl_types_ATerm a, howl_types_ATerm b, howl_types_AKind p, howl_types_AKind q) {
    return (((a.kind == p) && (b.kind == q)) || ((a.kind == q) && (b.kind == p)));
}

uint8_t howl_sriq_eq_usable(howl_types_ATerm s1, howl_types_ATerm t1) {
    return !((howl_sriq_kinds_are(s1, t1, howl_types_AKind_ak_x, howl_types_AKind_ak_y) || howl_sriq_kinds_are(s1, t1, howl_types_AKind_ak_y, howl_types_AKind_ak_u)));
}

uint8_t howl_sriq_plain(howl_types_ATerm a) {
    return !((((a.kind == howl_types_AKind_ak_fx)) || ((a.kind == howl_types_AKind_ak_fu)) || ((a.kind == howl_types_AKind_ak_y))));
}

uint8_t howl_sriq_s2_plain(howl_types_Lit l, howl_sriq_Pos p) {
    __auto_type _mv_482 = l.form;
    if (_mv_482 == howl_types_LitForm_lf_unary) {
        return howl_sriq_plain(l.t1);
    } else if (_mv_482 == howl_types_LitForm_lf_binary) {
        return (howl_sriq_plain(l.t1) && howl_sriq_plain(l.t2));
    } else if (_mv_482 == howl_types_LitForm_lf_eq) {
        return howl_sriq_plain(howl_sriq_arg_term(l, p.arg));
    } else if (_mv_482 == howl_types_LitForm_lf_neq) {
        return howl_sriq_plain(howl_sriq_arg_term(l, p.arg));
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriq_x_ok(howl_types_Lit l, howl_sriq_Pos p, howl_types_ATerm s1) {
    return (!((s1.kind == howl_types_AKind_ak_x)) || howl_sriq_s2_plain(l, p));
}

uint8_t howl_sriq_at_is(slop_option_howl_types_ATerm o, howl_types_ATerm s) {
    __auto_type _mv_483 = o;
    if (_mv_483.has_value) {
        __auto_type t = _mv_483.value;
        return howl_types_aterm_eq(t, s);
    } else if (!_mv_483.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

howl_sriq_RConcl howl_sriq_eq_rule(slop_arena* arena, howl_sriqorder_SriqOrder ord, uint8_t root, howl_sriq_Premise p1, uint32_t k1, howl_sriq_Premise p2, howl_sriq_Pos p) {
    SLOP_PRE(((((k1 == ((uint32_t)(1))) || (k1 == ((uint32_t)(2)))) && ((p.arg == ((uint32_t)(1))) || (p.arg == ((uint32_t)(2)))))), "(and (or (== k1 (cast U32 1)) (== k1 (cast U32 2))) (or (== (. p arg) (cast U32 1)) (== (. p arg) (cast U32 2))))");
    {
        __auto_type s1 = howl_sriq_arg_term(p1.sel, k1);
        __auto_type t1 = howl_sriq_arg_term(p1.sel, howl_sriq_other_arg(k1));
        __auto_type l2 = p2.sel;
        __auto_type lit = (((root && (s1.kind == howl_types_AKind_ak_u))) ? howl_sriq_replace_all(l2, p, s1, t1) : howl_sriq_replace_at(l2, p, t1));
        __auto_type h = howl_sriq_appended(arena, p1.rest, p2.rest);
        (void)(({ __auto_type _lst_p = &(h); __auto_type _item = (lit); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return ((howl_sriq_RConcl){.fires = ((p1.maxed) && ((p1.sel.form == howl_types_LitForm_lf_eq)) && (howl_sriq_side_ok(ord, p1.sel, k1)) && (howl_sriq_eq_usable(s1, t1)) && (p2.maxed) && (howl_sriq_side_ok(ord, l2, p.arg)) && (howl_sriq_at_is(howl_sriq_subterm_at(l2, p), s1)) && (howl_sriq_x_ok(l2, p, s1))), .body = howl_sriq_appended(arena, p1.body, p2.body), .head = h});
    }
}

howl_sriq_BodyView howl_sriq_body_at(slop_arena* arena, howl_types_Clause c, int64_t i) {
    SLOP_PRE((((i >= 0) && (i < ((int64_t)(((int64_t)((c.body).len))))))), "(and (>= i 0) (< i (cast Int (list-len (. c body)))))");
    return ((howl_sriq_BodyView){.lit = howl_sriq_lit_at(c.body, i), .rest = howl_sriq_without_at(arena, c.body, i), .head = c.head});
}

uint8_t howl_sriq_ground(howl_types_ATerm a) {
    return ((a.kind == howl_types_AKind_ak_u) || (a.kind == howl_types_AKind_ak_fu));
}

uint8_t howl_sriq_joinable(howl_types_Lit a) {
    __auto_type _mv_484 = a.form;
    if (_mv_484 == howl_types_LitForm_lf_unary) {
        return howl_sriq_ground(a.t1);
    } else if (_mv_484 == howl_types_LitForm_lf_binary) {
        return (howl_sriq_ground(a.t1) && howl_sriq_ground(a.t2));
    } else if (_mv_484 == howl_types_LitForm_lf_eq) {
        return (((a.t1.kind == howl_types_AKind_ak_u)) && ((a.t2.kind == howl_types_AKind_ak_u)) && (!(howl_types_aterm_eq(a.t1, a.t2))));
    } else if (_mv_484 == howl_types_LitForm_lf_neq) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

howl_sriq_RConcl howl_sriq_join_rule(slop_arena* arena, howl_sriq_Premise p1, howl_sriq_BodyView b) {
    return ((howl_sriq_RConcl){.fires = ((p1.maxed) && (howl_types_lit_eq(p1.sel, b.lit)) && (howl_sriq_joinable(b.lit))), .body = howl_sriq_appended(arena, p1.body, b.rest), .head = howl_sriq_appended(arena, p1.rest, b.head)});
}

uint8_t howl_sriq_kid_ok(howl_sriqorder_SriqOrder ord, uint32_t o, uint32_t sb2, uint32_t i, uint32_t k) {
    {
        __auto_type e = howl_sriqorder_const_entry(ord, k);
        return (((e.parent == o)) && ((e.srole == sb2)) && ((e.i == i)));
    }
}

uint8_t howl_sriq_kids_ok(howl_sriqorder_SriqOrder ord, uint32_t o, uint32_t sb2, uint32_t n, slop_list_u32 kids) {
    uint8_t _retval = {0};
    {
        uint32_t i = ((uint32_t)(1));
        uint8_t ok = (((int64_t)(((int64_t)((kids).len)))) == ((int64_t)(n)));
        {
            __auto_type _coll = kids;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                if (!(howl_sriq_kid_ok(ord, o, sb2, i, k))) {
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

slop_list_howl_types_Lit howl_sriq_nom_head(slop_arena* arena, slop_list_u32 kids) {
    slop_list_howl_types_Lit _retval = {0};
    {
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = kids;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_types_eq_lit(howl_types_at_x(), howl_types_at_u(k))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        _retval = out;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriq_nom_premises(howl_sriq_Premise p1, howl_sriq_Premise p2, uint32_t b1, uint32_t sb2) {
    {
        __auto_type a = p1.sel;
        __auto_type r = p2.sel;
        return (((a.form == howl_types_LitForm_lf_unary)) && ((a.pred == b1)) && ((a.t1.kind == howl_types_AKind_ak_u)) && ((r.form == howl_types_LitForm_lf_binary)) && ((r.pred == sb2)) && (howl_types_aterm_eq(r.t1, a.t1)) && ((r.t2.kind == howl_types_AKind_ak_x)));
    }
}

howl_sriq_RConcl howl_sriq_nom_rule(slop_arena* arena, howl_sriqorder_SriqOrder ord, int64_t lam, uint32_t b1, uint32_t sb2, uint32_t n, howl_sriq_Premise p1, howl_sriq_Premise p2, slop_list_u32 kids) {
    SLOP_PRE(((lam >= 0)), "(>= lam 0)");
    {
        __auto_type o = p1.sel.t1.cst;
        __auto_type h = howl_sriq_appended(arena, p1.rest, p2.rest);
        {
            __auto_type _coll = howl_sriq_nom_head(arena, kids);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(h); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ((howl_sriq_RConcl){.fires = ((p1.maxed) && (p2.maxed) && (howl_sriq_nom_premises(p1, p2, b1, sb2)) && ((((int64_t)(howl_sriqorder_const_entry(ord, o).len)) < lam)) && (howl_sriq_kids_ok(ord, o, sb2, n, kids))), .body = howl_sriq_appended(arena, p1.body, p2.body), .head = h});
    }
}

howl_types_ATerm howl_sriq_csub_term(howl_sriq_CSub s, howl_types_ATerm t) {
    howl_types_ATerm _retval = {0};
    __auto_type _mv_485 = t.kind;
    if (_mv_485 == howl_types_AKind_ak_x) {
        _retval = s.x;
        goto _slop_post;
    } else if (_mv_485 == howl_types_AKind_ak_y) {
        _retval = s.y;
        goto _slop_post;
    } else if (_mv_485 == howl_types_AKind_ak_z) {
        _retval = t;
        goto _slop_post;
    } else if (_mv_485 == howl_types_AKind_ak_fx) {
        _retval = t;
        goto _slop_post;
    } else if (_mv_485 == howl_types_AKind_ak_u) {
        _retval = t;
        goto _slop_post;
    } else if (_mv_485 == howl_types_AKind_ak_fu) {
        _retval = t;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

howl_types_Lit howl_sriq_csub_lit(howl_sriq_CSub s, howl_types_Lit l) {
    howl_types_Lit _retval = {0};
    {
        __auto_type a = howl_sriq_csub_term(s, l.t1);
        __auto_type b = howl_sriq_csub_term(s, l.t2);
        __auto_type _mv_486 = l.form;
        if (_mv_486 == howl_types_LitForm_lf_unary) {
            _retval = howl_types_atom1(l.pred, a);
            goto _slop_post;
        } else if (_mv_486 == howl_types_LitForm_lf_binary) {
            _retval = howl_types_atom2(l.pred, a, b);
            goto _slop_post;
        } else if (_mv_486 == howl_types_LitForm_lf_eq) {
            _retval = howl_types_eq_lit(a, b);
            goto _slop_post;
        } else if (_mv_486 == howl_types_LitForm_lf_neq) {
            _retval = howl_types_neq_lit(a, b);
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    }
    _slop_post: ;
    SLOP_POST(((_retval.form == l.form)), "(== (. $result form) (. l form))");
    return _retval;
}

howl_sriq_CSub howl_sriq_succ_csub(howl_sriq_SuccSig sg) {
    if (sg.root) {
        return ((howl_sriq_CSub){.x = howl_types_at_fu(sg.f, sg.u), .y = howl_types_at_u(sg.u)});
    } else {
        return ((howl_sriq_CSub){.x = howl_types_at_fx(sg.f), .y = howl_types_at_x()});
    }
}

uint8_t howl_sriq_is_succ_term(howl_sriq_SuccSig sg, howl_types_ATerm t) {
    if (sg.root) {
        return (((t.kind == howl_types_AKind_ak_fu)) && ((t.fsym == sg.f)) && ((t.cst == sg.u)));
    } else {
        return ((t.kind == howl_types_AKind_ak_fx) && (t.fsym == sg.f));
    }
}

uint8_t howl_sriq_is_atom(howl_types_Lit l) {
    return ((l.form == howl_types_LitForm_lf_unary) || (l.form == howl_types_LitForm_lf_binary));
}

uint8_t howl_sriq_succ_mentions(howl_sriq_SuccSig sg, howl_types_Lit l) {
    return (howl_sriq_is_atom(l) && (howl_sriq_is_succ_term(sg, l.t1) || ((l.form == howl_types_LitForm_lf_binary) && howl_sriq_is_succ_term(sg, l.t2))));
}

slop_option_howl_sriq_SuccSig howl_sriq_sig_of_term(uint8_t root, howl_types_ATerm t) {
    if (root && (t.kind == howl_types_AKind_ak_fu)) {
        return (slop_option_howl_sriq_SuccSig){.has_value = 1, .value = ((howl_sriq_SuccSig){.f = t.fsym, .root = 1, .u = t.cst})};
    } else if (!(root) && (t.kind == howl_types_AKind_ak_fx)) {
        return (slop_option_howl_sriq_SuccSig){.has_value = 1, .value = ((howl_sriq_SuccSig){.f = t.fsym, .root = 0, .u = ((uint32_t)(0))})};
    } else {
        return (slop_option_howl_sriq_SuccSig){.has_value = false};
    }
}

slop_option_howl_sriq_SuccSig howl_sriq_succ_sig(uint8_t root, howl_types_Lit l) {
    if (!(howl_sriq_is_atom(l))) {
        return (slop_option_howl_sriq_SuccSig){.has_value = false};
    } else if (l.form == howl_types_LitForm_lf_unary) {
        return howl_sriq_sig_of_term(root, l.t1);
    } else {
        __auto_type _mv_487 = howl_sriq_sig_of_term(root, l.t1);
        if (_mv_487.has_value) {
            __auto_type sg = _mv_487.value;
            return (slop_option_howl_sriq_SuccSig){.has_value = 1, .value = sg};
        } else if (!_mv_487.has_value) {
            return howl_sriq_sig_of_term(root, l.t2);
        }
        SLOP_UNREACHABLE();
    }
}

howl_sriq_PreLit howl_sriq_pre_none(howl_types_Lit l) {
    howl_sriq_PreLit _retval = {0};
    _retval = ((howl_sriq_PreLit){.ok = 0, .lit = l});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST((!(_retval.ok)), "(not (. $result ok))");
    return _retval;
}

howl_sriq_PreLit howl_sriq_pre_some(howl_types_Lit a) {
    howl_sriq_PreLit _retval = {0};
    _retval = ((howl_sriq_PreLit){.ok = 1, .lit = a});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.ok && ({ howl_types_Lit _eq_l_488 = (_retval.lit); howl_types_Lit _eq_r_489 = (a); slop_eq_howl_types_Lit(&_eq_l_488, &_eq_r_489); }))), "(and (. $result ok) (== (. $result lit) a))");
    return _retval;
}

howl_sriq_PreLit howl_sriq_pre_binary(howl_sriq_SuccSig sg, howl_types_Lit l) {
    howl_sriq_PreLit _retval = {0};
    {
        __auto_type yi = howl_sriq_succ_csub(sg).y;
        if (howl_sriq_is_succ_term(sg, l.t1) && howl_types_aterm_eq(l.t2, yi)) {
            _retval = howl_sriq_pre_some(howl_types_atom2(l.pred, howl_types_at_x(), howl_types_at_y()));
            goto _slop_post;
        } else if (howl_types_aterm_eq(l.t1, yi) && howl_sriq_is_succ_term(sg, l.t2)) {
            _retval = howl_sriq_pre_some(howl_types_atom2(l.pred, howl_types_at_y(), howl_types_at_x()));
            goto _slop_post;
        } else {
            _retval = howl_sriq_pre_none(l);
            goto _slop_post;
        }
    }
    _slop_post: ;
    return _retval;
}

howl_sriq_PreLit howl_sriq_succ_pre(howl_sriq_SuccSig sg, howl_types_Lit l) {
    howl_sriq_PreLit _retval = {0};
    if (!(howl_sriq_succ_mentions(sg, l))) {
        if ((howl_sriqctx_lit_ground(l)) && (!((l.form == howl_types_LitForm_lf_neq))) && (!(howl_sriq_has_fterm(l)))) {
            _retval = howl_sriq_pre_some(l);
            goto _slop_post;
        } else {
            _retval = howl_sriq_pre_none(l);
            goto _slop_post;
        }
    } else if (l.form == howl_types_LitForm_lf_unary) {
        _retval = howl_sriq_pre_some(howl_types_atom1(l.pred, howl_types_at_x()));
        goto _slop_post;
    } else {
        _retval = howl_sriq_pre_binary(sg, l);
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriq_has_fterm(howl_types_Lit l) {
    return ((l.t1.kind == howl_types_AKind_ak_fu) || (!((l.form == howl_types_LitForm_lf_unary)) && (l.t2.kind == howl_types_AKind_ak_fu)));
}

howl_sriq_PreLit howl_sriq_k_of_lit(howl_sriqctx_Triggers tr, howl_sriq_SuccSig sg, howl_types_Lit l) {
    {
        __auto_type a = howl_sriq_succ_pre(sg, l);
        if (a.ok && howl_sriqctx_in_su(tr, a.lit)) {
            return a;
        } else {
            return howl_sriq_pre_none(l);
        }
    }
}

howl_sriq_KSets howl_sriq_k_of_clause(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriqctx_Triggers tr, howl_sriq_SuccSig sg, howl_types_Clause c) {
    {
        __auto_type is_unit = ((((int64_t)((c.body).len)) == 0) && (((int64_t)((c.head).len)) == 1));
        __auto_type k1 = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type k2 = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = c.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                {
                    __auto_type a = howl_sriq_k_of_lit(tr, sg, l);
                    if (a.ok && howl_sriqorder_maximal_at(arena, ord, c.head, i)) {
                        (void)(({ __auto_type _lst_p = &(k2); __auto_type _item = (a.lit); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        if (is_unit && howl_sriqctx_mentions_x(a.lit)) {
                            (void)(({ __auto_type _lst_p = &(k1); __auto_type _item = (a.lit); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                    i = (i + 1);
                }
            }
        }
        return ((howl_sriq_KSets){.k1 = k1, .k2 = k2});
    }
}

howl_sriq_KSets howl_sriq_k_sets(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriqctx_Triggers tr, howl_sriq_SuccSig sg, slop_list_howl_types_Clause cs) {
    {
        __auto_type k1 = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type k2 = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type k = howl_sriq_k_of_clause(arena, ord, tr, sg, c);
                    {
                        __auto_type _coll = k.k1;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type a = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(k1); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                    {
                        __auto_type _coll = k.k2;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type a = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(k2); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        return ((howl_sriq_KSets){.k1 = howl_sriqclauses_lit_set(arena, k1), .k2 = howl_sriqclauses_lit_set(arena, k2)});
    }
}

uint8_t howl_sriq_within_one(slop_list_howl_types_Lit ls, howl_types_Lit a) {
    uint8_t _retval = {0};
    {
        uint8_t bad = 0;
        {
            __auto_type _coll = ls;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(howl_types_lit_eq(l, a))) {
                    bad = 1;
                }
            }
        }
        _retval = !(bad);
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriq_unit_held(howl_types_Lit a, slop_list_howl_types_Clause ws) {
    uint8_t _retval = {0};
    {
        uint8_t found = ((a.form == howl_types_LitForm_lf_eq) && howl_types_aterm_eq(a.t1, a.t2));
        {
            __auto_type _coll = ws;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type w = _coll.data[_i];
                if (howl_sriq_within_one(w.body, a) && howl_sriq_within_one(w.head, a)) {
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

uint8_t howl_sriq_covers(slop_list_howl_types_Lit k2, slop_list_howl_types_Lit core, slop_list_howl_types_Clause ws) {
    uint8_t _retval = {0};
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = k2;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (!((howl_sriq_holds_lit(core, a) || howl_sriq_unit_held(a, ws)))) {
                    ok = 0;
                }
            }
        }
        _retval = ok;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

howl_sriq_SuccConcl howl_sriq_succ_step(slop_arena* arena, howl_sriqctx_Strategy s, howl_sriqctx_Triggers tr, howl_sriq_SuccSig sg, howl_sriq_Premise p, howl_sriq_KSets ks, uint8_t covered) {
    {
        __auto_type cc = howl_sriqctx_strat_choice(s, tr, sg.f, ks.k1);
        __auto_type core = howl_sriqctx_core_of(arena, cc, ks.k1);
        __auto_type adds = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ks.k2;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (!(howl_sriq_holds_lit(core, a))) {
                    (void)(({ __auto_type _lst_p = &(adds); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return ((howl_sriq_SuccConcl){.fires = ((p.maxed) && (howl_sriq_succ_mentions(sg, p.sel)) && (!(covered))), .choice = cc, .adds = adds});
    }
}

howl_types_ATerm howl_sriq_x_to_y(howl_types_ATerm t) {
    if (t.kind == howl_types_AKind_ak_x) {
        return howl_types_at_y();
    } else {
        return t;
    }
}

howl_types_Lit howl_sriq_rsucc_lit(howl_types_Lit l) {
    howl_types_Lit _retval = {0};
    {
        __auto_type a = howl_sriq_x_to_y(l.t1);
        __auto_type b = howl_sriq_x_to_y(l.t2);
        __auto_type _mv_490 = l.form;
        if (_mv_490 == howl_types_LitForm_lf_unary) {
            _retval = howl_types_atom1(l.pred, a);
            goto _slop_post;
        } else if (_mv_490 == howl_types_LitForm_lf_binary) {
            _retval = howl_types_atom2(l.pred, a, b);
            goto _slop_post;
        } else if (_mv_490 == howl_types_LitForm_lf_eq) {
            _retval = howl_types_eq_lit(a, b);
            goto _slop_post;
        } else if (_mv_490 == howl_types_LitForm_lf_neq) {
            _retval = howl_types_neq_lit(a, b);
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    }
    _slop_post: ;
    SLOP_POST(((_retval.form == l.form)), "(== (. $result form) (. l form))");
    return _retval;
}

uint8_t howl_sriq_has_y(howl_types_Lit l) {
    return ((l.t1.kind == howl_types_AKind_ak_y) || (!((l.form == howl_types_LitForm_lf_unary)) && (l.t2.kind == howl_types_AKind_ak_y)));
}

uint8_t howl_sriq_has_const(howl_types_Lit l, uint32_t u) {
    return (((l.t1.kind == howl_types_AKind_ak_u) && (l.t1.cst == u)) || ((!((l.form == howl_types_LitForm_lf_unary))) && ((l.t2.kind == howl_types_AKind_ak_u)) && ((l.t2.cst == u))));
}

howl_sriq_RSuccConcl howl_sriq_rsucc_rule(howl_sriqctx_Triggers tr, uint8_t root, howl_sriq_Premise p, uint32_t u, uint8_t held) {
    return ((howl_sriq_RSuccConcl){.fires = ((!(root)) && (p.maxed) && (!(howl_sriq_has_y(p.sel))) && (howl_sriqctx_in_sur(tr, howl_sriq_rsucc_lit(p.sel))) && (howl_sriq_has_const(howl_sriq_rsucc_lit(p.sel), u)) && (!(held))), .lit = howl_sriq_rsucc_lit(p.sel)});
}

howl_sriq_PredView howl_sriq_pred_view(slop_arena* arena, howl_types_Clause c, slop_list_howl_types_Lit core, uint8_t to_root) {
    {
        __auto_type g = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type sl = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (howl_sriqctx_lit_ground(a)) {
                    (void)(({ __auto_type _lst_p = &(g); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                } else {
                    (void)(({ __auto_type _lst_p = &(sl); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        if (to_root) {
            {
                __auto_type _coll = core;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(sl); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return ((howl_sriq_PredView){.ground = g, .slots = sl, .head = c.head, .ok = 1});
    }
}

howl_sriq_PredView howl_sriq_rpred_view(slop_arena* arena, howl_sriqctx_Triggers tr, howl_types_Clause c) {
    {
        __auto_type g = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type sl = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t ok = 1;
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (howl_sriqctx_lit_ground(a)) {
                    (void)(({ __auto_type _lst_p = &(g); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    if (howl_sriq_has_fterm(a)) {
                        ok = 0;
                    }
                } else {
                    (void)(({ __auto_type _lst_p = &(sl); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    if (!(howl_sriqctx_in_sur(tr, a))) {
                        ok = 0;
                    }
                }
            }
        }
        return ((howl_sriq_PredView){.ground = g, .slots = sl, .head = c.head, .ok = ok});
    }
}

howl_sriq_PState howl_sriq_pred_start(slop_arena* arena, uint8_t edge) {
    howl_sriq_PState _retval = {0};
    _retval = ((howl_sriq_PState){.fires = edge, .body = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .head = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.fires == edge)), "(== (. $result fires) edge)");
    return _retval;
}

howl_sriq_PState howl_sriq_pred_step(slop_arena* arena, howl_sriq_PState st, howl_sriq_CSub s, howl_sriq_PSlot slot, howl_sriq_Premise p) {
    return ((howl_sriq_PState){.fires = ((st.fires) && (slot.edge) && (p.maxed) && (howl_types_lit_eq(p.sel, howl_sriq_csub_lit(s, slot.lit)))), .body = howl_sriq_appended(arena, st.body, p.body), .head = howl_sriq_appended(arena, st.head, p.rest)});
}

uint8_t howl_sriq_is_xu(howl_types_Lit l) {
    return ((l.form == howl_types_LitForm_lf_binary) && (((l.t1.kind == howl_types_AKind_ak_x) && (l.t2.kind == howl_types_AKind_ak_u)) || ((l.t1.kind == howl_types_AKind_ak_u) && (l.t2.kind == howl_types_AKind_ak_x))));
}

uint8_t howl_sriq_pred_head_ok(howl_sriqctx_Triggers tr, uint8_t to_root, howl_types_Lit l) {
    return ((howl_sriqctx_lit_ground(l)) || (howl_sriqctx_in_pr(tr, l)) || ((to_root && howl_sriq_is_xu(l))));
}

uint8_t howl_sriq_pred_heads_ok(howl_sriqctx_Triggers tr, uint8_t to_root, slop_list_howl_types_Lit ls) {
    uint8_t _retval = {0};
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = ls;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(howl_sriq_pred_head_ok(tr, to_root, l))) {
                    ok = 0;
                }
            }
        }
        _retval = ok;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

uint8_t howl_sriq_rpred_head_ok(howl_sriqctx_Triggers tr, howl_types_Lit l) {
    return (!(howl_sriq_has_fterm(l)) && (howl_sriqctx_lit_ground(l) || howl_sriqctx_in_prr(tr, l)));
}

uint8_t howl_sriq_rpred_heads_ok(howl_sriqctx_Triggers tr, slop_list_howl_types_Lit ls) {
    uint8_t _retval = {0};
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = ls;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(howl_sriq_rpred_head_ok(tr, l))) {
                    ok = 0;
                }
            }
        }
        _retval = ok;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

slop_list_howl_types_Lit howl_sriq_mapped(slop_arena* arena, howl_sriq_CSub s, slop_list_howl_types_Lit ls) {
    {
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ls;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriq_csub_lit(s, l)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_sriq_RConcl howl_sriq_pred_finish(slop_arena* arena, howl_sriq_PState st, howl_sriq_CSub s, howl_sriqctx_Triggers tr, uint8_t to_root, howl_sriq_PredView v) {
    return ((howl_sriq_RConcl){.fires = (st.fires && howl_sriq_pred_heads_ok(tr, to_root, v.head)), .body = howl_sriq_appended(arena, st.body, v.ground), .head = howl_sriq_appended(arena, st.head, howl_sriq_mapped(arena, s, v.head))});
}

howl_sriq_RConcl howl_sriq_rpred_finish(slop_arena* arena, howl_sriq_PState st, howl_sriqctx_Triggers tr, howl_sriq_PredView v) {
    return ((howl_sriq_RConcl){.fires = ((st.fires) && (v.ok) && (howl_sriq_rpred_heads_ok(tr, v.head))), .body = howl_sriq_appended(arena, st.body, v.ground), .head = howl_sriq_appended(arena, st.head, howl_sriq_mapped(arena, ((howl_sriq_CSub){.x = howl_types_at_x(), .y = howl_types_at_x()}), v.head))});
}

slop_list_howl_sriq_PState howl_sriq_pred_extend_one(slop_arena* arena, howl_sriq_PState st, howl_sriq_CSub s, howl_sriq_PSlot slot, slop_list_howl_sriq_Premise ps) {
    slop_list_howl_sriq_PState _retval = {0};
    {
        __auto_type out = ((slop_list_howl_sriq_PState){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                {
                    __auto_type n = howl_sriq_pred_step(arena, st, s, slot, p);
                    if (n.fires) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
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

slop_list_howl_sriq_PState howl_sriq_pred_join(slop_arena* arena, howl_sriq_PState start, howl_sriq_CSub s, slop_list_howl_sriq_PCands cs) {
    {
        __auto_type sts = ((slop_list_howl_sriq_PState){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (start.fires) {
            (void)(({ __auto_type _lst_p = &(sts); __auto_type _item = (start); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type next = ((slop_list_howl_sriq_PState){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    {
                        __auto_type _coll = sts;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type st = _coll.data[_i];
                            {
                                __auto_type _coll = howl_sriq_pred_extend_one(arena, st, s, c.slot, c.ps);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type n = _coll.data[_i];
                                    (void)(({ __auto_type _lst_p = &(next); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                }
                            }
                        }
                    }
                    sts = next;
                }
            }
        }
        return sts;
    }
}

int64_t howl_sriq_depth_limit(int64_t tsu, int64_t tpr, int64_t omega, int64_t omega_d) {
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

int64_t howl_sriq_stored_lambda(int64_t tsu, int64_t tpr, int64_t omega, int64_t omega_d) {
    SLOP_PRE(((((tsu >= 0)) && ((tsu <= 2147483648)) && ((tpr >= 0)) && ((tpr <= 2147483648)) && ((omega >= 0)) && ((omega <= 4611686018427387904)) && ((omega_d >= 1)) && ((omega_d <= 2147483648)))), "(and (>= tsu 0) (<= tsu 2147483648) (>= tpr 0) (<= tpr 2147483648) (>= omega 0) (<= omega 4611686018427387904) (>= omega-d 1) (<= omega-d 2147483648))");
    int64_t _retval = {0};
    {
        __auto_type d = howl_sriq_depth_limit(tsu, tpr, omega, omega_d);
        if (d >= 10001) {
            _retval = d;
            goto _slop_post;
        } else {
            _retval = 10001;
            goto _slop_post;
        }
    }
    _slop_post: ;
    SLOP_POST(((_retval >= 10001)), "(>= $result 10001)");
    return _retval;
}

uint8_t howl_sriq_lits_same(slop_list_howl_types_Lit a, slop_list_howl_types_Lit b) {
    {
        uint8_t ok = (((int64_t)((a).len)) == ((int64_t)((b).len)));
        int64_t i = 0;
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(howl_types_lit_eq(l, howl_sriq_lit_at(b, i)))) {
                    ok = 0;
                }
                i = (i + 1);
            }
        }
        return ok;
    }
}

uint8_t howl_sriq_rconcl_eq(howl_sriq_RConcl a, howl_sriq_RConcl b) {
    if (a.fires == b.fires) {
        if (howl_sriq_lits_same(a.body, b.body)) {
            return howl_sriq_lits_same(a.head, b.head);
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

uint8_t howl_sriq_fires_is(howl_sriq_RConcl a, howl_sriq_RConcl b) {
    return (a.fires == b.fires);
}

uint8_t howl_sriq_hstate_eq(howl_sriq_HState a, howl_sriq_HState b) {
    if (a.fires == b.fires) {
        if (howl_sriq_lits_same(a.body, b.body)) {
            return howl_sriq_lits_same(a.head, b.head);
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

howl_types_ATerm howl_sriq_ex_fx(int64_t f) {
    return howl_types_at_fx(((uint32_t)(f)));
}

howl_types_ATerm howl_sriq_ex_u(int64_t u) {
    return howl_types_at_u(((uint32_t)(u)));
}

howl_types_Lit howl_sriq_ex_a1(int64_t b, howl_types_ATerm t) {
    return howl_types_atom1(((uint32_t)(b)), t);
}

howl_types_Lit howl_sriq_ex_a2(int64_t r, howl_types_ATerm a, howl_types_ATerm b) {
    return howl_types_atom2(((uint32_t)(r)), a, b);
}

howl_sriq_Pos howl_sriq_ex_pos(int64_t k, uint8_t inner) {
    return ((howl_sriq_Pos){.arg = ((uint32_t)(k)), .inner = inner});
}

uint32_t howl_sriq_ex_side(howl_types_Lit l, howl_types_ATerm s) {
    if (howl_types_aterm_eq(l.t1, s)) {
        return ((uint32_t)(1));
    } else {
        return ((uint32_t)(2));
    }
}

slop_list_howl_types_Lit howl_sriq_ex_l0(slop_arena* arena) {
    return ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
}

slop_list_howl_types_Lit howl_sriq_ex_l1(slop_arena* arena, howl_types_Lit a) {
    {
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

slop_list_howl_types_Lit howl_sriq_ex_l2(slop_arena* arena, howl_types_Lit a, howl_types_Lit b) {
    {
        __auto_type out = howl_sriq_ex_l1(arena, a);
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

slop_list_howl_types_Lit howl_sriq_ex_l3(slop_arena* arena, howl_types_Lit a, howl_types_Lit b, howl_types_Lit c) {
    {
        __auto_type out = howl_sriq_ex_l2(arena, a, b);
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

howl_sriqorder_SriqOrder howl_sriq_ex_ord(slop_arena* arena) {
    return howl_sriqorder_named_consts(arena, 3);
}

howl_sriq_Premise howl_sriq_ex_sel(slop_arena* arena, slop_list_howl_types_Lit head, howl_types_Lit l) {
    {
        __auto_type c = howl_sriqclauses_make_clause(arena, ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), head);
        int64_t at = 0;
        int64_t i = 0;
        {
            __auto_type _coll = c.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type h = _coll.data[_i];
                if (howl_types_lit_eq(h, l)) {
                    at = i;
                }
                i = (i + 1);
            }
        }
        return howl_sriq_select(arena, howl_sriq_ex_ord(arena), c, at);
    }
}

howl_sriq_Premise howl_sriq_ex_fac(slop_arena* arena) {
    return howl_sriq_ex_sel(arena, howl_sriq_ex_l2(arena, howl_types_eq_lit(howl_sriq_ex_fx(1), howl_types_at_y()), howl_types_eq_lit(howl_sriq_ex_fx(1), howl_sriq_ex_fx(0))), howl_types_eq_lit(howl_sriq_ex_fx(1), howl_sriq_ex_fx(0)));
}

howl_sriq_BodyView howl_sriq_ex_body(slop_arena* arena, slop_list_howl_types_Lit body, slop_list_howl_types_Lit head, howl_types_Lit l) {
    {
        __auto_type c = howl_sriqclauses_make_clause(arena, body, head);
        int64_t at = 0;
        int64_t i = 0;
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                if (howl_types_lit_eq(b, l)) {
                    at = i;
                }
                i = (i + 1);
            }
        }
        return howl_sriq_body_at(arena, c, at);
    }
}

howl_sriq_RConcl howl_sriq_ex_rc(slop_arena* arena, uint8_t fires, slop_list_howl_types_Lit body, slop_list_howl_types_Lit head) {
    return ((howl_sriq_RConcl){.fires = fires, .body = body, .head = head});
}

howl_sriq_HState howl_sriq_ex_hs(slop_arena* arena, uint8_t fires, slop_list_howl_types_Lit body, slop_list_howl_types_Lit head) {
    return ((howl_sriq_HState){.fires = fires, .sub = howl_sriq_hyper_start(arena, howl_types_at_x(), 1).sub, .body = body, .head = head});
}

howl_sriqorder_SriqOrder howl_sriq_ex_kids_ord(slop_arena* arena) {
    {
        __auto_type base = howl_sriqorder_named_consts(arena, 2);
        __auto_type cs = ((slop_list_howl_sriqorder_ConstEntry){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = base.consts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(cs); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        (void)(({ __auto_type _lst_p = &(cs); __auto_type _item = (howl_sriqorder_aux_const(howl_sriqorder_const_entry(base, ((uint32_t)(0))), ((uint32_t)(0)), ((uint32_t)(2)), ((uint32_t)(1)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return ((howl_sriqorder_SriqOrder){.consts = cs, .rank = -1});
    }
}

slop_list_u32 howl_sriq_ex_ids(slop_arena* arena, int64_t k) {
    {
        __auto_type out = ((slop_list_u32){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((uint32_t)(k))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

