#include "../runtime/slop_runtime.h"
#include "slop_aligninput.h"

int64_t howl_aligninput_int_at(slop_list_int xs, int64_t i);
uint8_t howl_aligninput_bool_at(slop_list_u8 xs, int64_t i);
slop_string howl_aligninput_ref_key(slop_arena* arena, howl_types_AxiomRef r);
uint8_t howl_aligninput_concept_usable(howl_owl2_RawConcept c);
uint8_t howl_aligninput_concepts_usable(slop_list_howl_owl2_RawConcept cs);
howl_owl2_RawConcept howl_aligninput_canonical_concept(slop_arena* arena, howl_owl2_RawConcept c);
slop_list_howl_owl2_RawConcept howl_aligninput_append_operands(slop_arena* arena, slop_list_howl_owl2_RawConcept cs, uint8_t flatten, uint8_t conjunction);
howl_types_RoleId howl_aligninput_role_at(slop_list_howl_types_RoleId rs, int64_t i);
slop_list_howl_types_RoleId howl_aligninput_sort_roles(slop_arena* arena, slop_list_howl_types_RoleId rs);
slop_list_howl_owl2_RawConcept howl_aligninput_canonical_concepts(slop_arena* arena, slop_list_howl_owl2_RawConcept cs, uint8_t flatten, uint8_t conjunction);
slop_option_howl_owl2_RawAxiom howl_aligninput_canonical_mapping_axiom(slop_arena* arena, howl_owl2_RawAxiom ax);
uint8_t howl_aligninput_ascii_letter(int64_t c);
uint8_t howl_aligninput_source_iri_valid(slop_string s);
uint8_t howl_aligninput_metadata_problem(slop_list_slop_rdf_rdf_IRI sources, slop_list_u8 mapping_docs, int64_t documents);
slop_result_howl_aligninput_AlignmentBase_howl_types_Fault howl_aligninput_alignment_base(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports, slop_list_slop_rdf_rdf_IRI sources, slop_list_u8 mapping_docs);
howl_aligninput_AlignmentBase howl_aligninput_inventory(slop_arena* arena, howl_decode_Stage0 stage, howl_decode_Stage1 decoded, slop_list_slop_rdf_rdf_IRI sources, slop_list_u8 mapping_docs);
slop_map* howl_aligninput_live_negative(slop_arena* arena, slop_list_howl_termstore_IdTriple triples, slop_map* anchors, slop_map* removed, slop_map* roots);
slop_map* howl_aligninput_reachable(slop_arena* arena, slop_list_howl_termstore_IdTriple triples, slop_list_u8 scaffolds, slop_map* anchors, slop_map* removed, slop_map* negative_live, slop_list_u8 negative_parts);
slop_result_howl_normalize_Decoded_howl_types_Fault howl_aligninput_subset_decoded(slop_arena* arena, howl_aligninput_AlignmentBase base, slop_list_int removed);
slop_result_howl_normalize_Decoded_howl_types_Fault howl_aligninput_subset_with(slop_arena* arena, howl_aligninput_AlignmentBase base, slop_map* gone);

typedef struct { slop_list_howl_types_RoleId rs; } howl_aligninput__lambda_1644_env_t;

static int64_t howl_aligninput__lambda_1644(howl_aligninput__lambda_1644_env_t* _env, int64_t i, int64_t j) { return howl_canon_role_cmp(howl_aligninput_role_at(_env->rs, i), howl_aligninput_role_at(_env->rs, j)); }

int64_t howl_aligninput_int_at(slop_list_int xs, int64_t i) {
    __auto_type _mv_1638 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1638.has_value) {
        __auto_type n = _mv_1638.value;
        return n;
    } else if (!_mv_1638.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_aligninput_bool_at(slop_list_u8 xs, int64_t i) {
    __auto_type _mv_1639 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1639.has_value) {
        __auto_type b = _mv_1639.value;
        return b;
    } else if (!_mv_1639.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string howl_aligninput_ref_key(slop_arena* arena, howl_types_AxiomRef r) {
    return string_concat(arena, ({ __auto_type _mv = r.source; _mv.has_value ? ({ __auto_type s = _mv.value; s.value; }) : (SLOP_STR("")); }), string_concat(arena, SLOP_STR("\n"), r.text));
}

uint8_t howl_aligninput_concept_usable(howl_owl2_RawConcept c) {
    __auto_type _mv_1640 = c;
    switch (_mv_1640.tag) {
        case howl_owl2_RawConcept_rc_data:
        {
            __auto_type _ = _mv_1640.data.rc_data;
            return 0;
        }
        case howl_owl2_RawConcept_rc_anon:
        {
            __auto_type _ = _mv_1640.data.rc_anon;
            return 0;
        }
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_1640.data.rc_and;
            return howl_aligninput_concepts_usable(cs);
        }
        case howl_owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_1640.data.rc_or;
            return howl_aligninput_concepts_usable(cs);
        }
        case howl_owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_1640.data.rc_not;
            return howl_aligninput_concept_usable((*f));
        }
        case howl_owl2_RawConcept_rc_some:
        {
            __auto_type f = _mv_1640.data.rc_some.f1;
            return howl_aligninput_concept_usable((*f));
        }
        case howl_owl2_RawConcept_rc_all:
        {
            __auto_type f = _mv_1640.data.rc_all.f1;
            return howl_aligninput_concept_usable((*f));
        }
        case howl_owl2_RawConcept_rc_qcard:
        {
            __auto_type f = _mv_1640.data.rc_qcard.f3;
            return howl_aligninput_concept_usable((*f));
        }
        default: {
            return 1;
        }
    }
}

uint8_t howl_aligninput_concepts_usable(slop_list_howl_owl2_RawConcept cs) {
    {
        uint8_t yes = 1;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(howl_aligninput_concept_usable(c))) {
                    yes = 0;
                }
            }
        }
        return yes;
    }
}

howl_owl2_RawConcept howl_aligninput_canonical_concept(slop_arena* arena, howl_owl2_RawConcept c) {
    __auto_type _mv_1641 = c;
    switch (_mv_1641.tag) {
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_1641.data.rc_and;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_and, .data.rc_and = howl_aligninput_canonical_concepts(arena, cs, 1, 1) });
        }
        case howl_owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_1641.data.rc_or;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_or, .data.rc_or = howl_aligninput_canonical_concepts(arena, cs, 1, 0) });
        }
        case howl_owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_1641.data.rc_not;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_not, .data.rc_not = howl_decode_box_concept(arena, howl_aligninput_canonical_concept(arena, (*f))) });
        }
        case howl_owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_1641.data.rc_some.f0;
            __auto_type f = _mv_1641.data.rc_some.f1;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_some, .data.rc_some = { .f0 = r, .f1 = howl_decode_box_concept(arena, howl_aligninput_canonical_concept(arena, (*f))) } });
        }
        case howl_owl2_RawConcept_rc_all:
        {
            __auto_type r = _mv_1641.data.rc_all.f0;
            __auto_type f = _mv_1641.data.rc_all.f1;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_all, .data.rc_all = { .f0 = r, .f1 = howl_decode_box_concept(arena, howl_aligninput_canonical_concept(arena, (*f))) } });
        }
        case howl_owl2_RawConcept_rc_qcard:
        {
            __auto_type k = _mv_1641.data.rc_qcard.f0;
            __auto_type r = _mv_1641.data.rc_qcard.f1;
            __auto_type n = _mv_1641.data.rc_qcard.f2;
            __auto_type f = _mv_1641.data.rc_qcard.f3;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_qcard, .data.rc_qcard = { .f0 = k, .f1 = r, .f2 = n, .f3 = howl_decode_box_concept(arena, howl_aligninput_canonical_concept(arena, (*f))) } });
        }
        case howl_owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_1641.data.rc_oneof;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_oneof, .data.rc_oneof = howl_canon_sort_nodes(arena, ns) });
        }
        default: {
            return c;
        }
    }
}

slop_list_howl_owl2_RawConcept howl_aligninput_append_operands(slop_arena* arena, slop_list_howl_owl2_RawConcept cs, uint8_t flatten, uint8_t conjunction) {
    {
        __auto_type out = ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                __auto_type _mv_1642 = c;
                switch (_mv_1642.tag) {
                    case howl_owl2_RawConcept_rc_and:
                    {
                        __auto_type inner = _mv_1642.data.rc_and;
                        if (flatten && conjunction) {
                            {
                                __auto_type _coll = howl_aligninput_append_operands(arena, inner, flatten, conjunction);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type v = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        } else {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_aligninput_canonical_concept(arena, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        break;
                    }
                    case howl_owl2_RawConcept_rc_or:
                    {
                        __auto_type inner = _mv_1642.data.rc_or;
                        if (flatten && !(conjunction)) {
                            {
                                __auto_type _coll = howl_aligninput_append_operands(arena, inner, flatten, conjunction);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type v = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        } else {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_aligninput_canonical_concept(arena, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        break;
                    }
                    default: {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_aligninput_canonical_concept(arena, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                }
            }
        }
        return out;
    }
}

howl_types_RoleId howl_aligninput_role_at(slop_list_howl_types_RoleId rs, int64_t i) {
    __auto_type _mv_1643 = ({ __auto_type _lst = rs; size_t _idx = (size_t)i; slop_option_howl_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1643.has_value) {
        __auto_type r = _mv_1643.value;
        return r;
    } else if (!_mv_1643.has_value) {
        return ((howl_types_RoleId){ .tag = howl_types_RoleId_fresh_role, .data.fresh_role = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_RoleId howl_aligninput_sort_roles(slop_arena* arena, slop_list_howl_types_RoleId rs) {
    {
        __auto_type indices = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((rs).len)))), ({ howl_aligninput__lambda_1644_env_t* howl_aligninput__lambda_1644_env = (howl_aligninput__lambda_1644_env_t*)slop_arena_alloc(arena, sizeof(howl_aligninput__lambda_1644_env_t)); *howl_aligninput__lambda_1644_env = (howl_aligninput__lambda_1644_env_t){ .rs = rs }; (slop_closure_t){ (void*)howl_aligninput__lambda_1644, (void*)howl_aligninput__lambda_1644_env }; }));
        __auto_type out = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = indices;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_aligninput_role_at(rs, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_owl2_RawConcept howl_aligninput_canonical_concepts(slop_arena* arena, slop_list_howl_owl2_RawConcept cs, uint8_t flatten, uint8_t conjunction) {
    {
        __auto_type parts = howl_aligninput_append_operands(arena, cs, flatten, conjunction);
        __auto_type out = ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        slop_option_howl_owl2_RawConcept previous = (slop_option_howl_owl2_RawConcept){.has_value = false};
        {
            __auto_type _coll = howl_owl2_sort_concepts(arena, parts);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(flatten) || ({ __auto_type _mv = previous; _mv.has_value ? ({ __auto_type p = _mv.value; (howl_owl2_concept_cmp(p, c) != 0); }) : (1); })) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    previous = (slop_option_howl_owl2_RawConcept){.has_value = 1, .value = c};
                }
            }
        }
        return out;
    }
}

slop_option_howl_owl2_RawAxiom howl_aligninput_canonical_mapping_axiom(slop_arena* arena, howl_owl2_RawAxiom ax) {
    __auto_type _mv_1645 = ax;
    switch (_mv_1645.tag) {
        case howl_owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_1645.data.ra_sub_class_of.f0;
            __auto_type r = _mv_1645.data.ra_sub_class_of.f1;
            if (howl_aligninput_concept_usable((*l)) && howl_aligninput_concept_usable((*r))) {
                return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_sub_class_of, .data.ra_sub_class_of = { .f0 = howl_decode_box_concept(arena, howl_aligninput_canonical_concept(arena, (*l))), .f1 = howl_decode_box_concept(arena, howl_aligninput_canonical_concept(arena, (*r))) } })};
            } else {
                return (slop_option_howl_owl2_RawAxiom){.has_value = false};
            }
        }
        case howl_owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type cs = _mv_1645.data.ra_equivalent_classes;
            if (howl_aligninput_concepts_usable(cs)) {
                return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_equivalent_classes, .data.ra_equivalent_classes = howl_aligninput_canonical_concepts(arena, cs, 0, 0) })};
            } else {
                return (slop_option_howl_owl2_RawAxiom){.has_value = false};
            }
        }
        case howl_owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_1645.data.ra_disjoint_classes;
            if (howl_aligninput_concepts_usable(cs)) {
                return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_disjoint_classes, .data.ra_disjoint_classes = howl_aligninput_canonical_concepts(arena, cs, 0, 0) })};
            } else {
                return (slop_option_howl_owl2_RawAxiom){.has_value = false};
            }
        }
        case howl_owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_1645.data.ra_object_property_domain.f0;
            __auto_type c = _mv_1645.data.ra_object_property_domain.f1;
            if (howl_aligninput_concept_usable((*c))) {
                return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_object_property_domain, .data.ra_object_property_domain = { .f0 = r, .f1 = howl_decode_box_concept(arena, howl_aligninput_canonical_concept(arena, (*c))) } })};
            } else {
                return (slop_option_howl_owl2_RawAxiom){.has_value = false};
            }
        }
        case howl_owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type r = _mv_1645.data.ra_object_property_range.f0;
            __auto_type c = _mv_1645.data.ra_object_property_range.f1;
            if (howl_aligninput_concept_usable((*c))) {
                return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_object_property_range, .data.ra_object_property_range = { .f0 = r, .f1 = howl_decode_box_concept(arena, howl_aligninput_canonical_concept(arena, (*c))) } })};
            } else {
                return (slop_option_howl_owl2_RawAxiom){.has_value = false};
            }
        }
        case howl_owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_1645.data.ra_class_assertion;
            if (howl_aligninput_concept_usable((*ca.concept))) {
                return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_class_assertion, .data.ra_class_assertion = ((howl_owl2_RawClassAssertion){.subject = ca.subject, .concept = howl_decode_box_concept(arena, howl_aligninput_canonical_concept(arena, (*ca.concept)))}) })};
            } else {
                return (slop_option_howl_owl2_RawAxiom){.has_value = false};
            }
        }
        case howl_owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type du = _mv_1645.data.ra_disjoint_union;
            if (howl_aligninput_concepts_usable(du.members)) {
                return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_disjoint_union, .data.ra_disjoint_union = ((howl_owl2_RawDisjointUnion){.class = du.class, .members = howl_aligninput_canonical_concepts(arena, du.members, 0, 0)}) })};
            } else {
                return (slop_option_howl_owl2_RawAxiom){.has_value = false};
            }
        }
        case howl_owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type rs = _mv_1645.data.ra_equivalent_properties;
            return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_equivalent_properties, .data.ra_equivalent_properties = howl_aligninput_sort_roles(arena, rs) })};
        }
        case howl_owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type rs = _mv_1645.data.ra_disjoint_properties;
            return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_disjoint_properties, .data.ra_disjoint_properties = howl_aligninput_sort_roles(arena, rs) })};
        }
        case howl_owl2_RawAxiom_ra_same_individual:
        {
            __auto_type ns = _mv_1645.data.ra_same_individual;
            return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_same_individual, .data.ra_same_individual = howl_canon_sort_nodes(arena, ns) })};
        }
        case howl_owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type ns = _mv_1645.data.ra_different_individuals;
            return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_different_individuals, .data.ra_different_individuals = howl_canon_sort_nodes(arena, ns) })};
        }
        case howl_owl2_RawAxiom_ra_inverse_properties:
        {
            __auto_type a = _mv_1645.data.ra_inverse_properties.f0;
            __auto_type b = _mv_1645.data.ra_inverse_properties.f1;
            {
                __auto_type rs = howl_aligninput_sort_roles(arena, ({ slop_list_howl_types_RoleId _ll = (slop_list_howl_types_RoleId){ .data = (howl_types_RoleId*)slop_arena_alloc(arena, 2 * sizeof(howl_types_RoleId)), .len = 2, .cap = 2, .arena = arena }; _ll.data[0] = a; _ll.data[1] = b; _ll; }));
                return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_inverse_properties, .data.ra_inverse_properties = { .f0 = ({ __auto_type _mv = ({ __auto_type _lst = rs; size_t _idx = (size_t)0; slop_option_howl_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type r = _mv.value; r; }) : (a); }), .f1 = ({ __auto_type _mv = ({ __auto_type _lst = rs; size_t _idx = (size_t)1; slop_option_howl_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type r = _mv.value; r; }) : (b); }) } })};
            }
        }
        case howl_owl2_RawAxiom_ra_sub_object_property:
        {
            return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ax};
        }
        case howl_owl2_RawAxiom_ra_property_chain:
        {
            __auto_type _ = _mv_1645.data.ra_property_chain;
            return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ax};
        }
        case howl_owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type _ = _mv_1645.data.ra_transitive_property;
            return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ax};
        }
        case howl_owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type _ = _mv_1645.data.ra_object_property_assertion;
            return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ax};
        }
        case howl_owl2_RawAxiom_ra_property_characteristic:
        {
            return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ax};
        }
        case howl_owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type _ = _mv_1645.data.ra_negative_assertion;
            return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ax};
        }
        default: {
            return (slop_option_howl_owl2_RawAxiom){.has_value = false};
        }
    }
}

uint8_t howl_aligninput_ascii_letter(int64_t c) {
    return (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)));
}

uint8_t howl_aligninput_source_iri_valid(slop_string s) {
    {
        uint8_t ok = (string_len(s) > 0);
        uint8_t colon = 0;
        int64_t i = 0;
        while (i < string_len(s)) {
            {
                __auto_type c = ((int64_t)(std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at aligninput.slop:155:41"))));
                if (((c <= 32)) || ((c == 127)) || ((c == 60)) || ((c == 62)) || ((c == 34)) || ((c == 123)) || ((c == 125)) || ((c == 124)) || ((c == 92)) || ((c == 94)) || ((c == 96))) {
                    ok = 0;
                }
                if (!(colon)) {
                    if (c == 58) {
                        if (i == 0) {
                            ok = 0;
                        }
                        colon = 1;
                    } else {
                        if (!((howl_aligninput_ascii_letter(c) || ((i > 0) && ((((c >= 48) && (c <= 57))) || ((c == 43)) || ((c == 45)) || ((c == 46))))))) {
                            ok = 0;
                        }
                    }
                }
                i = (i + 1);
            }
        }
        return (ok && colon);
    }
}

uint8_t howl_aligninput_metadata_problem(slop_list_slop_rdf_rdf_IRI sources, slop_list_u8 mapping_docs, int64_t documents) {
    {
        uint8_t bad = ((((int64_t)((sources).len)) != documents) || (((int64_t)((mapping_docs).len)) != documents));
        int64_t i = 0;
        {
            __auto_type _coll = sources;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                if (!(howl_aligninput_source_iri_valid(s.value))) {
                    bad = 1;
                }
                {
                    int64_t j = 0;
                    {
                        __auto_type _coll = sources;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type t = _coll.data[_i];
                            if ((j < i) && (howl_canon_iri_cmp(s, t) == 0)) {
                                bad = 1;
                            }
                            j = (j + 1);
                        }
                    }
                }
                i = (i + 1);
            }
        }
        return bad;
    }
}

slop_result_howl_aligninput_AlignmentBase_howl_types_Fault howl_aligninput_alignment_base(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports, slop_list_slop_rdf_rdf_IRI sources, slop_list_u8 mapping_docs) {
    if (howl_aligninput_metadata_problem(sources, mapping_docs, ((int64_t)(((int64_t)((doc.starts).len)))))) {
        return ((slop_result_howl_aligninput_AlignmentBase_howl_types_Fault){ .is_ok = false, .data.err = ((howl_types_Fault){ .tag = howl_types_Fault_input_error, .data.input_error = SLOP_STR("Alignment documents need unique nonempty source IRIs and a role each") }) });
    } else {
        __auto_type _mv_1646 = howl_decode_stage0_encoded(arena, doc, imports);
        if (!_mv_1646.is_ok) {
            __auto_type f = _mv_1646.data.err;
            return ((slop_result_howl_aligninput_AlignmentBase_howl_types_Fault){ .is_ok = false, .data.err = f });
        } else if (_mv_1646.is_ok) {
            __auto_type stage = _mv_1646.data.ok;
            __auto_type _mv_1647 = howl_decode_decode_axioms_positioned(arena, stage.dict, stage.triples, stage.docs);
            if (!_mv_1647.is_ok) {
                __auto_type f = _mv_1647.data.err;
                return ((slop_result_howl_aligninput_AlignmentBase_howl_types_Fault){ .is_ok = false, .data.err = f });
            } else if (_mv_1647.is_ok) {
                __auto_type decoded = _mv_1647.data.ok;
                return ((slop_result_howl_aligninput_AlignmentBase_howl_types_Fault){ .is_ok = true, .data.ok = howl_aligninput_inventory(arena, stage, decoded, sources, mapping_docs) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

howl_aligninput_AlignmentBase howl_aligninput_inventory(slop_arena* arena, howl_decode_Stage0 stage, howl_decode_Stage1 decoded, slop_list_slop_rdf_rdf_IRI sources, slop_list_u8 mapping_docs) {
    {
        __auto_type refs = ((slop_list_howl_types_AxiomRef){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type positions = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type by_key = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type anchors = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, int64_t); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type mappings = ((slop_list_howl_types_AxiomRef){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type negative_roots = howl_decode_alignment_negative_roots(arena, stage.dict, stage.triples);
        int64_t i = 0;
        {
            __auto_type _coll = decoded.axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                {
                    __auto_type d = (((((int64_t)((sources).len)) == 1)) ? 0 : howl_aligninput_int_at(decoded.axiom_docs, i));
                    if (howl_aligninput_bool_at(mapping_docs, d)) {
                        __auto_type _mv_1648 = howl_aligninput_canonical_mapping_axiom(arena, ax);
                        if (!_mv_1648.has_value) {
                        } else if (_mv_1648.has_value) {
                            __auto_type ca = _mv_1648.value;
                            __auto_type _mv_1649 = ({ __auto_type _lst = sources; size_t _idx = (size_t)d; slop_option_slop_rdf_rdf_IRI _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                            if (!_mv_1649.has_value) {
                            } else if (_mv_1649.has_value) {
                                __auto_type source = _mv_1649.value;
                                ({ __auto_type _lst_p = &(refs); __auto_type _item = (((howl_types_AxiomRef){.source = (slop_option_slop_rdf_rdf_IRI){.has_value = 1, .value = source}, .text = howl_owl2_render_axiom(arena, ca)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                ({ __auto_type _lst_p = &(positions); __auto_type _item = (howl_aligninput_int_at(decoded.axiom_positions, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                    i = (i + 1);
                }
            }
        }
        {
            __auto_type _coll = howl_canon_sort_axiom_refs(arena, refs);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                {
                    __auto_type key = howl_aligninput_ref_key(arena, r);
                    if (!(slop_map_has(by_key, &(key)))) {
                        (void)(({ int64_t _val = ((int64_t)(((int64_t)((mappings).len)))); slop_map_put(NULL, by_key, &(key), &_val, sizeof(_val)); }));
                        (void)(({ __auto_type _lst_p = &(mappings); __auto_type _item = (howl_types_copy_axiom_ref(arena, r)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        i = 0;
        {
            __auto_type _coll = refs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                __auto_type _mv_1653 = ({ slop_string _key_1652 = (howl_aligninput_ref_key(arena, r)); void* _ptr = slop_map_get(by_key, &_key_1652); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
                if (_mv_1653.has_value) {
                    __auto_type k = _mv_1653.value;
                    ({ int64_t _val = k; slop_map_put(NULL, anchors, &(int64_t){howl_aligninput_int_at(positions, i)}, &_val, sizeof(_val)); });
                } else if (!_mv_1653.has_value) {
                }
                i = (i + 1);
            }
        }
        {
            __auto_type scaffolds = howl_decode_alignment_scaffolds(arena, stage.dict, stage.triples);
            __auto_type negative_parts = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            __auto_type part_ids = howl_decode_negative_assertion_parts(arena, stage.dict);
            {
                __auto_type _coll = stage.triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type t = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(negative_parts); __auto_type _item = (slop_map_has(part_ids, &(int64_t){t.p})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
            return ((howl_aligninput_AlignmentBase){.stage = stage, .signature = decoded.signature, .documents = ((int64_t)(((int64_t)((sources).len)))), .mappings = mappings, .anchors = anchors, .scaffolds = scaffolds, .negative_roots = negative_roots, .negative_parts = negative_parts, .owned = howl_aligninput_reachable(arena, stage.triples, scaffolds, anchors, ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); }), howl_aligninput_live_negative(arena, stage.triples, anchors, ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); }), negative_roots), negative_parts)});
        }
    }
}

slop_map* howl_aligninput_live_negative(slop_arena* arena, slop_list_howl_termstore_IdTriple triples, slop_map* anchors, slop_map* removed, slop_map* roots) {
    {
        __auto_type out = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        int64_t i = 0;
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (!(({ __auto_type _mv = ({ void* _ptr = slop_map_get(anchors, &(int64_t){i}); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type k = _mv.value; slop_map_has(removed, &(int64_t){k}); }) : (0); }))) {
                    __auto_type _mv_1659 = ({ void* _ptr = slop_map_get(roots, &(int64_t){i}); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
                    if (_mv_1659.has_value) {
                        __auto_type n = _mv_1659.value;
                        ({ slop_map_put(NULL, out, &(int64_t){n}, NULL, 0); });
                    } else if (!_mv_1659.has_value) {
                    }
                }
                i = (i + 1);
            }
        }
        return out;
    }
}

slop_map* howl_aligninput_reachable(slop_arena* arena, slop_list_howl_termstore_IdTriple triples, slop_list_u8 scaffolds, slop_map* anchors, slop_map* removed, slop_map* negative_live, slop_list_u8 negative_parts) {
    {
        __auto_type nodes = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        int64_t i = 0;
        uint8_t changed = 1;
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (!(howl_aligninput_bool_at(scaffolds, i)) && !(({ __auto_type _mv = ({ void* _ptr = slop_map_get(anchors, &(int64_t){i}); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type k = _mv.value; slop_map_has(removed, &(int64_t){k}); }) : (0); }))) {
                    (void)(({ slop_map_put(NULL, nodes, &(int64_t){t.s}, NULL, 0); }));
                    (void)(({ slop_map_put(NULL, nodes, &(int64_t){t.o}, NULL, 0); }));
                }
                i = (i + 1);
            }
        }
        while (changed) {
            changed = 0;
            i = 0;
            {
                __auto_type _coll = triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type t = _coll.data[_i];
                    if ((howl_aligninput_bool_at(scaffolds, i)) && (slop_map_has(nodes, &(int64_t){t.s})) && (!(slop_map_has(nodes, &(int64_t){t.o}))) && ((!(howl_aligninput_bool_at(negative_parts, i)) || slop_map_has(negative_live, &(int64_t){t.s})))) {
                        (void)(({ slop_map_put(NULL, nodes, &(int64_t){t.o}, NULL, 0); }));
                        changed = 1;
                    }
                    i = (i + 1);
                }
            }
        }
        return nodes;
    }
}

slop_result_howl_normalize_Decoded_howl_types_Fault howl_aligninput_subset_decoded(slop_arena* arena, howl_aligninput_AlignmentBase base, slop_list_int removed) {
    {
        __auto_type gone = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        uint8_t invalid = 0;
        {
            __auto_type _coll = removed;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                if ((k < 0) || (k >= ((int64_t)((base.mappings).len)))) {
                    invalid = 1;
                } else {
                    (void)(({ slop_map_put(NULL, gone, &(int64_t){k}, NULL, 0); }));
                }
            }
        }
        if (invalid) {
            return ((slop_result_howl_normalize_Decoded_howl_types_Fault){ .is_ok = false, .data.err = ((howl_types_Fault){ .tag = howl_types_Fault_input_error, .data.input_error = SLOP_STR("Alignment removal index outside mapping inventory") }) });
        } else {
            return howl_aligninput_subset_with(arena, base, gone);
        }
    }
}

slop_result_howl_normalize_Decoded_howl_types_Fault howl_aligninput_subset_with(slop_arena* arena, howl_aligninput_AlignmentBase base, slop_map* gone) {
    {
        __auto_type s0 = base.stage;
        __auto_type negative_live = howl_aligninput_live_negative(arena, s0.triples, base.anchors, gone, base.negative_roots);
        __auto_type live = howl_aligninput_reachable(arena, s0.triples, base.scaffolds, base.anchors, gone, negative_live, base.negative_parts);
        __auto_type triples = ((slop_list_howl_termstore_IdTriple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type docs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = s0.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (!(({ __auto_type _mv = ({ void* _ptr = slop_map_get(base.anchors, &(int64_t){i}); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type k = _mv.value; slop_map_has(gone, &(int64_t){k}); }) : (0); })) && (!(howl_aligninput_bool_at(base.scaffolds, i)) || ((!(howl_aligninput_bool_at(base.negative_parts, i)) || slop_map_has(negative_live, &(int64_t){t.s})) && (!(slop_map_has(base.owned, &(int64_t){t.s})) || slop_map_has(live, &(int64_t){t.s}))))) {
                    (void)(({ __auto_type _lst_p = &(triples); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    if (base.documents > 1) {
                        (void)(({ __auto_type _lst_p = &(docs); __auto_type _item = (howl_aligninput_int_at(s0.docs, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
                i = (i + 1);
            }
        }
        __auto_type _mv_1675 = howl_decode_decode_axioms_sourced(arena, s0.dict, triples, docs);
        if (!_mv_1675.is_ok) {
            __auto_type f = _mv_1675.data.err;
            return ((slop_result_howl_normalize_Decoded_howl_types_Fault){ .is_ok = false, .data.err = f });
        } else if (_mv_1675.is_ok) {
            __auto_type d = _mv_1675.data.ok;
            {
                __auto_type oms = ((slop_list_howl_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                __auto_type origins = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                {
                    __auto_type _coll = s0.omissions;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type o = _coll.data[_i];
                        ({ __auto_type _lst_p = &(oms); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                {
                    __auto_type _coll = d.omitted;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type o = _coll.data[_i];
                        ({ __auto_type _lst_p = &(oms); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                {
                    __auto_type _coll = s0.omission_docs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type k = _coll.data[_i];
                        ({ __auto_type _lst_p = &(origins); __auto_type _item = (k); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                {
                    __auto_type _coll = d.omission_docs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type k = _coll.data[_i];
                        ({ __auto_type _lst_p = &(origins); __auto_type _item = (k); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                return ((slop_result_howl_normalize_Decoded_howl_types_Fault){ .is_ok = true, .data.ok = ((howl_normalize_Decoded){.axioms = d.axioms, .signature = base.signature, .omissions = oms, .documents = base.documents, .axiom_docs = d.axiom_docs, .omission_docs = origins}) });
            }
        }
        SLOP_UNREACHABLE();
    }
}

