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

typedef struct { slop_list_string xs; } canon__lambda_94_env_t;

static int64_t canon__lambda_94(canon__lambda_94_env_t* _env, int64_t i, int64_t j) { return canon_string_cmp(canon_str_at(_env->xs, i), canon_str_at(_env->xs, j)); }

typedef struct { slop_list_rdf_IRI xs; } canon__lambda_95_env_t;

static int64_t canon__lambda_95(canon__lambda_95_env_t* _env, int64_t i, int64_t j) { return canon_iri_cmp(canon_iri_at(_env->xs, i), canon_iri_at(_env->xs, j)); }

typedef struct { slop_list_types_Node xs; } canon__lambda_96_env_t;

static int64_t canon__lambda_96(canon__lambda_96_env_t* _env, int64_t i, int64_t j) { return canon_node_cmp(canon_node_at(_env->xs, i), canon_node_at(_env->xs, j)); }

typedef struct { slop_list_types_SubPair xs; } canon__lambda_97_env_t;

static int64_t canon__lambda_97(canon__lambda_97_env_t* _env, int64_t i, int64_t j) { return canon_sub_pair_cmp(canon_sub_pair_at(_env->xs, i), canon_sub_pair_at(_env->xs, j)); }

typedef struct { slop_list_types_AxiomRef xs; } canon__lambda_98_env_t;

static int64_t canon__lambda_98(canon__lambda_98_env_t* _env, int64_t i, int64_t j) { return canon_axiom_ref_cmp(canon_axiom_ref_at(_env->xs, i), canon_axiom_ref_at(_env->xs, j)); }

typedef struct { slop_list_types_Omission xs; } canon__lambda_99_env_t;

static int64_t canon__lambda_99(canon__lambda_99_env_t* _env, int64_t i, int64_t j) { return canon_omission_cmp(canon_omission_at(_env->xs, i), canon_omission_at(_env->xs, j)); }

int64_t canon_string_cmp(slop_string a, slop_string b) {
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

int64_t canon_iri_cmp(rdf_IRI a, rdf_IRI b) {
    return canon_string_cmp(a.value, b.value);
}

int64_t canon_node_tag_rank(types_Node n) {
    __auto_type _mv_66 = n;
    switch (_mv_66.tag) {
        case types_Node_class_node:
        {
            __auto_type _ = _mv_66.data.class_node;
            return 0;
        }
        case types_Node_individual_node:
        {
            __auto_type _ = _mv_66.data.individual_node;
            return 1;
        }
        case types_Node_fresh_node:
        {
            __auto_type _ = _mv_66.data.fresh_node;
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
            __auto_type _mv_67 = a;
            switch (_mv_67.tag) {
                case types_Node_class_node:
                {
                    __auto_type ia = _mv_67.data.class_node;
                    __auto_type _mv_68 = b;
                    switch (_mv_68.tag) {
                        case types_Node_class_node:
                        {
                            __auto_type ib = _mv_68.data.class_node;
                            return canon_iri_cmp(ia, ib);
                        }
                        case types_Node_individual_node:
                        {
                            __auto_type _ = _mv_68.data.individual_node;
                            return 0;
                        }
                        case types_Node_fresh_node:
                        {
                            __auto_type _ = _mv_68.data.fresh_node;
                            return 0;
                        }
                    }
                    SLOP_UNREACHABLE();
                }
                case types_Node_individual_node:
                {
                    __auto_type ia = _mv_67.data.individual_node;
                    __auto_type _mv_69 = b;
                    switch (_mv_69.tag) {
                        case types_Node_individual_node:
                        {
                            __auto_type ib = _mv_69.data.individual_node;
                            return canon_iri_cmp(ia, ib);
                        }
                        case types_Node_class_node:
                        {
                            __auto_type _ = _mv_69.data.class_node;
                            return 0;
                        }
                        case types_Node_fresh_node:
                        {
                            __auto_type _ = _mv_69.data.fresh_node;
                            return 0;
                        }
                    }
                    SLOP_UNREACHABLE();
                }
                case types_Node_fresh_node:
                {
                    __auto_type fa = _mv_67.data.fresh_node;
                    __auto_type _mv_70 = b;
                    switch (_mv_70.tag) {
                        case types_Node_fresh_node:
                        {
                            __auto_type fb = _mv_70.data.fresh_node;
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
                            __auto_type _ = _mv_70.data.class_node;
                            return 0;
                        }
                        case types_Node_individual_node:
                        {
                            __auto_type _ = _mv_70.data.individual_node;
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
    __auto_type _mv_71 = a;
    switch (_mv_71.tag) {
        case types_RoleId_named_role:
        {
            __auto_type ia = _mv_71.data.named_role;
            __auto_type _mv_72 = b;
            switch (_mv_72.tag) {
                case types_RoleId_named_role:
                {
                    __auto_type ib = _mv_72.data.named_role;
                    return canon_iri_cmp(ia, ib);
                }
                case types_RoleId_inverse_role:
                {
                    __auto_type _ = _mv_72.data.inverse_role;
                    return -1;
                }
                case types_RoleId_fresh_role:
                {
                    __auto_type _ = _mv_72.data.fresh_role;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_RoleId_inverse_role:
        {
            __auto_type ia = _mv_71.data.inverse_role;
            __auto_type _mv_73 = b;
            switch (_mv_73.tag) {
                case types_RoleId_named_role:
                {
                    __auto_type _ = _mv_73.data.named_role;
                    return 1;
                }
                case types_RoleId_inverse_role:
                {
                    __auto_type ib = _mv_73.data.inverse_role;
                    return canon_iri_cmp(ia, ib);
                }
                case types_RoleId_fresh_role:
                {
                    __auto_type _ = _mv_73.data.fresh_role;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_RoleId_fresh_role:
        {
            __auto_type fa = _mv_71.data.fresh_role;
            __auto_type _mv_74 = b;
            switch (_mv_74.tag) {
                case types_RoleId_named_role:
                {
                    __auto_type _ = _mv_74.data.named_role;
                    return 1;
                }
                case types_RoleId_inverse_role:
                {
                    __auto_type _ = _mv_74.data.inverse_role;
                    return 1;
                }
                case types_RoleId_fresh_role:
                {
                    __auto_type fb = _mv_74.data.fresh_role;
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
    __auto_type _mv_75 = k;
    if (_mv_75 == types_EntityKind_entity_class) {
        return 0;
    } else if (_mv_75 == types_EntityKind_entity_object_property) {
        return 1;
    } else if (_mv_75 == types_EntityKind_entity_data_property) {
        return 2;
    } else if (_mv_75 == types_EntityKind_entity_annotation_property) {
        return 3;
    } else if (_mv_75 == types_EntityKind_entity_individual) {
        return 4;
    } else if (_mv_75 == types_EntityKind_entity_datatype) {
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
            __auto_type _mv_76 = a.source;
            if (!_mv_76.has_value) {
                __auto_type _mv_77 = b.source;
                if (!_mv_77.has_value) {
                    return 0;
                } else if (_mv_77.has_value) {
                    __auto_type _ = _mv_77.value;
                    return -1;
                }
                SLOP_UNREACHABLE();
            } else if (_mv_76.has_value) {
                __auto_type ia = _mv_76.value;
                __auto_type _mv_78 = b.source;
                if (!_mv_78.has_value) {
                    return 1;
                } else if (_mv_78.has_value) {
                    __auto_type ib = _mv_78.value;
                    return canon_iri_cmp(ia, ib);
                }
                SLOP_UNREACHABLE();
            }
            SLOP_UNREACHABLE();
        }
    }
}

int64_t canon_input_ref_cmp(types_InputRef a, types_InputRef b) {
    __auto_type _mv_79 = a;
    switch (_mv_79.tag) {
        case types_InputRef_owl_axiom:
        {
            __auto_type ra = _mv_79.data.owl_axiom;
            __auto_type _mv_80 = b;
            switch (_mv_80.tag) {
                case types_InputRef_owl_axiom:
                {
                    __auto_type rb = _mv_80.data.owl_axiom;
                    return canon_axiom_ref_cmp(ra, rb);
                }
                case types_InputRef_rdf_fragment:
                {
                    __auto_type _ = _mv_80.data.rdf_fragment;
                    return -1;
                }
                case types_InputRef_synthetic:
                {
                    __auto_type _ = _mv_80.data.synthetic;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_InputRef_rdf_fragment:
        {
            __auto_type sa = _mv_79.data.rdf_fragment;
            __auto_type _mv_81 = b;
            switch (_mv_81.tag) {
                case types_InputRef_owl_axiom:
                {
                    __auto_type _ = _mv_81.data.owl_axiom;
                    return 1;
                }
                case types_InputRef_rdf_fragment:
                {
                    __auto_type sb = _mv_81.data.rdf_fragment;
                    return canon_string_cmp(sa, sb);
                }
                case types_InputRef_synthetic:
                {
                    __auto_type _ = _mv_81.data.synthetic;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_InputRef_synthetic:
        {
            __auto_type sa = _mv_79.data.synthetic;
            __auto_type _mv_82 = b;
            switch (_mv_82.tag) {
                case types_InputRef_owl_axiom:
                {
                    __auto_type _ = _mv_82.data.owl_axiom;
                    return 1;
                }
                case types_InputRef_rdf_fragment:
                {
                    __auto_type _ = _mv_82.data.rdf_fragment;
                    return 1;
                }
                case types_InputRef_synthetic:
                {
                    __auto_type sb = _mv_82.data.synthetic;
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
    __auto_type _mv_83 = a;
    switch (_mv_83.tag) {
        case types_Omission_out_of_profile:
        {
            __auto_type ra = _mv_83.data.out_of_profile;
            __auto_type _mv_84 = b;
            switch (_mv_84.tag) {
                case types_Omission_out_of_profile:
                {
                    __auto_type rb = _mv_84.data.out_of_profile;
                    return canon_input_ref_cmp(ra, rb);
                }
                case types_Omission_unresolved_import:
                {
                    __auto_type _ = _mv_84.data.unresolved_import;
                    return -1;
                }
                case types_Omission_missing_declaration:
                {
                    __auto_type _ = _mv_84.data.missing_declaration;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_Omission_unresolved_import:
        {
            __auto_type ia = _mv_83.data.unresolved_import;
            __auto_type _mv_85 = b;
            switch (_mv_85.tag) {
                case types_Omission_out_of_profile:
                {
                    __auto_type _ = _mv_85.data.out_of_profile;
                    return 1;
                }
                case types_Omission_unresolved_import:
                {
                    __auto_type ib = _mv_85.data.unresolved_import;
                    return canon_iri_cmp(ia, ib);
                }
                case types_Omission_missing_declaration:
                {
                    __auto_type _ = _mv_85.data.missing_declaration;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_Omission_missing_declaration:
        {
            __auto_type ma = _mv_83.data.missing_declaration;
            __auto_type _mv_86 = b;
            switch (_mv_86.tag) {
                case types_Omission_out_of_profile:
                {
                    __auto_type _ = _mv_86.data.out_of_profile;
                    return 1;
                }
                case types_Omission_unresolved_import:
                {
                    __auto_type _ = _mv_86.data.unresolved_import;
                    return 1;
                }
                case types_Omission_missing_declaration:
                {
                    __auto_type mb = _mv_86.data.missing_declaration;
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
    __auto_type _mv_87 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_87.has_value) {
        __auto_type v = _mv_87.value;
        return v;
    } else if (!_mv_87.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_string canon_str_at(slop_list_string xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_88 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_string _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_88.has_value) {
        __auto_type v = _mv_88.value;
        return v;
    } else if (!_mv_88.has_value) {
        return SLOP_STR("");
    }
    SLOP_UNREACHABLE();
}

rdf_IRI canon_iri_at(slop_list_rdf_IRI xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_89 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_rdf_IRI _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_89.has_value) {
        __auto_type v = _mv_89.value;
        return v;
    } else if (!_mv_89.has_value) {
        return ((rdf_IRI){.value = SLOP_STR("")});
    }
    SLOP_UNREACHABLE();
}

types_Node canon_node_at(slop_list_types_Node xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_90 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_Node _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_90.has_value) {
        __auto_type v = _mv_90.value;
        return v;
    } else if (!_mv_90.has_value) {
        return ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = 0 });
    }
    SLOP_UNREACHABLE();
}

types_SubPair canon_sub_pair_at(slop_list_types_SubPair xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_91 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_SubPair _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_91.has_value) {
        __auto_type v = _mv_91.value;
        return v;
    } else if (!_mv_91.has_value) {
        return ((types_SubPair){.sub = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = 0 }), .super = ((types_Node){ .tag = types_Node_fresh_node, .data.fresh_node = 0 })});
    }
    SLOP_UNREACHABLE();
}

types_AxiomRef canon_axiom_ref_at(slop_list_types_AxiomRef xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_92 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_AxiomRef _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_92.has_value) {
        __auto_type v = _mv_92.value;
        return v;
    } else if (!_mv_92.has_value) {
        return ((types_AxiomRef){.source = (slop_option_rdf_IRI){.has_value = false}, .text = SLOP_STR("")});
    }
    SLOP_UNREACHABLE();
}

types_Omission canon_omission_at(slop_list_types_Omission xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_93 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_Omission _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_93.has_value) {
        __auto_type v = _mv_93.value;
        return v;
    } else if (!_mv_93.has_value) {
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
        __auto_type src = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type dst = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        int64_t width = 1;
        while (i < n) {
            ({ __auto_type _lst_p = &(src); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(dst); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ canon__lambda_94_env_t* canon__lambda_94_env = (canon__lambda_94_env_t*)slop_arena_alloc(arena, sizeof(canon__lambda_94_env_t)); *canon__lambda_94_env = (canon__lambda_94_env_t){ .xs = xs }; (slop_closure_t){ (void*)canon__lambda_94, (void*)canon__lambda_94_env }; }));
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (canon_str_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_rdf_IRI canon_sort_iris(slop_arena* arena, slop_list_rdf_IRI xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ canon__lambda_95_env_t* canon__lambda_95_env = (canon__lambda_95_env_t*)slop_arena_alloc(arena, sizeof(canon__lambda_95_env_t)); *canon__lambda_95_env = (canon__lambda_95_env_t){ .xs = xs }; (slop_closure_t){ (void*)canon__lambda_95, (void*)canon__lambda_95_env }; }));
        __auto_type out = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (canon_iri_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_Node canon_sort_nodes(slop_arena* arena, slop_list_types_Node xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ canon__lambda_96_env_t* canon__lambda_96_env = (canon__lambda_96_env_t*)slop_arena_alloc(arena, sizeof(canon__lambda_96_env_t)); *canon__lambda_96_env = (canon__lambda_96_env_t){ .xs = xs }; (slop_closure_t){ (void*)canon__lambda_96, (void*)canon__lambda_96_env }; }));
        __auto_type out = ((slop_list_types_Node){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (canon_node_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_SubPair canon_sort_sub_pairs(slop_arena* arena, slop_list_types_SubPair xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ canon__lambda_97_env_t* canon__lambda_97_env = (canon__lambda_97_env_t*)slop_arena_alloc(arena, sizeof(canon__lambda_97_env_t)); *canon__lambda_97_env = (canon__lambda_97_env_t){ .xs = xs }; (slop_closure_t){ (void*)canon__lambda_97, (void*)canon__lambda_97_env }; }));
        __auto_type out = ((slop_list_types_SubPair){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (canon_sub_pair_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_AxiomRef canon_sort_axiom_refs(slop_arena* arena, slop_list_types_AxiomRef xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ canon__lambda_98_env_t* canon__lambda_98_env = (canon__lambda_98_env_t*)slop_arena_alloc(arena, sizeof(canon__lambda_98_env_t)); *canon__lambda_98_env = (canon__lambda_98_env_t){ .xs = xs }; (slop_closure_t){ (void*)canon__lambda_98, (void*)canon__lambda_98_env }; }));
        __auto_type out = ((slop_list_types_AxiomRef){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (canon_axiom_ref_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_Omission canon_sort_omissions(slop_arena* arena, slop_list_types_Omission xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ canon__lambda_99_env_t* canon__lambda_99_env = (canon__lambda_99_env_t*)slop_arena_alloc(arena, sizeof(canon__lambda_99_env_t)); *canon__lambda_99_env = (canon__lambda_99_env_t){ .xs = xs }; (slop_closure_t){ (void*)canon__lambda_99, (void*)canon__lambda_99_env }; }));
        __auto_type out = ((slop_list_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (canon_omission_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

