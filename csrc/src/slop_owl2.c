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
uint8_t owl2_signature_has_data_property(owl2_Signature sig, rdf_IRI i);
int64_t owl2_signature_size(slop_arena* arena, owl2_Signature sig);
uint8_t owl2_role_in_profile(types_RoleId r);
uint8_t owl2_roles_in_profile(slop_list_types_RoleId rs);
uint8_t owl2_concepts_in_profile(slop_list_owl2_RawConcept cs);
uint8_t owl2_concept_in_profile(owl2_RawConcept c);
uint8_t owl2_axiom_in_profile(owl2_RawAxiom ax);
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

typedef struct { slop_list_owl2_RawConcept xs; } owl2__lambda_227_env_t;

static int64_t owl2__lambda_227(owl2__lambda_227_env_t* _env, int64_t i, int64_t j) { return owl2_concept_cmp(owl2_concept_at(_env->xs, i), owl2_concept_at(_env->xs, j)); }

owl2_Disposition owl2_disposition(owl2_RawAxiom ax) {
    __auto_type _mv_190 = ax;
    switch (_mv_190.tag) {
        case owl2_RawAxiom_ra_sub_class_of:
        {
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type _ = _mv_190.data.ra_equivalent_classes;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type _ = _mv_190.data.ra_disjoint_classes;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_sub_object_property:
        {
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_property_chain:
        {
            __auto_type _ = _mv_190.data.ra_property_chain;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type _ = _mv_190.data.ra_equivalent_properties;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type _ = _mv_190.data.ra_transitive_property;
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
            __auto_type _ = _mv_190.data.ra_class_assertion;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type _ = _mv_190.data.ra_object_property_assertion;
            return owl2_Disposition_d_in_profile;
        }
        case owl2_RawAxiom_ra_declaration:
        {
            __auto_type _ = _mv_190.data.ra_declaration;
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
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type _ = _mv_190.data.ra_disjoint_properties;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_same_individual:
        {
            __auto_type _ = _mv_190.data.ra_same_individual;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type _ = _mv_190.data.ra_different_individuals;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type _ = _mv_190.data.ra_negative_assertion;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type _ = _mv_190.data.ra_disjoint_union;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_has_key:
        {
            __auto_type _ = _mv_190.data.ra_has_key;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_inverse_expression:
        {
            __auto_type _ = _mv_190.data.ra_inverse_expression;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_data_axiom:
        {
            __auto_type _ = _mv_190.data.ra_data_axiom;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_builtin_role:
        {
            __auto_type _ = _mv_190.data.ra_builtin_role;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_anonymous_individual:
        {
            __auto_type _ = _mv_190.data.ra_anonymous_individual;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_reserved_vocabulary:
        {
            __auto_type _ = _mv_190.data.ra_reserved_vocabulary;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_swrl_rule:
        {
            __auto_type _ = _mv_190.data.ra_swrl_rule;
            return owl2_Disposition_d_out_of_profile;
        }
        case owl2_RawAxiom_ra_unrecognized:
        {
            __auto_type _ = _mv_190.data.ra_unrecognized;
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
    return (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.classes); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap}; })).len)))) + (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.obj_props); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap}; })).len)))) + (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.data_props); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap}; })).len)))) + (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.annot_props); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap}; })).len)))) + (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.individuals); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap}; })).len)))) + ((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.datatypes); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap}; })).len)))))))));
}

uint8_t owl2_role_in_profile(types_RoleId r) {
    __auto_type _mv_195 = r;
    switch (_mv_195.tag) {
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_195.data.fresh_role;
            return 1;
        }
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_195.data.named_role;
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
    __auto_type _mv_196 = c;
    switch (_mv_196.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type _ = _mv_196.data.rc_name;
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
            __auto_type cs = _mv_196.data.rc_and;
            return owl2_concepts_in_profile(cs);
        }
        case owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_196.data.rc_some.f0;
            __auto_type f = _mv_196.data.rc_some.f1;
            return (owl2_role_in_profile(r) && owl2_concept_in_profile((*f)));
        }
        case owl2_RawConcept_rc_or:
        {
            __auto_type _ = _mv_196.data.rc_or;
            return 0;
        }
        case owl2_RawConcept_rc_not:
        {
            __auto_type _ = _mv_196.data.rc_not;
            return 0;
        }
        case owl2_RawConcept_rc_all:
        {
            return 0;
        }
        case owl2_RawConcept_rc_oneof:
        {
            __auto_type _ = _mv_196.data.rc_oneof;
            return 0;
        }
        case owl2_RawConcept_rc_has_value:
        {
            return 0;
        }
        case owl2_RawConcept_rc_has_self:
        {
            __auto_type _ = _mv_196.data.rc_has_self;
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
            __auto_type _ = _mv_196.data.rc_data;
            return 0;
        }
        case owl2_RawConcept_rc_anon:
        {
            __auto_type _ = _mv_196.data.rc_anon;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t owl2_axiom_in_profile(owl2_RawAxiom ax) {
    if (owl2_disposition(ax) != owl2_Disposition_d_in_profile) {
        return 0;
    } else {
        __auto_type _mv_197 = ax;
        switch (_mv_197.tag) {
            case owl2_RawAxiom_ra_sub_class_of:
            {
                __auto_type l = _mv_197.data.ra_sub_class_of.f0;
                __auto_type r = _mv_197.data.ra_sub_class_of.f1;
                return (owl2_concept_in_profile((*l)) && owl2_concept_in_profile((*r)));
            }
            case owl2_RawAxiom_ra_equivalent_classes:
            {
                __auto_type cs = _mv_197.data.ra_equivalent_classes;
                return owl2_concepts_in_profile(cs);
            }
            case owl2_RawAxiom_ra_disjoint_classes:
            {
                __auto_type cs = _mv_197.data.ra_disjoint_classes;
                return owl2_concepts_in_profile(cs);
            }
            case owl2_RawAxiom_ra_object_property_domain:
            {
                __auto_type r = _mv_197.data.ra_object_property_domain.f0;
                __auto_type c = _mv_197.data.ra_object_property_domain.f1;
                return (owl2_role_in_profile(r) && owl2_concept_in_profile((*c)));
            }
            case owl2_RawAxiom_ra_object_property_range:
            {
                __auto_type r = _mv_197.data.ra_object_property_range.f0;
                __auto_type c = _mv_197.data.ra_object_property_range.f1;
                return (owl2_role_in_profile(r) && owl2_concept_in_profile((*c)));
            }
            case owl2_RawAxiom_ra_class_assertion:
            {
                __auto_type ca = _mv_197.data.ra_class_assertion;
                return owl2_concept_in_profile((*ca.concept));
            }
            case owl2_RawAxiom_ra_sub_object_property:
            {
                __auto_type a = _mv_197.data.ra_sub_object_property.f0;
                __auto_type b = _mv_197.data.ra_sub_object_property.f1;
                return (owl2_role_in_profile(a) && owl2_role_in_profile(b));
            }
            case owl2_RawAxiom_ra_property_chain:
            {
                __auto_type ch = _mv_197.data.ra_property_chain;
                return (owl2_roles_in_profile(ch.steps) && owl2_role_in_profile(ch.super));
            }
            case owl2_RawAxiom_ra_equivalent_properties:
            {
                __auto_type rs = _mv_197.data.ra_equivalent_properties;
                return owl2_roles_in_profile(rs);
            }
            case owl2_RawAxiom_ra_transitive_property:
            {
                __auto_type r = _mv_197.data.ra_transitive_property;
                return owl2_role_in_profile(r);
            }
            case owl2_RawAxiom_ra_object_property_assertion:
            {
                __auto_type e = _mv_197.data.ra_object_property_assertion;
                return owl2_role_in_profile(e.role);
            }
            case owl2_RawAxiom_ra_declaration:
            {
                __auto_type _ = _mv_197.data.ra_declaration;
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
            case owl2_RawAxiom_ra_property_characteristic:
            {
                return 0;
            }
            case owl2_RawAxiom_ra_disjoint_properties:
            {
                __auto_type _ = _mv_197.data.ra_disjoint_properties;
                return 0;
            }
            case owl2_RawAxiom_ra_same_individual:
            {
                __auto_type _ = _mv_197.data.ra_same_individual;
                return 0;
            }
            case owl2_RawAxiom_ra_different_individuals:
            {
                __auto_type _ = _mv_197.data.ra_different_individuals;
                return 0;
            }
            case owl2_RawAxiom_ra_negative_assertion:
            {
                __auto_type _ = _mv_197.data.ra_negative_assertion;
                return 0;
            }
            case owl2_RawAxiom_ra_disjoint_union:
            {
                __auto_type _ = _mv_197.data.ra_disjoint_union;
                return 0;
            }
            case owl2_RawAxiom_ra_has_key:
            {
                __auto_type _ = _mv_197.data.ra_has_key;
                return 0;
            }
            case owl2_RawAxiom_ra_inverse_expression:
            {
                __auto_type _ = _mv_197.data.ra_inverse_expression;
                return 0;
            }
            case owl2_RawAxiom_ra_data_axiom:
            {
                __auto_type _ = _mv_197.data.ra_data_axiom;
                return 0;
            }
            case owl2_RawAxiom_ra_builtin_role:
            {
                __auto_type _ = _mv_197.data.ra_builtin_role;
                return 0;
            }
            case owl2_RawAxiom_ra_anonymous_individual:
            {
                __auto_type _ = _mv_197.data.ra_anonymous_individual;
                return 0;
            }
            case owl2_RawAxiom_ra_reserved_vocabulary:
            {
                __auto_type _ = _mv_197.data.ra_reserved_vocabulary;
                return 0;
            }
            case owl2_RawAxiom_ra_swrl_rule:
            {
                __auto_type _ = _mv_197.data.ra_swrl_rule;
                return 0;
            }
            case owl2_RawAxiom_ra_unrecognized:
            {
                __auto_type _ = _mv_197.data.ra_unrecognized;
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    }
}

int64_t owl2_concept_tag_rank(owl2_RawConcept c) {
    __auto_type _mv_198 = c;
    switch (_mv_198.tag) {
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
            __auto_type _ = _mv_198.data.rc_name;
            return 2;
        }
        case owl2_RawConcept_rc_and:
        {
            __auto_type _ = _mv_198.data.rc_and;
            return 3;
        }
        case owl2_RawConcept_rc_some:
        {
            return 4;
        }
        case owl2_RawConcept_rc_or:
        {
            __auto_type _ = _mv_198.data.rc_or;
            return 5;
        }
        case owl2_RawConcept_rc_not:
        {
            __auto_type _ = _mv_198.data.rc_not;
            return 6;
        }
        case owl2_RawConcept_rc_all:
        {
            return 7;
        }
        case owl2_RawConcept_rc_oneof:
        {
            __auto_type _ = _mv_198.data.rc_oneof;
            return 8;
        }
        case owl2_RawConcept_rc_has_value:
        {
            return 9;
        }
        case owl2_RawConcept_rc_has_self:
        {
            __auto_type _ = _mv_198.data.rc_has_self;
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
            __auto_type _ = _mv_198.data.rc_data;
            return 13;
        }
        case owl2_RawConcept_rc_anon:
        {
            __auto_type _ = _mv_198.data.rc_anon;
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
    __auto_type _mv_199 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_owl2_RawConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_199.has_value) {
        __auto_type v = _mv_199.value;
        return v;
    } else if (!_mv_199.has_value) {
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
            __auto_type _mv_200 = a;
            switch (_mv_200.tag) {
                case owl2_RawConcept_rc_name:
                {
                    __auto_type na = _mv_200.data.rc_name;
                    __auto_type _mv_201 = b;
                    switch (_mv_201.tag) {
                        case owl2_RawConcept_rc_name:
                        {
                            __auto_type nb = _mv_201.data.rc_name;
                            return canon_node_cmp(na, nb);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case owl2_RawConcept_rc_and:
                {
                    __auto_type as = _mv_200.data.rc_and;
                    __auto_type _mv_202 = b;
                    switch (_mv_202.tag) {
                        case owl2_RawConcept_rc_and:
                        {
                            __auto_type bs = _mv_202.data.rc_and;
                            return owl2_concept_list_cmp(as, bs);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case owl2_RawConcept_rc_some:
                {
                    __auto_type ra2 = _mv_200.data.rc_some.f0;
                    __auto_type fa = _mv_200.data.rc_some.f1;
                    __auto_type _mv_203 = b;
                    switch (_mv_203.tag) {
                        case owl2_RawConcept_rc_some:
                        {
                            __auto_type rb2 = _mv_203.data.rc_some.f0;
                            __auto_type fb = _mv_203.data.rc_some.f1;
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
                    __auto_type as = _mv_200.data.rc_or;
                    __auto_type _mv_204 = b;
                    switch (_mv_204.tag) {
                        case owl2_RawConcept_rc_or:
                        {
                            __auto_type bs = _mv_204.data.rc_or;
                            return owl2_concept_list_cmp(as, bs);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case owl2_RawConcept_rc_not:
                {
                    __auto_type fa = _mv_200.data.rc_not;
                    __auto_type _mv_205 = b;
                    switch (_mv_205.tag) {
                        case owl2_RawConcept_rc_not:
                        {
                            __auto_type fb = _mv_205.data.rc_not;
                            return owl2_concept_cmp((*fa), (*fb));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case owl2_RawConcept_rc_all:
                {
                    __auto_type ra2 = _mv_200.data.rc_all.f0;
                    __auto_type fa = _mv_200.data.rc_all.f1;
                    __auto_type _mv_206 = b;
                    switch (_mv_206.tag) {
                        case owl2_RawConcept_rc_all:
                        {
                            __auto_type rb2 = _mv_206.data.rc_all.f0;
                            __auto_type fb = _mv_206.data.rc_all.f1;
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
                    __auto_type ra2 = _mv_200.data.rc_has_value.f0;
                    __auto_type na = _mv_200.data.rc_has_value.f1;
                    __auto_type _mv_207 = b;
                    switch (_mv_207.tag) {
                        case owl2_RawConcept_rc_has_value:
                        {
                            __auto_type rb2 = _mv_207.data.rc_has_value.f0;
                            __auto_type nb = _mv_207.data.rc_has_value.f1;
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
                    __auto_type ra2 = _mv_200.data.rc_has_self;
                    __auto_type _mv_208 = b;
                    switch (_mv_208.tag) {
                        case owl2_RawConcept_rc_has_self:
                        {
                            __auto_type rb2 = _mv_208.data.rc_has_self;
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
    __auto_type _mv_209 = r;
    switch (_mv_209.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_209.data.named_role;
            return i.value;
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_209.data.fresh_role;
            return SLOP_STR("_:fresh-role");
        }
    }
    SLOP_UNREACHABLE();
}

slop_string owl2_render_node(types_Node n) {
    __auto_type _mv_210 = n;
    switch (_mv_210.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_210.data.class_node;
            return i.value;
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_210.data.individual_node;
            return i.value;
        }
        case types_Node_fresh_node:
        {
            __auto_type _ = _mv_210.data.fresh_node;
            return SLOP_STR("_:fresh-node");
        }
    }
    SLOP_UNREACHABLE();
}

slop_string owl2_render_card_kind(owl2_CardKind k) {
    __auto_type _mv_211 = k;
    if (_mv_211 == owl2_CardKind_card_min) {
        return SLOP_STR("ObjectMinCardinality");
    } else if (_mv_211 == owl2_CardKind_card_max) {
        return SLOP_STR("ObjectMaxCardinality");
    } else if (_mv_211 == owl2_CardKind_card_exact) {
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
    __auto_type _mv_212 = c;
    switch (_mv_212.tag) {
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
            __auto_type n = _mv_212.data.rc_name;
            return owl2_render_node(n);
        }
        case owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_212.data.rc_and;
            return owl2_wrap(arena, SLOP_STR("ObjectIntersectionOf"), owl2_render_concept_list(arena, cs));
        }
        case owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_212.data.rc_or;
            return owl2_wrap(arena, SLOP_STR("ObjectUnionOf"), owl2_render_concept_list(arena, cs));
        }
        case owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_212.data.rc_not;
            return owl2_wrap(arena, SLOP_STR("ObjectComplementOf"), owl2_render_concept(arena, (*f)));
        }
        case owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_212.data.rc_some.f0;
            __auto_type f = _mv_212.data.rc_some.f1;
            return owl2_wrap(arena, SLOP_STR("ObjectSomeValuesFrom"), owl2_join2(arena, owl2_render_role(r), owl2_render_concept(arena, (*f))));
        }
        case owl2_RawConcept_rc_all:
        {
            __auto_type r = _mv_212.data.rc_all.f0;
            __auto_type f = _mv_212.data.rc_all.f1;
            return owl2_wrap(arena, SLOP_STR("ObjectAllValuesFrom"), owl2_join2(arena, owl2_render_role(r), owl2_render_concept(arena, (*f))));
        }
        case owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_212.data.rc_oneof;
            return owl2_wrap(arena, SLOP_STR("ObjectOneOf"), owl2_render_node_list(arena, ns));
        }
        case owl2_RawConcept_rc_has_value:
        {
            __auto_type r = _mv_212.data.rc_has_value.f0;
            __auto_type n = _mv_212.data.rc_has_value.f1;
            return owl2_wrap(arena, SLOP_STR("ObjectHasValue"), owl2_join2(arena, owl2_render_role(r), owl2_render_node(n)));
        }
        case owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_212.data.rc_has_self;
            return owl2_wrap(arena, SLOP_STR("ObjectHasSelf"), owl2_render_role(r));
        }
        case owl2_RawConcept_rc_card:
        {
            __auto_type k = _mv_212.data.rc_card.f0;
            __auto_type r = _mv_212.data.rc_card.f1;
            __auto_type n = _mv_212.data.rc_card.f2;
            return owl2_wrap(arena, owl2_render_card_kind(k), owl2_join2(arena, int_to_string(arena, n), owl2_render_role(r)));
        }
        case owl2_RawConcept_rc_qcard:
        {
            __auto_type k = _mv_212.data.rc_qcard.f0;
            __auto_type r = _mv_212.data.rc_qcard.f1;
            __auto_type n = _mv_212.data.rc_qcard.f2;
            __auto_type f = _mv_212.data.rc_qcard.f3;
            return owl2_wrap(arena, owl2_render_card_kind(k), owl2_join2(arena, int_to_string(arena, n), owl2_join2(arena, owl2_render_role(r), owl2_render_concept(arena, (*f)))));
        }
        case owl2_RawConcept_rc_data:
        {
            __auto_type ref = _mv_212.data.rc_data;
            return owl2_wrap(arena, SLOP_STR("DataRange"), owl2_render_input_ref(ref));
        }
        case owl2_RawConcept_rc_anon:
        {
            __auto_type ref = _mv_212.data.rc_anon;
            return owl2_wrap(arena, SLOP_STR("AnonymousClass"), owl2_render_input_ref(ref));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string owl2_render_input_ref(types_InputRef r) {
    __auto_type _mv_213 = r;
    switch (_mv_213.tag) {
        case types_InputRef_owl_axiom:
        {
            __auto_type a = _mv_213.data.owl_axiom;
            return a.text;
        }
        case types_InputRef_rdf_fragment:
        {
            __auto_type s = _mv_213.data.rdf_fragment;
            return s;
        }
        case types_InputRef_synthetic:
        {
            __auto_type s = _mv_213.data.synthetic;
            return s;
        }
    }
    SLOP_UNREACHABLE();
}

slop_string owl2_render_entity_kind(types_EntityKind k) {
    __auto_type _mv_214 = k;
    if (_mv_214 == types_EntityKind_entity_class) {
        return SLOP_STR("Class");
    } else if (_mv_214 == types_EntityKind_entity_object_property) {
        return SLOP_STR("ObjectProperty");
    } else if (_mv_214 == types_EntityKind_entity_data_property) {
        return SLOP_STR("DataProperty");
    } else if (_mv_214 == types_EntityKind_entity_annotation_property) {
        return SLOP_STR("AnnotationProperty");
    } else if (_mv_214 == types_EntityKind_entity_individual) {
        return SLOP_STR("NamedIndividual");
    } else if (_mv_214 == types_EntityKind_entity_datatype) {
        return SLOP_STR("Datatype");
    }
    SLOP_UNREACHABLE();
}

slop_string owl2_render_omission(slop_arena* arena, types_Omission o) {
    __auto_type _mv_215 = o;
    switch (_mv_215.tag) {
        case types_Omission_out_of_profile:
        {
            __auto_type ref = _mv_215.data.out_of_profile;
            return owl2_render_input_ref(ref);
        }
        case types_Omission_unresolved_import:
        {
            __auto_type i = _mv_215.data.unresolved_import;
            return owl2_wrap(arena, SLOP_STR("UnresolvedImport"), i.value);
        }
        case types_Omission_missing_declaration:
        {
            __auto_type md = _mv_215.data.missing_declaration;
            return owl2_wrap(arena, SLOP_STR("MissingDeclaration"), owl2_wrap(arena, owl2_render_entity_kind(md.kind), md.entity.value));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string owl2_render_axiom(slop_arena* arena, owl2_RawAxiom ax) {
    __auto_type _mv_216 = ax;
    switch (_mv_216.tag) {
        case owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_216.data.ra_sub_class_of.f0;
            __auto_type r = _mv_216.data.ra_sub_class_of.f1;
            return owl2_wrap(arena, SLOP_STR("SubClassOf"), owl2_join2(arena, owl2_render_concept(arena, (*l)), owl2_render_concept(arena, (*r))));
        }
        case owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type cs = _mv_216.data.ra_equivalent_classes;
            return owl2_wrap(arena, SLOP_STR("EquivalentClasses"), owl2_render_concept_list(arena, cs));
        }
        case owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_216.data.ra_disjoint_classes;
            return owl2_wrap(arena, SLOP_STR("DisjointClasses"), owl2_render_concept_list(arena, cs));
        }
        case owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type a = _mv_216.data.ra_sub_object_property.f0;
            __auto_type b = _mv_216.data.ra_sub_object_property.f1;
            return owl2_wrap(arena, SLOP_STR("SubObjectPropertyOf"), owl2_join2(arena, owl2_render_role(a), owl2_render_role(b)));
        }
        case owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_216.data.ra_property_chain;
            return owl2_wrap(arena, SLOP_STR("SubObjectPropertyOf"), owl2_join2(arena, owl2_wrap(arena, SLOP_STR("ObjectPropertyChain"), owl2_render_role_list(arena, ch.steps)), owl2_render_role(ch.super)));
        }
        case owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type rs = _mv_216.data.ra_equivalent_properties;
            return owl2_wrap(arena, SLOP_STR("EquivalentObjectProperties"), owl2_render_role_list(arena, rs));
        }
        case owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type r = _mv_216.data.ra_transitive_property;
            return owl2_wrap(arena, SLOP_STR("TransitiveObjectProperty"), owl2_render_role(r));
        }
        case owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_216.data.ra_object_property_domain.f0;
            __auto_type c = _mv_216.data.ra_object_property_domain.f1;
            return owl2_wrap(arena, SLOP_STR("ObjectPropertyDomain"), owl2_join2(arena, owl2_render_role(r), owl2_render_concept(arena, (*c))));
        }
        case owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type r = _mv_216.data.ra_object_property_range.f0;
            __auto_type c = _mv_216.data.ra_object_property_range.f1;
            return owl2_wrap(arena, SLOP_STR("ObjectPropertyRange"), owl2_join2(arena, owl2_render_role(r), owl2_render_concept(arena, (*c))));
        }
        case owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_216.data.ra_class_assertion;
            return owl2_wrap(arena, SLOP_STR("ClassAssertion"), owl2_join2(arena, owl2_render_concept(arena, (*ca.concept)), owl2_render_node(ca.subject)));
        }
        case owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type e = _mv_216.data.ra_object_property_assertion;
            return owl2_wrap(arena, SLOP_STR("ObjectPropertyAssertion"), owl2_join2(arena, owl2_render_role(e.role), owl2_join2(arena, owl2_render_node(e.from), owl2_render_node(e.to))));
        }
        case owl2_RawAxiom_ra_declaration:
        {
            __auto_type d = _mv_216.data.ra_declaration;
            return owl2_wrap(arena, SLOP_STR("Declaration"), d.entity.value);
        }
        case owl2_RawAxiom_ra_annotation:
        {
            return SLOP_STR("Annotation()");
        }
        case owl2_RawAxiom_ra_inverse_properties:
        {
            __auto_type a = _mv_216.data.ra_inverse_properties.f0;
            __auto_type b = _mv_216.data.ra_inverse_properties.f1;
            return owl2_wrap(arena, SLOP_STR("InverseObjectProperties"), owl2_join2(arena, owl2_render_role(a), owl2_render_role(b)));
        }
        case owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type c = _mv_216.data.ra_property_characteristic.f0;
            __auto_type r = _mv_216.data.ra_property_characteristic.f1;
            return owl2_wrap(arena, owl2_render_characteristic(c), owl2_render_role(r));
        }
        case owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type rs = _mv_216.data.ra_disjoint_properties;
            return owl2_wrap(arena, SLOP_STR("DisjointObjectProperties"), owl2_render_role_list(arena, rs));
        }
        case owl2_RawAxiom_ra_same_individual:
        {
            __auto_type ns = _mv_216.data.ra_same_individual;
            return owl2_wrap(arena, SLOP_STR("SameIndividual"), owl2_render_node_list(arena, ns));
        }
        case owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type ns = _mv_216.data.ra_different_individuals;
            return owl2_wrap(arena, SLOP_STR("DifferentIndividuals"), owl2_render_node_list(arena, ns));
        }
        case owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type ref = _mv_216.data.ra_negative_assertion;
            return owl2_wrap(arena, SLOP_STR("NegativeAssertion"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type ref = _mv_216.data.ra_disjoint_union;
            return owl2_wrap(arena, SLOP_STR("DisjointUnion"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_has_key:
        {
            __auto_type ref = _mv_216.data.ra_has_key;
            return owl2_wrap(arena, SLOP_STR("HasKey"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_inverse_expression:
        {
            __auto_type ref = _mv_216.data.ra_inverse_expression;
            return owl2_wrap(arena, SLOP_STR("ObjectInverseOf"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_data_axiom:
        {
            __auto_type ref = _mv_216.data.ra_data_axiom;
            return owl2_wrap(arena, SLOP_STR("DataAxiom"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_builtin_role:
        {
            __auto_type ref = _mv_216.data.ra_builtin_role;
            return owl2_wrap(arena, SLOP_STR("BuiltinRole"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_anonymous_individual:
        {
            __auto_type ref = _mv_216.data.ra_anonymous_individual;
            return owl2_wrap(arena, SLOP_STR("AnonymousIndividual"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_reserved_vocabulary:
        {
            __auto_type ref = _mv_216.data.ra_reserved_vocabulary;
            return owl2_wrap(arena, SLOP_STR("ReservedVocabulary"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_swrl_rule:
        {
            __auto_type ref = _mv_216.data.ra_swrl_rule;
            return owl2_wrap(arena, SLOP_STR("SWRLRule"), owl2_render_input_ref(ref));
        }
        case owl2_RawAxiom_ra_unrecognized:
        {
            __auto_type ref = _mv_216.data.ra_unrecognized;
            return owl2_wrap(arena, SLOP_STR("Unrecognized"), owl2_render_input_ref(ref));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string owl2_render_characteristic(owl2_PropCharacteristic c) {
    __auto_type _mv_217 = c;
    if (_mv_217 == owl2_PropCharacteristic_prop_functional) {
        return SLOP_STR("FunctionalObjectProperty");
    } else if (_mv_217 == owl2_PropCharacteristic_prop_inverse_functional) {
        return SLOP_STR("InverseFunctionalObjectProperty");
    } else if (_mv_217 == owl2_PropCharacteristic_prop_symmetric) {
        return SLOP_STR("SymmetricObjectProperty");
    } else if (_mv_217 == owl2_PropCharacteristic_prop_asymmetric) {
        return SLOP_STR("AsymmetricObjectProperty");
    } else if (_mv_217 == owl2_PropCharacteristic_prop_reflexive) {
        return SLOP_STR("ReflexiveObjectProperty");
    } else if (_mv_217 == owl2_PropCharacteristic_prop_irreflexive) {
        return SLOP_STR("IrreflexiveObjectProperty");
    }
    SLOP_UNREACHABLE();
}

owl2_RawConcept owl2_copy_concept(slop_arena* arena, owl2_RawConcept c) {
    __auto_type _mv_218 = c;
    switch (_mv_218.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_218.data.rc_name;
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
            __auto_type cs = _mv_218.data.rc_and;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_and, .data.rc_and = owl2_copy_concepts(arena, cs) });
        }
        case owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_218.data.rc_some.f0;
            __auto_type f = _mv_218.data.rc_some.f1;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_some, .data.rc_some = { .f0 = types_copy_role(arena, r), .f1 = owl2_copy_boxed(arena, f) } });
        }
        case owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_218.data.rc_or;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_or, .data.rc_or = owl2_copy_concepts(arena, cs) });
        }
        case owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_218.data.rc_not;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_not, .data.rc_not = owl2_copy_boxed(arena, f) });
        }
        case owl2_RawConcept_rc_all:
        {
            __auto_type r = _mv_218.data.rc_all.f0;
            __auto_type f = _mv_218.data.rc_all.f1;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_all, .data.rc_all = { .f0 = types_copy_role(arena, r), .f1 = owl2_copy_boxed(arena, f) } });
        }
        case owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_218.data.rc_oneof;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_oneof, .data.rc_oneof = owl2_copy_nodes(arena, ns) });
        }
        case owl2_RawConcept_rc_has_value:
        {
            __auto_type r = _mv_218.data.rc_has_value.f0;
            __auto_type n = _mv_218.data.rc_has_value.f1;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_has_value, .data.rc_has_value = { .f0 = types_copy_role(arena, r), .f1 = types_copy_node(arena, n) } });
        }
        case owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_218.data.rc_has_self;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_has_self, .data.rc_has_self = types_copy_role(arena, r) });
        }
        case owl2_RawConcept_rc_card:
        {
            __auto_type k = _mv_218.data.rc_card.f0;
            __auto_type r = _mv_218.data.rc_card.f1;
            __auto_type n = _mv_218.data.rc_card.f2;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_card, .data.rc_card = { .f0 = k, .f1 = types_copy_role(arena, r), .f2 = n } });
        }
        case owl2_RawConcept_rc_qcard:
        {
            __auto_type k = _mv_218.data.rc_qcard.f0;
            __auto_type r = _mv_218.data.rc_qcard.f1;
            __auto_type n = _mv_218.data.rc_qcard.f2;
            __auto_type f = _mv_218.data.rc_qcard.f3;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_qcard, .data.rc_qcard = { .f0 = k, .f1 = types_copy_role(arena, r), .f2 = n, .f3 = owl2_copy_boxed(arena, f) } });
        }
        case owl2_RawConcept_rc_data:
        {
            __auto_type ref = _mv_218.data.rc_data;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_data, .data.rc_data = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawConcept_rc_anon:
        {
            __auto_type ref = _mv_218.data.rc_anon;
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
        __auto_type out = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (owl2_copy_concept(arena, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_Node owl2_copy_nodes(slop_arena* arena, slop_list_types_Node ns) {
    {
        __auto_type out = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (types_copy_node(arena, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_RoleId owl2_copy_roles(slop_arena* arena, slop_list_types_RoleId rs) {
    {
        __auto_type out = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (types_copy_role(arena, r)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

owl2_RawAxiom owl2_copy_raw_axiom(slop_arena* arena, owl2_RawAxiom ax) {
    __auto_type _mv_219 = ax;
    switch (_mv_219.tag) {
        case owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_219.data.ra_sub_class_of.f0;
            __auto_type r = _mv_219.data.ra_sub_class_of.f1;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_sub_class_of, .data.ra_sub_class_of = { .f0 = owl2_copy_boxed(arena, l), .f1 = owl2_copy_boxed(arena, r) } });
        }
        case owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type cs = _mv_219.data.ra_equivalent_classes;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_equivalent_classes, .data.ra_equivalent_classes = owl2_copy_concepts(arena, cs) });
        }
        case owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_219.data.ra_disjoint_classes;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_classes, .data.ra_disjoint_classes = owl2_copy_concepts(arena, cs) });
        }
        case owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type a = _mv_219.data.ra_sub_object_property.f0;
            __auto_type b = _mv_219.data.ra_sub_object_property.f1;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_sub_object_property, .data.ra_sub_object_property = { .f0 = types_copy_role(arena, a), .f1 = types_copy_role(arena, b) } });
        }
        case owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_219.data.ra_property_chain;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_property_chain, .data.ra_property_chain = ((owl2_RawChain){.steps = owl2_copy_roles(arena, ch.steps), .super = types_copy_role(arena, ch.super)}) });
        }
        case owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type rs = _mv_219.data.ra_equivalent_properties;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_equivalent_properties, .data.ra_equivalent_properties = owl2_copy_roles(arena, rs) });
        }
        case owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type r = _mv_219.data.ra_transitive_property;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_transitive_property, .data.ra_transitive_property = types_copy_role(arena, r) });
        }
        case owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_219.data.ra_object_property_domain.f0;
            __auto_type c = _mv_219.data.ra_object_property_domain.f1;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_object_property_domain, .data.ra_object_property_domain = { .f0 = types_copy_role(arena, r), .f1 = owl2_copy_boxed(arena, c) } });
        }
        case owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type r = _mv_219.data.ra_object_property_range.f0;
            __auto_type c = _mv_219.data.ra_object_property_range.f1;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_object_property_range, .data.ra_object_property_range = { .f0 = types_copy_role(arena, r), .f1 = owl2_copy_boxed(arena, c) } });
        }
        case owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_219.data.ra_class_assertion;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_class_assertion, .data.ra_class_assertion = ((owl2_RawClassAssertion){.concept = owl2_copy_boxed(arena, ca.concept), .subject = types_copy_node(arena, ca.subject)}) });
        }
        case owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type e = _mv_219.data.ra_object_property_assertion;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_object_property_assertion, .data.ra_object_property_assertion = ((owl2_RawEdge){.role = types_copy_role(arena, e.role), .from = types_copy_node(arena, e.from), .to = types_copy_node(arena, e.to)}) });
        }
        case owl2_RawAxiom_ra_declaration:
        {
            __auto_type d = _mv_219.data.ra_declaration;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_declaration, .data.ra_declaration = ((owl2_RawDeclaration){.kind = d.kind, .entity = types_copy_iri(arena, d.entity)}) });
        }
        case owl2_RawAxiom_ra_annotation:
        {
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_annotation });
        }
        case owl2_RawAxiom_ra_inverse_properties:
        {
            __auto_type a = _mv_219.data.ra_inverse_properties.f0;
            __auto_type b = _mv_219.data.ra_inverse_properties.f1;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inverse_properties, .data.ra_inverse_properties = { .f0 = types_copy_role(arena, a), .f1 = types_copy_role(arena, b) } });
        }
        case owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type c = _mv_219.data.ra_property_characteristic.f0;
            __auto_type r = _mv_219.data.ra_property_characteristic.f1;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_property_characteristic, .data.ra_property_characteristic = { .f0 = c, .f1 = types_copy_role(arena, r) } });
        }
        case owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type rs = _mv_219.data.ra_disjoint_properties;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_properties, .data.ra_disjoint_properties = owl2_copy_roles(arena, rs) });
        }
        case owl2_RawAxiom_ra_same_individual:
        {
            __auto_type ns = _mv_219.data.ra_same_individual;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_same_individual, .data.ra_same_individual = owl2_copy_nodes(arena, ns) });
        }
        case owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type ns = _mv_219.data.ra_different_individuals;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_different_individuals, .data.ra_different_individuals = owl2_copy_nodes(arena, ns) });
        }
        case owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type ref = _mv_219.data.ra_negative_assertion;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_negative_assertion, .data.ra_negative_assertion = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type ref = _mv_219.data.ra_disjoint_union;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_union, .data.ra_disjoint_union = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_has_key:
        {
            __auto_type ref = _mv_219.data.ra_has_key;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_has_key, .data.ra_has_key = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_inverse_expression:
        {
            __auto_type ref = _mv_219.data.ra_inverse_expression;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inverse_expression, .data.ra_inverse_expression = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_data_axiom:
        {
            __auto_type ref = _mv_219.data.ra_data_axiom;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_builtin_role:
        {
            __auto_type ref = _mv_219.data.ra_builtin_role;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_builtin_role, .data.ra_builtin_role = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_anonymous_individual:
        {
            __auto_type ref = _mv_219.data.ra_anonymous_individual;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_reserved_vocabulary:
        {
            __auto_type ref = _mv_219.data.ra_reserved_vocabulary;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_swrl_rule:
        {
            __auto_type ref = _mv_219.data.ra_swrl_rule;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_swrl_rule, .data.ra_swrl_rule = types_copy_input_ref(arena, ref) });
        }
        case owl2_RawAxiom_ra_unrecognized:
        {
            __auto_type ref = _mv_219.data.ra_unrecognized;
            return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = types_copy_input_ref(arena, ref) });
        }
    }
    SLOP_UNREACHABLE();
}

owl2_RawAxiom owl2_raw_axiom_at(slop_list_owl2_RawAxiom xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_220 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_owl2_RawAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_220.has_value) {
        __auto_type v = _mv_220.value;
        return v;
    } else if (!_mv_220.has_value) {
        return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_annotation });
    }
    SLOP_UNREACHABLE();
}

slop_list_owl2_RawAxiom owl2_copy_axioms(slop_arena* arena, slop_list_owl2_RawAxiom xs) {
    slop_list_owl2_RawAxiom _retval = {0};
    {
        __auto_type n = ((int64_t)(((int64_t)((xs).len))));
        __auto_type out = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0 });
        int64_t i = 0;
        while (i < n) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (owl2_copy_raw_axiom(arena, owl2_raw_axiom_at(xs, i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        _retval = out;
    }
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
                    ({ rdf_IRI _key_221 = (types_copy_iri(arena, i)); slop_map_put(arena, out.classes, &_key_221, NULL, 0); });
                }
            }
        }
        {
            slop_map* _coll = (slop_map*)sig.obj_props;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    rdf_IRI i = *(rdf_IRI*)slop_map_key_at(_coll, _i);
                    ({ rdf_IRI _key_222 = (types_copy_iri(arena, i)); slop_map_put(arena, out.obj_props, &_key_222, NULL, 0); });
                }
            }
        }
        {
            slop_map* _coll = (slop_map*)sig.data_props;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    rdf_IRI i = *(rdf_IRI*)slop_map_key_at(_coll, _i);
                    ({ rdf_IRI _key_223 = (types_copy_iri(arena, i)); slop_map_put(arena, out.data_props, &_key_223, NULL, 0); });
                }
            }
        }
        {
            slop_map* _coll = (slop_map*)sig.annot_props;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    rdf_IRI i = *(rdf_IRI*)slop_map_key_at(_coll, _i);
                    ({ rdf_IRI _key_224 = (types_copy_iri(arena, i)); slop_map_put(arena, out.annot_props, &_key_224, NULL, 0); });
                }
            }
        }
        {
            slop_map* _coll = (slop_map*)sig.individuals;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    rdf_IRI i = *(rdf_IRI*)slop_map_key_at(_coll, _i);
                    ({ rdf_IRI _key_225 = (types_copy_iri(arena, i)); slop_map_put(arena, out.individuals, &_key_225, NULL, 0); });
                }
            }
        }
        {
            slop_map* _coll = (slop_map*)sig.datatypes;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    rdf_IRI i = *(rdf_IRI*)slop_map_key_at(_coll, _i);
                    ({ rdf_IRI _key_226 = (types_copy_iri(arena, i)); slop_map_put(arena, out.datatypes, &_key_226, NULL, 0); });
                }
            }
        }
        return out;
    }
}

slop_list_owl2_RawConcept owl2_sort_concepts(slop_arena* arena, slop_list_owl2_RawConcept xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ owl2__lambda_227_env_t* owl2__lambda_227_env = (owl2__lambda_227_env_t*)slop_arena_alloc(arena, sizeof(owl2__lambda_227_env_t)); *owl2__lambda_227_env = (owl2__lambda_227_env_t){ .xs = xs }; (slop_closure_t){ (void*)owl2__lambda_227, (void*)owl2__lambda_227_env }; }));
        __auto_type out = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (owl2_concept_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

