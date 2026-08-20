#include "../runtime/slop_runtime.h"
#include "slop_saturate.h"

uint8_t saturate_frontier_is_empty(slop_arena* arena, types_Saturation sat);
uint8_t saturate_budget_exhausted(types_Saturation sat, types_ReasonerConfig config);
slop_result_saturate_RoundResult_types_Fault saturate_saturate(slop_arena* arena, types_Saturation sat, slop_list_types_NormAxiom axioms, types_ReasonerConfig config);
types_Saturation saturate_advance_round(slop_arena* arena, types_Saturation sat, slop_list_types_NormAxiom axioms, types_ReasonerConfig config);

uint8_t saturate_frontier_is_empty(slop_arena* arena, types_Saturation sat) {
    return (((int64_t)((({ slop_set_elements_result _r = slop_set_elements_raw(arena, sat.active); (slop_list_types_Node){.data = (types_Node*)_r.data, .len = _r.len, .cap = _r.cap}; })).len)) == 0);
}

uint8_t saturate_budget_exhausted(types_Saturation sat, types_ReasonerConfig config) {
    SLOP_PRE(((sat.iteration >= 0)), "(>= (. sat iteration) 0)");
    uint8_t _retval = {0};
    _retval = (sat.iteration >= config.max_iterations);
    SLOP_POST(((_retval == (sat.iteration >= config.max_iterations))), "(== $result (>= (. sat iteration) (. config max-iterations)))");
    return _retval;
}

slop_result_saturate_RoundResult_types_Fault saturate_saturate(slop_arena* arena, types_Saturation sat, slop_list_types_NormAxiom axioms, types_ReasonerConfig config) {
    slop_result_saturate_RoundResult_types_Fault _retval = {0};
    {
        __auto_type state = sat;
        while (!(saturate_frontier_is_empty(arena, state))) {
            if (saturate_budget_exhausted(state, config)) {
                break;
            } else {
                state = saturate_advance_round(arena, state, axioms, config);
            }
        }
        if (saturate_frontier_is_empty(arena, state)) {
            _retval = ((slop_result_saturate_RoundResult_types_Fault){ .is_ok = true, .data.ok = ((saturate_RoundResult){.saturation = state, .termination = ((types_Termination){ .tag = types_Termination_fixpoint })}) });
        } else {
            _retval = ((slop_result_saturate_RoundResult_types_Fault){ .is_ok = true, .data.ok = ((saturate_RoundResult){.saturation = state, .termination = ((types_Termination){ .tag = types_Termination_resource_limit, .data.resource_limit = state.iteration })}) });
        }
    }
    SLOP_POST((({ __auto_type _mv = _retval; uint8_t _mr; if (_mv.is_ok) { __auto_type r = _mv.data.ok; _mr = (r.saturation.iteration <= config.max_iterations); } else { __auto_type _ = _mv.data.err; _mr = 1; } _mr; })), "(match $result ((ok r) (<= (. (. r saturation) iteration) (. config max-iterations))) ((error _) true))");
    return _retval;
}

types_Saturation saturate_advance_round(slop_arena* arena, types_Saturation sat, slop_list_types_NormAxiom axioms, types_ReasonerConfig config) {
    types_Saturation _retval = {0};
    _retval = ((types_Saturation){.contexts = sat.contexts, .active = slop_map_new_ptr(arena, 16, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node), .iteration = (sat.iteration + 1)});
    SLOP_POST(((_retval.iteration == (sat.iteration + 1))), "(== (. $result iteration) (+ (. sat iteration) 1))");
    SLOP_POST(((_retval.iteration > sat.iteration)), "(> (. $result iteration) (. sat iteration))");
    return _retval;
}

