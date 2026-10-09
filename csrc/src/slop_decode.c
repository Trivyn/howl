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
slop_option_types_RoleId decode_property_expression(slop_arena* arena, termstore_TermStore g, rdf_Term t);
uint8_t decode_malformed_inverse(slop_arena* arena, termstore_TermStore g, rdf_Triple t);
uint8_t decode_data_property_term(slop_arena* arena, termstore_TermStore g, rdf_Term t);
uint8_t decode_restriction_on_data(slop_arena* arena, termstore_TermStore g, rdf_Term b);
slop_string decode_data_restriction_pred(slop_arena* arena, termstore_TermStore g, rdf_Term b);
slop_string decode_data_restriction_name(slop_string pred);
slop_string decode_filler_text(slop_arena* arena, rdf_Term t);
owl2_RawConcept decode_nary_data_restriction(slop_arena* arena, termstore_TermStore g, rdf_Term b);
owl2_RawConcept decode_data_restriction(slop_arena* arena, termstore_TermStore g, rdf_Term b);
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
uint8_t decode_list_has_data(slop_arena* arena, termstore_TermStore g, rdf_Term head);
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
decode_DataVocab decode_data_vocab(slop_arena* arena, termstore_TermStore dict);
decode_DataLemma decode_data_lemma(slop_arena* arena, termstore_TermStore dict, owl2_Signature sig, decode_DataVocab v, slop_list_termstore_IdTriple triples);
void decode_mark_data_uses(termstore_TermStore dict, owl2_Signature sig, decode_DataVocab v, slop_map* data, slop_map* used, termstore_IdTriple it);
uint8_t decode_predicate_is_annotation(termstore_TermStore dict, owl2_Signature sig, int64_t p);
void decode_collect_inert_trees(slop_arena* arena, termstore_TermStore dict, decode_DataVocab v, slop_map* idle, slop_map* tree, slop_list_termstore_IdTriple triples);
uint8_t decode_filler_triple(rdf_Triple t, uint8_t restriction, uint8_t single);
uint8_t decode_id_is_blank(termstore_TermStore dict, int64_t id);
uint8_t decode_inert_data_axiom(decode_DataVocab v, decode_DataLemma lemma, termstore_IdTriple it);
slop_map* decode_negative_assertion_nodes(slop_arena* arena, termstore_TermStore dict, slop_list_termstore_IdTriple triples);
slop_map* decode_negative_assertion_parts(slop_arena* arena, termstore_TermStore dict);
uint8_t decode_negative_assertion_part(termstore_IdTriple it, slop_map* nodes, slop_map* parts);
slop_option_string decode_declaration_conflict(slop_arena* arena, owl2_Signature sig, termstore_TermStore dict, slop_list_termstore_IdTriple triples);

rdf_Term decode_term_at(slop_list_rdf_Term xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_635 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_635.has_value) {
        __auto_type v = _mv_635.value;
        return v;
    } else if (!_mv_635.has_value) {
        return ((rdf_Term){ .tag = rdf_Term_term_blank, .data.term_blank = ((rdf_BlankNode){.id = 0}) });
    }
    SLOP_UNREACHABLE();
}

rdf_Triple decode_triple_at(slop_list_rdf_Triple xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    {
        __auto_type blank = ((rdf_Term){ .tag = rdf_Term_term_blank, .data.term_blank = ((rdf_BlankNode){.id = 0}) });
        __auto_type _mv_636 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_rdf_Triple _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_636.has_value) {
            __auto_type v = _mv_636.value;
            return v;
        } else if (!_mv_636.has_value) {
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
            __auto_type _mv_637 = termstore_store_sole_object(g, subj, pred);
            if (_mv_637.has_value) {
                __auto_type o = _mv_637.value;
                return ((slop_result_rdf_Term_decode_LookupFault){ .is_ok = true, .data.ok = o });
            } else if (!_mv_637.has_value) {
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
        __auto_type out = ((slop_list_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type visited = ({ static const slop_map_desc _d = SLOP_SET_DESC(rdf_Term, slop_hash_rdf_Term, slop_eq_rdf_Term, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type current = head;
        slop_option_decode_ListFault fault = (slop_option_decode_ListFault){.has_value = false};
        uint8_t done = 0;
        while (!(done) && !(rdf_term_eq(current, nil_term))) {
            if (slop_map_has(visited, &(current))) {
                fault = (slop_option_decode_ListFault){.has_value = 1, .value = ((decode_ListFault){ .tag = decode_ListFault_list_cyclic, .data.list_cyclic = SLOP_STR("rdf:rest returns to a cell already visited") })};
                done = 1;
            } else {
                ({ slop_map_put(NULL, visited, &(current), NULL, 0); });
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
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (decode_term_at(firsts, 0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            current = decode_term_at(rests, 0);
                        }
                    }
                }
            }
        }
        __auto_type _mv_640 = fault;
        if (_mv_640.has_value) {
            __auto_type f = _mv_640.value;
            return ((slop_result_list_rdf_Term_decode_ListFault){ .is_ok = false, .data.err = f });
        } else if (!_mv_640.has_value) {
            return ((slop_result_list_rdf_Term_decode_ListFault){ .is_ok = true, .data.ok = out });
        }
        SLOP_UNREACHABLE();
    }
}

slop_option_rdf_IRI decode_term_iri_value(rdf_Term t) {
    __auto_type _mv_641 = t;
    switch (_mv_641.tag) {
        case rdf_Term_term_iri:
        {
            __auto_type i = _mv_641.data.term_iri;
            return (slop_option_rdf_IRI){.has_value = 1, .value = i};
        }
        case rdf_Term_term_blank:
        {
            __auto_type _ = _mv_641.data.term_blank;
            return (slop_option_rdf_IRI){.has_value = false};
        }
        case rdf_Term_term_literal:
        {
            __auto_type _ = _mv_641.data.term_literal;
            return (slop_option_rdf_IRI){.has_value = false};
        }
        case rdf_Term_term_triple:
        {
            __auto_type _ = _mv_641.data.term_triple;
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
        __auto_type out = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = doc.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (it.p == imports_id) {
                    __auto_type _mv_642 = decode_term_iri_value(termstore_term_of(doc.dict, it.o));
                    if (_mv_642.has_value) {
                        __auto_type i = _mv_642.value;
                        if (!(decode_iri_in_list(out, i))) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    } else if (!_mv_642.has_value) {
                    }
                }
            }
        }
        return canon_sort_iris(arena, out);
    }
}

int64_t decode_vocab_id(slop_arena* arena, termstore_TermStore dict, slop_string iri) {
    __auto_type _mv_643 = termstore_lookup_term(dict, rdf_make_iri(arena, iri));
    if (_mv_643.has_value) {
        __auto_type i = _mv_643.value;
        return i;
    } else if (!_mv_643.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

slop_list_types_Omission decode_unresolved_imports(slop_arena* arena, slop_list_rdf_IRI declared, slop_list_rdf_IRI resolved) {
    {
        __auto_type out = ((slop_list_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = declared;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type d = _coll.data[_i];
                if (!(decode_iri_in_list(resolved, d))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_Omission){ .tag = types_Omission_unresolved_import, .data.unresolved_import = d })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return canon_sort_omissions(arena, out);
    }
}

uint8_t decode_typed_as(rdf_Triple t, slop_string type_iri) {
    __auto_type _mv_644 = decode_term_iri_value(t.predicate);
    if (!_mv_644.has_value) {
        return 0;
    } else if (_mv_644.has_value) {
        __auto_type p = _mv_644.value;
        return ((canon_string_cmp(p.value, vocab_RDF_TYPE) == 0) && ({ __auto_type _mv = decode_term_iri_value(t.object); _mv.has_value ? ({ __auto_type o = _mv.value; (canon_string_cmp(o.value, type_iri) == 0); }) : (0); }));
    }
    SLOP_UNREACHABLE();
}

slop_list_int decode_typed_ids_in_order(slop_arena* arena, termstore_Encoded doc, slop_string type_iri) {
    {
        __auto_type type_pred = doc.dict.rdf_type;
        __auto_type type_id = decode_vocab_id(arena, doc.dict, type_iri);
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = doc.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if ((it.p == type_pred) && (it.o == type_id)) {
                    if (!(slop_map_has(seen, &(int64_t){it.s}))) {
                        ({ slop_map_put(NULL, seen, &(int64_t){it.s}, NULL, 0); });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (it.s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    __auto_type _mv_647 = decode_term_iri_value(t.predicate);
    if (!_mv_647.has_value) {
        return 0;
    } else if (_mv_647.has_value) {
        __auto_type p = _mv_647.value;
        if (canon_string_cmp(p.value, vocab_RDF_TYPE) == 0) {
            __auto_type _mv_648 = decode_term_iri_value(t.object);
            if (!_mv_648.has_value) {
                return 0;
            } else if (_mv_648.has_value) {
                __auto_type o = _mv_648.value;
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
                ({ slop_map_put(NULL, s, &(int64_t){x}, NULL, 0); });
            }
        }
        {
            __auto_type _coll = b;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ slop_map_put(NULL, s, &(int64_t){x}, NULL, 0); });
            }
        }
        {
            __auto_type _coll = c;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ slop_map_put(NULL, s, &(int64_t){x}, NULL, 0); });
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
    __auto_type _mv_652 = termstore_lookup_term(st, t);
    if (_mv_652.has_value) {
        __auto_type i = _mv_652.value;
        return i;
    } else if (!_mv_652.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

decode_Rebuilt decode_rebuild_candidates(slop_arena* arena, termstore_TermStore st, slop_list_int ax_subjs) {
    {
        __auto_type src_pred = rdf_make_iri(arena, vocab_OWL_ANNOTATED_SOURCE);
        __auto_type prop_pred = rdf_make_iri(arena, vocab_OWL_ANNOTATED_PROPERTY);
        __auto_type tgt_pred = rdf_make_iri(arena, vocab_OWL_ANNOTATED_TARGET);
        __auto_type out = ((slop_list_termstore_IdTriple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        slop_option_string fault = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = ax_subjs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ai = _coll.data[_i];
                {
                    __auto_type a = termstore_term_of(st, ai);
                    __auto_type _mv_653 = decode_one_object(arena, st, a, src_pred);
                    if (!_mv_653.is_ok) {
                        __auto_type _ = _mv_653.data.err;
                        fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("owl:Axiom node without a usable owl:annotatedSource")};
                    } else if (_mv_653.is_ok) {
                        __auto_type subj = _mv_653.data.ok;
                        __auto_type _mv_654 = decode_one_object(arena, st, a, prop_pred);
                        if (!_mv_654.is_ok) {
                            __auto_type _ = _mv_654.data.err;
                            fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("owl:Axiom node without a usable owl:annotatedProperty")};
                        } else if (_mv_654.is_ok) {
                            __auto_type pred = _mv_654.data.ok;
                            __auto_type _mv_655 = decode_one_object(arena, st, a, tgt_pred);
                            if (!_mv_655.is_ok) {
                                __auto_type _ = _mv_655.data.err;
                                fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("owl:Axiom node without a usable owl:annotatedTarget")};
                            } else if (_mv_655.is_ok) {
                                __auto_type obj = _mv_655.data.ok;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (((termstore_IdTriple){.s = decode_term_id(st, subj), .p = decode_term_id(st, pred), .o = decode_term_id(st, obj)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                ({ slop_map_put(NULL, cands, &(c), NULL, 0); });
            }
        }
        {
            __auto_type _coll = doc.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (slop_map_has(cands, &(it))) {
                    ({ slop_map_put(NULL, found, &(it), NULL, 0); });
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
        __auto_type out = ((slop_list_termstore_IdTriple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        slop_option_rdf_IRI ont = (slop_option_rdf_IRI){.has_value = false};
        slop_option_string fault = (slop_option_string){.has_value = false};
        {
            __auto_type header = decode_id_set(scratch, ont_subjs, ax_subjs, ann_subjs);
            {
                __auto_type _coll = doc.triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type it = _coll.data[_i];
                    if (!(slop_map_has(header, &(int64_t){it.s})) || !(decode_header_consumable(termstore_triple_of(dict, it)))) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (it); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
            fault = rb.fault;
        }
        {
            __auto_type _coll = ont_subjs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                __auto_type _mv_661 = decode_term_iri_value(termstore_term_of(dict, o));
                if (_mv_661.has_value) {
                    __auto_type i = _mv_661.value;
                    ont = (slop_option_rdf_IRI){.has_value = 1, .value = i};
                } else if (!_mv_661.has_value) {
                }
            }
        }
        __auto_type _mv_662 = fault;
        if (_mv_662.has_value) {
            __auto_type msg = _mv_662.value;
            return ((slop_result_decode_Stage0_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_input_error, .data.input_error = msg }) });
        } else if (!_mv_662.has_value) {
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
    __auto_type _mv_663 = f;
    switch (_mv_663.tag) {
        case decode_ListFault_list_truncated:
        {
            __auto_type m = _mv_663.data.list_truncated;
            return m;
        }
        case decode_ListFault_list_branching:
        {
            __auto_type m = _mv_663.data.list_branching;
            return m;
        }
        case decode_ListFault_list_cyclic:
        {
            __auto_type m = _mv_663.data.list_cyclic;
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
    __auto_type _mv_664 = decode_obj_of(arena, g, b, vocab_OWL_ON_PROPERTY);
    if (!_mv_664.is_ok) {
        __auto_type _ = _mv_664.data.err;
        return ((slop_result_types_RoleId_string){ .is_ok = false, .data.err = SLOP_STR("restriction without exactly one owl:onProperty") });
    } else if (_mv_664.is_ok) {
        __auto_type pt = _mv_664.data.ok;
        __auto_type _mv_665 = decode_property_expression(arena, g, pt);
        if (_mv_665.has_value) {
            __auto_type r = _mv_665.value;
            return ((slop_result_types_RoleId_string){ .is_ok = true, .data.ok = r });
        } else if (!_mv_665.has_value) {
            return ((slop_result_types_RoleId_string){ .is_ok = false, .data.err = SLOP_STR("owl:onProperty is a blank node that is not an inverse property expression") });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_option_types_RoleId decode_property_expression(slop_arena* arena, termstore_TermStore g, rdf_Term t) {
    __auto_type _mv_666 = decode_term_iri_value(t);
    if (_mv_666.has_value) {
        __auto_type i = _mv_666.value;
        return (slop_option_types_RoleId){.has_value = 1, .value = ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = i })};
    } else if (!_mv_666.has_value) {
        __auto_type _mv_667 = t;
        switch (_mv_667.tag) {
            case rdf_Term_term_blank:
            {
                __auto_type _ = _mv_667.data.term_blank;
                __auto_type _mv_668 = decode_obj_of(arena, g, t, vocab_OWL_INVERSE_OF);
                if (_mv_668.is_ok) {
                    __auto_type pt = _mv_668.data.ok;
                    __auto_type _mv_669 = decode_term_iri_value(pt);
                    if (_mv_669.has_value) {
                        __auto_type i = _mv_669.value;
                        return (slop_option_types_RoleId){.has_value = 1, .value = ((types_RoleId){ .tag = types_RoleId_inverse_role, .data.inverse_role = i })};
                    } else if (!_mv_669.has_value) {
                        return (slop_option_types_RoleId){.has_value = false};
                    }
                    SLOP_UNREACHABLE();
                } else if (!_mv_668.is_ok) {
                    __auto_type _ = _mv_668.data.err;
                    return (slop_option_types_RoleId){.has_value = false};
                }
                SLOP_UNREACHABLE();
            }
            default: {
                return (slop_option_types_RoleId){.has_value = false};
            }
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t decode_malformed_inverse(slop_arena* arena, termstore_TermStore g, rdf_Triple t) {
    return (decode_is_pred(t, vocab_OWL_INVERSE_OF) && ({ __auto_type _mv = t.subject; uint8_t _mr = {0}; switch (_mv.tag) { case rdf_Term_term_blank: { _mr = ({ __auto_type _mv = decode_property_expression(arena, g, t.subject); _mv.has_value ? ({ __auto_type _ = _mv.value; 0; }) : (1); }); break; } default: { _mr = 0; break; }  } _mr; }));
}

uint8_t decode_data_property_term(slop_arena* arena, termstore_TermStore g, rdf_Term t) {
    __auto_type _mv_670 = decode_term_iri_value(t);
    if (!_mv_670.has_value) {
        return 0;
    } else if (_mv_670.has_value) {
        __auto_type i = _mv_670.value;
        return (((canon_string_cmp(i.value, vocab_OWL_TOP_DATA_PROPERTY) == 0)) || ((canon_string_cmp(i.value, vocab_OWL_BOTTOM_DATA_PROPERTY) == 0)) || (termstore_store_contains(g, ((rdf_Triple){.subject = t, .predicate = rdf_make_iri(arena, vocab_RDF_TYPE), .object = rdf_make_iri(arena, vocab_OWL_DATATYPE_PROPERTY)}))));
    }
    SLOP_UNREACHABLE();
}

uint8_t decode_restriction_on_data(slop_arena* arena, termstore_TermStore g, rdf_Term b) {
    __auto_type _mv_671 = decode_obj_of(arena, g, b, vocab_OWL_ON_PROPERTY);
    if (_mv_671.is_ok) {
        __auto_type pt = _mv_671.data.ok;
        return decode_data_property_term(arena, g, pt);
    } else if (!_mv_671.is_ok) {
        __auto_type _ = _mv_671.data.err;
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string decode_data_restriction_pred(slop_arena* arena, termstore_TermStore g, rdf_Term b) {
    if (decode_has_pred(arena, g, b, vocab_OWL_SOME_VALUES_FROM)) {
        return vocab_OWL_SOME_VALUES_FROM;
    } else if (decode_has_pred(arena, g, b, vocab_OWL_ALL_VALUES_FROM)) {
        return vocab_OWL_ALL_VALUES_FROM;
    } else if (decode_has_pred(arena, g, b, vocab_OWL_HAS_VALUE)) {
        return vocab_OWL_HAS_VALUE;
    } else if (decode_has_pred(arena, g, b, vocab_OWL_HAS_SELF)) {
        return vocab_OWL_HAS_SELF;
    } else if (decode_has_pred(arena, g, b, vocab_OWL_QUALIFIED_CARDINALITY)) {
        return vocab_OWL_QUALIFIED_CARDINALITY;
    } else if (decode_has_pred(arena, g, b, vocab_OWL_MIN_QUALIFIED_CARDINALITY)) {
        return vocab_OWL_MIN_QUALIFIED_CARDINALITY;
    } else if (decode_has_pred(arena, g, b, vocab_OWL_MAX_QUALIFIED_CARDINALITY)) {
        return vocab_OWL_MAX_QUALIFIED_CARDINALITY;
    } else if (decode_has_pred(arena, g, b, vocab_OWL_CARDINALITY)) {
        return vocab_OWL_CARDINALITY;
    } else if (decode_has_pred(arena, g, b, vocab_OWL_MIN_CARDINALITY)) {
        return vocab_OWL_MIN_CARDINALITY;
    } else if (decode_has_pred(arena, g, b, vocab_OWL_MAX_CARDINALITY)) {
        return vocab_OWL_MAX_CARDINALITY;
    } else {
        return SLOP_STR("");
    }
}

slop_string decode_data_restriction_name(slop_string pred) {
    if (canon_string_cmp(pred, vocab_OWL_SOME_VALUES_FROM) == 0) {
        return SLOP_STR("DataSomeValuesFrom");
    } else if (canon_string_cmp(pred, vocab_OWL_ALL_VALUES_FROM) == 0) {
        return SLOP_STR("DataAllValuesFrom");
    } else if (canon_string_cmp(pred, vocab_OWL_HAS_VALUE) == 0) {
        return SLOP_STR("DataHasValue");
    } else if (canon_string_cmp(pred, vocab_OWL_HAS_SELF) == 0) {
        return SLOP_STR("ObjectHasSelf on a data property");
    } else if (canon_string_cmp(pred, vocab_OWL_QUALIFIED_CARDINALITY) == 0) {
        return SLOP_STR("DataExactCardinality");
    } else if (canon_string_cmp(pred, vocab_OWL_MIN_QUALIFIED_CARDINALITY) == 0) {
        return SLOP_STR("DataMinCardinality");
    } else if (canon_string_cmp(pred, vocab_OWL_MAX_QUALIFIED_CARDINALITY) == 0) {
        return SLOP_STR("DataMaxCardinality");
    } else if (canon_string_cmp(pred, vocab_OWL_CARDINALITY) == 0) {
        return SLOP_STR("DataExactCardinality");
    } else if (canon_string_cmp(pred, vocab_OWL_MIN_CARDINALITY) == 0) {
        return SLOP_STR("DataMinCardinality");
    } else if (canon_string_cmp(pred, vocab_OWL_MAX_CARDINALITY) == 0) {
        return SLOP_STR("DataMaxCardinality");
    } else {
        return SLOP_STR("a restriction on a data property");
    }
}

slop_string decode_filler_text(slop_arena* arena, rdf_Term t) {
    __auto_type _mv_672 = t;
    switch (_mv_672.tag) {
        case rdf_Term_term_iri:
        {
            __auto_type i = _mv_672.data.term_iri;
            return i.value;
        }
        case rdf_Term_term_blank:
        {
            __auto_type _ = _mv_672.data.term_blank;
            return SLOP_STR("_");
        }
        default: {
            return decode_render_term(arena, t);
        }
    }
}

owl2_RawConcept decode_nary_data_restriction(slop_arena* arena, termstore_TermStore g, rdf_Term b) {
    {
        __auto_type pred = decode_data_restriction_pred(arena, g, b);
        __auto_type props = ({ __auto_type _mv = decode_obj_of(arena, g, b, vocab_OWL_ON_PROPERTIES); slop_string _mr; if (_mv.is_ok) { __auto_type ht = _mv.data.ok; _mr = ({ __auto_type _mv = decode_rdf_list_checked(arena, g, ht); slop_string _mr; if (_mv.is_ok) { __auto_type terms = _mv.data.ok; _mr = ({ __auto_type out = SLOP_STR(""); uint8_t first = 1; ({ ({ __auto_type _coll = terms; for (size_t _i = 0; _i < _coll.len; _i++) { __auto_type tm = _coll.data[_i]; ({ (void)(((!(first)) ? ({ ({ out = string_concat(arena, out, SLOP_STR(" ")); (void)0; }); 0; }) : ({ (void)0; }))); ({ out = string_concat(arena, out, decode_filler_text(arena, tm)); (void)0; }); ({ first = 0; (void)0; }); }); } (void)0; }); out; }); }); } else { __auto_type _ = _mv.data.err; _mr = SLOP_STR("?"); } _mr; }); } else { __auto_type _ = _mv.data.err; _mr = SLOP_STR("?"); } _mr; });
        __auto_type fill = (((string_len(pred) == 0)) ? SLOP_STR("") : ({ __auto_type _mv = decode_obj_of(arena, g, b, pred); slop_string _mr; if (_mv.is_ok) { __auto_type ft = _mv.data.ok; _mr = decode_filler_text(arena, ft); } else { __auto_type _ = _mv.data.err; _mr = SLOP_STR("?"); } _mr; }));
        return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_data, .data.rc_data = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = string_concat(arena, decode_data_restriction_name(pred), string_concat(arena, SLOP_STR("(onProperties("), string_concat(arena, props, string_concat(arena, SLOP_STR(") "), string_concat(arena, fill, SLOP_STR(")")))))) }) });
    }
}

owl2_RawConcept decode_data_restriction(slop_arena* arena, termstore_TermStore g, rdf_Term b) {
    {
        __auto_type pred = decode_data_restriction_pred(arena, g, b);
        __auto_type prop = ({ __auto_type _mv = decode_obj_of(arena, g, b, vocab_OWL_ON_PROPERTY); slop_string _mr; if (_mv.is_ok) { __auto_type pt = _mv.data.ok; _mr = decode_filler_text(arena, pt); } else { __auto_type _ = _mv.data.err; _mr = SLOP_STR("?"); } _mr; });
        __auto_type fill = (((string_len(pred) == 0)) ? SLOP_STR("") : ({ __auto_type _mv = decode_obj_of(arena, g, b, pred); slop_string _mr; if (_mv.is_ok) { __auto_type ft = _mv.data.ok; _mr = decode_filler_text(arena, ft); } else { __auto_type _ = _mv.data.err; _mr = SLOP_STR("?"); } _mr; }));
        return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_data, .data.rc_data = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = string_concat(arena, decode_data_restriction_name(pred), string_concat(arena, SLOP_STR("("), string_concat(arena, prop, string_concat(arena, SLOP_STR(" "), string_concat(arena, fill, SLOP_STR(")")))))) }) });
    }
}

slop_result_int_string decode_literal_count(rdf_Term t) {
    __auto_type _mv_673 = t;
    switch (_mv_673.tag) {
        case rdf_Term_term_literal:
        {
            __auto_type l = _mv_673.data.term_literal;
            __auto_type _mv_674 = strlib_parse_int(l.value);
            if (_mv_674.is_ok) {
                __auto_type v = _mv_674.data.ok;
                if (((int64_t)(v)) < 0) {
                    return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality literal is negative") });
                } else {
                    return ((slop_result_int_string){ .is_ok = true, .data.ok = ((int64_t)(v)) });
                }
            } else if (!_mv_674.is_ok) {
                __auto_type _ = _mv_674.data.err;
                return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality is not an integer literal") });
            }
            SLOP_UNREACHABLE();
        }
        case rdf_Term_term_iri:
        {
            __auto_type _ = _mv_673.data.term_iri;
            return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality is an IRI, not a literal") });
        }
        case rdf_Term_term_blank:
        {
            __auto_type _ = _mv_673.data.term_blank;
            return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality is a blank node, not a literal") });
        }
        case rdf_Term_term_triple:
        {
            __auto_type _ = _mv_673.data.term_triple;
            return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality is a triple term, not a literal") });
        }
    }
    SLOP_UNREACHABLE();
}

decode_IndividualTerm decode_individual_term(rdf_Term tm) {
    __auto_type _mv_675 = tm;
    switch (_mv_675.tag) {
        case rdf_Term_term_iri:
        {
            __auto_type i = _mv_675.data.term_iri;
            if (decode_is_reserved_iri(i.value)) {
                return ((decode_IndividualTerm){ .tag = decode_IndividualTerm_reserved_individual });
            } else {
                return ((decode_IndividualTerm){ .tag = decode_IndividualTerm_named_individual, .data.named_individual = i });
            }
        }
        case rdf_Term_term_literal:
        {
            __auto_type _ = _mv_675.data.term_literal;
            return ((decode_IndividualTerm){ .tag = decode_IndividualTerm_literal_individual });
        }
        default: {
            return ((decode_IndividualTerm){ .tag = decode_IndividualTerm_anonymous_individual });
        }
    }
}

slop_result_decode_NodeList_string decode_decode_node_list(slop_arena* arena, termstore_TermStore g, rdf_Term head) {
    __auto_type _mv_676 = decode_rdf_list_checked(arena, g, head);
    if (!_mv_676.is_ok) {
        __auto_type lf = _mv_676.data.err;
        return ((slop_result_decode_NodeList_string){ .is_ok = false, .data.err = decode_list_fault_message(lf) });
    } else if (_mv_676.is_ok) {
        __auto_type terms = _mv_676.data.ok;
        {
            __auto_type out = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            uint8_t literal = 0;
            uint8_t anonymous = 0;
            uint8_t reserved = 0;
            {
                __auto_type _coll = terms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tm = _coll.data[_i];
                    __auto_type _mv_677 = decode_individual_term(tm);
                    switch (_mv_677.tag) {
                        case decode_IndividualTerm_named_individual:
                        {
                            __auto_type i = _mv_677.data.named_individual;
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_Node){ .tag = types_Node_individual_node, .data.individual_node = i })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    __auto_type _mv_678 = decode_rdf_list_checked(arena, g, head);
    if (!_mv_678.is_ok) {
        __auto_type lf = _mv_678.data.err;
        return ((slop_result_list_owl2_RawConcept_string){ .is_ok = false, .data.err = decode_list_fault_message(lf) });
    } else if (_mv_678.is_ok) {
        __auto_type terms = _mv_678.data.ok;
        {
            __auto_type out = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            slop_option_string fault = (slop_option_string){.has_value = false};
            {
                __auto_type _coll = terms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tm = _coll.data[_i];
                    __auto_type _mv_679 = decode_decode_concept(arena, g, tm, (fuel - 1));
                    if (!_mv_679.is_ok) {
                        __auto_type m = _mv_679.data.err;
                        fault = (slop_option_string){.has_value = 1, .value = m};
                    } else if (_mv_679.is_ok) {
                        __auto_type c = _mv_679.data.ok;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
            __auto_type _mv_680 = fault;
            if (_mv_680.has_value) {
                __auto_type m = _mv_680.value;
                return ((slop_result_list_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (!_mv_680.has_value) {
                return ((slop_result_list_owl2_RawConcept_string){ .is_ok = true, .data.ok = out });
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_owl2_RawConcept_string decode_decode_quantified(slop_arena* arena, termstore_TermStore g, rdf_Term b, slop_string filler_pred, uint8_t universal, int64_t fuel) {
    __auto_type _mv_681 = decode_decode_role(arena, g, b);
    if (!_mv_681.is_ok) {
        __auto_type m = _mv_681.data.err;
        return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
    } else if (_mv_681.is_ok) {
        __auto_type r = _mv_681.data.ok;
        __auto_type _mv_682 = decode_obj_of(arena, g, b, filler_pred);
        if (!_mv_682.is_ok) {
            __auto_type _ = _mv_682.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("quantified restriction without exactly one filler") });
        } else if (_mv_682.is_ok) {
            __auto_type ft = _mv_682.data.ok;
            __auto_type _mv_683 = decode_decode_concept(arena, g, ft, (fuel - 1));
            if (!_mv_683.is_ok) {
                __auto_type m = _mv_683.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_683.is_ok) {
                __auto_type c = _mv_683.data.ok;
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
    __auto_type _mv_684 = decode_decode_role(arena, g, b);
    if (!_mv_684.is_ok) {
        __auto_type m = _mv_684.data.err;
        return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
    } else if (_mv_684.is_ok) {
        __auto_type r = _mv_684.data.ok;
        __auto_type _mv_685 = decode_obj_of(arena, g, b, count_pred);
        if (!_mv_685.is_ok) {
            __auto_type _ = _mv_685.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("cardinality restriction without exactly one count") });
        } else if (_mv_685.is_ok) {
            __auto_type ct = _mv_685.data.ok;
            __auto_type _mv_686 = decode_literal_count(ct);
            if (!_mv_686.is_ok) {
                __auto_type m = _mv_686.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_686.is_ok) {
                __auto_type n = _mv_686.data.ok;
                if (!(qualified)) {
                    return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_card, .data.rc_card = { .f0 = kind, .f1 = r, .f2 = n } }) });
                } else {
                    __auto_type _mv_687 = decode_obj_of(arena, g, b, vocab_OWL_ON_CLASS);
                    if (!_mv_687.is_ok) {
                        __auto_type _ = _mv_687.data.err;
                        return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("qualified cardinality without exactly one owl:onClass") });
                    } else if (_mv_687.is_ok) {
                        __auto_type qt = _mv_687.data.ok;
                        __auto_type _mv_688 = decode_decode_concept(arena, g, qt, (fuel - 1));
                        if (!_mv_688.is_ok) {
                            __auto_type m = _mv_688.data.err;
                            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
                        } else if (_mv_688.is_ok) {
                            __auto_type qc = _mv_688.data.ok;
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
    if (decode_has_pred(arena, g, b, vocab_OWL_ON_PROPERTIES)) {
        return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = decode_nary_data_restriction(arena, g, b) });
    } else if (decode_restriction_on_data(arena, g, b) || decode_has_pred(arena, g, b, vocab_OWL_ON_DATA_RANGE)) {
        return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = decode_data_restriction(arena, g, b) });
    } else if (decode_has_pred(arena, g, b, vocab_OWL_INTERSECTION_OF)) {
        __auto_type _mv_689 = decode_obj_of(arena, g, b, vocab_OWL_INTERSECTION_OF);
        if (!_mv_689.is_ok) {
            __auto_type _ = _mv_689.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:intersectionOf is absent or ambiguous") });
        } else if (_mv_689.is_ok) {
            __auto_type head = _mv_689.data.ok;
            __auto_type _mv_690 = decode_decode_concept_list(arena, g, head, fuel);
            if (!_mv_690.is_ok) {
                __auto_type m = _mv_690.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_690.is_ok) {
                __auto_type cs = _mv_690.data.ok;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_and, .data.rc_and = cs }) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    } else if (decode_has_pred(arena, g, b, vocab_OWL_UNION_OF)) {
        __auto_type _mv_691 = decode_obj_of(arena, g, b, vocab_OWL_UNION_OF);
        if (!_mv_691.is_ok) {
            __auto_type _ = _mv_691.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:unionOf is absent or ambiguous") });
        } else if (_mv_691.is_ok) {
            __auto_type head = _mv_691.data.ok;
            __auto_type _mv_692 = decode_decode_concept_list(arena, g, head, fuel);
            if (!_mv_692.is_ok) {
                __auto_type m = _mv_692.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_692.is_ok) {
                __auto_type cs = _mv_692.data.ok;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_or, .data.rc_or = cs }) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    } else if (decode_has_pred(arena, g, b, vocab_OWL_ONE_OF)) {
        __auto_type _mv_693 = decode_obj_of(arena, g, b, vocab_OWL_ONE_OF);
        if (!_mv_693.is_ok) {
            __auto_type _ = _mv_693.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:oneOf is absent or ambiguous") });
        } else if (_mv_693.is_ok) {
            __auto_type head = _mv_693.data.ok;
            __auto_type _mv_694 = decode_decode_node_list(arena, g, head);
            if (!_mv_694.is_ok) {
                __auto_type m = _mv_694.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_694.is_ok) {
                __auto_type nl = _mv_694.data.ok;
                __auto_type _mv_695 = nl;
                switch (_mv_695.tag) {
                    case decode_NodeList_all_named:
                    {
                        __auto_type ns = _mv_695.data.all_named;
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
        __auto_type _mv_696 = decode_obj_of(arena, g, b, vocab_OWL_COMPLEMENT_OF);
        if (!_mv_696.is_ok) {
            __auto_type _ = _mv_696.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:complementOf is absent or ambiguous") });
        } else if (_mv_696.is_ok) {
            __auto_type ct = _mv_696.data.ok;
            __auto_type _mv_697 = decode_decode_concept(arena, g, ct, (fuel - 1));
            if (!_mv_697.is_ok) {
                __auto_type m = _mv_697.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_697.is_ok) {
                __auto_type c = _mv_697.data.ok;
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
        __auto_type _mv_698 = decode_decode_role(arena, g, b);
        if (!_mv_698.is_ok) {
            __auto_type m = _mv_698.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
        } else if (_mv_698.is_ok) {
            __auto_type r = _mv_698.data.ok;
            __auto_type _mv_699 = decode_obj_of(arena, g, b, vocab_OWL_HAS_VALUE);
            if (!_mv_699.is_ok) {
                __auto_type _ = _mv_699.data.err;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:hasValue is absent or ambiguous") });
            } else if (_mv_699.is_ok) {
                __auto_type vt = _mv_699.data.ok;
                __auto_type _mv_700 = decode_individual_term(vt);
                switch (_mv_700.tag) {
                    case decode_IndividualTerm_named_individual:
                    {
                        __auto_type i = _mv_700.data.named_individual;
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
        __auto_type _mv_701 = decode_decode_role(arena, g, b);
        if (!_mv_701.is_ok) {
            __auto_type m = _mv_701.data.err;
            return ((slop_result_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
        } else if (_mv_701.is_ok) {
            __auto_type r = _mv_701.data.ok;
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
        __auto_type _mv_702 = t;
        switch (_mv_702.tag) {
            case rdf_Term_term_iri:
            {
                __auto_type i = _mv_702.data.term_iri;
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
                __auto_type _ = _mv_702.data.term_literal;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_data, .data.rc_data = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("literal in a class position") }) }) });
            }
            case rdf_Term_term_triple:
            {
                __auto_type _ = _mv_702.data.term_triple;
                return ((slop_result_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_anon, .data.rc_anon = ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("RDF-star triple term in a class position") }) }) });
            }
            case rdf_Term_term_blank:
            {
                __auto_type _ = _mv_702.data.term_blank;
                return decode_decode_anon(arena, g, t, fuel);
            }
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t decode_declare_entity(slop_arena* arena, owl2_Signature sig, rdf_IRI entity, slop_string type_iri) {
    if (canon_string_cmp(type_iri, vocab_OWL_CLASS) == 0) {
        ({ slop_map_put(NULL, sig.classes, &(entity), NULL, 0); });
        return 1;
    } else if (canon_string_cmp(type_iri, vocab_OWL_OBJECT_PROPERTY) == 0) {
        ({ slop_map_put(NULL, sig.obj_props, &(entity), NULL, 0); });
        return 1;
    } else if (canon_string_cmp(type_iri, vocab_OWL_DATATYPE_PROPERTY) == 0) {
        ({ slop_map_put(NULL, sig.data_props, &(entity), NULL, 0); });
        return 1;
    } else if (canon_string_cmp(type_iri, vocab_OWL_ANNOTATION_PROPERTY) == 0) {
        ({ slop_map_put(NULL, sig.annot_props, &(entity), NULL, 0); });
        return 1;
    } else if (canon_string_cmp(type_iri, vocab_OWL_NAMED_INDIVIDUAL) == 0) {
        ({ slop_map_put(NULL, sig.individuals, &(entity), NULL, 0); });
        return 1;
    } else if (canon_string_cmp(type_iri, vocab_RDFS_DATATYPE) == 0) {
        ({ slop_map_put(NULL, sig.datatypes, &(entity), NULL, 0); });
        return 1;
    } else {
        return 0;
    }
}

uint8_t decode_add_builtins(slop_arena* arena, owl2_Signature sig) {
    ({ rdf_IRI _key_709 = (((rdf_IRI){.value = vocab_OWL_THING})); slop_map_put(NULL, sig.classes, &_key_709, NULL, 0); });
    ({ rdf_IRI _key_710 = (((rdf_IRI){.value = vocab_OWL_NOTHING})); slop_map_put(NULL, sig.classes, &_key_710, NULL, 0); });
    ({ rdf_IRI _key_711 = (((rdf_IRI){.value = vocab_OWL_TOP_OBJECT_PROPERTY})); slop_map_put(NULL, sig.obj_props, &_key_711, NULL, 0); });
    ({ rdf_IRI _key_712 = (((rdf_IRI){.value = vocab_OWL_BOTTOM_OBJECT_PROPERTY})); slop_map_put(NULL, sig.obj_props, &_key_712, NULL, 0); });
    ({ rdf_IRI _key_713 = (((rdf_IRI){.value = vocab_OWL_TOP_DATA_PROPERTY})); slop_map_put(NULL, sig.data_props, &_key_713, NULL, 0); });
    ({ rdf_IRI _key_714 = (((rdf_IRI){.value = vocab_OWL_BOTTOM_DATA_PROPERTY})); slop_map_put(NULL, sig.data_props, &_key_714, NULL, 0); });
    ({ rdf_IRI _key_715 = (((rdf_IRI){.value = vocab_RDFS_LABEL})); slop_map_put(NULL, sig.annot_props, &_key_715, NULL, 0); });
    ({ rdf_IRI _key_716 = (((rdf_IRI){.value = vocab_RDFS_COMMENT})); slop_map_put(NULL, sig.annot_props, &_key_716, NULL, 0); });
    ({ rdf_IRI _key_717 = (((rdf_IRI){.value = vocab_RDFS_SEE_ALSO})); slop_map_put(NULL, sig.annot_props, &_key_717, NULL, 0); });
    ({ rdf_IRI _key_718 = (((rdf_IRI){.value = vocab_RDFS_IS_DEFINED_BY})); slop_map_put(NULL, sig.annot_props, &_key_718, NULL, 0); });
    ({ rdf_IRI _key_719 = (((rdf_IRI){.value = vocab_OWL_VERSION_INFO})); slop_map_put(NULL, sig.annot_props, &_key_719, NULL, 0); });
    ({ rdf_IRI _key_720 = (((rdf_IRI){.value = vocab_OWL_DEPRECATED})); slop_map_put(NULL, sig.annot_props, &_key_720, NULL, 0); });
    ({ rdf_IRI _key_721 = (((rdf_IRI){.value = vocab_OWL_PRIOR_VERSION})); slop_map_put(NULL, sig.annot_props, &_key_721, NULL, 0); });
    ({ rdf_IRI _key_722 = (((rdf_IRI){.value = vocab_OWL_BACKWARD_COMPATIBLE_WITH})); slop_map_put(NULL, sig.annot_props, &_key_722, NULL, 0); });
    ({ rdf_IRI _key_723 = (((rdf_IRI){.value = vocab_OWL_INCOMPATIBLE_WITH})); slop_map_put(NULL, sig.annot_props, &_key_723, NULL, 0); });
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
                    __auto_type _mv_724 = decode_term_iri_value(termstore_term_of(dict, it.s));
                    if (_mv_724.has_value) {
                        __auto_type s = _mv_724.value;
                        __auto_type _mv_725 = decode_term_iri_value(termstore_term_of(dict, it.o));
                        if (_mv_725.has_value) {
                            __auto_type o = _mv_725.value;
                            decode_declare_entity(arena, sig, s, o.value);
                        } else if (!_mv_725.has_value) {
                            0;
                        }
                    } else if (!_mv_724.has_value) {
                        0;
                    }
                }
            }
        }
        return sig;
    }
}

slop_string decode_render_term(slop_arena* arena, rdf_Term t) {
    __auto_type _mv_726 = t;
    switch (_mv_726.tag) {
        case rdf_Term_term_iri:
        {
            __auto_type i = _mv_726.data.term_iri;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">")));
        }
        case rdf_Term_term_blank:
        {
            __auto_type b = _mv_726.data.term_blank;
            return string_concat(arena, SLOP_STR("_:b"), int_to_string(arena, b.id));
        }
        case rdf_Term_term_literal:
        {
            __auto_type l = _mv_726.data.term_literal;
            return string_concat(arena, SLOP_STR("\""), string_concat(arena, l.value, SLOP_STR("\"")));
        }
        case rdf_Term_term_triple:
        {
            __auto_type _ = _mv_726.data.term_triple;
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
    __auto_type _mv_727 = decode_term_iri_value(t.predicate);
    if (_mv_727.has_value) {
        __auto_type i = _mv_727.value;
        return (canon_string_cmp(i.value, iri) == 0);
    } else if (!_mv_727.has_value) {
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
            return (decode_is_pred(t, vocab_OWL_INVERSE_OF) && ({ __auto_type _mv = t.subject; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case rdf_Term_term_blank: { _mr = 1; _mm = 1; break; } case rdf_Term_term_iri: { _mr = 0; _mm = 1; break; } case rdf_Term_term_literal: { _mr = 0; _mm = 1; break; } case rdf_Term_term_triple: { _mr = 0; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }));
        } else {
            __auto_type _mv_728 = decode_term_iri_value(t.object);
            if (_mv_728.has_value) {
                __auto_type o = _mv_728.value;
                return (({ __auto_type _mv = t.subject; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case rdf_Term_term_blank: { _mr = 1; _mm = 1; break; } case rdf_Term_term_iri: { _mr = 0; _mm = 1; break; } case rdf_Term_term_literal: { _mr = 0; _mm = 1; break; } case rdf_Term_term_triple: { _mr = 0; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }) && ((canon_string_cmp(o.value, vocab_OWL_CLASS) == 0) || (canon_string_cmp(o.value, vocab_OWL_RESTRICTION) == 0)));
            } else if (!_mv_728.has_value) {
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
    __auto_type _mv_729 = decode_term_iri_value(t);
    if (_mv_729.has_value) {
        __auto_type i = _mv_729.value;
        return (slop_option_types_RoleId){.has_value = 1, .value = ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = i })};
    } else if (!_mv_729.has_value) {
        return (slop_option_types_RoleId){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

slop_result_list_types_RoleId_string decode_decode_role_list(slop_arena* arena, termstore_TermStore g, rdf_Term head) {
    __auto_type _mv_730 = decode_rdf_list_checked(arena, g, head);
    if (!_mv_730.is_ok) {
        __auto_type lf = _mv_730.data.err;
        return ((slop_result_list_types_RoleId_string){ .is_ok = false, .data.err = decode_list_fault_message(lf) });
    } else if (_mv_730.is_ok) {
        __auto_type terms = _mv_730.data.ok;
        {
            __auto_type out = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            slop_option_string fault = (slop_option_string){.has_value = false};
            {
                __auto_type _coll = terms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tm = _coll.data[_i];
                    __auto_type _mv_731 = decode_property_expression(arena, g, tm);
                    if (_mv_731.has_value) {
                        __auto_type r = _mv_731.value;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_731.has_value) {
                        fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("property chain step is not a property expression")};
                    }
                }
            }
            __auto_type _mv_732 = fault;
            if (_mv_732.has_value) {
                __auto_type m = _mv_732.value;
                return ((slop_result_list_types_RoleId_string){ .is_ok = false, .data.err = m });
            } else if (!_mv_732.has_value) {
                return ((slop_result_list_types_RoleId_string){ .is_ok = true, .data.ok = out });
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t decode_list_has_data(slop_arena* arena, termstore_TermStore g, rdf_Term head) {
    __auto_type _mv_733 = decode_rdf_list_checked(arena, g, head);
    if (!_mv_733.is_ok) {
        __auto_type _ = _mv_733.data.err;
        return 0;
    } else if (_mv_733.is_ok) {
        __auto_type terms = _mv_733.data.ok;
        {
            uint8_t found = 0;
            {
                __auto_type _coll = terms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tm = _coll.data[_i];
                    if (decode_data_property_term(arena, g, tm)) {
                        found = 1;
                    }
                }
            }
            return found;
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_list_owl2_RawConcept_string decode_binary_concepts(slop_arena* arena, termstore_TermStore g, rdf_Triple t) {
    __auto_type _mv_734 = decode_decode_concept(arena, g, t.subject, decode_CONCEPT_FUEL);
    if (!_mv_734.is_ok) {
        __auto_type m = _mv_734.data.err;
        return ((slop_result_list_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
    } else if (_mv_734.is_ok) {
        __auto_type lhs = _mv_734.data.ok;
        __auto_type _mv_735 = decode_decode_concept(arena, g, t.object, decode_CONCEPT_FUEL);
        if (!_mv_735.is_ok) {
            __auto_type m = _mv_735.data.err;
            return ((slop_result_list_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
        } else if (_mv_735.is_ok) {
            __auto_type rhs = _mv_735.data.ok;
            {
                __auto_type out = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (lhs); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (rhs); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                return ((slop_result_list_owl2_RawConcept_string){ .is_ok = true, .data.ok = out });
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_option_rdf_Term decode_members_head(slop_arena* arena, termstore_TermStore g, rdf_Term s) {
    __auto_type _mv_736 = decode_obj_of(arena, g, s, vocab_OWL_MEMBERS);
    if (_mv_736.is_ok) {
        __auto_type h = _mv_736.data.ok;
        return (slop_option_rdf_Term){.has_value = 1, .value = h};
    } else if (!_mv_736.is_ok) {
        __auto_type _ = _mv_736.data.err;
        __auto_type _mv_737 = decode_obj_of(arena, g, s, vocab_OWL_DISTINCT_MEMBERS);
        if (_mv_737.is_ok) {
            __auto_type h = _mv_737.data.ok;
            return (slop_option_rdf_Term){.has_value = 1, .value = h};
        } else if (!_mv_737.is_ok) {
            __auto_type _ = _mv_737.data.err;
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
            __auto_type _mv_738 = decode_term_iri_value(t.subject);
            if (_mv_738.has_value) {
                __auto_type s = _mv_738.value;
                __auto_type _mv_739 = decode_entity_kind_of(ov);
                if (_mv_739.has_value) {
                    __auto_type k = _mv_739.value;
                    if ((k == types_EntityKind_entity_individual) && decode_is_reserved_iri(s.value)) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = decode_frag(arena, t) }) });
                    } else {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_declaration, .data.ra_declaration = ((owl2_RawDeclaration){.kind = k, .entity = s}) }) });
                    }
                } else if (!_mv_739.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("unreachable: declaration type vanished") });
                }
                SLOP_UNREACHABLE();
            } else if (!_mv_738.has_value) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = decode_frag(arena, t) }) });
            }
            SLOP_UNREACHABLE();
        } else if (((canon_string_cmp(ov, vocab_OWL_TRANSITIVE_PROPERTY) == 0) || ({ __auto_type _mv = decode_characteristic_of(ov); _mv.has_value ? ({ __auto_type _ = _mv.value; 1; }) : (0); })) && decode_data_property_term(arena, g, t.subject)) {
            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
        } else if (canon_string_cmp(ov, vocab_OWL_TRANSITIVE_PROPERTY) == 0) {
            __auto_type _mv_740 = decode_property_expression(arena, g, t.subject);
            if (_mv_740.has_value) {
                __auto_type r = _mv_740.value;
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_transitive_property, .data.ra_transitive_property = r }) });
            } else if (!_mv_740.has_value) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:TransitiveProperty on a non-IRI subject") });
            }
            SLOP_UNREACHABLE();
        } else if (({ __auto_type _mv = decode_characteristic_of(ov); _mv.has_value ? ({ __auto_type _ = _mv.value; 1; }) : (0); })) {
            __auto_type _mv_741 = decode_property_expression(arena, g, t.subject);
            if (_mv_741.has_value) {
                __auto_type r = _mv_741.value;
                __auto_type _mv_742 = decode_characteristic_of(ov);
                if (_mv_742.has_value) {
                    __auto_type c = _mv_742.value;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_property_characteristic, .data.ra_property_characteristic = { .f0 = c, .f1 = r } }) });
                } else if (!_mv_742.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("unreachable: characteristic vanished") });
                }
                SLOP_UNREACHABLE();
            } else if (!_mv_741.has_value) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("property characteristic on a non-IRI subject") });
            }
            SLOP_UNREACHABLE();
        } else if (canon_string_cmp(ov, vocab_OWL_ALL_DIFFERENT) == 0) {
            __auto_type _mv_743 = decode_members_head(arena, g, t.subject);
            if (!_mv_743.has_value) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:AllDifferent without owl:members or owl:distinctMembers") });
            } else if (_mv_743.has_value) {
                __auto_type head = _mv_743.value;
                __auto_type _mv_744 = decode_decode_node_list(arena, g, head);
                if (!_mv_744.is_ok) {
                    __auto_type m = _mv_744.data.err;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                } else if (_mv_744.is_ok) {
                    __auto_type nl = _mv_744.data.ok;
                    __auto_type _mv_745 = nl;
                    switch (_mv_745.tag) {
                        case decode_NodeList_all_named:
                        {
                            __auto_type ns = _mv_745.data.all_named;
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
            __auto_type _mv_746 = decode_members_head(arena, g, t.subject);
            if (!_mv_746.has_value) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:AllDisjointClasses without owl:members") });
            } else if (_mv_746.has_value) {
                __auto_type head = _mv_746.value;
                __auto_type _mv_747 = decode_decode_concept_list(arena, g, head, decode_CONCEPT_FUEL);
                if (!_mv_747.is_ok) {
                    __auto_type m = _mv_747.data.err;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                } else if (_mv_747.is_ok) {
                    __auto_type cs = _mv_747.data.ok;
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
            __auto_type _mv_748 = decode_members_head(arena, g, t.subject);
            if (!_mv_748.has_value) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:AllDisjointProperties without owl:members") });
            } else if (_mv_748.has_value) {
                __auto_type head = _mv_748.value;
                if (decode_list_has_data(arena, g, head)) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
                } else {
                    __auto_type _mv_749 = decode_decode_role_list(arena, g, head);
                    if (!_mv_749.is_ok) {
                        __auto_type m = _mv_749.data.err;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                    } else if (_mv_749.is_ok) {
                        __auto_type rs = _mv_749.data.ok;
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
    __auto_type _mv_750 = decode_individual_term(t.subject);
    switch (_mv_750.tag) {
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
            __auto_type a = _mv_750.data.named_individual;
            __auto_type _mv_751 = decode_individual_term(t.object);
            switch (_mv_751.tag) {
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
                    __auto_type b = _mv_751.data.named_individual;
                    {
                        __auto_type ns = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                        ({ __auto_type _lst_p = &(ns); __auto_type _item = (((types_Node){ .tag = types_Node_individual_node, .data.individual_node = a })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(ns); __auto_type _item = (((types_Node){ .tag = types_Node_individual_node, .data.individual_node = b })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        __auto_type _mv_752 = decode_obj_of(arena, g, x, vocab_OWL_ASSERTION_PROPERTY);
        if (!_mv_752.is_ok) {
            __auto_type _ = _mv_752.data.err;
            return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:NegativePropertyAssertion without exactly one owl:assertionProperty") });
        } else if (_mv_752.is_ok) {
            __auto_type pt = _mv_752.data.ok;
            __auto_type _mv_753 = decode_obj_of(arena, g, x, vocab_OWL_SOURCE_INDIVIDUAL);
            if (!_mv_753.is_ok) {
                __auto_type _ = _mv_753.data.err;
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:NegativePropertyAssertion without exactly one owl:sourceIndividual") });
            } else if (_mv_753.is_ok) {
                __auto_type st = _mv_753.data.ok;
                if (decode_has_pred(arena, g, x, vocab_OWL_TARGET_VALUE) && decode_has_pred(arena, g, x, vocab_OWL_TARGET_INDIVIDUAL)) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:NegativePropertyAssertion with both owl:targetIndividual and owl:targetValue") });
                } else if (decode_has_pred(arena, g, x, vocab_OWL_TARGET_VALUE)) {
                    __auto_type _mv_754 = decode_obj_of(arena, g, x, vocab_OWL_TARGET_VALUE);
                    if (!_mv_754.is_ok) {
                        __auto_type _ = _mv_754.data.err;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:NegativePropertyAssertion without exactly one owl:targetValue") });
                    } else if (_mv_754.is_ok) {
                        __auto_type _ = _mv_754.data.ok;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
                    }
                    SLOP_UNREACHABLE();
                } else {
                    __auto_type _mv_755 = decode_obj_of(arena, g, x, vocab_OWL_TARGET_INDIVIDUAL);
                    if (!_mv_755.is_ok) {
                        __auto_type _ = _mv_755.data.err;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:NegativePropertyAssertion without exactly one owl:targetIndividual") });
                    } else if (_mv_755.is_ok) {
                        __auto_type tt = _mv_755.data.ok;
                        if (decode_data_property_term(arena, g, pt)) {
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
                        } else {
                            __auto_type _mv_756 = decode_property_expression(arena, g, pt);
                            if (!_mv_756.has_value) {
                                return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:assertionProperty is not a property") });
                            } else if (_mv_756.has_value) {
                                __auto_type r = _mv_756.value;
                                __auto_type _mv_757 = decode_individual_term(st);
                                switch (_mv_757.tag) {
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
                                        __auto_type a = _mv_757.data.named_individual;
                                        __auto_type _mv_758 = decode_individual_term(tt);
                                        switch (_mv_758.tag) {
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
                                                __auto_type b = _mv_758.data.named_individual;
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
    __auto_type _mv_759 = decode_decode_concept(arena, g, t.object, decode_CONCEPT_FUEL);
    if (!_mv_759.is_ok) {
        __auto_type m = _mv_759.data.err;
        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_759.is_ok) {
        __auto_type c = _mv_759.data.ok;
        __auto_type _mv_760 = decode_term_iri_value(t.subject);
        if (_mv_760.has_value) {
            __auto_type s = _mv_760.value;
            if (decode_is_reserved_iri(s.value)) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = decode_frag(arena, t) }) });
            } else {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_class_assertion, .data.ra_class_assertion = ((owl2_RawClassAssertion){.concept = decode_box_concept(arena, c), .subject = ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = s })}) }) });
            }
        } else if (!_mv_760.has_value) {
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
    __auto_type _mv_761 = decode_term_iri_value(subj);
    if (!_mv_761.has_value) {
        return 0;
    } else if (_mv_761.has_value) {
        __auto_type i = _mv_761.value;
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
    __auto_type _mv_762 = decode_term_iri_value(t.predicate);
    if (!_mv_762.has_value) {
        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = decode_frag(arena, t) }) });
    } else if (_mv_762.has_value) {
        __auto_type p = _mv_762.value;
        {
            __auto_type pv = p.value;
            if (canon_string_cmp(pv, vocab_RDF_TYPE) == 0) {
                __auto_type _mv_763 = t.object;
                switch (_mv_763.tag) {
                    case rdf_Term_term_iri:
                    {
                        __auto_type o = _mv_763.data.term_iri;
                        return decode_decode_typed(arena, g, t, o);
                    }
                    case rdf_Term_term_blank:
                    {
                        __auto_type _ = _mv_763.data.term_blank;
                        return decode_decode_class_assertion(arena, g, t);
                    }
                    default: {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = decode_frag(arena, t) }) });
                    }
                }
            } else if (canon_string_cmp(pv, vocab_RDFS_SUBCLASS_OF) == 0) {
                __auto_type _mv_764 = decode_decode_concept(arena, g, t.subject, decode_CONCEPT_FUEL);
                if (!_mv_764.is_ok) {
                    __auto_type m = _mv_764.data.err;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                } else if (_mv_764.is_ok) {
                    __auto_type lhs = _mv_764.data.ok;
                    __auto_type _mv_765 = decode_decode_concept(arena, g, t.object, decode_CONCEPT_FUEL);
                    if (!_mv_765.is_ok) {
                        __auto_type m = _mv_765.data.err;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                    } else if (_mv_765.is_ok) {
                        __auto_type rhs = _mv_765.data.ok;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_sub_class_of, .data.ra_sub_class_of = { .f0 = decode_box_concept(arena, lhs), .f1 = decode_box_concept(arena, rhs) } }) });
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_OWL_EQUIVALENT_CLASS) == 0) {
                __auto_type _mv_766 = decode_binary_concepts(arena, g, t);
                if (!_mv_766.is_ok) {
                    __auto_type m = _mv_766.data.err;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                } else if (_mv_766.is_ok) {
                    __auto_type cs = _mv_766.data.ok;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_equivalent_classes, .data.ra_equivalent_classes = cs }) });
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_OWL_DISJOINT_WITH) == 0) {
                __auto_type _mv_767 = decode_binary_concepts(arena, g, t);
                if (!_mv_767.is_ok) {
                    __auto_type m = _mv_767.data.err;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                } else if (_mv_767.is_ok) {
                    __auto_type cs = _mv_767.data.ok;
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_classes, .data.ra_disjoint_classes = cs }) });
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_OWL_PROPERTY_CHAIN_AXIOM) == 0) {
                __auto_type _mv_768 = decode_property_expression(arena, g, t.subject);
                if (!_mv_768.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:propertyChainAxiom on a non-IRI subject") });
                } else if (_mv_768.has_value) {
                    __auto_type super = _mv_768.value;
                    __auto_type _mv_769 = decode_decode_role_list(arena, g, t.object);
                    if (!_mv_769.is_ok) {
                        __auto_type m = _mv_769.data.err;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                    } else if (_mv_769.is_ok) {
                        __auto_type steps = _mv_769.data.ok;
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
                    __auto_type _mv_770 = decode_property_expression(arena, g, t.subject);
                    if (!_mv_770.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("rdfs:subPropertyOf on a non-IRI subject") });
                    } else if (_mv_770.has_value) {
                        __auto_type sub = _mv_770.value;
                        __auto_type _mv_771 = decode_property_expression(arena, g, t.object);
                        if (!_mv_771.has_value) {
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("rdfs:subPropertyOf with a non-IRI object") });
                        } else if (_mv_771.has_value) {
                            __auto_type sup = _mv_771.value;
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_sub_object_property, .data.ra_sub_object_property = { .f0 = sub, .f1 = sup } }) });
                        }
                        SLOP_UNREACHABLE();
                    }
                    SLOP_UNREACHABLE();
                }
            } else if (((canon_string_cmp(pv, vocab_OWL_EQUIVALENT_PROPERTY) == 0) || ((canon_string_cmp(pv, vocab_OWL_PROPERTY_DISJOINT_WITH) == 0) || (canon_string_cmp(pv, vocab_OWL_INVERSE_OF) == 0))) && (decode_data_property_term(arena, g, t.subject) || decode_data_property_term(arena, g, t.object))) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = decode_frag(arena, t) }) });
            } else if (canon_string_cmp(pv, vocab_OWL_EQUIVALENT_PROPERTY) == 0) {
                __auto_type _mv_772 = decode_property_expression(arena, g, t.subject);
                if (!_mv_772.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:equivalentProperty on a non-IRI subject") });
                } else if (_mv_772.has_value) {
                    __auto_type a = _mv_772.value;
                    __auto_type _mv_773 = decode_property_expression(arena, g, t.object);
                    if (!_mv_773.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:equivalentProperty with a non-IRI object") });
                    } else if (_mv_773.has_value) {
                        __auto_type b = _mv_773.value;
                        {
                            __auto_type rs = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_equivalent_properties, .data.ra_equivalent_properties = rs }) });
                        }
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_OWL_PROPERTY_DISJOINT_WITH) == 0) {
                __auto_type _mv_774 = decode_property_expression(arena, g, t.subject);
                if (!_mv_774.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:propertyDisjointWith on a non-IRI subject") });
                } else if (_mv_774.has_value) {
                    __auto_type a = _mv_774.value;
                    __auto_type _mv_775 = decode_property_expression(arena, g, t.object);
                    if (!_mv_775.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:propertyDisjointWith with a non-IRI object") });
                    } else if (_mv_775.has_value) {
                        __auto_type b = _mv_775.value;
                        {
                            __auto_type rs = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_properties, .data.ra_disjoint_properties = rs }) });
                        }
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_OWL_INVERSE_OF) == 0) {
                __auto_type _mv_776 = decode_property_expression(arena, g, t.subject);
                if (!_mv_776.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:inverseOf on a non-IRI subject") });
                } else if (_mv_776.has_value) {
                    __auto_type a = _mv_776.value;
                    __auto_type _mv_777 = decode_property_expression(arena, g, t.object);
                    if (!_mv_777.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:inverseOf with a non-IRI object") });
                    } else if (_mv_777.has_value) {
                        __auto_type b = _mv_777.value;
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
                    __auto_type _mv_778 = decode_property_expression(arena, g, t.subject);
                    if (!_mv_778.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("rdfs:domain on a non-IRI subject") });
                    } else if (_mv_778.has_value) {
                        __auto_type r = _mv_778.value;
                        __auto_type _mv_779 = decode_decode_concept(arena, g, t.object, decode_CONCEPT_FUEL);
                        if (!_mv_779.is_ok) {
                            __auto_type m = _mv_779.data.err;
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                        } else if (_mv_779.is_ok) {
                            __auto_type c = _mv_779.data.ok;
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
                    __auto_type _mv_780 = decode_property_expression(arena, g, t.subject);
                    if (!_mv_780.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("rdfs:range on a non-IRI subject") });
                    } else if (_mv_780.has_value) {
                        __auto_type r = _mv_780.value;
                        __auto_type _mv_781 = decode_decode_concept(arena, g, t.object, decode_CONCEPT_FUEL);
                        if (!_mv_781.is_ok) {
                            __auto_type m = _mv_781.data.err;
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
                        } else if (_mv_781.is_ok) {
                            __auto_type c = _mv_781.data.ok;
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
                __auto_type _mv_782 = decode_term_iri_value(t.subject);
                if (!_mv_782.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = decode_frag(arena, t) }) });
                } else if (_mv_782.has_value) {
                    __auto_type c = _mv_782.value;
                    __auto_type _mv_783 = decode_decode_concept_list(arena, g, t.object, decode_CONCEPT_FUEL);
                    if (!_mv_783.is_ok) {
                        __auto_type _ = _mv_783.data.err;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = decode_frag(arena, t) }) });
                    } else if (_mv_783.is_ok) {
                        __auto_type ds = _mv_783.data.ok;
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_union, .data.ra_disjoint_union = ((owl2_RawDisjointUnion){.class = c, .members = ds}) }) });
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            } else if (canon_string_cmp(pv, vocab_OWL_HAS_KEY) == 0) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_has_key, .data.ra_has_key = decode_frag(arena, t) }) });
            } else if (owl2_signature_has_annotation_property(sig, p)) {
                return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_annotation }) });
            } else if (owl2_signature_has_object_property(sig, p)) {
                __auto_type _mv_784 = decode_role_of_term(t.predicate);
                if (!_mv_784.has_value) {
                    return ((slop_result_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("unreachable: declared object property is not an IRI") });
                } else if (_mv_784.has_value) {
                    __auto_type r = _mv_784.value;
                    __auto_type _mv_785 = decode_term_iri_value(t.subject);
                    if (!_mv_785.has_value) {
                        return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = decode_frag(arena, t) }) });
                    } else if (_mv_785.has_value) {
                        __auto_type sfrom = _mv_785.value;
                        __auto_type _mv_786 = decode_term_iri_value(t.object);
                        if (!_mv_786.has_value) {
                            return ((slop_result_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = decode_frag(arena, t) }) });
                        } else if (_mv_786.has_value) {
                            __auto_type sto = _mv_786.value;
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
                        ({ slop_map_put(NULL, keep, &(int64_t){id}, NULL, 0); });
                    }
                }
            }
        }
        {
            __auto_type ty = decode_vocab_id(arena, dict, vocab_RDF_TYPE);
            __auto_type dtp = decode_vocab_id(arena, dict, vocab_OWL_DATATYPE_PROPERTY);
            {
                __auto_type _coll = triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type it = _coll.data[_i];
                    if (slop_map_has(keep, &(int64_t){it.p}) || ((dtp >= 0) && ((it.p == ty) && (it.o == dtp)))) {
                        termstore_store_insert_ids(arena, st, it);
                    }
                }
            }
        }
        return st;
    }
}

slop_list_string decode_queried_predicates(slop_arena* arena) {
    {
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_RDF_FIRST); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_RDF_REST); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_ON_PROPERTY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_INVERSE_OF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_INTERSECTION_OF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_UNION_OF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_ONE_OF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_COMPLEMENT_OF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_SOME_VALUES_FROM); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_ALL_VALUES_FROM); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_HAS_VALUE); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_HAS_SELF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_QUALIFIED_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_MIN_QUALIFIED_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_MAX_QUALIFIED_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_MIN_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_MAX_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_ON_CLASS); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_ON_DATA_RANGE); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_ON_PROPERTIES); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_MEMBERS); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_DISTINCT_MEMBERS); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_SOURCE_INDIVIDUAL); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_ASSERTION_PROPERTY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_TARGET_INDIVIDUAL); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (vocab_OWL_TARGET_VALUE); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ps;
    }
}

slop_result_decode_Stage1_types_Fault decode_decode_axioms_with(slop_arena* arena, termstore_TermStore ig, termstore_TermStore dict, slop_list_termstore_IdTriple triples) {
    {
        __auto_type sig = decode_build_signature(arena, dict, triples);
        __auto_type out = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t inert = 0;
        slop_option_string fault = (slop_option_string){.has_value = false};
        fault = decode_declaration_conflict(arena, sig, dict, triples);
        {
            __auto_type npa_nodes = decode_negative_assertion_nodes(arena, dict, triples);
            __auto_type npa_parts = decode_negative_assertion_parts(arena, dict);
            __auto_type dv = decode_data_vocab(arena, dict);
            __auto_type lemma = decode_data_lemma(arena, dict, sig, dv, triples);
            {
                __auto_type _coll = triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type it = _coll.data[_i];
                    {
                        __auto_type t = termstore_triple_of(dict, it);
                        if (decode_malformed_inverse(arena, ig, t)) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = decode_frag(arena, t) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        } else {
                            if ((!(decode_structural_triple(t))) && (!(decode_negative_assertion_part(it, npa_nodes, npa_parts))) && (!(slop_map_has(lemma.tree, &(int64_t){it.s})))) {
                                if (decode_inert_data_axiom(dv, lemma, it)) {
                                    __auto_type _mv_790 = owl2_disposition(types_Profile_profile_el, ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inert_data }));
                                    if (_mv_790 == owl2_Disposition_d_inert) {
                                        inert = (inert + 1);
                                    } else {
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_inert_data })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                } else {
                                    __auto_type _mv_791 = decode_decode_axiom(arena, ig, sig, t);
                                    if (!_mv_791.is_ok) {
                                        __auto_type m = _mv_791.data.err;
                                        fault = (slop_option_string){.has_value = 1, .value = m};
                                    } else if (_mv_791.is_ok) {
                                        __auto_type ax = _mv_791.data.ok;
                                        __auto_type _mv_792 = owl2_disposition(types_Profile_profile_el, ax);
                                        if (_mv_792 == owl2_Disposition_d_inert) {
                                            inert = (inert + 1);
                                        } else if (_mv_792 == owl2_Disposition_d_consumed) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        } else if (_mv_792 == owl2_Disposition_d_in_profile) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        } else if (_mv_792 == owl2_Disposition_d_out_of_profile) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        __auto_type _mv_793 = fault;
        if (_mv_793.has_value) {
            __auto_type m = _mv_793.value;
            return ((slop_result_decode_Stage1_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_input_error, .data.input_error = m }) });
        } else if (!_mv_793.has_value) {
            return ((slop_result_decode_Stage1_types_Fault){ .is_ok = true, .data.ok = ((decode_Stage1){.axioms = out, .signature = sig, .inert = inert}) });
        }
        SLOP_UNREACHABLE();
    }
}

decode_DataVocab decode_data_vocab(slop_arena* arena, termstore_TermStore dict) {
    return ((decode_DataVocab){.rdf_type = dict.rdf_type, .data_property = decode_vocab_id(arena, dict, vocab_OWL_DATATYPE_PROPERTY), .functional = decode_vocab_id(arena, dict, vocab_OWL_FUNCTIONAL_PROPERTY), .domain = decode_vocab_id(arena, dict, vocab_RDFS_DOMAIN), .range = decode_vocab_id(arena, dict, vocab_RDFS_RANGE), .sub_property = decode_vocab_id(arena, dict, vocab_RDFS_SUBPROPERTY_OF), .equivalent = decode_vocab_id(arena, dict, vocab_OWL_EQUIVALENT_PROPERTY), .disjoint = decode_vocab_id(arena, dict, vocab_OWL_PROPERTY_DISJOINT_WITH), .top = decode_vocab_id(arena, dict, vocab_OWL_TOP_DATA_PROPERTY), .on_datatype = decode_vocab_id(arena, dict, vocab_OWL_ON_DATATYPE)});
}

decode_DataLemma decode_data_lemma(slop_arena* arena, termstore_TermStore dict, owl2_Signature sig, decode_DataVocab v, slop_list_termstore_IdTriple triples) {
    {
        __auto_type data = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type used = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type idle = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type tree = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type bottom = decode_vocab_id(arena, dict, vocab_OWL_BOTTOM_DATA_PROPERTY);
        uint8_t any = 0;
        uint8_t changed = 1;
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if ((it.p == v.rdf_type) && (it.o == v.data_property)) {
                    ({ slop_map_put(NULL, data, &(int64_t){it.s}, NULL, 0); });
                    any = 1;
                }
            }
        }
        if (v.top >= 0) {
            ({ slop_map_put(NULL, data, &(int64_t){v.top}, NULL, 0); });
            ({ slop_map_put(NULL, used, &(int64_t){v.top}, NULL, 0); });
            any = 1;
        }
        if (bottom >= 0) {
            ({ slop_map_put(NULL, data, &(int64_t){bottom}, NULL, 0); });
            any = 1;
        }
        if (any) {
            {
                __auto_type _coll = triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type it = _coll.data[_i];
                    decode_mark_data_uses(dict, sig, v, data, used, it);
                }
            }
            while (changed) {
                changed = 0;
                {
                    __auto_type _coll = triples;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type it = _coll.data[_i];
                        if (slop_map_has(data, &(int64_t){it.s}) && slop_map_has(data, &(int64_t){it.o})) {
                            if ((((it.p == v.sub_property) || (it.p == v.equivalent))) && (slop_map_has(used, &(int64_t){it.s})) && (!(slop_map_has(used, &(int64_t){it.o})))) {
                                ({ slop_map_put(NULL, used, &(int64_t){it.o}, NULL, 0); });
                                changed = 1;
                            }
                            if (((it.p == v.equivalent)) && (slop_map_has(used, &(int64_t){it.o})) && (!(slop_map_has(used, &(int64_t){it.s})))) {
                                ({ slop_map_put(NULL, used, &(int64_t){it.s}, NULL, 0); });
                                changed = 1;
                            }
                        }
                    }
                }
            }
            {
                __auto_type _coll = triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type it = _coll.data[_i];
                    if (((it.p == v.rdf_type)) && ((it.o == v.data_property)) && (!(slop_map_has(used, &(int64_t){it.s})))) {
                        ({ slop_map_put(NULL, idle, &(int64_t){it.s}, NULL, 0); });
                    }
                }
            }
            if ((bottom >= 0) && !(slop_map_has(used, &(int64_t){bottom}))) {
                ({ slop_map_put(NULL, idle, &(int64_t){bottom}, NULL, 0); });
            }
            decode_collect_inert_trees(arena, dict, v, idle, tree, triples);
        }
        return ((decode_DataLemma){.data = data, .idle = idle, .tree = tree});
    }
}

void decode_mark_data_uses(termstore_TermStore dict, owl2_Signature sig, decode_DataVocab v, slop_map* data, slop_map* used, termstore_IdTriple it) {
    {
        __auto_type s = it.s;
        __auto_type p = it.p;
        __auto_type o = it.o;
        if (p == v.rdf_type) {
            if (slop_map_has(data, &(int64_t){o})) {
                ({ slop_map_put(NULL, used, &(int64_t){o}, NULL, 0); });
            }
            if ((slop_map_has(data, &(int64_t){s})) && (!((o == v.data_property))) && (!((o == v.functional)))) {
                ({ slop_map_put(NULL, used, &(int64_t){s}, NULL, 0); });
            }
        } else if (decode_predicate_is_annotation(dict, sig, p)) {
        } else if ((p == v.domain) || (p == v.range)) {
            if (slop_map_has(data, &(int64_t){o})) {
                ({ slop_map_put(NULL, used, &(int64_t){o}, NULL, 0); });
            }
        } else if ((((p == v.sub_property) || ((p == v.equivalent) || (p == v.disjoint)))) && (slop_map_has(data, &(int64_t){s})) && (slop_map_has(data, &(int64_t){o}))) {
        } else {
            if (slop_map_has(data, &(int64_t){s})) {
                ({ slop_map_put(NULL, used, &(int64_t){s}, NULL, 0); });
            }
            if (slop_map_has(data, &(int64_t){p})) {
                ({ slop_map_put(NULL, used, &(int64_t){p}, NULL, 0); });
            }
            if (slop_map_has(data, &(int64_t){o})) {
                ({ slop_map_put(NULL, used, &(int64_t){o}, NULL, 0); });
            }
        }
    }
}

uint8_t decode_predicate_is_annotation(termstore_TermStore dict, owl2_Signature sig, int64_t p) {
    __auto_type _mv_824 = decode_term_iri_value(termstore_term_of(dict, p));
    if (_mv_824.has_value) {
        __auto_type i = _mv_824.value;
        return owl2_signature_has_annotation_property(sig, i);
    } else if (!_mv_824.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

void decode_collect_inert_trees(slop_arena* arena, termstore_TermStore dict, decode_DataVocab v, slop_map* idle, slop_map* tree, slop_list_termstore_IdTriple triples) {
    {
        __auto_type once = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type twice = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type heads_two = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type heads = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type restricts = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type impure = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        uint8_t changed = 0;
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (decode_id_is_blank(dict, it.o)) {
                    if (slop_map_has(once, &(int64_t){it.o})) {
                        ({ slop_map_put(NULL, twice, &(int64_t){it.o}, NULL, 0); });
                    } else {
                        ({ slop_map_put(NULL, once, &(int64_t){it.o}, NULL, 0); });
                    }
                }
                if (slop_map_has(heads, &(int64_t){it.s})) {
                    ({ slop_map_put(NULL, heads_two, &(int64_t){it.s}, NULL, 0); });
                } else {
                    ({ slop_map_put(NULL, heads, &(int64_t){it.s}, NULL, 0); });
                }
                if (it.p == v.on_datatype) {
                    ({ slop_map_put(NULL, restricts, &(int64_t){it.s}, NULL, 0); });
                }
            }
        }
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (decode_id_is_blank(dict, it.s) && !(decode_filler_triple(termstore_triple_of(dict, it), slop_map_has(restricts, &(int64_t){it.s}), !(slop_map_has(heads_two, &(int64_t){it.s}))))) {
                    ({ slop_map_put(NULL, impure, &(int64_t){it.s}, NULL, 0); });
                }
            }
        }
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if ((((it.p == v.domain) || (it.p == v.range))) && (slop_map_has(idle, &(int64_t){it.s})) && (slop_map_has(once, &(int64_t){it.o})) && (!(slop_map_has(twice, &(int64_t){it.o}))) && (!(slop_map_has(impure, &(int64_t){it.o})))) {
                    ({ slop_map_put(NULL, tree, &(int64_t){it.o}, NULL, 0); });
                    changed = 1;
                }
            }
        }
        while (changed) {
            changed = 0;
            {
                __auto_type _coll = triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type it = _coll.data[_i];
                    if ((slop_map_has(tree, &(int64_t){it.s})) && (!(slop_map_has(tree, &(int64_t){it.o}))) && (slop_map_has(once, &(int64_t){it.o})) && (!(slop_map_has(twice, &(int64_t){it.o}))) && (!(slop_map_has(impure, &(int64_t){it.o})))) {
                        ({ slop_map_put(NULL, tree, &(int64_t){it.o}, NULL, 0); });
                        changed = 1;
                    }
                }
            }
        }
    }
}

uint8_t decode_filler_triple(rdf_Triple t, uint8_t restriction, uint8_t single) {
    return (decode_structural_triple(t) || ({ __auto_type _mv = decode_term_iri_value(t.predicate); _mv.has_value ? ({ __auto_type p = _mv.value; ((canon_string_cmp(p.value, vocab_OWL_WITH_RESTRICTIONS) == 0) ? restriction : ((canon_string_cmp(p.value, vocab_RDF_LANG_RANGE) == 0) ? single : (strlib_starts_with(p.value, vocab_XSD_NS) ? single : ((canon_string_cmp(p.value, vocab_RDF_TYPE) == 0) ? ({ __auto_type _mv = decode_term_iri_value(t.object); _mv.has_value ? ({ __auto_type o = _mv.value; ((canon_string_cmp(o.value, vocab_RDFS_DATATYPE) == 0) || (canon_string_cmp(o.value, vocab_OWL_DATA_RANGE) == 0)); }) : (0); }) : 0)))); }) : (0); }));
}

uint8_t decode_id_is_blank(termstore_TermStore dict, int64_t id) {
    __auto_type _mv_846 = termstore_term_of(dict, id);
    switch (_mv_846.tag) {
        case rdf_Term_term_blank:
        {
            __auto_type _ = _mv_846.data.term_blank;
            return 1;
        }
        case rdf_Term_term_iri:
        {
            __auto_type _ = _mv_846.data.term_iri;
            return 0;
        }
        case rdf_Term_term_literal:
        {
            __auto_type _ = _mv_846.data.term_literal;
            return 0;
        }
        case rdf_Term_term_triple:
        {
            __auto_type _ = _mv_846.data.term_triple;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t decode_inert_data_axiom(decode_DataVocab v, decode_DataLemma lemma, termstore_IdTriple it) {
    {
        __auto_type s = it.s;
        __auto_type p = it.p;
        __auto_type o = it.o;
        __auto_type data = lemma.data;
        __auto_type idle = lemma.idle;
        if ((p == v.domain) || (p == v.range)) {
            return slop_map_has(idle, &(int64_t){s});
        } else if (p == v.rdf_type) {
            return ((o == v.functional) && slop_map_has(idle, &(int64_t){s}));
        } else if (p == v.sub_property) {
            return ((slop_map_has(data, &(int64_t){s})) && (slop_map_has(data, &(int64_t){o})) && ((slop_map_has(idle, &(int64_t){s}) || (o == v.top))));
        } else if (p == v.equivalent) {
            return (slop_map_has(idle, &(int64_t){s}) && slop_map_has(idle, &(int64_t){o}));
        } else if (p == v.disjoint) {
            return ((slop_map_has(data, &(int64_t){s})) && (slop_map_has(data, &(int64_t){o})) && (!((s == v.top))) && (!((o == v.top))) && ((slop_map_has(idle, &(int64_t){s}) || slop_map_has(idle, &(int64_t){o}))));
        } else {
            return 0;
        }
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
                        ({ slop_map_put(NULL, out, &(int64_t){it.s}, NULL, 0); });
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
            __auto_type _coll = ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 4 * sizeof(slop_string)), .len = 4, .cap = 4, .arena = arena }; _ll.data[0] = vocab_OWL_SOURCE_INDIVIDUAL; _ll.data[1] = vocab_OWL_ASSERTION_PROPERTY; _ll.data[2] = vocab_OWL_TARGET_INDIVIDUAL; _ll.data[3] = vocab_OWL_TARGET_VALUE; _ll; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type iri = _coll.data[_i];
                {
                    __auto_type id = decode_vocab_id(arena, dict, iri);
                    if (id >= 0) {
                        ({ slop_map_put(NULL, out, &(int64_t){id}, NULL, 0); });
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
                    __auto_type _mv_862 = decode_term_iri_value(termstore_term_of(dict, it.s));
                    if (_mv_862.has_value) {
                        __auto_type e = _mv_862.value;
                        {
                            __auto_type np = (((owl2_signature_has_object_property(sig, e)) ? 1 : 0) + (((owl2_signature_has_data_property(sig, e)) ? 1 : 0) + ((owl2_signature_has_annotation_property(sig, e)) ? 1 : 0)));
                            if (np > 1) {
                                bad = (slop_option_string){.has_value = 1, .value = string_concat(arena, SLOP_STR("IRI declared under two disjoint property kinds: "), e.value)};
                            }
                        }
                    } else if (!_mv_862.has_value) {
                    }
                }
            }
        }
        return bad;
    }
}

