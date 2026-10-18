#include "../runtime/slop_runtime.h"
#include "slop_premise.h"

howl_premise_AxList howl_premise_pushed(slop_arena* arena, slop_option_howl_premise_AxList found, howl_types_NormAxiom ax);
howl_premise_Partners howl_premise_partnered(slop_arena* arena, slop_option_howl_premise_Partners found, howl_types_Node other, howl_types_NormAxiom ax);
howl_premise_RoleList howl_premise_role_pushed(slop_arena* arena, slop_option_howl_premise_RoleList found, howl_types_RoleId r);
slop_list_howl_types_RoleId howl_premise_axiom_roles(slop_arena* arena, howl_types_NormAxiom ax);
howl_premise_RoleList howl_premise_role_closure(slop_arena* arena, howl_premise_RoleGraph g, howl_types_RoleId r);
howl_premise_RuleIndex howl_premise_build_rule_index(slop_arena* arena, slop_list_howl_types_NormAxiom axioms);

howl_premise_AxList howl_premise_pushed(slop_arena* arena, slop_option_howl_premise_AxList found, howl_types_NormAxiom ax) {
    {
        __auto_type items = ({ __auto_type _mv = found; _mv.has_value ? ({ __auto_type l = _mv.value; l.items; }) : (((slop_list_howl_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena })); });
        (void)(({ __auto_type _lst_p = &(items); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return ((howl_premise_AxList){.items = items});
    }
}

howl_premise_Partners howl_premise_partnered(slop_arena* arena, slop_option_howl_premise_Partners found, howl_types_Node other, howl_types_NormAxiom ax) {
    {
        __auto_type p = ({ __auto_type _mv = found; _mv.has_value ? ({ __auto_type q = _mv.value; q; }) : (((howl_premise_Partners){.by_other = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_Node, slop_hash_howl_types_Node, slop_eq_howl_types_Node, SLOP_KEY_HASHED, howl_premise_AxList); slop_map_new_ptr(arena, 0, &_d); }), .count = 0})); });
        __auto_type prior = ({ void* _ptr = slop_map_get(p.by_other, &(other)); _ptr ? (slop_option_howl_premise_AxList){ .has_value = true, .value = *(howl_premise_AxList*)_ptr } : (slop_option_howl_premise_AxList){ .has_value = false }; });
        __auto_type l = howl_premise_pushed(arena, prior, ax);
        (void)(({ howl_premise_AxList _val = l; slop_map_put(NULL, p.by_other, &(other), &_val, sizeof(_val)); }));
        return ((howl_premise_Partners){.by_other = p.by_other, .count = ({ __auto_type _mv = prior; _mv.has_value ? ({ __auto_type _ = _mv.value; p.count; }) : ((p.count + 1)); })});
    }
}

howl_premise_RoleList howl_premise_role_pushed(slop_arena* arena, slop_option_howl_premise_RoleList found, howl_types_RoleId r) {
    {
        __auto_type items = ({ __auto_type _mv = found; _mv.has_value ? ({ __auto_type l = _mv.value; l.items; }) : (((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena })); });
        (void)(({ __auto_type _lst_p = &(items); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return ((howl_premise_RoleList){.items = items});
    }
}

slop_list_howl_types_RoleId howl_premise_axiom_roles(slop_arena* arena, howl_types_NormAxiom ax) {
    {
        __auto_type rs = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_518 = ax;
        switch (_mv_518.tag) {
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
                __auto_type r = _mv_518.data.sub_some_rhs.f1;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_NormAxiom_sub_some_lhs:
            {
                __auto_type r = _mv_518.data.sub_some_lhs.f0;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_NormAxiom_sub_role:
            {
                __auto_type r = _mv_518.data.sub_role.f0;
                __auto_type s = _mv_518.data.sub_role.f1;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_NormAxiom_role_chain:
            {
                __auto_type r = _mv_518.data.role_chain.f0;
                __auto_type s = _mv_518.data.role_chain.f1;
                __auto_type t = _mv_518.data.role_chain.f2;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
        }
        return rs;
    }
}

howl_premise_RoleList howl_premise_role_closure(slop_arena* arena, howl_premise_RoleGraph g, howl_types_RoleId r) {
    {
        __auto_type out = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(howl_types_RoleId, slop_hash_howl_types_RoleId, slop_eq_howl_types_RoleId, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        int64_t i = 0;
        (void)(({ slop_map_put(NULL, seen, &(r), NULL, 0); }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        while (i < ((int64_t)(((int64_t)((out).len))))) {
            __auto_type _mv_520 = ({ __auto_type _lst = out; size_t _idx = (size_t)i; slop_option_howl_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_520.has_value) {
                __auto_type q = _mv_520.value;
                __auto_type _mv_522 = ({ void* _ptr = slop_map_get(g.up, &(q)); _ptr ? (slop_option_howl_premise_RoleList){ .has_value = true, .value = *(howl_premise_RoleList*)_ptr } : (slop_option_howl_premise_RoleList){ .has_value = false }; });
                if (_mv_522.has_value) {
                    __auto_type l = _mv_522.value;
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
                } else if (!_mv_522.has_value) {
                }
            } else if (!_mv_520.has_value) {
            }
            i = (i + 1);
        }
        return ((howl_premise_RoleList){.items = out});
    }
}

howl_premise_RuleIndex howl_premise_build_rule_index(slop_arena* arena, slop_list_howl_types_NormAxiom axioms) {
    {
        __auto_type idx = ((howl_premise_RuleIndex){.sub_by_lhs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_Node, slop_hash_howl_types_Node, slop_eq_howl_types_Node, SLOP_KEY_HASHED, howl_premise_AxList); slop_map_new_ptr(arena, 0, &_d); }), .and_by_pair = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_Node, slop_hash_howl_types_Node, slop_eq_howl_types_Node, SLOP_KEY_HASHED, howl_premise_Partners); slop_map_new_ptr(arena, 0, &_d); }), .rhs_by_lhs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_Node, slop_hash_howl_types_Node, slop_eq_howl_types_Node, SLOP_KEY_HASHED, howl_premise_AxList); slop_map_new_ptr(arena, 0, &_d); }), .lhs_by_filler = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_Node, slop_hash_howl_types_Node, slop_eq_howl_types_Node, SLOP_KEY_HASHED, howl_premise_AxList); slop_map_new_ptr(arena, 0, &_d); }), .lhs_by_role = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_RoleId, slop_hash_howl_types_RoleId, slop_eq_howl_types_RoleId, SLOP_KEY_HASHED, howl_premise_Partners); slop_map_new_ptr(arena, 0, &_d); }), .chain_by_first = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_RoleId, slop_hash_howl_types_RoleId, slop_eq_howl_types_RoleId, SLOP_KEY_HASHED, howl_premise_AxList); slop_map_new_ptr(arena, 0, &_d); }), .chain_by_second = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_RoleId, slop_hash_howl_types_RoleId, slop_eq_howl_types_RoleId, SLOP_KEY_HASHED, howl_premise_AxList); slop_map_new_ptr(arena, 0, &_d); }), .roles = ((howl_premise_RoleClosure){.sups = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_RoleId, slop_hash_howl_types_RoleId, slop_eq_howl_types_RoleId, SLOP_KEY_HASHED, howl_premise_RoleList); slop_map_new_ptr(arena, 0, &_d); }), .subs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_RoleId, slop_hash_howl_types_RoleId, slop_eq_howl_types_RoleId, SLOP_KEY_HASHED, howl_premise_RoleList); slop_map_new_ptr(arena, 0, &_d); })})});
        __auto_type g = ((howl_premise_RoleGraph){.up = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_RoleId, slop_hash_howl_types_RoleId, slop_eq_howl_types_RoleId, SLOP_KEY_HASHED, howl_premise_RoleList); slop_map_new_ptr(arena, 0, &_d); })});
        __auto_type roles = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(howl_types_RoleId, slop_hash_howl_types_RoleId, slop_eq_howl_types_RoleId, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_525 = ax;
                switch (_mv_525.tag) {
                    case howl_types_NormAxiom_sub_name:
                    {
                        __auto_type b = _mv_525.data.sub_name.f0;
                        {
                            __auto_type l = howl_premise_pushed(arena, ({ void* _ptr = slop_map_get(idx.sub_by_lhs, &(b)); _ptr ? (slop_option_howl_premise_AxList){ .has_value = true, .value = *(howl_premise_AxList*)_ptr } : (slop_option_howl_premise_AxList){ .has_value = false }; }), ax);
                            ({ howl_premise_AxList _val = l; slop_map_put(NULL, idx.sub_by_lhs, &(b), &_val, sizeof(_val)); });
                        }
                        break;
                    }
                    case howl_types_NormAxiom_sub_and:
                    {
                        __auto_type b1 = _mv_525.data.sub_and.f0;
                        __auto_type b2 = _mv_525.data.sub_and.f1;
                        {
                            __auto_type p1 = howl_premise_partnered(arena, ({ void* _ptr = slop_map_get(idx.and_by_pair, &(b1)); _ptr ? (slop_option_howl_premise_Partners){ .has_value = true, .value = *(howl_premise_Partners*)_ptr } : (slop_option_howl_premise_Partners){ .has_value = false }; }), b2, ax);
                            ({ howl_premise_Partners _val = p1; slop_map_put(NULL, idx.and_by_pair, &(b1), &_val, sizeof(_val)); });
                        }
                        if (!(howl_types_node_eq(b1, b2))) {
                            {
                                __auto_type p2 = howl_premise_partnered(arena, ({ void* _ptr = slop_map_get(idx.and_by_pair, &(b2)); _ptr ? (slop_option_howl_premise_Partners){ .has_value = true, .value = *(howl_premise_Partners*)_ptr } : (slop_option_howl_premise_Partners){ .has_value = false }; }), b1, ax);
                                ({ howl_premise_Partners _val = p2; slop_map_put(NULL, idx.and_by_pair, &(b2), &_val, sizeof(_val)); });
                            }
                        }
                        break;
                    }
                    case howl_types_NormAxiom_sub_some_rhs:
                    {
                        __auto_type b = _mv_525.data.sub_some_rhs.f0;
                        {
                            __auto_type l = howl_premise_pushed(arena, ({ void* _ptr = slop_map_get(idx.rhs_by_lhs, &(b)); _ptr ? (slop_option_howl_premise_AxList){ .has_value = true, .value = *(howl_premise_AxList*)_ptr } : (slop_option_howl_premise_AxList){ .has_value = false }; }), ax);
                            ({ howl_premise_AxList _val = l; slop_map_put(NULL, idx.rhs_by_lhs, &(b), &_val, sizeof(_val)); });
                        }
                        break;
                    }
                    case howl_types_NormAxiom_sub_some_lhs:
                    {
                        __auto_type r = _mv_525.data.sub_some_lhs.f0;
                        __auto_type b = _mv_525.data.sub_some_lhs.f1;
                        {
                            __auto_type l = howl_premise_pushed(arena, ({ void* _ptr = slop_map_get(idx.lhs_by_filler, &(b)); _ptr ? (slop_option_howl_premise_AxList){ .has_value = true, .value = *(howl_premise_AxList*)_ptr } : (slop_option_howl_premise_AxList){ .has_value = false }; }), ax);
                            ({ howl_premise_AxList _val = l; slop_map_put(NULL, idx.lhs_by_filler, &(b), &_val, sizeof(_val)); });
                        }
                        {
                            __auto_type p = howl_premise_partnered(arena, ({ void* _ptr = slop_map_get(idx.lhs_by_role, &(r)); _ptr ? (slop_option_howl_premise_Partners){ .has_value = true, .value = *(howl_premise_Partners*)_ptr } : (slop_option_howl_premise_Partners){ .has_value = false }; }), b, ax);
                            ({ howl_premise_Partners _val = p; slop_map_put(NULL, idx.lhs_by_role, &(r), &_val, sizeof(_val)); });
                        }
                        break;
                    }
                    case howl_types_NormAxiom_sub_role:
                    {
                        __auto_type r = _mv_525.data.sub_role.f0;
                        __auto_type s = _mv_525.data.sub_role.f1;
                        {
                            __auto_type l = howl_premise_role_pushed(arena, ({ void* _ptr = slop_map_get(g.up, &(r)); _ptr ? (slop_option_howl_premise_RoleList){ .has_value = true, .value = *(howl_premise_RoleList*)_ptr } : (slop_option_howl_premise_RoleList){ .has_value = false }; }), s);
                            ({ howl_premise_RoleList _val = l; slop_map_put(NULL, g.up, &(r), &_val, sizeof(_val)); });
                        }
                        break;
                    }
                    case howl_types_NormAxiom_role_chain:
                    {
                        __auto_type r = _mv_525.data.role_chain.f0;
                        __auto_type s = _mv_525.data.role_chain.f1;
                        {
                            __auto_type l1 = howl_premise_pushed(arena, ({ void* _ptr = slop_map_get(idx.chain_by_first, &(r)); _ptr ? (slop_option_howl_premise_AxList){ .has_value = true, .value = *(howl_premise_AxList*)_ptr } : (slop_option_howl_premise_AxList){ .has_value = false }; }), ax);
                            ({ howl_premise_AxList _val = l1; slop_map_put(NULL, idx.chain_by_first, &(r), &_val, sizeof(_val)); });
                        }
                        {
                            __auto_type l2 = howl_premise_pushed(arena, ({ void* _ptr = slop_map_get(idx.chain_by_second, &(s)); _ptr ? (slop_option_howl_premise_AxList){ .has_value = true, .value = *(howl_premise_AxList*)_ptr } : (slop_option_howl_premise_AxList){ .has_value = false }; }), ax);
                            ({ howl_premise_AxList _val = l2; slop_map_put(NULL, idx.chain_by_second, &(s), &_val, sizeof(_val)); });
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
                    __auto_type c = howl_premise_role_closure(arena, g, r);
                    (void)(({ howl_premise_RoleList _val = c; slop_map_put(NULL, idx.roles.sups, &(r), &_val, sizeof(_val)); }));
                }
            }
        }
        {
            __auto_type _coll = roles;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                __auto_type _mv_548 = ({ void* _ptr = slop_map_get(idx.roles.sups, &(r)); _ptr ? (slop_option_howl_premise_RoleList){ .has_value = true, .value = *(howl_premise_RoleList*)_ptr } : (slop_option_howl_premise_RoleList){ .has_value = false }; });
                if (_mv_548.has_value) {
                    __auto_type c = _mv_548.value;
                    {
                        __auto_type _coll = c.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type s = _coll.data[_i];
                            {
                                __auto_type l = howl_premise_role_pushed(arena, ({ void* _ptr = slop_map_get(idx.roles.subs, &(s)); _ptr ? (slop_option_howl_premise_RoleList){ .has_value = true, .value = *(howl_premise_RoleList*)_ptr } : (slop_option_howl_premise_RoleList){ .has_value = false }; }), r);
                                ({ howl_premise_RoleList _val = l; slop_map_put(NULL, idx.roles.subs, &(s), &_val, sizeof(_val)); });
                            }
                        }
                    }
                } else if (!_mv_548.has_value) {
                }
            }
        }
        return idx;
    }
}

