#include "../runtime/slop_runtime.h"
#include "slop_ksc.h"

uint8_t ksc_is_name(types_KTerm t, types_KName n);
uint8_t ksc_is_nominal(types_KTerm t);
uint8_t ksc_is_individual(types_KElem x);
types_KElem ksc_term_elem(types_KTerm t);
uint8_t ksc_concl_eq(ksc_Concl a, ksc_Concl b);
rdf_IRI ksc_ex_a(void);
rdf_IRI ksc_ex_b(void);
types_KName ksc_ex_A(void);
types_KName ksc_ex_B(void);
types_KName ksc_ex_C(void);
types_RoleId ksc_ex_r(void);
types_RoleId ksc_ex_s(void);
types_RoleId ksc_ex_t(void);
types_KElem ksc_ex_x(void);
types_KElem ksc_ex_w(void);
types_KElem ksc_ex_ia(void);
types_KTerm ksc_ex_tA(void);
types_KTerm ksc_ex_tB(void);
types_KTerm ksc_ex_tC(void);
types_KTerm ksc_ex_na(void);
ksc_Concl ksc_ksc_1(rdf_IRI a);
ksc_Concl ksc_ksc_q(types_KName q);
ksc_Concl ksc_ksc_2(types_KElem x, types_RoleId v, types_KElem x1);
ksc_Concl ksc_ksc_3(types_KElem x, types_KTerm y);
uint8_t ksc_ksc_4(types_KElem u, types_KTerm z);
ksc_Concl ksc_ksc_5(types_KTerm sy, types_KTerm sz, types_KElem x, types_KTerm y);
ksc_Concl ksc_ksc_6(types_KName a, types_KName b, types_KName z, types_KElem x, types_KTerm y1, types_KElem x2, types_KTerm y2);
ksc_Concl ksc_ksc_7(types_RoleId v, types_KName a, types_KName z, types_KElem x, types_RoleId v1, types_KElem x1, types_KElem x2, types_KTerm y);
ksc_Concl ksc_ksc_8(types_RoleId v, types_KName a, types_KName z, types_KElem x, types_RoleId v1, types_KElem x2, types_KTerm y);
ksc_Concl ksc_ksc_9(types_KName a, types_RoleId v, types_KName b, int64_t w, types_KElem x, types_KTerm y);
ksc_Concl ksc_ksc_9_assert(rdf_IRI a, types_RoleId v, rdf_IRI b, types_KElem x, types_KTerm y);
ksc_Concl ksc_ksc_10(types_KName a, types_RoleId v, types_KName b, int64_t w, types_KElem x, types_KTerm y);
ksc_Concl ksc_ksc_10_assert(rdf_IRI a, types_RoleId v, rdf_IRI b, types_KElem x, types_KTerm y);
ksc_Concl ksc_ksc_11(types_RoleId v, types_KName z, types_KElem x, types_RoleId v1);
ksc_Concl ksc_ksc_12(types_KName a, types_RoleId v, types_KElem x, types_KTerm y);
ksc_Concl ksc_ksc_13(types_RoleId v, types_RoleId w, types_KElem x, types_RoleId v1, types_KElem x1);
ksc_Concl ksc_ksc_14(types_RoleId v, types_RoleId w, types_KElem x, types_RoleId v1);
ksc_Concl ksc_ksc_15(types_RoleId u, types_RoleId v, types_RoleId w, types_KElem x, types_RoleId u1, types_KElem x1, types_KElem x2, types_RoleId v1, types_KElem x3);
ksc_Concl ksc_ksc_16(types_RoleId u, types_RoleId v, types_RoleId w, types_KElem x, types_RoleId u1, types_KElem x2, types_RoleId v1, types_KElem x3);
ksc_Concl ksc_ksc_17(types_RoleId u, types_RoleId v, types_RoleId w, types_KElem x, types_RoleId u1, types_KElem x1, types_KElem x2, types_RoleId v1);
ksc_Concl ksc_ksc_18(types_RoleId u, types_RoleId v, types_RoleId w, types_KElem x, types_RoleId u1, types_KElem x2, types_RoleId v1);
ksc_Concl ksc_ksc_23(types_RoleId v, types_KName d, types_KElem x, types_RoleId v1, types_KElem x1);
ksc_Concl ksc_ksc_24(types_RoleId v, types_KName d, types_KElem x, types_RoleId v1);
ksc_Concl ksc_ksc_25(types_RoleId v, types_KName d, types_KElem x, types_RoleId v1, types_KElem x1);
ksc_Concl ksc_ksc_26(types_RoleId v, types_KName d, types_KElem x, types_RoleId v1);
ksc_Concl ksc_ksc_27(types_KElem x, types_KTerm y, types_KElem x2, types_KTerm z);
ksc_Concl ksc_ksc_28(types_KElem x, types_KTerm y, types_KElem x2, types_KTerm z);
ksc_Concl ksc_ksc_29(types_KElem x, types_KTerm y, types_KElem z, types_RoleId u, types_KElem x2);
ksc_Concl ksc_join_trigger_fails(types_KFact t);
ksc_Concl ksc_join_instance(ksc_JoinRule tag, types_KFact t, types_KFact p, types_KscAxiom ax);
slop_option_types_KFact ksc_join_conclusion(ksc_JoinRule tag, types_KFact t, types_KFact p, types_KscAxiom ax);
slop_list_types_KFact ksc_ksc_join(slop_arena* arena, ksc_JoinRule tag, types_KFact t, slop_list_types_KFact ps, types_KscAxiom ax);
uint8_t ksc_ref_add(slop_arena* arena, slop_map* seen, ksc_Concl c);
slop_list_types_KName ksc_ref_names(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes);
slop_list_types_KName ksc_axiom_names(slop_arena* arena, types_KscAxiom ax);
slop_list_rdf_IRI ksc_ref_individuals(slop_arena* arena, slop_list_types_KscAxiom axioms);
slop_list_ksc_Concl ksc_ref_unary(slop_arena* arena, types_KFact f, types_KscAxiom ax);
slop_list_ksc_Concl ksc_ref_binary(slop_arena* arena, types_KFact f1, types_KFact f2, types_KscAxiom ax);
slop_list_ksc_Concl ksc_ref_equality(slop_arena* arena, types_KFact f1, types_KFact f2);
slop_list_types_KFact ksc_reference_closure(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_option_types_KName q, slop_list_types_KName classes);
uint8_t ksc_reference_answer(slop_list_types_KFact facts, types_KName q, types_KName b);

uint8_t ksc_is_name(types_KTerm t, types_KName n) {
    __auto_type _mv_444 = t;
    switch (_mv_444.tag) {
        case types_KTerm_k_name:
        {
            __auto_type m = _mv_444.data.k_name;
            return types_kname_eq(m, n);
        }
        case types_KTerm_k_nominal:
        {
            __auto_type _ = _mv_444.data.k_nominal;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t ksc_is_nominal(types_KTerm t) {
    __auto_type _mv_445 = t;
    switch (_mv_445.tag) {
        case types_KTerm_k_nominal:
        {
            __auto_type _ = _mv_445.data.k_nominal;
            return 1;
        }
        case types_KTerm_k_name:
        {
            __auto_type _ = _mv_445.data.k_name;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t ksc_is_individual(types_KElem x) {
    __auto_type _mv_446 = x;
    switch (_mv_446.tag) {
        case types_KElem_e_ind:
        {
            __auto_type _ = _mv_446.data.e_ind;
            return 1;
        }
        case types_KElem_e_aux:
        {
            __auto_type _ = _mv_446.data.e_aux;
            return 0;
        }
        case types_KElem_e_class:
        {
            __auto_type _ = _mv_446.data.e_class;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

types_KElem ksc_term_elem(types_KTerm t) {
    __auto_type _mv_447 = t;
    switch (_mv_447.tag) {
        case types_KTerm_k_nominal:
        {
            __auto_type a = _mv_447.data.k_nominal;
            return types_ind_elem(a);
        }
        case types_KTerm_k_name:
        {
            __auto_type n = _mv_447.data.k_name;
            return types_class_elem(n);
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t ksc_concl_eq(ksc_Concl a, ksc_Concl b) {
    if (a.fires == b.fires) {
        return types_kfact_eq(a.fact, b.fact);
    } else {
        return 0;
    }
}

rdf_IRI ksc_ex_a(void) {
    return ((rdf_IRI){.value = SLOP_STR("http://example.org/a")});
}

rdf_IRI ksc_ex_b(void) {
    return ((rdf_IRI){.value = SLOP_STR("http://example.org/b")});
}

types_KName ksc_ex_A(void) {
    return ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = SLOP_STR("http://example.org/A")}) });
}

types_KName ksc_ex_B(void) {
    return ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = SLOP_STR("http://example.org/B")}) });
}

types_KName ksc_ex_C(void) {
    return ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = SLOP_STR("http://example.org/C")}) });
}

types_RoleId ksc_ex_r(void) {
    return ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = ((rdf_IRI){.value = SLOP_STR("http://example.org/r")}) });
}

types_RoleId ksc_ex_s(void) {
    return ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = ((rdf_IRI){.value = SLOP_STR("http://example.org/s")}) });
}

types_RoleId ksc_ex_t(void) {
    return ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = ((rdf_IRI){.value = SLOP_STR("http://example.org/t")}) });
}

types_KElem ksc_ex_x(void) {
    return types_class_elem(ksc_ex_A());
}

types_KElem ksc_ex_w(void) {
    return types_aux_elem(0);
}

types_KElem ksc_ex_ia(void) {
    return types_ind_elem(ksc_ex_a());
}

types_KTerm ksc_ex_tA(void) {
    return types_name_term(ksc_ex_A());
}

types_KTerm ksc_ex_tB(void) {
    return types_name_term(ksc_ex_B());
}

types_KTerm ksc_ex_tC(void) {
    return types_name_term(ksc_ex_C());
}

types_KTerm ksc_ex_na(void) {
    return types_nominal_term(ksc_ex_a());
}

ksc_Concl ksc_ksc_1(rdf_IRI a) {
    return ((ksc_Concl){.fires = 1, .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = types_ind_elem(a), .f1 = types_nominal_term(a) } })});
}

ksc_Concl ksc_ksc_q(types_KName q) {
    return ((ksc_Concl){.fires = 1, .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = types_class_elem(q), .f1 = types_name_term(q) } })});
}

ksc_Concl ksc_ksc_2(types_KElem x, types_RoleId v, types_KElem x1) {
    {
        __auto_type fire = ((ksc_is_individual(x)) ? types_kelem_eq(x, x1) : 0);
        return ((ksc_Concl){.fires = fire, .fact = ((types_KFact){ .tag = types_KFact_f_self, .data.f_self = { .f0 = x, .f1 = v } })});
    }
}

ksc_Concl ksc_ksc_3(types_KElem x, types_KTerm y) {
    return ((ksc_Concl){.fires = 1, .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = types_thing_term() } })});
}

uint8_t ksc_ksc_4(types_KElem u, types_KTerm z) {
    uint8_t _retval = {0};
    _retval = types_kterm_eq(z, types_nothing_term());
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval == types_kterm_eq(z, types_nothing_term()))), "(== $result (kterm-eq z (nothing-term)))");
    return _retval;
}

ksc_Concl ksc_ksc_5(types_KTerm sy, types_KTerm sz, types_KElem x, types_KTerm y) {
    return ((ksc_Concl){.fires = types_kterm_eq(sy, y), .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = sz } })});
}

ksc_Concl ksc_ksc_6(types_KName a, types_KName b, types_KName z, types_KElem x, types_KTerm y1, types_KElem x2, types_KTerm y2) {
    {
        __auto_type fire = ((ksc_is_name(y1, a)) ? ((types_kelem_eq(x, x2)) ? ksc_is_name(y2, b) : 0) : 0);
        return ((ksc_Concl){.fires = fire, .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = types_name_term(z) } })});
    }
}

ksc_Concl ksc_ksc_7(types_RoleId v, types_KName a, types_KName z, types_KElem x, types_RoleId v1, types_KElem x1, types_KElem x2, types_KTerm y) {
    {
        __auto_type fire = ((types_role_eq(v, v1)) ? ((types_kelem_eq(x1, x2)) ? ksc_is_name(y, a) : 0) : 0);
        return ((ksc_Concl){.fires = fire, .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = types_name_term(z) } })});
    }
}

ksc_Concl ksc_ksc_8(types_RoleId v, types_KName a, types_KName z, types_KElem x, types_RoleId v1, types_KElem x2, types_KTerm y) {
    {
        __auto_type fire = ((types_role_eq(v, v1)) ? ((types_kelem_eq(x, x2)) ? ksc_is_name(y, a) : 0) : 0);
        return ((ksc_Concl){.fires = fire, .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = types_name_term(z) } })});
    }
}

ksc_Concl ksc_ksc_9(types_KName a, types_RoleId v, types_KName b, int64_t w, types_KElem x, types_KTerm y) {
    return ((ksc_Concl){.fires = ksc_is_name(y, a), .fact = ((types_KFact){ .tag = types_KFact_f_triple, .data.f_triple = { .f0 = x, .f1 = v, .f2 = types_aux_elem(w) } })});
}

ksc_Concl ksc_ksc_9_assert(rdf_IRI a, types_RoleId v, rdf_IRI b, types_KElem x, types_KTerm y) {
    return ((ksc_Concl){.fires = types_kterm_eq(y, types_nominal_term(a)), .fact = ((types_KFact){ .tag = types_KFact_f_triple, .data.f_triple = { .f0 = x, .f1 = v, .f2 = types_ind_elem(b) } })});
}

ksc_Concl ksc_ksc_10(types_KName a, types_RoleId v, types_KName b, int64_t w, types_KElem x, types_KTerm y) {
    return ((ksc_Concl){.fires = ksc_is_name(y, a), .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = types_aux_elem(w), .f1 = types_name_term(b) } })});
}

ksc_Concl ksc_ksc_10_assert(rdf_IRI a, types_RoleId v, rdf_IRI b, types_KElem x, types_KTerm y) {
    return ((ksc_Concl){.fires = types_kterm_eq(y, types_nominal_term(a)), .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = types_ind_elem(b), .f1 = types_nominal_term(b) } })});
}

ksc_Concl ksc_ksc_11(types_RoleId v, types_KName z, types_KElem x, types_RoleId v1) {
    return ((ksc_Concl){.fires = types_role_eq(v, v1), .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = types_name_term(z) } })});
}

ksc_Concl ksc_ksc_12(types_KName a, types_RoleId v, types_KElem x, types_KTerm y) {
    return ((ksc_Concl){.fires = ksc_is_name(y, a), .fact = ((types_KFact){ .tag = types_KFact_f_self, .data.f_self = { .f0 = x, .f1 = v } })});
}

ksc_Concl ksc_ksc_13(types_RoleId v, types_RoleId w, types_KElem x, types_RoleId v1, types_KElem x1) {
    return ((ksc_Concl){.fires = types_role_eq(v, v1), .fact = ((types_KFact){ .tag = types_KFact_f_triple, .data.f_triple = { .f0 = x, .f1 = w, .f2 = x1 } })});
}

ksc_Concl ksc_ksc_14(types_RoleId v, types_RoleId w, types_KElem x, types_RoleId v1) {
    return ((ksc_Concl){.fires = types_role_eq(v, v1), .fact = ((types_KFact){ .tag = types_KFact_f_self, .data.f_self = { .f0 = x, .f1 = w } })});
}

ksc_Concl ksc_ksc_15(types_RoleId u, types_RoleId v, types_RoleId w, types_KElem x, types_RoleId u1, types_KElem x1, types_KElem x2, types_RoleId v1, types_KElem x3) {
    {
        __auto_type fire = ((types_role_eq(u, u1)) ? ((types_kelem_eq(x1, x2)) ? types_role_eq(v, v1) : 0) : 0);
        return ((ksc_Concl){.fires = fire, .fact = ((types_KFact){ .tag = types_KFact_f_triple, .data.f_triple = { .f0 = x, .f1 = w, .f2 = x3 } })});
    }
}

ksc_Concl ksc_ksc_16(types_RoleId u, types_RoleId v, types_RoleId w, types_KElem x, types_RoleId u1, types_KElem x2, types_RoleId v1, types_KElem x3) {
    {
        __auto_type fire = ((types_role_eq(u, u1)) ? ((types_kelem_eq(x, x2)) ? types_role_eq(v, v1) : 0) : 0);
        return ((ksc_Concl){.fires = fire, .fact = ((types_KFact){ .tag = types_KFact_f_triple, .data.f_triple = { .f0 = x, .f1 = w, .f2 = x3 } })});
    }
}

ksc_Concl ksc_ksc_17(types_RoleId u, types_RoleId v, types_RoleId w, types_KElem x, types_RoleId u1, types_KElem x1, types_KElem x2, types_RoleId v1) {
    {
        __auto_type fire = ((types_role_eq(u, u1)) ? ((types_kelem_eq(x1, x2)) ? types_role_eq(v, v1) : 0) : 0);
        return ((ksc_Concl){.fires = fire, .fact = ((types_KFact){ .tag = types_KFact_f_triple, .data.f_triple = { .f0 = x, .f1 = w, .f2 = x1 } })});
    }
}

ksc_Concl ksc_ksc_18(types_RoleId u, types_RoleId v, types_RoleId w, types_KElem x, types_RoleId u1, types_KElem x2, types_RoleId v1) {
    {
        __auto_type fire = ((types_role_eq(u, u1)) ? ((types_kelem_eq(x, x2)) ? types_role_eq(v, v1) : 0) : 0);
        return ((ksc_Concl){.fires = fire, .fact = ((types_KFact){ .tag = types_KFact_f_triple, .data.f_triple = { .f0 = x, .f1 = w, .f2 = x } })});
    }
}

ksc_Concl ksc_ksc_23(types_RoleId v, types_KName d, types_KElem x, types_RoleId v1, types_KElem x1) {
    return ((ksc_Concl){.fires = types_role_eq(v, v1), .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = types_thing_term() } })});
}

ksc_Concl ksc_ksc_24(types_RoleId v, types_KName d, types_KElem x, types_RoleId v1) {
    return ((ksc_Concl){.fires = types_role_eq(v, v1), .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = types_thing_term() } })});
}

ksc_Concl ksc_ksc_25(types_RoleId v, types_KName d, types_KElem x, types_RoleId v1, types_KElem x1) {
    return ((ksc_Concl){.fires = types_role_eq(v, v1), .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x1, .f1 = types_name_term(d) } })});
}

ksc_Concl ksc_ksc_26(types_RoleId v, types_KName d, types_KElem x, types_RoleId v1) {
    return ((ksc_Concl){.fires = types_role_eq(v, v1), .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = types_name_term(d) } })});
}

ksc_Concl ksc_ksc_27(types_KElem x, types_KTerm y, types_KElem x2, types_KTerm z) {
    {
        __auto_type fire = ((ksc_is_nominal(y)) ? types_kelem_eq(x, x2) : 0);
        return ((ksc_Concl){.fires = fire, .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = ksc_term_elem(y), .f1 = z } })});
    }
}

ksc_Concl ksc_ksc_28(types_KElem x, types_KTerm y, types_KElem x2, types_KTerm z) {
    {
        __auto_type fire = ((ksc_is_nominal(y)) ? types_kelem_eq(ksc_term_elem(y), x2) : 0);
        return ((ksc_Concl){.fires = fire, .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = z } })});
    }
}

ksc_Concl ksc_ksc_29(types_KElem x, types_KTerm y, types_KElem z, types_RoleId u, types_KElem x2) {
    {
        __auto_type fire = ((ksc_is_nominal(y)) ? types_kelem_eq(x, x2) : 0);
        return ((ksc_Concl){.fires = fire, .fact = ((types_KFact){ .tag = types_KFact_f_triple, .data.f_triple = { .f0 = z, .f1 = u, .f2 = ksc_term_elem(y) } })});
    }
}

ksc_Concl ksc_join_trigger_fails(types_KFact t) {
    return ((ksc_Concl){.fires = 0, .fact = t});
}

ksc_Concl ksc_join_instance(ksc_JoinRule tag, types_KFact t, types_KFact p, types_KscAxiom ax) {
    __auto_type _mv_448 = tag;
    if (_mv_448 == ksc_JoinRule_j7_inst) {
        __auto_type _mv_449 = ax;
        switch (_mv_449.tag) {
            case types_KscAxiom_k_some_lhs:
            {
                __auto_type v = _mv_449.data.k_some_lhs.f0;
                __auto_type a = _mv_449.data.k_some_lhs.f1;
                __auto_type z = _mv_449.data.k_some_lhs.f2;
                __auto_type _mv_450 = p;
                switch (_mv_450.tag) {
                    case types_KFact_f_triple:
                    {
                        __auto_type x = _mv_450.data.f_triple.f0;
                        __auto_type v1 = _mv_450.data.f_triple.f1;
                        __auto_type x1 = _mv_450.data.f_triple.f2;
                        __auto_type _mv_451 = t;
                        switch (_mv_451.tag) {
                            case types_KFact_f_inst:
                            {
                                __auto_type x2 = _mv_451.data.f_inst.f0;
                                __auto_type y = _mv_451.data.f_inst.f1;
                                return ksc_ksc_7(v, a, z, x, v1, x1, x2, y);
                            }
                            default: {
                                return ksc_join_trigger_fails(t);
                            }
                        }
                    }
                    default: {
                        return ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_448 == ksc_JoinRule_j15_first) {
        __auto_type _mv_452 = ax;
        switch (_mv_452.tag) {
            case types_KscAxiom_k_chain:
            {
                __auto_type u = _mv_452.data.k_chain.f0;
                __auto_type v = _mv_452.data.k_chain.f1;
                __auto_type w = _mv_452.data.k_chain.f2;
                __auto_type _mv_453 = t;
                switch (_mv_453.tag) {
                    case types_KFact_f_triple:
                    {
                        __auto_type x = _mv_453.data.f_triple.f0;
                        __auto_type u1 = _mv_453.data.f_triple.f1;
                        __auto_type x1 = _mv_453.data.f_triple.f2;
                        __auto_type _mv_454 = p;
                        switch (_mv_454.tag) {
                            case types_KFact_f_triple:
                            {
                                __auto_type x2 = _mv_454.data.f_triple.f0;
                                __auto_type v1 = _mv_454.data.f_triple.f1;
                                __auto_type x3 = _mv_454.data.f_triple.f2;
                                return ksc_ksc_15(u, v, w, x, u1, x1, x2, v1, x3);
                            }
                            default: {
                                return ksc_join_trigger_fails(t);
                            }
                        }
                    }
                    default: {
                        return ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_448 == ksc_JoinRule_j15_second) {
        __auto_type _mv_455 = ax;
        switch (_mv_455.tag) {
            case types_KscAxiom_k_chain:
            {
                __auto_type u = _mv_455.data.k_chain.f0;
                __auto_type v = _mv_455.data.k_chain.f1;
                __auto_type w = _mv_455.data.k_chain.f2;
                __auto_type _mv_456 = p;
                switch (_mv_456.tag) {
                    case types_KFact_f_triple:
                    {
                        __auto_type x = _mv_456.data.f_triple.f0;
                        __auto_type u1 = _mv_456.data.f_triple.f1;
                        __auto_type x1 = _mv_456.data.f_triple.f2;
                        __auto_type _mv_457 = t;
                        switch (_mv_457.tag) {
                            case types_KFact_f_triple:
                            {
                                __auto_type x2 = _mv_457.data.f_triple.f0;
                                __auto_type v1 = _mv_457.data.f_triple.f1;
                                __auto_type x3 = _mv_457.data.f_triple.f2;
                                return ksc_ksc_15(u, v, w, x, u1, x1, x2, v1, x3);
                            }
                            default: {
                                return ksc_join_trigger_fails(t);
                            }
                        }
                    }
                    default: {
                        return ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_448 == ksc_JoinRule_j16_self) {
        __auto_type _mv_458 = ax;
        switch (_mv_458.tag) {
            case types_KscAxiom_k_chain:
            {
                __auto_type u = _mv_458.data.k_chain.f0;
                __auto_type v = _mv_458.data.k_chain.f1;
                __auto_type w = _mv_458.data.k_chain.f2;
                __auto_type _mv_459 = t;
                switch (_mv_459.tag) {
                    case types_KFact_f_self:
                    {
                        __auto_type x = _mv_459.data.f_self.f0;
                        __auto_type u1 = _mv_459.data.f_self.f1;
                        __auto_type _mv_460 = p;
                        switch (_mv_460.tag) {
                            case types_KFact_f_triple:
                            {
                                __auto_type x2 = _mv_460.data.f_triple.f0;
                                __auto_type v1 = _mv_460.data.f_triple.f1;
                                __auto_type x3 = _mv_460.data.f_triple.f2;
                                return ksc_ksc_16(u, v, w, x, u1, x2, v1, x3);
                            }
                            default: {
                                return ksc_join_trigger_fails(t);
                            }
                        }
                    }
                    default: {
                        return ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_448 == ksc_JoinRule_j17_self) {
        __auto_type _mv_461 = ax;
        switch (_mv_461.tag) {
            case types_KscAxiom_k_chain:
            {
                __auto_type u = _mv_461.data.k_chain.f0;
                __auto_type v = _mv_461.data.k_chain.f1;
                __auto_type w = _mv_461.data.k_chain.f2;
                __auto_type _mv_462 = p;
                switch (_mv_462.tag) {
                    case types_KFact_f_triple:
                    {
                        __auto_type x = _mv_462.data.f_triple.f0;
                        __auto_type u1 = _mv_462.data.f_triple.f1;
                        __auto_type x1 = _mv_462.data.f_triple.f2;
                        __auto_type _mv_463 = t;
                        switch (_mv_463.tag) {
                            case types_KFact_f_self:
                            {
                                __auto_type x2 = _mv_463.data.f_self.f0;
                                __auto_type v1 = _mv_463.data.f_self.f1;
                                return ksc_ksc_17(u, v, w, x, u1, x1, x2, v1);
                            }
                            default: {
                                return ksc_join_trigger_fails(t);
                            }
                        }
                    }
                    default: {
                        return ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_448 == ksc_JoinRule_j27_nom) {
        __auto_type _mv_464 = t;
        switch (_mv_464.tag) {
            case types_KFact_f_inst:
            {
                __auto_type x = _mv_464.data.f_inst.f0;
                __auto_type y = _mv_464.data.f_inst.f1;
                __auto_type _mv_465 = p;
                switch (_mv_465.tag) {
                    case types_KFact_f_inst:
                    {
                        __auto_type x2 = _mv_465.data.f_inst.f0;
                        __auto_type z = _mv_465.data.f_inst.f1;
                        return ksc_ksc_27(x, y, x2, z);
                    }
                    default: {
                        return ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_448 == ksc_JoinRule_j27_other) {
        __auto_type _mv_466 = p;
        switch (_mv_466.tag) {
            case types_KFact_f_inst:
            {
                __auto_type x = _mv_466.data.f_inst.f0;
                __auto_type y = _mv_466.data.f_inst.f1;
                __auto_type _mv_467 = t;
                switch (_mv_467.tag) {
                    case types_KFact_f_inst:
                    {
                        __auto_type x2 = _mv_467.data.f_inst.f0;
                        __auto_type z = _mv_467.data.f_inst.f1;
                        return ksc_ksc_27(x, y, x2, z);
                    }
                    default: {
                        return ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_448 == ksc_JoinRule_j28_nom) {
        __auto_type _mv_468 = t;
        switch (_mv_468.tag) {
            case types_KFact_f_inst:
            {
                __auto_type x = _mv_468.data.f_inst.f0;
                __auto_type y = _mv_468.data.f_inst.f1;
                __auto_type _mv_469 = p;
                switch (_mv_469.tag) {
                    case types_KFact_f_inst:
                    {
                        __auto_type x2 = _mv_469.data.f_inst.f0;
                        __auto_type z = _mv_469.data.f_inst.f1;
                        return ksc_ksc_28(x, y, x2, z);
                    }
                    default: {
                        return ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_448 == ksc_JoinRule_j28_ind) {
        __auto_type _mv_470 = p;
        switch (_mv_470.tag) {
            case types_KFact_f_inst:
            {
                __auto_type x = _mv_470.data.f_inst.f0;
                __auto_type y = _mv_470.data.f_inst.f1;
                __auto_type _mv_471 = t;
                switch (_mv_471.tag) {
                    case types_KFact_f_inst:
                    {
                        __auto_type x2 = _mv_471.data.f_inst.f0;
                        __auto_type z = _mv_471.data.f_inst.f1;
                        return ksc_ksc_28(x, y, x2, z);
                    }
                    default: {
                        return ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_448 == ksc_JoinRule_j29_nom) {
        __auto_type _mv_472 = t;
        switch (_mv_472.tag) {
            case types_KFact_f_inst:
            {
                __auto_type x = _mv_472.data.f_inst.f0;
                __auto_type y = _mv_472.data.f_inst.f1;
                __auto_type _mv_473 = p;
                switch (_mv_473.tag) {
                    case types_KFact_f_triple:
                    {
                        __auto_type z = _mv_473.data.f_triple.f0;
                        __auto_type u = _mv_473.data.f_triple.f1;
                        __auto_type x2 = _mv_473.data.f_triple.f2;
                        return ksc_ksc_29(x, y, z, u, x2);
                    }
                    default: {
                        return ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_448 == ksc_JoinRule_j29_triple) {
        __auto_type _mv_474 = p;
        switch (_mv_474.tag) {
            case types_KFact_f_inst:
            {
                __auto_type x = _mv_474.data.f_inst.f0;
                __auto_type y = _mv_474.data.f_inst.f1;
                __auto_type _mv_475 = t;
                switch (_mv_475.tag) {
                    case types_KFact_f_triple:
                    {
                        __auto_type z = _mv_475.data.f_triple.f0;
                        __auto_type u = _mv_475.data.f_triple.f1;
                        __auto_type x2 = _mv_475.data.f_triple.f2;
                        return ksc_ksc_29(x, y, z, u, x2);
                    }
                    default: {
                        return ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return ksc_join_trigger_fails(t);
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_option_types_KFact ksc_join_conclusion(ksc_JoinRule tag, types_KFact t, types_KFact p, types_KscAxiom ax) {
    slop_option_types_KFact _retval = {0};
    {
        __auto_type c = ksc_join_instance(tag, t, p, ax);
        if (c.fires) {
            _retval = (slop_option_types_KFact){.has_value = 1, .value = c.fact};
            goto _slop_post;
        } else {
            _retval = (slop_option_types_KFact){.has_value = false};
            goto _slop_post;
        }
    }
    _slop_post: ;
    SLOP_POST((({ __auto_type _mv = _retval; _mv.has_value ? ({ __auto_type c = _mv.value; ((ksc_join_instance(tag, t, p, ax).fires == 1) && ({ types_KFact _eq_l_476 = (ksc_join_instance(tag, t, p, ax).fact); types_KFact _eq_r_477 = (c); slop_eq_types_KFact(&_eq_l_476, &_eq_r_477); })); }) : ((ksc_join_instance(tag, t, p, ax).fires == 0)); })), "(match $result ((some c) (and (== (. (join-instance tag t p ax) fires) true) (== (. (join-instance tag t p ax) fact) c))) ((none) (== (. (join-instance tag t p ax) fires) false)))");
    return _retval;
}

slop_list_types_KFact ksc_ksc_join(slop_arena* arena, ksc_JoinRule tag, types_KFact t, slop_list_types_KFact ps, types_KscAxiom ax) {
    slop_list_types_KFact _retval = {0};
    {
        __auto_type result = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                __auto_type _mv_478 = ksc_join_conclusion(tag, t, q, ax);
                if (_mv_478.has_value) {
                    __auto_type c = _mv_478.value;
                    ({ __auto_type _lst_p = &(result); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_478.has_value) {
                }
            }
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

uint8_t ksc_ref_add(slop_arena* arena, slop_map* seen, ksc_Concl c) {
    if (c.fires == 1) {
        if (slop_map_has(seen, &(c.fact))) {
            return 0;
        } else {
            ({ slop_map_put(arena, seen, &(c.fact), NULL, 0); });
            return 1;
        }
    } else {
        return 0;
    }
}

slop_list_types_KName ksc_ref_names(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes) {
    {
        __auto_type out = ((slop_list_types_KName){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_KName, slop_hash_types_KName, slop_eq_types_KName, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                if (!(slop_map_has(seen, &(n)))) {
                    ({ slop_map_put(arena, seen, &(n), NULL, 0); });
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type t = ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = vocab_OWL_THING}) });
            __auto_type b = ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = vocab_OWL_NOTHING}) });
            if (!(slop_map_has(seen, &(t)))) {
                ({ slop_map_put(arena, seen, &(t), NULL, 0); });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
            if (!(slop_map_has(seen, &(b)))) {
                ({ slop_map_put(arena, seen, &(b), NULL, 0); });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                {
                    __auto_type _coll = ksc_axiom_names(arena, ax);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type n = _coll.data[_i];
                        if (!(slop_map_has(seen, &(n)))) {
                            ({ slop_map_put(arena, seen, &(n), NULL, 0); });
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        return out;
    }
}

slop_list_types_KName ksc_axiom_names(slop_arena* arena, types_KscAxiom ax) {
    {
        __auto_type out = ((slop_list_types_KName){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_489 = ax;
        switch (_mv_489.tag) {
            case types_KscAxiom_k_sub:
            {
                __auto_type y = _mv_489.data.k_sub.f0;
                __auto_type z = _mv_489.data.k_sub.f1;
                __auto_type _mv_490 = y;
                switch (_mv_490.tag) {
                    case types_KTerm_k_name:
                    {
                        __auto_type n = _mv_490.data.k_name;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case types_KTerm_k_nominal:
                    {
                        __auto_type _ = _mv_490.data.k_nominal;
                        break;
                    }
                }
                __auto_type _mv_491 = z;
                switch (_mv_491.tag) {
                    case types_KTerm_k_name:
                    {
                        __auto_type n = _mv_491.data.k_name;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case types_KTerm_k_nominal:
                    {
                        __auto_type _ = _mv_491.data.k_nominal;
                        break;
                    }
                }
                break;
            }
            case types_KscAxiom_k_and:
            {
                __auto_type a = _mv_489.data.k_and.f0;
                __auto_type b = _mv_489.data.k_and.f1;
                __auto_type z = _mv_489.data.k_and.f2;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (z); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_KscAxiom_k_some_lhs:
            {
                __auto_type a = _mv_489.data.k_some_lhs.f1;
                __auto_type z = _mv_489.data.k_some_lhs.f2;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (z); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_KscAxiom_k_some_rhs:
            {
                __auto_type a = _mv_489.data.k_some_rhs.f0;
                __auto_type b = _mv_489.data.k_some_rhs.f2;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_KscAxiom_k_self_lhs:
            {
                __auto_type z = _mv_489.data.k_self_lhs.f1;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (z); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_KscAxiom_k_self_rhs:
            {
                __auto_type a = _mv_489.data.k_self_rhs.f0;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_KscAxiom_k_role:
            {
                break;
            }
            case types_KscAxiom_k_chain:
            {
                break;
            }
            case types_KscAxiom_k_range:
            {
                __auto_type d = _mv_489.data.k_range.f1;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (d); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_KscAxiom_k_role_assert:
            {
                break;
            }
        }
        return out;
    }
}

slop_list_rdf_IRI ksc_ref_individuals(slop_arena* arena, slop_list_types_KscAxiom axioms) {
    {
        __auto_type out = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(rdf_IRI, slop_hash_rdf_IRI, slop_eq_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_492 = ax;
                switch (_mv_492.tag) {
                    case types_KscAxiom_k_sub:
                    {
                        __auto_type y = _mv_492.data.k_sub.f0;
                        __auto_type z = _mv_492.data.k_sub.f1;
                        __auto_type _mv_493 = y;
                        switch (_mv_493.tag) {
                            case types_KTerm_k_nominal:
                            {
                                __auto_type a = _mv_493.data.k_nominal;
                                if (!(slop_map_has(seen, &(a)))) {
                                    ({ slop_map_put(arena, seen, &(a), NULL, 0); });
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                                break;
                            }
                            case types_KTerm_k_name:
                            {
                                __auto_type _ = _mv_493.data.k_name;
                                break;
                            }
                        }
                        __auto_type _mv_496 = z;
                        switch (_mv_496.tag) {
                            case types_KTerm_k_nominal:
                            {
                                __auto_type a = _mv_496.data.k_nominal;
                                if (!(slop_map_has(seen, &(a)))) {
                                    ({ slop_map_put(arena, seen, &(a), NULL, 0); });
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                                break;
                            }
                            case types_KTerm_k_name:
                            {
                                __auto_type _ = _mv_496.data.k_name;
                                break;
                            }
                        }
                        break;
                    }
                    case types_KscAxiom_k_role_assert:
                    {
                        __auto_type a = _mv_492.data.k_role_assert.f0;
                        __auto_type b = _mv_492.data.k_role_assert.f2;
                        if (!(slop_map_has(seen, &(a)))) {
                            ({ slop_map_put(arena, seen, &(a), NULL, 0); });
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        if (!(slop_map_has(seen, &(b)))) {
                            ({ slop_map_put(arena, seen, &(b), NULL, 0); });
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        break;
                    }
                    case types_KscAxiom_k_and:
                    {
                        break;
                    }
                    case types_KscAxiom_k_some_lhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_some_rhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_self_lhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_self_rhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_role:
                    {
                        break;
                    }
                    case types_KscAxiom_k_chain:
                    {
                        break;
                    }
                    case types_KscAxiom_k_range:
                    {
                        break;
                    }
                }
            }
        }
        return out;
    }
}

slop_list_ksc_Concl ksc_ref_unary(slop_arena* arena, types_KFact f, types_KscAxiom ax) {
    {
        __auto_type out = ((slop_list_ksc_Concl){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_503 = f;
        switch (_mv_503.tag) {
            case types_KFact_f_inst:
            {
                __auto_type x = _mv_503.data.f_inst.f0;
                __auto_type y = _mv_503.data.f_inst.f1;
                __auto_type _mv_504 = ax;
                switch (_mv_504.tag) {
                    case types_KscAxiom_k_sub:
                    {
                        __auto_type sy = _mv_504.data.k_sub.f0;
                        __auto_type sz = _mv_504.data.k_sub.f1;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_5(sy, sz, x, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case types_KscAxiom_k_some_rhs:
                    {
                        __auto_type a = _mv_504.data.k_some_rhs.f0;
                        __auto_type v = _mv_504.data.k_some_rhs.f1;
                        __auto_type b = _mv_504.data.k_some_rhs.f2;
                        __auto_type w = _mv_504.data.k_some_rhs.f3;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_9(a, v, b, w, x, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_10(a, v, b, w, x, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case types_KscAxiom_k_role_assert:
                    {
                        __auto_type a = _mv_504.data.k_role_assert.f0;
                        __auto_type v = _mv_504.data.k_role_assert.f1;
                        __auto_type b = _mv_504.data.k_role_assert.f2;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_9_assert(a, v, b, x, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_10_assert(a, v, b, x, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case types_KscAxiom_k_self_rhs:
                    {
                        __auto_type a = _mv_504.data.k_self_rhs.f0;
                        __auto_type v = _mv_504.data.k_self_rhs.f1;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_12(a, v, x, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case types_KscAxiom_k_and:
                    {
                        break;
                    }
                    case types_KscAxiom_k_some_lhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_self_lhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_role:
                    {
                        break;
                    }
                    case types_KscAxiom_k_chain:
                    {
                        break;
                    }
                    case types_KscAxiom_k_range:
                    {
                        break;
                    }
                }
                break;
            }
            case types_KFact_f_triple:
            {
                __auto_type x = _mv_503.data.f_triple.f0;
                __auto_type v1 = _mv_503.data.f_triple.f1;
                __auto_type x1 = _mv_503.data.f_triple.f2;
                __auto_type _mv_505 = ax;
                switch (_mv_505.tag) {
                    case types_KscAxiom_k_role:
                    {
                        __auto_type v = _mv_505.data.k_role.f0;
                        __auto_type w = _mv_505.data.k_role.f1;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_13(v, w, x, v1, x1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case types_KscAxiom_k_range:
                    {
                        __auto_type v = _mv_505.data.k_range.f0;
                        __auto_type d = _mv_505.data.k_range.f1;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_23(v, d, x, v1, x1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_25(v, d, x, v1, x1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case types_KscAxiom_k_sub:
                    {
                        break;
                    }
                    case types_KscAxiom_k_and:
                    {
                        break;
                    }
                    case types_KscAxiom_k_some_lhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_some_rhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_self_lhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_self_rhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_chain:
                    {
                        break;
                    }
                    case types_KscAxiom_k_role_assert:
                    {
                        break;
                    }
                }
                break;
            }
            case types_KFact_f_self:
            {
                __auto_type x = _mv_503.data.f_self.f0;
                __auto_type v1 = _mv_503.data.f_self.f1;
                __auto_type _mv_506 = ax;
                switch (_mv_506.tag) {
                    case types_KscAxiom_k_self_lhs:
                    {
                        __auto_type v = _mv_506.data.k_self_lhs.f0;
                        __auto_type z = _mv_506.data.k_self_lhs.f1;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_11(v, z, x, v1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case types_KscAxiom_k_role:
                    {
                        __auto_type v = _mv_506.data.k_role.f0;
                        __auto_type w = _mv_506.data.k_role.f1;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_14(v, w, x, v1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case types_KscAxiom_k_range:
                    {
                        __auto_type v = _mv_506.data.k_range.f0;
                        __auto_type d = _mv_506.data.k_range.f1;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_24(v, d, x, v1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_26(v, d, x, v1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case types_KscAxiom_k_sub:
                    {
                        break;
                    }
                    case types_KscAxiom_k_and:
                    {
                        break;
                    }
                    case types_KscAxiom_k_some_lhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_some_rhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_self_rhs:
                    {
                        break;
                    }
                    case types_KscAxiom_k_chain:
                    {
                        break;
                    }
                    case types_KscAxiom_k_role_assert:
                    {
                        break;
                    }
                }
                break;
            }
        }
        return out;
    }
}

slop_list_ksc_Concl ksc_ref_binary(slop_arena* arena, types_KFact f1, types_KFact f2, types_KscAxiom ax) {
    {
        __auto_type out = ((slop_list_ksc_Concl){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_507 = ax;
        switch (_mv_507.tag) {
            case types_KscAxiom_k_and:
            {
                __auto_type a = _mv_507.data.k_and.f0;
                __auto_type b = _mv_507.data.k_and.f1;
                __auto_type z = _mv_507.data.k_and.f2;
                __auto_type _mv_508 = f1;
                switch (_mv_508.tag) {
                    case types_KFact_f_inst:
                    {
                        __auto_type x = _mv_508.data.f_inst.f0;
                        __auto_type y1 = _mv_508.data.f_inst.f1;
                        __auto_type _mv_509 = f2;
                        switch (_mv_509.tag) {
                            case types_KFact_f_inst:
                            {
                                __auto_type x2 = _mv_509.data.f_inst.f0;
                                __auto_type y2 = _mv_509.data.f_inst.f1;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_6(a, b, z, x, y1, x2, y2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            default: {
                                break;
                            }
                        }
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
            case types_KscAxiom_k_some_lhs:
            {
                __auto_type v = _mv_507.data.k_some_lhs.f0;
                __auto_type a = _mv_507.data.k_some_lhs.f1;
                __auto_type z = _mv_507.data.k_some_lhs.f2;
                __auto_type _mv_510 = f2;
                switch (_mv_510.tag) {
                    case types_KFact_f_inst:
                    {
                        __auto_type x2 = _mv_510.data.f_inst.f0;
                        __auto_type y = _mv_510.data.f_inst.f1;
                        __auto_type _mv_511 = f1;
                        switch (_mv_511.tag) {
                            case types_KFact_f_triple:
                            {
                                __auto_type x = _mv_511.data.f_triple.f0;
                                __auto_type v1 = _mv_511.data.f_triple.f1;
                                __auto_type x1 = _mv_511.data.f_triple.f2;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_7(v, a, z, x, v1, x1, x2, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case types_KFact_f_self:
                            {
                                __auto_type x = _mv_511.data.f_self.f0;
                                __auto_type v1 = _mv_511.data.f_self.f1;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_8(v, a, z, x, v1, x2, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case types_KFact_f_inst:
                            {
                                break;
                            }
                        }
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
            case types_KscAxiom_k_chain:
            {
                __auto_type u = _mv_507.data.k_chain.f0;
                __auto_type v = _mv_507.data.k_chain.f1;
                __auto_type w = _mv_507.data.k_chain.f2;
                __auto_type _mv_512 = f1;
                switch (_mv_512.tag) {
                    case types_KFact_f_triple:
                    {
                        __auto_type x = _mv_512.data.f_triple.f0;
                        __auto_type u1 = _mv_512.data.f_triple.f1;
                        __auto_type x1 = _mv_512.data.f_triple.f2;
                        __auto_type _mv_513 = f2;
                        switch (_mv_513.tag) {
                            case types_KFact_f_triple:
                            {
                                __auto_type x2 = _mv_513.data.f_triple.f0;
                                __auto_type v1 = _mv_513.data.f_triple.f1;
                                __auto_type x3 = _mv_513.data.f_triple.f2;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_15(u, v, w, x, u1, x1, x2, v1, x3)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case types_KFact_f_self:
                            {
                                __auto_type x2 = _mv_513.data.f_self.f0;
                                __auto_type v1 = _mv_513.data.f_self.f1;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_17(u, v, w, x, u1, x1, x2, v1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case types_KFact_f_inst:
                            {
                                break;
                            }
                        }
                        break;
                    }
                    case types_KFact_f_self:
                    {
                        __auto_type x = _mv_512.data.f_self.f0;
                        __auto_type u1 = _mv_512.data.f_self.f1;
                        __auto_type _mv_514 = f2;
                        switch (_mv_514.tag) {
                            case types_KFact_f_triple:
                            {
                                __auto_type x2 = _mv_514.data.f_triple.f0;
                                __auto_type v1 = _mv_514.data.f_triple.f1;
                                __auto_type x3 = _mv_514.data.f_triple.f2;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_16(u, v, w, x, u1, x2, v1, x3)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case types_KFact_f_self:
                            {
                                __auto_type x2 = _mv_514.data.f_self.f0;
                                __auto_type v1 = _mv_514.data.f_self.f1;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_18(u, v, w, x, u1, x2, v1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case types_KFact_f_inst:
                            {
                                break;
                            }
                        }
                        break;
                    }
                    case types_KFact_f_inst:
                    {
                        break;
                    }
                }
                break;
            }
            case types_KscAxiom_k_sub:
            {
                break;
            }
            case types_KscAxiom_k_some_rhs:
            {
                break;
            }
            case types_KscAxiom_k_self_lhs:
            {
                break;
            }
            case types_KscAxiom_k_self_rhs:
            {
                break;
            }
            case types_KscAxiom_k_role:
            {
                break;
            }
            case types_KscAxiom_k_range:
            {
                break;
            }
            case types_KscAxiom_k_role_assert:
            {
                break;
            }
        }
        return out;
    }
}

slop_list_ksc_Concl ksc_ref_equality(slop_arena* arena, types_KFact f1, types_KFact f2) {
    {
        __auto_type out = ((slop_list_ksc_Concl){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_515 = f1;
        switch (_mv_515.tag) {
            case types_KFact_f_inst:
            {
                __auto_type x = _mv_515.data.f_inst.f0;
                __auto_type y = _mv_515.data.f_inst.f1;
                __auto_type _mv_516 = f2;
                switch (_mv_516.tag) {
                    case types_KFact_f_inst:
                    {
                        __auto_type x2 = _mv_516.data.f_inst.f0;
                        __auto_type z = _mv_516.data.f_inst.f1;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_27(x, y, x2, z)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_28(x, y, x2, z)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case types_KFact_f_triple:
                    {
                        __auto_type z = _mv_516.data.f_triple.f0;
                        __auto_type u = _mv_516.data.f_triple.f1;
                        __auto_type x2 = _mv_516.data.f_triple.f2;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ksc_ksc_29(x, y, z, u, x2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case types_KFact_f_self:
                    {
                        break;
                    }
                }
                break;
            }
            case types_KFact_f_triple:
            {
                break;
            }
            case types_KFact_f_self:
            {
                break;
            }
        }
        return out;
    }
}

slop_list_types_KFact ksc_reference_closure(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_option_types_KName q, slop_list_types_KName classes) {
    {
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_KFact, slop_hash_types_KFact, slop_eq_types_KFact, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type facts = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type names = ksc_ref_names(arena, axioms, classes);
        uint8_t changed = 1;
        {
            __auto_type _coll = ksc_ref_individuals(arena, axioms);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    __auto_type c = ksc_ksc_1(a);
                    if (ksc_ref_add(arena, seen, c)) {
                        ({ __auto_type _lst_p = &(facts); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        __auto_type _mv_517 = q;
        if (_mv_517.has_value) {
            __auto_type qn = _mv_517.value;
            {
                __auto_type c = ksc_ksc_q(qn);
                if (ksc_ref_add(arena, seen, c)) {
                    ({ __auto_type _lst_p = &(facts); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        } else if (!_mv_517.has_value) {
        }
        while (changed) {
            {
                __auto_type snap = facts;
                __auto_type fresh = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
                uint8_t bottom = 0;
                {
                    __auto_type _coll = snap;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type f1 = _coll.data[_i];
                        __auto_type _mv_518 = f1;
                        switch (_mv_518.tag) {
                            case types_KFact_f_inst:
                            {
                                __auto_type x = _mv_518.data.f_inst.f0;
                                __auto_type y = _mv_518.data.f_inst.f1;
                                {
                                    __auto_type c = ksc_ksc_3(x, y);
                                    if (ksc_ref_add(arena, seen, c)) {
                                        ({ __auto_type _lst_p = &(fresh); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                if (ksc_ksc_4(x, y)) {
                                    bottom = 1;
                                }
                                break;
                            }
                            case types_KFact_f_triple:
                            {
                                __auto_type x = _mv_518.data.f_triple.f0;
                                __auto_type v = _mv_518.data.f_triple.f1;
                                __auto_type x1 = _mv_518.data.f_triple.f2;
                                {
                                    __auto_type c = ksc_ksc_2(x, v, x1);
                                    if (ksc_ref_add(arena, seen, c)) {
                                        ({ __auto_type _lst_p = &(fresh); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            case types_KFact_f_self:
                            {
                                break;
                            }
                        }
                        {
                            __auto_type _coll = axioms;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ax = _coll.data[_i];
                                {
                                    __auto_type _coll = ksc_ref_unary(arena, f1, ax);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type c = _coll.data[_i];
                                        if (ksc_ref_add(arena, seen, c)) {
                                            ({ __auto_type _lst_p = &(fresh); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        }
                        {
                            __auto_type _coll = snap;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type f2 = _coll.data[_i];
                                {
                                    __auto_type _coll = axioms;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type ax = _coll.data[_i];
                                        {
                                            __auto_type _coll = ksc_ref_binary(arena, f1, f2, ax);
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type c = _coll.data[_i];
                                                if (ksc_ref_add(arena, seen, c)) {
                                                    ({ __auto_type _lst_p = &(fresh); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    __auto_type _coll = ksc_ref_equality(arena, f1, f2);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type c = _coll.data[_i];
                                        if (ksc_ref_add(arena, seen, c)) {
                                            ({ __auto_type _lst_p = &(fresh); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (bottom) {
                    {
                        __auto_type _coll = snap;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type f = _coll.data[_i];
                            __auto_type _mv_519 = f;
                            switch (_mv_519.tag) {
                                case types_KFact_f_inst:
                                {
                                    __auto_type x = _mv_519.data.f_inst.f0;
                                    {
                                        __auto_type _coll = names;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type n = _coll.data[_i];
                                            {
                                                __auto_type c = ((ksc_Concl){.fires = 1, .fact = ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = types_name_term(n) } })});
                                                if (ksc_ref_add(arena, seen, c)) {
                                                    ({ __auto_type _lst_p = &(fresh); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                                case types_KFact_f_triple:
                                {
                                    break;
                                }
                                case types_KFact_f_self:
                                {
                                    break;
                                }
                            }
                        }
                    }
                }
                {
                    __auto_type _coll = fresh;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type f = _coll.data[_i];
                        ({ __auto_type _lst_p = &(facts); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                changed = (((int64_t)((fresh).len)) > 0);
            }
        }
        return facts;
    }
}

uint8_t ksc_reference_answer(slop_list_types_KFact facts, types_KName q, types_KName b) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = facts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                __auto_type _mv_520 = f;
                switch (_mv_520.tag) {
                    case types_KFact_f_inst:
                    {
                        __auto_type x = _mv_520.data.f_inst.f0;
                        __auto_type y = _mv_520.data.f_inst.f1;
                        if (types_kelem_eq(x, types_class_elem(q))) {
                            if (ksc_is_name(y, b)) {
                                found = 1;
                            }
                        }
                        break;
                    }
                    case types_KFact_f_triple:
                    {
                        break;
                    }
                    case types_KFact_f_self:
                    {
                        break;
                    }
                }
            }
        }
        return found;
    }
}

