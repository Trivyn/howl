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
slop_list_types_Addressed el_cr_role_incl_on_pred(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node x, types_NormAxiom ax);
slop_list_types_Addressed el_cr_role_incl_on_succ(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node y, types_NormAxiom ax);
slop_list_types_Addressed el_cr_chain_on_pred(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node x, types_NormAxiom ax);
slop_list_types_Addressed el_cr_chain_on_succ(slop_arena* arena, types_Context ctx, types_RoleId s, types_Node z, types_NormAxiom ax);
slop_list_types_Addressed el_apply_el_rules(slop_arena* arena, types_Context ctx, types_Derived incoming, slop_list_types_NormAxiom axioms);

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
        ({ uint8_t _dummy = 1; slop_map_put(arena, ctx.subsumers, &(b), &_dummy); });
        ({ uint8_t _dummy = 1; slop_map_put(arena, ctx.subsumers, &(c), &_dummy); });
        return ctx;
    }
}

types_Context el_ex_ctx_bottom(slop_arena* arena) {
    {
        __auto_type ctx = types_make_context(arena, el_ex_x());
        __auto_type bot = types_node_bottom();
        ({ uint8_t _dummy = 1; slop_map_put(arena, ctx.subsumers, &(bot), &_dummy); });
        return ctx;
    }
}

slop_list_types_Addressed el_cr_sub_name_on_sub(slop_arena* arena, types_Context ctx, types_Node b, types_NormAxiom ax) {
    slop_list_types_Addressed _retval = {0};
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = (types_Addressed*)slop_arena_alloc(arena, 16 * sizeof(types_Addressed)), .len = 0, .cap = 16 });
        __auto_type _mv_29 = ax;
        switch (_mv_29.tag) {
            case types_NormAxiom_sub_name:
            {
                __auto_type b2 = _mv_29.data.sub_name.f0;
                __auto_type a = _mv_29.data.sub_name.f1;
                if (types_node_eq(b, b2)) {
                    ({ __auto_type _lst_p = &(result); __auto_type _item = (((types_Addressed){.to = ctx.root, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = a })})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    }
    SLOP_POST(((((int64_t)((_retval).len)) <= 1)), "(<= (list-len $result) 1)");
    return _retval;
}

slop_list_types_Addressed el_cr_and_on_sub(slop_arena* arena, types_Context ctx, types_Node b, types_NormAxiom ax) {
    slop_list_types_Addressed _retval = {0};
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = (types_Addressed*)slop_arena_alloc(arena, 16 * sizeof(types_Addressed)), .len = 0, .cap = 16 });
        __auto_type _mv_30 = ax;
        switch (_mv_30.tag) {
            case types_NormAxiom_sub_and:
            {
                __auto_type a1 = _mv_30.data.sub_and.f0;
                __auto_type a2 = _mv_30.data.sub_and.f1;
                __auto_type a = _mv_30.data.sub_and.f2;
                {
                    __auto_type fire = 0;
                    if (types_node_eq(b, a1)) {
                        if (slop_map_get(ctx.subsumers, &(a2)) != NULL) {
                            fire = 1;
                        }
                    } else {
                        if (types_node_eq(b, a2)) {
                            if (slop_map_get(ctx.subsumers, &(a1)) != NULL) {
                                fire = 1;
                            }
                        }
                    }
                    if (fire) {
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (((types_Addressed){.to = ctx.root, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = a })})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    }
    SLOP_POST(((((int64_t)((_retval).len)) <= 1)), "(<= (list-len $result) 1)");
    return _retval;
}

slop_list_types_Addressed el_cr_some_rhs_on_sub(slop_arena* arena, types_Context ctx, types_Node b, types_NormAxiom ax) {
    slop_list_types_Addressed _retval = {0};
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = (types_Addressed*)slop_arena_alloc(arena, 16 * sizeof(types_Addressed)), .len = 0, .cap = 16 });
        __auto_type _mv_31 = ax;
        switch (_mv_31.tag) {
            case types_NormAxiom_sub_some_rhs:
            {
                __auto_type b2 = _mv_31.data.sub_some_rhs.f0;
                __auto_type r = _mv_31.data.sub_some_rhs.f1;
                __auto_type a = _mv_31.data.sub_some_rhs.f2;
                if (types_node_eq(b, b2)) {
                    {
                        __auto_type pair = types_emit_edge(arena, ((types_LogicalEdge){.from = ctx.root, .role = r, .to = a}));
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.succ_half); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.pred_half); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    }
    SLOP_POST(((((int64_t)((_retval).len)) <= 2)), "(<= (list-len $result) 2)");
    return _retval;
}

slop_list_types_Addressed el_cr_exists_lhs_on_sub(slop_arena* arena, types_Context ctx, types_Node b, types_NormAxiom ax) {
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = (types_Addressed*)slop_arena_alloc(arena, 16 * sizeof(types_Addressed)), .len = 0, .cap = 16 });
        __auto_type _mv_32 = ax;
        switch (_mv_32.tag) {
            case types_NormAxiom_sub_some_lhs:
            {
                __auto_type r = _mv_32.data.sub_some_lhs.f0;
                __auto_type b2 = _mv_32.data.sub_some_lhs.f1;
                __auto_type a = _mv_32.data.sub_some_lhs.f2;
                if (types_node_eq(b, b2)) {
                    __auto_type _mv_33 = ({ void* _ptr = slop_map_get(ctx.preds, &(r)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                    if (_mv_33.has_value) {
                        __auto_type xs = _mv_33.value;
                        {
                            slop_map* _coll = (slop_map*)xs;
                            for (size_t _i = 0; _i < _coll->cap; _i++) {
                                if (_coll->entries[_i].occupied) {
                                    types_Node x = *(types_Node*)_coll->entries[_i].key;
                                    ({ __auto_type _lst_p = &(result); __auto_type _item = (((types_Addressed){.to = x, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = a })})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    } else if (!_mv_33.has_value) {
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
        __auto_type result = ((slop_list_types_Addressed){ .data = (types_Addressed*)slop_arena_alloc(arena, 16 * sizeof(types_Addressed)), .len = 0, .cap = 16 });
        __auto_type _mv_34 = ax;
        switch (_mv_34.tag) {
            case types_NormAxiom_sub_some_lhs:
            {
                __auto_type r2 = _mv_34.data.sub_some_lhs.f0;
                __auto_type b = _mv_34.data.sub_some_lhs.f1;
                __auto_type a = _mv_34.data.sub_some_lhs.f2;
                if (types_role_eq(r, r2)) {
                    if (slop_map_get(ctx.subsumers, &(b)) != NULL) {
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (((types_Addressed){.to = x, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = a })})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    }
    SLOP_POST(((((int64_t)((_retval).len)) <= 1)), "(<= (list-len $result) 1)");
    return _retval;
}

slop_list_types_Addressed el_cr_bottom_on_sub(slop_arena* arena, types_Context ctx, types_Node b) {
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = (types_Addressed*)slop_arena_alloc(arena, 16 * sizeof(types_Addressed)), .len = 0, .cap = 16 });
        __auto_type bottom = types_node_bottom();
        if (types_node_eq(b, bottom)) {
            {
                slop_map* _coll = (slop_map*)ctx.preds;
                for (size_t _i = 0; _i < _coll->cap; _i++) {
                    if (_coll->entries[_i].occupied) {
                        types_RoleId r = *(types_RoleId*)_coll->entries[_i].key;
                        slop_map* xs = *(slop_map**)_coll->entries[_i].value;
                        {
                            slop_map* _coll = (slop_map*)xs;
                            for (size_t _i = 0; _i < _coll->cap; _i++) {
                                if (_coll->entries[_i].occupied) {
                                    types_Node x = *(types_Node*)_coll->entries[_i].key;
                                    ({ __auto_type _lst_p = &(result); __auto_type _item = (((types_Addressed){.to = x, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = bottom })})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        __auto_type result = ((slop_list_types_Addressed){ .data = (types_Addressed*)slop_arena_alloc(arena, 16 * sizeof(types_Addressed)), .len = 0, .cap = 16 });
        __auto_type bottom = types_node_bottom();
        if (slop_map_get(ctx.subsumers, &(bottom)) != NULL) {
            ({ __auto_type _lst_p = &(result); __auto_type _item = (((types_Addressed){.to = x, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = bottom })})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        _retval = result;
    }
    SLOP_POST(((((int64_t)((_retval).len)) <= 1)), "(<= (list-len $result) 1)");
    return _retval;
}

slop_list_types_Addressed el_cr_role_incl_on_pred(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node x, types_NormAxiom ax) {
    slop_list_types_Addressed _retval = {0};
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = (types_Addressed*)slop_arena_alloc(arena, 16 * sizeof(types_Addressed)), .len = 0, .cap = 16 });
        __auto_type _mv_35 = ax;
        switch (_mv_35.tag) {
            case types_NormAxiom_sub_role:
            {
                __auto_type r2 = _mv_35.data.sub_role.f0;
                __auto_type s = _mv_35.data.sub_role.f1;
                if (types_role_eq(r, r2)) {
                    {
                        __auto_type pair = types_emit_edge(arena, ((types_LogicalEdge){.from = x, .role = s, .to = ctx.root}));
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.succ_half); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.pred_half); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
            case types_NormAxiom_role_chain:
            {
                break;
            }
        }
        _retval = result;
    }
    SLOP_POST(((((int64_t)((_retval).len)) <= 2)), "(<= (list-len $result) 2)");
    return _retval;
}

slop_list_types_Addressed el_cr_role_incl_on_succ(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node y, types_NormAxiom ax) {
    slop_list_types_Addressed _retval = {0};
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = (types_Addressed*)slop_arena_alloc(arena, 16 * sizeof(types_Addressed)), .len = 0, .cap = 16 });
        __auto_type _mv_36 = ax;
        switch (_mv_36.tag) {
            case types_NormAxiom_sub_role:
            {
                __auto_type r2 = _mv_36.data.sub_role.f0;
                __auto_type s = _mv_36.data.sub_role.f1;
                if (types_role_eq(r, r2)) {
                    {
                        __auto_type pair = types_emit_edge(arena, ((types_LogicalEdge){.from = ctx.root, .role = s, .to = y}));
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.succ_half); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.pred_half); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
            case types_NormAxiom_role_chain:
            {
                break;
            }
        }
        _retval = result;
    }
    SLOP_POST(((((int64_t)((_retval).len)) <= 2)), "(<= (list-len $result) 2)");
    return _retval;
}

slop_list_types_Addressed el_cr_chain_on_pred(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node x, types_NormAxiom ax) {
    {
        __auto_type result = ((slop_list_types_Addressed){ .data = (types_Addressed*)slop_arena_alloc(arena, 16 * sizeof(types_Addressed)), .len = 0, .cap = 16 });
        __auto_type _mv_37 = ax;
        switch (_mv_37.tag) {
            case types_NormAxiom_role_chain:
            {
                __auto_type r2 = _mv_37.data.role_chain.f0;
                __auto_type s = _mv_37.data.role_chain.f1;
                __auto_type t = _mv_37.data.role_chain.f2;
                if (types_role_eq(r, r2)) {
                    __auto_type _mv_38 = ({ void* _ptr = slop_map_get(ctx.succs, &(s)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                    if (_mv_38.has_value) {
                        __auto_type zs = _mv_38.value;
                        {
                            slop_map* _coll = (slop_map*)zs;
                            for (size_t _i = 0; _i < _coll->cap; _i++) {
                                if (_coll->entries[_i].occupied) {
                                    types_Node z = *(types_Node*)_coll->entries[_i].key;
                                    {
                                        __auto_type pair = types_emit_edge(arena, ((types_LogicalEdge){.from = x, .role = t, .to = z}));
                                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.succ_half); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.pred_half); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    } else if (!_mv_38.has_value) {
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
        __auto_type result = ((slop_list_types_Addressed){ .data = (types_Addressed*)slop_arena_alloc(arena, 16 * sizeof(types_Addressed)), .len = 0, .cap = 16 });
        __auto_type _mv_39 = ax;
        switch (_mv_39.tag) {
            case types_NormAxiom_role_chain:
            {
                __auto_type r = _mv_39.data.role_chain.f0;
                __auto_type s2 = _mv_39.data.role_chain.f1;
                __auto_type t = _mv_39.data.role_chain.f2;
                if (types_role_eq(s, s2)) {
                    __auto_type _mv_40 = ({ void* _ptr = slop_map_get(ctx.preds, &(r)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                    if (_mv_40.has_value) {
                        __auto_type xs = _mv_40.value;
                        {
                            slop_map* _coll = (slop_map*)xs;
                            for (size_t _i = 0; _i < _coll->cap; _i++) {
                                if (_coll->entries[_i].occupied) {
                                    types_Node x = *(types_Node*)_coll->entries[_i].key;
                                    {
                                        __auto_type pair = types_emit_edge(arena, ((types_LogicalEdge){.from = x, .role = t, .to = z}));
                                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.succ_half); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        ({ __auto_type _lst_p = &(result); __auto_type _item = (pair.pred_half); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    } else if (!_mv_40.has_value) {
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

slop_list_types_Addressed el_apply_el_rules(slop_arena* arena, types_Context ctx, types_Derived incoming, slop_list_types_NormAxiom axioms) {
    {
        __auto_type out = ((slop_list_types_Addressed){ .data = (types_Addressed*)slop_arena_alloc(arena, 16 * sizeof(types_Addressed)), .len = 0, .cap = 16 });
        __auto_type _mv_41 = incoming;
        switch (_mv_41.tag) {
            case types_Derived_derived_sub:
            {
                __auto_type b = _mv_41.data.derived_sub;
                {
                    __auto_type _coll = axioms;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type ax = _coll.data[_i];
                        {
                            __auto_type _coll = el_cr_sub_name_on_sub(arena, ctx, b, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            __auto_type _coll = el_cr_and_on_sub(arena, ctx, b, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            __auto_type _coll = el_cr_some_rhs_on_sub(arena, ctx, b, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            __auto_type _coll = el_cr_exists_lhs_on_sub(arena, ctx, b, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                {
                    __auto_type _coll = el_cr_bottom_on_sub(arena, ctx, b);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type m = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case types_Derived_derived_pred:
            {
                __auto_type r = _mv_41.data.derived_pred.f0;
                __auto_type x = _mv_41.data.derived_pred.f1;
                {
                    __auto_type _coll = axioms;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type ax = _coll.data[_i];
                        {
                            __auto_type _coll = el_cr_exists_lhs_on_pred(arena, ctx, r, x, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            __auto_type _coll = el_cr_role_incl_on_pred(arena, ctx, r, x, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            __auto_type _coll = el_cr_chain_on_pred(arena, ctx, r, x, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                {
                    __auto_type _coll = el_cr_bottom_on_pred(arena, ctx, x);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type m = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case types_Derived_derived_succ:
            {
                __auto_type r = _mv_41.data.derived_succ.f0;
                __auto_type y = _mv_41.data.derived_succ.f1;
                {
                    __auto_type _coll = axioms;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type ax = _coll.data[_i];
                        {
                            __auto_type _coll = el_cr_role_incl_on_succ(arena, ctx, r, y, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            __auto_type _coll = el_cr_chain_on_succ(arena, ctx, r, y, ax);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type m = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

