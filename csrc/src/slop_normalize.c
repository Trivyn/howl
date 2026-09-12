#include "../runtime/slop_runtime.h"
#include "slop_normalize.h"

normalize_NormState* normalize_new_state(slop_arena* arena);
uint8_t normalize_st_emit(slop_arena* arena, normalize_NormState* p, types_NormAxiom ax);
uint8_t normalize_st_emit_edge(slop_arena* arena, normalize_NormState* p, types_LogicalEdge e);
int64_t normalize_str_index(slop_list_string xs, slop_string t);
int64_t normalize_st_fresh_id(slop_arena* arena, normalize_NormState* p, slop_string text);
int64_t normalize_st_fresh_role_id(slop_arena* arena, normalize_NormState* p, slop_string text);
uint8_t normalize_st_mark_neg(slop_arena* arena, normalize_NormState* p, slop_string text);
uint8_t normalize_st_mark_pos(slop_arena* arena, normalize_NormState* p, slop_string text);
owl2_RawConcept normalize_rc_of_node(types_Node n);
slop_list_owl2_RawConcept normalize_flatten_and(slop_arena* arena, owl2_RawConcept c, slop_list_owl2_RawConcept acc);
slop_string normalize_prefix_text(slop_arena* arena, slop_list_owl2_RawConcept conj, int64_t upto);
types_Node normalize_neg_atom(slop_arena* arena, normalize_NormState* p, owl2_RawConcept c);
types_Node normalize_fold_conjuncts(slop_arena* arena, normalize_NormState* p, slop_list_owl2_RawConcept conj, int64_t n);
types_Node normalize_pos_atom(slop_arena* arena, normalize_NormState* p, owl2_RawConcept c);
uint8_t normalize_emit_inclusion(slop_arena* arena, normalize_NormState* p, slop_list_owl2_RawConcept conj, int64_t n, types_Node target);
uint8_t normalize_normalize_gci(slop_arena* arena, normalize_NormState* p, owl2_RawConcept lhs, owl2_RawConcept rhs);
uint8_t normalize_decompose_chain(slop_arena* arena, normalize_NormState* p, owl2_RawChain ch);
types_RoleId normalize_role_at_n(slop_list_types_RoleId xs, int64_t i);
slop_string normalize_prefix_role_text(slop_arena* arena, slop_list_types_RoleId steps, int64_t upto, types_RoleId super);
slop_string normalize_render_role_name(types_RoleId r);
slop_list_normalize_RangeFact normalize_collect_range_facts(slop_arena* arena, normalize_NormState* p, slop_list_owl2_RawAxiom axs, slop_list_types_RoleId roles);
slop_list_types_Node normalize_ran_t(slop_arena* arena, slop_list_normalize_RangeFact facts, slop_list_u8 told, int64_t n, int64_t r);
uint8_t normalize_mat_get_b(slop_list_u8 m, int64_t i);
slop_string normalize_range_elim_key(slop_arena* arena, types_RoleId r, types_Node d);
slop_string normalize_render_node_name(types_Node n);
uint8_t normalize_eliminate_ranges(slop_arena* arena, normalize_NormState* p, slop_list_normalize_RangeFact facts, slop_list_u8 told, int64_t n, slop_list_types_RoleId roles);
slop_list_types_Addressed normalize_edge_range_seeds(slop_arena* arena, slop_list_types_LogicalEdge edges, slop_list_normalize_RangeFact facts, slop_list_u8 told, int64_t n, slop_list_types_RoleId roles);
uint8_t normalize_normalize_axiom(slop_arena* arena, normalize_NormState* p, owl2_RawAxiom ax);
owl2_RawConcept* normalize_box_rc(slop_arena* arena, owl2_RawConcept c);
normalize_NormOutput normalize_normalize_accepted(slop_arena* arena, slop_list_owl2_RawAxiom axs);
uint8_t normalize_node_in_list(slop_list_types_Node xs, types_Node n);
slop_list_types_Node normalize_signature_nodes(slop_arena* arena, owl2_Signature sig, normalize_NormOutput no);
uint8_t normalize_install_seeds(slop_arena* arena, types_Saturation sat, normalize_NormOutput no);
slop_result_normalize_NormResult_types_Fault normalize_normalize_input(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);

normalize_NormState* normalize_new_state(slop_arena* arena) {
    {
        __auto_type p = ((normalize_NormState*)(({ __auto_type _alloc = (normalize_NormState*)slop_arena_alloc(arena, sizeof(normalize_NormState)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = ((normalize_NormState){.axioms = ((slop_list_types_NormAxiom){ .data = (types_NormAxiom*)slop_arena_alloc(arena, 16 * sizeof(types_NormAxiom)), .len = 0, .cap = 16 }), .fresh = ((slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 16 * sizeof(slop_string)), .len = 0, .cap = 16 }), .fresh_roles = ((slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 16 * sizeof(slop_string)), .len = 0, .cap = 16 }), .neg_done = ((slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 16 * sizeof(slop_string)), .len = 0, .cap = 16 }), .pos_done = ((slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 16 * sizeof(slop_string)), .len = 0, .cap = 16 }), .edges = ((slop_list_types_LogicalEdge){ .data = (types_LogicalEdge*)slop_arena_alloc(arena, 16 * sizeof(types_LogicalEdge)), .len = 0, .cap = 16 })});
        return p;
    }
}

uint8_t normalize_st_emit(slop_arena* arena, normalize_NormState* p, types_NormAxiom ax) {
    {
        __auto_type s = (*p);
        ({ __auto_type _lst_p = &(s.axioms); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        (*p) = s;
        return 1;
    }
}

uint8_t normalize_st_emit_edge(slop_arena* arena, normalize_NormState* p, types_LogicalEdge e) {
    {
        __auto_type s = (*p);
        ({ __auto_type _lst_p = &(s.edges); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        (*p) = s;
        return 1;
    }
}

int64_t normalize_str_index(slop_list_string xs, slop_string t) {
    {
        int64_t found = -1;
        int64_t i = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if ((found < 0) && (canon_string_cmp(x, t) == 0)) {
                    found = i;
                }
                i = (i + 1);
            }
        }
        return found;
    }
}

int64_t normalize_st_fresh_id(slop_arena* arena, normalize_NormState* p, slop_string text) {
    {
        __auto_type existing = normalize_str_index((*p).fresh, text);
        if (existing >= 0) {
            return existing;
        } else {
            {
                __auto_type s = (*p);
                __auto_type id = ((int64_t)(((int64_t)(((*p).fresh).len))));
                ({ __auto_type _lst_p = &(s.fresh); __auto_type _item = (text); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                (*p) = s;
                return id;
            }
        }
    }
}

int64_t normalize_st_fresh_role_id(slop_arena* arena, normalize_NormState* p, slop_string text) {
    {
        __auto_type existing = normalize_str_index((*p).fresh_roles, text);
        if (existing >= 0) {
            return existing;
        } else {
            {
                __auto_type s = (*p);
                __auto_type id = ((int64_t)(((int64_t)(((*p).fresh_roles).len))));
                ({ __auto_type _lst_p = &(s.fresh_roles); __auto_type _item = (text); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                (*p) = s;
                return id;
            }
        }
    }
}

uint8_t normalize_st_mark_neg(slop_arena* arena, normalize_NormState* p, slop_string text) {
    {
        __auto_type s = (*p);
        ({ __auto_type _lst_p = &(s.neg_done); __auto_type _item = (text); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        (*p) = s;
        return 1;
    }
}

uint8_t normalize_st_mark_pos(slop_arena* arena, normalize_NormState* p, slop_string text) {
    {
        __auto_type s = (*p);
        ({ __auto_type _lst_p = &(s.pos_done); __auto_type _item = (text); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        (*p) = s;
        return 1;
    }
}

owl2_RawConcept normalize_rc_of_node(types_Node n) {
    return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_name, .data.rc_name = n });
}

slop_list_owl2_RawConcept normalize_flatten_and(slop_arena* arena, owl2_RawConcept c, slop_list_owl2_RawConcept acc) {
    {
        __auto_type out = acc;
        __auto_type _mv_412 = c;
        switch (_mv_412.tag) {
            case owl2_RawConcept_rc_and:
            {
                __auto_type cs = _mv_412.data.rc_and;
                {
                    __auto_type _coll = cs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        out = normalize_flatten_and(arena, x, out);
                    }
                }
                break;
            }
            case owl2_RawConcept_rc_thing:
            {
                break;
            }
            default: {
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
        }
        return out;
    }
}

slop_string normalize_prefix_text(slop_arena* arena, slop_list_owl2_RawConcept conj, int64_t upto) {
    {
        __auto_type pre = ((slop_list_owl2_RawConcept){ .data = (owl2_RawConcept*)slop_arena_alloc(arena, 16 * sizeof(owl2_RawConcept)), .len = 0, .cap = 16 });
        int64_t i = 0;
        while (i < upto) {
            ({ __auto_type _lst_p = &(pre); __auto_type _item = (owl2_concept_at(conj, i)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        return owl2_render_concept(arena, ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_and, .data.rc_and = pre }));
    }
}

types_Node normalize_neg_atom(slop_arena* arena, normalize_NormState* p, owl2_RawConcept c) {
    __auto_type _mv_413 = c;
    switch (_mv_413.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_413.data.rc_name;
            return n;
        }
        case owl2_RawConcept_rc_thing:
        {
            return types_node_top();
        }
        case owl2_RawConcept_rc_nothing:
        {
            return types_node_bottom();
        }
        case owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_413.data.rc_some.f0;
            __auto_type f = _mv_413.data.rc_some.f1;
            {
                __auto_type text = owl2_render_concept(arena, c);
                __auto_type x = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = normalize_st_fresh_id(arena, p, owl2_render_concept(arena, c)) });
                if (normalize_str_index((*p).neg_done, text) < 0) {
                    normalize_st_mark_neg(arena, p, text);
                    normalize_st_emit(arena, p, ((types_NormAxiom){ .tag = types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = r, .f1 = normalize_neg_atom(arena, p, (*f)), .f2 = x } }));
                }
                return x;
            }
        }
        case owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_413.data.rc_and;
            {
                __auto_type flat = normalize_flatten_and(arena, c, ((slop_list_owl2_RawConcept){ .data = (owl2_RawConcept*)slop_arena_alloc(arena, 16 * sizeof(owl2_RawConcept)), .len = 0, .cap = 16 }));
                __auto_type n = ((int64_t)(((int64_t)((normalize_flatten_and(arena, c, ((slop_list_owl2_RawConcept){ .data = (owl2_RawConcept*)slop_arena_alloc(arena, 16 * sizeof(owl2_RawConcept)), .len = 0, .cap = 16 }))).len))));
                if (n == 0) {
                    return types_node_top();
                } else if (n == 1) {
                    return normalize_neg_atom(arena, p, owl2_concept_at(flat, 0));
                } else {
                    return normalize_fold_conjuncts(arena, p, flat, n);
                }
            }
        }
        default: {
            return types_node_bottom();
        }
    }
}

types_Node normalize_fold_conjuncts(slop_arena* arena, normalize_NormState* p, slop_list_owl2_RawConcept conj, int64_t n) {
    {
        __auto_type acc = normalize_neg_atom(arena, p, owl2_concept_at(conj, 0));
        int64_t i = 1;
        while (i < n) {
            {
                __auto_type x = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = normalize_st_fresh_id(arena, p, normalize_prefix_text(arena, conj, (i + 1))) });
                normalize_st_emit(arena, p, ((types_NormAxiom){ .tag = types_NormAxiom_sub_and, .data.sub_and = { .f0 = acc, .f1 = normalize_neg_atom(arena, p, owl2_concept_at(conj, i)), .f2 = x } }));
                acc = x;
                i = (i + 1);
            }
        }
        return acc;
    }
}

types_Node normalize_pos_atom(slop_arena* arena, normalize_NormState* p, owl2_RawConcept c) {
    __auto_type _mv_414 = c;
    switch (_mv_414.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_414.data.rc_name;
            return n;
        }
        case owl2_RawConcept_rc_thing:
        {
            return types_node_top();
        }
        case owl2_RawConcept_rc_nothing:
        {
            return types_node_bottom();
        }
        default: {
            {
                __auto_type text = owl2_render_concept(arena, c);
                __auto_type x = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = normalize_st_fresh_id(arena, p, owl2_render_concept(arena, c)) });
                if (normalize_str_index((*p).pos_done, text) < 0) {
                    normalize_st_mark_pos(arena, p, text);
                    normalize_normalize_gci(arena, p, normalize_rc_of_node(x), c);
                }
                return x;
            }
        }
    }
}

uint8_t normalize_emit_inclusion(slop_arena* arena, normalize_NormState* p, slop_list_owl2_RawConcept conj, int64_t n, types_Node target) {
    if (n == 0) {
        return normalize_st_emit(arena, p, ((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = types_node_top(), .f1 = target } }));
    } else if (n == 1) {
        return normalize_st_emit(arena, p, ((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = normalize_neg_atom(arena, p, owl2_concept_at(conj, 0)), .f1 = target } }));
    } else if (n == 2) {
        return normalize_st_emit(arena, p, ((types_NormAxiom){ .tag = types_NormAxiom_sub_and, .data.sub_and = { .f0 = normalize_neg_atom(arena, p, owl2_concept_at(conj, 0)), .f1 = normalize_neg_atom(arena, p, owl2_concept_at(conj, 1)), .f2 = target } }));
    } else {
        {
            __auto_type acc = normalize_fold_conjuncts(arena, p, conj, (n - 1));
            return normalize_st_emit(arena, p, ((types_NormAxiom){ .tag = types_NormAxiom_sub_and, .data.sub_and = { .f0 = acc, .f1 = normalize_neg_atom(arena, p, owl2_concept_at(conj, (n - 1))), .f2 = target } }));
        }
    }
}

uint8_t normalize_normalize_gci(slop_arena* arena, normalize_NormState* p, owl2_RawConcept lhs, owl2_RawConcept rhs) {
    __auto_type _mv_415 = rhs;
    switch (_mv_415.tag) {
        case owl2_RawConcept_rc_and:
        {
            __auto_type ds = _mv_415.data.rc_and;
            {
                __auto_type ok = 1;
                {
                    __auto_type _coll = ds;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type d = _coll.data[_i];
                        ok = normalize_normalize_gci(arena, p, lhs, d);
                    }
                }
                return ok;
            }
        }
        case owl2_RawConcept_rc_thing:
        {
            return 1;
        }
        default: {
            {
                __auto_type conj = normalize_flatten_and(arena, lhs, ((slop_list_owl2_RawConcept){ .data = (owl2_RawConcept*)slop_arena_alloc(arena, 16 * sizeof(owl2_RawConcept)), .len = 0, .cap = 16 }));
                __auto_type n = ((int64_t)(((int64_t)((normalize_flatten_and(arena, lhs, ((slop_list_owl2_RawConcept){ .data = (owl2_RawConcept*)slop_arena_alloc(arena, 16 * sizeof(owl2_RawConcept)), .len = 0, .cap = 16 }))).len))));
                __auto_type _mv_416 = rhs;
                switch (_mv_416.tag) {
                    case owl2_RawConcept_rc_name:
                    {
                        __auto_type b = _mv_416.data.rc_name;
                        return normalize_emit_inclusion(arena, p, conj, n, b);
                    }
                    case owl2_RawConcept_rc_nothing:
                    {
                        return normalize_emit_inclusion(arena, p, conj, n, types_node_bottom());
                    }
                    case owl2_RawConcept_rc_some:
                    {
                        __auto_type r = _mv_416.data.rc_some.f0;
                        __auto_type f = _mv_416.data.rc_some.f1;
                        {
                            __auto_type bnode = normalize_pos_atom(arena, p, (*f));
                            __auto_type lnode = (((n == 1)) ? normalize_neg_atom(arena, p, owl2_concept_at(conj, 0)) : normalize_fold_conjuncts(arena, p, conj, n));
                            return normalize_st_emit(arena, p, ((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = lnode, .f1 = r, .f2 = bnode } }));
                        }
                    }
                    default: {
                        return 1;
                    }
                }
            }
        }
    }
}

uint8_t normalize_decompose_chain(slop_arena* arena, normalize_NormState* p, owl2_RawChain ch) {
    {
        __auto_type steps = ch.steps;
        __auto_type len = ((int64_t)(((int64_t)((ch.steps).len))));
        if (len < 2) {
            return 1;
        } else if (len == 2) {
            return normalize_st_emit(arena, p, ((types_NormAxiom){ .tag = types_NormAxiom_role_chain, .data.role_chain = { .f0 = normalize_role_at_n(steps, 0), .f1 = normalize_role_at_n(steps, 1), .f2 = ch.super } }));
        } else {
            {
                __auto_type acc = normalize_role_at_n(steps, 0);
                int64_t i = 1;
                while (i < (len - 1)) {
                    {
                        __auto_type f = ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = normalize_st_fresh_role_id(arena, p, normalize_prefix_role_text(arena, steps, (i + 1), ch.super)) });
                        normalize_st_emit(arena, p, ((types_NormAxiom){ .tag = types_NormAxiom_role_chain, .data.role_chain = { .f0 = acc, .f1 = normalize_role_at_n(steps, i), .f2 = f } }));
                        acc = f;
                        i = (i + 1);
                    }
                }
                return normalize_st_emit(arena, p, ((types_NormAxiom){ .tag = types_NormAxiom_role_chain, .data.role_chain = { .f0 = acc, .f1 = normalize_role_at_n(steps, (len - 1)), .f2 = ch.super } }));
            }
        }
    }
}

types_RoleId normalize_role_at_n(slop_list_types_RoleId xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_417 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_417.has_value) {
        __auto_type v = _mv_417.value;
        return v;
    } else if (!_mv_417.has_value) {
        return ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_string normalize_prefix_role_text(slop_arena* arena, slop_list_types_RoleId steps, int64_t upto, types_RoleId super) {
    {
        __auto_type out = SLOP_STR("chain:");
        int64_t i = 0;
        while (i < upto) {
            out = string_concat(arena, out, string_concat(arena, normalize_render_role_name(normalize_role_at_n(steps, i)), SLOP_STR(".")));
            i = (i + 1);
        }
        return string_concat(arena, out, string_concat(arena, SLOP_STR("=>"), normalize_render_role_name(super)));
    }
}

slop_string normalize_render_role_name(types_RoleId r) {
    __auto_type _mv_418 = r;
    switch (_mv_418.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_418.data.named_role;
            return i.value;
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_418.data.fresh_role;
            return SLOP_STR("_:fresh");
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_normalize_RangeFact normalize_collect_range_facts(slop_arena* arena, normalize_NormState* p, slop_list_owl2_RawAxiom axs, slop_list_types_RoleId roles) {
    {
        __auto_type out = ((slop_list_normalize_RangeFact){ .data = (normalize_RangeFact*)slop_arena_alloc(arena, 16 * sizeof(normalize_RangeFact)), .len = 0, .cap = 16 });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_419 = ax;
                switch (_mv_419.tag) {
                    case owl2_RawAxiom_ra_object_property_range:
                    {
                        __auto_type r = _mv_419.data.ra_object_property_range.f0;
                        __auto_type c = _mv_419.data.ra_object_property_range.f1;
                        {
                            __auto_type ir = gate_role_idx(roles, r);
                            if (ir >= 0) {
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (((normalize_RangeFact){.role = ir, .filler = normalize_pos_atom(arena, p, (*c))})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        return out;
    }
}

slop_list_types_Node normalize_ran_t(slop_arena* arena, slop_list_normalize_RangeFact facts, slop_list_u8 told, int64_t n, int64_t r) {
    {
        __auto_type out = ((slop_list_types_Node){ .data = (types_Node*)slop_arena_alloc(arena, 16 * sizeof(types_Node)), .len = 0, .cap = 16 });
        if (r >= 0) {
            {
                __auto_type _coll = facts;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type f = _coll.data[_i];
                    if (normalize_mat_get_b(told, ((r * n) + f.role))) {
                        {
                            uint8_t dup = 0;
                            {
                                __auto_type _coll = out;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type x = _coll.data[_i];
                                    if (types_node_eq(x, f.filler)) {
                                        dup = 1;
                                    }
                                }
                            }
                            if (!(dup)) {
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (f.filler); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
            }
        }
        return out;
    }
}

uint8_t normalize_mat_get_b(slop_list_u8 m, int64_t i) {
    __auto_type _mv_420 = ({ __auto_type _lst = m; size_t _idx = (size_t)i; slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_420.has_value) {
        __auto_type v = _mv_420.value;
        return v;
    } else if (!_mv_420.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string normalize_range_elim_key(slop_arena* arena, types_RoleId r, types_Node d) {
    return string_concat(arena, SLOP_STR("range-elim:"), string_concat(arena, normalize_render_role_name(r), string_concat(arena, SLOP_STR(":"), normalize_render_node_name(d))));
}

slop_string normalize_render_node_name(types_Node n) {
    __auto_type _mv_421 = n;
    switch (_mv_421.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_421.data.class_node;
            return i.value;
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_421.data.individual_node;
            return i.value;
        }
        case types_Node_fresh_node:
        {
            __auto_type k = _mv_421.data.fresh_node;
            return SLOP_STR("_:fresh");
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t normalize_eliminate_ranges(slop_arena* arena, normalize_NormState* p, slop_list_normalize_RangeFact facts, slop_list_u8 told, int64_t n, slop_list_types_RoleId roles) {
    {
        __auto_type rebuilt = ((slop_list_types_NormAxiom){ .data = (types_NormAxiom*)slop_arena_alloc(arena, 16 * sizeof(types_NormAxiom)), .len = 0, .cap = 16 });
        __auto_type existing = (*p).axioms;
        {
            __auto_type _coll = existing;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_422 = ax;
                switch (_mv_422.tag) {
                    case types_NormAxiom_sub_some_rhs:
                    {
                        __auto_type c = _mv_422.data.sub_some_rhs.f0;
                        __auto_type r = _mv_422.data.sub_some_rhs.f1;
                        __auto_type d = _mv_422.data.sub_some_rhs.f2;
                        {
                            __auto_type fillers = normalize_ran_t(arena, facts, told, n, gate_role_idx(roles, r));
                            if (((int64_t)(((int64_t)((fillers).len)))) == 0) {
                                ({ __auto_type _lst_p = &(rebuilt); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else {
                                {
                                    __auto_type x = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = normalize_st_fresh_id(arena, p, normalize_range_elim_key(arena, r, d)) });
                                    ({ __auto_type _lst_p = &(rebuilt); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = c, .f1 = r, .f2 = x } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    ({ __auto_type _lst_p = &(rebuilt); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = x, .f1 = d } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    {
                                        __auto_type _coll = fillers;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type a = _coll.data[_i];
                                            ({ __auto_type _lst_p = &(rebuilt); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = x, .f1 = a } })); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                    default: {
                        ({ __auto_type _lst_p = &(rebuilt); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                }
            }
        }
        {
            __auto_type s = (*p);
            s.axioms = rebuilt;
            (*p) = s;
            return 1;
        }
    }
}

slop_list_types_Addressed normalize_edge_range_seeds(slop_arena* arena, slop_list_types_LogicalEdge edges, slop_list_normalize_RangeFact facts, slop_list_u8 told, int64_t n, slop_list_types_RoleId roles) {
    {
        __auto_type out = ((slop_list_types_Addressed){ .data = (types_Addressed*)slop_arena_alloc(arena, 16 * sizeof(types_Addressed)), .len = 0, .cap = 16 });
        {
            __auto_type _coll = edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                {
                    __auto_type _coll = normalize_ran_t(arena, facts, told, n, gate_role_idx(roles, e.role));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type a = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_Addressed){.to = e.to, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = a })})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

uint8_t normalize_normalize_axiom(slop_arena* arena, normalize_NormState* p, owl2_RawAxiom ax) {
    __auto_type _mv_423 = ax;
    switch (_mv_423.tag) {
        case owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_423.data.ra_sub_class_of.f0;
            __auto_type r = _mv_423.data.ra_sub_class_of.f1;
            return normalize_normalize_gci(arena, p, (*l), (*r));
        }
        case owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_423.data.ra_disjoint_classes;
            return normalize_normalize_gci(arena, p, ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_and, .data.rc_and = cs }), ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_nothing }));
        }
        case owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_423.data.ra_object_property_domain.f0;
            __auto_type c = _mv_423.data.ra_object_property_domain.f1;
            {
                __auto_type top_c = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_thing });
                return normalize_normalize_gci(arena, p, ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_some, .data.rc_some = { .f0 = r, .f1 = normalize_box_rc(arena, top_c) } }), (*c));
            }
        }
        case owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type a = _mv_423.data.ra_sub_object_property.f0;
            __auto_type b = _mv_423.data.ra_sub_object_property.f1;
            return normalize_st_emit(arena, p, ((types_NormAxiom){ .tag = types_NormAxiom_sub_role, .data.sub_role = { .f0 = a, .f1 = b } }));
        }
        case owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_423.data.ra_property_chain;
            return normalize_decompose_chain(arena, p, ch);
        }
        case owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_423.data.ra_class_assertion;
            return normalize_normalize_gci(arena, p, normalize_rc_of_node(ca.subject), (*ca.concept));
        }
        case owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type e = _mv_423.data.ra_object_property_assertion;
            return normalize_st_emit_edge(arena, p, ((types_LogicalEdge){.from = e.from, .role = e.role, .to = e.to}));
        }
        default: {
            return 1;
        }
    }
}

owl2_RawConcept* normalize_box_rc(slop_arena* arena, owl2_RawConcept c) {
    {
        __auto_type q = ((owl2_RawConcept*)(({ __auto_type _alloc = (owl2_RawConcept*)slop_arena_alloc(arena, sizeof(owl2_RawConcept)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*q) = c;
        return q;
    }
}

normalize_NormOutput normalize_normalize_accepted(slop_arena* arena, slop_list_owl2_RawAxiom axs) {
    {
        __auto_type p = normalize_new_state(arena);
        __auto_type roles = gate_collect_rbox_roles(arena, axs);
        __auto_type nr = ((int64_t)(((int64_t)((gate_collect_rbox_roles(arena, axs)).len))));
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                normalize_normalize_axiom(arena, p, ax);
            }
        }
        {
            __auto_type told = gate_told_closure(arena, axs, roles, nr);
            __auto_type facts = normalize_collect_range_facts(arena, p, axs, roles);
            normalize_eliminate_ranges(arena, p, facts, told, nr, roles);
            return ((normalize_NormOutput){.axioms = (*p).axioms, .edges = (*p).edges, .seeds = normalize_edge_range_seeds(arena, (*p).edges, facts, told, nr, roles), .fresh_count = ((int64_t)(((int64_t)(((*p).fresh).len))))});
        }
    }
}

uint8_t normalize_node_in_list(slop_list_types_Node xs, types_Node n) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (types_node_eq(x, n)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_list_types_Node normalize_signature_nodes(slop_arena* arena, owl2_Signature sig, normalize_NormOutput no) {
    {
        __auto_type out = ((slop_list_types_Node){ .data = (types_Node*)slop_arena_alloc(arena, 16 * sizeof(types_Node)), .len = 0, .cap = 16 });
        int64_t i = 0;
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.classes); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type n = ((types_Node){ .tag = types_Node_class_node, .data.class_node = c });
                    if (!(normalize_node_in_list(out, n))) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.individuals); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    __auto_type n = ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = a });
                    if (!(normalize_node_in_list(out, n))) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type _coll = no.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (!(normalize_node_in_list(out, e.from))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (e.from); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                if (!(normalize_node_in_list(out, e.to))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (e.to); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type _coll = no.seeds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type sd = _coll.data[_i];
                if (!(normalize_node_in_list(out, sd.to))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (sd.to); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        while (i < no.fresh_count) {
            {
                __auto_type n = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = i });
                if (!(normalize_node_in_list(out, n))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                i = (i + 1);
            }
        }
        return out;
    }
}

uint8_t normalize_install_seeds(slop_arena* arena, types_Saturation sat, normalize_NormOutput no) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = no.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                {
                    __auto_type pair = types_emit_edge(arena, e);
                    if (!(saturate_deliver_seed(arena, sat, pair.succ_half.to, pair.succ_half.what))) {
                        ok = 0;
                    }
                    if (!(saturate_deliver_seed(arena, sat, pair.pred_half.to, pair.pred_half.what))) {
                        ok = 0;
                    }
                }
            }
        }
        {
            __auto_type _coll = no.seeds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type sd = _coll.data[_i];
                if (!(saturate_deliver_seed(arena, sat, sd.to, sd.what))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

slop_result_normalize_NormResult_types_Fault normalize_normalize_input(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config) {
    __auto_type _mv_424 = decode_stage0_header(arena, triples, imports_resolved);
    if (!_mv_424.is_ok) {
        __auto_type f = _mv_424.data.err;
        return ((slop_result_normalize_NormResult_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_424.is_ok) {
        __auto_type s0 = _mv_424.data.ok;
        __auto_type _mv_425 = decode_decode_axioms(arena, s0.triples);
        if (!_mv_425.is_ok) {
            __auto_type f = _mv_425.data.err;
            return ((slop_result_normalize_NormResult_types_Fault){ .is_ok = false, .data.err = f });
        } else if (_mv_425.is_ok) {
            __auto_type s1 = _mv_425.data.ok;
            {
                __auto_type gr = gate_gate_axioms(arena, s1.axioms, s1.signature, s0.omissions);
                __auto_type no = normalize_normalize_accepted(arena, gate_gate_axioms(arena, s1.axioms, s1.signature, s0.omissions).accepted);
                {
                    __auto_type sat = saturate_make_initial_saturation(arena, normalize_signature_nodes(arena, gr.signature, no));
                    normalize_install_seeds(arena, sat, no);
                    return ((slop_result_normalize_NormResult_types_Fault){ .is_ok = true, .data.ok = ((normalize_NormResult){.axioms = no.axioms, .saturation = sat, .coverage = ((types_Coverage){.omitted = gr.omissions})}) });
                }
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

