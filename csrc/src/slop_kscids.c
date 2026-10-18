#include "../runtime/slop_runtime.h"
#include "slop_kscids.h"

uint8_t howl_kscids_inst_kind(void);
uint8_t howl_kscids_triple_kind(void);
uint8_t howl_kscids_self_kind(void);
int64_t howl_kscids_max_n(int64_t k, int64_t tag);
uint8_t howl_kscids_is_thing(slop_rdf_rdf_IRI i);
uint8_t howl_kscids_is_nothing(slop_rdf_rdf_IRI i);
uint8_t howl_kscids_elem_in_table(howl_types_KElem e);
uint8_t howl_kscids_term_in_table(howl_types_KTerm t);
uint8_t howl_kscids_role_in_table(howl_types_RoleId r);
howl_kscids_KscIds howl_kscids_with_elem(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KElem e);
howl_kscids_KscIds howl_kscids_with_term(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KTerm t);
howl_kscids_KscIds howl_kscids_with_role(slop_arena* arena, howl_kscids_KscIds ids, howl_types_RoleId r);
howl_kscids_KscIds howl_kscids_with_name(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KName n);
howl_kscids_KscIds howl_kscids_with_kterm(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KTerm t);
howl_kscids_KscIds howl_kscids_build_ksc_ids(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes, slop_list_slop_rdf_rdf_IRI individuals);
uint8_t howl_kscids_outside(slop_string what);
uint32_t howl_kscids_arith(int64_t n, int64_t k, int64_t tag);
uint32_t howl_kscids_table_id(slop_option_u32 found, int64_t k, int64_t tag, slop_string what);
uint32_t howl_kscids_elem_id(howl_kscids_KscIds ids, howl_types_KElem e);
uint32_t howl_kscids_term_id(howl_kscids_KscIds ids, howl_types_KTerm t);
uint32_t howl_kscids_role_id(howl_kscids_KscIds ids, howl_types_RoleId r);
howl_types_KElem howl_kscids_id_elem(howl_kscids_KscIds ids, uint32_t i);
howl_types_KTerm howl_kscids_id_term(howl_kscids_KscIds ids, uint32_t i);
howl_types_RoleId howl_kscids_id_role(howl_kscids_KscIds ids, uint32_t i);
howl_kscids_CFact howl_kscids_encode_fact(howl_kscids_KscIds ids, howl_types_KFact f);
howl_types_KFact howl_kscids_decode_fact(howl_kscids_KscIds ids, howl_kscids_CFact c);

uint8_t howl_kscids_inst_kind(void) {
    return ((uint8_t)(0));
}

uint8_t howl_kscids_triple_kind(void) {
    return ((uint8_t)(1));
}

uint8_t howl_kscids_self_kind(void) {
    return ((uint8_t)(2));
}

int64_t howl_kscids_max_n(int64_t k, int64_t tag) {
    return ((4294967295 - tag) / k);
}

uint8_t howl_kscids_is_thing(slop_rdf_rdf_IRI i) {
    return string_eq(i.value, slop_rdf_vocab_OWL_THING);
}

uint8_t howl_kscids_is_nothing(slop_rdf_rdf_IRI i) {
    return string_eq(i.value, slop_rdf_vocab_OWL_NOTHING);
}

uint8_t howl_kscids_elem_in_table(howl_types_KElem e) {
    __auto_type _mv_1155 = e;
    switch (_mv_1155.tag) {
        case howl_types_KElem_e_aux:
        {
            __auto_type _ = _mv_1155.data.e_aux;
            return 0;
        }
        case howl_types_KElem_e_ind:
        {
            __auto_type _ = _mv_1155.data.e_ind;
            return 1;
        }
        case howl_types_KElem_e_class:
        {
            __auto_type n = _mv_1155.data.e_class;
            __auto_type _mv_1156 = n;
            switch (_mv_1156.tag) {
                case howl_types_KName_k_fresh:
                {
                    __auto_type _ = _mv_1156.data.k_fresh;
                    return 0;
                }
                case howl_types_KName_k_class:
                {
                    __auto_type _ = _mv_1156.data.k_class;
                    return 1;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_kscids_term_in_table(howl_types_KTerm t) {
    __auto_type _mv_1157 = t;
    switch (_mv_1157.tag) {
        case howl_types_KTerm_k_nominal:
        {
            __auto_type _ = _mv_1157.data.k_nominal;
            return 1;
        }
        case howl_types_KTerm_k_name:
        {
            __auto_type n = _mv_1157.data.k_name;
            __auto_type _mv_1158 = n;
            switch (_mv_1158.tag) {
                case howl_types_KName_k_fresh:
                {
                    __auto_type _ = _mv_1158.data.k_fresh;
                    return 0;
                }
                case howl_types_KName_k_class:
                {
                    __auto_type _ = _mv_1158.data.k_class;
                    return 1;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_kscids_role_in_table(howl_types_RoleId r) {
    __auto_type _mv_1159 = r;
    switch (_mv_1159.tag) {
        case howl_types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_1159.data.fresh_role;
            return 0;
        }
        case howl_types_RoleId_named_role:
        {
            __auto_type _ = _mv_1159.data.named_role;
            return 1;
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type _ = _mv_1159.data.inverse_role;
            return 1;
        }
    }
    SLOP_UNREACHABLE();
}

howl_kscids_KscIds howl_kscids_with_elem(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KElem e) {
    if ((howl_kscids_elem_in_table(e)) ? !(slop_map_has(ids.elems, &(e))) : 0) {
        {
            __auto_type of = ids.elem_of;
            (void)(({ uint32_t _val = ((uint32_t)(((int64_t)((of).len)))); slop_map_put(NULL, ids.elems, &(e), &_val, sizeof(_val)); }));
            (void)(({ __auto_type _lst_p = &(of); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            return ((howl_kscids_KscIds){.elems = ids.elems, .elem_of = of, .terms = ids.terms, .term_of = ids.term_of, .roles = ids.roles, .role_of = ids.role_of});
        }
    } else {
        return ids;
    }
}

howl_kscids_KscIds howl_kscids_with_term(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KTerm t) {
    if ((howl_kscids_term_in_table(t)) ? !(slop_map_has(ids.terms, &(t))) : 0) {
        {
            __auto_type of = ids.term_of;
            (void)(({ uint32_t _val = ((uint32_t)(((int64_t)((of).len)))); slop_map_put(NULL, ids.terms, &(t), &_val, sizeof(_val)); }));
            (void)(({ __auto_type _lst_p = &(of); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            return ((howl_kscids_KscIds){.elems = ids.elems, .elem_of = ids.elem_of, .terms = ids.terms, .term_of = of, .roles = ids.roles, .role_of = ids.role_of});
        }
    } else {
        return ids;
    }
}

howl_kscids_KscIds howl_kscids_with_role(slop_arena* arena, howl_kscids_KscIds ids, howl_types_RoleId r) {
    if ((howl_kscids_role_in_table(r)) ? !(slop_map_has(ids.roles, &(r))) : 0) {
        {
            __auto_type of = ids.role_of;
            (void)(({ uint32_t _val = ((uint32_t)(((int64_t)((of).len)))); slop_map_put(NULL, ids.roles, &(r), &_val, sizeof(_val)); }));
            (void)(({ __auto_type _lst_p = &(of); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            return ((howl_kscids_KscIds){.elems = ids.elems, .elem_of = ids.elem_of, .terms = ids.terms, .term_of = ids.term_of, .roles = ids.roles, .role_of = of});
        }
    } else {
        return ids;
    }
}

howl_kscids_KscIds howl_kscids_with_name(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KName n) {
    return howl_kscids_with_elem(arena, howl_kscids_with_term(arena, ids, howl_types_name_term(n)), howl_types_class_elem(n));
}

howl_kscids_KscIds howl_kscids_with_kterm(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KTerm t) {
    __auto_type _mv_1166 = t;
    switch (_mv_1166.tag) {
        case howl_types_KTerm_k_name:
        {
            __auto_type n = _mv_1166.data.k_name;
            return howl_kscids_with_name(arena, ids, n);
        }
        case howl_types_KTerm_k_nominal:
        {
            __auto_type _ = _mv_1166.data.k_nominal;
            return howl_kscids_with_term(arena, ids, t);
        }
    }
    SLOP_UNREACHABLE();
}

howl_kscids_KscIds howl_kscids_build_ksc_ids(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes, slop_list_slop_rdf_rdf_IRI individuals) {
    {
        __auto_type ids = ((howl_kscids_KscIds){.elems = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_KElem, slop_hash_howl_types_KElem, slop_eq_howl_types_KElem, SLOP_KEY_HASHED, uint32_t); slop_map_new_ptr(arena, 0, &_d); }), .elem_of = ((slop_list_howl_types_KElem){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .terms = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_KTerm, slop_hash_howl_types_KTerm, slop_eq_howl_types_KTerm, SLOP_KEY_HASHED, uint32_t); slop_map_new_ptr(arena, 0, &_d); }), .term_of = ((slop_list_howl_types_KTerm){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .roles = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_RoleId, slop_hash_howl_types_RoleId, slop_eq_howl_types_RoleId, SLOP_KEY_HASHED, uint32_t); slop_map_new_ptr(arena, 0, &_d); }), .role_of = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
        ids = howl_kscids_with_name(arena, ids, ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_THING}) }));
        ids = howl_kscids_with_name(arena, ids, ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_NOTHING}) }));
        {
            __auto_type _coll = individuals;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ids = howl_kscids_with_term(arena, ids, howl_types_nominal_term(a));
                ids = howl_kscids_with_elem(arena, ids, howl_types_ind_elem(a));
            }
        }
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                ids = howl_kscids_with_name(arena, ids, q);
            }
        }
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1167 = ax;
                switch (_mv_1167.tag) {
                    case howl_types_KscAxiom_k_sub:
                    {
                        __auto_type a = _mv_1167.data.k_sub.f0;
                        __auto_type b = _mv_1167.data.k_sub.f1;
                        ids = howl_kscids_with_kterm(arena, ids, a);
                        ids = howl_kscids_with_kterm(arena, ids, b);
                        break;
                    }
                    case howl_types_KscAxiom_k_and:
                    {
                        __auto_type a = _mv_1167.data.k_and.f0;
                        __auto_type b = _mv_1167.data.k_and.f1;
                        __auto_type c = _mv_1167.data.k_and.f2;
                        ids = howl_kscids_with_name(arena, ids, a);
                        ids = howl_kscids_with_name(arena, ids, b);
                        ids = howl_kscids_with_name(arena, ids, c);
                        break;
                    }
                    case howl_types_KscAxiom_k_some_lhs:
                    {
                        __auto_type r = _mv_1167.data.k_some_lhs.f0;
                        __auto_type a = _mv_1167.data.k_some_lhs.f1;
                        __auto_type c = _mv_1167.data.k_some_lhs.f2;
                        ids = howl_kscids_with_role(arena, ids, r);
                        ids = howl_kscids_with_name(arena, ids, a);
                        ids = howl_kscids_with_name(arena, ids, c);
                        break;
                    }
                    case howl_types_KscAxiom_k_some_rhs:
                    {
                        __auto_type a = _mv_1167.data.k_some_rhs.f0;
                        __auto_type r = _mv_1167.data.k_some_rhs.f1;
                        __auto_type b = _mv_1167.data.k_some_rhs.f2;
                        ids = howl_kscids_with_name(arena, ids, a);
                        ids = howl_kscids_with_role(arena, ids, r);
                        ids = howl_kscids_with_name(arena, ids, b);
                        break;
                    }
                    case howl_types_KscAxiom_k_self_lhs:
                    {
                        __auto_type r = _mv_1167.data.k_self_lhs.f0;
                        __auto_type c = _mv_1167.data.k_self_lhs.f1;
                        ids = howl_kscids_with_role(arena, ids, r);
                        ids = howl_kscids_with_name(arena, ids, c);
                        break;
                    }
                    case howl_types_KscAxiom_k_self_rhs:
                    {
                        __auto_type a = _mv_1167.data.k_self_rhs.f0;
                        __auto_type r = _mv_1167.data.k_self_rhs.f1;
                        ids = howl_kscids_with_name(arena, ids, a);
                        ids = howl_kscids_with_role(arena, ids, r);
                        break;
                    }
                    case howl_types_KscAxiom_k_role:
                    {
                        __auto_type r = _mv_1167.data.k_role.f0;
                        __auto_type s = _mv_1167.data.k_role.f1;
                        ids = howl_kscids_with_role(arena, ids, r);
                        ids = howl_kscids_with_role(arena, ids, s);
                        break;
                    }
                    case howl_types_KscAxiom_k_chain:
                    {
                        __auto_type r = _mv_1167.data.k_chain.f0;
                        __auto_type s = _mv_1167.data.k_chain.f1;
                        __auto_type t = _mv_1167.data.k_chain.f2;
                        ids = howl_kscids_with_role(arena, ids, r);
                        ids = howl_kscids_with_role(arena, ids, s);
                        ids = howl_kscids_with_role(arena, ids, t);
                        break;
                    }
                    case howl_types_KscAxiom_k_range:
                    {
                        __auto_type r = _mv_1167.data.k_range.f0;
                        __auto_type d = _mv_1167.data.k_range.f1;
                        ids = howl_kscids_with_role(arena, ids, r);
                        ids = howl_kscids_with_name(arena, ids, d);
                        break;
                    }
                    case howl_types_KscAxiom_k_role_assert:
                    {
                        __auto_type r = _mv_1167.data.k_role_assert.f1;
                        ids = howl_kscids_with_role(arena, ids, r);
                        break;
                    }
                }
            }
        }
        return ids;
    }
}

uint8_t howl_kscids_outside(slop_string what) {
    fprintf(stderr, "howl: el++ store: %.*s outside the id space (kscids.slop)\n", (int)what.len, what.data); abort();;
    return 0;
}

uint32_t howl_kscids_arith(int64_t n, int64_t k, int64_t tag) {
    if (n > howl_kscids_max_n(k, tag)) {
        howl_kscids_outside(SLOP_STR("an Int"));
        return ((uint32_t)(0));
    } else {
        return ((uint32_t)(((n * k) + tag)));
    }
}

uint32_t howl_kscids_table_id(slop_option_u32 found, int64_t k, int64_t tag, slop_string what) {
    __auto_type _mv_1168 = found;
    if (_mv_1168.has_value) {
        __auto_type i = _mv_1168.value;
        return howl_kscids_arith(((int64_t)(i)), k, tag);
    } else if (!_mv_1168.has_value) {
        howl_kscids_outside(what);
        return ((uint32_t)(0));
    }
    SLOP_UNREACHABLE();
}

uint32_t howl_kscids_elem_id(howl_kscids_KscIds ids, howl_types_KElem e) {
    __auto_type _mv_1169 = e;
    switch (_mv_1169.tag) {
        case howl_types_KElem_e_aux:
        {
            __auto_type w = _mv_1169.data.e_aux;
            return howl_kscids_arith(w, 3, 0);
        }
        case howl_types_KElem_e_ind:
        {
            __auto_type _ = _mv_1169.data.e_ind;
            return howl_kscids_table_id(({ void* _ptr = slop_map_get(ids.elems, &(e)); _ptr ? (slop_option_u32){ .has_value = true, .value = *(uint32_t*)_ptr } : (slop_option_u32){ .has_value = false }; }), 3, 2, SLOP_STR("an individual"));
        }
        case howl_types_KElem_e_class:
        {
            __auto_type n = _mv_1169.data.e_class;
            __auto_type _mv_1171 = n;
            switch (_mv_1171.tag) {
                case howl_types_KName_k_fresh:
                {
                    __auto_type i = _mv_1171.data.k_fresh;
                    return howl_kscids_arith(i, 3, 1);
                }
                case howl_types_KName_k_class:
                {
                    __auto_type c = _mv_1171.data.k_class;
                    if (howl_kscids_is_thing(c)) {
                        return ((uint32_t)(2));
                    } else {
                        if (howl_kscids_is_nothing(c)) {
                            return ((uint32_t)(5));
                        } else {
                            return howl_kscids_table_id(({ void* _ptr = slop_map_get(ids.elems, &(e)); _ptr ? (slop_option_u32){ .has_value = true, .value = *(uint32_t*)_ptr } : (slop_option_u32){ .has_value = false }; }), 3, 2, SLOP_STR("a class element"));
                        }
                    }
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint32_t howl_kscids_term_id(howl_kscids_KscIds ids, howl_types_KTerm t) {
    __auto_type _mv_1173 = t;
    switch (_mv_1173.tag) {
        case howl_types_KTerm_k_nominal:
        {
            __auto_type _ = _mv_1173.data.k_nominal;
            return howl_kscids_table_id(({ void* _ptr = slop_map_get(ids.terms, &(t)); _ptr ? (slop_option_u32){ .has_value = true, .value = *(uint32_t*)_ptr } : (slop_option_u32){ .has_value = false }; }), 2, 1, SLOP_STR("a nominal"));
        }
        case howl_types_KTerm_k_name:
        {
            __auto_type n = _mv_1173.data.k_name;
            __auto_type _mv_1175 = n;
            switch (_mv_1175.tag) {
                case howl_types_KName_k_fresh:
                {
                    __auto_type i = _mv_1175.data.k_fresh;
                    return howl_kscids_arith(i, 2, 0);
                }
                case howl_types_KName_k_class:
                {
                    __auto_type c = _mv_1175.data.k_class;
                    if (howl_kscids_is_thing(c)) {
                        return ((uint32_t)(1));
                    } else {
                        if (howl_kscids_is_nothing(c)) {
                            return ((uint32_t)(3));
                        } else {
                            return howl_kscids_table_id(({ void* _ptr = slop_map_get(ids.terms, &(t)); _ptr ? (slop_option_u32){ .has_value = true, .value = *(uint32_t*)_ptr } : (slop_option_u32){ .has_value = false }; }), 2, 1, SLOP_STR("a class name"));
                        }
                    }
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint32_t howl_kscids_role_id(howl_kscids_KscIds ids, howl_types_RoleId r) {
    __auto_type _mv_1177 = r;
    switch (_mv_1177.tag) {
        case howl_types_RoleId_fresh_role:
        {
            __auto_type i = _mv_1177.data.fresh_role;
            return howl_kscids_arith(i, 2, 0);
        }
        case howl_types_RoleId_named_role:
        {
            __auto_type _ = _mv_1177.data.named_role;
            return howl_kscids_table_id(({ void* _ptr = slop_map_get(ids.roles, &(r)); _ptr ? (slop_option_u32){ .has_value = true, .value = *(uint32_t*)_ptr } : (slop_option_u32){ .has_value = false }; }), 2, 1, SLOP_STR("a named role"));
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type _ = _mv_1177.data.inverse_role;
            return howl_kscids_table_id(({ void* _ptr = slop_map_get(ids.roles, &(r)); _ptr ? (slop_option_u32){ .has_value = true, .value = *(uint32_t*)_ptr } : (slop_option_u32){ .has_value = false }; }), 2, 1, SLOP_STR("an inverse role"));
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_KElem howl_kscids_id_elem(howl_kscids_KscIds ids, uint32_t i) {
    {
        __auto_type n = (((int64_t)(i)) / 3);
        __auto_type tag = (((int64_t)(i)) - ((((int64_t)(i)) / 3) * 3));
        if (tag == 0) {
            return ((howl_types_KElem){ .tag = howl_types_KElem_e_aux, .data.e_aux = ((int64_t)(SLOP_RANGE(int64_t, n, 1, 0, 0, 0, "(Int 0 ..) at kscids.slop:278:49"))) });
        } else {
            if (tag == 1) {
                return ((howl_types_KElem){ .tag = howl_types_KElem_e_class, .data.e_class = ((howl_types_KName){ .tag = howl_types_KName_k_fresh, .data.k_fresh = ((int64_t)(SLOP_RANGE(int64_t, n, 1, 0, 0, 0, "(Int 0 ..) at kscids.slop:280:78"))) }) });
            } else {
                __auto_type _mv_1180 = ({ __auto_type _lst = ids.elem_of; size_t _idx = (size_t)n; slop_option_howl_types_KElem _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1180.has_value) {
                    __auto_type e = _mv_1180.value;
                    return e;
                } else if (!_mv_1180.has_value) {
                    howl_kscids_outside(SLOP_STR("an element id"));
                    return ((howl_types_KElem){ .tag = howl_types_KElem_e_aux, .data.e_aux = 0 });
                }
                SLOP_UNREACHABLE();
            }
        }
    }
}

howl_types_KTerm howl_kscids_id_term(howl_kscids_KscIds ids, uint32_t i) {
    {
        __auto_type n = (((int64_t)(i)) / 2);
        if ((((int64_t)(i)) - (n * 2)) == 0) {
            return ((howl_types_KTerm){ .tag = howl_types_KTerm_k_name, .data.k_name = ((howl_types_KName){ .tag = howl_types_KName_k_fresh, .data.k_fresh = ((int64_t)(SLOP_RANGE(int64_t, n, 1, 0, 0, 0, "(Int 0 ..) at kscids.slop:290:75"))) }) });
        } else {
            __auto_type _mv_1181 = ({ __auto_type _lst = ids.term_of; size_t _idx = (size_t)n; slop_option_howl_types_KTerm _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1181.has_value) {
                __auto_type t = _mv_1181.value;
                return t;
            } else if (!_mv_1181.has_value) {
                howl_kscids_outside(SLOP_STR("a term id"));
                return ((howl_types_KTerm){ .tag = howl_types_KTerm_k_name, .data.k_name = ((howl_types_KName){ .tag = howl_types_KName_k_fresh, .data.k_fresh = 0 }) });
            }
            SLOP_UNREACHABLE();
        }
    }
}

howl_types_RoleId howl_kscids_id_role(howl_kscids_KscIds ids, uint32_t i) {
    {
        __auto_type n = (((int64_t)(i)) / 2);
        if ((((int64_t)(i)) - (n * 2)) == 0) {
            return ((howl_types_RoleId){ .tag = howl_types_RoleId_fresh_role, .data.fresh_role = ((int64_t)(SLOP_RANGE(int64_t, n, 1, 0, 0, 0, "(Int 0 ..) at kscids.slop:300:55"))) });
        } else {
            __auto_type _mv_1182 = ({ __auto_type _lst = ids.role_of; size_t _idx = (size_t)n; slop_option_howl_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1182.has_value) {
                __auto_type r = _mv_1182.value;
                return r;
            } else if (!_mv_1182.has_value) {
                howl_kscids_outside(SLOP_STR("a role id"));
                return ((howl_types_RoleId){ .tag = howl_types_RoleId_fresh_role, .data.fresh_role = 0 });
            }
            SLOP_UNREACHABLE();
        }
    }
}

howl_kscids_CFact howl_kscids_encode_fact(howl_kscids_KscIds ids, howl_types_KFact f) {
    __auto_type _mv_1183 = f;
    switch (_mv_1183.tag) {
        case howl_types_KFact_f_inst:
        {
            __auto_type x = _mv_1183.data.f_inst.f0;
            __auto_type y = _mv_1183.data.f_inst.f1;
            return ((howl_kscids_CFact){.kind = howl_kscids_inst_kind(), .a = howl_kscids_elem_id(ids, x), .b = howl_kscids_term_id(ids, y), .c = ((uint32_t)(0))});
        }
        case howl_types_KFact_f_triple:
        {
            __auto_type x = _mv_1183.data.f_triple.f0;
            __auto_type v = _mv_1183.data.f_triple.f1;
            __auto_type x1 = _mv_1183.data.f_triple.f2;
            return ((howl_kscids_CFact){.kind = howl_kscids_triple_kind(), .a = howl_kscids_elem_id(ids, x), .b = howl_kscids_role_id(ids, v), .c = howl_kscids_elem_id(ids, x1)});
        }
        case howl_types_KFact_f_self:
        {
            __auto_type x = _mv_1183.data.f_self.f0;
            __auto_type v = _mv_1183.data.f_self.f1;
            return ((howl_kscids_CFact){.kind = howl_kscids_self_kind(), .a = howl_kscids_elem_id(ids, x), .b = howl_kscids_role_id(ids, v), .c = ((uint32_t)(0))});
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_KFact howl_kscids_decode_fact(howl_kscids_KscIds ids, howl_kscids_CFact c) {
    if (c.kind == howl_kscids_inst_kind()) {
        return ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = howl_kscids_id_elem(ids, c.a), .f1 = howl_kscids_id_term(ids, c.b) } });
    } else {
        if (c.kind == howl_kscids_triple_kind()) {
            return ((howl_types_KFact){ .tag = howl_types_KFact_f_triple, .data.f_triple = { .f0 = howl_kscids_id_elem(ids, c.a), .f1 = howl_kscids_id_role(ids, c.b), .f2 = howl_kscids_id_elem(ids, c.c) } });
        } else {
            return ((howl_types_KFact){ .tag = howl_types_KFact_f_self, .data.f_self = { .f0 = howl_kscids_id_elem(ids, c.a), .f1 = howl_kscids_id_role(ids, c.b) } });
        }
    }
}

