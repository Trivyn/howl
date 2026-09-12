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
uint8_t test_test_sort_is_stable(slop_arena* arena);
uint8_t test_test_sort_is_a_permutation(slop_arena* arena);
void test_print_test_result(slop_string name, uint8_t passed);
int main(int argc, char** _c_argv);

static int64_t test__lambda_150(void* _env, int64_t a, int64_t b) { return ({ __auto_type ka = (2 - (a / 3)); __auto_type kb = (2 - (b / 3)); ((ka < kb) ? -1 : ((ka > kb) ? 1 : 0)); }); }

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
    __auto_type _mv_138 = n;
    switch (_mv_138.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_138.data.class_node;
            return i.value;
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_138.data.individual_node;
            return i.value;
        }
        case types_Node_fresh_node:
        {
            __auto_type _ = _mv_138.data.fresh_node;
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
    __auto_type _mv_139 = howl_classify(arena, ((slop_list_rdf_Triple){ .data = (rdf_Triple*)slop_arena_alloc(arena, 16 * sizeof(rdf_Triple)), .len = 0, .cap = 16 }), ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 }), howl_default_config());
    if (_mv_139.is_ok) {
        __auto_type _ = _mv_139.data.ok;
        return 0;
    } else if (!_mv_139.is_ok) {
        __auto_type _ = _mv_139.data.err;
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
    __auto_type _mv_140 = test_run_fixture(arena, test_litmus_signature(arena), test_litmus_axioms(arena, correct_polarity));
    if (_mv_140.is_ok) {
        __auto_type r = _mv_140.data.ok;
        {
            __auto_type f = classify_extract_findings(arena, r.saturation);
            return classify_entails_sub(r.saturation, f.inconsistent, test_cls(SLOP_STR("http://example.org/Mother")), test_cls(SLOP_STR("http://example.org/Parent")));
        }
    } else if (!_mv_140.is_ok) {
        __auto_type _ = _mv_140.data.err;
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
        __auto_type _mv_141 = test_run_fixture(arena, sig, ax);
        if (_mv_141.is_ok) {
            __auto_type r = _mv_141.data.ok;
            __auto_type _mv_142 = r.termination;
            switch (_mv_142.tag) {
                case types_Termination_fixpoint:
                {
                    return 1;
                }
                case types_Termination_resource_limit:
                {
                    __auto_type _ = _mv_142.data.resource_limit;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_141.is_ok) {
            __auto_type _ = _mv_141.data.err;
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
        __auto_type _mv_143 = test_run_fixture(arena, sig, ax);
        if (_mv_143.is_ok) {
            __auto_type res = _mv_143.data.ok;
            {
                __auto_type fi = classify_extract_findings(arena, res.saturation);
                return classify_entails_sub(res.saturation, fi.inconsistent, e, h);
            }
        } else if (!_mv_143.is_ok) {
            __auto_type _ = _mv_143.data.err;
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
        __auto_type _mv_144 = test_run_fixture(arena, sig, ax);
        if (_mv_144.is_ok) {
            __auto_type res = _mv_144.data.ok;
            {
                __auto_type fi = classify_extract_findings(arena, res.saturation);
                return classify_entails_sub(res.saturation, fi.inconsistent, e, h);
            }
        } else if (!_mv_144.is_ok) {
            __auto_type _ = _mv_144.data.err;
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
    __auto_type _mv_145 = test_unsat_fixture(arena);
    if (_mv_145.is_ok) {
        __auto_type r = _mv_145.data.ok;
        {
            __auto_type f = classify_extract_findings(arena, r.saturation);
            if (((int64_t)((f.unsatisfiable).len)) == 1) {
                return types_findings_are_incoherent(f);
            } else {
                return 0;
            }
        }
    } else if (!_mv_145.is_ok) {
        __auto_type _ = _mv_145.data.err;
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t test_test_bottom_compression(slop_arena* arena) {
    __auto_type _mv_146 = test_unsat_fixture(arena);
    if (_mv_146.is_ok) {
        __auto_type r = _mv_146.data.ok;
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
    } else if (!_mv_146.is_ok) {
        __auto_type _ = _mv_146.data.err;
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
        __auto_type _mv_147 = test_run_fixture(arena, sig, ax);
        if (_mv_147.is_ok) {
            __auto_type r = _mv_147.data.ok;
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
        } else if (!_mv_147.is_ok) {
            __auto_type _ = _mv_147.data.err;
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
        __auto_type _mv_148 = test_run_fixture(arena, fwd, ax);
        if (_mv_148.is_ok) {
            __auto_type r1 = _mv_148.data.ok;
            __auto_type _mv_149 = test_run_fixture(arena, rev, ax);
            if (_mv_149.is_ok) {
                __auto_type r2 = _mv_149.data.ok;
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
            } else if (!_mv_149.is_ok) {
                __auto_type _ = _mv_149.data.err;
                return 0;
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_148.is_ok) {
            __auto_type _ = _mv_148.data.err;
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

uint8_t test_test_sort_is_stable(slop_arena* arena) {
    {
        __auto_type idx = canon_sort_range(arena, 9, (slop_closure_t){(void*)test__lambda_150, NULL});
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

