#include "../runtime/slop_runtime.h"
#include "slop_test.h"

types_Saturation test_empty_saturation(slop_arena* arena);
types_Saturation test_outcome_saturation(slop_arena* arena, types_Outcome o);
howl_ElWork test_prepared_el_work(slop_arena* arena, howl_Prepared p);
types_Findings test_make_findings(slop_arena* arena, uint8_t inconsistent, int64_t unsat_count);
types_Outcome test_make_outcome(slop_arena* arena, uint8_t inconsistent, int64_t unsat_count, int64_t omitted_count, uint8_t reached_fixpoint);
uint8_t test_verdict_eq(types_Verdict a, types_Verdict b);
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
slop_string test_cites_lines(slop_arena* arena, slop_list_types_AxiomRef refs);
slop_string test_cited_text(slop_arena* arena, gate_GateResult gr, slop_string iri);
uint8_t test_test_missing_declaration_cites_its_axioms(slop_arena* arena);
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
int64_t test_accepted_under(slop_arena* arena, slop_string ttl, types_Profile p);
uint8_t test_gate_alike_under(slop_arena* arena, slop_string label, slop_string a, slop_string b, types_Profile p);
uint8_t test_rungs_gate_alike(slop_arena* arena, slop_string label, slop_string ttl_a, slop_string ttl_b);
uint8_t test_rungs_omit(slop_arena* arena, slop_string label, slop_string ttl, int64_t el_want, int64_t elpp_want);
uint8_t test_test_data_lemma(slop_arena* arena);
slop_string test_inv_decls(void);
uint8_t test_test_inverses_decode_whole(slop_arena* arena);
uint8_t test_test_data_constructs_decode_as_data(slop_arena* arena);
uint8_t test_test_concept_order_is_total(slop_arena* arena);
owl2_RawConcept* test_box_test_concept(slop_arena* arena, owl2_RawConcept c);
uint8_t test_rungs3_omit(slop_arena* arena, slop_string label, slop_string ttl, int64_t el_want, int64_t elpp_want, int64_t sriq_want);
slop_string test_s0_prefix(void);
slop_string test_render_saxioms(slop_arena* arena, slop_list_sroiq_SAxiom axs);
slop_string test_s0_of(slop_arena* arena, slop_string ttl, uint8_t through_s1);
uint8_t test_s0_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
uint8_t test_s1_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
uint8_t test_test_sriq_s0_rows(slop_arena* arena);
slop_list_string test_sort_strings(slop_arena* arena, slop_list_string xs);
slop_string test_str_at_t(slop_list_string xs, int64_t i);
slop_string test_refusal_line(slop_arena* arena, slop_string m);
slop_string test_s2_text(slop_arena* arena, slop_result_sriqnormal_S2_string r);
slop_string test_s2_after_s1(slop_arena* arena, slop_result_sriqelim_S1_string r);
slop_string test_s2_after_s0(slop_arena* arena, slop_result_sriqnormal_S0_string r);
slop_string test_s2_of(slop_arena* arena, slop_string ttl);
uint8_t test_s2_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
slop_list_string test_sriq_fixtures(slop_arena* arena);
slop_option_gate_GateResult test_gate_triples_in(slop_arena* arena, slop_list_rdf_Triple ts, types_Profile p);
slop_list_owl2_RawAxiom test_reversed_raw(slop_arena* arena, slop_list_owl2_RawAxiom xs);
slop_list_sroiq_SAxiom test_reversed_saxioms(slop_arena* arena, slop_list_sroiq_SAxiom xs);
slop_result_sriqnames_SriqNormal_string test_s2_to_names(slop_arena* arena, gate_GateResult gr, sriqelim_S1 s1, uint8_t flip);
sriqnormal_S0 test_reversed_s0(slop_arena* arena, sriqnormal_S0 s0);
slop_result_sriqnames_SriqNormal_string test_sriq_nf(slop_arena* arena, gate_GateResult gr, uint8_t flip_accepted, uint8_t flip_s0, uint8_t flip_s2);
slop_list_string test_nf_lines(slop_arena* arena, slop_result_sriqnames_SriqNormal_string r);
uint8_t test_nf_invariants_hold(slop_arena* arena, slop_string path, slop_result_sriqnames_SriqNormal_string r);
uint8_t test_sriq_order_independent(slop_arena* arena, slop_string path);
uint8_t test_test_sriq_ids_row(slop_arena* arena);
uint8_t test_test_sriq_one_clause_from_two_axioms(slop_arena* arena);
uint8_t test_test_sriq_ids_from_content(slop_arena* arena);
uint8_t test_yields_nothing_by_design(owl2_RawAxiom a);
slop_list_owl2_RawAxiom test_one_raw(slop_arena* arena, owl2_RawAxiom a);
uint8_t test_print_alone(slop_arena* arena, owl2_RawAxiom a);
uint8_t test_is_chain_axiom(owl2_RawAxiom a);
int64_t test_yield_kind(slop_arena* arena, owl2_RawAxiom a, owl2_Signature sig);
uint8_t test_every_axiom_yields(slop_arena* arena, slop_string path);
uint8_t test_test_sriq_every_axiom_yields(slop_arena* arena);
slop_string test_s1_text(slop_arena* arena, sriqelim_S1 s1);
slop_string test_s1_bounded_of(slop_arena* arena, slop_string ttl, int64_t bound);
uint8_t test_s1_bounded_is(slop_arena* arena, slop_string label, slop_string ttl, int64_t bound, slop_string want);
uint8_t test_test_sriq_guard_witnesses(slop_arena* arena);
uint8_t test_test_sriq_s1_rows(slop_arena* arena);
uint8_t test_s1_invariants_hold(slop_arena* arena, slop_string path);
uint8_t test_print_problems(slop_string path, slop_list_string bad);
uint8_t test_test_sriq_s1_invariants(slop_arena* arena);
uint8_t test_test_sriq_s2_refuses_a_count_past_the_bound(slop_arena* arena);
uint8_t test_test_sriq_s2_rows(slop_arena* arena);
rdf_IRI test_x_iri(slop_arena* arena, slop_string local);
types_DName test_dn(slop_arena* arena, slop_string local);
types_DRole test_dp(slop_arena* arena, slop_string local);
slop_list_rdf_IRI test_iris_of(slop_arena* arena, slop_list_string locals);
slop_list_string test_strs(slop_arena* arena, slop_string text);
slop_list_string test_line1(slop_arena* arena, slop_string text);
sriqnames_SriqNormal test_row_normal(slop_arena* arena, slop_list_types_DlClause cs, int64_t nfresh, int64_t nsub, int64_t nfns);
slop_string test_clause_text(slop_arena* arena, sriqnames_SriqNormal n);
uint8_t test_clauses_sound(slop_arena* arena, sriqnames_SriqNormal n);
uint8_t test_table1_is(slop_arena* arena, slop_string label, sriqnames_SriqNormal n, slop_string want);
slop_list_types_DlClause test_one_dl(slop_arena* arena, types_DlClause c);
types_DlClause test_dl1_of(slop_arena* arena, slop_string body, slop_string head);
slop_list_int test_fn_ids(slop_arena* arena, int64_t n);
types_DlClause test_dl4_of(slop_arena* arena, slop_string sub, int64_t n, slop_option_types_DName filler);
types_DlClause test_dl2_of(slop_arena* arena, slop_string sub, types_DRole role, int64_t n, slop_option_types_DName filler);
uint8_t test_table1_rows_names(slop_arena* arena);
uint8_t test_table1_rows_dl4(slop_arena* arena);
uint8_t test_table1_rows_roles(slop_arena* arena);
uint8_t test_test_sriq_table1_rows(slop_arena* arena);
uint8_t test_boundary_refuses(slop_arena* arena, slop_string label, sriqnames_SriqNormal n, slop_string want);
uint8_t test_test_sriq_clauses_cover_every_name(slop_arena* arena);
slop_list_types_Lit test_lits_of(slop_arena* arena, types_Lit a, types_Lit b, types_Lit c);
slop_list_types_Lit test_no_lits(slop_arena* arena);
slop_list_types_Lit test_one_lit(slop_arena* arena, types_Lit a);
uint8_t test_not_canonical(slop_list_types_Lit body, slop_list_types_Lit head);
uint8_t test_canonical_rejects(slop_arena* arena);
slop_list_types_Lit test_lits2_of(slop_arena* arena, types_Lit a, types_Lit b);
slop_map* test_index_classes(slop_arena* arena, slop_list_types_DName ds);
slop_map* test_index_iris(slop_arena* arena, slop_list_rdf_IRI xs);
uint8_t test_permuted_tables_flagged(slop_arena* arena, types_Clause ok_clause);
slop_list_types_DRole test_bars_swapped(slop_arena* arena);
slop_map* test_bar_index(slop_arena* arena);
uint8_t test_shape_rejects(slop_arena* arena);
uint8_t test_flagged(slop_arena* arena, sriqclauses_SriqIds ids, types_Clause c);
uint8_t test_ids_dense_rejects(slop_arena* arena);
slop_list_types_DName test_reverse_dnames(slop_arena* arena, slop_list_types_DName xs);
uint8_t test_test_sriq_clause_checks_reject(slop_arena* arena);
slop_list_types_ATerm test_sample_aterms(slop_arena* arena);
uint8_t test_oriented_pair_ok(types_ATerm s, types_ATerm t, uint8_t same);
uint8_t test_test_sriq_eq_orientation(slop_arena* arena);
slop_list_string test_clause_lines(slop_arena* arena, slop_result_sriqnames_SriqNormal_string r);
uint8_t test_fixture_clauses_ok(slop_arena* arena, slop_string path);
uint8_t test_test_sriq_clauses_on_fixtures(slop_arena* arena);
sriqorder_SriqOrder test_ord_table(slop_arena* arena);
slop_list_int test_ord_label(slop_arena* arena, sriqorder_SriqOrder ord, uint32_t u);
int64_t test_ord_ints_cmp(slop_list_int a, slop_list_int b);
uint8_t test_ref_const_gt(slop_arena* arena, sriqorder_SriqOrder ord, uint32_t a, uint32_t b);
uint8_t test_ref_is_var(types_ATerm t);
uint8_t test_ref_has_arg(types_ATerm t);
types_ATerm test_ref_arg(types_ATerm t);
uint8_t test_ref_prec_gt(slop_arena* arena, sriqorder_SriqOrder ord, types_ATerm a, types_ATerm b);
uint8_t test_ref_same_head(types_ATerm a, types_ATerm b);
uint8_t test_ref_lpo(slop_arena* arena, sriqorder_SriqOrder ord, types_ATerm s, types_ATerm t);
uint8_t test_ord_aterm_same(types_ATerm a, types_ATerm b);
slop_list_types_ATerm test_ord_aterms(slop_arena* arena);
slop_list_sriqorder_CTerm test_ord_push_binary(slop_arena* arena, slop_list_sriqorder_CTerm out, types_ATerm l, types_ATerm r);
slop_list_sriqorder_CTerm test_ord_universe(slop_arena* arena);
sriqorder_CTerm test_ord_ct_at(slop_list_sriqorder_CTerm xs, int64_t i);
uint8_t test_ord_get(slop_list_u8 m, int64_t n, int64_t i, int64_t j);
uint8_t test_ord_ge(slop_list_u8 m, int64_t n, slop_list_sriqorder_CTerm u, int64_t i, int64_t j);
int64_t test_ord_index(slop_list_sriqorder_CTerm u, types_ATerm t);
uint8_t test_ord_arg_ge(slop_list_u8 m, int64_t n, slop_list_sriqorder_CTerm u, types_ATerm arg, int64_t j);
uint8_t test_ord_p_args_le(slop_list_u8 m, int64_t n, slop_list_sriqorder_CTerm u, types_Lit a, types_Lit b);
uint8_t test_ord_generated(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_u8 m, int64_t n, slop_list_sriqorder_CTerm u, int64_t i, int64_t j);
uint8_t test_ord_items_1_3(slop_arena* arena, sriqorder_SriqOrder ord, types_ATerm s, types_ATerm t);
slop_list_u8 test_ord_step(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_u8 m, int64_t n, slop_list_sriqorder_CTerm u);
slop_list_u8 test_ord_close(slop_list_u8 m, int64_t n);
uint8_t test_ord_close_row(slop_list_u8 m, int64_t n, int64_t i, int64_t k);
int64_t test_ord_count(slop_list_u8 m);
slop_list_u8 test_ord_least(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_sriqorder_CTerm u);
slop_string test_ct_text(slop_arena* arena, sriqorder_CTerm c);
slop_string test_aterm_code(slop_arena* arena, types_ATerm t);
int64_t test_akind_code(types_AKind k);
uint8_t test_test_sriq_order_closure(slop_arena* arena);
int64_t test_ord_row_mismatches(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_sriqorder_CTerm u, slop_list_u8 m, int64_t i, int64_t seen);
uint8_t test_test_sriq_order_strict_and_admissible(slop_arena* arena);
uint8_t test_ord_pair_ok(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_sriqorder_CTerm u, sriqorder_CTerm s, sriqorder_CTerm t);
uint8_t test_test_sriq_order_c2(slop_arena* arena);
uint8_t test_ord_c2_exempt(sriqorder_CTerm s);
uint8_t test_test_sriq_const_order(slop_arena* arena);
uint8_t test_const_row_ok(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_int ranks, int64_t a);
slop_string test_flags_text(slop_arena* arena, slop_list_u8 fs);
uint8_t test_flags_are(slop_arena* arena, slop_string label, slop_list_types_Lit head, slop_string want);
slop_list_types_Lit test_two_lits(slop_arena* arena, types_Lit a, types_Lit b);
uint8_t test_test_sriq_max_flags_rows(slop_arena* arena);
slop_list_types_Lit test_sample_lits(slop_arena* arena);
uint8_t test_lits_strict(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Lit ls);
slop_list_types_Lit test_letter_atoms(slop_arena* arena, slop_string letters);
types_Clause test_cl(slop_arena* arena, slop_string body, slop_string head);
types_Clause test_with_lit(slop_arena* arena, types_Clause c, types_Lit l);
slop_list_types_Clause test_clauses_of(slop_arena* arena, types_Clause a, types_Clause b);
uint8_t test_test_sriq_inhat_rows(slop_arena* arena);
slop_list_types_Clause test_reference_min(slop_arena* arena, slop_list_types_Clause xs);
uint8_t test_in_list(slop_list_types_Clause xs, types_Clause c);
uint8_t test_same_clause_set(slop_list_types_Clause a, slop_list_types_Clause b);
slop_list_types_Clause test_commit_w(slop_arena* arena);
slop_list_types_Clause test_commit_candidates(slop_arena* arena);
types_Clause test_clause_list_at(slop_list_types_Clause xs, int64_t i, types_Clause fallback);
slop_list_types_Clause test_permuted(slop_arena* arena, slop_list_types_Clause xs, int64_t code);
slop_list_types_Clause test_appended(slop_arena* arena, slop_list_types_Clause a, slop_list_types_Clause b);
slop_list_types_Clause test_new_members(slop_arena* arena, slop_list_types_Clause xs, slop_list_types_Clause ws);
uint8_t test_order_ok(slop_arena* arena, slop_list_types_Clause ws, slop_list_types_Clause order, slop_list_types_Clause want, slop_list_types_Clause want_added);
uint8_t test_test_sriq_commit_min_permutation(slop_arena* arena);
uint8_t test_keeps_but_adds_not(slop_arena* arena);
uint8_t test_test_sriq_commit_survivors(slop_arena* arena);
uint8_t test_test_sriq_inhat_persists(slop_arena* arena);
types_Lit test_r_atom(int64_t c, types_ATerm t);
types_Lit test_r_role(int64_t r, types_ATerm a, types_ATerm b);
types_ATerm test_r_fx(int64_t f);
types_Clause test_r_clause(slop_arena* arena, slop_list_types_Lit body, slop_list_types_Lit head);
slop_list_sriq_Premise test_r_premises(slop_arena* arena, sriqorder_SriqOrder ord, types_Clause c);
slop_list_sriq_Cands test_r_cands(slop_arena* arena, sriqorder_SriqOrder ord, int64_t atoms, slop_list_types_Clause cs);
slop_list_types_Clause test_r_hyper(slop_arena* arena, sriq_HState start, types_Clause ont, slop_list_types_Clause cs);
slop_list_types_Clause test_r_useful(slop_arena* arena, slop_list_types_Clause cs);
slop_list_types_Clause test_r_one(slop_arena* arena, types_Clause c);
uint8_t test_hyper_is(slop_arena* arena, slop_string label, slop_list_types_Clause got, slop_list_types_Clause want);
sriq_Premise test_r_premise(slop_arena* arena, sriqorder_SriqOrder ord, types_Clause c, types_Lit l);
uint8_t test_test_sriq_hyper_rows(slop_arena* arena);
uint8_t test_test_sriq_hyper_dl4(slop_arena* arena);
uint8_t test_test_sriq_hyper_root_rows(slop_arena* arena);
uint8_t test_test_sriq_hyper_example1(slop_arena* arena);
uint8_t test_test_sriq_ineq_factor_core_rows(slop_arena* arena);
uint8_t test_test_sriq_factor_each_condition(slop_arena* arena);
sriq_Pos test_r_pos(int64_t k, uint8_t inner);
types_Clause test_r_top(slop_arena* arena, slop_list_types_Lit head);
sriq_RConcl test_r_eq(slop_arena* arena, uint8_t root, types_Clause c1, types_Lit l1, int64_t k1, types_Clause c2, types_Lit l2, sriq_Pos p);
uint8_t test_eq_gives(slop_arena* arena, slop_string label, sriq_RConcl r, types_Clause want);
uint8_t test_test_sriq_eq_rows(slop_arena* arena);
int64_t test_side_of(types_Lit l, types_ATerm s);
uint8_t test_test_sriq_eq_excluded(slop_arena* arena);
uint8_t test_test_sriq_join_rows(slop_arena* arena);
sriq_BodyView test_r_body(slop_arena* arena, types_Clause c, types_Lit l);
sriqorder_SriqOrder test_r_kids_order(slop_arena* arena);
slop_list_u32 test_r_ids(slop_arena* arena, int64_t a, int64_t b);
uint8_t test_test_sriq_nom_rows(slop_arena* arena);
uint8_t test_test_sriq_depth_limit(slop_arena* arena);
uint8_t test_test_sriq_gate_table(slop_arena* arena);
uint8_t test_test_el_plus_plus_gate_table(slop_arena* arena);
uint8_t test_test_top_role_tautology_is_dropped(slop_arena* arena);
slop_string test_ksc_form_of_ttl(slop_arena* arena, slop_string ttl);
uint8_t test_ksc_form_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
slop_option_test_KscFixture test_ksc_fixture(slop_arena* arena, slop_string path);
slop_string test_kname_label(slop_arena* arena, types_KName n);
uint8_t test_ksc_engine_matches_reference(slop_arena* arena, slop_string label, slop_string ttl);
int64_t test_ksc_holds(slop_arena* arena, slop_string ttl, slop_string a, slop_string b);
int64_t test_ksc_inconsistent(slop_arena* arena, slop_string ttl);
int64_t test_ksc_fixture_count(void);
slop_string test_ksc_fixture_at(int64_t i);
types_ReasonerConfig test_cap_config(int64_t cap);
int64_t test_incomplete_answers(types_KscResult r);
uint8_t test_says_resource_limit(types_KscResult r);
int64_t test_capped_incomplete(slop_arena* arena, test_KscFixture fx);
uint8_t test_test_ksc_cut_runs_say_resource_limit(slop_arena* arena);
types_KFact test_ex_class_fact(slop_arena* arena, slop_string ind, slop_string cls);
uint8_t test_test_ksc_g_stops_at_bottom(slop_arena* arena);
uint8_t test_test_ksc_engine_matches_reference(slop_arena* arena);
uint8_t test_test_ksc_entailments(slop_arena* arena);
slop_option_types_Outcome test_classify_fixture_in(slop_arena* arena, slop_string path, types_Profile profile);
slop_list_string test_rung_neutral_lines(slop_arena* arena, types_Outcome o);
uint8_t test_rungs_agree_on(slop_arena* arena, slop_string path);
uint8_t test_test_el_and_el_plus_plus_agree(slop_arena* arena);
types_KscResult test_ksc_run(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, types_ReasonerConfig config);
int64_t test_cancel_flag_set(void);
uint8_t test_test_ksc_cancelled(slop_arena* arena);
uint8_t test_cancelled_under(slop_arena* arena, types_ReasonerConfig base_cfg);
uint8_t test_ids_round_trip(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes);
uint8_t test_test_ksc_ids_round_trip(slop_arena* arena);
uint8_t test_holds_under(kscpremise_KscIndex idx, slop_list_types_KFact fs, types_KElem x, types_RoleId v, types_KElem y);
uint8_t test_g_matches_reference(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes);
uint8_t test_test_ksc_g_matches_reference(slop_arena* arena);
uint8_t test_commit_agrees(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, uint8_t stop, uint8_t with_classes);
uint8_t test_commit_shapes_agree(slop_arena* arena, test_KscFixture fx, int64_t i);
uint8_t test_test_ksc_commit_identical(slop_arena* arena);
types_ReasonerConfig test_ksc_config(int64_t workers, int64_t cap);
uint8_t test_answers_equal(types_KscResult a, types_KscResult b);
uint8_t test_test_ksc_workers_agree(slop_arena* arena);
uint8_t test_same_run(types_KscResult a, types_KscResult b);
slop_list_int test_workers_under_test(slop_arena* arena);
uint8_t test_test_ksc_seed_unsat_counts_no_round(slop_arena* arena);
int64_t test_nothing_run_rounds(types_KscResult r);
int64_t test_max_run_rounds(types_KscResult r);
uint8_t test_test_ksc_cap(slop_arena* arena);
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
uint8_t test_encoded_agrees(slop_arena* arena, slop_string path, types_ProfileSelection selection);
uint8_t test_test_classify_encoded_is_classify(slop_arena* arena);
slop_option_string test_file_text(slop_arena* arena, slop_string path);
slop_list_string test_api_lines(slop_arena* arena, howl_Run r);
uint8_t test_api_agrees(slop_arena* arena, slop_string path, types_Profile profile);
howl_FaultKind test_api_fault(howl_Options o);
uint8_t test_test_public_api(slop_arena* arena);
uint8_t test_order_independent(slop_arena* arena, slop_string path);
uint8_t test_test_triple_order_independence(slop_arena* arena);
uint8_t test_addressed_subset(slop_list_types_Addressed xs, slop_list_types_Addressed ys);
uint8_t test_same_conclusions(slop_arena* arena, types_Context ctx, types_Derived d, premise_RuleIndex idx, slop_list_types_NormAxiom axioms);
uint8_t test_dispatch_agrees(slop_arena* arena, slop_string path);
uint8_t test_test_indexed_dispatch_matches_reference(slop_arena* arena);
uint8_t test_test_quoted_triple_header_subjects(slop_arena* arena);
int64_t test_strict_outcome(slop_arena* arena, slop_string path);
test_RunAs test_profile_run(slop_arena* arena, slop_string path, types_ProfileSelection selection);
uint8_t test_ran_as(test_RunAs r, types_Profile want);
uint8_t test_refused_as(test_RunAs r, types_Profile want);
uint8_t test_test_profile_selection(slop_arena* arena);
uint8_t test_test_profile_names_round_trip(slop_arena* arena);
uint8_t test_test_dropped_rung_refusal(slop_arena* arena);
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
slop_list_rdf_Triple test_rest_forked(slop_arena* arena);
uint8_t test_list_branches(slop_arena* arena, slop_list_rdf_Triple ts, rdf_Term head);
slop_string test_decode_prefix(void);
slop_string test_decoded_text(slop_arena* arena, slop_string ttl);
uint8_t test_decodes_exactly(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
uint8_t test_test_decode_rows(slop_arena* arena);
uint8_t test_test_sort_is_stable(slop_arena* arena);
uint8_t test_test_sort_is_a_permutation(slop_arena* arena);
void test_print_test_result(slop_string name, uint8_t passed);
slop_string test_arg_text(uint8_t** argv, int64_t i);
slop_list_rdf_IRI test_dump_classes(slop_arena* arena, owl2_Signature sig);
int64_t test_print_lines(slop_list_string ls);
int64_t test_dump_refused(slop_string m);
int64_t test_dump_s1(slop_arena* arena, gate_GateResult gr, slop_result_sriqnormal_S0_string r, int64_t bound);
int64_t test_dump_s1_invariants(slop_arena* arena, gate_GateResult gr, int64_t bound);
uint8_t test_s1_guarded(slop_arena* arena, gate_GateResult gr, int64_t bound);
uint8_t test_uses_reserved(slop_arena* arena, owl2_Signature sig);
int64_t test_clauses_report(slop_arena* arena, sriqclauses_SriqClauses sc);
int64_t test_clauses_check(slop_arena* arena, slop_result_sriqnames_SriqNormal_string r);
int64_t test_dump_stage(slop_arena* arena, slop_string stage, gate_GateResult gr, int64_t bound);
int64_t test_sriq_dump(slop_arena* arena, slop_string stage, slop_string path, int64_t bound);
int64_t test_bound_arg(slop_string s);
int64_t test_dump_tagged(slop_string tag, slop_string text);
int64_t test_dump_axiom_list(slop_arena* arena, slop_string tag, slop_list_owl2_RawAxiom axs);
int64_t test_dump_axiom_ref(slop_string tag, types_AxiomRef r);
int64_t test_dump_cited(slop_string tag, types_Omission o);
int64_t test_dump_omission_list(slop_arena* arena, slop_string tag, slop_list_types_Omission os);
int64_t test_dump_fault(slop_arena* arena, types_Fault f);
int64_t test_dump_signature(slop_arena* arena, owl2_Signature sig);
int64_t test_dump_triple(slop_arena* arena, termstore_IdTriple t);
int64_t test_dump_stage0(slop_arena* arena, decode_Stage0 s0);
int64_t test_dump_regularity(slop_arena* arena, slop_list_owl2_RawAxiom axs);
int64_t test_dump_rung(slop_arena* arena, decode_Stage0 s0, decode_Stage1 s1, types_Profile p, slop_string tag);
int64_t test_dump_decoded(slop_arena* arena, decode_Stage0 s0, decode_Stage1 s1);
int64_t test_front_dump(slop_arena* arena, slop_string path);
slop_string test_yes_no(uint8_t b);
int64_t test_dump_num(slop_arena* arena, slop_string tag, int64_t n);
int64_t test_dump_flag(slop_string tag, uint8_t b);
int64_t test_dump_cfact(slop_arena* arena, kscids_CFact c);
int64_t test_dump_ksc_run(slop_arena* arena, slop_string tag, kscsat_RunResult r);
slop_list_types_KFact test_ksc_seeds(slop_arena* arena, kscpremise_KscIndex idx, slop_list_types_KName classes, uint8_t w_phase);
int64_t test_dump_ksc_phases(slop_arena* arena, kscpremise_KscIndex idx, kscids_KscIds ids, slop_list_types_KName classes, int64_t w);
int64_t test_dump_answer(slop_arena* arena, types_ClassAnswer a);
int64_t test_dump_ksc_result(slop_arena* arena, types_KscResult r);
int64_t test_dump_ksc_classify(slop_arena* arena, test_KscFixture fx, int64_t w, int64_t cap);
int64_t test_dump_ksc_caps(slop_arena* arena, test_KscFixture fx, int64_t w);
int64_t test_ksc_dump(slop_arena* arena, slop_string path);
int main(int argc, char** _c_argv);
int64_t test_run_suite(void);

typedef struct { slop_list_string xs; } test__lambda_1496_env_t;

static int64_t test__lambda_1496(test__lambda_1496_env_t* _env, int64_t i, int64_t j) { return canon_string_cmp(test_str_at_t(_env->xs, i), test_str_at_t(_env->xs, j)); }

static int64_t test__lambda_1705(void* _env, int64_t a, int64_t b) { return ({ __auto_type ka = (2 - (a / 3)); __auto_type kb = (2 - (b / 3)); ((ka < kb) ? -1 : ((ka > kb) ? 1 : 0)); }); }

types_Saturation test_empty_saturation(slop_arena* arena) {
    return ((types_Saturation){.contexts = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, types_Context); slop_map_new_ptr(arena, 0, &_d); }), .queues = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, types_Queue); slop_map_new_ptr(arena, 0, &_d); }), .active = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .active_count = 0, .iteration = 0});
}

types_Saturation test_outcome_saturation(slop_arena* arena, types_Outcome o) {
    __auto_type _mv_1400 = o.evidence;
    switch (_mv_1400.tag) {
        case types_Evidence_el_evidence:
        {
            __auto_type sat = _mv_1400.data.el_evidence;
            return sat;
        }
        case types_Evidence_ksc_evidence:
        {
            __auto_type _ = _mv_1400.data.ksc_evidence;
            return test_empty_saturation(arena);
        }
    }
    SLOP_UNREACHABLE();
}

howl_ElWork test_prepared_el_work(slop_arena* arena, howl_Prepared p) {
    __auto_type _mv_1401 = p.work;
    switch (_mv_1401.tag) {
        case howl_Work_el_work:
        {
            __auto_type w = _mv_1401.data.el_work;
            return w;
        }
        case howl_Work_ksc_work:
        {
            __auto_type _ = _mv_1401.data.ksc_work;
            return ((howl_ElWork){.axioms = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .index = premise_build_rule_index(arena, ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena })), .saturation = test_empty_saturation(arena)});
        }
    }
    SLOP_UNREACHABLE();
}

types_Findings test_make_findings(slop_arena* arena, uint8_t inconsistent, int64_t unsat_count) {
    {
        __auto_type unsat = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (unsat_count > 0) {
            ({ __auto_type _lst_p = &(unsat); __auto_type _item = (((rdf_IRI){.value = SLOP_STR("http://example.org/Unsat")})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return ((types_Findings){.inconsistent = inconsistent, .unsatisfiable = unsat, .subsumptions = ((slop_list_types_SubPair){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .imports_seen = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
    }
}

types_Outcome test_make_outcome(slop_arena* arena, uint8_t inconsistent, int64_t unsat_count, int64_t omitted_count, uint8_t reached_fixpoint) {
    {
        __auto_type omitted = ((slop_list_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (omitted_count > 0) {
            ({ __auto_type _lst_p = &(omitted); __auto_type _item = (((types_Omission){ .tag = types_Omission_unresolved_import, .data.unresolved_import = ((rdf_IRI){.value = SLOP_STR("http://example.org/missing-import")}) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return ((types_Outcome){.profile = types_Profile_profile_el, .coverage = ((types_Coverage){.omitted = omitted}), .termination = ((reached_fixpoint) ? ((types_Termination){ .tag = types_Termination_fixpoint }) : ((types_Termination){ .tag = types_Termination_resource_limit, .data.resource_limit = 1000 })), .findings = test_make_findings(arena, inconsistent, unsat_count), .evidence = ((types_Evidence){ .tag = types_Evidence_el_evidence, .data.el_evidence = test_empty_saturation(arena) }), .rounds = 0, .names = types_empty_names(arena), .owned = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
    }
}

uint8_t test_verdict_eq(types_Verdict a, types_Verdict b) {
    return (a == b);
}

uint8_t test_test_coherent_requires_complete(slop_arena* arena) {
    return test_verdict_eq(types_verdict(test_make_outcome(arena, 0, 0, 0, 1)), types_Verdict_verdict_coherent);
}

uint8_t test_test_omission_blocks_coherent(slop_arena* arena) {
    return test_verdict_eq(types_verdict(test_make_outcome(arena, 0, 0, 1, 1)), types_Verdict_verdict_inconclusive);
}

uint8_t test_test_cap_blocks_coherent(slop_arena* arena) {
    return test_verdict_eq(types_verdict(test_make_outcome(arena, 0, 0, 0, 0)), types_Verdict_verdict_inconclusive);
}

uint8_t test_test_finding_beats_partial_coverage(slop_arena* arena) {
    return test_verdict_eq(types_verdict(test_make_outcome(arena, 1, 0, 1, 0)), types_Verdict_verdict_incoherent);
}

uint8_t test_test_consistent_but_incoherent(slop_arena* arena) {
    return (test_verdict_eq(types_verdict(test_make_outcome(arena, 0, 1, 0, 1)), types_Verdict_verdict_incoherent) && types_findings_are_incoherent(test_make_findings(arena, 0, 1)));
}

uint8_t test_test_context_starts_with_empty_store(slop_arena* arena) {
    {
        __auto_type ctx = types_make_context(arena, ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = SLOP_STR("http://example.org/C")}) }));
        return (((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, ctx.subsumers); (slop_list_types_Node){.data = (types_Node*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; })).len)) == 0);
    }
}

slop_string test_node_iri(types_Node n) {
    __auto_type _mv_1402 = n;
    switch (_mv_1402.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_1402.data.class_node;
            return i.value;
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_1402.data.individual_node;
            return i.value;
        }
        case types_Node_fresh_node:
        {
            __auto_type _ = _mv_1402.data.fresh_node;
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
    __auto_type _mv_1403 = ttl_parse_ttl_file(arena, path);
    if (!_mv_1403.is_ok) {
        __auto_type _ = _mv_1403.data.err;
        return (slop_option_types_Outcome){.has_value = false};
    } else if (_mv_1403.is_ok) {
        __auto_type g = _mv_1403.data.ok;
        __auto_type _mv_1404 = howl_classify(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), types_default_config());
        if (!_mv_1404.is_ok) {
            __auto_type _ = _mv_1404.data.err;
            return (slop_option_types_Outcome){.has_value = false};
        } else if (_mv_1404.is_ok) {
            __auto_type o = _mv_1404.data.ok;
            return (slop_option_types_Outcome){.has_value = 1, .value = o};
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_option_types_Outcome test_classify_fixture_with(slop_arena* arena, slop_string path, int64_t workers, int64_t cap) {
    {
        __auto_type cfg = types_default_config();
        cfg.worker_count = ((uint8_t)(SLOP_RANGE(uint8_t, workers, 1, 1, 1, 64, "(Int 1 .. 64) at test.slop:282:52")));
        cfg.max_iterations = ((uint16_t)(SLOP_RANGE(uint16_t, cap, 1, 1, 0, 10000, "(Int 0 .. 10000) at test.slop:283:57")));
        __auto_type _mv_1405 = ttl_parse_ttl_file(arena, path);
        if (!_mv_1405.is_ok) {
            __auto_type _ = _mv_1405.data.err;
            return (slop_option_types_Outcome){.has_value = false};
        } else if (_mv_1405.is_ok) {
            __auto_type g = _mv_1405.data.ok;
            __auto_type _mv_1406 = howl_classify(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), cfg);
            if (!_mv_1406.is_ok) {
                __auto_type _ = _mv_1406.data.err;
                return (slop_option_types_Outcome){.has_value = false};
            } else if (_mv_1406.is_ok) {
                __auto_type o = _mv_1406.data.ok;
                return (slop_option_types_Outcome){.has_value = 1, .value = o};
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_workers_agree(slop_arena* arena, slop_string path, int64_t cap) {
    __auto_type _mv_1407 = test_classify_fixture_with(arena, path, 1, cap);
    if (!_mv_1407.has_value) {
        return 0;
    } else if (_mv_1407.has_value) {
        __auto_type one = _mv_1407.value;
        __auto_type _mv_1408 = test_classify_fixture_with(arena, path, 4, cap);
        if (!_mv_1408.has_value) {
            return 0;
        } else if (_mv_1408.has_value) {
            __auto_type four = _mv_1408.value;
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
        ({ slop_map_put(NULL, s, &(m), NULL, 0); });
        if (succ) {
            ({ slop_map* _val = s; slop_map_put(NULL, c.succs, &(r), &_val, sizeof(_val)); });
        } else {
            ({ slop_map* _val = s; slop_map_put(NULL, c.preds, &(r), &_val, sizeof(_val)); });
        }
        return c;
    }
}

uint8_t test_queue_has(types_Saturation sat, types_Node n, types_Derived d) {
    __auto_type _mv_1412 = saturate_queue_of(sat, n);
    if (_mv_1412.has_value) {
        __auto_type q = _mv_1412.value;
        {
            uint8_t found = 0;
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
    } else if (!_mv_1412.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_stored_edge(types_Saturation sat, types_Node x, types_RoleId r, types_Node y) {
    return (({ __auto_type _mv = saturate_context_of(sat, x); _mv.has_value ? ({ __auto_type cx = _mv.value; ({ __auto_type _mv = ({ void* _ptr = slop_map_get(cx.succs, &(r)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; }); _mv.has_value ? ({ __auto_type s = _mv.value; slop_map_has(s, &(y)); }) : (0); }); }) : (0); }) && ({ __auto_type _mv = saturate_context_of(sat, y); _mv.has_value ? ({ __auto_type cy = _mv.value; ({ __auto_type _mv = ({ void* _ptr = slop_map_get(cy.preds, &(r)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; }); _mv.has_value ? ({ __auto_type s = _mv.value; slop_map_has(s, &(x)); }) : (0); }); }) : (0); }));
}

int64_t test_queue_len(types_Saturation sat, types_Node n) {
    __auto_type _mv_1417 = saturate_queue_of(sat, n);
    if (_mv_1417.has_value) {
        __auto_type q = _mv_1417.value;
        return ((int64_t)(((int64_t)((q.items).len))));
    } else if (!_mv_1417.has_value) {
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
        __auto_type ds = ((slop_list_saturate_RoundDelta){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type cas = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type qas = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ slop_map_put(NULL, ax.subsumers, &(p), NULL, 0); });
        ({ slop_map_put(NULL, bx.subsumers, &(p), NULL, 0); });
        ({ slop_map_put(NULL, bx.subsumers, &(q), NULL, 0); });
        ({ types_Context _val = ax; slop_map_put(NULL, a.pending, &(x), &_val, sizeof(_val)); });
        ({ types_Context _val = ay; slop_map_put(NULL, a.pending, &(y), &_val, sizeof(_val)); });
        ({ types_Context _val = bx; slop_map_put(NULL, b.pending, &(x), &_val, sizeof(_val)); });
        ({ types_Context _val = by; slop_map_put(NULL, b.pending, &(y), &_val, sizeof(_val)); });
        ({ __auto_type _lst_p = &(ds); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ds); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(cas); __auto_type _item = (c1); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(cas); __auto_type _item = (c2); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(qas); __auto_type _item = (q1); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(qas); __auto_type _item = (q2); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    __auto_type _mv_1427 = types_renamed_node(names, n);
    if (_mv_1427.has_value) {
        __auto_type r = _mv_1427.value;
        return types_node_eq(r, expect);
    } else if (!_mv_1427.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_litmus_end_to_end(slop_arena* arena) {
    {
        __auto_type parent = test_cls(SLOP_STR("http://example.org/t#Parent"));
        __auto_type mother = test_cls(SLOP_STR("http://example.org/t#Mother"));
        __auto_type _mv_1428 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl"));
        if (!_mv_1428.has_value) {
            return 0;
        } else if (_mv_1428.has_value) {
            __auto_type o = _mv_1428.value;
            return (((((int64_t)(((int64_t)((o.coverage.omitted).len)))) == 0)) && (classify_entails_sub(test_outcome_saturation(arena, o), o.names, o.findings.inconsistent, mother, parent)) && (({ __auto_type _mv = types_verdict(o); int _mi = (_mv == types_Verdict_verdict_coherent) ? 1 : 2; _mi == 1 ? (1) : (0); })));
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_role_hierarchy_carries_edges(slop_arena* arena) {
    __auto_type _mv_1429 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/probes/subproperty-existential.ttl"));
    if (!_mv_1429.has_value) {
        return 0;
    } else if (_mv_1429.has_value) {
        __auto_type o = _mv_1429.value;
        {
            __auto_type inc = o.findings.inconsistent;
            return (classify_entails_sub(test_outcome_saturation(arena, o), o.names, inc, test_cls(SLOP_STR("http://example.org/t#A")), test_cls(SLOP_STR("http://example.org/t#C"))) && !(classify_entails_sub(test_outcome_saturation(arena, o), o.names, inc, test_cls(SLOP_STR("http://example.org/t#E")), test_cls(SLOP_STR("http://example.org/t#F")))));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_role_closure_deep(slop_arena* arena) {
    __auto_type _mv_1430 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/role-hierarchy-deep.ttl"));
    if (!_mv_1430.has_value) {
        return 0;
    } else if (_mv_1430.has_value) {
        __auto_type o = _mv_1430.value;
        {
            __auto_type inc = o.findings.inconsistent;
            __auto_type sat = test_outcome_saturation(arena, o);
            __auto_type nm = o.names;
            return (((((int64_t)(((int64_t)((o.coverage.omitted).len)))) == 0)) && (classify_entails_sub(sat, nm, inc, test_cls(SLOP_STR("http://example.org/t#A1")), test_cls(SLOP_STR("http://example.org/t#C1")))) && (classify_entails_sub(sat, nm, inc, test_cls(SLOP_STR("http://example.org/t#A2")), test_cls(SLOP_STR("http://example.org/t#C2")))) && (classify_entails_sub(sat, nm, inc, test_cls(SLOP_STR("http://example.org/t#A3")), test_cls(SLOP_STR("http://example.org/t#C3")))) && (classify_entails_sub(sat, nm, inc, test_cls(SLOP_STR("http://example.org/t#D3")), test_cls(SLOP_STR("http://example.org/t#E3")))) && (classify_entails_sub(sat, nm, inc, test_cls(SLOP_STR("http://example.org/t#X4")), test_cls(SLOP_STR("http://example.org/t#E")))) && (classify_entails_sub(sat, nm, inc, test_cls(SLOP_STR("http://example.org/t#X5")), test_cls(SLOP_STR("http://example.org/t#E")))) && (classify_entails_sub(sat, nm, inc, test_cls(SLOP_STR("http://example.org/t#X6")), test_cls(SLOP_STR("http://example.org/t#F6")))) && (!(classify_entails_sub(sat, nm, inc, test_cls(SLOP_STR("http://example.org/t#A7")), test_cls(SLOP_STR("http://example.org/t#N7"))))));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_smaller_side_joins(slop_arena* arena) {
    __auto_type _mv_1431 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/smaller-side-join.ttl"));
    if (!_mv_1431.has_value) {
        return 0;
    } else if (_mv_1431.has_value) {
        __auto_type o = _mv_1431.value;
        {
            __auto_type inc = o.findings.inconsistent;
            return (((((int64_t)(((int64_t)((o.coverage.omitted).len)))) == 0)) && (classify_entails_sub(test_outcome_saturation(arena, o), o.names, inc, test_cls(SLOP_STR("http://example.org/t#X")), test_cls(SLOP_STR("http://example.org/t#E3")))) && (classify_entails_sub(test_outcome_saturation(arena, o), o.names, inc, test_cls(SLOP_STR("http://example.org/t#X2")), test_cls(SLOP_STR("http://example.org/t#H2")))));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_unattested_import_is_inconclusive(slop_arena* arena) {
    __auto_type _mv_1432 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/unattested-import.ttl"));
    if (!_mv_1432.has_value) {
        return 0;
    } else if (_mv_1432.has_value) {
        __auto_type o = _mv_1432.value;
        return ((((int64_t)(((int64_t)((o.coverage.omitted).len)))) > 0) && ({ __auto_type _mv = types_verdict(o); int _mi = (_mv == types_Verdict_verdict_inconclusive) ? 1 : 2; _mi == 1 ? (1) : (0); }));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_declared_unused_class_gets_a_context(slop_arena* arena) {
    {
        __auto_type unused = test_cls(SLOP_STR("http://example.org/t#Unused"));
        __auto_type _mv_1433 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/declared-unused-class.ttl"));
        if (!_mv_1433.has_value) {
            return 0;
        } else if (_mv_1433.has_value) {
            __auto_type o = _mv_1433.value;
            return (classify_entails_sub(test_outcome_saturation(arena, o), o.names, o.findings.inconsistent, unused, types_node_top()) && ({ __auto_type _mv = types_verdict(o); int _mi = (_mv == types_Verdict_verdict_coherent) ? 1 : 2; _mi == 1 ? (1) : (0); }));
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_abox_disjoint_range_is_incoherent(slop_arena* arena) {
    __auto_type _mv_1434 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/abox-disjoint-range.ttl"));
    if (!_mv_1434.has_value) {
        return 0;
    } else if (_mv_1434.has_value) {
        __auto_type o = _mv_1434.value;
        __auto_type _mv_1435 = types_verdict(o);
        if (_mv_1435 == types_Verdict_verdict_incoherent) {
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
    __auto_type _mv_1436 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/undeclared-individual.ttl"));
    if (!_mv_1436.has_value) {
        return 0;
    } else if (_mv_1436.has_value) {
        __auto_type o = _mv_1436.value;
        return (((test_omitted_count(o) == 0)) && (o.findings.inconsistent) && (({ __auto_type _mv = types_verdict(o); int _mi = (_mv == types_Verdict_verdict_incoherent) ? 1 : 2; _mi == 1 ? (1) : (0); })));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_anonymous_class_assertion_is_read(slop_arena* arena) {
    __auto_type _mv_1437 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/anonymous-class-assertion.ttl"));
    if (!_mv_1437.has_value) {
        return 0;
    } else if (_mv_1437.has_value) {
        __auto_type o = _mv_1437.value;
        return ((test_omitted_count(o) == 0) && o.findings.inconsistent);
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_annotation_on_annotation_is_consumed(slop_arena* arena) {
    {
        __auto_type path = SLOP_STR("corpus/fixtures/hazards/annotated-annotation.ttl");
        __auto_type src_pred = rdf_make_iri(arena, SLOP_STR("http://www.w3.org/2002/07/owl#annotatedSource"));
        return (({ __auto_type _mv = ttl_parse_ttl_file(arena, path); uint8_t _mr; if (_mv.is_ok) { __auto_type g = _mv.data.ok; _mr = ({ __auto_type _mv = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena })); uint8_t _mr; if (_mv.is_ok) { __auto_type s0 = _mv.data.ok; _mr = (((test_count_subclass_triples(g.triples, src_pred) == 1)) && ((test_count_subclass_triples(test_stage0_triples(arena, s0), src_pred) == 0)) && ((((int64_t)(((int64_t)((s0.omissions).len)))) == 0))); } else { __auto_type _ = _mv.data.err; _mr = 0; } _mr; }); } else { __auto_type _ = _mv.data.err; _mr = 0; } _mr; }) && ({ __auto_type _mv = test_classify_fixture(arena, path); _mv.has_value ? ({ __auto_type o = _mv.value; ((test_omitted_count(o) == 0) && ({ __auto_type _mv = types_verdict(o); int _mi = (_mv == types_Verdict_verdict_coherent) ? 1 : 2; _mi == 1 ? (1) : (0); })); }) : (0); }));
    }
}

uint8_t test_test_logical_triple_on_header_node_is_not_swallowed(slop_arena* arena) {
    __auto_type _mv_1438 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/logical-triple-on-header-node.ttl"));
    if (!_mv_1438.has_value) {
        return 0;
    } else if (_mv_1438.has_value) {
        __auto_type o = _mv_1438.value;
        return ((test_omitted_count(o) > 0) && ({ __auto_type _mv = types_verdict(o); int _mi = (_mv == types_Verdict_verdict_inconclusive) ? 1 : 2; _mi == 1 ? (1) : (0); }));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_repeated_disjoint_member_is_positional(slop_arena* arena) {
    {
        __auto_type a = ((rdf_IRI){.value = SLOP_STR("http://example.org/t#A")});
        __auto_type _mv_1439 = test_classify_fixture(arena, SLOP_STR("corpus/fixtures/hazards/disjoint-repeated-member.ttl"));
        if (!_mv_1439.has_value) {
            return 0;
        } else if (_mv_1439.has_value) {
            __auto_type o = _mv_1439.value;
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
    __auto_type _mv_1440 = test_classify_fixture(arena, path);
    if (!_mv_1440.has_value) {
        return 0;
    } else if (_mv_1440.has_value) {
        __auto_type o = _mv_1440.value;
        {
            __auto_type sat = test_outcome_saturation(arena, o);
            __auto_type names = o.names;
            __auto_type f = o.findings;
            uint8_t ok = 1;
            int64_t pairs = 0;
            {
                slop_map* _coll = (slop_map*)sat.contexts;
                for (size_t _i = 0; _i < _coll->len; _i++) {
                    {
                        types_Node ra = *(types_Node*)slop_map_key_at(_coll, _i);
                        types_Context actx = *(types_Context*)slop_map_value_at(_coll, _i);
                        {
                            __auto_type a = types_original_node(names, ra);
                            __auto_type _mv_1441 = a;
                            switch (_mv_1441.tag) {
                                case types_Node_class_node:
                                {
                                    __auto_type ai = _mv_1441.data.class_node;
                                    if (!(string_eq(ai.value, SLOP_STR("http://www.w3.org/2002/07/owl#Nothing")))) {
                                        {
                                            slop_map* _coll = (slop_map*)sat.contexts;
                                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                                {
                                                    types_Node rb = *(types_Node*)slop_map_key_at(_coll, _i);
                                                    types_Context bctx = *(types_Context*)slop_map_value_at(_coll, _i);
                                                    {
                                                        __auto_type b = types_original_node(names, rb);
                                                        __auto_type _mv_1442 = b;
                                                        switch (_mv_1442.tag) {
                                                            case types_Node_class_node:
                                                            {
                                                                __auto_type _ = _mv_1442.data.class_node;
                                                                pairs = (pairs + 1);
                                                                if (!((classify_entails_sub(sat, names, f.inconsistent, a, b) == test_report_entails(f, a, b)))) {
                                                                    ok = 0;
                                                                }
                                                                break;
                                                            }
                                                            case types_Node_individual_node:
                                                            {
                                                                __auto_type _ = _mv_1442.data.individual_node;
                                                                break;
                                                            }
                                                            case types_Node_fresh_node:
                                                            {
                                                                __auto_type _ = _mv_1442.data.fresh_node;
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
                                    __auto_type _ = _mv_1441.data.individual_node;
                                    break;
                                }
                                case types_Node_fresh_node:
                                {
                                    __auto_type _ = _mv_1441.data.fresh_node;
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
    return saturate_saturate(arena, saturate_make_initial_saturation(arena, signature), premise_build_rule_index(arena, axioms), types_default_config());
}

slop_list_types_Node test_litmus_signature(slop_arena* arena) {
    {
        __auto_type sig = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (test_cls(SLOP_STR("http://example.org/Person"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (test_cls(SLOP_STR("http://example.org/Parent"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (test_cls(SLOP_STR("http://example.org/Mother"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = 0 })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (correct_polarity) {
            ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = has_child, .f1 = person, .f2 = x } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else {
            ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = x, .f1 = has_child, .f2 = person } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_and, .data.sub_and = { .f0 = person, .f1 = x, .f2 = parent } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = parent, .f1 = person } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = parent, .f1 = has_child, .f2 = person } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = mother, .f1 = person } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = mother, .f1 = has_child, .f2 = person } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ax;
    }
}

uint8_t test_litmus_derives_parent(slop_arena* arena, uint8_t correct_polarity) {
    __auto_type _mv_1443 = test_run_fixture(arena, test_litmus_signature(arena), test_litmus_axioms(arena, correct_polarity));
    if (_mv_1443.is_ok) {
        __auto_type r = _mv_1443.data.ok;
        {
            __auto_type f = classify_extract_findings(arena, r.saturation, types_empty_names(arena));
            return classify_entails_sub(r.saturation, types_empty_names(arena), f.inconsistent, test_cls(SLOP_STR("http://example.org/Mother")), test_cls(SLOP_STR("http://example.org/Parent")));
        }
    } else if (!_mv_1443.is_ok) {
        __auto_type _ = _mv_1443.data.err;
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
        __auto_type sig = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = a, .f1 = b } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = b, .f1 = a } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_1444 = test_run_fixture(arena, sig, ax);
        if (_mv_1444.is_ok) {
            __auto_type r = _mv_1444.data.ok;
            __auto_type _mv_1445 = r.termination;
            switch (_mv_1445.tag) {
                case types_Termination_fixpoint:
                {
                    return 1;
                }
                case types_Termination_resource_limit:
                {
                    __auto_type _ = _mv_1445.data.resource_limit;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_1444.is_ok) {
            __auto_type _ = _mv_1444.data.err;
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
        __auto_type sig = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (h); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = e, .f1 = r, .f2 = f } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = f, .f1 = g } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = r, .f1 = g, .f2 = h } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_1446 = test_run_fixture(arena, sig, ax);
        if (_mv_1446.is_ok) {
            __auto_type res = _mv_1446.data.ok;
            {
                __auto_type fi = classify_extract_findings(arena, res.saturation, types_empty_names(arena));
                return classify_entails_sub(res.saturation, types_empty_names(arena), fi.inconsistent, e, h);
            }
        } else if (!_mv_1446.is_ok) {
            __auto_type _ = _mv_1446.data.err;
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
        __auto_type sig = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (f1); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (h); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = e, .f1 = r, .f2 = f } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = f, .f1 = f1 } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = f1, .f1 = g } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = r, .f1 = g, .f2 = h } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_1447 = test_run_fixture(arena, sig, ax);
        if (_mv_1447.is_ok) {
            __auto_type res = _mv_1447.data.ok;
            {
                __auto_type fi = classify_extract_findings(arena, res.saturation, types_empty_names(arena));
                return classify_entails_sub(res.saturation, types_empty_names(arena), fi.inconsistent, e, h);
            }
        } else if (!_mv_1447.is_ok) {
            __auto_type _ = _mv_1447.data.err;
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
        __auto_type sig = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = a, .f1 = b } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = a, .f1 = c } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_and, .data.sub_and = { .f0 = b, .f1 = c, .f2 = types_node_bottom() } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return test_run_fixture(arena, sig, ax);
    }
}

uint8_t test_test_unsatisfiable_class_detected(slop_arena* arena) {
    __auto_type _mv_1448 = test_unsat_fixture(arena);
    if (_mv_1448.is_ok) {
        __auto_type r = _mv_1448.data.ok;
        {
            __auto_type f = classify_extract_findings(arena, r.saturation, types_empty_names(arena));
            if (((int64_t)((f.unsatisfiable).len)) == 1) {
                return types_findings_are_incoherent(f);
            } else {
                return 0;
            }
        }
    } else if (!_mv_1448.is_ok) {
        __auto_type _ = _mv_1448.data.err;
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_bottom_compression(slop_arena* arena) {
    __auto_type _mv_1449 = test_unsat_fixture(arena);
    if (_mv_1449.is_ok) {
        __auto_type r = _mv_1449.data.ok;
        {
            __auto_type a = test_cls(SLOP_STR("http://example.org/A"));
            __auto_type b = test_cls(SLOP_STR("http://example.org/B"));
            __auto_type f = classify_extract_findings(arena, r.saturation, types_empty_names(arena));
            int64_t pairs_about_a = 0;
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
    } else if (!_mv_1449.is_ok) {
        __auto_type _ = _mv_1449.data.err;
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_inconsistency_suppresses_both_lists(slop_arena* arena) {
    {
        __auto_type a = test_cls(SLOP_STR("http://example.org/A"));
        __auto_type sig = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = types_node_top(), .f1 = types_node_bottom() } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_1450 = test_run_fixture(arena, sig, ax);
        if (_mv_1450.is_ok) {
            __auto_type r = _mv_1450.data.ok;
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
        } else if (!_mv_1450.is_ok) {
            __auto_type _ = _mv_1450.data.err;
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
        __auto_type fwd = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type rev = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(fwd); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(fwd); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(fwd); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(rev); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(rev); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(rev); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = a, .f1 = b } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = b, .f1 = c } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_1451 = test_run_fixture(arena, fwd, ax);
        if (_mv_1451.is_ok) {
            __auto_type r1 = _mv_1451.data.ok;
            __auto_type _mv_1452 = test_run_fixture(arena, rev, ax);
            if (_mv_1452.is_ok) {
                __auto_type r2 = _mv_1452.data.ok;
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
            } else if (!_mv_1452.is_ok) {
                __auto_type _ = _mv_1452.data.err;
                return 0;
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_1451.is_ok) {
            __auto_type _ = _mv_1451.data.err;
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
        __auto_type a = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type b = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(a); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/zebra"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(a); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/apple"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(a); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/apple2"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(a); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/mango"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(b); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/mango"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(b); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/apple2"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(b); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/zebra"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(b); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/apple"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    __auto_type _mv_1453 = ttl_parse_ttl_file(arena, SLOP_STR("corpus/fixtures/hazards/unattested-import.ttl"));
    if (!_mv_1453.is_ok) {
        __auto_type _ = _mv_1453.data.err;
        return 0;
    } else if (_mv_1453.is_ok) {
        __auto_type g = _mv_1453.data.ok;
        __auto_type _mv_1454 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        if (!_mv_1454.is_ok) {
            __auto_type _ = _mv_1454.data.err;
            return 0;
        } else if (_mv_1454.is_ok) {
            __auto_type s0 = _mv_1454.data.ok;
            return ((((int64_t)(((int64_t)((s0.imports_declared).len)))) == 1) && (((int64_t)(((int64_t)((s0.omissions).len)))) == 1));
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_attested_import_yields_none(slop_arena* arena) {
    __auto_type _mv_1455 = ttl_parse_ttl_file(arena, SLOP_STR("corpus/fixtures/hazards/unattested-import.ttl"));
    if (!_mv_1455.is_ok) {
        __auto_type _ = _mv_1455.data.err;
        return 0;
    } else if (_mv_1455.is_ok) {
        __auto_type g = _mv_1455.data.ok;
        {
            __auto_type resolved = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            ({ __auto_type _lst_p = &(resolved); __auto_type _item = (((rdf_IRI){.value = SLOP_STR("http://example.org/does-not-exist")})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            __auto_type _mv_1456 = decode_stage0_header(arena, g.triples, resolved);
            if (!_mv_1456.is_ok) {
                __auto_type _ = _mv_1456.data.err;
                return 0;
            } else if (_mv_1456.is_ok) {
                __auto_type s0 = _mv_1456.data.ok;
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
        __auto_type _mv_1457 = ttl_parse_ttl_string(arena, ttl);
        if (!_mv_1457.is_ok) {
            __auto_type _ = _mv_1457.data.err;
            return 0;
        } else if (_mv_1457.is_ok) {
            __auto_type g = _mv_1457.data.ok;
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
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, q1, p, o)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, n1, p, o)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, a, p, en)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type st = termstore_build_store(arena, ts);
            return (((((int64_t)(((int64_t)((termstore_store_objects(arena, st, q2, p)).len)))) == 1)) && (termstore_store_has_any(st, n2, p)) && (termstore_store_contains(st, rdf_make_triple(arena, a, p, en2))) && (!(termstore_store_contains(st, rdf_make_triple(arena, a, p, fr)))) && (!(termstore_store_contains(st, rdf_make_triple(arena, a, p, plain)))));
        }
    }
}

slop_list_rdf_Triple test_stage0_triples(slop_arena* arena, decode_Stage0 s0) {
    {
        __auto_type out = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = s0.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (termstore_triple_of(s0.dict, it)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_string test_decode_rendered(slop_arena* arena, slop_result_decode_Stage1_types_Fault r) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1458 = r;
        if (_mv_1458.is_ok) {
            __auto_type s1 = _mv_1458.data.ok;
            {
                __auto_type _coll = s1.axioms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ax = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (owl2_render_axiom(arena, ax)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        } else if (!_mv_1458.is_ok) {
            __auto_type f = _mv_1458.data.err;
            __auto_type _mv_1459 = f;
            switch (_mv_1459.tag) {
                case types_Fault_input_error:
                {
                    __auto_type m = _mv_1459.data.input_error;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    break;
                }
                case types_Fault_refused:
                {
                    __auto_type _ = _mv_1459.data.refused;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (SLOP_STR("refused")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    break;
                }
                case types_Fault_cancelled:
                {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (SLOP_STR("cancelled")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    break;
                }
                case types_Fault_unavailable:
                {
                    __auto_type _ = _mv_1459.data.unavailable;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (SLOP_STR("unavailable")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    break;
                }
            }
        }
        return out;
    }
}

uint8_t test_decode_store_agrees(slop_arena* arena, slop_string path) {
    __auto_type _mv_1460 = ttl_parse_ttl_file(arena, path);
    if (!_mv_1460.is_ok) {
        __auto_type _ = _mv_1460.data.err;
        return 0;
    } else if (_mv_1460.is_ok) {
        __auto_type g = _mv_1460.data.ok;
        __auto_type _mv_1461 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        if (!_mv_1461.is_ok) {
            __auto_type _ = _mv_1461.data.err;
            return 0;
        } else if (_mv_1461.is_ok) {
            __auto_type s0 = _mv_1461.data.ok;
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
                    uint8_t same = (((int64_t)((a).len)) == ((int64_t)((b).len)));
                    int64_t i = 0;
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
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/litmus.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/intersection.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-lhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/abox-assertions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/cardinality.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/complement.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/union.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/nominals.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/el++/has-self.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/inverse-expressions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/el++/equality.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/allvalues.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/datatypes.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/annotation-heavy.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    __auto_type _mv_1462 = decode_stage0_header(arena, ts, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
    if (_mv_1462.is_ok) {
        __auto_type _ = _mv_1462.data.ok;
        return SLOP_STR("");
    } else if (!_mv_1462.is_ok) {
        __auto_type f = _mv_1462.data.err;
        __auto_type _mv_1463 = f;
        switch (_mv_1463.tag) {
            case types_Fault_input_error:
            {
                __auto_type m = _mv_1463.data.input_error;
                return m;
            }
            case types_Fault_refused:
            {
                __auto_type _ = _mv_1463.data.refused;
                return SLOP_STR("refused");
            }
            case types_Fault_cancelled:
            {
                return SLOP_STR("cancelled");
            }
            case types_Fault_unavailable:
            {
                __auto_type _ = _mv_1463.data.unavailable;
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
        __auto_type _mv_1464 = ttl_parse_ttl_string(arena, ttl);
        if (!_mv_1464.is_ok) {
            __auto_type _ = _mv_1464.data.err;
            return 0;
        } else if (_mv_1464.is_ok) {
            __auto_type g = _mv_1464.data.ok;
            return ((canon_string_cmp(test_stage0_fault_of(arena, g.triples), SLOP_STR("owl:Axiom node without a usable owl:annotatedTarget")) == 0) && (canon_string_cmp(test_stage0_fault_of(arena, test_reversed_triples(arena, g.triples)), SLOP_STR("owl:Axiom node without a usable owl:annotatedSource")) == 0));
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_stage0_rebuild_checks_the_whole_input(slop_arena* arena) {
    {
        __auto_type ttl = SLOP_STR("@prefix owl: <http://www.w3.org/2002/07/owl#> .\n@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n<http://example.org/t> a owl:Ontology ; rdfs:comment \"c\" .\n_:x a owl:Axiom ; owl:annotatedSource <http://example.org/t> ; owl:annotatedProperty rdfs:comment ; owl:annotatedTarget \"c\" .\n");
        __auto_type _mv_1465 = ttl_parse_ttl_string(arena, ttl);
        if (!_mv_1465.is_ok) {
            __auto_type _ = _mv_1465.data.err;
            return 0;
        } else if (_mv_1465.is_ok) {
            __auto_type g = _mv_1465.data.ok;
            __auto_type _mv_1466 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
            if (!_mv_1466.is_ok) {
                __auto_type _ = _mv_1466.data.err;
                return 0;
            } else if (_mv_1466.is_ok) {
                __auto_type s0 = _mv_1466.data.ok;
                return (((int64_t)(((int64_t)((s0.triples).len)))) == 0);
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_header_and_reification_are_consumed(slop_arena* arena) {
    __auto_type _mv_1467 = ttl_parse_ttl_file(arena, SLOP_STR("corpus/fixtures/hazards/annotation-heavy.ttl"));
    if (!_mv_1467.is_ok) {
        __auto_type _ = _mv_1467.data.err;
        return 0;
    } else if (_mv_1467.is_ok) {
        __auto_type g = _mv_1467.data.ok;
        __auto_type _mv_1468 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        if (!_mv_1468.is_ok) {
            __auto_type _ = _mv_1468.data.err;
            return 0;
        } else if (_mv_1468.is_ok) {
            __auto_type s0 = _mv_1468.data.ok;
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
                __auto_type _mv_1469 = owl2_disposition(types_Profile_profile_el, a);
                if (_mv_1469 == owl2_Disposition_d_out_of_profile) {
                    n = (n + 1);
                } else if (_mv_1469 == owl2_Disposition_d_in_profile) {
                    if (!(owl2_axiom_in_profile(types_Profile_profile_el, a))) {
                        n = (n + 1);
                    }
                } else if (_mv_1469 == owl2_Disposition_d_inert) {
                } else if (_mv_1469 == owl2_Disposition_d_consumed) {
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
    __auto_type _mv_1470 = ttl_parse_ttl_file(arena, path);
    if (!_mv_1470.is_ok) {
        __auto_type _ = _mv_1470.data.err;
        return (slop_option_decode_Stage1){.has_value = false};
    } else if (_mv_1470.is_ok) {
        __auto_type g = _mv_1470.data.ok;
        __auto_type _mv_1471 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        if (!_mv_1471.is_ok) {
            __auto_type _ = _mv_1471.data.err;
            return (slop_option_decode_Stage1){.has_value = false};
        } else if (_mv_1471.is_ok) {
            __auto_type s0 = _mv_1471.data.ok;
            __auto_type _mv_1472 = decode_decode_axioms(arena, s0.dict, s0.triples);
            if (!_mv_1472.is_ok) {
                __auto_type _ = _mv_1472.data.err;
                return (slop_option_decode_Stage1){.has_value = false};
            } else if (_mv_1472.is_ok) {
                __auto_type s1 = _mv_1472.data.ok;
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
                __auto_type _mv_1473 = a;
                switch (_mv_1473.tag) {
                    case owl2_RawAxiom_ra_disjoint_classes:
                    {
                        __auto_type cs = _mv_1473.data.ra_disjoint_classes;
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
    __auto_type _mv_1474 = test_decode_fixture(arena, SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl"));
    if (!_mv_1474.has_value) {
        return 0;
    } else if (_mv_1474.has_value) {
        __auto_type s1 = _mv_1474.value;
        return ((test_nary_disjoint_member_count(s1.axioms) == 3) && (test_count_out_of_profile(s1.axioms) == 0));
    }
    SLOP_UNREACHABLE();
}

int64_t test_out_of_profile_count_of(slop_arena* arena, slop_string path) {
    __auto_type _mv_1475 = test_decode_fixture(arena, path);
    if (!_mv_1475.has_value) {
        return -1;
    } else if (_mv_1475.has_value) {
        __auto_type s1 = _mv_1475.value;
        return test_count_out_of_profile(s1.axioms);
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_v0_corpus_decodes_clean(slop_arena* arena) {
    {
        __auto_type paths = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t ok = 1;
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subclass-atomic.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/intersection.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-lhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-rhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-classes.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-properties.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-binary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subproperty.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/transitive.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/domain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/abox-assertions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/top-bottom.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/litmus.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        __auto_type paths = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t ok = 1;
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/union.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/complement.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/allvalues.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/nominals.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/cardinality.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/el++/has-self.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/inverse.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/el++/equality.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/property-characteristics.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/haskey-disjointunion.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/swrl-rule.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/el++/builtin-roles.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/anonymous-individual.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/datatypes.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/inverse-expressions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    __auto_type _mv_1476 = test_decode_fixture(arena, SLOP_STR("corpus/fixtures/hazards/annotation-heavy.ttl"));
    if (!_mv_1476.has_value) {
        return 0;
    } else if (_mv_1476.has_value) {
        __auto_type s1 = _mv_1476.value;
        {
            __auto_type axs = s1.axioms;
            return (((test_count_out_of_profile(axs) == 0)) && ((test_count_disposition(axs, owl2_Disposition_d_in_profile) > 0)) && ((s1.inert > 0)) && ((test_count_disposition(axs, owl2_Disposition_d_consumed) > 0)));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_litmus_decodes_clean(slop_arena* arena) {
    __auto_type _mv_1477 = test_decode_fixture(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl"));
    if (!_mv_1477.has_value) {
        return 0;
    } else if (_mv_1477.has_value) {
        __auto_type s1 = _mv_1477.value;
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

slop_string test_cites_lines(slop_arena* arena, slop_list_types_AxiomRef refs) {
    {
        __auto_type out = SLOP_STR("");
        {
            __auto_type _coll = refs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                out = string_concat(arena, out, string_concat(arena, r.text, SLOP_STR("\n")));
            }
        }
        return out;
    }
}

slop_string test_cited_text(slop_arena* arena, gate_GateResult gr, slop_string iri) {
    {
        __auto_type out = SLOP_STR("none");
        {
            __auto_type _coll = gr.omissions;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                __auto_type _mv_1478 = o;
                switch (_mv_1478.tag) {
                    case types_Omission_missing_declaration:
                    {
                        __auto_type md = _mv_1478.data.missing_declaration;
                        if (string_eq(md.entity.value, iri)) {
                            out = test_cites_lines(arena, md.referring);
                        }
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        return out;
    }
}

uint8_t test_test_missing_declaration_cites_its_axioms(slop_arena* arena) {
    {
        __auto_type pre = SLOP_STR("@prefix : <http://example.org/t#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n:A a owl:Class . :B a owl:Class .\n");
        __auto_type _mv_1479 = test_gate_ttl(arena, string_concat(arena, pre, SLOP_STR(":A rdfs:subClassOf :D . :B rdfs:subClassOf :D . :A rdfs:subClassOf :E . :A rdfs:subClassOf :B .")));
        if (!_mv_1479.has_value) {
            return 0;
        } else if (_mv_1479.has_value) {
            __auto_type gr = _mv_1479.value;
            return ((string_eq(test_cited_text(arena, gr, SLOP_STR("http://example.org/t#D")), SLOP_STR("SubClassOf(http://example.org/t#A http://example.org/t#D)\nSubClassOf(http://example.org/t#B http://example.org/t#D)\n"))) && (string_eq(test_cited_text(arena, gr, SLOP_STR("http://example.org/t#E")), SLOP_STR("SubClassOf(http://example.org/t#A http://example.org/t#E)\n"))) && (string_eq(test_cited_text(arena, gr, SLOP_STR("http://example.org/t#B")), SLOP_STR("none"))));
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_undeclared_individual_is_not_reported(slop_arena* arena) {
    {
        __auto_type ttl = SLOP_STR("@prefix : <http://example.org/t#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n:A a owl:Class . :p a owl:ObjectProperty .\n:a a :A . :a :p :b .\n");
        return (test_gate_omissions_of_ttl(arena, ttl) == 0);
    }
}

int64_t test_accepted_count_of_ttl(slop_arena* arena, slop_string ttl) {
    __auto_type _mv_1480 = ttl_parse_ttl_string(arena, ttl);
    if (!_mv_1480.is_ok) {
        __auto_type _ = _mv_1480.data.err;
        return -1;
    } else if (_mv_1480.is_ok) {
        __auto_type g = _mv_1480.data.ok;
        __auto_type _mv_1481 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        if (!_mv_1481.is_ok) {
            __auto_type _ = _mv_1481.data.err;
            return -1;
        } else if (_mv_1481.is_ok) {
            __auto_type s0 = _mv_1481.data.ok;
            __auto_type _mv_1482 = decode_decode_axioms(arena, s0.dict, s0.triples);
            if (!_mv_1482.is_ok) {
                __auto_type _ = _mv_1482.data.err;
                return -1;
            } else if (_mv_1482.is_ok) {
                __auto_type s1 = _mv_1482.data.ok;
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
    __auto_type _mv_1483 = ttl_parse_ttl_string(arena, ttl);
    if (!_mv_1483.is_ok) {
        __auto_type _ = _mv_1483.data.err;
        return 0;
    } else if (_mv_1483.is_ok) {
        __auto_type g = _mv_1483.data.ok;
        __auto_type _mv_1484 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        if (!_mv_1484.is_ok) {
            __auto_type _ = _mv_1484.data.err;
            return 0;
        } else if (_mv_1484.is_ok) {
            __auto_type s0 = _mv_1484.data.ok;
            __auto_type _mv_1485 = decode_decode_axioms(arena, s0.dict, s0.triples);
            if (!_mv_1485.is_ok) {
                __auto_type _ = _mv_1485.data.err;
                return 0;
            } else if (_mv_1485.is_ok) {
                __auto_type _ = _mv_1485.data.ok;
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
    __auto_type _mv_1486 = ttl_parse_ttl_string(arena, ttl);
    if (!_mv_1486.is_ok) {
        __auto_type _ = _mv_1486.data.err;
        return (slop_option_gate_GateResult){.has_value = false};
    } else if (_mv_1486.is_ok) {
        __auto_type g = _mv_1486.data.ok;
        __auto_type _mv_1487 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        if (!_mv_1487.is_ok) {
            __auto_type _ = _mv_1487.data.err;
            return (slop_option_gate_GateResult){.has_value = false};
        } else if (_mv_1487.is_ok) {
            __auto_type s0 = _mv_1487.data.ok;
            __auto_type _mv_1488 = decode_decode_axioms(arena, s0.dict, s0.triples);
            if (!_mv_1488.is_ok) {
                __auto_type _ = _mv_1488.data.err;
                return (slop_option_gate_GateResult){.has_value = false};
            } else if (_mv_1488.is_ok) {
                __auto_type s1 = _mv_1488.data.ok;
                return (slop_option_gate_GateResult){.has_value = 1, .value = gate_gate_axioms(arena, s1.axioms, s1.signature, s0.omissions, p)};
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

int64_t test_gate_omissions_of_ttl(slop_arena* arena, slop_string ttl) {
    __auto_type _mv_1489 = test_gate_ttl(arena, ttl);
    if (!_mv_1489.has_value) {
        return -1;
    } else if (_mv_1489.has_value) {
        __auto_type gr = _mv_1489.value;
        return ((int64_t)(((int64_t)((gr.omissions).len))));
    }
    SLOP_UNREACHABLE();
}

slop_string test_gate_accepted_of_ttl(slop_arena* arena, slop_string ttl) {
    __auto_type _mv_1490 = test_gate_ttl(arena, ttl);
    if (!_mv_1490.has_value) {
        return SLOP_STR("<did not gate>");
    } else if (_mv_1490.has_value) {
        __auto_type gr = _mv_1490.value;
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
    __auto_type _mv_1491 = test_gate_ttl_in(arena, ttl, p);
    if (!_mv_1491.has_value) {
        return -1;
    } else if (_mv_1491.has_value) {
        __auto_type gr = _mv_1491.value;
        return ((int64_t)(((int64_t)((gr.omissions).len))));
    }
    SLOP_UNREACHABLE();
}

int64_t test_accepted_under(slop_arena* arena, slop_string ttl, types_Profile p) {
    __auto_type _mv_1492 = test_gate_ttl_in(arena, ttl, p);
    if (!_mv_1492.has_value) {
        return -1;
    } else if (_mv_1492.has_value) {
        __auto_type gr = _mv_1492.value;
        return ((int64_t)(((int64_t)((gr.accepted).len))));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_gate_alike_under(slop_arena* arena, slop_string label, slop_string a, slop_string b, types_Profile p) {
    {
        __auto_type ka = test_accepted_under(arena, a, p);
        __auto_type kb = test_accepted_under(arena, b, p);
        __auto_type oa = test_omissions_under(arena, a, p);
        __auto_type ob = test_omissions_under(arena, b, p);
        if ((ka >= 0) && ((ka == kb) && (oa == ob))) {
            return 1;
        } else {
            printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [rungs] "), label)).len, (string_concat(arena, SLOP_STR("  [rungs] "), label)).data);
            printf("%s", "    kept ");
            printf("%.*s", (int)(int_to_string(arena, ka)).len, (int_to_string(arena, ka)).data);
            printf("%s", " vs ");
            printf("%.*s\n", (int)(int_to_string(arena, kb)).len, (int_to_string(arena, kb)).data);
            printf("%s", "    omitted ");
            printf("%.*s", (int)(int_to_string(arena, oa)).len, (int_to_string(arena, oa)).data);
            printf("%s", " vs ");
            printf("%.*s\n", (int)(int_to_string(arena, ob)).len, (int_to_string(arena, ob)).data);
            return 0;
        }
    }
}

uint8_t test_rungs_gate_alike(slop_arena* arena, slop_string label, slop_string ttl_a, slop_string ttl_b) {
    {
        __auto_type a = string_concat(arena, test_rung_prefix(), ttl_a);
        __auto_type b = string_concat(arena, test_rung_prefix(), ttl_b);
        return (test_gate_alike_under(arena, label, a, b, types_Profile_profile_el) && test_gate_alike_under(arena, label, a, b, types_Profile_profile_el_plus_plus));
    }
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

uint8_t test_test_data_lemma(slop_arena* arena) {
    return ((test_rungs_omit(arena, SLOP_STR("idle: domain, range, functionality"), SLOP_STR(":d a owl:DatatypeProperty , owl:FunctionalProperty ; rdfs:domain :C ; rdfs:range <http://www.w3.org/2001/XMLSchema#integer> ."), 0, 0)) && (test_rungs_omit(arena, SLOP_STR("idle: sub-property, equivalence, disjointness"), SLOP_STR(":d a owl:DatatypeProperty . :e a owl:DatatypeProperty . :f a owl:DatatypeProperty .\n:d rdfs:subPropertyOf :e ; owl:equivalentProperty :f . :e owl:propertyDisjointWith :f ."), 0, 0)) && (test_rungs_omit(arena, SLOP_STR("used in an assertion: domain and assertion omitted"), SLOP_STR(":d a owl:DatatypeProperty ; rdfs:domain :C . :a :d 1 ."), 2, 2)) && (test_rungs_omit(arena, SLOP_STR("used below: the super-property is not idle"), SLOP_STR(":p a owl:DatatypeProperty ; rdfs:domain :C .\n:q a owl:DatatypeProperty ; rdfs:subPropertyOf :p . :a :q 1 ."), 3, 3)) && (test_rungs_omit(arena, SLOP_STR("used in a restriction: the range stays"), SLOP_STR(":d a owl:DatatypeProperty ; rdfs:range <http://www.w3.org/2001/XMLSchema#integer> .\n:C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :d ; owl:someValuesFrom <http://www.w3.org/2001/XMLSchema#integer> ] ."), 2, 2)) && (test_rungs_omit(arena, SLOP_STR("disjointness: an idle member suffices, two used ones do not"), SLOP_STR(":u a owl:DatatypeProperty . :v a owl:DatatypeProperty . :i a owl:DatatypeProperty .\n:u owl:propertyDisjointWith :i . :u owl:propertyDisjointWith :v . :a :u 1 ; :v 2 ."), 3, 3)) && (test_rungs_omit(arena, SLOP_STR("a DatatypeRestriction range goes with its axiom"), SLOP_STR(":d a owl:DatatypeProperty ; rdfs:range [ a <http://www.w3.org/2000/01/rdf-schema#Datatype> ; owl:onDatatype <http://www.w3.org/2001/XMLSchema#short> ; owl:withRestrictions ( [ <http://www.w3.org/2001/XMLSchema#minInclusive> 0 ] ) ] ."), 0, 0)) && (test_rungs_omit(arena, SLOP_STR("a sub-property of owl:topDataProperty is a tautology"), SLOP_STR(":d a owl:DatatypeProperty ; rdfs:subPropertyOf owl:topDataProperty ."), 0, 0)) && (test_rungs_omit(arena, SLOP_STR("a domain on owl:topDataProperty stays"), SLOP_STR("owl:topDataProperty rdfs:domain :C ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("a declared owl:topDataProperty is still never idle"), SLOP_STR("owl:topDataProperty a owl:DatatypeProperty ; rdfs:domain :C ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("a disjointness with owl:topDataProperty stays"), SLOP_STR(":d a owl:DatatypeProperty ; owl:propertyDisjointWith owl:topDataProperty ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("an axiom annotation is not a use (RO annotates RO_0002029's range)"), SLOP_STR(":d a owl:DatatypeProperty ; rdfs:range <http://www.w3.org/2001/XMLSchema#integer> .\n[ a owl:Axiom ; owl:annotatedSource :d ; owl:annotatedProperty rdfs:range ; owl:annotatedTarget <http://www.w3.org/2001/XMLSchema#integer> ; rdfs:comment \"why\" ] ."), 0, 0)) && (test_rungs_omit(arena, SLOP_STR("a filler shared with its own reification still goes with its axiom"), SLOP_STR(":d a owl:DatatypeProperty ; rdfs:range _:x .\n_:x a <http://www.w3.org/2000/01/rdf-schema#Datatype> ; owl:onDatatype <http://www.w3.org/2001/XMLSchema#short> ; owl:withRestrictions ( [ <http://www.w3.org/2001/XMLSchema#minInclusive> 0 ] ) .\n[ a owl:Axiom ; owl:annotatedSource :d ; owl:annotatedProperty rdfs:range ; owl:annotatedTarget _:x ; rdfs:comment \"why\" ] ."), 0, 0)) && (test_rungs_omit(arena, SLOP_STR("a reified-only assertion is a use: it is rebuilt before the lemma"), SLOP_STR(":d a owl:DatatypeProperty ; rdfs:domain :C .\n[ a owl:Axiom ; owl:annotatedSource :a ; owl:annotatedProperty :d ; owl:annotatedTarget \"x\" ] ."), 2, 2)) && (test_rungs_omit(arena, SLOP_STR("owl:withRestrictions without owl:onDatatype is not swallowed"), SLOP_STR(":d a owl:DatatypeProperty ; rdfs:domain _:x .\n_:x a owl:Class ; owl:withRestrictions ( [ <http://www.w3.org/2001/XMLSchema#minInclusive> 0 ] ) ."), 2, 2)) && (test_rungs_omit(arena, SLOP_STR("a facet node with a second triple is not swallowed"), SLOP_STR(":d a owl:DatatypeProperty ; rdfs:range [ a <http://www.w3.org/2000/01/rdf-schema#Datatype> ; owl:onDatatype <http://www.w3.org/2001/XMLSchema#short> ; owl:withRestrictions ( [ <http://www.w3.org/2001/XMLSchema#minInclusive> 0 ; owl:someValuesFrom :C ] ) ] ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("a reified-only declaration declares: stage 0 rebuilds it"), SLOP_STR("[ a owl:Axiom ; owl:annotatedSource :d ; owl:annotatedProperty <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> ; owl:annotatedTarget owl:DatatypeProperty ] .\n:d rdfs:range <http://www.w3.org/2001/XMLSchema#integer> ."), 0, 0)) && (test_rungs_gate_alike(arena, SLOP_STR("a filler that heads an axiom keeps it"), SLOP_STR(":d a owl:DatatypeProperty ; rdfs:domain _:x .\n_:x owl:intersectionOf ( :C :D ) ; rdfs:subClassOf owl:Nothing ."), SLOP_STR(":d a owl:DatatypeProperty .\n[ owl:intersectionOf ( :C :D ) ] rdfs:subClassOf owl:Nothing ."))));
}

slop_string test_inv_decls(void) {
    return SLOP_STR("@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n:p a owl:ObjectProperty . :q a owl:ObjectProperty . :s a owl:ObjectProperty .\n:A a owl:Class . :B a owl:Class . :C a owl:Class .\n:d a owl:DatatypeProperty . :e a owl:DatatypeProperty .\n");
}

uint8_t test_test_inverses_decode_whole(slop_arena* arena) {
    return ((test_omits_exactly(arena, SLOP_STR("an inverse sub-property"), string_concat(arena, test_inv_decls(), SLOP_STR(":q rdfs:subPropertyOf [ owl:inverseOf :p ] .")), SLOP_STR("SubObjectPropertyOf(http://example.org/t#q ObjectInverseOf(http://example.org/t#p))\n"))) && (test_omits_exactly(arena, SLOP_STR("an inverse chain step"), string_concat(arena, test_inv_decls(), SLOP_STR(":s owl:propertyChainAxiom ( [ owl:inverseOf :p ] :q ) .")), SLOP_STR("SubObjectPropertyOf(ObjectPropertyChain(ObjectInverseOf(http://example.org/t#p) http://example.org/t#q) http://example.org/t#s)\n"))) && (test_omits_exactly(arena, SLOP_STR("two restrictions on inverses stay apart"), string_concat(arena, test_inv_decls(), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty [ owl:inverseOf :p ] ; owl:someValuesFrom :B ] .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty [ owl:inverseOf :q ] ; owl:allValuesFrom :C ] .")), SLOP_STR("SubClassOf(http://example.org/t#A ObjectAllValuesFrom(ObjectInverseOf(http://example.org/t#q) http://example.org/t#C))\nSubClassOf(http://example.org/t#A ObjectSomeValuesFrom(ObjectInverseOf(http://example.org/t#p) http://example.org/t#B))\n"))) && (test_omits_exactly(arena, SLOP_STR("an inverse's domain"), string_concat(arena, test_inv_decls(), SLOP_STR("[ owl:inverseOf :p ] rdfs:domain :A .")), SLOP_STR("ObjectPropertyDomain(ObjectInverseOf(http://example.org/t#p) http://example.org/t#A)\n"))) && (test_omits_exactly(arena, SLOP_STR("an inverse's characteristic"), string_concat(arena, test_inv_decls(), SLOP_STR("[ owl:inverseOf :q ] a owl:FunctionalProperty .")), SLOP_STR("FunctionalObjectProperty(ObjectInverseOf(http://example.org/t#q))\n"))) && (test_omits_exactly(arena, SLOP_STR("an inverse of an inverse expression"), string_concat(arena, test_inv_decls(), SLOP_STR(":p owl:inverseOf [ owl:inverseOf :q ] .")), SLOP_STR("InverseObjectProperties(http://example.org/t#p ObjectInverseOf(http://example.org/t#q))\n"))) && (test_omits_exactly(arena, SLOP_STR("a negative assertion on an inverse"), string_concat(arena, test_inv_decls(), SLOP_STR("[ a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; owl:assertionProperty [ owl:inverseOf :p ] ; owl:targetIndividual :b ] .")), SLOP_STR("NegativeObjectPropertyAssertion(ObjectInverseOf(http://example.org/t#p) http://example.org/t#a http://example.org/t#b)\n"))) && (test_omits_exactly(arena, SLOP_STR("disjoint properties with an inverse member"), string_concat(arena, test_inv_decls(), SLOP_STR("[ a owl:AllDisjointProperties ; owl:members ( :p [ owl:inverseOf :q ] ) ] .")), SLOP_STR("DisjointObjectProperties(http://example.org/t#p ObjectInverseOf(http://example.org/t#q))\n"))) && (test_omits_exactly(arena, SLOP_STR("a disjoint union, read whole"), string_concat(arena, test_inv_decls(), SLOP_STR(":C owl:disjointUnionOf ( :A :B ) .")), SLOP_STR("DisjointUnion(http://example.org/t#C http://example.org/t#A http://example.org/t#B)\n"))) && (test_rungs_omit(arena, SLOP_STR("an ambiguous inverse node is two omissions, not a silent drop"), SLOP_STR("_:x owl:inverseOf :r , :s ."), 2, 2)) && (test_omits_exactly(arena, SLOP_STR("an equivalence with an inverse, whole"), string_concat(arena, test_inv_decls(), SLOP_STR(":p owl:equivalentProperty [ owl:inverseOf :q ] .")), SLOP_STR("EquivalentObjectProperties(http://example.org/t#p ObjectInverseOf(http://example.org/t#q))\n"))) && (test_rungs_omit(arena, SLOP_STR("an inverse equivalent to itself is an omission, not a silent drop"), SLOP_STR("_:x owl:inverseOf :r ; owl:equivalentProperty _:x ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("an inverse into the universal role is omitted, not dropped"), SLOP_STR("[ owl:inverseOf :r ] rdfs:subPropertyOf owl:topObjectProperty ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("an inverse chain never reaches el's regularity check"), SLOP_STR(":t rdfs:subPropertyOf :s . :t owl:propertyChainAxiom ( :s [ owl:inverseOf :r ] ) ."), 1, 1)));
}

uint8_t test_test_data_constructs_decode_as_data(slop_arena* arena) {
    return ((test_omits_exactly(arena, SLOP_STR("DataSomeValuesFrom"), string_concat(arena, test_inv_decls(), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :d ; owl:someValuesFrom xsd:integer ] .")), SLOP_STR("SubClassOf(http://example.org/t#A DataRange(DataSomeValuesFrom(http://example.org/t#d http://www.w3.org/2001/XMLSchema#integer)))\n"))) && (test_omits_exactly(arena, SLOP_STR("DataAllValuesFrom"), string_concat(arena, test_inv_decls(), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :d ; owl:allValuesFrom xsd:integer ] .")), SLOP_STR("SubClassOf(http://example.org/t#A DataRange(DataAllValuesFrom(http://example.org/t#d http://www.w3.org/2001/XMLSchema#integer)))\n"))) && (test_omits_exactly(arena, SLOP_STR("a data cardinality"), string_concat(arena, test_inv_decls(), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :d ; owl:maxCardinality 1 ] .")), SLOP_STR("SubClassOf(http://example.org/t#A DataRange(DataMaxCardinality(http://example.org/t#d \"1\")))\n"))) && (test_omits_exactly(arena, SLOP_STR("owl:onDataRange is data, not a fault"), string_concat(arena, test_inv_decls(), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :e ; owl:minQualifiedCardinality 1 ; owl:onDataRange xsd:integer ] .")), SLOP_STR("SubClassOf(http://example.org/t#A DataRange(DataMinCardinality(http://example.org/t#e \"1\")))\n"))) && (test_rungs_omit(arena, SLOP_STR("owl:onProperties is data, not a fault"), SLOP_STR(":d a owl:DatatypeProperty . :e a owl:DatatypeProperty .\n:C rdfs:subClassOf [ a owl:Restriction ; owl:onProperties ( :d ) ; owl:someValuesFrom <http://www.w3.org/2001/XMLSchema#integer> ] .\n:D rdfs:subClassOf [ a owl:Restriction ; owl:onProperties ( :e ) ; owl:allValuesFrom <http://www.w3.org/2001/XMLSchema#integer> ] ."), 4, 4)) && (test_rungs_omit(arena, SLOP_STR("a stray owl:onProperties is an omission, not a silent drop"), SLOP_STR("_:x owl:onProperties ( :r ) ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("a disjoint union with no member list is an omission, not a fault"), SLOP_STR(":C owl:disjointUnionOf _:missing ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("FunctionalDataProperty on a used property is data"), SLOP_STR(":d a owl:DatatypeProperty , owl:FunctionalProperty . :a :d 1 ."), 2, 2)) && (test_rungs_omit(arena, SLOP_STR("EquivalentDataProperties is data, not role inclusions"), SLOP_STR(":d a owl:DatatypeProperty . :e a owl:DatatypeProperty . :d owl:equivalentProperty :e . :a :d 1 ."), 2, 2)) && (test_rungs_omit(arena, SLOP_STR("a negative assertion on a data property is data"), SLOP_STR(":d a owl:DatatypeProperty . :a :d 1 .\n[ a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; owl:assertionProperty :d ; owl:targetIndividual :b ] ."), 2, 2)) && (test_rungs_omit(arena, SLOP_STR("DisjointDataProperties on used properties is data"), SLOP_STR(":d a owl:DatatypeProperty . :e a owl:DatatypeProperty .\n[ a owl:AllDisjointProperties ; owl:members ( :d :e ) ] . :a :d 1 ; :e 2 ."), 3, 3)));
}

uint8_t test_test_concept_order_is_total(slop_arena* arena) {
    {
        __auto_type r = ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = ((rdf_IRI){.value = SLOP_STR("http://example.org/t#r")}) });
        __auto_type s = ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = ((rdf_IRI){.value = SLOP_STR("http://example.org/t#s")}) });
        __auto_type a = ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = ((rdf_IRI){.value = SLOP_STR("http://example.org/t#a")}) });
        __auto_type b = ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = ((rdf_IRI){.value = SLOP_STR("http://example.org/t#b")}) });
        __auto_type c = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_name, .data.rc_name = ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = SLOP_STR("http://example.org/t#C")}) }) });
        __auto_type d = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_name, .data.rc_name = ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = SLOP_STR("http://example.org/t#D")}) }) });
        __auto_type na = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type nb = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(na); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(nb); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(nb); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return (((owl2_concept_cmp(((owl2_RawConcept){ .tag = owl2_RawConcept_rc_card, .data.rc_card = { .f0 = owl2_CardKind_card_min, .f1 = r, .f2 = 1 } }), ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_card, .data.rc_card = { .f0 = owl2_CardKind_card_min, .f1 = r, .f2 = 2 } })) < 0)) && ((owl2_concept_cmp(((owl2_RawConcept){ .tag = owl2_RawConcept_rc_card, .data.rc_card = { .f0 = owl2_CardKind_card_min, .f1 = r, .f2 = 2 } }), ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_card, .data.rc_card = { .f0 = owl2_CardKind_card_max, .f1 = r, .f2 = 1 } })) < 0)) && ((owl2_concept_cmp(((owl2_RawConcept){ .tag = owl2_RawConcept_rc_card, .data.rc_card = { .f0 = owl2_CardKind_card_min, .f1 = r, .f2 = 1 } }), ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_card, .data.rc_card = { .f0 = owl2_CardKind_card_min, .f1 = s, .f2 = 1 } })) < 0)) && ((owl2_concept_cmp(((owl2_RawConcept){ .tag = owl2_RawConcept_rc_qcard, .data.rc_qcard = { .f0 = owl2_CardKind_card_max, .f1 = r, .f2 = 1, .f3 = test_box_test_concept(arena, c) } }), ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_qcard, .data.rc_qcard = { .f0 = owl2_CardKind_card_max, .f1 = r, .f2 = 1, .f3 = test_box_test_concept(arena, d) } })) < 0)) && ((owl2_concept_cmp(((owl2_RawConcept){ .tag = owl2_RawConcept_rc_qcard, .data.rc_qcard = { .f0 = owl2_CardKind_card_max, .f1 = r, .f2 = 1, .f3 = test_box_test_concept(arena, c) } }), ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_qcard, .data.rc_qcard = { .f0 = owl2_CardKind_card_max, .f1 = r, .f2 = 1, .f3 = test_box_test_concept(arena, c) } })) == 0)) && ((owl2_concept_cmp(((owl2_RawConcept){ .tag = owl2_RawConcept_rc_oneof, .data.rc_oneof = na }), ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_oneof, .data.rc_oneof = nb })) < 0)) && ((owl2_concept_cmp(((owl2_RawConcept){ .tag = owl2_RawConcept_rc_oneof, .data.rc_oneof = nb }), ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_oneof, .data.rc_oneof = na })) > 0)));
    }
}

owl2_RawConcept* test_box_test_concept(slop_arena* arena, owl2_RawConcept c) {
    {
        __auto_type p = ((owl2_RawConcept*)(({ __auto_type _alloc = (owl2_RawConcept*)slop_arena_alloc(arena, sizeof(owl2_RawConcept)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = c;
        return p;
    }
}

uint8_t test_rungs3_omit(slop_arena* arena, slop_string label, slop_string ttl, int64_t el_want, int64_t elpp_want, int64_t sriq_want) {
    {
        __auto_type doc = string_concat(arena, test_rung_prefix(), ttl);
        {
            __auto_type el = test_omissions_under(arena, doc, types_Profile_profile_el);
            __auto_type pp = test_omissions_under(arena, doc, types_Profile_profile_el_plus_plus);
            __auto_type sq = test_omissions_under(arena, doc, types_Profile_profile_sriq);
            if ((el == el_want) && ((pp == elpp_want) && (sq == sriq_want))) {
                return 1;
            } else {
                printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [rungs3] "), label)).len, (string_concat(arena, SLOP_STR("  [rungs3] "), label)).data);
                printf("%s", "    el ");
                printf("%.*s", (int)(int_to_string(arena, el)).len, (int_to_string(arena, el)).data);
                printf("%s", "  el++ ");
                printf("%.*s", (int)(int_to_string(arena, pp)).len, (int_to_string(arena, pp)).data);
                printf("%s", "  sriq ");
                printf("%.*s\n", (int)(int_to_string(arena, sq)).len, (int_to_string(arena, sq)).data);
                return 0;
            }
        }
    }
}

slop_string test_s0_prefix(void) {
    return SLOP_STR("@prefix : <urn:x:> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n:A a owl:Class . :B a owl:Class . :C a owl:Class .\n:r a owl:ObjectProperty . :s a owl:ObjectProperty . :t a owl:ObjectProperty .\n:a a owl:NamedIndividual . :b a owl:NamedIndividual .\n");
}

slop_string test_render_saxioms(slop_arena* arena, slop_list_sroiq_SAxiom axs) {
    {
        __auto_type out = SLOP_STR("");
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                out = string_concat(arena, out, string_concat(arena, sroiq_render_saxiom(arena, a), SLOP_STR("\n")));
            }
        }
        return out;
    }
}

slop_string test_s0_of(slop_arena* arena, slop_string ttl, uint8_t through_s1) {
    __auto_type _mv_1493 = test_gate_ttl_in(arena, string_concat(arena, test_s0_prefix(), ttl), types_Profile_profile_sriq);
    if (!_mv_1493.has_value) {
        return SLOP_STR("did not gate\n");
    } else if (_mv_1493.has_value) {
        __auto_type gr = _mv_1493.value;
        {
            __auto_type om = ((int64_t)(((int64_t)((gr.omissions).len))));
            __auto_type lead = (((((int64_t)(((int64_t)((gr.omissions).len)))) > 0)) ? string_concat(arena, SLOP_STR("omitted "), string_concat(arena, int_to_string(arena, om), SLOP_STR("\n"))) : SLOP_STR(""));
            __auto_type _mv_1494 = sriqnormal_sriq_s0(arena, gr.accepted);
            if (!_mv_1494.is_ok) {
                __auto_type m = _mv_1494.data.err;
                return string_concat(arena, lead, string_concat(arena, SLOP_STR("refused: "), string_concat(arena, m, SLOP_STR("\n"))));
            } else if (_mv_1494.is_ok) {
                __auto_type s0 = _mv_1494.data.ok;
                if (through_s1) {
                    __auto_type _mv_1495 = sriqelim_sriq_s1(arena, s0, sriqelim_S1_BOUND);
                    if (!_mv_1495.is_ok) {
                        __auto_type m = _mv_1495.data.err;
                        return string_concat(arena, lead, string_concat(arena, SLOP_STR("refused: "), string_concat(arena, m, SLOP_STR("\n"))));
                    } else if (_mv_1495.is_ok) {
                        __auto_type s1 = _mv_1495.data.ok;
                        return string_concat(arena, lead, test_render_saxioms(arena, s1.axioms));
                    }
                    SLOP_UNREACHABLE();
                } else {
                    return string_concat(arena, lead, test_render_saxioms(arena, s0.axioms));
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_s0_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want) {
    {
        __auto_type got = test_s0_of(arena, ttl, 0);
        if (canon_string_cmp(got, want) == 0) {
            return 1;
        } else {
            printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [s0] "), label)).len, (string_concat(arena, SLOP_STR("  [s0] "), label)).data);
            printf("%.*s", (int)(got).len, (got).data);
            return 0;
        }
    }
}

uint8_t test_s1_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want) {
    {
        __auto_type got = test_s0_of(arena, ttl, 1);
        if (canon_string_cmp(got, want) == 0) {
            return 1;
        } else {
            printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [s1] "), label)).len, (string_concat(arena, SLOP_STR("  [s1] "), label)).data);
            printf("%.*s", (int)(got).len, (got).data);
            return 0;
        }
    }
}

uint8_t test_test_sriq_s0_rows(slop_arena* arena) {
    {
        uint8_t ok = 1;
        if (!(test_s0_is(arena, SLOP_STR("subclass"), SLOP_STR(":A rdfs:subClassOf :B ."), SLOP_STR("urn:x:A ⊑ urn:x:B\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("domain"), SLOP_STR(":r rdfs:domain :A ."), SLOP_STR("∃urn:x:r.⊤ ⊑ urn:x:A\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("range"), SLOP_STR(":r rdfs:range :A ."), SLOP_STR("⊤ ⊑ ∀urn:x:r.urn:x:A\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("union and complement"), SLOP_STR(":A rdfs:subClassOf [ owl:unionOf ( :B [ owl:complementOf :C ] ) ] ."), SLOP_STR("urn:x:A ⊑ (urn:x:B ⊔ ¬urn:x:C)\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("ACI: a nested, repeated, reordered conjunction"), SLOP_STR(":A rdfs:subClassOf [ owl:intersectionOf ( :C [ owl:intersectionOf ( :B :C ) ] ) ] ."), SLOP_STR("urn:x:A ⊑ (urn:x:B ⊓ urn:x:C)\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("a unit: C or bottom is C"), SLOP_STR(":A rdfs:subClassOf [ owl:unionOf ( :B owl:Nothing ) ] ."), SLOP_STR("urn:x:A ⊑ urn:x:B\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("a unit: C and top is C"), SLOP_STR(":A rdfs:subClassOf [ owl:intersectionOf ( :B owl:Thing ) ] ."), SLOP_STR("urn:x:A ⊑ urn:x:B\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("a zero: C or top is top"), SLOP_STR(":A rdfs:subClassOf [ owl:unionOf ( :B owl:Thing ) ] ."), SLOP_STR("urn:x:A ⊑ ⊤\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("qualified >=1 is exists"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:minQualifiedCardinality 1 ; owl:onClass :B ] ."), SLOP_STR("urn:x:A ⊑ ∃urn:x:r.urn:x:B\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("exact 2 is >=2 and <=2"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:qualifiedCardinality 2 ; owl:onClass :B ] ."), SLOP_STR("urn:x:A ⊑ (≥2 urn:x:r.urn:x:B ⊓ ≤2 urn:x:r.urn:x:B)\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("unqualified is qualified by top"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:maxCardinality 3 ] ."), SLOP_STR("urn:x:A ⊑ ≤3 urn:x:r.⊤\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("Self on an inverse is Self on the property"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty [ owl:inverseOf :r ] ; owl:hasSelf true ] ."), SLOP_STR("urn:x:A ⊑ ∃urn:x:r.Self\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("DisjointClasses"), SLOP_STR(":A owl:disjointWith :B ."), SLOP_STR("(urn:x:A ⊓ urn:x:B) ⊑ ⊥\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("DisjointUnion"), SLOP_STR(":C owl:disjointUnionOf ( :A :B ) ."), SLOP_STR("urn:x:C ⊑ (urn:x:A ⊔ urn:x:B)\n(urn:x:A ⊓ urn:x:B) ⊑ ⊥\n(urn:x:A ⊔ urn:x:B) ⊑ urn:x:C\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("characteristics"), SLOP_STR(":r a owl:FunctionalProperty , owl:InverseFunctionalProperty , owl:ReflexiveProperty , owl:IrreflexiveProperty , owl:AsymmetricProperty ."), SLOP_STR("⊤ ⊑ ≤1 urn:x:r.⊤\n⊤ ⊑ ≤1 urn:x:r⁻.⊤\nRef(urn:x:r)\nIrr(urn:x:r)\nDis(urn:x:r, urn:x:r⁻)\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("DisjointObjectProperties"), SLOP_STR(":r owl:propertyDisjointWith :s ."), SLOP_STR("Dis(urn:x:r, urn:x:s)\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("ClassAssertion"), SLOP_STR(":a a [ owl:unionOf ( :A :B ) ] ."), SLOP_STR("{urn:x:a} ⊑ (urn:x:A ⊔ urn:x:B)\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("ObjectPropertyAssertion"), SLOP_STR(":a :r :b ."), SLOP_STR("{urn:x:a} ⊑ ∃urn:x:r.{urn:x:b}\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("NegativeObjectPropertyAssertion"), SLOP_STR("[ a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; owl:assertionProperty :r ; owl:targetIndividual :b ] ."), SLOP_STR("{urn:x:a} ⊑ ∀urn:x:r.¬{urn:x:b}\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("SameIndividual around the least member"), SLOP_STR(":b owl:sameAs :a ."), SLOP_STR("{urn:x:a} ⊑ {urn:x:b}\n{urn:x:b} ⊑ {urn:x:a}\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("DifferentIndividuals"), SLOP_STR(":a owl:differentFrom :b ."), SLOP_STR("({urn:x:a} ⊓ {urn:x:b}) ⊑ ⊥\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("InverseObjectProperties collapses to nothing"), SLOP_STR(":r owl:inverseOf :s .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :s ; owl:someValuesFrom :B ] ."), SLOP_STR("urn:x:A ⊑ ∃urn:x:r⁻.urn:x:B\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("an equivalence with an inverse collapses"), SLOP_STR(":r owl:equivalentProperty [ owl:inverseOf :s ] .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :s ; owl:someValuesFrom :B ] ."), SLOP_STR("urn:x:A ⊑ ∃urn:x:r⁻.urn:x:B\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("P and P- in one component keep P- [= P"), SLOP_STR(":r owl:inverseOf :r ."), SLOP_STR("urn:x:r⁻ ⊑ urn:x:r\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("symmetry is P- [= P"), SLOP_STR(":r a owl:SymmetricProperty ."), SLOP_STR("urn:x:r⁻ ⊑ urn:x:r\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("RO's part_of/has_part: transitivity in both orientations"), SLOP_STR(":r a owl:TransitiveProperty . :s a owl:TransitiveProperty . :r owl:inverseOf :s ."), SLOP_STR("urn:x:r ∘ urn:x:r ⊑ urn:x:r\nurn:x:r⁻ ∘ urn:x:r⁻ ⊑ urn:x:r⁻\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("a simple role hierarchy"), SLOP_STR(":r rdfs:subPropertyOf :s . :s rdfs:subPropertyOf :t ."), SLOP_STR("urn:x:r ⊑ urn:x:s\nurn:x:s ⊑ urn:x:t\n")))) {
            ok = 0;
        }
        if (!(test_s0_is(arena, SLOP_STR("the empty role"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty owl:bottomObjectProperty ; owl:someValuesFrom :B ] ."), SLOP_STR("urn:x:A ⊑ ∃http://www.w3.org/2002/07/owl#bottomObjectProperty.urn:x:B\n∃http://www.w3.org/2002/07/owl#bottomObjectProperty.⊤ ⊑ ⊥\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("S1's hook passes a chain-free RBox"), SLOP_STR(":r rdfs:subPropertyOf :s .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:someValuesFrom :B ] ."), SLOP_STR("urn:x:A ⊑ ∃urn:x:r.urn:x:B\nurn:x:r ⊑ urn:x:s\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("transitivity alone is eliminated: nothing is left"), SLOP_STR(":r a owl:TransitiveProperty ."), SLOP_STR("")))) {
            ok = 0;
        }
        return ok;
    }
}

slop_list_string test_sort_strings(slop_arena* arena, slop_list_string xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ test__lambda_1496_env_t* test__lambda_1496_env = (test__lambda_1496_env_t*)slop_arena_alloc(arena, sizeof(test__lambda_1496_env_t)); *test__lambda_1496_env = (test__lambda_1496_env_t){ .xs = xs }; (slop_closure_t){ (void*)test__lambda_1496, (void*)test__lambda_1496_env }; }));
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (test_str_at_t(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_string test_str_at_t(slop_list_string xs, int64_t i) {
    __auto_type _mv_1497 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_string _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1497.has_value) {
        __auto_type v = _mv_1497.value;
        return v;
    } else if (!_mv_1497.has_value) {
        return SLOP_STR("");
    }
    SLOP_UNREACHABLE();
}

slop_string test_refusal_line(slop_arena* arena, slop_string m) {
    return string_concat(arena, SLOP_STR("refused: "), string_concat(arena, m, SLOP_STR("\n")));
}

slop_string test_s2_text(slop_arena* arena, slop_result_sriqnormal_S2_string r) {
    __auto_type _mv_1498 = r;
    if (!_mv_1498.is_ok) {
        __auto_type m = _mv_1498.data.err;
        return string_concat(arena, SLOP_STR("S2 error: "), string_concat(arena, m, SLOP_STR("\n")));
    } else if (_mv_1498.is_ok) {
        __auto_type s2 = _mv_1498.data.ok;
        {
            __auto_type ls = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            __auto_type out = SLOP_STR("");
            {
                __auto_type _coll = s2.clauses;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    ({ __auto_type _lst_p = &(ls); __auto_type _item = (sriqnormal_render_dl(arena, s2, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            {
                __auto_type _coll = test_sort_strings(arena, ls);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type l = _coll.data[_i];
                    out = string_concat(arena, out, string_concat(arena, l, SLOP_STR("\n")));
                }
            }
            return out;
        }
    }
    SLOP_UNREACHABLE();
}

slop_string test_s2_after_s1(slop_arena* arena, slop_result_sriqelim_S1_string r) {
    __auto_type _mv_1499 = r;
    if (!_mv_1499.is_ok) {
        __auto_type m = _mv_1499.data.err;
        return test_refusal_line(arena, m);
    } else if (_mv_1499.is_ok) {
        __auto_type s1 = _mv_1499.data.ok;
        return test_s2_text(arena, sriqnormal_sriq_s2(arena, s1.axioms));
    }
    SLOP_UNREACHABLE();
}

slop_string test_s2_after_s0(slop_arena* arena, slop_result_sriqnormal_S0_string r) {
    __auto_type _mv_1500 = r;
    if (!_mv_1500.is_ok) {
        __auto_type m = _mv_1500.data.err;
        return test_refusal_line(arena, m);
    } else if (_mv_1500.is_ok) {
        __auto_type s0 = _mv_1500.data.ok;
        return test_s2_after_s1(arena, sriqelim_sriq_s1(arena, s0, sriqelim_S1_BOUND));
    }
    SLOP_UNREACHABLE();
}

slop_string test_s2_of(slop_arena* arena, slop_string ttl) {
    __auto_type _mv_1501 = test_gate_ttl_in(arena, string_concat(arena, test_s0_prefix(), ttl), types_Profile_profile_sriq);
    if (!_mv_1501.has_value) {
        return SLOP_STR("did not gate\n");
    } else if (_mv_1501.has_value) {
        __auto_type gr = _mv_1501.value;
        return string_concat(arena, (((((int64_t)(((int64_t)((gr.omissions).len)))) > 0)) ? SLOP_STR("OMITTED\n") : SLOP_STR("")), test_s2_after_s0(arena, sriqnormal_sriq_s0(arena, gr.accepted)));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_s2_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want) {
    {
        __auto_type got = test_s2_of(arena, ttl);
        if (canon_string_cmp(got, want) == 0) {
            return 1;
        } else {
            printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [s2] "), label)).len, (string_concat(arena, SLOP_STR("  [s2] "), label)).data);
            printf("%.*s", (int)(got).len, (got).data);
            return 0;
        }
    }
}

slop_list_string test_sriq_fixtures(slop_arena* arena) {
    {
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/litmus.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-domain-range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/inverse-expressions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/property-characteristics.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/cardinality.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/range-complex-fillers.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/abox-disjoint-range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/abox-complex-range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/abox-nary-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/smaller-side-join.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/role-hierarchy-deep.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/el++/ksc-22.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/el++/ksc-28.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/transitive.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/probes/chain-binary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/rbox-regularity-accept.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/chain-prefix-collision.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/abox-chain-mixed.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/el++/ksc-05.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/sriq/sim12-example1.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/sriq/symmetric.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/sriq/inverse-all.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ps;
    }
}

slop_option_gate_GateResult test_gate_triples_in(slop_arena* arena, slop_list_rdf_Triple ts, types_Profile p) {
    __auto_type _mv_1502 = decode_stage0_header(arena, ts, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
    if (!_mv_1502.is_ok) {
        __auto_type _ = _mv_1502.data.err;
        return (slop_option_gate_GateResult){.has_value = false};
    } else if (_mv_1502.is_ok) {
        __auto_type s0 = _mv_1502.data.ok;
        __auto_type _mv_1503 = decode_decode_axioms(arena, s0.dict, s0.triples);
        if (!_mv_1503.is_ok) {
            __auto_type _ = _mv_1503.data.err;
            return (slop_option_gate_GateResult){.has_value = false};
        } else if (_mv_1503.is_ok) {
            __auto_type s1 = _mv_1503.data.ok;
            return (slop_option_gate_GateResult){.has_value = 1, .value = gate_gate_axioms(arena, s1.axioms, s1.signature, s0.omissions, p)};
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_list_owl2_RawAxiom test_reversed_raw(slop_arena* arena, slop_list_owl2_RawAxiom xs) {
    {
        __auto_type out = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = (((int64_t)(((int64_t)((xs).len)))) - 1);
        while (k >= 0) {
            __auto_type _mv_1504 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_owl2_RawAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1504.has_value) {
                __auto_type x = _mv_1504.value;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_1504.has_value) {
            }
            k = (k - 1);
        }
        return out;
    }
}

slop_list_sroiq_SAxiom test_reversed_saxioms(slop_arena* arena, slop_list_sroiq_SAxiom xs) {
    {
        __auto_type out = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = (((int64_t)(((int64_t)((xs).len)))) - 1);
        while (k >= 0) {
            __auto_type _mv_1505 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_sroiq_SAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1505.has_value) {
                __auto_type x = _mv_1505.value;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_1505.has_value) {
            }
            k = (k - 1);
        }
        return out;
    }
}

slop_result_sriqnames_SriqNormal_string test_s2_to_names(slop_arena* arena, gate_GateResult gr, sriqelim_S1 s1, uint8_t flip) {
    __auto_type _mv_1506 = sriqnormal_sriq_s2(arena, ((flip) ? test_reversed_saxioms(arena, s1.axioms) : s1.axioms));
    if (!_mv_1506.is_ok) {
        __auto_type m = _mv_1506.data.err;
        return ((slop_result_sriqnames_SriqNormal_string){ .is_ok = false, .data.err = m });
    } else if (_mv_1506.is_ok) {
        __auto_type s2 = _mv_1506.data.ok;
        return ((slop_result_sriqnames_SriqNormal_string){ .is_ok = true, .data.ok = sriqnames_sriq_names(arena, s2, gr.signature, sriqnames_guard_witnesses(arena, gr.accepted, s1)) });
    }
    SLOP_UNREACHABLE();
}

sriqnormal_S0 test_reversed_s0(slop_arena* arena, sriqnormal_S0 s0) {
    return ((sriqnormal_S0){.axioms = test_reversed_saxioms(arena, s0.axioms), .rbox = s0.rbox});
}

slop_result_sriqnames_SriqNormal_string test_sriq_nf(slop_arena* arena, gate_GateResult gr, uint8_t flip_accepted, uint8_t flip_s0, uint8_t flip_s2) {
    __auto_type _mv_1507 = sriqnormal_sriq_s0(arena, ((flip_accepted) ? test_reversed_raw(arena, gr.accepted) : gr.accepted));
    if (!_mv_1507.is_ok) {
        __auto_type m = _mv_1507.data.err;
        return ((slop_result_sriqnames_SriqNormal_string){ .is_ok = false, .data.err = m });
    } else if (_mv_1507.is_ok) {
        __auto_type s0 = _mv_1507.data.ok;
        __auto_type _mv_1508 = sriqelim_sriq_s1(arena, ((flip_s0) ? test_reversed_s0(arena, s0) : s0), sriqelim_S1_BOUND);
        if (!_mv_1508.is_ok) {
            __auto_type m = _mv_1508.data.err;
            return ((slop_result_sriqnames_SriqNormal_string){ .is_ok = false, .data.err = m });
        } else if (_mv_1508.is_ok) {
            __auto_type s1 = _mv_1508.data.ok;
            return test_s2_to_names(arena, gr, s1, flip_s2);
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_list_string test_nf_lines(slop_arena* arena, slop_result_sriqnames_SriqNormal_string r) {
    __auto_type _mv_1509 = r;
    if (_mv_1509.is_ok) {
        __auto_type n = _mv_1509.data.ok;
        return sriqnames_render_sriq_normal(arena, n);
    } else if (!_mv_1509.is_ok) {
        __auto_type m = _mv_1509.data.err;
        {
            __auto_type ls = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            ({ __auto_type _lst_p = &(ls); __auto_type _item = (string_concat(arena, SLOP_STR("error: "), m)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            return ls;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_nf_invariants_hold(slop_arena* arena, slop_string path, slop_result_sriqnames_SriqNormal_string r) {
    __auto_type _mv_1510 = r;
    if (!_mv_1510.is_ok) {
        __auto_type m = _mv_1510.data.err;
        printf("%s", "  [s5] refused: ");
        printf("%.*s", (int)(path).len, (path).data);
        printf("%s", " ");
        printf("%.*s\n", (int)(m).len, (m).data);
        return 0;
    } else if (_mv_1510.is_ok) {
        __auto_type n = _mv_1510.data.ok;
        {
            __auto_type bad = sriqnames_sriq_invariants(arena, n);
            if (((int64_t)((bad).len)) == 0) {
                return 1;
            } else {
                printf("%s", "  [s5] ");
                printf("%.*s\n", (int)(path).len, (path).data);
                {
                    __auto_type _coll = bad;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type b = _coll.data[_i];
                        printf("%s", "    ");
                        printf("%.*s\n", (int)(b).len, (b).data);
                    }
                }
                return 0;
            }
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_sriq_order_independent(slop_arena* arena, slop_string path) {
    __auto_type _mv_1511 = ttl_parse_ttl_file(arena, path);
    if (!_mv_1511.is_ok) {
        __auto_type _ = _mv_1511.data.err;
        printf("%s", "  [s5] did not parse: ");
        printf("%.*s\n", (int)(path).len, (path).data);
        return 0;
    } else if (_mv_1511.is_ok) {
        __auto_type g = _mv_1511.data.ok;
        __auto_type _mv_1512 = test_gate_triples_in(arena, g.triples, types_Profile_profile_sriq);
        if (!_mv_1512.has_value) {
            printf("%s", "  [s5] did not gate: ");
            printf("%.*s\n", (int)(path).len, (path).data);
            return 0;
        } else if (_mv_1512.has_value) {
            __auto_type fwd = _mv_1512.value;
            __auto_type _mv_1513 = test_gate_triples_in(arena, test_reversed_triples(arena, g.triples), types_Profile_profile_sriq);
            if (!_mv_1513.has_value) {
                return 0;
            } else if (_mv_1513.has_value) {
                __auto_type rev = _mv_1513.value;
                {
                    __auto_type n0 = test_sriq_nf(arena, fwd, 0, 0, 0);
                    __auto_type l0 = test_nf_lines(arena, n0);
                    __auto_type l1 = test_nf_lines(arena, test_sriq_nf(arena, rev, 0, 0, 0));
                    __auto_type l2 = test_nf_lines(arena, test_sriq_nf(arena, fwd, 1, 0, 0));
                    __auto_type l3 = test_nf_lines(arena, test_sriq_nf(arena, fwd, 0, 0, 1));
                    __auto_type l4 = test_nf_lines(arena, test_sriq_nf(arena, fwd, 0, 1, 0));
                    uint8_t ok = test_nf_invariants_hold(arena, path, n0);
                    if (!(test_same_lines(l0, l1))) {
                        printf("%s", "  [s5] triples reversed differ: ");
                        printf("%.*s\n", (int)(path).len, (path).data);
                        ok = 0;
                    }
                    if (!(test_same_lines(l0, l2))) {
                        printf("%s", "  [s5] accepted reversed differs: ");
                        printf("%.*s\n", (int)(path).len, (path).data);
                        ok = 0;
                    }
                    if (!(test_same_lines(l0, l3))) {
                        printf("%s", "  [s5] S2's input reversed differs: ");
                        printf("%.*s\n", (int)(path).len, (path).data);
                        ok = 0;
                    }
                    if (!(test_same_lines(l0, l4))) {
                        printf("%s", "  [s5] S1's input reversed differs: ");
                        printf("%.*s\n", (int)(path).len, (path).data);
                        ok = 0;
                    }
                    return ok;
                }
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sriq_ids_row(slop_arena* arena) {
    __auto_type _mv_1514 = test_gate_ttl_in(arena, string_concat(arena, test_s0_prefix(), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty [ owl:inverseOf :s ] ; owl:someValuesFrom :B ] .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :C ] .\n:B rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:maxQualifiedCardinality 1 ; owl:onClass [ owl:unionOf ( :A :C ) ] ] .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :t ; owl:minQualifiedCardinality 2 ; owl:onClass :B ] .")), types_Profile_profile_sriq);
    if (!_mv_1514.has_value) {
        return 0;
    } else if (_mv_1514.has_value) {
        __auto_type gr = _mv_1514.value;
        {
            __auto_type want = SLOP_STR("DL1|| A0 A1\nDL1| urn:x:A| A3\nDL1| urn:x:A| A4\nDL1| urn:x:A A0|\nDL1| urn:x:B| A5\nDL1| urn:x:C| A2\nDL1| urn:x:C A0|\nDL2|A2|urn:x:s^bar|1|urn:x:B| f0\nDL2|A4|urn:x:t|2|urn:x:B| f1 f2\nDL3|urn:x:r^bar|A3|urn:x:C\nDL4|A5|urn:x:r|1|A1|S0\nDL8|urn:x:r|urn:x:r^bar\nDL8|urn:x:s|urn:x:s^bar\nDL8|urn:x:r^bar|urn:x:r\nDL8|urn:x:s^bar|urn:x:s\nA0 = (¬urn:x:A ⊓ ¬urn:x:C)\nA1 = (urn:x:A ⊔ urn:x:C)\nA2 = ∃urn:x:s⁻.urn:x:B\nA3 = ∀urn:x:r.urn:x:C\nA4 = ≥2 urn:x:t.urn:x:B\nA5 = ≤1 urn:x:r.(urn:x:A ⊔ urn:x:C)\nS0 = urn:x:r A1\nbar urn:x:r\nbar urn:x:s\nfns 3\nclass urn:x:A\nclass urn:x:B\nclass urn:x:C\nindividual urn:x:a\nindividual urn:x:b\n");
            __auto_type got = SLOP_STR("");
            {
                __auto_type _coll = test_nf_lines(arena, sriqnames_sriq_normalize(arena, gr.accepted, gr.signature));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type l = _coll.data[_i];
                    got = string_concat(arena, got, string_concat(arena, l, SLOP_STR("\n")));
                }
            }
            if (string_eq(got, want)) {
                return 1;
            } else {
                printf("%s\n", "  [s5] ids row, got:");
                printf("%.*s", (int)(got).len, (got).data);
                return 0;
            }
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sriq_one_clause_from_two_axioms(slop_arena* arena) {
    __auto_type _mv_1515 = test_gate_ttl_in(arena, string_concat(arena, test_s0_prefix(), SLOP_STR(":u a owl:ObjectProperty .\n:r rdfs:subPropertyOf :s .\n:t owl:inverseOf :r .\n:u owl:inverseOf :s .\n:t rdfs:subPropertyOf :u .")), types_Profile_profile_sriq);
    if (!_mv_1515.has_value) {
        return 0;
    } else if (_mv_1515.has_value) {
        __auto_type gr = _mv_1515.value;
        {
            __auto_type want = SLOP_STR("DL7|urn:x:r|urn:x:s\nfns 0\nclass urn:x:A\nclass urn:x:B\nclass urn:x:C\nindividual urn:x:a\nindividual urn:x:b\n");
            __auto_type got = SLOP_STR("");
            {
                __auto_type _coll = test_nf_lines(arena, sriqnames_sriq_normalize(arena, gr.accepted, gr.signature));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type l = _coll.data[_i];
                    got = string_concat(arena, got, string_concat(arena, l, SLOP_STR("\n")));
                }
            }
            if (string_eq(got, want)) {
                return 1;
            } else {
                printf("%s\n", "  [s5] one clause from two axioms, got:");
                printf("%.*s", (int)(got).len, (got).data);
                return 0;
            }
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sriq_ids_from_content(slop_arena* arena) {
    {
        uint8_t ok = 1;
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = test_sriq_fixtures(arena);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (!(test_sriq_order_independent(arena, p))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t test_yields_nothing_by_design(owl2_RawAxiom a) {
    __auto_type _mv_1516 = a;
    switch (_mv_1516.tag) {
        case owl2_RawAxiom_ra_declaration:
        {
            __auto_type _ = _mv_1516.data.ra_declaration;
            return 1;
        }
        case owl2_RawAxiom_ra_annotation:
        {
            return 1;
        }
        case owl2_RawAxiom_ra_inert_data:
        {
            return 1;
        }
        case owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type _ = _mv_1516.data.ra_equivalent_properties;
            return 1;
        }
        case owl2_RawAxiom_ra_inverse_properties:
        {
            return 1;
        }
        default: {
            return 0;
        }
    }
}

slop_list_owl2_RawAxiom test_one_raw(slop_arena* arena, owl2_RawAxiom a) {
    {
        __auto_type xs = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return xs;
    }
}

uint8_t test_print_alone(slop_arena* arena, owl2_RawAxiom a) {
    printf("%s", "  [s5] no clauses from ");
    __auto_type _mv_1517 = sriqnormal_sriq_s0(arena, test_one_raw(arena, a));
    if (_mv_1517.is_ok) {
        __auto_type s0 = _mv_1517.data.ok;
        printf("%.*s", (int)(test_render_saxioms(arena, s0.axioms)).len, (test_render_saxioms(arena, s0.axioms)).data);
    } else if (!_mv_1517.is_ok) {
        __auto_type _ = _mv_1517.data.err;
        printf("%s\n", "?");
    }
    return 1;
}

uint8_t test_is_chain_axiom(owl2_RawAxiom a) {
    __auto_type _mv_1518 = a;
    switch (_mv_1518.tag) {
        case owl2_RawAxiom_ra_property_chain:
        {
            __auto_type _ = _mv_1518.data.ra_property_chain;
            return 1;
        }
        default: {
            return 0;
        }
    }
}

int64_t test_yield_kind(slop_arena* arena, owl2_RawAxiom a, owl2_Signature sig) {
    __auto_type _mv_1519 = sriqnames_sriq_normalize(arena, test_one_raw(arena, a), sig);
    if (!_mv_1519.is_ok) {
        __auto_type m = _mv_1519.data.err;
        printf("%s", "  [s5] refused alone: ");
        printf("%.*s\n", (int)(m).len, (m).data);
        return 2;
    } else if (_mv_1519.is_ok) {
        __auto_type n = _mv_1519.data.ok;
        if (((int64_t)((n.clauses).len)) > 0) {
            return 0;
        } else if (test_is_chain_axiom(a)) {
            return 1;
        } else if (test_yields_nothing_by_design(a)) {
            return 0;
        } else {
            test_print_alone(arena, a);
            return 2;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_every_axiom_yields(slop_arena* arena, slop_string path) {
    __auto_type _mv_1520 = test_gate_fixture_in(arena, path, types_Profile_profile_sriq);
    if (!_mv_1520.has_value) {
        printf("%s", "  [s5] did not gate: ");
        printf("%.*s\n", (int)(path).len, (path).data);
        return 0;
    } else if (_mv_1520.has_value) {
        __auto_type gr = _mv_1520.value;
        {
            uint8_t ok = 1;
            int64_t chains = 0;
            {
                __auto_type _coll = gr.accepted;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    {
                        __auto_type k = test_yield_kind(arena, a, gr.signature);
                        if (k == 1) {
                            chains = (chains + 1);
                        }
                        if (k == 2) {
                            ok = 0;
                        }
                    }
                }
            }
            printf("%s", "  [s5] ");
            printf("%.*s", (int)(path).len, (path).data);
            printf("%s", ": ");
            printf("%.*s", (int)(int_to_string(arena, ((int64_t)(((int64_t)((gr.accepted).len)))))).len, (int_to_string(arena, ((int64_t)(((int64_t)((gr.accepted).len)))))).data);
            printf("%s", " accepted, ");
            printf("%.*s", (int)(int_to_string(arena, chains)).len, (int_to_string(arena, chains)).data);
            printf("%s\n", " chains eliminated by S1");
            return ok;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sriq_every_axiom_yields(slop_arena* arena) {
    {
        uint8_t ok = 1;
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = test_sriq_fixtures(arena);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (!(test_every_axiom_yields(arena, p))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

slop_string test_s1_text(slop_arena* arena, sriqelim_S1 s1) {
    {
        __auto_type out = test_render_saxioms(arena, s1.axioms);
        {
            __auto_type _coll = s1.omitted;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                out = string_concat(arena, out, string_concat(arena, SLOP_STR("omitted "), string_concat(arena, sroiq_render_saxiom(arena, a), SLOP_STR("\n"))));
            }
        }
        return out;
    }
}

slop_string test_s1_bounded_of(slop_arena* arena, slop_string ttl, int64_t bound) {
    __auto_type _mv_1521 = test_gate_ttl_in(arena, string_concat(arena, test_s0_prefix(), ttl), types_Profile_profile_sriq);
    if (!_mv_1521.has_value) {
        return SLOP_STR("did not gate\n");
    } else if (_mv_1521.has_value) {
        __auto_type gr = _mv_1521.value;
        __auto_type _mv_1522 = sriqnormal_sriq_s0(arena, gr.accepted);
        if (!_mv_1522.is_ok) {
            __auto_type m = _mv_1522.data.err;
            return string_concat(arena, SLOP_STR("refused: "), string_concat(arena, m, SLOP_STR("\n")));
        } else if (_mv_1522.is_ok) {
            __auto_type s0 = _mv_1522.data.ok;
            __auto_type _mv_1523 = sriqelim_sriq_s1(arena, s0, bound);
            if (!_mv_1523.is_ok) {
                __auto_type m = _mv_1523.data.err;
                return string_concat(arena, SLOP_STR("refused: "), string_concat(arena, m, SLOP_STR("\n")));
            } else if (_mv_1523.is_ok) {
                __auto_type s1 = _mv_1523.data.ok;
                return test_s1_text(arena, s1);
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_s1_bounded_is(slop_arena* arena, slop_string label, slop_string ttl, int64_t bound, slop_string want) {
    {
        __auto_type got = test_s1_bounded_of(arena, ttl, bound);
        if (string_eq(got, want)) {
            return 1;
        } else {
            printf("%s", "  [s1] ");
            printf("%.*s\n", (int)(label).len, (label).data);
            printf("%.*s", (int)(got).len, (got).data);
            return 0;
        }
    }
}

uint8_t test_test_sriq_guard_witnesses(slop_arena* arena) {
    __auto_type _mv_1524 = test_gate_ttl_in(arena, string_concat(arena, test_s0_prefix(), SLOP_STR(":r a owl:TransitiveProperty .\n:s owl:propertyChainAxiom ( :t ) .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :B ] .")), types_Profile_profile_sriq);
    if (!_mv_1524.has_value) {
        return 0;
    } else if (_mv_1524.has_value) {
        __auto_type gr = _mv_1524.value;
        __auto_type _mv_1525 = sriqnames_sriq_normalize_bounded(arena, gr.accepted, gr.signature, 0);
        if (!_mv_1525.is_ok) {
            __auto_type m = _mv_1525.data.err;
            printf("%s", "  [guard] refused: ");
            printf("%.*s\n", (int)(m).len, (m).data);
            return 0;
        } else if (_mv_1525.is_ok) {
            __auto_type n = _mv_1525.data.ok;
            {
                __auto_type want = SLOP_STR("omitted SubObjectPropertyOf(ObjectPropertyChain(urn:x:r urn:x:r) urn:x:r)\n");
                __auto_type got = SLOP_STR("");
                {
                    __auto_type _coll = sriqnames_render_sriq_normal(arena, n);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type l = _coll.data[_i];
                        if (strlib_starts_with(l, SLOP_STR("omitted "))) {
                            got = string_concat(arena, got, string_concat(arena, l, SLOP_STR("\n")));
                        }
                    }
                }
                if (string_eq(got, want) && (((int64_t)((n.clauses).len)) > 0)) {
                    return 1;
                } else {
                    printf("%s\n", "  [guard] witnesses, got:");
                    printf("%.*s", (int)(got).len, (got).data);
                    return 0;
                }
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sriq_s1_rows(slop_arena* arena) {
    {
        uint8_t ok = 1;
        if (!(test_s1_bounded_is(arena, SLOP_STR("the guard: past the bound, S0 minus its chains, the chains omitted"), SLOP_STR(":r a owl:TransitiveProperty .\n:s rdfs:subPropertyOf :r .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :B ] ."), 0, SLOP_STR("urn:x:A ⊑ ∀urn:x:r.urn:x:B\nurn:x:s ⊑ urn:x:r\nomitted urn:x:r ∘ urn:x:r ⊑ urn:x:r\n")))) {
            ok = 0;
        }
        if (!(test_s1_bounded_is(arena, SLOP_STR("the guard: at the bound, S1 runs whole"), SLOP_STR(":r a owl:TransitiveProperty .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :B ] ."), 1, SLOP_STR("urn:x:A ⊑ I[∀urn:x:r.urn:x:B]\nI[∀urn:x:r.urn:x:B] ⊑ ∀urn:x:r.F[∀urn:x:r.urn:x:B]\nF[∀urn:x:r.urn:x:B] ⊑ urn:x:B\nF[∀urn:x:r.urn:x:B] ⊑ I[∀urn:x:r.urn:x:B]\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("a filler is canonical before it is keyed: the named ∀ sorts after ≥2"), SLOP_STR(":r a owl:TransitiveProperty .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom [ owl:intersectionOf ( [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :B ] [ a owl:Restriction ; owl:onProperty :s ; owl:minQualifiedCardinality 2 ; owl:onClass :C ] ) ] ] ."), SLOP_STR("urn:x:A ⊑ I[∀urn:x:r.(≥2 urn:x:s.urn:x:C ⊓ I[∀urn:x:r.urn:x:B])]\nI[∀urn:x:r.urn:x:B] ⊑ ∀urn:x:r.F[∀urn:x:r.urn:x:B]\nI[∀urn:x:r.(≥2 urn:x:s.urn:x:C ⊓ I[∀urn:x:r.urn:x:B])] ⊑ ∀urn:x:r.F[∀urn:x:r.(≥2 urn:x:s.urn:x:C ⊓ I[∀urn:x:r.urn:x:B])]\nF[∀urn:x:r.urn:x:B] ⊑ urn:x:B\nF[∀urn:x:r.urn:x:B] ⊑ I[∀urn:x:r.urn:x:B]\nF[∀urn:x:r.(≥2 urn:x:s.urn:x:C ⊓ I[∀urn:x:r.urn:x:B])] ⊑ (≥2 urn:x:s.urn:x:C ⊓ I[∀urn:x:r.urn:x:B])\nF[∀urn:x:r.(≥2 urn:x:s.urn:x:C ⊓ I[∀urn:x:r.urn:x:B])] ⊑ I[∀urn:x:r.(≥2 urn:x:s.urn:x:C ⊓ I[∀urn:x:r.urn:x:B])]\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("transitive: a positive ∀ becomes I, F and the automaton (items 1, 5)"), SLOP_STR(":r a owl:TransitiveProperty .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :B ] ."), SLOP_STR("urn:x:A ⊑ I[∀urn:x:r.urn:x:B]\nI[∀urn:x:r.urn:x:B] ⊑ ∀urn:x:r.F[∀urn:x:r.urn:x:B]\nF[∀urn:x:r.urn:x:B] ⊑ urn:x:B\nF[∀urn:x:r.urn:x:B] ⊑ I[∀urn:x:r.urn:x:B]\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("a domain on a transitive role: a negative ∃ (Definition 6's ∃ case)"), SLOP_STR(":r a owl:TransitiveProperty ; rdfs:domain :A ."), SLOP_STR("⊤ ⊑ I[∃urn:x:r.⊤]\nI[∃urn:x:r.⊤] ⊑ ∀urn:x:r⁻.F[∃urn:x:r.⊤]\nF[∃urn:x:r.⊤] ⊑ urn:x:A\nF[∃urn:x:r.⊤] ⊑ I[∃urn:x:r.⊤]\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("a range on a transitive role: ⊤ ⊑ ∀r.A"), SLOP_STR(":r a owl:TransitiveProperty ; rdfs:range :A ."), SLOP_STR("⊤ ⊑ I[∀urn:x:r.urn:x:A]\nI[∀urn:x:r.urn:x:A] ⊑ ∀urn:x:r.F[∀urn:x:r.urn:x:A]\nF[∀urn:x:r.urn:x:A] ⊑ urn:x:A\nF[∀urn:x:r.urn:x:A] ⊑ I[∀urn:x:r.urn:x:A]\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("symmetric and transitive: expanded both ways, one pair"), SLOP_STR(":r a owl:TransitiveProperty , owl:SymmetricProperty .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :B ] ."), SLOP_STR("urn:x:A ⊑ I[∀urn:x:r.urn:x:B]\nI[∀urn:x:r.urn:x:B] ⊑ ∀urn:x:r.F[∀urn:x:r.urn:x:B]\nI[∀urn:x:r.urn:x:B] ⊑ ∀urn:x:r⁻.F[∀urn:x:r.urn:x:B]\nF[∀urn:x:r.urn:x:B] ⊑ urn:x:B\nF[∀urn:x:r.urn:x:B] ⊑ I[∀urn:x:r.urn:x:B]\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("a negative assertion on a transitive role"), SLOP_STR(":r a owl:TransitiveProperty .\n[] a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; owl:assertionProperty :r ; owl:targetIndividual :b ."), SLOP_STR("{urn:x:a} ⊑ I[∀urn:x:r.¬{urn:x:b}]\nI[∀urn:x:r.¬{urn:x:b}] ⊑ ∀urn:x:r.F[∀urn:x:r.¬{urn:x:b}]\nF[∀urn:x:r.¬{urn:x:b}] ⊑ ¬{urn:x:b}\nF[∀urn:x:r.¬{urn:x:b}] ⊑ I[∀urn:x:r.¬{urn:x:b}]\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("Ref on a transitive role is kept"), SLOP_STR(":r a owl:TransitiveProperty , owl:ReflexiveProperty .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :B ] ."), SLOP_STR("urn:x:A ⊑ I[∀urn:x:r.urn:x:B]\nI[∀urn:x:r.urn:x:B] ⊑ ∀urn:x:r.F[∀urn:x:r.urn:x:B]\nF[∀urn:x:r.urn:x:B] ⊑ urn:x:B\nF[∀urn:x:r.urn:x:B] ⊑ I[∀urn:x:r.urn:x:B]\nRef(urn:x:r)\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("a sub-role into a transitive role: item 2 keeps it (R1, length 1)"), SLOP_STR(":r a owl:TransitiveProperty .\n:s rdfs:subPropertyOf :r .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :B ] ."), SLOP_STR("urn:x:A ⊑ I[∀urn:x:r.urn:x:B]\nI[∀urn:x:r.urn:x:B] ⊑ ∀urn:x:r.F[∀urn:x:r.urn:x:B]\nI[∀urn:x:r.urn:x:B] ⊑ ∀urn:x:s.F[∀urn:x:r.urn:x:B]\nF[∀urn:x:r.urn:x:B] ⊑ urn:x:B\nF[∀urn:x:r.urn:x:B] ⊑ I[∀urn:x:r.urn:x:B]\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("a chain into its first role: item 3 (R2)"), SLOP_STR(":r owl:propertyChainAxiom ( :r :s ) .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :B ] ."), SLOP_STR("urn:x:A ⊑ I[∀urn:x:r.urn:x:B]\nI[∀urn:x:r.urn:x:B] ⊑ ∀urn:x:r.F[∀urn:x:r.urn:x:B]\nF[∀urn:x:r.urn:x:B] ⊑ urn:x:B\nF[∀urn:x:r.urn:x:B] ⊑ ∀urn:x:s.F[∀urn:x:r.urn:x:B]\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("a chain into its last role: item 4 (R3)"), SLOP_STR(":r owl:propertyChainAxiom ( :s :r ) .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :B ] ."), SLOP_STR("urn:x:A ⊑ I[∀urn:x:r.urn:x:B]\nI[∀urn:x:r.urn:x:B] ⊑ ∀urn:x:r.F[∀urn:x:r.urn:x:B]\nI[∀urn:x:r.urn:x:B] ⊑ ∀urn:x:s.I[∀urn:x:r.urn:x:B]\nF[∀urn:x:r.urn:x:B] ⊑ urn:x:B\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("a chain into a third role: item 2 (R1)"), SLOP_STR(":t owl:propertyChainAxiom ( :r :s ) .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :t ; owl:allValuesFrom :B ] ."), SLOP_STR("urn:x:A ⊑ I[∀urn:x:t.urn:x:B]\nI[∀urn:x:t.urn:x:B] ⊑ ∀urn:x:r.∀urn:x:s.F[∀urn:x:t.urn:x:B]\nI[∀urn:x:t.urn:x:B] ⊑ ∀urn:x:t.F[∀urn:x:t.urn:x:B]\nF[∀urn:x:t.urn:x:B] ⊑ urn:x:B\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("≤n's filler is negative: its ∃ on a transitive role is labelled"), SLOP_STR(":r a owl:TransitiveProperty .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :s ; owl:maxQualifiedCardinality 1 ; owl:onClass [ a owl:Restriction ; owl:onProperty :r ; owl:someValuesFrom :B ] ] ."), SLOP_STR("urn:x:A ⊑ ≤1 urn:x:s.F[∃urn:x:r.urn:x:B]\nurn:x:B ⊑ I[∃urn:x:r.urn:x:B]\nI[∃urn:x:r.urn:x:B] ⊑ ∀urn:x:r⁻.F[∃urn:x:r.urn:x:B]\nF[∃urn:x:r.urn:x:B] ⊑ I[∃urn:x:r.urn:x:B]\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("a positive ∃ on a transitive role is left alone"), SLOP_STR(":r a owl:TransitiveProperty .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:someValuesFrom :B ] ."), SLOP_STR("urn:x:A ⊑ ∃urn:x:r.urn:x:B\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("nested ∀∀: the inner one is named first"), SLOP_STR(":r a owl:TransitiveProperty .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :B ] ] ."), SLOP_STR("urn:x:A ⊑ I[∀urn:x:r.I[∀urn:x:r.urn:x:B]]\nI[∀urn:x:r.urn:x:B] ⊑ ∀urn:x:r.F[∀urn:x:r.urn:x:B]\nI[∀urn:x:r.I[∀urn:x:r.urn:x:B]] ⊑ ∀urn:x:r.F[∀urn:x:r.I[∀urn:x:r.urn:x:B]]\nF[∀urn:x:r.urn:x:B] ⊑ urn:x:B\nF[∀urn:x:r.urn:x:B] ⊑ I[∀urn:x:r.urn:x:B]\nF[∀urn:x:r.I[∀urn:x:r.urn:x:B]] ⊑ I[∀urn:x:r.urn:x:B]\nF[∀urn:x:r.I[∀urn:x:r.urn:x:B]] ⊑ I[∀urn:x:r.I[∀urn:x:r.urn:x:B]]\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("one pair for a repeated labelled concept"), SLOP_STR(":r a owl:TransitiveProperty .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :B ] .\n:C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :B ] ."), SLOP_STR("urn:x:A ⊑ I[∀urn:x:r.urn:x:B]\nurn:x:C ⊑ I[∀urn:x:r.urn:x:B]\nI[∀urn:x:r.urn:x:B] ⊑ ∀urn:x:r.F[∀urn:x:r.urn:x:B]\nF[∀urn:x:r.urn:x:B] ⊑ urn:x:B\nF[∀urn:x:r.urn:x:B] ⊑ I[∀urn:x:r.urn:x:B]\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("∀ and ∃ on the same (r, B) get different names"), SLOP_STR(":r a owl:TransitiveProperty .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :B ] .\n[ a owl:Restriction ; owl:onProperty :r ; owl:someValuesFrom :B ] rdfs:subClassOf :C ."), SLOP_STR("urn:x:A ⊑ I[∀urn:x:r.urn:x:B]\nurn:x:B ⊑ I[∃urn:x:r.urn:x:B]\nI[∀urn:x:r.urn:x:B] ⊑ ∀urn:x:r.F[∀urn:x:r.urn:x:B]\nF[∀urn:x:r.urn:x:B] ⊑ urn:x:B\nF[∀urn:x:r.urn:x:B] ⊑ I[∀urn:x:r.urn:x:B]\nI[∃urn:x:r.urn:x:B] ⊑ ∀urn:x:r⁻.F[∃urn:x:r.urn:x:B]\nF[∃urn:x:r.urn:x:B] ⊑ urn:x:C\nF[∃urn:x:r.urn:x:B] ⊑ I[∃urn:x:r.urn:x:B]\n")))) {
            ok = 0;
        }
        if (!(test_s1_is(arena, SLOP_STR("the bottom role's row is expanded like any other"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty owl:bottomObjectProperty ; owl:someValuesFrom :B ] ."), SLOP_STR("⊤ ⊑ I[∃http://www.w3.org/2002/07/owl#bottomObjectProperty.⊤]\nurn:x:A ⊑ ∃http://www.w3.org/2002/07/owl#bottomObjectProperty.urn:x:B\nI[∃http://www.w3.org/2002/07/owl#bottomObjectProperty.⊤] ⊑ ∀http://www.w3.org/2002/07/owl#bottomObjectProperty⁻.F[∃http://www.w3.org/2002/07/owl#bottomObjectProperty.⊤]\nF[∃http://www.w3.org/2002/07/owl#bottomObjectProperty.⊤] ⊑ ⊥\n")))) {
            ok = 0;
        }
        return ok;
    }
}

uint8_t test_s1_invariants_hold(slop_arena* arena, slop_string path) {
    __auto_type _mv_1526 = test_gate_fixture_in(arena, path, types_Profile_profile_sriq);
    if (!_mv_1526.has_value) {
        printf("%s", "  [s1] did not gate: ");
        printf("%.*s\n", (int)(path).len, (path).data);
        return 0;
    } else if (_mv_1526.has_value) {
        __auto_type gr = _mv_1526.value;
        __auto_type _mv_1527 = sriqnormal_sriq_s0(arena, gr.accepted);
        if (!_mv_1527.is_ok) {
            __auto_type m = _mv_1527.data.err;
            printf("%s", "  [s1] S0 refused: ");
            printf("%.*s\n", (int)(m).len, (m).data);
            return 0;
        } else if (_mv_1527.is_ok) {
            __auto_type s0 = _mv_1527.data.ok;
            __auto_type _mv_1528 = sriqelim_sriq_s1(arena, s0, sriqelim_S1_BOUND);
            if (!_mv_1528.is_ok) {
                __auto_type m = _mv_1528.data.err;
                printf("%s", "  [s1] refused: ");
                printf("%.*s\n", (int)(m).len, (m).data);
                return 0;
            } else if (_mv_1528.is_ok) {
                __auto_type s1 = _mv_1528.data.ok;
                return test_print_problems(path, sriqelim_sriq_s1_invariants(arena, s0.rbox, s0.axioms, s1));
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_print_problems(slop_string path, slop_list_string bad) {
    if (((int64_t)((bad).len)) == 0) {
        return 1;
    } else {
        printf("%s", "  [s1] ");
        printf("%.*s\n", (int)(path).len, (path).data);
        {
            __auto_type _coll = bad;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                printf("%s", "    ");
                printf("%.*s\n", (int)(b).len, (b).data);
            }
        }
        return 0;
    }
}

uint8_t test_test_sriq_s1_invariants(slop_arena* arena) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = test_sriq_fixtures(arena);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (!(test_s1_invariants_hold(arena, p))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t test_test_sriq_s2_refuses_a_count_past_the_bound(slop_arena* arena) {
    {
        __auto_type a = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_name, .data.sc_name = ((rdf_IRI){.value = SLOP_STR("urn:x:A")}) });
        __auto_type r = ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = ((rdf_IRI){.value = SLOP_STR("urn:x:r")}) });
        __auto_type axs = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(axs); __auto_type _item = (((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_gci, .data.sa_gci = { .f0 = sroiq_box_sc(arena, a), .f1 = sroiq_box_sc(arena, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = 17, .f1 = r, .f2 = sroiq_box_sc(arena, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_top })) } })) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_1529 = sriqnormal_sriq_s2(arena, axs);
        if (_mv_1529.is_ok) {
            __auto_type _ = _mv_1529.data.ok;
            return 0;
        } else if (!_mv_1529.is_ok) {
            __auto_type _ = _mv_1529.data.err;
            return 1;
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_test_sriq_s2_rows(slop_arena* arena) {
    {
        uint8_t ok = 1;
        if (!(test_s2_is(arena, SLOP_STR("a name below a name"), SLOP_STR(":A rdfs:subClassOf :B ."), SLOP_STR("DL1 urn:x:A ⊑ urn:x:B\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("a conjunction on the right is a disjunct, so named"), SLOP_STR(":A rdfs:subClassOf [ owl:intersectionOf ( :B :C ) ] ."), SLOP_STR("DL1 A[(urn:x:B ⊓ urn:x:C)] ⊑ urn:x:B\nDL1 A[(urn:x:B ⊓ urn:x:C)] ⊑ urn:x:C\nDL1 urn:x:A ⊑ A[(urn:x:B ⊓ urn:x:C)]\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("a top-level conjunction is split (choice 3)"), SLOP_STR("owl:Thing rdfs:subClassOf [ owl:intersectionOf ( :B :C ) ] ."), SLOP_STR("DL1 ⊤ ⊑ urn:x:B\nDL1 ⊤ ⊑ urn:x:C\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("a disjunction is one DL1"), SLOP_STR(":A rdfs:subClassOf [ owl:unionOf ( :B :C ) ] ."), SLOP_STR("DL1 urn:x:A ⊑ urn:x:B ⊔ urn:x:C\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("a conjunction on the left is the body"), SLOP_STR("[ owl:intersectionOf ( :A :B ) ] rdfs:subClassOf :C ."), SLOP_STR("DL1 urn:x:A ⊓ urn:x:B ⊑ urn:x:C\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("a negation is the body"), SLOP_STR(":A rdfs:subClassOf [ owl:complementOf :B ] ."), SLOP_STR("DL1 urn:x:A ⊓ urn:x:B ⊑ ⊥\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("bottom on the right"), SLOP_STR(":A rdfs:subClassOf owl:Nothing ."), SLOP_STR("DL1 urn:x:A ⊑ ⊥\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("top on the left"), SLOP_STR("owl:Thing rdfs:subClassOf :A ."), SLOP_STR("DL1 ⊤ ⊑ urn:x:A\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("a tautology emits nothing"), SLOP_STR(":A rdfs:subClassOf owl:Thing ."), SLOP_STR("")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("exists: DL1 then DL2, no shortcut"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:someValuesFrom :B ] ."), SLOP_STR("DL1 urn:x:A ⊑ A[∃urn:x:r.urn:x:B]\nDL2 A[∃urn:x:r.urn:x:B] ⊑ ≥1 urn:x:r.urn:x:B\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("exists top: DL2 keeps its filler as top"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:someValuesFrom owl:Thing ] ."), SLOP_STR("DL1 urn:x:A ⊑ A[∃urn:x:r.⊤]\nDL2 A[∃urn:x:r.⊤] ⊑ ≥1 urn:x:r.⊤\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("at least 2"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:minQualifiedCardinality 2 ; owl:onClass :B ] ."), SLOP_STR("DL1 urn:x:A ⊑ A[≥2 urn:x:r.urn:x:B]\nDL2 A[≥2 urn:x:r.urn:x:B] ⊑ ≥2 urn:x:r.urn:x:B\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("exists on an inverse uses bar"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty [ owl:inverseOf :r ] ; owl:someValuesFrom :B ] ."), SLOP_STR("DL1 urn:x:A ⊑ A[∃urn:x:r⁻.urn:x:B]\nDL2 A[∃urn:x:r⁻.urn:x:B] ⊑ ≥1 bar(urn:x:r).urn:x:B\nDL8 bar(urn:x:r) ⊑ urn:x:r⁻\nDL8 urn:x:r ⊑ bar(urn:x:r)⁻\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("forall is DL3 over inv(R), so bar"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :B ] ."), SLOP_STR("DL1 urn:x:A ⊑ A[∀urn:x:r.urn:x:B]\nDL3 ∃bar(urn:x:r).A[∀urn:x:r.urn:x:B] ⊑ urn:x:B\nDL8 bar(urn:x:r) ⊑ urn:x:r⁻\nDL8 urn:x:r ⊑ bar(urn:x:r)⁻\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("forall on an inverse needs no bar"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty [ owl:inverseOf :r ] ; owl:allValuesFrom :B ] ."), SLOP_STR("DL1 urn:x:A ⊑ A[∀urn:x:r⁻.urn:x:B]\nDL3 ∃urn:x:r.A[∀urn:x:r⁻.urn:x:B] ⊑ urn:x:B\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("forall with a negated filler"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty [ owl:inverseOf :r ] ; owl:allValuesFrom [ owl:complementOf :B ] ] ."), SLOP_STR("DL1 A[¬urn:x:B] ⊓ urn:x:B ⊑ ⊥\nDL1 urn:x:A ⊑ A[∀urn:x:r⁻.¬urn:x:B]\nDL3 ∃urn:x:r.A[∀urn:x:r⁻.¬urn:x:B] ⊑ A[¬urn:x:B]\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("at most: DL4 with S_{r,B}"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:maxQualifiedCardinality 2 ; owl:onClass :B ] ."), SLOP_STR("DL1 urn:x:A ⊑ A[≤2 urn:x:r.urn:x:B]\nDL4 A[≤2 urn:x:r.urn:x:B] ⊑ ≤2 urn:x:r.urn:x:B via S_{urn:x:r,urn:x:B}\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("S1's names are S2's names, never defined"), SLOP_STR(":r a owl:TransitiveProperty .\n:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :B ] ."), SLOP_STR("DL1 F[∀urn:x:r.urn:x:B] ⊑ I[∀urn:x:r.urn:x:B]\nDL1 F[∀urn:x:r.urn:x:B] ⊑ urn:x:B\nDL1 I[∀urn:x:r.urn:x:B] ⊑ A[∀urn:x:r.F[∀urn:x:r.urn:x:B]]\nDL1 urn:x:A ⊑ I[∀urn:x:r.urn:x:B]\nDL3 ∃bar(urn:x:r).A[∀urn:x:r.F[∀urn:x:r.urn:x:B]] ⊑ F[∀urn:x:r.urn:x:B]\nDL8 bar(urn:x:r) ⊑ urn:x:r⁻\nDL8 urn:x:r ⊑ bar(urn:x:r)⁻\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("two fillers on one role get two S roles"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:maxQualifiedCardinality 1 ; owl:onClass :B ] .\n:C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:maxQualifiedCardinality 1 ; owl:onClass :C ] ."), SLOP_STR("DL1 urn:x:A ⊑ A[≤1 urn:x:r.urn:x:B]\nDL1 urn:x:C ⊑ A[≤1 urn:x:r.urn:x:C]\nDL4 A[≤1 urn:x:r.urn:x:B] ⊑ ≤1 urn:x:r.urn:x:B via S_{urn:x:r,urn:x:B}\nDL4 A[≤1 urn:x:r.urn:x:C] ⊑ ≤1 urn:x:r.urn:x:C via S_{urn:x:r,urn:x:C}\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("at most over a union: the filler named above"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:maxQualifiedCardinality 1 ; owl:onClass [ owl:unionOf ( :B :C ) ] ] ."), SLOP_STR("DL1 A[(¬urn:x:B ⊓ ¬urn:x:C)] ⊓ urn:x:B ⊑ ⊥\nDL1 A[(¬urn:x:B ⊓ ¬urn:x:C)] ⊓ urn:x:C ⊑ ⊥\nDL1 urn:x:A ⊑ A[≤1 urn:x:r.(urn:x:B ⊔ urn:x:C)]\nDL1 ⊤ ⊑ A[(urn:x:B ⊔ urn:x:C)] ⊔ A[(¬urn:x:B ⊓ ¬urn:x:C)]\nDL4 A[≤1 urn:x:r.(urn:x:B ⊔ urn:x:C)] ⊑ ≤1 urn:x:r.A[(urn:x:B ⊔ urn:x:C)] via S_{urn:x:r,A[(urn:x:B ⊔ urn:x:C)]}\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("exactly 2: at least and at most"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:qualifiedCardinality 2 ; owl:onClass :B ] ."), SLOP_STR("DL1 urn:x:A ⊑ A[(≥2 urn:x:r.urn:x:B ⊓ ≤2 urn:x:r.urn:x:B)]\nDL2 A[(≥2 urn:x:r.urn:x:B ⊓ ≤2 urn:x:r.urn:x:B)] ⊑ ≥2 urn:x:r.urn:x:B\nDL4 A[(≥2 urn:x:r.urn:x:B ⊓ ≤2 urn:x:r.urn:x:B)] ⊑ ≤2 urn:x:r.urn:x:B via S_{urn:x:r,urn:x:B}\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("a nested conjunction is named once"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:someValuesFrom [ owl:intersectionOf ( :B :C ) ] ] .\n:B rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :s ; owl:someValuesFrom [ owl:intersectionOf ( :C :B ) ] ] ."), SLOP_STR("DL1 A[(urn:x:B ⊓ urn:x:C)] ⊑ urn:x:B\nDL1 A[(urn:x:B ⊓ urn:x:C)] ⊑ urn:x:C\nDL1 urn:x:A ⊑ A[∃urn:x:r.(urn:x:B ⊓ urn:x:C)]\nDL1 urn:x:B ⊑ A[∃urn:x:s.(urn:x:B ⊓ urn:x:C)]\nDL2 A[∃urn:x:r.(urn:x:B ⊓ urn:x:C)] ⊑ ≥1 urn:x:r.A[(urn:x:B ⊓ urn:x:C)]\nDL2 A[∃urn:x:s.(urn:x:B ⊓ urn:x:C)] ⊑ ≥1 urn:x:s.A[(urn:x:B ⊓ urn:x:C)]\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("exists on the left"), SLOP_STR("[ a owl:Restriction ; owl:onProperty :r ; owl:someValuesFrom :B ] rdfs:subClassOf :A ."), SLOP_STR("DL1 A[¬urn:x:B] ⊓ urn:x:B ⊑ ⊥\nDL1 ⊤ ⊑ urn:x:A ⊔ A[∀urn:x:r.¬urn:x:B]\nDL3 ∃bar(urn:x:r).A[∀urn:x:r.¬urn:x:B] ⊑ A[¬urn:x:B]\nDL8 bar(urn:x:r) ⊑ urn:x:r⁻\nDL8 urn:x:r ⊑ bar(urn:x:r)⁻\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("domain"), SLOP_STR(":r rdfs:domain :A ."), SLOP_STR("DL1 A[⊥] ⊑ ⊥\nDL1 ⊤ ⊑ urn:x:A ⊔ A[∀urn:x:r.⊥]\nDL3 ∃bar(urn:x:r).A[∀urn:x:r.⊥] ⊑ A[⊥]\nDL8 bar(urn:x:r) ⊑ urn:x:r⁻\nDL8 urn:x:r ⊑ bar(urn:x:r)⁻\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("range"), SLOP_STR(":r rdfs:range :A ."), SLOP_STR("DL1 ⊤ ⊑ A[∀urn:x:r.urn:x:A]\nDL3 ∃bar(urn:x:r).A[∀urn:x:r.urn:x:A] ⊑ urn:x:A\nDL8 bar(urn:x:r) ⊑ urn:x:r⁻\nDL8 urn:x:r ⊑ bar(urn:x:r)⁻\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("Self"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasSelf true ] ."), SLOP_STR("DL1 urn:x:A ⊑ A[∃urn:x:r.Self]\nDL5 A[∃urn:x:r.Self] ⊑ ∃urn:x:r.Self\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("Ref: top below a Self name"), SLOP_STR(":r a owl:ReflexiveProperty ."), SLOP_STR("DL1 ⊤ ⊑ A[∃urn:x:r.Self]\nDL5 A[∃urn:x:r.Self] ⊑ ∃urn:x:r.Self\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("Irr: DL6 and a DL1 to bottom"), SLOP_STR(":r a owl:IrreflexiveProperty ."), SLOP_STR("DL1 A[∃urn:x:r.Self] ⊑ ⊥\nDL6 ∃urn:x:r.Self ⊑ A[∃urn:x:r.Self]\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("Ref and Irr share one name"), SLOP_STR(":r a owl:ReflexiveProperty , owl:IrreflexiveProperty ."), SLOP_STR("DL1 A[∃urn:x:r.Self] ⊑ ⊥\nDL1 ⊤ ⊑ A[∃urn:x:r.Self]\nDL5 A[∃urn:x:r.Self] ⊑ ∃urn:x:r.Self\nDL6 ∃urn:x:r.Self ⊑ A[∃urn:x:r.Self]\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("functional: DL4 at most 1 with top"), SLOP_STR(":r a owl:FunctionalProperty ."), SLOP_STR("DL1 ⊤ ⊑ A[≤1 urn:x:r.⊤]\nDL4 A[≤1 urn:x:r.⊤] ⊑ ≤1 urn:x:r.⊤ via S_{urn:x:r,⊤}\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("inverse functional uses bar"), SLOP_STR(":r a owl:InverseFunctionalProperty ."), SLOP_STR("DL1 ⊤ ⊑ A[≤1 urn:x:r⁻.⊤]\nDL4 A[≤1 urn:x:r⁻.⊤] ⊑ ≤1 bar(urn:x:r).⊤ via S_{bar(urn:x:r),⊤}\nDL8 bar(urn:x:r) ⊑ urn:x:r⁻\nDL8 urn:x:r ⊑ bar(urn:x:r)⁻\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("a role inclusion is DL7"), SLOP_STR(":r rdfs:subPropertyOf :s ."), SLOP_STR("DL7 urn:x:r ⊑ urn:x:s\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("into an inverse is DL8"), SLOP_STR(":r rdfs:subPropertyOf [ owl:inverseOf :s ] ."), SLOP_STR("DL8 urn:x:r ⊑ urn:x:s⁻\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("symmetry is DL8 to itself"), SLOP_STR(":r a owl:SymmetricProperty ."), SLOP_STR("DL8 urn:x:r ⊑ urn:x:r⁻\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("disjoint properties"), SLOP_STR(":r owl:propertyDisjointWith :s ."), SLOP_STR("DL9 Disj(urn:x:r, urn:x:s)\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("asymmetry is DL9 with bar"), SLOP_STR(":r a owl:AsymmetricProperty ."), SLOP_STR("DL8 bar(urn:x:r) ⊑ urn:x:r⁻\nDL8 urn:x:r ⊑ bar(urn:x:r)⁻\nDL9 Disj(urn:x:r, bar(urn:x:r))\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("a class assertion: DL10 then DL1"), SLOP_STR(":a a :A ."), SLOP_STR("DL1 A[{urn:x:a}] ⊑ urn:x:A\nDL10 {urn:x:a} ⊑ A[{urn:x:a}]\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("a property assertion: DL10, DL1, DL2, DL11"), SLOP_STR(":a :r :b ."), SLOP_STR("DL1 A[{urn:x:a}] ⊑ A[∃urn:x:r.{urn:x:b}]\nDL10 {urn:x:a} ⊑ A[{urn:x:a}]\nDL11 A[{urn:x:b}] ⊑ {urn:x:b}\nDL2 A[∃urn:x:r.{urn:x:b}] ⊑ ≥1 urn:x:r.A[{urn:x:b}]\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("a negative assertion: DL10, DL1, DL3, DL1"), SLOP_STR("[ a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; owl:assertionProperty :r ; owl:targetIndividual :b ] ."), SLOP_STR("DL1 A[{urn:x:a}] ⊑ A[∀urn:x:r.¬{urn:x:b}]\nDL1 A[¬{urn:x:b}] ⊓ A[{urn:x:b}] ⊑ ⊥\nDL10 {urn:x:a} ⊑ A[{urn:x:a}]\nDL10 {urn:x:b} ⊑ A[{urn:x:b}]\nDL3 ∃bar(urn:x:r).A[∀urn:x:r.¬{urn:x:b}] ⊑ A[¬{urn:x:b}]\nDL8 bar(urn:x:r) ⊑ urn:x:r⁻\nDL8 urn:x:r ⊑ bar(urn:x:r)⁻\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("SameIndividual: one name per nominal, both ways"), SLOP_STR(":a owl:sameAs :b ."), SLOP_STR("DL1 A[{urn:x:a}] ⊑ A[{urn:x:b}]\nDL1 A[{urn:x:b}] ⊑ A[{urn:x:a}]\nDL10 {urn:x:a} ⊑ A[{urn:x:a}]\nDL10 {urn:x:b} ⊑ A[{urn:x:b}]\nDL11 A[{urn:x:a}] ⊑ {urn:x:a}\nDL11 A[{urn:x:b}] ⊑ {urn:x:b}\n")))) {
            ok = 0;
        }
        if (!(test_s2_is(arena, SLOP_STR("DifferentIndividuals"), SLOP_STR(":a owl:differentFrom :b ."), SLOP_STR("DL1 A[{urn:x:a}] ⊓ A[{urn:x:b}] ⊑ ⊥\nDL10 {urn:x:a} ⊑ A[{urn:x:a}]\nDL10 {urn:x:b} ⊑ A[{urn:x:b}]\n")))) {
            ok = 0;
        }
        return ok;
    }
}

rdf_IRI test_x_iri(slop_arena* arena, slop_string local) {
    return ((rdf_IRI){.value = string_concat(arena, SLOP_STR("urn:x:"), local)});
}

types_DName test_dn(slop_arena* arena, slop_string local) {
    return ((types_DName){ .tag = types_DName_dn_class, .data.dn_class = test_x_iri(arena, local) });
}

types_DRole test_dp(slop_arena* arena, slop_string local) {
    return ((types_DRole){ .tag = types_DRole_dr_prop, .data.dr_prop = test_x_iri(arena, local) });
}

slop_list_rdf_IRI test_iris_of(slop_arena* arena, slop_list_string locals) {
    {
        __auto_type out = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = locals;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (test_x_iri(arena, l)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_string test_strs(slop_arena* arena, slop_string text) {
    {
        __auto_type n = ((int64_t)(string_len(text)));
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t start = 0;
        int64_t i = 0;
        while (i <= n) {
            if ((i == n) || (((int64_t)(strlib_char_at(text, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at test.slop:3289:60")))) == 32)) {
                if (i > start) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (strlib_substring(arena, text, ((int64_t)(SLOP_RANGE(int64_t, start, 1, 0, 0, 0, "(Int 0 ..) at test.slop:3290:91"))), ((int64_t)(SLOP_RANGE(int64_t, (i - start), 1, 0, 0, 0, "(Int 0 ..) at test.slop:3290:115"))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                start = (i + 1);
            }
            i = (i + 1);
        }
        return out;
    }
}

slop_list_string test_line1(slop_arena* arena, slop_string text) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (text); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

sriqnames_SriqNormal test_row_normal(slop_arena* arena, slop_list_types_DlClause cs, int64_t nfresh, int64_t nsub, int64_t nfns) {
    {
        slop_option_types_DName top_filler = (slop_option_types_DName){.has_value = false};
        __auto_type concepts = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type sroles = ((slop_list_types_DRole){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type sfills = ((slop_list_option_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        while (k < nfresh) {
            ({ __auto_type _lst_p = &(concepts); __auto_type _item = (((sroiq_SConcept){ .tag = sroiq_SConcept_sc_top })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            k = (k + 1);
        }
        k = 0;
        while (k < nsub) {
            ({ __auto_type _lst_p = &(sroles); __auto_type _item = (test_dp(arena, SLOP_STR("r"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(sfills); __auto_type _item = (top_filler); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            k = (k + 1);
        }
        return ((sriqnames_SriqNormal){.clauses = cs, .concepts = concepts, .sroles = sroles, .sfills = sfills, .bars = test_iris_of(arena, test_strs(arena, SLOP_STR("s"))), .fns = ((int64_t)(SLOP_RANGE(int64_t, nfns, 1, 0, 0, 0, "(Int 0 ..) at test.slop:3320:41"))), .classes = test_iris_of(arena, test_strs(arena, SLOP_STR("A B C"))), .individuals = test_iris_of(arena, test_strs(arena, SLOP_STR("a b"))), .omitted = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
    }
}

slop_string test_clause_text(slop_arena* arena, sriqnames_SriqNormal n) {
    __auto_type _mv_1530 = sriqclauses_sriq_clauses(arena, n);
    if (!_mv_1530.is_ok) {
        __auto_type m = _mv_1530.data.err;
        return string_concat(arena, SLOP_STR("error: "), m);
    } else if (_mv_1530.is_ok) {
        __auto_type sc = _mv_1530.data.ok;
        {
            __auto_type out = SLOP_STR("");
            {
                __auto_type _coll = sriqclauses_render_clauses(arena, sc);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type l = _coll.data[_i];
                    out = string_concat(arena, out, string_concat(arena, l, SLOP_STR("\n")));
                }
            }
            return out;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_clauses_sound(slop_arena* arena, sriqnames_SriqNormal n) {
    __auto_type _mv_1531 = sriqclauses_sriq_clauses(arena, n);
    if (!_mv_1531.is_ok) {
        __auto_type _ = _mv_1531.data.err;
        return 0;
    } else if (_mv_1531.is_ok) {
        __auto_type sc = _mv_1531.data.ok;
        {
            uint8_t ok = (((int64_t)((sriqclauses_ids_dense(arena, sc)).len)) == 0);
            {
                __auto_type _coll = sc.clauses;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    if (!((sriqclauses_dl_clause_shape(c) && sriqclauses_clause_canonical(c)))) {
                        ok = 0;
                    }
                }
            }
            return ok;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_table1_is(slop_arena* arena, slop_string label, sriqnames_SriqNormal n, slop_string want) {
    {
        __auto_type got = test_clause_text(arena, n);
        if (!(string_eq(got, want))) {
            printf("%s", "  [table 1] ");
            printf("%.*s", (int)(label).len, (label).data);
            printf("%s\n", ", got:");
            printf("%.*s", (int)(got).len, (got).data);
            return 0;
        } else if (!(test_clauses_sound(arena, n))) {
            printf("%s", "  [table 1] ");
            printf("%.*s", (int)(label).len, (label).data);
            printf("%s\n", ": not a DL-clause, or an id out of range");
            return 0;
        } else {
            return 1;
        }
    }
}

slop_list_types_DlClause test_one_dl(slop_arena* arena, types_DlClause c) {
    {
        __auto_type out = ((slop_list_types_DlClause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

types_DlClause test_dl1_of(slop_arena* arena, slop_string body, slop_string head) {
    {
        __auto_type b = ((slop_list_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type h = ((slop_list_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = test_strs(arena, body);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type w = _coll.data[_i];
                ({ __auto_type _lst_p = &(b); __auto_type _item = (((string_eq(w, SLOP_STR("A0"))) ? ((types_DName){ .tag = types_DName_dn_fresh, .data.dn_fresh = 0 }) : test_dn(arena, w))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = test_strs(arena, head);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type w = _coll.data[_i];
                ({ __auto_type _lst_p = &(h); __auto_type _item = (((string_eq(w, SLOP_STR("A0"))) ? ((types_DName){ .tag = types_DName_dn_fresh, .data.dn_fresh = 0 }) : test_dn(arena, w))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((types_DlClause){ .tag = types_DlClause_dl1, .data.dl1 = ((types_Dl1){.body = b, .head = h}) });
    }
}

slop_list_int test_fn_ids(slop_arena* arena, int64_t n) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < n) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (((int64_t)(SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at test.slop:3381:62")))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        return out;
    }
}

types_DlClause test_dl4_of(slop_arena* arena, slop_string sub, int64_t n, slop_option_types_DName filler) {
    return ((types_DlClause){ .tag = types_DlClause_dl4, .data.dl4 = ((types_Dl4){.sub = test_dn(arena, sub), .role = test_dp(arena, SLOP_STR("r")), .count = ((int64_t)(SLOP_RANGE(int64_t, n, 1, 0, 0, 0, "(Int 0 ..) at test.slop:3387:112"))), .filler = filler, .srole = ((types_DRole){ .tag = types_DRole_dr_sub, .data.dr_sub = 0 })}) });
}

types_DlClause test_dl2_of(slop_arena* arena, slop_string sub, types_DRole role, int64_t n, slop_option_types_DName filler) {
    return ((types_DlClause){ .tag = types_DlClause_dl2, .data.dl2 = ((types_Dl2){.sub = test_dn(arena, sub), .role = role, .count = ((int64_t)(SLOP_RANGE(int64_t, n, 1, 0, 1, 0, "(Int 1 ..) at test.slop:3394:102"))), .filler = filler, .fns = test_fn_ids(arena, n)}) });
}

uint8_t test_table1_rows_names(slop_arena* arena) {
    {
        __auto_type bar_s = ((types_DRole){ .tag = types_DRole_dr_bar, .data.dr_bar = test_x_iri(arena, SLOP_STR("s")) });
        uint8_t ok = 1;
        if (!(test_table1_is(arena, SLOP_STR("DL1"), test_row_normal(arena, test_one_dl(arena, test_dl1_of(arena, SLOP_STR("A B"), SLOP_STR("C A0"))), 1, 0, 0), SLOP_STR("urn:x:A(x) ∧ urn:x:B(x) → urn:x:C(x) ∨ A0(x)\n")))) {
            ok = 0;
        }
        if (!(test_table1_is(arena, SLOP_STR("DL1, empty body"), test_row_normal(arena, test_one_dl(arena, test_dl1_of(arena, SLOP_STR(""), SLOP_STR("B A"))), 0, 0, 0), SLOP_STR("⊤ → urn:x:A(x) ∨ urn:x:B(x)\n")))) {
            ok = 0;
        }
        if (!(test_table1_is(arena, SLOP_STR("DL1, empty head"), test_row_normal(arena, test_one_dl(arena, test_dl1_of(arena, SLOP_STR("C A"), SLOP_STR(""))), 0, 0, 0), SLOP_STR("urn:x:A(x) ∧ urn:x:C(x) → ⊥\n")))) {
            ok = 0;
        }
        if (!(test_table1_is(arena, SLOP_STR("DL2, n = 3"), test_row_normal(arena, test_one_dl(arena, test_dl2_of(arena, SLOP_STR("A"), test_dp(arena, SLOP_STR("r")), 3, (slop_option_types_DName){.has_value = 1, .value = test_dn(arena, SLOP_STR("B"))})), 0, 0, 3), SLOP_STR("urn:x:A(x) → urn:x:B(f0(x))\nurn:x:A(x) → urn:x:B(f1(x))\nurn:x:A(x) → urn:x:B(f2(x))\nurn:x:A(x) → urn:x:r(x, f0(x))\nurn:x:A(x) → urn:x:r(x, f1(x))\nurn:x:A(x) → urn:x:r(x, f2(x))\nurn:x:A(x) → f1(x) ≉ f0(x)\nurn:x:A(x) → f2(x) ≉ f0(x)\nurn:x:A(x) → f2(x) ≉ f1(x)\n")))) {
            ok = 0;
        }
        if (!(test_table1_is(arena, SLOP_STR("DL2, filler ⊤, n = 2, over s̄"), test_row_normal(arena, test_one_dl(arena, test_dl2_of(arena, SLOP_STR("A"), bar_s, 2, ((slop_option_types_DName){.has_value = false}))), 0, 0, 2), SLOP_STR("urn:x:A(x) → urn:x:s^bar(x, f0(x))\nurn:x:A(x) → urn:x:s^bar(x, f1(x))\nurn:x:A(x) → f1(x) ≉ f0(x)\n")))) {
            ok = 0;
        }
        if (!(test_table1_is(arena, SLOP_STR("DL3"), test_row_normal(arena, test_one_dl(arena, ((types_DlClause){ .tag = types_DlClause_dl3, .data.dl3 = { .f0 = test_dp(arena, SLOP_STR("r")), .f1 = test_dn(arena, SLOP_STR("B")), .f2 = test_dn(arena, SLOP_STR("C")) } })), 0, 0, 0), SLOP_STR("urn:x:B(x) ∧ urn:x:r(z1, x) → urn:x:C(z1)\n")))) {
            ok = 0;
        }
        return ok;
    }
}

uint8_t test_table1_rows_dl4(slop_arena* arena) {
    {
        uint8_t ok = 1;
        __auto_type two = ((slop_list_types_DlClause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (!(test_table1_is(arena, SLOP_STR("DL4, n = 2"), test_row_normal(arena, test_one_dl(arena, test_dl4_of(arena, SLOP_STR("A"), 2, (slop_option_types_DName){.has_value = 1, .value = test_dn(arena, SLOP_STR("B"))})), 0, 1, 0), SLOP_STR("urn:x:A(x) ∧ S0(x, z1) ∧ S0(x, z2) ∧ S0(x, z3) → z2 ≈ z1 ∨ z3 ≈ z1 ∨ z3 ≈ z2\nurn:x:B(x) ∧ urn:x:r(z1, x) → S0(z1, x)\n")))) {
            ok = 0;
        }
        if (!(test_table1_is(arena, SLOP_STR("DL4, filler ⊤, n = 0"), test_row_normal(arena, test_one_dl(arena, test_dl4_of(arena, SLOP_STR("C"), 0, ((slop_option_types_DName){.has_value = false}))), 0, 1, 0), SLOP_STR("urn:x:C(x) ∧ S0(x, z1) → ⊥\nurn:x:r(z1, x) → S0(z1, x)\n")))) {
            ok = 0;
        }
        ({ __auto_type _lst_p = &(two); __auto_type _item = (test_dl4_of(arena, SLOP_STR("A"), 1, (slop_option_types_DName){.has_value = 1, .value = test_dn(arena, SLOP_STR("B"))})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(two); __auto_type _item = (test_dl4_of(arena, SLOP_STR("C"), 2, (slop_option_types_DName){.has_value = 1, .value = test_dn(arena, SLOP_STR("B"))})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        if (!(test_table1_is(arena, SLOP_STR("two DL4s sharing S_{B₂}"), test_row_normal(arena, two, 0, 1, 0), SLOP_STR("urn:x:A(x) ∧ S0(x, z1) ∧ S0(x, z2) → z2 ≈ z1\nurn:x:B(x) ∧ urn:x:r(z1, x) → S0(z1, x)\nurn:x:C(x) ∧ S0(x, z1) ∧ S0(x, z2) ∧ S0(x, z3) → z2 ≈ z1 ∨ z3 ≈ z1 ∨ z3 ≈ z2\n")))) {
            ok = 0;
        }
        return ok;
    }
}

uint8_t test_table1_rows_roles(slop_arena* arena) {
    {
        __auto_type bar_s = ((types_DRole){ .tag = types_DRole_dr_bar, .data.dr_bar = test_x_iri(arena, SLOP_STR("s")) });
        uint8_t ok = 1;
        if (!(test_table1_is(arena, SLOP_STR("DL5"), test_row_normal(arena, test_one_dl(arena, ((types_DlClause){ .tag = types_DlClause_dl5, .data.dl5 = { .f0 = test_dn(arena, SLOP_STR("A")), .f1 = test_dp(arena, SLOP_STR("r")) } })), 0, 0, 0), SLOP_STR("urn:x:A(x) → urn:x:r(x, x)\n")))) {
            ok = 0;
        }
        if (!(test_table1_is(arena, SLOP_STR("DL6"), test_row_normal(arena, test_one_dl(arena, ((types_DlClause){ .tag = types_DlClause_dl6, .data.dl6 = { .f0 = test_dp(arena, SLOP_STR("r")), .f1 = test_dn(arena, SLOP_STR("B")) } })), 0, 0, 0), SLOP_STR("urn:x:r(x, x) → urn:x:B(x)\n")))) {
            ok = 0;
        }
        if (!(test_table1_is(arena, SLOP_STR("DL7"), test_row_normal(arena, test_one_dl(arena, ((types_DlClause){ .tag = types_DlClause_dl7, .data.dl7 = { .f0 = test_dp(arena, SLOP_STR("r")), .f1 = test_dp(arena, SLOP_STR("s")) } })), 0, 0, 0), SLOP_STR("urn:x:r(z1, x) → urn:x:s(z1, x)\n")))) {
            ok = 0;
        }
        if (!(test_table1_is(arena, SLOP_STR("DL8"), test_row_normal(arena, test_one_dl(arena, ((types_DlClause){ .tag = types_DlClause_dl8, .data.dl8 = { .f0 = test_dp(arena, SLOP_STR("r")), .f1 = bar_s } })), 0, 0, 0), SLOP_STR("urn:x:r(z1, x) → urn:x:s^bar(x, z1)\n")))) {
            ok = 0;
        }
        if (!(test_table1_is(arena, SLOP_STR("DL9"), test_row_normal(arena, test_one_dl(arena, ((types_DlClause){ .tag = types_DlClause_dl9, .data.dl9 = { .f0 = test_dp(arena, SLOP_STR("s")), .f1 = test_dp(arena, SLOP_STR("r")) } })), 0, 0, 0), SLOP_STR("urn:x:r(z1, x) ∧ urn:x:s(z1, x) → ⊥\n")))) {
            ok = 0;
        }
        if (!(test_table1_is(arena, SLOP_STR("DL9 over one role: the body is a set"), test_row_normal(arena, test_one_dl(arena, ((types_DlClause){ .tag = types_DlClause_dl9, .data.dl9 = { .f0 = test_dp(arena, SLOP_STR("r")), .f1 = test_dp(arena, SLOP_STR("r")) } })), 0, 0, 0), SLOP_STR("urn:x:r(z1, x) → ⊥\n")))) {
            ok = 0;
        }
        if (!(test_table1_is(arena, SLOP_STR("DL10"), test_row_normal(arena, test_one_dl(arena, ((types_DlClause){ .tag = types_DlClause_dl10, .data.dl10 = { .f0 = test_x_iri(arena, SLOP_STR("a")), .f1 = test_dn(arena, SLOP_STR("B")) } })), 0, 0, 0), SLOP_STR("⊤ → urn:x:B(urn:x:a)\n")))) {
            ok = 0;
        }
        if (!(test_table1_is(arena, SLOP_STR("DL11"), test_row_normal(arena, test_one_dl(arena, ((types_DlClause){ .tag = types_DlClause_dl11, .data.dl11 = { .f0 = test_dn(arena, SLOP_STR("C")), .f1 = test_x_iri(arena, SLOP_STR("b")) } })), 0, 0, 0), SLOP_STR("urn:x:C(x) → urn:x:b ≈ x\n")))) {
            ok = 0;
        }
        return ok;
    }
}

uint8_t test_test_sriq_table1_rows(slop_arena* arena) {
    {
        __auto_type a = test_table1_rows_names(arena);
        __auto_type b = test_table1_rows_dl4(arena);
        __auto_type c = test_table1_rows_roles(arena);
        return ((a) && (b) && (c));
    }
}

uint8_t test_boundary_refuses(slop_arena* arena, slop_string label, sriqnames_SriqNormal n, slop_string want) {
    {
        __auto_type got = test_clause_text(arena, n);
        if (string_eq(got, string_concat(arena, SLOP_STR("error: the clause boundary has no id for "), want))) {
            return 1;
        } else {
            printf("%s", "  [clauses] ");
            printf("%.*s", (int)(label).len, (label).data);
            printf("%s", ": ");
            printf("%.*s\n", (int)(got).len, (got).data);
            return 0;
        }
    }
}

uint8_t test_test_sriq_clauses_cover_every_name(slop_arena* arena) {
    {
        __auto_type thing = ((types_DName){ .tag = types_DName_dn_class, .data.dn_class = ((rdf_IRI){.value = SLOP_STR("http://www.w3.org/2002/07/owl#Thing")}) });
        __auto_type bar_r = ((types_DRole){ .tag = types_DRole_dr_bar, .data.dr_bar = test_x_iri(arena, SLOP_STR("r")) });
        __auto_type over_fns = test_dl2_of(arena, SLOP_STR("A"), test_dp(arena, SLOP_STR("r")), 2, ((slop_option_types_DName){.has_value = false}));
        uint8_t ok = 1;
        if (!(test_table1_is(arena, SLOP_STR("an undeclared class"), test_row_normal(arena, test_one_dl(arena, test_dl1_of(arena, SLOP_STR("B AA"), SLOP_STR(""))), 0, 0, 0), SLOP_STR("urn:x:AA(x) ∧ urn:x:B(x) → ⊥\n")))) {
            ok = 0;
        }
        if (!(test_table1_is(arena, SLOP_STR("an undeclared individual"), test_row_normal(arena, test_one_dl(arena, ((types_DlClause){ .tag = types_DlClause_dl10, .data.dl10 = { .f0 = test_x_iri(arena, SLOP_STR("aa")), .f1 = test_dn(arena, SLOP_STR("B")) } })), 0, 0, 0), SLOP_STR("⊤ → urn:x:B(urn:x:aa)\n")))) {
            ok = 0;
        }
        if (!(test_boundary_refuses(arena, SLOP_STR("owl:Thing as a name"), test_row_normal(arena, test_one_dl(arena, ((types_DlClause){ .tag = types_DlClause_dl6, .data.dl6 = { .f0 = test_dp(arena, SLOP_STR("r")), .f1 = thing } })), 0, 0, 0), SLOP_STR("class http://www.w3.org/2002/07/owl#Thing")))) {
            ok = 0;
        }
        if (!(test_boundary_refuses(arena, SLOP_STR("a P̄ S2 never made"), test_row_normal(arena, test_one_dl(arena, ((types_DlClause){ .tag = types_DlClause_dl7, .data.dl7 = { .f0 = test_dp(arena, SLOP_STR("s")), .f1 = bar_r } })), 0, 0, 0), SLOP_STR("role urn:x:r^bar")))) {
            ok = 0;
        }
        if (!(test_boundary_refuses(arena, SLOP_STR("a fresh name past concepts"), test_row_normal(arena, test_one_dl(arena, test_dl1_of(arena, SLOP_STR("A0"), SLOP_STR("B"))), 0, 0, 0), SLOP_STR("class A0")))) {
            ok = 0;
        }
        if (!(test_boundary_refuses(arena, SLOP_STR("a function symbol past fns"), test_row_normal(arena, test_one_dl(arena, over_fns), 0, 0, 1), SLOP_STR("function symbol 1")))) {
            ok = 0;
        }
        return ok;
    }
}

slop_list_types_Lit test_lits_of(slop_arena* arena, types_Lit a, types_Lit b, types_Lit c) {
    {
        __auto_type out = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

slop_list_types_Lit test_no_lits(slop_arena* arena) {
    return ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
}

slop_list_types_Lit test_one_lit(slop_arena* arena, types_Lit a) {
    {
        __auto_type out = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

uint8_t test_not_canonical(slop_list_types_Lit body, slop_list_types_Lit head) {
    return !(sriqclauses_clause_canonical(((types_Clause){.body = body, .head = head})));
}

uint8_t test_canonical_rejects(slop_arena* arena) {
    {
        __auto_type b0 = ((uint32_t)(0));
        __auto_type b1 = ((uint32_t)(1));
        __auto_type x = types_at_x();
        __auto_type y = types_at_y();
        __auto_type z1 = types_at_z(((uint32_t)(1)));
        return ((test_not_canonical(test_no_lits(arena), test_one_lit(arena, ((types_Lit){.form = types_LitForm_lf_unary, .pred = b0, .t1 = x, .t2 = y})))) && (test_not_canonical(test_no_lits(arena), test_one_lit(arena, ((types_Lit){.form = types_LitForm_lf_eq, .pred = b0, .t1 = x, .t2 = z1})))) && (test_not_canonical(test_no_lits(arena), test_one_lit(arena, ((types_Lit){.form = types_LitForm_lf_neq, .pred = b0, .t1 = x, .t2 = z1})))) && (test_not_canonical(test_no_lits(arena), test_one_lit(arena, ((types_Lit){.form = types_LitForm_lf_eq, .pred = b1, .t1 = z1, .t2 = x})))) && (test_not_canonical(test_lits2_of(arena, types_atom1(b1, x), types_atom1(b0, x)), test_no_lits(arena))) && (test_not_canonical(test_lits2_of(arena, types_atom1(b0, x), types_atom1(b0, x)), test_no_lits(arena))) && (test_not_canonical(test_no_lits(arena), test_lits2_of(arena, types_eq_lit(z1, x), types_atom1(b0, x)))) && (test_not_canonical(test_one_lit(arena, types_atom1(b0, ((types_ATerm){.kind = types_AKind_ak_x, .fsym = b1, .cst = b0, .zi = b0}))), test_no_lits(arena))) && (test_not_canonical(test_one_lit(arena, types_atom2(b0, x, ((types_ATerm){.kind = types_AKind_ak_z, .fsym = b0, .cst = b0, .zi = b0}))), test_no_lits(arena))) && (test_not_canonical(test_no_lits(arena), test_one_lit(arena, types_atom1(b0, ((types_ATerm){.kind = types_AKind_ak_fx, .fsym = b0, .cst = b1, .zi = b0}))))) && (test_not_canonical(test_no_lits(arena), test_one_lit(arena, types_atom1(b0, ((types_ATerm){.kind = types_AKind_ak_y, .fsym = b0, .cst = b1, .zi = b0}))))) && (test_not_canonical(test_no_lits(arena), test_one_lit(arena, types_atom1(b0, ((types_ATerm){.kind = types_AKind_ak_u, .fsym = b1, .cst = b0, .zi = b0}))))) && (test_not_canonical(test_no_lits(arena), test_one_lit(arena, types_atom1(b0, ((types_ATerm){.kind = types_AKind_ak_fu, .fsym = b0, .cst = b0, .zi = b1}))))));
    }
}

slop_list_types_Lit test_lits2_of(slop_arena* arena, types_Lit a, types_Lit b) {
    {
        __auto_type out = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

slop_map* test_index_classes(slop_arena* arena, slop_list_types_DName ds) {
    {
        __auto_type m = ({ static const slop_map_desc _d = SLOP_MAP_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED, uint32_t); slop_map_new_ptr(arena, 0, &_d); });
        int64_t i = 0;
        {
            __auto_type _coll = ds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type d = _coll.data[_i];
                __auto_type _mv_1532 = d;
                switch (_mv_1532.tag) {
                    case types_DName_dn_class:
                    {
                        __auto_type c = _mv_1532.data.dn_class;
                        ({ uint32_t _val = ((uint32_t)(i)); slop_map_put(NULL, m, &(c), &_val, sizeof(_val)); });
                        break;
                    }
                    case types_DName_dn_fresh:
                    {
                        __auto_type _ = _mv_1532.data.dn_fresh;
                        break;
                    }
                }
                i = (i + 1);
            }
        }
        return m;
    }
}

slop_map* test_index_iris(slop_arena* arena, slop_list_rdf_IRI xs) {
    {
        __auto_type m = ({ static const slop_map_desc _d = SLOP_MAP_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED, uint32_t); slop_map_new_ptr(arena, 0, &_d); });
        int64_t i = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ uint32_t _val = ((uint32_t)(i)); slop_map_put(NULL, m, &(x), &_val, sizeof(_val)); });
                i = (i + 1);
            }
        }
        return m;
    }
}

uint8_t test_permuted_tables_flagged(slop_arena* arena, types_Clause ok_clause) {
    {
        __auto_type ids = sriqclauses_build_sriq_ids(arena, test_row_normal(arena, test_one_dl(arena, ((types_DlClause){ .tag = types_DlClause_dl7, .data.dl7 = { .f0 = test_dp(arena, SLOP_STR("r")), .f1 = test_dp(arena, SLOP_STR("s")) } })), 0, 0, 0));
        __auto_type roles = ((slop_list_types_DRole){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type consts = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type pr = ids;
        __auto_type pb = ids;
        __auto_type pc = ids;
        ({ __auto_type _lst_p = &(roles); __auto_type _item = (test_dp(arena, SLOP_STR("s"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(roles); __auto_type _item = (test_dp(arena, SLOP_STR("r"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(roles); __auto_type _item = (((types_DRole){ .tag = types_DRole_dr_bar, .data.dr_bar = test_x_iri(arena, SLOP_STR("s")) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        pr.role_of = roles;
        pr.prop_ix = test_index_iris(arena, test_iris_of(arena, test_strs(arena, SLOP_STR("s r"))));
        ({ __auto_type _lst_p = &(consts); __auto_type _item = (test_x_iri(arena, SLOP_STR("b"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(consts); __auto_type _item = (test_x_iri(arena, SLOP_STR("a"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        pc.const_of = consts;
        pc.const_ix = test_index_iris(arena, consts);
        pb.role_of = test_bars_swapped(arena);
        pb.sub0 = 4;
        pb.bar_ix = test_bar_index(arena);
        return ((!(test_flagged(arena, ids, ok_clause))) && (test_flagged(arena, pr, ok_clause)) && (test_flagged(arena, pb, ok_clause)) && (test_flagged(arena, pc, ok_clause)));
    }
}

slop_list_types_DRole test_bars_swapped(slop_arena* arena) {
    {
        __auto_type out = ((slop_list_types_DRole){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (test_dp(arena, SLOP_STR("r"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (test_dp(arena, SLOP_STR("s"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_DRole){ .tag = types_DRole_dr_bar, .data.dr_bar = test_x_iri(arena, SLOP_STR("s")) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_DRole){ .tag = types_DRole_dr_bar, .data.dr_bar = test_x_iri(arena, SLOP_STR("r")) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

slop_map* test_bar_index(slop_arena* arena) {
    {
        __auto_type m = ({ static const slop_map_desc _d = SLOP_MAP_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED, uint32_t); slop_map_new_ptr(arena, 0, &_d); });
        ({ rdf_IRI _key_1535 = (test_x_iri(arena, SLOP_STR("s"))); uint32_t _val = ((uint32_t)(2)); slop_map_put(NULL, m, &_key_1535, &_val, sizeof(_val)); });
        ({ rdf_IRI _key_1536 = (test_x_iri(arena, SLOP_STR("r"))); uint32_t _val = ((uint32_t)(3)); slop_map_put(NULL, m, &_key_1536, &_val, sizeof(_val)); });
        return m;
    }
}

uint8_t test_shape_rejects(slop_arena* arena) {
    {
        __auto_type b0 = ((uint32_t)(0));
        __auto_type x = types_at_x();
        __auto_type z1 = types_at_z(((uint32_t)(1)));
        __auto_type z2 = types_at_z(((uint32_t)(2)));
        __auto_type fx = types_at_fx(((uint32_t)(0)));
        __auto_type u = types_at_u(((uint32_t)(0)));
        __auto_type y = types_at_y();
        __auto_type good = sriqclauses_make_clause(arena, test_lits_of(arena, types_atom1(b0, x), types_atom2(b0, x, z1), types_atom2(b0, z1, x)), test_lits_of(arena, types_atom1(b0, fx), types_atom2(b0, fx, x), types_neq_lit(fx, u)));
        __auto_type good2 = sriqclauses_make_clause(arena, test_one_lit(arena, types_atom2(b0, x, x)), test_lits_of(arena, types_atom1(b0, u), types_atom2(b0, x, fx), types_eq_lit(z1, x)));
        return ((sriqclauses_dl_clause_shape(good)) && (sriqclauses_dl_clause_shape(good2)) && (!(sriqclauses_dl_clause_shape(sriqclauses_make_clause(arena, test_one_lit(arena, types_atom1(b0, fx)), test_no_lits(arena))))) && (!(sriqclauses_dl_clause_shape(sriqclauses_make_clause(arena, test_one_lit(arena, types_atom2(b0, z1, z2)), test_no_lits(arena))))) && (!(sriqclauses_dl_clause_shape(sriqclauses_make_clause(arena, test_one_lit(arena, types_atom1(b0, y)), test_no_lits(arena))))) && (!(sriqclauses_dl_clause_shape(sriqclauses_make_clause(arena, test_one_lit(arena, types_eq_lit(x, z1)), test_no_lits(arena))))) && (!(sriqclauses_dl_clause_shape(sriqclauses_make_clause(arena, test_no_lits(arena), test_one_lit(arena, types_atom1(b0, y)))))) && (!(sriqclauses_dl_clause_shape(sriqclauses_make_clause(arena, test_no_lits(arena), test_one_lit(arena, types_atom2(b0, fx, z1)))))) && (!(sriqclauses_dl_clause_shape(sriqclauses_make_clause(arena, test_no_lits(arena), test_one_lit(arena, types_eq_lit(y, x)))))) && (sriqclauses_clause_canonical(good)) && (sriqclauses_clause_canonical(good2)) && (test_canonical_rejects(arena)));
    }
}

uint8_t test_flagged(slop_arena* arena, sriqclauses_SriqIds ids, types_Clause c) {
    {
        __auto_type cs = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(cs); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return (((int64_t)((sriqclauses_ids_dense(arena, ((sriqclauses_SriqClauses){.ids = ids, .clauses = cs}))).len)) > 0);
    }
}

uint8_t test_ids_dense_rejects(slop_arena* arena) {
    {
        __auto_type ids = sriqclauses_build_sriq_ids(arena, test_row_normal(arena, test_one_dl(arena, ((types_DlClause){ .tag = types_DlClause_dl5, .data.dl5 = { .f0 = test_dn(arena, SLOP_STR("A")), .f1 = test_dp(arena, SLOP_STR("r")) } })), 0, 0, 0));
        __auto_type far = ((uint32_t)(99));
        __auto_type x = types_at_x();
        __auto_type ok_clause = sriqclauses_make_clause(arena, test_one_lit(arena, types_atom1(((uint32_t)(2)), x)), test_one_lit(arena, types_atom2(((uint32_t)(1)), x, types_at_u(((uint32_t)(1))))));
        __auto_type swapped = ids;
        __auto_type permuted = ids;
        swapped.class_of = test_reverse_dnames(arena, ids.class_of);
        permuted.class_of = test_reverse_dnames(arena, ids.class_of);
        permuted.class_ix = test_index_classes(arena, permuted.class_of);
        return ((!(test_flagged(arena, ids, ok_clause))) && (test_flagged(arena, ids, sriqclauses_make_clause(arena, test_one_lit(arena, types_atom1(far, x)), test_no_lits(arena)))) && (test_flagged(arena, ids, sriqclauses_make_clause(arena, test_one_lit(arena, types_atom2(far, x, x)), test_no_lits(arena)))) && (test_flagged(arena, ids, sriqclauses_make_clause(arena, test_no_lits(arena), test_one_lit(arena, types_atom1(((uint32_t)(0)), types_at_fx(((uint32_t)(0)))))))) && (test_flagged(arena, ids, sriqclauses_make_clause(arena, test_no_lits(arena), test_one_lit(arena, types_atom1(((uint32_t)(0)), types_at_u(((uint32_t)(2)))))))) && (test_flagged(arena, ids, sriqclauses_make_clause(arena, test_no_lits(arena), test_one_lit(arena, types_atom1(((uint32_t)(0)), types_at_z(((uint32_t)(0)))))))) && (test_flagged(arena, swapped, ok_clause)) && (test_flagged(arena, permuted, ok_clause)) && (test_permuted_tables_flagged(arena, ok_clause)));
    }
}

slop_list_types_DName test_reverse_dnames(slop_arena* arena, slop_list_types_DName xs) {
    {
        __auto_type out = ((slop_list_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = (((int64_t)(((int64_t)((xs).len)))) - 1);
        while (i >= 0) {
            __auto_type _mv_1537 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_DName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1537.has_value) {
                __auto_type d = _mv_1537.value;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (d); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_1537.has_value) {
            }
            i = (i - 1);
        }
        return out;
    }
}

uint8_t test_test_sriq_clause_checks_reject(slop_arena* arena) {
    {
        __auto_type a = test_shape_rejects(arena);
        __auto_type b = test_ids_dense_rejects(arena);
        if (!(a)) {
            printf("%s\n", "  [clauses] dl-clause-shape takes or refuses the wrong clause");
        }
        if (!(b)) {
            printf("%s\n", "  [clauses] ids-dense misses a broken id or table");
        }
        return (a && b);
    }
}

slop_list_types_ATerm test_sample_aterms(slop_arena* arena) {
    {
        __auto_type out = ((slop_list_types_ATerm){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_x()); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_y()); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_z(((uint32_t)(1)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_z(((uint32_t)(2)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_fx(((uint32_t)(0)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_fx(((uint32_t)(1)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_u(((uint32_t)(0)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_u(((uint32_t)(1)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_fu(((uint32_t)(0)), ((uint32_t)(1)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_fu(((uint32_t)(1)), ((uint32_t)(0)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

uint8_t test_oriented_pair_ok(types_ATerm s, types_ATerm t, uint8_t same) {
    return ((types_lit_eq(types_eq_lit(s, t), types_eq_lit(t, s))) && (types_lit_eq(types_neq_lit(s, t), types_neq_lit(t, s))) && (!(types_lit_eq(types_eq_lit(s, t), types_neq_lit(s, t)))) && ((types_aterm_cmp(types_eq_lit(s, t).t1, types_eq_lit(s, t).t2) >= 0)) && ((types_aterm_cmp(s, t) == (0 - types_aterm_cmp(t, s)))) && (((types_aterm_cmp(s, t) == 0) == same)));
}

uint8_t test_test_sriq_eq_orientation(slop_arena* arena) {
    {
        __auto_type ts = test_sample_aterms(arena);
        uint8_t ok = 1;
        int64_t i = 0;
        {
            __auto_type _coll = ts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                {
                    int64_t j = 0;
                    {
                        __auto_type _coll = ts;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type t = _coll.data[_i];
                            if (!(test_oriented_pair_ok(s, t, (i == j)))) {
                                printf("%s", "  [orientation] pair ");
                                printf("%.*s", (int)(int_to_string(arena, i)).len, (int_to_string(arena, i)).data);
                                printf("%s", " ");
                                printf("%.*s\n", (int)(int_to_string(arena, j)).len, (int_to_string(arena, j)).data);
                                ok = 0;
                            }
                            j = (j + 1);
                        }
                    }
                    i = (i + 1);
                }
            }
        }
        return ok;
    }
}

slop_list_string test_clause_lines(slop_arena* arena, slop_result_sriqnames_SriqNormal_string r) {
    __auto_type _mv_1538 = r;
    if (!_mv_1538.is_ok) {
        __auto_type m = _mv_1538.data.err;
        return test_line1(arena, string_concat(arena, SLOP_STR("error: "), m));
    } else if (_mv_1538.is_ok) {
        __auto_type n = _mv_1538.data.ok;
        __auto_type _mv_1539 = sriqclauses_sriq_clauses(arena, n);
        if (!_mv_1539.is_ok) {
            __auto_type m = _mv_1539.data.err;
            return test_line1(arena, string_concat(arena, SLOP_STR("error: "), m));
        } else if (_mv_1539.is_ok) {
            __auto_type sc = _mv_1539.data.ok;
            return sriqclauses_render_clauses(arena, sc);
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_fixture_clauses_ok(slop_arena* arena, slop_string path) {
    __auto_type _mv_1540 = test_gate_fixture_in(arena, path, types_Profile_profile_sriq);
    if (!_mv_1540.has_value) {
        printf("%s", "  [clauses] did not gate: ");
        printf("%.*s\n", (int)(path).len, (path).data);
        return 0;
    } else if (_mv_1540.has_value) {
        __auto_type gr = _mv_1540.value;
        {
            __auto_type n0 = test_sriq_nf(arena, gr, 0, 0, 0);
            __auto_type l0 = test_clause_lines(arena, n0);
            __auto_type l1 = test_clause_lines(arena, test_sriq_nf(arena, gr, 1, 0, 0));
            __auto_type l2 = test_clause_lines(arena, test_sriq_nf(arena, gr, 0, 1, 0));
            __auto_type l3 = test_clause_lines(arena, test_sriq_nf(arena, gr, 0, 0, 1));
            __auto_type _mv_1541 = n0;
            if (!_mv_1541.is_ok) {
                __auto_type m = _mv_1541.data.err;
                printf("%s", "  [clauses] refused: ");
                printf("%.*s", (int)(path).len, (path).data);
                printf("%s", " ");
                printf("%.*s\n", (int)(m).len, (m).data);
                return 0;
            } else if (_mv_1541.is_ok) {
                __auto_type n = _mv_1541.data.ok;
                if (!(test_clauses_sound(arena, n))) {
                    printf("%s", "  [clauses] not DL-clauses, or ids out of range: ");
                    printf("%.*s\n", (int)(path).len, (path).data);
                    return 0;
                } else if (!(((test_same_lines(l0, l1)) && (test_same_lines(l0, l2)) && (test_same_lines(l0, l3))))) {
                    printf("%s", "  [clauses] reordered input differs: ");
                    printf("%.*s\n", (int)(path).len, (path).data);
                    return 0;
                } else {
                    return 1;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sriq_clauses_on_fixtures(slop_arena* arena) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = test_sriq_fixtures(arena);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (!(test_fixture_clauses_ok(arena, p))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

sriqorder_SriqOrder test_ord_table(slop_arena* arena) {
    {
        __auto_type base = sriqorder_named_consts(arena, 2);
        __auto_type a = sriqorder_const_entry(base, ((uint32_t)(0)));
        __auto_type b = sriqorder_const_entry(base, ((uint32_t)(1)));
        __auto_type a2 = sriqorder_aux_const(a, ((uint32_t)(0)), ((uint32_t)(0)), ((uint32_t)(2)));
        __auto_type b1 = sriqorder_aux_const(b, ((uint32_t)(1)), ((uint32_t)(0)), ((uint32_t)(1)));
        __auto_type a1 = sriqorder_aux_const(a, ((uint32_t)(0)), ((uint32_t)(0)), ((uint32_t)(1)));
        __auto_type cs = ((slop_list_sriqorder_ConstEntry){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(cs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(cs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(cs); __auto_type _item = (a2); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(cs); __auto_type _item = (b1); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(cs); __auto_type _item = (a1); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(cs); __auto_type _item = (sriqorder_aux_const(a2, ((uint32_t)(2)), ((uint32_t)(0)), ((uint32_t)(1)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(cs); __auto_type _item = (sriqorder_aux_const(a1, ((uint32_t)(4)), ((uint32_t)(1)), ((uint32_t)(1)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(cs); __auto_type _item = (sriqorder_aux_const(a, ((uint32_t)(0)), ((uint32_t)(1)), ((uint32_t)(1)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((sriqorder_SriqOrder){.consts = cs});
    }
}

slop_list_int test_ord_label(slop_arena* arena, sriqorder_SriqOrder ord, uint32_t u) {
    {
        __auto_type back = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint32_t c = u;
        int64_t k = ((int64_t)(sriqorder_const_entry(ord, u).len));
        while (k > 0) {
            {
                __auto_type e = sriqorder_const_entry(ord, c);
                ({ __auto_type _lst_p = &(back); __auto_type _item = (((((int64_t)(e.srole)) * 1000) + ((int64_t)(e.i)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                c = e.parent;
                k = (k - 1);
            }
        }
        {
            int64_t j = (((int64_t)(((int64_t)((back).len)))) - 1);
            while (j >= 0) {
                ({ __auto_type _lst_p = &(out); __auto_type _item = (canon_int_at(back, j)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                j = (j - 1);
            }
        }
        return out;
    }
}

int64_t test_ord_ints_cmp(slop_list_int a, slop_list_int b) {
    {
        int64_t r = 0;
        int64_t i = 0;
        while ((r == 0) && (i < ((int64_t)(((int64_t)((a).len)))))) {
            r = ((canon_int_at(a, i) < canon_int_at(b, i)) ? -1 : ((canon_int_at(a, i) > canon_int_at(b, i)) ? 1 : 0));
            i = (i + 1);
        }
        return r;
    }
}

uint8_t test_ref_const_gt(slop_arena* arena, sriqorder_SriqOrder ord, uint32_t a, uint32_t b) {
    {
        __auto_type ea = sriqorder_const_entry(ord, a);
        __auto_type eb = sriqorder_const_entry(ord, b);
        if (ea.len != eb.len) {
            return (ea.len > eb.len);
        } else if (ea.base != eb.base) {
            return (ea.base > eb.base);
        } else {
            return (test_ord_ints_cmp(test_ord_label(arena, ord, a), test_ord_label(arena, ord, b)) > 0);
        }
    }
}

uint8_t test_ref_is_var(types_ATerm t) {
    return ((t.kind == types_AKind_ak_x) || (t.kind == types_AKind_ak_y));
}

uint8_t test_ref_has_arg(types_ATerm t) {
    return ((t.kind == types_AKind_ak_fx) || (t.kind == types_AKind_ak_fu));
}

types_ATerm test_ref_arg(types_ATerm t) {
    if (t.kind == types_AKind_ak_fx) {
        return types_at_x();
    } else {
        return types_at_u(t.cst);
    }
}

uint8_t test_ref_prec_gt(slop_arena* arena, sriqorder_SriqOrder ord, types_ATerm a, types_ATerm b) {
    if (test_ref_has_arg(a) && test_ref_has_arg(b)) {
        return (a.fsym > b.fsym);
    } else if (test_ref_has_arg(a)) {
        return 1;
    } else if (test_ref_has_arg(b)) {
        return 0;
    } else {
        return test_ref_const_gt(arena, ord, a.cst, b.cst);
    }
}

uint8_t test_ref_same_head(types_ATerm a, types_ATerm b) {
    if (test_ref_has_arg(a) && test_ref_has_arg(b)) {
        return (a.fsym == b.fsym);
    } else {
        return ((!(test_ref_has_arg(a))) && (!(test_ref_has_arg(b))) && ((a.cst == b.cst)));
    }
}

uint8_t test_ref_lpo(slop_arena* arena, sriqorder_SriqOrder ord, types_ATerm s, types_ATerm t) {
    if (test_ref_is_var(t)) {
        return ((s.kind == types_AKind_ak_fx) && (t.kind == types_AKind_ak_x));
    } else if (test_ref_is_var(s)) {
        return 0;
    } else if (test_ref_has_arg(s) && (test_ord_aterm_same(test_ref_arg(s), t) || test_ref_lpo(arena, ord, test_ref_arg(s), t))) {
        return 1;
    } else if (test_ref_prec_gt(arena, ord, s, t)) {
        return (!(test_ref_has_arg(t)) || test_ref_lpo(arena, ord, s, test_ref_arg(t)));
    } else if (test_ref_same_head(s, t) && test_ref_has_arg(s)) {
        return (test_ref_lpo(arena, ord, test_ref_arg(s), test_ref_arg(t)) && test_ref_lpo(arena, ord, s, test_ref_arg(t)));
    } else {
        return 0;
    }
}

uint8_t test_ord_aterm_same(types_ATerm a, types_ATerm b) {
    return (((a.kind == b.kind)) && ((a.fsym == b.fsym)) && ((a.cst == b.cst)) && ((a.zi == b.zi)));
}

slop_list_types_ATerm test_ord_aterms(slop_arena* arena) {
    {
        __auto_type out = ((slop_list_types_ATerm){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_x()); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_y()); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_fx(((uint32_t)(0)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_fx(((uint32_t)(1)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        while (k < 8) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_u(((uint32_t)(k)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            k = (k + 1);
        }
        k = 0;
        while (k < 8) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_fu(((uint32_t)(0)), ((uint32_t)(k)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (types_at_fu(((uint32_t)(1)), ((uint32_t)(k)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            k = (k + 1);
        }
        return out;
    }
}

slop_list_sriqorder_CTerm test_ord_push_binary(slop_arena* arena, slop_list_sriqorder_CTerm out, types_ATerm l, types_ATerm r) {
    {
        __auto_type o = out;
        ({ __auto_type _lst_p = &(o); __auto_type _item = (sriqorder_ct_p(types_atom2(((uint32_t)(0)), l, r))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return o;
    }
}

slop_list_sriqorder_CTerm test_ord_universe(slop_arena* arena) {
    {
        __auto_type as = test_ord_aterms(arena);
        __auto_type out = ((slop_list_sriqorder_CTerm){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqorder_ct_true()); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = as;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqorder_ct_a(t)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = as;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqorder_ct_p(types_atom1(((uint32_t)(0)), t))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqorder_ct_p(types_atom1(((uint32_t)(1)), t))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = as;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (!((t.kind == types_AKind_ak_fu))) {
                    out = test_ord_push_binary(arena, out, types_at_x(), t);
                    if (!((t.kind == types_AKind_ak_x))) {
                        out = test_ord_push_binary(arena, out, t, types_at_x());
                    }
                }
            }
        }
        {
            __auto_type _coll = as;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type u = _coll.data[_i];
                if (u.kind == types_AKind_ak_u) {
                    {
                        __auto_type _coll = as;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type t = _coll.data[_i];
                            if (((t.kind == types_AKind_ak_y)) || ((t.kind == types_AKind_ak_u)) || ((t.kind == types_AKind_ak_fu))) {
                                out = test_ord_push_binary(arena, out, u, t);
                                if (!((t.kind == types_AKind_ak_u))) {
                                    out = test_ord_push_binary(arena, out, t, u);
                                }
                            }
                        }
                    }
                }
            }
        }
        return out;
    }
}

sriqorder_CTerm test_ord_ct_at(slop_list_sriqorder_CTerm xs, int64_t i) {
    __auto_type _mv_1542 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_sriqorder_CTerm _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1542.has_value) {
        __auto_type c = _mv_1542.value;
        return c;
    } else if (!_mv_1542.has_value) {
        return sriqorder_ct_true();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_ord_get(slop_list_u8 m, int64_t n, int64_t i, int64_t j) {
    __auto_type _mv_1543 = ({ __auto_type _lst = m; size_t _idx = (size_t)((i * n) + j); slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1543.has_value) {
        __auto_type b = _mv_1543.value;
        return b;
    } else if (!_mv_1543.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_ord_ge(slop_list_u8 m, int64_t n, slop_list_sriqorder_CTerm u, int64_t i, int64_t j) {
    return ((i == j) || test_ord_get(m, n, i, j));
}

int64_t test_ord_index(slop_list_sriqorder_CTerm u, types_ATerm t) {
    {
        int64_t r = -1;
        int64_t i = 0;
        {
            __auto_type _coll = u;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (((r == -1)) && ((c.ck == sriqorder_CKind_ck_a)) && (test_ord_aterm_same(c.a, t))) {
                    r = i;
                }
                i = (i + 1);
            }
        }
        return r;
    }
}

uint8_t test_ord_arg_ge(slop_list_u8 m, int64_t n, slop_list_sriqorder_CTerm u, types_ATerm arg, int64_t j) {
    {
        __auto_type ia = test_ord_index(u, arg);
        __auto_type inner = ((test_ref_has_arg(arg)) ? test_ord_index(u, test_ref_arg(arg)) : -1);
        return (((ia >= 0) && test_ord_ge(m, n, u, ia, j)) || ((inner >= 0) && test_ord_ge(m, n, u, inner, j)));
    }
}

uint8_t test_ord_p_args_le(slop_list_u8 m, int64_t n, slop_list_sriqorder_CTerm u, types_Lit a, types_Lit b) {
    {
        __auto_type a1 = test_ord_index(u, a.t1);
        __auto_type b1 = test_ord_index(u, b.t1);
        __auto_type a2 = test_ord_index(u, a.t2);
        __auto_type b2 = test_ord_index(u, b.t2);
        __auto_type one = (((a1 >= 0)) && ((b1 >= 0)) && (test_ord_ge(m, n, u, a1, b1)));
        __auto_type two = ((a.form == types_LitForm_lf_unary) || (((a2 >= 0)) && ((b2 >= 0)) && (test_ord_ge(m, n, u, a2, b2))));
        __auto_type same = ((a1 == b1) && ((a.form == types_LitForm_lf_unary) || (a2 == b2)));
        return (((a.form == b.form)) && ((a.pred == b.pred)) && (one) && (two) && (!(same)));
    }
}

uint8_t test_ord_generated(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_u8 m, int64_t n, slop_list_sriqorder_CTerm u, int64_t i, int64_t j) {
    {
        __auto_type s = test_ord_ct_at(u, i);
        __auto_type t = test_ord_ct_at(u, j);
        if (i == j) {
            return 0;
        } else if (t.ck == sriqorder_CKind_ck_true) {
            return !((s.ck == sriqorder_CKind_ck_true));
        } else if ((s.ck == sriqorder_CKind_ck_a) && (t.ck == sriqorder_CKind_ck_a)) {
            return (test_ref_lpo(arena, ord, s.a, t.a) || test_ord_items_1_3(arena, ord, s.a, t.a));
        } else if ((s.ck == sriqorder_CKind_ck_p) && (t.ck == sriqorder_CKind_ck_a)) {
            return ((test_ref_is_var(t.a)) || (test_ord_arg_ge(m, n, u, s.p.t1, j)) || (((s.p.form == types_LitForm_lf_binary) && test_ord_arg_ge(m, n, u, s.p.t2, j))));
        } else if ((s.ck == sriqorder_CKind_ck_p) && (t.ck == sriqorder_CKind_ck_p)) {
            return test_ord_p_args_le(m, n, u, s.p, t.p);
        } else {
            return 0;
        }
    }
}

uint8_t test_ord_items_1_3(slop_arena* arena, sriqorder_SriqOrder ord, types_ATerm s, types_ATerm t) {
    return ((((s.kind == types_AKind_ak_x) && (t.kind == types_AKind_ak_y))) || ((((s.kind == types_AKind_ak_fx)) && ((t.kind == types_AKind_ak_fx)) && ((s.fsym > t.fsym)))) || (((s.kind == types_AKind_ak_fx) && (test_ref_is_var(t) || (t.kind == types_AKind_ak_u)))));
}

slop_list_u8 test_ord_step(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_u8 m, int64_t n, slop_list_sriqorder_CTerm u) {
    {
        __auto_type r = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < (n * n)) {
            ({ __auto_type _lst_p = &(r); __auto_type _item = ((test_ord_get(m, n, (i / n), (i % n)) || test_ord_generated(arena, ord, m, n, u, (i / n), (i % n)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        return test_ord_close(r, n);
    }
}

slop_list_u8 test_ord_close(slop_list_u8 m, int64_t n) {
    {
        int64_t k = 0;
        while (k < n) {
            {
                int64_t i = 0;
                while (i < n) {
                    if (test_ord_get(m, n, i, k)) {
                        test_ord_close_row(m, n, i, k);
                    }
                    i = (i + 1);
                }
                k = (k + 1);
            }
        }
        return m;
    }
}

uint8_t test_ord_close_row(slop_list_u8 m, int64_t n, int64_t i, int64_t k) {
    {
        int64_t j = 0;
        while (j < n) {
            if (test_ord_get(m, n, k, j)) {
                ({ __auto_type _set_lst = &(m); size_t _set_idx = (size_t)(((i * n) + j)); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
            }
            j = (j + 1);
        }
        return 1;
    }
}

int64_t test_ord_count(slop_list_u8 m) {
    {
        int64_t c = 0;
        {
            __auto_type _coll = m;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                if (b) {
                    c = (c + 1);
                }
            }
        }
        return c;
    }
}

slop_list_u8 test_ord_least(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_sriqorder_CTerm u) {
    {
        __auto_type n = ((int64_t)(((int64_t)((u).len))));
        __auto_type m = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        int64_t last = -1;
        while (i < (n * n)) {
            ({ __auto_type _lst_p = &(m); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        while (last != test_ord_count(m)) {
            last = test_ord_count(m);
            m = test_ord_step(arena, ord, m, n, u);
        }
        return m;
    }
}

slop_string test_ct_text(slop_arena* arena, sriqorder_CTerm c) {
    {
        __auto_type a = c.a;
        __auto_type p = c.p;
        __auto_type _mv_1544 = c.ck;
        if (_mv_1544 == sriqorder_CKind_ck_true) {
            return SLOP_STR("true");
        } else if (_mv_1544 == sriqorder_CKind_ck_a) {
            return string_concat(arena, SLOP_STR("a"), test_aterm_code(arena, a));
        } else if (_mv_1544 == sriqorder_CKind_ck_p) {
            return string_concat(arena, (((p.form == types_LitForm_lf_unary)) ? SLOP_STR("B") : SLOP_STR("S")), string_concat(arena, int_to_string(arena, ((int64_t)(p.pred))), string_concat(arena, test_aterm_code(arena, p.t1), (((p.form == types_LitForm_lf_unary)) ? SLOP_STR("") : test_aterm_code(arena, p.t2)))));
        }
        SLOP_UNREACHABLE();
    }
}

slop_string test_aterm_code(slop_arena* arena, types_ATerm t) {
    return string_concat(arena, SLOP_STR("("), string_concat(arena, int_to_string(arena, test_akind_code(t.kind)), string_concat(arena, SLOP_STR(" "), string_concat(arena, int_to_string(arena, ((int64_t)(t.fsym))), string_concat(arena, SLOP_STR(" "), string_concat(arena, int_to_string(arena, ((int64_t)(t.cst))), SLOP_STR(")")))))));
}

int64_t test_akind_code(types_AKind k) {
    __auto_type _mv_1545 = k;
    if (_mv_1545 == types_AKind_ak_x) {
        return 0;
    } else if (_mv_1545 == types_AKind_ak_y) {
        return 1;
    } else if (_mv_1545 == types_AKind_ak_z) {
        return 2;
    } else if (_mv_1545 == types_AKind_ak_fx) {
        return 3;
    } else if (_mv_1545 == types_AKind_ak_u) {
        return 4;
    } else if (_mv_1545 == types_AKind_ak_fu) {
        return 5;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sriq_order_closure(slop_arena* arena) {
    {
        __auto_type ord = test_ord_table(arena);
        __auto_type u = test_ord_universe(arena);
        __auto_type n = ((int64_t)(((int64_t)((u).len))));
        __auto_type m = test_ord_least(arena, ord, u);
        int64_t bad = 0;
        int64_t i = 0;
        while (i < n) {
            bad = (bad + test_ord_row_mismatches(arena, ord, u, m, i, bad));
            i = (i + 1);
        }
        if (test_ord_count(m) < 100) {
            printf("%s\n", "  [order] the closure is suspiciously small");
        }
        return ((bad == 0) && (test_ord_count(m) >= 100));
    }
}

int64_t test_ord_row_mismatches(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_sriqorder_CTerm u, slop_list_u8 m, int64_t i, int64_t seen) {
    {
        __auto_type n = ((int64_t)(((int64_t)((u).len))));
        int64_t bad = 0;
        int64_t j = 0;
        while (j < n) {
            if (test_ord_get(m, n, i, j) != sriqorder_cterm_gt(ord, test_ord_ct_at(u, i), test_ord_ct_at(u, j))) {
                if ((seen + bad) < 8) {
                    printf("%s", "  [order] closure ");
                    if (test_ord_get(m, n, i, j)) {
                        printf("%s", "has ");
                    } else {
                        printf("%s", "lacks ");
                    }
                    printf("%.*s", (int)(test_ct_text(arena, test_ord_ct_at(u, i))).len, (test_ct_text(arena, test_ord_ct_at(u, i))).data);
                    printf("%s", " > ");
                    printf("%.*s\n", (int)(test_ct_text(arena, test_ord_ct_at(u, j))).len, (test_ct_text(arena, test_ord_ct_at(u, j))).data);
                }
                bad = (bad + 1);
            }
            j = (j + 1);
        }
        return bad;
    }
}

uint8_t test_test_sriq_order_strict_and_admissible(slop_arena* arena) {
    {
        __auto_type ord = test_ord_table(arena);
        __auto_type u = test_ord_universe(arena);
        uint8_t ok = 1;
        {
            __auto_type _coll = u;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                if (sriqorder_cterm_gt(ord, s, s)) {
                    printf("%s", "  [order] reflexive at ");
                    printf("%.*s\n", (int)(test_ct_text(arena, s)).len, (test_ct_text(arena, s)).data);
                    ok = 0;
                }
                if (!((s.ck == sriqorder_CKind_ck_true)) && !(sriqorder_cterm_gt(ord, s, sriqorder_ct_true()))) {
                    printf("%s", "  [order] not above true: ");
                    printf("%.*s\n", (int)(test_ct_text(arena, s)).len, (test_ct_text(arena, s)).data);
                    ok = 0;
                }
                {
                    __auto_type _coll = u;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type t = _coll.data[_i];
                        if (!(test_ord_pair_ok(arena, ord, u, s, t))) {
                            ok = 0;
                        }
                    }
                }
                if ((s.ck == sriqorder_CKind_ck_a) && (sriqorder_aterm_gt(ord, types_at_z(((uint32_t)(1))), s.a) || sriqorder_aterm_gt(ord, s.a, types_at_z(((uint32_t)(1)))))) {
                    printf("%s", "  [order] compared with z1: ");
                    printf("%.*s\n", (int)(test_ct_text(arena, s)).len, (test_ct_text(arena, s)).data);
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t test_ord_pair_ok(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_sriqorder_CTerm u, sriqorder_CTerm s, sriqorder_CTerm t) {
    {
        __auto_type st = sriqorder_cterm_gt(ord, s, t);
        uint8_t ok = 1;
        if (st && sriqorder_cterm_gt(ord, t, s)) {
            ok = 0;
        }
        if (st) {
            {
                __auto_type _coll = u;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type r = _coll.data[_i];
                    if (sriqorder_cterm_gt(ord, t, r) && !(sriqorder_cterm_gt(ord, s, r))) {
                        ok = 0;
                    }
                }
            }
        }
        if (((s.ck == sriqorder_CKind_ck_p)) && ((t.ck == sriqorder_CKind_ck_a)) && ((t.a.kind == types_AKind_ak_x)) && (!(st))) {
            ok = 0;
        }
        if (((s.ck == sriqorder_CKind_ck_a)) && ((s.a.kind == types_AKind_ak_u)) && ((t.ck == sriqorder_CKind_ck_p)) && (st)) {
            ok = 0;
        }
        if (((s.ck == sriqorder_CKind_ck_a)) && ((t.ck == sriqorder_CKind_ck_a)) && (test_ref_lpo(arena, ord, s.a, t.a)) && (!(st))) {
            ok = 0;
        }
        if (((s.ck == sriqorder_CKind_ck_a)) && ((t.ck == sriqorder_CKind_ck_a)) && (((test_ref_is_var(s.a) && (t.a.kind == types_AKind_ak_u)) || ((s.a.kind == types_AKind_ak_u) && test_ref_is_var(t.a)))) && (st)) {
            ok = 0;
        }
        if (!(ok)) {
            printf("%s", "  [order] pair ");
            printf("%.*s", (int)(test_ct_text(arena, s)).len, (test_ct_text(arena, s)).data);
            printf("%s", " ");
            printf("%.*s\n", (int)(test_ct_text(arena, t)).len, (test_ct_text(arena, t)).data);
        }
        return ok;
    }
}

uint8_t test_test_sriq_order_c2(slop_arena* arena) {
    {
        __auto_type ord = test_ord_table(arena);
        __auto_type u = test_ord_universe(arena);
        uint8_t ok = 1;
        {
            __auto_type _coll = u;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (((a.ck == sriqorder_CKind_ck_p)) && ((a.p.form == types_LitForm_lf_unary)) && ((a.p.t1.kind == types_AKind_ak_x))) {
                    {
                        __auto_type _coll = u;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type s = _coll.data[_i];
                            if (sriqorder_cterm_gt(ord, a, s) && !(test_ord_c2_exempt(s))) {
                                printf("%s", "  [order] C2 fails: ");
                                printf("%.*s", (int)(test_ct_text(arena, a)).len, (test_ct_text(arena, a)).data);
                                printf("%s", " > ");
                                printf("%.*s\n", (int)(test_ct_text(arena, s)).len, (test_ct_text(arena, s)).data);
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

uint8_t test_ord_c2_exempt(sriqorder_CTerm s) {
    __auto_type _mv_1546 = s.ck;
    if (_mv_1546 == sriqorder_CKind_ck_true) {
        return 1;
    } else if (_mv_1546 == sriqorder_CKind_ck_a) {
        return ((s.a.kind == types_AKind_ak_x) || (s.a.kind == types_AKind_ak_y));
    } else if (_mv_1546 == sriqorder_CKind_ck_p) {
        return ((s.p.t1.kind == types_AKind_ak_y) || ((s.p.form == types_LitForm_lf_binary) && (s.p.t2.kind == types_AKind_ak_y)));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sriq_const_order(slop_arena* arena) {
    {
        __auto_type ord = test_ord_table(arena);
        __auto_type ranks = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t ok = 1;
        ({ __auto_type _lst_p = &(ranks); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ranks); __auto_type _item = (1); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ranks); __auto_type _item = (3); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ranks); __auto_type _item = (5); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ranks); __auto_type _item = (2); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ranks); __auto_type _item = (7); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ranks); __auto_type _item = (6); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ranks); __auto_type _item = (4); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            int64_t a = 0;
            while (a < 8) {
                if (!(test_const_row_ok(arena, ord, ranks, a))) {
                    ok = 0;
                }
                a = (a + 1);
            }
        }
        return ok;
    }
}

uint8_t test_const_row_ok(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_int ranks, int64_t a) {
    {
        uint8_t ok = 1;
        int64_t b = 0;
        while (b < 8) {
            if (sriqorder_const_gt(ord, ((uint32_t)(a)), ((uint32_t)(b))) != (canon_int_at(ranks, a) > canon_int_at(ranks, b))) {
                printf("%s", "  [order] constants ");
                printf("%.*s", (int)(int_to_string(arena, a)).len, (int_to_string(arena, a)).data);
                printf("%s", " ");
                printf("%.*s\n", (int)(int_to_string(arena, b)).len, (int_to_string(arena, b)).data);
                ok = 0;
            }
            b = (b + 1);
        }
        return ok;
    }
}

slop_string test_flags_text(slop_arena* arena, slop_list_u8 fs) {
    {
        __auto_type out = SLOP_STR("");
        {
            __auto_type _coll = fs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                out = string_concat(arena, out, ((f) ? SLOP_STR("T") : SLOP_STR("F")));
            }
        }
        return out;
    }
}

uint8_t test_flags_are(slop_arena* arena, slop_string label, slop_list_types_Lit head, slop_string want) {
    {
        __auto_type got = test_flags_text(arena, sriqorder_max_flags(arena, test_ord_table(arena), sriqclauses_make_clause(arena, ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), head).head));
        if (string_eq(got, want)) {
            return 1;
        } else {
            printf("%s", "  [max] ");
            printf("%.*s", (int)(label).len, (label).data);
            printf("%s", ": got ");
            printf("%.*s\n", (int)(got).len, (got).data);
            return 0;
        }
    }
}

slop_list_types_Lit test_two_lits(slop_arena* arena, types_Lit a, types_Lit b) {
    {
        __auto_type out = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

uint8_t test_test_sriq_max_flags_rows(slop_arena* arena) {
    {
        __auto_type b0 = ((uint32_t)(0));
        __auto_type s0 = ((uint32_t)(0));
        __auto_type x = types_at_x();
        __auto_type y = types_at_y();
        __auto_type f0x = types_at_fx(((uint32_t)(0)));
        __auto_type f1x = types_at_fx(((uint32_t)(1)));
        __auto_type u2 = types_at_u(((uint32_t)(2)));
        __auto_type u4 = types_at_u(((uint32_t)(4)));
        uint8_t ok = 1;
        if (!(test_flags_are(arena, SLOP_STR("B0(f0(x)), S0(x, f0(x))"), test_two_lits(arena, types_atom1(b0, f0x), types_atom2(s0, x, f0x)), SLOP_STR("TT")))) {
            ok = 0;
        }
        if (!(test_flags_are(arena, SLOP_STR("B0(x), B0(f0(x))"), test_two_lits(arena, types_atom1(b0, f0x), types_atom1(b0, x)), SLOP_STR("FT")))) {
            ok = 0;
        }
        if (!(test_flags_are(arena, SLOP_STR("B0(x), f1(x) ≈ f0(x)"), test_two_lits(arena, types_eq_lit(f0x, f1x), types_atom1(b0, x)), SLOP_STR("TT")))) {
            ok = 0;
        }
        if (!(test_flags_are(arena, SLOP_STR("f0(x) ≈ x, f1(x) ≈ x"), test_two_lits(arena, types_eq_lit(f1x, x), types_eq_lit(f0x, x)), SLOP_STR("FT")))) {
            ok = 0;
        }
        if (!(test_flags_are(arena, SLOP_STR("f0(x) ≈ x, f0(x) ≉ x"), test_two_lits(arena, types_neq_lit(f0x, x), types_eq_lit(x, f0x)), SLOP_STR("FT")))) {
            ok = 0;
        }
        if (!(test_flags_are(arena, SLOP_STR("B0(u2), B0(u4)"), test_two_lits(arena, types_atom1(b0, u4), types_atom1(b0, u2)), SLOP_STR("TF")))) {
            ok = 0;
        }
        if (!(test_flags_are(arena, SLOP_STR("B0(y), x ≈ y"), test_two_lits(arena, types_eq_lit(y, x), types_atom1(b0, y)), SLOP_STR("TF")))) {
            ok = 0;
        }
        if (!(test_lits_strict(arena, test_ord_table(arena), test_sample_lits(arena)))) {
            ok = 0;
        }
        return ok;
    }
}

slop_list_types_Lit test_sample_lits(slop_arena* arena) {
    {
        __auto_type x = types_at_x();
        __auto_type y = types_at_y();
        __auto_type f0x = types_at_fx(((uint32_t)(0)));
        __auto_type u2 = types_at_u(((uint32_t)(2)));
        __auto_type out = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_atom1(((uint32_t)(0)), x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_atom1(((uint32_t)(0)), f0x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_atom1(((uint32_t)(1)), y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_atom2(((uint32_t)(0)), x, f0x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_atom2(((uint32_t)(0)), u2, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_eq_lit(f0x, x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_eq_lit(x, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_eq_lit(u2, x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_neq_lit(f0x, x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (types_neq_lit(u2, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

uint8_t test_lits_strict(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Lit ls) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = ls;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (sriqorder_lit_gt(arena, ord, a, a)) {
                    printf("%s\n", "  [max] a literal above itself");
                    ok = 0;
                }
                {
                    __auto_type _coll = ls;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type b = _coll.data[_i];
                        if (sriqorder_lit_gt(arena, ord, a, b) && sriqorder_lit_gt(arena, ord, b, a)) {
                            printf("%s\n", "  [max] two literals above each other");
                            ok = 0;
                        }
                    }
                }
            }
        }
        return ok;
    }
}

slop_list_types_Lit test_letter_atoms(slop_arena* arena, slop_string letters) {
    {
        __auto_type out = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = test_strs(arena, letters);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type w = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (types_atom1(((uint32_t)((((int64_t)(strlib_char_at(w, 0))) - 65))), types_at_x())); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

types_Clause test_cl(slop_arena* arena, slop_string body, slop_string head) {
    return sriqclauses_make_clause(arena, test_letter_atoms(arena, body), test_letter_atoms(arena, head));
}

types_Clause test_with_lit(slop_arena* arena, types_Clause c, types_Lit l) {
    {
        __auto_type h = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = c.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(h); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        ({ __auto_type _lst_p = &(h); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return sriqclauses_make_clause(arena, c.body, h);
    }
}

slop_list_types_Clause test_clauses_of(slop_arena* arena, types_Clause a, types_Clause b) {
    {
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

uint8_t test_test_sriq_inhat_rows(slop_arena* arena) {
    {
        __auto_type x = types_at_x();
        __auto_type y = types_at_y();
        __auto_type fx = types_at_fx(((uint32_t)(0)));
        __auto_type none_set = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type w = test_clauses_of(arena, test_cl(arena, SLOP_STR("A"), SLOP_STR("B C")), test_cl(arena, SLOP_STR("D"), SLOP_STR("C")));
        __auto_type ay = sriqclauses_make_clause(arena, test_one_lit(arena, types_atom1(((uint32_t)(0)), y)), test_one_lit(arena, types_atom1(((uint32_t)(1)), y)));
        return ((sriqsubsume_in_hat(test_with_lit(arena, test_cl(arena, SLOP_STR("A"), SLOP_STR("B")), types_eq_lit(fx, fx)), none_set)) && (sriqsubsume_in_hat(test_with_lit(arena, test_with_lit(arena, test_cl(arena, SLOP_STR("A"), SLOP_STR("")), types_eq_lit(fx, x)), types_neq_lit(x, fx)), none_set)) && (!(sriqsubsume_in_hat(test_with_lit(arena, test_cl(arena, SLOP_STR("A"), SLOP_STR("B")), types_neq_lit(fx, fx)), none_set))) && (!(sriqsubsume_in_hat(test_with_lit(arena, test_cl(arena, SLOP_STR("A"), SLOP_STR("")), types_eq_lit(fx, x)), none_set))) && (!(sriqsubsume_in_hat(test_with_lit(arena, test_with_lit(arena, test_cl(arena, SLOP_STR("A"), SLOP_STR("")), types_eq_lit(fx, x)), types_neq_lit(y, fx)), none_set))) && (sriqsubsume_in_hat(test_cl(arena, SLOP_STR("A"), SLOP_STR("B C")), w)) && (sriqsubsume_in_hat(test_cl(arena, SLOP_STR("A B"), SLOP_STR("B C D")), w)) && (sriqsubsume_in_hat(test_cl(arena, SLOP_STR("D A"), SLOP_STR("C")), w)) && (!(sriqsubsume_in_hat(test_cl(arena, SLOP_STR(""), SLOP_STR("B C")), w))) && (!(sriqsubsume_in_hat(test_cl(arena, SLOP_STR("A"), SLOP_STR("B")), w))) && (!(sriqsubsume_in_hat(test_cl(arena, SLOP_STR("B"), SLOP_STR("C")), w))) && (!(sriqsubsume_in_hat(ay, test_clauses_of(arena, test_cl(arena, SLOP_STR("A"), SLOP_STR("B")), test_cl(arena, SLOP_STR("C"), SLOP_STR("D")))))));
    }
}

slop_list_types_Clause test_reference_min(slop_arena* arena, slop_list_types_Clause xs) {
    {
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    uint8_t keep = !(sriqsubsume_tautology(c));
                    {
                        __auto_type _coll = xs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type d = _coll.data[_i];
                            if (!(sriqclauses_clause_eq(c, d)) && sriqsubsume_subsumes(d, c)) {
                                keep = 0;
                            }
                        }
                    }
                    if (keep && !(test_in_list(out, c))) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

uint8_t test_in_list(slop_list_types_Clause xs, types_Clause c) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (sriqclauses_clause_eq(x, c)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t test_same_clause_set(slop_list_types_Clause a, slop_list_types_Clause b) {
    {
        uint8_t ok = (((int64_t)((a).len)) == ((int64_t)((b).len)));
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(test_in_list(b, c))) {
                    ok = 0;
                }
            }
        }
        {
            __auto_type _coll = b;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(test_in_list(a, c))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

slop_list_types_Clause test_commit_w(slop_arena* arena) {
    return test_clauses_of(arena, test_cl(arena, SLOP_STR("A"), SLOP_STR("B C")), test_cl(arena, SLOP_STR("D"), SLOP_STR("C")));
}

slop_list_types_Clause test_commit_candidates(slop_arena* arena) {
    {
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (test_cl(arena, SLOP_STR("A"), SLOP_STR("B"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (test_cl(arena, SLOP_STR("A D"), SLOP_STR("B"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (test_with_lit(arena, test_cl(arena, SLOP_STR("B"), SLOP_STR("")), types_eq_lit(types_at_x(), types_at_x()))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (test_cl(arena, SLOP_STR("D"), SLOP_STR("C B"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (test_cl(arena, SLOP_STR(""), SLOP_STR("C"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (test_cl(arena, SLOP_STR("A B"), SLOP_STR("C"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

types_Clause test_clause_list_at(slop_list_types_Clause xs, int64_t i, types_Clause fallback) {
    __auto_type _mv_1547 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1547.has_value) {
        __auto_type c = _mv_1547.value;
        return c;
    } else if (!_mv_1547.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_list_types_Clause test_permuted(slop_arena* arena, slop_list_types_Clause xs, int64_t code) {
    {
        __auto_type n = ((int64_t)(((int64_t)((xs).len))));
        __auto_type fallback = test_cl(arena, SLOP_STR(""), SLOP_STR(""));
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type used = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t c = code;
        uint8_t ok = 1;
        int64_t k = 0;
        while (k < n) {
            ({ __auto_type _lst_p = &(used); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            k = (k + 1);
        }
        k = 0;
        while (k < n) {
            {
                __auto_type p = (c % n);
                if (({ __auto_type _mv = ({ __auto_type _lst = used; size_t _idx = (size_t)p; slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type b = _mv.value; b; }) : (1); })) {
                    ok = 0;
                } else {
                    ({ __auto_type _set_lst = &(used); size_t _set_idx = (size_t)(p); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (test_clause_list_at(xs, p, fallback)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                c = (c / n);
                k = (k + 1);
            }
        }
        if (ok) {
            return out;
        } else {
            return ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        }
    }
}

slop_list_types_Clause test_appended(slop_arena* arena, slop_list_types_Clause a, slop_list_types_Clause b) {
    {
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = b;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_Clause test_new_members(slop_arena* arena, slop_list_types_Clause xs, slop_list_types_Clause ws) {
    {
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(test_in_list(ws, c))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

uint8_t test_order_ok(slop_arena* arena, slop_list_types_Clause ws, slop_list_types_Clause order, slop_list_types_Clause want, slop_list_types_Clause want_added) {
    {
        __auto_type r = sriqsubsume_commit_min(arena, ws, order);
        return (test_same_clause_set(r.set, want) && test_same_clause_set(r.added, want_added));
    }
}

uint8_t test_test_sriq_commit_min_permutation(slop_arena* arena) {
    {
        __auto_type ws = test_commit_w(arena);
        __auto_type cs = test_commit_candidates(arena);
        __auto_type want = test_reference_min(arena, test_appended(arena, ws, cs));
        __auto_type want_added = test_new_members(arena, want, ws);
        __auto_type expected = test_clauses_of(arena, test_cl(arena, SLOP_STR("A"), SLOP_STR("B")), test_cl(arena, SLOP_STR(""), SLOP_STR("C")));
        int64_t orders = 0;
        int64_t bad = 0;
        int64_t code = 0;
        while (code < 46656) {
            {
                __auto_type order = test_permuted(arena, cs, code);
                if (((int64_t)((order).len)) > 0) {
                    orders = (orders + 1);
                    if (!(test_order_ok(arena, ws, order, want, want_added))) {
                        bad = (bad + 1);
                    }
                }
                code = (code + 1);
            }
        }
        if (orders != 720) {
            printf("%s\n", "  [commit] not 720 orders");
        }
        if (bad > 0) {
            printf("%s", "  [commit] orders that differ: ");
            printf("%.*s\n", (int)(int_to_string(arena, bad)).len, (int_to_string(arena, bad)).data);
        }
        if (!(test_same_clause_set(want, expected))) {
            printf("%s\n", "  [commit] min(W ∪ C) is not {A → B, ⊤ → C}");
        }
        return (((orders == 720)) && ((bad == 0)) && (test_same_clause_set(want, expected)) && (test_same_clause_set(want_added, expected)));
    }
}

uint8_t test_keeps_but_adds_not(slop_arena* arena) {
    {
        __auto_type ws = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type cs = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ws); __auto_type _item = (test_cl(arena, SLOP_STR("A"), SLOP_STR("B"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(cs); __auto_type _item = (test_cl(arena, SLOP_STR("C"), SLOP_STR("D"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type r = sriqsubsume_commit_min(arena, ws, cs);
            return (((((int64_t)((r.set).len)) == 2)) && (test_in_list(r.set, test_cl(arena, SLOP_STR("A"), SLOP_STR("B")))) && ((((int64_t)((r.added).len)) == 1)) && (test_in_list(r.added, test_cl(arena, SLOP_STR("C"), SLOP_STR("D")))));
        }
    }
}

uint8_t test_test_sriq_commit_survivors(slop_arena* arena) {
    {
        __auto_type r = sriqsubsume_commit_min(arena, ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), test_clauses_of(arena, test_cl(arena, SLOP_STR("A B"), SLOP_STR("C")), test_cl(arena, SLOP_STR(""), SLOP_STR("C"))));
        __auto_type m = sriqsubsume_commit_min(arena, test_commit_w(arena), test_commit_candidates(arena));
        return ((test_in_list(r.added, test_cl(arena, SLOP_STR(""), SLOP_STR("C")))) && ((((int64_t)((r.added).len)) == 1)) && (test_keeps_but_adds_not(arena)) && (test_same_clause_set(m.set, test_clauses_of(arena, test_cl(arena, SLOP_STR("A"), SLOP_STR("B")), test_cl(arena, SLOP_STR(""), SLOP_STR("C"))))));
    }
}

uint8_t test_test_sriq_inhat_persists(slop_arena* arena) {
    {
        __auto_type ws = test_commit_w(arena);
        __auto_type after = sriqsubsume_commit_min(arena, ws, test_commit_candidates(arena)).set;
        __auto_type samples = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t ok = 1;
        ({ __auto_type _lst_p = &(samples); __auto_type _item = (test_cl(arena, SLOP_STR("A B"), SLOP_STR("B C"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(samples); __auto_type _item = (test_cl(arena, SLOP_STR("A D"), SLOP_STR("C"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(samples); __auto_type _item = (test_cl(arena, SLOP_STR("A"), SLOP_STR("B C D"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(samples); __auto_type _item = (test_cl(arena, SLOP_STR("D"), SLOP_STR("C"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(samples); __auto_type _item = (test_with_lit(arena, test_cl(arena, SLOP_STR("C"), SLOP_STR("")), types_eq_lit(types_at_y(), types_at_y()))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = samples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (sriqsubsume_in_hat(c, ws) && !(sriqsubsume_in_hat(c, after))) {
                    ok = 0;
                }
            }
        }
        return ((ok) && (!(test_in_list(after, test_cl(arena, SLOP_STR("A"), SLOP_STR("B C"))))) && (!(test_in_list(after, test_cl(arena, SLOP_STR("D"), SLOP_STR("C"))))));
    }
}

types_Lit test_r_atom(int64_t c, types_ATerm t) {
    return types_atom1(((uint32_t)(c)), t);
}

types_Lit test_r_role(int64_t r, types_ATerm a, types_ATerm b) {
    return types_atom2(((uint32_t)(r)), a, b);
}

types_ATerm test_r_fx(int64_t f) {
    return types_at_fx(((uint32_t)(f)));
}

types_Clause test_r_clause(slop_arena* arena, slop_list_types_Lit body, slop_list_types_Lit head) {
    return sriqclauses_make_clause(arena, body, head);
}

slop_list_sriq_Premise test_r_premises(slop_arena* arena, sriqorder_SriqOrder ord, types_Clause c) {
    {
        __auto_type out = ((slop_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < ((int64_t)(((int64_t)((c.head).len))))) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriq_select(arena, ord, c, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        return out;
    }
}

slop_list_sriq_Cands test_r_cands(slop_arena* arena, sriqorder_SriqOrder ord, int64_t atoms, slop_list_types_Clause cs) {
    {
        __auto_type ps = ((slop_list_sriq_Premise){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type out = ((slop_list_sriq_Cands){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type _coll = test_r_premises(arena, ord, c);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type p = _coll.data[_i];
                        ({ __auto_type _lst_p = &(ps); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        while (k < atoms) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriq_Cands){.ps = ps})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            k = (k + 1);
        }
        return out;
    }
}

slop_list_types_Clause test_r_hyper(slop_arena* arena, sriq_HState start, types_Clause ont, slop_list_types_Clause cs) {
    {
        __auto_type ord = sriqorder_named_consts(arena, 3);
        __auto_type rs = sriq_hyper_join(arena, start, ont.body, test_r_cands(arena, ord, ((int64_t)(((int64_t)((ont.body).len)))), cs), ont.head);
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriq_assemble(arena, r)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_Clause test_r_useful(slop_arena* arena, slop_list_types_Clause cs) {
    {
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(sriqsubsume_tautology(c)) && !(test_in_list(out, c))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

slop_list_types_Clause test_r_one(slop_arena* arena, types_Clause c) {
    {
        __auto_type out = ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

uint8_t test_hyper_is(slop_arena* arena, slop_string label, slop_list_types_Clause got, slop_list_types_Clause want) {
    if (test_same_clause_set(test_r_useful(arena, got), want)) {
        return 1;
    } else {
        printf("%s", "  [hyper] ");
        printf("%.*s\n", (int)(label).len, (label).data);
        return 0;
    }
}

sriq_Premise test_r_premise(slop_arena* arena, sriqorder_SriqOrder ord, types_Clause c, types_Lit l) {
    {
        int64_t at = 0;
        int64_t i = 0;
        {
            __auto_type _coll = c.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type h = _coll.data[_i];
                if (types_lit_eq(h, l)) {
                    at = i;
                }
                i = (i + 1);
            }
        }
        return sriq_select(arena, ord, c, at);
    }
}

uint8_t test_test_sriq_hyper_rows(slop_arena* arena) {
    {
        __auto_type x = types_at_x();
        __auto_type z1 = types_at_z(((uint32_t)(1)));
        __auto_type z2 = types_at_z(((uint32_t)(2)));
        __auto_type nolits = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type start = sriq_hyper_start(arena, types_at_x(), 1);
        __auto_type c15 = test_r_clause(arena, nolits, test_one_lit(arena, test_r_atom(0, x)));
        __auto_type c17 = test_r_clause(arena, nolits, test_one_lit(arena, test_r_role(0, x, test_r_fx(0))));
        __auto_type c18 = test_r_clause(arena, nolits, test_two_lits(arena, test_r_atom(3, x), test_r_atom(4, x)));
        __auto_type c20 = test_r_clause(arena, nolits, test_two_lits(arena, test_r_atom(3, x), test_r_role(0, x, test_r_fx(1))));
        __auto_type o2 = test_r_clause(arena, test_one_lit(arena, test_r_atom(0, x)), test_one_lit(arena, test_r_atom(1, test_r_fx(0))));
        __auto_type o3 = test_r_clause(arena, test_one_lit(arena, test_r_atom(0, x)), test_one_lit(arena, test_r_role(0, x, test_r_fx(0))));
        __auto_type o6 = test_r_clause(arena, test_one_lit(arena, test_r_atom(0, x)), test_two_lits(arena, test_r_atom(3, x), test_r_atom(4, x)));
        __auto_type o8 = test_r_clause(arena, test_one_lit(arena, test_r_atom(4, x)), test_one_lit(arena, test_r_role(0, x, test_r_fx(1))));
        __auto_type o7 = test_r_clause(arena, test_one_lit(arena, test_r_atom(4, x)), test_one_lit(arena, test_r_atom(2, test_r_fx(1))));
        __auto_type o9 = test_r_clause(arena, test_two_lits(arena, test_r_role(0, x, z1), test_r_role(0, x, z2)), test_one_lit(arena, types_eq_lit(z2, z1)));
        __auto_type blocked = test_r_clause(arena, nolits, test_two_lits(arena, test_r_atom(1, x), test_r_atom(1, test_r_fx(0))));
        __auto_type o_bc = test_r_clause(arena, test_one_lit(arena, test_r_atom(1, x)), test_one_lit(arena, test_r_atom(2, x)));
        __auto_type all = test_r_hyper(arena, start, o9, test_clauses_of(arena, c17, c20));
        return ((test_hyper_is(arena, SLOP_STR("(15) and (2) give (16)"), test_r_hyper(arena, start, o2, test_clauses_of(arena, c15, test_r_clause(arena, test_one_lit(arena, test_r_atom(2, x)), test_one_lit(arena, test_r_role(0, x, test_r_fx(0)))))), test_r_one(arena, test_r_clause(arena, nolits, test_one_lit(arena, test_r_atom(1, test_r_fx(0))))))) && (test_hyper_is(arena, SLOP_STR("(15) and (3) give (17)"), test_r_hyper(arena, start, o3, test_r_one(arena, c15)), test_r_one(arena, c17))) && (test_hyper_is(arena, SLOP_STR("(15) and (6) give (18)"), test_r_hyper(arena, start, o6, test_r_one(arena, c15)), test_r_one(arena, c18))) && (test_hyper_is(arena, SLOP_STR("(18) and (8) give (20)"), test_r_hyper(arena, start, o8, test_r_one(arena, c18)), test_r_one(arena, c20))) && (test_hyper_is(arena, SLOP_STR("(18) and (7) give (19)"), test_r_hyper(arena, start, o7, test_r_one(arena, c18)), test_r_one(arena, test_r_clause(arena, nolits, test_two_lits(arena, test_r_atom(3, x), test_r_atom(2, test_r_fx(1))))))) && (test_hyper_is(arena, SLOP_STR("(17), (20) and (9) give (21)"), all, test_r_one(arena, test_r_clause(arena, nolits, test_two_lits(arena, test_r_atom(3, x), types_eq_lit(test_r_fx(1), test_r_fx(0))))))) && ((((int64_t)((all).len)) == 4)) && (test_hyper_is(arena, SLOP_STR("a premise's body joins the conclusion's"), test_r_hyper(arena, start, o_bc, test_r_one(arena, test_r_clause(arena, test_one_lit(arena, test_r_atom(3, x)), test_one_lit(arena, test_r_atom(1, x))))), test_r_one(arena, test_r_clause(arena, test_one_lit(arena, test_r_atom(3, x)), test_one_lit(arena, test_r_atom(2, x)))))) && (test_hyper_is(arena, SLOP_STR("a literal below another is not selected"), test_r_hyper(arena, start, o_bc, test_r_one(arena, blocked)), ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena }))) && (test_test_sriq_hyper_dl4(arena)) && ((((int64_t)((sriq_hyper_join(arena, start, o9.body, ((slop_list_sriq_Cands){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), o9.head)).len)) == 0)));
    }
}

uint8_t test_test_sriq_hyper_dl4(slop_arena* arena) {
    {
        __auto_type x = types_at_x();
        __auto_type z1 = types_at_z(((uint32_t)(1)));
        __auto_type z2 = types_at_z(((uint32_t)(2)));
        __auto_type nolits = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type start = sriq_hyper_start(arena, types_at_x(), 1);
        __auto_type body = test_two_lits(arena, test_r_role(0, x, z1), test_r_role(0, x, z2));
        __auto_type o_dl4 = test_r_clause(arena, ({ ({ __auto_type _lst_p = &(body); __auto_type _item = (test_r_atom(1, z1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }); ({ __auto_type _lst_p = &(body); __auto_type _item = (test_r_atom(1, z2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }); body; }), test_one_lit(arena, types_eq_lit(z2, z1)));
        __auto_type cs = test_clauses_of(arena, test_r_clause(arena, nolits, test_one_lit(arena, test_r_role(0, x, test_r_fx(0)))), test_r_clause(arena, nolits, test_one_lit(arena, test_r_role(0, x, test_r_fx(1)))));
        __auto_type got = ({ ({ __auto_type _lst_p = &(cs); __auto_type _item = (test_r_clause(arena, nolits, test_one_lit(arena, test_r_atom(1, test_r_fx(0))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }); test_r_hyper(arena, start, o_dl4, cs); });
        return ((((int64_t)((got).len)) == 1) && test_hyper_is(arena, SLOP_STR("DL4's repeated neighbour is a tautology"), got, ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena })));
    }
}

uint8_t test_test_sriq_hyper_root_rows(slop_arena* arena) {
    {
        __auto_type x = types_at_x();
        __auto_type y = types_at_y();
        __auto_type z1 = types_at_z(((uint32_t)(1)));
        __auto_type u0 = types_at_u(((uint32_t)(0)));
        __auto_type u1 = types_at_u(((uint32_t)(1)));
        __auto_type nolits = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type root = sriq_hyper_start(arena, types_at_x(), 0);
        __auto_type b_u0 = test_r_clause(arena, nolits, test_one_lit(arena, test_r_atom(1, u0)));
        __auto_type b_y = test_r_clause(arena, nolits, test_one_lit(arena, test_r_atom(1, y)));
        __auto_type s_u1u0 = test_r_clause(arena, nolits, test_one_lit(arena, test_r_role(1, u1, u0)));
        __auto_type o_bc = test_r_clause(arena, test_one_lit(arena, test_r_atom(1, x)), test_one_lit(arena, test_r_atom(2, x)));
        __auto_type o_bf = test_r_clause(arena, test_one_lit(arena, test_r_atom(1, x)), test_one_lit(arena, test_r_atom(0, test_r_fx(0))));
        __auto_type o_top = test_r_clause(arena, nolits, test_two_lits(arena, test_r_atom(3, x), test_r_atom(5, x)));
        __auto_type o_dl3 = test_r_clause(arena, test_two_lits(arena, test_r_role(1, z1, x), test_r_atom(1, x)), test_one_lit(arena, test_r_atom(2, z1)));
        __auto_type o_self = test_r_clause(arena, test_one_lit(arena, test_r_role(1, x, x)), test_one_lit(arena, test_r_atom(2, x)));
        return ((test_test_sriq_hyper_example1(arena)) && (test_hyper_is(arena, SLOP_STR("B(u0) and B(x) → C(x) give C(u0)"), test_r_hyper(arena, root, o_bc, test_r_one(arena, b_u0)), test_r_one(arena, test_r_clause(arena, nolits, test_one_lit(arena, test_r_atom(2, u0)))))) && (test_hyper_is(arena, SLOP_STR("x never binds y at the root"), test_r_hyper(arena, root, o_bc, test_r_one(arena, b_y)), ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena }))) && (test_hyper_is(arena, SLOP_STR("f(x) at the root is f(u0)"), test_r_hyper(arena, root, o_bf, test_r_one(arena, b_u0)), test_r_one(arena, test_r_clause(arena, nolits, test_one_lit(arena, test_r_atom(0, types_at_fu(((uint32_t)(0)), ((uint32_t)(0))))))))) && (test_hyper_is(arena, SLOP_STR("a bodiless clause on the constant it is given"), test_r_hyper(arena, sriq_hyper_start(arena, u1, 1), o_top, ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena })), test_r_one(arena, test_r_clause(arena, nolits, test_two_lits(arena, test_r_atom(3, u1), test_r_atom(5, u1)))))) && (test_hyper_is(arena, SLOP_STR("DL3 at the root binds z1 to another constant"), test_r_hyper(arena, root, o_dl3, test_clauses_of(arena, b_u0, s_u1u0)), test_r_one(arena, test_r_clause(arena, nolits, test_one_lit(arena, test_r_atom(2, u1)))))) && (test_hyper_is(arena, SLOP_STR("S(x, x) does not match S(u0, u1)"), test_r_hyper(arena, root, o_self, test_r_one(arena, test_r_clause(arena, nolits, test_one_lit(arena, test_r_role(1, u0, u1))))), ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena }))) && (test_hyper_is(arena, SLOP_STR("S(x, x) matches S(u1, u1)"), test_r_hyper(arena, root, o_self, test_r_one(arena, test_r_clause(arena, nolits, test_one_lit(arena, test_r_role(1, u1, u1))))), test_r_one(arena, test_r_clause(arena, nolits, test_one_lit(arena, test_r_atom(2, u1)))))));
    }
}

uint8_t test_test_sriq_hyper_example1(slop_arena* arena) {
    {
        __auto_type x = types_at_x();
        __auto_type y = types_at_y();
        __auto_type z1 = types_at_z(((uint32_t)(1)));
        __auto_type o = types_at_u(((uint32_t)(0)));
        __auto_type root = sriq_hyper_start(arena, types_at_x(), 0);
        __auto_type c114 = test_r_clause(arena, test_one_lit(arena, test_r_atom(3, o)), test_one_lit(arena, test_r_atom(3, o)));
        __auto_type c115 = test_r_clause(arena, test_one_lit(arena, test_r_atom(2, o)), test_one_lit(arena, test_r_atom(2, o)));
        __auto_type c116 = test_r_clause(arena, test_one_lit(arena, test_r_role(1, y, o)), test_one_lit(arena, test_r_role(1, y, o)));
        __auto_type o88 = test_r_clause(arena, test_two_lits(arena, test_r_atom(2, x), test_r_atom(3, x)), test_one_lit(arena, test_r_atom(5, x)));
        __auto_type o90 = test_r_clause(arena, test_two_lits(arena, test_r_role(1, z1, x), test_r_atom(5, x)), test_one_lit(arena, test_r_atom(6, z1)));
        __auto_type c117 = test_r_clause(arena, test_two_lits(arena, test_r_atom(2, o), test_r_atom(3, o)), test_one_lit(arena, test_r_atom(5, o)));
        __auto_type b118 = test_two_lits(arena, test_r_atom(2, o), test_r_atom(3, o));
        ({ __auto_type _lst_p = &(b118); __auto_type _item = (test_r_role(1, y, o)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return (test_hyper_is(arena, SLOP_STR("(114), (115) and (88) give (117)"), test_r_hyper(arena, root, o88, test_clauses_of(arena, c114, c115)), test_r_one(arena, c117)) && test_hyper_is(arena, SLOP_STR("(117), (116) and (90) give (118)"), test_r_hyper(arena, root, o90, test_clauses_of(arena, c117, c116)), test_r_one(arena, test_r_clause(arena, b118, test_one_lit(arena, test_r_atom(6, y))))));
    }
}

uint8_t test_test_sriq_ineq_factor_core_rows(slop_arena* arena) {
    {
        __auto_type x = types_at_x();
        __auto_type y = types_at_y();
        __auto_type f1x = test_r_fx(1);
        __auto_type f0x = test_r_fx(0);
        __auto_type nolits = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type ord = sriqorder_named_consts(arena, 3);
        __auto_type low = test_r_clause(arena, nolits, test_two_lits(arena, types_neq_lit(x, x), test_r_atom(1, f0x)));
        __auto_type p_low_neq = test_r_premise(arena, ord, low, types_neq_lit(x, x));
        __auto_type p_eq = sriq_select(arena, ord, test_r_clause(arena, nolits, test_one_lit(arena, types_eq_lit(f1x, f1x))), 0);
        __auto_type p_non = sriq_select(arena, ord, test_r_clause(arena, nolits, test_one_lit(arena, types_neq_lit(f1x, x))), 0);
        __auto_type fac = test_r_clause(arena, nolits, test_two_lits(arena, types_eq_lit(f1x, y), types_eq_lit(f1x, f0x)));
        __auto_type p_fac = test_r_premise(arena, ord, fac, types_eq_lit(f1x, f0x));
        __auto_type ok_factor = sriq_factor_rule(arena, ord, p_fac, types_eq_lit(f1x, y), f1x);
        return ((sriqclauses_clause_eq(sriq_assemble(arena, sriq_ineq_rule(sriq_select(arena, ord, test_r_clause(arena, nolits, test_one_lit(arena, types_neq_lit(f1x, f1x))), 0))), test_r_clause(arena, nolits, nolits))) && (!(p_low_neq.maxed)) && (sriq_ineq_rule(p_low_neq).fires) && (sriqclauses_clause_eq(sriq_assemble(arena, sriq_ineq_rule(p_low_neq)), test_r_clause(arena, nolits, test_one_lit(arena, test_r_atom(1, f0x))))) && (!(sriq_ineq_rule(p_eq).fires)) && (!(sriq_ineq_rule(p_non).fires)) && (p_fac.maxed) && (ok_factor.fires) && (sriqclauses_clause_eq(sriq_assemble(arena, ok_factor), test_r_clause(arena, nolits, test_two_lits(arena, types_neq_lit(y, f0x), types_eq_lit(f1x, f0x))))) && (test_test_sriq_factor_each_condition(arena)) && (sriq_core_rule(arena, test_r_atom(0, x)).fires) && (sriqclauses_clause_eq(sriq_assemble(arena, sriq_core_rule(arena, test_r_atom(0, x))), test_r_clause(arena, nolits, test_one_lit(arena, test_r_atom(0, x))))));
    }
}

uint8_t test_test_sriq_factor_each_condition(slop_arena* arena) {
    {
        __auto_type x = types_at_x();
        __auto_type y = types_at_y();
        __auto_type f1x = test_r_fx(1);
        __auto_type f0x = test_r_fx(0);
        __auto_type nolits = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type ord = sriqorder_named_consts(arena, 3);
        __auto_type fac = test_r_clause(arena, nolits, test_two_lits(arena, types_eq_lit(f1x, y), types_eq_lit(f1x, f0x)));
        __auto_type p_low = test_r_premise(arena, ord, fac, types_eq_lit(f1x, y));
        __auto_type p_fac = test_r_premise(arena, ord, fac, types_eq_lit(f1x, f0x));
        __auto_type fy = test_r_clause(arena, nolits, test_two_lits(arena, types_eq_lit(f1x, y), types_eq_lit(f0x, y)));
        __auto_type p_fy = test_r_premise(arena, ord, fy, types_eq_lit(f1x, y));
        __auto_type fz = test_r_clause(arena, nolits, test_two_lits(arena, types_eq_lit(f1x, f0x), types_eq_lit(f0x, y)));
        __auto_type p_fz = test_r_premise(arena, ord, fz, types_eq_lit(f1x, f0x));
        __auto_type u0 = types_at_u(((uint32_t)(0)));
        __auto_type xy = test_r_clause(arena, nolits, test_two_lits(arena, types_eq_lit(x, y), types_eq_lit(u0, y)));
        __auto_type p_xy = test_r_premise(arena, ord, xy, types_eq_lit(x, y));
        __auto_type p_uy = test_r_premise(arena, ord, xy, types_eq_lit(u0, y));
        return ((!(p_low.maxed)) && (!(sriq_factor_rule(arena, ord, p_low, types_eq_lit(f1x, f0x), f1x).fires)) && (p_fy.maxed) && (!(sriq_factor_rule(arena, ord, p_fy, types_eq_lit(f0x, y), y).fires)) && (!(sriq_factor_rule(arena, ord, p_fac, types_eq_lit(f1x, x), f1x).fires)) && (p_fz.maxed) && (!(sriq_factor_rule(arena, ord, p_fz, types_eq_lit(f0x, y), f1x).fires)) && (p_xy.maxed) && (!(sriq_factor_rule(arena, ord, p_xy, types_eq_lit(u0, y), u0).fires)) && (p_uy.maxed) && (sriq_factor_rule(arena, ord, p_uy, types_eq_lit(x, y), y).fires) && (sriqclauses_clause_eq(sriq_assemble(arena, sriq_factor_rule(arena, ord, p_uy, types_eq_lit(x, y), y)), test_r_clause(arena, nolits, test_two_lits(arena, types_neq_lit(x, u0), types_eq_lit(u0, y))))));
    }
}

sriq_Pos test_r_pos(int64_t k, uint8_t inner) {
    return ((sriq_Pos){.arg = ((uint32_t)(k)), .inner = inner});
}

types_Clause test_r_top(slop_arena* arena, slop_list_types_Lit head) {
    return test_r_clause(arena, ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), head);
}

sriq_RConcl test_r_eq(slop_arena* arena, uint8_t root, types_Clause c1, types_Lit l1, int64_t k1, types_Clause c2, types_Lit l2, sriq_Pos p) {
    {
        __auto_type ord = sriqorder_named_consts(arena, 3);
        return sriq_eq_rule(arena, ord, root, test_r_premise(arena, ord, c1, l1), ((uint32_t)(k1)), test_r_premise(arena, ord, c2, l2), p);
    }
}

uint8_t test_eq_gives(slop_arena* arena, slop_string label, sriq_RConcl r, types_Clause want) {
    if (r.fires && sriqclauses_clause_eq(sriq_assemble(arena, r), want)) {
        return 1;
    } else {
        printf("%s", "  [eq] ");
        printf("%.*s\n", (int)(label).len, (label).data);
        return 0;
    }
}

uint8_t test_test_sriq_eq_rows(slop_arena* arena) {
    {
        __auto_type x = types_at_x();
        __auto_type f0x = test_r_fx(0);
        __auto_type f1x = test_r_fx(1);
        __auto_type f2x = test_r_fx(2);
        __auto_type o = types_at_u(((uint32_t)(0)));
        __auto_type u1 = types_at_u(((uint32_t)(1)));
        __auto_type c21 = test_r_top(arena, test_two_lits(arena, test_r_atom(3, x), types_eq_lit(f1x, f0x)));
        __auto_type c19 = test_r_top(arena, test_two_lits(arena, test_r_atom(3, x), test_r_atom(2, f1x)));
        __auto_type c95 = test_r_top(arena, test_two_lits(arena, test_r_atom(6, x), types_eq_lit(x, o)));
        __auto_type c94 = test_r_top(arena, test_two_lits(arena, test_r_atom(6, x), test_r_atom(3, x)));
        __auto_type c148 = test_r_top(arena, test_one_lit(arena, types_eq_lit(f2x, o)));
        __auto_type c147 = test_r_top(arena, test_one_lit(arena, test_r_role(2, f2x, x)));
        __auto_type root_eq = test_r_top(arena, test_one_lit(arena, types_eq_lit(u1, o)));
        __auto_type root_s = test_r_top(arena, test_one_lit(arena, test_r_role(1, u1, u1)));
        __auto_type root_f = test_r_top(arena, test_one_lit(arena, test_r_atom(1, types_at_fu(((uint32_t)(0)), ((uint32_t)(1))))));
        return ((test_eq_gives(arena, SLOP_STR("(21) and (19) give (22)"), test_r_eq(arena, 0, c21, types_eq_lit(f1x, f0x), test_side_of(types_eq_lit(f1x, f0x), f1x), c19, test_r_atom(2, f1x), test_r_pos(1, 0)), test_r_top(arena, test_two_lits(arena, test_r_atom(3, x), test_r_atom(2, f0x))))) && (test_eq_gives(arena, SLOP_STR("(95) and (94) give (96)"), test_r_eq(arena, 0, c95, types_eq_lit(x, o), test_side_of(types_eq_lit(x, o), x), c94, test_r_atom(3, x), test_r_pos(1, 0)), test_r_top(arena, test_two_lits(arena, test_r_atom(6, x), test_r_atom(3, o))))) && (test_eq_gives(arena, SLOP_STR("(148) and (147) give (149)"), test_r_eq(arena, 0, c148, types_eq_lit(f2x, o), test_side_of(types_eq_lit(f2x, o), f2x), c147, test_r_role(2, f2x, x), test_r_pos(1, 0)), test_r_top(arena, test_one_lit(arena, test_r_role(2, o, x))))) && (test_eq_gives(arena, SLOP_STR("the root rewrites u1 in both arguments"), test_r_eq(arena, 1, root_eq, types_eq_lit(u1, o), test_side_of(types_eq_lit(u1, o), u1), root_s, test_r_role(1, u1, u1), test_r_pos(1, 0)), test_r_top(arena, test_one_lit(arena, test_r_role(1, o, o))))) && (test_eq_gives(arena, SLOP_STR("away from the root, only at p"), test_r_eq(arena, 0, root_eq, types_eq_lit(u1, o), test_side_of(types_eq_lit(u1, o), u1), root_s, test_r_role(1, u1, u1), test_r_pos(1, 0)), test_r_top(arena, test_one_lit(arena, test_r_role(1, o, u1))))) && (test_eq_gives(arena, SLOP_STR("the root rewrites u1 under f"), test_r_eq(arena, 1, root_eq, types_eq_lit(u1, o), test_side_of(types_eq_lit(u1, o), u1), root_f, test_r_atom(1, types_at_fu(((uint32_t)(0)), ((uint32_t)(1)))), test_r_pos(1, 1)), test_r_top(arena, test_one_lit(arena, test_r_atom(1, types_at_fu(((uint32_t)(0)), ((uint32_t)(0)))))))) && (test_test_sriq_eq_excluded(arena)));
    }
}

int64_t test_side_of(types_Lit l, types_ATerm s) {
    if (types_aterm_eq(l.t1, s)) {
        return 1;
    } else {
        return 2;
    }
}

uint8_t test_test_sriq_eq_excluded(slop_arena* arena) {
    {
        __auto_type x = types_at_x();
        __auto_type y = types_at_y();
        __auto_type f0x = test_r_fx(0);
        __auto_type f1x = test_r_fx(1);
        __auto_type o = types_at_u(((uint32_t)(0)));
        __auto_type cxy = test_r_top(arena, test_one_lit(arena, types_eq_lit(x, y)));
        __auto_type cyu = test_r_top(arena, test_one_lit(arena, types_eq_lit(y, o)));
        __auto_type cxo = test_r_top(arena, test_one_lit(arena, types_eq_lit(x, o)));
        __auto_type bx = test_r_top(arena, test_one_lit(arena, test_r_atom(1, x)));
        __auto_type bo = test_r_top(arena, test_one_lit(arena, test_r_atom(1, o)));
        __auto_type syx = test_r_top(arena, test_one_lit(arena, test_r_role(1, y, x)));
        __auto_type bfx = test_r_top(arena, test_one_lit(arena, test_r_atom(1, f0x)));
        __auto_type cf = test_r_top(arena, test_one_lit(arena, types_eq_lit(f1x, f0x)));
        __auto_type bf1 = test_r_top(arena, test_one_lit(arena, test_r_atom(1, f1x)));
        __auto_type bf0 = test_r_top(arena, test_one_lit(arena, test_r_atom(1, f0x)));
        __auto_type e2 = test_r_top(arena, test_one_lit(arena, types_eq_lit(f1x, x)));
        __auto_type low = test_r_top(arena, test_two_lits(arena, types_eq_lit(f1x, y), types_eq_lit(f1x, f0x)));
        return ((!(test_r_eq(arena, 0, cxy, types_eq_lit(x, y), test_side_of(types_eq_lit(x, y), x), bx, test_r_atom(1, x), test_r_pos(1, 0)).fires)) && (!(test_r_eq(arena, 0, cyu, types_eq_lit(y, o), test_side_of(types_eq_lit(y, o), o), bo, test_r_atom(1, o), test_r_pos(1, 0)).fires)) && (test_r_eq(arena, 0, cxo, types_eq_lit(x, o), test_side_of(types_eq_lit(x, o), x), bx, test_r_atom(1, x), test_r_pos(1, 0)).fires) && (!(test_r_eq(arena, 0, cxo, types_eq_lit(x, o), test_side_of(types_eq_lit(x, o), x), syx, test_r_role(1, y, x), test_r_pos(2, 0)).fires)) && (!(test_r_eq(arena, 0, cxo, types_eq_lit(x, o), test_side_of(types_eq_lit(x, o), x), bfx, test_r_atom(1, f0x), test_r_pos(1, 1)).fires)) && (!(test_r_eq(arena, 0, cxo, types_eq_lit(x, o), test_side_of(types_eq_lit(x, o), x), bx, test_r_atom(1, x), test_r_pos(2, 0)).fires)) && (!(test_r_eq(arena, 0, test_r_top(arena, test_one_lit(arena, types_neq_lit(f1x, f0x))), types_neq_lit(f1x, f0x), test_side_of(types_neq_lit(f1x, f0x), f1x), bf1, test_r_atom(1, f1x), test_r_pos(1, 0)).fires)) && (!(test_r_eq(arena, 0, cf, types_eq_lit(f1x, f0x), test_side_of(types_eq_lit(f1x, f0x), f0x), bf0, test_r_atom(1, f0x), test_r_pos(1, 0)).fires)) && (test_r_eq(arena, 0, cf, types_eq_lit(f1x, f0x), test_side_of(types_eq_lit(f1x, f0x), f1x), bf1, test_r_atom(1, f1x), test_r_pos(1, 0)).fires) && (!(test_r_eq(arena, 0, cxo, types_eq_lit(x, o), test_side_of(types_eq_lit(x, o), x), e2, types_eq_lit(f1x, x), test_r_pos(test_side_of(types_eq_lit(f1x, x), x), 0)).fires)) && (!(test_r_eq(arena, 0, cf, types_eq_lit(f1x, f0x), test_side_of(types_eq_lit(f1x, f0x), f1x), bf0, test_r_atom(1, f0x), test_r_pos(1, 0)).fires)) && (!(test_r_eq(arena, 0, low, types_eq_lit(f1x, y), test_side_of(types_eq_lit(f1x, y), f1x), bf1, test_r_atom(1, f1x), test_r_pos(1, 0)).fires)) && (!(test_r_eq(arena, 0, cf, types_eq_lit(f1x, f0x), test_side_of(types_eq_lit(f1x, f0x), f1x), low, types_eq_lit(f1x, y), test_r_pos(test_side_of(types_eq_lit(f1x, y), f1x), 0)).fires)));
    }
}

uint8_t test_test_sriq_join_rows(slop_arena* arena) {
    {
        __auto_type x = types_at_x();
        __auto_type o = types_at_u(((uint32_t)(0)));
        __auto_type u1 = types_at_u(((uint32_t)(1)));
        __auto_type nolits = ((slop_list_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type ord = sriqorder_named_consts(arena, 3);
        __auto_type c110 = test_r_top(arena, test_one_lit(arena, test_r_atom(2, o)));
        __auto_type pre = test_r_clause(arena, test_two_lits(arena, test_r_atom(2, o), test_r_atom(3, o)), test_one_lit(arena, test_r_atom(6, x)));
        __auto_type j = sriq_join_rule(arena, test_r_premise(arena, ord, c110, test_r_atom(2, o)), test_r_body(arena, pre, test_r_atom(2, o)));
        __auto_type cx = test_r_top(arena, test_one_lit(arena, test_r_atom(2, x)));
        __auto_type prex = test_r_clause(arena, test_one_lit(arena, test_r_atom(2, x)), test_one_lit(arena, test_r_atom(6, x)));
        __auto_type uu = test_r_top(arena, test_one_lit(arena, types_eq_lit(o, u1)));
        __auto_type preu = test_r_clause(arena, test_one_lit(arena, types_eq_lit(o, u1)), test_one_lit(arena, test_r_atom(6, x)));
        __auto_type xo = test_r_top(arena, test_one_lit(arena, types_eq_lit(x, o)));
        __auto_type prexo = test_r_clause(arena, test_one_lit(arena, types_eq_lit(x, o)), test_one_lit(arena, test_r_atom(6, x)));
        __auto_type low = test_r_top(arena, test_two_lits(arena, test_r_atom(2, o), test_r_atom(2, types_at_fu(((uint32_t)(0)), ((uint32_t)(0))))));
        return ((j.fires) && (sriqclauses_clause_eq(sriq_assemble(arena, j), test_r_clause(arena, test_one_lit(arena, test_r_atom(3, o)), test_one_lit(arena, test_r_atom(6, x))))) && (sriq_join_rule(arena, test_r_premise(arena, ord, uu, types_eq_lit(o, u1)), test_r_body(arena, preu, types_eq_lit(o, u1))).fires) && (!(sriq_join_rule(arena, test_r_premise(arena, ord, cx, test_r_atom(2, x)), test_r_body(arena, prex, test_r_atom(2, x))).fires)) && (!(sriq_join_rule(arena, test_r_premise(arena, ord, xo, types_eq_lit(x, o)), test_r_body(arena, prexo, types_eq_lit(x, o))).fires)) && (!(sriq_join_rule(arena, test_r_premise(arena, ord, test_r_top(arena, test_one_lit(arena, types_eq_lit(o, o))), types_eq_lit(o, o)), test_r_body(arena, test_r_clause(arena, test_one_lit(arena, types_eq_lit(o, o)), test_one_lit(arena, test_r_atom(6, x))), types_eq_lit(o, o))).fires)) && (!(sriq_join_rule(arena, test_r_premise(arena, ord, low, test_r_atom(2, o)), test_r_body(arena, pre, test_r_atom(2, o))).fires)) && (!(sriq_join_rule(arena, test_r_premise(arena, ord, c110, test_r_atom(2, o)), test_r_body(arena, pre, test_r_atom(3, o))).fires)));
    }
}

sriq_BodyView test_r_body(slop_arena* arena, types_Clause c, types_Lit l) {
    {
        int64_t at = 0;
        int64_t i = 0;
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                if (types_lit_eq(b, l)) {
                    at = i;
                }
                i = (i + 1);
            }
        }
        return sriq_body_at(arena, c, at);
    }
}

sriqorder_SriqOrder test_r_kids_order(slop_arena* arena) {
    {
        __auto_type base = sriqorder_named_consts(arena, 2);
        __auto_type cs = ((slop_list_sriqorder_ConstEntry){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = base.consts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                ({ __auto_type _lst_p = &(cs); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type e0 = sriqorder_const_entry(base, ((uint32_t)(0)));
            ({ __auto_type _lst_p = &(cs); __auto_type _item = (sriqorder_aux_const(e0, ((uint32_t)(0)), ((uint32_t)(2)), ((uint32_t)(1)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(cs); __auto_type _item = (sriqorder_aux_const(e0, ((uint32_t)(0)), ((uint32_t)(2)), ((uint32_t)(2)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(cs); __auto_type _item = (sriqorder_aux_const(sriqorder_aux_const(e0, ((uint32_t)(0)), ((uint32_t)(2)), ((uint32_t)(1))), ((uint32_t)(2)), ((uint32_t)(2)), ((uint32_t)(1)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(cs); __auto_type _item = (sriqorder_aux_const(e0, ((uint32_t)(0)), ((uint32_t)(3)), ((uint32_t)(1)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return ((sriqorder_SriqOrder){.consts = cs});
    }
}

slop_list_u32 test_r_ids(slop_arena* arena, int64_t a, int64_t b) {
    {
        __auto_type out = ((slop_list_u32){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (((uint32_t)(a))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        if (b >= 0) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (((uint32_t)(b))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return out;
    }
}

uint8_t test_test_sriq_nom_rows(slop_arena* arena) {
    {
        __auto_type x = types_at_x();
        __auto_type o = types_at_u(((uint32_t)(0)));
        __auto_type o2 = types_at_u(((uint32_t)(2)));
        __auto_type ord = test_r_kids_order(arena);
        __auto_type cb = test_r_top(arena, test_one_lit(arena, test_r_atom(7, o)));
        __auto_type c149 = test_r_top(arena, test_one_lit(arena, test_r_role(2, o, x)));
        __auto_type p1 = test_r_premise(arena, ord, cb, test_r_atom(7, o));
        __auto_type p2 = test_r_premise(arena, ord, c149, test_r_role(2, o, x));
        __auto_type n1 = sriq_nom_rule(arena, ord, 5, ((uint32_t)(7)), ((uint32_t)(2)), ((uint32_t)(1)), p1, p2, test_r_ids(arena, 2, -1));
        __auto_type n2 = sriq_nom_rule(arena, ord, 5, ((uint32_t)(7)), ((uint32_t)(2)), ((uint32_t)(2)), p1, p2, test_r_ids(arena, 2, 3));
        __auto_type d1 = test_r_premise(arena, ord, test_r_top(arena, test_one_lit(arena, test_r_atom(7, o2))), test_r_atom(7, o2));
        __auto_type d2 = test_r_premise(arena, ord, test_r_top(arena, test_one_lit(arena, test_r_role(2, o2, x))), test_r_role(2, o2, x));
        return ((n1.fires) && (sriqclauses_clause_eq(sriq_assemble(arena, n1), test_r_top(arena, test_one_lit(arena, types_eq_lit(x, o2))))) && (n2.fires) && (sriqclauses_clause_eq(sriq_assemble(arena, n2), test_r_top(arena, test_two_lits(arena, types_eq_lit(x, o2), types_eq_lit(x, types_at_u(((uint32_t)(3)))))))) && (sriq_nom_rule(arena, ord, 2, ((uint32_t)(7)), ((uint32_t)(2)), ((uint32_t)(1)), d1, d2, test_r_ids(arena, 4, -1)).fires) && (!(sriq_nom_rule(arena, ord, 1, ((uint32_t)(7)), ((uint32_t)(2)), ((uint32_t)(1)), d1, d2, test_r_ids(arena, 4, -1)).fires)) && (!(sriq_nom_rule(arena, ord, 5, ((uint32_t)(7)), ((uint32_t)(2)), ((uint32_t)(2)), p1, p2, test_r_ids(arena, 3, 2)).fires)) && (!(sriq_nom_rule(arena, ord, 5, ((uint32_t)(7)), ((uint32_t)(2)), ((uint32_t)(2)), p1, p2, test_r_ids(arena, 2, -1)).fires)) && (!(sriq_nom_rule(arena, ord, 5, ((uint32_t)(7)), ((uint32_t)(2)), ((uint32_t)(1)), p1, p2, test_r_ids(arena, 4, -1)).fires)) && (!(sriq_nom_rule(arena, ord, 5, ((uint32_t)(7)), ((uint32_t)(2)), ((uint32_t)(1)), p1, p2, test_r_ids(arena, 5, -1)).fires)) && (!(sriq_nom_rule(arena, ord, 5, ((uint32_t)(7)), ((uint32_t)(3)), ((uint32_t)(1)), p1, p2, test_r_ids(arena, 5, -1)).fires)) && (!(sriq_nom_rule(arena, ord, 5, ((uint32_t)(7)), ((uint32_t)(2)), ((uint32_t)(1)), test_r_premise(arena, ord, test_r_top(arena, test_two_lits(arena, test_r_atom(7, o), test_r_atom(7, types_at_fu(((uint32_t)(0)), ((uint32_t)(0)))))), test_r_atom(7, o)), p2, test_r_ids(arena, 2, -1)).fires)) && (!(sriq_nom_rule(arena, ord, 5, ((uint32_t)(7)), ((uint32_t)(2)), ((uint32_t)(1)), test_r_premise(arena, ord, test_r_top(arena, test_one_lit(arena, test_r_atom(7, x))), test_r_atom(7, x)), test_r_premise(arena, ord, test_r_top(arena, test_one_lit(arena, test_r_role(2, x, x))), test_r_role(2, x, x)), test_r_ids(arena, 2, -1)).fires)) && (!(sriq_nom_rule(arena, ord, 5, ((uint32_t)(7)), ((uint32_t)(2)), ((uint32_t)(1)), p1, test_r_premise(arena, ord, test_r_top(arena, test_one_lit(arena, test_r_role(2, o, types_at_y()))), test_r_role(2, o, types_at_y())), test_r_ids(arena, 2, -1)).fires)) && (!(sriq_nom_rule(arena, ord, 5, ((uint32_t)(6)), ((uint32_t)(2)), ((uint32_t)(1)), p1, p2, test_r_ids(arena, 2, -1)).fires)) && (!(sriq_nom_rule(arena, ord, 5, ((uint32_t)(7)), ((uint32_t)(1)), ((uint32_t)(1)), p1, p2, test_r_ids(arena, 2, -1)).fires)) && (!(sriq_nom_rule(arena, ord, 5, ((uint32_t)(7)), ((uint32_t)(2)), ((uint32_t)(1)), p1, d2, test_r_ids(arena, 2, -1)).fires)));
    }
}

uint8_t test_test_sriq_depth_limit(slop_arena* arena) {
    return (((sriq_depth_limit(2, 3, 4, 6) == 320)) && ((sriq_depth_limit(0, 0, 1, 2) == 3)) && ((sriq_depth_limit(30, 30, 3, 1) == 4611686018427387904)) && ((sriq_depth_limit(30, 30, 4, 1) == 4611686018427387904)) && ((sriq_depth_limit(30, 29, 6, 1) == (7 * 576460752303423488))) && ((sriq_depth_limit(62, 0, 0, 1) == 4611686018427387904)) && ((sriq_depth_limit(40, 40, 3, 3) == 4611686018427387904)) && ((sriq_depth_limit(30, 30, 2, 1) == 3458764513820540928)) && ((sriq_depth_limit(0, 0, 4611686018427387904, 2) == 4611686018427387904)));
}

uint8_t test_test_sriq_gate_table(slop_arena* arena) {
    {
        uint8_t ok = 1;
        if (!(test_rungs3_omit(arena, SLOP_STR("plain EL stays in every rung"), SLOP_STR(":C rdfs:subClassOf :D ."), 0, 0, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("InverseObjectProperties"), SLOP_STR(":r owl:inverseOf :s ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("a restriction on an inverse"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty [ owl:inverseOf :r ] ; owl:someValuesFrom :D ] ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("ObjectAllValuesFrom"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :D ] ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("ObjectUnionOf with a complement"), SLOP_STR(":C rdfs:subClassOf [ owl:unionOf ( :D [ owl:complementOf :D ] ) ] ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("a complement on the left"), SLOP_STR("[ owl:complementOf :C ] rdfs:subClassOf :D ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("a qualified cardinality, n = 16"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:maxQualifiedCardinality 16 ; owl:onClass :D ] ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("a qualified cardinality, n = 17"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:maxQualifiedCardinality 17 ; owl:onClass :D ] ."), 1, 1, 1))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("an unqualified exact cardinality"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:cardinality 2 ] ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("a cardinality on a transitive role"), SLOP_STR(":r a owl:TransitiveProperty .\n  :C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:maxCardinality 1 ] ."), 1, 1, 1))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("a cardinality on the inverse of a transitive role"), SLOP_STR(":r a owl:TransitiveProperty .\n  :C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty [ owl:inverseOf :r ] ; owl:maxCardinality 1 ] ."), 1, 1, 1))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("FunctionalObjectProperty"), SLOP_STR(":r a owl:FunctionalProperty ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("a functional transitive role"), SLOP_STR(":r a owl:TransitiveProperty , owl:FunctionalProperty ."), 1, 1, 1))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("InverseFunctionalObjectProperty"), SLOP_STR(":r a owl:InverseFunctionalProperty ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("irreflexive and asymmetric"), SLOP_STR(":r a owl:IrreflexiveProperty , owl:AsymmetricProperty ."), 2, 2, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("Self on a simple role"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasSelf true ] ."), 1, 0, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("Self on a transitive role"), SLOP_STR(":r a owl:TransitiveProperty .\n  :C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasSelf true ] ."), 1, 1, 1))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("symmetric and transitive: (R5) and (R4)"), SLOP_STR(":r a owl:SymmetricProperty , owl:TransitiveProperty ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("RO's part_of/has_part: regular only after the collapse"), SLOP_STR(":r a owl:TransitiveProperty . :s a owl:TransitiveProperty . :r owl:inverseOf :s ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("P and P- in one component"), SLOP_STR(":r owl:inverseOf :r . :r a owl:TransitiveProperty ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("R o R- [= R: R^c makes it cyclic, so the whole RBox goes"), SLOP_STR(":s rdfs:subPropertyOf :t .\n  :r owl:propertyChainAxiom ( :r [ owl:inverseOf :r ] ) ."), 1, 1, 2))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("a cycle through a length-1 complex RIA"), SLOP_STR(":r owl:propertyChainAxiom ( :s :t ) . :r rdfs:subPropertyOf :s ."), 2, 2, 2))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("DisjointObjectProperties"), SLOP_STR(":r owl:propertyDisjointWith :s ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("DisjointObjectProperties on a transitive role"), SLOP_STR(":r a owl:TransitiveProperty . :r owl:propertyDisjointWith :s ."), 1, 1, 1))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("DisjointUnion"), SLOP_STR(":C owl:disjointUnionOf ( :D [ owl:complementOf :D ] ) ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("the top role as a super-role is a tautology"), SLOP_STR(":r rdfs:subPropertyOf owl:topObjectProperty ."), 1, 0, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("an inverse into the top role is a tautology under sriq"), SLOP_STR("[ owl:inverseOf :r ] rdfs:subPropertyOf owl:topObjectProperty ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("the top role elsewhere"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty owl:topObjectProperty ; owl:someValuesFrom :D ] ."), 1, 1, 1))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("the bottom role"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty owl:bottomObjectProperty ; owl:someValuesFrom :D ] ."), 1, 0, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("a cardinality on the bottom role"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty owl:bottomObjectProperty ; owl:maxCardinality 1 ] ."), 1, 1, 1))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("ObjectHasValue: a class nominal"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasValue :a ] ."), 1, 0, 1))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("ObjectOneOf: a class nominal"), SLOP_STR(":C rdfs:subClassOf [ owl:oneOf ( :a ) ] ."), 1, 0, 1))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("an anonymous individual"), SLOP_STR("_:x :r :a ."), 1, 1, 1))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("SameIndividual and DifferentIndividuals"), SLOP_STR(":a owl:sameAs :b . :a owl:differentFrom :b ."), 2, 0, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("a negative object assertion"), SLOP_STR("[ a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; owl:assertionProperty :r ; owl:targetIndividual :b ] ."), 1, 0, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("a class assertion with a union"), SLOP_STR(":a a [ owl:unionOf ( :C :D ) ] ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("no range condition under sriq"), SLOP_STR(":s rdfs:range :C . :t rdfs:range :D .\n  :t owl:propertyChainAxiom ( :r :s ) ."), 1, 1, 0))) {
            ok = 0;
        }
        if (!(test_rungs3_omit(arena, SLOP_STR("used data stays out"), SLOP_STR(":d a owl:DatatypeProperty . :a :d 1 ."), 1, 1, 1))) {
            ok = 0;
        }
        return ok;
    }
}

uint8_t test_test_el_plus_plus_gate_table(slop_arena* arena) {
    return ((test_rungs_omit(arena, SLOP_STR("hasValue"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasValue :a ] ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("oneOf of one"), SLOP_STR(":C owl:equivalentClass [ a owl:Class ; owl:oneOf ( :a ) ] ."), 2, 0)) && (test_rungs_omit(arena, SLOP_STR("hasSelf, simple role"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasSelf true ] ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("reflexive role"), SLOP_STR(":r a owl:ReflexiveProperty ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("sameAs"), SLOP_STR(":a owl:sameAs :b ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("differentFrom"), SLOP_STR(":a owl:differentFrom :b ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("AllDifferent"), SLOP_STR("[] a owl:AllDifferent ; owl:members ( :a :b ) ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("negative assertion"), SLOP_STR("[] a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; owl:assertionProperty :r ; owl:targetIndividual :b ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("empty role"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty owl:bottomObjectProperty ; owl:someValuesFrom owl:Thing ] ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("inclusion into the universal role"), SLOP_STR(":r rdfs:subPropertyOf owl:topObjectProperty ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("chain into the universal role"), SLOP_STR("owl:topObjectProperty owl:propertyChainAxiom ( :r :s ) ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("oneOf of two"), SLOP_STR(":C owl:equivalentClass [ a owl:Class ; owl:oneOf ( :a :b ) ] ."), 2, 2)) && (test_rungs_omit(arena, SLOP_STR("hasSelf, transitive role"), SLOP_STR(":t a owl:TransitiveProperty . :C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :t ; owl:hasSelf true ] ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("hasSelf, role above a transitive one"), SLOP_STR(":t a owl:TransitiveProperty . :t rdfs:subPropertyOf :s . :C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :s ; owl:hasSelf true ] ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("hasSelf, role above a chain"), SLOP_STR(":s owl:propertyChainAxiom ( :r :r ) . :C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :s ; owl:hasSelf true ] ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("universal role in a restriction"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty owl:topObjectProperty ; owl:someValuesFrom :D ] ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("universal role below another"), SLOP_STR(":t rdfs:subPropertyOf :r . owl:topObjectProperty rdfs:subPropertyOf :r ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("universal role as a chain step"), SLOP_STR(":s owl:propertyChainAxiom ( :r owl:topObjectProperty ) ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("empty role as a chain step"), SLOP_STR(":s owl:propertyChainAxiom ( :r owl:bottomObjectProperty ) ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("oneOf of a reserved IRI"), SLOP_STR(":C rdfs:subClassOf [ a owl:Class ; owl:oneOf ( owl:Thing ) ] ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("hasValue on a reserved IRI"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasValue owl:Thing ] ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("AllDifferent with a reserved IRI"), SLOP_STR("[] a owl:AllDifferent ; owl:members ( :a owl:Thing ) ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("sameAs an XSD IRI"), SLOP_STR("@prefix xsd: <http://www.w3.org/2001/XMLSchema#> . :a owl:sameAs xsd:string ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("universal role into itself"), SLOP_STR("owl:topObjectProperty rdfs:subPropertyOf owl:topObjectProperty ."), 1, 0)) && (test_rungs_omit(arena, SLOP_STR("functional role"), SLOP_STR(":r a owl:FunctionalProperty ."), 1, 1)) && (test_rungs_omit(arena, SLOP_STR("hasValue, anonymous"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasValue [] ] ."), 1, 1)));
}

uint8_t test_test_top_role_tautology_is_dropped(slop_arena* arena) {
    __auto_type _mv_1548 = test_gate_ttl_in(arena, string_concat(arena, test_rung_prefix(), SLOP_STR(":r rdfs:subPropertyOf owl:topObjectProperty .")), types_Profile_profile_el_plus_plus);
    if (!_mv_1548.has_value) {
        return 0;
    } else if (_mv_1548.has_value) {
        __auto_type gr = _mv_1548.value;
        return ((((int64_t)(((int64_t)((gr.accepted).len)))) == 0) && (((int64_t)(((int64_t)((gr.omissions).len)))) == 0));
    }
    SLOP_UNREACHABLE();
}

slop_string test_ksc_form_of_ttl(slop_arena* arena, slop_string ttl) {
    __auto_type _mv_1549 = test_gate_ttl_in(arena, string_concat(arena, test_rung_prefix(), ttl), types_Profile_profile_el_plus_plus);
    if (!_mv_1549.has_value) {
        return SLOP_STR("<did not gate>");
    } else if (_mv_1549.has_value) {
        __auto_type gr = _mv_1549.value;
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

slop_option_test_KscFixture test_ksc_fixture(slop_arena* arena, slop_string path) {
    __auto_type _mv_1550 = test_gate_fixture_in(arena, path, types_Profile_profile_el_plus_plus);
    if (!_mv_1550.has_value) {
        return (slop_option_test_KscFixture){.has_value = false};
    } else if (_mv_1550.has_value) {
        __auto_type gr = _mv_1550.value;
        if (((int64_t)((gr.omissions).len)) > 0) {
            {
                __auto_type _coll = gr.omissions;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type o = _coll.data[_i];
                    printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [ksc omitted] "), owl2_render_omission(arena, o))).len, (string_concat(arena, SLOP_STR("  [ksc omitted] "), owl2_render_omission(arena, o))).data);
                }
            }
            return (slop_option_test_KscFixture){.has_value = false};
        } else {
            return (slop_option_test_KscFixture){.has_value = 1, .value = ((test_KscFixture){.axioms = kscnormal_normalize_ksc(arena, gr.accepted).axioms, .classes = kscsat_input_classes(arena, gr.signature)})};
        }
    }
    SLOP_UNREACHABLE();
}

slop_string test_kname_label(slop_arena* arena, types_KName n) {
    __auto_type _mv_1551 = n;
    switch (_mv_1551.tag) {
        case types_KName_k_class:
        {
            __auto_type i = _mv_1551.data.k_class;
            return i.value;
        }
        case types_KName_k_fresh:
        {
            __auto_type k = _mv_1551.data.k_fresh;
            return string_concat(arena, SLOP_STR("_:"), int_to_string(arena, k));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_ksc_engine_matches_reference(slop_arena* arena, slop_string label, slop_string ttl) {
    __auto_type _mv_1552 = test_ksc_fixture(arena, ttl);
    if (!_mv_1552.has_value) {
        printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [ksc differential] did not gate whole: "), label)).len, (string_concat(arena, SLOP_STR("  [ksc differential] did not gate whole: "), label)).data);
        return 0;
    } else if (_mv_1552.has_value) {
        __auto_type fx = _mv_1552.value;
        {
            __auto_type res = test_ksc_run(arena, fx.axioms, fx.classes, types_default_config());
            __auto_type nothing = ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = vocab_OWL_NOTHING}) });
            __auto_type thing = ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = vocab_OWL_THING}) });
            uint8_t ok = 1;
            {
                __auto_type tref = ksc_reference_closure(arena, fx.axioms, (slop_option_types_KName){.has_value = 1, .value = thing}, fx.classes);
                if (!((res.inconsistent == ksc_reference_answer(tref, thing, nothing)))) {
                    printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [ksc differential] inconsistency differs: "), label)).len, (string_concat(arena, SLOP_STR("  [ksc differential] inconsistency differs: "), label)).data);
                    ok = 0;
                }
            }
            {
                __auto_type _coll = res.answers;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    {
                        __auto_type ref = ksc_reference_closure(arena, fx.axioms, (slop_option_types_KName){.has_value = 1, .value = a.cls}, fx.classes);
                        __auto_type ref_unsat = ksc_reference_answer(ref, a.cls, nothing);
                        if (!((a.unsat == ref_unsat))) {
                            printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [ksc differential] unsat differs: "), label)).len, (string_concat(arena, SLOP_STR("  [ksc differential] unsat differs: "), label)).data);
                            printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("    for "), test_kname_label(arena, a.cls))).len, (string_concat(arena, SLOP_STR("    for "), test_kname_label(arena, a.cls))).data);
                            ok = 0;
                        }
                        {
                            __auto_type _coll = fx.classes;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type b = _coll.data[_i];
                                {
                                    __auto_type eng = kscsat_answer_holds(a, b);
                                    __auto_type want = ((ref_unsat) ? 1 : ksc_reference_answer(ref, a.cls, b));
                                    if (!((eng == want))) {
                                        printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [ksc differential] holds differs: "), label)).len, (string_concat(arena, SLOP_STR("  [ksc differential] holds differs: "), label)).data);
                                        printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("    "), string_concat(arena, test_kname_label(arena, a.cls), string_concat(arena, SLOP_STR(" ⊑ "), test_kname_label(arena, b))))).len, (string_concat(arena, SLOP_STR("    "), string_concat(arena, test_kname_label(arena, a.cls), string_concat(arena, SLOP_STR(" ⊑ "), test_kname_label(arena, b))))).data);
                                        ok = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return ok;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t test_ksc_holds(slop_arena* arena, slop_string ttl, slop_string a, slop_string b) {
    __auto_type _mv_1553 = test_ksc_fixture(arena, ttl);
    if (!_mv_1553.has_value) {
        return -1;
    } else if (_mv_1553.has_value) {
        __auto_type fx = _mv_1553.value;
        {
            __auto_type res = test_ksc_run(arena, fx.axioms, fx.classes, types_default_config());
            __auto_type an = ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = a}) });
            __auto_type bn = ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = b}) });
            int64_t out = 0;
            if (res.inconsistent) {
                out = 1;
            }
            {
                __auto_type _coll = res.answers;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type x = _coll.data[_i];
                    if (types_kname_eq(x.cls, an)) {
                        if (kscsat_answer_holds(x, bn)) {
                            out = 1;
                        }
                    }
                }
            }
            return out;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t test_ksc_inconsistent(slop_arena* arena, slop_string ttl) {
    __auto_type _mv_1554 = test_ksc_fixture(arena, ttl);
    if (!_mv_1554.has_value) {
        return -1;
    } else if (_mv_1554.has_value) {
        __auto_type fx = _mv_1554.value;
        if (test_ksc_run(arena, fx.axioms, fx.classes, types_default_config()).inconsistent) {
            return 1;
        } else {
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t test_ksc_fixture_count(void) {
    return 38;
}

slop_string test_ksc_fixture_at(int64_t i) {
    __auto_type _mv_1555 = i;
    if (_mv_1555 == 0) {
        return SLOP_STR("corpus/fixtures/el++/ksc-00.ttl");
    } else if (_mv_1555 == 1) {
        return SLOP_STR("corpus/fixtures/el++/ksc-01.ttl");
    } else if (_mv_1555 == 2) {
        return SLOP_STR("corpus/fixtures/el++/ksc-02.ttl");
    } else if (_mv_1555 == 3) {
        return SLOP_STR("corpus/fixtures/el++/ksc-03.ttl");
    } else if (_mv_1555 == 4) {
        return SLOP_STR("corpus/fixtures/el++/ksc-04.ttl");
    } else if (_mv_1555 == 5) {
        return SLOP_STR("corpus/fixtures/el++/ksc-05.ttl");
    } else if (_mv_1555 == 6) {
        return SLOP_STR("corpus/fixtures/el++/ksc-06.ttl");
    } else if (_mv_1555 == 7) {
        return SLOP_STR("corpus/fixtures/el++/ksc-07.ttl");
    } else if (_mv_1555 == 8) {
        return SLOP_STR("corpus/fixtures/el++/ksc-08.ttl");
    } else if (_mv_1555 == 9) {
        return SLOP_STR("corpus/fixtures/el++/ksc-09.ttl");
    } else if (_mv_1555 == 10) {
        return SLOP_STR("corpus/fixtures/el++/ksc-10.ttl");
    } else if (_mv_1555 == 11) {
        return SLOP_STR("corpus/fixtures/el++/ksc-11.ttl");
    } else if (_mv_1555 == 12) {
        return SLOP_STR("corpus/fixtures/el++/ksc-12.ttl");
    } else if (_mv_1555 == 13) {
        return SLOP_STR("corpus/fixtures/el++/ksc-13.ttl");
    } else if (_mv_1555 == 14) {
        return SLOP_STR("corpus/fixtures/el++/ksc-14.ttl");
    } else if (_mv_1555 == 15) {
        return SLOP_STR("corpus/fixtures/el++/ksc-15.ttl");
    } else if (_mv_1555 == 16) {
        return SLOP_STR("corpus/fixtures/el++/ksc-16.ttl");
    } else if (_mv_1555 == 17) {
        return SLOP_STR("corpus/fixtures/el++/ksc-17.ttl");
    } else if (_mv_1555 == 18) {
        return SLOP_STR("corpus/fixtures/el++/ksc-18.ttl");
    } else if (_mv_1555 == 19) {
        return SLOP_STR("corpus/fixtures/el++/ksc-19.ttl");
    } else if (_mv_1555 == 20) {
        return SLOP_STR("corpus/fixtures/el++/ksc-20.ttl");
    } else if (_mv_1555 == 21) {
        return SLOP_STR("corpus/fixtures/el++/ksc-21.ttl");
    } else if (_mv_1555 == 22) {
        return SLOP_STR("corpus/fixtures/el++/ksc-22.ttl");
    } else if (_mv_1555 == 23) {
        return SLOP_STR("corpus/fixtures/el++/ksc-23.ttl");
    } else if (_mv_1555 == 24) {
        return SLOP_STR("corpus/fixtures/el++/ksc-24.ttl");
    } else if (_mv_1555 == 25) {
        return SLOP_STR("corpus/fixtures/el++/ksc-25.ttl");
    } else if (_mv_1555 == 26) {
        return SLOP_STR("corpus/fixtures/el++/ksc-26.ttl");
    } else if (_mv_1555 == 27) {
        return SLOP_STR("corpus/fixtures/el++/ksc-27.ttl");
    } else if (_mv_1555 == 28) {
        return SLOP_STR("corpus/fixtures/el++/ksc-28.ttl");
    } else if (_mv_1555 == 29) {
        return SLOP_STR("corpus/fixtures/el++/ksc-29.ttl");
    } else if (_mv_1555 == 30) {
        return SLOP_STR("corpus/fixtures/el++/ksc-30.ttl");
    } else if (_mv_1555 == 31) {
        return SLOP_STR("corpus/fixtures/el++/ksc-31.ttl");
    } else if (_mv_1555 == 32) {
        return SLOP_STR("corpus/fixtures/el++/ksc-32.ttl");
    } else if (_mv_1555 == 33) {
        return SLOP_STR("corpus/fixtures/el++/ksc-33.ttl");
    } else if (_mv_1555 == 34) {
        return SLOP_STR("corpus/fixtures/el++/ksc-34.ttl");
    } else if (_mv_1555 == 35) {
        return SLOP_STR("corpus/fixtures/el++/ksc-35.ttl");
    } else if (_mv_1555 == 36) {
        return SLOP_STR("corpus/fixtures/el++/ksc-36.ttl");
    } else if (_mv_1555 == 37) {
        return SLOP_STR("corpus/fixtures/el++/ksc-37.ttl");
    } else {
        return SLOP_STR("");
    }
}

types_ReasonerConfig test_cap_config(int64_t cap) {
    {
        __auto_type cfg = types_default_config();
        cfg.max_iterations = ((uint16_t)(SLOP_RANGE(uint16_t, cap, 1, 1, 0, 10000, "(Int 0 .. 10000) at test.slop:5513:59")));
        return cfg;
    }
}

int64_t test_incomplete_answers(types_KscResult r) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = r.answers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (!(a.complete)) {
                    n = (n + 1);
                }
            }
        }
        return n;
    }
}

uint8_t test_says_resource_limit(types_KscResult r) {
    __auto_type _mv_1556 = r.termination;
    switch (_mv_1556.tag) {
        case types_Termination_resource_limit:
        {
            __auto_type _ = _mv_1556.data.resource_limit;
            return 1;
        }
        case types_Termination_fixpoint:
        {
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t test_capped_incomplete(slop_arena* arena, test_KscFixture fx) {
    {
        __auto_type full = test_ksc_run(arena, fx.axioms, fx.classes, types_default_config());
        int64_t seen = 0;
        int64_t cap = 0;
        while ((seen >= 0) && (cap <= full.rounds)) {
            {
                __auto_type r = test_ksc_run(arena, fx.axioms, fx.classes, test_cap_config(cap));
                __auto_type k = test_incomplete_answers(r);
                if ((k > 0) && !(test_says_resource_limit(r))) {
                    seen = -1;
                } else {
                    seen = (seen + k);
                }
                cap = (cap + 1);
            }
        }
        return seen;
    }
}

uint8_t test_test_ksc_cut_runs_say_resource_limit(slop_arena* arena) {
    {
        uint8_t ok = 1;
        int64_t seen = 0;
        int64_t i = 0;
        while (i < test_ksc_fixture_count()) {
            __auto_type _mv_1557 = test_ksc_fixture(arena, test_ksc_fixture_at(i));
            if (!_mv_1557.has_value) {
                ok = 0;
            } else if (_mv_1557.has_value) {
                __auto_type fx = _mv_1557.value;
                {
                    __auto_type k = test_capped_incomplete(arena, fx);
                    if (k < 0) {
                        ok = 0;
                    } else {
                        seen = (seen + k);
                    }
                }
            }
            i = (i + 1);
        }
        return (ok && (seen > 0));
    }
}

types_KFact test_ex_class_fact(slop_arena* arena, slop_string ind, slop_string cls) {
    return ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = types_ind_elem(((rdf_IRI){.value = string_concat(arena, SLOP_STR("http://example.org/t#"), ind)})), .f1 = types_name_term(((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = string_concat(arena, SLOP_STR("http://example.org/t#"), cls)}) })) } });
}

uint8_t test_test_ksc_g_stops_at_bottom(slop_arena* arena) {
    __auto_type _mv_1558 = test_ksc_fixture(arena, SLOP_STR("corpus/fixtures/el++/ksc-37.ttl"));
    if (!_mv_1558.has_value) {
        return 0;
    } else if (_mv_1558.has_value) {
        __auto_type fx = _mv_1558.value;
        {
            __auto_type idx = kscpremise_build_ksc_index(arena, fx.axioms);
            __auto_type ids = kscids_build_ksc_ids(arena, fx.axioms, fx.classes, idx.individuals);
            __auto_type g = kscsat_run_ksc(arena, idx, ids, ((slop_option_kscsat_Base){.has_value = false}), test_ksc_seeds(arena, idx, fx.classes, 0), 1, 10000, 0, 1, ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
            return ((g.unsat) && (kscsat_store_holds(g.store, ((slop_option_kscsat_Base){.has_value = false}), test_ex_class_fact(arena, SLOP_STR("a"), SLOP_STR("F")))) && (!(kscsat_store_holds(g.store, ((slop_option_kscsat_Base){.has_value = false}), test_ex_class_fact(arena, SLOP_STR("a"), SLOP_STR("G"))))));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_ksc_engine_matches_reference(slop_arena* arena) {
    {
        uint8_t ok = 1;
        int64_t i = 0;
        while (i < test_ksc_fixture_count()) {
            if (!(test_ksc_engine_matches_reference(arena, string_concat(arena, SLOP_STR("fixture "), int_to_string(arena, i)), test_ksc_fixture_at(i)))) {
                ok = 0;
            }
            i = (i + 1);
        }
        return ok;
    }
}

uint8_t test_test_ksc_entailments(slop_arena* arena) {
    {
        uint8_t ok = 1;
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(0), SLOP_STR("http://example.org/t#Mother"), SLOP_STR("http://example.org/t#Parent")) == 1))) {
            printf("%s\n", "  [ksc] litmus: Mother ⊑ Parent");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(1), SLOP_STR("http://example.org/t#A"), SLOP_STR("http://example.org/t#B")) == 1))) {
            printf("%s\n", "  [ksc] KKS12 Example 5: A ⊑ B");
            ok = 0;
        }
        if (!((test_ksc_inconsistent(arena, test_ksc_fixture_at(2)) == 1))) {
            printf("%s\n", "  [ksc] ⊤ ⊑ ⊥ with no individuals is inconsistent");
            ok = 0;
        }
        if (!((test_ksc_inconsistent(arena, test_ksc_fixture_at(3)) == 0))) {
            printf("%s\n", "  [ksc] K3 example is consistent");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(3), SLOP_STR("http://example.org/t#Q"), SLOP_STR("http://www.w3.org/2002/07/owl#Nothing")) == 1))) {
            printf("%s\n", "  [ksc] K3 example: Q is unsatisfiable, ⊥ at a");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(3), SLOP_STR("http://example.org/t#A"), SLOP_STR("http://www.w3.org/2002/07/owl#Nothing")) == 0))) {
            printf("%s\n", "  [ksc] K3 example: A is satisfiable");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(4), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] Self with a chain: C ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(5), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#D")) == 1))) {
            printf("%s\n", "  [ksc] reflexive: C ⊑ D");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(5), SLOP_STR("http://example.org/t#X"), SLOP_STR("http://example.org/t#D")) == 1))) {
            printf("%s\n", "  [ksc] transitive: X ⊑ D");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(6), SLOP_STR("http://example.org/t#Q"), SLOP_STR("http://example.org/t#C")) == 1))) {
            printf("%s\n", "  [ksc] sameAs: Q ⊑ C");
            ok = 0;
        }
        if (!((test_ksc_inconsistent(arena, test_ksc_fixture_at(7)) == 1))) {
            printf("%s\n", "  [ksc] sameAs with differentFrom is inconsistent");
            ok = 0;
        }
        if (!((test_ksc_inconsistent(arena, test_ksc_fixture_at(8)) == 1))) {
            printf("%s\n", "  [ksc] a negative assertion against its assertion is inconsistent");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(9), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] hasValue: C ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(10), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] range: C ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(11), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://www.w3.org/2002/07/owl#Nothing")) == 1))) {
            printf("%s\n", "  [ksc] empty role: C unsatisfiable");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(11), SLOP_STR("http://example.org/t#D"), SLOP_STR("http://www.w3.org/2002/07/owl#Nothing")) == 0))) {
            printf("%s\n", "  [ksc] empty role: D satisfiable");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(12), SLOP_STR("http://example.org/t#Q"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] role assertion through a nominal: Q ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(13), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#D")) == 1))) {
            printf("%s\n", "  [ksc] Self on the left: C ⊑ D");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(13), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] Self under a role hierarchy: C ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(21), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] chain legs under sub-roles, first leg first: C ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(21), SLOP_STR("http://example.org/t#C2"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] chain legs under sub-roles, second leg first: C2 ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(21), SLOP_STR("http://example.org/t#X"), SLOP_STR("http://example.org/t#E")) == 0))) {
            printf("%s\n", "  [ksc] chain legs under sub-roles: X ⋢ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(22), SLOP_STR("http://example.org/t#Q"), SLOP_STR("http://example.org/t#D")) == 1))) {
            printf("%s\n", "  [ksc] Self on a sub-role reaches a super-role's range: Q ⊑ D");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(22), SLOP_STR("http://example.org/t#Q"), SLOP_STR("http://example.org/t#F")) == 1))) {
            printf("%s\n", "  [ksc] Self on a sub-role through (14): Q ⊑ F");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(22), SLOP_STR("http://example.org/t#Q"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] Self on a sub-role feeds a chain: Q ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(23), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] (29) re-points a sub-role triple into a chain: C ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(24), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] a super-role's range at a sub-role witness: C ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(24), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#E2")) == 1))) {
            printf("%s\n", "  [ksc] a sub-role triple read as its super-role: C ⊑ E2");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(24), SLOP_STR("http://example.org/t#C2"), SLOP_STR("http://example.org/t#E2")) == 1))) {
            printf("%s\n", "  [ksc] range on the role itself: C2 ⊑ E2");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(24), SLOP_STR("http://example.org/t#C2"), SLOP_STR("http://example.org/t#E")) == 0))) {
            printf("%s\n", "  [ksc] no read downwards: C2 ⋢ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(25), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] role cycle: C ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(25), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#F")) == 1))) {
            printf("%s\n", "  [ksc] role cycle: C ⊑ F");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(25), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#G")) == 1))) {
            printf("%s\n", "  [ksc] role cycle: C ⊑ G");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(25), SLOP_STR("http://example.org/t#D2"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] role cycle: D2 ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(25), SLOP_STR("http://example.org/t#D2"), SLOP_STR("http://example.org/t#F")) == 1))) {
            printf("%s\n", "  [ksc] role cycle: D2 ⊑ F");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(25), SLOP_STR("http://example.org/t#D2"), SLOP_STR("http://example.org/t#G")) == 1))) {
            printf("%s\n", "  [ksc] role cycle: D2 ⊑ G");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(26), SLOP_STR("http://example.org/t#S"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] K6 through sub-roles: S ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(26), SLOP_STR("http://example.org/t#U"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] K6 through sub-roles: U ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(26), SLOP_STR("http://example.org/t#U"), SLOP_STR("http://example.org/t#G")) == 1))) {
            printf("%s\n", "  [ksc] K6 through sub-roles: U ⊑ G");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(26), SLOP_STR("http://example.org/t#S"), SLOP_STR("http://example.org/t#G")) == 0))) {
            printf("%s\n", "  [ksc] K6 through sub-roles: S ⋢ G");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(27), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] transitive over sub-role legs: C ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(27), SLOP_STR("http://example.org/t#X"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] sub-role read up: X ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(27), SLOP_STR("http://example.org/t#X"), SLOP_STR("http://example.org/t#F")) == 1))) {
            printf("%s\n", "  [ksc] sub-role on its own: X ⊑ F");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(27), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#F")) == 0))) {
            printf("%s\n", "  [ksc] no read downwards: C ⋢ F");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(28), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] Self after a sub-role leg, rule (16): C ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(28), SLOP_STR("http://example.org/t#C3"), SLOP_STR("http://example.org/t#E3")) == 1))) {
            printf("%s\n", "  [ksc] Self after a sub-role leg, rule (17): C3 ⊑ E3");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(28), SLOP_STR("http://example.org/t#A2"), SLOP_STR("http://example.org/t#E")) == 0))) {
            printf("%s\n", "  [ksc] Self alone: A2 ⋢ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(29), SLOP_STR("http://example.org/t#Q"), SLOP_STR("http://example.org/t#B")) == 1))) {
            printf("%s\n", "  [ksc] a nominal's late class reaches its holder: Q ⊑ B");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(29), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] a nominal's late class through a witness: C ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_inconsistent(arena, test_ksc_fixture_at(30)) == 1))) {
            printf("%s\n", "  [ksc] a nominal's late class reaches a one-way member: inconsistent");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(14), SLOP_STR("http://example.org/t#D"), SLOP_STR("http://example.org/t#C")) == 1))) {
            printf("%s\n", "  [ksc] nominal: D ⊑ C");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(14), SLOP_STR("http://example.org/t#Q"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] chain through a nominal witness: Q ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(14), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#E")) == 0))) {
            printf("%s\n", "  [ksc] nominal: C ⋢ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(15), SLOP_STR("http://example.org/t#S"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] K6 shared witness: S ⊑ E (S safe)");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(15), SLOP_STR("http://example.org/t#U"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] K6 shared witness: U ⊑ E (U unsafe)");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(16), SLOP_STR("http://example.org/t#U"), SLOP_STR("http://www.w3.org/2002/07/owl#Nothing")) == 1))) {
            printf("%s\n", "  [ksc] K6.3: U unsatisfiable through a safe witness");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(16), SLOP_STR("http://example.org/t#S"), SLOP_STR("http://www.w3.org/2002/07/owl#Nothing")) == 1))) {
            printf("%s\n", "  [ksc] K6.2: S unsatisfiable through its cone");
            ok = 0;
        }
        if (!((test_ksc_inconsistent(arena, test_ksc_fixture_at(16)) == 0))) {
            printf("%s\n", "  [ksc] K6 fixture 16 is consistent");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(17), SLOP_STR("http://example.org/t#S"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] K6: a nominal two hops down: S ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(17), SLOP_STR("http://example.org/t#T"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] K6: a nominal two hops down: T ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(18), SLOP_STR("http://www.w3.org/2002/07/owl#Thing"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] K6: ⊤ ⊑ ∃r.{a} makes owl:Thing ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(18), SLOP_STR("http://example.org/t#C"), SLOP_STR("http://example.org/t#E")) == 1))) {
            printf("%s\n", "  [ksc] K6: ⊤ ⊑ ∃r.{a} makes C ⊑ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(19), SLOP_STR("http://example.org/t#Q2"), SLOP_STR("http://example.org/t#Q1")) == 0))) {
            printf("%s\n", "  [ksc] K6 does not merge: Q2 ⋢ Q1");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(19), SLOP_STR("http://example.org/t#Q1"), SLOP_STR("http://example.org/t#Q2")) == 0))) {
            printf("%s\n", "  [ksc] K6 does not merge: Q1 ⋢ Q2");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(20), SLOP_STR("http://example.org/t#Q2"), SLOP_STR("http://example.org/t#E")) == 0))) {
            printf("%s\n", "  [ksc] K6 does not merge through witnesses: Q2 ⋢ E");
            ok = 0;
        }
        if (!((test_ksc_holds(arena, test_ksc_fixture_at(20), SLOP_STR("http://example.org/t#Q1"), SLOP_STR("http://example.org/t#B")) == 0))) {
            printf("%s\n", "  [ksc] fixture 20: Q1 ⋢ B");
            ok = 0;
        }
        return ok;
    }
}

slop_option_types_Outcome test_classify_fixture_in(slop_arena* arena, slop_string path, types_Profile profile) {
    __auto_type _mv_1559 = ttl_parse_ttl_file(arena, path);
    if (!_mv_1559.is_ok) {
        __auto_type _ = _mv_1559.data.err;
        return (slop_option_types_Outcome){.has_value = false};
    } else if (_mv_1559.is_ok) {
        __auto_type g = _mv_1559.data.ok;
        __auto_type _mv_1560 = howl_decode_owned(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        if (!_mv_1560.is_ok) {
            __auto_type _ = _mv_1560.data.err;
            return (slop_option_types_Outcome){.has_value = false};
        } else if (_mv_1560.is_ok) {
            __auto_type d = _mv_1560.data.ok;
            __auto_type _mv_1561 = howl_prepare_in_profile(arena, d, types_default_config(), profile);
            if (!_mv_1561.is_ok) {
                __auto_type _ = _mv_1561.data.err;
                return (slop_option_types_Outcome){.has_value = false};
            } else if (_mv_1561.is_ok) {
                __auto_type p = _mv_1561.data.ok;
                __auto_type _mv_1562 = howl_reason(arena, p, types_default_config());
                if (!_mv_1562.is_ok) {
                    __auto_type _ = _mv_1562.data.err;
                    return (slop_option_types_Outcome){.has_value = false};
                } else if (_mv_1562.is_ok) {
                    __auto_type o = _mv_1562.data.ok;
                    return (slop_option_types_Outcome){.has_value = 1, .value = o};
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_list_string test_rung_neutral_lines(slop_arena* arena, types_Outcome o) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = report_report_lines(arena, o);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(strlib_starts_with(l, SLOP_STR("profile ")))) {
                    if (!(strlib_starts_with(l, SLOP_STR("rounds ")))) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

uint8_t test_rungs_agree_on(slop_arena* arena, slop_string path) {
    __auto_type _mv_1563 = test_classify_fixture_in(arena, path, types_Profile_profile_el);
    if (!_mv_1563.has_value) {
        printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [el vs el++] el did not run: "), path)).len, (string_concat(arena, SLOP_STR("  [el vs el++] el did not run: "), path)).data);
        return 0;
    } else if (_mv_1563.has_value) {
        __auto_type a = _mv_1563.value;
        __auto_type _mv_1564 = test_classify_fixture_in(arena, path, types_Profile_profile_el_plus_plus);
        if (!_mv_1564.has_value) {
            printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [el vs el++] el++ did not run: "), path)).len, (string_concat(arena, SLOP_STR("  [el vs el++] el++ did not run: "), path)).data);
            return 0;
        } else if (_mv_1564.has_value) {
            __auto_type b = _mv_1564.value;
            if (test_same_lines(test_rung_neutral_lines(arena, a), test_rung_neutral_lines(arena, b))) {
                return 1;
            } else {
                printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [el vs el++] reports differ: "), path)).len, (string_concat(arena, SLOP_STR("  [el vs el++] reports differ: "), path)).data);
                {
                    __auto_type _coll = test_rung_neutral_lines(arena, a);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type l = _coll.data[_i];
                        printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("    el   "), l)).len, (string_concat(arena, SLOP_STR("    el   "), l)).data);
                    }
                }
                {
                    __auto_type _coll = test_rung_neutral_lines(arena, b);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type l = _coll.data[_i];
                        printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("    el++ "), l)).len, (string_concat(arena, SLOP_STR("    el++ "), l)).data);
                    }
                }
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_el_and_el_plus_plus_agree(slop_arena* arena) {
    {
        uint8_t ok = 1;
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/abox-assertions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-binary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/domain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-classes.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-properties.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-lhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-rhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/intersection.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/litmus.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-domain-range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-superclass.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subclass-atomic.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subproperty.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/top-bottom.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/transitive.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (!(test_rungs_agree_on(arena, p))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

types_KscResult test_ksc_run(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, types_ReasonerConfig config) {
    __auto_type _mv_1565 = kscsat_ksc_classify(arena, axioms, classes, config);
    if (_mv_1565.is_ok) {
        __auto_type r = _mv_1565.data.ok;
        return r;
    } else if (!_mv_1565.is_ok) {
        __auto_type _ = _mv_1565.data.err;
        printf("%s\n", "  [ksc] ksc-classify returned a Fault under a config that cannot cancel");
        return ((types_KscResult){.inconsistent = 0, .termination = ((types_Termination){ .tag = types_Termination_resource_limit, .data.resource_limit = 0 }), .rounds = 0, .g_rounds = 0, .g_facts = 0, .w_rounds = 0, .w_facts = 0, .unsafe_count = 0, .answers = ((slop_list_types_ClassAnswer){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
    }
    SLOP_UNREACHABLE();
}

int64_t test_cancel_flag_set(void) {
    {
        int64_t p = 0;
        static uint32_t howl_test_cancel_flag = 1; p = (int64_t)(uintptr_t)&howl_test_cancel_flag;;
        return ((int64_t)(p));
    }
}

uint8_t test_test_ksc_cancelled(slop_arena* arena) {
    if (test_cancelled_under(arena, types_default_config())) {
        return test_cancelled_under(arena, test_ksc_config(1, 0));
    } else {
        return 0;
    }
}

uint8_t test_cancelled_under(slop_arena* arena, types_ReasonerConfig base_cfg) {
    {
        __auto_type cfg = base_cfg;
        cfg.cancel_ptr = test_cancel_flag_set();
        __auto_type _mv_1566 = test_ksc_fixture(arena, test_ksc_fixture_at(0));
        if (!_mv_1566.has_value) {
            return 0;
        } else if (_mv_1566.has_value) {
            __auto_type fx = _mv_1566.value;
            __auto_type _mv_1567 = kscsat_ksc_classify(arena, fx.axioms, fx.classes, cfg);
            if (_mv_1567.is_ok) {
                __auto_type _ = _mv_1567.data.ok;
                return 0;
            } else if (!_mv_1567.is_ok) {
                __auto_type f = _mv_1567.data.err;
                __auto_type _mv_1568 = f;
                switch (_mv_1568.tag) {
                    case types_Fault_cancelled:
                    {
                        return 1;
                    }
                    case types_Fault_input_error:
                    {
                        __auto_type _ = _mv_1568.data.input_error;
                        return 0;
                    }
                    case types_Fault_refused:
                    {
                        __auto_type _ = _mv_1568.data.refused;
                        return 0;
                    }
                    case types_Fault_unavailable:
                    {
                        __auto_type _ = _mv_1568.data.unavailable;
                        return 0;
                    }
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_ids_round_trip(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes) {
    {
        __auto_type ids = kscids_build_ksc_ids(arena, axioms, classes, kscpremise_build_ksc_index(arena, axioms).individuals);
        __auto_type thing = ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = vocab_OWL_THING}) });
        __auto_type facts = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_KFact, slop_hash_types_KFact, slop_eq_types_KFact, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type codes = ({ static const slop_map_desc _d = SLOP_SET_DESC(kscids_CFact, slop_hash_kscids_CFact, slop_eq_kscids_CFact, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type qs = ((slop_list_types_KName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t ok = 1;
        ({ __auto_type _lst_p = &(qs); __auto_type _item = (thing); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                ({ __auto_type _lst_p = &(qs); __auto_type _item = (q); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = qs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                {
                    __auto_type _coll = ksc_reference_closure(arena, axioms, (slop_option_types_KName){.has_value = 1, .value = q}, classes);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type f = _coll.data[_i];
                        {
                            __auto_type c = kscids_encode_fact(ids, f);
                            if (!(types_kfact_eq(kscids_decode_fact(ids, c), f))) {
                                ok = 0;
                            }
                            ({ slop_map_put(NULL, facts, &(f), NULL, 0); });
                            ({ slop_map_put(NULL, codes, &(c), NULL, 0); });
                        }
                    }
                }
            }
        }
        if (ok) {
            return (((int64_t)(facts)->len) == ((int64_t)(codes)->len));
        } else {
            return 0;
        }
    }
}

uint8_t test_test_ksc_ids_round_trip(slop_arena* arena) {
    {
        uint8_t ok = 1;
        int64_t i = 0;
        while (i < test_ksc_fixture_count()) {
            __auto_type _mv_1571 = test_ksc_fixture(arena, test_ksc_fixture_at(i));
            if (_mv_1571.has_value) {
                __auto_type fx = _mv_1571.value;
                {
                    __auto_type nm = kscnames_build_ksc_names(arena, fx.axioms, fx.classes);
                    if (!(test_ids_round_trip(arena, fx.axioms, fx.classes))) {
                        printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [ksc ids] input names, fixture "), int_to_string(arena, i))).len, (string_concat(arena, SLOP_STR("  [ksc ids] input names, fixture "), int_to_string(arena, i))).data);
                        ok = 0;
                    }
                    if (!(test_ids_round_trip(arena, kscnames_rename_ksc_axioms(arena, nm, fx.axioms), kscnames_rename_classes(arena, nm, fx.classes)))) {
                        printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [ksc ids] renamed, fixture "), int_to_string(arena, i))).len, (string_concat(arena, SLOP_STR("  [ksc ids] renamed, fixture "), int_to_string(arena, i))).data);
                        ok = 0;
                    }
                }
            } else if (!_mv_1571.has_value) {
                ok = 0;
            }
            i = (i + 1);
        }
        return ok;
    }
}

uint8_t test_holds_under(kscpremise_KscIndex idx, slop_list_types_KFact fs, types_KElem x, types_RoleId v, types_KElem y) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = fs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                __auto_type _mv_1572 = f;
                switch (_mv_1572.tag) {
                    case types_KFact_f_triple:
                    {
                        __auto_type a = _mv_1572.data.f_triple.f0;
                        __auto_type e = _mv_1572.data.f_triple.f1;
                        __auto_type b = _mv_1572.data.f_triple.f2;
                        if ((types_kelem_eq(a, x)) ? ((types_kelem_eq(b, y)) ? kscpremise_role_under(idx, e, v) : 0) : 0) {
                            found = 1;
                        }
                        break;
                    }
                    case types_KFact_f_inst:
                    {
                        break;
                    }
                    case types_KFact_f_self:
                    {
                        break;
                    }
                }
            }
        }
        return found;
    }
}

uint8_t test_g_matches_reference(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes) {
    {
        __auto_type idx = kscpremise_build_ksc_index(arena, axioms);
        __auto_type ids = kscids_build_ksc_ids(arena, axioms, classes, idx.individuals);
        __auto_type ref = ksc_reference_closure(arena, axioms, ((slop_option_types_KName){.has_value = false}), classes);
        __auto_type refset = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_KFact, slop_hash_types_KFact, slop_eq_types_KFact, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type seeds = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type eng = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t bottom = 0;
        uint8_t ok = 1;
        {
            __auto_type _coll = ref;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                ({ slop_map_put(NULL, refset, &(f), NULL, 0); });
                if (kscsat_is_bottom_fact(f)) {
                    bottom = 1;
                }
            }
        }
        if (bottom) {
            return 1;
        } else {
            {
                __auto_type _coll = idx.individuals;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    ({ __auto_type _lst_p = &(seeds); __auto_type _item = (ksc_ksc_1(a).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            {
                __auto_type g = kscsat_run_ksc(arena, idx, ids, ((slop_option_kscsat_Base){.has_value = false}), seeds, 0, 10000, 0, 1, ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
                __auto_type engset = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_KFact, slop_hash_types_KFact, slop_eq_types_KFact, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
                {
                    __auto_type _coll = kscsat_store_facts(arena, g.store);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        {
                            __auto_type f = kscids_decode_fact(ids, c);
                            ({ __auto_type _lst_p = &(eng); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ slop_map_put(NULL, engset, &(f), NULL, 0); });
                            if (!(slop_map_has(refset, &(f)))) {
                                ok = 0;
                            }
                        }
                    }
                }
                {
                    __auto_type _coll = ref;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type f = _coll.data[_i];
                        __auto_type _mv_1576 = f;
                        switch (_mv_1576.tag) {
                            case types_KFact_f_triple:
                            {
                                __auto_type x = _mv_1576.data.f_triple.f0;
                                __auto_type v = _mv_1576.data.f_triple.f1;
                                __auto_type y = _mv_1576.data.f_triple.f2;
                                if (!(test_holds_under(idx, eng, x, v, y))) {
                                    ok = 0;
                                }
                                break;
                            }
                            case types_KFact_f_inst:
                            {
                                if (!(slop_map_has(engset, &(f)))) {
                                    ok = 0;
                                }
                                break;
                            }
                            case types_KFact_f_self:
                            {
                                if (!(slop_map_has(engset, &(f)))) {
                                    ok = 0;
                                }
                                break;
                            }
                        }
                    }
                }
                return ok;
            }
        }
    }
}

uint8_t test_test_ksc_g_matches_reference(slop_arena* arena) {
    {
        uint8_t ok = 1;
        int64_t i = 0;
        while (i < test_ksc_fixture_count()) {
            __auto_type _mv_1579 = test_ksc_fixture(arena, test_ksc_fixture_at(i));
            if (_mv_1579.has_value) {
                __auto_type fx = _mv_1579.value;
                if (!(test_g_matches_reference(arena, fx.axioms, fx.classes))) {
                    printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [ksc G] differs from the reference, fixture "), int_to_string(arena, i))).len, (string_concat(arena, SLOP_STR("  [ksc G] differs from the reference, fixture "), int_to_string(arena, i))).data);
                    ok = 0;
                }
            } else if (!_mv_1579.has_value) {
                ok = 0;
            }
            i = (i + 1);
        }
        return ok;
    }
}

uint8_t test_commit_agrees(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, uint8_t stop, uint8_t with_classes) {
    {
        __auto_type idx = kscpremise_build_ksc_index(arena, axioms);
        __auto_type ids = kscids_build_ksc_ids(arena, axioms, classes, idx.individuals);
        __auto_type cas = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seeds = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t ok = 1;
        {
            __auto_type _coll = idx.individuals;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(seeds); __auto_type _item = (ksc_ksc_1(a).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        if (with_classes) {
            {
                __auto_type _coll = classes;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type q = _coll.data[_i];
                    ({ __auto_type _lst_p = &(seeds); __auto_type _item = (ksc_ksc_q(q).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        ({ __auto_type _lst_p = &(cas); __auto_type _item = (({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(4096); _new_arena; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(cas); __auto_type _item = (({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(4096); _new_arena; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(cas); __auto_type _item = (({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(4096); _new_arena; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(cas); __auto_type _item = (({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(4096); _new_arena; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type one = kscsat_run_ksc(arena, idx, ids, ((slop_option_kscsat_Base){.has_value = false}), seeds, stop, 10000, 0, 1, ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
            __auto_type par = kscsat_run_ksc(arena, idx, ids, ((slop_option_kscsat_Base){.has_value = false}), seeds, stop, 10000, 0, 4, cas);
            if (!((one.rounds == par.rounds))) {
                ok = 0;
            }
            if (!((one.facts == par.facts))) {
                ok = 0;
            }
            if (!((one.unsat == par.unsat))) {
                ok = 0;
            }
            if (!((one.capped == par.capped))) {
                ok = 0;
            }
            {
                __auto_type _coll = kscsat_store_facts(arena, one.store);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    if (!(kscsat_store_holds(par.store, ((slop_option_kscsat_Base){.has_value = false}), kscids_decode_fact(ids, c)))) {
                        ok = 0;
                    }
                }
            }
            {
                __auto_type _coll = kscsat_store_facts(arena, par.store);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    if (!(kscsat_store_holds(one.store, ((slop_option_kscsat_Base){.has_value = false}), kscids_decode_fact(ids, c)))) {
                        ok = 0;
                    }
                }
            }
            {
                __auto_type _coll = cas;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    ({ slop_arena_free(a); free(a); });
                }
            }
            return ok;
        }
    }
}

uint8_t test_commit_shapes_agree(slop_arena* arena, test_KscFixture fx, int64_t i) {
    {
        uint8_t ok = 1;
        if (!(test_commit_agrees(arena, fx.axioms, fx.classes, 1, 0))) {
            printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [ksc commit, G] W = 4 differs from W = 1, fixture "), int_to_string(arena, i))).len, (string_concat(arena, SLOP_STR("  [ksc commit, G] W = 4 differs from W = 1, fixture "), int_to_string(arena, i))).data);
            ok = 0;
        }
        if (!(test_commit_agrees(arena, fx.axioms, fx.classes, 0, 0))) {
            printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [ksc commit, G unstopped] W = 4 differs from W = 1, fixture "), int_to_string(arena, i))).len, (string_concat(arena, SLOP_STR("  [ksc commit, G unstopped] W = 4 differs from W = 1, fixture "), int_to_string(arena, i))).data);
            ok = 0;
        }
        if (!(test_commit_agrees(arena, fx.axioms, fx.classes, 0, 1))) {
            printf("%.*s\n", (int)(string_concat(arena, SLOP_STR("  [ksc commit, W] W = 4 differs from W = 1, fixture "), int_to_string(arena, i))).len, (string_concat(arena, SLOP_STR("  [ksc commit, W] W = 4 differs from W = 1, fixture "), int_to_string(arena, i))).data);
            ok = 0;
        }
        return ok;
    }
}

uint8_t test_test_ksc_commit_identical(slop_arena* arena) {
    {
        uint8_t ok = 1;
        int64_t i = 0;
        while (i < test_ksc_fixture_count()) {
            __auto_type _mv_1580 = test_ksc_fixture(arena, test_ksc_fixture_at(i));
            if (_mv_1580.has_value) {
                __auto_type fx = _mv_1580.value;
                if (!(test_commit_shapes_agree(arena, fx, i))) {
                    ok = 0;
                }
            } else if (!_mv_1580.has_value) {
                ok = 0;
            }
            i = (i + 1);
        }
        return ok;
    }
}

types_ReasonerConfig test_ksc_config(int64_t workers, int64_t cap) {
    {
        __auto_type cfg = types_default_config();
        cfg.worker_count = ((uint8_t)(SLOP_RANGE(uint8_t, workers, 1, 1, 1, 64, "(Int 1 .. 64) at test.slop:6083:52")));
        cfg.max_iterations = ((uint16_t)(SLOP_RANGE(uint16_t, cap, 1, 1, 0, 10000, "(Int 0 .. 10000) at test.slop:6084:57")));
        return cfg;
    }
}

uint8_t test_answers_equal(types_KscResult a, types_KscResult b) {
    if (!((a.inconsistent == b.inconsistent))) {
        return 0;
    } else {
        if (!((((int64_t)((a.answers).len)) == ((int64_t)((b.answers).len))))) {
            return 0;
        } else {
            {
                uint8_t ok = 1;
                int64_t i = 0;
                {
                    __auto_type _coll = a.answers;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        __auto_type _mv_1581 = ({ __auto_type _lst = b.answers; size_t _idx = (size_t)i; slop_option_types_ClassAnswer _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                        if (_mv_1581.has_value) {
                            __auto_type y = _mv_1581.value;
                            if (!(types_kname_eq(x.cls, y.cls))) {
                                ok = 0;
                            }
                            if (!((x.unsat == y.unsat))) {
                                ok = 0;
                            }
                            if (!((((int64_t)((x.subsumers).len)) == ((int64_t)((y.subsumers).len))))) {
                                ok = 0;
                            }
                            {
                                int64_t j = 0;
                                {
                                    __auto_type _coll = x.subsumers;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type n = _coll.data[_i];
                                        __auto_type _mv_1582 = ({ __auto_type _lst = y.subsumers; size_t _idx = (size_t)j; slop_option_types_KName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                        if (_mv_1582.has_value) {
                                            __auto_type m = _mv_1582.value;
                                            if (!(types_kname_eq(n, m))) {
                                                ok = 0;
                                            }
                                        } else if (!_mv_1582.has_value) {
                                            ok = 0;
                                        }
                                        j = (j + 1);
                                    }
                                }
                            }
                        } else if (!_mv_1581.has_value) {
                            ok = 0;
                        }
                        i = (i + 1);
                    }
                }
                return ok;
            }
        }
    }
}

uint8_t test_test_ksc_workers_agree(slop_arena* arena) {
    {
        uint8_t ok = 1;
        int64_t i = 0;
        while (i < test_ksc_fixture_count()) {
            __auto_type _mv_1583 = test_ksc_fixture(arena, test_ksc_fixture_at(i));
            if (_mv_1583.has_value) {
                __auto_type fx = _mv_1583.value;
                {
                    __auto_type full = test_ksc_run(arena, fx.axioms, fx.classes, test_ksc_config(1, 1000));
                    int64_t cap = 0;
                    while (cap <= (full.rounds + 1)) {
                        {
                            __auto_type one = test_ksc_run(arena, fx.axioms, fx.classes, test_ksc_config(1, cap));
                            {
                                __auto_type _coll = test_workers_under_test(arena);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type w = _coll.data[_i];
                                    if (!(test_same_run(one, test_ksc_run(arena, fx.axioms, fx.classes, test_ksc_config(w, cap))))) {
                                        printf("%.*s\n", (int)(string_concat(arena, string_concat(arena, SLOP_STR("  [ksc workers] fixture "), int_to_string(arena, i)), string_concat(arena, SLOP_STR(" differs at W="), string_concat(arena, int_to_string(arena, w), string_concat(arena, SLOP_STR(", cap "), int_to_string(arena, cap)))))).len, (string_concat(arena, string_concat(arena, SLOP_STR("  [ksc workers] fixture "), int_to_string(arena, i)), string_concat(arena, SLOP_STR(" differs at W="), string_concat(arena, int_to_string(arena, w), string_concat(arena, SLOP_STR(", cap "), int_to_string(arena, cap)))))).data);
                                        ok = 0;
                                    }
                                }
                            }
                            cap = (cap + 1);
                        }
                    }
                }
            } else if (!_mv_1583.has_value) {
                ok = 0;
            }
            i = (i + 1);
        }
        return ok;
    }
}

uint8_t test_same_run(types_KscResult a, types_KscResult b) {
    {
        uint8_t ok = test_answers_equal(a, b);
        int64_t i = 0;
        if (!((a.rounds == b.rounds))) {
            ok = 0;
        }
        if (!((a.g_rounds == b.g_rounds))) {
            ok = 0;
        }
        if (!((a.g_facts == b.g_facts))) {
            ok = 0;
        }
        if (!((a.w_rounds == b.w_rounds))) {
            ok = 0;
        }
        if (!((a.w_facts == b.w_facts))) {
            ok = 0;
        }
        if (!((a.unsafe_count == b.unsafe_count))) {
            ok = 0;
        }
        if (!(({ __auto_type _mv = a.termination; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case types_Termination_fixpoint: { _mr = ({ __auto_type _mv = b.termination; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case types_Termination_fixpoint: { _mr = 1; _mm = 1; break; } case types_Termination_resource_limit: { _mr = 0; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }); _mm = 1; break; } case types_Termination_resource_limit: { __auto_type x = _mv.data.resource_limit; _mr = ({ __auto_type _mv = b.termination; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case types_Termination_fixpoint: { _mr = 0; _mm = 1; break; } case types_Termination_resource_limit: { __auto_type y = _mv.data.resource_limit; _mr = (x == y); _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }); _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }))) {
            ok = 0;
        }
        {
            __auto_type _coll = a.answers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                __auto_type _mv_1584 = ({ __auto_type _lst = b.answers; size_t _idx = (size_t)i; slop_option_types_ClassAnswer _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1584.has_value) {
                    __auto_type y = _mv_1584.value;
                    if (!((((x.shared == y.shared)) ? (((x.complete == y.complete)) ? (((x.rounds == y.rounds)) ? (x.facts == y.facts) : 0) : 0) : 0))) {
                        ok = 0;
                    }
                } else if (!_mv_1584.has_value) {
                    ok = 0;
                }
                i = (i + 1);
            }
        }
        return ok;
    }
}

slop_list_int test_workers_under_test(slop_arena* arena) {
    {
        __auto_type ws = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ws); __auto_type _item = (2); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ws); __auto_type _item = (4); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ws); __auto_type _item = (8); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ws;
    }
}

uint8_t test_test_ksc_seed_unsat_counts_no_round(slop_arena* arena) {
    __auto_type _mv_1585 = test_ksc_fixture(arena, test_ksc_fixture_at(32));
    if (!_mv_1585.has_value) {
        return 0;
    } else if (_mv_1585.has_value) {
        __auto_type fx = _mv_1585.value;
        {
            __auto_type r = test_ksc_run(arena, fx.axioms, fx.classes, test_ksc_config(1, 1000));
            __auto_type r0 = test_ksc_run(arena, fx.axioms, fx.classes, test_ksc_config(1, 1000));
            return ((({ __auto_type _mv = r.termination; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case types_Termination_fixpoint: { _mr = 1; _mm = 1; break; } case types_Termination_resource_limit: { _mr = 0; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; })) && ((r.rounds == (r.g_rounds + (r.w_rounds + test_max_run_rounds(r))))) && ((test_nothing_run_rounds(r) == 0)) && (!(r0.inconsistent)));
        }
    }
    SLOP_UNREACHABLE();
}

int64_t test_nothing_run_rounds(types_KscResult r) {
    {
        __auto_type nothing = ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = vocab_OWL_NOTHING}) });
        int64_t out = -1;
        {
            __auto_type _coll = r.answers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (types_kname_eq(a.cls, nothing)) {
                    if (!(a.shared)) {
                        out = a.rounds;
                    }
                }
            }
        }
        return out;
    }
}

int64_t test_max_run_rounds(types_KscResult r) {
    {
        int64_t m = 0;
        {
            __auto_type _coll = r.answers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (a.rounds > m) {
                    m = a.rounds;
                }
            }
        }
        return m;
    }
}

uint8_t test_test_ksc_cap(slop_arena* arena) {
    __auto_type _mv_1586 = test_ksc_fixture(arena, test_ksc_fixture_at(0));
    if (!_mv_1586.has_value) {
        return 0;
    } else if (_mv_1586.has_value) {
        __auto_type fx = _mv_1586.value;
        {
            __auto_type full = test_ksc_run(arena, fx.axioms, fx.classes, test_ksc_config(1, 1000));
            __auto_type capped = test_ksc_run(arena, fx.axioms, fx.classes, test_ksc_config(1, 1));
            __auto_type zero = test_ksc_run(arena, fx.axioms, fx.classes, test_ksc_config(1, 0));
            return ((({ __auto_type _mv = full.termination; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case types_Termination_fixpoint: { _mr = 1; _mm = 1; break; } case types_Termination_resource_limit: { _mr = 0; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; })) && (({ __auto_type _mv = capped.termination; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case types_Termination_fixpoint: { _mr = 0; _mm = 1; break; } case types_Termination_resource_limit: { _mr = 1; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; })) && ((((int64_t)((capped.answers).len)) == 0)) && (!(capped.inconsistent)) && (({ __auto_type _mv = zero.termination; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case types_Termination_fixpoint: { _mr = 0; _mm = 1; break; } case types_Termination_resource_limit: { _mr = 1; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; })) && ((capped.rounds <= 1)) && ((((int64_t)((full.answers).len)) > 0)));
        }
    }
    SLOP_UNREACHABLE();
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
    __auto_type _mv_1587 = test_gate_ttl(arena, ttl);
    if (!_mv_1587.has_value) {
        return SLOP_STR("<did not gate>");
    } else if (_mv_1587.has_value) {
        __auto_type gr = _mv_1587.value;
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
    return (test_omits_exactly(arena, SLOP_STR("literal hasValue"), SLOP_STR(":C a owl:Class . :d a owl:DatatypeProperty . :C owl:equivalentClass [ a owl:Restriction ; owl:onProperty :d ; owl:hasValue \"x\" ] ."), SLOP_STR("SubClassOf(DataRange(DataHasValue(http://example.org/t#d \"x\")) http://example.org/t#C)\nSubClassOf(http://example.org/t#C DataRange(DataHasValue(http://example.org/t#d \"x\")))\n")) && test_omits_exactly(arena, SLOP_STR("literal hasValue on an object property"), SLOP_STR(":C a owl:Class . :r a owl:ObjectProperty . :C owl:equivalentClass [ a owl:Restriction ; owl:onProperty :r ; owl:hasValue \"x\" ] ."), SLOP_STR("SubClassOf(DataRange(owl:hasValue with a literal (DataHasValue)) http://example.org/t#C)\nSubClassOf(http://example.org/t#C DataRange(owl:hasValue with a literal (DataHasValue)))\n")));
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
        return ((test_accepts_exactly(arena, SLOP_STR("E out of profile"), SLOP_STR(":r rdfs:range [ owl:intersectionOf ( :A [ owl:complementOf [ owl:unionOf ( :B :C ) ] ] ) ] ."), SLOP_STR(""))) && ((test_gate_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR(":r rdfs:range [ owl:intersectionOf ( :A [ owl:complementOf [ owl:unionOf ( :B :C ) ] ] ) ] ."))) == 1)) && (test_accepts_exactly(arena, SLOP_STR("C out of profile"), SLOP_STR("[ owl:unionOf ( :A :C ) ] rdfs:subClassOf [ owl:complementOf :B ] ."), SLOP_STR(""))) && ((canon_string_cmp(test_omissions_of_ttl(arena, string_concat(arena, pre, SLOP_STR("[ owl:unionOf ( :A :C ) ] rdfs:subClassOf [ owl:complementOf :B ] ."))), SLOP_STR("SubClassOf(ObjectUnionOf(http://example.org/t#A http://example.org/t#C) ObjectComplementOf(http://example.org/t#B))\n")) == 0)) && (test_accepts_exactly(arena, SLOP_STR("under an existential"), SLOP_STR(":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:someValuesFrom [ owl:complementOf :B ] ] ."), SLOP_STR(""))));
    }
}

uint8_t test_test_negative_range_normalizes_to_bottom(slop_arena* arena) {
    {
        __auto_type b_cls = test_cls(SLOP_STR("http://example.org/t#B"));
        __auto_type r = test_rol(SLOP_STR("http://example.org/t#r"));
        __auto_type _mv_1588 = test_normalize_fixture(arena, SLOP_STR("corpus/fixtures/probes/complement-range.ttl"));
        if (!_mv_1588.has_value) {
            return 0;
        } else if (_mv_1588.has_value) {
            __auto_type no = _mv_1588.value;
            {
                __auto_type ax = no.axioms;
                slop_option_types_Node target = (slop_option_types_Node){.has_value = false};
                {
                    __auto_type _coll = ax;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type a = _coll.data[_i];
                        __auto_type _mv_1589 = a;
                        switch (_mv_1589.tag) {
                            case types_NormAxiom_sub_some_lhs:
                            {
                                __auto_type rr = _mv_1589.data.sub_some_lhs.f0;
                                __auto_type c = _mv_1589.data.sub_some_lhs.f1;
                                __auto_type d = _mv_1589.data.sub_some_lhs.f2;
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
                __auto_type _mv_1590 = target;
                if (!_mv_1590.has_value) {
                    return 0;
                } else if (_mv_1590.has_value) {
                    __auto_type x = _mv_1590.value;
                    return (({ __auto_type _mv = x; uint8_t _mr = {0}; switch (_mv.tag) { case types_Node_fresh_node: { _mr = 1; break; } default: { _mr = 0; break; }  } _mr; }) && test_norm_contains(ax, ((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = x, .f1 = types_node_bottom() } })));
                }
                SLOP_UNREACHABLE();
            }
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_norm_eq(types_NormAxiom a, types_NormAxiom b) {
    __auto_type _mv_1591 = a;
    switch (_mv_1591.tag) {
        case types_NormAxiom_sub_name:
        {
            __auto_type x = _mv_1591.data.sub_name.f0;
            __auto_type y = _mv_1591.data.sub_name.f1;
            __auto_type _mv_1592 = b;
            switch (_mv_1592.tag) {
                case types_NormAxiom_sub_name:
                {
                    __auto_type p = _mv_1592.data.sub_name.f0;
                    __auto_type q = _mv_1592.data.sub_name.f1;
                    return (types_node_eq(x, p) && types_node_eq(y, q));
                }
                default: {
                    return 0;
                }
            }
        }
        case types_NormAxiom_sub_and:
        {
            __auto_type x = _mv_1591.data.sub_and.f0;
            __auto_type y = _mv_1591.data.sub_and.f1;
            __auto_type z = _mv_1591.data.sub_and.f2;
            __auto_type _mv_1593 = b;
            switch (_mv_1593.tag) {
                case types_NormAxiom_sub_and:
                {
                    __auto_type p = _mv_1593.data.sub_and.f0;
                    __auto_type q = _mv_1593.data.sub_and.f1;
                    __auto_type r = _mv_1593.data.sub_and.f2;
                    return ((types_node_eq(x, p)) && (types_node_eq(y, q)) && (types_node_eq(z, r)));
                }
                default: {
                    return 0;
                }
            }
        }
        case types_NormAxiom_sub_some_rhs:
        {
            __auto_type x = _mv_1591.data.sub_some_rhs.f0;
            __auto_type r = _mv_1591.data.sub_some_rhs.f1;
            __auto_type y = _mv_1591.data.sub_some_rhs.f2;
            __auto_type _mv_1594 = b;
            switch (_mv_1594.tag) {
                case types_NormAxiom_sub_some_rhs:
                {
                    __auto_type p = _mv_1594.data.sub_some_rhs.f0;
                    __auto_type q = _mv_1594.data.sub_some_rhs.f1;
                    __auto_type z = _mv_1594.data.sub_some_rhs.f2;
                    return ((types_node_eq(x, p)) && (types_role_eq(r, q)) && (types_node_eq(y, z)));
                }
                default: {
                    return 0;
                }
            }
        }
        case types_NormAxiom_sub_some_lhs:
        {
            __auto_type r = _mv_1591.data.sub_some_lhs.f0;
            __auto_type x = _mv_1591.data.sub_some_lhs.f1;
            __auto_type y = _mv_1591.data.sub_some_lhs.f2;
            __auto_type _mv_1595 = b;
            switch (_mv_1595.tag) {
                case types_NormAxiom_sub_some_lhs:
                {
                    __auto_type q = _mv_1595.data.sub_some_lhs.f0;
                    __auto_type p = _mv_1595.data.sub_some_lhs.f1;
                    __auto_type z = _mv_1595.data.sub_some_lhs.f2;
                    return ((types_role_eq(r, q)) && (types_node_eq(x, p)) && (types_node_eq(y, z)));
                }
                default: {
                    return 0;
                }
            }
        }
        case types_NormAxiom_sub_role:
        {
            __auto_type r = _mv_1591.data.sub_role.f0;
            __auto_type s2 = _mv_1591.data.sub_role.f1;
            __auto_type _mv_1596 = b;
            switch (_mv_1596.tag) {
                case types_NormAxiom_sub_role:
                {
                    __auto_type q = _mv_1596.data.sub_role.f0;
                    __auto_type t2 = _mv_1596.data.sub_role.f1;
                    return (types_role_eq(r, q) && types_role_eq(s2, t2));
                }
                default: {
                    return 0;
                }
            }
        }
        case types_NormAxiom_role_chain:
        {
            __auto_type r = _mv_1591.data.role_chain.f0;
            __auto_type s2 = _mv_1591.data.role_chain.f1;
            __auto_type t2 = _mv_1591.data.role_chain.f2;
            __auto_type _mv_1597 = b;
            switch (_mv_1597.tag) {
                case types_NormAxiom_role_chain:
                {
                    __auto_type q = _mv_1597.data.role_chain.f0;
                    __auto_type u = _mv_1597.data.role_chain.f1;
                    __auto_type v = _mv_1597.data.role_chain.f2;
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
    __auto_type _mv_1598 = test_gate_fixture(arena, path);
    if (!_mv_1598.has_value) {
        return (slop_option_normalize_NormOutput){.has_value = false};
    } else if (_mv_1598.has_value) {
        __auto_type gr = _mv_1598.value;
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
        __auto_type _mv_1599 = test_normalize_fixture(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl"));
        if (!_mv_1599.has_value) {
            return 0;
        } else if (_mv_1599.has_value) {
            __auto_type no = _mv_1599.value;
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
        __auto_type _mv_1600 = test_normalize_fixture(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl"));
        if (!_mv_1600.has_value) {
            return 0;
        } else if (_mv_1600.has_value) {
            __auto_type no = _mv_1600.value;
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
        __auto_type _mv_1601 = test_normalize_fixture(arena, SLOP_STR("corpus/fixtures/v0/range.ttl"));
        if (!_mv_1601.has_value) {
            return 0;
        } else if (_mv_1601.has_value) {
            __auto_type no = _mv_1601.value;
            {
                __auto_type ax = no.axioms;
                slop_option_types_Node filler = (slop_option_types_Node){.has_value = false};
                {
                    __auto_type _coll = ax;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type a = _coll.data[_i];
                        __auto_type _mv_1602 = a;
                        switch (_mv_1602.tag) {
                            case types_NormAxiom_sub_some_rhs:
                            {
                                __auto_type c = _mv_1602.data.sub_some_rhs.f0;
                                __auto_type rr = _mv_1602.data.sub_some_rhs.f1;
                                __auto_type d = _mv_1602.data.sub_some_rhs.f2;
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
                __auto_type _mv_1603 = filler;
                if (!_mv_1603.has_value) {
                    return 0;
                } else if (_mv_1603.has_value) {
                    __auto_type x = _mv_1603.value;
                    return (({ __auto_type _mv = x; uint8_t _mr = {0}; switch (_mv.tag) { case types_Node_fresh_node: { _mr = 1; break; } default: { _mr = 0; break; }  } _mr; }) && test_norm_contains(ax, ((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = x, .f1 = a_cls } })));
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
        __auto_type _mv_1604 = test_normalize_fixture(arena, SLOP_STR("corpus/fixtures/hazards/abox-disjoint-range.ttl"));
        if (!_mv_1604.has_value) {
            return 0;
        } else if (_mv_1604.has_value) {
            __auto_type no = _mv_1604.value;
            {
                uint8_t saw_c = 0;
                uint8_t saw_d = 0;
                int64_t edges = ((int64_t)(((int64_t)((no.edges).len))));
                {
                    __auto_type _coll = no.seeds;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type sd = _coll.data[_i];
                        if (types_node_eq(sd.to, b_ind)) {
                            __auto_type _mv_1605 = sd.what;
                            switch (_mv_1605.tag) {
                                case types_Derived_derived_sub:
                                {
                                    __auto_type x = _mv_1605.data.derived_sub;
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
        return (test_complex_range_fillers_distinct(arena, path) && ({ __auto_type _mv = test_classify_fixture(arena, path); _mv.has_value ? ({ __auto_type o = _mv.value; ((((int64_t)(((int64_t)((o.findings.unsatisfiable).len)))) == 0) && ({ __auto_type _mv = types_verdict(o); int _mi = (_mv == types_Verdict_verdict_coherent) ? 1 : 2; _mi == 1 ? (1) : (0); })); }) : (0); }));
    }
}

uint8_t test_complex_range_fillers_distinct(slop_arena* arena, slop_string path) {
    {
        __auto_type c1 = test_cls(SLOP_STR("http://example.org/t#C1"));
        __auto_type c2 = test_cls(SLOP_STR("http://example.org/t#C2"));
        __auto_type r = test_rol(SLOP_STR("http://example.org/t#r"));
        __auto_type _mv_1606 = test_normalize_fixture(arena, path);
        if (!_mv_1606.has_value) {
            return 0;
        } else if (_mv_1606.has_value) {
            __auto_type no = _mv_1606.value;
            {
                slop_option_types_Node f1 = (slop_option_types_Node){.has_value = false};
                slop_option_types_Node f2 = (slop_option_types_Node){.has_value = false};
                {
                    __auto_type _coll = no.axioms;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type a = _coll.data[_i];
                        __auto_type _mv_1607 = a;
                        switch (_mv_1607.tag) {
                            case types_NormAxiom_sub_some_rhs:
                            {
                                __auto_type c = _mv_1607.data.sub_some_rhs.f0;
                                __auto_type rr = _mv_1607.data.sub_some_rhs.f1;
                                __auto_type d = _mv_1607.data.sub_some_rhs.f2;
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
                __auto_type _mv_1608 = f1;
                if (!_mv_1608.has_value) {
                    return 0;
                } else if (_mv_1608.has_value) {
                    __auto_type x1 = _mv_1608.value;
                    __auto_type _mv_1609 = f2;
                    if (!_mv_1609.has_value) {
                        return 0;
                    } else if (_mv_1609.has_value) {
                        __auto_type x2 = _mv_1609.value;
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
        return (((test_out_of_profile_count_of(arena, path) >= 2)) && (({ __auto_type _mv = test_classify_fixture(arena, path); _mv.has_value ? ({ __auto_type o = _mv.value; ((((int64_t)(((int64_t)((o.coverage.omitted).len)))) >= 3) && ({ __auto_type _mv = types_verdict(o); int _mi = (_mv == types_Verdict_verdict_inconclusive) ? 1 : 2; _mi == 1 ? (1) : (0); })); }) : (0); })) && (test_decodes_ok(arena, string_concat(arena, pre, SLOP_STR(":q rdfs:subPropertyOf [ owl:inverseOf :p ] .")))) && (!(test_decodes_ok(arena, string_concat(arena, pre, SLOP_STR(":q rdfs:subPropertyOf [ ] ."))))));
    }
}

slop_list_string test_m0_fixture_paths(slop_arena* arena) {
    {
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subclass-atomic.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/intersection.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-lhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-rhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-classes.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-properties.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-binary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subproperty.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/transitive.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/domain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/abox-assertions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/top-bottom.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/litmus.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-superclass.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-domain-range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/range-complex-fillers.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/abox-disjoint-range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ps;
    }
}

uint8_t test_accounting_exempt(owl2_RawAxiom ax) {
    __auto_type _mv_1610 = ax;
    switch (_mv_1610.tag) {
        case owl2_RawAxiom_ra_object_property_range:
        {
            return 1;
        }
        case owl2_RawAxiom_ra_declaration:
        {
            __auto_type _ = _mv_1610.data.ra_declaration;
            return 1;
        }
        case owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type r = _mv_1610.data.ra_sub_class_of.f1;
            __auto_type _mv_1611 = (*r);
            switch (_mv_1611.tag) {
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
        __auto_type one = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(one); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                __auto_type _mv_1612 = test_gate_fixture(arena, p);
                if (!_mv_1612.has_value) {
                    printf("%s", "  [accounting] did not gate: ");
                    printf("%.*s\n", (int)(p).len, (p).data);
                    ok = 0;
                } else if (_mv_1612.has_value) {
                    __auto_type gr = _mv_1612.value;
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
            __auto_type _mv_1613 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_owl2_RawAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1613.has_value) {
                __auto_type x = _mv_1613.value;
                __auto_type _mv_1614 = ({ __auto_type _lst = ys; size_t _idx = (size_t)i; slop_option_owl2_RawAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1614.has_value) {
                    __auto_type y = _mv_1614.value;
                    if (!(string_eq(owl2_render_axiom(arena, x), owl2_render_axiom(arena, y)))) {
                        ok = 0;
                    }
                } else if (!_mv_1614.has_value) {
                    ok = 0;
                }
            } else if (!_mv_1613.has_value) {
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
                __auto_type _mv_1615 = test_gate_fixture(arena, p);
                if (!_mv_1615.has_value) {
                    ok = 0;
                } else if (_mv_1615.has_value) {
                    __auto_type gr = _mv_1615.value;
                    {
                        __auto_type again = gate_gate_axioms(arena, gr.accepted, gr.signature, ((slop_list_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), types_Profile_profile_el);
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
        __auto_type out = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1616 = ax;
        switch (_mv_1616.tag) {
            case types_NormAxiom_sub_name:
            {
                __auto_type a = _mv_1616.data.sub_name.f0;
                __auto_type b = _mv_1616.data.sub_name.f1;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_NormAxiom_sub_and:
            {
                __auto_type a = _mv_1616.data.sub_and.f0;
                __auto_type b = _mv_1616.data.sub_and.f1;
                __auto_type c = _mv_1616.data.sub_and.f2;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_NormAxiom_sub_some_lhs:
            {
                __auto_type r = _mv_1616.data.sub_some_lhs.f0;
                __auto_type a = _mv_1616.data.sub_some_lhs.f1;
                __auto_type b = _mv_1616.data.sub_some_lhs.f2;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_NormAxiom_sub_some_rhs:
            {
                __auto_type a = _mv_1616.data.sub_some_rhs.f0;
                __auto_type r = _mv_1616.data.sub_some_rhs.f1;
                __auto_type b = _mv_1616.data.sub_some_rhs.f2;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_NormAxiom_sub_role:
            {
                __auto_type r = _mv_1616.data.sub_role.f0;
                __auto_type s = _mv_1616.data.sub_role.f1;
                break;
            }
            case types_NormAxiom_role_chain:
            {
                __auto_type r = _mv_1616.data.role_chain.f0;
                __auto_type s = _mv_1616.data.role_chain.f1;
                __auto_type t = _mv_1616.data.role_chain.f2;
                break;
            }
        }
        return out;
    }
}

uint8_t test_fresh_ids_dense(slop_arena* arena, normalize_NormOutput no) {
    {
        __auto_type n = no.fresh_count;
        __auto_type seen = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t ok = 1;
        int64_t i = 0;
        while (i < n) {
            ({ __auto_type _lst_p = &(seen); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                        __auto_type _mv_1617 = nd;
                        switch (_mv_1617.tag) {
                            case types_Node_fresh_node:
                            {
                                __auto_type k = _mv_1617.data.fresh_node;
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
                                __auto_type _ = _mv_1617.data.class_node;
                                break;
                            }
                            case types_Node_individual_node:
                            {
                                __auto_type _ = _mv_1617.data.individual_node;
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
                __auto_type _mv_1618 = test_normalize_fixture(arena, p);
                if (!_mv_1618.has_value) {
                    ok = 0;
                } else if (_mv_1618.has_value) {
                    __auto_type no = _mv_1618.value;
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
        __auto_type out = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = (((int64_t)(((int64_t)((ts).len)))) - 1);
        while (k >= 0) {
            __auto_type _mv_1619 = ({ __auto_type _lst = ts; size_t _idx = (size_t)k; slop_option_rdf_Triple _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1619.has_value) {
                __auto_type t = _mv_1619.value;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_1619.has_value) {
            }
            k = (k - 1);
        }
        return out;
    }
}

slop_option_normalize_NormOutput test_normalize_triples(slop_arena* arena, slop_list_rdf_Triple ts) {
    __auto_type _mv_1620 = decode_stage0_header(arena, ts, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
    if (!_mv_1620.is_ok) {
        __auto_type _ = _mv_1620.data.err;
        return (slop_option_normalize_NormOutput){.has_value = false};
    } else if (_mv_1620.is_ok) {
        __auto_type s0 = _mv_1620.data.ok;
        __auto_type _mv_1621 = decode_decode_axioms(arena, s0.dict, s0.triples);
        if (!_mv_1621.is_ok) {
            __auto_type _ = _mv_1621.data.err;
            return (slop_option_normalize_NormOutput){.has_value = false};
        } else if (_mv_1621.is_ok) {
            __auto_type s1 = _mv_1621.data.ok;
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
            __auto_type _mv_1622 = ({ __auto_type _lst = a.axioms; size_t _idx = (size_t)i; slop_option_types_NormAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1622.has_value) {
                __auto_type x = _mv_1622.value;
                __auto_type _mv_1623 = ({ __auto_type _lst = b.axioms; size_t _idx = (size_t)i; slop_option_types_NormAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1623.has_value) {
                    __auto_type y = _mv_1623.value;
                    if (!(test_norm_eq(x, y))) {
                        ok = 0;
                    }
                } else if (!_mv_1623.has_value) {
                    ok = 0;
                }
            } else if (!_mv_1622.has_value) {
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
            __auto_type _mv_1624 = ({ __auto_type _lst = sa; size_t _idx = (size_t)i; slop_option_types_SubPair _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1624.has_value) {
                __auto_type x = _mv_1624.value;
                __auto_type _mv_1625 = ({ __auto_type _lst = sb; size_t _idx = (size_t)i; slop_option_types_SubPair _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1625.has_value) {
                    __auto_type y = _mv_1625.value;
                    if (canon_sub_pair_cmp(x, y) != 0) {
                        ok = 0;
                    }
                } else if (!_mv_1625.has_value) {
                    ok = 0;
                }
            } else if (!_mv_1624.has_value) {
                ok = 0;
            }
            i = (i + 1);
        }
        i = 0;
        while (ok && (i < ((int64_t)(((int64_t)((ua).len)))))) {
            __auto_type _mv_1626 = ({ __auto_type _lst = ua; size_t _idx = (size_t)i; slop_option_rdf_IRI _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1626.has_value) {
                __auto_type x = _mv_1626.value;
                __auto_type _mv_1627 = ({ __auto_type _lst = ub; size_t _idx = (size_t)i; slop_option_rdf_IRI _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1627.has_value) {
                    __auto_type y = _mv_1627.value;
                    if (canon_iri_cmp(x, y) != 0) {
                        ok = 0;
                    }
                } else if (!_mv_1627.has_value) {
                    ok = 0;
                }
            } else if (!_mv_1626.has_value) {
                ok = 0;
            }
            i = (i + 1);
        }
        i = 0;
        while (ok && (i < ((int64_t)(((int64_t)((oa).len)))))) {
            __auto_type _mv_1628 = ({ __auto_type _lst = oa; size_t _idx = (size_t)i; slop_option_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1628.has_value) {
                __auto_type x = _mv_1628.value;
                __auto_type _mv_1629 = ({ __auto_type _lst = ob; size_t _idx = (size_t)i; slop_option_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1629.has_value) {
                    __auto_type y = _mv_1629.value;
                    if (canon_omission_cmp(x, y) != 0) {
                        ok = 0;
                    }
                } else if (!_mv_1629.has_value) {
                    ok = 0;
                }
            } else if (!_mv_1628.has_value) {
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
            __auto_type _mv_1630 = ({ __auto_type _lst = a; size_t _idx = (size_t)i; slop_option_string _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1630.has_value) {
                __auto_type x = _mv_1630.value;
                __auto_type _mv_1631 = ({ __auto_type _lst = b; size_t _idx = (size_t)i; slop_option_string _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1631.has_value) {
                    __auto_type y = _mv_1631.value;
                    if (!(string_eq(x, y))) {
                        ok = 0;
                    }
                } else if (!_mv_1631.has_value) {
                    ok = 0;
                }
            } else if (!_mv_1630.has_value) {
                ok = 0;
            }
            i = (i + 1);
        }
        return ok;
    }
}

uint8_t test_encoded_agrees(slop_arena* arena, slop_string path, types_ProfileSelection selection) {
    {
        __auto_type cfg = types_default_config();
        cfg.selection = selection;
        __auto_type _mv_1632 = ttl_parse_ttl_file(arena, path);
        if (!_mv_1632.is_ok) {
            __auto_type _ = _mv_1632.data.err;
            return 0;
        } else if (_mv_1632.is_ok) {
            __auto_type g = _mv_1632.data.ok;
            {
                __auto_type doc = termstore_encode_triples(arena, g.triples);
                __auto_type _mv_1633 = howl_classify(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), cfg);
                if (!_mv_1633.is_ok) {
                    __auto_type _ = _mv_1633.data.err;
                    return 0;
                } else if (_mv_1633.is_ok) {
                    __auto_type o1 = _mv_1633.data.ok;
                    __auto_type _mv_1634 = howl_classify_encoded(arena, doc, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), cfg);
                    if (!_mv_1634.is_ok) {
                        __auto_type _ = _mv_1634.data.err;
                        return 0;
                    } else if (_mv_1634.is_ok) {
                        __auto_type o2 = _mv_1634.data.ok;
                        __auto_type _mv_1635 = howl_classify_encoded(arena, doc, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), cfg);
                        if (!_mv_1635.is_ok) {
                            __auto_type _ = _mv_1635.data.err;
                            return 0;
                        } else if (_mv_1635.is_ok) {
                            __auto_type o3 = _mv_1635.data.ok;
                            {
                                __auto_type l1 = report_report_lines(arena, o1);
                                if (test_same_lines(l1, report_report_lines(arena, o2)) && test_same_lines(l1, report_report_lines(arena, o3))) {
                                    return 1;
                                } else {
                                    printf("%s", "  [encoded] report differs: ");
                                    printf("%.*s\n", (int)(path).len, (path).data);
                                    return 0;
                                }
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
}

uint8_t test_test_classify_encoded_is_classify(slop_arena* arena) {
    {
        uint8_t ok = 1;
        __auto_type el = ((types_ProfileSelection){ .tag = types_ProfileSelection_explicit, .data.explicit = types_Profile_profile_el });
        __auto_type elpp = ((types_ProfileSelection){ .tag = types_ProfileSelection_explicit, .data.explicit = types_Profile_profile_el_plus_plus });
        {
            __auto_type _coll = test_m0_fixture_paths(arena);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (!((test_encoded_agrees(arena, p, el) && test_encoded_agrees(arena, p, elpp)))) {
                    ok = 0;
                }
            }
        }
        if (!(test_encoded_agrees(arena, SLOP_STR("corpus/fixtures/hazards/unattested-import.ttl"), el))) {
            ok = 0;
        }
        return ok;
    }
}

slop_option_string test_file_text(slop_arena* arena, slop_string path) {
    __auto_type _mv_1636 = file_file_open(path, file_FileMode_read);
    if (!_mv_1636.is_ok) {
        __auto_type _ = _mv_1636.data.err;
        return (slop_option_string){.has_value = false};
    } else if (_mv_1636.is_ok) {
        __auto_type f = _mv_1636.data.ok;
        {
            __auto_type h = f;
            __auto_type text = ({ __auto_type _mv = file_file_read_all(arena, (&h)); slop_option_string _mr; if (_mv.is_ok) { __auto_type t = _mv.data.ok; _mr = (slop_option_string){.has_value = 1, .value = t}; } else { __auto_type _ = _mv.data.err; _mr = ((slop_option_string){.has_value = false}); } _mr; });
            file_file_close((&h));
            return text;
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_string test_api_lines(slop_arena* arena, howl_Run r) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < howl_run_report_len(r)) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (string_concat(arena, SLOP_STR(""), howl_run_report_line(r, i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        return out;
    }
}

uint8_t test_api_agrees(slop_arena* arena, slop_string path, types_Profile profile) {
    __auto_type _mv_1637 = test_file_text(arena, path);
    if (!_mv_1637.has_value) {
        return 0;
    } else if (_mv_1637.has_value) {
        __auto_type text = _mv_1637.value;
        __auto_type _mv_1638 = ttl_parse_ttl_file(arena, path);
        if (!_mv_1638.is_ok) {
            __auto_type _ = _mv_1638.data.err;
            return 0;
        } else if (_mv_1638.is_ok) {
            __auto_type g = _mv_1638.data.ok;
            {
                __auto_type cfg = types_default_config();
                __auto_type o = howl_default_options();
                __auto_type in = howl_input_new();
                cfg.selection = ((types_ProfileSelection){ .tag = types_ProfileSelection_explicit, .data.explicit = profile });
                o.profile = profile;
                howl_input_add_turtle(in, text);
                {
                    __auto_type r = howl_run_classify(in, o);
                    __auto_type same = ({ __auto_type _mv = howl_classify(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), cfg); uint8_t _mr; if (_mv.is_ok) { __auto_type want = _mv.data.ok; _mr = test_same_lines(report_report_lines(arena, want), test_api_lines(arena, r)); } else { __auto_type _ = _mv.data.err; _mr = 0; } _mr; });
                    howl_run_free(r);
                    howl_input_free(in);
                    if (!(same)) {
                        printf("%s", "  [api] report differs: ");
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

howl_FaultKind test_api_fault(howl_Options o) {
    {
        __auto_type in = howl_input_new();
        __auto_type r = howl_run_classify(in, o);
        __auto_type f = howl_run_fault(r);
        howl_run_free(r);
        howl_input_free(in);
        return f;
    }
}

uint8_t test_test_public_api(slop_arena* arena) {
    {
        uint8_t ok = 1;
        __auto_type d = howl_default_options();
        {
            __auto_type _coll = test_m0_fixture_paths(arena);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (!((test_api_agrees(arena, p, types_Profile_profile_el) && test_api_agrees(arena, p, types_Profile_profile_el_plus_plus)))) {
                    ok = 0;
                }
            }
        }
        {
            __auto_type o = d;
            o.workers = 0;
            if (!((test_api_fault(o) == howl_FaultKind_fault_invalid_options))) {
                ok = 0;
            }
        }
        {
            __auto_type o = d;
            o.workers = 65;
            if (!((test_api_fault(o) == howl_FaultKind_fault_invalid_options))) {
                ok = 0;
            }
        }
        {
            __auto_type o = d;
            o.max_iterations = 10001;
            if (!((test_api_fault(o) == howl_FaultKind_fault_invalid_options))) {
                ok = 0;
            }
        }
        {
            __auto_type o = d;
            o.max_iterations = -1;
            if (!((test_api_fault(o) == howl_FaultKind_fault_invalid_options))) {
                ok = 0;
            }
        }
        {
            __auto_type o = d;
            __auto_type in = howl_input_new();
            o.profile = types_Profile_profile_horn_sriq;
            {
                __auto_type r = howl_run_classify(in, o);
                if (!((((howl_run_fault(r) == howl_FaultKind_fault_unavailable)) && ((howl_run_fault_profile(r) == types_Profile_profile_horn_sriq)) && (string_eq(howl_run_fault_message(r), SLOP_STR("profile horn-sriq was dropped; sriq covers its language"))) && ((howl_run_verdict(r) == types_Verdict_verdict_inconclusive)) && (!(howl_run_ok(r)))))) {
                    ok = 0;
                }
                howl_run_free(r);
                howl_input_free(in);
            }
        }
        {
            __auto_type o = d;
            o.workers = 64;
            o.max_iterations = 0;
            if (!((test_api_fault(o) == howl_FaultKind_fault_none))) {
                ok = 0;
            }
        }
        return ok;
    }
}

uint8_t test_order_independent(slop_arena* arena, slop_string path) {
    __auto_type _mv_1639 = ttl_parse_ttl_file(arena, path);
    if (!_mv_1639.is_ok) {
        __auto_type _ = _mv_1639.data.err;
        return 0;
    } else if (_mv_1639.is_ok) {
        __auto_type g = _mv_1639.data.ok;
        {
            __auto_type fwd = g.triples;
            __auto_type rev = test_reversed_triples(arena, g.triples);
            __auto_type _mv_1640 = test_normalize_triples(arena, fwd);
            if (!_mv_1640.has_value) {
                return 0;
            } else if (_mv_1640.has_value) {
                __auto_type n1 = _mv_1640.value;
                __auto_type _mv_1641 = test_normalize_triples(arena, rev);
                if (!_mv_1641.has_value) {
                    return 0;
                } else if (_mv_1641.has_value) {
                    __auto_type n2 = _mv_1641.value;
                    if (!(test_same_normal_form(n1, n2))) {
                        printf("%s", "  [order] normal form differs: ");
                        printf("%.*s\n", (int)(path).len, (path).data);
                        return 0;
                    } else {
                        __auto_type _mv_1642 = howl_classify(arena, fwd, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), types_default_config());
                        if (!_mv_1642.is_ok) {
                            __auto_type _ = _mv_1642.data.err;
                            return 0;
                        } else if (_mv_1642.is_ok) {
                            __auto_type o1 = _mv_1642.data.ok;
                            __auto_type _mv_1643 = howl_classify(arena, rev, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), types_default_config());
                            if (!_mv_1643.is_ok) {
                                __auto_type _ = _mv_1643.data.err;
                                return 0;
                            } else if (_mv_1643.is_ok) {
                                __auto_type o2 = _mv_1643.data.ok;
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
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/litmus.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/range-complex-fillers.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/abox-disjoint-range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/rbox-regularity-reject.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/annotation-heavy.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/inverse-expressions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    __auto_type _mv_1644 = ttl_parse_ttl_file(arena, path);
    if (!_mv_1644.is_ok) {
        __auto_type _ = _mv_1644.data.err;
        return 0;
    } else if (_mv_1644.is_ok) {
        __auto_type g = _mv_1644.data.ok;
        __auto_type _mv_1645 = howl_prepare(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), types_default_config());
        if (!_mv_1645.is_ok) {
            __auto_type _ = _mv_1645.data.err;
            return 0;
        } else if (_mv_1645.is_ok) {
            __auto_type p = _mv_1645.data.ok;
            {
                __auto_type idx = test_prepared_el_work(arena, p).index;
                __auto_type axioms = test_prepared_el_work(arena, p).axioms;
                __auto_type _mv_1646 = howl_reason(arena, p, types_default_config());
                if (!_mv_1646.is_ok) {
                    __auto_type _ = _mv_1646.data.err;
                    return 0;
                } else if (_mv_1646.is_ok) {
                    __auto_type o = _mv_1646.data.ok;
                    {
                        uint8_t ok = 1;
                        int64_t facts = 0;
                        {
                            slop_map* _coll = (slop_map*)test_outcome_saturation(arena, o).contexts;
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
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/litmus.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/intersection.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-lhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-rhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/domain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subproperty.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-properties.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/abox-assertions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/top-bottom.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/abox-disjoint-range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/range-complex-fillers.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/rbox-regularity-accept.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/unsatisfiable-consistent.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/cyclic-hierarchy.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/smaller-side-join.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/probes/subproperty-existential.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("corpus/fixtures/hazards/role-hierarchy-deep.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, q1, tp, ont)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, q2, prop, o)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_1647 = decode_stage0_header(arena, ts, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        if (!_mv_1647.is_ok) {
            __auto_type _ = _mv_1647.data.err;
            return 0;
        } else if (_mv_1647.is_ok) {
            __auto_type s0 = _mv_1647.data.ok;
            return (((int64_t)(((int64_t)((s0.triples).len)))) == 0);
        }
        SLOP_UNREACHABLE();
    }
}

int64_t test_strict_outcome(slop_arena* arena, slop_string path) {
    {
        __auto_type cfg = types_default_config();
        cfg.strict_profile = 1;
        __auto_type _mv_1648 = ttl_parse_ttl_file(arena, path);
        if (!_mv_1648.is_ok) {
            __auto_type _ = _mv_1648.data.err;
            return -1;
        } else if (_mv_1648.is_ok) {
            __auto_type g = _mv_1648.data.ok;
            __auto_type _mv_1649 = howl_classify(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), cfg);
            if (_mv_1649.is_ok) {
                __auto_type _ = _mv_1649.data.ok;
                return 0;
            } else if (!_mv_1649.is_ok) {
                __auto_type f = _mv_1649.data.err;
                __auto_type _mv_1650 = f;
                switch (_mv_1650.tag) {
                    case types_Fault_refused:
                    {
                        __auto_type os = _mv_1650.data.refused;
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
                        __auto_type _ = _mv_1650.data.input_error;
                        return -1;
                    }
                    case types_Fault_unavailable:
                    {
                        __auto_type _ = _mv_1650.data.unavailable;
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

test_RunAs test_profile_run(slop_arena* arena, slop_string path, types_ProfileSelection selection) {
    {
        __auto_type cfg = types_default_config();
        cfg.selection = selection;
        __auto_type _mv_1651 = ttl_parse_ttl_file(arena, path);
        if (!_mv_1651.is_ok) {
            __auto_type _ = _mv_1651.data.err;
            return ((test_RunAs){ .tag = test_RunAs_failed });
        } else if (_mv_1651.is_ok) {
            __auto_type g = _mv_1651.data.ok;
            __auto_type _mv_1652 = howl_classify(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), cfg);
            if (_mv_1652.is_ok) {
                __auto_type o = _mv_1652.data.ok;
                return ((test_RunAs){ .tag = test_RunAs_ran, .data.ran = o.profile });
            } else if (!_mv_1652.is_ok) {
                __auto_type f = _mv_1652.data.err;
                __auto_type _mv_1653 = f;
                switch (_mv_1653.tag) {
                    case types_Fault_unavailable:
                    {
                        __auto_type p = _mv_1653.data.unavailable;
                        return ((test_RunAs){ .tag = test_RunAs_refused, .data.refused = p });
                    }
                    case types_Fault_refused:
                    {
                        __auto_type _ = _mv_1653.data.refused;
                        return ((test_RunAs){ .tag = test_RunAs_failed });
                    }
                    case types_Fault_cancelled:
                    {
                        return ((test_RunAs){ .tag = test_RunAs_failed });
                    }
                    case types_Fault_input_error:
                    {
                        __auto_type _ = _mv_1653.data.input_error;
                        return ((test_RunAs){ .tag = test_RunAs_failed });
                    }
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t test_ran_as(test_RunAs r, types_Profile want) {
    __auto_type _mv_1654 = r;
    switch (_mv_1654.tag) {
        case test_RunAs_ran:
        {
            __auto_type p = _mv_1654.data.ran;
            return (p == want);
        }
        case test_RunAs_refused:
        {
            __auto_type _ = _mv_1654.data.refused;
            return 0;
        }
        case test_RunAs_failed:
        {
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_refused_as(test_RunAs r, types_Profile want) {
    __auto_type _mv_1655 = r;
    switch (_mv_1655.tag) {
        case test_RunAs_ran:
        {
            __auto_type _ = _mv_1655.data.ran;
            return 0;
        }
        case test_RunAs_refused:
        {
            __auto_type p = _mv_1655.data.refused;
            return (p == want);
        }
        case test_RunAs_failed:
        {
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_profile_selection(slop_arena* arena) {
    {
        __auto_type litmus = SLOP_STR("corpus/fixtures/v0/litmus.ttl");
        __auto_type slop_auto = ((types_ProfileSelection){ .tag = types_ProfileSelection_slop_auto });
        return ((test_ran_as(test_profile_run(arena, litmus, types_default_config().selection), types_Profile_profile_el)) && (test_ran_as(test_profile_run(arena, litmus, ((types_ProfileSelection){ .tag = types_ProfileSelection_explicit, .data.explicit = types_Profile_profile_el })), types_Profile_profile_el)) && (test_ran_as(test_profile_run(arena, litmus, ((types_ProfileSelection){ .tag = types_ProfileSelection_explicit, .data.explicit = types_Profile_profile_el_plus_plus })), types_Profile_profile_el_plus_plus)) && (test_refused_as(test_profile_run(arena, litmus, ((types_ProfileSelection){ .tag = types_ProfileSelection_explicit, .data.explicit = types_Profile_profile_horn_sriq })), types_Profile_profile_horn_sriq)) && (test_refused_as(test_profile_run(arena, litmus, ((types_ProfileSelection){ .tag = types_ProfileSelection_explicit, .data.explicit = types_Profile_profile_sriq })), types_Profile_profile_sriq)) && (test_ran_as(test_profile_run(arena, litmus, slop_auto), types_Profile_profile_el)) && (test_ran_as(test_profile_run(arena, SLOP_STR("corpus/fixtures/el++/has-self.ttl"), slop_auto), types_Profile_profile_el_plus_plus)) && (test_ran_as(test_profile_run(arena, SLOP_STR("corpus/fixtures/out-of-profile/union.ttl"), slop_auto), types_Profile_profile_el)) && (test_ran_as(test_profile_run(arena, SLOP_STR("corpus/fixtures/out-of-profile/nominals.ttl"), slop_auto), types_Profile_profile_el_plus_plus)));
    }
}

uint8_t test_test_profile_names_round_trip(slop_arena* arena) {
    return ((test_name_round_trips(types_Profile_profile_el)) && (test_name_round_trips(types_Profile_profile_el_plus_plus)) && (test_name_round_trips(types_Profile_profile_horn_sriq)) && (test_name_round_trips(types_Profile_profile_sriq)) && (({ __auto_type _mv = select_parse_profile(SLOP_STR("auto")); _mv.has_value ? ({ __auto_type _ = _mv.value; 0; }) : (1); })) && (({ __auto_type _mv = select_parse_profile(SLOP_STR("EL")); _mv.has_value ? ({ __auto_type _ = _mv.value; 0; }) : (1); })) && (({ __auto_type _mv = select_parse_profile(SLOP_STR("sroiq")); _mv.has_value ? ({ __auto_type _ = _mv.value; 0; }) : (1); })));
}

uint8_t test_test_dropped_rung_refusal(slop_arena* arena) {
    return ((select_profile_dropped(types_Profile_profile_horn_sriq)) && (!(select_profile_dropped(types_Profile_profile_el))) && (!(select_profile_dropped(types_Profile_profile_el_plus_plus))) && (!(select_profile_dropped(types_Profile_profile_sriq))) && (string_eq(select_unavailable_message(arena, types_Profile_profile_horn_sriq), SLOP_STR("profile horn-sriq was dropped; sriq covers its language"))) && (string_eq(select_unavailable_message(arena, types_Profile_profile_sriq), SLOP_STR("profile sriq is not implemented yet (implemented: el, el++)"))));
}

uint8_t test_name_round_trips(types_Profile p) {
    __auto_type _mv_1656 = select_parse_profile(select_profile_name(p));
    if (_mv_1656.has_value) {
        __auto_type q = _mv_1656.value;
        return (q == p);
    } else if (!_mv_1656.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_strict_refuses_past_omissions(slop_arena* arena) {
    return ((test_strict_outcome(arena, SLOP_STR("corpus/fixtures/out-of-profile/union.ttl")) == 1) && (test_strict_outcome(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl")) == 0));
}

uint8_t test_test_nary_chain_decomposes_left_associated(slop_arena* arena) {
    __auto_type _mv_1657 = test_normalize_fixture(arena, SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl"));
    if (!_mv_1657.has_value) {
        return 0;
    } else if (_mv_1657.has_value) {
        __auto_type no = _mv_1657.value;
        {
            int64_t chains = 0;
            {
                __auto_type _coll = no.axioms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    __auto_type _mv_1658 = a;
                    switch (_mv_1658.tag) {
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
    __auto_type _mv_1659 = ttl_parse_ttl_file(arena, path);
    if (!_mv_1659.is_ok) {
        __auto_type _ = _mv_1659.data.err;
        return (slop_option_u8){.has_value = false};
    } else if (_mv_1659.is_ok) {
        __auto_type g = _mv_1659.data.ok;
        __auto_type _mv_1660 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        if (!_mv_1660.is_ok) {
            __auto_type _ = _mv_1660.data.err;
            return (slop_option_u8){.has_value = false};
        } else if (_mv_1660.is_ok) {
            __auto_type s0 = _mv_1660.data.ok;
            __auto_type _mv_1661 = decode_decode_axioms(arena, s0.dict, s0.triples);
            if (!_mv_1661.is_ok) {
                __auto_type _ = _mv_1661.data.err;
                return (slop_option_u8){.has_value = false};
            } else if (_mv_1661.is_ok) {
                __auto_type s1 = _mv_1661.data.ok;
                __auto_type _mv_1662 = gate_check_regularity(arena, gate_expand_sugar(arena, s1.axioms));
                switch (_mv_1662.tag) {
                    case gate_RboxVerdict_rbox_regular:
                    {
                        return (slop_option_u8){.has_value = 1, .value = 1};
                    }
                    case gate_RboxVerdict_rbox_irregular:
                    {
                        __auto_type _ = _mv_1662.data.rbox_irregular;
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
    __auto_type _mv_1663 = test_regularity_of(arena, SLOP_STR("corpus/fixtures/hazards/rbox-regularity-reject.ttl"));
    if (!_mv_1663.has_value) {
        return 0;
    } else if (_mv_1663.has_value) {
        __auto_type regular = _mv_1663.value;
        return !(regular);
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_regularity_accepts_equivalence_and_transitivity(slop_arena* arena) {
    __auto_type _mv_1664 = test_regularity_of(arena, SLOP_STR("corpus/fixtures/hazards/rbox-regularity-accept.ttl"));
    if (!_mv_1664.has_value) {
        return 0;
    } else if (_mv_1664.has_value) {
        __auto_type regular = _mv_1664.value;
        return regular;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_regularity_accepts_plain_subproperty(slop_arena* arena) {
    __auto_type _mv_1665 = test_regularity_of(arena, SLOP_STR("corpus/fixtures/v0/subproperty.ttl"));
    if (!_mv_1665.has_value) {
        return 0;
    } else if (_mv_1665.has_value) {
        __auto_type regular = _mv_1665.value;
        return regular;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_regularity_accepts_nary_chain(slop_arena* arena) {
    __auto_type _mv_1666 = test_regularity_of(arena, SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl"));
    if (!_mv_1666.has_value) {
        return 0;
    } else if (_mv_1666.has_value) {
        __auto_type regular = _mv_1666.value;
        return regular;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_irregular_rbox_is_omitted_whole(slop_arena* arena) {
    __auto_type _mv_1667 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/hazards/rbox-regularity-reject.ttl"));
    if (!_mv_1667.has_value) {
        return 0;
    } else if (_mv_1667.has_value) {
        __auto_type gr = _mv_1667.value;
        return ((((int64_t)(((int64_t)((gr.omissions).len)))) > 0) && (test_count_variant_chain(gr.accepted) == 0));
    }
    SLOP_UNREACHABLE();
}

slop_option_gate_GateResult test_gate_fixture(slop_arena* arena, slop_string path) {
    return test_gate_fixture_in(arena, path, types_Profile_profile_el);
}

slop_option_gate_GateResult test_gate_fixture_in(slop_arena* arena, slop_string path, types_Profile p) {
    __auto_type _mv_1668 = ttl_parse_ttl_file(arena, path);
    if (!_mv_1668.is_ok) {
        __auto_type _ = _mv_1668.data.err;
        return (slop_option_gate_GateResult){.has_value = false};
    } else if (_mv_1668.is_ok) {
        __auto_type g = _mv_1668.data.ok;
        __auto_type _mv_1669 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        if (!_mv_1669.is_ok) {
            __auto_type _ = _mv_1669.data.err;
            return (slop_option_gate_GateResult){.has_value = false};
        } else if (_mv_1669.is_ok) {
            __auto_type s0 = _mv_1669.data.ok;
            __auto_type _mv_1670 = decode_decode_axioms(arena, s0.dict, s0.triples);
            if (!_mv_1670.is_ok) {
                __auto_type _ = _mv_1670.data.err;
                return (slop_option_gate_GateResult){.has_value = false};
            } else if (_mv_1670.is_ok) {
                __auto_type s1 = _mv_1670.data.ok;
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
                __auto_type _mv_1671 = a;
                switch (_mv_1671.tag) {
                    case owl2_RawAxiom_ra_property_chain:
                    {
                        __auto_type _ = _mv_1671.data.ra_property_chain;
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
                __auto_type _mv_1672 = a;
                switch (_mv_1672.tag) {
                    case owl2_RawAxiom_ra_disjoint_classes:
                    {
                        __auto_type _ = _mv_1672.data.ra_disjoint_classes;
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
                __auto_type _mv_1673 = a;
                switch (_mv_1673.tag) {
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
    __auto_type _mv_1674 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/hazards/annotation-heavy.ttl"));
    if (!_mv_1674.has_value) {
        return 0;
    } else if (_mv_1674.has_value) {
        __auto_type gr = _mv_1674.value;
        return ((((int64_t)(((int64_t)((gr.omissions).len)))) == 0) && (test_count_variant_subclass(gr.accepted) > 0));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_gate_carries_import_omissions(slop_arena* arena) {
    __auto_type _mv_1675 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/hazards/unattested-import.ttl"));
    if (!_mv_1675.has_value) {
        return 0;
    } else if (_mv_1675.has_value) {
        __auto_type gr = _mv_1675.value;
        return (((int64_t)(((int64_t)((gr.omissions).len)))) == 1);
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sugar_transitivity_becomes_a_chain(slop_arena* arena) {
    __auto_type _mv_1676 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/v0/transitive.ttl"));
    if (!_mv_1676.has_value) {
        return 0;
    } else if (_mv_1676.has_value) {
        __auto_type gr = _mv_1676.value;
        return ((test_count_variant_chain(gr.accepted) > 0) && (((int64_t)(((int64_t)((gr.omissions).len)))) == 0));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sugar_nary_disjointness_becomes_pairs(slop_arena* arena) {
    __auto_type _mv_1677 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl"));
    if (!_mv_1677.has_value) {
        return 0;
    } else if (_mv_1677.has_value) {
        __auto_type gr = _mv_1677.value;
        return (test_count_variant_disjoint(gr.accepted) == 3);
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sugar_equivalence_is_a_star_not_all_pairs(slop_arena* arena) {
    __auto_type _mv_1678 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/v0/equivalent-classes.ttl"));
    if (!_mv_1678.has_value) {
        return 0;
    } else if (_mv_1678.has_value) {
        __auto_type gr = _mv_1678.value;
        return ((test_count_variant_subclass(gr.accepted) > 0) && (((int64_t)(((int64_t)((gr.omissions).len)))) == 0));
    }
    SLOP_UNREACHABLE();
}

int64_t test_gate_omission_count(slop_arena* arena, slop_string path) {
    __auto_type _mv_1679 = test_gate_fixture(arena, path);
    if (!_mv_1679.has_value) {
        return -1;
    } else if (_mv_1679.has_value) {
        __auto_type gr = _mv_1679.value;
        return ((int64_t)(((int64_t)((gr.omissions).len))));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_gate_accepts_every_v0_fixture(slop_arena* arena) {
    {
        __auto_type paths = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t ok = 1;
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subclass-atomic.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/intersection.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-lhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-rhs.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-classes.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-properties.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-binary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subproperty.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/transitive.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/domain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/abox-assertions.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/top-bottom.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/litmus.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-superclass.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-domain-range.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/negation-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        __auto_type paths = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t ok = 1;
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/union.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/complement.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/allvalues.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/nominals.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/cardinality.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/el++/has-self.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/inverse.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/el++/equality.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/property-characteristics.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/haskey-disjointunion.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/swrl-rule.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/el++/builtin-roles.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/anonymous-individual.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/datatypes.ttl")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    __auto_type _mv_1680 = ttl_parse_ttl_file(arena, path);
    if (!_mv_1680.is_ok) {
        __auto_type _ = _mv_1680.data.err;
        return (slop_option_owl2_Signature){.has_value = false};
    } else if (_mv_1680.is_ok) {
        __auto_type g = _mv_1680.data.ok;
        __auto_type _mv_1681 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        if (!_mv_1681.is_ok) {
            __auto_type _ = _mv_1681.data.err;
            return (slop_option_owl2_Signature){.has_value = false};
        } else if (_mv_1681.is_ok) {
            __auto_type s0 = _mv_1681.data.ok;
            return (slop_option_owl2_Signature){.has_value = 1, .value = decode_build_signature(arena, s0.dict, s0.triples)};
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_declared_unused_class_reaches_the_signature(slop_arena* arena) {
    __auto_type _mv_1682 = test_signature_of_fixture(arena, SLOP_STR("corpus/fixtures/hazards/declared-unused-class.ttl"));
    if (!_mv_1682.has_value) {
        return 0;
    } else if (_mv_1682.has_value) {
        __auto_type sig = _mv_1682.value;
        return (owl2_signature_has_class(sig, ((rdf_IRI){.value = SLOP_STR("http://example.org/t#Unused")})) && owl2_signature_has_class(sig, ((rdf_IRI){.value = SLOP_STR("http://example.org/t#A")})));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_builtins_are_declared(slop_arena* arena) {
    __auto_type _mv_1683 = test_signature_of_fixture(arena, SLOP_STR("corpus/fixtures/hazards/declared-unused-class.ttl"));
    if (!_mv_1683.has_value) {
        return 0;
    } else if (_mv_1683.has_value) {
        __auto_type sig = _mv_1683.value;
        return (owl2_signature_has_class(sig, ((rdf_IRI){.value = vocab_OWL_THING})) && owl2_signature_has_annotation_property(sig, ((rdf_IRI){.value = vocab_RDFS_LABEL})));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_custom_annotation_property_is_recognized(slop_arena* arena) {
    __auto_type _mv_1684 = test_signature_of_fixture(arena, SLOP_STR("corpus/fixtures/hazards/annotation-heavy.ttl"));
    if (!_mv_1684.has_value) {
        return 0;
    } else if (_mv_1684.has_value) {
        __auto_type sig = _mv_1684.value;
        return ((owl2_signature_has_annotation_property(sig, ((rdf_IRI){.value = SLOP_STR("http://example.org/t#curatorNote")}))) && (owl2_signature_has_class(sig, ((rdf_IRI){.value = SLOP_STR("http://example.org/t#A")}))) && (!(owl2_signature_has_class(sig, ((rdf_IRI){.value = SLOP_STR("http://example.org/t#curatorNote")})))));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_is_named_class(owl2_RawConcept c, slop_string iri) {
    __auto_type _mv_1685 = c;
    switch (_mv_1685.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type nd = _mv_1685.data.rc_name;
            __auto_type _mv_1686 = nd;
            switch (_mv_1686.tag) {
                case types_Node_class_node:
                {
                    __auto_type i = _mv_1686.data.class_node;
                    return (canon_string_cmp(i.value, iri) == 0);
                }
                case types_Node_individual_node:
                {
                    __auto_type _ = _mv_1686.data.individual_node;
                    return 0;
                }
                case types_Node_fresh_node:
                {
                    __auto_type _ = _mv_1686.data.fresh_node;
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
    __auto_type _mv_1687 = c;
    switch (_mv_1687.tag) {
        case owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_1687.data.rc_some.f0;
            __auto_type f = _mv_1687.data.rc_some.f1;
            return (({ __auto_type _mv = r; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case types_RoleId_named_role: { __auto_type i = _mv.data.named_role; _mr = (canon_string_cmp(i.value, role_iri) == 0); _mm = 1; break; } case types_RoleId_fresh_role: { _mr = 0; _mm = 1; break; } case types_RoleId_inverse_role: { _mr = 0; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }) && test_is_named_class((*f), filler_iri));
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
        __auto_type _mv_1688 = ttl_parse_ttl_file(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl"));
        if (!_mv_1688.is_ok) {
            __auto_type _ = _mv_1688.data.err;
            return 0;
        } else if (_mv_1688.is_ok) {
            __auto_type g = _mv_1688.data.ok;
            __auto_type _mv_1689 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
            if (!_mv_1689.is_ok) {
                __auto_type _ = _mv_1689.data.err;
                return 0;
            } else if (_mv_1689.is_ok) {
                __auto_type s0 = _mv_1689.data.ok;
                {
                    __auto_type ig = decode_graph_to_indexed(arena, test_stage0_triples(arena, s0));
                    __auto_type parent = rdf_make_iri(arena, SLOP_STR("http://example.org/t#Parent"));
                    __auto_type eq_pred = rdf_make_iri(arena, vocab_OWL_EQUIVALENT_CLASS);
                    __auto_type _mv_1690 = decode_one_object(arena, ig, parent, eq_pred);
                    if (!_mv_1690.is_ok) {
                        __auto_type _ = _mv_1690.data.err;
                        return 0;
                    } else if (_mv_1690.is_ok) {
                        __auto_type defn = _mv_1690.data.ok;
                        __auto_type _mv_1691 = decode_decode_concept(arena, ig, defn, decode_CONCEPT_FUEL);
                        if (!_mv_1691.is_ok) {
                            __auto_type _ = _mv_1691.data.err;
                            return 0;
                        } else if (_mv_1691.is_ok) {
                            __auto_type c = _mv_1691.data.ok;
                            __auto_type _mv_1692 = c;
                            switch (_mv_1692.tag) {
                                case owl2_RawConcept_rc_and:
                                {
                                    __auto_type cs = _mv_1692.data.rc_and;
                                    {
                                        int64_t n = 0;
                                        uint8_t saw_person = 0;
                                        uint8_t saw_some = 0;
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
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, u, c1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, c1, f, ea)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, c1, r, c2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, c2, f, eb)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, c2, r, nil_t)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_1693 = decode_decode_concept(arena, decode_graph_to_indexed(arena, ts), b1, decode_CONCEPT_FUEL);
        if (!_mv_1693.is_ok) {
            __auto_type _ = _mv_1693.data.err;
            return 0;
        } else if (_mv_1693.is_ok) {
            __auto_type c = _mv_1693.data.ok;
            __auto_type _mv_1694 = c;
            switch (_mv_1694.tag) {
                case owl2_RawConcept_rc_or:
                {
                    __auto_type cs = _mv_1694.data.rc_or;
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
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, comp, b1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_1695 = decode_decode_concept(arena, decode_graph_to_indexed(arena, ts), b1, decode_CONCEPT_FUEL);
        if (!_mv_1695.is_ok) {
            __auto_type _ = _mv_1695.data.err;
            return 1;
        } else if (_mv_1695.is_ok) {
            __auto_type _ = _mv_1695.data.ok;
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
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, f, ea)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, r, b2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, f, eb)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, r, b3)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b3, f, ec)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b3, r, nil_t)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_1696 = decode_rdf_list_checked(arena, decode_graph_to_indexed(arena, ts), b1);
        if (!_mv_1696.is_ok) {
            __auto_type _ = _mv_1696.data.err;
            return 0;
        } else if (_mv_1696.is_ok) {
            __auto_type els = _mv_1696.data.ok;
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
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, f, ea)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, r, b2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, r, b3)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b3, f, ec)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b3, r, nil_t)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_1697 = decode_rdf_list_checked(arena, decode_graph_to_indexed(arena, ts), b1);
        if (_mv_1697.is_ok) {
            __auto_type _ = _mv_1697.data.ok;
            return 0;
        } else if (!_mv_1697.is_ok) {
            __auto_type e = _mv_1697.data.err;
            __auto_type _mv_1698 = e;
            switch (_mv_1698.tag) {
                case decode_ListFault_list_truncated:
                {
                    __auto_type _ = _mv_1698.data.list_truncated;
                    return 1;
                }
                case decode_ListFault_list_branching:
                {
                    __auto_type _ = _mv_1698.data.list_branching;
                    return 0;
                }
                case decode_ListFault_list_cyclic:
                {
                    __auto_type _ = _mv_1698.data.list_cyclic;
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
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, f, ea)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, r, b2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, f, eb)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, r, b1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_1699 = decode_rdf_list_checked(arena, decode_graph_to_indexed(arena, ts), b1);
        if (_mv_1699.is_ok) {
            __auto_type _ = _mv_1699.data.ok;
            return 0;
        } else if (!_mv_1699.is_ok) {
            __auto_type e = _mv_1699.data.err;
            __auto_type _mv_1700 = e;
            switch (_mv_1700.tag) {
                case decode_ListFault_list_cyclic:
                {
                    __auto_type _ = _mv_1700.data.list_cyclic;
                    return 1;
                }
                case decode_ListFault_list_truncated:
                {
                    __auto_type _ = _mv_1700.data.list_truncated;
                    return 0;
                }
                case decode_ListFault_list_branching:
                {
                    __auto_type _ = _mv_1700.data.list_branching;
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
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, f, ea)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, f, eb)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, r, nil_t)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return (test_list_branches(arena, ts, b1) && test_list_branches(arena, test_rest_forked(arena), b1));
    }
}

slop_list_rdf_Triple test_rest_forked(slop_arena* arena) {
    {
        __auto_type b1 = rdf_make_blank(arena, 1);
        __auto_type b2 = rdf_make_blank(arena, 2);
        __auto_type nil_t = rdf_make_iri(arena, vocab_RDF_NIL);
        __auto_type f = rdf_make_iri(arena, vocab_RDF_FIRST);
        __auto_type r = rdf_make_iri(arena, vocab_RDF_REST);
        __auto_type ts = ((slop_list_rdf_Triple){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, f, test_ex_iri(arena, SLOP_STR("A")))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, r, nil_t)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, r, b2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, f, test_ex_iri(arena, SLOP_STR("B")))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, r, nil_t)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ts;
    }
}

uint8_t test_list_branches(slop_arena* arena, slop_list_rdf_Triple ts, rdf_Term head) {
    __auto_type _mv_1701 = decode_rdf_list_checked(arena, decode_graph_to_indexed(arena, ts), head);
    if (_mv_1701.is_ok) {
        __auto_type _ = _mv_1701.data.ok;
        return 0;
    } else if (!_mv_1701.is_ok) {
        __auto_type e = _mv_1701.data.err;
        __auto_type _mv_1702 = e;
        switch (_mv_1702.tag) {
            case decode_ListFault_list_branching:
            {
                __auto_type _ = _mv_1702.data.list_branching;
                return 1;
            }
            case decode_ListFault_list_truncated:
            {
                __auto_type _ = _mv_1702.data.list_truncated;
                return 0;
            }
            case decode_ListFault_list_cyclic:
            {
                __auto_type _ = _mv_1702.data.list_cyclic;
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_string test_decode_prefix(void) {
    return SLOP_STR("@prefix : <http://example.org/t#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .\n:A a owl:Class . :r a owl:ObjectProperty . :s a owl:ObjectProperty .\n:d a owl:DatatypeProperty . :d2 a owl:DatatypeProperty .\n:a a owl:NamedIndividual . :b a owl:NamedIndividual .\n");
}

slop_string test_decoded_text(slop_arena* arena, slop_string ttl) {
    __auto_type _mv_1703 = ttl_parse_ttl_string(arena, ttl);
    if (!_mv_1703.is_ok) {
        __auto_type _ = _mv_1703.data.err;
        return SLOP_STR("<did not parse>");
    } else if (_mv_1703.is_ok) {
        __auto_type g = _mv_1703.data.ok;
        __auto_type _mv_1704 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        if (!_mv_1704.is_ok) {
            __auto_type _ = _mv_1704.data.err;
            return SLOP_STR("<stage 0 faulted>");
        } else if (_mv_1704.is_ok) {
            __auto_type s0 = _mv_1704.data.ok;
            {
                __auto_type out = SLOP_STR("");
                {
                    __auto_type _coll = test_decode_rendered(arena, decode_decode_axioms(arena, s0.dict, s0.triples));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type l = _coll.data[_i];
                        if (!(strlib_starts_with(l, SLOP_STR("Declaration(")))) {
                            out = string_concat(arena, out, string_concat(arena, l, SLOP_STR("\n")));
                        }
                    }
                }
                return out;
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_decodes_exactly(slop_arena* arena, slop_string label, slop_string ttl, slop_string want) {
    {
        __auto_type got = test_decoded_text(arena, string_concat(arena, test_decode_prefix(), ttl));
        if (string_eq(got, want)) {
            return 1;
        } else {
            printf("%.*s\n", (int)(string_concat(arena, string_concat(arena, SLOP_STR("  [decode row] "), label), SLOP_STR(": decoded"))).len, (string_concat(arena, string_concat(arena, SLOP_STR("  [decode row] "), label), SLOP_STR(": decoded"))).data);
            printf("%.*s\n", (int)(got).len, (got).data);
            return 0;
        }
    }
}

uint8_t test_test_decode_rows(slop_arena* arena) {
    return ((test_decodes_exactly(arena, SLOP_STR("n-ary data restriction"), SLOP_STR(":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperties ( :d :d2 ) ; owl:allValuesFrom xsd:string ] ."), SLOP_STR("ReservedVocabulary(_:b0 <http://www.w3.org/2002/07/owl#onProperties> _:b1 .)\nSubClassOf(http://example.org/t#A DataRange(DataAllValuesFrom(onProperties(http://example.org/t#d http://example.org/t#d2) http://www.w3.org/2001/XMLSchema#string)))\n"))) && (test_decodes_exactly(arena, SLOP_STR("AllDisjointProperties over data properties"), SLOP_STR("[ a owl:AllDisjointProperties ; owl:members ( :d :d2 ) ] ."), SLOP_STR("DataAxiom(_:b0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://www.w3.org/2002/07/owl#AllDisjointProperties> .)\n"))) && (test_decodes_exactly(arena, SLOP_STR("negative assertion on a data property, individual target"), SLOP_STR("[ a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; owl:assertionProperty :d ; owl:targetIndividual :b ] ."), SLOP_STR("DataAxiom(_:b0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://www.w3.org/2002/07/owl#NegativePropertyAssertion> .)\n"))) && (test_decodes_exactly(arena, SLOP_STR("chain on a blank subject"), SLOP_STR("_:p owl:propertyChainAxiom ( :r :s ) ."), SLOP_STR("owl:propertyChainAxiom on a non-IRI subject\n"))) && (test_decodes_exactly(arena, SLOP_STR("reserved source of an assertion"), SLOP_STR("owl:Thing :r :b ."), SLOP_STR("ReservedVocabulary(<http://www.w3.org/2002/07/owl#Thing> <http://example.org/t#r> <http://example.org/t#b> .)\n"))) && (test_decodes_exactly(arena, SLOP_STR("the last fault wins"), SLOP_STR("_:p rdfs:domain :A . :r owl:inverseOf _:q ."), SLOP_STR("owl:inverseOf with a non-IRI object\n"))) && (test_decodes_exactly(arena, SLOP_STR("a use climbs every level of the data hierarchy"), SLOP_STR(":d3 a owl:DatatypeProperty . :d2 rdfs:subPropertyOf :d3 . :d rdfs:subPropertyOf :d2 . :d3 rdfs:domain :A . :a :d \"x\" ."), SLOP_STR("DataAxiom(<http://example.org/t#d2> <http://www.w3.org/2000/01/rdf-schema#subPropertyOf> <http://example.org/t#d3> .)\nDataAxiom(<http://example.org/t#d> <http://www.w3.org/2000/01/rdf-schema#subPropertyOf> <http://example.org/t#d2> .)\nDataAxiom(<http://example.org/t#d3> <http://www.w3.org/2000/01/rdf-schema#domain> <http://example.org/t#A> .)\nDataAxiom(<http://example.org/t#a> <http://example.org/t#d> \"x\" .)\n"))) && (test_decodes_exactly(arena, SLOP_STR("an equivalence carries a use both ways"), SLOP_STR(":d owl:equivalentProperty :d2 . :d rdfs:domain :A . :a :d2 \"x\" ."), SLOP_STR("DataAxiom(<http://example.org/t#d> <http://www.w3.org/2002/07/owl#equivalentProperty> <http://example.org/t#d2> .)\nDataAxiom(<http://example.org/t#d> <http://www.w3.org/2000/01/rdf-schema#domain> <http://example.org/t#A> .)\nDataAxiom(<http://example.org/t#a> <http://example.org/t#d2> \"x\" .)\n"))) && (test_decodes_exactly(arena, SLOP_STR("an unused bottom data property is idle"), SLOP_STR("owl:bottomDataProperty rdfs:domain :A ."), SLOP_STR(""))));
}

uint8_t test_test_sort_is_stable(slop_arena* arena) {
    {
        __auto_type idx = canon_sort_range(arena, 9, (slop_closure_t){(void*)test__lambda_1705, NULL});
        __auto_type expect = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t ok = 1;
        int64_t i = 0;
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (6); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (7); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (8); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (3); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (4); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (5); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (1); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (2); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        __auto_type xs = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (test_mk_iri(SLOP_STR("b"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (test_mk_iri(SLOP_STR("a"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (test_mk_iri(SLOP_STR("b"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (test_mk_iri(SLOP_STR("c"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (test_mk_iri(SLOP_STR("a"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

slop_string test_arg_text(uint8_t** argv, int64_t i) {
    {
        __auto_type ptr = argv[i];
        return (slop_string){.len = strlen(ptr), .data = ptr};
    }
}

slop_list_rdf_IRI test_dump_classes(slop_arena* arena, owl2_Signature sig) {
    {
        __auto_type out = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.classes); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!((string_eq(c.value, vocab_OWL_THING) || string_eq(c.value, vocab_OWL_NOTHING)))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return canon_sort_iris(arena, out);
    }
}

int64_t test_print_lines(slop_list_string ls) {
    {
        __auto_type _coll = ls;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type l = _coll.data[_i];
            printf("%.*s\n", (int)(l).len, (l).data);
        }
    }
    return 0;
}

int64_t test_dump_refused(slop_string m) {
    printf("%s", "refused: ");
    printf("%.*s\n", (int)(m).len, (m).data);
    return 2;
}

int64_t test_dump_s1(slop_arena* arena, gate_GateResult gr, slop_result_sriqnormal_S0_string r, int64_t bound) {
    __auto_type _mv_1706 = r;
    if (!_mv_1706.is_ok) {
        __auto_type m = _mv_1706.data.err;
        return test_dump_refused(m);
    } else if (_mv_1706.is_ok) {
        __auto_type s0 = _mv_1706.data.ok;
        __auto_type _mv_1707 = sriqelim_sriq_s1(arena, s0, bound);
        if (!_mv_1707.is_ok) {
            __auto_type m = _mv_1707.data.err;
            return test_dump_refused(m);
        } else if (_mv_1707.is_ok) {
            __auto_type s1 = _mv_1707.data.ok;
            return test_print_lines(sroiqfss_fss_axioms(arena, test_dump_classes(arena, gr.signature), s1.axioms));
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

int64_t test_dump_s1_invariants(slop_arena* arena, gate_GateResult gr, int64_t bound) {
    __auto_type _mv_1708 = sriqnormal_sriq_s0(arena, gr.accepted);
    if (!_mv_1708.is_ok) {
        __auto_type m = _mv_1708.data.err;
        return test_dump_refused(m);
    } else if (_mv_1708.is_ok) {
        __auto_type s0 = _mv_1708.data.ok;
        __auto_type _mv_1709 = sriqelim_sriq_s1(arena, s0, bound);
        if (!_mv_1709.is_ok) {
            __auto_type m = _mv_1709.data.err;
            return test_dump_refused(m);
        } else if (_mv_1709.is_ok) {
            __auto_type s1 = _mv_1709.data.ok;
            {
                __auto_type bad = sriqelim_sriq_s1_invariants(arena, s0.rbox, s0.axioms, s1);
                {
                    __auto_type _coll = bad;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type b = _coll.data[_i];
                        printf("%.*s\n", (int)(b).len, (b).data);
                    }
                }
                if (((int64_t)((bad).len)) == 0) {
                    printf("%s\n", "ok");
                    return 0;
                } else {
                    return 1;
                }
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_s1_guarded(slop_arena* arena, gate_GateResult gr, int64_t bound) {
    __auto_type _mv_1710 = sriqnormal_sriq_s0(arena, gr.accepted);
    if (!_mv_1710.is_ok) {
        __auto_type _ = _mv_1710.data.err;
        return 0;
    } else if (_mv_1710.is_ok) {
        __auto_type s0 = _mv_1710.data.ok;
        __auto_type _mv_1711 = sriqelim_sriq_s1(arena, s0, bound);
        if (!_mv_1711.is_ok) {
            __auto_type _ = _mv_1711.data.err;
            return 0;
        } else if (_mv_1711.is_ok) {
            __auto_type s1 = _mv_1711.data.ok;
            return (((int64_t)((s1.omitted).len)) > 0);
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_uses_reserved(slop_arena* arena, owl2_Signature sig) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.classes); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (strlib_starts_with(c.value, SLOP_STR("urn:howl:"))) {
                    found = 1;
                }
            }
        }
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.obj_props); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                if (strlib_starts_with(r.value, SLOP_STR("urn:howl:"))) {
                    found = 1;
                }
            }
        }
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.individuals); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                if (strlib_starts_with(i.value, SLOP_STR("urn:howl:"))) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

int64_t test_clauses_report(slop_arena* arena, sriqclauses_SriqClauses sc) {
    {
        __auto_type bad = sriqclauses_ids_dense(arena, sc);
        int64_t shape = 0;
        {
            __auto_type _coll = sc.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!((sriqclauses_dl_clause_shape(c) && sriqclauses_clause_canonical(c)))) {
                    shape = (shape + 1);
                }
            }
        }
        {
            __auto_type _coll = bad;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                printf("%s", "FAILED ");
                printf("%.*s\n", (int)(b).len, (b).data);
            }
        }
        if (shape > 0) {
            printf("%s", "FAILED not canonical DL-clauses: ");
            printf("%.*s\n", (int)(int_to_string(arena, shape)).len, (int_to_string(arena, shape)).data);
        }
        if ((((int64_t)((bad).len)) == 0) && (shape == 0)) {
            printf("%s", "ok ");
            printf("%.*s\n", (int)(int_to_string(arena, ((int64_t)(((int64_t)((sc.clauses).len)))))).len, (int_to_string(arena, ((int64_t)(((int64_t)((sc.clauses).len)))))).data);
            return 0;
        } else {
            return 1;
        }
    }
}

int64_t test_clauses_check(slop_arena* arena, slop_result_sriqnames_SriqNormal_string r) {
    __auto_type _mv_1712 = r;
    if (!_mv_1712.is_ok) {
        __auto_type m = _mv_1712.data.err;
        return test_dump_refused(m);
    } else if (_mv_1712.is_ok) {
        __auto_type n = _mv_1712.data.ok;
        __auto_type _mv_1713 = sriqclauses_sriq_clauses(arena, n);
        if (!_mv_1713.is_ok) {
            __auto_type m = _mv_1713.data.err;
            printf("%s", "FAILED ");
            printf("%.*s\n", (int)(m).len, (m).data);
            return 1;
        } else if (_mv_1713.is_ok) {
            __auto_type sc = _mv_1713.data.ok;
            return test_clauses_report(arena, sc);
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

int64_t test_dump_stage(slop_arena* arena, slop_string stage, gate_GateResult gr, int64_t bound) {
    if (!(string_eq(stage, SLOP_STR("info"))) && test_uses_reserved(arena, gr.signature)) {
        return test_dump_refused(SLOP_STR("reserved: the input names something under urn:howl:, which the dump uses for HOWL's own names"));
    } else if (string_eq(stage, SLOP_STR("info"))) {
        printf("%s", "omitted ");
        printf("%.*s\n", (int)(int_to_string(arena, ((int64_t)(((int64_t)((gr.omissions).len)))))).len, (int_to_string(arena, ((int64_t)(((int64_t)((gr.omissions).len)))))).data);
        printf("%s", "accepted ");
        printf("%.*s\n", (int)(int_to_string(arena, ((int64_t)(((int64_t)((gr.accepted).len)))))).len, (int_to_string(arena, ((int64_t)(((int64_t)((gr.accepted).len)))))).data);
        if (test_s1_guarded(arena, gr, bound)) {
            printf("%s\n", "s1-guarded yes");
        }
        {
            __auto_type _coll = test_dump_classes(arena, gr.signature);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                printf("%s", "class ");
                printf("%.*s\n", (int)(c.value).len, (c.value).data);
            }
        }
        return 0;
    } else if (string_eq(stage, SLOP_STR("s0"))) {
        __auto_type _mv_1714 = sriqnormal_sriq_s0(arena, gr.accepted);
        if (!_mv_1714.is_ok) {
            __auto_type m = _mv_1714.data.err;
            return test_dump_refused(m);
        } else if (_mv_1714.is_ok) {
            __auto_type s0 = _mv_1714.data.ok;
            return test_print_lines(sroiqfss_fss_axioms(arena, test_dump_classes(arena, gr.signature), s0.axioms));
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(stage, SLOP_STR("s1"))) {
        return test_dump_s1(arena, gr, sriqnormal_sriq_s0(arena, gr.accepted), bound);
    } else if (string_eq(stage, SLOP_STR("s1-invariants"))) {
        return test_dump_s1_invariants(arena, gr, bound);
    } else if (string_eq(stage, SLOP_STR("s2"))) {
        __auto_type _mv_1715 = sriqnames_sriq_normalize_bounded(arena, gr.accepted, gr.signature, bound);
        if (!_mv_1715.is_ok) {
            __auto_type m = _mv_1715.data.err;
            return test_dump_refused(m);
        } else if (_mv_1715.is_ok) {
            __auto_type n = _mv_1715.data.ok;
            return test_print_lines(sroiqfss_fss_normal(arena, n));
        }
        SLOP_UNREACHABLE();
    } else if (string_eq(stage, SLOP_STR("clauses"))) {
        return test_print_lines(test_clause_lines(arena, sriqnames_sriq_normalize_bounded(arena, gr.accepted, gr.signature, bound)));
    } else if (string_eq(stage, SLOP_STR("clauses-check"))) {
        return test_clauses_check(arena, sriqnames_sriq_normalize_bounded(arena, gr.accepted, gr.signature, bound));
    } else {
        return test_dump_refused(SLOP_STR("the stages are info, s0, s1, s1-invariants, s2, clauses and clauses-check"));
    }
}

int64_t test_sriq_dump(slop_arena* arena, slop_string stage, slop_string path, int64_t bound) {
    __auto_type _mv_1716 = test_gate_fixture_in(arena, path, types_Profile_profile_sriq);
    if (!_mv_1716.has_value) {
        return test_dump_refused(SLOP_STR("the file did not parse or gate"));
    } else if (_mv_1716.has_value) {
        __auto_type gr = _mv_1716.value;
        return test_dump_stage(arena, stage, gr, bound);
    }
    SLOP_UNREACHABLE();
}

int64_t test_bound_arg(slop_string s) {
    {
        uint8_t ok = ((string_len(s) > 0) && (string_len(s) <= 9));
        int64_t i = 0;
        while (ok && (i < string_len(s))) {
            if (!(strlib_is_digit(strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at test.slop:8514:47"))))) {
                ok = 0;
            }
            i = (i + 1);
        }
        if (!(ok)) {
            return -1;
        } else {
            __auto_type _mv_1717 = strlib_parse_int(s);
            if (_mv_1717.is_ok) {
                __auto_type n = _mv_1717.data.ok;
                return ((int64_t)(n));
            } else if (!_mv_1717.is_ok) {
                __auto_type _ = _mv_1717.data.err;
                return -1;
            }
            SLOP_UNREACHABLE();
        }
    }
}

int64_t test_dump_tagged(slop_string tag, slop_string text) {
    printf("%.*s", (int)(tag).len, (tag).data);
    printf("%.*s\n", (int)(text).len, (text).data);
    return 0;
}

int64_t test_dump_axiom_list(slop_arena* arena, slop_string tag, slop_list_owl2_RawAxiom axs) {
    {
        __auto_type _coll = axs;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type ax = _coll.data[_i];
            test_dump_tagged(tag, owl2_render_axiom(arena, ax));
        }
    }
    return 0;
}

int64_t test_dump_axiom_ref(slop_string tag, types_AxiomRef r) {
    __auto_type _mv_1718 = r.source;
    if (_mv_1718.has_value) {
        __auto_type i = _mv_1718.value;
        test_dump_tagged(tag, r.text);
        return test_dump_tagged(SLOP_STR("  from "), i.value);
    } else if (!_mv_1718.has_value) {
        return test_dump_tagged(tag, r.text);
    }
    SLOP_UNREACHABLE();
}

int64_t test_dump_cited(slop_string tag, types_Omission o) {
    __auto_type _mv_1719 = o;
    switch (_mv_1719.tag) {
        case types_Omission_missing_declaration:
        {
            __auto_type md = _mv_1719.data.missing_declaration;
            {
                __auto_type _coll = md.referring;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type r = _coll.data[_i];
                    test_dump_axiom_ref(tag, r);
                }
            }
            return 0;
        }
        default: {
            return 0;
        }
    }
}

int64_t test_dump_omission_list(slop_arena* arena, slop_string tag, slop_list_types_Omission os) {
    {
        __auto_type cites = string_concat(arena, tag, SLOP_STR("cites "));
        {
            __auto_type _coll = os;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                test_dump_tagged(tag, owl2_render_omission(arena, o));
                test_dump_cited(cites, o);
            }
        }
        return 0;
    }
}

int64_t test_dump_fault(slop_arena* arena, types_Fault f) {
    __auto_type _mv_1720 = f;
    switch (_mv_1720.tag) {
        case types_Fault_input_error:
        {
            __auto_type m = _mv_1720.data.input_error;
            test_dump_tagged(SLOP_STR("fault input-error "), m);
            return 1;
        }
        case types_Fault_refused:
        {
            __auto_type os = _mv_1720.data.refused;
            test_dump_omission_list(arena, SLOP_STR("fault refused "), os);
            return 1;
        }
        case types_Fault_cancelled:
        {
            printf("%s\n", "fault cancelled");
            return 1;
        }
        case types_Fault_unavailable:
        {
            __auto_type _ = _mv_1720.data.unavailable;
            printf("%s\n", "fault unavailable");
            return 1;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t test_dump_signature(slop_arena* arena, owl2_Signature sig) {
    {
        __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.classes); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type x = _coll.data[_i];
            test_dump_tagged(SLOP_STR("sig class "), x.value);
        }
    }
    {
        __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.obj_props); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type x = _coll.data[_i];
            test_dump_tagged(SLOP_STR("sig obj-prop "), x.value);
        }
    }
    {
        __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.data_props); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type x = _coll.data[_i];
            test_dump_tagged(SLOP_STR("sig data-prop "), x.value);
        }
    }
    {
        __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.annot_props); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type x = _coll.data[_i];
            test_dump_tagged(SLOP_STR("sig annot-prop "), x.value);
        }
    }
    {
        __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.individuals); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type x = _coll.data[_i];
            test_dump_tagged(SLOP_STR("sig individual "), x.value);
        }
    }
    {
        __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.datatypes); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type x = _coll.data[_i];
            test_dump_tagged(SLOP_STR("sig datatype "), x.value);
        }
    }
    return 0;
}

int64_t test_dump_triple(slop_arena* arena, termstore_IdTriple t) {
    printf("%s", "triple ");
    printf("%.*s", (int)(int_to_string(arena, t.s)).len, (int_to_string(arena, t.s)).data);
    printf("%s", " ");
    printf("%.*s", (int)(int_to_string(arena, t.p)).len, (int_to_string(arena, t.p)).data);
    printf("%s", " ");
    printf("%.*s\n", (int)(int_to_string(arena, t.o)).len, (int_to_string(arena, t.o)).data);
    return 0;
}

int64_t test_dump_stage0(slop_arena* arena, decode_Stage0 s0) {
    {
        __auto_type _coll = s0.triples;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type t = _coll.data[_i];
            test_dump_triple(arena, t);
        }
    }
    {
        __auto_type _coll = s0.imports_declared;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type i = _coll.data[_i];
            test_dump_tagged(SLOP_STR("import "), i.value);
        }
    }
    return test_dump_omission_list(arena, SLOP_STR("stage0 omitted "), s0.omissions);
}

int64_t test_dump_regularity(slop_arena* arena, slop_list_owl2_RawAxiom axs) {
    __auto_type _mv_1721 = gate_check_regularity(arena, gate_expand_sugar(arena, axs));
    switch (_mv_1721.tag) {
        case gate_RboxVerdict_rbox_regular:
        {
            printf("%s\n", "regularity regular");
            return 0;
        }
        case gate_RboxVerdict_rbox_irregular:
        {
            __auto_type m = _mv_1721.data.rbox_irregular;
            return test_dump_tagged(SLOP_STR("regularity irregular "), m);
        }
    }
    SLOP_UNREACHABLE();
}

int64_t test_dump_rung(slop_arena* arena, decode_Stage0 s0, decode_Stage1 s1, types_Profile p, slop_string tag) {
    {
        __auto_type expanded = gate_drop_top_role_tautologies(arena, p, gate_expand_negation(arena, p, gate_expand_sugar(arena, s1.axioms)));
        __auto_type gr = gate_gate_axioms(arena, s1.axioms, s1.signature, s0.omissions, p);
        __auto_type missing = gate_missing_declarations(arena, s1.signature, gate_collect_entity_refs(arena, gr.accepted));
        test_dump_axiom_list(arena, string_concat(arena, tag, SLOP_STR(" expanded ")), expanded);
        test_dump_axiom_list(arena, string_concat(arena, tag, SLOP_STR(" accepted ")), gr.accepted);
        test_dump_omission_list(arena, string_concat(arena, tag, SLOP_STR(" omitted ")), gr.omissions);
        return test_dump_omission_list(arena, string_concat(arena, tag, SLOP_STR(" missing ")), missing);
    }
}

int64_t test_dump_decoded(slop_arena* arena, decode_Stage0 s0, decode_Stage1 s1) {
    test_dump_axiom_list(arena, SLOP_STR("decoded "), s1.axioms);
    test_dump_tagged(SLOP_STR("inert "), int_to_string(arena, s1.inert));
    test_dump_signature(arena, s1.signature);
    test_dump_regularity(arena, s1.axioms);
    test_dump_rung(arena, s0, s1, types_Profile_profile_el, SLOP_STR("el"));
    test_dump_rung(arena, s0, s1, types_Profile_profile_el_plus_plus, SLOP_STR("el++"));
    return test_dump_rung(arena, s0, s1, types_Profile_profile_sriq, SLOP_STR("sriq"));
}

int64_t test_front_dump(slop_arena* arena, slop_string path) {
    __auto_type _mv_1722 = ttl_parse_ttl_file(arena, path);
    if (!_mv_1722.is_ok) {
        __auto_type _ = _mv_1722.data.err;
        printf("%s\n", "parse error");
        return 1;
    } else if (_mv_1722.is_ok) {
        __auto_type g = _mv_1722.data.ok;
        __auto_type _mv_1723 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        if (!_mv_1723.is_ok) {
            __auto_type f = _mv_1723.data.err;
            return test_dump_fault(arena, f);
        } else if (_mv_1723.is_ok) {
            __auto_type s0 = _mv_1723.data.ok;
            test_dump_stage0(arena, s0);
            __auto_type _mv_1724 = decode_decode_axioms(arena, s0.dict, s0.triples);
            if (!_mv_1724.is_ok) {
                __auto_type f = _mv_1724.data.err;
                return test_dump_fault(arena, f);
            } else if (_mv_1724.is_ok) {
                __auto_type s1 = _mv_1724.data.ok;
                return test_dump_decoded(arena, s0, s1);
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_string test_yes_no(uint8_t b) {
    if (b) {
        return SLOP_STR("yes");
    } else {
        return SLOP_STR("no");
    }
}

int64_t test_dump_num(slop_arena* arena, slop_string tag, int64_t n) {
    printf("%.*s", (int)(tag).len, (tag).data);
    printf("%.*s", (int)(int_to_string(arena, n)).len, (int_to_string(arena, n)).data);
    return 0;
}

int64_t test_dump_flag(slop_string tag, uint8_t b) {
    printf("%.*s", (int)(tag).len, (tag).data);
    printf("%.*s", (int)(test_yes_no(b)).len, (test_yes_no(b)).data);
    return 0;
}

int64_t test_dump_cfact(slop_arena* arena, kscids_CFact c) {
    test_dump_num(arena, SLOP_STR("  fact "), ((int64_t)(c.kind)));
    test_dump_num(arena, SLOP_STR(" "), ((int64_t)(c.a)));
    test_dump_num(arena, SLOP_STR(" "), ((int64_t)(c.b)));
    test_dump_num(arena, SLOP_STR(" "), ((int64_t)(c.c)));
    printf("%s\n", "");
    return 0;
}

int64_t test_dump_ksc_run(slop_arena* arena, slop_string tag, kscsat_RunResult r) {
    printf("%.*s", (int)(tag).len, (tag).data);
    test_dump_num(arena, SLOP_STR(" rounds "), r.rounds);
    test_dump_num(arena, SLOP_STR(" facts "), r.facts);
    test_dump_flag(SLOP_STR(" unsat "), r.unsat);
    test_dump_flag(SLOP_STR(" capped "), r.capped);
    test_dump_flag(SLOP_STR(" cancelled "), r.cancelled);
    printf("%s\n", "");
    {
        __auto_type _coll = kscsat_store_facts(arena, r.store);
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type c = _coll.data[_i];
            test_dump_cfact(arena, c);
        }
    }
    return 0;
}

slop_list_types_KFact test_ksc_seeds(slop_arena* arena, kscpremise_KscIndex idx, slop_list_types_KName classes, uint8_t w_phase) {
    {
        __auto_type seeds = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx.individuals;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(seeds); __auto_type _item = (ksc_ksc_1(a).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        if (w_phase) {
            ({ __auto_type _lst_p = &(seeds); __auto_type _item = (ksc_ksc_q(((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = vocab_OWL_THING}) })).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            {
                __auto_type _coll = classes;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type q = _coll.data[_i];
                    ({ __auto_type _lst_p = &(seeds); __auto_type _item = (ksc_ksc_q(q).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return seeds;
    }
}

int64_t test_dump_ksc_phases(slop_arena* arena, kscpremise_KscIndex idx, kscids_KscIds ids, slop_list_types_KName classes, int64_t w) {
    {
        __auto_type cas = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        if (w > 1) {
            while (k < w) {
                ({ __auto_type _lst_p = &(cas); __auto_type _item = (({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(4096); _new_arena; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                k = (k + 1);
            }
        }
        test_dump_ksc_run(arena, string_concat(arena, SLOP_STR("G w="), int_to_string(arena, w)), kscsat_run_ksc(arena, idx, ids, ((slop_option_kscsat_Base){.has_value = false}), test_ksc_seeds(arena, idx, classes, 0), 1, 10000, 0, w, cas));
        test_dump_ksc_run(arena, string_concat(arena, SLOP_STR("W w="), int_to_string(arena, w)), kscsat_run_ksc(arena, idx, ids, ((slop_option_kscsat_Base){.has_value = false}), test_ksc_seeds(arena, idx, classes, 1), 0, 10000, 0, w, cas));
        {
            __auto_type _coll = cas;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ slop_arena_free(a); free(a); });
            }
        }
        return 0;
    }
}

int64_t test_dump_answer(slop_arena* arena, types_ClassAnswer a) {
    printf("%s", "  answer ");
    printf("%.*s", (int)(test_kname_label(arena, a.cls)).len, (test_kname_label(arena, a.cls)).data);
    test_dump_flag(SLOP_STR(" shared "), a.shared);
    test_dump_flag(SLOP_STR(" unsat "), a.unsat);
    test_dump_flag(SLOP_STR(" complete "), a.complete);
    test_dump_num(arena, SLOP_STR(" rounds "), a.rounds);
    test_dump_num(arena, SLOP_STR(" facts "), a.facts);
    printf("%s\n", "");
    {
        __auto_type _coll = a.subsumers;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type s = _coll.data[_i];
            printf("%s", "    sub ");
            printf("%.*s\n", (int)(test_kname_label(arena, s)).len, (test_kname_label(arena, s)).data);
        }
    }
    return 0;
}

int64_t test_dump_ksc_result(slop_arena* arena, types_KscResult r) {
    test_dump_flag(SLOP_STR("  inconsistent "), r.inconsistent);
    test_dump_num(arena, SLOP_STR(" rounds "), r.rounds);
    test_dump_num(arena, SLOP_STR(" g "), r.g_rounds);
    test_dump_num(arena, SLOP_STR("/"), r.g_facts);
    test_dump_num(arena, SLOP_STR(" w "), r.w_rounds);
    test_dump_num(arena, SLOP_STR("/"), r.w_facts);
    test_dump_num(arena, SLOP_STR(" unsafe "), r.unsafe_count);
    __auto_type _mv_1725 = r.termination;
    switch (_mv_1725.tag) {
        case types_Termination_fixpoint:
        {
            printf("%s\n", " fixpoint");
            break;
        }
        case types_Termination_resource_limit:
        {
            __auto_type n = _mv_1725.data.resource_limit;
            test_dump_num(arena, SLOP_STR(" resource-limit "), n);
            printf("%s\n", "");
            break;
        }
    }
    {
        __auto_type _coll = r.answers;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type a = _coll.data[_i];
            test_dump_answer(arena, a);
        }
    }
    return 0;
}

int64_t test_dump_ksc_classify(slop_arena* arena, test_KscFixture fx, int64_t w, int64_t cap) {
    {
        __auto_type cfg = types_default_config();
        cfg.worker_count = ((uint8_t)(SLOP_RANGE(uint8_t, w, 1, 1, 1, 64, "(Int 1 .. 64) at test.slop:8781:52")));
        cfg.max_iterations = ((uint16_t)(SLOP_RANGE(uint16_t, cap, 1, 1, 0, 10000, "(Int 0 .. 10000) at test.slop:8782:57")));
        test_dump_num(arena, SLOP_STR("classify w="), w);
        test_dump_num(arena, SLOP_STR(" cap "), cap);
        printf("%s\n", "");
        __auto_type _mv_1726 = kscsat_ksc_classify(arena, fx.axioms, fx.classes, cfg);
        if (!_mv_1726.is_ok) {
            __auto_type f = _mv_1726.data.err;
            return test_dump_fault(arena, f);
        } else if (_mv_1726.is_ok) {
            __auto_type r = _mv_1726.data.ok;
            return test_dump_ksc_result(arena, r);
        }
        SLOP_UNREACHABLE();
    }
}

int64_t test_dump_ksc_caps(slop_arena* arena, test_KscFixture fx, int64_t w) {
    test_dump_ksc_classify(arena, fx, w, 1000);
    test_dump_ksc_classify(arena, fx, w, 0);
    test_dump_ksc_classify(arena, fx, w, 1);
    test_dump_ksc_classify(arena, fx, w, 2);
    return test_dump_ksc_classify(arena, fx, w, 3);
}

int64_t test_ksc_dump(slop_arena* arena, slop_string path) {
    __auto_type _mv_1727 = test_gate_fixture_in(arena, path, types_Profile_profile_el_plus_plus);
    if (!_mv_1727.has_value) {
        printf("%s\n", "did not gate");
        return 1;
    } else if (_mv_1727.has_value) {
        __auto_type gr = _mv_1727.value;
        {
            __auto_type fx = ((test_KscFixture){.axioms = kscnormal_normalize_ksc(arena, gr.accepted).axioms, .classes = kscsat_input_classes(arena, gr.signature)});
            __auto_type idx = kscpremise_build_ksc_index(arena, fx.axioms);
            __auto_type ids = kscids_build_ksc_ids(arena, fx.axioms, fx.classes, idx.individuals);
            test_dump_ksc_phases(arena, idx, ids, fx.classes, 1);
            test_dump_ksc_phases(arena, idx, ids, fx.classes, 4);
            test_dump_ksc_caps(arena, fx, 1);
            return test_dump_ksc_caps(arena, fx, 4);
        }
    }
    SLOP_UNREACHABLE();
}

int main(int argc, char** _c_argv) {
    uint8_t** argv = (uint8_t**)_c_argv;
    if (argc == 1) {
        return test_run_suite();
    } else if ((argc == 4) && string_eq(test_arg_text(argv, 1), SLOP_STR("sriq-dump"))) {
        {
            #ifdef SLOP_DEBUG
            SLOP_PRE((4194304) > 0, "with-arena size must be positive");
            #endif
            slop_arena _arena_4 = slop_arena_new(4194304);
            #ifdef SLOP_DEBUG
            SLOP_PRE(_arena_4.base != NULL, "arena allocation failed");
            #endif
            slop_arena* arena = &_arena_4;
            {
                int _wa_ret = test_sriq_dump(arena, test_arg_text(argv, 2), test_arg_text(argv, 3), sriqelim_S1_BOUND);
                slop_arena_free(&_arena_4);
                return _wa_ret;
            }
            slop_arena_free(arena);
        }
    } else if ((argc == 5) && string_eq(test_arg_text(argv, 1), SLOP_STR("sriq-dump"))) {
        {
            __auto_type b = test_bound_arg(test_arg_text(argv, 4));
            if (b < 0) {
                printf("%s\n", "the bound is a whole number");
                return 2;
            } else {
                {
                    #ifdef SLOP_DEBUG
                    SLOP_PRE((4194304) > 0, "with-arena size must be positive");
                    #endif
                    slop_arena _arena_5 = slop_arena_new(4194304);
                    #ifdef SLOP_DEBUG
                    SLOP_PRE(_arena_5.base != NULL, "arena allocation failed");
                    #endif
                    slop_arena* arena = &_arena_5;
                    {
                        int _wa_ret = test_sriq_dump(arena, test_arg_text(argv, 2), test_arg_text(argv, 3), b);
                        slop_arena_free(&_arena_5);
                        return _wa_ret;
                    }
                    slop_arena_free(arena);
                }
            }
        }
    } else if ((argc == 3) && string_eq(test_arg_text(argv, 1), SLOP_STR("front-dump"))) {
        {
            #ifdef SLOP_DEBUG
            SLOP_PRE((4194304) > 0, "with-arena size must be positive");
            #endif
            slop_arena _arena_6 = slop_arena_new(4194304);
            #ifdef SLOP_DEBUG
            SLOP_PRE(_arena_6.base != NULL, "arena allocation failed");
            #endif
            slop_arena* arena = &_arena_6;
            {
                int _wa_ret = test_front_dump(arena, test_arg_text(argv, 2));
                slop_arena_free(&_arena_6);
                return _wa_ret;
            }
            slop_arena_free(arena);
        }
    } else if ((argc == 3) && string_eq(test_arg_text(argv, 1), SLOP_STR("ksc-dump"))) {
        {
            #ifdef SLOP_DEBUG
            SLOP_PRE((4194304) > 0, "with-arena size must be positive");
            #endif
            slop_arena _arena_7 = slop_arena_new(4194304);
            #ifdef SLOP_DEBUG
            SLOP_PRE(_arena_7.base != NULL, "arena allocation failed");
            #endif
            slop_arena* arena = &_arena_7;
            {
                int _wa_ret = test_ksc_dump(arena, test_arg_text(argv, 2));
                slop_arena_free(&_arena_7);
                return _wa_ret;
            }
            slop_arena_free(arena);
        }
    } else {
        printf("%s\n", "usage: howl-test [sriq-dump STAGE FILE [BOUND] | front-dump FILE | ksc-dump FILE]");
        return 2;
    }
}

int64_t test_run_suite(void) {
    {
        #ifdef SLOP_DEBUG
        SLOP_PRE((4194304) > 0, "with-arena size must be positive");
        #endif
        slop_arena _arena_8 = slop_arena_new(4194304);
        #ifdef SLOP_DEBUG
        SLOP_PRE(_arena_8.base != NULL, "arena allocation failed");
        #endif
        slop_arena* arena = &_arena_8;
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
                __auto_type r = test_test_decode_rows(arena);
                test_print_test_result(SLOP_STR("decode: each pinned reading decodes exactly as written"), r);
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
                __auto_type r = test_test_inverses_decode_whole(arena);
                test_print_test_result(SLOP_STR("4a: ObjectInverseOf decodes in every property position"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_data_constructs_decode_as_data(arena);
                test_print_test_result(SLOP_STR("4a: data restrictions and data property axioms decode as data"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_concept_order_is_total(arena);
                test_print_test_result(SLOP_STR("4a: concept-cmp orders number restrictions and nominals"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_data_lemma(arena);
                test_print_test_result(SLOP_STR("§5.2: data axioms on idle data properties are inert in both rungs"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_ids_row(arena);
                test_print_test_result(SLOP_STR("5d: one document's ids, hand-checked"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_one_clause_from_two_axioms(arena);
                test_print_test_result(SLOP_STR("5d: one clause from two axioms, once"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_ids_from_content(arena);
                test_print_test_result(SLOP_STR("5d: sriq's ids from content, order-independent"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_every_axiom_yields(arena);
                test_print_test_result(SLOP_STR("5d: every accepted axiom yields clauses"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_guard_witnesses(arena);
                test_print_test_result(SLOP_STR("6e: a tripped guard's witnesses are the input's chains"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_s1_invariants(arena);
                test_print_test_result(SLOP_STR("6d: S1's promises hold on every fixture"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_s1_rows(arena);
                test_print_test_result(SLOP_STR("6d: sriq's S1, chain elimination, row by row"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_s2_refuses_a_count_past_the_bound(arena);
                test_print_test_result(SLOP_STR("5c: S2 refuses a count past the gate's bound"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_s2_rows(arena);
                test_print_test_result(SLOP_STR("5c: sriq's S2 into TGH21 Table 1, row by row"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_table1_rows(arena);
                test_print_test_result(SLOP_STR("7b: every Table 1 form expands to exactly its DL-clauses"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_clauses_cover_every_name(arena);
                test_print_test_result(SLOP_STR("7b: every name a clause uses gets an id, or the ontology is refused"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_clause_checks_reject(arena);
                test_print_test_result(SLOP_STR("7b: the DL-clause and id checks reject what they should"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_eq_orientation(arena);
                test_print_test_result(SLOP_STR("7b: s ≈ t and t ≈ s are one literal (TGH21 §2.1)"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_const_order(arena);
                test_print_test_result(SLOP_STR("7c: constants by label length, base, then label from the base"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_order_closure(arena);
                test_print_test_result(SLOP_STR("7c: the context order is the least order containing LPO and TGH21 §4.2's items"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_order_strict_and_admissible(arena);
                test_print_test_result(SLOP_STR("7c: the context order is strict and admissible (TGH21 Def. 7)"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_order_c2(arena);
                test_print_test_result(SLOP_STR("7c: the context order meets Theorem 2's C2 for every query"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_max_flags_rows(arena);
                test_print_test_result(SLOP_STR("7c: maximality (Δ ⊁ L), row by row"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_inhat_rows(arena);
                test_print_test_result(SLOP_STR("7d: ∈̂ by tautology (i), (ii), and by inclusion (iii), without substitution"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_commit_min_permutation(arena);
                test_print_test_result(SLOP_STR("7d: R1, the commit leaves min(W ∪ C) in every order of its candidates"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_commit_survivors(arena);
                test_print_test_result(SLOP_STR("7d: what the commit adds is what it inserts and keeps"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_inhat_persists(arena);
                test_print_test_result(SLOP_STR("7d: R2, ∈̂ persists through the commit"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_hyper_rows(arena);
                test_print_test_result(SLOP_STR("7e: Hyper, O1's inferences under HOWL's order"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_hyper_root_rows(arena);
                test_print_test_result(SLOP_STR("7e: Hyper at the root, E4's constants included"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_ineq_factor_core_rows(arena);
                test_print_test_result(SLOP_STR("7e: Ineq, Factor and Core, row by row"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_eq_rows(arena);
                test_print_test_result(SLOP_STR("7f: Eq, from O1, Example 1 and Example 2, and its exclusions"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_join_rows(arena);
                test_print_test_result(SLOP_STR("7f: Join, Example 1's (112)"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_nom_rows(arena);
                test_print_test_result(SLOP_STR("7f: Nom, Example 2's (150), below Λ only"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_depth_limit(arena);
                test_print_test_result(SLOP_STR("7f: Λ exact below 2^62, held there above"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_clauses_on_fixtures(arena);
                test_print_test_result(SLOP_STR("7b: every fixture's clauses are DL-clauses over dense ids, input-order independent"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_s0_rows(arena);
                test_print_test_result(SLOP_STR("5b: sriq's S0, the collapse and S1's hook, row by row"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_sriq_gate_table(arena);
                test_print_test_result(SLOP_STR("gate: sriq admits §5.5's language; el and el++ omit it (three-rung table)"), r);
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
                __auto_type r = test_test_ksc_cut_runs_say_resource_limit(arena);
                test_print_test_result(SLOP_STR("ksc: an answer the cap cut short says resource-limit"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_ksc_g_stops_at_bottom(arena);
                test_print_test_result(SLOP_STR("ksc: phase G stops committing at a round's first bottom (ksc-37)"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_ksc_engine_matches_reference(arena);
                test_print_test_result(SLOP_STR("ksc: the engine answers every class as the literal reference does"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_ksc_entailments(arena);
                test_print_test_result(SLOP_STR("ksc: §5.4's constructs reason as the Direct Semantics says"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_el_and_el_plus_plus_agree(arena);
                test_print_test_result(SLOP_STR("K5: el and el++ report the same on every el fixture"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_ksc_workers_agree(arena);
                test_print_test_result(SLOP_STR("ksc: every fixture answers the same at W = 1, 2, 4, 8 at every cap"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_ksc_cap(arena);
                test_print_test_result(SLOP_STR("ksc: a cap that cuts phase W answers nothing and says resource-limit"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_ksc_seed_unsat_counts_no_round(arena);
                test_print_test_result(SLOP_STR("ksc: a run flagged by its seed counts no round"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_ksc_cancelled(arena);
                test_print_test_result(SLOP_STR("ksc: a set cancel-ptr gives Fault::cancelled, no result"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_ksc_ids_round_trip(arena);
                test_print_test_result(SLOP_STR("ksc: the store's ids are a bijection on every derived fact"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_ksc_g_matches_reference(arena);
                test_print_test_result(SLOP_STR("ksc: the stored G is Psc's G, fact for fact through K7"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_ksc_commit_identical(arena);
                test_print_test_result(SLOP_STR("ksc: the parallel commit stores, counts and flags what the serial one does"), r);
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
                __auto_type r = test_test_missing_declaration_cites_its_axioms(arena);
                test_print_test_result(SLOP_STR("declarations: a missing declaration cites exactly the axioms naming it"), r);
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
                __auto_type r = test_test_classify_encoded_is_classify(arena);
                test_print_test_result(SLOP_STR("§8.4: classify-encoded reports what classify does (el, el++)"), r);
                if (r) {
                    passed = (passed + 1);
                } else {
                    failed = (failed + 1);
                }
            }
            {
                __auto_type r = test_test_public_api(arena);
                test_print_test_result(SLOP_STR("§8.4: the public C API reports what classify does, and refuses what it must"), r);
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
                test_print_test_result(SLOP_STR("§5.1: el and el++ run as asked, unbuilt rungs refused by name, auto by membership then fewest omissions"), r);
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
            {
                __auto_type r = test_test_dropped_rung_refusal(arena);
                test_print_test_result(SLOP_STR("§5: horn-sriq is dropped, and each refusal says why"), r);
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
                    int64_t _wa_ret = 0;
                    slop_arena_free(&_arena_8);
                    return _wa_ret;
                }
            } else {
                {
                    int64_t _wa_ret = 1;
                    slop_arena_free(&_arena_8);
                    return _wa_ret;
                }
            }
        }
        slop_arena_free(arena);
    }
}

