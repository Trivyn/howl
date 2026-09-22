#include "../runtime/slop_runtime.h"
#include "slop_howl.h"

howl_Verdict howl_verdict(types_Outcome o);
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

slop_result_howl_Prepared_types_Fault howl_prepare(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config) {
    __auto_type _mv_500 = normalize_normalize_input(arena, triples, imports_resolved, config);
    if (!_mv_500.is_ok) {
        __auto_type f = _mv_500.data.err;
        return ((slop_result_howl_Prepared_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_500.is_ok) {
        __auto_type nr = _mv_500.data.ok;
        if (config.strict_profile && (((int64_t)((nr.coverage.omitted).len)) > 0)) {
            return ((slop_result_howl_Prepared_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_refused, .data.refused = nr.coverage.omitted }) });
        } else {
            return ((slop_result_howl_Prepared_types_Fault){ .is_ok = true, .data.ok = ((howl_Prepared){.axioms = nr.axioms, .index = premise_build_rule_index(arena, nr.axioms), .saturation = nr.saturation, .coverage = nr.coverage}) });
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_types_Outcome_types_Fault howl_reason(slop_arena* arena, howl_Prepared p, types_ReasonerConfig config) {
    __auto_type _mv_501 = saturate_saturate(arena, p.saturation, p.index, config);
    if (!_mv_501.is_ok) {
        __auto_type f = _mv_501.data.err;
        return ((slop_result_types_Outcome_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_501.is_ok) {
        __auto_type rr = _mv_501.data.ok;
        return ((slop_result_types_Outcome_types_Fault){ .is_ok = true, .data.ok = ((types_Outcome){.coverage = p.coverage, .termination = rr.termination, .findings = classify_extract_findings(arena, rr.saturation), .saturation = rr.saturation}) });
    }
    SLOP_UNREACHABLE();
}

slop_result_types_Outcome_types_Fault howl_classify(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config) {
    __auto_type _mv_502 = howl_prepare(arena, triples, imports_resolved, config);
    if (!_mv_502.is_ok) {
        __auto_type f = _mv_502.data.err;
        return ((slop_result_types_Outcome_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_502.is_ok) {
        __auto_type p = _mv_502.data.ok;
        return howl_reason(arena, p, config);
    }
    SLOP_UNREACHABLE();
}

