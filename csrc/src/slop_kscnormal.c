#include "../runtime/slop_runtime.h"
#include "slop_kscnormal.h"

kscnormal_KscState* kscnormal_new_ksc_state(slop_arena* arena);
uint8_t kscnormal_k_emit(slop_arena* arena, kscnormal_KscState* p, types_KscAxiom ax);
types_KName kscnormal_mint(slop_arena* arena, kscnormal_KscState* p, slop_string key);
types_KName kscnormal_top_name(void);
types_KName kscnormal_bottom_name(void);
types_KTerm kscnormal_as_term(types_KName k);
rdf_IRI kscnormal_node_iri(types_Node n);
types_KTerm kscnormal_node_term(types_Node n);
slop_string kscnormal_name_key(slop_arena* arena, types_KName k);
slop_string kscnormal_term_key(slop_arena* arena, types_KTerm t);
owl2_RawConcept* kscnormal_box(slop_arena* arena, owl2_RawConcept c);
owl2_RawConcept kscnormal_node_of(types_Node n);
types_KName kscnormal_nominal_neg(slop_arena* arena, kscnormal_KscState* p, rdf_IRI a);
types_KName kscnormal_nominal_pos(slop_arena* arena, kscnormal_KscState* p, rdf_IRI a);
slop_option_types_Node kscnormal_single_individual(slop_list_types_Node ns);
types_KName kscnormal_neg_name(slop_arena* arena, kscnormal_KscState* p, types_Node n);
types_KName kscnormal_pos_name(slop_arena* arena, kscnormal_KscState* p, types_Node n);
types_KName kscnormal_neg_atom(slop_arena* arena, kscnormal_KscState* p, owl2_RawConcept c);
types_KName kscnormal_fold_conjuncts(slop_arena* arena, kscnormal_KscState* p, slop_list_owl2_RawConcept conj, int64_t n);
types_KName kscnormal_pos_atom(slop_arena* arena, kscnormal_KscState* p, owl2_RawConcept c);
owl2_RawConcept kscnormal_name_concept(types_KName k);
types_KName kscnormal_lhs_name(slop_arena* arena, kscnormal_KscState* p, slop_list_owl2_RawConcept conj, int64_t n);
types_KTerm kscnormal_sub_lhs(slop_arena* arena, kscnormal_KscState* p, owl2_RawConcept c);
types_KName kscnormal_class_target(slop_arena* arena, kscnormal_KscState* p, types_KTerm t);
uint8_t kscnormal_emit_inclusion(slop_arena* arena, kscnormal_KscState* p, slop_list_owl2_RawConcept conj, int64_t n, types_KTerm target);
int64_t kscnormal_witness(slop_arena* arena, kscnormal_KscState* p, types_KName a, types_RoleId r, types_KName b);
uint8_t kscnormal_normalize_gci(slop_arena* arena, kscnormal_KscState* p, owl2_RawConcept lhs, owl2_RawConcept rhs);
uint8_t kscnormal_decompose_chain(slop_arena* arena, kscnormal_KscState* p, owl2_RawChain ch);
uint8_t kscnormal_normalize_axiom(slop_arena* arena, kscnormal_KscState* p, owl2_RawAxiom ax);
types_Node kscnormal_node_at_or_top(slop_list_types_Node ns, int64_t i);
types_RoleId kscnormal_bottom_role(void);
uint8_t kscnormal_axiom_mentions_role(types_KscAxiom ax, types_RoleId r);
uint8_t kscnormal_mentions_bottom_role(slop_list_types_KscAxiom axs);
kscnormal_KscOutput kscnormal_normalize_ksc(slop_arena* arena, slop_list_owl2_RawAxiom axs);
slop_string kscnormal_render_ksc_axiom(slop_arena* arena, types_KscAxiom ax);
slop_string kscnormal_fact2(slop_arena* arena, slop_string name, slop_string x, slop_string y);
slop_string kscnormal_fact3(slop_arena* arena, slop_string name, slop_string x, slop_string y, slop_string z);
slop_string kscnormal_fact4(slop_arena* arena, slop_string name, slop_string x, slop_string y, slop_string z, slop_string w);

kscnormal_KscState* kscnormal_new_ksc_state(slop_arena* arena) {
    {
        __auto_type p = ((kscnormal_KscState*)(({ __auto_type _alloc = (kscnormal_KscState*)slop_arena_alloc(arena, sizeof(kscnormal_KscState)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = ((kscnormal_KscState){.axioms = ((slop_list_types_KscAxiom){ .data = NULL, .len = 0, .cap = 0 }), .registry = naming_new_registry(arena)});
        return p;
    }
}

uint8_t kscnormal_k_emit(slop_arena* arena, kscnormal_KscState* p, types_KscAxiom ax) {
    {
        __auto_type s = (*p);
        ({ __auto_type _lst_p = &(s.axioms); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        (*p) = s;
        return 1;
    }
}

types_KName kscnormal_mint(slop_arena* arena, kscnormal_KscState* p, slop_string key) {
    return ((types_KName){ .tag = types_KName_k_fresh, .data.k_fresh = naming_fresh_id(arena, (*p).registry, key) });
}

types_KName kscnormal_top_name(void) {
    return ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = vocab_OWL_THING}) });
}

types_KName kscnormal_bottom_name(void) {
    return ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = vocab_OWL_NOTHING}) });
}

types_KTerm kscnormal_as_term(types_KName k) {
    return ((types_KTerm){ .tag = types_KTerm_k_name, .data.k_name = k });
}

rdf_IRI kscnormal_node_iri(types_Node n) {
    __auto_type _mv_764 = n;
    switch (_mv_764.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_764.data.class_node;
            return i;
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_764.data.individual_node;
            return i;
        }
        case types_Node_fresh_node:
        {
            __auto_type _ = _mv_764.data.fresh_node;
            return ((rdf_IRI){.value = SLOP_STR("")});
        }
    }
    SLOP_UNREACHABLE();
}

types_KTerm kscnormal_node_term(types_Node n) {
    __auto_type _mv_765 = n;
    switch (_mv_765.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_765.data.class_node;
            return ((types_KTerm){ .tag = types_KTerm_k_name, .data.k_name = ((types_KName){ .tag = types_KName_k_class, .data.k_class = i }) });
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_765.data.individual_node;
            return ((types_KTerm){ .tag = types_KTerm_k_nominal, .data.k_nominal = i });
        }
        case types_Node_fresh_node:
        {
            __auto_type j = _mv_765.data.fresh_node;
            return ((types_KTerm){ .tag = types_KTerm_k_name, .data.k_name = ((types_KName){ .tag = types_KName_k_fresh, .data.k_fresh = j }) });
        }
    }
    SLOP_UNREACHABLE();
}

slop_string kscnormal_name_key(slop_arena* arena, types_KName k) {
    __auto_type _mv_766 = k;
    switch (_mv_766.tag) {
        case types_KName_k_class:
        {
            __auto_type i = _mv_766.data.k_class;
            return naming_node_key(arena, ((types_Node){ .tag = types_Node_class_node, .data.class_node = i }));
        }
        case types_KName_k_fresh:
        {
            __auto_type j = _mv_766.data.k_fresh;
            return naming_node_key(arena, ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = j }));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string kscnormal_term_key(slop_arena* arena, types_KTerm t) {
    __auto_type _mv_767 = t;
    switch (_mv_767.tag) {
        case types_KTerm_k_name:
        {
            __auto_type k = _mv_767.data.k_name;
            return kscnormal_name_key(arena, k);
        }
        case types_KTerm_k_nominal:
        {
            __auto_type i = _mv_767.data.k_nominal;
            return naming_node_key(arena, ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = i }));
        }
    }
    SLOP_UNREACHABLE();
}

owl2_RawConcept* kscnormal_box(slop_arena* arena, owl2_RawConcept c) {
    {
        __auto_type q = ((owl2_RawConcept*)(({ __auto_type _alloc = (owl2_RawConcept*)slop_arena_alloc(arena, sizeof(owl2_RawConcept)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*q) = c;
        return q;
    }
}

owl2_RawConcept kscnormal_node_of(types_Node n) {
    return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_name, .data.rc_name = n });
}

types_KName kscnormal_nominal_neg(slop_arena* arena, kscnormal_KscState* p, rdf_IRI a) {
    {
        __auto_type key = naming_node_key(arena, ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = a }));
        __auto_type x = kscnormal_mint(arena, p, key);
        if (!(naming_neg_defined((*p).registry, key))) {
            naming_mark_neg(arena, (*p).registry, key);
            kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_sub, .data.k_sub = { .f0 = ((types_KTerm){ .tag = types_KTerm_k_nominal, .data.k_nominal = a }), .f1 = kscnormal_as_term(x) } }));
        }
        return x;
    }
}

types_KName kscnormal_nominal_pos(slop_arena* arena, kscnormal_KscState* p, rdf_IRI a) {
    {
        __auto_type key = naming_node_key(arena, ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = a }));
        __auto_type x = kscnormal_mint(arena, p, key);
        if (!(naming_pos_defined((*p).registry, key))) {
            naming_mark_pos(arena, (*p).registry, key);
            kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_sub, .data.k_sub = { .f0 = kscnormal_as_term(x), .f1 = ((types_KTerm){ .tag = types_KTerm_k_nominal, .data.k_nominal = a }) } }));
        }
        return x;
    }
}

slop_option_types_Node kscnormal_single_individual(slop_list_types_Node ns) {
    if (((int64_t)((ns).len)) == 1) {
        return (slop_option_types_Node){.has_value = 1, .value = naming_node_at(ns, 0)};
    } else {
        return (slop_option_types_Node){.has_value = false};
    }
}

types_KName kscnormal_neg_name(slop_arena* arena, kscnormal_KscState* p, types_Node n) {
    __auto_type _mv_768 = n;
    switch (_mv_768.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_768.data.class_node;
            return ((types_KName){ .tag = types_KName_k_class, .data.k_class = i });
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_768.data.individual_node;
            return kscnormal_nominal_neg(arena, p, i);
        }
        case types_Node_fresh_node:
        {
            __auto_type j = _mv_768.data.fresh_node;
            return ((types_KName){ .tag = types_KName_k_fresh, .data.k_fresh = j });
        }
    }
    SLOP_UNREACHABLE();
}

types_KName kscnormal_pos_name(slop_arena* arena, kscnormal_KscState* p, types_Node n) {
    __auto_type _mv_769 = n;
    switch (_mv_769.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_769.data.class_node;
            return ((types_KName){ .tag = types_KName_k_class, .data.k_class = i });
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_769.data.individual_node;
            return kscnormal_nominal_pos(arena, p, i);
        }
        case types_Node_fresh_node:
        {
            __auto_type j = _mv_769.data.fresh_node;
            return ((types_KName){ .tag = types_KName_k_fresh, .data.k_fresh = j });
        }
    }
    SLOP_UNREACHABLE();
}

types_KName kscnormal_neg_atom(slop_arena* arena, kscnormal_KscState* p, owl2_RawConcept c) {
    __auto_type _mv_770 = c;
    switch (_mv_770.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_770.data.rc_name;
            return kscnormal_neg_name(arena, p, n);
        }
        case owl2_RawConcept_rc_thing:
        {
            return kscnormal_top_name();
        }
        case owl2_RawConcept_rc_nothing:
        {
            return kscnormal_bottom_name();
        }
        case owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_770.data.rc_oneof;
            __auto_type _mv_771 = kscnormal_single_individual(ns);
            if (_mv_771.has_value) {
                __auto_type a = _mv_771.value;
                return kscnormal_neg_name(arena, p, a);
            } else if (!_mv_771.has_value) {
                return kscnormal_bottom_name();
            }
            SLOP_UNREACHABLE();
        }
        case owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_770.data.rc_some.f0;
            __auto_type f = _mv_770.data.rc_some.f1;
            {
                __auto_type key = naming_concept_key(arena, c);
                __auto_type x = kscnormal_mint(arena, p, key);
                if (!(naming_neg_defined((*p).registry, key))) {
                    naming_mark_neg(arena, (*p).registry, key);
                    kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_some_lhs, .data.k_some_lhs = { .f0 = r, .f1 = kscnormal_neg_atom(arena, p, (*f)), .f2 = x } }));
                }
                return x;
            }
        }
        case owl2_RawConcept_rc_has_value:
        {
            __auto_type r = _mv_770.data.rc_has_value.f0;
            __auto_type a = _mv_770.data.rc_has_value.f1;
            {
                __auto_type key = naming_concept_key(arena, c);
                __auto_type x = kscnormal_mint(arena, p, key);
                if (!(naming_neg_defined((*p).registry, key))) {
                    naming_mark_neg(arena, (*p).registry, key);
                    kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_some_lhs, .data.k_some_lhs = { .f0 = r, .f1 = kscnormal_neg_name(arena, p, a), .f2 = x } }));
                }
                return x;
            }
        }
        case owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_770.data.rc_has_self;
            {
                __auto_type key = naming_concept_key(arena, c);
                __auto_type x = kscnormal_mint(arena, p, key);
                if (!(naming_neg_defined((*p).registry, key))) {
                    naming_mark_neg(arena, (*p).registry, key);
                    kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_self_lhs, .data.k_self_lhs = { .f0 = r, .f1 = x } }));
                }
                return x;
            }
        }
        case owl2_RawConcept_rc_and:
        {
            __auto_type _ = _mv_770.data.rc_and;
            {
                __auto_type flat = naming_flatten_and(arena, c, ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0 }));
                __auto_type n = ((int64_t)(((int64_t)((flat).len))));
                if (n == 0) {
                    return kscnormal_top_name();
                } else if (n == 1) {
                    return kscnormal_neg_atom(arena, p, owl2_concept_at(flat, 0));
                } else {
                    return kscnormal_fold_conjuncts(arena, p, flat, n);
                }
            }
        }
        default: {
            return kscnormal_bottom_name();
        }
    }
}

types_KName kscnormal_fold_conjuncts(slop_arena* arena, kscnormal_KscState* p, slop_list_owl2_RawConcept conj, int64_t n) {
    {
        __auto_type acc = kscnormal_neg_atom(arena, p, owl2_concept_at(conj, 0));
        int64_t i = 1;
        while (i < n) {
            {
                __auto_type x = kscnormal_mint(arena, p, naming_prefix_text(arena, conj, (i + 1)));
                kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_and, .data.k_and = { .f0 = acc, .f1 = kscnormal_neg_atom(arena, p, owl2_concept_at(conj, i)), .f2 = x } }));
                acc = x;
                i = (i + 1);
            }
        }
        return acc;
    }
}

types_KName kscnormal_pos_atom(slop_arena* arena, kscnormal_KscState* p, owl2_RawConcept c) {
    __auto_type _mv_772 = c;
    switch (_mv_772.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_772.data.rc_name;
            return kscnormal_pos_name(arena, p, n);
        }
        case owl2_RawConcept_rc_thing:
        {
            return kscnormal_top_name();
        }
        case owl2_RawConcept_rc_nothing:
        {
            return kscnormal_bottom_name();
        }
        case owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_772.data.rc_oneof;
            __auto_type _mv_773 = kscnormal_single_individual(ns);
            if (_mv_773.has_value) {
                __auto_type a = _mv_773.value;
                return kscnormal_pos_name(arena, p, a);
            } else if (!_mv_773.has_value) {
                return kscnormal_top_name();
            }
            SLOP_UNREACHABLE();
        }
        default: {
            {
                __auto_type key = naming_concept_key(arena, c);
                __auto_type x = kscnormal_mint(arena, p, key);
                if (!(naming_pos_defined((*p).registry, key))) {
                    naming_mark_pos(arena, (*p).registry, key);
                    kscnormal_normalize_gci(arena, p, kscnormal_name_concept(x), c);
                }
                return x;
            }
        }
    }
}

owl2_RawConcept kscnormal_name_concept(types_KName k) {
    __auto_type _mv_774 = k;
    switch (_mv_774.tag) {
        case types_KName_k_class:
        {
            __auto_type i = _mv_774.data.k_class;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_name, .data.rc_name = ((types_Node){ .tag = types_Node_class_node, .data.class_node = i }) });
        }
        case types_KName_k_fresh:
        {
            __auto_type j = _mv_774.data.k_fresh;
            return ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_name, .data.rc_name = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = j }) });
        }
    }
    SLOP_UNREACHABLE();
}

types_KName kscnormal_lhs_name(slop_arena* arena, kscnormal_KscState* p, slop_list_owl2_RawConcept conj, int64_t n) {
    if (n == 0) {
        return kscnormal_top_name();
    } else if (n == 1) {
        return kscnormal_neg_atom(arena, p, owl2_concept_at(conj, 0));
    } else {
        return kscnormal_fold_conjuncts(arena, p, conj, n);
    }
}

types_KTerm kscnormal_sub_lhs(slop_arena* arena, kscnormal_KscState* p, owl2_RawConcept c) {
    __auto_type _mv_775 = c;
    switch (_mv_775.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_775.data.rc_name;
            __auto_type _mv_776 = n;
            switch (_mv_776.tag) {
                case types_Node_individual_node:
                {
                    __auto_type i = _mv_776.data.individual_node;
                    return ((types_KTerm){ .tag = types_KTerm_k_nominal, .data.k_nominal = i });
                }
                default: {
                    return kscnormal_as_term(kscnormal_neg_atom(arena, p, c));
                }
            }
        }
        case owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_775.data.rc_oneof;
            __auto_type _mv_777 = kscnormal_single_individual(ns);
            if (_mv_777.has_value) {
                __auto_type a = _mv_777.value;
                return kscnormal_node_term(a);
            } else if (!_mv_777.has_value) {
                return kscnormal_as_term(kscnormal_neg_atom(arena, p, c));
            }
            SLOP_UNREACHABLE();
        }
        default: {
            return kscnormal_as_term(kscnormal_neg_atom(arena, p, c));
        }
    }
}

types_KName kscnormal_class_target(slop_arena* arena, kscnormal_KscState* p, types_KTerm t) {
    __auto_type _mv_778 = t;
    switch (_mv_778.tag) {
        case types_KTerm_k_name:
        {
            __auto_type k = _mv_778.data.k_name;
            return k;
        }
        case types_KTerm_k_nominal:
        {
            __auto_type i = _mv_778.data.k_nominal;
            return kscnormal_nominal_pos(arena, p, i);
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t kscnormal_emit_inclusion(slop_arena* arena, kscnormal_KscState* p, slop_list_owl2_RawConcept conj, int64_t n, types_KTerm target) {
    if (n == 0) {
        return kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_sub, .data.k_sub = { .f0 = kscnormal_as_term(kscnormal_top_name()), .f1 = target } }));
    } else if (n == 1) {
        return kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_sub, .data.k_sub = { .f0 = kscnormal_sub_lhs(arena, p, owl2_concept_at(conj, 0)), .f1 = target } }));
    } else if (n == 2) {
        return kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_and, .data.k_and = { .f0 = kscnormal_neg_atom(arena, p, owl2_concept_at(conj, 0)), .f1 = kscnormal_neg_atom(arena, p, owl2_concept_at(conj, 1)), .f2 = kscnormal_class_target(arena, p, target) } }));
    } else {
        {
            __auto_type acc = kscnormal_fold_conjuncts(arena, p, conj, (n - 1));
            return kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_and, .data.k_and = { .f0 = acc, .f1 = kscnormal_neg_atom(arena, p, owl2_concept_at(conj, (n - 1))), .f2 = kscnormal_class_target(arena, p, target) } }));
        }
    }
}

int64_t kscnormal_witness(slop_arena* arena, kscnormal_KscState* p, types_KName a, types_RoleId r, types_KName b) {
    return naming_fresh_id(arena, (*p).registry, string_concat(arena, SLOP_STR("witness("), string_concat(arena, kscnormal_name_key(arena, a), string_concat(arena, SLOP_STR(" "), string_concat(arena, naming_role_key(arena, r), string_concat(arena, SLOP_STR(" "), string_concat(arena, kscnormal_name_key(arena, b), SLOP_STR(")"))))))));
}

uint8_t kscnormal_normalize_gci(slop_arena* arena, kscnormal_KscState* p, owl2_RawConcept lhs, owl2_RawConcept rhs) {
    __auto_type _mv_779 = rhs;
    switch (_mv_779.tag) {
        case owl2_RawConcept_rc_and:
        {
            __auto_type ds = _mv_779.data.rc_and;
            {
                __auto_type ok = 1;
                {
                    __auto_type _coll = ds;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type d = _coll.data[_i];
                        ok = kscnormal_normalize_gci(arena, p, lhs, d);
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
                __auto_type conj = naming_flatten_and(arena, lhs, ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0 }));
                __auto_type n = ((int64_t)(((int64_t)((conj).len))));
                __auto_type _mv_780 = rhs;
                switch (_mv_780.tag) {
                    case owl2_RawConcept_rc_name:
                    {
                        __auto_type b = _mv_780.data.rc_name;
                        return kscnormal_emit_inclusion(arena, p, conj, n, kscnormal_node_term(b));
                    }
                    case owl2_RawConcept_rc_nothing:
                    {
                        return kscnormal_emit_inclusion(arena, p, conj, n, kscnormal_as_term(kscnormal_bottom_name()));
                    }
                    case owl2_RawConcept_rc_oneof:
                    {
                        __auto_type ns = _mv_780.data.rc_oneof;
                        __auto_type _mv_781 = kscnormal_single_individual(ns);
                        if (_mv_781.has_value) {
                            __auto_type a = _mv_781.value;
                            return kscnormal_emit_inclusion(arena, p, conj, n, kscnormal_node_term(a));
                        } else if (!_mv_781.has_value) {
                            return 1;
                        }
                        SLOP_UNREACHABLE();
                    }
                    case owl2_RawConcept_rc_some:
                    {
                        __auto_type r = _mv_780.data.rc_some.f0;
                        __auto_type f = _mv_780.data.rc_some.f1;
                        {
                            __auto_type a = kscnormal_lhs_name(arena, p, conj, n);
                            __auto_type b = kscnormal_pos_atom(arena, p, (*f));
                            return kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_some_rhs, .data.k_some_rhs = { .f0 = a, .f1 = r, .f2 = b, .f3 = kscnormal_witness(arena, p, a, r, b) } }));
                        }
                    }
                    case owl2_RawConcept_rc_has_value:
                    {
                        __auto_type r = _mv_780.data.rc_has_value.f0;
                        __auto_type c = _mv_780.data.rc_has_value.f1;
                        {
                            __auto_type a = kscnormal_lhs_name(arena, p, conj, n);
                            __auto_type b = kscnormal_pos_name(arena, p, c);
                            return kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_some_rhs, .data.k_some_rhs = { .f0 = a, .f1 = r, .f2 = b, .f3 = kscnormal_witness(arena, p, a, r, b) } }));
                        }
                    }
                    case owl2_RawConcept_rc_has_self:
                    {
                        __auto_type r = _mv_780.data.rc_has_self;
                        return kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_self_rhs, .data.k_self_rhs = { .f0 = kscnormal_lhs_name(arena, p, conj, n), .f1 = r } }));
                    }
                    default: {
                        return 1;
                    }
                }
            }
        }
    }
}

uint8_t kscnormal_decompose_chain(slop_arena* arena, kscnormal_KscState* p, owl2_RawChain ch) {
    {
        __auto_type steps = ch.steps;
        __auto_type len = ((int64_t)(((int64_t)((ch.steps).len))));
        if (len < 2) {
            return 1;
        } else if (len == 2) {
            return kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_chain, .data.k_chain = { .f0 = naming_role_at_n(steps, 0), .f1 = naming_role_at_n(steps, 1), .f2 = ch.super } }));
        } else {
            {
                __auto_type acc = naming_role_at_n(steps, 0);
                int64_t i = 1;
                while (i < (len - 1)) {
                    {
                        __auto_type f = ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = naming_fresh_role_id(arena, (*p).registry, naming_prefix_role_text(arena, steps, (i + 1), ch.super)) });
                        kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_chain, .data.k_chain = { .f0 = acc, .f1 = naming_role_at_n(steps, i), .f2 = f } }));
                        acc = f;
                        i = (i + 1);
                    }
                }
                return kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_chain, .data.k_chain = { .f0 = acc, .f1 = naming_role_at_n(steps, (len - 1)), .f2 = ch.super } }));
            }
        }
    }
}

uint8_t kscnormal_normalize_axiom(slop_arena* arena, kscnormal_KscState* p, owl2_RawAxiom ax) {
    __auto_type _mv_782 = ax;
    switch (_mv_782.tag) {
        case owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_782.data.ra_sub_class_of.f0;
            __auto_type r = _mv_782.data.ra_sub_class_of.f1;
            return kscnormal_normalize_gci(arena, p, (*l), (*r));
        }
        case owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_782.data.ra_disjoint_classes;
            return kscnormal_normalize_gci(arena, p, ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_and, .data.rc_and = cs }), ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_nothing }));
        }
        case owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_782.data.ra_object_property_domain.f0;
            __auto_type c = _mv_782.data.ra_object_property_domain.f1;
            return kscnormal_normalize_gci(arena, p, ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_some, .data.rc_some = { .f0 = r, .f1 = kscnormal_box(arena, ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_thing })) } }), (*c));
        }
        case owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type r = _mv_782.data.ra_object_property_range.f0;
            __auto_type c = _mv_782.data.ra_object_property_range.f1;
            return kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_range, .data.k_range = { .f0 = r, .f1 = kscnormal_pos_atom(arena, p, (*c)) } }));
        }
        case owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type a = _mv_782.data.ra_sub_object_property.f0;
            __auto_type b = _mv_782.data.ra_sub_object_property.f1;
            return kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_role, .data.k_role = { .f0 = a, .f1 = b } }));
        }
        case owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_782.data.ra_property_chain;
            return kscnormal_decompose_chain(arena, p, ch);
        }
        case owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_782.data.ra_class_assertion;
            return kscnormal_normalize_gci(arena, p, kscnormal_node_of(ca.subject), (*ca.concept));
        }
        case owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type e = _mv_782.data.ra_object_property_assertion;
            return kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_role_assert, .data.k_role_assert = { .f0 = kscnormal_node_iri(e.from), .f1 = e.role, .f2 = kscnormal_node_iri(e.to) } }));
        }
        case owl2_RawAxiom_ra_same_individual:
        {
            __auto_type ns = _mv_782.data.ra_same_individual;
            {
                __auto_type a0 = kscnormal_node_term(kscnormal_node_at_or_top(ns, 0));
                __auto_type i = 1;
                __auto_type n = ((int64_t)(((int64_t)((ns).len))));
                while (i < n) {
                    {
                        __auto_type ai = kscnormal_node_term(kscnormal_node_at_or_top(ns, i));
                        kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_sub, .data.k_sub = { .f0 = a0, .f1 = ai } }));
                        kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_sub, .data.k_sub = { .f0 = ai, .f1 = a0 } }));
                        i = (i + 1);
                    }
                }
                return 1;
            }
        }
        case owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type ns = _mv_782.data.ra_different_individuals;
            {
                __auto_type n = ((int64_t)(((int64_t)((ns).len))));
                __auto_type i = 0;
                while (i < n) {
                    {
                        __auto_type j = (i + 1);
                        while (j < n) {
                            {
                                __auto_type pair = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0 });
                                ({ __auto_type _lst_p = &(pair); __auto_type _item = (kscnormal_node_of(kscnormal_node_at_or_top(ns, i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                ({ __auto_type _lst_p = &(pair); __auto_type _item = (kscnormal_node_of(kscnormal_node_at_or_top(ns, j))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                kscnormal_normalize_gci(arena, p, ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_and, .data.rc_and = pair }), ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_nothing }));
                                j = (j + 1);
                            }
                        }
                        i = (i + 1);
                    }
                }
                return 1;
            }
        }
        case owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type e = _mv_782.data.ra_negative_assertion;
            {
                __auto_type both = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0 });
                ({ __auto_type _lst_p = &(both); __auto_type _item = (kscnormal_node_of(e.from)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(both); __auto_type _item = (((owl2_RawConcept){ .tag = owl2_RawConcept_rc_has_value, .data.rc_has_value = { .f0 = e.role, .f1 = e.to } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                return kscnormal_normalize_gci(arena, p, ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_and, .data.rc_and = both }), ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_nothing }));
            }
        }
        case owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type c = _mv_782.data.ra_property_characteristic.f0;
            __auto_type r = _mv_782.data.ra_property_characteristic.f1;
            __auto_type _mv_783 = c;
            if (_mv_783 == owl2_PropCharacteristic_prop_reflexive) {
                {
                    __auto_type s = ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = naming_fresh_role_id(arena, (*p).registry, string_concat(arena, SLOP_STR("reflexive "), naming_role_key(arena, r))) });
                    kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_self_rhs, .data.k_self_rhs = { .f0 = kscnormal_top_name(), .f1 = s } }));
                    return kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_role, .data.k_role = { .f0 = s, .f1 = r } }));
                }
            } else {
                return 1;
            }
        }
        default: {
            return 1;
        }
    }
}

types_Node kscnormal_node_at_or_top(slop_list_types_Node ns, int64_t i) {
    __auto_type _mv_784 = ({ __auto_type _lst = ns; size_t _idx = (size_t)i; slop_option_types_Node _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_784.has_value) {
        __auto_type v = _mv_784.value;
        return v;
    } else if (!_mv_784.has_value) {
        return ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = vocab_OWL_THING}) });
    }
    SLOP_UNREACHABLE();
}

types_RoleId kscnormal_bottom_role(void) {
    return ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = ((rdf_IRI){.value = vocab_OWL_BOTTOM_OBJECT_PROPERTY}) });
}

uint8_t kscnormal_axiom_mentions_role(types_KscAxiom ax, types_RoleId r) {
    __auto_type _mv_785 = ax;
    switch (_mv_785.tag) {
        case types_KscAxiom_k_sub:
        {
            return 0;
        }
        case types_KscAxiom_k_and:
        {
            return 0;
        }
        case types_KscAxiom_k_some_lhs:
        {
            __auto_type s = _mv_785.data.k_some_lhs.f0;
            return types_role_eq(s, r);
        }
        case types_KscAxiom_k_some_rhs:
        {
            __auto_type s = _mv_785.data.k_some_rhs.f1;
            return types_role_eq(s, r);
        }
        case types_KscAxiom_k_self_lhs:
        {
            __auto_type s = _mv_785.data.k_self_lhs.f0;
            return types_role_eq(s, r);
        }
        case types_KscAxiom_k_self_rhs:
        {
            __auto_type s = _mv_785.data.k_self_rhs.f1;
            return types_role_eq(s, r);
        }
        case types_KscAxiom_k_role:
        {
            __auto_type s = _mv_785.data.k_role.f0;
            __auto_type t = _mv_785.data.k_role.f1;
            if (types_role_eq(s, r)) {
                return 1;
            } else {
                return types_role_eq(t, r);
            }
        }
        case types_KscAxiom_k_chain:
        {
            __auto_type s = _mv_785.data.k_chain.f0;
            __auto_type t = _mv_785.data.k_chain.f1;
            __auto_type u = _mv_785.data.k_chain.f2;
            if (types_role_eq(s, r)) {
                return 1;
            } else {
                if (types_role_eq(t, r)) {
                    return 1;
                } else {
                    return types_role_eq(u, r);
                }
            }
        }
        case types_KscAxiom_k_range:
        {
            __auto_type s = _mv_785.data.k_range.f0;
            return types_role_eq(s, r);
        }
        case types_KscAxiom_k_role_assert:
        {
            __auto_type s = _mv_785.data.k_role_assert.f1;
            return types_role_eq(s, r);
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t kscnormal_mentions_bottom_role(slop_list_types_KscAxiom axs) {
    {
        __auto_type n = kscnormal_bottom_role();
        uint8_t found = 0;
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                if (kscnormal_axiom_mentions_role(ax, n)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

kscnormal_KscOutput kscnormal_normalize_ksc(slop_arena* arena, slop_list_owl2_RawAxiom axs) {
    {
        __auto_type p = kscnormal_new_ksc_state(arena);
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                kscnormal_normalize_axiom(arena, p, ax);
            }
        }
        if (kscnormal_mentions_bottom_role((*p).axioms)) {
            kscnormal_k_emit(arena, p, ((types_KscAxiom){ .tag = types_KscAxiom_k_some_lhs, .data.k_some_lhs = { .f0 = kscnormal_bottom_role(), .f1 = kscnormal_top_name(), .f2 = kscnormal_bottom_name() } }));
        }
        return ((kscnormal_KscOutput){.axioms = (*p).axioms, .fresh_count = naming_fresh_count((*p).registry), .fresh_role_count = naming_fresh_role_count((*p).registry)});
    }
}

slop_string kscnormal_render_ksc_axiom(slop_arena* arena, types_KscAxiom ax) {
    __auto_type _mv_786 = ax;
    switch (_mv_786.tag) {
        case types_KscAxiom_k_sub:
        {
            __auto_type a = _mv_786.data.k_sub.f0;
            __auto_type b = _mv_786.data.k_sub.f1;
            return kscnormal_fact2(arena, SLOP_STR("subClass"), kscnormal_term_key(arena, a), kscnormal_term_key(arena, b));
        }
        case types_KscAxiom_k_and:
        {
            __auto_type a = _mv_786.data.k_and.f0;
            __auto_type b = _mv_786.data.k_and.f1;
            __auto_type c = _mv_786.data.k_and.f2;
            return kscnormal_fact3(arena, SLOP_STR("subConj"), kscnormal_name_key(arena, a), kscnormal_name_key(arena, b), kscnormal_name_key(arena, c));
        }
        case types_KscAxiom_k_some_lhs:
        {
            __auto_type r = _mv_786.data.k_some_lhs.f0;
            __auto_type a = _mv_786.data.k_some_lhs.f1;
            __auto_type c = _mv_786.data.k_some_lhs.f2;
            return kscnormal_fact3(arena, SLOP_STR("subEx"), naming_role_key(arena, r), kscnormal_name_key(arena, a), kscnormal_name_key(arena, c));
        }
        case types_KscAxiom_k_some_rhs:
        {
            __auto_type a = _mv_786.data.k_some_rhs.f0;
            __auto_type r = _mv_786.data.k_some_rhs.f1;
            __auto_type b = _mv_786.data.k_some_rhs.f2;
            __auto_type w = _mv_786.data.k_some_rhs.f3;
            return kscnormal_fact4(arena, SLOP_STR("supEx"), kscnormal_name_key(arena, a), naming_role_key(arena, r), kscnormal_name_key(arena, b), naming_node_key(arena, ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = w })));
        }
        case types_KscAxiom_k_self_lhs:
        {
            __auto_type r = _mv_786.data.k_self_lhs.f0;
            __auto_type c = _mv_786.data.k_self_lhs.f1;
            return kscnormal_fact2(arena, SLOP_STR("subSelf"), naming_role_key(arena, r), kscnormal_name_key(arena, c));
        }
        case types_KscAxiom_k_self_rhs:
        {
            __auto_type a = _mv_786.data.k_self_rhs.f0;
            __auto_type r = _mv_786.data.k_self_rhs.f1;
            return kscnormal_fact2(arena, SLOP_STR("supSelf"), kscnormal_name_key(arena, a), naming_role_key(arena, r));
        }
        case types_KscAxiom_k_role:
        {
            __auto_type r = _mv_786.data.k_role.f0;
            __auto_type t = _mv_786.data.k_role.f1;
            return kscnormal_fact2(arena, SLOP_STR("subRole"), naming_role_key(arena, r), naming_role_key(arena, t));
        }
        case types_KscAxiom_k_chain:
        {
            __auto_type r = _mv_786.data.k_chain.f0;
            __auto_type s = _mv_786.data.k_chain.f1;
            __auto_type t = _mv_786.data.k_chain.f2;
            return kscnormal_fact3(arena, SLOP_STR("subRChain"), naming_role_key(arena, r), naming_role_key(arena, s), naming_role_key(arena, t));
        }
        case types_KscAxiom_k_range:
        {
            __auto_type r = _mv_786.data.k_range.f0;
            __auto_type d = _mv_786.data.k_range.f1;
            return kscnormal_fact3(arena, SLOP_STR("supProd"), naming_role_key(arena, r), SLOP_STR("⊤"), kscnormal_name_key(arena, d));
        }
        case types_KscAxiom_k_role_assert:
        {
            __auto_type a = _mv_786.data.k_role_assert.f0;
            __auto_type r = _mv_786.data.k_role_assert.f1;
            __auto_type b = _mv_786.data.k_role_assert.f2;
            {
                __auto_type bk = naming_node_key(arena, ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = b }));
                return kscnormal_fact4(arena, SLOP_STR("supEx"), naming_node_key(arena, ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = a })), naming_role_key(arena, r), bk, bk);
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_string kscnormal_fact2(slop_arena* arena, slop_string name, slop_string x, slop_string y) {
    return string_concat(arena, name, string_concat(arena, SLOP_STR("("), string_concat(arena, x, string_concat(arena, SLOP_STR(", "), string_concat(arena, y, SLOP_STR(")"))))));
}

slop_string kscnormal_fact3(slop_arena* arena, slop_string name, slop_string x, slop_string y, slop_string z) {
    return kscnormal_fact2(arena, name, x, string_concat(arena, y, string_concat(arena, SLOP_STR(", "), z)));
}

slop_string kscnormal_fact4(slop_arena* arena, slop_string name, slop_string x, slop_string y, slop_string z, slop_string w) {
    return kscnormal_fact3(arena, name, x, y, string_concat(arena, z, string_concat(arena, SLOP_STR(", "), w)));
}

