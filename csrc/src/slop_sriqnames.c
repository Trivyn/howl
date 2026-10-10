#include "../runtime/slop_runtime.h"
#include "slop_sriqnames.h"

int64_t sriqnames_int_at(slop_list_int xs, int64_t i);
slop_list_int sriqnames_ints_new(slop_arena* arena, int64_t n, int64_t v);
int64_t sriqnames_cmp_int(int64_t a, int64_t b);
sroiq_SConcept sriqnames_sc_at_n(slop_list_sroiq_SConcept xs, int64_t i);
int64_t sriqnames_dname_cmp(types_DName a, types_DName b);
int64_t sriqnames_filler_cmp(slop_option_types_DName a, slop_option_types_DName b);
int64_t sriqnames_drole_rank(types_DRole r);
int64_t sriqnames_drole_cmp(types_DRole a, types_DRole b);
int64_t sriqnames_dnames_cmp(slop_list_types_DName a, slop_list_types_DName b);
int64_t sriqnames_dl_rank(types_DlClause c);
int64_t sriqnames_then_cmp(int64_t first, int64_t second);
int64_t sriqnames_dl1_cmp(types_Dl1 x, types_Dl1 y);
int64_t sriqnames_dl2_cmp(types_Dl2 x, types_Dl2 y);
int64_t sriqnames_dl4_cmp(types_Dl4 x, types_Dl4 y);
int64_t sriqnames_roles_cmp(types_DRole a1, types_DRole b1, types_DRole a2, types_DRole b2);
int64_t sriqnames_dl_cmp(types_DlClause a, types_DlClause b);
types_DName sriqnames_rename_name(slop_list_int fresh, types_DName n);
slop_option_types_DName sriqnames_rename_filler(slop_list_int fresh, slop_option_types_DName b);
types_DRole sriqnames_rename_role(slop_list_int subs, types_DRole r);
slop_list_types_DName sriqnames_sort_dnames(slop_arena* arena, slop_list_types_DName xs);
types_DName sriqnames_dname_at(slop_list_types_DName xs, int64_t i);
slop_list_types_DName sriqnames_rename_names(slop_arena* arena, slop_list_int fresh, slop_list_types_DName ns);
types_DlClause sriqnames_rename_clause(slop_arena* arena, slop_list_int fresh, slop_list_int subs, types_DlClause c);
types_DlClause sriqnames_clause_at(slop_list_types_DlClause xs, int64_t i);
types_DlClause sriqnames_renumber_fns(slop_arena* arena, types_DlClause c, int64_t next);
int64_t sriqnames_fn_count(types_DlClause c);
slop_list_int sriqnames_rank_of(slop_arena* arena, slop_list_int order);
slop_list_int sriqnames_concept_order(slop_arena* arena, slop_list_sroiq_SConcept cs);
slop_list_int sriqnames_srole_order(slop_arena* arena, slop_list_types_DRole roles, slop_list_option_types_DName fills);
slop_list_sroiq_SConcept sriqnames_pick_concepts(slop_arena* arena, slop_list_sroiq_SConcept cs, slop_list_int order);
slop_list_types_DRole sriqnames_pick_roles(slop_arena* arena, slop_list_types_DRole rs, slop_list_int order);
slop_list_option_types_DName sriqnames_pick_fills(slop_arena* arena, slop_list_option_types_DName bs, slop_list_int order);
slop_list_option_types_DName sriqnames_rename_fills(slop_arena* arena, slop_list_int fresh, slop_list_option_types_DName bs);
slop_list_types_DlClause sriqnames_rename_clauses(slop_arena* arena, slop_list_int fresh, slop_list_int subs, slop_list_types_DlClause cs);
slop_list_types_DlClause sriqnames_canonical_clauses(slop_arena* arena, slop_list_types_DlClause cs);
int64_t sriqnames_fn_total(slop_list_types_DlClause cs);
slop_list_rdf_IRI sriqnames_input_classes(slop_arena* arena, owl2_Signature sig);
slop_list_rdf_IRI sriqnames_input_individuals(slop_arena* arena, owl2_Signature sig);
sriqnames_SriqNormal sriqnames_sriq_names(slop_arena* arena, sriqnormal_S2 s2, owl2_Signature sig, slop_list_owl2_RawAxiom omitted);
types_DRole sriqnames_role_at(slop_list_types_DRole xs, int64_t i);
slop_option_types_DName sriqnames_fill_at(slop_list_option_types_DName xs, int64_t i);
slop_list_owl2_RawAxiom sriqnames_guard_witnesses(slop_arena* arena, slop_list_owl2_RawAxiom accepted, sriqelim_S1 s1);
slop_result_sriqnames_SriqNormal_string sriqnames_normalize_after_s1(slop_arena* arena, slop_list_owl2_RawAxiom accepted, sriqelim_S1 s1, owl2_Signature sig);
slop_result_sriqnames_SriqNormal_string sriqnames_normalize_after_s0(slop_arena* arena, slop_list_owl2_RawAxiom accepted, sriqnormal_S0 s0, owl2_Signature sig, int64_t bound);
slop_result_sriqnames_SriqNormal_string sriqnames_sriq_normalize_bounded(slop_arena* arena, slop_list_owl2_RawAxiom accepted, owl2_Signature sig, int64_t bound);
slop_result_sriqnames_SriqNormal_string sriqnames_sriq_normalize(slop_arena* arena, slop_list_owl2_RawAxiom accepted, owl2_Signature sig);
slop_string sriqnames_rn(slop_arena* arena, types_DName n);
slop_string sriqnames_rr(slop_arena* arena, types_DRole r);
slop_string sriqnames_rf(slop_arena* arena, slop_option_types_DName b);
slop_string sriqnames_rns(slop_arena* arena, slop_list_types_DName ns);
slop_string sriqnames_rints(slop_arena* arena, slop_list_int xs);
slop_string sriqnames_j(slop_arena* arena, slop_list_string parts);
slop_string sriqnames_render_dl_ids(slop_arena* arena, types_DlClause c);
slop_string sriqnames_table_line(slop_arena* arena, slop_string prefix, int64_t k, slop_string text);
slop_list_string sriqnames_prefixed(slop_arena* arena, slop_string prefix, slop_list_rdf_IRI is);
slop_list_string sriqnames_render_sriq_normal(slop_arena* arena, sriqnames_SriqNormal n);
uint8_t sriqnames_name_in_range(types_DName n, int64_t nc);
uint8_t sriqnames_names_in_range(slop_list_types_DName ns, int64_t nc);
uint8_t sriqnames_filler_in_range(slop_option_types_DName b, int64_t nc);
uint8_t sriqnames_role_in_range(types_DRole r, int64_t ns);
uint8_t sriqnames_clause_in_range(types_DlClause c, int64_t nc, int64_t ns);
slop_list_string sriqnames_concepts_ordered(slop_arena* arena, slop_list_sroiq_SConcept cs);
slop_list_string sriqnames_sroles_ordered(slop_arena* arena, slop_list_types_DRole rs, slop_list_option_types_DName bs);
slop_list_string sriqnames_clauses_ordered(slop_arena* arena, slop_list_types_DlClause cs);
slop_list_string sriqnames_ids_in_range(slop_arena* arena, sriqnames_SriqNormal n);
uint8_t sriqnames_witness_count_ok(types_DlClause c);
slop_list_int sriqnames_clause_fns(slop_arena* arena, types_DlClause c);
slop_list_string sriqnames_fns_dense(slop_arena* arena, sriqnames_SriqNormal n);
slop_list_string sriqnames_fresh_not_signature(slop_arena* arena, sriqnames_SriqNormal n);
slop_list_string sriqnames_sriq_invariants(slop_arena* arena, sriqnames_SriqNormal n);

typedef struct { slop_list_types_DName xs; } sriqnames__lambda_1247_env_t;

static int64_t sriqnames__lambda_1247(sriqnames__lambda_1247_env_t* _env, int64_t i, int64_t j) { return sriqnames_dname_cmp(sriqnames_dname_at(_env->xs, i), sriqnames_dname_at(_env->xs, j)); }

typedef struct { slop_list_sroiq_SConcept cs; } sriqnames__lambda_1253_env_t;

static int64_t sriqnames__lambda_1253(sriqnames__lambda_1253_env_t* _env, int64_t i, int64_t j) { return sroiq_sc_cmp(sriqnames_sc_at_n(_env->cs, i), sriqnames_sc_at_n(_env->cs, j)); }

typedef struct { slop_list_types_DRole roles; slop_list_option_types_DName fills; } sriqnames__lambda_1254_env_t;

static int64_t sriqnames__lambda_1254(sriqnames__lambda_1254_env_t* _env, int64_t i, int64_t j) { return sriqnames_then_cmp(sriqnames_drole_cmp(sriqnames_role_at(_env->roles, i), sriqnames_role_at(_env->roles, j)), sriqnames_filler_cmp(sriqnames_fill_at(_env->fills, i), sriqnames_fill_at(_env->fills, j))); }

typedef struct { slop_list_types_DlClause cs; } sriqnames__lambda_1255_env_t;

static int64_t sriqnames__lambda_1255(sriqnames__lambda_1255_env_t* _env, int64_t i, int64_t j) { return sriqnames_dl_cmp(sriqnames_clause_at(_env->cs, i), sriqnames_clause_at(_env->cs, j)); }

int64_t sriqnames_int_at(slop_list_int xs, int64_t i) {
    __auto_type _mv_1216 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1216.has_value) {
        __auto_type v = _mv_1216.value;
        return v;
    } else if (!_mv_1216.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

slop_list_int sriqnames_ints_new(slop_arena* arena, int64_t n, int64_t v) {
    {
        __auto_type xs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < n) {
            ({ __auto_type _lst_p = &(xs); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        return xs;
    }
}

int64_t sriqnames_cmp_int(int64_t a, int64_t b) {
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

sroiq_SConcept sriqnames_sc_at_n(slop_list_sroiq_SConcept xs, int64_t i) {
    __auto_type _mv_1217 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_sroiq_SConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1217.has_value) {
        __auto_type v = _mv_1217.value;
        return v;
    } else if (!_mv_1217.has_value) {
        return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_top });
    }
    SLOP_UNREACHABLE();
}

int64_t sriqnames_dname_cmp(types_DName a, types_DName b) {
    __auto_type _mv_1218 = a;
    switch (_mv_1218.tag) {
        case types_DName_dn_class:
        {
            __auto_type ia = _mv_1218.data.dn_class;
            __auto_type _mv_1219 = b;
            switch (_mv_1219.tag) {
                case types_DName_dn_class:
                {
                    __auto_type ib = _mv_1219.data.dn_class;
                    return canon_iri_cmp(ia, ib);
                }
                case types_DName_dn_fresh:
                {
                    __auto_type _ = _mv_1219.data.dn_fresh;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case types_DName_dn_fresh:
        {
            __auto_type ka = _mv_1218.data.dn_fresh;
            __auto_type _mv_1220 = b;
            switch (_mv_1220.tag) {
                case types_DName_dn_class:
                {
                    __auto_type _ = _mv_1220.data.dn_class;
                    return 1;
                }
                case types_DName_dn_fresh:
                {
                    __auto_type kb = _mv_1220.data.dn_fresh;
                    return sriqnames_cmp_int(ka, kb);
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

int64_t sriqnames_filler_cmp(slop_option_types_DName a, slop_option_types_DName b) {
    __auto_type _mv_1221 = a;
    if (!_mv_1221.has_value) {
        __auto_type _mv_1222 = b;
        if (!_mv_1222.has_value) {
            return 0;
        } else if (_mv_1222.has_value) {
            __auto_type _ = _mv_1222.value;
            return -1;
        }
        SLOP_UNREACHABLE();
    } else if (_mv_1221.has_value) {
        __auto_type x = _mv_1221.value;
        __auto_type _mv_1223 = b;
        if (!_mv_1223.has_value) {
            return 1;
        } else if (_mv_1223.has_value) {
            __auto_type y = _mv_1223.value;
            return sriqnames_dname_cmp(x, y);
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

int64_t sriqnames_drole_rank(types_DRole r) {
    __auto_type _mv_1224 = r;
    switch (_mv_1224.tag) {
        case types_DRole_dr_prop:
        {
            __auto_type _ = _mv_1224.data.dr_prop;
            return 0;
        }
        case types_DRole_dr_bar:
        {
            __auto_type _ = _mv_1224.data.dr_bar;
            return 1;
        }
        case types_DRole_dr_sub:
        {
            __auto_type _ = _mv_1224.data.dr_sub;
            return 2;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t sriqnames_drole_cmp(types_DRole a, types_DRole b) {
    {
        __auto_type ra = sriqnames_drole_rank(a);
        __auto_type rb = sriqnames_drole_rank(b);
        if (ra != rb) {
            return sriqnames_cmp_int(ra, rb);
        } else {
            __auto_type _mv_1225 = a;
            switch (_mv_1225.tag) {
                case types_DRole_dr_prop:
                {
                    __auto_type ia = _mv_1225.data.dr_prop;
                    __auto_type _mv_1226 = b;
                    switch (_mv_1226.tag) {
                        case types_DRole_dr_prop:
                        {
                            __auto_type ib = _mv_1226.data.dr_prop;
                            return canon_iri_cmp(ia, ib);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case types_DRole_dr_bar:
                {
                    __auto_type ia = _mv_1225.data.dr_bar;
                    __auto_type _mv_1227 = b;
                    switch (_mv_1227.tag) {
                        case types_DRole_dr_bar:
                        {
                            __auto_type ib = _mv_1227.data.dr_bar;
                            return canon_iri_cmp(ia, ib);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case types_DRole_dr_sub:
                {
                    __auto_type ka = _mv_1225.data.dr_sub;
                    __auto_type _mv_1228 = b;
                    switch (_mv_1228.tag) {
                        case types_DRole_dr_sub:
                        {
                            __auto_type kb = _mv_1228.data.dr_sub;
                            return sriqnames_cmp_int(ka, kb);
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

int64_t sriqnames_dnames_cmp(slop_list_types_DName a, slop_list_types_DName b) {
    {
        __auto_type alen = ((int64_t)(((int64_t)((a).len))));
        __auto_type blen = ((int64_t)(((int64_t)((b).len))));
        __auto_type n = ((alen) < (blen) ? (alen) : (blen));
        int64_t i = 0;
        int64_t r = 0;
        while ((i < n) && (r == 0)) {
            __auto_type _mv_1229 = ({ __auto_type _lst = a; size_t _idx = (size_t)i; slop_option_types_DName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1229.has_value) {
                __auto_type x = _mv_1229.value;
                __auto_type _mv_1230 = ({ __auto_type _lst = b; size_t _idx = (size_t)i; slop_option_types_DName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1230.has_value) {
                    __auto_type y = _mv_1230.value;
                    r = sriqnames_dname_cmp(x, y);
                } else if (!_mv_1230.has_value) {
                }
            } else if (!_mv_1229.has_value) {
            }
            i = (i + 1);
        }
        if (r != 0) {
            return r;
        } else if (alen < blen) {
            return -1;
        } else if (alen > blen) {
            return 1;
        } else {
            return 0;
        }
    }
}

int64_t sriqnames_dl_rank(types_DlClause c) {
    __auto_type _mv_1231 = c;
    switch (_mv_1231.tag) {
        case types_DlClause_dl1:
        {
            __auto_type _ = _mv_1231.data.dl1;
            return 1;
        }
        case types_DlClause_dl2:
        {
            __auto_type _ = _mv_1231.data.dl2;
            return 2;
        }
        case types_DlClause_dl3:
        {
            return 3;
        }
        case types_DlClause_dl4:
        {
            __auto_type _ = _mv_1231.data.dl4;
            return 4;
        }
        case types_DlClause_dl5:
        {
            return 5;
        }
        case types_DlClause_dl6:
        {
            return 6;
        }
        case types_DlClause_dl7:
        {
            return 7;
        }
        case types_DlClause_dl8:
        {
            return 8;
        }
        case types_DlClause_dl9:
        {
            return 9;
        }
        case types_DlClause_dl10:
        {
            return 10;
        }
        case types_DlClause_dl11:
        {
            return 11;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t sriqnames_then_cmp(int64_t first, int64_t second) {
    if (first != 0) {
        return first;
    } else {
        return second;
    }
}

int64_t sriqnames_dl1_cmp(types_Dl1 x, types_Dl1 y) {
    return sriqnames_then_cmp(sriqnames_dnames_cmp(x.body, y.body), sriqnames_dnames_cmp(x.head, y.head));
}

int64_t sriqnames_dl2_cmp(types_Dl2 x, types_Dl2 y) {
    return sriqnames_then_cmp(sriqnames_dname_cmp(x.sub, y.sub), sriqnames_then_cmp(sriqnames_drole_cmp(x.role, y.role), sriqnames_then_cmp(sriqnames_cmp_int(x.count, y.count), sriqnames_filler_cmp(x.filler, y.filler))));
}

int64_t sriqnames_dl4_cmp(types_Dl4 x, types_Dl4 y) {
    return sriqnames_then_cmp(sriqnames_dname_cmp(x.sub, y.sub), sriqnames_then_cmp(sriqnames_drole_cmp(x.role, y.role), sriqnames_then_cmp(sriqnames_cmp_int(x.count, y.count), sriqnames_then_cmp(sriqnames_filler_cmp(x.filler, y.filler), sriqnames_drole_cmp(x.srole, y.srole)))));
}

int64_t sriqnames_roles_cmp(types_DRole a1, types_DRole b1, types_DRole a2, types_DRole b2) {
    return sriqnames_then_cmp(sriqnames_drole_cmp(a1, a2), sriqnames_drole_cmp(b1, b2));
}

int64_t sriqnames_dl_cmp(types_DlClause a, types_DlClause b) {
    {
        __auto_type ra = sriqnames_dl_rank(a);
        __auto_type rb = sriqnames_dl_rank(b);
        if (ra != rb) {
            return sriqnames_cmp_int(ra, rb);
        } else {
            __auto_type _mv_1232 = a;
            switch (_mv_1232.tag) {
                case types_DlClause_dl1:
                {
                    __auto_type x = _mv_1232.data.dl1;
                    __auto_type _mv_1233 = b;
                    switch (_mv_1233.tag) {
                        case types_DlClause_dl1:
                        {
                            __auto_type y = _mv_1233.data.dl1;
                            return sriqnames_dl1_cmp(x, y);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case types_DlClause_dl2:
                {
                    __auto_type x = _mv_1232.data.dl2;
                    __auto_type _mv_1234 = b;
                    switch (_mv_1234.tag) {
                        case types_DlClause_dl2:
                        {
                            __auto_type y = _mv_1234.data.dl2;
                            return sriqnames_dl2_cmp(x, y);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case types_DlClause_dl3:
                {
                    __auto_type s1 = _mv_1232.data.dl3.f0;
                    __auto_type p1 = _mv_1232.data.dl3.f1;
                    __auto_type q1 = _mv_1232.data.dl3.f2;
                    __auto_type _mv_1235 = b;
                    switch (_mv_1235.tag) {
                        case types_DlClause_dl3:
                        {
                            __auto_type s2 = _mv_1235.data.dl3.f0;
                            __auto_type p2 = _mv_1235.data.dl3.f1;
                            __auto_type q2 = _mv_1235.data.dl3.f2;
                            return sriqnames_then_cmp(sriqnames_drole_cmp(s1, s2), sriqnames_then_cmp(sriqnames_dname_cmp(p1, p2), sriqnames_dname_cmp(q1, q2)));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case types_DlClause_dl4:
                {
                    __auto_type x = _mv_1232.data.dl4;
                    __auto_type _mv_1236 = b;
                    switch (_mv_1236.tag) {
                        case types_DlClause_dl4:
                        {
                            __auto_type y = _mv_1236.data.dl4;
                            return sriqnames_dl4_cmp(x, y);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case types_DlClause_dl5:
                {
                    __auto_type n1 = _mv_1232.data.dl5.f0;
                    __auto_type s1 = _mv_1232.data.dl5.f1;
                    __auto_type _mv_1237 = b;
                    switch (_mv_1237.tag) {
                        case types_DlClause_dl5:
                        {
                            __auto_type n2 = _mv_1237.data.dl5.f0;
                            __auto_type s2 = _mv_1237.data.dl5.f1;
                            return sriqnames_then_cmp(sriqnames_dname_cmp(n1, n2), sriqnames_drole_cmp(s1, s2));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case types_DlClause_dl6:
                {
                    __auto_type s1 = _mv_1232.data.dl6.f0;
                    __auto_type n1 = _mv_1232.data.dl6.f1;
                    __auto_type _mv_1238 = b;
                    switch (_mv_1238.tag) {
                        case types_DlClause_dl6:
                        {
                            __auto_type s2 = _mv_1238.data.dl6.f0;
                            __auto_type n2 = _mv_1238.data.dl6.f1;
                            return sriqnames_then_cmp(sriqnames_drole_cmp(s1, s2), sriqnames_dname_cmp(n1, n2));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case types_DlClause_dl7:
                {
                    __auto_type a1 = _mv_1232.data.dl7.f0;
                    __auto_type b1 = _mv_1232.data.dl7.f1;
                    __auto_type _mv_1239 = b;
                    switch (_mv_1239.tag) {
                        case types_DlClause_dl7:
                        {
                            __auto_type a2 = _mv_1239.data.dl7.f0;
                            __auto_type b2 = _mv_1239.data.dl7.f1;
                            return sriqnames_roles_cmp(a1, b1, a2, b2);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case types_DlClause_dl8:
                {
                    __auto_type a1 = _mv_1232.data.dl8.f0;
                    __auto_type b1 = _mv_1232.data.dl8.f1;
                    __auto_type _mv_1240 = b;
                    switch (_mv_1240.tag) {
                        case types_DlClause_dl8:
                        {
                            __auto_type a2 = _mv_1240.data.dl8.f0;
                            __auto_type b2 = _mv_1240.data.dl8.f1;
                            return sriqnames_roles_cmp(a1, b1, a2, b2);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case types_DlClause_dl9:
                {
                    __auto_type a1 = _mv_1232.data.dl9.f0;
                    __auto_type b1 = _mv_1232.data.dl9.f1;
                    __auto_type _mv_1241 = b;
                    switch (_mv_1241.tag) {
                        case types_DlClause_dl9:
                        {
                            __auto_type a2 = _mv_1241.data.dl9.f0;
                            __auto_type b2 = _mv_1241.data.dl9.f1;
                            return sriqnames_roles_cmp(a1, b1, a2, b2);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case types_DlClause_dl10:
                {
                    __auto_type o1 = _mv_1232.data.dl10.f0;
                    __auto_type n1 = _mv_1232.data.dl10.f1;
                    __auto_type _mv_1242 = b;
                    switch (_mv_1242.tag) {
                        case types_DlClause_dl10:
                        {
                            __auto_type o2 = _mv_1242.data.dl10.f0;
                            __auto_type n2 = _mv_1242.data.dl10.f1;
                            return sriqnames_then_cmp(canon_iri_cmp(o1, o2), sriqnames_dname_cmp(n1, n2));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case types_DlClause_dl11:
                {
                    __auto_type n1 = _mv_1232.data.dl11.f0;
                    __auto_type o1 = _mv_1232.data.dl11.f1;
                    __auto_type _mv_1243 = b;
                    switch (_mv_1243.tag) {
                        case types_DlClause_dl11:
                        {
                            __auto_type n2 = _mv_1243.data.dl11.f0;
                            __auto_type o2 = _mv_1243.data.dl11.f1;
                            return sriqnames_then_cmp(sriqnames_dname_cmp(n1, n2), canon_iri_cmp(o1, o2));
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

types_DName sriqnames_rename_name(slop_list_int fresh, types_DName n) {
    __auto_type _mv_1244 = n;
    switch (_mv_1244.tag) {
        case types_DName_dn_class:
        {
            __auto_type _ = _mv_1244.data.dn_class;
            return n;
        }
        case types_DName_dn_fresh:
        {
            __auto_type k = _mv_1244.data.dn_fresh;
            return ((types_DName){ .tag = types_DName_dn_fresh, .data.dn_fresh = ((int64_t)(SLOP_RANGE(int64_t, sriqnames_int_at(fresh, ((int64_t)(k))), 1, 0, 0, 0, "(Int 0 ..) at sriqnames.slop:205:64"))) });
        }
    }
    SLOP_UNREACHABLE();
}

slop_option_types_DName sriqnames_rename_filler(slop_list_int fresh, slop_option_types_DName b) {
    __auto_type _mv_1245 = b;
    if (!_mv_1245.has_value) {
        return b;
    } else if (_mv_1245.has_value) {
        __auto_type n = _mv_1245.value;
        return (slop_option_types_DName){.has_value = 1, .value = sriqnames_rename_name(fresh, n)};
    }
    SLOP_UNREACHABLE();
}

types_DRole sriqnames_rename_role(slop_list_int subs, types_DRole r) {
    __auto_type _mv_1246 = r;
    switch (_mv_1246.tag) {
        case types_DRole_dr_sub:
        {
            __auto_type k = _mv_1246.data.dr_sub;
            return ((types_DRole){ .tag = types_DRole_dr_sub, .data.dr_sub = ((int64_t)(SLOP_RANGE(int64_t, sriqnames_int_at(subs, ((int64_t)(k))), 1, 0, 0, 0, "(Int 0 ..) at sriqnames.slop:218:60"))) });
        }
        default: {
            return r;
        }
    }
}

slop_list_types_DName sriqnames_sort_dnames(slop_arena* arena, slop_list_types_DName xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ sriqnames__lambda_1247_env_t* sriqnames__lambda_1247_env = (sriqnames__lambda_1247_env_t*)slop_arena_alloc(arena, sizeof(sriqnames__lambda_1247_env_t)); *sriqnames__lambda_1247_env = (sriqnames__lambda_1247_env_t){ .xs = xs }; (slop_closure_t){ (void*)sriqnames__lambda_1247, (void*)sriqnames__lambda_1247_env }; }));
        __auto_type out = ((slop_list_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t have = 0;
        __auto_type last = ((types_DName){ .tag = types_DName_dn_fresh, .data.dn_fresh = 0 });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type n = sriqnames_dname_at(xs, k);
                    if (!(have) || (sriqnames_dname_cmp(n, last) != 0)) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        last = n;
                        have = 1;
                    }
                }
            }
        }
        return out;
    }
}

types_DName sriqnames_dname_at(slop_list_types_DName xs, int64_t i) {
    __auto_type _mv_1248 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_DName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1248.has_value) {
        __auto_type v = _mv_1248.value;
        return v;
    } else if (!_mv_1248.has_value) {
        return ((types_DName){ .tag = types_DName_dn_fresh, .data.dn_fresh = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_list_types_DName sriqnames_rename_names(slop_arena* arena, slop_list_int fresh, slop_list_types_DName ns) {
    {
        __auto_type out = ((slop_list_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnames_rename_name(fresh, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

types_DlClause sriqnames_rename_clause(slop_arena* arena, slop_list_int fresh, slop_list_int subs, types_DlClause c) {
    __auto_type _mv_1249 = c;
    switch (_mv_1249.tag) {
        case types_DlClause_dl1:
        {
            __auto_type d = _mv_1249.data.dl1;
            return ((types_DlClause){ .tag = types_DlClause_dl1, .data.dl1 = ((types_Dl1){.body = sriqnames_sort_dnames(arena, sriqnames_rename_names(arena, fresh, d.body)), .head = sriqnames_sort_dnames(arena, sriqnames_rename_names(arena, fresh, d.head))}) });
        }
        case types_DlClause_dl2:
        {
            __auto_type d = _mv_1249.data.dl2;
            return ((types_DlClause){ .tag = types_DlClause_dl2, .data.dl2 = ((types_Dl2){.sub = sriqnames_rename_name(fresh, d.sub), .role = sriqnames_rename_role(subs, d.role), .count = d.count, .filler = sriqnames_rename_filler(fresh, d.filler), .fns = d.fns}) });
        }
        case types_DlClause_dl3:
        {
            __auto_type s = _mv_1249.data.dl3.f0;
            __auto_type b1 = _mv_1249.data.dl3.f1;
            __auto_type b2 = _mv_1249.data.dl3.f2;
            return ((types_DlClause){ .tag = types_DlClause_dl3, .data.dl3 = { .f0 = sriqnames_rename_role(subs, s), .f1 = sriqnames_rename_name(fresh, b1), .f2 = sriqnames_rename_name(fresh, b2) } });
        }
        case types_DlClause_dl4:
        {
            __auto_type d = _mv_1249.data.dl4;
            return ((types_DlClause){ .tag = types_DlClause_dl4, .data.dl4 = ((types_Dl4){.sub = sriqnames_rename_name(fresh, d.sub), .role = sriqnames_rename_role(subs, d.role), .count = d.count, .filler = sriqnames_rename_filler(fresh, d.filler), .srole = sriqnames_rename_role(subs, d.srole)}) });
        }
        case types_DlClause_dl5:
        {
            __auto_type b = _mv_1249.data.dl5.f0;
            __auto_type s = _mv_1249.data.dl5.f1;
            return ((types_DlClause){ .tag = types_DlClause_dl5, .data.dl5 = { .f0 = sriqnames_rename_name(fresh, b), .f1 = sriqnames_rename_role(subs, s) } });
        }
        case types_DlClause_dl6:
        {
            __auto_type s = _mv_1249.data.dl6.f0;
            __auto_type b = _mv_1249.data.dl6.f1;
            return ((types_DlClause){ .tag = types_DlClause_dl6, .data.dl6 = { .f0 = sriqnames_rename_role(subs, s), .f1 = sriqnames_rename_name(fresh, b) } });
        }
        case types_DlClause_dl7:
        {
            __auto_type a = _mv_1249.data.dl7.f0;
            __auto_type b = _mv_1249.data.dl7.f1;
            return ((types_DlClause){ .tag = types_DlClause_dl7, .data.dl7 = { .f0 = sriqnames_rename_role(subs, a), .f1 = sriqnames_rename_role(subs, b) } });
        }
        case types_DlClause_dl8:
        {
            __auto_type a = _mv_1249.data.dl8.f0;
            __auto_type b = _mv_1249.data.dl8.f1;
            return ((types_DlClause){ .tag = types_DlClause_dl8, .data.dl8 = { .f0 = sriqnames_rename_role(subs, a), .f1 = sriqnames_rename_role(subs, b) } });
        }
        case types_DlClause_dl9:
        {
            __auto_type a = _mv_1249.data.dl9.f0;
            __auto_type b = _mv_1249.data.dl9.f1;
            return ((types_DlClause){ .tag = types_DlClause_dl9, .data.dl9 = { .f0 = sriqnames_rename_role(subs, a), .f1 = sriqnames_rename_role(subs, b) } });
        }
        case types_DlClause_dl10:
        {
            __auto_type o = _mv_1249.data.dl10.f0;
            __auto_type b = _mv_1249.data.dl10.f1;
            return ((types_DlClause){ .tag = types_DlClause_dl10, .data.dl10 = { .f0 = o, .f1 = sriqnames_rename_name(fresh, b) } });
        }
        case types_DlClause_dl11:
        {
            __auto_type b = _mv_1249.data.dl11.f0;
            __auto_type o = _mv_1249.data.dl11.f1;
            return ((types_DlClause){ .tag = types_DlClause_dl11, .data.dl11 = { .f0 = sriqnames_rename_name(fresh, b), .f1 = o } });
        }
    }
    SLOP_UNREACHABLE();
}

types_DlClause sriqnames_clause_at(slop_list_types_DlClause xs, int64_t i) {
    __auto_type _mv_1250 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_DlClause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1250.has_value) {
        __auto_type v = _mv_1250.value;
        return v;
    } else if (!_mv_1250.has_value) {
        return ((types_DlClause){ .tag = types_DlClause_dl7, .data.dl7 = { .f0 = ((types_DRole){ .tag = types_DRole_dr_sub, .data.dr_sub = 0 }), .f1 = ((types_DRole){ .tag = types_DRole_dr_sub, .data.dr_sub = 0 }) } });
    }
    SLOP_UNREACHABLE();
}

types_DlClause sriqnames_renumber_fns(slop_arena* arena, types_DlClause c, int64_t next) {
    __auto_type _mv_1251 = c;
    switch (_mv_1251.tag) {
        case types_DlClause_dl2:
        {
            __auto_type d = _mv_1251.data.dl2;
            {
                __auto_type fs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                int64_t i = 0;
                while (i < ((int64_t)(((int64_t)((d.fns).len))))) {
                    ({ __auto_type _lst_p = &(fs); __auto_type _item = (((int64_t)(SLOP_RANGE(int64_t, (next + i), 1, 0, 0, 0, "(Int 0 ..) at sriqnames.slop:295:50")))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    i = (i + 1);
                }
                return ((types_DlClause){ .tag = types_DlClause_dl2, .data.dl2 = ((types_Dl2){.sub = d.sub, .role = d.role, .count = d.count, .filler = d.filler, .fns = fs}) });
            }
        }
        default: {
            return c;
        }
    }
}

int64_t sriqnames_fn_count(types_DlClause c) {
    __auto_type _mv_1252 = c;
    switch (_mv_1252.tag) {
        case types_DlClause_dl2:
        {
            __auto_type d = _mv_1252.data.dl2;
            return ((int64_t)(((int64_t)((d.fns).len))));
        }
        default: {
            return 0;
        }
    }
}

slop_list_int sriqnames_rank_of(slop_arena* arena, slop_list_int order) {
    {
        __auto_type rank = sriqnames_ints_new(arena, ((int64_t)(((int64_t)((order).len)))), 0);
        int64_t k = 0;
        {
            __auto_type _coll = order;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type old = _coll.data[_i];
                ({ __auto_type _set_lst = &(rank); size_t _set_idx = (size_t)(old); __auto_type _set_val = (k); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
                k = (k + 1);
            }
        }
        return rank;
    }
}

slop_list_int sriqnames_concept_order(slop_arena* arena, slop_list_sroiq_SConcept cs) {
    return canon_sort_range(arena, ((int64_t)(((int64_t)((cs).len)))), ({ sriqnames__lambda_1253_env_t* sriqnames__lambda_1253_env = (sriqnames__lambda_1253_env_t*)slop_arena_alloc(arena, sizeof(sriqnames__lambda_1253_env_t)); *sriqnames__lambda_1253_env = (sriqnames__lambda_1253_env_t){ .cs = cs }; (slop_closure_t){ (void*)sriqnames__lambda_1253, (void*)sriqnames__lambda_1253_env }; }));
}

slop_list_int sriqnames_srole_order(slop_arena* arena, slop_list_types_DRole roles, slop_list_option_types_DName fills) {
    return canon_sort_range(arena, ((int64_t)(((int64_t)((roles).len)))), ({ sriqnames__lambda_1254_env_t* sriqnames__lambda_1254_env = (sriqnames__lambda_1254_env_t*)slop_arena_alloc(arena, sizeof(sriqnames__lambda_1254_env_t)); *sriqnames__lambda_1254_env = (sriqnames__lambda_1254_env_t){ .roles = roles, .fills = fills }; (slop_closure_t){ (void*)sriqnames__lambda_1254, (void*)sriqnames__lambda_1254_env }; }));
}

slop_list_sroiq_SConcept sriqnames_pick_concepts(slop_arena* arena, slop_list_sroiq_SConcept cs, slop_list_int order) {
    {
        __auto_type out = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = order;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnames_sc_at_n(cs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_DRole sriqnames_pick_roles(slop_arena* arena, slop_list_types_DRole rs, slop_list_int order) {
    {
        __auto_type out = ((slop_list_types_DRole){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = order;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnames_role_at(rs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_option_types_DName sriqnames_pick_fills(slop_arena* arena, slop_list_option_types_DName bs, slop_list_int order) {
    {
        __auto_type out = ((slop_list_option_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = order;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnames_fill_at(bs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_option_types_DName sriqnames_rename_fills(slop_arena* arena, slop_list_int fresh, slop_list_option_types_DName bs) {
    {
        __auto_type out = ((slop_list_option_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = bs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnames_rename_filler(fresh, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_DlClause sriqnames_rename_clauses(slop_arena* arena, slop_list_int fresh, slop_list_int subs, slop_list_types_DlClause cs) {
    {
        __auto_type out = ((slop_list_types_DlClause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnames_rename_clause(arena, fresh, subs, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_types_DlClause sriqnames_canonical_clauses(slop_arena* arena, slop_list_types_DlClause cs) {
    {
        __auto_type order = canon_sort_range(arena, ((int64_t)(((int64_t)((cs).len)))), ({ sriqnames__lambda_1255_env_t* sriqnames__lambda_1255_env = (sriqnames__lambda_1255_env_t*)slop_arena_alloc(arena, sizeof(sriqnames__lambda_1255_env_t)); *sriqnames__lambda_1255_env = (sriqnames__lambda_1255_env_t){ .cs = cs }; (slop_closure_t){ (void*)sriqnames__lambda_1255, (void*)sriqnames__lambda_1255_env }; }));
        __auto_type out = ((slop_list_types_DlClause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t next = 0;
        {
            __auto_type _coll = order;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type c = sriqnames_clause_at(cs, k);
                    __auto_type n = ((int64_t)(((int64_t)((out).len))));
                    if ((n == 0) || (sriqnames_dl_cmp(c, sriqnames_clause_at(out, (n - 1))) != 0)) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnames_renumber_fns(arena, c, next)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        next = (next + sriqnames_fn_count(c));
                    }
                }
            }
        }
        return out;
    }
}

int64_t sriqnames_fn_total(slop_list_types_DlClause cs) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                n = (n + sriqnames_fn_count(c));
            }
        }
        return n;
    }
}

slop_list_rdf_IRI sriqnames_input_classes(slop_arena* arena, owl2_Signature sig) {
    {
        __auto_type out = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.classes); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!((string_eq(c.value, vocab_OWL_THING) || string_eq(c.value, vocab_OWL_NOTHING)))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return canon_sort_iris(arena, out);
    }
}

slop_list_rdf_IRI sriqnames_input_individuals(slop_arena* arena, owl2_Signature sig) {
    {
        __auto_type out = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.individuals); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return canon_sort_iris(arena, out);
    }
}

sriqnames_SriqNormal sriqnames_sriq_names(slop_arena* arena, sriqnormal_S2 s2, owl2_Signature sig, slop_list_owl2_RawAxiom omitted) {
    {
        __auto_type forder = sriqnames_concept_order(arena, s2.concepts);
        __auto_type fresh = sriqnames_rank_of(arena, forder);
        __auto_type fills = sriqnames_rename_fills(arena, fresh, s2.sfills);
        __auto_type sorder = sriqnames_srole_order(arena, s2.sroles, fills);
        __auto_type subs = sriqnames_rank_of(arena, sorder);
        __auto_type clauses = sriqnames_canonical_clauses(arena, sriqnames_rename_clauses(arena, fresh, subs, s2.clauses));
        return ((sriqnames_SriqNormal){.clauses = clauses, .concepts = sriqnames_pick_concepts(arena, s2.concepts, forder), .sroles = sriqnames_pick_roles(arena, s2.sroles, sorder), .sfills = sriqnames_pick_fills(arena, fills, sorder), .bars = canon_sort_iris(arena, s2.bars), .fns = ((int64_t)(SLOP_RANGE(int64_t, sriqnames_fn_total(clauses), 1, 0, 0, 0, "(Int 0 ..) at sriqnames.slop:432:39"))), .classes = sriqnames_input_classes(arena, sig), .individuals = sriqnames_input_individuals(arena, sig), .omitted = omitted});
    }
}

types_DRole sriqnames_role_at(slop_list_types_DRole xs, int64_t i) {
    __auto_type _mv_1256 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_DRole _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1256.has_value) {
        __auto_type v = _mv_1256.value;
        return v;
    } else if (!_mv_1256.has_value) {
        return ((types_DRole){ .tag = types_DRole_dr_sub, .data.dr_sub = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_option_types_DName sriqnames_fill_at(slop_list_option_types_DName xs, int64_t i) {
    __auto_type _mv_1257 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_option_types_DName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1257.has_value) {
        __auto_type v = _mv_1257.value;
        return v;
    } else if (!_mv_1257.has_value) {
        return (slop_option_types_DName){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

slop_list_owl2_RawAxiom sriqnames_guard_witnesses(slop_arena* arena, slop_list_owl2_RawAxiom accepted, sriqelim_S1 s1) {
    {
        __auto_type out = ((slop_list_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (((int64_t)((s1.omitted).len)) > 0) {
            {
                __auto_type _coll = accepted;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    __auto_type _mv_1258 = a;
                    switch (_mv_1258.tag) {
                        case owl2_RawAxiom_ra_property_chain:
                        {
                            __auto_type ch = _mv_1258.data.ra_property_chain;
                            if (((int64_t)((ch.steps).len)) > 1) {
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                }
            }
        }
        return out;
    }
}

slop_result_sriqnames_SriqNormal_string sriqnames_normalize_after_s1(slop_arena* arena, slop_list_owl2_RawAxiom accepted, sriqelim_S1 s1, owl2_Signature sig) {
    __auto_type _mv_1259 = sriqnormal_sriq_s2(arena, s1.axioms);
    if (!_mv_1259.is_ok) {
        __auto_type m = _mv_1259.data.err;
        return ((slop_result_sriqnames_SriqNormal_string){ .is_ok = false, .data.err = m });
    } else if (_mv_1259.is_ok) {
        __auto_type s2 = _mv_1259.data.ok;
        return ((slop_result_sriqnames_SriqNormal_string){ .is_ok = true, .data.ok = sriqnames_sriq_names(arena, s2, sig, sriqnames_guard_witnesses(arena, accepted, s1)) });
    }
    SLOP_UNREACHABLE();
}

slop_result_sriqnames_SriqNormal_string sriqnames_normalize_after_s0(slop_arena* arena, slop_list_owl2_RawAxiom accepted, sriqnormal_S0 s0, owl2_Signature sig, int64_t bound) {
    __auto_type _mv_1260 = sriqelim_sriq_s1(arena, s0, bound);
    if (!_mv_1260.is_ok) {
        __auto_type m = _mv_1260.data.err;
        return ((slop_result_sriqnames_SriqNormal_string){ .is_ok = false, .data.err = m });
    } else if (_mv_1260.is_ok) {
        __auto_type s1 = _mv_1260.data.ok;
        return sriqnames_normalize_after_s1(arena, accepted, s1, sig);
    }
    SLOP_UNREACHABLE();
}

slop_result_sriqnames_SriqNormal_string sriqnames_sriq_normalize_bounded(slop_arena* arena, slop_list_owl2_RawAxiom accepted, owl2_Signature sig, int64_t bound) {
    __auto_type _mv_1261 = sriqnormal_sriq_s0(arena, accepted);
    if (!_mv_1261.is_ok) {
        __auto_type m = _mv_1261.data.err;
        return ((slop_result_sriqnames_SriqNormal_string){ .is_ok = false, .data.err = m });
    } else if (_mv_1261.is_ok) {
        __auto_type s0 = _mv_1261.data.ok;
        return sriqnames_normalize_after_s0(arena, accepted, s0, sig, bound);
    }
    SLOP_UNREACHABLE();
}

slop_result_sriqnames_SriqNormal_string sriqnames_sriq_normalize(slop_arena* arena, slop_list_owl2_RawAxiom accepted, owl2_Signature sig) {
    return sriqnames_sriq_normalize_bounded(arena, accepted, sig, sriqelim_S1_BOUND);
}

slop_string sriqnames_rn(slop_arena* arena, types_DName n) {
    __auto_type _mv_1262 = n;
    switch (_mv_1262.tag) {
        case types_DName_dn_class:
        {
            __auto_type i = _mv_1262.data.dn_class;
            return i.value;
        }
        case types_DName_dn_fresh:
        {
            __auto_type k = _mv_1262.data.dn_fresh;
            return string_concat(arena, SLOP_STR("A"), int_to_string(arena, k));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string sriqnames_rr(slop_arena* arena, types_DRole r) {
    __auto_type _mv_1263 = r;
    switch (_mv_1263.tag) {
        case types_DRole_dr_prop:
        {
            __auto_type i = _mv_1263.data.dr_prop;
            return i.value;
        }
        case types_DRole_dr_bar:
        {
            __auto_type i = _mv_1263.data.dr_bar;
            return string_concat(arena, i.value, SLOP_STR("^bar"));
        }
        case types_DRole_dr_sub:
        {
            __auto_type k = _mv_1263.data.dr_sub;
            return string_concat(arena, SLOP_STR("S"), int_to_string(arena, k));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string sriqnames_rf(slop_arena* arena, slop_option_types_DName b) {
    __auto_type _mv_1264 = b;
    if (!_mv_1264.has_value) {
        return SLOP_STR("T");
    } else if (_mv_1264.has_value) {
        __auto_type n = _mv_1264.value;
        return sriqnames_rn(arena, n);
    }
    SLOP_UNREACHABLE();
}

slop_string sriqnames_rns(slop_arena* arena, slop_list_types_DName ns) {
    {
        __auto_type out = SLOP_STR("");
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                out = string_concat(arena, out, string_concat(arena, SLOP_STR(" "), sriqnames_rn(arena, n)));
            }
        }
        return out;
    }
}

slop_string sriqnames_rints(slop_arena* arena, slop_list_int xs) {
    {
        __auto_type out = SLOP_STR("");
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                out = string_concat(arena, out, string_concat(arena, SLOP_STR(" f"), int_to_string(arena, x)));
            }
        }
        return out;
    }
}

slop_string sriqnames_j(slop_arena* arena, slop_list_string parts) {
    {
        __auto_type out = SLOP_STR("");
        uint8_t first = 1;
        {
            __auto_type _coll = parts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                if (!(first)) {
                    out = string_concat(arena, out, SLOP_STR("|"));
                }
                out = string_concat(arena, out, s);
                first = 0;
            }
        }
        return out;
    }
}

slop_string sriqnames_render_dl_ids(slop_arena* arena, types_DlClause c) {
    {
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1265 = c;
        switch (_mv_1265.tag) {
            case types_DlClause_dl1:
            {
                __auto_type d = _mv_1265.data.dl1;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL1")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rns(arena, d.body)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rns(arena, d.head)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_DlClause_dl2:
            {
                __auto_type d = _mv_1265.data.dl2;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL2")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rn(arena, d.sub)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rr(arena, d.role)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (int_to_string(arena, d.count)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rf(arena, d.filler)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rints(arena, d.fns)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_DlClause_dl3:
            {
                __auto_type s = _mv_1265.data.dl3.f0;
                __auto_type a = _mv_1265.data.dl3.f1;
                __auto_type b = _mv_1265.data.dl3.f2;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL3")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rr(arena, s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rn(arena, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rn(arena, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_DlClause_dl4:
            {
                __auto_type d = _mv_1265.data.dl4;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL4")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rn(arena, d.sub)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rr(arena, d.role)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (int_to_string(arena, d.count)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rf(arena, d.filler)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rr(arena, d.srole)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_DlClause_dl5:
            {
                __auto_type b = _mv_1265.data.dl5.f0;
                __auto_type s = _mv_1265.data.dl5.f1;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL5")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rn(arena, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rr(arena, s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_DlClause_dl6:
            {
                __auto_type s = _mv_1265.data.dl6.f0;
                __auto_type b = _mv_1265.data.dl6.f1;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL6")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rr(arena, s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rn(arena, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_DlClause_dl7:
            {
                __auto_type a = _mv_1265.data.dl7.f0;
                __auto_type b = _mv_1265.data.dl7.f1;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL7")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rr(arena, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rr(arena, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_DlClause_dl8:
            {
                __auto_type a = _mv_1265.data.dl8.f0;
                __auto_type b = _mv_1265.data.dl8.f1;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL8")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rr(arena, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rr(arena, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_DlClause_dl9:
            {
                __auto_type a = _mv_1265.data.dl9.f0;
                __auto_type b = _mv_1265.data.dl9.f1;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL9")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rr(arena, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rr(arena, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_DlClause_dl10:
            {
                __auto_type o = _mv_1265.data.dl10.f0;
                __auto_type b = _mv_1265.data.dl10.f1;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL10")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (o.value); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rn(arena, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case types_DlClause_dl11:
            {
                __auto_type b = _mv_1265.data.dl11.f0;
                __auto_type o = _mv_1265.data.dl11.f1;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL11")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (sriqnames_rn(arena, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (o.value); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
        }
        return sriqnames_j(arena, ps);
    }
}

slop_string sriqnames_table_line(slop_arena* arena, slop_string prefix, int64_t k, slop_string text) {
    return string_concat(arena, prefix, string_concat(arena, int_to_string(arena, k), string_concat(arena, SLOP_STR(" = "), text)));
}

slop_list_string sriqnames_prefixed(slop_arena* arena, slop_string prefix, slop_list_rdf_IRI is) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = is;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (string_concat(arena, prefix, i.value)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_string sriqnames_render_sriq_normal(slop_arena* arena, sriqnames_SriqNormal n) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = n.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnames_render_dl_ids(arena, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = n.concepts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnames_table_line(arena, SLOP_STR("A"), k, sroiq_render_sconcept(arena, c))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                k = (k + 1);
            }
        }
        k = 0;
        {
            __auto_type _coll = n.sroles;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                {
                    __auto_type b = sriqnames_fill_at(n.sfills, k);
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqnames_table_line(arena, SLOP_STR("S"), k, string_concat(arena, sriqnames_rr(arena, r), string_concat(arena, SLOP_STR(" "), sriqnames_rf(arena, b))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    k = (k + 1);
                }
            }
        }
        {
            __auto_type _coll = sriqnames_prefixed(arena, SLOP_STR("bar "), n.bars);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        ({ __auto_type _lst_p = &(out); __auto_type _item = (string_concat(arena, SLOP_STR("fns "), int_to_string(arena, n.fns))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = sriqnames_prefixed(arena, SLOP_STR("class "), n.classes);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqnames_prefixed(arena, SLOP_STR("individual "), n.individuals);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = n.omitted;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (string_concat(arena, SLOP_STR("omitted "), owl2_render_axiom(arena, a))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

uint8_t sriqnames_name_in_range(types_DName n, int64_t nc) {
    __auto_type _mv_1266 = n;
    switch (_mv_1266.tag) {
        case types_DName_dn_class:
        {
            __auto_type _ = _mv_1266.data.dn_class;
            return 1;
        }
        case types_DName_dn_fresh:
        {
            __auto_type k = _mv_1266.data.dn_fresh;
            return (((int64_t)(k)) < nc);
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqnames_names_in_range(slop_list_types_DName ns, int64_t nc) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                if (!(sriqnames_name_in_range(n, nc))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t sriqnames_filler_in_range(slop_option_types_DName b, int64_t nc) {
    __auto_type _mv_1267 = b;
    if (!_mv_1267.has_value) {
        return 1;
    } else if (_mv_1267.has_value) {
        __auto_type n = _mv_1267.value;
        return sriqnames_name_in_range(n, nc);
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqnames_role_in_range(types_DRole r, int64_t ns) {
    __auto_type _mv_1268 = r;
    switch (_mv_1268.tag) {
        case types_DRole_dr_sub:
        {
            __auto_type k = _mv_1268.data.dr_sub;
            return (((int64_t)(k)) < ns);
        }
        default: {
            return 1;
        }
    }
}

uint8_t sriqnames_clause_in_range(types_DlClause c, int64_t nc, int64_t ns) {
    __auto_type _mv_1269 = c;
    switch (_mv_1269.tag) {
        case types_DlClause_dl1:
        {
            __auto_type d = _mv_1269.data.dl1;
            return (sriqnames_names_in_range(d.body, nc) && sriqnames_names_in_range(d.head, nc));
        }
        case types_DlClause_dl2:
        {
            __auto_type d = _mv_1269.data.dl2;
            return ((sriqnames_name_in_range(d.sub, nc)) && (sriqnames_role_in_range(d.role, ns)) && (sriqnames_filler_in_range(d.filler, nc)));
        }
        case types_DlClause_dl3:
        {
            __auto_type r = _mv_1269.data.dl3.f0;
            __auto_type a = _mv_1269.data.dl3.f1;
            __auto_type b = _mv_1269.data.dl3.f2;
            return ((sriqnames_role_in_range(r, ns)) && (sriqnames_name_in_range(a, nc)) && (sriqnames_name_in_range(b, nc)));
        }
        case types_DlClause_dl4:
        {
            __auto_type d = _mv_1269.data.dl4;
            return ((sriqnames_name_in_range(d.sub, nc)) && (sriqnames_role_in_range(d.role, ns)) && (sriqnames_filler_in_range(d.filler, nc)) && (sriqnames_role_in_range(d.srole, ns)));
        }
        case types_DlClause_dl5:
        {
            __auto_type b = _mv_1269.data.dl5.f0;
            __auto_type r = _mv_1269.data.dl5.f1;
            return (sriqnames_name_in_range(b, nc) && sriqnames_role_in_range(r, ns));
        }
        case types_DlClause_dl6:
        {
            __auto_type r = _mv_1269.data.dl6.f0;
            __auto_type b = _mv_1269.data.dl6.f1;
            return (sriqnames_role_in_range(r, ns) && sriqnames_name_in_range(b, nc));
        }
        case types_DlClause_dl7:
        {
            __auto_type a = _mv_1269.data.dl7.f0;
            __auto_type b = _mv_1269.data.dl7.f1;
            return (sriqnames_role_in_range(a, ns) && sriqnames_role_in_range(b, ns));
        }
        case types_DlClause_dl8:
        {
            __auto_type a = _mv_1269.data.dl8.f0;
            __auto_type b = _mv_1269.data.dl8.f1;
            return (sriqnames_role_in_range(a, ns) && sriqnames_role_in_range(b, ns));
        }
        case types_DlClause_dl9:
        {
            __auto_type a = _mv_1269.data.dl9.f0;
            __auto_type b = _mv_1269.data.dl9.f1;
            return (sriqnames_role_in_range(a, ns) && sriqnames_role_in_range(b, ns));
        }
        case types_DlClause_dl10:
        {
            __auto_type b = _mv_1269.data.dl10.f1;
            return sriqnames_name_in_range(b, nc);
        }
        case types_DlClause_dl11:
        {
            __auto_type b = _mv_1269.data.dl11.f0;
            return sriqnames_name_in_range(b, nc);
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_string sriqnames_concepts_ordered(slop_arena* arena, slop_list_sroiq_SConcept cs) {
    {
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 1;
        while (i < ((int64_t)(((int64_t)((cs).len))))) {
            if (sroiq_sc_cmp(sriqnames_sc_at_n(cs, (i - 1)), sriqnames_sc_at_n(cs, i)) >= 0) {
                ({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("A ids out of key order at "), int_to_string(arena, i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
            i = (i + 1);
        }
        return bad;
    }
}

slop_list_string sriqnames_sroles_ordered(slop_arena* arena, slop_list_types_DRole rs, slop_list_option_types_DName bs) {
    {
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 1;
        while (i < ((int64_t)(((int64_t)((rs).len))))) {
            if (sriqnames_then_cmp(sriqnames_drole_cmp(sriqnames_role_at(rs, (i - 1)), sriqnames_role_at(rs, i)), sriqnames_filler_cmp(sriqnames_fill_at(bs, (i - 1)), sriqnames_fill_at(bs, i))) >= 0) {
                ({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("S ids out of key order at "), int_to_string(arena, i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
            i = (i + 1);
        }
        return bad;
    }
}

slop_list_string sriqnames_clauses_ordered(slop_arena* arena, slop_list_types_DlClause cs) {
    {
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 1;
        while (i < ((int64_t)(((int64_t)((cs).len))))) {
            if (sriqnames_dl_cmp(sriqnames_clause_at(cs, (i - 1)), sriqnames_clause_at(cs, i)) >= 0) {
                ({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("clauses out of order at "), int_to_string(arena, i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
            i = (i + 1);
        }
        return bad;
    }
}

slop_list_string sriqnames_ids_in_range(slop_arena* arena, sriqnames_SriqNormal n) {
    {
        __auto_type nc = ((int64_t)(((int64_t)((n.concepts).len))));
        __auto_type ns = ((int64_t)(((int64_t)((n.sroles).len))));
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = n.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(sriqnames_clause_in_range(c, nc, ns))) {
                    ({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("an id out of range: "), sriqnames_render_dl_ids(arena, c))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return bad;
    }
}

uint8_t sriqnames_witness_count_ok(types_DlClause c) {
    __auto_type _mv_1270 = c;
    switch (_mv_1270.tag) {
        case types_DlClause_dl2:
        {
            __auto_type d = _mv_1270.data.dl2;
            return (((int64_t)(((int64_t)((d.fns).len)))) == ((int64_t)(d.count)));
        }
        default: {
            return 1;
        }
    }
}

slop_list_int sriqnames_clause_fns(slop_arena* arena, types_DlClause c) {
    __auto_type _mv_1271 = c;
    switch (_mv_1271.tag) {
        case types_DlClause_dl2:
        {
            __auto_type d = _mv_1271.data.dl2;
            return d.fns;
        }
        default: {
            return ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        }
    }
}

slop_list_string sriqnames_fns_dense(slop_arena* arena, sriqnames_SriqNormal n) {
    {
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t next = 0;
        {
            __auto_type _coll = n.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(sriqnames_witness_count_ok(c))) {
                    ({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("a DL2 without one function symbol per witness: "), sriqnames_render_dl_ids(arena, c))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                {
                    __auto_type _coll = sriqnames_clause_fns(arena, c);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type f = _coll.data[_i];
                        if (((int64_t)(f)) != next) {
                            ({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("function symbols not dense: "), sriqnames_render_dl_ids(arena, c))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        next = (next + 1);
                    }
                }
            }
        }
        if (next != ((int64_t)(n.fns))) {
            ({ __auto_type _lst_p = &(bad); __auto_type _item = (SLOP_STR("the function symbol count disagrees with the clauses")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return bad;
    }
}

slop_list_string sriqnames_fresh_not_signature(slop_arena* arena, sriqnames_SriqNormal n) {
    {
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = n.concepts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                __auto_type _mv_1272 = c;
                switch (_mv_1272.tag) {
                    case sroiq_SConcept_sc_name:
                    {
                        __auto_type _ = _mv_1272.data.sc_name;
                        ({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("a fresh name for a class name: "), sroiq_render_sconcept(arena, c))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case sroiq_SConcept_sc_top:
                    {
                        ({ __auto_type _lst_p = &(bad); __auto_type _item = (SLOP_STR("a fresh name for ⊤")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        return bad;
    }
}

slop_list_string sriqnames_sriq_invariants(slop_arena* arena, sriqnames_SriqNormal n) {
    {
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = sriqnames_concepts_ordered(arena, n.concepts);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                ({ __auto_type _lst_p = &(bad); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqnames_sroles_ordered(arena, n.sroles, n.sfills);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                ({ __auto_type _lst_p = &(bad); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqnames_clauses_ordered(arena, n.clauses);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                ({ __auto_type _lst_p = &(bad); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqnames_ids_in_range(arena, n);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                ({ __auto_type _lst_p = &(bad); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqnames_fns_dense(arena, n);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                ({ __auto_type _lst_p = &(bad); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = sriqnames_fresh_not_signature(arena, n);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                ({ __auto_type _lst_p = &(bad); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return bad;
    }
}

