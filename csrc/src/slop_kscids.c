#include "../runtime/slop_runtime.h"
#include "slop_kscids.h"

uint8_t kscids_inst_kind(void);
uint8_t kscids_triple_kind(void);
uint8_t kscids_self_kind(void);
int64_t kscids_max_n(int64_t k, int64_t tag);
uint8_t kscids_is_thing(rdf_IRI i);
uint8_t kscids_is_nothing(rdf_IRI i);
uint8_t kscids_elem_in_table(types_KElem e);
uint8_t kscids_term_in_table(types_KTerm t);
uint8_t kscids_role_in_table(types_RoleId r);
kscids_KscIds kscids_with_elem(slop_arena* arena, kscids_KscIds ids, types_KElem e);
kscids_KscIds kscids_with_term(slop_arena* arena, kscids_KscIds ids, types_KTerm t);
kscids_KscIds kscids_with_role(slop_arena* arena, kscids_KscIds ids, types_RoleId r);
kscids_KscIds kscids_with_name(slop_arena* arena, kscids_KscIds ids, types_KName n);
kscids_KscIds kscids_with_kterm(slop_arena* arena, kscids_KscIds ids, types_KTerm t);
kscids_KscIds kscids_build_ksc_ids(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, slop_list_rdf_IRI individuals);
uint8_t kscids_outside(slop_string what);
uint32_t kscids_arith(int64_t n, int64_t k, int64_t tag);
uint32_t kscids_table_id(slop_option_u32 found, int64_t k, int64_t tag, slop_string what);
uint32_t kscids_elem_id(kscids_KscIds ids, types_KElem e);
uint32_t kscids_term_id(kscids_KscIds ids, types_KTerm t);
uint32_t kscids_role_id(kscids_KscIds ids, types_RoleId r);
types_KElem kscids_id_elem(kscids_KscIds ids, uint32_t i);
types_KTerm kscids_id_term(kscids_KscIds ids, uint32_t i);
types_RoleId kscids_id_role(kscids_KscIds ids, uint32_t i);
kscids_CFact kscids_encode_fact(kscids_KscIds ids, types_KFact f);
types_KFact kscids_decode_fact(kscids_KscIds ids, kscids_CFact c);

uint8_t kscids_inst_kind(void) {
    return ((uint8_t)(0));
}

uint8_t kscids_triple_kind(void) {
    return ((uint8_t)(1));
}

uint8_t kscids_self_kind(void) {
    return ((uint8_t)(2));
}

int64_t kscids_max_n(int64_t k, int64_t tag) {
    return ((4294967295 - tag) / k);
}

uint8_t kscids_is_thing(rdf_IRI i) {
    return string_eq(i.value, vocab_OWL_THING);
}

uint8_t kscids_is_nothing(rdf_IRI i) {
    return string_eq(i.value, vocab_OWL_NOTHING);
}

uint8_t kscids_elem_in_table(types_KElem e) {
    __auto_type _mv_332 = e;
    switch (_mv_332.tag) {
        case types_KElem_e_aux:
        {
            __auto_type _ = _mv_332.data.e_aux;
            return 0;
        }
        case types_KElem_e_ind:
        {
            __auto_type _ = _mv_332.data.e_ind;
            return 1;
        }
        case types_KElem_e_class:
        {
            __auto_type n = _mv_332.data.e_class;
            __auto_type _mv_333 = n;
            switch (_mv_333.tag) {
                case types_KName_k_fresh:
                {
                    __auto_type _ = _mv_333.data.k_fresh;
                    return 0;
                }
                case types_KName_k_class:
                {
                    __auto_type _ = _mv_333.data.k_class;
                    return 1;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t kscids_term_in_table(types_KTerm t) {
    __auto_type _mv_334 = t;
    switch (_mv_334.tag) {
        case types_KTerm_k_nominal:
        {
            __auto_type _ = _mv_334.data.k_nominal;
            return 1;
        }
        case types_KTerm_k_name:
        {
            __auto_type n = _mv_334.data.k_name;
            __auto_type _mv_335 = n;
            switch (_mv_335.tag) {
                case types_KName_k_fresh:
                {
                    __auto_type _ = _mv_335.data.k_fresh;
                    return 0;
                }
                case types_KName_k_class:
                {
                    __auto_type _ = _mv_335.data.k_class;
                    return 1;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t kscids_role_in_table(types_RoleId r) {
    __auto_type _mv_336 = r;
    switch (_mv_336.tag) {
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_336.data.fresh_role;
            return 0;
        }
        case types_RoleId_named_role:
        {
            __auto_type _ = _mv_336.data.named_role;
            return 1;
        }
    }
    SLOP_UNREACHABLE();
}

kscids_KscIds kscids_with_elem(slop_arena* arena, kscids_KscIds ids, types_KElem e) {
    if ((kscids_elem_in_table(e)) ? !(slop_map_has(ids.elems, &(e))) : 0) {
        {
            __auto_type of = ids.elem_of;
            ({ uint32_t _val = ((uint32_t)(((int64_t)((of).len)))); slop_map_put(arena, ids.elems, &(e), &_val, sizeof(_val)); });
            ({ __auto_type _lst_p = &(of); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            return ((kscids_KscIds){.elems = ids.elems, .elem_of = of, .terms = ids.terms, .term_of = ids.term_of, .roles = ids.roles, .role_of = ids.role_of});
        }
    } else {
        return ids;
    }
}

kscids_KscIds kscids_with_term(slop_arena* arena, kscids_KscIds ids, types_KTerm t) {
    if ((kscids_term_in_table(t)) ? !(slop_map_has(ids.terms, &(t))) : 0) {
        {
            __auto_type of = ids.term_of;
            ({ uint32_t _val = ((uint32_t)(((int64_t)((of).len)))); slop_map_put(arena, ids.terms, &(t), &_val, sizeof(_val)); });
            ({ __auto_type _lst_p = &(of); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            return ((kscids_KscIds){.elems = ids.elems, .elem_of = ids.elem_of, .terms = ids.terms, .term_of = of, .roles = ids.roles, .role_of = ids.role_of});
        }
    } else {
        return ids;
    }
}

kscids_KscIds kscids_with_role(slop_arena* arena, kscids_KscIds ids, types_RoleId r) {
    if ((kscids_role_in_table(r)) ? !(slop_map_has(ids.roles, &(r))) : 0) {
        {
            __auto_type of = ids.role_of;
            ({ uint32_t _val = ((uint32_t)(((int64_t)((of).len)))); slop_map_put(arena, ids.roles, &(r), &_val, sizeof(_val)); });
            ({ __auto_type _lst_p = &(of); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            return ((kscids_KscIds){.elems = ids.elems, .elem_of = ids.elem_of, .terms = ids.terms, .term_of = ids.term_of, .roles = ids.roles, .role_of = of});
        }
    } else {
        return ids;
    }
}

kscids_KscIds kscids_with_name(slop_arena* arena, kscids_KscIds ids, types_KName n) {
    return kscids_with_elem(arena, kscids_with_term(arena, ids, types_name_term(n)), types_class_elem(n));
}

kscids_KscIds kscids_with_kterm(slop_arena* arena, kscids_KscIds ids, types_KTerm t) {
    __auto_type _mv_343 = t;
    switch (_mv_343.tag) {
        case types_KTerm_k_name:
        {
            __auto_type n = _mv_343.data.k_name;
            return kscids_with_name(arena, ids, n);
        }
        case types_KTerm_k_nominal:
        {
            __auto_type _ = _mv_343.data.k_nominal;
            return kscids_with_term(arena, ids, t);
        }
    }
    SLOP_UNREACHABLE();
}

kscids_KscIds kscids_build_ksc_ids(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, slop_list_rdf_IRI individuals) {
    {
        __auto_type ids = ((kscids_KscIds){.elems = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED, uint32_t); slop_map_new_ptr(arena, 0, &_d); }), .elem_of = ((slop_list_types_KElem){ .data = NULL, .len = 0, .cap = 0 }), .terms = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KTerm, slop_hash_types_KTerm, slop_eq_types_KTerm, SLOP_KEY_HASHED, uint32_t); slop_map_new_ptr(arena, 0, &_d); }), .term_of = ((slop_list_types_KTerm){ .data = NULL, .len = 0, .cap = 0 }), .roles = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, uint32_t); slop_map_new_ptr(arena, 0, &_d); }), .role_of = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 })});
        ids = kscids_with_name(arena, ids, ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = vocab_OWL_THING}) }));
        ids = kscids_with_name(arena, ids, ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = vocab_OWL_NOTHING}) }));
        {
            __auto_type _coll = individuals;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ids = kscids_with_term(arena, ids, types_nominal_term(a));
                ids = kscids_with_elem(arena, ids, types_ind_elem(a));
            }
        }
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                ids = kscids_with_name(arena, ids, q);
            }
        }
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_344 = ax;
                switch (_mv_344.tag) {
                    case types_KscAxiom_k_sub:
                    {
                        __auto_type a = _mv_344.data.k_sub.f0;
                        __auto_type b = _mv_344.data.k_sub.f1;
                        ids = kscids_with_kterm(arena, ids, a);
                        ids = kscids_with_kterm(arena, ids, b);
                        break;
                    }
                    case types_KscAxiom_k_and:
                    {
                        __auto_type a = _mv_344.data.k_and.f0;
                        __auto_type b = _mv_344.data.k_and.f1;
                        __auto_type c = _mv_344.data.k_and.f2;
                        ids = kscids_with_name(arena, ids, a);
                        ids = kscids_with_name(arena, ids, b);
                        ids = kscids_with_name(arena, ids, c);
                        break;
                    }
                    case types_KscAxiom_k_some_lhs:
                    {
                        __auto_type r = _mv_344.data.k_some_lhs.f0;
                        __auto_type a = _mv_344.data.k_some_lhs.f1;
                        __auto_type c = _mv_344.data.k_some_lhs.f2;
                        ids = kscids_with_role(arena, ids, r);
                        ids = kscids_with_name(arena, ids, a);
                        ids = kscids_with_name(arena, ids, c);
                        break;
                    }
                    case types_KscAxiom_k_some_rhs:
                    {
                        __auto_type a = _mv_344.data.k_some_rhs.f0;
                        __auto_type r = _mv_344.data.k_some_rhs.f1;
                        __auto_type b = _mv_344.data.k_some_rhs.f2;
                        ids = kscids_with_name(arena, ids, a);
                        ids = kscids_with_role(arena, ids, r);
                        ids = kscids_with_name(arena, ids, b);
                        break;
                    }
                    case types_KscAxiom_k_self_lhs:
                    {
                        __auto_type r = _mv_344.data.k_self_lhs.f0;
                        __auto_type c = _mv_344.data.k_self_lhs.f1;
                        ids = kscids_with_role(arena, ids, r);
                        ids = kscids_with_name(arena, ids, c);
                        break;
                    }
                    case types_KscAxiom_k_self_rhs:
                    {
                        __auto_type a = _mv_344.data.k_self_rhs.f0;
                        __auto_type r = _mv_344.data.k_self_rhs.f1;
                        ids = kscids_with_name(arena, ids, a);
                        ids = kscids_with_role(arena, ids, r);
                        break;
                    }
                    case types_KscAxiom_k_role:
                    {
                        __auto_type r = _mv_344.data.k_role.f0;
                        __auto_type s = _mv_344.data.k_role.f1;
                        ids = kscids_with_role(arena, ids, r);
                        ids = kscids_with_role(arena, ids, s);
                        break;
                    }
                    case types_KscAxiom_k_chain:
                    {
                        __auto_type r = _mv_344.data.k_chain.f0;
                        __auto_type s = _mv_344.data.k_chain.f1;
                        __auto_type t = _mv_344.data.k_chain.f2;
                        ids = kscids_with_role(arena, ids, r);
                        ids = kscids_with_role(arena, ids, s);
                        ids = kscids_with_role(arena, ids, t);
                        break;
                    }
                    case types_KscAxiom_k_range:
                    {
                        __auto_type r = _mv_344.data.k_range.f0;
                        __auto_type d = _mv_344.data.k_range.f1;
                        ids = kscids_with_role(arena, ids, r);
                        ids = kscids_with_name(arena, ids, d);
                        break;
                    }
                    case types_KscAxiom_k_role_assert:
                    {
                        __auto_type r = _mv_344.data.k_role_assert.f1;
                        ids = kscids_with_role(arena, ids, r);
                        break;
                    }
                }
            }
        }
        return ids;
    }
}

uint8_t kscids_outside(slop_string what) {
    fprintf(stderr, "howl: el++ store: %.*s outside the id space (kscids.slop)\n", (int)what.len, what.data); abort();;
    return 0;
}

uint32_t kscids_arith(int64_t n, int64_t k, int64_t tag) {
    if (n > kscids_max_n(k, tag)) {
        kscids_outside(SLOP_STR("an Int"));
        return ((uint32_t)(0));
    } else {
        return ((uint32_t)(((n * k) + tag)));
    }
}

uint32_t kscids_table_id(slop_option_u32 found, int64_t k, int64_t tag, slop_string what) {
    __auto_type _mv_345 = found;
    if (_mv_345.has_value) {
        __auto_type i = _mv_345.value;
        return kscids_arith(((int64_t)(i)), k, tag);
    } else if (!_mv_345.has_value) {
        kscids_outside(what);
        return ((uint32_t)(0));
    }
    SLOP_UNREACHABLE();
}

uint32_t kscids_elem_id(kscids_KscIds ids, types_KElem e) {
    __auto_type _mv_346 = e;
    switch (_mv_346.tag) {
        case types_KElem_e_aux:
        {
            __auto_type w = _mv_346.data.e_aux;
            return kscids_arith(w, 3, 0);
        }
        case types_KElem_e_ind:
        {
            __auto_type _ = _mv_346.data.e_ind;
            return kscids_table_id(({ void* _ptr = slop_map_get(ids.elems, &(e)); _ptr ? (slop_option_u32){ .has_value = true, .value = *(uint32_t*)_ptr } : (slop_option_u32){ .has_value = false }; }), 3, 2, SLOP_STR("an individual"));
        }
        case types_KElem_e_class:
        {
            __auto_type n = _mv_346.data.e_class;
            __auto_type _mv_348 = n;
            switch (_mv_348.tag) {
                case types_KName_k_fresh:
                {
                    __auto_type i = _mv_348.data.k_fresh;
                    return kscids_arith(i, 3, 1);
                }
                case types_KName_k_class:
                {
                    __auto_type c = _mv_348.data.k_class;
                    if (kscids_is_thing(c)) {
                        return ((uint32_t)(2));
                    } else {
                        if (kscids_is_nothing(c)) {
                            return ((uint32_t)(5));
                        } else {
                            return kscids_table_id(({ void* _ptr = slop_map_get(ids.elems, &(e)); _ptr ? (slop_option_u32){ .has_value = true, .value = *(uint32_t*)_ptr } : (slop_option_u32){ .has_value = false }; }), 3, 2, SLOP_STR("a class element"));
                        }
                    }
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint32_t kscids_term_id(kscids_KscIds ids, types_KTerm t) {
    __auto_type _mv_350 = t;
    switch (_mv_350.tag) {
        case types_KTerm_k_nominal:
        {
            __auto_type _ = _mv_350.data.k_nominal;
            return kscids_table_id(({ void* _ptr = slop_map_get(ids.terms, &(t)); _ptr ? (slop_option_u32){ .has_value = true, .value = *(uint32_t*)_ptr } : (slop_option_u32){ .has_value = false }; }), 2, 1, SLOP_STR("a nominal"));
        }
        case types_KTerm_k_name:
        {
            __auto_type n = _mv_350.data.k_name;
            __auto_type _mv_352 = n;
            switch (_mv_352.tag) {
                case types_KName_k_fresh:
                {
                    __auto_type i = _mv_352.data.k_fresh;
                    return kscids_arith(i, 2, 0);
                }
                case types_KName_k_class:
                {
                    __auto_type c = _mv_352.data.k_class;
                    if (kscids_is_thing(c)) {
                        return ((uint32_t)(1));
                    } else {
                        if (kscids_is_nothing(c)) {
                            return ((uint32_t)(3));
                        } else {
                            return kscids_table_id(({ void* _ptr = slop_map_get(ids.terms, &(t)); _ptr ? (slop_option_u32){ .has_value = true, .value = *(uint32_t*)_ptr } : (slop_option_u32){ .has_value = false }; }), 2, 1, SLOP_STR("a class name"));
                        }
                    }
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint32_t kscids_role_id(kscids_KscIds ids, types_RoleId r) {
    __auto_type _mv_354 = r;
    switch (_mv_354.tag) {
        case types_RoleId_fresh_role:
        {
            __auto_type i = _mv_354.data.fresh_role;
            return kscids_arith(i, 2, 0);
        }
        case types_RoleId_named_role:
        {
            __auto_type _ = _mv_354.data.named_role;
            return kscids_table_id(({ void* _ptr = slop_map_get(ids.roles, &(r)); _ptr ? (slop_option_u32){ .has_value = true, .value = *(uint32_t*)_ptr } : (slop_option_u32){ .has_value = false }; }), 2, 1, SLOP_STR("a named role"));
        }
    }
    SLOP_UNREACHABLE();
}

types_KElem kscids_id_elem(kscids_KscIds ids, uint32_t i) {
    {
        __auto_type n = (((int64_t)(i)) / 3);
        __auto_type tag = (((int64_t)(i)) - ((((int64_t)(i)) / 3) * 3));
        if (tag == 0) {
            return ((types_KElem){ .tag = types_KElem_e_aux, .data.e_aux = ((int64_t)(n)) });
        } else {
            if (tag == 1) {
                return ((types_KElem){ .tag = types_KElem_e_class, .data.e_class = ((types_KName){ .tag = types_KName_k_fresh, .data.k_fresh = ((int64_t)(n)) }) });
            } else {
                __auto_type _mv_356 = ({ __auto_type _lst = ids.elem_of; size_t _idx = (size_t)n; slop_option_types_KElem _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_356.has_value) {
                    __auto_type e = _mv_356.value;
                    return e;
                } else if (!_mv_356.has_value) {
                    kscids_outside(SLOP_STR("an element id"));
                    return ((types_KElem){ .tag = types_KElem_e_aux, .data.e_aux = 0 });
                }
                SLOP_UNREACHABLE();
            }
        }
    }
}

types_KTerm kscids_id_term(kscids_KscIds ids, uint32_t i) {
    {
        __auto_type n = (((int64_t)(i)) / 2);
        if ((((int64_t)(i)) - (n * 2)) == 0) {
            return ((types_KTerm){ .tag = types_KTerm_k_name, .data.k_name = ((types_KName){ .tag = types_KName_k_fresh, .data.k_fresh = ((int64_t)(n)) }) });
        } else {
            __auto_type _mv_357 = ({ __auto_type _lst = ids.term_of; size_t _idx = (size_t)n; slop_option_types_KTerm _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_357.has_value) {
                __auto_type t = _mv_357.value;
                return t;
            } else if (!_mv_357.has_value) {
                kscids_outside(SLOP_STR("a term id"));
                return ((types_KTerm){ .tag = types_KTerm_k_name, .data.k_name = ((types_KName){ .tag = types_KName_k_fresh, .data.k_fresh = 0 }) });
            }
            SLOP_UNREACHABLE();
        }
    }
}

types_RoleId kscids_id_role(kscids_KscIds ids, uint32_t i) {
    {
        __auto_type n = (((int64_t)(i)) / 2);
        if ((((int64_t)(i)) - (n * 2)) == 0) {
            return ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = ((int64_t)(n)) });
        } else {
            __auto_type _mv_358 = ({ __auto_type _lst = ids.role_of; size_t _idx = (size_t)n; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_358.has_value) {
                __auto_type r = _mv_358.value;
                return r;
            } else if (!_mv_358.has_value) {
                kscids_outside(SLOP_STR("a role id"));
                return ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = 0 });
            }
            SLOP_UNREACHABLE();
        }
    }
}

kscids_CFact kscids_encode_fact(kscids_KscIds ids, types_KFact f) {
    __auto_type _mv_359 = f;
    switch (_mv_359.tag) {
        case types_KFact_f_inst:
        {
            __auto_type x = _mv_359.data.f_inst.f0;
            __auto_type y = _mv_359.data.f_inst.f1;
            return ((kscids_CFact){.kind = kscids_inst_kind(), .a = kscids_elem_id(ids, x), .b = kscids_term_id(ids, y), .c = ((uint32_t)(0))});
        }
        case types_KFact_f_triple:
        {
            __auto_type x = _mv_359.data.f_triple.f0;
            __auto_type v = _mv_359.data.f_triple.f1;
            __auto_type x1 = _mv_359.data.f_triple.f2;
            return ((kscids_CFact){.kind = kscids_triple_kind(), .a = kscids_elem_id(ids, x), .b = kscids_role_id(ids, v), .c = kscids_elem_id(ids, x1)});
        }
        case types_KFact_f_self:
        {
            __auto_type x = _mv_359.data.f_self.f0;
            __auto_type v = _mv_359.data.f_self.f1;
            return ((kscids_CFact){.kind = kscids_self_kind(), .a = kscids_elem_id(ids, x), .b = kscids_role_id(ids, v), .c = ((uint32_t)(0))});
        }
    }
    SLOP_UNREACHABLE();
}

types_KFact kscids_decode_fact(kscids_KscIds ids, kscids_CFact c) {
    if (c.kind == kscids_inst_kind()) {
        return ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = kscids_id_elem(ids, c.a), .f1 = kscids_id_term(ids, c.b) } });
    } else {
        if (c.kind == kscids_triple_kind()) {
            return ((types_KFact){ .tag = types_KFact_f_triple, .data.f_triple = { .f0 = kscids_id_elem(ids, c.a), .f1 = kscids_id_role(ids, c.b), .f2 = kscids_id_elem(ids, c.c) } });
        } else {
            return ((types_KFact){ .tag = types_KFact_f_self, .data.f_self = { .f0 = kscids_id_elem(ids, c.a), .f1 = kscids_id_role(ids, c.b) } });
        }
    }
}

