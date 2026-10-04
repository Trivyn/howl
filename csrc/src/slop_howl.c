#include "../runtime/slop_runtime.h"
#include "slop_howl.h"

howl_Verdict howl_verdict(types_Outcome o);
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

howl_Verdict howl_verdict(types_Outcome o) {
    howl_Verdict _retval = {0};
    if (types_findings_are_incoherent(o.findings)) {
        _retval = howl_Verdict_verdict_incoherent;
        goto _slop_post;
    } else {
        if (((int64_t)((o.coverage.omitted).len)) > 0) {
            _retval = howl_Verdict_verdict_inconclusive;
            goto _slop_post;
        } else {
            if (types_outcome_is_complete(o)) {
                _retval = howl_Verdict_verdict_coherent;
                goto _slop_post;
            } else {
                _retval = howl_Verdict_verdict_inconclusive;
                goto _slop_post;
            }
        }
    }
    _slop_post: ;
    return _retval;
}

slop_result_normalize_Decoded_types_Fault howl_decode(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved) {
    return normalize_decode_document(arena, triples, imports_resolved);
}

slop_result_normalize_Decoded_types_Fault howl_decode_from(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved) {
    return normalize_decode_encoded(arena, doc, imports_resolved);
}

slop_result_normalize_Decoded_types_Fault howl_own_decoded(slop_arena* arena, slop_result_normalize_Decoded_types_Fault r) {
    __auto_type _mv_954 = r;
    if (_mv_954.is_ok) {
        __auto_type d = _mv_954.data.ok;
        return ((slop_result_normalize_Decoded_types_Fault){ .is_ok = true, .data.ok = normalize_copy_decoded(arena, d) });
    } else if (!_mv_954.is_ok) {
        __auto_type f = _mv_954.data.err;
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
    __auto_type _mv_955 = select_select_profile(config.selection);
    if (_mv_955.has_value) {
        __auto_type profile = _mv_955.value;
        if (!(select_profile_implemented(profile))) {
            return ((slop_result_howl_Prepared_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_unavailable, .data.unavailable = profile }) });
        } else {
            return howl_prepare_in_profile(arena, d, config, profile);
        }
    } else if (!_mv_955.has_value) {
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
                __auto_type _mv_956 = o;
                switch (_mv_956.tag) {
                    case types_Omission_out_of_profile:
                    {
                        __auto_type _ = _mv_956.data.out_of_profile;
                        n = (n + 1);
                        break;
                    }
                    case types_Omission_unresolved_import:
                    {
                        __auto_type _ = _mv_956.data.unresolved_import;
                        break;
                    }
                    case types_Omission_missing_declaration:
                    {
                        __auto_type _ = _mv_956.data.missing_declaration;
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
        __auto_type chosen = select_choose_auto(((int64_t)(SLOP_RANGE(int64_t, out_el, 1, 0, 0, 0, "(Int 0 ..) at howl.slop:323:50"))), ((int64_t)(SLOP_RANGE(int64_t, out_pp, 1, 0, 0, 0, "(Int 0 ..) at howl.slop:323:75"))));
        ({ slop_arena_free(scratch); free(scratch); });
        return chosen;
    }
}

slop_result_howl_Prepared_types_Fault howl_prepare_in_profile(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config, types_Profile profile) {
    __auto_type _mv_957 = profile;
    if (_mv_957 == types_Profile_profile_el_plus_plus) {
        return howl_prepare_ksc(arena, d, config, profile);
    } else if (_mv_957 == types_Profile_profile_el) {
        return howl_prepare_el(arena, d, config, profile);
    } else if (_mv_957 == types_Profile_profile_horn_sriq) {
        return howl_prepare_el(arena, d, config, profile);
    } else if (_mv_957 == types_Profile_profile_sriq) {
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
    __auto_type _mv_958 = p.work;
    switch (_mv_958.tag) {
        case howl_Work_el_work:
        {
            __auto_type w = _mv_958.data.el_work;
            __auto_type _mv_959 = saturate_saturate(arena, w.saturation, w.index, config);
            if (!_mv_959.is_ok) {
                __auto_type f = _mv_959.data.err;
                return ((slop_result_types_Outcome_types_Fault){ .is_ok = false, .data.err = f });
            } else if (_mv_959.is_ok) {
                __auto_type rr = _mv_959.data.ok;
                return ((slop_result_types_Outcome_types_Fault){ .is_ok = true, .data.ok = ((types_Outcome){.profile = p.profile, .coverage = p.coverage, .termination = rr.termination, .findings = classify_extract_findings(arena, rr.saturation, p.names), .evidence = ((types_Evidence){ .tag = types_Evidence_el_evidence, .data.el_evidence = rr.saturation }), .rounds = rr.saturation.iteration, .names = p.names}) });
            }
            SLOP_UNREACHABLE();
        }
        case howl_Work_ksc_work:
        {
            __auto_type w = _mv_958.data.ksc_work;
            __auto_type _mv_960 = kscsat_ksc_classify(arena, w.axioms, w.classes, config);
            if (!_mv_960.is_ok) {
                __auto_type f = _mv_960.data.err;
                return ((slop_result_types_Outcome_types_Fault){ .is_ok = false, .data.err = f });
            } else if (_mv_960.is_ok) {
                __auto_type r = _mv_960.data.ok;
                return ((slop_result_types_Outcome_types_Fault){ .is_ok = true, .data.ok = ((types_Outcome){.profile = p.profile, .coverage = p.coverage, .termination = r.termination, .findings = classify_extract_ksc_findings(arena, r), .evidence = ((types_Evidence){ .tag = types_Evidence_ksc_evidence, .data.ksc_evidence = r }), .rounds = r.rounds, .names = p.names}) });
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_types_Outcome_types_Fault howl_classify(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config) {
    __auto_type _mv_961 = howl_prepare(arena, triples, imports_resolved, config);
    if (!_mv_961.is_ok) {
        __auto_type f = _mv_961.data.err;
        return ((slop_result_types_Outcome_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_961.is_ok) {
        __auto_type p = _mv_961.data.ok;
        return howl_reason(arena, p, config);
    }
    SLOP_UNREACHABLE();
}

