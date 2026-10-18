#include "../runtime/slop_runtime.h"
#include "slop_howl.h"

slop_result_howl_normalize_Decoded_howl_types_Fault howl_decode(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved);
slop_result_howl_normalize_Decoded_howl_types_Fault howl_decode_from(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved);
slop_result_howl_normalize_Decoded_howl_types_Fault howl_own_decoded(slop_arena* arena, slop_result_howl_normalize_Decoded_howl_types_Fault r);
slop_result_howl_normalize_Decoded_howl_types_Fault howl_decode_owned(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved);
slop_result_howl_Prepared_howl_types_Fault howl_prepare_decoded(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config);
howl_Prepared howl_with_step_down(slop_arena* arena, howl_Prepared p, howl_normalize_Decoded d, howl_types_Profile low);
int64_t howl_out_of_profile_count(slop_list_howl_types_Omission oms);
howl_AutoChoice howl_auto_profile(howl_normalize_Decoded d);
int64_t howl_rung_count(slop_arena* scratch, howl_normalize_Decoded d, howl_types_Profile p);
slop_result_howl_Prepared_howl_types_Fault howl_prepare_in_profile(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config, howl_types_Profile profile);
slop_result_howl_Prepared_howl_types_Fault howl_prepare_sourced(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config, howl_types_Profile profile);
uint8_t howl_strict_refuses(howl_types_ReasonerConfig config, howl_types_Coverage cov);
slop_result_howl_Prepared_howl_types_Fault howl_prepare_el(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config, howl_types_Profile profile);
slop_result_howl_Prepared_howl_types_Fault howl_prepare_ksc(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config, howl_types_Profile profile);
slop_result_howl_Prepared_howl_types_Fault howl_prepare_sriq(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config, howl_types_Profile profile);
slop_result_howl_Prepared_howl_types_Fault howl_sriq_prepared(slop_arena* arena, howl_types_ReasonerConfig config, howl_types_Profile profile, slop_list_howl_types_Omission gate_oms, slop_list_howl_types_OmissionCause gate_causes, howl_sriqabox_Inputs in);
howl_types_Coverage howl_sriq_coverage(slop_arena* arena, slop_list_howl_types_Omission gate_oms, slop_list_howl_types_OmissionCause gate_causes, slop_list_howl_owl2_RawAxiom s1);
howl_sriqref_RefIn howl_copy_refin(slop_arena* arena, howl_sriqref_RefIn in);
slop_list_slop_rdf_rdf_IRI howl_query_iris(slop_arena* arena, howl_sriqclauses_SriqIds ids);
slop_list_howl_types_KName howl_copy_knames(slop_arena* arena, slop_list_howl_types_KName ns);
slop_result_howl_Prepared_howl_types_Fault howl_prepare(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config);
slop_result_howl_types_Outcome_howl_types_Fault howl_reason(slop_arena* arena, howl_Prepared p, howl_types_ReasonerConfig config);
slop_result_howl_types_Outcome_howl_types_Fault howl_sriq_reason(slop_arena* arena, howl_Prepared p, howl_SriqWork w, howl_types_ReasonerConfig config);
uint8_t howl_steps_down(howl_sriqabox_SplitRun sp, howl_types_Outcome o);
uint8_t howl_over_budget(howl_sriqref_RefStatus s);
slop_result_howl_types_Outcome_howl_types_Fault howl_step_down(slop_arena* arena, howl_StepDown s, howl_types_ReasonerConfig config);
howl_types_Outcome howl_stepped(slop_arena* arena, howl_types_Outcome o);
howl_types_Outcome howl_sriq_outcome(slop_arena* arena, howl_Prepared p, howl_SriqWork w, howl_sriqabox_SplitRun sp);
slop_result_howl_types_Outcome_howl_types_Fault howl_classify(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config);
void howl_release_outcome(howl_types_Outcome o);
slop_result_howl_Prepared_howl_types_Fault howl_prepare_encoded(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config);
slop_result_howl_ModulePrepared_howl_types_Fault howl_prepare_encoded_within(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config, uint8_t modular, slop_list_slop_rdf_rdf_IRI seed);
slop_result_howl_ModulePrepared_howl_types_Fault howl_prepare_module(slop_arena* arena, slop_arena* held, howl_normalize_Decoded m, howl_types_ReasonerConfig config, uint8_t modular);
slop_list_howl_types_Profile howl_answer_rungs(slop_arena* arena, howl_types_ProfileSelection selection);
howl_normalize_Decoded howl_within_seed(slop_arena* held, howl_normalize_Decoded d, uint8_t modular, slop_list_slop_rdf_rdf_IRI seed);
slop_result_howl_types_Outcome_howl_types_Fault howl_classify_encoded(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config);
slop_result_howl_probe_Probing_howl_types_Fault howl_probe_encoded(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, slop_list_howl_probe_Query queries, howl_types_ReasonerConfig config, uint8_t modular);
slop_result_howl_types_Outcome_howl_types_Fault howl_probe_classified(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config, uint8_t modular, slop_list_howl_probe_Query queries);
howl_types_ReasonerConfig howl_module_budget(howl_types_ReasonerConfig config, uint8_t omits);
slop_result_howl_types_Outcome_howl_types_Fault howl_module_or_whole(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config, int64_t gated, slop_result_howl_types_Outcome_howl_types_Fault m);
uint8_t howl_at_fixpoint(howl_types_Termination t);
slop_result_howl_types_Outcome_howl_types_Fault howl_classify_within(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config, uint8_t modular, slop_list_slop_rdf_rdf_IRI seed);
slop_list_slop_rdf_rdf_IRI howl_query_seed(slop_arena* arena, slop_list_howl_probe_Query queries);
slop_result_howl_probe_Probing_howl_types_Fault howl_probe_outcome(slop_arena* arena, slop_result_howl_types_Outcome_howl_types_Fault r, slop_list_howl_probe_Query queries);
howl_probe_Probing howl_probing_of(slop_arena* arena, howl_types_Outcome o, slop_list_howl_probe_Query queries);
howl_probe_Probing howl_no_probing(slop_arena* arena);
slop_list_int howl_copy_origins(slop_arena* arena, slop_list_int xs);
howl_InputState* howl_input_state(howl_Input in);
howl_RunState howl_run_state(howl_Run r);
howl_Input howl_input_new(void);
void howl_input_free(howl_Input in);
void howl_input_begin_document(howl_Input in);
void howl_input_begin_probe_document(howl_Input in);
howl_termstore_Encoded* howl_target(howl_InputState st, uint8_t probe);
void howl_begin_in(howl_Input in, uint8_t probe);
slop_option_string howl_optional_string(slop_string s);
slop_option_slop_rdf_rdf_Term howl_make_term(slop_arena* arena, howl_TermIn t);
uint8_t howl_input_add_triple(howl_Input in, howl_TermIn s, howl_TermIn p, howl_TermIn o);
uint8_t howl_input_add_probe_triple(howl_Input in, howl_TermIn s, howl_TermIn p, howl_TermIn o);
uint8_t howl_add_triple_to(howl_Input in, uint8_t probe, howl_TermIn s, howl_TermIn p, howl_TermIn o);
howl_TurtleResult howl_input_add_turtle(howl_Input in, slop_string text);
howl_TurtleResult howl_input_add_probe_turtle(howl_Input in, slop_string text);
howl_TurtleResult howl_add_turtle_to(howl_Input in, uint8_t probe, slop_string text);
void howl_input_attest_import(howl_Input in, slop_string iri);
void howl_input_ask_unsatisfiable(howl_Input in, slop_string cls);
void howl_input_ask_subsumed(howl_Input in, slop_string sub, slop_string sup);
void howl_ask(howl_Input in, howl_probe_QueryKind kind, slop_string sub, slop_string sup);
howl_Options howl_default_options(void);
slop_option_string howl_options_problem(howl_Options o);
howl_types_ReasonerConfig howl_options_config(howl_Options o);
howl_Run howl_new_run(slop_arena* a, howl_RunState st);
howl_Run howl_faulted(slop_arena* a, howl_FaultKind kind, slop_string message, howl_types_Profile profile);
howl_Run howl_run_classify(howl_Input in, howl_Options o);
howl_Run howl_run_faulted(slop_arena* a, howl_types_Fault f, slop_string prefix, howl_types_Profile profile);
slop_result_howl_probe_Probing_howl_types_Fault howl_probe_run(slop_arena* a, howl_InputState st, howl_Options o, uint8_t modular);
howl_Run howl_with_probes(slop_arena* a, howl_InputState st, howl_types_Outcome out, howl_Options o);
howl_Run howl_run_answer(howl_Input in, howl_Options o);
howl_Run howl_answer_of_input(slop_arena* a, howl_InputState st, howl_Options o);
howl_Run howl_answered(slop_arena* a, howl_probe_Probing p, uint8_t ran);
howl_Run howl_finished(slop_arena* a, howl_types_Outcome out, howl_probe_Probing p, uint8_t asked);
void howl_run_free(howl_Run r);
uint8_t howl_run_ok(howl_Run r);
howl_FaultKind howl_run_fault(howl_Run r);
slop_string howl_run_fault_message(howl_Run r);
howl_types_Profile howl_run_fault_profile(howl_Run r);
howl_types_Profile howl_run_profile(howl_Run r);
howl_types_Verdict howl_run_verdict(howl_Run r);
uint8_t howl_run_inconsistent(howl_Run r);
howl_types_Termination howl_run_termination(howl_Run r);
int64_t howl_run_rounds(howl_Run r);
int64_t howl_run_unsat_len(howl_Run r);
slop_string howl_run_unsat(howl_Run r, int64_t i);
int64_t howl_run_sub_len(howl_Run r);
slop_string howl_run_sub(howl_Run r, int64_t i);
slop_string howl_run_super(howl_Run r, int64_t i);
int64_t howl_run_omission_len(howl_Run r);
slop_string howl_run_omission(howl_Run r, int64_t i);
slop_string howl_omission_kind(slop_arena* arena, howl_types_Omission om);
howl_types_EntityKind howl_omission_entity_kind(howl_types_Omission om);
int64_t howl_origin_at(slop_list_int origins, int64_t i);
slop_string howl_run_omission_kind(howl_Run r, int64_t i);
howl_types_EntityKind howl_run_omission_entity_kind(howl_Run r, int64_t i);
int64_t howl_run_omission_document(howl_Run r, int64_t i);
howl_types_OmissionCause howl_omission_cause(slop_list_howl_types_Omission oms, slop_list_howl_types_OmissionCause causes, int64_t i);
howl_types_OmissionReason howl_run_omission_reason(howl_Run r, int64_t i);
slop_string howl_run_omission_reason_role(howl_Run r, int64_t i);
int64_t howl_run_probe_len(howl_Run r);
slop_option_howl_probe_Answered howl_probe_at(howl_Run r, int64_t i);
howl_probe_QueryKind howl_run_probe_kind(howl_Run r, int64_t i);
slop_string howl_run_probe_sub(howl_Run r, int64_t i);
slop_string howl_run_probe_sup(howl_Run r, int64_t i);
howl_probe_ProbeAnswer howl_run_probe_answer(howl_Run r, int64_t i);
uint8_t howl_run_probe_inconsistent(howl_Run r);
int64_t howl_run_probe_omission_len(howl_Run r);
slop_string howl_run_probe_omission(howl_Run r, int64_t i);
slop_string howl_run_probe_omission_kind(howl_Run r, int64_t i);
howl_types_EntityKind howl_run_probe_omission_entity_kind(howl_Run r, int64_t i);
howl_types_OmissionReason howl_run_probe_omission_reason(howl_Run r, int64_t i);
slop_string howl_run_probe_omission_reason_role(howl_Run r, int64_t i);
int64_t howl_probe_origin(howl_probe_Probing p, int64_t i);
howl_DocumentSource howl_run_probe_omission_source(howl_Run r, int64_t i);
int64_t howl_run_probe_omission_document(howl_Run r, int64_t i);
int64_t howl_run_report_len(howl_Run r);
slop_string howl_run_report_line(howl_Run r, int64_t i);

typedef struct { slop_arena* arena; howl_termstore_Encoded* enc; } howl__lambda_1688_env_t;

static void howl__lambda_1688(howl__lambda_1688_env_t* _env, slop_rdf_rdf_Triple t) { howl_termstore_encoded_add(_env->arena, _env->enc, t); }

slop_result_howl_normalize_Decoded_howl_types_Fault howl_decode(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved) {
    return howl_normalize_decode_document(arena, triples, imports_resolved);
}

slop_result_howl_normalize_Decoded_howl_types_Fault howl_decode_from(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved) {
    return howl_normalize_decode_encoded(arena, doc, imports_resolved);
}

slop_result_howl_normalize_Decoded_howl_types_Fault howl_own_decoded(slop_arena* arena, slop_result_howl_normalize_Decoded_howl_types_Fault r) {
    __auto_type _mv_1662 = r;
    if (_mv_1662.is_ok) {
        __auto_type d = _mv_1662.data.ok;
        return ((slop_result_howl_normalize_Decoded_howl_types_Fault){ .is_ok = true, .data.ok = howl_normalize_copy_decoded(arena, d) });
    } else if (!_mv_1662.is_ok) {
        __auto_type f = _mv_1662.data.err;
        return ((slop_result_howl_normalize_Decoded_howl_types_Fault){ .is_ok = false, .data.err = howl_types_copy_fault(arena, f) });
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_normalize_Decoded_howl_types_Fault howl_decode_owned(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved) {
    {
        __auto_type front = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type res = howl_own_decoded(arena, howl_decode(front, triples, imports_resolved));
        (void)(({ slop_arena_free(front); free(front); }));
        return res;
    }
}

slop_result_howl_Prepared_howl_types_Fault howl_prepare_decoded(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config) {
    __auto_type _mv_1663 = howl_select_select_profile(config.selection);
    if (_mv_1663.has_value) {
        __auto_type profile = _mv_1663.value;
        if (!(howl_select_profile_implemented(profile))) {
            return ((slop_result_howl_Prepared_howl_types_Fault){ .is_ok = false, .data.err = ((howl_types_Fault){ .tag = howl_types_Fault_unavailable, .data.unavailable = profile }) });
        } else {
            return howl_prepare_sourced(arena, d, config, profile);
        }
    } else if (!_mv_1663.has_value) {
        {
            __auto_type ch = howl_auto_profile(d);
            __auto_type _mv_1664 = howl_prepare_sourced(arena, d, config, ch.profile);
            if (_mv_1664.is_ok) {
                __auto_type p = _mv_1664.data.ok;
                return ((slop_result_howl_Prepared_howl_types_Fault){ .is_ok = true, .data.ok = howl_with_step_down(arena, p, d, ch.low) });
            } else if (!_mv_1664.is_ok) {
                __auto_type f = _mv_1664.data.err;
                return ((slop_result_howl_Prepared_howl_types_Fault){ .is_ok = false, .data.err = f });
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

howl_Prepared howl_with_step_down(slop_arena* arena, howl_Prepared p, howl_normalize_Decoded d, howl_types_Profile low) {
    __auto_type _mv_1665 = p.work;
    switch (_mv_1665.tag) {
        case howl_Work_sriq_work:
        {
            __auto_type w = _mv_1665.data.sriq_work;
            return ((howl_Prepared){.profile = p.profile, .work = ((howl_Work){ .tag = howl_Work_sriq_work, .data.sriq_work = ((howl_SriqWork){.h = w.h, .c = w.c, .has_c = w.has_c, .classes = w.classes, .step = (slop_option_howl_StepDown){.has_value = 1, .value = ((howl_StepDown){.profile = low, .decoded = howl_normalize_copy_decoded(arena, d)})}}) }), .coverage = p.coverage, .names = p.names});
        }
        default: {
            return p;
        }
    }
}

int64_t howl_out_of_profile_count(slop_list_howl_types_Omission oms) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = oms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                __auto_type _mv_1666 = o;
                switch (_mv_1666.tag) {
                    case howl_types_Omission_out_of_profile:
                    {
                        __auto_type _ = _mv_1666.data.out_of_profile;
                        n = (n + 1);
                        break;
                    }
                    case howl_types_Omission_unresolved_import:
                    {
                        __auto_type _ = _mv_1666.data.unresolved_import;
                        break;
                    }
                    case howl_types_Omission_missing_declaration:
                    {
                        __auto_type _ = _mv_1666.data.missing_declaration;
                        break;
                    }
                    case howl_types_Omission_undeclared_property:
                    {
                        __auto_type _ = _mv_1666.data.undeclared_property;
                        break;
                    }
                }
            }
        }
        return n;
    }
}

howl_AutoChoice howl_auto_profile(howl_normalize_Decoded d) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type out_el = howl_rung_count(scratch, d, howl_types_Profile_profile_el);
        __auto_type out_pp = (((out_el == 0)) ? 0 : howl_rung_count(scratch, d, howl_types_Profile_profile_el_plus_plus));
        __auto_type out_sq = (((out_pp == 0)) ? 0 : howl_rung_count(scratch, d, howl_types_Profile_profile_sriq));
        __auto_type chosen = ((howl_AutoChoice){.profile = howl_select_choose_auto(((int64_t)(SLOP_RANGE(int64_t, out_el, 1, 0, 0, 0, "(Int 0 ..) at howl.slop:333:61"))), ((int64_t)(SLOP_RANGE(int64_t, out_pp, 1, 0, 0, 0, "(Int 0 ..) at howl.slop:333:86"))), ((int64_t)(SLOP_RANGE(int64_t, out_sq, 1, 0, 0, 0, "(Int 0 ..) at howl.slop:333:111")))), .low = howl_select_choose_auto_low(((int64_t)(SLOP_RANGE(int64_t, out_el, 1, 0, 0, 0, "(Int 0 ..) at howl.slop:334:65"))), ((int64_t)(SLOP_RANGE(int64_t, out_pp, 1, 0, 0, 0, "(Int 0 ..) at howl.slop:334:90"))))});
        (void)(({ slop_arena_free(scratch); free(scratch); }));
        return chosen;
    }
}

int64_t howl_rung_count(slop_arena* scratch, howl_normalize_Decoded d, howl_types_Profile p) {
    return howl_out_of_profile_count(howl_gate_gate_axioms(scratch, d.axioms, d.signature, d.omissions, p).omissions);
}

slop_result_howl_Prepared_howl_types_Fault howl_prepare_in_profile(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config, howl_types_Profile profile) {
    __auto_type _mv_1667 = profile;
    if (_mv_1667 == howl_types_Profile_profile_el_plus_plus) {
        return howl_prepare_ksc(arena, d, config, profile);
    } else if (_mv_1667 == howl_types_Profile_profile_el) {
        return howl_prepare_el(arena, d, config, profile);
    } else if (_mv_1667 == howl_types_Profile_profile_horn_sriq) {
        return howl_prepare_el(arena, d, config, profile);
    } else if (_mv_1667 == howl_types_Profile_profile_sriq) {
        return howl_prepare_sriq(arena, d, config, profile);
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_Prepared_howl_types_Fault howl_prepare_sourced(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config, howl_types_Profile profile) {
    __auto_type _mv_1668 = howl_prepare_in_profile(arena, d, config, profile);
    if (_mv_1668.is_ok) {
        __auto_type p = _mv_1668.data.ok;
        {
            __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
            __auto_type gp = ({ __auto_type _mv = p.profile; int _mi = (_mv == howl_types_Profile_profile_el_plus_plus) ? 1 : (_mv == howl_types_Profile_profile_sriq) ? 2 : (_mv == howl_types_Profile_profile_el) ? 3 : (_mv == howl_types_Profile_profile_horn_sriq) ? 4 : 0; if (!_mi) { SLOP_UNREACHABLE(); } _mi == 1 ? (howl_types_Profile_profile_el_plus_plus) : _mi == 2 ? (howl_types_Profile_profile_sriq) : _mi == 3 ? (howl_types_Profile_profile_el) : (howl_types_Profile_profile_el); });
            __auto_type origins = howl_gate_omission_origins(arena, scratch, p.coverage.omitted, d.axioms, d.axiom_docs, d.omissions, d.omission_docs, d.documents, gp);
            ({ slop_arena_free(scratch); free(scratch); });
            return ((slop_result_howl_Prepared_howl_types_Fault){ .is_ok = true, .data.ok = ((howl_Prepared){.profile = p.profile, .work = p.work, .coverage = ((howl_types_Coverage){.omitted = p.coverage.omitted, .origins = origins, .reasons = p.coverage.reasons}), .names = p.names}) });
        }
    } else if (!_mv_1668.is_ok) {
        __auto_type f = _mv_1668.data.err;
        return ((slop_result_howl_Prepared_howl_types_Fault){ .is_ok = false, .data.err = f });
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_strict_refuses(howl_types_ReasonerConfig config, howl_types_Coverage cov) {
    if (config.strict_profile) {
        return (((int64_t)((cov.omitted).len)) > 0);
    } else {
        return 0;
    }
}

slop_result_howl_Prepared_howl_types_Fault howl_prepare_el(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config, howl_types_Profile profile) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type nr = howl_normalize_normalize_decoded(arena, scratch, d);
        __auto_type res = ((howl_strict_refuses(config, nr.coverage)) ? ((slop_result_howl_Prepared_howl_types_Fault){ .is_ok = false, .data.err = ((howl_types_Fault){ .tag = howl_types_Fault_refused, .data.refused = nr.coverage.omitted }) }) : ((slop_result_howl_Prepared_howl_types_Fault){ .is_ok = true, .data.ok = ((howl_Prepared){.profile = profile, .work = ((howl_Work){ .tag = howl_Work_el_work, .data.el_work = ((howl_ElWork){.axioms = nr.axioms, .index = howl_premise_build_rule_index(arena, nr.axioms), .saturation = nr.saturation}) }), .coverage = nr.coverage, .names = nr.names}) }));
        (void)(({ slop_arena_free(scratch); free(scratch); }));
        return res;
    }
}

slop_result_howl_Prepared_howl_types_Fault howl_prepare_ksc(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config, howl_types_Profile profile) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type gr = howl_gate_gate_axioms(scratch, d.axioms, d.signature, d.omissions, howl_types_Profile_profile_el_plus_plus);
        __auto_type cov = ((howl_types_Coverage){.omitted = howl_types_copy_omissions(arena, gr.omissions), .origins = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .reasons = howl_types_copy_causes(arena, gr.reasons)});
        __auto_type res = ((howl_strict_refuses(config, cov)) ? ((slop_result_howl_Prepared_howl_types_Fault){ .is_ok = false, .data.err = ((howl_types_Fault){ .tag = howl_types_Fault_refused, .data.refused = cov.omitted }) }) : ((slop_result_howl_Prepared_howl_types_Fault){ .is_ok = true, .data.ok = ((howl_Prepared){.profile = profile, .work = ((howl_Work){ .tag = howl_Work_ksc_work, .data.ksc_work = ((howl_KscWork){.axioms = howl_kscnormal_copy_ksc_axioms(arena, howl_kscnormal_normalize_ksc(scratch, gr.accepted).axioms), .classes = howl_copy_knames(arena, howl_kscsat_input_classes(scratch, gr.signature))}) }), .coverage = cov, .names = howl_types_empty_names(arena)}) }));
        (void)(({ slop_arena_free(scratch); free(scratch); }));
        return res;
    }
}

slop_result_howl_Prepared_howl_types_Fault howl_prepare_sriq(slop_arena* arena, howl_normalize_Decoded d, howl_types_ReasonerConfig config, howl_types_Profile profile) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type gr = howl_gate_gate_axioms(scratch, d.axioms, d.signature, d.omissions, howl_types_Profile_profile_sriq);
        __auto_type res = ({ __auto_type _mv = howl_sriqabox_split_inputs(scratch, gr); slop_result_howl_Prepared_howl_types_Fault _mr; if (_mv.is_ok) { __auto_type in = _mv.data.ok; _mr = howl_sriq_prepared(arena, config, profile, gr.omissions, gr.reasons, in); } else { __auto_type m = _mv.data.err; _mr = ((slop_result_howl_Prepared_howl_types_Fault){ .is_ok = false, .data.err = ((howl_types_Fault){ .tag = howl_types_Fault_input_error, .data.input_error = howl_types_copy_string(arena, m) }) }); } _mr; });
        (void)(({ slop_arena_free(scratch); free(scratch); }));
        return res;
    }
}

slop_result_howl_Prepared_howl_types_Fault howl_sriq_prepared(slop_arena* arena, howl_types_ReasonerConfig config, howl_types_Profile profile, slop_list_howl_types_Omission gate_oms, slop_list_howl_types_OmissionCause gate_causes, howl_sriqabox_Inputs in) {
    {
        __auto_type cov = howl_sriq_coverage(arena, gate_oms, gate_causes, in.omitted);
        if (howl_strict_refuses(config, cov)) {
            return ((slop_result_howl_Prepared_howl_types_Fault){ .is_ok = false, .data.err = ((howl_types_Fault){ .tag = howl_types_Fault_refused, .data.refused = cov.omitted }) });
        } else {
            return ((slop_result_howl_Prepared_howl_types_Fault){ .is_ok = true, .data.ok = ((howl_Prepared){.profile = profile, .work = ((howl_Work){ .tag = howl_Work_sriq_work, .data.sriq_work = ((howl_SriqWork){.h = howl_copy_refin(arena, in.h), .c = howl_copy_refin(arena, in.c), .has_c = in.has_c, .classes = howl_query_iris(arena, in.ids), .step = (slop_option_howl_StepDown){.has_value = false}}) }), .coverage = cov, .names = howl_types_empty_names(arena)}) });
        }
    }
}

howl_types_Coverage howl_sriq_coverage(slop_arena* arena, slop_list_howl_types_Omission gate_oms, slop_list_howl_types_OmissionCause gate_causes, slop_list_howl_owl2_RawAxiom s1) {
    {
        __auto_type all = ((slop_list_howl_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type why = ((slop_list_howl_types_OmissionCause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = gate_oms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(all); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = gate_causes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(why); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = s1;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(all); __auto_type _item = (((howl_types_Omission){ .tag = howl_types_Omission_out_of_profile, .data.out_of_profile = howl_gate_axiom_input_ref(arena, a) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(why); __auto_type _item = (howl_types_cause_of(howl_types_OmissionReason_reason_resource_guard)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type idx = howl_canon_omission_order(arena, all);
            __auto_type out = ((slop_list_howl_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            __auto_type cs = ((slop_list_howl_types_OmissionCause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = idx;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type k = _coll.data[_i];
                    {
                        __auto_type o = howl_canon_omission_at(all, k);
                        __auto_type c = howl_gate_cause_at(why, k);
                        __auto_type n = ((int64_t)(((int64_t)((out).len))));
                        __auto_type _mv_1669 = ({ __auto_type _lst = out; size_t _idx = (size_t)(n - 1); slop_option_howl_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                        if (_mv_1669.has_value) {
                            __auto_type last = _mv_1669.value;
                            if (howl_canon_omission_cmp(last, o) != 0) {
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                ({ __auto_type _lst_p = &(cs); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else {
                                if (howl_types_reason_rank(c.reason) < howl_types_reason_rank(howl_gate_cause_at(cs, (n - 1)).reason)) {
                                    ({ __auto_type _set_lst = &(cs); size_t _set_idx = (size_t)((n - 1)); __auto_type _set_val = (c); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
                                }
                            }
                        } else if (!_mv_1669.has_value) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(cs); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
            return ((howl_types_Coverage){.omitted = howl_types_copy_omissions(arena, out), .origins = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .reasons = howl_types_copy_causes(arena, cs)});
        }
    }
}

howl_sriqref_RefIn howl_copy_refin(slop_arena* arena, howl_sriqref_RefIn in) {
    {
        __auto_type hid = ((slop_list_u32){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = in.hidden;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type h = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(hid); __auto_type _item = (h); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ((howl_sriqref_RefIn){.onto = howl_sriqref_copy_clauses(arena, in.onto), .nclass = in.nclass, .nquery = in.nquery, .nrole = in.nrole, .nfn = in.nfn, .nconst = in.nconst, .hidden = hid});
    }
}

slop_list_slop_rdf_rdf_IRI howl_query_iris(slop_arena* arena, howl_sriqclauses_SriqIds ids) {
    {
        __auto_type out = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t b = 0;
        {
            __auto_type _coll = ids.class_of;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                if (b < ids.nclass) {
                    __auto_type _mv_1670 = n;
                    switch (_mv_1670.tag) {
                        case howl_types_DName_dn_class:
                        {
                            __auto_type i = _mv_1670.data.dn_class;
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_types_copy_iri(arena, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        case howl_types_DName_dn_fresh:
                        {
                            __auto_type _ = _mv_1670.data.dn_fresh;
                            break;
                        }
                    }
                }
                b = (b + 1);
            }
        }
        return out;
    }
}

slop_list_howl_types_KName howl_copy_knames(slop_arena* arena, slop_list_howl_types_KName ns) {
    {
        __auto_type out = ((slop_list_howl_types_KName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_kscnormal_copy_kname(arena, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_result_howl_Prepared_howl_types_Fault howl_prepare(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config) {
    {
        __auto_type held = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type res = ({ __auto_type _mv = howl_decode_owned(held, triples, imports_resolved); slop_result_howl_Prepared_howl_types_Fault _mr; if (_mv.is_ok) { __auto_type d = _mv.data.ok; _mr = howl_prepare_decoded(arena, d, config); } else { __auto_type f = _mv.data.err; _mr = ((slop_result_howl_Prepared_howl_types_Fault){ .is_ok = false, .data.err = howl_types_copy_fault(arena, f) }); } _mr; });
        (void)(({ slop_arena_free(held); free(held); }));
        return res;
    }
}

slop_result_howl_types_Outcome_howl_types_Fault howl_reason(slop_arena* arena, howl_Prepared p, howl_types_ReasonerConfig config) {
    __auto_type _mv_1671 = p.work;
    switch (_mv_1671.tag) {
        case howl_Work_el_work:
        {
            __auto_type w = _mv_1671.data.el_work;
            __auto_type _mv_1672 = howl_saturate_saturate(arena, w.saturation, w.index, config);
            if (!_mv_1672.is_ok) {
                __auto_type f = _mv_1672.data.err;
                return ((slop_result_howl_types_Outcome_howl_types_Fault){ .is_ok = false, .data.err = f });
            } else if (_mv_1672.is_ok) {
                __auto_type rr = _mv_1672.data.ok;
                return ((slop_result_howl_types_Outcome_howl_types_Fault){ .is_ok = true, .data.ok = ((howl_types_Outcome){.profile = p.profile, .coverage = p.coverage, .termination = rr.termination, .findings = howl_classify_extract_findings(arena, rr.saturation, p.names), .evidence = ((howl_types_Evidence){ .tag = howl_types_Evidence_el_evidence, .data.el_evidence = rr.saturation }), .rounds = rr.saturation.iteration, .names = p.names, .owned = rr.arenas, .stepped_down = 0}) });
            }
            SLOP_UNREACHABLE();
        }
        case howl_Work_ksc_work:
        {
            __auto_type w = _mv_1671.data.ksc_work;
            __auto_type _mv_1673 = howl_kscsat_ksc_classify(arena, w.axioms, w.classes, config);
            if (!_mv_1673.is_ok) {
                __auto_type f = _mv_1673.data.err;
                return ((slop_result_howl_types_Outcome_howl_types_Fault){ .is_ok = false, .data.err = f });
            } else if (_mv_1673.is_ok) {
                __auto_type r = _mv_1673.data.ok;
                return ((slop_result_howl_types_Outcome_howl_types_Fault){ .is_ok = true, .data.ok = ((howl_types_Outcome){.profile = p.profile, .coverage = p.coverage, .termination = r.termination, .findings = howl_classify_extract_ksc_findings(arena, r), .evidence = ((howl_types_Evidence){ .tag = howl_types_Evidence_ksc_evidence, .data.ksc_evidence = r }), .rounds = r.rounds, .names = p.names, .owned = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .stepped_down = 0}) });
            }
            SLOP_UNREACHABLE();
        }
        case howl_Work_sriq_work:
        {
            __auto_type w = _mv_1671.data.sriq_work;
            return howl_sriq_reason(arena, p, w, config);
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_types_Outcome_howl_types_Fault howl_sriq_reason(slop_arena* arena, howl_Prepared p, howl_SriqWork w, howl_types_ReasonerConfig config) {
    {
        __auto_type sp = howl_sriqabox_split_run_of(arena, w.h, w.c, w.has_c, 0, howl_sriqabox_sriq_config(((int64_t)(config.max_iterations)), ((int64_t)(config.clause_budget)), config.cancel_ptr));
        if (sp.cancelled) {
            return ((slop_result_howl_types_Outcome_howl_types_Fault){ .is_ok = false, .data.err = ((howl_types_Fault){ .tag = howl_types_Fault_cancelled }) });
        } else {
            {
                __auto_type o = howl_sriq_outcome(arena, p, w, sp);
                __auto_type _mv_1674 = w.step;
                if (_mv_1674.has_value) {
                    __auto_type s = _mv_1674.value;
                    if (howl_steps_down(sp, o)) {
                        return howl_step_down(arena, s, config);
                    } else {
                        return ((slop_result_howl_types_Outcome_howl_types_Fault){ .is_ok = true, .data.ok = o });
                    }
                } else if (!_mv_1674.has_value) {
                    return ((slop_result_howl_types_Outcome_howl_types_Fault){ .is_ok = true, .data.ok = o });
                }
                SLOP_UNREACHABLE();
            }
        }
    }
}

uint8_t howl_steps_down(howl_sriqabox_SplitRun sp, howl_types_Outcome o) {
    return ((howl_over_budget(sp.h.res.status) || (sp.ran_c && howl_over_budget(sp.c.res.status))) && !(howl_types_findings_are_incoherent(o.findings)));
}

uint8_t howl_over_budget(howl_sriqref_RefStatus s) {
    return ((s == howl_sriqref_RefStatus_rs_clauses) || (s == howl_sriqref_RefStatus_rs_product));
}

slop_result_howl_types_Outcome_howl_types_Fault howl_step_down(slop_arena* arena, howl_StepDown s, howl_types_ReasonerConfig config) {
    __auto_type _mv_1675 = howl_prepare_sourced(arena, s.decoded, config, s.profile);
    if (_mv_1675.is_ok) {
        __auto_type lp = _mv_1675.data.ok;
        __auto_type _mv_1676 = howl_reason(arena, lp, config);
        if (_mv_1676.is_ok) {
            __auto_type o = _mv_1676.data.ok;
            return ((slop_result_howl_types_Outcome_howl_types_Fault){ .is_ok = true, .data.ok = howl_stepped(arena, o) });
        } else if (!_mv_1676.is_ok) {
            __auto_type f = _mv_1676.data.err;
            return ((slop_result_howl_types_Outcome_howl_types_Fault){ .is_ok = false, .data.err = f });
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_1675.is_ok) {
        __auto_type f = _mv_1675.data.err;
        return ((slop_result_howl_types_Outcome_howl_types_Fault){ .is_ok = false, .data.err = f });
    }
    SLOP_UNREACHABLE();
}

howl_types_Outcome howl_stepped(slop_arena* arena, howl_types_Outcome o) {
    return ((howl_types_Outcome){.profile = o.profile, .coverage = o.coverage, .termination = o.termination, .findings = o.findings, .evidence = o.evidence, .rounds = o.rounds, .names = o.names, .owned = o.owned, .stepped_down = 1});
}

howl_types_Outcome howl_sriq_outcome(slop_arena* arena, howl_Prepared p, howl_SriqWork w, howl_sriqabox_SplitRun sp) {
    return ((howl_types_Outcome){.profile = p.profile, .coverage = p.coverage, .termination = ((sp.finished) ? ((howl_types_Termination){ .tag = howl_types_Termination_fixpoint }) : ((howl_types_Termination){ .tag = howl_types_Termination_resource_limit, .data.resource_limit = ((int64_t)(SLOP_RANGE(int64_t, sp.rounds, 1, 0, 0, 0, "(Int 0 ..) at howl.slop:679:77"))) })), .findings = howl_sriqabox_split_findings(arena, sp.h.res.st, w.classes, sp.inconsistent), .evidence = ((howl_types_Evidence){ .tag = howl_types_Evidence_sriq_evidence, .data.sriq_evidence = ((howl_types_SriqEvidence){.h_rounds = sp.h.res.rounds, .c_rounds = ((sp.ran_c) ? sp.c.res.rounds : 0), .ran_c = sp.ran_c}) }), .rounds = sp.rounds, .names = p.names, .owned = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .stepped_down = 0});
}

slop_result_howl_types_Outcome_howl_types_Fault howl_classify(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config) {
    __auto_type _mv_1677 = howl_prepare(arena, triples, imports_resolved, config);
    if (!_mv_1677.is_ok) {
        __auto_type f = _mv_1677.data.err;
        return ((slop_result_howl_types_Outcome_howl_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_1677.is_ok) {
        __auto_type p = _mv_1677.data.ok;
        return howl_reason(arena, p, config);
    }
    SLOP_UNREACHABLE();
}

void howl_release_outcome(howl_types_Outcome o) {
    {
        __auto_type _coll = o.owned;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type a = _coll.data[_i];
            (void)(({ slop_arena_free(a); free(a); }));
        }
    }
}

slop_result_howl_Prepared_howl_types_Fault howl_prepare_encoded(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config) {
    __auto_type _mv_1678 = howl_prepare_encoded_within(arena, doc, imports_resolved, config, 0, ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
    if (_mv_1678.is_ok) {
        __auto_type mp = _mv_1678.data.ok;
        return ((slop_result_howl_Prepared_howl_types_Fault){ .is_ok = true, .data.ok = mp.prepared });
    } else if (!_mv_1678.is_ok) {
        __auto_type f = _mv_1678.data.err;
        return ((slop_result_howl_Prepared_howl_types_Fault){ .is_ok = false, .data.err = f });
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_ModulePrepared_howl_types_Fault howl_prepare_encoded_within(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config, uint8_t modular, slop_list_slop_rdf_rdf_IRI seed) {
    {
        __auto_type held = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type front = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type d = howl_own_decoded(held, howl_decode_from(front, doc, imports_resolved));
        (void)(({ slop_arena_free(front); free(front); }));
        {
            __auto_type res = ({ __auto_type _mv = d; slop_result_howl_ModulePrepared_howl_types_Fault _mr; if (_mv.is_ok) { __auto_type dd = _mv.data.ok; _mr = howl_prepare_module(arena, held, howl_within_seed(held, dd, modular, seed), config, modular); } else { __auto_type f = _mv.data.err; _mr = ((slop_result_howl_ModulePrepared_howl_types_Fault){ .is_ok = false, .data.err = howl_types_copy_fault(arena, f) }); } _mr; });
            (void)(({ slop_arena_free(held); free(held); }));
            return res;
        }
    }
}

slop_result_howl_ModulePrepared_howl_types_Fault howl_prepare_module(slop_arena* arena, slop_arena* held, howl_normalize_Decoded m, howl_types_ReasonerConfig config, uint8_t modular) {
    __auto_type _mv_1679 = howl_prepare_decoded(arena, m, config);
    if (_mv_1679.is_ok) {
        __auto_type p = _mv_1679.data.ok;
        return ((slop_result_howl_ModulePrepared_howl_types_Fault){ .is_ok = true, .data.ok = ((howl_ModulePrepared){.prepared = p, .shared = ((!(modular)) || ((((int64_t)((p.coverage.omitted).len)) == 0)) || (howl_gate_module_omissions_shared(held, m.axioms, m.omissions, p.coverage.omitted, p.profile, howl_answer_rungs(held, config.selection))))}) });
    } else if (!_mv_1679.is_ok) {
        __auto_type f = _mv_1679.data.err;
        return ((slop_result_howl_ModulePrepared_howl_types_Fault){ .is_ok = false, .data.err = f });
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Profile howl_answer_rungs(slop_arena* arena, howl_types_ProfileSelection selection) {
    {
        __auto_type rs = ((slop_list_howl_types_Profile){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1680 = selection;
        switch (_mv_1680.tag) {
            case howl_types_ProfileSelection_explicit:
            {
                __auto_type p = _mv_1680.data.explicit;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_ProfileSelection_slop_auto:
            {
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (howl_types_Profile_profile_el); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (howl_types_Profile_profile_el_plus_plus); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (howl_types_Profile_profile_sriq); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
        }
        return rs;
    }
}

howl_normalize_Decoded howl_within_seed(slop_arena* held, howl_normalize_Decoded d, uint8_t modular, slop_list_slop_rdf_rdf_IRI seed) {
    if (modular) {
        return howl_locality_module_decoded(held, d, seed);
    } else {
        return d;
    }
}

slop_result_howl_types_Outcome_howl_types_Fault howl_classify_encoded(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config) {
    __auto_type _mv_1681 = howl_prepare_encoded(arena, doc, imports_resolved, config);
    if (!_mv_1681.is_ok) {
        __auto_type f = _mv_1681.data.err;
        return ((slop_result_howl_types_Outcome_howl_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_1681.is_ok) {
        __auto_type p = _mv_1681.data.ok;
        return howl_reason(arena, p, config);
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_probe_Probing_howl_types_Fault howl_probe_encoded(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, slop_list_howl_probe_Query queries, howl_types_ReasonerConfig config, uint8_t modular) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type cfg = config;
        cfg.strict_profile = 0;
        {
            __auto_type res = howl_probe_outcome(arena, howl_probe_classified(scratch, doc, imports_resolved, cfg, modular, queries), queries);
            (void)(({ slop_arena_free(scratch); free(scratch); }));
            return res;
        }
    }
}

slop_result_howl_types_Outcome_howl_types_Fault howl_probe_classified(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config, uint8_t modular, slop_list_howl_probe_Query queries) {
    if (!(modular)) {
        return howl_classify_within(arena, doc, imports_resolved, config, 0, ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
    } else {
        __auto_type _mv_1682 = howl_prepare_encoded_within(arena, doc, imports_resolved, config, 1, howl_query_seed(arena, queries));
        if (!_mv_1682.is_ok) {
            __auto_type f = _mv_1682.data.err;
            return ((slop_result_howl_types_Outcome_howl_types_Fault){ .is_ok = false, .data.err = f });
        } else if (_mv_1682.is_ok) {
            __auto_type mp = _mv_1682.data.ok;
            if (!(mp.shared)) {
                return howl_classify_within(arena, doc, imports_resolved, config, 0, ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
            } else {
                {
                    __auto_type omitted = mp.prepared.coverage.omitted;
                    return howl_module_or_whole(arena, doc, imports_resolved, config, howl_out_of_profile_count(omitted), howl_reason(arena, mp.prepared, howl_module_budget(config, (((int64_t)((omitted).len)) > 0))));
                }
            }
        }
        SLOP_UNREACHABLE();
    }
}

howl_types_ReasonerConfig howl_module_budget(howl_types_ReasonerConfig config, uint8_t omits) {
    {
        __auto_type c = config;
        if (omits) {
            c.clause_budget = ((int64_t)(SLOP_RANGE(int64_t, ((1) > ((((int64_t)(config.clause_budget)) / 10)) ? (1) : ((((int64_t)(config.clause_budget)) / 10))), 1, 0, 1, 0, "(Int 1 ..) at howl.slop:858:50")));
        }
        return c;
    }
}

slop_result_howl_types_Outcome_howl_types_Fault howl_module_or_whole(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config, int64_t gated, slop_result_howl_types_Outcome_howl_types_Fault m) {
    __auto_type _mv_1683 = m;
    if (_mv_1683.is_ok) {
        __auto_type o = _mv_1683.data.ok;
        if ((howl_types_outcome_is_complete(o)) || (o.findings.inconsistent) || (((howl_at_fixpoint(o.termination)) && (!(o.stepped_down)) && ((howl_out_of_profile_count(o.coverage.omitted) == gated))))) {
            return m;
        } else {
            howl_release_outcome(o);
            return howl_classify_within(arena, doc, imports_resolved, config, 0, ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
        }
    } else if (!_mv_1683.is_ok) {
        __auto_type _ = _mv_1683.data.err;
        return m;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_at_fixpoint(howl_types_Termination t) {
    __auto_type _mv_1684 = t;
    switch (_mv_1684.tag) {
        case howl_types_Termination_fixpoint:
        {
            return 1;
        }
        case howl_types_Termination_resource_limit:
        {
            __auto_type _ = _mv_1684.data.resource_limit;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_types_Outcome_howl_types_Fault howl_classify_within(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config, uint8_t modular, slop_list_slop_rdf_rdf_IRI seed) {
    __auto_type _mv_1685 = howl_prepare_encoded_within(arena, doc, imports_resolved, config, modular, seed);
    if (!_mv_1685.is_ok) {
        __auto_type f = _mv_1685.data.err;
        return ((slop_result_howl_types_Outcome_howl_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_1685.is_ok) {
        __auto_type mp = _mv_1685.data.ok;
        return howl_reason(arena, mp.prepared, config);
    }
    SLOP_UNREACHABLE();
}

slop_list_slop_rdf_rdf_IRI howl_query_seed(slop_arena* arena, slop_list_howl_probe_Query queries) {
    {
        __auto_type out = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = queries;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (q.sub); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                if (string_len(q.sup.value) > 0) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (q.sup); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

slop_result_howl_probe_Probing_howl_types_Fault howl_probe_outcome(slop_arena* arena, slop_result_howl_types_Outcome_howl_types_Fault r, slop_list_howl_probe_Query queries) {
    __auto_type _mv_1686 = r;
    if (_mv_1686.is_ok) {
        __auto_type o = _mv_1686.data.ok;
        return ((slop_result_howl_probe_Probing_howl_types_Fault){ .is_ok = true, .data.ok = howl_probing_of(arena, o, queries) });
    } else if (!_mv_1686.is_ok) {
        __auto_type f = _mv_1686.data.err;
        return ((slop_result_howl_probe_Probing_howl_types_Fault){ .is_ok = false, .data.err = howl_types_copy_fault(arena, f) });
    }
    SLOP_UNREACHABLE();
}

howl_probe_Probing howl_probing_of(slop_arena* arena, howl_types_Outcome o, slop_list_howl_probe_Query queries) {
    {
        __auto_type p = ((howl_probe_Probing){.answers = howl_probe_answer_queries(arena, o, queries), .inconsistent = o.findings.inconsistent, .omissions = howl_types_copy_omissions(arena, o.coverage.omitted), .profile = o.profile, .origins = howl_copy_origins(arena, o.coverage.origins), .reasons = howl_types_copy_causes(arena, o.coverage.reasons), .input_docs = 0, .probe_docs = 0});
        howl_release_outcome(o);
        return p;
    }
}

howl_probe_Probing howl_no_probing(slop_arena* arena) {
    return ((howl_probe_Probing){.answers = ((slop_list_howl_probe_Answered){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .inconsistent = 0, .omissions = ((slop_list_howl_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .profile = howl_types_Profile_profile_el, .origins = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .reasons = ((slop_list_howl_types_OmissionCause){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .input_docs = 0, .probe_docs = 0});
}

slop_list_int howl_copy_origins(slop_arena* arena, slop_list_int xs) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_InputState* howl_input_state(howl_Input in) {
    return ((howl_InputState*)(in.p));
}

howl_RunState howl_run_state(howl_Run r) {
    return (*((howl_RunState*)(r.p)));
}

howl_Input howl_input_new(void) {
    {
        __auto_type a = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type p = ((howl_InputState*)(({ __auto_type _alloc = (howl_InputState*)slop_arena_alloc(a, sizeof(howl_InputState)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = ((howl_InputState){.arena = a, .scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; }), .enc = howl_termstore_new_encoded(a), .imports = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = a }), .documents = 0, .probes = howl_termstore_new_encoded(a), .probe_docs = 0, .queries = ((slop_list_howl_probe_Query){ .data = NULL, .len = 0, .cap = 0, .arena = a }), .failed = (slop_option_string){.has_value = false}});
        return ((howl_Input){.p = ((void*)(p))});
    }
}

void howl_input_free(howl_Input in) {
    {
        __auto_type s = (*howl_input_state(in));
        (void)(({ slop_arena_free(s.scratch); free(s.scratch); }));
        (void)(({ slop_arena_free(s.arena); free(s.arena); }));
    }
}

void howl_input_begin_document(howl_Input in) {
    howl_begin_in(in, 0);
}

void howl_input_begin_probe_document(howl_Input in) {
    howl_begin_in(in, 1);
}

howl_termstore_Encoded* howl_target(howl_InputState st, uint8_t probe) {
    if (probe) {
        return st.probes;
    } else {
        return st.enc;
    }
}

void howl_begin_in(howl_Input in, uint8_t probe) {
    {
        __auto_type p = howl_input_state(in);
        __auto_type s = (*p);
        __auto_type n = ((probe) ? s.probe_docs : s.documents);
        if (n > 0) {
            howl_termstore_encoded_next_document(s.arena, howl_target(s, probe));
        }
        if (probe) {
            s.probe_docs = (n + 1);
        } else {
            s.documents = (n + 1);
        }
        (*p) = s;
    }
}

slop_option_string howl_optional_string(slop_string s) {
    if (string_len(s) == 0) {
        return (slop_option_string){.has_value = false};
    } else {
        return (slop_option_string){.has_value = 1, .value = s};
    }
}

slop_option_slop_rdf_rdf_Term howl_make_term(slop_arena* arena, howl_TermIn t) {
    __auto_type _mv_1687 = t.kind;
    if (_mv_1687 == slop_rdf_rdf_TermKind_iri) {
        return (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rdf_make_iri(arena, t.value)};
    } else if (_mv_1687 == slop_rdf_rdf_TermKind_blank) {
        if ((t.blank >= 0) && (t.blank <= 1099511627775)) {
            return (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rdf_make_blank(arena, ((int64_t)(SLOP_RANGE(int64_t, t.blank, 1, 0, 0, 0, "(Int 0 ..) at howl.slop:1125:60"))))};
        } else {
            return (slop_option_slop_rdf_rdf_Term){.has_value = false};
        }
    } else if (_mv_1687 == slop_rdf_rdf_TermKind_literal) {
        return (slop_option_slop_rdf_rdf_Term){.has_value = 1, .value = rdf_make_literal(arena, t.value, howl_optional_string(t.datatype), howl_optional_string(t.lang))};
    } else if (_mv_1687 == slop_rdf_rdf_TermKind_triple) {
        return (slop_option_slop_rdf_rdf_Term){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_input_add_triple(howl_Input in, howl_TermIn s, howl_TermIn p, howl_TermIn o) {
    return howl_add_triple_to(in, 0, s, p, o);
}

uint8_t howl_input_add_probe_triple(howl_Input in, howl_TermIn s, howl_TermIn p, howl_TermIn o) {
    return howl_add_triple_to(in, 1, s, p, o);
}

uint8_t howl_add_triple_to(howl_Input in, uint8_t probe, howl_TermIn s, howl_TermIn p, howl_TermIn o) {
    {
        __auto_type ptr = howl_input_state(in);
        __auto_type st = (*ptr);
        __auto_type sc = st.scratch;
        __auto_type ok = ({ __auto_type _mv = howl_make_term(sc, s); _mv.has_value ? ({ __auto_type ts = _mv.value; ({ __auto_type _mv = howl_make_term(sc, p); _mv.has_value ? ({ __auto_type tp = _mv.value; ({ __auto_type _mv = howl_make_term(sc, o); _mv.has_value ? ({ __auto_type to = _mv.value; ({ howl_termstore_encoded_add(st.arena, howl_target(st, probe), rdf_make_triple(sc, ts, tp, to)); 1; }); }) : (0); }); }) : (0); }); }) : (0); });
        howl_saturate_reuse_arena(sc);
        if (!(ok)) {
            st.failed = (slop_option_string){.has_value = 1, .value = SLOP_STR("a term of a kind HOWL does not take (a quoted triple, or a blank id outside 0..2^40-1)")};
            (*ptr) = st;
        }
        return ok;
    }
}

howl_TurtleResult howl_input_add_turtle(howl_Input in, slop_string text) {
    return howl_add_turtle_to(in, 0, text);
}

howl_TurtleResult howl_input_add_probe_turtle(howl_Input in, slop_string text) {
    return howl_add_turtle_to(in, 1, text);
}

howl_TurtleResult howl_add_turtle_to(howl_Input in, uint8_t probe, slop_string text) {
    howl_begin_in(in, probe);
    if (string_len(text) == 0) {
        return ((howl_TurtleResult){.ok = 1, .message = SLOP_STR(""), .line = 0, .column = 0});
    } else {
        {
            __auto_type ptr = howl_input_state(in);
            __auto_type st = (*ptr);
            __auto_type arena = st.arena;
            __auto_type enc = howl_target(st, probe);
            __auto_type parse = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
            __auto_type res = ({ __auto_type _mv = slop_rdf_ttl_parse_ttl_string_for_each_triple(parse, text, ({ howl__lambda_1688_env_t* howl__lambda_1688_env = (howl__lambda_1688_env_t*)slop_arena_alloc(arena, sizeof(howl__lambda_1688_env_t)); *howl__lambda_1688_env = (howl__lambda_1688_env_t){ .arena = arena, .enc = enc }; (slop_closure_t){ (void*)howl__lambda_1688, (void*)howl__lambda_1688_env }; })); howl_TurtleResult _mr; if (_mv.is_ok) { __auto_type _ = _mv.data.ok; _mr = ((howl_TurtleResult){.ok = 1, .message = SLOP_STR(""), .line = 0, .column = 0}); } else { __auto_type e = _mv.data.err; _mr = ((howl_TurtleResult){.ok = 0, .message = string_concat(arena, SLOP_STR(""), e.message), .line = e.position.line, .column = e.position.column}); } _mr; });
            (void)(({ slop_arena_free(parse); free(parse); }));
            if (!(res.ok)) {
                st.failed = (slop_option_string){.has_value = 1, .value = string_concat(arena, SLOP_STR("a Turtle document does not parse: "), res.message)};
                (*ptr) = st;
            }
            return res;
        }
    }
}

void howl_input_attest_import(howl_Input in, slop_string iri) {
    {
        __auto_type ptr = howl_input_state(in);
        __auto_type st = (*ptr);
        (void)(({ __auto_type _lst_p = &(st.imports); __auto_type _item = (((slop_rdf_rdf_IRI){.value = string_concat(st.arena, SLOP_STR(""), iri)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (*ptr) = st;
    }
}

void howl_input_ask_unsatisfiable(howl_Input in, slop_string cls) {
    howl_ask(in, howl_probe_QueryKind_query_unsatisfiable, cls, SLOP_STR(""));
}

void howl_input_ask_subsumed(howl_Input in, slop_string sub, slop_string sup) {
    howl_ask(in, howl_probe_QueryKind_query_subsumed, sub, sup);
}

void howl_ask(howl_Input in, howl_probe_QueryKind kind, slop_string sub, slop_string sup) {
    {
        __auto_type ptr = howl_input_state(in);
        __auto_type st = (*ptr);
        __auto_type a = st.arena;
        __auto_type empty = ({ __auto_type _mv = kind; int _mi = (_mv == howl_probe_QueryKind_query_unsatisfiable) ? 1 : (_mv == howl_probe_QueryKind_query_subsumed) ? 2 : 0; if (!_mi) { SLOP_UNREACHABLE(); } _mi == 1 ? ((string_len(sub) == 0)) : (((string_len(sub) == 0) || (string_len(sup) == 0))); });
        if (empty) {
            st.failed = (slop_option_string){.has_value = 1, .value = SLOP_STR("a probe query names an empty IRI")};
        } else {
            (void)(({ __auto_type _lst_p = &(st.queries); __auto_type _item = (((howl_probe_Query){.kind = kind, .sub = ((slop_rdf_rdf_IRI){.value = string_concat(a, SLOP_STR(""), sub)}), .sup = ((slop_rdf_rdf_IRI){.value = string_concat(a, SLOP_STR(""), sup)})})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        (*ptr) = st;
    }
}

howl_Options howl_default_options(void) {
    {
        __auto_type c = howl_types_default_config();
        return ((howl_Options){.workers = ((int64_t)(c.worker_count)), .max_iterations = ((int64_t)(c.max_iterations)), .profile = ({ __auto_type _mv = c.selection; howl_types_Profile _mr = {0}; int _mm = 0; switch (_mv.tag) { case howl_types_ProfileSelection_explicit: { __auto_type p = _mv.data.explicit; _mr = p; _mm = 1; break; } case howl_types_ProfileSelection_slop_auto: { _mr = howl_types_Profile_profile_el; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }), .auto_select = ({ __auto_type _mv = c.selection; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case howl_types_ProfileSelection_explicit: { _mr = 0; _mm = 1; break; } case howl_types_ProfileSelection_slop_auto: { _mr = 1; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }), .cancel = c.cancel_ptr});
    }
}

slop_option_string howl_options_problem(howl_Options o) {
    slop_option_string _retval = {0};
    if (o.workers < 1) {
        _retval = (slop_option_string){.has_value = 1, .value = SLOP_STR("workers must be 1..64")};
        goto _slop_post;
    } else {
        if (o.workers > 64) {
            _retval = (slop_option_string){.has_value = 1, .value = SLOP_STR("workers must be 1..64")};
            goto _slop_post;
        } else {
            if (o.max_iterations < 0) {
                _retval = (slop_option_string){.has_value = 1, .value = SLOP_STR("max_iterations must be 0..10000")};
                goto _slop_post;
            } else {
                if (o.max_iterations > 10000) {
                    _retval = (slop_option_string){.has_value = 1, .value = SLOP_STR("max_iterations must be 0..10000")};
                    goto _slop_post;
                } else {
                    _retval = (slop_option_string){.has_value = false};
                    goto _slop_post;
                }
            }
        }
    }
    _slop_post: ;
    SLOP_POST((({ __auto_type _mv = _retval; _mv.has_value ? ({ __auto_type _ = _mv.value; 1; }) : ((((o.workers >= 1)) && ((o.workers <= 64)) && ((o.max_iterations >= 0)) && ((o.max_iterations <= 10000)))); })), "(match $result ((none) (and (>= (. o workers) 1) (<= (. o workers) 64) (>= (. o max-iterations) 0) (<= (. o max-iterations) 10000))) ((some _) true))");
    return _retval;
}

howl_types_ReasonerConfig howl_options_config(howl_Options o) {
    SLOP_PRE(((o.workers >= 1)), "(>= (. o workers) 1)");
    SLOP_PRE(((o.workers <= 64)), "(<= (. o workers) 64)");
    SLOP_PRE(((o.max_iterations >= 0)), "(>= (. o max-iterations) 0)");
    SLOP_PRE(((o.max_iterations <= 10000)), "(<= (. o max-iterations) 10000)");
    {
        __auto_type c = howl_types_default_config();
        c.worker_count = ((uint8_t)(SLOP_RANGE(uint8_t, o.workers, 1, 1, 1, 64, "(Int 1 .. 64) at howl.slop:1294:50")));
        c.max_iterations = ((uint16_t)(SLOP_RANGE(uint16_t, o.max_iterations, 1, 1, 0, 10000, "(Int 0 .. 10000) at howl.slop:1295:55")));
        c.selection = ((o.auto_select) ? ((howl_types_ProfileSelection){ .tag = howl_types_ProfileSelection_slop_auto }) : ((howl_types_ProfileSelection){ .tag = howl_types_ProfileSelection_explicit, .data.explicit = o.profile }));
        c.strict_profile = 0;
        c.cancel_ptr = o.cancel;
        return c;
    }
}

howl_Run howl_new_run(slop_arena* a, howl_RunState st) {
    {
        __auto_type p = ((howl_RunState*)(({ __auto_type _alloc = (howl_RunState*)slop_arena_alloc(a, sizeof(howl_RunState)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = st;
        return ((howl_Run){.p = ((void*)(p))});
    }
}

howl_Run howl_faulted(slop_arena* a, howl_FaultKind kind, slop_string message, howl_types_Profile profile) {
    return howl_new_run(a, ((howl_RunState){.arena = a, .outcome = (slop_option_howl_types_Outcome){.has_value = false}, .fault = kind, .message = message, .fault_profile = profile, .verdict = howl_types_Verdict_verdict_inconclusive, .probing = howl_no_probing(a), .lines = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = a })}));
}

howl_Run howl_run_classify(howl_Input in, howl_Options o) {
    {
        __auto_type a = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type st = (*howl_input_state(in));
        __auto_type _mv_1689 = howl_options_problem(o);
        if (_mv_1689.has_value) {
            __auto_type why = _mv_1689.value;
            return howl_faulted(a, howl_FaultKind_fault_invalid_options, why, o.profile);
        } else if (!_mv_1689.has_value) {
            __auto_type _mv_1690 = st.failed;
            if (_mv_1690.has_value) {
                __auto_type why = _mv_1690.value;
                return howl_faulted(a, howl_FaultKind_fault_input_error, string_concat(a, SLOP_STR(""), why), o.profile);
            } else if (!_mv_1690.has_value) {
                __auto_type _mv_1691 = howl_classify_encoded(a, (*st.enc), st.imports, howl_options_config(o));
                if (_mv_1691.is_ok) {
                    __auto_type out = _mv_1691.data.ok;
                    return howl_with_probes(a, st, out, o);
                } else if (!_mv_1691.is_ok) {
                    __auto_type f = _mv_1691.data.err;
                    return howl_run_faulted(a, f, SLOP_STR(""), o.profile);
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

howl_Run howl_run_faulted(slop_arena* a, howl_types_Fault f, slop_string prefix, howl_types_Profile profile) {
    __auto_type _mv_1692 = f;
    switch (_mv_1692.tag) {
        case howl_types_Fault_cancelled:
        {
            return howl_faulted(a, howl_FaultKind_fault_cancelled, SLOP_STR(""), profile);
        }
        case howl_types_Fault_input_error:
        {
            __auto_type m = _mv_1692.data.input_error;
            return howl_faulted(a, howl_FaultKind_fault_input_error, string_concat(a, prefix, m), profile);
        }
        case howl_types_Fault_unavailable:
        {
            __auto_type p = _mv_1692.data.unavailable;
            return howl_faulted(a, howl_FaultKind_fault_unavailable, howl_select_unavailable_message(a, p), p);
        }
        case howl_types_Fault_refused:
        {
            __auto_type _ = _mv_1692.data.refused;
            return howl_faulted(a, howl_FaultKind_fault_input_error, SLOP_STR("refused under a strict profile"), profile);
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_probe_Probing_howl_types_Fault howl_probe_run(slop_arena* a, howl_InputState st, howl_Options o, uint8_t modular) {
    {
        __auto_type qs = howl_probe_sort_queries(a, st.queries);
        __auto_type pa = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type doc = howl_probe_probe_document(pa, (*st.enc), (*st.probes), qs);
        __auto_type res = howl_probe_encoded(a, (*doc), st.imports, qs, howl_options_config(o), modular);
        (void)(({ slop_arena_free(pa); free(pa); }));
        __auto_type _mv_1693 = res;
        if (_mv_1693.is_ok) {
            __auto_type p = _mv_1693.data.ok;
            {
                __auto_type q = p;
                q.input_docs = ((int64_t)(((int64_t)(((*st.enc).starts).len))));
                q.probe_docs = ((int64_t)(((int64_t)(((*st.probes).starts).len))));
                return ((slop_result_howl_probe_Probing_howl_types_Fault){ .is_ok = true, .data.ok = q });
            }
        } else if (!_mv_1693.is_ok) {
            __auto_type f = _mv_1693.data.err;
            return ((slop_result_howl_probe_Probing_howl_types_Fault){ .is_ok = false, .data.err = f });
        }
        SLOP_UNREACHABLE();
    }
}

howl_Run howl_with_probes(slop_arena* a, howl_InputState st, howl_types_Outcome out, howl_Options o) {
    if (((int64_t)((st.queries).len)) == 0) {
        return howl_finished(a, out, howl_no_probing(a), 0);
    } else {
        __auto_type _mv_1694 = howl_probe_run(a, st, o, 0);
        if (_mv_1694.is_ok) {
            __auto_type p = _mv_1694.data.ok;
            return howl_finished(a, out, p, 1);
        } else if (!_mv_1694.is_ok) {
            __auto_type f = _mv_1694.data.err;
            howl_release_outcome(out);
            return howl_run_faulted(a, f, SLOP_STR("probe run: "), o.profile);
        }
        SLOP_UNREACHABLE();
    }
}

howl_Run howl_run_answer(howl_Input in, howl_Options o) {
    {
        __auto_type a = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type st = (*howl_input_state(in));
        __auto_type _mv_1695 = howl_options_problem(o);
        if (_mv_1695.has_value) {
            __auto_type why = _mv_1695.value;
            return howl_faulted(a, howl_FaultKind_fault_invalid_options, why, o.profile);
        } else if (!_mv_1695.has_value) {
            __auto_type _mv_1696 = st.failed;
            if (_mv_1696.has_value) {
                __auto_type why = _mv_1696.value;
                return howl_faulted(a, howl_FaultKind_fault_input_error, string_concat(a, SLOP_STR(""), why), o.profile);
            } else if (!_mv_1696.has_value) {
                return howl_answer_of_input(a, st, o);
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

howl_Run howl_answer_of_input(slop_arena* a, howl_InputState st, howl_Options o) {
    if (((int64_t)((st.queries).len)) == 0) {
        return howl_answered(a, howl_no_probing(a), 0);
    } else {
        __auto_type _mv_1697 = howl_probe_run(a, st, o, 1);
        if (_mv_1697.is_ok) {
            __auto_type p = _mv_1697.data.ok;
            return howl_answered(a, p, 1);
        } else if (!_mv_1697.is_ok) {
            __auto_type f = _mv_1697.data.err;
            return howl_run_faulted(a, f, SLOP_STR(""), o.profile);
        }
        SLOP_UNREACHABLE();
    }
}

howl_Run howl_answered(slop_arena* a, howl_probe_Probing p, uint8_t ran) {
    return howl_new_run(a, ((howl_RunState){.arena = a, .outcome = (slop_option_howl_types_Outcome){.has_value = false}, .fault = howl_FaultKind_fault_none, .message = SLOP_STR(""), .fault_profile = p.profile, .verdict = howl_types_Verdict_verdict_inconclusive, .probing = p, .lines = howl_report_answer_lines(a, p, ran)}));
}

howl_Run howl_finished(slop_arena* a, howl_types_Outcome out, howl_probe_Probing p, uint8_t asked) {
    {
        __auto_type lines = howl_report_report_lines(a, out);
        if (asked) {
            {
                __auto_type _coll = howl_report_probe_lines(a, p);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type l = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(lines); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return howl_new_run(a, ((howl_RunState){.arena = a, .outcome = (slop_option_howl_types_Outcome){.has_value = 1, .value = out}, .fault = howl_FaultKind_fault_none, .message = SLOP_STR(""), .fault_profile = out.profile, .verdict = howl_types_verdict(out), .probing = p, .lines = lines}));
    }
}

void howl_run_free(howl_Run r) {
    {
        __auto_type st = howl_run_state(r);
        __auto_type _mv_1698 = st.outcome;
        if (_mv_1698.has_value) {
            __auto_type o = _mv_1698.value;
            howl_release_outcome(o);
        } else if (!_mv_1698.has_value) {
        }
        (void)(({ slop_arena_free(st.arena); free(st.arena); }));
    }
}

uint8_t howl_run_ok(howl_Run r) {
    return (howl_run_state(r).fault == howl_FaultKind_fault_none);
}

howl_FaultKind howl_run_fault(howl_Run r) {
    return howl_run_state(r).fault;
}

slop_string howl_run_fault_message(howl_Run r) {
    return howl_run_state(r).message;
}

howl_types_Profile howl_run_fault_profile(howl_Run r) {
    return howl_run_state(r).fault_profile;
}

howl_types_Profile howl_run_profile(howl_Run r) {
    return howl_run_state(r).fault_profile;
}

howl_types_Verdict howl_run_verdict(howl_Run r) {
    return howl_run_state(r).verdict;
}

uint8_t howl_run_inconsistent(howl_Run r) {
    __auto_type _mv_1699 = howl_run_state(r).outcome;
    if (_mv_1699.has_value) {
        __auto_type o = _mv_1699.value;
        return o.findings.inconsistent;
    } else if (!_mv_1699.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

howl_types_Termination howl_run_termination(howl_Run r) {
    __auto_type _mv_1700 = howl_run_state(r).outcome;
    if (_mv_1700.has_value) {
        __auto_type o = _mv_1700.value;
        return o.termination;
    } else if (!_mv_1700.has_value) {
        return ((howl_types_Termination){ .tag = howl_types_Termination_resource_limit, .data.resource_limit = 0 });
    }
    SLOP_UNREACHABLE();
}

int64_t howl_run_rounds(howl_Run r) {
    __auto_type _mv_1701 = howl_run_state(r).outcome;
    if (_mv_1701.has_value) {
        __auto_type o = _mv_1701.value;
        return o.rounds;
    } else if (!_mv_1701.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

int64_t howl_run_unsat_len(howl_Run r) {
    __auto_type _mv_1702 = howl_run_state(r).outcome;
    if (_mv_1702.has_value) {
        __auto_type o = _mv_1702.value;
        return ((int64_t)(((int64_t)((o.findings.unsatisfiable).len))));
    } else if (!_mv_1702.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string howl_run_unsat(howl_Run r, int64_t i) {
    __auto_type _mv_1703 = howl_run_state(r).outcome;
    if (_mv_1703.has_value) {
        __auto_type o = _mv_1703.value;
        __auto_type _mv_1704 = ({ __auto_type _lst = o.findings.unsatisfiable; size_t _idx = (size_t)i; slop_option_slop_rdf_rdf_IRI _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1704.has_value) {
            __auto_type c = _mv_1704.value;
            return c.value;
        } else if (!_mv_1704.has_value) {
            return SLOP_STR("");
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_1703.has_value) {
        return SLOP_STR("");
    }
    SLOP_UNREACHABLE();
}

int64_t howl_run_sub_len(howl_Run r) {
    __auto_type _mv_1705 = howl_run_state(r).outcome;
    if (_mv_1705.has_value) {
        __auto_type o = _mv_1705.value;
        return ((int64_t)(((int64_t)((o.findings.subsumptions).len))));
    } else if (!_mv_1705.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string howl_run_sub(howl_Run r, int64_t i) {
    {
        __auto_type st = howl_run_state(r);
        __auto_type _mv_1706 = st.outcome;
        if (_mv_1706.has_value) {
            __auto_type o = _mv_1706.value;
            __auto_type _mv_1707 = ({ __auto_type _lst = o.findings.subsumptions; size_t _idx = (size_t)i; slop_option_howl_types_SubPair _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1707.has_value) {
                __auto_type sp = _mv_1707.value;
                return howl_report_node_text(st.arena, sp.sub);
            } else if (!_mv_1707.has_value) {
                return SLOP_STR("");
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_1706.has_value) {
            return SLOP_STR("");
        }
        SLOP_UNREACHABLE();
    }
}

slop_string howl_run_super(howl_Run r, int64_t i) {
    {
        __auto_type st = howl_run_state(r);
        __auto_type _mv_1708 = st.outcome;
        if (_mv_1708.has_value) {
            __auto_type o = _mv_1708.value;
            __auto_type _mv_1709 = ({ __auto_type _lst = o.findings.subsumptions; size_t _idx = (size_t)i; slop_option_howl_types_SubPair _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1709.has_value) {
                __auto_type sp = _mv_1709.value;
                return howl_report_node_text(st.arena, sp.super);
            } else if (!_mv_1709.has_value) {
                return SLOP_STR("");
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_1708.has_value) {
            return SLOP_STR("");
        }
        SLOP_UNREACHABLE();
    }
}

int64_t howl_run_omission_len(howl_Run r) {
    __auto_type _mv_1710 = howl_run_state(r).outcome;
    if (_mv_1710.has_value) {
        __auto_type o = _mv_1710.value;
        return ((int64_t)(((int64_t)((o.coverage.omitted).len))));
    } else if (!_mv_1710.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string howl_run_omission(howl_Run r, int64_t i) {
    {
        __auto_type st = howl_run_state(r);
        __auto_type _mv_1711 = st.outcome;
        if (_mv_1711.has_value) {
            __auto_type o = _mv_1711.value;
            __auto_type _mv_1712 = ({ __auto_type _lst = o.coverage.omitted; size_t _idx = (size_t)i; slop_option_howl_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1712.has_value) {
                __auto_type om = _mv_1712.value;
                return howl_owl2_render_omission(st.arena, om);
            } else if (!_mv_1712.has_value) {
                return SLOP_STR("");
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_1711.has_value) {
            return SLOP_STR("");
        }
        SLOP_UNREACHABLE();
    }
}

slop_string howl_omission_kind(slop_arena* arena, howl_types_Omission om) {
    {
        __auto_type t = howl_owl2_render_omission(arena, om);
        __auto_type _mv_1713 = std_strlib_index_of(t, SLOP_STR("("));
        if (_mv_1713.has_value) {
            __auto_type n = _mv_1713.value;
            return std_strlib_substring(arena, t, 0, n);
        } else if (!_mv_1713.has_value) {
            return t;
        }
        SLOP_UNREACHABLE();
    }
}

howl_types_EntityKind howl_omission_entity_kind(howl_types_Omission om) {
    __auto_type _mv_1714 = om;
    switch (_mv_1714.tag) {
        case howl_types_Omission_missing_declaration:
        {
            __auto_type md = _mv_1714.data.missing_declaration;
            return md.kind;
        }
        case howl_types_Omission_out_of_profile:
        {
            __auto_type _ = _mv_1714.data.out_of_profile;
            return howl_types_EntityKind_entity_class;
        }
        case howl_types_Omission_unresolved_import:
        {
            __auto_type _ = _mv_1714.data.unresolved_import;
            return howl_types_EntityKind_entity_class;
        }
        case howl_types_Omission_undeclared_property:
        {
            __auto_type _ = _mv_1714.data.undeclared_property;
            return howl_types_EntityKind_entity_class;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t howl_origin_at(slop_list_int origins, int64_t i) {
    __auto_type _mv_1715 = ({ __auto_type _lst = origins; size_t _idx = (size_t)i; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1715.has_value) {
        __auto_type d = _mv_1715.value;
        return d;
    } else if (!_mv_1715.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

slop_string howl_run_omission_kind(howl_Run r, int64_t i) {
    {
        __auto_type st = howl_run_state(r);
        __auto_type _mv_1716 = st.outcome;
        if (_mv_1716.has_value) {
            __auto_type o = _mv_1716.value;
            __auto_type _mv_1717 = ({ __auto_type _lst = o.coverage.omitted; size_t _idx = (size_t)i; slop_option_howl_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1717.has_value) {
                __auto_type om = _mv_1717.value;
                return howl_omission_kind(st.arena, om);
            } else if (!_mv_1717.has_value) {
                return SLOP_STR("");
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_1716.has_value) {
            return SLOP_STR("");
        }
        SLOP_UNREACHABLE();
    }
}

howl_types_EntityKind howl_run_omission_entity_kind(howl_Run r, int64_t i) {
    __auto_type _mv_1718 = howl_run_state(r).outcome;
    if (_mv_1718.has_value) {
        __auto_type o = _mv_1718.value;
        __auto_type _mv_1719 = ({ __auto_type _lst = o.coverage.omitted; size_t _idx = (size_t)i; slop_option_howl_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1719.has_value) {
            __auto_type om = _mv_1719.value;
            return howl_omission_entity_kind(om);
        } else if (!_mv_1719.has_value) {
            return howl_types_EntityKind_entity_class;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_1718.has_value) {
        return howl_types_EntityKind_entity_class;
    }
    SLOP_UNREACHABLE();
}

int64_t howl_run_omission_document(howl_Run r, int64_t i) {
    __auto_type _mv_1720 = howl_run_state(r).outcome;
    if (_mv_1720.has_value) {
        __auto_type o = _mv_1720.value;
        return howl_origin_at(o.coverage.origins, i);
    } else if (!_mv_1720.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

howl_types_OmissionCause howl_omission_cause(slop_list_howl_types_Omission oms, slop_list_howl_types_OmissionCause causes, int64_t i) {
    __auto_type _mv_1721 = ({ __auto_type _lst = causes; size_t _idx = (size_t)i; slop_option_howl_types_OmissionCause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1721.has_value) {
        __auto_type c = _mv_1721.value;
        return c;
    } else if (!_mv_1721.has_value) {
        __auto_type _mv_1722 = ({ __auto_type _lst = oms; size_t _idx = (size_t)i; slop_option_howl_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1722.has_value) {
            __auto_type om = _mv_1722.value;
            return howl_types_variant_cause(om);
        } else if (!_mv_1722.has_value) {
            return howl_types_cause_of(howl_types_OmissionReason_reason_out_of_profile);
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

howl_types_OmissionReason howl_run_omission_reason(howl_Run r, int64_t i) {
    __auto_type _mv_1723 = howl_run_state(r).outcome;
    if (_mv_1723.has_value) {
        __auto_type o = _mv_1723.value;
        return howl_omission_cause(o.coverage.omitted, o.coverage.reasons, i).reason;
    } else if (!_mv_1723.has_value) {
        return howl_types_OmissionReason_reason_out_of_profile;
    }
    SLOP_UNREACHABLE();
}

slop_string howl_run_omission_reason_role(howl_Run r, int64_t i) {
    __auto_type _mv_1724 = howl_run_state(r).outcome;
    if (_mv_1724.has_value) {
        __auto_type o = _mv_1724.value;
        return howl_omission_cause(o.coverage.omitted, o.coverage.reasons, i).role;
    } else if (!_mv_1724.has_value) {
        return SLOP_STR("");
    }
    SLOP_UNREACHABLE();
}

int64_t howl_run_probe_len(howl_Run r) {
    return ((int64_t)(((int64_t)((howl_run_state(r).probing.answers).len))));
}

slop_option_howl_probe_Answered howl_probe_at(howl_Run r, int64_t i) {
    return ({ __auto_type _lst = howl_run_state(r).probing.answers; size_t _idx = (size_t)i; slop_option_howl_probe_Answered _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
}

howl_probe_QueryKind howl_run_probe_kind(howl_Run r, int64_t i) {
    __auto_type _mv_1725 = howl_probe_at(r, i);
    if (_mv_1725.has_value) {
        __auto_type a = _mv_1725.value;
        return a.query.kind;
    } else if (!_mv_1725.has_value) {
        return howl_probe_QueryKind_query_unsatisfiable;
    }
    SLOP_UNREACHABLE();
}

slop_string howl_run_probe_sub(howl_Run r, int64_t i) {
    __auto_type _mv_1726 = howl_probe_at(r, i);
    if (_mv_1726.has_value) {
        __auto_type a = _mv_1726.value;
        return a.query.sub.value;
    } else if (!_mv_1726.has_value) {
        return SLOP_STR("");
    }
    SLOP_UNREACHABLE();
}

slop_string howl_run_probe_sup(howl_Run r, int64_t i) {
    __auto_type _mv_1727 = howl_probe_at(r, i);
    if (_mv_1727.has_value) {
        __auto_type a = _mv_1727.value;
        return a.query.sup.value;
    } else if (!_mv_1727.has_value) {
        return SLOP_STR("");
    }
    SLOP_UNREACHABLE();
}

howl_probe_ProbeAnswer howl_run_probe_answer(howl_Run r, int64_t i) {
    __auto_type _mv_1728 = howl_probe_at(r, i);
    if (_mv_1728.has_value) {
        __auto_type a = _mv_1728.value;
        return a.answer;
    } else if (!_mv_1728.has_value) {
        return howl_probe_ProbeAnswer_answer_unknown;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_run_probe_inconsistent(howl_Run r) {
    return howl_run_state(r).probing.inconsistent;
}

int64_t howl_run_probe_omission_len(howl_Run r) {
    return ((int64_t)(((int64_t)((howl_run_state(r).probing.omissions).len))));
}

slop_string howl_run_probe_omission(howl_Run r, int64_t i) {
    {
        __auto_type st = howl_run_state(r);
        __auto_type _mv_1729 = ({ __auto_type _lst = st.probing.omissions; size_t _idx = (size_t)i; slop_option_howl_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1729.has_value) {
            __auto_type om = _mv_1729.value;
            return howl_owl2_render_omission(st.arena, om);
        } else if (!_mv_1729.has_value) {
            return SLOP_STR("");
        }
        SLOP_UNREACHABLE();
    }
}

slop_string howl_run_probe_omission_kind(howl_Run r, int64_t i) {
    {
        __auto_type st = howl_run_state(r);
        __auto_type _mv_1730 = ({ __auto_type _lst = st.probing.omissions; size_t _idx = (size_t)i; slop_option_howl_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1730.has_value) {
            __auto_type om = _mv_1730.value;
            return howl_omission_kind(st.arena, om);
        } else if (!_mv_1730.has_value) {
            return SLOP_STR("");
        }
        SLOP_UNREACHABLE();
    }
}

howl_types_EntityKind howl_run_probe_omission_entity_kind(howl_Run r, int64_t i) {
    __auto_type _mv_1731 = ({ __auto_type _lst = howl_run_state(r).probing.omissions; size_t _idx = (size_t)i; slop_option_howl_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1731.has_value) {
        __auto_type om = _mv_1731.value;
        return howl_omission_entity_kind(om);
    } else if (!_mv_1731.has_value) {
        return howl_types_EntityKind_entity_class;
    }
    SLOP_UNREACHABLE();
}

howl_types_OmissionReason howl_run_probe_omission_reason(howl_Run r, int64_t i) {
    {
        __auto_type p = howl_run_state(r).probing;
        return howl_omission_cause(p.omissions, p.reasons, i).reason;
    }
}

slop_string howl_run_probe_omission_reason_role(howl_Run r, int64_t i) {
    {
        __auto_type p = howl_run_state(r).probing;
        return howl_omission_cause(p.omissions, p.reasons, i).role;
    }
}

int64_t howl_probe_origin(howl_probe_Probing p, int64_t i) {
    return howl_origin_at(p.origins, i);
}

howl_DocumentSource howl_run_probe_omission_source(howl_Run r, int64_t i) {
    {
        __auto_type p = howl_run_state(r).probing;
        __auto_type k = howl_probe_origin(p, i);
        if (k < 0) {
            return howl_DocumentSource_document_none;
        } else {
            if (k < p.input_docs) {
                return howl_DocumentSource_document_input;
            } else {
                if (k < (p.input_docs + p.probe_docs)) {
                    return howl_DocumentSource_document_probe;
                } else {
                    return howl_DocumentSource_document_none;
                }
            }
        }
    }
}

int64_t howl_run_probe_omission_document(howl_Run r, int64_t i) {
    {
        __auto_type p = howl_run_state(r).probing;
        __auto_type k = howl_probe_origin(p, i);
        if (k < 0) {
            return -1;
        } else {
            if (k < p.input_docs) {
                return k;
            } else {
                if (k < (p.input_docs + p.probe_docs)) {
                    return (k - p.input_docs);
                } else {
                    return -1;
                }
            }
        }
    }
}

int64_t howl_run_report_len(howl_Run r) {
    return ((int64_t)(((int64_t)((howl_run_state(r).lines).len))));
}

slop_string howl_run_report_line(howl_Run r, int64_t i) {
    __auto_type _mv_1732 = ({ __auto_type _lst = howl_run_state(r).lines; size_t _idx = (size_t)i; slop_option_string _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1732.has_value) {
        __auto_type l = _mv_1732.value;
        return l;
    } else if (!_mv_1732.has_value) {
        return SLOP_STR("");
    }
    SLOP_UNREACHABLE();
}

