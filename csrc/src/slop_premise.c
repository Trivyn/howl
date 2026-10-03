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
        __auto_type items = ({ __auto_type _mv = found; _mv.has_value ? ({ __auto_type l = _mv.value; l.items; }) : (((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena })); });
        ({ __auto_type _lst_p = &(items); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((premise_AxList){.items = items});
    }
}

premise_Partners premise_partnered(slop_arena* arena, slop_option_premise_Partners found, types_Node other, types_NormAxiom ax) {
    {
        __auto_type p = ({ __auto_type _mv = found; _mv.has_value ? ({ __auto_type q = _mv.value; q; }) : (((premise_Partners){.by_other = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, premise_AxList); slop_map_new_ptr(arena, 0, &_d); }), .count = 0})); });
        __auto_type prior = ({ void* _ptr = slop_map_get(p.by_other, &(other)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; });
        __auto_type l = premise_pushed(arena, prior, ax);
        ({ premise_AxList _val = l; slop_map_put(NULL, p.by_other, &(other), &_val, sizeof(_val)); });
        return ((premise_Partners){.by_other = p.by_other, .count = ({ __auto_type _mv = prior; _mv.has_value ? ({ __auto_type _ = _mv.value; p.count; }) : ((p.count + 1)); })});
    }
}

premise_RoleList premise_role_pushed(slop_arena* arena, slop_option_premise_RoleList found, types_RoleId r) {
    {
        __auto_type items = ({ __auto_type _mv = found; _mv.has_value ? ({ __auto_type l = _mv.value; l.items; }) : (((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena })); });
        ({ __auto_type _lst_p = &(items); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((premise_RoleList){.items = items});
    }
}

slop_list_types_RoleId premise_axiom_roles(slop_arena* arena, types_NormAxiom ax) {
    {
        __auto_type rs = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_139 = ax;
        switch (_mv_139.tag) {
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
                __auto_type r = _mv_139.data.sub_some_rhs.f1;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_NormAxiom_sub_some_lhs:
            {
                __auto_type r = _mv_139.data.sub_some_lhs.f0;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_NormAxiom_sub_role:
            {
                __auto_type r = _mv_139.data.sub_role.f0;
                __auto_type s = _mv_139.data.sub_role.f1;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_NormAxiom_role_chain:
            {
                __auto_type r = _mv_139.data.role_chain.f0;
                __auto_type s = _mv_139.data.role_chain.f1;
                __auto_type t = _mv_139.data.role_chain.f2;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
        }
        return rs;
    }
}

premise_RoleList premise_role_closure(slop_arena* arena, premise_RoleGraph g, types_RoleId r) {
    {
        __auto_type out = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        int64_t i = 0;
        ({ slop_map_put(NULL, seen, &(r), NULL, 0); });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        while (i < ((int64_t)(((int64_t)((out).len))))) {
            __auto_type _mv_141 = ({ __auto_type _lst = out; size_t _idx = (size_t)i; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_141.has_value) {
                __auto_type q = _mv_141.value;
                __auto_type _mv_143 = ({ void* _ptr = slop_map_get(g.up, &(q)); _ptr ? (slop_option_premise_RoleList){ .has_value = true, .value = *(premise_RoleList*)_ptr } : (slop_option_premise_RoleList){ .has_value = false }; });
                if (_mv_143.has_value) {
                    __auto_type l = _mv_143.value;
                    {
                        __auto_type _coll = l.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type s = _coll.data[_i];
                            if (!(slop_map_has(seen, &(s)))) {
                                ({ slop_map_put(NULL, seen, &(s), NULL, 0); });
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                } else if (!_mv_143.has_value) {
                }
            } else if (!_mv_141.has_value) {
            }
            i = (i + 1);
        }
        return ((premise_RoleList){.items = out});
    }
}

premise_RuleIndex premise_build_rule_index(slop_arena* arena, slop_list_types_NormAxiom axioms) {
    {
        __auto_type idx = ((premise_RuleIndex){.sub_by_lhs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, premise_AxList); slop_map_new_ptr(arena, 0, &_d); }), .and_by_pair = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, premise_Partners); slop_map_new_ptr(arena, 0, &_d); }), .rhs_by_lhs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, premise_AxList); slop_map_new_ptr(arena, 0, &_d); }), .lhs_by_filler = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, premise_AxList); slop_map_new_ptr(arena, 0, &_d); }), .lhs_by_role = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, premise_Partners); slop_map_new_ptr(arena, 0, &_d); }), .chain_by_first = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, premise_AxList); slop_map_new_ptr(arena, 0, &_d); }), .chain_by_second = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, premise_AxList); slop_map_new_ptr(arena, 0, &_d); }), .roles = ((premise_RoleClosure){.sups = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, premise_RoleList); slop_map_new_ptr(arena, 0, &_d); }), .subs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, premise_RoleList); slop_map_new_ptr(arena, 0, &_d); })})});
        __auto_type g = ((premise_RoleGraph){.up = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, premise_RoleList); slop_map_new_ptr(arena, 0, &_d); })});
        __auto_type roles = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_146 = ax;
                switch (_mv_146.tag) {
                    case types_NormAxiom_sub_name:
                    {
                        __auto_type b = _mv_146.data.sub_name.f0;
                        {
                            __auto_type l = premise_pushed(arena, ({ void* _ptr = slop_map_get(idx.sub_by_lhs, &(b)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; }), ax);
                            ({ premise_AxList _val = l; slop_map_put(NULL, idx.sub_by_lhs, &(b), &_val, sizeof(_val)); });
                        }
                        break;
                    }
                    case types_NormAxiom_sub_and:
                    {
                        __auto_type b1 = _mv_146.data.sub_and.f0;
                        __auto_type b2 = _mv_146.data.sub_and.f1;
                        {
                            __auto_type p1 = premise_partnered(arena, ({ void* _ptr = slop_map_get(idx.and_by_pair, &(b1)); _ptr ? (slop_option_premise_Partners){ .has_value = true, .value = *(premise_Partners*)_ptr } : (slop_option_premise_Partners){ .has_value = false }; }), b2, ax);
                            ({ premise_Partners _val = p1; slop_map_put(NULL, idx.and_by_pair, &(b1), &_val, sizeof(_val)); });
                        }
                        if (!(types_node_eq(b1, b2))) {
                            {
                                __auto_type p2 = premise_partnered(arena, ({ void* _ptr = slop_map_get(idx.and_by_pair, &(b2)); _ptr ? (slop_option_premise_Partners){ .has_value = true, .value = *(premise_Partners*)_ptr } : (slop_option_premise_Partners){ .has_value = false }; }), b1, ax);
                                ({ premise_Partners _val = p2; slop_map_put(NULL, idx.and_by_pair, &(b2), &_val, sizeof(_val)); });
                            }
                        }
                        break;
                    }
                    case types_NormAxiom_sub_some_rhs:
                    {
                        __auto_type b = _mv_146.data.sub_some_rhs.f0;
                        {
                            __auto_type l = premise_pushed(arena, ({ void* _ptr = slop_map_get(idx.rhs_by_lhs, &(b)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; }), ax);
                            ({ premise_AxList _val = l; slop_map_put(NULL, idx.rhs_by_lhs, &(b), &_val, sizeof(_val)); });
                        }
                        break;
                    }
                    case types_NormAxiom_sub_some_lhs:
                    {
                        __auto_type r = _mv_146.data.sub_some_lhs.f0;
                        __auto_type b = _mv_146.data.sub_some_lhs.f1;
                        {
                            __auto_type l = premise_pushed(arena, ({ void* _ptr = slop_map_get(idx.lhs_by_filler, &(b)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; }), ax);
                            ({ premise_AxList _val = l; slop_map_put(NULL, idx.lhs_by_filler, &(b), &_val, sizeof(_val)); });
                        }
                        {
                            __auto_type p = premise_partnered(arena, ({ void* _ptr = slop_map_get(idx.lhs_by_role, &(r)); _ptr ? (slop_option_premise_Partners){ .has_value = true, .value = *(premise_Partners*)_ptr } : (slop_option_premise_Partners){ .has_value = false }; }), b, ax);
                            ({ premise_Partners _val = p; slop_map_put(NULL, idx.lhs_by_role, &(r), &_val, sizeof(_val)); });
                        }
                        break;
                    }
                    case types_NormAxiom_sub_role:
                    {
                        __auto_type r = _mv_146.data.sub_role.f0;
                        __auto_type s = _mv_146.data.sub_role.f1;
                        {
                            __auto_type l = premise_role_pushed(arena, ({ void* _ptr = slop_map_get(g.up, &(r)); _ptr ? (slop_option_premise_RoleList){ .has_value = true, .value = *(premise_RoleList*)_ptr } : (slop_option_premise_RoleList){ .has_value = false }; }), s);
                            ({ premise_RoleList _val = l; slop_map_put(NULL, g.up, &(r), &_val, sizeof(_val)); });
                        }
                        break;
                    }
                    case types_NormAxiom_role_chain:
                    {
                        __auto_type r = _mv_146.data.role_chain.f0;
                        __auto_type s = _mv_146.data.role_chain.f1;
                        {
                            __auto_type l1 = premise_pushed(arena, ({ void* _ptr = slop_map_get(idx.chain_by_first, &(r)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; }), ax);
                            ({ premise_AxList _val = l1; slop_map_put(NULL, idx.chain_by_first, &(r), &_val, sizeof(_val)); });
                        }
                        {
                            __auto_type l2 = premise_pushed(arena, ({ void* _ptr = slop_map_get(idx.chain_by_second, &(s)); _ptr ? (slop_option_premise_AxList){ .has_value = true, .value = *(premise_AxList*)_ptr } : (slop_option_premise_AxList){ .has_value = false }; }), ax);
                            ({ premise_AxList _val = l2; slop_map_put(NULL, idx.chain_by_second, &(s), &_val, sizeof(_val)); });
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
                        if (!(slop_map_has(seen, &(r)))) {
                            ({ slop_map_put(NULL, seen, &(r), NULL, 0); });
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                    ({ premise_RoleList _val = c; slop_map_put(NULL, idx.roles.sups, &(r), &_val, sizeof(_val)); });
                }
            }
        }
        {
            __auto_type _coll = roles;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                __auto_type _mv_169 = ({ void* _ptr = slop_map_get(idx.roles.sups, &(r)); _ptr ? (slop_option_premise_RoleList){ .has_value = true, .value = *(premise_RoleList*)_ptr } : (slop_option_premise_RoleList){ .has_value = false }; });
                if (_mv_169.has_value) {
                    __auto_type c = _mv_169.value;
                    {
                        __auto_type _coll = c.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type s = _coll.data[_i];
                            {
                                __auto_type l = premise_role_pushed(arena, ({ void* _ptr = slop_map_get(idx.roles.subs, &(s)); _ptr ? (slop_option_premise_RoleList){ .has_value = true, .value = *(premise_RoleList*)_ptr } : (slop_option_premise_RoleList){ .has_value = false }; }), r);
                                ({ premise_RoleList _val = l; slop_map_put(NULL, idx.roles.subs, &(s), &_val, sizeof(_val)); });
                            }
                        }
                    }
                } else if (!_mv_169.has_value) {
                }
            }
        }
        return idx;
    }
}

