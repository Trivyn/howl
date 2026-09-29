#include "../runtime/slop_runtime.h"
#include "slop_premise.h"

premise_AxList premise_pushed(slop_arena* arena, slop_option_premise_AxList found, types_NormAxiom ax);
premise_Partners premise_partnered(slop_arena* arena, slop_option_premise_Partners found, types_Node other, types_NormAxiom ax);
premise_RoleList premise_role_pushed(slop_arena* arena, slop_option_premise_RoleList found, types_RoleId r);
slop_list_types_RoleId premise_axiom_roles(slop_arena* arena, types_NormAxiom ax);
premise_RoleList premise_role_closure(slop_arena* arena, premise_RoleGraph g, types_RoleId r);
premise_RuleIndex premise_build_rule_index(slop_arena* arena, slop_list_types_NormAxiom axioms);

premise_AxList premise_pushed(slop_arena* arena, slop_option_premise_AxList found, types_NormAxiom ax) {
    {
        __auto_type items = ({ __auto_type _mv = found; _mv.has_value ? ({ __auto_type l = _mv.value; l.items; }) : (((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0 })); });
        ({ __auto_type _lst_p = &(items); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((premise_AxList){.items = items});
    }
}

premise_Partners premise_partnered(slop_arena* arena, slop_option_premise_Partners found, types_Node other, types_NormAxiom ax) {
    {
        __auto_type p = ({ __auto_type _mv = found; _mv.has_value ? ({ __auto_type q = _mv.value; q; }) : (((premise_Partners){.by_other = slop_map_new_ptr(arena, 0, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node), .count = 0})); });
        __auto_type prior = ({ void* _ptr = slop_map_get(p.by_other, &(other)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; });
        __auto_type l = premise_pushed(arena, prior, ax);
        ({ __auto_type _val = l; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, p.by_other, &(other), _vptr); });
        return ((premise_Partners){.by_other = p.by_other, .count = ({ __auto_type _mv = prior; _mv.has_value ? ({ __auto_type _ = _mv.value; p.count; }) : ((p.count + 1)); })});
    }
}

premise_RoleList premise_role_pushed(slop_arena* arena, slop_option_premise_RoleList found, types_RoleId r) {
    {
        __auto_type items = ({ __auto_type _mv = found; _mv.has_value ? ({ __auto_type l = _mv.value; l.items; }) : (((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 })); });
        ({ __auto_type _lst_p = &(items); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((premise_RoleList){.items = items});
    }
}

slop_list_types_RoleId premise_axiom_roles(slop_arena* arena, types_NormAxiom ax) {
    {
        __auto_type rs = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_53 = ax;
        switch (_mv_53.tag) {
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
                __auto_type r = _mv_53.data.sub_some_rhs.f1;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_NormAxiom_sub_some_lhs:
            {
                __auto_type r = _mv_53.data.sub_some_lhs.f0;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_NormAxiom_sub_role:
            {
                __auto_type r = _mv_53.data.sub_role.f0;
                __auto_type s = _mv_53.data.sub_role.f1;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_NormAxiom_role_chain:
            {
                __auto_type r = _mv_53.data.role_chain.f0;
                __auto_type s = _mv_53.data.role_chain.f1;
                __auto_type t = _mv_53.data.role_chain.f2;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
        }
        return rs;
    }
}

premise_RoleList premise_role_closure(slop_arena* arena, premise_RoleGraph g, types_RoleId r) {
    {
        __auto_type out = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type seen = slop_map_new_ptr(arena, 0, sizeof(types_RoleId), slop_hash_types_RoleId, slop_eq_types_RoleId);
        int64_t i = 0;
        ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(r), &_dummy); });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        while (i < ((int64_t)(((int64_t)((out).len))))) {
            __auto_type _mv_55 = ({ __auto_type _lst = out; size_t _idx = (size_t)i; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_55.has_value) {
                __auto_type q = _mv_55.value;
                __auto_type _mv_57 = ({ void* _ptr = slop_map_get(g.up, &(q)); _ptr ? (slop_option_premise_RoleList){ .has_value = true, .value = *(premise_RoleList*)_ptr } : (slop_option_premise_RoleList){ .has_value = false }; });
                if (_mv_57.has_value) {
                    __auto_type l = _mv_57.value;
                    {
                        __auto_type _coll = l.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type s = _coll.data[_i];
                            if (!((slop_map_get(seen, &(s)) != NULL))) {
                                ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(s), &_dummy); });
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                } else if (!_mv_57.has_value) {
                }
            } else if (!_mv_55.has_value) {
            }
            i = (i + 1);
        }
        return ((premise_RoleList){.items = out});
    }
}

premise_RuleIndex premise_build_rule_index(slop_arena* arena, slop_list_types_NormAxiom axioms) {
    {
        __auto_type idx = ((premise_RuleIndex){.sub_by_lhs = slop_map_new_ptr(arena, 0, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node), .and_by_pair = slop_map_new_ptr(arena, 0, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node), .rhs_by_lhs = slop_map_new_ptr(arena, 0, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node), .lhs_by_filler = slop_map_new_ptr(arena, 0, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node), .lhs_by_role = slop_map_new_ptr(arena, 0, sizeof(types_RoleId), slop_hash_types_RoleId, slop_eq_types_RoleId), .chain_by_first = slop_map_new_ptr(arena, 0, sizeof(types_RoleId), slop_hash_types_RoleId, slop_eq_types_RoleId), .chain_by_second = slop_map_new_ptr(arena, 0, sizeof(types_RoleId), slop_hash_types_RoleId, slop_eq_types_RoleId), .roles = ((premise_RoleClosure){.sups = slop_map_new_ptr(arena, 0, sizeof(types_RoleId), slop_hash_types_RoleId, slop_eq_types_RoleId), .subs = slop_map_new_ptr(arena, 0, sizeof(types_RoleId), slop_hash_types_RoleId, slop_eq_types_RoleId)})});
        __auto_type g = ((premise_RoleGraph){.up = slop_map_new_ptr(arena, 0, sizeof(types_RoleId), slop_hash_types_RoleId, slop_eq_types_RoleId)});
        __auto_type roles = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type seen = slop_map_new_ptr(arena, 0, sizeof(types_RoleId), slop_hash_types_RoleId, slop_eq_types_RoleId);
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_60 = ax;
                switch (_mv_60.tag) {
                    case types_NormAxiom_sub_name:
                    {
                        __auto_type b = _mv_60.data.sub_name.f0;
                        {
                            __auto_type l = premise_pushed(arena, ({ void* _ptr = slop_map_get(idx.sub_by_lhs, &(b)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; }), ax);
                            ({ __auto_type _val = l; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, idx.sub_by_lhs, &(b), _vptr); });
                        }
                        break;
                    }
                    case types_NormAxiom_sub_and:
                    {
                        __auto_type b1 = _mv_60.data.sub_and.f0;
                        __auto_type b2 = _mv_60.data.sub_and.f1;
                        {
                            __auto_type p1 = premise_partnered(arena, ({ void* _ptr = slop_map_get(idx.and_by_pair, &(b1)); _ptr ? (slop_option_premise_Partners){ .has_value = true, .value = *(premise_Partners*)_ptr } : (slop_option_premise_Partners){ .has_value = false }; }), b2, ax);
                            ({ __auto_type _val = p1; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, idx.and_by_pair, &(b1), _vptr); });
                        }
                        if (!(types_node_eq(b1, b2))) {
                            {
                                __auto_type p2 = premise_partnered(arena, ({ void* _ptr = slop_map_get(idx.and_by_pair, &(b2)); _ptr ? (slop_option_premise_Partners){ .has_value = true, .value = *(premise_Partners*)_ptr } : (slop_option_premise_Partners){ .has_value = false }; }), b1, ax);
                                ({ __auto_type _val = p2; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, idx.and_by_pair, &(b2), _vptr); });
                            }
                        }
                        break;
                    }
                    case types_NormAxiom_sub_some_rhs:
                    {
                        __auto_type b = _mv_60.data.sub_some_rhs.f0;
                        {
                            __auto_type l = premise_pushed(arena, ({ void* _ptr = slop_map_get(idx.rhs_by_lhs, &(b)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; }), ax);
                            ({ __auto_type _val = l; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, idx.rhs_by_lhs, &(b), _vptr); });
                        }
                        break;
                    }
                    case types_NormAxiom_sub_some_lhs:
                    {
                        __auto_type r = _mv_60.data.sub_some_lhs.f0;
                        __auto_type b = _mv_60.data.sub_some_lhs.f1;
                        {
                            __auto_type l = premise_pushed(arena, ({ void* _ptr = slop_map_get(idx.lhs_by_filler, &(b)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; }), ax);
                            ({ __auto_type _val = l; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, idx.lhs_by_filler, &(b), _vptr); });
                        }
                        {
                            __auto_type p = premise_partnered(arena, ({ void* _ptr = slop_map_get(idx.lhs_by_role, &(r)); _ptr ? (slop_option_premise_Partners){ .has_value = true, .value = *(premise_Partners*)_ptr } : (slop_option_premise_Partners){ .has_value = false }; }), b, ax);
                            ({ __auto_type _val = p; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, idx.lhs_by_role, &(r), _vptr); });
                        }
                        break;
                    }
                    case types_NormAxiom_sub_role:
                    {
                        __auto_type r = _mv_60.data.sub_role.f0;
                        __auto_type s = _mv_60.data.sub_role.f1;
                        {
                            __auto_type l = premise_role_pushed(arena, ({ void* _ptr = slop_map_get(g.up, &(r)); _ptr ? (slop_option_premise_RoleList){ .has_value = true, .value = *(premise_RoleList*)_ptr } : (slop_option_premise_RoleList){ .has_value = false }; }), s);
                            ({ __auto_type _val = l; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, g.up, &(r), _vptr); });
                        }
                        break;
                    }
                    case types_NormAxiom_role_chain:
                    {
                        __auto_type r = _mv_60.data.role_chain.f0;
                        __auto_type s = _mv_60.data.role_chain.f1;
                        {
                            __auto_type l1 = premise_pushed(arena, ({ void* _ptr = slop_map_get(idx.chain_by_first, &(r)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; }), ax);
                            ({ __auto_type _val = l1; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, idx.chain_by_first, &(r), _vptr); });
                        }
                        {
                            __auto_type l2 = premise_pushed(arena, ({ void* _ptr = slop_map_get(idx.chain_by_second, &(s)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; }), ax);
                            ({ __auto_type _val = l2; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, idx.chain_by_second, &(s), _vptr); });
                        }
                        break;
                    }
                }
            }
        }
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                {
                    __auto_type _coll = premise_axiom_roles(arena, ax);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        if (!((slop_map_get(seen, &(r)) != NULL))) {
                            ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(r), &_dummy); });
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                    __auto_type c = premise_role_closure(arena, g, r);
                    ({ __auto_type _val = c; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, idx.roles.sups, &(r), _vptr); });
                }
            }
        }
        {
            __auto_type _coll = roles;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                __auto_type _mv_83 = ({ void* _ptr = slop_map_get(idx.roles.sups, &(r)); _ptr ? (slop_option_premise_RoleList){ .has_value = true, .value = *(premise_RoleList*)_ptr } : (slop_option_premise_RoleList){ .has_value = false }; });
                if (_mv_83.has_value) {
                    __auto_type c = _mv_83.value;
                    {
                        __auto_type _coll = c.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type s = _coll.data[_i];
                            {
                                __auto_type l = premise_role_pushed(arena, ({ void* _ptr = slop_map_get(idx.roles.subs, &(s)); _ptr ? (slop_option_premise_RoleList){ .has_value = true, .value = *(premise_RoleList*)_ptr } : (slop_option_premise_RoleList){ .has_value = false }; }), r);
                                ({ __auto_type _val = l; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, idx.roles.subs, &(s), _vptr); });
                            }
                        }
                    }
                } else if (!_mv_83.has_value) {
                }
            }
        }
        return idx;
    }
}

