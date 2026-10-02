#include "../runtime/slop_runtime.h"
#include "slop_el.h"

types_Node el_ex_x(void);
types_Node el_ex_a(void);
types_Node el_ex_b(void);
types_Node el_ex_c(void);
types_RoleId el_ex_r(void);
types_Context el_ex_ctx(slop_arena* arena);
types_Context el_ex_ctx_bottom(slop_arena* arena);
slop_list_types_Addressed el_cr_sub_name_on_sub(slop_arena* arena, types_Context ctx, types_Node b, types_NormAxiom ax);
slop_list_types_Addressed el_cr_and_on_sub(slop_arena* arena, types_Context ctx, types_Node b, types_NormAxiom ax);
slop_list_types_Addressed el_cr_some_rhs_on_sub(slop_arena* arena, types_Context ctx, types_Node b, types_NormAxiom ax);
slop_list_types_Addressed el_cr_exists_lhs_on_sub(slop_arena* arena, types_Context ctx, types_Node b, types_NormAxiom ax);
slop_list_types_Addressed el_cr_exists_lhs_on_pred(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node x, types_NormAxiom ax);
slop_list_types_Addressed el_cr_bottom_on_sub(slop_arena* arena, types_Context ctx, types_Node b);
slop_list_types_Addressed el_cr_bottom_on_pred(slop_arena* arena, types_Context ctx, types_Node x);
slop_list_types_Addressed el_cr_chain_on_pred(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node x, types_NormAxiom ax);
slop_list_types_Addressed el_cr_chain_on_succ(slop_arena* arena, types_Context ctx, types_RoleId s, types_Node z, types_NormAxiom ax);
slop_list_types_RoleId el_sups_of(slop_arena* arena, premise_RoleClosure rc, types_RoleId e);
slop_list_types_Addressed el_cr4_on_sub_through(slop_arena* arena, types_Context ctx, premise_RoleClosure rc, types_Node b, types_NormAxiom ax);
slop_list_types_Addressed el_cr7_on_pred_through(slop_arena* arena, types_Context ctx, premise_RoleClosure rc, types_RoleId r, types_Node x, types_NormAxiom ax);
slop_list_types_Addressed el_cr7_on_succ_through(slop_arena* arena, types_Context ctx, premise_RoleClosure rc, types_RoleId s, types_Node z, types_NormAxiom ax);
premise_RoleClosure el_role_closure_naive(slop_arena* arena, slop_list_types_NormAxiom axioms);
uint8_t el_in_sups(premise_RoleClosure rc, types_RoleId e, types_RoleId r);
slop_list_types_Addressed el_ref_cr4_on_sub(slop_arena* arena, types_Context ctx, premise_RoleClosure rc, types_Node b, types_NormAxiom ax);
slop_list_types_Addressed el_ref_cr7_on_pred(slop_arena* arena, types_Context ctx, premise_RoleClosure rc, types_RoleId r, types_Node x, types_NormAxiom ax);
slop_list_types_Addressed el_ref_cr7_on_succ(slop_arena* arena, types_Context ctx, premise_RoleClosure rc, types_RoleId s, types_Node z, types_NormAxiom ax);
slop_list_types_Addressed el_apply_el_rules(slop_arena* arena, types_Context ctx, types_Derived incoming, premise_RuleIndex idx);
slop_list_types_Addressed el_apply_el_rules_reference(slop_arena* arena, types_Context ctx, types_Derived incoming, slop_list_types_NormAxiom axioms);

types_Node el_ex_x(void) {
    return ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = SLOP_STR("http://example.org/X")}) });
}

types_Node el_ex_a(void) {
    return ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = SLOP_STR("http://example.org/A")}) });
}

types_Node el_ex_b(void) {
    return ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = SLOP_STR("http://example.org/B")}) });
}

types_Node el_ex_c(void) {
    return ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = SLOP_STR("http://example.org/C")}) });
}

types_RoleId el_ex_r(void) {
    return ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = ((rdf_IRI){.value = SLOP_STR("http://example.org/r")}) });
}

types_Context el_ex_ctx(slop_arena* arena) {
    {
        __auto_type ctx = types_make_context(arena, el_ex_x());
        __auto_type b = el_ex_b();
        __auto_type c = el_ex_c();
        ({ slop_map_put(arena, ctx.subsumers, &(b), NULL, 0); });
        ({ slop_map_put(arena, ctx.subsumers, &(c), NULL, 0); });
        return ctx;
    }
}

types_Context el_ex_ctx_bottom(slop_arena* arena) {
    {
        __auto_type ctx = types_make_context(arena, el_ex_x());
        __auto_type bot = types_node_bottom();
        ({ slop_map_put(arena, ctx.subsumers, &(bot), NULL, 0); });
        return ctx;
    }
}

slop_list_types_Addressed el_cr_sub_name_on_sub(slop_arena* arena, types_Context ctx, types_Node b, types_NormAxiom ax) {
    slop_list_types_Addressed _retval = {0};
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_192 = ax;
        switch (_mv_192.tag) {
            case types_NormAxiom_sub_name:
            {
                __auto_type b2 = _mv_192.data.sub_name.f0;
                __auto_type a = _mv_192.data.sub_name.f1;
                if (types_node_eq(b, b2)) {
                    ({ __auto_type _lst_p = &(result); __auto_type _item = (((types_Addressed){.to = ctx.root, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = a })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                break;
            }
            case types_NormAxiom_sub_and:
            {
                break;
            }
            case types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case types_NormAxiom_sub_role:
            {
                break;
            }
            case types_NormAxiom_role_chain:
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

slop_list_types_Addressed el_cr_and_on_sub(slop_arena* arena, types_Context ctx, types_Node b, types_NormAxiom ax) {
    slop_list_types_Addressed _retval = {0};
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_193 = ax;
        switch (_mv_193.tag) {
            case types_NormAxiom_sub_and:
            {
                __auto_type a1 = _mv_193.data.sub_and.f0;
                __auto_type a2 = _mv_193.data.sub_and.f1;
                __auto_type a = _mv_193.data.sub_and.f2;
                {
                    __auto_type fire = 0;
                    if (types_node_eq(b, a1)) {
                        if (slop_map_has(ctx.subsumers, &(a2))) {
                            fire = 1;
                        }
                    } else {
                        if (types_node_eq(b, a2)) {
                            if (slop_map_has(ctx.subsumers, &(a1))) {
                                fire = 1;
                            }
                        }
                    }
                    if (fire) {
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (((types_Addressed){.to = ctx.root, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = a })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case types_NormAxiom_sub_name:
            {
                break;
            }
            case types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case types_NormAxiom_sub_role:
            {
                break;
            }
            case types_NormAxiom_role_chain:
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

slop_list_types_Addressed el_cr_some_rhs_on_sub(slop_arena* arena, types_Context ctx, types_Node b, types_NormAxiom ax) {
    slop_list_types_Addressed _retval = {0};
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_196 = ax;
        switch (_mv_196.tag) {
            case types_NormAxiom_sub_some_rhs:
            {
                __auto_type b2 = _mv_196.data.sub_some_rhs.f0;
                __auto_type r = _mv_196.data.sub_some_rhs.f1;
                __auto_type a = _mv_196.data.sub_some_rhs.f2;
                if (types_node_eq(b, b2)) {
                    {
                        __auto_type pair = types_emit_edge(arena, ((types_LogicalEdge){.from = ctx.root, .role = r, .to = a}));
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.succ_half); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.pred_half); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case types_NormAxiom_sub_name:
            {
                break;
            }
            case types_NormAxiom_sub_and:
            {
                break;
            }
            case types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case types_NormAxiom_sub_role:
            {
                break;
            }
            case types_NormAxiom_role_chain:
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

slop_list_types_Addressed el_cr_exists_lhs_on_sub(slop_arena* arena, types_Context ctx, types_Node b, types_NormAxiom ax) {
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_197 = ax;
        switch (_mv_197.tag) {
            case types_NormAxiom_sub_some_lhs:
            {
                __auto_type r = _mv_197.data.sub_some_lhs.f0;
                __auto_type b2 = _mv_197.data.sub_some_lhs.f1;
                __auto_type a = _mv_197.data.sub_some_lhs.f2;
                if (types_node_eq(b, b2)) {
                    __auto_type _mv_199 = ({ void* _ptr = slop_map_get(ctx.preds, &(r)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
                    if (_mv_199.has_value) {
                        __auto_type xs = _mv_199.value;
                        {
                            slop_map* _coll = (slop_map*)xs;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    types_Node x = *(types_Node*)slop_map_key_at(_coll, _i);
                                    ({ __auto_type _lst_p = &(result); __auto_type _item = (((types_Addressed){.to = x, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = a })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    } else if (!_mv_199.has_value) {
                    }
                }
                break;
            }
            case types_NormAxiom_sub_name:
            {
                break;
            }
            case types_NormAxiom_sub_and:
            {
                break;
            }
            case types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case types_NormAxiom_sub_role:
            {
                break;
            }
            case types_NormAxiom_role_chain:
            {
                break;
            }
        }
        return result;
    }
}

slop_list_types_Addressed el_cr_exists_lhs_on_pred(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node x, types_NormAxiom ax) {
    slop_list_types_Addressed _retval = {0};
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_200 = ax;
        switch (_mv_200.tag) {
            case types_NormAxiom_sub_some_lhs:
            {
                __auto_type r2 = _mv_200.data.sub_some_lhs.f0;
                __auto_type b = _mv_200.data.sub_some_lhs.f1;
                __auto_type a = _mv_200.data.sub_some_lhs.f2;
                if (types_role_eq(r, r2)) {
                    if (slop_map_has(ctx.subsumers, &(b))) {
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (((types_Addressed){.to = x, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = a })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case types_NormAxiom_sub_name:
            {
                break;
            }
            case types_NormAxiom_sub_and:
            {
                break;
            }
            case types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case types_NormAxiom_sub_role:
            {
                break;
            }
            case types_NormAxiom_role_chain:
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

slop_list_types_Addressed el_cr_bottom_on_sub(slop_arena* arena, types_Context ctx, types_Node b) {
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type bottom = types_node_bottom();
        if (types_node_eq(b, bottom)) {
            {
                slop_map* _coll = (slop_map*)ctx.preds;
                for (size_t _i = 0; _i < _coll->len; _i++) {
                    {
                        types_RoleId r = *(types_RoleId*)slop_map_key_at(_coll, _i);
                        slop_map* xs = *(slop_map**)slop_map_value_at(_coll, _i);
                        {
                            slop_map* _coll = (slop_map*)xs;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    types_Node x = *(types_Node*)slop_map_key_at(_coll, _i);
                                    ({ __auto_type _lst_p = &(result); __auto_type _item = (((types_Addressed){.to = x, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = bottom })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

slop_list_types_Addressed el_cr_bottom_on_pred(slop_arena* arena, types_Context ctx, types_Node x) {
    slop_list_types_Addressed _retval = {0};
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type bottom = types_node_bottom();
        if (slop_map_has(ctx.subsumers, &(bottom))) {
            ({ __auto_type _lst_p = &(result); __auto_type _item = (((types_Addressed){.to = x, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = bottom })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) <= 1)), "(<= (list-len $result) 1)");
    return _retval;
}

slop_list_types_Addressed el_cr_chain_on_pred(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node x, types_NormAxiom ax) {
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_203 = ax;
        switch (_mv_203.tag) {
            case types_NormAxiom_role_chain:
            {
                __auto_type r2 = _mv_203.data.role_chain.f0;
                __auto_type s = _mv_203.data.role_chain.f1;
                __auto_type t = _mv_203.data.role_chain.f2;
                if (types_role_eq(r, r2)) {
                    __auto_type _mv_205 = ({ void* _ptr = slop_map_get(ctx.succs, &(s)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
                    if (_mv_205.has_value) {
                        __auto_type zs = _mv_205.value;
                        {
                            slop_map* _coll = (slop_map*)zs;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    types_Node z = *(types_Node*)slop_map_key_at(_coll, _i);
                                    {
                                        __auto_type pair = types_emit_edge(arena, ((types_LogicalEdge){.from = x, .role = t, .to = z}));
                                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.succ_half); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.pred_half); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    } else if (!_mv_205.has_value) {
                    }
                }
                break;
            }
            case types_NormAxiom_sub_name:
            {
                break;
            }
            case types_NormAxiom_sub_and:
            {
                break;
            }
            case types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case types_NormAxiom_sub_role:
            {
                break;
            }
        }
        return result;
    }
}

slop_list_types_Addressed el_cr_chain_on_succ(slop_arena* arena, types_Context ctx, types_RoleId s, types_Node z, types_NormAxiom ax) {
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_206 = ax;
        switch (_mv_206.tag) {
            case types_NormAxiom_role_chain:
            {
                __auto_type r = _mv_206.data.role_chain.f0;
                __auto_type s2 = _mv_206.data.role_chain.f1;
                __auto_type t = _mv_206.data.role_chain.f2;
                if (types_role_eq(s, s2)) {
                    __auto_type _mv_208 = ({ void* _ptr = slop_map_get(ctx.preds, &(r)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
                    if (_mv_208.has_value) {
                        __auto_type xs = _mv_208.value;
                        {
                            slop_map* _coll = (slop_map*)xs;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    types_Node x = *(types_Node*)slop_map_key_at(_coll, _i);
                                    {
                                        __auto_type pair = types_emit_edge(arena, ((types_LogicalEdge){.from = x, .role = t, .to = z}));
                                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.succ_half); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.pred_half); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    } else if (!_mv_208.has_value) {
                    }
                }
                break;
            }
            case types_NormAxiom_sub_name:
            {
                break;
            }
            case types_NormAxiom_sub_and:
            {
                break;
            }
            case types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case types_NormAxiom_sub_role:
            {
                break;
            }
        }
        return result;
    }
}

slop_list_types_RoleId el_sups_of(slop_arena* arena, premise_RoleClosure rc, types_RoleId e) {
    __auto_type _mv_210 = ({ void* _ptr = slop_map_get(rc.sups, &(e)); _ptr ? (slop_option_premise_RoleList){ .has_value = true, .value = *(premise_RoleList*)_ptr } : (slop_option_premise_RoleList){ .has_value = false }; });
    if (_mv_210.has_value) {
        __auto_type l = _mv_210.value;
        return l.items;
    } else if (!_mv_210.has_value) {
        {
            __auto_type one = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 });
            ({ __auto_type _lst_p = &(one); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            return one;
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_types_Addressed el_cr4_on_sub_through(slop_arena* arena, types_Context ctx, premise_RoleClosure rc, types_Node b, types_NormAxiom ax) {
    {
        __auto_type out = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_211 = ax;
        switch (_mv_211.tag) {
            case types_NormAxiom_sub_some_lhs:
            {
                __auto_type r = _mv_211.data.sub_some_lhs.f0;
                __auto_type b2 = _mv_211.data.sub_some_lhs.f1;
                __auto_type a = _mv_211.data.sub_some_lhs.f2;
                __auto_type _mv_213 = ({ void* _ptr = slop_map_get(rc.subs, &(r)); _ptr ? (slop_option_premise_RoleList){ .has_value = true, .value = *(premise_RoleList*)_ptr } : (slop_option_premise_RoleList){ .has_value = false }; });
                if (_mv_213.has_value) {
                    __auto_type es = _mv_213.value;
                    {
                        __auto_type _coll = es.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type e = _coll.data[_i];
                            {
                                __auto_type via = ((types_NormAxiom){ .tag = types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = e, .f1 = b2, .f2 = a } });
                                {
                                    __auto_type _coll = el_cr_exists_lhs_on_sub(arena, ctx, b, via);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_213.has_value) {
                    {
                        __auto_type _coll = el_cr_exists_lhs_on_sub(arena, ctx, b, ax);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type m = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case types_NormAxiom_sub_name:
            {
                break;
            }
            case types_NormAxiom_sub_and:
            {
                break;
            }
            case types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case types_NormAxiom_sub_role:
            {
                break;
            }
            case types_NormAxiom_role_chain:
            {
                break;
            }
        }
        return out;
    }
}

slop_list_types_Addressed el_cr7_on_pred_through(slop_arena* arena, types_Context ctx, premise_RoleClosure rc, types_RoleId r, types_Node x, types_NormAxiom ax) {
    {
        __auto_type out = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_214 = ax;
        switch (_mv_214.tag) {
            case types_NormAxiom_role_chain:
            {
                __auto_type r2 = _mv_214.data.role_chain.f0;
                __auto_type s2 = _mv_214.data.role_chain.f1;
                __auto_type t = _mv_214.data.role_chain.f2;
                __auto_type _mv_216 = ({ void* _ptr = slop_map_get(rc.subs, &(s2)); _ptr ? (slop_option_premise_RoleList){ .has_value = true, .value = *(premise_RoleList*)_ptr } : (slop_option_premise_RoleList){ .has_value = false }; });
                if (_mv_216.has_value) {
                    __auto_type es = _mv_216.value;
                    {
                        __auto_type _coll = es.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type e = _coll.data[_i];
                            {
                                __auto_type via = ((types_NormAxiom){ .tag = types_NormAxiom_role_chain, .data.role_chain = { .f0 = r2, .f1 = e, .f2 = t } });
                                {
                                    __auto_type _coll = el_cr_chain_on_pred(arena, ctx, r, x, via);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_216.has_value) {
                    {
                        __auto_type _coll = el_cr_chain_on_pred(arena, ctx, r, x, ax);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type m = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case types_NormAxiom_sub_name:
            {
                break;
            }
            case types_NormAxiom_sub_and:
            {
                break;
            }
            case types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case types_NormAxiom_sub_role:
            {
                break;
            }
        }
        return out;
    }
}

slop_list_types_Addressed el_cr7_on_succ_through(slop_arena* arena, types_Context ctx, premise_RoleClosure rc, types_RoleId s, types_Node z, types_NormAxiom ax) {
    {
        __auto_type out = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_217 = ax;
        switch (_mv_217.tag) {
            case types_NormAxiom_role_chain:
            {
                __auto_type r2 = _mv_217.data.role_chain.f0;
                __auto_type s2 = _mv_217.data.role_chain.f1;
                __auto_type t = _mv_217.data.role_chain.f2;
                __auto_type _mv_219 = ({ void* _ptr = slop_map_get(rc.subs, &(r2)); _ptr ? (slop_option_premise_RoleList){ .has_value = true, .value = *(premise_RoleList*)_ptr } : (slop_option_premise_RoleList){ .has_value = false }; });
                if (_mv_219.has_value) {
                    __auto_type es = _mv_219.value;
                    {
                        __auto_type _coll = es.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type e = _coll.data[_i];
                            {
                                __auto_type via = ((types_NormAxiom){ .tag = types_NormAxiom_role_chain, .data.role_chain = { .f0 = e, .f1 = s2, .f2 = t } });
                                {
                                    __auto_type _coll = el_cr_chain_on_succ(arena, ctx, s, z, via);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_219.has_value) {
                    {
                        __auto_type _coll = el_cr_chain_on_succ(arena, ctx, s, z, ax);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type m = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case types_NormAxiom_sub_name:
            {
                break;
            }
            case types_NormAxiom_sub_and:
            {
                break;
            }
            case types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case types_NormAxiom_sub_role:
            {
                break;
            }
        }
        return out;
    }
}

premise_RoleClosure el_role_closure_naive(slop_arena* arena, slop_list_types_NormAxiom axioms) {
    {
        __auto_type rc = ((premise_RoleClosure){.sups = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, premise_RoleList); slop_map_new_ptr(arena, 0, &_d); }), .subs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, premise_RoleList); slop_map_new_ptr(arena, 0, &_d); })});
        __auto_type roles = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                {
                    __auto_type _coll = premise_axiom_roles(arena, ax);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        if (!(slop_map_has(seen, &(r)))) {
                            ({ slop_map_put(arena, seen, &(r), NULL, 0); });
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                    __auto_type up = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 });
                    __auto_type have = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
                    uint8_t grew = 1;
                    ({ slop_map_put(arena, have, &(r), NULL, 0); });
                    ({ __auto_type _lst_p = &(up); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    while (grew) {
                        grew = 0;
                        {
                            __auto_type _coll = axioms;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ax = _coll.data[_i];
                                __auto_type _mv_223 = ax;
                                switch (_mv_223.tag) {
                                    case types_NormAxiom_sub_role:
                                    {
                                        __auto_type a = _mv_223.data.sub_role.f0;
                                        __auto_type c = _mv_223.data.sub_role.f1;
                                        if (slop_map_has(have, &(a)) && !(slop_map_has(have, &(c)))) {
                                            ({ slop_map_put(arena, have, &(c), NULL, 0); });
                                            ({ __auto_type _lst_p = &(up); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            grew = 1;
                                        }
                                        break;
                                    }
                                    case types_NormAxiom_sub_name:
                                    {
                                        break;
                                    }
                                    case types_NormAxiom_sub_and:
                                    {
                                        break;
                                    }
                                    case types_NormAxiom_sub_some_rhs:
                                    {
                                        break;
                                    }
                                    case types_NormAxiom_sub_some_lhs:
                                    {
                                        break;
                                    }
                                    case types_NormAxiom_role_chain:
                                    {
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    {
                        __auto_type l = ((premise_RoleList){.items = up});
                        ({ premise_RoleList _val = l; slop_map_put(arena, rc.sups, &(r), &_val, sizeof(_val)); });
                    }
                }
            }
        }
        return rc;
    }
}

uint8_t el_in_sups(premise_RoleClosure rc, types_RoleId e, types_RoleId r) {
    __auto_type _mv_229 = ({ void* _ptr = slop_map_get(rc.sups, &(e)); _ptr ? (slop_option_premise_RoleList){ .has_value = true, .value = *(premise_RoleList*)_ptr } : (slop_option_premise_RoleList){ .has_value = false }; });
    if (_mv_229.has_value) {
        __auto_type l = _mv_229.value;
        {
            __auto_type found = 0;
            {
                __auto_type _coll = l.items;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type q = _coll.data[_i];
                    if (types_role_eq(q, r)) {
                        found = 1;
                    }
                }
            }
            return found;
        }
    } else if (!_mv_229.has_value) {
        return types_role_eq(e, r);
    }
    SLOP_UNREACHABLE();
}

slop_list_types_Addressed el_ref_cr4_on_sub(slop_arena* arena, types_Context ctx, premise_RoleClosure rc, types_Node b, types_NormAxiom ax) {
    {
        __auto_type out = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_230 = ax;
        switch (_mv_230.tag) {
            case types_NormAxiom_sub_some_lhs:
            {
                __auto_type r = _mv_230.data.sub_some_lhs.f0;
                __auto_type b2 = _mv_230.data.sub_some_lhs.f1;
                __auto_type a = _mv_230.data.sub_some_lhs.f2;
                {
                    slop_map* _coll = (slop_map*)ctx.preds;
                    for (size_t _i = 0; _i < _coll->len; _i++) {
                        {
                            types_RoleId e = *(types_RoleId*)slop_map_key_at(_coll, _i);
                            slop_map* _ = *(slop_map**)slop_map_value_at(_coll, _i);
                            if (el_in_sups(rc, e, r)) {
                                {
                                    __auto_type _coll = el_cr_exists_lhs_on_sub(arena, ctx, b, ((types_NormAxiom){ .tag = types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = e, .f1 = b2, .f2 = a } }));
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case types_NormAxiom_sub_name:
            {
                break;
            }
            case types_NormAxiom_sub_and:
            {
                break;
            }
            case types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case types_NormAxiom_sub_role:
            {
                break;
            }
            case types_NormAxiom_role_chain:
            {
                break;
            }
        }
        return out;
    }
}

slop_list_types_Addressed el_ref_cr7_on_pred(slop_arena* arena, types_Context ctx, premise_RoleClosure rc, types_RoleId r, types_Node x, types_NormAxiom ax) {
    {
        __auto_type out = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_231 = ax;
        switch (_mv_231.tag) {
            case types_NormAxiom_role_chain:
            {
                __auto_type r2 = _mv_231.data.role_chain.f0;
                __auto_type s2 = _mv_231.data.role_chain.f1;
                __auto_type t = _mv_231.data.role_chain.f2;
                {
                    slop_map* _coll = (slop_map*)ctx.succs;
                    for (size_t _i = 0; _i < _coll->len; _i++) {
                        {
                            types_RoleId e = *(types_RoleId*)slop_map_key_at(_coll, _i);
                            slop_map* _ = *(slop_map**)slop_map_value_at(_coll, _i);
                            if (el_in_sups(rc, e, s2)) {
                                {
                                    __auto_type _coll = el_cr_chain_on_pred(arena, ctx, r, x, ((types_NormAxiom){ .tag = types_NormAxiom_role_chain, .data.role_chain = { .f0 = r2, .f1 = e, .f2 = t } }));
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case types_NormAxiom_sub_name:
            {
                break;
            }
            case types_NormAxiom_sub_and:
            {
                break;
            }
            case types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case types_NormAxiom_sub_role:
            {
                break;
            }
        }
        return out;
    }
}

slop_list_types_Addressed el_ref_cr7_on_succ(slop_arena* arena, types_Context ctx, premise_RoleClosure rc, types_RoleId s, types_Node z, types_NormAxiom ax) {
    {
        __auto_type out = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_232 = ax;
        switch (_mv_232.tag) {
            case types_NormAxiom_role_chain:
            {
                __auto_type r2 = _mv_232.data.role_chain.f0;
                __auto_type s2 = _mv_232.data.role_chain.f1;
                __auto_type t = _mv_232.data.role_chain.f2;
                {
                    slop_map* _coll = (slop_map*)ctx.preds;
                    for (size_t _i = 0; _i < _coll->len; _i++) {
                        {
                            types_RoleId e = *(types_RoleId*)slop_map_key_at(_coll, _i);
                            slop_map* _ = *(slop_map**)slop_map_value_at(_coll, _i);
                            if (el_in_sups(rc, e, r2)) {
                                {
                                    __auto_type _coll = el_cr_chain_on_succ(arena, ctx, s, z, ((types_NormAxiom){ .tag = types_NormAxiom_role_chain, .data.role_chain = { .f0 = e, .f1 = s2, .f2 = t } }));
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case types_NormAxiom_sub_name:
            {
                break;
            }
            case types_NormAxiom_sub_and:
            {
                break;
            }
            case types_NormAxiom_sub_some_rhs:
            {
                break;
            }
            case types_NormAxiom_sub_some_lhs:
            {
                break;
            }
            case types_NormAxiom_sub_role:
            {
                break;
            }
        }
        return out;
    }
}

slop_list_types_Addressed el_apply_el_rules(slop_arena* arena, types_Context ctx, types_Derived incoming, premise_RuleIndex idx) {
    {
        __auto_type out = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_233 = incoming;
        switch (_mv_233.tag) {
            case types_Derived_derived_sub:
            {
                __auto_type b = _mv_233.data.derived_sub;
                __auto_type _mv_235 = ({ void* _ptr = slop_map_get(idx.sub_by_lhs, &(b)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; });
                if (_mv_235.has_value) {
                    __auto_type l = _mv_235.value;
                    {
                        __auto_type _coll = l.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ax = _coll.data[_i];
                            {
                                __auto_type _coll = el_cr_sub_name_on_sub(arena, ctx, b, ax);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type m = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                } else if (!_mv_235.has_value) {
                }
                __auto_type _mv_237 = ({ void* _ptr = slop_map_get(idx.and_by_pair, &(b)); _ptr ? (slop_option_premise_Partners){ .has_value = true, .value = *(premise_Partners*)_ptr } : (slop_option_premise_Partners){ .has_value = false }; });
                if (_mv_237.has_value) {
                    __auto_type p = _mv_237.value;
                    if (((int64_t)(ctx.subsumers)->len) <= p.count) {
                        {
                            slop_map* _coll = (slop_map*)ctx.subsumers;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    types_Node c = *(types_Node*)slop_map_key_at(_coll, _i);
                                    __auto_type _mv_239 = ({ void* _ptr = slop_map_get(p.by_other, &(c)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; });
                                    if (_mv_239.has_value) {
                                        __auto_type l = _mv_239.value;
                                        {
                                            __auto_type _coll = l.items;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type ax = _coll.data[_i];
                                                {
                                                    __auto_type _coll = el_cr_and_on_sub(arena, ctx, b, ax);
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type m = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                            }
                                        }
                                    } else if (!_mv_239.has_value) {
                                    }
                                }
                            }
                        }
                    } else {
                        {
                            slop_map* _coll = (slop_map*)p.by_other;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    types_Node c = *(types_Node*)slop_map_key_at(_coll, _i);
                                    premise_AxList l = *(premise_AxList*)slop_map_value_at(_coll, _i);
                                    if (slop_map_has(ctx.subsumers, &(c))) {
                                        {
                                            __auto_type _coll = l.items;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type ax = _coll.data[_i];
                                                {
                                                    __auto_type _coll = el_cr_and_on_sub(arena, ctx, b, ax);
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type m = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_237.has_value) {
                }
                __auto_type _mv_242 = ({ void* _ptr = slop_map_get(idx.rhs_by_lhs, &(b)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; });
                if (_mv_242.has_value) {
                    __auto_type l = _mv_242.value;
                    {
                        __auto_type _coll = l.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ax = _coll.data[_i];
                            {
                                __auto_type _coll = el_cr_some_rhs_on_sub(arena, ctx, b, ax);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type m = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                } else if (!_mv_242.has_value) {
                }
                __auto_type _mv_244 = ({ void* _ptr = slop_map_get(idx.lhs_by_filler, &(b)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; });
                if (_mv_244.has_value) {
                    __auto_type l = _mv_244.value;
                    {
                        __auto_type _coll = l.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ax = _coll.data[_i];
                            {
                                __auto_type _coll = el_cr4_on_sub_through(arena, ctx, idx.roles, b, ax);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type m = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                } else if (!_mv_244.has_value) {
                }
                {
                    __auto_type _coll = el_cr_bottom_on_sub(arena, ctx, b);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type m = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case types_Derived_derived_pred:
            {
                __auto_type e = _mv_233.data.derived_pred.f0;
                __auto_type x = _mv_233.data.derived_pred.f1;
                {
                    __auto_type _coll = el_sups_of(arena, idx.roles, e);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        __auto_type _mv_246 = ({ void* _ptr = slop_map_get(idx.lhs_by_role, &(r)); _ptr ? (slop_option_premise_Partners){ .has_value = true, .value = *(premise_Partners*)_ptr } : (slop_option_premise_Partners){ .has_value = false }; });
                        if (_mv_246.has_value) {
                            __auto_type p = _mv_246.value;
                            if (((int64_t)(ctx.subsumers)->len) <= p.count) {
                                {
                                    slop_map* _coll = (slop_map*)ctx.subsumers;
                                    for (size_t _i = 0; _i < _coll->len; _i++) {
                                        {
                                            types_Node b = *(types_Node*)slop_map_key_at(_coll, _i);
                                            __auto_type _mv_248 = ({ void* _ptr = slop_map_get(p.by_other, &(b)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; });
                                            if (_mv_248.has_value) {
                                                __auto_type l = _mv_248.value;
                                                {
                                                    __auto_type _coll = l.items;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type ax = _coll.data[_i];
                                                        {
                                                            __auto_type _coll = el_cr_exists_lhs_on_pred(arena, ctx, r, x, ax);
                                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                                __auto_type m = _coll.data[_i];
                                                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                            }
                                                        }
                                                    }
                                                }
                                            } else if (!_mv_248.has_value) {
                                            }
                                        }
                                    }
                                }
                            } else {
                                {
                                    slop_map* _coll = (slop_map*)p.by_other;
                                    for (size_t _i = 0; _i < _coll->len; _i++) {
                                        {
                                            types_Node b = *(types_Node*)slop_map_key_at(_coll, _i);
                                            premise_AxList l = *(premise_AxList*)slop_map_value_at(_coll, _i);
                                            if (slop_map_has(ctx.subsumers, &(b))) {
                                                {
                                                    __auto_type _coll = l.items;
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type ax = _coll.data[_i];
                                                        {
                                                            __auto_type _coll = el_cr_exists_lhs_on_pred(arena, ctx, r, x, ax);
                                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                                __auto_type m = _coll.data[_i];
                                                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if (!_mv_246.has_value) {
                        }
                        __auto_type _mv_251 = ({ void* _ptr = slop_map_get(idx.chain_by_first, &(r)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; });
                        if (_mv_251.has_value) {
                            __auto_type l = _mv_251.value;
                            {
                                __auto_type _coll = l.items;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type ax = _coll.data[_i];
                                    {
                                        __auto_type _coll = el_cr7_on_pred_through(arena, ctx, idx.roles, r, x, ax);
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type m = _coll.data[_i];
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        } else if (!_mv_251.has_value) {
                        }
                    }
                }
                {
                    __auto_type _coll = el_cr_bottom_on_pred(arena, ctx, x);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type m = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case types_Derived_derived_succ:
            {
                __auto_type e = _mv_233.data.derived_succ.f0;
                __auto_type z = _mv_233.data.derived_succ.f1;
                {
                    __auto_type _coll = el_sups_of(arena, idx.roles, e);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type s = _coll.data[_i];
                        __auto_type _mv_253 = ({ void* _ptr = slop_map_get(idx.chain_by_second, &(s)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; });
                        if (_mv_253.has_value) {
                            __auto_type l = _mv_253.value;
                            {
                                __auto_type _coll = l.items;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type ax = _coll.data[_i];
                                    {
                                        __auto_type _coll = el_cr7_on_succ_through(arena, ctx, idx.roles, s, z, ax);
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type m = _coll.data[_i];
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        } else if (!_mv_253.has_value) {
                        }
                    }
                }
                break;
            }
        }
        return out;
    }
}

slop_list_types_Addressed el_apply_el_rules_reference(slop_arena* arena, types_Context ctx, types_Derived incoming, slop_list_types_NormAxiom axioms) {
    {
        __auto_type out = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type rc = el_role_closure_naive(arena, axioms);
        __auto_type _mv_254 = incoming;
        switch (_mv_254.tag) {
            case types_Derived_derived_sub:
            {
                __auto_type b = _mv_254.data.derived_sub;
                {
                    __auto_type _coll = axioms;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type ax = _coll.data[_i];
                        {
                            __auto_type _coll = el_cr_sub_name_on_sub(arena, ctx, b, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            __auto_type _coll = el_cr_and_on_sub(arena, ctx, b, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            __auto_type _coll = el_cr_some_rhs_on_sub(arena, ctx, b, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            __auto_type _coll = el_ref_cr4_on_sub(arena, ctx, rc, b, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                {
                    __auto_type _coll = el_cr_bottom_on_sub(arena, ctx, b);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type m = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case types_Derived_derived_pred:
            {
                __auto_type e = _mv_254.data.derived_pred.f0;
                __auto_type x = _mv_254.data.derived_pred.f1;
                {
                    __auto_type _coll = el_sups_of(arena, rc, e);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        {
                            __auto_type _coll = axioms;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ax = _coll.data[_i];
                                {
                                    __auto_type _coll = el_cr_exists_lhs_on_pred(arena, ctx, r, x, ax);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                {
                                    __auto_type _coll = el_ref_cr7_on_pred(arena, ctx, rc, r, x, ax);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    __auto_type _coll = el_cr_bottom_on_pred(arena, ctx, x);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type m = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case types_Derived_derived_succ:
            {
                __auto_type e = _mv_254.data.derived_succ.f0;
                __auto_type z = _mv_254.data.derived_succ.f1;
                {
                    __auto_type _coll = el_sups_of(arena, rc, e);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type s = _coll.data[_i];
                        {
                            __auto_type _coll = axioms;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ax = _coll.data[_i];
                                {
                                    __auto_type _coll = el_ref_cr7_on_succ(arena, ctx, rc, s, z, ax);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

