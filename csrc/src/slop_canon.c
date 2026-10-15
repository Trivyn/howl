#include "../runtime/slop_runtime.h"
#include "slop_canon.h"

int64_t howl_canon_string_cmp(slop_string a, slop_string b);
int64_t howl_canon_iri_cmp(slop_rdf_rdf_IRI a, slop_rdf_rdf_IRI b);
int64_t howl_canon_node_tag_rank(howl_types_Node n);
int64_t howl_canon_node_cmp(howl_types_Node a, howl_types_Node b);
int64_t howl_canon_role_cmp(howl_types_RoleId a, howl_types_RoleId b);
int64_t howl_canon_sub_pair_cmp(howl_types_SubPair a, howl_types_SubPair b);
int64_t howl_canon_entity_kind_rank(howl_types_EntityKind k);
int64_t howl_canon_axiom_ref_cmp(howl_types_AxiomRef a, howl_types_AxiomRef b);
int64_t howl_canon_input_ref_cmp(howl_types_InputRef a, howl_types_InputRef b);
int64_t howl_canon_missing_declaration_cmp(howl_types_MissingDeclaration a, howl_types_MissingDeclaration b);
int64_t howl_canon_undeclared_property_cmp(howl_types_UndeclaredProperty a, howl_types_UndeclaredProperty b);
int64_t howl_canon_omission_rank(howl_types_Omission o);
int64_t howl_canon_omission_cmp(howl_types_Omission a, howl_types_Omission b);
int64_t howl_canon_int_at(slop_list_int xs, int64_t i);
slop_string howl_canon_str_at(slop_list_string xs, int64_t i);
slop_rdf_rdf_IRI howl_canon_iri_at(slop_list_slop_rdf_rdf_IRI xs, int64_t i);
howl_types_Node howl_canon_node_at(slop_list_howl_types_Node xs, int64_t i);
howl_types_SubPair howl_canon_sub_pair_at(slop_list_howl_types_SubPair xs, int64_t i);
howl_types_AxiomRef howl_canon_axiom_ref_at(slop_list_howl_types_AxiomRef xs, int64_t i);
howl_types_Omission howl_canon_omission_at(slop_list_howl_types_Omission xs, int64_t i);
uint8_t howl_canon_merge_run(slop_list_int src, slop_list_int dst, int64_t lo, int64_t mid, int64_t hi, slop_closure_t cmp);
slop_list_int howl_canon_sort_range(slop_arena* arena, int64_t n, slop_closure_t cmp);
slop_list_string howl_canon_sort_strings(slop_arena* arena, slop_list_string xs);
slop_list_slop_rdf_rdf_IRI howl_canon_sort_iris(slop_arena* arena, slop_list_slop_rdf_rdf_IRI xs);
slop_list_howl_types_Node howl_canon_sort_nodes(slop_arena* arena, slop_list_howl_types_Node xs);
slop_list_howl_types_SubPair howl_canon_sort_sub_pairs(slop_arena* arena, slop_list_howl_types_SubPair xs);
slop_list_howl_types_AxiomRef howl_canon_sort_axiom_refs(slop_arena* arena, slop_list_howl_types_AxiomRef xs);
slop_list_howl_types_Omission howl_canon_sort_omissions(slop_arena* arena, slop_list_howl_types_Omission xs);

typedef struct { slop_list_string xs; } howl_canon__lambda_98_env_t;

static int64_t howl_canon__lambda_98(howl_canon__lambda_98_env_t* _env, int64_t i, int64_t j) { return howl_canon_string_cmp(howl_canon_str_at(_env->xs, i), howl_canon_str_at(_env->xs, j)); }

typedef struct { slop_list_slop_rdf_rdf_IRI xs; } howl_canon__lambda_99_env_t;

static int64_t howl_canon__lambda_99(howl_canon__lambda_99_env_t* _env, int64_t i, int64_t j) { return howl_canon_iri_cmp(howl_canon_iri_at(_env->xs, i), howl_canon_iri_at(_env->xs, j)); }

typedef struct { slop_list_howl_types_Node xs; } howl_canon__lambda_100_env_t;

static int64_t howl_canon__lambda_100(howl_canon__lambda_100_env_t* _env, int64_t i, int64_t j) { return howl_canon_node_cmp(howl_canon_node_at(_env->xs, i), howl_canon_node_at(_env->xs, j)); }

typedef struct { slop_list_howl_types_SubPair xs; } howl_canon__lambda_101_env_t;

static int64_t howl_canon__lambda_101(howl_canon__lambda_101_env_t* _env, int64_t i, int64_t j) { return howl_canon_sub_pair_cmp(howl_canon_sub_pair_at(_env->xs, i), howl_canon_sub_pair_at(_env->xs, j)); }

typedef struct { slop_list_howl_types_AxiomRef xs; } howl_canon__lambda_102_env_t;

static int64_t howl_canon__lambda_102(howl_canon__lambda_102_env_t* _env, int64_t i, int64_t j) { return howl_canon_axiom_ref_cmp(howl_canon_axiom_ref_at(_env->xs, i), howl_canon_axiom_ref_at(_env->xs, j)); }

typedef struct { slop_list_howl_types_Omission xs; } howl_canon__lambda_103_env_t;

static int64_t howl_canon__lambda_103(howl_canon__lambda_103_env_t* _env, int64_t i, int64_t j) { return howl_canon_omission_cmp(howl_canon_omission_at(_env->xs, i), howl_canon_omission_at(_env->xs, j)); }

int64_t howl_canon_string_cmp(slop_string a, slop_string b) {
    int64_t _retval = {0};
    {
        __auto_type alen = ((int64_t)(a.len));
        __auto_type blen = ((int64_t)(b.len));
        __auto_type n = ((alen) < (blen) ? (alen) : (blen));
        __auto_type r = memcmp(((uint8_t*)(a.data)), ((uint8_t*)(b.data)), ((uint64_t)(n)));
        if (r < 0) {
            _retval = -1;
            goto _slop_post;
        } else if (r > 0) {
            _retval = 1;
            goto _slop_post;
        } else if (alen < blen) {
            _retval = -1;
            goto _slop_post;
        } else if (alen > blen) {
            _retval = 1;
            goto _slop_post;
        } else {
            _retval = 0;
            goto _slop_post;
        }
    }
    _slop_post: ;
    SLOP_POST(((((_retval == -1)) || ((_retval == 0)) || ((_retval == 1)))), "(or (== $result -1) (== $result 0) (== $result 1))");
    return _retval;
}

int64_t howl_canon_iri_cmp(slop_rdf_rdf_IRI a, slop_rdf_rdf_IRI b) {
    return howl_canon_string_cmp(a.value, b.value);
}

int64_t howl_canon_node_tag_rank(howl_types_Node n) {
    __auto_type _mv_68 = n;
    switch (_mv_68.tag) {
        case howl_types_Node_class_node:
        {
            __auto_type _ = _mv_68.data.class_node;
            return 0;
        }
        case howl_types_Node_individual_node:
        {
            __auto_type _ = _mv_68.data.individual_node;
            return 1;
        }
        case howl_types_Node_fresh_node:
        {
            __auto_type _ = _mv_68.data.fresh_node;
            return 2;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t howl_canon_node_cmp(howl_types_Node a, howl_types_Node b) {
    {
        __auto_type ra = howl_canon_node_tag_rank(a);
        __auto_type rb = howl_canon_node_tag_rank(b);
        if (ra < rb) {
            return -1;
        } else if (ra > rb) {
            return 1;
        } else {
            __auto_type _mv_69 = a;
            switch (_mv_69.tag) {
                case howl_types_Node_class_node:
                {
                    __auto_type ia = _mv_69.data.class_node;
                    __auto_type _mv_70 = b;
                    switch (_mv_70.tag) {
                        case howl_types_Node_class_node:
                        {
                            __auto_type ib = _mv_70.data.class_node;
                            return howl_canon_iri_cmp(ia, ib);
                        }
                        case howl_types_Node_individual_node:
                        {
                            __auto_type _ = _mv_70.data.individual_node;
                            return 0;
                        }
                        case howl_types_Node_fresh_node:
                        {
                            __auto_type _ = _mv_70.data.fresh_node;
                            return 0;
                        }
                    }
                    SLOP_UNREACHABLE();
                }
                case howl_types_Node_individual_node:
                {
                    __auto_type ia = _mv_69.data.individual_node;
                    __auto_type _mv_71 = b;
                    switch (_mv_71.tag) {
                        case howl_types_Node_individual_node:
                        {
                            __auto_type ib = _mv_71.data.individual_node;
                            return howl_canon_iri_cmp(ia, ib);
                        }
                        case howl_types_Node_class_node:
                        {
                            __auto_type _ = _mv_71.data.class_node;
                            return 0;
                        }
                        case howl_types_Node_fresh_node:
                        {
                            __auto_type _ = _mv_71.data.fresh_node;
                            return 0;
                        }
                    }
                    SLOP_UNREACHABLE();
                }
                case howl_types_Node_fresh_node:
                {
                    __auto_type fa = _mv_69.data.fresh_node;
                    __auto_type _mv_72 = b;
                    switch (_mv_72.tag) {
                        case howl_types_Node_fresh_node:
                        {
                            __auto_type fb = _mv_72.data.fresh_node;
                            if (fa < fb) {
                                return -1;
                            } else if (fa > fb) {
                                return 1;
                            } else {
                                return 0;
                            }
                        }
                        case howl_types_Node_class_node:
                        {
                            __auto_type _ = _mv_72.data.class_node;
                            return 0;
                        }
                        case howl_types_Node_individual_node:
                        {
                            __auto_type _ = _mv_72.data.individual_node;
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

int64_t howl_canon_role_cmp(howl_types_RoleId a, howl_types_RoleId b) {
    __auto_type _mv_73 = a;
    switch (_mv_73.tag) {
        case howl_types_RoleId_named_role:
        {
            __auto_type ia = _mv_73.data.named_role;
            __auto_type _mv_74 = b;
            switch (_mv_74.tag) {
                case howl_types_RoleId_named_role:
                {
                    __auto_type ib = _mv_74.data.named_role;
                    return howl_canon_iri_cmp(ia, ib);
                }
                case howl_types_RoleId_inverse_role:
                {
                    __auto_type _ = _mv_74.data.inverse_role;
                    return -1;
                }
                case howl_types_RoleId_fresh_role:
                {
                    __auto_type _ = _mv_74.data.fresh_role;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type ia = _mv_73.data.inverse_role;
            __auto_type _mv_75 = b;
            switch (_mv_75.tag) {
                case howl_types_RoleId_named_role:
                {
                    __auto_type _ = _mv_75.data.named_role;
                    return 1;
                }
                case howl_types_RoleId_inverse_role:
                {
                    __auto_type ib = _mv_75.data.inverse_role;
                    return howl_canon_iri_cmp(ia, ib);
                }
                case howl_types_RoleId_fresh_role:
                {
                    __auto_type _ = _mv_75.data.fresh_role;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type fa = _mv_73.data.fresh_role;
            __auto_type _mv_76 = b;
            switch (_mv_76.tag) {
                case howl_types_RoleId_named_role:
                {
                    __auto_type _ = _mv_76.data.named_role;
                    return 1;
                }
                case howl_types_RoleId_inverse_role:
                {
                    __auto_type _ = _mv_76.data.inverse_role;
                    return 1;
                }
                case howl_types_RoleId_fresh_role:
                {
                    __auto_type fb = _mv_76.data.fresh_role;
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

int64_t howl_canon_sub_pair_cmp(howl_types_SubPair a, howl_types_SubPair b) {
    {
        __auto_type c = howl_canon_node_cmp(a.sub, b.sub);
        if (c != 0) {
            return c;
        } else {
            return howl_canon_node_cmp(a.super, b.super);
        }
    }
}

int64_t howl_canon_entity_kind_rank(howl_types_EntityKind k) {
    __auto_type _mv_77 = k;
    if (_mv_77 == howl_types_EntityKind_entity_class) {
        return 0;
    } else if (_mv_77 == howl_types_EntityKind_entity_object_property) {
        return 1;
    } else if (_mv_77 == howl_types_EntityKind_entity_data_property) {
        return 2;
    } else if (_mv_77 == howl_types_EntityKind_entity_annotation_property) {
        return 3;
    } else if (_mv_77 == howl_types_EntityKind_entity_individual) {
        return 4;
    } else if (_mv_77 == howl_types_EntityKind_entity_datatype) {
        return 5;
    }
    SLOP_UNREACHABLE();
}

int64_t howl_canon_axiom_ref_cmp(howl_types_AxiomRef a, howl_types_AxiomRef b) {
    {
        __auto_type c = howl_canon_string_cmp(a.text, b.text);
        if (c != 0) {
            return c;
        } else {
            __auto_type _mv_78 = a.source;
            if (!_mv_78.has_value) {
                __auto_type _mv_79 = b.source;
                if (!_mv_79.has_value) {
                    return 0;
                } else if (_mv_79.has_value) {
                    __auto_type _ = _mv_79.value;
                    return -1;
                }
                SLOP_UNREACHABLE();
            } else if (_mv_78.has_value) {
                __auto_type ia = _mv_78.value;
                __auto_type _mv_80 = b.source;
                if (!_mv_80.has_value) {
                    return 1;
                } else if (_mv_80.has_value) {
                    __auto_type ib = _mv_80.value;
                    return howl_canon_iri_cmp(ia, ib);
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
    }
}

int64_t howl_canon_input_ref_cmp(howl_types_InputRef a, howl_types_InputRef b) {
    __auto_type _mv_81 = a;
    switch (_mv_81.tag) {
        case howl_types_InputRef_owl_axiom:
        {
            __auto_type ra = _mv_81.data.owl_axiom;
            __auto_type _mv_82 = b;
            switch (_mv_82.tag) {
                case howl_types_InputRef_owl_axiom:
                {
                    __auto_type rb = _mv_82.data.owl_axiom;
                    return howl_canon_axiom_ref_cmp(ra, rb);
                }
                case howl_types_InputRef_rdf_fragment:
                {
                    __auto_type _ = _mv_82.data.rdf_fragment;
                    return -1;
                }
                case howl_types_InputRef_synthetic:
                {
                    __auto_type _ = _mv_82.data.synthetic;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_InputRef_rdf_fragment:
        {
            __auto_type sa = _mv_81.data.rdf_fragment;
            __auto_type _mv_83 = b;
            switch (_mv_83.tag) {
                case howl_types_InputRef_owl_axiom:
                {
                    __auto_type _ = _mv_83.data.owl_axiom;
                    return 1;
                }
                case howl_types_InputRef_rdf_fragment:
                {
                    __auto_type sb = _mv_83.data.rdf_fragment;
                    return howl_canon_string_cmp(sa, sb);
                }
                case howl_types_InputRef_synthetic:
                {
                    __auto_type _ = _mv_83.data.synthetic;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_InputRef_synthetic:
        {
            __auto_type sa = _mv_81.data.synthetic;
            __auto_type _mv_84 = b;
            switch (_mv_84.tag) {
                case howl_types_InputRef_owl_axiom:
                {
                    __auto_type _ = _mv_84.data.owl_axiom;
                    return 1;
                }
                case howl_types_InputRef_rdf_fragment:
                {
                    __auto_type _ = _mv_84.data.rdf_fragment;
                    return 1;
                }
                case howl_types_InputRef_synthetic:
                {
                    __auto_type sb = _mv_84.data.synthetic;
                    return howl_canon_string_cmp(sa, sb);
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

int64_t howl_canon_missing_declaration_cmp(howl_types_MissingDeclaration a, howl_types_MissingDeclaration b) {
    {
        __auto_type ka = howl_canon_entity_kind_rank(a.kind);
        __auto_type kb = howl_canon_entity_kind_rank(b.kind);
        if (ka < kb) {
            return -1;
        } else if (ka > kb) {
            return 1;
        } else {
            {
                __auto_type c = howl_canon_iri_cmp(a.entity, b.entity);
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
                            r = howl_canon_axiom_ref_cmp(howl_canon_axiom_ref_at(a.referring, i), howl_canon_axiom_ref_at(b.referring, i));
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

int64_t howl_canon_undeclared_property_cmp(howl_types_UndeclaredProperty a, howl_types_UndeclaredProperty b) {
    {
        __auto_type c = howl_canon_iri_cmp(a.property, b.property);
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
                    r = howl_canon_string_cmp(howl_canon_str_at(a.referring, i), howl_canon_str_at(b.referring, i));
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

int64_t howl_canon_omission_rank(howl_types_Omission o) {
    __auto_type _mv_85 = o;
    switch (_mv_85.tag) {
        case howl_types_Omission_out_of_profile:
        {
            __auto_type _ = _mv_85.data.out_of_profile;
            return 0;
        }
        case howl_types_Omission_unresolved_import:
        {
            __auto_type _ = _mv_85.data.unresolved_import;
            return 1;
        }
        case howl_types_Omission_missing_declaration:
        {
            __auto_type _ = _mv_85.data.missing_declaration;
            return 2;
        }
        case howl_types_Omission_undeclared_property:
        {
            __auto_type _ = _mv_85.data.undeclared_property;
            return 3;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t howl_canon_omission_cmp(howl_types_Omission a, howl_types_Omission b) {
    {
        __auto_type ra = howl_canon_omission_rank(a);
        __auto_type rb = howl_canon_omission_rank(b);
        if (ra != rb) {
            if (ra < rb) {
                return -1;
            } else {
                return 1;
            }
        } else {
            __auto_type _mv_86 = a;
            switch (_mv_86.tag) {
                case howl_types_Omission_out_of_profile:
                {
                    __auto_type x = _mv_86.data.out_of_profile;
                    __auto_type _mv_87 = b;
                    switch (_mv_87.tag) {
                        case howl_types_Omission_out_of_profile:
                        {
                            __auto_type y = _mv_87.data.out_of_profile;
                            return howl_canon_input_ref_cmp(x, y);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_types_Omission_unresolved_import:
                {
                    __auto_type x = _mv_86.data.unresolved_import;
                    __auto_type _mv_88 = b;
                    switch (_mv_88.tag) {
                        case howl_types_Omission_unresolved_import:
                        {
                            __auto_type y = _mv_88.data.unresolved_import;
                            return howl_canon_iri_cmp(x, y);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_types_Omission_missing_declaration:
                {
                    __auto_type x = _mv_86.data.missing_declaration;
                    __auto_type _mv_89 = b;
                    switch (_mv_89.tag) {
                        case howl_types_Omission_missing_declaration:
                        {
                            __auto_type y = _mv_89.data.missing_declaration;
                            return howl_canon_missing_declaration_cmp(x, y);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_types_Omission_undeclared_property:
                {
                    __auto_type x = _mv_86.data.undeclared_property;
                    __auto_type _mv_90 = b;
                    switch (_mv_90.tag) {
                        case howl_types_Omission_undeclared_property:
                        {
                            __auto_type y = _mv_90.data.undeclared_property;
                            return howl_canon_undeclared_property_cmp(x, y);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
            }
            SLOP_UNREACHABLE();
        }
    }
}

int64_t howl_canon_int_at(slop_list_int xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_91 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_91.has_value) {
        __auto_type v = _mv_91.value;
        return v;
    } else if (!_mv_91.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string howl_canon_str_at(slop_list_string xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_92 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_string _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_92.has_value) {
        __auto_type v = _mv_92.value;
        return v;
    } else if (!_mv_92.has_value) {
        return SLOP_STR("");
    }
    SLOP_UNREACHABLE();
}

slop_rdf_rdf_IRI howl_canon_iri_at(slop_list_slop_rdf_rdf_IRI xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_93 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_slop_rdf_rdf_IRI _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_93.has_value) {
        __auto_type v = _mv_93.value;
        return v;
    } else if (!_mv_93.has_value) {
        return ((slop_rdf_rdf_IRI){.value = SLOP_STR("")});
    }
    SLOP_UNREACHABLE();
}

howl_types_Node howl_canon_node_at(slop_list_howl_types_Node xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_94 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_Node _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_94.has_value) {
        __auto_type v = _mv_94.value;
        return v;
    } else if (!_mv_94.has_value) {
        return ((howl_types_Node){ .tag = howl_types_Node_fresh_node, .data.fresh_node = 0 });
    }
    SLOP_UNREACHABLE();
}

howl_types_SubPair howl_canon_sub_pair_at(slop_list_howl_types_SubPair xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_95 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_SubPair _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_95.has_value) {
        __auto_type v = _mv_95.value;
        return v;
    } else if (!_mv_95.has_value) {
        return ((howl_types_SubPair){.sub = ((howl_types_Node){ .tag = howl_types_Node_fresh_node, .data.fresh_node = 0 }), .super = ((howl_types_Node){ .tag = howl_types_Node_fresh_node, .data.fresh_node = 0 })});
    }
    SLOP_UNREACHABLE();
}

howl_types_AxiomRef howl_canon_axiom_ref_at(slop_list_howl_types_AxiomRef xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_96 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_AxiomRef _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_96.has_value) {
        __auto_type v = _mv_96.value;
        return v;
    } else if (!_mv_96.has_value) {
        return ((howl_types_AxiomRef){.source = (slop_option_slop_rdf_rdf_IRI){.has_value = false}, .text = SLOP_STR("")});
    }
    SLOP_UNREACHABLE();
}

howl_types_Omission howl_canon_omission_at(slop_list_howl_types_Omission xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_97 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_97.has_value) {
        __auto_type v = _mv_97.value;
        return v;
    } else if (!_mv_97.has_value) {
        return ((howl_types_Omission){ .tag = howl_types_Omission_unresolved_import, .data.unresolved_import = ((slop_rdf_rdf_IRI){.value = SLOP_STR("")}) });
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_canon_merge_run(slop_list_int src, slop_list_int dst, int64_t lo, int64_t mid, int64_t hi, slop_closure_t cmp) {
    {
        int64_t i = lo;
        int64_t j = mid;
        int64_t k = lo;
        while ((i < mid) && (j < hi)) {
            if (((int64_t(*)(void*, int64_t, int64_t))cmp.fn)(cmp.env, howl_canon_int_at(src, i), howl_canon_int_at(src, j)) <= 0) {
                (void)(({ __auto_type _set_lst = &(dst); size_t _set_idx = (size_t)(k); __auto_type _set_val = (howl_canon_int_at(src, i)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
                i = (i + 1);
                k = (k + 1);
            } else {
                (void)(({ __auto_type _set_lst = &(dst); size_t _set_idx = (size_t)(k); __auto_type _set_val = (howl_canon_int_at(src, j)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
                j = (j + 1);
                k = (k + 1);
            }
        }
        while (i < mid) {
            (void)(({ __auto_type _set_lst = &(dst); size_t _set_idx = (size_t)(k); __auto_type _set_val = (howl_canon_int_at(src, i)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
            i = (i + 1);
            k = (k + 1);
        }
        while (j < hi) {
            (void)(({ __auto_type _set_lst = &(dst); size_t _set_idx = (size_t)(k); __auto_type _set_val = (howl_canon_int_at(src, j)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
            j = (j + 1);
            k = (k + 1);
        }
        return 1;
    }
}

slop_list_int howl_canon_sort_range(slop_arena* arena, int64_t n, slop_closure_t cmp) {
    {
        __auto_type src = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type dst = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        int64_t width = 1;
        while (i < n) {
            (void)(({ __auto_type _lst_p = &(src); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(dst); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            i = (i + 1);
        }
        while (width < n) {
            {
                int64_t lo = 0;
                while (lo < n) {
                    {
                        __auto_type mid = (((lo + width)) < (n) ? ((lo + width)) : (n));
                        __auto_type hi = (((lo + (width + width))) < (n) ? ((lo + (width + width))) : (n));
                        howl_canon_merge_run(src, dst, lo, mid, hi, cmp);
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

slop_list_string howl_canon_sort_strings(slop_arena* arena, slop_list_string xs) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ howl_canon__lambda_98_env_t* howl_canon__lambda_98_env = (howl_canon__lambda_98_env_t*)slop_arena_alloc(arena, sizeof(howl_canon__lambda_98_env_t)); *howl_canon__lambda_98_env = (howl_canon__lambda_98_env_t){ .xs = xs }; (slop_closure_t){ (void*)howl_canon__lambda_98, (void*)howl_canon__lambda_98_env }; }));
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_canon_str_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_slop_rdf_rdf_IRI howl_canon_sort_iris(slop_arena* arena, slop_list_slop_rdf_rdf_IRI xs) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ howl_canon__lambda_99_env_t* howl_canon__lambda_99_env = (howl_canon__lambda_99_env_t*)slop_arena_alloc(arena, sizeof(howl_canon__lambda_99_env_t)); *howl_canon__lambda_99_env = (howl_canon__lambda_99_env_t){ .xs = xs }; (slop_closure_t){ (void*)howl_canon__lambda_99, (void*)howl_canon__lambda_99_env }; }));
        __auto_type out = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_canon_iri_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_types_Node howl_canon_sort_nodes(slop_arena* arena, slop_list_howl_types_Node xs) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ howl_canon__lambda_100_env_t* howl_canon__lambda_100_env = (howl_canon__lambda_100_env_t*)slop_arena_alloc(arena, sizeof(howl_canon__lambda_100_env_t)); *howl_canon__lambda_100_env = (howl_canon__lambda_100_env_t){ .xs = xs }; (slop_closure_t){ (void*)howl_canon__lambda_100, (void*)howl_canon__lambda_100_env }; }));
        __auto_type out = ((slop_list_howl_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_canon_node_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_types_SubPair howl_canon_sort_sub_pairs(slop_arena* arena, slop_list_howl_types_SubPair xs) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ howl_canon__lambda_101_env_t* howl_canon__lambda_101_env = (howl_canon__lambda_101_env_t*)slop_arena_alloc(arena, sizeof(howl_canon__lambda_101_env_t)); *howl_canon__lambda_101_env = (howl_canon__lambda_101_env_t){ .xs = xs }; (slop_closure_t){ (void*)howl_canon__lambda_101, (void*)howl_canon__lambda_101_env }; }));
        __auto_type out = ((slop_list_howl_types_SubPair){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_canon_sub_pair_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_types_AxiomRef howl_canon_sort_axiom_refs(slop_arena* arena, slop_list_howl_types_AxiomRef xs) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ howl_canon__lambda_102_env_t* howl_canon__lambda_102_env = (howl_canon__lambda_102_env_t*)slop_arena_alloc(arena, sizeof(howl_canon__lambda_102_env_t)); *howl_canon__lambda_102_env = (howl_canon__lambda_102_env_t){ .xs = xs }; (slop_closure_t){ (void*)howl_canon__lambda_102, (void*)howl_canon__lambda_102_env }; }));
        __auto_type out = ((slop_list_howl_types_AxiomRef){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_canon_axiom_ref_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_types_Omission howl_canon_sort_omissions(slop_arena* arena, slop_list_howl_types_Omission xs) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ howl_canon__lambda_103_env_t* howl_canon__lambda_103_env = (howl_canon__lambda_103_env_t*)slop_arena_alloc(arena, sizeof(howl_canon__lambda_103_env_t)); *howl_canon__lambda_103_env = (howl_canon__lambda_103_env_t){ .xs = xs }; (slop_closure_t){ (void*)howl_canon__lambda_103, (void*)howl_canon__lambda_103_env }; }));
        __auto_type out = ((slop_list_howl_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_canon_omission_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

