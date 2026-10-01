#include "../runtime/slop_runtime.h"
#include "slop_gate.h"

types_InputRef gate_axiom_input_ref(slop_arena* arena, owl2_RawAxiom ax);
slop_option_types_RoleId gate_least_role(slop_list_types_RoleId rs);
slop_list_owl2_RawAxiom gate_expand_sugar(slop_arena* arena, slop_list_owl2_RawAxiom axs);
uint8_t gate_has_negated_conjunct(owl2_RawConcept c);
slop_list_owl2_RawConcept gate_conjuncts(slop_arena* arena, owl2_RawConcept c);
gate_NegSplit gate_negation_split(slop_arena* arena, owl2_RawConcept c);
uint8_t gate_split_rewritable(types_Profile p, gate_NegSplit s);
owl2_RawConcept gate_conjunction(slop_list_owl2_RawConcept cs);
owl2_RawConcept gate_with_conjunct(slop_arena* arena, owl2_RawConcept c, owl2_RawConcept e);
owl2_RawAxiom gate_empty_axiom(slop_arena* arena, owl2_RawConcept c);
slop_list_owl2_RawAxiom gate_expand_negation(slop_arena* arena, types_Profile p, slop_list_owl2_RawAxiom axs);
uint8_t gate_is_top_role(types_RoleId r);
uint8_t gate_into_top_role(owl2_RawAxiom ax);
slop_list_owl2_RawAxiom gate_drop_top_role_tautologies(slop_arena* arena, types_Profile p, slop_list_owl2_RawAxiom axs);
uint8_t gate_role_listed(slop_list_types_RoleId rs, types_RoleId r);
slop_list_types_RoleId gate_non_simple_roles(slop_arena* arena, slop_list_owl2_RawAxiom axs);
uint8_t gate_concept_self_roles_simple(slop_list_types_RoleId nonsimple, owl2_RawConcept c);
uint8_t gate_self_roles_simple(slop_list_types_RoleId nonsimple, owl2_RawAxiom ax);
owl2_RawConcept* gate_box_c(slop_arena* arena, owl2_RawConcept c);
uint8_t gate_is_rbox_axiom(owl2_RawAxiom ax);
uint8_t gate_axiom_range_ok(slop_list_gate_RangeEntry entries, slop_list_u8 told, int64_t n, slop_list_types_RoleId roles, owl2_RawAxiom ax);
gate_GateResult gate_gate_axioms(slop_arena* arena, slop_list_owl2_RawAxiom axs, owl2_Signature sig, slop_list_types_Omission carried, types_Profile p);
slop_list_owl2_RawAxiom gate_sort_axioms(slop_arena* arena, slop_list_owl2_RawAxiom xs);
slop_list_string gate_axiom_texts(slop_arena* arena, slop_list_owl2_RawAxiom xs);
owl2_RawAxiom gate_axiom_at(slop_list_owl2_RawAxiom xs, int64_t i);
int64_t gate_role_idx(slop_list_types_RoleId roles, types_RoleId r);
uint8_t gate_push_role_unique(slop_list_types_RoleId rs, types_RoleId r);
slop_list_types_RoleId gate_collect_rbox_roles(slop_arena* arena, slop_list_owl2_RawAxiom axs);
slop_list_types_RoleId gate_sort_roles(slop_arena* arena, slop_list_types_RoleId xs);
types_RoleId gate_role_at(slop_list_types_RoleId xs, int64_t i);
slop_list_u8 gate_mat_new(slop_arena* arena, int64_t cells);
uint8_t gate_mat_get(slop_list_u8 m, int64_t i);
uint8_t gate_mat_close(slop_list_u8 m, int64_t n);
slop_list_u8 gate_told_closure(slop_arena* arena, slop_list_owl2_RawAxiom axs, slop_list_types_RoleId roles, int64_t n);
int64_t gate_candidate_size(owl2_RawChain ch, int64_t from, int64_t to);
uint8_t gate_add_chain_constraints(owl2_RawChain ch, slop_list_types_RoleId roles, int64_t n, slop_list_u8 cmat, int64_t from, int64_t to);
slop_string gate_describe_violation(slop_arena* arena, slop_list_types_RoleId roles, int64_t i, int64_t j);
gate_RboxVerdict gate_check_regularity(slop_arena* arena, slop_list_owl2_RawAxiom axs);
slop_list_gate_RangeEntry gate_collect_ranges(slop_arena* arena, slop_list_owl2_RawAxiom axs, slop_list_types_RoleId roles);
uint8_t gate_has_inherited_range(slop_list_gate_RangeEntry entries, slop_list_u8 told, int64_t n, int64_t base, owl2_RawConcept c);
uint8_t gate_chain_range_ok(slop_list_gate_RangeEntry entries, slop_list_u8 told, int64_t n, slop_list_types_RoleId roles, owl2_RawChain ch);
types_AxiomRef gate_axiom_ref_of(slop_arena* arena, owl2_RawAxiom ax);
slop_list_rdf_IRI gate_collect_concept_classes(slop_arena* arena, owl2_RawConcept c, slop_list_rdf_IRI acc);
slop_list_gate_EntityRef gate_collect_entity_refs(slop_arena* arena, slop_list_owl2_RawAxiom axs);
uint8_t gate_entity_ref_declared(owl2_Signature sig, gate_EntityRef e);
uint8_t gate_same_entity(gate_EntityRef a, gate_EntityRef b);
slop_list_types_Omission gate_missing_declarations(slop_arena* arena, owl2_Signature sig, slop_list_gate_EntityRef refs);

typedef struct { slop_list_string texts; } gate__lambda_566_env_t;

static int64_t gate__lambda_566(gate__lambda_566_env_t* _env, int64_t i, int64_t j) { return canon_string_cmp(canon_str_at(_env->texts, i), canon_str_at(_env->texts, j)); }

typedef struct { slop_list_types_RoleId xs; } gate__lambda_569_env_t;

static int64_t gate__lambda_569(gate__lambda_569_env_t* _env, int64_t i, int64_t j) { return canon_role_cmp(gate_role_at(_env->xs, i), gate_role_at(_env->xs, j)); }

types_InputRef gate_axiom_input_ref(slop_arena* arena, owl2_RawAxiom ax) {
    {
        slop_option_rdf_IRI no_source = (slop_option_rdf_IRI){.has_value = false};
        return ((types_InputRef){ .tag = types_InputRef_owl_axiom, .data.owl_axiom = ((types_AxiomRef){.source = no_source, .text = owl2_render_axiom(arena, ax)}) });
    }
}

slop_option_types_RoleId gate_least_role(slop_list_types_RoleId rs) {
    {
        slop_option_types_RoleId best = (slop_option_types_RoleId){.has_value = false};
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                __auto_type _mv_549 = best;
                if (!_mv_549.has_value) {
                    best = (slop_option_types_RoleId){.has_value = 1, .value = r};
                } else if (_mv_549.has_value) {
                    __auto_type b = _mv_549.value;
                    if (canon_role_cmp(r, b) < 0) {
                        best = (slop_option_types_RoleId){.has_value = 1, .value = r};
                    }
                }
            }
        }
        return best;
    }
}

slop_list_owl2_RawAxiom gate_expand_sugar(slop_arena* arena, slop_list_owl2_RawAxiom axs) {
    {
        __auto_type out = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_550 = ax;
                switch (_mv_550.tag) {
                    case owl2_RawAxiom_ra_transitive_property:
                    {
                        __auto_type r = _mv_550.data.ra_transitive_property;
                        {
                            __auto_type steps = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 });
                            ({ __auto_type _lst_p = &(steps); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(steps); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_property_chain, .data.ra_property_chain = ((owl2_RawChain){.steps = steps, .super = r}) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        break;
                    }
                    case owl2_RawAxiom_ra_equivalent_properties:
                    {
                        __auto_type rs = _mv_550.data.ra_equivalent_properties;
                        __auto_type _mv_551 = gate_least_role(rs);
                        if (!_mv_551.has_value) {
                        } else if (_mv_551.has_value) {
                            __auto_type hub = _mv_551.value;
                            {
                                __auto_type _coll = rs;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type r = _coll.data[_i];
                                    if (canon_role_cmp(r, hub) != 0) {
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_sub_object_property, .data.ra_sub_object_property = { .f0 = hub, .f1 = r } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_sub_object_property, .data.ra_sub_object_property = { .f0 = r, .f1 = hub } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                        break;
                    }
                    case owl2_RawAxiom_ra_equivalent_classes:
                    {
                        __auto_type cs = _mv_550.data.ra_equivalent_classes;
                        {
                            __auto_type sorted = owl2_sort_concepts(arena, cs);
                            __auto_type n = ((int64_t)(((int64_t)((cs).len))));
                            if (n > 0) {
                                {
                                    __auto_type hub = owl2_concept_at(sorted, 0);
                                    __auto_type i = 1;
                                    while (i < n) {
                                        {
                                            __auto_type c = owl2_concept_at(sorted, i);
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_sub_class_of, .data.ra_sub_class_of = { .f0 = gate_box_c(arena, hub), .f1 = gate_box_c(arena, c) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_sub_class_of, .data.ra_sub_class_of = { .f0 = gate_box_c(arena, c), .f1 = gate_box_c(arena, hub) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            i = (i + 1);
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                    case owl2_RawAxiom_ra_disjoint_classes:
                    {
                        __auto_type cs = _mv_550.data.ra_disjoint_classes;
                        {
                            __auto_type n = ((int64_t)(((int64_t)((cs).len))));
                            if (n <= 2) {
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else {
                                {
                                    __auto_type sorted = owl2_sort_concepts(arena, cs);
                                    __auto_type i = 0;
                                    while (i < n) {
                                        {
                                            __auto_type j = (i + 1);
                                            while (j < n) {
                                                {
                                                    __auto_type pair = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0 });
                                                    ({ __auto_type _lst_p = &(pair); __auto_type _item = (owl2_concept_at(sorted, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    ({ __auto_type _lst_p = &(pair); __auto_type _item = (owl2_concept_at(sorted, j)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_disjoint_classes, .data.ra_disjoint_classes = pair })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    j = (j + 1);
                                                }
                                            }
                                            i = (i + 1);
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                    default: {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                }
            }
        }
        return out;
    }
}

uint8_t gate_has_negated_conjunct(owl2_RawConcept c) {
    __auto_type _mv_552 = c;
    switch (_mv_552.tag) {
        case owl2_RawConcept_rc_not:
        {
            __auto_type _ = _mv_552.data.rc_not;
            return 1;
        }
        case owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_552.data.rc_and;
            {
                __auto_type found = 0;
                {
                    __auto_type _coll = cs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        __auto_type _mv_553 = x;
                        switch (_mv_553.tag) {
                            case owl2_RawConcept_rc_not:
                            {
                                __auto_type _ = _mv_553.data.rc_not;
                                found = 1;
                                break;
                            }
                            default: {
                                break;
                            }
                        }
                    }
                }
                return found;
            }
        }
        default: {
            return 0;
        }
    }
}

slop_list_owl2_RawConcept gate_conjuncts(slop_arena* arena, owl2_RawConcept c) {
    {
        __auto_type out = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_554 = c;
        switch (_mv_554.tag) {
            case owl2_RawConcept_rc_and:
            {
                __auto_type cs = _mv_554.data.rc_and;
                {
                    __auto_type _coll = cs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
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

gate_NegSplit gate_negation_split(slop_arena* arena, owl2_RawConcept c) {
    {
        __auto_type pos = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type neg = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = gate_conjuncts(arena, c);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                __auto_type _mv_555 = x;
                switch (_mv_555.tag) {
                    case owl2_RawConcept_rc_not:
                    {
                        __auto_type e = _mv_555.data.rc_not;
                        ({ __auto_type _lst_p = &(neg); __auto_type _item = ((*e)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    default: {
                        ({ __auto_type _lst_p = &(pos); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                }
            }
        }
        return ((gate_NegSplit){.pos = pos, .neg = neg});
    }
}

uint8_t gate_split_rewritable(types_Profile p, gate_NegSplit s) {
    return (((((int64_t)((s.neg).len)) > 0)) && (owl2_concepts_in_profile(p, s.pos)) && (owl2_concepts_in_profile(p, s.neg)));
}

owl2_RawConcept gate_conjunction(slop_list_owl2_RawConcept cs) {
    SLOP_PRE(((((int64_t)((cs).len)) > 0)), "(> (list-len cs) 0)");
    if (((int64_t)((cs).len)) == 1) {
        return owl2_concept_at(cs, 0);
    } else {
        return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_and, .data.rc_and = cs });
    }
}

owl2_RawConcept gate_with_conjunct(slop_arena* arena, owl2_RawConcept c, owl2_RawConcept e) {
    {
        __auto_type cs = gate_conjuncts(arena, c);
        ({ __auto_type _lst_p = &(cs); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_and, .data.rc_and = cs });
    }
}

owl2_RawAxiom gate_empty_axiom(slop_arena* arena, owl2_RawConcept c) {
    return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_sub_class_of, .data.ra_sub_class_of = { .f0 = gate_box_c(arena, c), .f1 = gate_box_c(arena, ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_nothing })) } });
}

slop_list_owl2_RawAxiom gate_expand_negation(slop_arena* arena, types_Profile p, slop_list_owl2_RawAxiom axs) {
    {
        __auto_type out = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_556 = ax;
                switch (_mv_556.tag) {
                    case owl2_RawAxiom_ra_sub_class_of:
                    {
                        __auto_type l = _mv_556.data.ra_sub_class_of.f0;
                        __auto_type r = _mv_556.data.ra_sub_class_of.f1;
                        if (!(gate_has_negated_conjunct((*r)))) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        } else {
                            {
                                __auto_type s = gate_negation_split(arena, (*r));
                                if (!((owl2_concept_in_profile(p, (*l)) && gate_split_rewritable(p, s)))) {
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                } else {
                                    if (((int64_t)((s.pos).len)) > 0) {
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_sub_class_of, .data.ra_sub_class_of = { .f0 = l, .f1 = gate_box_c(arena, gate_conjunction(s.pos)) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                    {
                                        __auto_type _coll = s.neg;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type e = _coll.data[_i];
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (gate_empty_axiom(arena, gate_with_conjunct(arena, (*l), e))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                    case owl2_RawAxiom_ra_object_property_domain:
                    {
                        __auto_type r = _mv_556.data.ra_object_property_domain.f0;
                        __auto_type c = _mv_556.data.ra_object_property_domain.f1;
                        if (!(gate_has_negated_conjunct((*c)))) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        } else {
                            {
                                __auto_type s = gate_negation_split(arena, (*c));
                                if (!((owl2_role_in_profile(p, r) && gate_split_rewritable(p, s)))) {
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                } else {
                                    {
                                        __auto_type some_r = ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_some, .data.rc_some = { .f0 = r, .f1 = gate_box_c(arena, ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_thing })) } });
                                        if (((int64_t)((s.pos).len)) > 0) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_object_property_domain, .data.ra_object_property_domain = { .f0 = r, .f1 = gate_box_c(arena, gate_conjunction(s.pos)) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                        {
                                            __auto_type _coll = s.neg;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type e = _coll.data[_i];
                                                ({ __auto_type _lst_p = &(out); __auto_type _item = (gate_empty_axiom(arena, gate_with_conjunct(arena, some_r, e))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                    case owl2_RawAxiom_ra_object_property_range:
                    {
                        __auto_type r = _mv_556.data.ra_object_property_range.f0;
                        __auto_type c = _mv_556.data.ra_object_property_range.f1;
                        if (!(gate_has_negated_conjunct((*c)))) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        } else {
                            {
                                __auto_type s = gate_negation_split(arena, (*c));
                                if (!((owl2_role_in_profile(p, r) && gate_split_rewritable(p, s)))) {
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                } else {
                                    if (((int64_t)((s.pos).len)) > 0) {
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_object_property_range, .data.ra_object_property_range = { .f0 = r, .f1 = gate_box_c(arena, gate_conjunction(s.pos)) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                    {
                                        __auto_type _coll = s.neg;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type e = _coll.data[_i];
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (gate_empty_axiom(arena, ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_some, .data.rc_some = { .f0 = r, .f1 = gate_box_c(arena, e) } }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                    default: {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                }
            }
        }
        return out;
    }
}

uint8_t gate_is_top_role(types_RoleId r) {
    __auto_type _mv_557 = r;
    switch (_mv_557.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_557.data.named_role;
            return (canon_string_cmp(i.value, vocab_OWL_TOP_OBJECT_PROPERTY) == 0);
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_557.data.fresh_role;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t gate_into_top_role(owl2_RawAxiom ax) {
    __auto_type _mv_558 = ax;
    switch (_mv_558.tag) {
        case owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type sup = _mv_558.data.ra_sub_object_property.f1;
            return gate_is_top_role(sup);
        }
        case owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_558.data.ra_property_chain;
            return gate_is_top_role(ch.super);
        }
        default: {
            return 0;
        }
    }
}

slop_list_owl2_RawAxiom gate_drop_top_role_tautologies(slop_arena* arena, types_Profile p, slop_list_owl2_RawAxiom axs) {
    if (!(owl2_is_el_plus_plus(p))) {
        return axs;
    } else {
        {
            __auto_type out = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0 });
            {
                __auto_type _coll = axs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ax = _coll.data[_i];
                    if (!(gate_into_top_role(ax))) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
            return out;
        }
    }
}

uint8_t gate_role_listed(slop_list_types_RoleId rs, types_RoleId r) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (canon_role_cmp(x, r) == 0) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_list_types_RoleId gate_non_simple_roles(slop_arena* arena, slop_list_owl2_RawAxiom axs) {
    {
        __auto_type out = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 });
        uint8_t changed = 1;
        ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = ((rdf_IRI){.value = vocab_OWL_BOTTOM_OBJECT_PROPERTY}) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_559 = ax;
                switch (_mv_559.tag) {
                    case owl2_RawAxiom_ra_property_chain:
                    {
                        __auto_type ch = _mv_559.data.ra_property_chain;
                        if (!(gate_role_listed(out, ch.super))) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (ch.super); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        while (changed) {
            changed = 0;
            {
                __auto_type _coll = axs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ax = _coll.data[_i];
                    __auto_type _mv_560 = ax;
                    switch (_mv_560.tag) {
                        case owl2_RawAxiom_ra_sub_object_property:
                        {
                            __auto_type a = _mv_560.data.ra_sub_object_property.f0;
                            __auto_type b = _mv_560.data.ra_sub_object_property.f1;
                            if (gate_role_listed(out, a) && !(gate_role_listed(out, b))) {
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                changed = 1;
                            }
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                }
            }
        }
        return out;
    }
}

uint8_t gate_concept_self_roles_simple(slop_list_types_RoleId nonsimple, owl2_RawConcept c) {
    __auto_type _mv_561 = c;
    switch (_mv_561.tag) {
        case owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_561.data.rc_has_self;
            return !(gate_role_listed(nonsimple, r));
        }
        case owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_561.data.rc_and;
            {
                __auto_type ok = 1;
                {
                    __auto_type _coll = cs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        if (!(gate_concept_self_roles_simple(nonsimple, x))) {
                            ok = 0;
                        }
                    }
                }
                return ok;
            }
        }
        case owl2_RawConcept_rc_some:
        {
            __auto_type f = _mv_561.data.rc_some.f1;
            return gate_concept_self_roles_simple(nonsimple, (*f));
        }
        default: {
            return 1;
        }
    }
}

uint8_t gate_self_roles_simple(slop_list_types_RoleId nonsimple, owl2_RawAxiom ax) {
    __auto_type _mv_562 = ax;
    switch (_mv_562.tag) {
        case owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_562.data.ra_sub_class_of.f0;
            __auto_type r = _mv_562.data.ra_sub_class_of.f1;
            return (gate_concept_self_roles_simple(nonsimple, (*l)) && gate_concept_self_roles_simple(nonsimple, (*r)));
        }
        case owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_562.data.ra_disjoint_classes;
            {
                __auto_type ok = 1;
                {
                    __auto_type _coll = cs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        if (!(gate_concept_self_roles_simple(nonsimple, x))) {
                            ok = 0;
                        }
                    }
                }
                return ok;
            }
        }
        case owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type c = _mv_562.data.ra_object_property_domain.f1;
            return gate_concept_self_roles_simple(nonsimple, (*c));
        }
        case owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type c = _mv_562.data.ra_object_property_range.f1;
            return gate_concept_self_roles_simple(nonsimple, (*c));
        }
        case owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_562.data.ra_class_assertion;
            return gate_concept_self_roles_simple(nonsimple, (*ca.concept));
        }
        default: {
            return 1;
        }
    }
}

owl2_RawConcept* gate_box_c(slop_arena* arena, owl2_RawConcept c) {
    {
        __auto_type p = ((owl2_RawConcept*)(({ __auto_type _alloc = (owl2_RawConcept*)slop_arena_alloc(arena, sizeof(owl2_RawConcept)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = c;
        return p;
    }
}

uint8_t gate_is_rbox_axiom(owl2_RawAxiom ax) {
    __auto_type _mv_563 = ax;
    switch (_mv_563.tag) {
        case owl2_RawAxiom_ra_sub_object_property:
        {
            return 1;
        }
        case owl2_RawAxiom_ra_property_chain:
        {
            __auto_type _ = _mv_563.data.ra_property_chain;
            return 1;
        }
        default: {
            return 0;
        }
    }
}

uint8_t gate_axiom_range_ok(slop_list_gate_RangeEntry entries, slop_list_u8 told, int64_t n, slop_list_types_RoleId roles, owl2_RawAxiom ax) {
    __auto_type _mv_564 = ax;
    switch (_mv_564.tag) {
        case owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_564.data.ra_property_chain;
            return gate_chain_range_ok(entries, told, n, roles, ch);
        }
        default: {
            return 1;
        }
    }
}

gate_GateResult gate_gate_axioms(slop_arena* arena, slop_list_owl2_RawAxiom axs, owl2_Signature sig, slop_list_types_Omission carried, types_Profile p) {
    {
        __auto_type expanded = gate_drop_top_role_tautologies(arena, p, gate_expand_negation(arena, p, gate_expand_sugar(arena, axs)));
        __auto_type accepted = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type omitted = ((slop_list_types_Omission){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = carried;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                ({ __auto_type _lst_p = &(omitted); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type rbox_bad = ({ __auto_type _mv = gate_check_regularity(arena, expanded); uint8_t _mr = {0}; switch (_mv.tag) { case gate_RboxVerdict_rbox_regular: { _mr = 0; break; } case gate_RboxVerdict_rbox_irregular: { __auto_type _ = _mv.data.rbox_irregular; _mr = 1; break; }  } _mr; });
            __auto_type rroles = gate_collect_rbox_roles(arena, expanded);
            __auto_type told = gate_told_closure(arena, expanded, rroles, ((int64_t)(((int64_t)((rroles).len)))));
            __auto_type ranges = gate_collect_ranges(arena, expanded, rroles);
            __auto_type nonsimple = ((owl2_is_el_plus_plus(p)) ? gate_non_simple_roles(arena, expanded) : ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 }));
            {
                __auto_type _coll = expanded;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ax = _coll.data[_i];
                    __auto_type _mv_565 = owl2_disposition(p, ax);
                    if (_mv_565 == owl2_Disposition_d_consumed) {
                    } else if (_mv_565 == owl2_Disposition_d_inert) {
                    } else if (_mv_565 == owl2_Disposition_d_in_profile) {
                        if ((owl2_axiom_in_profile(p, ax)) && (!((rbox_bad && gate_is_rbox_axiom(ax)))) && (gate_self_roles_simple(nonsimple, ax)) && (gate_axiom_range_ok(ranges, told, ((int64_t)(((int64_t)((rroles).len)))), rroles, ax))) {
                            ({ __auto_type _lst_p = &(accepted); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        } else {
                            ({ __auto_type _lst_p = &(omitted); __auto_type _item = (((types_Omission){ .tag = types_Omission_out_of_profile, .data.out_of_profile = gate_axiom_input_ref(arena, ax) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    } else if (_mv_565 == owl2_Disposition_d_out_of_profile) {
                        ({ __auto_type _lst_p = &(omitted); __auto_type _item = (((types_Omission){ .tag = types_Omission_out_of_profile, .data.out_of_profile = gate_axiom_input_ref(arena, ax) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type _coll = gate_missing_declarations(arena, sig, gate_collect_entity_refs(arena, accepted));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                ({ __auto_type _lst_p = &(omitted); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((gate_GateResult){.accepted = gate_sort_axioms(arena, accepted), .omissions = canon_sort_omissions(arena, omitted), .signature = sig});
    }
}

slop_list_owl2_RawAxiom gate_sort_axioms(slop_arena* arena, slop_list_owl2_RawAxiom xs) {
    {
        __auto_type texts = gate_axiom_texts(arena, xs);
        {
            __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ gate__lambda_566_env_t* gate__lambda_566_env = (gate__lambda_566_env_t*)slop_arena_alloc(arena, sizeof(gate__lambda_566_env_t)); *gate__lambda_566_env = (gate__lambda_566_env_t){ .texts = texts }; (slop_closure_t){ (void*)gate__lambda_566, (void*)gate__lambda_566_env }; }));
            __auto_type out = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0 });
            {
                __auto_type _coll = idx;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type k = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (gate_axiom_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            return out;
        }
    }
}

slop_list_string gate_axiom_texts(slop_arena* arena, slop_list_owl2_RawAxiom xs) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (owl2_render_axiom(arena, ax)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

owl2_RawAxiom gate_axiom_at(slop_list_owl2_RawAxiom xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_567 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_owl2_RawAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_567.has_value) {
        __auto_type v = _mv_567.value;
        return v;
    } else if (!_mv_567.has_value) {
        return ((owl2_RawAxiom){ .tag = owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = ((types_InputRef){ .tag = types_InputRef_synthetic, .data.synthetic = SLOP_STR("unreachable: axiom index out of range") }) });
    }
    SLOP_UNREACHABLE();
}

int64_t gate_role_idx(slop_list_types_RoleId roles, types_RoleId r) {
    {
        int64_t found = -1;
        int64_t i = 0;
        {
            __auto_type _coll = roles;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if ((found < 0) && (canon_role_cmp(x, r) == 0)) {
                    found = i;
                }
                i = (i + 1);
            }
        }
        return found;
    }
}

uint8_t gate_push_role_unique(slop_list_types_RoleId rs, types_RoleId r) {
    return (gate_role_idx(rs, r) < 0);
}

slop_list_types_RoleId gate_collect_rbox_roles(slop_arena* arena, slop_list_owl2_RawAxiom axs) {
    {
        __auto_type rs = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_568 = ax;
                switch (_mv_568.tag) {
                    case owl2_RawAxiom_ra_sub_object_property:
                    {
                        __auto_type a = _mv_568.data.ra_sub_object_property.f0;
                        __auto_type b = _mv_568.data.ra_sub_object_property.f1;
                        if (gate_push_role_unique(rs, a)) {
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        if (gate_push_role_unique(rs, b)) {
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        break;
                    }
                    case owl2_RawAxiom_ra_property_chain:
                    {
                        __auto_type ch = _mv_568.data.ra_property_chain;
                        {
                            __auto_type _coll = ch.steps;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type st = _coll.data[_i];
                                if (gate_push_role_unique(rs, st)) {
                                    ({ __auto_type _lst_p = &(rs); __auto_type _item = (st); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                        if (gate_push_role_unique(rs, ch.super)) {
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (ch.super); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        break;
                    }
                    case owl2_RawAxiom_ra_object_property_range:
                    {
                        __auto_type r = _mv_568.data.ra_object_property_range.f0;
                        if (gate_push_role_unique(rs, r)) {
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        return gate_sort_roles(arena, rs);
    }
}

slop_list_types_RoleId gate_sort_roles(slop_arena* arena, slop_list_types_RoleId xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ gate__lambda_569_env_t* gate__lambda_569_env = (gate__lambda_569_env_t*)slop_arena_alloc(arena, sizeof(gate__lambda_569_env_t)); *gate__lambda_569_env = (gate__lambda_569_env_t){ .xs = xs }; (slop_closure_t){ (void*)gate__lambda_569, (void*)gate__lambda_569_env }; }));
        __auto_type out = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (gate_role_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

types_RoleId gate_role_at(slop_list_types_RoleId xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_570 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_570.has_value) {
        __auto_type v = _mv_570.value;
        return v;
    } else if (!_mv_570.has_value) {
        return ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_list_u8 gate_mat_new(slop_arena* arena, int64_t cells) {
    {
        __auto_type m = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0 });
        int64_t i = 0;
        while (i < cells) {
            ({ __auto_type _lst_p = &(m); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        return m;
    }
}

uint8_t gate_mat_get(slop_list_u8 m, int64_t i) {
    __auto_type _mv_571 = ({ __auto_type _lst = m; size_t _idx = (size_t)i; slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_571.has_value) {
        __auto_type v = _mv_571.value;
        return v;
    } else if (!_mv_571.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t gate_mat_close(slop_list_u8 m, int64_t n) {
    {
        int64_t k = 0;
        while (k < n) {
            {
                int64_t i = 0;
                while (i < n) {
                    if (gate_mat_get(m, ((i * n) + k))) {
                        {
                            int64_t j = 0;
                            while (j < n) {
                                if (gate_mat_get(m, ((k * n) + j))) {
                                    ({ __auto_type _set_lst = &(m); size_t _set_idx = (size_t)(((i * n) + j)); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
                                }
                                j = (j + 1);
                            }
                        }
                    }
                    i = (i + 1);
                }
            }
            k = (k + 1);
        }
        return 1;
    }
}

slop_list_u8 gate_told_closure(slop_arena* arena, slop_list_owl2_RawAxiom axs, slop_list_types_RoleId roles, int64_t n) {
    {
        __auto_type m = gate_mat_new(arena, (n * n));
        int64_t i = 0;
        while (i < n) {
            ({ __auto_type _set_lst = &(m); size_t _set_idx = (size_t)(((i * n) + i)); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
            i = (i + 1);
        }
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_572 = ax;
                switch (_mv_572.tag) {
                    case owl2_RawAxiom_ra_sub_object_property:
                    {
                        __auto_type a = _mv_572.data.ra_sub_object_property.f0;
                        __auto_type b = _mv_572.data.ra_sub_object_property.f1;
                        {
                            __auto_type ia = gate_role_idx(roles, a);
                            __auto_type ib = gate_role_idx(roles, b);
                            if ((ia >= 0) && (ib >= 0)) {
                                ({ __auto_type _set_lst = &(m); size_t _set_idx = (size_t)(((ia * n) + ib)); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
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
        gate_mat_close(m, n);
        return m;
    }
}

int64_t gate_candidate_size(owl2_RawChain ch, int64_t from, int64_t to) {
    {
        __auto_type steps = ch.steps;
        int64_t count = 0;
        int64_t i = from;
        while (i <= to) {
            {
                uint8_t dup = 0;
                int64_t j = from;
                while (j < i) {
                    if (canon_role_cmp(gate_role_at(steps, j), gate_role_at(steps, i)) == 0) {
                        dup = 1;
                    }
                    j = (j + 1);
                }
                if (!(dup)) {
                    count = (count + 1);
                }
            }
            i = (i + 1);
        }
        return count;
    }
}

uint8_t gate_add_chain_constraints(owl2_RawChain ch, slop_list_types_RoleId roles, int64_t n, slop_list_u8 cmat, int64_t from, int64_t to) {
    {
        __auto_type steps = ch.steps;
        __auto_type isup = gate_role_idx(roles, ch.super);
        int64_t i = from;
        while (i <= to) {
            {
                __auto_type ist = gate_role_idx(roles, gate_role_at(steps, i));
                if ((ist >= 0) && (isup >= 0)) {
                    ({ __auto_type _set_lst = &(cmat); size_t _set_idx = (size_t)(((ist * n) + isup)); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
                }
            }
            i = (i + 1);
        }
        return 1;
    }
}

slop_string gate_describe_violation(slop_arena* arena, slop_list_types_RoleId roles, int64_t i, int64_t j) {
    return string_concat(arena, SLOP_STR("property-chain regularity: "), string_concat(arena, owl2_render_role(gate_role_at(roles, i)), string_concat(arena, SLOP_STR(" must precede "), string_concat(arena, owl2_render_role(gate_role_at(roles, j)), string_concat(arena, SLOP_STR(", but the told hierarchy has "), string_concat(arena, owl2_render_role(gate_role_at(roles, j)), string_concat(arena, SLOP_STR(" sub-property-of "), owl2_render_role(gate_role_at(roles, i)))))))));
}

gate_RboxVerdict gate_check_regularity(slop_arena* arena, slop_list_owl2_RawAxiom axs) {
    {
        __auto_type roles = gate_collect_rbox_roles(arena, axs);
        __auto_type n = ((int64_t)(((int64_t)((roles).len))));
        if (n == 0) {
            return ((gate_RboxVerdict){ .tag = gate_RboxVerdict_rbox_regular });
        } else {
            {
                __auto_type told = gate_told_closure(arena, axs, roles, n);
                __auto_type cmat = gate_mat_new(arena, (n * n));
                slop_option_string msg = (slop_option_string){.has_value = false};
                {
                    __auto_type _coll = axs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type ax = _coll.data[_i];
                        __auto_type _mv_573 = ax;
                        switch (_mv_573.tag) {
                            case owl2_RawAxiom_ra_property_chain:
                            {
                                __auto_type ch = _mv_573.data.ra_property_chain;
                                {
                                    __auto_type steps = ch.steps;
                                    __auto_type len = ((int64_t)(((int64_t)((ch.steps).len))));
                                    __auto_type sup = ch.super;
                                    if (len >= 2) {
                                        {
                                            __auto_type left_ok = (canon_role_cmp(gate_role_at(steps, 0), sup) == 0);
                                            __auto_type right_ok = (canon_role_cmp(gate_role_at(steps, (len - 1)), sup) == 0);
                                            if (((len == 2)) && (left_ok) && (right_ok)) {
                                            } else {
                                                {
                                                    __auto_type gen = gate_candidate_size(ch, 0, (len - 1));
                                                    __auto_type lft = ((left_ok) ? gate_candidate_size(ch, 1, (len - 1)) : 1000000);
                                                    __auto_type rgt = ((right_ok) ? gate_candidate_size(ch, 0, (len - 2)) : 1000000);
                                                    if ((lft <= rgt) && (lft <= gen)) {
                                                        gate_add_chain_constraints(ch, roles, n, cmat, 1, (len - 1));
                                                    } else if (rgt <= gen) {
                                                        gate_add_chain_constraints(ch, roles, n, cmat, 0, (len - 2));
                                                    } else {
                                                        gate_add_chain_constraints(ch, roles, n, cmat, 0, (len - 1));
                                                    }
                                                }
                                            }
                                        }
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
                gate_mat_close(cmat, n);
                {
                    int64_t i = 0;
                    while (i < n) {
                        {
                            int64_t j = 0;
                            while (j < n) {
                                if (gate_mat_get(cmat, ((i * n) + j)) && gate_mat_get(told, ((j * n) + i))) {
                                    __auto_type _mv_574 = msg;
                                    if (!_mv_574.has_value) {
                                        msg = (slop_option_string){.has_value = 1, .value = gate_describe_violation(arena, roles, i, j)};
                                    } else if (_mv_574.has_value) {
                                        __auto_type _ = _mv_574.value;
                                    }
                                }
                                j = (j + 1);
                            }
                        }
                        i = (i + 1);
                    }
                }
                __auto_type _mv_575 = msg;
                if (_mv_575.has_value) {
                    __auto_type m = _mv_575.value;
                    return ((gate_RboxVerdict){ .tag = gate_RboxVerdict_rbox_irregular, .data.rbox_irregular = m });
                } else if (!_mv_575.has_value) {
                    return ((gate_RboxVerdict){ .tag = gate_RboxVerdict_rbox_regular });
                }
                SLOP_UNREACHABLE();
            }
        }
    }
}

slop_list_gate_RangeEntry gate_collect_ranges(slop_arena* arena, slop_list_owl2_RawAxiom axs, slop_list_types_RoleId roles) {
    {
        __auto_type out = ((slop_list_gate_RangeEntry){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_576 = ax;
                switch (_mv_576.tag) {
                    case owl2_RawAxiom_ra_object_property_range:
                    {
                        __auto_type r = _mv_576.data.ra_object_property_range.f0;
                        __auto_type c = _mv_576.data.ra_object_property_range.f1;
                        {
                            __auto_type ir = gate_role_idx(roles, r);
                            if (ir >= 0) {
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (((gate_RangeEntry){.role = ir, .filler = (*c)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

uint8_t gate_has_inherited_range(slop_list_gate_RangeEntry entries, slop_list_u8 told, int64_t n, int64_t base, owl2_RawConcept c) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = entries;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (gate_mat_get(told, ((base * n) + e.role)) && (owl2_concept_cmp(e.filler, c) == 0)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t gate_chain_range_ok(slop_list_gate_RangeEntry entries, slop_list_u8 told, int64_t n, slop_list_types_RoleId roles, owl2_RawChain ch) {
    {
        __auto_type steps = ch.steps;
        __auto_type len = ((int64_t)(((int64_t)((ch.steps).len))));
        __auto_type it = gate_role_idx(roles, ch.super);
        if ((len < 1) || (it < 0)) {
            return 1;
        } else {
            {
                __auto_type ilast = gate_role_idx(roles, gate_role_at(steps, (len - 1)));
                uint8_t ok = 1;
                if (ilast >= 0) {
                    {
                        __auto_type _coll = entries;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type e = _coll.data[_i];
                            if (gate_mat_get(told, ((it * n) + e.role))) {
                                if (!(gate_has_inherited_range(entries, told, n, ilast, e.filler))) {
                                    ok = 0;
                                }
                            }
                        }
                    }
                }
                return ok;
            }
        }
    }
}

types_AxiomRef gate_axiom_ref_of(slop_arena* arena, owl2_RawAxiom ax) {
    {
        slop_option_rdf_IRI no_source = (slop_option_rdf_IRI){.has_value = false};
        return ((types_AxiomRef){.source = no_source, .text = owl2_render_axiom(arena, ax)});
    }
}

slop_list_rdf_IRI gate_collect_concept_classes(slop_arena* arena, owl2_RawConcept c, slop_list_rdf_IRI acc) {
    {
        __auto_type out = acc;
        __auto_type _mv_577 = c;
        switch (_mv_577.tag) {
            case owl2_RawConcept_rc_name:
            {
                __auto_type n = _mv_577.data.rc_name;
                __auto_type _mv_578 = n;
                switch (_mv_578.tag) {
                    case types_Node_class_node:
                    {
                        __auto_type i = _mv_578.data.class_node;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case types_Node_individual_node:
                    {
                        __auto_type _ = _mv_578.data.individual_node;
                        break;
                    }
                    case types_Node_fresh_node:
                    {
                        __auto_type _ = _mv_578.data.fresh_node;
                        break;
                    }
                }
                break;
            }
            case owl2_RawConcept_rc_and:
            {
                __auto_type cs = _mv_577.data.rc_and;
                {
                    __auto_type _coll = cs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        out = gate_collect_concept_classes(arena, x, out);
                    }
                }
                break;
            }
            case owl2_RawConcept_rc_some:
            {
                __auto_type f = _mv_577.data.rc_some.f1;
                out = gate_collect_concept_classes(arena, (*f), out);
                break;
            }
            default: {
                break;
            }
        }
        return out;
    }
}

slop_list_gate_EntityRef gate_collect_entity_refs(slop_arena* arena, slop_list_owl2_RawAxiom axs) {
    {
        __auto_type out = ((slop_list_gate_EntityRef){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                {
                    __auto_type classes = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 });
                    __auto_type roles = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0 });
                    __auto_type _mv_579 = ax;
                    switch (_mv_579.tag) {
                        case owl2_RawAxiom_ra_sub_class_of:
                        {
                            __auto_type l = _mv_579.data.ra_sub_class_of.f0;
                            __auto_type rr = _mv_579.data.ra_sub_class_of.f1;
                            classes = gate_collect_concept_classes(arena, (*l), classes);
                            classes = gate_collect_concept_classes(arena, (*rr), classes);
                            break;
                        }
                        case owl2_RawAxiom_ra_equivalent_classes:
                        {
                            __auto_type cs = _mv_579.data.ra_equivalent_classes;
                            {
                                __auto_type _coll = cs;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type x = _coll.data[_i];
                                    classes = gate_collect_concept_classes(arena, x, classes);
                                }
                            }
                            break;
                        }
                        case owl2_RawAxiom_ra_disjoint_classes:
                        {
                            __auto_type cs = _mv_579.data.ra_disjoint_classes;
                            {
                                __auto_type _coll = cs;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type x = _coll.data[_i];
                                    classes = gate_collect_concept_classes(arena, x, classes);
                                }
                            }
                            break;
                        }
                        case owl2_RawAxiom_ra_object_property_domain:
                        {
                            __auto_type rl = _mv_579.data.ra_object_property_domain.f0;
                            __auto_type c = _mv_579.data.ra_object_property_domain.f1;
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (rl); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            classes = gate_collect_concept_classes(arena, (*c), classes);
                            break;
                        }
                        case owl2_RawAxiom_ra_object_property_range:
                        {
                            __auto_type rl = _mv_579.data.ra_object_property_range.f0;
                            __auto_type c = _mv_579.data.ra_object_property_range.f1;
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (rl); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            classes = gate_collect_concept_classes(arena, (*c), classes);
                            break;
                        }
                        case owl2_RawAxiom_ra_class_assertion:
                        {
                            __auto_type ca = _mv_579.data.ra_class_assertion;
                            classes = gate_collect_concept_classes(arena, (*ca.concept), classes);
                            break;
                        }
                        case owl2_RawAxiom_ra_sub_object_property:
                        {
                            __auto_type a = _mv_579.data.ra_sub_object_property.f0;
                            __auto_type b = _mv_579.data.ra_sub_object_property.f1;
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        case owl2_RawAxiom_ra_property_chain:
                        {
                            __auto_type ch = _mv_579.data.ra_property_chain;
                            {
                                __auto_type _coll = ch.steps;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type st = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(roles); __auto_type _item = (st); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (ch.super); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        case owl2_RawAxiom_ra_object_property_assertion:
                        {
                            __auto_type e = _mv_579.data.ra_object_property_assertion;
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (e.role); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        case owl2_RawAxiom_ra_negative_assertion:
                        {
                            __auto_type e = _mv_579.data.ra_negative_assertion;
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (e.role); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        case owl2_RawAxiom_ra_property_characteristic:
                        {
                            __auto_type rl = _mv_579.data.ra_property_characteristic.f1;
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (rl); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                    {
                        __auto_type _coll = classes;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type i = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (((gate_EntityRef){.kind = types_EntityKind_entity_class, .entity = i, .axiom = ax})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                    {
                        __auto_type _coll = roles;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type rl = _coll.data[_i];
                            __auto_type _mv_580 = rl;
                            switch (_mv_580.tag) {
                                case types_RoleId_named_role:
                                {
                                    __auto_type i = _mv_580.data.named_role;
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((gate_EntityRef){.kind = types_EntityKind_entity_object_property, .entity = i, .axiom = ax})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    break;
                                }
                                case types_RoleId_fresh_role:
                                {
                                    __auto_type _ = _mv_580.data.fresh_role;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        return out;
    }
}

uint8_t gate_entity_ref_declared(owl2_Signature sig, gate_EntityRef e) {
    __auto_type _mv_581 = e.kind;
    if (_mv_581 == types_EntityKind_entity_class) {
        return owl2_signature_has_class(sig, e.entity);
    } else if (_mv_581 == types_EntityKind_entity_object_property) {
        return owl2_signature_has_object_property(sig, e.entity);
    } else if (_mv_581 == types_EntityKind_entity_data_property) {
        return 1;
    } else if (_mv_581 == types_EntityKind_entity_annotation_property) {
        return 1;
    } else if (_mv_581 == types_EntityKind_entity_individual) {
        return 1;
    } else if (_mv_581 == types_EntityKind_entity_datatype) {
        return 1;
    }
    SLOP_UNREACHABLE();
}

uint8_t gate_same_entity(gate_EntityRef a, gate_EntityRef b) {
    return ((a.kind == b.kind) && (canon_iri_cmp(a.entity, b.entity) == 0));
}

slop_list_types_Omission gate_missing_declarations(slop_arena* arena, owl2_Signature sig, slop_list_gate_EntityRef refs) {
    {
        __auto_type out = ((slop_list_types_Omission){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type seen = ((slop_list_gate_EntityRef){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = refs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (!(gate_entity_ref_declared(sig, e))) {
                    {
                        uint8_t dup = 0;
                        {
                            __auto_type _coll = seen;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type s2 = _coll.data[_i];
                                if (gate_same_entity(s2, e)) {
                                    dup = 1;
                                }
                            }
                        }
                        if (!(dup)) {
                            {
                                __auto_type refs_for = ((slop_list_types_AxiomRef){ .data = NULL, .len = 0, .cap = 0 });
                                ({ __auto_type _lst_p = &(seen); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                {
                                    __auto_type _coll = refs;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type f = _coll.data[_i];
                                        if (gate_same_entity(f, e)) {
                                            ({ __auto_type _lst_p = &(refs_for); __auto_type _item = (gate_axiom_ref_of(arena, f.axiom)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_Omission){ .tag = types_Omission_missing_declaration, .data.missing_declaration = ((types_MissingDeclaration){.kind = e.kind, .entity = e.entity, .referring = canon_sort_axiom_refs(arena, refs_for)}) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
            }
        }
        return out;
    }
}

