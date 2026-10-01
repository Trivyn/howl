#include "../runtime/slop_runtime.h"
#include "slop_test.h"

types_Saturation test_empty_saturation(slop_arena* arena);
types_Findings test_make_findings(slop_arena* arena, uint8_t inconsistent, int64_t unsat_count);
types_Outcome test_make_outcome(slop_arena* arena, uint8_t inconsistent, int64_t unsat_count, int64_t omitted_count, uint8_t reached_fixpoint);
uint8_t test_verdict_eq(howl_Verdict a, howl_Verdict b);
uint8_t test_test_coherent_requires_complete(slop_arena* arena);
uint8_t test_test_omission_blocks_coherent(slop_arena* arena);
uint8_t test_test_cap_blocks_coherent(slop_arena* arena);
uint8_t test_test_finding_beats_partial_coverage(slop_arena* arena);
uint8_t test_test_consistent_but_incoherent(slop_arena* arena);
uint8_t test_test_context_starts_with_empty_store(slop_arena* arena);
slop_string test_node_iri(types_Node n);
uint8_t test_test_emit_edge_addresses_both_halves(slop_arena* arena);
slop_option_types_Outcome test_classify_fixture(slop_arena* arena, slop_string path);
slop_option_types_Outcome test_classify_fixture_with(slop_arena* arena, slop_string path, int64_t workers, int64_t cap);
uint8_t test_workers_agree(slop_arena* arena, slop_string path, int64_t cap);
uint8_t test_test_worker_count_does_not_change_the_report(slop_arena* arena);
types_Context test_edge_context(slop_arena* arena, types_Node n, types_RoleId r, types_Node m, uint8_t succ);
uint8_t test_queue_has(types_Saturation sat, types_Node n, types_Derived d);
uint8_t test_stored_edge(types_Saturation sat, types_Node x, types_RoleId r, types_Node y);
int64_t test_queue_len(types_Saturation sat, types_Node n);
uint8_t test_test_commit_dedups_across_deltas(slop_arena* arena);
uint8_t test_test_names_round_trip(slop_arena* arena);
uint8_t test_same_renamed(types_Names names, types_Node n, types_Node expect);
uint8_t test_test_litmus_end_to_end(slop_arena* arena);
uint8_t test_test_role_hierarchy_carries_edges(slop_arena* arena);
uint8_t test_test_role_closure_deep(slop_arena* arena);
uint8_t test_test_smaller_side_joins(slop_arena* arena);
uint8_t test_test_unattested_import_is_inconclusive(slop_arena* arena);
uint8_t test_test_declared_unused_class_gets_a_context(slop_arena* arena);
uint8_t test_test_abox_disjoint_range_is_incoherent(slop_arena* arena);
int64_t test_omitted_count(types_Outcome o);
uint8_t test_test_undeclared_individual_is_reasoned_over(slop_arena* arena);
uint8_t test_test_anonymous_class_assertion_is_read(slop_arena* arena);
uint8_t test_test_annotation_on_annotation_is_consumed(slop_arena* arena);
uint8_t test_test_logical_triple_on_header_node_is_not_swallowed(slop_arena* arena);
uint8_t test_test_repeated_disjoint_member_is_positional(slop_arena* arena);
uint8_t test_report_entails(types_Findings f, types_Node a, types_Node b);
uint8_t test_probe_agrees_with_report(slop_arena* arena, slop_string path);
uint8_t test_test_entails_sub_agrees_with_report(slop_arena* arena);
types_Node test_cls(slop_string name);
types_RoleId test_rol(slop_string name);
slop_result_saturate_RoundResult_types_Fault test_run_fixture(slop_arena* arena, slop_list_types_Node signature, slop_list_types_NormAxiom axioms);
slop_list_types_Node test_litmus_signature(slop_arena* arena);
slop_list_types_NormAxiom test_litmus_axioms(slop_arena* arena, uint8_t correct_polarity);
uint8_t test_litmus_derives_parent(slop_arena* arena, uint8_t correct_polarity);
uint8_t test_test_litmus(slop_arena* arena);
uint8_t test_test_polarity_guard(slop_arena* arena);
uint8_t test_test_cyclic_hierarchy_terminates(slop_arena* arena);
uint8_t test_test_same_round_co_arrival(slop_arena* arena);
uint8_t test_test_late_subsumer_still_concludes(slop_arena* arena);
slop_result_saturate_RoundResult_types_Fault test_unsat_fixture(slop_arena* arena);
uint8_t test_test_unsatisfiable_class_detected(slop_arena* arena);
uint8_t test_test_bottom_compression(slop_arena* arena);
uint8_t test_test_inconsistency_suppresses_both_lists(slop_arena* arena);
uint8_t test_test_derived_eq_compares_both_payloads(slop_arena* arena);
uint8_t test_test_order_independence(slop_arena* arena);
rdf_IRI test_mk_iri(slop_string v);
uint8_t test_test_string_cmp_is_length_safe(slop_arena* arena);
uint8_t test_test_node_cmp_separates_punned_iris(slop_arena* arena);
uint8_t test_test_sort_orders_and_is_input_determined(slop_arena* arena);
rdf_Term test_ex_iri(slop_arena* arena, slop_string local);
int64_t test_count_subclass_triples(slop_list_rdf_Triple ts, rdf_Term pred);
uint8_t test_test_unattested_import_yields_an_omission(slop_arena* arena);
uint8_t test_test_attested_import_yields_none(slop_arena* arena);
uint8_t test_test_term_store_by_content(slop_arena* arena);
uint8_t test_test_term_store_quoted_and_tagged(slop_arena* arena);
slop_list_rdf_Triple test_stage0_triples(slop_arena* arena, decode_Stage0 s0);
slop_list_string test_decode_rendered(slop_arena* arena, slop_result_decode_Stage1_types_Fault r);
uint8_t test_decode_store_agrees(slop_arena* arena, slop_string path);
uint8_t test_test_decode_store_answers_as_the_full_store(slop_arena* arena);
slop_string test_stage0_fault_of(slop_arena* arena, slop_list_rdf_Triple ts);
uint8_t test_test_stage0_fault_follows_the_document(slop_arena* arena);
uint8_t test_test_stage0_rebuild_checks_the_whole_input(slop_arena* arena);
uint8_t test_test_header_and_reification_are_consumed(slop_arena* arena);
int64_t test_count_out_of_profile(slop_list_owl2_RawAxiom axs);
int64_t test_count_disposition(slop_list_owl2_RawAxiom axs, owl2_Disposition want);
slop_option_decode_Stage1 test_decode_fixture(slop_arena* arena, slop_string path);
int64_t test_nary_disjoint_member_count(slop_list_owl2_RawAxiom axs);
uint8_t test_test_nary_disjointness_keeps_its_members(slop_arena* arena);
int64_t test_out_of_profile_count_of(slop_arena* arena, slop_string path);
uint8_t test_test_v0_corpus_decodes_clean(slop_arena* arena);
uint8_t test_test_out_of_profile_corpus_is_caught(slop_arena* arena);
uint8_t test_test_annotation_heavy_decodes_clean(slop_arena* arena);
uint8_t test_test_litmus_decodes_clean(slop_arena* arena);
uint8_t test_test_missing_class_declaration_is_reported(slop_arena* arena);
uint8_t test_test_undeclared_individual_is_not_reported(slop_arena* arena);
int64_t test_accepted_count_of_ttl(slop_arena* arena, slop_string ttl);
uint8_t test_test_reserved_iri_as_individual_is_out_of_profile(slop_arena* arena);
uint8_t test_test_annotation_property_axioms_are_inert(slop_arena* arena);
uint8_t test_decodes_ok(slop_arena* arena, slop_string ttl);
uint8_t test_test_undeclared_property_is_an_input_error(slop_arena* arena);
uint8_t test_test_unknown_owl_vocabulary_still_decodes(slop_arena* arena);
uint8_t test_test_conflicting_declarations_are_an_input_error(slop_arena* arena);
slop_option_gate_GateResult test_gate_ttl(slop_arena* arena, slop_string ttl);
slop_option_gate_GateResult test_gate_ttl_in(slop_arena* arena, slop_string ttl, types_Profile p);
int64_t test_gate_omissions_of_ttl(slop_arena* arena, slop_string ttl);
slop_string test_gate_accepted_of_ttl(slop_arena* arena, slop_string ttl);
slop_string test_rc_prefix(void);
uint8_t test_test_range_composition_table(slop_arena* arena);
slop_string test_rung_prefix(void);
int64_t test_omissions_under(slop_arena* arena, slop_string ttl, types_Profile p);
uint8_t test_rungs_omit(slop_arena* arena, slop_string label, slop_string ttl, int64_t el_want, int64_t elpp_want);
uint8_t test_test_el_plus_plus_gate_table(slop_arena* arena);
uint8_t test_test_top_role_tautology_is_dropped(slop_arena* arena);
slop_string test_ksc_form_of_ttl(slop_arena* arena, slop_string ttl);
uint8_t test_ksc_form_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
uint8_t test_test_ksc_normal_form_rows(slop_arena* arena);
slop_string test_omissions_of_ttl(slop_arena* arena, slop_string ttl);
uint8_t test_omits_exactly(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
slop_string test_eq_prefix(void);
uint8_t test_test_equality_never_drops_an_operand(slop_arena* arena);
uint8_t test_test_anonymous_members_are_omissions_not_faults(slop_arena* arena);
uint8_t test_test_negative_assertion_decodes_whole(slop_arena* arena);
uint8_t test_test_literal_has_value_is_data(slop_arena* arena);
slop_string test_neg_prefix(void);
uint8_t test_accepts_exactly(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
uint8_t test_test_negation_rewrites_to_bottom_gcis(slop_arena* arena);
uint8_t test_test_negation_rewrites_whole_axioms_or_none(slop_arena* arena);
uint8_t test_test_negative_range_normalizes_to_bottom(slop_arena* arena);
uint8_t test_norm_eq(types_NormAxiom a, types_NormAxiom b);
uint8_t test_norm_contains(slop_list_types_NormAxiom xs, types_NormAxiom a);
slop_option_normalize_NormOutput test_normalize_fixture(slop_arena* arena, slop_string path);
uint8_t test_test_litmus_reproduces_the_m1_normal_form(slop_arena* arena);
uint8_t test_test_normalization_polarity_is_negative_on_the_left(slop_arena* arena);
uint8_t test_test_range_elimination_introduces_a_shared_filler(slop_arena* arena);
uint8_t test_test_asserted_edges_seed_their_range(slop_arena* arena);
uint8_t test_test_range_complex_fillers_stay_apart(slop_arena* arena);
uint8_t test_complex_range_fillers_distinct(slop_arena* arena, slop_string path);
uint8_t test_test_inverse_expressions_are_omissions(slop_arena* arena);
slop_list_string test_m0_fixture_paths(slop_arena* arena);
uint8_t test_accounting_exempt(owl2_RawAxiom ax);
uint8_t test_axiom_accounted(slop_arena* arena, owl2_RawAxiom ax);
uint8_t test_test_accounting_holds(slop_arena* arena);
uint8_t test_same_rendering(slop_arena* arena, slop_list_owl2_RawAxiom xs, slop_list_owl2_RawAxiom ys);
uint8_t test_test_canonicalization_is_idempotent(slop_arena* arena);
slop_list_types_Node test_norm_nodes(slop_arena* arena, types_NormAxiom ax);
uint8_t test_fresh_ids_dense(slop_arena* arena, normalize_NormOutput no);
uint8_t test_test_fresh_nodes_are_fresh(slop_arena* arena);
slop_list_rdf_Triple test_reversed_triples(slop_arena* arena, slop_list_rdf_Triple ts);
slop_option_normalize_NormOutput test_normalize_triples(slop_arena* arena, slop_list_rdf_Triple ts);
uint8_t test_same_normal_form(normalize_NormOutput a, normalize_NormOutput b);
uint8_t test_same_report(types_Outcome a, types_Outcome b);
uint8_t test_same_lines(slop_list_string a, slop_list_string b);
uint8_t test_order_independent(slop_arena* arena, slop_string path);
uint8_t test_test_triple_order_independence(slop_arena* arena);
uint8_t test_addressed_subset(slop_list_types_Addressed xs, slop_list_types_Addressed ys);
uint8_t test_same_conclusions(slop_arena* arena, types_Context ctx, types_Derived d, premise_RuleIndex idx, slop_list_types_NormAxiom axioms);
uint8_t test_dispatch_agrees(slop_arena* arena, slop_string path);
uint8_t test_test_indexed_dispatch_matches_reference(slop_arena* arena);
uint8_t test_test_quoted_triple_header_subjects(slop_arena* arena);
int64_t test_strict_outcome(slop_arena* arena, slop_string path);
slop_result_types_Profile_types_Profile test_profile_run(slop_arena* arena, types_ProfileSelection selection);
uint8_t test_ran_as(slop_result_types_Profile_types_Profile r, types_Profile want);
uint8_t test_refused_as(slop_result_types_Profile_types_Profile r, types_Profile want);
uint8_t test_test_profile_selection(slop_arena* arena);
uint8_t test_test_profile_names_round_trip(slop_arena* arena);
uint8_t test_name_round_trips(types_Profile p);
uint8_t test_test_strict_refuses_past_omissions(slop_arena* arena);
uint8_t test_test_nary_chain_decomposes_left_associated(slop_arena* arena);
slop_option_u8 test_regularity_of(slop_arena* arena, slop_string path);
uint8_t test_test_regularity_rejects_mutual_recursion(slop_arena* arena);
uint8_t test_test_regularity_accepts_equivalence_and_transitivity(slop_arena* arena);
uint8_t test_test_regularity_accepts_plain_subproperty(slop_arena* arena);
uint8_t test_test_regularity_accepts_nary_chain(slop_arena* arena);
uint8_t test_test_irregular_rbox_is_omitted_whole(slop_arena* arena);
slop_option_gate_GateResult test_gate_fixture(slop_arena* arena, slop_string path);
slop_option_gate_GateResult test_gate_fixture_in(slop_arena* arena, slop_string path, types_Profile p);
int64_t test_count_variant_chain(slop_list_owl2_RawAxiom axs);
int64_t test_count_variant_disjoint(slop_list_owl2_RawAxiom axs);
int64_t test_count_variant_subclass(slop_list_owl2_RawAxiom axs);
uint8_t test_test_gate_annotation_heavy_is_clean(slop_arena* arena);
uint8_t test_test_gate_carries_import_omissions(slop_arena* arena);
uint8_t test_test_sugar_transitivity_becomes_a_chain(slop_arena* arena);
uint8_t test_test_sugar_nary_disjointness_becomes_pairs(slop_arena* arena);
uint8_t test_test_sugar_equivalence_is_a_star_not_all_pairs(slop_arena* arena);
int64_t test_gate_omission_count(slop_arena* arena, slop_string path);
uint8_t test_test_gate_accepts_every_v0_fixture(slop_arena* arena);
uint8_t test_test_gate_rejects_every_out_of_profile_fixture(slop_arena* arena);
slop_option_owl2_Signature test_signature_of_fixture(slop_arena* arena, slop_string path);
uint8_t test_test_declared_unused_class_reaches_the_signature(slop_arena* arena);
uint8_t test_test_builtins_are_declared(slop_arena* arena);
uint8_t test_test_custom_annotation_property_is_recognized(slop_arena* arena);
uint8_t test_is_named_class(owl2_RawConcept c, slop_string iri);
uint8_t test_is_some_person(owl2_RawConcept c, slop_string role_iri, slop_string filler_iri);
uint8_t test_test_decode_litmus_class_expression(slop_arena* arena);
uint8_t test_test_decode_represents_out_of_profile_rather_than_failing(slop_arena* arena);
uint8_t test_test_decode_blank_node_cycle_is_bounded(slop_arena* arena);
uint8_t test_test_rdf_list_well_formed(slop_arena* arena);
uint8_t test_test_rdf_list_truncation_is_a_fault(slop_arena* arena);
uint8_t test_test_rdf_list_cycle_terminates(slop_arena* arena);
uint8_t test_test_rdf_list_branching_is_a_fault(slop_arena* arena);
uint8_t test_test_sort_is_stable(slop_arena* arena);
uint8_t test_test_sort_is_a_permutation(slop_arena* arena);
void test_print_test_result(slop_string name, uint8_t passed);
int main(int argc, char** _c_argv);

static int64_t test__lambda_873(void* _env, int64_t a, int64_t b) { return ({ __auto_type ka = (2 - (a / 3)); __auto_type kb = (2 - (b / 3)); ((ka < kb) ? -1 : ((ka > kb) ? 1 : 0)); }); }

types_Saturation test_empty_saturation(slop_arena* arena) {
    return ((types_Saturation){.contexts = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, types_Context); slop_map_new_ptr(arena, 0, &_d); }), .queues = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, types_Queue); slop_map_new_ptr(arena, 0, &_d); }), .active = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .active_count = 0, .iteration = 0});
}

types_Findings test_make_findings(slop_arena* arena, uint8_t inconsistent, int64_t unsat_count) {
    {
        __auto_type unsat = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 });
        if (unsat_count > 0) {
            ({ __auto_type _lst_p = &(unsat); __auto_type _item = (((rdf_IRI){.value = SLOP_STR("http://example.org/Unsat")})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return ((types_Findings){.inconsistent = inconsistent, .unsatisfiable = unsat, .subsumptions = ((slop_list_types_SubPair){ .data = NULL, .len = 0, .cap = 0 }), .imports_seen = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 })});
    }
}

types_Outcome test_make_outcome(slop_arena* arena, uint8_t inconsistent, int64_t unsat_count, int64_t omitted_count, uint8_t reached_fixpoint) {
    {
        __auto_type omitted = ((slop_list_types_Omission){ .data = NULL, .len = 0, .cap = 0 });
        if (omitted_count > 0) {
            ({ __auto_type _lst_p = &(omitted); __auto_type _item = (((types_Omission){ .tag = types_Omission_unresolved_import, .data.unresolved_import = ((rdf_IRI){.value = SLOP_STR("http://example.org/missing-import")}) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return ((types_Outcome){.profile = types_Profile_profile_el, .coverage = ((types_Coverage){.omitted = omitted}), .termination = ((reached_fixpoint) ? ((types_Termination){ .tag = types_Termination_fixpoint }) : ((types_Termination){ .tag = types_Termination_resource_limit, .data.resource_limit = 1000 })), .findings = test_make_findings(arena, inconsistent, unsat_count), .saturation = test_empty_saturation(arena), .names = types_empty_names(arena)});
    }
}

uint8_t test_verdict_eq(howl_Verdict a, howl_Verdict b) {
    return (a == b);
}

uint8_t test_test_coherent_requires_complete(slop_arena* arena) {
    return test_verdict_eq(howl_verdict(test_make_outcome(arena, 0, 0, 0, 1)), howl_Verdict_verdict_coherent);
}

uint8_t test_test_omission_blocks_coherent(slop_arena* arena) {
    return test_verdict_eq(howl_verdict(test_make_outcome(arena, 0, 0, 1, 1)), howl_Verdict_verdict_inconclusive);
}

uint8_t test_test_cap_blocks_coherent(slop_arena* arena) {
    return test_verdict_eq(howl_verdict(test_make_outcome(arena, 0, 0, 0, 0)), howl_Verdict_verdict_inconclusive);
}

uint8_t test_test_finding_beats_partial_coverage(slop_arena* arena) {
    return test_verdict_eq(howl_verdict(test_make_outcome(arena, 1, 0, 1, 0)), howl_Verdict_verdict_incoherent);
}

uint8_t test_test_consistent_but_incoherent(slop_arena* arena) {
    return (test_verdict_eq(howl_verdict(test_make_outcome(arena, 0, 1, 0, 1)), howl_Verdict_verdict_incoherent) && types_findings_are_incoherent(test_make_findings(arena, 0, 1)));
}

uint8_t test_test_context_starts_with_empty_store(slop_arena* arena) {
    {
        __auto_type ctx = types_make_context(arena, ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = SLOP_STR("http://example.org/C")}) }));
        return (((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, ctx.subsumers); (slop_list_types_Node){.data = (types_Node*)_r.data, .len = _r.len, .cap = _r.cap}; })).len)) == 0);
    }
}

slop_string test_node_iri(types_Node n) {
    __auto_type _mv_674 = n;
    switch (_mv_674.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_674.data.class_node;
            return i.value;
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_674.data.individual_node;
            return i.value;
        }
        case types_Node_fresh_node:
        {
            __auto_type _ = _mv_674.data.fresh_node;
            return SLOP_STR("");
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_emit_edge_addresses_both_halves(slop_arena* arena) {
    {
        __auto_type x = ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = SLOP_STR("http://example.org/X")}) });
        __auto_type y = ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = SLOP_STR("http://example.org/Y")}) });
        __auto_type r = ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = ((rdf_IRI){.value = SLOP_STR("http://example.org/r")}) });
        __auto_type pair = types_emit_edge(arena, ((types_LogicalEdge){.from = x, .role = r, .to = y}));
        if (string_eq(test_node_iri(pair.succ_half.to), SLOP_STR("http://example.org/X"))) {
            return string_eq(test_node_iri(pair.pred_half.to), SLOP_STR("http://example.org/Y"));
        } else {
            return 0;
        }
    }
}

slop_option_types_Outcome test_classify_fixture(slop_arena* arena, slop_string path) {
    __auto_type _mv_675 = ttl_parse_ttl_file(arena, path);
    if (!_mv_675.is_ok) {
        __auto_type _ = _mv_675.data.err;
        return (slop_option_types_Outcome){.has_value = false};
    } else if (_mv_675.is_ok) {
        __auto_type g = _mv_675.data.ok;
        __auto_type _mv_676 = howl_classify(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }), howl_default_config());
        if (!_mv_676.is_ok) {
            __auto_type _ = _mv_676.data.err;
            return (slop_option_types_Outcome){.has_value = false};
        } else if (_mv_676.is_ok) {
            __auto_type o = _mv_676.data.ok;
            return (slop_option_types_Outcome){.has_value = 1, .value = o};
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_option_types_Outcome test_classify_fixture_with(slop_arena* arena, slop_string path, int64_t workers, int64_t cap) {
    {
        __auto_type cfg = howl_default_config();
        cfg.worker_count = ((uint8_t)(workers));
        cfg.max_iterations = ((uint16_t)(cap));
        __auto_type _mv_677 = ttl_parse_ttl_file(arena, path);
        if (!_mv_677.is_ok) {
            __auto_type _ = _mv_677.data.err;
            return (slop_option_types_Outcome){.has_value = false};
        } else if (_mv_677.is_ok) {
            __auto_type g = _mv_677.data.ok;
            __auto_type _mv_678 = howl_classify(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }), cfg);
            if (!_mv_678.is_ok) {
                __auto_type _ = _mv_678.data.err;
                return (slop_option_types_Outcome){.has_value = false};
            } else if (_mv_678.is_ok) {
                __auto_type o = _mv_678.data.ok;
                return (slop_option_types_Outcome){.has_value = 1, .value = o};
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_workers_agree(slop_arena* arena, slop_string path, int64_t cap) {
    __auto_type _mv_679 = test_classify_fixture_with(arena, path, 1, cap);
    if (!_mv_679.has_value) {
        return 0;
    } else if (_mv_679.has_value) {
        __auto_type one = _mv_679.value;
        __auto_type _mv_680 = test_classify_fixture_with(arena, path, 4, cap);
        if (!_mv_680.has_value) {
            return 0;
        } else if (_mv_680.has_value) {
            __auto_type four = _mv_680.value;
            return test_same_lines(report_report_lines(arena, one), report_report_lines(arena, four));
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_worker_count_does_not_change_the_report(slop_arena* arena) {
    return ((test_workers_agree(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl"), 1000)) && (test_workers_agree(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl"), 1)) && (test_workers_agree(arena, SLOP_STR("corpus/fixtures/hazards/cyclic-hierarchy.ttl"), 1)) && (test_workers_agree(arena, SLOP_STR("corpus/fixtures/hazards/abox-disjoint-range.ttl"), 1)) && (test_workers_agree(arena, SLOP_STR("corpus/fixtures/probes/some-unsat-filler.ttl"), 2)) && (test_workers_agree(arena, SLOP_STR("corpus/fixtures/probes/chain-nary.ttl"), 1000)) && (test_workers_agree(arena, SLOP_STR("corpus/fixtures/hazards/undeclared-filler.ttl"), 1000)) && (test_workers_agree(arena, SLOP_STR("corpus/fixtures/hazards/undeclared-filler.ttl"), 1)));
}

types_Context test_edge_context(slop_arena* arena, types_Node n, types_RoleId r, types_Node m, uint8_t succ) {
    {
        __auto_type c = types_make_context(arena, n);
        __auto_type s = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        ({ slop_map_put(arena, s, &(m), NULL, 0); });
        if (succ) {
            ({ slop_map* _val = s; slop_map_put(arena, c.succs, &(r), &_val, sizeof(_val)); });
        } else {
            ({ slop_map* _val = s; slop_map_put(arena, c.preds, &(r), &_val, sizeof(_val)); });
        }
        return c;
    }
}

uint8_t test_queue_has(types_Saturation sat, types_Node n, types_Derived d) {
    __auto_type _mv_684 = saturate_queue_of(sat, n);
    if (_mv_684.has_value) {
        __auto_type q = _mv_684.value;
        {
            __auto_type found = 0;
            {
                __auto_type _coll = q.items;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type it = _coll.data[_i];
                    if (types_derived_eq(it, d)) {
                        found = 1;
                    }
                }
            }
            return found;
        }
    } else if (!_mv_684.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_stored_edge(types_Saturation sat, types_Node x, types_RoleId r, types_Node y) {
    return (({ __auto_type _mv = saturate_context_of(sat, x); _mv.has_value ? ({ __auto_type cx = _mv.value; ({ __auto_type _mv = ({ void* _ptr = slop_map_get(cx.succs, &(r)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; }); _mv.has_value ? ({ __auto_type s = _mv.value; slop_map_has(s, &(y)); }) : (0); }); }) : (0); }) && ({ __auto_type _mv = saturate_context_of(sat, y); _mv.has_value ? ({ __auto_type cy = _mv.value; ({ __auto_type _mv = ({ void* _ptr = slop_map_get(cy.preds, &(r)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; }); _mv.has_value ? ({ __auto_type s = _mv.value; slop_map_has(s, &(x)); }) : (0); }); }) : (0); }));
}

int64_t test_queue_len(types_Saturation sat, types_Node n) {
    __auto_type _mv_689 = saturate_queue_of(sat, n);
    if (_mv_689.has_value) {
        __auto_type q = _mv_689.value;
        return ((int64_t)(((int64_t)((q.items).len))));
    } else if (!_mv_689.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_commit_dedups_across_deltas(slop_arena* arena) {
    {
        __auto_type x = test_cls(SLOP_STR("http://example.org/X"));
        __auto_type y = test_cls(SLOP_STR("http://example.org/Y"));
        __auto_type p = test_cls(SLOP_STR("http://example.org/P"));
        __auto_type q = test_cls(SLOP_STR("http://example.org/Q"));
        __auto_type r = test_rol(SLOP_STR("http://example.org/r"));
        __auto_type sat = test_empty_saturation(arena);
        __auto_type a = ((saturate_RoundDelta){.pending = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, types_Context); slop_map_new_ptr(arena, 0, &_d); })});
        __auto_type b = ((saturate_RoundDelta){.pending = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, types_Context); slop_map_new_ptr(arena, 0, &_d); })});
        __auto_type ax = test_edge_context(arena, x, r, y, 1);
        __auto_type ay = test_edge_context(arena, y, r, x, 0);
        __auto_type bx = test_edge_context(arena, x, r, y, 1);
        __auto_type by = test_edge_context(arena, y, r, x, 0);
        __auto_type c1 = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        __auto_type c2 = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        __auto_type q1 = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        __auto_type q2 = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        __auto_type ds = ((slop_list_saturate_RoundDelta){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type cas = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type qas = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0 });
        ({ slop_map_put(arena, ax.subsumers, &(p), NULL, 0); });
        ({ slop_map_put(arena, bx.subsumers, &(p), NULL, 0); });
        ({ slop_map_put(arena, bx.subsumers, &(q), NULL, 0); });
        ({ types_Context _val = ax; slop_map_put(arena, a.pending, &(x), &_val, sizeof(_val)); });
        ({ types_Context _val = ay; slop_map_put(arena, a.pending, &(y), &_val, sizeof(_val)); });
        ({ types_Context _val = bx; slop_map_put(arena, b.pending, &(x), &_val, sizeof(_val)); });
        ({ types_Context _val = by; slop_map_put(arena, b.pending, &(y), &_val, sizeof(_val)); });
        ({ __auto_type _lst_p = &(ds); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ds); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(cas); __auto_type _item = (c1); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(cas); __auto_type _item = (c2); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(qas); __auto_type _item = (q1); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(qas); __auto_type _item = (q2); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type next = saturate_commit_round(arena, arena, arena, sat, ds, cas, qas);
            return (((test_queue_len(next, x) == 3)) && ((test_queue_len(next, y) == 1)) && (test_queue_has(next, x, ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = p }))) && (test_queue_has(next, x, ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = q }))) && (test_queue_has(next, x, ((types_Derived){ .tag = types_Derived_derived_succ, .data.derived_succ = { .f0 = r, .f1 = y } }))) && (test_queue_has(next, y, ((types_Derived){ .tag = types_Derived_derived_pred, .data.derived_pred = { .f0 = r, .f1 = x } }))) && (test_stored_edge(next, x, r, y)) && ((next.active_count == 2)) && ((next.iteration == 1)) && (({ __auto_type _mv = saturate_context_of(next, x); _mv.has_value ? ({ __auto_type cx = _mv.value; (slop_map_has(cx.subsumers, &(p)) && slop_map_has(cx.subsumers, &(q))); }) : (0); })));
        }
    }
}

uint8_t test_test_names_round_trip(slop_arena* arena) {
    {
        __auto_type names = types_empty_names(arena);
        __auto_type empty = types_empty_names(arena);
        __auto_type c = test_cls(SLOP_STR("http://example.org/C"));
        __auto_type i = ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = ((rdf_IRI){.value = SLOP_STR("http://example.org/C")}) });
        __auto_type f = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = 7 });
        __auto_type r = test_rol(SLOP_STR("http://example.org/r"));
        __auto_type top = types_node_top();
        __auto_type bottom = types_node_bottom();
        __auto_type rc = types_intern_node(arena, names, c);
        __auto_type ri = types_intern_node(arena, names, i);
        __auto_type rf = types_intern_node(arena, names, f);
        __auto_type rr = types_intern_role(arena, names, r);
        return ((types_node_eq(types_original_node(names, rc), c)) && (types_node_eq(types_original_node(names, ri), i)) && (types_node_eq(types_original_node(names, rf), f)) && (types_role_eq(types_original_role(names, rr), r)) && (!(types_node_eq(rc, ri))) && (types_node_eq(types_intern_node(arena, names, c), rc)) && (test_same_renamed(names, c, rc)) && (types_node_eq(types_intern_node(arena, names, top), top)) && (types_node_eq(types_intern_node(arena, names, bottom), bottom)) && (types_node_eq(types_original_node(empty, f), f)) && (test_same_renamed(empty, c, c)) && (test_same_renamed(empty, f, f)) && (({ __auto_type _mv = types_renamed_node(names, ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = 0 })); _mv.has_value ? ({ __auto_type _ = _mv.value; 0; }) : (1); })));
    }
}

uint8_t test_same_renamed(types_Names names, types_Node n, types_Node expect) {
    __auto_type _mv_699 = types_renamed_node(names, n);
    if (_mv_699.has_value) {
        __auto_type r = _mv_699.value;
        return types_node_eq(r, expect);
    } else if (!_mv_699.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_litmus_end_to_end(slop_arena* arena) {
    {
        __auto_type parent = test_cls(SLOP_STR("http://example.org/t#Parent"));
        __auto_type mother = test_cls(SLOP_STR("http://example.org/t#Mother"));
        __auto_type _mv_700 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl"));
        if (!_mv_700.has_value) {
            return 0;
        } else if (_mv_700.has_value) {
            __auto_type o = _mv_700.value;
            return (((((int64_t)(((int64_t)((o.coverage.omitted).len)))) == 0)) && (classify_entails_sub(o.saturation, o.names, o.findings.inconsistent, mother, parent)) && ((howl_verdict(o) == howl_Verdict_verdict_coherent ? 1 : 0)));
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_role_hierarchy_carries_edges(slop_arena* arena) {
    __auto_type _mv_701 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/probes/subproperty-existential.ttl"));
    if (!_mv_701.has_value) {
        return 0;
    } else if (_mv_701.has_value) {
        __auto_type o = _mv_701.value;
        {
            __auto_type inc = o.findings.inconsistent;
            return (classify_entails_sub(o.saturation, o.names, inc, test_cls(SLOP_STR("http://example.org/t#A")), test_cls(SLOP_STR("http://example.org/t#C"))) && !(classify_entails_sub(o.saturation, o.names, inc, test_cls(SLOP_STR("http://example.org/t#E")), test_cls(SLOP_STR("http://example.org/t#F")))));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_role_closure_deep(slop_arena* arena) {
    __auto_type _mv_702 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/role-hierarchy-deep.ttl"));
    if (!_mv_702.has_value) {
        return 0;
    } else if (_mv_702.has_value) {
        __auto_type o = _mv_702.value;
        {
            __auto_type inc = o.findings.inconsistent;
            __auto_type sat = o.saturation;
            __auto_type nm = o.names;
            return (((((int64_t)(((int64_t)((o.coverage.omitted).len)))) == 0)) && (classify_entails_sub(sat, nm, inc, test_cls(SLOP_STR("http://example.org/t#A1")), test_cls(SLOP_STR("http://example.org/t#C1")))) && (classify_entails_sub(sat, nm, inc, test_cls(SLOP_STR("http://example.org/t#A2")), test_cls(SLOP_STR("http://example.org/t#C2")))) && (classify_entails_sub(sat, nm, inc, test_cls(SLOP_STR("http://example.org/t#A3")), test_cls(SLOP_STR("http://example.org/t#C3")))) && (classify_entails_sub(sat, nm, inc, test_cls(SLOP_STR("http://example.org/t#D3")), test_cls(SLOP_STR("http://example.org/t#E3")))) && (classify_entails_sub(sat, nm, inc, test_cls(SLOP_STR("http://example.org/t#X4")), test_cls(SLOP_STR("http://example.org/t#E")))) && (classify_entails_sub(sat, nm, inc, test_cls(SLOP_STR("http://example.org/t#X5")), test_cls(SLOP_STR("http://example.org/t#E")))) && (classify_entails_sub(sat, nm, inc, test_cls(SLOP_STR("http://example.org/t#X6")), test_cls(SLOP_STR("http://example.org/t#F6")))) && (!(classify_entails_sub(sat, nm, inc, test_cls(SLOP_STR("http://example.org/t#A7")), test_cls(SLOP_STR("http://example.org/t#N7"))))));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_smaller_side_joins(slop_arena* arena) {
    __auto_type _mv_703 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/smaller-side-join.ttl"));
    if (!_mv_703.has_value) {
        return 0;
    } else if (_mv_703.has_value) {
        __auto_type o = _mv_703.value;
        {
            __auto_type inc = o.findings.inconsistent;
            return (((((int64_t)(((int64_t)((o.coverage.omitted).len)))) == 0)) && (classify_entails_sub(o.saturation, o.names, inc, test_cls(SLOP_STR("http://example.org/t#X")), test_cls(SLOP_STR("http://example.org/t#E3")))) && (classify_entails_sub(o.saturation, o.names, inc, test_cls(SLOP_STR("http://example.org/t#X2")), test_cls(SLOP_STR("http://example.org/t#H2")))));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_unattested_import_is_inconclusive(slop_arena* arena) {
    __auto_type _mv_704 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/unattested-import.ttl"));
    if (!_mv_704.has_value) {
        return 0;
    } else if (_mv_704.has_value) {
        __auto_type o = _mv_704.value;
        return ((((int64_t)(((int64_t)((o.coverage.omitted).len)))) > 0) && (howl_verdict(o) == howl_Verdict_verdict_inconclusive ? 1 : 0));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_declared_unused_class_gets_a_context(slop_arena* arena) {
    {
        __auto_type unused = test_cls(SLOP_STR("http://example.org/t#Unused"));
        __auto_type _mv_705 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/declared-unused-class.ttl"));
        if (!_mv_705.has_value) {
            return 0;
        } else if (_mv_705.has_value) {
            __auto_type o = _mv_705.value;
            return (classify_entails_sub(o.saturation, o.names, o.findings.inconsistent, unused, types_node_top()) && (howl_verdict(o) == howl_Verdict_verdict_coherent ? 1 : 0));
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_abox_disjoint_range_is_incoherent(slop_arena* arena) {
    __auto_type _mv_706 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/abox-disjoint-range.ttl"));
    if (!_mv_706.has_value) {
        return 0;
    } else if (_mv_706.has_value) {
        __auto_type o = _mv_706.value;
        __auto_type _mv_707 = howl_verdict(o);
        if (_mv_707 == howl_Verdict_verdict_incoherent) {
            return 1;
        } else {
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t test_omitted_count(types_Outcome o) {
    return ((int64_t)(((int64_t)((o.coverage.omitted).len))));
}

uint8_t test_test_undeclared_individual_is_reasoned_over(slop_arena* arena) {
    __auto_type _mv_708 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/undeclared-individual.ttl"));
    if (!_mv_708.has_value) {
        return 0;
    } else if (_mv_708.has_value) {
        __auto_type o = _mv_708.value;
        return (((test_omitted_count(o) == 0)) && (o.findings.inconsistent) && ((howl_verdict(o) == howl_Verdict_verdict_incoherent ? 1 : 0)));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_anonymous_class_assertion_is_read(slop_arena* arena) {
    __auto_type _mv_709 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/anonymous-class-assertion.ttl"));
    if (!_mv_709.has_value) {
        return 0;
    } else if (_mv_709.has_value) {
        __auto_type o = _mv_709.value;
        return ((test_omitted_count(o) == 0) && o.findings.inconsistent);
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_annotation_on_annotation_is_consumed(slop_arena* arena) {
    {
        __auto_type path = SLOP_STR("corpus/fixtures/hazards/annotated-annotation.ttl");
        __auto_type src_pred = rdf_make_iri(arena, SLOP_STR("http://www.w3.org/2002/07/owl#annotatedSource"));
        return (({ __auto_type _mv = ttl_parse_ttl_file(arena, path); uint8_t _mr; if (_mv.is_ok) { __auto_type g = _mv.data.ok; _mr = ({ __auto_type _mv = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 })); uint8_t _mr; if (_mv.is_ok) { __auto_type s0 = _mv.data.ok; _mr = (((test_count_subclass_triples(g.triples, src_pred) == 1)) && ((test_count_subclass_triples(test_stage0_triples(arena, s0), src_pred) == 0)) && ((((int64_t)(((int64_t)((s0.omissions).len)))) == 0))); } else { __auto_type _ = _mv.data.err; _mr = 0; } _mr; }); } else { __auto_type _ = _mv.data.err; _mr = 0; } _mr; }) && ({ __auto_type _mv = test_classify_fixture(arena, path); _mv.has_value ? ({ __auto_type o = _mv.value; ((test_omitted_count(o) == 0) && (howl_verdict(o) == howl_Verdict_verdict_coherent ? 1 : 0)); }) : (0); }));
    }
}

uint8_t test_test_logical_triple_on_header_node_is_not_swallowed(slop_arena* arena) {
    __auto_type _mv_710 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/logical-triple-on-header-node.ttl"));
    if (!_mv_710.has_value) {
        return 0;
    } else if (_mv_710.has_value) {
        __auto_type o = _mv_710.value;
        return ((test_omitted_count(o) > 0) && (howl_verdict(o) == howl_Verdict_verdict_inconclusive ? 1 : 0));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_repeated_disjoint_member_is_positional(slop_arena* arena) {
    {
        __auto_type a = ((rdf_IRI){.value = SLOP_STR("http://example.org/t#A")});
        __auto_type _mv_711 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/disjoint-repeated-member.ttl"));
        if (!_mv_711.has_value) {
            return 0;
        } else if (_mv_711.has_value) {
            __auto_type o = _mv_711.value;
            {
                __auto_type unsat = o.findings.unsatisfiable;
                return (((test_omitted_count(o) == 0)) && (!(o.findings.inconsistent)) && ((((int64_t)(((int64_t)((unsat).len)))) == 1)) && (({ __auto_type _mv = ({ __auto_type _lst = unsat; size_t _idx = (size_t)0; slop_option_rdf_IRI _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type u = _mv.value; string_eq(u.value, a.value); }) : (0); })));
            }
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_report_entails(types_Findings f, types_Node a, types_Node b) {
    if (f.inconsistent) {
        return 1;
    } else {
        {
            __auto_type bottom = types_node_bottom();
            uint8_t found = 0;
            {
                __auto_type _coll = f.subsumptions;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type p = _coll.data[_i];
                    if (types_node_eq(p.sub, a)) {
                        if (types_node_eq(p.super, bottom)) {
                            found = 1;
                        }
                        if (types_node_eq(p.super, b)) {
                            found = 1;
                        }
                    }
                }
            }
            return found;
        }
    }
}

uint8_t test_probe_agrees_with_report(slop_arena* arena, slop_string path) {
    __auto_type _mv_712 = test_classify_fixture(arena, path);
    if (!_mv_712.has_value) {
        return 0;
    } else if (_mv_712.has_value) {
        __auto_type o = _mv_712.value;
        {
            __auto_type sat = o.saturation;
            __auto_type names = o.names;
            __auto_type f = o.findings;
            __auto_type ok = 1;
            __auto_type pairs = 0;
            {
                slop_map* _coll = (slop_map*)sat.contexts;
                for (size_t _i = 0; _i < _coll->len; _i++) {
                    {
                        types_Node ra = *(types_Node*)slop_map_key_at(_coll, _i);
                        types_Context actx = *(types_Context*)slop_map_value_at(_coll, _i);
                        {
                            __auto_type a = types_original_node(names, ra);
                            __auto_type _mv_713 = a;
                            switch (_mv_713.tag) {
                                case types_Node_class_node:
                                {
                                    __auto_type ai = _mv_713.data.class_node;
                                    if (!(string_eq(ai.value, SLOP_STR("http://www.w3.org/2002/07/owl#Nothing")))) {
                                        {
                                            slop_map* _coll = (slop_map*)sat.contexts;
                                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                                {
                                                    types_Node rb = *(types_Node*)slop_map_key_at(_coll, _i);
                                                    types_Context bctx = *(types_Context*)slop_map_value_at(_coll, _i);
                                                    {
                                                        __auto_type b = types_original_node(names, rb);
                                                        __auto_type _mv_714 = b;
                                                        switch (_mv_714.tag) {
                                                            case types_Node_class_node:
                                                            {
                                                                __auto_type _ = _mv_714.data.class_node;
                                                                pairs = (pairs + 1);
                                                                if (!((classify_entails_sub(sat, names, f.inconsistent, a, b) == test_report_entails(f, a, b)))) {
                                                                    ok = 0;
                                                                }
                                                                break;
                                                            }
                                                            case types_Node_individual_node:
                                                            {
                                                                __auto_type _ = _mv_714.data.individual_node;
                                                                break;
                                                            }
                                                            case types_Node_fresh_node:
                                                            {
                                                                __auto_type _ = _mv_714.data.fresh_node;
                                                                break;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                                case types_Node_individual_node:
                                {
                                    __auto_type _ = _mv_713.data.individual_node;
                                    break;
                                }
                                case types_Node_fresh_node:
                                {
                                    __auto_type _ = _mv_713.data.fresh_node;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            return (ok && (pairs > 0));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_entails_sub_agrees_with_report(slop_arena* arena) {
    return ((test_probe_agrees_with_report(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl"))) && (test_probe_agrees_with_report(arena, SLOP_STR("corpus/fixtures/v0/top-bottom.ttl"))) && (test_probe_agrees_with_report(arena, SLOP_STR("corpus/fixtures/hazards/unsatisfiable-consistent.ttl"))) && (test_probe_agrees_with_report(arena, SLOP_STR("corpus/fixtures/hazards/inconsistent-via-individual.ttl"))) && (test_probe_agrees_with_report(arena, SLOP_STR("corpus/fixtures/hazards/abox-disjoint-range.ttl"))) && (test_probe_agrees_with_report(arena, SLOP_STR("corpus/fixtures/hazards/cyclic-hierarchy.ttl"))) && (test_probe_agrees_with_report(arena, SLOP_STR("corpus/fixtures/hazards/punning.ttl"))) && (test_probe_agrees_with_report(arena, SLOP_STR("corpus/fixtures/hazards/owl-nothing-present.ttl"))) && (test_probe_agrees_with_report(arena, SLOP_STR("corpus/fixtures/hazards/declared-unused-class.ttl"))) && (test_probe_agrees_with_report(arena, SLOP_STR("corpus/fixtures/probes/some-unsat-filler.ttl"))) && (test_probe_agrees_with_report(arena, SLOP_STR("corpus/fixtures/probes/top-subsumes-everything.ttl"))));
}

types_Node test_cls(slop_string name) {
    return ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = name}) });
}

types_RoleId test_rol(slop_string name) {
    return ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = ((rdf_IRI){.value = name}) });
}

slop_result_saturate_RoundResult_types_Fault test_run_fixture(slop_arena* arena, slop_list_types_Node signature, slop_list_types_NormAxiom axioms) {
    return saturate_saturate(arena, saturate_make_initial_saturation(arena, signature), premise_build_rule_index(arena, axioms), howl_default_config());
}

slop_list_types_Node test_litmus_signature(slop_arena* arena) {
    {
        __auto_type sig = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (test_cls(SLOP_STR("http://example.org/Person"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (test_cls(SLOP_STR("http://example.org/Parent"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (test_cls(SLOP_STR("http://example.org/Mother"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = 0 })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return sig;
    }
}

slop_list_types_NormAxiom test_litmus_axioms(slop_arena* arena, uint8_t correct_polarity) {
    {
        __auto_type person = test_cls(SLOP_STR("http://example.org/Person"));
        __auto_type parent = test_cls(SLOP_STR("http://example.org/Parent"));
        __auto_type mother = test_cls(SLOP_STR("http://example.org/Mother"));
        __auto_type x = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = 0 });
        __auto_type has_child = test_rol(SLOP_STR("http://example.org/hasChild"));
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0 });
        if (correct_polarity) {
            ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = has_child, .f1 = person, .f2 = x } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else {
            ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = x, .f1 = has_child, .f2 = person } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_and, .data.sub_and = { .f0 = person, .f1 = x, .f2 = parent } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = parent, .f1 = person } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = parent, .f1 = has_child, .f2 = person } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = mother, .f1 = person } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = mother, .f1 = has_child, .f2 = person } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ax;
    }
}

uint8_t test_litmus_derives_parent(slop_arena* arena, uint8_t correct_polarity) {
    __auto_type _mv_715 = test_run_fixture(arena, test_litmus_signature(arena), test_litmus_axioms(arena, correct_polarity));
    if (_mv_715.is_ok) {
        __auto_type r = _mv_715.data.ok;
        {
            __auto_type f = classify_extract_findings(arena, r.saturation, types_empty_names(arena));
            return classify_entails_sub(r.saturation, types_empty_names(arena), f.inconsistent, test_cls(SLOP_STR("http://example.org/Mother")), test_cls(SLOP_STR("http://example.org/Parent")));
        }
    } else if (!_mv_715.is_ok) {
        __auto_type _ = _mv_715.data.err;
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_litmus(slop_arena* arena) {
    return test_litmus_derives_parent(arena, 1);
}

uint8_t test_test_polarity_guard(slop_arena* arena) {
    return !(test_litmus_derives_parent(arena, 0));
}

uint8_t test_test_cyclic_hierarchy_terminates(slop_arena* arena) {
    {
        __auto_type a = test_cls(SLOP_STR("http://example.org/A"));
        __auto_type b = test_cls(SLOP_STR("http://example.org/B"));
        __auto_type sig = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = a, .f1 = b } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = b, .f1 = a } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_716 = test_run_fixture(arena, sig, ax);
        if (_mv_716.is_ok) {
            __auto_type r = _mv_716.data.ok;
            __auto_type _mv_717 = r.termination;
            switch (_mv_717.tag) {
                case types_Termination_fixpoint:
                {
                    return 1;
                }
                case types_Termination_resource_limit:
                {
                    __auto_type _ = _mv_717.data.resource_limit;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_716.is_ok) {
            __auto_type _ = _mv_716.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_same_round_co_arrival(slop_arena* arena) {
    {
        __auto_type e = test_cls(SLOP_STR("http://example.org/E"));
        __auto_type f = test_cls(SLOP_STR("http://example.org/F"));
        __auto_type g = test_cls(SLOP_STR("http://example.org/G"));
        __auto_type h = test_cls(SLOP_STR("http://example.org/H"));
        __auto_type r = test_rol(SLOP_STR("http://example.org/r"));
        __auto_type sig = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (h); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = e, .f1 = r, .f2 = f } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = f, .f1 = g } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = r, .f1 = g, .f2 = h } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_718 = test_run_fixture(arena, sig, ax);
        if (_mv_718.is_ok) {
            __auto_type res = _mv_718.data.ok;
            {
                __auto_type fi = classify_extract_findings(arena, res.saturation, types_empty_names(arena));
                return classify_entails_sub(res.saturation, types_empty_names(arena), fi.inconsistent, e, h);
            }
        } else if (!_mv_718.is_ok) {
            __auto_type _ = _mv_718.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_late_subsumer_still_concludes(slop_arena* arena) {
    {
        __auto_type e = test_cls(SLOP_STR("http://example.org/E"));
        __auto_type f = test_cls(SLOP_STR("http://example.org/F"));
        __auto_type f1 = test_cls(SLOP_STR("http://example.org/F1"));
        __auto_type g = test_cls(SLOP_STR("http://example.org/G"));
        __auto_type h = test_cls(SLOP_STR("http://example.org/H"));
        __auto_type r = test_rol(SLOP_STR("http://example.org/r"));
        __auto_type sig = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (f1); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (h); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = e, .f1 = r, .f2 = f } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = f, .f1 = f1 } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = f1, .f1 = g } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = r, .f1 = g, .f2 = h } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_719 = test_run_fixture(arena, sig, ax);
        if (_mv_719.is_ok) {
            __auto_type res = _mv_719.data.ok;
            {
                __auto_type fi = classify_extract_findings(arena, res.saturation, types_empty_names(arena));
                return classify_entails_sub(res.saturation, types_empty_names(arena), fi.inconsistent, e, h);
            }
        } else if (!_mv_719.is_ok) {
            __auto_type _ = _mv_719.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

slop_result_saturate_RoundResult_types_Fault test_unsat_fixture(slop_arena* arena) {
    {
        __auto_type a = test_cls(SLOP_STR("http://example.org/A"));
        __auto_type b = test_cls(SLOP_STR("http://example.org/B"));
        __auto_type c = test_cls(SLOP_STR("http://example.org/C"));
        __auto_type sig = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = a, .f1 = b } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = a, .f1 = c } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_and, .data.sub_and = { .f0 = b, .f1 = c, .f2 = types_node_bottom() } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return test_run_fixture(arena, sig, ax);
    }
}

uint8_t test_test_unsatisfiable_class_detected(slop_arena* arena) {
    __auto_type _mv_720 = test_unsat_fixture(arena);
    if (_mv_720.is_ok) {
        __auto_type r = _mv_720.data.ok;
        {
            __auto_type f = classify_extract_findings(arena, r.saturation, types_empty_names(arena));
            if (((int64_t)((f.unsatisfiable).len)) == 1) {
                return types_findings_are_incoherent(f);
            } else {
                return 0;
            }
        }
    } else if (!_mv_720.is_ok) {
        __auto_type _ = _mv_720.data.err;
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_bottom_compression(slop_arena* arena) {
    __auto_type _mv_721 = test_unsat_fixture(arena);
    if (_mv_721.is_ok) {
        __auto_type r = _mv_721.data.ok;
        {
            __auto_type a = test_cls(SLOP_STR("http://example.org/A"));
            __auto_type b = test_cls(SLOP_STR("http://example.org/B"));
            __auto_type f = classify_extract_findings(arena, r.saturation, types_empty_names(arena));
            __auto_type pairs_about_a = 0;
            {
                __auto_type _coll = f.subsumptions;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type p = _coll.data[_i];
                    if (types_node_eq(p.sub, a)) {
                        pairs_about_a = (pairs_about_a + 1);
                    }
                }
            }
            if (classify_entails_sub(r.saturation, types_empty_names(arena), f.inconsistent, a, b)) {
                return (pairs_about_a == 1);
            } else {
                return 0;
            }
        }
    } else if (!_mv_721.is_ok) {
        __auto_type _ = _mv_721.data.err;
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_inconsistency_suppresses_both_lists(slop_arena* arena) {
    {
        __auto_type a = test_cls(SLOP_STR("http://example.org/A"));
        __auto_type sig = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = types_node_top(), .f1 = types_node_bottom() } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_722 = test_run_fixture(arena, sig, ax);
        if (_mv_722.is_ok) {
            __auto_type r = _mv_722.data.ok;
            {
                __auto_type f = classify_extract_findings(arena, r.saturation, types_empty_names(arena));
                if (f.inconsistent) {
                    if (((int64_t)((f.unsatisfiable).len)) == 0) {
                        return (((int64_t)((f.subsumptions).len)) == 0);
                    } else {
                        return 0;
                    }
                } else {
                    return 0;
                }
            }
        } else if (!_mv_722.is_ok) {
            __auto_type _ = _mv_722.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_derived_eq_compares_both_payloads(slop_arena* arena) {
    {
        __auto_type r = test_rol(SLOP_STR("http://example.org/r"));
        __auto_type y1 = test_cls(SLOP_STR("http://example.org/Y1"));
        __auto_type y2 = test_cls(SLOP_STR("http://example.org/Y2"));
        __auto_type x = test_cls(SLOP_STR("http://example.org/X"));
        if (types_derived_eq(((types_Derived){ .tag = types_Derived_derived_succ, .data.derived_succ = { .f0 = r, .f1 = y1 } }), ((types_Derived){ .tag = types_Derived_derived_succ, .data.derived_succ = { .f0 = r, .f1 = y2 } }))) {
            return 0;
        } else {
            if (!(types_derived_eq(((types_Derived){ .tag = types_Derived_derived_succ, .data.derived_succ = { .f0 = r, .f1 = y1 } }), ((types_Derived){ .tag = types_Derived_derived_succ, .data.derived_succ = { .f0 = r, .f1 = y1 } })))) {
                return 0;
            } else {
                if (types_derived_eq(((types_Derived){ .tag = types_Derived_derived_succ, .data.derived_succ = { .f0 = r, .f1 = y1 } }), ((types_Derived){ .tag = types_Derived_derived_pred, .data.derived_pred = { .f0 = r, .f1 = y1 } }))) {
                    return 0;
                } else {
                    if (types_addressed_eq(((types_Addressed){.to = x, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = y1 })}), ((types_Addressed){.to = y2, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = y1 })}))) {
                        return 0;
                    } else {
                        return types_addressed_eq(((types_Addressed){.to = x, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = y1 })}), ((types_Addressed){.to = x, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = y1 })}));
                    }
                }
            }
        }
    }
}

uint8_t test_test_order_independence(slop_arena* arena) {
    {
        __auto_type a = test_cls(SLOP_STR("http://example.org/A"));
        __auto_type b = test_cls(SLOP_STR("http://example.org/B"));
        __auto_type c = test_cls(SLOP_STR("http://example.org/C"));
        __auto_type fwd = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type rev = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(fwd); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(fwd); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(fwd); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(rev); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(rev); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(rev); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = a, .f1 = b } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = b, .f1 = c } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_723 = test_run_fixture(arena, fwd, ax);
        if (_mv_723.is_ok) {
            __auto_type r1 = _mv_723.data.ok;
            __auto_type _mv_724 = test_run_fixture(arena, rev, ax);
            if (_mv_724.is_ok) {
                __auto_type r2 = _mv_724.data.ok;
                {
                    __auto_type f1 = classify_extract_findings(arena, r1.saturation, types_empty_names(arena));
                    __auto_type f2 = classify_extract_findings(arena, r2.saturation, types_empty_names(arena));
                    if (r1.saturation.iteration == r2.saturation.iteration) {
                        if (((int64_t)((f1.subsumptions).len)) == ((int64_t)((f2.subsumptions).len))) {
                            return (((int64_t)((f1.unsatisfiable).len)) == ((int64_t)((f2.unsatisfiable).len)));
                        } else {
                            return 0;
                        }
                    } else {
                        return 0;
                    }
                }
            } else if (!_mv_724.is_ok) {
                __auto_type _ = _mv_724.data.err;
                return 0;
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_723.is_ok) {
            __auto_type _ = _mv_723.data.err;
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

rdf_IRI test_mk_iri(slop_string v) {
    return ((rdf_IRI){.value = v});
}

uint8_t test_test_string_cmp_is_length_safe(slop_arena* arena) {
    {
        __auto_type buf = SLOP_STR("applesauce");
        __auto_type apple = (slop_string){.len = 5, .data = buf.data};
        return (((canon_string_cmp(apple, buf) == -1)) && ((canon_string_cmp(buf, apple) == 1)) && ((canon_string_cmp(apple, SLOP_STR("apple")) == 0)) && ((canon_string_cmp(apple, apple) == 0)));
    }
}

uint8_t test_test_node_cmp_separates_punned_iris(slop_arena* arena) {
    {
        __auto_type c = ((types_Node){ .tag = types_Node_class_node, .data.class_node = test_mk_iri(SLOP_STR("http://example.org/x")) });
        __auto_type i = ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = test_mk_iri(SLOP_STR("http://example.org/x")) });
        return (((canon_node_cmp(c, i) != 0)) && ((canon_node_cmp(c, i) == -1)) && ((canon_node_cmp(i, c) == 1)) && ((canon_node_cmp(c, c) == 0)));
    }
}

uint8_t test_test_sort_orders_and_is_input_determined(slop_arena* arena) {
    {
        __auto_type a = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type b = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(a); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/zebra"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(a); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/apple"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(a); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/apple2"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(a); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/mango"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(b); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/mango"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(b); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/apple2"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(b); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/zebra"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(b); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/apple"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type sa = canon_sort_iris(arena, a);
            __auto_type sb = canon_sort_iris(arena, b);
            uint8_t ok = 1;
            int64_t i = 0;
            __auto_type n = ((int64_t)(((int64_t)((sa).len))));
            if (n != 4) {
                ok = 0;
            } else {
            }
            if (((int64_t)(((int64_t)((sb).len)))) != 4) {
                ok = 0;
            } else {
            }
            while (i < n) {
                if (canon_iri_cmp(canon_iri_at(sa, i), canon_iri_at(sb, i)) != 0) {
                    ok = 0;
                } else {
                }
                if ((i > 0) && (canon_iri_cmp(canon_iri_at(sa, (i - 1)), canon_iri_at(sa, i)) >= 0)) {
                    ok = 0;
                } else {
                }
                i = (i + 1);
            }
            if (canon_iri_cmp(canon_iri_at(sa, 0), test_mk_iri(SLOP_STR("http://example.org/apple"))) != 0) {
                ok = 0;
            } else {
            }
            return ok;
        }
    }
}

rdf_Term test_ex_iri(slop_arena* arena, slop_string local) {
    return rdf_make_iri(arena, string_concat(arena, SLOP_STR("http://example.org/t#"), local));
}

int64_t test_count_subclass_triples(slop_list_rdf_Triple ts, rdf_Term pred) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = ts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (rdf_term_eq(t.predicate, pred)) {
                    n = (n + 1);
                }
            }
        }
        return n;
    }
}

uint8_t test_test_unattested_import_yields_an_omission(slop_arena* arena) {
    __auto_type _mv_725 = ttl_parse_ttl_file(arena, SLOP_STR("corpus/fixtures/hazards/unattested-import.ttl"));
    if (!_mv_725.is_ok) {
        __auto_type _ = _mv_725.data.err;
        return 0;
    } else if (_mv_725.is_ok) {
        __auto_type g = _mv_725.data.ok;
        __auto_type _mv_726 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }));
        if (!_mv_726.is_ok) {
            __auto_type _ = _mv_726.data.err;
            return 0;
        } else if (_mv_726.is_ok) {
            __auto_type s0 = _mv_726.data.ok;
            return ((((int64_t)(((int64_t)((s0.imports_declared).len)))) == 1) && (((int64_t)(((int64_t)((s0.omissions).len)))) == 1));
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_attested_import_yields_none(slop_arena* arena) {
    __auto_type _mv_727 = ttl_parse_ttl_file(arena, SLOP_STR("corpus/fixtures/hazards/unattested-import.ttl"));
    if (!_mv_727.is_ok) {
        __auto_type _ = _mv_727.data.err;
        return 0;
    } else if (_mv_727.is_ok) {
        __auto_type g = _mv_727.data.ok;
        {
            __auto_type resolved = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 });
            ({ __auto_type _lst_p = &(resolved); __auto_type _item = (((rdf_IRI){.value = SLOP_STR("http://example.org/does-not-exist")})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            __auto_type _mv_728 = decode_stage0_header(arena, g.triples, resolved);
            if (!_mv_728.is_ok) {
                __auto_type _ = _mv_728.data.err;
                return 0;
            } else if (_mv_728.is_ok) {
                __auto_type s0 = _mv_728.data.ok;
                return ((((int64_t)(((int64_t)((s0.imports_declared).len)))) == 1) && (((int64_t)(((int64_t)((s0.omissions).len)))) == 0));
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_term_store_by_content(slop_arena* arena) {
    {
        __auto_type ttl = SLOP_STR("@prefix : <http://example.org/t#> .\n:s :p \"v\"^^:dt .\n:s :p \"v\"^^:dt .\n:s a :T .\n:u a :T .\n");
        __auto_type _mv_729 = ttl_parse_ttl_string(arena, ttl);
        if (!_mv_729.is_ok) {
            __auto_type _ = _mv_729.data.err;
            return 0;
        } else if (_mv_729.is_ok) {
            __auto_type g = _mv_729.data.ok;
            {
                __auto_type st = termstore_build_store(arena, g.triples);
                __auto_type s = rdf_make_iri(arena, SLOP_STR("http://example.org/t#s"));
                __auto_type p = rdf_make_iri(arena, SLOP_STR("http://example.org/t#p"));
                __auto_type u = rdf_make_iri(arena, SLOP_STR("http://example.org/t#u"));
                __auto_type dt = string_concat(arena, SLOP_STR("http://example.org/t#"), SLOP_STR("dt"));
                __auto_type v = rdf_make_literal(arena, SLOP_STR("v"), (slop_option_string){.has_value = 1, .value = dt}, ((slop_option_string){.has_value = false}));
                __auto_type other = rdf_make_literal(arena, SLOP_STR("v"), ((slop_option_string){.has_value = false}), ((slop_option_string){.has_value = false}));
                return (((((int64_t)(((int64_t)((termstore_store_objects(arena, st, s, p)).len)))) == 1)) && (termstore_store_contains(st, rdf_make_triple(arena, s, p, v))) && (!(termstore_store_contains(st, rdf_make_triple(arena, s, p, other)))) && ((((int64_t)(((int64_t)((termstore_store_typed(arena, st, rdf_make_iri(arena, SLOP_STR("http://example.org/t#T")))).len)))) == 2)) && (termstore_store_has_any(st, s, p)) && (!(termstore_store_has_any(st, u, p))) && ((((int64_t)(((int64_t)((termstore_store_objects(arena, st, u, p)).len)))) == 0)));
            }
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_term_store_quoted_and_tagged(slop_arena* arena) {
    {
        __auto_type a = rdf_make_iri(arena, SLOP_STR("http://example.org/t#a"));
        __auto_type b = rdf_make_iri(arena, SLOP_STR("http://example.org/t#b"));
        __auto_type c = rdf_make_iri(arena, SLOP_STR("http://example.org/t#c"));
        __auto_type p = rdf_make_iri(arena, SLOP_STR("http://example.org/t#p"));
        __auto_type r = rdf_make_iri(arena, SLOP_STR("http://example.org/t#r"));
        __auto_type o = rdf_make_iri(arena, SLOP_STR("http://example.org/t#o"));
        __auto_type q1 = rdf_make_triple_term(arena, rdf_make_triple(arena, a, b, c));
        __auto_type q2 = rdf_make_triple_term(arena, rdf_make_triple(arena, a, b, c));
        __auto_type n1 = rdf_make_triple_term(arena, rdf_make_triple(arena, q1, r, o));
        __auto_type n2 = rdf_make_triple_term(arena, rdf_make_triple(arena, q2, r, o));
        __auto_type en = rdf_make_literal(arena, SLOP_STR("v"), ((slop_option_string){.has_value = false}), (slop_option_string){.has_value = 1, .value = SLOP_STR("en")});
        __auto_type en2 = rdf_make_literal(arena, SLOP_STR("v"), ((slop_option_string){.has_value = false}), (slop_option_string){.has_value = 1, .value = string_concat(arena, SLOP_STR("e"), SLOP_STR("n"))});
        __auto_type fr = rdf_make_literal(arena, SLOP_STR("v"), ((slop_option_string){.has_value = false}), (slop_option_string){.has_value = 1, .value = SLOP_STR("fr")});
        __auto_type plain = rdf_make_literal(arena, SLOP_STR("v"), ((slop_option_string){.has_value = false}), ((slop_option_string){.has_value = false}));
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, q1, p, o)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, n1, p, o)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, a, p, en)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type st = termstore_build_store(arena, ts);
            return (((((int64_t)(((int64_t)((termstore_store_objects(arena, st, q2, p)).len)))) == 1)) && (termstore_store_has_any(st, n2, p)) && (termstore_store_contains(st, rdf_make_triple(arena, a, p, en2))) && (!(termstore_store_contains(st, rdf_make_triple(arena, a, p, fr)))) && (!(termstore_store_contains(st, rdf_make_triple(arena, a, p, plain)))));
        }
    }
}

slop_list_rdf_Triple test_stage0_triples(slop_arena* arena, decode_Stage0 s0) {
    {
        __auto_type out = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = s0.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (termstore_triple_of(s0.dict, it)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_string test_decode_rendered(slop_arena* arena, slop_result_decode_Stage1_types_Fault r) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_730 = r;
        if (_mv_730.is_ok) {
            __auto_type s1 = _mv_730.data.ok;
            {
                __auto_type _coll = s1.axioms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ax = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (owl2_render_axiom(arena, ax)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        } else if (!_mv_730.is_ok) {
            __auto_type f = _mv_730.data.err;
            __auto_type _mv_731 = f;
            switch (_mv_731.tag) {
                case types_Fault_input_error:
                {
                    __auto_type m = _mv_731.data.input_error;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    break;
                }
                case types_Fault_refused:
                {
                    __auto_type _ = _mv_731.data.refused;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (SLOP_STR("refused")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    break;
                }
                case types_Fault_cancelled:
                {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (SLOP_STR("cancelled")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    break;
                }
                case types_Fault_unavailable:
                {
                    __auto_type _ = _mv_731.data.unavailable;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (SLOP_STR("unavailable")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    break;
                }
            }
        }
        return out;
    }
}

uint8_t test_decode_store_agrees(slop_arena* arena, slop_string path) {
    __auto_type _mv_732 = ttl_parse_ttl_file(arena, path);
    if (!_mv_732.is_ok) {
        __auto_type _ = _mv_732.data.err;
        return 0;
    } else if (_mv_732.is_ok) {
        __auto_type g = _mv_732.data.ok;
        __auto_type _mv_733 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }));
        if (!_mv_733.is_ok) {
            __auto_type _ = _mv_733.data.err;
            return 0;
        } else if (_mv_733.is_ok) {
            __auto_type s0 = _mv_733.data.ok;
            {
                __auto_type full = termstore_store_over(arena, s0.dict);
                {
                    __auto_type _coll = s0.triples;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type it = _coll.data[_i];
                        termstore_store_insert_ids(arena, full, it);
                    }
                }
                {
                    __auto_type a = test_decode_rendered(arena, decode_decode_axioms_with(arena, full, s0.dict, s0.triples));
                    __auto_type b = test_decode_rendered(arena, decode_decode_axioms_with(arena, decode_decode_store(arena, s0.dict, s0.triples), s0.dict, s0.triples));
                    __auto_type same = (((int64_t)((a).len)) == ((int64_t)((b).len)));
                    __auto_type i = 0;
                    while (same && (i < ((int64_t)(((int64_t)((a).len)))))) {
                        if (canon_string_cmp(canon_str_at(a, i), canon_str_at(b, i)) != 0) {
                            same = 0;
                        }
                        i = (i + 1);
                    }
                    if (!(same)) {
                        printf("%s", "  [decode-store] differs: ");
                        printf("%.*s\n", (int)(path).len, (path).data);
                    }
                    return same;
                }
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_decode_store_answers_as_the_full_store(slop_arena* arena) {
    {
        uint8_t ok = 1;
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/litmus.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/intersection.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-lhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/abox-assertions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/cardinality.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/complement.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/union.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/nominals.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/has-self.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/inverse-expressions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/equality.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/allvalues.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/datatypes.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/annotation-heavy.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (!(test_decode_store_agrees(arena, p))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

slop_string test_stage0_fault_of(slop_arena* arena, slop_list_rdf_Triple ts) {
    __auto_type _mv_734 = decode_stage0_header(arena, ts, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }));
    if (_mv_734.is_ok) {
        __auto_type _ = _mv_734.data.ok;
        return SLOP_STR("");
    } else if (!_mv_734.is_ok) {
        __auto_type f = _mv_734.data.err;
        __auto_type _mv_735 = f;
        switch (_mv_735.tag) {
            case types_Fault_input_error:
            {
                __auto_type m = _mv_735.data.input_error;
                return m;
            }
            case types_Fault_refused:
            {
                __auto_type _ = _mv_735.data.refused;
                return SLOP_STR("refused");
            }
            case types_Fault_cancelled:
            {
                return SLOP_STR("cancelled");
            }
            case types_Fault_unavailable:
            {
                __auto_type _ = _mv_735.data.unavailable;
                return SLOP_STR("unavailable");
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_stage0_fault_follows_the_document(slop_arena* arena) {
    {
        __auto_type ttl = SLOP_STR("@prefix : <http://example.org/t#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n:A a owl:Class . :B a owl:Class .\n_:x a owl:Axiom ; owl:annotatedProperty rdfs:subClassOf ; owl:annotatedTarget :B .\n_:y a owl:Axiom ; owl:annotatedSource :A ; owl:annotatedProperty rdfs:subClassOf .\n");
        __auto_type _mv_736 = ttl_parse_ttl_string(arena, ttl);
        if (!_mv_736.is_ok) {
            __auto_type _ = _mv_736.data.err;
            return 0;
        } else if (_mv_736.is_ok) {
            __auto_type g = _mv_736.data.ok;
            return ((canon_string_cmp(test_stage0_fault_of(arena, g.triples), SLOP_STR("owl:Axiom node without a usable owl:annotatedTarget")) == 0) && (canon_string_cmp(test_stage0_fault_of(arena, test_reversed_triples(arena, g.triples)), SLOP_STR("owl:Axiom node without a usable owl:annotatedSource")) == 0));
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_stage0_rebuild_checks_the_whole_input(slop_arena* arena) {
    {
        __auto_type ttl = SLOP_STR("@prefix owl: <http://www.w3.org/2002/07/owl#> .\n@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n<http://example.org/t> a owl:Ontology ; rdfs:comment \"c\" .\n_:x a owl:Axiom ; owl:annotatedSource <http://example.org/t> ; owl:annotatedProperty rdfs:comment ; owl:annotatedTarget \"c\" .\n");
        __auto_type _mv_737 = ttl_parse_ttl_string(arena, ttl);
        if (!_mv_737.is_ok) {
            __auto_type _ = _mv_737.data.err;
            return 0;
        } else if (_mv_737.is_ok) {
            __auto_type g = _mv_737.data.ok;
            __auto_type _mv_738 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }));
            if (!_mv_738.is_ok) {
                __auto_type _ = _mv_738.data.err;
                return 0;
            } else if (_mv_738.is_ok) {
                __auto_type s0 = _mv_738.data.ok;
                return (((int64_t)(((int64_t)((s0.triples).len)))) == 0);
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_header_and_reification_are_consumed(slop_arena* arena) {
    __auto_type _mv_739 = ttl_parse_ttl_file(arena, SLOP_STR("corpus/fixtures/hazards/annotation-heavy.ttl"));
    if (!_mv_739.is_ok) {
        __auto_type _ = _mv_739.data.err;
        return 0;
    } else if (_mv_739.is_ok) {
        __auto_type g = _mv_739.data.ok;
        __auto_type _mv_740 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }));
        if (!_mv_740.is_ok) {
            __auto_type _ = _mv_740.data.err;
            return 0;
        } else if (_mv_740.is_ok) {
            __auto_type s0 = _mv_740.data.ok;
            {
                __auto_type sub_pred = rdf_make_iri(arena, vocab_RDFS_SUBCLASS_OF);
                __auto_type kept = test_count_subclass_triples(test_stage0_triples(arena, s0), sub_pred);
                __auto_type before = test_count_subclass_triples(g.triples, sub_pred);
                return (((kept == 1)) && ((before == 1)) && ((((int64_t)(((int64_t)((s0.omissions).len)))) == 0)) && ((((int64_t)(((int64_t)((s0.triples).len)))) < ((int64_t)(((int64_t)((g.triples).len)))))));
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

int64_t test_count_out_of_profile(slop_list_owl2_RawAxiom axs) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_741 = owl2_disposition(types_Profile_profile_el, a);
                if (_mv_741 == owl2_Disposition_d_out_of_profile) {
                    n = (n + 1);
                } else if (_mv_741 == owl2_Disposition_d_in_profile) {
                    if (!(owl2_axiom_in_profile(types_Profile_profile_el, a))) {
                        n = (n + 1);
                    }
                } else if (_mv_741 == owl2_Disposition_d_inert) {
                } else if (_mv_741 == owl2_Disposition_d_consumed) {
                }
            }
        }
        return n;
    }
}

int64_t test_count_disposition(slop_list_owl2_RawAxiom axs, owl2_Disposition want) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (owl2_disposition(types_Profile_profile_el, a) == want) {
                    n = (n + 1);
                }
            }
        }
        return n;
    }
}

slop_option_decode_Stage1 test_decode_fixture(slop_arena* arena, slop_string path) {
    __auto_type _mv_742 = ttl_parse_ttl_file(arena, path);
    if (!_mv_742.is_ok) {
        __auto_type _ = _mv_742.data.err;
        return (slop_option_decode_Stage1){.has_value = false};
    } else if (_mv_742.is_ok) {
        __auto_type g = _mv_742.data.ok;
        __auto_type _mv_743 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }));
        if (!_mv_743.is_ok) {
            __auto_type _ = _mv_743.data.err;
            return (slop_option_decode_Stage1){.has_value = false};
        } else if (_mv_743.is_ok) {
            __auto_type s0 = _mv_743.data.ok;
            __auto_type _mv_744 = decode_decode_axioms(arena, s0.dict, s0.triples);
            if (!_mv_744.is_ok) {
                __auto_type _ = _mv_744.data.err;
                return (slop_option_decode_Stage1){.has_value = false};
            } else if (_mv_744.is_ok) {
                __auto_type s1 = _mv_744.data.ok;
                return (slop_option_decode_Stage1){.has_value = 1, .value = s1};
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

int64_t test_nary_disjoint_member_count(slop_list_owl2_RawAxiom axs) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_745 = a;
                switch (_mv_745.tag) {
                    case owl2_RawAxiom_ra_disjoint_classes:
                    {
                        __auto_type cs = _mv_745.data.ra_disjoint_classes;
                        n = ((int64_t)(((int64_t)((cs).len))));
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        return n;
    }
}

uint8_t test_test_nary_disjointness_keeps_its_members(slop_arena* arena) {
    __auto_type _mv_746 = test_decode_fixture(arena, SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl"));
    if (!_mv_746.has_value) {
        return 0;
    } else if (_mv_746.has_value) {
        __auto_type s1 = _mv_746.value;
        return ((test_nary_disjoint_member_count(s1.axioms) == 3) && (test_count_out_of_profile(s1.axioms) == 0));
    }
    SLOP_UNREACHABLE();
}

int64_t test_out_of_profile_count_of(slop_arena* arena, slop_string path) {
    __auto_type _mv_747 = test_decode_fixture(arena, path);
    if (!_mv_747.has_value) {
        return -1;
    } else if (_mv_747.has_value) {
        __auto_type s1 = _mv_747.value;
        return test_count_out_of_profile(s1.axioms);
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_v0_corpus_decodes_clean(slop_arena* arena) {
    {
        __auto_type paths = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0 });
        uint8_t ok = 1;
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subclass-atomic.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/intersection.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-lhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-rhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-classes.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-properties.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-binary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subproperty.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/transitive.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/domain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/abox-assertions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/top-bottom.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/litmus.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = paths;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (test_out_of_profile_count_of(arena, p) != 0) {
                    printf("%s", "  [sweep] expected 0 out-of-profile, got ");
                    printf("%.*s", (int)(int_to_string(arena, test_out_of_profile_count_of(arena, p))).len, (int_to_string(arena, test_out_of_profile_count_of(arena, p))).data);
                    printf("%s", " in ");
                    printf("%.*s\n", (int)(p).len, (p).data);
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t test_test_out_of_profile_corpus_is_caught(slop_arena* arena) {
    {
        __auto_type paths = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0 });
        uint8_t ok = 1;
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/union.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/complement.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/allvalues.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/nominals.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/cardinality.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/has-self.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/inverse.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/equality.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/property-characteristics.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/haskey-disjointunion.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/swrl-rule.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/builtin-roles.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/anonymous-individual.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/datatypes.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/inverse-expressions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = paths;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (test_out_of_profile_count_of(arena, p) < 1) {
                    printf("%s", "  [sweep] expected >=1 out-of-profile, got ");
                    printf("%.*s", (int)(int_to_string(arena, test_out_of_profile_count_of(arena, p))).len, (int_to_string(arena, test_out_of_profile_count_of(arena, p))).data);
                    printf("%s", " in ");
                    printf("%.*s\n", (int)(p).len, (p).data);
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t test_test_annotation_heavy_decodes_clean(slop_arena* arena) {
    __auto_type _mv_748 = test_decode_fixture(arena, SLOP_STR("corpus/fixtures/hazards/annotation-heavy.ttl"));
    if (!_mv_748.has_value) {
        return 0;
    } else if (_mv_748.has_value) {
        __auto_type s1 = _mv_748.value;
        {
            __auto_type axs = s1.axioms;
            return (((test_count_out_of_profile(axs) == 0)) && ((test_count_disposition(axs, owl2_Disposition_d_in_profile) > 0)) && ((s1.inert > 0)) && ((test_count_disposition(axs, owl2_Disposition_d_consumed) > 0)));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_litmus_decodes_clean(slop_arena* arena) {
    __auto_type _mv_749 = test_decode_fixture(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl"));
    if (!_mv_749.has_value) {
        return 0;
    } else if (_mv_749.has_value) {
        __auto_type s1 = _mv_749.value;
        {
            __auto_type axs = s1.axioms;
            return ((test_count_out_of_profile(axs) == 0) && (test_count_disposition(axs, owl2_Disposition_d_in_profile) >= 2));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_missing_class_declaration_is_reported(slop_arena* arena) {
    {
        __auto_type pre = SLOP_STR("@prefix : <http://example.org/t#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n");
        return ((test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":A a owl:Class . :A rdfs:subClassOf :B ."))) > 0) && (test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":A a owl:Class . :B a owl:Class . :A rdfs:subClassOf :B ."))) == 0));
    }
}

uint8_t test_test_undeclared_individual_is_not_reported(slop_arena* arena) {
    {
        __auto_type ttl = SLOP_STR("@prefix : <http://example.org/t#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n:A a owl:Class . :p a owl:ObjectProperty .\n:a a :A . :a :p :b .\n");
        return (test_gate_omissions_of_ttl(arena, ttl) == 0);
    }
}

int64_t test_accepted_count_of_ttl(slop_arena* arena, slop_string ttl) {
    __auto_type _mv_750 = ttl_parse_ttl_string(arena, ttl);
    if (!_mv_750.is_ok) {
        __auto_type _ = _mv_750.data.err;
        return -1;
    } else if (_mv_750.is_ok) {
        __auto_type g = _mv_750.data.ok;
        __auto_type _mv_751 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }));
        if (!_mv_751.is_ok) {
            __auto_type _ = _mv_751.data.err;
            return -1;
        } else if (_mv_751.is_ok) {
            __auto_type s0 = _mv_751.data.ok;
            __auto_type _mv_752 = decode_decode_axioms(arena, s0.dict, s0.triples);
            if (!_mv_752.is_ok) {
                __auto_type _ = _mv_752.data.err;
                return -1;
            } else if (_mv_752.is_ok) {
                __auto_type s1 = _mv_752.data.ok;
                return ((int64_t)(((int64_t)((gate_gate_axioms(arena, s1.axioms, s1.signature, s0.omissions, types_Profile_profile_el).accepted).len))));
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_reserved_iri_as_individual_is_out_of_profile(slop_arena* arena) {
    {
        __auto_type pre = SLOP_STR("@prefix : <http://example.org/t#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n:A a owl:Class . :p a owl:ObjectProperty . :a a owl:NamedIndividual .\n");
        return (((test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR("owl:Nothing a owl:NamedIndividual ."))) > 0)) && ((test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":a :p owl:Nothing ."))) > 0)) && ((test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR("owl:Thing a owl:Class ."))) == 0)));
    }
}

uint8_t test_test_annotation_property_axioms_are_inert(slop_arena* arena) {
    {
        __auto_type pre = SLOP_STR("@prefix : <http://example.org/t#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n:A a owl:Class .\n:note a owl:AnnotationProperty . :other a owl:AnnotationProperty .\n");
        return (((test_accepted_count_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":note rdfs:domain :A ."))) == 0)) && ((test_accepted_count_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":note rdfs:range :A ."))) == 0)) && ((test_accepted_count_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":note rdfs:subPropertyOf :other ."))) == 0)));
    }
}

uint8_t test_decodes_ok(slop_arena* arena, slop_string ttl) {
    __auto_type _mv_753 = ttl_parse_ttl_string(arena, ttl);
    if (!_mv_753.is_ok) {
        __auto_type _ = _mv_753.data.err;
        return 0;
    } else if (_mv_753.is_ok) {
        __auto_type g = _mv_753.data.ok;
        __auto_type _mv_754 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }));
        if (!_mv_754.is_ok) {
            __auto_type _ = _mv_754.data.err;
            return 0;
        } else if (_mv_754.is_ok) {
            __auto_type s0 = _mv_754.data.ok;
            __auto_type _mv_755 = decode_decode_axioms(arena, s0.dict, s0.triples);
            if (!_mv_755.is_ok) {
                __auto_type _ = _mv_755.data.err;
                return 0;
            } else if (_mv_755.is_ok) {
                __auto_type _ = _mv_755.data.ok;
                return 1;
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_undeclared_property_is_an_input_error(slop_arena* arena) {
    {
        __auto_type pre = SLOP_STR("@prefix : <http://example.org/t#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n:a a owl:NamedIndividual . :b a owl:NamedIndividual .\n");
        return (!(test_decodes_ok(arena, string_concat(arena, pre, SLOP_STR(":a :p :b .")))) && test_decodes_ok(arena, string_concat(arena, pre, SLOP_STR(":p a owl:ObjectProperty . :a :p :b ."))));
    }
}

uint8_t test_test_unknown_owl_vocabulary_still_decodes(slop_arena* arena) {
    {
        __auto_type ttl = SLOP_STR("@prefix : <http://example.org/t#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n:A a owl:Class . :B a owl:Class .\n:A owl:someFutureAxiom :B .\n");
        return (test_decodes_ok(arena, ttl) && (test_gate_omissions_of_ttl(arena, ttl) > 0));
    }
}

uint8_t test_test_conflicting_declarations_are_an_input_error(slop_arena* arena) {
    {
        __auto_type pre = SLOP_STR("@prefix : <http://example.org/t#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n");
        return (!(test_decodes_ok(arena, string_concat(arena, pre, SLOP_STR(":p a owl:ObjectProperty . :p a owl:AnnotationProperty .")))) && test_decodes_ok(arena, string_concat(arena, pre, SLOP_STR(":x a owl:Class . :x a owl:NamedIndividual ."))));
    }
}

slop_option_gate_GateResult test_gate_ttl(slop_arena* arena, slop_string ttl) {
    return test_gate_ttl_in(arena, ttl, types_Profile_profile_el);
}

slop_option_gate_GateResult test_gate_ttl_in(slop_arena* arena, slop_string ttl, types_Profile p) {
    __auto_type _mv_756 = ttl_parse_ttl_string(arena, ttl);
    if (!_mv_756.is_ok) {
        __auto_type _ = _mv_756.data.err;
        return (slop_option_gate_GateResult){.has_value = false};
    } else if (_mv_756.is_ok) {
        __auto_type g = _mv_756.data.ok;
        __auto_type _mv_757 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }));
        if (!_mv_757.is_ok) {
            __auto_type _ = _mv_757.data.err;
            return (slop_option_gate_GateResult){.has_value = false};
        } else if (_mv_757.is_ok) {
            __auto_type s0 = _mv_757.data.ok;
            __auto_type _mv_758 = decode_decode_axioms(arena, s0.dict, s0.triples);
            if (!_mv_758.is_ok) {
                __auto_type _ = _mv_758.data.err;
                return (slop_option_gate_GateResult){.has_value = false};
            } else if (_mv_758.is_ok) {
                __auto_type s1 = _mv_758.data.ok;
                return (slop_option_gate_GateResult){.has_value = 1, .value = gate_gate_axioms(arena, s1.axioms, s1.signature, s0.omissions, p)};
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

int64_t test_gate_omissions_of_ttl(slop_arena* arena, slop_string ttl) {
    __auto_type _mv_759 = test_gate_ttl(arena, ttl);
    if (!_mv_759.has_value) {
        return -1;
    } else if (_mv_759.has_value) {
        __auto_type gr = _mv_759.value;
        return ((int64_t)(((int64_t)((gr.omissions).len))));
    }
    SLOP_UNREACHABLE();
}

slop_string test_gate_accepted_of_ttl(slop_arena* arena, slop_string ttl) {
    __auto_type _mv_760 = test_gate_ttl(arena, ttl);
    if (!_mv_760.has_value) {
        return SLOP_STR("<did not gate>");
    } else if (_mv_760.has_value) {
        __auto_type gr = _mv_760.value;
        {
            __auto_type out = SLOP_STR("");
            {
                __auto_type _coll = gr.accepted;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ax = _coll.data[_i];
                    out = string_concat(arena, out, string_concat(arena, owl2_render_axiom(arena, ax), SLOP_STR("\n")));
                }
            }
            return out;
        }
    }
    SLOP_UNREACHABLE();
}

slop_string test_rc_prefix(void) {
    return SLOP_STR("@prefix : <http://example.org/t#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n:r a owl:ObjectProperty . :s a owl:ObjectProperty . :t a owl:ObjectProperty .\n:u a owl:ObjectProperty . :s2 a owl:ObjectProperty . :p a owl:ObjectProperty .\n:q a owl:ObjectProperty .\n:Agent a owl:Class . :Person a owl:Class .\n");
}

uint8_t test_test_range_composition_table(slop_arena* arena) {
    {
        __auto_type pre = test_rc_prefix();
        uint8_t ok = 1;
        if (test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":t owl:propertyChainAxiom ( :r :s ) . :s rdfs:range :Agent . :t rdfs:range :Agent ."))) != 0) {
            printf("%s\n", "  [range] row 1 should be ACCEPTED");
            ok = 0;
        }
        if (test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":t owl:propertyChainAxiom ( :r :s ) . :t rdfs:range :Agent . :s rdfs:subPropertyOf :s2 . :s2 rdfs:range :Agent ."))) != 0) {
            printf("%s\n", "  [range] row 2 should be ACCEPTED");
            ok = 0;
        }
        if (test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":t owl:propertyChainAxiom ( :r :s ) . :s rdfs:range :Person . :t rdfs:range :Agent . :Person rdfs:subClassOf :Agent ."))) < 1) {
            printf("%s\n", "  [range] row 3 should be REJECTED (subclass range)");
            ok = 0;
        }
        if (test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":t owl:propertyChainAxiom ( :r :s ) . :t rdfs:range :Agent ."))) < 1) {
            printf("%s\n", "  [range] row 4 should be REJECTED (no range on s)");
            ok = 0;
        }
        if (test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":t owl:propertyChainAxiom ( :r :s ) . :t rdfs:subPropertyOf :u . :u rdfs:range :Agent ."))) < 1) {
            printf("%s\n", "  [range] row 5 should be REJECTED (inherited range on t)");
            ok = 0;
        }
        if (test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":t owl:propertyChainAxiom ( :r :s ) ."))) != 0) {
            printf("%s\n", "  [range] row 6 should be ACCEPTED (no range on t)");
            ok = 0;
        }
        if (test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":r rdfs:subPropertyOf :s . :r rdfs:range :Person . :s rdfs:range :Agent ."))) != 0) {
            printf("%s\n", "  [range] row 7 should be ACCEPTED (plain subproperty)");
            ok = 0;
        }
        if (test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":t owl:propertyChainAxiom ( :p :q :s ) . :t rdfs:range :Agent . :s rdfs:range :Agent ."))) != 0) {
            printf("%s\n", "  [range] row 8 should be ACCEPTED (n-ary, last role carries it)");
            ok = 0;
        }
        if (test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":t owl:propertyChainAxiom ( :r :s ) . :t rdfs:range [ owl:intersectionOf ( :Agent [ owl:complementOf :Person ] ) ] . :s rdfs:range :Agent ."))) != 0) {
            printf("%s\n", "  [range] row 9 should be ACCEPTED (only the positive part is imposed)");
            ok = 0;
        }
        if (test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":t owl:propertyChainAxiom ( :r :s ) . :t rdfs:range [ owl:intersectionOf ( :Agent [ owl:complementOf :Person ] ) ] ."))) < 1) {
            printf("%s\n", "  [range] row 10 should be REJECTED (positive part not on s)");
            ok = 0;
        }
        if (test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":t owl:propertyChainAxiom ( :r :s ) . :t rdfs:range [ owl:complementOf :Person ] ."))) != 0) {
            printf("%s\n", "  [range] row 11 should be ACCEPTED (negative range only)");
            ok = 0;
        }
        if (test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":t owl:propertyChainAxiom ( :r :s ) . :t rdfs:range [ owl:intersectionOf ( :Agent [ owl:complementOf [ owl:unionOf ( :Agent :Person ) ] ] ) ] . :s rdfs:range :Agent ."))) != 2) {
            printf("%s\n", "  [range] row 12 should omit the range AND the chain");
            ok = 0;
        }
        return ok;
    }
}

slop_string test_rung_prefix(void) {
    return SLOP_STR("@prefix : <http://example.org/t#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n:r a owl:ObjectProperty . :s a owl:ObjectProperty . :t a owl:ObjectProperty .\n:C a owl:Class . :D a owl:Class .\n:a a owl:NamedIndividual . :b a owl:NamedIndividual .\n");
}

int64_t test_omissions_under(slop_arena* arena, slop_string ttl, types_Profile p) {
    __auto_type _mv_761 = test_gate_ttl_in(arena, ttl, p);
    if (!_mv_761.has_value) {
        return -1;
    } else if (_mv_761.has_value) {
        __auto_type gr = _mv_761.value;
        return ((int64_t)(((int64_t)((gr.omissions).len))));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_rungs_omit(slop_arena* arena, slop_string label, slop_string ttl, int64_t el_want, int64_t elpp_want) {
    {
        __auto_type doc = string_concat(arena, test_rung_prefix(), ttl);
        {
            __auto_type el = test_omissions_under(arena, doc, types_Profile_profile_el);
            __auto_type pp = test_omissions_under(arena, doc, types_Profile_profile_el_plus_plus);
            if ((el == el_want) && (pp == elpp_want)) {
                return 1;
            } else {
                printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [rungs] "), label)).len, (string_concat(arena, SLOP_STR("  [rungs] "), label)).data);
                printf("%s", "    el omitted ");
                printf("%.*s\n", (int)(int_to_string(arena, el)).len, (int_to_string(arena, el)).data);
                printf("%s", "    el++ omitted ");
                printf("%.*s\n", (int)(int_to_string(arena, pp)).len, (int_to_string(arena, pp)).data);
                return 0;
            }
        }
    }
}

uint8_t test_test_el_plus_plus_gate_table(slop_arena* arena) {
    return ((test_rungs_omit(arena, SLOP_STR("hasValue"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasValue :a ] ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("oneOf of one"), SLOP_STR(":C owl:equivalentClass [ a owl:Class ; owl:oneOf ( :a ) ] ."), 2, 0)) && (test_rungs_omit(arena, SLOP_STR("hasSelf, simple role"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasSelf true ] ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("reflexive role"), SLOP_STR(":r a owl:ReflexiveProperty ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("sameAs"), SLOP_STR(":a owl:sameAs :b ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("differentFrom"), SLOP_STR(":a owl:differentFrom :b ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("AllDifferent"), SLOP_STR("[] a owl:AllDifferent ; owl:members ( :a :b ) ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("negative assertion"), SLOP_STR("[] a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; owl:assertionProperty :r ; owl:targetIndividual :b ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("empty role"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty owl:bottomObjectProperty ; owl:someValuesFrom owl:Thing ] ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("inclusion into the universal role"), SLOP_STR(":r rdfs:subPropertyOf owl:topObjectProperty ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("chain into the universal role"), SLOP_STR("owl:topObjectProperty owl:propertyChainAxiom ( :r :s ) ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("oneOf of two"), SLOP_STR(":C owl:equivalentClass [ a owl:Class ; owl:oneOf ( :a :b ) ] ."), 2, 2)) && (test_rungs_omit(arena, SLOP_STR("hasSelf, transitive role"), SLOP_STR(":t a owl:TransitiveProperty . :C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :t ; owl:hasSelf true ] ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("hasSelf, role above a transitive one"), SLOP_STR(":t a owl:TransitiveProperty . :t rdfs:subPropertyOf :s . :C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :s ; owl:hasSelf true ] ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("hasSelf, role above a chain"), SLOP_STR(":s owl:propertyChainAxiom ( :r :r ) . :C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :s ; owl:hasSelf true ] ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("universal role in a restriction"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty owl:topObjectProperty ; owl:someValuesFrom :D ] ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("universal role below another"), SLOP_STR(":t rdfs:subPropertyOf :r . owl:topObjectProperty rdfs:subPropertyOf :r ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("universal role as a chain step"), SLOP_STR(":s owl:propertyChainAxiom ( :r owl:topObjectProperty ) ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("empty role as a chain step"), SLOP_STR(":s owl:propertyChainAxiom ( :r owl:bottomObjectProperty ) ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("oneOf of a reserved IRI"), SLOP_STR(":C rdfs:subClassOf [ a owl:Class ; owl:oneOf ( owl:Thing ) ] ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("hasValue on a reserved IRI"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasValue owl:Thing ] ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("AllDifferent with a reserved IRI"), SLOP_STR("[] a owl:AllDifferent ; owl:members ( :a owl:Thing ) ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("sameAs an XSD IRI"), SLOP_STR("@prefix xsd: <http://www.w3.org/2001/XMLSchema#> . :a owl:sameAs xsd:string ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("universal role into itself"), SLOP_STR("owl:topObjectProperty rdfs:subPropertyOf owl:topObjectProperty ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("functional role"), SLOP_STR(":r a owl:FunctionalProperty ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("hasValue, anonymous"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasValue [] ] ."), 1, 1)));
}

uint8_t test_test_top_role_tautology_is_dropped(slop_arena* arena) {
    __auto_type _mv_762 = test_gate_ttl_in(arena, string_concat(arena, test_rung_prefix(), SLOP_STR(":r rdfs:subPropertyOf owl:topObjectProperty .")), types_Profile_profile_el_plus_plus);
    if (!_mv_762.has_value) {
        return 0;
    } else if (_mv_762.has_value) {
        __auto_type gr = _mv_762.value;
        return ((((int64_t)(((int64_t)((gr.accepted).len)))) == 0) && (((int64_t)(((int64_t)((gr.omissions).len)))) == 0));
    }
    SLOP_UNREACHABLE();
}

slop_string test_ksc_form_of_ttl(slop_arena* arena, slop_string ttl) {
    __auto_type _mv_763 = test_gate_ttl_in(arena, string_concat(arena, test_rung_prefix(), ttl), types_Profile_profile_el_plus_plus);
    if (!_mv_763.has_value) {
        return SLOP_STR("<did not gate>");
    } else if (_mv_763.has_value) {
        __auto_type gr = _mv_763.value;
        {
            __auto_type no = kscnormal_normalize_ksc(arena, gr.accepted);
            __auto_type out = SLOP_STR("");
            {
                __auto_type _coll = no.axioms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ax = _coll.data[_i];
                    out = string_concat(arena, out, string_concat(arena, kscnormal_render_ksc_axiom(arena, ax), SLOP_STR("\n")));
                }
            }
            return out;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_ksc_form_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want) {
    {
        __auto_type got = test_ksc_form_of_ttl(arena, ttl);
        if (canon_string_cmp(got, want) == 0) {
            return 1;
        } else {
            printf("%.*s\n", (int)(string_concat(arena, string_concat(arena, SLOP_STR("  [ksc] "), label), SLOP_STR(":"))).len, (string_concat(arena, string_concat(arena, SLOP_STR("  [ksc] "), label), SLOP_STR(":"))).data);
            printf("%.*s", (int)(got).len, (got).data);
            return 0;
        }
    }
}

uint8_t test_test_ksc_normal_form_rows(slop_arena* arena) {
    {
        uint8_t ok = 1;
        if (!(test_ksc_form_is(arena, SLOP_STR("hasValue on the right"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasValue :a ] ."), SLOP_STR("subClass(_:0, {<http://example.org/t#a>})\nsupEx(<http://example.org/t#C>, <http://example.org/t#r>, _:0, _:1)\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("hasValue on the left"), SLOP_STR("[ a owl:Restriction ; owl:onProperty :r ; owl:hasValue :a ] rdfs:subClassOf :C ."), SLOP_STR("subClass({<http://example.org/t#a>}, _:1)\nsubEx(<http://example.org/t#r>, _:1, _:0)\nsubClass(_:0, <http://example.org/t#C>)\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("nominal on the left"), SLOP_STR("[ a owl:Class ; owl:oneOf ( :a ) ] rdfs:subClassOf :C ."), SLOP_STR("subClass({<http://example.org/t#a>}, <http://example.org/t#C>)\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("nominal on the right"), SLOP_STR(":C rdfs:subClassOf [ a owl:Class ; owl:oneOf ( :a ) ] ."), SLOP_STR("subClass(<http://example.org/t#C>, {<http://example.org/t#a>})\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("Self on the right"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasSelf true ] ."), SLOP_STR("supSelf(<http://example.org/t#C>, <http://example.org/t#r>)\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("Self on the left"), SLOP_STR("[ a owl:Restriction ; owl:onProperty :r ; owl:hasSelf true ] rdfs:subClassOf :C ."), SLOP_STR("subSelf(<http://example.org/t#r>, _:0)\nsubClass(_:0, <http://example.org/t#C>)\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("reflexive role"), SLOP_STR(":r a owl:ReflexiveProperty ."), SLOP_STR("supSelf(<http://www.w3.org/2002/07/owl#Thing>, _:r0)\nsubRole(_:r0, <http://example.org/t#r>)\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("sameAs"), SLOP_STR(":a owl:sameAs :b ."), SLOP_STR("subClass({<http://example.org/t#a>}, {<http://example.org/t#b>})\nsubClass({<http://example.org/t#b>}, {<http://example.org/t#a>})\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("differentFrom"), SLOP_STR(":a owl:differentFrom :b ."), SLOP_STR("subClass({<http://example.org/t#a>}, _:0)\nsubClass({<http://example.org/t#b>}, _:1)\nsubConj(_:0, _:1, <http://www.w3.org/2002/07/owl#Nothing>)\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("negative assertion"), SLOP_STR("[] a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; owl:assertionProperty :r ; owl:targetIndividual :b ."), SLOP_STR("subClass({<http://example.org/t#a>}, _:0)\nsubClass({<http://example.org/t#b>}, _:2)\nsubEx(<http://example.org/t#r>, _:2, _:1)\nsubConj(_:0, _:1, <http://www.w3.org/2002/07/owl#Nothing>)\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("range"), SLOP_STR(":r rdfs:range :C ."), SLOP_STR("supProd(<http://example.org/t#r>, ⊤, <http://example.org/t#C>)\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("domain"), SLOP_STR(":r rdfs:domain :C ."), SLOP_STR("subEx(<http://example.org/t#r>, <http://www.w3.org/2002/07/owl#Thing>, _:0)\nsubClass(_:0, <http://example.org/t#C>)\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("class assertion"), SLOP_STR(":a a :C ."), SLOP_STR("subClass({<http://example.org/t#a>}, <http://example.org/t#C>)\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("complex class assertion"), SLOP_STR(":a a [ a owl:Restriction ; owl:onProperty :r ; owl:someValuesFrom :C ] ."), SLOP_STR("subClass({<http://example.org/t#a>}, _:0)\nsupEx(_:0, <http://example.org/t#r>, <http://example.org/t#C>, _:1)\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("role assertion"), SLOP_STR(":a :r :b ."), SLOP_STR("supEx({<http://example.org/t#a>}, <http://example.org/t#r>, {<http://example.org/t#b>}, {<http://example.org/t#b>})\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("three-step chain"), SLOP_STR(":t owl:propertyChainAxiom ( :r :s :r ) ."), SLOP_STR("subRChain(<http://example.org/t#r>, <http://example.org/t#s>, _:r0)\nsubRChain(_:r0, <http://example.org/t#r>, <http://example.org/t#t>)\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("empty role"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty owl:bottomObjectProperty ; owl:someValuesFrom owl:Thing ] ."), SLOP_STR("supEx(<http://example.org/t#C>, <http://www.w3.org/2002/07/owl#bottomObjectProperty>, <http://www.w3.org/2002/07/owl#Thing>, _:0)\nsubEx(<http://www.w3.org/2002/07/owl#bottomObjectProperty>, <http://www.w3.org/2002/07/owl#Thing>, <http://www.w3.org/2002/07/owl#Nothing>)\n")))) {
            ok = 0;
        }
        if (!(test_ksc_form_is(arena, SLOP_STR("conjunction with a nominal"), SLOP_STR("[ a owl:Class ; owl:intersectionOf ( :C [ a owl:Class ; owl:oneOf ( :a ) ] :D ) ] rdfs:subClassOf owl:Nothing ."), SLOP_STR("subClass({<http://example.org/t#a>}, _:1)\nsubConj(<http://example.org/t#C>, _:1, _:0)\nsubConj(_:0, <http://example.org/t#D>, <http://www.w3.org/2002/07/owl#Nothing>)\n")))) {
            ok = 0;
        }
        return ok;
    }
}

slop_string test_omissions_of_ttl(slop_arena* arena, slop_string ttl) {
    __auto_type _mv_764 = test_gate_ttl(arena, ttl);
    if (!_mv_764.has_value) {
        return SLOP_STR("<did not gate>");
    } else if (_mv_764.has_value) {
        __auto_type gr = _mv_764.value;
        {
            __auto_type out = SLOP_STR("");
            {
                __auto_type _coll = gr.omissions;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type o = _coll.data[_i];
                    out = string_concat(arena, out, string_concat(arena, owl2_render_omission(arena, o), SLOP_STR("\n")));
                }
            }
            return out;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_omits_exactly(slop_arena* arena, slop_string label, slop_string ttl, slop_string want) {
    {
        __auto_type got = test_omissions_of_ttl(arena, string_concat(arena, test_eq_prefix(), ttl));
        if (canon_string_cmp(got, want) == 0) {
            return 1;
        } else {
            printf("%.*s\n", (int)(string_concat(arena, string_concat(arena, SLOP_STR("  [decode] "), label), SLOP_STR(": omitted"))).len, (string_concat(arena, string_concat(arena, SLOP_STR("  [decode] "), label), SLOP_STR(": omitted"))).data);
            printf("%.*s\n", (int)(got).len, (got).data);
            return 0;
        }
    }
}

slop_string test_eq_prefix(void) {
    return SLOP_STR("@prefix : <http://example.org/t#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .\n:r a owl:ObjectProperty .\n:a a owl:NamedIndividual . :b a owl:NamedIndividual .\n");
}

uint8_t test_test_equality_never_drops_an_operand(slop_arena* arena) {
    return ((test_omits_exactly(arena, SLOP_STR("sameAs, both named"), SLOP_STR(":a owl:sameAs :b ."), SLOP_STR("SameIndividual(http://example.org/t#a http://example.org/t#b)\n"))) && (test_omits_exactly(arena, SLOP_STR("sameAs, blank object"), SLOP_STR(":a owl:sameAs [] ."), SLOP_STR("AnonymousIndividual(<http://example.org/t#a> <http://www.w3.org/2002/07/owl#sameAs> _:b0 .)\n"))) && (test_omits_exactly(arena, SLOP_STR("differentFrom, blank subject"), SLOP_STR("[] owl:differentFrom :b ."), SLOP_STR("AnonymousIndividual(_:b0 <http://www.w3.org/2002/07/owl#differentFrom> <http://example.org/t#b> .)\n"))) && (test_omits_exactly(arena, SLOP_STR("sameAs, reserved IRI"), SLOP_STR(":a owl:sameAs owl:Nothing ."), SLOP_STR("ReservedVocabulary(<http://example.org/t#a> <http://www.w3.org/2002/07/owl#sameAs> <http://www.w3.org/2002/07/owl#Nothing> .)\n"))) && (test_omits_exactly(arena, SLOP_STR("sameAs, literal"), SLOP_STR(":a owl:sameAs \"x\" ."), SLOP_STR("DataAxiom(<http://example.org/t#a> <http://www.w3.org/2002/07/owl#sameAs> \"x\" .)\n"))) && (test_omits_exactly(arena, SLOP_STR("AllDifferent, literal member"), SLOP_STR("[] a owl:AllDifferent ; owl:members ( :a \"x\" ) ."), SLOP_STR("DataAxiom(_:b0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://www.w3.org/2002/07/owl#AllDifferent> .)\n"))));
}

uint8_t test_test_anonymous_members_are_omissions_not_faults(slop_arena* arena) {
    {
        __auto_type pre = test_eq_prefix();
        return ((test_decodes_ok(arena, string_concat(arena, pre, SLOP_STR("[] a owl:AllDifferent ; owl:members ( :a [] ) .")))) && (test_omits_exactly(arena, SLOP_STR("AllDifferent, anonymous member"), SLOP_STR("[] a owl:AllDifferent ; owl:members ( :a [] ) ."), SLOP_STR("AnonymousIndividual(_:b0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://www.w3.org/2002/07/owl#AllDifferent> .)\n"))) && (test_decodes_ok(arena, string_concat(arena, pre, SLOP_STR(":C a owl:Class . :C owl:equivalentClass [ a owl:Class ; owl:oneOf ( :a [] ) ] .")))) && (test_omits_exactly(arena, SLOP_STR("oneOf, anonymous member"), SLOP_STR(":C a owl:Class . :C owl:equivalentClass [ a owl:Class ; owl:oneOf ( :a [] ) ] ."), SLOP_STR("SubClassOf(AnonymousClass(owl:oneOf with an anonymous individual) http://example.org/t#C)\nSubClassOf(http://example.org/t#C AnonymousClass(owl:oneOf with an anonymous individual))\n"))));
    }
}

uint8_t test_test_negative_assertion_decodes_whole(slop_arena* arena) {
    {
        __auto_type pre = test_eq_prefix();
        return ((test_omits_exactly(arena, SLOP_STR("object form"), SLOP_STR("[] a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; owl:assertionProperty :r ; owl:targetIndividual :b ."), SLOP_STR("NegativeObjectPropertyAssertion(http://example.org/t#r http://example.org/t#a http://example.org/t#b)\n"))) && ((test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":d a owl:DatatypeProperty . [] a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; owl:assertionProperty :d ; owl:targetValue \"x\" ."))) == 1)) && ((test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR("[] a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; owl:assertionProperty :r ; owl:targetIndividual [] ."))) == 1)) && (!(test_decodes_ok(arena, string_concat(arena, pre, SLOP_STR("[] a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; owl:assertionProperty :r ."))))) && (!(test_decodes_ok(arena, string_concat(arena, pre, SLOP_STR("[] a owl:NegativePropertyAssertion ; owl:targetValue \"x\" ."))))) && (!(test_decodes_ok(arena, string_concat(arena, pre, SLOP_STR("[] a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; owl:assertionProperty :r ; owl:targetIndividual :b ; owl:targetValue \"x\" ."))))) && (!(test_decodes_ok(arena, string_concat(arena, pre, SLOP_STR("[] a owl:NegativePropertyAssertion ; owl:sourceIndividual :a , :b ; owl:assertionProperty :r ; owl:targetIndividual :b ."))))) && (test_omits_exactly(arena, SLOP_STR("stray part predicate"), SLOP_STR(":a owl:sourceIndividual :b ."), SLOP_STR("ReservedVocabulary(<http://example.org/t#a> <http://www.w3.org/2002/07/owl#sourceIndividual> <http://example.org/t#b> .)\n"))));
    }
}

uint8_t test_test_literal_has_value_is_data(slop_arena* arena) {
    return test_omits_exactly(arena, SLOP_STR("literal hasValue"), SLOP_STR(":C a owl:Class . :d a owl:DatatypeProperty . :C owl:equivalentClass [ a owl:Restriction ; owl:onProperty :d ; owl:hasValue \"x\" ] ."), SLOP_STR("SubClassOf(DataRange(owl:hasValue with a literal (DataHasValue)) http://example.org/t#C)\nSubClassOf(http://example.org/t#C DataRange(owl:hasValue with a literal (DataHasValue)))\n"));
}

slop_string test_neg_prefix(void) {
    return SLOP_STR("@prefix : <http://example.org/t#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n:A a owl:Class . :B a owl:Class . :C a owl:Class .\n:r a owl:ObjectProperty .\n");
}

uint8_t test_accepts_exactly(slop_arena* arena, slop_string label, slop_string ttl, slop_string want) {
    {
        __auto_type got = test_gate_accepted_of_ttl(arena, string_concat(arena, test_neg_prefix(), ttl));
        if (canon_string_cmp(got, want) == 0) {
            return 1;
        } else {
            printf("%.*s\n", (int)(string_concat(arena, string_concat(arena, SLOP_STR("  [negation] "), label), SLOP_STR(": accepted"))).len, (string_concat(arena, string_concat(arena, SLOP_STR("  [negation] "), label), SLOP_STR(": accepted"))).data);
            printf("%.*s\n", (int)(got).len, (got).data);
            return 0;
        }
    }
}

uint8_t test_test_negation_rewrites_to_bottom_gcis(slop_arena* arena) {
    return ((test_accepts_exactly(arena, SLOP_STR("range"), SLOP_STR(":r rdfs:range [ owl:intersectionOf ( :A [ owl:complementOf :B ] ) ] ."), SLOP_STR("ObjectPropertyRange(http://example.org/t#r http://example.org/t#A)\nSubClassOf(ObjectSomeValuesFrom(http://example.org/t#r http://example.org/t#B) owl:Nothing)\n"))) && (test_accepts_exactly(arena, SLOP_STR("domain"), SLOP_STR(":r rdfs:domain [ owl:complementOf :B ] ."), SLOP_STR("SubClassOf(ObjectIntersectionOf(ObjectSomeValuesFrom(http://example.org/t#r owl:Thing) http://example.org/t#B) owl:Nothing)\n"))) && (test_accepts_exactly(arena, SLOP_STR("superclass"), SLOP_STR(":C rdfs:subClassOf [ owl:intersectionOf ( :A [ owl:complementOf [ a owl:Restriction ; owl:onProperty :r ; owl:someValuesFrom :B ] ] [ owl:complementOf :B ] ) ] ."), SLOP_STR("SubClassOf(ObjectIntersectionOf(http://example.org/t#C ObjectSomeValuesFrom(http://example.org/t#r http://example.org/t#B)) owl:Nothing)\nSubClassOf(ObjectIntersectionOf(http://example.org/t#C http://example.org/t#B) owl:Nothing)\nSubClassOf(http://example.org/t#C http://example.org/t#A)\n"))) && (test_accepts_exactly(arena, SLOP_STR("conjunction on the left"), SLOP_STR("[ owl:intersectionOf ( :A :C ) ] rdfs:subClassOf [ owl:complementOf :B ] ."), SLOP_STR("SubClassOf(ObjectIntersectionOf(http://example.org/t#A http://example.org/t#C http://example.org/t#B) owl:Nothing)\n"))));
}

uint8_t test_test_negation_rewrites_whole_axioms_or_none(slop_arena* arena) {
    {
        __auto_type pre = test_neg_prefix();
        return ((test_accepts_exactly(arena, SLOP_STR("E out of profile"), SLOP_STR(":r rdfs:range [ owl:intersectionOf ( :A [ owl:complementOf [ owl:unionOf ( :B :C ) ] ] ) ] ."), SLOP_STR(""))) && ((test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":r rdfs:range [ owl:intersectionOf ( :A [ owl:complementOf [ owl:unionOf ( :B :C ) ] ] ) ] ."))) == 1)) && (test_accepts_exactly(arena, SLOP_STR("C out of profile"), SLOP_STR("[ owl:unionOf ( :A :C ) ] rdfs:subClassOf [ owl:complementOf :B ] ."), SLOP_STR(""))) && (test_accepts_exactly(arena, SLOP_STR("under an existential"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:someValuesFrom [ owl:complementOf :B ] ] ."), SLOP_STR(""))));
    }
}

uint8_t test_test_negative_range_normalizes_to_bottom(slop_arena* arena) {
    {
        __auto_type b_cls = test_cls(SLOP_STR("http://example.org/t#B"));
        __auto_type r = test_rol(SLOP_STR("http://example.org/t#r"));
        __auto_type _mv_765 = test_normalize_fixture(arena, SLOP_STR("corpus/fixtures/probes/complement-range.ttl"));
        if (!_mv_765.has_value) {
            return 0;
        } else if (_mv_765.has_value) {
            __auto_type no = _mv_765.value;
            {
                __auto_type ax = no.axioms;
                slop_option_types_Node target = (slop_option_types_Node){.has_value = false};
                {
                    __auto_type _coll = ax;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type a = _coll.data[_i];
                        __auto_type _mv_766 = a;
                        switch (_mv_766.tag) {
                            case types_NormAxiom_sub_some_lhs:
                            {
                                __auto_type rr = _mv_766.data.sub_some_lhs.f0;
                                __auto_type c = _mv_766.data.sub_some_lhs.f1;
                                __auto_type d = _mv_766.data.sub_some_lhs.f2;
                                if (types_role_eq(rr, r) && types_node_eq(c, b_cls)) {
                                    target = (slop_option_types_Node){.has_value = 1, .value = d};
                                }
                                break;
                            }
                            default: {
                                break;
                            }
                        }
                    }
                }
                __auto_type _mv_767 = target;
                if (!_mv_767.has_value) {
                    return 0;
                } else if (_mv_767.has_value) {
                    __auto_type x = _mv_767.value;
                    return (({ __auto_type _mv = x; uint8_t _mr = {0}; switch (_mv.tag) { case types_Node_fresh_node: { __auto_type _ = _mv.data.fresh_node; _mr = 1; break; } default: { _mr = 0; break; }  } _mr; }) && test_norm_contains(ax, ((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = x, .f1 = types_node_bottom() } })));
                }
                SLOP_UNREACHABLE();
            }
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_norm_eq(types_NormAxiom a, types_NormAxiom b) {
    __auto_type _mv_768 = a;
    switch (_mv_768.tag) {
        case types_NormAxiom_sub_name:
        {
            __auto_type x = _mv_768.data.sub_name.f0;
            __auto_type y = _mv_768.data.sub_name.f1;
            __auto_type _mv_769 = b;
            switch (_mv_769.tag) {
                case types_NormAxiom_sub_name:
                {
                    __auto_type p = _mv_769.data.sub_name.f0;
                    __auto_type q = _mv_769.data.sub_name.f1;
                    return (types_node_eq(x, p) && types_node_eq(y, q));
                }
                default: {
                    return 0;
                }
            }
        }
        case types_NormAxiom_sub_and:
        {
            __auto_type x = _mv_768.data.sub_and.f0;
            __auto_type y = _mv_768.data.sub_and.f1;
            __auto_type z = _mv_768.data.sub_and.f2;
            __auto_type _mv_770 = b;
            switch (_mv_770.tag) {
                case types_NormAxiom_sub_and:
                {
                    __auto_type p = _mv_770.data.sub_and.f0;
                    __auto_type q = _mv_770.data.sub_and.f1;
                    __auto_type r = _mv_770.data.sub_and.f2;
                    return ((types_node_eq(x, p)) && (types_node_eq(y, q)) && (types_node_eq(z, r)));
                }
                default: {
                    return 0;
                }
            }
        }
        case types_NormAxiom_sub_some_rhs:
        {
            __auto_type x = _mv_768.data.sub_some_rhs.f0;
            __auto_type r = _mv_768.data.sub_some_rhs.f1;
            __auto_type y = _mv_768.data.sub_some_rhs.f2;
            __auto_type _mv_771 = b;
            switch (_mv_771.tag) {
                case types_NormAxiom_sub_some_rhs:
                {
                    __auto_type p = _mv_771.data.sub_some_rhs.f0;
                    __auto_type q = _mv_771.data.sub_some_rhs.f1;
                    __auto_type z = _mv_771.data.sub_some_rhs.f2;
                    return ((types_node_eq(x, p)) && (types_role_eq(r, q)) && (types_node_eq(y, z)));
                }
                default: {
                    return 0;
                }
            }
        }
        case types_NormAxiom_sub_some_lhs:
        {
            __auto_type r = _mv_768.data.sub_some_lhs.f0;
            __auto_type x = _mv_768.data.sub_some_lhs.f1;
            __auto_type y = _mv_768.data.sub_some_lhs.f2;
            __auto_type _mv_772 = b;
            switch (_mv_772.tag) {
                case types_NormAxiom_sub_some_lhs:
                {
                    __auto_type q = _mv_772.data.sub_some_lhs.f0;
                    __auto_type p = _mv_772.data.sub_some_lhs.f1;
                    __auto_type z = _mv_772.data.sub_some_lhs.f2;
                    return ((types_role_eq(r, q)) && (types_node_eq(x, p)) && (types_node_eq(y, z)));
                }
                default: {
                    return 0;
                }
            }
        }
        case types_NormAxiom_sub_role:
        {
            __auto_type r = _mv_768.data.sub_role.f0;
            __auto_type s2 = _mv_768.data.sub_role.f1;
            __auto_type _mv_773 = b;
            switch (_mv_773.tag) {
                case types_NormAxiom_sub_role:
                {
                    __auto_type q = _mv_773.data.sub_role.f0;
                    __auto_type t2 = _mv_773.data.sub_role.f1;
                    return (types_role_eq(r, q) && types_role_eq(s2, t2));
                }
                default: {
                    return 0;
                }
            }
        }
        case types_NormAxiom_role_chain:
        {
            __auto_type r = _mv_768.data.role_chain.f0;
            __auto_type s2 = _mv_768.data.role_chain.f1;
            __auto_type t2 = _mv_768.data.role_chain.f2;
            __auto_type _mv_774 = b;
            switch (_mv_774.tag) {
                case types_NormAxiom_role_chain:
                {
                    __auto_type q = _mv_774.data.role_chain.f0;
                    __auto_type u = _mv_774.data.role_chain.f1;
                    __auto_type v = _mv_774.data.role_chain.f2;
                    return ((types_role_eq(r, q)) && (types_role_eq(s2, u)) && (types_role_eq(t2, v)));
                }
                default: {
                    return 0;
                }
            }
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_norm_contains(slop_list_types_NormAxiom xs, types_NormAxiom a) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (test_norm_eq(x, a)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_option_normalize_NormOutput test_normalize_fixture(slop_arena* arena, slop_string path) {
    __auto_type _mv_775 = test_gate_fixture(arena, path);
    if (!_mv_775.has_value) {
        return (slop_option_normalize_NormOutput){.has_value = false};
    } else if (_mv_775.has_value) {
        __auto_type gr = _mv_775.value;
        return (slop_option_normalize_NormOutput){.has_value = 1, .value = normalize_normalize_accepted(arena, gr.accepted)};
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_litmus_reproduces_the_m1_normal_form(slop_arena* arena) {
    {
        __auto_type person = test_cls(SLOP_STR("http://example.org/t#Person"));
        __auto_type parent = test_cls(SLOP_STR("http://example.org/t#Parent"));
        __auto_type mother = test_cls(SLOP_STR("http://example.org/t#Mother"));
        __auto_type hc = test_rol(SLOP_STR("http://example.org/t#hasChild"));
        __auto_type x = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = 0 });
        __auto_type _mv_776 = test_normalize_fixture(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl"));
        if (!_mv_776.has_value) {
            return 0;
        } else if (_mv_776.has_value) {
            __auto_type no = _mv_776.value;
            {
                __auto_type ax = no.axioms;
                return (((((int64_t)(((int64_t)((ax).len)))) == 6)) && ((no.fresh_count == 1)) && (test_norm_contains(ax, ((types_NormAxiom){ .tag = types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = hc, .f1 = person, .f2 = x } }))) && (test_norm_contains(ax, ((types_NormAxiom){ .tag = types_NormAxiom_sub_and, .data.sub_and = { .f0 = person, .f1 = x, .f2 = parent } }))) && (test_norm_contains(ax, ((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = parent, .f1 = person } }))) && (test_norm_contains(ax, ((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = parent, .f1 = hc, .f2 = person } }))) && (test_norm_contains(ax, ((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = mother, .f1 = person } }))) && (test_norm_contains(ax, ((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = mother, .f1 = hc, .f2 = person } }))));
            }
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_normalization_polarity_is_negative_on_the_left(slop_arena* arena) {
    {
        __auto_type person = test_cls(SLOP_STR("http://example.org/t#Person"));
        __auto_type hc = test_rol(SLOP_STR("http://example.org/t#hasChild"));
        __auto_type x = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = 0 });
        __auto_type _mv_777 = test_normalize_fixture(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl"));
        if (!_mv_777.has_value) {
            return 0;
        } else if (_mv_777.has_value) {
            __auto_type no = _mv_777.value;
            return (test_norm_contains(no.axioms, ((types_NormAxiom){ .tag = types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = hc, .f1 = person, .f2 = x } })) && !(test_norm_contains(no.axioms, ((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = x, .f1 = hc, .f2 = person } }))));
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_range_elimination_introduces_a_shared_filler(slop_arena* arena) {
    {
        __auto_type a_cls = test_cls(SLOP_STR("http://example.org/t#A"));
        __auto_type b_cls = test_cls(SLOP_STR("http://example.org/t#B"));
        __auto_type r = test_rol(SLOP_STR("http://example.org/t#r"));
        __auto_type _mv_778 = test_normalize_fixture(arena, SLOP_STR("corpus/fixtures/v0/range.ttl"));
        if (!_mv_778.has_value) {
            return 0;
        } else if (_mv_778.has_value) {
            __auto_type no = _mv_778.value;
            {
                __auto_type ax = no.axioms;
                slop_option_types_Node filler = (slop_option_types_Node){.has_value = false};
                {
                    __auto_type _coll = ax;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type a = _coll.data[_i];
                        __auto_type _mv_779 = a;
                        switch (_mv_779.tag) {
                            case types_NormAxiom_sub_some_rhs:
                            {
                                __auto_type c = _mv_779.data.sub_some_rhs.f0;
                                __auto_type rr = _mv_779.data.sub_some_rhs.f1;
                                __auto_type d = _mv_779.data.sub_some_rhs.f2;
                                if (types_node_eq(c, b_cls) && types_role_eq(rr, r)) {
                                    filler = (slop_option_types_Node){.has_value = 1, .value = d};
                                }
                                break;
                            }
                            default: {
                                break;
                            }
                        }
                    }
                }
                __auto_type _mv_780 = filler;
                if (!_mv_780.has_value) {
                    return 0;
                } else if (_mv_780.has_value) {
                    __auto_type x = _mv_780.value;
                    return (({ __auto_type _mv = x; uint8_t _mr = {0}; switch (_mv.tag) { case types_Node_fresh_node: { __auto_type _ = _mv.data.fresh_node; _mr = 1; break; } default: { _mr = 0; break; }  } _mr; }) && test_norm_contains(ax, ((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = x, .f1 = a_cls } })));
                }
                SLOP_UNREACHABLE();
            }
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_asserted_edges_seed_their_range(slop_arena* arena) {
    {
        __auto_type c_cls = test_cls(SLOP_STR("http://example.org/t#C"));
        __auto_type d_cls = test_cls(SLOP_STR("http://example.org/t#D"));
        __auto_type b_ind = ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = ((rdf_IRI){.value = SLOP_STR("http://example.org/t#b")}) });
        __auto_type _mv_781 = test_normalize_fixture(arena, SLOP_STR("corpus/fixtures/hazards/abox-disjoint-range.ttl"));
        if (!_mv_781.has_value) {
            return 0;
        } else if (_mv_781.has_value) {
            __auto_type no = _mv_781.value;
            {
                __auto_type saw_c = 0;
                __auto_type saw_d = 0;
                __auto_type edges = ((int64_t)(((int64_t)((no.edges).len))));
                {
                    __auto_type _coll = no.seeds;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type sd = _coll.data[_i];
                        if (types_node_eq(sd.to, b_ind)) {
                            __auto_type _mv_782 = sd.what;
                            switch (_mv_782.tag) {
                                case types_Derived_derived_sub:
                                {
                                    __auto_type x = _mv_782.data.derived_sub;
                                    if (types_node_eq(x, c_cls)) {
                                        saw_c = 1;
                                    }
                                    if (types_node_eq(x, d_cls)) {
                                        saw_d = 1;
                                    }
                                    break;
                                }
                                default: {
                                    break;
                                }
                            }
                        }
                    }
                }
                return (((edges == 2)) && (saw_c) && (saw_d));
            }
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_range_complex_fillers_stay_apart(slop_arena* arena) {
    {
        __auto_type path = SLOP_STR("corpus/fixtures/hazards/range-complex-fillers.ttl");
        return (test_complex_range_fillers_distinct(arena, path) && ({ __auto_type _mv = test_classify_fixture(arena, path); _mv.has_value ? ({ __auto_type o = _mv.value; ((((int64_t)(((int64_t)((o.findings.unsatisfiable).len)))) == 0) && (howl_verdict(o) == howl_Verdict_verdict_coherent ? 1 : 0)); }) : (0); }));
    }
}

uint8_t test_complex_range_fillers_distinct(slop_arena* arena, slop_string path) {
    {
        __auto_type c1 = test_cls(SLOP_STR("http://example.org/t#C1"));
        __auto_type c2 = test_cls(SLOP_STR("http://example.org/t#C2"));
        __auto_type r = test_rol(SLOP_STR("http://example.org/t#r"));
        __auto_type _mv_783 = test_normalize_fixture(arena, path);
        if (!_mv_783.has_value) {
            return 0;
        } else if (_mv_783.has_value) {
            __auto_type no = _mv_783.value;
            {
                slop_option_types_Node f1 = (slop_option_types_Node){.has_value = false};
                slop_option_types_Node f2 = (slop_option_types_Node){.has_value = false};
                {
                    __auto_type _coll = no.axioms;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type a = _coll.data[_i];
                        __auto_type _mv_784 = a;
                        switch (_mv_784.tag) {
                            case types_NormAxiom_sub_some_rhs:
                            {
                                __auto_type c = _mv_784.data.sub_some_rhs.f0;
                                __auto_type rr = _mv_784.data.sub_some_rhs.f1;
                                __auto_type d = _mv_784.data.sub_some_rhs.f2;
                                if (types_role_eq(rr, r)) {
                                    if (types_node_eq(c, c1)) {
                                        f1 = (slop_option_types_Node){.has_value = 1, .value = d};
                                    }
                                    if (types_node_eq(c, c2)) {
                                        f2 = (slop_option_types_Node){.has_value = 1, .value = d};
                                    }
                                }
                                break;
                            }
                            default: {
                                break;
                            }
                        }
                    }
                }
                __auto_type _mv_785 = f1;
                if (!_mv_785.has_value) {
                    return 0;
                } else if (_mv_785.has_value) {
                    __auto_type x1 = _mv_785.value;
                    __auto_type _mv_786 = f2;
                    if (!_mv_786.has_value) {
                        return 0;
                    } else if (_mv_786.has_value) {
                        __auto_type x2 = _mv_786.value;
                        return !(types_node_eq(x1, x2));
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            }
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_inverse_expressions_are_omissions(slop_arena* arena) {
    {
        __auto_type path = SLOP_STR("corpus/fixtures/out-of-profile/inverse-expressions.ttl");
        __auto_type pre = SLOP_STR("@prefix : <http://example.org/t#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n:p a owl:ObjectProperty . :q a owl:ObjectProperty .\n");
        return (((test_out_of_profile_count_of(arena, path) >= 2)) && (({ __auto_type _mv = test_classify_fixture(arena, path); _mv.has_value ? ({ __auto_type o = _mv.value; ((((int64_t)(((int64_t)((o.coverage.omitted).len)))) >= 3) && (howl_verdict(o) == howl_Verdict_verdict_inconclusive ? 1 : 0)); }) : (0); })) && (test_decodes_ok(arena, string_concat(arena, pre, SLOP_STR(":q rdfs:subPropertyOf [ owl:inverseOf :p ] .")))) && (!(test_decodes_ok(arena, string_concat(arena, pre, SLOP_STR(":q rdfs:subPropertyOf [ ] ."))))));
    }
}

slop_list_string test_m0_fixture_paths(slop_arena* arena) {
    {
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subclass-atomic.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/intersection.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-lhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-rhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-classes.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-properties.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-binary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subproperty.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/transitive.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/domain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/abox-assertions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/top-bottom.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/litmus.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-superclass.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-domain-range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/range-complex-fillers.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/abox-disjoint-range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ps;
    }
}

uint8_t test_accounting_exempt(owl2_RawAxiom ax) {
    __auto_type _mv_787 = ax;
    switch (_mv_787.tag) {
        case owl2_RawAxiom_ra_object_property_range:
        {
            return 1;
        }
        case owl2_RawAxiom_ra_declaration:
        {
            __auto_type _ = _mv_787.data.ra_declaration;
            return 1;
        }
        case owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type r = _mv_787.data.ra_sub_class_of.f1;
            __auto_type _mv_788 = (*r);
            switch (_mv_788.tag) {
                case owl2_RawConcept_rc_thing:
                {
                    return 1;
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

uint8_t test_axiom_accounted(slop_arena* arena, owl2_RawAxiom ax) {
    {
        __auto_type one = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(one); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type no = normalize_normalize_accepted(arena, one);
            return ((test_accounting_exempt(ax)) || ((((int64_t)(((int64_t)((no.axioms).len)))) > 0)) || ((((int64_t)(((int64_t)((no.edges).len)))) > 0)) || ((((int64_t)(((int64_t)((no.seeds).len)))) > 0)));
        }
    }
}

uint8_t test_test_accounting_holds(slop_arena* arena) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = test_m0_fixture_paths(arena);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                __auto_type _mv_789 = test_gate_fixture(arena, p);
                if (!_mv_789.has_value) {
                    printf("%s", "  [accounting] did not gate: ");
                    printf("%.*s\n", (int)(p).len, (p).data);
                    ok = 0;
                } else if (_mv_789.has_value) {
                    __auto_type gr = _mv_789.value;
                    {
                        __auto_type _coll = gr.accepted;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ax = _coll.data[_i];
                            if (!(test_axiom_accounted(arena, ax))) {
                                printf("%s", "  [accounting] undischarged in ");
                                printf("%.*s", (int)(p).len, (p).data);
                                printf("%s", ": ");
                                printf("%.*s\n", (int)(owl2_render_axiom(arena, ax)).len, (owl2_render_axiom(arena, ax)).data);
                                ok = 0;
                            }
                        }
                    }
                }
            }
        }
        return ok;
    }
}

uint8_t test_same_rendering(slop_arena* arena, slop_list_owl2_RawAxiom xs, slop_list_owl2_RawAxiom ys) {
    {
        uint8_t ok = (((int64_t)((xs).len)) == ((int64_t)((ys).len)));
        int64_t i = 0;
        __auto_type n = ((int64_t)(((int64_t)((xs).len))));
        while (ok && (i < n)) {
            __auto_type _mv_790 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_owl2_RawAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_790.has_value) {
                __auto_type x = _mv_790.value;
                __auto_type _mv_791 = ({ __auto_type _lst = ys; size_t _idx = (size_t)i; slop_option_owl2_RawAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_791.has_value) {
                    __auto_type y = _mv_791.value;
                    if (!(string_eq(owl2_render_axiom(arena, x), owl2_render_axiom(arena, y)))) {
                        ok = 0;
                    }
                } else if (!_mv_791.has_value) {
                    ok = 0;
                }
            } else if (!_mv_790.has_value) {
                ok = 0;
            }
            i = (i + 1);
        }
        return ok;
    }
}

uint8_t test_test_canonicalization_is_idempotent(slop_arena* arena) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = test_m0_fixture_paths(arena);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                __auto_type _mv_792 = test_gate_fixture(arena, p);
                if (!_mv_792.has_value) {
                    ok = 0;
                } else if (_mv_792.has_value) {
                    __auto_type gr = _mv_792.value;
                    {
                        __auto_type again = gate_gate_axioms(arena, gr.accepted, gr.signature, ((slop_list_types_Omission){ .data = NULL, .len = 0, .cap = 0 }), types_Profile_profile_el);
                        if (!(test_same_rendering(arena, gr.accepted, again.accepted))) {
                            printf("%s", "  [idempotence] regating changed ");
                            printf("%.*s\n", (int)(p).len, (p).data);
                            ok = 0;
                        }
                    }
                }
            }
        }
        return ok;
    }
}

slop_list_types_Node test_norm_nodes(slop_arena* arena, types_NormAxiom ax) {
    {
        __auto_type out = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_793 = ax;
        switch (_mv_793.tag) {
            case types_NormAxiom_sub_name:
            {
                __auto_type a = _mv_793.data.sub_name.f0;
                __auto_type b = _mv_793.data.sub_name.f1;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_NormAxiom_sub_and:
            {
                __auto_type a = _mv_793.data.sub_and.f0;
                __auto_type b = _mv_793.data.sub_and.f1;
                __auto_type c = _mv_793.data.sub_and.f2;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_NormAxiom_sub_some_lhs:
            {
                __auto_type r = _mv_793.data.sub_some_lhs.f0;
                __auto_type a = _mv_793.data.sub_some_lhs.f1;
                __auto_type b = _mv_793.data.sub_some_lhs.f2;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_NormAxiom_sub_some_rhs:
            {
                __auto_type a = _mv_793.data.sub_some_rhs.f0;
                __auto_type r = _mv_793.data.sub_some_rhs.f1;
                __auto_type b = _mv_793.data.sub_some_rhs.f2;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_NormAxiom_sub_role:
            {
                __auto_type r = _mv_793.data.sub_role.f0;
                __auto_type s = _mv_793.data.sub_role.f1;
                break;
            }
            case types_NormAxiom_role_chain:
            {
                __auto_type r = _mv_793.data.role_chain.f0;
                __auto_type s = _mv_793.data.role_chain.f1;
                __auto_type t = _mv_793.data.role_chain.f2;
                break;
            }
        }
        return out;
    }
}

uint8_t test_fresh_ids_dense(slop_arena* arena, normalize_NormOutput no) {
    {
        __auto_type n = no.fresh_count;
        __auto_type seen = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0 });
        uint8_t ok = 1;
        int64_t i = 0;
        while (i < n) {
            ({ __auto_type _lst_p = &(seen); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        {
            __auto_type _coll = no.axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                {
                    __auto_type _coll = test_norm_nodes(arena, ax);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type nd = _coll.data[_i];
                        __auto_type _mv_794 = nd;
                        switch (_mv_794.tag) {
                            case types_Node_fresh_node:
                            {
                                __auto_type k = _mv_794.data.fresh_node;
                                if (k < n) {
                                    ({ __auto_type _set_lst = &(seen); size_t _set_idx = (size_t)(k); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
                                }
                                if (k >= n) {
                                    ok = 0;
                                }
                                break;
                            }
                            case types_Node_class_node:
                            {
                                __auto_type _ = _mv_794.data.class_node;
                                break;
                            }
                            case types_Node_individual_node:
                            {
                                __auto_type _ = _mv_794.data.individual_node;
                                break;
                            }
                        }
                    }
                }
            }
        }
        {
            __auto_type _coll = seen;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                if (!(b)) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t test_test_fresh_nodes_are_fresh(slop_arena* arena) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = test_m0_fixture_paths(arena);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                __auto_type _mv_795 = test_normalize_fixture(arena, p);
                if (!_mv_795.has_value) {
                    ok = 0;
                } else if (_mv_795.has_value) {
                    __auto_type no = _mv_795.value;
                    if (!(test_fresh_ids_dense(arena, no))) {
                        printf("%s", "  [freshness] ");
                        printf("%.*s\n", (int)(p).len, (p).data);
                        ok = 0;
                    }
                }
            }
        }
        return ok;
    }
}

slop_list_rdf_Triple test_reversed_triples(slop_arena* arena, slop_list_rdf_Triple ts) {
    {
        __auto_type out = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0 });
        int64_t k = (((int64_t)(((int64_t)((ts).len)))) - 1);
        while (k >= 0) {
            __auto_type _mv_796 = ({ __auto_type _lst = ts; size_t _idx = (size_t)k; slop_option_rdf_Triple _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_796.has_value) {
                __auto_type t = _mv_796.value;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_796.has_value) {
            }
            k = (k - 1);
        }
        return out;
    }
}

slop_option_normalize_NormOutput test_normalize_triples(slop_arena* arena, slop_list_rdf_Triple ts) {
    __auto_type _mv_797 = decode_stage0_header(arena, ts, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }));
    if (!_mv_797.is_ok) {
        __auto_type _ = _mv_797.data.err;
        return (slop_option_normalize_NormOutput){.has_value = false};
    } else if (_mv_797.is_ok) {
        __auto_type s0 = _mv_797.data.ok;
        __auto_type _mv_798 = decode_decode_axioms(arena, s0.dict, s0.triples);
        if (!_mv_798.is_ok) {
            __auto_type _ = _mv_798.data.err;
            return (slop_option_normalize_NormOutput){.has_value = false};
        } else if (_mv_798.is_ok) {
            __auto_type s1 = _mv_798.data.ok;
            return (slop_option_normalize_NormOutput){.has_value = 1, .value = normalize_normalize_accepted(arena, gate_gate_axioms(arena, s1.axioms, s1.signature, s0.omissions, types_Profile_profile_el).accepted)};
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_same_normal_form(normalize_NormOutput a, normalize_NormOutput b) {
    {
        uint8_t ok = ((a.fresh_count == b.fresh_count) && (((int64_t)((a.axioms).len)) == ((int64_t)((b.axioms).len))));
        int64_t i = 0;
        __auto_type n = ((int64_t)(((int64_t)((a.axioms).len))));
        while (ok && (i < n)) {
            __auto_type _mv_799 = ({ __auto_type _lst = a.axioms; size_t _idx = (size_t)i; slop_option_types_NormAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_799.has_value) {
                __auto_type x = _mv_799.value;
                __auto_type _mv_800 = ({ __auto_type _lst = b.axioms; size_t _idx = (size_t)i; slop_option_types_NormAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_800.has_value) {
                    __auto_type y = _mv_800.value;
                    if (!(test_norm_eq(x, y))) {
                        ok = 0;
                    }
                } else if (!_mv_800.has_value) {
                    ok = 0;
                }
            } else if (!_mv_799.has_value) {
                ok = 0;
            }
            i = (i + 1);
        }
        return ok;
    }
}

uint8_t test_same_report(types_Outcome a, types_Outcome b) {
    {
        __auto_type sa = a.findings.subsumptions;
        __auto_type sb = b.findings.subsumptions;
        __auto_type ua = a.findings.unsatisfiable;
        __auto_type ub = b.findings.unsatisfiable;
        __auto_type oa = a.coverage.omitted;
        __auto_type ob = b.coverage.omitted;
        uint8_t ok = 1;
        int64_t i = 0;
        if (((((int64_t)((sa).len)) != ((int64_t)((sb).len)))) || ((((int64_t)((ua).len)) != ((int64_t)((ub).len)))) || ((((int64_t)((oa).len)) != ((int64_t)((ob).len))))) {
            ok = 0;
        }
        while (ok && (i < ((int64_t)(((int64_t)((sa).len)))))) {
            __auto_type _mv_801 = ({ __auto_type _lst = sa; size_t _idx = (size_t)i; slop_option_types_SubPair _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_801.has_value) {
                __auto_type x = _mv_801.value;
                __auto_type _mv_802 = ({ __auto_type _lst = sb; size_t _idx = (size_t)i; slop_option_types_SubPair _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_802.has_value) {
                    __auto_type y = _mv_802.value;
                    if (canon_sub_pair_cmp(x, y) != 0) {
                        ok = 0;
                    }
                } else if (!_mv_802.has_value) {
                    ok = 0;
                }
            } else if (!_mv_801.has_value) {
                ok = 0;
            }
            i = (i + 1);
        }
        i = 0;
        while (ok && (i < ((int64_t)(((int64_t)((ua).len)))))) {
            __auto_type _mv_803 = ({ __auto_type _lst = ua; size_t _idx = (size_t)i; slop_option_rdf_IRI _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_803.has_value) {
                __auto_type x = _mv_803.value;
                __auto_type _mv_804 = ({ __auto_type _lst = ub; size_t _idx = (size_t)i; slop_option_rdf_IRI _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_804.has_value) {
                    __auto_type y = _mv_804.value;
                    if (canon_iri_cmp(x, y) != 0) {
                        ok = 0;
                    }
                } else if (!_mv_804.has_value) {
                    ok = 0;
                }
            } else if (!_mv_803.has_value) {
                ok = 0;
            }
            i = (i + 1);
        }
        i = 0;
        while (ok && (i < ((int64_t)(((int64_t)((oa).len)))))) {
            __auto_type _mv_805 = ({ __auto_type _lst = oa; size_t _idx = (size_t)i; slop_option_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_805.has_value) {
                __auto_type x = _mv_805.value;
                __auto_type _mv_806 = ({ __auto_type _lst = ob; size_t _idx = (size_t)i; slop_option_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_806.has_value) {
                    __auto_type y = _mv_806.value;
                    if (canon_omission_cmp(x, y) != 0) {
                        ok = 0;
                    }
                } else if (!_mv_806.has_value) {
                    ok = 0;
                }
            } else if (!_mv_805.has_value) {
                ok = 0;
            }
            i = (i + 1);
        }
        return ok;
    }
}

uint8_t test_same_lines(slop_list_string a, slop_list_string b) {
    {
        uint8_t ok = 1;
        int64_t i = 0;
        if (((int64_t)((a).len)) != ((int64_t)((b).len))) {
            ok = 0;
        }
        while (ok && (i < ((int64_t)(((int64_t)((a).len)))))) {
            __auto_type _mv_807 = ({ __auto_type _lst = a; size_t _idx = (size_t)i; slop_option_string _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_807.has_value) {
                __auto_type x = _mv_807.value;
                __auto_type _mv_808 = ({ __auto_type _lst = b; size_t _idx = (size_t)i; slop_option_string _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_808.has_value) {
                    __auto_type y = _mv_808.value;
                    if (!(string_eq(x, y))) {
                        ok = 0;
                    }
                } else if (!_mv_808.has_value) {
                    ok = 0;
                }
            } else if (!_mv_807.has_value) {
                ok = 0;
            }
            i = (i + 1);
        }
        return ok;
    }
}

uint8_t test_order_independent(slop_arena* arena, slop_string path) {
    __auto_type _mv_809 = ttl_parse_ttl_file(arena, path);
    if (!_mv_809.is_ok) {
        __auto_type _ = _mv_809.data.err;
        return 0;
    } else if (_mv_809.is_ok) {
        __auto_type g = _mv_809.data.ok;
        {
            __auto_type fwd = g.triples;
            __auto_type rev = test_reversed_triples(arena, g.triples);
            __auto_type _mv_810 = test_normalize_triples(arena, fwd);
            if (!_mv_810.has_value) {
                return 0;
            } else if (_mv_810.has_value) {
                __auto_type n1 = _mv_810.value;
                __auto_type _mv_811 = test_normalize_triples(arena, rev);
                if (!_mv_811.has_value) {
                    return 0;
                } else if (_mv_811.has_value) {
                    __auto_type n2 = _mv_811.value;
                    if (!(test_same_normal_form(n1, n2))) {
                        printf("%s", "  [order] normal form differs: ");
                        printf("%.*s\n", (int)(path).len, (path).data);
                        return 0;
                    } else {
                        __auto_type _mv_812 = howl_classify(arena, fwd, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }), howl_default_config());
                        if (!_mv_812.is_ok) {
                            __auto_type _ = _mv_812.data.err;
                            return 0;
                        } else if (_mv_812.is_ok) {
                            __auto_type o1 = _mv_812.data.ok;
                            __auto_type _mv_813 = howl_classify(arena, rev, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }), howl_default_config());
                            if (!_mv_813.is_ok) {
                                __auto_type _ = _mv_813.data.err;
                                return 0;
                            } else if (_mv_813.is_ok) {
                                __auto_type o2 = _mv_813.data.ok;
                                if (test_same_report(o1, o2) && test_same_lines(report_report_lines(arena, o1), report_report_lines(arena, o2))) {
                                    return 1;
                                } else {
                                    printf("%s", "  [order] report differs: ");
                                    printf("%.*s\n", (int)(path).len, (path).data);
                                    return 0;
                                }
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
    SLOP_UNREACHABLE();
}

uint8_t test_test_triple_order_independence(slop_arena* arena) {
    {
        uint8_t ok = 1;
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/litmus.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/range-complex-fillers.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/abox-disjoint-range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/rbox-regularity-reject.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/annotation-heavy.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/inverse-expressions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (!(test_order_independent(arena, p))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t test_addressed_subset(slop_list_types_Addressed xs, slop_list_types_Addressed ys) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                {
                    uint8_t found = 0;
                    {
                        __auto_type _coll = ys;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type y = _coll.data[_i];
                            if (types_addressed_eq(x, y)) {
                                found = 1;
                            }
                        }
                    }
                    if (!(found)) {
                        ok = 0;
                    }
                }
            }
        }
        return ok;
    }
}

uint8_t test_same_conclusions(slop_arena* arena, types_Context ctx, types_Derived d, premise_RuleIndex idx, slop_list_types_NormAxiom axioms) {
    {
        __auto_type xs = el_apply_el_rules(arena, ctx, d, idx);
        __auto_type ys = el_apply_el_rules_reference(arena, ctx, d, axioms);
        if (test_addressed_subset(xs, ys)) {
            return test_addressed_subset(ys, xs);
        } else {
            return 0;
        }
    }
}

uint8_t test_dispatch_agrees(slop_arena* arena, slop_string path) {
    __auto_type _mv_814 = ttl_parse_ttl_file(arena, path);
    if (!_mv_814.is_ok) {
        __auto_type _ = _mv_814.data.err;
        return 0;
    } else if (_mv_814.is_ok) {
        __auto_type g = _mv_814.data.ok;
        __auto_type _mv_815 = howl_prepare(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }), howl_default_config());
        if (!_mv_815.is_ok) {
            __auto_type _ = _mv_815.data.err;
            return 0;
        } else if (_mv_815.is_ok) {
            __auto_type p = _mv_815.data.ok;
            {
                __auto_type idx = p.index;
                __auto_type axioms = p.axioms;
                __auto_type _mv_816 = howl_reason(arena, p, howl_default_config());
                if (!_mv_816.is_ok) {
                    __auto_type _ = _mv_816.data.err;
                    return 0;
                } else if (_mv_816.is_ok) {
                    __auto_type o = _mv_816.data.ok;
                    {
                        __auto_type ok = 1;
                        __auto_type facts = 0;
                        {
                            slop_map* _coll = (slop_map*)o.saturation.contexts;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    types_Node n = *(types_Node*)slop_map_key_at(_coll, _i);
                                    types_Context ctx = *(types_Context*)slop_map_value_at(_coll, _i);
                                    {
                                        slop_map* _coll = (slop_map*)ctx.subsumers;
                                        for (size_t _i = 0; _i < _coll->len; _i++) {
                                            {
                                                types_Node b = *(types_Node*)slop_map_key_at(_coll, _i);
                                                facts = (facts + 1);
                                                if (!(test_same_conclusions(arena, ctx, ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = b }), idx, axioms))) {
                                                    ok = 0;
                                                }
                                            }
                                        }
                                    }
                                    {
                                        slop_map* _coll = (slop_map*)ctx.succs;
                                        for (size_t _i = 0; _i < _coll->len; _i++) {
                                            {
                                                types_RoleId r = *(types_RoleId*)slop_map_key_at(_coll, _i);
                                                slop_map* ys = *(slop_map**)slop_map_value_at(_coll, _i);
                                                {
                                                    slop_map* _coll = (slop_map*)ys;
                                                    for (size_t _i = 0; _i < _coll->len; _i++) {
                                                        {
                                                            types_Node y = *(types_Node*)slop_map_key_at(_coll, _i);
                                                            if (!(test_same_conclusions(arena, ctx, ((types_Derived){ .tag = types_Derived_derived_succ, .data.derived_succ = { .f0 = r, .f1 = y } }), idx, axioms))) {
                                                                ok = 0;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    {
                                        slop_map* _coll = (slop_map*)ctx.preds;
                                        for (size_t _i = 0; _i < _coll->len; _i++) {
                                            {
                                                types_RoleId r = *(types_RoleId*)slop_map_key_at(_coll, _i);
                                                slop_map* xs = *(slop_map**)slop_map_value_at(_coll, _i);
                                                {
                                                    slop_map* _coll = (slop_map*)xs;
                                                    for (size_t _i = 0; _i < _coll->len; _i++) {
                                                        {
                                                            types_Node x = *(types_Node*)slop_map_key_at(_coll, _i);
                                                            if (!(test_same_conclusions(arena, ctx, ((types_Derived){ .tag = types_Derived_derived_pred, .data.derived_pred = { .f0 = r, .f1 = x } }), idx, axioms))) {
                                                                ok = 0;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (!(ok)) {
                            printf("%s", "  [dispatch] indexed != reference: ");
                            printf("%.*s\n", (int)(path).len, (path).data);
                        }
                        if (facts > 0) {
                            return ok;
                        } else {
                            return 0;
                        }
                    }
                }
                SLOP_UNREACHABLE();
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_indexed_dispatch_matches_reference(slop_arena* arena) {
    {
        uint8_t ok = 1;
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/litmus.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/intersection.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-lhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-rhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/domain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subproperty.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-properties.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/abox-assertions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/top-bottom.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/abox-disjoint-range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/range-complex-fillers.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/rbox-regularity-accept.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/unsatisfiable-consistent.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/cyclic-hierarchy.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/smaller-side-join.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/probes/subproperty-existential.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/role-hierarchy-deep.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (!(test_dispatch_agrees(arena, p))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t test_test_quoted_triple_header_subjects(slop_arena* arena) {
    {
        __auto_type s = rdf_make_iri(arena, SLOP_STR("http://example.org/t#s"));
        __auto_type p = rdf_make_iri(arena, SLOP_STR("http://example.org/t#p"));
        __auto_type o = rdf_make_iri(arena, SLOP_STR("http://example.org/t#o"));
        __auto_type q1 = rdf_make_triple_term(arena, rdf_make_triple(arena, s, p, o));
        __auto_type q2 = rdf_make_triple_term(arena, rdf_make_triple(arena, s, p, o));
        __auto_type tp = rdf_make_iri(arena, vocab_RDF_TYPE);
        __auto_type ont = rdf_make_iri(arena, vocab_OWL_ONTOLOGY);
        __auto_type prop = rdf_make_iri(arena, SLOP_STR("http://example.org/t#undeclared"));
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, q1, tp, ont)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, q2, prop, o)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_817 = decode_stage0_header(arena, ts, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }));
        if (!_mv_817.is_ok) {
            __auto_type _ = _mv_817.data.err;
            return 0;
        } else if (_mv_817.is_ok) {
            __auto_type s0 = _mv_817.data.ok;
            return (((int64_t)(((int64_t)((s0.triples).len)))) == 0);
        }
        SLOP_UNREACHABLE();
    }
}

int64_t test_strict_outcome(slop_arena* arena, slop_string path) {
    {
        __auto_type cfg = howl_default_config();
        cfg.strict_profile = 1;
        __auto_type _mv_818 = ttl_parse_ttl_file(arena, path);
        if (!_mv_818.is_ok) {
            __auto_type _ = _mv_818.data.err;
            return -1;
        } else if (_mv_818.is_ok) {
            __auto_type g = _mv_818.data.ok;
            __auto_type _mv_819 = howl_classify(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }), cfg);
            if (_mv_819.is_ok) {
                __auto_type _ = _mv_819.data.ok;
                return 0;
            } else if (!_mv_819.is_ok) {
                __auto_type f = _mv_819.data.err;
                __auto_type _mv_820 = f;
                switch (_mv_820.tag) {
                    case types_Fault_refused:
                    {
                        __auto_type os = _mv_820.data.refused;
                        if (((int64_t)(((int64_t)((os).len)))) > 0) {
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                    case types_Fault_cancelled:
                    {
                        return -1;
                    }
                    case types_Fault_input_error:
                    {
                        __auto_type _ = _mv_820.data.input_error;
                        return -1;
                    }
                    case types_Fault_unavailable:
                    {
                        __auto_type _ = _mv_820.data.unavailable;
                        return -1;
                    }
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

slop_result_types_Profile_types_Profile test_profile_run(slop_arena* arena, types_ProfileSelection selection) {
    {
        __auto_type cfg = howl_default_config();
        cfg.selection = selection;
        __auto_type _mv_821 = ttl_parse_ttl_file(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl"));
        if (!_mv_821.is_ok) {
            __auto_type _ = _mv_821.data.err;
            return ((slop_result_types_Profile_types_Profile){ .is_ok = false, .data.err = types_Profile_profile_el_plus_plus });
        } else if (_mv_821.is_ok) {
            __auto_type g = _mv_821.data.ok;
            __auto_type _mv_822 = howl_classify(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }), cfg);
            if (_mv_822.is_ok) {
                __auto_type o = _mv_822.data.ok;
                return ((slop_result_types_Profile_types_Profile){ .is_ok = true, .data.ok = o.profile });
            } else if (!_mv_822.is_ok) {
                __auto_type f = _mv_822.data.err;
                __auto_type _mv_823 = f;
                switch (_mv_823.tag) {
                    case types_Fault_unavailable:
                    {
                        __auto_type p = _mv_823.data.unavailable;
                        return ((slop_result_types_Profile_types_Profile){ .is_ok = false, .data.err = p });
                    }
                    case types_Fault_refused:
                    {
                        __auto_type _ = _mv_823.data.refused;
                        return ((slop_result_types_Profile_types_Profile){ .is_ok = false, .data.err = types_Profile_profile_el_plus_plus });
                    }
                    case types_Fault_cancelled:
                    {
                        return ((slop_result_types_Profile_types_Profile){ .is_ok = false, .data.err = types_Profile_profile_el_plus_plus });
                    }
                    case types_Fault_input_error:
                    {
                        __auto_type _ = _mv_823.data.input_error;
                        return ((slop_result_types_Profile_types_Profile){ .is_ok = false, .data.err = types_Profile_profile_el_plus_plus });
                    }
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_ran_as(slop_result_types_Profile_types_Profile r, types_Profile want) {
    __auto_type _mv_824 = r;
    if (_mv_824.is_ok) {
        __auto_type p = _mv_824.data.ok;
        return (p == want);
    } else if (!_mv_824.is_ok) {
        __auto_type _ = _mv_824.data.err;
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_refused_as(slop_result_types_Profile_types_Profile r, types_Profile want) {
    __auto_type _mv_825 = r;
    if (_mv_825.is_ok) {
        __auto_type _ = _mv_825.data.ok;
        return 0;
    } else if (!_mv_825.is_ok) {
        __auto_type p = _mv_825.data.err;
        return (p == want);
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_profile_selection(slop_arena* arena) {
    return ((test_ran_as(test_profile_run(arena, howl_default_config().selection), types_Profile_profile_el)) && (test_ran_as(test_profile_run(arena, ((types_ProfileSelection){ .tag = types_ProfileSelection_slop_auto })), types_Profile_profile_el)) && (test_ran_as(test_profile_run(arena, ((types_ProfileSelection){ .tag = types_ProfileSelection_explicit, .data.explicit = types_Profile_profile_el })), types_Profile_profile_el)) && (test_refused_as(test_profile_run(arena, ((types_ProfileSelection){ .tag = types_ProfileSelection_explicit, .data.explicit = types_Profile_profile_el_plus_plus })), types_Profile_profile_el_plus_plus)) && (test_refused_as(test_profile_run(arena, ((types_ProfileSelection){ .tag = types_ProfileSelection_explicit, .data.explicit = types_Profile_profile_horn_sriq })), types_Profile_profile_horn_sriq)) && (test_refused_as(test_profile_run(arena, ((types_ProfileSelection){ .tag = types_ProfileSelection_explicit, .data.explicit = types_Profile_profile_sriq })), types_Profile_profile_sriq)));
}

uint8_t test_test_profile_names_round_trip(slop_arena* arena) {
    return ((test_name_round_trips(types_Profile_profile_el)) && (test_name_round_trips(types_Profile_profile_el_plus_plus)) && (test_name_round_trips(types_Profile_profile_horn_sriq)) && (test_name_round_trips(types_Profile_profile_sriq)) && (({ __auto_type _mv = select_parse_profile(SLOP_STR("auto")); _mv.has_value ? ({ __auto_type _ = _mv.value; 0; }) : (1); })) && (({ __auto_type _mv = select_parse_profile(SLOP_STR("EL")); _mv.has_value ? ({ __auto_type _ = _mv.value; 0; }) : (1); })) && (({ __auto_type _mv = select_parse_profile(SLOP_STR("sroiq")); _mv.has_value ? ({ __auto_type _ = _mv.value; 0; }) : (1); })));
}

uint8_t test_name_round_trips(types_Profile p) {
    __auto_type _mv_826 = select_parse_profile(select_profile_name(p));
    if (_mv_826.has_value) {
        __auto_type q = _mv_826.value;
        return (q == p);
    } else if (!_mv_826.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_strict_refuses_past_omissions(slop_arena* arena) {
    return ((test_strict_outcome(arena, SLOP_STR("corpus/fixtures/out-of-profile/union.ttl")) == 1) && (test_strict_outcome(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl")) == 0));
}

uint8_t test_test_nary_chain_decomposes_left_associated(slop_arena* arena) {
    __auto_type _mv_827 = test_normalize_fixture(arena, SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl"));
    if (!_mv_827.has_value) {
        return 0;
    } else if (_mv_827.has_value) {
        __auto_type no = _mv_827.value;
        {
            __auto_type chains = 0;
            {
                __auto_type _coll = no.axioms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    __auto_type _mv_828 = a;
                    switch (_mv_828.tag) {
                        case types_NormAxiom_role_chain:
                        {
                            chains = (chains + 1);
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                }
            }
            return (chains == 2);
        }
    }
    SLOP_UNREACHABLE();
}

slop_option_u8 test_regularity_of(slop_arena* arena, slop_string path) {
    __auto_type _mv_829 = ttl_parse_ttl_file(arena, path);
    if (!_mv_829.is_ok) {
        __auto_type _ = _mv_829.data.err;
        return (slop_option_u8){.has_value = false};
    } else if (_mv_829.is_ok) {
        __auto_type g = _mv_829.data.ok;
        __auto_type _mv_830 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }));
        if (!_mv_830.is_ok) {
            __auto_type _ = _mv_830.data.err;
            return (slop_option_u8){.has_value = false};
        } else if (_mv_830.is_ok) {
            __auto_type s0 = _mv_830.data.ok;
            __auto_type _mv_831 = decode_decode_axioms(arena, s0.dict, s0.triples);
            if (!_mv_831.is_ok) {
                __auto_type _ = _mv_831.data.err;
                return (slop_option_u8){.has_value = false};
            } else if (_mv_831.is_ok) {
                __auto_type s1 = _mv_831.data.ok;
                __auto_type _mv_832 = gate_check_regularity(arena, gate_expand_sugar(arena, s1.axioms));
                switch (_mv_832.tag) {
                    case gate_RboxVerdict_rbox_regular:
                    {
                        return (slop_option_u8){.has_value = 1, .value = 1};
                    }
                    case gate_RboxVerdict_rbox_irregular:
                    {
                        __auto_type _ = _mv_832.data.rbox_irregular;
                        return (slop_option_u8){.has_value = 1, .value = 0};
                    }
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_regularity_rejects_mutual_recursion(slop_arena* arena) {
    __auto_type _mv_833 = test_regularity_of(arena, SLOP_STR("corpus/fixtures/hazards/rbox-regularity-reject.ttl"));
    if (!_mv_833.has_value) {
        return 0;
    } else if (_mv_833.has_value) {
        __auto_type regular = _mv_833.value;
        return !(regular);
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_regularity_accepts_equivalence_and_transitivity(slop_arena* arena) {
    __auto_type _mv_834 = test_regularity_of(arena, SLOP_STR("corpus/fixtures/hazards/rbox-regularity-accept.ttl"));
    if (!_mv_834.has_value) {
        return 0;
    } else if (_mv_834.has_value) {
        __auto_type regular = _mv_834.value;
        return regular;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_regularity_accepts_plain_subproperty(slop_arena* arena) {
    __auto_type _mv_835 = test_regularity_of(arena, SLOP_STR("corpus/fixtures/v0/subproperty.ttl"));
    if (!_mv_835.has_value) {
        return 0;
    } else if (_mv_835.has_value) {
        __auto_type regular = _mv_835.value;
        return regular;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_regularity_accepts_nary_chain(slop_arena* arena) {
    __auto_type _mv_836 = test_regularity_of(arena, SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl"));
    if (!_mv_836.has_value) {
        return 0;
    } else if (_mv_836.has_value) {
        __auto_type regular = _mv_836.value;
        return regular;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_irregular_rbox_is_omitted_whole(slop_arena* arena) {
    __auto_type _mv_837 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/hazards/rbox-regularity-reject.ttl"));
    if (!_mv_837.has_value) {
        return 0;
    } else if (_mv_837.has_value) {
        __auto_type gr = _mv_837.value;
        return ((((int64_t)(((int64_t)((gr.omissions).len)))) > 0) && (test_count_variant_chain(gr.accepted) == 0));
    }
    SLOP_UNREACHABLE();
}

slop_option_gate_GateResult test_gate_fixture(slop_arena* arena, slop_string path) {
    return test_gate_fixture_in(arena, path, types_Profile_profile_el);
}

slop_option_gate_GateResult test_gate_fixture_in(slop_arena* arena, slop_string path, types_Profile p) {
    __auto_type _mv_838 = ttl_parse_ttl_file(arena, path);
    if (!_mv_838.is_ok) {
        __auto_type _ = _mv_838.data.err;
        return (slop_option_gate_GateResult){.has_value = false};
    } else if (_mv_838.is_ok) {
        __auto_type g = _mv_838.data.ok;
        __auto_type _mv_839 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }));
        if (!_mv_839.is_ok) {
            __auto_type _ = _mv_839.data.err;
            return (slop_option_gate_GateResult){.has_value = false};
        } else if (_mv_839.is_ok) {
            __auto_type s0 = _mv_839.data.ok;
            __auto_type _mv_840 = decode_decode_axioms(arena, s0.dict, s0.triples);
            if (!_mv_840.is_ok) {
                __auto_type _ = _mv_840.data.err;
                return (slop_option_gate_GateResult){.has_value = false};
            } else if (_mv_840.is_ok) {
                __auto_type s1 = _mv_840.data.ok;
                return (slop_option_gate_GateResult){.has_value = 1, .value = gate_gate_axioms(arena, s1.axioms, s1.signature, s0.omissions, p)};
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

int64_t test_count_variant_chain(slop_list_owl2_RawAxiom axs) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_841 = a;
                switch (_mv_841.tag) {
                    case owl2_RawAxiom_ra_property_chain:
                    {
                        __auto_type _ = _mv_841.data.ra_property_chain;
                        n = (n + 1);
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        return n;
    }
}

int64_t test_count_variant_disjoint(slop_list_owl2_RawAxiom axs) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_842 = a;
                switch (_mv_842.tag) {
                    case owl2_RawAxiom_ra_disjoint_classes:
                    {
                        __auto_type _ = _mv_842.data.ra_disjoint_classes;
                        n = (n + 1);
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        return n;
    }
}

int64_t test_count_variant_subclass(slop_list_owl2_RawAxiom axs) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_843 = a;
                switch (_mv_843.tag) {
                    case owl2_RawAxiom_ra_sub_class_of:
                    {
                        n = (n + 1);
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        return n;
    }
}

uint8_t test_test_gate_annotation_heavy_is_clean(slop_arena* arena) {
    __auto_type _mv_844 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/hazards/annotation-heavy.ttl"));
    if (!_mv_844.has_value) {
        return 0;
    } else if (_mv_844.has_value) {
        __auto_type gr = _mv_844.value;
        return ((((int64_t)(((int64_t)((gr.omissions).len)))) == 0) && (test_count_variant_subclass(gr.accepted) > 0));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_gate_carries_import_omissions(slop_arena* arena) {
    __auto_type _mv_845 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/hazards/unattested-import.ttl"));
    if (!_mv_845.has_value) {
        return 0;
    } else if (_mv_845.has_value) {
        __auto_type gr = _mv_845.value;
        return (((int64_t)(((int64_t)((gr.omissions).len)))) == 1);
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sugar_transitivity_becomes_a_chain(slop_arena* arena) {
    __auto_type _mv_846 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/v0/transitive.ttl"));
    if (!_mv_846.has_value) {
        return 0;
    } else if (_mv_846.has_value) {
        __auto_type gr = _mv_846.value;
        return ((test_count_variant_chain(gr.accepted) > 0) && (((int64_t)(((int64_t)((gr.omissions).len)))) == 0));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sugar_nary_disjointness_becomes_pairs(slop_arena* arena) {
    __auto_type _mv_847 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl"));
    if (!_mv_847.has_value) {
        return 0;
    } else if (_mv_847.has_value) {
        __auto_type gr = _mv_847.value;
        return (test_count_variant_disjoint(gr.accepted) == 3);
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sugar_equivalence_is_a_star_not_all_pairs(slop_arena* arena) {
    __auto_type _mv_848 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/v0/equivalent-classes.ttl"));
    if (!_mv_848.has_value) {
        return 0;
    } else if (_mv_848.has_value) {
        __auto_type gr = _mv_848.value;
        return ((test_count_variant_subclass(gr.accepted) > 0) && (((int64_t)(((int64_t)((gr.omissions).len)))) == 0));
    }
    SLOP_UNREACHABLE();
}

int64_t test_gate_omission_count(slop_arena* arena, slop_string path) {
    __auto_type _mv_849 = test_gate_fixture(arena, path);
    if (!_mv_849.has_value) {
        return -1;
    } else if (_mv_849.has_value) {
        __auto_type gr = _mv_849.value;
        return ((int64_t)(((int64_t)((gr.omissions).len))));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_gate_accepts_every_v0_fixture(slop_arena* arena) {
    {
        __auto_type paths = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0 });
        uint8_t ok = 1;
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subclass-atomic.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/intersection.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-lhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-rhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-classes.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-properties.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-binary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subproperty.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/transitive.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/domain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/abox-assertions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/top-bottom.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/litmus.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-superclass.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-domain-range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = paths;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (test_gate_omission_count(arena, p) != 0) {
                    printf("%s", "  [gate] expected 0 omissions, got ");
                    printf("%.*s", (int)(int_to_string(arena, test_gate_omission_count(arena, p))).len, (int_to_string(arena, test_gate_omission_count(arena, p))).data);
                    printf("%s", " in ");
                    printf("%.*s\n", (int)(p).len, (p).data);
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t test_test_gate_rejects_every_out_of_profile_fixture(slop_arena* arena) {
    {
        __auto_type paths = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0 });
        uint8_t ok = 1;
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/union.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/complement.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/allvalues.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/nominals.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/cardinality.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/has-self.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/inverse.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/equality.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/property-characteristics.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/haskey-disjointunion.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/swrl-rule.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/builtin-roles.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/anonymous-individual.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/datatypes.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = paths;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (test_gate_omission_count(arena, p) < 1) {
                    printf("%s", "  [gate] expected >=1 omission, got ");
                    printf("%.*s", (int)(int_to_string(arena, test_gate_omission_count(arena, p))).len, (int_to_string(arena, test_gate_omission_count(arena, p))).data);
                    printf("%s", " in ");
                    printf("%.*s\n", (int)(p).len, (p).data);
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

slop_option_owl2_Signature test_signature_of_fixture(slop_arena* arena, slop_string path) {
    __auto_type _mv_850 = ttl_parse_ttl_file(arena, path);
    if (!_mv_850.is_ok) {
        __auto_type _ = _mv_850.data.err;
        return (slop_option_owl2_Signature){.has_value = false};
    } else if (_mv_850.is_ok) {
        __auto_type g = _mv_850.data.ok;
        __auto_type _mv_851 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }));
        if (!_mv_851.is_ok) {
            __auto_type _ = _mv_851.data.err;
            return (slop_option_owl2_Signature){.has_value = false};
        } else if (_mv_851.is_ok) {
            __auto_type s0 = _mv_851.data.ok;
            return (slop_option_owl2_Signature){.has_value = 1, .value = decode_build_signature(arena, s0.dict, s0.triples)};
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_declared_unused_class_reaches_the_signature(slop_arena* arena) {
    __auto_type _mv_852 = test_signature_of_fixture(arena, SLOP_STR("corpus/fixtures/hazards/declared-unused-class.ttl"));
    if (!_mv_852.has_value) {
        return 0;
    } else if (_mv_852.has_value) {
        __auto_type sig = _mv_852.value;
        return (owl2_signature_has_class(sig, ((rdf_IRI){.value = SLOP_STR("http://example.org/t#Unused")})) && owl2_signature_has_class(sig, ((rdf_IRI){.value = SLOP_STR("http://example.org/t#A")})));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_builtins_are_declared(slop_arena* arena) {
    __auto_type _mv_853 = test_signature_of_fixture(arena, SLOP_STR("corpus/fixtures/hazards/declared-unused-class.ttl"));
    if (!_mv_853.has_value) {
        return 0;
    } else if (_mv_853.has_value) {
        __auto_type sig = _mv_853.value;
        return (owl2_signature_has_class(sig, ((rdf_IRI){.value = vocab_OWL_THING})) && owl2_signature_has_annotation_property(sig, ((rdf_IRI){.value = vocab_RDFS_LABEL})));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_custom_annotation_property_is_recognized(slop_arena* arena) {
    __auto_type _mv_854 = test_signature_of_fixture(arena, SLOP_STR("corpus/fixtures/hazards/annotation-heavy.ttl"));
    if (!_mv_854.has_value) {
        return 0;
    } else if (_mv_854.has_value) {
        __auto_type sig = _mv_854.value;
        return ((owl2_signature_has_annotation_property(sig, ((rdf_IRI){.value = SLOP_STR("http://example.org/t#curatorNote")}))) && (owl2_signature_has_class(sig, ((rdf_IRI){.value = SLOP_STR("http://example.org/t#A")}))) && (!(owl2_signature_has_class(sig, ((rdf_IRI){.value = SLOP_STR("http://example.org/t#curatorNote")})))));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_is_named_class(owl2_RawConcept c, slop_string iri) {
    __auto_type _mv_855 = c;
    switch (_mv_855.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type nd = _mv_855.data.rc_name;
            __auto_type _mv_856 = nd;
            switch (_mv_856.tag) {
                case types_Node_class_node:
                {
                    __auto_type i = _mv_856.data.class_node;
                    return (canon_string_cmp(i.value, iri) == 0);
                }
                case types_Node_individual_node:
                {
                    __auto_type _ = _mv_856.data.individual_node;
                    return 0;
                }
                case types_Node_fresh_node:
                {
                    __auto_type _ = _mv_856.data.fresh_node;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        default: {
            return 0;
        }
    }
}

uint8_t test_is_some_person(owl2_RawConcept c, slop_string role_iri, slop_string filler_iri) {
    __auto_type _mv_857 = c;
    switch (_mv_857.tag) {
        case owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_857.data.rc_some.f0;
            __auto_type f = _mv_857.data.rc_some.f1;
            return (({ __auto_type _mv = r; uint8_t _mr = {0}; switch (_mv.tag) { case types_RoleId_named_role: { __auto_type i = _mv.data.named_role; _mr = (canon_string_cmp(i.value, role_iri) == 0); break; } case types_RoleId_fresh_role: { __auto_type _ = _mv.data.fresh_role; _mr = 0; break; }  } _mr; }) && test_is_named_class((*f), filler_iri));
        }
        default: {
            return 0;
        }
    }
}

uint8_t test_test_decode_litmus_class_expression(slop_arena* arena) {
    {
        __auto_type person = SLOP_STR("http://example.org/t#Person");
        __auto_type has_child = SLOP_STR("http://example.org/t#hasChild");
        __auto_type _mv_858 = ttl_parse_ttl_file(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl"));
        if (!_mv_858.is_ok) {
            __auto_type _ = _mv_858.data.err;
            return 0;
        } else if (_mv_858.is_ok) {
            __auto_type g = _mv_858.data.ok;
            __auto_type _mv_859 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }));
            if (!_mv_859.is_ok) {
                __auto_type _ = _mv_859.data.err;
                return 0;
            } else if (_mv_859.is_ok) {
                __auto_type s0 = _mv_859.data.ok;
                {
                    __auto_type ig = decode_graph_to_indexed(arena, test_stage0_triples(arena, s0));
                    __auto_type parent = rdf_make_iri(arena, SLOP_STR("http://example.org/t#Parent"));
                    __auto_type eq_pred = rdf_make_iri(arena, vocab_OWL_EQUIVALENT_CLASS);
                    __auto_type _mv_860 = decode_one_object(arena, ig, parent, eq_pred);
                    if (!_mv_860.is_ok) {
                        __auto_type _ = _mv_860.data.err;
                        return 0;
                    } else if (_mv_860.is_ok) {
                        __auto_type defn = _mv_860.data.ok;
                        __auto_type _mv_861 = decode_decode_concept(arena, ig, defn, decode_CONCEPT_FUEL);
                        if (!_mv_861.is_ok) {
                            __auto_type _ = _mv_861.data.err;
                            return 0;
                        } else if (_mv_861.is_ok) {
                            __auto_type c = _mv_861.data.ok;
                            __auto_type _mv_862 = c;
                            switch (_mv_862.tag) {
                                case owl2_RawConcept_rc_and:
                                {
                                    __auto_type cs = _mv_862.data.rc_and;
                                    {
                                        __auto_type n = 0;
                                        __auto_type saw_person = 0;
                                        __auto_type saw_some = 0;
                                        {
                                            __auto_type _coll = cs;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type x = _coll.data[_i];
                                                n = (n + 1);
                                                if (test_is_named_class(x, person)) {
                                                    saw_person = 1;
                                                }
                                                if (test_is_some_person(x, has_child, person)) {
                                                    saw_some = 1;
                                                }
                                            }
                                        }
                                        return (((n == 2)) && (saw_person) && (saw_some));
                                    }
                                }
                                default: {
                                    return 0;
                                }
                            }
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

uint8_t test_test_decode_represents_out_of_profile_rather_than_failing(slop_arena* arena) {
    {
        __auto_type b1 = rdf_make_blank(arena, 1);
        __auto_type c1 = rdf_make_blank(arena, 2);
        __auto_type c2 = rdf_make_blank(arena, 3);
        __auto_type nil_t = rdf_make_iri(arena, vocab_RDF_NIL);
        __auto_type f = rdf_make_iri(arena, vocab_RDF_FIRST);
        __auto_type r = rdf_make_iri(arena, vocab_RDF_REST);
        __auto_type u = rdf_make_iri(arena, SLOP_STR("http://www.w3.org/2002/07/owl#unionOf"));
        __auto_type ea = test_ex_iri(arena, SLOP_STR("A"));
        __auto_type eb = test_ex_iri(arena, SLOP_STR("B"));
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, u, c1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, c1, f, ea)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, c1, r, c2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, c2, f, eb)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, c2, r, nil_t)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_863 = decode_decode_concept(arena, decode_graph_to_indexed(arena, ts), b1, decode_CONCEPT_FUEL);
        if (!_mv_863.is_ok) {
            __auto_type _ = _mv_863.data.err;
            return 0;
        } else if (_mv_863.is_ok) {
            __auto_type c = _mv_863.data.ok;
            __auto_type _mv_864 = c;
            switch (_mv_864.tag) {
                case owl2_RawConcept_rc_or:
                {
                    __auto_type cs = _mv_864.data.rc_or;
                    return (((int64_t)(((int64_t)((cs).len)))) == 2);
                }
                default: {
                    return 0;
                }
            }
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_decode_blank_node_cycle_is_bounded(slop_arena* arena) {
    {
        __auto_type b1 = rdf_make_blank(arena, 1);
        __auto_type comp = rdf_make_iri(arena, SLOP_STR("http://www.w3.org/2002/07/owl#complementOf"));
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, comp, b1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_865 = decode_decode_concept(arena, decode_graph_to_indexed(arena, ts), b1, decode_CONCEPT_FUEL);
        if (!_mv_865.is_ok) {
            __auto_type _ = _mv_865.data.err;
            return 1;
        } else if (_mv_865.is_ok) {
            __auto_type _ = _mv_865.data.ok;
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_rdf_list_well_formed(slop_arena* arena) {
    {
        __auto_type b1 = rdf_make_blank(arena, 1);
        __auto_type b2 = rdf_make_blank(arena, 2);
        __auto_type b3 = rdf_make_blank(arena, 3);
        __auto_type nil_t = rdf_make_iri(arena, vocab_RDF_NIL);
        __auto_type f = rdf_make_iri(arena, vocab_RDF_FIRST);
        __auto_type r = rdf_make_iri(arena, vocab_RDF_REST);
        __auto_type ea = test_ex_iri(arena, SLOP_STR("A"));
        __auto_type eb = test_ex_iri(arena, SLOP_STR("B"));
        __auto_type ec = test_ex_iri(arena, SLOP_STR("C"));
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, f, ea)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, r, b2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, f, eb)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, r, b3)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b3, f, ec)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b3, r, nil_t)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_866 = decode_rdf_list_checked(arena, decode_graph_to_indexed(arena, ts), b1);
        if (!_mv_866.is_ok) {
            __auto_type _ = _mv_866.data.err;
            return 0;
        } else if (_mv_866.is_ok) {
            __auto_type els = _mv_866.data.ok;
            return (((((int64_t)(((int64_t)((els).len)))) == 3)) && (rdf_term_eq(decode_term_at(els, 0), ea)) && (rdf_term_eq(decode_term_at(els, 1), eb)) && (rdf_term_eq(decode_term_at(els, 2), ec)));
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_rdf_list_truncation_is_a_fault(slop_arena* arena) {
    {
        __auto_type b1 = rdf_make_blank(arena, 1);
        __auto_type b2 = rdf_make_blank(arena, 2);
        __auto_type b3 = rdf_make_blank(arena, 3);
        __auto_type nil_t = rdf_make_iri(arena, vocab_RDF_NIL);
        __auto_type f = rdf_make_iri(arena, vocab_RDF_FIRST);
        __auto_type r = rdf_make_iri(arena, vocab_RDF_REST);
        __auto_type ea = test_ex_iri(arena, SLOP_STR("A"));
        __auto_type ec = test_ex_iri(arena, SLOP_STR("C"));
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, f, ea)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, r, b2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, r, b3)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b3, f, ec)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b3, r, nil_t)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_867 = decode_rdf_list_checked(arena, decode_graph_to_indexed(arena, ts), b1);
        if (_mv_867.is_ok) {
            __auto_type _ = _mv_867.data.ok;
            return 0;
        } else if (!_mv_867.is_ok) {
            __auto_type e = _mv_867.data.err;
            __auto_type _mv_868 = e;
            switch (_mv_868.tag) {
                case decode_ListFault_list_truncated:
                {
                    __auto_type _ = _mv_868.data.list_truncated;
                    return 1;
                }
                case decode_ListFault_list_branching:
                {
                    __auto_type _ = _mv_868.data.list_branching;
                    return 0;
                }
                case decode_ListFault_list_cyclic:
                {
                    __auto_type _ = _mv_868.data.list_cyclic;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_rdf_list_cycle_terminates(slop_arena* arena) {
    {
        __auto_type b1 = rdf_make_blank(arena, 1);
        __auto_type b2 = rdf_make_blank(arena, 2);
        __auto_type f = rdf_make_iri(arena, vocab_RDF_FIRST);
        __auto_type r = rdf_make_iri(arena, vocab_RDF_REST);
        __auto_type ea = test_ex_iri(arena, SLOP_STR("A"));
        __auto_type eb = test_ex_iri(arena, SLOP_STR("B"));
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, f, ea)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, r, b2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, f, eb)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, r, b1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_869 = decode_rdf_list_checked(arena, decode_graph_to_indexed(arena, ts), b1);
        if (_mv_869.is_ok) {
            __auto_type _ = _mv_869.data.ok;
            return 0;
        } else if (!_mv_869.is_ok) {
            __auto_type e = _mv_869.data.err;
            __auto_type _mv_870 = e;
            switch (_mv_870.tag) {
                case decode_ListFault_list_cyclic:
                {
                    __auto_type _ = _mv_870.data.list_cyclic;
                    return 1;
                }
                case decode_ListFault_list_truncated:
                {
                    __auto_type _ = _mv_870.data.list_truncated;
                    return 0;
                }
                case decode_ListFault_list_branching:
                {
                    __auto_type _ = _mv_870.data.list_branching;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_rdf_list_branching_is_a_fault(slop_arena* arena) {
    {
        __auto_type b1 = rdf_make_blank(arena, 1);
        __auto_type nil_t = rdf_make_iri(arena, vocab_RDF_NIL);
        __auto_type f = rdf_make_iri(arena, vocab_RDF_FIRST);
        __auto_type r = rdf_make_iri(arena, vocab_RDF_REST);
        __auto_type ea = test_ex_iri(arena, SLOP_STR("A"));
        __auto_type eb = test_ex_iri(arena, SLOP_STR("B"));
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, f, ea)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, f, eb)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, r, nil_t)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_871 = decode_rdf_list_checked(arena, decode_graph_to_indexed(arena, ts), b1);
        if (_mv_871.is_ok) {
            __auto_type _ = _mv_871.data.ok;
            return 0;
        } else if (!_mv_871.is_ok) {
            __auto_type e = _mv_871.data.err;
            __auto_type _mv_872 = e;
            switch (_mv_872.tag) {
                case decode_ListFault_list_branching:
                {
                    __auto_type _ = _mv_872.data.list_branching;
                    return 1;
                }
                case decode_ListFault_list_truncated:
                {
                    __auto_type _ = _mv_872.data.list_truncated;
                    return 0;
                }
                case decode_ListFault_list_cyclic:
                {
                    __auto_type _ = _mv_872.data.list_cyclic;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_sort_is_stable(slop_arena* arena) {
    {
        __auto_type idx = canon_sort_range(arena, 9, (slop_closure_t){(void*)test__lambda_873, NULL});
        __auto_type expect = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0 });
        uint8_t ok = 1;
        int64_t i = 0;
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (6); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (7); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (8); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (3); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (4); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (5); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (1); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (2); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        if (((int64_t)(((int64_t)((idx).len)))) != 9) {
            ok = 0;
        } else {
        }
        while (i < 9) {
            if (canon_int_at(idx, i) != canon_int_at(expect, i)) {
                ok = 0;
            } else {
            }
            i = (i + 1);
        }
        return ok;
    }
}

uint8_t test_test_sort_is_a_permutation(slop_arena* arena) {
    {
        __auto_type xs = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (test_mk_iri(SLOP_STR("b"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (test_mk_iri(SLOP_STR("a"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (test_mk_iri(SLOP_STR("b"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (test_mk_iri(SLOP_STR("c"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (test_mk_iri(SLOP_STR("a"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type s = canon_sort_iris(arena, xs);
            uint8_t ok = 1;
            int64_t i = 0;
            __auto_type n = ((int64_t)(((int64_t)((xs).len))));
            if (((int64_t)(((int64_t)((s).len)))) != 5) {
                ok = 0;
            } else {
            }
            while (i < n) {
                {
                    uint8_t found = 0;
                    int64_t j = 0;
                    while (j < 5) {
                        if (canon_iri_cmp(canon_iri_at(xs, i), canon_iri_at(s, j)) == 0) {
                            found = 1;
                        } else {
                        }
                        j = (j + 1);
                    }
                    if (found) {
                    } else {
                        ok = 0;
                    }
                    i = (i + 1);
                }
            }
            if (canon_iri_cmp(canon_iri_at(s, 0), test_mk_iri(SLOP_STR("a"))) != 0) {
                ok = 0;
            } else {
            }
            if (canon_iri_cmp(canon_iri_at(s, 1), test_mk_iri(SLOP_STR("a"))) != 0) {
                ok = 0;
            } else {
            }
            if (canon_iri_cmp(canon_iri_at(s, 4), test_mk_iri(SLOP_STR("c"))) != 0) {
                ok = 0;
            } else {
            }
            return ok;
        }
    }
}

void test_print_test_result(slop_string name, uint8_t passed) {
    if (passed) {
        printf("%s", "[PASS] ");
        printf("%.*s\n", (int)(name).len, (name).data);
    } else {
        printf("%s", "[FAIL] ");
        printf("%.*s\n", (int)(name).len, (name).data);
    }
}

int main(int argc, char** _c_argv) {
    uint8_t** argv = (uint8_t**)_c_argv;
    {
        #ifdef SLOP_DEBUG
        SLOP_PRE((4194304) > 0, "with-arena size must be positive");
        #endif
        slop_arena _arena = slop_arena_new(4194304);
        #ifdef SLOP_DEBUG
        SLOP_PRE(_arena.base != NULL, "arena allocation failed");
        #endif
        slop_arena* arena = &_arena;
        {
            int64_t passed = 0;
            int64_t failed = 0;
            printf("%s\n", "HOWL — verdict discipline & structural invariants");
            printf("%s\n", "========================================");
            {
                __auto_type r = test_test_coherent_requires_complete(arena);
                test_print_test_result(SLOP_STR("verdict: complete + clean => coherent"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_omission_blocks_coherent(arena);
                test_print_test_result(SLOP_STR("verdict: omission blocks coherent"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_cap_blocks_coherent(arena);
                test_print_test_result(SLOP_STR("verdict: round cap blocks coherent"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_finding_beats_partial_coverage(arena);
                test_print_test_result(SLOP_STR("verdict: finding beats partial coverage"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_consistent_but_incoherent(arena);
                test_print_test_result(SLOP_STR("verdict: consistent-but-incoherent => incoherent"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_context_starts_with_empty_store(arena);
                test_print_test_result(SLOP_STR("init: context store starts empty"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_emit_edge_addresses_both_halves(arena);
                test_print_test_result(SLOP_STR("edges: emit-edge addresses both halves"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_litmus_end_to_end(arena);
                test_print_test_result(SLOP_STR("§12 LITMUS: Turtle in, Mother subseteq Parent out, COHERENT"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_unattested_import_is_inconclusive(arena);
                test_print_test_result(SLOP_STR("§12(b) e2e: a dangling import is INCONCLUSIVE, never coherent"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_declared_unused_class_gets_a_context(arena);
                test_print_test_result(SLOP_STR("§12(c) e2e: a declared, unused class has a context"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_abox_disjoint_range_is_incoherent(arena);
                test_print_test_result(SLOP_STR("identity fixture: disjoint ranges on one target => INCOHERENT"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_worker_count_does_not_change_the_report(arena);
                test_print_test_result(SLOP_STR("M1 (e): the same report at W = 1 and W = 4, complete and capped"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_names_round_trip(arena);
                test_print_test_result(SLOP_STR("saturation names: renaming inverts, keeps ⊤ and ⊥, keeps punning apart"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_commit_dedups_across_deltas(arena);
                test_print_test_result(SLOP_STR("barrier: facts two workers share are committed once and queued once"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_entails_sub_agrees_with_report(arena);
                test_print_test_result(SLOP_STR("differential: entails-sub answers every pair as the report does"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_undeclared_individual_is_reasoned_over(arena);
                test_print_test_result(SLOP_STR("W3C DisjointClasses-002: undeclared individual is reasoned over"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_anonymous_class_assertion_is_read(arena);
                test_print_test_result(SLOP_STR("W3C WebOnt-Restriction-001: anonymous class assertion is read"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_annotation_on_annotation_is_consumed(arena);
                test_print_test_result(SLOP_STR("W3C AnnotationAnnotations-001: owl:Annotation is header"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_repeated_disjoint_member_is_positional(arena);
                test_print_test_result(SLOP_STR("ELK DisjointSelf: repeated disjoint member is positional"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_logical_triple_on_header_node_is_not_swallowed(arena);
                test_print_test_result(SLOP_STR("stage 0: a logical triple on a header node is not swallowed"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_litmus(arena);
                test_print_test_result(SLOP_STR("§3.1 LITMUS: derives Mother ⊑ Parent"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_polarity_guard(arena);
                test_print_test_result(SLOP_STR("polarity: wrong-direction fresh definition loses the litmus"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_cyclic_hierarchy_terminates(arena);
                test_print_test_result(SLOP_STR("termination: A ⊑ B, B ⊑ A reaches fixpoint"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_same_round_co_arrival(arena);
                test_print_test_result(SLOP_STR("CR4: same-round co-arrival still concludes"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_late_subsumer_still_concludes(arena);
                test_print_test_result(SLOP_STR("CR4: subsumer arriving after its edge still concludes"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_unsatisfiable_class_detected(arena);
                test_print_test_result(SLOP_STR("unsat: ⊥ ∈ S(A) found, owl:Nothing excluded"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_bottom_compression(arena);
                test_print_test_result(SLOP_STR("output: probe entails all, taxonomy holds only (A,⊥)"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_inconsistency_suppresses_both_lists(arena);
                test_print_test_result(SLOP_STR("findings: inconsistency empties both lists (undefined, not empty)"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_derived_eq_compares_both_payloads(arena);
                test_print_test_result(SLOP_STR("equality: derived-eq compares BOTH payloads (slop#66)"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_order_independence(arena);
                test_print_test_result(SLOP_STR("determinism: signature order changes nothing"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_string_cmp_is_length_safe(arena);
                test_print_test_result(SLOP_STR("order: string-cmp is length-safe (no NUL assumption)"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_node_cmp_separates_punned_iris(arena);
                test_print_test_result(SLOP_STR("order: punned IRIs stay distinct under node-cmp"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sort_orders_and_is_input_determined(arena);
                test_print_test_result(SLOP_STR("order: sort is input-determined, not insertion-ordered"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sort_is_a_permutation(arena);
                test_print_test_result(SLOP_STR("order: sort preserves length and multiset"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sort_is_stable(arena);
                test_print_test_result(SLOP_STR("order: sort is stable, so ties are content-determined"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_rdf_list_well_formed(arena);
                test_print_test_result(SLOP_STR("rdf-list: a well-formed collection reads back in order"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_rdf_list_truncation_is_a_fault(arena);
                test_print_test_result(SLOP_STR("rdf-list: truncation FAULTS, never a shorter conjunction"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_rdf_list_cycle_terminates(arena);
                test_print_test_result(SLOP_STR("rdf-list: an rdf:rest cycle terminates with a fault"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_rdf_list_branching_is_a_fault(arena);
                test_print_test_result(SLOP_STR("rdf-list: a branching cell has no determinate reading"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_unattested_import_yields_an_omission(arena);
                test_print_test_result(SLOP_STR("§12(b): an unattested owl:imports becomes an omission"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_attested_import_yields_none(arena);
                test_print_test_result(SLOP_STR("§12(b): the same import, attested, gates clean"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_header_and_reification_are_consumed(arena);
                test_print_test_result(SLOP_STR("stage 0: header and owl:Axiom scaffolding consumed"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_stage0_rebuild_checks_the_whole_input(arena);
                test_print_test_result(SLOP_STR("stage 0: a reified triple asserted anywhere in the input is not rebuilt"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_decode_store_answers_as_the_full_store(arena);
                test_print_test_result(SLOP_STR("decode: the store of queried predicates decodes as a full store"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_role_hierarchy_carries_edges(arena);
                test_print_test_result(SLOP_STR("Role hierarchy: an r-edge is an s-edge when r ⊑ s, not the converse"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_role_closure_deep(arena);
                test_print_test_result(SLOP_STR("CR4 and CR7 match through the role closure: depth, cycles, chains, transitivity"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_smaller_side_joins(arena);
                test_print_test_result(SLOP_STR("CR2 and CR4 walk the smaller side, context side included"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_term_store_by_content(arena);
                test_print_test_result(SLOP_STR("term store: terms by content, duplicates collapse, unseen terms match nothing"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_term_store_quoted_and_tagged(arena);
                test_print_test_result(SLOP_STR("term store: equal quoted triples are one term, nested too; tags distinguish literals"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_stage0_fault_follows_the_document(arena);
                test_print_test_result(SLOP_STR("stage 0: the reported fault follows the document, not hash order"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_decode_litmus_class_expression(arena);
                test_print_test_result(SLOP_STR("stage 1: §3.1's defining expression decodes intact"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_decode_represents_out_of_profile_rather_than_failing(arena);
                test_print_test_result(SLOP_STR("stage 1: owl:unionOf is REPRESENTED, not a parse error"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_decode_blank_node_cycle_is_bounded(arena);
                test_print_test_result(SLOP_STR("stage 1: a cyclic class expression terminates"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_declared_unused_class_reaches_the_signature(arena);
                test_print_test_result(SLOP_STR("§12(c): a declared, unused class reaches the signature"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_builtins_are_declared(arena);
                test_print_test_result(SLOP_STR("signature: OWL built-ins are never missing declarations"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_custom_annotation_property_is_recognized(arena);
                test_print_test_result(SLOP_STR("signature: a custom annotation property is structural"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_annotation_heavy_decodes_clean(arena);
                test_print_test_result(SLOP_STR("§12(a): an annotated ontology decodes with 0 out-of-profile"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_litmus_decodes_clean(arena);
                test_print_test_result(SLOP_STR("stage 1: the litmus ontology decodes clean"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_nary_disjointness_keeps_its_members(arena);
                test_print_test_result(SLOP_STR("stage 1: n-ary disjointness keeps all its members"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_v0_corpus_decodes_clean(arena);
                test_print_test_result(SLOP_STR("corpus: all 17 v0 fixtures decode with 0 out-of-profile"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_out_of_profile_corpus_is_caught(arena);
                test_print_test_result(SLOP_STR("corpus: every out-of-profile fixture is caught"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_gate_annotation_heavy_is_clean(arena);
                test_print_test_result(SLOP_STR("§12(a): an annotated ontology GATES clean"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_gate_carries_import_omissions(arena);
                test_print_test_result(SLOP_STR("§12(b): a stage-0 import omission survives the gate"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sugar_transitivity_becomes_a_chain(arena);
                test_print_test_result(SLOP_STR("sugar: TransitiveObjectProperty becomes r o r subseteq r"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sugar_nary_disjointness_becomes_pairs(arena);
                test_print_test_result(SLOP_STR("sugar: 3 disjoint classes give exactly 3 pairs"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sugar_equivalence_is_a_star_not_all_pairs(arena);
                test_print_test_result(SLOP_STR("sugar: equivalence expands to a canonical star"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_gate_accepts_every_v0_fixture(arena);
                test_print_test_result(SLOP_STR("gate: all 20 v0 fixtures gate CLEAN (false-fail half)"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_gate_rejects_every_out_of_profile_fixture(arena);
                test_print_test_result(SLOP_STR("gate: all 14 out-of-profile fixtures are omitted"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_regularity_rejects_mutual_recursion(arena);
                test_print_test_result(SLOP_STR("regularity: mutually recursive chains are rejected"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_regularity_accepts_equivalence_and_transitivity(arena);
                test_print_test_result(SLOP_STR("regularity: equivalent roles + transitivity ACCEPTED"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_regularity_accepts_plain_subproperty(arena);
                test_print_test_result(SLOP_STR("regularity: a plain subPropertyOf is accepted"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_regularity_accepts_nary_chain(arena);
                test_print_test_result(SLOP_STR("regularity: a well-founded n-ary chain is accepted"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_irregular_rbox_is_omitted_whole(arena);
                test_print_test_result(SLOP_STR("regularity: an irregular RBox is omitted WHOLE"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_range_composition_table(arena);
                test_print_test_result(SLOP_STR("range: all 12 rows of §5.2's verdict table"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_equality_never_drops_an_operand(arena);
                test_print_test_result(SLOP_STR("decode: sameAs/differentFrom never drop an operand"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_anonymous_members_are_omissions_not_faults(arena);
                test_print_test_result(SLOP_STR("decode: an anonymous AllDifferent/oneOf member is an omission"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_negative_assertion_decodes_whole(arena);
                test_print_test_result(SLOP_STR("decode: a negative assertion is read whole, its parts consumed"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_literal_has_value_is_data(arena);
                test_print_test_result(SLOP_STR("decode: a literal hasValue is data"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_el_plus_plus_gate_table(arena);
                test_print_test_result(SLOP_STR("gate: el++ admits its constructs, el omits them (two-rung table)"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_top_role_tautology_is_dropped(arena);
                test_print_test_result(SLOP_STR("gate: under el++, an inclusion into the universal role is dropped"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_ksc_normal_form_rows(arena);
                test_print_test_result(SLOP_STR("kscnormal: each translation row gives exactly its Definition 1 facts"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_negation_rewrites_to_bottom_gcis(arena);
                test_print_test_result(SLOP_STR("negation: each positive ¬E becomes exactly its ⊥ GCI"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_negation_rewrites_whole_axioms_or_none(arena);
                test_print_test_result(SLOP_STR("negation: a partly-out axiom is omitted as written"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_negative_range_normalizes_to_bottom(arena);
                test_print_test_result(SLOP_STR("negation: a negative range is ∃r.B ⊑ ⊥, on the left"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_undeclared_property_is_an_input_error(arena);
                test_print_test_result(SLOP_STR("declarations: an ambiguous undeclared property FAULTS"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_unknown_owl_vocabulary_still_decodes(arena);
                test_print_test_result(SLOP_STR("declarations: unknown owl: vocabulary gates, never faults"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_conflicting_declarations_are_an_input_error(arena);
                test_print_test_result(SLOP_STR("declarations: conflicting kinds fault; punning still legal"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_missing_class_declaration_is_reported(arena);
                test_print_test_result(SLOP_STR("declarations: an undeclared CLASS is a missing-declaration"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_undeclared_individual_is_not_reported(arena);
                test_print_test_result(SLOP_STR("declarations: an undeclared individual is NOT a finding"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_annotation_property_axioms_are_inert(arena);
                test_print_test_result(SLOP_STR("inert: annotation property domain/range/subPropertyOf"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_reserved_iri_as_individual_is_out_of_profile(arena);
                test_print_test_result(SLOP_STR("reserved: owl:Nothing as an individual is reported"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_litmus_reproduces_the_m1_normal_form(arena);
                test_print_test_result(SLOP_STR("§12: litmus.ttl reproduces M1's canonical normal form"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_normalization_polarity_is_negative_on_the_left(arena);
                test_print_test_result(SLOP_STR("normalize: the defining existential is NEGATIVE"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_nary_chain_decomposes_left_associated(arena);
                test_print_test_result(SLOP_STR("normalize: an n-ary chain becomes binary steps"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_range_elimination_introduces_a_shared_filler(arena);
                test_print_test_result(SLOP_STR("normalize: range elimination rewrites the existential"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_asserted_edges_seed_their_range(arena);
                test_print_test_result(SLOP_STR("normalize: asserted edges seed ran_T into the target"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_range_complex_fillers_stay_apart(arena);
                test_print_test_result(SLOP_STR("normalize: complex range fillers get distinct X_{r,D}"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_inverse_expressions_are_omissions(arena);
                test_print_test_result(SLOP_STR("decode: ObjectInverseOf is an omission, not an input-error"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_accounting_holds(arena);
                test_print_test_result(SLOP_STR("§12: every accepted axiom is discharged (accounting)"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_canonicalization_is_idempotent(arena);
                test_print_test_result(SLOP_STR("§12: canonicalization is idempotent"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_fresh_nodes_are_fresh(arena);
                test_print_test_result(SLOP_STR("§12: fresh ids are bounded and dense"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_triple_order_independence(arena);
                test_print_test_result(SLOP_STR("§6.8: reversed triples give the same normal form and report"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_indexed_dispatch_matches_reference(arena);
                test_print_test_result(SLOP_STR("M1: the premise index concludes exactly what the full scan does"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_quoted_triple_header_subjects(arena);
                test_print_test_result(SLOP_STR("stage 0: a quoted-triple header subject is matched structurally"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_strict_refuses_past_omissions(arena);
                test_print_test_result(SLOP_STR("§10.12: strict refuses with omissions, and only then"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_profile_selection(arena);
                test_print_test_result(SLOP_STR("§5.1: default and auto run el; unbuilt rungs are refused by name"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_profile_names_round_trip(arena);
                test_print_test_result(SLOP_STR("§5.1: rung names round-trip"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            printf("%s\n", "");
            printf("%s\n", "========================================");
            printf("%s", "Passed: ");
            printf("%.*s\n", (int)(int_to_string(arena, passed)).len, (int_to_string(arena, passed)).data);
            printf("%s", "Failed: ");
            printf("%.*s\n", (int)(int_to_string(arena, failed)).len, (int_to_string(arena, failed)).data);
            printf("%s\n", "========================================");
            if (failed == 0) {
                {
                    int _wa_ret = 0;
                    slop_arena_free(arena);
                    return _wa_ret;
                }
            } else {
                {
                    int _wa_ret = 1;
                    slop_arena_free(arena);
                    return _wa_ret;
                }
            }
        }
        slop_arena_free(arena);
    }
}

