#include "../runtime/slop_runtime.h"
#include "slop_types.h"

types_ReasonerConfig howl_default_config(void);
types_Node types_node_top(void);
types_Node types_node_bottom(void);
uint8_t types_node_eq(types_Node a, types_Node b);
uint8_t types_role_eq(types_RoleId a, types_RoleId b);
types_Context types_make_context(slop_arena* arena, types_Node root);
types_Queue types_make_queue(slop_arena* arena);
uint8_t types_queue_is_active(types_Queue q);
types_EdgePair types_emit_edge(slop_arena* arena, types_LogicalEdge e);
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

types_Node types_node_top(void) {
    return ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = vocab_OWL_THING}) });
}

types_Node types_node_bottom(void) {
    return ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = vocab_OWL_NOTHING}) });
}

uint8_t types_node_eq(types_Node a, types_Node b) {
    __auto_type _mv_10 = a;
    switch (_mv_10.tag) {
        case types_Node_class_node:
        {
            __auto_type ai = _mv_10.data.class_node;
            __auto_type _mv_11 = b;
            switch (_mv_11.tag) {
                case types_Node_class_node:
                {
                    __auto_type bi = _mv_11.data.class_node;
                    return string_eq(ai.value, bi.value);
                }
                case types_Node_individual_node:
                {
                    __auto_type _ = _mv_11.data.individual_node;
                    return 0;
                }
                case types_Node_fresh_node:
                {
                    __auto_type _ = _mv_11.data.fresh_node;
                    return 0;
                }
            }
        }
        case types_Node_individual_node:
        {
            __auto_type ai = _mv_10.data.individual_node;
            __auto_type _mv_12 = b;
            switch (_mv_12.tag) {
                case types_Node_individual_node:
                {
                    __auto_type bi = _mv_12.data.individual_node;
                    return string_eq(ai.value, bi.value);
                }
                case types_Node_class_node:
                {
                    __auto_type _ = _mv_12.data.class_node;
                    return 0;
                }
                case types_Node_fresh_node:
                {
                    __auto_type _ = _mv_12.data.fresh_node;
                    return 0;
                }
            }
        }
        case types_Node_fresh_node:
        {
            __auto_type ai = _mv_10.data.fresh_node;
            __auto_type _mv_13 = b;
            switch (_mv_13.tag) {
                case types_Node_fresh_node:
                {
                    __auto_type bi = _mv_13.data.fresh_node;
                    return (ai == bi);
                }
                case types_Node_class_node:
                {
                    __auto_type _ = _mv_13.data.class_node;
                    return 0;
                }
                case types_Node_individual_node:
                {
                    __auto_type _ = _mv_13.data.individual_node;
                    return 0;
                }
            }
        }
    }
}

uint8_t types_role_eq(types_RoleId a, types_RoleId b) {
    __auto_type _mv_14 = a;
    switch (_mv_14.tag) {
        case types_RoleId_named_role:
        {
            __auto_type ai = _mv_14.data.named_role;
            __auto_type _mv_15 = b;
            switch (_mv_15.tag) {
                case types_RoleId_named_role:
                {
                    __auto_type bi = _mv_15.data.named_role;
                    return string_eq(ai.value, bi.value);
                }
                case types_RoleId_fresh_role:
                {
                    __auto_type _ = _mv_15.data.fresh_role;
                    return 0;
                }
            }
        }
        case types_RoleId_fresh_role:
        {
            __auto_type ai = _mv_14.data.fresh_role;
            __auto_type _mv_16 = b;
            switch (_mv_16.tag) {
                case types_RoleId_fresh_role:
                {
                    __auto_type bi = _mv_16.data.fresh_role;
                    return (ai == bi);
                }
                case types_RoleId_named_role:
                {
                    __auto_type _ = _mv_16.data.named_role;
                    return 0;
                }
            }
        }
    }
}

types_Context types_make_context(slop_arena* arena, types_Node root) {
    types_Context _retval = {0};
    _retval = ((types_Context){.root = root, .subsumers = slop_map_new_ptr(arena, 16, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node), .succs = slop_map_new_ptr(arena, 16, sizeof(types_RoleId), slop_hash_types_RoleId, slop_eq_types_RoleId), .preds = slop_map_new_ptr(arena, 16, sizeof(types_RoleId), slop_hash_types_RoleId, slop_eq_types_RoleId)});
    SLOP_POST(((_retval.root == root)), "(== (. $result root) root)");
    return _retval;
}

types_Queue types_make_queue(slop_arena* arena) {
    types_Queue _retval = {0};
    _retval = ((types_Queue){.items = ((slop_list_types_Derived){ .data = (types_Derived*)slop_arena_alloc(arena, 16 * sizeof(types_Derived)), .len = 0, .cap = 16 })});
    SLOP_POST(((((int64_t)((_retval.items).len)) == 0)), "(== (list-len (. $result items)) 0)");
    return _retval;
}

uint8_t types_queue_is_active(types_Queue q) {
    uint8_t _retval = {0};
    _retval = (((int64_t)((q.items).len)) > 0);
    SLOP_POST(((_retval == (((int64_t)((q.items).len)) > 0))), "(== $result (> (list-len (. q items)) 0))");
    return _retval;
}

types_EdgePair types_emit_edge(slop_arena* arena, types_LogicalEdge e) {
    types_EdgePair _retval = {0};
    _retval = ((types_EdgePair){.succ_half = ((types_Addressed){.to = e.from, .what = ((types_Derived){ .tag = types_Derived_derived_succ, .data.derived_succ = { .f0 = e.role, .f1 = e.to } })}), .pred_half = ((types_Addressed){.to = e.to, .what = ((types_Derived){ .tag = types_Derived_derived_pred, .data.derived_pred = { .f0 = e.role, .f1 = e.from } })})});
    SLOP_POST(((_retval.succ_half.to == e.from)), "(== (. (. $result succ-half) to) (. e from))");
    SLOP_POST(((_retval.pred_half.to == e.to)), "(== (. (. $result pred-half) to) (. e to))");
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

