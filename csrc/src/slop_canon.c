#include "../runtime/slop_runtime.h"
#include "slop_canon.h"

int64_t canon_string_cmp(slop_string a, slop_string b);
int64_t canon_iri_cmp(rdf_IRI a, rdf_IRI b);
int64_t canon_node_tag_rank(types_Node n);
int64_t canon_node_cmp(types_Node a, types_Node b);
int64_t canon_role_cmp(types_RoleId a, types_RoleId b);
int64_t canon_sub_pair_cmp(types_SubPair a, types_SubPair b);
int64_t canon_entity_kind_rank(types_EntityKind k);
int64_t canon_axiom_ref_cmp(types_AxiomRef a, types_AxiomRef b);
int64_t canon_input_ref_cmp(types_InputRef a, types_InputRef b);
int64_t canon_missing_declaration_cmp(types_MissingDeclaration a, types_MissingDeclaration b);
int64_t canon_omission_cmp(types_Omission a, types_Omission b);
int64_t canon_int_at(slop_list_int xs, int64_t i);
slop_string canon_str_at(slop_list_string xs, int64_t i);
rdf_IRI canon_iri_at(slop_list_rdf_IRI xs, int64_t i);
types_Node canon_node_at(slop_list_types_Node xs, int64_t i);
types_SubPair canon_sub_pair_at(slop_list_types_SubPair xs, int64_t i);
types_AxiomRef canon_axiom_ref_at(slop_list_types_AxiomRef xs, int64_t i);
types_Omission canon_omission_at(slop_list_types_Omission xs, int64_t i);
uint8_t canon_merge_run(slop_list_int src, slop_list_int dst, int64_t lo, int64_t mid, int64_t hi, slop_closure_t cmp);
slop_list_int canon_sort_range(slop_arena* arena, int64_t n, slop_closure_t cmp);
slop_list_string canon_sort_strings(slop_arena* arena, slop_list_string xs);
slop_list_rdf_IRI canon_sort_iris(slop_arena* arena, slop_list_rdf_IRI xs);
slop_list_types_Node canon_sort_nodes(slop_arena* arena, slop_list_types_Node xs);
slop_list_types_SubPair canon_sort_sub_pairs(slop_arena* arena, slop_list_types_SubPair xs);
slop_list_types_AxiomRef canon_sort_axiom_refs(slop_arena* arena, slop_list_types_AxiomRef xs);
slop_list_types_Omission canon_sort_omissions(slop_arena* arena, slop_list_types_Omission xs);

typedef struct { slop_list_string xs; } canon__lambda_56_env_t;

static int64_t canon__lambda_56(canon__lambda_56_env_t* _env, int64_t i, int64_t j) { return canon_string_cmp(canon_str_at(_env->xs, i), canon_str_at(_env->xs, j)); }

typedef struct { slop_list_rdf_IRI xs; } canon__lambda_57_env_t;

static int64_t canon__lambda_57(canon__lambda_57_env_t* _env, int64_t i, int64_t j) { return canon_iri_cmp(canon_iri_at(_env->xs, i), canon_iri_at(_env->xs, j)); }

typedef struct { slop_list_types_Node xs; } canon__lambda_58_env_t;

static int64_t canon__lambda_58(canon__lambda_58_env_t* _env, int64_t i, int64_t j) { return canon_node_cmp(canon_node_at(_env->xs, i), canon_node_at(_env->xs, j)); }

typedef struct { slop_list_types_SubPair xs; } canon__lambda_59_env_t;

static int64_t canon__lambda_59(canon__lambda_59_env_t* _env, int64_t i, int64_t j) { return canon_sub_pair_cmp(canon_sub_pair_at(_env->xs, i), canon_sub_pair_at(_env->xs, j)); }

typedef struct { slop_list_types_AxiomRef xs; } canon__lambda_60_env_t;

static int64_t canon__lambda_60(canon__lambda_60_env_t* _env, int64_t i, int64_t j) { return canon_axiom_ref_cmp(canon_axiom_ref_at(_env->xs, i), canon_axiom_ref_at(_env->xs, j)); }

typedef struct { slop_list_types_Omission xs; } canon__lambda_61_env_t;

static int64_t canon__lambda_61(canon__lambda_61_env_t* _env, int64_t i, int64_t j) { return canon_omission_cmp(canon_omission_at(_env->xs, i), canon_omission_at(_env->xs, j)); }

int64_t canon_string_cmp(slop_string a, slop_string b) {
    int64_t _retval = {0};
    {
        __auto_type alen = ((int64_t)(a.len));
        __auto_type blen = ((int64_t)(b.len));
        __auto_type n = ((alen) < (blen) ? (alen) : (blen));
        __auto_type r = memcmp(((uint8_t*)(a.data)), ((uint8_t*)(b.data)), ((uint64_t)(n)));
        if (r < 0) {
            _retval = -1;
        } else if (r > 0) {
            _retval = 1;
        } else if (alen < blen) {
            _retval = -1;
        } else if (alen > blen) {
            _retval = 1;
        } else {
            _retval = 0;
        }
    }
    SLOP_POST((((_retval == -1) || ((_retval == 0) || (_retval == 1)))), "(or (== $result -1) (or (== $result 0) (== $result 1)))");
    return _retval;
}

int64_t canon_iri_cmp(rdf_IRI a, rdf_IRI b) {
    return canon_string_cmp(a.value, b.value);
}

int64_t canon_node_tag_rank(types_Node n) {
    __auto_type _mv_29 = n;
    switch (_mv_29.tag) {
        case types_Node_class_node:
        {
            __auto_type _ = _mv_29.data.class_node;
            return 0;
        }
        case types_Node_individual_node:
        {
            __auto_type _ = _mv_29.data.individual_node;
            return 1;
        }
        case types_Node_fresh_node:
        {
            __auto_type _ = _mv_29.data.fresh_node;
            return 2;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t canon_node_cmp(types_Node a, types_Node b) {
    {
        __auto_type ra = canon_node_tag_rank(a);
        __auto_type rb = canon_node_tag_rank(b);
        if (ra < rb) {
            return -1;
        } else if (ra > rb) {
            return 1;
        } else {
            __auto_type _mv_30 = a;
            switch (_mv_30.tag) {
                case types_Node_class_node:
                {
                    __auto_type ia = _mv_30.data.class_node;
                    __auto_type _mv_31 = b;
                    switch (_mv_31.tag) {
                        case types_Node_class_node:
                        {
                            __auto_type ib = _mv_31.data.class_node;
                            return canon_iri_cmp(ia, ib);
                        }
                        case types_Node_individual_node:
                        {
                            __auto_type _ = _mv_31.data.individual_node;
                            return 0;
                        }
                        case types_Node_fresh_node:
                        {
                            __auto_type _ = _mv_31.data.fresh_node;
                            return 0;
                        }
                    }
                    SLOP_UNREACHABLE();
                }
                case types_Node_individual_node:
                {
                    __auto_type ia = _mv_30.data.individual_node;
                    __auto_type _mv_32 = b;
                    switch (_mv_32.tag) {
                        case types_Node_individual_node:
                        {
                            __auto_type ib = _mv_32.data.individual_node;
                            return canon_iri_cmp(ia, ib);
                        }
                        case types_Node_class_node:
                        {
                            __auto_type _ = _mv_32.data.class_node;
                            return 0;
                        }
                        case types_Node_fresh_node:
                        {
                            __auto_type _ = _mv_32.data.fresh_node;
                            return 0;
                        }
                    }
                    SLOP_UNREACHABLE();
                }
                case types_Node_fresh_node:
                {
                    __auto_type fa = _mv_30.data.fresh_node;
                    __auto_type _mv_33 = b;
                    switch (_mv_33.tag) {
                        case types_Node_fresh_node:
                        {
                            __auto_type fb = _mv_33.data.fresh_node;
                            if (fa < fb) {
                                return -1;
                            } else if (fa > fb) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                        case types_Node_class_node:
                        {
                            __auto_type _ = _mv_33.data.class_node;
                            return 0;
                        }
                        case types_Node_individual_node:
                        {
                            __auto_type _ = _mv_33.data.individual_node;
                            return 0;
                        }
                    }
                    SLOP_UNREACHABLE();
                }
            }
            SLOP_UNREACHABLE();
        }
    }
}

int64_t canon_role_cmp(types_RoleId a, types_RoleId b) {
    __auto_type _mv_34 = a;
    switch (_mv_34.tag) {
        case types_RoleId_named_role:
        {
            __auto_type ia = _mv_34.data.named_role;
            __auto_type _mv_35 = b;
            switch (_mv_35.tag) {
                case types_RoleId_named_role:
                {
                    __auto_type ib = _mv_35.data.named_role;
                    return canon_iri_cmp(ia, ib);
                }
                case types_RoleId_fresh_role:
                {
                    __auto_type _ = _mv_35.data.fresh_role;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_RoleId_fresh_role:
        {
            __auto_type fa = _mv_34.data.fresh_role;
            __auto_type _mv_36 = b;
            switch (_mv_36.tag) {
                case types_RoleId_named_role:
                {
                    __auto_type _ = _mv_36.data.named_role;
                    return 1;
                }
                case types_RoleId_fresh_role:
                {
                    __auto_type fb = _mv_36.data.fresh_role;
                    if (fa < fb) {
                        return -1;
                    } else if (fa > fb) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

int64_t canon_sub_pair_cmp(types_SubPair a, types_SubPair b) {
    {
        __auto_type c = canon_node_cmp(a.sub, b.sub);
        if (c != 0) {
            return c;
        } else {
            return canon_node_cmp(a.super, b.super);
        }
    }
}

int64_t canon_entity_kind_rank(types_EntityKind k) {
    __auto_type _mv_37 = k;
    if (_mv_37 == types_EntityKind_entity_class) {
        return 0;
    } else if (_mv_37 == types_EntityKind_entity_object_property) {
        return 1;
    } else if (_mv_37 == types_EntityKind_entity_data_property) {
        return 2;
    } else if (_mv_37 == types_EntityKind_entity_annotation_property) {
        return 3;
    } else if (_mv_37 == types_EntityKind_entity_individual) {
        return 4;
    } else if (_mv_37 == types_EntityKind_entity_datatype) {
        return 5;
    }
    SLOP_UNREACHABLE();
}

int64_t canon_axiom_ref_cmp(types_AxiomRef a, types_AxiomRef b) {
    {
        __auto_type c = canon_string_cmp(a.text, b.text);
        if (c != 0) {
            return c;
        } else {
            __auto_type _mv_38 = a.source;
            if (!_mv_38.has_value) {
                __auto_type _mv_39 = b.source;
                if (!_mv_39.has_value) {
                    return 0;
                } else if (_mv_39.has_value) {
                    __auto_type _ = _mv_39.value;
                    return -1;
                }
                SLOP_UNREACHABLE();
            } else if (_mv_38.has_value) {
                __auto_type ia = _mv_38.value;
                __auto_type _mv_40 = b.source;
                if (!_mv_40.has_value) {
                    return 1;
                } else if (_mv_40.has_value) {
                    __auto_type ib = _mv_40.value;
                    return canon_iri_cmp(ia, ib);
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
    }
}

int64_t canon_input_ref_cmp(types_InputRef a, types_InputRef b) {
    __auto_type _mv_41 = a;
    switch (_mv_41.tag) {
        case types_InputRef_owl_axiom:
        {
            __auto_type ra = _mv_41.data.owl_axiom;
            __auto_type _mv_42 = b;
            switch (_mv_42.tag) {
                case types_InputRef_owl_axiom:
                {
                    __auto_type rb = _mv_42.data.owl_axiom;
                    return canon_axiom_ref_cmp(ra, rb);
                }
                case types_InputRef_rdf_fragment:
                {
                    __auto_type _ = _mv_42.data.rdf_fragment;
                    return -1;
                }
                case types_InputRef_synthetic:
                {
                    __auto_type _ = _mv_42.data.synthetic;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_InputRef_rdf_fragment:
        {
            __auto_type sa = _mv_41.data.rdf_fragment;
            __auto_type _mv_43 = b;
            switch (_mv_43.tag) {
                case types_InputRef_owl_axiom:
                {
                    __auto_type _ = _mv_43.data.owl_axiom;
                    return 1;
                }
                case types_InputRef_rdf_fragment:
                {
                    __auto_type sb = _mv_43.data.rdf_fragment;
                    return canon_string_cmp(sa, sb);
                }
                case types_InputRef_synthetic:
                {
                    __auto_type _ = _mv_43.data.synthetic;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_InputRef_synthetic:
        {
            __auto_type sa = _mv_41.data.synthetic;
            __auto_type _mv_44 = b;
            switch (_mv_44.tag) {
                case types_InputRef_owl_axiom:
                {
                    __auto_type _ = _mv_44.data.owl_axiom;
                    return 1;
                }
                case types_InputRef_rdf_fragment:
                {
                    __auto_type _ = _mv_44.data.rdf_fragment;
                    return 1;
                }
                case types_InputRef_synthetic:
                {
                    __auto_type sb = _mv_44.data.synthetic;
                    return canon_string_cmp(sa, sb);
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

int64_t canon_missing_declaration_cmp(types_MissingDeclaration a, types_MissingDeclaration b) {
    {
        __auto_type ka = canon_entity_kind_rank(a.kind);
        __auto_type kb = canon_entity_kind_rank(b.kind);
        if (ka < kb) {
            return -1;
        } else if (ka > kb) {
            return 1;
        } else {
            {
                __auto_type c = canon_iri_cmp(a.entity, b.entity);
                if (c != 0) {
                    return c;
                } else {
                    {
                        __auto_type la = ((int64_t)(((int64_t)((a.referring).len))));
                        __auto_type lb = ((int64_t)(((int64_t)((b.referring).len))));
                        __auto_type n = ((la) < (lb) ? (la) : (lb));
                        int64_t i = 0;
                        int64_t r = 0;
                        while ((i < n) && (r == 0)) {
                            r = canon_axiom_ref_cmp(canon_axiom_ref_at(a.referring, i), canon_axiom_ref_at(b.referring, i));
                            i = (i + 1);
                        }
                        if (r != 0) {
                            return r;
                        } else if (la < lb) {
                            return -1;
                        } else if (la > lb) {
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            }
        }
    }
}

int64_t canon_omission_cmp(types_Omission a, types_Omission b) {
    __auto_type _mv_45 = a;
    switch (_mv_45.tag) {
        case types_Omission_out_of_profile:
        {
            __auto_type ra = _mv_45.data.out_of_profile;
            __auto_type _mv_46 = b;
            switch (_mv_46.tag) {
                case types_Omission_out_of_profile:
                {
                    __auto_type rb = _mv_46.data.out_of_profile;
                    return canon_input_ref_cmp(ra, rb);
                }
                case types_Omission_unresolved_import:
                {
                    __auto_type _ = _mv_46.data.unresolved_import;
                    return -1;
                }
                case types_Omission_missing_declaration:
                {
                    __auto_type _ = _mv_46.data.missing_declaration;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_Omission_unresolved_import:
        {
            __auto_type ia = _mv_45.data.unresolved_import;
            __auto_type _mv_47 = b;
            switch (_mv_47.tag) {
                case types_Omission_out_of_profile:
                {
                    __auto_type _ = _mv_47.data.out_of_profile;
                    return 1;
                }
                case types_Omission_unresolved_import:
                {
                    __auto_type ib = _mv_47.data.unresolved_import;
                    return canon_iri_cmp(ia, ib);
                }
                case types_Omission_missing_declaration:
                {
                    __auto_type _ = _mv_47.data.missing_declaration;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_Omission_missing_declaration:
        {
            __auto_type ma = _mv_45.data.missing_declaration;
            __auto_type _mv_48 = b;
            switch (_mv_48.tag) {
                case types_Omission_out_of_profile:
                {
                    __auto_type _ = _mv_48.data.out_of_profile;
                    return 1;
                }
                case types_Omission_unresolved_import:
                {
                    __auto_type _ = _mv_48.data.unresolved_import;
                    return 1;
                }
                case types_Omission_missing_declaration:
                {
                    __auto_type mb = _mv_48.data.missing_declaration;
                    return canon_missing_declaration_cmp(ma, mb);
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

int64_t canon_int_at(slop_list_int xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_49 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_49.has_value) {
        __auto_type v = _mv_49.value;
        return v;
    } else if (!_mv_49.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string canon_str_at(slop_list_string xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_50 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_string _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_50.has_value) {
        __auto_type v = _mv_50.value;
        return v;
    } else if (!_mv_50.has_value) {
        return SLOP_STR("");
    }
    SLOP_UNREACHABLE();
}

rdf_IRI canon_iri_at(slop_list_rdf_IRI xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_51 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_rdf_IRI _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_51.has_value) {
        __auto_type v = _mv_51.value;
        return v;
    } else if (!_mv_51.has_value) {
        return ((rdf_IRI){.value = SLOP_STR("")});
    }
    SLOP_UNREACHABLE();
}

types_Node canon_node_at(slop_list_types_Node xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_52 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_Node _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_52.has_value) {
        __auto_type v = _mv_52.value;
        return v;
    } else if (!_mv_52.has_value) {
        return ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = 0 });
    }
    SLOP_UNREACHABLE();
}

types_SubPair canon_sub_pair_at(slop_list_types_SubPair xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_53 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_SubPair _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_53.has_value) {
        __auto_type v = _mv_53.value;
        return v;
    } else if (!_mv_53.has_value) {
        return ((types_SubPair){.sub = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = 0 }), .super = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = 0 })});
    }
    SLOP_UNREACHABLE();
}

types_AxiomRef canon_axiom_ref_at(slop_list_types_AxiomRef xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_54 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_AxiomRef _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_54.has_value) {
        __auto_type v = _mv_54.value;
        return v;
    } else if (!_mv_54.has_value) {
        return ((types_AxiomRef){.source = (slop_option_rdf_IRI){.has_value = false}, .text = SLOP_STR("")});
    }
    SLOP_UNREACHABLE();
}

types_Omission canon_omission_at(slop_list_types_Omission xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_55 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_55.has_value) {
        __auto_type v = _mv_55.value;
        return v;
    } else if (!_mv_55.has_value) {
        return ((types_Omission){ .tag = types_Omission_unresolved_import, .data.unresolved_import = ((rdf_IRI){.value = SLOP_STR("")}) });
    }
    SLOP_UNREACHABLE();
}

uint8_t canon_merge_run(slop_list_int src, slop_list_int dst, int64_t lo, int64_t mid, int64_t hi, slop_closure_t cmp) {
    {
        int64_t i = lo;
        int64_t j = mid;
        int64_t k = lo;
        while ((i < mid) && (j < hi)) {
            if (((int64_t(*)(void*, int64_t, int64_t))cmp.fn)(cmp.env, canon_int_at(src, i), canon_int_at(src, j)) <= 0) {
                ({ __auto_type _set_lst = &(dst); size_t _set_idx = (size_t)(k); __auto_type _set_val = (canon_int_at(src, i)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
                i = (i + 1);
                k = (k + 1);
            } else {
                ({ __auto_type _set_lst = &(dst); size_t _set_idx = (size_t)(k); __auto_type _set_val = (canon_int_at(src, j)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
                j = (j + 1);
                k = (k + 1);
            }
        }
        while (i < mid) {
            ({ __auto_type _set_lst = &(dst); size_t _set_idx = (size_t)(k); __auto_type _set_val = (canon_int_at(src, i)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
            i = (i + 1);
            k = (k + 1);
        }
        while (j < hi) {
            ({ __auto_type _set_lst = &(dst); size_t _set_idx = (size_t)(k); __auto_type _set_val = (canon_int_at(src, j)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
            j = (j + 1);
            k = (k + 1);
        }
        return 1;
    }
}

slop_list_int canon_sort_range(slop_arena* arena, int64_t n, slop_closure_t cmp) {
    {
        __auto_type src = ((slop_list_int){ .data = (int64_t*)slop_arena_alloc(arena, 16 * sizeof(int64_t)), .len = 0, .cap = 16 });
        __auto_type dst = ((slop_list_int){ .data = (int64_t*)slop_arena_alloc(arena, 16 * sizeof(int64_t)), .len = 0, .cap = 16 });
        int64_t i = 0;
        int64_t width = 1;
        while (i < n) {
            ({ __auto_type _lst_p = &(src); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(dst); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        while (width < n) {
            {
                int64_t lo = 0;
                while (lo < n) {
                    {
                        __auto_type mid = (((lo + width)) < (n) ? ((lo + width)) : (n));
                        __auto_type hi = (((lo + (width + width))) < (n) ? ((lo + (width + width))) : (n));
                        canon_merge_run(src, dst, lo, mid, hi, cmp);
                        lo = hi;
                    }
                }
            }
            {
                __auto_type tmp = src;
                src = dst;
                dst = tmp;
            }
            width = (width + width);
        }
        return src;
    }
}

slop_list_string canon_sort_strings(slop_arena* arena, slop_list_string xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ canon__lambda_56_env_t* canon__lambda_56_env = (canon__lambda_56_env_t*)slop_arena_alloc(arena, sizeof(canon__lambda_56_env_t)); *canon__lambda_56_env = (canon__lambda_56_env_t){ .xs = xs }; (slop_closure_t){ (void*)canon__lambda_56, (void*)canon__lambda_56_env }; }));
        __auto_type out = ((slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 16 * sizeof(slop_string)), .len = 0, .cap = 16 });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (canon_str_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_rdf_IRI canon_sort_iris(slop_arena* arena, slop_list_rdf_IRI xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ canon__lambda_57_env_t* canon__lambda_57_env = (canon__lambda_57_env_t*)slop_arena_alloc(arena, sizeof(canon__lambda_57_env_t)); *canon__lambda_57_env = (canon__lambda_57_env_t){ .xs = xs }; (slop_closure_t){ (void*)canon__lambda_57, (void*)canon__lambda_57_env }; }));
        __auto_type out = ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (canon_iri_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_Node canon_sort_nodes(slop_arena* arena, slop_list_types_Node xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ canon__lambda_58_env_t* canon__lambda_58_env = (canon__lambda_58_env_t*)slop_arena_alloc(arena, sizeof(canon__lambda_58_env_t)); *canon__lambda_58_env = (canon__lambda_58_env_t){ .xs = xs }; (slop_closure_t){ (void*)canon__lambda_58, (void*)canon__lambda_58_env }; }));
        __auto_type out = ((slop_list_types_Node){ .data = (types_Node*)slop_arena_alloc(arena, 16 * sizeof(types_Node)), .len = 0, .cap = 16 });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (canon_node_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_SubPair canon_sort_sub_pairs(slop_arena* arena, slop_list_types_SubPair xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ canon__lambda_59_env_t* canon__lambda_59_env = (canon__lambda_59_env_t*)slop_arena_alloc(arena, sizeof(canon__lambda_59_env_t)); *canon__lambda_59_env = (canon__lambda_59_env_t){ .xs = xs }; (slop_closure_t){ (void*)canon__lambda_59, (void*)canon__lambda_59_env }; }));
        __auto_type out = ((slop_list_types_SubPair){ .data = (types_SubPair*)slop_arena_alloc(arena, 16 * sizeof(types_SubPair)), .len = 0, .cap = 16 });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (canon_sub_pair_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_AxiomRef canon_sort_axiom_refs(slop_arena* arena, slop_list_types_AxiomRef xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ canon__lambda_60_env_t* canon__lambda_60_env = (canon__lambda_60_env_t*)slop_arena_alloc(arena, sizeof(canon__lambda_60_env_t)); *canon__lambda_60_env = (canon__lambda_60_env_t){ .xs = xs }; (slop_closure_t){ (void*)canon__lambda_60, (void*)canon__lambda_60_env }; }));
        __auto_type out = ((slop_list_types_AxiomRef){ .data = (types_AxiomRef*)slop_arena_alloc(arena, 16 * sizeof(types_AxiomRef)), .len = 0, .cap = 16 });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (canon_axiom_ref_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_Omission canon_sort_omissions(slop_arena* arena, slop_list_types_Omission xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ canon__lambda_61_env_t* canon__lambda_61_env = (canon__lambda_61_env_t*)slop_arena_alloc(arena, sizeof(canon__lambda_61_env_t)); *canon__lambda_61_env = (canon__lambda_61_env_t){ .xs = xs }; (slop_closure_t){ (void*)canon__lambda_61, (void*)canon__lambda_61_env }; }));
        __auto_type out = ((slop_list_types_Omission){ .data = (types_Omission*)slop_arena_alloc(arena, 16 * sizeof(types_Omission)), .len = 0, .cap = 16 });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (canon_omission_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

