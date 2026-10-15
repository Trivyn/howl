#include "../runtime/slop_runtime.h"
#include "slop_classify.h"

uint8_t howl_classify_context_has_bottom(howl_types_Saturation sat, howl_types_Node n);
uint8_t howl_classify_detect_inconsistent(howl_types_Saturation sat, howl_types_Names names);
uint8_t howl_classify_is_individual(howl_types_Names names, howl_types_Node n);
uint8_t howl_classify_entails_sub(howl_types_Saturation sat, howl_types_Names names, uint8_t inconsistent, howl_types_Node a, howl_types_Node b);
uint8_t howl_classify_is_bottom_iri(slop_rdf_rdf_IRI iri);
slop_list_slop_rdf_rdf_IRI howl_classify_collect_unsatisfiable(slop_arena* arena, howl_types_Saturation sat, howl_types_Names names);
slop_list_howl_types_SubPair howl_classify_collect_taxonomy(slop_arena* arena, howl_types_Saturation sat, howl_types_Names names);
howl_types_Findings howl_classify_extract_findings(slop_arena* arena, howl_types_Saturation sat, howl_types_Names names);
slop_list_slop_rdf_rdf_IRI howl_classify_ksc_unsatisfiable(slop_arena* arena, howl_types_KscResult r);
slop_list_howl_types_SubPair howl_classify_ksc_taxonomy(slop_arena* arena, howl_types_KscResult r);
howl_types_Findings howl_classify_extract_ksc_findings(slop_arena* arena, howl_types_KscResult r);
uint8_t howl_classify_ksc_answer_holds(howl_types_ClassAnswer a, howl_types_KName b);
uint8_t howl_classify_ksc_entails_sub(howl_types_KscResult r, howl_types_KName a, howl_types_KName b);

uint8_t howl_classify_context_has_bottom(howl_types_Saturation sat, howl_types_Node n) {
    {
        __auto_type bottom = howl_types_node_bottom();
        __auto_type _mv_1098 = ({ void* _ptr = slop_map_get(sat.contexts, &(n)); _ptr ? (slop_option_howl_types_Context){ .has_value = true, .value = *(howl_types_Context*)_ptr } : (slop_option_howl_types_Context){ .has_value = false }; });
        if (_mv_1098.has_value) {
            __auto_type ctx = _mv_1098.value;
            return slop_map_has(ctx.subsumers, &(bottom));
        } else if (!_mv_1098.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t howl_classify_detect_inconsistent(howl_types_Saturation sat, howl_types_Names names) {
    {
        uint8_t found = howl_classify_context_has_bottom(sat, howl_types_node_top());
        {
            slop_map* _coll = (slop_map*)sat.contexts;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    howl_types_Node n = *(howl_types_Node*)slop_map_key_at(_coll, _i);
                    if (howl_classify_is_individual(names, n)) {
                        if (howl_classify_context_has_bottom(sat, n)) {
                            found = 1;
                        }
                    }
                }
            }
        }
        return found;
    }
}

uint8_t howl_classify_is_individual(howl_types_Names names, howl_types_Node n) {
    __auto_type _mv_1100 = howl_types_original_node(names, n);
    switch (_mv_1100.tag) {
        case howl_types_Node_individual_node:
        {
            __auto_type _ = _mv_1100.data.individual_node;
            return 1;
        }
        case howl_types_Node_class_node:
        {
            __auto_type _ = _mv_1100.data.class_node;
            return 0;
        }
        case howl_types_Node_fresh_node:
        {
            __auto_type _ = _mv_1100.data.fresh_node;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_classify_entails_sub(howl_types_Saturation sat, howl_types_Names names, uint8_t inconsistent, howl_types_Node a, howl_types_Node b) {
    uint8_t _retval = {0};
    {
        __auto_type bottom = howl_types_node_bottom();
        if (inconsistent) {
            _retval = 1;
            goto _slop_post;
        } else {
            __auto_type _mv_1101 = howl_types_renamed_node(names, a);
            if (!_mv_1101.has_value) {
                _retval = 0;
                goto _slop_post;
            } else if (_mv_1101.has_value) {
                __auto_type ra = _mv_1101.value;
                __auto_type _mv_1103 = ({ void* _ptr = slop_map_get(sat.contexts, &(ra)); _ptr ? (slop_option_howl_types_Context){ .has_value = true, .value = *(howl_types_Context*)_ptr } : (slop_option_howl_types_Context){ .has_value = false }; });
                if (_mv_1103.has_value) {
                    __auto_type ctx = _mv_1103.value;
                    if (slop_map_has(ctx.subsumers, &(bottom))) {
                        _retval = 1;
                        goto _slop_post;
                    } else {
                        __auto_type _mv_1105 = howl_types_renamed_node(names, b);
                        if (_mv_1105.has_value) {
                            __auto_type rb = _mv_1105.value;
                            _retval = slop_map_has(ctx.subsumers, &(rb));
                            goto _slop_post;
                        } else if (!_mv_1105.has_value) {
                            _retval = 0;
                            goto _slop_post;
                        }
                        SLOP_UNREACHABLE();
                    }
                } else if (!_mv_1103.has_value) {
                    _retval = 0;
                    goto _slop_post;
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
    }
    _slop_post: ;
    return _retval;
}

uint8_t howl_classify_is_bottom_iri(slop_rdf_rdf_IRI iri) {
    return string_eq(iri.value, slop_rdf_vocab_OWL_NOTHING);
}

slop_list_slop_rdf_rdf_IRI howl_classify_collect_unsatisfiable(slop_arena* arena, howl_types_Saturation sat, howl_types_Names names) {
    {
        __auto_type unsat = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type bottom = howl_types_node_bottom();
        {
            slop_map* _coll = (slop_map*)sat.contexts;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    howl_types_Node n = *(howl_types_Node*)slop_map_key_at(_coll, _i);
                    howl_types_Context ctx = *(howl_types_Context*)slop_map_value_at(_coll, _i);
                    __auto_type _mv_1107 = howl_types_original_node(names, n);
                    switch (_mv_1107.tag) {
                        case howl_types_Node_class_node:
                        {
                            __auto_type iri = _mv_1107.data.class_node;
                            if (!(howl_classify_is_bottom_iri(iri))) {
                                if (slop_map_has(ctx.subsumers, &(bottom))) {
                                    ({ __auto_type _lst_p = &(unsat); __auto_type _item = (iri); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                            break;
                        }
                        case howl_types_Node_individual_node:
                        {
                            __auto_type _ = _mv_1107.data.individual_node;
                            break;
                        }
                        case howl_types_Node_fresh_node:
                        {
                            __auto_type _ = _mv_1107.data.fresh_node;
                            break;
                        }
                    }
                }
            }
        }
        return howl_canon_sort_iris(arena, unsat);
    }
}

slop_list_howl_types_SubPair howl_classify_collect_taxonomy(slop_arena* arena, howl_types_Saturation sat, howl_types_Names names) {
    {
        __auto_type subs = ((slop_list_howl_types_SubPair){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type bottom = howl_types_node_bottom();
        {
            slop_map* _coll = (slop_map*)sat.contexts;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    howl_types_Node rn = *(howl_types_Node*)slop_map_key_at(_coll, _i);
                    howl_types_Context ctx = *(howl_types_Context*)slop_map_value_at(_coll, _i);
                    __auto_type _mv_1109 = howl_types_original_node(names, rn);
                    switch (_mv_1109.tag) {
                        case howl_types_Node_class_node:
                        {
                            __auto_type iri = _mv_1109.data.class_node;
                            if (!(howl_classify_is_bottom_iri(iri))) {
                                if (slop_map_has(ctx.subsumers, &(bottom))) {
                                    {
                                        __auto_type n = howl_types_original_node(names, rn);
                                        ({ __auto_type _lst_p = &(subs); __auto_type _item = (((howl_types_SubPair){.sub = n, .super = bottom})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                } else {
                                    {
                                        slop_map* _coll = (slop_map*)ctx.subsumers;
                                        for (size_t _i = 0; _i < _coll->len; _i++) {
                                            {
                                                howl_types_Node rb = *(howl_types_Node*)slop_map_key_at(_coll, _i);
                                                __auto_type _mv_1111 = howl_types_original_node(names, rb);
                                                switch (_mv_1111.tag) {
                                                    case howl_types_Node_class_node:
                                                    {
                                                        __auto_type _ = _mv_1111.data.class_node;
                                                        {
                                                            __auto_type n = howl_types_original_node(names, rn);
                                                            __auto_type b = howl_types_original_node(names, rb);
                                                            ({ __auto_type _lst_p = &(subs); __auto_type _item = (((howl_types_SubPair){.sub = n, .super = b})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        }
                                                        break;
                                                    }
                                                    case howl_types_Node_individual_node:
                                                    {
                                                        __auto_type _ = _mv_1111.data.individual_node;
                                                        break;
                                                    }
                                                    case howl_types_Node_fresh_node:
                                                    {
                                                        __auto_type _ = _mv_1111.data.fresh_node;
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
                        case howl_types_Node_individual_node:
                        {
                            __auto_type _ = _mv_1109.data.individual_node;
                            break;
                        }
                        case howl_types_Node_fresh_node:
                        {
                            __auto_type _ = _mv_1109.data.fresh_node;
                            break;
                        }
                    }
                }
            }
        }
        return howl_canon_sort_sub_pairs(arena, subs);
    }
}

howl_types_Findings howl_classify_extract_findings(slop_arena* arena, howl_types_Saturation sat, howl_types_Names names) {
    {
        __auto_type inconsistent = howl_classify_detect_inconsistent(sat, names);
        return ((howl_types_Findings){.inconsistent = inconsistent, .unsatisfiable = ((inconsistent) ? ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) : howl_classify_collect_unsatisfiable(arena, sat, names)), .subsumptions = ((inconsistent) ? ((slop_list_howl_types_SubPair){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) : howl_classify_collect_taxonomy(arena, sat, names)), .imports_seen = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
    }
}

slop_list_slop_rdf_rdf_IRI howl_classify_ksc_unsatisfiable(slop_arena* arena, howl_types_KscResult r) {
    {
        __auto_type unsat = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = r.answers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_1112 = a.cls;
                switch (_mv_1112.tag) {
                    case howl_types_KName_k_class:
                    {
                        __auto_type iri = _mv_1112.data.k_class;
                        if (!(howl_classify_is_bottom_iri(iri))) {
                            if (a.unsat) {
                                ({ __auto_type _lst_p = &(unsat); __auto_type _item = (iri); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        break;
                    }
                    case howl_types_KName_k_fresh:
                    {
                        __auto_type _ = _mv_1112.data.k_fresh;
                        break;
                    }
                }
            }
        }
        return howl_canon_sort_iris(arena, unsat);
    }
}

slop_list_howl_types_SubPair howl_classify_ksc_taxonomy(slop_arena* arena, howl_types_KscResult r) {
    {
        __auto_type subs = ((slop_list_howl_types_SubPair){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type bottom = howl_types_node_bottom();
        {
            __auto_type _coll = r.answers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                __auto_type _mv_1113 = a.cls;
                switch (_mv_1113.tag) {
                    case howl_types_KName_k_class:
                    {
                        __auto_type iri = _mv_1113.data.k_class;
                        if (!(howl_classify_is_bottom_iri(iri))) {
                            {
                                __auto_type n = ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = iri });
                                if (a.unsat) {
                                    ({ __auto_type _lst_p = &(subs); __auto_type _item = (((howl_types_SubPair){.sub = n, .super = bottom})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                } else {
                                    {
                                        __auto_type _coll = a.subsumers;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type b = _coll.data[_i];
                                            __auto_type _mv_1114 = b;
                                            switch (_mv_1114.tag) {
                                                case howl_types_KName_k_class:
                                                {
                                                    __auto_type biri = _mv_1114.data.k_class;
                                                    ({ __auto_type _lst_p = &(subs); __auto_type _item = (((howl_types_SubPair){.sub = n, .super = ((howl_types_Node){ .tag = howl_types_Node_class_node, .data.class_node = biri })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    break;
                                                }
                                                case howl_types_KName_k_fresh:
                                                {
                                                    __auto_type _ = _mv_1114.data.k_fresh;
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
                    case howl_types_KName_k_fresh:
                    {
                        __auto_type _ = _mv_1113.data.k_fresh;
                        break;
                    }
                }
            }
        }
        return howl_canon_sort_sub_pairs(arena, subs);
    }
}

howl_types_Findings howl_classify_extract_ksc_findings(slop_arena* arena, howl_types_KscResult r) {
    howl_types_Findings _retval = {0};
    {
        __auto_type inconsistent = r.inconsistent;
        _retval = ((howl_types_Findings){.inconsistent = inconsistent, .unsatisfiable = ((inconsistent) ? ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) : howl_classify_ksc_unsatisfiable(arena, r)), .subsumptions = ((inconsistent) ? ((slop_list_howl_types_SubPair){ .data = NULL, .len = 0, .cap = 0, .arena = arena }) : howl_classify_ksc_taxonomy(arena, r)), .imports_seen = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((_retval.inconsistent == r.inconsistent)), "(== (. $result inconsistent) (. r inconsistent))");
    return _retval;
}

uint8_t howl_classify_ksc_answer_holds(howl_types_ClassAnswer a, howl_types_KName b) {
    if (a.unsat) {
        return 1;
    } else {
        {
            uint8_t found = 0;
            {
                __auto_type _coll = a.subsumers;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type n = _coll.data[_i];
                    if (howl_types_kname_eq(n, b)) {
                        found = 1;
                    }
                }
            }
            return found;
        }
    }
}

uint8_t howl_classify_ksc_entails_sub(howl_types_KscResult r, howl_types_KName a, howl_types_KName b) {
    uint8_t _retval = {0};
    if (r.inconsistent) {
        _retval = 1;
        goto _slop_post;
    } else {
        {
            uint8_t found = 0;
            {
                __auto_type _coll = r.answers;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type x = _coll.data[_i];
                    if (howl_types_kname_eq(x.cls, a)) {
                        if (howl_classify_ksc_answer_holds(x, b)) {
                            found = 1;
                        }
                    }
                }
            }
            _retval = found;
            goto _slop_post;
        }
    }
    _slop_post: ;
    return _retval;
}

