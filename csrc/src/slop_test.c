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
uint8_t test_test_stub_refuses_rather_than_passing(slop_arena* arena);
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
uint8_t test_decodes_ok(slop_arena* arena, slop_string ttl);
uint8_t test_test_undeclared_property_is_an_input_error(slop_arena* arena);
uint8_t test_test_unknown_owl_vocabulary_still_decodes(slop_arena* arena);
uint8_t test_test_conflicting_declarations_are_an_input_error(slop_arena* arena);
int64_t test_gate_omissions_of_ttl(slop_arena* arena, slop_string ttl);
slop_string test_rc_prefix(void);
uint8_t test_test_range_composition_table(slop_arena* arena);
slop_option_u8 test_regularity_of(slop_arena* arena, slop_string path);
uint8_t test_test_regularity_rejects_mutual_recursion(slop_arena* arena);
uint8_t test_test_regularity_accepts_equivalence_and_transitivity(slop_arena* arena);
uint8_t test_test_regularity_accepts_plain_subproperty(slop_arena* arena);
uint8_t test_test_regularity_accepts_nary_chain(slop_arena* arena);
uint8_t test_test_irregular_rbox_is_omitted_whole(slop_arena* arena);
slop_option_gate_GateResult test_gate_fixture(slop_arena* arena, slop_string path);
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

static int64_t test__lambda_498(void* _env, int64_t a, int64_t b) { return ({ __auto_type ka = (2 - (a / 3)); __auto_type kb = (2 - (b / 3)); ((ka < kb) ? -1 : ((ka > kb) ? 1 : 0)); }); }

types_Saturation test_empty_saturation(slop_arena* arena) {
    return ((types_Saturation){.contexts = slop_map_new_ptr(arena, 16, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node), .queues = slop_map_new_ptr(arena, 16, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node), .active = slop_map_new_ptr(arena, 16, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node), .active_count = 0, .iteration = 0});
}

types_Findings test_make_findings(slop_arena* arena, uint8_t inconsistent, int64_t unsat_count) {
    {
        __auto_type unsat = ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 });
        if (unsat_count > 0) {
            ({ __auto_type _lst_p = &(unsat); __auto_type _item = (((rdf_IRI){.value = SLOP_STR("http://example.org/Unsat")})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return ((types_Findings){.inconsistent = inconsistent, .unsatisfiable = unsat, .subsumptions = ((slop_list_types_SubPair){ .data = (types_SubPair*)slop_arena_alloc(arena, 16 * sizeof(types_SubPair)), .len = 0, .cap = 16 }), .imports_seen = ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 })});
    }
}

types_Outcome test_make_outcome(slop_arena* arena, uint8_t inconsistent, int64_t unsat_count, int64_t omitted_count, uint8_t reached_fixpoint) {
    {
        __auto_type omitted = ((slop_list_types_Omission){ .data = (types_Omission*)slop_arena_alloc(arena, 16 * sizeof(types_Omission)), .len = 0, .cap = 16 });
        if (omitted_count > 0) {
            ({ __auto_type _lst_p = &(omitted); __auto_type _item = (((types_Omission){ .tag = types_Omission_unresolved_import, .data.unresolved_import = ((rdf_IRI){.value = SLOP_STR("http://example.org/missing-import")}) })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return ((types_Outcome){.coverage = ((types_Coverage){.omitted = omitted}), .termination = ((reached_fixpoint) ? ((types_Termination){ .tag = types_Termination_fixpoint }) : ((types_Termination){ .tag = types_Termination_resource_limit, .data.resource_limit = 1000 })), .findings = test_make_findings(arena, inconsistent, unsat_count), .saturation = test_empty_saturation(arena)});
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
    __auto_type _mv_421 = n;
    switch (_mv_421.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_421.data.class_node;
            return i.value;
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_421.data.individual_node;
            return i.value;
        }
        case types_Node_fresh_node:
        {
            __auto_type _ = _mv_421.data.fresh_node;
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

uint8_t test_test_stub_refuses_rather_than_passing(slop_arena* arena) {
    __auto_type _mv_422 = howl_classify(arena, ((slop_list_rdf_Triple){ .data = (rdf_Triple*)slop_arena_alloc(arena, 16 * sizeof(rdf_Triple)), .len = 0, .cap = 16 }), ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 }), howl_default_config());
    if (_mv_422.is_ok) {
        __auto_type _ = _mv_422.data.ok;
        return 0;
    } else if (!_mv_422.is_ok) {
        __auto_type _ = _mv_422.data.err;
        return 1;
    }
    SLOP_UNREACHABLE();
}

types_Node test_cls(slop_string name) {
    return ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = name}) });
}

types_RoleId test_rol(slop_string name) {
    return ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = ((rdf_IRI){.value = name}) });
}

slop_result_saturate_RoundResult_types_Fault test_run_fixture(slop_arena* arena, slop_list_types_Node signature, slop_list_types_NormAxiom axioms) {
    return saturate_saturate(arena, saturate_make_initial_saturation(arena, signature), axioms, howl_default_config());
}

slop_list_types_Node test_litmus_signature(slop_arena* arena) {
    {
        __auto_type sig = ((slop_list_types_Node){ .data = (types_Node*)slop_arena_alloc(arena, 16 * sizeof(types_Node)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (test_cls(SLOP_STR("http://example.org/Person"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (test_cls(SLOP_STR("http://example.org/Parent"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (test_cls(SLOP_STR("http://example.org/Mother"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = 0 })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = (types_NormAxiom*)slop_arena_alloc(arena, 16 * sizeof(types_NormAxiom)), .len = 0, .cap = 16 });
        if (correct_polarity) {
            ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = has_child, .f1 = person, .f2 = x } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else {
            ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = x, .f1 = has_child, .f2 = person } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_and, .data.sub_and = { .f0 = person, .f1 = x, .f2 = parent } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = parent, .f1 = person } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = parent, .f1 = has_child, .f2 = person } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = mother, .f1 = person } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = mother, .f1 = has_child, .f2 = person } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ax;
    }
}

uint8_t test_litmus_derives_parent(slop_arena* arena, uint8_t correct_polarity) {
    __auto_type _mv_423 = test_run_fixture(arena, test_litmus_signature(arena), test_litmus_axioms(arena, correct_polarity));
    if (_mv_423.is_ok) {
        __auto_type r = _mv_423.data.ok;
        {
            __auto_type f = classify_extract_findings(arena, r.saturation);
            return classify_entails_sub(r.saturation, f.inconsistent, test_cls(SLOP_STR("http://example.org/Mother")), test_cls(SLOP_STR("http://example.org/Parent")));
        }
    } else if (!_mv_423.is_ok) {
        __auto_type _ = _mv_423.data.err;
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
        __auto_type sig = ((slop_list_types_Node){ .data = (types_Node*)slop_arena_alloc(arena, 16 * sizeof(types_Node)), .len = 0, .cap = 16 });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = (types_NormAxiom*)slop_arena_alloc(arena, 16 * sizeof(types_NormAxiom)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = a, .f1 = b } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = b, .f1 = a } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_424 = test_run_fixture(arena, sig, ax);
        if (_mv_424.is_ok) {
            __auto_type r = _mv_424.data.ok;
            __auto_type _mv_425 = r.termination;
            switch (_mv_425.tag) {
                case types_Termination_fixpoint:
                {
                    return 1;
                }
                case types_Termination_resource_limit:
                {
                    __auto_type _ = _mv_425.data.resource_limit;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_424.is_ok) {
            __auto_type _ = _mv_424.data.err;
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
        __auto_type sig = ((slop_list_types_Node){ .data = (types_Node*)slop_arena_alloc(arena, 16 * sizeof(types_Node)), .len = 0, .cap = 16 });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = (types_NormAxiom*)slop_arena_alloc(arena, 16 * sizeof(types_NormAxiom)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (h); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = e, .f1 = r, .f2 = f } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = f, .f1 = g } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = r, .f1 = g, .f2 = h } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_426 = test_run_fixture(arena, sig, ax);
        if (_mv_426.is_ok) {
            __auto_type res = _mv_426.data.ok;
            {
                __auto_type fi = classify_extract_findings(arena, res.saturation);
                return classify_entails_sub(res.saturation, fi.inconsistent, e, h);
            }
        } else if (!_mv_426.is_ok) {
            __auto_type _ = _mv_426.data.err;
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
        __auto_type sig = ((slop_list_types_Node){ .data = (types_Node*)slop_arena_alloc(arena, 16 * sizeof(types_Node)), .len = 0, .cap = 16 });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = (types_NormAxiom*)slop_arena_alloc(arena, 16 * sizeof(types_NormAxiom)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (f1); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (h); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = e, .f1 = r, .f2 = f } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = f, .f1 = f1 } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = f1, .f1 = g } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = r, .f1 = g, .f2 = h } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_427 = test_run_fixture(arena, sig, ax);
        if (_mv_427.is_ok) {
            __auto_type res = _mv_427.data.ok;
            {
                __auto_type fi = classify_extract_findings(arena, res.saturation);
                return classify_entails_sub(res.saturation, fi.inconsistent, e, h);
            }
        } else if (!_mv_427.is_ok) {
            __auto_type _ = _mv_427.data.err;
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
        __auto_type sig = ((slop_list_types_Node){ .data = (types_Node*)slop_arena_alloc(arena, 16 * sizeof(types_Node)), .len = 0, .cap = 16 });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = (types_NormAxiom*)slop_arena_alloc(arena, 16 * sizeof(types_NormAxiom)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = a, .f1 = b } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = a, .f1 = c } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_and, .data.sub_and = { .f0 = b, .f1 = c, .f2 = types_node_bottom() } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return test_run_fixture(arena, sig, ax);
    }
}

uint8_t test_test_unsatisfiable_class_detected(slop_arena* arena) {
    __auto_type _mv_428 = test_unsat_fixture(arena);
    if (_mv_428.is_ok) {
        __auto_type r = _mv_428.data.ok;
        {
            __auto_type f = classify_extract_findings(arena, r.saturation);
            if (((int64_t)((f.unsatisfiable).len)) == 1) {
                return types_findings_are_incoherent(f);
            } else {
                return 0;
            }
        }
    } else if (!_mv_428.is_ok) {
        __auto_type _ = _mv_428.data.err;
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_bottom_compression(slop_arena* arena) {
    __auto_type _mv_429 = test_unsat_fixture(arena);
    if (_mv_429.is_ok) {
        __auto_type r = _mv_429.data.ok;
        {
            __auto_type a = test_cls(SLOP_STR("http://example.org/A"));
            __auto_type b = test_cls(SLOP_STR("http://example.org/B"));
            __auto_type f = classify_extract_findings(arena, r.saturation);
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
            if (classify_entails_sub(r.saturation, f.inconsistent, a, b)) {
                return (pairs_about_a == 1);
            } else {
                return 0;
            }
        }
    } else if (!_mv_429.is_ok) {
        __auto_type _ = _mv_429.data.err;
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_inconsistency_suppresses_both_lists(slop_arena* arena) {
    {
        __auto_type a = test_cls(SLOP_STR("http://example.org/A"));
        __auto_type sig = ((slop_list_types_Node){ .data = (types_Node*)slop_arena_alloc(arena, 16 * sizeof(types_Node)), .len = 0, .cap = 16 });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = (types_NormAxiom*)slop_arena_alloc(arena, 16 * sizeof(types_NormAxiom)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(sig); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = types_node_top(), .f1 = types_node_bottom() } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_430 = test_run_fixture(arena, sig, ax);
        if (_mv_430.is_ok) {
            __auto_type r = _mv_430.data.ok;
            {
                __auto_type f = classify_extract_findings(arena, r.saturation);
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
        } else if (!_mv_430.is_ok) {
            __auto_type _ = _mv_430.data.err;
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
        __auto_type fwd = ((slop_list_types_Node){ .data = (types_Node*)slop_arena_alloc(arena, 16 * sizeof(types_Node)), .len = 0, .cap = 16 });
        __auto_type rev = ((slop_list_types_Node){ .data = (types_Node*)slop_arena_alloc(arena, 16 * sizeof(types_Node)), .len = 0, .cap = 16 });
        __auto_type ax = ((slop_list_types_NormAxiom){ .data = (types_NormAxiom*)slop_arena_alloc(arena, 16 * sizeof(types_NormAxiom)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(fwd); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(fwd); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(fwd); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(rev); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(rev); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(rev); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = a, .f1 = b } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ax); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = b, .f1 = c } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_431 = test_run_fixture(arena, fwd, ax);
        if (_mv_431.is_ok) {
            __auto_type r1 = _mv_431.data.ok;
            __auto_type _mv_432 = test_run_fixture(arena, rev, ax);
            if (_mv_432.is_ok) {
                __auto_type r2 = _mv_432.data.ok;
                {
                    __auto_type f1 = classify_extract_findings(arena, r1.saturation);
                    __auto_type f2 = classify_extract_findings(arena, r2.saturation);
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
            } else if (!_mv_432.is_ok) {
                __auto_type _ = _mv_432.data.err;
                return 0;
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_431.is_ok) {
            __auto_type _ = _mv_431.data.err;
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
        return ((canon_string_cmp(apple, buf) == -1) && ((canon_string_cmp(buf, apple) == 1) && ((canon_string_cmp(apple, SLOP_STR("apple")) == 0) && (canon_string_cmp(apple, apple) == 0))));
    }
}

uint8_t test_test_node_cmp_separates_punned_iris(slop_arena* arena) {
    {
        __auto_type c = ((types_Node){ .tag = types_Node_class_node, .data.class_node = test_mk_iri(SLOP_STR("http://example.org/x")) });
        __auto_type i = ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = test_mk_iri(SLOP_STR("http://example.org/x")) });
        return ((canon_node_cmp(c, i) != 0) && ((canon_node_cmp(c, i) == -1) && ((canon_node_cmp(i, c) == 1) && (canon_node_cmp(c, c) == 0))));
    }
}

uint8_t test_test_sort_orders_and_is_input_determined(slop_arena* arena) {
    {
        __auto_type a = ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 });
        __auto_type b = ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(a); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/zebra"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(a); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/apple"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(a); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/apple2"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(a); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/mango"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(b); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/mango"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(b); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/apple2"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(b); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/zebra"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(b); __auto_type _item = (test_mk_iri(SLOP_STR("http://example.org/apple"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    __auto_type _mv_433 = ttl_parse_ttl_file(arena, SLOP_STR("corpus/fixtures/hazards/unattested-import.ttl"));
    if (!_mv_433.is_ok) {
        __auto_type _ = _mv_433.data.err;
        return 0;
    } else if (_mv_433.is_ok) {
        __auto_type g = _mv_433.data.ok;
        __auto_type _mv_434 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 }));
        if (!_mv_434.is_ok) {
            __auto_type _ = _mv_434.data.err;
            return 0;
        } else if (_mv_434.is_ok) {
            __auto_type s0 = _mv_434.data.ok;
            return ((((int64_t)(((int64_t)((s0.imports_declared).len)))) == 1) && (((int64_t)(((int64_t)((s0.omissions).len)))) == 1));
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_attested_import_yields_none(slop_arena* arena) {
    __auto_type _mv_435 = ttl_parse_ttl_file(arena, SLOP_STR("corpus/fixtures/hazards/unattested-import.ttl"));
    if (!_mv_435.is_ok) {
        __auto_type _ = _mv_435.data.err;
        return 0;
    } else if (_mv_435.is_ok) {
        __auto_type g = _mv_435.data.ok;
        {
            __auto_type resolved = ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 });
            ({ __auto_type _lst_p = &(resolved); __auto_type _item = (((rdf_IRI){.value = SLOP_STR("http://example.org/does-not-exist")})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            __auto_type _mv_436 = decode_stage0_header(arena, g.triples, resolved);
            if (!_mv_436.is_ok) {
                __auto_type _ = _mv_436.data.err;
                return 0;
            } else if (_mv_436.is_ok) {
                __auto_type s0 = _mv_436.data.ok;
                return ((((int64_t)(((int64_t)((s0.imports_declared).len)))) == 1) && (((int64_t)(((int64_t)((s0.omissions).len)))) == 0));
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_header_and_reification_are_consumed(slop_arena* arena) {
    __auto_type _mv_437 = ttl_parse_ttl_file(arena, SLOP_STR("corpus/fixtures/hazards/annotation-heavy.ttl"));
    if (!_mv_437.is_ok) {
        __auto_type _ = _mv_437.data.err;
        return 0;
    } else if (_mv_437.is_ok) {
        __auto_type g = _mv_437.data.ok;
        __auto_type _mv_438 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 }));
        if (!_mv_438.is_ok) {
            __auto_type _ = _mv_438.data.err;
            return 0;
        } else if (_mv_438.is_ok) {
            __auto_type s0 = _mv_438.data.ok;
            {
                __auto_type sub_pred = rdf_make_iri(arena, vocab_RDFS_SUBCLASS_OF);
                __auto_type kept = test_count_subclass_triples(s0.triples, sub_pred);
                __auto_type before = test_count_subclass_triples(g.triples, sub_pred);
                return ((kept == 1) && ((before == 1) && ((((int64_t)(((int64_t)((s0.omissions).len)))) == 0) && (((int64_t)(((int64_t)((s0.triples).len)))) < ((int64_t)(((int64_t)((g.triples).len))))))));
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
                __auto_type _mv_439 = owl2_disposition(a);
                if (_mv_439 == owl2_Disposition_d_out_of_profile) {
                    n = (n + 1);
                } else if (_mv_439 == owl2_Disposition_d_in_profile) {
                    if (!(owl2_axiom_in_profile(a))) {
                        n = (n + 1);
                    }
                } else if (_mv_439 == owl2_Disposition_d_inert) {
                } else if (_mv_439 == owl2_Disposition_d_consumed) {
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
                if (owl2_disposition(a) == want) {
                    n = (n + 1);
                }
            }
        }
        return n;
    }
}

slop_option_decode_Stage1 test_decode_fixture(slop_arena* arena, slop_string path) {
    __auto_type _mv_440 = ttl_parse_ttl_file(arena, path);
    if (!_mv_440.is_ok) {
        __auto_type _ = _mv_440.data.err;
        return (slop_option_decode_Stage1){.has_value = false};
    } else if (_mv_440.is_ok) {
        __auto_type g = _mv_440.data.ok;
        __auto_type _mv_441 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 }));
        if (!_mv_441.is_ok) {
            __auto_type _ = _mv_441.data.err;
            return (slop_option_decode_Stage1){.has_value = false};
        } else if (_mv_441.is_ok) {
            __auto_type s0 = _mv_441.data.ok;
            __auto_type _mv_442 = decode_decode_axioms(arena, s0.triples);
            if (!_mv_442.is_ok) {
                __auto_type _ = _mv_442.data.err;
                return (slop_option_decode_Stage1){.has_value = false};
            } else if (_mv_442.is_ok) {
                __auto_type s1 = _mv_442.data.ok;
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
                __auto_type _mv_443 = a;
                switch (_mv_443.tag) {
                    case owl2_RawAxiom_ra_disjoint_classes:
                    {
                        __auto_type cs = _mv_443.data.ra_disjoint_classes;
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
    __auto_type _mv_444 = test_decode_fixture(arena, SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl"));
    if (!_mv_444.has_value) {
        return 0;
    } else if (_mv_444.has_value) {
        __auto_type s1 = _mv_444.value;
        return ((test_nary_disjoint_member_count(s1.axioms) == 3) && (test_count_out_of_profile(s1.axioms) == 0));
    }
    SLOP_UNREACHABLE();
}

int64_t test_out_of_profile_count_of(slop_arena* arena, slop_string path) {
    __auto_type _mv_445 = test_decode_fixture(arena, path);
    if (!_mv_445.has_value) {
        return -1;
    } else if (_mv_445.has_value) {
        __auto_type s1 = _mv_445.value;
        return test_count_out_of_profile(s1.axioms);
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_v0_corpus_decodes_clean(slop_arena* arena) {
    {
        __auto_type paths = ((slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 16 * sizeof(slop_string)), .len = 0, .cap = 16 });
        uint8_t ok = 1;
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subclass-atomic.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/intersection.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-lhs.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-rhs.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-classes.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-properties.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-binary.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subproperty.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/transitive.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/domain.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/range.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/abox-assertions.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/top-bottom.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/litmus.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        __auto_type paths = ((slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 16 * sizeof(slop_string)), .len = 0, .cap = 16 });
        uint8_t ok = 1;
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/union.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/complement.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/allvalues.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/nominals.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/cardinality.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/has-self.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/inverse.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/equality.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/property-characteristics.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/haskey-disjointunion.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/swrl-rule.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/builtin-roles.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/anonymous-individual.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/datatypes.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    __auto_type _mv_446 = test_decode_fixture(arena, SLOP_STR("corpus/fixtures/hazards/annotation-heavy.ttl"));
    if (!_mv_446.has_value) {
        return 0;
    } else if (_mv_446.has_value) {
        __auto_type s1 = _mv_446.value;
        {
            __auto_type axs = s1.axioms;
            return ((test_count_out_of_profile(axs) == 0) && ((test_count_disposition(axs, owl2_Disposition_d_in_profile) > 0) && ((test_count_disposition(axs, owl2_Disposition_d_inert) > 0) && (test_count_disposition(axs, owl2_Disposition_d_consumed) > 0))));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_litmus_decodes_clean(slop_arena* arena) {
    __auto_type _mv_447 = test_decode_fixture(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl"));
    if (!_mv_447.has_value) {
        return 0;
    } else if (_mv_447.has_value) {
        __auto_type s1 = _mv_447.value;
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

uint8_t test_decodes_ok(slop_arena* arena, slop_string ttl) {
    __auto_type _mv_448 = ttl_parse_ttl_string(arena, ttl);
    if (!_mv_448.is_ok) {
        __auto_type _ = _mv_448.data.err;
        return 0;
    } else if (_mv_448.is_ok) {
        __auto_type g = _mv_448.data.ok;
        __auto_type _mv_449 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 }));
        if (!_mv_449.is_ok) {
            __auto_type _ = _mv_449.data.err;
            return 0;
        } else if (_mv_449.is_ok) {
            __auto_type s0 = _mv_449.data.ok;
            __auto_type _mv_450 = decode_decode_axioms(arena, s0.triples);
            if (!_mv_450.is_ok) {
                __auto_type _ = _mv_450.data.err;
                return 0;
            } else if (_mv_450.is_ok) {
                __auto_type _ = _mv_450.data.ok;
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

int64_t test_gate_omissions_of_ttl(slop_arena* arena, slop_string ttl) {
    __auto_type _mv_451 = ttl_parse_ttl_string(arena, ttl);
    if (!_mv_451.is_ok) {
        __auto_type _ = _mv_451.data.err;
        return -1;
    } else if (_mv_451.is_ok) {
        __auto_type g = _mv_451.data.ok;
        __auto_type _mv_452 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 }));
        if (!_mv_452.is_ok) {
            __auto_type _ = _mv_452.data.err;
            return -1;
        } else if (_mv_452.is_ok) {
            __auto_type s0 = _mv_452.data.ok;
            __auto_type _mv_453 = decode_decode_axioms(arena, s0.triples);
            if (!_mv_453.is_ok) {
                __auto_type _ = _mv_453.data.err;
                return -1;
            } else if (_mv_453.is_ok) {
                __auto_type s1 = _mv_453.data.ok;
                return ((int64_t)(((int64_t)((gate_gate_axioms(arena, s1.axioms, s1.signature, s0.omissions).omissions).len))));
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
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
        return ok;
    }
}

slop_option_u8 test_regularity_of(slop_arena* arena, slop_string path) {
    __auto_type _mv_454 = ttl_parse_ttl_file(arena, path);
    if (!_mv_454.is_ok) {
        __auto_type _ = _mv_454.data.err;
        return (slop_option_u8){.has_value = false};
    } else if (_mv_454.is_ok) {
        __auto_type g = _mv_454.data.ok;
        __auto_type _mv_455 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 }));
        if (!_mv_455.is_ok) {
            __auto_type _ = _mv_455.data.err;
            return (slop_option_u8){.has_value = false};
        } else if (_mv_455.is_ok) {
            __auto_type s0 = _mv_455.data.ok;
            __auto_type _mv_456 = decode_decode_axioms(arena, s0.triples);
            if (!_mv_456.is_ok) {
                __auto_type _ = _mv_456.data.err;
                return (slop_option_u8){.has_value = false};
            } else if (_mv_456.is_ok) {
                __auto_type s1 = _mv_456.data.ok;
                __auto_type _mv_457 = gate_check_regularity(arena, gate_expand_sugar(arena, s1.axioms));
                switch (_mv_457.tag) {
                    case gate_RboxVerdict_rbox_regular:
                    {
                        return (slop_option_u8){.has_value = 1, .value = 1};
                    }
                    case gate_RboxVerdict_rbox_irregular:
                    {
                        __auto_type _ = _mv_457.data.rbox_irregular;
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
    __auto_type _mv_458 = test_regularity_of(arena, SLOP_STR("corpus/fixtures/hazards/rbox-regularity-reject.ttl"));
    if (!_mv_458.has_value) {
        return 0;
    } else if (_mv_458.has_value) {
        __auto_type regular = _mv_458.value;
        return !(regular);
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_regularity_accepts_equivalence_and_transitivity(slop_arena* arena) {
    __auto_type _mv_459 = test_regularity_of(arena, SLOP_STR("corpus/fixtures/hazards/rbox-regularity-accept.ttl"));
    if (!_mv_459.has_value) {
        return 0;
    } else if (_mv_459.has_value) {
        __auto_type regular = _mv_459.value;
        return regular;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_regularity_accepts_plain_subproperty(slop_arena* arena) {
    __auto_type _mv_460 = test_regularity_of(arena, SLOP_STR("corpus/fixtures/v0/subproperty.ttl"));
    if (!_mv_460.has_value) {
        return 0;
    } else if (_mv_460.has_value) {
        __auto_type regular = _mv_460.value;
        return regular;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_regularity_accepts_nary_chain(slop_arena* arena) {
    __auto_type _mv_461 = test_regularity_of(arena, SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl"));
    if (!_mv_461.has_value) {
        return 0;
    } else if (_mv_461.has_value) {
        __auto_type regular = _mv_461.value;
        return regular;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_irregular_rbox_is_omitted_whole(slop_arena* arena) {
    __auto_type _mv_462 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/hazards/rbox-regularity-reject.ttl"));
    if (!_mv_462.has_value) {
        return 0;
    } else if (_mv_462.has_value) {
        __auto_type gr = _mv_462.value;
        return ((((int64_t)(((int64_t)((gr.omissions).len)))) > 0) && (test_count_variant_chain(gr.accepted) == 0));
    }
    SLOP_UNREACHABLE();
}

slop_option_gate_GateResult test_gate_fixture(slop_arena* arena, slop_string path) {
    __auto_type _mv_463 = ttl_parse_ttl_file(arena, path);
    if (!_mv_463.is_ok) {
        __auto_type _ = _mv_463.data.err;
        return (slop_option_gate_GateResult){.has_value = false};
    } else if (_mv_463.is_ok) {
        __auto_type g = _mv_463.data.ok;
        __auto_type _mv_464 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 }));
        if (!_mv_464.is_ok) {
            __auto_type _ = _mv_464.data.err;
            return (slop_option_gate_GateResult){.has_value = false};
        } else if (_mv_464.is_ok) {
            __auto_type s0 = _mv_464.data.ok;
            __auto_type _mv_465 = decode_decode_axioms(arena, s0.triples);
            if (!_mv_465.is_ok) {
                __auto_type _ = _mv_465.data.err;
                return (slop_option_gate_GateResult){.has_value = false};
            } else if (_mv_465.is_ok) {
                __auto_type s1 = _mv_465.data.ok;
                return (slop_option_gate_GateResult){.has_value = 1, .value = gate_gate_axioms(arena, s1.axioms, s1.signature, s0.omissions)};
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
                __auto_type _mv_466 = a;
                switch (_mv_466.tag) {
                    case owl2_RawAxiom_ra_property_chain:
                    {
                        __auto_type _ = _mv_466.data.ra_property_chain;
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
                __auto_type _mv_467 = a;
                switch (_mv_467.tag) {
                    case owl2_RawAxiom_ra_disjoint_classes:
                    {
                        __auto_type _ = _mv_467.data.ra_disjoint_classes;
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
                __auto_type _mv_468 = a;
                switch (_mv_468.tag) {
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
    __auto_type _mv_469 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/hazards/annotation-heavy.ttl"));
    if (!_mv_469.has_value) {
        return 0;
    } else if (_mv_469.has_value) {
        __auto_type gr = _mv_469.value;
        return ((((int64_t)(((int64_t)((gr.omissions).len)))) == 0) && (test_count_variant_subclass(gr.accepted) > 0));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_gate_carries_import_omissions(slop_arena* arena) {
    __auto_type _mv_470 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/hazards/unattested-import.ttl"));
    if (!_mv_470.has_value) {
        return 0;
    } else if (_mv_470.has_value) {
        __auto_type gr = _mv_470.value;
        return (((int64_t)(((int64_t)((gr.omissions).len)))) == 1);
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sugar_transitivity_becomes_a_chain(slop_arena* arena) {
    __auto_type _mv_471 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/v0/transitive.ttl"));
    if (!_mv_471.has_value) {
        return 0;
    } else if (_mv_471.has_value) {
        __auto_type gr = _mv_471.value;
        return ((test_count_variant_chain(gr.accepted) > 0) && (((int64_t)(((int64_t)((gr.omissions).len)))) == 0));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sugar_nary_disjointness_becomes_pairs(slop_arena* arena) {
    __auto_type _mv_472 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl"));
    if (!_mv_472.has_value) {
        return 0;
    } else if (_mv_472.has_value) {
        __auto_type gr = _mv_472.value;
        return (test_count_variant_disjoint(gr.accepted) == 3);
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_sugar_equivalence_is_a_star_not_all_pairs(slop_arena* arena) {
    __auto_type _mv_473 = test_gate_fixture(arena, SLOP_STR("corpus/fixtures/v0/equivalent-classes.ttl"));
    if (!_mv_473.has_value) {
        return 0;
    } else if (_mv_473.has_value) {
        __auto_type gr = _mv_473.value;
        return ((test_count_variant_subclass(gr.accepted) > 0) && (((int64_t)(((int64_t)((gr.omissions).len)))) == 0));
    }
    SLOP_UNREACHABLE();
}

int64_t test_gate_omission_count(slop_arena* arena, slop_string path) {
    __auto_type _mv_474 = test_gate_fixture(arena, path);
    if (!_mv_474.has_value) {
        return -1;
    } else if (_mv_474.has_value) {
        __auto_type gr = _mv_474.value;
        return ((int64_t)(((int64_t)((gr.omissions).len))));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_gate_accepts_every_v0_fixture(slop_arena* arena) {
    {
        __auto_type paths = ((slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 16 * sizeof(slop_string)), .len = 0, .cap = 16 });
        uint8_t ok = 1;
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subclass-atomic.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/intersection.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-lhs.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/exists-rhs.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-classes.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/equivalent-properties.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-binary.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/disjoint-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/subproperty.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/property-chain-nary.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/transitive.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/domain.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/range.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/abox-assertions.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/top-bottom.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/v0/litmus.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        __auto_type paths = ((slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 16 * sizeof(slop_string)), .len = 0, .cap = 16 });
        uint8_t ok = 1;
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/union.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/complement.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/allvalues.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/nominals.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/cardinality.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/has-self.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/inverse.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/equality.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/property-characteristics.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/haskey-disjointunion.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/swrl-rule.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/builtin-roles.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/anonymous-individual.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(paths); __auto_type _item = (SLOP_STR("corpus/fixtures/out-of-profile/datatypes.ttl")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    __auto_type _mv_475 = ttl_parse_ttl_file(arena, path);
    if (!_mv_475.is_ok) {
        __auto_type _ = _mv_475.data.err;
        return (slop_option_owl2_Signature){.has_value = false};
    } else if (_mv_475.is_ok) {
        __auto_type g = _mv_475.data.ok;
        __auto_type _mv_476 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 }));
        if (!_mv_476.is_ok) {
            __auto_type _ = _mv_476.data.err;
            return (slop_option_owl2_Signature){.has_value = false};
        } else if (_mv_476.is_ok) {
            __auto_type s0 = _mv_476.data.ok;
            return (slop_option_owl2_Signature){.has_value = 1, .value = decode_build_signature(arena, s0.triples)};
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_declared_unused_class_reaches_the_signature(slop_arena* arena) {
    __auto_type _mv_477 = test_signature_of_fixture(arena, SLOP_STR("corpus/fixtures/hazards/declared-unused-class.ttl"));
    if (!_mv_477.has_value) {
        return 0;
    } else if (_mv_477.has_value) {
        __auto_type sig = _mv_477.value;
        return (owl2_signature_has_class(sig, ((rdf_IRI){.value = SLOP_STR("http://example.org/t#Unused")})) && owl2_signature_has_class(sig, ((rdf_IRI){.value = SLOP_STR("http://example.org/t#A")})));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_builtins_are_declared(slop_arena* arena) {
    __auto_type _mv_478 = test_signature_of_fixture(arena, SLOP_STR("corpus/fixtures/hazards/declared-unused-class.ttl"));
    if (!_mv_478.has_value) {
        return 0;
    } else if (_mv_478.has_value) {
        __auto_type sig = _mv_478.value;
        return (owl2_signature_has_class(sig, ((rdf_IRI){.value = vocab_OWL_THING})) && owl2_signature_has_annotation_property(sig, ((rdf_IRI){.value = vocab_RDFS_LABEL})));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_custom_annotation_property_is_recognized(slop_arena* arena) {
    __auto_type _mv_479 = test_signature_of_fixture(arena, SLOP_STR("corpus/fixtures/hazards/annotation-heavy.ttl"));
    if (!_mv_479.has_value) {
        return 0;
    } else if (_mv_479.has_value) {
        __auto_type sig = _mv_479.value;
        return (owl2_signature_has_annotation_property(sig, ((rdf_IRI){.value = SLOP_STR("http://example.org/t#curatorNote")})) && (owl2_signature_has_class(sig, ((rdf_IRI){.value = SLOP_STR("http://example.org/t#A")})) && !(owl2_signature_has_class(sig, ((rdf_IRI){.value = SLOP_STR("http://example.org/t#curatorNote")})))));
    }
    SLOP_UNREACHABLE();
}

uint8_t test_is_named_class(owl2_RawConcept c, slop_string iri) {
    __auto_type _mv_480 = c;
    switch (_mv_480.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type nd = _mv_480.data.rc_name;
            __auto_type _mv_481 = nd;
            switch (_mv_481.tag) {
                case types_Node_class_node:
                {
                    __auto_type i = _mv_481.data.class_node;
                    return (canon_string_cmp(i.value, iri) == 0);
                }
                case types_Node_individual_node:
                {
                    __auto_type _ = _mv_481.data.individual_node;
                    return 0;
                }
                case types_Node_fresh_node:
                {
                    __auto_type _ = _mv_481.data.fresh_node;
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
    __auto_type _mv_482 = c;
    switch (_mv_482.tag) {
        case owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_482.data.rc_some.f0;
            __auto_type f = _mv_482.data.rc_some.f1;
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
        __auto_type _mv_483 = ttl_parse_ttl_file(arena, SLOP_STR("corpus/fixtures/v0/litmus.ttl"));
        if (!_mv_483.is_ok) {
            __auto_type _ = _mv_483.data.err;
            return 0;
        } else if (_mv_483.is_ok) {
            __auto_type g = _mv_483.data.ok;
            __auto_type _mv_484 = decode_stage0_header(arena, g.triples, ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 }));
            if (!_mv_484.is_ok) {
                __auto_type _ = _mv_484.data.err;
                return 0;
            } else if (_mv_484.is_ok) {
                __auto_type s0 = _mv_484.data.ok;
                {
                    __auto_type ig = decode_graph_to_indexed(arena, s0.triples);
                    __auto_type parent = rdf_make_iri(arena, SLOP_STR("http://example.org/t#Parent"));
                    __auto_type eq_pred = rdf_make_iri(arena, vocab_OWL_EQUIVALENT_CLASS);
                    __auto_type _mv_485 = decode_one_object(arena, ig, parent, eq_pred);
                    if (!_mv_485.is_ok) {
                        __auto_type _ = _mv_485.data.err;
                        return 0;
                    } else if (_mv_485.is_ok) {
                        __auto_type defn = _mv_485.data.ok;
                        __auto_type _mv_486 = decode_decode_concept(arena, ig, defn, decode_CONCEPT_FUEL);
                        if (!_mv_486.is_ok) {
                            __auto_type _ = _mv_486.data.err;
                            return 0;
                        } else if (_mv_486.is_ok) {
                            __auto_type c = _mv_486.data.ok;
                            __auto_type _mv_487 = c;
                            switch (_mv_487.tag) {
                                case owl2_RawConcept_rc_and:
                                {
                                    __auto_type cs = _mv_487.data.rc_and;
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
                                        return ((n == 2) && (saw_person && saw_some));
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
        __auto_type ts = ((slop_list_rdf_Triple){ .data = (rdf_Triple*)slop_arena_alloc(arena, 16 * sizeof(rdf_Triple)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, u, c1)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, c1, f, ea)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, c1, r, c2)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, c2, f, eb)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, c2, r, nil_t)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_488 = decode_decode_concept(arena, decode_graph_to_indexed(arena, ts), b1, decode_CONCEPT_FUEL);
        if (!_mv_488.is_ok) {
            __auto_type _ = _mv_488.data.err;
            return 0;
        } else if (_mv_488.is_ok) {
            __auto_type c = _mv_488.data.ok;
            __auto_type _mv_489 = c;
            switch (_mv_489.tag) {
                case owl2_RawConcept_rc_or:
                {
                    __auto_type cs = _mv_489.data.rc_or;
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
        __auto_type ts = ((slop_list_rdf_Triple){ .data = (rdf_Triple*)slop_arena_alloc(arena, 16 * sizeof(rdf_Triple)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, comp, b1)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_490 = decode_decode_concept(arena, decode_graph_to_indexed(arena, ts), b1, decode_CONCEPT_FUEL);
        if (!_mv_490.is_ok) {
            __auto_type _ = _mv_490.data.err;
            return 1;
        } else if (_mv_490.is_ok) {
            __auto_type _ = _mv_490.data.ok;
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
        __auto_type ts = ((slop_list_rdf_Triple){ .data = (rdf_Triple*)slop_arena_alloc(arena, 16 * sizeof(rdf_Triple)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, f, ea)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, r, b2)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, f, eb)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, r, b3)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b3, f, ec)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b3, r, nil_t)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_491 = decode_rdf_list_checked(arena, decode_graph_to_indexed(arena, ts), b1);
        if (!_mv_491.is_ok) {
            __auto_type _ = _mv_491.data.err;
            return 0;
        } else if (_mv_491.is_ok) {
            __auto_type els = _mv_491.data.ok;
            return ((((int64_t)(((int64_t)((els).len)))) == 3) && (rdf_term_eq(decode_term_at(els, 0), ea) && (rdf_term_eq(decode_term_at(els, 1), eb) && rdf_term_eq(decode_term_at(els, 2), ec))));
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
        __auto_type ts = ((slop_list_rdf_Triple){ .data = (rdf_Triple*)slop_arena_alloc(arena, 16 * sizeof(rdf_Triple)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, f, ea)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, r, b2)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, r, b3)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b3, f, ec)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b3, r, nil_t)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_492 = decode_rdf_list_checked(arena, decode_graph_to_indexed(arena, ts), b1);
        if (_mv_492.is_ok) {
            __auto_type _ = _mv_492.data.ok;
            return 0;
        } else if (!_mv_492.is_ok) {
            __auto_type e = _mv_492.data.err;
            __auto_type _mv_493 = e;
            switch (_mv_493.tag) {
                case decode_ListFault_list_truncated:
                {
                    __auto_type _ = _mv_493.data.list_truncated;
                    return 1;
                }
                case decode_ListFault_list_branching:
                {
                    __auto_type _ = _mv_493.data.list_branching;
                    return 0;
                }
                case decode_ListFault_list_cyclic:
                {
                    __auto_type _ = _mv_493.data.list_cyclic;
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
        __auto_type ts = ((slop_list_rdf_Triple){ .data = (rdf_Triple*)slop_arena_alloc(arena, 16 * sizeof(rdf_Triple)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, f, ea)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, r, b2)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, f, eb)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b2, r, b1)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_494 = decode_rdf_list_checked(arena, decode_graph_to_indexed(arena, ts), b1);
        if (_mv_494.is_ok) {
            __auto_type _ = _mv_494.data.ok;
            return 0;
        } else if (!_mv_494.is_ok) {
            __auto_type e = _mv_494.data.err;
            __auto_type _mv_495 = e;
            switch (_mv_495.tag) {
                case decode_ListFault_list_cyclic:
                {
                    __auto_type _ = _mv_495.data.list_cyclic;
                    return 1;
                }
                case decode_ListFault_list_truncated:
                {
                    __auto_type _ = _mv_495.data.list_truncated;
                    return 0;
                }
                case decode_ListFault_list_branching:
                {
                    __auto_type _ = _mv_495.data.list_branching;
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
        __auto_type ts = ((slop_list_rdf_Triple){ .data = (rdf_Triple*)slop_arena_alloc(arena, 16 * sizeof(rdf_Triple)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, f, ea)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, f, eb)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ts); __auto_type _item = (rdf_make_triple(arena, b1, r, nil_t)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        __auto_type _mv_496 = decode_rdf_list_checked(arena, decode_graph_to_indexed(arena, ts), b1);
        if (_mv_496.is_ok) {
            __auto_type _ = _mv_496.data.ok;
            return 0;
        } else if (!_mv_496.is_ok) {
            __auto_type e = _mv_496.data.err;
            __auto_type _mv_497 = e;
            switch (_mv_497.tag) {
                case decode_ListFault_list_branching:
                {
                    __auto_type _ = _mv_497.data.list_branching;
                    return 1;
                }
                case decode_ListFault_list_truncated:
                {
                    __auto_type _ = _mv_497.data.list_truncated;
                    return 0;
                }
                case decode_ListFault_list_cyclic:
                {
                    __auto_type _ = _mv_497.data.list_cyclic;
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
        __auto_type idx = canon_sort_range(arena, 9, (slop_closure_t){(void*)test__lambda_498, NULL});
        __auto_type expect = ((slop_list_int){ .data = (int64_t*)slop_arena_alloc(arena, 16 * sizeof(int64_t)), .len = 0, .cap = 16 });
        uint8_t ok = 1;
        int64_t i = 0;
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (6); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (7); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (8); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (3); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (4); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (5); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (1); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(expect); __auto_type _item = (2); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        __auto_type xs = ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (test_mk_iri(SLOP_STR("b"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (test_mk_iri(SLOP_STR("a"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (test_mk_iri(SLOP_STR("b"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (test_mk_iri(SLOP_STR("c"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (test_mk_iri(SLOP_STR("a"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                __auto_type r = test_test_stub_refuses_rather_than_passing(arena);
                test_print_test_result(SLOP_STR("stub: classify refuses, never passes"), r);
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
                test_print_test_result(SLOP_STR("gate: all 17 v0 fixtures gate CLEAN (false-fail half)"), r);
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
                test_print_test_result(SLOP_STR("range: all 8 rows of §5.2's verdict table"), r);
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
            printf("%s\n", "");
            printf("%s\n", "========================================");
            printf("%s", "Passed: ");
            printf("%.*s\n", (int)(int_to_string(arena, passed)).len, (int_to_string(arena, passed)).data);
            printf("%s", "Failed: ");
            printf("%.*s\n", (int)(int_to_string(arena, failed)).len, (int_to_string(arena, failed)).data);
            printf("%s\n", "========================================");
            if (failed == 0) {
                return 0;
            } else {
                return 1;
            }
        }
        slop_arena_free(arena);
    }
}

