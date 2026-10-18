#include "../runtime/slop_runtime.h"
#include "slop_locality.h"

uint8_t howl_locality_iri_out(slop_map* s, slop_rdf_rdf_IRI i);
uint8_t howl_locality_owl_own(slop_rdf_rdf_IRI i);
uint8_t howl_locality_role_out(slop_map* s, howl_types_RoleId r);
uint8_t howl_locality_name_out(slop_map* s, howl_types_Node n);
uint8_t howl_locality_con_bot(howl_owl2_RawConcept c, slop_map* s);
uint8_t howl_locality_con_top(howl_owl2_RawConcept c, slop_map* s);
uint8_t howl_locality_at_least_one(howl_owl2_CardKind k, int64_t n);
uint8_t howl_locality_min_zero(howl_owl2_CardKind k, int64_t n);
uint8_t howl_locality_at_most(howl_owl2_CardKind k, int64_t n);
uint8_t howl_locality_some_bot(slop_list_howl_owl2_RawConcept cs, slop_map* s);
uint8_t howl_locality_all_bot(slop_list_howl_owl2_RawConcept cs, slop_map* s);
int64_t howl_locality_not_bot(slop_list_howl_owl2_RawConcept cs, slop_map* s);
uint8_t howl_locality_some_top(slop_list_howl_owl2_RawConcept cs, slop_map* s);
uint8_t howl_locality_all_top(slop_list_howl_owl2_RawConcept cs, slop_map* s);
int64_t howl_locality_roles_not_out(slop_list_howl_types_RoleId rs, slop_map* s);
uint8_t howl_locality_axiom_local(howl_owl2_RawAxiom ax, slop_map* s);
slop_list_slop_rdf_rdf_IRI howl_locality_axiom_symbols(slop_arena* arena, howl_owl2_RawAxiom ax);
void howl_locality_add_axiom_symbols(howl_owl2_RawAxiom ax, slop_map* out);
void howl_locality_add_concept_symbols(howl_owl2_RawConcept c, slop_map* out);
void howl_locality_add_concepts_symbols(slop_list_howl_owl2_RawConcept cs, slop_map* out);
void howl_locality_add_role(howl_types_RoleId r, slop_map* out);
void howl_locality_add_roles(slop_list_howl_types_RoleId rs, slop_map* out);
void howl_locality_add_node(howl_types_Node n, slop_map* out);
void howl_locality_add_nodes(slop_list_howl_types_Node ns, slop_map* out);
void howl_locality_add_edge(howl_owl2_RawEdge e, slop_map* out);
uint8_t howl_locality_axiom_readable(howl_owl2_RawAxiom ax);
uint8_t howl_locality_concept_readable(howl_owl2_RawConcept c);
uint8_t howl_locality_concepts_readable(slop_list_howl_owl2_RawConcept cs);
howl_locality_ModuleOut howl_locality_module_axioms(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_list_slop_rdf_rdf_IRI seed);
slop_list_int howl_locality_admit_symbols(slop_arena* arena, slop_list_slop_rdf_rdf_IRI syms, slop_map* s, slop_map* index, slop_list_u8 in_m);
slop_list_list_slop_rdf_rdf_IRI howl_locality_symbols_of(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
slop_map* howl_locality_symbol_index(slop_arena* arena, slop_list_list_slop_rdf_rdf_IRI sigs);
slop_list_howl_owl2_RawAxiom howl_locality_kept(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_list_u8 in_m);
int64_t howl_locality_int_of(slop_list_int xs, int64_t k);
uint8_t howl_locality_bool_of(slop_list_u8 xs, int64_t k);
howl_owl2_RawAxiom howl_locality_axiom_of(slop_list_howl_owl2_RawAxiom axs, int64_t k);
slop_list_slop_rdf_rdf_IRI howl_locality_sym_of(slop_arena* arena, slop_list_list_slop_rdf_rdf_IRI sigs, int64_t k);
howl_normalize_Decoded howl_locality_module_decoded(slop_arena* arena, howl_normalize_Decoded d, slop_list_slop_rdf_rdf_IRI seed);
slop_list_int howl_locality_kept_docs(slop_arena* arena, slop_list_int docs, slop_list_u8 in_m);
howl_owl2_Signature howl_locality_restricted(slop_arena* arena, howl_owl2_Signature sig, slop_map* s);
slop_map* howl_locality_within(slop_arena* arena, slop_map* xs, slop_map* s);

uint8_t howl_locality_iri_out(slop_map* s, slop_rdf_rdf_IRI i) {
    return (!(slop_map_has(s, &(i))) && !(howl_locality_owl_own(i)));
}

uint8_t howl_locality_owl_own(slop_rdf_rdf_IRI i) {
    return std_strlib_starts_with(i.value, SLOP_STR("http://www.w3.org/2002/07/owl#"));
}

uint8_t howl_locality_role_out(slop_map* s, howl_types_RoleId r) {
    __auto_type _mv_1611 = r;
    switch (_mv_1611.tag) {
        case howl_types_RoleId_named_role:
        {
            __auto_type i = _mv_1611.data.named_role;
            return howl_locality_iri_out(s, i);
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type i = _mv_1611.data.inverse_role;
            return howl_locality_iri_out(s, i);
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_1611.data.fresh_role;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_locality_name_out(slop_map* s, howl_types_Node n) {
    __auto_type _mv_1612 = n;
    switch (_mv_1612.tag) {
        case howl_types_Node_class_node:
        {
            __auto_type i = _mv_1612.data.class_node;
            return howl_locality_iri_out(s, i);
        }
        case howl_types_Node_individual_node:
        {
            __auto_type _ = _mv_1612.data.individual_node;
            return 0;
        }
        case howl_types_Node_fresh_node:
        {
            __auto_type _ = _mv_1612.data.fresh_node;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_locality_con_bot(howl_owl2_RawConcept c, slop_map* s) {
    __auto_type _mv_1613 = c;
    switch (_mv_1613.tag) {
        case howl_owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_1613.data.rc_name;
            return howl_locality_name_out(s, n);
        }
        case howl_owl2_RawConcept_rc_thing:
        {
            return 0;
        }
        case howl_owl2_RawConcept_rc_nothing:
        {
            return 1;
        }
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_1613.data.rc_and;
            return howl_locality_some_bot(cs, s);
        }
        case howl_owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_1613.data.rc_some.f0;
            __auto_type f = _mv_1613.data.rc_some.f1;
            return (howl_locality_role_out(s, r) || howl_locality_con_bot((*f), s));
        }
        case howl_owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_1613.data.rc_or;
            return howl_locality_all_bot(cs, s);
        }
        case howl_owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_1613.data.rc_not;
            return howl_locality_con_top((*f), s);
        }
        case howl_owl2_RawConcept_rc_all:
        {
            return 0;
        }
        case howl_owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_1613.data.rc_oneof;
            return (((int64_t)((ns).len)) == 0);
        }
        case howl_owl2_RawConcept_rc_has_value:
        {
            __auto_type r = _mv_1613.data.rc_has_value.f0;
            return howl_locality_role_out(s, r);
        }
        case howl_owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_1613.data.rc_has_self;
            return howl_locality_role_out(s, r);
        }
        case howl_owl2_RawConcept_rc_card:
        {
            __auto_type k = _mv_1613.data.rc_card.f0;
            __auto_type r = _mv_1613.data.rc_card.f1;
            __auto_type n = _mv_1613.data.rc_card.f2;
            return (howl_locality_at_least_one(k, n) && howl_locality_role_out(s, r));
        }
        case howl_owl2_RawConcept_rc_qcard:
        {
            __auto_type k = _mv_1613.data.rc_qcard.f0;
            __auto_type r = _mv_1613.data.rc_qcard.f1;
            __auto_type n = _mv_1613.data.rc_qcard.f2;
            __auto_type f = _mv_1613.data.rc_qcard.f3;
            return (howl_locality_at_least_one(k, n) && (howl_locality_role_out(s, r) || howl_locality_con_bot((*f), s)));
        }
        case howl_owl2_RawConcept_rc_data:
        {
            __auto_type _ = _mv_1613.data.rc_data;
            return 0;
        }
        case howl_owl2_RawConcept_rc_anon:
        {
            __auto_type _ = _mv_1613.data.rc_anon;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_locality_con_top(howl_owl2_RawConcept c, slop_map* s) {
    __auto_type _mv_1614 = c;
    switch (_mv_1614.tag) {
        case howl_owl2_RawConcept_rc_name:
        {
            __auto_type _ = _mv_1614.data.rc_name;
            return 0;
        }
        case howl_owl2_RawConcept_rc_thing:
        {
            return 1;
        }
        case howl_owl2_RawConcept_rc_nothing:
        {
            return 0;
        }
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_1614.data.rc_and;
            return howl_locality_all_top(cs, s);
        }
        case howl_owl2_RawConcept_rc_some:
        {
            return 0;
        }
        case howl_owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_1614.data.rc_or;
            return howl_locality_some_top(cs, s);
        }
        case howl_owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_1614.data.rc_not;
            return howl_locality_con_bot((*f), s);
        }
        case howl_owl2_RawConcept_rc_all:
        {
            __auto_type r = _mv_1614.data.rc_all.f0;
            __auto_type f = _mv_1614.data.rc_all.f1;
            return (howl_locality_role_out(s, r) || howl_locality_con_top((*f), s));
        }
        case howl_owl2_RawConcept_rc_oneof:
        {
            __auto_type _ = _mv_1614.data.rc_oneof;
            return 0;
        }
        case howl_owl2_RawConcept_rc_has_value:
        {
            return 0;
        }
        case howl_owl2_RawConcept_rc_has_self:
        {
            __auto_type _ = _mv_1614.data.rc_has_self;
            return 0;
        }
        case howl_owl2_RawConcept_rc_card:
        {
            __auto_type k = _mv_1614.data.rc_card.f0;
            __auto_type r = _mv_1614.data.rc_card.f1;
            __auto_type n = _mv_1614.data.rc_card.f2;
            return (howl_locality_min_zero(k, n) || (howl_locality_at_most(k, n) && howl_locality_role_out(s, r)));
        }
        case howl_owl2_RawConcept_rc_qcard:
        {
            __auto_type k = _mv_1614.data.rc_qcard.f0;
            __auto_type r = _mv_1614.data.rc_qcard.f1;
            __auto_type n = _mv_1614.data.rc_qcard.f2;
            __auto_type f = _mv_1614.data.rc_qcard.f3;
            return (howl_locality_min_zero(k, n) || (howl_locality_at_most(k, n) && (howl_locality_role_out(s, r) || howl_locality_con_bot((*f), s))));
        }
        case howl_owl2_RawConcept_rc_data:
        {
            __auto_type _ = _mv_1614.data.rc_data;
            return 0;
        }
        case howl_owl2_RawConcept_rc_anon:
        {
            __auto_type _ = _mv_1614.data.rc_anon;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_locality_at_least_one(howl_owl2_CardKind k, int64_t n) {
    return ((n >= 1) && !((k == howl_owl2_CardKind_card_max)));
}

uint8_t howl_locality_min_zero(howl_owl2_CardKind k, int64_t n) {
    return ((k == howl_owl2_CardKind_card_min) && (n == 0));
}

uint8_t howl_locality_at_most(howl_owl2_CardKind k, int64_t n) {
    return ((k == howl_owl2_CardKind_card_max) || ((k == howl_owl2_CardKind_card_exact) && (n == 0)));
}

uint8_t howl_locality_some_bot(slop_list_howl_owl2_RawConcept cs, slop_map* s) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (howl_locality_con_bot(c, s)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t howl_locality_all_bot(slop_list_howl_owl2_RawConcept cs, slop_map* s) {
    return (howl_locality_not_bot(cs, s) == 0);
}

int64_t howl_locality_not_bot(slop_list_howl_owl2_RawConcept cs, slop_map* s) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(howl_locality_con_bot(c, s))) {
                    n = (n + 1);
                }
            }
        }
        return n;
    }
}

uint8_t howl_locality_some_top(slop_list_howl_owl2_RawConcept cs, slop_map* s) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (howl_locality_con_top(c, s)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t howl_locality_all_top(slop_list_howl_owl2_RawConcept cs, slop_map* s) {
    {
        uint8_t all = 1;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(howl_locality_con_top(c, s))) {
                    all = 0;
                }
            }
        }
        return all;
    }
}

int64_t howl_locality_roles_not_out(slop_list_howl_types_RoleId rs, slop_map* s) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                if (!(howl_locality_role_out(s, r))) {
                    n = (n + 1);
                }
            }
        }
        return n;
    }
}

uint8_t howl_locality_axiom_local(howl_owl2_RawAxiom ax, slop_map* s) {
    __auto_type _mv_1615 = ax;
    switch (_mv_1615.tag) {
        case howl_owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type c = _mv_1615.data.ra_sub_class_of.f0;
            __auto_type d = _mv_1615.data.ra_sub_class_of.f1;
            return (howl_locality_con_bot((*c), s) || howl_locality_con_top((*d), s));
        }
        case howl_owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type cs = _mv_1615.data.ra_equivalent_classes;
            return (howl_locality_all_bot(cs, s) || howl_locality_all_top(cs, s));
        }
        case howl_owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_1615.data.ra_disjoint_classes;
            return (howl_locality_not_bot(cs, s) <= 1);
        }
        case howl_owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type r = _mv_1615.data.ra_sub_object_property.f0;
            return howl_locality_role_out(s, r);
        }
        case howl_owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_1615.data.ra_property_chain;
            return (howl_locality_roles_not_out(ch.steps, s) < ((int64_t)(((int64_t)((ch.steps).len)))));
        }
        case howl_owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type rs = _mv_1615.data.ra_equivalent_properties;
            return (howl_locality_roles_not_out(rs, s) == 0);
        }
        case howl_owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type r = _mv_1615.data.ra_transitive_property;
            return howl_locality_role_out(s, r);
        }
        case howl_owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_1615.data.ra_object_property_domain.f0;
            __auto_type c = _mv_1615.data.ra_object_property_domain.f1;
            return (howl_locality_role_out(s, r) || howl_locality_con_top((*c), s));
        }
        case howl_owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type r = _mv_1615.data.ra_object_property_range.f0;
            __auto_type c = _mv_1615.data.ra_object_property_range.f1;
            return (howl_locality_role_out(s, r) || howl_locality_con_top((*c), s));
        }
        case howl_owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_1615.data.ra_class_assertion;
            return howl_locality_con_top((*ca.concept), s);
        }
        case howl_owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type _ = _mv_1615.data.ra_object_property_assertion;
            return 0;
        }
        case howl_owl2_RawAxiom_ra_declaration:
        {
            __auto_type _ = _mv_1615.data.ra_declaration;
            return 1;
        }
        case howl_owl2_RawAxiom_ra_annotation:
        {
            return 1;
        }
        case howl_owl2_RawAxiom_ra_inert_data:
        {
            return 1;
        }
        case howl_owl2_RawAxiom_ra_inverse_properties:
        {
            __auto_type r = _mv_1615.data.ra_inverse_properties.f0;
            __auto_type q = _mv_1615.data.ra_inverse_properties.f1;
            return (howl_locality_role_out(s, r) && howl_locality_role_out(s, q));
        }
        case howl_owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type k = _mv_1615.data.ra_property_characteristic.f0;
            __auto_type r = _mv_1615.data.ra_property_characteristic.f1;
            return (!((k == howl_owl2_PropCharacteristic_prop_reflexive)) && howl_locality_role_out(s, r));
        }
        case howl_owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type rs = _mv_1615.data.ra_disjoint_properties;
            return (howl_locality_roles_not_out(rs, s) <= 1);
        }
        case howl_owl2_RawAxiom_ra_same_individual:
        {
            __auto_type ns = _mv_1615.data.ra_same_individual;
            return (((int64_t)((ns).len)) <= 1);
        }
        case howl_owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type ns = _mv_1615.data.ra_different_individuals;
            return (((int64_t)((ns).len)) <= 1);
        }
        case howl_owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type e = _mv_1615.data.ra_negative_assertion;
            return howl_locality_role_out(s, e.role);
        }
        case howl_owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type du = _mv_1615.data.ra_disjoint_union;
            return (howl_locality_iri_out(s, du.class) && howl_locality_all_bot(du.members, s));
        }
        case howl_owl2_RawAxiom_ra_has_key:
        {
            __auto_type _ = _mv_1615.data.ra_has_key;
            return 0;
        }
        case howl_owl2_RawAxiom_ra_data_axiom:
        {
            __auto_type _ = _mv_1615.data.ra_data_axiom;
            return 0;
        }
        case howl_owl2_RawAxiom_ra_builtin_role:
        {
            __auto_type _ = _mv_1615.data.ra_builtin_role;
            return 0;
        }
        case howl_owl2_RawAxiom_ra_anonymous_individual:
        {
            __auto_type _ = _mv_1615.data.ra_anonymous_individual;
            return 0;
        }
        case howl_owl2_RawAxiom_ra_reserved_vocabulary:
        {
            __auto_type _ = _mv_1615.data.ra_reserved_vocabulary;
            return 0;
        }
        case howl_owl2_RawAxiom_ra_swrl_rule:
        {
            __auto_type _ = _mv_1615.data.ra_swrl_rule;
            return 0;
        }
        case howl_owl2_RawAxiom_ra_unrecognized:
        {
            __auto_type _ = _mv_1615.data.ra_unrecognized;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_slop_rdf_rdf_IRI howl_locality_axiom_symbols(slop_arena* arena, howl_owl2_RawAxiom ax) {
    {
        __auto_type out = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        howl_locality_add_axiom_symbols(ax, out);
        return ({ slop_set_elements_result _r = slop_set_elements_raw(arena, out); (slop_list_slop_rdf_rdf_IRI){.data = (slop_rdf_rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
    }
}

void howl_locality_add_axiom_symbols(howl_owl2_RawAxiom ax, slop_map* out) {
    __auto_type _mv_1616 = ax;
    switch (_mv_1616.tag) {
        case howl_owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type c = _mv_1616.data.ra_sub_class_of.f0;
            __auto_type d = _mv_1616.data.ra_sub_class_of.f1;
            howl_locality_add_concept_symbols((*c), out);
            howl_locality_add_concept_symbols((*d), out);
            break;
        }
        case howl_owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type cs = _mv_1616.data.ra_equivalent_classes;
            howl_locality_add_concepts_symbols(cs, out);
            break;
        }
        case howl_owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_1616.data.ra_disjoint_classes;
            howl_locality_add_concepts_symbols(cs, out);
            break;
        }
        case howl_owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type r = _mv_1616.data.ra_sub_object_property.f0;
            __auto_type q = _mv_1616.data.ra_sub_object_property.f1;
            howl_locality_add_role(r, out);
            howl_locality_add_role(q, out);
            break;
        }
        case howl_owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_1616.data.ra_property_chain;
            howl_locality_add_roles(ch.steps, out);
            howl_locality_add_role(ch.super, out);
            break;
        }
        case howl_owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type rs = _mv_1616.data.ra_equivalent_properties;
            howl_locality_add_roles(rs, out);
            break;
        }
        case howl_owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type r = _mv_1616.data.ra_transitive_property;
            howl_locality_add_role(r, out);
            break;
        }
        case howl_owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_1616.data.ra_object_property_domain.f0;
            __auto_type c = _mv_1616.data.ra_object_property_domain.f1;
            howl_locality_add_role(r, out);
            howl_locality_add_concept_symbols((*c), out);
            break;
        }
        case howl_owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type r = _mv_1616.data.ra_object_property_range.f0;
            __auto_type c = _mv_1616.data.ra_object_property_range.f1;
            howl_locality_add_role(r, out);
            howl_locality_add_concept_symbols((*c), out);
            break;
        }
        case howl_owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_1616.data.ra_class_assertion;
            howl_locality_add_concept_symbols((*ca.concept), out);
            howl_locality_add_node(ca.subject, out);
            break;
        }
        case howl_owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type e = _mv_1616.data.ra_object_property_assertion;
            howl_locality_add_edge(e, out);
            break;
        }
        case howl_owl2_RawAxiom_ra_declaration:
        {
            __auto_type d = _mv_1616.data.ra_declaration;
            ({ slop_map_put(NULL, out, &(d.entity), NULL, 0); });
            break;
        }
        case howl_owl2_RawAxiom_ra_annotation:
        {
            break;
        }
        case howl_owl2_RawAxiom_ra_inert_data:
        {
            break;
        }
        case howl_owl2_RawAxiom_ra_inverse_properties:
        {
            __auto_type r = _mv_1616.data.ra_inverse_properties.f0;
            __auto_type q = _mv_1616.data.ra_inverse_properties.f1;
            howl_locality_add_role(r, out);
            howl_locality_add_role(q, out);
            break;
        }
        case howl_owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type r = _mv_1616.data.ra_property_characteristic.f1;
            howl_locality_add_role(r, out);
            break;
        }
        case howl_owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type rs = _mv_1616.data.ra_disjoint_properties;
            howl_locality_add_roles(rs, out);
            break;
        }
        case howl_owl2_RawAxiom_ra_same_individual:
        {
            __auto_type ns = _mv_1616.data.ra_same_individual;
            howl_locality_add_nodes(ns, out);
            break;
        }
        case howl_owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type ns = _mv_1616.data.ra_different_individuals;
            howl_locality_add_nodes(ns, out);
            break;
        }
        case howl_owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type e = _mv_1616.data.ra_negative_assertion;
            howl_locality_add_edge(e, out);
            break;
        }
        case howl_owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type du = _mv_1616.data.ra_disjoint_union;
            ({ slop_map_put(NULL, out, &(du.class), NULL, 0); });
            howl_locality_add_concepts_symbols(du.members, out);
            break;
        }
        case howl_owl2_RawAxiom_ra_has_key:
        {
            __auto_type _ = _mv_1616.data.ra_has_key;
            break;
        }
        case howl_owl2_RawAxiom_ra_data_axiom:
        {
            __auto_type _ = _mv_1616.data.ra_data_axiom;
            break;
        }
        case howl_owl2_RawAxiom_ra_builtin_role:
        {
            __auto_type _ = _mv_1616.data.ra_builtin_role;
            break;
        }
        case howl_owl2_RawAxiom_ra_anonymous_individual:
        {
            __auto_type _ = _mv_1616.data.ra_anonymous_individual;
            break;
        }
        case howl_owl2_RawAxiom_ra_reserved_vocabulary:
        {
            __auto_type _ = _mv_1616.data.ra_reserved_vocabulary;
            break;
        }
        case howl_owl2_RawAxiom_ra_swrl_rule:
        {
            __auto_type _ = _mv_1616.data.ra_swrl_rule;
            break;
        }
        case howl_owl2_RawAxiom_ra_unrecognized:
        {
            __auto_type _ = _mv_1616.data.ra_unrecognized;
            break;
        }
    }
}

void howl_locality_add_concept_symbols(howl_owl2_RawConcept c, slop_map* out) {
    __auto_type _mv_1619 = c;
    switch (_mv_1619.tag) {
        case howl_owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_1619.data.rc_name;
            howl_locality_add_node(n, out);
            break;
        }
        case howl_owl2_RawConcept_rc_thing:
        {
            break;
        }
        case howl_owl2_RawConcept_rc_nothing:
        {
            break;
        }
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_1619.data.rc_and;
            howl_locality_add_concepts_symbols(cs, out);
            break;
        }
        case howl_owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_1619.data.rc_some.f0;
            __auto_type f = _mv_1619.data.rc_some.f1;
            howl_locality_add_role(r, out);
            howl_locality_add_concept_symbols((*f), out);
            break;
        }
        case howl_owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_1619.data.rc_or;
            howl_locality_add_concepts_symbols(cs, out);
            break;
        }
        case howl_owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_1619.data.rc_not;
            howl_locality_add_concept_symbols((*f), out);
            break;
        }
        case howl_owl2_RawConcept_rc_all:
        {
            __auto_type r = _mv_1619.data.rc_all.f0;
            __auto_type f = _mv_1619.data.rc_all.f1;
            howl_locality_add_role(r, out);
            howl_locality_add_concept_symbols((*f), out);
            break;
        }
        case howl_owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_1619.data.rc_oneof;
            howl_locality_add_nodes(ns, out);
            break;
        }
        case howl_owl2_RawConcept_rc_has_value:
        {
            __auto_type r = _mv_1619.data.rc_has_value.f0;
            __auto_type n = _mv_1619.data.rc_has_value.f1;
            howl_locality_add_role(r, out);
            howl_locality_add_node(n, out);
            break;
        }
        case howl_owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_1619.data.rc_has_self;
            howl_locality_add_role(r, out);
            break;
        }
        case howl_owl2_RawConcept_rc_card:
        {
            __auto_type r = _mv_1619.data.rc_card.f1;
            howl_locality_add_role(r, out);
            break;
        }
        case howl_owl2_RawConcept_rc_qcard:
        {
            __auto_type r = _mv_1619.data.rc_qcard.f1;
            __auto_type f = _mv_1619.data.rc_qcard.f3;
            howl_locality_add_role(r, out);
            howl_locality_add_concept_symbols((*f), out);
            break;
        }
        case howl_owl2_RawConcept_rc_data:
        {
            __auto_type _ = _mv_1619.data.rc_data;
            break;
        }
        case howl_owl2_RawConcept_rc_anon:
        {
            __auto_type _ = _mv_1619.data.rc_anon;
            break;
        }
    }
}

void howl_locality_add_concepts_symbols(slop_list_howl_owl2_RawConcept cs, slop_map* out) {
    {
        __auto_type _coll = cs;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type c = _coll.data[_i];
            howl_locality_add_concept_symbols(c, out);
        }
    }
}

void howl_locality_add_role(howl_types_RoleId r, slop_map* out) {
    __auto_type _mv_1620 = r;
    switch (_mv_1620.tag) {
        case howl_types_RoleId_named_role:
        {
            __auto_type i = _mv_1620.data.named_role;
            ({ slop_map_put(NULL, out, &(i), NULL, 0); });
            break;
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type i = _mv_1620.data.inverse_role;
            ({ slop_map_put(NULL, out, &(i), NULL, 0); });
            break;
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_1620.data.fresh_role;
            break;
        }
    }
}

void howl_locality_add_roles(slop_list_howl_types_RoleId rs, slop_map* out) {
    {
        __auto_type _coll = rs;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type r = _coll.data[_i];
            howl_locality_add_role(r, out);
        }
    }
}

void howl_locality_add_node(howl_types_Node n, slop_map* out) {
    __auto_type _mv_1623 = n;
    switch (_mv_1623.tag) {
        case howl_types_Node_class_node:
        {
            __auto_type i = _mv_1623.data.class_node;
            ({ slop_map_put(NULL, out, &(i), NULL, 0); });
            break;
        }
        case howl_types_Node_individual_node:
        {
            __auto_type i = _mv_1623.data.individual_node;
            ({ slop_map_put(NULL, out, &(i), NULL, 0); });
            break;
        }
        case howl_types_Node_fresh_node:
        {
            __auto_type _ = _mv_1623.data.fresh_node;
            break;
        }
    }
}

void howl_locality_add_nodes(slop_list_howl_types_Node ns, slop_map* out) {
    {
        __auto_type _coll = ns;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type n = _coll.data[_i];
            howl_locality_add_node(n, out);
        }
    }
}

void howl_locality_add_edge(howl_owl2_RawEdge e, slop_map* out) {
    howl_locality_add_role(e.role, out);
    howl_locality_add_node(e.from, out);
    howl_locality_add_node(e.to, out);
}

uint8_t howl_locality_axiom_readable(howl_owl2_RawAxiom ax) {
    __auto_type _mv_1626 = ax;
    switch (_mv_1626.tag) {
        case howl_owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type c = _mv_1626.data.ra_sub_class_of.f0;
            __auto_type d = _mv_1626.data.ra_sub_class_of.f1;
            return (howl_locality_concept_readable((*c)) && howl_locality_concept_readable((*d)));
        }
        case howl_owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type cs = _mv_1626.data.ra_equivalent_classes;
            return howl_locality_concepts_readable(cs);
        }
        case howl_owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_1626.data.ra_disjoint_classes;
            return howl_locality_concepts_readable(cs);
        }
        case howl_owl2_RawAxiom_ra_sub_object_property:
        {
            return 1;
        }
        case howl_owl2_RawAxiom_ra_property_chain:
        {
            __auto_type _ = _mv_1626.data.ra_property_chain;
            return 1;
        }
        case howl_owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type _ = _mv_1626.data.ra_equivalent_properties;
            return 1;
        }
        case howl_owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type _ = _mv_1626.data.ra_transitive_property;
            return 1;
        }
        case howl_owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type c = _mv_1626.data.ra_object_property_domain.f1;
            return howl_locality_concept_readable((*c));
        }
        case howl_owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type c = _mv_1626.data.ra_object_property_range.f1;
            return howl_locality_concept_readable((*c));
        }
        case howl_owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_1626.data.ra_class_assertion;
            return howl_locality_concept_readable((*ca.concept));
        }
        case howl_owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type _ = _mv_1626.data.ra_object_property_assertion;
            return 1;
        }
        case howl_owl2_RawAxiom_ra_declaration:
        {
            __auto_type _ = _mv_1626.data.ra_declaration;
            return 1;
        }
        case howl_owl2_RawAxiom_ra_annotation:
        {
            return 1;
        }
        case howl_owl2_RawAxiom_ra_inert_data:
        {
            return 1;
        }
        case howl_owl2_RawAxiom_ra_inverse_properties:
        {
            return 1;
        }
        case howl_owl2_RawAxiom_ra_property_characteristic:
        {
            return 1;
        }
        case howl_owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type _ = _mv_1626.data.ra_disjoint_properties;
            return 1;
        }
        case howl_owl2_RawAxiom_ra_same_individual:
        {
            __auto_type _ = _mv_1626.data.ra_same_individual;
            return 1;
        }
        case howl_owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type _ = _mv_1626.data.ra_different_individuals;
            return 1;
        }
        case howl_owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type _ = _mv_1626.data.ra_negative_assertion;
            return 1;
        }
        case howl_owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type du = _mv_1626.data.ra_disjoint_union;
            return howl_locality_concepts_readable(du.members);
        }
        case howl_owl2_RawAxiom_ra_has_key:
        {
            __auto_type _ = _mv_1626.data.ra_has_key;
            return 0;
        }
        case howl_owl2_RawAxiom_ra_data_axiom:
        {
            __auto_type _ = _mv_1626.data.ra_data_axiom;
            return 0;
        }
        case howl_owl2_RawAxiom_ra_builtin_role:
        {
            __auto_type _ = _mv_1626.data.ra_builtin_role;
            return 0;
        }
        case howl_owl2_RawAxiom_ra_anonymous_individual:
        {
            __auto_type _ = _mv_1626.data.ra_anonymous_individual;
            return 0;
        }
        case howl_owl2_RawAxiom_ra_reserved_vocabulary:
        {
            __auto_type _ = _mv_1626.data.ra_reserved_vocabulary;
            return 0;
        }
        case howl_owl2_RawAxiom_ra_swrl_rule:
        {
            __auto_type _ = _mv_1626.data.ra_swrl_rule;
            return 0;
        }
        case howl_owl2_RawAxiom_ra_unrecognized:
        {
            __auto_type _ = _mv_1626.data.ra_unrecognized;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_locality_concept_readable(howl_owl2_RawConcept c) {
    __auto_type _mv_1627 = c;
    switch (_mv_1627.tag) {
        case howl_owl2_RawConcept_rc_name:
        {
            __auto_type _ = _mv_1627.data.rc_name;
            return 1;
        }
        case howl_owl2_RawConcept_rc_thing:
        {
            return 1;
        }
        case howl_owl2_RawConcept_rc_nothing:
        {
            return 1;
        }
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_1627.data.rc_and;
            return howl_locality_concepts_readable(cs);
        }
        case howl_owl2_RawConcept_rc_some:
        {
            __auto_type f = _mv_1627.data.rc_some.f1;
            return howl_locality_concept_readable((*f));
        }
        case howl_owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_1627.data.rc_or;
            return howl_locality_concepts_readable(cs);
        }
        case howl_owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_1627.data.rc_not;
            return howl_locality_concept_readable((*f));
        }
        case howl_owl2_RawConcept_rc_all:
        {
            __auto_type f = _mv_1627.data.rc_all.f1;
            return howl_locality_concept_readable((*f));
        }
        case howl_owl2_RawConcept_rc_oneof:
        {
            __auto_type _ = _mv_1627.data.rc_oneof;
            return 1;
        }
        case howl_owl2_RawConcept_rc_has_value:
        {
            return 1;
        }
        case howl_owl2_RawConcept_rc_has_self:
        {
            __auto_type _ = _mv_1627.data.rc_has_self;
            return 1;
        }
        case howl_owl2_RawConcept_rc_card:
        {
            return 1;
        }
        case howl_owl2_RawConcept_rc_qcard:
        {
            __auto_type f = _mv_1627.data.rc_qcard.f3;
            return howl_locality_concept_readable((*f));
        }
        case howl_owl2_RawConcept_rc_data:
        {
            __auto_type _ = _mv_1627.data.rc_data;
            return 0;
        }
        case howl_owl2_RawConcept_rc_anon:
        {
            __auto_type _ = _mv_1627.data.rc_anon;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_locality_concepts_readable(slop_list_howl_owl2_RawConcept cs) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(howl_locality_concept_readable(c))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

howl_locality_ModuleOut howl_locality_module_axioms(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_list_slop_rdf_rdf_IRI seed) {
    {
        __auto_type s = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type sigs = howl_locality_symbols_of(arena, axs);
        __auto_type index = howl_locality_symbol_index(arena, sigs);
        __auto_type in_m = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type queue = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t head = 0;
        int64_t i = 0;
        {
            __auto_type _coll = seed;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ slop_map_put(NULL, s, &(x), NULL, 0); }));
            }
        }
        while (i < ((int64_t)(((int64_t)((axs).len))))) {
            (void)(({ __auto_type _lst_p = &(in_m); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(queue); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            i = (i + 1);
        }
        while (head < ((int64_t)(((int64_t)((queue).len))))) {
            {
                __auto_type k = howl_locality_int_of(queue, head);
                head = (head + 1);
                if (!(howl_locality_bool_of(in_m, k)) && !(howl_locality_axiom_local(howl_locality_axiom_of(axs, k), s))) {
                    (void)(({ __auto_type _set_lst = &(in_m); size_t _set_idx = (size_t)(k); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
                    {
                        __auto_type _coll = howl_locality_admit_symbols(arena, howl_locality_sym_of(arena, sigs, k), s, index, in_m);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type j = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(queue); __auto_type _item = (j); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        return ((howl_locality_ModuleOut){.axioms = howl_locality_kept(arena, axs, in_m), .symbols = s, .in_m = in_m});
    }
}

slop_list_int howl_locality_admit_symbols(slop_arena* arena, slop_list_slop_rdf_rdf_IRI syms, slop_map* s, slop_map* index, slop_list_u8 in_m) {
    {
        __auto_type again = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = syms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (!(slop_map_has(s, &(x)))) {
                    (void)(({ slop_map_put(NULL, s, &(x), NULL, 0); }));
                    __auto_type _mv_1632 = ({ void* _ptr = slop_map_get(index, &(x)); _ptr ? (slop_option_list_int){ .has_value = true, .value = *(slop_list_int*)_ptr } : (slop_option_list_int){ .has_value = false }; });
                    if (_mv_1632.has_value) {
                        __auto_type ks = _mv_1632.value;
                        {
                            __auto_type _coll = ks;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type j = _coll.data[_i];
                                if (!(howl_locality_bool_of(in_m, j))) {
                                    ({ __auto_type _lst_p = &(again); __auto_type _item = (j); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    } else if (!_mv_1632.has_value) {
                    }
                }
            }
        }
        return again;
    }
}

slop_list_list_slop_rdf_rdf_IRI howl_locality_symbols_of(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs) {
    {
        __auto_type out = ((slop_list_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_locality_axiom_symbols(arena, ax)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_map* howl_locality_symbol_index(slop_arena* arena, slop_list_list_slop_rdf_rdf_IRI sigs) {
    {
        __auto_type index = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED, slop_list_int); slop_map_new_ptr(arena, 0, &_d); });
        int64_t k = 0;
        {
            __auto_type _coll = sigs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type syms = _coll.data[_i];
                {
                    __auto_type _coll = syms;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        {
                            __auto_type ks = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(index, &(x)); _ptr ? (slop_option_list_int){ .has_value = true, .value = *(slop_list_int*)_ptr } : (slop_option_list_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type l = _mv.value; l; }) : (((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena })); });
                            (void)(({ __auto_type _lst_p = &(ks); __auto_type _item = (k); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            (void)(({ slop_list_int _val = ks; slop_map_put(NULL, index, &(x), &_val, sizeof(_val)); }));
                        }
                    }
                }
                k = (k + 1);
            }
        }
        return index;
    }
}

slop_list_howl_owl2_RawAxiom howl_locality_kept(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_list_u8 in_m) {
    {
        __auto_type out = ((slop_list_howl_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                if (howl_locality_bool_of(in_m, k)) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                k = (k + 1);
            }
        }
        return out;
    }
}

int64_t howl_locality_int_of(slop_list_int xs, int64_t k) {
    __auto_type _mv_1635 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1635.has_value) {
        __auto_type v = _mv_1635.value;
        return v;
    } else if (!_mv_1635.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_locality_bool_of(slop_list_u8 xs, int64_t k) {
    __auto_type _mv_1636 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1636.has_value) {
        __auto_type v = _mv_1636.value;
        return v;
    } else if (!_mv_1636.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

howl_owl2_RawAxiom howl_locality_axiom_of(slop_list_howl_owl2_RawAxiom axs, int64_t k) {
    __auto_type _mv_1637 = ({ __auto_type _lst = axs; size_t _idx = (size_t)k; slop_option_howl_owl2_RawAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1637.has_value) {
        __auto_type a = _mv_1637.value;
        return a;
    } else if (!_mv_1637.has_value) {
        return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_annotation });
    }
    SLOP_UNREACHABLE();
}

slop_list_slop_rdf_rdf_IRI howl_locality_sym_of(slop_arena* arena, slop_list_list_slop_rdf_rdf_IRI sigs, int64_t k) {
    __auto_type _mv_1638 = ({ __auto_type _lst = sigs; size_t _idx = (size_t)k; slop_option_list_slop_rdf_rdf_IRI _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1638.has_value) {
        __auto_type l = _mv_1638.value;
        return l;
    } else if (!_mv_1638.has_value) {
        return ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

howl_normalize_Decoded howl_locality_module_decoded(slop_arena* arena, howl_normalize_Decoded d, slop_list_slop_rdf_rdf_IRI seed) {
    {
        __auto_type m = howl_locality_module_axioms(arena, d.axioms, seed);
        return ((howl_normalize_Decoded){.axioms = m.axioms, .signature = howl_locality_restricted(arena, d.signature, m.symbols), .omissions = d.omissions, .documents = d.documents, .axiom_docs = howl_locality_kept_docs(arena, d.axiom_docs, m.in_m), .omission_docs = d.omission_docs});
    }
}

slop_list_int howl_locality_kept_docs(slop_arena* arena, slop_list_int docs, slop_list_u8 in_m) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = docs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (howl_locality_bool_of(in_m, k)) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                k = (k + 1);
            }
        }
        return out;
    }
}

howl_owl2_Signature howl_locality_restricted(slop_arena* arena, howl_owl2_Signature sig, slop_map* s) {
    return ((howl_owl2_Signature){.classes = howl_locality_within(arena, sig.classes, s), .obj_props = howl_locality_within(arena, sig.obj_props, s), .data_props = sig.data_props, .annot_props = sig.annot_props, .individuals = howl_locality_within(arena, sig.individuals, s), .datatypes = sig.datatypes});
}

slop_map* howl_locality_within(slop_arena* arena, slop_map* xs, slop_map* s) {
    {
        __auto_type out = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, xs); (slop_list_slop_rdf_rdf_IRI){.data = (slop_rdf_rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (slop_map_has(s, &(x)) || howl_locality_owl_own(x)) {
                    (void)(({ slop_map_put(NULL, out, &(x), NULL, 0); }));
                }
            }
        }
        return out;
    }
}

