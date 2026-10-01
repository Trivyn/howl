#include "../runtime/slop_runtime.h"
#include "slop_termstore.h"

int64_t termstore_intern_term(slop_arena* arena, termstore_TermStore st, rdf_Term t);
slop_option_int termstore_lookup_term(termstore_TermStore st, rdf_Term t);
slop_string termstore_copy_string(slop_arena* arena, slop_string s);
slop_option_string termstore_copy_option_string(slop_arena* arena, slop_option_string s);
rdf_Term termstore_own_plain_term(slop_arena* arena, rdf_Term t);
rdf_Term termstore_term_of(termstore_TermStore st, int64_t id);
rdf_Triple termstore_triple_of(termstore_TermStore st, termstore_IdTriple it);
int64_t termstore_intern_owned(slop_arena* arena, termstore_TermStore st, rdf_Term t);
void termstore_typed_put(slop_arena* arena, termstore_TermStore st, int64_t type, int64_t s);
uint8_t termstore_store_insert(slop_arena* arena, termstore_TermStore st, rdf_Triple t);
uint8_t termstore_store_insert_ids(slop_arena* arena, termstore_TermStore st, termstore_IdTriple it);
termstore_TermStore termstore_build_store(slop_arena* arena, slop_list_rdf_Triple triples);
termstore_TermStore termstore_empty_store(slop_arena* arena);
termstore_TermStore termstore_store_over(slop_arena* arena, termstore_TermStore dict);
termstore_Encoded* termstore_new_encoded(slop_arena* arena);
int64_t termstore_max_blank_in(rdf_Term t);
rdf_Term termstore_shift_blanks(slop_arena* arena, rdf_Term t, int64_t offset);
void termstore_encoded_add(slop_arena* arena, termstore_Encoded* p, rdf_Triple t);
void termstore_encoded_next_document(slop_arena* arena, termstore_Encoded* p);
termstore_Encoded termstore_encode_triples(slop_arena* arena, slop_list_rdf_Triple triples);
slop_list_rdf_Term termstore_store_objects(slop_arena* arena, termstore_TermStore st, rdf_Term s, rdf_Term p);
int64_t termstore_store_object_count(termstore_TermStore st, rdf_Term s, rdf_Term p);
slop_option_rdf_Term termstore_store_sole_object(termstore_TermStore st, rdf_Term s, rdf_Term p);
slop_list_rdf_Term termstore_store_typed(slop_arena* arena, termstore_TermStore st, rdf_Term type);
uint8_t termstore_store_contains(termstore_TermStore st, rdf_Triple t);
uint8_t termstore_store_has_any(termstore_TermStore st, rdf_Term s, rdf_Term p);

int64_t termstore_intern_term(slop_arena* arena, termstore_TermStore st, rdf_Term t) {
    __auto_type _mv_243 = t;
    switch (_mv_243.tag) {
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_243.data.term_triple;
            {
                __auto_type tr = (*tt);
                __auto_type key = ((termstore_IdTriple){.s = termstore_intern_term(arena, st, tr.subject), .p = termstore_intern_term(arena, st, tr.predicate), .o = termstore_intern_term(arena, st, tr.object)});
                __auto_type _mv_245 = ({ void* _ptr = slop_map_get(st.quoted, &(key)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
                if (_mv_245.has_value) {
                    __auto_type id = _mv_245.value;
                    return id;
                } else if (!_mv_245.has_value) {
                    {
                        __auto_type id = ((int64_t)(((int64_t)(st.terms)->len)));
                        ({ int64_t _val = id; slop_map_put(arena, st.quoted, &(key), &_val, sizeof(_val)); });
                        ({ rdf_Term _val = t; slop_map_put(arena, st.terms, &(int64_t){id}, &_val, sizeof(_val)); });
                        return id;
                    }
                }
                SLOP_UNREACHABLE();
            }
        }
        default: {
            __auto_type _mv_249 = ({ void* _ptr = slop_map_get(st.ids, &(t)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
            if (_mv_249.has_value) {
                __auto_type id = _mv_249.value;
                return id;
            } else if (!_mv_249.has_value) {
                {
                    __auto_type id = ((int64_t)(((int64_t)(st.terms)->len)));
                    ({ int64_t _val = id; slop_map_put(arena, st.ids, &(t), &_val, sizeof(_val)); });
                    ({ rdf_Term _val = t; slop_map_put(arena, st.terms, &(int64_t){id}, &_val, sizeof(_val)); });
                    return id;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
}

slop_option_int termstore_lookup_term(termstore_TermStore st, rdf_Term t) {
    __auto_type _mv_252 = t;
    switch (_mv_252.tag) {
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_252.data.term_triple;
            {
                __auto_type tr = (*tt);
                __auto_type _mv_253 = termstore_lookup_term(st, tr.subject);
                if (!_mv_253.has_value) {
                    return (slop_option_int){.has_value = false};
                } else if (_mv_253.has_value) {
                    __auto_type s = _mv_253.value;
                    __auto_type _mv_254 = termstore_lookup_term(st, tr.predicate);
                    if (!_mv_254.has_value) {
                        return (slop_option_int){.has_value = false};
                    } else if (_mv_254.has_value) {
                        __auto_type p = _mv_254.value;
                        __auto_type _mv_255 = termstore_lookup_term(st, tr.object);
                        if (!_mv_255.has_value) {
                            return (slop_option_int){.has_value = false};
                        } else if (_mv_255.has_value) {
                            __auto_type o = _mv_255.value;
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

slop_string termstore_copy_string(slop_arena* arena, slop_string s) {
    return string_concat(arena, s, SLOP_STR(""));
}

slop_option_string termstore_copy_option_string(slop_arena* arena, slop_option_string s) {
    __auto_type _mv_258 = s;
    if (_mv_258.has_value) {
        __auto_type v = _mv_258.value;
        return (slop_option_string){.has_value = 1, .value = termstore_copy_string(arena, v)};
    } else if (!_mv_258.has_value) {
        return (slop_option_string){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

rdf_Term termstore_own_plain_term(slop_arena* arena, rdf_Term t) {
    __auto_type _mv_259 = t;
    switch (_mv_259.tag) {
        case rdf_Term_term_iri:
        {
            __auto_type i = _mv_259.data.term_iri;
            return ((rdf_Term){ .tag = rdf_Term_term_iri, .data.term_iri = ((rdf_IRI){.value = termstore_copy_string(arena, i.value)}) });
        }
        case rdf_Term_term_blank:
        {
            __auto_type _ = _mv_259.data.term_blank;
            return t;
        }
        case rdf_Term_term_literal:
        {
            __auto_type l = _mv_259.data.term_literal;
            return rdf_make_literal(arena, termstore_copy_string(arena, l.value), termstore_copy_option_string(arena, l.datatype), termstore_copy_option_string(arena, l.lang));
        }
        case rdf_Term_term_triple:
        {
            __auto_type _ = _mv_259.data.term_triple;
            return t;
        }
    }
    SLOP_UNREACHABLE();
}

rdf_Term termstore_term_of(termstore_TermStore st, int64_t id) {
    __auto_type _mv_261 = ({ void* _ptr = slop_map_get(st.terms, &(int64_t){id}); _ptr ? (slop_option_rdf_Term){ .has_value = true, .value = *(rdf_Term*)_ptr } : (slop_option_rdf_Term){ .has_value = false }; });
    if (_mv_261.has_value) {
        __auto_type t = _mv_261.value;
        return t;
    } else if (!_mv_261.has_value) {
        return ((rdf_Term){ .tag = rdf_Term_term_blank, .data.term_blank = ((rdf_BlankNode){.id = 0}) });
    }
    SLOP_UNREACHABLE();
}

rdf_Triple termstore_triple_of(termstore_TermStore st, termstore_IdTriple it) {
    return ((rdf_Triple){.subject = termstore_term_of(st, it.s), .predicate = termstore_term_of(st, it.p), .object = termstore_term_of(st, it.o)});
}

int64_t termstore_intern_owned(slop_arena* arena, termstore_TermStore st, rdf_Term t) {
    __auto_type _mv_262 = t;
    switch (_mv_262.tag) {
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_262.data.term_triple;
            {
                __auto_type tr = (*tt);
                __auto_type key = ((termstore_IdTriple){.s = termstore_intern_owned(arena, st, tr.subject), .p = termstore_intern_owned(arena, st, tr.predicate), .o = termstore_intern_owned(arena, st, tr.object)});
                __auto_type _mv_264 = ({ void* _ptr = slop_map_get(st.quoted, &(key)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
                if (_mv_264.has_value) {
                    __auto_type id = _mv_264.value;
                    return id;
                } else if (!_mv_264.has_value) {
                    {
                        __auto_type id = ((int64_t)(((int64_t)(st.terms)->len)));
                        __auto_type owned = rdf_make_triple_term(arena, rdf_make_triple(arena, termstore_term_of(st, key.s), termstore_term_of(st, key.p), termstore_term_of(st, key.o)));
                        ({ int64_t _val = id; slop_map_put(arena, st.quoted, &(key), &_val, sizeof(_val)); });
                        ({ rdf_Term _val = owned; slop_map_put(arena, st.terms, &(int64_t){id}, &_val, sizeof(_val)); });
                        return id;
                    }
                }
                SLOP_UNREACHABLE();
            }
        }
        default: {
            __auto_type _mv_268 = ({ void* _ptr = slop_map_get(st.ids, &(t)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
            if (_mv_268.has_value) {
                __auto_type id = _mv_268.value;
                return id;
            } else if (!_mv_268.has_value) {
                {
                    __auto_type id = ((int64_t)(((int64_t)(st.terms)->len)));
                    __auto_type c = termstore_own_plain_term(arena, t);
                    ({ int64_t _val = id; slop_map_put(arena, st.ids, &(c), &_val, sizeof(_val)); });
                    ({ rdf_Term _val = c; slop_map_put(arena, st.terms, &(int64_t){id}, &_val, sizeof(_val)); });
                    return id;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
}

void termstore_typed_put(slop_arena* arena, termstore_TermStore st, int64_t type, int64_t s) {
    __auto_type _mv_272 = ({ void* _ptr = slop_map_get(st.typed, &(int64_t){type}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
    if (_mv_272.has_value) {
        __auto_type subs = _mv_272.value;
        ({ slop_map_put(arena, subs, &(int64_t){s}, NULL, 0); });
    } else if (!_mv_272.has_value) {
        {
            __auto_type subs = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
            ({ slop_map_put(arena, subs, &(int64_t){s}, NULL, 0); });
            ({ slop_map* _val = subs; slop_map_put(arena, st.typed, &(int64_t){type}, &_val, sizeof(_val)); });
        }
    }
}

uint8_t termstore_store_insert(slop_arena* arena, termstore_TermStore st, rdf_Triple t) {
    return termstore_store_insert_ids(arena, st, ((termstore_IdTriple){.s = termstore_intern_term(arena, st, t.subject), .p = termstore_intern_term(arena, st, t.predicate), .o = termstore_intern_term(arena, st, t.object)}));
}

uint8_t termstore_store_insert_ids(slop_arena* arena, termstore_TermStore st, termstore_IdTriple it) {
    {
        __auto_type s = it.s;
        __auto_type p = it.p;
        __auto_type o = it.o;
        __auto_type sp = ((termstore_IdPair){.a = s, .b = p});
        __auto_type _mv_277 = ({ void* _ptr = slop_map_get(st.spo, &(sp)); _ptr ? (slop_option_termstore_Objects){ .has_value = true, .value = *(termstore_Objects*)_ptr } : (slop_option_termstore_Objects){ .has_value = false }; });
        if (_mv_277.has_value) {
            __auto_type objs = _mv_277.value;
            if ((objs.first == o) || slop_map_has(objs.more, &(int64_t){o})) {
                return 0;
            } else {
                ({ slop_map_put(arena, objs.more, &(int64_t){o}, NULL, 0); });
                if (p == st.rdf_type) {
                    termstore_typed_put(arena, st, o, s);
                }
                return 1;
            }
        } else if (!_mv_277.has_value) {
            {
                __auto_type objs = ((termstore_Objects){.first = o, .more = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); })});
                ({ termstore_Objects _val = objs; slop_map_put(arena, st.spo, &(sp), &_val, sizeof(_val)); });
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
        __auto_type st = termstore_empty_store(arena);
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

termstore_TermStore termstore_empty_store(slop_arena* arena) {
    {
        __auto_type st0 = ((termstore_TermStore){.ids = ({ static const slop_map_desc _d = SLOP_MAP_DESC(rdf_Term, slop_hash_rdf_Term, slop_eq_rdf_Term, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .quoted = ({ static const slop_map_desc _d = SLOP_MAP_DESC(termstore_IdTriple, slop_hash_termstore_IdTriple, slop_eq_termstore_IdTriple, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .terms = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, rdf_Term); slop_map_new_ptr(arena, 0, &_d); }), .spo = ({ static const slop_map_desc _d = SLOP_MAP_DESC(termstore_IdPair, slop_hash_termstore_IdPair, slop_eq_termstore_IdPair, SLOP_KEY_HASHED, termstore_Objects); slop_map_new_ptr(arena, 0, &_d); }), .typed = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, slop_map*); slop_map_new_ptr(arena, 0, &_d); }), .rdf_type = 0});
        __auto_type ty = termstore_intern_term(arena, st0, rdf_make_iri(arena, vocab_RDF_TYPE));
        __auto_type st = ((termstore_TermStore){.ids = st0.ids, .quoted = st0.quoted, .terms = st0.terms, .spo = st0.spo, .typed = st0.typed, .rdf_type = ty});
        return st;
    }
}

termstore_TermStore termstore_store_over(slop_arena* arena, termstore_TermStore dict) {
    return ((termstore_TermStore){.ids = dict.ids, .quoted = dict.quoted, .terms = dict.terms, .spo = ({ static const slop_map_desc _d = SLOP_MAP_DESC(termstore_IdPair, slop_hash_termstore_IdPair, slop_eq_termstore_IdPair, SLOP_KEY_HASHED, termstore_Objects); slop_map_new_ptr(arena, 0, &_d); }), .typed = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, slop_map*); slop_map_new_ptr(arena, 0, &_d); }), .rdf_type = dict.rdf_type});
}

termstore_Encoded* termstore_new_encoded(slop_arena* arena) {
    {
        __auto_type p = ((termstore_Encoded*)(({ __auto_type _alloc = (termstore_Encoded*)slop_arena_alloc(arena, sizeof(termstore_Encoded)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = ((termstore_Encoded){.dict = termstore_empty_store(arena), .triples = ((slop_list_termstore_IdTriple){ .data = NULL, .len = 0, .cap = 0 }), .offset = 0, .max_blank = 0});
        return p;
    }
}

int64_t termstore_max_blank_in(rdf_Term t) {
    __auto_type _mv_281 = t;
    switch (_mv_281.tag) {
        case rdf_Term_term_blank:
        {
            __auto_type b = _mv_281.data.term_blank;
            return b.id;
        }
        case rdf_Term_term_iri:
        {
            __auto_type _ = _mv_281.data.term_iri;
            return 0;
        }
        case rdf_Term_term_literal:
        {
            __auto_type _ = _mv_281.data.term_literal;
            return 0;
        }
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_281.data.term_triple;
            {
                __auto_type tr = (*tt);
                return ((termstore_max_blank_in(tr.subject)) > (((termstore_max_blank_in(tr.predicate)) > (termstore_max_blank_in(tr.object)) ? (termstore_max_blank_in(tr.predicate)) : (termstore_max_blank_in(tr.object)))) ? (termstore_max_blank_in(tr.subject)) : (((termstore_max_blank_in(tr.predicate)) > (termstore_max_blank_in(tr.object)) ? (termstore_max_blank_in(tr.predicate)) : (termstore_max_blank_in(tr.object)))));
            }
        }
    }
    SLOP_UNREACHABLE();
}

rdf_Term termstore_shift_blanks(slop_arena* arena, rdf_Term t, int64_t offset) {
    __auto_type _mv_282 = t;
    switch (_mv_282.tag) {
        case rdf_Term_term_blank:
        {
            __auto_type b = _mv_282.data.term_blank;
            return rdf_make_blank(arena, (b.id + offset));
        }
        case rdf_Term_term_iri:
        {
            __auto_type _ = _mv_282.data.term_iri;
            return t;
        }
        case rdf_Term_term_literal:
        {
            __auto_type _ = _mv_282.data.term_literal;
            return t;
        }
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_282.data.term_triple;
            {
                __auto_type tr = (*tt);
                return rdf_make_triple_term(arena, rdf_make_triple(arena, termstore_shift_blanks(arena, tr.subject, offset), termstore_shift_blanks(arena, tr.predicate, offset), termstore_shift_blanks(arena, tr.object, offset)));
            }
        }
    }
    SLOP_UNREACHABLE();
}

void termstore_encoded_add(slop_arena* arena, termstore_Encoded* p, rdf_Triple t) {
    {
        __auto_type e = (*p);
        __auto_type off = e.offset;
        __auto_type sj = (((off == 0)) ? t.subject : termstore_shift_blanks(arena, t.subject, off));
        __auto_type pr = t.predicate;
        __auto_type ob = (((off == 0)) ? t.object : termstore_shift_blanks(arena, t.object, off));
        __auto_type it = ((termstore_IdTriple){.s = termstore_intern_owned(arena, e.dict, sj), .p = termstore_intern_owned(arena, e.dict, pr), .o = termstore_intern_owned(arena, e.dict, ob)});
        ({ __auto_type _lst_p = &(e.triples); __auto_type _item = (it); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        e.max_blank = ((e.max_blank) > (((termstore_max_blank_in(sj)) > (((termstore_max_blank_in(pr)) > (termstore_max_blank_in(ob)) ? (termstore_max_blank_in(pr)) : (termstore_max_blank_in(ob)))) ? (termstore_max_blank_in(sj)) : (((termstore_max_blank_in(pr)) > (termstore_max_blank_in(ob)) ? (termstore_max_blank_in(pr)) : (termstore_max_blank_in(ob)))))) ? (e.max_blank) : (((termstore_max_blank_in(sj)) > (((termstore_max_blank_in(pr)) > (termstore_max_blank_in(ob)) ? (termstore_max_blank_in(pr)) : (termstore_max_blank_in(ob)))) ? (termstore_max_blank_in(sj)) : (((termstore_max_blank_in(pr)) > (termstore_max_blank_in(ob)) ? (termstore_max_blank_in(pr)) : (termstore_max_blank_in(ob)))))));
        (*p) = e;
    }
}

void termstore_encoded_next_document(slop_arena* arena, termstore_Encoded* p) {
    {
        __auto_type e = (*p);
        e.offset = (e.max_blank + 1);
        (*p) = e;
    }
}

termstore_Encoded termstore_encode_triples(slop_arena* arena, slop_list_rdf_Triple triples) {
    {
        __auto_type p = termstore_new_encoded(arena);
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                termstore_encoded_add(arena, p, t);
            }
        }
        return (*p);
    }
}

slop_list_rdf_Term termstore_store_objects(slop_arena* arena, termstore_TermStore st, rdf_Term s, rdf_Term p) {
    {
        __auto_type out = ((slop_list_rdf_Term){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_283 = termstore_lookup_term(st, s);
        if (_mv_283.has_value) {
            __auto_type si = _mv_283.value;
            __auto_type _mv_284 = termstore_lookup_term(st, p);
            if (_mv_284.has_value) {
                __auto_type pi = _mv_284.value;
                {
                    __auto_type key = ((termstore_IdPair){.a = si, .b = pi});
                    __auto_type _mv_286 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_termstore_Objects){ .has_value = true, .value = *(termstore_Objects*)_ptr } : (slop_option_termstore_Objects){ .has_value = false }; });
                    if (_mv_286.has_value) {
                        __auto_type objs = _mv_286.value;
                        __auto_type _mv_288 = ({ void* _ptr = slop_map_get(st.terms, &(int64_t){objs.first}); _ptr ? (slop_option_rdf_Term){ .has_value = true, .value = *(rdf_Term*)_ptr } : (slop_option_rdf_Term){ .has_value = false }; });
                        if (_mv_288.has_value) {
                            __auto_type term = _mv_288.value;
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (term); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        } else if (!_mv_288.has_value) {
                        }
                        {
                            slop_map* _coll = (slop_map*)objs.more;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    int64_t o = *(int64_t*)slop_map_key_at(_coll, _i);
                                    __auto_type _mv_290 = ({ void* _ptr = slop_map_get(st.terms, &(int64_t){o}); _ptr ? (slop_option_rdf_Term){ .has_value = true, .value = *(rdf_Term*)_ptr } : (slop_option_rdf_Term){ .has_value = false }; });
                                    if (_mv_290.has_value) {
                                        __auto_type term = _mv_290.value;
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (term); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_290.has_value) {
                                    }
                                }
                            }
                        }
                    } else if (!_mv_286.has_value) {
                    }
                }
            } else if (!_mv_284.has_value) {
            }
        } else if (!_mv_283.has_value) {
        }
        return out;
    }
}

int64_t termstore_store_object_count(termstore_TermStore st, rdf_Term s, rdf_Term p) {
    __auto_type _mv_291 = termstore_lookup_term(st, s);
    if (_mv_291.has_value) {
        __auto_type si = _mv_291.value;
        __auto_type _mv_292 = termstore_lookup_term(st, p);
        if (_mv_292.has_value) {
            __auto_type pi = _mv_292.value;
            {
                __auto_type key = ((termstore_IdPair){.a = si, .b = pi});
                __auto_type _mv_294 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_termstore_Objects){ .has_value = true, .value = *(termstore_Objects*)_ptr } : (slop_option_termstore_Objects){ .has_value = false }; });
                if (_mv_294.has_value) {
                    __auto_type objs = _mv_294.value;
                    return (1 + ((int64_t)(((int64_t)(objs.more)->len))));
                } else if (!_mv_294.has_value) {
                    return 0;
                }
                SLOP_UNREACHABLE();
            }
        } else if (!_mv_292.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_291.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_option_rdf_Term termstore_store_sole_object(termstore_TermStore st, rdf_Term s, rdf_Term p) {
    __auto_type _mv_295 = termstore_lookup_term(st, s);
    if (_mv_295.has_value) {
        __auto_type si = _mv_295.value;
        __auto_type _mv_296 = termstore_lookup_term(st, p);
        if (_mv_296.has_value) {
            __auto_type pi = _mv_296.value;
            {
                __auto_type key = ((termstore_IdPair){.a = si, .b = pi});
                __auto_type _mv_298 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_termstore_Objects){ .has_value = true, .value = *(termstore_Objects*)_ptr } : (slop_option_termstore_Objects){ .has_value = false }; });
                if (_mv_298.has_value) {
                    __auto_type objs = _mv_298.value;
                    if (((int64_t)(objs.more)->len) == 0) {
                        return ({ void* _ptr = slop_map_get(st.terms, &(int64_t){objs.first}); _ptr ? (slop_option_rdf_Term){ .has_value = true, .value = *(rdf_Term*)_ptr } : (slop_option_rdf_Term){ .has_value = false }; });
                    } else {
                        return (slop_option_rdf_Term){.has_value = false};
                    }
                } else if (!_mv_298.has_value) {
                    return (slop_option_rdf_Term){.has_value = false};
                }
                SLOP_UNREACHABLE();
            }
        } else if (!_mv_296.has_value) {
            return (slop_option_rdf_Term){.has_value = false};
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_295.has_value) {
        return (slop_option_rdf_Term){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

slop_list_rdf_Term termstore_store_typed(slop_arena* arena, termstore_TermStore st, rdf_Term type) {
    {
        __auto_type out = ((slop_list_rdf_Term){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_300 = termstore_lookup_term(st, type);
        if (_mv_300.has_value) {
            __auto_type ti = _mv_300.value;
            __auto_type _mv_302 = ({ void* _ptr = slop_map_get(st.typed, &(int64_t){ti}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
            if (_mv_302.has_value) {
                __auto_type subs = _mv_302.value;
                {
                    slop_map* _coll = (slop_map*)subs;
                    for (size_t _i = 0; _i < _coll->len; _i++) {
                        {
                            int64_t s = *(int64_t*)slop_map_key_at(_coll, _i);
                            __auto_type _mv_304 = ({ void* _ptr = slop_map_get(st.terms, &(int64_t){s}); _ptr ? (slop_option_rdf_Term){ .has_value = true, .value = *(rdf_Term*)_ptr } : (slop_option_rdf_Term){ .has_value = false }; });
                            if (_mv_304.has_value) {
                                __auto_type term = _mv_304.value;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (term); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else if (!_mv_304.has_value) {
                            }
                        }
                    }
                }
            } else if (!_mv_302.has_value) {
            }
        } else if (!_mv_300.has_value) {
        }
        return out;
    }
}

uint8_t termstore_store_contains(termstore_TermStore st, rdf_Triple t) {
    __auto_type _mv_305 = termstore_lookup_term(st, t.subject);
    if (!_mv_305.has_value) {
        return 0;
    } else if (_mv_305.has_value) {
        __auto_type si = _mv_305.value;
        __auto_type _mv_306 = termstore_lookup_term(st, t.predicate);
        if (!_mv_306.has_value) {
            return 0;
        } else if (_mv_306.has_value) {
            __auto_type pi = _mv_306.value;
            __auto_type _mv_307 = termstore_lookup_term(st, t.object);
            if (!_mv_307.has_value) {
                return 0;
            } else if (_mv_307.has_value) {
                __auto_type oi = _mv_307.value;
                {
                    __auto_type key = ((termstore_IdPair){.a = si, .b = pi});
                    __auto_type _mv_309 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_termstore_Objects){ .has_value = true, .value = *(termstore_Objects*)_ptr } : (slop_option_termstore_Objects){ .has_value = false }; });
                    if (_mv_309.has_value) {
                        __auto_type objs = _mv_309.value;
                        return ((objs.first == oi) || slop_map_has(objs.more, &(int64_t){oi}));
                    } else if (!_mv_309.has_value) {
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
    __auto_type _mv_311 = termstore_lookup_term(st, s);
    if (!_mv_311.has_value) {
        return 0;
    } else if (_mv_311.has_value) {
        __auto_type si = _mv_311.value;
        __auto_type _mv_312 = termstore_lookup_term(st, p);
        if (!_mv_312.has_value) {
            return 0;
        } else if (_mv_312.has_value) {
            __auto_type pi = _mv_312.value;
            {
                __auto_type key = ((termstore_IdPair){.a = si, .b = pi});
                __auto_type _mv_314 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_termstore_Objects){ .has_value = true, .value = *(termstore_Objects*)_ptr } : (slop_option_termstore_Objects){ .has_value = false }; });
                if (_mv_314.has_value) {
                    __auto_type _ = _mv_314.value;
                    return 1;
                } else if (!_mv_314.has_value) {
                    return 0;
                }
                SLOP_UNREACHABLE();
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

