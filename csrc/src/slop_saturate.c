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
int64_t saturate_round_join_part(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, saturate_RoundDelta delta, slop_list_types_Node part);
void saturate_reuse_arena(slop_arena* a);
void saturate_join_context(slop_arena* arena, slop_arena* ra, types_Saturation sat, premise_RuleIndex idx, saturate_RoundDelta delta, types_Node n);
types_Context saturate_ensure_context(slop_arena* arena, types_Saturation sat, types_Node n);
saturate_Bucket saturate_bucketed(slop_arena* arena, slop_option_saturate_Bucket found, saturate_Touched e);
int64_t saturate_partition_one(slop_arena* arena, slop_arena* run, types_Saturation sat, saturate_Partition part, types_Node x, types_Context dc, int64_t turn, int64_t w);
int64_t saturate_partition_delta(slop_arena* arena, slop_arena* run, types_Saturation sat, saturate_RoundDelta d, saturate_Partition part, int64_t turn, int64_t w);
slop_list_saturate_Touched saturate_bucket_items(slop_arena* arena, slop_option_saturate_Bucket found);
saturate_Partition saturate_partition_round(slop_arena* arena, slop_arena* run, types_Saturation sat, slop_list_saturate_RoundDelta deltas, int64_t w);
uint8_t saturate_commit_succ(slop_arena* arena, types_Context store, types_RoleId r, types_Node y);
uint8_t saturate_commit_pred(slop_arena* arena, types_Context store, types_RoleId r, types_Node x);
uint8_t saturate_commit_sub(slop_arena* arena, types_Context store, types_Node b);
void saturate_commit_entry(slop_arena* arena, slop_arena* ca, types_Saturation sat, saturate_Touched e, saturate_Queues qs);
int64_t saturate_commit_bucket(slop_arena* arena, slop_arena* ca, types_Saturation sat, slop_list_saturate_Touched entries, saturate_Queues qs);
types_Saturation saturate_commit_round(slop_arena* arena, slop_arena* run, slop_arena* scratch, types_Saturation sat, slop_list_saturate_RoundDelta deltas, slop_list_arena_ptr cas, slop_list_arena_ptr qas);
slop_list_arena_ptr saturate_generation_arenas(slop_arena* arena, int64_t w);
slop_list_arena_ptr saturate_committer_arenas(slop_arena* arena, slop_list_arena_ptr gen);
saturate_Advanced saturate_advance_round(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, types_ReasonerConfig config, slop_list_arena_ptr cas);
saturate_Joined saturate_parallel_join(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, int64_t w);
uint8_t saturate_seed_node(slop_arena* arena, types_Saturation sat, types_Node n);
types_Saturation saturate_make_initial_saturation(slop_arena* arena, slop_list_types_Node signature);
uint8_t saturate_frontier_is_empty(types_Saturation sat);
uint8_t saturate_budget_exhausted(types_Saturation sat, types_ReasonerConfig config);
slop_list_arena_ptr saturate_commit_arenas(slop_arena* arena, int64_t w);
slop_result_saturate_RoundResult_types_Fault saturate_saturate(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, types_ReasonerConfig config);
uint8_t saturate_deliver_seed(slop_arena* arena, types_Saturation sat, types_Node to, types_Derived d);

typedef struct { slop_arena* qa; slop_arena* ca; types_Saturation sat; slop_list_saturate_Touched share; saturate_Queues qs; } saturate__lambda_357_env_t;

static int64_t saturate__lambda_357(saturate__lambda_357_env_t* _env) { return saturate_commit_bucket(_env->qa, _env->ca, _env->sat, _env->share, _env->qs); }

typedef struct { slop_arena* wa; types_Saturation sat; premise_RuleIndex idx; saturate_RoundDelta d; slop_list_types_Node share; } saturate__lambda_361_env_t;

static int64_t saturate__lambda_361(saturate__lambda_361_env_t* _env) { return saturate_round_join_part(_env->wa, _env->sat, _env->idx, _env->d, _env->share); }

slop_option_types_Context saturate_context_of(types_Saturation sat, types_Node n) {
    return ({ void* _ptr = slop_map_get(sat.contexts, &(n)); _ptr ? (slop_option_types_Context){ .has_value = true, .value = *(types_Context*)_ptr } : (slop_option_types_Context){ .has_value = false }; });
}

slop_option_types_Queue saturate_queue_of(types_Saturation sat, types_Node n) {
    return ({ void* _ptr = slop_map_get(sat.queues, &(n)); _ptr ? (slop_option_types_Queue){ .has_value = true, .value = *(types_Queue*)_ptr } : (slop_option_types_Queue){ .has_value = false }; });
}

uint8_t saturate_store_has_sub(types_Saturation sat, types_Node x, types_Node b) {
    __auto_type _mv_303 = ({ void* _ptr = slop_map_get(sat.contexts, &(x)); _ptr ? (slop_option_types_Context){ .has_value = true, .value = *(types_Context*)_ptr } : (slop_option_types_Context){ .has_value = false }; });
    if (_mv_303.has_value) {
        __auto_type ctx = _mv_303.value;
        return slop_map_has(ctx.subsumers, &(b));
    } else if (!_mv_303.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t saturate_store_has_succ(types_Saturation sat, types_Node x, types_RoleId r, types_Node y) {
    __auto_type _mv_306 = ({ void* _ptr = slop_map_get(sat.contexts, &(x)); _ptr ? (slop_option_types_Context){ .has_value = true, .value = *(types_Context*)_ptr } : (slop_option_types_Context){ .has_value = false }; });
    if (_mv_306.has_value) {
        __auto_type ctx = _mv_306.value;
        __auto_type _mv_308 = ({ void* _ptr = slop_map_get(ctx.succs, &(r)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
        if (_mv_308.has_value) {
            __auto_type ys = _mv_308.value;
            return slop_map_has(ys, &(y));
        } else if (!_mv_308.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_306.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

types_Context saturate_delta_context(slop_arena* arena, saturate_RoundDelta delta, types_Node x) {
    __auto_type _mv_311 = ({ void* _ptr = slop_map_get(delta.pending, &(x)); _ptr ? (slop_option_types_Context){ .has_value = true, .value = *(types_Context*)_ptr } : (slop_option_types_Context){ .has_value = false }; });
    if (_mv_311.has_value) {
        __auto_type c = _mv_311.value;
        return c;
    } else if (!_mv_311.has_value) {
        {
            __auto_type c = types_make_context(arena, x);
            ({ types_Context _val = c; slop_map_put(arena, delta.pending, &(x), &_val, sizeof(_val)); });
            return c;
        }
    }
    SLOP_UNREACHABLE();
}

void saturate_add_succ(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node y) {
    __auto_type _mv_314 = ({ void* _ptr = slop_map_get(ctx.succs, &(r)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
    if (_mv_314.has_value) {
        __auto_type s = _mv_314.value;
        ({ slop_map_put(arena, s, &(y), NULL, 0); });
    } else if (!_mv_314.has_value) {
        {
            __auto_type s = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
            ({ slop_map_put(arena, s, &(y), NULL, 0); });
            ({ slop_map* _val = s; slop_map_put(arena, ctx.succs, &(r), &_val, sizeof(_val)); });
        }
    }
}

void saturate_add_pred(slop_arena* arena, types_Context ctx, types_RoleId r, types_Node x) {
    __auto_type _mv_319 = ({ void* _ptr = slop_map_get(ctx.preds, &(r)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
    if (_mv_319.has_value) {
        __auto_type s = _mv_319.value;
        ({ slop_map_put(arena, s, &(x), NULL, 0); });
    } else if (!_mv_319.has_value) {
        {
            __auto_type s = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
            ({ slop_map_put(arena, s, &(x), NULL, 0); });
            ({ slop_map* _val = s; slop_map_put(arena, ctx.preds, &(r), &_val, sizeof(_val)); });
        }
    }
}

void saturate_admit_sub(slop_arena* arena, types_Saturation sat, saturate_RoundDelta delta, types_Node x, types_Node b) {
    if (!(saturate_store_has_sub(sat, x, b))) {
        {
            __auto_type dc = saturate_delta_context(arena, delta, x);
            ({ slop_map_put(arena, dc.subsumers, &(b), NULL, 0); });
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
    __auto_type _mv_324 = m.what;
    switch (_mv_324.tag) {
        case types_Derived_derived_sub:
        {
            __auto_type b = _mv_324.data.derived_sub;
            saturate_admit_sub(arena, sat, delta, m.to, b);
            break;
        }
        case types_Derived_derived_succ:
        {
            __auto_type r = _mv_324.data.derived_succ.f0;
            __auto_type y = _mv_324.data.derived_succ.f1;
            saturate_admit_edge(arena, sat, delta, ((types_LogicalEdge){.from = m.to, .role = r, .to = y}));
            break;
        }
        case types_Derived_derived_pred:
        {
            break;
        }
    }
}

void saturate_round_join(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, saturate_RoundDelta delta) {
    {
        __auto_type ra = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        {
            slop_map* _coll = (slop_map*)sat.active;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    types_Node n = *(types_Node*)slop_map_key_at(_coll, _i);
                    saturate_join_context(arena, ra, sat, idx, delta, n);
                }
            }
        }
        ({ slop_arena_free(ra); free(ra); });
    }
}

int64_t saturate_round_join_part(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, saturate_RoundDelta delta, slop_list_types_Node part) {
    {
        __auto_type ra = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        {
            __auto_type _coll = part;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                saturate_join_context(arena, ra, sat, idx, delta, n);
            }
        }
        ({ slop_arena_free(ra); free(ra); });
        return 0;
    }
}

void saturate_reuse_arena(slop_arena* a) {
    slop_arena_reset(a);;
}

void saturate_join_context(slop_arena* arena, slop_arena* ra, types_Saturation sat, premise_RuleIndex idx, saturate_RoundDelta delta, types_Node n) {
    __auto_type _mv_325 = saturate_context_of(sat, n);
    if (_mv_325.has_value) {
        __auto_type ctx = _mv_325.value;
        __auto_type _mv_326 = saturate_queue_of(sat, n);
        if (_mv_326.has_value) {
            __auto_type q = _mv_326.value;
            {
                __auto_type _coll = q.items;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type d = _coll.data[_i];
                    {
                        __auto_type _coll = el_apply_el_rules(ra, ctx, d, idx);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type m = _coll.data[_i];
                            saturate_admit(arena, sat, delta, m);
                        }
                    }
                }
            }
            saturate_reuse_arena(ra);
        } else if (!_mv_326.has_value) {
        }
    } else if (!_mv_325.has_value) {
    }
}

types_Context saturate_ensure_context(slop_arena* arena, types_Saturation sat, types_Node n) {
    __auto_type _mv_328 = ({ void* _ptr = slop_map_get(sat.contexts, &(n)); _ptr ? (slop_option_types_Context){ .has_value = true, .value = *(types_Context*)_ptr } : (slop_option_types_Context){ .has_value = false }; });
    if (_mv_328.has_value) {
        __auto_type c = _mv_328.value;
        return c;
    } else if (!_mv_328.has_value) {
        {
            __auto_type c = types_make_context(arena, n);
            ({ types_Context _val = c; slop_map_put(arena, sat.contexts, &(n), &_val, sizeof(_val)); });
            return c;
        }
    }
    SLOP_UNREACHABLE();
}

saturate_Bucket saturate_bucketed(slop_arena* arena, slop_option_saturate_Bucket found, saturate_Touched e) {
    {
        __auto_type items = ({ __auto_type _mv = found; _mv.has_value ? ({ __auto_type b = _mv.value; b.items; }) : (((slop_list_saturate_Touched){ .data = NULL, .len = 0, .cap = 0 })); });
        ({ __auto_type _lst_p = &(items); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((saturate_Bucket){.items = items});
    }
}

int64_t saturate_partition_one(slop_arena* arena, slop_arena* run, types_Saturation sat, saturate_Partition part, types_Node x, types_Context dc, int64_t turn, int64_t w) {
    saturate_ensure_context(run, sat, x);
    __auto_type _mv_331 = ({ void* _ptr = slop_map_get(part.owner, &(x)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
    if (_mv_331.has_value) {
        __auto_type o = _mv_331.value;
        {
            __auto_type e = ((saturate_Touched){.node = x, .pending = dc});
            __auto_type b = saturate_bucketed(arena, ({ void* _ptr = slop_map_get(part.by_owner, &(int64_t){o}); _ptr ? (slop_option_saturate_Bucket){ .has_value = true, .value = *(saturate_Bucket*)_ptr } : (slop_option_saturate_Bucket){ .has_value = false }; }), e);
            ({ saturate_Bucket _val = b; slop_map_put(arena, part.by_owner, &(int64_t){o}, &_val, sizeof(_val)); });
            return turn;
        }
    } else if (!_mv_331.has_value) {
        {
            __auto_type k = (turn % w);
            __auto_type e = ((saturate_Touched){.node = x, .pending = dc});
            __auto_type b = saturate_bucketed(arena, ({ void* _ptr = slop_map_get(part.by_owner, &(int64_t){k}); _ptr ? (slop_option_saturate_Bucket){ .has_value = true, .value = *(saturate_Bucket*)_ptr } : (slop_option_saturate_Bucket){ .has_value = false }; }), e);
            ({ int64_t _val = k; slop_map_put(arena, part.owner, &(x), &_val, sizeof(_val)); });
            ({ saturate_Bucket _val = b; slop_map_put(arena, part.by_owner, &(int64_t){k}, &_val, sizeof(_val)); });
            return (turn + 1);
        }
    }
    SLOP_UNREACHABLE();
}

int64_t saturate_partition_delta(slop_arena* arena, slop_arena* run, types_Saturation sat, saturate_RoundDelta d, saturate_Partition part, int64_t turn, int64_t w) {
    {
        int64_t t = turn;
        {
            slop_map* _coll = (slop_map*)d.pending;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    types_Node x = *(types_Node*)slop_map_key_at(_coll, _i);
                    types_Context dc = *(types_Context*)slop_map_value_at(_coll, _i);
                    t = saturate_partition_one(arena, run, sat, part, x, dc, t, w);
                }
            }
        }
        return t;
    }
}

slop_list_saturate_Touched saturate_bucket_items(slop_arena* arena, slop_option_saturate_Bucket found) {
    __auto_type _mv_337 = found;
    if (_mv_337.has_value) {
        __auto_type b = _mv_337.value;
        return b.items;
    } else if (!_mv_337.has_value) {
        return ((slop_list_saturate_Touched){ .data = NULL, .len = 0, .cap = 0 });
    }
    SLOP_UNREACHABLE();
}

saturate_Partition saturate_partition_round(slop_arena* arena, slop_arena* run, types_Saturation sat, slop_list_saturate_RoundDelta deltas, int64_t w) {
    {
        __auto_type part = ((saturate_Partition){.owner = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .by_owner = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, saturate_Bucket); slop_map_new_ptr(arena, 0, &_d); })});
        int64_t turn = 0;
        {
            __auto_type _coll = deltas;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type d = _coll.data[_i];
                turn = saturate_partition_delta(arena, run, sat, d, part, turn, w);
            }
        }
        return part;
    }
}

uint8_t saturate_commit_succ(slop_arena* arena, types_Context store, types_RoleId r, types_Node y) {
    __auto_type _mv_339 = ({ void* _ptr = slop_map_get(store.succs, &(r)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
    if (_mv_339.has_value) {
        __auto_type s = _mv_339.value;
        if (slop_map_has(s, &(y))) {
            return 0;
        } else {
            ({ slop_map_put(arena, s, &(y), NULL, 0); });
            return 1;
        }
    } else if (!_mv_339.has_value) {
        {
            __auto_type s = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
            ({ slop_map_put(arena, s, &(y), NULL, 0); });
            ({ slop_map* _val = s; slop_map_put(arena, store.succs, &(r), &_val, sizeof(_val)); });
            return 1;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t saturate_commit_pred(slop_arena* arena, types_Context store, types_RoleId r, types_Node x) {
    __auto_type _mv_345 = ({ void* _ptr = slop_map_get(store.preds, &(r)); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
    if (_mv_345.has_value) {
        __auto_type s = _mv_345.value;
        if (slop_map_has(s, &(x))) {
            return 0;
        } else {
            ({ slop_map_put(arena, s, &(x), NULL, 0); });
            return 1;
        }
    } else if (!_mv_345.has_value) {
        {
            __auto_type s = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
            ({ slop_map_put(arena, s, &(x), NULL, 0); });
            ({ slop_map* _val = s; slop_map_put(arena, store.preds, &(r), &_val, sizeof(_val)); });
            return 1;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t saturate_commit_sub(slop_arena* arena, types_Context store, types_Node b) {
    if (slop_map_has(store.subsumers, &(b))) {
        return 0;
    } else {
        ({ slop_map_put(arena, store.subsumers, &(b), NULL, 0); });
        return 1;
    }
}

void saturate_commit_entry(slop_arena* arena, slop_arena* ca, types_Saturation sat, saturate_Touched e, saturate_Queues qs) {
    {
        __auto_type x = e.node;
        __auto_type dc = e.pending;
        __auto_type _mv_353 = ({ void* _ptr = slop_map_get(sat.contexts, &(x)); _ptr ? (slop_option_types_Context){ .has_value = true, .value = *(types_Context*)_ptr } : (slop_option_types_Context){ .has_value = false }; });
        if (_mv_353.has_value) {
            __auto_type store = _mv_353.value;
            {
                __auto_type q = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(qs.by_node, &(x)); _ptr ? (slop_option_types_Queue){ .has_value = true, .value = *(types_Queue*)_ptr } : (slop_option_types_Queue){ .has_value = false }; }); _mv.has_value ? ({ __auto_type q0 = _mv.value; q0; }) : (types_make_queue(arena)); });
                {
                    slop_map* _coll = (slop_map*)dc.subsumers;
                    for (size_t _i = 0; _i < _coll->len; _i++) {
                        {
                            types_Node b = *(types_Node*)slop_map_key_at(_coll, _i);
                            if (saturate_commit_sub(ca, store, b)) {
                                ({ __auto_type _lst_p = &(q.items); __auto_type _item = (((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = b })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                {
                    slop_map* _coll = (slop_map*)dc.succs;
                    for (size_t _i = 0; _i < _coll->len; _i++) {
                        {
                            types_RoleId r = *(types_RoleId*)slop_map_key_at(_coll, _i);
                            slop_map* ys = *(slop_map**)slop_map_value_at(_coll, _i);
                            {
                                slop_map* _coll = (slop_map*)ys;
                                for (size_t _i = 0; _i < _coll->len; _i++) {
                                    {
                                        types_Node y = *(types_Node*)slop_map_key_at(_coll, _i);
                                        if (saturate_commit_succ(ca, store, r, y)) {
                                            ({ __auto_type _lst_p = &(q.items); __auto_type _item = (((types_Derived){ .tag = types_Derived_derived_succ, .data.derived_succ = { .f0 = r, .f1 = y } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    slop_map* _coll = (slop_map*)dc.preds;
                    for (size_t _i = 0; _i < _coll->len; _i++) {
                        {
                            types_RoleId r = *(types_RoleId*)slop_map_key_at(_coll, _i);
                            slop_map* ps = *(slop_map**)slop_map_value_at(_coll, _i);
                            {
                                slop_map* _coll = (slop_map*)ps;
                                for (size_t _i = 0; _i < _coll->len; _i++) {
                                    {
                                        types_Node p = *(types_Node*)slop_map_key_at(_coll, _i);
                                        if (saturate_commit_pred(ca, store, r, p)) {
                                            ({ __auto_type _lst_p = &(q.items); __auto_type _item = (((types_Derived){ .tag = types_Derived_derived_pred, .data.derived_pred = { .f0 = r, .f1 = p } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                ({ types_Queue _val = q; slop_map_put(arena, qs.by_node, &(x), &_val, sizeof(_val)); });
            }
        } else if (!_mv_353.has_value) {
        }
    }
}

int64_t saturate_commit_bucket(slop_arena* arena, slop_arena* ca, types_Saturation sat, slop_list_saturate_Touched entries, saturate_Queues qs) {
    {
        __auto_type _coll = entries;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type e = _coll.data[_i];
            saturate_commit_entry(arena, ca, sat, e, qs);
        }
    }
    return 0;
}

types_Saturation saturate_commit_round(slop_arena* arena, slop_arena* run, slop_arena* scratch, types_Saturation sat, slop_list_saturate_RoundDelta deltas, slop_list_arena_ptr cas, slop_list_arena_ptr qas) {
    types_Saturation _retval = {0};
    {
        __auto_type w = ((int64_t)(((int64_t)((cas).len))));
        __auto_type buckets = saturate_partition_round(scratch, run, sat, deltas, w);
        __auto_type qss = ((slop_list_saturate_Queues){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type threads = ((slop_list_thread_int_ptr){ .data = NULL, .len = 0, .cap = 0 });
        int64_t k = 0;
        while (k < w) {
            {
                __auto_type qs = ((saturate_Queues){.by_node = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, types_Queue); slop_map_new_ptr(scratch, 0, &_d); })});
                __auto_type ca = ({ __auto_type _mv = ({ __auto_type _lst = cas; size_t _idx = (size_t)k; slop_option_arena_ptr _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type a = _mv.value; a; }) : (run); });
                __auto_type qa = ({ __auto_type _mv = ({ __auto_type _lst = qas; size_t _idx = (size_t)k; slop_option_arena_ptr _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type a = _mv.value; a; }) : (arena); });
                __auto_type share = saturate_bucket_items(scratch, ({ void* _ptr = slop_map_get(buckets.by_owner, &(int64_t){k}); _ptr ? (slop_option_saturate_Bucket){ .has_value = true, .value = *(saturate_Bucket*)_ptr } : (slop_option_saturate_Bucket){ .has_value = false }; }));
                ({ __auto_type _lst_p = &(qss); __auto_type _item = (qs); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                if (w <= 1) {
                    saturate_commit_bucket(qa, ca, sat, share, qs);
                } else {
                    ({ __auto_type _lst_p = &(threads); __auto_type _item = (({ slop_closure_t _spawn_cl = ({ saturate__lambda_357_env_t* saturate__lambda_357_env = (saturate__lambda_357_env_t*)slop_arena_alloc(arena, sizeof(saturate__lambda_357_env_t)); *saturate__lambda_357_env = (saturate__lambda_357_env_t){ .qa = qa, .ca = ca, .sat = sat, .share = share, .qs = qs }; (slop_closure_t){ (void*)saturate__lambda_357, (void*)saturate__lambda_357_env }; }); slop_thread_int* _spawn_th = slop_arena_alloc(scratch, sizeof(slop_thread_int)); _spawn_th->func = _spawn_cl.fn; _spawn_th->env = _spawn_cl.env; _spawn_th->done = false; pthread_create(&_spawn_th->id, NULL, (void*)slop_thread_int_entry, (void*)_spawn_th); _spawn_th; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                k = (k + 1);
            }
        }
        {
            __auto_type _coll = threads;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                thread_join(t);
            }
        }
        {
            __auto_type new_queues = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, types_Queue); slop_map_new_ptr(arena, 0, &_d); });
            __auto_type new_active = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
            int64_t count = 0;
            {
                __auto_type _coll = qss;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type qs = _coll.data[_i];
                    {
                        slop_map* _coll = (slop_map*)qs.by_node;
                        for (size_t _i = 0; _i < _coll->len; _i++) {
                            {
                                types_Node x = *(types_Node*)slop_map_key_at(_coll, _i);
                                types_Queue q = *(types_Queue*)slop_map_value_at(_coll, _i);
                                ({ types_Queue _val = q; slop_map_put(arena, new_queues, &(x), &_val, sizeof(_val)); });
                                ({ slop_map_put(arena, new_active, &(x), NULL, 0); });
                                count = (count + 1);
                            }
                        }
                    }
                }
            }
            _retval = ((types_Saturation){.contexts = sat.contexts, .queues = new_queues, .active = new_active, .active_count = count, .iteration = (sat.iteration + 1)});
        }
    }
    SLOP_POST(((_retval.iteration == (sat.iteration + 1))), "(== (. $result iteration) (+ (. sat iteration) 1))");
    SLOP_POST(((_retval.iteration > sat.iteration)), "(> (. $result iteration) (. sat iteration))");
    SLOP_POST(((_retval.active_count >= 0)), "(>= (. $result active-count) 0)");
    return _retval;
}

slop_list_arena_ptr saturate_generation_arenas(slop_arena* arena, int64_t w) {
    {
        __auto_type out = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        if (w > 1) {
            {
                int64_t k = 0;
                while (k < w) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    k = (k + 1);
                }
            }
        }
        return out;
    }
}

slop_list_arena_ptr saturate_committer_arenas(slop_arena* arena, slop_list_arena_ptr gen) {
    {
        __auto_type out = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0 });
        int64_t i = 0;
        {
            __auto_type _coll = gen;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (i > 0) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                i = (i + 1);
            }
        }
        return out;
    }
}

saturate_Advanced saturate_advance_round(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, types_ReasonerConfig config, slop_list_arena_ptr cas) {
    saturate_Advanced _retval = {0};
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type joined = (((config.worker_count <= 1)) ? ({ __auto_type d = ((saturate_RoundDelta){.pending = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, types_Context); slop_map_new_ptr(scratch, 0, &_d); })}); __auto_type ds = ((slop_list_saturate_RoundDelta){ .data = NULL, .len = 0, .cap = 0 }); ({ saturate_round_join(scratch, sat, idx, d); ({ __auto_type _lst_p = &(ds); __auto_type _item = (d); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }); ((saturate_Joined){.deltas = ds, .arenas = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0 })}); }); }) : saturate_parallel_join(scratch, sat, idx, config.worker_count));
        __auto_type gen = saturate_generation_arenas(arena, ((int64_t)(((int64_t)((cas).len)))));
        __auto_type g = ({ __auto_type _mv = ({ __auto_type _lst = gen; size_t _idx = (size_t)0; slop_option_arena_ptr _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type a = _mv.value; a; }) : (arena); });
        __auto_type next = saturate_commit_round(g, arena, scratch, sat, joined.deltas, cas, saturate_committer_arenas(scratch, gen));
        {
            __auto_type _coll = joined.arenas;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ slop_arena_free(a); free(a); });
            }
        }
        ({ slop_arena_free(scratch); free(scratch); });
        _retval = ((saturate_Advanced){.saturation = next, .arenas = gen});
    }
    SLOP_POST(((_retval.saturation.iteration == (sat.iteration + 1))), "(== (. (. $result saturation) iteration) (+ (. sat iteration) 1))");
    return _retval;
}

saturate_Joined saturate_parallel_join(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, int64_t w) {
    {
        __auto_type nodes = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sat.active); (slop_list_types_Node){.data = (types_Node*)_r.data, .len = _r.len, .cap = _r.cap}; });
        __auto_type n = ((int64_t)(((int64_t)((nodes).len))));
        __auto_type arenas = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type deltas = ((slop_list_saturate_RoundDelta){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type threads = ((slop_list_thread_int_ptr){ .data = NULL, .len = 0, .cap = 0 });
        int64_t k = 0;
        while (k < w) {
            {
                __auto_type lo = ((k * n) / w);
                __auto_type hi = (((k + 1) * n) / w);
                if (lo < hi) {
                    {
                        __auto_type wa = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                        __auto_type part = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
                        int64_t i = lo;
                        while (i < hi) {
                            __auto_type _mv_360 = ({ __auto_type _lst = nodes; size_t _idx = (size_t)i; slop_option_types_Node _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                            if (_mv_360.has_value) {
                                __auto_type x = _mv_360.value;
                                ({ __auto_type _lst_p = &(part); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else if (!_mv_360.has_value) {
                            }
                            i = (i + 1);
                        }
                        {
                            __auto_type d = ((saturate_RoundDelta){.pending = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, types_Context); slop_map_new_ptr(wa, 0, &_d); })});
                            __auto_type share = part;
                            ({ __auto_type _lst_p = &(arenas); __auto_type _item = (wa); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(deltas); __auto_type _item = (d); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(threads); __auto_type _item = (({ slop_closure_t _spawn_cl = ({ saturate__lambda_361_env_t* saturate__lambda_361_env = (saturate__lambda_361_env_t*)slop_arena_alloc(arena, sizeof(saturate__lambda_361_env_t)); *saturate__lambda_361_env = (saturate__lambda_361_env_t){ .wa = wa, .sat = sat, .idx = idx, .d = d, .share = share }; (slop_closure_t){ (void*)saturate__lambda_361, (void*)saturate__lambda_361_env }; }); slop_thread_int* _spawn_th = slop_arena_alloc(arena, sizeof(slop_thread_int)); _spawn_th->func = _spawn_cl.fn; _spawn_th->env = _spawn_cl.env; _spawn_th->done = false; pthread_create(&_spawn_th->id, NULL, (void*)slop_thread_int_entry, (void*)_spawn_th); _spawn_th; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                k = (k + 1);
            }
        }
        {
            __auto_type _coll = threads;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                thread_join(t);
            }
        }
        return ((saturate_Joined){.deltas = deltas, .arenas = arenas});
    }
}

uint8_t saturate_seed_node(slop_arena* arena, types_Saturation sat, types_Node n) {
    if (slop_map_has(sat.contexts, &(n))) {
        return 0;
    } else {
        {
            __auto_type ctx = types_make_context(arena, n);
            __auto_type q = types_make_queue(arena);
            __auto_type top = types_node_top();
            ({ __auto_type _lst_p = &(q.items); __auto_type _item = (((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = n })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(q.items); __auto_type _item = (((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = top })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ slop_map_put(arena, ctx.subsumers, &(n), NULL, 0); });
            ({ slop_map_put(arena, ctx.subsumers, &(top), NULL, 0); });
            ({ types_Context _val = ctx; slop_map_put(arena, sat.contexts, &(n), &_val, sizeof(_val)); });
            ({ types_Queue _val = q; slop_map_put(arena, sat.queues, &(n), &_val, sizeof(_val)); });
            ({ slop_map_put(arena, sat.active, &(n), NULL, 0); });
            return 1;
        }
    }
}

types_Saturation saturate_make_initial_saturation(slop_arena* arena, slop_list_types_Node signature) {
    types_Saturation _retval = {0};
    {
        __auto_type acc = ((types_Saturation){.contexts = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, types_Context); slop_map_new_ptr(arena, 0, &_d); }), .queues = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, types_Queue); slop_map_new_ptr(arena, 0, &_d); }), .active = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .active_count = 0, .iteration = 0});
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

slop_list_arena_ptr saturate_commit_arenas(slop_arena* arena, int64_t w) {
    {
        __auto_type out = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0 });
        if (w <= 1) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (arena); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else {
            {
                int64_t k = 0;
                while (k < w) {
                    {
                        __auto_type a = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        k = (k + 1);
                    }
                }
            }
        }
        return out;
    }
}

slop_result_saturate_RoundResult_types_Fault saturate_saturate(slop_arena* arena, types_Saturation sat, premise_RuleIndex idx, types_ReasonerConfig config) {
    slop_result_saturate_RoundResult_types_Fault _retval = {0};
    {
        __auto_type state = sat;
        uint8_t cancelled = 0;
        __auto_type prev = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type cas = saturate_commit_arenas(arena, config.worker_count);
        while (!(saturate_frontier_is_empty(state))) {
            if (config.cancel_ptr && __atomic_load_n((uint32_t*)(uintptr_t)config.cancel_ptr, __ATOMIC_RELAXED)) { cancelled = 1; };
            if (cancelled) {
                break;
            } else {
                if (saturate_budget_exhausted(state, config)) {
                    break;
                } else {
                    {
                        __auto_type adv = saturate_advance_round(arena, state, idx, config, cas);
                        {
                            __auto_type _coll = prev;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type a = _coll.data[_i];
                                ({ slop_arena_free(a); free(a); });
                            }
                        }
                        prev = adv.arenas;
                        state = adv.saturation;
                    }
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
    __auto_type _mv_369 = ({ void* _ptr = slop_map_get(sat.queues, &(to)); _ptr ? (slop_option_types_Queue){ .has_value = true, .value = *(types_Queue*)_ptr } : (slop_option_types_Queue){ .has_value = false }; });
    if (!_mv_369.has_value) {
        return 0;
    } else if (_mv_369.has_value) {
        __auto_type q = _mv_369.value;
        {
            __auto_type qq = q;
            __auto_type store = saturate_ensure_context(arena, sat, to);
            __auto_type _mv_370 = d;
            switch (_mv_370.tag) {
                case types_Derived_derived_sub:
                {
                    __auto_type b = _mv_370.data.derived_sub;
                    ({ slop_map_put(arena, store.subsumers, &(b), NULL, 0); });
                    break;
                }
                case types_Derived_derived_succ:
                {
                    __auto_type r = _mv_370.data.derived_succ.f0;
                    __auto_type y = _mv_370.data.derived_succ.f1;
                    saturate_add_succ(arena, store, r, y);
                    break;
                }
                case types_Derived_derived_pred:
                {
                    __auto_type r = _mv_370.data.derived_pred.f0;
                    __auto_type x = _mv_370.data.derived_pred.f1;
                    saturate_add_pred(arena, store, r, x);
                    break;
                }
            }
            ({ __auto_type _lst_p = &(qq.items); __auto_type _item = (d); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ types_Queue _val = qq; slop_map_put(arena, sat.queues, &(to), &_val, sizeof(_val)); });
            ({ slop_map_put(arena, sat.active, &(to), NULL, 0); });
            return 1;
        }
    }
    SLOP_UNREACHABLE();
}

