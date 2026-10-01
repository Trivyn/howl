#include "../runtime/slop_runtime.h"
#include "slop_decode.h"


rdf_Term decode_term_at(slop_list_rdf_Term xs, int64_t i);
rdf_Triple decode_triple_at(slop_list_rdf_Triple xs, int64_t i);
termstore_TermStore decode_graph_to_indexed(slop_arena* arena, slop_list_rdf_Triple triples);
slop_result_rdf_Term_decode_LookupFault decode_one_object(slop_arena* arena, termstore_TermStore g, rdf_Term subj, rdf_Term pred);
slop_result_list_rdf_Term_decode_ListFault decode_rdf_list_checked(slop_arena* arena, termstore_TermStore g, rdf_Term head);
slop_option_rdf_IRI decode_term_iri_value(rdf_Term t);
uint8_t decode_iri_in_list(slop_list_rdf_IRI xs, rdf_IRI target);
slop_list_rdf_IRI decode_collect_imports(slop_arena* arena, termstore_Encoded doc);
int64_t decode_vocab_id(slop_arena* arena, termstore_TermStore dict, slop_string iri);
slop_list_types_Omission decode_unresolved_imports(slop_arena* arena, slop_list_rdf_IRI declared, slop_list_rdf_IRI resolved);
uint8_t decode_typed_as(rdf_Triple t, slop_string type_iri);
slop_list_int decode_typed_ids_in_order(slop_arena* arena, termstore_Encoded doc, slop_string type_iri);
uint8_t decode_logical_predicate(slop_string pv);
rdf_Triple decode_ex_hdr(slop_string p, slop_string o);
uint8_t decode_header_consumable(rdf_Triple t);
slop_result_decode_Stage0_types_Fault decode_stage0_header(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved);
slop_result_decode_Stage0_types_Fault decode_stage0_encoded(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved);
slop_map* decode_id_set(slop_arena* arena, slop_list_int a, slop_list_int b, slop_list_int c);
termstore_TermStore decode_annotated_store(slop_arena* arena, termstore_Encoded doc);
int64_t decode_term_id(termstore_TermStore st, rdf_Term t);
decode_Rebuilt decode_rebuild_candidates(slop_arena* arena, termstore_TermStore st, slop_list_int ax_subjs);
slop_map* decode_asserted_among(slop_arena* arena, slop_list_termstore_IdTriple candidates, termstore_Encoded doc);
slop_result_decode_Stage0_types_Fault decode_stage0_scan(slop_arena* arena, slop_arena* scratch, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved);
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
decode_IndividualTerm decode_individual_term(rdf_Term tm);
slop_result_decode_NodeList_string decode_decode_node_list(slop_arena* arena, termstore_TermStore g, rdf_Term head);
slop_result_list_owl2_RawConcept_string decode_decode_concept_list(slop_arena* arena, termstore_TermStore g, rdf_Term head, int64_t fuel);
slop_result_owl2_RawConcept_string decode_decode_quantified(slop_arena* arena, termstore_TermStore g, rdf_Term b, slop_string filler_pred, uint8_t universal, int64_t fuel);
slop_result_owl2_RawConcept_string decode_decode_cardinality(slop_arena* arena, termstore_TermStore g, rdf_Term b, owl2_CardKind kind, slop_string count_pred, uint8_t qualified, int64_t fuel);
slop_result_owl2_RawConcept_string decode_decode_anon(slop_arena* arena, termstore_TermStore g, rdf_Term b, int64_t fuel);
slop_result_owl2_RawConcept_string decode_decode_concept(slop_arena* arena, termstore_TermStore g, rdf_Term t, int64_t fuel);
uint8_t decode_declare_entity(slop_arena* arena, owl2_Signature sig, rdf_IRI entity, slop_string type_iri);
uint8_t decode_add_builtins(slop_arena* arena, owl2_Signature sig);
owl2_Signature decode_build_signature(slop_arena* arena, termstore_TermStore dict, slop_list_termstore_IdTriple triples);
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
slop_result_owl2_RawAxiom_string decode_decode_individual_pair(slop_arena* arena, rdf_Triple t, uint8_t same);
slop_result_owl2_RawAxiom_string decode_decode_negative_assertion(slop_arena* arena, termstore_TermStore g, rdf_Triple t);
slop_result_owl2_RawAxiom_string decode_decode_class_assertion(slop_arena* arena, termstore_TermStore g, rdf_Triple t);
uint8_t decode_is_reserved_iri(slop_string v);
int64_t decode_property_axiom_kind(owl2_Signature sig, rdf_Term subj);
slop_result_owl2_RawAxiom_string decode_decode_axiom(slop_arena* arena, termstore_TermStore g, owl2_Signature sig, rdf_Triple t);
slop_result_decode_Stage1_types_Fault decode_decode_axioms(slop_arena* arena, termstore_TermStore dict, slop_list_termstore_IdTriple triples);
termstore_TermStore decode_decode_store(slop_arena* arena, termstore_TermStore dict, slop_list_termstore_IdTriple triples);
slop_list_string decode_queried_predicates(slop_arena* arena);
slop_result_decode_Stage1_types_Fault decode_decode_axioms_with(slop_arena* arena, termstore_TermStore ig, termstore_TermStore dict, slop_list_termstore_IdTriple triples);
slop_map* decode_negative_assertion_nodes(slop_arena* arena, termstore_TermStore dict, slop_list_termstore_IdTriple triples);
slop_map* decode_negative_assertion_parts(slop_arena* arena, termstore_TermStore dict);
uint8_t decode_negative_assertion_part(termstore_IdTriple it, slop_map* nodes, slop_map* parts);
slop_option_string decode_declaration_conflict(slop_arena* arena, owl2_Signature sig, termstore_TermStore dict, slop_list_termstore_IdTriple triples);

rdf_Term decode_term_at(slop_list_rdf_Term xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_392 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_392.has_value) {
        __auto_type v = _mv_392.value;
        return v;
    } else if (!_mv_392.has_value) {
        return ((rdf_Term){ .tag = rdf_Term_term_blank, .data.term_blank = ((rdf_BlankNode){.id = 0}) });
    }
    SLOP_UNREACHABLE();
}

rdf_Triple decode_triple_at(slop_list_rdf_Triple xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    {
        __auto_type blank = ((rdf_Term){ .tag = rdf_Term_term_blank, .data.term_blank = ((rdf_BlankNode){.id = 0}) });
        __auto_type _mv_393 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_rdf_Triple _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_393.has_value) {
            __auto_type v = _mv_393.value;
            return v;
        } else if (!_mv_393.has_value) {
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
        __auto_type n = termstore_store_object_count(g, subj, pred);
        if (n == 1) {
            __auto_type _mv_394 = termstore_store_sole_object(g, subj, pred);
            if (_mv_394.has_value) {
                __auto_type o = _mv_394.value;
                return ((slop_result_rdf_Term_decode_LookupFault){ .is_ok = true, .data.ok = o });
            } else if (!_mv_394.has_value) {
                return ((slop_result_rdf_Term_decode_LookupFault){ .is_ok = false, .data.err = decode_LookupFault_lookup_missing });
            }
            SLOP_UNREACHABLE();
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
        __auto_type out = ((slop_list_rdf_Term){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type visited = ({ static const slop_map_desc _d = SLOP_SET_DESC(rdf_Term, slop_hash_rdf_Term, slop_eq_rdf_Term, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type current = head;
        slop_option_decode_ListFault fault = (slop_option_decode_ListFault){.has_value = false};
        uint8_t done = 0;
        while (!(done) && !(rdf_term_eq(current, nil_term))) {
            if (slop_map_has(visited, &(current))) {
                fault = (slop_option_decode_ListFault){.has_value = 1, .value = ((decode_ListFault){ .tag = decode_ListFault_list_cyclic, .data.list_cyclic = SLOP_STR("rdf:rest returns to a cell already visited") })};
                done = 1;
            } else {
                ({ slop_map_put(arena, visited, &(current), NULL, 0); });
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
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (decode_term_at(firsts, 0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            current = decode_term_at(rests, 0);
                        }
                    }
                }
            }
        }
        __auto_type _mv_397 = fault;
        if (_mv_397.has_value) {
            __auto_type f = _mv_397.value;
            return ((slop_result_list_rdf_Term_decode_ListFault){ .is_ok = false, .data.err = f });
        } else if (!_mv_397.has_value) {
            return ((slop_result_list_rdf_Term_decode_ListFault){ .is_ok = true, .data.ok = out });
        }
        SLOP_UNREACHABLE();
    }
}

slop_option_rdf_IRI decode_term_iri_value(rdf_Term t) {
    __auto_type _mv_398 = t;
    switch (_mv_398.tag) {
        case rdf_Term_term_iri:
        {
            __auto_type i = _mv_398.data.term_iri;
            return (slop_option_rdf_IRI){.has_value = 1, .value = i};
        }
        case rdf_Term_term_blank:
        {
            __auto_type _ = _mv_398.data.term_blank;
            return (slop_option_rdf_IRI){.has_value = false};
        }
        case rdf_Term_term_literal:
        {
            __auto_type _ = _mv_398.data.term_literal;
            return (slop_option_rdf_IRI){.has_value = false};
        }
        case rdf_Term_term_triple:
        {
            __auto_type _ = _mv_398.data.term_triple;
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

slop_list_rdf_IRI decode_collect_imports(slop_arena* arena, termstore_Encoded doc) {
    {
        __auto_type imports_id = decode_vocab_id(arena, doc.dict, vocab_OWL_IMPORTS);
        __auto_type out = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = doc.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (it.p == imports_id) {
                    __auto_type _mv_399 = decode_term_iri_value(termstore_term_of(doc.dict, it.o));
                    if (_mv_399.has_value) {
                        __auto_type i = _mv_399.value;
                        if (!(decode_iri_in_list(out, i))) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    } else if (!_mv_399.has_value) {
                    }
                }
            }
        }
        return canon_sort_iris(arena, out);
    }
}

int64_t decode_vocab_id(slop_arena* arena, termstore_TermStore dict, slop_string iri) {
    __auto_type _mv_400 = termstore_lookup_term(dict, rdf_make_iri(arena, iri));
    if (_mv_400.has_value) {
        __auto_type i = _mv_400.value;
        return i;
    } else if (!_mv_400.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

slop_list_types_Omission decode_unresolved_imports(slop_arena* arena, slop_list_rdf_IRI declared, slop_list_rdf_IRI resolved) {
    {
        __auto_type out = ((slop_list_types_Omission){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = declared;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type d = _coll.data[_i];
                if (!(decode_iri_in_list(resolved, d))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_Omission){ .tag = types_Omission_unresolved_import, .data.unresolved_import = d })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return canon_sort_omissions(arena, out);
    }
}

uint8_t decode_typed_as(rdf_Triple t, slop_string type_iri) {
    __auto_type _mv_401 = decode_term_iri_value(t.predicate);
    if (!_mv_401.has_value) {
        return 0;
    } else if (_mv_401.has_value) {
        __auto_type p = _mv_401.value;
        return ((canon_string_cmp(p.value, vocab_RDF_TYPE) == 0) && ({ __auto_type _mv = decode_term_iri_value(t.object); _mv.has_value ? ({ __auto_type o = _mv.value; (canon_string_cmp(o.value, type_iri) == 0); }) : (0); }));
    }
    SLOP_UNREACHABLE();
}

slop_list_int decode_typed_ids_in_order(slop_arena* arena, termstore_Encoded doc, slop_string type_iri) {
    {
        __auto_type type_pred = doc.dict.rdf_type;
        __auto_type type_id = decode_vocab_id(arena, doc.dict, type_iri);
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = doc.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if ((it.p == type_pred) && (it.o == type_id)) {
                    if (!(slop_map_has(seen, &(int64_t){it.s}))) {
                        ({ slop_map_put(arena, seen, &(int64_t){it.s}, NULL, 0); });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (it.s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    __auto_type _mv_404 = decode_term_iri_value(t.predicate);
    if (!_mv_404.has_value) {
        return 0;
    } else if (_mv_404.has_value) {
        __auto_type p = _mv_404.value;
        if (canon_string_cmp(p.value, vocab_RDF_TYPE) == 0) {
            __auto_type _mv_405 = decode_term_iri_value(t.object);
            if (!_mv_405.has_value) {
                return 0;
            } else if (_mv_405.has_value) {
                __auto_type o = _mv_405.value;
                if (canon_string_cmp(o.value, vocab_OWL_ONTOLOGY) == 0) {
                    return 1;
                } else if (canon_string_cmp(o.value, vocab_OWL_AXIOM) == 0) {
                    return 1;
                } else if (canon_string_cmp(o.value, vocab_OWL_ANNOTATION) == 0) {
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
    return decode_stage0_encoded(arena, termstore_encode_triples(arena, triples), imports_resolved);
}

slop_result_decode_Stage0_types_Fault decode_stage0_encoded(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type res = decode_stage0_scan(arena, scratch, doc, imports_resolved);
        ({ slop_arena_free(scratch); free(scratch); });
        return res;
    }
}

slop_map* decode_id_set(slop_arena* arena, slop_list_int a, slop_list_int b, slop_list_int c) {
    {
        __auto_type s = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ slop_map_put(arena, s, &(int64_t){x}, NULL, 0); });
            }
        }
        {
            __auto_type _coll = b;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ slop_map_put(arena, s, &(int64_t){x}, NULL, 0); });
            }
        }
        {
            __auto_type _coll = c;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ slop_map_put(arena, s, &(int64_t){x}, NULL, 0); });
            }
        }
        return s;
    }
}

termstore_TermStore decode_annotated_store(slop_arena* arena, termstore_Encoded doc) {
    {
        __auto_type st = termstore_store_over(arena, doc.dict);
        __auto_type src = decode_vocab_id(arena, doc.dict, vocab_OWL_ANNOTATED_SOURCE);
        __auto_type prop = decode_vocab_id(arena, doc.dict, vocab_OWL_ANNOTATED_PROPERTY);
        __auto_type tgt = decode_vocab_id(arena, doc.dict, vocab_OWL_ANNOTATED_TARGET);
        {
            __auto_type _coll = doc.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (((it.p == src)) || ((it.p == prop)) || ((it.p == tgt))) {
                    termstore_store_insert_ids(arena, st, it);
                }
            }
        }
        return st;
    }
}

int64_t decode_term_id(termstore_TermStore st, rdf_Term t) {
    __auto_type _mv_409 = termstore_lookup_term(st, t);
    if (_mv_409.has_value) {
        __auto_type i = _mv_409.value;
        return i;
    } else if (!_mv_409.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

decode_Rebuilt decode_rebuild_candidates(slop_arena* arena, termstore_TermStore st, slop_list_int ax_subjs) {
    {
        __auto_type src_pred = rdf_make_iri(arena, vocab_OWL_ANNOTATED_SOURCE);
        __auto_type prop_pred = rdf_make_iri(arena, vocab_OWL_ANNOTATED_PROPERTY);
        __auto_type tgt_pred = rdf_make_iri(arena, vocab_OWL_ANNOTATED_TARGET);
        __auto_type out = ((slop_list_termstore_IdTriple){ .data = NULL, .len = 0, .cap = 0 });
        slop_option_string fault = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = ax_subjs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ai = _coll.data[_i];
                {
                    __auto_type a = termstore_term_of(st, ai);
                    __auto_type _mv_410 = decode_one_object(arena, st, a, src_pred);
                    if (!_mv_410.is_ok) {
                        __auto_type _ = _mv_410.data.err;
                        fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("owl:Axiom node without a usable owl:annotatedSource")};
                    } else if (_mv_410.is_ok) {
                        __auto_type subj = _mv_410.data.ok;
                        __auto_type _mv_411 = decode_one_object(arena, st, a, prop_pred);
                        if (!_mv_411.is_ok) {
                            __auto_type _ = _mv_411.data.err;
                            fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("owl:Axiom node without a usable owl:annotatedProperty")};
                        } else if (_mv_411.is_ok) {
                            __auto_type pred = _mv_411.data.ok;
                            __auto_type _mv_412 = decode_one_object(arena, st, a, tgt_pred);
                            if (!_mv_412.is_ok) {
                                __auto_type _ = _mv_412.data.err;
                                fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("owl:Axiom node without a usable owl:annotatedTarget")};
                            } else if (_mv_412.is_ok) {
                                __auto_type obj = _mv_412.data.ok;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (((termstore_IdTriple){.s = decode_term_id(st, subj), .p = decode_term_id(st, pred), .o = decode_term_id(st, obj)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
            }
        }
        return ((decode_Rebuilt){.triples = out, .fault = fault});
    }
}

slop_map* decode_asserted_among(slop_arena* arena, slop_list_termstore_IdTriple candidates, termstore_Encoded doc) {
    {
        __auto_type cands = ({ static const slop_map_desc _d = SLOP_SET_DESC(termstore_IdTriple, slop_hash_termstore_IdTriple, slop_eq_termstore_IdTriple, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type found = ({ static const slop_map_desc _d = SLOP_SET_DESC(termstore_IdTriple, slop_hash_termstore_IdTriple, slop_eq_termstore_IdTriple, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = candidates;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ slop_map_put(arena, cands, &(c), NULL, 0); });
            }
        }
        {
            __auto_type _coll = doc.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (slop_map_has(cands, &(it))) {
                    ({ slop_map_put(arena, found, &(it), NULL, 0); });
                }
            }
        }
        return found;
    }
}

slop_result_decode_Stage0_types_Fault decode_stage0_scan(slop_arena* arena, slop_arena* scratch, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved) {
    {
        __auto_type ont_subjs = decode_typed_ids_in_order(scratch, doc, vocab_OWL_ONTOLOGY);
        __auto_type ax_subjs = decode_typed_ids_in_order(scratch, doc, vocab_OWL_AXIOM);
        __auto_type ann_subjs = decode_typed_ids_in_order(scratch, doc, vocab_OWL_ANNOTATION);
        __auto_type declared = decode_collect_imports(arena, doc);
        __auto_type dict = doc.dict;
        __auto_type out = ((slop_list_termstore_IdTriple){ .data = NULL, .len = 0, .cap = 0 });
        slop_option_rdf_IRI ont = (slop_option_rdf_IRI){.has_value = false};
        slop_option_string fault = (slop_option_string){.has_value = false};
        {
            __auto_type header = decode_id_set(scratch, ont_subjs, ax_subjs, ann_subjs);
            {
                __auto_type _coll = doc.triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type it = _coll.data[_i];
                    if (!(slop_map_has(header, &(int64_t){it.s})) || !(decode_header_consumable(termstore_triple_of(dict, it)))) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (it); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type rb = decode_rebuild_candidates(scratch, decode_annotated_store(scratch, doc), ax_subjs);
            __auto_type asserted = decode_asserted_among(scratch, rb.triples, doc);
            {
                __auto_type _coll = rb.triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    if (!(slop_map_has(asserted, &(c)))) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
            fault = rb.fault;
        }
        {
            __auto_type _coll = ont_subjs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                __auto_type _mv_418 = decode_term_iri_value(termstore_term_of(dict, o));
                if (_mv_418.has_value) {
                    __auto_type i = _mv_418.value;
                    ont = (slop_option_rdf_IRI){.has_value = 1, .value = i};
                } else if (!_mv_418.has_value) {
                }
            }
        }
        __auto_type _mv_419 = fault;
        if (_mv_419.has_value) {
            __auto_type msg = _mv_419.value;
            return ((slop_result_decode_Stage0_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_input_error, .data.input_error = msg }) });
        } else if (!_mv_419.has_value) {
            return ((slop_result_decode_Stage0_types_Fault){ .is_ok = true, .data.ok = ((decode_Stage0){.dict = dict, .triples = out, .imports_declared = declared, .omissions = decode_unresolved_imports(arena, declared, imports_resolved), .ontology_iri = ont}) });
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
    __auto_type _mv_420 = f;
    switch (_mv_420.tag) {
        case decode_ListFault_list_truncated:
        {
            __auto_type m = _mv_420.data.list_truncated;
            return m;
        }
        case decode_ListFault_list_branching:
        {
            __auto_type m = _mv_420.data.list_branching;
            return m;
        }
        case decode_ListFault_list_cyclic:
        {
            __auto_type m = _mv_420.data.list_cyclic;
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
    __auto_type _mv_421 = decode_obj_of(arena, g, b, vocab_OWL_ON_PROPERTY);
    if (!_mv_421.is_ok) {
        __auto_type _ = _mv_421.data.err;
        return ((slop_result_types_RoleId_string){ .is_ok = false, .data.err = SLOP_STR("restriction without exactly one owl:onProperty") });
    } else if (_mv_421.is_ok) {
        __auto_type pt = _mv_421.data.ok;
        __auto_type _mv_422 = decode_term_iri_value(pt);
        if (_mv_422.has_value) {
            __auto_type i = _mv_422.value;
            return ((slop_result_types_RoleId_string){ .is_ok = true, .data.ok = ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = i }) });
        } else if (!_mv_422.has_value) {
            return ((slop_result_types_RoleId_string){ .is_ok = false, .data.err = SLOP_STR("owl:onProperty is a blank node that is not an inverse property expression") });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t decode_inverse_expression_term(slop_arena* arena, termstore_TermStore g, rdf_Term t) {
    __auto_type _mv_423 = t;
    switch (_mv_423.tag) {
        case rdf_Term_term_blank:
        {
            __auto_type _ = _mv_423.data.term_blank;
            __auto_type _mv_424 = decode_obj_of(arena, g, t, vocab_OWL_INVERSE_OF);
            if (_mv_424.is_ok) {
                __auto_type pt = _mv_424.data.ok;
                __auto_type _mv_425 = decode_term_iri_value(pt);
                if (_mv_425.has_value) {
                    __auto_type _ = _mv_425.value;
                    return 1;
                } else if (!_mv_425.has_value) {
                    return 0;
                }
                SLOP_UNREACHABLE();
            } else if (!_mv_424.is_ok) {
                __auto_type _ = _mv_424.data.err;
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
    __auto_type _mv_426 = decode_obj_of(arena, g, b, vocab_OWL_ON_PROPERTY);
    if (_mv_426.is_ok) {
        __auto_type pt = _mv_426.data.ok;
        return decode_inverse_expression_term(arena, g, pt);
    } else if (!_mv_426.is_ok) {
        __auto_type _ = _mv_426.data.err;
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t decode_list_has_inverse(slop_arena* arena, termstore_TermStore g, rdf_Term head) {
    __auto_type _mv_427 = decode_rdf_list_checked(arena, g, head);
    if (!_mv_427.is_ok) {
        __auto_type _ = _mv_427.data.err;
        return 0;
    } else if (_mv_427.is_ok) {
        __auto_type terms = _mv_427.data.ok;
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
    } else if (((canon_string_cmp(pv, vocab_RDFS_SUBPROPERTY_OF) == 0)) || ((canon_string_cmp(pv, vocab_OWL_EQUIVALENT_PROPERTY) == 0)) || ((canon_string_cmp(pv, vocab_OWL_PROPERTY_DISJOINT_WITH) == 0))) {
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
    __auto_type _mv_428 = t;
    switch (_mv_428.tag) {
        case rdf_Term_term_literal:
        {
            __auto_type l = _mv_428.data.term_literal;
            __auto_type _mv_429 = strlib_parse_int(l.value);
            if (_mv_429.is_ok) {
                __auto_type v = _mv_429.data.ok;
                if (((int64_t)(v)) < 0) {
                    return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality literal is negative") });
                } else {
                    return ((slop_result_int_string){ .is_ok = true, .data.ok = ((int64_t)(v)) });
                }
            } else if (!_mv_429.is_ok) {
                __auto_type _ = _mv_429.data.err;
                return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality is not an integer literal") });
            }
            SLOP_UNREACHABLE();
        }
        case rdf_Term_term_iri:
        {
            __auto_type _ = _mv_428.data.term_iri;
            return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality is an IRI, not a literal") });
        }
        case rdf_Term_term_blank:
        {
            __auto_type _ = _mv_428.data.term_blank;
            return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality is a blank node, not a literal") });
        }
        case rdf_Term_term_triple:
        {
            __auto_type _ = _mv_428.data.term_triple;
            return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality is a triple term, not a literal") });
        }
    }
    SLOP_UNREACHABLE();
}

decode_IndividualTerm decode_individual_term(rdf_Term tm) {
    __auto_type _mv_430 = tm;
    switch (_mv_430.tag) {
        case rdf_Term_term_iri:
        {
            __auto_type i = _mv_430.data.term_iri;
            if (decode_is_reserved_iri(i.value)) {
                return ((decode_IndividualTerm){ .tag = decode_IndividualTerm_reserved_individual });
            } else {
                return ((decode_IndividualTerm){ .tag = decode_IndividualTerm_named_individual, .data.named_individual = i });
            }
        }
        case rdf_Term_term_literal:
        {
            __auto_type _ = _mv_430.data.term_literal;
            return ((decode_IndividualTerm){ .tag = decode_IndividualTerm_literal_individual });
        }
        default: {
            return ((decode_IndividualTerm){ .tag = decode_IndividualTerm_anonymous_individual });
        }
    }
}

slop_result_decode_NodeList_string decode_decode_node_list(slop_arena* arena, termstore_TermStore g, rdf_Term head) {
    __auto_type _mv_431 = decode_rdf_list_checked(arena, g, head);
    if (!_mv_431.is_ok) {
        __auto_type lf = _mv_431.data.err;
        return ((slop_result_decode_NodeList_string){ .is_ok = false, .data.err = decode_list_fault_message(lf) });
    } else if (_mv_431.is_ok) {
        __auto_type terms = _mv_431.data.ok;
        {
            __auto_type out = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
            __auto_type literal = 0;
            __auto_type anonymous = 0;
            __auto_type reserved = 0;
            {
                __auto_type _coll = terms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tm = _coll.data[_i];
                    __auto_type _mv_432 = decode_individual_term(tm);
                    switch (_mv_432.tag) {
                        case decode_IndividualTerm_named_individual:
                        {
                            __auto_type i = _mv_432.data.named_individual;
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_Node){ .tag = types_Node_individual_node, .data.individual_node = i })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        case decode_IndividualTerm_literal_individual:
                        {
                            literal = 1;
                            break;
                        }
                        case decode_IndividualTerm_anonymous_individual:
                        {
                            anonymous = 1;
                            break;
                        }
                        case decode_IndividualTerm_reserved_individual:
                        {
                            reserved = 1;
                            break;
                        }
                    }
                }
            }
            if (literal) {
                return ((slop_result_decode_NodeList_string){ .is_ok = true, .data.ok = ((decode_NodeList){ .tag = decode_NodeList_has_literal }) });
            } else if (anonymous) {
                return ((slop_result_decode_NodeList_string){ .is_ok = true, .data.ok = ((decode_NodeList){ .tag = decode_NodeList_has_anonymous }) });
            } else if (reserved) {
                return ((slop_result_decode_NodeList_string){ .is_ok = true, .data.ok = ((decode_NodeList){ .tag = decode_NodeList_has_reserved }) });
            } else {
                return ((slop_result_decode_NodeList_string){ .is_ok = true, .data.ok = ((decode_NodeList){ .tag = decode_NodeList_all_named, .data.all_named = out }) });
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_list_owl2_RawConcept_string decode_decode_concept_list(slop_arena* arena, termstore_TermStore g, rdf_Term head, int64_t fuel) {
    __auto_type _mv_433 = decode_rdf_list_checked(arena, g, head);
    if (!_mv_433.is_ok) {
        __auto_type lf = _mv_433.data.err;
        return ((slop_result_list_owl2_RawConcept_string){ .is_ok = false, .data.err = decode_list_fault_message(lf) });
    } else if (_mv_433.is_ok) {
        __auto_type terms = _mv_433.data.ok;
        {
            __auto_type out = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0 });
            slop_option_string fault = (slop_option_string){.has_value = false};
            {
                __auto_type _coll = terms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tm = _coll.data[_i];
                    __auto_type _mv_434 = decode_decode_concept(arena, g, tm, (fuel - 1));
                    if (!_mv_434.is_ok) {
                        __auto_type m = _mv_434.data.err;
                        fault = (slop_option_string){.has_value = 1, .value = m};
                    } else if (_mv_434.is_ok) {
                        __auto_type c = _mv_434.data.ok;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
            __auto_type _mv_435 = fault;
            if (_mv_435.has_value) {
                __auto_type m = _mv_435.value;
                return ((slop_result_list_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (!_mv_435.has_value) {
                return ((slop_result_list_owl2_RawConcept_string){ .is_ok = true, .data.ok = out });
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_owl2_RawConcept_string decode_decode_quantified(slop_arena* arena, termstore_TermStore g, rdf_Term b, slop_string filler_pred, uint8_t universal, int64_t fuel) {
    __auto_type _mv_436 = decode_decode_role(arena, g, b);
    if (!_mv_436.is_ok) {
        __auto_type m = _mv_436.data.err;
        return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
    } else if (_mv_436.is_ok) {
        __auto_type r = _mv_436.data.ok;
        __auto_type _mv_437 = decode_obj_of(arena, g, b, filler_pred);
        if (!_mv_437.is_ok) {
            __auto_type _ = _mv_437.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("quantified restriction without exactly one filler") });
        } else if (_mv_437.is_ok) {
            __auto_type ft = _mv_437.data.ok;
            __auto_type _mv_438 = decode_decode_concept(arena, g, ft, (fuel - 1));
            if (!_mv_438.is_ok) {
                __auto_type m = _mv_438.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_438.is_ok) {
                __auto_type c = _mv_438.data.ok;
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
    __auto_type _mv_439 = decode_decode_role(arena, g, b);
    if (!_mv_439.is_ok) {
        __auto_type m = _mv_439.data.err;
        return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
    } else if (_mv_439.is_ok) {
        __auto_type r = _mv_439.data.ok;
        __auto_type _mv_440 = decode_obj_of(arena, g, b, count_pred);
        if (!_mv_440.is_ok) {
            __auto_type _ = _mv_440.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("cardinality restriction without exactly one count") });
        } else if (_mv_440.is_ok) {
            __auto_type ct = _mv_440.data.ok;
            __auto_type _mv_441 = decode_literal_count(ct);
            if (!_mv_441.is_ok) {
                __auto_type m = _mv_441.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_441.is_ok) {
                __auto_type n = _mv_441.data.ok;
                if (!(qualified)) {
                    return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_card, .data.rc_card = { .f0 = kind, .f1 = r, .f2 = n } }) });
                } else {
                    __auto_type _mv_442 = decode_obj_of(arena, g, b, vocab_OWL_ON_CLASS);
                    if (!_mv_442.is_ok) {
                        __auto_type _ = _mv_442.data.err;
                        return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("qualified cardinality without exactly one owl:onClass") });
                    } else if (_mv_442.is_ok) {
                        __auto_type qt = _mv_442.data.ok;
                        __auto_type _mv_443 = decode_decode_concept(arena, g, qt, (fuel - 1));
                        if (!_mv_443.is_ok) {
                            __auto_type m = _mv_443.data.err;
                            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
                        } else if (_mv_443.is_ok) {
                            __auto_type qc = _mv_443.data.ok;
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
        __auto_type _mv_444 = decode_obj_of(arena, g, b, vocab_OWL_INTERSECTION_OF);
        if (!_mv_444.is_ok) {
            __auto_type _ = _mv_444.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:intersectionOf is absent or ambiguous") });
        } else if (_mv_444.is_ok) {
            __auto_type head = _mv_444.data.ok;
            __auto_type _mv_445 = decode_decode_concept_list(arena, g, head, fuel);
            if (!_mv_445.is_ok) {
                __auto_type m = _mv_445.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_445.is_ok) {
                __auto_type cs = _mv_445.data.ok;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_and, .data.rc_and = cs }) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    } else if (decode_has_pred(arena, g, b, vocab_OWL_UNION_OF)) {
        __auto_type _mv_446 = decode_obj_of(arena, g, b, vocab_OWL_UNION_OF);
        if (!_mv_446.is_ok) {
            __auto_type _ = _mv_446.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:unionOf is absent or ambiguous") });
        } else if (_mv_446.is_ok) {
            __auto_type head = _mv_446.data.ok;
            __auto_type _mv_447 = decode_decode_concept_list(arena, g, head, fuel);
            if (!_mv_447.is_ok) {
                __auto_type m = _mv_447.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_447.is_ok) {
                __auto_type cs = _mv_447.data.ok;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_or, .data.rc_or = cs }) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    } else if (decode_has_pred(arena, g, b, vocab_OWL_ONE_OF)) {
        __auto_type _mv_448 = decode_obj_of(arena, g, b, vocab_OWL_ONE_OF);
        if (!_mv_448.is_ok) {
            __auto_type _ = _mv_448.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:oneOf is absent or ambiguous") });
        } else if (_mv_448.is_ok) {
            __auto_type head = _mv_448.data.ok;
            __auto_type _mv_449 = decode_decode_node_list(arena, g, head);
            if (!_mv_449.is_ok) {
                __auto_type m = _mv_449.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_449.is_ok) {
                __auto_type nl = _mv_449.data.ok;
                __auto_type _mv_450 = nl;
                switch (_mv_450.tag) {
                    case decode_NodeList_all_named:
                    {
                        __auto_type ns = _mv_450.data.all_named;
                        return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_oneof, .data.rc_oneof = ns }) });
                    }
                    case decode_NodeList_has_literal:
                    {
                        return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_data, .data.rc_data = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("owl:oneOf with a literal (DataOneOf)") }) }) });
                    }
                    case decode_NodeList_has_anonymous:
                    {
                        return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_anon, .data.rc_anon = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("owl:oneOf with an anonymous individual") }) }) });
                    }
                    case decode_NodeList_has_reserved:
                    {
                        return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_anon, .data.rc_anon = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("owl:oneOf with a reserved IRI as an individual") }) }) });
                    }
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    } else if (decode_has_pred(arena, g, b, vocab_OWL_COMPLEMENT_OF)) {
        __auto_type _mv_451 = decode_obj_of(arena, g, b, vocab_OWL_COMPLEMENT_OF);
        if (!_mv_451.is_ok) {
            __auto_type _ = _mv_451.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:complementOf is absent or ambiguous") });
        } else if (_mv_451.is_ok) {
            __auto_type ct = _mv_451.data.ok;
            __auto_type _mv_452 = decode_decode_concept(arena, g, ct, (fuel - 1));
            if (!_mv_452.is_ok) {
                __auto_type m = _mv_452.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_452.is_ok) {
                __auto_type c = _mv_452.data.ok;
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
        __auto_type _mv_453 = decode_decode_role(arena, g, b);
        if (!_mv_453.is_ok) {
            __auto_type m = _mv_453.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
        } else if (_mv_453.is_ok) {
            __auto_type r = _mv_453.data.ok;
            __auto_type _mv_454 = decode_obj_of(arena, g, b, vocab_OWL_HAS_VALUE);
            if (!_mv_454.is_ok) {
                __auto_type _ = _mv_454.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:hasValue is absent or ambiguous") });
            } else if (_mv_454.is_ok) {
                __auto_type vt = _mv_454.data.ok;
                __auto_type _mv_455 = decode_individual_term(vt);
                switch (_mv_455.tag) {
                    case decode_IndividualTerm_named_individual:
                    {
                        __auto_type i = _mv_455.data.named_individual;
                        return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_has_value, .data.rc_has_value = { .f0 = r, .f1 = ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = i }) } }) });
                    }
                    case decode_IndividualTerm_literal_individual:
                    {
                        return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_data, .data.rc_data = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("owl:hasValue with a literal (DataHasValue)") }) }) });
                    }
                    case decode_IndividualTerm_anonymous_individual:
                    {
                        return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_anon, .data.rc_anon = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("owl:hasValue on an anonymous individual") }) }) });
                    }
                    case decode_IndividualTerm_reserved_individual:
                    {
                        return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_anon, .data.rc_anon = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("owl:hasValue on a reserved IRI as an individual") }) }) });
                    }
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    } else if (decode_has_pred(arena, g, b, vocab_OWL_HAS_SELF)) {
        __auto_type _mv_456 = decode_decode_role(arena, g, b);
        if (!_mv_456.is_ok) {
            __auto_type m = _mv_456.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
        } else if (_mv_456.is_ok) {
            __auto_type r = _mv_456.data.ok;
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
        __auto_type _mv_457 = t;
        switch (_mv_457.tag) {
            case rdf_Term_term_iri:
            {
                __auto_type i = _mv_457.data.term_iri;
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
                __auto_type _ = _mv_457.data.term_literal;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_data, .data.rc_data = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("literal in a class position") }) }) });
            }
            case rdf_Term_term_triple:
            {
                __auto_type _ = _mv_457.data.term_triple;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_anon, .data.rc_anon = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("RDF-star triple term in a class position") }) }) });
            }
            case rdf_Term_term_blank:
            {
                __auto_type _ = _mv_457.data.term_blank;
                return decode_decode_anon(arena, g, t, fuel);
            }
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t decode_declare_entity(slop_arena* arena, owl2_Signature sig, rdf_IRI entity, slop_string type_iri) {
    if (canon_string_cmp(type_iri, vocab_OWL_CLASS) == 0) {
        ({ slop_map_put(arena, sig.classes, &(entity), NULL, 0); });
        return 1;
    } else if (canon_string_cmp(type_iri, vocab_OWL_OBJECT_PROPERTY) == 0) {
        ({ slop_map_put(arena, sig.obj_props, &(entity), NULL, 0); });
        return 1;
    } else if (canon_string_cmp(type_iri, vocab_OWL_DATATYPE_PROPERTY) == 0) {
        ({ slop_map_put(arena, sig.data_props, &(entity), NULL, 0); });
        return 1;
    } else if (canon_string_cmp(type_iri, vocab_OWL_ANNOTATION_PROPERTY) == 0) {
        ({ slop_map_put(arena, sig.annot_props, &(entity), NULL, 0); });
        return 1;
    } else if (canon_string_cmp(type_iri, vocab_OWL_NAMED_INDIVIDUAL) == 0) {
        ({ slop_map_put(arena, sig.individuals, &(entity), NULL, 0); });
        return 1;
    } else if (canon_string_cmp(type_iri, vocab_RDFS_DATATYPE) == 0) {
        ({ slop_map_put(arena, sig.datatypes, &(entity), NULL, 0); });
        return 1;
    } else {
        return 0;
    }
}

uint8_t decode_add_builtins(slop_arena* arena, owl2_Signature sig) {
    ({ rdf_IRI _key_464 = (((rdf_IRI){.value = vocab_OWL_THING})); slop_map_put(arena, sig.classes, &_key_464, NULL, 0); });
    ({ rdf_IRI _key_465 = (((rdf_IRI){.value = vocab_OWL_NOTHING})); slop_map_put(arena, sig.classes, &_key_465, NULL, 0); });
    ({ rdf_IRI _key_466 = (((rdf_IRI){.value = vocab_OWL_TOP_OBJECT_PROPERTY})); slop_map_put(arena, sig.obj_props, &_key_466, NULL, 0); });
    ({ rdf_IRI _key_467 = (((rdf_IRI){.value = vocab_OWL_BOTTOM_OBJECT_PROPERTY})); slop_map_put(arena, sig.obj_props, &_key_467, NULL, 0); });
    ({ rdf_IRI _key_468 = (((rdf_IRI){.value = vocab_OWL_TOP_DATA_PROPERTY})); slop_map_put(arena, sig.data_props, &_key_468, NULL, 0); });
    ({ rdf_IRI _key_469 = (((rdf_IRI){.value = vocab_OWL_BOTTOM_DATA_PROPERTY})); slop_map_put(arena, sig.data_props, &_key_469, NULL, 0); });
    ({ rdf_IRI _key_470 = (((rdf_IRI){.value = vocab_RDFS_LABEL})); slop_map_put(arena, sig.annot_props, &_key_470, NULL, 0); });
    ({ rdf_IRI _key_471 = (((rdf_IRI){.value = vocab_RDFS_COMMENT})); slop_map_put(arena, sig.annot_props, &_key_471, NULL, 0); });
    ({ rdf_IRI _key_472 = (((rdf_IRI){.value = vocab_RDFS_SEE_ALSO})); slop_map_put(arena, sig.annot_props, &_key_472, NULL, 0); });
    ({ rdf_IRI _key_473 = (((rdf_IRI){.value = vocab_RDFS_IS_DEFINED_BY})); slop_map_put(arena, sig.annot_props, &_key_473, NULL, 0); });
    ({ rdf_IRI _key_474 = (((rdf_IRI){.value = vocab_OWL_VERSION_INFO})); slop_map_put(arena, sig.annot_props, &_key_474, NULL, 0); });
    ({ rdf_IRI _key_475 = (((rdf_IRI){.value = vocab_OWL_DEPRECATED})); slop_map_put(arena, sig.annot_props, &_key_475, NULL, 0); });
    ({ rdf_IRI _key_476 = (((rdf_IRI){.value = vocab_OWL_PRIOR_VERSION})); slop_map_put(arena, sig.annot_props, &_key_476, NULL, 0); });
    ({ rdf_IRI _key_477 = (((rdf_IRI){.value = vocab_OWL_BACKWARD_COMPATIBLE_WITH})); slop_map_put(arena, sig.annot_props, &_key_477, NULL, 0); });
    ({ rdf_IRI _key_478 = (((rdf_IRI){.value = vocab_OWL_INCOMPATIBLE_WITH})); slop_map_put(arena, sig.annot_props, &_key_478, NULL, 0); });
    return 1;
}

owl2_Signature decode_build_signature(slop_arena* arena, termstore_TermStore dict, slop_list_termstore_IdTriple triples) {
    {
        __auto_type sig = owl2_make_signature(arena);
        __auto_type type_pred = dict.rdf_type;
        decode_add_builtins(arena, sig);
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (it.p == type_pred) {
                    __auto_type _mv_479 = decode_term_iri_value(termstore_term_of(dict, it.s));
                    if (_mv_479.has_value) {
                        __auto_type s = _mv_479.value;
                        __auto_type _mv_480 = decode_term_iri_value(termstore_term_of(dict, it.o));
                        if (_mv_480.has_value) {
                            __auto_type o = _mv_480.value;
                            decode_declare_entity(arena, sig, s, o.value);
                        } else if (!_mv_480.has_value) {
                            0;
                        }
                    } else if (!_mv_479.has_value) {
                        0;
                    }
                }
            }
        }
        return sig;
    }
}

slop_string decode_render_term(slop_arena* arena, rdf_Term t) {
    __auto_type _mv_481 = t;
    switch (_mv_481.tag) {
        case rdf_Term_term_iri:
        {
            __auto_type i = _mv_481.data.term_iri;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">")));
        }
        case rdf_Term_term_blank:
        {
            __auto_type b = _mv_481.data.term_blank;
            return string_concat(arena, SLOP_STR("_:b"), int_to_string(arena, b.id));
        }
        case rdf_Term_term_literal:
        {
            __auto_type l = _mv_481.data.term_literal;
            return string_concat(arena, SLOP_STR("\""), string_concat(arena, l.value, SLOP_STR("\"")));
        }
        case rdf_Term_term_triple:
        {
            __auto_type _ = _mv_481.data.term_triple;
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
    __auto_type _mv_482 = decode_term_iri_value(t.predicate);
    if (_mv_482.has_value) {
        __auto_type i = _mv_482.value;
        return (canon_string_cmp(i.value, iri) == 0);
    } else if (!_mv_482.has_value) {
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
            __auto_type _mv_483 = decode_term_iri_value(t.object);
            if (_mv_483.has_value) {
                __auto_type o = _mv_483.value;
                return (({ __auto_type _mv = t.subject; uint8_t _mr = {0}; switch (_mv.tag) { case rdf_Term_term_blank: { __auto_type _ = _mv.data.term_blank; _mr = 1; break; } case rdf_Term_term_iri: { __auto_type _ = _mv.data.term_iri; _mr = 0; break; } case rdf_Term_term_literal: { __auto_type _ = _mv.data.term_literal; _mr = 0; break; } case rdf_Term_term_triple: { __auto_type _ = _mv.data.term_triple; _mr = 0; break; }  } _mr; }) && ((canon_string_cmp(o.value, vocab_OWL_CLASS) == 0) || (canon_string_cmp(o.value, vocab_OWL_RESTRICTION) == 0)));
            } else if (!_mv_483.has_value) {
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
    __auto_type _mv_484 = decode_term_iri_value(t);
    if (_mv_484.has_value) {
        __auto_type i = _mv_484.value;
        return (slop_option_types_RoleId){.has_value = 1, .value = ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = i })};
    } else if (!_mv_484.has_value) {
        return (slop_option_types_RoleId){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

slop_result_list_types_RoleId_string decode_decode_role_list(slop_arena* arena, termstore_TermStore g, rdf_Term head) {
    __auto_type _mv_485 = decode_rdf_list_checked(arena, g, head);
    if (!_mv_485.is_ok) {
        __auto_type lf = _mv_485.data.err;
        return ((slop_result_list_types_RoleId_string){ .is_ok = false, .data.err = decode_list_fault_message(lf) });
    } else if (_mv_485.is_ok) {
        __auto_type terms = _mv_485.data.ok;
        {
            __auto_type out = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 });
            slop_option_string fault = (slop_option_string){.has_value = false};
            {
                __auto_type _coll = terms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tm = _coll.data[_i];
                    __auto_type _mv_486 = decode_role_of_term(tm);
                    if (_mv_486.has_value) {
                        __auto_type r = _mv_486.value;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_486.has_value) {
                        fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("property chain step is not a named property")};
                    }
                }
            }
            __auto_type _mv_487 = fault;
            if (_mv_487.has_value) {
                __auto_type m = _mv_487.value;
                return ((slop_result_list_types_RoleId_string){ .is_ok = false, .data.err = m });
            } else if (!_mv_487.has_value) {
                return ((slop_result_list_types_RoleId_string){ .is_ok = true, .data.ok = out });
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_list_owl2_RawConcept_string decode_binary_concepts(slop_arena* arena, termstore_TermStore g, rdf_Triple t) {
    __auto_type _mv_488 = decode_decode_concept(arena, g, t.subject, decode_CONCEPT_FUEL);
    if (!_mv_488.is_ok) {
        __auto_type m = _mv_488.data.err;
        return ((slop_result_list_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
    } else if (_mv_488.is_ok) {
        __auto_type lhs = _mv_488.data.ok;
        __auto_type _mv_489 = decode_decode_concept(arena, g, t.object, decode_CONCEPT_FUEL);
        if (!_mv_489.is_ok) {
            __auto_type m = _mv_489.data.err;
            return ((slop_result_list_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
        } else if (_mv_489.is_ok) {
            __auto_type rhs = _mv_489.data.ok;
            {
                __auto_type out = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0 });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (lhs); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (rhs); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                return ((slop_result_list_owl2_RawConcept_string){ .is_ok = true, .data.ok = out });
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_option_rdf_Term decode_members_head(slop_arena* arena, termstore_TermStore g, rdf_Term s) {
    __auto_type _mv_490 = decode_obj_of(arena, g, s, vocab_OWL_MEMBERS);
    if (_mv_490.is_ok) {
        __auto_type h = _mv_490.data.ok;
        return (slop_option_rdf_Term){.has_value = 1, .value = h};
    } else if (!_mv_490.is_ok) {
        __auto_type _ = _mv_490.data.err;
        __auto_type _mv_491 = decode_obj_of(arena, g, s, vocab_OWL_DISTINCT_MEMBERS);
        if (_mv_491.is_ok) {
            __auto_type h = _mv_491.data.ok;
            return (slop_option_rdf_Term){.has_value = 1, .value = h};
        } else if (!_mv_491.is_ok) {
            __auto_type _ = _mv_491.data.err;
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
            __auto_type _mv_492 = decode_term_iri_value(t.subject);
            if (_mv_492.has_value) {
                __auto_type s = _mv_492.value;
                __auto_type _mv_493 = decode_entity_kind_of(ov);
                if (_mv_493.has_value) {
                    __auto_type k = _mv_493.value;
                    if ((k == types_EntityKind_entity_individual) && decode_is_reserved_iri(s.value)) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = decode_frag(arena, t) }) });
                    } else {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_declaration, .data.ra_declaration = ((owl2_RawDeclaration){.kind = k, .entity = s}) }) });
                    }
                } else if (!_mv_493.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("unreachable: declaration type vanished") });
                }
                SLOP_UNREACHABLE();
            } else if (!_mv_492.has_value) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = decode_frag(arena, t) }) });
            }
            SLOP_UNREACHABLE();
        } else if (canon_string_cmp(ov, vocab_OWL_TRANSITIVE_PROPERTY) == 0) {
            __auto_type _mv_494 = decode_role_of_term(t.subject);
            if (_mv_494.has_value) {
                __auto_type r = _mv_494.value;
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_transitive_property, .data.ra_transitive_property = r }) });
            } else if (!_mv_494.has_value) {
                if (decode_inverse_expression_term(arena, g, t.subject)) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inverse_expression, .data.ra_inverse_expression = decode_frag(arena, t) }) });
                } else {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:TransitiveProperty on a non-IRI subject") });
                }
            }
            SLOP_UNREACHABLE();
        } else if (({ __auto_type _mv = decode_characteristic_of(ov); _mv.has_value ? ({ __auto_type _ = _mv.value; 1; }) : (0); })) {
            __auto_type _mv_495 = decode_role_of_term(t.subject);
            if (_mv_495.has_value) {
                __auto_type r = _mv_495.value;
                __auto_type _mv_496 = decode_characteristic_of(ov);
                if (_mv_496.has_value) {
                    __auto_type c = _mv_496.value;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_property_characteristic, .data.ra_property_characteristic = { .f0 = c, .f1 = r } }) });
                } else if (!_mv_496.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("unreachable: characteristic vanished") });
                }
                SLOP_UNREACHABLE();
            } else if (!_mv_495.has_value) {
                if (decode_inverse_expression_term(arena, g, t.subject)) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inverse_expression, .data.ra_inverse_expression = decode_frag(arena, t) }) });
                } else {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("property characteristic on a non-IRI subject") });
                }
            }
            SLOP_UNREACHABLE();
        } else if (canon_string_cmp(ov, vocab_OWL_ALL_DIFFERENT) == 0) {
            __auto_type _mv_497 = decode_members_head(arena, g, t.subject);
            if (!_mv_497.has_value) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:AllDifferent without owl:members or owl:distinctMembers") });
            } else if (_mv_497.has_value) {
                __auto_type head = _mv_497.value;
                __auto_type _mv_498 = decode_decode_node_list(arena, g, head);
                if (!_mv_498.is_ok) {
                    __auto_type m = _mv_498.data.err;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                } else if (_mv_498.is_ok) {
                    __auto_type nl = _mv_498.data.ok;
                    __auto_type _mv_499 = nl;
                    switch (_mv_499.tag) {
                        case decode_NodeList_all_named:
                        {
                            __auto_type ns = _mv_499.data.all_named;
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_different_individuals, .data.ra_different_individuals = ns }) });
                        }
                        case decode_NodeList_has_literal:
                        {
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
                        }
                        case decode_NodeList_has_anonymous:
                        {
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = decode_frag(arena, t) }) });
                        }
                        case decode_NodeList_has_reserved:
                        {
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = decode_frag(arena, t) }) });
                        }
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        } else if (canon_string_cmp(ov, vocab_OWL_ALL_DISJOINT_CLASSES) == 0) {
            __auto_type _mv_500 = decode_members_head(arena, g, t.subject);
            if (!_mv_500.has_value) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:AllDisjointClasses without owl:members") });
            } else if (_mv_500.has_value) {
                __auto_type head = _mv_500.value;
                __auto_type _mv_501 = decode_decode_concept_list(arena, g, head, decode_CONCEPT_FUEL);
                if (!_mv_501.is_ok) {
                    __auto_type m = _mv_501.data.err;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                } else if (_mv_501.is_ok) {
                    __auto_type cs = _mv_501.data.ok;
                    if (((int64_t)((cs).len)) < 2) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = decode_frag(arena, t) }) });
                    } else {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_classes, .data.ra_disjoint_classes = cs }) });
                    }
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        } else if (canon_string_cmp(ov, vocab_OWL_ALL_DISJOINT_PROPERTIES) == 0) {
            __auto_type _mv_502 = decode_members_head(arena, g, t.subject);
            if (!_mv_502.has_value) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:AllDisjointProperties without owl:members") });
            } else if (_mv_502.has_value) {
                __auto_type head = _mv_502.value;
                if (decode_list_has_inverse(arena, g, head)) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inverse_expression, .data.ra_inverse_expression = decode_frag(arena, t) }) });
                } else {
                    __auto_type _mv_503 = decode_decode_role_list(arena, g, head);
                    if (!_mv_503.is_ok) {
                        __auto_type m = _mv_503.data.err;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                    } else if (_mv_503.is_ok) {
                        __auto_type rs = _mv_503.data.ok;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_properties, .data.ra_disjoint_properties = rs }) });
                    }
                    SLOP_UNREACHABLE();
                }
            }
            SLOP_UNREACHABLE();
        } else if (canon_string_cmp(ov, vocab_OWL_NEGATIVE_PROPERTY_ASSERTION) == 0) {
            return decode_decode_negative_assertion(arena, g, t);
        } else if (canon_string_cmp(ov, vocab_SWRL_IMP) == 0) {
            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_swrl_rule, .data.ra_swrl_rule = decode_frag(arena, t) }) });
        } else {
            return decode_decode_class_assertion(arena, g, t);
        }
    }
}

slop_result_owl2_RawAxiom_string decode_decode_individual_pair(slop_arena* arena, rdf_Triple t, uint8_t same) {
    __auto_type _mv_504 = decode_individual_term(t.subject);
    switch (_mv_504.tag) {
        case decode_IndividualTerm_literal_individual:
        {
            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
        }
        case decode_IndividualTerm_anonymous_individual:
        {
            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = decode_frag(arena, t) }) });
        }
        case decode_IndividualTerm_reserved_individual:
        {
            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = decode_frag(arena, t) }) });
        }
        case decode_IndividualTerm_named_individual:
        {
            __auto_type a = _mv_504.data.named_individual;
            __auto_type _mv_505 = decode_individual_term(t.object);
            switch (_mv_505.tag) {
                case decode_IndividualTerm_literal_individual:
                {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
                }
                case decode_IndividualTerm_anonymous_individual:
                {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = decode_frag(arena, t) }) });
                }
                case decode_IndividualTerm_reserved_individual:
                {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = decode_frag(arena, t) }) });
                }
                case decode_IndividualTerm_named_individual:
                {
                    __auto_type b = _mv_505.data.named_individual;
                    {
                        __auto_type ns = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
                        ({ __auto_type _lst_p = &(ns); __auto_type _item = (((types_Node){ .tag = types_Node_individual_node, .data.individual_node = a })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(ns); __auto_type _item = (((types_Node){ .tag = types_Node_individual_node, .data.individual_node = b })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        if (same) {
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_same_individual, .data.ra_same_individual = ns }) });
                        } else {
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_different_individuals, .data.ra_different_individuals = ns }) });
                        }
                    }
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_owl2_RawAxiom_string decode_decode_negative_assertion(slop_arena* arena, termstore_TermStore g, rdf_Triple t) {
    {
        __auto_type x = t.subject;
        __auto_type _mv_506 = decode_obj_of(arena, g, x, vocab_OWL_ASSERTION_PROPERTY);
        if (!_mv_506.is_ok) {
            __auto_type _ = _mv_506.data.err;
            return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:NegativePropertyAssertion without exactly one owl:assertionProperty") });
        } else if (_mv_506.is_ok) {
            __auto_type pt = _mv_506.data.ok;
            __auto_type _mv_507 = decode_obj_of(arena, g, x, vocab_OWL_SOURCE_INDIVIDUAL);
            if (!_mv_507.is_ok) {
                __auto_type _ = _mv_507.data.err;
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:NegativePropertyAssertion without exactly one owl:sourceIndividual") });
            } else if (_mv_507.is_ok) {
                __auto_type st = _mv_507.data.ok;
                if (decode_has_pred(arena, g, x, vocab_OWL_TARGET_VALUE) && decode_has_pred(arena, g, x, vocab_OWL_TARGET_INDIVIDUAL)) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:NegativePropertyAssertion with both owl:targetIndividual and owl:targetValue") });
                } else if (decode_has_pred(arena, g, x, vocab_OWL_TARGET_VALUE)) {
                    __auto_type _mv_508 = decode_obj_of(arena, g, x, vocab_OWL_TARGET_VALUE);
                    if (!_mv_508.is_ok) {
                        __auto_type _ = _mv_508.data.err;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:NegativePropertyAssertion without exactly one owl:targetValue") });
                    } else if (_mv_508.is_ok) {
                        __auto_type _ = _mv_508.data.ok;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
                    }
                    SLOP_UNREACHABLE();
                } else {
                    __auto_type _mv_509 = decode_obj_of(arena, g, x, vocab_OWL_TARGET_INDIVIDUAL);
                    if (!_mv_509.is_ok) {
                        __auto_type _ = _mv_509.data.err;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:NegativePropertyAssertion without exactly one owl:targetIndividual") });
                    } else if (_mv_509.is_ok) {
                        __auto_type tt = _mv_509.data.ok;
                        __auto_type _mv_510 = decode_role_of_term(pt);
                        if (!_mv_510.has_value) {
                            if (decode_inverse_expression_term(arena, g, pt)) {
                                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inverse_expression, .data.ra_inverse_expression = decode_frag(arena, t) }) });
                            } else {
                                return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:assertionProperty is not a property") });
                            }
                        } else if (_mv_510.has_value) {
                            __auto_type r = _mv_510.value;
                            __auto_type _mv_511 = decode_individual_term(st);
                            switch (_mv_511.tag) {
                                case decode_IndividualTerm_literal_individual:
                                {
                                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
                                }
                                case decode_IndividualTerm_anonymous_individual:
                                {
                                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = decode_frag(arena, t) }) });
                                }
                                case decode_IndividualTerm_reserved_individual:
                                {
                                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = decode_frag(arena, t) }) });
                                }
                                case decode_IndividualTerm_named_individual:
                                {
                                    __auto_type a = _mv_511.data.named_individual;
                                    __auto_type _mv_512 = decode_individual_term(tt);
                                    switch (_mv_512.tag) {
                                        case decode_IndividualTerm_literal_individual:
                                        {
                                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
                                        }
                                        case decode_IndividualTerm_anonymous_individual:
                                        {
                                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = decode_frag(arena, t) }) });
                                        }
                                        case decode_IndividualTerm_reserved_individual:
                                        {
                                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = decode_frag(arena, t) }) });
                                        }
                                        case decode_IndividualTerm_named_individual:
                                        {
                                            __auto_type b = _mv_512.data.named_individual;
                                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_negative_assertion, .data.ra_negative_assertion = ((owl2_RawEdge){.role = r, .from = ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = a }), .to = ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = b })}) }) });
                                        }
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
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

slop_result_owl2_RawAxiom_string decode_decode_class_assertion(slop_arena* arena, termstore_TermStore g, rdf_Triple t) {
    __auto_type _mv_513 = decode_decode_concept(arena, g, t.object, decode_CONCEPT_FUEL);
    if (!_mv_513.is_ok) {
        __auto_type m = _mv_513.data.err;
        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_513.is_ok) {
        __auto_type c = _mv_513.data.ok;
        __auto_type _mv_514 = decode_term_iri_value(t.subject);
        if (_mv_514.has_value) {
            __auto_type s = _mv_514.value;
            if (decode_is_reserved_iri(s.value)) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = decode_frag(arena, t) }) });
            } else {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_class_assertion, .data.ra_class_assertion = ((owl2_RawClassAssertion){.concept = decode_box_concept(arena, c), .subject = ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = s })}) }) });
            }
        } else if (!_mv_514.has_value) {
            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = decode_frag(arena, t) }) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t decode_is_reserved_iri(slop_string v) {
    return ((strlib_starts_with(v, vocab_OWL_NS)) || (strlib_starts_with(v, vocab_RDF_NS)) || (strlib_starts_with(v, vocab_RDFS_NS)) || (strlib_starts_with(v, vocab_SWRL_NS)) || (strlib_starts_with(v, vocab_XSD_NS)));
}

int64_t decode_property_axiom_kind(owl2_Signature sig, rdf_Term subj) {
    __auto_type _mv_515 = decode_term_iri_value(subj);
    if (!_mv_515.has_value) {
        return 0;
    } else if (_mv_515.has_value) {
        __auto_type i = _mv_515.value;
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
    __auto_type _mv_516 = decode_term_iri_value(t.predicate);
    if (!_mv_516.has_value) {
        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = decode_frag(arena, t) }) });
    } else if (_mv_516.has_value) {
        __auto_type p = _mv_516.value;
        {
            __auto_type pv = p.value;
            if (canon_string_cmp(pv, vocab_RDF_TYPE) == 0) {
                __auto_type _mv_517 = t.object;
                switch (_mv_517.tag) {
                    case rdf_Term_term_iri:
                    {
                        __auto_type o = _mv_517.data.term_iri;
                        return decode_decode_typed(arena, g, t, o);
                    }
                    case rdf_Term_term_blank:
                    {
                        __auto_type _ = _mv_517.data.term_blank;
                        return decode_decode_class_assertion(arena, g, t);
                    }
                    default: {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = decode_frag(arena, t) }) });
                    }
                }
            } else if (decode_property_axiom_on_inverse(arena, g, pv, t)) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inverse_expression, .data.ra_inverse_expression = decode_frag(arena, t) }) });
            } else if (canon_string_cmp(pv, vocab_RDFS_SUBCLASS_OF) == 0) {
                __auto_type _mv_518 = decode_decode_concept(arena, g, t.subject, decode_CONCEPT_FUEL);
                if (!_mv_518.is_ok) {
                    __auto_type m = _mv_518.data.err;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                } else if (_mv_518.is_ok) {
                    __auto_type lhs = _mv_518.data.ok;
                    __auto_type _mv_519 = decode_decode_concept(arena, g, t.object, decode_CONCEPT_FUEL);
                    if (!_mv_519.is_ok) {
                        __auto_type m = _mv_519.data.err;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                    } else if (_mv_519.is_ok) {
                        __auto_type rhs = _mv_519.data.ok;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_sub_class_of, .data.ra_sub_class_of = { .f0 = decode_box_concept(arena, lhs), .f1 = decode_box_concept(arena, rhs) } }) });
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_OWL_EQUIVALENT_CLASS) == 0) {
                __auto_type _mv_520 = decode_binary_concepts(arena, g, t);
                if (!_mv_520.is_ok) {
                    __auto_type m = _mv_520.data.err;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                } else if (_mv_520.is_ok) {
                    __auto_type cs = _mv_520.data.ok;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_equivalent_classes, .data.ra_equivalent_classes = cs }) });
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_OWL_DISJOINT_WITH) == 0) {
                __auto_type _mv_521 = decode_binary_concepts(arena, g, t);
                if (!_mv_521.is_ok) {
                    __auto_type m = _mv_521.data.err;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                } else if (_mv_521.is_ok) {
                    __auto_type cs = _mv_521.data.ok;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_classes, .data.ra_disjoint_classes = cs }) });
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_OWL_PROPERTY_CHAIN_AXIOM) == 0) {
                __auto_type _mv_522 = decode_role_of_term(t.subject);
                if (!_mv_522.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:propertyChainAxiom on a non-IRI subject") });
                } else if (_mv_522.has_value) {
                    __auto_type super = _mv_522.value;
                    __auto_type _mv_523 = decode_decode_role_list(arena, g, t.object);
                    if (!_mv_523.is_ok) {
                        __auto_type m = _mv_523.data.err;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                    } else if (_mv_523.is_ok) {
                        __auto_type steps = _mv_523.data.ok;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_property_chain, .data.ra_property_chain = ((owl2_RawChain){.steps = steps, .super = super}) }) });
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_RDFS_SUBPROPERTY_OF) == 0) {
                if (decode_property_axiom_kind(sig, t.subject) == 1) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_annotation }) });
                } else if (decode_property_axiom_kind(sig, t.subject) == 2) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
                } else {
                    __auto_type _mv_524 = decode_role_of_term(t.subject);
                    if (!_mv_524.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("rdfs:subPropertyOf on a non-IRI subject") });
                    } else if (_mv_524.has_value) {
                        __auto_type sub = _mv_524.value;
                        __auto_type _mv_525 = decode_role_of_term(t.object);
                        if (!_mv_525.has_value) {
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("rdfs:subPropertyOf with a non-IRI object") });
                        } else if (_mv_525.has_value) {
                            __auto_type sup = _mv_525.value;
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_sub_object_property, .data.ra_sub_object_property = { .f0 = sub, .f1 = sup } }) });
                        }
                        SLOP_UNREACHABLE();
                    }
                    SLOP_UNREACHABLE();
                }
            } else if (canon_string_cmp(pv, vocab_OWL_EQUIVALENT_PROPERTY) == 0) {
                __auto_type _mv_526 = decode_role_of_term(t.subject);
                if (!_mv_526.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:equivalentProperty on a non-IRI subject") });
                } else if (_mv_526.has_value) {
                    __auto_type a = _mv_526.value;
                    __auto_type _mv_527 = decode_role_of_term(t.object);
                    if (!_mv_527.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:equivalentProperty with a non-IRI object") });
                    } else if (_mv_527.has_value) {
                        __auto_type b = _mv_527.value;
                        {
                            __auto_type rs = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 });
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_equivalent_properties, .data.ra_equivalent_properties = rs }) });
                        }
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_OWL_PROPERTY_DISJOINT_WITH) == 0) {
                __auto_type _mv_528 = decode_role_of_term(t.subject);
                if (!_mv_528.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:propertyDisjointWith on a non-IRI subject") });
                } else if (_mv_528.has_value) {
                    __auto_type a = _mv_528.value;
                    __auto_type _mv_529 = decode_role_of_term(t.object);
                    if (!_mv_529.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:propertyDisjointWith with a non-IRI object") });
                    } else if (_mv_529.has_value) {
                        __auto_type b = _mv_529.value;
                        {
                            __auto_type rs = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 });
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_properties, .data.ra_disjoint_properties = rs }) });
                        }
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_OWL_INVERSE_OF) == 0) {
                __auto_type _mv_530 = decode_role_of_term(t.subject);
                if (!_mv_530.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:inverseOf on a non-IRI subject") });
                } else if (_mv_530.has_value) {
                    __auto_type a = _mv_530.value;
                    __auto_type _mv_531 = decode_role_of_term(t.object);
                    if (!_mv_531.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:inverseOf with a non-IRI object") });
                    } else if (_mv_531.has_value) {
                        __auto_type b = _mv_531.value;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inverse_properties, .data.ra_inverse_properties = { .f0 = a, .f1 = b } }) });
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_RDFS_DOMAIN) == 0) {
                if (decode_property_axiom_kind(sig, t.subject) == 1) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_annotation }) });
                } else if (decode_property_axiom_kind(sig, t.subject) == 2) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
                } else {
                    __auto_type _mv_532 = decode_role_of_term(t.subject);
                    if (!_mv_532.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("rdfs:domain on a non-IRI subject") });
                    } else if (_mv_532.has_value) {
                        __auto_type r = _mv_532.value;
                        __auto_type _mv_533 = decode_decode_concept(arena, g, t.object, decode_CONCEPT_FUEL);
                        if (!_mv_533.is_ok) {
                            __auto_type m = _mv_533.data.err;
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                        } else if (_mv_533.is_ok) {
                            __auto_type c = _mv_533.data.ok;
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_object_property_domain, .data.ra_object_property_domain = { .f0 = r, .f1 = decode_box_concept(arena, c) } }) });
                        }
                        SLOP_UNREACHABLE();
                    }
                    SLOP_UNREACHABLE();
                }
            } else if (canon_string_cmp(pv, vocab_RDFS_RANGE) == 0) {
                if (decode_property_axiom_kind(sig, t.subject) == 1) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_annotation }) });
                } else if (decode_property_axiom_kind(sig, t.subject) == 2) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
                } else {
                    __auto_type _mv_534 = decode_role_of_term(t.subject);
                    if (!_mv_534.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("rdfs:range on a non-IRI subject") });
                    } else if (_mv_534.has_value) {
                        __auto_type r = _mv_534.value;
                        __auto_type _mv_535 = decode_decode_concept(arena, g, t.object, decode_CONCEPT_FUEL);
                        if (!_mv_535.is_ok) {
                            __auto_type m = _mv_535.data.err;
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                        } else if (_mv_535.is_ok) {
                            __auto_type c = _mv_535.data.ok;
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_object_property_range, .data.ra_object_property_range = { .f0 = r, .f1 = decode_box_concept(arena, c) } }) });
                        }
                        SLOP_UNREACHABLE();
                    }
                    SLOP_UNREACHABLE();
                }
            } else if (canon_string_cmp(pv, vocab_OWL_SAME_AS) == 0) {
                return decode_decode_individual_pair(arena, t, 1);
            } else if (canon_string_cmp(pv, vocab_OWL_DIFFERENT_FROM) == 0) {
                return decode_decode_individual_pair(arena, t, 0);
            } else if (canon_string_cmp(pv, vocab_OWL_DISJOINT_UNION_OF) == 0) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_union, .data.ra_disjoint_union = decode_frag(arena, t) }) });
            } else if (canon_string_cmp(pv, vocab_OWL_HAS_KEY) == 0) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_has_key, .data.ra_has_key = decode_frag(arena, t) }) });
            } else if (owl2_signature_has_annotation_property(sig, p)) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_annotation }) });
            } else if (owl2_signature_has_object_property(sig, p)) {
                __auto_type _mv_536 = decode_role_of_term(t.predicate);
                if (!_mv_536.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("unreachable: declared object property is not an IRI") });
                } else if (_mv_536.has_value) {
                    __auto_type r = _mv_536.value;
                    __auto_type _mv_537 = decode_term_iri_value(t.subject);
                    if (!_mv_537.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = decode_frag(arena, t) }) });
                    } else if (_mv_537.has_value) {
                        __auto_type sfrom = _mv_537.value;
                        __auto_type _mv_538 = decode_term_iri_value(t.object);
                        if (!_mv_538.has_value) {
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = decode_frag(arena, t) }) });
                        } else if (_mv_538.has_value) {
                            __auto_type sto = _mv_538.value;
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

slop_result_decode_Stage1_types_Fault decode_decode_axioms(slop_arena* arena, termstore_TermStore dict, slop_list_termstore_IdTriple triples) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type res = decode_decode_axioms_with(arena, decode_decode_store(scratch, dict, triples), dict, triples);
        ({ slop_arena_free(scratch); free(scratch); });
        return res;
    }
}

termstore_TermStore decode_decode_store(slop_arena* arena, termstore_TermStore dict, slop_list_termstore_IdTriple triples) {
    {
        __auto_type st = termstore_store_over(arena, dict);
        __auto_type keep = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = decode_queried_predicates(arena);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type iri = _coll.data[_i];
                {
                    __auto_type id = decode_vocab_id(arena, dict, iri);
                    if (id >= 0) {
                        ({ slop_map_put(arena, keep, &(int64_t){id}, NULL, 0); });
                    }
                }
            }
        }
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (slop_map_has(keep, &(int64_t){it.p})) {
                    termstore_store_insert_ids(arena, st, it);
                }
            }
        }
        return st;
    }
}

slop_list_string decode_queried_predicates(slop_arena* arena) {
    {
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_RDF_FIRST); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_RDF_REST); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_ON_PROPERTY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_INVERSE_OF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_INTERSECTION_OF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_UNION_OF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_ONE_OF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_COMPLEMENT_OF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_SOME_VALUES_FROM); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_ALL_VALUES_FROM); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_HAS_VALUE); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_HAS_SELF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_QUALIFIED_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_MIN_QUALIFIED_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_MAX_QUALIFIED_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_MIN_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_MAX_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_ON_CLASS); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_MEMBERS); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_DISTINCT_MEMBERS); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_SOURCE_INDIVIDUAL); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_ASSERTION_PROPERTY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_TARGET_INDIVIDUAL); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_TARGET_VALUE); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ps;
    }
}

slop_result_decode_Stage1_types_Fault decode_decode_axioms_with(slop_arena* arena, termstore_TermStore ig, termstore_TermStore dict, slop_list_termstore_IdTriple triples) {
    {
        __auto_type sig = decode_build_signature(arena, dict, triples);
        __auto_type out = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0 });
        int64_t inert = 0;
        slop_option_string fault = (slop_option_string){.has_value = false};
        fault = decode_declaration_conflict(arena, sig, dict, triples);
        {
            __auto_type npa_nodes = decode_negative_assertion_nodes(arena, dict, triples);
            __auto_type npa_parts = decode_negative_assertion_parts(arena, dict);
            {
                __auto_type _coll = triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type it = _coll.data[_i];
                    {
                        __auto_type t = termstore_triple_of(dict, it);
                        if (!(decode_structural_triple(t)) && !(decode_negative_assertion_part(it, npa_nodes, npa_parts))) {
                            __auto_type _mv_541 = decode_decode_axiom(arena, ig, sig, t);
                            if (!_mv_541.is_ok) {
                                __auto_type m = _mv_541.data.err;
                                fault = (slop_option_string){.has_value = 1, .value = m};
                            } else if (_mv_541.is_ok) {
                                __auto_type ax = _mv_541.data.ok;
                                __auto_type _mv_542 = owl2_disposition(types_Profile_profile_el, ax);
                                if (_mv_542 == owl2_Disposition_d_inert) {
                                    inert = (inert + 1);
                                } else if (_mv_542 == owl2_Disposition_d_consumed) {
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                } else if (_mv_542 == owl2_Disposition_d_in_profile) {
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                } else if (_mv_542 == owl2_Disposition_d_out_of_profile) {
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                }
            }
        }
        __auto_type _mv_543 = fault;
        if (_mv_543.has_value) {
            __auto_type m = _mv_543.value;
            return ((slop_result_decode_Stage1_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_input_error, .data.input_error = m }) });
        } else if (!_mv_543.has_value) {
            return ((slop_result_decode_Stage1_types_Fault){ .is_ok = true, .data.ok = ((decode_Stage1){.axioms = out, .signature = sig, .inert = inert}) });
        }
        SLOP_UNREACHABLE();
    }
}

slop_map* decode_negative_assertion_nodes(slop_arena* arena, termstore_TermStore dict, slop_list_termstore_IdTriple triples) {
    {
        __auto_type npa = decode_vocab_id(arena, dict, vocab_OWL_NEGATIVE_PROPERTY_ASSERTION);
        __auto_type type_pred = dict.rdf_type;
        __auto_type out = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        if (npa >= 0) {
            {
                __auto_type _coll = triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type it = _coll.data[_i];
                    if ((it.p == type_pred) && (it.o == npa)) {
                        ({ slop_map_put(arena, out, &(int64_t){it.s}, NULL, 0); });
                    }
                }
            }
        }
        return out;
    }
}

slop_map* decode_negative_assertion_parts(slop_arena* arena, termstore_TermStore dict) {
    {
        __auto_type out = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 4 * sizeof(slop_string)), .len = 4, .cap = 4 }; _ll.data[0] = vocab_OWL_SOURCE_INDIVIDUAL; _ll.data[1] = vocab_OWL_ASSERTION_PROPERTY; _ll.data[2] = vocab_OWL_TARGET_INDIVIDUAL; _ll.data[3] = vocab_OWL_TARGET_VALUE; _ll; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type iri = _coll.data[_i];
                {
                    __auto_type id = decode_vocab_id(arena, dict, iri);
                    if (id >= 0) {
                        ({ slop_map_put(arena, out, &(int64_t){id}, NULL, 0); });
                    }
                }
            }
        }
        return out;
    }
}

uint8_t decode_negative_assertion_part(termstore_IdTriple it, slop_map* nodes, slop_map* parts) {
    return (slop_map_has(parts, &(int64_t){it.p}) && slop_map_has(nodes, &(int64_t){it.s}));
}

slop_option_string decode_declaration_conflict(slop_arena* arena, owl2_Signature sig, termstore_TermStore dict, slop_list_termstore_IdTriple triples) {
    {
        __auto_type type_pred = dict.rdf_type;
        slop_option_string bad = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (it.p == type_pred) {
                    __auto_type _mv_548 = decode_term_iri_value(termstore_term_of(dict, it.s));
                    if (_mv_548.has_value) {
                        __auto_type e = _mv_548.value;
                        {
                            __auto_type np = (((owl2_signature_has_object_property(sig, e)) ? 1 : 0) + (((owl2_signature_has_data_property(sig, e)) ? 1 : 0) + ((owl2_signature_has_annotation_property(sig, e)) ? 1 : 0)));
                            if (np > 1) {
                                bad = (slop_option_string){.has_value = 1, .value = string_concat(arena, SLOP_STR("IRI declared under two disjoint property kinds: "), e.value)};
                            }
                        }
                    } else if (!_mv_548.has_value) {
                    }
                }
            }
        }
        return bad;
    }
}

