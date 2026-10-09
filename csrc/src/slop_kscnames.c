#include "../runtime/slop_runtime.h"
#include "slop_kscnames.h"

uint8_t kscnames_kept_as_iri(rdf_IRI i);
int64_t kscnames_max_fresh_name(types_KName k, int64_t m);
int64_t kscnames_max_fresh_term(types_KTerm t, int64_t m);
int64_t kscnames_max_fresh_role(types_RoleId r, int64_t m);
uint8_t kscnames_note_class(slop_arena* arena, kscnames_KscNames nm, types_KName k);
uint8_t kscnames_note_role(slop_arena* arena, kscnames_KscNames nm, types_RoleId r);
uint8_t kscnames_note_term(slop_arena* arena, kscnames_KscNames nm, types_KTerm t);
kscnames_KscNames kscnames_build_ksc_names(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes);
types_KName kscnames_rename_class(kscnames_KscNames nm, types_KName k);
types_KTerm kscnames_rename_term(kscnames_KscNames nm, types_KTerm t);
types_RoleId kscnames_rename_role(kscnames_KscNames nm, types_RoleId r);
types_KscAxiom kscnames_rename_axiom(kscnames_KscNames nm, types_KscAxiom ax);
slop_list_types_KscAxiom kscnames_rename_ksc_axioms(slop_arena* arena, kscnames_KscNames nm, slop_list_types_KscAxiom axioms);
slop_list_types_KName kscnames_rename_classes(slop_arena* arena, kscnames_KscNames nm, slop_list_types_KName classes);
types_KName kscnames_unrename_class(kscnames_KscNames nm, types_KName k);
types_ClassAnswer kscnames_unrename_answer(slop_arena* arena, kscnames_KscNames nm, types_ClassAnswer a);

uint8_t kscnames_kept_as_iri(rdf_IRI i) {
    if (string_eq(i.value, vocab_OWL_THING)) {
        return 1;
    } else {
        return string_eq(i.value, vocab_OWL_NOTHING);
    }
}

int64_t kscnames_max_fresh_name(types_KName k, int64_t m) {
    __auto_type _mv_385 = k;
    switch (_mv_385.tag) {
        case types_KName_k_fresh:
        {
            __auto_type n = _mv_385.data.k_fresh;
            if (n >= m) {
                return (n + 1);
            } else {
                return m;
            }
        }
        case types_KName_k_class:
        {
            __auto_type _ = _mv_385.data.k_class;
            return m;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t kscnames_max_fresh_term(types_KTerm t, int64_t m) {
    __auto_type _mv_386 = t;
    switch (_mv_386.tag) {
        case types_KTerm_k_name:
        {
            __auto_type k = _mv_386.data.k_name;
            return kscnames_max_fresh_name(k, m);
        }
        case types_KTerm_k_nominal:
        {
            __auto_type _ = _mv_386.data.k_nominal;
            return m;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t kscnames_max_fresh_role(types_RoleId r, int64_t m) {
    __auto_type _mv_387 = r;
    switch (_mv_387.tag) {
        case types_RoleId_fresh_role:
        {
            __auto_type n = _mv_387.data.fresh_role;
            if (n >= m) {
                return (n + 1);
            } else {
                return m;
            }
        }
        case types_RoleId_named_role:
        {
            __auto_type _ = _mv_387.data.named_role;
            return m;
        }
        case types_RoleId_inverse_role:
        {
            __auto_type _ = _mv_387.data.inverse_role;
            return m;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t kscnames_note_class(slop_arena* arena, kscnames_KscNames nm, types_KName k) {
    __auto_type _mv_388 = k;
    switch (_mv_388.tag) {
        case types_KName_k_class:
        {
            __auto_type i = _mv_388.data.k_class;
            if (kscnames_kept_as_iri(i)) {
                return 0;
            } else {
                __auto_type _mv_390 = ({ void* _ptr = slop_map_get(nm.classes, &(i)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
                if (_mv_390.has_value) {
                    __auto_type _ = _mv_390.value;
                    return 0;
                } else if (!_mv_390.has_value) {
                    {
                        __auto_type id = (nm.class_base + ((int64_t)(((int64_t)(nm.classes)->len))));
                        ({ int64_t _val = id; slop_map_put(NULL, nm.classes, &(i), &_val, sizeof(_val)); });
                        ({ types_KName _val = ((types_KName){ .tag = types_KName_k_class, .data.k_class = types_copy_iri(arena, i) }); slop_map_put(NULL, nm.back, &(int64_t){id}, &_val, sizeof(_val)); });
                        return 1;
                    }
                }
                SLOP_UNREACHABLE();
            }
        }
        case types_KName_k_fresh:
        {
            __auto_type _ = _mv_388.data.k_fresh;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t kscnames_note_role(slop_arena* arena, kscnames_KscNames nm, types_RoleId r) {
    __auto_type _mv_393 = r;
    switch (_mv_393.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_393.data.named_role;
            __auto_type _mv_395 = ({ void* _ptr = slop_map_get(nm.roles, &(i)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
            if (_mv_395.has_value) {
                __auto_type _ = _mv_395.value;
                return 0;
            } else if (!_mv_395.has_value) {
                {
                    __auto_type id = (nm.role_base + ((int64_t)(((int64_t)(nm.roles)->len))));
                    ({ int64_t _val = id; slop_map_put(NULL, nm.roles, &(i), &_val, sizeof(_val)); });
                    return 1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_393.data.fresh_role;
            return 0;
        }
        case types_RoleId_inverse_role:
        {
            __auto_type _ = _mv_393.data.inverse_role;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t kscnames_note_term(slop_arena* arena, kscnames_KscNames nm, types_KTerm t) {
    __auto_type _mv_397 = t;
    switch (_mv_397.tag) {
        case types_KTerm_k_name:
        {
            __auto_type k = _mv_397.data.k_name;
            return kscnames_note_class(arena, nm, k);
        }
        case types_KTerm_k_nominal:
        {
            __auto_type _ = _mv_397.data.k_nominal;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

kscnames_KscNames kscnames_build_ksc_names(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes) {
    {
        int64_t fc = 0;
        int64_t fr = 0;
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_398 = ax;
                switch (_mv_398.tag) {
                    case types_KscAxiom_k_sub:
                    {
                        __auto_type a = _mv_398.data.k_sub.f0;
                        __auto_type b = _mv_398.data.k_sub.f1;
                        fc = kscnames_max_fresh_term(b, kscnames_max_fresh_term(a, fc));
                        break;
                    }
                    case types_KscAxiom_k_and:
                    {
                        __auto_type a = _mv_398.data.k_and.f0;
                        __auto_type b = _mv_398.data.k_and.f1;
                        __auto_type c = _mv_398.data.k_and.f2;
                        fc = kscnames_max_fresh_name(c, kscnames_max_fresh_name(b, kscnames_max_fresh_name(a, fc)));
                        break;
                    }
                    case types_KscAxiom_k_some_lhs:
                    {
                        __auto_type r = _mv_398.data.k_some_lhs.f0;
                        __auto_type a = _mv_398.data.k_some_lhs.f1;
                        __auto_type c = _mv_398.data.k_some_lhs.f2;
                        fr = kscnames_max_fresh_role(r, fr);
                        fc = kscnames_max_fresh_name(c, kscnames_max_fresh_name(a, fc));
                        break;
                    }
                    case types_KscAxiom_k_some_rhs:
                    {
                        __auto_type a = _mv_398.data.k_some_rhs.f0;
                        __auto_type r = _mv_398.data.k_some_rhs.f1;
                        __auto_type b = _mv_398.data.k_some_rhs.f2;
                        fr = kscnames_max_fresh_role(r, fr);
                        fc = kscnames_max_fresh_name(b, kscnames_max_fresh_name(a, fc));
                        break;
                    }
                    case types_KscAxiom_k_self_lhs:
                    {
                        __auto_type r = _mv_398.data.k_self_lhs.f0;
                        __auto_type c = _mv_398.data.k_self_lhs.f1;
                        fr = kscnames_max_fresh_role(r, fr);
                        fc = kscnames_max_fresh_name(c, fc);
                        break;
                    }
                    case types_KscAxiom_k_self_rhs:
                    {
                        __auto_type a = _mv_398.data.k_self_rhs.f0;
                        __auto_type r = _mv_398.data.k_self_rhs.f1;
                        fr = kscnames_max_fresh_role(r, fr);
                        fc = kscnames_max_fresh_name(a, fc);
                        break;
                    }
                    case types_KscAxiom_k_role:
                    {
                        __auto_type r = _mv_398.data.k_role.f0;
                        __auto_type t = _mv_398.data.k_role.f1;
                        fr = kscnames_max_fresh_role(t, kscnames_max_fresh_role(r, fr));
                        break;
                    }
                    case types_KscAxiom_k_chain:
                    {
                        __auto_type r = _mv_398.data.k_chain.f0;
                        __auto_type s = _mv_398.data.k_chain.f1;
                        __auto_type t = _mv_398.data.k_chain.f2;
                        fr = kscnames_max_fresh_role(t, kscnames_max_fresh_role(s, kscnames_max_fresh_role(r, fr)));
                        break;
                    }
                    case types_KscAxiom_k_range:
                    {
                        __auto_type r = _mv_398.data.k_range.f0;
                        __auto_type d = _mv_398.data.k_range.f1;
                        fr = kscnames_max_fresh_role(r, fr);
                        fc = kscnames_max_fresh_name(d, fc);
                        break;
                    }
                    case types_KscAxiom_k_role_assert:
                    {
                        __auto_type r = _mv_398.data.k_role_assert.f1;
                        fr = kscnames_max_fresh_role(r, fr);
                        break;
                    }
                }
            }
        }
        {
            __auto_type nm = ((kscnames_KscNames){.classes = ({ static const slop_map_desc _d = SLOP_MAP_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .roles = ({ static const slop_map_desc _d = SLOP_MAP_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .back = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, types_KName); slop_map_new_ptr(arena, 0, &_d); }), .class_base = fc, .role_base = fr});
            {
                __auto_type _coll = axioms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ax = _coll.data[_i];
                    __auto_type _mv_399 = ax;
                    switch (_mv_399.tag) {
                        case types_KscAxiom_k_sub:
                        {
                            __auto_type a = _mv_399.data.k_sub.f0;
                            __auto_type b = _mv_399.data.k_sub.f1;
                            kscnames_note_term(arena, nm, a);
                            kscnames_note_term(arena, nm, b);
                            break;
                        }
                        case types_KscAxiom_k_and:
                        {
                            __auto_type a = _mv_399.data.k_and.f0;
                            __auto_type b = _mv_399.data.k_and.f1;
                            __auto_type c = _mv_399.data.k_and.f2;
                            kscnames_note_class(arena, nm, a);
                            kscnames_note_class(arena, nm, b);
                            kscnames_note_class(arena, nm, c);
                            break;
                        }
                        case types_KscAxiom_k_some_lhs:
                        {
                            __auto_type r = _mv_399.data.k_some_lhs.f0;
                            __auto_type a = _mv_399.data.k_some_lhs.f1;
                            __auto_type c = _mv_399.data.k_some_lhs.f2;
                            kscnames_note_role(arena, nm, r);
                            kscnames_note_class(arena, nm, a);
                            kscnames_note_class(arena, nm, c);
                            break;
                        }
                        case types_KscAxiom_k_some_rhs:
                        {
                            __auto_type a = _mv_399.data.k_some_rhs.f0;
                            __auto_type r = _mv_399.data.k_some_rhs.f1;
                            __auto_type b = _mv_399.data.k_some_rhs.f2;
                            kscnames_note_class(arena, nm, a);
                            kscnames_note_role(arena, nm, r);
                            kscnames_note_class(arena, nm, b);
                            break;
                        }
                        case types_KscAxiom_k_self_lhs:
                        {
                            __auto_type r = _mv_399.data.k_self_lhs.f0;
                            __auto_type c = _mv_399.data.k_self_lhs.f1;
                            kscnames_note_role(arena, nm, r);
                            kscnames_note_class(arena, nm, c);
                            break;
                        }
                        case types_KscAxiom_k_self_rhs:
                        {
                            __auto_type a = _mv_399.data.k_self_rhs.f0;
                            __auto_type r = _mv_399.data.k_self_rhs.f1;
                            kscnames_note_class(arena, nm, a);
                            kscnames_note_role(arena, nm, r);
                            break;
                        }
                        case types_KscAxiom_k_role:
                        {
                            __auto_type r = _mv_399.data.k_role.f0;
                            __auto_type t = _mv_399.data.k_role.f1;
                            kscnames_note_role(arena, nm, r);
                            kscnames_note_role(arena, nm, t);
                            break;
                        }
                        case types_KscAxiom_k_chain:
                        {
                            __auto_type r = _mv_399.data.k_chain.f0;
                            __auto_type s = _mv_399.data.k_chain.f1;
                            __auto_type t = _mv_399.data.k_chain.f2;
                            kscnames_note_role(arena, nm, r);
                            kscnames_note_role(arena, nm, s);
                            kscnames_note_role(arena, nm, t);
                            break;
                        }
                        case types_KscAxiom_k_range:
                        {
                            __auto_type r = _mv_399.data.k_range.f0;
                            __auto_type d = _mv_399.data.k_range.f1;
                            kscnames_note_role(arena, nm, r);
                            kscnames_note_class(arena, nm, d);
                            break;
                        }
                        case types_KscAxiom_k_role_assert:
                        {
                            __auto_type r = _mv_399.data.k_role_assert.f1;
                            kscnames_note_role(arena, nm, r);
                            break;
                        }
                    }
                }
            }
            {
                __auto_type _coll = classes;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type q = _coll.data[_i];
                    kscnames_note_class(arena, nm, q);
                }
            }
            return nm;
        }
    }
}

types_KName kscnames_rename_class(kscnames_KscNames nm, types_KName k) {
    __auto_type _mv_400 = k;
    switch (_mv_400.tag) {
        case types_KName_k_class:
        {
            __auto_type i = _mv_400.data.k_class;
            __auto_type _mv_402 = ({ void* _ptr = slop_map_get(nm.classes, &(i)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
            if (_mv_402.has_value) {
                __auto_type id = _mv_402.value;
                return ((types_KName){ .tag = types_KName_k_fresh, .data.k_fresh = ((int64_t)(SLOP_RANGE(int64_t, id, 1, 0, 0, 0, "(Int 0 ..) at kscnames.slop:166:64"))) });
            } else if (!_mv_402.has_value) {
                return k;
            }
            SLOP_UNREACHABLE();
        }
        case types_KName_k_fresh:
        {
            __auto_type _ = _mv_400.data.k_fresh;
            return k;
        }
    }
    SLOP_UNREACHABLE();
}

types_KTerm kscnames_rename_term(kscnames_KscNames nm, types_KTerm t) {
    __auto_type _mv_403 = t;
    switch (_mv_403.tag) {
        case types_KTerm_k_name:
        {
            __auto_type k = _mv_403.data.k_name;
            return ((types_KTerm){ .tag = types_KTerm_k_name, .data.k_name = kscnames_rename_class(nm, k) });
        }
        case types_KTerm_k_nominal:
        {
            __auto_type _ = _mv_403.data.k_nominal;
            return t;
        }
    }
    SLOP_UNREACHABLE();
}

types_RoleId kscnames_rename_role(kscnames_KscNames nm, types_RoleId r) {
    __auto_type _mv_404 = r;
    switch (_mv_404.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_404.data.named_role;
            __auto_type _mv_406 = ({ void* _ptr = slop_map_get(nm.roles, &(i)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
            if (_mv_406.has_value) {
                __auto_type id = _mv_406.value;
                return ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = ((int64_t)(SLOP_RANGE(int64_t, id, 1, 0, 0, 0, "(Int 0 ..) at kscnames.slop:183:68"))) });
            } else if (!_mv_406.has_value) {
                return r;
            }
            SLOP_UNREACHABLE();
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_404.data.fresh_role;
            return r;
        }
        case types_RoleId_inverse_role:
        {
            __auto_type _ = _mv_404.data.inverse_role;
            return r;
        }
    }
    SLOP_UNREACHABLE();
}

types_KscAxiom kscnames_rename_axiom(kscnames_KscNames nm, types_KscAxiom ax) {
    __auto_type _mv_407 = ax;
    switch (_mv_407.tag) {
        case types_KscAxiom_k_sub:
        {
            __auto_type a = _mv_407.data.k_sub.f0;
            __auto_type b = _mv_407.data.k_sub.f1;
            return ((types_KscAxiom){ .tag = types_KscAxiom_k_sub, .data.k_sub = { .f0 = kscnames_rename_term(nm, a), .f1 = kscnames_rename_term(nm, b) } });
        }
        case types_KscAxiom_k_and:
        {
            __auto_type a = _mv_407.data.k_and.f0;
            __auto_type b = _mv_407.data.k_and.f1;
            __auto_type c = _mv_407.data.k_and.f2;
            return ((types_KscAxiom){ .tag = types_KscAxiom_k_and, .data.k_and = { .f0 = kscnames_rename_class(nm, a), .f1 = kscnames_rename_class(nm, b), .f2 = kscnames_rename_class(nm, c) } });
        }
        case types_KscAxiom_k_some_lhs:
        {
            __auto_type r = _mv_407.data.k_some_lhs.f0;
            __auto_type a = _mv_407.data.k_some_lhs.f1;
            __auto_type c = _mv_407.data.k_some_lhs.f2;
            return ((types_KscAxiom){ .tag = types_KscAxiom_k_some_lhs, .data.k_some_lhs = { .f0 = kscnames_rename_role(nm, r), .f1 = kscnames_rename_class(nm, a), .f2 = kscnames_rename_class(nm, c) } });
        }
        case types_KscAxiom_k_some_rhs:
        {
            __auto_type a = _mv_407.data.k_some_rhs.f0;
            __auto_type r = _mv_407.data.k_some_rhs.f1;
            __auto_type b = _mv_407.data.k_some_rhs.f2;
            __auto_type w = _mv_407.data.k_some_rhs.f3;
            return ((types_KscAxiom){ .tag = types_KscAxiom_k_some_rhs, .data.k_some_rhs = { .f0 = kscnames_rename_class(nm, a), .f1 = kscnames_rename_role(nm, r), .f2 = kscnames_rename_class(nm, b), .f3 = w } });
        }
        case types_KscAxiom_k_self_lhs:
        {
            __auto_type r = _mv_407.data.k_self_lhs.f0;
            __auto_type c = _mv_407.data.k_self_lhs.f1;
            return ((types_KscAxiom){ .tag = types_KscAxiom_k_self_lhs, .data.k_self_lhs = { .f0 = kscnames_rename_role(nm, r), .f1 = kscnames_rename_class(nm, c) } });
        }
        case types_KscAxiom_k_self_rhs:
        {
            __auto_type a = _mv_407.data.k_self_rhs.f0;
            __auto_type r = _mv_407.data.k_self_rhs.f1;
            return ((types_KscAxiom){ .tag = types_KscAxiom_k_self_rhs, .data.k_self_rhs = { .f0 = kscnames_rename_class(nm, a), .f1 = kscnames_rename_role(nm, r) } });
        }
        case types_KscAxiom_k_role:
        {
            __auto_type r = _mv_407.data.k_role.f0;
            __auto_type t = _mv_407.data.k_role.f1;
            return ((types_KscAxiom){ .tag = types_KscAxiom_k_role, .data.k_role = { .f0 = kscnames_rename_role(nm, r), .f1 = kscnames_rename_role(nm, t) } });
        }
        case types_KscAxiom_k_chain:
        {
            __auto_type r = _mv_407.data.k_chain.f0;
            __auto_type s = _mv_407.data.k_chain.f1;
            __auto_type t = _mv_407.data.k_chain.f2;
            return ((types_KscAxiom){ .tag = types_KscAxiom_k_chain, .data.k_chain = { .f0 = kscnames_rename_role(nm, r), .f1 = kscnames_rename_role(nm, s), .f2 = kscnames_rename_role(nm, t) } });
        }
        case types_KscAxiom_k_range:
        {
            __auto_type r = _mv_407.data.k_range.f0;
            __auto_type d = _mv_407.data.k_range.f1;
            return ((types_KscAxiom){ .tag = types_KscAxiom_k_range, .data.k_range = { .f0 = kscnames_rename_role(nm, r), .f1 = kscnames_rename_class(nm, d) } });
        }
        case types_KscAxiom_k_role_assert:
        {
            __auto_type a = _mv_407.data.k_role_assert.f0;
            __auto_type r = _mv_407.data.k_role_assert.f1;
            __auto_type b = _mv_407.data.k_role_assert.f2;
            return ((types_KscAxiom){ .tag = types_KscAxiom_k_role_assert, .data.k_role_assert = { .f0 = a, .f1 = kscnames_rename_role(nm, r), .f2 = b } });
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_types_KscAxiom kscnames_rename_ksc_axioms(slop_arena* arena, kscnames_KscNames nm, slop_list_types_KscAxiom axioms) {
    {
        __auto_type out = ((slop_list_types_KscAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (kscnames_rename_axiom(nm, ax)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_KName kscnames_rename_classes(slop_arena* arena, kscnames_KscNames nm, slop_list_types_KName classes) {
    {
        __auto_type out = ((slop_list_types_KName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (kscnames_rename_class(nm, q)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

types_KName kscnames_unrename_class(kscnames_KscNames nm, types_KName k) {
    __auto_type _mv_408 = k;
    switch (_mv_408.tag) {
        case types_KName_k_fresh:
        {
            __auto_type n = _mv_408.data.k_fresh;
            __auto_type _mv_410 = ({ void* _ptr = slop_map_get(nm.back, &(int64_t){n}); _ptr ? (slop_option_types_KName){ .has_value = true, .value = *(types_KName*)_ptr } : (slop_option_types_KName){ .has_value = false }; });
            if (_mv_410.has_value) {
                __auto_type orig = _mv_410.value;
                return orig;
            } else if (!_mv_410.has_value) {
                return k;
            }
            SLOP_UNREACHABLE();
        }
        case types_KName_k_class:
        {
            __auto_type _ = _mv_408.data.k_class;
            return k;
        }
    }
    SLOP_UNREACHABLE();
}

types_ClassAnswer kscnames_unrename_answer(slop_arena* arena, kscnames_KscNames nm, types_ClassAnswer a) {
    {
        __auto_type subs = ((slop_list_types_KName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = a.subsumers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                ({ __auto_type _lst_p = &(subs); __auto_type _item = (kscnames_unrename_class(nm, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((types_ClassAnswer){.cls = kscnames_unrename_class(nm, a.cls), .shared = a.shared, .unsat = a.unsat, .subsumers = subs, .complete = a.complete, .rounds = a.rounds, .facts = a.facts});
    }
}

