#include "../runtime/slop_runtime.h"
#include "slop_sriqnormal.h"

howl_sroiq_SConcept* howl_sriqnormal_sc(slop_arena* arena, howl_sroiq_SConcept c);
slop_result_list_howl_sroiq_SConcept_string howl_sriqnormal_s0_concepts(slop_arena* arena, slop_list_howl_owl2_RawConcept cs);
slop_result_howl_sroiq_SConcept_string howl_sriqnormal_s0_filler(slop_arena* arena, howl_owl2_RawConcept* f);
howl_sroiq_SConcept howl_sriqnormal_s0_count(slop_arena* arena, howl_owl2_CardKind k, howl_types_RoleId r, int64_t n, howl_sroiq_SConcept f);
slop_result_howl_sroiq_SConcept_string howl_sriqnormal_s0_concept(slop_arena* arena, howl_owl2_RawConcept c);
howl_sroiq_SAxiom howl_sriqnormal_gci(slop_arena* arena, howl_sroiq_SConcept l, howl_sroiq_SConcept r);
howl_sroiq_SAxiom howl_sriqnormal_ria(slop_arena* arena, slop_list_howl_types_RoleId w, howl_types_RoleId s);
howl_sroiq_SAxiom howl_sriqnormal_ria1(slop_arena* arena, howl_types_RoleId r, howl_types_RoleId s);
slop_option_howl_sroiq_SConcept howl_sriqnormal_nominal(howl_types_Node n);
slop_option_slop_rdf_rdf_IRI howl_sriqnormal_least_individual(slop_list_howl_types_Node ns);
howl_sroiq_SConcept howl_sriqnormal_top_sc(void);
slop_list_howl_sroiq_SAxiom howl_sriqnormal_one_axiom(slop_arena* arena, howl_sroiq_SAxiom a);
slop_list_howl_sroiq_SAxiom howl_sriqnormal_two_axioms(slop_arena* arena, howl_sroiq_SAxiom a, howl_sroiq_SAxiom b);
howl_sroiq_SAxiom howl_sriqnormal_meet_empty(slop_arena* arena, howl_sroiq_SConcept a, howl_sroiq_SConcept b);
slop_list_howl_sroiq_SAxiom howl_sriqnormal_pairwise_disjoint(slop_arena* arena, slop_list_howl_sroiq_SConcept xs);
slop_list_howl_sroiq_SAxiom howl_sriqnormal_pairwise_dis(slop_arena* arena, slop_list_howl_types_RoleId rs);
slop_list_howl_sroiq_SAxiom howl_sriqnormal_mutual_gcis(slop_arena* arena, slop_list_howl_sroiq_SConcept xs);
slop_list_howl_sroiq_SAxiom howl_sriqnormal_mutual_rias(slop_arena* arena, slop_list_howl_types_RoleId rs);
slop_list_howl_sroiq_SAxiom howl_sriqnormal_around_hub(slop_arena* arena, howl_sroiq_SConcept hub, slop_list_howl_sroiq_SConcept xs);
slop_result_list_howl_sroiq_SConcept_string howl_sriqnormal_s0_nominals(slop_arena* arena, slop_list_howl_types_Node ns, slop_string what);
howl_sroiq_SAxiom howl_sriqnormal_transitivity(slop_arena* arena, howl_types_RoleId r);
howl_sroiq_SAxiom howl_sriqnormal_characteristic(slop_arena* arena, howl_owl2_PropCharacteristic c, howl_types_RoleId r);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_sub_class(slop_arena* arena, howl_owl2_RawConcept* l, howl_owl2_RawConcept* r);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_equivalent_classes(slop_arena* arena, slop_list_howl_owl2_RawConcept cs);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_disjoint_classes(slop_arena* arena, slop_list_howl_owl2_RawConcept cs);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_domain(slop_arena* arena, howl_types_RoleId r, howl_owl2_RawConcept* c);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_range(slop_arena* arena, howl_types_RoleId r, howl_owl2_RawConcept* c);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_class_assertion(slop_arena* arena, howl_owl2_RawClassAssertion ca);
howl_sroiq_SConcept howl_sriqnormal_edge_filler(slop_arena* arena, howl_types_RoleId r, howl_sroiq_SConcept b, uint8_t negative);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_assertion(slop_arena* arena, howl_owl2_RawEdge e, slop_string what, uint8_t negative);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_same_individual(slop_arena* arena, slop_list_howl_types_Node ns);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_different_individuals(slop_arena* arena, slop_list_howl_types_Node ns);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_disjoint_union(slop_arena* arena, howl_owl2_RawDisjointUnion du);
howl_sroiq_SConcept howl_sriqnormal_named_class(slop_rdf_rdf_IRI i);
slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_axiom(slop_arena* arena, howl_owl2_RawAxiom ax);
int64_t howl_sriqnormal_rep_at(howl_sriqrbox_SriqRbox rb, int64_t n);
howl_types_RoleId howl_sriqnormal_collapse_role(howl_sriqrbox_SriqRbox rb, howl_types_RoleId r);
slop_list_howl_types_RoleId howl_sriqnormal_collapse_word(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_types_RoleId w);
slop_list_howl_sroiq_SConcept howl_sriqnormal_collapse_concepts(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SConcept cs);
howl_sroiq_SConcept howl_sriqnormal_collapse_concept(slop_arena* arena, howl_sriqrbox_SriqRbox rb, howl_sroiq_SConcept c);
uint8_t howl_sriqnormal_trivial_ria(slop_list_howl_types_RoleId w, howl_types_RoleId s);
uint8_t howl_sriqnormal_role_eq_p(howl_types_RoleId a, howl_types_RoleId b);
slop_option_howl_sroiq_SAxiom howl_sriqnormal_collapse_axiom(slop_arena* arena, howl_sriqrbox_SriqRbox rb, howl_sroiq_SAxiom a);
howl_types_RoleId howl_sriqnormal_bottom_role(void);
uint8_t howl_sriqnormal_is_bottom(howl_types_RoleId r);
uint8_t howl_sriqnormal_concept_bottom_p(howl_sroiq_SConcept c);
uint8_t howl_sriqnormal_concepts_bottom_p(slop_list_howl_sroiq_SConcept cs);
uint8_t howl_sriqnormal_axiom_bottom_p(howl_sroiq_SAxiom a);
slop_result_howl_sriqnormal_S0_string howl_sriqnormal_sriq_s0(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted);
howl_sriqnormal_S2State* howl_sriqnormal_new_s2(slop_arena* arena);
uint8_t howl_sriqnormal_emit(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DlClause c);
int64_t howl_sriqnormal_fresh_name(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept c);
howl_sroiq_SConcept howl_sriqnormal_concept_of(howl_sriqnormal_S2State* p, int64_t k);
howl_types_DRole howl_sriqnormal_role_name(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_RoleId r);
slop_string howl_sriqnormal_dname_key(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DName n);
slop_string howl_sriqnormal_filler_key(slop_arena* arena, howl_sriqnormal_S2State* p, slop_option_howl_types_DName b);
slop_string howl_sriqnormal_drole_key(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DRole r);
slop_string howl_sriqnormal_key_of(slop_arena* arena, slop_string tag, slop_list_string parts);
slop_string howl_sriqnormal_srole_key(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DRole s, slop_option_howl_types_DName b);
howl_types_DRole howl_sriqnormal_srole_of(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DRole s, slop_option_howl_types_DName b);
int64_t howl_sriqnormal_fn_id(slop_arena* arena, howl_sriqnormal_S2State* p, slop_string key);
slop_list_int howl_sriqnormal_fn_ids(slop_arena* arena, howl_sriqnormal_S2State* p, slop_string axkey, int64_t n);
slop_list_howl_sroiq_SConcept howl_sriqnormal_nnf_list(slop_arena* arena, slop_list_howl_sroiq_SConcept xs, uint8_t pos);
howl_sroiq_SConcept howl_sriqnormal_nnf(slop_arena* arena, howl_sroiq_SConcept c, uint8_t pos);
slop_option_howl_types_DName howl_sriqnormal_pos_name(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept c);
slop_option_howl_types_DName howl_sriqnormal_neg_name(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept c);
slop_option_howl_types_DName howl_sriqnormal_neg_literal_name(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept lit);
slop_list_howl_sroiq_SConcept howl_sriqnormal_singleton_sc(slop_arena* arena, howl_sroiq_SConcept c);
uint8_t howl_sriqnormal_disjunction(slop_arena* arena, howl_sriqnormal_S2State* p, slop_option_howl_types_DName lhs, slop_option_howl_types_DName extra, howl_sroiq_SConcept e);
uint8_t howl_sriqnormal_define_pos(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DName x, howl_sroiq_SConcept e);
uint8_t howl_sriqnormal_define_dl2(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DName x, howl_types_RoleId r, int64_t n, howl_sroiq_SConcept f);
uint8_t howl_sriqnormal_s2_gci(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept l, howl_sroiq_SConcept r);
uint8_t howl_sriqnormal_gci_nnf(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept l, howl_sroiq_SConcept r);
uint8_t howl_sriqnormal_assert_top(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept e, uint8_t ranges);
uint8_t howl_sriqnormal_sc_is_top(howl_sroiq_SConcept c);
uint8_t howl_sriqnormal_sc_is_bottom(howl_sroiq_SConcept c);
howl_types_DName howl_sriqnormal_top_name(slop_arena* arena, howl_sriqnormal_S2State* p);
slop_list_howl_types_DName howl_sriqnormal_one_name(slop_arena* arena, howl_types_DName n);
uint8_t howl_sriqnormal_gci_dl3(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_RoleId r, howl_sroiq_SConcept c, howl_sroiq_SConcept d);
uint8_t howl_sriqnormal_dl3_of(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_RoleId r, slop_option_howl_types_DName b1, howl_sroiq_SConcept d);
slop_option_slop_rdf_rdf_IRI howl_sriqnormal_role_prop(howl_types_RoleId r);
uint8_t howl_sriqnormal_role_inverted(howl_types_RoleId r);
slop_result_u8_string howl_sriqnormal_s2_inclusion(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_RoleId r, howl_types_RoleId s);
slop_result_u8_string howl_sriqnormal_s2_ria(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SRia x);
uint8_t howl_sriqnormal_s2_dis(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_RoleId r, howl_types_RoleId s);
uint8_t howl_sriqnormal_counts_ok(howl_sroiq_SConcept c);
uint8_t howl_sriqnormal_counts_list_ok(slop_list_howl_sroiq_SConcept cs);
slop_result_howl_sriqnormal_S2_string howl_sriqnormal_sriq_s2(slop_arena* arena, slop_list_howl_sroiq_SAxiom axs);
slop_string howl_sriqnormal_render_dname(slop_arena* arena, howl_sriqnormal_S2 s2, howl_types_DName n);
slop_string howl_sriqnormal_render_fresh(slop_arena* arena, howl_sroiq_SConcept c);
slop_string howl_sriqnormal_render_dfiller(slop_arena* arena, howl_sriqnormal_S2 s2, slop_option_howl_types_DName b);
slop_string howl_sriqnormal_render_drole(slop_arena* arena, howl_sriqnormal_S2 s2, howl_types_DRole r);
slop_string howl_sriqnormal_render_dnames(slop_arena* arena, howl_sriqnormal_S2 s2, slop_list_howl_types_DName ns, slop_string sep, slop_string empty);
slop_string howl_sriqnormal_inclusion(slop_arena* arena, slop_string form, slop_string lhs, slop_string rhs);
slop_string howl_sriqnormal_restriction_text(slop_arena* arena, slop_string op, slop_string role, slop_string filler);
slop_string howl_sriqnormal_count_op(slop_arena* arena, slop_string op, int64_t n);
slop_string howl_sriqnormal_braces(slop_arena* arena, slop_rdf_rdf_IRI o);
slop_string howl_sriqnormal_render_dl(slop_arena* arena, howl_sriqnormal_S2 s2, howl_types_DlClause c);

howl_sroiq_SConcept* howl_sriqnormal_sc(slop_arena* arena, howl_sroiq_SConcept c) {
    return howl_sroiq_box_sc(arena, c);
}

slop_result_list_howl_sroiq_SConcept_string howl_sriqnormal_s0_concepts(slop_arena* arena, slop_list_howl_owl2_RawConcept cs) {
    {
        __auto_type out = ((slop_list_howl_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        slop_option_string fault = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                __auto_type _mv_221 = howl_sriqnormal_s0_concept(arena, c);
                if (_mv_221.is_ok) {
                    __auto_type x = _mv_221.data.ok;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_221.is_ok) {
                    __auto_type m = _mv_221.data.err;
                    fault = (slop_option_string){.has_value = 1, .value = m};
                }
            }
        }
        __auto_type _mv_222 = fault;
        if (_mv_222.has_value) {
            __auto_type m = _mv_222.value;
            return ((slop_result_list_howl_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
        } else if (!_mv_222.has_value) {
            return ((slop_result_list_howl_sroiq_SConcept_string){ .is_ok = true, .data.ok = out });
        }
        SLOP_UNREACHABLE();
    }
}

slop_result_howl_sroiq_SConcept_string howl_sriqnormal_s0_filler(slop_arena* arena, howl_owl2_RawConcept* f) {
    return howl_sriqnormal_s0_concept(arena, (*f));
}

howl_sroiq_SConcept howl_sriqnormal_s0_count(slop_arena* arena, howl_owl2_CardKind k, howl_types_RoleId r, int64_t n, howl_sroiq_SConcept f) {
    __auto_type _mv_223 = k;
    if (_mv_223 == howl_owl2_CardKind_card_min) {
        return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_atleast, .data.sc_atleast = { .f0 = n, .f1 = r, .f2 = howl_sriqnormal_sc(arena, f) } });
    } else if (_mv_223 == howl_owl2_CardKind_card_max) {
        return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = n, .f1 = r, .f2 = howl_sriqnormal_sc(arena, f) } });
    } else if (_mv_223 == howl_owl2_CardKind_card_exact) {
        {
            __auto_type both = ((slop_list_howl_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            ({ __auto_type _lst_p = &(both); __auto_type _item = (((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_atleast, .data.sc_atleast = { .f0 = n, .f1 = r, .f2 = howl_sriqnormal_sc(arena, f) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(both); __auto_type _item = (((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = n, .f1 = r, .f2 = howl_sriqnormal_sc(arena, f) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_and, .data.sc_and = both });
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_sroiq_SConcept_string howl_sriqnormal_s0_concept(slop_arena* arena, howl_owl2_RawConcept c) {
    __auto_type _mv_224 = c;
    switch (_mv_224.tag) {
        case howl_owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_224.data.rc_name;
            __auto_type _mv_225 = n;
            switch (_mv_225.tag) {
                case howl_types_Node_class_node:
                {
                    __auto_type i = _mv_225.data.class_node;
                    return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_name, .data.sc_name = i }) });
                }
                case howl_types_Node_individual_node:
                {
                    __auto_type _ = _mv_225.data.individual_node;
                    return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = false, .data.err = SLOP_STR("an individual in a class position") });
                }
                case howl_types_Node_fresh_node:
                {
                    __auto_type _ = _mv_225.data.fresh_node;
                    return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = false, .data.err = SLOP_STR("a fresh node in a class position") });
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_owl2_RawConcept_rc_thing:
        {
            return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_top }) });
        }
        case howl_owl2_RawConcept_rc_nothing:
        {
            return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_bottom }) });
        }
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_224.data.rc_and;
            __auto_type _mv_226 = howl_sriqnormal_s0_concepts(arena, cs);
            if (_mv_226.is_ok) {
                __auto_type xs = _mv_226.data.ok;
                return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_and, .data.sc_and = xs }) });
            } else if (!_mv_226.is_ok) {
                __auto_type m = _mv_226.data.err;
                return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case howl_owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_224.data.rc_or;
            __auto_type _mv_227 = howl_sriqnormal_s0_concepts(arena, cs);
            if (_mv_227.is_ok) {
                __auto_type xs = _mv_227.data.ok;
                return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_or, .data.sc_or = xs }) });
            } else if (!_mv_227.is_ok) {
                __auto_type m = _mv_227.data.err;
                return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case howl_owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_224.data.rc_not;
            __auto_type _mv_228 = howl_sriqnormal_s0_filler(arena, f);
            if (_mv_228.is_ok) {
                __auto_type x = _mv_228.data.ok;
                return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_not, .data.sc_not = howl_sriqnormal_sc(arena, x) }) });
            } else if (!_mv_228.is_ok) {
                __auto_type m = _mv_228.data.err;
                return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case howl_owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_224.data.rc_some.f0;
            __auto_type f = _mv_224.data.rc_some.f1;
            __auto_type _mv_229 = howl_sriqnormal_s0_filler(arena, f);
            if (_mv_229.is_ok) {
                __auto_type x = _mv_229.data.ok;
                return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = howl_sriqnormal_sc(arena, x) } }) });
            } else if (!_mv_229.is_ok) {
                __auto_type m = _mv_229.data.err;
                return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case howl_owl2_RawConcept_rc_all:
        {
            __auto_type r = _mv_224.data.rc_all.f0;
            __auto_type f = _mv_224.data.rc_all.f1;
            __auto_type _mv_230 = howl_sriqnormal_s0_filler(arena, f);
            if (_mv_230.is_ok) {
                __auto_type x = _mv_230.data.ok;
                return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = howl_sriqnormal_sc(arena, x) } }) });
            } else if (!_mv_230.is_ok) {
                __auto_type m = _mv_230.data.err;
                return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case howl_owl2_RawConcept_rc_card:
        {
            __auto_type k = _mv_224.data.rc_card.f0;
            __auto_type r = _mv_224.data.rc_card.f1;
            __auto_type n = _mv_224.data.rc_card.f2;
            return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = true, .data.ok = howl_sriqnormal_s0_count(arena, k, r, n, ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_top })) });
        }
        case howl_owl2_RawConcept_rc_qcard:
        {
            __auto_type k = _mv_224.data.rc_qcard.f0;
            __auto_type r = _mv_224.data.rc_qcard.f1;
            __auto_type n = _mv_224.data.rc_qcard.f2;
            __auto_type f = _mv_224.data.rc_qcard.f3;
            __auto_type _mv_231 = howl_sriqnormal_s0_filler(arena, f);
            if (_mv_231.is_ok) {
                __auto_type x = _mv_231.data.ok;
                return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = true, .data.ok = howl_sriqnormal_s0_count(arena, k, r, n, x) });
            } else if (!_mv_231.is_ok) {
                __auto_type m = _mv_231.data.err;
                return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case howl_owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_224.data.rc_has_self;
            return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_self, .data.sc_self = r }) });
        }
        case howl_owl2_RawConcept_rc_oneof:
        {
            __auto_type _ = _mv_224.data.rc_oneof;
            return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = false, .data.err = SLOP_STR("ObjectOneOf, which the sriq gate does not admit") });
        }
        case howl_owl2_RawConcept_rc_has_value:
        {
            return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = false, .data.err = SLOP_STR("ObjectHasValue, which the sriq gate does not admit") });
        }
        case howl_owl2_RawConcept_rc_data:
        {
            __auto_type _ = _mv_224.data.rc_data;
            return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = false, .data.err = SLOP_STR("a data range, which the sriq gate does not admit") });
        }
        case howl_owl2_RawConcept_rc_anon:
        {
            __auto_type _ = _mv_224.data.rc_anon;
            return ((slop_result_howl_sroiq_SConcept_string){ .is_ok = false, .data.err = SLOP_STR("an undecodable class, which the sriq gate does not admit") });
        }
    }
    SLOP_UNREACHABLE();
}

howl_sroiq_SAxiom howl_sriqnormal_gci(slop_arena* arena, howl_sroiq_SConcept l, howl_sroiq_SConcept r) {
    return ((howl_sroiq_SAxiom){ .tag = howl_sroiq_SAxiom_sa_gci, .data.sa_gci = { .f0 = howl_sriqnormal_sc(arena, l), .f1 = howl_sriqnormal_sc(arena, r) } });
}

howl_sroiq_SAxiom howl_sriqnormal_ria(slop_arena* arena, slop_list_howl_types_RoleId w, howl_types_RoleId s) {
    return ((howl_sroiq_SAxiom){ .tag = howl_sroiq_SAxiom_sa_ria, .data.sa_ria = ((howl_sroiq_SRia){.word = w, .super = s}) });
}

howl_sroiq_SAxiom howl_sriqnormal_ria1(slop_arena* arena, howl_types_RoleId r, howl_types_RoleId s) {
    {
        __auto_type w = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(w); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return howl_sriqnormal_ria(arena, w, s);
    }
}

slop_option_howl_sroiq_SConcept howl_sriqnormal_nominal(howl_types_Node n) {
    __auto_type _mv_232 = n;
    switch (_mv_232.tag) {
        case howl_types_Node_individual_node:
        {
            __auto_type i = _mv_232.data.individual_node;
            return (slop_option_howl_sroiq_SConcept){.has_value = 1, .value = ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_nominal, .data.sc_nominal = i })};
        }
        case howl_types_Node_class_node:
        {
            __auto_type _ = _mv_232.data.class_node;
            return (slop_option_howl_sroiq_SConcept){.has_value = false};
        }
        case howl_types_Node_fresh_node:
        {
            __auto_type _ = _mv_232.data.fresh_node;
            return (slop_option_howl_sroiq_SConcept){.has_value = false};
        }
    }
    SLOP_UNREACHABLE();
}

slop_option_slop_rdf_rdf_IRI howl_sriqnormal_least_individual(slop_list_howl_types_Node ns) {
    {
        slop_option_slop_rdf_rdf_IRI best = (slop_option_slop_rdf_rdf_IRI){.has_value = false};
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                __auto_type _mv_233 = n;
                switch (_mv_233.tag) {
                    case howl_types_Node_individual_node:
                    {
                        __auto_type i = _mv_233.data.individual_node;
                        __auto_type _mv_234 = best;
                        if (!_mv_234.has_value) {
                            best = (slop_option_slop_rdf_rdf_IRI){.has_value = 1, .value = i};
                        } else if (_mv_234.has_value) {
                            __auto_type b = _mv_234.value;
                            if (howl_canon_iri_cmp(i, b) < 0) {
                                best = (slop_option_slop_rdf_rdf_IRI){.has_value = 1, .value = i};
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
        return best;
    }
}

howl_sroiq_SConcept howl_sriqnormal_top_sc(void) {
    return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_top });
}

slop_list_howl_sroiq_SAxiom howl_sriqnormal_one_axiom(slop_arena* arena, howl_sroiq_SAxiom a) {
    {
        __auto_type xs = ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(xs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return xs;
    }
}

slop_list_howl_sroiq_SAxiom howl_sriqnormal_two_axioms(slop_arena* arena, howl_sroiq_SAxiom a, howl_sroiq_SAxiom b) {
    {
        __auto_type xs = ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(xs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(xs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return xs;
    }
}

howl_sroiq_SAxiom howl_sriqnormal_meet_empty(slop_arena* arena, howl_sroiq_SConcept a, howl_sroiq_SConcept b) {
    {
        __auto_type ab = ((slop_list_howl_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(ab); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(ab); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return howl_sriqnormal_gci(arena, ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_and, .data.sc_and = ab }), ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_bottom }));
    }
}

slop_list_howl_sroiq_SAxiom howl_sriqnormal_pairwise_disjoint(slop_arena* arena, slop_list_howl_sroiq_SConcept xs) {
    {
        __auto_type out = ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    int64_t j = 0;
                    {
                        __auto_type _coll = xs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type b = _coll.data[_i];
                            if (i < j) {
                                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnormal_meet_empty(arena, a, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                            j = (j + 1);
                        }
                    }
                    i = (i + 1);
                }
            }
        }
        return out;
    }
}

slop_list_howl_sroiq_SAxiom howl_sriqnormal_pairwise_dis(slop_arena* arena, slop_list_howl_types_RoleId rs) {
    {
        __auto_type out = ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    int64_t j = 0;
                    {
                        __auto_type _coll = rs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type b = _coll.data[_i];
                            if (i < j) {
                                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sroiq_SAxiom){ .tag = howl_sroiq_SAxiom_sa_dis, .data.sa_dis = { .f0 = a, .f1 = b } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                            j = (j + 1);
                        }
                    }
                    i = (i + 1);
                }
            }
        }
        return out;
    }
}

slop_list_howl_sroiq_SAxiom howl_sriqnormal_mutual_gcis(slop_arena* arena, slop_list_howl_sroiq_SConcept xs) {
    {
        __auto_type out = ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    __auto_type _coll = xs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type b = _coll.data[_i];
                        if (howl_sroiq_sc_cmp(a, b) != 0) {
                            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnormal_gci(arena, a, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_sroiq_SAxiom howl_sriqnormal_mutual_rias(slop_arena* arena, slop_list_howl_types_RoleId rs) {
    {
        __auto_type out = ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    __auto_type _coll = rs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type b = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnormal_ria1(arena, a, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_sroiq_SAxiom howl_sriqnormal_around_hub(slop_arena* arena, howl_sroiq_SConcept hub, slop_list_howl_sroiq_SConcept xs) {
    {
        __auto_type out = ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (howl_sroiq_sc_cmp(x, hub) != 0) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnormal_gci(arena, hub, x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnormal_gci(arena, x, hub)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

slop_result_list_howl_sroiq_SConcept_string howl_sriqnormal_s0_nominals(slop_arena* arena, slop_list_howl_types_Node ns, slop_string what) {
    {
        __auto_type out = ((slop_list_howl_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        slop_option_string fault = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                __auto_type _mv_235 = howl_sriqnormal_nominal(n);
                if (_mv_235.has_value) {
                    __auto_type x = _mv_235.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_235.has_value) {
                    fault = (slop_option_string){.has_value = 1, .value = string_concat(arena, what, SLOP_STR(" with a non-individual"))};
                }
            }
        }
        __auto_type _mv_236 = fault;
        if (_mv_236.has_value) {
            __auto_type m = _mv_236.value;
            return ((slop_result_list_howl_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
        } else if (!_mv_236.has_value) {
            return ((slop_result_list_howl_sroiq_SConcept_string){ .is_ok = true, .data.ok = out });
        }
        SLOP_UNREACHABLE();
    }
}

howl_sroiq_SAxiom howl_sriqnormal_transitivity(slop_arena* arena, howl_types_RoleId r) {
    {
        __auto_type w = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(w); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(w); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return howl_sriqnormal_ria(arena, w, r);
    }
}

howl_sroiq_SAxiom howl_sriqnormal_characteristic(slop_arena* arena, howl_owl2_PropCharacteristic c, howl_types_RoleId r) {
    __auto_type _mv_237 = c;
    if (_mv_237 == howl_owl2_PropCharacteristic_prop_functional) {
        return howl_sriqnormal_gci(arena, howl_sriqnormal_top_sc(), ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = 1, .f1 = r, .f2 = howl_sriqnormal_sc(arena, howl_sriqnormal_top_sc()) } }));
    } else if (_mv_237 == howl_owl2_PropCharacteristic_prop_inverse_functional) {
        return howl_sriqnormal_gci(arena, howl_sriqnormal_top_sc(), ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = 1, .f1 = howl_sroiq_inv_role(r), .f2 = howl_sriqnormal_sc(arena, howl_sriqnormal_top_sc()) } }));
    } else if (_mv_237 == howl_owl2_PropCharacteristic_prop_symmetric) {
        return howl_sriqnormal_ria1(arena, howl_sroiq_inv_role(r), r);
    } else if (_mv_237 == howl_owl2_PropCharacteristic_prop_asymmetric) {
        return ((howl_sroiq_SAxiom){ .tag = howl_sroiq_SAxiom_sa_dis, .data.sa_dis = { .f0 = r, .f1 = howl_sroiq_inv_role(r) } });
    } else if (_mv_237 == howl_owl2_PropCharacteristic_prop_reflexive) {
        return ((howl_sroiq_SAxiom){ .tag = howl_sroiq_SAxiom_sa_ref, .data.sa_ref = r });
    } else if (_mv_237 == howl_owl2_PropCharacteristic_prop_irreflexive) {
        return ((howl_sroiq_SAxiom){ .tag = howl_sroiq_SAxiom_sa_irr, .data.sa_irr = r });
    }
    SLOP_UNREACHABLE();
}

slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_sub_class(slop_arena* arena, howl_owl2_RawConcept* l, howl_owl2_RawConcept* r) {
    __auto_type _mv_238 = howl_sriqnormal_s0_filler(arena, l);
    if (!_mv_238.is_ok) {
        __auto_type m = _mv_238.data.err;
        return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_238.is_ok) {
        __auto_type lx = _mv_238.data.ok;
        __auto_type _mv_239 = howl_sriqnormal_s0_filler(arena, r);
        if (!_mv_239.is_ok) {
            __auto_type m = _mv_239.data.err;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
        } else if (_mv_239.is_ok) {
            __auto_type rx = _mv_239.data.ok;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = howl_sriqnormal_one_axiom(arena, howl_sriqnormal_gci(arena, lx, rx)) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_equivalent_classes(slop_arena* arena, slop_list_howl_owl2_RawConcept cs) {
    __auto_type _mv_240 = howl_sriqnormal_s0_concepts(arena, cs);
    if (!_mv_240.is_ok) {
        __auto_type m = _mv_240.data.err;
        return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_240.is_ok) {
        __auto_type xs = _mv_240.data.ok;
        return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = howl_sriqnormal_mutual_gcis(arena, xs) });
    }
    SLOP_UNREACHABLE();
}

slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_disjoint_classes(slop_arena* arena, slop_list_howl_owl2_RawConcept cs) {
    __auto_type _mv_241 = howl_sriqnormal_s0_concepts(arena, cs);
    if (!_mv_241.is_ok) {
        __auto_type m = _mv_241.data.err;
        return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_241.is_ok) {
        __auto_type xs = _mv_241.data.ok;
        return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = howl_sriqnormal_pairwise_disjoint(arena, xs) });
    }
    SLOP_UNREACHABLE();
}

slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_domain(slop_arena* arena, howl_types_RoleId r, howl_owl2_RawConcept* c) {
    __auto_type _mv_242 = howl_sriqnormal_s0_filler(arena, c);
    if (!_mv_242.is_ok) {
        __auto_type m = _mv_242.data.err;
        return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_242.is_ok) {
        __auto_type cx = _mv_242.data.ok;
        return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = howl_sriqnormal_one_axiom(arena, howl_sriqnormal_gci(arena, ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = howl_sriqnormal_sc(arena, howl_sriqnormal_top_sc()) } }), cx)) });
    }
    SLOP_UNREACHABLE();
}

slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_range(slop_arena* arena, howl_types_RoleId r, howl_owl2_RawConcept* c) {
    __auto_type _mv_243 = howl_sriqnormal_s0_filler(arena, c);
    if (!_mv_243.is_ok) {
        __auto_type m = _mv_243.data.err;
        return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_243.is_ok) {
        __auto_type cx = _mv_243.data.ok;
        return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = howl_sriqnormal_one_axiom(arena, howl_sriqnormal_gci(arena, howl_sriqnormal_top_sc(), ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = howl_sriqnormal_sc(arena, cx) } }))) });
    }
    SLOP_UNREACHABLE();
}

slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_class_assertion(slop_arena* arena, howl_owl2_RawClassAssertion ca) {
    __auto_type _mv_244 = howl_sriqnormal_nominal(ca.subject);
    if (!_mv_244.has_value) {
        return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("a class assertion on a non-individual") });
    } else if (_mv_244.has_value) {
        __auto_type a = _mv_244.value;
        __auto_type _mv_245 = howl_sriqnormal_s0_filler(arena, ca.concept);
        if (!_mv_245.is_ok) {
            __auto_type m = _mv_245.data.err;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
        } else if (_mv_245.is_ok) {
            __auto_type cx = _mv_245.data.ok;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = howl_sriqnormal_one_axiom(arena, howl_sriqnormal_gci(arena, a, cx)) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

howl_sroiq_SConcept howl_sriqnormal_edge_filler(slop_arena* arena, howl_types_RoleId r, howl_sroiq_SConcept b, uint8_t negative) {
    if (negative) {
        return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = howl_sriqnormal_sc(arena, ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_not, .data.sc_not = howl_sriqnormal_sc(arena, b) })) } });
    } else {
        return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = howl_sriqnormal_sc(arena, b) } });
    }
}

slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_assertion(slop_arena* arena, howl_owl2_RawEdge e, slop_string what, uint8_t negative) {
    __auto_type _mv_246 = howl_sriqnormal_nominal(e.from);
    if (!_mv_246.has_value) {
        return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = string_concat(arena, what, SLOP_STR(" from a non-individual")) });
    } else if (_mv_246.has_value) {
        __auto_type a = _mv_246.value;
        __auto_type _mv_247 = howl_sriqnormal_nominal(e.to);
        if (!_mv_247.has_value) {
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = string_concat(arena, what, SLOP_STR(" to a non-individual")) });
        } else if (_mv_247.has_value) {
            __auto_type b = _mv_247.value;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = howl_sriqnormal_one_axiom(arena, howl_sriqnormal_gci(arena, a, howl_sriqnormal_edge_filler(arena, e.role, b, negative))) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_same_individual(slop_arena* arena, slop_list_howl_types_Node ns) {
    __auto_type _mv_248 = howl_sriqnormal_least_individual(ns);
    if (!_mv_248.has_value) {
        return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("SameIndividual without an individual") });
    } else if (_mv_248.has_value) {
        __auto_type h = _mv_248.value;
        __auto_type _mv_249 = howl_sriqnormal_s0_nominals(arena, ns, SLOP_STR("SameIndividual"));
        if (!_mv_249.is_ok) {
            __auto_type m = _mv_249.data.err;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
        } else if (_mv_249.is_ok) {
            __auto_type xs = _mv_249.data.ok;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = howl_sriqnormal_around_hub(arena, ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_nominal, .data.sc_nominal = h }), xs) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_different_individuals(slop_arena* arena, slop_list_howl_types_Node ns) {
    __auto_type _mv_250 = howl_sriqnormal_s0_nominals(arena, ns, SLOP_STR("DifferentIndividuals"));
    if (!_mv_250.is_ok) {
        __auto_type m = _mv_250.data.err;
        return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_250.is_ok) {
        __auto_type xs = _mv_250.data.ok;
        return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = howl_sriqnormal_pairwise_disjoint(arena, xs) });
    }
    SLOP_UNREACHABLE();
}

slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_disjoint_union(slop_arena* arena, howl_owl2_RawDisjointUnion du) {
    __auto_type _mv_251 = howl_sriqnormal_s0_concepts(arena, du.members);
    if (!_mv_251.is_ok) {
        __auto_type m = _mv_251.data.err;
        return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_251.is_ok) {
        __auto_type xs = _mv_251.data.ok;
        {
            __auto_type c = howl_sriqnormal_named_class(du.class);
            __auto_type uni = ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_or, .data.sc_or = xs });
            __auto_type out = ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnormal_gci(arena, c, uni)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnormal_gci(arena, uni, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            {
                __auto_type _coll = howl_sriqnormal_pairwise_disjoint(arena, xs);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = out });
        }
    }
    SLOP_UNREACHABLE();
}

howl_sroiq_SConcept howl_sriqnormal_named_class(slop_rdf_rdf_IRI i) {
    if (string_eq(i.value, slop_rdf_vocab_OWL_THING)) {
        return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_top });
    } else if (string_eq(i.value, slop_rdf_vocab_OWL_NOTHING)) {
        return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_bottom });
    } else {
        return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_name, .data.sc_name = i });
    }
}

slop_result_list_howl_sroiq_SAxiom_string howl_sriqnormal_s0_axiom(slop_arena* arena, howl_owl2_RawAxiom ax) {
    __auto_type _mv_252 = ax;
    switch (_mv_252.tag) {
        case howl_owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_252.data.ra_sub_class_of.f0;
            __auto_type r = _mv_252.data.ra_sub_class_of.f1;
            return howl_sriqnormal_s0_sub_class(arena, l, r);
        }
        case howl_owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type cs = _mv_252.data.ra_equivalent_classes;
            return howl_sriqnormal_s0_equivalent_classes(arena, cs);
        }
        case howl_owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_252.data.ra_disjoint_classes;
            return howl_sriqnormal_s0_disjoint_classes(arena, cs);
        }
        case howl_owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type a = _mv_252.data.ra_sub_object_property.f0;
            __auto_type b = _mv_252.data.ra_sub_object_property.f1;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = howl_sriqnormal_one_axiom(arena, howl_sriqnormal_ria1(arena, a, b)) });
        }
        case howl_owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_252.data.ra_property_chain;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = howl_sriqnormal_one_axiom(arena, howl_sriqnormal_ria(arena, ch.steps, ch.super)) });
        }
        case howl_owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type rs = _mv_252.data.ra_equivalent_properties;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = howl_sriqnormal_mutual_rias(arena, rs) });
        }
        case howl_owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type r = _mv_252.data.ra_transitive_property;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = howl_sriqnormal_one_axiom(arena, howl_sriqnormal_transitivity(arena, r)) });
        }
        case howl_owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_252.data.ra_object_property_domain.f0;
            __auto_type c = _mv_252.data.ra_object_property_domain.f1;
            return howl_sriqnormal_s0_domain(arena, r, c);
        }
        case howl_owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type r = _mv_252.data.ra_object_property_range.f0;
            __auto_type c = _mv_252.data.ra_object_property_range.f1;
            return howl_sriqnormal_s0_range(arena, r, c);
        }
        case howl_owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_252.data.ra_class_assertion;
            return howl_sriqnormal_s0_class_assertion(arena, ca);
        }
        case howl_owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type e = _mv_252.data.ra_object_property_assertion;
            return howl_sriqnormal_s0_assertion(arena, e, SLOP_STR("a property assertion"), 0);
        }
        case howl_owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type e = _mv_252.data.ra_negative_assertion;
            return howl_sriqnormal_s0_assertion(arena, e, SLOP_STR("a negative assertion"), 1);
        }
        case howl_owl2_RawAxiom_ra_inverse_properties:
        {
            __auto_type a = _mv_252.data.ra_inverse_properties.f0;
            __auto_type b = _mv_252.data.ra_inverse_properties.f1;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = howl_sriqnormal_two_axioms(arena, howl_sriqnormal_ria1(arena, a, howl_sroiq_inv_role(b)), howl_sriqnormal_ria1(arena, howl_sroiq_inv_role(b), a)) });
        }
        case howl_owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type c = _mv_252.data.ra_property_characteristic.f0;
            __auto_type r = _mv_252.data.ra_property_characteristic.f1;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = howl_sriqnormal_one_axiom(arena, howl_sriqnormal_characteristic(arena, c, r)) });
        }
        case howl_owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type rs = _mv_252.data.ra_disjoint_properties;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = true, .data.ok = howl_sriqnormal_pairwise_dis(arena, rs) });
        }
        case howl_owl2_RawAxiom_ra_same_individual:
        {
            __auto_type ns = _mv_252.data.ra_same_individual;
            return howl_sriqnormal_s0_same_individual(arena, ns);
        }
        case howl_owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type ns = _mv_252.data.ra_different_individuals;
            return howl_sriqnormal_s0_different_individuals(arena, ns);
        }
        case howl_owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type du = _mv_252.data.ra_disjoint_union;
            return howl_sriqnormal_s0_disjoint_union(arena, du);
        }
        case howl_owl2_RawAxiom_ra_declaration:
        {
            __auto_type _ = _mv_252.data.ra_declaration;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("a declaration reached the normaliser") });
        }
        case howl_owl2_RawAxiom_ra_annotation:
        {
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("an annotation reached the normaliser") });
        }
        case howl_owl2_RawAxiom_ra_inert_data:
        {
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("an inert data axiom reached the normaliser") });
        }
        case howl_owl2_RawAxiom_ra_has_key:
        {
            __auto_type _ = _mv_252.data.ra_has_key;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("HasKey, which the sriq gate does not admit") });
        }
        case howl_owl2_RawAxiom_ra_data_axiom:
        {
            __auto_type _ = _mv_252.data.ra_data_axiom;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("a data axiom, which the sriq gate does not admit") });
        }
        case howl_owl2_RawAxiom_ra_builtin_role:
        {
            __auto_type _ = _mv_252.data.ra_builtin_role;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("a built-in role axiom, which the sriq gate does not admit") });
        }
        case howl_owl2_RawAxiom_ra_anonymous_individual:
        {
            __auto_type _ = _mv_252.data.ra_anonymous_individual;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("an anonymous individual, which the sriq gate does not admit") });
        }
        case howl_owl2_RawAxiom_ra_reserved_vocabulary:
        {
            __auto_type _ = _mv_252.data.ra_reserved_vocabulary;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("reserved vocabulary, which the sriq gate does not admit") });
        }
        case howl_owl2_RawAxiom_ra_swrl_rule:
        {
            __auto_type _ = _mv_252.data.ra_swrl_rule;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("a SWRL rule, which the sriq gate does not admit") });
        }
        case howl_owl2_RawAxiom_ra_unrecognized:
        {
            __auto_type _ = _mv_252.data.ra_unrecognized;
            return ((slop_result_list_howl_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("an unrecognized axiom, which the sriq gate does not admit") });
        }
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqnormal_rep_at(howl_sriqrbox_SriqRbox rb, int64_t n) {
    __auto_type _mv_253 = ({ __auto_type _lst = rb.rep; size_t _idx = (size_t)n; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_253.has_value) {
        __auto_type v = _mv_253.value;
        return v;
    } else if (!_mv_253.has_value) {
        return n;
    }
    SLOP_UNREACHABLE();
}

howl_types_RoleId howl_sriqnormal_collapse_role(howl_sriqrbox_SriqRbox rb, howl_types_RoleId r) {
    {
        __auto_type n = howl_sriqrbox_sriq_node(rb.props, r);
        if (n < 0) {
            return r;
        } else {
            return howl_sriqrbox_node_role(rb.props, howl_sriqnormal_rep_at(rb, n));
        }
    }
}

slop_list_howl_types_RoleId howl_sriqnormal_collapse_word(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_types_RoleId w) {
    {
        __auto_type out = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = w;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnormal_collapse_role(rb, r)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_sroiq_SConcept howl_sriqnormal_collapse_concepts(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SConcept cs) {
    {
        __auto_type out = ((slop_list_howl_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnormal_collapse_concept(arena, rb, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_sroiq_SConcept howl_sriqnormal_collapse_concept(slop_arena* arena, howl_sriqrbox_SriqRbox rb, howl_sroiq_SConcept c) {
    __auto_type _mv_254 = c;
    switch (_mv_254.tag) {
        case howl_sroiq_SConcept_sc_top:
        {
            return c;
        }
        case howl_sroiq_SConcept_sc_bottom:
        {
            return c;
        }
        case howl_sroiq_SConcept_sc_name:
        {
            __auto_type _ = _mv_254.data.sc_name;
            return c;
        }
        case howl_sroiq_SConcept_sc_nominal:
        {
            __auto_type _ = _mv_254.data.sc_nominal;
            return c;
        }
        case howl_sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_254.data.sc_not;
            return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_not, .data.sc_not = howl_sriqnormal_sc(arena, howl_sriqnormal_collapse_concept(arena, rb, (*f))) });
        }
        case howl_sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_254.data.sc_and;
            return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_and, .data.sc_and = howl_sriqnormal_collapse_concepts(arena, rb, xs) });
        }
        case howl_sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_254.data.sc_or;
            return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_or, .data.sc_or = howl_sriqnormal_collapse_concepts(arena, rb, xs) });
        }
        case howl_sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_254.data.sc_some.f0;
            __auto_type f = _mv_254.data.sc_some.f1;
            return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_some, .data.sc_some = { .f0 = howl_sriqnormal_collapse_role(rb, r), .f1 = howl_sriqnormal_sc(arena, howl_sriqnormal_collapse_concept(arena, rb, (*f))) } });
        }
        case howl_sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_254.data.sc_all.f0;
            __auto_type f = _mv_254.data.sc_all.f1;
            return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_all, .data.sc_all = { .f0 = howl_sriqnormal_collapse_role(rb, r), .f1 = howl_sriqnormal_sc(arena, howl_sriqnormal_collapse_concept(arena, rb, (*f))) } });
        }
        case howl_sroiq_SConcept_sc_atleast:
        {
            __auto_type n = _mv_254.data.sc_atleast.f0;
            __auto_type r = _mv_254.data.sc_atleast.f1;
            __auto_type f = _mv_254.data.sc_atleast.f2;
            return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_atleast, .data.sc_atleast = { .f0 = n, .f1 = howl_sriqnormal_collapse_role(rb, r), .f2 = howl_sriqnormal_sc(arena, howl_sriqnormal_collapse_concept(arena, rb, (*f))) } });
        }
        case howl_sroiq_SConcept_sc_atmost:
        {
            __auto_type n = _mv_254.data.sc_atmost.f0;
            __auto_type r = _mv_254.data.sc_atmost.f1;
            __auto_type f = _mv_254.data.sc_atmost.f2;
            return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = n, .f1 = howl_sriqnormal_collapse_role(rb, r), .f2 = howl_sriqnormal_sc(arena, howl_sriqnormal_collapse_concept(arena, rb, (*f))) } });
        }
        case howl_sroiq_SConcept_sc_self:
        {
            __auto_type r = _mv_254.data.sc_self;
            return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_self, .data.sc_self = howl_sriqnormal_collapse_role(rb, r) });
        }
        case howl_sroiq_SConcept_sc_elim:
        {
            return c;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqnormal_trivial_ria(slop_list_howl_types_RoleId w, howl_types_RoleId s) {
    return ((((int64_t)((w).len)) == 1) && ({ __auto_type _mv = ({ __auto_type _lst = w; size_t _idx = (size_t)0; slop_option_howl_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type r = _mv.value; howl_sriqnormal_role_eq_p(r, s); }) : (0); }));
}

uint8_t howl_sriqnormal_role_eq_p(howl_types_RoleId a, howl_types_RoleId b) {
    __auto_type _mv_255 = a;
    switch (_mv_255.tag) {
        case howl_types_RoleId_named_role:
        {
            __auto_type ia = _mv_255.data.named_role;
            __auto_type _mv_256 = b;
            switch (_mv_256.tag) {
                case howl_types_RoleId_named_role:
                {
                    __auto_type ib = _mv_256.data.named_role;
                    return (howl_canon_string_cmp(ia.value, ib.value) == 0);
                }
                default: {
                    return 0;
                }
            }
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type ia = _mv_255.data.inverse_role;
            __auto_type _mv_257 = b;
            switch (_mv_257.tag) {
                case howl_types_RoleId_inverse_role:
                {
                    __auto_type ib = _mv_257.data.inverse_role;
                    return (howl_canon_string_cmp(ia.value, ib.value) == 0);
                }
                default: {
                    return 0;
                }
            }
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type ka = _mv_255.data.fresh_role;
            __auto_type _mv_258 = b;
            switch (_mv_258.tag) {
                case howl_types_RoleId_fresh_role:
                {
                    __auto_type kb = _mv_258.data.fresh_role;
                    return (ka == kb);
                }
                default: {
                    return 0;
                }
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_option_howl_sroiq_SAxiom howl_sriqnormal_collapse_axiom(slop_arena* arena, howl_sriqrbox_SriqRbox rb, howl_sroiq_SAxiom a) {
    __auto_type _mv_259 = a;
    switch (_mv_259.tag) {
        case howl_sroiq_SAxiom_sa_gci:
        {
            __auto_type l = _mv_259.data.sa_gci.f0;
            __auto_type r = _mv_259.data.sa_gci.f1;
            return (slop_option_howl_sroiq_SAxiom){.has_value = 1, .value = ((howl_sroiq_SAxiom){ .tag = howl_sroiq_SAxiom_sa_gci, .data.sa_gci = { .f0 = howl_sriqnormal_sc(arena, howl_sroiq_sc_canon(arena, howl_sriqnormal_collapse_concept(arena, rb, (*l)))), .f1 = howl_sriqnormal_sc(arena, howl_sroiq_sc_canon(arena, howl_sriqnormal_collapse_concept(arena, rb, (*r)))) } })};
        }
        case howl_sroiq_SAxiom_sa_ria:
        {
            __auto_type x = _mv_259.data.sa_ria;
            {
                __auto_type w = howl_sriqnormal_collapse_word(arena, rb, x.word);
                __auto_type s = howl_sriqnormal_collapse_role(rb, x.super);
                if (howl_sriqnormal_trivial_ria(w, s)) {
                    return (slop_option_howl_sroiq_SAxiom){.has_value = false};
                } else {
                    return (slop_option_howl_sroiq_SAxiom){.has_value = 1, .value = howl_sriqnormal_ria(arena, w, s)};
                }
            }
        }
        case howl_sroiq_SAxiom_sa_ref:
        {
            __auto_type r = _mv_259.data.sa_ref;
            return (slop_option_howl_sroiq_SAxiom){.has_value = 1, .value = ((howl_sroiq_SAxiom){ .tag = howl_sroiq_SAxiom_sa_ref, .data.sa_ref = howl_sriqnormal_collapse_role(rb, r) })};
        }
        case howl_sroiq_SAxiom_sa_irr:
        {
            __auto_type r = _mv_259.data.sa_irr;
            return (slop_option_howl_sroiq_SAxiom){.has_value = 1, .value = ((howl_sroiq_SAxiom){ .tag = howl_sroiq_SAxiom_sa_irr, .data.sa_irr = howl_sriqnormal_collapse_role(rb, r) })};
        }
        case howl_sroiq_SAxiom_sa_dis:
        {
            __auto_type r = _mv_259.data.sa_dis.f0;
            __auto_type s = _mv_259.data.sa_dis.f1;
            return (slop_option_howl_sroiq_SAxiom){.has_value = 1, .value = ((howl_sroiq_SAxiom){ .tag = howl_sroiq_SAxiom_sa_dis, .data.sa_dis = { .f0 = howl_sriqnormal_collapse_role(rb, r), .f1 = howl_sriqnormal_collapse_role(rb, s) } })};
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_RoleId howl_sriqnormal_bottom_role(void) {
    return ((howl_types_RoleId){ .tag = howl_types_RoleId_named_role, .data.named_role = ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_BOTTOM_OBJECT_PROPERTY}) });
}

uint8_t howl_sriqnormal_is_bottom(howl_types_RoleId r) {
    __auto_type _mv_260 = r;
    switch (_mv_260.tag) {
        case howl_types_RoleId_named_role:
        {
            __auto_type i = _mv_260.data.named_role;
            return (howl_canon_string_cmp(i.value, slop_rdf_vocab_OWL_BOTTOM_OBJECT_PROPERTY) == 0);
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type i = _mv_260.data.inverse_role;
            return (howl_canon_string_cmp(i.value, slop_rdf_vocab_OWL_BOTTOM_OBJECT_PROPERTY) == 0);
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_260.data.fresh_role;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqnormal_concept_bottom_p(howl_sroiq_SConcept c) {
    __auto_type _mv_261 = c;
    switch (_mv_261.tag) {
        case howl_sroiq_SConcept_sc_top:
        {
            return 0;
        }
        case howl_sroiq_SConcept_sc_bottom:
        {
            return 0;
        }
        case howl_sroiq_SConcept_sc_name:
        {
            __auto_type _ = _mv_261.data.sc_name;
            return 0;
        }
        case howl_sroiq_SConcept_sc_nominal:
        {
            __auto_type _ = _mv_261.data.sc_nominal;
            return 0;
        }
        case howl_sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_261.data.sc_not;
            return howl_sriqnormal_concept_bottom_p((*f));
        }
        case howl_sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_261.data.sc_and;
            return howl_sriqnormal_concepts_bottom_p(xs);
        }
        case howl_sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_261.data.sc_or;
            return howl_sriqnormal_concepts_bottom_p(xs);
        }
        case howl_sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_261.data.sc_some.f0;
            __auto_type f = _mv_261.data.sc_some.f1;
            return (howl_sriqnormal_is_bottom(r) || howl_sriqnormal_concept_bottom_p((*f)));
        }
        case howl_sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_261.data.sc_all.f0;
            __auto_type f = _mv_261.data.sc_all.f1;
            return (howl_sriqnormal_is_bottom(r) || howl_sriqnormal_concept_bottom_p((*f)));
        }
        case howl_sroiq_SConcept_sc_atleast:
        {
            __auto_type r = _mv_261.data.sc_atleast.f1;
            __auto_type f = _mv_261.data.sc_atleast.f2;
            return (howl_sriqnormal_is_bottom(r) || howl_sriqnormal_concept_bottom_p((*f)));
        }
        case howl_sroiq_SConcept_sc_atmost:
        {
            __auto_type r = _mv_261.data.sc_atmost.f1;
            __auto_type f = _mv_261.data.sc_atmost.f2;
            return (howl_sriqnormal_is_bottom(r) || howl_sriqnormal_concept_bottom_p((*f)));
        }
        case howl_sroiq_SConcept_sc_self:
        {
            __auto_type r = _mv_261.data.sc_self;
            return howl_sriqnormal_is_bottom(r);
        }
        case howl_sroiq_SConcept_sc_elim:
        {
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqnormal_concepts_bottom_p(slop_list_howl_sroiq_SConcept cs) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (howl_sriqnormal_concept_bottom_p(c)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t howl_sriqnormal_axiom_bottom_p(howl_sroiq_SAxiom a) {
    __auto_type _mv_262 = a;
    switch (_mv_262.tag) {
        case howl_sroiq_SAxiom_sa_gci:
        {
            __auto_type l = _mv_262.data.sa_gci.f0;
            __auto_type r = _mv_262.data.sa_gci.f1;
            return (howl_sriqnormal_concept_bottom_p((*l)) || howl_sriqnormal_concept_bottom_p((*r)));
        }
        case howl_sroiq_SAxiom_sa_ria:
        {
            __auto_type x = _mv_262.data.sa_ria;
            {
                uint8_t found = howl_sriqnormal_is_bottom(x.super);
                {
                    __auto_type _coll = x.word;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        if (howl_sriqnormal_is_bottom(r)) {
                            found = 1;
                        }
                    }
                }
                return found;
            }
        }
        case howl_sroiq_SAxiom_sa_ref:
        {
            __auto_type r = _mv_262.data.sa_ref;
            return howl_sriqnormal_is_bottom(r);
        }
        case howl_sroiq_SAxiom_sa_irr:
        {
            __auto_type r = _mv_262.data.sa_irr;
            return howl_sriqnormal_is_bottom(r);
        }
        case howl_sroiq_SAxiom_sa_dis:
        {
            __auto_type r = _mv_262.data.sa_dis.f0;
            __auto_type s = _mv_262.data.sa_dis.f1;
            return (howl_sriqnormal_is_bottom(r) || howl_sriqnormal_is_bottom(s));
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_sriqnormal_S0_string howl_sriqnormal_sriq_s0(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted) {
    {
        __auto_type rb = howl_sriqrbox_sriq_rbox(arena, accepted);
        __auto_type raw = ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type out = ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t bottom = 0;
        slop_option_string fault = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = accepted;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_263 = howl_sriqnormal_s0_axiom(arena, ax);
                if (!_mv_263.is_ok) {
                    __auto_type m = _mv_263.data.err;
                    fault = (slop_option_string){.has_value = 1, .value = m};
                } else if (_mv_263.is_ok) {
                    __auto_type xs = _mv_263.data.ok;
                    {
                        __auto_type _coll = xs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type x = _coll.data[_i];
                            ({ __auto_type _lst_p = &(raw); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        {
            __auto_type _coll = raw;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (howl_sriqnormal_axiom_bottom_p(a)) {
                    bottom = 1;
                }
                __auto_type _mv_264 = howl_sriqnormal_collapse_axiom(arena, rb, a);
                if (_mv_264.has_value) {
                    __auto_type c = _mv_264.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_264.has_value) {
                }
            }
        }
        {
            __auto_type k = ((int64_t)(((int64_t)((rb.props).len))));
            int64_t i = 0;
            while (i < k) {
                if ((howl_sriqnormal_rep_at(rb, (2 * i)) == (2 * i)) && (howl_sriqnormal_rep_at(rb, ((2 * i) + 1)) == (2 * i))) {
                    {
                        __auto_type p = howl_sriqrbox_node_role(rb.props, (2 * i));
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnormal_ria1(arena, howl_sroiq_inv_role(p), p)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
                i = (i + 1);
            }
        }
        if (bottom) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnormal_gci(arena, ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_some, .data.sc_some = { .f0 = howl_sriqnormal_collapse_role(rb, howl_sriqnormal_bottom_role()), .f1 = howl_sriqnormal_sc(arena, howl_sriqnormal_top_sc()) } }), ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_bottom }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        __auto_type _mv_265 = fault;
        if (_mv_265.has_value) {
            __auto_type m = _mv_265.value;
            return ((slop_result_howl_sriqnormal_S0_string){ .is_ok = false, .data.err = m });
        } else if (!_mv_265.has_value) {
            return ((slop_result_howl_sriqnormal_S0_string){ .is_ok = true, .data.ok = ((howl_sriqnormal_S0){.axioms = howl_sroiq_dedupe_saxioms(arena, howl_sroiq_sort_saxioms(arena, out)), .rbox = rb}) });
        }
        SLOP_UNREACHABLE();
    }
}

howl_sriqnormal_S2State* howl_sriqnormal_new_s2(slop_arena* arena) {
    {
        __auto_type p = ((howl_sriqnormal_S2State*)(({ __auto_type _alloc = (howl_sriqnormal_S2State*)slop_arena_alloc(arena, sizeof(howl_sriqnormal_S2State)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = ((howl_sriqnormal_S2State){.out = ((slop_list_howl_types_DlClause){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .registry = howl_naming_new_registry(arena), .concepts = ((slop_list_howl_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .sroles = ((slop_list_howl_types_DRole){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .sfills = ((slop_list_option_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .bars = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .barset = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .fnkeys = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .fnindex = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); })});
        return p;
    }
}

uint8_t howl_sriqnormal_emit(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DlClause c) {
    {
        __auto_type s = (*p);
        (void)(({ __auto_type _lst_p = &(s.out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (*p) = s;
        return 1;
    }
}

int64_t howl_sriqnormal_fresh_name(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept c) {
    {
        __auto_type id = howl_naming_fresh_id(arena, (*p).registry, howl_sroiq_sc_key(arena, c));
        if (((int64_t)(id)) == ((int64_t)(((int64_t)(((*p).concepts).len))))) {
            {
                __auto_type s = (*p);
                (void)(({ __auto_type _lst_p = &(s.concepts); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (*p) = s;
            }
        }
        return SLOP_RANGE(int64_t, id, 1, 0, 0, 0, "(Int 0 ..) at sriqnormal.slop:744:9");
    }
}

howl_sroiq_SConcept howl_sriqnormal_concept_of(howl_sriqnormal_S2State* p, int64_t k) {
    __auto_type _mv_266 = ({ __auto_type _lst = (*p).concepts; size_t _idx = (size_t)k; slop_option_howl_sroiq_SConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_266.has_value) {
        __auto_type c = _mv_266.value;
        return c;
    } else if (!_mv_266.has_value) {
        return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_top });
    }
    SLOP_UNREACHABLE();
}

howl_types_DRole howl_sriqnormal_role_name(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_RoleId r) {
    __auto_type _mv_267 = r;
    switch (_mv_267.tag) {
        case howl_types_RoleId_named_role:
        {
            __auto_type i = _mv_267.data.named_role;
            return ((howl_types_DRole){ .tag = howl_types_DRole_dr_prop, .data.dr_prop = i });
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type i = _mv_267.data.inverse_role;
            if (!(slop_map_has((*p).barset, &(i.value)))) {
                {
                    __auto_type s = (*p);
                    ({ slop_map_put(NULL, s.barset, &(i.value), NULL, 0); });
                    ({ __auto_type _lst_p = &(s.bars); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    (*p) = s;
                }
            }
            return ((howl_types_DRole){ .tag = howl_types_DRole_dr_bar, .data.dr_bar = i });
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type k = _mv_267.data.fresh_role;
            return ((howl_types_DRole){ .tag = howl_types_DRole_dr_sub, .data.dr_sub = k });
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_sriqnormal_dname_key(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DName n) {
    __auto_type _mv_270 = n;
    switch (_mv_270.tag) {
        case howl_types_DName_dn_class:
        {
            __auto_type i = _mv_270.data.dn_class;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">")));
        }
        case howl_types_DName_dn_fresh:
        {
            __auto_type k = _mv_270.data.dn_fresh;
            return string_concat(arena, SLOP_STR("["), string_concat(arena, howl_sroiq_sc_key(arena, howl_sriqnormal_concept_of(p, k)), SLOP_STR("]")));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_sriqnormal_filler_key(slop_arena* arena, howl_sriqnormal_S2State* p, slop_option_howl_types_DName b) {
    __auto_type _mv_271 = b;
    if (_mv_271.has_value) {
        __auto_type n = _mv_271.value;
        return howl_sriqnormal_dname_key(arena, p, n);
    } else if (!_mv_271.has_value) {
        return SLOP_STR("T");
    }
    SLOP_UNREACHABLE();
}

slop_string howl_sriqnormal_drole_key(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DRole r) {
    __auto_type _mv_272 = r;
    switch (_mv_272.tag) {
        case howl_types_DRole_dr_prop:
        {
            __auto_type i = _mv_272.data.dr_prop;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">")));
        }
        case howl_types_DRole_dr_bar:
        {
            __auto_type i = _mv_272.data.dr_bar;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">bar")));
        }
        case howl_types_DRole_dr_sub:
        {
            __auto_type k = _mv_272.data.dr_sub;
            return howl_sriqnormal_srole_key(arena, p, ({ __auto_type _mv = ({ __auto_type _lst = (*p).sroles; size_t _idx = (size_t)k; slop_option_howl_types_DRole _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : (r); }), ({ __auto_type _mv = ({ __auto_type _lst = (*p).sfills; size_t _idx = (size_t)k; slop_option_option_howl_types_DName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : ((slop_option_howl_types_DName){.has_value = false}); }));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_sriqnormal_key_of(slop_arena* arena, slop_string tag, slop_list_string parts) {
    {
        __auto_type out = string_concat(arena, tag, SLOP_STR("("));
        uint8_t first = 1;
        {
            __auto_type _coll = parts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (!(first)) {
                    out = string_concat(arena, out, SLOP_STR(","));
                }
                out = string_concat(arena, out, x);
                first = 0;
            }
        }
        return string_concat(arena, out, SLOP_STR(")"));
    }
}

slop_string howl_sriqnormal_srole_key(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DRole s, slop_option_howl_types_DName b) {
    {
        __auto_type parts = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (howl_sriqnormal_drole_key(arena, p, s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (howl_sriqnormal_filler_key(arena, p, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return howl_sriqnormal_key_of(arena, SLOP_STR("S"), parts);
    }
}

howl_types_DRole howl_sriqnormal_srole_of(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DRole s, slop_option_howl_types_DName b) {
    {
        __auto_type id = howl_naming_fresh_role_id(arena, (*p).registry, howl_sriqnormal_srole_key(arena, p, s, b));
        if (((int64_t)(id)) == ((int64_t)(((int64_t)(((*p).sroles).len))))) {
            {
                __auto_type st = (*p);
                (void)(({ __auto_type _lst_p = &(st.sroles); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(st.sfills); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (*p) = st;
            }
        }
        return ((howl_types_DRole){ .tag = howl_types_DRole_dr_sub, .data.dr_sub = id });
    }
}

int64_t howl_sriqnormal_fn_id(slop_arena* arena, howl_sriqnormal_S2State* p, slop_string key) {
    __auto_type _mv_274 = ({ void* _ptr = slop_map_get((*p).fnindex, &(key)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
    if (_mv_274.has_value) {
        __auto_type id = _mv_274.value;
        return ((int64_t)(id));
    } else if (!_mv_274.has_value) {
        {
            __auto_type s = (*p);
            __auto_type id = ((int64_t)(SLOP_RANGE(int64_t, ((int64_t)(((*p).fnkeys).len)), 1, 0, 0, 0, "(Int 0 ..) at sriqnormal.slop:834:36")));
            ({ __auto_type _lst_p = &(s.fnkeys); __auto_type _item = (key); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ int64_t _val = SLOP_RANGE(int64_t, id, 1, 0, 0, 0, "(Int 0 ..) at sriqnormal.slop:837:40"); slop_map_put(NULL, s.fnindex, &(key), &_val, sizeof(_val)); });
            (*p) = s;
            return SLOP_RANGE(int64_t, id, 1, 0, 0, 0, "(Int 0 ..) at sriqnormal.slop:839:13");
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_int howl_sriqnormal_fn_ids(slop_arena* arena, howl_sriqnormal_S2State* p, slop_string axkey, int64_t n) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 1;
        while (i <= n) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnormal_fn_id(arena, p, string_concat(arena, axkey, string_concat(arena, SLOP_STR("|"), int_to_string(arena, i))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            i = (i + 1);
        }
        return out;
    }
}

slop_list_howl_sroiq_SConcept howl_sriqnormal_nnf_list(slop_arena* arena, slop_list_howl_sroiq_SConcept xs, uint8_t pos) {
    {
        __auto_type out = ((slop_list_howl_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnormal_nnf(arena, x, pos)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_sroiq_SConcept howl_sriqnormal_nnf(slop_arena* arena, howl_sroiq_SConcept c, uint8_t pos) {
    if (pos) {
        __auto_type _mv_276 = c;
        switch (_mv_276.tag) {
            case howl_sroiq_SConcept_sc_top:
            {
                return c;
            }
            case howl_sroiq_SConcept_sc_bottom:
            {
                return c;
            }
            case howl_sroiq_SConcept_sc_name:
            {
                __auto_type _ = _mv_276.data.sc_name;
                return c;
            }
            case howl_sroiq_SConcept_sc_nominal:
            {
                __auto_type _ = _mv_276.data.sc_nominal;
                return c;
            }
            case howl_sroiq_SConcept_sc_self:
            {
                __auto_type _ = _mv_276.data.sc_self;
                return c;
            }
            case howl_sroiq_SConcept_sc_elim:
            {
                return c;
            }
            case howl_sroiq_SConcept_sc_not:
            {
                __auto_type f = _mv_276.data.sc_not;
                return howl_sriqnormal_nnf(arena, (*f), 0);
            }
            case howl_sroiq_SConcept_sc_and:
            {
                __auto_type xs = _mv_276.data.sc_and;
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_and, .data.sc_and = howl_sriqnormal_nnf_list(arena, xs, 1) });
            }
            case howl_sroiq_SConcept_sc_or:
            {
                __auto_type xs = _mv_276.data.sc_or;
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_or, .data.sc_or = howl_sriqnormal_nnf_list(arena, xs, 1) });
            }
            case howl_sroiq_SConcept_sc_some:
            {
                __auto_type r = _mv_276.data.sc_some.f0;
                __auto_type f = _mv_276.data.sc_some.f1;
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = howl_sriqnormal_sc(arena, howl_sriqnormal_nnf(arena, (*f), 1)) } });
            }
            case howl_sroiq_SConcept_sc_all:
            {
                __auto_type r = _mv_276.data.sc_all.f0;
                __auto_type f = _mv_276.data.sc_all.f1;
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = howl_sriqnormal_sc(arena, howl_sriqnormal_nnf(arena, (*f), 1)) } });
            }
            case howl_sroiq_SConcept_sc_atleast:
            {
                __auto_type n = _mv_276.data.sc_atleast.f0;
                __auto_type r = _mv_276.data.sc_atleast.f1;
                __auto_type f = _mv_276.data.sc_atleast.f2;
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_atleast, .data.sc_atleast = { .f0 = n, .f1 = r, .f2 = howl_sriqnormal_sc(arena, howl_sriqnormal_nnf(arena, (*f), 1)) } });
            }
            case howl_sroiq_SConcept_sc_atmost:
            {
                __auto_type n = _mv_276.data.sc_atmost.f0;
                __auto_type r = _mv_276.data.sc_atmost.f1;
                __auto_type f = _mv_276.data.sc_atmost.f2;
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = n, .f1 = r, .f2 = howl_sriqnormal_sc(arena, howl_sriqnormal_nnf(arena, (*f), 1)) } });
            }
        }
        SLOP_UNREACHABLE();
    } else {
        __auto_type _mv_277 = c;
        switch (_mv_277.tag) {
            case howl_sroiq_SConcept_sc_top:
            {
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_bottom });
            }
            case howl_sroiq_SConcept_sc_bottom:
            {
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_top });
            }
            case howl_sroiq_SConcept_sc_name:
            {
                __auto_type _ = _mv_277.data.sc_name;
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_not, .data.sc_not = howl_sriqnormal_sc(arena, c) });
            }
            case howl_sroiq_SConcept_sc_nominal:
            {
                __auto_type _ = _mv_277.data.sc_nominal;
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_not, .data.sc_not = howl_sriqnormal_sc(arena, c) });
            }
            case howl_sroiq_SConcept_sc_self:
            {
                __auto_type _ = _mv_277.data.sc_self;
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_not, .data.sc_not = howl_sriqnormal_sc(arena, c) });
            }
            case howl_sroiq_SConcept_sc_elim:
            {
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_not, .data.sc_not = howl_sriqnormal_sc(arena, c) });
            }
            case howl_sroiq_SConcept_sc_not:
            {
                __auto_type f = _mv_277.data.sc_not;
                return howl_sriqnormal_nnf(arena, (*f), 1);
            }
            case howl_sroiq_SConcept_sc_and:
            {
                __auto_type xs = _mv_277.data.sc_and;
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_or, .data.sc_or = howl_sriqnormal_nnf_list(arena, xs, 0) });
            }
            case howl_sroiq_SConcept_sc_or:
            {
                __auto_type xs = _mv_277.data.sc_or;
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_and, .data.sc_and = howl_sriqnormal_nnf_list(arena, xs, 0) });
            }
            case howl_sroiq_SConcept_sc_some:
            {
                __auto_type r = _mv_277.data.sc_some.f0;
                __auto_type f = _mv_277.data.sc_some.f1;
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = howl_sriqnormal_sc(arena, howl_sriqnormal_nnf(arena, (*f), 0)) } });
            }
            case howl_sroiq_SConcept_sc_all:
            {
                __auto_type r = _mv_277.data.sc_all.f0;
                __auto_type f = _mv_277.data.sc_all.f1;
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = howl_sriqnormal_sc(arena, howl_sriqnormal_nnf(arena, (*f), 0)) } });
            }
            case howl_sroiq_SConcept_sc_atleast:
            {
                __auto_type n = _mv_277.data.sc_atleast.f0;
                __auto_type r = _mv_277.data.sc_atleast.f1;
                __auto_type f = _mv_277.data.sc_atleast.f2;
                if (n == 0) {
                    return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_bottom });
                } else {
                    return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = ((int64_t)(SLOP_RANGE(int64_t, (n - 1), 1, 0, 0, 0, "(Int 0 ..) at sriqnormal.slop:901:60"))), .f1 = r, .f2 = howl_sriqnormal_sc(arena, howl_sriqnormal_nnf(arena, (*f), 1)) } });
                }
            }
            case howl_sroiq_SConcept_sc_atmost:
            {
                __auto_type n = _mv_277.data.sc_atmost.f0;
                __auto_type r = _mv_277.data.sc_atmost.f1;
                __auto_type f = _mv_277.data.sc_atmost.f2;
                return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_atleast, .data.sc_atleast = { .f0 = ((int64_t)((n + 1))), .f1 = r, .f2 = howl_sriqnormal_sc(arena, howl_sriqnormal_nnf(arena, (*f), 1)) } });
            }
        }
        SLOP_UNREACHABLE();
    }
}

slop_option_howl_types_DName howl_sriqnormal_pos_name(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept c) {
    __auto_type _mv_278 = c;
    switch (_mv_278.tag) {
        case howl_sroiq_SConcept_sc_top:
        {
            return (slop_option_howl_types_DName){.has_value = false};
        }
        case howl_sroiq_SConcept_sc_name:
        {
            __auto_type i = _mv_278.data.sc_name;
            return (slop_option_howl_types_DName){.has_value = 1, .value = ((howl_types_DName){ .tag = howl_types_DName_dn_class, .data.dn_class = i })};
        }
        case howl_sroiq_SConcept_sc_elim:
        {
            return (slop_option_howl_types_DName){.has_value = 1, .value = ((howl_types_DName){ .tag = howl_types_DName_dn_fresh, .data.dn_fresh = howl_sriqnormal_fresh_name(arena, p, c) })};
        }
        default: {
            {
                __auto_type key = howl_sroiq_sc_key(arena, c);
                __auto_type x = ((howl_types_DName){ .tag = howl_types_DName_dn_fresh, .data.dn_fresh = howl_sriqnormal_fresh_name(arena, p, c) });
                if (!(howl_naming_pos_defined((*p).registry, key))) {
                    howl_naming_mark_pos(arena, (*p).registry, key);
                    howl_sriqnormal_define_pos(arena, p, x, c);
                }
                return (slop_option_howl_types_DName){.has_value = 1, .value = x};
            }
        }
    }
}

slop_option_howl_types_DName howl_sriqnormal_neg_name(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept c) {
    __auto_type _mv_279 = c;
    switch (_mv_279.tag) {
        case howl_sroiq_SConcept_sc_top:
        {
            return (slop_option_howl_types_DName){.has_value = false};
        }
        case howl_sroiq_SConcept_sc_name:
        {
            __auto_type i = _mv_279.data.sc_name;
            return (slop_option_howl_types_DName){.has_value = 1, .value = ((howl_types_DName){ .tag = howl_types_DName_dn_class, .data.dn_class = i })};
        }
        case howl_sroiq_SConcept_sc_elim:
        {
            return (slop_option_howl_types_DName){.has_value = 1, .value = ((howl_types_DName){ .tag = howl_types_DName_dn_fresh, .data.dn_fresh = howl_sriqnormal_fresh_name(arena, p, c) })};
        }
        default: {
            {
                __auto_type key = howl_sroiq_sc_key(arena, c);
                __auto_type x = ((howl_types_DName){ .tag = howl_types_DName_dn_fresh, .data.dn_fresh = howl_sriqnormal_fresh_name(arena, p, c) });
                if (!(howl_naming_neg_defined((*p).registry, key))) {
                    howl_naming_mark_neg(arena, (*p).registry, key);
                    __auto_type _mv_280 = c;
                    switch (_mv_280.tag) {
                        case howl_sroiq_SConcept_sc_nominal:
                        {
                            __auto_type i = _mv_280.data.sc_nominal;
                            howl_sriqnormal_emit(arena, p, ((howl_types_DlClause){ .tag = howl_types_DlClause_dl10, .data.dl10 = { .f0 = i, .f1 = x } }));
                            break;
                        }
                        case howl_sroiq_SConcept_sc_self:
                        {
                            __auto_type r = _mv_280.data.sc_self;
                            howl_sriqnormal_emit(arena, p, ((howl_types_DlClause){ .tag = howl_types_DlClause_dl6, .data.dl6 = { .f0 = howl_sriqnormal_role_name(arena, p, r), .f1 = x } }));
                            break;
                        }
                        default: {
                            howl_sriqnormal_disjunction(arena, p, ((slop_option_howl_types_DName){.has_value = false}), (slop_option_howl_types_DName){.has_value = 1, .value = x}, howl_sroiq_sc_canon(arena, howl_sriqnormal_nnf(arena, c, 0)));
                            break;
                        }
                    }
                }
                return (slop_option_howl_types_DName){.has_value = 1, .value = x};
            }
        }
    }
}

slop_option_howl_types_DName howl_sriqnormal_neg_literal_name(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept lit) {
    return howl_sriqnormal_neg_name(arena, p, lit);
}

slop_list_howl_sroiq_SConcept howl_sriqnormal_singleton_sc(slop_arena* arena, howl_sroiq_SConcept c) {
    {
        __auto_type xs = ((slop_list_howl_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(xs); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return xs;
    }
}

uint8_t howl_sriqnormal_disjunction(slop_arena* arena, howl_sriqnormal_S2State* p, slop_option_howl_types_DName lhs, slop_option_howl_types_DName extra, howl_sroiq_SConcept e) {
    {
        __auto_type ds = ({ __auto_type _mv = e; slop_list_howl_sroiq_SConcept _mr = {0}; switch (_mv.tag) { case howl_sroiq_SConcept_sc_or: { __auto_type xs = _mv.data.sc_or; _mr = xs; break; } default: { _mr = howl_sriqnormal_singleton_sc(arena, e); break; }  } _mr; });
        __auto_type body = ((slop_list_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type head = ((slop_list_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t taut = 0;
        __auto_type _mv_281 = lhs;
        if (_mv_281.has_value) {
            __auto_type x = _mv_281.value;
            ({ __auto_type _lst_p = &(body); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (!_mv_281.has_value) {
        }
        __auto_type _mv_282 = extra;
        if (_mv_282.has_value) {
            __auto_type x = _mv_282.value;
            ({ __auto_type _lst_p = &(head); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (!_mv_282.has_value) {
        }
        {
            __auto_type _coll = ds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type d = _coll.data[_i];
                __auto_type _mv_283 = d;
                switch (_mv_283.tag) {
                    case howl_sroiq_SConcept_sc_top:
                    {
                        taut = 1;
                        break;
                    }
                    case howl_sroiq_SConcept_sc_bottom:
                    {
                        break;
                    }
                    case howl_sroiq_SConcept_sc_name:
                    {
                        __auto_type i = _mv_283.data.sc_name;
                        ({ __auto_type _lst_p = &(head); __auto_type _item = (((howl_types_DName){ .tag = howl_types_DName_dn_class, .data.dn_class = i })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_sroiq_SConcept_sc_not:
                    {
                        __auto_type f = _mv_283.data.sc_not;
                        __auto_type _mv_284 = howl_sriqnormal_neg_literal_name(arena, p, (*f));
                        if (_mv_284.has_value) {
                            __auto_type n = _mv_284.value;
                            ({ __auto_type _lst_p = &(body); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        } else if (!_mv_284.has_value) {
                        }
                        break;
                    }
                    default: {
                        __auto_type _mv_285 = howl_sriqnormal_pos_name(arena, p, d);
                        if (_mv_285.has_value) {
                            __auto_type n = _mv_285.value;
                            ({ __auto_type _lst_p = &(head); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        } else if (!_mv_285.has_value) {
                            taut = 1;
                        }
                        break;
                    }
                }
            }
        }
        if (!(taut)) {
            howl_sriqnormal_emit(arena, p, ((howl_types_DlClause){ .tag = howl_types_DlClause_dl1, .data.dl1 = ((howl_types_Dl1){.body = body, .head = head}) }));
        }
        return 1;
    }
}

uint8_t howl_sriqnormal_define_pos(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DName x, howl_sroiq_SConcept e) {
    __auto_type _mv_286 = e;
    switch (_mv_286.tag) {
        case howl_sroiq_SConcept_sc_top:
        {
            return 1;
        }
        case howl_sroiq_SConcept_sc_name:
        {
            __auto_type _ = _mv_286.data.sc_name;
            return howl_sriqnormal_disjunction(arena, p, (slop_option_howl_types_DName){.has_value = 1, .value = x}, ((slop_option_howl_types_DName){.has_value = false}), e);
        }
        case howl_sroiq_SConcept_sc_elim:
        {
            return howl_sriqnormal_disjunction(arena, p, (slop_option_howl_types_DName){.has_value = 1, .value = x}, ((slop_option_howl_types_DName){.has_value = false}), e);
        }
        case howl_sroiq_SConcept_sc_bottom:
        {
            return howl_sriqnormal_disjunction(arena, p, (slop_option_howl_types_DName){.has_value = 1, .value = x}, ((slop_option_howl_types_DName){.has_value = false}), e);
        }
        case howl_sroiq_SConcept_sc_not:
        {
            __auto_type _ = _mv_286.data.sc_not;
            return howl_sriqnormal_disjunction(arena, p, (slop_option_howl_types_DName){.has_value = 1, .value = x}, ((slop_option_howl_types_DName){.has_value = false}), e);
        }
        case howl_sroiq_SConcept_sc_or:
        {
            __auto_type _ = _mv_286.data.sc_or;
            return howl_sriqnormal_disjunction(arena, p, (slop_option_howl_types_DName){.has_value = 1, .value = x}, ((slop_option_howl_types_DName){.has_value = false}), e);
        }
        case howl_sroiq_SConcept_sc_nominal:
        {
            __auto_type i = _mv_286.data.sc_nominal;
            return howl_sriqnormal_emit(arena, p, ((howl_types_DlClause){ .tag = howl_types_DlClause_dl11, .data.dl11 = { .f0 = x, .f1 = i } }));
        }
        case howl_sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_286.data.sc_and;
            {
                __auto_type _coll = xs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    howl_sriqnormal_define_pos(arena, p, x, c);
                }
            }
            return 1;
        }
        case howl_sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_286.data.sc_some.f0;
            __auto_type f = _mv_286.data.sc_some.f1;
            return howl_sriqnormal_define_dl2(arena, p, x, r, 1, (*f));
        }
        case howl_sroiq_SConcept_sc_atleast:
        {
            __auto_type n = _mv_286.data.sc_atleast.f0;
            __auto_type r = _mv_286.data.sc_atleast.f1;
            __auto_type f = _mv_286.data.sc_atleast.f2;
            if (n == 0) {
                return 1;
            } else {
                return howl_sriqnormal_define_dl2(arena, p, x, r, n, (*f));
            }
        }
        case howl_sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_286.data.sc_all.f0;
            __auto_type f = _mv_286.data.sc_all.f1;
            __auto_type _mv_287 = howl_sriqnormal_pos_name(arena, p, (*f));
            if (!_mv_287.has_value) {
                return 1;
            } else if (_mv_287.has_value) {
                __auto_type b = _mv_287.value;
                return howl_sriqnormal_emit(arena, p, ((howl_types_DlClause){ .tag = howl_types_DlClause_dl3, .data.dl3 = { .f0 = howl_sriqnormal_role_name(arena, p, howl_sroiq_inv_role(r)), .f1 = x, .f2 = b } }));
            }
            SLOP_UNREACHABLE();
        }
        case howl_sroiq_SConcept_sc_atmost:
        {
            __auto_type n = _mv_286.data.sc_atmost.f0;
            __auto_type r = _mv_286.data.sc_atmost.f1;
            __auto_type f = _mv_286.data.sc_atmost.f2;
            {
                __auto_type s = howl_sriqnormal_role_name(arena, p, r);
                __auto_type b = howl_sriqnormal_neg_name(arena, p, (*f));
                return howl_sriqnormal_emit(arena, p, ((howl_types_DlClause){ .tag = howl_types_DlClause_dl4, .data.dl4 = ((howl_types_Dl4){.sub = x, .role = s, .count = n, .filler = b, .srole = howl_sriqnormal_srole_of(arena, p, s, b)}) }));
            }
        }
        case howl_sroiq_SConcept_sc_self:
        {
            __auto_type r = _mv_286.data.sc_self;
            return howl_sriqnormal_emit(arena, p, ((howl_types_DlClause){ .tag = howl_types_DlClause_dl5, .data.dl5 = { .f0 = x, .f1 = howl_sriqnormal_role_name(arena, p, r) } }));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqnormal_define_dl2(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_DName x, howl_types_RoleId r, int64_t n, howl_sroiq_SConcept f) {
    {
        __auto_type s = howl_sriqnormal_role_name(arena, p, r);
        __auto_type b = howl_sriqnormal_pos_name(arena, p, f);
        __auto_type parts = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (howl_sriqnormal_dname_key(arena, p, x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (int_to_string(arena, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (howl_sriqnormal_drole_key(arena, p, s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(parts); __auto_type _item = (howl_sriqnormal_filler_key(arena, p, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return howl_sriqnormal_emit(arena, p, ((howl_types_DlClause){ .tag = howl_types_DlClause_dl2, .data.dl2 = ((howl_types_Dl2){.sub = x, .role = s, .count = ((int64_t)(SLOP_RANGE(int64_t, n, 1, 0, 1, 0, "(Int 1 ..) at sriqnormal.slop:1052:82"))), .filler = b, .fns = howl_sriqnormal_fn_ids(arena, p, howl_sriqnormal_key_of(arena, SLOP_STR("dl2"), parts), ((int64_t)(n)))}) }));
    }
}

uint8_t howl_sriqnormal_s2_gci(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept l, howl_sroiq_SConcept r) {
    {
        __auto_type lc = howl_sroiq_sc_canon(arena, howl_sriqnormal_nnf(arena, l, 1));
        __auto_type _mv_288 = lc;
        switch (_mv_288.tag) {
            case howl_sroiq_SConcept_sc_some:
            {
                __auto_type role = _mv_288.data.sc_some.f0;
                __auto_type f = _mv_288.data.sc_some.f1;
                return howl_sriqnormal_gci_dl3(arena, p, role, (*f), howl_sroiq_sc_canon(arena, howl_sriqnormal_nnf(arena, r, 1)));
            }
            case howl_sroiq_SConcept_sc_top:
            {
                return howl_sriqnormal_assert_top(arena, p, howl_sroiq_sc_canon(arena, howl_sriqnormal_nnf(arena, r, 1)), 1);
            }
            default: {
                return howl_sriqnormal_gci_nnf(arena, p, l, r);
            }
        }
    }
}

uint8_t howl_sriqnormal_gci_nnf(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept l, howl_sroiq_SConcept r) {
    {
        __auto_type both = ((slop_list_howl_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(both); __auto_type _item = (((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_not, .data.sc_not = howl_sriqnormal_sc(arena, l) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(both); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return howl_sriqnormal_assert_top(arena, p, howl_sroiq_sc_canon(arena, howl_sriqnormal_nnf(arena, ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_or, .data.sc_or = both }), 1)), 0);
    }
}

uint8_t howl_sriqnormal_assert_top(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SConcept e, uint8_t ranges) {
    __auto_type _mv_289 = e;
    switch (_mv_289.tag) {
        case howl_sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_289.data.sc_and;
            {
                __auto_type _coll = xs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    howl_sriqnormal_assert_top(arena, p, c, ranges);
                }
            }
            return 1;
        }
        case howl_sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_289.data.sc_all.f0;
            __auto_type f = _mv_289.data.sc_all.f1;
            if (!(ranges)) {
                return howl_sriqnormal_disjunction(arena, p, ((slop_option_howl_types_DName){.has_value = false}), ((slop_option_howl_types_DName){.has_value = false}), e);
            } else if (howl_sriqnormal_sc_is_top((*f))) {
                return 1;
            } else {
                return howl_sriqnormal_dl3_of(arena, p, howl_sroiq_inv_role(r), (slop_option_howl_types_DName){.has_value = 1, .value = howl_sriqnormal_top_name(arena, p)}, (*f));
            }
        }
        default: {
            return howl_sriqnormal_disjunction(arena, p, ((slop_option_howl_types_DName){.has_value = false}), ((slop_option_howl_types_DName){.has_value = false}), e);
        }
    }
}

uint8_t howl_sriqnormal_sc_is_top(howl_sroiq_SConcept c) {
    __auto_type _mv_290 = c;
    switch (_mv_290.tag) {
        case howl_sroiq_SConcept_sc_top:
        {
            return 1;
        }
        default: {
            return 0;
        }
    }
}

uint8_t howl_sriqnormal_sc_is_bottom(howl_sroiq_SConcept c) {
    __auto_type _mv_291 = c;
    switch (_mv_291.tag) {
        case howl_sroiq_SConcept_sc_bottom:
        {
            return 1;
        }
        default: {
            return 0;
        }
    }
}

howl_types_DName howl_sriqnormal_top_name(slop_arena* arena, howl_sriqnormal_S2State* p) {
    {
        __auto_type c = ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_top });
        __auto_type key = howl_sroiq_sc_key(arena, ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_top }));
        __auto_type t = ((howl_types_DName){ .tag = howl_types_DName_dn_fresh, .data.dn_fresh = howl_sriqnormal_fresh_name(arena, p, ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_top })) });
        if (!(howl_naming_pos_defined((*p).registry, key))) {
            howl_naming_mark_pos(arena, (*p).registry, key);
            howl_sriqnormal_emit(arena, p, ((howl_types_DlClause){ .tag = howl_types_DlClause_dl1, .data.dl1 = ((howl_types_Dl1){.body = ((slop_list_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .head = howl_sriqnormal_one_name(arena, t)}) }));
        }
        return t;
    }
}

slop_list_howl_types_DName howl_sriqnormal_one_name(slop_arena* arena, howl_types_DName n) {
    {
        __auto_type xs = ((slop_list_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(xs); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return xs;
    }
}

uint8_t howl_sriqnormal_gci_dl3(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_RoleId r, howl_sroiq_SConcept c, howl_sroiq_SConcept d) {
    if (howl_sriqnormal_sc_is_bottom(c) || howl_sriqnormal_sc_is_top(d)) {
        return 1;
    } else if (howl_sriqnormal_sc_is_top(c)) {
        return howl_sriqnormal_dl3_of(arena, p, r, (slop_option_howl_types_DName){.has_value = 1, .value = howl_sriqnormal_top_name(arena, p)}, d);
    } else {
        return howl_sriqnormal_dl3_of(arena, p, r, howl_sriqnormal_neg_name(arena, p, c), d);
    }
}

uint8_t howl_sriqnormal_dl3_of(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_RoleId r, slop_option_howl_types_DName b1, howl_sroiq_SConcept d) {
    __auto_type _mv_292 = b1;
    if (!_mv_292.has_value) {
        return 1;
    } else if (_mv_292.has_value) {
        __auto_type x = _mv_292.value;
        __auto_type _mv_293 = howl_sriqnormal_pos_name(arena, p, d);
        if (!_mv_293.has_value) {
            return 1;
        } else if (_mv_293.has_value) {
            __auto_type y = _mv_293.value;
            return howl_sriqnormal_emit(arena, p, ((howl_types_DlClause){ .tag = howl_types_DlClause_dl3, .data.dl3 = { .f0 = howl_sriqnormal_role_name(arena, p, r), .f1 = x, .f2 = y } }));
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_option_slop_rdf_rdf_IRI howl_sriqnormal_role_prop(howl_types_RoleId r) {
    __auto_type _mv_294 = r;
    switch (_mv_294.tag) {
        case howl_types_RoleId_named_role:
        {
            __auto_type i = _mv_294.data.named_role;
            return (slop_option_slop_rdf_rdf_IRI){.has_value = 1, .value = i};
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type i = _mv_294.data.inverse_role;
            return (slop_option_slop_rdf_rdf_IRI){.has_value = 1, .value = i};
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_294.data.fresh_role;
            return (slop_option_slop_rdf_rdf_IRI){.has_value = false};
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqnormal_role_inverted(howl_types_RoleId r) {
    __auto_type _mv_295 = r;
    switch (_mv_295.tag) {
        case howl_types_RoleId_inverse_role:
        {
            __auto_type _ = _mv_295.data.inverse_role;
            return 1;
        }
        default: {
            return 0;
        }
    }
}

slop_result_u8_string howl_sriqnormal_s2_inclusion(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_RoleId r, howl_types_RoleId s) {
    __auto_type _mv_296 = howl_sriqnormal_role_prop(r);
    if (!_mv_296.has_value) {
        return ((slop_result_u8_string){ .is_ok = false, .data.err = SLOP_STR("a fresh role in S2") });
    } else if (_mv_296.has_value) {
        __auto_type pi = _mv_296.value;
        __auto_type _mv_297 = howl_sriqnormal_role_prop(s);
        if (!_mv_297.has_value) {
            return ((slop_result_u8_string){ .is_ok = false, .data.err = SLOP_STR("a fresh role in S2") });
        } else if (_mv_297.has_value) {
            __auto_type qi = _mv_297.value;
            {
                __auto_type a = ((howl_types_DRole){ .tag = howl_types_DRole_dr_prop, .data.dr_prop = pi });
                __auto_type b = ((howl_types_DRole){ .tag = howl_types_DRole_dr_prop, .data.dr_prop = qi });
                howl_sriqnormal_emit(arena, p, (((howl_sriqnormal_role_inverted(r) == howl_sriqnormal_role_inverted(s))) ? ((howl_types_DlClause){ .tag = howl_types_DlClause_dl7, .data.dl7 = { .f0 = a, .f1 = b } }) : ((howl_types_DlClause){ .tag = howl_types_DlClause_dl8, .data.dl8 = { .f0 = a, .f1 = b } })));
                return ((slop_result_u8_string){ .is_ok = true, .data.ok = 1 });
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_u8_string howl_sriqnormal_s2_ria(slop_arena* arena, howl_sriqnormal_S2State* p, howl_sroiq_SRia x) {
    if (((int64_t)((x.word).len)) != 1) {
        return ((slop_result_u8_string){ .is_ok = false, .data.err = SLOP_STR("a complex role inclusion reached S2: S1 must eliminate it first") });
    } else {
        __auto_type _mv_298 = ({ __auto_type _lst = x.word; size_t _idx = (size_t)0; slop_option_howl_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_298.has_value) {
            return ((slop_result_u8_string){ .is_ok = false, .data.err = SLOP_STR("an empty role inclusion") });
        } else if (_mv_298.has_value) {
            __auto_type r = _mv_298.value;
            return howl_sriqnormal_s2_inclusion(arena, p, r, x.super);
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t howl_sriqnormal_s2_dis(slop_arena* arena, howl_sriqnormal_S2State* p, howl_types_RoleId r, howl_types_RoleId s) {
    __auto_type _mv_299 = r;
    switch (_mv_299.tag) {
        case howl_types_RoleId_inverse_role:
        {
            __auto_type pi = _mv_299.data.inverse_role;
            __auto_type _mv_300 = s;
            switch (_mv_300.tag) {
                case howl_types_RoleId_inverse_role:
                {
                    __auto_type qi = _mv_300.data.inverse_role;
                    return howl_sriqnormal_emit(arena, p, ((howl_types_DlClause){ .tag = howl_types_DlClause_dl9, .data.dl9 = { .f0 = ((howl_types_DRole){ .tag = howl_types_DRole_dr_prop, .data.dr_prop = pi }), .f1 = ((howl_types_DRole){ .tag = howl_types_DRole_dr_prop, .data.dr_prop = qi }) } }));
                }
                default: {
                    return howl_sriqnormal_emit(arena, p, ((howl_types_DlClause){ .tag = howl_types_DlClause_dl9, .data.dl9 = { .f0 = howl_sriqnormal_role_name(arena, p, r), .f1 = howl_sriqnormal_role_name(arena, p, s) } }));
                }
            }
        }
        default: {
            return howl_sriqnormal_emit(arena, p, ((howl_types_DlClause){ .tag = howl_types_DlClause_dl9, .data.dl9 = { .f0 = howl_sriqnormal_role_name(arena, p, r), .f1 = howl_sriqnormal_role_name(arena, p, s) } }));
        }
    }
}

uint8_t howl_sriqnormal_counts_ok(howl_sroiq_SConcept c) {
    __auto_type _mv_301 = c;
    switch (_mv_301.tag) {
        case howl_sroiq_SConcept_sc_top:
        {
            return 1;
        }
        case howl_sroiq_SConcept_sc_bottom:
        {
            return 1;
        }
        case howl_sroiq_SConcept_sc_name:
        {
            __auto_type _ = _mv_301.data.sc_name;
            return 1;
        }
        case howl_sroiq_SConcept_sc_nominal:
        {
            __auto_type _ = _mv_301.data.sc_nominal;
            return 1;
        }
        case howl_sroiq_SConcept_sc_self:
        {
            __auto_type _ = _mv_301.data.sc_self;
            return 1;
        }
        case howl_sroiq_SConcept_sc_elim:
        {
            return 1;
        }
        case howl_sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_301.data.sc_not;
            return howl_sriqnormal_counts_ok((*f));
        }
        case howl_sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_301.data.sc_and;
            return howl_sriqnormal_counts_list_ok(xs);
        }
        case howl_sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_301.data.sc_or;
            return howl_sriqnormal_counts_list_ok(xs);
        }
        case howl_sroiq_SConcept_sc_some:
        {
            __auto_type f = _mv_301.data.sc_some.f1;
            return howl_sriqnormal_counts_ok((*f));
        }
        case howl_sroiq_SConcept_sc_all:
        {
            __auto_type f = _mv_301.data.sc_all.f1;
            return howl_sriqnormal_counts_ok((*f));
        }
        case howl_sroiq_SConcept_sc_atleast:
        {
            __auto_type n = _mv_301.data.sc_atleast.f0;
            __auto_type f = _mv_301.data.sc_atleast.f2;
            return ((n <= howl_owl2_SRIQ_MAX_COUNT) && howl_sriqnormal_counts_ok((*f)));
        }
        case howl_sroiq_SConcept_sc_atmost:
        {
            __auto_type n = _mv_301.data.sc_atmost.f0;
            __auto_type f = _mv_301.data.sc_atmost.f2;
            return ((n <= howl_owl2_SRIQ_MAX_COUNT) && howl_sriqnormal_counts_ok((*f)));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqnormal_counts_list_ok(slop_list_howl_sroiq_SConcept cs) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(howl_sriqnormal_counts_ok(c))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

slop_result_howl_sriqnormal_S2_string howl_sriqnormal_sriq_s2(slop_arena* arena, slop_list_howl_sroiq_SAxiom axs) {
    {
        __auto_type p = howl_sriqnormal_new_s2(arena);
        slop_option_string fault = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_302 = a;
                switch (_mv_302.tag) {
                    case howl_sroiq_SAxiom_sa_gci:
                    {
                        __auto_type l = _mv_302.data.sa_gci.f0;
                        __auto_type r = _mv_302.data.sa_gci.f1;
                        if (!((howl_sriqnormal_counts_ok((*l)) && howl_sriqnormal_counts_ok((*r))))) {
                            fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("a number restriction above the sriq gate's bound of 16 reached S2")};
                        }
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_303 = a;
                switch (_mv_303.tag) {
                    case howl_sroiq_SAxiom_sa_gci:
                    {
                        __auto_type l = _mv_303.data.sa_gci.f0;
                        __auto_type r = _mv_303.data.sa_gci.f1;
                        howl_sriqnormal_s2_gci(arena, p, (*l), (*r));
                        break;
                    }
                    case howl_sroiq_SAxiom_sa_ria:
                    {
                        __auto_type x = _mv_303.data.sa_ria;
                        __auto_type _mv_304 = howl_sriqnormal_s2_ria(arena, p, x);
                        if (_mv_304.is_ok) {
                            __auto_type _ = _mv_304.data.ok;
                        } else if (!_mv_304.is_ok) {
                            __auto_type m = _mv_304.data.err;
                            fault = (slop_option_string){.has_value = 1, .value = m};
                        }
                        break;
                    }
                    case howl_sroiq_SAxiom_sa_ref:
                    {
                        __auto_type r = _mv_303.data.sa_ref;
                        howl_sriqnormal_s2_gci(arena, p, ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_top }), ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_self, .data.sc_self = r }));
                        break;
                    }
                    case howl_sroiq_SAxiom_sa_irr:
                    {
                        __auto_type r = _mv_303.data.sa_irr;
                        howl_sriqnormal_s2_gci(arena, p, ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_self, .data.sc_self = r }), ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_bottom }));
                        break;
                    }
                    case howl_sroiq_SAxiom_sa_dis:
                    {
                        __auto_type r = _mv_303.data.sa_dis.f0;
                        __auto_type s = _mv_303.data.sa_dis.f1;
                        howl_sriqnormal_s2_dis(arena, p, r, s);
                        break;
                    }
                }
            }
        }
        {
            __auto_type _coll = (*p).bars;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                howl_sriqnormal_emit(arena, p, ((howl_types_DlClause){ .tag = howl_types_DlClause_dl8, .data.dl8 = { .f0 = ((howl_types_DRole){ .tag = howl_types_DRole_dr_prop, .data.dr_prop = i }), .f1 = ((howl_types_DRole){ .tag = howl_types_DRole_dr_bar, .data.dr_bar = i }) } }));
                howl_sriqnormal_emit(arena, p, ((howl_types_DlClause){ .tag = howl_types_DlClause_dl8, .data.dl8 = { .f0 = ((howl_types_DRole){ .tag = howl_types_DRole_dr_bar, .data.dr_bar = i }), .f1 = ((howl_types_DRole){ .tag = howl_types_DRole_dr_prop, .data.dr_prop = i }) } }));
            }
        }
        __auto_type _mv_305 = fault;
        if (_mv_305.has_value) {
            __auto_type m = _mv_305.value;
            return ((slop_result_howl_sriqnormal_S2_string){ .is_ok = false, .data.err = m });
        } else if (!_mv_305.has_value) {
            {
                __auto_type s = (*p);
                return ((slop_result_howl_sriqnormal_S2_string){ .is_ok = true, .data.ok = ((howl_sriqnormal_S2){.clauses = s.out, .concepts = s.concepts, .sroles = s.sroles, .sfills = s.sfills, .bars = s.bars, .fnkeys = s.fnkeys}) });
            }
        }
        SLOP_UNREACHABLE();
    }
}

slop_string howl_sriqnormal_render_dname(slop_arena* arena, howl_sriqnormal_S2 s2, howl_types_DName n) {
    __auto_type _mv_306 = n;
    switch (_mv_306.tag) {
        case howl_types_DName_dn_class:
        {
            __auto_type i = _mv_306.data.dn_class;
            return i.value;
        }
        case howl_types_DName_dn_fresh:
        {
            __auto_type k = _mv_306.data.dn_fresh;
            __auto_type _mv_307 = ({ __auto_type _lst = s2.concepts; size_t _idx = (size_t)k; slop_option_howl_sroiq_SConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_307.has_value) {
                __auto_type c = _mv_307.value;
                return howl_sriqnormal_render_fresh(arena, c);
            } else if (!_mv_307.has_value) {
                return SLOP_STR("A[?]");
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_sriqnormal_render_fresh(slop_arena* arena, howl_sroiq_SConcept c) {
    __auto_type _mv_308 = c;
    switch (_mv_308.tag) {
        case howl_sroiq_SConcept_sc_elim:
        {
            return howl_sroiq_render_sconcept(arena, c);
        }
        default: {
            return string_concat(arena, SLOP_STR("A["), string_concat(arena, howl_sroiq_render_sconcept(arena, c), SLOP_STR("]")));
        }
    }
}

slop_string howl_sriqnormal_render_dfiller(slop_arena* arena, howl_sriqnormal_S2 s2, slop_option_howl_types_DName b) {
    __auto_type _mv_309 = b;
    if (_mv_309.has_value) {
        __auto_type n = _mv_309.value;
        return howl_sriqnormal_render_dname(arena, s2, n);
    } else if (!_mv_309.has_value) {
        return SLOP_STR("⊤");
    }
    SLOP_UNREACHABLE();
}

slop_string howl_sriqnormal_render_drole(slop_arena* arena, howl_sriqnormal_S2 s2, howl_types_DRole r) {
    __auto_type _mv_310 = r;
    switch (_mv_310.tag) {
        case howl_types_DRole_dr_prop:
        {
            __auto_type i = _mv_310.data.dr_prop;
            return i.value;
        }
        case howl_types_DRole_dr_bar:
        {
            __auto_type i = _mv_310.data.dr_bar;
            return string_concat(arena, SLOP_STR("bar("), string_concat(arena, i.value, SLOP_STR(")")));
        }
        case howl_types_DRole_dr_sub:
        {
            __auto_type k = _mv_310.data.dr_sub;
            {
                __auto_type s = ({ __auto_type _mv = ({ __auto_type _lst = s2.sroles; size_t _idx = (size_t)k; slop_option_howl_types_DRole _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : (r); });
                __auto_type b = ({ __auto_type _mv = ({ __auto_type _lst = s2.sfills; size_t _idx = (size_t)k; slop_option_option_howl_types_DName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : ((slop_option_howl_types_DName){.has_value = false}); });
                return string_concat(arena, SLOP_STR("S_{"), string_concat(arena, howl_sriqnormal_render_drole(arena, s2, s), string_concat(arena, SLOP_STR(","), string_concat(arena, howl_sriqnormal_render_dfiller(arena, s2, b), SLOP_STR("}")))));
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_sriqnormal_render_dnames(slop_arena* arena, howl_sriqnormal_S2 s2, slop_list_howl_types_DName ns, slop_string sep, slop_string empty) {
    if (((int64_t)((ns).len)) == 0) {
        return empty;
    } else {
        {
            __auto_type out = SLOP_STR("");
            uint8_t first = 1;
            {
                __auto_type _coll = ns;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type n = _coll.data[_i];
                    if (!(first)) {
                        out = string_concat(arena, out, sep);
                    }
                    out = string_concat(arena, out, howl_sriqnormal_render_dname(arena, s2, n));
                    first = 0;
                }
            }
            return out;
        }
    }
}

slop_string howl_sriqnormal_inclusion(slop_arena* arena, slop_string form, slop_string lhs, slop_string rhs) {
    return string_concat(arena, form, string_concat(arena, SLOP_STR(" "), string_concat(arena, lhs, string_concat(arena, SLOP_STR(" ⊑ "), rhs))));
}

slop_string howl_sriqnormal_restriction_text(slop_arena* arena, slop_string op, slop_string role, slop_string filler) {
    return string_concat(arena, op, string_concat(arena, role, string_concat(arena, SLOP_STR("."), filler)));
}

slop_string howl_sriqnormal_count_op(slop_arena* arena, slop_string op, int64_t n) {
    return string_concat(arena, op, string_concat(arena, int_to_string(arena, n), SLOP_STR(" ")));
}

slop_string howl_sriqnormal_braces(slop_arena* arena, slop_rdf_rdf_IRI o) {
    return string_concat(arena, SLOP_STR("{"), string_concat(arena, o.value, SLOP_STR("}")));
}

slop_string howl_sriqnormal_render_dl(slop_arena* arena, howl_sriqnormal_S2 s2, howl_types_DlClause c) {
    __auto_type _mv_311 = c;
    switch (_mv_311.tag) {
        case howl_types_DlClause_dl1:
        {
            __auto_type d = _mv_311.data.dl1;
            return howl_sriqnormal_inclusion(arena, SLOP_STR("DL1"), howl_sriqnormal_render_dnames(arena, s2, d.body, SLOP_STR(" ⊓ "), SLOP_STR("⊤")), howl_sriqnormal_render_dnames(arena, s2, d.head, SLOP_STR(" ⊔ "), SLOP_STR("⊥")));
        }
        case howl_types_DlClause_dl2:
        {
            __auto_type d = _mv_311.data.dl2;
            return howl_sriqnormal_inclusion(arena, SLOP_STR("DL2"), howl_sriqnormal_render_dname(arena, s2, d.sub), howl_sriqnormal_restriction_text(arena, howl_sriqnormal_count_op(arena, SLOP_STR("≥"), d.count), howl_sriqnormal_render_drole(arena, s2, d.role), howl_sriqnormal_render_dfiller(arena, s2, d.filler)));
        }
        case howl_types_DlClause_dl3:
        {
            __auto_type s = _mv_311.data.dl3.f0;
            __auto_type b1 = _mv_311.data.dl3.f1;
            __auto_type b2 = _mv_311.data.dl3.f2;
            return howl_sriqnormal_inclusion(arena, SLOP_STR("DL3"), howl_sriqnormal_restriction_text(arena, SLOP_STR("∃"), howl_sriqnormal_render_drole(arena, s2, s), howl_sriqnormal_render_dname(arena, s2, b1)), howl_sriqnormal_render_dname(arena, s2, b2));
        }
        case howl_types_DlClause_dl4:
        {
            __auto_type d = _mv_311.data.dl4;
            return howl_sriqnormal_inclusion(arena, SLOP_STR("DL4"), howl_sriqnormal_render_dname(arena, s2, d.sub), string_concat(arena, howl_sriqnormal_restriction_text(arena, howl_sriqnormal_count_op(arena, SLOP_STR("≤"), d.count), howl_sriqnormal_render_drole(arena, s2, d.role), howl_sriqnormal_render_dfiller(arena, s2, d.filler)), string_concat(arena, SLOP_STR(" via "), howl_sriqnormal_render_drole(arena, s2, d.srole))));
        }
        case howl_types_DlClause_dl5:
        {
            __auto_type b = _mv_311.data.dl5.f0;
            __auto_type s = _mv_311.data.dl5.f1;
            return howl_sriqnormal_inclusion(arena, SLOP_STR("DL5"), howl_sriqnormal_render_dname(arena, s2, b), howl_sriqnormal_restriction_text(arena, SLOP_STR("∃"), howl_sriqnormal_render_drole(arena, s2, s), SLOP_STR("Self")));
        }
        case howl_types_DlClause_dl6:
        {
            __auto_type s = _mv_311.data.dl6.f0;
            __auto_type b = _mv_311.data.dl6.f1;
            return howl_sriqnormal_inclusion(arena, SLOP_STR("DL6"), howl_sriqnormal_restriction_text(arena, SLOP_STR("∃"), howl_sriqnormal_render_drole(arena, s2, s), SLOP_STR("Self")), howl_sriqnormal_render_dname(arena, s2, b));
        }
        case howl_types_DlClause_dl7:
        {
            __auto_type a = _mv_311.data.dl7.f0;
            __auto_type b = _mv_311.data.dl7.f1;
            return howl_sriqnormal_inclusion(arena, SLOP_STR("DL7"), howl_sriqnormal_render_drole(arena, s2, a), howl_sriqnormal_render_drole(arena, s2, b));
        }
        case howl_types_DlClause_dl8:
        {
            __auto_type a = _mv_311.data.dl8.f0;
            __auto_type b = _mv_311.data.dl8.f1;
            return howl_sriqnormal_inclusion(arena, SLOP_STR("DL8"), howl_sriqnormal_render_drole(arena, s2, a), string_concat(arena, howl_sriqnormal_render_drole(arena, s2, b), SLOP_STR("⁻")));
        }
        case howl_types_DlClause_dl9:
        {
            __auto_type a = _mv_311.data.dl9.f0;
            __auto_type b = _mv_311.data.dl9.f1;
            return string_concat(arena, SLOP_STR("DL9 Disj("), string_concat(arena, howl_sriqnormal_render_drole(arena, s2, a), string_concat(arena, SLOP_STR(", "), string_concat(arena, howl_sriqnormal_render_drole(arena, s2, b), SLOP_STR(")")))));
        }
        case howl_types_DlClause_dl10:
        {
            __auto_type o = _mv_311.data.dl10.f0;
            __auto_type b = _mv_311.data.dl10.f1;
            return howl_sriqnormal_inclusion(arena, SLOP_STR("DL10"), howl_sriqnormal_braces(arena, o), howl_sriqnormal_render_dname(arena, s2, b));
        }
        case howl_types_DlClause_dl11:
        {
            __auto_type b = _mv_311.data.dl11.f0;
            __auto_type o = _mv_311.data.dl11.f1;
            return howl_sriqnormal_inclusion(arena, SLOP_STR("DL11"), howl_sriqnormal_render_dname(arena, s2, b), howl_sriqnormal_braces(arena, o));
        }
    }
    SLOP_UNREACHABLE();
}

