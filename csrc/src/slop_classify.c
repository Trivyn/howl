#include "../runtime/slop_runtime.h"
#include "slop_classify.h"

uint8_t classify_context_has_bottom(types_Saturation sat, types_Node n);
uint8_t classify_detect_inconsistent(types_Saturation sat);
uint8_t classify_entails_sub(types_Saturation sat, uint8_t inconsistent, types_Node a, types_Node b);
uint8_t classify_is_bottom_iri(rdf_IRI iri);
slop_list_rdf_IRI classify_collect_unsatisfiable(slop_arena* arena, types_Saturation sat);
slop_list_types_SubPair classify_collect_taxonomy(slop_arena* arena, types_Saturation sat);
types_Findings classify_extract_findings(slop_arena* arena, types_Saturation sat);

uint8_t classify_context_has_bottom(types_Saturation sat, types_Node n) {
    {
        __auto_type bottom = types_node_bottom();
        __auto_type _mv_399 = ({ void* _ptr = slop_map_get(sat.contexts, &(n)); _ptr ? (slop_option_types_Context){ .has_value = true, .value = *(types_Context*)_ptr } : (slop_option_types_Context){ .has_value = false }; });
        if (_mv_399.has_value) {
            __auto_type ctx = _mv_399.value;
            return (slop_map_get(ctx.subsumers, &(bottom)) != NULL);
        } else if (!_mv_399.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t classify_detect_inconsistent(types_Saturation sat) {
    {
        uint8_t found = classify_context_has_bottom(sat, types_node_top());
        {
            slop_map* _coll = (slop_map*)sat.contexts;
            for (size_t _i = 0; _i < _coll->cap; _i++) {
                if (_coll->entries[_i].occupied) {
                    types_Node n = *(types_Node*)_coll->entries[_i].key;
                    __auto_type _mv_401 = n;
                    switch (_mv_401.tag) {
                        case types_Node_individual_node:
                        {
                            __auto_type _ = _mv_401.data.individual_node;
                            if (classify_context_has_bottom(sat, n)) {
                                found = 1;
                            }
                            break;
                        }
                        case types_Node_class_node:
                        {
                            __auto_type _ = _mv_401.data.class_node;
                            break;
                        }
                        case types_Node_fresh_node:
                        {
                            __auto_type _ = _mv_401.data.fresh_node;
                            break;
                        }
                    }
                }
            }
        }
        return found;
    }
}

uint8_t classify_entails_sub(types_Saturation sat, uint8_t inconsistent, types_Node a, types_Node b) {
    uint8_t _retval = {0};
    {
        __auto_type bottom = types_node_bottom();
        if (inconsistent) {
            _retval = 1;
        } else {
            __auto_type _mv_403 = ({ void* _ptr = slop_map_get(sat.contexts, &(a)); _ptr ? (slop_option_types_Context){ .has_value = true, .value = *(types_Context*)_ptr } : (slop_option_types_Context){ .has_value = false }; });
            if (_mv_403.has_value) {
                __auto_type ctx = _mv_403.value;
                if (slop_map_get(ctx.subsumers, &(bottom)) != NULL) {
                    return 1;
                } else {
                    return (slop_map_get(ctx.subsumers, &(b)) != NULL);
                }
            } else if (!_mv_403.has_value) {
                return 0;
            }
            SLOP_UNREACHABLE();
        }
    }
    return _retval;
}

uint8_t classify_is_bottom_iri(rdf_IRI iri) {
    return string_eq(iri.value, vocab_OWL_NOTHING);
}

slop_list_rdf_IRI classify_collect_unsatisfiable(slop_arena* arena, types_Saturation sat) {
    {
        __auto_type unsat = ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 });
        __auto_type bottom = types_node_bottom();
        {
            slop_map* _coll = (slop_map*)sat.contexts;
            for (size_t _i = 0; _i < _coll->cap; _i++) {
                if (_coll->entries[_i].occupied) {
                    types_Node n = *(types_Node*)_coll->entries[_i].key;
                    types_Context ctx = *(types_Context*)_coll->entries[_i].value;
                    __auto_type _mv_406 = n;
                    switch (_mv_406.tag) {
                        case types_Node_class_node:
                        {
                            __auto_type iri = _mv_406.data.class_node;
                            if (!(classify_is_bottom_iri(iri))) {
                                if (slop_map_get(ctx.subsumers, &(bottom)) != NULL) {
                                    ({ __auto_type _lst_p = &(unsat); __auto_type _item = (iri); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                            break;
                        }
                        case types_Node_individual_node:
                        {
                            __auto_type _ = _mv_406.data.individual_node;
                            break;
                        }
                        case types_Node_fresh_node:
                        {
                            __auto_type _ = _mv_406.data.fresh_node;
                            break;
                        }
                    }
                }
            }
        }
        return canon_sort_iris(arena, unsat);
    }
}

slop_list_types_SubPair classify_collect_taxonomy(slop_arena* arena, types_Saturation sat) {
    {
        __auto_type subs = ((slop_list_types_SubPair){ .data = (types_SubPair*)slop_arena_alloc(arena, 16 * sizeof(types_SubPair)), .len = 0, .cap = 16 });
        __auto_type bottom = types_node_bottom();
        {
            slop_map* _coll = (slop_map*)sat.contexts;
            for (size_t _i = 0; _i < _coll->cap; _i++) {
                if (_coll->entries[_i].occupied) {
                    types_Node n = *(types_Node*)_coll->entries[_i].key;
                    types_Context ctx = *(types_Context*)_coll->entries[_i].value;
                    __auto_type _mv_408 = n;
                    switch (_mv_408.tag) {
                        case types_Node_class_node:
                        {
                            __auto_type iri = _mv_408.data.class_node;
                            if (!(classify_is_bottom_iri(iri))) {
                                if (slop_map_get(ctx.subsumers, &(bottom)) != NULL) {
                                    ({ __auto_type _lst_p = &(subs); __auto_type _item = (((types_SubPair){.sub = n, .super = bottom})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                } else {
                                    {
                                        slop_map* _coll = (slop_map*)ctx.subsumers;
                                        for (size_t _i = 0; _i < _coll->cap; _i++) {
                                            if (_coll->entries[_i].occupied) {
                                                types_Node b = *(types_Node*)_coll->entries[_i].key;
                                                __auto_type _mv_410 = b;
                                                switch (_mv_410.tag) {
                                                    case types_Node_class_node:
                                                    {
                                                        __auto_type _ = _mv_410.data.class_node;
                                                        ({ __auto_type _lst_p = &(subs); __auto_type _item = (((types_SubPair){.sub = n, .super = b})); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        break;
                                                    }
                                                    case types_Node_individual_node:
                                                    {
                                                        __auto_type _ = _mv_410.data.individual_node;
                                                        break;
                                                    }
                                                    case types_Node_fresh_node:
                                                    {
                                                        __auto_type _ = _mv_410.data.fresh_node;
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
                            __auto_type _ = _mv_408.data.individual_node;
                            break;
                        }
                        case types_Node_fresh_node:
                        {
                            __auto_type _ = _mv_408.data.fresh_node;
                            break;
                        }
                    }
                }
            }
        }
        return canon_sort_sub_pairs(arena, subs);
    }
}

types_Findings classify_extract_findings(slop_arena* arena, types_Saturation sat) {
    {
        __auto_type inconsistent = classify_detect_inconsistent(sat);
        return ((types_Findings){.inconsistent = inconsistent, .unsatisfiable = ((inconsistent) ? ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 }) : classify_collect_unsatisfiable(arena, sat)), .subsumptions = ((inconsistent) ? ((slop_list_types_SubPair){ .data = (types_SubPair*)slop_arena_alloc(arena, 16 * sizeof(types_SubPair)), .len = 0, .cap = 16 }) : classify_collect_taxonomy(arena, sat)), .imports_seen = ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 })});
    }
}

