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

kscpremise_KList kscpremise_k_pushed(slop_arena* arena, slop_option_kscpremise_KList found, types_KscAxiom ax) {
    {
        __auto_type items = ({ __auto_type _mv = found; _mv.has_value ? ({ __auto_type l = _mv.value; l.items; }) : (((slop_list_types_KscAxiom){ .data = NULL, .len = 0, .cap = 0 })); });
        ({ __auto_type _lst_p = &(items); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((kscpremise_KList){.items = items});
    }
}

uint8_t kscpremise_k_partnered(slop_arena* arena, slop_map* m, types_KTerm key, types_KTerm other, types_KscAxiom ax) {
    {
        __auto_type p = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(m, &(key)); _ptr ? (slop_option_kscpremise_KPartners){ .has_value = true, .value = *(kscpremise_KPartners*)_ptr } : (slop_option_kscpremise_KPartners){ .has_value = false }; }); _mv.has_value ? ({ __auto_type q = _mv.value; q; }) : (((kscpremise_KPartners){.by_other = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KTerm, slop_hash_types_KTerm, slop_eq_types_KTerm, SLOP_KEY_HASHED, kscpremise_KList); slop_map_new_ptr(arena, 0, &_d); }), .count = 0})); });
        __auto_type prior = ({ void* _ptr = slop_map_get(p.by_other, &(other)); _ptr ? (slop_option_kscpremise_KList){ .has_value = true, .value = *(kscpremise_KList*)_ptr } : (slop_option_kscpremise_KList){ .has_value = false }; });
        __auto_type l = kscpremise_k_pushed(arena, prior, ax);
        ({ kscpremise_KList _val = l; slop_map_put(arena, p.by_other, &(other), &_val, sizeof(_val)); });
        ({ kscpremise_KPartners _val = ((kscpremise_KPartners){.by_other = p.by_other, .count = ({ __auto_type _mv = prior; _mv.has_value ? ({ __auto_type _ = _mv.value; p.count; }) : ((p.count + 1)); })}); slop_map_put(arena, m, &(key), &_val, sizeof(_val)); });
        return 1;
    }
}

uint8_t kscpremise_r_partnered(slop_arena* arena, slop_map* m, types_RoleId key, types_KTerm other, types_KscAxiom ax) {
    {
        __auto_type p = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(m, &(key)); _ptr ? (slop_option_kscpremise_KPartners){ .has_value = true, .value = *(kscpremise_KPartners*)_ptr } : (slop_option_kscpremise_KPartners){ .has_value = false }; }); _mv.has_value ? ({ __auto_type q = _mv.value; q; }) : (((kscpremise_KPartners){.by_other = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KTerm, slop_hash_types_KTerm, slop_eq_types_KTerm, SLOP_KEY_HASHED, kscpremise_KList); slop_map_new_ptr(arena, 0, &_d); }), .count = 0})); });
        __auto_type prior = ({ void* _ptr = slop_map_get(p.by_other, &(other)); _ptr ? (slop_option_kscpremise_KList){ .has_value = true, .value = *(kscpremise_KList*)_ptr } : (slop_option_kscpremise_KList){ .has_value = false }; });
        __auto_type l = kscpremise_k_pushed(arena, prior, ax);
        ({ kscpremise_KList _val = l; slop_map_put(arena, p.by_other, &(other), &_val, sizeof(_val)); });
        ({ kscpremise_KPartners _val = ((kscpremise_KPartners){.by_other = p.by_other, .count = ({ __auto_type _mv = prior; _mv.has_value ? ({ __auto_type _ = _mv.value; p.count; }) : ((p.count + 1)); })}); slop_map_put(arena, m, &(key), &_val, sizeof(_val)); });
        return 1;
    }
}

uint8_t kscpremise_file_term(slop_arena* arena, slop_map* m, types_KTerm y, types_KscAxiom ax) {
    {
        __auto_type l = kscpremise_k_pushed(arena, ({ void* _ptr = slop_map_get(m, &(y)); _ptr ? (slop_option_kscpremise_KList){ .has_value = true, .value = *(kscpremise_KList*)_ptr } : (slop_option_kscpremise_KList){ .has_value = false }; }), ax);
        ({ kscpremise_KList _val = l; slop_map_put(arena, m, &(y), &_val, sizeof(_val)); });
        return 1;
    }
}

uint8_t kscpremise_file_role(slop_arena* arena, slop_map* m, types_RoleId v, types_KscAxiom ax) {
    {
        __auto_type l = kscpremise_k_pushed(arena, ({ void* _ptr = slop_map_get(m, &(v)); _ptr ? (slop_option_kscpremise_KList){ .has_value = true, .value = *(kscpremise_KList*)_ptr } : (slop_option_kscpremise_KList){ .has_value = false }; }), ax);
        ({ kscpremise_KList _val = l; slop_map_put(arena, m, &(v), &_val, sizeof(_val)); });
        return 1;
    }
}

uint8_t kscpremise_first_mention(slop_arena* arena, slop_map* seen, rdf_IRI a) {
    if (slop_map_has(seen, &(a))) {
        return 0;
    } else {
        ({ slop_map_put(arena, seen, &(a), NULL, 0); });
        return 1;
    }
}

slop_option_rdf_IRI kscpremise_term_individual(types_KTerm t) {
    __auto_type _mv_472 = t;
    switch (_mv_472.tag) {
        case types_KTerm_k_nominal:
        {
            __auto_type a = _mv_472.data.k_nominal;
            return (slop_option_rdf_IRI){.has_value = 1, .value = a};
        }
        case types_KTerm_k_name:
        {
            __auto_type _ = _mv_472.data.k_name;
            return (slop_option_rdf_IRI){.has_value = false};
        }
    }
    SLOP_UNREACHABLE();
}

kscpremise_KscIndex kscpremise_build_ksc_index(slop_arena* arena, slop_list_types_KscAxiom axioms) {
    {
        __auto_type on_term = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KTerm, slop_hash_types_KTerm, slop_eq_types_KTerm, SLOP_KEY_HASHED, kscpremise_KList); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type on_role = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, kscpremise_KList); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type and_pairs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KTerm, slop_hash_types_KTerm, slop_eq_types_KTerm, SLOP_KEY_HASHED, kscpremise_KPartners); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type ex_by_role = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, kscpremise_KPartners); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type nis = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_473 = ax;
                switch (_mv_473.tag) {
                    case types_KscAxiom_k_sub:
                    {
                        __auto_type y = _mv_473.data.k_sub.f0;
                        __auto_type z = _mv_473.data.k_sub.f1;
                        kscpremise_file_term(arena, on_term, y, ax);
                        __auto_type _mv_474 = kscpremise_term_individual(y);
                        if (_mv_474.has_value) {
                            __auto_type a = _mv_474.value;
                            if (kscpremise_first_mention(arena, seen, a)) {
                                ({ __auto_type _lst_p = &(nis); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        } else if (!_mv_474.has_value) {
                        }
                        __auto_type _mv_475 = kscpremise_term_individual(z);
                        if (_mv_475.has_value) {
                            __auto_type a = _mv_475.value;
                            if (kscpremise_first_mention(arena, seen, a)) {
                                ({ __auto_type _lst_p = &(nis); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        } else if (!_mv_475.has_value) {
                        }
                        break;
                    }
                    case types_KscAxiom_k_and:
                    {
                        __auto_type a = _mv_473.data.k_and.f0;
                        __auto_type b = _mv_473.data.k_and.f1;
                        kscpremise_k_partnered(arena, and_pairs, types_name_term(a), types_name_term(b), ax);
                        if (!(types_kname_eq(a, b))) {
                            kscpremise_k_partnered(arena, and_pairs, types_name_term(b), types_name_term(a), ax);
                        }
                        break;
                    }
                    case types_KscAxiom_k_some_lhs:
                    {
                        __auto_type v = _mv_473.data.k_some_lhs.f0;
                        __auto_type a = _mv_473.data.k_some_lhs.f1;
                        kscpremise_file_term(arena, on_term, types_name_term(a), ax);
                        kscpremise_r_partnered(arena, ex_by_role, v, types_name_term(a), ax);
                        break;
                    }
                    case types_KscAxiom_k_some_rhs:
                    {
                        __auto_type a = _mv_473.data.k_some_rhs.f0;
                        kscpremise_file_term(arena, on_term, types_name_term(a), ax);
                        break;
                    }
                    case types_KscAxiom_k_self_lhs:
                    {
                        __auto_type v = _mv_473.data.k_self_lhs.f0;
                        kscpremise_file_role(arena, on_role, v, ax);
                        break;
                    }
                    case types_KscAxiom_k_self_rhs:
                    {
                        __auto_type a = _mv_473.data.k_self_rhs.f0;
                        kscpremise_file_term(arena, on_term, types_name_term(a), ax);
                        break;
                    }
                    case types_KscAxiom_k_role:
                    {
                        __auto_type v = _mv_473.data.k_role.f0;
                        kscpremise_file_role(arena, on_role, v, ax);
                        break;
                    }
                    case types_KscAxiom_k_chain:
                    {
                        __auto_type u = _mv_473.data.k_chain.f0;
                        __auto_type v = _mv_473.data.k_chain.f1;
                        kscpremise_file_role(arena, on_role, u, ax);
                        if (!(types_role_eq(u, v))) {
                            kscpremise_file_role(arena, on_role, v, ax);
                        }
                        break;
                    }
                    case types_KscAxiom_k_range:
                    {
                        __auto_type v = _mv_473.data.k_range.f0;
                        kscpremise_file_role(arena, on_role, v, ax);
                        break;
                    }
                    case types_KscAxiom_k_role_assert:
                    {
                        __auto_type a = _mv_473.data.k_role_assert.f0;
                        __auto_type b = _mv_473.data.k_role_assert.f2;
                        kscpremise_file_term(arena, on_term, types_nominal_term(a), ax);
                        if (kscpremise_first_mention(arena, seen, a)) {
                            ({ __auto_type _lst_p = &(nis); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        if (kscpremise_first_mention(arena, seen, b)) {
                            ({ __auto_type _lst_p = &(nis); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        break;
                    }
                }
            }
        }
        return ((kscpremise_KscIndex){.on_term = on_term, .on_role = on_role, .and_pairs = and_pairs, .ex_by_role = ex_by_role, .individuals = nis});
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

