#include "../runtime/slop_runtime.h"
#include "slop_termstore.h"

int64_t howl_termstore_intern_term(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Term t);
slop_option_int howl_termstore_lookup_term(howl_termstore_TermStore st, slop_rdf_rdf_Term t);
slop_string howl_termstore_copy_string(slop_arena* arena, slop_string s);
slop_option_string howl_termstore_copy_option_string(slop_arena* arena, slop_option_string s);
slop_rdf_rdf_Term howl_termstore_own_plain_term(slop_arena* arena, slop_rdf_rdf_Term t);
slop_rdf_rdf_Term howl_termstore_term_of(howl_termstore_TermStore st, int64_t id);
slop_rdf_rdf_Triple howl_termstore_triple_of(howl_termstore_TermStore st, howl_termstore_IdTriple it);
int64_t howl_termstore_intern_owned(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Term t);
void howl_termstore_typed_put(slop_arena* arena, howl_termstore_TermStore st, int64_t type, int64_t s);
uint8_t howl_termstore_store_insert(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Triple t);
uint8_t howl_termstore_store_insert_ids(slop_arena* arena, howl_termstore_TermStore st, howl_termstore_IdTriple it);
howl_termstore_TermStore howl_termstore_build_store(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples);
howl_termstore_TermStore howl_termstore_empty_store(slop_arena* arena);
howl_termstore_TermStore howl_termstore_store_over(slop_arena* arena, howl_termstore_TermStore dict);
howl_termstore_Encoded* howl_termstore_new_encoded(slop_arena* arena);
slop_list_int howl_termstore_first_start(slop_arena* arena);
int64_t howl_termstore_max_blank_in(slop_rdf_rdf_Term t);
slop_rdf_rdf_Term howl_termstore_shift_blanks(slop_arena* arena, slop_rdf_rdf_Term t, int64_t offset);
void howl_termstore_encoded_add(slop_arena* arena, howl_termstore_Encoded* p, slop_rdf_rdf_Triple t);
void howl_termstore_encoded_next_document(slop_arena* arena, howl_termstore_Encoded* p);
int64_t howl_termstore_doc_at(slop_list_int starts, int64_t i, int64_t cur);
howl_termstore_Encoded howl_termstore_encode_triples(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples);
slop_list_slop_rdf_rdf_Term howl_termstore_store_objects(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Term s, slop_rdf_rdf_Term p);
int64_t howl_termstore_store_object_count(howl_termstore_TermStore st, slop_rdf_rdf_Term s, slop_rdf_rdf_Term p);
slop_option_slop_rdf_rdf_Term howl_termstore_store_sole_object(howl_termstore_TermStore st, slop_rdf_rdf_Term s, slop_rdf_rdf_Term p);
slop_list_slop_rdf_rdf_Term howl_termstore_store_typed(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Term type);
uint8_t howl_termstore_store_contains(howl_termstore_TermStore st, slop_rdf_rdf_Triple t);
uint8_t howl_termstore_store_has_any(howl_termstore_TermStore st, slop_rdf_rdf_Term s, slop_rdf_rdf_Term p);

int64_t howl_termstore_intern_term(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Term t) {
    __auto_type _mv_665 = t;
    switch (_mv_665.tag) {
        case slop_rdf_rdf_Term_term_triple:
        {
            __auto_type tt = _mv_665.data.term_triple;
            {
                __auto_type tr = (*tt);
                __auto_type key = ((howl_termstore_IdTriple){.s = howl_termstore_intern_term(arena, st, tr.subject), .p = howl_termstore_intern_term(arena, st, tr.predicate), .o = howl_termstore_intern_term(arena, st, tr.object)});
                __auto_type _mv_667 = ({ void* _ptr = slop_map_get(st.quoted, &(key)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
                if (_mv_667.has_value) {
                    __auto_type id = _mv_667.value;
                    return id;
                } else if (!_mv_667.has_value) {
                    {
                        __auto_type id = ((int64_t)(((int64_t)(st.terms)->len)));
                        ({ int64_t _val = id; slop_map_put(NULL, st.quoted, &(key), &_val, sizeof(_val)); });
                        ({ slop_rdf_rdf_Term _val = t; slop_map_put(NULL, st.terms, &(int64_t){id}, &_val, sizeof(_val)); });
                        return id;
                    }
                }
                SLOP_UNREACHABLE();
            }
        }
        default: {
            __auto_type _mv_671 = ({ void* _ptr = slop_map_get(st.ids, &(t)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
            if (_mv_671.has_value) {
                __auto_type id = _mv_671.value;
                return id;
            } else if (!_mv_671.has_value) {
                {
                    __auto_type id = ((int64_t)(((int64_t)(st.terms)->len)));
                    ({ int64_t _val = id; slop_map_put(NULL, st.ids, &(t), &_val, sizeof(_val)); });
                    ({ slop_rdf_rdf_Term _val = t; slop_map_put(NULL, st.terms, &(int64_t){id}, &_val, sizeof(_val)); });
                    return id;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
}

slop_option_int howl_termstore_lookup_term(howl_termstore_TermStore st, slop_rdf_rdf_Term t) {
    __auto_type _mv_674 = t;
    switch (_mv_674.tag) {
        case slop_rdf_rdf_Term_term_triple:
        {
            __auto_type tt = _mv_674.data.term_triple;
            {
                __auto_type tr = (*tt);
                __auto_type _mv_675 = howl_termstore_lookup_term(st, tr.subject);
                if (!_mv_675.has_value) {
                    return (slop_option_int){.has_value = false};
                } else if (_mv_675.has_value) {
                    __auto_type s = _mv_675.value;
                    __auto_type _mv_676 = howl_termstore_lookup_term(st, tr.predicate);
                    if (!_mv_676.has_value) {
                        return (slop_option_int){.has_value = false};
                    } else if (_mv_676.has_value) {
                        __auto_type p = _mv_676.value;
                        __auto_type _mv_677 = howl_termstore_lookup_term(st, tr.object);
                        if (!_mv_677.has_value) {
                            return (slop_option_int){.has_value = false};
                        } else if (_mv_677.has_value) {
                            __auto_type o = _mv_677.value;
                            {
                                __auto_type key = ((howl_termstore_IdTriple){.s = s, .p = p, .o = o});
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

slop_string howl_termstore_copy_string(slop_arena* arena, slop_string s) {
    return string_concat(arena, s, SLOP_STR(""));
}

slop_option_string howl_termstore_copy_option_string(slop_arena* arena, slop_option_string s) {
    __auto_type _mv_680 = s;
    if (_mv_680.has_value) {
        __auto_type v = _mv_680.value;
        return (slop_option_string){.has_value = 1, .value = howl_termstore_copy_string(arena, v)};
    } else if (!_mv_680.has_value) {
        return (slop_option_string){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

slop_rdf_rdf_Term howl_termstore_own_plain_term(slop_arena* arena, slop_rdf_rdf_Term t) {
    __auto_type _mv_681 = t;
    switch (_mv_681.tag) {
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type i = _mv_681.data.term_iri;
            return ((slop_rdf_rdf_Term){ .tag = slop_rdf_rdf_Term_term_iri, .data.term_iri = ((slop_rdf_rdf_IRI){.value = howl_termstore_copy_string(arena, i.value)}) });
        }
        case slop_rdf_rdf_Term_term_blank:
        {
            __auto_type _ = _mv_681.data.term_blank;
            return t;
        }
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type l = _mv_681.data.term_literal;
            return rdf_make_literal(arena, howl_termstore_copy_string(arena, l.value), howl_termstore_copy_option_string(arena, l.datatype), howl_termstore_copy_option_string(arena, l.lang));
        }
        case slop_rdf_rdf_Term_term_triple:
        {
            __auto_type _ = _mv_681.data.term_triple;
            return t;
        }
    }
    SLOP_UNREACHABLE();
}

slop_rdf_rdf_Term howl_termstore_term_of(howl_termstore_TermStore st, int64_t id) {
    __auto_type _mv_683 = ({ void* _ptr = slop_map_get(st.terms, &(int64_t){id}); _ptr ? (slop_option_slop_rdf_rdf_Term){ .has_value = true, .value = *(slop_rdf_rdf_Term*)_ptr } : (slop_option_slop_rdf_rdf_Term){ .has_value = false }; });
    if (_mv_683.has_value) {
        __auto_type t = _mv_683.value;
        return t;
    } else if (!_mv_683.has_value) {
        return ((slop_rdf_rdf_Term){ .tag = slop_rdf_rdf_Term_term_blank, .data.term_blank = ((slop_rdf_rdf_BlankNode){.id = 0}) });
    }
    SLOP_UNREACHABLE();
}

slop_rdf_rdf_Triple howl_termstore_triple_of(howl_termstore_TermStore st, howl_termstore_IdTriple it) {
    return ((slop_rdf_rdf_Triple){.subject = howl_termstore_term_of(st, it.s), .predicate = howl_termstore_term_of(st, it.p), .object = howl_termstore_term_of(st, it.o)});
}

int64_t howl_termstore_intern_owned(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Term t) {
    __auto_type _mv_684 = t;
    switch (_mv_684.tag) {
        case slop_rdf_rdf_Term_term_triple:
        {
            __auto_type tt = _mv_684.data.term_triple;
            {
                __auto_type tr = (*tt);
                __auto_type key = ((howl_termstore_IdTriple){.s = howl_termstore_intern_owned(arena, st, tr.subject), .p = howl_termstore_intern_owned(arena, st, tr.predicate), .o = howl_termstore_intern_owned(arena, st, tr.object)});
                __auto_type _mv_686 = ({ void* _ptr = slop_map_get(st.quoted, &(key)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
                if (_mv_686.has_value) {
                    __auto_type id = _mv_686.value;
                    return id;
                } else if (!_mv_686.has_value) {
                    {
                        __auto_type id = ((int64_t)(((int64_t)(st.terms)->len)));
                        __auto_type owned = rdf_make_triple_term(arena, rdf_make_triple(arena, howl_termstore_term_of(st, key.s), howl_termstore_term_of(st, key.p), howl_termstore_term_of(st, key.o)));
                        ({ int64_t _val = id; slop_map_put(NULL, st.quoted, &(key), &_val, sizeof(_val)); });
                        ({ slop_rdf_rdf_Term _val = owned; slop_map_put(NULL, st.terms, &(int64_t){id}, &_val, sizeof(_val)); });
                        return id;
                    }
                }
                SLOP_UNREACHABLE();
            }
        }
        default: {
            __auto_type _mv_690 = ({ void* _ptr = slop_map_get(st.ids, &(t)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
            if (_mv_690.has_value) {
                __auto_type id = _mv_690.value;
                return id;
            } else if (!_mv_690.has_value) {
                {
                    __auto_type id = ((int64_t)(((int64_t)(st.terms)->len)));
                    __auto_type c = howl_termstore_own_plain_term(arena, t);
                    ({ int64_t _val = id; slop_map_put(NULL, st.ids, &(c), &_val, sizeof(_val)); });
                    ({ slop_rdf_rdf_Term _val = c; slop_map_put(NULL, st.terms, &(int64_t){id}, &_val, sizeof(_val)); });
                    return id;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
}

void howl_termstore_typed_put(slop_arena* arena, howl_termstore_TermStore st, int64_t type, int64_t s) {
    __auto_type _mv_694 = ({ void* _ptr = slop_map_get(st.typed, &(int64_t){type}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
    if (_mv_694.has_value) {
        __auto_type subs = _mv_694.value;
        ({ slop_map_put(NULL, subs, &(int64_t){s}, NULL, 0); });
    } else if (!_mv_694.has_value) {
        {
            __auto_type subs = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
            ({ slop_map_put(NULL, subs, &(int64_t){s}, NULL, 0); });
            ({ slop_map* _val = subs; slop_map_put(NULL, st.typed, &(int64_t){type}, &_val, sizeof(_val)); });
        }
    }
}

uint8_t howl_termstore_store_insert(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Triple t) {
    return howl_termstore_store_insert_ids(arena, st, ((howl_termstore_IdTriple){.s = howl_termstore_intern_term(arena, st, t.subject), .p = howl_termstore_intern_term(arena, st, t.predicate), .o = howl_termstore_intern_term(arena, st, t.object)}));
}

uint8_t howl_termstore_store_insert_ids(slop_arena* arena, howl_termstore_TermStore st, howl_termstore_IdTriple it) {
    {
        __auto_type s = it.s;
        __auto_type p = it.p;
        __auto_type o = it.o;
        __auto_type sp = ((howl_termstore_IdPair){.a = s, .b = p});
        __auto_type _mv_699 = ({ void* _ptr = slop_map_get(st.spo, &(sp)); _ptr ? (slop_option_howl_termstore_Objects){ .has_value = true, .value = *(howl_termstore_Objects*)_ptr } : (slop_option_howl_termstore_Objects){ .has_value = false }; });
        if (_mv_699.has_value) {
            __auto_type objs = _mv_699.value;
            if ((objs.first == o) || slop_map_has(objs.more, &(int64_t){o})) {
                return 0;
            } else {
                ({ slop_map_put(NULL, objs.more, &(int64_t){o}, NULL, 0); });
                if (p == st.rdf_type) {
                    howl_termstore_typed_put(arena, st, o, s);
                }
                return 1;
            }
        } else if (!_mv_699.has_value) {
            {
                __auto_type objs = ((howl_termstore_Objects){.first = o, .more = ({ static const slop_map_desc _d = SLOP_SET_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); })});
                ({ howl_termstore_Objects _val = objs; slop_map_put(NULL, st.spo, &(sp), &_val, sizeof(_val)); });
                if (p == st.rdf_type) {
                    howl_termstore_typed_put(arena, st, o, s);
                }
                return 1;
            }
        }
        SLOP_UNREACHABLE();
    }
}

howl_termstore_TermStore howl_termstore_build_store(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples) {
    {
        __auto_type st = howl_termstore_empty_store(arena);
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                howl_termstore_store_insert(arena, st, t);
            }
        }
        return st;
    }
}

howl_termstore_TermStore howl_termstore_empty_store(slop_arena* arena) {
    {
        __auto_type st0 = ((howl_termstore_TermStore){.ids = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_Term, slop_hash_slop_rdf_rdf_Term, slop_eq_slop_rdf_rdf_Term, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .quoted = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_termstore_IdTriple, slop_hash_howl_termstore_IdTriple, slop_eq_howl_termstore_IdTriple, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .terms = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, slop_rdf_rdf_Term); slop_map_new_ptr(arena, 0, &_d); }), .spo = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_termstore_IdPair, slop_hash_howl_termstore_IdPair, slop_eq_howl_termstore_IdPair, SLOP_KEY_HASHED, howl_termstore_Objects); slop_map_new_ptr(arena, 0, &_d); }), .typed = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, slop_map*); slop_map_new_ptr(arena, 0, &_d); }), .rdf_type = 0});
        __auto_type ty = howl_termstore_intern_term(arena, st0, rdf_make_iri(arena, slop_rdf_vocab_RDF_TYPE));
        __auto_type st = ((howl_termstore_TermStore){.ids = st0.ids, .quoted = st0.quoted, .terms = st0.terms, .spo = st0.spo, .typed = st0.typed, .rdf_type = ty});
        return st;
    }
}

howl_termstore_TermStore howl_termstore_store_over(slop_arena* arena, howl_termstore_TermStore dict) {
    return ((howl_termstore_TermStore){.ids = dict.ids, .quoted = dict.quoted, .terms = dict.terms, .spo = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_termstore_IdPair, slop_hash_howl_termstore_IdPair, slop_eq_howl_termstore_IdPair, SLOP_KEY_HASHED, howl_termstore_Objects); slop_map_new_ptr(arena, 0, &_d); }), .typed = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, slop_map*); slop_map_new_ptr(arena, 0, &_d); }), .rdf_type = dict.rdf_type});
}

howl_termstore_Encoded* howl_termstore_new_encoded(slop_arena* arena) {
    {
        __auto_type p = ((howl_termstore_Encoded*)(({ __auto_type _alloc = (howl_termstore_Encoded*)slop_arena_alloc(arena, sizeof(howl_termstore_Encoded)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = ((howl_termstore_Encoded){.dict = howl_termstore_empty_store(arena), .triples = ((slop_list_howl_termstore_IdTriple){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .offset = 0, .max_blank = 0, .starts = howl_termstore_first_start(arena)});
        return p;
    }
}

slop_list_int howl_termstore_first_start(slop_arena* arena) {
    {
        __auto_type s = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(s); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return s;
    }
}

int64_t howl_termstore_max_blank_in(slop_rdf_rdf_Term t) {
    __auto_type _mv_703 = t;
    switch (_mv_703.tag) {
        case slop_rdf_rdf_Term_term_blank:
        {
            __auto_type b = _mv_703.data.term_blank;
            return b.id;
        }
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type _ = _mv_703.data.term_iri;
            return 0;
        }
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type _ = _mv_703.data.term_literal;
            return 0;
        }
        case slop_rdf_rdf_Term_term_triple:
        {
            __auto_type tt = _mv_703.data.term_triple;
            {
                __auto_type tr = (*tt);
                return ((howl_termstore_max_blank_in(tr.subject)) > (((howl_termstore_max_blank_in(tr.predicate)) > (howl_termstore_max_blank_in(tr.object)) ? (howl_termstore_max_blank_in(tr.predicate)) : (howl_termstore_max_blank_in(tr.object)))) ? (howl_termstore_max_blank_in(tr.subject)) : (((howl_termstore_max_blank_in(tr.predicate)) > (howl_termstore_max_blank_in(tr.object)) ? (howl_termstore_max_blank_in(tr.predicate)) : (howl_termstore_max_blank_in(tr.object)))));
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_rdf_rdf_Term howl_termstore_shift_blanks(slop_arena* arena, slop_rdf_rdf_Term t, int64_t offset) {
    __auto_type _mv_704 = t;
    switch (_mv_704.tag) {
        case slop_rdf_rdf_Term_term_blank:
        {
            __auto_type b = _mv_704.data.term_blank;
            return rdf_make_blank(arena, SLOP_RANGE(slop_rdf_rdf_BlankNodeId, (b.id + offset), 1, 0, 0, 0, "BlankNodeId (Int 0 ..) at termstore.slop:415:43"));
        }
        case slop_rdf_rdf_Term_term_iri:
        {
            __auto_type _ = _mv_704.data.term_iri;
            return t;
        }
        case slop_rdf_rdf_Term_term_literal:
        {
            __auto_type _ = _mv_704.data.term_literal;
            return t;
        }
        case slop_rdf_rdf_Term_term_triple:
        {
            __auto_type tt = _mv_704.data.term_triple;
            {
                __auto_type tr = (*tt);
                return rdf_make_triple_term(arena, rdf_make_triple(arena, howl_termstore_shift_blanks(arena, tr.subject, offset), howl_termstore_shift_blanks(arena, tr.predicate, offset), howl_termstore_shift_blanks(arena, tr.object, offset)));
            }
        }
    }
    SLOP_UNREACHABLE();
}

void howl_termstore_encoded_add(slop_arena* arena, howl_termstore_Encoded* p, slop_rdf_rdf_Triple t) {
    {
        __auto_type e = (*p);
        __auto_type off = e.offset;
        __auto_type sj = (((off == 0)) ? t.subject : howl_termstore_shift_blanks(arena, t.subject, off));
        __auto_type pr = t.predicate;
        __auto_type ob = (((off == 0)) ? t.object : howl_termstore_shift_blanks(arena, t.object, off));
        __auto_type it = ((howl_termstore_IdTriple){.s = howl_termstore_intern_owned(arena, e.dict, sj), .p = howl_termstore_intern_owned(arena, e.dict, pr), .o = howl_termstore_intern_owned(arena, e.dict, ob)});
        (void)(({ __auto_type _lst_p = &(e.triples); __auto_type _item = (it); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        e.max_blank = ((e.max_blank) > (((howl_termstore_max_blank_in(sj)) > (((howl_termstore_max_blank_in(pr)) > (howl_termstore_max_blank_in(ob)) ? (howl_termstore_max_blank_in(pr)) : (howl_termstore_max_blank_in(ob)))) ? (howl_termstore_max_blank_in(sj)) : (((howl_termstore_max_blank_in(pr)) > (howl_termstore_max_blank_in(ob)) ? (howl_termstore_max_blank_in(pr)) : (howl_termstore_max_blank_in(ob)))))) ? (e.max_blank) : (((howl_termstore_max_blank_in(sj)) > (((howl_termstore_max_blank_in(pr)) > (howl_termstore_max_blank_in(ob)) ? (howl_termstore_max_blank_in(pr)) : (howl_termstore_max_blank_in(ob)))) ? (howl_termstore_max_blank_in(sj)) : (((howl_termstore_max_blank_in(pr)) > (howl_termstore_max_blank_in(ob)) ? (howl_termstore_max_blank_in(pr)) : (howl_termstore_max_blank_in(ob)))))));
        (*p) = e;
    }
}

void howl_termstore_encoded_next_document(slop_arena* arena, howl_termstore_Encoded* p) {
    {
        __auto_type e = (*p);
        e.offset = (e.max_blank + 1);
        (void)(({ __auto_type _lst_p = &(e.starts); __auto_type _item = (((int64_t)(((int64_t)((e.triples).len))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (*p) = e;
    }
}

int64_t howl_termstore_doc_at(slop_list_int starts, int64_t i, int64_t cur) {
    {
        int64_t k = cur;
        __auto_type n = ((int64_t)(((int64_t)((starts).len))));
        while (((k + 1) < n) && ({ __auto_type _mv = ({ __auto_type _lst = starts; size_t _idx = (size_t)(k + 1); slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type s = _mv.value; (s <= i); }) : (0); })) {
            k = (k + 1);
        }
        return k;
    }
}

howl_termstore_Encoded howl_termstore_encode_triples(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples) {
    {
        __auto_type p = howl_termstore_new_encoded(arena);
        {
            __auto_type _coll = triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                howl_termstore_encoded_add(arena, p, t);
            }
        }
        return (*p);
    }
}

slop_list_slop_rdf_rdf_Term howl_termstore_store_objects(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Term s, slop_rdf_rdf_Term p) {
    {
        __auto_type out = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_705 = howl_termstore_lookup_term(st, s);
        if (_mv_705.has_value) {
            __auto_type si = _mv_705.value;
            __auto_type _mv_706 = howl_termstore_lookup_term(st, p);
            if (_mv_706.has_value) {
                __auto_type pi = _mv_706.value;
                {
                    __auto_type key = ((howl_termstore_IdPair){.a = si, .b = pi});
                    __auto_type _mv_708 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_howl_termstore_Objects){ .has_value = true, .value = *(howl_termstore_Objects*)_ptr } : (slop_option_howl_termstore_Objects){ .has_value = false }; });
                    if (_mv_708.has_value) {
                        __auto_type objs = _mv_708.value;
                        __auto_type _mv_710 = ({ void* _ptr = slop_map_get(st.terms, &(int64_t){objs.first}); _ptr ? (slop_option_slop_rdf_rdf_Term){ .has_value = true, .value = *(slop_rdf_rdf_Term*)_ptr } : (slop_option_slop_rdf_rdf_Term){ .has_value = false }; });
                        if (_mv_710.has_value) {
                            __auto_type term = _mv_710.value;
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (term); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        } else if (!_mv_710.has_value) {
                        }
                        {
                            slop_map* _coll = (slop_map*)objs.more;
                            for (size_t _i = 0; _i < _coll->len; _i++) {
                                {
                                    int64_t o = *(int64_t*)slop_map_key_at(_coll, _i);
                                    __auto_type _mv_712 = ({ void* _ptr = slop_map_get(st.terms, &(int64_t){o}); _ptr ? (slop_option_slop_rdf_rdf_Term){ .has_value = true, .value = *(slop_rdf_rdf_Term*)_ptr } : (slop_option_slop_rdf_rdf_Term){ .has_value = false }; });
                                    if (_mv_712.has_value) {
                                        __auto_type term = _mv_712.value;
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (term); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_712.has_value) {
                                    }
                                }
                            }
                        }
                    } else if (!_mv_708.has_value) {
                    }
                }
            } else if (!_mv_706.has_value) {
            }
        } else if (!_mv_705.has_value) {
        }
        return out;
    }
}

int64_t howl_termstore_store_object_count(howl_termstore_TermStore st, slop_rdf_rdf_Term s, slop_rdf_rdf_Term p) {
    __auto_type _mv_713 = howl_termstore_lookup_term(st, s);
    if (_mv_713.has_value) {
        __auto_type si = _mv_713.value;
        __auto_type _mv_714 = howl_termstore_lookup_term(st, p);
        if (_mv_714.has_value) {
            __auto_type pi = _mv_714.value;
            {
                __auto_type key = ((howl_termstore_IdPair){.a = si, .b = pi});
                __auto_type _mv_716 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_howl_termstore_Objects){ .has_value = true, .value = *(howl_termstore_Objects*)_ptr } : (slop_option_howl_termstore_Objects){ .has_value = false }; });
                if (_mv_716.has_value) {
                    __auto_type objs = _mv_716.value;
                    return (1 + ((int64_t)(((int64_t)(objs.more)->len))));
                } else if (!_mv_716.has_value) {
                    return 0;
                }
                SLOP_UNREACHABLE();
            }
        } else if (!_mv_714.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_713.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_option_slop_rdf_rdf_Term howl_termstore_store_sole_object(howl_termstore_TermStore st, slop_rdf_rdf_Term s, slop_rdf_rdf_Term p) {
    __auto_type _mv_717 = howl_termstore_lookup_term(st, s);
    if (_mv_717.has_value) {
        __auto_type si = _mv_717.value;
        __auto_type _mv_718 = howl_termstore_lookup_term(st, p);
        if (_mv_718.has_value) {
            __auto_type pi = _mv_718.value;
            {
                __auto_type key = ((howl_termstore_IdPair){.a = si, .b = pi});
                __auto_type _mv_720 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_howl_termstore_Objects){ .has_value = true, .value = *(howl_termstore_Objects*)_ptr } : (slop_option_howl_termstore_Objects){ .has_value = false }; });
                if (_mv_720.has_value) {
                    __auto_type objs = _mv_720.value;
                    if (((int64_t)(objs.more)->len) == 0) {
                        return ({ void* _ptr = slop_map_get(st.terms, &(int64_t){objs.first}); _ptr ? (slop_option_slop_rdf_rdf_Term){ .has_value = true, .value = *(slop_rdf_rdf_Term*)_ptr } : (slop_option_slop_rdf_rdf_Term){ .has_value = false }; });
                    } else {
                        return (slop_option_slop_rdf_rdf_Term){.has_value = false};
                    }
                } else if (!_mv_720.has_value) {
                    return (slop_option_slop_rdf_rdf_Term){.has_value = false};
                }
                SLOP_UNREACHABLE();
            }
        } else if (!_mv_718.has_value) {
            return (slop_option_slop_rdf_rdf_Term){.has_value = false};
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_717.has_value) {
        return (slop_option_slop_rdf_rdf_Term){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

slop_list_slop_rdf_rdf_Term howl_termstore_store_typed(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Term type) {
    {
        __auto_type out = ((slop_list_slop_rdf_rdf_Term){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_722 = howl_termstore_lookup_term(st, type);
        if (_mv_722.has_value) {
            __auto_type ti = _mv_722.value;
            __auto_type _mv_724 = ({ void* _ptr = slop_map_get(st.typed, &(int64_t){ti}); _ptr ? (slop_option_map_ptr){ .has_value = true, .value = *(slop_map**)_ptr } : (slop_option_map_ptr){ .has_value = false }; });
            if (_mv_724.has_value) {
                __auto_type subs = _mv_724.value;
                {
                    slop_map* _coll = (slop_map*)subs;
                    for (size_t _i = 0; _i < _coll->len; _i++) {
                        {
                            int64_t s = *(int64_t*)slop_map_key_at(_coll, _i);
                            __auto_type _mv_726 = ({ void* _ptr = slop_map_get(st.terms, &(int64_t){s}); _ptr ? (slop_option_slop_rdf_rdf_Term){ .has_value = true, .value = *(slop_rdf_rdf_Term*)_ptr } : (slop_option_slop_rdf_rdf_Term){ .has_value = false }; });
                            if (_mv_726.has_value) {
                                __auto_type term = _mv_726.value;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (term); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else if (!_mv_726.has_value) {
                            }
                        }
                    }
                }
            } else if (!_mv_724.has_value) {
            }
        } else if (!_mv_722.has_value) {
        }
        return out;
    }
}

uint8_t howl_termstore_store_contains(howl_termstore_TermStore st, slop_rdf_rdf_Triple t) {
    __auto_type _mv_727 = howl_termstore_lookup_term(st, t.subject);
    if (!_mv_727.has_value) {
        return 0;
    } else if (_mv_727.has_value) {
        __auto_type si = _mv_727.value;
        __auto_type _mv_728 = howl_termstore_lookup_term(st, t.predicate);
        if (!_mv_728.has_value) {
            return 0;
        } else if (_mv_728.has_value) {
            __auto_type pi = _mv_728.value;
            __auto_type _mv_729 = howl_termstore_lookup_term(st, t.object);
            if (!_mv_729.has_value) {
                return 0;
            } else if (_mv_729.has_value) {
                __auto_type oi = _mv_729.value;
                {
                    __auto_type key = ((howl_termstore_IdPair){.a = si, .b = pi});
                    __auto_type _mv_731 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_howl_termstore_Objects){ .has_value = true, .value = *(howl_termstore_Objects*)_ptr } : (slop_option_howl_termstore_Objects){ .has_value = false }; });
                    if (_mv_731.has_value) {
                        __auto_type objs = _mv_731.value;
                        return ((objs.first == oi) || slop_map_has(objs.more, &(int64_t){oi}));
                    } else if (!_mv_731.has_value) {
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

uint8_t howl_termstore_store_has_any(howl_termstore_TermStore st, slop_rdf_rdf_Term s, slop_rdf_rdf_Term p) {
    __auto_type _mv_733 = howl_termstore_lookup_term(st, s);
    if (!_mv_733.has_value) {
        return 0;
    } else if (_mv_733.has_value) {
        __auto_type si = _mv_733.value;
        __auto_type _mv_734 = howl_termstore_lookup_term(st, p);
        if (!_mv_734.has_value) {
            return 0;
        } else if (_mv_734.has_value) {
            __auto_type pi = _mv_734.value;
            {
                __auto_type key = ((howl_termstore_IdPair){.a = si, .b = pi});
                __auto_type _mv_736 = ({ void* _ptr = slop_map_get(st.spo, &(key)); _ptr ? (slop_option_howl_termstore_Objects){ .has_value = true, .value = *(howl_termstore_Objects*)_ptr } : (slop_option_howl_termstore_Objects){ .has_value = false }; });
                if (_mv_736.has_value) {
                    __auto_type _ = _mv_736.value;
                    return 1;
                } else if (!_mv_736.has_value) {
                    return 0;
                }
                SLOP_UNREACHABLE();
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

