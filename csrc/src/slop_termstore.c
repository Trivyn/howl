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
    __auto_type _mv_755 = t;
    switch (_mv_755.tag) {
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_755.data.term_triple;
            {
                __auto_type tr = (*tt);
                __auto_type key = ((termstore_IdTriple){.s = termstore_intern_term(arena, st, tr.subject), .p = termstore_intern_term(arena, st, tr.predicate), .o = termstore_intern_term(arena, st, tr.object)});
                __auto_type _mv_757 = ({ void* _ptr = slop_map_get(st.quoted, &(key)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
                if (_mv_757.has_value) {
                    __auto_type id = _mv_757.value;
                    return id;
                } else if (!_mv_757.has_value) {
                    {
                        __auto_type id = ((int64_t)(((int64_t)(st.terms)->len)));
                        ({ int64_t _val = id; slop_map_put(NULL, st.quoted, &(key), &_val, sizeof(_val)); });
                        ({ rdf_Term _val = t; slop_map_put(NULL, st.terms, &(int64_t){id}, &_val, sizeof(_val)); });
                        return id;
                    }
                }
                SLOP_UNREACHABLE();
            }
        }
        default: {
            __auto_type _mv_761 = ({ void* _ptr = slop_map_get(st.ids, &(t)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
            if (_mv_761.has_value) {
                __auto_type id = _mv_761.value;
                return id;
            } else if (!_mv_761.has_value) {
                {
                    __auto_type id = ((int64_t)(((int64_t)(st.terms)->len)));
                    ({ int64_t _val = id; slop_map_put(NULL, st.ids, &(t), &_val, sizeof(_val)); });
                    ({ rdf_Term _val = t; slop_map_put(NULL, st.terms, &(int64_t){id}, &_val, sizeof(_val)); });
                    return id;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
}

slop_option_int termstore_lookup_term(termstore_TermStore st, rdf_Term t) {
    __auto_type _mv_764 = t;
    switch (_mv_764.tag) {
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_764.data.term_triple;
            {
                __auto_type tr = (*tt);
                __auto_type _mv_765 = termstore_lookup_term(st, tr.subject);
                if (!_mv_765.has_value) {
                    return (slop_option_int){.has_value = false};
                } else if (_mv_765.has_value) {
                    __auto_type s = _mv_765.value;
                    __auto_type _mv_766 = termstore_lookup_term(st, tr.predicate);
                    if (!_mv_766.has_value) {
                        return (slop_option_int){.has_value = false};
                    } else if (_mv_766.has_value) {
                        __auto_type p = _mv_766.value;
                        __auto_type _mv_767 = termstore_lookup_term(st, tr.object);
                        if (!_mv_767.has_value) {
                            return (slop_option_int){.has_value = false};
                        } else if (_mv_767.has_value) {
                            __auto_type o = _mv_767.value;
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
    __auto_type _mv_770 = s;
    if (_mv_770.has_value) {
        __auto_type v = _mv_770.value;
        return (slop_option_string){.has_value = 1, .value = termstore_copy_string(arena, v)};
    } else if (!_mv_770.has_value) {
        return (slop_option_string){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

rdf_Term termstore_own_plain_term(slop_arena* arena, rdf_Term t) {
    __auto_type _mv_771 = t;
    switch (_mv_771.tag) {
        case rdf_Term_term_iri:
        {
            __auto_type i = _mv_771.data.term_iri;
            return ((rdf_Term){ .tag = rdf_Term_term_iri, .data.term_iri = ((rdf_IRI){.value = termstore_copy_string(arena, i.value)}) });
        }
        case rdf_Term_term_blank:
        {
            __auto_type _ = _mv_771.data.term_blank;
            return t;
        }
        case rdf_Term_term_literal:
        {
            __auto_type l = _mv_771.data.term_literal;
            return rdf_make_literal(arena, termstore_copy_string(arena, l.value), termstore_copy_option_string(arena, l.datatype), termstore_copy_option_string(arena, l.lang));
        }
        case rdf_Term_term_triple:
        {
            __auto_type _ = _mv_771.data.term_triple;
            return t;
        }
    }
    SLOP_UNREACHABLE();
}

rdf_Term termstore_term_of(termstore_TermStore st, int64_t id) {
    __auto_type _mv_773 = ({ void* _ptr = slop_map_get(st.terms, &(int64_t){id}); _ptr ? (slop_option_rdf_Term){ .has_value = true, .value = *(rdf_Term*)_ptr } : (slop_option_rdf_Term){ .has_value = false }; });
    if (_mv_773.has_value) {
        __auto_type t = _mv_773.value;
        return t;
    } else if (!_mv_773.has_value) {
        return ((rdf_Term){ .tag = rdf_Term_term_blank, .data.term_blank = ((rdf_BlankNode){.id = 0}) });
    }
    SLOP_UNREACHABLE();
}

rdf_Triple termstore_triple_of(termstore_TermStore st, termstore_IdTriple it) {
    return ((rdf_Triple){.subject = termstore_term_of(st, it.s), .predicate = termstore_term_of(st, it.p), .object = termstore_term_of(st, it.o)});
}

int64_t termstore_intern_owned(slop_arena* arena, termstore_TermStore st, rdf_Term t) {
    __auto_type _mv_774 = t;
    switch (_mv_774.tag) {
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_774.data.term_triple;
            {
                __auto_type tr = (*tt);
                __auto_type key = ((termstore_IdTriple){.s = termstore_intern_owned(arena, st, tr.subject), .p = termstore_intern_owned(arena, st, tr.predicate), .o = termstore_intern_owned(arena, st, tr.object)});
                __auto_type _mv_776 = ({ void* _ptr = slop_map_get(st.quoted, &(key)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
                if (_mv_776.has_value) {
                    __auto_type id = _mv_776.value;
                    return id;
                } else if (!_mv_776.has_value) {
                    {
                        __auto_type id = ((int64_t)(((int64_t)(st.terms)->len)));
                        __auto_type owned = rdf_make_triple_term(arena, rdf_make_triple(arena, termstore_term_of(st, key.s), termstore_term_of(st, key.p), termstore_term_of(st, key.o)));
                        ({ int64_t _val = id; slop_map_put(NULL, st.quoted, &(key), &_val, sizeof(_val)); });
                        ({ rdf_Term _val = owned; slop_map_put(NULL, st.terms, &(int64_t){id}, &_val, sizeof(_val)); });
                        return id;
                    }
                }
                SLOP_UNREACHABLE();
            }
        }
        default: {
            __auto_type _mv_780 = ({ void* _ptr = slop_map_get(st.ids, &(t)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
            if (_mv_780.has_value) {
                __auto_type id = _mv_780.value;
                return id;
            } else if (!_mv_780.has_value) {
                {
                    __auto_type id = ((int64_t)(((int64_t)(st.terms)->len)));
                    __auto_type c = termstore_own_plain_term(arena, t);
                    ({ int64_t _val = id; slop_map_put(NULL, st.ids, &(c), &_val, sizeof(_val)); });
                    ({ rdf_Term _val = c; slop_map_put(NULL, st.terms, &(int64_t){id}, &_val, sizeof(_val)); });
                    return id;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
}

void termstore_typed_put(slop_arena* arena, termstore_TermStore st, int64_t type, int64_t s) {
    __auto_type _mv_784 = ({ void* _ptr = slop_map_get(st.typed, &(int64_t){type}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
    if (_mv_784.has_value) {
        __auto_type subs = _mv_784.value;
        ({ slop_map_put(NULL, subs, &(int64_t){s}, NULL, 0); });
    } else if (!_mv_784.has_value) {
        {
            __auto_type subs = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
            ({ slop_map_put(NULL, subs, &(int64_t){s}, NULL, 0); });
            ({ slop_map* _val = subs; slop_map_put(NULL, st.typed, &(int64_t){type}, &_val, sizeof(_val)); });
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
        __auto_type _mv_789 = ({ void* _ptr = slop_map_get(st.spo, &(sp)); _ptr ? (slop_option_termstore_Objects){ .has_value = true, .value = *(termstore_Objects*)_ptr } : (slop_option_termstore_Objects){ .has_value = false }; });
        if (_mv_789.has_value) {
            __auto_type objs = _mv_789.value;
            if ((objs.first == o) || slop_map_has(objs.more, &(int64_t){o})) {
                return 0;
            } else {
                ({ slop_map_put(NULL, objs.more, &(int64_t){o}, NULL, 0); });
                if (p == st.rdf_type) {
                    termstore_typed_put(arena, st, o, s);
                }
                return 1;
            }
        } else if (!_mv_789.has_value) {
            {
                __auto_type objs = ((termstore_Objects){.first = o, .more = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); })});
                ({ termstore_Objects _val = objs; slop_map_put(NULL, st.spo, &(sp), &_val, sizeof(_val)); });
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
        (*p) = ((termstore_Encoded){.dict = termstore_empty_store(arena), .triples = ((slop_list_termstore_IdTriple){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .offset = 0, .max_blank = 0});
        return p;
    }
}

int64_t termstore_max_blank_in(rdf_Term t) {
    __auto_type _mv_793 = t;
    switch (_mv_793.tag) {
        case rdf_Term_term_blank:
        {
            __auto_type b = _mv_793.data.term_blank;
            return b.id;
        }
        case rdf_Term_term_iri:
        {
            __auto_type _ = _mv_793.data.term_iri;
            return 0;
        }
        case rdf_Term_term_literal:
        {
            __auto_type _ = _mv_793.data.term_literal;
            return 0;
        }
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_793.data.term_triple;
            {
                __auto_type tr = (*tt);
                return ((termstore_max_blank_in(tr.subject)) > (((termstore_max_blank_in(tr.predicate)) > (termstore_max_blank_in(tr.object)) ? (termstore_max_blank_in(tr.predicate)) : (termstore_max_blank_in(tr.object)))) ? (termstore_max_blank_in(tr.subject)) : (((termstore_max_blank_in(tr.predicate)) > (termstore_max_blank_in(tr.object)) ? (termstore_max_blank_in(tr.predicate)) : (termstore_max_blank_in(tr.object)))));
            }
        }
    }
    SLOP_UNREACHABLE();
}

rdf_Term termstore_shift_blanks(slop_arena* arena, rdf_Term t, int64_t offset) {
    __auto_type _mv_794 = t;
    switch (_mv_794.tag) {
        case rdf_Term_term_blank:
        {
            __auto_type b = _mv_794.data.term_blank;
            return rdf_make_blank(arena, SLOP_RANGE(rdf_BlankNodeId, (b.id + offset), 1, 0, 0, 0, "BlankNodeId (Int 0 ..) at termstore.slop:405:43"));
        }
        case rdf_Term_term_iri:
        {
            __auto_type _ = _mv_794.data.term_iri;
            return t;
        }
        case rdf_Term_term_literal:
        {
            __auto_type _ = _mv_794.data.term_literal;
            return t;
        }
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_794.data.term_triple;
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
        ({ __auto_type _lst_p = &(e.triples); __auto_type _item = (it); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        __auto_type out = ((slop_list_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_795 = termstore_lookup_term(st, s);
        if (_mv_795.has_value) {
            __auto_type si = _mv_795.value;
            __auto_type _mv_796 = termstore_lookup_term(st, p);
            if (_mv_796.has_value) {
                __auto_type pi = _mv_796.value;
                {
                    __auto_type key = ((termstore_IdPair){.a = si, .b = pi});
                    __auto_type _mv_798 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_termstore_Objects){ .has_value = true, .value = *(termstore_Objects*)_ptr } : (slop_option_termstore_Objects){ .has_value = false }; });
                    if (_mv_798.has_value) {
                        __auto_type objs = _mv_798.value;
                        __auto_type _mv_800 = ({ void* _ptr = slop_map_get(st.terms, &(int64_t){objs.first}); _ptr ? (slop_option_rdf_Term){ .has_value = true, .value = *(rdf_Term*)_ptr } : (slop_option_rdf_Term){ .has_value = false }; });
                        if (_mv_800.has_value) {
                            __auto_type term = _mv_800.value;
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (term); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        } else if (!_mv_800.has_value) {
                        }
                        {
                            slop_map* _coll = (slop_map*)objs.more;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    int64_t o = *(int64_t*)slop_map_key_at(_coll, _i);
                                    __auto_type _mv_802 = ({ void* _ptr = slop_map_get(st.terms, &(int64_t){o}); _ptr ? (slop_option_rdf_Term){ .has_value = true, .value = *(rdf_Term*)_ptr } : (slop_option_rdf_Term){ .has_value = false }; });
                                    if (_mv_802.has_value) {
                                        __auto_type term = _mv_802.value;
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (term); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_802.has_value) {
                                    }
                                }
                            }
                        }
                    } else if (!_mv_798.has_value) {
                    }
                }
            } else if (!_mv_796.has_value) {
            }
        } else if (!_mv_795.has_value) {
        }
        return out;
    }
}

int64_t termstore_store_object_count(termstore_TermStore st, rdf_Term s, rdf_Term p) {
    __auto_type _mv_803 = termstore_lookup_term(st, s);
    if (_mv_803.has_value) {
        __auto_type si = _mv_803.value;
        __auto_type _mv_804 = termstore_lookup_term(st, p);
        if (_mv_804.has_value) {
            __auto_type pi = _mv_804.value;
            {
                __auto_type key = ((termstore_IdPair){.a = si, .b = pi});
                __auto_type _mv_806 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_termstore_Objects){ .has_value = true, .value = *(termstore_Objects*)_ptr } : (slop_option_termstore_Objects){ .has_value = false }; });
                if (_mv_806.has_value) {
                    __auto_type objs = _mv_806.value;
                    return (1 + ((int64_t)(((int64_t)(objs.more)->len))));
                } else if (!_mv_806.has_value) {
                    return 0;
                }
                SLOP_UNREACHABLE();
            }
        } else if (!_mv_804.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_803.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_option_rdf_Term termstore_store_sole_object(termstore_TermStore st, rdf_Term s, rdf_Term p) {
    __auto_type _mv_807 = termstore_lookup_term(st, s);
    if (_mv_807.has_value) {
        __auto_type si = _mv_807.value;
        __auto_type _mv_808 = termstore_lookup_term(st, p);
        if (_mv_808.has_value) {
            __auto_type pi = _mv_808.value;
            {
                __auto_type key = ((termstore_IdPair){.a = si, .b = pi});
                __auto_type _mv_810 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_termstore_Objects){ .has_value = true, .value = *(termstore_Objects*)_ptr } : (slop_option_termstore_Objects){ .has_value = false }; });
                if (_mv_810.has_value) {
                    __auto_type objs = _mv_810.value;
                    if (((int64_t)(objs.more)->len) == 0) {
                        return ({ void* _ptr = slop_map_get(st.terms, &(int64_t){objs.first}); _ptr ? (slop_option_rdf_Term){ .has_value = true, .value = *(rdf_Term*)_ptr } : (slop_option_rdf_Term){ .has_value = false }; });
                    } else {
                        return (slop_option_rdf_Term){.has_value = false};
                    }
                } else if (!_mv_810.has_value) {
                    return (slop_option_rdf_Term){.has_value = false};
                }
                SLOP_UNREACHABLE();
            }
        } else if (!_mv_808.has_value) {
            return (slop_option_rdf_Term){.has_value = false};
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_807.has_value) {
        return (slop_option_rdf_Term){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

slop_list_rdf_Term termstore_store_typed(slop_arena* arena, termstore_TermStore st, rdf_Term type) {
    {
        __auto_type out = ((slop_list_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_812 = termstore_lookup_term(st, type);
        if (_mv_812.has_value) {
            __auto_type ti = _mv_812.value;
            __auto_type _mv_814 = ({ void* _ptr = slop_map_get(st.typed, &(int64_t){ti}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
            if (_mv_814.has_value) {
                __auto_type subs = _mv_814.value;
                {
                    slop_map* _coll = (slop_map*)subs;
                    for (size_t _i = 0; _i < _coll->len; _i++) {
                        {
                            int64_t s = *(int64_t*)slop_map_key_at(_coll, _i);
                            __auto_type _mv_816 = ({ void* _ptr = slop_map_get(st.terms, &(int64_t){s}); _ptr ? (slop_option_rdf_Term){ .has_value = true, .value = *(rdf_Term*)_ptr } : (slop_option_rdf_Term){ .has_value = false }; });
                            if (_mv_816.has_value) {
                                __auto_type term = _mv_816.value;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (term); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else if (!_mv_816.has_value) {
                            }
                        }
                    }
                }
            } else if (!_mv_814.has_value) {
            }
        } else if (!_mv_812.has_value) {
        }
        return out;
    }
}

uint8_t termstore_store_contains(termstore_TermStore st, rdf_Triple t) {
    __auto_type _mv_817 = termstore_lookup_term(st, t.subject);
    if (!_mv_817.has_value) {
        return 0;
    } else if (_mv_817.has_value) {
        __auto_type si = _mv_817.value;
        __auto_type _mv_818 = termstore_lookup_term(st, t.predicate);
        if (!_mv_818.has_value) {
            return 0;
        } else if (_mv_818.has_value) {
            __auto_type pi = _mv_818.value;
            __auto_type _mv_819 = termstore_lookup_term(st, t.object);
            if (!_mv_819.has_value) {
                return 0;
            } else if (_mv_819.has_value) {
                __auto_type oi = _mv_819.value;
                {
                    __auto_type key = ((termstore_IdPair){.a = si, .b = pi});
                    __auto_type _mv_821 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_termstore_Objects){ .has_value = true, .value = *(termstore_Objects*)_ptr } : (slop_option_termstore_Objects){ .has_value = false }; });
                    if (_mv_821.has_value) {
                        __auto_type objs = _mv_821.value;
                        return ((objs.first == oi) || slop_map_has(objs.more, &(int64_t){oi}));
                    } else if (!_mv_821.has_value) {
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
    __auto_type _mv_823 = termstore_lookup_term(st, s);
    if (!_mv_823.has_value) {
        return 0;
    } else if (_mv_823.has_value) {
        __auto_type si = _mv_823.value;
        __auto_type _mv_824 = termstore_lookup_term(st, p);
        if (!_mv_824.has_value) {
            return 0;
        } else if (_mv_824.has_value) {
            __auto_type pi = _mv_824.value;
            {
                __auto_type key = ((termstore_IdPair){.a = si, .b = pi});
                __auto_type _mv_826 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_termstore_Objects){ .has_value = true, .value = *(termstore_Objects*)_ptr } : (slop_option_termstore_Objects){ .has_value = false }; });
                if (_mv_826.has_value) {
                    __auto_type _ = _mv_826.value;
                    return 1;
                } else if (!_mv_826.has_value) {
                    return 0;
                }
                SLOP_UNREACHABLE();
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

