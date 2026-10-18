#include "../runtime/slop_runtime.h"
#include "slop_owl2.h"


howl_owl2_Disposition howl_owl2_disposition(howl_types_Profile p, howl_owl2_RawAxiom ax);
howl_owl2_Signature howl_owl2_make_signature(slop_arena* arena);
uint8_t howl_owl2_signature_has_class(howl_owl2_Signature sig, slop_rdf_rdf_IRI i);
uint8_t howl_owl2_signature_has_object_property(howl_owl2_Signature sig, slop_rdf_rdf_IRI i);
uint8_t howl_owl2_signature_has_annotation_property(howl_owl2_Signature sig, slop_rdf_rdf_IRI i);
uint8_t howl_owl2_signature_has_data_property(howl_owl2_Signature sig, slop_rdf_rdf_IRI i);
int64_t howl_owl2_signature_size(slop_arena* arena, howl_owl2_Signature sig);
uint8_t howl_owl2_is_el_plus_plus(howl_types_Profile p);
howl_owl2_Disposition howl_owl2_when_el_plus_plus(howl_types_Profile p);
uint8_t howl_owl2_is_sriq(howl_types_Profile p);
howl_owl2_Disposition howl_owl2_when_sriq(howl_types_Profile p);
howl_owl2_Disposition howl_owl2_when_el_plus_plus_or_sriq(howl_types_Profile p);
uint8_t howl_owl2_role_in_profile(howl_types_Profile p, howl_types_RoleId r);
uint8_t howl_owl2_roles_in_profile(howl_types_Profile p, slop_list_howl_types_RoleId rs);
uint8_t howl_owl2_concepts_in_profile(howl_types_Profile p, slop_list_howl_owl2_RawConcept cs);
uint8_t howl_owl2_concept_in_profile(howl_types_Profile p, howl_owl2_RawConcept c);
uint8_t howl_owl2_axiom_in_profile(howl_types_Profile p, howl_owl2_RawAxiom ax);
uint8_t howl_owl2_concepts_in_profile_at(howl_types_Profile p, int64_t cap, slop_list_howl_owl2_RawConcept cs);
uint8_t howl_owl2_concept_in_profile_at(howl_types_Profile p, int64_t cap, howl_owl2_RawConcept c);
uint8_t howl_owl2_axiom_in_profile_at(howl_types_Profile p, int64_t cap, howl_owl2_RawAxiom ax);
int64_t howl_owl2_concept_tag_rank(howl_owl2_RawConcept c);
int64_t howl_owl2_concept_list_cmp(slop_list_howl_owl2_RawConcept a, slop_list_howl_owl2_RawConcept b);
howl_owl2_RawConcept howl_owl2_concept_at(slop_list_howl_owl2_RawConcept xs, int64_t i);
int64_t howl_owl2_concept_cmp(howl_owl2_RawConcept a, howl_owl2_RawConcept b);
int64_t howl_owl2_card_cmp(howl_owl2_CardKind ka, howl_types_RoleId ra, int64_t na, howl_owl2_CardKind kb, howl_types_RoleId rb, int64_t nb);
int64_t howl_owl2_card_rank(howl_owl2_CardKind k);
int64_t howl_owl2_node_list_cmp(slop_list_howl_types_Node a, slop_list_howl_types_Node b);
slop_string howl_owl2_render_role(slop_arena* arena, howl_types_RoleId r);
slop_string howl_owl2_render_node(howl_types_Node n);
slop_string howl_owl2_render_card_kind(howl_owl2_CardKind k);
slop_string howl_owl2_render_concept_list(slop_arena* arena, slop_list_howl_owl2_RawConcept cs);
slop_string howl_owl2_render_node_list(slop_arena* arena, slop_list_howl_types_Node ns);
slop_string howl_owl2_render_role_list(slop_arena* arena, slop_list_howl_types_RoleId rs);
slop_string howl_owl2_wrap(slop_arena* arena, slop_string head, slop_string body);
slop_string howl_owl2_join2(slop_arena* arena, slop_string a, slop_string b);
slop_string howl_owl2_render_concept(slop_arena* arena, howl_owl2_RawConcept c);
slop_string howl_owl2_render_input_ref(howl_types_InputRef r);
slop_string howl_owl2_render_entity_kind(howl_types_EntityKind k);
slop_string howl_owl2_render_omission(slop_arena* arena, howl_types_Omission o);
slop_string howl_owl2_render_axiom(slop_arena* arena, howl_owl2_RawAxiom ax);
slop_string howl_owl2_render_characteristic(howl_owl2_PropCharacteristic c);
howl_owl2_RawConcept howl_owl2_copy_concept(slop_arena* arena, howl_owl2_RawConcept c);
howl_owl2_RawConcept* howl_owl2_copy_boxed(slop_arena* arena, howl_owl2_RawConcept* p);
slop_list_howl_owl2_RawConcept howl_owl2_copy_concepts(slop_arena* arena, slop_list_howl_owl2_RawConcept cs);
slop_list_howl_types_Node howl_owl2_copy_nodes(slop_arena* arena, slop_list_howl_types_Node ns);
slop_list_howl_types_RoleId howl_owl2_copy_roles(slop_arena* arena, slop_list_howl_types_RoleId rs);
howl_owl2_RawAxiom howl_owl2_copy_raw_axiom(slop_arena* arena, howl_owl2_RawAxiom ax);
howl_owl2_RawAxiom howl_owl2_raw_axiom_at(slop_list_howl_owl2_RawAxiom xs, int64_t i);
slop_list_howl_owl2_RawAxiom howl_owl2_copy_axioms(slop_arena* arena, slop_list_howl_owl2_RawAxiom xs);
howl_owl2_Signature howl_owl2_copy_signature(slop_arena* arena, howl_owl2_Signature sig);
slop_list_howl_owl2_RawConcept howl_owl2_sort_concepts(slop_arena* arena, slop_list_howl_owl2_RawConcept xs);

typedef struct { slop_list_howl_owl2_RawConcept xs; } howl_owl2__lambda_151_env_t;

static int64_t howl_owl2__lambda_151(howl_owl2__lambda_151_env_t* _env, int64_t i, int64_t j) { return howl_owl2_concept_cmp(howl_owl2_concept_at(_env->xs, i), howl_owl2_concept_at(_env->xs, j)); }

howl_owl2_Disposition howl_owl2_disposition(howl_types_Profile p, howl_owl2_RawAxiom ax) {
    __auto_type _mv_106 = ax;
    switch (_mv_106.tag) {
        case howl_owl2_RawAxiom_ra_sub_class_of:
        {
            return howl_owl2_Disposition_d_in_profile;
        }
        case howl_owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type _ = _mv_106.data.ra_equivalent_classes;
            return howl_owl2_Disposition_d_in_profile;
        }
        case howl_owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type _ = _mv_106.data.ra_disjoint_classes;
            return howl_owl2_Disposition_d_in_profile;
        }
        case howl_owl2_RawAxiom_ra_sub_object_property:
        {
            return howl_owl2_Disposition_d_in_profile;
        }
        case howl_owl2_RawAxiom_ra_property_chain:
        {
            __auto_type _ = _mv_106.data.ra_property_chain;
            return howl_owl2_Disposition_d_in_profile;
        }
        case howl_owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type _ = _mv_106.data.ra_equivalent_properties;
            return howl_owl2_Disposition_d_in_profile;
        }
        case howl_owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type _ = _mv_106.data.ra_transitive_property;
            return howl_owl2_Disposition_d_in_profile;
        }
        case howl_owl2_RawAxiom_ra_object_property_domain:
        {
            return howl_owl2_Disposition_d_in_profile;
        }
        case howl_owl2_RawAxiom_ra_object_property_range:
        {
            return howl_owl2_Disposition_d_in_profile;
        }
        case howl_owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type _ = _mv_106.data.ra_class_assertion;
            return howl_owl2_Disposition_d_in_profile;
        }
        case howl_owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type _ = _mv_106.data.ra_object_property_assertion;
            return howl_owl2_Disposition_d_in_profile;
        }
        case howl_owl2_RawAxiom_ra_declaration:
        {
            __auto_type _ = _mv_106.data.ra_declaration;
            return howl_owl2_Disposition_d_consumed;
        }
        case howl_owl2_RawAxiom_ra_annotation:
        {
            return howl_owl2_Disposition_d_inert;
        }
        case howl_owl2_RawAxiom_ra_inert_data:
        {
            return howl_owl2_Disposition_d_inert;
        }
        case howl_owl2_RawAxiom_ra_inverse_properties:
        {
            return howl_owl2_when_sriq(p);
        }
        case howl_owl2_RawAxiom_ra_property_characteristic:
        {
            return howl_owl2_when_el_plus_plus_or_sriq(p);
        }
        case howl_owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type _ = _mv_106.data.ra_disjoint_properties;
            return howl_owl2_when_sriq(p);
        }
        case howl_owl2_RawAxiom_ra_same_individual:
        {
            __auto_type _ = _mv_106.data.ra_same_individual;
            return howl_owl2_when_el_plus_plus_or_sriq(p);
        }
        case howl_owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type _ = _mv_106.data.ra_different_individuals;
            return howl_owl2_when_el_plus_plus_or_sriq(p);
        }
        case howl_owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type _ = _mv_106.data.ra_negative_assertion;
            return howl_owl2_when_el_plus_plus_or_sriq(p);
        }
        case howl_owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type _ = _mv_106.data.ra_disjoint_union;
            return howl_owl2_when_sriq(p);
        }
        case howl_owl2_RawAxiom_ra_has_key:
        {
            __auto_type _ = _mv_106.data.ra_has_key;
            return howl_owl2_Disposition_d_out_of_profile;
        }
        case howl_owl2_RawAxiom_ra_data_axiom:
        {
            __auto_type _ = _mv_106.data.ra_data_axiom;
            return howl_owl2_Disposition_d_out_of_profile;
        }
        case howl_owl2_RawAxiom_ra_builtin_role:
        {
            __auto_type _ = _mv_106.data.ra_builtin_role;
            return howl_owl2_Disposition_d_out_of_profile;
        }
        case howl_owl2_RawAxiom_ra_anonymous_individual:
        {
            __auto_type _ = _mv_106.data.ra_anonymous_individual;
            return howl_owl2_Disposition_d_out_of_profile;
        }
        case howl_owl2_RawAxiom_ra_reserved_vocabulary:
        {
            __auto_type _ = _mv_106.data.ra_reserved_vocabulary;
            return howl_owl2_Disposition_d_out_of_profile;
        }
        case howl_owl2_RawAxiom_ra_swrl_rule:
        {
            __auto_type _ = _mv_106.data.ra_swrl_rule;
            return howl_owl2_Disposition_d_out_of_profile;
        }
        case howl_owl2_RawAxiom_ra_unrecognized:
        {
            __auto_type _ = _mv_106.data.ra_unrecognized;
            return howl_owl2_Disposition_d_out_of_profile;
        }
    }
    SLOP_UNREACHABLE();
}

howl_owl2_Signature howl_owl2_make_signature(slop_arena* arena) {
    return ((howl_owl2_Signature){.classes = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .obj_props = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .data_props = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .annot_props = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .individuals = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .datatypes = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); })});
}

uint8_t howl_owl2_signature_has_class(howl_owl2_Signature sig, slop_rdf_rdf_IRI i) {
    return slop_map_has(sig.classes, &(i));
}

uint8_t howl_owl2_signature_has_object_property(howl_owl2_Signature sig, slop_rdf_rdf_IRI i) {
    return slop_map_has(sig.obj_props, &(i));
}

uint8_t howl_owl2_signature_has_annotation_property(howl_owl2_Signature sig, slop_rdf_rdf_IRI i) {
    return slop_map_has(sig.annot_props, &(i));
}

uint8_t howl_owl2_signature_has_data_property(howl_owl2_Signature sig, slop_rdf_rdf_IRI i) {
    return slop_map_has(sig.data_props, &(i));
}

int64_t howl_owl2_signature_size(slop_arena* arena, howl_owl2_Signature sig) {
    return (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.classes); (slop_list_slop_rdf_rdf_IRI){.data = (slop_rdf_rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; })).len)))) + (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.obj_props); (slop_list_slop_rdf_rdf_IRI){.data = (slop_rdf_rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; })).len)))) + (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.data_props); (slop_list_slop_rdf_rdf_IRI){.data = (slop_rdf_rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; })).len)))) + (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.annot_props); (slop_list_slop_rdf_rdf_IRI){.data = (slop_rdf_rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; })).len)))) + (((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.individuals); (slop_list_slop_rdf_rdf_IRI){.data = (slop_rdf_rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; })).len)))) + ((int64_t)(((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.datatypes); (slop_list_slop_rdf_rdf_IRI){.data = (slop_rdf_rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; })).len)))))))));
}

uint8_t howl_owl2_is_el_plus_plus(howl_types_Profile p) {
    uint8_t _retval = {0};
    __auto_type _mv_111 = p;
    if (_mv_111 == howl_types_Profile_profile_el) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_111 == howl_types_Profile_profile_el_plus_plus) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_111 == howl_types_Profile_profile_horn_sriq) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_111 == howl_types_Profile_profile_sriq) {
        _retval = 0;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST(((_retval == (p == howl_types_Profile_profile_el_plus_plus))), "(== $result (== p (quote profile-el-plus-plus)))");
    return _retval;
}

howl_owl2_Disposition howl_owl2_when_el_plus_plus(howl_types_Profile p) {
    howl_owl2_Disposition _retval = {0};
    if (howl_owl2_is_el_plus_plus(p)) {
        _retval = howl_owl2_Disposition_d_in_profile;
        goto _slop_post;
    } else {
        _retval = howl_owl2_Disposition_d_out_of_profile;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((_retval == howl_owl2_Disposition_d_in_profile) == (p == howl_types_Profile_profile_el_plus_plus))), "(== (== $result (quote d-in-profile)) (== p (quote profile-el-plus-plus)))");
    return _retval;
}

uint8_t howl_owl2_is_sriq(howl_types_Profile p) {
    uint8_t _retval = {0};
    __auto_type _mv_112 = p;
    if (_mv_112 == howl_types_Profile_profile_sriq) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_112 == howl_types_Profile_profile_el) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_112 == howl_types_Profile_profile_el_plus_plus) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_112 == howl_types_Profile_profile_horn_sriq) {
        _retval = 0;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST(((_retval == (p == howl_types_Profile_profile_sriq))), "(== $result (== p (quote profile-sriq)))");
    return _retval;
}

howl_owl2_Disposition howl_owl2_when_sriq(howl_types_Profile p) {
    howl_owl2_Disposition _retval = {0};
    if (howl_owl2_is_sriq(p)) {
        _retval = howl_owl2_Disposition_d_in_profile;
        goto _slop_post;
    } else {
        _retval = howl_owl2_Disposition_d_out_of_profile;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((_retval == howl_owl2_Disposition_d_in_profile) == (p == howl_types_Profile_profile_sriq))), "(== (== $result (quote d-in-profile)) (== p (quote profile-sriq)))");
    return _retval;
}

howl_owl2_Disposition howl_owl2_when_el_plus_plus_or_sriq(howl_types_Profile p) {
    howl_owl2_Disposition _retval = {0};
    if (howl_owl2_is_el_plus_plus(p) || howl_owl2_is_sriq(p)) {
        _retval = howl_owl2_Disposition_d_in_profile;
        goto _slop_post;
    } else {
        _retval = howl_owl2_Disposition_d_out_of_profile;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST((((_retval == howl_owl2_Disposition_d_in_profile) == (p(==, howl_types_Profile_profile_el_plus_plus) || p(==, howl_types_Profile_profile_sriq)))), "(== (== $result (quote d-in-profile)) (or (p == (quote profile-el-plus-plus)) (p == (quote profile-sriq))))");
    return _retval;
}

uint8_t howl_owl2_role_in_profile(howl_types_Profile p, howl_types_RoleId r) {
    __auto_type _mv_113 = r;
    switch (_mv_113.tag) {
        case howl_types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_113.data.fresh_role;
            return 1;
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type i = _mv_113.data.inverse_role;
            return ((howl_owl2_is_sriq(p)) && (!((howl_canon_string_cmp(i.value, slop_rdf_vocab_OWL_TOP_OBJECT_PROPERTY) == 0))) && (!((howl_canon_string_cmp(i.value, slop_rdf_vocab_OWL_TOP_DATA_PROPERTY) == 0))) && (!((howl_canon_string_cmp(i.value, slop_rdf_vocab_OWL_BOTTOM_DATA_PROPERTY) == 0))));
        }
        case howl_types_RoleId_named_role:
        {
            __auto_type i = _mv_113.data.named_role;
            if (howl_canon_string_cmp(i.value, slop_rdf_vocab_OWL_BOTTOM_OBJECT_PROPERTY) == 0) {
                return (howl_owl2_is_el_plus_plus(p) || howl_owl2_is_sriq(p));
            } else if (howl_canon_string_cmp(i.value, slop_rdf_vocab_OWL_TOP_OBJECT_PROPERTY) == 0) {
                return 0;
            } else if (howl_canon_string_cmp(i.value, slop_rdf_vocab_OWL_TOP_DATA_PROPERTY) == 0) {
                return 0;
            } else if (howl_canon_string_cmp(i.value, slop_rdf_vocab_OWL_BOTTOM_DATA_PROPERTY) == 0) {
                return 0;
            } else {
                return 1;
            }
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_owl2_roles_in_profile(howl_types_Profile p, slop_list_howl_types_RoleId rs) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                if (!(howl_owl2_role_in_profile(p, r))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t howl_owl2_concepts_in_profile(howl_types_Profile p, slop_list_howl_owl2_RawConcept cs) {
    return howl_owl2_concepts_in_profile_at(p, howl_owl2_SRIQ_MAX_COUNT, cs);
}

uint8_t howl_owl2_concept_in_profile(howl_types_Profile p, howl_owl2_RawConcept c) {
    return howl_owl2_concept_in_profile_at(p, howl_owl2_SRIQ_MAX_COUNT, c);
}

uint8_t howl_owl2_axiom_in_profile(howl_types_Profile p, howl_owl2_RawAxiom ax) {
    return howl_owl2_axiom_in_profile_at(p, howl_owl2_SRIQ_MAX_COUNT, ax);
}

uint8_t howl_owl2_concepts_in_profile_at(howl_types_Profile p, int64_t cap, slop_list_howl_owl2_RawConcept cs) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(howl_owl2_concept_in_profile_at(p, cap, c))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t howl_owl2_concept_in_profile_at(howl_types_Profile p, int64_t cap, howl_owl2_RawConcept c) {
    __auto_type _mv_114 = c;
    switch (_mv_114.tag) {
        case howl_owl2_RawConcept_rc_name:
        {
            __auto_type _ = _mv_114.data.rc_name;
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
            __auto_type cs = _mv_114.data.rc_and;
            return howl_owl2_concepts_in_profile_at(p, cap, cs);
        }
        case howl_owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_114.data.rc_some.f0;
            __auto_type f = _mv_114.data.rc_some.f1;
            return (howl_owl2_role_in_profile(p, r) && howl_owl2_concept_in_profile_at(p, cap, (*f)));
        }
        case howl_owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_114.data.rc_or;
            return (howl_owl2_is_sriq(p) && howl_owl2_concepts_in_profile_at(p, cap, cs));
        }
        case howl_owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_114.data.rc_not;
            return (howl_owl2_is_sriq(p) && howl_owl2_concept_in_profile_at(p, cap, (*f)));
        }
        case howl_owl2_RawConcept_rc_all:
        {
            __auto_type r = _mv_114.data.rc_all.f0;
            __auto_type f = _mv_114.data.rc_all.f1;
            return ((howl_owl2_is_sriq(p)) && (howl_owl2_role_in_profile(p, r)) && (howl_owl2_concept_in_profile_at(p, cap, (*f))));
        }
        case howl_owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_114.data.rc_oneof;
            return (howl_owl2_is_el_plus_plus(p) && (((int64_t)((ns).len)) == 1));
        }
        case howl_owl2_RawConcept_rc_has_value:
        {
            __auto_type r = _mv_114.data.rc_has_value.f0;
            return (howl_owl2_is_el_plus_plus(p) && howl_owl2_role_in_profile(p, r));
        }
        case howl_owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_114.data.rc_has_self;
            return ((howl_owl2_is_el_plus_plus(p) || howl_owl2_is_sriq(p)) && howl_owl2_role_in_profile(p, r));
        }
        case howl_owl2_RawConcept_rc_card:
        {
            __auto_type r = _mv_114.data.rc_card.f1;
            __auto_type n = _mv_114.data.rc_card.f2;
            return ((howl_owl2_is_sriq(p)) && ((n <= cap)) && (howl_owl2_role_in_profile(p, r)));
        }
        case howl_owl2_RawConcept_rc_qcard:
        {
            __auto_type r = _mv_114.data.rc_qcard.f1;
            __auto_type n = _mv_114.data.rc_qcard.f2;
            __auto_type f = _mv_114.data.rc_qcard.f3;
            return ((howl_owl2_is_sriq(p)) && ((n <= cap)) && (howl_owl2_role_in_profile(p, r)) && (howl_owl2_concept_in_profile_at(p, cap, (*f))));
        }
        case howl_owl2_RawConcept_rc_data:
        {
            __auto_type _ = _mv_114.data.rc_data;
            return 0;
        }
        case howl_owl2_RawConcept_rc_anon:
        {
            __auto_type _ = _mv_114.data.rc_anon;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_owl2_axiom_in_profile_at(howl_types_Profile p, int64_t cap, howl_owl2_RawAxiom ax) {
    if (howl_owl2_disposition(p, ax) != howl_owl2_Disposition_d_in_profile) {
        return 0;
    } else {
        __auto_type _mv_115 = ax;
        switch (_mv_115.tag) {
            case howl_owl2_RawAxiom_ra_sub_class_of:
            {
                __auto_type l = _mv_115.data.ra_sub_class_of.f0;
                __auto_type r = _mv_115.data.ra_sub_class_of.f1;
                return (howl_owl2_concept_in_profile_at(p, cap, (*l)) && howl_owl2_concept_in_profile_at(p, cap, (*r)));
            }
            case howl_owl2_RawAxiom_ra_equivalent_classes:
            {
                __auto_type cs = _mv_115.data.ra_equivalent_classes;
                return howl_owl2_concepts_in_profile_at(p, cap, cs);
            }
            case howl_owl2_RawAxiom_ra_disjoint_classes:
            {
                __auto_type cs = _mv_115.data.ra_disjoint_classes;
                return howl_owl2_concepts_in_profile_at(p, cap, cs);
            }
            case howl_owl2_RawAxiom_ra_object_property_domain:
            {
                __auto_type r = _mv_115.data.ra_object_property_domain.f0;
                __auto_type c = _mv_115.data.ra_object_property_domain.f1;
                return (howl_owl2_role_in_profile(p, r) && howl_owl2_concept_in_profile_at(p, cap, (*c)));
            }
            case howl_owl2_RawAxiom_ra_object_property_range:
            {
                __auto_type r = _mv_115.data.ra_object_property_range.f0;
                __auto_type c = _mv_115.data.ra_object_property_range.f1;
                return (howl_owl2_role_in_profile(p, r) && howl_owl2_concept_in_profile_at(p, cap, (*c)));
            }
            case howl_owl2_RawAxiom_ra_class_assertion:
            {
                __auto_type ca = _mv_115.data.ra_class_assertion;
                return howl_owl2_concept_in_profile_at(p, cap, (*ca.concept));
            }
            case howl_owl2_RawAxiom_ra_sub_object_property:
            {
                __auto_type a = _mv_115.data.ra_sub_object_property.f0;
                __auto_type b = _mv_115.data.ra_sub_object_property.f1;
                return (howl_owl2_role_in_profile(p, a) && howl_owl2_role_in_profile(p, b));
            }
            case howl_owl2_RawAxiom_ra_property_chain:
            {
                __auto_type ch = _mv_115.data.ra_property_chain;
                return (howl_owl2_roles_in_profile(p, ch.steps) && howl_owl2_role_in_profile(p, ch.super));
            }
            case howl_owl2_RawAxiom_ra_equivalent_properties:
            {
                __auto_type rs = _mv_115.data.ra_equivalent_properties;
                return howl_owl2_roles_in_profile(p, rs);
            }
            case howl_owl2_RawAxiom_ra_transitive_property:
            {
                __auto_type r = _mv_115.data.ra_transitive_property;
                return howl_owl2_role_in_profile(p, r);
            }
            case howl_owl2_RawAxiom_ra_object_property_assertion:
            {
                __auto_type e = _mv_115.data.ra_object_property_assertion;
                return howl_owl2_role_in_profile(p, e.role);
            }
            case howl_owl2_RawAxiom_ra_property_characteristic:
            {
                __auto_type c = _mv_115.data.ra_property_characteristic.f0;
                __auto_type r = _mv_115.data.ra_property_characteristic.f1;
                return ((howl_owl2_is_sriq(p) || (c == howl_owl2_PropCharacteristic_prop_reflexive)) && howl_owl2_role_in_profile(p, r));
            }
            case howl_owl2_RawAxiom_ra_same_individual:
            {
                __auto_type ns = _mv_115.data.ra_same_individual;
                return (((int64_t)((ns).len)) >= 2);
            }
            case howl_owl2_RawAxiom_ra_different_individuals:
            {
                __auto_type ns = _mv_115.data.ra_different_individuals;
                return (((int64_t)((ns).len)) >= 2);
            }
            case howl_owl2_RawAxiom_ra_negative_assertion:
            {
                __auto_type e = _mv_115.data.ra_negative_assertion;
                return howl_owl2_role_in_profile(p, e.role);
            }
            case howl_owl2_RawAxiom_ra_declaration:
            {
                __auto_type _ = _mv_115.data.ra_declaration;
                return 0;
            }
            case howl_owl2_RawAxiom_ra_annotation:
            {
                return 0;
            }
            case howl_owl2_RawAxiom_ra_inert_data:
            {
                return 0;
            }
            case howl_owl2_RawAxiom_ra_inverse_properties:
            {
                __auto_type a = _mv_115.data.ra_inverse_properties.f0;
                __auto_type b = _mv_115.data.ra_inverse_properties.f1;
                return (howl_owl2_role_in_profile(p, a) && howl_owl2_role_in_profile(p, b));
            }
            case howl_owl2_RawAxiom_ra_disjoint_properties:
            {
                __auto_type rs = _mv_115.data.ra_disjoint_properties;
                return ((((int64_t)((rs).len)) >= 2) && howl_owl2_roles_in_profile(p, rs));
            }
            case howl_owl2_RawAxiom_ra_disjoint_union:
            {
                __auto_type du = _mv_115.data.ra_disjoint_union;
                return ((((int64_t)((du.members).len)) >= 2) && howl_owl2_concepts_in_profile_at(p, cap, du.members));
            }
            case howl_owl2_RawAxiom_ra_has_key:
            {
                __auto_type _ = _mv_115.data.ra_has_key;
                return 0;
            }
            case howl_owl2_RawAxiom_ra_data_axiom:
            {
                __auto_type _ = _mv_115.data.ra_data_axiom;
                return 0;
            }
            case howl_owl2_RawAxiom_ra_builtin_role:
            {
                __auto_type _ = _mv_115.data.ra_builtin_role;
                return 0;
            }
            case howl_owl2_RawAxiom_ra_anonymous_individual:
            {
                __auto_type _ = _mv_115.data.ra_anonymous_individual;
                return 0;
            }
            case howl_owl2_RawAxiom_ra_reserved_vocabulary:
            {
                __auto_type _ = _mv_115.data.ra_reserved_vocabulary;
                return 0;
            }
            case howl_owl2_RawAxiom_ra_swrl_rule:
            {
                __auto_type _ = _mv_115.data.ra_swrl_rule;
                return 0;
            }
            case howl_owl2_RawAxiom_ra_unrecognized:
            {
                __auto_type _ = _mv_115.data.ra_unrecognized;
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    }
}

int64_t howl_owl2_concept_tag_rank(howl_owl2_RawConcept c) {
    __auto_type _mv_116 = c;
    switch (_mv_116.tag) {
        case howl_owl2_RawConcept_rc_thing:
        {
            return 0;
        }
        case howl_owl2_RawConcept_rc_nothing:
        {
            return 1;
        }
        case howl_owl2_RawConcept_rc_name:
        {
            __auto_type _ = _mv_116.data.rc_name;
            return 2;
        }
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type _ = _mv_116.data.rc_and;
            return 3;
        }
        case howl_owl2_RawConcept_rc_some:
        {
            return 4;
        }
        case howl_owl2_RawConcept_rc_or:
        {
            __auto_type _ = _mv_116.data.rc_or;
            return 5;
        }
        case howl_owl2_RawConcept_rc_not:
        {
            __auto_type _ = _mv_116.data.rc_not;
            return 6;
        }
        case howl_owl2_RawConcept_rc_all:
        {
            return 7;
        }
        case howl_owl2_RawConcept_rc_oneof:
        {
            __auto_type _ = _mv_116.data.rc_oneof;
            return 8;
        }
        case howl_owl2_RawConcept_rc_has_value:
        {
            return 9;
        }
        case howl_owl2_RawConcept_rc_has_self:
        {
            __auto_type _ = _mv_116.data.rc_has_self;
            return 10;
        }
        case howl_owl2_RawConcept_rc_card:
        {
            return 11;
        }
        case howl_owl2_RawConcept_rc_qcard:
        {
            return 12;
        }
        case howl_owl2_RawConcept_rc_data:
        {
            __auto_type _ = _mv_116.data.rc_data;
            return 13;
        }
        case howl_owl2_RawConcept_rc_anon:
        {
            __auto_type _ = _mv_116.data.rc_anon;
            return 14;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t howl_owl2_concept_list_cmp(slop_list_howl_owl2_RawConcept a, slop_list_howl_owl2_RawConcept b) {
    {
        __auto_type alen = ((int64_t)(((int64_t)((a).len))));
        __auto_type blen = ((int64_t)(((int64_t)((b).len))));
        __auto_type n = ((alen) < (blen) ? (alen) : (blen));
        int64_t i = 0;
        int64_t r = 0;
        while ((i < n) && (r == 0)) {
            r = howl_owl2_concept_cmp(howl_owl2_concept_at(a, i), howl_owl2_concept_at(b, i));
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

howl_owl2_RawConcept howl_owl2_concept_at(slop_list_howl_owl2_RawConcept xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_117 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_owl2_RawConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_117.has_value) {
        __auto_type v = _mv_117.value;
        return v;
    } else if (!_mv_117.has_value) {
        return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_thing });
    }
    SLOP_UNREACHABLE();
}

int64_t howl_owl2_concept_cmp(howl_owl2_RawConcept a, howl_owl2_RawConcept b) {
    {
        __auto_type ra = howl_owl2_concept_tag_rank(a);
        __auto_type rb = howl_owl2_concept_tag_rank(b);
        if (ra != rb) {
            if (ra < rb) {
                return -1;
            } else {
                return 1;
            }
        } else {
            __auto_type _mv_118 = a;
            switch (_mv_118.tag) {
                case howl_owl2_RawConcept_rc_name:
                {
                    __auto_type na = _mv_118.data.rc_name;
                    __auto_type _mv_119 = b;
                    switch (_mv_119.tag) {
                        case howl_owl2_RawConcept_rc_name:
                        {
                            __auto_type nb = _mv_119.data.rc_name;
                            return howl_canon_node_cmp(na, nb);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_owl2_RawConcept_rc_and:
                {
                    __auto_type as = _mv_118.data.rc_and;
                    __auto_type _mv_120 = b;
                    switch (_mv_120.tag) {
                        case howl_owl2_RawConcept_rc_and:
                        {
                            __auto_type bs = _mv_120.data.rc_and;
                            return howl_owl2_concept_list_cmp(as, bs);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_owl2_RawConcept_rc_some:
                {
                    __auto_type ra2 = _mv_118.data.rc_some.f0;
                    __auto_type fa = _mv_118.data.rc_some.f1;
                    __auto_type _mv_121 = b;
                    switch (_mv_121.tag) {
                        case howl_owl2_RawConcept_rc_some:
                        {
                            __auto_type rb2 = _mv_121.data.rc_some.f0;
                            __auto_type fb = _mv_121.data.rc_some.f1;
                            {
                                __auto_type rr = howl_canon_role_cmp(ra2, rb2);
                                if (rr != 0) {
                                    return rr;
                                } else {
                                    return howl_owl2_concept_cmp((*fa), (*fb));
                                }
                            }
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_owl2_RawConcept_rc_or:
                {
                    __auto_type as = _mv_118.data.rc_or;
                    __auto_type _mv_122 = b;
                    switch (_mv_122.tag) {
                        case howl_owl2_RawConcept_rc_or:
                        {
                            __auto_type bs = _mv_122.data.rc_or;
                            return howl_owl2_concept_list_cmp(as, bs);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_owl2_RawConcept_rc_not:
                {
                    __auto_type fa = _mv_118.data.rc_not;
                    __auto_type _mv_123 = b;
                    switch (_mv_123.tag) {
                        case howl_owl2_RawConcept_rc_not:
                        {
                            __auto_type fb = _mv_123.data.rc_not;
                            return howl_owl2_concept_cmp((*fa), (*fb));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_owl2_RawConcept_rc_all:
                {
                    __auto_type ra2 = _mv_118.data.rc_all.f0;
                    __auto_type fa = _mv_118.data.rc_all.f1;
                    __auto_type _mv_124 = b;
                    switch (_mv_124.tag) {
                        case howl_owl2_RawConcept_rc_all:
                        {
                            __auto_type rb2 = _mv_124.data.rc_all.f0;
                            __auto_type fb = _mv_124.data.rc_all.f1;
                            {
                                __auto_type rr = howl_canon_role_cmp(ra2, rb2);
                                if (rr != 0) {
                                    return rr;
                                } else {
                                    return howl_owl2_concept_cmp((*fa), (*fb));
                                }
                            }
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_owl2_RawConcept_rc_has_value:
                {
                    __auto_type ra2 = _mv_118.data.rc_has_value.f0;
                    __auto_type na = _mv_118.data.rc_has_value.f1;
                    __auto_type _mv_125 = b;
                    switch (_mv_125.tag) {
                        case howl_owl2_RawConcept_rc_has_value:
                        {
                            __auto_type rb2 = _mv_125.data.rc_has_value.f0;
                            __auto_type nb = _mv_125.data.rc_has_value.f1;
                            {
                                __auto_type rr = howl_canon_role_cmp(ra2, rb2);
                                if (rr != 0) {
                                    return rr;
                                } else {
                                    return howl_canon_node_cmp(na, nb);
                                }
                            }
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_owl2_RawConcept_rc_has_self:
                {
                    __auto_type ra2 = _mv_118.data.rc_has_self;
                    __auto_type _mv_126 = b;
                    switch (_mv_126.tag) {
                        case howl_owl2_RawConcept_rc_has_self:
                        {
                            __auto_type rb2 = _mv_126.data.rc_has_self;
                            return howl_canon_role_cmp(ra2, rb2);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_owl2_RawConcept_rc_oneof:
                {
                    __auto_type na = _mv_118.data.rc_oneof;
                    __auto_type _mv_127 = b;
                    switch (_mv_127.tag) {
                        case howl_owl2_RawConcept_rc_oneof:
                        {
                            __auto_type nb = _mv_127.data.rc_oneof;
                            return howl_owl2_node_list_cmp(na, nb);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_owl2_RawConcept_rc_card:
                {
                    __auto_type ka = _mv_118.data.rc_card.f0;
                    __auto_type ra2 = _mv_118.data.rc_card.f1;
                    __auto_type na = _mv_118.data.rc_card.f2;
                    __auto_type _mv_128 = b;
                    switch (_mv_128.tag) {
                        case howl_owl2_RawConcept_rc_card:
                        {
                            __auto_type kb = _mv_128.data.rc_card.f0;
                            __auto_type rb2 = _mv_128.data.rc_card.f1;
                            __auto_type nb = _mv_128.data.rc_card.f2;
                            return howl_owl2_card_cmp(ka, ra2, na, kb, rb2, nb);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_owl2_RawConcept_rc_qcard:
                {
                    __auto_type ka = _mv_118.data.rc_qcard.f0;
                    __auto_type ra2 = _mv_118.data.rc_qcard.f1;
                    __auto_type na = _mv_118.data.rc_qcard.f2;
                    __auto_type fa = _mv_118.data.rc_qcard.f3;
                    __auto_type _mv_129 = b;
                    switch (_mv_129.tag) {
                        case howl_owl2_RawConcept_rc_qcard:
                        {
                            __auto_type kb = _mv_129.data.rc_qcard.f0;
                            __auto_type rb2 = _mv_129.data.rc_qcard.f1;
                            __auto_type nb = _mv_129.data.rc_qcard.f2;
                            __auto_type fb = _mv_129.data.rc_qcard.f3;
                            {
                                __auto_type cc = howl_owl2_card_cmp(ka, ra2, na, kb, rb2, nb);
                                if (cc != 0) {
                                    return cc;
                                } else {
                                    return howl_owl2_concept_cmp((*fa), (*fb));
                                }
                            }
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

int64_t howl_owl2_card_cmp(howl_owl2_CardKind ka, howl_types_RoleId ra, int64_t na, howl_owl2_CardKind kb, howl_types_RoleId rb, int64_t nb) {
    {
        __auto_type ka2 = howl_owl2_card_rank(ka);
        __auto_type kb2 = howl_owl2_card_rank(kb);
        if (ka2 != kb2) {
            if (ka2 < kb2) {
                return -1;
            } else {
                return 1;
            }
        } else {
            {
                __auto_type rr = howl_canon_role_cmp(ra, rb);
                if (rr != 0) {
                    return rr;
                } else if (na < nb) {
                    return -1;
                } else if (na > nb) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }
}

int64_t howl_owl2_card_rank(howl_owl2_CardKind k) {
    __auto_type _mv_130 = k;
    if (_mv_130 == howl_owl2_CardKind_card_min) {
        return 0;
    } else if (_mv_130 == howl_owl2_CardKind_card_max) {
        return 1;
    } else if (_mv_130 == howl_owl2_CardKind_card_exact) {
        return 2;
    }
    SLOP_UNREACHABLE();
}

int64_t howl_owl2_node_list_cmp(slop_list_howl_types_Node a, slop_list_howl_types_Node b) {
    {
        __auto_type alen = ((int64_t)(((int64_t)((a).len))));
        __auto_type blen = ((int64_t)(((int64_t)((b).len))));
        __auto_type n = ((alen) < (blen) ? (alen) : (blen));
        int64_t i = 0;
        int64_t r = 0;
        while ((i < n) && (r == 0)) {
            __auto_type _mv_131 = ({ __auto_type _lst = a; size_t _idx = (size_t)i; slop_option_howl_types_Node _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_131.has_value) {
                __auto_type x = _mv_131.value;
                __auto_type _mv_132 = ({ __auto_type _lst = b; size_t _idx = (size_t)i; slop_option_howl_types_Node _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_132.has_value) {
                    __auto_type y = _mv_132.value;
                    r = howl_canon_node_cmp(x, y);
                } else if (!_mv_132.has_value) {
                }
            } else if (!_mv_131.has_value) {
            }
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

slop_string howl_owl2_render_role(slop_arena* arena, howl_types_RoleId r) {
    __auto_type _mv_133 = r;
    switch (_mv_133.tag) {
        case howl_types_RoleId_named_role:
        {
            __auto_type i = _mv_133.data.named_role;
            return i.value;
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type i = _mv_133.data.inverse_role;
            return howl_owl2_wrap(arena, SLOP_STR("ObjectInverseOf"), i.value);
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_133.data.fresh_role;
            return SLOP_STR("_:fresh-role");
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_owl2_render_node(howl_types_Node n) {
    __auto_type _mv_134 = n;
    switch (_mv_134.tag) {
        case howl_types_Node_class_node:
        {
            __auto_type i = _mv_134.data.class_node;
            return i.value;
        }
        case howl_types_Node_individual_node:
        {
            __auto_type i = _mv_134.data.individual_node;
            return i.value;
        }
        case howl_types_Node_fresh_node:
        {
            __auto_type _ = _mv_134.data.fresh_node;
            return SLOP_STR("_:fresh-node");
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_owl2_render_card_kind(howl_owl2_CardKind k) {
    __auto_type _mv_135 = k;
    if (_mv_135 == howl_owl2_CardKind_card_min) {
        return SLOP_STR("ObjectMinCardinality");
    } else if (_mv_135 == howl_owl2_CardKind_card_max) {
        return SLOP_STR("ObjectMaxCardinality");
    } else if (_mv_135 == howl_owl2_CardKind_card_exact) {
        return SLOP_STR("ObjectExactCardinality");
    }
    SLOP_UNREACHABLE();
}

slop_string howl_owl2_render_concept_list(slop_arena* arena, slop_list_howl_owl2_RawConcept cs) {
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
                out = string_concat(arena, out, howl_owl2_render_concept(arena, c));
                first = 0;
            }
        }
        return out;
    }
}

slop_string howl_owl2_render_node_list(slop_arena* arena, slop_list_howl_types_Node ns) {
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
                out = string_concat(arena, out, howl_owl2_render_node(n));
                first = 0;
            }
        }
        return out;
    }
}

slop_string howl_owl2_render_role_list(slop_arena* arena, slop_list_howl_types_RoleId rs) {
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
                out = string_concat(arena, out, howl_owl2_render_role(arena, r));
                first = 0;
            }
        }
        return out;
    }
}

slop_string howl_owl2_wrap(slop_arena* arena, slop_string head, slop_string body) {
    return string_concat(arena, head, string_concat(arena, SLOP_STR("("), string_concat(arena, body, SLOP_STR(")"))));
}

slop_string howl_owl2_join2(slop_arena* arena, slop_string a, slop_string b) {
    return string_concat(arena, a, string_concat(arena, SLOP_STR(" "), b));
}

slop_string howl_owl2_render_concept(slop_arena* arena, howl_owl2_RawConcept c) {
    __auto_type _mv_136 = c;
    switch (_mv_136.tag) {
        case howl_owl2_RawConcept_rc_thing:
        {
            return SLOP_STR("owl:Thing");
        }
        case howl_owl2_RawConcept_rc_nothing:
        {
            return SLOP_STR("owl:Nothing");
        }
        case howl_owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_136.data.rc_name;
            return howl_owl2_render_node(n);
        }
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_136.data.rc_and;
            return howl_owl2_wrap(arena, SLOP_STR("ObjectIntersectionOf"), howl_owl2_render_concept_list(arena, cs));
        }
        case howl_owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_136.data.rc_or;
            return howl_owl2_wrap(arena, SLOP_STR("ObjectUnionOf"), howl_owl2_render_concept_list(arena, cs));
        }
        case howl_owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_136.data.rc_not;
            return howl_owl2_wrap(arena, SLOP_STR("ObjectComplementOf"), howl_owl2_render_concept(arena, (*f)));
        }
        case howl_owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_136.data.rc_some.f0;
            __auto_type f = _mv_136.data.rc_some.f1;
            return howl_owl2_wrap(arena, SLOP_STR("ObjectSomeValuesFrom"), howl_owl2_join2(arena, howl_owl2_render_role(arena, r), howl_owl2_render_concept(arena, (*f))));
        }
        case howl_owl2_RawConcept_rc_all:
        {
            __auto_type r = _mv_136.data.rc_all.f0;
            __auto_type f = _mv_136.data.rc_all.f1;
            return howl_owl2_wrap(arena, SLOP_STR("ObjectAllValuesFrom"), howl_owl2_join2(arena, howl_owl2_render_role(arena, r), howl_owl2_render_concept(arena, (*f))));
        }
        case howl_owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_136.data.rc_oneof;
            return howl_owl2_wrap(arena, SLOP_STR("ObjectOneOf"), howl_owl2_render_node_list(arena, ns));
        }
        case howl_owl2_RawConcept_rc_has_value:
        {
            __auto_type r = _mv_136.data.rc_has_value.f0;
            __auto_type n = _mv_136.data.rc_has_value.f1;
            return howl_owl2_wrap(arena, SLOP_STR("ObjectHasValue"), howl_owl2_join2(arena, howl_owl2_render_role(arena, r), howl_owl2_render_node(n)));
        }
        case howl_owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_136.data.rc_has_self;
            return howl_owl2_wrap(arena, SLOP_STR("ObjectHasSelf"), howl_owl2_render_role(arena, r));
        }
        case howl_owl2_RawConcept_rc_card:
        {
            __auto_type k = _mv_136.data.rc_card.f0;
            __auto_type r = _mv_136.data.rc_card.f1;
            __auto_type n = _mv_136.data.rc_card.f2;
            return howl_owl2_wrap(arena, howl_owl2_render_card_kind(k), howl_owl2_join2(arena, int_to_string(arena, n), howl_owl2_render_role(arena, r)));
        }
        case howl_owl2_RawConcept_rc_qcard:
        {
            __auto_type k = _mv_136.data.rc_qcard.f0;
            __auto_type r = _mv_136.data.rc_qcard.f1;
            __auto_type n = _mv_136.data.rc_qcard.f2;
            __auto_type f = _mv_136.data.rc_qcard.f3;
            return howl_owl2_wrap(arena, howl_owl2_render_card_kind(k), howl_owl2_join2(arena, int_to_string(arena, n), howl_owl2_join2(arena, howl_owl2_render_role(arena, r), howl_owl2_render_concept(arena, (*f)))));
        }
        case howl_owl2_RawConcept_rc_data:
        {
            __auto_type ref = _mv_136.data.rc_data;
            return howl_owl2_wrap(arena, SLOP_STR("DataRange"), howl_owl2_render_input_ref(ref));
        }
        case howl_owl2_RawConcept_rc_anon:
        {
            __auto_type ref = _mv_136.data.rc_anon;
            return howl_owl2_wrap(arena, SLOP_STR("AnonymousClass"), howl_owl2_render_input_ref(ref));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_owl2_render_input_ref(howl_types_InputRef r) {
    __auto_type _mv_137 = r;
    switch (_mv_137.tag) {
        case howl_types_InputRef_owl_axiom:
        {
            __auto_type a = _mv_137.data.owl_axiom;
            return a.text;
        }
        case howl_types_InputRef_rdf_fragment:
        {
            __auto_type s = _mv_137.data.rdf_fragment;
            return s;
        }
        case howl_types_InputRef_synthetic:
        {
            __auto_type s = _mv_137.data.synthetic;
            return s;
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_owl2_render_entity_kind(howl_types_EntityKind k) {
    __auto_type _mv_138 = k;
    if (_mv_138 == howl_types_EntityKind_entity_class) {
        return SLOP_STR("Class");
    } else if (_mv_138 == howl_types_EntityKind_entity_object_property) {
        return SLOP_STR("ObjectProperty");
    } else if (_mv_138 == howl_types_EntityKind_entity_data_property) {
        return SLOP_STR("DataProperty");
    } else if (_mv_138 == howl_types_EntityKind_entity_annotation_property) {
        return SLOP_STR("AnnotationProperty");
    } else if (_mv_138 == howl_types_EntityKind_entity_individual) {
        return SLOP_STR("NamedIndividual");
    } else if (_mv_138 == howl_types_EntityKind_entity_datatype) {
        return SLOP_STR("Datatype");
    }
    SLOP_UNREACHABLE();
}

slop_string howl_owl2_render_omission(slop_arena* arena, howl_types_Omission o) {
    __auto_type _mv_139 = o;
    switch (_mv_139.tag) {
        case howl_types_Omission_out_of_profile:
        {
            __auto_type ref = _mv_139.data.out_of_profile;
            return howl_owl2_render_input_ref(ref);
        }
        case howl_types_Omission_unresolved_import:
        {
            __auto_type i = _mv_139.data.unresolved_import;
            return howl_owl2_wrap(arena, SLOP_STR("UnresolvedImport"), i.value);
        }
        case howl_types_Omission_missing_declaration:
        {
            __auto_type md = _mv_139.data.missing_declaration;
            return howl_owl2_wrap(arena, SLOP_STR("MissingDeclaration"), howl_owl2_wrap(arena, howl_owl2_render_entity_kind(md.kind), md.entity.value));
        }
        case howl_types_Omission_undeclared_property:
        {
            __auto_type u = _mv_139.data.undeclared_property;
            return howl_owl2_wrap(arena, SLOP_STR("UndeclaredProperty"), u.property.value);
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_owl2_render_axiom(slop_arena* arena, howl_owl2_RawAxiom ax) {
    __auto_type _mv_140 = ax;
    switch (_mv_140.tag) {
        case howl_owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_140.data.ra_sub_class_of.f0;
            __auto_type r = _mv_140.data.ra_sub_class_of.f1;
            return howl_owl2_wrap(arena, SLOP_STR("SubClassOf"), howl_owl2_join2(arena, howl_owl2_render_concept(arena, (*l)), howl_owl2_render_concept(arena, (*r))));
        }
        case howl_owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type cs = _mv_140.data.ra_equivalent_classes;
            return howl_owl2_wrap(arena, SLOP_STR("EquivalentClasses"), howl_owl2_render_concept_list(arena, cs));
        }
        case howl_owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_140.data.ra_disjoint_classes;
            return howl_owl2_wrap(arena, SLOP_STR("DisjointClasses"), howl_owl2_render_concept_list(arena, cs));
        }
        case howl_owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type a = _mv_140.data.ra_sub_object_property.f0;
            __auto_type b = _mv_140.data.ra_sub_object_property.f1;
            return howl_owl2_wrap(arena, SLOP_STR("SubObjectPropertyOf"), howl_owl2_join2(arena, howl_owl2_render_role(arena, a), howl_owl2_render_role(arena, b)));
        }
        case howl_owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_140.data.ra_property_chain;
            return howl_owl2_wrap(arena, SLOP_STR("SubObjectPropertyOf"), howl_owl2_join2(arena, howl_owl2_wrap(arena, SLOP_STR("ObjectPropertyChain"), howl_owl2_render_role_list(arena, ch.steps)), howl_owl2_render_role(arena, ch.super)));
        }
        case howl_owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type rs = _mv_140.data.ra_equivalent_properties;
            return howl_owl2_wrap(arena, SLOP_STR("EquivalentObjectProperties"), howl_owl2_render_role_list(arena, rs));
        }
        case howl_owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type r = _mv_140.data.ra_transitive_property;
            return howl_owl2_wrap(arena, SLOP_STR("TransitiveObjectProperty"), howl_owl2_render_role(arena, r));
        }
        case howl_owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_140.data.ra_object_property_domain.f0;
            __auto_type c = _mv_140.data.ra_object_property_domain.f1;
            return howl_owl2_wrap(arena, SLOP_STR("ObjectPropertyDomain"), howl_owl2_join2(arena, howl_owl2_render_role(arena, r), howl_owl2_render_concept(arena, (*c))));
        }
        case howl_owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type r = _mv_140.data.ra_object_property_range.f0;
            __auto_type c = _mv_140.data.ra_object_property_range.f1;
            return howl_owl2_wrap(arena, SLOP_STR("ObjectPropertyRange"), howl_owl2_join2(arena, howl_owl2_render_role(arena, r), howl_owl2_render_concept(arena, (*c))));
        }
        case howl_owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_140.data.ra_class_assertion;
            return howl_owl2_wrap(arena, SLOP_STR("ClassAssertion"), howl_owl2_join2(arena, howl_owl2_render_concept(arena, (*ca.concept)), howl_owl2_render_node(ca.subject)));
        }
        case howl_owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type e = _mv_140.data.ra_object_property_assertion;
            return howl_owl2_wrap(arena, SLOP_STR("ObjectPropertyAssertion"), howl_owl2_join2(arena, howl_owl2_render_role(arena, e.role), howl_owl2_join2(arena, howl_owl2_render_node(e.from), howl_owl2_render_node(e.to))));
        }
        case howl_owl2_RawAxiom_ra_declaration:
        {
            __auto_type d = _mv_140.data.ra_declaration;
            return howl_owl2_wrap(arena, SLOP_STR("Declaration"), d.entity.value);
        }
        case howl_owl2_RawAxiom_ra_annotation:
        {
            return SLOP_STR("Annotation()");
        }
        case howl_owl2_RawAxiom_ra_inert_data:
        {
            return SLOP_STR("InertDataAxiom()");
        }
        case howl_owl2_RawAxiom_ra_inverse_properties:
        {
            __auto_type a = _mv_140.data.ra_inverse_properties.f0;
            __auto_type b = _mv_140.data.ra_inverse_properties.f1;
            return howl_owl2_wrap(arena, SLOP_STR("InverseObjectProperties"), howl_owl2_join2(arena, howl_owl2_render_role(arena, a), howl_owl2_render_role(arena, b)));
        }
        case howl_owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type c = _mv_140.data.ra_property_characteristic.f0;
            __auto_type r = _mv_140.data.ra_property_characteristic.f1;
            return howl_owl2_wrap(arena, howl_owl2_render_characteristic(c), howl_owl2_render_role(arena, r));
        }
        case howl_owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type rs = _mv_140.data.ra_disjoint_properties;
            return howl_owl2_wrap(arena, SLOP_STR("DisjointObjectProperties"), howl_owl2_render_role_list(arena, rs));
        }
        case howl_owl2_RawAxiom_ra_same_individual:
        {
            __auto_type ns = _mv_140.data.ra_same_individual;
            return howl_owl2_wrap(arena, SLOP_STR("SameIndividual"), howl_owl2_render_node_list(arena, ns));
        }
        case howl_owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type ns = _mv_140.data.ra_different_individuals;
            return howl_owl2_wrap(arena, SLOP_STR("DifferentIndividuals"), howl_owl2_render_node_list(arena, ns));
        }
        case howl_owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type e = _mv_140.data.ra_negative_assertion;
            return howl_owl2_wrap(arena, SLOP_STR("NegativeObjectPropertyAssertion"), howl_owl2_join2(arena, howl_owl2_render_role(arena, e.role), howl_owl2_join2(arena, howl_owl2_render_node(e.from), howl_owl2_render_node(e.to))));
        }
        case howl_owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type du = _mv_140.data.ra_disjoint_union;
            return howl_owl2_wrap(arena, SLOP_STR("DisjointUnion"), howl_owl2_join2(arena, du.class.value, howl_owl2_render_concept_list(arena, du.members)));
        }
        case howl_owl2_RawAxiom_ra_has_key:
        {
            __auto_type ref = _mv_140.data.ra_has_key;
            return howl_owl2_wrap(arena, SLOP_STR("HasKey"), howl_owl2_render_input_ref(ref));
        }
        case howl_owl2_RawAxiom_ra_data_axiom:
        {
            __auto_type ref = _mv_140.data.ra_data_axiom;
            return howl_owl2_wrap(arena, SLOP_STR("DataAxiom"), howl_owl2_render_input_ref(ref));
        }
        case howl_owl2_RawAxiom_ra_builtin_role:
        {
            __auto_type ref = _mv_140.data.ra_builtin_role;
            return howl_owl2_wrap(arena, SLOP_STR("BuiltinRole"), howl_owl2_render_input_ref(ref));
        }
        case howl_owl2_RawAxiom_ra_anonymous_individual:
        {
            __auto_type ref = _mv_140.data.ra_anonymous_individual;
            return howl_owl2_wrap(arena, SLOP_STR("AnonymousIndividual"), howl_owl2_render_input_ref(ref));
        }
        case howl_owl2_RawAxiom_ra_reserved_vocabulary:
        {
            __auto_type ref = _mv_140.data.ra_reserved_vocabulary;
            return howl_owl2_wrap(arena, SLOP_STR("ReservedVocabulary"), howl_owl2_render_input_ref(ref));
        }
        case howl_owl2_RawAxiom_ra_swrl_rule:
        {
            __auto_type ref = _mv_140.data.ra_swrl_rule;
            return howl_owl2_wrap(arena, SLOP_STR("SWRLRule"), howl_owl2_render_input_ref(ref));
        }
        case howl_owl2_RawAxiom_ra_unrecognized:
        {
            __auto_type ref = _mv_140.data.ra_unrecognized;
            return howl_owl2_wrap(arena, SLOP_STR("Unrecognized"), howl_owl2_render_input_ref(ref));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_owl2_render_characteristic(howl_owl2_PropCharacteristic c) {
    __auto_type _mv_141 = c;
    if (_mv_141 == howl_owl2_PropCharacteristic_prop_functional) {
        return SLOP_STR("FunctionalObjectProperty");
    } else if (_mv_141 == howl_owl2_PropCharacteristic_prop_inverse_functional) {
        return SLOP_STR("InverseFunctionalObjectProperty");
    } else if (_mv_141 == howl_owl2_PropCharacteristic_prop_symmetric) {
        return SLOP_STR("SymmetricObjectProperty");
    } else if (_mv_141 == howl_owl2_PropCharacteristic_prop_asymmetric) {
        return SLOP_STR("AsymmetricObjectProperty");
    } else if (_mv_141 == howl_owl2_PropCharacteristic_prop_reflexive) {
        return SLOP_STR("ReflexiveObjectProperty");
    } else if (_mv_141 == howl_owl2_PropCharacteristic_prop_irreflexive) {
        return SLOP_STR("IrreflexiveObjectProperty");
    }
    SLOP_UNREACHABLE();
}

howl_owl2_RawConcept howl_owl2_copy_concept(slop_arena* arena, howl_owl2_RawConcept c) {
    __auto_type _mv_142 = c;
    switch (_mv_142.tag) {
        case howl_owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_142.data.rc_name;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_name, .data.rc_name = howl_types_copy_node(arena, n) });
        }
        case howl_owl2_RawConcept_rc_thing:
        {
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_thing });
        }
        case howl_owl2_RawConcept_rc_nothing:
        {
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_nothing });
        }
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_142.data.rc_and;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_and, .data.rc_and = howl_owl2_copy_concepts(arena, cs) });
        }
        case howl_owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_142.data.rc_some.f0;
            __auto_type f = _mv_142.data.rc_some.f1;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_some, .data.rc_some = { .f0 = howl_types_copy_role(arena, r), .f1 = howl_owl2_copy_boxed(arena, f) } });
        }
        case howl_owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_142.data.rc_or;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_or, .data.rc_or = howl_owl2_copy_concepts(arena, cs) });
        }
        case howl_owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_142.data.rc_not;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_not, .data.rc_not = howl_owl2_copy_boxed(arena, f) });
        }
        case howl_owl2_RawConcept_rc_all:
        {
            __auto_type r = _mv_142.data.rc_all.f0;
            __auto_type f = _mv_142.data.rc_all.f1;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_all, .data.rc_all = { .f0 = howl_types_copy_role(arena, r), .f1 = howl_owl2_copy_boxed(arena, f) } });
        }
        case howl_owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_142.data.rc_oneof;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_oneof, .data.rc_oneof = howl_owl2_copy_nodes(arena, ns) });
        }
        case howl_owl2_RawConcept_rc_has_value:
        {
            __auto_type r = _mv_142.data.rc_has_value.f0;
            __auto_type n = _mv_142.data.rc_has_value.f1;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_has_value, .data.rc_has_value = { .f0 = howl_types_copy_role(arena, r), .f1 = howl_types_copy_node(arena, n) } });
        }
        case howl_owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_142.data.rc_has_self;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_has_self, .data.rc_has_self = howl_types_copy_role(arena, r) });
        }
        case howl_owl2_RawConcept_rc_card:
        {
            __auto_type k = _mv_142.data.rc_card.f0;
            __auto_type r = _mv_142.data.rc_card.f1;
            __auto_type n = _mv_142.data.rc_card.f2;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_card, .data.rc_card = { .f0 = k, .f1 = howl_types_copy_role(arena, r), .f2 = n } });
        }
        case howl_owl2_RawConcept_rc_qcard:
        {
            __auto_type k = _mv_142.data.rc_qcard.f0;
            __auto_type r = _mv_142.data.rc_qcard.f1;
            __auto_type n = _mv_142.data.rc_qcard.f2;
            __auto_type f = _mv_142.data.rc_qcard.f3;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_qcard, .data.rc_qcard = { .f0 = k, .f1 = howl_types_copy_role(arena, r), .f2 = n, .f3 = howl_owl2_copy_boxed(arena, f) } });
        }
        case howl_owl2_RawConcept_rc_data:
        {
            __auto_type ref = _mv_142.data.rc_data;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_data, .data.rc_data = howl_types_copy_input_ref(arena, ref) });
        }
        case howl_owl2_RawConcept_rc_anon:
        {
            __auto_type ref = _mv_142.data.rc_anon;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_anon, .data.rc_anon = howl_types_copy_input_ref(arena, ref) });
        }
    }
    SLOP_UNREACHABLE();
}

howl_owl2_RawConcept* howl_owl2_copy_boxed(slop_arena* arena, howl_owl2_RawConcept* p) {
    {
        __auto_type q = ((howl_owl2_RawConcept*)(({ __auto_type _alloc = (howl_owl2_RawConcept*)slop_arena_alloc(arena, sizeof(howl_owl2_RawConcept)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*q) = howl_owl2_copy_concept(arena, (*p));
        return q;
    }
}

slop_list_howl_owl2_RawConcept howl_owl2_copy_concepts(slop_arena* arena, slop_list_howl_owl2_RawConcept cs) {
    {
        __auto_type out = ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_owl2_copy_concept(arena, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_types_Node howl_owl2_copy_nodes(slop_arena* arena, slop_list_howl_types_Node ns) {
    {
        __auto_type out = ((slop_list_howl_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_types_copy_node(arena, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_types_RoleId howl_owl2_copy_roles(slop_arena* arena, slop_list_howl_types_RoleId rs) {
    {
        __auto_type out = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_types_copy_role(arena, r)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_owl2_RawAxiom howl_owl2_copy_raw_axiom(slop_arena* arena, howl_owl2_RawAxiom ax) {
    __auto_type _mv_143 = ax;
    switch (_mv_143.tag) {
        case howl_owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_143.data.ra_sub_class_of.f0;
            __auto_type r = _mv_143.data.ra_sub_class_of.f1;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_sub_class_of, .data.ra_sub_class_of = { .f0 = howl_owl2_copy_boxed(arena, l), .f1 = howl_owl2_copy_boxed(arena, r) } });
        }
        case howl_owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type cs = _mv_143.data.ra_equivalent_classes;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_equivalent_classes, .data.ra_equivalent_classes = howl_owl2_copy_concepts(arena, cs) });
        }
        case howl_owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_143.data.ra_disjoint_classes;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_disjoint_classes, .data.ra_disjoint_classes = howl_owl2_copy_concepts(arena, cs) });
        }
        case howl_owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type a = _mv_143.data.ra_sub_object_property.f0;
            __auto_type b = _mv_143.data.ra_sub_object_property.f1;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_sub_object_property, .data.ra_sub_object_property = { .f0 = howl_types_copy_role(arena, a), .f1 = howl_types_copy_role(arena, b) } });
        }
        case howl_owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_143.data.ra_property_chain;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_property_chain, .data.ra_property_chain = ((howl_owl2_RawChain){.steps = howl_owl2_copy_roles(arena, ch.steps), .super = howl_types_copy_role(arena, ch.super)}) });
        }
        case howl_owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type rs = _mv_143.data.ra_equivalent_properties;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_equivalent_properties, .data.ra_equivalent_properties = howl_owl2_copy_roles(arena, rs) });
        }
        case howl_owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type r = _mv_143.data.ra_transitive_property;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_transitive_property, .data.ra_transitive_property = howl_types_copy_role(arena, r) });
        }
        case howl_owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_143.data.ra_object_property_domain.f0;
            __auto_type c = _mv_143.data.ra_object_property_domain.f1;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_object_property_domain, .data.ra_object_property_domain = { .f0 = howl_types_copy_role(arena, r), .f1 = howl_owl2_copy_boxed(arena, c) } });
        }
        case howl_owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type r = _mv_143.data.ra_object_property_range.f0;
            __auto_type c = _mv_143.data.ra_object_property_range.f1;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_object_property_range, .data.ra_object_property_range = { .f0 = howl_types_copy_role(arena, r), .f1 = howl_owl2_copy_boxed(arena, c) } });
        }
        case howl_owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_143.data.ra_class_assertion;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_class_assertion, .data.ra_class_assertion = ((howl_owl2_RawClassAssertion){.concept = howl_owl2_copy_boxed(arena, ca.concept), .subject = howl_types_copy_node(arena, ca.subject)}) });
        }
        case howl_owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type e = _mv_143.data.ra_object_property_assertion;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_object_property_assertion, .data.ra_object_property_assertion = ((howl_owl2_RawEdge){.role = howl_types_copy_role(arena, e.role), .from = howl_types_copy_node(arena, e.from), .to = howl_types_copy_node(arena, e.to)}) });
        }
        case howl_owl2_RawAxiom_ra_declaration:
        {
            __auto_type d = _mv_143.data.ra_declaration;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_declaration, .data.ra_declaration = ((howl_owl2_RawDeclaration){.kind = d.kind, .entity = howl_types_copy_iri(arena, d.entity)}) });
        }
        case howl_owl2_RawAxiom_ra_annotation:
        {
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_annotation });
        }
        case howl_owl2_RawAxiom_ra_inert_data:
        {
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_inert_data });
        }
        case howl_owl2_RawAxiom_ra_inverse_properties:
        {
            __auto_type a = _mv_143.data.ra_inverse_properties.f0;
            __auto_type b = _mv_143.data.ra_inverse_properties.f1;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_inverse_properties, .data.ra_inverse_properties = { .f0 = howl_types_copy_role(arena, a), .f1 = howl_types_copy_role(arena, b) } });
        }
        case howl_owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type c = _mv_143.data.ra_property_characteristic.f0;
            __auto_type r = _mv_143.data.ra_property_characteristic.f1;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_property_characteristic, .data.ra_property_characteristic = { .f0 = c, .f1 = howl_types_copy_role(arena, r) } });
        }
        case howl_owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type rs = _mv_143.data.ra_disjoint_properties;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_disjoint_properties, .data.ra_disjoint_properties = howl_owl2_copy_roles(arena, rs) });
        }
        case howl_owl2_RawAxiom_ra_same_individual:
        {
            __auto_type ns = _mv_143.data.ra_same_individual;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_same_individual, .data.ra_same_individual = howl_owl2_copy_nodes(arena, ns) });
        }
        case howl_owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type ns = _mv_143.data.ra_different_individuals;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_different_individuals, .data.ra_different_individuals = howl_owl2_copy_nodes(arena, ns) });
        }
        case howl_owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type e = _mv_143.data.ra_negative_assertion;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_negative_assertion, .data.ra_negative_assertion = ((howl_owl2_RawEdge){.role = howl_types_copy_role(arena, e.role), .from = howl_types_copy_node(arena, e.from), .to = howl_types_copy_node(arena, e.to)}) });
        }
        case howl_owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type du = _mv_143.data.ra_disjoint_union;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_disjoint_union, .data.ra_disjoint_union = ((howl_owl2_RawDisjointUnion){.class = howl_types_copy_iri(arena, du.class), .members = howl_owl2_copy_concepts(arena, du.members)}) });
        }
        case howl_owl2_RawAxiom_ra_has_key:
        {
            __auto_type ref = _mv_143.data.ra_has_key;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_has_key, .data.ra_has_key = howl_types_copy_input_ref(arena, ref) });
        }
        case howl_owl2_RawAxiom_ra_data_axiom:
        {
            __auto_type ref = _mv_143.data.ra_data_axiom;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = howl_types_copy_input_ref(arena, ref) });
        }
        case howl_owl2_RawAxiom_ra_builtin_role:
        {
            __auto_type ref = _mv_143.data.ra_builtin_role;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_builtin_role, .data.ra_builtin_role = howl_types_copy_input_ref(arena, ref) });
        }
        case howl_owl2_RawAxiom_ra_anonymous_individual:
        {
            __auto_type ref = _mv_143.data.ra_anonymous_individual;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = howl_types_copy_input_ref(arena, ref) });
        }
        case howl_owl2_RawAxiom_ra_reserved_vocabulary:
        {
            __auto_type ref = _mv_143.data.ra_reserved_vocabulary;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = howl_types_copy_input_ref(arena, ref) });
        }
        case howl_owl2_RawAxiom_ra_swrl_rule:
        {
            __auto_type ref = _mv_143.data.ra_swrl_rule;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_swrl_rule, .data.ra_swrl_rule = howl_types_copy_input_ref(arena, ref) });
        }
        case howl_owl2_RawAxiom_ra_unrecognized:
        {
            __auto_type ref = _mv_143.data.ra_unrecognized;
            return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = howl_types_copy_input_ref(arena, ref) });
        }
    }
    SLOP_UNREACHABLE();
}

howl_owl2_RawAxiom howl_owl2_raw_axiom_at(slop_list_howl_owl2_RawAxiom xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_144 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_owl2_RawAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_144.has_value) {
        __auto_type v = _mv_144.value;
        return v;
    } else if (!_mv_144.has_value) {
        return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_annotation });
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_owl2_RawAxiom howl_owl2_copy_axioms(slop_arena* arena, slop_list_howl_owl2_RawAxiom xs) {
    slop_list_howl_owl2_RawAxiom _retval = {0};
    {
        __auto_type n = ((int64_t)(((int64_t)((xs).len))));
        __auto_type out = ((slop_list_howl_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < n) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_owl2_copy_raw_axiom(arena, howl_owl2_raw_axiom_at(xs, i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            i = (i + 1);
        }
        _retval = out;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) == ((int64_t)((xs).len)))), "(== (list-len $result) (list-len xs))");
    return _retval;
}

howl_owl2_Signature howl_owl2_copy_signature(slop_arena* arena, howl_owl2_Signature sig) {
    {
        __auto_type out = howl_owl2_make_signature(arena);
        {
            slop_map* _coll = (slop_map*)sig.classes;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    slop_rdf_rdf_IRI i = *(slop_rdf_rdf_IRI*)slop_map_key_at(_coll, _i);
                    (void)(({ slop_rdf_rdf_IRI _key_145 = (howl_types_copy_iri(arena, i)); slop_map_put(NULL, out.classes, &_key_145, NULL, 0); }));
                }
            }
        }
        {
            slop_map* _coll = (slop_map*)sig.obj_props;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    slop_rdf_rdf_IRI i = *(slop_rdf_rdf_IRI*)slop_map_key_at(_coll, _i);
                    (void)(({ slop_rdf_rdf_IRI _key_146 = (howl_types_copy_iri(arena, i)); slop_map_put(NULL, out.obj_props, &_key_146, NULL, 0); }));
                }
            }
        }
        {
            slop_map* _coll = (slop_map*)sig.data_props;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    slop_rdf_rdf_IRI i = *(slop_rdf_rdf_IRI*)slop_map_key_at(_coll, _i);
                    (void)(({ slop_rdf_rdf_IRI _key_147 = (howl_types_copy_iri(arena, i)); slop_map_put(NULL, out.data_props, &_key_147, NULL, 0); }));
                }
            }
        }
        {
            slop_map* _coll = (slop_map*)sig.annot_props;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    slop_rdf_rdf_IRI i = *(slop_rdf_rdf_IRI*)slop_map_key_at(_coll, _i);
                    (void)(({ slop_rdf_rdf_IRI _key_148 = (howl_types_copy_iri(arena, i)); slop_map_put(NULL, out.annot_props, &_key_148, NULL, 0); }));
                }
            }
        }
        {
            slop_map* _coll = (slop_map*)sig.individuals;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    slop_rdf_rdf_IRI i = *(slop_rdf_rdf_IRI*)slop_map_key_at(_coll, _i);
                    (void)(({ slop_rdf_rdf_IRI _key_149 = (howl_types_copy_iri(arena, i)); slop_map_put(NULL, out.individuals, &_key_149, NULL, 0); }));
                }
            }
        }
        {
            slop_map* _coll = (slop_map*)sig.datatypes;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    slop_rdf_rdf_IRI i = *(slop_rdf_rdf_IRI*)slop_map_key_at(_coll, _i);
                    (void)(({ slop_rdf_rdf_IRI _key_150 = (howl_types_copy_iri(arena, i)); slop_map_put(NULL, out.datatypes, &_key_150, NULL, 0); }));
                }
            }
        }
        return out;
    }
}

slop_list_howl_owl2_RawConcept howl_owl2_sort_concepts(slop_arena* arena, slop_list_howl_owl2_RawConcept xs) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ howl_owl2__lambda_151_env_t* howl_owl2__lambda_151_env = (howl_owl2__lambda_151_env_t*)slop_arena_alloc(arena, sizeof(howl_owl2__lambda_151_env_t)); *howl_owl2__lambda_151_env = (howl_owl2__lambda_151_env_t){ .xs = xs }; (slop_closure_t){ (void*)howl_owl2__lambda_151, (void*)howl_owl2__lambda_151_env }; }));
        __auto_type out = ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_owl2_concept_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

