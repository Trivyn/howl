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
                __auto_type _mv_1137 = sriqnormal_s0_concept(arena, c);
                if (_mv_1137.is_ok) {
                    __auto_type x = _mv_1137.data.ok;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1137.is_ok) {
                    __auto_type m = _mv_1137.data.err;
                    fault = (slop_option_string){.has_value = 1, .value = m};
                }
            }
        }
        __auto_type _mv_1138 = fault;
        if (_mv_1138.has_value) {
            __auto_type m = _mv_1138.value;
            return ((slop_result_list_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
        } else if (!_mv_1138.has_value) {
            return ((slop_result_list_sroiq_SConcept_string){ .is_ok = true, .data.ok = out });
        }
        SLOP_UNREACHABLE();
    }
}

slop_result_sroiq_SConcept_string sriqnormal_s0_filler(slop_arena* arena, owl2_RawConcept* f) {
    return sriqnormal_s0_concept(arena, (*f));
}

sroiq_SConcept sriqnormal_s0_count(slop_arena* arena, owl2_CardKind k, types_RoleId r, int64_t n, sroiq_SConcept f) {
    __auto_type _mv_1139 = k;
    if (_mv_1139 == owl2_CardKind_card_min) {
        return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atleast, .data.sc_atleast = { .f0 = n, .f1 = r, .f2 = sriqnormal_sc(arena, f) } });
    } else if (_mv_1139 == owl2_CardKind_card_max) {
        return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = n, .f1 = r, .f2 = sriqnormal_sc(arena, f) } });
    } else if (_mv_1139 == owl2_CardKind_card_exact) {
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
    __auto_type _mv_1140 = c;
    switch (_mv_1140.tag) {
        case owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_1140.data.rc_name;
            __auto_type _mv_1141 = n;
            switch (_mv_1141.tag) {
                case types_Node_class_node:
                {
                    __auto_type i = _mv_1141.data.class_node;
                    return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_name, .data.sc_name = i }) });
                }
                case types_Node_individual_node:
                {
                    __auto_type _ = _mv_1141.data.individual_node;
                    return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = SLOP_STR("an individual in a class position") });
                }
                case types_Node_fresh_node:
                {
                    __auto_type _ = _mv_1141.data.fresh_node;
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
            __auto_type cs = _mv_1140.data.rc_and;
            __auto_type _mv_1142 = sriqnormal_s0_concepts(arena, cs);
            if (_mv_1142.is_ok) {
                __auto_type xs = _mv_1142.data.ok;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_and, .data.sc_and = xs }) });
            } else if (!_mv_1142.is_ok) {
                __auto_type m = _mv_1142.data.err;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_1140.data.rc_or;
            __auto_type _mv_1143 = sriqnormal_s0_concepts(arena, cs);
            if (_mv_1143.is_ok) {
                __auto_type xs = _mv_1143.data.ok;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_or, .data.sc_or = xs }) });
            } else if (!_mv_1143.is_ok) {
                __auto_type m = _mv_1143.data.err;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_1140.data.rc_not;
            __auto_type _mv_1144 = sriqnormal_s0_filler(arena, f);
            if (_mv_1144.is_ok) {
                __auto_type x = _mv_1144.data.ok;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_not, .data.sc_not = sriqnormal_sc(arena, x) }) });
            } else if (!_mv_1144.is_ok) {
                __auto_type m = _mv_1144.data.err;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_1140.data.rc_some.f0;
            __auto_type f = _mv_1140.data.rc_some.f1;
            __auto_type _mv_1145 = sriqnormal_s0_filler(arena, f);
            if (_mv_1145.is_ok) {
                __auto_type x = _mv_1145.data.ok;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = sriqnormal_sc(arena, x) } }) });
            } else if (!_mv_1145.is_ok) {
                __auto_type m = _mv_1145.data.err;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case owl2_RawConcept_rc_all:
        {
            __auto_type r = _mv_1140.data.rc_all.f0;
            __auto_type f = _mv_1140.data.rc_all.f1;
            __auto_type _mv_1146 = sriqnormal_s0_filler(arena, f);
            if (_mv_1146.is_ok) {
                __auto_type x = _mv_1146.data.ok;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = sriqnormal_sc(arena, x) } }) });
            } else if (!_mv_1146.is_ok) {
                __auto_type m = _mv_1146.data.err;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case owl2_RawConcept_rc_card:
        {
            __auto_type k = _mv_1140.data.rc_card.f0;
            __auto_type r = _mv_1140.data.rc_card.f1;
            __auto_type n = _mv_1140.data.rc_card.f2;
            return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = sriqnormal_s0_count(arena, k, r, n, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_top })) });
        }
        case owl2_RawConcept_rc_qcard:
        {
            __auto_type k = _mv_1140.data.rc_qcard.f0;
            __auto_type r = _mv_1140.data.rc_qcard.f1;
            __auto_type n = _mv_1140.data.rc_qcard.f2;
            __auto_type f = _mv_1140.data.rc_qcard.f3;
            __auto_type _mv_1147 = sriqnormal_s0_filler(arena, f);
            if (_mv_1147.is_ok) {
                __auto_type x = _mv_1147.data.ok;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = sriqnormal_s0_count(arena, k, r, n, x) });
            } else if (!_mv_1147.is_ok) {
                __auto_type m = _mv_1147.data.err;
                return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = m });
            }
            SLOP_UNREACHABLE();
        }
        case owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_1140.data.rc_has_self;
            return ((slop_result_sroiq_SConcept_string){ .is_ok = true, .data.ok = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_self, .data.sc_self = r }) });
        }
        case owl2_RawConcept_rc_oneof:
        {
            __auto_type _ = _mv_1140.data.rc_oneof;
            return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = SLOP_STR("ObjectOneOf, which the sriq gate does not admit") });
        }
        case owl2_RawConcept_rc_has_value:
        {
            return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = SLOP_STR("ObjectHasValue, which the sriq gate does not admit") });
        }
        case owl2_RawConcept_rc_data:
        {
            __auto_type _ = _mv_1140.data.rc_data;
            return ((slop_result_sroiq_SConcept_string){ .is_ok = false, .data.err = SLOP_STR("a data range, which the sriq gate does not admit") });
        }
        case owl2_RawConcept_rc_anon:
        {
            __auto_type _ = _mv_1140.data.rc_anon;
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
    __auto_type _mv_1148 = n;
    switch (_mv_1148.tag) {
        case types_Node_individual_node:
        {
            __auto_type i = _mv_1148.data.individual_node;
            return (slop_option_sroiq_SConcept){.has_value = 1, .value = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_nominal, .data.sc_nominal = i })};
        }
        case types_Node_class_node:
        {
            __auto_type _ = _mv_1148.data.class_node;
            return (slop_option_sroiq_SConcept){.has_value = false};
        }
        case types_Node_fresh_node:
        {
            __auto_type _ = _mv_1148.data.fresh_node;
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
                __auto_type _mv_1149 = n;
                switch (_mv_1149.tag) {
                    case types_Node_individual_node:
                    {
                        __auto_type i = _mv_1149.data.individual_node;
                        __auto_type _mv_1150 = best;
                        if (!_mv_1150.has_value) {
                            best = (slop_option_rdf_IRI){.has_value = 1, .value = i};
                        } else if (_mv_1150.has_value) {
                            __auto_type b = _mv_1150.value;
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

slop_result_list_sroiq_SAxiom_string sriqnormal_s0_axiom(slop_arena* arena, owl2_RawAxiom ax) {
    {
        __auto_type out = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        slop_option_string fault = (slop_option_string){.has_value = false};
        __auto_type _mv_1151 = ax;
        switch (_mv_1151.tag) {
            case owl2_RawAxiom_ra_sub_class_of:
            {
                __auto_type l = _mv_1151.data.ra_sub_class_of.f0;
                __auto_type r = _mv_1151.data.ra_sub_class_of.f1;
                __auto_type _mv_1152 = sriqnormal_s0_filler(arena, l);
                if (!_mv_1152.is_ok) {
                    __auto_type m = _mv_1152.data.err;
                    fault = (slop_option_string){.has_value = 1, .value = m};
                } else if (_mv_1152.is_ok) {
                    __auto_type lx = _mv_1152.data.ok;
                    __auto_type _mv_1153 = sriqnormal_s0_filler(arena, r);
                    if (!_mv_1153.is_ok) {
                        __auto_type m = _mv_1153.data.err;
                        fault = (slop_option_string){.has_value = 1, .value = m};
                    } else if (_mv_1153.is_ok) {
                        __auto_type rx = _mv_1153.data.ok;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, lx, rx)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case owl2_RawAxiom_ra_equivalent_classes:
            {
                __auto_type cs = _mv_1151.data.ra_equivalent_classes;
                __auto_type _mv_1154 = sriqnormal_s0_concepts(arena, cs);
                if (!_mv_1154.is_ok) {
                    __auto_type m = _mv_1154.data.err;
                    fault = (slop_option_string){.has_value = 1, .value = m};
                } else if (_mv_1154.is_ok) {
                    __auto_type xs = _mv_1154.data.ok;
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
                }
                break;
            }
            case owl2_RawAxiom_ra_disjoint_classes:
            {
                __auto_type cs = _mv_1151.data.ra_disjoint_classes;
                __auto_type _mv_1155 = sriqnormal_s0_concepts(arena, cs);
                if (!_mv_1155.is_ok) {
                    __auto_type m = _mv_1155.data.err;
                    fault = (slop_option_string){.has_value = 1, .value = m};
                } else if (_mv_1155.is_ok) {
                    __auto_type xs = _mv_1155.data.ok;
                    {
                        __auto_type n = ((int64_t)(((int64_t)((xs).len))));
                        int64_t i = 0;
                        while (i < n) {
                            {
                                int64_t j = (i + 1);
                                while (j < n) {
                                    __auto_type _mv_1156 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_sroiq_SConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_1156.has_value) {
                                        __auto_type a = _mv_1156.value;
                                        __auto_type _mv_1157 = ({ __auto_type _lst = xs; size_t _idx = (size_t)j; slop_option_sroiq_SConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                        if (_mv_1157.has_value) {
                                            __auto_type b = _mv_1157.value;
                                            {
                                                __auto_type ab = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                                                ({ __auto_type _lst_p = &(ab); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                ({ __auto_type _lst_p = &(ab); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_and, .data.sc_and = ab }), ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_bottom }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        } else if (!_mv_1157.has_value) {
                                        }
                                    } else if (!_mv_1156.has_value) {
                                    }
                                    j = (j + 1);
                                }
                            }
                            i = (i + 1);
                        }
                    }
                }
                break;
            }
            case owl2_RawAxiom_ra_sub_object_property:
            {
                __auto_type a = _mv_1151.data.ra_sub_object_property.f0;
                __auto_type b = _mv_1151.data.ra_sub_object_property.f1;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_ria1(arena, a, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case owl2_RawAxiom_ra_property_chain:
            {
                __auto_type ch = _mv_1151.data.ra_property_chain;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_ria(arena, ch.steps, ch.super)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case owl2_RawAxiom_ra_equivalent_properties:
            {
                __auto_type rs = _mv_1151.data.ra_equivalent_properties;
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
                break;
            }
            case owl2_RawAxiom_ra_transitive_property:
            {
                __auto_type r = _mv_1151.data.ra_transitive_property;
                {
                    __auto_type w = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    ({ __auto_type _lst_p = &(w); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(w); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_ria(arena, w, r)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                break;
            }
            case owl2_RawAxiom_ra_object_property_domain:
            {
                __auto_type r = _mv_1151.data.ra_object_property_domain.f0;
                __auto_type c = _mv_1151.data.ra_object_property_domain.f1;
                __auto_type _mv_1158 = sriqnormal_s0_filler(arena, c);
                if (!_mv_1158.is_ok) {
                    __auto_type m = _mv_1158.data.err;
                    fault = (slop_option_string){.has_value = 1, .value = m};
                } else if (_mv_1158.is_ok) {
                    __auto_type cx = _mv_1158.data.ok;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = sriqnormal_sc(arena, sriqnormal_top_sc()) } }), cx)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                break;
            }
            case owl2_RawAxiom_ra_object_property_range:
            {
                __auto_type r = _mv_1151.data.ra_object_property_range.f0;
                __auto_type c = _mv_1151.data.ra_object_property_range.f1;
                __auto_type _mv_1159 = sriqnormal_s0_filler(arena, c);
                if (!_mv_1159.is_ok) {
                    __auto_type m = _mv_1159.data.err;
                    fault = (slop_option_string){.has_value = 1, .value = m};
                } else if (_mv_1159.is_ok) {
                    __auto_type cx = _mv_1159.data.ok;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, sriqnormal_top_sc(), ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = sriqnormal_sc(arena, cx) } }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                break;
            }
            case owl2_RawAxiom_ra_class_assertion:
            {
                __auto_type ca = _mv_1151.data.ra_class_assertion;
                __auto_type _mv_1160 = sriqnormal_nominal(ca.subject);
                if (!_mv_1160.has_value) {
                    fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("a class assertion on a non-individual")};
                } else if (_mv_1160.has_value) {
                    __auto_type a = _mv_1160.value;
                    __auto_type _mv_1161 = sriqnormal_s0_filler(arena, ca.concept);
                    if (!_mv_1161.is_ok) {
                        __auto_type m = _mv_1161.data.err;
                        fault = (slop_option_string){.has_value = 1, .value = m};
                    } else if (_mv_1161.is_ok) {
                        __auto_type cx = _mv_1161.data.ok;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, a, cx)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case owl2_RawAxiom_ra_object_property_assertion:
            {
                __auto_type e = _mv_1151.data.ra_object_property_assertion;
                __auto_type _mv_1162 = sriqnormal_nominal(e.from);
                if (!_mv_1162.has_value) {
                    fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("a property assertion from a non-individual")};
                } else if (_mv_1162.has_value) {
                    __auto_type a = _mv_1162.value;
                    __auto_type _mv_1163 = sriqnormal_nominal(e.to);
                    if (!_mv_1163.has_value) {
                        fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("a property assertion to a non-individual")};
                    } else if (_mv_1163.has_value) {
                        __auto_type b = _mv_1163.value;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, a, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_some, .data.sc_some = { .f0 = e.role, .f1 = sriqnormal_sc(arena, b) } }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case owl2_RawAxiom_ra_negative_assertion:
            {
                __auto_type e = _mv_1151.data.ra_negative_assertion;
                __auto_type _mv_1164 = sriqnormal_nominal(e.from);
                if (!_mv_1164.has_value) {
                    fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("a negative assertion from a non-individual")};
                } else if (_mv_1164.has_value) {
                    __auto_type a = _mv_1164.value;
                    __auto_type _mv_1165 = sriqnormal_nominal(e.to);
                    if (!_mv_1165.has_value) {
                        fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("a negative assertion to a non-individual")};
                    } else if (_mv_1165.has_value) {
                        __auto_type b = _mv_1165.value;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, a, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = e.role, .f1 = sriqnormal_sc(arena, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_not, .data.sc_not = sriqnormal_sc(arena, b) })) } }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case owl2_RawAxiom_ra_inverse_properties:
            {
                __auto_type a = _mv_1151.data.ra_inverse_properties.f0;
                __auto_type b = _mv_1151.data.ra_inverse_properties.f1;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_ria1(arena, a, sroiq_inv_role(b))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_ria1(arena, sroiq_inv_role(b), a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case owl2_RawAxiom_ra_property_characteristic:
            {
                __auto_type c = _mv_1151.data.ra_property_characteristic.f0;
                __auto_type r = _mv_1151.data.ra_property_characteristic.f1;
                __auto_type _mv_1166 = c;
                if (_mv_1166 == owl2_PropCharacteristic_prop_functional) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, sriqnormal_top_sc(), ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = 1, .f1 = r, .f2 = sriqnormal_sc(arena, sriqnormal_top_sc()) } }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (_mv_1166 == owl2_PropCharacteristic_prop_inverse_functional) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, sriqnormal_top_sc(), ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = 1, .f1 = sroiq_inv_role(r), .f2 = sriqnormal_sc(arena, sriqnormal_top_sc()) } }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (_mv_1166 == owl2_PropCharacteristic_prop_symmetric) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_ria1(arena, sroiq_inv_role(r), r)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (_mv_1166 == owl2_PropCharacteristic_prop_asymmetric) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_dis, .data.sa_dis = { .f0 = r, .f1 = sroiq_inv_role(r) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (_mv_1166 == owl2_PropCharacteristic_prop_reflexive) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_ref, .data.sa_ref = r })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (_mv_1166 == owl2_PropCharacteristic_prop_irreflexive) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_irr, .data.sa_irr = r })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                break;
            }
            case owl2_RawAxiom_ra_disjoint_properties:
            {
                __auto_type rs = _mv_1151.data.ra_disjoint_properties;
                {
                    __auto_type n = ((int64_t)(((int64_t)((rs).len))));
                    int64_t i = 0;
                    while (i < n) {
                        {
                            int64_t j = (i + 1);
                            while (j < n) {
                                __auto_type _mv_1167 = ({ __auto_type _lst = rs; size_t _idx = (size_t)i; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                if (_mv_1167.has_value) {
                                    __auto_type a = _mv_1167.value;
                                    __auto_type _mv_1168 = ({ __auto_type _lst = rs; size_t _idx = (size_t)j; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_1168.has_value) {
                                        __auto_type b = _mv_1168.value;
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_dis, .data.sa_dis = { .f0 = a, .f1 = b } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_1168.has_value) {
                                    }
                                } else if (!_mv_1167.has_value) {
                                }
                                j = (j + 1);
                            }
                        }
                        i = (i + 1);
                    }
                }
                break;
            }
            case owl2_RawAxiom_ra_same_individual:
            {
                __auto_type ns = _mv_1151.data.ra_same_individual;
                __auto_type _mv_1169 = sriqnormal_least_individual(ns);
                if (!_mv_1169.has_value) {
                    fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("SameIndividual without an individual")};
                } else if (_mv_1169.has_value) {
                    __auto_type h = _mv_1169.value;
                    {
                        __auto_type hub = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_nominal, .data.sc_nominal = h });
                        {
                            __auto_type _coll = ns;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type n = _coll.data[_i];
                                __auto_type _mv_1170 = sriqnormal_nominal(n);
                                if (!_mv_1170.has_value) {
                                    fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("SameIndividual with a non-individual")};
                                } else if (_mv_1170.has_value) {
                                    __auto_type x = _mv_1170.value;
                                    __auto_type _mv_1171 = n;
                                    switch (_mv_1171.tag) {
                                        case types_Node_individual_node:
                                        {
                                            __auto_type i = _mv_1171.data.individual_node;
                                            if (canon_iri_cmp(i, h) != 0) {
                                                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, hub, x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, x, hub)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                    }
                }
                break;
            }
            case owl2_RawAxiom_ra_different_individuals:
            {
                __auto_type ns = _mv_1151.data.ra_different_individuals;
                {
                    __auto_type n = ((int64_t)(((int64_t)((ns).len))));
                    int64_t i = 0;
                    while (i < n) {
                        {
                            int64_t j = (i + 1);
                            while (j < n) {
                                __auto_type _mv_1172 = ({ __auto_type _lst = ns; size_t _idx = (size_t)i; slop_option_types_Node _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                if (_mv_1172.has_value) {
                                    __auto_type a = _mv_1172.value;
                                    __auto_type _mv_1173 = ({ __auto_type _lst = ns; size_t _idx = (size_t)j; slop_option_types_Node _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_1173.has_value) {
                                        __auto_type b = _mv_1173.value;
                                        __auto_type _mv_1174 = sriqnormal_nominal(a);
                                        if (_mv_1174.has_value) {
                                            __auto_type xa = _mv_1174.value;
                                            __auto_type _mv_1175 = sriqnormal_nominal(b);
                                            if (_mv_1175.has_value) {
                                                __auto_type xb = _mv_1175.value;
                                                {
                                                    __auto_type ab = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                                                    ({ __auto_type _lst_p = &(ab); __auto_type _item = (xa); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    ({ __auto_type _lst_p = &(ab); __auto_type _item = (xb); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_and, .data.sc_and = ab }), ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_bottom }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            } else if (!_mv_1175.has_value) {
                                                fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("DifferentIndividuals with a non-individual")};
                                            }
                                        } else if (!_mv_1174.has_value) {
                                            fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("DifferentIndividuals with a non-individual")};
                                        }
                                    } else if (!_mv_1173.has_value) {
                                    }
                                } else if (!_mv_1172.has_value) {
                                }
                                j = (j + 1);
                            }
                        }
                        i = (i + 1);
                    }
                }
                break;
            }
            case owl2_RawAxiom_ra_disjoint_union:
            {
                __auto_type du = _mv_1151.data.ra_disjoint_union;
                __auto_type _mv_1176 = sriqnormal_s0_concepts(arena, du.members);
                if (!_mv_1176.is_ok) {
                    __auto_type m = _mv_1176.data.err;
                    fault = (slop_option_string){.has_value = 1, .value = m};
                } else if (_mv_1176.is_ok) {
                    __auto_type xs = _mv_1176.data.ok;
                    {
                        __auto_type c = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_name, .data.sc_name = du.class });
                        __auto_type uni = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_or, .data.sc_or = xs });
                        __auto_type n = ((int64_t)(((int64_t)((xs).len))));
                        int64_t i = 0;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, c, uni)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, uni, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        while (i < n) {
                            {
                                int64_t j = (i + 1);
                                while (j < n) {
                                    __auto_type _mv_1177 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_sroiq_SConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                    if (_mv_1177.has_value) {
                                        __auto_type a = _mv_1177.value;
                                        __auto_type _mv_1178 = ({ __auto_type _lst = xs; size_t _idx = (size_t)j; slop_option_sroiq_SConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                                        if (_mv_1178.has_value) {
                                            __auto_type b = _mv_1178.value;
                                            {
                                                __auto_type ab = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                                                ({ __auto_type _lst_p = &(ab); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                ({ __auto_type _lst_p = &(ab); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnormal_gci(arena, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_and, .data.sc_and = ab }), ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_bottom }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        } else if (!_mv_1178.has_value) {
                                        }
                                    } else if (!_mv_1177.has_value) {
                                    }
                                    j = (j + 1);
                                }
                            }
                            i = (i + 1);
                        }
                    }
                }
                break;
            }
            case owl2_RawAxiom_ra_declaration:
            {
                __auto_type _ = _mv_1151.data.ra_declaration;
                fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("a declaration reached the normaliser")};
                break;
            }
            case owl2_RawAxiom_ra_annotation:
            {
                fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("an annotation reached the normaliser")};
                break;
            }
            case owl2_RawAxiom_ra_inert_data:
            {
                fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("an inert data axiom reached the normaliser")};
                break;
            }
            case owl2_RawAxiom_ra_has_key:
            {
                __auto_type _ = _mv_1151.data.ra_has_key;
                fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("HasKey, which the sriq gate does not admit")};
                break;
            }
            case owl2_RawAxiom_ra_data_axiom:
            {
                __auto_type _ = _mv_1151.data.ra_data_axiom;
                fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("a data axiom, which the sriq gate does not admit")};
                break;
            }
            case owl2_RawAxiom_ra_builtin_role:
            {
                __auto_type _ = _mv_1151.data.ra_builtin_role;
                fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("a built-in role axiom, which the sriq gate does not admit")};
                break;
            }
            case owl2_RawAxiom_ra_anonymous_individual:
            {
                __auto_type _ = _mv_1151.data.ra_anonymous_individual;
                fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("an anonymous individual, which the sriq gate does not admit")};
                break;
            }
            case owl2_RawAxiom_ra_reserved_vocabulary:
            {
                __auto_type _ = _mv_1151.data.ra_reserved_vocabulary;
                fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("reserved vocabulary, which the sriq gate does not admit")};
                break;
            }
            case owl2_RawAxiom_ra_swrl_rule:
            {
                __auto_type _ = _mv_1151.data.ra_swrl_rule;
                fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("a SWRL rule, which the sriq gate does not admit")};
                break;
            }
            case owl2_RawAxiom_ra_unrecognized:
            {
                __auto_type _ = _mv_1151.data.ra_unrecognized;
                fault = (slop_option_string){.has_value = 1, .value = SLOP_STR("an unrecognized axiom, which the sriq gate does not admit")};
                break;
            }
        }
        __auto_type _mv_1179 = fault;
        if (_mv_1179.has_value) {
            __auto_type m = _mv_1179.value;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = m });
        } else if (!_mv_1179.has_value) {
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = out });
        }
        SLOP_UNREACHABLE();
    }
}

int64_t sriqnormal_rep_at(sriqrbox_SriqRbox rb, int64_t n) {
    __auto_type _mv_1180 = ({ __auto_type _lst = rb.rep; size_t _idx = (size_t)n; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1180.has_value) {
        __auto_type v = _mv_1180.value;
        return v;
    } else if (!_mv_1180.has_value) {
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
    __auto_type _mv_1181 = c;
    switch (_mv_1181.tag) {
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
            __auto_type _ = _mv_1181.data.sc_name;
            return c;
        }
        case sroiq_SConcept_sc_nominal:
        {
            __auto_type _ = _mv_1181.data.sc_nominal;
            return c;
        }
        case sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_1181.data.sc_not;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_not, .data.sc_not = sriqnormal_sc(arena, sriqnormal_collapse_concept(arena, rb, (*f))) });
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_1181.data.sc_and;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_and, .data.sc_and = sriqnormal_collapse_concepts(arena, rb, xs) });
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_1181.data.sc_or;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_or, .data.sc_or = sriqnormal_collapse_concepts(arena, rb, xs) });
        }
        case sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_1181.data.sc_some.f0;
            __auto_type f = _mv_1181.data.sc_some.f1;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_some, .data.sc_some = { .f0 = sriqnormal_collapse_role(rb, r), .f1 = sriqnormal_sc(arena, sriqnormal_collapse_concept(arena, rb, (*f))) } });
        }
        case sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_1181.data.sc_all.f0;
            __auto_type f = _mv_1181.data.sc_all.f1;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = sriqnormal_collapse_role(rb, r), .f1 = sriqnormal_sc(arena, sriqnormal_collapse_concept(arena, rb, (*f))) } });
        }
        case sroiq_SConcept_sc_atleast:
        {
            __auto_type n = _mv_1181.data.sc_atleast.f0;
            __auto_type r = _mv_1181.data.sc_atleast.f1;
            __auto_type f = _mv_1181.data.sc_atleast.f2;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atleast, .data.sc_atleast = { .f0 = n, .f1 = sriqnormal_collapse_role(rb, r), .f2 = sriqnormal_sc(arena, sriqnormal_collapse_concept(arena, rb, (*f))) } });
        }
        case sroiq_SConcept_sc_atmost:
        {
            __auto_type n = _mv_1181.data.sc_atmost.f0;
            __auto_type r = _mv_1181.data.sc_atmost.f1;
            __auto_type f = _mv_1181.data.sc_atmost.f2;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = n, .f1 = sriqnormal_collapse_role(rb, r), .f2 = sriqnormal_sc(arena, sriqnormal_collapse_concept(arena, rb, (*f))) } });
        }
        case sroiq_SConcept_sc_self:
        {
            __auto_type r = _mv_1181.data.sc_self;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_self, .data.sc_self = sriqnormal_collapse_role(rb, r) });
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqnormal_trivial_ria(slop_list_types_RoleId w, types_RoleId s) {
    return ((((int64_t)((w).len)) == 1) && ({ __auto_type _mv = ({ __auto_type _lst = w; size_t _idx = (size_t)0; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type r = _mv.value; sriqnormal_role_eq_p(r, s); }) : (0); }));
}

uint8_t sriqnormal_role_eq_p(types_RoleId a, types_RoleId b) {
    __auto_type _mv_1182 = a;
    switch (_mv_1182.tag) {
        case types_RoleId_named_role:
        {
            __auto_type ia = _mv_1182.data.named_role;
            __auto_type _mv_1183 = b;
            switch (_mv_1183.tag) {
                case types_RoleId_named_role:
                {
                    __auto_type ib = _mv_1183.data.named_role;
                    return (canon_string_cmp(ia.value, ib.value) == 0);
                }
                default: {
                    return 0;
                }
            }
        }
        case types_RoleId_inverse_role:
        {
            __auto_type ia = _mv_1182.data.inverse_role;
            __auto_type _mv_1184 = b;
            switch (_mv_1184.tag) {
                case types_RoleId_inverse_role:
                {
                    __auto_type ib = _mv_1184.data.inverse_role;
                    return (canon_string_cmp(ia.value, ib.value) == 0);
                }
                default: {
                    return 0;
                }
            }
        }
        case types_RoleId_fresh_role:
        {
            __auto_type ka = _mv_1182.data.fresh_role;
            __auto_type _mv_1185 = b;
            switch (_mv_1185.tag) {
                case types_RoleId_fresh_role:
                {
                    __auto_type kb = _mv_1185.data.fresh_role;
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
    __auto_type _mv_1186 = a;
    switch (_mv_1186.tag) {
        case sroiq_SAxiom_sa_gci:
        {
            __auto_type l = _mv_1186.data.sa_gci.f0;
            __auto_type r = _mv_1186.data.sa_gci.f1;
            return (slop_option_sroiq_SAxiom){.has_value = 1, .value = ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_gci, .data.sa_gci = { .f0 = sriqnormal_sc(arena, sroiq_sc_canon(arena, sriqnormal_collapse_concept(arena, rb, (*l)))), .f1 = sriqnormal_sc(arena, sroiq_sc_canon(arena, sriqnormal_collapse_concept(arena, rb, (*r)))) } })};
        }
        case sroiq_SAxiom_sa_ria:
        {
            __auto_type x = _mv_1186.data.sa_ria;
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
            __auto_type r = _mv_1186.data.sa_ref;
            return (slop_option_sroiq_SAxiom){.has_value = 1, .value = ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_ref, .data.sa_ref = sriqnormal_collapse_role(rb, r) })};
        }
        case sroiq_SAxiom_sa_irr:
        {
            __auto_type r = _mv_1186.data.sa_irr;
            return (slop_option_sroiq_SAxiom){.has_value = 1, .value = ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_irr, .data.sa_irr = sriqnormal_collapse_role(rb, r) })};
        }
        case sroiq_SAxiom_sa_dis:
        {
            __auto_type r = _mv_1186.data.sa_dis.f0;
            __auto_type s = _mv_1186.data.sa_dis.f1;
            return (slop_option_sroiq_SAxiom){.has_value = 1, .value = ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_dis, .data.sa_dis = { .f0 = sriqnormal_collapse_role(rb, r), .f1 = sriqnormal_collapse_role(rb, s) } })};
        }
    }
    SLOP_UNREACHABLE();
}

types_RoleId sriqnormal_bottom_role(void) {
    return ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = ((rdf_IRI){.value = vocab_OWL_BOTTOM_OBJECT_PROPERTY}) });
}

uint8_t sriqnormal_is_bottom(types_RoleId r) {
    __auto_type _mv_1187 = r;
    switch (_mv_1187.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_1187.data.named_role;
            return (canon_string_cmp(i.value, vocab_OWL_BOTTOM_OBJECT_PROPERTY) == 0);
        }
        case types_RoleId_inverse_role:
        {
            __auto_type i = _mv_1187.data.inverse_role;
            return (canon_string_cmp(i.value, vocab_OWL_BOTTOM_OBJECT_PROPERTY) == 0);
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_1187.data.fresh_role;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqnormal_concept_bottom_p(sroiq_SConcept c) {
    __auto_type _mv_1188 = c;
    switch (_mv_1188.tag) {
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
            __auto_type _ = _mv_1188.data.sc_name;
            return 0;
        }
        case sroiq_SConcept_sc_nominal:
        {
            __auto_type _ = _mv_1188.data.sc_nominal;
            return 0;
        }
        case sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_1188.data.sc_not;
            return sriqnormal_concept_bottom_p((*f));
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_1188.data.sc_and;
            return sriqnormal_concepts_bottom_p(xs);
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_1188.data.sc_or;
            return sriqnormal_concepts_bottom_p(xs);
        }
        case sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_1188.data.sc_some.f0;
            __auto_type f = _mv_1188.data.sc_some.f1;
            return (sriqnormal_is_bottom(r) || sriqnormal_concept_bottom_p((*f)));
        }
        case sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_1188.data.sc_all.f0;
            __auto_type f = _mv_1188.data.sc_all.f1;
            return (sriqnormal_is_bottom(r) || sriqnormal_concept_bottom_p((*f)));
        }
        case sroiq_SConcept_sc_atleast:
        {
            __auto_type r = _mv_1188.data.sc_atleast.f1;
            __auto_type f = _mv_1188.data.sc_atleast.f2;
            return (sriqnormal_is_bottom(r) || sriqnormal_concept_bottom_p((*f)));
        }
        case sroiq_SConcept_sc_atmost:
        {
            __auto_type r = _mv_1188.data.sc_atmost.f1;
            __auto_type f = _mv_1188.data.sc_atmost.f2;
            return (sriqnormal_is_bottom(r) || sriqnormal_concept_bottom_p((*f)));
        }
        case sroiq_SConcept_sc_self:
        {
            __auto_type r = _mv_1188.data.sc_self;
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
    __auto_type _mv_1189 = a;
    switch (_mv_1189.tag) {
        case sroiq_SAxiom_sa_gci:
        {
            __auto_type l = _mv_1189.data.sa_gci.f0;
            __auto_type r = _mv_1189.data.sa_gci.f1;
            return (sriqnormal_concept_bottom_p((*l)) || sriqnormal_concept_bottom_p((*r)));
        }
        case sroiq_SAxiom_sa_ria:
        {
            __auto_type x = _mv_1189.data.sa_ria;
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
            __auto_type r = _mv_1189.data.sa_ref;
            return sriqnormal_is_bottom(r);
        }
        case sroiq_SAxiom_sa_irr:
        {
            __auto_type r = _mv_1189.data.sa_irr;
            return sriqnormal_is_bottom(r);
        }
        case sroiq_SAxiom_sa_dis:
        {
            __auto_type r = _mv_1189.data.sa_dis.f0;
            __auto_type s = _mv_1189.data.sa_dis.f1;
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
                __auto_type _mv_1190 = sriqnormal_s0_axiom(arena, ax);
                if (!_mv_1190.is_ok) {
                    __auto_type m = _mv_1190.data.err;
                    fault = (slop_option_string){.has_value = 1, .value = m};
                } else if (_mv_1190.is_ok) {
                    __auto_type xs = _mv_1190.data.ok;
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
                __auto_type _mv_1191 = sriqnormal_collapse_axiom(arena, rb, a);
                if (_mv_1191.has_value) {
                    __auto_type c = _mv_1191.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1191.has_value) {
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
        __auto_type _mv_1192 = fault;
        if (_mv_1192.has_value) {
            __auto_type m = _mv_1192.value;
            return ((slop_result_sriqnormal_S0_string){ .is_ok = false, .data.err = m });
        } else if (!_mv_1192.has_value) {
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
                __auto_type _mv_1193 = ({ __auto_type _lst = rb.nonsimple; size_t _idx = (size_t)n; slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1193.has_value) {
                    __auto_type v = _mv_1193.value;
                    return v;
                } else if (!_mv_1193.has_value) {
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
                __auto_type _mv_1194 = a;
                switch (_mv_1194.tag) {
                    case sroiq_SAxiom_sa_ria:
                    {
                        __auto_type x = _mv_1194.data.sa_ria;
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
        __auto_type _mv_1195 = first;
        if (!_mv_1195.has_value) {
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = true, .data.ok = s0.axioms });
        } else if (_mv_1195.has_value) {
            __auto_type a = _mv_1195.value;
            return ((slop_result_list_sroiq_SAxiom_string){ .is_ok = false, .data.err = string_concat(arena, SLOP_STR("complex role inclusions need chain elimination (SPEC 5.5 S1), not yet built; first: "), sroiq_render_saxiom(arena, a)) });
        }
        SLOP_UNREACHABLE();
    }
}

