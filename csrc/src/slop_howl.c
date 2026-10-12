#include "../runtime/slop_runtime.h"
#include "slop_howl.h"

slop_result_normalize_Decoded_types_Fault howl_decode(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved);
slop_result_normalize_Decoded_types_Fault howl_decode_from(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved);
slop_result_normalize_Decoded_types_Fault howl_own_decoded(slop_arena* arena, slop_result_normalize_Decoded_types_Fault r);
slop_result_normalize_Decoded_types_Fault howl_decode_owned(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved);
slop_result_howl_Prepared_types_Fault howl_prepare_decoded(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config);
int64_t howl_out_of_profile_count(slop_list_types_Omission oms);
types_Profile howl_auto_profile(normalize_Decoded d);
slop_result_howl_Prepared_types_Fault howl_prepare_in_profile(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config, types_Profile profile);
uint8_t howl_strict_refuses(types_ReasonerConfig config, types_Coverage cov);
slop_result_howl_Prepared_types_Fault howl_prepare_el(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config, types_Profile profile);
slop_result_howl_Prepared_types_Fault howl_prepare_ksc(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config, types_Profile profile);
slop_list_types_KName howl_copy_knames(slop_arena* arena, slop_list_types_KName ns);
slop_result_howl_Prepared_types_Fault howl_prepare(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);
slop_result_types_Outcome_types_Fault howl_reason(slop_arena* arena, howl_Prepared p, types_ReasonerConfig config);
slop_result_types_Outcome_types_Fault howl_classify(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);
void howl_release_outcome(types_Outcome o);
slop_result_howl_Prepared_types_Fault howl_prepare_encoded(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);
slop_result_types_Outcome_types_Fault howl_classify_encoded(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);
howl_InputState* howl_input_state(howl_Input in);
howl_RunState howl_run_state(howl_Run r);
howl_Input howl_input_new(void);
void howl_input_free(howl_Input in);
void howl_input_begin_document(howl_Input in);
slop_option_string howl_optional_string(slop_string s);
slop_option_rdf_Term howl_make_term(slop_arena* arena, howl_TermIn t);
uint8_t howl_input_add_triple(howl_Input in, howl_TermIn s, howl_TermIn p, howl_TermIn o);
howl_TurtleResult howl_input_add_turtle(howl_Input in, slop_string text);
void howl_input_attest_import(howl_Input in, slop_string iri);
howl_Options howl_default_options(void);
slop_option_string howl_options_problem(howl_Options o);
types_ReasonerConfig howl_options_config(howl_Options o);
howl_Run howl_new_run(slop_arena* a, howl_RunState st);
howl_Run howl_faulted(slop_arena* a, howl_FaultKind kind, slop_string message, types_Profile profile);
howl_Run howl_run_classify(howl_Input in, howl_Options o);
void howl_run_free(howl_Run r);
uint8_t howl_run_ok(howl_Run r);
howl_FaultKind howl_run_fault(howl_Run r);
slop_string howl_run_fault_message(howl_Run r);
types_Profile howl_run_fault_profile(howl_Run r);
types_Profile howl_run_profile(howl_Run r);
types_Verdict howl_run_verdict(howl_Run r);
uint8_t howl_run_inconsistent(howl_Run r);
types_Termination howl_run_termination(howl_Run r);
int64_t howl_run_rounds(howl_Run r);
int64_t howl_run_unsat_len(howl_Run r);
slop_string howl_run_unsat(howl_Run r, int64_t i);
int64_t howl_run_sub_len(howl_Run r);
slop_string howl_run_sub(howl_Run r, int64_t i);
slop_string howl_run_super(howl_Run r, int64_t i);
int64_t howl_run_omission_len(howl_Run r);
slop_string howl_run_omission(howl_Run r, int64_t i);
int64_t howl_run_report_len(howl_Run r);
slop_string howl_run_report_line(howl_Run r, int64_t i);

typedef struct { slop_arena* arena; termstore_Encoded* enc; } howl__lambda_1066_env_t;

static void howl__lambda_1066(howl__lambda_1066_env_t* _env, rdf_Triple t) { termstore_encoded_add(_env->arena, _env->enc, t); }

slop_result_normalize_Decoded_types_Fault howl_decode(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved) {
    return normalize_decode_document(arena, triples, imports_resolved);
}

slop_result_normalize_Decoded_types_Fault howl_decode_from(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved) {
    return normalize_decode_encoded(arena, doc, imports_resolved);
}

slop_result_normalize_Decoded_types_Fault howl_own_decoded(slop_arena* arena, slop_result_normalize_Decoded_types_Fault r) {
    __auto_type _mv_1056 = r;
    if (_mv_1056.is_ok) {
        __auto_type d = _mv_1056.data.ok;
        return ((slop_result_normalize_Decoded_types_Fault){ .is_ok = true, .data.ok = normalize_copy_decoded(arena, d) });
    } else if (!_mv_1056.is_ok) {
        __auto_type f = _mv_1056.data.err;
        return ((slop_result_normalize_Decoded_types_Fault){ .is_ok = false, .data.err = types_copy_fault(arena, f) });
    }
    SLOP_UNREACHABLE();
}

slop_result_normalize_Decoded_types_Fault howl_decode_owned(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved) {
    {
        __auto_type front = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type res = howl_own_decoded(arena, howl_decode(front, triples, imports_resolved));
        ({ slop_arena_free(front); free(front); });
        return res;
    }
}

slop_result_howl_Prepared_types_Fault howl_prepare_decoded(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config) {
    __auto_type _mv_1057 = select_select_profile(config.selection);
    if (_mv_1057.has_value) {
        __auto_type profile = _mv_1057.value;
        if (!(select_profile_implemented(profile))) {
            return ((slop_result_howl_Prepared_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_unavailable, .data.unavailable = profile }) });
        } else {
            return howl_prepare_in_profile(arena, d, config, profile);
        }
    } else if (!_mv_1057.has_value) {
        return howl_prepare_in_profile(arena, d, config, howl_auto_profile(d));
    }
    SLOP_UNREACHABLE();
}

int64_t howl_out_of_profile_count(slop_list_types_Omission oms) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = oms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                __auto_type _mv_1058 = o;
                switch (_mv_1058.tag) {
                    case types_Omission_out_of_profile:
                    {
                        __auto_type _ = _mv_1058.data.out_of_profile;
                        n = (n + 1);
                        break;
                    }
                    case types_Omission_unresolved_import:
                    {
                        __auto_type _ = _mv_1058.data.unresolved_import;
                        break;
                    }
                    case types_Omission_missing_declaration:
                    {
                        __auto_type _ = _mv_1058.data.missing_declaration;
                        break;
                    }
                }
            }
        }
        return n;
    }
}

types_Profile howl_auto_profile(normalize_Decoded d) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type out_el = howl_out_of_profile_count(gate_gate_axioms(scratch, d.axioms, d.signature, d.omissions, types_Profile_profile_el).omissions);
        __auto_type out_pp = (((out_el == 0)) ? 0 : howl_out_of_profile_count(gate_gate_axioms(scratch, d.axioms, d.signature, d.omissions, types_Profile_profile_el_plus_plus).omissions));
        __auto_type chosen = select_choose_auto(((int64_t)(SLOP_RANGE(int64_t, out_el, 1, 0, 0, 0, "(Int 0 ..) at howl.slop:271:50"))), ((int64_t)(SLOP_RANGE(int64_t, out_pp, 1, 0, 0, 0, "(Int 0 ..) at howl.slop:271:75"))));
        ({ slop_arena_free(scratch); free(scratch); });
        return chosen;
    }
}

slop_result_howl_Prepared_types_Fault howl_prepare_in_profile(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config, types_Profile profile) {
    __auto_type _mv_1059 = profile;
    if (_mv_1059 == types_Profile_profile_el_plus_plus) {
        return howl_prepare_ksc(arena, d, config, profile);
    } else if (_mv_1059 == types_Profile_profile_el) {
        return howl_prepare_el(arena, d, config, profile);
    } else if (_mv_1059 == types_Profile_profile_horn_sriq) {
        return howl_prepare_el(arena, d, config, profile);
    } else if (_mv_1059 == types_Profile_profile_sriq) {
        return howl_prepare_el(arena, d, config, profile);
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_strict_refuses(types_ReasonerConfig config, types_Coverage cov) {
    if (config.strict_profile) {
        return (((int64_t)((cov.omitted).len)) > 0);
    } else {
        return 0;
    }
}

slop_result_howl_Prepared_types_Fault howl_prepare_el(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config, types_Profile profile) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type nr = normalize_normalize_decoded(arena, scratch, d);
        __auto_type res = ((howl_strict_refuses(config, nr.coverage)) ? ((slop_result_howl_Prepared_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_refused, .data.refused = nr.coverage.omitted }) }) : ((slop_result_howl_Prepared_types_Fault){ .is_ok = true, .data.ok = ((howl_Prepared){.profile = profile, .work = ((howl_Work){ .tag = howl_Work_el_work, .data.el_work = ((howl_ElWork){.axioms = nr.axioms, .index = premise_build_rule_index(arena, nr.axioms), .saturation = nr.saturation}) }), .coverage = nr.coverage, .names = nr.names}) }));
        ({ slop_arena_free(scratch); free(scratch); });
        return res;
    }
}

slop_result_howl_Prepared_types_Fault howl_prepare_ksc(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config, types_Profile profile) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type gr = gate_gate_axioms(scratch, d.axioms, d.signature, d.omissions, types_Profile_profile_el_plus_plus);
        __auto_type cov = ((types_Coverage){.omitted = types_copy_omissions(arena, gr.omissions)});
        __auto_type res = ((howl_strict_refuses(config, cov)) ? ((slop_result_howl_Prepared_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_refused, .data.refused = cov.omitted }) }) : ((slop_result_howl_Prepared_types_Fault){ .is_ok = true, .data.ok = ((howl_Prepared){.profile = profile, .work = ((howl_Work){ .tag = howl_Work_ksc_work, .data.ksc_work = ((howl_KscWork){.axioms = kscnormal_copy_ksc_axioms(arena, kscnormal_normalize_ksc(scratch, gr.accepted).axioms), .classes = howl_copy_knames(arena, kscsat_input_classes(scratch, gr.signature))}) }), .coverage = cov, .names = types_empty_names(arena)}) }));
        ({ slop_arena_free(scratch); free(scratch); });
        return res;
    }
}

slop_list_types_KName howl_copy_knames(slop_arena* arena, slop_list_types_KName ns) {
    {
        __auto_type out = ((slop_list_types_KName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (kscnormal_copy_kname(arena, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_result_howl_Prepared_types_Fault howl_prepare(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config) {
    {
        __auto_type held = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type res = ({ __auto_type _mv = howl_decode_owned(held, triples, imports_resolved); slop_result_howl_Prepared_types_Fault _mr; if (_mv.is_ok) { __auto_type d = _mv.data.ok; _mr = howl_prepare_decoded(arena, d, config); } else { __auto_type f = _mv.data.err; _mr = ((slop_result_howl_Prepared_types_Fault){ .is_ok = false, .data.err = types_copy_fault(arena, f) }); } _mr; });
        ({ slop_arena_free(held); free(held); });
        return res;
    }
}

slop_result_types_Outcome_types_Fault howl_reason(slop_arena* arena, howl_Prepared p, types_ReasonerConfig config) {
    __auto_type _mv_1060 = p.work;
    switch (_mv_1060.tag) {
        case howl_Work_el_work:
        {
            __auto_type w = _mv_1060.data.el_work;
            __auto_type _mv_1061 = saturate_saturate(arena, w.saturation, w.index, config);
            if (!_mv_1061.is_ok) {
                __auto_type f = _mv_1061.data.err;
                return ((slop_result_types_Outcome_types_Fault){ .is_ok = false, .data.err = f });
            } else if (_mv_1061.is_ok) {
                __auto_type rr = _mv_1061.data.ok;
                return ((slop_result_types_Outcome_types_Fault){ .is_ok = true, .data.ok = ((types_Outcome){.profile = p.profile, .coverage = p.coverage, .termination = rr.termination, .findings = classify_extract_findings(arena, rr.saturation, p.names), .evidence = ((types_Evidence){ .tag = types_Evidence_el_evidence, .data.el_evidence = rr.saturation }), .rounds = rr.saturation.iteration, .names = p.names, .owned = rr.arenas}) });
            }
            SLOP_UNREACHABLE();
        }
        case howl_Work_ksc_work:
        {
            __auto_type w = _mv_1060.data.ksc_work;
            __auto_type _mv_1062 = kscsat_ksc_classify(arena, w.axioms, w.classes, config);
            if (!_mv_1062.is_ok) {
                __auto_type f = _mv_1062.data.err;
                return ((slop_result_types_Outcome_types_Fault){ .is_ok = false, .data.err = f });
            } else if (_mv_1062.is_ok) {
                __auto_type r = _mv_1062.data.ok;
                return ((slop_result_types_Outcome_types_Fault){ .is_ok = true, .data.ok = ((types_Outcome){.profile = p.profile, .coverage = p.coverage, .termination = r.termination, .findings = classify_extract_ksc_findings(arena, r), .evidence = ((types_Evidence){ .tag = types_Evidence_ksc_evidence, .data.ksc_evidence = r }), .rounds = r.rounds, .names = p.names, .owned = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena })}) });
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_types_Outcome_types_Fault howl_classify(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config) {
    __auto_type _mv_1063 = howl_prepare(arena, triples, imports_resolved, config);
    if (!_mv_1063.is_ok) {
        __auto_type f = _mv_1063.data.err;
        return ((slop_result_types_Outcome_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_1063.is_ok) {
        __auto_type p = _mv_1063.data.ok;
        return howl_reason(arena, p, config);
    }
    SLOP_UNREACHABLE();
}

void howl_release_outcome(types_Outcome o) {
    {
        __auto_type _coll = o.owned;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type a = _coll.data[_i];
            ({ slop_arena_free(a); free(a); });
        }
    }
}

slop_result_howl_Prepared_types_Fault howl_prepare_encoded(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config) {
    {
        __auto_type held = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type front = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type d = howl_own_decoded(held, howl_decode_from(front, doc, imports_resolved));
        ({ slop_arena_free(front); free(front); });
        {
            __auto_type res = ({ __auto_type _mv = d; slop_result_howl_Prepared_types_Fault _mr; if (_mv.is_ok) { __auto_type dd = _mv.data.ok; _mr = howl_prepare_decoded(arena, dd, config); } else { __auto_type f = _mv.data.err; _mr = ((slop_result_howl_Prepared_types_Fault){ .is_ok = false, .data.err = types_copy_fault(arena, f) }); } _mr; });
            ({ slop_arena_free(held); free(held); });
            return res;
        }
    }
}

slop_result_types_Outcome_types_Fault howl_classify_encoded(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config) {
    __auto_type _mv_1064 = howl_prepare_encoded(arena, doc, imports_resolved, config);
    if (!_mv_1064.is_ok) {
        __auto_type f = _mv_1064.data.err;
        return ((slop_result_types_Outcome_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_1064.is_ok) {
        __auto_type p = _mv_1064.data.ok;
        return howl_reason(arena, p, config);
    }
    SLOP_UNREACHABLE();
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
        (*p) = ((howl_InputState){.arena = a, .scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; }), .enc = termstore_new_encoded(a), .imports = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = a }), .documents = 0, .failed = (slop_option_string){.has_value = false}});
        return ((howl_Input){.p = ((void*)(p))});
    }
}

void howl_input_free(howl_Input in) {
    {
        __auto_type s = (*howl_input_state(in));
        ({ slop_arena_free(s.scratch); free(s.scratch); });
        ({ slop_arena_free(s.arena); free(s.arena); });
    }
}

void howl_input_begin_document(howl_Input in) {
    {
        __auto_type p = howl_input_state(in);
        __auto_type s = (*p);
        if (s.documents > 0) {
            termstore_encoded_next_document(s.arena, s.enc);
        }
        s.documents = (s.documents + 1);
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

slop_option_rdf_Term howl_make_term(slop_arena* arena, howl_TermIn t) {
    __auto_type _mv_1065 = t.kind;
    if (_mv_1065 == rdf_TermKind_iri) {
        return (slop_option_rdf_Term){.has_value = 1, .value = rdf_make_iri(arena, t.value)};
    } else if (_mv_1065 == rdf_TermKind_blank) {
        if ((t.blank >= 0) && (t.blank <= 1099511627775)) {
            return (slop_option_rdf_Term){.has_value = 1, .value = rdf_make_blank(arena, ((int64_t)(SLOP_RANGE(int64_t, t.blank, 1, 0, 0, 0, "(Int 0 ..) at howl.slop:611:60"))))};
        } else {
            return (slop_option_rdf_Term){.has_value = false};
        }
    } else if (_mv_1065 == rdf_TermKind_literal) {
        return (slop_option_rdf_Term){.has_value = 1, .value = rdf_make_literal(arena, t.value, howl_optional_string(t.datatype), howl_optional_string(t.lang))};
    } else if (_mv_1065 == rdf_TermKind_triple) {
        return (slop_option_rdf_Term){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_input_add_triple(howl_Input in, howl_TermIn s, howl_TermIn p, howl_TermIn o) {
    {
        __auto_type ptr = howl_input_state(in);
        __auto_type st = (*ptr);
        __auto_type sc = st.scratch;
        __auto_type ok = ({ __auto_type _mv = howl_make_term(sc, s); _mv.has_value ? ({ __auto_type ts = _mv.value; ({ __auto_type _mv = howl_make_term(sc, p); _mv.has_value ? ({ __auto_type tp = _mv.value; ({ __auto_type _mv = howl_make_term(sc, o); _mv.has_value ? ({ __auto_type to = _mv.value; ({ termstore_encoded_add(st.arena, st.enc, rdf_make_triple(sc, ts, tp, to)); 1; }); }) : (0); }); }) : (0); }); }) : (0); });
        saturate_reuse_arena(sc);
        if (!(ok)) {
            st.failed = (slop_option_string){.has_value = 1, .value = SLOP_STR("a term of a kind HOWL does not take (a quoted triple, or a blank id outside 0..2^40-1)")};
            (*ptr) = st;
        }
        return ok;
    }
}

howl_TurtleResult howl_input_add_turtle(howl_Input in, slop_string text) {
    howl_input_begin_document(in);
    if (string_len(text) == 0) {
        return ((howl_TurtleResult){.ok = 1, .message = SLOP_STR(""), .line = 0, .column = 0});
    } else {
        {
            __auto_type ptr = howl_input_state(in);
            __auto_type st = (*ptr);
            __auto_type arena = st.arena;
            __auto_type enc = st.enc;
            __auto_type parse = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
            __auto_type res = ({ __auto_type _mv = ttl_parse_ttl_string_for_each_triple(parse, text, ({ howl__lambda_1066_env_t* howl__lambda_1066_env = (howl__lambda_1066_env_t*)slop_arena_alloc(arena, sizeof(howl__lambda_1066_env_t)); *howl__lambda_1066_env = (howl__lambda_1066_env_t){ .arena = arena, .enc = enc }; (slop_closure_t){ (void*)howl__lambda_1066, (void*)howl__lambda_1066_env }; })); howl_TurtleResult _mr; if (_mv.is_ok) { __auto_type _ = _mv.data.ok; _mr = ((howl_TurtleResult){.ok = 1, .message = SLOP_STR(""), .line = 0, .column = 0}); } else { __auto_type e = _mv.data.err; _mr = ((howl_TurtleResult){.ok = 0, .message = string_concat(arena, SLOP_STR(""), e.message), .line = e.position.line, .column = e.position.column}); } _mr; });
            ({ slop_arena_free(parse); free(parse); });
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
        ({ __auto_type _lst_p = &(st.imports); __auto_type _item = (((rdf_IRI){.value = string_concat(st.arena, SLOP_STR(""), iri)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        (*ptr) = st;
    }
}

howl_Options howl_default_options(void) {
    {
        __auto_type c = types_default_config();
        return ((howl_Options){.workers = ((int64_t)(c.worker_count)), .max_iterations = ((int64_t)(c.max_iterations)), .profile = ({ __auto_type _mv = c.selection; types_Profile _mr = {0}; int _mm = 0; switch (_mv.tag) { case types_ProfileSelection_explicit: { __auto_type p = _mv.data.explicit; _mr = p; _mm = 1; break; } case types_ProfileSelection_slop_auto: { _mr = types_Profile_profile_el; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }), .auto_select = ({ __auto_type _mv = c.selection; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case types_ProfileSelection_explicit: { _mr = 0; _mm = 1; break; } case types_ProfileSelection_slop_auto: { _mr = 1; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }), .cancel = c.cancel_ptr});
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

types_ReasonerConfig howl_options_config(howl_Options o) {
    SLOP_PRE(((o.workers >= 1)), "(>= (. o workers) 1)");
    SLOP_PRE(((o.workers <= 64)), "(<= (. o workers) 64)");
    SLOP_PRE(((o.max_iterations >= 0)), "(>= (. o max-iterations) 0)");
    SLOP_PRE(((o.max_iterations <= 10000)), "(<= (. o max-iterations) 10000)");
    {
        __auto_type c = types_default_config();
        c.worker_count = ((uint8_t)(SLOP_RANGE(uint8_t, o.workers, 1, 1, 1, 64, "(Int 1 .. 64) at howl.slop:726:50")));
        c.max_iterations = ((uint16_t)(SLOP_RANGE(uint16_t, o.max_iterations, 1, 1, 0, 10000, "(Int 0 .. 10000) at howl.slop:727:55")));
        c.selection = ((o.auto_select) ? ((types_ProfileSelection){ .tag = types_ProfileSelection_slop_auto }) : ((types_ProfileSelection){ .tag = types_ProfileSelection_explicit, .data.explicit = o.profile }));
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

howl_Run howl_faulted(slop_arena* a, howl_FaultKind kind, slop_string message, types_Profile profile) {
    return howl_new_run(a, ((howl_RunState){.arena = a, .outcome = (slop_option_types_Outcome){.has_value = false}, .fault = kind, .message = message, .fault_profile = profile, .verdict = types_Verdict_verdict_inconclusive, .lines = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = a })}));
}

howl_Run howl_run_classify(howl_Input in, howl_Options o) {
    {
        __auto_type a = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type st = (*howl_input_state(in));
        __auto_type _mv_1067 = howl_options_problem(o);
        if (_mv_1067.has_value) {
            __auto_type why = _mv_1067.value;
            return howl_faulted(a, howl_FaultKind_fault_invalid_options, why, o.profile);
        } else if (!_mv_1067.has_value) {
            __auto_type _mv_1068 = st.failed;
            if (_mv_1068.has_value) {
                __auto_type why = _mv_1068.value;
                return howl_faulted(a, howl_FaultKind_fault_input_error, string_concat(a, SLOP_STR(""), why), o.profile);
            } else if (!_mv_1068.has_value) {
                __auto_type _mv_1069 = howl_classify_encoded(a, (*st.enc), st.imports, howl_options_config(o));
                if (_mv_1069.is_ok) {
                    __auto_type out = _mv_1069.data.ok;
                    return howl_new_run(a, ((howl_RunState){.arena = a, .outcome = (slop_option_types_Outcome){.has_value = 1, .value = out}, .fault = howl_FaultKind_fault_none, .message = SLOP_STR(""), .fault_profile = out.profile, .verdict = types_verdict(out), .lines = report_report_lines(a, out)}));
                } else if (!_mv_1069.is_ok) {
                    __auto_type f = _mv_1069.data.err;
                    __auto_type _mv_1070 = f;
                    switch (_mv_1070.tag) {
                        case types_Fault_cancelled:
                        {
                            return howl_faulted(a, howl_FaultKind_fault_cancelled, SLOP_STR(""), o.profile);
                        }
                        case types_Fault_input_error:
                        {
                            __auto_type m = _mv_1070.data.input_error;
                            return howl_faulted(a, howl_FaultKind_fault_input_error, m, o.profile);
                        }
                        case types_Fault_unavailable:
                        {
                            __auto_type p = _mv_1070.data.unavailable;
                            return howl_faulted(a, howl_FaultKind_fault_unavailable, select_unavailable_message(a, p), p);
                        }
                        case types_Fault_refused:
                        {
                            __auto_type _ = _mv_1070.data.refused;
                            return howl_faulted(a, howl_FaultKind_fault_input_error, SLOP_STR("refused under a strict profile"), o.profile);
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
}

void howl_run_free(howl_Run r) {
    {
        __auto_type st = howl_run_state(r);
        __auto_type _mv_1071 = st.outcome;
        if (_mv_1071.has_value) {
            __auto_type o = _mv_1071.value;
            howl_release_outcome(o);
        } else if (!_mv_1071.has_value) {
        }
        ({ slop_arena_free(st.arena); free(st.arena); });
    }
}

uint8_t howl_run_ok(howl_Run r) {
    __auto_type _mv_1072 = howl_run_state(r).outcome;
    if (_mv_1072.has_value) {
        __auto_type _ = _mv_1072.value;
        return 1;
    } else if (!_mv_1072.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

howl_FaultKind howl_run_fault(howl_Run r) {
    return howl_run_state(r).fault;
}

slop_string howl_run_fault_message(howl_Run r) {
    return howl_run_state(r).message;
}

types_Profile howl_run_fault_profile(howl_Run r) {
    return howl_run_state(r).fault_profile;
}

types_Profile howl_run_profile(howl_Run r) {
    return howl_run_state(r).fault_profile;
}

types_Verdict howl_run_verdict(howl_Run r) {
    return howl_run_state(r).verdict;
}

uint8_t howl_run_inconsistent(howl_Run r) {
    __auto_type _mv_1073 = howl_run_state(r).outcome;
    if (_mv_1073.has_value) {
        __auto_type o = _mv_1073.value;
        return o.findings.inconsistent;
    } else if (!_mv_1073.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

types_Termination howl_run_termination(howl_Run r) {
    __auto_type _mv_1074 = howl_run_state(r).outcome;
    if (_mv_1074.has_value) {
        __auto_type o = _mv_1074.value;
        return o.termination;
    } else if (!_mv_1074.has_value) {
        return ((types_Termination){ .tag = types_Termination_resource_limit, .data.resource_limit = 0 });
    }
    SLOP_UNREACHABLE();
}

int64_t howl_run_rounds(howl_Run r) {
    __auto_type _mv_1075 = howl_run_state(r).outcome;
    if (_mv_1075.has_value) {
        __auto_type o = _mv_1075.value;
        return o.rounds;
    } else if (!_mv_1075.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

int64_t howl_run_unsat_len(howl_Run r) {
    __auto_type _mv_1076 = howl_run_state(r).outcome;
    if (_mv_1076.has_value) {
        __auto_type o = _mv_1076.value;
        return ((int64_t)(((int64_t)((o.findings.unsatisfiable).len))));
    } else if (!_mv_1076.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string howl_run_unsat(howl_Run r, int64_t i) {
    __auto_type _mv_1077 = howl_run_state(r).outcome;
    if (_mv_1077.has_value) {
        __auto_type o = _mv_1077.value;
        __auto_type _mv_1078 = ({ __auto_type _lst = o.findings.unsatisfiable; size_t _idx = (size_t)i; slop_option_rdf_IRI _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1078.has_value) {
            __auto_type c = _mv_1078.value;
            return c.value;
        } else if (!_mv_1078.has_value) {
            return SLOP_STR("");
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_1077.has_value) {
        return SLOP_STR("");
    }
    SLOP_UNREACHABLE();
}

int64_t howl_run_sub_len(howl_Run r) {
    __auto_type _mv_1079 = howl_run_state(r).outcome;
    if (_mv_1079.has_value) {
        __auto_type o = _mv_1079.value;
        return ((int64_t)(((int64_t)((o.findings.subsumptions).len))));
    } else if (!_mv_1079.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string howl_run_sub(howl_Run r, int64_t i) {
    {
        __auto_type st = howl_run_state(r);
        __auto_type _mv_1080 = st.outcome;
        if (_mv_1080.has_value) {
            __auto_type o = _mv_1080.value;
            __auto_type _mv_1081 = ({ __auto_type _lst = o.findings.subsumptions; size_t _idx = (size_t)i; slop_option_types_SubPair _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1081.has_value) {
                __auto_type sp = _mv_1081.value;
                return report_node_text(st.arena, sp.sub);
            } else if (!_mv_1081.has_value) {
                return SLOP_STR("");
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_1080.has_value) {
            return SLOP_STR("");
        }
        SLOP_UNREACHABLE();
    }
}

slop_string howl_run_super(howl_Run r, int64_t i) {
    {
        __auto_type st = howl_run_state(r);
        __auto_type _mv_1082 = st.outcome;
        if (_mv_1082.has_value) {
            __auto_type o = _mv_1082.value;
            __auto_type _mv_1083 = ({ __auto_type _lst = o.findings.subsumptions; size_t _idx = (size_t)i; slop_option_types_SubPair _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1083.has_value) {
                __auto_type sp = _mv_1083.value;
                return report_node_text(st.arena, sp.super);
            } else if (!_mv_1083.has_value) {
                return SLOP_STR("");
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_1082.has_value) {
            return SLOP_STR("");
        }
        SLOP_UNREACHABLE();
    }
}

int64_t howl_run_omission_len(howl_Run r) {
    __auto_type _mv_1084 = howl_run_state(r).outcome;
    if (_mv_1084.has_value) {
        __auto_type o = _mv_1084.value;
        return ((int64_t)(((int64_t)((o.coverage.omitted).len))));
    } else if (!_mv_1084.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string howl_run_omission(howl_Run r, int64_t i) {
    {
        __auto_type st = howl_run_state(r);
        __auto_type _mv_1085 = st.outcome;
        if (_mv_1085.has_value) {
            __auto_type o = _mv_1085.value;
            __auto_type _mv_1086 = ({ __auto_type _lst = o.coverage.omitted; size_t _idx = (size_t)i; slop_option_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1086.has_value) {
                __auto_type om = _mv_1086.value;
                return owl2_render_omission(st.arena, om);
            } else if (!_mv_1086.has_value) {
                return SLOP_STR("");
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_1085.has_value) {
            return SLOP_STR("");
        }
        SLOP_UNREACHABLE();
    }
}

int64_t howl_run_report_len(howl_Run r) {
    return ((int64_t)(((int64_t)((howl_run_state(r).lines).len))));
}

slop_string howl_run_report_line(howl_Run r, int64_t i) {
    __auto_type _mv_1087 = ({ __auto_type _lst = howl_run_state(r).lines; size_t _idx = (size_t)i; slop_option_string _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1087.has_value) {
        __auto_type l = _mv_1087.value;
        return l;
    } else if (!_mv_1087.has_value) {
        return SLOP_STR("");
    }
    SLOP_UNREACHABLE();
}

