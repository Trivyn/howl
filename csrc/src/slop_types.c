#include "../runtime/slop_runtime.h"
#include "slop_types.h"

types_ReasonerConfig howl_default_config(void);
types_Node types_node_top(void);
types_Node types_node_bottom(void);
uint8_t types_node_eq(types_Node a, types_Node b);
uint8_t types_role_eq(types_RoleId a, types_RoleId b);
types_Names types_empty_names(slop_arena* arena);
types_Node types_intern_node(slop_arena* arena, types_Names names, types_Node n);
types_RoleId types_intern_role(slop_arena* arena, types_Names names, types_RoleId r);
slop_option_types_Node types_renamed_node(types_Names names, types_Node n);
types_Node types_original_node(types_Names names, types_Node n);
types_RoleId types_original_role(types_Names names, types_RoleId r);
types_Context types_make_context(slop_arena* arena, types_Node root);
types_Queue types_make_queue(slop_arena* arena);
uint8_t types_queue_is_active(types_Queue q);
uint8_t types_derived_eq(types_Derived a, types_Derived b);
uint8_t types_addressed_eq(types_Addressed a, types_Addressed b);
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
    __auto_type _mv_12 = a;
    switch (_mv_12.tag) {
        case types_Node_class_node:
        {
            __auto_type ai = _mv_12.data.class_node;
            __auto_type _mv_13 = b;
            switch (_mv_13.tag) {
                case types_Node_class_node:
                {
                    __auto_type bi = _mv_13.data.class_node;
                    return string_eq(ai.value, bi.value);
                }
                case types_Node_individual_node:
                {
                    __auto_type _ = _mv_13.data.individual_node;
                    return 0;
                }
                case types_Node_fresh_node:
                {
                    __auto_type _ = _mv_13.data.fresh_node;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_Node_individual_node:
        {
            __auto_type ai = _mv_12.data.individual_node;
            __auto_type _mv_14 = b;
            switch (_mv_14.tag) {
                case types_Node_individual_node:
                {
                    __auto_type bi = _mv_14.data.individual_node;
                    return string_eq(ai.value, bi.value);
                }
                case types_Node_class_node:
                {
                    __auto_type _ = _mv_14.data.class_node;
                    return 0;
                }
                case types_Node_fresh_node:
                {
                    __auto_type _ = _mv_14.data.fresh_node;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_Node_fresh_node:
        {
            __auto_type ai = _mv_12.data.fresh_node;
            __auto_type _mv_15 = b;
            switch (_mv_15.tag) {
                case types_Node_fresh_node:
                {
                    __auto_type bi = _mv_15.data.fresh_node;
                    return (ai == bi);
                }
                case types_Node_class_node:
                {
                    __auto_type _ = _mv_15.data.class_node;
                    return 0;
                }
                case types_Node_individual_node:
                {
                    __auto_type _ = _mv_15.data.individual_node;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t types_role_eq(types_RoleId a, types_RoleId b) {
    __auto_type _mv_16 = a;
    switch (_mv_16.tag) {
        case types_RoleId_named_role:
        {
            __auto_type ai = _mv_16.data.named_role;
            __auto_type _mv_17 = b;
            switch (_mv_17.tag) {
                case types_RoleId_named_role:
                {
                    __auto_type bi = _mv_17.data.named_role;
                    return string_eq(ai.value, bi.value);
                }
                case types_RoleId_fresh_role:
                {
                    __auto_type _ = _mv_17.data.fresh_role;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_RoleId_fresh_role:
        {
            __auto_type ai = _mv_16.data.fresh_role;
            __auto_type _mv_18 = b;
            switch (_mv_18.tag) {
                case types_RoleId_fresh_role:
                {
                    __auto_type bi = _mv_18.data.fresh_role;
                    return (ai == bi);
                }
                case types_RoleId_named_role:
                {
                    __auto_type _ = _mv_18.data.named_role;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

types_Names types_empty_names(slop_arena* arena) {
    return ((types_Names){.node_ids = slop_map_new_ptr(arena, 0, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node), .nodes = slop_map_new_ptr(arena, 0, sizeof(int64_t), slop_hash_int, slop_eq_int), .role_ids = slop_map_new_ptr(arena, 0, sizeof(types_RoleId), slop_hash_types_RoleId, slop_eq_types_RoleId), .roles = slop_map_new_ptr(arena, 0, sizeof(int64_t), slop_hash_int, slop_eq_int)});
}

types_Node types_intern_node(slop_arena* arena, types_Names names, types_Node n) {
    {
        __auto_type top = types_node_top();
        __auto_type bottom = types_node_bottom();
        if (types_node_eq(n, top)) {
            return n;
        } else {
            if (types_node_eq(n, bottom)) {
                return n;
            } else {
                __auto_type _mv_20 = ({ void* _ptr = slop_map_get(names.node_ids, &(n)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
                if (_mv_20.has_value) {
                    __auto_type k = _mv_20.value;
                    return ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = k });
                } else if (!_mv_20.has_value) {
                    {
                        __auto_type k = ((int64_t)(((int64_t)(names.nodes)->len)));
                        ({ int64_t _val = k; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, names.node_ids, &(n), _vptr); });
                        ({ __auto_type _val = n; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, names.nodes, &(int64_t){k}, _vptr); });
                        return ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = k });
                    }
                }
                SLOP_UNREACHABLE();
            }
        }
    }
}

types_RoleId types_intern_role(slop_arena* arena, types_Names names, types_RoleId r) {
    __auto_type _mv_24 = ({ void* _ptr = slop_map_get(names.role_ids, &(r)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
    if (_mv_24.has_value) {
        __auto_type k = _mv_24.value;
        return ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = k });
    } else if (!_mv_24.has_value) {
        {
            __auto_type k = ((int64_t)(((int64_t)(names.roles)->len)));
            ({ int64_t _val = k; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, names.role_ids, &(r), _vptr); });
            ({ __auto_type _val = r; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, names.roles, &(int64_t){k}, _vptr); });
            return ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = k });
        }
    }
    SLOP_UNREACHABLE();
}

slop_option_types_Node types_renamed_node(types_Names names, types_Node n) {
    __auto_type _mv_28 = ({ void* _ptr = slop_map_get(names.node_ids, &(n)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
    if (_mv_28.has_value) {
        __auto_type k = _mv_28.value;
        return (slop_option_types_Node){.has_value = 1, .value = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = k })};
    } else if (!_mv_28.has_value) {
        __auto_type _mv_29 = n;
        switch (_mv_29.tag) {
            case types_Node_fresh_node:
            {
                __auto_type _ = _mv_29.data.fresh_node;
                if (((int64_t)(names.nodes)->len) == 0) {
                    return (slop_option_types_Node){.has_value = 1, .value = n};
                } else {
                    return (slop_option_types_Node){.has_value = false};
                }
            }
            case types_Node_class_node:
            {
                __auto_type _ = _mv_29.data.class_node;
                return (slop_option_types_Node){.has_value = 1, .value = n};
            }
            case types_Node_individual_node:
            {
                __auto_type _ = _mv_29.data.individual_node;
                return (slop_option_types_Node){.has_value = 1, .value = n};
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

types_Node types_original_node(types_Names names, types_Node n) {
    __auto_type _mv_30 = n;
    switch (_mv_30.tag) {
        case types_Node_fresh_node:
        {
            __auto_type k = _mv_30.data.fresh_node;
            __auto_type _mv_32 = ({ void* _ptr = slop_map_get(names.nodes, &(int64_t){k}); _ptr ? (slop_option_types_Node){ .has_value = true, .value = *(types_Node*)_ptr } : (slop_option_types_Node){ .has_value = false }; });
            if (_mv_32.has_value) {
                __auto_type o = _mv_32.value;
                return o;
            } else if (!_mv_32.has_value) {
                return n;
            }
            SLOP_UNREACHABLE();
        }
        case types_Node_class_node:
        {
            __auto_type _ = _mv_30.data.class_node;
            return n;
        }
        case types_Node_individual_node:
        {
            __auto_type _ = _mv_30.data.individual_node;
            return n;
        }
    }
    SLOP_UNREACHABLE();
}

types_RoleId types_original_role(types_Names names, types_RoleId r) {
    __auto_type _mv_33 = r;
    switch (_mv_33.tag) {
        case types_RoleId_fresh_role:
        {
            __auto_type k = _mv_33.data.fresh_role;
            __auto_type _mv_35 = ({ void* _ptr = slop_map_get(names.roles, &(int64_t){k}); _ptr ? (slop_option_types_RoleId){ .has_value = true, .value = *(types_RoleId*)_ptr } : (slop_option_types_RoleId){ .has_value = false }; });
            if (_mv_35.has_value) {
                __auto_type o = _mv_35.value;
                return o;
            } else if (!_mv_35.has_value) {
                return r;
            }
            SLOP_UNREACHABLE();
        }
        case types_RoleId_named_role:
        {
            __auto_type _ = _mv_33.data.named_role;
            return r;
        }
    }
    SLOP_UNREACHABLE();
}

types_Context types_make_context(slop_arena* arena, types_Node root) {
    types_Context _retval = {0};
    _retval = ((types_Context){.root = root, .subsumers = slop_map_new_ptr(arena, 0, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node), .succs = slop_map_new_ptr(arena, 0, sizeof(types_RoleId), slop_hash_types_RoleId, slop_eq_types_RoleId), .preds = slop_map_new_ptr(arena, 0, sizeof(types_RoleId), slop_hash_types_RoleId, slop_eq_types_RoleId)});
    SLOP_POST((({ types_Node _eq_l_36 = (_retval.root); types_Node _eq_r_37 = (root); slop_eq_types_Node(&_eq_l_36, &_eq_r_37); })), "(== (. $result root) root)");
    return _retval;
}

types_Queue types_make_queue(slop_arena* arena) {
    types_Queue _retval = {0};
    _retval = ((types_Queue){.items = ((slop_list_types_Derived){ .data = NULL, .len = 0, .cap = 0 })});
    SLOP_POST(((((int64_t)((_retval.items).len)) == 0)), "(== (list-len (. $result items)) 0)");
    return _retval;
}

uint8_t types_queue_is_active(types_Queue q) {
    uint8_t _retval = {0};
    _retval = (((int64_t)((q.items).len)) > 0);
    SLOP_POST(((_retval == (((int64_t)((q.items).len)) > 0))), "(== $result (> (list-len (. q items)) 0))");
    return _retval;
}

uint8_t types_derived_eq(types_Derived a, types_Derived b) {
    __auto_type _mv_38 = a;
    switch (_mv_38.tag) {
        case types_Derived_derived_sub:
        {
            __auto_type an = _mv_38.data.derived_sub;
            __auto_type _mv_39 = b;
            switch (_mv_39.tag) {
                case types_Derived_derived_sub:
                {
                    __auto_type bn = _mv_39.data.derived_sub;
                    return types_node_eq(an, bn);
                }
                case types_Derived_derived_succ:
                {
                    return 0;
                }
                case types_Derived_derived_pred:
                {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_Derived_derived_succ:
        {
            __auto_type ar = _mv_38.data.derived_succ.f0;
            __auto_type an = _mv_38.data.derived_succ.f1;
            __auto_type _mv_40 = b;
            switch (_mv_40.tag) {
                case types_Derived_derived_succ:
                {
                    __auto_type br = _mv_40.data.derived_succ.f0;
                    __auto_type bn = _mv_40.data.derived_succ.f1;
                    if (types_role_eq(ar, br)) {
                        return types_node_eq(an, bn);
                    } else {
                        return 0;
                    }
                }
                case types_Derived_derived_sub:
                {
                    __auto_type _ = _mv_40.data.derived_sub;
                    return 0;
                }
                case types_Derived_derived_pred:
                {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_Derived_derived_pred:
        {
            __auto_type ar = _mv_38.data.derived_pred.f0;
            __auto_type an = _mv_38.data.derived_pred.f1;
            __auto_type _mv_41 = b;
            switch (_mv_41.tag) {
                case types_Derived_derived_pred:
                {
                    __auto_type br = _mv_41.data.derived_pred.f0;
                    __auto_type bn = _mv_41.data.derived_pred.f1;
                    if (types_role_eq(ar, br)) {
                        return types_node_eq(an, bn);
                    } else {
                        return 0;
                    }
                }
                case types_Derived_derived_sub:
                {
                    __auto_type _ = _mv_41.data.derived_sub;
                    return 0;
                }
                case types_Derived_derived_succ:
                {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t types_addressed_eq(types_Addressed a, types_Addressed b) {
    if (types_node_eq(a.to, b.to)) {
        return types_derived_eq(a.what, b.what);
    } else {
        return 0;
    }
}

types_EdgePair types_emit_edge(slop_arena* arena, types_LogicalEdge e) {
    types_EdgePair _retval = {0};
    _retval = ((types_EdgePair){.succ_half = ((types_Addressed){.to = e.from, .what = ((types_Derived){ .tag = types_Derived_derived_succ, .data.derived_succ = { .f0 = e.role, .f1 = e.to } })}), .pred_half = ((types_Addressed){.to = e.to, .what = ((types_Derived){ .tag = types_Derived_derived_pred, .data.derived_pred = { .f0 = e.role, .f1 = e.from } })})});
    SLOP_POST((({ types_Node _eq_l_42 = (_retval.succ_half.to); types_Node _eq_r_43 = (e.from); slop_eq_types_Node(&_eq_l_42, &_eq_r_43); })), "(== (. (. $result succ-half) to) (. e from))");
    SLOP_POST((({ types_Node _eq_l_44 = (_retval.pred_half.to); types_Node _eq_r_45 = (e.to); slop_eq_types_Node(&_eq_l_44, &_eq_r_45); })), "(== (. (. $result pred-half) to) (. e to))");
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

