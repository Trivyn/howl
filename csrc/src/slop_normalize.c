#include "../runtime/slop_runtime.h"
#include "slop_normalize.h"

normalize_NormState* normalize_new_state(slop_arena* arena);
uint8_t normalize_st_emit(slop_arena* arena, normalize_NormState* p, types_NormAxiom ax);
uint8_t normalize_st_emit_edge(slop_arena* arena, normalize_NormState* p, types_LogicalEdge e);
uint8_t normalize_st_note_asserted(slop_arena* arena, normalize_NormState* p, types_Node n);
int64_t normalize_st_fresh_id(slop_arena* arena, normalize_NormState* p, slop_string text);
int64_t normalize_st_fresh_role_id(slop_arena* arena, normalize_NormState* p, slop_string text);
uint8_t normalize_st_mark_neg(slop_arena* arena, normalize_NormState* p, slop_string text);
uint8_t normalize_st_mark_pos(slop_arena* arena, normalize_NormState* p, slop_string text);
owl2_RawConcept normalize_rc_of_node(types_Node n);
slop_list_owl2_RawConcept normalize_flatten_and(slop_arena* arena, owl2_RawConcept c, slop_list_owl2_RawConcept acc);
slop_string normalize_concept_key(slop_arena* arena, owl2_RawConcept c);
slop_string normalize_node_key(slop_arena* arena, types_Node n);
slop_string normalize_role_key(slop_arena* arena, types_RoleId r);
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
slop_string normalize_render_node_name(slop_arena* arena, types_Node n);
uint8_t normalize_eliminate_ranges(slop_arena* arena, normalize_NormState* p, slop_list_normalize_RangeFact facts, slop_list_u8 told, int64_t n, slop_list_types_RoleId roles);
slop_list_types_Addressed normalize_edge_range_seeds(slop_arena* arena, slop_list_types_LogicalEdge edges, slop_list_normalize_RangeFact facts, slop_list_u8 told, int64_t n, slop_list_types_RoleId roles);
uint8_t normalize_normalize_axiom(slop_arena* arena, normalize_NormState* p, owl2_RawAxiom ax);
owl2_RawConcept* normalize_box_rc(slop_arena* arena, owl2_RawConcept c);
normalize_NormOutput normalize_normalize_accepted(slop_arena* arena, slop_list_owl2_RawAxiom axs);
types_Node normalize_ex_stewie(void);
normalize_NormOutput normalize_ex_asserting_stewie(slop_arena* arena);
owl2_Signature normalize_ex_declaring_stewie(slop_arena* arena);
slop_list_types_Node normalize_signature_nodes(slop_arena* arena, owl2_Signature sig, normalize_NormOutput no);
uint8_t normalize_install_seeds(slop_arena* arena, types_Saturation sat, normalize_NormOutput no);
types_NormAxiom normalize_rename_axiom(slop_arena* arena, types_Names names, types_NormAxiom ax);
types_Derived normalize_rename_derived(slop_arena* arena, types_Names names, types_Derived d);
slop_list_types_Node normalize_rename_nodes(slop_arena* arena, types_Names names, slop_list_types_Node ns);
normalize_NormOutput normalize_rename_output(slop_arena* arena, types_Names names, normalize_NormOutput no);
slop_result_normalize_Decoded_types_Fault normalize_decode_document(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved);
slop_result_normalize_Decoded_types_Fault normalize_decode_encoded(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved);
normalize_Decoded normalize_copy_decoded(slop_arena* arena, normalize_Decoded d);
normalize_NormResult normalize_normalize_decoded(slop_arena* arena, slop_arena* scratch, normalize_Decoded d);
slop_result_normalize_NormResult_types_Fault normalize_normalize_input(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);

normalize_NormState* normalize_new_state(slop_arena* arena) {
    {
        __auto_type p = ((normalize_NormState*)(({ __auto_type _alloc = (normalize_NormState*)slop_arena_alloc(arena, sizeof(normalize_NormState)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = ((normalize_NormState){.axioms = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0 }), .fresh = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0 }), .fresh_index = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .fresh_roles = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0 }), .fresh_role_index = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .neg_done = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .pos_done = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .edges = ((slop_list_types_LogicalEdge){ .data = NULL, .len = 0, .cap = 0 }), .asserted = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 })});
        return p;
    }
}

uint8_t normalize_st_emit(slop_arena* arena, normalize_NormState* p, types_NormAxiom ax) {
    {
        __auto_type s = (*p);
        ({ __auto_type _lst_p = &(s.axioms); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        (*p) = s;
        return 1;
    }
}

uint8_t normalize_st_emit_edge(slop_arena* arena, normalize_NormState* p, types_LogicalEdge e) {
    {
        __auto_type s = (*p);
        ({ __auto_type _lst_p = &(s.edges); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        (*p) = s;
        return 1;
    }
}

uint8_t normalize_st_note_asserted(slop_arena* arena, normalize_NormState* p, types_Node n) {
    {
        __auto_type s = (*p);
        ({ __auto_type _lst_p = &(s.asserted); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        (*p) = s;
        return 1;
    }
}

int64_t normalize_st_fresh_id(slop_arena* arena, normalize_NormState* p, slop_string text) {
    __auto_type _mv_561 = ({ void* _ptr = slop_map_get((*p).fresh_index, &(text)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
    if (_mv_561.has_value) {
        __auto_type id = _mv_561.value;
        return id;
    } else if (!_mv_561.has_value) {
        {
            __auto_type s = (*p);
            __auto_type id = ((int64_t)(((int64_t)(((*p).fresh).len))));
            ({ __auto_type _lst_p = &(s.fresh); __auto_type _item = (text); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ int64_t _val = id; slop_map_put(arena, s.fresh_index, &(text), &_val, sizeof(_val)); });
            (*p) = s;
            return id;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t normalize_st_fresh_role_id(slop_arena* arena, normalize_NormState* p, slop_string text) {
    __auto_type _mv_564 = ({ void* _ptr = slop_map_get((*p).fresh_role_index, &(text)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
    if (_mv_564.has_value) {
        __auto_type id = _mv_564.value;
        return id;
    } else if (!_mv_564.has_value) {
        {
            __auto_type s = (*p);
            __auto_type id = ((int64_t)(((int64_t)(((*p).fresh_roles).len))));
            ({ __auto_type _lst_p = &(s.fresh_roles); __auto_type _item = (text); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ int64_t _val = id; slop_map_put(arena, s.fresh_role_index, &(text), &_val, sizeof(_val)); });
            (*p) = s;
            return id;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t normalize_st_mark_neg(slop_arena* arena, normalize_NormState* p, slop_string text) {
    ({ slop_map_put(arena, (*p).neg_done, &(text), NULL, 0); });
    return 1;
}

uint8_t normalize_st_mark_pos(slop_arena* arena, normalize_NormState* p, slop_string text) {
    ({ slop_map_put(arena, (*p).pos_done, &(text), NULL, 0); });
    return 1;
}

owl2_RawConcept normalize_rc_of_node(types_Node n) {
    return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_name, .data.rc_name = n });
}

slop_list_owl2_RawConcept normalize_flatten_and(slop_arena* arena, owl2_RawConcept c, slop_list_owl2_RawConcept acc) {
    {
        __auto_type out = acc;
        __auto_type _mv_568 = c;
        switch (_mv_568.tag) {
            case owl2_RawConcept_rc_and:
            {
                __auto_type cs = _mv_568.data.rc_and;
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
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
        }
        return out;
    }
}

slop_string normalize_concept_key(slop_arena* arena, owl2_RawConcept c) {
    __auto_type _mv_569 = c;
    switch (_mv_569.tag) {
        case owl2_RawConcept_rc_thing:
        {
            return SLOP_STR("⊤");
        }
        case owl2_RawConcept_rc_nothing:
        {
            return SLOP_STR("⊥");
        }
        case owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_569.data.rc_name;
            return normalize_node_key(arena, n);
        }
        case owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_569.data.rc_and;
            {
                __auto_type out = SLOP_STR("and(");
                __auto_type first = 1;
                {
                    __auto_type _coll = cs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        if (!(first)) {
                            out = string_concat(arena, out, SLOP_STR(" "));
                        }
                        out = string_concat(arena, out, normalize_concept_key(arena, x));
                        first = 0;
                    }
                }
                return string_concat(arena, out, SLOP_STR(")"));
            }
        }
        case owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_569.data.rc_some.f0;
            __auto_type f = _mv_569.data.rc_some.f1;
            return string_concat(arena, SLOP_STR("some("), string_concat(arena, normalize_role_key(arena, r), string_concat(arena, SLOP_STR(" "), string_concat(arena, normalize_concept_key(arena, (*f)), SLOP_STR(")")))));
        }
        default: {
            return string_concat(arena, SLOP_STR("!"), owl2_render_concept(arena, c));
        }
    }
}

slop_string normalize_node_key(slop_arena* arena, types_Node n) {
    __auto_type _mv_570 = n;
    switch (_mv_570.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_570.data.class_node;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">")));
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_570.data.individual_node;
            return string_concat(arena, SLOP_STR("{<"), string_concat(arena, i.value, SLOP_STR(">}")));
        }
        case types_Node_fresh_node:
        {
            __auto_type k = _mv_570.data.fresh_node;
            return string_concat(arena, SLOP_STR("_:"), int_to_string(arena, k));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string normalize_role_key(slop_arena* arena, types_RoleId r) {
    __auto_type _mv_571 = r;
    switch (_mv_571.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_571.data.named_role;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">")));
        }
        case types_RoleId_fresh_role:
        {
            __auto_type k = _mv_571.data.fresh_role;
            return string_concat(arena, SLOP_STR("_:r"), int_to_string(arena, k));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string normalize_prefix_text(slop_arena* arena, slop_list_owl2_RawConcept conj, int64_t upto) {
    {
        __auto_type pre = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0 });
        int64_t i = 0;
        while (i < upto) {
            ({ __auto_type _lst_p = &(pre); __auto_type _item = (owl2_concept_at(conj, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        return normalize_concept_key(arena, ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_and, .data.rc_and = pre }));
    }
}

types_Node normalize_neg_atom(slop_arena* arena, normalize_NormState* p, owl2_RawConcept c) {
    __auto_type _mv_572 = c;
    switch (_mv_572.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_572.data.rc_name;
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
            __auto_type r = _mv_572.data.rc_some.f0;
            __auto_type f = _mv_572.data.rc_some.f1;
            {
                __auto_type text = normalize_concept_key(arena, c);
                __auto_type x = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = normalize_st_fresh_id(arena, p, text) });
                if (!(slop_map_has((*p).neg_done, &(text)))) {
                    normalize_st_mark_neg(arena, p, text);
                    normalize_st_emit(arena, p, ((types_NormAxiom){ .tag = types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = r, .f1 = normalize_neg_atom(arena, p, (*f)), .f2 = x } }));
                }
                return x;
            }
        }
        case owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_572.data.rc_and;
            {
                __auto_type flat = normalize_flatten_and(arena, c, ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0 }));
                __auto_type n = ((int64_t)(((int64_t)((flat).len))));
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
    __auto_type _mv_574 = c;
    switch (_mv_574.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_574.data.rc_name;
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
                __auto_type text = normalize_concept_key(arena, c);
                __auto_type x = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = normalize_st_fresh_id(arena, p, text) });
                if (!(slop_map_has((*p).pos_done, &(text)))) {
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
    __auto_type _mv_576 = rhs;
    switch (_mv_576.tag) {
        case owl2_RawConcept_rc_and:
        {
            __auto_type ds = _mv_576.data.rc_and;
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
                __auto_type conj = normalize_flatten_and(arena, lhs, ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0 }));
                __auto_type n = ((int64_t)(((int64_t)((conj).len))));
                __auto_type _mv_577 = rhs;
                switch (_mv_577.tag) {
                    case owl2_RawConcept_rc_name:
                    {
                        __auto_type b = _mv_577.data.rc_name;
                        return normalize_emit_inclusion(arena, p, conj, n, b);
                    }
                    case owl2_RawConcept_rc_nothing:
                    {
                        return normalize_emit_inclusion(arena, p, conj, n, types_node_bottom());
                    }
                    case owl2_RawConcept_rc_some:
                    {
                        __auto_type r = _mv_577.data.rc_some.f0;
                        __auto_type f = _mv_577.data.rc_some.f1;
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
    __auto_type _mv_578 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_578.has_value) {
        __auto_type v = _mv_578.value;
        return v;
    } else if (!_mv_578.has_value) {
        return ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_string normalize_prefix_role_text(slop_arena* arena, slop_list_types_RoleId steps, int64_t upto, types_RoleId super) {
    {
        __auto_type out = string_concat(arena, SLOP_STR("chain "), normalize_render_role_name(super));
        int64_t i = 0;
        while (i < upto) {
            out = string_concat(arena, out, string_concat(arena, SLOP_STR(" "), normalize_render_role_name(normalize_role_at_n(steps, i))));
            i = (i + 1);
        }
        return out;
    }
}

slop_string normalize_render_role_name(types_RoleId r) {
    __auto_type _mv_579 = r;
    switch (_mv_579.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_579.data.named_role;
            return i.value;
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_579.data.fresh_role;
            return SLOP_STR("_:fresh");
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_normalize_RangeFact normalize_collect_range_facts(slop_arena* arena, normalize_NormState* p, slop_list_owl2_RawAxiom axs, slop_list_types_RoleId roles) {
    {
        __auto_type out = ((slop_list_normalize_RangeFact){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_580 = ax;
                switch (_mv_580.tag) {
                    case owl2_RawAxiom_ra_object_property_range:
                    {
                        __auto_type r = _mv_580.data.ra_object_property_range.f0;
                        __auto_type c = _mv_580.data.ra_object_property_range.f1;
                        {
                            __auto_type ir = gate_role_idx(roles, r);
                            if (ir >= 0) {
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (((normalize_RangeFact){.role = ir, .filler = normalize_pos_atom(arena, p, (*c))})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        __auto_type out = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
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
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (f.filler); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
    __auto_type _mv_581 = ({ __auto_type _lst = m; size_t _idx = (size_t)i; slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_581.has_value) {
        __auto_type v = _mv_581.value;
        return v;
    } else if (!_mv_581.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string normalize_range_elim_key(slop_arena* arena, types_RoleId r, types_Node d) {
    return string_concat(arena, SLOP_STR("range-elim "), string_concat(arena, normalize_render_role_name(r), string_concat(arena, SLOP_STR(" "), normalize_render_node_name(arena, d))));
}

slop_string normalize_render_node_name(slop_arena* arena, types_Node n) {
    __auto_type _mv_582 = n;
    switch (_mv_582.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_582.data.class_node;
            return i.value;
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_582.data.individual_node;
            return string_concat(arena, SLOP_STR("{"), string_concat(arena, i.value, SLOP_STR("}")));
        }
        case types_Node_fresh_node:
        {
            __auto_type k = _mv_582.data.fresh_node;
            return string_concat(arena, SLOP_STR("_:fresh"), int_to_string(arena, k));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t normalize_eliminate_ranges(slop_arena* arena, normalize_NormState* p, slop_list_normalize_RangeFact facts, slop_list_u8 told, int64_t n, slop_list_types_RoleId roles) {
    {
        __auto_type rebuilt = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type existing = (*p).axioms;
        {
            __auto_type _coll = existing;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_583 = ax;
                switch (_mv_583.tag) {
                    case types_NormAxiom_sub_some_rhs:
                    {
                        __auto_type c = _mv_583.data.sub_some_rhs.f0;
                        __auto_type r = _mv_583.data.sub_some_rhs.f1;
                        __auto_type d = _mv_583.data.sub_some_rhs.f2;
                        {
                            __auto_type fillers = normalize_ran_t(arena, facts, told, n, gate_role_idx(roles, r));
                            if (((int64_t)(((int64_t)((fillers).len)))) == 0) {
                                ({ __auto_type _lst_p = &(rebuilt); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else {
                                {
                                    __auto_type x = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = normalize_st_fresh_id(arena, p, normalize_range_elim_key(arena, r, d)) });
                                    ({ __auto_type _lst_p = &(rebuilt); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = c, .f1 = r, .f2 = x } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    ({ __auto_type _lst_p = &(rebuilt); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = x, .f1 = d } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    {
                                        __auto_type _coll = fillers;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type a = _coll.data[_i];
                                            ({ __auto_type _lst_p = &(rebuilt); __auto_type _item = (((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = x, .f1 = a } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                    default: {
                        ({ __auto_type _lst_p = &(rebuilt); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        __auto_type out = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                {
                    __auto_type _coll = normalize_ran_t(arena, facts, told, n, gate_role_idx(roles, e.role));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type a = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_Addressed){.to = e.to, .what = ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = a })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

uint8_t normalize_normalize_axiom(slop_arena* arena, normalize_NormState* p, owl2_RawAxiom ax) {
    __auto_type _mv_584 = ax;
    switch (_mv_584.tag) {
        case owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_584.data.ra_sub_class_of.f0;
            __auto_type r = _mv_584.data.ra_sub_class_of.f1;
            return normalize_normalize_gci(arena, p, (*l), (*r));
        }
        case owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_584.data.ra_disjoint_classes;
            return normalize_normalize_gci(arena, p, ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_and, .data.rc_and = cs }), ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_nothing }));
        }
        case owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_584.data.ra_object_property_domain.f0;
            __auto_type c = _mv_584.data.ra_object_property_domain.f1;
            {
                __auto_type top_c = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_thing });
                return normalize_normalize_gci(arena, p, ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_some, .data.rc_some = { .f0 = r, .f1 = normalize_box_rc(arena, top_c) } }), (*c));
            }
        }
        case owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type a = _mv_584.data.ra_sub_object_property.f0;
            __auto_type b = _mv_584.data.ra_sub_object_property.f1;
            return normalize_st_emit(arena, p, ((types_NormAxiom){ .tag = types_NormAxiom_sub_role, .data.sub_role = { .f0 = a, .f1 = b } }));
        }
        case owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_584.data.ra_property_chain;
            return normalize_decompose_chain(arena, p, ch);
        }
        case owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_584.data.ra_class_assertion;
            normalize_st_note_asserted(arena, p, ca.subject);
            return normalize_normalize_gci(arena, p, normalize_rc_of_node(ca.subject), (*ca.concept));
        }
        case owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type e = _mv_584.data.ra_object_property_assertion;
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
        __auto_type nr = ((int64_t)(((int64_t)((roles).len))));
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
            return ((normalize_NormOutput){.axioms = (*p).axioms, .edges = (*p).edges, .asserted = (*p).asserted, .seeds = normalize_edge_range_seeds(arena, (*p).edges, facts, told, nr, roles), .fresh_count = ((int64_t)(((int64_t)(((*p).fresh).len))))});
        }
    }
}

types_Node normalize_ex_stewie(void) {
    return ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = ((rdf_IRI){.value = SLOP_STR("http://example.org/stewie")}) });
}

normalize_NormOutput normalize_ex_asserting_stewie(slop_arena* arena) {
    {
        __auto_type asserted = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(asserted); __auto_type _item = (normalize_ex_stewie()); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((normalize_NormOutput){.axioms = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0 }), .edges = ((slop_list_types_LogicalEdge){ .data = NULL, .len = 0, .cap = 0 }), .asserted = asserted, .seeds = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 }), .fresh_count = 0});
    }
}

owl2_Signature normalize_ex_declaring_stewie(slop_arena* arena) {
    {
        __auto_type sig = owl2_make_signature(arena);
        ({ rdf_IRI _key_585 = (((rdf_IRI){.value = SLOP_STR("http://example.org/stewie")})); slop_map_put(arena, sig.individuals, &_key_585, NULL, 0); });
        return sig;
    }
}

slop_list_types_Node normalize_signature_nodes(slop_arena* arena, owl2_Signature sig, normalize_NormOutput no) {
    {
        __auto_type out = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        int64_t i = 0;
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.classes); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type n = ((types_Node){ .tag = types_Node_class_node, .data.class_node = c });
                    if (!(slop_map_has(seen, &(n)))) {
                        ({ slop_map_put(arena, seen, &(n), NULL, 0); });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                    if (!(slop_map_has(seen, &(n)))) {
                        ({ slop_map_put(arena, seen, &(n), NULL, 0); });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                        ({ slop_map_put(arena, seen, &(from), NULL, 0); });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (from); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                    if (!(slop_map_has(seen, &(to)))) {
                        ({ slop_map_put(arena, seen, &(to), NULL, 0); });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (to); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type _coll = no.asserted;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (!(slop_map_has(seen, &(a)))) {
                    ({ slop_map_put(arena, seen, &(a), NULL, 0); });
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                        ({ slop_map_put(arena, seen, &(to), NULL, 0); });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (to); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        while (i < no.fresh_count) {
            {
                __auto_type n = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = i });
                if (!(slop_map_has(seen, &(n)))) {
                    ({ slop_map_put(arena, seen, &(n), NULL, 0); });
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

types_NormAxiom normalize_rename_axiom(slop_arena* arena, types_Names names, types_NormAxiom ax) {
    __auto_type _mv_600 = ax;
    switch (_mv_600.tag) {
        case types_NormAxiom_sub_name:
        {
            __auto_type a = _mv_600.data.sub_name.f0;
            __auto_type b = _mv_600.data.sub_name.f1;
            return ((types_NormAxiom){ .tag = types_NormAxiom_sub_name, .data.sub_name = { .f0 = types_intern_node(arena, names, a), .f1 = types_intern_node(arena, names, b) } });
        }
        case types_NormAxiom_sub_and:
        {
            __auto_type a1 = _mv_600.data.sub_and.f0;
            __auto_type a2 = _mv_600.data.sub_and.f1;
            __auto_type b = _mv_600.data.sub_and.f2;
            return ((types_NormAxiom){ .tag = types_NormAxiom_sub_and, .data.sub_and = { .f0 = types_intern_node(arena, names, a1), .f1 = types_intern_node(arena, names, a2), .f2 = types_intern_node(arena, names, b) } });
        }
        case types_NormAxiom_sub_some_rhs:
        {
            __auto_type a = _mv_600.data.sub_some_rhs.f0;
            __auto_type r = _mv_600.data.sub_some_rhs.f1;
            __auto_type b = _mv_600.data.sub_some_rhs.f2;
            return ((types_NormAxiom){ .tag = types_NormAxiom_sub_some_rhs, .data.sub_some_rhs = { .f0 = types_intern_node(arena, names, a), .f1 = types_intern_role(arena, names, r), .f2 = types_intern_node(arena, names, b) } });
        }
        case types_NormAxiom_sub_some_lhs:
        {
            __auto_type r = _mv_600.data.sub_some_lhs.f0;
            __auto_type b = _mv_600.data.sub_some_lhs.f1;
            __auto_type a = _mv_600.data.sub_some_lhs.f2;
            return ((types_NormAxiom){ .tag = types_NormAxiom_sub_some_lhs, .data.sub_some_lhs = { .f0 = types_intern_role(arena, names, r), .f1 = types_intern_node(arena, names, b), .f2 = types_intern_node(arena, names, a) } });
        }
        case types_NormAxiom_sub_role:
        {
            __auto_type r = _mv_600.data.sub_role.f0;
            __auto_type s = _mv_600.data.sub_role.f1;
            return ((types_NormAxiom){ .tag = types_NormAxiom_sub_role, .data.sub_role = { .f0 = types_intern_role(arena, names, r), .f1 = types_intern_role(arena, names, s) } });
        }
        case types_NormAxiom_role_chain:
        {
            __auto_type r = _mv_600.data.role_chain.f0;
            __auto_type s = _mv_600.data.role_chain.f1;
            __auto_type t = _mv_600.data.role_chain.f2;
            return ((types_NormAxiom){ .tag = types_NormAxiom_role_chain, .data.role_chain = { .f0 = types_intern_role(arena, names, r), .f1 = types_intern_role(arena, names, s), .f2 = types_intern_role(arena, names, t) } });
        }
    }
    SLOP_UNREACHABLE();
}

types_Derived normalize_rename_derived(slop_arena* arena, types_Names names, types_Derived d) {
    __auto_type _mv_601 = d;
    switch (_mv_601.tag) {
        case types_Derived_derived_sub:
        {
            __auto_type b = _mv_601.data.derived_sub;
            return ((types_Derived){ .tag = types_Derived_derived_sub, .data.derived_sub = types_intern_node(arena, names, b) });
        }
        case types_Derived_derived_succ:
        {
            __auto_type r = _mv_601.data.derived_succ.f0;
            __auto_type y = _mv_601.data.derived_succ.f1;
            return ((types_Derived){ .tag = types_Derived_derived_succ, .data.derived_succ = { .f0 = types_intern_role(arena, names, r), .f1 = types_intern_node(arena, names, y) } });
        }
        case types_Derived_derived_pred:
        {
            __auto_type r = _mv_601.data.derived_pred.f0;
            __auto_type x = _mv_601.data.derived_pred.f1;
            return ((types_Derived){ .tag = types_Derived_derived_pred, .data.derived_pred = { .f0 = types_intern_role(arena, names, r), .f1 = types_intern_node(arena, names, x) } });
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_types_Node normalize_rename_nodes(slop_arena* arena, types_Names names, slop_list_types_Node ns) {
    {
        __auto_type out = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (types_intern_node(arena, names, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

normalize_NormOutput normalize_rename_output(slop_arena* arena, types_Names names, normalize_NormOutput no) {
    {
        __auto_type axioms = ((slop_list_types_NormAxiom){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type edges = ((slop_list_types_LogicalEdge){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type seeds = ((slop_list_types_Addressed){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = no.axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                ({ __auto_type _lst_p = &(axioms); __auto_type _item = (normalize_rename_axiom(arena, names, ax)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = no.edges;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                ({ __auto_type _lst_p = &(edges); __auto_type _item = (((types_LogicalEdge){.from = types_intern_node(arena, names, e.from), .role = types_intern_role(arena, names, e.role), .to = types_intern_node(arena, names, e.to)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = no.seeds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type sd = _coll.data[_i];
                ({ __auto_type _lst_p = &(seeds); __auto_type _item = (((types_Addressed){.to = types_intern_node(arena, names, sd.to), .what = normalize_rename_derived(arena, names, sd.what)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((normalize_NormOutput){.axioms = axioms, .edges = edges, .asserted = normalize_rename_nodes(arena, names, no.asserted), .seeds = seeds, .fresh_count = no.fresh_count});
    }
}

slop_result_normalize_Decoded_types_Fault normalize_decode_document(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved) {
    return normalize_decode_encoded(arena, termstore_encode_triples(arena, triples), imports_resolved);
}

slop_result_normalize_Decoded_types_Fault normalize_decode_encoded(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved) {
    __auto_type _mv_602 = decode_stage0_encoded(arena, doc, imports_resolved);
    if (!_mv_602.is_ok) {
        __auto_type f = _mv_602.data.err;
        return ((slop_result_normalize_Decoded_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_602.is_ok) {
        __auto_type s0 = _mv_602.data.ok;
        __auto_type _mv_603 = decode_decode_axioms(arena, s0.dict, s0.triples);
        if (!_mv_603.is_ok) {
            __auto_type f = _mv_603.data.err;
            return ((slop_result_normalize_Decoded_types_Fault){ .is_ok = false, .data.err = f });
        } else if (_mv_603.is_ok) {
            __auto_type s1 = _mv_603.data.ok;
            return ((slop_result_normalize_Decoded_types_Fault){ .is_ok = true, .data.ok = ((normalize_Decoded){.axioms = s1.axioms, .signature = s1.signature, .omissions = s0.omissions}) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

normalize_Decoded normalize_copy_decoded(slop_arena* arena, normalize_Decoded d) {
    normalize_Decoded _retval = {0};
    {
        __auto_type axioms = owl2_copy_axioms(arena, d.axioms);
        _retval = ((normalize_Decoded){.axioms = axioms, .signature = owl2_copy_signature(arena, d.signature), .omissions = types_copy_omissions(arena, d.omissions)});
    }
    SLOP_POST(((((int64_t)((_retval.axioms).len)) == ((int64_t)((d.axioms).len)))), "(== (list-len (. $result axioms)) (list-len (. d axioms)))");
    return _retval;
}

normalize_NormResult normalize_normalize_decoded(slop_arena* arena, slop_arena* scratch, normalize_Decoded d) {
    {
        __auto_type gr = gate_gate_axioms(scratch, d.axioms, d.signature, d.omissions);
        __auto_type no = normalize_normalize_accepted(scratch, gr.accepted);
        __auto_type names = types_empty_names(arena);
        __auto_type sig = normalize_rename_nodes(arena, names, normalize_signature_nodes(scratch, gr.signature, no));
        __auto_type rno = normalize_rename_output(arena, names, no);
        {
            __auto_type sat = saturate_make_initial_saturation(arena, sig);
            normalize_install_seeds(arena, sat, rno);
            return ((normalize_NormResult){.axioms = rno.axioms, .saturation = sat, .coverage = ((types_Coverage){.omitted = types_copy_omissions(arena, gr.omissions)}), .names = names});
        }
    }
}

slop_result_normalize_NormResult_types_Fault normalize_normalize_input(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config) {
    __auto_type _mv_604 = normalize_decode_document(arena, triples, imports_resolved);
    if (!_mv_604.is_ok) {
        __auto_type f = _mv_604.data.err;
        return ((slop_result_normalize_NormResult_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_604.is_ok) {
        __auto_type d = _mv_604.data.ok;
        return ((slop_result_normalize_NormResult_types_Fault){ .is_ok = true, .data.ok = normalize_normalize_decoded(arena, arena, d) });
    }
    SLOP_UNREACHABLE();
}

