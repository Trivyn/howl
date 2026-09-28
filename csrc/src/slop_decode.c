#include "../runtime/slop_runtime.h"
#include "slop_decode.h"


rdf_Term decode_term_at(slop_list_rdf_Term xs, int64_t i);
rdf_Triple decode_triple_at(slop_list_rdf_Triple xs, int64_t i);
termstore_TermStore decode_graph_to_indexed(slop_arena* arena, slop_list_rdf_Triple triples);
slop_result_rdf_Term_decode_LookupFault decode_one_object(slop_arena* arena, termstore_TermStore g, rdf_Term subj, rdf_Term pred);
slop_result_list_rdf_Term_decode_ListFault decode_rdf_list_checked(slop_arena* arena, termstore_TermStore g, rdf_Term head);
slop_option_rdf_IRI decode_term_iri_value(rdf_Term t);
uint8_t decode_iri_in_list(slop_list_rdf_IRI xs, rdf_IRI target);
slop_list_rdf_IRI decode_collect_imports(slop_arena* arena, slop_list_rdf_Triple triples);
slop_list_types_Omission decode_unresolved_imports(slop_arena* arena, slop_list_rdf_IRI declared, slop_list_rdf_IRI resolved);
slop_list_rdf_Term decode_subjects_of_type(slop_arena* arena, termstore_TermStore g, slop_string type_iri);
uint8_t decode_typed_as(rdf_Triple t, slop_string type_iri);
slop_list_rdf_Term decode_typed_subjects_in_order(slop_arena* arena, slop_list_rdf_Triple triples, slop_string type_iri);
uint8_t decode_logical_predicate(slop_string pv);
rdf_Triple decode_ex_hdr(slop_string p, slop_string o);
uint8_t decode_header_consumable(rdf_Triple t);
slop_result_decode_Stage0_types_Fault decode_stage0_header(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved);
owl2_RawConcept* decode_box_concept(slop_arena* arena, owl2_RawConcept c);
slop_string decode_list_fault_message(decode_ListFault f);
uint8_t decode_has_pred(slop_arena* arena, termstore_TermStore g, rdf_Term s, slop_string pred_iri);
slop_result_rdf_Term_decode_LookupFault decode_obj_of(slop_arena* arena, termstore_TermStore g, rdf_Term s, slop_string pred_iri);
slop_result_types_RoleId_string decode_decode_role(slop_arena* arena, termstore_TermStore g, rdf_Term b);
uint8_t decode_inverse_expression_term(slop_arena* arena, termstore_TermStore g, rdf_Term t);
uint8_t decode_restriction_on_inverse(slop_arena* arena, termstore_TermStore g, rdf_Term b);
uint8_t decode_list_has_inverse(slop_arena* arena, termstore_TermStore g, rdf_Term head);
uint8_t decode_property_axiom_on_inverse(slop_arena* arena, termstore_TermStore g, slop_string pv, rdf_Triple t);
slop_result_int_string decode_literal_count(rdf_Term t);
slop_result_list_types_Node_string decode_decode_node_list(slop_arena* arena, termstore_TermStore g, rdf_Term head);
slop_result_list_owl2_RawConcept_string decode_decode_concept_list(slop_arena* arena, termstore_TermStore g, rdf_Term head, int64_t fuel);
slop_result_owl2_RawConcept_string decode_decode_quantified(slop_arena* arena, termstore_TermStore g, rdf_Term b, slop_string filler_pred, uint8_t universal, int64_t fuel);
slop_result_owl2_RawConcept_string decode_decode_cardinality(slop_arena* arena, termstore_TermStore g, rdf_Term b, owl2_CardKind kind, slop_string count_pred, uint8_t qualified, int64_t fuel);
slop_result_owl2_RawConcept_string decode_decode_anon(slop_arena* arena, termstore_TermStore g, rdf_Term b, int64_t fuel);
slop_result_owl2_RawConcept_string decode_decode_concept(slop_arena* arena, termstore_TermStore g, rdf_Term t, int64_t fuel);
uint8_t decode_declare_entity(slop_arena* arena, owl2_Signature sig, rdf_IRI entity, slop_string type_iri);
uint8_t decode_add_builtins(slop_arena* arena, owl2_Signature sig);
owl2_Signature decode_build_signature(slop_arena* arena, slop_list_rdf_Triple triples);
slop_string decode_render_term(slop_arena* arena, rdf_Term t);
slop_string decode_render_triple(slop_arena* arena, rdf_Triple t);
types_InputRef decode_frag(slop_arena* arena, rdf_Triple t);
uint8_t decode_is_pred(rdf_Triple t, slop_string iri);
uint8_t decode_structural_predicate(slop_string p);
uint8_t decode_structural_triple(rdf_Triple t);
slop_option_types_EntityKind decode_entity_kind_of(slop_string type_iri);
slop_option_owl2_PropCharacteristic decode_characteristic_of(slop_string type_iri);
slop_option_types_RoleId decode_role_of_term(rdf_Term t);
slop_result_list_types_RoleId_string decode_decode_role_list(slop_arena* arena, termstore_TermStore g, rdf_Term head);
slop_result_list_owl2_RawConcept_string decode_binary_concepts(slop_arena* arena, termstore_TermStore g, rdf_Triple t);
slop_option_rdf_Term decode_members_head(slop_arena* arena, termstore_TermStore g, rdf_Term s);
slop_result_owl2_RawAxiom_string decode_decode_typed(slop_arena* arena, termstore_TermStore g, rdf_Triple t, rdf_IRI obj);
slop_result_owl2_RawAxiom_string decode_decode_class_assertion(slop_arena* arena, termstore_TermStore g, rdf_Triple t);
uint8_t decode_is_reserved_iri(slop_string v);
int64_t decode_property_axiom_kind(owl2_Signature sig, rdf_Term subj);
slop_result_owl2_RawAxiom_string decode_decode_axiom(slop_arena* arena, termstore_TermStore g, owl2_Signature sig, rdf_Triple t);
slop_result_decode_Stage1_types_Fault decode_decode_axioms(slop_arena* arena, slop_list_rdf_Triple triples);
slop_option_string decode_declaration_conflict(slop_arena* arena, owl2_Signature sig, slop_list_rdf_Triple triples);

rdf_Term decode_term_at(slop_list_rdf_Term xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_257 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_257.has_value) {
        __auto_type v = _mv_257.value;
        return v;
    } else if (!_mv_257.has_value) {
        return ((rdf_Term){ .tag = rdf_Term_term_blank, .data.term_blank = ((rdf_BlankNode){.id = 0}) });
    }
    SLOP_UNREACHABLE();
}

rdf_Triple decode_triple_at(slop_list_rdf_Triple xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    {
        __auto_type blank = ((rdf_Term){ .tag = rdf_Term_term_blank, .data.term_blank = ((rdf_BlankNode){.id = 0}) });
        __auto_type _mv_258 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_rdf_Triple _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_258.has_value) {
            __auto_type v = _mv_258.value;
            return v;
        } else if (!_mv_258.has_value) {
            return ((rdf_Triple){.subject = blank, .predicate = blank, .object = blank});
        }
        SLOP_UNREACHABLE();
    }
}

termstore_TermStore decode_graph_to_indexed(slop_arena* arena, slop_list_rdf_Triple triples) {
    return termstore_build_store(arena, triples);
}

slop_result_rdf_Term_decode_LookupFault decode_one_object(slop_arena* arena, termstore_TermStore g, rdf_Term subj, rdf_Term pred) {
    {
        __auto_type objs = termstore_store_objects(arena, g, subj, pred);
        __auto_type n = ((int64_t)(((int64_t)((objs).len))));
        if (n == 1) {
            return ((slop_result_rdf_Term_decode_LookupFault){ .is_ok = true, .data.ok = decode_term_at(objs, 0) });
        } else if (n == 0) {
            return ((slop_result_rdf_Term_decode_LookupFault){ .is_ok = false, .data.err = decode_LookupFault_lookup_missing });
        } else {
            return ((slop_result_rdf_Term_decode_LookupFault){ .is_ok = false, .data.err = decode_LookupFault_lookup_ambiguous });
        }
    }
}

slop_result_list_rdf_Term_decode_ListFault decode_rdf_list_checked(slop_arena* arena, termstore_TermStore g, rdf_Term head) {
    {
        __auto_type first_pred = rdf_make_iri(arena, vocab_RDF_FIRST);
        __auto_type rest_pred = rdf_make_iri(arena, vocab_RDF_REST);
        __auto_type nil_term = rdf_make_iri(arena, vocab_RDF_NIL);
        __auto_type out = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type visited = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        __auto_type current = head;
        slop_option_decode_ListFault fault = (slop_option_decode_ListFault){.has_value = false};
        uint8_t done = 0;
        while (!(done) && !(rdf_term_eq(current, nil_term))) {
            if (slop_map_get(visited, &(current)) != NULL) {
                fault = (slop_option_decode_ListFault){.has_value = 1, .value = ((decode_ListFault){ .tag = decode_ListFault_list_cyclic, .data.list_cyclic = SLOP_STR("rdf:rest returns to a cell already visited") })};
                done = 1;
            } else {
                ({ uint8_t _dummy = 1; slop_map_put(arena, visited, &(current), &_dummy); });
                {
                    __auto_type firsts = termstore_store_objects(arena, g, current, first_pred);
                    __auto_type rests = termstore_store_objects(arena, g, current, rest_pred);
                    {
                        __auto_type nf = ((int64_t)(((int64_t)((firsts).len))));
                        __auto_type nr = ((int64_t)(((int64_t)((rests).len))));
                        if (nf == 0) {
                            fault = (slop_option_decode_ListFault){.has_value = 1, .value = ((decode_ListFault){ .tag = decode_ListFault_list_truncated, .data.list_truncated = SLOP_STR("list cell has no rdf:first") })};
                            done = 1;
                        } else if (nf > 1) {
                            fault = (slop_option_decode_ListFault){.has_value = 1, .value = ((decode_ListFault){ .tag = decode_ListFault_list_branching, .data.list_branching = SLOP_STR("list cell has several rdf:first values") })};
                            done = 1;
                        } else if (nr == 0) {
                            fault = (slop_option_decode_ListFault){.has_value = 1, .value = ((decode_ListFault){ .tag = decode_ListFault_list_truncated, .data.list_truncated = SLOP_STR("list cell has no rdf:rest") })};
                            done = 1;
                        } else if (nr > 1) {
                            fault = (slop_option_decode_ListFault){.has_value = 1, .value = ((decode_ListFault){ .tag = decode_ListFault_list_branching, .data.list_branching = SLOP_STR("list cell has several rdf:rest values") })};
                            done = 1;
                        } else {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (decode_term_at(firsts, 0)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            current = decode_term_at(rests, 0);
                        }
                    }
                }
            }
        }
        __auto_type _mv_261 = fault;
        if (_mv_261.has_value) {
            __auto_type f = _mv_261.value;
            return ((slop_result_list_rdf_Term_decode_ListFault){ .is_ok = false, .data.err = f });
        } else if (!_mv_261.has_value) {
            return ((slop_result_list_rdf_Term_decode_ListFault){ .is_ok = true, .data.ok = out });
        }
        SLOP_UNREACHABLE();
    }
}

slop_option_rdf_IRI decode_term_iri_value(rdf_Term t) {
    __auto_type _mv_262 = t;
    switch (_mv_262.tag) {
        case rdf_Term_term_iri:
        {
            __auto_type i = _mv_262.data.term_iri;
            return (slop_option_rdf_IRI){.has_value = 1, .value = i};
        }
        case rdf_Term_term_blank:
        {
            __auto_type _ = _mv_262.data.term_blank;
            return (slop_option_rdf_IRI){.has_value = false};
        }
        case rdf_Term_term_literal:
        {
            __auto_type _ = _mv_262.data.term_literal;
            return (slop_option_rdf_IRI){.has_value = false};
        }
        case rdf_Term_term_triple:
        {
            __auto_type _ = _mv_262.data.term_triple;
            return (slop_option_rdf_IRI){.has_value = false};
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t decode_iri_in_list(slop_list_rdf_IRI xs, rdf_IRI target) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (canon_iri_cmp(x, target) == 0) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_list_rdf_IRI decode_collect_imports(slop_arena* arena, slop_list_rdf_Triple triples) {
    {
        __auto_type imports_iri = rdf_make_iri(arena, vocab_OWL_IMPORTS);
        __auto_type out = ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 });
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (rdf_term_eq(t.predicate, imports_iri)) {
                    __auto_type _mv_263 = decode_term_iri_value(t.object);
                    if (_mv_263.has_value) {
                        __auto_type i = _mv_263.value;
                        if (!(decode_iri_in_list(out, i))) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    } else if (!_mv_263.has_value) {
                    }
                }
            }
        }
        return canon_sort_iris(arena, out);
    }
}

slop_list_types_Omission decode_unresolved_imports(slop_arena* arena, slop_list_rdf_IRI declared, slop_list_rdf_IRI resolved) {
    {
        __auto_type out = ((slop_list_types_Omission){ .data = (types_Omission*)slop_arena_alloc(arena, 16 * sizeof(types_Omission)), .len = 0, .cap = 16 });
        {
            __auto_type _coll = declared;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type d = _coll.data[_i];
                if (!(decode_iri_in_list(resolved, d))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_Omission){ .tag = types_Omission_unresolved_import, .data.unresolved_import = d })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return canon_sort_omissions(arena, out);
    }
}

slop_list_rdf_Term decode_subjects_of_type(slop_arena* arena, termstore_TermStore g, slop_string type_iri) {
    return termstore_store_typed(arena, g, rdf_make_iri(arena, type_iri));
}

uint8_t decode_typed_as(rdf_Triple t, slop_string type_iri) {
    __auto_type _mv_264 = decode_term_iri_value(t.predicate);
    if (!_mv_264.has_value) {
        return 0;
    } else if (_mv_264.has_value) {
        __auto_type p = _mv_264.value;
        return ((canon_string_cmp(p.value, vocab_RDF_TYPE) == 0) && ({ __auto_type _mv = decode_term_iri_value(t.object); _mv.has_value ? ({ __auto_type o = _mv.value; (canon_string_cmp(o.value, type_iri) == 0); }) : (0); }));
    }
    SLOP_UNREACHABLE();
}

slop_list_rdf_Term decode_typed_subjects_in_order(slop_arena* arena, slop_list_rdf_Triple triples, slop_string type_iri) {
    {
        __auto_type seen = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
        __auto_type out = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (decode_typed_as(t, type_iri)) {
                    {
                        __auto_type s = t.subject;
                        __auto_type _mv_265 = s;
                        switch (_mv_265.tag) {
                            case rdf_Term_term_triple:
                            {
                                __auto_type _ = _mv_265.data.term_triple;
                                {
                                    __auto_type dup = 0;
                                    {
                                        __auto_type _coll = out;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type q = _coll.data[_i];
                                            if (rdf_term_eq(q, s)) {
                                                dup = 1;
                                            }
                                        }
                                    }
                                    if (!(dup)) {
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            default: {
                                if (!((slop_map_get(seen, &(s)) != NULL))) {
                                    ({ uint8_t _dummy = 1; slop_map_put(arena, seen, &(s), &_dummy); });
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
        return out;
    }
}

uint8_t decode_logical_predicate(slop_string pv) {
    if (canon_string_cmp(pv, vocab_RDFS_SUBCLASS_OF) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_EQUIVALENT_CLASS) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_DISJOINT_WITH) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_RDFS_SUBPROPERTY_OF) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_EQUIVALENT_PROPERTY) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_PROPERTY_DISJOINT_WITH) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_PROPERTY_CHAIN_AXIOM) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_INVERSE_OF) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_RDFS_DOMAIN) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_RDFS_RANGE) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_SAME_AS) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_DIFFERENT_FROM) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_HAS_KEY) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_INTERSECTION_OF) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_UNION_OF) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_COMPLEMENT_OF) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_ONE_OF) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_SOME_VALUES_FROM) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_ALL_VALUES_FROM) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_HAS_VALUE) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_HAS_SELF) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_ON_PROPERTY) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_MEMBERS) == 0) {
        return 1;
    } else if (canon_string_cmp(pv, vocab_OWL_DISTINCT_MEMBERS) == 0) {
        return 1;
    } else {
        return 0;
    }
}

rdf_Triple decode_ex_hdr(slop_string p, slop_string o) {
    return ((rdf_Triple){.subject = ((rdf_Term){ .tag = rdf_Term_term_blank, .data.term_blank = ((rdf_BlankNode){.id = 7}) }), .predicate = ((rdf_Term){ .tag = rdf_Term_term_iri, .data.term_iri = ((rdf_IRI){.value = p}) }), .object = ((rdf_Term){ .tag = rdf_Term_term_iri, .data.term_iri = ((rdf_IRI){.value = o}) })});
}

uint8_t decode_header_consumable(rdf_Triple t) {
    __auto_type _mv_268 = decode_term_iri_value(t.predicate);
    if (!_mv_268.has_value) {
        return 0;
    } else if (_mv_268.has_value) {
        __auto_type p = _mv_268.value;
        if (canon_string_cmp(p.value, vocab_RDF_TYPE) == 0) {
            __auto_type _mv_269 = decode_term_iri_value(t.object);
            if (!_mv_269.has_value) {
                return 0;
            } else if (_mv_269.has_value) {
                __auto_type o = _mv_269.value;
                if (canon_string_cmp(o.value, vocab_OWL_ONTOLOGY) == 0) {
                    return 1;
                } else if (canon_string_cmp(o.value, owl2_OWL_AXIOM) == 0) {
                    return 1;
                } else if (canon_string_cmp(o.value, owl2_OWL_ANNOTATION) == 0) {
                    return 1;
                } else {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else {
            return !(decode_logical_predicate(p.value));
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_decode_Stage0_types_Fault decode_stage0_header(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved) {
    {
        __auto_type ig = decode_graph_to_indexed(arena, triples);
        __auto_type ont_subjs = decode_typed_subjects_in_order(arena, triples, vocab_OWL_ONTOLOGY);
        __auto_type ax_subjs = decode_typed_subjects_in_order(arena, triples, owl2_OWL_AXIOM);
        __auto_type ann_subjs = decode_subjects_of_type(arena, ig, owl2_OWL_ANNOTATION);
        __auto_type declared = decode_collect_imports(arena, triples);
        __auto_type src_pred = rdf_make_iri(arena, owl2_OWL_ANNOTATED_SOURCE);
        __auto_type prop_pred = rdf_make_iri(arena, owl2_OWL_ANNOTATED_PROPERTY);
        __auto_type tgt_pred = rdf_make_iri(arena, owl2_OWL_ANNOTATED_TARGET);
        __auto_type out = ((slop_list_rdf_Triple){ .data = (rdf_Triple*)slop_arena_alloc(arena, 16 * sizeof(rdf_Triple)), .len = 0, .cap = 16 });
        slop_option_rdf_IRI ont = (slop_option_rdf_IRI){.has_value = false};
        slop_option_string fault = (slop_option_string){.has_value = false};
        {
            __auto_type header_subjs = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
            __auto_type quoted = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
            {
                __auto_type _coll = ont_subjs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type o = _coll.data[_i];
                    __auto_type _mv_270 = o;
                    switch (_mv_270.tag) {
                        case rdf_Term_term_triple:
                        {
                            __auto_type _ = _mv_270.data.term_triple;
                            ({ __auto_type _lst_p = &(quoted); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        default: {
                            ({ uint8_t _dummy = 1; slop_map_put(arena, header_subjs, &(o), &_dummy); });
                            break;
                        }
                    }
                }
            }
            {
                __auto_type _coll = ax_subjs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    __auto_type _mv_272 = a;
                    switch (_mv_272.tag) {
                        case rdf_Term_term_triple:
                        {
                            __auto_type _ = _mv_272.data.term_triple;
                            ({ __auto_type _lst_p = &(quoted); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        default: {
                            ({ uint8_t _dummy = 1; slop_map_put(arena, header_subjs, &(a), &_dummy); });
                            break;
                        }
                    }
                }
            }
            {
                __auto_type _coll = ann_subjs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    __auto_type _mv_274 = a;
                    switch (_mv_274.tag) {
                        case rdf_Term_term_triple:
                        {
                            __auto_type _ = _mv_274.data.term_triple;
                            ({ __auto_type _lst_p = &(quoted); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        default: {
                            ({ uint8_t _dummy = 1; slop_map_put(arena, header_subjs, &(a), &_dummy); });
                            break;
                        }
                    }
                }
            }
            {
                __auto_type _coll = triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type t = _coll.data[_i];
                    {
                        __auto_type s = t.subject;
                        uint8_t header = 0;
                        __auto_type _mv_276 = s;
                        switch (_mv_276.tag) {
                            case rdf_Term_term_triple:
                            {
                                __auto_type _ = _mv_276.data.term_triple;
                                {
                                    __auto_type _coll = quoted;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type q = _coll.data[_i];
                                        if (rdf_term_eq(q, s)) {
                                            header = 1;
                                        }
                                    }
                                }
                                break;
                            }
                            default: {
                                if (slop_map_get(header_subjs, &(s)) != NULL) {
                                    header = 1;
                                }
                                break;
                            }
                        }
                        if (!(header) || !(decode_header_consumable(t))) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        {
            __auto_type _coll = ax_subjs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_278 = decode_one_object(arena, ig, a, src_pred);
                if (!_mv_278.is_ok) {
                    __auto_type _ = _mv_278.data.err;
                    fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("owl:Axiom node without a usable owl:annotatedSource")};
                } else if (_mv_278.is_ok) {
                    __auto_type subj = _mv_278.data.ok;
                    __auto_type _mv_279 = decode_one_object(arena, ig, a, prop_pred);
                    if (!_mv_279.is_ok) {
                        __auto_type _ = _mv_279.data.err;
                        fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("owl:Axiom node without a usable owl:annotatedProperty")};
                    } else if (_mv_279.is_ok) {
                        __auto_type pred = _mv_279.data.ok;
                        __auto_type _mv_280 = decode_one_object(arena, ig, a, tgt_pred);
                        if (!_mv_280.is_ok) {
                            __auto_type _ = _mv_280.data.err;
                            fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("owl:Axiom node without a usable owl:annotatedTarget")};
                        } else if (_mv_280.is_ok) {
                            __auto_type obj = _mv_280.data.ok;
                            {
                                __auto_type rebuilt = ((rdf_Triple){.subject = subj, .predicate = pred, .object = obj});
                                if (!(termstore_store_contains(ig, rebuilt))) {
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (rebuilt); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            __auto_type _coll = ont_subjs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                __auto_type _mv_281 = decode_term_iri_value(o);
                if (_mv_281.has_value) {
                    __auto_type i = _mv_281.value;
                    ont = (slop_option_rdf_IRI){.has_value = 1, .value = i};
                } else if (!_mv_281.has_value) {
                }
            }
        }
        __auto_type _mv_282 = fault;
        if (_mv_282.has_value) {
            __auto_type msg = _mv_282.value;
            return ((slop_result_decode_Stage0_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_input_error, .data.input_error = msg }) });
        } else if (!_mv_282.has_value) {
            return ((slop_result_decode_Stage0_types_Fault){ .is_ok = true, .data.ok = ((decode_Stage0){.triples = out, .imports_declared = declared, .omissions = decode_unresolved_imports(arena, declared, imports_resolved), .ontology_iri = ont}) });
        }
        SLOP_UNREACHABLE();
    }
}

owl2_RawConcept* decode_box_concept(slop_arena* arena, owl2_RawConcept c) {
    {
        __auto_type p = ((owl2_RawConcept*)(({ __auto_type _alloc = (owl2_RawConcept*)slop_arena_alloc(arena, sizeof(owl2_RawConcept)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = c;
        return p;
    }
}

slop_string decode_list_fault_message(decode_ListFault f) {
    __auto_type _mv_283 = f;
    switch (_mv_283.tag) {
        case decode_ListFault_list_truncated:
        {
            __auto_type m = _mv_283.data.list_truncated;
            return m;
        }
        case decode_ListFault_list_branching:
        {
            __auto_type m = _mv_283.data.list_branching;
            return m;
        }
        case decode_ListFault_list_cyclic:
        {
            __auto_type m = _mv_283.data.list_cyclic;
            return m;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t decode_has_pred(slop_arena* arena, termstore_TermStore g, rdf_Term s, slop_string pred_iri) {
    return termstore_store_has_any(g, s, rdf_make_iri(arena, pred_iri));
}

slop_result_rdf_Term_decode_LookupFault decode_obj_of(slop_arena* arena, termstore_TermStore g, rdf_Term s, slop_string pred_iri) {
    return decode_one_object(arena, g, s, rdf_make_iri(arena, pred_iri));
}

slop_result_types_RoleId_string decode_decode_role(slop_arena* arena, termstore_TermStore g, rdf_Term b) {
    __auto_type _mv_284 = decode_obj_of(arena, g, b, vocab_OWL_ON_PROPERTY);
    if (!_mv_284.is_ok) {
        __auto_type _ = _mv_284.data.err;
        return ((slop_result_types_RoleId_string){ .is_ok = false, .data.err = SLOP_STR("restriction without exactly one owl:onProperty") });
    } else if (_mv_284.is_ok) {
        __auto_type pt = _mv_284.data.ok;
        __auto_type _mv_285 = decode_term_iri_value(pt);
        if (_mv_285.has_value) {
            __auto_type i = _mv_285.value;
            return ((slop_result_types_RoleId_string){ .is_ok = true, .data.ok = ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = i }) });
        } else if (!_mv_285.has_value) {
            return ((slop_result_types_RoleId_string){ .is_ok = false, .data.err = SLOP_STR("owl:onProperty is a blank node that is not an inverse property expression") });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t decode_inverse_expression_term(slop_arena* arena, termstore_TermStore g, rdf_Term t) {
    __auto_type _mv_286 = t;
    switch (_mv_286.tag) {
        case rdf_Term_term_blank:
        {
            __auto_type _ = _mv_286.data.term_blank;
            __auto_type _mv_287 = decode_obj_of(arena, g, t, vocab_OWL_INVERSE_OF);
            if (_mv_287.is_ok) {
                __auto_type pt = _mv_287.data.ok;
                __auto_type _mv_288 = decode_term_iri_value(pt);
                if (_mv_288.has_value) {
                    __auto_type _ = _mv_288.value;
                    return 1;
                } else if (!_mv_288.has_value) {
                    return 0;
                }
                SLOP_UNREACHABLE();
            } else if (!_mv_287.is_ok) {
                __auto_type _ = _mv_287.data.err;
                return 0;
            }
            SLOP_UNREACHABLE();
        }
        default: {
            return 0;
        }
    }
}

uint8_t decode_restriction_on_inverse(slop_arena* arena, termstore_TermStore g, rdf_Term b) {
    __auto_type _mv_289 = decode_obj_of(arena, g, b, vocab_OWL_ON_PROPERTY);
    if (_mv_289.is_ok) {
        __auto_type pt = _mv_289.data.ok;
        return decode_inverse_expression_term(arena, g, pt);
    } else if (!_mv_289.is_ok) {
        __auto_type _ = _mv_289.data.err;
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t decode_list_has_inverse(slop_arena* arena, termstore_TermStore g, rdf_Term head) {
    __auto_type _mv_290 = decode_rdf_list_checked(arena, g, head);
    if (!_mv_290.is_ok) {
        __auto_type _ = _mv_290.data.err;
        return 0;
    } else if (_mv_290.is_ok) {
        __auto_type terms = _mv_290.data.ok;
        {
            __auto_type found = 0;
            {
                __auto_type _coll = terms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tm = _coll.data[_i];
                    if (decode_inverse_expression_term(arena, g, tm)) {
                        found = 1;
                    }
                }
            }
            return found;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t decode_property_axiom_on_inverse(slop_arena* arena, termstore_TermStore g, slop_string pv, rdf_Triple t) {
    if (canon_string_cmp(pv, vocab_OWL_PROPERTY_CHAIN_AXIOM) == 0) {
        return (decode_inverse_expression_term(arena, g, t.subject) || decode_list_has_inverse(arena, g, t.object));
    } else if ((canon_string_cmp(pv, vocab_RDFS_SUBPROPERTY_OF) == 0) || ((canon_string_cmp(pv, vocab_OWL_EQUIVALENT_PROPERTY) == 0) || (canon_string_cmp(pv, vocab_OWL_PROPERTY_DISJOINT_WITH) == 0))) {
        return (decode_inverse_expression_term(arena, g, t.subject) || decode_inverse_expression_term(arena, g, t.object));
    } else if (canon_string_cmp(pv, vocab_OWL_INVERSE_OF) == 0) {
        return decode_inverse_expression_term(arena, g, t.object);
    } else if ((canon_string_cmp(pv, vocab_RDFS_DOMAIN) == 0) || (canon_string_cmp(pv, vocab_RDFS_RANGE) == 0)) {
        return decode_inverse_expression_term(arena, g, t.subject);
    } else {
        return 0;
    }
}

slop_result_int_string decode_literal_count(rdf_Term t) {
    __auto_type _mv_291 = t;
    switch (_mv_291.tag) {
        case rdf_Term_term_literal:
        {
            __auto_type l = _mv_291.data.term_literal;
            __auto_type _mv_292 = strlib_parse_int(l.value);
            if (_mv_292.is_ok) {
                __auto_type v = _mv_292.data.ok;
                if (((int64_t)(v)) < 0) {
                    return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality literal is negative") });
                } else {
                    return ((slop_result_int_string){ .is_ok = true, .data.ok = ((int64_t)(v)) });
                }
            } else if (!_mv_292.is_ok) {
                __auto_type _ = _mv_292.data.err;
                return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality is not an integer literal") });
            }
            SLOP_UNREACHABLE();
        }
        case rdf_Term_term_iri:
        {
            __auto_type _ = _mv_291.data.term_iri;
            return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality is an IRI, not a literal") });
        }
        case rdf_Term_term_blank:
        {
            __auto_type _ = _mv_291.data.term_blank;
            return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality is a blank node, not a literal") });
        }
        case rdf_Term_term_triple:
        {
            __auto_type _ = _mv_291.data.term_triple;
            return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality is a triple term, not a literal") });
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_list_types_Node_string decode_decode_node_list(slop_arena* arena, termstore_TermStore g, rdf_Term head) {
    __auto_type _mv_293 = decode_rdf_list_checked(arena, g, head);
    if (!_mv_293.is_ok) {
        __auto_type lf = _mv_293.data.err;
        return ((slop_result_list_types_Node_string){ .is_ok = false, .data.err = decode_list_fault_message(lf) });
    } else if (_mv_293.is_ok) {
        __auto_type terms = _mv_293.data.ok;
        {
            __auto_type out = ((slop_list_types_Node){ .data = (types_Node*)slop_arena_alloc(arena, 16 * sizeof(types_Node)), .len = 0, .cap = 16 });
            slop_option_string fault = (slop_option_string){.has_value = false};
            {
                __auto_type _coll = terms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tm = _coll.data[_i];
                    __auto_type _mv_294 = decode_term_iri_value(tm);
                    if (_mv_294.has_value) {
                        __auto_type i = _mv_294.value;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_Node){ .tag = types_Node_individual_node, .data.individual_node = i })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_294.has_value) {
                        fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("owl:oneOf member is not a named individual")};
                    }
                }
            }
            __auto_type _mv_295 = fault;
            if (_mv_295.has_value) {
                __auto_type m = _mv_295.value;
                return ((slop_result_list_types_Node_string){ .is_ok = false, .data.err = m });
            } else if (!_mv_295.has_value) {
                return ((slop_result_list_types_Node_string){ .is_ok = true, .data.ok = out });
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_list_owl2_RawConcept_string decode_decode_concept_list(slop_arena* arena, termstore_TermStore g, rdf_Term head, int64_t fuel) {
    __auto_type _mv_296 = decode_rdf_list_checked(arena, g, head);
    if (!_mv_296.is_ok) {
        __auto_type lf = _mv_296.data.err;
        return ((slop_result_list_owl2_RawConcept_string){ .is_ok = false, .data.err = decode_list_fault_message(lf) });
    } else if (_mv_296.is_ok) {
        __auto_type terms = _mv_296.data.ok;
        {
            __auto_type out = ((slop_list_owl2_RawConcept){ .data = (owl2_RawConcept*)slop_arena_alloc(arena, 16 * sizeof(owl2_RawConcept)), .len = 0, .cap = 16 });
            slop_option_string fault = (slop_option_string){.has_value = false};
            {
                __auto_type _coll = terms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tm = _coll.data[_i];
                    __auto_type _mv_297 = decode_decode_concept(arena, g, tm, (fuel - 1));
                    if (!_mv_297.is_ok) {
                        __auto_type m = _mv_297.data.err;
                        fault = (slop_option_string){.has_value = 1, .value = m};
                    } else if (_mv_297.is_ok) {
                        __auto_type c = _mv_297.data.ok;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
            __auto_type _mv_298 = fault;
            if (_mv_298.has_value) {
                __auto_type m = _mv_298.value;
                return ((slop_result_list_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (!_mv_298.has_value) {
                return ((slop_result_list_owl2_RawConcept_string){ .is_ok = true, .data.ok = out });
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_owl2_RawConcept_string decode_decode_quantified(slop_arena* arena, termstore_TermStore g, rdf_Term b, slop_string filler_pred, uint8_t universal, int64_t fuel) {
    __auto_type _mv_299 = decode_decode_role(arena, g, b);
    if (!_mv_299.is_ok) {
        __auto_type m = _mv_299.data.err;
        return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
    } else if (_mv_299.is_ok) {
        __auto_type r = _mv_299.data.ok;
        __auto_type _mv_300 = decode_obj_of(arena, g, b, filler_pred);
        if (!_mv_300.is_ok) {
            __auto_type _ = _mv_300.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("quantified restriction without exactly one filler") });
        } else if (_mv_300.is_ok) {
            __auto_type ft = _mv_300.data.ok;
            __auto_type _mv_301 = decode_decode_concept(arena, g, ft, (fuel - 1));
            if (!_mv_301.is_ok) {
                __auto_type m = _mv_301.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_301.is_ok) {
                __auto_type c = _mv_301.data.ok;
                if (universal) {
                    return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_all, .data.rc_all = { .f0 = r, .f1 = decode_box_concept(arena, c) } }) });
                } else {
                    return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_some, .data.rc_some = { .f0 = r, .f1 = decode_box_concept(arena, c) } }) });
                }
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_owl2_RawConcept_string decode_decode_cardinality(slop_arena* arena, termstore_TermStore g, rdf_Term b, owl2_CardKind kind, slop_string count_pred, uint8_t qualified, int64_t fuel) {
    __auto_type _mv_302 = decode_decode_role(arena, g, b);
    if (!_mv_302.is_ok) {
        __auto_type m = _mv_302.data.err;
        return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
    } else if (_mv_302.is_ok) {
        __auto_type r = _mv_302.data.ok;
        __auto_type _mv_303 = decode_obj_of(arena, g, b, count_pred);
        if (!_mv_303.is_ok) {
            __auto_type _ = _mv_303.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("cardinality restriction without exactly one count") });
        } else if (_mv_303.is_ok) {
            __auto_type ct = _mv_303.data.ok;
            __auto_type _mv_304 = decode_literal_count(ct);
            if (!_mv_304.is_ok) {
                __auto_type m = _mv_304.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_304.is_ok) {
                __auto_type n = _mv_304.data.ok;
                if (!(qualified)) {
                    return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_card, .data.rc_card = { .f0 = kind, .f1 = r, .f2 = n } }) });
                } else {
                    __auto_type _mv_305 = decode_obj_of(arena, g, b, vocab_OWL_ON_CLASS);
                    if (!_mv_305.is_ok) {
                        __auto_type _ = _mv_305.data.err;
                        return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("qualified cardinality without exactly one owl:onClass") });
                    } else if (_mv_305.is_ok) {
                        __auto_type qt = _mv_305.data.ok;
                        __auto_type _mv_306 = decode_decode_concept(arena, g, qt, (fuel - 1));
                        if (!_mv_306.is_ok) {
                            __auto_type m = _mv_306.data.err;
                            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
                        } else if (_mv_306.is_ok) {
                            __auto_type qc = _mv_306.data.ok;
                            return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_qcard, .data.rc_qcard = { .f0 = kind, .f1 = r, .f2 = n, .f3 = decode_box_concept(arena, qc) } }) });
                        }
                        SLOP_UNREACHABLE();
                    }
                    SLOP_UNREACHABLE();
                }
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_owl2_RawConcept_string decode_decode_anon(slop_arena* arena, termstore_TermStore g, rdf_Term b, int64_t fuel) {
    if (decode_restriction_on_inverse(arena, g, b)) {
        return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_anon, .data.rc_anon = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("restriction on an ObjectInverseOf property") }) }) });
    } else if (decode_has_pred(arena, g, b, vocab_OWL_INTERSECTION_OF)) {
        __auto_type _mv_307 = decode_obj_of(arena, g, b, vocab_OWL_INTERSECTION_OF);
        if (!_mv_307.is_ok) {
            __auto_type _ = _mv_307.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:intersectionOf is absent or ambiguous") });
        } else if (_mv_307.is_ok) {
            __auto_type head = _mv_307.data.ok;
            __auto_type _mv_308 = decode_decode_concept_list(arena, g, head, fuel);
            if (!_mv_308.is_ok) {
                __auto_type m = _mv_308.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_308.is_ok) {
                __auto_type cs = _mv_308.data.ok;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_and, .data.rc_and = cs }) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    } else if (decode_has_pred(arena, g, b, vocab_OWL_UNION_OF)) {
        __auto_type _mv_309 = decode_obj_of(arena, g, b, vocab_OWL_UNION_OF);
        if (!_mv_309.is_ok) {
            __auto_type _ = _mv_309.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:unionOf is absent or ambiguous") });
        } else if (_mv_309.is_ok) {
            __auto_type head = _mv_309.data.ok;
            __auto_type _mv_310 = decode_decode_concept_list(arena, g, head, fuel);
            if (!_mv_310.is_ok) {
                __auto_type m = _mv_310.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_310.is_ok) {
                __auto_type cs = _mv_310.data.ok;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_or, .data.rc_or = cs }) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    } else if (decode_has_pred(arena, g, b, vocab_OWL_ONE_OF)) {
        __auto_type _mv_311 = decode_obj_of(arena, g, b, vocab_OWL_ONE_OF);
        if (!_mv_311.is_ok) {
            __auto_type _ = _mv_311.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:oneOf is absent or ambiguous") });
        } else if (_mv_311.is_ok) {
            __auto_type head = _mv_311.data.ok;
            __auto_type _mv_312 = decode_decode_node_list(arena, g, head);
            if (!_mv_312.is_ok) {
                __auto_type m = _mv_312.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_312.is_ok) {
                __auto_type ns = _mv_312.data.ok;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_oneof, .data.rc_oneof = ns }) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    } else if (decode_has_pred(arena, g, b, vocab_OWL_COMPLEMENT_OF)) {
        __auto_type _mv_313 = decode_obj_of(arena, g, b, vocab_OWL_COMPLEMENT_OF);
        if (!_mv_313.is_ok) {
            __auto_type _ = _mv_313.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:complementOf is absent or ambiguous") });
        } else if (_mv_313.is_ok) {
            __auto_type ct = _mv_313.data.ok;
            __auto_type _mv_314 = decode_decode_concept(arena, g, ct, (fuel - 1));
            if (!_mv_314.is_ok) {
                __auto_type m = _mv_314.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_314.is_ok) {
                __auto_type c = _mv_314.data.ok;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_not, .data.rc_not = decode_box_concept(arena, c) }) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    } else if (decode_has_pred(arena, g, b, vocab_OWL_SOME_VALUES_FROM)) {
        return decode_decode_quantified(arena, g, b, vocab_OWL_SOME_VALUES_FROM, 0, fuel);
    } else if (decode_has_pred(arena, g, b, vocab_OWL_ALL_VALUES_FROM)) {
        return decode_decode_quantified(arena, g, b, vocab_OWL_ALL_VALUES_FROM, 1, fuel);
    } else if (decode_has_pred(arena, g, b, vocab_OWL_HAS_VALUE)) {
        __auto_type _mv_315 = decode_decode_role(arena, g, b);
        if (!_mv_315.is_ok) {
            __auto_type m = _mv_315.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
        } else if (_mv_315.is_ok) {
            __auto_type r = _mv_315.data.ok;
            __auto_type _mv_316 = decode_obj_of(arena, g, b, vocab_OWL_HAS_VALUE);
            if (!_mv_316.is_ok) {
                __auto_type _ = _mv_316.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:hasValue is absent or ambiguous") });
            } else if (_mv_316.is_ok) {
                __auto_type vt = _mv_316.data.ok;
                __auto_type _mv_317 = decode_term_iri_value(vt);
                if (_mv_317.has_value) {
                    __auto_type i = _mv_317.value;
                    return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_has_value, .data.rc_has_value = { .f0 = r, .f1 = ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = i }) } }) });
                } else if (!_mv_317.has_value) {
                    return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_anon, .data.rc_anon = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("owl:hasValue on an anonymous individual") }) }) });
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    } else if (decode_has_pred(arena, g, b, vocab_OWL_HAS_SELF)) {
        __auto_type _mv_318 = decode_decode_role(arena, g, b);
        if (!_mv_318.is_ok) {
            __auto_type m = _mv_318.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
        } else if (_mv_318.is_ok) {
            __auto_type r = _mv_318.data.ok;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_has_self, .data.rc_has_self = r }) });
        }
        SLOP_UNREACHABLE();
    } else if (decode_has_pred(arena, g, b, vocab_OWL_QUALIFIED_CARDINALITY)) {
        return decode_decode_cardinality(arena, g, b, owl2_CardKind_card_exact, vocab_OWL_QUALIFIED_CARDINALITY, 1, fuel);
    } else if (decode_has_pred(arena, g, b, vocab_OWL_MIN_QUALIFIED_CARDINALITY)) {
        return decode_decode_cardinality(arena, g, b, owl2_CardKind_card_min, vocab_OWL_MIN_QUALIFIED_CARDINALITY, 1, fuel);
    } else if (decode_has_pred(arena, g, b, vocab_OWL_MAX_QUALIFIED_CARDINALITY)) {
        return decode_decode_cardinality(arena, g, b, owl2_CardKind_card_max, vocab_OWL_MAX_QUALIFIED_CARDINALITY, 1, fuel);
    } else if (decode_has_pred(arena, g, b, vocab_OWL_CARDINALITY)) {
        return decode_decode_cardinality(arena, g, b, owl2_CardKind_card_exact, vocab_OWL_CARDINALITY, 0, fuel);
    } else if (decode_has_pred(arena, g, b, vocab_OWL_MIN_CARDINALITY)) {
        return decode_decode_cardinality(arena, g, b, owl2_CardKind_card_min, vocab_OWL_MIN_CARDINALITY, 0, fuel);
    } else if (decode_has_pred(arena, g, b, vocab_OWL_MAX_CARDINALITY)) {
        return decode_decode_cardinality(arena, g, b, owl2_CardKind_card_max, vocab_OWL_MAX_CARDINALITY, 0, fuel);
    } else {
        return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_anon, .data.rc_anon = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("blank node with no recognized class-expression vocabulary") }) }) });
    }
}

slop_result_owl2_RawConcept_string decode_decode_concept(slop_arena* arena, termstore_TermStore g, rdf_Term t, int64_t fuel) {
    if (fuel <= 0) {
        return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("class expression nests past the fuel bound — a blank-node cycle") });
    } else {
        __auto_type _mv_319 = t;
        switch (_mv_319.tag) {
            case rdf_Term_term_iri:
            {
                __auto_type i = _mv_319.data.term_iri;
                if (canon_string_cmp(i.value, vocab_OWL_THING) == 0) {
                    return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_thing }) });
                } else if (canon_string_cmp(i.value, vocab_OWL_NOTHING) == 0) {
                    return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_nothing }) });
                } else {
                    return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_name, .data.rc_name = ((types_Node){ .tag = types_Node_class_node, .data.class_node = i }) }) });
                }
            }
            case rdf_Term_term_literal:
            {
                __auto_type _ = _mv_319.data.term_literal;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_data, .data.rc_data = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("literal in a class position") }) }) });
            }
            case rdf_Term_term_triple:
            {
                __auto_type _ = _mv_319.data.term_triple;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_anon, .data.rc_anon = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("RDF-star triple term in a class position") }) }) });
            }
            case rdf_Term_term_blank:
            {
                __auto_type _ = _mv_319.data.term_blank;
                return decode_decode_anon(arena, g, t, fuel);
            }
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t decode_declare_entity(slop_arena* arena, owl2_Signature sig, rdf_IRI entity, slop_string type_iri) {
    if (canon_string_cmp(type_iri, vocab_OWL_CLASS) == 0) {
        ({ uint8_t _dummy = 1; slop_map_put(arena, sig.classes, &(entity), &_dummy); });
        return 1;
    } else if (canon_string_cmp(type_iri, vocab_OWL_OBJECT_PROPERTY) == 0) {
        ({ uint8_t _dummy = 1; slop_map_put(arena, sig.obj_props, &(entity), &_dummy); });
        return 1;
    } else if (canon_string_cmp(type_iri, vocab_OWL_DATATYPE_PROPERTY) == 0) {
        ({ uint8_t _dummy = 1; slop_map_put(arena, sig.data_props, &(entity), &_dummy); });
        return 1;
    } else if (canon_string_cmp(type_iri, vocab_OWL_ANNOTATION_PROPERTY) == 0) {
        ({ uint8_t _dummy = 1; slop_map_put(arena, sig.annot_props, &(entity), &_dummy); });
        return 1;
    } else if (canon_string_cmp(type_iri, vocab_OWL_NAMED_INDIVIDUAL) == 0) {
        ({ uint8_t _dummy = 1; slop_map_put(arena, sig.individuals, &(entity), &_dummy); });
        return 1;
    } else if (canon_string_cmp(type_iri, vocab_RDFS_DATATYPE) == 0) {
        ({ uint8_t _dummy = 1; slop_map_put(arena, sig.datatypes, &(entity), &_dummy); });
        return 1;
    } else {
        return 0;
    }
}

uint8_t decode_add_builtins(slop_arena* arena, owl2_Signature sig) {
    ({ rdf_IRI _key_326 = (((rdf_IRI){.value = vocab_OWL_THING})); uint8_t _dummy = 1; slop_map_put(arena, sig.classes, &_key_326, &_dummy); });
    ({ rdf_IRI _key_327 = (((rdf_IRI){.value = vocab_OWL_NOTHING})); uint8_t _dummy = 1; slop_map_put(arena, sig.classes, &_key_327, &_dummy); });
    ({ rdf_IRI _key_328 = (((rdf_IRI){.value = owl2_OWL_TOP_OBJECT_PROPERTY})); uint8_t _dummy = 1; slop_map_put(arena, sig.obj_props, &_key_328, &_dummy); });
    ({ rdf_IRI _key_329 = (((rdf_IRI){.value = owl2_OWL_BOTTOM_OBJECT_PROPERTY})); uint8_t _dummy = 1; slop_map_put(arena, sig.obj_props, &_key_329, &_dummy); });
    ({ rdf_IRI _key_330 = (((rdf_IRI){.value = owl2_OWL_TOP_DATA_PROPERTY})); uint8_t _dummy = 1; slop_map_put(arena, sig.data_props, &_key_330, &_dummy); });
    ({ rdf_IRI _key_331 = (((rdf_IRI){.value = owl2_OWL_BOTTOM_DATA_PROPERTY})); uint8_t _dummy = 1; slop_map_put(arena, sig.data_props, &_key_331, &_dummy); });
    ({ rdf_IRI _key_332 = (((rdf_IRI){.value = vocab_RDFS_LABEL})); uint8_t _dummy = 1; slop_map_put(arena, sig.annot_props, &_key_332, &_dummy); });
    ({ rdf_IRI _key_333 = (((rdf_IRI){.value = vocab_RDFS_COMMENT})); uint8_t _dummy = 1; slop_map_put(arena, sig.annot_props, &_key_333, &_dummy); });
    ({ rdf_IRI _key_334 = (((rdf_IRI){.value = vocab_RDFS_SEE_ALSO})); uint8_t _dummy = 1; slop_map_put(arena, sig.annot_props, &_key_334, &_dummy); });
    ({ rdf_IRI _key_335 = (((rdf_IRI){.value = vocab_RDFS_IS_DEFINED_BY})); uint8_t _dummy = 1; slop_map_put(arena, sig.annot_props, &_key_335, &_dummy); });
    ({ rdf_IRI _key_336 = (((rdf_IRI){.value = vocab_OWL_VERSION_INFO})); uint8_t _dummy = 1; slop_map_put(arena, sig.annot_props, &_key_336, &_dummy); });
    ({ rdf_IRI _key_337 = (((rdf_IRI){.value = vocab_OWL_DEPRECATED})); uint8_t _dummy = 1; slop_map_put(arena, sig.annot_props, &_key_337, &_dummy); });
    ({ rdf_IRI _key_338 = (((rdf_IRI){.value = vocab_OWL_PRIOR_VERSION})); uint8_t _dummy = 1; slop_map_put(arena, sig.annot_props, &_key_338, &_dummy); });
    ({ rdf_IRI _key_339 = (((rdf_IRI){.value = vocab_OWL_BACKWARD_COMPATIBLE_WITH})); uint8_t _dummy = 1; slop_map_put(arena, sig.annot_props, &_key_339, &_dummy); });
    ({ rdf_IRI _key_340 = (((rdf_IRI){.value = vocab_OWL_INCOMPATIBLE_WITH})); uint8_t _dummy = 1; slop_map_put(arena, sig.annot_props, &_key_340, &_dummy); });
    return 1;
}

owl2_Signature decode_build_signature(slop_arena* arena, slop_list_rdf_Triple triples) {
    {
        __auto_type sig = owl2_make_signature(arena);
        __auto_type type_pred = rdf_make_iri(arena, vocab_RDF_TYPE);
        decode_add_builtins(arena, sig);
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (rdf_term_eq(t.predicate, type_pred)) {
                    __auto_type _mv_341 = decode_term_iri_value(t.subject);
                    if (_mv_341.has_value) {
                        __auto_type s = _mv_341.value;
                        __auto_type _mv_342 = decode_term_iri_value(t.object);
                        if (_mv_342.has_value) {
                            __auto_type o = _mv_342.value;
                            decode_declare_entity(arena, sig, s, o.value);
                        } else if (!_mv_342.has_value) {
                            0;
                        }
                    } else if (!_mv_341.has_value) {
                        0;
                    }
                }
            }
        }
        return sig;
    }
}

slop_string decode_render_term(slop_arena* arena, rdf_Term t) {
    __auto_type _mv_343 = t;
    switch (_mv_343.tag) {
        case rdf_Term_term_iri:
        {
            __auto_type i = _mv_343.data.term_iri;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">")));
        }
        case rdf_Term_term_blank:
        {
            __auto_type b = _mv_343.data.term_blank;
            return string_concat(arena, SLOP_STR("_:b"), int_to_string(arena, b.id));
        }
        case rdf_Term_term_literal:
        {
            __auto_type l = _mv_343.data.term_literal;
            return string_concat(arena, SLOP_STR("\""), string_concat(arena, l.value, SLOP_STR("\"")));
        }
        case rdf_Term_term_triple:
        {
            __auto_type _ = _mv_343.data.term_triple;
            return SLOP_STR("<<embedded triple>>");
        }
    }
    SLOP_UNREACHABLE();
}

slop_string decode_render_triple(slop_arena* arena, rdf_Triple t) {
    return string_concat(arena, decode_render_term(arena, t.subject), string_concat(arena, SLOP_STR(" "), string_concat(arena, decode_render_term(arena, t.predicate), string_concat(arena, SLOP_STR(" "), string_concat(arena, decode_render_term(arena, t.object), SLOP_STR(" ."))))));
}

types_InputRef decode_frag(slop_arena* arena, rdf_Triple t) {
    return ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = decode_render_triple(arena, t) });
}

uint8_t decode_is_pred(rdf_Triple t, slop_string iri) {
    __auto_type _mv_344 = decode_term_iri_value(t.predicate);
    if (_mv_344.has_value) {
        __auto_type i = _mv_344.value;
        return (canon_string_cmp(i.value, iri) == 0);
    } else if (!_mv_344.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t decode_structural_predicate(slop_string p) {
    if (canon_string_cmp(p, vocab_RDF_FIRST) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_RDF_REST) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_INTERSECTION_OF) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_UNION_OF) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_ONE_OF) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_COMPLEMENT_OF) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_SOME_VALUES_FROM) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_ALL_VALUES_FROM) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_HAS_VALUE) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_HAS_SELF) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_ON_PROPERTY) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_ON_CLASS) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_ON_DATA_RANGE) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_ON_DATATYPE) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_DATATYPE_COMPLEMENT_OF) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_MIN_CARDINALITY) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_MAX_CARDINALITY) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_CARDINALITY) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_MIN_QUALIFIED_CARDINALITY) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_MAX_QUALIFIED_CARDINALITY) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_QUALIFIED_CARDINALITY) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_MEMBERS) == 0) {
        return 1;
    } else if (canon_string_cmp(p, vocab_OWL_DISTINCT_MEMBERS) == 0) {
        return 1;
    } else {
        return 0;
    }
}

uint8_t decode_structural_triple(rdf_Triple t) {
    if (({ __auto_type _mv = decode_term_iri_value(t.predicate); _mv.has_value ? ({ __auto_type i = _mv.value; decode_structural_predicate(i.value); }) : (0); })) {
        return 1;
    } else {
        if (!(decode_is_pred(t, vocab_RDF_TYPE))) {
            return (decode_is_pred(t, vocab_OWL_INVERSE_OF) && ({ __auto_type _mv = t.subject; uint8_t _mr = {0}; switch (_mv.tag) { case rdf_Term_term_blank: { __auto_type _ = _mv.data.term_blank; _mr = 1; break; } case rdf_Term_term_iri: { __auto_type _ = _mv.data.term_iri; _mr = 0; break; } case rdf_Term_term_literal: { __auto_type _ = _mv.data.term_literal; _mr = 0; break; } case rdf_Term_term_triple: { __auto_type _ = _mv.data.term_triple; _mr = 0; break; }  } _mr; }));
        } else {
            __auto_type _mv_345 = decode_term_iri_value(t.object);
            if (_mv_345.has_value) {
                __auto_type o = _mv_345.value;
                return (({ __auto_type _mv = t.subject; uint8_t _mr = {0}; switch (_mv.tag) { case rdf_Term_term_blank: { __auto_type _ = _mv.data.term_blank; _mr = 1; break; } case rdf_Term_term_iri: { __auto_type _ = _mv.data.term_iri; _mr = 0; break; } case rdf_Term_term_literal: { __auto_type _ = _mv.data.term_literal; _mr = 0; break; } case rdf_Term_term_triple: { __auto_type _ = _mv.data.term_triple; _mr = 0; break; }  } _mr; }) && ((canon_string_cmp(o.value, vocab_OWL_CLASS) == 0) || (canon_string_cmp(o.value, vocab_OWL_RESTRICTION) == 0)));
            } else if (!_mv_345.has_value) {
                return 0;
            }
            SLOP_UNREACHABLE();
        }
    }
}

slop_option_types_EntityKind decode_entity_kind_of(slop_string type_iri) {
    if (canon_string_cmp(type_iri, vocab_OWL_CLASS) == 0) {
        return (slop_option_types_EntityKind){.has_value = 1, .value = types_EntityKind_entity_class};
    } else if (canon_string_cmp(type_iri, vocab_OWL_OBJECT_PROPERTY) == 0) {
        return (slop_option_types_EntityKind){.has_value = 1, .value = types_EntityKind_entity_object_property};
    } else if (canon_string_cmp(type_iri, vocab_OWL_DATATYPE_PROPERTY) == 0) {
        return (slop_option_types_EntityKind){.has_value = 1, .value = types_EntityKind_entity_data_property};
    } else if (canon_string_cmp(type_iri, vocab_OWL_ANNOTATION_PROPERTY) == 0) {
        return (slop_option_types_EntityKind){.has_value = 1, .value = types_EntityKind_entity_annotation_property};
    } else if (canon_string_cmp(type_iri, vocab_OWL_NAMED_INDIVIDUAL) == 0) {
        return (slop_option_types_EntityKind){.has_value = 1, .value = types_EntityKind_entity_individual};
    } else if (canon_string_cmp(type_iri, vocab_RDFS_DATATYPE) == 0) {
        return (slop_option_types_EntityKind){.has_value = 1, .value = types_EntityKind_entity_datatype};
    } else {
        return (slop_option_types_EntityKind){.has_value = false};
    }
}

slop_option_owl2_PropCharacteristic decode_characteristic_of(slop_string type_iri) {
    if (canon_string_cmp(type_iri, vocab_OWL_FUNCTIONAL_PROPERTY) == 0) {
        return (slop_option_owl2_PropCharacteristic){.has_value = 1, .value = owl2_PropCharacteristic_prop_functional};
    } else if (canon_string_cmp(type_iri, vocab_OWL_INVERSE_FUNCTIONAL_PROPERTY) == 0) {
        return (slop_option_owl2_PropCharacteristic){.has_value = 1, .value = owl2_PropCharacteristic_prop_inverse_functional};
    } else if (canon_string_cmp(type_iri, vocab_OWL_SYMMETRIC_PROPERTY) == 0) {
        return (slop_option_owl2_PropCharacteristic){.has_value = 1, .value = owl2_PropCharacteristic_prop_symmetric};
    } else if (canon_string_cmp(type_iri, vocab_OWL_ASYMMETRIC_PROPERTY) == 0) {
        return (slop_option_owl2_PropCharacteristic){.has_value = 1, .value = owl2_PropCharacteristic_prop_asymmetric};
    } else if (canon_string_cmp(type_iri, vocab_OWL_REFLEXIVE_PROPERTY) == 0) {
        return (slop_option_owl2_PropCharacteristic){.has_value = 1, .value = owl2_PropCharacteristic_prop_reflexive};
    } else if (canon_string_cmp(type_iri, vocab_OWL_IRREFLEXIVE_PROPERTY) == 0) {
        return (slop_option_owl2_PropCharacteristic){.has_value = 1, .value = owl2_PropCharacteristic_prop_irreflexive};
    } else {
        return (slop_option_owl2_PropCharacteristic){.has_value = false};
    }
}

slop_option_types_RoleId decode_role_of_term(rdf_Term t) {
    __auto_type _mv_346 = decode_term_iri_value(t);
    if (_mv_346.has_value) {
        __auto_type i = _mv_346.value;
        return (slop_option_types_RoleId){.has_value = 1, .value = ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = i })};
    } else if (!_mv_346.has_value) {
        return (slop_option_types_RoleId){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

slop_result_list_types_RoleId_string decode_decode_role_list(slop_arena* arena, termstore_TermStore g, rdf_Term head) {
    __auto_type _mv_347 = decode_rdf_list_checked(arena, g, head);
    if (!_mv_347.is_ok) {
        __auto_type lf = _mv_347.data.err;
        return ((slop_result_list_types_RoleId_string){ .is_ok = false, .data.err = decode_list_fault_message(lf) });
    } else if (_mv_347.is_ok) {
        __auto_type terms = _mv_347.data.ok;
        {
            __auto_type out = ((slop_list_types_RoleId){ .data = (types_RoleId*)slop_arena_alloc(arena, 16 * sizeof(types_RoleId)), .len = 0, .cap = 16 });
            slop_option_string fault = (slop_option_string){.has_value = false};
            {
                __auto_type _coll = terms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tm = _coll.data[_i];
                    __auto_type _mv_348 = decode_role_of_term(tm);
                    if (_mv_348.has_value) {
                        __auto_type r = _mv_348.value;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_348.has_value) {
                        fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("property chain step is not a named property")};
                    }
                }
            }
            __auto_type _mv_349 = fault;
            if (_mv_349.has_value) {
                __auto_type m = _mv_349.value;
                return ((slop_result_list_types_RoleId_string){ .is_ok = false, .data.err = m });
            } else if (!_mv_349.has_value) {
                return ((slop_result_list_types_RoleId_string){ .is_ok = true, .data.ok = out });
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_list_owl2_RawConcept_string decode_binary_concepts(slop_arena* arena, termstore_TermStore g, rdf_Triple t) {
    __auto_type _mv_350 = decode_decode_concept(arena, g, t.subject, decode_CONCEPT_FUEL);
    if (!_mv_350.is_ok) {
        __auto_type m = _mv_350.data.err;
        return ((slop_result_list_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
    } else if (_mv_350.is_ok) {
        __auto_type lhs = _mv_350.data.ok;
        __auto_type _mv_351 = decode_decode_concept(arena, g, t.object, decode_CONCEPT_FUEL);
        if (!_mv_351.is_ok) {
            __auto_type m = _mv_351.data.err;
            return ((slop_result_list_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
        } else if (_mv_351.is_ok) {
            __auto_type rhs = _mv_351.data.ok;
            {
                __auto_type out = ((slop_list_owl2_RawConcept){ .data = (owl2_RawConcept*)slop_arena_alloc(arena, 16 * sizeof(owl2_RawConcept)), .len = 0, .cap = 16 });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (lhs); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (rhs); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                return ((slop_result_list_owl2_RawConcept_string){ .is_ok = true, .data.ok = out });
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_option_rdf_Term decode_members_head(slop_arena* arena, termstore_TermStore g, rdf_Term s) {
    __auto_type _mv_352 = decode_obj_of(arena, g, s, vocab_OWL_MEMBERS);
    if (_mv_352.is_ok) {
        __auto_type h = _mv_352.data.ok;
        return (slop_option_rdf_Term){.has_value = 1, .value = h};
    } else if (!_mv_352.is_ok) {
        __auto_type _ = _mv_352.data.err;
        __auto_type _mv_353 = decode_obj_of(arena, g, s, vocab_OWL_DISTINCT_MEMBERS);
        if (_mv_353.is_ok) {
            __auto_type h = _mv_353.data.ok;
            return (slop_option_rdf_Term){.has_value = 1, .value = h};
        } else if (!_mv_353.is_ok) {
            __auto_type _ = _mv_353.data.err;
            return (slop_option_rdf_Term){.has_value = false};
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_owl2_RawAxiom_string decode_decode_typed(slop_arena* arena, termstore_TermStore g, rdf_Triple t, rdf_IRI obj) {
    {
        __auto_type ov = obj.value;
        if (({ __auto_type _mv = decode_entity_kind_of(ov); _mv.has_value ? ({ __auto_type _ = _mv.value; 1; }) : (0); })) {
            __auto_type _mv_354 = decode_term_iri_value(t.subject);
            if (_mv_354.has_value) {
                __auto_type s = _mv_354.value;
                __auto_type _mv_355 = decode_entity_kind_of(ov);
                if (_mv_355.has_value) {
                    __auto_type k = _mv_355.value;
                    if ((k == types_EntityKind_entity_individual) && decode_is_reserved_iri(s.value)) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = decode_frag(arena, t) }) });
                    } else {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_declaration, .data.ra_declaration = ((owl2_RawDeclaration){.kind = k, .entity = s}) }) });
                    }
                } else if (!_mv_355.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("unreachable: declaration type vanished") });
                }
                SLOP_UNREACHABLE();
            } else if (!_mv_354.has_value) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = decode_frag(arena, t) }) });
            }
            SLOP_UNREACHABLE();
        } else if (canon_string_cmp(ov, vocab_OWL_TRANSITIVE_PROPERTY) == 0) {
            __auto_type _mv_356 = decode_role_of_term(t.subject);
            if (_mv_356.has_value) {
                __auto_type r = _mv_356.value;
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_transitive_property, .data.ra_transitive_property = r }) });
            } else if (!_mv_356.has_value) {
                if (decode_inverse_expression_term(arena, g, t.subject)) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inverse_expression, .data.ra_inverse_expression = decode_frag(arena, t) }) });
                } else {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:TransitiveProperty on a non-IRI subject") });
                }
            }
            SLOP_UNREACHABLE();
        } else if (({ __auto_type _mv = decode_characteristic_of(ov); _mv.has_value ? ({ __auto_type _ = _mv.value; 1; }) : (0); })) {
            __auto_type _mv_357 = decode_role_of_term(t.subject);
            if (_mv_357.has_value) {
                __auto_type r = _mv_357.value;
                __auto_type _mv_358 = decode_characteristic_of(ov);
                if (_mv_358.has_value) {
                    __auto_type c = _mv_358.value;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_property_characteristic, .data.ra_property_characteristic = { .f0 = c, .f1 = r } }) });
                } else if (!_mv_358.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("unreachable: characteristic vanished") });
                }
                SLOP_UNREACHABLE();
            } else if (!_mv_357.has_value) {
                if (decode_inverse_expression_term(arena, g, t.subject)) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inverse_expression, .data.ra_inverse_expression = decode_frag(arena, t) }) });
                } else {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("property characteristic on a non-IRI subject") });
                }
            }
            SLOP_UNREACHABLE();
        } else if (canon_string_cmp(ov, vocab_OWL_ALL_DIFFERENT) == 0) {
            __auto_type _mv_359 = decode_members_head(arena, g, t.subject);
            if (!_mv_359.has_value) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:AllDifferent without owl:members or owl:distinctMembers") });
            } else if (_mv_359.has_value) {
                __auto_type head = _mv_359.value;
                __auto_type _mv_360 = decode_decode_node_list(arena, g, head);
                if (!_mv_360.is_ok) {
                    __auto_type m = _mv_360.data.err;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                } else if (_mv_360.is_ok) {
                    __auto_type ns = _mv_360.data.ok;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_different_individuals, .data.ra_different_individuals = ns }) });
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        } else if (canon_string_cmp(ov, vocab_OWL_ALL_DISJOINT_CLASSES) == 0) {
            __auto_type _mv_361 = decode_members_head(arena, g, t.subject);
            if (!_mv_361.has_value) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:AllDisjointClasses without owl:members") });
            } else if (_mv_361.has_value) {
                __auto_type head = _mv_361.value;
                __auto_type _mv_362 = decode_decode_concept_list(arena, g, head, decode_CONCEPT_FUEL);
                if (!_mv_362.is_ok) {
                    __auto_type m = _mv_362.data.err;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                } else if (_mv_362.is_ok) {
                    __auto_type cs = _mv_362.data.ok;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_classes, .data.ra_disjoint_classes = cs }) });
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        } else if (canon_string_cmp(ov, vocab_OWL_ALL_DISJOINT_PROPERTIES) == 0) {
            __auto_type _mv_363 = decode_members_head(arena, g, t.subject);
            if (!_mv_363.has_value) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:AllDisjointProperties without owl:members") });
            } else if (_mv_363.has_value) {
                __auto_type head = _mv_363.value;
                if (decode_list_has_inverse(arena, g, head)) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inverse_expression, .data.ra_inverse_expression = decode_frag(arena, t) }) });
                } else {
                    __auto_type _mv_364 = decode_decode_role_list(arena, g, head);
                    if (!_mv_364.is_ok) {
                        __auto_type m = _mv_364.data.err;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                    } else if (_mv_364.is_ok) {
                        __auto_type rs = _mv_364.data.ok;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_properties, .data.ra_disjoint_properties = rs }) });
                    }
                    SLOP_UNREACHABLE();
                }
            }
            SLOP_UNREACHABLE();
        } else if (canon_string_cmp(ov, vocab_OWL_NEGATIVE_PROPERTY_ASSERTION) == 0) {
            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_negative_assertion, .data.ra_negative_assertion = decode_frag(arena, t) }) });
        } else if (canon_string_cmp(ov, owl2_SWRL_IMP) == 0) {
            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_swrl_rule, .data.ra_swrl_rule = decode_frag(arena, t) }) });
        } else {
            return decode_decode_class_assertion(arena, g, t);
        }
    }
}

slop_result_owl2_RawAxiom_string decode_decode_class_assertion(slop_arena* arena, termstore_TermStore g, rdf_Triple t) {
    __auto_type _mv_365 = decode_decode_concept(arena, g, t.object, decode_CONCEPT_FUEL);
    if (!_mv_365.is_ok) {
        __auto_type m = _mv_365.data.err;
        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_365.is_ok) {
        __auto_type c = _mv_365.data.ok;
        __auto_type _mv_366 = decode_term_iri_value(t.subject);
        if (_mv_366.has_value) {
            __auto_type s = _mv_366.value;
            if (decode_is_reserved_iri(s.value)) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = decode_frag(arena, t) }) });
            } else {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_class_assertion, .data.ra_class_assertion = ((owl2_RawClassAssertion){.concept = decode_box_concept(arena, c), .subject = ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = s })}) }) });
            }
        } else if (!_mv_366.has_value) {
            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = decode_frag(arena, t) }) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t decode_is_reserved_iri(slop_string v) {
    return (strlib_starts_with(v, SLOP_STR("http://www.w3.org/2002/07/owl#")) || (strlib_starts_with(v, SLOP_STR("http://www.w3.org/1999/02/22-rdf-syntax-ns#")) || (strlib_starts_with(v, SLOP_STR("http://www.w3.org/2000/01/rdf-schema#")) || (strlib_starts_with(v, SLOP_STR("http://www.w3.org/2003/11/swrl#")) || strlib_starts_with(v, SLOP_STR("http://www.w3.org/2001/XMLSchema#"))))));
}

int64_t decode_property_axiom_kind(owl2_Signature sig, rdf_Term subj) {
    __auto_type _mv_367 = decode_term_iri_value(subj);
    if (!_mv_367.has_value) {
        return 0;
    } else if (_mv_367.has_value) {
        __auto_type i = _mv_367.value;
        if (owl2_signature_has_annotation_property(sig, i)) {
            return 1;
        } else if (owl2_signature_has_data_property(sig, i)) {
            return 2;
        } else {
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_owl2_RawAxiom_string decode_decode_axiom(slop_arena* arena, termstore_TermStore g, owl2_Signature sig, rdf_Triple t) {
    __auto_type _mv_368 = decode_term_iri_value(t.predicate);
    if (!_mv_368.has_value) {
        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = decode_frag(arena, t) }) });
    } else if (_mv_368.has_value) {
        __auto_type p = _mv_368.value;
        {
            __auto_type pv = p.value;
            if (canon_string_cmp(pv, vocab_RDF_TYPE) == 0) {
                __auto_type _mv_369 = t.object;
                switch (_mv_369.tag) {
                    case rdf_Term_term_iri:
                    {
                        __auto_type o = _mv_369.data.term_iri;
                        return decode_decode_typed(arena, g, t, o);
                    }
                    case rdf_Term_term_blank:
                    {
                        __auto_type _ = _mv_369.data.term_blank;
                        return decode_decode_class_assertion(arena, g, t);
                    }
                    default: {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = decode_frag(arena, t) }) });
                    }
                }
            } else if (decode_property_axiom_on_inverse(arena, g, pv, t)) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inverse_expression, .data.ra_inverse_expression = decode_frag(arena, t) }) });
            } else if (canon_string_cmp(pv, vocab_RDFS_SUBCLASS_OF) == 0) {
                __auto_type _mv_370 = decode_decode_concept(arena, g, t.subject, decode_CONCEPT_FUEL);
                if (!_mv_370.is_ok) {
                    __auto_type m = _mv_370.data.err;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                } else if (_mv_370.is_ok) {
                    __auto_type lhs = _mv_370.data.ok;
                    __auto_type _mv_371 = decode_decode_concept(arena, g, t.object, decode_CONCEPT_FUEL);
                    if (!_mv_371.is_ok) {
                        __auto_type m = _mv_371.data.err;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                    } else if (_mv_371.is_ok) {
                        __auto_type rhs = _mv_371.data.ok;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_sub_class_of, .data.ra_sub_class_of = { .f0 = decode_box_concept(arena, lhs), .f1 = decode_box_concept(arena, rhs) } }) });
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_OWL_EQUIVALENT_CLASS) == 0) {
                __auto_type _mv_372 = decode_binary_concepts(arena, g, t);
                if (!_mv_372.is_ok) {
                    __auto_type m = _mv_372.data.err;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                } else if (_mv_372.is_ok) {
                    __auto_type cs = _mv_372.data.ok;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_equivalent_classes, .data.ra_equivalent_classes = cs }) });
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_OWL_DISJOINT_WITH) == 0) {
                __auto_type _mv_373 = decode_binary_concepts(arena, g, t);
                if (!_mv_373.is_ok) {
                    __auto_type m = _mv_373.data.err;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                } else if (_mv_373.is_ok) {
                    __auto_type cs = _mv_373.data.ok;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_classes, .data.ra_disjoint_classes = cs }) });
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_OWL_PROPERTY_CHAIN_AXIOM) == 0) {
                __auto_type _mv_374 = decode_role_of_term(t.subject);
                if (!_mv_374.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:propertyChainAxiom on a non-IRI subject") });
                } else if (_mv_374.has_value) {
                    __auto_type super = _mv_374.value;
                    __auto_type _mv_375 = decode_decode_role_list(arena, g, t.object);
                    if (!_mv_375.is_ok) {
                        __auto_type m = _mv_375.data.err;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                    } else if (_mv_375.is_ok) {
                        __auto_type steps = _mv_375.data.ok;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_property_chain, .data.ra_property_chain = ((owl2_RawChain){.steps = steps, .super = super}) }) });
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_RDFS_SUBPROPERTY_OF) == 0) {
                if (decode_property_axiom_kind(sig, t.subject) == 1) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_annotation_axiom, .data.ra_annotation_axiom = decode_frag(arena, t) }) });
                } else if (decode_property_axiom_kind(sig, t.subject) == 2) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
                } else {
                    __auto_type _mv_376 = decode_role_of_term(t.subject);
                    if (!_mv_376.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("rdfs:subPropertyOf on a non-IRI subject") });
                    } else if (_mv_376.has_value) {
                        __auto_type sub = _mv_376.value;
                        __auto_type _mv_377 = decode_role_of_term(t.object);
                        if (!_mv_377.has_value) {
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("rdfs:subPropertyOf with a non-IRI object") });
                        } else if (_mv_377.has_value) {
                            __auto_type sup = _mv_377.value;
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_sub_object_property, .data.ra_sub_object_property = { .f0 = sub, .f1 = sup } }) });
                        }
                        SLOP_UNREACHABLE();
                    }
                    SLOP_UNREACHABLE();
                }
            } else if (canon_string_cmp(pv, vocab_OWL_EQUIVALENT_PROPERTY) == 0) {
                __auto_type _mv_378 = decode_role_of_term(t.subject);
                if (!_mv_378.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:equivalentProperty on a non-IRI subject") });
                } else if (_mv_378.has_value) {
                    __auto_type a = _mv_378.value;
                    __auto_type _mv_379 = decode_role_of_term(t.object);
                    if (!_mv_379.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:equivalentProperty with a non-IRI object") });
                    } else if (_mv_379.has_value) {
                        __auto_type b = _mv_379.value;
                        {
                            __auto_type rs = ((slop_list_types_RoleId){ .data = (types_RoleId*)slop_arena_alloc(arena, 16 * sizeof(types_RoleId)), .len = 0, .cap = 16 });
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_equivalent_properties, .data.ra_equivalent_properties = rs }) });
                        }
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_OWL_PROPERTY_DISJOINT_WITH) == 0) {
                __auto_type _mv_380 = decode_role_of_term(t.subject);
                if (!_mv_380.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:propertyDisjointWith on a non-IRI subject") });
                } else if (_mv_380.has_value) {
                    __auto_type a = _mv_380.value;
                    __auto_type _mv_381 = decode_role_of_term(t.object);
                    if (!_mv_381.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:propertyDisjointWith with a non-IRI object") });
                    } else if (_mv_381.has_value) {
                        __auto_type b = _mv_381.value;
                        {
                            __auto_type rs = ((slop_list_types_RoleId){ .data = (types_RoleId*)slop_arena_alloc(arena, 16 * sizeof(types_RoleId)), .len = 0, .cap = 16 });
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_properties, .data.ra_disjoint_properties = rs }) });
                        }
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_OWL_INVERSE_OF) == 0) {
                __auto_type _mv_382 = decode_role_of_term(t.subject);
                if (!_mv_382.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:inverseOf on a non-IRI subject") });
                } else if (_mv_382.has_value) {
                    __auto_type a = _mv_382.value;
                    __auto_type _mv_383 = decode_role_of_term(t.object);
                    if (!_mv_383.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:inverseOf with a non-IRI object") });
                    } else if (_mv_383.has_value) {
                        __auto_type b = _mv_383.value;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inverse_properties, .data.ra_inverse_properties = { .f0 = a, .f1 = b } }) });
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_RDFS_DOMAIN) == 0) {
                if (decode_property_axiom_kind(sig, t.subject) == 1) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_annotation_axiom, .data.ra_annotation_axiom = decode_frag(arena, t) }) });
                } else if (decode_property_axiom_kind(sig, t.subject) == 2) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
                } else {
                    __auto_type _mv_384 = decode_role_of_term(t.subject);
                    if (!_mv_384.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("rdfs:domain on a non-IRI subject") });
                    } else if (_mv_384.has_value) {
                        __auto_type r = _mv_384.value;
                        __auto_type _mv_385 = decode_decode_concept(arena, g, t.object, decode_CONCEPT_FUEL);
                        if (!_mv_385.is_ok) {
                            __auto_type m = _mv_385.data.err;
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                        } else if (_mv_385.is_ok) {
                            __auto_type c = _mv_385.data.ok;
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_object_property_domain, .data.ra_object_property_domain = { .f0 = r, .f1 = decode_box_concept(arena, c) } }) });
                        }
                        SLOP_UNREACHABLE();
                    }
                    SLOP_UNREACHABLE();
                }
            } else if (canon_string_cmp(pv, vocab_RDFS_RANGE) == 0) {
                if (decode_property_axiom_kind(sig, t.subject) == 1) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_annotation_axiom, .data.ra_annotation_axiom = decode_frag(arena, t) }) });
                } else if (decode_property_axiom_kind(sig, t.subject) == 2) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
                } else {
                    __auto_type _mv_386 = decode_role_of_term(t.subject);
                    if (!_mv_386.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("rdfs:range on a non-IRI subject") });
                    } else if (_mv_386.has_value) {
                        __auto_type r = _mv_386.value;
                        __auto_type _mv_387 = decode_decode_concept(arena, g, t.object, decode_CONCEPT_FUEL);
                        if (!_mv_387.is_ok) {
                            __auto_type m = _mv_387.data.err;
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                        } else if (_mv_387.is_ok) {
                            __auto_type c = _mv_387.data.ok;
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_object_property_range, .data.ra_object_property_range = { .f0 = r, .f1 = decode_box_concept(arena, c) } }) });
                        }
                        SLOP_UNREACHABLE();
                    }
                    SLOP_UNREACHABLE();
                }
            } else if (canon_string_cmp(pv, vocab_OWL_SAME_AS) == 0) {
                {
                    __auto_type ns = ((slop_list_types_Node){ .data = (types_Node*)slop_arena_alloc(arena, 16 * sizeof(types_Node)), .len = 0, .cap = 16 });
                    __auto_type _mv_388 = decode_term_iri_value(t.subject);
                    if (_mv_388.has_value) {
                        __auto_type i = _mv_388.value;
                        ({ __auto_type _lst_p = &(ns); __auto_type _item = (((types_Node){ .tag = types_Node_individual_node, .data.individual_node = i })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_388.has_value) {
                    }
                    __auto_type _mv_389 = decode_term_iri_value(t.object);
                    if (_mv_389.has_value) {
                        __auto_type i = _mv_389.value;
                        ({ __auto_type _lst_p = &(ns); __auto_type _item = (((types_Node){ .tag = types_Node_individual_node, .data.individual_node = i })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_389.has_value) {
                    }
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_same_individual, .data.ra_same_individual = ns }) });
                }
            } else if (canon_string_cmp(pv, vocab_OWL_DIFFERENT_FROM) == 0) {
                {
                    __auto_type ns = ((slop_list_types_Node){ .data = (types_Node*)slop_arena_alloc(arena, 16 * sizeof(types_Node)), .len = 0, .cap = 16 });
                    __auto_type _mv_390 = decode_term_iri_value(t.subject);
                    if (_mv_390.has_value) {
                        __auto_type i = _mv_390.value;
                        ({ __auto_type _lst_p = &(ns); __auto_type _item = (((types_Node){ .tag = types_Node_individual_node, .data.individual_node = i })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_390.has_value) {
                    }
                    __auto_type _mv_391 = decode_term_iri_value(t.object);
                    if (_mv_391.has_value) {
                        __auto_type i = _mv_391.value;
                        ({ __auto_type _lst_p = &(ns); __auto_type _item = (((types_Node){ .tag = types_Node_individual_node, .data.individual_node = i })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_391.has_value) {
                    }
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_different_individuals, .data.ra_different_individuals = ns }) });
                }
            } else if (canon_string_cmp(pv, owl2_OWL_DISJOINT_UNION_OF) == 0) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_union, .data.ra_disjoint_union = decode_frag(arena, t) }) });
            } else if (canon_string_cmp(pv, vocab_OWL_HAS_KEY) == 0) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_has_key, .data.ra_has_key = decode_frag(arena, t) }) });
            } else if (owl2_signature_has_annotation_property(sig, p)) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_annotation_assertion, .data.ra_annotation_assertion = ((owl2_RawAnnotation){.property = p, .subject = decode_frag(arena, t), .target = decode_render_term(arena, t.object)}) }) });
            } else if (owl2_signature_has_object_property(sig, p)) {
                __auto_type _mv_392 = decode_role_of_term(t.predicate);
                if (!_mv_392.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("unreachable: declared object property is not an IRI") });
                } else if (_mv_392.has_value) {
                    __auto_type r = _mv_392.value;
                    __auto_type _mv_393 = decode_term_iri_value(t.subject);
                    if (!_mv_393.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = decode_frag(arena, t) }) });
                    } else if (_mv_393.has_value) {
                        __auto_type sfrom = _mv_393.value;
                        __auto_type _mv_394 = decode_term_iri_value(t.object);
                        if (!_mv_394.has_value) {
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = decode_frag(arena, t) }) });
                        } else if (_mv_394.has_value) {
                            __auto_type sto = _mv_394.value;
                            if (decode_is_reserved_iri(sfrom.value) || decode_is_reserved_iri(sto.value)) {
                                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = decode_frag(arena, t) }) });
                            } else {
                                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_object_property_assertion, .data.ra_object_property_assertion = ((owl2_RawEdge){.role = r, .from = ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = sfrom }), .to = ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = sto })}) }) });
                            }
                        }
                        SLOP_UNREACHABLE();
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            } else if (decode_is_reserved_iri(pv)) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = decode_frag(arena, t) }) });
            } else if (owl2_signature_has_data_property(sig, p)) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
            } else {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = string_concat(arena, SLOP_STR("undeclared property, ambiguous between object, data and annotation property: "), pv) });
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_decode_Stage1_types_Fault decode_decode_axioms(slop_arena* arena, slop_list_rdf_Triple triples) {
    {
        __auto_type ig = decode_graph_to_indexed(arena, triples);
        __auto_type sig = decode_build_signature(arena, triples);
        __auto_type out = ((slop_list_owl2_RawAxiom){ .data = (owl2_RawAxiom*)slop_arena_alloc(arena, 16 * sizeof(owl2_RawAxiom)), .len = 0, .cap = 16 });
        slop_option_string fault = (slop_option_string){.has_value = false};
        fault = decode_declaration_conflict(arena, sig, triples);
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (!(decode_structural_triple(t))) {
                    __auto_type _mv_395 = decode_decode_axiom(arena, ig, sig, t);
                    if (!_mv_395.is_ok) {
                        __auto_type m = _mv_395.data.err;
                        fault = (slop_option_string){.has_value = 1, .value = m};
                    } else if (_mv_395.is_ok) {
                        __auto_type ax = _mv_395.data.ok;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        __auto_type _mv_396 = fault;
        if (_mv_396.has_value) {
            __auto_type m = _mv_396.value;
            return ((slop_result_decode_Stage1_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_input_error, .data.input_error = m }) });
        } else if (!_mv_396.has_value) {
            return ((slop_result_decode_Stage1_types_Fault){ .is_ok = true, .data.ok = ((decode_Stage1){.axioms = out, .signature = sig}) });
        }
        SLOP_UNREACHABLE();
    }
}

slop_option_string decode_declaration_conflict(slop_arena* arena, owl2_Signature sig, slop_list_rdf_Triple triples) {
    {
        __auto_type type_pred = rdf_make_iri(arena, vocab_RDF_TYPE);
        slop_option_string bad = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (rdf_term_eq(t.predicate, type_pred)) {
                    __auto_type _mv_397 = decode_term_iri_value(t.subject);
                    if (_mv_397.has_value) {
                        __auto_type e = _mv_397.value;
                        {
                            __auto_type np = (((owl2_signature_has_object_property(sig, e)) ? 1 : 0) + (((owl2_signature_has_data_property(sig, e)) ? 1 : 0) + ((owl2_signature_has_annotation_property(sig, e)) ? 1 : 0)));
                            if (np > 1) {
                                bad = (slop_option_string){.has_value = 1, .value = string_concat(arena, SLOP_STR("IRI declared under two disjoint property kinds: "), e.value)};
                            }
                        }
                    } else if (!_mv_397.has_value) {
                    }
                }
            }
        }
        return bad;
    }
}

