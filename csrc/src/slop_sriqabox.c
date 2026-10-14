#include "../runtime/slop_runtime.h"
#include "slop_sriqabox.h"

slop_option_rdf_IRI sriqabox_individual_of(types_Node n);
void sriqabox_put_node(slop_map* s, types_Node n);
slop_map* sriqabox_unfoldable(slop_arena* arena, slop_list_owl2_RawAxiom axs);
slop_list_rdf_IRI sriqabox_different_bad(slop_arena* arena, slop_list_types_Node ns);
slop_list_rdf_IRI sriqabox_repeated(slop_arena* arena, slop_list_types_Node ns);
slop_option_rdf_IRI sriqabox_foldable_subject(owl2_RawClassAssertion ca, slop_map* bad);
slop_list_sriqabox_Typed sriqabox_typed_pairs(slop_arena* arena, slop_list_owl2_RawAxiom axs, slop_map* bad);
slop_option_sriqabox_Typed sriqabox_typed_of(owl2_RawAxiom ax, slop_map* bad);
sriqabox_Typed sriqabox_typed_at(slop_list_sriqabox_Typed xs, int64_t k, sriqabox_Typed fallback);
int64_t sriqabox_typed_cmp(sriqabox_Typed a, sriqabox_Typed b);
slop_list_sriqabox_Typing sriqabox_typings(slop_arena* arena, slop_list_sriqabox_Typed pairs);
slop_list_sriqabox_Typed sriqabox_sorted_typed(slop_arena* arena, slop_list_sriqabox_Typed pairs, sriqabox_Typed p0);
slop_list_sriqabox_Typing sriqabox_typings_sorted(slop_arena* arena, slop_list_sriqabox_Typed ps, sriqabox_Typed p0);
int64_t sriqabox_run_end(slop_list_sriqabox_Typed ps, int64_t k, sriqabox_Typed p0);
slop_list_owl2_RawConcept sriqabox_run_types(slop_arena* arena, slop_list_sriqabox_Typed ps, int64_t k, int64_t end, sriqabox_Typed p0);
uint8_t sriqabox_ends_with(slop_list_owl2_RawConcept cs, owl2_RawConcept c);
int64_t sriqabox_types_cmp(slop_list_owl2_RawConcept a, slop_list_owl2_RawConcept b);
sriqabox_Typing sriqabox_typing_at(slop_list_sriqabox_Typing xs, int64_t k, sriqabox_Typing fallback);
slop_map* sriqabox_representatives(slop_arena* arena, slop_list_sriqabox_Typing ts);
int64_t sriqabox_typing_cmp(sriqabox_Typing a, sriqabox_Typing b);
slop_list_sriqabox_Typing sriqabox_sorted_typings(slop_arena* arena, slop_list_sriqabox_Typing ts, sriqabox_Typing t0);
slop_map* sriqabox_first_of_each(slop_arena* arena, slop_list_sriqabox_Typing ts);
uint8_t sriqabox_h_keeps(owl2_RawAxiom ax, slop_map* reps);
slop_option_owl2_RawAxiom sriqabox_c_axiom(slop_arena* arena, owl2_RawAxiom ax, slop_map* bad);
slop_list_types_Node sriqabox_unfoldable_nodes(slop_arena* arena, slop_list_types_Node ns, slop_map* bad);
uint8_t sriqabox_is_assertion(owl2_RawAxiom ax);
owl2_Signature sriqabox_with_individuals(owl2_Signature sig, slop_map* inds);
sriqabox_Split sriqabox_abox_split(slop_arena* arena, gate_GateResult gr);
slop_result_sriqabox_Folded_string sriqabox_fold_clauses(slop_arena* arena, sriqnames_SriqNormal n);
slop_list_u32 sriqabox_hidden_ids(slop_arena* arena, sriqclauses_SriqClauses sc, slop_list_types_DName names);
uint32_t sriqabox_u32_at(slop_list_u32 xs, int64_t k);
int64_t sriqabox_u32_cmp(uint32_t a, uint32_t b);
sriqref_RefIn sriqabox_h_input(slop_arena* arena, sriqabox_Folded f);
sriqref_RefIn sriqabox_consistency_input(sriqref_RefIn in);
slop_result_sriqabox_Inputs_string sriqabox_split_inputs(slop_arena* arena, gate_GateResult gr);
slop_result_sriqabox_Inputs_string sriqabox_split_inputs_bounded(slop_arena* arena, gate_GateResult gr, int64_t bound);
slop_result_sriqabox_Inputs_string sriqabox_inputs_from(slop_arena* arena, sriqabox_Split sp, sriqabox_Folded f, slop_list_owl2_RawAxiom omitted, int64_t bound);
slop_result_sriqabox_Inputs_string sriqabox_c_inputs(slop_arena* arena, sriqabox_Split sp, sriqclauses_SriqIds ids, sriqref_RefIn h, slop_list_owl2_RawAxiom omitted, int64_t bound);
slop_list_owl2_RawAxiom sriqabox_both_omitted(slop_arena* arena, slop_list_owl2_RawAxiom a, slop_list_owl2_RawAxiom b);
uint8_t sriqabox_finished(sriqref_RefStatus s);
sriqabox_SplitRun sriqabox_split_run(slop_arena* arena, sriqabox_Inputs in, sriqsat_SatConfig cfg);
sriqabox_SplitRun sriqabox_split_run_of(slop_arena* arena, sriqref_RefIn h_in, sriqref_RefIn c_in, uint8_t has_c, uint8_t omitted, sriqsat_SatConfig cfg);
sriqabox_SplitRun sriqabox_c_run(slop_arena* arena, sriqsat_SatResult h, uint8_t hdone, sriqref_RefIn c_in, uint8_t omitted, sriqsat_SatConfig cfg);
sriqsat_SatConfig sriqabox_with_fuel(sriqsat_SatConfig cfg, int64_t fuel);
sriqsat_SatConfig sriqabox_sriq_config(int64_t max_rounds, int64_t budget, int64_t cancel);
types_Findings sriqabox_split_findings(slop_arena* arena, sriqctx_Structure st, slop_list_rdf_IRI classes, uint8_t inconsistent);
slop_list_types_Clause sriqabox_set_at_ctx(slop_arena* arena, sriqctx_Structure st, int64_t v);
uint8_t sriqabox_body_within(types_Clause c, int64_t b);
uint8_t sriqabox_is_x_atom(types_Lit l, int64_t b);
int64_t sriqabox_head_class(types_Clause c, int64_t n);
uint8_t sriqabox_unsat_at(slop_arena* arena, sriqctx_Structure st, int64_t b);
slop_list_rdf_IRI sriqabox_unsat_classes(slop_arena* arena, sriqctx_Structure st, slop_list_rdf_IRI classes);
slop_list_types_SubPair sriqabox_taxonomy(slop_arena* arena, sriqctx_Structure st, slop_list_rdf_IRI classes);
slop_list_types_SubPair sriqabox_class_rows(slop_arena* arena, sriqctx_Structure st, slop_list_rdf_IRI classes, int64_t b, int64_t n);
slop_list_int sriqabox_holds_in(slop_arena* arena, sriqctx_Structure st, int64_t v, int64_t b, int64_t n);
types_Node sriqabox_class_at(slop_list_rdf_IRI classes, int64_t a);
slop_list_types_SubPair sriqabox_distinct_pairs(slop_arena* arena, slop_list_types_SubPair ps);

typedef struct { slop_list_sriqabox_Typed pairs; sriqabox_Typed p0; } sriqabox__lambda_1512_env_t;

static int64_t sriqabox__lambda_1512(sriqabox__lambda_1512_env_t* _env, int64_t i, int64_t j) { return sriqabox_typed_cmp(sriqabox_typed_at(_env->pairs, i, _env->p0), sriqabox_typed_at(_env->pairs, j, _env->p0)); }

typedef struct { slop_list_sriqabox_Typing ts; sriqabox_Typing t0; } sriqabox__lambda_1517_env_t;

static int64_t sriqabox__lambda_1517(sriqabox__lambda_1517_env_t* _env, int64_t i, int64_t j) { return sriqabox_typing_cmp(sriqabox_typing_at(_env->ts, i, _env->t0), sriqabox_typing_at(_env->ts, j, _env->t0)); }

typedef struct { slop_list_u32* raw; } sriqabox__lambda_1530_env_t;

static int64_t sriqabox__lambda_1530(sriqabox__lambda_1530_env_t* _env, int64_t i, int64_t j) { return sriqabox_u32_cmp(sriqabox_u32_at((*_env->raw), i), sriqabox_u32_at((*_env->raw), j)); }

slop_option_rdf_IRI sriqabox_individual_of(types_Node n) {
    __auto_type _mv_1496 = n;
    switch (_mv_1496.tag) {
        case types_Node_individual_node:
        {
            __auto_type i = _mv_1496.data.individual_node;
            return (slop_option_rdf_IRI){.has_value = 1, .value = i};
        }
        case types_Node_class_node:
        {
            __auto_type _ = _mv_1496.data.class_node;
            return (slop_option_rdf_IRI){.has_value = false};
        }
        case types_Node_fresh_node:
        {
            __auto_type _ = _mv_1496.data.fresh_node;
            return (slop_option_rdf_IRI){.has_value = false};
        }
    }
    SLOP_UNREACHABLE();
}

void sriqabox_put_node(slop_map* s, types_Node n) {
    __auto_type _mv_1497 = sriqabox_individual_of(n);
    if (_mv_1497.has_value) {
        __auto_type i = _mv_1497.value;
        ({ slop_map_put(NULL, s, &(i), NULL, 0); });
    } else if (!_mv_1497.has_value) {
    }
}

slop_map* sriqabox_unfoldable(slop_arena* arena, slop_list_owl2_RawAxiom axs) {
    {
        __auto_type bad = ({ static const slop_map_desc _d = SLOP_SET_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1499 = ax;
                switch (_mv_1499.tag) {
                    case owl2_RawAxiom_ra_object_property_assertion:
                    {
                        __auto_type e = _mv_1499.data.ra_object_property_assertion;
                        sriqabox_put_node(bad, e.from);
                        sriqabox_put_node(bad, e.to);
                        break;
                    }
                    case owl2_RawAxiom_ra_negative_assertion:
                    {
                        __auto_type e = _mv_1499.data.ra_negative_assertion;
                        sriqabox_put_node(bad, e.from);
                        sriqabox_put_node(bad, e.to);
                        break;
                    }
                    case owl2_RawAxiom_ra_same_individual:
                    {
                        __auto_type ns = _mv_1499.data.ra_same_individual;
                        {
                            __auto_type _coll = ns;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type n = _coll.data[_i];
                                sriqabox_put_node(bad, n);
                            }
                        }
                        break;
                    }
                    case owl2_RawAxiom_ra_different_individuals:
                    {
                        __auto_type ns = _mv_1499.data.ra_different_individuals;
                        {
                            __auto_type _coll = sriqabox_different_bad(arena, ns);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type i = _coll.data[_i];
                                ({ slop_map_put(NULL, bad, &(i), NULL, 0); });
                            }
                        }
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        return bad;
    }
}

slop_list_rdf_IRI sriqabox_different_bad(slop_arena* arena, slop_list_types_Node ns) {
    {
        uint8_t odd = 0;
        __auto_type all = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                __auto_type _mv_1501 = sriqabox_individual_of(n);
                if (_mv_1501.has_value) {
                    __auto_type i = _mv_1501.value;
                    ({ __auto_type _lst_p = &(all); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1501.has_value) {
                    odd = 1;
                }
            }
        }
        if (odd) {
            return all;
        } else {
            return sriqabox_repeated(arena, ns);
        }
    }
}

slop_list_rdf_IRI sriqabox_repeated(slop_arena* arena, slop_list_types_Node ns) {
    {
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type out = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                __auto_type _mv_1502 = sriqabox_individual_of(n);
                if (_mv_1502.has_value) {
                    __auto_type i = _mv_1502.value;
                    if (slop_map_has(seen, &(i))) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else {
                        ({ slop_map_put(NULL, seen, &(i), NULL, 0); });
                    }
                } else if (!_mv_1502.has_value) {
                }
            }
        }
        return out;
    }
}

slop_option_rdf_IRI sriqabox_foldable_subject(owl2_RawClassAssertion ca, slop_map* bad) {
    __auto_type _mv_1505 = sriqabox_individual_of(ca.subject);
    if (_mv_1505.has_value) {
        __auto_type i = _mv_1505.value;
        if (slop_map_has(bad, &(i))) {
            return (slop_option_rdf_IRI){.has_value = false};
        } else {
            return (slop_option_rdf_IRI){.has_value = 1, .value = i};
        }
    } else if (!_mv_1505.has_value) {
        return (slop_option_rdf_IRI){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

slop_list_sriqabox_Typed sriqabox_typed_pairs(slop_arena* arena, slop_list_owl2_RawAxiom axs, slop_map* bad) {
    {
        __auto_type out = ((slop_list_sriqabox_Typed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1507 = sriqabox_typed_of(ax, bad);
                if (_mv_1507.has_value) {
                    __auto_type t = _mv_1507.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1507.has_value) {
                }
            }
        }
        return out;
    }
}

slop_option_sriqabox_Typed sriqabox_typed_of(owl2_RawAxiom ax, slop_map* bad) {
    __auto_type _mv_1508 = ax;
    switch (_mv_1508.tag) {
        case owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_1508.data.ra_class_assertion;
            __auto_type _mv_1509 = sriqabox_foldable_subject(ca, bad);
            if (_mv_1509.has_value) {
                __auto_type i = _mv_1509.value;
                return (slop_option_sriqabox_Typed){.has_value = 1, .value = ((sriqabox_Typed){.ind = i, .c = (*ca.concept)})};
            } else if (!_mv_1509.has_value) {
                return (slop_option_sriqabox_Typed){.has_value = false};
            }
            SLOP_UNREACHABLE();
        }
        default: {
            return (slop_option_sriqabox_Typed){.has_value = false};
        }
    }
}

sriqabox_Typed sriqabox_typed_at(slop_list_sriqabox_Typed xs, int64_t k, sriqabox_Typed fallback) {
    __auto_type _mv_1510 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_sriqabox_Typed _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1510.has_value) {
        __auto_type x = _mv_1510.value;
        return x;
    } else if (!_mv_1510.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

int64_t sriqabox_typed_cmp(sriqabox_Typed a, sriqabox_Typed b) {
    {
        __auto_type r = canon_iri_cmp(a.ind, b.ind);
        if (r != 0) {
            return r;
        } else {
            return owl2_concept_cmp(a.c, b.c);
        }
    }
}

slop_list_sriqabox_Typing sriqabox_typings(slop_arena* arena, slop_list_sriqabox_Typed pairs) {
    __auto_type _mv_1511 = ({ __auto_type _lst = pairs; size_t _idx = (size_t)0; slop_option_sriqabox_Typed _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1511.has_value) {
        return ((slop_list_sriqabox_Typing){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    } else if (_mv_1511.has_value) {
        __auto_type p0 = _mv_1511.value;
        return sriqabox_typings_sorted(arena, sriqabox_sorted_typed(arena, pairs, p0), p0);
    }
    SLOP_UNREACHABLE();
}

slop_list_sriqabox_Typed sriqabox_sorted_typed(slop_arena* arena, slop_list_sriqabox_Typed pairs, sriqabox_Typed p0) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((pairs).len)))), ({ sriqabox__lambda_1512_env_t* sriqabox__lambda_1512_env = (sriqabox__lambda_1512_env_t*)slop_arena_alloc(arena, sizeof(sriqabox__lambda_1512_env_t)); *sriqabox__lambda_1512_env = (sriqabox__lambda_1512_env_t){ .pairs = pairs, .p0 = p0 }; (slop_closure_t){ (void*)sriqabox__lambda_1512, (void*)sriqabox__lambda_1512_env }; }));
        __auto_type out = ((slop_list_sriqabox_Typed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqabox_typed_at(pairs, k, p0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_sriqabox_Typing sriqabox_typings_sorted(slop_arena* arena, slop_list_sriqabox_Typed ps, sriqabox_Typed p0) {
    {
        __auto_type out = ((slop_list_sriqabox_Typing){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        __auto_type n = ((int64_t)(((int64_t)((ps).len))));
        while (k < n) {
            {
                __auto_type ind = sriqabox_typed_at(ps, k, p0).ind;
                __auto_type end = sriqabox_run_end(ps, k, p0);
                ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqabox_Typing){.ind = ind, .types = sriqabox_run_types(arena, ps, k, end, p0)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                k = end;
            }
        }
        return out;
    }
}

int64_t sriqabox_run_end(slop_list_sriqabox_Typed ps, int64_t k, sriqabox_Typed p0) {
    {
        __auto_type ind = sriqabox_typed_at(ps, k, p0).ind;
        int64_t e = k;
        while ((e < ((int64_t)(((int64_t)((ps).len))))) && (canon_iri_cmp(sriqabox_typed_at(ps, e, p0).ind, ind) == 0)) {
            e = (e + 1);
        }
        return e;
    }
}

slop_list_owl2_RawConcept sriqabox_run_types(slop_arena* arena, slop_list_sriqabox_Typed ps, int64_t k, int64_t end, sriqabox_Typed p0) {
    {
        __auto_type cur = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = k;
        while (i < end) {
            if (!(sriqabox_ends_with(cur, sriqabox_typed_at(ps, i, p0).c))) {
                ({ __auto_type _lst_p = &(cur); __auto_type _item = (sriqabox_typed_at(ps, i, p0).c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
            i = (i + 1);
        }
        return cur;
    }
}

uint8_t sriqabox_ends_with(slop_list_owl2_RawConcept cs, owl2_RawConcept c) {
    __auto_type _mv_1513 = ({ __auto_type _lst = cs; size_t _idx = (size_t)(((int64_t)(((int64_t)((cs).len)))) - 1); slop_option_owl2_RawConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1513.has_value) {
        __auto_type x = _mv_1513.value;
        return (owl2_concept_cmp(x, c) == 0);
    } else if (!_mv_1513.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

int64_t sriqabox_types_cmp(slop_list_owl2_RawConcept a, slop_list_owl2_RawConcept b) {
    {
        int64_t r = 0;
        int64_t i = 0;
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (r == 0) {
                    __auto_type _mv_1514 = ({ __auto_type _lst = b; size_t _idx = (size_t)i; slop_option_owl2_RawConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_1514.has_value) {
                        __auto_type y = _mv_1514.value;
                        r = owl2_concept_cmp(x, y);
                    } else if (!_mv_1514.has_value) {
                        r = 1;
                    }
                }
                i = (i + 1);
            }
        }
        if ((r == 0) && (((int64_t)((a).len)) < ((int64_t)((b).len)))) {
            return -1;
        } else {
            return r;
        }
    }
}

sriqabox_Typing sriqabox_typing_at(slop_list_sriqabox_Typing xs, int64_t k, sriqabox_Typing fallback) {
    __auto_type _mv_1515 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_sriqabox_Typing _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1515.has_value) {
        __auto_type x = _mv_1515.value;
        return x;
    } else if (!_mv_1515.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_map* sriqabox_representatives(slop_arena* arena, slop_list_sriqabox_Typing ts) {
    __auto_type _mv_1516 = ({ __auto_type _lst = ts; size_t _idx = (size_t)0; slop_option_sriqabox_Typing _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1516.has_value) {
        return ({ static const slop_map_desc _d = SLOP_SET_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
    } else if (_mv_1516.has_value) {
        __auto_type t0 = _mv_1516.value;
        return sriqabox_first_of_each(arena, sriqabox_sorted_typings(arena, ts, t0));
    }
    SLOP_UNREACHABLE();
}

int64_t sriqabox_typing_cmp(sriqabox_Typing a, sriqabox_Typing b) {
    {
        __auto_type r = sriqabox_types_cmp(a.types, b.types);
        if (r != 0) {
            return r;
        } else {
            return canon_iri_cmp(a.ind, b.ind);
        }
    }
}

slop_list_sriqabox_Typing sriqabox_sorted_typings(slop_arena* arena, slop_list_sriqabox_Typing ts, sriqabox_Typing t0) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((ts).len)))), ({ sriqabox__lambda_1517_env_t* sriqabox__lambda_1517_env = (sriqabox__lambda_1517_env_t*)slop_arena_alloc(arena, sizeof(sriqabox__lambda_1517_env_t)); *sriqabox__lambda_1517_env = (sriqabox__lambda_1517_env_t){ .ts = ts, .t0 = t0 }; (slop_closure_t){ (void*)sriqabox__lambda_1517, (void*)sriqabox__lambda_1517_env }; }));
        __auto_type out = ((slop_list_sriqabox_Typing){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqabox_typing_at(ts, k, t0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_map* sriqabox_first_of_each(slop_arena* arena, slop_list_sriqabox_Typing ts) {
    {
        __auto_type reps = ({ static const slop_map_desc _d = SLOP_SET_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type prev = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t started = 0;
        {
            __auto_type _coll = ts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (!(started) || (sriqabox_types_cmp(prev, t.types) != 0)) {
                    {
                        __auto_type i = t.ind;
                        ({ slop_map_put(NULL, reps, &(i), NULL, 0); });
                        prev = t.types;
                        started = 1;
                    }
                }
            }
        }
        return reps;
    }
}

uint8_t sriqabox_h_keeps(owl2_RawAxiom ax, slop_map* reps) {
    __auto_type _mv_1519 = ax;
    switch (_mv_1519.tag) {
        case owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_1519.data.ra_class_assertion;
            __auto_type _mv_1520 = sriqabox_individual_of(ca.subject);
            if (_mv_1520.has_value) {
                __auto_type i = _mv_1520.value;
                return slop_map_has(reps, &(i));
            } else if (!_mv_1520.has_value) {
                return 0;
            }
            SLOP_UNREACHABLE();
        }
        case owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type _ = _mv_1519.data.ra_object_property_assertion;
            return 0;
        }
        case owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type _ = _mv_1519.data.ra_negative_assertion;
            return 0;
        }
        case owl2_RawAxiom_ra_same_individual:
        {
            __auto_type _ = _mv_1519.data.ra_same_individual;
            return 0;
        }
        case owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type _ = _mv_1519.data.ra_different_individuals;
            return 0;
        }
        default: {
            return 1;
        }
    }
}

slop_option_owl2_RawAxiom sriqabox_c_axiom(slop_arena* arena, owl2_RawAxiom ax, slop_map* bad) {
    __auto_type _mv_1522 = ax;
    switch (_mv_1522.tag) {
        case owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_1522.data.ra_class_assertion;
            __auto_type _mv_1523 = sriqabox_foldable_subject(ca, bad);
            if (_mv_1523.has_value) {
                __auto_type _ = _mv_1523.value;
                return (slop_option_owl2_RawAxiom){.has_value = false};
            } else if (!_mv_1523.has_value) {
                return (slop_option_owl2_RawAxiom){.has_value = 1, .value = ax};
            }
            SLOP_UNREACHABLE();
        }
        case owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type ns = _mv_1522.data.ra_different_individuals;
            {
                __auto_type kept = sriqabox_unfoldable_nodes(arena, ns, bad);
                if (((int64_t)((kept).len)) >= 2) {
                    return (slop_option_owl2_RawAxiom){.has_value = 1, .value = ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_different_individuals, .data.ra_different_individuals = kept })};
                } else {
                    return (slop_option_owl2_RawAxiom){.has_value = false};
                }
            }
        }
        default: {
            return (slop_option_owl2_RawAxiom){.has_value = 1, .value = ax};
        }
    }
}

slop_list_types_Node sriqabox_unfoldable_nodes(slop_arena* arena, slop_list_types_Node ns, slop_map* bad) {
    {
        __auto_type out = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                __auto_type _mv_1524 = sriqabox_individual_of(n);
                if (_mv_1524.has_value) {
                    __auto_type i = _mv_1524.value;
                    if (slop_map_has(bad, &(i))) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                } else if (!_mv_1524.has_value) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

uint8_t sriqabox_is_assertion(owl2_RawAxiom ax) {
    __auto_type _mv_1526 = ax;
    switch (_mv_1526.tag) {
        case owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type _ = _mv_1526.data.ra_class_assertion;
            return 1;
        }
        case owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type _ = _mv_1526.data.ra_object_property_assertion;
            return 1;
        }
        case owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type _ = _mv_1526.data.ra_negative_assertion;
            return 1;
        }
        case owl2_RawAxiom_ra_same_individual:
        {
            __auto_type _ = _mv_1526.data.ra_same_individual;
            return 1;
        }
        case owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type _ = _mv_1526.data.ra_different_individuals;
            return 1;
        }
        default: {
            return 0;
        }
    }
}

owl2_Signature sriqabox_with_individuals(owl2_Signature sig, slop_map* inds) {
    return ((owl2_Signature){.classes = sig.classes, .obj_props = sig.obj_props, .data_props = sig.data_props, .annot_props = sig.annot_props, .individuals = inds, .datatypes = sig.datatypes});
}

sriqabox_Split sriqabox_abox_split(slop_arena* arena, gate_GateResult gr) {
    {
        __auto_type bad = sriqabox_unfoldable(arena, gr.accepted);
        __auto_type reps = sriqabox_representatives(arena, sriqabox_typings(arena, sriqabox_typed_pairs(arena, gr.accepted, bad)));
        __auto_type hs = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type cs = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t rest = 0;
        {
            __auto_type _coll = gr.accepted;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                if (sriqabox_h_keeps(ax, reps)) {
                    ({ __auto_type _lst_p = &(hs); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                __auto_type _mv_1527 = sriqabox_c_axiom(arena, ax, bad);
                if (_mv_1527.has_value) {
                    __auto_type x = _mv_1527.value;
                    ({ __auto_type _lst_p = &(cs); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    if (sriqabox_is_assertion(x)) {
                        rest = 1;
                    }
                } else if (!_mv_1527.has_value) {
                }
            }
        }
        return ((sriqabox_Split){.h = ((gate_GateResult){.accepted = hs, .omissions = gr.omissions, .signature = sriqabox_with_individuals(gr.signature, ({ static const slop_map_desc _d = SLOP_SET_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }))}), .c = ((gate_GateResult){.accepted = cs, .omissions = gr.omissions, .signature = sriqabox_with_individuals(gr.signature, bad)}), .has_c = rest});
    }
}

slop_result_sriqabox_Folded_string sriqabox_fold_clauses(slop_arena* arena, sriqnames_SriqNormal n) {
    {
        __auto_type kept = ((slop_list_types_DlClause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type names = ((slop_list_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t dl11 = 0;
        {
            __auto_type _coll = n.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                __auto_type _mv_1528 = c;
                switch (_mv_1528.tag) {
                    case types_DlClause_dl10:
                    {
                        __auto_type a = _mv_1528.data.dl10.f1;
                        ({ __auto_type _lst_p = &(names); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case types_DlClause_dl11:
                    {
                        dl11 = 1;
                        break;
                    }
                    default: {
                        ({ __auto_type _lst_p = &(kept); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                }
            }
        }
        if (dl11) {
            return ((slop_result_sriqabox_Folded_string){ .is_ok = false, .data.err = SLOP_STR("Run H holds a DL11 clause, so a positive nominal") });
        } else {
            __auto_type _mv_1529 = sriqclauses_sriq_clauses(arena, ((sriqnames_SriqNormal){.clauses = kept, .concepts = n.concepts, .sroles = n.sroles, .sfills = n.sfills, .bars = n.bars, .fns = n.fns, .classes = n.classes, .individuals = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .omitted = n.omitted}));
            if (!_mv_1529.is_ok) {
                __auto_type m = _mv_1529.data.err;
                return ((slop_result_sriqabox_Folded_string){ .is_ok = false, .data.err = m });
            } else if (_mv_1529.is_ok) {
                __auto_type sc = _mv_1529.data.ok;
                return ((slop_result_sriqabox_Folded_string){ .is_ok = true, .data.ok = ((sriqabox_Folded){.sc = sc, .hidden = sriqabox_hidden_ids(arena, sc, names)}) });
            }
            SLOP_UNREACHABLE();
        }
    }
}

slop_list_u32 sriqabox_hidden_ids(slop_arena* arena, sriqclauses_SriqClauses sc, slop_list_types_DName names) {
    {
        __auto_type raw = ((slop_list_u32){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type out = ((slop_list_u32){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = names;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(raw); __auto_type _item = (sriqclauses_class_id(sc.ids, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ sriqabox__lambda_1530_env_t* sriqabox__lambda_1530_env = (sriqabox__lambda_1530_env_t*)slop_arena_alloc(arena, sizeof(sriqabox__lambda_1530_env_t)); *sriqabox__lambda_1530_env = (sriqabox__lambda_1530_env_t){ .raw = &(raw) }; (slop_closure_t){ (void*)sriqabox__lambda_1530, (void*)sriqabox__lambda_1530_env }; }));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type v = sriqabox_u32_at(raw, k);
                    __auto_type _mv_1531 = ({ __auto_type _lst = out; size_t _idx = (size_t)(((int64_t)(((int64_t)((out).len)))) - 1); slop_option_u32 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_1531.has_value) {
                        __auto_type last = _mv_1531.value;
                        if (last != v) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    } else if (!_mv_1531.has_value) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

uint32_t sriqabox_u32_at(slop_list_u32 xs, int64_t k) {
    __auto_type _mv_1532 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_u32 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1532.has_value) {
        __auto_type x = _mv_1532.value;
        return x;
    } else if (!_mv_1532.has_value) {
        return ((uint32_t)(0));
    }
    SLOP_UNREACHABLE();
}

int64_t sriqabox_u32_cmp(uint32_t a, uint32_t b) {
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    } else {
        return 0;
    }
}

sriqref_RefIn sriqabox_h_input(slop_arena* arena, sriqabox_Folded f) {
    {
        __auto_type in = sriqref_ref_input(arena, f.sc);
        return ((sriqref_RefIn){.onto = in.onto, .nclass = in.nclass, .nquery = in.nquery, .nrole = in.nrole, .nfn = in.nfn, .nconst = in.nconst, .hidden = f.hidden});
    }
}

sriqref_RefIn sriqabox_consistency_input(sriqref_RefIn in) {
    return ((sriqref_RefIn){.onto = in.onto, .nclass = in.nclass, .nquery = 0, .nrole = in.nrole, .nfn = in.nfn, .nconst = in.nconst, .hidden = in.hidden});
}

slop_result_sriqabox_Inputs_string sriqabox_split_inputs(slop_arena* arena, gate_GateResult gr) {
    return sriqabox_split_inputs_bounded(arena, gr, sriqelim_S1_BOUND);
}

slop_result_sriqabox_Inputs_string sriqabox_split_inputs_bounded(slop_arena* arena, gate_GateResult gr, int64_t bound) {
    {
        __auto_type sp = sriqabox_abox_split(arena, gr);
        __auto_type _mv_1533 = sriqnames_sriq_normalize_bounded(arena, sp.h.accepted, sp.h.signature, bound);
        if (!_mv_1533.is_ok) {
            __auto_type m = _mv_1533.data.err;
            return ((slop_result_sriqabox_Inputs_string){ .is_ok = false, .data.err = m });
        } else if (_mv_1533.is_ok) {
            __auto_type nh = _mv_1533.data.ok;
            __auto_type _mv_1534 = sriqabox_fold_clauses(arena, nh);
            if (!_mv_1534.is_ok) {
                __auto_type m = _mv_1534.data.err;
                return ((slop_result_sriqabox_Inputs_string){ .is_ok = false, .data.err = m });
            } else if (_mv_1534.is_ok) {
                __auto_type f = _mv_1534.data.ok;
                return sriqabox_inputs_from(arena, sp, f, nh.omitted, bound);
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

slop_result_sriqabox_Inputs_string sriqabox_inputs_from(slop_arena* arena, sriqabox_Split sp, sriqabox_Folded f, slop_list_owl2_RawAxiom omitted, int64_t bound) {
    {
        __auto_type h = sriqabox_h_input(arena, f);
        if (sp.has_c) {
            return sriqabox_c_inputs(arena, sp, f.sc.ids, h, omitted, bound);
        } else {
            return ((slop_result_sriqabox_Inputs_string){ .is_ok = true, .data.ok = ((sriqabox_Inputs){.ids = f.sc.ids, .h = h, .c = h, .has_c = 0, .omitted = omitted}) });
        }
    }
}

slop_result_sriqabox_Inputs_string sriqabox_c_inputs(slop_arena* arena, sriqabox_Split sp, sriqclauses_SriqIds ids, sriqref_RefIn h, slop_list_owl2_RawAxiom omitted, int64_t bound) {
    __auto_type _mv_1535 = sriqnames_sriq_normalize_bounded(arena, sp.c.accepted, sp.c.signature, bound);
    if (!_mv_1535.is_ok) {
        __auto_type m = _mv_1535.data.err;
        return ((slop_result_sriqabox_Inputs_string){ .is_ok = false, .data.err = m });
    } else if (_mv_1535.is_ok) {
        __auto_type nc = _mv_1535.data.ok;
        __auto_type _mv_1536 = sriqclauses_sriq_clauses(arena, nc);
        if (!_mv_1536.is_ok) {
            __auto_type m = _mv_1536.data.err;
            return ((slop_result_sriqabox_Inputs_string){ .is_ok = false, .data.err = m });
        } else if (_mv_1536.is_ok) {
            __auto_type sc = _mv_1536.data.ok;
            return ((slop_result_sriqabox_Inputs_string){ .is_ok = true, .data.ok = ((sriqabox_Inputs){.ids = ids, .h = h, .c = sriqabox_consistency_input(sriqref_ref_input(arena, sc)), .has_c = 1, .omitted = sriqabox_both_omitted(arena, omitted, nc.omitted)}) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_list_owl2_RawAxiom sriqabox_both_omitted(slop_arena* arena, slop_list_owl2_RawAxiom a, slop_list_owl2_RawAxiom b) {
    {
        __auto_type out = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = b;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

uint8_t sriqabox_finished(sriqref_RefStatus s) {
    return ((s == sriqref_RefStatus_rs_fixpoint) || (s == sriqref_RefStatus_rs_inconsistent));
}

sriqabox_SplitRun sriqabox_split_run(slop_arena* arena, sriqabox_Inputs in, sriqsat_SatConfig cfg) {
    return sriqabox_split_run_of(arena, in.h, in.c, in.has_c, (((int64_t)((in.omitted).len)) > 0), cfg);
}

sriqabox_SplitRun sriqabox_split_run_of(slop_arena* arena, sriqref_RefIn h_in, sriqref_RefIn c_in, uint8_t has_c, uint8_t omitted, sriqsat_SatConfig cfg) {
    {
        __auto_type h = sriqsat_sat_run(arena, h_in, cfg);
        __auto_type hst = h.res.st;
        __auto_type hdone = sriqabox_finished(h.res.status);
        __auto_type hbad = (sriqctx_q_inconsistent(arena, hst) || sriqctx_q_hidden_unsat(arena, hst, h_in.nquery, h_in.hidden));
        if ((hbad) || (h.cancelled) || (!(has_c))) {
            return ((sriqabox_SplitRun){.h = h, .c = h, .ran_c = 0, .inconsistent = hbad, .complete = (hbad || (hdone && !(omitted))), .finished = hdone, .rounds = h.res.rounds, .cancelled = h.cancelled});
        } else {
            return sriqabox_c_run(arena, h, hdone, c_in, omitted, cfg);
        }
    }
}

sriqabox_SplitRun sriqabox_c_run(slop_arena* arena, sriqsat_SatResult h, uint8_t hdone, sriqref_RefIn c_in, uint8_t omitted, sriqsat_SatConfig cfg) {
    {
        __auto_type c = sriqsat_sat_run(arena, c_in, sriqabox_with_fuel(cfg, (cfg.base.fuel - h.res.rounds)));
        __auto_type cbad = sriqctx_q_inconsistent(arena, c.res.st);
        __auto_type both = (hdone && sriqabox_finished(c.res.status));
        return ((sriqabox_SplitRun){.h = h, .c = c, .ran_c = 1, .inconsistent = cbad, .complete = (cbad || (both && !(omitted))), .finished = both, .rounds = (h.res.rounds + c.res.rounds), .cancelled = c.cancelled});
    }
}

sriqsat_SatConfig sriqabox_with_fuel(sriqsat_SatConfig cfg, int64_t fuel) {
    {
        __auto_type b = cfg.base;
        return ((sriqsat_SatConfig){.base = ((sriqref_RefConfig){.strat = b.strat, .fuel = (((fuel < 0)) ? 0 : fuel), .lam = b.lam, .ctxs = b.ctxs, .cls = b.cls, .prod = b.prod, .cnst = b.cnst}), .perm = cfg.perm, .scan = cfg.scan, .defer = cfg.defer, .views = cfg.views, .check = cfg.check, .cancel = cfg.cancel});
    }
}

sriqsat_SatConfig sriqabox_sriq_config(int64_t max_rounds, int64_t budget, int64_t cancel) {
    return ((sriqsat_SatConfig){.base = ((sriqref_RefConfig){.strat = sriqctx_Strategy_st_cautious, .fuel = max_rounds, .lam = -1, .ctxs = 2147483647, .cls = budget, .prod = budget, .cnst = 2147483647}), .perm = 0, .scan = 0, .defer = 1, .views = 1, .check = 0, .cancel = cancel});
}

types_Findings sriqabox_split_findings(slop_arena* arena, sriqctx_Structure st, slop_list_rdf_IRI classes, uint8_t inconsistent) {
    types_Findings _retval = {0};
    _retval = ((types_Findings){.inconsistent = inconsistent, .unsatisfiable = ((inconsistent) ? ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) : sriqabox_unsat_classes(arena, st, classes)), .subsumptions = ((inconsistent) ? ((slop_list_types_SubPair){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) : sriqabox_taxonomy(arena, st, classes)), .imports_seen = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.inconsistent == inconsistent)), "(== (. $result inconsistent) inconsistent)");
    return _retval;
}

slop_list_types_Clause sriqabox_set_at_ctx(slop_arena* arena, sriqctx_Structure st, int64_t v) {
    __auto_type _mv_1537 = ({ __auto_type _lst = st.sets; size_t _idx = (size_t)v; slop_option_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1537.has_value) {
        __auto_type s = _mv_1537.value;
        return s.cs;
    } else if (!_mv_1537.has_value) {
        return ((slop_list_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqabox_body_within(types_Clause c, int64_t b) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(sriqabox_is_x_atom(l, b))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t sriqabox_is_x_atom(types_Lit l, int64_t b) {
    return (((b >= 0)) && ((l.form == types_LitForm_lf_unary)) && ((l.t1.kind == types_AKind_ak_x)) && ((((int64_t)(l.pred)) == b)));
}

int64_t sriqabox_head_class(types_Clause c, int64_t n) {
    __auto_type _mv_1538 = ({ __auto_type _lst = c.head; size_t _idx = (size_t)0; slop_option_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1538.has_value) {
        __auto_type l = _mv_1538.value;
        if (((((int64_t)((c.head).len)) == 1)) && ((l.form == types_LitForm_lf_unary)) && ((l.t1.kind == types_AKind_ak_x)) && ((((int64_t)(l.pred)) < n))) {
            return ((int64_t)(l.pred));
        } else {
            return -1;
        }
    } else if (!_mv_1538.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqabox_unsat_at(slop_arena* arena, sriqctx_Structure st, int64_t b) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = sriqabox_set_at_ctx(arena, st, (2 + b));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if ((((int64_t)((c.head).len)) == 0) && sriqabox_body_within(c, b)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_list_rdf_IRI sriqabox_unsat_classes(slop_arena* arena, sriqctx_Structure st, slop_list_rdf_IRI classes) {
    {
        __auto_type out = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t b = 0;
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                if (sriqabox_unsat_at(arena, st, b)) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                b = (b + 1);
            }
        }
        return canon_sort_iris(arena, out);
    }
}

slop_list_types_SubPair sriqabox_taxonomy(slop_arena* arena, sriqctx_Structure st, slop_list_rdf_IRI classes) {
    {
        __auto_type n = ((int64_t)(((int64_t)((classes).len))));
        __auto_type top = types_node_top();
        __auto_type raw = ((slop_list_types_SubPair){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t b = 0;
        ({ __auto_type _lst_p = &(raw); __auto_type _item = (((types_SubPair){.sub = top, .super = top})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = sriqabox_holds_in(arena, st, 1, -1, n);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(raw); __auto_type _item = (((types_SubPair){.sub = top, .super = sriqabox_class_at(classes, a)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                {
                    __auto_type _coll = sriqabox_class_rows(arena, st, classes, b, n);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type p = _coll.data[_i];
                        ({ __auto_type _lst_p = &(raw); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                b = (b + 1);
            }
        }
        return sriqabox_distinct_pairs(arena, canon_sort_sub_pairs(arena, raw));
    }
}

slop_list_types_SubPair sriqabox_class_rows(slop_arena* arena, sriqctx_Structure st, slop_list_rdf_IRI classes, int64_t b, int64_t n) {
    {
        __auto_type me = sriqabox_class_at(classes, b);
        __auto_type out = ((slop_list_types_SubPair){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (sriqabox_unsat_at(arena, st, b)) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_SubPair){.sub = me, .super = types_node_bottom()})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_SubPair){.sub = me, .super = types_node_top()})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            {
                __auto_type _coll = sriqabox_holds_in(arena, st, (2 + b), b, n);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_SubPair){.sub = me, .super = sriqabox_class_at(classes, a)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

slop_list_int sriqabox_holds_in(slop_arena* arena, sriqctx_Structure st, int64_t v, int64_t b, int64_t n) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = sriqabox_set_at_ctx(arena, st, v);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (sriqabox_body_within(c, b)) {
                    {
                        __auto_type a = sriqabox_head_class(c, n);
                        if (a >= 0) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        return out;
    }
}

types_Node sriqabox_class_at(slop_list_rdf_IRI classes, int64_t a) {
    __auto_type _mv_1539 = ({ __auto_type _lst = classes; size_t _idx = (size_t)a; slop_option_rdf_IRI _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1539.has_value) {
        __auto_type i = _mv_1539.value;
        return ((types_Node){ .tag = types_Node_class_node, .data.class_node = i });
    } else if (!_mv_1539.has_value) {
        return types_node_top();
    }
    SLOP_UNREACHABLE();
}

slop_list_types_SubPair sriqabox_distinct_pairs(slop_arena* arena, slop_list_types_SubPair ps) {
    {
        __auto_type out = ((slop_list_types_SubPair){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                __auto_type _mv_1540 = ({ __auto_type _lst = out; size_t _idx = (size_t)(((int64_t)(((int64_t)((out).len)))) - 1); slop_option_types_SubPair _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1540.has_value) {
                    __auto_type last = _mv_1540.value;
                    if (canon_sub_pair_cmp(last, p) != 0) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                } else if (!_mv_1540.has_value) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

