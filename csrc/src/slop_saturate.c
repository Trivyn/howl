#include "../runtime/slop_runtime.h"
#include "slop_saturate.h"

slop_option_types_Context saturate_context_of(types_Saturation sat, types_Node n);
slop_option_types_Queue saturate_queue_of(types_Saturation sat, types_Node n);
uint8_t saturate_store_has_sub(types_Saturation sat, types_Node x, types_Node b);
uint8_t saturate_store_has_succ(types_Saturation sat, types_Node x, types_RoleId r, types_Node y);
types_Context saturate_delta_context(slop_arena* arena, saturate_RoundDelta delta, types_Node x);
void saturate_add_succ(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node y);
void saturate_add_pred(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node x);
void saturate_admit_sub(slop_arena* arena, types_Saturation sat, saturate_RoundDelta delta, types_Node x, types_Node b);
void saturate_admit_edge(slop_arena* arena, types_Saturation sat, saturate_RoundDelta delta, types_LogicalEdge e);
void saturate_admit(slop_arena* arena, types_Saturation sat, saturate_RoundDelta delta, types_Addressed m);
void saturate_round_join(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, saturate_RoundDelta delta);
types_Context saturate_ensure_context(slop_arena* arena, types_Saturation sat, types_Node n);
types_Saturation saturate_round_commit(slop_arena* arena, types_Saturation sat, saturate_RoundDelta delta);
types_Saturation saturate_advance_round(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, types_ReasonerConfig config);
uint8_t saturate_seed_node(slop_arena* arena, types_Saturation sat, types_Node n);
types_Saturation saturate_make_initial_saturation(slop_arena* arena, slop_list_types_Node signature);
uint8_t saturate_frontier_is_empty(types_Saturation sat);
uint8_t saturate_budget_exhausted(types_Saturation sat, types_ReasonerConfig config);
slop_result_saturate_RoundResult_types_Fault saturate_saturate(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, types_ReasonerConfig config);
uint8_t saturate_deliver_seed(slop_arena* arena, types_Saturation sat, types_Node to, types_Derived d);

slop_option_types_Context saturate_context_of(types_Saturation sat, types_Node n) {
    return ({ void* _ptr = slop_map_get(sat.contexts, &(n)); _ptr ? (slop_option_types_Context){ .has_value = true, .value = *(types_Context*)_ptr } : (slop_option_types_Context){ .has_value = false }; });
}

slop_option_types_Queue saturate_queue_of(types_Saturation sat, types_Node n) {
    return ({ void* _ptr = slop_map_get(sat.queues, &(n)); _ptr ? (slop_option_types_Queue){ .has_value = true, .value = *(types_Queue*)_ptr } : (slop_option_types_Queue){ .has_value = false }; });
}

uint8_t saturate_store_has_sub(types_Saturation sat, types_Node x, types_Node b) {
    __auto_type _mv_253 = ({ void* _ptr = slop_map_get(sat.contexts, &(x)); _ptr ? (slop_option_types_Context){ .has_value = true, .value = *(types_Context*)_ptr } : (slop_option_types_Context){ .has_value = false }; });
    if (_mv_253.has_value) {
        __auto_type ctx = _mv_253.value;
        return (slop_map_get(ctx.subsumers, &(b)) != NULL);
    } else if (!_mv_253.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t saturate_store_has_succ(types_Saturation sat, types_Node x, types_RoleId r, types_Node y) {
    __auto_type _mv_256 = ({ void* _ptr = slop_map_get(sat.contexts, &(x)); _ptr ? (slop_option_types_Context){ .has_value = true, .value = *(types_Context*)_ptr } : (slop_option_types_Context){ .has_value = false }; });
    if (_mv_256.has_value) {
        __auto_type ctx = _mv_256.value;
        __auto_type _mv_258 = ({ void* _ptr = slop_map_get(ctx.succs, &(r)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
        if (_mv_258.has_value) {
            __auto_type ys = _mv_258.value;
            return (slop_map_get(ys, &(y)) != NULL);
        } else if (!_mv_258.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_256.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

types_Context saturate_delta_context(slop_arena* arena, saturate_RoundDelta delta, types_Node x) {
    __auto_type _mv_261 = ({ void* _ptr = slop_map_get(delta.pending, &(x)); _ptr ? (slop_option_types_Context){ .has_value = true, .value = *(types_Context*)_ptr } : (slop_option_types_Context){ .has_value = false }; });
    if (_mv_261.has_value) {
        __auto_type c = _mv_261.value;
        return c;
    } else if (!_mv_261.has_value) {
        {
            __auto_type c = types_make_context(arena, x);
            ({ __auto_type _val = c; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, delta.pending, &(x), _vptr); });
            return c;
        }
    }
    SLOP_UNREACHABLE();
}

void saturate_add_succ(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node y) {
    __auto_type _mv_264 = ({ void* _ptr = slop_map_get(ctx.succs, &(r)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
    if (_mv_264.has_value) {
        __auto_type s = _mv_264.value;
        ({ uint8_t _dummy = 1; slop_map_put(arena, s, &(y), &_dummy); });
    } else if (!_mv_264.has_value) {
        {
            __auto_type s = slop_map_new_ptr(arena, 16, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node);
            ({ uint8_t _dummy = 1; slop_map_put(arena, s, &(y), &_dummy); });
            ({ __auto_type _val = s; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, ctx.succs, &(r), _vptr); });
        }
    }
}

void saturate_add_pred(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node x) {
    __auto_type _mv_269 = ({ void* _ptr = slop_map_get(ctx.preds, &(r)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
    if (_mv_269.has_value) {
        __auto_type s = _mv_269.value;
        ({ uint8_t _dummy = 1; slop_map_put(arena, s, &(x), &_dummy); });
    } else if (!_mv_269.has_value) {
        {
            __auto_type s = slop_map_new_ptr(arena, 16, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node);
            ({ uint8_t _dummy = 1; slop_map_put(arena, s, &(x), &_dummy); });
            ({ __auto_type _val = s; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, ctx.preds, &(r), _vptr); });
        }
    }
}

void saturate_admit_sub(slop_arena* arena, types_Saturation sat, saturate_RoundDelta delta, types_Node x, types_Node b) {
    if (!(saturate_store_has_sub(sat, x, b))) {
        {
            __auto_type dc = saturate_delta_context(arena, delta, x);
            ({ uint8_t _dummy = 1; slop_map_put(arena, dc.subsumers, &(b), &_dummy); });
        }
    }
}

void saturate_admit_edge(slop_arena* arena, types_Saturation sat, saturate_RoundDelta delta, types_LogicalEdge e) {
    if (!(saturate_store_has_succ(sat, e.from, e.role, e.to))) {
        {
            __auto_type dx = saturate_delta_context(arena, delta, e.from);
            __auto_type dy = saturate_delta_context(arena, delta, e.to);
            __auto_type r = e.role;
            __auto_type x = e.from;
            __auto_type y = e.to;
            saturate_add_succ(arena, dx, r, y);
            saturate_add_pred(arena, dy, r, x);
        }
    }
}

void saturate_admit(slop_arena* arena, types_Saturation sat, saturate_RoundDelta delta, types_Addressed m) {
    __auto_type _mv_274 = m.what;
    switch (_mv_274.tag) {
        case types_Derived_derived_sub:
        {
            __auto_type b = _mv_274.data.derived_sub;
            saturate_admit_sub(arena, sat, delta, m.to, b);
            break;
        }
        case types_Derived_derived_succ:
        {
            __auto_type r = _mv_274.data.derived_succ.f0;
            __auto_type y = _mv_274.data.derived_succ.f1;
            saturate_admit_edge(arena, sat, delta, ((types_LogicalEdge){.from = m.to, .role = r, .to = y}));
            break;
        }
        case types_Derived_derived_pred:
        {
            __auto_type r = _mv_274.data.derived_pred.f0;
            __auto_type x = _mv_274.data.derived_pred.f1;
            saturate_admit_edge(arena, sat, delta, ((types_LogicalEdge){.from = x, .role = r, .to = m.to}));
            break;
        }
    }
}

void saturate_round_join(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, saturate_RoundDelta delta) {
    {
        slop_map* _coll = (slop_map*)sat.active;
        for (size_t _i = 0; _i < _coll->cap; _i++) {
            if (_coll->entries[_i].occupied) {
                types_Node n = *(types_Node*)_coll->entries[_i].key;
                __auto_type _mv_275 = saturate_context_of(sat, n);
                if (_mv_275.has_value) {
                    __auto_type ctx = _mv_275.value;
                    __auto_type _mv_276 = saturate_queue_of(sat, n);
                    if (_mv_276.has_value) {
                        __auto_type q = _mv_276.value;
                        {
                            __auto_type _coll = q.items;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type d = _coll.data[_i];
                                {
                                    __auto_type _coll = el_apply_el_rules(arena, ctx, d, idx);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        saturate_admit(arena, sat, delta, m);
                                    }
                                }
                            }
                        }
                    } else if (!_mv_276.has_value) {
                    }
                } else if (!_mv_275.has_value) {
                }
            }
        }
    }
}

types_Context saturate_ensure_context(slop_arena* arena, types_Saturation sat, types_Node n) {
    __auto_type _mv_278 = ({ void* _ptr = slop_map_get(sat.contexts, &(n)); _ptr ? (slop_option_types_Context){ .has_value = true, .value = *(types_Context*)_ptr } : (slop_option_types_Context){ .has_value = false }; });
    if (_mv_278.has_value) {
        __auto_type c = _mv_278.value;
        return c;
    } else if (!_mv_278.has_value) {
        {
            __auto_type c = types_make_context(arena, n);
            ({ __auto_type _val = c; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, sat.contexts, &(n), _vptr); });
            return c;
        }
    }
    SLOP_UNREACHABLE();
}

types_Saturation saturate_round_commit(slop_arena* arena, types_Saturation sat, saturate_RoundDelta delta) {
    types_Saturation _retval = {0};
    {
        __auto_type new_queues = slop_map_new_ptr(arena, 16, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node);
        __auto_type new_active = slop_map_new_ptr(arena, 16, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node);
        int64_t count = 0;
        {
            slop_map* _coll = (slop_map*)delta.pending;
            for (size_t _i = 0; _i < _coll->cap; _i++) {
                if (_coll->entries[_i].occupied) {
                    types_Node x = *(types_Node*)_coll->entries[_i].key;
                    types_Context dc = *(types_Context*)_coll->entries[_i].value;
                    {
                        __auto_type store = saturate_ensure_context(arena, sat, x);
                        __auto_type q = types_make_queue(arena);
                        {
                            slop_map* _coll = (slop_map*)dc.subsumers;
                            for (size_t _i = 0; _i < _coll->cap; _i++) {
                                if (_coll->entries[_i].occupied) {
                                    types_Node b = *(types_Node*)_coll->entries[_i].key;
                                    ({ uint8_t _dummy = 1; slop_map_put(arena, store.subsumers, &(b), &_dummy); });
                                    ({ __auto_type _lst_p = &(q.items); __auto_type _item = (((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = b })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                        {
                            slop_map* _coll = (slop_map*)dc.succs;
                            for (size_t _i = 0; _i < _coll->cap; _i++) {
                                if (_coll->entries[_i].occupied) {
                                    types_RoleId r = *(types_RoleId*)_coll->entries[_i].key;
                                    slop_map* ys = *(slop_map**)_coll->entries[_i].value;
                                    {
                                        slop_map* _coll = (slop_map*)ys;
                                        for (size_t _i = 0; _i < _coll->cap; _i++) {
                                            if (_coll->entries[_i].occupied) {
                                                types_Node y = *(types_Node*)_coll->entries[_i].key;
                                                saturate_add_succ(arena, store, r, y);
                                                ({ __auto_type _lst_p = &(q.items); __auto_type _item = (((types_Derived){ .tag = types_Derived_derived_succ, .data.derived_succ = { .f0 = r, .f1 = y } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        {
                            slop_map* _coll = (slop_map*)dc.preds;
                            for (size_t _i = 0; _i < _coll->cap; _i++) {
                                if (_coll->entries[_i].occupied) {
                                    types_RoleId r = *(types_RoleId*)_coll->entries[_i].key;
                                    slop_map* ps = *(slop_map**)_coll->entries[_i].value;
                                    {
                                        slop_map* _coll = (slop_map*)ps;
                                        for (size_t _i = 0; _i < _coll->cap; _i++) {
                                            if (_coll->entries[_i].occupied) {
                                                types_Node p = *(types_Node*)_coll->entries[_i].key;
                                                saturate_add_pred(arena, store, r, p);
                                                ({ __auto_type _lst_p = &(q.items); __auto_type _item = (((types_Derived){ .tag = types_Derived_derived_pred, .data.derived_pred = { .f0 = r, .f1 = p } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        ({ __auto_type _val = q; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, new_queues, &(x), _vptr); });
                        ({ uint8_t _dummy = 1; slop_map_put(arena, new_active, &(x), &_dummy); });
                        count = (count + 1);
                    }
                }
            }
        }
        _retval = ((types_Saturation){.contexts = sat.contexts, .queues = new_queues, .active = new_active, .active_count = count, .iteration = (sat.iteration + 1)});
    }
    SLOP_POST(((_retval.iteration == (sat.iteration + 1))), "(== (. $result iteration) (+ (. sat iteration) 1))");
    SLOP_POST(((_retval.iteration > sat.iteration)), "(> (. $result iteration) (. sat iteration))");
    SLOP_POST(((_retval.active_count >= 0)), "(>= (. $result active-count) 0)");
    return _retval;
}

types_Saturation saturate_advance_round(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, types_ReasonerConfig config) {
    {
        #ifdef SLOP_DEBUG
        SLOP_PRE((16777216) > 0, "with-arena size must be positive");
        #endif
        slop_arena _arena_scratch = slop_arena_new(16777216);
        #ifdef SLOP_DEBUG
        SLOP_PRE(_arena_scratch.base != NULL, "arena allocation failed");
        #endif
        slop_arena* scratch = &_arena_scratch;
        {
            __auto_type delta = ((saturate_RoundDelta){.pending = slop_map_new_ptr(scratch, 16, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node)});
            saturate_round_join(scratch, sat, idx, delta);
            return saturate_round_commit(arena, sat, delta);
        }
        slop_arena_free(scratch);
    }
}

uint8_t saturate_seed_node(slop_arena* arena, types_Saturation sat, types_Node n) {
    if (slop_map_get(sat.contexts, &(n)) != NULL) {
        return 0;
    } else {
        {
            __auto_type ctx = types_make_context(arena, n);
            __auto_type q = types_make_queue(arena);
            __auto_type top = types_node_top();
            ({ __auto_type _lst_p = &(q.items); __auto_type _item = (((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = n })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(q.items); __auto_type _item = (((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = top })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ uint8_t _dummy = 1; slop_map_put(arena, ctx.subsumers, &(n), &_dummy); });
            ({ uint8_t _dummy = 1; slop_map_put(arena, ctx.subsumers, &(top), &_dummy); });
            ({ __auto_type _val = ctx; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, sat.contexts, &(n), _vptr); });
            ({ __auto_type _val = q; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, sat.queues, &(n), _vptr); });
            ({ uint8_t _dummy = 1; slop_map_put(arena, sat.active, &(n), &_dummy); });
            return 1;
        }
    }
}

types_Saturation saturate_make_initial_saturation(slop_arena* arena, slop_list_types_Node signature) {
    types_Saturation _retval = {0};
    {
        __auto_type acc = ((types_Saturation){.contexts = slop_map_new_ptr(arena, 16, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node), .queues = slop_map_new_ptr(arena, 16, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node), .active = slop_map_new_ptr(arena, 16, sizeof(types_Node), slop_hash_types_Node, slop_eq_types_Node), .active_count = 0, .iteration = 0});
        int64_t count = 0;
        {
            __auto_type _coll = signature;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                if (saturate_seed_node(arena, acc, n)) {
                    count = (count + 1);
                }
            }
        }
        if (saturate_seed_node(arena, acc, types_node_top())) {
            count = (count + 1);
        }
        if (saturate_seed_node(arena, acc, types_node_bottom())) {
            count = (count + 1);
        }
        _retval = ((types_Saturation){.contexts = acc.contexts, .queues = acc.queues, .active = acc.active, .active_count = count, .iteration = 0});
    }
    SLOP_POST(((_retval.iteration == 0)), "(== (. $result iteration) 0)");
    return _retval;
}

uint8_t saturate_frontier_is_empty(types_Saturation sat) {
    SLOP_PRE(((sat.active_count >= 0)), "(>= (. sat active-count) 0)");
    uint8_t _retval = {0};
    _retval = (sat.active_count == 0);
    SLOP_POST(((_retval == (sat.active_count == 0))), "(== $result (== (. sat active-count) 0))");
    return _retval;
}

uint8_t saturate_budget_exhausted(types_Saturation sat, types_ReasonerConfig config) {
    SLOP_PRE(((sat.iteration >= 0)), "(>= (. sat iteration) 0)");
    uint8_t _retval = {0};
    _retval = (sat.iteration >= config.max_iterations);
    SLOP_POST(((_retval == (sat.iteration >= config.max_iterations))), "(== $result (>= (. sat iteration) (. config max-iterations)))");
    return _retval;
}

slop_result_saturate_RoundResult_types_Fault saturate_saturate(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, types_ReasonerConfig config) {
    slop_result_saturate_RoundResult_types_Fault _retval = {0};
    {
        __auto_type state = sat;
        uint8_t cancelled = 0;
        while (!(saturate_frontier_is_empty(state))) {
            if (config.cancel_ptr && __atomic_load_n((uint32_t*)(uintptr_t)config.cancel_ptr, __ATOMIC_RELAXED)) { cancelled = 1; };
            if (cancelled) {
                break;
            } else {
                if (saturate_budget_exhausted(state, config)) {
                    break;
                } else {
                    state = saturate_advance_round(arena, state, idx, config);
                }
            }
        }
        if (cancelled) {
            _retval = ((slop_result_saturate_RoundResult_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_cancelled }) });
        } else {
            if (saturate_frontier_is_empty(state)) {
                _retval = ((slop_result_saturate_RoundResult_types_Fault){ .is_ok = true, .data.ok = ((saturate_RoundResult){.saturation = state, .termination = ((types_Termination){ .tag = types_Termination_fixpoint })}) });
            } else {
                _retval = ((slop_result_saturate_RoundResult_types_Fault){ .is_ok = true, .data.ok = ((saturate_RoundResult){.saturation = state, .termination = ((types_Termination){ .tag = types_Termination_resource_limit, .data.resource_limit = state.iteration })}) });
            }
        }
    }
    SLOP_POST((({ __auto_type _mv = _retval; uint8_t _mr; if (_mv.is_ok) { __auto_type r = _mv.data.ok; _mr = (r.saturation.iteration <= config.max_iterations); } else { __auto_type _ = _mv.data.err; _mr = 1; } _mr; })), "(match $result ((ok r) (<= (. (. r saturation) iteration) (. config max-iterations))) ((error _) true))");
    return _retval;
}

uint8_t saturate_deliver_seed(slop_arena* arena, types_Saturation sat, types_Node to, types_Derived d) {
    __auto_type _mv_290 = ({ void* _ptr = slop_map_get(sat.queues, &(to)); _ptr ? (slop_option_types_Queue){ .has_value = true, .value = *(types_Queue*)_ptr } : (slop_option_types_Queue){ .has_value = false }; });
    if (!_mv_290.has_value) {
        return 0;
    } else if (_mv_290.has_value) {
        __auto_type q = _mv_290.value;
        {
            __auto_type qq = q;
            __auto_type store = saturate_ensure_context(arena, sat, to);
            __auto_type _mv_291 = d;
            switch (_mv_291.tag) {
                case types_Derived_derived_sub:
                {
                    __auto_type b = _mv_291.data.derived_sub;
                    ({ uint8_t _dummy = 1; slop_map_put(arena, store.subsumers, &(b), &_dummy); });
                    break;
                }
                case types_Derived_derived_succ:
                {
                    __auto_type r = _mv_291.data.derived_succ.f0;
                    __auto_type y = _mv_291.data.derived_succ.f1;
                    saturate_add_succ(arena, store, r, y);
                    break;
                }
                case types_Derived_derived_pred:
                {
                    __auto_type r = _mv_291.data.derived_pred.f0;
                    __auto_type x = _mv_291.data.derived_pred.f1;
                    saturate_add_pred(arena, store, r, x);
                    break;
                }
            }
            ({ __auto_type _lst_p = &(qq.items); __auto_type _item = (d); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _val = qq; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, sat.queues, &(to), _vptr); });
            ({ uint8_t _dummy = 1; slop_map_put(arena, sat.active, &(to), &_dummy); });
            return 1;
        }
    }
    SLOP_UNREACHABLE();
}

