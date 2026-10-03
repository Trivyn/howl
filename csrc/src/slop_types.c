#include "../runtime/slop_runtime.h"
#include "slop_types.h"

types_ReasonerConfig howl_default_config(void);
types_Node types_node_top(void);
types_Node types_node_bottom(void);
uint8_t types_node_eq(types_Node a, types_Node b);
uint8_t types_role_eq(types_RoleId a, types_RoleId b);
uint8_t types_kname_eq(types_KName a, types_KName b);
uint8_t types_kterm_eq(types_KTerm a, types_KTerm b);
uint8_t types_kelem_eq(types_KElem a, types_KElem b);
uint8_t types_kfact_eq(types_KFact a, types_KFact b);
types_KTerm types_name_term(types_KName n);
types_KTerm types_nominal_term(rdf_IRI a);
types_KElem types_ind_elem(rdf_IRI a);
types_KElem types_aux_elem(int64_t w);
types_KElem types_class_elem(types_KName q);
types_KTerm types_thing_term(void);
types_KTerm types_nothing_term(void);
types_Names types_empty_names(slop_arena* arena);
types_Node types_intern_node(slop_arena* arena, types_Names names, types_Node n);
types_RoleId types_intern_role(slop_arena* arena, types_Names names, types_RoleId r);
slop_string types_copy_string(slop_arena* arena, slop_string s);
rdf_IRI types_copy_iri(slop_arena* arena, rdf_IRI i);
types_Node types_copy_node(slop_arena* arena, types_Node n);
types_RoleId types_copy_role(slop_arena* arena, types_RoleId r);
types_AxiomRef types_copy_axiom_ref(slop_arena* arena, types_AxiomRef a);
types_InputRef types_copy_input_ref(slop_arena* arena, types_InputRef r);
types_Omission types_copy_omission(slop_arena* arena, types_Omission o);
slop_list_types_Omission types_copy_omissions(slop_arena* arena, slop_list_types_Omission os);
types_Fault types_copy_fault(slop_arena* arena, types_Fault f);
slop_option_types_Node types_renamed_node(types_Names names, types_Node n);
types_Node types_original_node(types_Names names, types_Node n);
types_RoleId types_original_role(types_Names names, types_RoleId r);
types_Context types_make_context(slop_arena* arena, types_Node root);
types_Queue types_make_queue(slop_arena* arena);
uint8_t types_queue_is_active(types_Queue q);
uint8_t types_derived_eq(types_Derived a, types_Derived b);
uint8_t types_addressed_eq(types_Addressed a, types_Addressed b);
types_EdgePair types_emit_edge(slop_arena* arena, types_LogicalEdge e);
uint8_t types_outcome_is_complete(types_Outcome o);
uint8_t types_findings_are_incoherent(types_Findings f);

types_ReasonerConfig howl_default_config(void) {
    types_ReasonerConfig _retval = {0};
    _retval = ((types_ReasonerConfig){.worker_count = 4, .channel_buffer = 256, .max_iterations = 1000, .selection = ((types_ProfileSelection){ .tag = types_ProfileSelection_explicit, .data.explicit = types_Profile_profile_el }), .strict_profile = 0, .cancel_ptr = 0, .verbose = 0});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.worker_count == 4)), "(== (. $result worker-count) 4)");
    SLOP_POST(((_retval.channel_buffer == 256)), "(== (. $result channel-buffer) 256)");
    SLOP_POST(((_retval.max_iterations == 1000)), "(== (. $result max-iterations) 1000)");
    SLOP_POST(((_retval.cancel_ptr == 0)), "(== (. $result cancel-ptr) 0)");
    SLOP_POST(((_retval.verbose == 0)), "(== (. $result verbose) false)");
    SLOP_POST(((_retval.strict_profile == 0)), "(== (. $result strict-profile) false)");
    SLOP_POST((({ __auto_type _mv = _retval.selection; uint8_t _mr = {0}; switch (_mv.tag) { case types_ProfileSelection_slop_auto: { _mr = 0; break; } case types_ProfileSelection_explicit: { __auto_type p = _mv.data.explicit; _mr = (p == types_Profile_profile_el); break; }  } _mr; })), "(match (. $result selection) ((auto) false) ((explicit p) (== p (quote profile-el))))");
    return _retval;
}

types_Node types_node_top(void) {
    return ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = vocab_OWL_THING}) });
}

types_Node types_node_bottom(void) {
    return ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = vocab_OWL_NOTHING}) });
}

uint8_t types_node_eq(types_Node a, types_Node b) {
    __auto_type _mv_12 = a;
    switch (_mv_12.tag) {
        case types_Node_class_node:
        {
            __auto_type ai = _mv_12.data.class_node;
            __auto_type _mv_13 = b;
            switch (_mv_13.tag) {
                case types_Node_class_node:
                {
                    __auto_type bi = _mv_13.data.class_node;
                    return string_eq(ai.value, bi.value);
                }
                case types_Node_individual_node:
                {
                    __auto_type _ = _mv_13.data.individual_node;
                    return 0;
                }
                case types_Node_fresh_node:
                {
                    __auto_type _ = _mv_13.data.fresh_node;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_Node_individual_node:
        {
            __auto_type ai = _mv_12.data.individual_node;
            __auto_type _mv_14 = b;
            switch (_mv_14.tag) {
                case types_Node_individual_node:
                {
                    __auto_type bi = _mv_14.data.individual_node;
                    return string_eq(ai.value, bi.value);
                }
                case types_Node_class_node:
                {
                    __auto_type _ = _mv_14.data.class_node;
                    return 0;
                }
                case types_Node_fresh_node:
                {
                    __auto_type _ = _mv_14.data.fresh_node;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_Node_fresh_node:
        {
            __auto_type ai = _mv_12.data.fresh_node;
            __auto_type _mv_15 = b;
            switch (_mv_15.tag) {
                case types_Node_fresh_node:
                {
                    __auto_type bi = _mv_15.data.fresh_node;
                    return (ai == bi);
                }
                case types_Node_class_node:
                {
                    __auto_type _ = _mv_15.data.class_node;
                    return 0;
                }
                case types_Node_individual_node:
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

uint8_t types_role_eq(types_RoleId a, types_RoleId b) {
    __auto_type _mv_16 = a;
    switch (_mv_16.tag) {
        case types_RoleId_named_role:
        {
            __auto_type ai = _mv_16.data.named_role;
            __auto_type _mv_17 = b;
            switch (_mv_17.tag) {
                case types_RoleId_named_role:
                {
                    __auto_type bi = _mv_17.data.named_role;
                    return string_eq(ai.value, bi.value);
                }
                case types_RoleId_fresh_role:
                {
                    __auto_type _ = _mv_17.data.fresh_role;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_RoleId_fresh_role:
        {
            __auto_type ai = _mv_16.data.fresh_role;
            __auto_type _mv_18 = b;
            switch (_mv_18.tag) {
                case types_RoleId_fresh_role:
                {
                    __auto_type bi = _mv_18.data.fresh_role;
                    return (ai == bi);
                }
                case types_RoleId_named_role:
                {
                    __auto_type _ = _mv_18.data.named_role;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t types_kname_eq(types_KName a, types_KName b) {
    __auto_type _mv_19 = a;
    switch (_mv_19.tag) {
        case types_KName_k_class:
        {
            __auto_type ai = _mv_19.data.k_class;
            __auto_type _mv_20 = b;
            switch (_mv_20.tag) {
                case types_KName_k_class:
                {
                    __auto_type bi = _mv_20.data.k_class;
                    return string_eq(ai.value, bi.value);
                }
                case types_KName_k_fresh:
                {
                    __auto_type _ = _mv_20.data.k_fresh;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_KName_k_fresh:
        {
            __auto_type ai = _mv_19.data.k_fresh;
            __auto_type _mv_21 = b;
            switch (_mv_21.tag) {
                case types_KName_k_fresh:
                {
                    __auto_type bi = _mv_21.data.k_fresh;
                    return (ai == bi);
                }
                case types_KName_k_class:
                {
                    __auto_type _ = _mv_21.data.k_class;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t types_kterm_eq(types_KTerm a, types_KTerm b) {
    __auto_type _mv_22 = a;
    switch (_mv_22.tag) {
        case types_KTerm_k_name:
        {
            __auto_type ai = _mv_22.data.k_name;
            __auto_type _mv_23 = b;
            switch (_mv_23.tag) {
                case types_KTerm_k_name:
                {
                    __auto_type bi = _mv_23.data.k_name;
                    return types_kname_eq(ai, bi);
                }
                case types_KTerm_k_nominal:
                {
                    __auto_type _ = _mv_23.data.k_nominal;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_KTerm_k_nominal:
        {
            __auto_type ai = _mv_22.data.k_nominal;
            __auto_type _mv_24 = b;
            switch (_mv_24.tag) {
                case types_KTerm_k_nominal:
                {
                    __auto_type bi = _mv_24.data.k_nominal;
                    return string_eq(ai.value, bi.value);
                }
                case types_KTerm_k_name:
                {
                    __auto_type _ = _mv_24.data.k_name;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t types_kelem_eq(types_KElem a, types_KElem b) {
    __auto_type _mv_25 = a;
    switch (_mv_25.tag) {
        case types_KElem_e_ind:
        {
            __auto_type ai = _mv_25.data.e_ind;
            __auto_type _mv_26 = b;
            switch (_mv_26.tag) {
                case types_KElem_e_ind:
                {
                    __auto_type bi = _mv_26.data.e_ind;
                    return string_eq(ai.value, bi.value);
                }
                case types_KElem_e_aux:
                {
                    __auto_type _ = _mv_26.data.e_aux;
                    return 0;
                }
                case types_KElem_e_class:
                {
                    __auto_type _ = _mv_26.data.e_class;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_KElem_e_aux:
        {
            __auto_type ai = _mv_25.data.e_aux;
            __auto_type _mv_27 = b;
            switch (_mv_27.tag) {
                case types_KElem_e_aux:
                {
                    __auto_type bi = _mv_27.data.e_aux;
                    return (ai == bi);
                }
                case types_KElem_e_ind:
                {
                    __auto_type _ = _mv_27.data.e_ind;
                    return 0;
                }
                case types_KElem_e_class:
                {
                    __auto_type _ = _mv_27.data.e_class;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_KElem_e_class:
        {
            __auto_type ai = _mv_25.data.e_class;
            __auto_type _mv_28 = b;
            switch (_mv_28.tag) {
                case types_KElem_e_class:
                {
                    __auto_type bi = _mv_28.data.e_class;
                    return types_kname_eq(ai, bi);
                }
                case types_KElem_e_ind:
                {
                    __auto_type _ = _mv_28.data.e_ind;
                    return 0;
                }
                case types_KElem_e_aux:
                {
                    __auto_type _ = _mv_28.data.e_aux;
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t types_kfact_eq(types_KFact a, types_KFact b) {
    __auto_type _mv_29 = a;
    switch (_mv_29.tag) {
        case types_KFact_f_inst:
        {
            __auto_type x = _mv_29.data.f_inst.f0;
            __auto_type y = _mv_29.data.f_inst.f1;
            __auto_type _mv_30 = b;
            switch (_mv_30.tag) {
                case types_KFact_f_inst:
                {
                    __auto_type x2 = _mv_30.data.f_inst.f0;
                    __auto_type y2 = _mv_30.data.f_inst.f1;
                    if (types_kelem_eq(x, x2)) {
                        return types_kterm_eq(y, y2);
                    } else {
                        return 0;
                    }
                }
                case types_KFact_f_triple:
                {
                    return 0;
                }
                case types_KFact_f_self:
                {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_KFact_f_triple:
        {
            __auto_type x = _mv_29.data.f_triple.f0;
            __auto_type v = _mv_29.data.f_triple.f1;
            __auto_type z = _mv_29.data.f_triple.f2;
            __auto_type _mv_31 = b;
            switch (_mv_31.tag) {
                case types_KFact_f_triple:
                {
                    __auto_type x2 = _mv_31.data.f_triple.f0;
                    __auto_type v2 = _mv_31.data.f_triple.f1;
                    __auto_type z2 = _mv_31.data.f_triple.f2;
                    if (types_kelem_eq(x, x2)) {
                        if (types_role_eq(v, v2)) {
                            return types_kelem_eq(z, z2);
                        } else {
                            return 0;
                        }
                    } else {
                        return 0;
                    }
                }
                case types_KFact_f_inst:
                {
                    return 0;
                }
                case types_KFact_f_self:
                {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_KFact_f_self:
        {
            __auto_type x = _mv_29.data.f_self.f0;
            __auto_type v = _mv_29.data.f_self.f1;
            __auto_type _mv_32 = b;
            switch (_mv_32.tag) {
                case types_KFact_f_self:
                {
                    __auto_type x2 = _mv_32.data.f_self.f0;
                    __auto_type v2 = _mv_32.data.f_self.f1;
                    if (types_kelem_eq(x, x2)) {
                        return types_role_eq(v, v2);
                    } else {
                        return 0;
                    }
                }
                case types_KFact_f_inst:
                {
                    return 0;
                }
                case types_KFact_f_triple:
                {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

types_KTerm types_name_term(types_KName n) {
    return ((types_KTerm){ .tag = types_KTerm_k_name, .data.k_name = n });
}

types_KTerm types_nominal_term(rdf_IRI a) {
    return ((types_KTerm){ .tag = types_KTerm_k_nominal, .data.k_nominal = a });
}

types_KElem types_ind_elem(rdf_IRI a) {
    return ((types_KElem){ .tag = types_KElem_e_ind, .data.e_ind = a });
}

types_KElem types_aux_elem(int64_t w) {
    return ((types_KElem){ .tag = types_KElem_e_aux, .data.e_aux = w });
}

types_KElem types_class_elem(types_KName q) {
    return ((types_KElem){ .tag = types_KElem_e_class, .data.e_class = q });
}

types_KTerm types_thing_term(void) {
    return ((types_KTerm){ .tag = types_KTerm_k_name, .data.k_name = ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = vocab_OWL_THING}) }) });
}

types_KTerm types_nothing_term(void) {
    return ((types_KTerm){ .tag = types_KTerm_k_name, .data.k_name = ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = vocab_OWL_NOTHING}) }) });
}

types_Names types_empty_names(slop_arena* arena) {
    return ((types_Names){.node_ids = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .nodes = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, types_Node); slop_map_new_ptr(arena, 0, &_d); }), .role_ids = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .roles = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, types_RoleId); slop_map_new_ptr(arena, 0, &_d); })});
}

types_Node types_intern_node(slop_arena* arena, types_Names names, types_Node n) {
    {
        __auto_type top = types_node_top();
        __auto_type bottom = types_node_bottom();
        if (types_node_eq(n, top)) {
            return top;
        } else {
            if (types_node_eq(n, bottom)) {
                return bottom;
            } else {
                __auto_type _mv_34 = ({ void* _ptr = slop_map_get(names.node_ids, &(n)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
                if (_mv_34.has_value) {
                    __auto_type k = _mv_34.value;
                    return ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = k });
                } else if (!_mv_34.has_value) {
                    {
                        __auto_type k = ((int64_t)(((int64_t)(names.nodes)->len)));
                        __auto_type c = types_copy_node(arena, n);
                        ({ int64_t _val = k; slop_map_put(NULL, names.node_ids, &(c), &_val, sizeof(_val)); });
                        ({ types_Node _val = c; slop_map_put(NULL, names.nodes, &(int64_t){k}, &_val, sizeof(_val)); });
                        return ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = k });
                    }
                }
                SLOP_UNREACHABLE();
            }
        }
    }
}

types_RoleId types_intern_role(slop_arena* arena, types_Names names, types_RoleId r) {
    __auto_type _mv_38 = ({ void* _ptr = slop_map_get(names.role_ids, &(r)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
    if (_mv_38.has_value) {
        __auto_type k = _mv_38.value;
        return ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = k });
    } else if (!_mv_38.has_value) {
        {
            __auto_type k = ((int64_t)(((int64_t)(names.roles)->len)));
            __auto_type c = types_copy_role(arena, r);
            ({ int64_t _val = k; slop_map_put(NULL, names.role_ids, &(c), &_val, sizeof(_val)); });
            ({ types_RoleId _val = c; slop_map_put(NULL, names.roles, &(int64_t){k}, &_val, sizeof(_val)); });
            return ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = k });
        }
    }
    SLOP_UNREACHABLE();
}

slop_string types_copy_string(slop_arena* arena, slop_string s) {
    return string_concat(arena, s, SLOP_STR(""));
}

rdf_IRI types_copy_iri(slop_arena* arena, rdf_IRI i) {
    return ((rdf_IRI){.value = types_copy_string(arena, i.value)});
}

types_Node types_copy_node(slop_arena* arena, types_Node n) {
    __auto_type _mv_41 = n;
    switch (_mv_41.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_41.data.class_node;
            return ((types_Node){ .tag = types_Node_class_node, .data.class_node = types_copy_iri(arena, i) });
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_41.data.individual_node;
            return ((types_Node){ .tag = types_Node_individual_node, .data.individual_node = types_copy_iri(arena, i) });
        }
        case types_Node_fresh_node:
        {
            __auto_type k = _mv_41.data.fresh_node;
            return ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = k });
        }
    }
    SLOP_UNREACHABLE();
}

types_RoleId types_copy_role(slop_arena* arena, types_RoleId r) {
    __auto_type _mv_42 = r;
    switch (_mv_42.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_42.data.named_role;
            return ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = types_copy_iri(arena, i) });
        }
        case types_RoleId_fresh_role:
        {
            __auto_type k = _mv_42.data.fresh_role;
            return ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = k });
        }
    }
    SLOP_UNREACHABLE();
}

types_AxiomRef types_copy_axiom_ref(slop_arena* arena, types_AxiomRef a) {
    return ((types_AxiomRef){.source = ({ __auto_type _mv = a.source; _mv.has_value ? ({ __auto_type i = _mv.value; (slop_option_rdf_IRI){.has_value = 1, .value = types_copy_iri(arena, i)}; }) : ((slop_option_rdf_IRI){.has_value = false}); }), .text = types_copy_string(arena, a.text)});
}

types_InputRef types_copy_input_ref(slop_arena* arena, types_InputRef r) {
    __auto_type _mv_43 = r;
    switch (_mv_43.tag) {
        case types_InputRef_owl_axiom:
        {
            __auto_type a = _mv_43.data.owl_axiom;
            return ((types_InputRef){ .tag = types_InputRef_owl_axiom, .data.owl_axiom = types_copy_axiom_ref(arena, a) });
        }
        case types_InputRef_rdf_fragment:
        {
            __auto_type s = _mv_43.data.rdf_fragment;
            return ((types_InputRef){ .tag = types_InputRef_rdf_fragment, .data.rdf_fragment = types_copy_string(arena, s) });
        }
        case types_InputRef_synthetic:
        {
            __auto_type s = _mv_43.data.synthetic;
            return ((types_InputRef){ .tag = types_InputRef_synthetic, .data.synthetic = types_copy_string(arena, s) });
        }
    }
    SLOP_UNREACHABLE();
}

types_Omission types_copy_omission(slop_arena* arena, types_Omission o) {
    __auto_type _mv_44 = o;
    switch (_mv_44.tag) {
        case types_Omission_out_of_profile:
        {
            __auto_type r = _mv_44.data.out_of_profile;
            return ((types_Omission){ .tag = types_Omission_out_of_profile, .data.out_of_profile = types_copy_input_ref(arena, r) });
        }
        case types_Omission_unresolved_import:
        {
            __auto_type i = _mv_44.data.unresolved_import;
            return ((types_Omission){ .tag = types_Omission_unresolved_import, .data.unresolved_import = types_copy_iri(arena, i) });
        }
        case types_Omission_missing_declaration:
        {
            __auto_type m = _mv_44.data.missing_declaration;
            {
                __auto_type refs = ((slop_list_types_AxiomRef){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                {
                    __auto_type _coll = m.referring;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type a = _coll.data[_i];
                        ({ __auto_type _lst_p = &(refs); __auto_type _item = (types_copy_axiom_ref(arena, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                return ((types_Omission){ .tag = types_Omission_missing_declaration, .data.missing_declaration = ((types_MissingDeclaration){.kind = m.kind, .entity = types_copy_iri(arena, m.entity), .referring = refs}) });
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_types_Omission types_copy_omissions(slop_arena* arena, slop_list_types_Omission os) {
    {
        __auto_type out = ((slop_list_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = os;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (types_copy_omission(arena, o)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

types_Fault types_copy_fault(slop_arena* arena, types_Fault f) {
    __auto_type _mv_45 = f;
    switch (_mv_45.tag) {
        case types_Fault_cancelled:
        {
            return ((types_Fault){ .tag = types_Fault_cancelled });
        }
        case types_Fault_input_error:
        {
            __auto_type m = _mv_45.data.input_error;
            return ((types_Fault){ .tag = types_Fault_input_error, .data.input_error = types_copy_string(arena, m) });
        }
        case types_Fault_refused:
        {
            __auto_type os = _mv_45.data.refused;
            return ((types_Fault){ .tag = types_Fault_refused, .data.refused = types_copy_omissions(arena, os) });
        }
        case types_Fault_unavailable:
        {
            __auto_type p = _mv_45.data.unavailable;
            return ((types_Fault){ .tag = types_Fault_unavailable, .data.unavailable = p });
        }
    }
    SLOP_UNREACHABLE();
}

slop_option_types_Node types_renamed_node(types_Names names, types_Node n) {
    __auto_type _mv_47 = ({ void* _ptr = slop_map_get(names.node_ids, &(n)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
    if (_mv_47.has_value) {
        __auto_type k = _mv_47.value;
        return (slop_option_types_Node){.has_value = 1, .value = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = k })};
    } else if (!_mv_47.has_value) {
        __auto_type _mv_48 = n;
        switch (_mv_48.tag) {
            case types_Node_fresh_node:
            {
                __auto_type _ = _mv_48.data.fresh_node;
                if (((int64_t)(names.nodes)->len) == 0) {
                    return (slop_option_types_Node){.has_value = 1, .value = n};
                } else {
                    return (slop_option_types_Node){.has_value = false};
                }
            }
            case types_Node_class_node:
            {
                __auto_type _ = _mv_48.data.class_node;
                return (slop_option_types_Node){.has_value = 1, .value = n};
            }
            case types_Node_individual_node:
            {
                __auto_type _ = _mv_48.data.individual_node;
                return (slop_option_types_Node){.has_value = 1, .value = n};
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

types_Node types_original_node(types_Names names, types_Node n) {
    __auto_type _mv_49 = n;
    switch (_mv_49.tag) {
        case types_Node_fresh_node:
        {
            __auto_type k = _mv_49.data.fresh_node;
            __auto_type _mv_51 = ({ void* _ptr = slop_map_get(names.nodes, &(int64_t){k}); _ptr ? (slop_option_types_Node){ .has_value = true, .value = *(types_Node*)_ptr } : (slop_option_types_Node){ .has_value = false }; });
            if (_mv_51.has_value) {
                __auto_type o = _mv_51.value;
                return o;
            } else if (!_mv_51.has_value) {
                return n;
            }
            SLOP_UNREACHABLE();
        }
        case types_Node_class_node:
        {
            __auto_type _ = _mv_49.data.class_node;
            return n;
        }
        case types_Node_individual_node:
        {
            __auto_type _ = _mv_49.data.individual_node;
            return n;
        }
    }
    SLOP_UNREACHABLE();
}

types_RoleId types_original_role(types_Names names, types_RoleId r) {
    __auto_type _mv_52 = r;
    switch (_mv_52.tag) {
        case types_RoleId_fresh_role:
        {
            __auto_type k = _mv_52.data.fresh_role;
            __auto_type _mv_54 = ({ void* _ptr = slop_map_get(names.roles, &(int64_t){k}); _ptr ? (slop_option_types_RoleId){ .has_value = true, .value = *(types_RoleId*)_ptr } : (slop_option_types_RoleId){ .has_value = false }; });
            if (_mv_54.has_value) {
                __auto_type o = _mv_54.value;
                return o;
            } else if (!_mv_54.has_value) {
                return r;
            }
            SLOP_UNREACHABLE();
        }
        case types_RoleId_named_role:
        {
            __auto_type _ = _mv_52.data.named_role;
            return r;
        }
    }
    SLOP_UNREACHABLE();
}

types_Context types_make_context(slop_arena* arena, types_Node root) {
    types_Context _retval = {0};
    _retval = ((types_Context){.root = root, .subsumers = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_Node, slop_hash_types_Node, slop_eq_types_Node, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .succs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, slop_map*); slop_map_new_ptr(arena, 0, &_d); }), .preds = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, slop_map*); slop_map_new_ptr(arena, 0, &_d); })});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST((({ types_Node _eq_l_55 = (_retval.root); types_Node _eq_r_56 = (root); slop_eq_types_Node(&_eq_l_55, &_eq_r_56); })), "(== (. $result root) root)");
    return _retval;
}

types_Queue types_make_queue(slop_arena* arena) {
    types_Queue _retval = {0};
    _retval = ((types_Queue){.items = ((slop_list_types_Derived){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((((int64_t)((_retval.items).len)) == 0)), "(== (list-len (. $result items)) 0)");
    return _retval;
}

uint8_t types_queue_is_active(types_Queue q) {
    uint8_t _retval = {0};
    _retval = (((int64_t)((q.items).len)) > 0);
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval == (((int64_t)((q.items).len)) > 0))), "(== $result (> (list-len (. q items)) 0))");
    return _retval;
}

uint8_t types_derived_eq(types_Derived a, types_Derived b) {
    __auto_type _mv_57 = a;
    switch (_mv_57.tag) {
        case types_Derived_derived_sub:
        {
            __auto_type an = _mv_57.data.derived_sub;
            __auto_type _mv_58 = b;
            switch (_mv_58.tag) {
                case types_Derived_derived_sub:
                {
                    __auto_type bn = _mv_58.data.derived_sub;
                    return types_node_eq(an, bn);
                }
                case types_Derived_derived_succ:
                {
                    return 0;
                }
                case types_Derived_derived_pred:
                {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_Derived_derived_succ:
        {
            __auto_type ar = _mv_57.data.derived_succ.f0;
            __auto_type an = _mv_57.data.derived_succ.f1;
            __auto_type _mv_59 = b;
            switch (_mv_59.tag) {
                case types_Derived_derived_succ:
                {
                    __auto_type br = _mv_59.data.derived_succ.f0;
                    __auto_type bn = _mv_59.data.derived_succ.f1;
                    if (types_role_eq(ar, br)) {
                        return types_node_eq(an, bn);
                    } else {
                        return 0;
                    }
                }
                case types_Derived_derived_sub:
                {
                    __auto_type _ = _mv_59.data.derived_sub;
                    return 0;
                }
                case types_Derived_derived_pred:
                {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_Derived_derived_pred:
        {
            __auto_type ar = _mv_57.data.derived_pred.f0;
            __auto_type an = _mv_57.data.derived_pred.f1;
            __auto_type _mv_60 = b;
            switch (_mv_60.tag) {
                case types_Derived_derived_pred:
                {
                    __auto_type br = _mv_60.data.derived_pred.f0;
                    __auto_type bn = _mv_60.data.derived_pred.f1;
                    if (types_role_eq(ar, br)) {
                        return types_node_eq(an, bn);
                    } else {
                        return 0;
                    }
                }
                case types_Derived_derived_sub:
                {
                    __auto_type _ = _mv_60.data.derived_sub;
                    return 0;
                }
                case types_Derived_derived_succ:
                {
                    return 0;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t types_addressed_eq(types_Addressed a, types_Addressed b) {
    if (types_node_eq(a.to, b.to)) {
        return types_derived_eq(a.what, b.what);
    } else {
        return 0;
    }
}

types_EdgePair types_emit_edge(slop_arena* arena, types_LogicalEdge e) {
    types_EdgePair _retval = {0};
    _retval = ((types_EdgePair){.succ_half = ((types_Addressed){.to = e.from, .what = ((types_Derived){ .tag = types_Derived_derived_succ, .data.derived_succ = { .f0 = e.role, .f1 = e.to } })}), .pred_half = ((types_Addressed){.to = e.to, .what = ((types_Derived){ .tag = types_Derived_derived_pred, .data.derived_pred = { .f0 = e.role, .f1 = e.from } })})});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST((({ types_Node _eq_l_61 = (_retval.succ_half.to); types_Node _eq_r_62 = (e.from); slop_eq_types_Node(&_eq_l_61, &_eq_r_62); })), "(== (. (. $result succ-half) to) (. e from))");
    SLOP_POST((({ types_Node _eq_l_63 = (_retval.pred_half.to); types_Node _eq_r_64 = (e.to); slop_eq_types_Node(&_eq_l_63, &_eq_r_64); })), "(== (. (. $result pred-half) to) (. e to))");
    return _retval;
}

uint8_t types_outcome_is_complete(types_Outcome o) {
    uint8_t _retval = {0};
    _retval = ((((int64_t)((o.coverage.omitted).len)) == 0) && ({ __auto_type _mv = o.termination; uint8_t _mr = {0}; switch (_mv.tag) { case types_Termination_fixpoint: { _mr = 1; break; } case types_Termination_resource_limit: { __auto_type _ = _mv.data.resource_limit; _mr = 0; break; }  } _mr; }));
    goto _slop_post;
    _slop_post: ;
    return _retval;
}

uint8_t types_findings_are_incoherent(types_Findings f) {
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

