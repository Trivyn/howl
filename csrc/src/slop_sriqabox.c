#include "../runtime/slop_runtime.h"
#include "slop_sriqabox.h"

slop_option_slop_rdf_rdf_IRI howl_sriqabox_individual_of(howl_types_Node n);
void howl_sriqabox_put_node(slop_map* s, howl_types_Node n);
slop_map* howl_sriqabox_unfoldable(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
slop_list_slop_rdf_rdf_IRI howl_sriqabox_different_bad(slop_arena* arena, slop_list_howl_types_Node ns);
slop_list_slop_rdf_rdf_IRI howl_sriqabox_repeated(slop_arena* arena, slop_list_howl_types_Node ns);
slop_option_slop_rdf_rdf_IRI howl_sriqabox_foldable_subject(howl_owl2_RawClassAssertion ca, slop_map* bad);
slop_list_howl_sriqabox_Typed howl_sriqabox_typed_pairs(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_map* bad);
slop_option_howl_sriqabox_Typed howl_sriqabox_typed_of(howl_owl2_RawAxiom ax, slop_map* bad);
howl_sriqabox_Typed howl_sriqabox_typed_at(slop_list_howl_sriqabox_Typed xs, int64_t k, howl_sriqabox_Typed fallback);
int64_t howl_sriqabox_typed_cmp(howl_sriqabox_Typed a, howl_sriqabox_Typed b);
slop_list_howl_sriqabox_Typing howl_sriqabox_typings(slop_arena* arena, slop_list_howl_sriqabox_Typed pairs);
slop_list_howl_sriqabox_Typed howl_sriqabox_sorted_typed(slop_arena* arena, slop_list_howl_sriqabox_Typed pairs, howl_sriqabox_Typed p0);
slop_list_howl_sriqabox_Typing howl_sriqabox_typings_sorted(slop_arena* arena, slop_list_howl_sriqabox_Typed ps, howl_sriqabox_Typed p0);
int64_t howl_sriqabox_run_end(slop_list_howl_sriqabox_Typed ps, int64_t k, howl_sriqabox_Typed p0);
slop_list_howl_owl2_RawConcept howl_sriqabox_run_types(slop_arena* arena, slop_list_howl_sriqabox_Typed ps, int64_t k, int64_t end, howl_sriqabox_Typed p0);
uint8_t howl_sriqabox_ends_with(slop_list_howl_owl2_RawConcept cs, howl_owl2_RawConcept c);
int64_t howl_sriqabox_types_cmp(slop_list_howl_owl2_RawConcept a, slop_list_howl_owl2_RawConcept b);
howl_sriqabox_Typing howl_sriqabox_typing_at(slop_list_howl_sriqabox_Typing xs, int64_t k, howl_sriqabox_Typing fallback);
slop_map* howl_sriqabox_representatives(slop_arena* arena, slop_list_howl_sriqabox_Typing ts);
int64_t howl_sriqabox_typing_cmp(howl_sriqabox_Typing a, howl_sriqabox_Typing b);
slop_list_howl_sriqabox_Typing howl_sriqabox_sorted_typings(slop_arena* arena, slop_list_howl_sriqabox_Typing ts, howl_sriqabox_Typing t0);
slop_map* howl_sriqabox_first_of_each(slop_arena* arena, slop_list_howl_sriqabox_Typing ts);
uint8_t howl_sriqabox_h_keeps(howl_owl2_RawAxiom ax, slop_map* reps);
slop_option_howl_owl2_RawAxiom howl_sriqabox_c_axiom(slop_arena* arena, howl_owl2_RawAxiom ax, slop_map* bad);
slop_list_howl_types_Node howl_sriqabox_unfoldable_nodes(slop_arena* arena, slop_list_howl_types_Node ns, slop_map* bad);
uint8_t howl_sriqabox_is_assertion(howl_owl2_RawAxiom ax);
howl_owl2_Signature howl_sriqabox_with_individuals(howl_owl2_Signature sig, slop_map* inds);
howl_sriqabox_Split howl_sriqabox_abox_split(slop_arena* arena, howl_gate_GateResult gr);
slop_result_howl_sriqabox_Folded_string howl_sriqabox_fold_clauses(slop_arena* arena, howl_sriqnames_SriqNormal n);
slop_list_u32 howl_sriqabox_hidden_ids(slop_arena* arena, howl_sriqclauses_SriqClauses sc, slop_list_howl_types_DName names);
uint32_t howl_sriqabox_u32_at(slop_list_u32 xs, int64_t k);
int64_t howl_sriqabox_u32_cmp(uint32_t a, uint32_t b);
howl_sriqref_RefIn howl_sriqabox_h_input(slop_arena* arena, howl_sriqabox_Folded f);
howl_sriqref_RefIn howl_sriqabox_consistency_input(howl_sriqref_RefIn in);
slop_result_howl_sriqabox_Inputs_string howl_sriqabox_split_inputs(slop_arena* arena, howl_gate_GateResult gr);
slop_result_howl_sriqabox_Inputs_string howl_sriqabox_split_inputs_bounded(slop_arena* arena, howl_gate_GateResult gr, int64_t bound);
slop_result_howl_sriqabox_Inputs_string howl_sriqabox_inputs_from(slop_arena* arena, howl_sriqabox_Split sp, howl_sriqabox_Folded f, slop_list_howl_owl2_RawAxiom omitted, int64_t bound);
slop_result_howl_sriqabox_Inputs_string howl_sriqabox_c_inputs(slop_arena* arena, howl_sriqabox_Split sp, howl_sriqclauses_SriqIds ids, howl_sriqref_RefIn h, slop_list_howl_owl2_RawAxiom omitted, int64_t bound);
slop_list_howl_owl2_RawAxiom howl_sriqabox_both_omitted(slop_arena* arena, slop_list_howl_owl2_RawAxiom a, slop_list_howl_owl2_RawAxiom b);
uint8_t howl_sriqabox_finished(howl_sriqref_RefStatus s);
howl_sriqabox_SplitRun howl_sriqabox_split_run(slop_arena* arena, howl_sriqabox_Inputs in, howl_sriqsat_SatConfig cfg);
howl_sriqabox_SplitRun howl_sriqabox_split_run_of(slop_arena* arena, howl_sriqref_RefIn h_in, howl_sriqref_RefIn c_in, uint8_t has_c, uint8_t omitted, howl_sriqsat_SatConfig cfg);
howl_sriqabox_SplitRun howl_sriqabox_c_run(slop_arena* arena, howl_sriqsat_SatResult h, uint8_t hdone, howl_sriqref_RefIn c_in, uint8_t omitted, howl_sriqsat_SatConfig cfg);
howl_sriqsat_SatConfig howl_sriqabox_with_fuel(howl_sriqsat_SatConfig cfg, int64_t fuel);
howl_sriqsat_SatConfig howl_sriqabox_sriq_config(int64_t max_rounds, int64_t budget, int64_t cancel);
howl_types_Findings howl_sriqabox_split_findings(slop_arena* arena, howl_sriqctx_Structure st, slop_list_slop_rdf_rdf_IRI classes, uint8_t inconsistent);
slop_list_howl_types_Clause howl_sriqabox_set_at_ctx(slop_arena* arena, howl_sriqctx_Structure st, int64_t v);
uint8_t howl_sriqabox_body_within(howl_types_Clause c, int64_t b);
uint8_t howl_sriqabox_is_x_atom(howl_types_Lit l, int64_t b);
int64_t howl_sriqabox_head_class(howl_types_Clause c, int64_t n);
uint8_t howl_sriqabox_unsat_at(slop_arena* arena, howl_sriqctx_Structure st, int64_t b);
slop_list_slop_rdf_rdf_IRI howl_sriqabox_unsat_classes(slop_arena* arena, howl_sriqctx_Structure st, slop_list_slop_rdf_rdf_IRI classes);
slop_list_howl_types_SubPair howl_sriqabox_taxonomy(slop_arena* arena, howl_sriqctx_Structure st, slop_list_slop_rdf_rdf_IRI classes);
slop_list_howl_types_SubPair howl_sriqabox_class_rows(slop_arena* arena, howl_sriqctx_Structure st, slop_list_slop_rdf_rdf_IRI classes, int64_t b, int64_t n);
slop_list_int howl_sriqabox_holds_in(slop_arena* arena, howl_sriqctx_Structure st, int64_t v, int64_t b, int64_t n);
howl_types_Node howl_sriqabox_class_at(slop_list_slop_rdf_rdf_IRI classes, int64_t a);
slop_list_howl_types_SubPair howl_sriqabox_distinct_pairs(slop_arena* arena, slop_list_howl_types_SubPair ps);

typedef struct { slop_list_howl_sriqabox_Typed pairs; howl_sriqabox_Typed p0; } howl_sriqabox__lambda_1581_env_t;

static int64_t howl_sriqabox__lambda_1581(howl_sriqabox__lambda_1581_env_t* _env, int64_t i, int64_t j) { return howl_sriqabox_typed_cmp(howl_sriqabox_typed_at(_env->pairs, i, _env->p0), howl_sriqabox_typed_at(_env->pairs, j, _env->p0)); }

typedef struct { slop_list_howl_sriqabox_Typing ts; howl_sriqabox_Typing t0; } howl_sriqabox__lambda_1586_env_t;

static int64_t howl_sriqabox__lambda_1586(howl_sriqabox__lambda_1586_env_t* _env, int64_t i, int64_t j) { return howl_sriqabox_typing_cmp(howl_sriqabox_typing_at(_env->ts, i, _env->t0), howl_sriqabox_typing_at(_env->ts, j, _env->t0)); }

typedef struct { slop_list_u32* raw; } howl_sriqabox__lambda_1599_env_t;

static int64_t howl_sriqabox__lambda_1599(howl_sriqabox__lambda_1599_env_t* _env, int64_t i, int64_t j) { return howl_sriqabox_u32_cmp(howl_sriqabox_u32_at((*_env->raw), i), howl_sriqabox_u32_at((*_env->raw), j)); }

slop_option_slop_rdf_rdf_IRI howl_sriqabox_individual_of(howl_types_Node n) {
    __auto_type _mv_1565 = n;
    switch (_mv_1565.tag) {
        case howl_types_Node_individual_node:
        {
            __auto_type i = _mv_1565.data.individual_node;
            return (slop_option_slop_rdf_rdf_IRI){.has_value = 1, .value = i};
        }
        case howl_types_Node_class_node:
        {
            __auto_type _ = _mv_1565.data.class_node;
            return (slop_option_slop_rdf_rdf_IRI){.has_value = false};
        }
        case howl_types_Node_fresh_node:
        {
            __auto_type _ = _mv_1565.data.fresh_node;
            return (slop_option_slop_rdf_rdf_IRI){.has_value = false};
        }
    }
    SLOP_UNREACHABLE();
}

void howl_sriqabox_put_node(slop_map* s, howl_types_Node n) {
    __auto_type _mv_1566 = howl_sriqabox_individual_of(n);
    if (_mv_1566.has_value) {
        __auto_type i = _mv_1566.value;
        ({ slop_map_put(NULL, s, &(i), NULL, 0); });
    } else if (!_mv_1566.has_value) {
    }
}

slop_map* howl_sriqabox_unfoldable(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs) {
    {
        __auto_type bad = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1568 = ax;
                switch (_mv_1568.tag) {
                    case howl_owl2_RawAxiom_ra_object_property_assertion:
                    {
                        __auto_type e = _mv_1568.data.ra_object_property_assertion;
                        howl_sriqabox_put_node(bad, e.from);
                        howl_sriqabox_put_node(bad, e.to);
                        break;
                    }
                    case howl_owl2_RawAxiom_ra_negative_assertion:
                    {
                        __auto_type e = _mv_1568.data.ra_negative_assertion;
                        howl_sriqabox_put_node(bad, e.from);
                        howl_sriqabox_put_node(bad, e.to);
                        break;
                    }
                    case howl_owl2_RawAxiom_ra_same_individual:
                    {
                        __auto_type ns = _mv_1568.data.ra_same_individual;
                        {
                            __auto_type _coll = ns;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type n = _coll.data[_i];
                                howl_sriqabox_put_node(bad, n);
                            }
                        }
                        break;
                    }
                    case howl_owl2_RawAxiom_ra_different_individuals:
                    {
                        __auto_type ns = _mv_1568.data.ra_different_individuals;
                        {
                            __auto_type _coll = howl_sriqabox_different_bad(arena, ns);
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

slop_list_slop_rdf_rdf_IRI howl_sriqabox_different_bad(slop_arena* arena, slop_list_howl_types_Node ns) {
    {
        uint8_t odd = 0;
        __auto_type all = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                __auto_type _mv_1570 = howl_sriqabox_individual_of(n);
                if (_mv_1570.has_value) {
                    __auto_type i = _mv_1570.value;
                    ({ __auto_type _lst_p = &(all); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1570.has_value) {
                    odd = 1;
                }
            }
        }
        if (odd) {
            return all;
        } else {
            return howl_sriqabox_repeated(arena, ns);
        }
    }
}

slop_list_slop_rdf_rdf_IRI howl_sriqabox_repeated(slop_arena* arena, slop_list_howl_types_Node ns) {
    {
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type out = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                __auto_type _mv_1571 = howl_sriqabox_individual_of(n);
                if (_mv_1571.has_value) {
                    __auto_type i = _mv_1571.value;
                    if (slop_map_has(seen, &(i))) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else {
                        ({ slop_map_put(NULL, seen, &(i), NULL, 0); });
                    }
                } else if (!_mv_1571.has_value) {
                }
            }
        }
        return out;
    }
}

slop_option_slop_rdf_rdf_IRI howl_sriqabox_foldable_subject(howl_owl2_RawClassAssertion ca, slop_map* bad) {
    __auto_type _mv_1574 = howl_sriqabox_individual_of(ca.subject);
    if (_mv_1574.has_value) {
        __auto_type i = _mv_1574.value;
        if (slop_map_has(bad, &(i))) {
            return (slop_option_slop_rdf_rdf_IRI){.has_value = false};
        } else {
            return (slop_option_slop_rdf_rdf_IRI){.has_value = 1, .value = i};
        }
    } else if (!_mv_1574.has_value) {
        return (slop_option_slop_rdf_rdf_IRI){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_sriqabox_Typed howl_sriqabox_typed_pairs(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_map* bad) {
    {
        __auto_type out = ((slop_list_howl_sriqabox_Typed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1576 = howl_sriqabox_typed_of(ax, bad);
                if (_mv_1576.has_value) {
                    __auto_type t = _mv_1576.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1576.has_value) {
                }
            }
        }
        return out;
    }
}

slop_option_howl_sriqabox_Typed howl_sriqabox_typed_of(howl_owl2_RawAxiom ax, slop_map* bad) {
    __auto_type _mv_1577 = ax;
    switch (_mv_1577.tag) {
        case howl_owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_1577.data.ra_class_assertion;
            __auto_type _mv_1578 = howl_sriqabox_foldable_subject(ca, bad);
            if (_mv_1578.has_value) {
                __auto_type i = _mv_1578.value;
                return (slop_option_howl_sriqabox_Typed){.has_value = 1, .value = ((howl_sriqabox_Typed){.ind = i, .c = (*ca.concept)})};
            } else if (!_mv_1578.has_value) {
                return (slop_option_howl_sriqabox_Typed){.has_value = false};
            }
            SLOP_UNREACHABLE();
        }
        default: {
            return (slop_option_howl_sriqabox_Typed){.has_value = false};
        }
    }
}

howl_sriqabox_Typed howl_sriqabox_typed_at(slop_list_howl_sriqabox_Typed xs, int64_t k, howl_sriqabox_Typed fallback) {
    __auto_type _mv_1579 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_howl_sriqabox_Typed _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1579.has_value) {
        __auto_type x = _mv_1579.value;
        return x;
    } else if (!_mv_1579.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqabox_typed_cmp(howl_sriqabox_Typed a, howl_sriqabox_Typed b) {
    {
        __auto_type r = howl_canon_iri_cmp(a.ind, b.ind);
        if (r != 0) {
            return r;
        } else {
            return howl_owl2_concept_cmp(a.c, b.c);
        }
    }
}

slop_list_howl_sriqabox_Typing howl_sriqabox_typings(slop_arena* arena, slop_list_howl_sriqabox_Typed pairs) {
    __auto_type _mv_1580 = ({ __auto_type _lst = pairs; size_t _idx = (size_t)0; slop_option_howl_sriqabox_Typed _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1580.has_value) {
        return ((slop_list_howl_sriqabox_Typing){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    } else if (_mv_1580.has_value) {
        __auto_type p0 = _mv_1580.value;
        return howl_sriqabox_typings_sorted(arena, howl_sriqabox_sorted_typed(arena, pairs, p0), p0);
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_sriqabox_Typed howl_sriqabox_sorted_typed(slop_arena* arena, slop_list_howl_sriqabox_Typed pairs, howl_sriqabox_Typed p0) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((pairs).len)))), ({ howl_sriqabox__lambda_1581_env_t* howl_sriqabox__lambda_1581_env = (howl_sriqabox__lambda_1581_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqabox__lambda_1581_env_t)); *howl_sriqabox__lambda_1581_env = (howl_sriqabox__lambda_1581_env_t){ .pairs = pairs, .p0 = p0 }; (slop_closure_t){ (void*)howl_sriqabox__lambda_1581, (void*)howl_sriqabox__lambda_1581_env }; }));
        __auto_type out = ((slop_list_howl_sriqabox_Typed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqabox_typed_at(pairs, k, p0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_sriqabox_Typing howl_sriqabox_typings_sorted(slop_arena* arena, slop_list_howl_sriqabox_Typed ps, howl_sriqabox_Typed p0) {
    {
        __auto_type out = ((slop_list_howl_sriqabox_Typing){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        __auto_type n = ((int64_t)(((int64_t)((ps).len))));
        while (k < n) {
            {
                __auto_type ind = howl_sriqabox_typed_at(ps, k, p0).ind;
                __auto_type end = howl_sriqabox_run_end(ps, k, p0);
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqabox_Typing){.ind = ind, .types = howl_sriqabox_run_types(arena, ps, k, end, p0)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                k = end;
            }
        }
        return out;
    }
}

int64_t howl_sriqabox_run_end(slop_list_howl_sriqabox_Typed ps, int64_t k, howl_sriqabox_Typed p0) {
    {
        __auto_type ind = howl_sriqabox_typed_at(ps, k, p0).ind;
        int64_t e = k;
        while ((e < ((int64_t)(((int64_t)((ps).len))))) && (howl_canon_iri_cmp(howl_sriqabox_typed_at(ps, e, p0).ind, ind) == 0)) {
            e = (e + 1);
        }
        return e;
    }
}

slop_list_howl_owl2_RawConcept howl_sriqabox_run_types(slop_arena* arena, slop_list_howl_sriqabox_Typed ps, int64_t k, int64_t end, howl_sriqabox_Typed p0) {
    {
        __auto_type cur = ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = k;
        while (i < end) {
            if (!(howl_sriqabox_ends_with(cur, howl_sriqabox_typed_at(ps, i, p0).c))) {
                (void)(({ __auto_type _lst_p = &(cur); __auto_type _item = (howl_sriqabox_typed_at(ps, i, p0).c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
            i = (i + 1);
        }
        return cur;
    }
}

uint8_t howl_sriqabox_ends_with(slop_list_howl_owl2_RawConcept cs, howl_owl2_RawConcept c) {
    __auto_type _mv_1582 = ({ __auto_type _lst = cs; size_t _idx = (size_t)(((int64_t)(((int64_t)((cs).len)))) - 1); slop_option_howl_owl2_RawConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1582.has_value) {
        __auto_type x = _mv_1582.value;
        return (howl_owl2_concept_cmp(x, c) == 0);
    } else if (!_mv_1582.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqabox_types_cmp(slop_list_howl_owl2_RawConcept a, slop_list_howl_owl2_RawConcept b) {
    {
        int64_t r = 0;
        int64_t i = 0;
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (r == 0) {
                    __auto_type _mv_1583 = ({ __auto_type _lst = b; size_t _idx = (size_t)i; slop_option_howl_owl2_RawConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_1583.has_value) {
                        __auto_type y = _mv_1583.value;
                        r = howl_owl2_concept_cmp(x, y);
                    } else if (!_mv_1583.has_value) {
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

howl_sriqabox_Typing howl_sriqabox_typing_at(slop_list_howl_sriqabox_Typing xs, int64_t k, howl_sriqabox_Typing fallback) {
    __auto_type _mv_1584 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_howl_sriqabox_Typing _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1584.has_value) {
        __auto_type x = _mv_1584.value;
        return x;
    } else if (!_mv_1584.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_map* howl_sriqabox_representatives(slop_arena* arena, slop_list_howl_sriqabox_Typing ts) {
    __auto_type _mv_1585 = ({ __auto_type _lst = ts; size_t _idx = (size_t)0; slop_option_howl_sriqabox_Typing _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1585.has_value) {
        return ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
    } else if (_mv_1585.has_value) {
        __auto_type t0 = _mv_1585.value;
        return howl_sriqabox_first_of_each(arena, howl_sriqabox_sorted_typings(arena, ts, t0));
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqabox_typing_cmp(howl_sriqabox_Typing a, howl_sriqabox_Typing b) {
    {
        __auto_type r = howl_sriqabox_types_cmp(a.types, b.types);
        if (r != 0) {
            return r;
        } else {
            return howl_canon_iri_cmp(a.ind, b.ind);
        }
    }
}

slop_list_howl_sriqabox_Typing howl_sriqabox_sorted_typings(slop_arena* arena, slop_list_howl_sriqabox_Typing ts, howl_sriqabox_Typing t0) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((ts).len)))), ({ howl_sriqabox__lambda_1586_env_t* howl_sriqabox__lambda_1586_env = (howl_sriqabox__lambda_1586_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqabox__lambda_1586_env_t)); *howl_sriqabox__lambda_1586_env = (howl_sriqabox__lambda_1586_env_t){ .ts = ts, .t0 = t0 }; (slop_closure_t){ (void*)howl_sriqabox__lambda_1586, (void*)howl_sriqabox__lambda_1586_env }; }));
        __auto_type out = ((slop_list_howl_sriqabox_Typing){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqabox_typing_at(ts, k, t0)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_map* howl_sriqabox_first_of_each(slop_arena* arena, slop_list_howl_sriqabox_Typing ts) {
    {
        __auto_type reps = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type prev = ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t started = 0;
        {
            __auto_type _coll = ts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                if (!(started) || (howl_sriqabox_types_cmp(prev, t.types) != 0)) {
                    {
                        __auto_type i = t.ind;
                        (void)(({ slop_map_put(NULL, reps, &(i), NULL, 0); }));
                        prev = t.types;
                        started = 1;
                    }
                }
            }
        }
        return reps;
    }
}

uint8_t howl_sriqabox_h_keeps(howl_owl2_RawAxiom ax, slop_map* reps) {
    __auto_type _mv_1588 = ax;
    switch (_mv_1588.tag) {
        case howl_owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_1588.data.ra_class_assertion;
            __auto_type _mv_1589 = howl_sriqabox_individual_of(ca.subject);
            if (_mv_1589.has_value) {
                __auto_type i = _mv_1589.value;
                return slop_map_has(reps, &(i));
            } else if (!_mv_1589.has_value) {
                return 0;
            }
            SLOP_UNREACHABLE();
        }
        case howl_owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type _ = _mv_1588.data.ra_object_property_assertion;
            return 0;
        }
        case howl_owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type _ = _mv_1588.data.ra_negative_assertion;
            return 0;
        }
        case howl_owl2_RawAxiom_ra_same_individual:
        {
            __auto_type _ = _mv_1588.data.ra_same_individual;
            return 0;
        }
        case howl_owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type _ = _mv_1588.data.ra_different_individuals;
            return 0;
        }
        default: {
            return 1;
        }
    }
}

slop_option_howl_owl2_RawAxiom howl_sriqabox_c_axiom(slop_arena* arena, howl_owl2_RawAxiom ax, slop_map* bad) {
    __auto_type _mv_1591 = ax;
    switch (_mv_1591.tag) {
        case howl_owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_1591.data.ra_class_assertion;
            __auto_type _mv_1592 = howl_sriqabox_foldable_subject(ca, bad);
            if (_mv_1592.has_value) {
                __auto_type _ = _mv_1592.value;
                return (slop_option_howl_owl2_RawAxiom){.has_value = false};
            } else if (!_mv_1592.has_value) {
                return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ax};
            }
            SLOP_UNREACHABLE();
        }
        case howl_owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type ns = _mv_1591.data.ra_different_individuals;
            {
                __auto_type kept = howl_sriqabox_unfoldable_nodes(arena, ns, bad);
                if (((int64_t)((kept).len)) >= 2) {
                    return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_different_individuals, .data.ra_different_individuals = kept })};
                } else {
                    return (slop_option_howl_owl2_RawAxiom){.has_value = false};
                }
            }
        }
        default: {
            return (slop_option_howl_owl2_RawAxiom){.has_value = 1, .value = ax};
        }
    }
}

slop_list_howl_types_Node howl_sriqabox_unfoldable_nodes(slop_arena* arena, slop_list_howl_types_Node ns, slop_map* bad) {
    {
        __auto_type out = ((slop_list_howl_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                __auto_type _mv_1593 = howl_sriqabox_individual_of(n);
                if (_mv_1593.has_value) {
                    __auto_type i = _mv_1593.value;
                    if (slop_map_has(bad, &(i))) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                } else if (!_mv_1593.has_value) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

uint8_t howl_sriqabox_is_assertion(howl_owl2_RawAxiom ax) {
    __auto_type _mv_1595 = ax;
    switch (_mv_1595.tag) {
        case howl_owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type _ = _mv_1595.data.ra_class_assertion;
            return 1;
        }
        case howl_owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type _ = _mv_1595.data.ra_object_property_assertion;
            return 1;
        }
        case howl_owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type _ = _mv_1595.data.ra_negative_assertion;
            return 1;
        }
        case howl_owl2_RawAxiom_ra_same_individual:
        {
            __auto_type _ = _mv_1595.data.ra_same_individual;
            return 1;
        }
        case howl_owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type _ = _mv_1595.data.ra_different_individuals;
            return 1;
        }
        default: {
            return 0;
        }
    }
}

howl_owl2_Signature howl_sriqabox_with_individuals(howl_owl2_Signature sig, slop_map* inds) {
    return ((howl_owl2_Signature){.classes = sig.classes, .obj_props = sig.obj_props, .data_props = sig.data_props, .annot_props = sig.annot_props, .individuals = inds, .datatypes = sig.datatypes});
}

howl_sriqabox_Split howl_sriqabox_abox_split(slop_arena* arena, howl_gate_GateResult gr) {
    {
        __auto_type bad = howl_sriqabox_unfoldable(arena, gr.accepted);
        __auto_type reps = howl_sriqabox_representatives(arena, howl_sriqabox_typings(arena, howl_sriqabox_typed_pairs(arena, gr.accepted, bad)));
        __auto_type hs = ((slop_list_howl_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type cs = ((slop_list_howl_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t rest = 0;
        {
            __auto_type _coll = gr.accepted;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                if (howl_sriqabox_h_keeps(ax, reps)) {
                    (void)(({ __auto_type _lst_p = &(hs); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                __auto_type _mv_1596 = howl_sriqabox_c_axiom(arena, ax, bad);
                if (_mv_1596.has_value) {
                    __auto_type x = _mv_1596.value;
                    ({ __auto_type _lst_p = &(cs); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    if (howl_sriqabox_is_assertion(x)) {
                        rest = 1;
                    }
                } else if (!_mv_1596.has_value) {
                }
            }
        }
        return ((howl_sriqabox_Split){.h = ((howl_gate_GateResult){.accepted = hs, .omissions = gr.omissions, .reasons = gr.reasons, .signature = howl_sriqabox_with_individuals(gr.signature, ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }))}), .c = ((howl_gate_GateResult){.accepted = cs, .omissions = gr.omissions, .reasons = gr.reasons, .signature = howl_sriqabox_with_individuals(gr.signature, bad)}), .has_c = rest});
    }
}

slop_result_howl_sriqabox_Folded_string howl_sriqabox_fold_clauses(slop_arena* arena, howl_sriqnames_SriqNormal n) {
    {
        __auto_type kept = ((slop_list_howl_types_DlClause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type names = ((slop_list_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t dl11 = 0;
        {
            __auto_type _coll = n.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                __auto_type _mv_1597 = c;
                switch (_mv_1597.tag) {
                    case howl_types_DlClause_dl10:
                    {
                        __auto_type a = _mv_1597.data.dl10.f1;
                        ({ __auto_type _lst_p = &(names); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_types_DlClause_dl11:
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
            return ((slop_result_howl_sriqabox_Folded_string){ .is_ok = false, .data.err = SLOP_STR("Run H holds a DL11 clause, so a positive nominal") });
        } else {
            __auto_type _mv_1598 = howl_sriqclauses_sriq_clauses(arena, ((howl_sriqnames_SriqNormal){.clauses = kept, .concepts = n.concepts, .sroles = n.sroles, .sfills = n.sfills, .bars = n.bars, .fns = n.fns, .classes = n.classes, .individuals = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .omitted = n.omitted}));
            if (!_mv_1598.is_ok) {
                __auto_type m = _mv_1598.data.err;
                return ((slop_result_howl_sriqabox_Folded_string){ .is_ok = false, .data.err = m });
            } else if (_mv_1598.is_ok) {
                __auto_type sc = _mv_1598.data.ok;
                return ((slop_result_howl_sriqabox_Folded_string){ .is_ok = true, .data.ok = ((howl_sriqabox_Folded){.sc = sc, .hidden = howl_sriqabox_hidden_ids(arena, sc, names)}) });
            }
            SLOP_UNREACHABLE();
        }
    }
}

slop_list_u32 howl_sriqabox_hidden_ids(slop_arena* arena, howl_sriqclauses_SriqClauses sc, slop_list_howl_types_DName names) {
    {
        __auto_type raw = ((slop_list_u32){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type out = ((slop_list_u32){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = names;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(raw); __auto_type _item = (howl_sriqclauses_class_id(sc.ids, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((raw).len)))), ({ howl_sriqabox__lambda_1599_env_t* howl_sriqabox__lambda_1599_env = (howl_sriqabox__lambda_1599_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqabox__lambda_1599_env_t)); *howl_sriqabox__lambda_1599_env = (howl_sriqabox__lambda_1599_env_t){ .raw = &(raw) }; (slop_closure_t){ (void*)howl_sriqabox__lambda_1599, (void*)howl_sriqabox__lambda_1599_env }; }));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type v = howl_sriqabox_u32_at(raw, k);
                    __auto_type _mv_1600 = ({ __auto_type _lst = out; size_t _idx = (size_t)(((int64_t)(((int64_t)((out).len)))) - 1); slop_option_u32 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_1600.has_value) {
                        __auto_type last = _mv_1600.value;
                        if (last != v) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    } else if (!_mv_1600.has_value) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

uint32_t howl_sriqabox_u32_at(slop_list_u32 xs, int64_t k) {
    __auto_type _mv_1601 = ({ __auto_type _lst = xs; size_t _idx = (size_t)k; slop_option_u32 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1601.has_value) {
        __auto_type x = _mv_1601.value;
        return x;
    } else if (!_mv_1601.has_value) {
        return ((uint32_t)(0));
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqabox_u32_cmp(uint32_t a, uint32_t b) {
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    } else {
        return 0;
    }
}

howl_sriqref_RefIn howl_sriqabox_h_input(slop_arena* arena, howl_sriqabox_Folded f) {
    {
        __auto_type in = howl_sriqref_ref_input(arena, f.sc);
        return ((howl_sriqref_RefIn){.onto = in.onto, .nclass = in.nclass, .nquery = in.nquery, .nrole = in.nrole, .nfn = in.nfn, .nconst = in.nconst, .hidden = f.hidden});
    }
}

howl_sriqref_RefIn howl_sriqabox_consistency_input(howl_sriqref_RefIn in) {
    return ((howl_sriqref_RefIn){.onto = in.onto, .nclass = in.nclass, .nquery = 0, .nrole = in.nrole, .nfn = in.nfn, .nconst = in.nconst, .hidden = in.hidden});
}

slop_result_howl_sriqabox_Inputs_string howl_sriqabox_split_inputs(slop_arena* arena, howl_gate_GateResult gr) {
    return howl_sriqabox_split_inputs_bounded(arena, gr, howl_sriqelim_S1_BOUND);
}

slop_result_howl_sriqabox_Inputs_string howl_sriqabox_split_inputs_bounded(slop_arena* arena, howl_gate_GateResult gr, int64_t bound) {
    {
        __auto_type sp = howl_sriqabox_abox_split(arena, gr);
        __auto_type _mv_1602 = howl_sriqnames_sriq_normalize_bounded(arena, sp.h.accepted, sp.h.signature, bound);
        if (!_mv_1602.is_ok) {
            __auto_type m = _mv_1602.data.err;
            return ((slop_result_howl_sriqabox_Inputs_string){ .is_ok = false, .data.err = m });
        } else if (_mv_1602.is_ok) {
            __auto_type nh = _mv_1602.data.ok;
            __auto_type _mv_1603 = howl_sriqabox_fold_clauses(arena, nh);
            if (!_mv_1603.is_ok) {
                __auto_type m = _mv_1603.data.err;
                return ((slop_result_howl_sriqabox_Inputs_string){ .is_ok = false, .data.err = m });
            } else if (_mv_1603.is_ok) {
                __auto_type f = _mv_1603.data.ok;
                return howl_sriqabox_inputs_from(arena, sp, f, nh.omitted, bound);
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

slop_result_howl_sriqabox_Inputs_string howl_sriqabox_inputs_from(slop_arena* arena, howl_sriqabox_Split sp, howl_sriqabox_Folded f, slop_list_howl_owl2_RawAxiom omitted, int64_t bound) {
    {
        __auto_type h = howl_sriqabox_h_input(arena, f);
        if (sp.has_c) {
            return howl_sriqabox_c_inputs(arena, sp, f.sc.ids, h, omitted, bound);
        } else {
            return ((slop_result_howl_sriqabox_Inputs_string){ .is_ok = true, .data.ok = ((howl_sriqabox_Inputs){.ids = f.sc.ids, .h = h, .c = h, .has_c = 0, .omitted = omitted}) });
        }
    }
}

slop_result_howl_sriqabox_Inputs_string howl_sriqabox_c_inputs(slop_arena* arena, howl_sriqabox_Split sp, howl_sriqclauses_SriqIds ids, howl_sriqref_RefIn h, slop_list_howl_owl2_RawAxiom omitted, int64_t bound) {
    __auto_type _mv_1604 = howl_sriqnames_sriq_normalize_bounded(arena, sp.c.accepted, sp.c.signature, bound);
    if (!_mv_1604.is_ok) {
        __auto_type m = _mv_1604.data.err;
        return ((slop_result_howl_sriqabox_Inputs_string){ .is_ok = false, .data.err = m });
    } else if (_mv_1604.is_ok) {
        __auto_type nc = _mv_1604.data.ok;
        __auto_type _mv_1605 = howl_sriqclauses_sriq_clauses(arena, nc);
        if (!_mv_1605.is_ok) {
            __auto_type m = _mv_1605.data.err;
            return ((slop_result_howl_sriqabox_Inputs_string){ .is_ok = false, .data.err = m });
        } else if (_mv_1605.is_ok) {
            __auto_type sc = _mv_1605.data.ok;
            return ((slop_result_howl_sriqabox_Inputs_string){ .is_ok = true, .data.ok = ((howl_sriqabox_Inputs){.ids = ids, .h = h, .c = howl_sriqabox_consistency_input(howl_sriqref_ref_input(arena, sc)), .has_c = 1, .omitted = howl_sriqabox_both_omitted(arena, omitted, nc.omitted)}) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_owl2_RawAxiom howl_sriqabox_both_omitted(slop_arena* arena, slop_list_howl_owl2_RawAxiom a, slop_list_howl_owl2_RawAxiom b) {
    {
        __auto_type out = ((slop_list_howl_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = b;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

uint8_t howl_sriqabox_finished(howl_sriqref_RefStatus s) {
    return ((s == howl_sriqref_RefStatus_rs_fixpoint) || (s == howl_sriqref_RefStatus_rs_inconsistent));
}

howl_sriqabox_SplitRun howl_sriqabox_split_run(slop_arena* arena, howl_sriqabox_Inputs in, howl_sriqsat_SatConfig cfg) {
    return howl_sriqabox_split_run_of(arena, in.h, in.c, in.has_c, (((int64_t)((in.omitted).len)) > 0), cfg);
}

howl_sriqabox_SplitRun howl_sriqabox_split_run_of(slop_arena* arena, howl_sriqref_RefIn h_in, howl_sriqref_RefIn c_in, uint8_t has_c, uint8_t omitted, howl_sriqsat_SatConfig cfg) {
    {
        __auto_type h = howl_sriqsat_sat_run(arena, h_in, cfg);
        __auto_type hst = h.res.st;
        __auto_type hdone = howl_sriqabox_finished(h.res.status);
        __auto_type hbad = (howl_sriqctx_q_inconsistent(arena, hst) || howl_sriqctx_q_hidden_unsat(arena, hst, h_in.nquery, h_in.hidden));
        if ((hbad) || (h.cancelled) || (!(has_c))) {
            return ((howl_sriqabox_SplitRun){.h = h, .c = h, .ran_c = 0, .inconsistent = hbad, .complete = (hbad || (hdone && !(omitted))), .finished = hdone, .rounds = h.res.rounds, .cancelled = h.cancelled});
        } else {
            return howl_sriqabox_c_run(arena, h, hdone, c_in, omitted, cfg);
        }
    }
}

howl_sriqabox_SplitRun howl_sriqabox_c_run(slop_arena* arena, howl_sriqsat_SatResult h, uint8_t hdone, howl_sriqref_RefIn c_in, uint8_t omitted, howl_sriqsat_SatConfig cfg) {
    {
        __auto_type c = howl_sriqsat_sat_run(arena, c_in, howl_sriqabox_with_fuel(cfg, (cfg.base.fuel - h.res.rounds)));
        __auto_type cbad = howl_sriqctx_q_inconsistent(arena, c.res.st);
        __auto_type both = (hdone && howl_sriqabox_finished(c.res.status));
        return ((howl_sriqabox_SplitRun){.h = h, .c = c, .ran_c = 1, .inconsistent = cbad, .complete = (cbad || (both && !(omitted))), .finished = both, .rounds = (h.res.rounds + c.res.rounds), .cancelled = c.cancelled});
    }
}

howl_sriqsat_SatConfig howl_sriqabox_with_fuel(howl_sriqsat_SatConfig cfg, int64_t fuel) {
    {
        __auto_type b = cfg.base;
        return ((howl_sriqsat_SatConfig){.base = ((howl_sriqref_RefConfig){.strat = b.strat, .fuel = (((fuel < 0)) ? 0 : fuel), .lam = b.lam, .ctxs = b.ctxs, .cls = b.cls, .prod = b.prod, .cnst = b.cnst}), .perm = cfg.perm, .scan = cfg.scan, .defer = cfg.defer, .views = cfg.views, .check = cfg.check, .cancel = cfg.cancel});
    }
}

howl_sriqsat_SatConfig howl_sriqabox_sriq_config(int64_t max_rounds, int64_t budget, int64_t cancel) {
    return ((howl_sriqsat_SatConfig){.base = ((howl_sriqref_RefConfig){.strat = howl_sriqctx_Strategy_st_cautious, .fuel = max_rounds, .lam = -1, .ctxs = 2147483647, .cls = budget, .prod = budget, .cnst = 2147483647}), .perm = 0, .scan = 0, .defer = 1, .views = 1, .check = 0, .cancel = cancel});
}

howl_types_Findings howl_sriqabox_split_findings(slop_arena* arena, howl_sriqctx_Structure st, slop_list_slop_rdf_rdf_IRI classes, uint8_t inconsistent) {
    howl_types_Findings _retval = {0};
    _retval = ((howl_types_Findings){.inconsistent = inconsistent, .unsatisfiable = ((inconsistent) ? ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) : howl_sriqabox_unsat_classes(arena, st, classes)), .subsumptions = ((inconsistent) ? ((slop_list_howl_types_SubPair){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) : howl_sriqabox_taxonomy(arena, st, classes)), .imports_seen = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.inconsistent == inconsistent)), "(== (. $result inconsistent) inconsistent)");
    return _retval;
}

slop_list_howl_types_Clause howl_sriqabox_set_at_ctx(slop_arena* arena, howl_sriqctx_Structure st, int64_t v) {
    __auto_type _mv_1606 = ({ __auto_type _lst = st.sets; size_t _idx = (size_t)v; slop_option_howl_sriqctx_CtxSet _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1606.has_value) {
        __auto_type s = _mv_1606.value;
        return s.cs;
    } else if (!_mv_1606.has_value) {
        return ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqabox_body_within(howl_types_Clause c, int64_t b) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(howl_sriqabox_is_x_atom(l, b))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t howl_sriqabox_is_x_atom(howl_types_Lit l, int64_t b) {
    return (((b >= 0)) && ((l.form == howl_types_LitForm_lf_unary)) && ((l.t1.kind == howl_types_AKind_ak_x)) && ((((int64_t)(l.pred)) == b)));
}

int64_t howl_sriqabox_head_class(howl_types_Clause c, int64_t n) {
    __auto_type _mv_1607 = ({ __auto_type _lst = c.head; size_t _idx = (size_t)0; slop_option_howl_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1607.has_value) {
        __auto_type l = _mv_1607.value;
        if (((((int64_t)((c.head).len)) == 1)) && ((l.form == howl_types_LitForm_lf_unary)) && ((l.t1.kind == howl_types_AKind_ak_x)) && ((((int64_t)(l.pred)) < n))) {
            return ((int64_t)(l.pred));
        } else {
            return -1;
        }
    } else if (!_mv_1607.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqabox_unsat_at(slop_arena* arena, howl_sriqctx_Structure st, int64_t b) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = howl_sriqabox_set_at_ctx(arena, st, (2 + b));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if ((((int64_t)((c.head).len)) == 0) && howl_sriqabox_body_within(c, b)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_list_slop_rdf_rdf_IRI howl_sriqabox_unsat_classes(slop_arena* arena, howl_sriqctx_Structure st, slop_list_slop_rdf_rdf_IRI classes) {
    {
        __auto_type out = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t b = 0;
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                if (howl_sriqabox_unsat_at(arena, st, b)) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                b = (b + 1);
            }
        }
        return howl_canon_sort_iris(arena, out);
    }
}

slop_list_howl_types_SubPair howl_sriqabox_taxonomy(slop_arena* arena, howl_sriqctx_Structure st, slop_list_slop_rdf_rdf_IRI classes) {
    {
        __auto_type n = ((int64_t)(((int64_t)((classes).len))));
        __auto_type top = howl_types_node_top();
        __auto_type raw = ((slop_list_howl_types_SubPair){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t b = 0;
        (void)(({ __auto_type _lst_p = &(raw); __auto_type _item = (((howl_types_SubPair){.sub = top, .super = top})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        {
            __auto_type _coll = howl_sriqabox_holds_in(arena, st, 1, -1, n);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(raw); __auto_type _item = (((howl_types_SubPair){.sub = top, .super = howl_sriqabox_class_at(classes, a)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                {
                    __auto_type _coll = howl_sriqabox_class_rows(arena, st, classes, b, n);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type p = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(raw); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
                b = (b + 1);
            }
        }
        return howl_sriqabox_distinct_pairs(arena, howl_canon_sort_sub_pairs(arena, raw));
    }
}

slop_list_howl_types_SubPair howl_sriqabox_class_rows(slop_arena* arena, howl_sriqctx_Structure st, slop_list_slop_rdf_rdf_IRI classes, int64_t b, int64_t n) {
    {
        __auto_type me = howl_sriqabox_class_at(classes, b);
        __auto_type out = ((slop_list_howl_types_SubPair){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (howl_sriqabox_unsat_at(arena, st, b)) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_types_SubPair){.sub = me, .super = howl_types_node_bottom()})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        } else {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_types_SubPair){.sub = me, .super = howl_types_node_top()})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            {
                __auto_type _coll = howl_sriqabox_holds_in(arena, st, (2 + b), b, n);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_types_SubPair){.sub = me, .super = howl_sriqabox_class_at(classes, a)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

slop_list_int howl_sriqabox_holds_in(slop_arena* arena, howl_sriqctx_Structure st, int64_t v, int64_t b, int64_t n) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = howl_sriqabox_set_at_ctx(arena, st, v);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (howl_sriqabox_body_within(c, b)) {
                    {
                        __auto_type a = howl_sriqabox_head_class(c, n);
                        if (a >= 0) {
                            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        return out;
    }
}

howl_types_Node howl_sriqabox_class_at(slop_list_slop_rdf_rdf_IRI classes, int64_t a) {
    __auto_type _mv_1608 = ({ __auto_type _lst = classes; size_t _idx = (size_t)a; slop_option_slop_rdf_rdf_IRI _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1608.has_value) {
        __auto_type i = _mv_1608.value;
        return ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = i });
    } else if (!_mv_1608.has_value) {
        return howl_types_node_top();
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_SubPair howl_sriqabox_distinct_pairs(slop_arena* arena, slop_list_howl_types_SubPair ps) {
    {
        __auto_type out = ((slop_list_howl_types_SubPair){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                __auto_type _mv_1609 = ({ __auto_type _lst = out; size_t _idx = (size_t)(((int64_t)(((int64_t)((out).len)))) - 1); slop_option_howl_types_SubPair _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1609.has_value) {
                    __auto_type last = _mv_1609.value;
                    if (howl_canon_sub_pair_cmp(last, p) != 0) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                } else if (!_mv_1609.has_value) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

