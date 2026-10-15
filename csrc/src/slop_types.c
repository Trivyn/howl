#include "../runtime/slop_runtime.h"
#include "slop_types.h"


howl_types_ReasonerConfig howl_types_default_config(void);
uint8_t howl_types_cancel_requested(int64_t cancel);
howl_types_Node howl_types_node_top(void);
howl_types_Node howl_types_node_bottom(void);
uint8_t howl_types_node_eq(howl_types_Node a, howl_types_Node b);
uint8_t howl_types_role_eq(howl_types_RoleId a, howl_types_RoleId b);
uint8_t howl_types_kname_eq(howl_types_KName a, howl_types_KName b);
uint8_t howl_types_kterm_eq(howl_types_KTerm a, howl_types_KTerm b);
uint8_t howl_types_kelem_eq(howl_types_KElem a, howl_types_KElem b);
uint8_t howl_types_kfact_eq(howl_types_KFact a, howl_types_KFact b);
howl_types_KTerm howl_types_name_term(howl_types_KName n);
howl_types_KTerm howl_types_nominal_term(slop_rdf_rdf_IRI a);
howl_types_KElem howl_types_ind_elem(slop_rdf_rdf_IRI a);
howl_types_KElem howl_types_aux_elem(int64_t w);
howl_types_KElem howl_types_class_elem(howl_types_KName q);
howl_types_KTerm howl_types_thing_term(void);
howl_types_KTerm howl_types_nothing_term(void);
howl_types_ATerm howl_types_at_x(void);
howl_types_ATerm howl_types_at_y(void);
howl_types_ATerm howl_types_at_z(uint32_t i);
howl_types_ATerm howl_types_at_fx(uint32_t f);
howl_types_ATerm howl_types_at_u(uint32_t u);
howl_types_ATerm howl_types_at_fu(uint32_t f, uint32_t u);
int64_t howl_types_ord_int(int64_t a, int64_t b);
int64_t howl_types_akind_rank(howl_types_AKind k);
int64_t howl_types_aterm_cmp(howl_types_ATerm a, howl_types_ATerm b);
uint8_t howl_types_aterm_eq(howl_types_ATerm a, howl_types_ATerm b);
howl_types_Lit howl_types_atom1(uint32_t b, howl_types_ATerm t);
howl_types_Lit howl_types_atom2(uint32_t s, howl_types_ATerm l, howl_types_ATerm r);
howl_types_Lit howl_types_oriented(howl_types_LitForm form, howl_types_ATerm s, howl_types_ATerm t);
howl_types_Lit howl_types_eq_lit(howl_types_ATerm s, howl_types_ATerm t);
howl_types_Lit howl_types_neq_lit(howl_types_ATerm s, howl_types_ATerm t);
int64_t howl_types_lit_form_rank(howl_types_LitForm f);
int64_t howl_types_lit_cmp(howl_types_Lit a, howl_types_Lit b);
uint8_t howl_types_lit_eq(howl_types_Lit a, howl_types_Lit b);
howl_types_Names howl_types_empty_names(slop_arena* arena);
howl_types_Node howl_types_intern_node(slop_arena* arena, howl_types_Names names, howl_types_Node n);
howl_types_RoleId howl_types_intern_role(slop_arena* arena, howl_types_Names names, howl_types_RoleId r);
slop_string howl_types_copy_string(slop_arena* arena, slop_string s);
slop_rdf_rdf_IRI howl_types_copy_iri(slop_arena* arena, slop_rdf_rdf_IRI i);
howl_types_Node howl_types_copy_node(slop_arena* arena, howl_types_Node n);
howl_types_RoleId howl_types_copy_role(slop_arena* arena, howl_types_RoleId r);
howl_types_AxiomRef howl_types_copy_axiom_ref(slop_arena* arena, howl_types_AxiomRef a);
howl_types_InputRef howl_types_copy_input_ref(slop_arena* arena, howl_types_InputRef r);
howl_types_Omission howl_types_copy_omission(slop_arena* arena, howl_types_Omission o);
slop_list_howl_types_Omission howl_types_copy_omissions(slop_arena* arena, slop_list_howl_types_Omission os);
howl_types_Fault howl_types_copy_fault(slop_arena* arena, howl_types_Fault f);
slop_option_howl_types_Node howl_types_renamed_node(howl_types_Names names, howl_types_Node n);
howl_types_Node howl_types_original_node(howl_types_Names names, howl_types_Node n);
howl_types_RoleId howl_types_original_role(howl_types_Names names, howl_types_RoleId r);
howl_types_Context howl_types_make_context(slop_arena* arena, howl_types_Node root);
howl_types_Queue howl_types_make_queue(slop_arena* arena);
uint8_t howl_types_queue_is_active(howl_types_Queue q);
uint8_t howl_types_derived_eq(howl_types_Derived a, howl_types_Derived b);
uint8_t howl_types_addressed_eq(howl_types_Addressed a, howl_types_Addressed b);
howl_types_EdgePair howl_types_emit_edge(slop_arena* arena, howl_types_LogicalEdge e);
uint8_t howl_types_outcome_is_complete(howl_types_Outcome o);
uint8_t howl_types_findings_are_incoherent(howl_types_Findings f);
howl_types_Verdict howl_types_verdict(howl_types_Outcome o);

howl_types_ReasonerConfig howl_types_default_config(void) {
    howl_types_ReasonerConfig _retval = {0};
    _retval = ((howl_types_ReasonerConfig){.worker_count = 4, .channel_buffer = 256, .max_iterations = 1000, .selection = ((howl_types_ProfileSelection){ .tag = howl_types_ProfileSelection_explicit, .data.explicit = howl_types_Profile_profile_el }), .strict_profile = 0, .cancel_ptr = 0, .verbose = 0, .clause_budget = 500000});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.worker_count == 4)), "(== (. $result worker-count) 4)");
    SLOP_POST(((_retval.channel_buffer == 256)), "(== (. $result channel-buffer) 256)");
    SLOP_POST(((_retval.max_iterations == 1000)), "(== (. $result max-iterations) 1000)");
    SLOP_POST(((_retval.cancel_ptr == 0)), "(== (. $result cancel-ptr) 0)");
    SLOP_POST(((_retval.verbose == 0)), "(== (. $result verbose) false)");
    SLOP_POST(((_retval.clause_budget == 500000)), "(== (. $result clause-budget) 500000)");
    SLOP_POST(((_retval.strict_profile == 0)), "(== (. $result strict-profile) false)");
    SLOP_POST((({ __auto_type _mv = _retval.selection; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case howl_types_ProfileSelection_slop_auto: { _mr = 0; _mm = 1; break; } case howl_types_ProfileSelection_explicit: { __auto_type p = _mv.data.explicit; _mr = (p == howl_types_Profile_profile_el); _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; })), "(match (. $result selection) ((auto) false) ((explicit p) (== p (quote profile-el))))");
    return _retval;
}

uint8_t howl_types_cancel_requested(int64_t cancel) {
    {
        uint8_t seen = 0;
        if (cancel && __atomic_load_n((uint32_t*)(uintptr_t)cancel, __ATOMIC_RELAXED)) { seen = 1; };
        return seen;
    }
}

howl_types_Node howl_types_node_top(void) {
    return ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_THING}) });
}

howl_types_Node howl_types_node_bottom(void) {
    return ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_NOTHING}) });
}

uint8_t howl_types_node_eq(howl_types_Node a, howl_types_Node b) {
    __auto_type _mv_12 = a;
    switch (_mv_12.tag) {
        case howl_types_Node_class_node:
        {
            __auto_type ai = _mv_12.data.class_node;
            __auto_type _mv_13 = b;
            switch (_mv_13.tag) {
                case howl_types_Node_class_node:
                {
                    __auto_type bi = _mv_13.data.class_node;
                    return string_eq(ai.value, bi.value);
                }
                case howl_types_Node_individual_node:
                {
                    __auto_type _ = _mv_13.data.individual_node;
                    return 0;
                }
                case howl_types_Node_fresh_node:
                {
                    __auto_type _ = _mv_13.data.fresh_node;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_Node_individual_node:
        {
            __auto_type ai = _mv_12.data.individual_node;
            __auto_type _mv_14 = b;
            switch (_mv_14.tag) {
                case howl_types_Node_individual_node:
                {
                    __auto_type bi = _mv_14.data.individual_node;
                    return string_eq(ai.value, bi.value);
                }
                case howl_types_Node_class_node:
                {
                    __auto_type _ = _mv_14.data.class_node;
                    return 0;
                }
                case howl_types_Node_fresh_node:
                {
                    __auto_type _ = _mv_14.data.fresh_node;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_Node_fresh_node:
        {
            __auto_type ai = _mv_12.data.fresh_node;
            __auto_type _mv_15 = b;
            switch (_mv_15.tag) {
                case howl_types_Node_fresh_node:
                {
                    __auto_type bi = _mv_15.data.fresh_node;
                    return (ai == bi);
                }
                case howl_types_Node_class_node:
                {
                    __auto_type _ = _mv_15.data.class_node;
                    return 0;
                }
                case howl_types_Node_individual_node:
                {
                    __auto_type _ = _mv_15.data.individual_node;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_types_role_eq(howl_types_RoleId a, howl_types_RoleId b) {
    __auto_type _mv_16 = a;
    switch (_mv_16.tag) {
        case howl_types_RoleId_named_role:
        {
            __auto_type ai = _mv_16.data.named_role;
            __auto_type _mv_17 = b;
            switch (_mv_17.tag) {
                case howl_types_RoleId_named_role:
                {
                    __auto_type bi = _mv_17.data.named_role;
                    return string_eq(ai.value, bi.value);
                }
                case howl_types_RoleId_fresh_role:
                {
                    __auto_type _ = _mv_17.data.fresh_role;
                    return 0;
                }
                case howl_types_RoleId_inverse_role:
                {
                    __auto_type _ = _mv_17.data.inverse_role;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type ai = _mv_16.data.fresh_role;
            __auto_type _mv_18 = b;
            switch (_mv_18.tag) {
                case howl_types_RoleId_fresh_role:
                {
                    __auto_type bi = _mv_18.data.fresh_role;
                    return (ai == bi);
                }
                case howl_types_RoleId_named_role:
                {
                    __auto_type _ = _mv_18.data.named_role;
                    return 0;
                }
                case howl_types_RoleId_inverse_role:
                {
                    __auto_type _ = _mv_18.data.inverse_role;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type ai = _mv_16.data.inverse_role;
            __auto_type _mv_19 = b;
            switch (_mv_19.tag) {
                case howl_types_RoleId_inverse_role:
                {
                    __auto_type bi = _mv_19.data.inverse_role;
                    return string_eq(ai.value, bi.value);
                }
                case howl_types_RoleId_named_role:
                {
                    __auto_type _ = _mv_19.data.named_role;
                    return 0;
                }
                case howl_types_RoleId_fresh_role:
                {
                    __auto_type _ = _mv_19.data.fresh_role;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_types_kname_eq(howl_types_KName a, howl_types_KName b) {
    __auto_type _mv_20 = a;
    switch (_mv_20.tag) {
        case howl_types_KName_k_class:
        {
            __auto_type ai = _mv_20.data.k_class;
            __auto_type _mv_21 = b;
            switch (_mv_21.tag) {
                case howl_types_KName_k_class:
                {
                    __auto_type bi = _mv_21.data.k_class;
                    return string_eq(ai.value, bi.value);
                }
                case howl_types_KName_k_fresh:
                {
                    __auto_type _ = _mv_21.data.k_fresh;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_KName_k_fresh:
        {
            __auto_type ai = _mv_20.data.k_fresh;
            __auto_type _mv_22 = b;
            switch (_mv_22.tag) {
                case howl_types_KName_k_fresh:
                {
                    __auto_type bi = _mv_22.data.k_fresh;
                    return (ai == bi);
                }
                case howl_types_KName_k_class:
                {
                    __auto_type _ = _mv_22.data.k_class;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_types_kterm_eq(howl_types_KTerm a, howl_types_KTerm b) {
    __auto_type _mv_23 = a;
    switch (_mv_23.tag) {
        case howl_types_KTerm_k_name:
        {
            __auto_type ai = _mv_23.data.k_name;
            __auto_type _mv_24 = b;
            switch (_mv_24.tag) {
                case howl_types_KTerm_k_name:
                {
                    __auto_type bi = _mv_24.data.k_name;
                    return howl_types_kname_eq(ai, bi);
                }
                case howl_types_KTerm_k_nominal:
                {
                    __auto_type _ = _mv_24.data.k_nominal;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_KTerm_k_nominal:
        {
            __auto_type ai = _mv_23.data.k_nominal;
            __auto_type _mv_25 = b;
            switch (_mv_25.tag) {
                case howl_types_KTerm_k_nominal:
                {
                    __auto_type bi = _mv_25.data.k_nominal;
                    return string_eq(ai.value, bi.value);
                }
                case howl_types_KTerm_k_name:
                {
                    __auto_type _ = _mv_25.data.k_name;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_types_kelem_eq(howl_types_KElem a, howl_types_KElem b) {
    __auto_type _mv_26 = a;
    switch (_mv_26.tag) {
        case howl_types_KElem_e_ind:
        {
            __auto_type ai = _mv_26.data.e_ind;
            __auto_type _mv_27 = b;
            switch (_mv_27.tag) {
                case howl_types_KElem_e_ind:
                {
                    __auto_type bi = _mv_27.data.e_ind;
                    return string_eq(ai.value, bi.value);
                }
                case howl_types_KElem_e_aux:
                {
                    __auto_type _ = _mv_27.data.e_aux;
                    return 0;
                }
                case howl_types_KElem_e_class:
                {
                    __auto_type _ = _mv_27.data.e_class;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_KElem_e_aux:
        {
            __auto_type ai = _mv_26.data.e_aux;
            __auto_type _mv_28 = b;
            switch (_mv_28.tag) {
                case howl_types_KElem_e_aux:
                {
                    __auto_type bi = _mv_28.data.e_aux;
                    return (ai == bi);
                }
                case howl_types_KElem_e_ind:
                {
                    __auto_type _ = _mv_28.data.e_ind;
                    return 0;
                }
                case howl_types_KElem_e_class:
                {
                    __auto_type _ = _mv_28.data.e_class;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_KElem_e_class:
        {
            __auto_type ai = _mv_26.data.e_class;
            __auto_type _mv_29 = b;
            switch (_mv_29.tag) {
                case howl_types_KElem_e_class:
                {
                    __auto_type bi = _mv_29.data.e_class;
                    return howl_types_kname_eq(ai, bi);
                }
                case howl_types_KElem_e_ind:
                {
                    __auto_type _ = _mv_29.data.e_ind;
                    return 0;
                }
                case howl_types_KElem_e_aux:
                {
                    __auto_type _ = _mv_29.data.e_aux;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_types_kfact_eq(howl_types_KFact a, howl_types_KFact b) {
    __auto_type _mv_30 = a;
    switch (_mv_30.tag) {
        case howl_types_KFact_f_inst:
        {
            __auto_type x = _mv_30.data.f_inst.f0;
            __auto_type y = _mv_30.data.f_inst.f1;
            __auto_type _mv_31 = b;
            switch (_mv_31.tag) {
                case howl_types_KFact_f_inst:
                {
                    __auto_type x2 = _mv_31.data.f_inst.f0;
                    __auto_type y2 = _mv_31.data.f_inst.f1;
                    if (howl_types_kelem_eq(x, x2)) {
                        return howl_types_kterm_eq(y, y2);
                    } else {
                        return 0;
                    }
                }
                case howl_types_KFact_f_triple:
                {
                    return 0;
                }
                case howl_types_KFact_f_self:
                {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_KFact_f_triple:
        {
            __auto_type x = _mv_30.data.f_triple.f0;
            __auto_type v = _mv_30.data.f_triple.f1;
            __auto_type z = _mv_30.data.f_triple.f2;
            __auto_type _mv_32 = b;
            switch (_mv_32.tag) {
                case howl_types_KFact_f_triple:
                {
                    __auto_type x2 = _mv_32.data.f_triple.f0;
                    __auto_type v2 = _mv_32.data.f_triple.f1;
                    __auto_type z2 = _mv_32.data.f_triple.f2;
                    if (howl_types_kelem_eq(x, x2)) {
                        if (howl_types_role_eq(v, v2)) {
                            return howl_types_kelem_eq(z, z2);
                        } else {
                            return 0;
                        }
                    } else {
                        return 0;
                    }
                }
                case howl_types_KFact_f_inst:
                {
                    return 0;
                }
                case howl_types_KFact_f_self:
                {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_KFact_f_self:
        {
            __auto_type x = _mv_30.data.f_self.f0;
            __auto_type v = _mv_30.data.f_self.f1;
            __auto_type _mv_33 = b;
            switch (_mv_33.tag) {
                case howl_types_KFact_f_self:
                {
                    __auto_type x2 = _mv_33.data.f_self.f0;
                    __auto_type v2 = _mv_33.data.f_self.f1;
                    if (howl_types_kelem_eq(x, x2)) {
                        return howl_types_role_eq(v, v2);
                    } else {
                        return 0;
                    }
                }
                case howl_types_KFact_f_inst:
                {
                    return 0;
                }
                case howl_types_KFact_f_triple:
                {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_KTerm howl_types_name_term(howl_types_KName n) {
    return ((howl_types_KTerm){ .tag = howl_types_KTerm_k_name, .data.k_name = n });
}

howl_types_KTerm howl_types_nominal_term(slop_rdf_rdf_IRI a) {
    return ((howl_types_KTerm){ .tag = howl_types_KTerm_k_nominal, .data.k_nominal = a });
}

howl_types_KElem howl_types_ind_elem(slop_rdf_rdf_IRI a) {
    return ((howl_types_KElem){ .tag = howl_types_KElem_e_ind, .data.e_ind = a });
}

howl_types_KElem howl_types_aux_elem(int64_t w) {
    return ((howl_types_KElem){ .tag = howl_types_KElem_e_aux, .data.e_aux = w });
}

howl_types_KElem howl_types_class_elem(howl_types_KName q) {
    return ((howl_types_KElem){ .tag = howl_types_KElem_e_class, .data.e_class = q });
}

howl_types_KTerm howl_types_thing_term(void) {
    return ((howl_types_KTerm){ .tag = howl_types_KTerm_k_name, .data.k_name = ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_THING}) }) });
}

howl_types_KTerm howl_types_nothing_term(void) {
    return ((howl_types_KTerm){ .tag = howl_types_KTerm_k_name, .data.k_name = ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_NOTHING}) }) });
}

howl_types_ATerm howl_types_at_x(void) {
    return ((howl_types_ATerm){.kind = howl_types_AKind_ak_x, .fsym = ((uint32_t)(0)), .cst = ((uint32_t)(0)), .zi = ((uint32_t)(0))});
}

howl_types_ATerm howl_types_at_y(void) {
    return ((howl_types_ATerm){.kind = howl_types_AKind_ak_y, .fsym = ((uint32_t)(0)), .cst = ((uint32_t)(0)), .zi = ((uint32_t)(0))});
}

howl_types_ATerm howl_types_at_z(uint32_t i) {
    return ((howl_types_ATerm){.kind = howl_types_AKind_ak_z, .fsym = ((uint32_t)(0)), .cst = ((uint32_t)(0)), .zi = i});
}

howl_types_ATerm howl_types_at_fx(uint32_t f) {
    return ((howl_types_ATerm){.kind = howl_types_AKind_ak_fx, .fsym = f, .cst = ((uint32_t)(0)), .zi = ((uint32_t)(0))});
}

howl_types_ATerm howl_types_at_u(uint32_t u) {
    return ((howl_types_ATerm){.kind = howl_types_AKind_ak_u, .fsym = ((uint32_t)(0)), .cst = u, .zi = ((uint32_t)(0))});
}

howl_types_ATerm howl_types_at_fu(uint32_t f, uint32_t u) {
    return ((howl_types_ATerm){.kind = howl_types_AKind_ak_fu, .fsym = f, .cst = u, .zi = ((uint32_t)(0))});
}

int64_t howl_types_ord_int(int64_t a, int64_t b) {
    int64_t _retval = {0};
    if (a < b) {
        _retval = -1;
        goto _slop_post;
    } else if (a > b) {
        _retval = 1;
        goto _slop_post;
    } else {
        _retval = 0;
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((_retval >= -1)), "(>= $result -1)");
    SLOP_POST(((_retval <= 1)), "(<= $result 1)");
    return _retval;
}

int64_t howl_types_akind_rank(howl_types_AKind k) {
    __auto_type _mv_34 = k;
    if (_mv_34 == howl_types_AKind_ak_x) {
        return 0;
    } else if (_mv_34 == howl_types_AKind_ak_y) {
        return 1;
    } else if (_mv_34 == howl_types_AKind_ak_z) {
        return 2;
    } else if (_mv_34 == howl_types_AKind_ak_fx) {
        return 3;
    } else if (_mv_34 == howl_types_AKind_ak_u) {
        return 4;
    } else if (_mv_34 == howl_types_AKind_ak_fu) {
        return 5;
    }
    SLOP_UNREACHABLE();
}

int64_t howl_types_aterm_cmp(howl_types_ATerm a, howl_types_ATerm b) {
    int64_t _retval = {0};
    {
        __auto_type ka = howl_types_akind_rank(a.kind);
        __auto_type kb = howl_types_akind_rank(b.kind);
        if (ka != kb) {
            _retval = howl_types_ord_int(ka, kb);
            goto _slop_post;
        } else if (a.fsym != b.fsym) {
            _retval = howl_types_ord_int(((int64_t)(a.fsym)), ((int64_t)(b.fsym)));
            goto _slop_post;
        } else if (a.cst != b.cst) {
            _retval = howl_types_ord_int(((int64_t)(a.cst)), ((int64_t)(b.cst)));
            goto _slop_post;
        } else {
            _retval = howl_types_ord_int(((int64_t)(a.zi)), ((int64_t)(b.zi)));
            goto _slop_post;
        }
    }
    _slop_post: ;
    SLOP_POST(((_retval >= -1)), "(>= $result -1)");
    SLOP_POST(((_retval <= 1)), "(<= $result 1)");
    return _retval;
}

uint8_t howl_types_aterm_eq(howl_types_ATerm a, howl_types_ATerm b) {
    return (howl_types_aterm_cmp(a, b) == 0);
}

howl_types_Lit howl_types_atom1(uint32_t b, howl_types_ATerm t) {
    howl_types_Lit _retval = {0};
    _retval = ((howl_types_Lit){.form = howl_types_LitForm_lf_unary, .pred = b, .t1 = t, .t2 = howl_types_at_x()});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.form == howl_types_LitForm_lf_unary)), "(== (. $result form) (quote lf-unary))");
    return _retval;
}

howl_types_Lit howl_types_atom2(uint32_t s, howl_types_ATerm l, howl_types_ATerm r) {
    howl_types_Lit _retval = {0};
    _retval = ((howl_types_Lit){.form = howl_types_LitForm_lf_binary, .pred = s, .t1 = l, .t2 = r});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.form == howl_types_LitForm_lf_binary)), "(== (. $result form) (quote lf-binary))");
    return _retval;
}

howl_types_Lit howl_types_oriented(howl_types_LitForm form, howl_types_ATerm s, howl_types_ATerm t) {
    howl_types_Lit _retval = {0};
    if (howl_types_aterm_cmp(s, t) >= 0) {
        _retval = ((howl_types_Lit){.form = form, .pred = ((uint32_t)(0)), .t1 = s, .t2 = t});
        goto _slop_post;
    } else {
        _retval = ((howl_types_Lit){.form = form, .pred = ((uint32_t)(0)), .t1 = t, .t2 = s});
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((_retval.form == form)), "(== (. $result form) form)");
    return _retval;
}

howl_types_Lit howl_types_eq_lit(howl_types_ATerm s, howl_types_ATerm t) {
    howl_types_Lit _retval = {0};
    _retval = howl_types_oriented(howl_types_LitForm_lf_eq, s, t);
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.form == howl_types_LitForm_lf_eq)), "(== (. $result form) (quote lf-eq))");
    return _retval;
}

howl_types_Lit howl_types_neq_lit(howl_types_ATerm s, howl_types_ATerm t) {
    howl_types_Lit _retval = {0};
    _retval = howl_types_oriented(howl_types_LitForm_lf_neq, s, t);
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.form == howl_types_LitForm_lf_neq)), "(== (. $result form) (quote lf-neq))");
    return _retval;
}

int64_t howl_types_lit_form_rank(howl_types_LitForm f) {
    __auto_type _mv_35 = f;
    if (_mv_35 == howl_types_LitForm_lf_unary) {
        return 0;
    } else if (_mv_35 == howl_types_LitForm_lf_binary) {
        return 1;
    } else if (_mv_35 == howl_types_LitForm_lf_eq) {
        return 2;
    } else if (_mv_35 == howl_types_LitForm_lf_neq) {
        return 3;
    }
    SLOP_UNREACHABLE();
}

int64_t howl_types_lit_cmp(howl_types_Lit a, howl_types_Lit b) {
    int64_t _retval = {0};
    {
        __auto_type fa = howl_types_lit_form_rank(a.form);
        __auto_type fb = howl_types_lit_form_rank(b.form);
        __auto_type c1 = howl_types_aterm_cmp(a.t1, b.t1);
        if (fa != fb) {
            _retval = howl_types_ord_int(fa, fb);
            goto _slop_post;
        } else if (a.pred != b.pred) {
            _retval = howl_types_ord_int(((int64_t)(a.pred)), ((int64_t)(b.pred)));
            goto _slop_post;
        } else if (c1 != 0) {
            _retval = c1;
            goto _slop_post;
        } else {
            _retval = howl_types_aterm_cmp(a.t2, b.t2);
            goto _slop_post;
        }
    }
    _slop_post: ;
    SLOP_POST(((_retval >= -1)), "(>= $result -1)");
    SLOP_POST(((_retval <= 1)), "(<= $result 1)");
    return _retval;
}

uint8_t howl_types_lit_eq(howl_types_Lit a, howl_types_Lit b) {
    return (howl_types_lit_cmp(a, b) == 0);
}

howl_types_Names howl_types_empty_names(slop_arena* arena) {
    return ((howl_types_Names){.node_ids = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_Node, slop_hash_howl_types_Node, slop_eq_howl_types_Node, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .nodes = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, howl_types_Node); slop_map_new_ptr(arena, 0, &_d); }), .role_ids = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_RoleId, slop_hash_howl_types_RoleId, slop_eq_howl_types_RoleId, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .roles = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, howl_types_RoleId); slop_map_new_ptr(arena, 0, &_d); })});
}

howl_types_Node howl_types_intern_node(slop_arena* arena, howl_types_Names names, howl_types_Node n) {
    {
        __auto_type top = howl_types_node_top();
        __auto_type bottom = howl_types_node_bottom();
        if (howl_types_node_eq(n, top)) {
            return top;
        } else {
            if (howl_types_node_eq(n, bottom)) {
                return bottom;
            } else {
                __auto_type _mv_37 = ({ void* _ptr = slop_map_get(names.node_ids, &(n)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
                if (_mv_37.has_value) {
                    __auto_type k = _mv_37.value;
                    return ((howl_types_Node){ .tag = howl_types_Node_fresh_node, .data.fresh_node = k });
                } else if (!_mv_37.has_value) {
                    {
                        __auto_type k = ((int64_t)(((int64_t)(names.nodes)->len)));
                        __auto_type c = howl_types_copy_node(arena, n);
                        ({ int64_t _val = k; slop_map_put(NULL, names.node_ids, &(c), &_val, sizeof(_val)); });
                        ({ howl_types_Node _val = c; slop_map_put(NULL, names.nodes, &(int64_t){k}, &_val, sizeof(_val)); });
                        return ((howl_types_Node){ .tag = howl_types_Node_fresh_node, .data.fresh_node = k });
                    }
                }
                SLOP_UNREACHABLE();
            }
        }
    }
}

howl_types_RoleId howl_types_intern_role(slop_arena* arena, howl_types_Names names, howl_types_RoleId r) {
    __auto_type _mv_41 = ({ void* _ptr = slop_map_get(names.role_ids, &(r)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
    if (_mv_41.has_value) {
        __auto_type k = _mv_41.value;
        return ((howl_types_RoleId){ .tag = howl_types_RoleId_fresh_role, .data.fresh_role = k });
    } else if (!_mv_41.has_value) {
        {
            __auto_type k = ((int64_t)(((int64_t)(names.roles)->len)));
            __auto_type c = howl_types_copy_role(arena, r);
            ({ int64_t _val = k; slop_map_put(NULL, names.role_ids, &(c), &_val, sizeof(_val)); });
            ({ howl_types_RoleId _val = c; slop_map_put(NULL, names.roles, &(int64_t){k}, &_val, sizeof(_val)); });
            return ((howl_types_RoleId){ .tag = howl_types_RoleId_fresh_role, .data.fresh_role = k });
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_types_copy_string(slop_arena* arena, slop_string s) {
    return string_concat(arena, s, SLOP_STR(""));
}

slop_rdf_rdf_IRI howl_types_copy_iri(slop_arena* arena, slop_rdf_rdf_IRI i) {
    return ((slop_rdf_rdf_IRI){.value = howl_types_copy_string(arena, i.value)});
}

howl_types_Node howl_types_copy_node(slop_arena* arena, howl_types_Node n) {
    __auto_type _mv_44 = n;
    switch (_mv_44.tag) {
        case howl_types_Node_class_node:
        {
            __auto_type i = _mv_44.data.class_node;
            return ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = howl_types_copy_iri(arena, i) });
        }
        case howl_types_Node_individual_node:
        {
            __auto_type i = _mv_44.data.individual_node;
            return ((howl_types_Node){ .tag = howl_types_Node_individual_node, .data.individual_node = howl_types_copy_iri(arena, i) });
        }
        case howl_types_Node_fresh_node:
        {
            __auto_type k = _mv_44.data.fresh_node;
            return ((howl_types_Node){ .tag = howl_types_Node_fresh_node, .data.fresh_node = k });
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_RoleId howl_types_copy_role(slop_arena* arena, howl_types_RoleId r) {
    __auto_type _mv_45 = r;
    switch (_mv_45.tag) {
        case howl_types_RoleId_named_role:
        {
            __auto_type i = _mv_45.data.named_role;
            return ((howl_types_RoleId){ .tag = howl_types_RoleId_named_role, .data.named_role = howl_types_copy_iri(arena, i) });
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type k = _mv_45.data.fresh_role;
            return ((howl_types_RoleId){ .tag = howl_types_RoleId_fresh_role, .data.fresh_role = k });
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type i = _mv_45.data.inverse_role;
            return ((howl_types_RoleId){ .tag = howl_types_RoleId_inverse_role, .data.inverse_role = howl_types_copy_iri(arena, i) });
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_AxiomRef howl_types_copy_axiom_ref(slop_arena* arena, howl_types_AxiomRef a) {
    return ((howl_types_AxiomRef){.source = ({ __auto_type _mv = a.source; _mv.has_value ? ({ __auto_type i = _mv.value; (slop_option_slop_rdf_rdf_IRI){.has_value = 1, .value = howl_types_copy_iri(arena, i)}; }) : ((slop_option_slop_rdf_rdf_IRI){.has_value = false}); }), .text = howl_types_copy_string(arena, a.text)});
}

howl_types_InputRef howl_types_copy_input_ref(slop_arena* arena, howl_types_InputRef r) {
    __auto_type _mv_46 = r;
    switch (_mv_46.tag) {
        case howl_types_InputRef_owl_axiom:
        {
            __auto_type a = _mv_46.data.owl_axiom;
            return ((howl_types_InputRef){ .tag = howl_types_InputRef_owl_axiom, .data.owl_axiom = howl_types_copy_axiom_ref(arena, a) });
        }
        case howl_types_InputRef_rdf_fragment:
        {
            __auto_type s = _mv_46.data.rdf_fragment;
            return ((howl_types_InputRef){ .tag = howl_types_InputRef_rdf_fragment, .data.rdf_fragment = howl_types_copy_string(arena, s) });
        }
        case howl_types_InputRef_synthetic:
        {
            __auto_type s = _mv_46.data.synthetic;
            return ((howl_types_InputRef){ .tag = howl_types_InputRef_synthetic, .data.synthetic = howl_types_copy_string(arena, s) });
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_Omission howl_types_copy_omission(slop_arena* arena, howl_types_Omission o) {
    __auto_type _mv_47 = o;
    switch (_mv_47.tag) {
        case howl_types_Omission_out_of_profile:
        {
            __auto_type r = _mv_47.data.out_of_profile;
            return ((howl_types_Omission){ .tag = howl_types_Omission_out_of_profile, .data.out_of_profile = howl_types_copy_input_ref(arena, r) });
        }
        case howl_types_Omission_unresolved_import:
        {
            __auto_type i = _mv_47.data.unresolved_import;
            return ((howl_types_Omission){ .tag = howl_types_Omission_unresolved_import, .data.unresolved_import = howl_types_copy_iri(arena, i) });
        }
        case howl_types_Omission_missing_declaration:
        {
            __auto_type m = _mv_47.data.missing_declaration;
            {
                __auto_type refs = ((slop_list_howl_types_AxiomRef){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                {
                    __auto_type _coll = m.referring;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type a = _coll.data[_i];
                        ({ __auto_type _lst_p = &(refs); __auto_type _item = (howl_types_copy_axiom_ref(arena, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                return ((howl_types_Omission){ .tag = howl_types_Omission_missing_declaration, .data.missing_declaration = ((howl_types_MissingDeclaration){.kind = m.kind, .entity = howl_types_copy_iri(arena, m.entity), .referring = refs}) });
            }
        }
        case howl_types_Omission_undeclared_property:
        {
            __auto_type u = _mv_47.data.undeclared_property;
            {
                __auto_type refs = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                {
                    __auto_type _coll = u.referring;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type s = _coll.data[_i];
                        ({ __auto_type _lst_p = &(refs); __auto_type _item = (howl_types_copy_string(arena, s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                return ((howl_types_Omission){ .tag = howl_types_Omission_undeclared_property, .data.undeclared_property = ((howl_types_UndeclaredProperty){.property = howl_types_copy_iri(arena, u.property), .referring = refs}) });
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Omission howl_types_copy_omissions(slop_arena* arena, slop_list_howl_types_Omission os) {
    {
        __auto_type out = ((slop_list_howl_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = os;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_types_copy_omission(arena, o)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_types_Fault howl_types_copy_fault(slop_arena* arena, howl_types_Fault f) {
    __auto_type _mv_48 = f;
    switch (_mv_48.tag) {
        case howl_types_Fault_cancelled:
        {
            return ((howl_types_Fault){ .tag = howl_types_Fault_cancelled });
        }
        case howl_types_Fault_input_error:
        {
            __auto_type m = _mv_48.data.input_error;
            return ((howl_types_Fault){ .tag = howl_types_Fault_input_error, .data.input_error = howl_types_copy_string(arena, m) });
        }
        case howl_types_Fault_refused:
        {
            __auto_type os = _mv_48.data.refused;
            return ((howl_types_Fault){ .tag = howl_types_Fault_refused, .data.refused = howl_types_copy_omissions(arena, os) });
        }
        case howl_types_Fault_unavailable:
        {
            __auto_type p = _mv_48.data.unavailable;
            return ((howl_types_Fault){ .tag = howl_types_Fault_unavailable, .data.unavailable = p });
        }
    }
    SLOP_UNREACHABLE();
}

slop_option_howl_types_Node howl_types_renamed_node(howl_types_Names names, howl_types_Node n) {
    __auto_type _mv_50 = ({ void* _ptr = slop_map_get(names.node_ids, &(n)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
    if (_mv_50.has_value) {
        __auto_type k = _mv_50.value;
        return (slop_option_howl_types_Node){.has_value = 1, .value = ((howl_types_Node){ .tag = howl_types_Node_fresh_node, .data.fresh_node = k })};
    } else if (!_mv_50.has_value) {
        __auto_type _mv_51 = n;
        switch (_mv_51.tag) {
            case howl_types_Node_fresh_node:
            {
                __auto_type _ = _mv_51.data.fresh_node;
                if (((int64_t)(names.nodes)->len) == 0) {
                    return (slop_option_howl_types_Node){.has_value = 1, .value = n};
                } else {
                    return (slop_option_howl_types_Node){.has_value = false};
                }
            }
            case howl_types_Node_class_node:
            {
                __auto_type _ = _mv_51.data.class_node;
                return (slop_option_howl_types_Node){.has_value = 1, .value = n};
            }
            case howl_types_Node_individual_node:
            {
                __auto_type _ = _mv_51.data.individual_node;
                return (slop_option_howl_types_Node){.has_value = 1, .value = n};
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

howl_types_Node howl_types_original_node(howl_types_Names names, howl_types_Node n) {
    __auto_type _mv_52 = n;
    switch (_mv_52.tag) {
        case howl_types_Node_fresh_node:
        {
            __auto_type k = _mv_52.data.fresh_node;
            __auto_type _mv_54 = ({ void* _ptr = slop_map_get(names.nodes, &(int64_t){k}); _ptr ? (slop_option_howl_types_Node){ .has_value = true, .value = *(howl_types_Node*)_ptr } : (slop_option_howl_types_Node){ .has_value = false }; });
            if (_mv_54.has_value) {
                __auto_type o = _mv_54.value;
                return o;
            } else if (!_mv_54.has_value) {
                return n;
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_Node_class_node:
        {
            __auto_type _ = _mv_52.data.class_node;
            return n;
        }
        case howl_types_Node_individual_node:
        {
            __auto_type _ = _mv_52.data.individual_node;
            return n;
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_RoleId howl_types_original_role(howl_types_Names names, howl_types_RoleId r) {
    __auto_type _mv_55 = r;
    switch (_mv_55.tag) {
        case howl_types_RoleId_fresh_role:
        {
            __auto_type k = _mv_55.data.fresh_role;
            __auto_type _mv_57 = ({ void* _ptr = slop_map_get(names.roles, &(int64_t){k}); _ptr ? (slop_option_howl_types_RoleId){ .has_value = true, .value = *(howl_types_RoleId*)_ptr } : (slop_option_howl_types_RoleId){ .has_value = false }; });
            if (_mv_57.has_value) {
                __auto_type o = _mv_57.value;
                return o;
            } else if (!_mv_57.has_value) {
                return r;
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_RoleId_named_role:
        {
            __auto_type _ = _mv_55.data.named_role;
            return r;
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type _ = _mv_55.data.inverse_role;
            return r;
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_Context howl_types_make_context(slop_arena* arena, howl_types_Node root) {
    howl_types_Context _retval = {0};
    _retval = ((howl_types_Context){.root = root, .subsumers = ({ static const slop_map_desc _d = SLOP_SET_DESC(howl_types_Node, slop_hash_howl_types_Node, slop_eq_howl_types_Node, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .succs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_RoleId, slop_hash_howl_types_RoleId, slop_eq_howl_types_RoleId, SLOP_KEY_HASHED, slop_map*); slop_map_new_ptr(arena, 0, &_d); }), .preds = ({ static const slop_map_desc _d = SLOP_MAP_DESC(howl_types_RoleId, slop_hash_howl_types_RoleId, slop_eq_howl_types_RoleId, SLOP_KEY_HASHED, slop_map*); slop_map_new_ptr(arena, 0, &_d); })});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST((({ howl_types_Node _eq_l_58 = (_retval.root); howl_types_Node _eq_r_59 = (root); slop_eq_howl_types_Node(&_eq_l_58, &_eq_r_59); })), "(== (. $result root) root)");
    return _retval;
}

howl_types_Queue howl_types_make_queue(slop_arena* arena) {
    howl_types_Queue _retval = {0};
    _retval = ((howl_types_Queue){.items = ((slop_list_howl_types_Derived){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval.items).len)) == 0)), "(== (list-len (. $result items)) 0)");
    return _retval;
}

uint8_t howl_types_queue_is_active(howl_types_Queue q) {
    uint8_t _retval = {0};
    _retval = (((int64_t)((q.items).len)) > 0);
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval == (((int64_t)((q.items).len)) > 0))), "(== $result (> (list-len (. q items)) 0))");
    return _retval;
}

uint8_t howl_types_derived_eq(howl_types_Derived a, howl_types_Derived b) {
    __auto_type _mv_60 = a;
    switch (_mv_60.tag) {
        case howl_types_Derived_derived_sub:
        {
            __auto_type an = _mv_60.data.derived_sub;
            __auto_type _mv_61 = b;
            switch (_mv_61.tag) {
                case howl_types_Derived_derived_sub:
                {
                    __auto_type bn = _mv_61.data.derived_sub;
                    return howl_types_node_eq(an, bn);
                }
                case howl_types_Derived_derived_succ:
                {
                    return 0;
                }
                case howl_types_Derived_derived_pred:
                {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_Derived_derived_succ:
        {
            __auto_type ar = _mv_60.data.derived_succ.f0;
            __auto_type an = _mv_60.data.derived_succ.f1;
            __auto_type _mv_62 = b;
            switch (_mv_62.tag) {
                case howl_types_Derived_derived_succ:
                {
                    __auto_type br = _mv_62.data.derived_succ.f0;
                    __auto_type bn = _mv_62.data.derived_succ.f1;
                    if (howl_types_role_eq(ar, br)) {
                        return howl_types_node_eq(an, bn);
                    } else {
                        return 0;
                    }
                }
                case howl_types_Derived_derived_sub:
                {
                    __auto_type _ = _mv_62.data.derived_sub;
                    return 0;
                }
                case howl_types_Derived_derived_pred:
                {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_Derived_derived_pred:
        {
            __auto_type ar = _mv_60.data.derived_pred.f0;
            __auto_type an = _mv_60.data.derived_pred.f1;
            __auto_type _mv_63 = b;
            switch (_mv_63.tag) {
                case howl_types_Derived_derived_pred:
                {
                    __auto_type br = _mv_63.data.derived_pred.f0;
                    __auto_type bn = _mv_63.data.derived_pred.f1;
                    if (howl_types_role_eq(ar, br)) {
                        return howl_types_node_eq(an, bn);
                    } else {
                        return 0;
                    }
                }
                case howl_types_Derived_derived_sub:
                {
                    __auto_type _ = _mv_63.data.derived_sub;
                    return 0;
                }
                case howl_types_Derived_derived_succ:
                {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_types_addressed_eq(howl_types_Addressed a, howl_types_Addressed b) {
    if (howl_types_node_eq(a.to, b.to)) {
        return howl_types_derived_eq(a.what, b.what);
    } else {
        return 0;
    }
}

howl_types_EdgePair howl_types_emit_edge(slop_arena* arena, howl_types_LogicalEdge e) {
    howl_types_EdgePair _retval = {0};
    _retval = ((howl_types_EdgePair){.succ_half = ((howl_types_Addressed){.to = e.from, .what = ((howl_types_Derived){ .tag = howl_types_Derived_derived_succ, .data.derived_succ = { .f0 = e.role, .f1 = e.to } })}), .pred_half = ((howl_types_Addressed){.to = e.to, .what = ((howl_types_Derived){ .tag = howl_types_Derived_derived_pred, .data.derived_pred = { .f0 = e.role, .f1 = e.from } })})});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST((({ howl_types_Node _eq_l_64 = (_retval.succ_half.to); howl_types_Node _eq_r_65 = (e.from); slop_eq_howl_types_Node(&_eq_l_64, &_eq_r_65); })), "(== (. (. $result succ-half) to) (. e from))");
    SLOP_POST((({ howl_types_Node _eq_l_66 = (_retval.pred_half.to); howl_types_Node _eq_r_67 = (e.to); slop_eq_howl_types_Node(&_eq_l_66, &_eq_r_67); })), "(== (. (. $result pred-half) to) (. e to))");
    return _retval;
}

uint8_t howl_types_outcome_is_complete(howl_types_Outcome o) {
    uint8_t _retval = {0};
    _retval = ((((int64_t)((o.coverage.omitted).len)) == 0) && ({ __auto_type _mv = o.termination; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case howl_types_Termination_fixpoint: { _mr = 1; _mm = 1; break; } case howl_types_Termination_resource_limit: { _mr = 0; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }));
    goto _slop_post;
    _slop_post: ;
    return _retval;
}

uint8_t howl_types_findings_are_incoherent(howl_types_Findings f) {
    uint8_t _retval = {0};
    if (((int64_t)((f.unsatisfiable).len)) > 0) {
        _retval = 1;
        goto _slop_post;
    } else {
        _retval = f.inconsistent;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

howl_types_Verdict howl_types_verdict(howl_types_Outcome o) {
    howl_types_Verdict _retval = {0};
    if (howl_types_findings_are_incoherent(o.findings)) {
        _retval = howl_types_Verdict_verdict_incoherent;
        goto _slop_post;
    } else {
        if (((int64_t)((o.coverage.omitted).len)) > 0) {
            _retval = howl_types_Verdict_verdict_inconclusive;
            goto _slop_post;
        } else {
            if (howl_types_outcome_is_complete(o)) {
                _retval = howl_types_Verdict_verdict_coherent;
                goto _slop_post;
            } else {
                _retval = howl_types_Verdict_verdict_inconclusive;
                goto _slop_post;
            }
        }
    }
    _slop_post: ;
    return _retval;
}

