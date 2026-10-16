#include "../runtime/slop_runtime.h"
#include "slop_kscnormal.h"

howl_kscnormal_KscState* howl_kscnormal_new_ksc_state(slop_arena* arena);
uint8_t howl_kscnormal_k_emit(slop_arena* arena, howl_kscnormal_KscState* p, howl_types_KscAxiom ax);
howl_types_KName howl_kscnormal_mint(slop_arena* arena, howl_kscnormal_KscState* p, slop_string key);
howl_types_KName howl_kscnormal_top_name(void);
howl_types_KName howl_kscnormal_bottom_name(void);
howl_types_KTerm howl_kscnormal_as_term(howl_types_KName k);
slop_rdf_rdf_IRI howl_kscnormal_node_iri(howl_types_Node n);
howl_types_KTerm howl_kscnormal_node_term(howl_types_Node n);
slop_string howl_kscnormal_name_key(slop_arena* arena, howl_types_KName k);
slop_string howl_kscnormal_term_key(slop_arena* arena, howl_types_KTerm t);
howl_owl2_RawConcept* howl_kscnormal_box(slop_arena* arena, howl_owl2_RawConcept c);
howl_owl2_RawConcept howl_kscnormal_node_of(howl_types_Node n);
howl_types_KName howl_kscnormal_nominal_neg(slop_arena* arena, howl_kscnormal_KscState* p, slop_rdf_rdf_IRI a);
howl_types_KName howl_kscnormal_nominal_pos(slop_arena* arena, howl_kscnormal_KscState* p, slop_rdf_rdf_IRI a);
slop_option_howl_types_Node howl_kscnormal_single_individual(slop_list_howl_types_Node ns);
howl_types_KName howl_kscnormal_neg_name(slop_arena* arena, howl_kscnormal_KscState* p, howl_types_Node n);
howl_types_KName howl_kscnormal_pos_name(slop_arena* arena, howl_kscnormal_KscState* p, howl_types_Node n);
howl_types_KName howl_kscnormal_neg_atom(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawConcept c);
howl_types_KName howl_kscnormal_fold_conjuncts(slop_arena* arena, howl_kscnormal_KscState* p, slop_list_howl_owl2_RawConcept conj, int64_t n);
howl_types_KName howl_kscnormal_pos_atom(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawConcept c);
howl_owl2_RawConcept howl_kscnormal_name_concept(howl_types_KName k);
howl_types_KName howl_kscnormal_lhs_name(slop_arena* arena, howl_kscnormal_KscState* p, slop_list_howl_owl2_RawConcept conj, int64_t n);
howl_types_KTerm howl_kscnormal_sub_lhs(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawConcept c);
howl_types_KName howl_kscnormal_class_target(slop_arena* arena, howl_kscnormal_KscState* p, howl_types_KTerm t);
uint8_t howl_kscnormal_emit_inclusion(slop_arena* arena, howl_kscnormal_KscState* p, slop_list_howl_owl2_RawConcept conj, int64_t n, howl_types_KTerm target);
int64_t howl_kscnormal_witness(slop_arena* arena, howl_kscnormal_KscState* p, howl_types_KName a, howl_types_RoleId r, howl_types_KName b);
uint8_t howl_kscnormal_normalize_gci(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawConcept lhs, howl_owl2_RawConcept rhs);
uint8_t howl_kscnormal_decompose_chain(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawChain ch);
uint8_t howl_kscnormal_normalize_axiom(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawAxiom ax);
howl_types_Node howl_kscnormal_node_at_or_top(slop_list_howl_types_Node ns, int64_t i);
howl_types_RoleId howl_kscnormal_bottom_role(void);
uint8_t howl_kscnormal_axiom_mentions_role(howl_types_KscAxiom ax, howl_types_RoleId r);
uint8_t howl_kscnormal_mentions_bottom_role(slop_list_howl_types_KscAxiom axs);
howl_kscnormal_KscOutput howl_kscnormal_normalize_ksc(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
slop_string howl_kscnormal_render_ksc_axiom(slop_arena* arena, howl_types_KscAxiom ax);
slop_string howl_kscnormal_fact2(slop_arena* arena, slop_string name, slop_string x, slop_string y);
slop_string howl_kscnormal_fact3(slop_arena* arena, slop_string name, slop_string x, slop_string y, slop_string z);
slop_string howl_kscnormal_fact4(slop_arena* arena, slop_string name, slop_string x, slop_string y, slop_string z, slop_string w);
howl_types_KName howl_kscnormal_copy_kname(slop_arena* arena, howl_types_KName n);
howl_types_KTerm howl_kscnormal_copy_kterm(slop_arena* arena, howl_types_KTerm t);
howl_types_KscAxiom howl_kscnormal_copy_ksc_axiom(slop_arena* arena, howl_types_KscAxiom ax);
slop_list_howl_types_KscAxiom howl_kscnormal_copy_ksc_axioms(slop_arena* arena, slop_list_howl_types_KscAxiom axs);

howl_kscnormal_KscState* howl_kscnormal_new_ksc_state(slop_arena* arena) {
    {
        __auto_type p = ((howl_kscnormal_KscState*)(({ __auto_type _alloc = (howl_kscnormal_KscState*)slop_arena_alloc(arena, sizeof(howl_kscnormal_KscState)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = ((howl_kscnormal_KscState){.axioms = ((slop_list_howl_types_KscAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .registry = howl_naming_new_registry(arena)});
        return p;
    }
}

uint8_t howl_kscnormal_k_emit(slop_arena* arena, howl_kscnormal_KscState* p, howl_types_KscAxiom ax) {
    {
        __auto_type s = (*p);
        (void)(({ __auto_type _lst_p = &(s.axioms); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (*p) = s;
        return 1;
    }
}

howl_types_KName howl_kscnormal_mint(slop_arena* arena, howl_kscnormal_KscState* p, slop_string key) {
    return ((howl_types_KName){ .tag = howl_types_KName_k_fresh, .data.k_fresh = howl_naming_fresh_id(arena, (*p).registry, key) });
}

howl_types_KName howl_kscnormal_top_name(void) {
    return ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_THING}) });
}

howl_types_KName howl_kscnormal_bottom_name(void) {
    return ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_NOTHING}) });
}

howl_types_KTerm howl_kscnormal_as_term(howl_types_KName k) {
    return ((howl_types_KTerm){ .tag = howl_types_KTerm_k_name, .data.k_name = k });
}

slop_rdf_rdf_IRI howl_kscnormal_node_iri(howl_types_Node n) {
    __auto_type _mv_1192 = n;
    switch (_mv_1192.tag) {
        case howl_types_Node_class_node:
        {
            __auto_type i = _mv_1192.data.class_node;
            return i;
        }
        case howl_types_Node_individual_node:
        {
            __auto_type i = _mv_1192.data.individual_node;
            return i;
        }
        case howl_types_Node_fresh_node:
        {
            __auto_type _ = _mv_1192.data.fresh_node;
            return ((slop_rdf_rdf_IRI){.value = SLOP_STR("")});
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_KTerm howl_kscnormal_node_term(howl_types_Node n) {
    __auto_type _mv_1193 = n;
    switch (_mv_1193.tag) {
        case howl_types_Node_class_node:
        {
            __auto_type i = _mv_1193.data.class_node;
            return ((howl_types_KTerm){ .tag = howl_types_KTerm_k_name, .data.k_name = ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = i }) });
        }
        case howl_types_Node_individual_node:
        {
            __auto_type i = _mv_1193.data.individual_node;
            return ((howl_types_KTerm){ .tag = howl_types_KTerm_k_nominal, .data.k_nominal = i });
        }
        case howl_types_Node_fresh_node:
        {
            __auto_type j = _mv_1193.data.fresh_node;
            return ((howl_types_KTerm){ .tag = howl_types_KTerm_k_name, .data.k_name = ((howl_types_KName){ .tag = howl_types_KName_k_fresh, .data.k_fresh = j }) });
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_kscnormal_name_key(slop_arena* arena, howl_types_KName k) {
    __auto_type _mv_1194 = k;
    switch (_mv_1194.tag) {
        case howl_types_KName_k_class:
        {
            __auto_type i = _mv_1194.data.k_class;
            return howl_naming_node_key(arena, ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = i }));
        }
        case howl_types_KName_k_fresh:
        {
            __auto_type j = _mv_1194.data.k_fresh;
            return howl_naming_node_key(arena, ((howl_types_Node){ .tag = howl_types_Node_fresh_node, .data.fresh_node = j }));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_kscnormal_term_key(slop_arena* arena, howl_types_KTerm t) {
    __auto_type _mv_1195 = t;
    switch (_mv_1195.tag) {
        case howl_types_KTerm_k_name:
        {
            __auto_type k = _mv_1195.data.k_name;
            return howl_kscnormal_name_key(arena, k);
        }
        case howl_types_KTerm_k_nominal:
        {
            __auto_type i = _mv_1195.data.k_nominal;
            return howl_naming_node_key(arena, ((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = i }));
        }
    }
    SLOP_UNREACHABLE();
}

howl_owl2_RawConcept* howl_kscnormal_box(slop_arena* arena, howl_owl2_RawConcept c) {
    {
        __auto_type q = ((howl_owl2_RawConcept*)(({ __auto_type _alloc = (howl_owl2_RawConcept*)slop_arena_alloc(arena, sizeof(howl_owl2_RawConcept)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*q) = c;
        return q;
    }
}

howl_owl2_RawConcept howl_kscnormal_node_of(howl_types_Node n) {
    return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_name, .data.rc_name = n });
}

howl_types_KName howl_kscnormal_nominal_neg(slop_arena* arena, howl_kscnormal_KscState* p, slop_rdf_rdf_IRI a) {
    {
        __auto_type key = howl_naming_node_key(arena, ((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = a }));
        __auto_type x = howl_kscnormal_mint(arena, p, key);
        if (!(howl_naming_neg_defined((*p).registry, key))) {
            howl_naming_mark_neg(arena, (*p).registry, key);
            howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_sub, .data.k_sub = { .f0 = ((howl_types_KTerm){ .tag = howl_types_KTerm_k_nominal, .data.k_nominal = a }), .f1 = howl_kscnormal_as_term(x) } }));
        }
        return x;
    }
}

howl_types_KName howl_kscnormal_nominal_pos(slop_arena* arena, howl_kscnormal_KscState* p, slop_rdf_rdf_IRI a) {
    {
        __auto_type key = howl_naming_node_key(arena, ((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = a }));
        __auto_type x = howl_kscnormal_mint(arena, p, key);
        if (!(howl_naming_pos_defined((*p).registry, key))) {
            howl_naming_mark_pos(arena, (*p).registry, key);
            howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_sub, .data.k_sub = { .f0 = howl_kscnormal_as_term(x), .f1 = ((howl_types_KTerm){ .tag = howl_types_KTerm_k_nominal, .data.k_nominal = a }) } }));
        }
        return x;
    }
}

slop_option_howl_types_Node howl_kscnormal_single_individual(slop_list_howl_types_Node ns) {
    if (((int64_t)((ns).len)) == 1) {
        return (slop_option_howl_types_Node){.has_value = 1, .value = howl_naming_node_at(ns, 0)};
    } else {
        return (slop_option_howl_types_Node){.has_value = false};
    }
}

howl_types_KName howl_kscnormal_neg_name(slop_arena* arena, howl_kscnormal_KscState* p, howl_types_Node n) {
    __auto_type _mv_1196 = n;
    switch (_mv_1196.tag) {
        case howl_types_Node_class_node:
        {
            __auto_type i = _mv_1196.data.class_node;
            return ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = i });
        }
        case howl_types_Node_individual_node:
        {
            __auto_type i = _mv_1196.data.individual_node;
            return howl_kscnormal_nominal_neg(arena, p, i);
        }
        case howl_types_Node_fresh_node:
        {
            __auto_type j = _mv_1196.data.fresh_node;
            return ((howl_types_KName){ .tag = howl_types_KName_k_fresh, .data.k_fresh = j });
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_KName howl_kscnormal_pos_name(slop_arena* arena, howl_kscnormal_KscState* p, howl_types_Node n) {
    __auto_type _mv_1197 = n;
    switch (_mv_1197.tag) {
        case howl_types_Node_class_node:
        {
            __auto_type i = _mv_1197.data.class_node;
            return ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = i });
        }
        case howl_types_Node_individual_node:
        {
            __auto_type i = _mv_1197.data.individual_node;
            return howl_kscnormal_nominal_pos(arena, p, i);
        }
        case howl_types_Node_fresh_node:
        {
            __auto_type j = _mv_1197.data.fresh_node;
            return ((howl_types_KName){ .tag = howl_types_KName_k_fresh, .data.k_fresh = j });
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_KName howl_kscnormal_neg_atom(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawConcept c) {
    __auto_type _mv_1198 = c;
    switch (_mv_1198.tag) {
        case howl_owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_1198.data.rc_name;
            return howl_kscnormal_neg_name(arena, p, n);
        }
        case howl_owl2_RawConcept_rc_thing:
        {
            return howl_kscnormal_top_name();
        }
        case howl_owl2_RawConcept_rc_nothing:
        {
            return howl_kscnormal_bottom_name();
        }
        case howl_owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_1198.data.rc_oneof;
            __auto_type _mv_1199 = howl_kscnormal_single_individual(ns);
            if (_mv_1199.has_value) {
                __auto_type a = _mv_1199.value;
                return howl_kscnormal_neg_name(arena, p, a);
            } else if (!_mv_1199.has_value) {
                return howl_kscnormal_bottom_name();
            }
            SLOP_UNREACHABLE();
        }
        case howl_owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_1198.data.rc_some.f0;
            __auto_type f = _mv_1198.data.rc_some.f1;
            {
                __auto_type key = howl_naming_concept_key(arena, c);
                __auto_type x = howl_kscnormal_mint(arena, p, key);
                if (!(howl_naming_neg_defined((*p).registry, key))) {
                    howl_naming_mark_neg(arena, (*p).registry, key);
                    howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_some_lhs, .data.k_some_lhs = { .f0 = r, .f1 = howl_kscnormal_neg_atom(arena, p, (*f)), .f2 = x } }));
                }
                return x;
            }
        }
        case howl_owl2_RawConcept_rc_has_value:
        {
            __auto_type r = _mv_1198.data.rc_has_value.f0;
            __auto_type a = _mv_1198.data.rc_has_value.f1;
            {
                __auto_type key = howl_naming_concept_key(arena, c);
                __auto_type x = howl_kscnormal_mint(arena, p, key);
                if (!(howl_naming_neg_defined((*p).registry, key))) {
                    howl_naming_mark_neg(arena, (*p).registry, key);
                    howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_some_lhs, .data.k_some_lhs = { .f0 = r, .f1 = howl_kscnormal_neg_name(arena, p, a), .f2 = x } }));
                }
                return x;
            }
        }
        case howl_owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_1198.data.rc_has_self;
            {
                __auto_type key = howl_naming_concept_key(arena, c);
                __auto_type x = howl_kscnormal_mint(arena, p, key);
                if (!(howl_naming_neg_defined((*p).registry, key))) {
                    howl_naming_mark_neg(arena, (*p).registry, key);
                    howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_self_lhs, .data.k_self_lhs = { .f0 = r, .f1 = x } }));
                }
                return x;
            }
        }
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type _ = _mv_1198.data.rc_and;
            {
                __auto_type flat = howl_naming_flatten_and(arena, c, ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
                __auto_type n = ((int64_t)(((int64_t)((flat).len))));
                if (n == 0) {
                    return howl_kscnormal_top_name();
                } else if (n == 1) {
                    return howl_kscnormal_neg_atom(arena, p, howl_owl2_concept_at(flat, 0));
                } else {
                    return howl_kscnormal_fold_conjuncts(arena, p, flat, n);
                }
            }
        }
        default: {
            return howl_kscnormal_bottom_name();
        }
    }
}

howl_types_KName howl_kscnormal_fold_conjuncts(slop_arena* arena, howl_kscnormal_KscState* p, slop_list_howl_owl2_RawConcept conj, int64_t n) {
    {
        __auto_type acc = howl_kscnormal_neg_atom(arena, p, howl_owl2_concept_at(conj, 0));
        int64_t i = 1;
        while (i < n) {
            {
                __auto_type x = howl_kscnormal_mint(arena, p, howl_naming_prefix_text(arena, conj, (i + 1)));
                howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_and, .data.k_and = { .f0 = acc, .f1 = howl_kscnormal_neg_atom(arena, p, howl_owl2_concept_at(conj, i)), .f2 = x } }));
                acc = x;
                i = (i + 1);
            }
        }
        return acc;
    }
}

howl_types_KName howl_kscnormal_pos_atom(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawConcept c) {
    __auto_type _mv_1200 = c;
    switch (_mv_1200.tag) {
        case howl_owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_1200.data.rc_name;
            return howl_kscnormal_pos_name(arena, p, n);
        }
        case howl_owl2_RawConcept_rc_thing:
        {
            return howl_kscnormal_top_name();
        }
        case howl_owl2_RawConcept_rc_nothing:
        {
            return howl_kscnormal_bottom_name();
        }
        case howl_owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_1200.data.rc_oneof;
            __auto_type _mv_1201 = howl_kscnormal_single_individual(ns);
            if (_mv_1201.has_value) {
                __auto_type a = _mv_1201.value;
                return howl_kscnormal_pos_name(arena, p, a);
            } else if (!_mv_1201.has_value) {
                return howl_kscnormal_top_name();
            }
            SLOP_UNREACHABLE();
        }
        default: {
            {
                __auto_type key = howl_naming_concept_key(arena, c);
                __auto_type x = howl_kscnormal_mint(arena, p, key);
                if (!(howl_naming_pos_defined((*p).registry, key))) {
                    howl_naming_mark_pos(arena, (*p).registry, key);
                    howl_kscnormal_normalize_gci(arena, p, howl_kscnormal_name_concept(x), c);
                }
                return x;
            }
        }
    }
}

howl_owl2_RawConcept howl_kscnormal_name_concept(howl_types_KName k) {
    __auto_type _mv_1202 = k;
    switch (_mv_1202.tag) {
        case howl_types_KName_k_class:
        {
            __auto_type i = _mv_1202.data.k_class;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_name, .data.rc_name = ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = i }) });
        }
        case howl_types_KName_k_fresh:
        {
            __auto_type j = _mv_1202.data.k_fresh;
            return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_name, .data.rc_name = ((howl_types_Node){ .tag = howl_types_Node_fresh_node, .data.fresh_node = j }) });
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_KName howl_kscnormal_lhs_name(slop_arena* arena, howl_kscnormal_KscState* p, slop_list_howl_owl2_RawConcept conj, int64_t n) {
    if (n == 0) {
        return howl_kscnormal_top_name();
    } else if (n == 1) {
        return howl_kscnormal_neg_atom(arena, p, howl_owl2_concept_at(conj, 0));
    } else {
        return howl_kscnormal_fold_conjuncts(arena, p, conj, n);
    }
}

howl_types_KTerm howl_kscnormal_sub_lhs(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawConcept c) {
    __auto_type _mv_1203 = c;
    switch (_mv_1203.tag) {
        case howl_owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_1203.data.rc_name;
            __auto_type _mv_1204 = n;
            switch (_mv_1204.tag) {
                case howl_types_Node_individual_node:
                {
                    __auto_type i = _mv_1204.data.individual_node;
                    return ((howl_types_KTerm){ .tag = howl_types_KTerm_k_nominal, .data.k_nominal = i });
                }
                default: {
                    return howl_kscnormal_as_term(howl_kscnormal_neg_atom(arena, p, c));
                }
            }
        }
        case howl_owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_1203.data.rc_oneof;
            __auto_type _mv_1205 = howl_kscnormal_single_individual(ns);
            if (_mv_1205.has_value) {
                __auto_type a = _mv_1205.value;
                return howl_kscnormal_node_term(a);
            } else if (!_mv_1205.has_value) {
                return howl_kscnormal_as_term(howl_kscnormal_neg_atom(arena, p, c));
            }
            SLOP_UNREACHABLE();
        }
        default: {
            return howl_kscnormal_as_term(howl_kscnormal_neg_atom(arena, p, c));
        }
    }
}

howl_types_KName howl_kscnormal_class_target(slop_arena* arena, howl_kscnormal_KscState* p, howl_types_KTerm t) {
    __auto_type _mv_1206 = t;
    switch (_mv_1206.tag) {
        case howl_types_KTerm_k_name:
        {
            __auto_type k = _mv_1206.data.k_name;
            return k;
        }
        case howl_types_KTerm_k_nominal:
        {
            __auto_type i = _mv_1206.data.k_nominal;
            return howl_kscnormal_nominal_pos(arena, p, i);
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_kscnormal_emit_inclusion(slop_arena* arena, howl_kscnormal_KscState* p, slop_list_howl_owl2_RawConcept conj, int64_t n, howl_types_KTerm target) {
    if (n == 0) {
        return howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_sub, .data.k_sub = { .f0 = howl_kscnormal_as_term(howl_kscnormal_top_name()), .f1 = target } }));
    } else if (n == 1) {
        return howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_sub, .data.k_sub = { .f0 = howl_kscnormal_sub_lhs(arena, p, howl_owl2_concept_at(conj, 0)), .f1 = target } }));
    } else if (n == 2) {
        return howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_and, .data.k_and = { .f0 = howl_kscnormal_neg_atom(arena, p, howl_owl2_concept_at(conj, 0)), .f1 = howl_kscnormal_neg_atom(arena, p, howl_owl2_concept_at(conj, 1)), .f2 = howl_kscnormal_class_target(arena, p, target) } }));
    } else {
        {
            __auto_type acc = howl_kscnormal_fold_conjuncts(arena, p, conj, (n - 1));
            return howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_and, .data.k_and = { .f0 = acc, .f1 = howl_kscnormal_neg_atom(arena, p, howl_owl2_concept_at(conj, (n - 1))), .f2 = howl_kscnormal_class_target(arena, p, target) } }));
        }
    }
}

int64_t howl_kscnormal_witness(slop_arena* arena, howl_kscnormal_KscState* p, howl_types_KName a, howl_types_RoleId r, howl_types_KName b) {
    return howl_naming_fresh_id(arena, (*p).registry, string_concat(arena, SLOP_STR("witness("), string_concat(arena, howl_kscnormal_name_key(arena, a), string_concat(arena, SLOP_STR(" "), string_concat(arena, howl_naming_role_key(arena, r), string_concat(arena, SLOP_STR(" "), string_concat(arena, howl_kscnormal_name_key(arena, b), SLOP_STR(")"))))))));
}

uint8_t howl_kscnormal_normalize_gci(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawConcept lhs, howl_owl2_RawConcept rhs) {
    __auto_type _mv_1207 = rhs;
    switch (_mv_1207.tag) {
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type ds = _mv_1207.data.rc_and;
            {
                uint8_t ok = 1;
                {
                    __auto_type _coll = ds;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type d = _coll.data[_i];
                        ok = howl_kscnormal_normalize_gci(arena, p, lhs, d);
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
                __auto_type _mv_1208 = rhs;
                switch (_mv_1208.tag) {
                    case howl_owl2_RawConcept_rc_name:
                    {
                        __auto_type b = _mv_1208.data.rc_name;
                        return howl_kscnormal_emit_inclusion(arena, p, conj, n, howl_kscnormal_node_term(b));
                    }
                    case howl_owl2_RawConcept_rc_nothing:
                    {
                        return howl_kscnormal_emit_inclusion(arena, p, conj, n, howl_kscnormal_as_term(howl_kscnormal_bottom_name()));
                    }
                    case howl_owl2_RawConcept_rc_oneof:
                    {
                        __auto_type ns = _mv_1208.data.rc_oneof;
                        __auto_type _mv_1209 = howl_kscnormal_single_individual(ns);
                        if (_mv_1209.has_value) {
                            __auto_type a = _mv_1209.value;
                            return howl_kscnormal_emit_inclusion(arena, p, conj, n, howl_kscnormal_node_term(a));
                        } else if (!_mv_1209.has_value) {
                            return 1;
                        }
                        SLOP_UNREACHABLE();
                    }
                    case howl_owl2_RawConcept_rc_some:
                    {
                        __auto_type r = _mv_1208.data.rc_some.f0;
                        __auto_type f = _mv_1208.data.rc_some.f1;
                        {
                            __auto_type a = howl_kscnormal_lhs_name(arena, p, conj, n);
                            __auto_type b = howl_kscnormal_pos_atom(arena, p, (*f));
                            return howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_some_rhs, .data.k_some_rhs = { .f0 = a, .f1 = r, .f2 = b, .f3 = howl_kscnormal_witness(arena, p, a, r, b) } }));
                        }
                    }
                    case howl_owl2_RawConcept_rc_has_value:
                    {
                        __auto_type r = _mv_1208.data.rc_has_value.f0;
                        __auto_type c = _mv_1208.data.rc_has_value.f1;
                        {
                            __auto_type a = howl_kscnormal_lhs_name(arena, p, conj, n);
                            __auto_type b = howl_kscnormal_pos_name(arena, p, c);
                            return howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_some_rhs, .data.k_some_rhs = { .f0 = a, .f1 = r, .f2 = b, .f3 = howl_kscnormal_witness(arena, p, a, r, b) } }));
                        }
                    }
                    case howl_owl2_RawConcept_rc_has_self:
                    {
                        __auto_type r = _mv_1208.data.rc_has_self;
                        return howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_self_rhs, .data.k_self_rhs = { .f0 = howl_kscnormal_lhs_name(arena, p, conj, n), .f1 = r } }));
                    }
                    default: {
                        return 1;
                    }
                }
            }
        }
    }
}

uint8_t howl_kscnormal_decompose_chain(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawChain ch) {
    {
        __auto_type steps = ch.steps;
        __auto_type len = ((int64_t)(((int64_t)((ch.steps).len))));
        if (len < 2) {
            return 1;
        } else if (len == 2) {
            return howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_chain, .data.k_chain = { .f0 = howl_naming_role_at_n(steps, 0), .f1 = howl_naming_role_at_n(steps, 1), .f2 = ch.super } }));
        } else {
            {
                __auto_type acc = howl_naming_role_at_n(steps, 0);
                int64_t i = 1;
                while (i < (len - 1)) {
                    {
                        __auto_type f = ((howl_types_RoleId){ .tag = howl_types_RoleId_fresh_role, .data.fresh_role = howl_naming_fresh_role_id(arena, (*p).registry, howl_naming_prefix_role_text(arena, steps, (i + 1), ch.super)) });
                        howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_chain, .data.k_chain = { .f0 = acc, .f1 = howl_naming_role_at_n(steps, i), .f2 = f } }));
                        acc = f;
                        i = (i + 1);
                    }
                }
                return howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_chain, .data.k_chain = { .f0 = acc, .f1 = howl_naming_role_at_n(steps, (len - 1)), .f2 = ch.super } }));
            }
        }
    }
}

uint8_t howl_kscnormal_normalize_axiom(slop_arena* arena, howl_kscnormal_KscState* p, howl_owl2_RawAxiom ax) {
    __auto_type _mv_1210 = ax;
    switch (_mv_1210.tag) {
        case howl_owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_1210.data.ra_sub_class_of.f0;
            __auto_type r = _mv_1210.data.ra_sub_class_of.f1;
            return howl_kscnormal_normalize_gci(arena, p, (*l), (*r));
        }
        case howl_owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_1210.data.ra_disjoint_classes;
            return howl_kscnormal_normalize_gci(arena, p, ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_and, .data.rc_and = cs }), ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_nothing }));
        }
        case howl_owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_1210.data.ra_object_property_domain.f0;
            __auto_type c = _mv_1210.data.ra_object_property_domain.f1;
            return howl_kscnormal_normalize_gci(arena, p, ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_some, .data.rc_some = { .f0 = r, .f1 = howl_kscnormal_box(arena, ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_thing })) } }), (*c));
        }
        case howl_owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type r = _mv_1210.data.ra_object_property_range.f0;
            __auto_type c = _mv_1210.data.ra_object_property_range.f1;
            return howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_range, .data.k_range = { .f0 = r, .f1 = howl_kscnormal_pos_atom(arena, p, (*c)) } }));
        }
        case howl_owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type a = _mv_1210.data.ra_sub_object_property.f0;
            __auto_type b = _mv_1210.data.ra_sub_object_property.f1;
            return howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_role, .data.k_role = { .f0 = a, .f1 = b } }));
        }
        case howl_owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_1210.data.ra_property_chain;
            return howl_kscnormal_decompose_chain(arena, p, ch);
        }
        case howl_owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_1210.data.ra_class_assertion;
            return howl_kscnormal_normalize_gci(arena, p, howl_kscnormal_node_of(ca.subject), (*ca.concept));
        }
        case howl_owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type e = _mv_1210.data.ra_object_property_assertion;
            return howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_role_assert, .data.k_role_assert = { .f0 = howl_kscnormal_node_iri(e.from), .f1 = e.role, .f2 = howl_kscnormal_node_iri(e.to) } }));
        }
        case howl_owl2_RawAxiom_ra_same_individual:
        {
            __auto_type ns = _mv_1210.data.ra_same_individual;
            {
                __auto_type a0 = howl_kscnormal_node_term(howl_kscnormal_node_at_or_top(ns, 0));
                int64_t i = 1;
                __auto_type n = ((int64_t)(((int64_t)((ns).len))));
                while (i < n) {
                    {
                        __auto_type ai = howl_kscnormal_node_term(howl_kscnormal_node_at_or_top(ns, i));
                        howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_sub, .data.k_sub = { .f0 = a0, .f1 = ai } }));
                        howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_sub, .data.k_sub = { .f0 = ai, .f1 = a0 } }));
                        i = (i + 1);
                    }
                }
                return 1;
            }
        }
        case howl_owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type ns = _mv_1210.data.ra_different_individuals;
            {
                __auto_type n = ((int64_t)(((int64_t)((ns).len))));
                int64_t i = 0;
                while (i < n) {
                    {
                        int64_t j = (i + 1);
                        while (j < n) {
                            {
                                __auto_type pair = ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                                ({ __auto_type _lst_p = &(pair); __auto_type _item = (howl_kscnormal_node_of(howl_kscnormal_node_at_or_top(ns, i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                ({ __auto_type _lst_p = &(pair); __auto_type _item = (howl_kscnormal_node_of(howl_kscnormal_node_at_or_top(ns, j))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                howl_kscnormal_normalize_gci(arena, p, ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_and, .data.rc_and = pair }), ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_nothing }));
                                j = (j + 1);
                            }
                        }
                        i = (i + 1);
                    }
                }
                return 1;
            }
        }
        case howl_owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type e = _mv_1210.data.ra_negative_assertion;
            {
                __auto_type both = ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                ({ __auto_type _lst_p = &(both); __auto_type _item = (howl_kscnormal_node_of(e.from)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(both); __auto_type _item = (((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_has_value, .data.rc_has_value = { .f0 = e.role, .f1 = e.to } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                return howl_kscnormal_normalize_gci(arena, p, ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_and, .data.rc_and = both }), ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_nothing }));
            }
        }
        case howl_owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type c = _mv_1210.data.ra_property_characteristic.f0;
            __auto_type r = _mv_1210.data.ra_property_characteristic.f1;
            __auto_type _mv_1211 = c;
            if (_mv_1211 == howl_owl2_PropCharacteristic_prop_reflexive) {
                {
                    __auto_type s = ((howl_types_RoleId){ .tag = howl_types_RoleId_fresh_role, .data.fresh_role = howl_naming_fresh_role_id(arena, (*p).registry, string_concat(arena, SLOP_STR("reflexive "), howl_naming_role_key(arena, r))) });
                    howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_self_rhs, .data.k_self_rhs = { .f0 = howl_kscnormal_top_name(), .f1 = s } }));
                    return howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_role, .data.k_role = { .f0 = s, .f1 = r } }));
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

howl_types_Node howl_kscnormal_node_at_or_top(slop_list_howl_types_Node ns, int64_t i) {
    __auto_type _mv_1212 = ({ __auto_type _lst = ns; size_t _idx = (size_t)i; slop_option_howl_types_Node _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1212.has_value) {
        __auto_type v = _mv_1212.value;
        return v;
    } else if (!_mv_1212.has_value) {
        return ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_THING}) });
    }
    SLOP_UNREACHABLE();
}

howl_types_RoleId howl_kscnormal_bottom_role(void) {
    return ((howl_types_RoleId){ .tag = howl_types_RoleId_named_role, .data.named_role = ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_BOTTOM_OBJECT_PROPERTY}) });
}

uint8_t howl_kscnormal_axiom_mentions_role(howl_types_KscAxiom ax, howl_types_RoleId r) {
    __auto_type _mv_1213 = ax;
    switch (_mv_1213.tag) {
        case howl_types_KscAxiom_k_sub:
        {
            return 0;
        }
        case howl_types_KscAxiom_k_and:
        {
            return 0;
        }
        case howl_types_KscAxiom_k_some_lhs:
        {
            __auto_type s = _mv_1213.data.k_some_lhs.f0;
            return howl_types_role_eq(s, r);
        }
        case howl_types_KscAxiom_k_some_rhs:
        {
            __auto_type s = _mv_1213.data.k_some_rhs.f1;
            return howl_types_role_eq(s, r);
        }
        case howl_types_KscAxiom_k_self_lhs:
        {
            __auto_type s = _mv_1213.data.k_self_lhs.f0;
            return howl_types_role_eq(s, r);
        }
        case howl_types_KscAxiom_k_self_rhs:
        {
            __auto_type s = _mv_1213.data.k_self_rhs.f1;
            return howl_types_role_eq(s, r);
        }
        case howl_types_KscAxiom_k_role:
        {
            __auto_type s = _mv_1213.data.k_role.f0;
            __auto_type t = _mv_1213.data.k_role.f1;
            if (howl_types_role_eq(s, r)) {
                return 1;
            } else {
                return howl_types_role_eq(t, r);
            }
        }
        case howl_types_KscAxiom_k_chain:
        {
            __auto_type s = _mv_1213.data.k_chain.f0;
            __auto_type t = _mv_1213.data.k_chain.f1;
            __auto_type u = _mv_1213.data.k_chain.f2;
            if (howl_types_role_eq(s, r)) {
                return 1;
            } else {
                if (howl_types_role_eq(t, r)) {
                    return 1;
                } else {
                    return howl_types_role_eq(u, r);
                }
            }
        }
        case howl_types_KscAxiom_k_range:
        {
            __auto_type s = _mv_1213.data.k_range.f0;
            return howl_types_role_eq(s, r);
        }
        case howl_types_KscAxiom_k_role_assert:
        {
            __auto_type s = _mv_1213.data.k_role_assert.f1;
            return howl_types_role_eq(s, r);
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_kscnormal_mentions_bottom_role(slop_list_howl_types_KscAxiom axs) {
    {
        __auto_type n = howl_kscnormal_bottom_role();
        uint8_t found = 0;
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                if (howl_kscnormal_axiom_mentions_role(ax, n)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

howl_kscnormal_KscOutput howl_kscnormal_normalize_ksc(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs) {
    {
        __auto_type p = howl_kscnormal_new_ksc_state(arena);
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                howl_kscnormal_normalize_axiom(arena, p, ax);
            }
        }
        if (howl_kscnormal_mentions_bottom_role((*p).axioms)) {
            howl_kscnormal_k_emit(arena, p, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_some_lhs, .data.k_some_lhs = { .f0 = howl_kscnormal_bottom_role(), .f1 = howl_kscnormal_top_name(), .f2 = howl_kscnormal_bottom_name() } }));
        }
        return ((howl_kscnormal_KscOutput){.axioms = (*p).axioms, .fresh_count = howl_naming_fresh_count((*p).registry), .fresh_role_count = howl_naming_fresh_role_count((*p).registry)});
    }
}

slop_string howl_kscnormal_render_ksc_axiom(slop_arena* arena, howl_types_KscAxiom ax) {
    __auto_type _mv_1214 = ax;
    switch (_mv_1214.tag) {
        case howl_types_KscAxiom_k_sub:
        {
            __auto_type a = _mv_1214.data.k_sub.f0;
            __auto_type b = _mv_1214.data.k_sub.f1;
            return howl_kscnormal_fact2(arena, SLOP_STR("subClass"), howl_kscnormal_term_key(arena, a), howl_kscnormal_term_key(arena, b));
        }
        case howl_types_KscAxiom_k_and:
        {
            __auto_type a = _mv_1214.data.k_and.f0;
            __auto_type b = _mv_1214.data.k_and.f1;
            __auto_type c = _mv_1214.data.k_and.f2;
            return howl_kscnormal_fact3(arena, SLOP_STR("subConj"), howl_kscnormal_name_key(arena, a), howl_kscnormal_name_key(arena, b), howl_kscnormal_name_key(arena, c));
        }
        case howl_types_KscAxiom_k_some_lhs:
        {
            __auto_type r = _mv_1214.data.k_some_lhs.f0;
            __auto_type a = _mv_1214.data.k_some_lhs.f1;
            __auto_type c = _mv_1214.data.k_some_lhs.f2;
            return howl_kscnormal_fact3(arena, SLOP_STR("subEx"), howl_naming_role_key(arena, r), howl_kscnormal_name_key(arena, a), howl_kscnormal_name_key(arena, c));
        }
        case howl_types_KscAxiom_k_some_rhs:
        {
            __auto_type a = _mv_1214.data.k_some_rhs.f0;
            __auto_type r = _mv_1214.data.k_some_rhs.f1;
            __auto_type b = _mv_1214.data.k_some_rhs.f2;
            __auto_type w = _mv_1214.data.k_some_rhs.f3;
            return howl_kscnormal_fact4(arena, SLOP_STR("supEx"), howl_kscnormal_name_key(arena, a), howl_naming_role_key(arena, r), howl_kscnormal_name_key(arena, b), howl_naming_node_key(arena, ((howl_types_Node){ .tag = howl_types_Node_fresh_node, .data.fresh_node = w })));
        }
        case howl_types_KscAxiom_k_self_lhs:
        {
            __auto_type r = _mv_1214.data.k_self_lhs.f0;
            __auto_type c = _mv_1214.data.k_self_lhs.f1;
            return howl_kscnormal_fact2(arena, SLOP_STR("subSelf"), howl_naming_role_key(arena, r), howl_kscnormal_name_key(arena, c));
        }
        case howl_types_KscAxiom_k_self_rhs:
        {
            __auto_type a = _mv_1214.data.k_self_rhs.f0;
            __auto_type r = _mv_1214.data.k_self_rhs.f1;
            return howl_kscnormal_fact2(arena, SLOP_STR("supSelf"), howl_kscnormal_name_key(arena, a), howl_naming_role_key(arena, r));
        }
        case howl_types_KscAxiom_k_role:
        {
            __auto_type r = _mv_1214.data.k_role.f0;
            __auto_type t = _mv_1214.data.k_role.f1;
            return howl_kscnormal_fact2(arena, SLOP_STR("subRole"), howl_naming_role_key(arena, r), howl_naming_role_key(arena, t));
        }
        case howl_types_KscAxiom_k_chain:
        {
            __auto_type r = _mv_1214.data.k_chain.f0;
            __auto_type s = _mv_1214.data.k_chain.f1;
            __auto_type t = _mv_1214.data.k_chain.f2;
            return howl_kscnormal_fact3(arena, SLOP_STR("subRChain"), howl_naming_role_key(arena, r), howl_naming_role_key(arena, s), howl_naming_role_key(arena, t));
        }
        case howl_types_KscAxiom_k_range:
        {
            __auto_type r = _mv_1214.data.k_range.f0;
            __auto_type d = _mv_1214.data.k_range.f1;
            return howl_kscnormal_fact3(arena, SLOP_STR("supProd"), howl_naming_role_key(arena, r), SLOP_STR("⊤"), howl_kscnormal_name_key(arena, d));
        }
        case howl_types_KscAxiom_k_role_assert:
        {
            __auto_type a = _mv_1214.data.k_role_assert.f0;
            __auto_type r = _mv_1214.data.k_role_assert.f1;
            __auto_type b = _mv_1214.data.k_role_assert.f2;
            {
                __auto_type bk = howl_naming_node_key(arena, ((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = b }));
                return howl_kscnormal_fact4(arena, SLOP_STR("supEx"), howl_naming_node_key(arena, ((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = a })), howl_naming_role_key(arena, r), bk, bk);
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_kscnormal_fact2(slop_arena* arena, slop_string name, slop_string x, slop_string y) {
    return string_concat(arena, name, string_concat(arena, SLOP_STR("("), string_concat(arena, x, string_concat(arena, SLOP_STR(", "), string_concat(arena, y, SLOP_STR(")"))))));
}

slop_string howl_kscnormal_fact3(slop_arena* arena, slop_string name, slop_string x, slop_string y, slop_string z) {
    return howl_kscnormal_fact2(arena, name, x, string_concat(arena, y, string_concat(arena, SLOP_STR(", "), z)));
}

slop_string howl_kscnormal_fact4(slop_arena* arena, slop_string name, slop_string x, slop_string y, slop_string z, slop_string w) {
    return howl_kscnormal_fact3(arena, name, x, y, string_concat(arena, z, string_concat(arena, SLOP_STR(", "), w)));
}

howl_types_KName howl_kscnormal_copy_kname(slop_arena* arena, howl_types_KName n) {
    __auto_type _mv_1215 = n;
    switch (_mv_1215.tag) {
        case howl_types_KName_k_class:
        {
            __auto_type i = _mv_1215.data.k_class;
            return ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = howl_types_copy_iri(arena, i) });
        }
        case howl_types_KName_k_fresh:
        {
            __auto_type k = _mv_1215.data.k_fresh;
            return ((howl_types_KName){ .tag = howl_types_KName_k_fresh, .data.k_fresh = k });
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_KTerm howl_kscnormal_copy_kterm(slop_arena* arena, howl_types_KTerm t) {
    __auto_type _mv_1216 = t;
    switch (_mv_1216.tag) {
        case howl_types_KTerm_k_name:
        {
            __auto_type n = _mv_1216.data.k_name;
            return ((howl_types_KTerm){ .tag = howl_types_KTerm_k_name, .data.k_name = howl_kscnormal_copy_kname(arena, n) });
        }
        case howl_types_KTerm_k_nominal:
        {
            __auto_type a = _mv_1216.data.k_nominal;
            return ((howl_types_KTerm){ .tag = howl_types_KTerm_k_nominal, .data.k_nominal = howl_types_copy_iri(arena, a) });
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_KscAxiom howl_kscnormal_copy_ksc_axiom(slop_arena* arena, howl_types_KscAxiom ax) {
    __auto_type _mv_1217 = ax;
    switch (_mv_1217.tag) {
        case howl_types_KscAxiom_k_sub:
        {
            __auto_type a = _mv_1217.data.k_sub.f0;
            __auto_type b = _mv_1217.data.k_sub.f1;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_sub, .data.k_sub = { .f0 = howl_kscnormal_copy_kterm(arena, a), .f1 = howl_kscnormal_copy_kterm(arena, b) } });
        }
        case howl_types_KscAxiom_k_and:
        {
            __auto_type a = _mv_1217.data.k_and.f0;
            __auto_type b = _mv_1217.data.k_and.f1;
            __auto_type c = _mv_1217.data.k_and.f2;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_and, .data.k_and = { .f0 = howl_kscnormal_copy_kname(arena, a), .f1 = howl_kscnormal_copy_kname(arena, b), .f2 = howl_kscnormal_copy_kname(arena, c) } });
        }
        case howl_types_KscAxiom_k_some_lhs:
        {
            __auto_type r = _mv_1217.data.k_some_lhs.f0;
            __auto_type a = _mv_1217.data.k_some_lhs.f1;
            __auto_type c = _mv_1217.data.k_some_lhs.f2;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_some_lhs, .data.k_some_lhs = { .f0 = howl_types_copy_role(arena, r), .f1 = howl_kscnormal_copy_kname(arena, a), .f2 = howl_kscnormal_copy_kname(arena, c) } });
        }
        case howl_types_KscAxiom_k_some_rhs:
        {
            __auto_type a = _mv_1217.data.k_some_rhs.f0;
            __auto_type r = _mv_1217.data.k_some_rhs.f1;
            __auto_type b = _mv_1217.data.k_some_rhs.f2;
            __auto_type w = _mv_1217.data.k_some_rhs.f3;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_some_rhs, .data.k_some_rhs = { .f0 = howl_kscnormal_copy_kname(arena, a), .f1 = howl_types_copy_role(arena, r), .f2 = howl_kscnormal_copy_kname(arena, b), .f3 = w } });
        }
        case howl_types_KscAxiom_k_self_lhs:
        {
            __auto_type r = _mv_1217.data.k_self_lhs.f0;
            __auto_type c = _mv_1217.data.k_self_lhs.f1;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_self_lhs, .data.k_self_lhs = { .f0 = howl_types_copy_role(arena, r), .f1 = howl_kscnormal_copy_kname(arena, c) } });
        }
        case howl_types_KscAxiom_k_self_rhs:
        {
            __auto_type a = _mv_1217.data.k_self_rhs.f0;
            __auto_type r = _mv_1217.data.k_self_rhs.f1;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_self_rhs, .data.k_self_rhs = { .f0 = howl_kscnormal_copy_kname(arena, a), .f1 = howl_types_copy_role(arena, r) } });
        }
        case howl_types_KscAxiom_k_role:
        {
            __auto_type r = _mv_1217.data.k_role.f0;
            __auto_type t = _mv_1217.data.k_role.f1;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_role, .data.k_role = { .f0 = howl_types_copy_role(arena, r), .f1 = howl_types_copy_role(arena, t) } });
        }
        case howl_types_KscAxiom_k_chain:
        {
            __auto_type r = _mv_1217.data.k_chain.f0;
            __auto_type s = _mv_1217.data.k_chain.f1;
            __auto_type t = _mv_1217.data.k_chain.f2;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_chain, .data.k_chain = { .f0 = howl_types_copy_role(arena, r), .f1 = howl_types_copy_role(arena, s), .f2 = howl_types_copy_role(arena, t) } });
        }
        case howl_types_KscAxiom_k_range:
        {
            __auto_type r = _mv_1217.data.k_range.f0;
            __auto_type d = _mv_1217.data.k_range.f1;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_range, .data.k_range = { .f0 = howl_types_copy_role(arena, r), .f1 = howl_kscnormal_copy_kname(arena, d) } });
        }
        case howl_types_KscAxiom_k_role_assert:
        {
            __auto_type a = _mv_1217.data.k_role_assert.f0;
            __auto_type r = _mv_1217.data.k_role_assert.f1;
            __auto_type b = _mv_1217.data.k_role_assert.f2;
            return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_role_assert, .data.k_role_assert = { .f0 = howl_types_copy_iri(arena, a), .f1 = howl_types_copy_role(arena, r), .f2 = howl_types_copy_iri(arena, b) } });
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_KscAxiom howl_kscnormal_copy_ksc_axioms(slop_arena* arena, slop_list_howl_types_KscAxiom axs) {
    {
        __auto_type out = ((slop_list_howl_types_KscAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_kscnormal_copy_ksc_axiom(arena, ax)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

