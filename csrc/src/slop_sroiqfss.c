#include "../runtime/slop_runtime.h"
#include "slop_sroiqfss.h"

static const slop_string sroiqfss_OWL_NS_PREFIX = SLOP_STR("http://www.w3.org/2002/07/owl#");

slop_string sroiqfss_angle(slop_arena* arena, slop_string v);
slop_string sroiqfss_call1(slop_arena* arena, slop_string f, slop_string a);
slop_string sroiqfss_call2(slop_arena* arena, slop_string f, slop_string a, slop_string b);
slop_string sroiqfss_call3(slop_arena* arena, slop_string f, slop_string a, slop_string b, slop_string c);
slop_string sroiqfss_joined(slop_arena* arena, slop_list_string parts);
slop_string sroiqfss_junction(slop_arena* arena, slop_string f, slop_list_string parts, slop_string empty);
slop_string sroiqfss_thing(slop_arena* arena);
slop_string sroiqfss_nothing(slop_arena* arena);
slop_string sroiqfss_role_text(slop_arena* arena, types_RoleId r);
slop_list_string sroiqfss_concepts_text(slop_arena* arena, slop_list_sroiq_SConcept atoms, slop_list_sroiq_SConcept cs);
slop_string sroiqfss_concept_text(slop_arena* arena, slop_list_sroiq_SConcept atoms, sroiq_SConcept c);
slop_list_string sroiqfss_roles_text(slop_arena* arena, slop_list_types_RoleId rs);
slop_string sroiqfss_ria_text(slop_arena* arena, sroiq_SRia x);
slop_string sroiqfss_axiom_text(slop_arena* arena, slop_list_sroiq_SConcept atoms, sroiq_SAxiom a);
slop_list_sroiq_SConcept sroiqfss_atoms_in(slop_arena* arena, sroiq_SConcept c);
slop_list_sroiq_SConcept sroiqfss_atoms_in_all(slop_arena* arena, slop_list_sroiq_SConcept cs);
sroiq_SConcept sroiqfss_atom_at(slop_list_sroiq_SConcept xs, int64_t i);
slop_list_sroiq_SConcept sroiqfss_document_atoms(slop_arena* arena, slop_list_sroiq_SAxiom axs);
int64_t sroiqfss_atom_index(slop_list_sroiq_SConcept atoms, sroiq_SConcept c);
slop_string sroiqfss_atom_iri(slop_arena* arena, slop_list_sroiq_SConcept atoms, sroiq_SConcept c);
slop_list_string sroiqfss_declare(slop_arena* arena, slop_string kind, slop_string v);
slop_list_string sroiqfss_role_decls(slop_arena* arena, types_RoleId r);
slop_list_string sroiqfss_concept_decls(slop_arena* arena, slop_list_sroiq_SConcept atoms, sroiq_SConcept c);
slop_list_string sroiqfss_concepts_decls(slop_arena* arena, slop_list_sroiq_SConcept atoms, slop_list_sroiq_SConcept cs);
slop_list_string sroiqfss_append2(slop_arena* arena, slop_list_string a, slop_list_string b);
slop_list_string sroiqfss_axiom_decls(slop_arena* arena, slop_list_sroiq_SConcept atoms, sroiq_SAxiom a);
slop_list_string sroiqfss_unique_sorted(slop_arena* arena, slop_list_string xs);
slop_list_string sroiqfss_document(slop_arena* arena, slop_list_string decls, slop_list_string axioms);
slop_list_string sroiqfss_class_decls(slop_arena* arena, slop_list_rdf_IRI classes);
slop_list_string sroiqfss_fss_axioms(slop_arena* arena, slop_list_rdf_IRI classes, slop_list_sroiq_SAxiom axs);
slop_string sroiqfss_fresh_iri(slop_arena* arena, int64_t k);
int64_t sroiqfss_bar_index(slop_list_rdf_IRI bars, rdf_IRI p);
slop_string sroiqfss_bar_iri(slop_arena* arena, slop_list_rdf_IRI bars, rdf_IRI p);
slop_string sroiqfss_dname_iri(slop_arena* arena, types_DName n);
slop_string sroiqfss_dname_text(slop_arena* arena, types_DName n);
slop_string sroiqfss_drole_iri(slop_arena* arena, slop_list_rdf_IRI bars, types_DRole r);
slop_string sroiqfss_drole_text(slop_arena* arena, slop_list_rdf_IRI bars, types_DRole r);
slop_list_string sroiqfss_dnames_text(slop_arena* arena, slop_list_types_DName ns);
slop_string sroiqfss_filler_text(slop_arena* arena, slop_option_types_DName b);
slop_string sroiqfss_count_text(slop_arena* arena, slop_string f, int64_t n, slop_string role, slop_string filler);
slop_string sroiqfss_clause_text(slop_arena* arena, slop_list_rdf_IRI bars, types_DlClause c);
slop_list_string sroiqfss_dname_decls(slop_arena* arena, types_DName n);
slop_list_string sroiqfss_filler_decls(slop_arena* arena, slop_option_types_DName b);
slop_list_string sroiqfss_drole_decls(slop_arena* arena, slop_list_rdf_IRI bars, types_DRole r);
slop_list_string sroiqfss_dnames_decls(slop_arena* arena, slop_list_types_DName ns);
slop_list_string sroiqfss_clause_decls(slop_arena* arena, slop_list_rdf_IRI bars, types_DlClause c);
slop_list_string sroiqfss_fss_normal(slop_arena* arena, sriqnames_SriqNormal n);

typedef struct { slop_list_sroiq_SConcept* all; } sroiqfss__lambda_1314_env_t;

static int64_t sroiqfss__lambda_1314(sroiqfss__lambda_1314_env_t* _env, int64_t i, int64_t j) { return sroiq_sc_cmp(sroiqfss_atom_at((*_env->all), i), sroiqfss_atom_at((*_env->all), j)); }

slop_string sroiqfss_angle(slop_arena* arena, slop_string v) {
    return string_concat(arena, SLOP_STR("<"), string_concat(arena, v, SLOP_STR(">")));
}

slop_string sroiqfss_call1(slop_arena* arena, slop_string f, slop_string a) {
    return string_concat(arena, f, string_concat(arena, SLOP_STR("("), string_concat(arena, a, SLOP_STR(")"))));
}

slop_string sroiqfss_call2(slop_arena* arena, slop_string f, slop_string a, slop_string b) {
    return sroiqfss_call1(arena, f, string_concat(arena, a, string_concat(arena, SLOP_STR(" "), b)));
}

slop_string sroiqfss_call3(slop_arena* arena, slop_string f, slop_string a, slop_string b, slop_string c) {
    return sroiqfss_call2(arena, f, a, string_concat(arena, b, string_concat(arena, SLOP_STR(" "), c)));
}

slop_string sroiqfss_joined(slop_arena* arena, slop_list_string parts) {
    {
        __auto_type out = SLOP_STR("");
        uint8_t first = 1;
        {
            __auto_type _coll = parts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (!(first)) {
                    out = string_concat(arena, out, SLOP_STR(" "));
                }
                out = string_concat(arena, out, p);
                first = 0;
            }
        }
        return out;
    }
}

slop_string sroiqfss_junction(slop_arena* arena, slop_string f, slop_list_string parts, slop_string empty) {
    if (((int64_t)((parts).len)) == 0) {
        return empty;
    } else if (((int64_t)((parts).len)) == 1) {
        __auto_type _mv_1307 = ({ __auto_type _lst = parts; size_t _idx = (size_t)0; slop_option_string _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1307.has_value) {
            __auto_type p = _mv_1307.value;
            return p;
        } else if (!_mv_1307.has_value) {
            return empty;
        }
        SLOP_UNREACHABLE();
    } else {
        return sroiqfss_call1(arena, f, sroiqfss_joined(arena, parts));
    }
}

slop_string sroiqfss_thing(slop_arena* arena) {
    return sroiqfss_angle(arena, vocab_OWL_THING);
}

slop_string sroiqfss_nothing(slop_arena* arena) {
    return sroiqfss_angle(arena, vocab_OWL_NOTHING);
}

slop_string sroiqfss_role_text(slop_arena* arena, types_RoleId r) {
    __auto_type _mv_1308 = r;
    switch (_mv_1308.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_1308.data.named_role;
            return sroiqfss_angle(arena, i.value);
        }
        case types_RoleId_inverse_role:
        {
            __auto_type i = _mv_1308.data.inverse_role;
            return sroiqfss_call1(arena, SLOP_STR("ObjectInverseOf"), sroiqfss_angle(arena, i.value));
        }
        case types_RoleId_fresh_role:
        {
            __auto_type k = _mv_1308.data.fresh_role;
            return sroiqfss_angle(arena, string_concat(arena, SLOP_STR("urn:howl:role:"), int_to_string(arena, ((int64_t)(k)))));
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_string sroiqfss_concepts_text(slop_arena* arena, slop_list_sroiq_SConcept atoms, slop_list_sroiq_SConcept cs) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sroiqfss_concept_text(arena, atoms, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_string sroiqfss_concept_text(slop_arena* arena, slop_list_sroiq_SConcept atoms, sroiq_SConcept c) {
    __auto_type _mv_1309 = c;
    switch (_mv_1309.tag) {
        case sroiq_SConcept_sc_top:
        {
            return sroiqfss_thing(arena);
        }
        case sroiq_SConcept_sc_bottom:
        {
            return sroiqfss_nothing(arena);
        }
        case sroiq_SConcept_sc_name:
        {
            __auto_type i = _mv_1309.data.sc_name;
            return sroiqfss_angle(arena, i.value);
        }
        case sroiq_SConcept_sc_nominal:
        {
            __auto_type i = _mv_1309.data.sc_nominal;
            return sroiqfss_call1(arena, SLOP_STR("ObjectOneOf"), sroiqfss_angle(arena, i.value));
        }
        case sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_1309.data.sc_not;
            return sroiqfss_call1(arena, SLOP_STR("ObjectComplementOf"), sroiqfss_concept_text(arena, atoms, (*f)));
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_1309.data.sc_and;
            return sroiqfss_junction(arena, SLOP_STR("ObjectIntersectionOf"), sroiqfss_concepts_text(arena, atoms, xs), sroiqfss_thing(arena));
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_1309.data.sc_or;
            return sroiqfss_junction(arena, SLOP_STR("ObjectUnionOf"), sroiqfss_concepts_text(arena, atoms, xs), sroiqfss_nothing(arena));
        }
        case sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_1309.data.sc_some.f0;
            __auto_type f = _mv_1309.data.sc_some.f1;
            return sroiqfss_call2(arena, SLOP_STR("ObjectSomeValuesFrom"), sroiqfss_role_text(arena, r), sroiqfss_concept_text(arena, atoms, (*f)));
        }
        case sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_1309.data.sc_all.f0;
            __auto_type f = _mv_1309.data.sc_all.f1;
            return sroiqfss_call2(arena, SLOP_STR("ObjectAllValuesFrom"), sroiqfss_role_text(arena, r), sroiqfss_concept_text(arena, atoms, (*f)));
        }
        case sroiq_SConcept_sc_atleast:
        {
            __auto_type n = _mv_1309.data.sc_atleast.f0;
            __auto_type r = _mv_1309.data.sc_atleast.f1;
            __auto_type f = _mv_1309.data.sc_atleast.f2;
            return sroiqfss_call3(arena, SLOP_STR("ObjectMinCardinality"), int_to_string(arena, n), sroiqfss_role_text(arena, r), sroiqfss_concept_text(arena, atoms, (*f)));
        }
        case sroiq_SConcept_sc_atmost:
        {
            __auto_type n = _mv_1309.data.sc_atmost.f0;
            __auto_type r = _mv_1309.data.sc_atmost.f1;
            __auto_type f = _mv_1309.data.sc_atmost.f2;
            return sroiqfss_call3(arena, SLOP_STR("ObjectMaxCardinality"), int_to_string(arena, n), sroiqfss_role_text(arena, r), sroiqfss_concept_text(arena, atoms, (*f)));
        }
        case sroiq_SConcept_sc_self:
        {
            __auto_type r = _mv_1309.data.sc_self;
            return sroiqfss_call1(arena, SLOP_STR("ObjectHasSelf"), sroiqfss_role_text(arena, r));
        }
        case sroiq_SConcept_sc_elim:
        {
            return sroiqfss_angle(arena, sroiqfss_atom_iri(arena, atoms, c));
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_string sroiqfss_roles_text(slop_arena* arena, slop_list_types_RoleId rs) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sroiqfss_role_text(arena, r)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_string sroiqfss_ria_text(slop_arena* arena, sroiq_SRia x) {
    {
        __auto_type sub = (((((int64_t)((x.word).len)) == 1)) ? sroiqfss_joined(arena, sroiqfss_roles_text(arena, x.word)) : sroiqfss_call1(arena, SLOP_STR("ObjectPropertyChain"), sroiqfss_joined(arena, sroiqfss_roles_text(arena, x.word))));
        return sroiqfss_call2(arena, SLOP_STR("SubObjectPropertyOf"), sub, sroiqfss_role_text(arena, x.super));
    }
}

slop_string sroiqfss_axiom_text(slop_arena* arena, slop_list_sroiq_SConcept atoms, sroiq_SAxiom a) {
    __auto_type _mv_1310 = a;
    switch (_mv_1310.tag) {
        case sroiq_SAxiom_sa_gci:
        {
            __auto_type l = _mv_1310.data.sa_gci.f0;
            __auto_type r = _mv_1310.data.sa_gci.f1;
            return sroiqfss_call2(arena, SLOP_STR("SubClassOf"), sroiqfss_concept_text(arena, atoms, (*l)), sroiqfss_concept_text(arena, atoms, (*r)));
        }
        case sroiq_SAxiom_sa_ria:
        {
            __auto_type x = _mv_1310.data.sa_ria;
            return sroiqfss_ria_text(arena, x);
        }
        case sroiq_SAxiom_sa_ref:
        {
            __auto_type r = _mv_1310.data.sa_ref;
            return sroiqfss_call1(arena, SLOP_STR("ReflexiveObjectProperty"), sroiqfss_role_text(arena, r));
        }
        case sroiq_SAxiom_sa_irr:
        {
            __auto_type r = _mv_1310.data.sa_irr;
            return sroiqfss_call1(arena, SLOP_STR("IrreflexiveObjectProperty"), sroiqfss_role_text(arena, r));
        }
        case sroiq_SAxiom_sa_dis:
        {
            __auto_type r = _mv_1310.data.sa_dis.f0;
            __auto_type s = _mv_1310.data.sa_dis.f1;
            return sroiqfss_call2(arena, SLOP_STR("DisjointObjectProperties"), sroiqfss_role_text(arena, r), sroiqfss_role_text(arena, s));
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_sroiq_SConcept sroiqfss_atoms_in(slop_arena* arena, sroiq_SConcept c) {
    __auto_type _mv_1311 = c;
    switch (_mv_1311.tag) {
        case sroiq_SConcept_sc_elim:
        {
            {
                __auto_type xs = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                ({ __auto_type _lst_p = &(xs); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                return xs;
            }
        }
        case sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_1311.data.sc_not;
            return sroiqfss_atoms_in(arena, (*f));
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_1311.data.sc_and;
            return sroiqfss_atoms_in_all(arena, xs);
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_1311.data.sc_or;
            return sroiqfss_atoms_in_all(arena, xs);
        }
        case sroiq_SConcept_sc_some:
        {
            __auto_type f = _mv_1311.data.sc_some.f1;
            return sroiqfss_atoms_in(arena, (*f));
        }
        case sroiq_SConcept_sc_all:
        {
            __auto_type f = _mv_1311.data.sc_all.f1;
            return sroiqfss_atoms_in(arena, (*f));
        }
        case sroiq_SConcept_sc_atleast:
        {
            __auto_type f = _mv_1311.data.sc_atleast.f2;
            return sroiqfss_atoms_in(arena, (*f));
        }
        case sroiq_SConcept_sc_atmost:
        {
            __auto_type f = _mv_1311.data.sc_atmost.f2;
            return sroiqfss_atoms_in(arena, (*f));
        }
        default: {
            return ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        }
    }
}

slop_list_sroiq_SConcept sroiqfss_atoms_in_all(slop_arena* arena, slop_list_sroiq_SConcept cs) {
    {
        __auto_type out = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type _coll = sroiqfss_atoms_in(arena, c);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type a = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

sroiq_SConcept sroiqfss_atom_at(slop_list_sroiq_SConcept xs, int64_t i) {
    __auto_type _mv_1312 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_sroiq_SConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1312.has_value) {
        __auto_type v = _mv_1312.value;
        return v;
    } else if (!_mv_1312.has_value) {
        return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_top });
    }
    SLOP_UNREACHABLE();
}

slop_list_sroiq_SConcept sroiqfss_document_atoms(slop_arena* arena, slop_list_sroiq_SAxiom axs) {
    {
        __auto_type all = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type out = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_1313 = a;
                switch (_mv_1313.tag) {
                    case sroiq_SAxiom_sa_gci:
                    {
                        __auto_type l = _mv_1313.data.sa_gci.f0;
                        __auto_type r = _mv_1313.data.sa_gci.f1;
                        {
                            __auto_type _coll = sroiqfss_atoms_in(arena, (*l));
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type x = _coll.data[_i];
                                ({ __auto_type _lst_p = &(all); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        {
                            __auto_type _coll = sroiqfss_atoms_in(arena, (*r));
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type x = _coll.data[_i];
                                ({ __auto_type _lst_p = &(all); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        {
            __auto_type _coll = canon_sort_range(arena, ((int64_t)(((int64_t)((all).len)))), ({ sroiqfss__lambda_1314_env_t* sroiqfss__lambda_1314_env = (sroiqfss__lambda_1314_env_t*)slop_arena_alloc(arena, sizeof(sroiqfss__lambda_1314_env_t)); *sroiqfss__lambda_1314_env = (sroiqfss__lambda_1314_env_t){ .all = &(all) }; (slop_closure_t){ (void*)sroiqfss__lambda_1314, (void*)sroiqfss__lambda_1314_env }; }));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type x = sroiqfss_atom_at(all, k);
                    __auto_type n = ((int64_t)(((int64_t)((out).len))));
                    if ((n == 0) || (sroiq_sc_cmp(x, sroiqfss_atom_at(out, (n - 1))) != 0)) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

int64_t sroiqfss_atom_index(slop_list_sroiq_SConcept atoms, sroiq_SConcept c) {
    {
        int64_t lo = 0;
        int64_t hi = (((int64_t)(((int64_t)((atoms).len)))) - 1);
        int64_t found = -1;
        while ((lo <= hi) && (found < 0)) {
            {
                __auto_type mid = ((lo + hi) / 2);
                __auto_type d = sroiq_sc_cmp(sroiqfss_atom_at(atoms, ((lo + hi) / 2)), c);
                if (d == 0) {
                    found = mid;
                } else if (d < 0) {
                    lo = (mid + 1);
                } else {
                    hi = (mid - 1);
                }
            }
        }
        return found;
    }
}

slop_string sroiqfss_atom_iri(slop_arena* arena, slop_list_sroiq_SConcept atoms, sroiq_SConcept c) {
    return string_concat(arena, SLOP_STR("urn:howl:elim:"), int_to_string(arena, sroiqfss_atom_index(atoms, c)));
}

slop_list_string sroiqfss_declare(slop_arena* arena, slop_string kind, slop_string v) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (!(strlib_starts_with(v, sroiqfss_OWL_NS_PREFIX))) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sroiqfss_call1(arena, SLOP_STR("Declaration"), sroiqfss_call1(arena, kind, sroiqfss_angle(arena, v)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return out;
    }
}

slop_list_string sroiqfss_role_decls(slop_arena* arena, types_RoleId r) {
    __auto_type _mv_1315 = r;
    switch (_mv_1315.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_1315.data.named_role;
            return sroiqfss_declare(arena, SLOP_STR("ObjectProperty"), i.value);
        }
        case types_RoleId_inverse_role:
        {
            __auto_type i = _mv_1315.data.inverse_role;
            return sroiqfss_declare(arena, SLOP_STR("ObjectProperty"), i.value);
        }
        case types_RoleId_fresh_role:
        {
            __auto_type k = _mv_1315.data.fresh_role;
            return sroiqfss_declare(arena, SLOP_STR("ObjectProperty"), string_concat(arena, SLOP_STR("urn:howl:role:"), int_to_string(arena, ((int64_t)(k)))));
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_string sroiqfss_concept_decls(slop_arena* arena, slop_list_sroiq_SConcept atoms, sroiq_SConcept c) {
    __auto_type _mv_1316 = c;
    switch (_mv_1316.tag) {
        case sroiq_SConcept_sc_top:
        {
            return ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        }
        case sroiq_SConcept_sc_bottom:
        {
            return ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        }
        case sroiq_SConcept_sc_name:
        {
            __auto_type i = _mv_1316.data.sc_name;
            return sroiqfss_declare(arena, SLOP_STR("Class"), i.value);
        }
        case sroiq_SConcept_sc_nominal:
        {
            __auto_type i = _mv_1316.data.sc_nominal;
            return sroiqfss_declare(arena, SLOP_STR("NamedIndividual"), i.value);
        }
        case sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_1316.data.sc_not;
            return sroiqfss_concept_decls(arena, atoms, (*f));
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_1316.data.sc_and;
            return sroiqfss_concepts_decls(arena, atoms, xs);
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_1316.data.sc_or;
            return sroiqfss_concepts_decls(arena, atoms, xs);
        }
        case sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_1316.data.sc_some.f0;
            __auto_type f = _mv_1316.data.sc_some.f1;
            return sroiqfss_append2(arena, sroiqfss_role_decls(arena, r), sroiqfss_concept_decls(arena, atoms, (*f)));
        }
        case sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_1316.data.sc_all.f0;
            __auto_type f = _mv_1316.data.sc_all.f1;
            return sroiqfss_append2(arena, sroiqfss_role_decls(arena, r), sroiqfss_concept_decls(arena, atoms, (*f)));
        }
        case sroiq_SConcept_sc_atleast:
        {
            __auto_type r = _mv_1316.data.sc_atleast.f1;
            __auto_type f = _mv_1316.data.sc_atleast.f2;
            return sroiqfss_append2(arena, sroiqfss_role_decls(arena, r), sroiqfss_concept_decls(arena, atoms, (*f)));
        }
        case sroiq_SConcept_sc_atmost:
        {
            __auto_type r = _mv_1316.data.sc_atmost.f1;
            __auto_type f = _mv_1316.data.sc_atmost.f2;
            return sroiqfss_append2(arena, sroiqfss_role_decls(arena, r), sroiqfss_concept_decls(arena, atoms, (*f)));
        }
        case sroiq_SConcept_sc_self:
        {
            __auto_type r = _mv_1316.data.sc_self;
            return sroiqfss_role_decls(arena, r);
        }
        case sroiq_SConcept_sc_elim:
        {
            return sroiqfss_declare(arena, SLOP_STR("Class"), sroiqfss_atom_iri(arena, atoms, c));
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_string sroiqfss_concepts_decls(slop_arena* arena, slop_list_sroiq_SConcept atoms, slop_list_sroiq_SConcept cs) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type _coll = sroiqfss_concept_decls(arena, atoms, c);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type d = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (d); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

slop_list_string sroiqfss_append2(slop_arena* arena, slop_list_string a, slop_list_string b) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = b;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_string sroiqfss_axiom_decls(slop_arena* arena, slop_list_sroiq_SConcept atoms, sroiq_SAxiom a) {
    __auto_type _mv_1317 = a;
    switch (_mv_1317.tag) {
        case sroiq_SAxiom_sa_gci:
        {
            __auto_type l = _mv_1317.data.sa_gci.f0;
            __auto_type r = _mv_1317.data.sa_gci.f1;
            return sroiqfss_append2(arena, sroiqfss_concept_decls(arena, atoms, (*l)), sroiqfss_concept_decls(arena, atoms, (*r)));
        }
        case sroiq_SAxiom_sa_ria:
        {
            __auto_type x = _mv_1317.data.sa_ria;
            {
                __auto_type out = sroiqfss_role_decls(arena, x.super);
                {
                    __auto_type _coll = x.word;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        {
                            __auto_type _coll = sroiqfss_role_decls(arena, r);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type d = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (d); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                return out;
            }
        }
        case sroiq_SAxiom_sa_ref:
        {
            __auto_type r = _mv_1317.data.sa_ref;
            return sroiqfss_role_decls(arena, r);
        }
        case sroiq_SAxiom_sa_irr:
        {
            __auto_type r = _mv_1317.data.sa_irr;
            return sroiqfss_role_decls(arena, r);
        }
        case sroiq_SAxiom_sa_dis:
        {
            __auto_type r = _mv_1317.data.sa_dis.f0;
            __auto_type s = _mv_1317.data.sa_dis.f1;
            return sroiqfss_append2(arena, sroiqfss_role_decls(arena, r), sroiqfss_role_decls(arena, s));
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_string sroiqfss_unique_sorted(slop_arena* arena, slop_list_string xs) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type last = SLOP_STR("");
        {
            __auto_type _coll = canon_sort_strings(arena, xs);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if ((((int64_t)((out).len)) == 0) || !(string_eq(x, last))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    last = x;
                }
            }
        }
        return out;
    }
}

slop_list_string sroiqfss_document(slop_arena* arena, slop_list_string decls, slop_list_string axioms) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (SLOP_STR("Ontology(<urn:howl:dump>")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = sroiqfss_unique_sorted(arena, decls);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type d = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (d); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        ({ __auto_type _lst_p = &(out); __auto_type _item = (SLOP_STR(")")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

slop_list_string sroiqfss_class_decls(slop_arena* arena, slop_list_rdf_IRI classes) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type _coll = sroiqfss_declare(arena, SLOP_STR("Class"), c.value);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type d = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (d); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

slop_list_string sroiqfss_fss_axioms(slop_arena* arena, slop_list_rdf_IRI classes, slop_list_sroiq_SAxiom axs) {
    {
        __auto_type atoms = sroiqfss_document_atoms(arena, axs);
        __auto_type decls = sroiqfss_class_decls(arena, classes);
        __auto_type lines = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    __auto_type _coll = sroiqfss_axiom_decls(arena, atoms, a);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type d = _coll.data[_i];
                        ({ __auto_type _lst_p = &(decls); __auto_type _item = (d); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                ({ __auto_type _lst_p = &(lines); __auto_type _item = (sroiqfss_axiom_text(arena, atoms, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return sroiqfss_document(arena, decls, lines);
    }
}

slop_string sroiqfss_fresh_iri(slop_arena* arena, int64_t k) {
    return string_concat(arena, SLOP_STR("urn:howl:a:"), int_to_string(arena, k));
}

int64_t sroiqfss_bar_index(slop_list_rdf_IRI bars, rdf_IRI p) {
    {
        int64_t k = 0;
        int64_t found = -1;
        {
            __auto_type _coll = bars;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                if (string_eq(b.value, p.value)) {
                    found = k;
                }
                k = (k + 1);
            }
        }
        return found;
    }
}

slop_string sroiqfss_bar_iri(slop_arena* arena, slop_list_rdf_IRI bars, rdf_IRI p) {
    return string_concat(arena, SLOP_STR("urn:howl:bar:"), int_to_string(arena, sroiqfss_bar_index(bars, p)));
}

slop_string sroiqfss_dname_iri(slop_arena* arena, types_DName n) {
    __auto_type _mv_1318 = n;
    switch (_mv_1318.tag) {
        case types_DName_dn_class:
        {
            __auto_type i = _mv_1318.data.dn_class;
            return i.value;
        }
        case types_DName_dn_fresh:
        {
            __auto_type k = _mv_1318.data.dn_fresh;
            return sroiqfss_fresh_iri(arena, ((int64_t)(k)));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string sroiqfss_dname_text(slop_arena* arena, types_DName n) {
    return sroiqfss_angle(arena, sroiqfss_dname_iri(arena, n));
}

slop_string sroiqfss_drole_iri(slop_arena* arena, slop_list_rdf_IRI bars, types_DRole r) {
    __auto_type _mv_1319 = r;
    switch (_mv_1319.tag) {
        case types_DRole_dr_prop:
        {
            __auto_type i = _mv_1319.data.dr_prop;
            return i.value;
        }
        case types_DRole_dr_bar:
        {
            __auto_type i = _mv_1319.data.dr_bar;
            return sroiqfss_bar_iri(arena, bars, i);
        }
        case types_DRole_dr_sub:
        {
            __auto_type k = _mv_1319.data.dr_sub;
            return string_concat(arena, SLOP_STR("urn:howl:sub:"), int_to_string(arena, ((int64_t)(k))));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string sroiqfss_drole_text(slop_arena* arena, slop_list_rdf_IRI bars, types_DRole r) {
    return sroiqfss_angle(arena, sroiqfss_drole_iri(arena, bars, r));
}

slop_list_string sroiqfss_dnames_text(slop_arena* arena, slop_list_types_DName ns) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sroiqfss_dname_text(arena, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_string sroiqfss_filler_text(slop_arena* arena, slop_option_types_DName b) {
    __auto_type _mv_1320 = b;
    if (!_mv_1320.has_value) {
        return sroiqfss_thing(arena);
    } else if (_mv_1320.has_value) {
        __auto_type n = _mv_1320.value;
        return sroiqfss_dname_text(arena, n);
    }
    SLOP_UNREACHABLE();
}

slop_string sroiqfss_count_text(slop_arena* arena, slop_string f, int64_t n, slop_string role, slop_string filler) {
    return sroiqfss_call3(arena, f, int_to_string(arena, n), role, filler);
}

slop_string sroiqfss_clause_text(slop_arena* arena, slop_list_rdf_IRI bars, types_DlClause c) {
    __auto_type _mv_1321 = c;
    switch (_mv_1321.tag) {
        case types_DlClause_dl1:
        {
            __auto_type d = _mv_1321.data.dl1;
            return sroiqfss_call2(arena, SLOP_STR("SubClassOf"), sroiqfss_junction(arena, SLOP_STR("ObjectIntersectionOf"), sroiqfss_dnames_text(arena, d.body), sroiqfss_thing(arena)), sroiqfss_junction(arena, SLOP_STR("ObjectUnionOf"), sroiqfss_dnames_text(arena, d.head), sroiqfss_nothing(arena)));
        }
        case types_DlClause_dl2:
        {
            __auto_type d = _mv_1321.data.dl2;
            return sroiqfss_call2(arena, SLOP_STR("SubClassOf"), sroiqfss_dname_text(arena, d.sub), sroiqfss_count_text(arena, SLOP_STR("ObjectMinCardinality"), d.count, sroiqfss_drole_text(arena, bars, d.role), sroiqfss_filler_text(arena, d.filler)));
        }
        case types_DlClause_dl3:
        {
            __auto_type s = _mv_1321.data.dl3.f0;
            __auto_type b1 = _mv_1321.data.dl3.f1;
            __auto_type b2 = _mv_1321.data.dl3.f2;
            return sroiqfss_call2(arena, SLOP_STR("SubClassOf"), sroiqfss_call2(arena, SLOP_STR("ObjectSomeValuesFrom"), sroiqfss_drole_text(arena, bars, s), sroiqfss_dname_text(arena, b1)), sroiqfss_dname_text(arena, b2));
        }
        case types_DlClause_dl4:
        {
            __auto_type d = _mv_1321.data.dl4;
            return sroiqfss_call2(arena, SLOP_STR("SubClassOf"), sroiqfss_dname_text(arena, d.sub), sroiqfss_count_text(arena, SLOP_STR("ObjectMaxCardinality"), d.count, sroiqfss_drole_text(arena, bars, d.role), sroiqfss_filler_text(arena, d.filler)));
        }
        case types_DlClause_dl5:
        {
            __auto_type b = _mv_1321.data.dl5.f0;
            __auto_type s = _mv_1321.data.dl5.f1;
            return sroiqfss_call2(arena, SLOP_STR("SubClassOf"), sroiqfss_dname_text(arena, b), sroiqfss_call1(arena, SLOP_STR("ObjectHasSelf"), sroiqfss_drole_text(arena, bars, s)));
        }
        case types_DlClause_dl6:
        {
            __auto_type s = _mv_1321.data.dl6.f0;
            __auto_type b = _mv_1321.data.dl6.f1;
            return sroiqfss_call2(arena, SLOP_STR("SubClassOf"), sroiqfss_call1(arena, SLOP_STR("ObjectHasSelf"), sroiqfss_drole_text(arena, bars, s)), sroiqfss_dname_text(arena, b));
        }
        case types_DlClause_dl7:
        {
            __auto_type a = _mv_1321.data.dl7.f0;
            __auto_type b = _mv_1321.data.dl7.f1;
            return sroiqfss_call2(arena, SLOP_STR("SubObjectPropertyOf"), sroiqfss_drole_text(arena, bars, a), sroiqfss_drole_text(arena, bars, b));
        }
        case types_DlClause_dl8:
        {
            __auto_type a = _mv_1321.data.dl8.f0;
            __auto_type b = _mv_1321.data.dl8.f1;
            return sroiqfss_call2(arena, SLOP_STR("SubObjectPropertyOf"), sroiqfss_drole_text(arena, bars, a), sroiqfss_call1(arena, SLOP_STR("ObjectInverseOf"), sroiqfss_drole_text(arena, bars, b)));
        }
        case types_DlClause_dl9:
        {
            __auto_type a = _mv_1321.data.dl9.f0;
            __auto_type b = _mv_1321.data.dl9.f1;
            return sroiqfss_call2(arena, SLOP_STR("DisjointObjectProperties"), sroiqfss_drole_text(arena, bars, a), sroiqfss_drole_text(arena, bars, b));
        }
        case types_DlClause_dl10:
        {
            __auto_type o = _mv_1321.data.dl10.f0;
            __auto_type b = _mv_1321.data.dl10.f1;
            return sroiqfss_call2(arena, SLOP_STR("SubClassOf"), sroiqfss_call1(arena, SLOP_STR("ObjectOneOf"), sroiqfss_angle(arena, o.value)), sroiqfss_dname_text(arena, b));
        }
        case types_DlClause_dl11:
        {
            __auto_type b = _mv_1321.data.dl11.f0;
            __auto_type o = _mv_1321.data.dl11.f1;
            return sroiqfss_call2(arena, SLOP_STR("SubClassOf"), sroiqfss_dname_text(arena, b), sroiqfss_call1(arena, SLOP_STR("ObjectOneOf"), sroiqfss_angle(arena, o.value)));
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_string sroiqfss_dname_decls(slop_arena* arena, types_DName n) {
    return sroiqfss_declare(arena, SLOP_STR("Class"), sroiqfss_dname_iri(arena, n));
}

slop_list_string sroiqfss_filler_decls(slop_arena* arena, slop_option_types_DName b) {
    __auto_type _mv_1322 = b;
    if (!_mv_1322.has_value) {
        return ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    } else if (_mv_1322.has_value) {
        __auto_type n = _mv_1322.value;
        return sroiqfss_dname_decls(arena, n);
    }
    SLOP_UNREACHABLE();
}

slop_list_string sroiqfss_drole_decls(slop_arena* arena, slop_list_rdf_IRI bars, types_DRole r) {
    return sroiqfss_declare(arena, SLOP_STR("ObjectProperty"), sroiqfss_drole_iri(arena, bars, r));
}

slop_list_string sroiqfss_dnames_decls(slop_arena* arena, slop_list_types_DName ns) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                {
                    __auto_type _coll = sroiqfss_dname_decls(arena, n);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type d = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (d); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

slop_list_string sroiqfss_clause_decls(slop_arena* arena, slop_list_rdf_IRI bars, types_DlClause c) {
    __auto_type _mv_1323 = c;
    switch (_mv_1323.tag) {
        case types_DlClause_dl1:
        {
            __auto_type d = _mv_1323.data.dl1;
            return sroiqfss_append2(arena, sroiqfss_dnames_decls(arena, d.body), sroiqfss_dnames_decls(arena, d.head));
        }
        case types_DlClause_dl2:
        {
            __auto_type d = _mv_1323.data.dl2;
            return sroiqfss_append2(arena, sroiqfss_append2(arena, sroiqfss_dname_decls(arena, d.sub), sroiqfss_drole_decls(arena, bars, d.role)), sroiqfss_filler_decls(arena, d.filler));
        }
        case types_DlClause_dl3:
        {
            __auto_type s = _mv_1323.data.dl3.f0;
            __auto_type a = _mv_1323.data.dl3.f1;
            __auto_type b = _mv_1323.data.dl3.f2;
            return sroiqfss_append2(arena, sroiqfss_drole_decls(arena, bars, s), sroiqfss_append2(arena, sroiqfss_dname_decls(arena, a), sroiqfss_dname_decls(arena, b)));
        }
        case types_DlClause_dl4:
        {
            __auto_type d = _mv_1323.data.dl4;
            return sroiqfss_append2(arena, sroiqfss_append2(arena, sroiqfss_dname_decls(arena, d.sub), sroiqfss_drole_decls(arena, bars, d.role)), sroiqfss_filler_decls(arena, d.filler));
        }
        case types_DlClause_dl5:
        {
            __auto_type b = _mv_1323.data.dl5.f0;
            __auto_type s = _mv_1323.data.dl5.f1;
            return sroiqfss_append2(arena, sroiqfss_dname_decls(arena, b), sroiqfss_drole_decls(arena, bars, s));
        }
        case types_DlClause_dl6:
        {
            __auto_type s = _mv_1323.data.dl6.f0;
            __auto_type b = _mv_1323.data.dl6.f1;
            return sroiqfss_append2(arena, sroiqfss_drole_decls(arena, bars, s), sroiqfss_dname_decls(arena, b));
        }
        case types_DlClause_dl7:
        {
            __auto_type a = _mv_1323.data.dl7.f0;
            __auto_type b = _mv_1323.data.dl7.f1;
            return sroiqfss_append2(arena, sroiqfss_drole_decls(arena, bars, a), sroiqfss_drole_decls(arena, bars, b));
        }
        case types_DlClause_dl8:
        {
            __auto_type a = _mv_1323.data.dl8.f0;
            __auto_type b = _mv_1323.data.dl8.f1;
            return sroiqfss_append2(arena, sroiqfss_drole_decls(arena, bars, a), sroiqfss_drole_decls(arena, bars, b));
        }
        case types_DlClause_dl9:
        {
            __auto_type a = _mv_1323.data.dl9.f0;
            __auto_type b = _mv_1323.data.dl9.f1;
            return sroiqfss_append2(arena, sroiqfss_drole_decls(arena, bars, a), sroiqfss_drole_decls(arena, bars, b));
        }
        case types_DlClause_dl10:
        {
            __auto_type o = _mv_1323.data.dl10.f0;
            __auto_type b = _mv_1323.data.dl10.f1;
            return sroiqfss_append2(arena, sroiqfss_declare(arena, SLOP_STR("NamedIndividual"), o.value), sroiqfss_dname_decls(arena, b));
        }
        case types_DlClause_dl11:
        {
            __auto_type b = _mv_1323.data.dl11.f0;
            __auto_type o = _mv_1323.data.dl11.f1;
            return sroiqfss_append2(arena, sroiqfss_dname_decls(arena, b), sroiqfss_declare(arena, SLOP_STR("NamedIndividual"), o.value));
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_string sroiqfss_fss_normal(slop_arena* arena, sriqnames_SriqNormal n) {
    {
        __auto_type decls = sroiqfss_class_decls(arena, n.classes);
        __auto_type lines = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = n.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type _coll = sroiqfss_clause_decls(arena, n.bars, c);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type d = _coll.data[_i];
                        ({ __auto_type _lst_p = &(decls); __auto_type _item = (d); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                ({ __auto_type _lst_p = &(lines); __auto_type _item = (sroiqfss_clause_text(arena, n.bars, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return sroiqfss_document(arena, decls, lines);
    }
}

