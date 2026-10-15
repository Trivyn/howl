#include "../runtime/slop_runtime.h"
#include "slop_decode.h"


slop_rdf_rdf_Term howl_decode_term_at(slop_list_slop_rdf_rdf_Term xs, int64_t i);
slop_rdf_rdf_Triple howl_decode_triple_at(slop_list_slop_rdf_rdf_Triple xs, int64_t i);
howl_termstore_TermStore howl_decode_graph_to_indexed(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples);
slop_result_slop_rdf_rdf_Term_howl_decode_LookupFault howl_decode_one_object(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term subj, slop_rdf_rdf_Term pred);
slop_option_howl_decode_ListFault howl_decode_cell_fault(int64_t nf, int64_t nr);
slop_result_list_slop_rdf_rdf_Term_howl_decode_ListFault howl_decode_rdf_list_checked(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term head);
slop_option_slop_rdf_rdf_IRI howl_decode_term_iri_value(slop_rdf_rdf_Term t);
uint8_t howl_decode_iri_in_list(slop_list_slop_rdf_rdf_IRI xs, slop_rdf_rdf_IRI target);
slop_list_slop_rdf_rdf_IRI howl_decode_collect_imports(slop_arena* arena, howl_termstore_Encoded doc);
int64_t howl_decode_vocab_id(slop_arena* arena, howl_termstore_TermStore dict, slop_string iri);
slop_list_howl_types_Omission howl_decode_unresolved_imports(slop_arena* arena, slop_list_slop_rdf_rdf_IRI declared, slop_list_slop_rdf_rdf_IRI resolved);
uint8_t howl_decode_typed_as(slop_rdf_rdf_Triple t, slop_string type_iri);
slop_list_int howl_decode_typed_ids_in_order(slop_arena* arena, howl_termstore_Encoded doc, slop_string type_iri);
uint8_t howl_decode_logical_predicate(slop_string pv);
slop_rdf_rdf_Triple howl_decode_ex_hdr(slop_string p, slop_string o);
uint8_t howl_decode_header_consumable(slop_rdf_rdf_Triple t);
slop_result_howl_decode_Stage0_howl_types_Fault howl_decode_stage0_header(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved);
slop_result_howl_decode_Stage0_howl_types_Fault howl_decode_stage0_encoded(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved);
slop_map* howl_decode_id_set(slop_arena* arena, slop_list_int a, slop_list_int b, slop_list_int c);
howl_termstore_TermStore howl_decode_annotated_store(slop_arena* arena, howl_termstore_Encoded doc);
int64_t howl_decode_term_id(howl_termstore_TermStore st, slop_rdf_rdf_Term t);
slop_result_howl_termstore_IdTriple_string howl_decode_rebuild_one(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Term a, slop_rdf_rdf_Term src_pred, slop_rdf_rdf_Term prop_pred, slop_rdf_rdf_Term tgt_pred);
howl_decode_Rebuilt howl_decode_rebuild_candidates(slop_arena* arena, howl_termstore_TermStore st, slop_list_int ax_subjs);
slop_map* howl_decode_asserted_among(slop_arena* arena, slop_list_howl_termstore_IdTriple candidates, howl_termstore_Encoded doc);
slop_result_howl_decode_Stage0_howl_types_Fault howl_decode_stage0_scan(slop_arena* arena, slop_arena* scratch, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved);
howl_owl2_RawConcept* howl_decode_box_concept(slop_arena* arena, howl_owl2_RawConcept c);
slop_string howl_decode_list_fault_message(howl_decode_ListFault f);
uint8_t howl_decode_has_pred(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term s, slop_string pred_iri);
slop_result_slop_rdf_rdf_Term_howl_decode_LookupFault howl_decode_obj_of(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term s, slop_string pred_iri);
slop_result_howl_types_RoleId_string howl_decode_decode_role(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b);
slop_option_howl_types_RoleId howl_decode_property_expression(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term t);
uint8_t howl_decode_malformed_inverse(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
uint8_t howl_decode_data_property_term(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term t);
uint8_t howl_decode_restriction_on_data(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b);
slop_string howl_decode_data_restriction_pred(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b);
slop_string howl_decode_data_restriction_name(slop_string pred);
slop_string howl_decode_filler_text(slop_arena* arena, slop_rdf_rdf_Term t);
slop_string howl_decode_terms_text(slop_arena* arena, slop_list_slop_rdf_rdf_Term terms);
slop_string howl_decode_on_properties_text(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b);
slop_string howl_decode_nary_text(slop_arena* arena, slop_string name, slop_string props, slop_string fill);
howl_owl2_RawConcept howl_decode_nary_data_restriction(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b);
howl_owl2_RawConcept howl_decode_data_restriction(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b);
slop_result_int_string howl_decode_literal_count(slop_rdf_rdf_Term t);
howl_decode_IndividualTerm howl_decode_individual_term(slop_rdf_rdf_Term tm);
slop_result_howl_decode_NodeList_string howl_decode_decode_node_list(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term head);
slop_result_list_howl_owl2_RawConcept_string howl_decode_decode_concept_list(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term head, int64_t fuel);
slop_result_howl_owl2_RawConcept_string howl_decode_decode_quantified(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b, slop_string filler_pred, uint8_t universal, int64_t fuel);
slop_result_int_string howl_decode_cardinality_count(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b, slop_string count_pred);
slop_result_howl_owl2_RawConcept_string howl_decode_qualified_cardinality(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b, howl_owl2_CardKind kind, howl_types_RoleId r, int64_t n, int64_t fuel);
slop_result_howl_owl2_RawConcept_string howl_decode_decode_cardinality(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b, howl_owl2_CardKind kind, slop_string count_pred, uint8_t qualified, int64_t fuel);
slop_result_howl_owl2_RawConcept_string howl_decode_decode_anon(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b, int64_t fuel);
slop_result_howl_owl2_RawConcept_string howl_decode_decode_concept(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term t, int64_t fuel);
uint8_t howl_decode_declare_entity(slop_arena* arena, howl_owl2_Signature sig, slop_rdf_rdf_IRI entity, slop_string type_iri);
uint8_t howl_decode_add_builtins(slop_arena* arena, howl_owl2_Signature sig);
howl_owl2_Signature howl_decode_build_signature(slop_arena* arena, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples);
slop_string howl_decode_render_term(slop_arena* arena, slop_rdf_rdf_Term t);
slop_string howl_decode_nt_escape(slop_arena* arena, slop_string s);
slop_string howl_decode_render_triple(slop_arena* arena, slop_rdf_rdf_Triple t);
howl_types_InputRef howl_decode_frag(slop_arena* arena, slop_rdf_rdf_Triple t);
uint8_t howl_decode_is_pred(slop_rdf_rdf_Triple t, slop_string iri);
uint8_t howl_decode_structural_predicate(slop_string p);
uint8_t howl_decode_structural_triple(slop_rdf_rdf_Triple t);
slop_option_howl_types_EntityKind howl_decode_entity_kind_of(slop_string type_iri);
slop_option_howl_owl2_PropCharacteristic howl_decode_characteristic_of(slop_string type_iri);
slop_option_howl_types_RoleId howl_decode_role_of_term(slop_rdf_rdf_Term t);
slop_result_list_howl_types_RoleId_string howl_decode_decode_role_list(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term head);
uint8_t howl_decode_list_has_data(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term head);
slop_result_list_howl_owl2_RawConcept_string howl_decode_binary_concepts(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_option_slop_rdf_rdf_Term howl_decode_members_head(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term s);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_declaration(slop_arena* arena, slop_rdf_rdf_Triple t, howl_types_EntityKind k);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_all_different(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_all_disjoint_classes(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_all_disjoint_properties(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_typed(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t, slop_rdf_rdf_IRI obj);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_individual_pair(slop_arena* arena, slop_rdf_rdf_Triple t, uint8_t same);
slop_result_howl_owl2_RawAxiom_string howl_decode_negative_object_assertion(slop_arena* arena, slop_rdf_rdf_Triple t, howl_types_RoleId r, slop_rdf_rdf_Term st, slop_rdf_rdf_Term tt);
slop_result_howl_owl2_RawAxiom_string howl_decode_negative_target_individual(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t, slop_rdf_rdf_Term pt, slop_rdf_rdf_Term st);
slop_result_howl_owl2_RawAxiom_string howl_decode_negative_target(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t, slop_rdf_rdf_Term pt, slop_rdf_rdf_Term st);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_negative_assertion(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_class_assertion(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
uint8_t howl_decode_is_reserved_iri(slop_string v);
int64_t howl_decode_property_axiom_kind(howl_owl2_Signature sig, slop_rdf_rdf_Term subj);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_sub_class_of(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_property_chain(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_sub_property(slop_arena* arena, howl_termstore_TermStore g, howl_owl2_Signature sig, slop_rdf_rdf_Triple t);
slop_result_list_howl_types_RoleId_string howl_decode_property_pair(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t, slop_string pred);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_inverse_of(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_domain(slop_arena* arena, howl_termstore_TermStore g, howl_owl2_Signature sig, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_range(slop_arena* arena, howl_termstore_TermStore g, howl_owl2_Signature sig, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_disjoint_union(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_assertion_between(slop_arena* arena, slop_rdf_rdf_Triple t, howl_types_RoleId r, slop_rdf_rdf_IRI sfrom, slop_rdf_rdf_IRI sto);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_property_assertion(slop_arena* arena, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_list_axiom(slop_result_list_howl_owl2_RawConcept_string r, uint8_t disjoint);
slop_result_howl_owl2_RawAxiom_string howl_decode_pair_axiom(slop_result_list_howl_types_RoleId_string r, uint8_t disjoint);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_axiom(slop_arena* arena, howl_termstore_TermStore g, howl_owl2_Signature sig, slop_rdf_rdf_Triple t);
slop_result_howl_decode_Stage1_howl_types_Fault howl_decode_decode_axioms(slop_arena* arena, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples);
howl_termstore_TermStore howl_decode_decode_store(slop_arena* arena, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples);
slop_list_string howl_decode_queried_predicates(slop_arena* arena);
uint8_t howl_decode_keep_axiom(howl_decode_Decoding* c, howl_owl2_RawAxiom ax);
uint8_t howl_decode_decode_triple(slop_arena* arena, howl_decode_Decoding* c, howl_termstore_IdTriple it, slop_rdf_rdf_Triple t);
slop_result_howl_decode_Stage1_howl_types_Fault howl_decode_decode_axioms_with(slop_arena* arena, howl_termstore_TermStore ig, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples);
slop_option_slop_rdf_rdf_IRI howl_decode_undeclared_predicate(howl_owl2_Signature sig, slop_rdf_rdf_Triple t);
slop_list_howl_types_Omission howl_decode_undeclared_omissions(slop_arena* arena, slop_list_slop_rdf_rdf_IRI ps, slop_list_string texts);
howl_types_Omission howl_decode_undeclared_of(slop_rdf_rdf_IRI p, slop_list_string refs);
howl_decode_DataVocab howl_decode_data_vocab(slop_arena* arena, howl_termstore_TermStore dict);
uint8_t howl_decode_promote_use(howl_decode_DataVocab v, slop_map* used, howl_termstore_IdTriple it);
uint8_t howl_decode_promote_uses(howl_decode_DataVocab v, slop_map* data, slop_map* used, slop_list_howl_termstore_IdTriple triples);
void howl_decode_collect_idle(howl_decode_DataVocab v, slop_map* used, slop_map* idle, int64_t bottom, slop_list_howl_termstore_IdTriple triples);
howl_decode_DataLemma howl_decode_data_lemma(slop_arena* arena, howl_termstore_TermStore dict, howl_owl2_Signature sig, howl_decode_DataVocab v, slop_list_howl_termstore_IdTriple triples);
void howl_decode_mark_data_uses(howl_termstore_TermStore dict, howl_owl2_Signature sig, howl_decode_DataVocab v, slop_map* data, slop_map* used, howl_termstore_IdTriple it);
uint8_t howl_decode_predicate_is_annotation(howl_termstore_TermStore dict, howl_owl2_Signature sig, int64_t p);
void howl_decode_collect_inert_trees(slop_arena* arena, howl_termstore_TermStore dict, howl_decode_DataVocab v, slop_map* idle, slop_map* tree, slop_list_howl_termstore_IdTriple triples);
uint8_t howl_decode_filler_triple(slop_rdf_rdf_Triple t, uint8_t restriction, uint8_t single);
uint8_t howl_decode_id_is_blank(howl_termstore_TermStore dict, int64_t id);
uint8_t howl_decode_inert_data_axiom(howl_decode_DataVocab v, howl_decode_DataLemma lemma, howl_termstore_IdTriple it);
slop_map* howl_decode_negative_assertion_nodes(slop_arena* arena, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples);
slop_map* howl_decode_negative_assertion_parts(slop_arena* arena, howl_termstore_TermStore dict);
uint8_t howl_decode_negative_assertion_part(howl_termstore_IdTriple it, slop_map* nodes, slop_map* parts);
int64_t howl_decode_property_kinds(howl_owl2_Signature sig, slop_rdf_rdf_IRI e);
slop_option_string howl_decode_declaration_conflict(slop_arena* arena, howl_owl2_Signature sig, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples);

typedef struct { slop_list_slop_rdf_rdf_IRI ps; slop_list_string texts; } howl_decode__lambda_989_env_t;

static int64_t howl_decode__lambda_989(howl_decode__lambda_989_env_t* _env, int64_t i, int64_t j) { return ({ __auto_type c = howl_canon_iri_cmp(howl_canon_iri_at(_env->ps, i), howl_canon_iri_at(_env->ps, j)); (((c != 0)) ? c : howl_canon_string_cmp(howl_canon_str_at(_env->texts, i), howl_canon_str_at(_env->texts, j))); }); }

slop_rdf_rdf_Term howl_decode_term_at(slop_list_slop_rdf_rdf_Term xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_827 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_slop_rdf_rdf_Term _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_827.has_value) {
        __auto_type v = _mv_827.value;
        return v;
    } else if (!_mv_827.has_value) {
        return ((slop_rdf_rdf_Term){ .tag = slop_rdf_rdf_Term_term_blank, .data.term_blank = ((slop_rdf_rdf_BlankNode){.id = 0}) });
    }
    SLOP_UNREACHABLE();
}

slop_rdf_rdf_Triple howl_decode_triple_at(slop_list_slop_rdf_rdf_Triple xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    {
        __auto_type blank = ((slop_rdf_rdf_Term){ .tag = slop_rdf_rdf_Term_term_blank, .data.term_blank = ((slop_rdf_rdf_BlankNode){.id = 0}) });
        __auto_type _mv_828 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_slop_rdf_rdf_Triple _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_828.has_value) {
            __auto_type v = _mv_828.value;
            return v;
        } else if (!_mv_828.has_value) {
            return ((slop_rdf_rdf_Triple){.subject = blank, .predicate = blank, .object = blank});
        }
        SLOP_UNREACHABLE();
    }
}

howl_termstore_TermStore howl_decode_graph_to_indexed(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples) {
    return howl_termstore_build_store(arena, triples);
}

slop_result_slop_rdf_rdf_Term_howl_decode_LookupFault howl_decode_one_object(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term subj, slop_rdf_rdf_Term pred) {
    {
        __auto_type n = howl_termstore_store_object_count(g, subj, pred);
        if (n == 1) {
            __auto_type _mv_829 = howl_termstore_store_sole_object(g, subj, pred);
            if (_mv_829.has_value) {
                __auto_type o = _mv_829.value;
                return ((slop_result_slop_rdf_rdf_Term_howl_decode_LookupFault){ .is_ok = true, .data.ok = o });
            } else if (!_mv_829.has_value) {
                return ((slop_result_slop_rdf_rdf_Term_howl_decode_LookupFault){ .is_ok = false, .data.err = howl_decode_LookupFault_lookup_missing });
            }
            SLOP_UNREACHABLE();
        } else if (n == 0) {
            return ((slop_result_slop_rdf_rdf_Term_howl_decode_LookupFault){ .is_ok = false, .data.err = howl_decode_LookupFault_lookup_missing });
        } else {
            return ((slop_result_slop_rdf_rdf_Term_howl_decode_LookupFault){ .is_ok = false, .data.err = howl_decode_LookupFault_lookup_ambiguous });
        }
    }
}

slop_option_howl_decode_ListFault howl_decode_cell_fault(int64_t nf, int64_t nr) {
    if (nf == 0) {
        return (slop_option_howl_decode_ListFault){.has_value = 1, .value = ((howl_decode_ListFault){ .tag = howl_decode_ListFault_list_truncated, .data.list_truncated = SLOP_STR("list cell has no rdf:first") })};
    } else if (nf > 1) {
        return (slop_option_howl_decode_ListFault){.has_value = 1, .value = ((howl_decode_ListFault){ .tag = howl_decode_ListFault_list_branching, .data.list_branching = SLOP_STR("list cell has several rdf:first values") })};
    } else if (nr == 0) {
        return (slop_option_howl_decode_ListFault){.has_value = 1, .value = ((howl_decode_ListFault){ .tag = howl_decode_ListFault_list_truncated, .data.list_truncated = SLOP_STR("list cell has no rdf:rest") })};
    } else if (nr > 1) {
        return (slop_option_howl_decode_ListFault){.has_value = 1, .value = ((howl_decode_ListFault){ .tag = howl_decode_ListFault_list_branching, .data.list_branching = SLOP_STR("list cell has several rdf:rest values") })};
    } else {
        return (slop_option_howl_decode_ListFault){.has_value = false};
    }
}

slop_result_list_slop_rdf_rdf_Term_howl_decode_ListFault howl_decode_rdf_list_checked(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term head) {
    {
        __auto_type first_pred = rdf_make_iri(arena, slop_rdf_vocab_RDF_FIRST);
        __auto_type rest_pred = rdf_make_iri(arena, slop_rdf_vocab_RDF_REST);
        __auto_type nil_term = rdf_make_iri(arena, slop_rdf_vocab_RDF_NIL);
        __auto_type out = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type visited = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type current = head;
        slop_option_howl_decode_ListFault fault = (slop_option_howl_decode_ListFault){.has_value = false};
        uint8_t done = 0;
        while (!(done) && !(rdf_term_eq(current, nil_term))) {
            if (slop_map_has(visited, &(current))) {
                fault = (slop_option_howl_decode_ListFault){.has_value = 1, .value = ((howl_decode_ListFault){ .tag = howl_decode_ListFault_list_cyclic, .data.list_cyclic = SLOP_STR("rdf:rest returns to a cell already visited") })};
                done = 1;
            } else {
                (void)(({ slop_map_put(NULL, visited, &(current), NULL, 0); }));
                {
                    __auto_type firsts = howl_termstore_store_objects(arena, g, current, first_pred);
                    __auto_type rests = howl_termstore_store_objects(arena, g, current, rest_pred);
                    __auto_type _mv_832 = howl_decode_cell_fault(((int64_t)(((int64_t)((firsts).len)))), ((int64_t)(((int64_t)((rests).len)))));
                    if (_mv_832.has_value) {
                        __auto_type f = _mv_832.value;
                        fault = (slop_option_howl_decode_ListFault){.has_value = 1, .value = f};
                        done = 1;
                    } else if (!_mv_832.has_value) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_decode_term_at(firsts, 0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        current = howl_decode_term_at(rests, 0);
                    }
                }
            }
        }
        __auto_type _mv_833 = fault;
        if (_mv_833.has_value) {
            __auto_type f = _mv_833.value;
            return ((slop_result_list_slop_rdf_rdf_Term_howl_decode_ListFault){ .is_ok = false, .data.err = f });
        } else if (!_mv_833.has_value) {
            return ((slop_result_list_slop_rdf_rdf_Term_howl_decode_ListFault){ .is_ok = true, .data.ok = out });
        }
        SLOP_UNREACHABLE();
    }
}

slop_option_slop_rdf_rdf_IRI howl_decode_term_iri_value(slop_rdf_rdf_Term t) {
    __auto_type _mv_834 = t;
    switch (_mv_834.tag) {
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type i = _mv_834.data.term_iri;
            return (slop_option_slop_rdf_rdf_IRI){.has_value = 1, .value = i};
        }
        case slop_rdf_rdf_Term_term_blank:
        {
            __auto_type _ = _mv_834.data.term_blank;
            return (slop_option_slop_rdf_rdf_IRI){.has_value = false};
        }
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type _ = _mv_834.data.term_literal;
            return (slop_option_slop_rdf_rdf_IRI){.has_value = false};
        }
        case slop_rdf_rdf_Term_term_triple:
        {
            __auto_type _ = _mv_834.data.term_triple;
            return (slop_option_slop_rdf_rdf_IRI){.has_value = false};
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_decode_iri_in_list(slop_list_slop_rdf_rdf_IRI xs, slop_rdf_rdf_IRI target) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (howl_canon_iri_cmp(x, target) == 0) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_list_slop_rdf_rdf_IRI howl_decode_collect_imports(slop_arena* arena, howl_termstore_Encoded doc) {
    {
        __auto_type imports_id = howl_decode_vocab_id(arena, doc.dict, slop_rdf_vocab_OWL_IMPORTS);
        __auto_type out = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = doc.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (it.p == imports_id) {
                    __auto_type _mv_835 = howl_decode_term_iri_value(howl_termstore_term_of(doc.dict, it.o));
                    if (_mv_835.has_value) {
                        __auto_type i = _mv_835.value;
                        if (!(howl_decode_iri_in_list(out, i))) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    } else if (!_mv_835.has_value) {
                    }
                }
            }
        }
        return howl_canon_sort_iris(arena, out);
    }
}

int64_t howl_decode_vocab_id(slop_arena* arena, howl_termstore_TermStore dict, slop_string iri) {
    __auto_type _mv_836 = howl_termstore_lookup_term(dict, rdf_make_iri(arena, iri));
    if (_mv_836.has_value) {
        __auto_type i = _mv_836.value;
        return i;
    } else if (!_mv_836.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Omission howl_decode_unresolved_imports(slop_arena* arena, slop_list_slop_rdf_rdf_IRI declared, slop_list_slop_rdf_rdf_IRI resolved) {
    {
        __auto_type out = ((slop_list_howl_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = declared;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type d = _coll.data[_i];
                if (!(howl_decode_iri_in_list(resolved, d))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_types_Omission){ .tag = howl_types_Omission_unresolved_import, .data.unresolved_import = d })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return howl_canon_sort_omissions(arena, out);
    }
}

uint8_t howl_decode_typed_as(slop_rdf_rdf_Triple t, slop_string type_iri) {
    __auto_type _mv_837 = howl_decode_term_iri_value(t.predicate);
    if (!_mv_837.has_value) {
        return 0;
    } else if (_mv_837.has_value) {
        __auto_type p = _mv_837.value;
        return ((howl_canon_string_cmp(p.value, slop_rdf_vocab_RDF_TYPE) == 0) && ({ __auto_type _mv = howl_decode_term_iri_value(t.object); _mv.has_value ? ({ __auto_type o = _mv.value; (howl_canon_string_cmp(o.value, type_iri) == 0); }) : (0); }));
    }
    SLOP_UNREACHABLE();
}

slop_list_int howl_decode_typed_ids_in_order(slop_arena* arena, howl_termstore_Encoded doc, slop_string type_iri) {
    {
        __auto_type type_pred = doc.dict.rdf_type;
        __auto_type type_id = howl_decode_vocab_id(arena, doc.dict, type_iri);
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = doc.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if ((it.p == type_pred) && (it.o == type_id)) {
                    if (!(slop_map_has(seen, &(int64_t){it.s}))) {
                        (void)(({ slop_map_put(NULL, seen, &(int64_t){it.s}, NULL, 0); }));
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (it.s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

uint8_t howl_decode_logical_predicate(slop_string pv) {
    if (howl_canon_string_cmp(pv, slop_rdf_vocab_RDFS_SUBCLASS_OF) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_EQUIVALENT_CLASS) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_DISJOINT_WITH) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_RDFS_SUBPROPERTY_OF) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_EQUIVALENT_PROPERTY) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_PROPERTY_DISJOINT_WITH) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_PROPERTY_CHAIN_AXIOM) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_INVERSE_OF) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_RDFS_DOMAIN) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_RDFS_RANGE) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_SAME_AS) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_DIFFERENT_FROM) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_HAS_KEY) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_INTERSECTION_OF) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_UNION_OF) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_COMPLEMENT_OF) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_ONE_OF) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_SOME_VALUES_FROM) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_ALL_VALUES_FROM) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_HAS_VALUE) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_HAS_SELF) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_ON_PROPERTY) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_MEMBERS) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_DISTINCT_MEMBERS) == 0) {
        return 1;
    } else {
        return 0;
    }
}

slop_rdf_rdf_Triple howl_decode_ex_hdr(slop_string p, slop_string o) {
    return ((slop_rdf_rdf_Triple){.subject = ((slop_rdf_rdf_Term){ .tag = slop_rdf_rdf_Term_term_blank, .data.term_blank = ((slop_rdf_rdf_BlankNode){.id = 7}) }), .predicate = ((slop_rdf_rdf_Term){ .tag = slop_rdf_rdf_Term_term_iri, .data.term_iri = ((slop_rdf_rdf_IRI){.value = p}) }), .object = ((slop_rdf_rdf_Term){ .tag = slop_rdf_rdf_Term_term_iri, .data.term_iri = ((slop_rdf_rdf_IRI){.value = o}) })});
}

uint8_t howl_decode_header_consumable(slop_rdf_rdf_Triple t) {
    __auto_type _mv_840 = howl_decode_term_iri_value(t.predicate);
    if (!_mv_840.has_value) {
        return 0;
    } else if (_mv_840.has_value) {
        __auto_type p = _mv_840.value;
        if (howl_canon_string_cmp(p.value, slop_rdf_vocab_RDF_TYPE) == 0) {
            __auto_type _mv_841 = howl_decode_term_iri_value(t.object);
            if (!_mv_841.has_value) {
                return 0;
            } else if (_mv_841.has_value) {
                __auto_type o = _mv_841.value;
                if (howl_canon_string_cmp(o.value, slop_rdf_vocab_OWL_ONTOLOGY) == 0) {
                    return 1;
                } else if (howl_canon_string_cmp(o.value, slop_rdf_vocab_OWL_AXIOM) == 0) {
                    return 1;
                } else if (howl_canon_string_cmp(o.value, slop_rdf_vocab_OWL_ANNOTATION) == 0) {
                    return 1;
                } else {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else {
            return !(howl_decode_logical_predicate(p.value));
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_decode_Stage0_howl_types_Fault howl_decode_stage0_header(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved) {
    return howl_decode_stage0_encoded(arena, howl_termstore_encode_triples(arena, triples), imports_resolved);
}

slop_result_howl_decode_Stage0_howl_types_Fault howl_decode_stage0_encoded(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type res = howl_decode_stage0_scan(arena, scratch, doc, imports_resolved);
        (void)(({ slop_arena_free(scratch); free(scratch); }));
        return res;
    }
}

slop_map* howl_decode_id_set(slop_arena* arena, slop_list_int a, slop_list_int b, slop_list_int c) {
    {
        __auto_type s = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ slop_map_put(NULL, s, &(int64_t){x}, NULL, 0); }));
            }
        }
        {
            __auto_type _coll = b;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ slop_map_put(NULL, s, &(int64_t){x}, NULL, 0); }));
            }
        }
        {
            __auto_type _coll = c;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ slop_map_put(NULL, s, &(int64_t){x}, NULL, 0); }));
            }
        }
        return s;
    }
}

howl_termstore_TermStore howl_decode_annotated_store(slop_arena* arena, howl_termstore_Encoded doc) {
    {
        __auto_type st = howl_termstore_store_over(arena, doc.dict);
        __auto_type src = howl_decode_vocab_id(arena, doc.dict, slop_rdf_vocab_OWL_ANNOTATED_SOURCE);
        __auto_type prop = howl_decode_vocab_id(arena, doc.dict, slop_rdf_vocab_OWL_ANNOTATED_PROPERTY);
        __auto_type tgt = howl_decode_vocab_id(arena, doc.dict, slop_rdf_vocab_OWL_ANNOTATED_TARGET);
        {
            __auto_type _coll = doc.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (((it.p == src)) || ((it.p == prop)) || ((it.p == tgt))) {
                    howl_termstore_store_insert_ids(arena, st, it);
                }
            }
        }
        return st;
    }
}

int64_t howl_decode_term_id(howl_termstore_TermStore st, slop_rdf_rdf_Term t) {
    __auto_type _mv_845 = howl_termstore_lookup_term(st, t);
    if (_mv_845.has_value) {
        __auto_type i = _mv_845.value;
        return i;
    } else if (!_mv_845.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_termstore_IdTriple_string howl_decode_rebuild_one(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Term a, slop_rdf_rdf_Term src_pred, slop_rdf_rdf_Term prop_pred, slop_rdf_rdf_Term tgt_pred) {
    __auto_type _mv_846 = howl_decode_one_object(arena, st, a, src_pred);
    if (!_mv_846.is_ok) {
        __auto_type _ = _mv_846.data.err;
        return ((slop_result_howl_termstore_IdTriple_string){ .is_ok = false, .data.err = SLOP_STR("owl:Axiom node without a usable owl:annotatedSource") });
    } else if (_mv_846.is_ok) {
        __auto_type subj = _mv_846.data.ok;
        __auto_type _mv_847 = howl_decode_one_object(arena, st, a, prop_pred);
        if (!_mv_847.is_ok) {
            __auto_type _ = _mv_847.data.err;
            return ((slop_result_howl_termstore_IdTriple_string){ .is_ok = false, .data.err = SLOP_STR("owl:Axiom node without a usable owl:annotatedProperty") });
        } else if (_mv_847.is_ok) {
            __auto_type pred = _mv_847.data.ok;
            __auto_type _mv_848 = howl_decode_one_object(arena, st, a, tgt_pred);
            if (!_mv_848.is_ok) {
                __auto_type _ = _mv_848.data.err;
                return ((slop_result_howl_termstore_IdTriple_string){ .is_ok = false, .data.err = SLOP_STR("owl:Axiom node without a usable owl:annotatedTarget") });
            } else if (_mv_848.is_ok) {
                __auto_type obj = _mv_848.data.ok;
                return ((slop_result_howl_termstore_IdTriple_string){ .is_ok = true, .data.ok = ((howl_termstore_IdTriple){.s = howl_decode_term_id(st, subj), .p = howl_decode_term_id(st, pred), .o = howl_decode_term_id(st, obj)}) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

howl_decode_Rebuilt howl_decode_rebuild_candidates(slop_arena* arena, howl_termstore_TermStore st, slop_list_int ax_subjs) {
    {
        __auto_type src_pred = rdf_make_iri(arena, slop_rdf_vocab_OWL_ANNOTATED_SOURCE);
        __auto_type prop_pred = rdf_make_iri(arena, slop_rdf_vocab_OWL_ANNOTATED_PROPERTY);
        __auto_type tgt_pred = rdf_make_iri(arena, slop_rdf_vocab_OWL_ANNOTATED_TARGET);
        __auto_type out = ((slop_list_howl_termstore_IdTriple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        slop_option_string fault = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = ax_subjs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ai = _coll.data[_i];
                __auto_type _mv_849 = howl_decode_rebuild_one(arena, st, howl_termstore_term_of(st, ai), src_pred, prop_pred, tgt_pred);
                if (!_mv_849.is_ok) {
                    __auto_type m = _mv_849.data.err;
                    fault = (slop_option_string){.has_value = 1, .value = m};
                } else if (_mv_849.is_ok) {
                    __auto_type t = _mv_849.data.ok;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return ((howl_decode_Rebuilt){.triples = out, .fault = fault});
    }
}

slop_map* howl_decode_asserted_among(slop_arena* arena, slop_list_howl_termstore_IdTriple candidates, howl_termstore_Encoded doc) {
    {
        __auto_type cands = ({ static const slop_map_desc _d = SLOP_SET_DESC(howl_termstore_IdTriple, slop_hash_howl_termstore_IdTriple, slop_eq_howl_termstore_IdTriple, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type found = ({ static const slop_map_desc _d = SLOP_SET_DESC(howl_termstore_IdTriple, slop_hash_howl_termstore_IdTriple, slop_eq_howl_termstore_IdTriple, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = candidates;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ slop_map_put(NULL, cands, &(c), NULL, 0); }));
            }
        }
        {
            __auto_type _coll = doc.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (slop_map_has(cands, &(it))) {
                    (void)(({ slop_map_put(NULL, found, &(it), NULL, 0); }));
                }
            }
        }
        return found;
    }
}

slop_result_howl_decode_Stage0_howl_types_Fault howl_decode_stage0_scan(slop_arena* arena, slop_arena* scratch, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved) {
    {
        __auto_type ont_subjs = howl_decode_typed_ids_in_order(scratch, doc, slop_rdf_vocab_OWL_ONTOLOGY);
        __auto_type ax_subjs = howl_decode_typed_ids_in_order(scratch, doc, slop_rdf_vocab_OWL_AXIOM);
        __auto_type ann_subjs = howl_decode_typed_ids_in_order(scratch, doc, slop_rdf_vocab_OWL_ANNOTATION);
        __auto_type declared = howl_decode_collect_imports(arena, doc);
        __auto_type dict = doc.dict;
        __auto_type out = ((slop_list_howl_termstore_IdTriple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        slop_option_slop_rdf_rdf_IRI ont = (slop_option_slop_rdf_rdf_IRI){.has_value = false};
        slop_option_string fault = (slop_option_string){.has_value = false};
        {
            __auto_type header = howl_decode_id_set(scratch, ont_subjs, ax_subjs, ann_subjs);
            {
                __auto_type _coll = doc.triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type it = _coll.data[_i];
                    if (!(slop_map_has(header, &(int64_t){it.s})) || !(howl_decode_header_consumable(howl_termstore_triple_of(dict, it)))) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (it); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        {
            __auto_type rb = howl_decode_rebuild_candidates(scratch, howl_decode_annotated_store(scratch, doc), ax_subjs);
            __auto_type asserted = howl_decode_asserted_among(scratch, rb.triples, doc);
            {
                __auto_type _coll = rb.triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    if (!(slop_map_has(asserted, &(c)))) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
            fault = rb.fault;
        }
        {
            __auto_type _coll = ont_subjs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                __auto_type _mv_855 = howl_decode_term_iri_value(howl_termstore_term_of(dict, o));
                if (_mv_855.has_value) {
                    __auto_type i = _mv_855.value;
                    ont = (slop_option_slop_rdf_rdf_IRI){.has_value = 1, .value = i};
                } else if (!_mv_855.has_value) {
                }
            }
        }
        __auto_type _mv_856 = fault;
        if (_mv_856.has_value) {
            __auto_type msg = _mv_856.value;
            return ((slop_result_howl_decode_Stage0_howl_types_Fault){ .is_ok = false, .data.err = ((howl_types_Fault){ .tag = howl_types_Fault_input_error, .data.input_error = msg }) });
        } else if (!_mv_856.has_value) {
            return ((slop_result_howl_decode_Stage0_howl_types_Fault){ .is_ok = true, .data.ok = ((howl_decode_Stage0){.dict = dict, .triples = out, .imports_declared = declared, .omissions = howl_decode_unresolved_imports(arena, declared, imports_resolved), .ontology_iri = ont}) });
        }
        SLOP_UNREACHABLE();
    }
}

howl_owl2_RawConcept* howl_decode_box_concept(slop_arena* arena, howl_owl2_RawConcept c) {
    {
        __auto_type p = ((howl_owl2_RawConcept*)(({ __auto_type _alloc = (howl_owl2_RawConcept*)slop_arena_alloc(arena, sizeof(howl_owl2_RawConcept)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = c;
        return p;
    }
}

slop_string howl_decode_list_fault_message(howl_decode_ListFault f) {
    __auto_type _mv_857 = f;
    switch (_mv_857.tag) {
        case howl_decode_ListFault_list_truncated:
        {
            __auto_type m = _mv_857.data.list_truncated;
            return m;
        }
        case howl_decode_ListFault_list_branching:
        {
            __auto_type m = _mv_857.data.list_branching;
            return m;
        }
        case howl_decode_ListFault_list_cyclic:
        {
            __auto_type m = _mv_857.data.list_cyclic;
            return m;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_decode_has_pred(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term s, slop_string pred_iri) {
    return howl_termstore_store_has_any(g, s, rdf_make_iri(arena, pred_iri));
}

slop_result_slop_rdf_rdf_Term_howl_decode_LookupFault howl_decode_obj_of(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term s, slop_string pred_iri) {
    return howl_decode_one_object(arena, g, s, rdf_make_iri(arena, pred_iri));
}

slop_result_howl_types_RoleId_string howl_decode_decode_role(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b) {
    __auto_type _mv_858 = howl_decode_obj_of(arena, g, b, slop_rdf_vocab_OWL_ON_PROPERTY);
    if (!_mv_858.is_ok) {
        __auto_type _ = _mv_858.data.err;
        return ((slop_result_howl_types_RoleId_string){ .is_ok = false, .data.err = SLOP_STR("restriction without exactly one owl:onProperty") });
    } else if (_mv_858.is_ok) {
        __auto_type pt = _mv_858.data.ok;
        __auto_type _mv_859 = howl_decode_property_expression(arena, g, pt);
        if (_mv_859.has_value) {
            __auto_type r = _mv_859.value;
            return ((slop_result_howl_types_RoleId_string){ .is_ok = true, .data.ok = r });
        } else if (!_mv_859.has_value) {
            return ((slop_result_howl_types_RoleId_string){ .is_ok = false, .data.err = SLOP_STR("owl:onProperty is a blank node that is not an inverse property expression") });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_option_howl_types_RoleId howl_decode_property_expression(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term t) {
    __auto_type _mv_860 = howl_decode_term_iri_value(t);
    if (_mv_860.has_value) {
        __auto_type i = _mv_860.value;
        return (slop_option_howl_types_RoleId){.has_value = 1, .value = ((howl_types_RoleId){ .tag = howl_types_RoleId_named_role, .data.named_role = i })};
    } else if (!_mv_860.has_value) {
        __auto_type _mv_861 = t;
        switch (_mv_861.tag) {
            case slop_rdf_rdf_Term_term_blank:
            {
                __auto_type _ = _mv_861.data.term_blank;
                __auto_type _mv_862 = howl_decode_obj_of(arena, g, t, slop_rdf_vocab_OWL_INVERSE_OF);
                if (_mv_862.is_ok) {
                    __auto_type pt = _mv_862.data.ok;
                    __auto_type _mv_863 = howl_decode_term_iri_value(pt);
                    if (_mv_863.has_value) {
                        __auto_type i = _mv_863.value;
                        return (slop_option_howl_types_RoleId){.has_value = 1, .value = ((howl_types_RoleId){ .tag = howl_types_RoleId_inverse_role, .data.inverse_role = i })};
                    } else if (!_mv_863.has_value) {
                        return (slop_option_howl_types_RoleId){.has_value = false};
                    }
                    SLOP_UNREACHABLE();
                } else if (!_mv_862.is_ok) {
                    __auto_type _ = _mv_862.data.err;
                    return (slop_option_howl_types_RoleId){.has_value = false};
                }
                SLOP_UNREACHABLE();
            }
            default: {
                return (slop_option_howl_types_RoleId){.has_value = false};
            }
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_decode_malformed_inverse(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t) {
    return (howl_decode_is_pred(t, slop_rdf_vocab_OWL_INVERSE_OF) && ({ __auto_type _mv = t.subject; uint8_t _mr = {0}; switch (_mv.tag) { case slop_rdf_rdf_Term_term_blank: { _mr = ({ __auto_type _mv = howl_decode_property_expression(arena, g, t.subject); _mv.has_value ? ({ __auto_type _ = _mv.value; 0; }) : (1); }); break; } default: { _mr = 0; break; }  } _mr; }));
}

uint8_t howl_decode_data_property_term(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term t) {
    __auto_type _mv_864 = howl_decode_term_iri_value(t);
    if (!_mv_864.has_value) {
        return 0;
    } else if (_mv_864.has_value) {
        __auto_type i = _mv_864.value;
        return (((howl_canon_string_cmp(i.value, slop_rdf_vocab_OWL_TOP_DATA_PROPERTY) == 0)) || ((howl_canon_string_cmp(i.value, slop_rdf_vocab_OWL_BOTTOM_DATA_PROPERTY) == 0)) || (howl_termstore_store_contains(g, ((slop_rdf_rdf_Triple){.subject = t, .predicate = rdf_make_iri(arena, slop_rdf_vocab_RDF_TYPE), .object = rdf_make_iri(arena, slop_rdf_vocab_OWL_DATATYPE_PROPERTY)}))));
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_decode_restriction_on_data(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b) {
    __auto_type _mv_865 = howl_decode_obj_of(arena, g, b, slop_rdf_vocab_OWL_ON_PROPERTY);
    if (_mv_865.is_ok) {
        __auto_type pt = _mv_865.data.ok;
        return howl_decode_data_property_term(arena, g, pt);
    } else if (!_mv_865.is_ok) {
        __auto_type _ = _mv_865.data.err;
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string howl_decode_data_restriction_pred(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b) {
    if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_SOME_VALUES_FROM)) {
        return slop_rdf_vocab_OWL_SOME_VALUES_FROM;
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_ALL_VALUES_FROM)) {
        return slop_rdf_vocab_OWL_ALL_VALUES_FROM;
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_HAS_VALUE)) {
        return slop_rdf_vocab_OWL_HAS_VALUE;
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_HAS_SELF)) {
        return slop_rdf_vocab_OWL_HAS_SELF;
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_QUALIFIED_CARDINALITY)) {
        return slop_rdf_vocab_OWL_QUALIFIED_CARDINALITY;
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_MIN_QUALIFIED_CARDINALITY)) {
        return slop_rdf_vocab_OWL_MIN_QUALIFIED_CARDINALITY;
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_MAX_QUALIFIED_CARDINALITY)) {
        return slop_rdf_vocab_OWL_MAX_QUALIFIED_CARDINALITY;
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_CARDINALITY)) {
        return slop_rdf_vocab_OWL_CARDINALITY;
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_MIN_CARDINALITY)) {
        return slop_rdf_vocab_OWL_MIN_CARDINALITY;
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_MAX_CARDINALITY)) {
        return slop_rdf_vocab_OWL_MAX_CARDINALITY;
    } else {
        return SLOP_STR("");
    }
}

slop_string howl_decode_data_restriction_name(slop_string pred) {
    if (howl_canon_string_cmp(pred, slop_rdf_vocab_OWL_SOME_VALUES_FROM) == 0) {
        return SLOP_STR("DataSomeValuesFrom");
    } else if (howl_canon_string_cmp(pred, slop_rdf_vocab_OWL_ALL_VALUES_FROM) == 0) {
        return SLOP_STR("DataAllValuesFrom");
    } else if (howl_canon_string_cmp(pred, slop_rdf_vocab_OWL_HAS_VALUE) == 0) {
        return SLOP_STR("DataHasValue");
    } else if (howl_canon_string_cmp(pred, slop_rdf_vocab_OWL_HAS_SELF) == 0) {
        return SLOP_STR("ObjectHasSelf on a data property");
    } else if (howl_canon_string_cmp(pred, slop_rdf_vocab_OWL_QUALIFIED_CARDINALITY) == 0) {
        return SLOP_STR("DataExactCardinality");
    } else if (howl_canon_string_cmp(pred, slop_rdf_vocab_OWL_MIN_QUALIFIED_CARDINALITY) == 0) {
        return SLOP_STR("DataMinCardinality");
    } else if (howl_canon_string_cmp(pred, slop_rdf_vocab_OWL_MAX_QUALIFIED_CARDINALITY) == 0) {
        return SLOP_STR("DataMaxCardinality");
    } else if (howl_canon_string_cmp(pred, slop_rdf_vocab_OWL_CARDINALITY) == 0) {
        return SLOP_STR("DataExactCardinality");
    } else if (howl_canon_string_cmp(pred, slop_rdf_vocab_OWL_MIN_CARDINALITY) == 0) {
        return SLOP_STR("DataMinCardinality");
    } else if (howl_canon_string_cmp(pred, slop_rdf_vocab_OWL_MAX_CARDINALITY) == 0) {
        return SLOP_STR("DataMaxCardinality");
    } else {
        return SLOP_STR("a restriction on a data property");
    }
}

slop_string howl_decode_filler_text(slop_arena* arena, slop_rdf_rdf_Term t) {
    __auto_type _mv_866 = t;
    switch (_mv_866.tag) {
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type i = _mv_866.data.term_iri;
            return i.value;
        }
        case slop_rdf_rdf_Term_term_blank:
        {
            __auto_type _ = _mv_866.data.term_blank;
            return SLOP_STR("_");
        }
        default: {
            return howl_decode_render_term(arena, t);
        }
    }
}

slop_string howl_decode_terms_text(slop_arena* arena, slop_list_slop_rdf_rdf_Term terms) {
    {
        __auto_type out = SLOP_STR("");
        uint8_t first = 1;
        {
            __auto_type _coll = terms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type tm = _coll.data[_i];
                if (!(first)) {
                    out = string_concat(arena, out, SLOP_STR(" "));
                }
                out = string_concat(arena, out, howl_decode_filler_text(arena, tm));
                first = 0;
            }
        }
        return out;
    }
}

slop_string howl_decode_on_properties_text(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b) {
    __auto_type _mv_867 = howl_decode_obj_of(arena, g, b, slop_rdf_vocab_OWL_ON_PROPERTIES);
    if (!_mv_867.is_ok) {
        __auto_type _ = _mv_867.data.err;
        return SLOP_STR("?");
    } else if (_mv_867.is_ok) {
        __auto_type ht = _mv_867.data.ok;
        __auto_type _mv_868 = howl_decode_rdf_list_checked(arena, g, ht);
        if (!_mv_868.is_ok) {
            __auto_type _ = _mv_868.data.err;
            return SLOP_STR("?");
        } else if (_mv_868.is_ok) {
            __auto_type terms = _mv_868.data.ok;
            return howl_decode_terms_text(arena, terms);
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_string howl_decode_nary_text(slop_arena* arena, slop_string name, slop_string props, slop_string fill) {
    return string_concat(arena, name, string_concat(arena, SLOP_STR("(onProperties("), string_concat(arena, props, string_concat(arena, SLOP_STR(") "), string_concat(arena, fill, SLOP_STR(")"))))));
}

howl_owl2_RawConcept howl_decode_nary_data_restriction(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b) {
    {
        __auto_type pred = howl_decode_data_restriction_pred(arena, g, b);
        __auto_type props = howl_decode_on_properties_text(arena, g, b);
        __auto_type fill = (((string_len(pred) == 0)) ? SLOP_STR("") : ({ __auto_type _mv = howl_decode_obj_of(arena, g, b, pred); slop_string _mr; if (_mv.is_ok) { __auto_type ft = _mv.data.ok; _mr = howl_decode_filler_text(arena, ft); } else { __auto_type _ = _mv.data.err; _mr = SLOP_STR("?"); } _mr; }));
        return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_data, .data.rc_data = ((howl_types_InputRef){ .tag = howl_types_InputRef_rdf_fragment, .data.rdf_fragment = howl_decode_nary_text(arena, howl_decode_data_restriction_name(pred), props, fill) }) });
    }
}

howl_owl2_RawConcept howl_decode_data_restriction(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b) {
    {
        __auto_type pred = howl_decode_data_restriction_pred(arena, g, b);
        __auto_type prop = ({ __auto_type _mv = howl_decode_obj_of(arena, g, b, slop_rdf_vocab_OWL_ON_PROPERTY); slop_string _mr; if (_mv.is_ok) { __auto_type pt = _mv.data.ok; _mr = howl_decode_filler_text(arena, pt); } else { __auto_type _ = _mv.data.err; _mr = SLOP_STR("?"); } _mr; });
        __auto_type fill = (((string_len(pred) == 0)) ? SLOP_STR("") : ({ __auto_type _mv = howl_decode_obj_of(arena, g, b, pred); slop_string _mr; if (_mv.is_ok) { __auto_type ft = _mv.data.ok; _mr = howl_decode_filler_text(arena, ft); } else { __auto_type _ = _mv.data.err; _mr = SLOP_STR("?"); } _mr; }));
        return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_data, .data.rc_data = ((howl_types_InputRef){ .tag = howl_types_InputRef_rdf_fragment, .data.rdf_fragment = string_concat(arena, howl_decode_data_restriction_name(pred), string_concat(arena, SLOP_STR("("), string_concat(arena, prop, string_concat(arena, SLOP_STR(" "), string_concat(arena, fill, SLOP_STR(")")))))) }) });
    }
}

slop_result_int_string howl_decode_literal_count(slop_rdf_rdf_Term t) {
    __auto_type _mv_869 = t;
    switch (_mv_869.tag) {
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type l = _mv_869.data.term_literal;
            __auto_type _mv_870 = std_strlib_parse_int(l.value);
            if (_mv_870.is_ok) {
                __auto_type v = _mv_870.data.ok;
                if (((int64_t)(v)) < 0) {
                    return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality literal is negative") });
                } else {
                    return ((slop_result_int_string){ .is_ok = true, .data.ok = ((int64_t)(v)) });
                }
            } else if (!_mv_870.is_ok) {
                __auto_type _ = _mv_870.data.err;
                return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality is not an integer literal") });
            }
            SLOP_UNREACHABLE();
        }
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type _ = _mv_869.data.term_iri;
            return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality is an IRI, not a literal") });
        }
        case slop_rdf_rdf_Term_term_blank:
        {
            __auto_type _ = _mv_869.data.term_blank;
            return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality is a blank node, not a literal") });
        }
        case slop_rdf_rdf_Term_term_triple:
        {
            __auto_type _ = _mv_869.data.term_triple;
            return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality is a triple term, not a literal") });
        }
    }
    SLOP_UNREACHABLE();
}

howl_decode_IndividualTerm howl_decode_individual_term(slop_rdf_rdf_Term tm) {
    __auto_type _mv_871 = tm;
    switch (_mv_871.tag) {
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type i = _mv_871.data.term_iri;
            if (howl_decode_is_reserved_iri(i.value)) {
                return ((howl_decode_IndividualTerm){ .tag = howl_decode_IndividualTerm_reserved_individual });
            } else {
                return ((howl_decode_IndividualTerm){ .tag = howl_decode_IndividualTerm_named_individual, .data.named_individual = i });
            }
        }
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type _ = _mv_871.data.term_literal;
            return ((howl_decode_IndividualTerm){ .tag = howl_decode_IndividualTerm_literal_individual });
        }
        default: {
            return ((howl_decode_IndividualTerm){ .tag = howl_decode_IndividualTerm_anonymous_individual });
        }
    }
}

slop_result_howl_decode_NodeList_string howl_decode_decode_node_list(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term head) {
    __auto_type _mv_872 = howl_decode_rdf_list_checked(arena, g, head);
    if (!_mv_872.is_ok) {
        __auto_type lf = _mv_872.data.err;
        return ((slop_result_howl_decode_NodeList_string){ .is_ok = false, .data.err = howl_decode_list_fault_message(lf) });
    } else if (_mv_872.is_ok) {
        __auto_type terms = _mv_872.data.ok;
        {
            __auto_type out = ((slop_list_howl_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            uint8_t literal = 0;
            uint8_t anonymous = 0;
            uint8_t reserved = 0;
            {
                __auto_type _coll = terms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tm = _coll.data[_i];
                    __auto_type _mv_873 = howl_decode_individual_term(tm);
                    switch (_mv_873.tag) {
                        case howl_decode_IndividualTerm_named_individual:
                        {
                            __auto_type i = _mv_873.data.named_individual;
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = i })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        case howl_decode_IndividualTerm_literal_individual:
                        {
                            literal = 1;
                            break;
                        }
                        case howl_decode_IndividualTerm_anonymous_individual:
                        {
                            anonymous = 1;
                            break;
                        }
                        case howl_decode_IndividualTerm_reserved_individual:
                        {
                            reserved = 1;
                            break;
                        }
                    }
                }
            }
            if (literal) {
                return ((slop_result_howl_decode_NodeList_string){ .is_ok = true, .data.ok = ((howl_decode_NodeList){ .tag = howl_decode_NodeList_has_literal }) });
            } else if (anonymous) {
                return ((slop_result_howl_decode_NodeList_string){ .is_ok = true, .data.ok = ((howl_decode_NodeList){ .tag = howl_decode_NodeList_has_anonymous }) });
            } else if (reserved) {
                return ((slop_result_howl_decode_NodeList_string){ .is_ok = true, .data.ok = ((howl_decode_NodeList){ .tag = howl_decode_NodeList_has_reserved }) });
            } else {
                return ((slop_result_howl_decode_NodeList_string){ .is_ok = true, .data.ok = ((howl_decode_NodeList){ .tag = howl_decode_NodeList_all_named, .data.all_named = out }) });
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_list_howl_owl2_RawConcept_string howl_decode_decode_concept_list(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term head, int64_t fuel) {
    __auto_type _mv_874 = howl_decode_rdf_list_checked(arena, g, head);
    if (!_mv_874.is_ok) {
        __auto_type lf = _mv_874.data.err;
        return ((slop_result_list_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = howl_decode_list_fault_message(lf) });
    } else if (_mv_874.is_ok) {
        __auto_type terms = _mv_874.data.ok;
        {
            __auto_type out = ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            slop_option_string fault = (slop_option_string){.has_value = false};
            {
                __auto_type _coll = terms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tm = _coll.data[_i];
                    __auto_type _mv_875 = howl_decode_decode_concept(arena, g, tm, (fuel - 1));
                    if (!_mv_875.is_ok) {
                        __auto_type m = _mv_875.data.err;
                        fault = (slop_option_string){.has_value = 1, .value = m};
                    } else if (_mv_875.is_ok) {
                        __auto_type c = _mv_875.data.ok;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
            __auto_type _mv_876 = fault;
            if (_mv_876.has_value) {
                __auto_type m = _mv_876.value;
                return ((slop_result_list_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (!_mv_876.has_value) {
                return ((slop_result_list_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = out });
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawConcept_string howl_decode_decode_quantified(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b, slop_string filler_pred, uint8_t universal, int64_t fuel) {
    __auto_type _mv_877 = howl_decode_decode_role(arena, g, b);
    if (!_mv_877.is_ok) {
        __auto_type m = _mv_877.data.err;
        return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
    } else if (_mv_877.is_ok) {
        __auto_type r = _mv_877.data.ok;
        __auto_type _mv_878 = howl_decode_obj_of(arena, g, b, filler_pred);
        if (!_mv_878.is_ok) {
            __auto_type _ = _mv_878.data.err;
            return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("quantified restriction without exactly one filler") });
        } else if (_mv_878.is_ok) {
            __auto_type ft = _mv_878.data.ok;
            __auto_type _mv_879 = howl_decode_decode_concept(arena, g, ft, (fuel - 1));
            if (!_mv_879.is_ok) {
                __auto_type m = _mv_879.data.err;
                return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_879.is_ok) {
                __auto_type c = _mv_879.data.ok;
                if (universal) {
                    return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_all, .data.rc_all = { .f0 = r, .f1 = howl_decode_box_concept(arena, c) } }) });
                } else {
                    return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_some, .data.rc_some = { .f0 = r, .f1 = howl_decode_box_concept(arena, c) } }) });
                }
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_int_string howl_decode_cardinality_count(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b, slop_string count_pred) {
    __auto_type _mv_880 = howl_decode_obj_of(arena, g, b, count_pred);
    if (!_mv_880.is_ok) {
        __auto_type _ = _mv_880.data.err;
        return ((slop_result_int_string){ .is_ok = false, .data.err = SLOP_STR("cardinality restriction without exactly one count") });
    } else if (_mv_880.is_ok) {
        __auto_type ct = _mv_880.data.ok;
        return howl_decode_literal_count(ct);
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawConcept_string howl_decode_qualified_cardinality(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b, howl_owl2_CardKind kind, howl_types_RoleId r, int64_t n, int64_t fuel) {
    __auto_type _mv_881 = howl_decode_obj_of(arena, g, b, slop_rdf_vocab_OWL_ON_CLASS);
    if (!_mv_881.is_ok) {
        __auto_type _ = _mv_881.data.err;
        return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("qualified cardinality without exactly one owl:onClass") });
    } else if (_mv_881.is_ok) {
        __auto_type qt = _mv_881.data.ok;
        __auto_type _mv_882 = howl_decode_decode_concept(arena, g, qt, (fuel - 1));
        if (!_mv_882.is_ok) {
            __auto_type m = _mv_882.data.err;
            return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
        } else if (_mv_882.is_ok) {
            __auto_type qc = _mv_882.data.ok;
            return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_qcard, .data.rc_qcard = { .f0 = kind, .f1 = r, .f2 = n, .f3 = howl_decode_box_concept(arena, qc) } }) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawConcept_string howl_decode_decode_cardinality(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b, howl_owl2_CardKind kind, slop_string count_pred, uint8_t qualified, int64_t fuel) {
    __auto_type _mv_883 = howl_decode_decode_role(arena, g, b);
    if (!_mv_883.is_ok) {
        __auto_type m = _mv_883.data.err;
        return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
    } else if (_mv_883.is_ok) {
        __auto_type r = _mv_883.data.ok;
        __auto_type _mv_884 = howl_decode_cardinality_count(arena, g, b, count_pred);
        if (!_mv_884.is_ok) {
            __auto_type m = _mv_884.data.err;
            return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
        } else if (_mv_884.is_ok) {
            __auto_type n = _mv_884.data.ok;
            if (!(qualified)) {
                return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_card, .data.rc_card = { .f0 = kind, .f1 = r, .f2 = n } }) });
            } else {
                return howl_decode_qualified_cardinality(arena, g, b, kind, r, n, fuel);
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawConcept_string howl_decode_decode_anon(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b, int64_t fuel) {
    if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_ON_PROPERTIES)) {
        return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = howl_decode_nary_data_restriction(arena, g, b) });
    } else if (howl_decode_restriction_on_data(arena, g, b) || howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_ON_DATA_RANGE)) {
        return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = howl_decode_data_restriction(arena, g, b) });
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_INTERSECTION_OF)) {
        __auto_type _mv_885 = howl_decode_obj_of(arena, g, b, slop_rdf_vocab_OWL_INTERSECTION_OF);
        if (!_mv_885.is_ok) {
            __auto_type _ = _mv_885.data.err;
            return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:intersectionOf is absent or ambiguous") });
        } else if (_mv_885.is_ok) {
            __auto_type head = _mv_885.data.ok;
            __auto_type _mv_886 = howl_decode_decode_concept_list(arena, g, head, fuel);
            if (!_mv_886.is_ok) {
                __auto_type m = _mv_886.data.err;
                return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_886.is_ok) {
                __auto_type cs = _mv_886.data.ok;
                return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_and, .data.rc_and = cs }) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_UNION_OF)) {
        __auto_type _mv_887 = howl_decode_obj_of(arena, g, b, slop_rdf_vocab_OWL_UNION_OF);
        if (!_mv_887.is_ok) {
            __auto_type _ = _mv_887.data.err;
            return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:unionOf is absent or ambiguous") });
        } else if (_mv_887.is_ok) {
            __auto_type head = _mv_887.data.ok;
            __auto_type _mv_888 = howl_decode_decode_concept_list(arena, g, head, fuel);
            if (!_mv_888.is_ok) {
                __auto_type m = _mv_888.data.err;
                return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_888.is_ok) {
                __auto_type cs = _mv_888.data.ok;
                return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_or, .data.rc_or = cs }) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_ONE_OF)) {
        __auto_type _mv_889 = howl_decode_obj_of(arena, g, b, slop_rdf_vocab_OWL_ONE_OF);
        if (!_mv_889.is_ok) {
            __auto_type _ = _mv_889.data.err;
            return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:oneOf is absent or ambiguous") });
        } else if (_mv_889.is_ok) {
            __auto_type head = _mv_889.data.ok;
            __auto_type _mv_890 = howl_decode_decode_node_list(arena, g, head);
            if (!_mv_890.is_ok) {
                __auto_type m = _mv_890.data.err;
                return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_890.is_ok) {
                __auto_type nl = _mv_890.data.ok;
                __auto_type _mv_891 = nl;
                switch (_mv_891.tag) {
                    case howl_decode_NodeList_all_named:
                    {
                        __auto_type ns = _mv_891.data.all_named;
                        return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_oneof, .data.rc_oneof = ns }) });
                    }
                    case howl_decode_NodeList_has_literal:
                    {
                        return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_data, .data.rc_data = ((howl_types_InputRef){ .tag = howl_types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("owl:oneOf with a literal (DataOneOf)") }) }) });
                    }
                    case howl_decode_NodeList_has_anonymous:
                    {
                        return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_anon, .data.rc_anon = ((howl_types_InputRef){ .tag = howl_types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("owl:oneOf with an anonymous individual") }) }) });
                    }
                    case howl_decode_NodeList_has_reserved:
                    {
                        return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_anon, .data.rc_anon = ((howl_types_InputRef){ .tag = howl_types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("owl:oneOf with a reserved IRI as an individual") }) }) });
                    }
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_COMPLEMENT_OF)) {
        __auto_type _mv_892 = howl_decode_obj_of(arena, g, b, slop_rdf_vocab_OWL_COMPLEMENT_OF);
        if (!_mv_892.is_ok) {
            __auto_type _ = _mv_892.data.err;
            return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:complementOf is absent or ambiguous") });
        } else if (_mv_892.is_ok) {
            __auto_type ct = _mv_892.data.ok;
            __auto_type _mv_893 = howl_decode_decode_concept(arena, g, ct, (fuel - 1));
            if (!_mv_893.is_ok) {
                __auto_type m = _mv_893.data.err;
                return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
            } else if (_mv_893.is_ok) {
                __auto_type c = _mv_893.data.ok;
                return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_not, .data.rc_not = howl_decode_box_concept(arena, c) }) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_SOME_VALUES_FROM)) {
        return howl_decode_decode_quantified(arena, g, b, slop_rdf_vocab_OWL_SOME_VALUES_FROM, 0, fuel);
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_ALL_VALUES_FROM)) {
        return howl_decode_decode_quantified(arena, g, b, slop_rdf_vocab_OWL_ALL_VALUES_FROM, 1, fuel);
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_HAS_VALUE)) {
        __auto_type _mv_894 = howl_decode_decode_role(arena, g, b);
        if (!_mv_894.is_ok) {
            __auto_type m = _mv_894.data.err;
            return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
        } else if (_mv_894.is_ok) {
            __auto_type r = _mv_894.data.ok;
            __auto_type _mv_895 = howl_decode_obj_of(arena, g, b, slop_rdf_vocab_OWL_HAS_VALUE);
            if (!_mv_895.is_ok) {
                __auto_type _ = _mv_895.data.err;
                return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("owl:hasValue is absent or ambiguous") });
            } else if (_mv_895.is_ok) {
                __auto_type vt = _mv_895.data.ok;
                __auto_type _mv_896 = howl_decode_individual_term(vt);
                switch (_mv_896.tag) {
                    case howl_decode_IndividualTerm_named_individual:
                    {
                        __auto_type i = _mv_896.data.named_individual;
                        return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_has_value, .data.rc_has_value = { .f0 = r, .f1 = ((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = i }) } }) });
                    }
                    case howl_decode_IndividualTerm_literal_individual:
                    {
                        return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_data, .data.rc_data = ((howl_types_InputRef){ .tag = howl_types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("owl:hasValue with a literal (DataHasValue)") }) }) });
                    }
                    case howl_decode_IndividualTerm_anonymous_individual:
                    {
                        return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_anon, .data.rc_anon = ((howl_types_InputRef){ .tag = howl_types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("owl:hasValue on an anonymous individual") }) }) });
                    }
                    case howl_decode_IndividualTerm_reserved_individual:
                    {
                        return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_anon, .data.rc_anon = ((howl_types_InputRef){ .tag = howl_types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("owl:hasValue on a reserved IRI as an individual") }) }) });
                    }
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_HAS_SELF)) {
        __auto_type _mv_897 = howl_decode_decode_role(arena, g, b);
        if (!_mv_897.is_ok) {
            __auto_type m = _mv_897.data.err;
            return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
        } else if (_mv_897.is_ok) {
            __auto_type r = _mv_897.data.ok;
            return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_has_self, .data.rc_has_self = r }) });
        }
        SLOP_UNREACHABLE();
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_QUALIFIED_CARDINALITY)) {
        return howl_decode_decode_cardinality(arena, g, b, howl_owl2_CardKind_card_exact, slop_rdf_vocab_OWL_QUALIFIED_CARDINALITY, 1, fuel);
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_MIN_QUALIFIED_CARDINALITY)) {
        return howl_decode_decode_cardinality(arena, g, b, howl_owl2_CardKind_card_min, slop_rdf_vocab_OWL_MIN_QUALIFIED_CARDINALITY, 1, fuel);
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_MAX_QUALIFIED_CARDINALITY)) {
        return howl_decode_decode_cardinality(arena, g, b, howl_owl2_CardKind_card_max, slop_rdf_vocab_OWL_MAX_QUALIFIED_CARDINALITY, 1, fuel);
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_CARDINALITY)) {
        return howl_decode_decode_cardinality(arena, g, b, howl_owl2_CardKind_card_exact, slop_rdf_vocab_OWL_CARDINALITY, 0, fuel);
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_MIN_CARDINALITY)) {
        return howl_decode_decode_cardinality(arena, g, b, howl_owl2_CardKind_card_min, slop_rdf_vocab_OWL_MIN_CARDINALITY, 0, fuel);
    } else if (howl_decode_has_pred(arena, g, b, slop_rdf_vocab_OWL_MAX_CARDINALITY)) {
        return howl_decode_decode_cardinality(arena, g, b, howl_owl2_CardKind_card_max, slop_rdf_vocab_OWL_MAX_CARDINALITY, 0, fuel);
    } else {
        return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_anon, .data.rc_anon = ((howl_types_InputRef){ .tag = howl_types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("blank node with no recognized class-expression vocabulary") }) }) });
    }
}

slop_result_howl_owl2_RawConcept_string howl_decode_decode_concept(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term t, int64_t fuel) {
    if (fuel <= 0) {
        return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = SLOP_STR("class expression nests past the fuel bound — a blank-node cycle") });
    } else {
        __auto_type _mv_898 = t;
        switch (_mv_898.tag) {
            case slop_rdf_rdf_Term_term_iri:
            {
                __auto_type i = _mv_898.data.term_iri;
                if (howl_canon_string_cmp(i.value, slop_rdf_vocab_OWL_THING) == 0) {
                    return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_thing }) });
                } else if (howl_canon_string_cmp(i.value, slop_rdf_vocab_OWL_NOTHING) == 0) {
                    return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_nothing }) });
                } else {
                    return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_name, .data.rc_name = ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = i }) }) });
                }
            }
            case slop_rdf_rdf_Term_term_literal:
            {
                __auto_type _ = _mv_898.data.term_literal;
                return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_data, .data.rc_data = ((howl_types_InputRef){ .tag = howl_types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("literal in a class position") }) }) });
            }
            case slop_rdf_rdf_Term_term_triple:
            {
                __auto_type _ = _mv_898.data.term_triple;
                return ((slop_result_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_anon, .data.rc_anon = ((howl_types_InputRef){ .tag = howl_types_InputRef_rdf_fragment, .data.rdf_fragment = SLOP_STR("RDF-star triple term in a class position") }) }) });
            }
            case slop_rdf_rdf_Term_term_blank:
            {
                __auto_type _ = _mv_898.data.term_blank;
                return howl_decode_decode_anon(arena, g, t, fuel);
            }
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t howl_decode_declare_entity(slop_arena* arena, howl_owl2_Signature sig, slop_rdf_rdf_IRI entity, slop_string type_iri) {
    if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_OWL_CLASS) == 0) {
        (void)(({ slop_map_put(NULL, sig.classes, &(entity), NULL, 0); }));
        return 1;
    } else if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_OWL_OBJECT_PROPERTY) == 0) {
        (void)(({ slop_map_put(NULL, sig.obj_props, &(entity), NULL, 0); }));
        return 1;
    } else if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_OWL_DATATYPE_PROPERTY) == 0) {
        (void)(({ slop_map_put(NULL, sig.data_props, &(entity), NULL, 0); }));
        return 1;
    } else if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_OWL_ANNOTATION_PROPERTY) == 0) {
        (void)(({ slop_map_put(NULL, sig.annot_props, &(entity), NULL, 0); }));
        return 1;
    } else if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_OWL_NAMED_INDIVIDUAL) == 0) {
        (void)(({ slop_map_put(NULL, sig.individuals, &(entity), NULL, 0); }));
        return 1;
    } else if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_RDFS_DATATYPE) == 0) {
        (void)(({ slop_map_put(NULL, sig.datatypes, &(entity), NULL, 0); }));
        return 1;
    } else {
        return 0;
    }
}

uint8_t howl_decode_add_builtins(slop_arena* arena, howl_owl2_Signature sig) {
    (void)(({ slop_rdf_rdf_IRI _key_905 = (((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_THING})); slop_map_put(NULL, sig.classes, &_key_905, NULL, 0); }));
    (void)(({ slop_rdf_rdf_IRI _key_906 = (((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_NOTHING})); slop_map_put(NULL, sig.classes, &_key_906, NULL, 0); }));
    (void)(({ slop_rdf_rdf_IRI _key_907 = (((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_TOP_OBJECT_PROPERTY})); slop_map_put(NULL, sig.obj_props, &_key_907, NULL, 0); }));
    (void)(({ slop_rdf_rdf_IRI _key_908 = (((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_BOTTOM_OBJECT_PROPERTY})); slop_map_put(NULL, sig.obj_props, &_key_908, NULL, 0); }));
    (void)(({ slop_rdf_rdf_IRI _key_909 = (((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_TOP_DATA_PROPERTY})); slop_map_put(NULL, sig.data_props, &_key_909, NULL, 0); }));
    (void)(({ slop_rdf_rdf_IRI _key_910 = (((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_BOTTOM_DATA_PROPERTY})); slop_map_put(NULL, sig.data_props, &_key_910, NULL, 0); }));
    (void)(({ slop_rdf_rdf_IRI _key_911 = (((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_RDFS_LABEL})); slop_map_put(NULL, sig.annot_props, &_key_911, NULL, 0); }));
    (void)(({ slop_rdf_rdf_IRI _key_912 = (((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_RDFS_COMMENT})); slop_map_put(NULL, sig.annot_props, &_key_912, NULL, 0); }));
    (void)(({ slop_rdf_rdf_IRI _key_913 = (((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_RDFS_SEE_ALSO})); slop_map_put(NULL, sig.annot_props, &_key_913, NULL, 0); }));
    (void)(({ slop_rdf_rdf_IRI _key_914 = (((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_RDFS_IS_DEFINED_BY})); slop_map_put(NULL, sig.annot_props, &_key_914, NULL, 0); }));
    (void)(({ slop_rdf_rdf_IRI _key_915 = (((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_VERSION_INFO})); slop_map_put(NULL, sig.annot_props, &_key_915, NULL, 0); }));
    (void)(({ slop_rdf_rdf_IRI _key_916 = (((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_DEPRECATED})); slop_map_put(NULL, sig.annot_props, &_key_916, NULL, 0); }));
    (void)(({ slop_rdf_rdf_IRI _key_917 = (((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_PRIOR_VERSION})); slop_map_put(NULL, sig.annot_props, &_key_917, NULL, 0); }));
    (void)(({ slop_rdf_rdf_IRI _key_918 = (((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_BACKWARD_COMPATIBLE_WITH})); slop_map_put(NULL, sig.annot_props, &_key_918, NULL, 0); }));
    (void)(({ slop_rdf_rdf_IRI _key_919 = (((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_INCOMPATIBLE_WITH})); slop_map_put(NULL, sig.annot_props, &_key_919, NULL, 0); }));
    return 1;
}

howl_owl2_Signature howl_decode_build_signature(slop_arena* arena, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples) {
    {
        __auto_type sig = howl_owl2_make_signature(arena);
        __auto_type type_pred = dict.rdf_type;
        howl_decode_add_builtins(arena, sig);
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (it.p == type_pred) {
                    __auto_type _mv_920 = howl_decode_term_iri_value(howl_termstore_term_of(dict, it.s));
                    if (_mv_920.has_value) {
                        __auto_type s = _mv_920.value;
                        __auto_type _mv_921 = howl_decode_term_iri_value(howl_termstore_term_of(dict, it.o));
                        if (_mv_921.has_value) {
                            __auto_type o = _mv_921.value;
                            howl_decode_declare_entity(arena, sig, s, o.value);
                        } else if (!_mv_921.has_value) {
                            0;
                        }
                    } else if (!_mv_920.has_value) {
                        0;
                    }
                }
            }
        }
        return sig;
    }
}

slop_string howl_decode_render_term(slop_arena* arena, slop_rdf_rdf_Term t) {
    __auto_type _mv_922 = t;
    switch (_mv_922.tag) {
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type i = _mv_922.data.term_iri;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">")));
        }
        case slop_rdf_rdf_Term_term_blank:
        {
            __auto_type b = _mv_922.data.term_blank;
            return string_concat(arena, SLOP_STR("_:b"), int_to_string(arena, b.id));
        }
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type l = _mv_922.data.term_literal;
            return string_concat(arena, SLOP_STR("\""), string_concat(arena, howl_decode_nt_escape(arena, l.value), SLOP_STR("\"")));
        }
        case slop_rdf_rdf_Term_term_triple:
        {
            __auto_type _ = _mv_922.data.term_triple;
            return SLOP_STR("<<embedded triple>>");
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_decode_nt_escape(slop_arena* arena, slop_string s) {
    return std_strlib_replace_all(arena, std_strlib_replace_all(arena, std_strlib_replace_all(arena, std_strlib_replace_all(arena, s, SLOP_STR("\\"), SLOP_STR("\\\\")), SLOP_STR("\""), SLOP_STR("\\\"")), SLOP_STR("\n"), SLOP_STR("\\n")), SLOP_STR("\r"), SLOP_STR("\\r"));
}

slop_string howl_decode_render_triple(slop_arena* arena, slop_rdf_rdf_Triple t) {
    return string_concat(arena, howl_decode_render_term(arena, t.subject), string_concat(arena, SLOP_STR(" "), string_concat(arena, howl_decode_render_term(arena, t.predicate), string_concat(arena, SLOP_STR(" "), string_concat(arena, howl_decode_render_term(arena, t.object), SLOP_STR(" ."))))));
}

howl_types_InputRef howl_decode_frag(slop_arena* arena, slop_rdf_rdf_Triple t) {
    return ((howl_types_InputRef){ .tag = howl_types_InputRef_rdf_fragment, .data.rdf_fragment = howl_decode_render_triple(arena, t) });
}

uint8_t howl_decode_is_pred(slop_rdf_rdf_Triple t, slop_string iri) {
    __auto_type _mv_923 = howl_decode_term_iri_value(t.predicate);
    if (_mv_923.has_value) {
        __auto_type i = _mv_923.value;
        return (howl_canon_string_cmp(i.value, iri) == 0);
    } else if (!_mv_923.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_decode_structural_predicate(slop_string p) {
    if (howl_canon_string_cmp(p, slop_rdf_vocab_RDF_FIRST) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_RDF_REST) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_INTERSECTION_OF) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_UNION_OF) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_ONE_OF) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_COMPLEMENT_OF) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_SOME_VALUES_FROM) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_ALL_VALUES_FROM) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_HAS_VALUE) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_HAS_SELF) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_ON_PROPERTY) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_ON_CLASS) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_ON_DATA_RANGE) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_ON_DATATYPE) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_DATATYPE_COMPLEMENT_OF) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_MIN_CARDINALITY) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_MAX_CARDINALITY) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_CARDINALITY) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_MIN_QUALIFIED_CARDINALITY) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_MAX_QUALIFIED_CARDINALITY) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_QUALIFIED_CARDINALITY) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_MEMBERS) == 0) {
        return 1;
    } else if (howl_canon_string_cmp(p, slop_rdf_vocab_OWL_DISTINCT_MEMBERS) == 0) {
        return 1;
    } else {
        return 0;
    }
}

uint8_t howl_decode_structural_triple(slop_rdf_rdf_Triple t) {
    if (({ __auto_type _mv = howl_decode_term_iri_value(t.predicate); _mv.has_value ? ({ __auto_type i = _mv.value; howl_decode_structural_predicate(i.value); }) : (0); }) && ({ __auto_type _mv = t.subject; uint8_t _mr = {0}; switch (_mv.tag) { case slop_rdf_rdf_Term_term_blank: { _mr = 1; break; } default: { _mr = 0; break; }  } _mr; })) {
        return 1;
    } else {
        if (!(howl_decode_is_pred(t, slop_rdf_vocab_RDF_TYPE))) {
            return (howl_decode_is_pred(t, slop_rdf_vocab_OWL_INVERSE_OF) && ({ __auto_type _mv = t.subject; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case slop_rdf_rdf_Term_term_blank: { _mr = 1; _mm = 1; break; } case slop_rdf_rdf_Term_term_iri: { _mr = 0; _mm = 1; break; } case slop_rdf_rdf_Term_term_literal: { _mr = 0; _mm = 1; break; } case slop_rdf_rdf_Term_term_triple: { _mr = 0; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }));
        } else {
            __auto_type _mv_924 = howl_decode_term_iri_value(t.object);
            if (_mv_924.has_value) {
                __auto_type o = _mv_924.value;
                return (({ __auto_type _mv = t.subject; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case slop_rdf_rdf_Term_term_blank: { _mr = 1; _mm = 1; break; } case slop_rdf_rdf_Term_term_iri: { _mr = 0; _mm = 1; break; } case slop_rdf_rdf_Term_term_literal: { _mr = 0; _mm = 1; break; } case slop_rdf_rdf_Term_term_triple: { _mr = 0; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }) && ((howl_canon_string_cmp(o.value, slop_rdf_vocab_OWL_CLASS) == 0) || (howl_canon_string_cmp(o.value, slop_rdf_vocab_OWL_RESTRICTION) == 0)));
            } else if (!_mv_924.has_value) {
                return 0;
            }
            SLOP_UNREACHABLE();
        }
    }
}

slop_option_howl_types_EntityKind howl_decode_entity_kind_of(slop_string type_iri) {
    if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_OWL_CLASS) == 0) {
        return (slop_option_howl_types_EntityKind){.has_value = 1, .value = howl_types_EntityKind_entity_class};
    } else if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_OWL_OBJECT_PROPERTY) == 0) {
        return (slop_option_howl_types_EntityKind){.has_value = 1, .value = howl_types_EntityKind_entity_object_property};
    } else if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_OWL_DATATYPE_PROPERTY) == 0) {
        return (slop_option_howl_types_EntityKind){.has_value = 1, .value = howl_types_EntityKind_entity_data_property};
    } else if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_OWL_ANNOTATION_PROPERTY) == 0) {
        return (slop_option_howl_types_EntityKind){.has_value = 1, .value = howl_types_EntityKind_entity_annotation_property};
    } else if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_OWL_NAMED_INDIVIDUAL) == 0) {
        return (slop_option_howl_types_EntityKind){.has_value = 1, .value = howl_types_EntityKind_entity_individual};
    } else if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_RDFS_DATATYPE) == 0) {
        return (slop_option_howl_types_EntityKind){.has_value = 1, .value = howl_types_EntityKind_entity_datatype};
    } else {
        return (slop_option_howl_types_EntityKind){.has_value = false};
    }
}

slop_option_howl_owl2_PropCharacteristic howl_decode_characteristic_of(slop_string type_iri) {
    if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_OWL_FUNCTIONAL_PROPERTY) == 0) {
        return (slop_option_howl_owl2_PropCharacteristic){.has_value = 1, .value = howl_owl2_PropCharacteristic_prop_functional};
    } else if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_OWL_INVERSE_FUNCTIONAL_PROPERTY) == 0) {
        return (slop_option_howl_owl2_PropCharacteristic){.has_value = 1, .value = howl_owl2_PropCharacteristic_prop_inverse_functional};
    } else if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_OWL_SYMMETRIC_PROPERTY) == 0) {
        return (slop_option_howl_owl2_PropCharacteristic){.has_value = 1, .value = howl_owl2_PropCharacteristic_prop_symmetric};
    } else if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_OWL_ASYMMETRIC_PROPERTY) == 0) {
        return (slop_option_howl_owl2_PropCharacteristic){.has_value = 1, .value = howl_owl2_PropCharacteristic_prop_asymmetric};
    } else if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_OWL_REFLEXIVE_PROPERTY) == 0) {
        return (slop_option_howl_owl2_PropCharacteristic){.has_value = 1, .value = howl_owl2_PropCharacteristic_prop_reflexive};
    } else if (howl_canon_string_cmp(type_iri, slop_rdf_vocab_OWL_IRREFLEXIVE_PROPERTY) == 0) {
        return (slop_option_howl_owl2_PropCharacteristic){.has_value = 1, .value = howl_owl2_PropCharacteristic_prop_irreflexive};
    } else {
        return (slop_option_howl_owl2_PropCharacteristic){.has_value = false};
    }
}

slop_option_howl_types_RoleId howl_decode_role_of_term(slop_rdf_rdf_Term t) {
    __auto_type _mv_925 = howl_decode_term_iri_value(t);
    if (_mv_925.has_value) {
        __auto_type i = _mv_925.value;
        return (slop_option_howl_types_RoleId){.has_value = 1, .value = ((howl_types_RoleId){ .tag = howl_types_RoleId_named_role, .data.named_role = i })};
    } else if (!_mv_925.has_value) {
        return (slop_option_howl_types_RoleId){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

slop_result_list_howl_types_RoleId_string howl_decode_decode_role_list(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term head) {
    __auto_type _mv_926 = howl_decode_rdf_list_checked(arena, g, head);
    if (!_mv_926.is_ok) {
        __auto_type lf = _mv_926.data.err;
        return ((slop_result_list_howl_types_RoleId_string){ .is_ok = false, .data.err = howl_decode_list_fault_message(lf) });
    } else if (_mv_926.is_ok) {
        __auto_type terms = _mv_926.data.ok;
        {
            __auto_type out = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            slop_option_string fault = (slop_option_string){.has_value = false};
            {
                __auto_type _coll = terms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tm = _coll.data[_i];
                    __auto_type _mv_927 = howl_decode_property_expression(arena, g, tm);
                    if (_mv_927.has_value) {
                        __auto_type r = _mv_927.value;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_927.has_value) {
                        fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("property chain step is not a property expression")};
                    }
                }
            }
            __auto_type _mv_928 = fault;
            if (_mv_928.has_value) {
                __auto_type m = _mv_928.value;
                return ((slop_result_list_howl_types_RoleId_string){ .is_ok = false, .data.err = m });
            } else if (!_mv_928.has_value) {
                return ((slop_result_list_howl_types_RoleId_string){ .is_ok = true, .data.ok = out });
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_decode_list_has_data(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term head) {
    __auto_type _mv_929 = howl_decode_rdf_list_checked(arena, g, head);
    if (!_mv_929.is_ok) {
        __auto_type _ = _mv_929.data.err;
        return 0;
    } else if (_mv_929.is_ok) {
        __auto_type terms = _mv_929.data.ok;
        {
            uint8_t found = 0;
            {
                __auto_type _coll = terms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type tm = _coll.data[_i];
                    if (howl_decode_data_property_term(arena, g, tm)) {
                        found = 1;
                    }
                }
            }
            return found;
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_list_howl_owl2_RawConcept_string howl_decode_binary_concepts(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t) {
    __auto_type _mv_930 = howl_decode_decode_concept(arena, g, t.subject, howl_decode_CONCEPT_FUEL);
    if (!_mv_930.is_ok) {
        __auto_type m = _mv_930.data.err;
        return ((slop_result_list_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
    } else if (_mv_930.is_ok) {
        __auto_type lhs = _mv_930.data.ok;
        __auto_type _mv_931 = howl_decode_decode_concept(arena, g, t.object, howl_decode_CONCEPT_FUEL);
        if (!_mv_931.is_ok) {
            __auto_type m = _mv_931.data.err;
            return ((slop_result_list_howl_owl2_RawConcept_string){ .is_ok = false, .data.err = m });
        } else if (_mv_931.is_ok) {
            __auto_type rhs = _mv_931.data.ok;
            {
                __auto_type out = ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (lhs); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (rhs); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                return ((slop_result_list_howl_owl2_RawConcept_string){ .is_ok = true, .data.ok = out });
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_option_slop_rdf_rdf_Term howl_decode_members_head(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term s) {
    __auto_type _mv_932 = howl_decode_obj_of(arena, g, s, slop_rdf_vocab_OWL_MEMBERS);
    if (_mv_932.is_ok) {
        __auto_type h = _mv_932.data.ok;
        return (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = h};
    } else if (!_mv_932.is_ok) {
        __auto_type _ = _mv_932.data.err;
        __auto_type _mv_933 = howl_decode_obj_of(arena, g, s, slop_rdf_vocab_OWL_DISTINCT_MEMBERS);
        if (_mv_933.is_ok) {
            __auto_type h = _mv_933.data.ok;
            return (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = h};
        } else if (!_mv_933.is_ok) {
            __auto_type _ = _mv_933.data.err;
            return (slop_option_slop_rdf_rdf_Term){.has_value = false};
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_declaration(slop_arena* arena, slop_rdf_rdf_Triple t, howl_types_EntityKind k) {
    __auto_type _mv_934 = howl_decode_term_iri_value(t.subject);
    if (_mv_934.has_value) {
        __auto_type s = _mv_934.value;
        if ((k == howl_types_EntityKind_entity_individual) && howl_decode_is_reserved_iri(s.value)) {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = howl_decode_frag(arena, t) }) });
        } else {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_declaration, .data.ra_declaration = ((howl_owl2_RawDeclaration){.kind = k, .entity = s}) }) });
        }
    } else if (!_mv_934.has_value) {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = howl_decode_frag(arena, t) }) });
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_all_different(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t) {
    __auto_type _mv_935 = howl_decode_members_head(arena, g, t.subject);
    if (!_mv_935.has_value) {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:AllDifferent without owl:members or owl:distinctMembers") });
    } else if (_mv_935.has_value) {
        __auto_type head = _mv_935.value;
        __auto_type _mv_936 = howl_decode_decode_node_list(arena, g, head);
        if (!_mv_936.is_ok) {
            __auto_type m = _mv_936.data.err;
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
        } else if (_mv_936.is_ok) {
            __auto_type nl = _mv_936.data.ok;
            __auto_type _mv_937 = nl;
            switch (_mv_937.tag) {
                case howl_decode_NodeList_all_named:
                {
                    __auto_type ns = _mv_937.data.all_named;
                    return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_different_individuals, .data.ra_different_individuals = ns }) });
                }
                case howl_decode_NodeList_has_literal:
                {
                    return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = howl_decode_frag(arena, t) }) });
                }
                case howl_decode_NodeList_has_anonymous:
                {
                    return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = howl_decode_frag(arena, t) }) });
                }
                case howl_decode_NodeList_has_reserved:
                {
                    return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = howl_decode_frag(arena, t) }) });
                }
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_all_disjoint_classes(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t) {
    __auto_type _mv_938 = howl_decode_members_head(arena, g, t.subject);
    if (!_mv_938.has_value) {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:AllDisjointClasses without owl:members") });
    } else if (_mv_938.has_value) {
        __auto_type head = _mv_938.value;
        __auto_type _mv_939 = howl_decode_decode_concept_list(arena, g, head, howl_decode_CONCEPT_FUEL);
        if (!_mv_939.is_ok) {
            __auto_type m = _mv_939.data.err;
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
        } else if (_mv_939.is_ok) {
            __auto_type cs = _mv_939.data.ok;
            if (((int64_t)((cs).len)) < 2) {
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = howl_decode_frag(arena, t) }) });
            } else {
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_disjoint_classes, .data.ra_disjoint_classes = cs }) });
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_all_disjoint_properties(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t) {
    __auto_type _mv_940 = howl_decode_members_head(arena, g, t.subject);
    if (!_mv_940.has_value) {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:AllDisjointProperties without owl:members") });
    } else if (_mv_940.has_value) {
        __auto_type head = _mv_940.value;
        if (howl_decode_list_has_data(arena, g, head)) {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = howl_decode_frag(arena, t) }) });
        } else {
            __auto_type _mv_941 = howl_decode_decode_role_list(arena, g, head);
            if (!_mv_941.is_ok) {
                __auto_type m = _mv_941.data.err;
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
            } else if (_mv_941.is_ok) {
                __auto_type rs = _mv_941.data.ok;
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_disjoint_properties, .data.ra_disjoint_properties = rs }) });
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_typed(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t, slop_rdf_rdf_IRI obj) {
    {
        __auto_type ov = obj.value;
        if (({ __auto_type _mv = howl_decode_entity_kind_of(ov); _mv.has_value ? ({ __auto_type _ = _mv.value; 1; }) : (0); })) {
            __auto_type _mv_942 = howl_decode_entity_kind_of(ov);
            if (_mv_942.has_value) {
                __auto_type k = _mv_942.value;
                return howl_decode_decode_declaration(arena, t, k);
            } else if (!_mv_942.has_value) {
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("unreachable: declaration type vanished") });
            }
            SLOP_UNREACHABLE();
        } else if (((howl_canon_string_cmp(ov, slop_rdf_vocab_OWL_TRANSITIVE_PROPERTY) == 0) || ({ __auto_type _mv = howl_decode_characteristic_of(ov); _mv.has_value ? ({ __auto_type _ = _mv.value; 1; }) : (0); })) && howl_decode_data_property_term(arena, g, t.subject)) {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = howl_decode_frag(arena, t) }) });
        } else if (howl_canon_string_cmp(ov, slop_rdf_vocab_OWL_TRANSITIVE_PROPERTY) == 0) {
            __auto_type _mv_943 = howl_decode_property_expression(arena, g, t.subject);
            if (_mv_943.has_value) {
                __auto_type r = _mv_943.value;
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_transitive_property, .data.ra_transitive_property = r }) });
            } else if (!_mv_943.has_value) {
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:TransitiveProperty on a non-IRI subject") });
            }
            SLOP_UNREACHABLE();
        } else if (({ __auto_type _mv = howl_decode_characteristic_of(ov); _mv.has_value ? ({ __auto_type _ = _mv.value; 1; }) : (0); })) {
            __auto_type _mv_944 = howl_decode_property_expression(arena, g, t.subject);
            if (_mv_944.has_value) {
                __auto_type r = _mv_944.value;
                __auto_type _mv_945 = howl_decode_characteristic_of(ov);
                if (_mv_945.has_value) {
                    __auto_type c = _mv_945.value;
                    return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_property_characteristic, .data.ra_property_characteristic = { .f0 = c, .f1 = r } }) });
                } else if (!_mv_945.has_value) {
                    return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("unreachable: characteristic vanished") });
                }
                SLOP_UNREACHABLE();
            } else if (!_mv_944.has_value) {
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("property characteristic on a non-IRI subject") });
            }
            SLOP_UNREACHABLE();
        } else if (howl_canon_string_cmp(ov, slop_rdf_vocab_OWL_ALL_DIFFERENT) == 0) {
            return howl_decode_decode_all_different(arena, g, t);
        } else if (howl_canon_string_cmp(ov, slop_rdf_vocab_OWL_ALL_DISJOINT_CLASSES) == 0) {
            return howl_decode_decode_all_disjoint_classes(arena, g, t);
        } else if (howl_canon_string_cmp(ov, slop_rdf_vocab_OWL_ALL_DISJOINT_PROPERTIES) == 0) {
            return howl_decode_decode_all_disjoint_properties(arena, g, t);
        } else if (howl_canon_string_cmp(ov, slop_rdf_vocab_OWL_NEGATIVE_PROPERTY_ASSERTION) == 0) {
            return howl_decode_decode_negative_assertion(arena, g, t);
        } else if (howl_canon_string_cmp(ov, slop_rdf_vocab_SWRL_IMP) == 0) {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_swrl_rule, .data.ra_swrl_rule = howl_decode_frag(arena, t) }) });
        } else {
            return howl_decode_decode_class_assertion(arena, g, t);
        }
    }
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_individual_pair(slop_arena* arena, slop_rdf_rdf_Triple t, uint8_t same) {
    __auto_type _mv_946 = howl_decode_individual_term(t.subject);
    switch (_mv_946.tag) {
        case howl_decode_IndividualTerm_literal_individual:
        {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = howl_decode_frag(arena, t) }) });
        }
        case howl_decode_IndividualTerm_anonymous_individual:
        {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = howl_decode_frag(arena, t) }) });
        }
        case howl_decode_IndividualTerm_reserved_individual:
        {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = howl_decode_frag(arena, t) }) });
        }
        case howl_decode_IndividualTerm_named_individual:
        {
            __auto_type a = _mv_946.data.named_individual;
            __auto_type _mv_947 = howl_decode_individual_term(t.object);
            switch (_mv_947.tag) {
                case howl_decode_IndividualTerm_literal_individual:
                {
                    return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = howl_decode_frag(arena, t) }) });
                }
                case howl_decode_IndividualTerm_anonymous_individual:
                {
                    return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = howl_decode_frag(arena, t) }) });
                }
                case howl_decode_IndividualTerm_reserved_individual:
                {
                    return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = howl_decode_frag(arena, t) }) });
                }
                case howl_decode_IndividualTerm_named_individual:
                {
                    __auto_type b = _mv_947.data.named_individual;
                    {
                        __auto_type ns = ((slop_list_howl_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                        ({ __auto_type _lst_p = &(ns); __auto_type _item = (((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = a })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(ns); __auto_type _item = (((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = b })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        if (same) {
                            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_same_individual, .data.ra_same_individual = ns }) });
                        } else {
                            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_different_individuals, .data.ra_different_individuals = ns }) });
                        }
                    }
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_negative_object_assertion(slop_arena* arena, slop_rdf_rdf_Triple t, howl_types_RoleId r, slop_rdf_rdf_Term st, slop_rdf_rdf_Term tt) {
    __auto_type _mv_948 = howl_decode_individual_term(st);
    switch (_mv_948.tag) {
        case howl_decode_IndividualTerm_literal_individual:
        {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = howl_decode_frag(arena, t) }) });
        }
        case howl_decode_IndividualTerm_anonymous_individual:
        {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = howl_decode_frag(arena, t) }) });
        }
        case howl_decode_IndividualTerm_reserved_individual:
        {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = howl_decode_frag(arena, t) }) });
        }
        case howl_decode_IndividualTerm_named_individual:
        {
            __auto_type a = _mv_948.data.named_individual;
            __auto_type _mv_949 = howl_decode_individual_term(tt);
            switch (_mv_949.tag) {
                case howl_decode_IndividualTerm_literal_individual:
                {
                    return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = howl_decode_frag(arena, t) }) });
                }
                case howl_decode_IndividualTerm_anonymous_individual:
                {
                    return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = howl_decode_frag(arena, t) }) });
                }
                case howl_decode_IndividualTerm_reserved_individual:
                {
                    return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = howl_decode_frag(arena, t) }) });
                }
                case howl_decode_IndividualTerm_named_individual:
                {
                    __auto_type b = _mv_949.data.named_individual;
                    return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_negative_assertion, .data.ra_negative_assertion = ((howl_owl2_RawEdge){.role = r, .from = ((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = a }), .to = ((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = b })}) }) });
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_negative_target_individual(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t, slop_rdf_rdf_Term pt, slop_rdf_rdf_Term st) {
    __auto_type _mv_950 = howl_decode_obj_of(arena, g, t.subject, slop_rdf_vocab_OWL_TARGET_INDIVIDUAL);
    if (!_mv_950.is_ok) {
        __auto_type _ = _mv_950.data.err;
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:NegativePropertyAssertion without exactly one owl:targetIndividual") });
    } else if (_mv_950.is_ok) {
        __auto_type tt = _mv_950.data.ok;
        if (howl_decode_data_property_term(arena, g, pt)) {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = howl_decode_frag(arena, t) }) });
        } else {
            __auto_type _mv_951 = howl_decode_property_expression(arena, g, pt);
            if (!_mv_951.has_value) {
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:assertionProperty is not a property") });
            } else if (_mv_951.has_value) {
                __auto_type r = _mv_951.value;
                return howl_decode_negative_object_assertion(arena, t, r, st, tt);
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_negative_target(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t, slop_rdf_rdf_Term pt, slop_rdf_rdf_Term st) {
    {
        __auto_type x = t.subject;
        if (howl_decode_has_pred(arena, g, x, slop_rdf_vocab_OWL_TARGET_VALUE) && howl_decode_has_pred(arena, g, x, slop_rdf_vocab_OWL_TARGET_INDIVIDUAL)) {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:NegativePropertyAssertion with both owl:targetIndividual and owl:targetValue") });
        } else if (howl_decode_has_pred(arena, g, x, slop_rdf_vocab_OWL_TARGET_VALUE)) {
            __auto_type _mv_952 = howl_decode_obj_of(arena, g, x, slop_rdf_vocab_OWL_TARGET_VALUE);
            if (!_mv_952.is_ok) {
                __auto_type _ = _mv_952.data.err;
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:NegativePropertyAssertion without exactly one owl:targetValue") });
            } else if (_mv_952.is_ok) {
                __auto_type _ = _mv_952.data.ok;
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = howl_decode_frag(arena, t) }) });
            }
            SLOP_UNREACHABLE();
        } else {
            return howl_decode_negative_target_individual(arena, g, t, pt, st);
        }
    }
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_negative_assertion(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t) {
    {
        __auto_type x = t.subject;
        __auto_type _mv_953 = howl_decode_obj_of(arena, g, x, slop_rdf_vocab_OWL_ASSERTION_PROPERTY);
        if (!_mv_953.is_ok) {
            __auto_type _ = _mv_953.data.err;
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:NegativePropertyAssertion without exactly one owl:assertionProperty") });
        } else if (_mv_953.is_ok) {
            __auto_type pt = _mv_953.data.ok;
            __auto_type _mv_954 = howl_decode_obj_of(arena, g, x, slop_rdf_vocab_OWL_SOURCE_INDIVIDUAL);
            if (!_mv_954.is_ok) {
                __auto_type _ = _mv_954.data.err;
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:NegativePropertyAssertion without exactly one owl:sourceIndividual") });
            } else if (_mv_954.is_ok) {
                __auto_type st = _mv_954.data.ok;
                return howl_decode_negative_target(arena, g, t, pt, st);
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_class_assertion(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t) {
    __auto_type _mv_955 = howl_decode_decode_concept(arena, g, t.object, howl_decode_CONCEPT_FUEL);
    if (!_mv_955.is_ok) {
        __auto_type m = _mv_955.data.err;
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_955.is_ok) {
        __auto_type c = _mv_955.data.ok;
        __auto_type _mv_956 = howl_decode_term_iri_value(t.subject);
        if (_mv_956.has_value) {
            __auto_type s = _mv_956.value;
            if (howl_decode_is_reserved_iri(s.value)) {
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = howl_decode_frag(arena, t) }) });
            } else {
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_class_assertion, .data.ra_class_assertion = ((howl_owl2_RawClassAssertion){.concept = howl_decode_box_concept(arena, c), .subject = ((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = s })}) }) });
            }
        } else if (!_mv_956.has_value) {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = howl_decode_frag(arena, t) }) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_decode_is_reserved_iri(slop_string v) {
    return ((std_strlib_starts_with(v, slop_rdf_vocab_OWL_NS)) || (std_strlib_starts_with(v, slop_rdf_vocab_RDF_NS)) || (std_strlib_starts_with(v, slop_rdf_vocab_RDFS_NS)) || (std_strlib_starts_with(v, slop_rdf_vocab_SWRL_NS)) || (std_strlib_starts_with(v, slop_rdf_vocab_XSD_NS)));
}

int64_t howl_decode_property_axiom_kind(howl_owl2_Signature sig, slop_rdf_rdf_Term subj) {
    __auto_type _mv_957 = howl_decode_term_iri_value(subj);
    if (!_mv_957.has_value) {
        return 0;
    } else if (_mv_957.has_value) {
        __auto_type i = _mv_957.value;
        if (howl_owl2_signature_has_annotation_property(sig, i)) {
            return 1;
        } else if (howl_owl2_signature_has_data_property(sig, i)) {
            return 2;
        } else {
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_sub_class_of(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t) {
    __auto_type _mv_958 = howl_decode_decode_concept(arena, g, t.subject, howl_decode_CONCEPT_FUEL);
    if (!_mv_958.is_ok) {
        __auto_type m = _mv_958.data.err;
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_958.is_ok) {
        __auto_type lhs = _mv_958.data.ok;
        __auto_type _mv_959 = howl_decode_decode_concept(arena, g, t.object, howl_decode_CONCEPT_FUEL);
        if (!_mv_959.is_ok) {
            __auto_type m = _mv_959.data.err;
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
        } else if (_mv_959.is_ok) {
            __auto_type rhs = _mv_959.data.ok;
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_sub_class_of, .data.ra_sub_class_of = { .f0 = howl_decode_box_concept(arena, lhs), .f1 = howl_decode_box_concept(arena, rhs) } }) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_property_chain(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t) {
    __auto_type _mv_960 = howl_decode_property_expression(arena, g, t.subject);
    if (!_mv_960.has_value) {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:propertyChainAxiom on a non-IRI subject") });
    } else if (_mv_960.has_value) {
        __auto_type super = _mv_960.value;
        __auto_type _mv_961 = howl_decode_decode_role_list(arena, g, t.object);
        if (!_mv_961.is_ok) {
            __auto_type m = _mv_961.data.err;
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
        } else if (_mv_961.is_ok) {
            __auto_type steps = _mv_961.data.ok;
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_property_chain, .data.ra_property_chain = ((howl_owl2_RawChain){.steps = steps, .super = super}) }) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_sub_property(slop_arena* arena, howl_termstore_TermStore g, howl_owl2_Signature sig, slop_rdf_rdf_Triple t) {
    if (howl_decode_property_axiom_kind(sig, t.subject) == 1) {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_annotation }) });
    } else if (howl_decode_property_axiom_kind(sig, t.subject) == 2) {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = howl_decode_frag(arena, t) }) });
    } else {
        __auto_type _mv_962 = howl_decode_property_expression(arena, g, t.subject);
        if (!_mv_962.has_value) {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("rdfs:subPropertyOf on a non-IRI subject") });
        } else if (_mv_962.has_value) {
            __auto_type sub = _mv_962.value;
            __auto_type _mv_963 = howl_decode_property_expression(arena, g, t.object);
            if (!_mv_963.has_value) {
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("rdfs:subPropertyOf with a non-IRI object") });
            } else if (_mv_963.has_value) {
                __auto_type sup = _mv_963.value;
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_sub_object_property, .data.ra_sub_object_property = { .f0 = sub, .f1 = sup } }) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

slop_result_list_howl_types_RoleId_string howl_decode_property_pair(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t, slop_string pred) {
    __auto_type _mv_964 = howl_decode_property_expression(arena, g, t.subject);
    if (!_mv_964.has_value) {
        return ((slop_result_list_howl_types_RoleId_string){ .is_ok = false, .data.err = string_concat(arena, pred, SLOP_STR(" on a non-IRI subject")) });
    } else if (_mv_964.has_value) {
        __auto_type a = _mv_964.value;
        __auto_type _mv_965 = howl_decode_property_expression(arena, g, t.object);
        if (!_mv_965.has_value) {
            return ((slop_result_list_howl_types_RoleId_string){ .is_ok = false, .data.err = string_concat(arena, pred, SLOP_STR(" with a non-IRI object")) });
        } else if (_mv_965.has_value) {
            __auto_type b = _mv_965.value;
            {
                __auto_type rs = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                return ((slop_result_list_howl_types_RoleId_string){ .is_ok = true, .data.ok = rs });
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_inverse_of(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t) {
    __auto_type _mv_966 = howl_decode_property_expression(arena, g, t.subject);
    if (!_mv_966.has_value) {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:inverseOf on a non-IRI subject") });
    } else if (_mv_966.has_value) {
        __auto_type a = _mv_966.value;
        __auto_type _mv_967 = howl_decode_property_expression(arena, g, t.object);
        if (!_mv_967.has_value) {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("owl:inverseOf with a non-IRI object") });
        } else if (_mv_967.has_value) {
            __auto_type b = _mv_967.value;
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_inverse_properties, .data.ra_inverse_properties = { .f0 = a, .f1 = b } }) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_domain(slop_arena* arena, howl_termstore_TermStore g, howl_owl2_Signature sig, slop_rdf_rdf_Triple t) {
    if (howl_decode_property_axiom_kind(sig, t.subject) == 1) {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_annotation }) });
    } else if (howl_decode_property_axiom_kind(sig, t.subject) == 2) {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = howl_decode_frag(arena, t) }) });
    } else {
        __auto_type _mv_968 = howl_decode_property_expression(arena, g, t.subject);
        if (!_mv_968.has_value) {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("rdfs:domain on a non-IRI subject") });
        } else if (_mv_968.has_value) {
            __auto_type r = _mv_968.value;
            __auto_type _mv_969 = howl_decode_decode_concept(arena, g, t.object, howl_decode_CONCEPT_FUEL);
            if (!_mv_969.is_ok) {
                __auto_type m = _mv_969.data.err;
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
            } else if (_mv_969.is_ok) {
                __auto_type c = _mv_969.data.ok;
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_object_property_domain, .data.ra_object_property_domain = { .f0 = r, .f1 = howl_decode_box_concept(arena, c) } }) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_range(slop_arena* arena, howl_termstore_TermStore g, howl_owl2_Signature sig, slop_rdf_rdf_Triple t) {
    if (howl_decode_property_axiom_kind(sig, t.subject) == 1) {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_annotation }) });
    } else if (howl_decode_property_axiom_kind(sig, t.subject) == 2) {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = howl_decode_frag(arena, t) }) });
    } else {
        __auto_type _mv_970 = howl_decode_property_expression(arena, g, t.subject);
        if (!_mv_970.has_value) {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("rdfs:range on a non-IRI subject") });
        } else if (_mv_970.has_value) {
            __auto_type r = _mv_970.value;
            __auto_type _mv_971 = howl_decode_decode_concept(arena, g, t.object, howl_decode_CONCEPT_FUEL);
            if (!_mv_971.is_ok) {
                __auto_type m = _mv_971.data.err;
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
            } else if (_mv_971.is_ok) {
                __auto_type c = _mv_971.data.ok;
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_object_property_range, .data.ra_object_property_range = { .f0 = r, .f1 = howl_decode_box_concept(arena, c) } }) });
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_disjoint_union(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t) {
    __auto_type _mv_972 = howl_decode_term_iri_value(t.subject);
    if (!_mv_972.has_value) {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = howl_decode_frag(arena, t) }) });
    } else if (_mv_972.has_value) {
        __auto_type c = _mv_972.value;
        __auto_type _mv_973 = howl_decode_decode_concept_list(arena, g, t.object, howl_decode_CONCEPT_FUEL);
        if (!_mv_973.is_ok) {
            __auto_type _ = _mv_973.data.err;
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = howl_decode_frag(arena, t) }) });
        } else if (_mv_973.is_ok) {
            __auto_type ds = _mv_973.data.ok;
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_disjoint_union, .data.ra_disjoint_union = ((howl_owl2_RawDisjointUnion){.class = c, .members = ds}) }) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_assertion_between(slop_arena* arena, slop_rdf_rdf_Triple t, howl_types_RoleId r, slop_rdf_rdf_IRI sfrom, slop_rdf_rdf_IRI sto) {
    if (howl_decode_is_reserved_iri(sfrom.value) || howl_decode_is_reserved_iri(sto.value)) {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = howl_decode_frag(arena, t) }) });
    } else {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_object_property_assertion, .data.ra_object_property_assertion = ((howl_owl2_RawEdge){.role = r, .from = ((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = sfrom }), .to = ((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = sto })}) }) });
    }
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_property_assertion(slop_arena* arena, slop_rdf_rdf_Triple t) {
    __auto_type _mv_974 = howl_decode_role_of_term(t.predicate);
    if (!_mv_974.has_value) {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = SLOP_STR("unreachable: declared object property is not an IRI") });
    } else if (_mv_974.has_value) {
        __auto_type r = _mv_974.value;
        __auto_type _mv_975 = howl_decode_term_iri_value(t.subject);
        if (!_mv_975.has_value) {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = howl_decode_frag(arena, t) }) });
        } else if (_mv_975.has_value) {
            __auto_type sfrom = _mv_975.value;
            __auto_type _mv_976 = howl_decode_term_iri_value(t.object);
            if (!_mv_976.has_value) {
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_anonymous_individual, .data.ra_anonymous_individual = howl_decode_frag(arena, t) }) });
            } else if (_mv_976.has_value) {
                __auto_type sto = _mv_976.value;
                return howl_decode_assertion_between(arena, t, r, sfrom, sto);
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_list_axiom(slop_result_list_howl_owl2_RawConcept_string r, uint8_t disjoint) {
    __auto_type _mv_977 = r;
    if (!_mv_977.is_ok) {
        __auto_type m = _mv_977.data.err;
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_977.is_ok) {
        __auto_type cs = _mv_977.data.ok;
        if (disjoint) {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_disjoint_classes, .data.ra_disjoint_classes = cs }) });
        } else {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_equivalent_classes, .data.ra_equivalent_classes = cs }) });
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_pair_axiom(slop_result_list_howl_types_RoleId_string r, uint8_t disjoint) {
    __auto_type _mv_978 = r;
    if (!_mv_978.is_ok) {
        __auto_type m = _mv_978.data.err;
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_978.is_ok) {
        __auto_type rs = _mv_978.data.ok;
        if (disjoint) {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_disjoint_properties, .data.ra_disjoint_properties = rs }) });
        } else {
            return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_equivalent_properties, .data.ra_equivalent_properties = rs }) });
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_owl2_RawAxiom_string howl_decode_decode_axiom(slop_arena* arena, howl_termstore_TermStore g, howl_owl2_Signature sig, slop_rdf_rdf_Triple t) {
    __auto_type _mv_979 = howl_decode_term_iri_value(t.predicate);
    if (!_mv_979.has_value) {
        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = howl_decode_frag(arena, t) }) });
    } else if (_mv_979.has_value) {
        __auto_type p = _mv_979.value;
        {
            __auto_type pv = p.value;
            if (howl_canon_string_cmp(pv, slop_rdf_vocab_RDF_TYPE) == 0) {
                __auto_type _mv_980 = t.object;
                switch (_mv_980.tag) {
                    case slop_rdf_rdf_Term_term_iri:
                    {
                        __auto_type o = _mv_980.data.term_iri;
                        return howl_decode_decode_typed(arena, g, t, o);
                    }
                    case slop_rdf_rdf_Term_term_blank:
                    {
                        __auto_type _ = _mv_980.data.term_blank;
                        return howl_decode_decode_class_assertion(arena, g, t);
                    }
                    default: {
                        return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = howl_decode_frag(arena, t) }) });
                    }
                }
            } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_RDFS_SUBCLASS_OF) == 0) {
                return howl_decode_decode_sub_class_of(arena, g, t);
            } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_EQUIVALENT_CLASS) == 0) {
                return howl_decode_list_axiom(howl_decode_binary_concepts(arena, g, t), 0);
            } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_DISJOINT_WITH) == 0) {
                return howl_decode_list_axiom(howl_decode_binary_concepts(arena, g, t), 1);
            } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_PROPERTY_CHAIN_AXIOM) == 0) {
                return howl_decode_decode_property_chain(arena, g, t);
            } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_RDFS_SUBPROPERTY_OF) == 0) {
                return howl_decode_decode_sub_property(arena, g, sig, t);
            } else if ((((howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_EQUIVALENT_PROPERTY) == 0)) || ((howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_PROPERTY_DISJOINT_WITH) == 0)) || ((howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_INVERSE_OF) == 0))) && (howl_decode_data_property_term(arena, g, t.subject) || howl_decode_data_property_term(arena, g, t.object))) {
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = howl_decode_frag(arena, t) }) });
            } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_EQUIVALENT_PROPERTY) == 0) {
                return howl_decode_pair_axiom(howl_decode_property_pair(arena, g, t, SLOP_STR("owl:equivalentProperty")), 0);
            } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_PROPERTY_DISJOINT_WITH) == 0) {
                return howl_decode_pair_axiom(howl_decode_property_pair(arena, g, t, SLOP_STR("owl:propertyDisjointWith")), 1);
            } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_INVERSE_OF) == 0) {
                return howl_decode_decode_inverse_of(arena, g, t);
            } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_RDFS_DOMAIN) == 0) {
                return howl_decode_decode_domain(arena, g, sig, t);
            } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_RDFS_RANGE) == 0) {
                return howl_decode_decode_range(arena, g, sig, t);
            } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_SAME_AS) == 0) {
                return howl_decode_decode_individual_pair(arena, t, 1);
            } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_DIFFERENT_FROM) == 0) {
                return howl_decode_decode_individual_pair(arena, t, 0);
            } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_DISJOINT_UNION_OF) == 0) {
                return howl_decode_decode_disjoint_union(arena, g, t);
            } else if (howl_canon_string_cmp(pv, slop_rdf_vocab_OWL_HAS_KEY) == 0) {
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_has_key, .data.ra_has_key = howl_decode_frag(arena, t) }) });
            } else if (howl_owl2_signature_has_annotation_property(sig, p)) {
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_annotation }) });
            } else if (howl_owl2_signature_has_object_property(sig, p)) {
                return howl_decode_decode_property_assertion(arena, t);
            } else if (howl_decode_is_reserved_iri(pv)) {
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_reserved_vocabulary, .data.ra_reserved_vocabulary = howl_decode_frag(arena, t) }) });
            } else if (howl_owl2_signature_has_data_property(sig, p)) {
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = true, .data.ok = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_data_axiom, .data.ra_data_axiom = howl_decode_frag(arena, t) }) });
            } else {
                return ((slop_result_howl_owl2_RawAxiom_string){ .is_ok = false, .data.err = string_concat(arena, SLOP_STR("unreachable: undeclared property reached decode-axiom: "), pv) });
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_decode_Stage1_howl_types_Fault howl_decode_decode_axioms(slop_arena* arena, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type res = howl_decode_decode_axioms_with(arena, howl_decode_decode_store(scratch, dict, triples), dict, triples);
        (void)(({ slop_arena_free(scratch); free(scratch); }));
        return res;
    }
}

howl_termstore_TermStore howl_decode_decode_store(slop_arena* arena, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples) {
    {
        __auto_type st = howl_termstore_store_over(arena, dict);
        __auto_type keep = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = howl_decode_queried_predicates(arena);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type iri = _coll.data[_i];
                {
                    __auto_type id = howl_decode_vocab_id(arena, dict, iri);
                    if (id >= 0) {
                        (void)(({ slop_map_put(NULL, keep, &(int64_t){id}, NULL, 0); }));
                    }
                }
            }
        }
        {
            __auto_type ty = howl_decode_vocab_id(arena, dict, slop_rdf_vocab_RDF_TYPE);
            __auto_type dtp = howl_decode_vocab_id(arena, dict, slop_rdf_vocab_OWL_DATATYPE_PROPERTY);
            {
                __auto_type _coll = triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type it = _coll.data[_i];
                    if (slop_map_has(keep, &(int64_t){it.p}) || ((dtp >= 0) && ((it.p == ty) && (it.o == dtp)))) {
                        howl_termstore_store_insert_ids(arena, st, it);
                    }
                }
            }
        }
        return st;
    }
}

slop_list_string howl_decode_queried_predicates(slop_arena* arena) {
    {
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_RDF_FIRST); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_RDF_REST); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_ON_PROPERTY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_INVERSE_OF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_INTERSECTION_OF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_UNION_OF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_ONE_OF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_COMPLEMENT_OF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_SOME_VALUES_FROM); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_ALL_VALUES_FROM); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_HAS_VALUE); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_HAS_SELF); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_QUALIFIED_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_MIN_QUALIFIED_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_MAX_QUALIFIED_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_MIN_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_MAX_CARDINALITY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_ON_CLASS); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_ON_DATA_RANGE); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_ON_PROPERTIES); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_MEMBERS); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_DISTINCT_MEMBERS); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_SOURCE_INDIVIDUAL); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_ASSERTION_PROPERTY); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_TARGET_INDIVIDUAL); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ps); __auto_type _item = (slop_rdf_vocab_OWL_TARGET_VALUE); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return ps;
    }
}

uint8_t howl_decode_keep_axiom(howl_decode_Decoding* c, howl_owl2_RawAxiom ax) {
    __auto_type _mv_983 = howl_owl2_disposition(howl_types_Profile_profile_el, ax);
    if (_mv_983 == howl_owl2_Disposition_d_inert) {
        (*c).inert = ((*c).inert + 1);
    } else if (_mv_983 == howl_owl2_Disposition_d_consumed) {
        ({ __auto_type _lst_p = &((*c).out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
    } else if (_mv_983 == howl_owl2_Disposition_d_in_profile) {
        ({ __auto_type _lst_p = &((*c).out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
    } else if (_mv_983 == howl_owl2_Disposition_d_out_of_profile) {
        ({ __auto_type _lst_p = &((*c).out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
    }
    return 1;
}

uint8_t howl_decode_decode_triple(slop_arena* arena, howl_decode_Decoding* c, howl_termstore_IdTriple it, slop_rdf_rdf_Triple t) {
    if (howl_decode_malformed_inverse(arena, (*c).ig, t)) {
        (void)(({ __auto_type _lst_p = &((*c).out); __auto_type _item = (((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = howl_decode_frag(arena, t) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return 1;
    } else if ((howl_decode_structural_triple(t)) || (howl_decode_negative_assertion_part(it, (*c).npa_nodes, (*c).npa_parts)) || (slop_map_has((*c).lemma.tree, &(int64_t){it.s}))) {
        return 1;
    } else if (howl_decode_inert_data_axiom((*c).dv, (*c).lemma, it)) {
        return howl_decode_keep_axiom(c, ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_inert_data }));
    } else {
        __auto_type _mv_985 = howl_decode_undeclared_predicate((*c).sig, t);
        if (_mv_985.has_value) {
            __auto_type up = _mv_985.value;
            ({ __auto_type _lst_p = &((*c).uprops); __auto_type _item = (up); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &((*c).utexts); __auto_type _item = (howl_decode_render_triple(arena, t)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            return 1;
        } else if (!_mv_985.has_value) {
            __auto_type _mv_986 = howl_decode_decode_axiom(arena, (*c).ig, (*c).sig, t);
            if (!_mv_986.is_ok) {
                __auto_type m = _mv_986.data.err;
                (*c).fault = (slop_option_string){.has_value = 1, .value = m};
                return 1;
            } else if (_mv_986.is_ok) {
                __auto_type ax = _mv_986.data.ok;
                return howl_decode_keep_axiom(c, ax);
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

slop_result_howl_decode_Stage1_howl_types_Fault howl_decode_decode_axioms_with(slop_arena* arena, howl_termstore_TermStore ig, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples) {
    {
        __auto_type sig = howl_decode_build_signature(arena, dict, triples);
        __auto_type conflict = howl_decode_declaration_conflict(arena, sig, dict, triples);
        __auto_type npa_nodes = howl_decode_negative_assertion_nodes(arena, dict, triples);
        __auto_type npa_parts = howl_decode_negative_assertion_parts(arena, dict);
        __auto_type dv = howl_decode_data_vocab(arena, dict);
        __auto_type lemma = howl_decode_data_lemma(arena, dict, sig, dv, triples);
        __auto_type c = ((howl_decode_Decoding*)(({ __auto_type _alloc = (howl_decode_Decoding*)slop_arena_alloc(arena, sizeof(howl_decode_Decoding)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*c) = ((howl_decode_Decoding){.ig = ig, .sig = sig, .dv = dv, .lemma = lemma, .npa_nodes = npa_nodes, .npa_parts = npa_parts, .out = ((slop_list_howl_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .inert = 0, .uprops = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .utexts = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .fault = conflict});
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                howl_decode_decode_triple(arena, c, it, howl_termstore_triple_of(dict, it));
            }
        }
        __auto_type _mv_987 = (*c).fault;
        if (_mv_987.has_value) {
            __auto_type m = _mv_987.value;
            return ((slop_result_howl_decode_Stage1_howl_types_Fault){ .is_ok = false, .data.err = ((howl_types_Fault){ .tag = howl_types_Fault_input_error, .data.input_error = m }) });
        } else if (!_mv_987.has_value) {
            return ((slop_result_howl_decode_Stage1_howl_types_Fault){ .is_ok = true, .data.ok = ((howl_decode_Stage1){.axioms = (*c).out, .signature = sig, .inert = (*c).inert, .omitted = howl_decode_undeclared_omissions(arena, (*c).uprops, (*c).utexts)}) });
        }
        SLOP_UNREACHABLE();
    }
}

slop_option_slop_rdf_rdf_IRI howl_decode_undeclared_predicate(howl_owl2_Signature sig, slop_rdf_rdf_Triple t) {
    __auto_type _mv_988 = howl_decode_term_iri_value(t.predicate);
    if (!_mv_988.has_value) {
        return (slop_option_slop_rdf_rdf_IRI){.has_value = false};
    } else if (_mv_988.has_value) {
        __auto_type p = _mv_988.value;
        if (howl_decode_is_reserved_iri(p.value) || (howl_owl2_signature_has_annotation_property(sig, p) || (howl_owl2_signature_has_object_property(sig, p) || howl_owl2_signature_has_data_property(sig, p)))) {
            return (slop_option_slop_rdf_rdf_IRI){.has_value = false};
        } else {
            return (slop_option_slop_rdf_rdf_IRI){.has_value = 1, .value = p};
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Omission howl_decode_undeclared_omissions(slop_arena* arena, slop_list_slop_rdf_rdf_IRI ps, slop_list_string texts) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((ps).len)))), ({ howl_decode__lambda_989_env_t* howl_decode__lambda_989_env = (howl_decode__lambda_989_env_t*)slop_arena_alloc(arena, sizeof(howl_decode__lambda_989_env_t)); *howl_decode__lambda_989_env = (howl_decode__lambda_989_env_t){ .ps = ps, .texts = texts }; (slop_closure_t){ (void*)howl_decode__lambda_989, (void*)howl_decode__lambda_989_env }; }));
        __auto_type out = ((slop_list_howl_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type refs = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        slop_option_slop_rdf_rdf_IRI cur = (slop_option_slop_rdf_rdf_IRI){.has_value = false};
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                __auto_type _mv_990 = cur;
                if (_mv_990.has_value) {
                    __auto_type p = _mv_990.value;
                    if (howl_canon_iri_cmp(p, howl_canon_iri_at(ps, k)) != 0) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_decode_undeclared_of(p, refs)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        refs = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    }
                } else if (!_mv_990.has_value) {
                }
                cur = (slop_option_slop_rdf_rdf_IRI){.has_value = 1, .value = howl_canon_iri_at(ps, k)};
                (void)(({ __auto_type _lst_p = &(refs); __auto_type _item = (howl_canon_str_at(texts, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        __auto_type _mv_991 = cur;
        if (_mv_991.has_value) {
            __auto_type p = _mv_991.value;
            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_decode_undeclared_of(p, refs)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (!_mv_991.has_value) {
        }
        return out;
    }
}

howl_types_Omission howl_decode_undeclared_of(slop_rdf_rdf_IRI p, slop_list_string refs) {
    return ((howl_types_Omission){ .tag = howl_types_Omission_undeclared_property, .data.undeclared_property = ((howl_types_UndeclaredProperty){.property = p, .referring = refs}) });
}

howl_decode_DataVocab howl_decode_data_vocab(slop_arena* arena, howl_termstore_TermStore dict) {
    return ((howl_decode_DataVocab){.rdf_type = dict.rdf_type, .data_property = howl_decode_vocab_id(arena, dict, slop_rdf_vocab_OWL_DATATYPE_PROPERTY), .functional = howl_decode_vocab_id(arena, dict, slop_rdf_vocab_OWL_FUNCTIONAL_PROPERTY), .domain = howl_decode_vocab_id(arena, dict, slop_rdf_vocab_RDFS_DOMAIN), .range = howl_decode_vocab_id(arena, dict, slop_rdf_vocab_RDFS_RANGE), .sub_property = howl_decode_vocab_id(arena, dict, slop_rdf_vocab_RDFS_SUBPROPERTY_OF), .equivalent = howl_decode_vocab_id(arena, dict, slop_rdf_vocab_OWL_EQUIVALENT_PROPERTY), .disjoint = howl_decode_vocab_id(arena, dict, slop_rdf_vocab_OWL_PROPERTY_DISJOINT_WITH), .top = howl_decode_vocab_id(arena, dict, slop_rdf_vocab_OWL_TOP_DATA_PROPERTY), .on_datatype = howl_decode_vocab_id(arena, dict, slop_rdf_vocab_OWL_ON_DATATYPE)});
}

uint8_t howl_decode_promote_use(howl_decode_DataVocab v, slop_map* used, howl_termstore_IdTriple it) {
    {
        uint8_t changed = 0;
        if ((((it.p == v.sub_property) || (it.p == v.equivalent))) && (slop_map_has(used, &(int64_t){it.s})) && (!(slop_map_has(used, &(int64_t){it.o})))) {
            (void)(({ slop_map_put(NULL, used, &(int64_t){it.o}, NULL, 0); }));
            changed = 1;
        }
        if (((it.p == v.equivalent)) && (slop_map_has(used, &(int64_t){it.o})) && (!(slop_map_has(used, &(int64_t){it.s})))) {
            (void)(({ slop_map_put(NULL, used, &(int64_t){it.s}, NULL, 0); }));
            changed = 1;
        }
        return changed;
    }
}

uint8_t howl_decode_promote_uses(howl_decode_DataVocab v, slop_map* data, slop_map* used, slop_list_howl_termstore_IdTriple triples) {
    {
        uint8_t changed = 0;
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if ((slop_map_has(data, &(int64_t){it.s})) && (slop_map_has(data, &(int64_t){it.o})) && (howl_decode_promote_use(v, used, it))) {
                    changed = 1;
                }
            }
        }
        return changed;
    }
}

void howl_decode_collect_idle(howl_decode_DataVocab v, slop_map* used, slop_map* idle, int64_t bottom, slop_list_howl_termstore_IdTriple triples) {
    {
        __auto_type _coll = triples;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type it = _coll.data[_i];
            if (((it.p == v.rdf_type)) && ((it.o == v.data_property)) && (!(slop_map_has(used, &(int64_t){it.s})))) {
                (void)(({ slop_map_put(NULL, idle, &(int64_t){it.s}, NULL, 0); }));
            }
        }
    }
    if ((bottom >= 0) && !(slop_map_has(used, &(int64_t){bottom}))) {
        (void)(({ slop_map_put(NULL, idle, &(int64_t){bottom}, NULL, 0); }));
    }
}

howl_decode_DataLemma howl_decode_data_lemma(slop_arena* arena, howl_termstore_TermStore dict, howl_owl2_Signature sig, howl_decode_DataVocab v, slop_list_howl_termstore_IdTriple triples) {
    {
        __auto_type data = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type used = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type idle = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type tree = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type bottom = howl_decode_vocab_id(arena, dict, slop_rdf_vocab_OWL_BOTTOM_DATA_PROPERTY);
        uint8_t any = 0;
        uint8_t changed = 1;
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if ((it.p == v.rdf_type) && (it.o == v.data_property)) {
                    (void)(({ slop_map_put(NULL, data, &(int64_t){it.s}, NULL, 0); }));
                    any = 1;
                }
            }
        }
        if (v.top >= 0) {
            (void)(({ slop_map_put(NULL, data, &(int64_t){v.top}, NULL, 0); }));
            (void)(({ slop_map_put(NULL, used, &(int64_t){v.top}, NULL, 0); }));
            any = 1;
        }
        if (bottom >= 0) {
            (void)(({ slop_map_put(NULL, data, &(int64_t){bottom}, NULL, 0); }));
            any = 1;
        }
        if (any) {
            {
                __auto_type _coll = triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type it = _coll.data[_i];
                    howl_decode_mark_data_uses(dict, sig, v, data, used, it);
                }
            }
            while (changed) {
                changed = howl_decode_promote_uses(v, data, used, triples);
            }
            howl_decode_collect_idle(v, used, idle, bottom, triples);
            howl_decode_collect_inert_trees(arena, dict, v, idle, tree, triples);
        }
        return ((howl_decode_DataLemma){.data = data, .idle = idle, .tree = tree});
    }
}

void howl_decode_mark_data_uses(howl_termstore_TermStore dict, howl_owl2_Signature sig, howl_decode_DataVocab v, slop_map* data, slop_map* used, howl_termstore_IdTriple it) {
    {
        __auto_type s = it.s;
        __auto_type p = it.p;
        __auto_type o = it.o;
        if (p == v.rdf_type) {
            if (slop_map_has(data, &(int64_t){o})) {
                (void)(({ slop_map_put(NULL, used, &(int64_t){o}, NULL, 0); }));
            }
            if ((slop_map_has(data, &(int64_t){s})) && (!((o == v.data_property))) && (!((o == v.functional)))) {
                (void)(({ slop_map_put(NULL, used, &(int64_t){s}, NULL, 0); }));
            }
        } else if (howl_decode_predicate_is_annotation(dict, sig, p)) {
        } else if ((p == v.domain) || (p == v.range)) {
            if (slop_map_has(data, &(int64_t){o})) {
                (void)(({ slop_map_put(NULL, used, &(int64_t){o}, NULL, 0); }));
            }
        } else if ((((p == v.sub_property) || ((p == v.equivalent) || (p == v.disjoint)))) && (slop_map_has(data, &(int64_t){s})) && (slop_map_has(data, &(int64_t){o}))) {
        } else {
            if (slop_map_has(data, &(int64_t){s})) {
                (void)(({ slop_map_put(NULL, used, &(int64_t){s}, NULL, 0); }));
            }
            if (slop_map_has(data, &(int64_t){p})) {
                (void)(({ slop_map_put(NULL, used, &(int64_t){p}, NULL, 0); }));
            }
            if (slop_map_has(data, &(int64_t){o})) {
                (void)(({ slop_map_put(NULL, used, &(int64_t){o}, NULL, 0); }));
            }
        }
    }
}

uint8_t howl_decode_predicate_is_annotation(howl_termstore_TermStore dict, howl_owl2_Signature sig, int64_t p) {
    __auto_type _mv_1022 = howl_decode_term_iri_value(howl_termstore_term_of(dict, p));
    if (_mv_1022.has_value) {
        __auto_type i = _mv_1022.value;
        return howl_owl2_signature_has_annotation_property(sig, i);
    } else if (!_mv_1022.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

void howl_decode_collect_inert_trees(slop_arena* arena, howl_termstore_TermStore dict, howl_decode_DataVocab v, slop_map* idle, slop_map* tree, slop_list_howl_termstore_IdTriple triples) {
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
                if (howl_decode_id_is_blank(dict, it.o)) {
                    if (slop_map_has(once, &(int64_t){it.o})) {
                        (void)(({ slop_map_put(NULL, twice, &(int64_t){it.o}, NULL, 0); }));
                    } else {
                        (void)(({ slop_map_put(NULL, once, &(int64_t){it.o}, NULL, 0); }));
                    }
                }
                if (slop_map_has(heads, &(int64_t){it.s})) {
                    (void)(({ slop_map_put(NULL, heads_two, &(int64_t){it.s}, NULL, 0); }));
                } else {
                    (void)(({ slop_map_put(NULL, heads, &(int64_t){it.s}, NULL, 0); }));
                }
                if (it.p == v.on_datatype) {
                    (void)(({ slop_map_put(NULL, restricts, &(int64_t){it.s}, NULL, 0); }));
                }
            }
        }
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (howl_decode_id_is_blank(dict, it.s) && !(howl_decode_filler_triple(howl_termstore_triple_of(dict, it), slop_map_has(restricts, &(int64_t){it.s}), !(slop_map_has(heads_two, &(int64_t){it.s}))))) {
                    (void)(({ slop_map_put(NULL, impure, &(int64_t){it.s}, NULL, 0); }));
                }
            }
        }
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if ((((it.p == v.domain) || (it.p == v.range))) && (slop_map_has(idle, &(int64_t){it.s})) && (slop_map_has(once, &(int64_t){it.o})) && (!(slop_map_has(twice, &(int64_t){it.o}))) && (!(slop_map_has(impure, &(int64_t){it.o})))) {
                    (void)(({ slop_map_put(NULL, tree, &(int64_t){it.o}, NULL, 0); }));
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
                        (void)(({ slop_map_put(NULL, tree, &(int64_t){it.o}, NULL, 0); }));
                        changed = 1;
                    }
                }
            }
        }
    }
}

uint8_t howl_decode_filler_triple(slop_rdf_rdf_Triple t, uint8_t restriction, uint8_t single) {
    return (howl_decode_structural_triple(t) || ({ __auto_type _mv = howl_decode_term_iri_value(t.predicate); _mv.has_value ? ({ __auto_type p = _mv.value; ((howl_canon_string_cmp(p.value, slop_rdf_vocab_OWL_WITH_RESTRICTIONS) == 0) ? restriction : ((howl_canon_string_cmp(p.value, slop_rdf_vocab_RDF_LANG_RANGE) == 0) ? single : (std_strlib_starts_with(p.value, slop_rdf_vocab_XSD_NS) ? single : ((howl_canon_string_cmp(p.value, slop_rdf_vocab_RDF_TYPE) == 0) ? ({ __auto_type _mv = howl_decode_term_iri_value(t.object); _mv.has_value ? ({ __auto_type o = _mv.value; ((howl_canon_string_cmp(o.value, slop_rdf_vocab_RDFS_DATATYPE) == 0) || (howl_canon_string_cmp(o.value, slop_rdf_vocab_OWL_DATA_RANGE) == 0)); }) : (0); }) : 0)))); }) : (0); }));
}

uint8_t howl_decode_id_is_blank(howl_termstore_TermStore dict, int64_t id) {
    __auto_type _mv_1044 = howl_termstore_term_of(dict, id);
    switch (_mv_1044.tag) {
        case slop_rdf_rdf_Term_term_blank:
        {
            __auto_type _ = _mv_1044.data.term_blank;
            return 1;
        }
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type _ = _mv_1044.data.term_iri;
            return 0;
        }
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type _ = _mv_1044.data.term_literal;
            return 0;
        }
        case slop_rdf_rdf_Term_term_triple:
        {
            __auto_type _ = _mv_1044.data.term_triple;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_decode_inert_data_axiom(howl_decode_DataVocab v, howl_decode_DataLemma lemma, howl_termstore_IdTriple it) {
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

slop_map* howl_decode_negative_assertion_nodes(slop_arena* arena, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples) {
    {
        __auto_type npa = howl_decode_vocab_id(arena, dict, slop_rdf_vocab_OWL_NEGATIVE_PROPERTY_ASSERTION);
        __auto_type type_pred = dict.rdf_type;
        __auto_type out = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        if (npa >= 0) {
            {
                __auto_type _coll = triples;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type it = _coll.data[_i];
                    if ((it.p == type_pred) && (it.o == npa)) {
                        (void)(({ slop_map_put(NULL, out, &(int64_t){it.s}, NULL, 0); }));
                    }
                }
            }
        }
        return out;
    }
}

slop_map* howl_decode_negative_assertion_parts(slop_arena* arena, howl_termstore_TermStore dict) {
    {
        __auto_type out = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 4 * sizeof(slop_string)), .len = 4, .cap = 4, .arena = arena }; _ll.data[0] = slop_rdf_vocab_OWL_SOURCE_INDIVIDUAL; _ll.data[1] = slop_rdf_vocab_OWL_ASSERTION_PROPERTY; _ll.data[2] = slop_rdf_vocab_OWL_TARGET_INDIVIDUAL; _ll.data[3] = slop_rdf_vocab_OWL_TARGET_VALUE; _ll; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type iri = _coll.data[_i];
                {
                    __auto_type id = howl_decode_vocab_id(arena, dict, iri);
                    if (id >= 0) {
                        (void)(({ slop_map_put(NULL, out, &(int64_t){id}, NULL, 0); }));
                    }
                }
            }
        }
        return out;
    }
}

uint8_t howl_decode_negative_assertion_part(howl_termstore_IdTriple it, slop_map* nodes, slop_map* parts) {
    return (slop_map_has(parts, &(int64_t){it.p}) && slop_map_has(nodes, &(int64_t){it.s}));
}

int64_t howl_decode_property_kinds(howl_owl2_Signature sig, slop_rdf_rdf_IRI e) {
    return (((howl_owl2_signature_has_object_property(sig, e)) ? 1 : 0) + (((howl_owl2_signature_has_data_property(sig, e)) ? 1 : 0) + ((howl_owl2_signature_has_annotation_property(sig, e)) ? 1 : 0)));
}

slop_option_string howl_decode_declaration_conflict(slop_arena* arena, howl_owl2_Signature sig, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples) {
    {
        __auto_type type_pred = dict.rdf_type;
        slop_option_string bad = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (it.p == type_pred) {
                    __auto_type _mv_1060 = howl_decode_term_iri_value(howl_termstore_term_of(dict, it.s));
                    if (_mv_1060.has_value) {
                        __auto_type e = _mv_1060.value;
                        if (howl_decode_property_kinds(sig, e) > 1) {
                            bad = (slop_option_string){.has_value = 1, .value = string_concat(arena, SLOP_STR("IRI declared under two disjoint property kinds: "), e.value)};
                        }
                    } else if (!_mv_1060.has_value) {
                    }
                }
            }
        }
        return bad;
    }
}

