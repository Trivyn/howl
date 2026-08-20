#include "../runtime/slop_runtime.h"
#include "slop_types.h"

types_ReasonerConfig howl_default_config(void);
types_Context types_make_context(slop_arena* arena, types_Node root);
uint8_t types_context_is_active(types_Context ctx);
types_EdgePair types_emit_edge(slop_arena* arena, types_Node x, types_RoleId r, types_Node y);
uint8_t types_outcome_is_complete(types_Outcome o);
uint8_t types_findings_are_incoherent(types_Findings f);

types_ReasonerConfig howl_default_config(void) {
    types_ReasonerConfig _retval = {0};
    _retval = ((types_ReasonerConfig){.worker_count = 4, .channel_buffer = 256, .max_iterations = 1000, .selection = ((types_ProfileSelection){ .tag = types_ProfileSelection_slop_auto }), .strict_profile = 0, .cancel_ptr = 0, .verbose = 0});
    SLOP_POST(((_retval.worker_count == 4)), "(== (. $result worker-count) 4)");
    SLOP_POST(((_retval.channel_buffer == 256)), "(== (. $result channel-buffer) 256)");
    SLOP_POST(((_retval.max_iterations == 1000)), "(== (. $result max-iterations) 1000)");
    SLOP_POST(((_retval.cancel_ptr == 0)), "(== (. $result cancel-ptr) 0)");
    SLOP_POST(((_retval.verbose == 0)), "(== (. $result verbose) false)");
    SLOP_POST(((_retval.strict_profile == 0)), "(== (. $result strict-profile) false)");
    return _retval;
}

types_Context types_make_context(slop_arena* arena, types_Node root) {
    types_Context _retval = {0};
    _retval = ((types_Context){.root = root, .subsumers = slop_map_new_ptr(arena, 16, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node), .succs = slop_map_new_ptr(arena, 16, sizeof(types_RoleId), slop_hash_types_RoleId, slop_eq_types_RoleId), .preds = slop_map_new_ptr(arena, 16, sizeof(types_RoleId), slop_hash_types_RoleId, slop_eq_types_RoleId), .queue = ((slop_list_types_Derived){ .data = (types_Derived*)slop_arena_alloc(arena, 16 * sizeof(types_Derived)), .len = 0, .cap = 16 })});
    SLOP_POST(((_retval.root == root)), "(== (. $result root) root)");
    SLOP_POST(((((int64_t)((_retval.queue).len)) == 0)), "(== (list-len (. $result queue)) 0)");
    return _retval;
}

uint8_t types_context_is_active(types_Context ctx) {
    uint8_t _retval = {0};
    _retval = (((int64_t)((ctx.queue).len)) > 0);
    SLOP_POST(((_retval == (((int64_t)((ctx.queue).len)) > 0))), "(== $result (> (list-len (. ctx queue)) 0))");
    return _retval;
}

types_EdgePair types_emit_edge(slop_arena* arena, types_Node x, types_RoleId r, types_Node y) {
    types_EdgePair _retval = {0};
    _retval = ((types_EdgePair){.succ_half = ((types_Addressed){.to = x, .what = ((types_Derived){ .tag = types_Derived_derived_succ, .data.derived_succ = { .f0 = r, .f1 = y } })}), .pred_half = ((types_Addressed){.to = y, .what = ((types_Derived){ .tag = types_Derived_derived_pred, .data.derived_pred = { .f0 = r, .f1 = x } })})});
    SLOP_POST(((_retval.succ_half.to == x)), "(== (. (. $result succ-half) to) x)");
    SLOP_POST(((_retval.pred_half.to == y)), "(== (. (. $result pred-half) to) y)");
    return _retval;
}

uint8_t types_outcome_is_complete(types_Outcome o) {
    uint8_t _retval = {0};
    _retval = ((((int64_t)((o.coverage.omitted).len)) == 0) && ({ __auto_type _mv = o.termination; uint8_t _mr = {0}; switch (_mv.tag) { case types_Termination_fixpoint: { _mr = 1; break; } case types_Termination_resource_limit: { __auto_type _ = _mv.data.resource_limit; _mr = 0; break; }  } _mr; }));
    return _retval;
}

uint8_t types_findings_are_incoherent(types_Findings f) {
    uint8_t _retval = {0};
    if (((int64_t)((f.unsatisfiable).len)) > 0) {
        _retval = 1;
    } else {
        _retval = f.inconsistent;
    }
    return _retval;
}

