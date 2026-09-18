#include "../runtime/slop_runtime.h"
#include "slop_index.h"

index_IndexedGraph rdf_indexed_graph_create(slop_arena* arena);
index_IndexedGraph rdf_indexed_graph_add(slop_arena* arena, index_IndexedGraph g, rdf_Triple t);
uint8_t rdf_indexed_graph_contains(index_IndexedGraph g, rdf_Triple t);
slop_list_rdf_Triple rdf_indexed_graph_match(slop_arena* arena, index_IndexedGraph g, slop_option_rdf_Term subj, slop_option_rdf_Term pred, slop_option_rdf_Term obj);
void rdf_indexed_graph_for_each(index_IndexedGraph g, slop_option_rdf_Term subj, slop_option_rdf_Term pred, slop_option_rdf_Term obj, slop_closure_t callback);
int64_t rdf_indexed_graph_size(index_IndexedGraph g);
slop_list_rdf_Term rdf_indexed_graph_subjects(slop_arena* arena, index_IndexedGraph g, rdf_Term pred, rdf_Term obj);
slop_list_rdf_Term rdf_indexed_graph_objects(slop_arena* arena, index_IndexedGraph g, rdf_Term subj, rdf_Term pred);

index_IndexedGraph rdf_indexed_graph_create(slop_arena* arena) {
    index_IndexedGraph _retval = {0};
    _retval = ((index_IndexedGraph){.triples = ((slop_list_rdf_Triple){ .data = (rdf_Triple*)slop_arena_alloc(arena, 16 * sizeof(rdf_Triple)), .len = 0, .cap = 16 }), .index = ((index_TripleIndex){.spo = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term), .pso = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term), .osp = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term), .pos = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term)}), .size = 0});
    SLOP_POST(((_retval.size == 0)), "(== (. $result size) 0)");
    return _retval;
}

index_IndexedGraph rdf_indexed_graph_add(slop_arena* arena, index_IndexedGraph g, rdf_Triple t) {
    SLOP_PRE(((g.size >= 0)), "(>= (. g size) 0)");
    index_IndexedGraph _retval = {0};
    if (rdf_indexed_graph_contains(g, t)) {
        _retval = g;
    }
    {
        __auto_type s = rdf_triple_subject(t);
        __auto_type p = rdf_triple_predicate(t);
        __auto_type o = rdf_triple_object(t);
        ({ __auto_type _lst_p = &(g.triples); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type spo_idx = g.index.spo;
            __auto_type _mv_156 = ({ void* _ptr = slop_map_get(spo_idx, &(s)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
            if (_mv_156.has_value) {
                __auto_type pred_map = _mv_156.value;
                __auto_type _mv_158 = ({ void* _ptr = slop_map_get(pred_map, &(p)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                if (_mv_158.has_value) {
                    __auto_type obj_set = _mv_158.value;
                    ({ uint8_t _dummy = 1; slop_map_put(arena, obj_set, &(o), &_dummy); });
                } else if (!_mv_158.has_value) {
                    {
                        __auto_type ts = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                        ({ uint8_t _dummy = 1; slop_map_put(arena, ts, &(o), &_dummy); });
                        ({ __auto_type _val = ts; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, pred_map, &(p), _vptr); });
                    }
                }
            } else if (!_mv_156.has_value) {
                {
                    __auto_type pred_map = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                    __auto_type ts = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                    ({ uint8_t _dummy = 1; slop_map_put(arena, ts, &(o), &_dummy); });
                    ({ __auto_type _val = ts; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, pred_map, &(p), _vptr); });
                    ({ __auto_type _val = pred_map; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, spo_idx, &(s), _vptr); });
                }
            }
        }
        {
            __auto_type pso_idx = g.index.pso;
            __auto_type _mv_166 = ({ void* _ptr = slop_map_get(pso_idx, &(p)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
            if (_mv_166.has_value) {
                __auto_type subj_map = _mv_166.value;
                __auto_type _mv_168 = ({ void* _ptr = slop_map_get(subj_map, &(s)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                if (_mv_168.has_value) {
                    __auto_type obj_set = _mv_168.value;
                    ({ uint8_t _dummy = 1; slop_map_put(arena, obj_set, &(o), &_dummy); });
                } else if (!_mv_168.has_value) {
                    {
                        __auto_type ts = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                        ({ uint8_t _dummy = 1; slop_map_put(arena, ts, &(o), &_dummy); });
                        ({ __auto_type _val = ts; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, subj_map, &(s), _vptr); });
                    }
                }
            } else if (!_mv_166.has_value) {
                {
                    __auto_type subj_map = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                    __auto_type ts = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                    ({ uint8_t _dummy = 1; slop_map_put(arena, ts, &(o), &_dummy); });
                    ({ __auto_type _val = ts; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, subj_map, &(s), _vptr); });
                    ({ __auto_type _val = subj_map; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, pso_idx, &(p), _vptr); });
                }
            }
        }
        {
            __auto_type osp_idx = g.index.osp;
            __auto_type _mv_176 = ({ void* _ptr = slop_map_get(osp_idx, &(o)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
            if (_mv_176.has_value) {
                __auto_type subj_map = _mv_176.value;
                __auto_type _mv_178 = ({ void* _ptr = slop_map_get(subj_map, &(s)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                if (_mv_178.has_value) {
                    __auto_type pred_set = _mv_178.value;
                    ({ uint8_t _dummy = 1; slop_map_put(arena, pred_set, &(p), &_dummy); });
                } else if (!_mv_178.has_value) {
                    {
                        __auto_type ts = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                        ({ uint8_t _dummy = 1; slop_map_put(arena, ts, &(p), &_dummy); });
                        ({ __auto_type _val = ts; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, subj_map, &(s), _vptr); });
                    }
                }
            } else if (!_mv_176.has_value) {
                {
                    __auto_type subj_map = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                    __auto_type ts = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                    ({ uint8_t _dummy = 1; slop_map_put(arena, ts, &(p), &_dummy); });
                    ({ __auto_type _val = ts; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, subj_map, &(s), _vptr); });
                    ({ __auto_type _val = subj_map; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, osp_idx, &(o), _vptr); });
                }
            }
        }
        {
            __auto_type pos_idx = g.index.pos;
            __auto_type _mv_186 = ({ void* _ptr = slop_map_get(pos_idx, &(p)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
            if (_mv_186.has_value) {
                __auto_type obj_map = _mv_186.value;
                __auto_type _mv_188 = ({ void* _ptr = slop_map_get(obj_map, &(o)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                if (_mv_188.has_value) {
                    __auto_type subj_set = _mv_188.value;
                    ({ uint8_t _dummy = 1; slop_map_put(arena, subj_set, &(s), &_dummy); });
                } else if (!_mv_188.has_value) {
                    {
                        __auto_type ts = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                        ({ uint8_t _dummy = 1; slop_map_put(arena, ts, &(s), &_dummy); });
                        ({ __auto_type _val = ts; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, obj_map, &(o), _vptr); });
                    }
                }
            } else if (!_mv_186.has_value) {
                {
                    __auto_type obj_map = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                    __auto_type ts = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term);
                    ({ uint8_t _dummy = 1; slop_map_put(arena, ts, &(s), &_dummy); });
                    ({ __auto_type _val = ts; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, obj_map, &(o), _vptr); });
                    ({ __auto_type _val = obj_map; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, pos_idx, &(p), _vptr); });
                }
            }
        }
        _retval = ((index_IndexedGraph){.triples = g.triples, .index = g.index, .size = (g.size + 1)});
    }
    SLOP_POST(((_retval.size >= g.size)), "(>= (. $result size) (. g size))");
    return _retval;
}

uint8_t rdf_indexed_graph_contains(index_IndexedGraph g, rdf_Triple t) {
    SLOP_PRE(((g.size >= 0)), "(>= (. g size) 0)");
    uint8_t _retval = {0};
    {
        __auto_type s = rdf_triple_subject(t);
        __auto_type p = rdf_triple_predicate(t);
        __auto_type o = rdf_triple_object(t);
        __auto_type spo_idx = g.index.spo;
        __auto_type _mv_196 = ({ void* _ptr = slop_map_get(spo_idx, &(s)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
        if (_mv_196.has_value) {
            __auto_type pred_map = _mv_196.value;
            __auto_type _mv_198 = ({ void* _ptr = slop_map_get(pred_map, &(p)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
            if (_mv_198.has_value) {
                __auto_type obj_set = _mv_198.value;
                return (slop_map_get(obj_set, &(o)) != NULL);
            } else if (!_mv_198.has_value) {
                return 0;
            }
            SLOP_UNREACHABLE();
        } else if (!_mv_196.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    }
    return _retval;
}

slop_list_rdf_Triple rdf_indexed_graph_match(slop_arena* arena, index_IndexedGraph g, slop_option_rdf_Term subj, slop_option_rdf_Term pred, slop_option_rdf_Term obj) {
    SLOP_PRE(((g.size >= 0)), "(>= (. g size) 0)");
    slop_list_rdf_Triple _retval = {0};
    {
        __auto_type result = ((slop_list_rdf_Triple){ .data = (rdf_Triple*)slop_arena_alloc(arena, 16 * sizeof(rdf_Triple)), .len = 0, .cap = 16 });
        __auto_type _mv_200 = subj;
        if (_mv_200.has_value) {
            __auto_type s = _mv_200.value;
            __auto_type _mv_202 = ({ void* _ptr = slop_map_get(g.index.spo, &(s)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
            if (_mv_202.has_value) {
                __auto_type pred_map = _mv_202.value;
                __auto_type _mv_203 = pred;
                if (_mv_203.has_value) {
                    __auto_type p = _mv_203.value;
                    __auto_type _mv_205 = ({ void* _ptr = slop_map_get(pred_map, &(p)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                    if (_mv_205.has_value) {
                        __auto_type term_set = _mv_205.value;
                        __auto_type _mv_206 = obj;
                        if (_mv_206.has_value) {
                            __auto_type o = _mv_206.value;
                            if (slop_map_get(term_set, &(o)) != NULL) {
                                ({ __auto_type _lst_p = &(result); __auto_type _item = (((rdf_Triple){.subject = s, .predicate = p, .object = o})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        } else if (!_mv_206.has_value) {
                            {
                                slop_map* _coll = (slop_map*)term_set;
                                for (size_t _i = 0; _i < _coll->cap; _i++) {
                                    if (_coll->entries[_i].occupied) {
                                        rdf_Term o = *(rdf_Term*)_coll->entries[_i].key;
                                        ({ __auto_type _lst_p = &(result); __auto_type _item = (((rdf_Triple){.subject = s, .predicate = p, .object = o})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    } else if (!_mv_205.has_value) {
                    }
                } else if (!_mv_203.has_value) {
                    {
                        slop_map* _coll = (slop_map*)pred_map;
                        for (size_t _i = 0; _i < _coll->cap; _i++) {
                            if (_coll->entries[_i].occupied) {
                                rdf_Term p = *(rdf_Term*)_coll->entries[_i].key;
                                index_TermSet term_set = *(index_TermSet*)_coll->entries[_i].value;
                                __auto_type _mv_208 = obj;
                                if (_mv_208.has_value) {
                                    __auto_type o = _mv_208.value;
                                    if (slop_map_get(term_set, &(o)) != NULL) {
                                        ({ __auto_type _lst_p = &(result); __auto_type _item = (((rdf_Triple){.subject = s, .predicate = p, .object = o})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                } else if (!_mv_208.has_value) {
                                    {
                                        slop_map* _coll = (slop_map*)term_set;
                                        for (size_t _i = 0; _i < _coll->cap; _i++) {
                                            if (_coll->entries[_i].occupied) {
                                                rdf_Term o = *(rdf_Term*)_coll->entries[_i].key;
                                                ({ __auto_type _lst_p = &(result); __auto_type _item = (((rdf_Triple){.subject = s, .predicate = p, .object = o})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else if (!_mv_202.has_value) {
            }
        } else if (!_mv_200.has_value) {
            __auto_type _mv_210 = pred;
            if (_mv_210.has_value) {
                __auto_type p = _mv_210.value;
                __auto_type _mv_211 = obj;
                if (_mv_211.has_value) {
                    __auto_type o = _mv_211.value;
                    __auto_type _mv_213 = ({ void* _ptr = slop_map_get(g.index.pos, &(p)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                    if (_mv_213.has_value) {
                        __auto_type obj_map = _mv_213.value;
                        __auto_type _mv_215 = ({ void* _ptr = slop_map_get(obj_map, &(o)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                        if (_mv_215.has_value) {
                            __auto_type subj_set = _mv_215.value;
                            {
                                slop_map* _coll = (slop_map*)subj_set;
                                for (size_t _i = 0; _i < _coll->cap; _i++) {
                                    if (_coll->entries[_i].occupied) {
                                        rdf_Term s = *(rdf_Term*)_coll->entries[_i].key;
                                        ({ __auto_type _lst_p = &(result); __auto_type _item = (((rdf_Triple){.subject = s, .predicate = p, .object = o})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        } else if (!_mv_215.has_value) {
                        }
                    } else if (!_mv_213.has_value) {
                    }
                } else if (!_mv_211.has_value) {
                    __auto_type _mv_217 = ({ void* _ptr = slop_map_get(g.index.pso, &(p)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                    if (_mv_217.has_value) {
                        __auto_type subj_map = _mv_217.value;
                        {
                            slop_map* _coll = (slop_map*)subj_map;
                            for (size_t _i = 0; _i < _coll->cap; _i++) {
                                if (_coll->entries[_i].occupied) {
                                    rdf_Term s = *(rdf_Term*)_coll->entries[_i].key;
                                    index_TermSet term_set = *(index_TermSet*)_coll->entries[_i].value;
                                    {
                                        slop_map* _coll = (slop_map*)term_set;
                                        for (size_t _i = 0; _i < _coll->cap; _i++) {
                                            if (_coll->entries[_i].occupied) {
                                                rdf_Term o = *(rdf_Term*)_coll->entries[_i].key;
                                                ({ __auto_type _lst_p = &(result); __auto_type _item = (((rdf_Triple){.subject = s, .predicate = p, .object = o})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if (!_mv_217.has_value) {
                    }
                }
            } else if (!_mv_210.has_value) {
                __auto_type _mv_218 = obj;
                if (_mv_218.has_value) {
                    __auto_type o = _mv_218.value;
                    __auto_type _mv_220 = ({ void* _ptr = slop_map_get(g.index.osp, &(o)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                    if (_mv_220.has_value) {
                        __auto_type subj_map = _mv_220.value;
                        {
                            slop_map* _coll = (slop_map*)subj_map;
                            for (size_t _i = 0; _i < _coll->cap; _i++) {
                                if (_coll->entries[_i].occupied) {
                                    rdf_Term s = *(rdf_Term*)_coll->entries[_i].key;
                                    index_TermSet term_set = *(index_TermSet*)_coll->entries[_i].value;
                                    {
                                        slop_map* _coll = (slop_map*)term_set;
                                        for (size_t _i = 0; _i < _coll->cap; _i++) {
                                            if (_coll->entries[_i].occupied) {
                                                rdf_Term p = *(rdf_Term*)_coll->entries[_i].key;
                                                ({ __auto_type _lst_p = &(result); __auto_type _item = (((rdf_Triple){.subject = s, .predicate = p, .object = o})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if (!_mv_220.has_value) {
                    }
                } else if (!_mv_218.has_value) {
                    {
                        __auto_type _coll = g.triples;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type t = _coll.data[_i];
                            ({ __auto_type _lst_p = &(result); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        _retval = result;
    }
    SLOP_POST(((((int64_t)((_retval).len)) >= 0)), "(>= (list-len $result) 0)");
    return _retval;
}

void rdf_indexed_graph_for_each(index_IndexedGraph g, slop_option_rdf_Term subj, slop_option_rdf_Term pred, slop_option_rdf_Term obj, slop_closure_t callback) {
    SLOP_PRE(((g.size >= 0)), "(>= (. g size) 0)");
    __auto_type _mv_221 = subj;
    if (_mv_221.has_value) {
        __auto_type s = _mv_221.value;
        __auto_type _mv_223 = ({ void* _ptr = slop_map_get(g.index.spo, &(s)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
        if (_mv_223.has_value) {
            __auto_type pred_map = _mv_223.value;
            __auto_type _mv_224 = pred;
            if (_mv_224.has_value) {
                __auto_type p = _mv_224.value;
                __auto_type _mv_226 = ({ void* _ptr = slop_map_get(pred_map, &(p)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                if (_mv_226.has_value) {
                    __auto_type term_set = _mv_226.value;
                    __auto_type _mv_227 = obj;
                    if (_mv_227.has_value) {
                        __auto_type o = _mv_227.value;
                        if (slop_map_get(term_set, &(o)) != NULL) {
                            ((void(*)(void*, rdf_Triple))callback.fn)(callback.env, ((rdf_Triple){.subject = s, .predicate = p, .object = o}));
                        }
                    } else if (!_mv_227.has_value) {
                        {
                            slop_map* _coll = (slop_map*)term_set;
                            for (size_t _i = 0; _i < _coll->cap; _i++) {
                                if (_coll->entries[_i].occupied) {
                                    rdf_Term o = *(rdf_Term*)_coll->entries[_i].key;
                                    ((void(*)(void*, rdf_Triple))callback.fn)(callback.env, ((rdf_Triple){.subject = s, .predicate = p, .object = o}));
                                }
                            }
                        }
                    }
                } else if (!_mv_226.has_value) {
                }
            } else if (!_mv_224.has_value) {
                {
                    slop_map* _coll = (slop_map*)pred_map;
                    for (size_t _i = 0; _i < _coll->cap; _i++) {
                        if (_coll->entries[_i].occupied) {
                            rdf_Term p = *(rdf_Term*)_coll->entries[_i].key;
                            index_TermSet term_set = *(index_TermSet*)_coll->entries[_i].value;
                            __auto_type _mv_229 = obj;
                            if (_mv_229.has_value) {
                                __auto_type o = _mv_229.value;
                                if (slop_map_get(term_set, &(o)) != NULL) {
                                    ((void(*)(void*, rdf_Triple))callback.fn)(callback.env, ((rdf_Triple){.subject = s, .predicate = p, .object = o}));
                                }
                            } else if (!_mv_229.has_value) {
                                {
                                    slop_map* _coll = (slop_map*)term_set;
                                    for (size_t _i = 0; _i < _coll->cap; _i++) {
                                        if (_coll->entries[_i].occupied) {
                                            rdf_Term o = *(rdf_Term*)_coll->entries[_i].key;
                                            ((void(*)(void*, rdf_Triple))callback.fn)(callback.env, ((rdf_Triple){.subject = s, .predicate = p, .object = o}));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if (!_mv_223.has_value) {
        }
    } else if (!_mv_221.has_value) {
        __auto_type _mv_231 = pred;
        if (_mv_231.has_value) {
            __auto_type p = _mv_231.value;
            __auto_type _mv_232 = obj;
            if (_mv_232.has_value) {
                __auto_type o = _mv_232.value;
                __auto_type _mv_234 = ({ void* _ptr = slop_map_get(g.index.pos, &(p)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                if (_mv_234.has_value) {
                    __auto_type obj_map = _mv_234.value;
                    __auto_type _mv_236 = ({ void* _ptr = slop_map_get(obj_map, &(o)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                    if (_mv_236.has_value) {
                        __auto_type subj_set = _mv_236.value;
                        {
                            slop_map* _coll = (slop_map*)subj_set;
                            for (size_t _i = 0; _i < _coll->cap; _i++) {
                                if (_coll->entries[_i].occupied) {
                                    rdf_Term s = *(rdf_Term*)_coll->entries[_i].key;
                                    ((void(*)(void*, rdf_Triple))callback.fn)(callback.env, ((rdf_Triple){.subject = s, .predicate = p, .object = o}));
                                }
                            }
                        }
                    } else if (!_mv_236.has_value) {
                    }
                } else if (!_mv_234.has_value) {
                }
            } else if (!_mv_232.has_value) {
                __auto_type _mv_238 = ({ void* _ptr = slop_map_get(g.index.pso, &(p)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                if (_mv_238.has_value) {
                    __auto_type subj_map = _mv_238.value;
                    {
                        slop_map* _coll = (slop_map*)subj_map;
                        for (size_t _i = 0; _i < _coll->cap; _i++) {
                            if (_coll->entries[_i].occupied) {
                                rdf_Term s = *(rdf_Term*)_coll->entries[_i].key;
                                index_TermSet term_set = *(index_TermSet*)_coll->entries[_i].value;
                                {
                                    slop_map* _coll = (slop_map*)term_set;
                                    for (size_t _i = 0; _i < _coll->cap; _i++) {
                                        if (_coll->entries[_i].occupied) {
                                            rdf_Term o = *(rdf_Term*)_coll->entries[_i].key;
                                            ((void(*)(void*, rdf_Triple))callback.fn)(callback.env, ((rdf_Triple){.subject = s, .predicate = p, .object = o}));
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_238.has_value) {
                }
            }
        } else if (!_mv_231.has_value) {
            __auto_type _mv_239 = obj;
            if (_mv_239.has_value) {
                __auto_type o = _mv_239.value;
                __auto_type _mv_241 = ({ void* _ptr = slop_map_get(g.index.osp, &(o)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                if (_mv_241.has_value) {
                    __auto_type subj_map = _mv_241.value;
                    {
                        slop_map* _coll = (slop_map*)subj_map;
                        for (size_t _i = 0; _i < _coll->cap; _i++) {
                            if (_coll->entries[_i].occupied) {
                                rdf_Term s = *(rdf_Term*)_coll->entries[_i].key;
                                index_TermSet term_set = *(index_TermSet*)_coll->entries[_i].value;
                                {
                                    slop_map* _coll = (slop_map*)term_set;
                                    for (size_t _i = 0; _i < _coll->cap; _i++) {
                                        if (_coll->entries[_i].occupied) {
                                            rdf_Term p = *(rdf_Term*)_coll->entries[_i].key;
                                            ((void(*)(void*, rdf_Triple))callback.fn)(callback.env, ((rdf_Triple){.subject = s, .predicate = p, .object = o}));
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_241.has_value) {
                }
            } else if (!_mv_239.has_value) {
                {
                    __auto_type _coll = g.triples;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type t = _coll.data[_i];
                        ((void(*)(void*, rdf_Triple))callback.fn)(callback.env, t);
                    }
                }
            }
        }
    }
}

int64_t rdf_indexed_graph_size(index_IndexedGraph g) {
    int64_t _retval = {0};
    _retval = g.size;
    SLOP_POST(((_retval == g.size)), "(== $result (. g size))");
    return _retval;
}

slop_list_rdf_Term rdf_indexed_graph_subjects(slop_arena* arena, index_IndexedGraph g, rdf_Term pred, rdf_Term obj) {
    SLOP_PRE(((g.size >= 0)), "(>= (. g size) 0)");
    {
        __auto_type result = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type pos_idx = g.index.pos;
        __auto_type _mv_243 = ({ void* _ptr = slop_map_get(pos_idx, &(pred)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
        if (_mv_243.has_value) {
            __auto_type obj_map = _mv_243.value;
            __auto_type _mv_245 = ({ void* _ptr = slop_map_get(obj_map, &(obj)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
            if (_mv_245.has_value) {
                __auto_type subj_set = _mv_245.value;
                {
                    slop_map* _coll = (slop_map*)subj_set;
                    for (size_t _i = 0; _i < _coll->cap; _i++) {
                        if (_coll->entries[_i].occupied) {
                            rdf_Term s = *(rdf_Term*)_coll->entries[_i].key;
                            ({ __auto_type _lst_p = &(result); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            } else if (!_mv_245.has_value) {
            }
        } else if (!_mv_243.has_value) {
        }
        return result;
    }
}

slop_list_rdf_Term rdf_indexed_graph_objects(slop_arena* arena, index_IndexedGraph g, rdf_Term subj, rdf_Term pred) {
    SLOP_PRE(((g.size >= 0)), "(>= (. g size) 0)");
    {
        __auto_type result = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type spo_idx = g.index.spo;
        __auto_type _mv_247 = ({ void* _ptr = slop_map_get(spo_idx, &(subj)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
        if (_mv_247.has_value) {
            __auto_type pred_map = _mv_247.value;
            __auto_type _mv_249 = ({ void* _ptr = slop_map_get(pred_map, &(pred)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
            if (_mv_249.has_value) {
                __auto_type obj_set = _mv_249.value;
                {
                    slop_map* _coll = (slop_map*)obj_set;
                    for (size_t _i = 0; _i < _coll->cap; _i++) {
                        if (_coll->entries[_i].occupied) {
                            rdf_Term o = *(rdf_Term*)_coll->entries[_i].key;
                            ({ __auto_type _lst_p = &(result); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            } else if (!_mv_249.has_value) {
            }
        } else if (!_mv_247.has_value) {
        }
        return result;
    }
}

