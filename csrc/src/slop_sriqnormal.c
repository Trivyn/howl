#include "../runtime/slop_runtime.h"
#include "slop_sriqnormal.h"

sroiq_SConcept* sriqnormal_sc(slop_arena* arena, sroiq_SConcept c);
slop_result_list_sroiq_SConcept_string sriqnormal_s0_concepts(slop_arena* arena, slop_list_owl2_RawConcept cs);
slop_result_sroiq_SConcept_string sriqnormal_s0_filler(slop_arena* arena, owl2_RawConcept* f);
sroiq_SConcept sriqnormal_s0_count(slop_arena* arena, owl2_CardKind k, types_RoleId r, int64_t n, sroiq_SConcept f);
slop_result_sroiq_SConcept_string sriqnormal_s0_concept(slop_arena* arena, owl2_RawConcept c);
sroiq_SAxiom sriqnormal_gci(slop_arena* arena, sroiq_SConcept l, sroiq_SConcept r);
sroiq_SAxiom sriqnormal_ria(slop_arena* arena, slop_list_types_RoleId w, types_RoleId s);
sroiq_SAxiom sriqnormal_ria1(slop_arena* arena, types_RoleId r, types_RoleId s);
slop_option_sroiq_SConcept sriqnormal_nominal(types_Node n);
slop_option_rdf_IRI sriqnormal_least_individual(slop_list_types_Node ns);
sroiq_SConcept sriqnormal_top_sc(void);
slop_list_sroiq_SAxiom sriqnormal_one_axiom(slop_arena* arena, sroiq_SAxiom a);
slop_list_sroiq_SAxiom sriqnormal_two_axioms(slop_arena* arena, sroiq_SAxiom a, sroiq_SAxiom b);
sroiq_SAxiom sriqnormal_meet_empty(slop_arena* arena, sroiq_SConcept a, sroiq_SConcept b);
slop_list_sroiq_SAxiom sriqnormal_pairwise_disjoint(slop_arena* arena, slop_list_sroiq_SConcept xs);
slop_list_sroiq_SAxiom sriqnormal_pairwise_dis(slop_arena* arena, slop_list_types_RoleId rs);
slop_list_sroiq_SAxiom sriqnormal_mutual_gcis(slop_arena* arena, slop_list_sroiq_SConcept xs);
slop_list_sroiq_SAxiom sriqnormal_mutual_rias(slop_arena* arena, slop_list_types_RoleId rs);
slop_list_sroiq_SAxiom sriqnormal_around_hub(slop_arena* arena, sroiq_SConcept hub, slop_list_sroiq_SConcept xs);
slop_result_list_sroiq_SConcept_string sriqnormal_s0_nominals(slop_arena* arena, slop_list_types_Node ns, slop_string what);
sroiq_SAxiom sriqnormal_transitivity(slop_arena* arena, types_RoleId r);
sroiq_SAxiom sriqnormal_characteristic(slop_arena* arena, owl2_PropCharacteristic c, types_RoleId r);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_sub_class(slop_arena* arena, owl2_RawConcept* l, owl2_RawConcept* r);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_equivalent_classes(slop_arena* arena, slop_list_owl2_RawConcept cs);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_disjoint_classes(slop_arena* arena, slop_list_owl2_RawConcept cs);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_domain(slop_arena* arena, types_RoleId r, owl2_RawConcept* c);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_range(slop_arena* arena, types_RoleId r, owl2_RawConcept* c);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_class_assertion(slop_arena* arena, owl2_RawClassAssertion ca);
sroiq_SConcept sriqnormal_edge_filler(slop_arena* arena, types_RoleId r, sroiq_SConcept b, uint8_t negative);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_assertion(slop_arena* arena, owl2_RawEdge e, slop_string what, uint8_t negative);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_same_individual(slop_arena* arena, slop_list_types_Node ns);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_different_individuals(slop_arena* arena, slop_list_types_Node ns);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_disjoint_union(slop_arena* arena, owl2_RawDisjointUnion du);
slop_result_list_sroiq_SAxiom_string sriqnormal_s0_axiom(slop_arena* arena, owl2_RawAxiom ax);
int64_t sriqnormal_rep_at(sriqrbox_SriqRbox rb, int64_t n);
types_RoleId sriqnormal_collapse_role(sriqrbox_SriqRbox rb, types_RoleId r);
slop_list_types_RoleId sriqnormal_collapse_word(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_types_RoleId w);
slop_list_sroiq_SConcept sriqnormal_collapse_concepts(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_sroiq_SConcept cs);
sroiq_SConcept sriqnormal_collapse_concept(slop_arena* arena, sriqrbox_SriqRbox rb, sroiq_SConcept c);
uint8_t sriqnormal_trivial_ria(slop_list_types_RoleId w, types_RoleId s);
uint8_t sriqnormal_role_eq_p(types_RoleId a, types_RoleId b);
slop_option_sroiq_SAxiom sriqnormal_collapse_axiom(slop_arena* arena, sriqrbox_SriqRbox rb, sroiq_SAxiom a);
types_RoleId sriqnormal_bottom_role(void);
uint8_t sriqnormal_is_bottom(types_RoleId r);
uint8_t sriqnormal_concept_bottom_p(sroiq_SConcept c);
uint8_t sriqnormal_concepts_bottom_p(slop_list_sroiq_SConcept cs);
uint8_t sriqnormal_axiom_bottom_p(sroiq_SAxiom a);
slop_result_sriqnormal_S0_string sriqnormal_sriq_s0(slop_arena* arena, slop_list_owl2_RawAxiom accepted);
uint8_t sriqnormal_ria_complex(sriqrbox_SriqRbox rb, sroiq_SRia x);
slop_result_list_sroiq_SAxiom_string sriqnormal_sriq_s1(slop_arena* arena, sriqnormal_S0 s0);
sriqnormal_S2State* sriqnormal_new_s2(slop_arena* arena);
uint8_t sriqnormal_emit(slop_arena* arena, sriqnormal_S2State* p, types_DlClause c);
int64_t sriqnormal_fresh_name(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept c);
sroiq_SConcept sriqnormal_concept_of(sriqnormal_S2State* p, int64_t k);
types_DRole sriqnormal_role_name(slop_arena* arena, sriqnormal_S2State* p, types_RoleId r);
slop_string sriqnormal_dname_key(slop_arena* arena, sriqnormal_S2State* p, types_DName n);
slop_string sriqnormal_filler_key(slop_arena* arena, sriqnormal_S2State* p, slop_option_types_DName b);
slop_string sriqnormal_drole_key(slop_arena* arena, sriqnormal_S2State* p, types_DRole r);
slop_string sriqnormal_key_of(slop_arena* arena, slop_string tag, slop_list_string parts);
slop_string sriqnormal_srole_key(slop_arena* arena, sriqnormal_S2State* p, types_DRole s, slop_option_types_DName b);
types_DRole sriqnormal_srole_of(slop_arena* arena, sriqnormal_S2State* p, types_DRole s, slop_option_types_DName b);
int64_t sriqnormal_fn_id(slop_arena* arena, sriqnormal_S2State* p, slop_string key);
slop_list_int sriqnormal_fn_ids(slop_arena* arena, sriqnormal_S2State* p, slop_string axkey, int64_t n);
slop_list_sroiq_SConcept sriqnormal_nnf_list(slop_arena* arena, slop_list_sroiq_SConcept xs, uint8_t pos);
sroiq_SConcept sriqnormal_nnf(slop_arena* arena, sroiq_SConcept c, uint8_t pos);
slop_option_types_DName sriqnormal_pos_name(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept c);
slop_option_types_DName sriqnormal_neg_name(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept c);
slop_option_types_DName sriqnormal_neg_literal_name(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept lit);
slop_list_sroiq_SConcept sriqnormal_singleton_sc(slop_arena* arena, sroiq_SConcept c);
uint8_t sriqnormal_disjunction(slop_arena* arena, sriqnormal_S2State* p, slop_option_types_DName lhs, slop_option_types_DName extra, sroiq_SConcept e);
uint8_t sriqnormal_define_pos(slop_arena* arena, sriqnormal_S2State* p, types_DName x, sroiq_SConcept e);
uint8_t sriqnormal_define_dl2(slop_arena* arena, sriqnormal_S2State* p, types_DName x, types_RoleId r, int64_t n, sroiq_SConcept f);
uint8_t sriqnormal_s2_gci(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept l, sroiq_SConcept r);
uint8_t sriqnormal_assert_top(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept e);
slop_option_rdf_IRI sriqnormal_role_prop(types_RoleId r);
uint8_t sriqnormal_role_inverted(types_RoleId r);
slop_result_u8_string sriqnormal_s2_inclusion(slop_arena* arena, sriqnormal_S2State* p, types_RoleId r, types_RoleId s);
slop_result_u8_string sriqnormal_s2_ria(slop_arena* arena, sriqnormal_S2State* p, sroiq_SRia x);
uint8_t sriqnormal_s2_dis(slop_arena* arena, sriqnormal_S2State* p, types_RoleId r, types_RoleId s);
uint8_t sriqnormal_counts_ok(sroiq_SConcept c);
uint8_t sriqnormal_counts_list_ok(slop_list_sroiq_SConcept cs);
slop_result_sriqnormal_S2_string sriqnormal_sriq_s2(slop_arena* arena, slop_list_sroiq_SAxiom axs);
slop_string sriqnormal_render_dname(slop_arena* arena, sriqnormal_S2 s2, types_DName n);
slop_string sriqnormal_render_dfiller(slop_arena* arena, sriqnormal_S2 s2, slop_option_types_DName b);
slop_string sriqnormal_render_drole(slop_arena* arena, sriqnormal_S2 s2, types_DRole r);
slop_string sriqnormal_render_dnames(slop_arena* arena, sriqnormal_S2 s2, slop_list_types_DName ns, slop_string sep, slop_string empty);
slop_string sriqnormal_inclusion(slop_arena* arena, slop_string form, slop_string lhs, slop_string rhs);
slop_string sriqnormal_restriction_text(slop_arena* arena, slop_string op, slop_string role, slop_string filler);
slop_string sriqnormal_count_op(slop_arena* arena, slop_string op, int64_t n);
slop_string sriqnormal_braces(slop_arena* arena, rdf_IRI o);
slop_string sriqnormal_render_dl(slop_arena* arena, sriqnormal_S2 s2, types_DlClause c);

sroiq_SConcept* sriqnormal_sc(slop_arena* arena, sroiq_SConcept c) {
    return sroiq_box_sc(arena, c);
}

slop_result_list_sroiq_SConcept_string sriqnormal_s0_concepts(slop_arena* arena, slop_list_owl2_RawConcept cs) {
    {
        __auto_type out = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        slop_option_string fault = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                __auto_type _mv_1139 = sriqnormal_s0_concept(arena, c);
                if (_mv_1139.is_ok) {
                    __auto_type x = _mv_1139.data.ok;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1139.is_ok) {
                    __auto_type m = _mv_1139.data.err;
                    fault = (slop_option_string){.has_value = 1, .value = m};
                }
            }
        }
        __auto_type _mv_1140 = fault;
        if (_mv_1140.has_value) {
            __auto_type m = _mv_1140.value;
            return ((slop_result_list_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
        } else if (!_mv_1140.has_value) {
            return ((slop_result_list_sroiq_SConcept_string){ .is_ok = true, .data.ok = out });
        }
        SLOP_UNREACHABLE();
    }
}

slop_result_sroiq_SConcept_string sriqnormal_s0_filler(slop_arena* arena, owl2_RawConcept* f) {
    return sriqnormal_s0_concept(arena, (*f));
}

sroiq_SConcept sriqnormal_s0_count(slop_arena* arena, owl2_CardKind k, types_RoleId r, int64_t n, sroiq_SConcept f) {
    __auto_type _mv_1141 = k;
    if (_mv_1141 == owl2_CardKind_card_min) {
        return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atleast, .data.sc_atleast = { .f0 = n, .f1 = r, .f2 = sriqnormal_sc(arena, f) } });
    } else if (_mv_1141 == owl2_CardKind_card_max) {
        return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = n, .f1 = r, .f2 = sriqnormal_sc(arena, f) } });
    } else if (_mv_1141 == owl2_CardKind_card_exact) {
        {
            __auto_type both = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            ({ __auto_type _lst_p = &(both); __auto_type _item = (((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atleast, .data.sc_atleast = { .f0 = n, .f1 = r, .f2 = sriqnormal_sc(arena, f) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(both); __auto_type _item = (((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = n, .f1 = r, .f2 = sriqnormal_sc(arena, f) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_and, .data.sc_and = both });
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_sroiq_SConcept_string sriqnormal_s0_concept(slop_arena* arena, owl2_RawConcept c) {
    __auto_type _mv_1142 = c;
    switch (_mv_1142.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_1142.data.rc_name;
            __auto_type _mv_1143 = n;
            switch (_mv_1143.tag) {
                case types_Node_class_node:
                {
                    __auto_type i = _mv_1143.data.class_node;
                    return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_name, .data.sc_name = i }) });
                }
                case types_Node_individual_node:
                {
                    __auto_type _ = _mv_1143.data.individual_node;
                    return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = SLOP_STR("an individual in a class position") });
                }
                case types_Node_fresh_node:
                {
                    __auto_type _ = _mv_1143.data.fresh_node;
                    return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = SLOP_STR("a fresh node in a class position") });
                }
            }
            SLOP_UNREACHABLE();
        }
        case owl2_RawConcept_rc_thing:
        {
            return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_top }) });
        }
        case owl2_RawConcept_rc_nothing:
        {
            return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_bottom }) });
        }
        case owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_1142.data.rc_and;
            __auto_type _mv_1144 = sriqnormal_s0_concepts(arena, cs);
            if (_mv_1144.is_ok) {
                __auto_type xs = _mv_1144.data.ok;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_and, .data.sc_and = xs }) });
            } else if (!_mv_1144.is_ok) {
                __auto_type m = _mv_1144.data.err;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_1142.data.rc_or;
            __auto_type _mv_1145 = sriqnormal_s0_concepts(arena, cs);
            if (_mv_1145.is_ok) {
                __auto_type xs = _mv_1145.data.ok;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_or, .data.sc_or = xs }) });
            } else if (!_mv_1145.is_ok) {
                __auto_type m = _mv_1145.data.err;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_1142.data.rc_not;
            __auto_type _mv_1146 = sriqnormal_s0_filler(arena, f);
            if (_mv_1146.is_ok) {
                __auto_type x = _mv_1146.data.ok;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_not, .data.sc_not = sriqnormal_sc(arena, x) }) });
            } else if (!_mv_1146.is_ok) {
                __auto_type m = _mv_1146.data.err;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_1142.data.rc_some.f0;
            __auto_type f = _mv_1142.data.rc_some.f1;
            __auto_type _mv_1147 = sriqnormal_s0_filler(arena, f);
            if (_mv_1147.is_ok) {
                __auto_type x = _mv_1147.data.ok;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = sriqnormal_sc(arena, x) } }) });
            } else if (!_mv_1147.is_ok) {
                __auto_type m = _mv_1147.data.err;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case owl2_RawConcept_rc_all:
        {
            __auto_type r = _mv_1142.data.rc_all.f0;
            __auto_type f = _mv_1142.data.rc_all.f1;
            __auto_type _mv_1148 = sriqnormal_s0_filler(arena, f);
            if (_mv_1148.is_ok) {
                __auto_type x = _mv_1148.data.ok;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = sriqnormal_sc(arena, x) } }) });
            } else if (!_mv_1148.is_ok) {
                __auto_type m = _mv_1148.data.err;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case owl2_RawConcept_rc_card:
        {
            __auto_type k = _mv_1142.data.rc_card.f0;
            __auto_type r = _mv_1142.data.rc_card.f1;
            __auto_type n = _mv_1142.data.rc_card.f2;
            return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = sriqnormal_s0_count(arena, k, r, n, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_top })) });
        }
        case owl2_RawConcept_rc_qcard:
        {
            __auto_type k = _mv_1142.data.rc_qcard.f0;
            __auto_type r = _mv_1142.data.rc_qcard.f1;
            __auto_type n = _mv_1142.data.rc_qcard.f2;
            __auto_type f = _mv_1142.data.rc_qcard.f3;
            __auto_type _mv_1149 = sriqnormal_s0_filler(arena, f);
            if (_mv_1149.is_ok) {
                __auto_type x = _mv_1149.data.ok;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = sriqnormal_s0_count(arena, k, r, n, x) });
            } else if (!_mv_1149.is_ok) {
                __auto_type m = _mv_1149.data.err;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_1142.data.rc_has_self;
            return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_self, .data.sc_self = r }) });
        }
        case owl2_RawConcept_rc_oneof:
        {
            __auto_type _ = _mv_1142.data.rc_oneof;
            return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = SLOP_STR("ObjectOneOf, which the sriq gate does not admit") });
        }
        case owl2_RawConcept_rc_has_value:
        {
            return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = SLOP_STR("ObjectHasValue, which the sriq gate does not admit") });
        }
        case owl2_RawConcept_rc_data:
        {
            __auto_type _ = _mv_1142.data.rc_data;
            return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = SLOP_STR("a data range, which the sriq gate does not admit") });
        }
        case owl2_RawConcept_rc_anon:
        {
            __auto_type _ = _mv_1142.data.rc_anon;
            return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = SLOP_STR("an undecodable class, which the sriq gate does not admit") });
        }
    }
    SLOP_UNREACHABLE();
}

sroiq_SAxiom sriqnormal_gci(slop_arena* arena, sroiq_SConcept l, sroiq_SConcept r) {
    return ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_gci, .data.sa_gci = { .f0 = sriqnormal_sc(arena, l), .f1 = sriqnormal_sc(arena, r) } });
}

sroiq_SAxiom sriqnormal_ria(slop_arena* arena, slop_list_types_RoleId w, types_RoleId s) {
    return ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_ria, .data.sa_ria = ((sroiq_SRia){.word = w, .super = s}) });
}

sroiq_SAxiom sriqnormal_ria1(slop_arena* arena, types_RoleId r, types_RoleId s) {
    {
        __auto_type w = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(w); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return sriqnormal_ria(arena, w, s);
    }
}

slop_option_sroiq_SConcept sriqnormal_nominal(types_Node n) {
    __auto_type _mv_1150 = n;
    switch (_mv_1150.tag) {
        case types_Node_individual_node:
        {
            __auto_type i = _mv_1150.data.individual_node;
            return (slop_option_sroiq_SConcept){.has_value = 1, .value = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_nominal, .data.sc_nominal = i })};
        }
        case types_Node_class_node:
        {
            __auto_type _ = _mv_1150.data.class_node;
            return (slop_option_sroiq_SConcept){.has_value = false};
        }
        case types_Node_fresh_node:
        {
            __auto_type _ = _mv_1150.data.fresh_node;
            return (slop_option_sroiq_SConcept){.has_value = false};
        }
    }
    SLOP_UNREACHABLE();
}

slop_option_rdf_IRI sriqnormal_least_individual(slop_list_types_Node ns) {
    {
        slop_option_rdf_IRI best = (slop_option_rdf_IRI){.has_value = false};
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                __auto_type _mv_1151 = n;
                switch (_mv_1151.tag) {
                    case types_Node_individual_node:
                    {
                        __auto_type i = _mv_1151.data.individual_node;
                        __auto_type _mv_1152 = best;
                        if (!_mv_1152.has_value) {
                            best = (slop_option_rdf_IRI){.has_value = 1, .value = i};
                        } else if (_mv_1152.has_value) {
                            __auto_type b = _mv_1152.value;
                            if (canon_iri_cmp(i, b) < 0) {
                                best = (slop_option_rdf_IRI){.has_value = 1, .value = i};
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

sroiq_SConcept sriqnormal_top_sc(void) {
    return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_top });
}

slop_list_sroiq_SAxiom sriqnormal_one_axiom(slop_arena* arena, sroiq_SAxiom a) {
    {
        __auto_type xs = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return xs;
    }
}

slop_list_sroiq_SAxiom sriqnormal_two_axioms(slop_arena* arena, sroiq_SAxiom a, sroiq_SAxiom b) {
    {
        __auto_type xs = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return xs;
    }
}

sroiq_SAxiom sriqnormal_meet_empty(slop_arena* arena, sroiq_SConcept a, sroiq_SConcept b) {
    {
        __auto_type ab = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(ab); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(ab); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return sriqnormal_gci(arena, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_and, .data.sc_and = ab }), ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_bottom }));
    }
}

slop_list_sroiq_SAxiom sriqnormal_pairwise_disjoint(slop_arena* arena, slop_list_sroiq_SConcept xs) {
    {
        __auto_type out = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
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
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_meet_empty(arena, a, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

slop_list_sroiq_SAxiom sriqnormal_pairwise_dis(slop_arena* arena, slop_list_types_RoleId rs) {
    {
        __auto_type out = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
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
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_dis, .data.sa_dis = { .f0 = a, .f1 = b } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

slop_list_sroiq_SAxiom sriqnormal_mutual_gcis(slop_arena* arena, slop_list_sroiq_SConcept xs) {
    {
        __auto_type out = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    __auto_type _coll = xs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type b = _coll.data[_i];
                        if (sroiq_sc_cmp(a, b) != 0) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, a, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        return out;
    }
}

slop_list_sroiq_SAxiom sriqnormal_mutual_rias(slop_arena* arena, slop_list_types_RoleId rs) {
    {
        __auto_type out = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    __auto_type _coll = rs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type b = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_ria1(arena, a, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

slop_list_sroiq_SAxiom sriqnormal_around_hub(slop_arena* arena, sroiq_SConcept hub, slop_list_sroiq_SConcept xs) {
    {
        __auto_type out = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (sroiq_sc_cmp(x, hub) != 0) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, hub, x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, x, hub)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

slop_result_list_sroiq_SConcept_string sriqnormal_s0_nominals(slop_arena* arena, slop_list_types_Node ns, slop_string what) {
    {
        __auto_type out = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        slop_option_string fault = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                __auto_type _mv_1153 = sriqnormal_nominal(n);
                if (_mv_1153.has_value) {
                    __auto_type x = _mv_1153.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1153.has_value) {
                    fault = (slop_option_string){.has_value = 1, .value = string_concat(arena, what, SLOP_STR(" with a non-individual"))};
                }
            }
        }
        __auto_type _mv_1154 = fault;
        if (_mv_1154.has_value) {
            __auto_type m = _mv_1154.value;
            return ((slop_result_list_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
        } else if (!_mv_1154.has_value) {
            return ((slop_result_list_sroiq_SConcept_string){ .is_ok = true, .data.ok = out });
        }
        SLOP_UNREACHABLE();
    }
}

sroiq_SAxiom sriqnormal_transitivity(slop_arena* arena, types_RoleId r) {
    {
        __auto_type w = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(w); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(w); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return sriqnormal_ria(arena, w, r);
    }
}

sroiq_SAxiom sriqnormal_characteristic(slop_arena* arena, owl2_PropCharacteristic c, types_RoleId r) {
    __auto_type _mv_1155 = c;
    if (_mv_1155 == owl2_PropCharacteristic_prop_functional) {
        return sriqnormal_gci(arena, sriqnormal_top_sc(), ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = 1, .f1 = r, .f2 = sriqnormal_sc(arena, sriqnormal_top_sc()) } }));
    } else if (_mv_1155 == owl2_PropCharacteristic_prop_inverse_functional) {
        return sriqnormal_gci(arena, sriqnormal_top_sc(), ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = 1, .f1 = sroiq_inv_role(r), .f2 = sriqnormal_sc(arena, sriqnormal_top_sc()) } }));
    } else if (_mv_1155 == owl2_PropCharacteristic_prop_symmetric) {
        return sriqnormal_ria1(arena, sroiq_inv_role(r), r);
    } else if (_mv_1155 == owl2_PropCharacteristic_prop_asymmetric) {
        return ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_dis, .data.sa_dis = { .f0 = r, .f1 = sroiq_inv_role(r) } });
    } else if (_mv_1155 == owl2_PropCharacteristic_prop_reflexive) {
        return ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_ref, .data.sa_ref = r });
    } else if (_mv_1155 == owl2_PropCharacteristic_prop_irreflexive) {
        return ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_irr, .data.sa_irr = r });
    }
    SLOP_UNREACHABLE();
}

slop_result_list_sroiq_SAxiom_string sriqnormal_s0_sub_class(slop_arena* arena, owl2_RawConcept* l, owl2_RawConcept* r) {
    __auto_type _mv_1156 = sriqnormal_s0_filler(arena, l);
    if (!_mv_1156.is_ok) {
        __auto_type m = _mv_1156.data.err;
        return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_1156.is_ok) {
        __auto_type lx = _mv_1156.data.ok;
        __auto_type _mv_1157 = sriqnormal_s0_filler(arena, r);
        if (!_mv_1157.is_ok) {
            __auto_type m = _mv_1157.data.err;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
        } else if (_mv_1157.is_ok) {
            __auto_type rx = _mv_1157.data.ok;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = sriqnormal_one_axiom(arena, sriqnormal_gci(arena, lx, rx)) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_list_sroiq_SAxiom_string sriqnormal_s0_equivalent_classes(slop_arena* arena, slop_list_owl2_RawConcept cs) {
    __auto_type _mv_1158 = sriqnormal_s0_concepts(arena, cs);
    if (!_mv_1158.is_ok) {
        __auto_type m = _mv_1158.data.err;
        return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_1158.is_ok) {
        __auto_type xs = _mv_1158.data.ok;
        return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = sriqnormal_mutual_gcis(arena, xs) });
    }
    SLOP_UNREACHABLE();
}

slop_result_list_sroiq_SAxiom_string sriqnormal_s0_disjoint_classes(slop_arena* arena, slop_list_owl2_RawConcept cs) {
    __auto_type _mv_1159 = sriqnormal_s0_concepts(arena, cs);
    if (!_mv_1159.is_ok) {
        __auto_type m = _mv_1159.data.err;
        return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_1159.is_ok) {
        __auto_type xs = _mv_1159.data.ok;
        return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = sriqnormal_pairwise_disjoint(arena, xs) });
    }
    SLOP_UNREACHABLE();
}

slop_result_list_sroiq_SAxiom_string sriqnormal_s0_domain(slop_arena* arena, types_RoleId r, owl2_RawConcept* c) {
    __auto_type _mv_1160 = sriqnormal_s0_filler(arena, c);
    if (!_mv_1160.is_ok) {
        __auto_type m = _mv_1160.data.err;
        return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_1160.is_ok) {
        __auto_type cx = _mv_1160.data.ok;
        return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = sriqnormal_one_axiom(arena, sriqnormal_gci(arena, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = sriqnormal_sc(arena, sriqnormal_top_sc()) } }), cx)) });
    }
    SLOP_UNREACHABLE();
}

slop_result_list_sroiq_SAxiom_string sriqnormal_s0_range(slop_arena* arena, types_RoleId r, owl2_RawConcept* c) {
    __auto_type _mv_1161 = sriqnormal_s0_filler(arena, c);
    if (!_mv_1161.is_ok) {
        __auto_type m = _mv_1161.data.err;
        return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_1161.is_ok) {
        __auto_type cx = _mv_1161.data.ok;
        return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = sriqnormal_one_axiom(arena, sriqnormal_gci(arena, sriqnormal_top_sc(), ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = sriqnormal_sc(arena, cx) } }))) });
    }
    SLOP_UNREACHABLE();
}

slop_result_list_sroiq_SAxiom_string sriqnormal_s0_class_assertion(slop_arena* arena, owl2_RawClassAssertion ca) {
    __auto_type _mv_1162 = sriqnormal_nominal(ca.subject);
    if (!_mv_1162.has_value) {
        return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("a class assertion on a non-individual") });
    } else if (_mv_1162.has_value) {
        __auto_type a = _mv_1162.value;
        __auto_type _mv_1163 = sriqnormal_s0_filler(arena, ca.concept);
        if (!_mv_1163.is_ok) {
            __auto_type m = _mv_1163.data.err;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
        } else if (_mv_1163.is_ok) {
            __auto_type cx = _mv_1163.data.ok;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = sriqnormal_one_axiom(arena, sriqnormal_gci(arena, a, cx)) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

sroiq_SConcept sriqnormal_edge_filler(slop_arena* arena, types_RoleId r, sroiq_SConcept b, uint8_t negative) {
    if (negative) {
        return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = sriqnormal_sc(arena, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_not, .data.sc_not = sriqnormal_sc(arena, b) })) } });
    } else {
        return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = sriqnormal_sc(arena, b) } });
    }
}

slop_result_list_sroiq_SAxiom_string sriqnormal_s0_assertion(slop_arena* arena, owl2_RawEdge e, slop_string what, uint8_t negative) {
    __auto_type _mv_1164 = sriqnormal_nominal(e.from);
    if (!_mv_1164.has_value) {
        return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = string_concat(arena, what, SLOP_STR(" from a non-individual")) });
    } else if (_mv_1164.has_value) {
        __auto_type a = _mv_1164.value;
        __auto_type _mv_1165 = sriqnormal_nominal(e.to);
        if (!_mv_1165.has_value) {
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = string_concat(arena, what, SLOP_STR(" to a non-individual")) });
        } else if (_mv_1165.has_value) {
            __auto_type b = _mv_1165.value;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = sriqnormal_one_axiom(arena, sriqnormal_gci(arena, a, sriqnormal_edge_filler(arena, e.role, b, negative))) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_list_sroiq_SAxiom_string sriqnormal_s0_same_individual(slop_arena* arena, slop_list_types_Node ns) {
    __auto_type _mv_1166 = sriqnormal_least_individual(ns);
    if (!_mv_1166.has_value) {
        return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("SameIndividual without an individual") });
    } else if (_mv_1166.has_value) {
        __auto_type h = _mv_1166.value;
        __auto_type _mv_1167 = sriqnormal_s0_nominals(arena, ns, SLOP_STR("SameIndividual"));
        if (!_mv_1167.is_ok) {
            __auto_type m = _mv_1167.data.err;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
        } else if (_mv_1167.is_ok) {
            __auto_type xs = _mv_1167.data.ok;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = sriqnormal_around_hub(arena, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_nominal, .data.sc_nominal = h }), xs) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_list_sroiq_SAxiom_string sriqnormal_s0_different_individuals(slop_arena* arena, slop_list_types_Node ns) {
    __auto_type _mv_1168 = sriqnormal_s0_nominals(arena, ns, SLOP_STR("DifferentIndividuals"));
    if (!_mv_1168.is_ok) {
        __auto_type m = _mv_1168.data.err;
        return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_1168.is_ok) {
        __auto_type xs = _mv_1168.data.ok;
        return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = sriqnormal_pairwise_disjoint(arena, xs) });
    }
    SLOP_UNREACHABLE();
}

slop_result_list_sroiq_SAxiom_string sriqnormal_s0_disjoint_union(slop_arena* arena, owl2_RawDisjointUnion du) {
    __auto_type _mv_1169 = sriqnormal_s0_concepts(arena, du.members);
    if (!_mv_1169.is_ok) {
        __auto_type m = _mv_1169.data.err;
        return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
    } else if (_mv_1169.is_ok) {
        __auto_type xs = _mv_1169.data.ok;
        {
            __auto_type c = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_name, .data.sc_name = du.class });
            __auto_type uni = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_or, .data.sc_or = xs });
            __auto_type out = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, c, uni)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, uni, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            {
                __auto_type _coll = sriqnormal_pairwise_disjoint(arena, xs);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = out });
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_list_sroiq_SAxiom_string sriqnormal_s0_axiom(slop_arena* arena, owl2_RawAxiom ax) {
    __auto_type _mv_1170 = ax;
    switch (_mv_1170.tag) {
        case owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_1170.data.ra_sub_class_of.f0;
            __auto_type r = _mv_1170.data.ra_sub_class_of.f1;
            return sriqnormal_s0_sub_class(arena, l, r);
        }
        case owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type cs = _mv_1170.data.ra_equivalent_classes;
            return sriqnormal_s0_equivalent_classes(arena, cs);
        }
        case owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_1170.data.ra_disjoint_classes;
            return sriqnormal_s0_disjoint_classes(arena, cs);
        }
        case owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type a = _mv_1170.data.ra_sub_object_property.f0;
            __auto_type b = _mv_1170.data.ra_sub_object_property.f1;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = sriqnormal_one_axiom(arena, sriqnormal_ria1(arena, a, b)) });
        }
        case owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_1170.data.ra_property_chain;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = sriqnormal_one_axiom(arena, sriqnormal_ria(arena, ch.steps, ch.super)) });
        }
        case owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type rs = _mv_1170.data.ra_equivalent_properties;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = sriqnormal_mutual_rias(arena, rs) });
        }
        case owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type r = _mv_1170.data.ra_transitive_property;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = sriqnormal_one_axiom(arena, sriqnormal_transitivity(arena, r)) });
        }
        case owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_1170.data.ra_object_property_domain.f0;
            __auto_type c = _mv_1170.data.ra_object_property_domain.f1;
            return sriqnormal_s0_domain(arena, r, c);
        }
        case owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type r = _mv_1170.data.ra_object_property_range.f0;
            __auto_type c = _mv_1170.data.ra_object_property_range.f1;
            return sriqnormal_s0_range(arena, r, c);
        }
        case owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_1170.data.ra_class_assertion;
            return sriqnormal_s0_class_assertion(arena, ca);
        }
        case owl2_RawAxiom_ra_object_property_assertion:
        {
            __auto_type e = _mv_1170.data.ra_object_property_assertion;
            return sriqnormal_s0_assertion(arena, e, SLOP_STR("a property assertion"), 0);
        }
        case owl2_RawAxiom_ra_negative_assertion:
        {
            __auto_type e = _mv_1170.data.ra_negative_assertion;
            return sriqnormal_s0_assertion(arena, e, SLOP_STR("a negative assertion"), 1);
        }
        case owl2_RawAxiom_ra_inverse_properties:
        {
            __auto_type a = _mv_1170.data.ra_inverse_properties.f0;
            __auto_type b = _mv_1170.data.ra_inverse_properties.f1;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = sriqnormal_two_axioms(arena, sriqnormal_ria1(arena, a, sroiq_inv_role(b)), sriqnormal_ria1(arena, sroiq_inv_role(b), a)) });
        }
        case owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type c = _mv_1170.data.ra_property_characteristic.f0;
            __auto_type r = _mv_1170.data.ra_property_characteristic.f1;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = sriqnormal_one_axiom(arena, sriqnormal_characteristic(arena, c, r)) });
        }
        case owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type rs = _mv_1170.data.ra_disjoint_properties;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = sriqnormal_pairwise_dis(arena, rs) });
        }
        case owl2_RawAxiom_ra_same_individual:
        {
            __auto_type ns = _mv_1170.data.ra_same_individual;
            return sriqnormal_s0_same_individual(arena, ns);
        }
        case owl2_RawAxiom_ra_different_individuals:
        {
            __auto_type ns = _mv_1170.data.ra_different_individuals;
            return sriqnormal_s0_different_individuals(arena, ns);
        }
        case owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type du = _mv_1170.data.ra_disjoint_union;
            return sriqnormal_s0_disjoint_union(arena, du);
        }
        case owl2_RawAxiom_ra_declaration:
        {
            __auto_type _ = _mv_1170.data.ra_declaration;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("a declaration reached the normaliser") });
        }
        case owl2_RawAxiom_ra_annotation:
        {
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("an annotation reached the normaliser") });
        }
        case owl2_RawAxiom_ra_inert_data:
        {
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("an inert data axiom reached the normaliser") });
        }
        case owl2_RawAxiom_ra_has_key:
        {
            __auto_type _ = _mv_1170.data.ra_has_key;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("HasKey, which the sriq gate does not admit") });
        }
        case owl2_RawAxiom_ra_data_axiom:
        {
            __auto_type _ = _mv_1170.data.ra_data_axiom;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("a data axiom, which the sriq gate does not admit") });
        }
        case owl2_RawAxiom_ra_builtin_role:
        {
            __auto_type _ = _mv_1170.data.ra_builtin_role;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("a built-in role axiom, which the sriq gate does not admit") });
        }
        case owl2_RawAxiom_ra_anonymous_individual:
        {
            __auto_type _ = _mv_1170.data.ra_anonymous_individual;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("an anonymous individual, which the sriq gate does not admit") });
        }
        case owl2_RawAxiom_ra_reserved_vocabulary:
        {
            __auto_type _ = _mv_1170.data.ra_reserved_vocabulary;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("reserved vocabulary, which the sriq gate does not admit") });
        }
        case owl2_RawAxiom_ra_swrl_rule:
        {
            __auto_type _ = _mv_1170.data.ra_swrl_rule;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("a SWRL rule, which the sriq gate does not admit") });
        }
        case owl2_RawAxiom_ra_unrecognized:
        {
            __auto_type _ = _mv_1170.data.ra_unrecognized;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = SLOP_STR("an unrecognized axiom, which the sriq gate does not admit") });
        }
    }
    SLOP_UNREACHABLE();
}

int64_t sriqnormal_rep_at(sriqrbox_SriqRbox rb, int64_t n) {
    __auto_type _mv_1171 = ({ __auto_type _lst = rb.rep; size_t _idx = (size_t)n; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1171.has_value) {
        __auto_type v = _mv_1171.value;
        return v;
    } else if (!_mv_1171.has_value) {
        return n;
    }
    SLOP_UNREACHABLE();
}

types_RoleId sriqnormal_collapse_role(sriqrbox_SriqRbox rb, types_RoleId r) {
    {
        __auto_type n = sriqrbox_sriq_node(rb.props, r);
        if (n < 0) {
            return r;
        } else {
            return sriqrbox_node_role(rb.props, sriqnormal_rep_at(rb, n));
        }
    }
}

slop_list_types_RoleId sriqnormal_collapse_word(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_types_RoleId w) {
    {
        __auto_type out = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = w;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_collapse_role(rb, r)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_sroiq_SConcept sriqnormal_collapse_concepts(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_sroiq_SConcept cs) {
    {
        __auto_type out = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_collapse_concept(arena, rb, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

sroiq_SConcept sriqnormal_collapse_concept(slop_arena* arena, sriqrbox_SriqRbox rb, sroiq_SConcept c) {
    __auto_type _mv_1172 = c;
    switch (_mv_1172.tag) {
        case sroiq_SConcept_sc_top:
        {
            return c;
        }
        case sroiq_SConcept_sc_bottom:
        {
            return c;
        }
        case sroiq_SConcept_sc_name:
        {
            __auto_type _ = _mv_1172.data.sc_name;
            return c;
        }
        case sroiq_SConcept_sc_nominal:
        {
            __auto_type _ = _mv_1172.data.sc_nominal;
            return c;
        }
        case sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_1172.data.sc_not;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_not, .data.sc_not = sriqnormal_sc(arena, sriqnormal_collapse_concept(arena, rb, (*f))) });
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_1172.data.sc_and;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_and, .data.sc_and = sriqnormal_collapse_concepts(arena, rb, xs) });
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_1172.data.sc_or;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_or, .data.sc_or = sriqnormal_collapse_concepts(arena, rb, xs) });
        }
        case sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_1172.data.sc_some.f0;
            __auto_type f = _mv_1172.data.sc_some.f1;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_some, .data.sc_some = { .f0 = sriqnormal_collapse_role(rb, r), .f1 = sriqnormal_sc(arena, sriqnormal_collapse_concept(arena, rb, (*f))) } });
        }
        case sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_1172.data.sc_all.f0;
            __auto_type f = _mv_1172.data.sc_all.f1;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = sriqnormal_collapse_role(rb, r), .f1 = sriqnormal_sc(arena, sriqnormal_collapse_concept(arena, rb, (*f))) } });
        }
        case sroiq_SConcept_sc_atleast:
        {
            __auto_type n = _mv_1172.data.sc_atleast.f0;
            __auto_type r = _mv_1172.data.sc_atleast.f1;
            __auto_type f = _mv_1172.data.sc_atleast.f2;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atleast, .data.sc_atleast = { .f0 = n, .f1 = sriqnormal_collapse_role(rb, r), .f2 = sriqnormal_sc(arena, sriqnormal_collapse_concept(arena, rb, (*f))) } });
        }
        case sroiq_SConcept_sc_atmost:
        {
            __auto_type n = _mv_1172.data.sc_atmost.f0;
            __auto_type r = _mv_1172.data.sc_atmost.f1;
            __auto_type f = _mv_1172.data.sc_atmost.f2;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = n, .f1 = sriqnormal_collapse_role(rb, r), .f2 = sriqnormal_sc(arena, sriqnormal_collapse_concept(arena, rb, (*f))) } });
        }
        case sroiq_SConcept_sc_self:
        {
            __auto_type r = _mv_1172.data.sc_self;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_self, .data.sc_self = sriqnormal_collapse_role(rb, r) });
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqnormal_trivial_ria(slop_list_types_RoleId w, types_RoleId s) {
    return ((((int64_t)((w).len)) == 1) && ({ __auto_type _mv = ({ __auto_type _lst = w; size_t _idx = (size_t)0; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type r = _mv.value; sriqnormal_role_eq_p(r, s); }) : (0); }));
}

uint8_t sriqnormal_role_eq_p(types_RoleId a, types_RoleId b) {
    __auto_type _mv_1173 = a;
    switch (_mv_1173.tag) {
        case types_RoleId_named_role:
        {
            __auto_type ia = _mv_1173.data.named_role;
            __auto_type _mv_1174 = b;
            switch (_mv_1174.tag) {
                case types_RoleId_named_role:
                {
                    __auto_type ib = _mv_1174.data.named_role;
                    return (canon_string_cmp(ia.value, ib.value) == 0);
                }
                default: {
                    return 0;
                }
            }
        }
        case types_RoleId_inverse_role:
        {
            __auto_type ia = _mv_1173.data.inverse_role;
            __auto_type _mv_1175 = b;
            switch (_mv_1175.tag) {
                case types_RoleId_inverse_role:
                {
                    __auto_type ib = _mv_1175.data.inverse_role;
                    return (canon_string_cmp(ia.value, ib.value) == 0);
                }
                default: {
                    return 0;
                }
            }
        }
        case types_RoleId_fresh_role:
        {
            __auto_type ka = _mv_1173.data.fresh_role;
            __auto_type _mv_1176 = b;
            switch (_mv_1176.tag) {
                case types_RoleId_fresh_role:
                {
                    __auto_type kb = _mv_1176.data.fresh_role;
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

slop_option_sroiq_SAxiom sriqnormal_collapse_axiom(slop_arena* arena, sriqrbox_SriqRbox rb, sroiq_SAxiom a) {
    __auto_type _mv_1177 = a;
    switch (_mv_1177.tag) {
        case sroiq_SAxiom_sa_gci:
        {
            __auto_type l = _mv_1177.data.sa_gci.f0;
            __auto_type r = _mv_1177.data.sa_gci.f1;
            return (slop_option_sroiq_SAxiom){.has_value = 1, .value = ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_gci, .data.sa_gci = { .f0 = sriqnormal_sc(arena, sroiq_sc_canon(arena, sriqnormal_collapse_concept(arena, rb, (*l)))), .f1 = sriqnormal_sc(arena, sroiq_sc_canon(arena, sriqnormal_collapse_concept(arena, rb, (*r)))) } })};
        }
        case sroiq_SAxiom_sa_ria:
        {
            __auto_type x = _mv_1177.data.sa_ria;
            {
                __auto_type w = sriqnormal_collapse_word(arena, rb, x.word);
                __auto_type s = sriqnormal_collapse_role(rb, x.super);
                if (sriqnormal_trivial_ria(w, s)) {
                    return (slop_option_sroiq_SAxiom){.has_value = false};
                } else {
                    return (slop_option_sroiq_SAxiom){.has_value = 1, .value = sriqnormal_ria(arena, w, s)};
                }
            }
        }
        case sroiq_SAxiom_sa_ref:
        {
            __auto_type r = _mv_1177.data.sa_ref;
            return (slop_option_sroiq_SAxiom){.has_value = 1, .value = ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_ref, .data.sa_ref = sriqnormal_collapse_role(rb, r) })};
        }
        case sroiq_SAxiom_sa_irr:
        {
            __auto_type r = _mv_1177.data.sa_irr;
            return (slop_option_sroiq_SAxiom){.has_value = 1, .value = ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_irr, .data.sa_irr = sriqnormal_collapse_role(rb, r) })};
        }
        case sroiq_SAxiom_sa_dis:
        {
            __auto_type r = _mv_1177.data.sa_dis.f0;
            __auto_type s = _mv_1177.data.sa_dis.f1;
            return (slop_option_sroiq_SAxiom){.has_value = 1, .value = ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_dis, .data.sa_dis = { .f0 = sriqnormal_collapse_role(rb, r), .f1 = sriqnormal_collapse_role(rb, s) } })};
        }
    }
    SLOP_UNREACHABLE();
}

types_RoleId sriqnormal_bottom_role(void) {
    return ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = ((rdf_IRI){.value = vocab_OWL_BOTTOM_OBJECT_PROPERTY}) });
}

uint8_t sriqnormal_is_bottom(types_RoleId r) {
    __auto_type _mv_1178 = r;
    switch (_mv_1178.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_1178.data.named_role;
            return (canon_string_cmp(i.value, vocab_OWL_BOTTOM_OBJECT_PROPERTY) == 0);
        }
        case types_RoleId_inverse_role:
        {
            __auto_type i = _mv_1178.data.inverse_role;
            return (canon_string_cmp(i.value, vocab_OWL_BOTTOM_OBJECT_PROPERTY) == 0);
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_1178.data.fresh_role;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqnormal_concept_bottom_p(sroiq_SConcept c) {
    __auto_type _mv_1179 = c;
    switch (_mv_1179.tag) {
        case sroiq_SConcept_sc_top:
        {
            return 0;
        }
        case sroiq_SConcept_sc_bottom:
        {
            return 0;
        }
        case sroiq_SConcept_sc_name:
        {
            __auto_type _ = _mv_1179.data.sc_name;
            return 0;
        }
        case sroiq_SConcept_sc_nominal:
        {
            __auto_type _ = _mv_1179.data.sc_nominal;
            return 0;
        }
        case sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_1179.data.sc_not;
            return sriqnormal_concept_bottom_p((*f));
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_1179.data.sc_and;
            return sriqnormal_concepts_bottom_p(xs);
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_1179.data.sc_or;
            return sriqnormal_concepts_bottom_p(xs);
        }
        case sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_1179.data.sc_some.f0;
            __auto_type f = _mv_1179.data.sc_some.f1;
            return (sriqnormal_is_bottom(r) || sriqnormal_concept_bottom_p((*f)));
        }
        case sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_1179.data.sc_all.f0;
            __auto_type f = _mv_1179.data.sc_all.f1;
            return (sriqnormal_is_bottom(r) || sriqnormal_concept_bottom_p((*f)));
        }
        case sroiq_SConcept_sc_atleast:
        {
            __auto_type r = _mv_1179.data.sc_atleast.f1;
            __auto_type f = _mv_1179.data.sc_atleast.f2;
            return (sriqnormal_is_bottom(r) || sriqnormal_concept_bottom_p((*f)));
        }
        case sroiq_SConcept_sc_atmost:
        {
            __auto_type r = _mv_1179.data.sc_atmost.f1;
            __auto_type f = _mv_1179.data.sc_atmost.f2;
            return (sriqnormal_is_bottom(r) || sriqnormal_concept_bottom_p((*f)));
        }
        case sroiq_SConcept_sc_self:
        {
            __auto_type r = _mv_1179.data.sc_self;
            return sriqnormal_is_bottom(r);
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqnormal_concepts_bottom_p(slop_list_sroiq_SConcept cs) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (sriqnormal_concept_bottom_p(c)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t sriqnormal_axiom_bottom_p(sroiq_SAxiom a) {
    __auto_type _mv_1180 = a;
    switch (_mv_1180.tag) {
        case sroiq_SAxiom_sa_gci:
        {
            __auto_type l = _mv_1180.data.sa_gci.f0;
            __auto_type r = _mv_1180.data.sa_gci.f1;
            return (sriqnormal_concept_bottom_p((*l)) || sriqnormal_concept_bottom_p((*r)));
        }
        case sroiq_SAxiom_sa_ria:
        {
            __auto_type x = _mv_1180.data.sa_ria;
            {
                uint8_t found = sriqnormal_is_bottom(x.super);
                {
                    __auto_type _coll = x.word;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        if (sriqnormal_is_bottom(r)) {
                            found = 1;
                        }
                    }
                }
                return found;
            }
        }
        case sroiq_SAxiom_sa_ref:
        {
            __auto_type r = _mv_1180.data.sa_ref;
            return sriqnormal_is_bottom(r);
        }
        case sroiq_SAxiom_sa_irr:
        {
            __auto_type r = _mv_1180.data.sa_irr;
            return sriqnormal_is_bottom(r);
        }
        case sroiq_SAxiom_sa_dis:
        {
            __auto_type r = _mv_1180.data.sa_dis.f0;
            __auto_type s = _mv_1180.data.sa_dis.f1;
            return (sriqnormal_is_bottom(r) || sriqnormal_is_bottom(s));
        }
    }
    SLOP_UNREACHABLE();
}

slop_result_sriqnormal_S0_string sriqnormal_sriq_s0(slop_arena* arena, slop_list_owl2_RawAxiom accepted) {
    {
        __auto_type rb = sriqrbox_sriq_rbox(arena, accepted);
        __auto_type raw = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type out = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t bottom = 0;
        slop_option_string fault = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = accepted;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1181 = sriqnormal_s0_axiom(arena, ax);
                if (!_mv_1181.is_ok) {
                    __auto_type m = _mv_1181.data.err;
                    fault = (slop_option_string){.has_value = 1, .value = m};
                } else if (_mv_1181.is_ok) {
                    __auto_type xs = _mv_1181.data.ok;
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
                if (sriqnormal_axiom_bottom_p(a)) {
                    bottom = 1;
                }
                __auto_type _mv_1182 = sriqnormal_collapse_axiom(arena, rb, a);
                if (_mv_1182.has_value) {
                    __auto_type c = _mv_1182.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1182.has_value) {
                }
            }
        }
        {
            __auto_type k = ((int64_t)(((int64_t)((rb.props).len))));
            int64_t i = 0;
            while (i < k) {
                if ((sriqnormal_rep_at(rb, (2 * i)) == (2 * i)) && (sriqnormal_rep_at(rb, ((2 * i) + 1)) == (2 * i))) {
                    {
                        __auto_type p = sriqrbox_node_role(rb.props, (2 * i));
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_ria1(arena, sroiq_inv_role(p), p)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                i = (i + 1);
            }
        }
        if (bottom) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_some, .data.sc_some = { .f0 = sriqnormal_collapse_role(rb, sriqnormal_bottom_role()), .f1 = sriqnormal_sc(arena, sriqnormal_top_sc()) } }), ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_bottom }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        __auto_type _mv_1183 = fault;
        if (_mv_1183.has_value) {
            __auto_type m = _mv_1183.value;
            return ((slop_result_sriqnormal_S0_string){ .is_ok = false, .data.err = m });
        } else if (!_mv_1183.has_value) {
            return ((slop_result_sriqnormal_S0_string){ .is_ok = true, .data.ok = ((sriqnormal_S0){.axioms = sroiq_dedupe_saxioms(arena, sroiq_sort_saxioms(arena, out)), .rbox = rb}) });
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t sriqnormal_ria_complex(sriqrbox_SriqRbox rb, sroiq_SRia x) {
    if (((int64_t)((x.word).len)) > 1) {
        return 1;
    } else {
        {
            __auto_type n = sriqrbox_sriq_node(rb.props, x.super);
            if (n < 0) {
                return 0;
            } else {
                __auto_type _mv_1184 = ({ __auto_type _lst = rb.nonsimple; size_t _idx = (size_t)n; slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1184.has_value) {
                    __auto_type v = _mv_1184.value;
                    return v;
                } else if (!_mv_1184.has_value) {
                    return 0;
                }
                SLOP_UNREACHABLE();
            }
        }
    }
}

slop_result_list_sroiq_SAxiom_string sriqnormal_sriq_s1(slop_arena* arena, sriqnormal_S0 s0) {
    {
        slop_option_sroiq_SAxiom first = (slop_option_sroiq_SAxiom){.has_value = false};
        {
            __auto_type _coll = s0.axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_1185 = a;
                switch (_mv_1185.tag) {
                    case sroiq_SAxiom_sa_ria:
                    {
                        __auto_type x = _mv_1185.data.sa_ria;
                        if (sriqnormal_ria_complex(s0.rbox, x) && ({ __auto_type _mv = first; _mv.has_value ? ({ __auto_type _ = _mv.value; 0; }) : (1); })) {
                            first = (slop_option_sroiq_SAxiom){.has_value = 1, .value = a};
                        }
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        __auto_type _mv_1186 = first;
        if (!_mv_1186.has_value) {
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = s0.axioms });
        } else if (_mv_1186.has_value) {
            __auto_type a = _mv_1186.value;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = string_concat(arena, SLOP_STR("complex role inclusions need chain elimination (SPEC 5.5 S1), not yet built; first: "), sroiq_render_saxiom(arena, a)) });
        }
        SLOP_UNREACHABLE();
    }
}

sriqnormal_S2State* sriqnormal_new_s2(slop_arena* arena) {
    {
        __auto_type p = ((sriqnormal_S2State*)(({ __auto_type _alloc = (sriqnormal_S2State*)slop_arena_alloc(arena, sizeof(sriqnormal_S2State)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = ((sriqnormal_S2State){.out = ((slop_list_types_DlClause){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .registry = naming_new_registry(arena), .concepts = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .sroles = ((slop_list_types_DRole){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .sfills = ((slop_list_option_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .bars = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .barset = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .fnkeys = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .fnindex = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); })});
        return p;
    }
}

uint8_t sriqnormal_emit(slop_arena* arena, sriqnormal_S2State* p, types_DlClause c) {
    {
        __auto_type s = (*p);
        ({ __auto_type _lst_p = &(s.out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        (*p) = s;
        return 1;
    }
}

int64_t sriqnormal_fresh_name(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept c) {
    {
        __auto_type id = naming_fresh_id(arena, (*p).registry, sroiq_sc_key(arena, c));
        if (((int64_t)(id)) == ((int64_t)(((int64_t)(((*p).concepts).len))))) {
            {
                __auto_type s = (*p);
                ({ __auto_type _lst_p = &(s.concepts); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                (*p) = s;
            }
        }
        return SLOP_RANGE(int64_t, id, 1, 0, 0, 0, "(Int 0 ..) at sriqnormal.slop:769:9");
    }
}

sroiq_SConcept sriqnormal_concept_of(sriqnormal_S2State* p, int64_t k) {
    __auto_type _mv_1187 = ({ __auto_type _lst = (*p).concepts; size_t _idx = (size_t)k; slop_option_sroiq_SConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1187.has_value) {
        __auto_type c = _mv_1187.value;
        return c;
    } else if (!_mv_1187.has_value) {
        return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_top });
    }
    SLOP_UNREACHABLE();
}

types_DRole sriqnormal_role_name(slop_arena* arena, sriqnormal_S2State* p, types_RoleId r) {
    __auto_type _mv_1188 = r;
    switch (_mv_1188.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_1188.data.named_role;
            return ((types_DRole){ .tag = types_DRole_dr_prop, .data.dr_prop = i });
        }
        case types_RoleId_inverse_role:
        {
            __auto_type i = _mv_1188.data.inverse_role;
            if (!(slop_map_has((*p).barset, &(i.value)))) {
                {
                    __auto_type s = (*p);
                    ({ slop_map_put(NULL, s.barset, &(i.value), NULL, 0); });
                    ({ __auto_type _lst_p = &(s.bars); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    (*p) = s;
                }
            }
            return ((types_DRole){ .tag = types_DRole_dr_bar, .data.dr_bar = i });
        }
        case types_RoleId_fresh_role:
        {
            __auto_type k = _mv_1188.data.fresh_role;
            return ((types_DRole){ .tag = types_DRole_dr_sub, .data.dr_sub = k });
        }
    }
    SLOP_UNREACHABLE();
}

slop_string sriqnormal_dname_key(slop_arena* arena, sriqnormal_S2State* p, types_DName n) {
    __auto_type _mv_1191 = n;
    switch (_mv_1191.tag) {
        case types_DName_dn_class:
        {
            __auto_type i = _mv_1191.data.dn_class;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">")));
        }
        case types_DName_dn_fresh:
        {
            __auto_type k = _mv_1191.data.dn_fresh;
            return string_concat(arena, SLOP_STR("["), string_concat(arena, sroiq_sc_key(arena, sriqnormal_concept_of(p, k)), SLOP_STR("]")));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string sriqnormal_filler_key(slop_arena* arena, sriqnormal_S2State* p, slop_option_types_DName b) {
    __auto_type _mv_1192 = b;
    if (_mv_1192.has_value) {
        __auto_type n = _mv_1192.value;
        return sriqnormal_dname_key(arena, p, n);
    } else if (!_mv_1192.has_value) {
        return SLOP_STR("T");
    }
    SLOP_UNREACHABLE();
}

slop_string sriqnormal_drole_key(slop_arena* arena, sriqnormal_S2State* p, types_DRole r) {
    __auto_type _mv_1193 = r;
    switch (_mv_1193.tag) {
        case types_DRole_dr_prop:
        {
            __auto_type i = _mv_1193.data.dr_prop;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">")));
        }
        case types_DRole_dr_bar:
        {
            __auto_type i = _mv_1193.data.dr_bar;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">bar")));
        }
        case types_DRole_dr_sub:
        {
            __auto_type k = _mv_1193.data.dr_sub;
            return sriqnormal_srole_key(arena, p, ({ __auto_type _mv = ({ __auto_type _lst = (*p).sroles; size_t _idx = (size_t)k; slop_option_types_DRole _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : (r); }), ({ __auto_type _mv = ({ __auto_type _lst = (*p).sfills; size_t _idx = (size_t)k; slop_option_option_types_DName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : ((slop_option_types_DName){.has_value = false}); }));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string sriqnormal_key_of(slop_arena* arena, slop_string tag, slop_list_string parts) {
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

slop_string sriqnormal_srole_key(slop_arena* arena, sriqnormal_S2State* p, types_DRole s, slop_option_types_DName b) {
    {
        __auto_type parts = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(parts); __auto_type _item = (sriqnormal_drole_key(arena, p, s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(parts); __auto_type _item = (sriqnormal_filler_key(arena, p, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return sriqnormal_key_of(arena, SLOP_STR("S"), parts);
    }
}

types_DRole sriqnormal_srole_of(slop_arena* arena, sriqnormal_S2State* p, types_DRole s, slop_option_types_DName b) {
    {
        __auto_type id = naming_fresh_role_id(arena, (*p).registry, sriqnormal_srole_key(arena, p, s, b));
        if (((int64_t)(id)) == ((int64_t)(((int64_t)(((*p).sroles).len))))) {
            {
                __auto_type st = (*p);
                ({ __auto_type _lst_p = &(st.sroles); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(st.sfills); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                (*p) = st;
            }
        }
        return ((types_DRole){ .tag = types_DRole_dr_sub, .data.dr_sub = id });
    }
}

int64_t sriqnormal_fn_id(slop_arena* arena, sriqnormal_S2State* p, slop_string key) {
    __auto_type _mv_1195 = ({ void* _ptr = slop_map_get((*p).fnindex, &(key)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
    if (_mv_1195.has_value) {
        __auto_type id = _mv_1195.value;
        return ((int64_t)(id));
    } else if (!_mv_1195.has_value) {
        {
            __auto_type s = (*p);
            __auto_type id = ((int64_t)(SLOP_RANGE(int64_t, ((int64_t)(((*p).fnkeys).len)), 1, 0, 0, 0, "(Int 0 ..) at sriqnormal.slop:859:36")));
            ({ __auto_type _lst_p = &(s.fnkeys); __auto_type _item = (key); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ int64_t _val = SLOP_RANGE(int64_t, id, 1, 0, 0, 0, "(Int 0 ..) at sriqnormal.slop:862:40"); slop_map_put(NULL, s.fnindex, &(key), &_val, sizeof(_val)); });
            (*p) = s;
            return SLOP_RANGE(int64_t, id, 1, 0, 0, 0, "(Int 0 ..) at sriqnormal.slop:864:13");
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_int sriqnormal_fn_ids(slop_arena* arena, sriqnormal_S2State* p, slop_string axkey, int64_t n) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 1;
        while (i <= n) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_fn_id(arena, p, string_concat(arena, axkey, string_concat(arena, SLOP_STR("|"), int_to_string(arena, i))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        return out;
    }
}

slop_list_sroiq_SConcept sriqnormal_nnf_list(slop_arena* arena, slop_list_sroiq_SConcept xs, uint8_t pos) {
    {
        __auto_type out = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_nnf(arena, x, pos)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

sroiq_SConcept sriqnormal_nnf(slop_arena* arena, sroiq_SConcept c, uint8_t pos) {
    if (pos) {
        __auto_type _mv_1197 = c;
        switch (_mv_1197.tag) {
            case sroiq_SConcept_sc_top:
            {
                return c;
            }
            case sroiq_SConcept_sc_bottom:
            {
                return c;
            }
            case sroiq_SConcept_sc_name:
            {
                __auto_type _ = _mv_1197.data.sc_name;
                return c;
            }
            case sroiq_SConcept_sc_nominal:
            {
                __auto_type _ = _mv_1197.data.sc_nominal;
                return c;
            }
            case sroiq_SConcept_sc_self:
            {
                __auto_type _ = _mv_1197.data.sc_self;
                return c;
            }
            case sroiq_SConcept_sc_not:
            {
                __auto_type f = _mv_1197.data.sc_not;
                return sriqnormal_nnf(arena, (*f), 0);
            }
            case sroiq_SConcept_sc_and:
            {
                __auto_type xs = _mv_1197.data.sc_and;
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_and, .data.sc_and = sriqnormal_nnf_list(arena, xs, 1) });
            }
            case sroiq_SConcept_sc_or:
            {
                __auto_type xs = _mv_1197.data.sc_or;
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_or, .data.sc_or = sriqnormal_nnf_list(arena, xs, 1) });
            }
            case sroiq_SConcept_sc_some:
            {
                __auto_type r = _mv_1197.data.sc_some.f0;
                __auto_type f = _mv_1197.data.sc_some.f1;
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = sriqnormal_sc(arena, sriqnormal_nnf(arena, (*f), 1)) } });
            }
            case sroiq_SConcept_sc_all:
            {
                __auto_type r = _mv_1197.data.sc_all.f0;
                __auto_type f = _mv_1197.data.sc_all.f1;
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = sriqnormal_sc(arena, sriqnormal_nnf(arena, (*f), 1)) } });
            }
            case sroiq_SConcept_sc_atleast:
            {
                __auto_type n = _mv_1197.data.sc_atleast.f0;
                __auto_type r = _mv_1197.data.sc_atleast.f1;
                __auto_type f = _mv_1197.data.sc_atleast.f2;
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atleast, .data.sc_atleast = { .f0 = n, .f1 = r, .f2 = sriqnormal_sc(arena, sriqnormal_nnf(arena, (*f), 1)) } });
            }
            case sroiq_SConcept_sc_atmost:
            {
                __auto_type n = _mv_1197.data.sc_atmost.f0;
                __auto_type r = _mv_1197.data.sc_atmost.f1;
                __auto_type f = _mv_1197.data.sc_atmost.f2;
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = n, .f1 = r, .f2 = sriqnormal_sc(arena, sriqnormal_nnf(arena, (*f), 1)) } });
            }
        }
        SLOP_UNREACHABLE();
    } else {
        __auto_type _mv_1198 = c;
        switch (_mv_1198.tag) {
            case sroiq_SConcept_sc_top:
            {
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_bottom });
            }
            case sroiq_SConcept_sc_bottom:
            {
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_top });
            }
            case sroiq_SConcept_sc_name:
            {
                __auto_type _ = _mv_1198.data.sc_name;
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_not, .data.sc_not = sriqnormal_sc(arena, c) });
            }
            case sroiq_SConcept_sc_nominal:
            {
                __auto_type _ = _mv_1198.data.sc_nominal;
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_not, .data.sc_not = sriqnormal_sc(arena, c) });
            }
            case sroiq_SConcept_sc_self:
            {
                __auto_type _ = _mv_1198.data.sc_self;
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_not, .data.sc_not = sriqnormal_sc(arena, c) });
            }
            case sroiq_SConcept_sc_not:
            {
                __auto_type f = _mv_1198.data.sc_not;
                return sriqnormal_nnf(arena, (*f), 1);
            }
            case sroiq_SConcept_sc_and:
            {
                __auto_type xs = _mv_1198.data.sc_and;
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_or, .data.sc_or = sriqnormal_nnf_list(arena, xs, 0) });
            }
            case sroiq_SConcept_sc_or:
            {
                __auto_type xs = _mv_1198.data.sc_or;
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_and, .data.sc_and = sriqnormal_nnf_list(arena, xs, 0) });
            }
            case sroiq_SConcept_sc_some:
            {
                __auto_type r = _mv_1198.data.sc_some.f0;
                __auto_type f = _mv_1198.data.sc_some.f1;
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = sriqnormal_sc(arena, sriqnormal_nnf(arena, (*f), 0)) } });
            }
            case sroiq_SConcept_sc_all:
            {
                __auto_type r = _mv_1198.data.sc_all.f0;
                __auto_type f = _mv_1198.data.sc_all.f1;
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = sriqnormal_sc(arena, sriqnormal_nnf(arena, (*f), 0)) } });
            }
            case sroiq_SConcept_sc_atleast:
            {
                __auto_type n = _mv_1198.data.sc_atleast.f0;
                __auto_type r = _mv_1198.data.sc_atleast.f1;
                __auto_type f = _mv_1198.data.sc_atleast.f2;
                if (n == 0) {
                    return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_bottom });
                } else {
                    return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = ((int64_t)(SLOP_RANGE(int64_t, (n - 1), 1, 0, 0, 0, "(Int 0 ..) at sriqnormal.slop:923:60"))), .f1 = r, .f2 = sriqnormal_sc(arena, sriqnormal_nnf(arena, (*f), 1)) } });
                }
            }
            case sroiq_SConcept_sc_atmost:
            {
                __auto_type n = _mv_1198.data.sc_atmost.f0;
                __auto_type r = _mv_1198.data.sc_atmost.f1;
                __auto_type f = _mv_1198.data.sc_atmost.f2;
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atleast, .data.sc_atleast = { .f0 = ((int64_t)((n + 1))), .f1 = r, .f2 = sriqnormal_sc(arena, sriqnormal_nnf(arena, (*f), 1)) } });
            }
        }
        SLOP_UNREACHABLE();
    }
}

slop_option_types_DName sriqnormal_pos_name(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept c) {
    __auto_type _mv_1199 = c;
    switch (_mv_1199.tag) {
        case sroiq_SConcept_sc_top:
        {
            return (slop_option_types_DName){.has_value = false};
        }
        case sroiq_SConcept_sc_name:
        {
            __auto_type i = _mv_1199.data.sc_name;
            return (slop_option_types_DName){.has_value = 1, .value = ((types_DName){ .tag = types_DName_dn_class, .data.dn_class = i })};
        }
        default: {
            {
                __auto_type key = sroiq_sc_key(arena, c);
                __auto_type x = ((types_DName){ .tag = types_DName_dn_fresh, .data.dn_fresh = sriqnormal_fresh_name(arena, p, c) });
                if (!(naming_pos_defined((*p).registry, key))) {
                    naming_mark_pos(arena, (*p).registry, key);
                    sriqnormal_define_pos(arena, p, x, c);
                }
                return (slop_option_types_DName){.has_value = 1, .value = x};
            }
        }
    }
}

slop_option_types_DName sriqnormal_neg_name(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept c) {
    __auto_type _mv_1200 = c;
    switch (_mv_1200.tag) {
        case sroiq_SConcept_sc_top:
        {
            return (slop_option_types_DName){.has_value = false};
        }
        case sroiq_SConcept_sc_name:
        {
            __auto_type i = _mv_1200.data.sc_name;
            return (slop_option_types_DName){.has_value = 1, .value = ((types_DName){ .tag = types_DName_dn_class, .data.dn_class = i })};
        }
        default: {
            {
                __auto_type key = sroiq_sc_key(arena, c);
                __auto_type x = ((types_DName){ .tag = types_DName_dn_fresh, .data.dn_fresh = sriqnormal_fresh_name(arena, p, c) });
                if (!(naming_neg_defined((*p).registry, key))) {
                    naming_mark_neg(arena, (*p).registry, key);
                    __auto_type _mv_1201 = c;
                    switch (_mv_1201.tag) {
                        case sroiq_SConcept_sc_nominal:
                        {
                            __auto_type i = _mv_1201.data.sc_nominal;
                            sriqnormal_emit(arena, p, ((types_DlClause){ .tag = types_DlClause_dl10, .data.dl10 = { .f0 = i, .f1 = x } }));
                            break;
                        }
                        case sroiq_SConcept_sc_self:
                        {
                            __auto_type r = _mv_1201.data.sc_self;
                            sriqnormal_emit(arena, p, ((types_DlClause){ .tag = types_DlClause_dl6, .data.dl6 = { .f0 = sriqnormal_role_name(arena, p, r), .f1 = x } }));
                            break;
                        }
                        default: {
                            sriqnormal_disjunction(arena, p, ((slop_option_types_DName){.has_value = false}), (slop_option_types_DName){.has_value = 1, .value = x}, sroiq_sc_canon(arena, sriqnormal_nnf(arena, c, 0)));
                            break;
                        }
                    }
                }
                return (slop_option_types_DName){.has_value = 1, .value = x};
            }
        }
    }
}

slop_option_types_DName sriqnormal_neg_literal_name(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept lit) {
    return sriqnormal_neg_name(arena, p, lit);
}

slop_list_sroiq_SConcept sriqnormal_singleton_sc(slop_arena* arena, sroiq_SConcept c) {
    {
        __auto_type xs = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(xs); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return xs;
    }
}

uint8_t sriqnormal_disjunction(slop_arena* arena, sriqnormal_S2State* p, slop_option_types_DName lhs, slop_option_types_DName extra, sroiq_SConcept e) {
    {
        __auto_type ds = ({ __auto_type _mv = e; slop_list_sroiq_SConcept _mr = {0}; switch (_mv.tag) { case sroiq_SConcept_sc_or: { __auto_type xs = _mv.data.sc_or; _mr = xs; break; } default: { _mr = sriqnormal_singleton_sc(arena, e); break; }  } _mr; });
        __auto_type body = ((slop_list_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type head = ((slop_list_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t taut = 0;
        __auto_type _mv_1202 = lhs;
        if (_mv_1202.has_value) {
            __auto_type x = _mv_1202.value;
            ({ __auto_type _lst_p = &(body); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (!_mv_1202.has_value) {
        }
        __auto_type _mv_1203 = extra;
        if (_mv_1203.has_value) {
            __auto_type x = _mv_1203.value;
            ({ __auto_type _lst_p = &(head); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (!_mv_1203.has_value) {
        }
        {
            __auto_type _coll = ds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type d = _coll.data[_i];
                __auto_type _mv_1204 = d;
                switch (_mv_1204.tag) {
                    case sroiq_SConcept_sc_top:
                    {
                        taut = 1;
                        break;
                    }
                    case sroiq_SConcept_sc_bottom:
                    {
                        break;
                    }
                    case sroiq_SConcept_sc_name:
                    {
                        __auto_type i = _mv_1204.data.sc_name;
                        ({ __auto_type _lst_p = &(head); __auto_type _item = (((types_DName){ .tag = types_DName_dn_class, .data.dn_class = i })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case sroiq_SConcept_sc_not:
                    {
                        __auto_type f = _mv_1204.data.sc_not;
                        __auto_type _mv_1205 = sriqnormal_neg_literal_name(arena, p, (*f));
                        if (_mv_1205.has_value) {
                            __auto_type n = _mv_1205.value;
                            ({ __auto_type _lst_p = &(body); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        } else if (!_mv_1205.has_value) {
                        }
                        break;
                    }
                    default: {
                        __auto_type _mv_1206 = sriqnormal_pos_name(arena, p, d);
                        if (_mv_1206.has_value) {
                            __auto_type n = _mv_1206.value;
                            ({ __auto_type _lst_p = &(head); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        } else if (!_mv_1206.has_value) {
                            taut = 1;
                        }
                        break;
                    }
                }
            }
        }
        if (!(taut)) {
            sriqnormal_emit(arena, p, ((types_DlClause){ .tag = types_DlClause_dl1, .data.dl1 = ((types_Dl1){.body = body, .head = head}) }));
        }
        return 1;
    }
}

uint8_t sriqnormal_define_pos(slop_arena* arena, sriqnormal_S2State* p, types_DName x, sroiq_SConcept e) {
    __auto_type _mv_1207 = e;
    switch (_mv_1207.tag) {
        case sroiq_SConcept_sc_top:
        {
            return 1;
        }
        case sroiq_SConcept_sc_name:
        {
            __auto_type _ = _mv_1207.data.sc_name;
            return sriqnormal_disjunction(arena, p, (slop_option_types_DName){.has_value = 1, .value = x}, ((slop_option_types_DName){.has_value = false}), e);
        }
        case sroiq_SConcept_sc_bottom:
        {
            return sriqnormal_disjunction(arena, p, (slop_option_types_DName){.has_value = 1, .value = x}, ((slop_option_types_DName){.has_value = false}), e);
        }
        case sroiq_SConcept_sc_not:
        {
            __auto_type _ = _mv_1207.data.sc_not;
            return sriqnormal_disjunction(arena, p, (slop_option_types_DName){.has_value = 1, .value = x}, ((slop_option_types_DName){.has_value = false}), e);
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type _ = _mv_1207.data.sc_or;
            return sriqnormal_disjunction(arena, p, (slop_option_types_DName){.has_value = 1, .value = x}, ((slop_option_types_DName){.has_value = false}), e);
        }
        case sroiq_SConcept_sc_nominal:
        {
            __auto_type i = _mv_1207.data.sc_nominal;
            return sriqnormal_emit(arena, p, ((types_DlClause){ .tag = types_DlClause_dl11, .data.dl11 = { .f0 = x, .f1 = i } }));
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_1207.data.sc_and;
            {
                __auto_type _coll = xs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    sriqnormal_define_pos(arena, p, x, c);
                }
            }
            return 1;
        }
        case sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_1207.data.sc_some.f0;
            __auto_type f = _mv_1207.data.sc_some.f1;
            return sriqnormal_define_dl2(arena, p, x, r, 1, (*f));
        }
        case sroiq_SConcept_sc_atleast:
        {
            __auto_type n = _mv_1207.data.sc_atleast.f0;
            __auto_type r = _mv_1207.data.sc_atleast.f1;
            __auto_type f = _mv_1207.data.sc_atleast.f2;
            if (n == 0) {
                return 1;
            } else {
                return sriqnormal_define_dl2(arena, p, x, r, n, (*f));
            }
        }
        case sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_1207.data.sc_all.f0;
            __auto_type f = _mv_1207.data.sc_all.f1;
            __auto_type _mv_1208 = sriqnormal_pos_name(arena, p, (*f));
            if (!_mv_1208.has_value) {
                return 1;
            } else if (_mv_1208.has_value) {
                __auto_type b = _mv_1208.value;
                return sriqnormal_emit(arena, p, ((types_DlClause){ .tag = types_DlClause_dl3, .data.dl3 = { .f0 = sriqnormal_role_name(arena, p, sroiq_inv_role(r)), .f1 = x, .f2 = b } }));
            }
            SLOP_UNREACHABLE();
        }
        case sroiq_SConcept_sc_atmost:
        {
            __auto_type n = _mv_1207.data.sc_atmost.f0;
            __auto_type r = _mv_1207.data.sc_atmost.f1;
            __auto_type f = _mv_1207.data.sc_atmost.f2;
            {
                __auto_type s = sriqnormal_role_name(arena, p, r);
                __auto_type b = sriqnormal_neg_name(arena, p, (*f));
                return sriqnormal_emit(arena, p, ((types_DlClause){ .tag = types_DlClause_dl4, .data.dl4 = ((types_Dl4){.sub = x, .role = s, .count = n, .filler = b, .srole = sriqnormal_srole_of(arena, p, s, b)}) }));
            }
        }
        case sroiq_SConcept_sc_self:
        {
            __auto_type r = _mv_1207.data.sc_self;
            return sriqnormal_emit(arena, p, ((types_DlClause){ .tag = types_DlClause_dl5, .data.dl5 = { .f0 = x, .f1 = sriqnormal_role_name(arena, p, r) } }));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqnormal_define_dl2(slop_arena* arena, sriqnormal_S2State* p, types_DName x, types_RoleId r, int64_t n, sroiq_SConcept f) {
    {
        __auto_type s = sriqnormal_role_name(arena, p, r);
        __auto_type b = sriqnormal_pos_name(arena, p, f);
        __auto_type parts = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(parts); __auto_type _item = (sriqnormal_dname_key(arena, p, x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(parts); __auto_type _item = (int_to_string(arena, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(parts); __auto_type _item = (sriqnormal_drole_key(arena, p, s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(parts); __auto_type _item = (sriqnormal_filler_key(arena, p, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return sriqnormal_emit(arena, p, ((types_DlClause){ .tag = types_DlClause_dl2, .data.dl2 = ((types_Dl2){.sub = x, .role = s, .count = ((int64_t)(SLOP_RANGE(int64_t, n, 1, 0, 1, 0, "(Int 1 ..) at sriqnormal.slop:1069:82"))), .filler = b, .fns = sriqnormal_fn_ids(arena, p, sriqnormal_key_of(arena, SLOP_STR("dl2"), parts), ((int64_t)(n)))}) }));
    }
}

uint8_t sriqnormal_s2_gci(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept l, sroiq_SConcept r) {
    {
        __auto_type both = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(both); __auto_type _item = (((sroiq_SConcept){ .tag = sroiq_SConcept_sc_not, .data.sc_not = sriqnormal_sc(arena, l) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(both); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return sriqnormal_assert_top(arena, p, sroiq_sc_canon(arena, sriqnormal_nnf(arena, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_or, .data.sc_or = both }), 1)));
    }
}

uint8_t sriqnormal_assert_top(slop_arena* arena, sriqnormal_S2State* p, sroiq_SConcept e) {
    __auto_type _mv_1209 = e;
    switch (_mv_1209.tag) {
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_1209.data.sc_and;
            {
                __auto_type _coll = xs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    sriqnormal_assert_top(arena, p, c);
                }
            }
            return 1;
        }
        default: {
            return sriqnormal_disjunction(arena, p, ((slop_option_types_DName){.has_value = false}), ((slop_option_types_DName){.has_value = false}), e);
        }
    }
}

slop_option_rdf_IRI sriqnormal_role_prop(types_RoleId r) {
    __auto_type _mv_1210 = r;
    switch (_mv_1210.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_1210.data.named_role;
            return (slop_option_rdf_IRI){.has_value = 1, .value = i};
        }
        case types_RoleId_inverse_role:
        {
            __auto_type i = _mv_1210.data.inverse_role;
            return (slop_option_rdf_IRI){.has_value = 1, .value = i};
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_1210.data.fresh_role;
            return (slop_option_rdf_IRI){.has_value = false};
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqnormal_role_inverted(types_RoleId r) {
    __auto_type _mv_1211 = r;
    switch (_mv_1211.tag) {
        case types_RoleId_inverse_role:
        {
            __auto_type _ = _mv_1211.data.inverse_role;
            return 1;
        }
        default: {
            return 0;
        }
    }
}

slop_result_u8_string sriqnormal_s2_inclusion(slop_arena* arena, sriqnormal_S2State* p, types_RoleId r, types_RoleId s) {
    __auto_type _mv_1212 = sriqnormal_role_prop(r);
    if (!_mv_1212.has_value) {
        return ((slop_result_u8_string){ .is_ok = false, .data.err = SLOP_STR("a fresh role in S2") });
    } else if (_mv_1212.has_value) {
        __auto_type pi = _mv_1212.value;
        __auto_type _mv_1213 = sriqnormal_role_prop(s);
        if (!_mv_1213.has_value) {
            return ((slop_result_u8_string){ .is_ok = false, .data.err = SLOP_STR("a fresh role in S2") });
        } else if (_mv_1213.has_value) {
            __auto_type qi = _mv_1213.value;
            {
                __auto_type a = ((types_DRole){ .tag = types_DRole_dr_prop, .data.dr_prop = pi });
                __auto_type b = ((types_DRole){ .tag = types_DRole_dr_prop, .data.dr_prop = qi });
                sriqnormal_emit(arena, p, (((sriqnormal_role_inverted(r) == sriqnormal_role_inverted(s))) ? ((types_DlClause){ .tag = types_DlClause_dl7, .data.dl7 = { .f0 = a, .f1 = b } }) : ((types_DlClause){ .tag = types_DlClause_dl8, .data.dl8 = { .f0 = a, .f1 = b } })));
                return ((slop_result_u8_string){ .is_ok = true, .data.ok = 1 });
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_u8_string sriqnormal_s2_ria(slop_arena* arena, sriqnormal_S2State* p, sroiq_SRia x) {
    if (((int64_t)((x.word).len)) != 1) {
        return ((slop_result_u8_string){ .is_ok = false, .data.err = SLOP_STR("a complex role inclusion reached S2: S1 must eliminate it first") });
    } else {
        __auto_type _mv_1214 = ({ __auto_type _lst = x.word; size_t _idx = (size_t)0; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1214.has_value) {
            return ((slop_result_u8_string){ .is_ok = false, .data.err = SLOP_STR("an empty role inclusion") });
        } else if (_mv_1214.has_value) {
            __auto_type r = _mv_1214.value;
            return sriqnormal_s2_inclusion(arena, p, r, x.super);
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t sriqnormal_s2_dis(slop_arena* arena, sriqnormal_S2State* p, types_RoleId r, types_RoleId s) {
    __auto_type _mv_1215 = r;
    switch (_mv_1215.tag) {
        case types_RoleId_inverse_role:
        {
            __auto_type pi = _mv_1215.data.inverse_role;
            __auto_type _mv_1216 = s;
            switch (_mv_1216.tag) {
                case types_RoleId_inverse_role:
                {
                    __auto_type qi = _mv_1216.data.inverse_role;
                    return sriqnormal_emit(arena, p, ((types_DlClause){ .tag = types_DlClause_dl9, .data.dl9 = { .f0 = ((types_DRole){ .tag = types_DRole_dr_prop, .data.dr_prop = pi }), .f1 = ((types_DRole){ .tag = types_DRole_dr_prop, .data.dr_prop = qi }) } }));
                }
                default: {
                    return sriqnormal_emit(arena, p, ((types_DlClause){ .tag = types_DlClause_dl9, .data.dl9 = { .f0 = sriqnormal_role_name(arena, p, r), .f1 = sriqnormal_role_name(arena, p, s) } }));
                }
            }
        }
        default: {
            return sriqnormal_emit(arena, p, ((types_DlClause){ .tag = types_DlClause_dl9, .data.dl9 = { .f0 = sriqnormal_role_name(arena, p, r), .f1 = sriqnormal_role_name(arena, p, s) } }));
        }
    }
}

uint8_t sriqnormal_counts_ok(sroiq_SConcept c) {
    __auto_type _mv_1217 = c;
    switch (_mv_1217.tag) {
        case sroiq_SConcept_sc_top:
        {
            return 1;
        }
        case sroiq_SConcept_sc_bottom:
        {
            return 1;
        }
        case sroiq_SConcept_sc_name:
        {
            __auto_type _ = _mv_1217.data.sc_name;
            return 1;
        }
        case sroiq_SConcept_sc_nominal:
        {
            __auto_type _ = _mv_1217.data.sc_nominal;
            return 1;
        }
        case sroiq_SConcept_sc_self:
        {
            __auto_type _ = _mv_1217.data.sc_self;
            return 1;
        }
        case sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_1217.data.sc_not;
            return sriqnormal_counts_ok((*f));
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_1217.data.sc_and;
            return sriqnormal_counts_list_ok(xs);
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_1217.data.sc_or;
            return sriqnormal_counts_list_ok(xs);
        }
        case sroiq_SConcept_sc_some:
        {
            __auto_type f = _mv_1217.data.sc_some.f1;
            return sriqnormal_counts_ok((*f));
        }
        case sroiq_SConcept_sc_all:
        {
            __auto_type f = _mv_1217.data.sc_all.f1;
            return sriqnormal_counts_ok((*f));
        }
        case sroiq_SConcept_sc_atleast:
        {
            __auto_type n = _mv_1217.data.sc_atleast.f0;
            __auto_type f = _mv_1217.data.sc_atleast.f2;
            return ((n <= owl2_SRIQ_MAX_COUNT) && sriqnormal_counts_ok((*f)));
        }
        case sroiq_SConcept_sc_atmost:
        {
            __auto_type n = _mv_1217.data.sc_atmost.f0;
            __auto_type f = _mv_1217.data.sc_atmost.f2;
            return ((n <= owl2_SRIQ_MAX_COUNT) && sriqnormal_counts_ok((*f)));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqnormal_counts_list_ok(slop_list_sroiq_SConcept cs) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(sriqnormal_counts_ok(c))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

slop_result_sriqnormal_S2_string sriqnormal_sriq_s2(slop_arena* arena, slop_list_sroiq_SAxiom axs) {
    {
        __auto_type p = sriqnormal_new_s2(arena);
        slop_option_string fault = (slop_option_string){.has_value = false};
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_1218 = a;
                switch (_mv_1218.tag) {
                    case sroiq_SAxiom_sa_gci:
                    {
                        __auto_type l = _mv_1218.data.sa_gci.f0;
                        __auto_type r = _mv_1218.data.sa_gci.f1;
                        if (!((sriqnormal_counts_ok((*l)) && sriqnormal_counts_ok((*r))))) {
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
                __auto_type _mv_1219 = a;
                switch (_mv_1219.tag) {
                    case sroiq_SAxiom_sa_gci:
                    {
                        __auto_type l = _mv_1219.data.sa_gci.f0;
                        __auto_type r = _mv_1219.data.sa_gci.f1;
                        sriqnormal_s2_gci(arena, p, (*l), (*r));
                        break;
                    }
                    case sroiq_SAxiom_sa_ria:
                    {
                        __auto_type x = _mv_1219.data.sa_ria;
                        __auto_type _mv_1220 = sriqnormal_s2_ria(arena, p, x);
                        if (_mv_1220.is_ok) {
                            __auto_type _ = _mv_1220.data.ok;
                        } else if (!_mv_1220.is_ok) {
                            __auto_type m = _mv_1220.data.err;
                            fault = (slop_option_string){.has_value = 1, .value = m};
                        }
                        break;
                    }
                    case sroiq_SAxiom_sa_ref:
                    {
                        __auto_type r = _mv_1219.data.sa_ref;
                        sriqnormal_s2_gci(arena, p, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_top }), ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_self, .data.sc_self = r }));
                        break;
                    }
                    case sroiq_SAxiom_sa_irr:
                    {
                        __auto_type r = _mv_1219.data.sa_irr;
                        sriqnormal_s2_gci(arena, p, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_self, .data.sc_self = r }), ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_bottom }));
                        break;
                    }
                    case sroiq_SAxiom_sa_dis:
                    {
                        __auto_type r = _mv_1219.data.sa_dis.f0;
                        __auto_type s = _mv_1219.data.sa_dis.f1;
                        sriqnormal_s2_dis(arena, p, r, s);
                        break;
                    }
                }
            }
        }
        {
            __auto_type _coll = (*p).bars;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                sriqnormal_emit(arena, p, ((types_DlClause){ .tag = types_DlClause_dl8, .data.dl8 = { .f0 = ((types_DRole){ .tag = types_DRole_dr_prop, .data.dr_prop = i }), .f1 = ((types_DRole){ .tag = types_DRole_dr_bar, .data.dr_bar = i }) } }));
                sriqnormal_emit(arena, p, ((types_DlClause){ .tag = types_DlClause_dl8, .data.dl8 = { .f0 = ((types_DRole){ .tag = types_DRole_dr_bar, .data.dr_bar = i }), .f1 = ((types_DRole){ .tag = types_DRole_dr_prop, .data.dr_prop = i }) } }));
            }
        }
        __auto_type _mv_1221 = fault;
        if (_mv_1221.has_value) {
            __auto_type m = _mv_1221.value;
            return ((slop_result_sriqnormal_S2_string){ .is_ok = false, .data.err = m });
        } else if (!_mv_1221.has_value) {
            {
                __auto_type s = (*p);
                return ((slop_result_sriqnormal_S2_string){ .is_ok = true, .data.ok = ((sriqnormal_S2){.clauses = s.out, .concepts = s.concepts, .sroles = s.sroles, .sfills = s.sfills, .bars = s.bars, .fnkeys = s.fnkeys}) });
            }
        }
        SLOP_UNREACHABLE();
    }
}

slop_string sriqnormal_render_dname(slop_arena* arena, sriqnormal_S2 s2, types_DName n) {
    __auto_type _mv_1222 = n;
    switch (_mv_1222.tag) {
        case types_DName_dn_class:
        {
            __auto_type i = _mv_1222.data.dn_class;
            return i.value;
        }
        case types_DName_dn_fresh:
        {
            __auto_type k = _mv_1222.data.dn_fresh;
            __auto_type _mv_1223 = ({ __auto_type _lst = s2.concepts; size_t _idx = (size_t)k; slop_option_sroiq_SConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1223.has_value) {
                __auto_type c = _mv_1223.value;
                return string_concat(arena, SLOP_STR("A["), string_concat(arena, sroiq_render_sconcept(arena, c), SLOP_STR("]")));
            } else if (!_mv_1223.has_value) {
                return SLOP_STR("A[?]");
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

slop_string sriqnormal_render_dfiller(slop_arena* arena, sriqnormal_S2 s2, slop_option_types_DName b) {
    __auto_type _mv_1224 = b;
    if (_mv_1224.has_value) {
        __auto_type n = _mv_1224.value;
        return sriqnormal_render_dname(arena, s2, n);
    } else if (!_mv_1224.has_value) {
        return SLOP_STR("⊤");
    }
    SLOP_UNREACHABLE();
}

slop_string sriqnormal_render_drole(slop_arena* arena, sriqnormal_S2 s2, types_DRole r) {
    __auto_type _mv_1225 = r;
    switch (_mv_1225.tag) {
        case types_DRole_dr_prop:
        {
            __auto_type i = _mv_1225.data.dr_prop;
            return i.value;
        }
        case types_DRole_dr_bar:
        {
            __auto_type i = _mv_1225.data.dr_bar;
            return string_concat(arena, SLOP_STR("bar("), string_concat(arena, i.value, SLOP_STR(")")));
        }
        case types_DRole_dr_sub:
        {
            __auto_type k = _mv_1225.data.dr_sub;
            {
                __auto_type s = ({ __auto_type _mv = ({ __auto_type _lst = s2.sroles; size_t _idx = (size_t)k; slop_option_types_DRole _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : (r); });
                __auto_type b = ({ __auto_type _mv = ({ __auto_type _lst = s2.sfills; size_t _idx = (size_t)k; slop_option_option_types_DName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : ((slop_option_types_DName){.has_value = false}); });
                return string_concat(arena, SLOP_STR("S_{"), string_concat(arena, sriqnormal_render_drole(arena, s2, s), string_concat(arena, SLOP_STR(","), string_concat(arena, sriqnormal_render_dfiller(arena, s2, b), SLOP_STR("}")))));
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_string sriqnormal_render_dnames(slop_arena* arena, sriqnormal_S2 s2, slop_list_types_DName ns, slop_string sep, slop_string empty) {
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
                    out = string_concat(arena, out, sriqnormal_render_dname(arena, s2, n));
                    first = 0;
                }
            }
            return out;
        }
    }
}

slop_string sriqnormal_inclusion(slop_arena* arena, slop_string form, slop_string lhs, slop_string rhs) {
    return string_concat(arena, form, string_concat(arena, SLOP_STR(" "), string_concat(arena, lhs, string_concat(arena, SLOP_STR(" ⊑ "), rhs))));
}

slop_string sriqnormal_restriction_text(slop_arena* arena, slop_string op, slop_string role, slop_string filler) {
    return string_concat(arena, op, string_concat(arena, role, string_concat(arena, SLOP_STR("."), filler)));
}

slop_string sriqnormal_count_op(slop_arena* arena, slop_string op, int64_t n) {
    return string_concat(arena, op, string_concat(arena, int_to_string(arena, n), SLOP_STR(" ")));
}

slop_string sriqnormal_braces(slop_arena* arena, rdf_IRI o) {
    return string_concat(arena, SLOP_STR("{"), string_concat(arena, o.value, SLOP_STR("}")));
}

slop_string sriqnormal_render_dl(slop_arena* arena, sriqnormal_S2 s2, types_DlClause c) {
    __auto_type _mv_1226 = c;
    switch (_mv_1226.tag) {
        case types_DlClause_dl1:
        {
            __auto_type d = _mv_1226.data.dl1;
            return sriqnormal_inclusion(arena, SLOP_STR("DL1"), sriqnormal_render_dnames(arena, s2, d.body, SLOP_STR(" ⊓ "), SLOP_STR("⊤")), sriqnormal_render_dnames(arena, s2, d.head, SLOP_STR(" ⊔ "), SLOP_STR("⊥")));
        }
        case types_DlClause_dl2:
        {
            __auto_type d = _mv_1226.data.dl2;
            return sriqnormal_inclusion(arena, SLOP_STR("DL2"), sriqnormal_render_dname(arena, s2, d.sub), sriqnormal_restriction_text(arena, sriqnormal_count_op(arena, SLOP_STR("≥"), d.count), sriqnormal_render_drole(arena, s2, d.role), sriqnormal_render_dfiller(arena, s2, d.filler)));
        }
        case types_DlClause_dl3:
        {
            __auto_type s = _mv_1226.data.dl3.f0;
            __auto_type b1 = _mv_1226.data.dl3.f1;
            __auto_type b2 = _mv_1226.data.dl3.f2;
            return sriqnormal_inclusion(arena, SLOP_STR("DL3"), sriqnormal_restriction_text(arena, SLOP_STR("∃"), sriqnormal_render_drole(arena, s2, s), sriqnormal_render_dname(arena, s2, b1)), sriqnormal_render_dname(arena, s2, b2));
        }
        case types_DlClause_dl4:
        {
            __auto_type d = _mv_1226.data.dl4;
            return sriqnormal_inclusion(arena, SLOP_STR("DL4"), sriqnormal_render_dname(arena, s2, d.sub), string_concat(arena, sriqnormal_restriction_text(arena, sriqnormal_count_op(arena, SLOP_STR("≤"), d.count), sriqnormal_render_drole(arena, s2, d.role), sriqnormal_render_dfiller(arena, s2, d.filler)), string_concat(arena, SLOP_STR(" via "), sriqnormal_render_drole(arena, s2, d.srole))));
        }
        case types_DlClause_dl5:
        {
            __auto_type b = _mv_1226.data.dl5.f0;
            __auto_type s = _mv_1226.data.dl5.f1;
            return sriqnormal_inclusion(arena, SLOP_STR("DL5"), sriqnormal_render_dname(arena, s2, b), sriqnormal_restriction_text(arena, SLOP_STR("∃"), sriqnormal_render_drole(arena, s2, s), SLOP_STR("Self")));
        }
        case types_DlClause_dl6:
        {
            __auto_type s = _mv_1226.data.dl6.f0;
            __auto_type b = _mv_1226.data.dl6.f1;
            return sriqnormal_inclusion(arena, SLOP_STR("DL6"), sriqnormal_restriction_text(arena, SLOP_STR("∃"), sriqnormal_render_drole(arena, s2, s), SLOP_STR("Self")), sriqnormal_render_dname(arena, s2, b));
        }
        case types_DlClause_dl7:
        {
            __auto_type a = _mv_1226.data.dl7.f0;
            __auto_type b = _mv_1226.data.dl7.f1;
            return sriqnormal_inclusion(arena, SLOP_STR("DL7"), sriqnormal_render_drole(arena, s2, a), sriqnormal_render_drole(arena, s2, b));
        }
        case types_DlClause_dl8:
        {
            __auto_type a = _mv_1226.data.dl8.f0;
            __auto_type b = _mv_1226.data.dl8.f1;
            return sriqnormal_inclusion(arena, SLOP_STR("DL8"), sriqnormal_render_drole(arena, s2, a), string_concat(arena, sriqnormal_render_drole(arena, s2, b), SLOP_STR("⁻")));
        }
        case types_DlClause_dl9:
        {
            __auto_type a = _mv_1226.data.dl9.f0;
            __auto_type b = _mv_1226.data.dl9.f1;
            return string_concat(arena, SLOP_STR("DL9 Disj("), string_concat(arena, sriqnormal_render_drole(arena, s2, a), string_concat(arena, SLOP_STR(", "), string_concat(arena, sriqnormal_render_drole(arena, s2, b), SLOP_STR(")")))));
        }
        case types_DlClause_dl10:
        {
            __auto_type o = _mv_1226.data.dl10.f0;
            __auto_type b = _mv_1226.data.dl10.f1;
            return sriqnormal_inclusion(arena, SLOP_STR("DL10"), sriqnormal_braces(arena, o), sriqnormal_render_dname(arena, s2, b));
        }
        case types_DlClause_dl11:
        {
            __auto_type b = _mv_1226.data.dl11.f0;
            __auto_type o = _mv_1226.data.dl11.f1;
            return sriqnormal_inclusion(arena, SLOP_STR("DL11"), sriqnormal_render_dname(arena, s2, b), sriqnormal_braces(arena, o));
        }
    }
    SLOP_UNREACHABLE();
}

