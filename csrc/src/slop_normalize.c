#include "../runtime/slop_runtime.h"
#include "slop_normalize.h"

howl_normalize_NormState* howl_normalize_new_state(slop_arena* arena);
uint8_t howl_normalize_st_emit(slop_arena* arena, howl_normalize_NormState* p, howl_types_NormAxiom ax);
uint8_t howl_normalize_st_emit_edge(slop_arena* arena, howl_normalize_NormState* p, howl_types_LogicalEdge e);
uint8_t howl_normalize_st_note_asserted(slop_arena* arena, howl_normalize_NormState* p, howl_types_Node n);
int64_t howl_normalize_st_fresh_id(slop_arena* arena, howl_normalize_NormState* p, slop_string text);
int64_t howl_normalize_st_fresh_role_id(slop_arena* arena, howl_normalize_NormState* p, slop_string text);
uint8_t howl_normalize_st_mark_neg(slop_arena* arena, howl_normalize_NormState* p, slop_string text);
uint8_t howl_normalize_st_mark_pos(slop_arena* arena, howl_normalize_NormState* p, slop_string text);
howl_owl2_RawConcept howl_normalize_rc_of_node(howl_types_Node n);
howl_types_Node howl_normalize_neg_atom(slop_arena* arena, howl_normalize_NormState* p, howl_owl2_RawConcept c);
howl_types_Node howl_normalize_fold_conjuncts(slop_arena* arena, howl_normalize_NormState* p, slop_list_howl_owl2_RawConcept conj, int64_t n);
howl_types_Node howl_normalize_pos_atom(slop_arena* arena, howl_normalize_NormState* p, howl_owl2_RawConcept c);
uint8_t howl_normalize_emit_inclusion(slop_arena* arena, howl_normalize_NormState* p, slop_list_howl_owl2_RawConcept conj, int64_t n, howl_types_Node target);
uint8_t howl_normalize_normalize_gci(slop_arena* arena, howl_normalize_NormState* p, howl_owl2_RawConcept lhs, howl_owl2_RawConcept rhs);
uint8_t howl_normalize_decompose_chain(slop_arena* arena, howl_normalize_NormState* p, howl_owl2_RawChain ch);
slop_list_howl_normalize_RangeFact howl_normalize_collect_range_facts(slop_arena* arena, howl_normalize_NormState* p, slop_list_howl_owl2_RawAxiom axs, slop_list_howl_types_RoleId roles);
slop_list_howl_types_Node howl_normalize_ran_t(slop_arena* arena, slop_list_howl_normalize_RangeFact facts, slop_list_u8 told, int64_t n, int64_t r);
uint8_t howl_normalize_mat_get_b(slop_list_u8 m, int64_t i);
slop_string howl_normalize_range_elim_key(slop_arena* arena, howl_types_RoleId r, howl_types_Node d);
slop_string howl_normalize_render_node_name(slop_arena* arena, howl_types_Node n);
uint8_t howl_normalize_eliminate_ranges(slop_arena* arena, howl_normalize_NormState* p, slop_list_howl_normalize_RangeFact facts, slop_list_u8 told, int64_t n, slop_list_howl_types_RoleId roles);
slop_list_howl_types_Addressed howl_normalize_edge_range_seeds(slop_arena* arena, slop_list_howl_types_LogicalEdge edges, slop_list_howl_normalize_RangeFact facts, slop_list_u8 told, int64_t n, slop_list_howl_types_RoleId roles);
uint8_t howl_normalize_normalize_axiom(slop_arena* arena, howl_normalize_NormState* p, howl_owl2_RawAxiom ax);
howl_owl2_RawConcept* howl_normalize_box_rc(slop_arena* arena, howl_owl2_RawConcept c);
howl_normalize_NormOutput howl_normalize_normalize_accepted(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
howl_types_Node howl_normalize_ex_stewie(void);
howl_normalize_NormOutput howl_normalize_ex_asserting_stewie(slop_arena* arena);
howl_owl2_Signature howl_normalize_ex_declaring_stewie(slop_arena* arena);
slop_list_howl_types_Node howl_normalize_signature_nodes(slop_arena* arena, howl_owl2_Signature sig, howl_normalize_NormOutput no);
uint8_t howl_normalize_install_seeds(slop_arena* arena, howl_types_Saturation sat, howl_normalize_NormOutput no);
howl_types_NormAxiom howl_normalize_rename_axiom(slop_arena* arena, howl_types_Names names, howl_types_NormAxiom ax);
howl_types_Derived howl_normalize_rename_derived(slop_arena* arena, howl_types_Names names, howl_types_Derived d);
slop_list_howl_types_Node howl_normalize_rename_nodes(slop_arena* arena, howl_types_Names names, slop_list_howl_types_Node ns);
howl_normalize_NormOutput howl_normalize_rename_output(slop_arena* arena, howl_types_Names names, howl_normalize_NormOutput no);
slop_result_howl_normalize_Decoded_howl_types_Fault howl_normalize_decode_document(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved);
slop_result_howl_normalize_Decoded_howl_types_Fault howl_normalize_decode_encoded(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved);
howl_normalize_Decoded howl_normalize_copy_decoded(slop_arena* arena, howl_normalize_Decoded d);
slop_list_int howl_normalize_copy_ints(slop_arena* arena, slop_list_int xs);
howl_normalize_NormResult howl_normalize_normalize_decoded(slop_arena* arena, slop_arena* scratch, howl_normalize_Decoded d);
slop_result_howl_normalize_NormResult_howl_types_Fault howl_normalize_normalize_input(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config);

howl_normalize_NormState* howl_normalize_new_state(slop_arena* arena) {
    {
        __auto_type p = ((howl_normalize_NormState*)(({ __auto_type _alloc = (howl_normalize_NormState*)slop_arena_alloc(arena, sizeof(howl_normalize_NormState)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = ((howl_normalize_NormState){.axioms = ((slop_list_howl_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .registry = howl_naming_new_registry(arena), .edges = ((slop_list_howl_types_LogicalEdge){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .asserted = ((slop_list_howl_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
        return p;
    }
}

uint8_t howl_normalize_st_emit(slop_arena* arena, howl_normalize_NormState* p, howl_types_NormAxiom ax) {
    {
        __auto_type s = (*p);
        (void)(({ __auto_type _lst_p = &(s.axioms); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (*p) = s;
        return 1;
    }
}

uint8_t howl_normalize_st_emit_edge(slop_arena* arena, howl_normalize_NormState* p, howl_types_LogicalEdge e) {
    {
        __auto_type s = (*p);
        (void)(({ __auto_type _lst_p = &(s.edges); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (*p) = s;
        return 1;
    }
}

uint8_t howl_normalize_st_note_asserted(slop_arena* arena, howl_normalize_NormState* p, howl_types_Node n) {
    {
        __auto_type s = (*p);
        (void)(({ __auto_type _lst_p = &(s.asserted); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (*p) = s;
        return 1;
    }
}

int64_t howl_normalize_st_fresh_id(slop_arena* arena, howl_normalize_NormState* p, slop_string text) {
    return howl_naming_fresh_id(arena, (*p).registry, text);
}

int64_t howl_normalize_st_fresh_role_id(slop_arena* arena, howl_normalize_NormState* p, slop_string text) {
    return howl_naming_fresh_role_id(arena, (*p).registry, text);
}

uint8_t howl_normalize_st_mark_neg(slop_arena* arena, howl_normalize_NormState* p, slop_string text) {
    return howl_naming_mark_neg(arena, (*p).registry, text);
}

uint8_t howl_normalize_st_mark_pos(slop_arena* arena, howl_normalize_NormState* p, slop_string text) {
    return howl_naming_mark_pos(arena, (*p).registry, text);
}

howl_owl2_RawConcept howl_normalize_rc_of_node(howl_types_Node n) {
    return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_name, .data.rc_name = n });
}

howl_types_Node howl_normalize_neg_atom(slop_arena* arena, howl_normalize_NormState* p, howl_owl2_RawConcept c) {
    __auto_type _mv_1402 = c;
    switch (_mv_1402.tag) {
        case howl_owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_1402.data.rc_name;
            return n;
        }
        case howl_owl2_RawConcept_rc_thing:
        {
            return howl_types_node_top();
        }
        case howl_owl2_RawConcept_rc_nothing:
        {
            return howl_types_node_bottom();
        }
        case howl_owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_1402.data.rc_some.f0;
            __auto_type f = _mv_1402.data.rc_some.f1;
            {
                __auto_type text = howl_naming_concept_key(arena, c);
                __auto_type x = ((howl_types_Node){ .tag = howl_types_Node_fresh_node, .data.fresh_node = howl_normalize_st_fresh_id(arena, p, text) });
                if (!(howl_naming_neg_defined((*p).registry, text))) {
                    howl_normalize_st_mark_neg(arena, p, text);
                    howl_normalize_st_emit(arena, p, ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = r, .f1 = howl_normalize_neg_atom(arena, p, (*f)), .f2 = x } }));
                }
                return x;
            }
        }
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_1402.data.rc_and;
            {
                __auto_type flat = howl_naming_flatten_and(arena, c, ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
                __auto_type n = ((int64_t)(((int64_t)((flat).len))));
                if (n == 0) {
                    return howl_types_node_top();
                } else if (n == 1) {
                    return howl_normalize_neg_atom(arena, p, howl_owl2_concept_at(flat, 0));
                } else {
                    return howl_normalize_fold_conjuncts(arena, p, flat, n);
                }
            }
        }
        default: {
            return howl_types_node_bottom();
        }
    }
}

howl_types_Node howl_normalize_fold_conjuncts(slop_arena* arena, howl_normalize_NormState* p, slop_list_howl_owl2_RawConcept conj, int64_t n) {
    {
        __auto_type acc = howl_normalize_neg_atom(arena, p, howl_owl2_concept_at(conj, 0));
        int64_t i = 1;
        while (i < n) {
            {
                __auto_type x = ((howl_types_Node){ .tag = howl_types_Node_fresh_node, .data.fresh_node = howl_normalize_st_fresh_id(arena, p, howl_naming_prefix_text(arena, conj, (i + 1))) });
                howl_normalize_st_emit(arena, p, ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_and, .data.sub_and = { .f0 = acc, .f1 = howl_normalize_neg_atom(arena, p, howl_owl2_concept_at(conj, i)), .f2 = x } }));
                acc = x;
                i = (i + 1);
            }
        }
        return acc;
    }
}

howl_types_Node howl_normalize_pos_atom(slop_arena* arena, howl_normalize_NormState* p, howl_owl2_RawConcept c) {
    __auto_type _mv_1403 = c;
    switch (_mv_1403.tag) {
        case howl_owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_1403.data.rc_name;
            return n;
        }
        case howl_owl2_RawConcept_rc_thing:
        {
            return howl_types_node_top();
        }
        case howl_owl2_RawConcept_rc_nothing:
        {
            return howl_types_node_bottom();
        }
        default: {
            {
                __auto_type text = howl_naming_concept_key(arena, c);
                __auto_type x = ((howl_types_Node){ .tag = howl_types_Node_fresh_node, .data.fresh_node = howl_normalize_st_fresh_id(arena, p, text) });
                if (!(howl_naming_pos_defined((*p).registry, text))) {
                    howl_normalize_st_mark_pos(arena, p, text);
                    howl_normalize_normalize_gci(arena, p, howl_normalize_rc_of_node(x), c);
                }
                return x;
            }
        }
    }
}

uint8_t howl_normalize_emit_inclusion(slop_arena* arena, howl_normalize_NormState* p, slop_list_howl_owl2_RawConcept conj, int64_t n, howl_types_Node target) {
    if (n == 0) {
        return howl_normalize_st_emit(arena, p, ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_name, .data.sub_name = { .f0 = howl_types_node_top(), .f1 = target } }));
    } else if (n == 1) {
        return howl_normalize_st_emit(arena, p, ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_name, .data.sub_name = { .f0 = howl_normalize_neg_atom(arena, p, howl_owl2_concept_at(conj, 0)), .f1 = target } }));
    } else if (n == 2) {
        return howl_normalize_st_emit(arena, p, ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_and, .data.sub_and = { .f0 = howl_normalize_neg_atom(arena, p, howl_owl2_concept_at(conj, 0)), .f1 = howl_normalize_neg_atom(arena, p, howl_owl2_concept_at(conj, 1)), .f2 = target } }));
    } else {
        {
            __auto_type acc = howl_normalize_fold_conjuncts(arena, p, conj, (n - 1));
            return howl_normalize_st_emit(arena, p, ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_and, .data.sub_and = { .f0 = acc, .f1 = howl_normalize_neg_atom(arena, p, howl_owl2_concept_at(conj, (n - 1))), .f2 = target } }));
        }
    }
}

uint8_t howl_normalize_normalize_gci(slop_arena* arena, howl_normalize_NormState* p, howl_owl2_RawConcept lhs, howl_owl2_RawConcept rhs) {
    __auto_type _mv_1404 = rhs;
    switch (_mv_1404.tag) {
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type ds = _mv_1404.data.rc_and;
            {
                uint8_t ok = 1;
                {
                    __auto_type _coll = ds;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type d = _coll.data[_i];
                        ok = howl_normalize_normalize_gci(arena, p, lhs, d);
                    }
                }
                return ok;
            }
        }
        case howl_owl2_RawConcept_rc_thing:
        {
            return 1;
        }
        default: {
            {
                __auto_type conj = howl_naming_flatten_and(arena, lhs, ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
                __auto_type n = ((int64_t)(((int64_t)((conj).len))));
                __auto_type _mv_1405 = rhs;
                switch (_mv_1405.tag) {
                    case howl_owl2_RawConcept_rc_name:
                    {
                        __auto_type b = _mv_1405.data.rc_name;
                        return howl_normalize_emit_inclusion(arena, p, conj, n, b);
                    }
                    case howl_owl2_RawConcept_rc_nothing:
                    {
                        return howl_normalize_emit_inclusion(arena, p, conj, n, howl_types_node_bottom());
                    }
                    case howl_owl2_RawConcept_rc_some:
                    {
                        __auto_type r = _mv_1405.data.rc_some.f0;
                        __auto_type f = _mv_1405.data.rc_some.f1;
                        {
                            __auto_type bnode = howl_normalize_pos_atom(arena, p, (*f));
                            __auto_type lnode = (((n == 1)) ? howl_normalize_neg_atom(arena, p, howl_owl2_concept_at(conj, 0)) : howl_normalize_fold_conjuncts(arena, p, conj, n));
                            return howl_normalize_st_emit(arena, p, ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = lnode, .f1 = r, .f2 = bnode } }));
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

uint8_t howl_normalize_decompose_chain(slop_arena* arena, howl_normalize_NormState* p, howl_owl2_RawChain ch) {
    {
        __auto_type steps = ch.steps;
        __auto_type len = ((int64_t)(((int64_t)((ch.steps).len))));
        if (len < 2) {
            return 1;
        } else if (len == 2) {
            return howl_normalize_st_emit(arena, p, ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_role_chain, .data.role_chain = { .f0 = howl_naming_role_at_n(steps, 0), .f1 = howl_naming_role_at_n(steps, 1), .f2 = ch.super } }));
        } else {
            {
                __auto_type acc = howl_naming_role_at_n(steps, 0);
                int64_t i = 1;
                while (i < (len - 1)) {
                    {
                        __auto_type f = ((howl_types_RoleId){ .tag = howl_types_RoleId_fresh_role, .data.fresh_role = howl_normalize_st_fresh_role_id(arena, p, howl_naming_prefix_role_text(arena, steps, (i + 1), ch.super)) });
                        howl_normalize_st_emit(arena, p, ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_role_chain, .data.role_chain = { .f0 = acc, .f1 = howl_naming_role_at_n(steps, i), .f2 = f } }));
                        acc = f;
                        i = (i + 1);
                    }
                }
                return howl_normalize_st_emit(arena, p, ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_role_chain, .data.role_chain = { .f0 = acc, .f1 = howl_naming_role_at_n(steps, (len - 1)), .f2 = ch.super } }));
            }
        }
    }
}

slop_list_howl_normalize_RangeFact howl_normalize_collect_range_facts(slop_arena* arena, howl_normalize_NormState* p, slop_list_howl_owl2_RawAxiom axs, slop_list_howl_types_RoleId roles) {
    {
        __auto_type out = ((slop_list_howl_normalize_RangeFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1406 = ax;
                switch (_mv_1406.tag) {
                    case howl_owl2_RawAxiom_ra_object_property_range:
                    {
                        __auto_type r = _mv_1406.data.ra_object_property_range.f0;
                        __auto_type c = _mv_1406.data.ra_object_property_range.f1;
                        {
                            __auto_type ir = howl_gate_role_idx(roles, r);
                            if (ir >= 0) {
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_normalize_RangeFact){.role = ir, .filler = howl_normalize_pos_atom(arena, p, (*c))})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

slop_list_howl_types_Node howl_normalize_ran_t(slop_arena* arena, slop_list_howl_normalize_RangeFact facts, slop_list_u8 told, int64_t n, int64_t r) {
    {
        __auto_type out = ((slop_list_howl_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (r >= 0) {
            {
                __auto_type _coll = facts;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type f = _coll.data[_i];
                    if (howl_normalize_mat_get_b(told, ((r * n) + f.role))) {
                        {
                            uint8_t dup = 0;
                            {
                                __auto_type _coll = out;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type x = _coll.data[_i];
                                    if (howl_types_node_eq(x, f.filler)) {
                                        dup = 1;
                                    }
                                }
                            }
                            if (!(dup)) {
                                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (f.filler); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                        }
                    }
                }
            }
        }
        return out;
    }
}

uint8_t howl_normalize_mat_get_b(slop_list_u8 m, int64_t i) {
    __auto_type _mv_1407 = ({ __auto_type _lst = m; size_t _idx = (size_t)i; slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1407.has_value) {
        __auto_type v = _mv_1407.value;
        return v;
    } else if (!_mv_1407.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string howl_normalize_range_elim_key(slop_arena* arena, howl_types_RoleId r, howl_types_Node d) {
    return string_concat(arena, SLOP_STR("range-elim "), string_concat(arena, howl_naming_render_role_name(arena, r), string_concat(arena, SLOP_STR(" "), howl_normalize_render_node_name(arena, d))));
}

slop_string howl_normalize_render_node_name(slop_arena* arena, howl_types_Node n) {
    __auto_type _mv_1408 = n;
    switch (_mv_1408.tag) {
        case howl_types_Node_class_node:
        {
            __auto_type i = _mv_1408.data.class_node;
            return i.value;
        }
        case howl_types_Node_individual_node:
        {
            __auto_type i = _mv_1408.data.individual_node;
            return string_concat(arena, SLOP_STR("{"), string_concat(arena, i.value, SLOP_STR("}")));
        }
        case howl_types_Node_fresh_node:
        {
            __auto_type k = _mv_1408.data.fresh_node;
            return string_concat(arena, SLOP_STR("_:fresh"), int_to_string(arena, k));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_normalize_eliminate_ranges(slop_arena* arena, howl_normalize_NormState* p, slop_list_howl_normalize_RangeFact facts, slop_list_u8 told, int64_t n, slop_list_howl_types_RoleId roles) {
    {
        __auto_type rebuilt = ((slop_list_howl_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type existing = (*p).axioms;
        {
            __auto_type _coll = existing;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1409 = ax;
                switch (_mv_1409.tag) {
                    case howl_types_NormAxiom_sub_some_rhs:
                    {
                        __auto_type c = _mv_1409.data.sub_some_rhs.f0;
                        __auto_type r = _mv_1409.data.sub_some_rhs.f1;
                        __auto_type d = _mv_1409.data.sub_some_rhs.f2;
                        {
                            __auto_type fillers = howl_normalize_ran_t(arena, facts, told, n, howl_gate_role_idx(roles, r));
                            if (((int64_t)(((int64_t)((fillers).len)))) == 0) {
                                ({ __auto_type _lst_p = &(rebuilt); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else {
                                {
                                    __auto_type x = ((howl_types_Node){ .tag = howl_types_Node_fresh_node, .data.fresh_node = howl_normalize_st_fresh_id(arena, p, howl_normalize_range_elim_key(arena, r, d)) });
                                    ({ __auto_type _lst_p = &(rebuilt); __auto_type _item = (((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = c, .f1 = r, .f2 = x } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    ({ __auto_type _lst_p = &(rebuilt); __auto_type _item = (((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_name, .data.sub_name = { .f0 = x, .f1 = d } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    {
                                        __auto_type _coll = fillers;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type a = _coll.data[_i];
                                            ({ __auto_type _lst_p = &(rebuilt); __auto_type _item = (((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_name, .data.sub_name = { .f0 = x, .f1 = a } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                    default: {
                        ({ __auto_type _lst_p = &(rebuilt); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

slop_list_howl_types_Addressed howl_normalize_edge_range_seeds(slop_arena* arena, slop_list_howl_types_LogicalEdge edges, slop_list_howl_normalize_RangeFact facts, slop_list_u8 told, int64_t n, slop_list_howl_types_RoleId roles) {
    {
        __auto_type out = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                {
                    __auto_type _coll = howl_normalize_ran_t(arena, facts, told, n, howl_gate_role_idx(roles, e.role));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type a = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_types_Addressed){.to = e.to, .what = ((howl_types_Derived){ .tag = howl_types_Derived_derived_sub, .data.derived_sub = a })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

uint8_t howl_normalize_normalize_axiom(slop_arena* arena, howl_normalize_NormState* p, howl_owl2_RawAxiom ax) {
    __auto_type _mv_1410 = ax;
    switch (_mv_1410.tag) {
        case howl_owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_1410.data.ra_sub_class_of.f0;
            __auto_type r = _mv_1410.data.ra_sub_class_of.f1;
            return howl_normalize_normalize_gci(arena, p, (*l), (*r));
        }
        case howl_owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_1410.data.ra_disjoint_classes;
            return howl_normalize_normalize_gci(arena, p, ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_and, .data.rc_and = cs }), ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_nothing }));
        }
        case howl_owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_1410.data.ra_object_property_domain.f0;
            __auto_type c = _mv_1410.data.ra_object_property_domain.f1;
            {
                __auto_type top_c = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_thing });
                return howl_normalize_normalize_gci(arena, p, ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_some, .data.rc_some = { .f0 = r, .f1 = howl_normalize_box_rc(arena, top_c) } }), (*c));
            }
        }
        case howl_owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type a = _mv_1410.data.ra_sub_object_property.f0;
            __auto_type b = _mv_1410.data.ra_sub_object_property.f1;
            return howl_normalize_st_emit(arena, p, ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_role, .data.sub_role = { .f0 = a, .f1 = b } }));
        }
        case howl_owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_1410.data.ra_property_chain;
            return howl_normalize_decompose_chain(arena, p, ch);
        }
        case howl_owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_1410.data.ra_class_assertion;
            howl_normalize_st_note_asserted(arena, p, ca.subject);
            return howl_normalize_normalize_gci(arena, p, howl_normalize_rc_of_node(ca.subject), (*ca.concept));
        }
        case howl_owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type e = _mv_1410.data.ra_object_property_assertion;
            return howl_normalize_st_emit_edge(arena, p, ((howl_types_LogicalEdge){.from = e.from, .role = e.role, .to = e.to}));
        }
        default: {
            return 1;
        }
    }
}

howl_owl2_RawConcept* howl_normalize_box_rc(slop_arena* arena, howl_owl2_RawConcept c) {
    {
        __auto_type q = ((howl_owl2_RawConcept*)(({ __auto_type _alloc = (howl_owl2_RawConcept*)slop_arena_alloc(arena, sizeof(howl_owl2_RawConcept)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*q) = c;
        return q;
    }
}

howl_normalize_NormOutput howl_normalize_normalize_accepted(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs) {
    {
        __auto_type p = howl_normalize_new_state(arena);
        __auto_type roles = howl_gate_collect_rbox_roles(arena, axs);
        __auto_type nr = ((int64_t)(((int64_t)((roles).len))));
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                howl_normalize_normalize_axiom(arena, p, ax);
            }
        }
        {
            __auto_type told = howl_gate_told_closure(arena, axs, roles, nr);
            __auto_type facts = howl_normalize_collect_range_facts(arena, p, axs, roles);
            howl_normalize_eliminate_ranges(arena, p, facts, told, nr, roles);
            return ((howl_normalize_NormOutput){.axioms = (*p).axioms, .edges = (*p).edges, .asserted = (*p).asserted, .seeds = howl_normalize_edge_range_seeds(arena, (*p).edges, facts, told, nr, roles), .fresh_count = howl_naming_fresh_count((*p).registry)});
        }
    }
}

howl_types_Node howl_normalize_ex_stewie(void) {
    return ((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = ((slop_rdf_rdf_IRI){.value = SLOP_STR("http://example.org/stewie")}) });
}

howl_normalize_NormOutput howl_normalize_ex_asserting_stewie(slop_arena* arena) {
    {
        __auto_type asserted = ((slop_list_howl_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(asserted); __auto_type _item = (howl_normalize_ex_stewie()); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return ((howl_normalize_NormOutput){.axioms = ((slop_list_howl_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .edges = ((slop_list_howl_types_LogicalEdge){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .asserted = asserted, .seeds = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .fresh_count = 0});
    }
}

howl_owl2_Signature howl_normalize_ex_declaring_stewie(slop_arena* arena) {
    {
        __auto_type sig = howl_owl2_make_signature(arena);
        (void)(({ slop_rdf_rdf_IRI _key_1411 = (((slop_rdf_rdf_IRI){.value = SLOP_STR("http://example.org/stewie")})); slop_map_put(NULL, sig.individuals, &_key_1411, NULL, 0); }));
        return sig;
    }
}

slop_list_howl_types_Node howl_normalize_signature_nodes(slop_arena* arena, howl_owl2_Signature sig, howl_normalize_NormOutput no) {
    {
        __auto_type out = ((slop_list_howl_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(howl_types_Node, slop_hash_howl_types_Node, slop_eq_howl_types_Node, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        int64_t i = 0;
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.classes); (slop_list_slop_rdf_rdf_IRI){.data = (slop_rdf_rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type n = ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = c });
                    if (!(slop_map_has(seen, &(n)))) {
                        (void)(({ slop_map_put(NULL, seen, &(n), NULL, 0); }));
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.individuals); (slop_list_slop_rdf_rdf_IRI){.data = (slop_rdf_rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    __auto_type n = ((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = a });
                    if (!(slop_map_has(seen, &(n)))) {
                        (void)(({ slop_map_put(NULL, seen, &(n), NULL, 0); }));
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        {
            __auto_type _coll = no.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                {
                    __auto_type from = e.from;
                    __auto_type to = e.to;
                    if (!(slop_map_has(seen, &(from)))) {
                        (void)(({ slop_map_put(NULL, seen, &(from), NULL, 0); }));
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (from); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                    if (!(slop_map_has(seen, &(to)))) {
                        (void)(({ slop_map_put(NULL, seen, &(to), NULL, 0); }));
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (to); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        {
            __auto_type _coll = no.asserted;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (!(slop_map_has(seen, &(a)))) {
                    (void)(({ slop_map_put(NULL, seen, &(a), NULL, 0); }));
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type _coll = no.seeds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type sd = _coll.data[_i];
                {
                    __auto_type to = sd.to;
                    if (!(slop_map_has(seen, &(to)))) {
                        (void)(({ slop_map_put(NULL, seen, &(to), NULL, 0); }));
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (to); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        while (i < no.fresh_count) {
            {
                __auto_type n = ((howl_types_Node){ .tag = howl_types_Node_fresh_node, .data.fresh_node = i });
                if (!(slop_map_has(seen, &(n)))) {
                    (void)(({ slop_map_put(NULL, seen, &(n), NULL, 0); }));
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                i = (i + 1);
            }
        }
        return out;
    }
}

uint8_t howl_normalize_install_seeds(slop_arena* arena, howl_types_Saturation sat, howl_normalize_NormOutput no) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = no.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                {
                    __auto_type pair = howl_types_emit_edge(arena, e);
                    if (!(howl_saturate_deliver_seed(arena, sat, pair.succ_half.to, pair.succ_half.what))) {
                        ok = 0;
                    }
                    if (!(howl_saturate_deliver_seed(arena, sat, pair.pred_half.to, pair.pred_half.what))) {
                        ok = 0;
                    }
                }
            }
        }
        {
            __auto_type _coll = no.seeds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type sd = _coll.data[_i];
                if (!(howl_saturate_deliver_seed(arena, sat, sd.to, sd.what))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

howl_types_NormAxiom howl_normalize_rename_axiom(slop_arena* arena, howl_types_Names names, howl_types_NormAxiom ax) {
    __auto_type _mv_1426 = ax;
    switch (_mv_1426.tag) {
        case howl_types_NormAxiom_sub_name:
        {
            __auto_type a = _mv_1426.data.sub_name.f0;
            __auto_type b = _mv_1426.data.sub_name.f1;
            return ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_name, .data.sub_name = { .f0 = howl_types_intern_node(arena, names, a), .f1 = howl_types_intern_node(arena, names, b) } });
        }
        case howl_types_NormAxiom_sub_and:
        {
            __auto_type a1 = _mv_1426.data.sub_and.f0;
            __auto_type a2 = _mv_1426.data.sub_and.f1;
            __auto_type b = _mv_1426.data.sub_and.f2;
            return ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_and, .data.sub_and = { .f0 = howl_types_intern_node(arena, names, a1), .f1 = howl_types_intern_node(arena, names, a2), .f2 = howl_types_intern_node(arena, names, b) } });
        }
        case howl_types_NormAxiom_sub_some_rhs:
        {
            __auto_type a = _mv_1426.data.sub_some_rhs.f0;
            __auto_type r = _mv_1426.data.sub_some_rhs.f1;
            __auto_type b = _mv_1426.data.sub_some_rhs.f2;
            return ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = howl_types_intern_node(arena, names, a), .f1 = howl_types_intern_role(arena, names, r), .f2 = howl_types_intern_node(arena, names, b) } });
        }
        case howl_types_NormAxiom_sub_some_lhs:
        {
            __auto_type r = _mv_1426.data.sub_some_lhs.f0;
            __auto_type b = _mv_1426.data.sub_some_lhs.f1;
            __auto_type a = _mv_1426.data.sub_some_lhs.f2;
            return ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = howl_types_intern_role(arena, names, r), .f1 = howl_types_intern_node(arena, names, b), .f2 = howl_types_intern_node(arena, names, a) } });
        }
        case howl_types_NormAxiom_sub_role:
        {
            __auto_type r = _mv_1426.data.sub_role.f0;
            __auto_type s = _mv_1426.data.sub_role.f1;
            return ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_sub_role, .data.sub_role = { .f0 = howl_types_intern_role(arena, names, r), .f1 = howl_types_intern_role(arena, names, s) } });
        }
        case howl_types_NormAxiom_role_chain:
        {
            __auto_type r = _mv_1426.data.role_chain.f0;
            __auto_type s = _mv_1426.data.role_chain.f1;
            __auto_type t = _mv_1426.data.role_chain.f2;
            return ((howl_types_NormAxiom){ .tag = howl_types_NormAxiom_role_chain, .data.role_chain = { .f0 = howl_types_intern_role(arena, names, r), .f1 = howl_types_intern_role(arena, names, s), .f2 = howl_types_intern_role(arena, names, t) } });
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_Derived howl_normalize_rename_derived(slop_arena* arena, howl_types_Names names, howl_types_Derived d) {
    __auto_type _mv_1427 = d;
    switch (_mv_1427.tag) {
        case howl_types_Derived_derived_sub:
        {
            __auto_type b = _mv_1427.data.derived_sub;
            return ((howl_types_Derived){ .tag = howl_types_Derived_derived_sub, .data.derived_sub = howl_types_intern_node(arena, names, b) });
        }
        case howl_types_Derived_derived_succ:
        {
            __auto_type r = _mv_1427.data.derived_succ.f0;
            __auto_type y = _mv_1427.data.derived_succ.f1;
            return ((howl_types_Derived){ .tag = howl_types_Derived_derived_succ, .data.derived_succ = { .f0 = howl_types_intern_role(arena, names, r), .f1 = howl_types_intern_node(arena, names, y) } });
        }
        case howl_types_Derived_derived_pred:
        {
            __auto_type r = _mv_1427.data.derived_pred.f0;
            __auto_type x = _mv_1427.data.derived_pred.f1;
            return ((howl_types_Derived){ .tag = howl_types_Derived_derived_pred, .data.derived_pred = { .f0 = howl_types_intern_role(arena, names, r), .f1 = howl_types_intern_node(arena, names, x) } });
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Node howl_normalize_rename_nodes(slop_arena* arena, howl_types_Names names, slop_list_howl_types_Node ns) {
    {
        __auto_type out = ((slop_list_howl_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_types_intern_node(arena, names, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_normalize_NormOutput howl_normalize_rename_output(slop_arena* arena, howl_types_Names names, howl_normalize_NormOutput no) {
    {
        __auto_type axioms = ((slop_list_howl_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type edges = ((slop_list_howl_types_LogicalEdge){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seeds = ((slop_list_howl_types_Addressed){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = no.axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(axioms); __auto_type _item = (howl_normalize_rename_axiom(arena, names, ax)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = no.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(edges); __auto_type _item = (((howl_types_LogicalEdge){.from = howl_types_intern_node(arena, names, e.from), .role = howl_types_intern_role(arena, names, e.role), .to = howl_types_intern_node(arena, names, e.to)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = no.seeds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type sd = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(seeds); __auto_type _item = (((howl_types_Addressed){.to = howl_types_intern_node(arena, names, sd.to), .what = howl_normalize_rename_derived(arena, names, sd.what)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ((howl_normalize_NormOutput){.axioms = axioms, .edges = edges, .asserted = howl_normalize_rename_nodes(arena, names, no.asserted), .seeds = seeds, .fresh_count = no.fresh_count});
    }
}

slop_result_howl_normalize_Decoded_howl_types_Fault howl_normalize_decode_document(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved) {
    return howl_normalize_decode_encoded(arena, howl_termstore_encode_triples(arena, triples), imports_resolved);
}

slop_result_howl_normalize_Decoded_howl_types_Fault howl_normalize_decode_encoded(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved) {
    __auto_type _mv_1428 = howl_decode_stage0_encoded(arena, doc, imports_resolved);
    if (!_mv_1428.is_ok) {
        __auto_type f = _mv_1428.data.err;
        return ((slop_result_howl_normalize_Decoded_howl_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_1428.is_ok) {
        __auto_type s0 = _mv_1428.data.ok;
        __auto_type _mv_1429 = howl_decode_decode_axioms_sourced(arena, s0.dict, s0.triples, s0.docs);
        if (!_mv_1429.is_ok) {
            __auto_type f = _mv_1429.data.err;
            return ((slop_result_howl_normalize_Decoded_howl_types_Fault){ .is_ok = false, .data.err = f });
        } else if (_mv_1429.is_ok) {
            __auto_type s1 = _mv_1429.data.ok;
            {
                __auto_type oms = ((slop_list_howl_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                __auto_type odocs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                {
                    __auto_type _coll = s0.omissions;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type o = _coll.data[_i];
                        ({ __auto_type _lst_p = &(oms); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                {
                    __auto_type _coll = s1.omitted;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type o = _coll.data[_i];
                        ({ __auto_type _lst_p = &(oms); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                {
                    __auto_type _coll = s0.omission_docs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type k = _coll.data[_i];
                        ({ __auto_type _lst_p = &(odocs); __auto_type _item = (k); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                {
                    __auto_type _coll = s1.omission_docs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type k = _coll.data[_i];
                        ({ __auto_type _lst_p = &(odocs); __auto_type _item = (k); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                return ((slop_result_howl_normalize_Decoded_howl_types_Fault){ .is_ok = true, .data.ok = ((howl_normalize_Decoded){.axioms = s1.axioms, .signature = s1.signature, .omissions = oms, .documents = ((int64_t)(((int64_t)((doc.starts).len)))), .axiom_docs = s1.axiom_docs, .omission_docs = odocs}) });
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

howl_normalize_Decoded howl_normalize_copy_decoded(slop_arena* arena, howl_normalize_Decoded d) {
    howl_normalize_Decoded _retval = {0};
    {
        __auto_type axioms = howl_owl2_copy_axioms(arena, d.axioms);
        _retval = ((howl_normalize_Decoded){.axioms = axioms, .signature = howl_owl2_copy_signature(arena, d.signature), .omissions = howl_types_copy_omissions(arena, d.omissions), .documents = d.documents, .axiom_docs = howl_normalize_copy_ints(arena, d.axiom_docs), .omission_docs = howl_normalize_copy_ints(arena, d.omission_docs)});
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval.axioms).len)) == ((int64_t)((d.axioms).len)))), "(== (list-len (. $result axioms)) (list-len (. d axioms)))");
    return _retval;
}

slop_list_int howl_normalize_copy_ints(slop_arena* arena, slop_list_int xs) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_normalize_NormResult howl_normalize_normalize_decoded(slop_arena* arena, slop_arena* scratch, howl_normalize_Decoded d) {
    {
        __auto_type gr = howl_gate_gate_axioms(scratch, d.axioms, d.signature, d.omissions, howl_types_Profile_profile_el);
        __auto_type no = howl_normalize_normalize_accepted(scratch, gr.accepted);
        __auto_type names = howl_types_empty_names(arena);
        __auto_type sig = howl_normalize_rename_nodes(arena, names, howl_normalize_signature_nodes(scratch, gr.signature, no));
        __auto_type rno = howl_normalize_rename_output(arena, names, no);
        {
            __auto_type sat = howl_saturate_make_initial_saturation(arena, sig);
            howl_normalize_install_seeds(arena, sat, rno);
            return ((howl_normalize_NormResult){.axioms = rno.axioms, .saturation = sat, .coverage = ((howl_types_Coverage){.omitted = howl_types_copy_omissions(arena, gr.omissions), .origins = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena })}), .names = names});
        }
    }
}

slop_result_howl_normalize_NormResult_howl_types_Fault howl_normalize_normalize_input(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config) {
    __auto_type _mv_1430 = howl_normalize_decode_document(arena, triples, imports_resolved);
    if (!_mv_1430.is_ok) {
        __auto_type f = _mv_1430.data.err;
        return ((slop_result_howl_normalize_NormResult_howl_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_1430.is_ok) {
        __auto_type d = _mv_1430.data.ok;
        return ((slop_result_howl_normalize_NormResult_howl_types_Fault){ .is_ok = true, .data.ok = howl_normalize_normalize_decoded(arena, arena, d) });
    }
    SLOP_UNREACHABLE();
}

