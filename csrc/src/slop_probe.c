#include "../runtime/slop_runtime.h"
#include "slop_probe.h"

int64_t howl_probe_kind_rank(howl_probe_QueryKind k);
int64_t howl_probe_query_cmp(howl_probe_Query a, howl_probe_Query b);
howl_probe_Query howl_probe_query_at(slop_list_howl_probe_Query qs, int64_t i);
slop_list_howl_probe_Query howl_probe_sort_queries(slop_arena* arena, slop_list_howl_probe_Query qs);
howl_termstore_Encoded* howl_probe_probe_document(slop_arena* arena, howl_termstore_Encoded main, howl_termstore_Encoded probes, slop_list_howl_probe_Query queries);
slop_rdf_rdf_Triple howl_probe_class_declaration(slop_arena* arena, slop_rdf_rdf_IRI c);
slop_list_howl_probe_Answered howl_probe_answer_queries(slop_arena* arena, howl_types_Outcome o, slop_list_howl_probe_Query queries);
howl_probe_ProbeAnswer howl_probe_answer_of(howl_types_Outcome o, howl_probe_Query q);
slop_rdf_rdf_IRI howl_probe_query_target(howl_probe_Query q);
slop_option_u8 howl_probe_query_holds(howl_types_Outcome o, howl_probe_Query q);
slop_option_u8 howl_probe_findings_hold(howl_types_Findings f, slop_rdf_rdf_IRI a, slop_rdf_rdf_IRI b);
uint8_t howl_probe_node_is(howl_types_Node n, slop_rdf_rdf_IRI i);
slop_option_u8 howl_probe_el_holds(howl_types_Saturation sat, howl_types_Outcome o, slop_rdf_rdf_IRI a, slop_rdf_rdf_IRI b);
uint8_t howl_probe_has_context(howl_types_Saturation sat, howl_types_Outcome o, howl_types_Node n);
slop_option_u8 howl_probe_ksc_holds(howl_types_KscResult r, slop_rdf_rdf_IRI a, slop_rdf_rdf_IRI b);

typedef struct { slop_list_howl_probe_Query qs; } howl_probe__lambda_1453_env_t;

static int64_t howl_probe__lambda_1453(howl_probe__lambda_1453_env_t* _env, int64_t i, int64_t j) { return howl_probe_query_cmp(howl_probe_query_at(_env->qs, i), howl_probe_query_at(_env->qs, j)); }

int64_t howl_probe_kind_rank(howl_probe_QueryKind k) {
    __auto_type _mv_1451 = k;
    if (_mv_1451 == howl_probe_QueryKind_query_unsatisfiable) {
        return 0;
    } else if (_mv_1451 == howl_probe_QueryKind_query_subsumed) {
        return 1;
    }
    SLOP_UNREACHABLE();
}

int64_t howl_probe_query_cmp(howl_probe_Query a, howl_probe_Query b) {
    {
        __auto_type ka = howl_probe_kind_rank(a.kind);
        __auto_type kb = howl_probe_kind_rank(b.kind);
        if (ka != kb) {
            if (ka < kb) {
                return -1;
            } else {
                return 1;
            }
        } else {
            {
                __auto_type c = howl_canon_iri_cmp(a.sub, b.sub);
                if (c != 0) {
                    return c;
                } else {
                    return howl_canon_iri_cmp(a.sup, b.sup);
                }
            }
        }
    }
}

howl_probe_Query howl_probe_query_at(slop_list_howl_probe_Query qs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    __auto_type _mv_1452 = ({ __auto_type _lst = qs; size_t _idx = (size_t)i; slop_option_howl_probe_Query _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1452.has_value) {
        __auto_type q = _mv_1452.value;
        return q;
    } else if (!_mv_1452.has_value) {
        return ((howl_probe_Query){.kind = howl_probe_QueryKind_query_unsatisfiable, .sub = ((slop_rdf_rdf_IRI){.value = SLOP_STR("")}), .sup = ((slop_rdf_rdf_IRI){.value = SLOP_STR("")})});
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_probe_Query howl_probe_sort_queries(slop_arena* arena, slop_list_howl_probe_Query qs) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((qs).len)))), ({ howl_probe__lambda_1453_env_t* howl_probe__lambda_1453_env = (howl_probe__lambda_1453_env_t*)slop_arena_alloc(arena, sizeof(howl_probe__lambda_1453_env_t)); *howl_probe__lambda_1453_env = (howl_probe__lambda_1453_env_t){ .qs = qs }; (slop_closure_t){ (void*)howl_probe__lambda_1453, (void*)howl_probe__lambda_1453_env }; }));
        __auto_type out = ((slop_list_howl_probe_Query){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type q = howl_probe_query_at(qs, k);
                    __auto_type n = ((int64_t)(((int64_t)((out).len))));
                    if ((n == 0) || (howl_probe_query_cmp(howl_probe_query_at(out, (n - 1)), q) != 0)) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (q); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

howl_termstore_Encoded* howl_probe_probe_document(slop_arena* arena, howl_termstore_Encoded main, howl_termstore_Encoded probes, slop_list_howl_probe_Query queries) {
    {
        __auto_type p = howl_termstore_new_encoded(arena);
        __auto_type base = ((int64_t)(((int64_t)((main.triples).len))));
        {
            __auto_type _coll = main.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                howl_termstore_encoded_add(arena, p, howl_termstore_triple_of(main.dict, it));
            }
        }
        {
            __auto_type e = (*p);
            __auto_type starts = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = main.starts;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type s = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(starts); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
            e.starts = starts;
            (*p) = e;
        }
        howl_termstore_encoded_next_document(arena, p);
        {
            __auto_type _coll = probes.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                howl_termstore_encoded_add(arena, p, howl_termstore_triple_of(probes.dict, it));
            }
        }
        {
            __auto_type e = (*p);
            int64_t k = 0;
            {
                __auto_type _coll = probes.starts;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type s = _coll.data[_i];
                    if (k > 0) {
                        (void)(({ __auto_type _lst_p = &(e.starts); __auto_type _item = ((base + s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                    k = (k + 1);
                }
            }
            (*p) = e;
        }
        howl_termstore_encoded_next_document(arena, p);
        {
            __auto_type _coll = queries;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                howl_termstore_encoded_add(arena, p, howl_probe_class_declaration(arena, q.sub));
                __auto_type _mv_1454 = q.kind;
                if (_mv_1454 == howl_probe_QueryKind_query_subsumed) {
                    howl_termstore_encoded_add(arena, p, howl_probe_class_declaration(arena, q.sup));
                } else if (_mv_1454 == howl_probe_QueryKind_query_unsatisfiable) {
                }
            }
        }
        return p;
    }
}

slop_rdf_rdf_Triple howl_probe_class_declaration(slop_arena* arena, slop_rdf_rdf_IRI c) {
    return rdf_make_triple(arena, rdf_make_iri(arena, c.value), rdf_make_iri(arena, slop_rdf_vocab_RDF_TYPE), rdf_make_iri(arena, slop_rdf_vocab_OWL_CLASS));
}

slop_list_howl_probe_Answered howl_probe_answer_queries(slop_arena* arena, howl_types_Outcome o, slop_list_howl_probe_Query queries) {
    {
        __auto_type out = ((slop_list_howl_probe_Answered){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = queries;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_probe_Answered){.query = ((howl_probe_Query){.kind = q.kind, .sub = howl_types_copy_iri(arena, q.sub), .sup = howl_types_copy_iri(arena, q.sup)}), .answer = howl_probe_answer_of(o, q)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_probe_ProbeAnswer howl_probe_answer_of(howl_types_Outcome o, howl_probe_Query q) {
    __auto_type _mv_1455 = howl_probe_query_holds(o, q);
    if (_mv_1455.has_value) {
        __auto_type h = _mv_1455.value;
        if (h) {
            return howl_probe_ProbeAnswer_answer_yes;
        } else if (howl_types_outcome_is_complete(o)) {
            return howl_probe_ProbeAnswer_answer_no;
        } else {
            return howl_probe_ProbeAnswer_answer_unknown;
        }
    } else if (!_mv_1455.has_value) {
        return howl_probe_ProbeAnswer_answer_unknown;
    }
    SLOP_UNREACHABLE();
}

slop_rdf_rdf_IRI howl_probe_query_target(howl_probe_Query q) {
    __auto_type _mv_1456 = q.kind;
    if (_mv_1456 == howl_probe_QueryKind_query_subsumed) {
        return q.sup;
    } else if (_mv_1456 == howl_probe_QueryKind_query_unsatisfiable) {
        return ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_NOTHING});
    }
    SLOP_UNREACHABLE();
}

slop_option_u8 howl_probe_query_holds(howl_types_Outcome o, howl_probe_Query q) {
    {
        __auto_type b = howl_probe_query_target(q);
        if (howl_canon_string_cmp(q.sub.value, slop_rdf_vocab_OWL_NOTHING) == 0) {
            return (slop_option_u8){.has_value = 1, .value = 1};
        } else if (howl_canon_string_cmp(b.value, slop_rdf_vocab_OWL_THING) == 0) {
            return (slop_option_u8){.has_value = 1, .value = 1};
        } else if (howl_canon_iri_cmp(q.sub, b) == 0) {
            return (slop_option_u8){.has_value = 1, .value = 1};
        } else {
            __auto_type _mv_1457 = o.evidence;
            switch (_mv_1457.tag) {
                case howl_types_Evidence_el_evidence:
                {
                    __auto_type sat = _mv_1457.data.el_evidence;
                    return howl_probe_el_holds(sat, o, q.sub, b);
                }
                case howl_types_Evidence_ksc_evidence:
                {
                    __auto_type r = _mv_1457.data.ksc_evidence;
                    return howl_probe_ksc_holds(r, q.sub, b);
                }
                case howl_types_Evidence_sriq_evidence:
                {
                    __auto_type _ = _mv_1457.data.sriq_evidence;
                    return howl_probe_findings_hold(o.findings, q.sub, b);
                }
            }
            SLOP_UNREACHABLE();
        }
    }
}

slop_option_u8 howl_probe_findings_hold(howl_types_Findings f, slop_rdf_rdf_IRI a, slop_rdf_rdf_IRI b) {
    {
        uint8_t has_row = 0;
        uint8_t holds = 0;
        {
            __auto_type _coll = f.unsatisfiable;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type u = _coll.data[_i];
                if (howl_canon_iri_cmp(u, a) == 0) {
                    holds = 1;
                }
            }
        }
        {
            __auto_type _coll = f.subsumptions;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                if (howl_probe_node_is(p.sub, a)) {
                    has_row = 1;
                    if (howl_probe_node_is(p.super, b)) {
                        holds = 1;
                    }
                }
            }
        }
        if (f.inconsistent) {
            return (slop_option_u8){.has_value = 1, .value = 1};
        } else if (holds) {
            return (slop_option_u8){.has_value = 1, .value = 1};
        } else if (has_row) {
            return (slop_option_u8){.has_value = 1, .value = 0};
        } else {
            return (slop_option_u8){.has_value = false};
        }
    }
}

uint8_t howl_probe_node_is(howl_types_Node n, slop_rdf_rdf_IRI i) {
    __auto_type _mv_1458 = n;
    switch (_mv_1458.tag) {
        case howl_types_Node_class_node:
        {
            __auto_type s = _mv_1458.data.class_node;
            return (howl_canon_iri_cmp(s, i) == 0);
        }
        default: {
            return 0;
        }
    }
}

slop_option_u8 howl_probe_el_holds(howl_types_Saturation sat, howl_types_Outcome o, slop_rdf_rdf_IRI a, slop_rdf_rdf_IRI b) {
    {
        __auto_type na = ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = a });
        __auto_type nb = ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = b });
        if (howl_probe_has_context(sat, o, na)) {
            return (slop_option_u8){.has_value = 1, .value = howl_classify_entails_sub(sat, o.names, o.findings.inconsistent, na, nb)};
        } else {
            if (o.findings.inconsistent) {
                return (slop_option_u8){.has_value = 1, .value = 1};
            } else {
                return (slop_option_u8){.has_value = false};
            }
        }
    }
}

uint8_t howl_probe_has_context(howl_types_Saturation sat, howl_types_Outcome o, howl_types_Node n) {
    __auto_type _mv_1459 = howl_types_renamed_node(o.names, n);
    if (!_mv_1459.has_value) {
        return 0;
    } else if (_mv_1459.has_value) {
        __auto_type r = _mv_1459.value;
        __auto_type _mv_1461 = ({ void* _ptr = slop_map_get(sat.contexts, &(r)); _ptr ? (slop_option_howl_types_Context){ .has_value = true, .value = *(howl_types_Context*)_ptr } : (slop_option_howl_types_Context){ .has_value = false }; });
        if (_mv_1461.has_value) {
            __auto_type _ = _mv_1461.value;
            return 1;
        } else if (!_mv_1461.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_option_u8 howl_probe_ksc_holds(howl_types_KscResult r, slop_rdf_rdf_IRI a, slop_rdf_rdf_IRI b) {
    {
        __auto_type ka = ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = a });
        uint8_t found = 0;
        {
            __auto_type _coll = r.answers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (howl_types_kname_eq(x.cls, ka)) {
                    found = 1;
                }
            }
        }
        if (r.inconsistent) {
            return (slop_option_u8){.has_value = 1, .value = 1};
        } else if (found) {
            return (slop_option_u8){.has_value = 1, .value = howl_classify_ksc_entails_sub(r, ka, ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = b }))};
        } else {
            return (slop_option_u8){.has_value = false};
        }
    }
}

