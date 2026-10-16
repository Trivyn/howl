#include "../runtime/slop_runtime.h"
#include "slop_kscnames.h"

uint8_t howl_kscnames_kept_as_iri(slop_rdf_rdf_IRI i);
int64_t howl_kscnames_max_fresh_name(howl_types_KName k, int64_t m);
int64_t howl_kscnames_max_fresh_term(howl_types_KTerm t, int64_t m);
int64_t howl_kscnames_max_fresh_role(howl_types_RoleId r, int64_t m);
uint8_t howl_kscnames_note_class(slop_arena* arena, howl_kscnames_KscNames nm, howl_types_KName k);
uint8_t howl_kscnames_note_role(slop_arena* arena, howl_kscnames_KscNames nm, howl_types_RoleId r);
uint8_t howl_kscnames_note_term(slop_arena* arena, howl_kscnames_KscNames nm, howl_types_KTerm t);
howl_kscnames_KscNames howl_kscnames_build_ksc_names(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes);
howl_types_KName howl_kscnames_rename_class(howl_kscnames_KscNames nm, howl_types_KName k);
howl_types_KTerm howl_kscnames_rename_term(howl_kscnames_KscNames nm, howl_types_KTerm t);
howl_types_RoleId howl_kscnames_rename_role(howl_kscnames_KscNames nm, howl_types_RoleId r);
howl_types_KscAxiom howl_kscnames_rename_axiom(howl_kscnames_KscNames nm, howl_types_KscAxiom ax);
slop_list_howl_types_KscAxiom howl_kscnames_rename_ksc_axioms(slop_arena* arena, howl_kscnames_KscNames nm, slop_list_howl_types_KscAxiom axioms);
slop_list_howl_types_KName howl_kscnames_rename_classes(slop_arena* arena, howl_kscnames_KscNames nm, slop_list_howl_types_KName classes);
howl_types_KName howl_kscnames_unrename_class(howl_kscnames_KscNames nm, howl_types_KName k);
howl_types_ClassAnswer howl_kscnames_unrename_answer(slop_arena* arena, howl_kscnames_KscNames nm, howl_types_ClassAnswer a);

uint8_t howl_kscnames_kept_as_iri(slop_rdf_rdf_IRI i) {
    if (string_eq(i.value, slop_rdf_vocab_OWL_THING)) {
        return 1;
    } else {
        return string_eq(i.value, slop_rdf_vocab_OWL_NOTHING);
    }
}

int64_t howl_kscnames_max_fresh_name(howl_types_KName k, int64_t m) {
    __auto_type _mv_1174 = k;
    switch (_mv_1174.tag) {
        case howl_types_KName_k_fresh:
        {
            __auto_type n = _mv_1174.data.k_fresh;
            if (n >= m) {
                return (n + 1);
            } else {
                return m;
            }
        }
        case howl_types_KName_k_class:
        {
            __auto_type _ = _mv_1174.data.k_class;
            return m;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t howl_kscnames_max_fresh_term(howl_types_KTerm t, int64_t m) {
    __auto_type _mv_1175 = t;
    switch (_mv_1175.tag) {
        case howl_types_KTerm_k_name:
        {
            __auto_type k = _mv_1175.data.k_name;
            return howl_kscnames_max_fresh_name(k, m);
        }
        case howl_types_KTerm_k_nominal:
        {
            __auto_type _ = _mv_1175.data.k_nominal;
            return m;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t howl_kscnames_max_fresh_role(howl_types_RoleId r, int64_t m) {
    __auto_type _mv_1176 = r;
    switch (_mv_1176.tag) {
        case howl_types_RoleId_fresh_role:
        {
            __auto_type n = _mv_1176.data.fresh_role;
            if (n >= m) {
                return (n + 1);
            } else {
                return m;
            }
        }
        case howl_types_RoleId_named_role:
        {
            __auto_type _ = _mv_1176.data.named_role;
            return m;
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type _ = _mv_1176.data.inverse_role;
            return m;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_kscnames_note_class(slop_arena* arena, howl_kscnames_KscNames nm, howl_types_KName k) {
    __auto_type _mv_1177 = k;
    switch (_mv_1177.tag) {
        case howl_types_KName_k_class:
        {
            __auto_type i = _mv_1177.data.k_class;
            if (howl_kscnames_kept_as_iri(i)) {
                return 0;
            } else {
                __auto_type _mv_1179 = ({ void* _ptr = slop_map_get(nm.classes, &(i)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
                if (_mv_1179.has_value) {
                    __auto_type _ = _mv_1179.value;
                    return 0;
                } else if (!_mv_1179.has_value) {
                    {
                        __auto_type id = (nm.class_base + ((int64_t)(((int64_t)(nm.classes)->len))));
                        ({ int64_t _val = id; slop_map_put(NULL, nm.classes, &(i), &_val, sizeof(_val)); });
                        ({ howl_types_KName _val = ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = howl_types_copy_iri(arena, i) }); slop_map_put(NULL, nm.back, &(int64_t){id}, &_val, sizeof(_val)); });
                        return 1;
                    }
                }
                SLOP_UNREACHABLE();
            }
        }
        case howl_types_KName_k_fresh:
        {
            __auto_type _ = _mv_1177.data.k_fresh;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_kscnames_note_role(slop_arena* arena, howl_kscnames_KscNames nm, howl_types_RoleId r) {
    __auto_type _mv_1182 = r;
    switch (_mv_1182.tag) {
        case howl_types_RoleId_named_role:
        {
            __auto_type i = _mv_1182.data.named_role;
            __auto_type _mv_1184 = ({ void* _ptr = slop_map_get(nm.roles, &(i)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
            if (_mv_1184.has_value) {
                __auto_type _ = _mv_1184.value;
                return 0;
            } else if (!_mv_1184.has_value) {
                {
                    __auto_type id = (nm.role_base + ((int64_t)(((int64_t)(nm.roles)->len))));
                    ({ int64_t _val = id; slop_map_put(NULL, nm.roles, &(i), &_val, sizeof(_val)); });
                    return 1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_1182.data.fresh_role;
            return 0;
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type _ = _mv_1182.data.inverse_role;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_kscnames_note_term(slop_arena* arena, howl_kscnames_KscNames nm, howl_types_KTerm t) {
    __auto_type _mv_1186 = t;
    switch (_mv_1186.tag) {
        case howl_types_KTerm_k_name:
        {
            __auto_type k = _mv_1186.data.k_name;
            return howl_kscnames_note_class(arena, nm, k);
        }
        case howl_types_KTerm_k_nominal:
        {
            __auto_type _ = _mv_1186.data.k_nominal;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

howl_kscnames_KscNames howl_kscnames_build_ksc_names(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes) {
    {
        int64_t fc = 0;
        int64_t fr = 0;
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1187 = ax;
                switch (_mv_1187.tag) {
                    case howl_types_KscAxiom_k_sub:
                    {
                        __auto_type a = _mv_1187.data.k_sub.f0;
                        __auto_type b = _mv_1187.data.k_sub.f1;
                        fc = howl_kscnames_max_fresh_term(b, howl_kscnames_max_fresh_term(a, fc));
                        break;
                    }
                    case howl_types_KscAxiom_k_and:
                    {
                        __auto_type a = _mv_1187.data.k_and.f0;
                        __auto_type b = _mv_1187.data.k_and.f1;
                        __auto_type c = _mv_1187.data.k_and.f2;
                        fc = howl_kscnames_max_fresh_name(c, howl_kscnames_max_fresh_name(b, howl_kscnames_max_fresh_name(a, fc)));
                        break;
                    }
                    case howl_types_KscAxiom_k_some_lhs:
                    {
                        __auto_type r = _mv_1187.data.k_some_lhs.f0;
                        __auto_type a = _mv_1187.data.k_some_lhs.f1;
                        __auto_type c = _mv_1187.data.k_some_lhs.f2;
                        fr = howl_kscnames_max_fresh_role(r, fr);
                        fc = howl_kscnames_max_fresh_name(c, howl_kscnames_max_fresh_name(a, fc));
                        break;
                    }
                    case howl_types_KscAxiom_k_some_rhs:
                    {
                        __auto_type a = _mv_1187.data.k_some_rhs.f0;
                        __auto_type r = _mv_1187.data.k_some_rhs.f1;
                        __auto_type b = _mv_1187.data.k_some_rhs.f2;
                        fr = howl_kscnames_max_fresh_role(r, fr);
                        fc = howl_kscnames_max_fresh_name(b, howl_kscnames_max_fresh_name(a, fc));
                        break;
                    }
                    case howl_types_KscAxiom_k_self_lhs:
                    {
                        __auto_type r = _mv_1187.data.k_self_lhs.f0;
                        __auto_type c = _mv_1187.data.k_self_lhs.f1;
                        fr = howl_kscnames_max_fresh_role(r, fr);
                        fc = howl_kscnames_max_fresh_name(c, fc);
                        break;
                    }
                    case howl_types_KscAxiom_k_self_rhs:
                    {
                        __auto_type a = _mv_1187.data.k_self_rhs.f0;
                        __auto_type r = _mv_1187.data.k_self_rhs.f1;
                        fr = howl_kscnames_max_fresh_role(r, fr);
                        fc = howl_kscnames_max_fresh_name(a, fc);
                        break;
                    }
                    case howl_types_KscAxiom_k_role:
                    {
                        __auto_type r = _mv_1187.data.k_role.f0;
                        __auto_type t = _mv_1187.data.k_role.f1;
                        fr = howl_kscnames_max_fresh_role(t, howl_kscnames_max_fresh_role(r, fr));
                        break;
                    }
                    case howl_types_KscAxiom_k_chain:
                    {
                        __auto_type r = _mv_1187.data.k_chain.f0;
                        __auto_type s = _mv_1187.data.k_chain.f1;
                        __auto_type t = _mv_1187.data.k_chain.f2;
                        fr = howl_kscnames_max_fresh_role(t, howl_kscnames_max_fresh_role(s, howl_kscnames_max_fresh_role(r, fr)));
                        break;
                    }
                    case howl_types_KscAxiom_k_range:
                    {
                        __auto_type r = _mv_1187.data.k_range.f0;
                        __auto_type d = _mv_1187.data.k_range.f1;
                        fr = howl_kscnames_max_fresh_role(r, fr);
                        fc = howl_kscnames_max_fresh_name(d, fc);
                        break;
                    }
                    case howl_types_KscAxiom_k_role_assert:
                    {
                        __auto_type r = _mv_1187.data.k_role_assert.f1;
                        fr = howl_kscnames_max_fresh_role(r, fr);
                        break;
                    }
                }
            }
        }
        {
            __auto_type nm = ((howl_kscnames_KscNames){.classes = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .roles = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .back = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, howl_types_KName); slop_map_new_ptr(arena, 0, &_d); }), .class_base = fc, .role_base = fr});
            {
                __auto_type _coll = axioms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ax = _coll.data[_i];
                    __auto_type _mv_1188 = ax;
                    switch (_mv_1188.tag) {
                        case howl_types_KscAxiom_k_sub:
                        {
                            __auto_type a = _mv_1188.data.k_sub.f0;
                            __auto_type b = _mv_1188.data.k_sub.f1;
                            howl_kscnames_note_term(arena, nm, a);
                            howl_kscnames_note_term(arena, nm, b);
                            break;
                        }
                        case howl_types_KscAxiom_k_and:
                        {
                            __auto_type a = _mv_1188.data.k_and.f0;
                            __auto_type b = _mv_1188.data.k_and.f1;
                            __auto_type c = _mv_1188.data.k_and.f2;
                            howl_kscnames_note_class(arena, nm, a);
                            howl_kscnames_note_class(arena, nm, b);
                            howl_kscnames_note_class(arena, nm, c);
                            break;
                        }
                        case howl_types_KscAxiom_k_some_lhs:
                        {
                            __auto_type r = _mv_1188.data.k_some_lhs.f0;
                            __auto_type a = _mv_1188.data.k_some_lhs.f1;
                            __auto_type c = _mv_1188.data.k_some_lhs.f2;
                            howl_kscnames_note_role(arena, nm, r);
                            howl_kscnames_note_class(arena, nm, a);
                            howl_kscnames_note_class(arena, nm, c);
                            break;
                        }
                        case howl_types_KscAxiom_k_some_rhs:
                        {
                            __auto_type a = _mv_1188.data.k_some_rhs.f0;
                            __auto_type r = _mv_1188.data.k_some_rhs.f1;
                            __auto_type b = _mv_1188.data.k_some_rhs.f2;
                            howl_kscnames_note_class(arena, nm, a);
                            howl_kscnames_note_role(arena, nm, r);
                            howl_kscnames_note_class(arena, nm, b);
                            break;
                        }
                        case howl_types_KscAxiom_k_self_lhs:
                        {
                            __auto_type r = _mv_1188.data.k_self_lhs.f0;
                            __auto_type c = _mv_1188.data.k_self_lhs.f1;
                            howl_kscnames_note_role(arena, nm, r);
                            howl_kscnames_note_class(arena, nm, c);
                            break;
                        }
                        case howl_types_KscAxiom_k_self_rhs:
                        {
                            __auto_type a = _mv_1188.data.k_self_rhs.f0;
                            __auto_type r = _mv_1188.data.k_self_rhs.f1;
                            howl_kscnames_note_class(arena, nm, a);
                            howl_kscnames_note_role(arena, nm, r);
                            break;
                        }
                        case howl_types_KscAxiom_k_role:
                        {
                            __auto_type r = _mv_1188.data.k_role.f0;
                            __auto_type t = _mv_1188.data.k_role.f1;
                            howl_kscnames_note_role(arena, nm, r);
                            howl_kscnames_note_role(arena, nm, t);
                            break;
                        }
                        case howl_types_KscAxiom_k_chain:
                        {
                            __auto_type r = _mv_1188.data.k_chain.f0;
                            __auto_type s = _mv_1188.data.k_chain.f1;
                            __auto_type t = _mv_1188.data.k_chain.f2;
                            howl_kscnames_note_role(arena, nm, r);
                            howl_kscnames_note_role(arena, nm, s);
                            howl_kscnames_note_role(arena, nm, t);
                            break;
                        }
                        case howl_types_KscAxiom_k_range:
                        {
                            __auto_type r = _mv_1188.data.k_range.f0;
                            __auto_type d = _mv_1188.data.k_range.f1;
                            howl_kscnames_note_role(arena, nm, r);
                            howl_kscnames_note_class(arena, nm, d);
                            break;
                        }
                        case howl_types_KscAxiom_k_role_assert:
                        {
                            __auto_type r = _mv_1188.data.k_role_assert.f1;
                            howl_kscnames_note_role(arena, nm, r);
                            break;
                        }
                    }
                }
            }
            {
                __auto_type _coll = classes;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type q = _coll.data[_i];
                    howl_kscnames_note_class(arena, nm, q);
                }
            }
            return nm;
        }
    }
}

howl_types_KName howl_kscnames_rename_class(howl_kscnames_KscNames nm, howl_types_KName k) {
    __auto_type _mv_1189 = k;
    switch (_mv_1189.tag) {
        case howl_types_KName_k_class:
        {
            __auto_type i = _mv_1189.data.k_class;
            __auto_type _mv_1191 = ({ void* _ptr = slop_map_get(nm.classes, &(i)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
            if (_mv_1191.has_value) {
                __auto_type id = _mv_1191.value;
                return ((howl_types_KName){ .tag = howl_types_KName_k_fresh, .data.k_fresh = ((int64_t)(SLOP_RANGE(int64_t, id, 1, 0, 0, 0, "(Int 0 ..) at kscnames.slop:166:64"))) });
            } else if (!_mv_1191.has_value) {
                return k;
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_KName_k_fresh:
        {
            __auto_type _ = _mv_1189.data.k_fresh;
            return k;
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_KTerm howl_kscnames_rename_term(howl_kscnames_KscNames nm, howl_types_KTerm t) {
    __auto_type _mv_1192 = t;
    switch (_mv_1192.tag) {
        case howl_types_KTerm_k_name:
        {
            __auto_type k = _mv_1192.data.k_name;
            return ((howl_types_KTerm){ .tag = howl_types_KTerm_k_name, .data.k_name = howl_kscnames_rename_class(nm, k) });
        }
        case howl_types_KTerm_k_nominal:
        {
            __auto_type _ = _mv_1192.data.k_nominal;
            return t;
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_RoleId howl_kscnames_rename_role(howl_kscnames_KscNames nm, howl_types_RoleId r) {
    __auto_type _mv_1193 = r;
    switch (_mv_1193.tag) {
        case howl_types_RoleId_named_role:
        {
            __auto_type i = _mv_1193.data.named_role;
            __auto_type _mv_1195 = ({ void* _ptr = slop_map_get(nm.roles, &(i)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
            if (_mv_1195.has_value) {
                __auto_type id = _mv_1195.value;
                return ((howl_types_RoleId){ .tag = howl_types_RoleId_fresh_role, .data.fresh_role = ((int64_t)(SLOP_RANGE(int64_t, id, 1, 0, 0, 0, "(Int 0 ..) at kscnames.slop:183:68"))) });
            } else if (!_mv_1195.has_value) {
                return r;
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_1193.data.fresh_role;
            return r;
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type _ = _mv_1193.data.inverse_role;
            return r;
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_KscAxiom howl_kscnames_rename_axiom(howl_kscnames_KscNames nm, howl_types_KscAxiom ax) {
    __auto_type _mv_1196 = ax;
    switch (_mv_1196.tag) {
        case howl_types_KscAxiom_k_sub:
        {
            __auto_type a = _mv_1196.data.k_sub.f0;
            __auto_type b = _mv_1196.data.k_sub.f1;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_sub, .data.k_sub = { .f0 = howl_kscnames_rename_term(nm, a), .f1 = howl_kscnames_rename_term(nm, b) } });
        }
        case howl_types_KscAxiom_k_and:
        {
            __auto_type a = _mv_1196.data.k_and.f0;
            __auto_type b = _mv_1196.data.k_and.f1;
            __auto_type c = _mv_1196.data.k_and.f2;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_and, .data.k_and = { .f0 = howl_kscnames_rename_class(nm, a), .f1 = howl_kscnames_rename_class(nm, b), .f2 = howl_kscnames_rename_class(nm, c) } });
        }
        case howl_types_KscAxiom_k_some_lhs:
        {
            __auto_type r = _mv_1196.data.k_some_lhs.f0;
            __auto_type a = _mv_1196.data.k_some_lhs.f1;
            __auto_type c = _mv_1196.data.k_some_lhs.f2;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_some_lhs, .data.k_some_lhs = { .f0 = howl_kscnames_rename_role(nm, r), .f1 = howl_kscnames_rename_class(nm, a), .f2 = howl_kscnames_rename_class(nm, c) } });
        }
        case howl_types_KscAxiom_k_some_rhs:
        {
            __auto_type a = _mv_1196.data.k_some_rhs.f0;
            __auto_type r = _mv_1196.data.k_some_rhs.f1;
            __auto_type b = _mv_1196.data.k_some_rhs.f2;
            __auto_type w = _mv_1196.data.k_some_rhs.f3;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_some_rhs, .data.k_some_rhs = { .f0 = howl_kscnames_rename_class(nm, a), .f1 = howl_kscnames_rename_role(nm, r), .f2 = howl_kscnames_rename_class(nm, b), .f3 = w } });
        }
        case howl_types_KscAxiom_k_self_lhs:
        {
            __auto_type r = _mv_1196.data.k_self_lhs.f0;
            __auto_type c = _mv_1196.data.k_self_lhs.f1;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_self_lhs, .data.k_self_lhs = { .f0 = howl_kscnames_rename_role(nm, r), .f1 = howl_kscnames_rename_class(nm, c) } });
        }
        case howl_types_KscAxiom_k_self_rhs:
        {
            __auto_type a = _mv_1196.data.k_self_rhs.f0;
            __auto_type r = _mv_1196.data.k_self_rhs.f1;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_self_rhs, .data.k_self_rhs = { .f0 = howl_kscnames_rename_class(nm, a), .f1 = howl_kscnames_rename_role(nm, r) } });
        }
        case howl_types_KscAxiom_k_role:
        {
            __auto_type r = _mv_1196.data.k_role.f0;
            __auto_type t = _mv_1196.data.k_role.f1;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_role, .data.k_role = { .f0 = howl_kscnames_rename_role(nm, r), .f1 = howl_kscnames_rename_role(nm, t) } });
        }
        case howl_types_KscAxiom_k_chain:
        {
            __auto_type r = _mv_1196.data.k_chain.f0;
            __auto_type s = _mv_1196.data.k_chain.f1;
            __auto_type t = _mv_1196.data.k_chain.f2;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_chain, .data.k_chain = { .f0 = howl_kscnames_rename_role(nm, r), .f1 = howl_kscnames_rename_role(nm, s), .f2 = howl_kscnames_rename_role(nm, t) } });
        }
        case howl_types_KscAxiom_k_range:
        {
            __auto_type r = _mv_1196.data.k_range.f0;
            __auto_type d = _mv_1196.data.k_range.f1;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_range, .data.k_range = { .f0 = howl_kscnames_rename_role(nm, r), .f1 = howl_kscnames_rename_class(nm, d) } });
        }
        case howl_types_KscAxiom_k_role_assert:
        {
            __auto_type a = _mv_1196.data.k_role_assert.f0;
            __auto_type r = _mv_1196.data.k_role_assert.f1;
            __auto_type b = _mv_1196.data.k_role_assert.f2;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_role_assert, .data.k_role_assert = { .f0 = a, .f1 = howl_kscnames_rename_role(nm, r), .f2 = b } });
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_KscAxiom howl_kscnames_rename_ksc_axioms(slop_arena* arena, howl_kscnames_KscNames nm, slop_list_howl_types_KscAxiom axioms) {
    {
        __auto_type out = ((slop_list_howl_types_KscAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_kscnames_rename_axiom(nm, ax)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_types_KName howl_kscnames_rename_classes(slop_arena* arena, howl_kscnames_KscNames nm, slop_list_howl_types_KName classes) {
    {
        __auto_type out = ((slop_list_howl_types_KName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_kscnames_rename_class(nm, q)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_types_KName howl_kscnames_unrename_class(howl_kscnames_KscNames nm, howl_types_KName k) {
    __auto_type _mv_1197 = k;
    switch (_mv_1197.tag) {
        case howl_types_KName_k_fresh:
        {
            __auto_type n = _mv_1197.data.k_fresh;
            __auto_type _mv_1199 = ({ void* _ptr = slop_map_get(nm.back, &(int64_t){n}); _ptr ? (slop_option_howl_types_KName){ .has_value = true, .value = *(howl_types_KName*)_ptr } : (slop_option_howl_types_KName){ .has_value = false }; });
            if (_mv_1199.has_value) {
                __auto_type orig = _mv_1199.value;
                return orig;
            } else if (!_mv_1199.has_value) {
                return k;
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_KName_k_class:
        {
            __auto_type _ = _mv_1197.data.k_class;
            return k;
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_ClassAnswer howl_kscnames_unrename_answer(slop_arena* arena, howl_kscnames_KscNames nm, howl_types_ClassAnswer a) {
    {
        __auto_type subs = ((slop_list_howl_types_KName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = a.subsumers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(subs); __auto_type _item = (howl_kscnames_unrename_class(nm, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ((howl_types_ClassAnswer){.cls = howl_kscnames_unrename_class(nm, a.cls), .shared = a.shared, .unsat = a.unsat, .subsumers = subs, .complete = a.complete, .rounds = a.rounds, .facts = a.facts});
    }
}

