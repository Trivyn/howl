#include "../runtime/slop_runtime.h"
#include "slop_kscpremise.h"

kscpremise_KList kscpremise_k_pushed(slop_arena* arena, slop_option_kscpremise_KList found, types_KscAxiom ax);
uint8_t kscpremise_k_partnered(slop_arena* arena, slop_map* m, types_KTerm key, types_KTerm other, types_KscAxiom ax);
uint8_t kscpremise_r_partnered(slop_arena* arena, slop_map* m, types_RoleId key, types_KTerm other, types_KscAxiom ax);
uint8_t kscpremise_file_term(slop_arena* arena, slop_map* m, types_KTerm y, types_KscAxiom ax);
uint8_t kscpremise_file_role(slop_arena* arena, slop_map* m, types_RoleId v, types_KscAxiom ax);
uint8_t kscpremise_first_mention(slop_arena* arena, slop_map* seen, rdf_IRI a);
slop_option_rdf_IRI kscpremise_term_individual(types_KTerm t);
kscpremise_KscIndex kscpremise_build_ksc_index(slop_arena* arena, slop_list_types_KscAxiom axioms);
slop_option_kscpremise_KList kscpremise_term_bucket(kscpremise_KscIndex idx, types_KTerm y);
slop_option_kscpremise_KList kscpremise_role_bucket(kscpremise_KscIndex idx, types_RoleId v);
slop_option_kscpremise_KPartners kscpremise_and_partners(kscpremise_KscIndex idx, types_KTerm y);
slop_option_kscpremise_KPartners kscpremise_ex_partners(kscpremise_KscIndex idx, types_RoleId v);
kscpremise_RoleList kscpremise_role_pushed(slop_arena* arena, slop_option_kscpremise_RoleList found, types_RoleId r);
kscpremise_RoleList kscpremise_role_walk(slop_arena* arena, slop_map* edges, types_RoleId r);
slop_list_types_RoleId kscpremise_role_sups(slop_arena* arena, kscpremise_KscIndex idx, types_RoleId e);
slop_list_types_RoleId kscpremise_role_subs(slop_arena* arena, kscpremise_KscIndex idx, types_RoleId v);
uint8_t kscpremise_role_under(kscpremise_KscIndex idx, types_RoleId e, types_RoleId v);

kscpremise_KList kscpremise_k_pushed(slop_arena* arena, slop_option_kscpremise_KList found, types_KscAxiom ax) {
    {
        __auto_type items = ({ __auto_type _mv = found; _mv.has_value ? ({ __auto_type l = _mv.value; l.items; }) : (((slop_list_types_KscAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena })); });
        ({ __auto_type _lst_p = &(items); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((kscpremise_KList){.items = items});
    }
}

uint8_t kscpremise_k_partnered(slop_arena* arena, slop_map* m, types_KTerm key, types_KTerm other, types_KscAxiom ax) {
    {
        __auto_type p = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(m, &(key)); _ptr ? (slop_option_kscpremise_KPartners){ .has_value = true, .value = *(kscpremise_KPartners*)_ptr } : (slop_option_kscpremise_KPartners){ .has_value = false }; }); _mv.has_value ? ({ __auto_type q = _mv.value; q; }) : (((kscpremise_KPartners){.by_other = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KTerm, slop_hash_types_KTerm, slop_eq_types_KTerm, SLOP_KEY_HASHED, kscpremise_KList); slop_map_new_ptr(arena, 0, &_d); }), .count = 0})); });
        __auto_type prior = ({ void* _ptr = slop_map_get(p.by_other, &(other)); _ptr ? (slop_option_kscpremise_KList){ .has_value = true, .value = *(kscpremise_KList*)_ptr } : (slop_option_kscpremise_KList){ .has_value = false }; });
        __auto_type l = kscpremise_k_pushed(arena, prior, ax);
        ({ kscpremise_KList _val = l; slop_map_put(NULL, p.by_other, &(other), &_val, sizeof(_val)); });
        ({ kscpremise_KPartners _val = ((kscpremise_KPartners){.by_other = p.by_other, .count = ({ __auto_type _mv = prior; _mv.has_value ? ({ __auto_type _ = _mv.value; p.count; }) : ((p.count + 1)); })}); slop_map_put(NULL, m, &(key), &_val, sizeof(_val)); });
        return 1;
    }
}

uint8_t kscpremise_r_partnered(slop_arena* arena, slop_map* m, types_RoleId key, types_KTerm other, types_KscAxiom ax) {
    {
        __auto_type p = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(m, &(key)); _ptr ? (slop_option_kscpremise_KPartners){ .has_value = true, .value = *(kscpremise_KPartners*)_ptr } : (slop_option_kscpremise_KPartners){ .has_value = false }; }); _mv.has_value ? ({ __auto_type q = _mv.value; q; }) : (((kscpremise_KPartners){.by_other = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KTerm, slop_hash_types_KTerm, slop_eq_types_KTerm, SLOP_KEY_HASHED, kscpremise_KList); slop_map_new_ptr(arena, 0, &_d); }), .count = 0})); });
        __auto_type prior = ({ void* _ptr = slop_map_get(p.by_other, &(other)); _ptr ? (slop_option_kscpremise_KList){ .has_value = true, .value = *(kscpremise_KList*)_ptr } : (slop_option_kscpremise_KList){ .has_value = false }; });
        __auto_type l = kscpremise_k_pushed(arena, prior, ax);
        ({ kscpremise_KList _val = l; slop_map_put(NULL, p.by_other, &(other), &_val, sizeof(_val)); });
        ({ kscpremise_KPartners _val = ((kscpremise_KPartners){.by_other = p.by_other, .count = ({ __auto_type _mv = prior; _mv.has_value ? ({ __auto_type _ = _mv.value; p.count; }) : ((p.count + 1)); })}); slop_map_put(NULL, m, &(key), &_val, sizeof(_val)); });
        return 1;
    }
}

uint8_t kscpremise_file_term(slop_arena* arena, slop_map* m, types_KTerm y, types_KscAxiom ax) {
    {
        __auto_type l = kscpremise_k_pushed(arena, ({ void* _ptr = slop_map_get(m, &(y)); _ptr ? (slop_option_kscpremise_KList){ .has_value = true, .value = *(kscpremise_KList*)_ptr } : (slop_option_kscpremise_KList){ .has_value = false }; }), ax);
        ({ kscpremise_KList _val = l; slop_map_put(NULL, m, &(y), &_val, sizeof(_val)); });
        return 1;
    }
}

uint8_t kscpremise_file_role(slop_arena* arena, slop_map* m, types_RoleId v, types_KscAxiom ax) {
    {
        __auto_type l = kscpremise_k_pushed(arena, ({ void* _ptr = slop_map_get(m, &(v)); _ptr ? (slop_option_kscpremise_KList){ .has_value = true, .value = *(kscpremise_KList*)_ptr } : (slop_option_kscpremise_KList){ .has_value = false }; }), ax);
        ({ kscpremise_KList _val = l; slop_map_put(NULL, m, &(v), &_val, sizeof(_val)); });
        return 1;
    }
}

uint8_t kscpremise_first_mention(slop_arena* arena, slop_map* seen, rdf_IRI a) {
    if (slop_map_has(seen, &(a))) {
        return 0;
    } else {
        ({ slop_map_put(NULL, seen, &(a), NULL, 0); });
        return 1;
    }
}

slop_option_rdf_IRI kscpremise_term_individual(types_KTerm t) {
    __auto_type _mv_509 = t;
    switch (_mv_509.tag) {
        case types_KTerm_k_nominal:
        {
            __auto_type a = _mv_509.data.k_nominal;
            return (slop_option_rdf_IRI){.has_value = 1, .value = a};
        }
        case types_KTerm_k_name:
        {
            __auto_type _ = _mv_509.data.k_name;
            return (slop_option_rdf_IRI){.has_value = false};
        }
    }
    SLOP_UNREACHABLE();
}

kscpremise_KscIndex kscpremise_build_ksc_index(slop_arena* arena, slop_list_types_KscAxiom axioms) {
    {
        __auto_type up = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, kscpremise_RoleList); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type down = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, kscpremise_RoleList); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type sups = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, kscpremise_RoleList); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type subs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, kscpremise_RoleList); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type below = ({ static const slop_map_desc _d = SLOP_SET_DESC(kscpremise_RolePair, slop_hash_kscpremise_RolePair, slop_eq_kscpremise_RolePair, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type on_term = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KTerm, slop_hash_types_KTerm, slop_eq_types_KTerm, SLOP_KEY_HASHED, kscpremise_KList); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type on_role = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, kscpremise_KList); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type and_pairs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KTerm, slop_hash_types_KTerm, slop_eq_types_KTerm, SLOP_KEY_HASHED, kscpremise_KPartners); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type ex_by_role = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, kscpremise_KPartners); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type nis = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_510 = ax;
                switch (_mv_510.tag) {
                    case types_KscAxiom_k_sub:
                    {
                        __auto_type y = _mv_510.data.k_sub.f0;
                        __auto_type z = _mv_510.data.k_sub.f1;
                        kscpremise_file_term(arena, on_term, y, ax);
                        __auto_type _mv_511 = kscpremise_term_individual(y);
                        if (_mv_511.has_value) {
                            __auto_type a = _mv_511.value;
                            if (kscpremise_first_mention(arena, seen, a)) {
                                ({ __auto_type _lst_p = &(nis); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        } else if (!_mv_511.has_value) {
                        }
                        __auto_type _mv_512 = kscpremise_term_individual(z);
                        if (_mv_512.has_value) {
                            __auto_type a = _mv_512.value;
                            if (kscpremise_first_mention(arena, seen, a)) {
                                ({ __auto_type _lst_p = &(nis); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        } else if (!_mv_512.has_value) {
                        }
                        break;
                    }
                    case types_KscAxiom_k_and:
                    {
                        __auto_type a = _mv_510.data.k_and.f0;
                        __auto_type b = _mv_510.data.k_and.f1;
                        kscpremise_k_partnered(arena, and_pairs, types_name_term(a), types_name_term(b), ax);
                        if (!(types_kname_eq(a, b))) {
                            kscpremise_k_partnered(arena, and_pairs, types_name_term(b), types_name_term(a), ax);
                        }
                        break;
                    }
                    case types_KscAxiom_k_some_lhs:
                    {
                        __auto_type v = _mv_510.data.k_some_lhs.f0;
                        __auto_type a = _mv_510.data.k_some_lhs.f1;
                        kscpremise_file_term(arena, on_term, types_name_term(a), ax);
                        kscpremise_r_partnered(arena, ex_by_role, v, types_name_term(a), ax);
                        break;
                    }
                    case types_KscAxiom_k_some_rhs:
                    {
                        __auto_type a = _mv_510.data.k_some_rhs.f0;
                        kscpremise_file_term(arena, on_term, types_name_term(a), ax);
                        break;
                    }
                    case types_KscAxiom_k_self_lhs:
                    {
                        __auto_type v = _mv_510.data.k_self_lhs.f0;
                        kscpremise_file_role(arena, on_role, v, ax);
                        break;
                    }
                    case types_KscAxiom_k_self_rhs:
                    {
                        __auto_type a = _mv_510.data.k_self_rhs.f0;
                        kscpremise_file_term(arena, on_term, types_name_term(a), ax);
                        break;
                    }
                    case types_KscAxiom_k_role:
                    {
                        __auto_type v = _mv_510.data.k_role.f0;
                        __auto_type w = _mv_510.data.k_role.f1;
                        kscpremise_file_role(arena, on_role, v, ax);
                        {
                            __auto_type u = kscpremise_role_pushed(arena, ({ void* _ptr = slop_map_get(up, &(v)); _ptr ? (slop_option_kscpremise_RoleList){ .has_value = true, .value = *(kscpremise_RoleList*)_ptr } : (slop_option_kscpremise_RoleList){ .has_value = false }; }), w);
                            __auto_type d = kscpremise_role_pushed(arena, ({ void* _ptr = slop_map_get(down, &(w)); _ptr ? (slop_option_kscpremise_RoleList){ .has_value = true, .value = *(kscpremise_RoleList*)_ptr } : (slop_option_kscpremise_RoleList){ .has_value = false }; }), v);
                            ({ kscpremise_RoleList _val = u; slop_map_put(NULL, up, &(v), &_val, sizeof(_val)); });
                            ({ kscpremise_RoleList _val = d; slop_map_put(NULL, down, &(w), &_val, sizeof(_val)); });
                        }
                        break;
                    }
                    case types_KscAxiom_k_chain:
                    {
                        __auto_type u = _mv_510.data.k_chain.f0;
                        __auto_type v = _mv_510.data.k_chain.f1;
                        kscpremise_file_role(arena, on_role, u, ax);
                        if (!(types_role_eq(u, v))) {
                            kscpremise_file_role(arena, on_role, v, ax);
                        }
                        break;
                    }
                    case types_KscAxiom_k_range:
                    {
                        __auto_type v = _mv_510.data.k_range.f0;
                        kscpremise_file_role(arena, on_role, v, ax);
                        break;
                    }
                    case types_KscAxiom_k_role_assert:
                    {
                        __auto_type a = _mv_510.data.k_role_assert.f0;
                        __auto_type b = _mv_510.data.k_role_assert.f2;
                        kscpremise_file_term(arena, on_term, types_nominal_term(a), ax);
                        if (kscpremise_first_mention(arena, seen, a)) {
                            ({ __auto_type _lst_p = &(nis); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        if (kscpremise_first_mention(arena, seen, b)) {
                            ({ __auto_type _lst_p = &(nis); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                __auto_type _mv_517 = ax;
                switch (_mv_517.tag) {
                    case types_KscAxiom_k_role:
                    {
                        __auto_type v = _mv_517.data.k_role.f0;
                        __auto_type w = _mv_517.data.k_role.f1;
                        if (!(slop_map_has(sups, &(v)))) {
                            ({ kscpremise_RoleList _val = kscpremise_role_walk(arena, up, v); slop_map_put(NULL, sups, &(v), &_val, sizeof(_val)); });
                        }
                        if (!(slop_map_has(sups, &(w)))) {
                            ({ kscpremise_RoleList _val = kscpremise_role_walk(arena, up, w); slop_map_put(NULL, sups, &(w), &_val, sizeof(_val)); });
                        }
                        if (!(slop_map_has(subs, &(v)))) {
                            ({ kscpremise_RoleList _val = kscpremise_role_walk(arena, down, v); slop_map_put(NULL, subs, &(v), &_val, sizeof(_val)); });
                        }
                        if (!(slop_map_has(subs, &(w)))) {
                            ({ kscpremise_RoleList _val = kscpremise_role_walk(arena, down, w); slop_map_put(NULL, subs, &(w), &_val, sizeof(_val)); });
                        }
                        break;
                    }
                    case types_KscAxiom_k_sub:
                    {
                        break;
                    }
                    case types_KscAxiom_k_and:
                    {
                        break;
                    }
                    case types_KscAxiom_k_some_lhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_some_rhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_self_lhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_self_rhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_chain:
                    {
                        break;
                    }
                    case types_KscAxiom_k_range:
                    {
                        break;
                    }
                    case types_KscAxiom_k_role_assert:
                    {
                        break;
                    }
                }
            }
        }
        {
            slop_map* _coll = (slop_map*)subs;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    types_RoleId v = *(types_RoleId*)slop_map_key_at(_coll, _i);
                    kscpremise_RoleList l = *(kscpremise_RoleList*)slop_map_value_at(_coll, _i);
                    {
                        __auto_type _coll = l.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type e = _coll.data[_i];
                            if (!(types_role_eq(e, v))) {
                                ({ kscpremise_RolePair _key_526 = (((kscpremise_RolePair){.sub = e, .sup = v})); slop_map_put(NULL, below, &_key_526, NULL, 0); });
                            }
                        }
                    }
                }
            }
        }
        return ((kscpremise_KscIndex){.sups = sups, .subs = subs, .below = below, .on_term = on_term, .on_role = on_role, .and_pairs = and_pairs, .ex_by_role = ex_by_role, .individuals = nis});
    }
}

slop_option_kscpremise_KList kscpremise_term_bucket(kscpremise_KscIndex idx, types_KTerm y) {
    return ({ void* _ptr = slop_map_get(idx.on_term, &(y)); _ptr ? (slop_option_kscpremise_KList){ .has_value = true, .value = *(kscpremise_KList*)_ptr } : (slop_option_kscpremise_KList){ .has_value = false }; });
}

slop_option_kscpremise_KList kscpremise_role_bucket(kscpremise_KscIndex idx, types_RoleId v) {
    return ({ void* _ptr = slop_map_get(idx.on_role, &(v)); _ptr ? (slop_option_kscpremise_KList){ .has_value = true, .value = *(kscpremise_KList*)_ptr } : (slop_option_kscpremise_KList){ .has_value = false }; });
}

slop_option_kscpremise_KPartners kscpremise_and_partners(kscpremise_KscIndex idx, types_KTerm y) {
    return ({ void* _ptr = slop_map_get(idx.and_pairs, &(y)); _ptr ? (slop_option_kscpremise_KPartners){ .has_value = true, .value = *(kscpremise_KPartners*)_ptr } : (slop_option_kscpremise_KPartners){ .has_value = false }; });
}

slop_option_kscpremise_KPartners kscpremise_ex_partners(kscpremise_KscIndex idx, types_RoleId v) {
    return ({ void* _ptr = slop_map_get(idx.ex_by_role, &(v)); _ptr ? (slop_option_kscpremise_KPartners){ .has_value = true, .value = *(kscpremise_KPartners*)_ptr } : (slop_option_kscpremise_KPartners){ .has_value = false }; });
}

kscpremise_RoleList kscpremise_role_pushed(slop_arena* arena, slop_option_kscpremise_RoleList found, types_RoleId r) {
    {
        __auto_type items = ({ __auto_type _mv = found; _mv.has_value ? ({ __auto_type l = _mv.value; l.items; }) : (((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena })); });
        ({ __auto_type _lst_p = &(items); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((kscpremise_RoleList){.items = items});
    }
}

kscpremise_RoleList kscpremise_role_walk(slop_arena* arena, slop_map* edges, types_RoleId r) {
    {
        __auto_type out = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        int64_t i = 0;
        ({ slop_map_put(NULL, seen, &(r), NULL, 0); });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        while (i < ((int64_t)(((int64_t)((out).len))))) {
            __auto_type _mv_532 = ({ __auto_type _lst = out; size_t _idx = (size_t)i; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_532.has_value) {
                __auto_type q = _mv_532.value;
                __auto_type _mv_534 = ({ void* _ptr = slop_map_get(edges, &(q)); _ptr ? (slop_option_kscpremise_RoleList){ .has_value = true, .value = *(kscpremise_RoleList*)_ptr } : (slop_option_kscpremise_RoleList){ .has_value = false }; });
                if (_mv_534.has_value) {
                    __auto_type l = _mv_534.value;
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
                } else if (!_mv_534.has_value) {
                }
            } else if (!_mv_532.has_value) {
            }
            i = (i + 1);
        }
        return ((kscpremise_RoleList){.items = out});
    }
}

slop_list_types_RoleId kscpremise_role_sups(slop_arena* arena, kscpremise_KscIndex idx, types_RoleId e) {
    __auto_type _mv_538 = ({ void* _ptr = slop_map_get(idx.sups, &(e)); _ptr ? (slop_option_kscpremise_RoleList){ .has_value = true, .value = *(kscpremise_RoleList*)_ptr } : (slop_option_kscpremise_RoleList){ .has_value = false }; });
    if (_mv_538.has_value) {
        __auto_type l = _mv_538.value;
        return l.items;
    } else if (!_mv_538.has_value) {
        {
            __auto_type out = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            return out;
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_types_RoleId kscpremise_role_subs(slop_arena* arena, kscpremise_KscIndex idx, types_RoleId v) {
    __auto_type _mv_540 = ({ void* _ptr = slop_map_get(idx.subs, &(v)); _ptr ? (slop_option_kscpremise_RoleList){ .has_value = true, .value = *(kscpremise_RoleList*)_ptr } : (slop_option_kscpremise_RoleList){ .has_value = false }; });
    if (_mv_540.has_value) {
        __auto_type l = _mv_540.value;
        return l.items;
    } else if (!_mv_540.has_value) {
        {
            __auto_type out = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            return out;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t kscpremise_role_under(kscpremise_KscIndex idx, types_RoleId e, types_RoleId v) {
    if (types_role_eq(e, v)) {
        return 1;
    } else {
        return ({ kscpremise_RolePair _key_541 = (((kscpremise_RolePair){.sub = e, .sup = v})); slop_map_has(idx.below, &_key_541); });
    }
}

