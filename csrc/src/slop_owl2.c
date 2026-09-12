#include "../runtime/slop_runtime.h"
#include "slop_owl2.h"

const slop_string owl2_OWL_AXIOM = SLOP_STR("http://www.w3.org/2002/07/owl#Axiom");
const slop_string owl2_OWL_ANNOTATED_SOURCE = SLOP_STR("http://www.w3.org/2002/07/owl#annotatedSource");
const slop_string owl2_OWL_ANNOTATED_PROPERTY = SLOP_STR("http://www.w3.org/2002/07/owl#annotatedProperty");
const slop_string owl2_OWL_ANNOTATED_TARGET = SLOP_STR("http://www.w3.org/2002/07/owl#annotatedTarget");
const slop_string owl2_OWL_ANNOTATION = SLOP_STR("http://www.w3.org/2002/07/owl#Annotation");
const slop_string owl2_OWL_DISJOINT_UNION_OF = SLOP_STR("http://www.w3.org/2002/07/owl#disjointUnionOf");
const slop_string owl2_OWL_TOP_OBJECT_PROPERTY = SLOP_STR("http://www.w3.org/2002/07/owl#topObjectProperty");
const slop_string owl2_OWL_BOTTOM_OBJECT_PROPERTY = SLOP_STR("http://www.w3.org/2002/07/owl#bottomObjectProperty");
const slop_string owl2_OWL_TOP_DATA_PROPERTY = SLOP_STR("http://www.w3.org/2002/07/owl#topDataProperty");
const slop_string owl2_OWL_BOTTOM_DATA_PROPERTY = SLOP_STR("http://www.w3.org/2002/07/owl#bottomDataProperty");
const slop_string owl2_SWRL_NS = SLOP_STR("http://www.w3.org/2003/11/swrl#");
const slop_string owl2_SWRL_IMP = SLOP_STR("http://www.w3.org/2003/11/swrl#Imp");
const slop_string owl2_SWRL_BODY = SLOP_STR("http://www.w3.org/2003/11/swrl#body");
const slop_string owl2_SWRL_HEAD = SLOP_STR("http://www.w3.org/2003/11/swrl#head");

owl2_Disposition owl2_disposition(owl2_RawAxiom ax);
owl2_Signature owl2_make_signature(slop_arena* arena);
uint8_t owl2_signature_has_class(owl2_Signature sig, rdf_IRI i);
uint8_t owl2_signature_has_object_property(owl2_Signature sig, rdf_IRI i);
uint8_t owl2_signature_has_annotation_property(owl2_Signature sig, rdf_IRI i);
int64_t owl2_signature_size(slop_arena* arena, owl2_Signature sig);
uint8_t owl2_role_in_profile(types_RoleId r);
uint8_t owl2_roles_in_profile(slop_list_types_RoleId rs);
uint8_t owl2_concepts_in_profile(slop_list_owl2_RawConcept cs);
uint8_t owl2_concept_in_profile(owl2_RawConcept c);
uint8_t owl2_axiom_in_profile(owl2_RawAxiom ax);

owl2_Disposition owl2_disposition(owl2_RawAxiom ax) {
    __auto_type _mv_143 = ax;
    switch (_mv_143.tag) {
        case owl2_RawAxiom_ra_sub_class_of:
        {
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type _ = _mv_143.data.ra_equivalent_classes;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type _ = _mv_143.data.ra_disjoint_classes;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_sub_object_property:
        {
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_property_chain:
        {
            __auto_type _ = _mv_143.data.ra_property_chain;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type _ = _mv_143.data.ra_equivalent_properties;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type _ = _mv_143.data.ra_transitive_property;
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
            __auto_type _ = _mv_143.data.ra_class_assertion;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type _ = _mv_143.data.ra_object_property_assertion;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_declaration:
        {
            __auto_type _ = _mv_143.data.ra_declaration;
            return owl2_Disposition_d_consumed;
        }
        case owl2_RawAxiom_ra_annotation_assertion:
        {
            __auto_type _ = _mv_143.data.ra_annotation_assertion;
            return owl2_Disposition_d_inert;
        }
        case owl2_RawAxiom_ra_annotation_axiom:
        {
            __auto_type _ = _mv_143.data.ra_annotation_axiom;
            return owl2_Disposition_d_inert;
        }
        case owl2_RawAxiom_ra_inverse_properties:
        {
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_property_characteristic:
        {
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type _ = _mv_143.data.ra_disjoint_properties;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_same_individual:
        {
            __auto_type _ = _mv_143.data.ra_same_individual;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type _ = _mv_143.data.ra_different_individuals;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type _ = _mv_143.data.ra_negative_assertion;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type _ = _mv_143.data.ra_disjoint_union;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_has_key:
        {
            __auto_type _ = _mv_143.data.ra_has_key;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_data_axiom:
        {
            __auto_type _ = _mv_143.data.ra_data_axiom;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_builtin_role:
        {
            __auto_type _ = _mv_143.data.ra_builtin_role;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_anonymous_individual:
        {
            __auto_type _ = _mv_143.data.ra_anonymous_individual;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_reserved_vocabulary:
        {
            __auto_type _ = _mv_143.data.ra_reserved_vocabulary;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_swrl_rule:
        {
            __auto_type _ = _mv_143.data.ra_swrl_rule;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_unrecognized:
        {
            __auto_type _ = _mv_143.data.ra_unrecognized;
            return owl2_Disposition_d_out_of_profile;
        }
    }
    SLOP_UNREACHABLE();
}

owl2_Signature owl2_make_signature(slop_arena* arena) {
    return ((owl2_Signature){.classes = slop_map_new_ptr(arena, 16, sizeof(rdf_IRI), slop_hash_rdf_IRI, slop_eq_rdf_IRI), .obj_props = slop_map_new_ptr(arena, 16, sizeof(rdf_IRI), slop_hash_rdf_IRI, slop_eq_rdf_IRI), .data_props = slop_map_new_ptr(arena, 16, sizeof(rdf_IRI), slop_hash_rdf_IRI, slop_eq_rdf_IRI), .annot_props = slop_map_new_ptr(arena, 16, sizeof(rdf_IRI), slop_hash_rdf_IRI, slop_eq_rdf_IRI), .individuals = slop_map_new_ptr(arena, 16, sizeof(rdf_IRI), slop_hash_rdf_IRI, slop_eq_rdf_IRI), .datatypes = slop_map_new_ptr(arena, 16, sizeof(rdf_IRI), slop_hash_rdf_IRI, slop_eq_rdf_IRI)});
}

uint8_t owl2_signature_has_class(owl2_Signature sig, rdf_IRI i) {
    return (slop_map_get(sig.classes, &(i)) != NULL);
}

uint8_t owl2_signature_has_object_property(owl2_Signature sig, rdf_IRI i) {
    return (slop_map_get(sig.obj_props, &(i)) != NULL);
}

uint8_t owl2_signature_has_annotation_property(owl2_Signature sig, rdf_IRI i) {
    return (slop_map_get(sig.annot_props, &(i)) != NULL);
}

int64_t owl2_signature_size(slop_arena* arena, owl2_Signature sig) {
    return (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.classes); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap}; })).len)))) + (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.obj_props); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap}; })).len)))) + (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.data_props); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap}; })).len)))) + (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.annot_props); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap}; })).len)))) + (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.individuals); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap}; })).len)))) + ((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.datatypes); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap}; })).len)))))))));
}

uint8_t owl2_role_in_profile(types_RoleId r) {
    __auto_type _mv_147 = r;
    switch (_mv_147.tag) {
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_147.data.fresh_role;
            return 1;
        }
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_147.data.named_role;
            return ((canon_string_cmp(i.value, owl2_OWL_TOP_OBJECT_PROPERTY) != 0) && ((canon_string_cmp(i.value, owl2_OWL_BOTTOM_OBJECT_PROPERTY) != 0) && ((canon_string_cmp(i.value, owl2_OWL_TOP_DATA_PROPERTY) != 0) && (canon_string_cmp(i.value, owl2_OWL_BOTTOM_DATA_PROPERTY) != 0))));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t owl2_roles_in_profile(slop_list_types_RoleId rs) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                if (!(owl2_role_in_profile(r))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t owl2_concepts_in_profile(slop_list_owl2_RawConcept cs) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(owl2_concept_in_profile(c))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t owl2_concept_in_profile(owl2_RawConcept c) {
    __auto_type _mv_148 = c;
    switch (_mv_148.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type _ = _mv_148.data.rc_name;
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
            __auto_type cs = _mv_148.data.rc_and;
            return owl2_concepts_in_profile(cs);
        }
        case owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_148.data.rc_some.f0;
            __auto_type f = _mv_148.data.rc_some.f1;
            return (owl2_role_in_profile(r) && owl2_concept_in_profile((*f)));
        }
        case owl2_RawConcept_rc_or:
        {
            __auto_type _ = _mv_148.data.rc_or;
            return 0;
        }
        case owl2_RawConcept_rc_not:
        {
            __auto_type _ = _mv_148.data.rc_not;
            return 0;
        }
        case owl2_RawConcept_rc_all:
        {
            return 0;
        }
        case owl2_RawConcept_rc_oneof:
        {
            __auto_type _ = _mv_148.data.rc_oneof;
            return 0;
        }
        case owl2_RawConcept_rc_has_value:
        {
            return 0;
        }
        case owl2_RawConcept_rc_has_self:
        {
            __auto_type _ = _mv_148.data.rc_has_self;
            return 0;
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
            __auto_type _ = _mv_148.data.rc_data;
            return 0;
        }
        case owl2_RawConcept_rc_anon:
        {
            __auto_type _ = _mv_148.data.rc_anon;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t owl2_axiom_in_profile(owl2_RawAxiom ax) {
    if (owl2_disposition(ax) != owl2_Disposition_d_in_profile) {
        return 0;
    } else {
        __auto_type _mv_149 = ax;
        switch (_mv_149.tag) {
            case owl2_RawAxiom_ra_sub_class_of:
            {
                __auto_type l = _mv_149.data.ra_sub_class_of.f0;
                __auto_type r = _mv_149.data.ra_sub_class_of.f1;
                return (owl2_concept_in_profile((*l)) && owl2_concept_in_profile((*r)));
            }
            case owl2_RawAxiom_ra_equivalent_classes:
            {
                __auto_type cs = _mv_149.data.ra_equivalent_classes;
                return owl2_concepts_in_profile(cs);
            }
            case owl2_RawAxiom_ra_disjoint_classes:
            {
                __auto_type cs = _mv_149.data.ra_disjoint_classes;
                return owl2_concepts_in_profile(cs);
            }
            case owl2_RawAxiom_ra_object_property_domain:
            {
                __auto_type r = _mv_149.data.ra_object_property_domain.f0;
                __auto_type c = _mv_149.data.ra_object_property_domain.f1;
                return (owl2_role_in_profile(r) && owl2_concept_in_profile((*c)));
            }
            case owl2_RawAxiom_ra_object_property_range:
            {
                __auto_type r = _mv_149.data.ra_object_property_range.f0;
                __auto_type c = _mv_149.data.ra_object_property_range.f1;
                return (owl2_role_in_profile(r) && owl2_concept_in_profile((*c)));
            }
            case owl2_RawAxiom_ra_class_assertion:
            {
                __auto_type ca = _mv_149.data.ra_class_assertion;
                return owl2_concept_in_profile((*ca.concept));
            }
            case owl2_RawAxiom_ra_sub_object_property:
            {
                __auto_type a = _mv_149.data.ra_sub_object_property.f0;
                __auto_type b = _mv_149.data.ra_sub_object_property.f1;
                return (owl2_role_in_profile(a) && owl2_role_in_profile(b));
            }
            case owl2_RawAxiom_ra_property_chain:
            {
                __auto_type ch = _mv_149.data.ra_property_chain;
                return (owl2_roles_in_profile(ch.steps) && owl2_role_in_profile(ch.super));
            }
            case owl2_RawAxiom_ra_equivalent_properties:
            {
                __auto_type rs = _mv_149.data.ra_equivalent_properties;
                return owl2_roles_in_profile(rs);
            }
            case owl2_RawAxiom_ra_transitive_property:
            {
                __auto_type r = _mv_149.data.ra_transitive_property;
                return owl2_role_in_profile(r);
            }
            case owl2_RawAxiom_ra_object_property_assertion:
            {
                __auto_type e = _mv_149.data.ra_object_property_assertion;
                return owl2_role_in_profile(e.role);
            }
            case owl2_RawAxiom_ra_declaration:
            {
                __auto_type _ = _mv_149.data.ra_declaration;
                return 0;
            }
            case owl2_RawAxiom_ra_annotation_assertion:
            {
                __auto_type _ = _mv_149.data.ra_annotation_assertion;
                return 0;
            }
            case owl2_RawAxiom_ra_annotation_axiom:
            {
                __auto_type _ = _mv_149.data.ra_annotation_axiom;
                return 0;
            }
            case owl2_RawAxiom_ra_inverse_properties:
            {
                return 0;
            }
            case owl2_RawAxiom_ra_property_characteristic:
            {
                return 0;
            }
            case owl2_RawAxiom_ra_disjoint_properties:
            {
                __auto_type _ = _mv_149.data.ra_disjoint_properties;
                return 0;
            }
            case owl2_RawAxiom_ra_same_individual:
            {
                __auto_type _ = _mv_149.data.ra_same_individual;
                return 0;
            }
            case owl2_RawAxiom_ra_different_individuals:
            {
                __auto_type _ = _mv_149.data.ra_different_individuals;
                return 0;
            }
            case owl2_RawAxiom_ra_negative_assertion:
            {
                __auto_type _ = _mv_149.data.ra_negative_assertion;
                return 0;
            }
            case owl2_RawAxiom_ra_disjoint_union:
            {
                __auto_type _ = _mv_149.data.ra_disjoint_union;
                return 0;
            }
            case owl2_RawAxiom_ra_has_key:
            {
                __auto_type _ = _mv_149.data.ra_has_key;
                return 0;
            }
            case owl2_RawAxiom_ra_data_axiom:
            {
                __auto_type _ = _mv_149.data.ra_data_axiom;
                return 0;
            }
            case owl2_RawAxiom_ra_builtin_role:
            {
                __auto_type _ = _mv_149.data.ra_builtin_role;
                return 0;
            }
            case owl2_RawAxiom_ra_anonymous_individual:
            {
                __auto_type _ = _mv_149.data.ra_anonymous_individual;
                return 0;
            }
            case owl2_RawAxiom_ra_reserved_vocabulary:
            {
                __auto_type _ = _mv_149.data.ra_reserved_vocabulary;
                return 0;
            }
            case owl2_RawAxiom_ra_swrl_rule:
            {
                __auto_type _ = _mv_149.data.ra_swrl_rule;
                return 0;
            }
            case owl2_RawAxiom_ra_unrecognized:
            {
                __auto_type _ = _mv_149.data.ra_unrecognized;
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    }
}

