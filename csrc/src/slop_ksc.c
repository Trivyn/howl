#include "../runtime/slop_runtime.h"
#include "slop_ksc.h"

uint8_t howl_ksc_is_name(howl_types_KTerm t, howl_types_KName n);
uint8_t howl_ksc_is_nominal(howl_types_KTerm t);
uint8_t howl_ksc_is_individual(howl_types_KElem x);
howl_types_KElem howl_ksc_term_elem(howl_types_KTerm t);
uint8_t howl_ksc_concl_eq(howl_ksc_Concl a, howl_ksc_Concl b);
slop_rdf_rdf_IRI howl_ksc_ex_a(void);
slop_rdf_rdf_IRI howl_ksc_ex_b(void);
howl_types_KName howl_ksc_ex_A(void);
howl_types_KName howl_ksc_ex_B(void);
howl_types_KName howl_ksc_ex_C(void);
howl_types_RoleId howl_ksc_ex_r(void);
howl_types_RoleId howl_ksc_ex_s(void);
howl_types_RoleId howl_ksc_ex_t(void);
howl_types_KElem howl_ksc_ex_x(void);
howl_types_KElem howl_ksc_ex_w(void);
howl_types_KElem howl_ksc_ex_ia(void);
howl_types_KTerm howl_ksc_ex_tA(void);
howl_types_KTerm howl_ksc_ex_tB(void);
howl_types_KTerm howl_ksc_ex_tC(void);
howl_types_KTerm howl_ksc_ex_na(void);
howl_ksc_Concl howl_ksc_ksc_1(slop_rdf_rdf_IRI a);
howl_ksc_Concl howl_ksc_ksc_q(howl_types_KName q);
howl_ksc_Concl howl_ksc_ksc_2(howl_types_KElem x, howl_types_RoleId v, howl_types_KElem x1);
howl_ksc_Concl howl_ksc_ksc_3(howl_types_KElem x, howl_types_KTerm y);
uint8_t howl_ksc_ksc_4(howl_types_KElem u, howl_types_KTerm z);
howl_ksc_Concl howl_ksc_ksc_5(howl_types_KTerm sy, howl_types_KTerm sz, howl_types_KElem x, howl_types_KTerm y);
howl_ksc_Concl howl_ksc_ksc_6(howl_types_KName a, howl_types_KName b, howl_types_KName z, howl_types_KElem x, howl_types_KTerm y1, howl_types_KElem x2, howl_types_KTerm y2);
howl_ksc_Concl howl_ksc_ksc_7(howl_types_RoleId v, howl_types_KName a, howl_types_KName z, howl_types_KElem x, howl_types_RoleId v1, howl_types_KElem x1, howl_types_KElem x2, howl_types_KTerm y);
howl_ksc_Concl howl_ksc_ksc_8(howl_types_RoleId v, howl_types_KName a, howl_types_KName z, howl_types_KElem x, howl_types_RoleId v1, howl_types_KElem x2, howl_types_KTerm y);
howl_ksc_Concl howl_ksc_ksc_9(howl_types_KName a, howl_types_RoleId v, howl_types_KName b, int64_t w, howl_types_KElem x, howl_types_KTerm y);
howl_ksc_Concl howl_ksc_ksc_9_assert(slop_rdf_rdf_IRI a, howl_types_RoleId v, slop_rdf_rdf_IRI b, howl_types_KElem x, howl_types_KTerm y);
howl_ksc_Concl howl_ksc_ksc_10(howl_types_KName a, howl_types_RoleId v, howl_types_KName b, int64_t w, howl_types_KElem x, howl_types_KTerm y);
howl_ksc_Concl howl_ksc_ksc_10_assert(slop_rdf_rdf_IRI a, howl_types_RoleId v, slop_rdf_rdf_IRI b, howl_types_KElem x, howl_types_KTerm y);
howl_ksc_Concl howl_ksc_ksc_11(howl_types_RoleId v, howl_types_KName z, howl_types_KElem x, howl_types_RoleId v1);
howl_ksc_Concl howl_ksc_ksc_12(howl_types_KName a, howl_types_RoleId v, howl_types_KElem x, howl_types_KTerm y);
howl_ksc_Concl howl_ksc_ksc_13(howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId v1, howl_types_KElem x1);
howl_ksc_Concl howl_ksc_ksc_14(howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId v1);
howl_ksc_Concl howl_ksc_ksc_15(howl_types_RoleId u, howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId u1, howl_types_KElem x1, howl_types_KElem x2, howl_types_RoleId v1, howl_types_KElem x3);
howl_ksc_Concl howl_ksc_ksc_16(howl_types_RoleId u, howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId u1, howl_types_KElem x2, howl_types_RoleId v1, howl_types_KElem x3);
howl_ksc_Concl howl_ksc_ksc_17(howl_types_RoleId u, howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId u1, howl_types_KElem x1, howl_types_KElem x2, howl_types_RoleId v1);
howl_ksc_Concl howl_ksc_ksc_18(howl_types_RoleId u, howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId u1, howl_types_KElem x2, howl_types_RoleId v1);
howl_ksc_Concl howl_ksc_ksc_23(howl_types_RoleId v, howl_types_KName d, howl_types_KElem x, howl_types_RoleId v1, howl_types_KElem x1);
howl_ksc_Concl howl_ksc_ksc_24(howl_types_RoleId v, howl_types_KName d, howl_types_KElem x, howl_types_RoleId v1);
howl_ksc_Concl howl_ksc_ksc_25(howl_types_RoleId v, howl_types_KName d, howl_types_KElem x, howl_types_RoleId v1, howl_types_KElem x1);
howl_ksc_Concl howl_ksc_ksc_26(howl_types_RoleId v, howl_types_KName d, howl_types_KElem x, howl_types_RoleId v1);
howl_ksc_Concl howl_ksc_ksc_27(howl_types_KElem x, howl_types_KTerm y, howl_types_KElem x2, howl_types_KTerm z);
howl_ksc_Concl howl_ksc_ksc_28(howl_types_KElem x, howl_types_KTerm y, howl_types_KElem x2, howl_types_KTerm z);
howl_ksc_Concl howl_ksc_ksc_29(howl_types_KElem x, howl_types_KTerm y, howl_types_KElem z, howl_types_RoleId u, howl_types_KElem x2);
howl_ksc_Concl howl_ksc_join_trigger_fails(howl_types_KFact t);
howl_ksc_Concl howl_ksc_join_instance(howl_ksc_JoinRule tag, howl_types_KFact t, howl_types_KFact p, howl_types_KscAxiom ax);
slop_option_howl_types_KFact howl_ksc_join_conclusion(howl_ksc_JoinRule tag, howl_types_KFact t, howl_types_KFact p, howl_types_KscAxiom ax);
slop_list_howl_types_KFact howl_ksc_ksc_join(slop_arena* arena, howl_ksc_JoinRule tag, howl_types_KFact t, slop_list_howl_types_KFact ps, howl_types_KscAxiom ax);
uint8_t howl_ksc_ref_add(slop_arena* arena, slop_map* seen, howl_ksc_Concl c);
slop_list_howl_types_KName howl_ksc_ref_names(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes);
slop_list_howl_types_KName howl_ksc_axiom_names(slop_arena* arena, howl_types_KscAxiom ax);
slop_list_slop_rdf_rdf_IRI howl_ksc_ref_individuals(slop_arena* arena, slop_list_howl_types_KscAxiom axioms);
slop_list_howl_ksc_Concl howl_ksc_ref_unary(slop_arena* arena, howl_types_KFact f, howl_types_KscAxiom ax);
slop_list_howl_ksc_Concl howl_ksc_ref_binary(slop_arena* arena, howl_types_KFact f1, howl_types_KFact f2, howl_types_KscAxiom ax);
slop_list_howl_ksc_Concl howl_ksc_ref_equality(slop_arena* arena, howl_types_KFact f1, howl_types_KFact f2);
slop_list_howl_types_KFact howl_ksc_reference_closure(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_option_howl_types_KName q, slop_list_howl_types_KName classes);
uint8_t howl_ksc_reference_answer(slop_list_howl_types_KFact facts, howl_types_KName q, howl_types_KName b);

uint8_t howl_ksc_is_name(howl_types_KTerm t, howl_types_KName n) {
    __auto_type _mv_1265 = t;
    switch (_mv_1265.tag) {
        case howl_types_KTerm_k_name:
        {
            __auto_type m = _mv_1265.data.k_name;
            return howl_types_kname_eq(m, n);
        }
        case howl_types_KTerm_k_nominal:
        {
            __auto_type _ = _mv_1265.data.k_nominal;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_ksc_is_nominal(howl_types_KTerm t) {
    __auto_type _mv_1266 = t;
    switch (_mv_1266.tag) {
        case howl_types_KTerm_k_nominal:
        {
            __auto_type _ = _mv_1266.data.k_nominal;
            return 1;
        }
        case howl_types_KTerm_k_name:
        {
            __auto_type _ = _mv_1266.data.k_name;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_ksc_is_individual(howl_types_KElem x) {
    __auto_type _mv_1267 = x;
    switch (_mv_1267.tag) {
        case howl_types_KElem_e_ind:
        {
            __auto_type _ = _mv_1267.data.e_ind;
            return 1;
        }
        case howl_types_KElem_e_aux:
        {
            __auto_type _ = _mv_1267.data.e_aux;
            return 0;
        }
        case howl_types_KElem_e_class:
        {
            __auto_type _ = _mv_1267.data.e_class;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_KElem howl_ksc_term_elem(howl_types_KTerm t) {
    __auto_type _mv_1268 = t;
    switch (_mv_1268.tag) {
        case howl_types_KTerm_k_nominal:
        {
            __auto_type a = _mv_1268.data.k_nominal;
            return howl_types_ind_elem(a);
        }
        case howl_types_KTerm_k_name:
        {
            __auto_type n = _mv_1268.data.k_name;
            return howl_types_class_elem(n);
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_ksc_concl_eq(howl_ksc_Concl a, howl_ksc_Concl b) {
    if (a.fires == b.fires) {
        return howl_types_kfact_eq(a.fact, b.fact);
    } else {
        return 0;
    }
}

slop_rdf_rdf_IRI howl_ksc_ex_a(void) {
    return ((slop_rdf_rdf_IRI){.value = SLOP_STR("http://example.org/a")});
}

slop_rdf_rdf_IRI howl_ksc_ex_b(void) {
    return ((slop_rdf_rdf_IRI){.value = SLOP_STR("http://example.org/b")});
}

howl_types_KName howl_ksc_ex_A(void) {
    return ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = ((slop_rdf_rdf_IRI){.value = SLOP_STR("http://example.org/A")}) });
}

howl_types_KName howl_ksc_ex_B(void) {
    return ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = ((slop_rdf_rdf_IRI){.value = SLOP_STR("http://example.org/B")}) });
}

howl_types_KName howl_ksc_ex_C(void) {
    return ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = ((slop_rdf_rdf_IRI){.value = SLOP_STR("http://example.org/C")}) });
}

howl_types_RoleId howl_ksc_ex_r(void) {
    return ((howl_types_RoleId){ .tag = howl_types_RoleId_named_role, .data.named_role = ((slop_rdf_rdf_IRI){.value = SLOP_STR("http://example.org/r")}) });
}

howl_types_RoleId howl_ksc_ex_s(void) {
    return ((howl_types_RoleId){ .tag = howl_types_RoleId_named_role, .data.named_role = ((slop_rdf_rdf_IRI){.value = SLOP_STR("http://example.org/s")}) });
}

howl_types_RoleId howl_ksc_ex_t(void) {
    return ((howl_types_RoleId){ .tag = howl_types_RoleId_named_role, .data.named_role = ((slop_rdf_rdf_IRI){.value = SLOP_STR("http://example.org/t")}) });
}

howl_types_KElem howl_ksc_ex_x(void) {
    return howl_types_class_elem(howl_ksc_ex_A());
}

howl_types_KElem howl_ksc_ex_w(void) {
    return howl_types_aux_elem(0);
}

howl_types_KElem howl_ksc_ex_ia(void) {
    return howl_types_ind_elem(howl_ksc_ex_a());
}

howl_types_KTerm howl_ksc_ex_tA(void) {
    return howl_types_name_term(howl_ksc_ex_A());
}

howl_types_KTerm howl_ksc_ex_tB(void) {
    return howl_types_name_term(howl_ksc_ex_B());
}

howl_types_KTerm howl_ksc_ex_tC(void) {
    return howl_types_name_term(howl_ksc_ex_C());
}

howl_types_KTerm howl_ksc_ex_na(void) {
    return howl_types_nominal_term(howl_ksc_ex_a());
}

howl_ksc_Concl howl_ksc_ksc_1(slop_rdf_rdf_IRI a) {
    return ((howl_ksc_Concl){.fires = 1, .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = howl_types_ind_elem(a), .f1 = howl_types_nominal_term(a) } })});
}

howl_ksc_Concl howl_ksc_ksc_q(howl_types_KName q) {
    return ((howl_ksc_Concl){.fires = 1, .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = howl_types_class_elem(q), .f1 = howl_types_name_term(q) } })});
}

howl_ksc_Concl howl_ksc_ksc_2(howl_types_KElem x, howl_types_RoleId v, howl_types_KElem x1) {
    {
        __auto_type fire = ((howl_ksc_is_individual(x)) ? howl_types_kelem_eq(x, x1) : 0);
        return ((howl_ksc_Concl){.fires = fire, .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_self, .data.f_self = { .f0 = x, .f1 = v } })});
    }
}

howl_ksc_Concl howl_ksc_ksc_3(howl_types_KElem x, howl_types_KTerm y) {
    return ((howl_ksc_Concl){.fires = 1, .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = howl_types_thing_term() } })});
}

uint8_t howl_ksc_ksc_4(howl_types_KElem u, howl_types_KTerm z) {
    uint8_t _retval = {0};
    _retval = howl_types_kterm_eq(z, howl_types_nothing_term());
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval == howl_types_kterm_eq(z, howl_types_nothing_term()))), "(== $result (kterm-eq z (nothing-term)))");
    return _retval;
}

howl_ksc_Concl howl_ksc_ksc_5(howl_types_KTerm sy, howl_types_KTerm sz, howl_types_KElem x, howl_types_KTerm y) {
    return ((howl_ksc_Concl){.fires = howl_types_kterm_eq(sy, y), .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = sz } })});
}

howl_ksc_Concl howl_ksc_ksc_6(howl_types_KName a, howl_types_KName b, howl_types_KName z, howl_types_KElem x, howl_types_KTerm y1, howl_types_KElem x2, howl_types_KTerm y2) {
    {
        __auto_type fire = ((howl_ksc_is_name(y1, a)) ? ((howl_types_kelem_eq(x, x2)) ? howl_ksc_is_name(y2, b) : 0) : 0);
        return ((howl_ksc_Concl){.fires = fire, .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = howl_types_name_term(z) } })});
    }
}

howl_ksc_Concl howl_ksc_ksc_7(howl_types_RoleId v, howl_types_KName a, howl_types_KName z, howl_types_KElem x, howl_types_RoleId v1, howl_types_KElem x1, howl_types_KElem x2, howl_types_KTerm y) {
    {
        __auto_type fire = ((howl_types_role_eq(v, v1)) ? ((howl_types_kelem_eq(x1, x2)) ? howl_ksc_is_name(y, a) : 0) : 0);
        return ((howl_ksc_Concl){.fires = fire, .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = howl_types_name_term(z) } })});
    }
}

howl_ksc_Concl howl_ksc_ksc_8(howl_types_RoleId v, howl_types_KName a, howl_types_KName z, howl_types_KElem x, howl_types_RoleId v1, howl_types_KElem x2, howl_types_KTerm y) {
    {
        __auto_type fire = ((howl_types_role_eq(v, v1)) ? ((howl_types_kelem_eq(x, x2)) ? howl_ksc_is_name(y, a) : 0) : 0);
        return ((howl_ksc_Concl){.fires = fire, .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = howl_types_name_term(z) } })});
    }
}

howl_ksc_Concl howl_ksc_ksc_9(howl_types_KName a, howl_types_RoleId v, howl_types_KName b, int64_t w, howl_types_KElem x, howl_types_KTerm y) {
    return ((howl_ksc_Concl){.fires = howl_ksc_is_name(y, a), .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_triple, .data.f_triple = { .f0 = x, .f1 = v, .f2 = howl_types_aux_elem(SLOP_RANGE(int64_t, w, 1, 0, 0, 0, "(Int 0 ..) at ksc.slop:375:91")) } })});
}

howl_ksc_Concl howl_ksc_ksc_9_assert(slop_rdf_rdf_IRI a, howl_types_RoleId v, slop_rdf_rdf_IRI b, howl_types_KElem x, howl_types_KTerm y) {
    return ((howl_ksc_Concl){.fires = howl_types_kterm_eq(y, howl_types_nominal_term(a)), .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_triple, .data.f_triple = { .f0 = x, .f1 = v, .f2 = howl_types_ind_elem(b) } })});
}

howl_ksc_Concl howl_ksc_ksc_10(howl_types_KName a, howl_types_RoleId v, howl_types_KName b, int64_t w, howl_types_KElem x, howl_types_KTerm y) {
    return ((howl_ksc_Concl){.fires = howl_ksc_is_name(y, a), .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = howl_types_aux_elem(w), .f1 = howl_types_name_term(b) } })});
}

howl_ksc_Concl howl_ksc_ksc_10_assert(slop_rdf_rdf_IRI a, howl_types_RoleId v, slop_rdf_rdf_IRI b, howl_types_KElem x, howl_types_KTerm y) {
    return ((howl_ksc_Concl){.fires = howl_types_kterm_eq(y, howl_types_nominal_term(a)), .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = howl_types_ind_elem(b), .f1 = howl_types_nominal_term(b) } })});
}

howl_ksc_Concl howl_ksc_ksc_11(howl_types_RoleId v, howl_types_KName z, howl_types_KElem x, howl_types_RoleId v1) {
    return ((howl_ksc_Concl){.fires = howl_types_role_eq(v, v1), .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = howl_types_name_term(z) } })});
}

howl_ksc_Concl howl_ksc_ksc_12(howl_types_KName a, howl_types_RoleId v, howl_types_KElem x, howl_types_KTerm y) {
    return ((howl_ksc_Concl){.fires = howl_ksc_is_name(y, a), .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_self, .data.f_self = { .f0 = x, .f1 = v } })});
}

howl_ksc_Concl howl_ksc_ksc_13(howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId v1, howl_types_KElem x1) {
    return ((howl_ksc_Concl){.fires = howl_types_role_eq(v, v1), .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_triple, .data.f_triple = { .f0 = x, .f1 = w, .f2 = x1 } })});
}

howl_ksc_Concl howl_ksc_ksc_14(howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId v1) {
    return ((howl_ksc_Concl){.fires = howl_types_role_eq(v, v1), .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_self, .data.f_self = { .f0 = x, .f1 = w } })});
}

howl_ksc_Concl howl_ksc_ksc_15(howl_types_RoleId u, howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId u1, howl_types_KElem x1, howl_types_KElem x2, howl_types_RoleId v1, howl_types_KElem x3) {
    {
        __auto_type fire = ((howl_types_role_eq(u, u1)) ? ((howl_types_kelem_eq(x1, x2)) ? howl_types_role_eq(v, v1) : 0) : 0);
        return ((howl_ksc_Concl){.fires = fire, .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_triple, .data.f_triple = { .f0 = x, .f1 = w, .f2 = x3 } })});
    }
}

howl_ksc_Concl howl_ksc_ksc_16(howl_types_RoleId u, howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId u1, howl_types_KElem x2, howl_types_RoleId v1, howl_types_KElem x3) {
    {
        __auto_type fire = ((howl_types_role_eq(u, u1)) ? ((howl_types_kelem_eq(x, x2)) ? howl_types_role_eq(v, v1) : 0) : 0);
        return ((howl_ksc_Concl){.fires = fire, .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_triple, .data.f_triple = { .f0 = x, .f1 = w, .f2 = x3 } })});
    }
}

howl_ksc_Concl howl_ksc_ksc_17(howl_types_RoleId u, howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId u1, howl_types_KElem x1, howl_types_KElem x2, howl_types_RoleId v1) {
    {
        __auto_type fire = ((howl_types_role_eq(u, u1)) ? ((howl_types_kelem_eq(x1, x2)) ? howl_types_role_eq(v, v1) : 0) : 0);
        return ((howl_ksc_Concl){.fires = fire, .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_triple, .data.f_triple = { .f0 = x, .f1 = w, .f2 = x1 } })});
    }
}

howl_ksc_Concl howl_ksc_ksc_18(howl_types_RoleId u, howl_types_RoleId v, howl_types_RoleId w, howl_types_KElem x, howl_types_RoleId u1, howl_types_KElem x2, howl_types_RoleId v1) {
    {
        __auto_type fire = ((howl_types_role_eq(u, u1)) ? ((howl_types_kelem_eq(x, x2)) ? howl_types_role_eq(v, v1) : 0) : 0);
        return ((howl_ksc_Concl){.fires = fire, .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_triple, .data.f_triple = { .f0 = x, .f1 = w, .f2 = x } })});
    }
}

howl_ksc_Concl howl_ksc_ksc_23(howl_types_RoleId v, howl_types_KName d, howl_types_KElem x, howl_types_RoleId v1, howl_types_KElem x1) {
    return ((howl_ksc_Concl){.fires = howl_types_role_eq(v, v1), .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = howl_types_thing_term() } })});
}

howl_ksc_Concl howl_ksc_ksc_24(howl_types_RoleId v, howl_types_KName d, howl_types_KElem x, howl_types_RoleId v1) {
    return ((howl_ksc_Concl){.fires = howl_types_role_eq(v, v1), .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = howl_types_thing_term() } })});
}

howl_ksc_Concl howl_ksc_ksc_25(howl_types_RoleId v, howl_types_KName d, howl_types_KElem x, howl_types_RoleId v1, howl_types_KElem x1) {
    return ((howl_ksc_Concl){.fires = howl_types_role_eq(v, v1), .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = x1, .f1 = howl_types_name_term(d) } })});
}

howl_ksc_Concl howl_ksc_ksc_26(howl_types_RoleId v, howl_types_KName d, howl_types_KElem x, howl_types_RoleId v1) {
    return ((howl_ksc_Concl){.fires = howl_types_role_eq(v, v1), .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = howl_types_name_term(d) } })});
}

howl_ksc_Concl howl_ksc_ksc_27(howl_types_KElem x, howl_types_KTerm y, howl_types_KElem x2, howl_types_KTerm z) {
    {
        __auto_type fire = ((howl_ksc_is_nominal(y)) ? howl_types_kelem_eq(x, x2) : 0);
        return ((howl_ksc_Concl){.fires = fire, .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = howl_ksc_term_elem(y), .f1 = z } })});
    }
}

howl_ksc_Concl howl_ksc_ksc_28(howl_types_KElem x, howl_types_KTerm y, howl_types_KElem x2, howl_types_KTerm z) {
    {
        __auto_type fire = ((howl_ksc_is_nominal(y)) ? howl_types_kelem_eq(howl_ksc_term_elem(y), x2) : 0);
        return ((howl_ksc_Concl){.fires = fire, .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = z } })});
    }
}

howl_ksc_Concl howl_ksc_ksc_29(howl_types_KElem x, howl_types_KTerm y, howl_types_KElem z, howl_types_RoleId u, howl_types_KElem x2) {
    {
        __auto_type fire = ((howl_ksc_is_nominal(y)) ? howl_types_kelem_eq(x, x2) : 0);
        return ((howl_ksc_Concl){.fires = fire, .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_triple, .data.f_triple = { .f0 = z, .f1 = u, .f2 = howl_ksc_term_elem(y) } })});
    }
}

howl_ksc_Concl howl_ksc_join_trigger_fails(howl_types_KFact t) {
    return ((howl_ksc_Concl){.fires = 0, .fact = t});
}

howl_ksc_Concl howl_ksc_join_instance(howl_ksc_JoinRule tag, howl_types_KFact t, howl_types_KFact p, howl_types_KscAxiom ax) {
    __auto_type _mv_1269 = tag;
    if (_mv_1269 == howl_ksc_JoinRule_j7_inst) {
        __auto_type _mv_1270 = ax;
        switch (_mv_1270.tag) {
            case howl_types_KscAxiom_k_some_lhs:
            {
                __auto_type v = _mv_1270.data.k_some_lhs.f0;
                __auto_type a = _mv_1270.data.k_some_lhs.f1;
                __auto_type z = _mv_1270.data.k_some_lhs.f2;
                __auto_type _mv_1271 = p;
                switch (_mv_1271.tag) {
                    case howl_types_KFact_f_triple:
                    {
                        __auto_type x = _mv_1271.data.f_triple.f0;
                        __auto_type v1 = _mv_1271.data.f_triple.f1;
                        __auto_type x1 = _mv_1271.data.f_triple.f2;
                        __auto_type _mv_1272 = t;
                        switch (_mv_1272.tag) {
                            case howl_types_KFact_f_inst:
                            {
                                __auto_type x2 = _mv_1272.data.f_inst.f0;
                                __auto_type y = _mv_1272.data.f_inst.f1;
                                return howl_ksc_ksc_7(v, a, z, x, v1, x1, x2, y);
                            }
                            default: {
                                return howl_ksc_join_trigger_fails(t);
                            }
                        }
                    }
                    default: {
                        return howl_ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return howl_ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_1269 == howl_ksc_JoinRule_j15_first) {
        __auto_type _mv_1273 = ax;
        switch (_mv_1273.tag) {
            case howl_types_KscAxiom_k_chain:
            {
                __auto_type u = _mv_1273.data.k_chain.f0;
                __auto_type v = _mv_1273.data.k_chain.f1;
                __auto_type w = _mv_1273.data.k_chain.f2;
                __auto_type _mv_1274 = t;
                switch (_mv_1274.tag) {
                    case howl_types_KFact_f_triple:
                    {
                        __auto_type x = _mv_1274.data.f_triple.f0;
                        __auto_type u1 = _mv_1274.data.f_triple.f1;
                        __auto_type x1 = _mv_1274.data.f_triple.f2;
                        __auto_type _mv_1275 = p;
                        switch (_mv_1275.tag) {
                            case howl_types_KFact_f_triple:
                            {
                                __auto_type x2 = _mv_1275.data.f_triple.f0;
                                __auto_type v1 = _mv_1275.data.f_triple.f1;
                                __auto_type x3 = _mv_1275.data.f_triple.f2;
                                return howl_ksc_ksc_15(u, v, w, x, u1, x1, x2, v1, x3);
                            }
                            default: {
                                return howl_ksc_join_trigger_fails(t);
                            }
                        }
                    }
                    default: {
                        return howl_ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return howl_ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_1269 == howl_ksc_JoinRule_j15_second) {
        __auto_type _mv_1276 = ax;
        switch (_mv_1276.tag) {
            case howl_types_KscAxiom_k_chain:
            {
                __auto_type u = _mv_1276.data.k_chain.f0;
                __auto_type v = _mv_1276.data.k_chain.f1;
                __auto_type w = _mv_1276.data.k_chain.f2;
                __auto_type _mv_1277 = p;
                switch (_mv_1277.tag) {
                    case howl_types_KFact_f_triple:
                    {
                        __auto_type x = _mv_1277.data.f_triple.f0;
                        __auto_type u1 = _mv_1277.data.f_triple.f1;
                        __auto_type x1 = _mv_1277.data.f_triple.f2;
                        __auto_type _mv_1278 = t;
                        switch (_mv_1278.tag) {
                            case howl_types_KFact_f_triple:
                            {
                                __auto_type x2 = _mv_1278.data.f_triple.f0;
                                __auto_type v1 = _mv_1278.data.f_triple.f1;
                                __auto_type x3 = _mv_1278.data.f_triple.f2;
                                return howl_ksc_ksc_15(u, v, w, x, u1, x1, x2, v1, x3);
                            }
                            default: {
                                return howl_ksc_join_trigger_fails(t);
                            }
                        }
                    }
                    default: {
                        return howl_ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return howl_ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_1269 == howl_ksc_JoinRule_j16_self) {
        __auto_type _mv_1279 = ax;
        switch (_mv_1279.tag) {
            case howl_types_KscAxiom_k_chain:
            {
                __auto_type u = _mv_1279.data.k_chain.f0;
                __auto_type v = _mv_1279.data.k_chain.f1;
                __auto_type w = _mv_1279.data.k_chain.f2;
                __auto_type _mv_1280 = t;
                switch (_mv_1280.tag) {
                    case howl_types_KFact_f_self:
                    {
                        __auto_type x = _mv_1280.data.f_self.f0;
                        __auto_type u1 = _mv_1280.data.f_self.f1;
                        __auto_type _mv_1281 = p;
                        switch (_mv_1281.tag) {
                            case howl_types_KFact_f_triple:
                            {
                                __auto_type x2 = _mv_1281.data.f_triple.f0;
                                __auto_type v1 = _mv_1281.data.f_triple.f1;
                                __auto_type x3 = _mv_1281.data.f_triple.f2;
                                return howl_ksc_ksc_16(u, v, w, x, u1, x2, v1, x3);
                            }
                            default: {
                                return howl_ksc_join_trigger_fails(t);
                            }
                        }
                    }
                    default: {
                        return howl_ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return howl_ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_1269 == howl_ksc_JoinRule_j17_self) {
        __auto_type _mv_1282 = ax;
        switch (_mv_1282.tag) {
            case howl_types_KscAxiom_k_chain:
            {
                __auto_type u = _mv_1282.data.k_chain.f0;
                __auto_type v = _mv_1282.data.k_chain.f1;
                __auto_type w = _mv_1282.data.k_chain.f2;
                __auto_type _mv_1283 = p;
                switch (_mv_1283.tag) {
                    case howl_types_KFact_f_triple:
                    {
                        __auto_type x = _mv_1283.data.f_triple.f0;
                        __auto_type u1 = _mv_1283.data.f_triple.f1;
                        __auto_type x1 = _mv_1283.data.f_triple.f2;
                        __auto_type _mv_1284 = t;
                        switch (_mv_1284.tag) {
                            case howl_types_KFact_f_self:
                            {
                                __auto_type x2 = _mv_1284.data.f_self.f0;
                                __auto_type v1 = _mv_1284.data.f_self.f1;
                                return howl_ksc_ksc_17(u, v, w, x, u1, x1, x2, v1);
                            }
                            default: {
                                return howl_ksc_join_trigger_fails(t);
                            }
                        }
                    }
                    default: {
                        return howl_ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return howl_ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_1269 == howl_ksc_JoinRule_j27_nom) {
        __auto_type _mv_1285 = t;
        switch (_mv_1285.tag) {
            case howl_types_KFact_f_inst:
            {
                __auto_type x = _mv_1285.data.f_inst.f0;
                __auto_type y = _mv_1285.data.f_inst.f1;
                __auto_type _mv_1286 = p;
                switch (_mv_1286.tag) {
                    case howl_types_KFact_f_inst:
                    {
                        __auto_type x2 = _mv_1286.data.f_inst.f0;
                        __auto_type z = _mv_1286.data.f_inst.f1;
                        return howl_ksc_ksc_27(x, y, x2, z);
                    }
                    default: {
                        return howl_ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return howl_ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_1269 == howl_ksc_JoinRule_j27_other) {
        __auto_type _mv_1287 = p;
        switch (_mv_1287.tag) {
            case howl_types_KFact_f_inst:
            {
                __auto_type x = _mv_1287.data.f_inst.f0;
                __auto_type y = _mv_1287.data.f_inst.f1;
                __auto_type _mv_1288 = t;
                switch (_mv_1288.tag) {
                    case howl_types_KFact_f_inst:
                    {
                        __auto_type x2 = _mv_1288.data.f_inst.f0;
                        __auto_type z = _mv_1288.data.f_inst.f1;
                        return howl_ksc_ksc_27(x, y, x2, z);
                    }
                    default: {
                        return howl_ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return howl_ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_1269 == howl_ksc_JoinRule_j28_nom) {
        __auto_type _mv_1289 = t;
        switch (_mv_1289.tag) {
            case howl_types_KFact_f_inst:
            {
                __auto_type x = _mv_1289.data.f_inst.f0;
                __auto_type y = _mv_1289.data.f_inst.f1;
                __auto_type _mv_1290 = p;
                switch (_mv_1290.tag) {
                    case howl_types_KFact_f_inst:
                    {
                        __auto_type x2 = _mv_1290.data.f_inst.f0;
                        __auto_type z = _mv_1290.data.f_inst.f1;
                        return howl_ksc_ksc_28(x, y, x2, z);
                    }
                    default: {
                        return howl_ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return howl_ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_1269 == howl_ksc_JoinRule_j28_ind) {
        __auto_type _mv_1291 = p;
        switch (_mv_1291.tag) {
            case howl_types_KFact_f_inst:
            {
                __auto_type x = _mv_1291.data.f_inst.f0;
                __auto_type y = _mv_1291.data.f_inst.f1;
                __auto_type _mv_1292 = t;
                switch (_mv_1292.tag) {
                    case howl_types_KFact_f_inst:
                    {
                        __auto_type x2 = _mv_1292.data.f_inst.f0;
                        __auto_type z = _mv_1292.data.f_inst.f1;
                        return howl_ksc_ksc_28(x, y, x2, z);
                    }
                    default: {
                        return howl_ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return howl_ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_1269 == howl_ksc_JoinRule_j29_nom) {
        __auto_type _mv_1293 = t;
        switch (_mv_1293.tag) {
            case howl_types_KFact_f_inst:
            {
                __auto_type x = _mv_1293.data.f_inst.f0;
                __auto_type y = _mv_1293.data.f_inst.f1;
                __auto_type _mv_1294 = p;
                switch (_mv_1294.tag) {
                    case howl_types_KFact_f_triple:
                    {
                        __auto_type z = _mv_1294.data.f_triple.f0;
                        __auto_type u = _mv_1294.data.f_triple.f1;
                        __auto_type x2 = _mv_1294.data.f_triple.f2;
                        return howl_ksc_ksc_29(x, y, z, u, x2);
                    }
                    default: {
                        return howl_ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return howl_ksc_join_trigger_fails(t);
            }
        }
    } else if (_mv_1269 == howl_ksc_JoinRule_j29_triple) {
        __auto_type _mv_1295 = p;
        switch (_mv_1295.tag) {
            case howl_types_KFact_f_inst:
            {
                __auto_type x = _mv_1295.data.f_inst.f0;
                __auto_type y = _mv_1295.data.f_inst.f1;
                __auto_type _mv_1296 = t;
                switch (_mv_1296.tag) {
                    case howl_types_KFact_f_triple:
                    {
                        __auto_type z = _mv_1296.data.f_triple.f0;
                        __auto_type u = _mv_1296.data.f_triple.f1;
                        __auto_type x2 = _mv_1296.data.f_triple.f2;
                        return howl_ksc_ksc_29(x, y, z, u, x2);
                    }
                    default: {
                        return howl_ksc_join_trigger_fails(t);
                    }
                }
            }
            default: {
                return howl_ksc_join_trigger_fails(t);
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_option_howl_types_KFact howl_ksc_join_conclusion(howl_ksc_JoinRule tag, howl_types_KFact t, howl_types_KFact p, howl_types_KscAxiom ax) {
    slop_option_howl_types_KFact _retval = {0};
    {
        __auto_type c = howl_ksc_join_instance(tag, t, p, ax);
        if (c.fires) {
            _retval = (slop_option_howl_types_KFact){.has_value = 1, .value = c.fact};
            goto _slop_post;
        } else {
            _retval = (slop_option_howl_types_KFact){.has_value = false};
            goto _slop_post;
        }
    }
    _slop_post: ;
    SLOP_POST((({ __auto_type _mv = _retval; _mv.has_value ? ({ __auto_type c = _mv.value; ((howl_ksc_join_instance(tag, t, p, ax).fires == 1) && ({ howl_types_KFact _eq_l_1297 = (howl_ksc_join_instance(tag, t, p, ax).fact); howl_types_KFact _eq_r_1298 = (c); slop_eq_howl_types_KFact(&_eq_l_1297, &_eq_r_1298); })); }) : ((howl_ksc_join_instance(tag, t, p, ax).fires == 0)); })), "(match $result ((some c) (and (== (. (join-instance tag t p ax) fires) true) (== (. (join-instance tag t p ax) fact) c))) ((none) (== (. (join-instance tag t p ax) fires) false)))");
    return _retval;
}

slop_list_howl_types_KFact howl_ksc_ksc_join(slop_arena* arena, howl_ksc_JoinRule tag, howl_types_KFact t, slop_list_howl_types_KFact ps, howl_types_KscAxiom ax) {
    slop_list_howl_types_KFact _retval = {0};
    {
        __auto_type result = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ps;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                __auto_type _mv_1299 = howl_ksc_join_conclusion(tag, t, q, ax);
                if (_mv_1299.has_value) {
                    __auto_type c = _mv_1299.value;
                    ({ __auto_type _lst_p = &(result); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1299.has_value) {
                }
            }
        }
        _retval = result;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

uint8_t howl_ksc_ref_add(slop_arena* arena, slop_map* seen, howl_ksc_Concl c) {
    if (c.fires == 1) {
        if (slop_map_has(seen, &(c.fact))) {
            return 0;
        } else {
            (void)(({ slop_map_put(NULL, seen, &(c.fact), NULL, 0); }));
            return 1;
        }
    } else {
        return 0;
    }
}

slop_list_howl_types_KName howl_ksc_ref_names(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes) {
    {
        __auto_type out = ((slop_list_howl_types_KName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(howl_types_KName, slop_hash_howl_types_KName, slop_eq_howl_types_KName, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                if (!(slop_map_has(seen, &(n)))) {
                    (void)(({ slop_map_put(NULL, seen, &(n), NULL, 0); }));
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type t = ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_THING}) });
            __auto_type b = ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_NOTHING}) });
            if (!(slop_map_has(seen, &(t)))) {
                (void)(({ slop_map_put(NULL, seen, &(t), NULL, 0); }));
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
            if (!(slop_map_has(seen, &(b)))) {
                (void)(({ slop_map_put(NULL, seen, &(b), NULL, 0); }));
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                {
                    __auto_type _coll = howl_ksc_axiom_names(arena, ax);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type n = _coll.data[_i];
                        if (!(slop_map_has(seen, &(n)))) {
                            (void)(({ slop_map_put(NULL, seen, &(n), NULL, 0); }));
                            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_types_KName howl_ksc_axiom_names(slop_arena* arena, howl_types_KscAxiom ax) {
    {
        __auto_type out = ((slop_list_howl_types_KName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1310 = ax;
        switch (_mv_1310.tag) {
            case howl_types_KscAxiom_k_sub:
            {
                __auto_type y = _mv_1310.data.k_sub.f0;
                __auto_type z = _mv_1310.data.k_sub.f1;
                __auto_type _mv_1311 = y;
                switch (_mv_1311.tag) {
                    case howl_types_KTerm_k_name:
                    {
                        __auto_type n = _mv_1311.data.k_name;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_types_KTerm_k_nominal:
                    {
                        __auto_type _ = _mv_1311.data.k_nominal;
                        break;
                    }
                }
                __auto_type _mv_1312 = z;
                switch (_mv_1312.tag) {
                    case howl_types_KTerm_k_name:
                    {
                        __auto_type n = _mv_1312.data.k_name;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_types_KTerm_k_nominal:
                    {
                        __auto_type _ = _mv_1312.data.k_nominal;
                        break;
                    }
                }
                break;
            }
            case howl_types_KscAxiom_k_and:
            {
                __auto_type a = _mv_1310.data.k_and.f0;
                __auto_type b = _mv_1310.data.k_and.f1;
                __auto_type z = _mv_1310.data.k_and.f2;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (z); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_KscAxiom_k_some_lhs:
            {
                __auto_type a = _mv_1310.data.k_some_lhs.f1;
                __auto_type z = _mv_1310.data.k_some_lhs.f2;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (z); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_KscAxiom_k_some_rhs:
            {
                __auto_type a = _mv_1310.data.k_some_rhs.f0;
                __auto_type b = _mv_1310.data.k_some_rhs.f2;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_KscAxiom_k_self_lhs:
            {
                __auto_type z = _mv_1310.data.k_self_lhs.f1;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (z); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_KscAxiom_k_self_rhs:
            {
                __auto_type a = _mv_1310.data.k_self_rhs.f0;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_KscAxiom_k_role:
            {
                break;
            }
            case howl_types_KscAxiom_k_chain:
            {
                break;
            }
            case howl_types_KscAxiom_k_range:
            {
                __auto_type d = _mv_1310.data.k_range.f1;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (d); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_KscAxiom_k_role_assert:
            {
                break;
            }
        }
        return out;
    }
}

slop_list_slop_rdf_rdf_IRI howl_ksc_ref_individuals(slop_arena* arena, slop_list_howl_types_KscAxiom axioms) {
    {
        __auto_type out = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = axioms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1313 = ax;
                switch (_mv_1313.tag) {
                    case howl_types_KscAxiom_k_sub:
                    {
                        __auto_type y = _mv_1313.data.k_sub.f0;
                        __auto_type z = _mv_1313.data.k_sub.f1;
                        __auto_type _mv_1314 = y;
                        switch (_mv_1314.tag) {
                            case howl_types_KTerm_k_nominal:
                            {
                                __auto_type a = _mv_1314.data.k_nominal;
                                if (!(slop_map_has(seen, &(a)))) {
                                    ({ slop_map_put(NULL, seen, &(a), NULL, 0); });
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                                break;
                            }
                            case howl_types_KTerm_k_name:
                            {
                                __auto_type _ = _mv_1314.data.k_name;
                                break;
                            }
                        }
                        __auto_type _mv_1317 = z;
                        switch (_mv_1317.tag) {
                            case howl_types_KTerm_k_nominal:
                            {
                                __auto_type a = _mv_1317.data.k_nominal;
                                if (!(slop_map_has(seen, &(a)))) {
                                    ({ slop_map_put(NULL, seen, &(a), NULL, 0); });
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                                break;
                            }
                            case howl_types_KTerm_k_name:
                            {
                                __auto_type _ = _mv_1317.data.k_name;
                                break;
                            }
                        }
                        break;
                    }
                    case howl_types_KscAxiom_k_role_assert:
                    {
                        __auto_type a = _mv_1313.data.k_role_assert.f0;
                        __auto_type b = _mv_1313.data.k_role_assert.f2;
                        if (!(slop_map_has(seen, &(a)))) {
                            ({ slop_map_put(NULL, seen, &(a), NULL, 0); });
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        if (!(slop_map_has(seen, &(b)))) {
                            ({ slop_map_put(NULL, seen, &(b), NULL, 0); });
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        break;
                    }
                    case howl_types_KscAxiom_k_and:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_some_lhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_some_rhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_self_lhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_self_rhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_role:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_chain:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_range:
                    {
                        break;
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_ksc_Concl howl_ksc_ref_unary(slop_arena* arena, howl_types_KFact f, howl_types_KscAxiom ax) {
    {
        __auto_type out = ((slop_list_howl_ksc_Concl){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1324 = f;
        switch (_mv_1324.tag) {
            case howl_types_KFact_f_inst:
            {
                __auto_type x = _mv_1324.data.f_inst.f0;
                __auto_type y = _mv_1324.data.f_inst.f1;
                __auto_type _mv_1325 = ax;
                switch (_mv_1325.tag) {
                    case howl_types_KscAxiom_k_sub:
                    {
                        __auto_type sy = _mv_1325.data.k_sub.f0;
                        __auto_type sz = _mv_1325.data.k_sub.f1;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_5(sy, sz, x, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_types_KscAxiom_k_some_rhs:
                    {
                        __auto_type a = _mv_1325.data.k_some_rhs.f0;
                        __auto_type v = _mv_1325.data.k_some_rhs.f1;
                        __auto_type b = _mv_1325.data.k_some_rhs.f2;
                        __auto_type w = _mv_1325.data.k_some_rhs.f3;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_9(a, v, b, w, x, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_10(a, v, b, w, x, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_types_KscAxiom_k_role_assert:
                    {
                        __auto_type a = _mv_1325.data.k_role_assert.f0;
                        __auto_type v = _mv_1325.data.k_role_assert.f1;
                        __auto_type b = _mv_1325.data.k_role_assert.f2;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_9_assert(a, v, b, x, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_10_assert(a, v, b, x, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_types_KscAxiom_k_self_rhs:
                    {
                        __auto_type a = _mv_1325.data.k_self_rhs.f0;
                        __auto_type v = _mv_1325.data.k_self_rhs.f1;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_12(a, v, x, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_types_KscAxiom_k_and:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_some_lhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_self_lhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_role:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_chain:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_range:
                    {
                        break;
                    }
                }
                break;
            }
            case howl_types_KFact_f_triple:
            {
                __auto_type x = _mv_1324.data.f_triple.f0;
                __auto_type v1 = _mv_1324.data.f_triple.f1;
                __auto_type x1 = _mv_1324.data.f_triple.f2;
                __auto_type _mv_1326 = ax;
                switch (_mv_1326.tag) {
                    case howl_types_KscAxiom_k_role:
                    {
                        __auto_type v = _mv_1326.data.k_role.f0;
                        __auto_type w = _mv_1326.data.k_role.f1;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_13(v, w, x, v1, x1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_types_KscAxiom_k_range:
                    {
                        __auto_type v = _mv_1326.data.k_range.f0;
                        __auto_type d = _mv_1326.data.k_range.f1;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_23(v, d, x, v1, x1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_25(v, d, x, v1, x1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_types_KscAxiom_k_sub:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_and:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_some_lhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_some_rhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_self_lhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_self_rhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_chain:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_role_assert:
                    {
                        break;
                    }
                }
                break;
            }
            case howl_types_KFact_f_self:
            {
                __auto_type x = _mv_1324.data.f_self.f0;
                __auto_type v1 = _mv_1324.data.f_self.f1;
                __auto_type _mv_1327 = ax;
                switch (_mv_1327.tag) {
                    case howl_types_KscAxiom_k_self_lhs:
                    {
                        __auto_type v = _mv_1327.data.k_self_lhs.f0;
                        __auto_type z = _mv_1327.data.k_self_lhs.f1;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_11(v, z, x, v1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_types_KscAxiom_k_role:
                    {
                        __auto_type v = _mv_1327.data.k_role.f0;
                        __auto_type w = _mv_1327.data.k_role.f1;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_14(v, w, x, v1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_types_KscAxiom_k_range:
                    {
                        __auto_type v = _mv_1327.data.k_range.f0;
                        __auto_type d = _mv_1327.data.k_range.f1;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_24(v, d, x, v1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_26(v, d, x, v1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_types_KscAxiom_k_sub:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_and:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_some_lhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_some_rhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_self_rhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_chain:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_role_assert:
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

slop_list_howl_ksc_Concl howl_ksc_ref_binary(slop_arena* arena, howl_types_KFact f1, howl_types_KFact f2, howl_types_KscAxiom ax) {
    {
        __auto_type out = ((slop_list_howl_ksc_Concl){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1328 = ax;
        switch (_mv_1328.tag) {
            case howl_types_KscAxiom_k_and:
            {
                __auto_type a = _mv_1328.data.k_and.f0;
                __auto_type b = _mv_1328.data.k_and.f1;
                __auto_type z = _mv_1328.data.k_and.f2;
                __auto_type _mv_1329 = f1;
                switch (_mv_1329.tag) {
                    case howl_types_KFact_f_inst:
                    {
                        __auto_type x = _mv_1329.data.f_inst.f0;
                        __auto_type y1 = _mv_1329.data.f_inst.f1;
                        __auto_type _mv_1330 = f2;
                        switch (_mv_1330.tag) {
                            case howl_types_KFact_f_inst:
                            {
                                __auto_type x2 = _mv_1330.data.f_inst.f0;
                                __auto_type y2 = _mv_1330.data.f_inst.f1;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_6(a, b, z, x, y1, x2, y2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
            case howl_types_KscAxiom_k_some_lhs:
            {
                __auto_type v = _mv_1328.data.k_some_lhs.f0;
                __auto_type a = _mv_1328.data.k_some_lhs.f1;
                __auto_type z = _mv_1328.data.k_some_lhs.f2;
                __auto_type _mv_1331 = f2;
                switch (_mv_1331.tag) {
                    case howl_types_KFact_f_inst:
                    {
                        __auto_type x2 = _mv_1331.data.f_inst.f0;
                        __auto_type y = _mv_1331.data.f_inst.f1;
                        __auto_type _mv_1332 = f1;
                        switch (_mv_1332.tag) {
                            case howl_types_KFact_f_triple:
                            {
                                __auto_type x = _mv_1332.data.f_triple.f0;
                                __auto_type v1 = _mv_1332.data.f_triple.f1;
                                __auto_type x1 = _mv_1332.data.f_triple.f2;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_7(v, a, z, x, v1, x1, x2, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case howl_types_KFact_f_self:
                            {
                                __auto_type x = _mv_1332.data.f_self.f0;
                                __auto_type v1 = _mv_1332.data.f_self.f1;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_8(v, a, z, x, v1, x2, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case howl_types_KFact_f_inst:
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
            case howl_types_KscAxiom_k_chain:
            {
                __auto_type u = _mv_1328.data.k_chain.f0;
                __auto_type v = _mv_1328.data.k_chain.f1;
                __auto_type w = _mv_1328.data.k_chain.f2;
                __auto_type _mv_1333 = f1;
                switch (_mv_1333.tag) {
                    case howl_types_KFact_f_triple:
                    {
                        __auto_type x = _mv_1333.data.f_triple.f0;
                        __auto_type u1 = _mv_1333.data.f_triple.f1;
                        __auto_type x1 = _mv_1333.data.f_triple.f2;
                        __auto_type _mv_1334 = f2;
                        switch (_mv_1334.tag) {
                            case howl_types_KFact_f_triple:
                            {
                                __auto_type x2 = _mv_1334.data.f_triple.f0;
                                __auto_type v1 = _mv_1334.data.f_triple.f1;
                                __auto_type x3 = _mv_1334.data.f_triple.f2;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_15(u, v, w, x, u1, x1, x2, v1, x3)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case howl_types_KFact_f_self:
                            {
                                __auto_type x2 = _mv_1334.data.f_self.f0;
                                __auto_type v1 = _mv_1334.data.f_self.f1;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_17(u, v, w, x, u1, x1, x2, v1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case howl_types_KFact_f_inst:
                            {
                                break;
                            }
                        }
                        break;
                    }
                    case howl_types_KFact_f_self:
                    {
                        __auto_type x = _mv_1333.data.f_self.f0;
                        __auto_type u1 = _mv_1333.data.f_self.f1;
                        __auto_type _mv_1335 = f2;
                        switch (_mv_1335.tag) {
                            case howl_types_KFact_f_triple:
                            {
                                __auto_type x2 = _mv_1335.data.f_triple.f0;
                                __auto_type v1 = _mv_1335.data.f_triple.f1;
                                __auto_type x3 = _mv_1335.data.f_triple.f2;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_16(u, v, w, x, u1, x2, v1, x3)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case howl_types_KFact_f_self:
                            {
                                __auto_type x2 = _mv_1335.data.f_self.f0;
                                __auto_type v1 = _mv_1335.data.f_self.f1;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_18(u, v, w, x, u1, x2, v1)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case howl_types_KFact_f_inst:
                            {
                                break;
                            }
                        }
                        break;
                    }
                    case howl_types_KFact_f_inst:
                    {
                        break;
                    }
                }
                break;
            }
            case howl_types_KscAxiom_k_sub:
            {
                break;
            }
            case howl_types_KscAxiom_k_some_rhs:
            {
                break;
            }
            case howl_types_KscAxiom_k_self_lhs:
            {
                break;
            }
            case howl_types_KscAxiom_k_self_rhs:
            {
                break;
            }
            case howl_types_KscAxiom_k_role:
            {
                break;
            }
            case howl_types_KscAxiom_k_range:
            {
                break;
            }
            case howl_types_KscAxiom_k_role_assert:
            {
                break;
            }
        }
        return out;
    }
}

slop_list_howl_ksc_Concl howl_ksc_ref_equality(slop_arena* arena, howl_types_KFact f1, howl_types_KFact f2) {
    {
        __auto_type out = ((slop_list_howl_ksc_Concl){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1336 = f1;
        switch (_mv_1336.tag) {
            case howl_types_KFact_f_inst:
            {
                __auto_type x = _mv_1336.data.f_inst.f0;
                __auto_type y = _mv_1336.data.f_inst.f1;
                __auto_type _mv_1337 = f2;
                switch (_mv_1337.tag) {
                    case howl_types_KFact_f_inst:
                    {
                        __auto_type x2 = _mv_1337.data.f_inst.f0;
                        __auto_type z = _mv_1337.data.f_inst.f1;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_27(x, y, x2, z)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_28(x, y, x2, z)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_types_KFact_f_triple:
                    {
                        __auto_type z = _mv_1337.data.f_triple.f0;
                        __auto_type u = _mv_1337.data.f_triple.f1;
                        __auto_type x2 = _mv_1337.data.f_triple.f2;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_ksc_ksc_29(x, y, z, u, x2)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_types_KFact_f_self:
                    {
                        break;
                    }
                }
                break;
            }
            case howl_types_KFact_f_triple:
            {
                break;
            }
            case howl_types_KFact_f_self:
            {
                break;
            }
        }
        return out;
    }
}

slop_list_howl_types_KFact howl_ksc_reference_closure(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_option_howl_types_KName q, slop_list_howl_types_KName classes) {
    {
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(howl_types_KFact, slop_hash_howl_types_KFact, slop_eq_howl_types_KFact, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type facts = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type names = howl_ksc_ref_names(arena, axioms, classes);
        uint8_t changed = 1;
        {
            __auto_type _coll = howl_ksc_ref_individuals(arena, axioms);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    __auto_type c = howl_ksc_ksc_1(a);
                    if (howl_ksc_ref_add(arena, seen, c)) {
                        (void)(({ __auto_type _lst_p = &(facts); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        __auto_type _mv_1338 = q;
        if (_mv_1338.has_value) {
            __auto_type qn = _mv_1338.value;
            {
                __auto_type c = howl_ksc_ksc_q(qn);
                if (howl_ksc_ref_add(arena, seen, c)) {
                    ({ __auto_type _lst_p = &(facts); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        } else if (!_mv_1338.has_value) {
        }
        while (changed) {
            {
                __auto_type snap = facts;
                __auto_type fresh = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                uint8_t bottom = 0;
                {
                    __auto_type _coll = snap;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type f1 = _coll.data[_i];
                        __auto_type _mv_1339 = f1;
                        switch (_mv_1339.tag) {
                            case howl_types_KFact_f_inst:
                            {
                                __auto_type x = _mv_1339.data.f_inst.f0;
                                __auto_type y = _mv_1339.data.f_inst.f1;
                                {
                                    __auto_type c = howl_ksc_ksc_3(x, y);
                                    if (howl_ksc_ref_add(arena, seen, c)) {
                                        ({ __auto_type _lst_p = &(fresh); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                if (howl_ksc_ksc_4(x, y)) {
                                    bottom = 1;
                                }
                                break;
                            }
                            case howl_types_KFact_f_triple:
                            {
                                __auto_type x = _mv_1339.data.f_triple.f0;
                                __auto_type v = _mv_1339.data.f_triple.f1;
                                __auto_type x1 = _mv_1339.data.f_triple.f2;
                                {
                                    __auto_type c = howl_ksc_ksc_2(x, v, x1);
                                    if (howl_ksc_ref_add(arena, seen, c)) {
                                        ({ __auto_type _lst_p = &(fresh); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                break;
                            }
                            case howl_types_KFact_f_self:
                            {
                                break;
                            }
                        }
                        {
                            __auto_type _coll = axioms;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ax = _coll.data[_i];
                                {
                                    __auto_type _coll = howl_ksc_ref_unary(arena, f1, ax);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type c = _coll.data[_i];
                                        if (howl_ksc_ref_add(arena, seen, c)) {
                                            (void)(({ __auto_type _lst_p = &(fresh); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
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
                                            __auto_type _coll = howl_ksc_ref_binary(arena, f1, f2, ax);
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type c = _coll.data[_i];
                                                if (howl_ksc_ref_add(arena, seen, c)) {
                                                    (void)(({ __auto_type _lst_p = &(fresh); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    __auto_type _coll = howl_ksc_ref_equality(arena, f1, f2);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type c = _coll.data[_i];
                                        if (howl_ksc_ref_add(arena, seen, c)) {
                                            (void)(({ __auto_type _lst_p = &(fresh); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
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
                            __auto_type _mv_1340 = f;
                            switch (_mv_1340.tag) {
                                case howl_types_KFact_f_inst:
                                {
                                    __auto_type x = _mv_1340.data.f_inst.f0;
                                    {
                                        __auto_type _coll = names;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type n = _coll.data[_i];
                                            {
                                                __auto_type c = ((howl_ksc_Concl){.fires = 1, .fact = ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = howl_types_name_term(n) } })});
                                                if (howl_ksc_ref_add(arena, seen, c)) {
                                                    ({ __auto_type _lst_p = &(fresh); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                                case howl_types_KFact_f_triple:
                                {
                                    break;
                                }
                                case howl_types_KFact_f_self:
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
                        (void)(({ __auto_type _lst_p = &(facts); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
                changed = (((int64_t)((fresh).len)) > 0);
            }
        }
        return facts;
    }
}

uint8_t howl_ksc_reference_answer(slop_list_howl_types_KFact facts, howl_types_KName q, howl_types_KName b) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = facts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                __auto_type _mv_1341 = f;
                switch (_mv_1341.tag) {
                    case howl_types_KFact_f_inst:
                    {
                        __auto_type x = _mv_1341.data.f_inst.f0;
                        __auto_type y = _mv_1341.data.f_inst.f1;
                        if (howl_types_kelem_eq(x, howl_types_class_elem(q))) {
                            if (howl_ksc_is_name(y, b)) {
                                found = 1;
                            }
                        }
                        break;
                    }
                    case howl_types_KFact_f_triple:
                    {
                        break;
                    }
                    case howl_types_KFact_f_self:
                    {
                        break;
                    }
                }
            }
        }
        return found;
    }
}

