#include "../runtime/slop_runtime.h"
#include "slop_classify.h"

uint8_t classify_context_has_bottom(types_Saturation sat, types_Node n);
uint8_t classify_detect_inconsistent(types_Saturation sat, types_Names names);
uint8_t classify_is_individual(types_Names names, types_Node n);
uint8_t classify_entails_sub(types_Saturation sat, types_Names names, uint8_t inconsistent, types_Node a, types_Node b);
uint8_t classify_is_bottom_iri(rdf_IRI iri);
slop_list_rdf_IRI classify_collect_unsatisfiable(slop_arena* arena, types_Saturation sat, types_Names names);
slop_list_types_SubPair classify_collect_taxonomy(slop_arena* arena, types_Saturation sat, types_Names names);
types_Findings classify_extract_findings(slop_arena* arena, types_Saturation sat, types_Names names);

uint8_t classify_context_has_bottom(types_Saturation sat, types_Node n) {
    {
        __auto_type bottom = types_node_bottom();
        __auto_type _mv_548 = ({ void* _ptr = slop_map_get(sat.contexts, &(n)); _ptr ? (slop_option_types_Context){ .has_value = true, .value = *(types_Context*)_ptr } : (slop_option_types_Context){ .has_value = false }; });
        if (_mv_548.has_value) {
            __auto_type ctx = _mv_548.value;
            return slop_map_has(ctx.subsumers, &(bottom));
        } else if (!_mv_548.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t classify_detect_inconsistent(types_Saturation sat, types_Names names) {
    {
        uint8_t found = classify_context_has_bottom(sat, types_node_top());
        {
            slop_map* _coll = (slop_map*)sat.contexts;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    types_Node n = *(types_Node*)slop_map_key_at(_coll, _i);
                    if (classify_is_individual(names, n)) {
                        if (classify_context_has_bottom(sat, n)) {
                            found = 1;
                        }
                    }
                }
            }
        }
        return found;
    }
}

uint8_t classify_is_individual(types_Names names, types_Node n) {
    __auto_type _mv_550 = types_original_node(names, n);
    switch (_mv_550.tag) {
        case types_Node_individual_node:
        {
            __auto_type _ = _mv_550.data.individual_node;
            return 1;
        }
        case types_Node_class_node:
        {
            __auto_type _ = _mv_550.data.class_node;
            return 0;
        }
        case types_Node_fresh_node:
        {
            __auto_type _ = _mv_550.data.fresh_node;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t classify_entails_sub(types_Saturation sat, types_Names names, uint8_t inconsistent, types_Node a, types_Node b) {
    uint8_t _retval = {0};
    {
        __auto_type bottom = types_node_bottom();
        if (inconsistent) {
            _retval = 1;
        } else {
            __auto_type _mv_551 = types_renamed_node(names, a);
            if (!_mv_551.has_value) {
                return 0;
            } else if (_mv_551.has_value) {
                __auto_type ra = _mv_551.value;
                __auto_type _mv_553 = ({ void* _ptr = slop_map_get(sat.contexts, &(ra)); _ptr ? (slop_option_types_Context){ .has_value = true, .value = *(types_Context*)_ptr } : (slop_option_types_Context){ .has_value = false }; });
                if (_mv_553.has_value) {
                    __auto_type ctx = _mv_553.value;
                    if (slop_map_has(ctx.subsumers, &(bottom))) {
                        return 1;
                    } else {
                        __auto_type _mv_555 = types_renamed_node(names, b);
                        if (_mv_555.has_value) {
                            __auto_type rb = _mv_555.value;
                            return slop_map_has(ctx.subsumers, &(rb));
                        } else if (!_mv_555.has_value) {
                            return 0;
                        }
                        SLOP_UNREACHABLE();
                    }
                } else if (!_mv_553.has_value) {
                    return 0;
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
    }
    return _retval;
}

uint8_t classify_is_bottom_iri(rdf_IRI iri) {
    return string_eq(iri.value, vocab_OWL_NOTHING);
}

slop_list_rdf_IRI classify_collect_unsatisfiable(slop_arena* arena, types_Saturation sat, types_Names names) {
    {
        __auto_type unsat = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type bottom = types_node_bottom();
        {
            slop_map* _coll = (slop_map*)sat.contexts;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    types_Node n = *(types_Node*)slop_map_key_at(_coll, _i);
                    types_Context ctx = *(types_Context*)slop_map_value_at(_coll, _i);
                    __auto_type _mv_557 = types_original_node(names, n);
                    switch (_mv_557.tag) {
                        case types_Node_class_node:
                        {
                            __auto_type iri = _mv_557.data.class_node;
                            if (!(classify_is_bottom_iri(iri))) {
                                if (slop_map_has(ctx.subsumers, &(bottom))) {
                                    ({ __auto_type _lst_p = &(unsat); __auto_type _item = (iri); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                            break;
                        }
                        case types_Node_individual_node:
                        {
                            __auto_type _ = _mv_557.data.individual_node;
                            break;
                        }
                        case types_Node_fresh_node:
                        {
                            __auto_type _ = _mv_557.data.fresh_node;
                            break;
                        }
                    }
                }
            }
        }
        return canon_sort_iris(arena, unsat);
    }
}

slop_list_types_SubPair classify_collect_taxonomy(slop_arena* arena, types_Saturation sat, types_Names names) {
    {
        __auto_type subs = ((slop_list_types_SubPair){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type bottom = types_node_bottom();
        {
            slop_map* _coll = (slop_map*)sat.contexts;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    types_Node rn = *(types_Node*)slop_map_key_at(_coll, _i);
                    types_Context ctx = *(types_Context*)slop_map_value_at(_coll, _i);
                    __auto_type _mv_559 = types_original_node(names, rn);
                    switch (_mv_559.tag) {
                        case types_Node_class_node:
                        {
                            __auto_type iri = _mv_559.data.class_node;
                            if (!(classify_is_bottom_iri(iri))) {
                                if (slop_map_has(ctx.subsumers, &(bottom))) {
                                    {
                                        __auto_type n = types_original_node(names, rn);
                                        ({ __auto_type _lst_p = &(subs); __auto_type _item = (((types_SubPair){.sub = n, .super = bottom})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                } else {
                                    {
                                        slop_map* _coll = (slop_map*)ctx.subsumers;
                                        for (size_t _i = 0; _i < _coll->len; _i++) {
                                            {
                                                types_Node rb = *(types_Node*)slop_map_key_at(_coll, _i);
                                                __auto_type _mv_561 = types_original_node(names, rb);
                                                switch (_mv_561.tag) {
                                                    case types_Node_class_node:
                                                    {
                                                        __auto_type _ = _mv_561.data.class_node;
                                                        {
                                                            __auto_type n = types_original_node(names, rn);
                                                            __auto_type b = types_original_node(names, rb);
                                                            ({ __auto_type _lst_p = &(subs); __auto_type _item = (((types_SubPair){.sub = n, .super = b})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        }
                                                        break;
                                                    }
                                                    case types_Node_individual_node:
                                                    {
                                                        __auto_type _ = _mv_561.data.individual_node;
                                                        break;
                                                    }
                                                    case types_Node_fresh_node:
                                                    {
                                                        __auto_type _ = _mv_561.data.fresh_node;
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
                        case types_Node_individual_node:
                        {
                            __auto_type _ = _mv_559.data.individual_node;
                            break;
                        }
                        case types_Node_fresh_node:
                        {
                            __auto_type _ = _mv_559.data.fresh_node;
                            break;
                        }
                    }
                }
            }
        }
        return canon_sort_sub_pairs(arena, subs);
    }
}

types_Findings classify_extract_findings(slop_arena* arena, types_Saturation sat, types_Names names) {
    {
        __auto_type inconsistent = classify_detect_inconsistent(sat, names);
        return ((types_Findings){.inconsistent = inconsistent, .unsatisfiable = ((inconsistent) ? ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 }) : classify_collect_unsatisfiable(arena, sat, names)), .subsumptions = ((inconsistent) ? ((slop_list_types_SubPair){ .data = NULL, .len = 0, .cap = 0 }) : classify_collect_taxonomy(arena, sat, names)), .imports_seen = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 })});
    }
}

