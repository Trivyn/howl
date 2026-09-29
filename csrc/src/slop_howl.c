#include "../runtime/slop_runtime.h"
#include "slop_howl.h"

howl_Verdict howl_verdict(types_Outcome o);
slop_result_normalize_Decoded_types_Fault howl_decode(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved);
slop_result_howl_Prepared_types_Fault howl_prepare_decoded(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config);
slop_result_howl_Prepared_types_Fault howl_prepare(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);
slop_result_types_Outcome_types_Fault howl_reason(slop_arena* arena, howl_Prepared p, types_ReasonerConfig config);
slop_result_types_Outcome_types_Fault howl_classify(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);

howl_Verdict howl_verdict(types_Outcome o) {
    howl_Verdict _retval = {0};
    if (types_findings_are_incoherent(o.findings)) {
        _retval = howl_Verdict_verdict_incoherent;
    } else {
        if (((int64_t)((o.coverage.omitted).len)) > 0) {
            _retval = howl_Verdict_verdict_inconclusive;
        } else {
            if (types_outcome_is_complete(o)) {
                _retval = howl_Verdict_verdict_coherent;
            } else {
                _retval = howl_Verdict_verdict_inconclusive;
            }
        }
    }
    return _retval;
}

slop_result_normalize_Decoded_types_Fault howl_decode(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved) {
    return normalize_decode_document(arena, triples, imports_resolved);
}

slop_result_howl_Prepared_types_Fault howl_prepare_decoded(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type nr = normalize_normalize_decoded(arena, scratch, d);
        __auto_type res = (((config.strict_profile && (((int64_t)((nr.coverage.omitted).len)) > 0))) ? ((slop_result_howl_Prepared_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_refused, .data.refused = nr.coverage.omitted }) }) : ((slop_result_howl_Prepared_types_Fault){ .is_ok = true, .data.ok = ((howl_Prepared){.axioms = nr.axioms, .index = premise_build_rule_index(arena, nr.axioms), .saturation = nr.saturation, .coverage = nr.coverage, .names = nr.names}) }));
        ({ slop_arena_free(scratch); free(scratch); });
        return res;
    }
}

slop_result_howl_Prepared_types_Fault howl_prepare(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config) {
    {
        __auto_type front = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type res = ({ __auto_type _mv = howl_decode(front, triples, imports_resolved); slop_result_howl_Prepared_types_Fault _mr; if (_mv.is_ok) { __auto_type d = _mv.data.ok; _mr = howl_prepare_decoded(arena, d, config); } else { __auto_type f = _mv.data.err; _mr = ((slop_result_howl_Prepared_types_Fault){ .is_ok = false, .data.err = types_copy_fault(arena, f) }); } _mr; });
        ({ slop_arena_free(front); free(front); });
        return res;
    }
}

slop_result_types_Outcome_types_Fault howl_reason(slop_arena* arena, howl_Prepared p, types_ReasonerConfig config) {
    __auto_type _mv_573 = saturate_saturate(arena, p.saturation, p.index, config);
    if (!_mv_573.is_ok) {
        __auto_type f = _mv_573.data.err;
        return ((slop_result_types_Outcome_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_573.is_ok) {
        __auto_type rr = _mv_573.data.ok;
        return ((slop_result_types_Outcome_types_Fault){ .is_ok = true, .data.ok = ((types_Outcome){.coverage = p.coverage, .termination = rr.termination, .findings = classify_extract_findings(arena, rr.saturation, p.names), .saturation = rr.saturation, .names = p.names}) });
    }
    SLOP_UNREACHABLE();
}

slop_result_types_Outcome_types_Fault howl_classify(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config) {
    __auto_type _mv_574 = howl_prepare(arena, triples, imports_resolved, config);
    if (!_mv_574.is_ok) {
        __auto_type f = _mv_574.data.err;
        return ((slop_result_types_Outcome_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_574.is_ok) {
        __auto_type p = _mv_574.data.ok;
        return howl_reason(arena, p, config);
    }
    SLOP_UNREACHABLE();
}

