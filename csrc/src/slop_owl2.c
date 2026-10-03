#include "../runtime/slop_runtime.h"
#include "slop_owl2.h"

owl2_Disposition owl2_disposition(types_Profile p, owl2_RawAxiom ax);
owl2_Signature owl2_make_signature(slop_arena* arena);
uint8_t owl2_signature_has_class(owl2_Signature sig, rdf_IRI i);
uint8_t owl2_signature_has_object_property(owl2_Signature sig, rdf_IRI i);
uint8_t owl2_signature_has_annotation_property(owl2_Signature sig, rdf_IRI i);
uint8_t owl2_signature_has_data_property(owl2_Signature sig, rdf_IRI i);
int64_t owl2_signature_size(slop_arena* arena, owl2_Signature sig);
uint8_t owl2_is_el_plus_plus(types_Profile p);
owl2_Disposition owl2_when_el_plus_plus(types_Profile p);
uint8_t owl2_role_in_profile(types_Profile p, types_RoleId r);
uint8_t owl2_roles_in_profile(types_Profile p, slop_list_types_RoleId rs);
uint8_t owl2_concepts_in_profile(types_Profile p, slop_list_owl2_RawConcept cs);
uint8_t owl2_concept_in_profile(types_Profile p, owl2_RawConcept c);
uint8_t owl2_axiom_in_profile(types_Profile p, owl2_RawAxiom ax);
int64_t owl2_concept_tag_rank(owl2_RawConcept c);
int64_t owl2_concept_list_cmp(slop_list_owl2_RawConcept a, slop_list_owl2_RawConcept b);
owl2_RawConcept owl2_concept_at(slop_list_owl2_RawConcept xs, int64_t i);
int64_t owl2_concept_cmp(owl2_RawConcept a, owl2_RawConcept b);
slop_string owl2_render_role(types_RoleId r);
slop_string owl2_render_node(types_Node n);
slop_string owl2_render_card_kind(owl2_CardKind k);
slop_string owl2_render_concept_list(slop_arena* arena, slop_list_owl2_RawConcept cs);
slop_string owl2_render_node_list(slop_arena* arena, slop_list_types_Node ns);
slop_string owl2_render_role_list(slop_arena* arena, slop_list_types_RoleId rs);
slop_string owl2_wrap(slop_arena* arena, slop_string head, slop_string body);
slop_string owl2_join2(slop_arena* arena, slop_string a, slop_string b);
slop_string owl2_render_concept(slop_arena* arena, owl2_RawConcept c);
slop_string owl2_render_input_ref(types_InputRef r);
slop_string owl2_render_entity_kind(types_EntityKind k);
slop_string owl2_render_omission(slop_arena* arena, types_Omission o);
slop_string owl2_render_axiom(slop_arena* arena, owl2_RawAxiom ax);
slop_string owl2_render_characteristic(owl2_PropCharacteristic c);
owl2_RawConcept owl2_copy_concept(slop_arena* arena, owl2_RawConcept c);
owl2_RawConcept* owl2_copy_boxed(slop_arena* arena, owl2_RawConcept* p);
slop_list_owl2_RawConcept owl2_copy_concepts(slop_arena* arena, slop_list_owl2_RawConcept cs);
slop_list_types_Node owl2_copy_nodes(slop_arena* arena, slop_list_types_Node ns);
slop_list_types_RoleId owl2_copy_roles(slop_arena* arena, slop_list_types_RoleId rs);
owl2_RawAxiom owl2_copy_raw_axiom(slop_arena* arena, owl2_RawAxiom ax);
owl2_RawAxiom owl2_raw_axiom_at(slop_list_owl2_RawAxiom xs, int64_t i);
slop_list_owl2_RawAxiom owl2_copy_axioms(slop_arena* arena, slop_list_owl2_RawAxiom xs);
owl2_Signature owl2_copy_signature(slop_arena* arena, owl2_Signature sig);
slop_list_owl2_RawConcept owl2_sort_concepts(slop_arena* arena, slop_list_owl2_RawConcept xs);

typedef struct { slop_list_owl2_RawConcept xs; } owl2__lambda_136_env_t;

static int64_t owl2__lambda_136(owl2__lambda_136_env_t* _env, int64_t i, int64_t j) { return owl2_concept_cmp(owl2_concept_at(_env->xs, i), owl2_concept_at(_env->xs, j)); }

owl2_Disposition owl2_disposition(types_Profile p, owl2_RawAxiom ax) {
    __auto_type _mv_98 = ax;
    switch (_mv_98.tag) {
        case owl2_RawAxiom_ra_sub_class_of:
        {
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type _ = _mv_98.data.ra_equivalent_classes;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type _ = _mv_98.data.ra_disjoint_classes;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_sub_object_property:
        {
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_property_chain:
        {
            __auto_type _ = _mv_98.data.ra_property_chain;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type _ = _mv_98.data.ra_equivalent_properties;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type _ = _mv_98.data.ra_transitive_property;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_object_property_domain:
        {
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_object_property_range:
        {
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type _ = _mv_98.data.ra_class_assertion;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type _ = _mv_98.data.ra_object_property_assertion;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_declaration:
        {
            __auto_type _ = _mv_98.data.ra_declaration;
            return owl2_Disposition_d_consumed;
        }
        case owl2_RawAxiom_ra_annotation:
        {
            return owl2_Disposition_d_inert;
        }
        case owl2_RawAxiom_ra_inverse_properties:
        {
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_property_characteristic:
        {
            return owl2_when_el_plus_plus(p);
        }
        case owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type _ = _mv_98.data.ra_disjoint_properties;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_same_individual:
        {
            __auto_type _ = _mv_98.data.ra_same_individual;
            return owl2_when_el_plus_plus(p);
        }
        case owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type _ = _mv_98.data.ra_different_individuals;
            return owl2_when_el_plus_plus(p);
        }
        case owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type _ = _mv_98.data.ra_negative_assertion;
            return owl2_when_el_plus_plus(p);
        }
        case owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type _ = _mv_98.data.ra_disjoint_union;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_has_key:
        {
            __auto_type _ = _mv_98.data.ra_has_key;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_inverse_expression:
        {
            __auto_type _ = _mv_98.data.ra_inverse_expression;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_data_axiom:
        {
            __auto_type _ = _mv_98.data.ra_data_axiom;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_builtin_role:
        {
            __auto_type _ = _mv_98.data.ra_builtin_role;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_anonymous_individual:
        {
            __auto_type _ = _mv_98.data.ra_anonymous_individual;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_reserved_vocabulary:
        {
            __auto_type _ = _mv_98.data.ra_reserved_vocabulary;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_swrl_rule:
        {
            __auto_type _ = _mv_98.data.ra_swrl_rule;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_unrecognized:
        {
            __auto_type _ = _mv_98.data.ra_unrecognized;
            return owl2_Disposition_d_out_of_profile;
        }
    }
    SLOP_UNREACHABLE();
}

owl2_Signature owl2_make_signature(slop_arena* arena) {
    return ((owl2_Signature){.classes = ({ static const slop_map_desc _d = SLOP_SET_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .obj_props = ({ static const slop_map_desc _d = SLOP_SET_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .data_props = ({ static const slop_map_desc _d = SLOP_SET_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .annot_props = ({ static const slop_map_desc _d = SLOP_SET_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .individuals = ({ static const slop_map_desc _d = SLOP_SET_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .datatypes = ({ static const slop_map_desc _d = SLOP_SET_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); })});
}

uint8_t owl2_signature_has_class(owl2_Signature sig, rdf_IRI i) {
    return slop_map_has(sig.classes, &(i));
}

uint8_t owl2_signature_has_object_property(owl2_Signature sig, rdf_IRI i) {
    return slop_map_has(sig.obj_props, &(i));
}

uint8_t owl2_signature_has_annotation_property(owl2_Signature sig, rdf_IRI i) {
    return slop_map_has(sig.annot_props, &(i));
}

uint8_t owl2_signature_has_data_property(owl2_Signature sig, rdf_IRI i) {
    return slop_map_has(sig.data_props, &(i));
}

int64_t owl2_signature_size(slop_arena* arena, owl2_Signature sig) {
    return (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.classes); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; })).len)))) + (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.obj_props); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; })).len)))) + (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.data_props); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; })).len)))) + (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.annot_props); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; })).len)))) + (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.individuals); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; })).len)))) + ((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.datatypes); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; })).len)))))))));
}

uint8_t owl2_is_el_plus_plus(types_Profile p) {
    uint8_t _retval = {0};
    __auto_type _mv_103 = p;
    if (_mv_103 == types_Profile_profile_el) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_103 == types_Profile_profile_el_plus_plus) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_103 == types_Profile_profile_horn_sriq) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_103 == types_Profile_profile_sriq) {
        _retval = 0;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST(((_retval == (p == types_Profile_profile_el_plus_plus))), "(== $result (== p (quote profile-el-plus-plus)))");
    return _retval;
}

owl2_Disposition owl2_when_el_plus_plus(types_Profile p) {
    owl2_Disposition _retval = {0};
    if (owl2_is_el_plus_plus(p)) {
        _retval = owl2_Disposition_d_in_profile;
        goto _slop_post;
    } else {
        _retval = owl2_Disposition_d_out_of_profile;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((_retval == owl2_Disposition_d_in_profile) == (p == types_Profile_profile_el_plus_plus))), "(== (== $result (quote d-in-profile)) (== p (quote profile-el-plus-plus)))");
    return _retval;
}

uint8_t owl2_role_in_profile(types_Profile p, types_RoleId r) {
    __auto_type _mv_104 = r;
    switch (_mv_104.tag) {
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_104.data.fresh_role;
            return 1;
        }
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_104.data.named_role;
            if (canon_string_cmp(i.value, vocab_OWL_BOTTOM_OBJECT_PROPERTY) == 0) {
                return owl2_is_el_plus_plus(p);
            } else if (canon_string_cmp(i.value, vocab_OWL_TOP_OBJECT_PROPERTY) == 0) {
                return 0;
            } else if (canon_string_cmp(i.value, vocab_OWL_TOP_DATA_PROPERTY) == 0) {
                return 0;
            } else if (canon_string_cmp(i.value, vocab_OWL_BOTTOM_DATA_PROPERTY) == 0) {
                return 0;
            } else {
                return 1;
            }
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t owl2_roles_in_profile(types_Profile p, slop_list_types_RoleId rs) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                if (!(owl2_role_in_profile(p, r))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t owl2_concepts_in_profile(types_Profile p, slop_list_owl2_RawConcept cs) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(owl2_concept_in_profile(p, c))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t owl2_concept_in_profile(types_Profile p, owl2_RawConcept c) {
    __auto_type _mv_105 = c;
    switch (_mv_105.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type _ = _mv_105.data.rc_name;
            return 1;
        }
        case owl2_RawConcept_rc_thing:
        {
            return 1;
        }
        case owl2_RawConcept_rc_nothing:
        {
            return 1;
        }
        case owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_105.data.rc_and;
            return owl2_concepts_in_profile(p, cs);
        }
        case owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_105.data.rc_some.f0;
            __auto_type f = _mv_105.data.rc_some.f1;
            return (owl2_role_in_profile(p, r) && owl2_concept_in_profile(p, (*f)));
        }
        case owl2_RawConcept_rc_or:
        {
            __auto_type _ = _mv_105.data.rc_or;
            return 0;
        }
        case owl2_RawConcept_rc_not:
        {
            __auto_type _ = _mv_105.data.rc_not;
            return 0;
        }
        case owl2_RawConcept_rc_all:
        {
            return 0;
        }
        case owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_105.data.rc_oneof;
            return (owl2_is_el_plus_plus(p) && (((int64_t)((ns).len)) == 1));
        }
        case owl2_RawConcept_rc_has_value:
        {
            __auto_type r = _mv_105.data.rc_has_value.f0;
            return (owl2_is_el_plus_plus(p) && owl2_role_in_profile(p, r));
        }
        case owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_105.data.rc_has_self;
            return (owl2_is_el_plus_plus(p) && owl2_role_in_profile(p, r));
        }
        case owl2_RawConcept_rc_card:
        {
            return 0;
        }
        case owl2_RawConcept_rc_qcard:
        {
            return 0;
        }
        case owl2_RawConcept_rc_data:
        {
            __auto_type _ = _mv_105.data.rc_data;
            return 0;
        }
        case owl2_RawConcept_rc_anon:
        {
            __auto_type _ = _mv_105.data.rc_anon;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t owl2_axiom_in_profile(types_Profile p, owl2_RawAxiom ax) {
    if (owl2_disposition(p, ax) != owl2_Disposition_d_in_profile) {
        return 0;
    } else {
        __auto_type _mv_106 = ax;
        switch (_mv_106.tag) {
            case owl2_RawAxiom_ra_sub_class_of:
            {
                __auto_type l = _mv_106.data.ra_sub_class_of.f0;
                __auto_type r = _mv_106.data.ra_sub_class_of.f1;
                return (owl2_concept_in_profile(p, (*l)) && owl2_concept_in_profile(p, (*r)));
            }
            case owl2_RawAxiom_ra_equivalent_classes:
            {
                __auto_type cs = _mv_106.data.ra_equivalent_classes;
                return owl2_concepts_in_profile(p, cs);
            }
            case owl2_RawAxiom_ra_disjoint_classes:
            {
                __auto_type cs = _mv_106.data.ra_disjoint_classes;
                return owl2_concepts_in_profile(p, cs);
            }
            case owl2_RawAxiom_ra_object_property_domain:
            {
                __auto_type r = _mv_106.data.ra_object_property_domain.f0;
                __auto_type c = _mv_106.data.ra_object_property_domain.f1;
                return (owl2_role_in_profile(p, r) && owl2_concept_in_profile(p, (*c)));
            }
            case owl2_RawAxiom_ra_object_property_range:
            {
                __auto_type r = _mv_106.data.ra_object_property_range.f0;
                __auto_type c = _mv_106.data.ra_object_property_range.f1;
                return (owl2_role_in_profile(p, r) && owl2_concept_in_profile(p, (*c)));
            }
            case owl2_RawAxiom_ra_class_assertion:
            {
                __auto_type ca = _mv_106.data.ra_class_assertion;
                return owl2_concept_in_profile(p, (*ca.concept));
            }
            case owl2_RawAxiom_ra_sub_object_property:
            {
                __auto_type a = _mv_106.data.ra_sub_object_property.f0;
                __auto_type b = _mv_106.data.ra_sub_object_property.f1;
                return (owl2_role_in_profile(p, a) && owl2_role_in_profile(p, b));
            }
            case owl2_RawAxiom_ra_property_chain:
            {
                __auto_type ch = _mv_106.data.ra_property_chain;
                return (owl2_roles_in_profile(p, ch.steps) && owl2_role_in_profile(p, ch.super));
            }
            case owl2_RawAxiom_ra_equivalent_properties:
            {
                __auto_type rs = _mv_106.data.ra_equivalent_properties;
                return owl2_roles_in_profile(p, rs);
            }
            case owl2_RawAxiom_ra_transitive_property:
            {
                __auto_type r = _mv_106.data.ra_transitive_property;
                return owl2_role_in_profile(p, r);
            }
            case owl2_RawAxiom_ra_object_property_assertion:
            {
                __auto_type e = _mv_106.data.ra_object_property_assertion;
                return owl2_role_in_profile(p, e.role);
            }
            case owl2_RawAxiom_ra_property_characteristic:
            {
                __auto_type c = _mv_106.data.ra_property_characteristic.f0;
                __auto_type r = _mv_106.data.ra_property_characteristic.f1;
                return ((c == owl2_PropCharacteristic_prop_reflexive) && owl2_role_in_profile(p, r));
            }
            case owl2_RawAxiom_ra_same_individual:
            {
                __auto_type ns = _mv_106.data.ra_same_individual;
                return (((int64_t)((ns).len)) >= 2);
            }
            case owl2_RawAxiom_ra_different_individuals:
            {
                __auto_type ns = _mv_106.data.ra_different_individuals;
                return (((int64_t)((ns).len)) >= 2);
            }
            case owl2_RawAxiom_ra_negative_assertion:
            {
                __auto_type e = _mv_106.data.ra_negative_assertion;
                return owl2_role_in_profile(p, e.role);
            }
            case owl2_RawAxiom_ra_declaration:
            {
                __auto_type _ = _mv_106.data.ra_declaration;
                return 0;
            }
            case owl2_RawAxiom_ra_annotation:
            {
                return 0;
            }
            case owl2_RawAxiom_ra_inverse_properties:
            {
                return 0;
            }
            case owl2_RawAxiom_ra_disjoint_properties:
            {
                __auto_type _ = _mv_106.data.ra_disjoint_properties;
                return 0;
            }
            case owl2_RawAxiom_ra_disjoint_union:
            {
                __auto_type _ = _mv_106.data.ra_disjoint_union;
                return 0;
            }
            case owl2_RawAxiom_ra_has_key:
            {
                __auto_type _ = _mv_106.data.ra_has_key;
                return 0;
            }
            case owl2_RawAxiom_ra_inverse_expression:
            {
                __auto_type _ = _mv_106.data.ra_inverse_expression;
                return 0;
            }
            case owl2_RawAxiom_ra_data_axiom:
            {
                __auto_type _ = _mv_106.data.ra_data_axiom;
                return 0;
            }
            case owl2_RawAxiom_ra_builtin_role:
            {
                __auto_type _ = _mv_106.data.ra_builtin_role;
                return 0;
            }
            case owl2_RawAxiom_ra_anonymous_individual:
            {
                __auto_type _ = _mv_106.data.ra_anonymous_individual;
                return 0;
            }
            case owl2_RawAxiom_ra_reserved_vocabulary:
            {
                __auto_type _ = _mv_106.data.ra_reserved_vocabulary;
                return 0;
            }
            case owl2_RawAxiom_ra_swrl_rule:
            {
                __auto_type _ = _mv_106.data.ra_swrl_rule;
                return 0;
            }
            case owl2_RawAxiom_ra_unrecognized:
            {
                __auto_type _ = _mv_106.data.ra_unrecognized;
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    }
}

int64_t owl2_concept_tag_rank(owl2_RawConcept c) {
    __auto_type _mv_107 = c;
    switch (_mv_107.tag) {
        case owl2_RawConcept_rc_thing:
        {
            return 0;
        }
        case owl2_RawConcept_rc_nothing:
        {
            return 1;
        }
        case owl2_RawConcept_rc_name:
        {
            __auto_type _ = _mv_107.data.rc_name;
            return 2;
        }
        case owl2_RawConcept_rc_and:
        {
            __auto_type _ = _mv_107.data.rc_and;
            return 3;
        }
        case owl2_RawConcept_rc_some:
        {
            return 4;
        }
        case owl2_RawConcept_rc_or:
        {
            __auto_type _ = _mv_107.data.rc_or;
            return 5;
        }
        case owl2_RawConcept_rc_not:
        {
            __auto_type _ = _mv_107.data.rc_not;
            return 6;
        }
        case owl2_RawConcept_rc_all:
        {
            return 7;
        }
        case owl2_RawConcept_rc_oneof:
        {
            __auto_type _ = _mv_107.data.rc_oneof;
            return 8;
        }
        case owl2_RawConcept_rc_has_value:
        {
            return 9;
        }
        case owl2_RawConcept_rc_has_self:
        {
            __auto_type _ = _mv_107.data.rc_has_self;
            return 10;
        }
        case owl2_RawConcept_rc_card:
        {
            return 11;
        }
        case owl2_RawConcept_rc_qcard:
        {
            return 12;
        }
        case owl2_RawConcept_rc_data:
        {
            __auto_type _ = _mv_107.data.rc_data;
            return 13;
        }
        case owl2_RawConcept_rc_anon:
        {
            __auto_type _ = _mv_107.data.rc_anon;
            return 14;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t owl2_concept_list_cmp(slop_list_owl2_RawConcept a, slop_list_owl2_RawConcept b) {
    {
        __auto_type alen = ((int64_t)(((int64_t)((a).len))));
        __auto_type blen = ((int64_t)(((int64_t)((b).len))));
        __auto_type n = ((alen) < (blen) ? (alen) : (blen));
        int64_t i = 0;
        int64_t r = 0;
        while ((i < n) && (r == 0)) {
            r = owl2_concept_cmp(owl2_concept_at(a, i), owl2_concept_at(b, i));
            i = (i + 1);
        }
        if (r != 0) {
            return r;
        } else if (alen < blen) {
            return -1;
        } else if (alen > blen) {
            return 1;
        } else {
            return 0;
        }
    }
}

owl2_RawConcept owl2_concept_at(slop_list_owl2_RawConcept xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_108 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_owl2_RawConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_108.has_value) {
        __auto_type v = _mv_108.value;
        return v;
    } else if (!_mv_108.has_value) {
        return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_thing });
    }
    SLOP_UNREACHABLE();
}

int64_t owl2_concept_cmp(owl2_RawConcept a, owl2_RawConcept b) {
    {
        __auto_type ra = owl2_concept_tag_rank(a);
        __auto_type rb = owl2_concept_tag_rank(b);
        if (ra != rb) {
            if (ra < rb) {
                return -1;
            } else {
                return 1;
            }
        } else {
            __auto_type _mv_109 = a;
            switch (_mv_109.tag) {
                case owl2_RawConcept_rc_name:
                {
                    __auto_type na = _mv_109.data.rc_name;
                    __auto_type _mv_110 = b;
                    switch (_mv_110.tag) {
                        case owl2_RawConcept_rc_name:
                        {
                            __auto_type nb = _mv_110.data.rc_name;
                            return canon_node_cmp(na, nb);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case owl2_RawConcept_rc_and:
                {
                    __auto_type as = _mv_109.data.rc_and;
                    __auto_type _mv_111 = b;
                    switch (_mv_111.tag) {
                        case owl2_RawConcept_rc_and:
                        {
                            __auto_type bs = _mv_111.data.rc_and;
                            return owl2_concept_list_cmp(as, bs);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case owl2_RawConcept_rc_some:
                {
                    __auto_type ra2 = _mv_109.data.rc_some.f0;
                    __auto_type fa = _mv_109.data.rc_some.f1;
                    __auto_type _mv_112 = b;
                    switch (_mv_112.tag) {
                        case owl2_RawConcept_rc_some:
                        {
                            __auto_type rb2 = _mv_112.data.rc_some.f0;
                            __auto_type fb = _mv_112.data.rc_some.f1;
                            {
                                __auto_type rr = canon_role_cmp(ra2, rb2);
                                if (rr != 0) {
                                    return rr;
                                } else {
                                    return owl2_concept_cmp((*fa), (*fb));
                                }
                            }
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case owl2_RawConcept_rc_or:
                {
                    __auto_type as = _mv_109.data.rc_or;
                    __auto_type _mv_113 = b;
                    switch (_mv_113.tag) {
                        case owl2_RawConcept_rc_or:
                        {
                            __auto_type bs = _mv_113.data.rc_or;
                            return owl2_concept_list_cmp(as, bs);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case owl2_RawConcept_rc_not:
                {
                    __auto_type fa = _mv_109.data.rc_not;
                    __auto_type _mv_114 = b;
                    switch (_mv_114.tag) {
                        case owl2_RawConcept_rc_not:
                        {
                            __auto_type fb = _mv_114.data.rc_not;
                            return owl2_concept_cmp((*fa), (*fb));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case owl2_RawConcept_rc_all:
                {
                    __auto_type ra2 = _mv_109.data.rc_all.f0;
                    __auto_type fa = _mv_109.data.rc_all.f1;
                    __auto_type _mv_115 = b;
                    switch (_mv_115.tag) {
                        case owl2_RawConcept_rc_all:
                        {
                            __auto_type rb2 = _mv_115.data.rc_all.f0;
                            __auto_type fb = _mv_115.data.rc_all.f1;
                            {
                                __auto_type rr = canon_role_cmp(ra2, rb2);
                                if (rr != 0) {
                                    return rr;
                                } else {
                                    return owl2_concept_cmp((*fa), (*fb));
                                }
                            }
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case owl2_RawConcept_rc_has_value:
                {
                    __auto_type ra2 = _mv_109.data.rc_has_value.f0;
                    __auto_type na = _mv_109.data.rc_has_value.f1;
                    __auto_type _mv_116 = b;
                    switch (_mv_116.tag) {
                        case owl2_RawConcept_rc_has_value:
                        {
                            __auto_type rb2 = _mv_116.data.rc_has_value.f0;
                            __auto_type nb = _mv_116.data.rc_has_value.f1;
                            {
                                __auto_type rr = canon_role_cmp(ra2, rb2);
                                if (rr != 0) {
                                    return rr;
                                } else {
                                    return canon_node_cmp(na, nb);
                                }
                            }
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case owl2_RawConcept_rc_has_self:
                {
                    __auto_type ra2 = _mv_109.data.rc_has_self;
                    __auto_type _mv_117 = b;
                    switch (_mv_117.tag) {
                        case owl2_RawConcept_rc_has_self:
                        {
                            __auto_type rb2 = _mv_117.data.rc_has_self;
                            return canon_role_cmp(ra2, rb2);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                default: {
                    return 0;
                }
            }
        }
    }
}

slop_string owl2_render_role(types_RoleId r) {
    __auto_type _mv_118 = r;
    switch (_mv_118.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_118.data.named_role;
            return i.value;
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_118.data.fresh_role;
            return SLOP_STR("_:fresh-role");
        }
    }
    SLOP_UNREACHABLE();
}

slop_string owl2_render_node(types_Node n) {
    __auto_type _mv_119 = n;
    switch (_mv_119.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_119.data.class_node;
            return i.value;
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_119.data.individual_node;
            return i.value;
        }
        case types_Node_fresh_node:
        {
            __auto_type _ = _mv_119.data.fresh_node;
            return SLOP_STR("_:fresh-node");
        }
    }
    SLOP_UNREACHABLE();
}

slop_string owl2_render_card_kind(owl2_CardKind k) {
    __auto_type _mv_120 = k;
    if (_mv_120 == owl2_CardKind_card_min) {
        return SLOP_STR("ObjectMinCardinality");
    } else if (_mv_120 == owl2_CardKind_card_max) {
        return SLOP_STR("ObjectMaxCardinality");
    } else if (_mv_120 == owl2_CardKind_card_exact) {
        return SLOP_STR("ObjectExactCardinality");
    }
    SLOP_UNREACHABLE();
}

slop_string owl2_render_concept_list(slop_arena* arena, slop_list_owl2_RawConcept cs) {
    {
        __auto_type out = SLOP_STR("");
        uint8_t first = 1;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(first)) {
                    out = string_concat(arena, out, SLOP_STR(" "));
                }
                out = string_concat(arena, out, owl2_render_concept(arena, c));
                first = 0;
            }
        }
        return out;
    }
}

slop_string owl2_render_node_list(slop_arena* arena, slop_list_types_Node ns) {
    {
        __auto_type out = SLOP_STR("");
        uint8_t first = 1;
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                if (!(first)) {
                    out = string_concat(arena, out, SLOP_STR(" "));
                }
                out = string_concat(arena, out, owl2_render_node(n));
                first = 0;
            }
        }
        return out;
    }
}

slop_string owl2_render_role_list(slop_arena* arena, slop_list_types_RoleId rs) {
    {
        __auto_type out = SLOP_STR("");
        uint8_t first = 1;
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                if (!(first)) {
                    out = string_concat(arena, out, SLOP_STR(" "));
                }
                out = string_concat(arena, out, owl2_render_role(r));
                first = 0;
            }
        }
        return out;
    }
}

slop_string owl2_wrap(slop_arena* arena, slop_string head, slop_string body) {
    return string_concat(arena, head, string_concat(arena, SLOP_STR("("), string_concat(arena, body, SLOP_STR(")"))));
}

slop_string owl2_join2(slop_arena* arena, slop_string a, slop_string b) {
    return string_concat(arena, a, string_concat(arena, SLOP_STR(" "), b));
}

slop_string owl2_render_concept(slop_arena* arena, owl2_RawConcept c) {
    __auto_type _mv_121 = c;
    switch (_mv_121.tag) {
        case owl2_RawConcept_rc_thing:
        {
            return SLOP_STR("owl:Thing");
        }
        case owl2_RawConcept_rc_nothing:
        {
            return SLOP_STR("owl:Nothing");
        }
        case owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_121.data.rc_name;
            return owl2_render_node(n);
        }
        case owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_121.data.rc_and;
            return owl2_wrap(arena, SLOP_STR("ObjectIntersectionOf"), owl2_render_concept_list(arena, cs));
        }
        case owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_121.data.rc_or;
            return owl2_wrap(arena, SLOP_STR("ObjectUnionOf"), owl2_render_concept_list(arena, cs));
        }
        case owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_121.data.rc_not;
            return owl2_wrap(arena, SLOP_STR("ObjectComplementOf"), owl2_render_concept(arena, (*f)));
        }
        case owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_121.data.rc_some.f0;
            __auto_type f = _mv_121.data.rc_some.f1;
            return owl2_wrap(arena, SLOP_STR("ObjectSomeValuesFrom"), owl2_join2(arena, owl2_render_role(r), owl2_render_concept(arena, (*f))));
        }
        case owl2_RawConcept_rc_all:
        {
            __auto_type r = _mv_121.data.rc_all.f0;
            __auto_type f = _mv_121.data.rc_all.f1;
            return owl2_wrap(arena, SLOP_STR("ObjectAllValuesFrom"), owl2_join2(arena, owl2_render_role(r), owl2_render_concept(arena, (*f))));
        }
        case owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_121.data.rc_oneof;
            return owl2_wrap(arena, SLOP_STR("ObjectOneOf"), owl2_render_node_list(arena, ns));
        }
        case owl2_RawConcept_rc_has_value:
        {
            __auto_type r = _mv_121.data.rc_has_value.f0;
            __auto_type n = _mv_121.data.rc_has_value.f1;
            return owl2_wrap(arena, SLOP_STR("ObjectHasValue"), owl2_join2(arena, owl2_render_role(r), owl2_render_node(n)));
        }
        case owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_121.data.rc_has_self;
            return owl2_wrap(arena, SLOP_STR("ObjectHasSelf"), owl2_render_role(r));
        }
        case owl2_RawConcept_rc_card:
        {
            __auto_type k = _mv_121.data.rc_card.f0;
            __auto_type r = _mv_121.data.rc_card.f1;
            __auto_type n = _mv_121.data.rc_card.f2;
            return owl2_wrap(arena, owl2_render_card_kind(k), owl2_join2(arena, int_to_string(arena, n), owl2_render_role(r)));
        }
        case owl2_RawConcept_rc_qcard:
        {
            __auto_type k = _mv_121.data.rc_qcard.f0;
            __auto_type r = _mv_121.data.rc_qcard.f1;
            __auto_type n = _mv_121.data.rc_qcard.f2;
            __auto_type f = _mv_121.data.rc_qcard.f3;
            return owl2_wrap(arena, owl2_render_card_kind(k), owl2_join2(arena, int_to_string(arena, n), owl2_join2(arena, owl2_render_role(r), owl2_render_concept(arena, (*f)))));
        }
        case owl2_RawConcept_rc_data:
        {
            __auto_type ref = _mv_121.data.rc_data;
            return owl2_wrap(arena, SLOP_STR("DataRange"), owl2_render_input_ref(ref));
        }
        case owl2_RawConcept_rc_anon:
        {
            __auto_type ref = _mv_121.data.rc_anon;
            return owl2_wrap(arena, SLOP_STR("AnonymousClass"), owl2_render_input_ref(ref));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string owl2_render_input_ref(types_InputRef r) {
    __auto_type _mv_122 = r;
    switch (_mv_122.tag) {
        case types_InputRef_owl_axiom:
        {
            __auto_type a = _mv_122.data.owl_axiom;
            return a.text;
        }
        case types_InputRef_rdf_fragment:
        {
            __auto_type s = _mv_122.data.rdf_fragment;
            return s;
        }
        case types_InputRef_synthetic:
        {
            __auto_type s = _mv_122.data.synthetic;
            return s;
        }
    }
    SLOP_UNREACHABLE();
}

slop_string owl2_render_entity_kind(types_EntityKind k) {
    __auto_type _mv_123 = k;
    if (_mv_123 == types_EntityKind_entity_class) {
        return SLOP_STR("Class");
    } else if (_mv_123 == types_EntityKind_entity_object_property) {
        return SLOP_STR("ObjectProperty");
    } else if (_mv_123 == types_EntityKind_entity_data_property) {
        return SLOP_STR("DataProperty");
    } else if (_mv_123 == types_EntityKind_entity_annotation_property) {
        return SLOP_STR("AnnotationProperty");
    } else if (_mv_123 == types_EntityKind_entity_individual) {
        return SLOP_STR("NamedIndividual");
    } else if (_mv_123 == types_EntityKind_entity_datatype) {
        return SLOP_STR("Datatype");
    }
    SLOP_UNREACHABLE();
}

slop_string owl2_render_omission(slop_arena* arena, types_Omission o) {
    __auto_type _mv_124 = o;
    switch (_mv_124.tag) {
        case types_Omission_out_of_profile:
        {
            __auto_type ref = _mv_124.data.out_of_profile;
            return owl2_render_input_ref(ref);
        }
        case types_Omission_unresolved_import:
        {
            __auto_type i = _mv_124.data.unresolved_import;
            return owl2_wrap(arena, SLOP_STR("UnresolvedImport"), i.value);
        }
        case types_Omission_missing_declaration:
        {
            __auto_type md = _mv_124.data.missing_declaration;
            return owl2_wrap(arena, SLOP_STR("MissingDeclaration"), owl2_wrap(arena, owl2_render_entity_kind(md.kind), md.entity.value));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string owl2_render_axiom(slop_arena* arena, owl2_RawAxiom ax) {
    __auto_type _mv_125 = ax;
    switch (_mv_125.tag) {
        case owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_125.data.ra_sub_class_of.f0;
            __auto_type r = _mv_125.data.ra_sub_class_of.f1;
            return owl2_wrap(arena, SLOP_STR("SubClassOf"), owl2_join2(arena, owl2_render_concept(arena, (*l)), owl2_render_concept(arena, (*r))));
        }
        case owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type cs = _mv_125.data.ra_equivalent_classes;
            return owl2_wrap(arena, SLOP_STR("EquivalentClasses"), owl2_render_concept_list(arena, cs));
        }
        case owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_125.data.ra_disjoint_classes;
            return owl2_wrap(arena, SLOP_STR("DisjointClasses"), owl2_render_concept_list(arena, cs));
        }
        case owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type a = _mv_125.data.ra_sub_object_property.f0;
            __auto_type b = _mv_125.data.ra_sub_object_property.f1;
            return owl2_wrap(arena, SLOP_STR("SubObjectPropertyOf"), owl2_join2(arena, owl2_render_role(a), owl2_render_role(b)));
        }
        case owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_125.data.ra_property_chain;
            return owl2_wrap(arena, SLOP_STR("SubObjectPropertyOf"), owl2_join2(arena, owl2_wrap(arena, SLOP_STR("ObjectPropertyChain"), owl2_render_role_list(arena, ch.steps)), owl2_render_role(ch.super)));
        }
        case owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type rs = _mv_125.data.ra_equivalent_properties;
            return owl2_wrap(arena, SLOP_STR("EquivalentObjectProperties"), owl2_render_role_list(arena, rs));
        }
        case owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type r = _mv_125.data.ra_transitive_property;
            return owl2_wrap(arena, SLOP_STR("TransitiveObjectProperty"), owl2_render_role(r));
        }
        case owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_125.data.ra_object_property_domain.f0;
            __auto_type c = _mv_125.data.ra_object_property_domain.f1;
            return owl2_wrap(arena, SLOP_STR("ObjectPropertyDomain"), owl2_join2(arena, owl2_render_role(r), owl2_render_concept(arena, (*c))));
        }
        case owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type r = _mv_125.data.ra_object_property_range.f0;
            __auto_type c = _mv_125.data.ra_object_property_range.f1;
            return owl2_wrap(arena, SLOP_STR("ObjectPropertyRange"), owl2_join2(arena, owl2_render_role(r), owl2_render_concept(arena, (*c))));
        }
        case owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_125.data.ra_class_assertion;
            return owl2_wrap(arena, SLOP_STR("ClassAssertion"), owl2_join2(arena, owl2_render_concept(arena, (*ca.concept)), owl2_render_node(ca.subject)));
        }
        case owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type e = _mv_125.data.ra_object_property_assertion;
            return owl2_wrap(arena, SLOP_STR("ObjectPropertyAssertion"), owl2_join2(arena, owl2_render_role(e.role), owl2_join2(arena, owl2_render_node(e.from), owl2_render_node(e.to))));
        }
        case owl2_RawAxiom_ra_declaration:
        {
            __auto_type d = _mv_125.data.ra_declaration;
            return owl2_wrap(arena, SLOP_STR("Declaration"), d.entity.value);
        }
        case owl2_RawAxiom_ra_annotation:
        {
            return SLOP_STR("Annotation()");
        }
        case owl2_RawAxiom_ra_inverse_properties:
        {
            __auto_type a = _mv_125.data.ra_inverse_properties.f0;
            __auto_type b = _mv_125.data.ra_inverse_properties.f1;
            return owl2_wrap(arena, SLOP_STR("InverseObjectProperties"), owl2_join2(arena, owl2_render_role(a), owl2_render_role(b)));
        }
        case owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type c = _mv_125.data.ra_property_characteristic.f0;
            __auto_type r = _mv_125.data.ra_property_characteristic.f1;
            return owl2_wrap(arena, owl2_render_characteristic(c), owl2_render_role(r));
        }
        case owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type rs = _mv_125.data.ra_disjoint_properties;
            return owl2_wrap(arena, SLOP_STR("DisjointObjectProperties"), owl2_render_role_list(arena, rs));
        }
        case owl2_RawAxiom_ra_same_individual:
        {
            __auto_type ns = _mv_125.data.ra_same_individual;
            return owl2_wrap(arena, SLOP_STR("SameIndividual"), owl2_render_node_list(arena, ns));
        }
        case owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type ns = _mv_125.data.ra_different_individuals;
            return owl2_wrap(arena, SLOP_STR("DifferentIndividuals"), owl2_render_node_list(arena, ns));
        }
        case owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type e = _mv_125.data.ra_negative_assertion;
            return owl2_wrap(arena, SLOP_STR("NegativeObjectPropertyAssertion"), owl2_join2(arena, owl2_render_role(e.role), owl2_join2(arena, owl2_render_node(e.from), owl2_render_node(e.to))));
        }
        case owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type ref = _mv_125.data.ra_disjoint_union;
            return owl2_wrap(arena, SLOP_STR("DisjointUnion"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_has_key:
        {
            __auto_type ref = _mv_125.data.ra_has_key;
            return owl2_wrap(arena, SLOP_STR("HasKey"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_inverse_expression:
        {
            __auto_type ref = _mv_125.data.ra_inverse_expression;
            return owl2_wrap(arena, SLOP_STR("ObjectInverseOf"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_data_axiom:
        {
            __auto_type ref = _mv_125.data.ra_data_axiom;
            return owl2_wrap(arena, SLOP_STR("DataAxiom"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_builtin_role:
        {
            __auto_type ref = _mv_125.data.ra_builtin_role;
            return owl2_wrap(arena, SLOP_STR("BuiltinRole"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_anonymous_individual:
        {
            __auto_type ref = _mv_125.data.ra_anonymous_individual;
            return owl2_wrap(arena, SLOP_STR("AnonymousIndividual"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_reserved_vocabulary:
        {
            __auto_type ref = _mv_125.data.ra_reserved_vocabulary;
            return owl2_wrap(arena, SLOP_STR("ReservedVocabulary"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_swrl_rule:
        {
            __auto_type ref = _mv_125.data.ra_swrl_rule;
            return owl2_wrap(arena, SLOP_STR("SWRLRule"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_unrecognized:
        {
            __auto_type ref = _mv_125.data.ra_unrecognized;
            return owl2_wrap(arena, SLOP_STR("Unrecognized"), owl2_render_input_ref(ref));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string owl2_render_characteristic(owl2_PropCharacteristic c) {
    __auto_type _mv_126 = c;
    if (_mv_126 == owl2_PropCharacteristic_prop_functional) {
        return SLOP_STR("FunctionalObjectProperty");
    } else if (_mv_126 == owl2_PropCharacteristic_prop_inverse_functional) {
        return SLOP_STR("InverseFunctionalObjectProperty");
    } else if (_mv_126 == owl2_PropCharacteristic_prop_symmetric) {
        return SLOP_STR("SymmetricObjectProperty");
    } else if (_mv_126 == owl2_PropCharacteristic_prop_asymmetric) {
        return SLOP_STR("AsymmetricObjectProperty");
    } else if (_mv_126 == owl2_PropCharacteristic_prop_reflexive) {
        return SLOP_STR("ReflexiveObjectProperty");
    } else if (_mv_126 == owl2_PropCharacteristic_prop_irreflexive) {
        return SLOP_STR("IrreflexiveObjectProperty");
    }
    SLOP_UNREACHABLE();
}

owl2_RawConcept owl2_copy_concept(slop_arena* arena, owl2_RawConcept c) {
    __auto_type _mv_127 = c;
    switch (_mv_127.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_127.data.rc_name;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_name, .data.rc_name = types_copy_node(arena, n) });
        }
        case owl2_RawConcept_rc_thing:
        {
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_thing });
        }
        case owl2_RawConcept_rc_nothing:
        {
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_nothing });
        }
        case owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_127.data.rc_and;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_and, .data.rc_and = owl2_copy_concepts(arena, cs) });
        }
        case owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_127.data.rc_some.f0;
            __auto_type f = _mv_127.data.rc_some.f1;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_some, .data.rc_some = { .f0 = types_copy_role(arena, r), .f1 = owl2_copy_boxed(arena, f) } });
        }
        case owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_127.data.rc_or;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_or, .data.rc_or = owl2_copy_concepts(arena, cs) });
        }
        case owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_127.data.rc_not;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_not, .data.rc_not = owl2_copy_boxed(arena, f) });
        }
        case owl2_RawConcept_rc_all:
        {
            __auto_type r = _mv_127.data.rc_all.f0;
            __auto_type f = _mv_127.data.rc_all.f1;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_all, .data.rc_all = { .f0 = types_copy_role(arena, r), .f1 = owl2_copy_boxed(arena, f) } });
        }
        case owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_127.data.rc_oneof;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_oneof, .data.rc_oneof = owl2_copy_nodes(arena, ns) });
        }
        case owl2_RawConcept_rc_has_value:
        {
            __auto_type r = _mv_127.data.rc_has_value.f0;
            __auto_type n = _mv_127.data.rc_has_value.f1;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_has_value, .data.rc_has_value = { .f0 = types_copy_role(arena, r), .f1 = types_copy_node(arena, n) } });
        }
        case owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_127.data.rc_has_self;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_has_self, .data.rc_has_self = types_copy_role(arena, r) });
        }
        case owl2_RawConcept_rc_card:
        {
            __auto_type k = _mv_127.data.rc_card.f0;
            __auto_type r = _mv_127.data.rc_card.f1;
            __auto_type n = _mv_127.data.rc_card.f2;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_card, .data.rc_card = { .f0 = k, .f1 = types_copy_role(arena, r), .f2 = n } });
        }
        case owl2_RawConcept_rc_qcard:
        {
            __auto_type k = _mv_127.data.rc_qcard.f0;
            __auto_type r = _mv_127.data.rc_qcard.f1;
            __auto_type n = _mv_127.data.rc_qcard.f2;
            __auto_type f = _mv_127.data.rc_qcard.f3;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_qcard, .data.rc_qcard = { .f0 = k, .f1 = types_copy_role(arena, r), .f2 = n, .f3 = owl2_copy_boxed(arena, f) } });
        }
        case owl2_RawConcept_rc_data:
        {
            __auto_type ref = _mv_127.data.rc_data;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_data, .data.rc_data = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawConcept_rc_anon:
        {
            __auto_type ref = _mv_127.data.rc_anon;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_anon, .data.rc_anon = types_copy_input_ref(arena, ref) });
        }
    }
    SLOP_UNREACHABLE();
}

owl2_RawConcept* owl2_copy_boxed(slop_arena* arena, owl2_RawConcept* p) {
    {
        __auto_type q = ((owl2_RawConcept*)(({ __auto_type _alloc = (owl2_RawConcept*)slop_arena_alloc(arena, sizeof(owl2_RawConcept)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*q) = owl2_copy_concept(arena, (*p));
        return q;
    }
}

slop_list_owl2_RawConcept owl2_copy_concepts(slop_arena* arena, slop_list_owl2_RawConcept cs) {
    {
        __auto_type out = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (owl2_copy_concept(arena, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_Node owl2_copy_nodes(slop_arena* arena, slop_list_types_Node ns) {
    {
        __auto_type out = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (types_copy_node(arena, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_RoleId owl2_copy_roles(slop_arena* arena, slop_list_types_RoleId rs) {
    {
        __auto_type out = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (types_copy_role(arena, r)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

owl2_RawAxiom owl2_copy_raw_axiom(slop_arena* arena, owl2_RawAxiom ax) {
    __auto_type _mv_128 = ax;
    switch (_mv_128.tag) {
        case owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_128.data.ra_sub_class_of.f0;
            __auto_type r = _mv_128.data.ra_sub_class_of.f1;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_sub_class_of, .data.ra_sub_class_of = { .f0 = owl2_copy_boxed(arena, l), .f1 = owl2_copy_boxed(arena, r) } });
        }
        case owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type cs = _mv_128.data.ra_equivalent_classes;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_equivalent_classes, .data.ra_equivalent_classes = owl2_copy_concepts(arena, cs) });
        }
        case owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_128.data.ra_disjoint_classes;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_classes, .data.ra_disjoint_classes = owl2_copy_concepts(arena, cs) });
        }
        case owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type a = _mv_128.data.ra_sub_object_property.f0;
            __auto_type b = _mv_128.data.ra_sub_object_property.f1;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_sub_object_property, .data.ra_sub_object_property = { .f0 = types_copy_role(arena, a), .f1 = types_copy_role(arena, b) } });
        }
        case owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_128.data.ra_property_chain;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_property_chain, .data.ra_property_chain = ((owl2_RawChain){.steps = owl2_copy_roles(arena, ch.steps), .super = types_copy_role(arena, ch.super)}) });
        }
        case owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type rs = _mv_128.data.ra_equivalent_properties;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_equivalent_properties, .data.ra_equivalent_properties = owl2_copy_roles(arena, rs) });
        }
        case owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type r = _mv_128.data.ra_transitive_property;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_transitive_property, .data.ra_transitive_property = types_copy_role(arena, r) });
        }
        case owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_128.data.ra_object_property_domain.f0;
            __auto_type c = _mv_128.data.ra_object_property_domain.f1;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_object_property_domain, .data.ra_object_property_domain = { .f0 = types_copy_role(arena, r), .f1 = owl2_copy_boxed(arena, c) } });
        }
        case owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type r = _mv_128.data.ra_object_property_range.f0;
            __auto_type c = _mv_128.data.ra_object_property_range.f1;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_object_property_range, .data.ra_object_property_range = { .f0 = types_copy_role(arena, r), .f1 = owl2_copy_boxed(arena, c) } });
        }
        case owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_128.data.ra_class_assertion;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_class_assertion, .data.ra_class_assertion = ((owl2_RawClassAssertion){.concept = owl2_copy_boxed(arena, ca.concept), .subject = types_copy_node(arena, ca.subject)}) });
        }
        case owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type e = _mv_128.data.ra_object_property_assertion;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_object_property_assertion, .data.ra_object_property_assertion = ((owl2_RawEdge){.role = types_copy_role(arena, e.role), .from = types_copy_node(arena, e.from), .to = types_copy_node(arena, e.to)}) });
        }
        case owl2_RawAxiom_ra_declaration:
        {
            __auto_type d = _mv_128.data.ra_declaration;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_declaration, .data.ra_declaration = ((owl2_RawDeclaration){.kind = d.kind, .entity = types_copy_iri(arena, d.entity)}) });
        }
        case owl2_RawAxiom_ra_annotation:
        {
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_annotation });
        }
        case owl2_RawAxiom_ra_inverse_properties:
        {
            __auto_type a = _mv_128.data.ra_inverse_properties.f0;
            __auto_type b = _mv_128.data.ra_inverse_properties.f1;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inverse_properties, .data.ra_inverse_properties = { .f0 = types_copy_role(arena, a), .f1 = types_copy_role(arena, b) } });
        }
        case owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type c = _mv_128.data.ra_property_characteristic.f0;
            __auto_type r = _mv_128.data.ra_property_characteristic.f1;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_property_characteristic, .data.ra_property_characteristic = { .f0 = c, .f1 = types_copy_role(arena, r) } });
        }
        case owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type rs = _mv_128.data.ra_disjoint_properties;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_properties, .data.ra_disjoint_properties = owl2_copy_roles(arena, rs) });
        }
        case owl2_RawAxiom_ra_same_individual:
        {
            __auto_type ns = _mv_128.data.ra_same_individual;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_same_individual, .data.ra_same_individual = owl2_copy_nodes(arena, ns) });
        }
        case owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type ns = _mv_128.data.ra_different_individuals;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_different_individuals, .data.ra_different_individuals = owl2_copy_nodes(arena, ns) });
        }
        case owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type e = _mv_128.data.ra_negative_assertion;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_negative_assertion, .data.ra_negative_assertion = ((owl2_RawEdge){.role = types_copy_role(arena, e.role), .from = types_copy_node(arena, e.from), .to = types_copy_node(arena, e.to)}) });
        }
        case owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type ref = _mv_128.data.ra_disjoint_union;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_union, .data.ra_disjoint_union = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_has_key:
        {
            __auto_type ref = _mv_128.data.ra_has_key;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_has_key, .data.ra_has_key = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_inverse_expression:
        {
            __auto_type ref = _mv_128.data.ra_inverse_expression;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inverse_expression, .data.ra_inverse_expression = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_data_axiom:
        {
            __auto_type ref = _mv_128.data.ra_data_axiom;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_builtin_role:
        {
            __auto_type ref = _mv_128.data.ra_builtin_role;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_builtin_role, .data.ra_builtin_role = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_anonymous_individual:
        {
            __auto_type ref = _mv_128.data.ra_anonymous_individual;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_reserved_vocabulary:
        {
            __auto_type ref = _mv_128.data.ra_reserved_vocabulary;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_swrl_rule:
        {
            __auto_type ref = _mv_128.data.ra_swrl_rule;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_swrl_rule, .data.ra_swrl_rule = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_unrecognized:
        {
            __auto_type ref = _mv_128.data.ra_unrecognized;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = types_copy_input_ref(arena, ref) });
        }
    }
    SLOP_UNREACHABLE();
}

owl2_RawAxiom owl2_raw_axiom_at(slop_list_owl2_RawAxiom xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_129 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_owl2_RawAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_129.has_value) {
        __auto_type v = _mv_129.value;
        return v;
    } else if (!_mv_129.has_value) {
        return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_annotation });
    }
    SLOP_UNREACHABLE();
}

slop_list_owl2_RawAxiom owl2_copy_axioms(slop_arena* arena, slop_list_owl2_RawAxiom xs) {
    slop_list_owl2_RawAxiom _retval = {0};
    {
        __auto_type n = ((int64_t)(((int64_t)((xs).len))));
        __auto_type out = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < n) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (owl2_copy_raw_axiom(arena, owl2_raw_axiom_at(xs, i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        _retval = out;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) == ((int64_t)((xs).len)))), "(== (list-len $result) (list-len xs))");
    return _retval;
}

owl2_Signature owl2_copy_signature(slop_arena* arena, owl2_Signature sig) {
    {
        __auto_type out = owl2_make_signature(arena);
        {
            slop_map* _coll = (slop_map*)sig.classes;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    rdf_IRI i = *(rdf_IRI*)slop_map_key_at(_coll, _i);
                    ({ rdf_IRI _key_130 = (types_copy_iri(arena, i)); slop_map_put(NULL, out.classes, &_key_130, NULL, 0); });
                }
            }
        }
        {
            slop_map* _coll = (slop_map*)sig.obj_props;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    rdf_IRI i = *(rdf_IRI*)slop_map_key_at(_coll, _i);
                    ({ rdf_IRI _key_131 = (types_copy_iri(arena, i)); slop_map_put(NULL, out.obj_props, &_key_131, NULL, 0); });
                }
            }
        }
        {
            slop_map* _coll = (slop_map*)sig.data_props;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    rdf_IRI i = *(rdf_IRI*)slop_map_key_at(_coll, _i);
                    ({ rdf_IRI _key_132 = (types_copy_iri(arena, i)); slop_map_put(NULL, out.data_props, &_key_132, NULL, 0); });
                }
            }
        }
        {
            slop_map* _coll = (slop_map*)sig.annot_props;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    rdf_IRI i = *(rdf_IRI*)slop_map_key_at(_coll, _i);
                    ({ rdf_IRI _key_133 = (types_copy_iri(arena, i)); slop_map_put(NULL, out.annot_props, &_key_133, NULL, 0); });
                }
            }
        }
        {
            slop_map* _coll = (slop_map*)sig.individuals;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    rdf_IRI i = *(rdf_IRI*)slop_map_key_at(_coll, _i);
                    ({ rdf_IRI _key_134 = (types_copy_iri(arena, i)); slop_map_put(NULL, out.individuals, &_key_134, NULL, 0); });
                }
            }
        }
        {
            slop_map* _coll = (slop_map*)sig.datatypes;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    rdf_IRI i = *(rdf_IRI*)slop_map_key_at(_coll, _i);
                    ({ rdf_IRI _key_135 = (types_copy_iri(arena, i)); slop_map_put(NULL, out.datatypes, &_key_135, NULL, 0); });
                }
            }
        }
        return out;
    }
}

slop_list_owl2_RawConcept owl2_sort_concepts(slop_arena* arena, slop_list_owl2_RawConcept xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ owl2__lambda_136_env_t* owl2__lambda_136_env = (owl2__lambda_136_env_t*)slop_arena_alloc(arena, sizeof(owl2__lambda_136_env_t)); *owl2__lambda_136_env = (owl2__lambda_136_env_t){ .xs = xs }; (slop_closure_t){ (void*)owl2__lambda_136, (void*)owl2__lambda_136_env }; }));
        __auto_type out = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (owl2_concept_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

