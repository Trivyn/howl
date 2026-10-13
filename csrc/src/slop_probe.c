#include "../runtime/slop_runtime.h"
#include "slop_probe.h"

int64_t probe_kind_rank(probe_QueryKind k);
int64_t probe_query_cmp(probe_Query a, probe_Query b);
probe_Query probe_query_at(slop_list_probe_Query qs, int64_t i);
slop_list_probe_Query probe_sort_queries(slop_arena* arena, slop_list_probe_Query qs);
termstore_Encoded* probe_probe_document(slop_arena* arena, termstore_Encoded main, termstore_Encoded probes, slop_list_probe_Query queries);
rdf_Triple probe_class_declaration(slop_arena* arena, rdf_IRI c);
slop_list_probe_Answered probe_answer_queries(slop_arena* arena, types_Outcome o, slop_list_probe_Query queries);
probe_ProbeAnswer probe_answer_of(types_Outcome o, probe_Query q);
rdf_IRI probe_query_target(probe_Query q);
slop_option_u8 probe_query_holds(types_Outcome o, probe_Query q);
slop_option_u8 probe_el_holds(types_Saturation sat, types_Outcome o, rdf_IRI a, rdf_IRI b);
uint8_t probe_has_context(types_Saturation sat, types_Outcome o, types_Node n);
slop_option_u8 probe_ksc_holds(types_KscResult r, rdf_IRI a, rdf_IRI b);

typedef struct { slop_list_probe_Query qs; } probe__lambda_929_env_t;

static int64_t probe__lambda_929(probe__lambda_929_env_t* _env, int64_t i, int64_t j) { return probe_query_cmp(probe_query_at(_env->qs, i), probe_query_at(_env->qs, j)); }

int64_t probe_kind_rank(probe_QueryKind k) {
    __auto_type _mv_927 = k;
    if (_mv_927 == probe_QueryKind_query_unsatisfiable) {
        return 0;
    } else if (_mv_927 == probe_QueryKind_query_subsumed) {
        return 1;
    }
    SLOP_UNREACHABLE();
}

int64_t probe_query_cmp(probe_Query a, probe_Query b) {
    {
        __auto_type ka = probe_kind_rank(a.kind);
        __auto_type kb = probe_kind_rank(b.kind);
        if (ka != kb) {
            if (ka < kb) {
                return -1;
            } else {
                return 1;
            }
        } else {
            {
                __auto_type c = canon_iri_cmp(a.sub, b.sub);
                if (c != 0) {
                    return c;
                } else {
                    return canon_iri_cmp(a.sup, b.sup);
                }
            }
        }
    }
}

probe_Query probe_query_at(slop_list_probe_Query qs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    __auto_type _mv_928 = ({ __auto_type _lst = qs; size_t _idx = (size_t)i; slop_option_probe_Query _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_928.has_value) {
        __auto_type q = _mv_928.value;
        return q;
    } else if (!_mv_928.has_value) {
        return ((probe_Query){.kind = probe_QueryKind_query_unsatisfiable, .sub = ((rdf_IRI){.value = SLOP_STR("")}), .sup = ((rdf_IRI){.value = SLOP_STR("")})});
    }
    SLOP_UNREACHABLE();
}

slop_list_probe_Query probe_sort_queries(slop_arena* arena, slop_list_probe_Query qs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((qs).len)))), ({ probe__lambda_929_env_t* probe__lambda_929_env = (probe__lambda_929_env_t*)slop_arena_alloc(arena, sizeof(probe__lambda_929_env_t)); *probe__lambda_929_env = (probe__lambda_929_env_t){ .qs = qs }; (slop_closure_t){ (void*)probe__lambda_929, (void*)probe__lambda_929_env }; }));
        __auto_type out = ((slop_list_probe_Query){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type q = probe_query_at(qs, k);
                    __auto_type n = ((int64_t)(((int64_t)((out).len))));
                    if ((n == 0) || (probe_query_cmp(probe_query_at(out, (n - 1)), q) != 0)) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (q); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

termstore_Encoded* probe_probe_document(slop_arena* arena, termstore_Encoded main, termstore_Encoded probes, slop_list_probe_Query queries) {
    {
        __auto_type p = termstore_new_encoded(arena);
        {
            __auto_type _coll = main.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                termstore_encoded_add(arena, p, termstore_triple_of(main.dict, it));
            }
        }
        termstore_encoded_next_document(arena, p);
        {
            __auto_type _coll = probes.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                termstore_encoded_add(arena, p, termstore_triple_of(probes.dict, it));
            }
        }
        termstore_encoded_next_document(arena, p);
        {
            __auto_type _coll = queries;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                termstore_encoded_add(arena, p, probe_class_declaration(arena, q.sub));
                __auto_type _mv_930 = q.kind;
                if (_mv_930 == probe_QueryKind_query_subsumed) {
                    termstore_encoded_add(arena, p, probe_class_declaration(arena, q.sup));
                } else if (_mv_930 == probe_QueryKind_query_unsatisfiable) {
                }
            }
        }
        return p;
    }
}

rdf_Triple probe_class_declaration(slop_arena* arena, rdf_IRI c) {
    return rdf_make_triple(arena, rdf_make_iri(arena, c.value), rdf_make_iri(arena, vocab_RDF_TYPE), rdf_make_iri(arena, vocab_OWL_CLASS));
}

slop_list_probe_Answered probe_answer_queries(slop_arena* arena, types_Outcome o, slop_list_probe_Query queries) {
    {
        __auto_type out = ((slop_list_probe_Answered){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = queries;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (((probe_Answered){.query = ((probe_Query){.kind = q.kind, .sub = types_copy_iri(arena, q.sub), .sup = types_copy_iri(arena, q.sup)}), .answer = probe_answer_of(o, q)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

probe_ProbeAnswer probe_answer_of(types_Outcome o, probe_Query q) {
    __auto_type _mv_931 = probe_query_holds(o, q);
    if (_mv_931.has_value) {
        __auto_type h = _mv_931.value;
        if (h) {
            return probe_ProbeAnswer_answer_yes;
        } else if (types_outcome_is_complete(o)) {
            return probe_ProbeAnswer_answer_no;
        } else {
            return probe_ProbeAnswer_answer_unknown;
        }
    } else if (!_mv_931.has_value) {
        return probe_ProbeAnswer_answer_unknown;
    }
    SLOP_UNREACHABLE();
}

rdf_IRI probe_query_target(probe_Query q) {
    __auto_type _mv_932 = q.kind;
    if (_mv_932 == probe_QueryKind_query_subsumed) {
        return q.sup;
    } else if (_mv_932 == probe_QueryKind_query_unsatisfiable) {
        return ((rdf_IRI){.value = vocab_OWL_NOTHING});
    }
    SLOP_UNREACHABLE();
}

slop_option_u8 probe_query_holds(types_Outcome o, probe_Query q) {
    {
        __auto_type b = probe_query_target(q);
        if (canon_string_cmp(q.sub.value, vocab_OWL_NOTHING) == 0) {
            return (slop_option_u8){.has_value = 1, .value = 1};
        } else if (canon_string_cmp(b.value, vocab_OWL_THING) == 0) {
            return (slop_option_u8){.has_value = 1, .value = 1};
        } else if (canon_iri_cmp(q.sub, b) == 0) {
            return (slop_option_u8){.has_value = 1, .value = 1};
        } else {
            __auto_type _mv_933 = o.evidence;
            switch (_mv_933.tag) {
                case types_Evidence_el_evidence:
                {
                    __auto_type sat = _mv_933.data.el_evidence;
                    return probe_el_holds(sat, o, q.sub, b);
                }
                case types_Evidence_ksc_evidence:
                {
                    __auto_type r = _mv_933.data.ksc_evidence;
                    return probe_ksc_holds(r, q.sub, b);
                }
            }
            SLOP_UNREACHABLE();
        }
    }
}

slop_option_u8 probe_el_holds(types_Saturation sat, types_Outcome o, rdf_IRI a, rdf_IRI b) {
    {
        __auto_type na = ((types_Node){ .tag = types_Node_class_node, .data.class_node = a });
        __auto_type nb = ((types_Node){ .tag = types_Node_class_node, .data.class_node = b });
        if (probe_has_context(sat, o, na)) {
            return (slop_option_u8){.has_value = 1, .value = classify_entails_sub(sat, o.names, o.findings.inconsistent, na, nb)};
        } else {
            if (o.findings.inconsistent) {
                return (slop_option_u8){.has_value = 1, .value = 1};
            } else {
                return (slop_option_u8){.has_value = false};
            }
        }
    }
}

uint8_t probe_has_context(types_Saturation sat, types_Outcome o, types_Node n) {
    __auto_type _mv_934 = types_renamed_node(o.names, n);
    if (!_mv_934.has_value) {
        return 0;
    } else if (_mv_934.has_value) {
        __auto_type r = _mv_934.value;
        __auto_type _mv_936 = ({ void* _ptr = slop_map_get(sat.contexts, &(r)); _ptr ? (slop_option_types_Context){ .has_value = true, .value = *(types_Context*)_ptr } : (slop_option_types_Context){ .has_value = false }; });
        if (_mv_936.has_value) {
            __auto_type _ = _mv_936.value;
            return 1;
        } else if (!_mv_936.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_option_u8 probe_ksc_holds(types_KscResult r, rdf_IRI a, rdf_IRI b) {
    {
        __auto_type ka = ((types_KName){ .tag = types_KName_k_class, .data.k_class = a });
        uint8_t found = 0;
        {
            __auto_type _coll = r.answers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (types_kname_eq(x.cls, ka)) {
                    found = 1;
                }
            }
        }
        if (r.inconsistent) {
            return (slop_option_u8){.has_value = 1, .value = 1};
        } else if (found) {
            return (slop_option_u8){.has_value = 1, .value = classify_ksc_entails_sub(r, ka, ((types_KName){ .tag = types_KName_k_class, .data.k_class = b }))};
        } else {
            return (slop_option_u8){.has_value = false};
        }
    }
}

