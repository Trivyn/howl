#include "../runtime/slop_runtime.h"
#include "slop_howl.h"

howl_Verdict howl_verdict(types_Outcome o);
slop_result_normalize_Decoded_types_Fault howl_decode(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved);
slop_result_normalize_Decoded_types_Fault howl_decode_from(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved);
slop_result_normalize_Decoded_types_Fault howl_own_decoded(slop_arena* arena, slop_result_normalize_Decoded_types_Fault r);
slop_result_normalize_Decoded_types_Fault howl_decode_owned(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved);
slop_result_howl_Prepared_types_Fault howl_prepare_decoded(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config);
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
    __auto_type _mv_865 = r;
    if (_mv_865.is_ok) {
        __auto_type d = _mv_865.data.ok;
        return ((slop_result_normalize_Decoded_types_Fault){ .is_ok = true, .data.ok = normalize_copy_decoded(arena, d) });
    } else if (!_mv_865.is_ok) {
        __auto_type f = _mv_865.data.err;
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
    {
        __auto_type profile = select_select_profile(config.selection);
        if (!(select_profile_implemented(profile))) {
            return ((slop_result_howl_Prepared_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_unavailable, .data.unavailable = profile }) });
        } else {
            return howl_prepare_in_profile(arena, d, config, profile);
        }
    }
}

slop_result_howl_Prepared_types_Fault howl_prepare_in_profile(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config, types_Profile profile) {
    __auto_type _mv_866 = profile;
    if (_mv_866 == types_Profile_profile_el_plus_plus) {
        return howl_prepare_ksc(arena, d, config, profile);
    } else if (_mv_866 == types_Profile_profile_el) {
        return howl_prepare_el(arena, d, config, profile);
    } else if (_mv_866 == types_Profile_profile_horn_sriq) {
        return howl_prepare_el(arena, d, config, profile);
    } else if (_mv_866 == types_Profile_profile_sriq) {
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
        __auto_type out = ((slop_list_types_KName){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (kscnormal_copy_kname(arena, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    __auto_type _mv_867 = p.work;
    switch (_mv_867.tag) {
        case howl_Work_el_work:
        {
            __auto_type w = _mv_867.data.el_work;
            __auto_type _mv_868 = saturate_saturate(arena, w.saturation, w.index, config);
            if (!_mv_868.is_ok) {
                __auto_type f = _mv_868.data.err;
                return ((slop_result_types_Outcome_types_Fault){ .is_ok = false, .data.err = f });
            } else if (_mv_868.is_ok) {
                __auto_type rr = _mv_868.data.ok;
                return ((slop_result_types_Outcome_types_Fault){ .is_ok = true, .data.ok = ((types_Outcome){.profile = p.profile, .coverage = p.coverage, .termination = rr.termination, .findings = classify_extract_findings(arena, rr.saturation, p.names), .evidence = ((types_Evidence){ .tag = types_Evidence_el_evidence, .data.el_evidence = rr.saturation }), .rounds = rr.saturation.iteration, .names = p.names}) });
            }
            SLOP_UNREACHABLE();
        }
        case howl_Work_ksc_work:
        {
            __auto_type w = _mv_867.data.ksc_work;
            {
                __auto_type r = kscsat_ksc_classify(arena, w.axioms, w.classes, config);
                return ((slop_result_types_Outcome_types_Fault){ .is_ok = true, .data.ok = ((types_Outcome){.profile = p.profile, .coverage = p.coverage, .termination = r.termination, .findings = classify_extract_ksc_findings(arena, r), .evidence = ((types_Evidence){ .tag = types_Evidence_ksc_evidence, .data.ksc_evidence = r }), .rounds = r.rounds, .names = p.names}) });
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_types_Outcome_types_Fault howl_classify(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config) {
    __auto_type _mv_869 = howl_prepare(arena, triples, imports_resolved, config);
    if (!_mv_869.is_ok) {
        __auto_type f = _mv_869.data.err;
        return ((slop_result_types_Outcome_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_869.is_ok) {
        __auto_type p = _mv_869.data.ok;
        return howl_reason(arena, p, config);
    }
    SLOP_UNREACHABLE();
}

