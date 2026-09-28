#include "../runtime/slop_runtime.h"
#include "slop_termstore.h"

int64_t termstore_intern_term(slop_arena* arena, termstore_TermStore st, rdf_Term t);
slop_option_int termstore_lookup_term(termstore_TermStore st, rdf_Term t);
void termstore_typed_put(slop_arena* arena, termstore_TermStore st, int64_t type, int64_t s);
uint8_t termstore_store_insert(slop_arena* arena, termstore_TermStore st, rdf_Triple t);
termstore_TermStore termstore_build_store(slop_arena* arena, slop_list_rdf_Triple triples);
slop_list_rdf_Term termstore_store_objects(slop_arena* arena, termstore_TermStore st, rdf_Term s, rdf_Term p);
slop_list_rdf_Term termstore_store_typed(slop_arena* arena, termstore_TermStore st, rdf_Term type);
uint8_t termstore_store_contains(termstore_TermStore st, rdf_Triple t);
uint8_t termstore_store_has_any(termstore_TermStore st, rdf_Term s, rdf_Term p);

int64_t termstore_intern_term(slop_arena* arena, termstore_TermStore st, rdf_Term t) {
    __auto_type _mv_162 = t;
    switch (_mv_162.tag) {
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_162.data.term_triple;
            {
                __auto_type tr = (*tt);
                __auto_type key = ((termstore_IdTriple){.s = termstore_intern_term(arena, st, tr.subject), .p = termstore_intern_term(arena, st, tr.predicate), .o = termstore_intern_term(arena, st, tr.object)});
                __auto_type _mv_164 = ({ void* _ptr = slop_map_get(st.quoted, &(key)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
                if (_mv_164.has_value) {
                    __auto_type id = _mv_164.value;
                    return id;
                } else if (!_mv_164.has_value) {
                    {
                        __auto_type id = ((int64_t)(((int64_t)(st.terms)->len)));
                        ({ int64_t _val = id; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, st.quoted, &(key), _vptr); });
                        ({ __auto_type _val = t; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, st.terms, &(int64_t){id}, _vptr); });
                        return id;
                    }
                }
                SLOP_UNREACHABLE();
            }
        }
        default: {
            __auto_type _mv_168 = ({ void* _ptr = slop_map_get(st.ids, &(t)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
            if (_mv_168.has_value) {
                __auto_type id = _mv_168.value;
                return id;
            } else if (!_mv_168.has_value) {
                {
                    __auto_type id = ((int64_t)(((int64_t)(st.terms)->len)));
                    ({ int64_t _val = id; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, st.ids, &(t), _vptr); });
                    ({ __auto_type _val = t; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, st.terms, &(int64_t){id}, _vptr); });
                    return id;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
}

slop_option_int termstore_lookup_term(termstore_TermStore st, rdf_Term t) {
    __auto_type _mv_171 = t;
    switch (_mv_171.tag) {
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_171.data.term_triple;
            {
                __auto_type tr = (*tt);
                __auto_type _mv_172 = termstore_lookup_term(st, tr.subject);
                if (!_mv_172.has_value) {
                    return (slop_option_int){.has_value = false};
                } else if (_mv_172.has_value) {
                    __auto_type s = _mv_172.value;
                    __auto_type _mv_173 = termstore_lookup_term(st, tr.predicate);
                    if (!_mv_173.has_value) {
                        return (slop_option_int){.has_value = false};
                    } else if (_mv_173.has_value) {
                        __auto_type p = _mv_173.value;
                        __auto_type _mv_174 = termstore_lookup_term(st, tr.object);
                        if (!_mv_174.has_value) {
                            return (slop_option_int){.has_value = false};
                        } else if (_mv_174.has_value) {
                            __auto_type o = _mv_174.value;
                            {
                                __auto_type key = ((termstore_IdTriple){.s = s, .p = p, .o = o});
                                return ({ void* _ptr = slop_map_get(st.quoted, &(key)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
                            }
                        }
                        SLOP_UNREACHABLE();
                    }
                    SLOP_UNREACHABLE();
                }
                SLOP_UNREACHABLE();
            }
        }
        default: {
            return ({ void* _ptr = slop_map_get(st.ids, &(t)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
        }
    }
}

void termstore_typed_put(slop_arena* arena, termstore_TermStore st, int64_t type, int64_t s) {
    __auto_type _mv_178 = ({ void* _ptr = slop_map_get(st.typed, &(int64_t){type}); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
    if (_mv_178.has_value) {
        __auto_type subs = _mv_178.value;
        ({ uint8_t _dummy = 1; slop_map_put(arena, subs, &(int64_t){s}, &_dummy); });
    } else if (!_mv_178.has_value) {
        {
            __auto_type subs = slop_map_new_ptr(arena, 16, sizeof(int64_t), slop_hash_int, slop_eq_int);
            ({ uint8_t _dummy = 1; slop_map_put(arena, subs, &(int64_t){s}, &_dummy); });
            ({ __auto_type _val = subs; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, st.typed, &(int64_t){type}, _vptr); });
        }
    }
}

uint8_t termstore_store_insert(slop_arena* arena, termstore_TermStore st, rdf_Triple t) {
    {
        __auto_type s = termstore_intern_term(arena, st, t.subject);
        __auto_type p = termstore_intern_term(arena, st, t.predicate);
        __auto_type o = termstore_intern_term(arena, st, t.object);
        __auto_type sp = ((termstore_IdPair){.a = s, .b = p});
        __auto_type _mv_183 = ({ void* _ptr = slop_map_get(st.spo, &(sp)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
        if (_mv_183.has_value) {
            __auto_type objs = _mv_183.value;
            if (slop_map_get(objs, &(int64_t){o}) != NULL) {
                return 0;
            } else {
                ({ uint8_t _dummy = 1; slop_map_put(arena, objs, &(int64_t){o}, &_dummy); });
                if (p == st.rdf_type) {
                    termstore_typed_put(arena, st, o, s);
                }
                return 1;
            }
        } else if (!_mv_183.has_value) {
            {
                __auto_type objs = slop_map_new_ptr(arena, 16, sizeof(int64_t), slop_hash_int, slop_eq_int);
                ({ uint8_t _dummy = 1; slop_map_put(arena, objs, &(int64_t){o}, &_dummy); });
                ({ __auto_type _val = objs; void* _vptr = slop_arena_alloc(arena, sizeof(_val)); memcpy(_vptr, &_val, sizeof(_val)); slop_map_put(arena, st.spo, &(sp), _vptr); });
                if (p == st.rdf_type) {
                    termstore_typed_put(arena, st, o, s);
                }
                return 1;
            }
        }
        SLOP_UNREACHABLE();
    }
}

termstore_TermStore termstore_build_store(slop_arena* arena, slop_list_rdf_Triple triples) {
    {
        __auto_type st0 = ((termstore_TermStore){.ids = slop_map_new_ptr(arena, 16, sizeof(rdf_Term), slop_hash_rdf_Term, slop_eq_rdf_Term), .quoted = slop_map_new_ptr(arena, 16, sizeof(termstore_IdTriple), slop_hash_termstore_IdTriple, slop_eq_termstore_IdTriple), .terms = slop_map_new_ptr(arena, 16, sizeof(int64_t), slop_hash_int, slop_eq_int), .spo = slop_map_new_ptr(arena, 16, sizeof(termstore_IdPair), slop_hash_termstore_IdPair, slop_eq_termstore_IdPair), .typed = slop_map_new_ptr(arena, 16, sizeof(int64_t), slop_hash_int, slop_eq_int), .rdf_type = 0});
        __auto_type ty = termstore_intern_term(arena, st0, rdf_make_iri(arena, vocab_RDF_TYPE));
        __auto_type st = ((termstore_TermStore){.ids = st0.ids, .quoted = st0.quoted, .terms = st0.terms, .spo = st0.spo, .typed = st0.typed, .rdf_type = ty});
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                termstore_store_insert(arena, st, t);
            }
        }
        return st;
    }
}

slop_list_rdf_Term termstore_store_objects(slop_arena* arena, termstore_TermStore st, rdf_Term s, rdf_Term p) {
    {
        __auto_type out = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type _mv_188 = termstore_lookup_term(st, s);
        if (_mv_188.has_value) {
            __auto_type si = _mv_188.value;
            __auto_type _mv_189 = termstore_lookup_term(st, p);
            if (_mv_189.has_value) {
                __auto_type pi = _mv_189.value;
                {
                    __auto_type key = ((termstore_IdPair){.a = si, .b = pi});
                    __auto_type _mv_191 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                    if (_mv_191.has_value) {
                        __auto_type objs = _mv_191.value;
                        {
                            slop_map* _coll = (slop_map*)objs;
                            for (size_t _i = 0; _i < _coll->cap; _i++) {
                                if (_coll->entries[_i].occupied) {
                                    int64_t o = *(int64_t*)_coll->entries[_i].key;
                                    __auto_type _mv_193 = ({ void* _ptr = slop_map_get(st.terms, &(int64_t){o}); _ptr ? (slop_option_rdf_Term){ .has_value = true, .value = *(rdf_Term*)_ptr } : (slop_option_rdf_Term){ .has_value = false }; });
                                    if (_mv_193.has_value) {
                                        __auto_type term = _mv_193.value;
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (term); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_193.has_value) {
                                    }
                                }
                            }
                        }
                    } else if (!_mv_191.has_value) {
                    }
                }
            } else if (!_mv_189.has_value) {
            }
        } else if (!_mv_188.has_value) {
        }
        return out;
    }
}

slop_list_rdf_Term termstore_store_typed(slop_arena* arena, termstore_TermStore st, rdf_Term type) {
    {
        __auto_type out = ((slop_list_rdf_Term){ .data = (rdf_Term*)slop_arena_alloc(arena, 16 * sizeof(rdf_Term)), .len = 0, .cap = 16 });
        __auto_type _mv_194 = termstore_lookup_term(st, type);
        if (_mv_194.has_value) {
            __auto_type ti = _mv_194.value;
            __auto_type _mv_196 = ({ void* _ptr = slop_map_get(st.typed, &(int64_t){ti}); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
            if (_mv_196.has_value) {
                __auto_type subs = _mv_196.value;
                {
                    slop_map* _coll = (slop_map*)subs;
                    for (size_t _i = 0; _i < _coll->cap; _i++) {
                        if (_coll->entries[_i].occupied) {
                            int64_t s = *(int64_t*)_coll->entries[_i].key;
                            __auto_type _mv_198 = ({ void* _ptr = slop_map_get(st.terms, &(int64_t){s}); _ptr ? (slop_option_rdf_Term){ .has_value = true, .value = *(rdf_Term*)_ptr } : (slop_option_rdf_Term){ .has_value = false }; });
                            if (_mv_198.has_value) {
                                __auto_type term = _mv_198.value;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (term); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else if (!_mv_198.has_value) {
                            }
                        }
                    }
                }
            } else if (!_mv_196.has_value) {
            }
        } else if (!_mv_194.has_value) {
        }
        return out;
    }
}

uint8_t termstore_store_contains(termstore_TermStore st, rdf_Triple t) {
    __auto_type _mv_199 = termstore_lookup_term(st, t.subject);
    if (!_mv_199.has_value) {
        return 0;
    } else if (_mv_199.has_value) {
        __auto_type si = _mv_199.value;
        __auto_type _mv_200 = termstore_lookup_term(st, t.predicate);
        if (!_mv_200.has_value) {
            return 0;
        } else if (_mv_200.has_value) {
            __auto_type pi = _mv_200.value;
            __auto_type _mv_201 = termstore_lookup_term(st, t.object);
            if (!_mv_201.has_value) {
                return 0;
            } else if (_mv_201.has_value) {
                __auto_type oi = _mv_201.value;
                {
                    __auto_type key = ((termstore_IdPair){.a = si, .b = pi});
                    __auto_type _mv_203 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                    if (_mv_203.has_value) {
                        __auto_type objs = _mv_203.value;
                        return (slop_map_get(objs, &(int64_t){oi}) != NULL);
                    } else if (!_mv_203.has_value) {
                        return 0;
                    }
                    SLOP_UNREACHABLE();
                }
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

uint8_t termstore_store_has_any(termstore_TermStore st, rdf_Term s, rdf_Term p) {
    __auto_type _mv_205 = termstore_lookup_term(st, s);
    if (!_mv_205.has_value) {
        return 0;
    } else if (_mv_205.has_value) {
        __auto_type si = _mv_205.value;
        __auto_type _mv_206 = termstore_lookup_term(st, p);
        if (!_mv_206.has_value) {
            return 0;
        } else if (_mv_206.has_value) {
            __auto_type pi = _mv_206.value;
            {
                __auto_type key = ((termstore_IdPair){.a = si, .b = pi});
                __auto_type _mv_208 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_ptr){ .has_value = true, .value = *(void**)_ptr } : (slop_option_ptr){ .has_value = false }; });
                if (_mv_208.has_value) {
                    __auto_type _ = _mv_208.value;
                    return 1;
                } else if (!_mv_208.has_value) {
                    return 0;
                }
                SLOP_UNREACHABLE();
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

