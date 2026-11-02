#include "../runtime/slop_runtime.h"
#include "slop_repair.h"

slop_string howl_repair_candidate_reason_text(howl_repair_CandidateReason reason);
howl_repair_SearchOptions howl_repair_default_search_options(void);
uint8_t howl_repair_has_index(slop_list_int xs, int64_t x);
uint8_t howl_repair_subset(slop_list_int xs, slop_list_int ys);
int64_t howl_repair_index_at(slop_list_int xs, int64_t i);
slop_list_int howl_repair_indices(slop_arena* arena, int64_t n);
slop_list_int howl_repair_set_add(slop_arena* arena, slop_list_int xs, int64_t x);
slop_list_int howl_repair_remove_index(slop_arena* arena, slop_list_int xs, int64_t x);
slop_list_int howl_repair_difference(slop_arena* arena, slop_list_int xs, slop_list_int ys);
int64_t howl_repair_set_cmp(slop_list_int xs, slop_list_int ys);
slop_list_int howl_repair_set_at(slop_arena* arena, slop_list_howl_repair_MappingSet xs, int64_t i);
uint8_t howl_repair_known_set(slop_list_howl_repair_MappingSet xs, slop_list_int items);
void howl_repair_keep_set(slop_list_howl_repair_MappingSet* xs, slop_list_int items);
slop_list_howl_repair_MappingSet howl_repair_sorted_sets(slop_arena* arena, slop_list_howl_repair_MappingSet xs);
slop_string howl_repair_set_key(slop_arena* arena, slop_list_int xs);
uint8_t howl_repair_fresh(slop_arena* arena, slop_map* seen, slop_list_int items);
howl_repair_Phase howl_repair_empty_phase(void);
uint8_t howl_repair_phase_complete(howl_repair_Phase p);
uint8_t howl_repair_stopped(howl_repair_SearchState* st, howl_repair_SearchOptions options);
uint8_t howl_repair_good(howl_repair_Check c);
uint8_t howl_repair_bad(howl_repair_Check c);
slop_option_howl_repair_Check howl_repair_ask(slop_arena* arena, howl_repair_SearchState* st, howl_repair_SearchOptions options, int64_t phase, slop_list_int removed, slop_closure_t check);
slop_option_howl_repair_MappingSet howl_repair_find_conflict(slop_list_howl_repair_MappingSet known, slop_list_int retained);
slop_option_howl_repair_MappingSet howl_repair_shrink(slop_arena* arena, howl_repair_SearchState* st, howl_repair_SearchOptions options, slop_list_int all, slop_list_int retained, slop_closure_t check);
void howl_repair_heap_push(slop_arena* arena, slop_list_howl_repair_MappingSet* queue, slop_list_int items);
slop_list_int howl_repair_heap_pop(slop_arena* arena, slop_list_howl_repair_MappingSet* queue);
slop_list_howl_repair_MappingSet howl_repair_enumerate_conflicts(slop_arena* arena, howl_repair_SearchState* st, howl_repair_SearchOptions options, slop_list_int all, slop_closure_t check);
uint8_t howl_repair_intersects(slop_list_int a, slop_list_int b);
slop_option_howl_repair_MappingSet howl_repair_unhit(slop_list_howl_repair_MappingSet conflicts, slop_list_int removed);
uint8_t howl_repair_minimal_hit(slop_list_howl_repair_MappingSet conflicts, slop_list_int removed);
slop_list_howl_repair_MappingSet howl_repair_enumerate_hits(slop_arena* arena, howl_repair_SearchState* st, howl_repair_SearchOptions options, slop_list_howl_repair_MappingSet conflicts);
void howl_repair_keep_candidate(slop_arena* arena, slop_list_howl_repair_Candidate* out, slop_map* seen, slop_list_int removed, howl_repair_CandidateReason reason);
void howl_repair_verify_candidate(slop_arena* arena, howl_repair_SearchState* st, howl_repair_SearchOptions options, slop_list_int removed, slop_list_howl_repair_MappingSet* verified, slop_list_howl_repair_Candidate* candidates, slop_map* seen, slop_closure_t check);
slop_list_howl_types_Omission howl_repair_sorted_omissions(slop_arena* arena, slop_list_howl_types_Omission xs);
slop_list_howl_repair_Candidate howl_repair_sorted_candidates(slop_arena* arena, slop_list_howl_repair_Candidate xs, slop_list_howl_repair_MappingSet verified);
slop_result_howl_repair_SearchResult_howl_types_Fault howl_repair_search(slop_arena* arena, int64_t n, howl_repair_Check initial, howl_repair_SearchOptions options, slop_closure_t check);

typedef struct { slop_arena* arena; slop_list_howl_repair_MappingSet xs; } howl_repair__lambda_1470_env_t;

static int64_t howl_repair__lambda_1470(howl_repair__lambda_1470_env_t* _env, int64_t i, int64_t j) { return howl_repair_set_cmp(howl_repair_set_at(_env->arena, _env->xs, i), howl_repair_set_at(_env->arena, _env->xs, j)); }

typedef struct { slop_list_howl_types_Omission xs; } howl_repair__lambda_1487_env_t;

static int64_t howl_repair__lambda_1487(howl_repair__lambda_1487_env_t* _env, int64_t a, int64_t b) { return ({ __auto_type _mv = ({ __auto_type _lst = _env->xs; size_t _idx = (size_t)a; slop_option_howl_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type x = _mv.value; ({ __auto_type _mv = ({ __auto_type _lst = _env->xs; size_t _idx = (size_t)b; slop_option_howl_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type y = _mv.value; howl_canon_omission_cmp(x, y); }) : (0); }); }) : (0); }); }

typedef struct { slop_list_howl_repair_Candidate xs; } howl_repair__lambda_1489_env_t;

static int64_t howl_repair__lambda_1489(howl_repair__lambda_1489_env_t* _env, int64_t a, int64_t b) { return ({ __auto_type _mv = ({ __auto_type _lst = _env->xs; size_t _idx = (size_t)a; slop_option_howl_repair_Candidate _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type x = _mv.value; ({ __auto_type _mv = ({ __auto_type _lst = _env->xs; size_t _idx = (size_t)b; slop_option_howl_repair_Candidate _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type y = _mv.value; howl_repair_set_cmp(x.removed, y.removed); }) : (0); }); }) : (0); }); }

slop_string howl_repair_candidate_reason_text(howl_repair_CandidateReason reason) {
    __auto_type _mv_1467 = reason;
    if (_mv_1467 == howl_repair_CandidateReason_candidate_budget) {
        return SLOP_STR("verification-budget");
    } else if (_mv_1467 == howl_repair_CandidateReason_candidate_unknown) {
        return SLOP_STR("inconclusive-classification");
    }
    SLOP_UNREACHABLE();
}

howl_repair_SearchOptions howl_repair_default_search_options(void) {
    howl_repair_SearchOptions _retval = {0};
    _retval = ((howl_repair_SearchOptions){.conflict_calls = 128, .conflict_nodes = 100000, .hitting_nodes = 100000, .verification_calls = 128, .cancel = 0});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.conflict_calls == 128)), "(== (. $result conflict-calls) 128)");
    SLOP_POST(((_retval.verification_calls == 128)), "(== (. $result verification-calls) 128)");
    return _retval;
}

uint8_t howl_repair_has_index(slop_list_int xs, int64_t x) {
    uint8_t _retval = {0};
    {
        uint8_t found = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type v = _coll.data[_i];
                if (v == x) {
                    found = 1;
                }
            }
        }
        _retval = found;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

uint8_t howl_repair_subset(slop_list_int xs, slop_list_int ys) {
    {
        uint8_t yes = 1;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (!(howl_repair_has_index(ys, x))) {
                    yes = 0;
                }
            }
        }
        return yes;
    }
}

int64_t howl_repair_index_at(slop_list_int xs, int64_t i) {
    __auto_type _mv_1468 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1468.has_value) {
        __auto_type x = _mv_1468.value;
        return x;
    } else if (!_mv_1468.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

slop_list_int howl_repair_indices(slop_arena* arena, int64_t n) {
    SLOP_PRE(((n >= 0)), "(>= n 0)");
    {
        __auto_type xs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < n) {
            (void)(({ __auto_type _lst_p = &(xs); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            i = (i + 1);
        }
        return xs;
    }
}

slop_list_int howl_repair_set_add(slop_arena* arena, slop_list_int xs, int64_t x) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t placed = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type v = _coll.data[_i];
                if (!(placed) && (x <= v)) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    placed = 1;
                }
                if (v != x) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        if (!(placed)) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        return out;
    }
}

slop_list_int howl_repair_remove_index(slop_arena* arena, slop_list_int xs, int64_t x) {
    slop_list_int _retval = {0};
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type v = _coll.data[_i];
                if (v != x) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        _retval = out;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval).len)) <= ((int64_t)((xs).len)))), "(<= (list-len $result) (list-len xs))");
    return _retval;
}

slop_list_int howl_repair_difference(slop_arena* arena, slop_list_int xs, slop_list_int ys) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type v = _coll.data[_i];
                if (!(howl_repair_has_index(ys, v))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

int64_t howl_repair_set_cmp(slop_list_int xs, slop_list_int ys) {
    {
        int64_t cmp = 0;
        int64_t i = 0;
        if (((int64_t)((xs).len)) != ((int64_t)((ys).len))) {
            cmp = (((((int64_t)((xs).len)) < ((int64_t)((ys).len)))) ? -1 : 1);
        } else {
            while ((cmp == 0) && (i < ((int64_t)((xs).len)))) {
                {
                    __auto_type a = howl_repair_index_at(xs, i);
                    __auto_type b = howl_repair_index_at(ys, i);
                    if (a != b) {
                        cmp = (((a < b)) ? -1 : 1);
                    }
                }
                i = (i + 1);
            }
        }
        return cmp;
    }
}

slop_list_int howl_repair_set_at(slop_arena* arena, slop_list_howl_repair_MappingSet xs, int64_t i) {
    __auto_type _mv_1469 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_repair_MappingSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1469.has_value) {
        __auto_type x = _mv_1469.value;
        return x.items;
    } else if (!_mv_1469.has_value) {
        return ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_repair_known_set(slop_list_howl_repair_MappingSet xs, slop_list_int items) {
    {
        uint8_t yes = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (howl_repair_set_cmp(x.items, items) == 0) {
                    yes = 1;
                }
            }
        }
        return yes;
    }
}

void howl_repair_keep_set(slop_list_howl_repair_MappingSet* xs, slop_list_int items) {
    if (!(howl_repair_known_set((*xs), items))) {
        (void)(({ __auto_type _lst_p = &((*xs)); __auto_type _item = (((howl_repair_MappingSet){.items = items})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
    }
}

slop_list_howl_repair_MappingSet howl_repair_sorted_sets(slop_arena* arena, slop_list_howl_repair_MappingSet xs) {
    {
        __auto_type order = howl_canon_sort_range(arena, ((int64_t)((xs).len)), ({ howl_repair__lambda_1470_env_t* howl_repair__lambda_1470_env = (howl_repair__lambda_1470_env_t*)slop_arena_alloc(arena, sizeof(howl_repair__lambda_1470_env_t)); *howl_repair__lambda_1470_env = (howl_repair__lambda_1470_env_t){ .arena = arena, .xs = xs }; (slop_closure_t){ (void*)howl_repair__lambda_1470, (void*)howl_repair__lambda_1470_env }; }));
        __auto_type out = ((slop_list_howl_repair_MappingSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        slop_option_howl_repair_MappingSet previous = (slop_option_howl_repair_MappingSet){.has_value = false};
        {
            __auto_type _coll = order;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                {
                    __auto_type x = ((howl_repair_MappingSet){.items = howl_repair_set_at(arena, xs, i)});
                    if (({ __auto_type _mv = previous; _mv.has_value ? ({ __auto_type p = _mv.value; (howl_repair_set_cmp(p.items, x.items) != 0); }) : (1); })) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        previous = (slop_option_howl_repair_MappingSet){.has_value = 1, .value = x};
                    }
                }
            }
        }
        return out;
    }
}

slop_string howl_repair_set_key(slop_arena* arena, slop_list_int xs) {
    {
        slop_string key = SLOP_STR("");
        { char d[24]; size_t n = 0, k = 0;
 for (size_t i = 0; i < xs.len; i++) n += (size_t)snprintf(d, sizeof d, "%lld,", (long long)xs.data[i]);
 char *buf = (char*)slop_arena_alloc(arena, n + 1);
 for (size_t i = 0; i < xs.len; i++) k += (size_t)snprintf(buf + k, n + 1 - k, "%lld,", (long long)xs.data[i]);
 key = (slop_string){n, buf}; };
        return key;
    }
}

uint8_t howl_repair_fresh(slop_arena* arena, slop_map* seen, slop_list_int items) {
    {
        __auto_type key = howl_repair_set_key(arena, items);
        uint8_t yes = 0;
        if (!(slop_map_has(seen, &(key)))) {
            (void)(({ slop_map_put(NULL, seen, &(key), NULL, 0); }));
            yes = 1;
        }
        return yes;
    }
}

howl_repair_Phase howl_repair_empty_phase(void) {
    return ((howl_repair_Phase){.exhausted = 0, .capped = 0, .unresolved = 0});
}

uint8_t howl_repair_phase_complete(howl_repair_Phase p) {
    uint8_t _retval = {0};
    _retval = ((p.exhausted) && (!(p.capped)) && (!(p.unresolved)));
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval == ((p.exhausted && !(p.capped)) && !(p.unresolved)))), "(== $result (and (and (. p exhausted) (not (. p capped))) (not (. p unresolved))))");
    return _retval;
}

uint8_t howl_repair_stopped(howl_repair_SearchState* st, howl_repair_SearchOptions options) {
    if (howl_types_cancel_requested(options.cancel)) {
        (*st).fault = (slop_option_howl_types_Fault){.has_value = 1, .value = ((howl_types_Fault){ .tag = howl_types_Fault_cancelled })};
    }
    __auto_type _mv_1473 = (*st).fault;
    if (_mv_1473.has_value) {
        __auto_type _ = _mv_1473.value;
        return 1;
    } else if (!_mv_1473.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_repair_good(howl_repair_Check c) {
    uint8_t _retval = {0};
    _retval = (c.complete && (c.verdict == howl_types_Verdict_verdict_coherent));
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval == (c.complete && (c.verdict == howl_types_Verdict_verdict_coherent)))), "(== $result (and (. c complete) (== (. c verdict) (quote verdict-coherent))))");
    return _retval;
}

uint8_t howl_repair_bad(howl_repair_Check c) {
    uint8_t _retval = {0};
    _retval = (c.verdict == howl_types_Verdict_verdict_incoherent);
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval == (c.verdict == howl_types_Verdict_verdict_incoherent))), "(== $result (== (. c verdict) (quote verdict-incoherent)))");
    return _retval;
}

slop_option_howl_repair_Check howl_repair_ask(slop_arena* arena, howl_repair_SearchState* st, howl_repair_SearchOptions options, int64_t phase, slop_list_int removed, slop_closure_t check) {
    {
        slop_option_howl_repair_Check answer = (slop_option_howl_repair_Check){.has_value = false};
        if (!(howl_repair_stopped(st, options))) {
            {
                __auto_type _coll = (*st).cache;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type entry = _coll.data[_i];
                    if (howl_repair_set_cmp(removed, entry.removed) == 0) {
                        answer = (slop_option_howl_repair_Check){.has_value = 1, .value = entry.answer};
                    }
                }
            }
            __auto_type _mv_1474 = answer;
            if (_mv_1474.has_value) {
                __auto_type _ = _mv_1474.value;
                (*st).counts.cache_hits = ((*st).counts.cache_hits + 1);
            } else if (!_mv_1474.has_value) {
                {
                    __auto_type capped = (((phase == 1) && ((*st).counts.conflict_calls >= options.conflict_calls)) || ((phase == 2) && ((*st).counts.verification_calls >= options.verification_calls)));
                    if (capped) {
                        if (phase == 1) {
                            (*st).conflict_phase.capped = 1;
                        } else {
                            (*st).verification_phase.capped = 1;
                        }
                    } else {
                        if (phase == 0) {
                            (*st).counts.preflight_calls = ((*st).counts.preflight_calls + 1);
                        } else if (phase == 1) {
                            (*st).counts.conflict_calls = ((*st).counts.conflict_calls + 1);
                        } else {
                            (*st).counts.verification_calls = ((*st).counts.verification_calls + 1);
                        }
                        {
                            howl_repair_Checked reply = ((howl_repair_Checked(*)(void*, slop_list_int))check.fn)(check.env, removed);
                            __auto_type _mv_1475 = reply;
                            switch (_mv_1475.tag) {
                                case howl_repair_Checked_check_fault:
                                {
                                    __auto_type f = _mv_1475.data.check_fault;
                                    {
                                        slop_option_howl_types_Fault held = (slop_option_howl_types_Fault){.has_value = 1, .value = f};
                                        (*st).fault = held;
                                    }
                                    break;
                                }
                                case howl_repair_Checked_checked:
                                {
                                    __auto_type c = _mv_1475.data.checked;
                                    ({ __auto_type _lst_p = &((*st).cache); __auto_type _item = (((howl_repair_Cached){.removed = removed, .answer = c})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    {
                                        slop_list_howl_types_Omission oms = c.omissions;
                                        {
                                            __auto_type _coll = oms;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type o = _coll.data[_i];
                                                ({ __auto_type _lst_p = &((*st).omissions); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                    }
                                    answer = (slop_option_howl_repair_Check){.has_value = 1, .value = c};
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (howl_repair_stopped(st, options)) {
            answer = (slop_option_howl_repair_Check){.has_value = false};
        }
        return answer;
    }
}

slop_option_howl_repair_MappingSet howl_repair_find_conflict(slop_list_howl_repair_MappingSet known, slop_list_int retained) {
    {
        slop_option_howl_repair_MappingSet found = (slop_option_howl_repair_MappingSet){.has_value = false};
        {
            __auto_type _coll = known;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                __auto_type _mv_1476 = found;
                if (_mv_1476.has_value) {
                    __auto_type _ = _mv_1476.value;
                } else if (!_mv_1476.has_value) {
                    if (howl_repair_subset(c.items, retained)) {
                        found = (slop_option_howl_repair_MappingSet){.has_value = 1, .value = c};
                    }
                }
            }
        }
        return found;
    }
}

slop_option_howl_repair_MappingSet howl_repair_shrink(slop_arena* arena, howl_repair_SearchState* st, howl_repair_SearchOptions options, slop_list_int all, slop_list_int retained, slop_closure_t check) {
    {
        __auto_type cur = retained;
        int64_t width = ((int64_t)((retained).len));
        uint8_t valid = 1;
        while ((valid) && ((width > 0)) && (!(howl_repair_stopped(st, options)))) {
            {
                int64_t pos = 0;
                while ((valid) && ((pos < ((int64_t)((cur).len)))) && (!(howl_repair_stopped(st, options)))) {
                    {
                        __auto_type trial = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                        int64_t i = 0;
                        {
                            __auto_type _coll = cur;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type x = _coll.data[_i];
                                if ((i < pos) || (i >= (pos + width))) {
                                    (void)(({ __auto_type _lst_p = &(trial); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                }
                                i = (i + 1);
                            }
                        }
                        __auto_type _mv_1477 = howl_repair_ask(arena, st, options, 1, howl_repair_difference(arena, all, trial), check);
                        if (!_mv_1477.has_value) {
                            valid = 0;
                        } else if (_mv_1477.has_value) {
                            __auto_type c = _mv_1477.value;
                            if (howl_repair_bad(c)) {
                                cur = trial;
                            } else if (howl_repair_good(c)) {
                                pos = (pos + width);
                            } else {
                                valid = 0;
                                (*st).conflict_phase.unresolved = 1;
                            }
                        }
                    }
                }
            }
            width = (((width == 1)) ? 0 : ((width + 1) / 2));
        }
        if (valid) {
            __auto_type _mv_1478 = howl_repair_ask(arena, st, options, 1, howl_repair_difference(arena, all, cur), check);
            if (!_mv_1478.has_value) {
                valid = 0;
            } else if (_mv_1478.has_value) {
                __auto_type final = _mv_1478.value;
                if (!((final.complete && howl_repair_bad(final)))) {
                    valid = 0;
                    (*st).conflict_phase.unresolved = 1;
                }
            }
        }
        if (valid) {
            return (slop_option_howl_repair_MappingSet){.has_value = 1, .value = ((howl_repair_MappingSet){.items = cur})};
        } else {
            return (slop_option_howl_repair_MappingSet){.has_value = false};
        }
    }
}

void howl_repair_heap_push(slop_arena* arena, slop_list_howl_repair_MappingSet* queue, slop_list_int items) {
    {
        int64_t i = ((int64_t)(((*queue)).len));
        uint8_t moving = 1;
        (void)(({ __auto_type _lst_p = &((*queue)); __auto_type _item = (((howl_repair_MappingSet){.items = items})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        while (moving && (i > 0)) {
            {
                __auto_type parent = ((i - 1) / 2);
                {
                    __auto_type up = howl_repair_set_at(arena, (*queue), parent);
                    if (howl_repair_set_cmp(items, up) < 0) {
                        if (({ __auto_type _set_lst = &((*queue)); size_t _set_idx = (size_t)(i); __auto_type _set_val = (((howl_repair_MappingSet){.items = up})); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; })) {
                        }
                        i = parent;
                    } else {
                        moving = 0;
                    }
                }
            }
        }
        if (({ __auto_type _set_lst = &((*queue)); size_t _set_idx = (size_t)(i); __auto_type _set_val = (((howl_repair_MappingSet){.items = items})); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; })) {
        }
    }
}

slop_list_int howl_repair_heap_pop(slop_arena* arena, slop_list_howl_repair_MappingSet* queue) {
    {
        __auto_type least = howl_repair_set_at(arena, (*queue), 0);
        __auto_type _mv_1479 = ({ __auto_type _lst_p = &((*queue)); slop_option_howl_repair_MappingSet _r = {0}; if (_lst_p->len > 0) { _lst_p->len--; _r.has_value = true; _r.value = _lst_p->data[_lst_p->len]; } _r; });
        if (!_mv_1479.has_value) {
        } else if (_mv_1479.has_value) {
            __auto_type last = _mv_1479.value;
            {
                __auto_type n = ((int64_t)(((*queue)).len));
                int64_t i = 0;
                uint8_t moving = (((int64_t)(((*queue)).len)) > 0);
                while (moving) {
                    {
                        int64_t child = ((2 * i) + 1);
                        if (child >= n) {
                            moving = 0;
                        } else {
                            if (((child + 1) < n) && (howl_repair_set_cmp(howl_repair_set_at(arena, (*queue), (child + 1)), howl_repair_set_at(arena, (*queue), child)) < 0)) {
                                child = (child + 1);
                            }
                            if (howl_repair_set_cmp(howl_repair_set_at(arena, (*queue), child), last.items) < 0) {
                                if (({ __auto_type _set_lst = &((*queue)); size_t _set_idx = (size_t)(i); __auto_type _set_val = (((howl_repair_MappingSet){.items = howl_repair_set_at(arena, (*queue), child)})); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; })) {
                                }
                                i = child;
                            } else {
                                moving = 0;
                            }
                        }
                    }
                }
                if (i < n) {
                    if (({ __auto_type _set_lst = &((*queue)); size_t _set_idx = (size_t)(i); __auto_type _set_val = (last); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; })) {
                    }
                }
            }
        }
        return least;
    }
}

slop_list_howl_repair_MappingSet howl_repair_enumerate_conflicts(slop_arena* arena, howl_repair_SearchState* st, howl_repair_SearchOptions options, slop_list_int all, slop_closure_t check) {
    {
        __auto_type known = ((slop_list_howl_repair_MappingSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type queue = ((slop_list_howl_repair_MappingSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type empty = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (howl_repair_fresh(arena, seen, empty)) {
            howl_repair_heap_push(arena, (&queue), empty);
        }
        while (((((int64_t)((queue).len)) > 0)) && (!((*st).conflict_phase.capped)) && (!(howl_repair_stopped(st, options)))) {
            {
                __auto_type excluded = howl_repair_heap_pop(arena, (&queue));
                {
                    __auto_type retained = howl_repair_difference(arena, all, excluded);
                    slop_option_howl_repair_MappingSet conflict = (slop_option_howl_repair_MappingSet){.has_value = false};
                    conflict = howl_repair_find_conflict(known, retained);
                    __auto_type _mv_1480 = conflict;
                    if (_mv_1480.has_value) {
                        __auto_type _ = _mv_1480.value;
                    } else if (!_mv_1480.has_value) {
                        __auto_type _mv_1481 = howl_repair_ask(arena, st, options, 1, excluded, check);
                        if (!_mv_1481.has_value) {
                        } else if (_mv_1481.has_value) {
                            __auto_type c = _mv_1481.value;
                            if (howl_repair_good(c)) {
                            } else if (howl_repair_bad(c)) {
                                conflict = howl_repair_shrink(arena, st, options, all, retained, check);
                            } else {
                                (*st).conflict_phase.unresolved = 1;
                            }
                        }
                    }
                    __auto_type _mv_1482 = conflict;
                    if (!_mv_1482.has_value) {
                    } else if (_mv_1482.has_value) {
                        __auto_type c = _mv_1482.value;
                        howl_repair_keep_set((&known), c.items);
                        {
                            slop_list_int members = c.items;
                            {
                                __auto_type _coll = members;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type x = _coll.data[_i];
                                    if (!(howl_repair_stopped(st, options))) {
                                        if ((*st).counts.conflict_nodes >= options.conflict_nodes) {
                                            (*st).conflict_phase.capped = 1;
                                        } else {
                                            (*st).counts.conflict_nodes = ((*st).counts.conflict_nodes + 1);
                                            {
                                                __auto_type child = howl_repair_set_add(arena, excluded, x);
                                                if (howl_repair_fresh(arena, seen, child)) {
                                                    howl_repair_heap_push(arena, (&queue), child);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        (*st).conflict_phase.exhausted = (((int64_t)((queue).len)) == 0);
        return howl_repair_sorted_sets(arena, known);
    }
}

uint8_t howl_repair_intersects(slop_list_int a, slop_list_int b) {
    {
        uint8_t yes = 0;
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (howl_repair_has_index(b, x)) {
                    yes = 1;
                }
            }
        }
        return yes;
    }
}

slop_option_howl_repair_MappingSet howl_repair_unhit(slop_list_howl_repair_MappingSet conflicts, slop_list_int removed) {
    {
        slop_option_howl_repair_MappingSet found = (slop_option_howl_repair_MappingSet){.has_value = false};
        {
            __auto_type _coll = conflicts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                __auto_type _mv_1483 = found;
                if (_mv_1483.has_value) {
                    __auto_type _ = _mv_1483.value;
                } else if (!_mv_1483.has_value) {
                    if (!(howl_repair_intersects(c.items, removed))) {
                        found = (slop_option_howl_repair_MappingSet){.has_value = 1, .value = c};
                    }
                }
            }
        }
        return found;
    }
}

uint8_t howl_repair_minimal_hit(slop_list_howl_repair_MappingSet conflicts, slop_list_int removed) {
    {
        uint8_t minimal = 1;
        {
            __auto_type _coll = removed;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                {
                    uint8_t witness = 0;
                    {
                        __auto_type _coll = conflicts;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            if (howl_repair_has_index(c.items, x)) {
                                {
                                    int64_t count = 0;
                                    {
                                        __auto_type _coll = removed;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type y = _coll.data[_i];
                                            if (howl_repair_has_index(c.items, y)) {
                                                count = (count + 1);
                                            }
                                        }
                                    }
                                    if (count == 1) {
                                        witness = 1;
                                    }
                                }
                            }
                        }
                    }
                    if (!(witness)) {
                        minimal = 0;
                    }
                }
            }
        }
        return minimal;
    }
}

slop_list_howl_repair_MappingSet howl_repair_enumerate_hits(slop_arena* arena, howl_repair_SearchState* st, howl_repair_SearchOptions options, slop_list_howl_repair_MappingSet conflicts) {
    {
        __auto_type nodes = ((slop_list_howl_repair_MappingSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type stack = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type found = ((slop_list_howl_repair_MappingSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t top = 0;
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type empty = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (howl_repair_fresh(arena, seen, empty)) {
            (void)(({ __auto_type _lst_p = &(nodes); __auto_type _item = (((howl_repair_MappingSet){.items = empty})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        (void)(({ __auto_type _lst_p = &(stack); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        top = 1;
        while (((top > 0)) && (!((*st).hitting_phase.capped)) && (!(howl_repair_stopped(st, options)))) {
            top = (top - 1);
            {
                __auto_type candidate = howl_repair_set_at(arena, nodes, howl_repair_index_at(stack, top));
                __auto_type _mv_1484 = howl_repair_unhit(conflicts, candidate);
                if (!_mv_1484.has_value) {
                    if (howl_repair_minimal_hit(conflicts, candidate)) {
                        ({ __auto_type _lst_p = &(found); __auto_type _item = (((howl_repair_MappingSet){.items = candidate})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                } else if (_mv_1484.has_value) {
                    __auto_type c = _mv_1484.value;
                    {
                        int64_t i = (((int64_t)((c.items).len)) - 1);
                        while (((i >= 0)) && (!((*st).hitting_phase.capped)) && (!(howl_repair_stopped(st, options)))) {
                            if ((*st).counts.hitting_nodes >= options.hitting_nodes) {
                                (*st).hitting_phase.capped = 1;
                            } else {
                                (*st).counts.hitting_nodes = ((*st).counts.hitting_nodes + 1);
                                {
                                    __auto_type child = howl_repair_set_add(arena, candidate, howl_repair_index_at(c.items, i));
                                    if (howl_repair_fresh(arena, seen, child)) {
                                        ({ __auto_type _lst_p = &(nodes); __auto_type _item = (((howl_repair_MappingSet){.items = child})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        if (top < ((int64_t)((stack).len))) {
                                            if (({ __auto_type _set_lst = &(stack); size_t _set_idx = (size_t)(top); __auto_type _set_val = ((((int64_t)((nodes).len)) - 1)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; })) {
                                            }
                                        } else {
                                            ({ __auto_type _lst_p = &(stack); __auto_type _item = ((((int64_t)((nodes).len)) - 1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                        top = (top + 1);
                                    }
                                }
                            }
                            i = (i - 1);
                        }
                    }
                }
            }
        }
        (*st).hitting_phase.exhausted = (top == 0);
        return howl_repair_sorted_sets(arena, found);
    }
}

void howl_repair_keep_candidate(slop_arena* arena, slop_list_howl_repair_Candidate* out, slop_map* seen, slop_list_int removed, howl_repair_CandidateReason reason) {
    if (howl_repair_fresh(arena, seen, removed)) {
        (void)(({ __auto_type _lst_p = &((*out)); __auto_type _item = (((howl_repair_Candidate){.removed = removed, .reason = reason})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
    }
}

void howl_repair_verify_candidate(slop_arena* arena, howl_repair_SearchState* st, howl_repair_SearchOptions options, slop_list_int removed, slop_list_howl_repair_MappingSet* verified, slop_list_howl_repair_Candidate* candidates, slop_map* seen, slop_closure_t check) {
    __auto_type _mv_1485 = howl_repair_ask(arena, st, options, 2, removed, check);
    if (!_mv_1485.has_value) {
        howl_repair_keep_candidate(arena, candidates, seen, removed, howl_repair_CandidateReason_candidate_budget);
    } else if (_mv_1485.has_value) {
        __auto_type initial = _mv_1485.value;
        if (howl_repair_good(initial)) {
            {
                __auto_type cur = removed;
                uint8_t certain = 1;
                __auto_type reason = howl_repair_CandidateReason_candidate_unknown;
                {
                    __auto_type _coll = removed;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        if (certain && !(howl_repair_stopped(st, options))) {
                            {
                                __auto_type trial = howl_repair_remove_index(arena, cur, x);
                                __auto_type _mv_1486 = howl_repair_ask(arena, st, options, 2, trial, check);
                                if (!_mv_1486.has_value) {
                                    certain = 0;
                                    reason = howl_repair_CandidateReason_candidate_budget;
                                } else if (_mv_1486.has_value) {
                                    __auto_type c = _mv_1486.value;
                                    if (howl_repair_good(c)) {
                                        cur = trial;
                                    } else if (c.complete && howl_repair_bad(c)) {
                                    } else {
                                        certain = 0;
                                        (*st).verification_phase.unresolved = 1;
                                    }
                                }
                            }
                        }
                    }
                }
                if (certain) {
                    howl_repair_keep_set(verified, cur);
                } else {
                    howl_repair_keep_candidate(arena, candidates, seen, cur, reason);
                }
            }
        } else if (howl_repair_bad(initial)) {
        } else {
            howl_repair_keep_candidate(arena, candidates, seen, removed, howl_repair_CandidateReason_candidate_unknown);
            (*st).verification_phase.unresolved = 1;
        }
    }
}

slop_list_howl_types_Omission howl_repair_sorted_omissions(slop_arena* arena, slop_list_howl_types_Omission xs) {
    {
        __auto_type out = ((slop_list_howl_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        slop_option_howl_types_Omission previous = (slop_option_howl_types_Omission){.has_value = false};
        {
            __auto_type _coll = howl_canon_sort_range(arena, ((int64_t)((xs).len)), ({ howl_repair__lambda_1487_env_t* howl_repair__lambda_1487_env = (howl_repair__lambda_1487_env_t*)slop_arena_alloc(arena, sizeof(howl_repair__lambda_1487_env_t)); *howl_repair__lambda_1487_env = (howl_repair__lambda_1487_env_t){ .xs = xs }; (slop_closure_t){ (void*)howl_repair__lambda_1487, (void*)howl_repair__lambda_1487_env }; }));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                __auto_type _mv_1488 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (!_mv_1488.has_value) {
                } else if (_mv_1488.has_value) {
                    __auto_type x = _mv_1488.value;
                    if (({ __auto_type _mv = previous; _mv.has_value ? ({ __auto_type p = _mv.value; (howl_canon_omission_cmp(p, x) != 0); }) : (1); })) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        previous = (slop_option_howl_types_Omission){.has_value = 1, .value = x};
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_repair_Candidate howl_repair_sorted_candidates(slop_arena* arena, slop_list_howl_repair_Candidate xs, slop_list_howl_repair_MappingSet verified) {
    {
        __auto_type out = ((slop_list_howl_repair_Candidate){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = howl_canon_sort_range(arena, ((int64_t)((xs).len)), ({ howl_repair__lambda_1489_env_t* howl_repair__lambda_1489_env = (howl_repair__lambda_1489_env_t*)slop_arena_alloc(arena, sizeof(howl_repair__lambda_1489_env_t)); *howl_repair__lambda_1489_env = (howl_repair__lambda_1489_env_t){ .xs = xs }; (slop_closure_t){ (void*)howl_repair__lambda_1489, (void*)howl_repair__lambda_1489_env }; }));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                __auto_type _mv_1490 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_repair_Candidate _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (!_mv_1490.has_value) {
                } else if (_mv_1490.has_value) {
                    __auto_type c = _mv_1490.value;
                    if (!(howl_repair_known_set(verified, c.removed))) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

slop_result_howl_repair_SearchResult_howl_types_Fault howl_repair_search(slop_arena* arena, int64_t n, howl_repair_Check initial, howl_repair_SearchOptions options, slop_closure_t check) {
    SLOP_PRE(((n >= 0)), "(>= n 0)");
    SLOP_PRE(((options.conflict_calls >= 0)), "(>= (. options conflict-calls) 0)");
    SLOP_PRE(((options.conflict_nodes >= 0)), "(>= (. options conflict-nodes) 0)");
    SLOP_PRE(((options.hitting_nodes >= 0)), "(>= (. options hitting-nodes) 0)");
    SLOP_PRE(((options.verification_calls >= 0)), "(>= (. options verification-calls) 0)");
    {
        __auto_type all = howl_repair_indices(arena, n);
        __auto_type empty = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type st = ((howl_repair_SearchState*)(({ __auto_type _alloc = (howl_repair_SearchState*)slop_arena_alloc(arena, sizeof(howl_repair_SearchState)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        __auto_type verified = ((slop_list_howl_repair_MappingSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type candidates = ((slop_list_howl_repair_Candidate){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type candidate_keys = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type conflicts = ((slop_list_howl_repair_MappingSet){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t already = 0;
        uint8_t unrepairable = 0;
        uint8_t shortcut = 0;
        (*st) = ((howl_repair_SearchState){.cache = ((slop_list_howl_repair_Cached){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .omissions = ((slop_list_howl_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .fault = (slop_option_howl_types_Fault){.has_value = false}, .counts = ((howl_repair_SearchCounts){.preflight_calls = 1, .conflict_calls = 0, .conflict_nodes = 0, .hitting_nodes = 0, .verification_calls = 0, .cache_hits = 0}), .conflict_phase = howl_repair_empty_phase(), .hitting_phase = howl_repair_empty_phase(), .verification_phase = howl_repair_empty_phase()});
        (void)(({ __auto_type _lst_p = &((*st).cache); __auto_type _item = (((howl_repair_Cached){.removed = empty, .answer = initial})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        {
            __auto_type _coll = initial.omissions;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &((*st).omissions); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        if (howl_repair_good(initial)) {
            already = 1;
            shortcut = 1;
        } else {
            __auto_type _mv_1491 = howl_repair_ask(arena, st, options, 0, all, check);
            if (!_mv_1491.has_value) {
            } else if (_mv_1491.has_value) {
                __auto_type background = _mv_1491.value;
                if (howl_repair_bad(background)) {
                    unrepairable = 1;
                    shortcut = 1;
                    if (!(background.complete)) {
                        (*st).conflict_phase.unresolved = 1;
                    }
                } else {
                    conflicts = howl_repair_enumerate_conflicts(arena, st, options, all, check);
                    {
                        __auto_type hits = howl_repair_enumerate_hits(arena, st, options, conflicts);
                        if (!(howl_repair_phase_complete((*st).conflict_phase)) && howl_repair_good(background)) {
                            howl_repair_verify_candidate(arena, st, options, all, (&verified), (&candidates), candidate_keys, check);
                        }
                        {
                            __auto_type _coll = hits;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type h = _coll.data[_i];
                                if (!(howl_repair_stopped(st, options))) {
                                    howl_repair_verify_candidate(arena, st, options, h.items, (&verified), (&candidates), candidate_keys, check);
                                }
                            }
                        }
                        (*st).verification_phase.exhausted = (!((*st).verification_phase.capped) && !((*st).verification_phase.unresolved));
                    }
                }
            }
        }
        if (shortcut) {
            (*st).conflict_phase.exhausted = 1;
            (*st).hitting_phase.exhausted = 1;
            (*st).verification_phase.exhausted = 1;
        }
        howl_repair_stopped(st, options);
        __auto_type _mv_1492 = (*st).fault;
        if (_mv_1492.has_value) {
            __auto_type f = _mv_1492.value;
            return ((slop_result_howl_repair_SearchResult_howl_types_Fault){ .is_ok = false, .data.err = f });
        } else if (!_mv_1492.has_value) {
            return ((slop_result_howl_repair_SearchResult_howl_types_Fault){ .is_ok = true, .data.ok = ((howl_repair_SearchResult){.verified = howl_repair_sorted_sets(arena, verified), .candidates = howl_repair_sorted_candidates(arena, candidates, verified), .conflicts = conflicts, .conflict_phase = (*st).conflict_phase, .hitting_phase = (*st).hitting_phase, .verification_phase = (*st).verification_phase, .omissions = howl_repair_sorted_omissions(arena, (*st).omissions), .counts = (*st).counts, .already_coherent = already, .unrepairable = unrepairable, .complete = ((howl_repair_phase_complete((*st).conflict_phase)) && (howl_repair_phase_complete((*st).hitting_phase)) && (howl_repair_phase_complete((*st).verification_phase)) && ((((int64_t)(((*st).omissions).len)) == 0)))}) });
        }
        SLOP_UNREACHABLE();
    }
}

