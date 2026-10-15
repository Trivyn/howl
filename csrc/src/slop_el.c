#include "../runtime/slop_runtime.h"
#include "slop_el.h"

howl_types_Node howl_el_ex_x(void);
howl_types_Node howl_el_ex_a(void);
howl_types_Node howl_el_ex_b(void);
howl_types_Node howl_el_ex_c(void);
howl_types_RoleId howl_el_ex_r(void);
howl_types_Context howl_el_ex_ctx(slop_arena* arena);
howl_types_Context howl_el_ex_ctx_bottom(slop_arena* arena);
slop_list_howl_types_Addressed howl_el_cr_sub_name_on_sub(slop_arena* arena, howl_types_Context ctx, howl_types_Node b, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_cr_and_on_sub(slop_arena* arena, howl_types_Context ctx, howl_types_Node b, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_cr_some_rhs_on_sub(slop_arena* arena, howl_types_Context ctx, howl_types_Node b, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_cr_exists_lhs_on_sub(slop_arena* arena, howl_types_Context ctx, howl_types_Node b, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_cr_exists_lhs_on_pred(slop_arena* arena, howl_types_Context ctx, howl_types_RoleId r, howl_types_Node x, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_cr_bottom_on_sub(slop_arena* arena, howl_types_Context ctx, howl_types_Node b);
slop_list_howl_types_Addressed howl_el_cr_bottom_on_pred(slop_arena* arena, howl_types_Context ctx, howl_types_Node x);
slop_list_howl_types_Addressed howl_el_cr_chain_on_pred(slop_arena* arena, howl_types_Context ctx, howl_types_RoleId r, howl_types_Node x, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_cr_chain_on_succ(slop_arena* arena, howl_types_Context ctx, howl_types_RoleId s, howl_types_Node z, howl_types_NormAxiom ax);
slop_list_howl_types_RoleId howl_el_sups_of(slop_arena* arena, howl_premise_RoleClosure rc, howl_types_RoleId e);
slop_list_howl_types_Addressed howl_el_cr4_on_sub_through(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_Node b, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_cr7_on_pred_through(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_RoleId r, howl_types_Node x, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_cr7_on_succ_through(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_RoleId s, howl_types_Node z, howl_types_NormAxiom ax);
howl_premise_RoleClosure howl_el_role_closure_naive(slop_arena* arena, slop_list_howl_types_NormAxiom axioms);
uint8_t howl_el_in_sups(howl_premise_RoleClosure rc, howl_types_RoleId e, howl_types_RoleId r);
slop_list_howl_types_Addressed howl_el_ref_cr4_on_sub(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_Node b, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_ref_cr7_on_pred(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_RoleId r, howl_types_Node x, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_ref_cr7_on_succ(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_RoleId s, howl_types_Node z, howl_types_NormAxiom ax);
slop_list_howl_types_Addressed howl_el_apply_el_rules(slop_arena* arena, howl_types_Context ctx, howl_types_Derived incoming, howl_premise_RuleIndex idx);
slop_list_howl_types_Addressed howl_el_apply_el_rules_reference(slop_arena* arena, howl_types_Context ctx, howl_types_Derived incoming, slop_list_howl_types_NormAxiom axioms);

howl_types_Node howl_el_ex_x(void) {
    return ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = ((slop_rdf_rdf_IRI){.value = SLOP_STR("http://example.org/X")}) });
}

howl_types_Node howl_el_ex_a(void) {
    return ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = ((slop_rdf_rdf_IRI){.value = SLOP_STR("http://example.org/A")}) });
}

howl_types_Node howl_el_ex_b(void) {
    return ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = ((slop_rdf_rdf_IRI){.value = SLOP_STR("http://example.org/B")}) });
}

howl_types_Node howl_el_ex_c(void) {
    return ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = ((slop_rdf_rdf_IRI){.value = SLOP_STR("http://example.org/C")}) });
}

howl_types_RoleId howl_el_ex_r(void) {
    return ((howl_types_RoleId){ .tag = howl_types_RoleId_named_role, .data.named_role = ((slop_rdf_rdf_IRI){.value = SLOP_STR("http://example.org/r")}) });
}

howl_types_Context howl_el_ex_ctx(slop_arena* arena) {
    {
        __auto_type ctx = howl_types_make_context(arena, howl_el_ex_x());
        __auto_type b = howl_el_ex_b();
        __auto_type c = howl_el_ex_c();
        (void)(({ slop_map_put(NULL, ctx.subsumers, &(b), NULL, 0); }));
        (void)(({ slop_map_put(NULL, ctx.subsumers, &(c), NULL, 0); }));
        return ctx;
    }
}

howl_types_Context howl_el_ex_ctx_bottom(slop_arena* arena) {
    {
        __auto_type ctx = howl_types_make_context(arena, howl_el_ex_x());
        __auto_type bot = howl_types_node_bottom();
        (void)(({ slop_map_put(NULL, ctx.subsumers, &(bot), NULL, 0); }));
        return ctx;
    }
}

slop_list_howl_types_Addressed howl_el_cr_sub_name_on_sub(slop_arena* arena, howl_types_Context ctx, howl_types_Node b, howl_types_NormAxiom ax) {
    slop_list_howl_types_Addressed _retval = {0};
    {
        __auto_type result = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_597 = ax;
        switch (_mv_597.tag) {
            case howl_types_NormAxiom_sub_name:
            {
                __auto_type b2 = _mv_597.data.sub_name.f0;
                __auto_type a = _mv_597.data.sub_name.f1;
                if (howl_types_node_eq(b, b2)) {
                    ({ __auto_type _lst_p = &(result); __auto_type _item = (((howl_types_Addressed){.to = ctx.root, .what = ((howl_types_Derived){ .tag = howl_types_Derived_derived_sub, .data.derived_sub = a })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                break;
            }
            case howl_types_NormAxiom_sub_and:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_role:
            {
                break;
            }
            case howl_types_NormAxiom_role_chain:
            {
                break;
            }
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) <= 1)), "(<= (list-len $result) 1)");
    return _retval;
}

slop_list_howl_types_Addressed howl_el_cr_and_on_sub(slop_arena* arena, howl_types_Context ctx, howl_types_Node b, howl_types_NormAxiom ax) {
    slop_list_howl_types_Addressed _retval = {0};
    {
        __auto_type result = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_598 = ax;
        switch (_mv_598.tag) {
            case howl_types_NormAxiom_sub_and:
            {
                __auto_type a1 = _mv_598.data.sub_and.f0;
                __auto_type a2 = _mv_598.data.sub_and.f1;
                __auto_type a = _mv_598.data.sub_and.f2;
                {
                    uint8_t fire = 0;
                    if (howl_types_node_eq(b, a1)) {
                        if (slop_map_has(ctx.subsumers, &(a2))) {
                            fire = 1;
                        }
                    } else {
                        if (howl_types_node_eq(b, a2)) {
                            if (slop_map_has(ctx.subsumers, &(a1))) {
                                fire = 1;
                            }
                        }
                    }
                    if (fire) {
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (((howl_types_Addressed){.to = ctx.root, .what = ((howl_types_Derived){ .tag = howl_types_Derived_derived_sub, .data.derived_sub = a })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case howl_types_NormAxiom_sub_name:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_role:
            {
                break;
            }
            case howl_types_NormAxiom_role_chain:
            {
                break;
            }
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) <= 1)), "(<= (list-len $result) 1)");
    return _retval;
}

slop_list_howl_types_Addressed howl_el_cr_some_rhs_on_sub(slop_arena* arena, howl_types_Context ctx, howl_types_Node b, howl_types_NormAxiom ax) {
    slop_list_howl_types_Addressed _retval = {0};
    {
        __auto_type result = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_601 = ax;
        switch (_mv_601.tag) {
            case howl_types_NormAxiom_sub_some_rhs:
            {
                __auto_type b2 = _mv_601.data.sub_some_rhs.f0;
                __auto_type r = _mv_601.data.sub_some_rhs.f1;
                __auto_type a = _mv_601.data.sub_some_rhs.f2;
                if (howl_types_node_eq(b, b2)) {
                    {
                        __auto_type pair = howl_types_emit_edge(arena, ((howl_types_LogicalEdge){.from = ctx.root, .role = r, .to = a}));
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.succ_half); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.pred_half); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case howl_types_NormAxiom_sub_name:
            {
                break;
            }
            case howl_types_NormAxiom_sub_and:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_role:
            {
                break;
            }
            case howl_types_NormAxiom_role_chain:
            {
                break;
            }
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) <= 2)), "(<= (list-len $result) 2)");
    return _retval;
}

slop_list_howl_types_Addressed howl_el_cr_exists_lhs_on_sub(slop_arena* arena, howl_types_Context ctx, howl_types_Node b, howl_types_NormAxiom ax) {
    {
        __auto_type result = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_602 = ax;
        switch (_mv_602.tag) {
            case howl_types_NormAxiom_sub_some_lhs:
            {
                __auto_type r = _mv_602.data.sub_some_lhs.f0;
                __auto_type b2 = _mv_602.data.sub_some_lhs.f1;
                __auto_type a = _mv_602.data.sub_some_lhs.f2;
                if (howl_types_node_eq(b, b2)) {
                    __auto_type _mv_604 = ({ void* _ptr = slop_map_get(ctx.preds, &(r)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
                    if (_mv_604.has_value) {
                        __auto_type xs = _mv_604.value;
                        {
                            slop_map* _coll = (slop_map*)xs;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    howl_types_Node x = *(howl_types_Node*)slop_map_key_at(_coll, _i);
                                    ({ __auto_type _lst_p = &(result); __auto_type _item = (((howl_types_Addressed){.to = x, .what = ((howl_types_Derived){ .tag = howl_types_Derived_derived_sub, .data.derived_sub = a })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    } else if (!_mv_604.has_value) {
                    }
                }
                break;
            }
            case howl_types_NormAxiom_sub_name:
            {
                break;
            }
            case howl_types_NormAxiom_sub_and:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_role:
            {
                break;
            }
            case howl_types_NormAxiom_role_chain:
            {
                break;
            }
        }
        return result;
    }
}

slop_list_howl_types_Addressed howl_el_cr_exists_lhs_on_pred(slop_arena* arena, howl_types_Context ctx, howl_types_RoleId r, howl_types_Node x, howl_types_NormAxiom ax) {
    slop_list_howl_types_Addressed _retval = {0};
    {
        __auto_type result = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_605 = ax;
        switch (_mv_605.tag) {
            case howl_types_NormAxiom_sub_some_lhs:
            {
                __auto_type r2 = _mv_605.data.sub_some_lhs.f0;
                __auto_type b = _mv_605.data.sub_some_lhs.f1;
                __auto_type a = _mv_605.data.sub_some_lhs.f2;
                if (howl_types_role_eq(r, r2)) {
                    if (slop_map_has(ctx.subsumers, &(b))) {
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (((howl_types_Addressed){.to = x, .what = ((howl_types_Derived){ .tag = howl_types_Derived_derived_sub, .data.derived_sub = a })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case howl_types_NormAxiom_sub_name:
            {
                break;
            }
            case howl_types_NormAxiom_sub_and:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_role:
            {
                break;
            }
            case howl_types_NormAxiom_role_chain:
            {
                break;
            }
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) <= 1)), "(<= (list-len $result) 1)");
    return _retval;
}

slop_list_howl_types_Addressed howl_el_cr_bottom_on_sub(slop_arena* arena, howl_types_Context ctx, howl_types_Node b) {
    {
        __auto_type result = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type bottom = howl_types_node_bottom();
        if (howl_types_node_eq(b, bottom)) {
            {
                slop_map* _coll = (slop_map*)ctx.preds;
                for (size_t _i = 0; _i < _coll->len; _i++) {
                    {
                        howl_types_RoleId r = *(howl_types_RoleId*)slop_map_key_at(_coll, _i);
                        slop_map* xs = *(slop_map**)slop_map_value_at(_coll, _i);
                        {
                            slop_map* _coll = (slop_map*)xs;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    howl_types_Node x = *(howl_types_Node*)slop_map_key_at(_coll, _i);
                                    (void)(({ __auto_type _lst_p = &(result); __auto_type _item = (((howl_types_Addressed){.to = x, .what = ((howl_types_Derived){ .tag = howl_types_Derived_derived_sub, .data.derived_sub = bottom })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                }
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
}

slop_list_howl_types_Addressed howl_el_cr_bottom_on_pred(slop_arena* arena, howl_types_Context ctx, howl_types_Node x) {
    slop_list_howl_types_Addressed _retval = {0};
    {
        __auto_type result = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type bottom = howl_types_node_bottom();
        if (slop_map_has(ctx.subsumers, &(bottom))) {
            (void)(({ __auto_type _lst_p = &(result); __auto_type _item = (((howl_types_Addressed){.to = x, .what = ((howl_types_Derived){ .tag = howl_types_Derived_derived_sub, .data.derived_sub = bottom })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) <= 1)), "(<= (list-len $result) 1)");
    return _retval;
}

slop_list_howl_types_Addressed howl_el_cr_chain_on_pred(slop_arena* arena, howl_types_Context ctx, howl_types_RoleId r, howl_types_Node x, howl_types_NormAxiom ax) {
    {
        __auto_type result = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_608 = ax;
        switch (_mv_608.tag) {
            case howl_types_NormAxiom_role_chain:
            {
                __auto_type r2 = _mv_608.data.role_chain.f0;
                __auto_type s = _mv_608.data.role_chain.f1;
                __auto_type t = _mv_608.data.role_chain.f2;
                if (howl_types_role_eq(r, r2)) {
                    __auto_type _mv_610 = ({ void* _ptr = slop_map_get(ctx.succs, &(s)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
                    if (_mv_610.has_value) {
                        __auto_type zs = _mv_610.value;
                        {
                            slop_map* _coll = (slop_map*)zs;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    howl_types_Node z = *(howl_types_Node*)slop_map_key_at(_coll, _i);
                                    {
                                        __auto_type pair = howl_types_emit_edge(arena, ((howl_types_LogicalEdge){.from = x, .role = t, .to = z}));
                                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.succ_half); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.pred_half); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    } else if (!_mv_610.has_value) {
                    }
                }
                break;
            }
            case howl_types_NormAxiom_sub_name:
            {
                break;
            }
            case howl_types_NormAxiom_sub_and:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_role:
            {
                break;
            }
        }
        return result;
    }
}

slop_list_howl_types_Addressed howl_el_cr_chain_on_succ(slop_arena* arena, howl_types_Context ctx, howl_types_RoleId s, howl_types_Node z, howl_types_NormAxiom ax) {
    {
        __auto_type result = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_611 = ax;
        switch (_mv_611.tag) {
            case howl_types_NormAxiom_role_chain:
            {
                __auto_type r = _mv_611.data.role_chain.f0;
                __auto_type s2 = _mv_611.data.role_chain.f1;
                __auto_type t = _mv_611.data.role_chain.f2;
                if (howl_types_role_eq(s, s2)) {
                    __auto_type _mv_613 = ({ void* _ptr = slop_map_get(ctx.preds, &(r)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
                    if (_mv_613.has_value) {
                        __auto_type xs = _mv_613.value;
                        {
                            slop_map* _coll = (slop_map*)xs;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    howl_types_Node x = *(howl_types_Node*)slop_map_key_at(_coll, _i);
                                    {
                                        __auto_type pair = howl_types_emit_edge(arena, ((howl_types_LogicalEdge){.from = x, .role = t, .to = z}));
                                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.succ_half); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.pred_half); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    } else if (!_mv_613.has_value) {
                    }
                }
                break;
            }
            case howl_types_NormAxiom_sub_name:
            {
                break;
            }
            case howl_types_NormAxiom_sub_and:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_role:
            {
                break;
            }
        }
        return result;
    }
}

slop_list_howl_types_RoleId howl_el_sups_of(slop_arena* arena, howl_premise_RoleClosure rc, howl_types_RoleId e) {
    __auto_type _mv_615 = ({ void* _ptr = slop_map_get(rc.sups, &(e)); _ptr ? (slop_option_howl_premise_RoleList){ .has_value = true, .value = *(howl_premise_RoleList*)_ptr } : (slop_option_howl_premise_RoleList){ .has_value = false }; });
    if (_mv_615.has_value) {
        __auto_type l = _mv_615.value;
        return l.items;
    } else if (!_mv_615.has_value) {
        {
            __auto_type one = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            ({ __auto_type _lst_p = &(one); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            return one;
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Addressed howl_el_cr4_on_sub_through(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_Node b, howl_types_NormAxiom ax) {
    {
        __auto_type out = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_616 = ax;
        switch (_mv_616.tag) {
            case howl_types_NormAxiom_sub_some_lhs:
            {
                __auto_type r = _mv_616.data.sub_some_lhs.f0;
                __auto_type b2 = _mv_616.data.sub_some_lhs.f1;
                __auto_type a = _mv_616.data.sub_some_lhs.f2;
                __auto_type _mv_618 = ({ void* _ptr = slop_map_get(rc.subs, &(r)); _ptr ? (slop_option_howl_premise_RoleList){ .has_value = true, .value = *(howl_premise_RoleList*)_ptr } : (slop_option_howl_premise_RoleList){ .has_value = false }; });
                if (_mv_618.has_value) {
                    __auto_type es = _mv_618.value;
                    {
                        __auto_type _coll = es.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type e = _coll.data[_i];
                            {
                                __auto_type via = ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = e, .f1 = b2, .f2 = a } });
                                {
                                    __auto_type _coll = howl_el_cr_exists_lhs_on_sub(arena, ctx, b, via);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_618.has_value) {
                    {
                        __auto_type _coll = howl_el_cr_exists_lhs_on_sub(arena, ctx, b, ax);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type m = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case howl_types_NormAxiom_sub_name:
            {
                break;
            }
            case howl_types_NormAxiom_sub_and:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_role:
            {
                break;
            }
            case howl_types_NormAxiom_role_chain:
            {
                break;
            }
        }
        return out;
    }
}

slop_list_howl_types_Addressed howl_el_cr7_on_pred_through(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_RoleId r, howl_types_Node x, howl_types_NormAxiom ax) {
    {
        __auto_type out = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_619 = ax;
        switch (_mv_619.tag) {
            case howl_types_NormAxiom_role_chain:
            {
                __auto_type r2 = _mv_619.data.role_chain.f0;
                __auto_type s2 = _mv_619.data.role_chain.f1;
                __auto_type t = _mv_619.data.role_chain.f2;
                __auto_type _mv_621 = ({ void* _ptr = slop_map_get(rc.subs, &(s2)); _ptr ? (slop_option_howl_premise_RoleList){ .has_value = true, .value = *(howl_premise_RoleList*)_ptr } : (slop_option_howl_premise_RoleList){ .has_value = false }; });
                if (_mv_621.has_value) {
                    __auto_type es = _mv_621.value;
                    {
                        __auto_type _coll = es.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type e = _coll.data[_i];
                            {
                                __auto_type via = ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_role_chain, .data.role_chain = { .f0 = r2, .f1 = e, .f2 = t } });
                                {
                                    __auto_type _coll = howl_el_cr_chain_on_pred(arena, ctx, r, x, via);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_621.has_value) {
                    {
                        __auto_type _coll = howl_el_cr_chain_on_pred(arena, ctx, r, x, ax);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type m = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case howl_types_NormAxiom_sub_name:
            {
                break;
            }
            case howl_types_NormAxiom_sub_and:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_role:
            {
                break;
            }
        }
        return out;
    }
}

slop_list_howl_types_Addressed howl_el_cr7_on_succ_through(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_RoleId s, howl_types_Node z, howl_types_NormAxiom ax) {
    {
        __auto_type out = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_622 = ax;
        switch (_mv_622.tag) {
            case howl_types_NormAxiom_role_chain:
            {
                __auto_type r2 = _mv_622.data.role_chain.f0;
                __auto_type s2 = _mv_622.data.role_chain.f1;
                __auto_type t = _mv_622.data.role_chain.f2;
                __auto_type _mv_624 = ({ void* _ptr = slop_map_get(rc.subs, &(r2)); _ptr ? (slop_option_howl_premise_RoleList){ .has_value = true, .value = *(howl_premise_RoleList*)_ptr } : (slop_option_howl_premise_RoleList){ .has_value = false }; });
                if (_mv_624.has_value) {
                    __auto_type es = _mv_624.value;
                    {
                        __auto_type _coll = es.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type e = _coll.data[_i];
                            {
                                __auto_type via = ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_role_chain, .data.role_chain = { .f0 = e, .f1 = s2, .f2 = t } });
                                {
                                    __auto_type _coll = howl_el_cr_chain_on_succ(arena, ctx, s, z, via);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_624.has_value) {
                    {
                        __auto_type _coll = howl_el_cr_chain_on_succ(arena, ctx, s, z, ax);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type m = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case howl_types_NormAxiom_sub_name:
            {
                break;
            }
            case howl_types_NormAxiom_sub_and:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_role:
            {
                break;
            }
        }
        return out;
    }
}

howl_premise_RoleClosure howl_el_role_closure_naive(slop_arena* arena, slop_list_howl_types_NormAxiom axioms) {
    {
        __auto_type rc = ((howl_premise_RoleClosure){.sups = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_RoleId, slop_hash_howl_types_RoleId, slop_eq_howl_types_RoleId, SLOP_KEY_HASHED, howl_premise_RoleList); slop_map_new_ptr(arena, 0, &_d); }), .subs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_RoleId, slop_hash_howl_types_RoleId, slop_eq_howl_types_RoleId, SLOP_KEY_HASHED, howl_premise_RoleList); slop_map_new_ptr(arena, 0, &_d); })});
        __auto_type roles = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(howl_types_RoleId, slop_hash_howl_types_RoleId, slop_eq_howl_types_RoleId, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                {
                    __auto_type _coll = howl_premise_axiom_roles(arena, ax);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        if (!(slop_map_has(seen, &(r)))) {
                            (void)(({ slop_map_put(NULL, seen, &(r), NULL, 0); }));
                            (void)(({ __auto_type _lst_p = &(roles); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        {
            __auto_type _coll = roles;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                {
                    __auto_type up = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    __auto_type have = ({ static const slop_map_desc _d = SLOP_SET_DESC(howl_types_RoleId, slop_hash_howl_types_RoleId, slop_eq_howl_types_RoleId, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
                    uint8_t grew = 1;
                    (void)(({ slop_map_put(NULL, have, &(r), NULL, 0); }));
                    (void)(({ __auto_type _lst_p = &(up); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    while (grew) {
                        grew = 0;
                        {
                            __auto_type _coll = axioms;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ax = _coll.data[_i];
                                __auto_type _mv_628 = ax;
                                switch (_mv_628.tag) {
                                    case howl_types_NormAxiom_sub_role:
                                    {
                                        __auto_type a = _mv_628.data.sub_role.f0;
                                        __auto_type c = _mv_628.data.sub_role.f1;
                                        if (slop_map_has(have, &(a)) && !(slop_map_has(have, &(c)))) {
                                            ({ slop_map_put(NULL, have, &(c), NULL, 0); });
                                            ({ __auto_type _lst_p = &(up); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            grew = 1;
                                        }
                                        break;
                                    }
                                    case howl_types_NormAxiom_sub_name:
                                    {
                                        break;
                                    }
                                    case howl_types_NormAxiom_sub_and:
                                    {
                                        break;
                                    }
                                    case howl_types_NormAxiom_sub_some_rhs:
                                    {
                                        break;
                                    }
                                    case howl_types_NormAxiom_sub_some_lhs:
                                    {
                                        break;
                                    }
                                    case howl_types_NormAxiom_role_chain:
                                    {
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    {
                        __auto_type l = ((howl_premise_RoleList){.items = up});
                        (void)(({ howl_premise_RoleList _val = l; slop_map_put(NULL, rc.sups, &(r), &_val, sizeof(_val)); }));
                    }
                }
            }
        }
        return rc;
    }
}

uint8_t howl_el_in_sups(howl_premise_RoleClosure rc, howl_types_RoleId e, howl_types_RoleId r) {
    __auto_type _mv_634 = ({ void* _ptr = slop_map_get(rc.sups, &(e)); _ptr ? (slop_option_howl_premise_RoleList){ .has_value = true, .value = *(howl_premise_RoleList*)_ptr } : (slop_option_howl_premise_RoleList){ .has_value = false }; });
    if (_mv_634.has_value) {
        __auto_type l = _mv_634.value;
        {
            uint8_t found = 0;
            {
                __auto_type _coll = l.items;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type q = _coll.data[_i];
                    if (howl_types_role_eq(q, r)) {
                        found = 1;
                    }
                }
            }
            return found;
        }
    } else if (!_mv_634.has_value) {
        return howl_types_role_eq(e, r);
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Addressed howl_el_ref_cr4_on_sub(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_Node b, howl_types_NormAxiom ax) {
    {
        __auto_type out = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_635 = ax;
        switch (_mv_635.tag) {
            case howl_types_NormAxiom_sub_some_lhs:
            {
                __auto_type r = _mv_635.data.sub_some_lhs.f0;
                __auto_type b2 = _mv_635.data.sub_some_lhs.f1;
                __auto_type a = _mv_635.data.sub_some_lhs.f2;
                {
                    slop_map* _coll = (slop_map*)ctx.preds;
                    for (size_t _i = 0; _i < _coll->len; _i++) {
                        {
                            howl_types_RoleId e = *(howl_types_RoleId*)slop_map_key_at(_coll, _i);
                            slop_map* _ = *(slop_map**)slop_map_value_at(_coll, _i);
                            if (howl_el_in_sups(rc, e, r)) {
                                {
                                    __auto_type _coll = howl_el_cr_exists_lhs_on_sub(arena, ctx, b, ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = e, .f1 = b2, .f2 = a } }));
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case howl_types_NormAxiom_sub_name:
            {
                break;
            }
            case howl_types_NormAxiom_sub_and:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_role:
            {
                break;
            }
            case howl_types_NormAxiom_role_chain:
            {
                break;
            }
        }
        return out;
    }
}

slop_list_howl_types_Addressed howl_el_ref_cr7_on_pred(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_RoleId r, howl_types_Node x, howl_types_NormAxiom ax) {
    {
        __auto_type out = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_636 = ax;
        switch (_mv_636.tag) {
            case howl_types_NormAxiom_role_chain:
            {
                __auto_type r2 = _mv_636.data.role_chain.f0;
                __auto_type s2 = _mv_636.data.role_chain.f1;
                __auto_type t = _mv_636.data.role_chain.f2;
                {
                    slop_map* _coll = (slop_map*)ctx.succs;
                    for (size_t _i = 0; _i < _coll->len; _i++) {
                        {
                            howl_types_RoleId e = *(howl_types_RoleId*)slop_map_key_at(_coll, _i);
                            slop_map* _ = *(slop_map**)slop_map_value_at(_coll, _i);
                            if (howl_el_in_sups(rc, e, s2)) {
                                {
                                    __auto_type _coll = howl_el_cr_chain_on_pred(arena, ctx, r, x, ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_role_chain, .data.role_chain = { .f0 = r2, .f1 = e, .f2 = t } }));
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case howl_types_NormAxiom_sub_name:
            {
                break;
            }
            case howl_types_NormAxiom_sub_and:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_role:
            {
                break;
            }
        }
        return out;
    }
}

slop_list_howl_types_Addressed howl_el_ref_cr7_on_succ(slop_arena* arena, howl_types_Context ctx, howl_premise_RoleClosure rc, howl_types_RoleId s, howl_types_Node z, howl_types_NormAxiom ax) {
    {
        __auto_type out = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_637 = ax;
        switch (_mv_637.tag) {
            case howl_types_NormAxiom_role_chain:
            {
                __auto_type r2 = _mv_637.data.role_chain.f0;
                __auto_type s2 = _mv_637.data.role_chain.f1;
                __auto_type t = _mv_637.data.role_chain.f2;
                {
                    slop_map* _coll = (slop_map*)ctx.preds;
                    for (size_t _i = 0; _i < _coll->len; _i++) {
                        {
                            howl_types_RoleId e = *(howl_types_RoleId*)slop_map_key_at(_coll, _i);
                            slop_map* _ = *(slop_map**)slop_map_value_at(_coll, _i);
                            if (howl_el_in_sups(rc, e, r2)) {
                                {
                                    __auto_type _coll = howl_el_cr_chain_on_succ(arena, ctx, s, z, ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_role_chain, .data.role_chain = { .f0 = e, .f1 = s2, .f2 = t } }));
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case howl_types_NormAxiom_sub_name:
            {
                break;
            }
            case howl_types_NormAxiom_sub_and:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case howl_types_NormAxiom_sub_role:
            {
                break;
            }
        }
        return out;
    }
}

slop_list_howl_types_Addressed howl_el_apply_el_rules(slop_arena* arena, howl_types_Context ctx, howl_types_Derived incoming, howl_premise_RuleIndex idx) {
    {
        __auto_type out = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_638 = incoming;
        switch (_mv_638.tag) {
            case howl_types_Derived_derived_sub:
            {
                __auto_type b = _mv_638.data.derived_sub;
                __auto_type _mv_640 = ({ void* _ptr = slop_map_get(idx.sub_by_lhs, &(b)); _ptr ? (slop_option_howl_premise_AxList){ .has_value = true, .value = *(howl_premise_AxList*)_ptr } : (slop_option_howl_premise_AxList){ .has_value = false }; });
                if (_mv_640.has_value) {
                    __auto_type l = _mv_640.value;
                    {
                        __auto_type _coll = l.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ax = _coll.data[_i];
                            {
                                __auto_type _coll = howl_el_cr_sub_name_on_sub(arena, ctx, b, ax);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type m = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                } else if (!_mv_640.has_value) {
                }
                __auto_type _mv_642 = ({ void* _ptr = slop_map_get(idx.and_by_pair, &(b)); _ptr ? (slop_option_howl_premise_Partners){ .has_value = true, .value = *(howl_premise_Partners*)_ptr } : (slop_option_howl_premise_Partners){ .has_value = false }; });
                if (_mv_642.has_value) {
                    __auto_type p = _mv_642.value;
                    if (((int64_t)(ctx.subsumers)->len) <= p.count) {
                        {
                            slop_map* _coll = (slop_map*)ctx.subsumers;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    howl_types_Node c = *(howl_types_Node*)slop_map_key_at(_coll, _i);
                                    __auto_type _mv_644 = ({ void* _ptr = slop_map_get(p.by_other, &(c)); _ptr ? (slop_option_howl_premise_AxList){ .has_value = true, .value = *(howl_premise_AxList*)_ptr } : (slop_option_howl_premise_AxList){ .has_value = false }; });
                                    if (_mv_644.has_value) {
                                        __auto_type l = _mv_644.value;
                                        {
                                            __auto_type _coll = l.items;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type ax = _coll.data[_i];
                                                {
                                                    __auto_type _coll = howl_el_cr_and_on_sub(arena, ctx, b, ax);
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type m = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                            }
                                        }
                                    } else if (!_mv_644.has_value) {
                                    }
                                }
                            }
                        }
                    } else {
                        {
                            slop_map* _coll = (slop_map*)p.by_other;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    howl_types_Node c = *(howl_types_Node*)slop_map_key_at(_coll, _i);
                                    howl_premise_AxList l = *(howl_premise_AxList*)slop_map_value_at(_coll, _i);
                                    if (slop_map_has(ctx.subsumers, &(c))) {
                                        {
                                            __auto_type _coll = l.items;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type ax = _coll.data[_i];
                                                {
                                                    __auto_type _coll = howl_el_cr_and_on_sub(arena, ctx, b, ax);
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type m = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_642.has_value) {
                }
                __auto_type _mv_647 = ({ void* _ptr = slop_map_get(idx.rhs_by_lhs, &(b)); _ptr ? (slop_option_howl_premise_AxList){ .has_value = true, .value = *(howl_premise_AxList*)_ptr } : (slop_option_howl_premise_AxList){ .has_value = false }; });
                if (_mv_647.has_value) {
                    __auto_type l = _mv_647.value;
                    {
                        __auto_type _coll = l.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ax = _coll.data[_i];
                            {
                                __auto_type _coll = howl_el_cr_some_rhs_on_sub(arena, ctx, b, ax);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type m = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                } else if (!_mv_647.has_value) {
                }
                __auto_type _mv_649 = ({ void* _ptr = slop_map_get(idx.lhs_by_filler, &(b)); _ptr ? (slop_option_howl_premise_AxList){ .has_value = true, .value = *(howl_premise_AxList*)_ptr } : (slop_option_howl_premise_AxList){ .has_value = false }; });
                if (_mv_649.has_value) {
                    __auto_type l = _mv_649.value;
                    {
                        __auto_type _coll = l.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ax = _coll.data[_i];
                            {
                                __auto_type _coll = howl_el_cr4_on_sub_through(arena, ctx, idx.roles, b, ax);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type m = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                } else if (!_mv_649.has_value) {
                }
                {
                    __auto_type _coll = howl_el_cr_bottom_on_sub(arena, ctx, b);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type m = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case howl_types_Derived_derived_pred:
            {
                __auto_type e = _mv_638.data.derived_pred.f0;
                __auto_type x = _mv_638.data.derived_pred.f1;
                {
                    __auto_type _coll = howl_el_sups_of(arena, idx.roles, e);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        __auto_type _mv_651 = ({ void* _ptr = slop_map_get(idx.lhs_by_role, &(r)); _ptr ? (slop_option_howl_premise_Partners){ .has_value = true, .value = *(howl_premise_Partners*)_ptr } : (slop_option_howl_premise_Partners){ .has_value = false }; });
                        if (_mv_651.has_value) {
                            __auto_type p = _mv_651.value;
                            if (((int64_t)(ctx.subsumers)->len) <= p.count) {
                                {
                                    slop_map* _coll = (slop_map*)ctx.subsumers;
                                    for (size_t _i = 0; _i < _coll->len; _i++) {
                                        {
                                            howl_types_Node b = *(howl_types_Node*)slop_map_key_at(_coll, _i);
                                            __auto_type _mv_653 = ({ void* _ptr = slop_map_get(p.by_other, &(b)); _ptr ? (slop_option_howl_premise_AxList){ .has_value = true, .value = *(howl_premise_AxList*)_ptr } : (slop_option_howl_premise_AxList){ .has_value = false }; });
                                            if (_mv_653.has_value) {
                                                __auto_type l = _mv_653.value;
                                                {
                                                    __auto_type _coll = l.items;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type ax = _coll.data[_i];
                                                        {
                                                            __auto_type _coll = howl_el_cr_exists_lhs_on_pred(arena, ctx, r, x, ax);
                                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                                __auto_type m = _coll.data[_i];
                                                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                            }
                                                        }
                                                    }
                                                }
                                            } else if (!_mv_653.has_value) {
                                            }
                                        }
                                    }
                                }
                            } else {
                                {
                                    slop_map* _coll = (slop_map*)p.by_other;
                                    for (size_t _i = 0; _i < _coll->len; _i++) {
                                        {
                                            howl_types_Node b = *(howl_types_Node*)slop_map_key_at(_coll, _i);
                                            howl_premise_AxList l = *(howl_premise_AxList*)slop_map_value_at(_coll, _i);
                                            if (slop_map_has(ctx.subsumers, &(b))) {
                                                {
                                                    __auto_type _coll = l.items;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type ax = _coll.data[_i];
                                                        {
                                                            __auto_type _coll = howl_el_cr_exists_lhs_on_pred(arena, ctx, r, x, ax);
                                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                                __auto_type m = _coll.data[_i];
                                                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if (!_mv_651.has_value) {
                        }
                        __auto_type _mv_656 = ({ void* _ptr = slop_map_get(idx.chain_by_first, &(r)); _ptr ? (slop_option_howl_premise_AxList){ .has_value = true, .value = *(howl_premise_AxList*)_ptr } : (slop_option_howl_premise_AxList){ .has_value = false }; });
                        if (_mv_656.has_value) {
                            __auto_type l = _mv_656.value;
                            {
                                __auto_type _coll = l.items;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type ax = _coll.data[_i];
                                    {
                                        __auto_type _coll = howl_el_cr7_on_pred_through(arena, ctx, idx.roles, r, x, ax);
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type m = _coll.data[_i];
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        } else if (!_mv_656.has_value) {
                        }
                    }
                }
                {
                    __auto_type _coll = howl_el_cr_bottom_on_pred(arena, ctx, x);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type m = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case howl_types_Derived_derived_succ:
            {
                __auto_type e = _mv_638.data.derived_succ.f0;
                __auto_type z = _mv_638.data.derived_succ.f1;
                {
                    __auto_type _coll = howl_el_sups_of(arena, idx.roles, e);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type s = _coll.data[_i];
                        __auto_type _mv_658 = ({ void* _ptr = slop_map_get(idx.chain_by_second, &(s)); _ptr ? (slop_option_howl_premise_AxList){ .has_value = true, .value = *(howl_premise_AxList*)_ptr } : (slop_option_howl_premise_AxList){ .has_value = false }; });
                        if (_mv_658.has_value) {
                            __auto_type l = _mv_658.value;
                            {
                                __auto_type _coll = l.items;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type ax = _coll.data[_i];
                                    {
                                        __auto_type _coll = howl_el_cr7_on_succ_through(arena, ctx, idx.roles, s, z, ax);
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type m = _coll.data[_i];
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        } else if (!_mv_658.has_value) {
                        }
                    }
                }
                break;
            }
        }
        return out;
    }
}

slop_list_howl_types_Addressed howl_el_apply_el_rules_reference(slop_arena* arena, howl_types_Context ctx, howl_types_Derived incoming, slop_list_howl_types_NormAxiom axioms) {
    {
        __auto_type out = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type rc = howl_el_role_closure_naive(arena, axioms);
        __auto_type _mv_659 = incoming;
        switch (_mv_659.tag) {
            case howl_types_Derived_derived_sub:
            {
                __auto_type b = _mv_659.data.derived_sub;
                {
                    __auto_type _coll = axioms;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type ax = _coll.data[_i];
                        {
                            __auto_type _coll = howl_el_cr_sub_name_on_sub(arena, ctx, b, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            __auto_type _coll = howl_el_cr_and_on_sub(arena, ctx, b, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            __auto_type _coll = howl_el_cr_some_rhs_on_sub(arena, ctx, b, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            __auto_type _coll = howl_el_ref_cr4_on_sub(arena, ctx, rc, b, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                {
                    __auto_type _coll = howl_el_cr_bottom_on_sub(arena, ctx, b);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type m = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case howl_types_Derived_derived_pred:
            {
                __auto_type e = _mv_659.data.derived_pred.f0;
                __auto_type x = _mv_659.data.derived_pred.f1;
                {
                    __auto_type _coll = howl_el_sups_of(arena, rc, e);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        {
                            __auto_type _coll = axioms;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ax = _coll.data[_i];
                                {
                                    __auto_type _coll = howl_el_cr_exists_lhs_on_pred(arena, ctx, r, x, ax);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                {
                                    __auto_type _coll = howl_el_ref_cr7_on_pred(arena, ctx, rc, r, x, ax);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    __auto_type _coll = howl_el_cr_bottom_on_pred(arena, ctx, x);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type m = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case howl_types_Derived_derived_succ:
            {
                __auto_type e = _mv_659.data.derived_succ.f0;
                __auto_type z = _mv_659.data.derived_succ.f1;
                {
                    __auto_type _coll = howl_el_sups_of(arena, rc, e);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type s = _coll.data[_i];
                        {
                            __auto_type _coll = axioms;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ax = _coll.data[_i];
                                {
                                    __auto_type _coll = howl_el_ref_cr7_on_succ(arena, ctx, rc, s, z, ax);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
        return out;
    }
}

