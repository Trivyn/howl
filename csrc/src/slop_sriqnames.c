#include "../runtime/slop_runtime.h"
#include "slop_sriqnames.h"

int64_t howl_sriqnames_int_at(slop_list_int xs, int64_t i);
slop_list_int howl_sriqnames_ints_new(slop_arena* arena, int64_t n, int64_t v);
int64_t howl_sriqnames_cmp_int(int64_t a, int64_t b);
howl_sroiq_SConcept howl_sriqnames_sc_at_n(slop_list_howl_sroiq_SConcept xs, int64_t i);
int64_t howl_sriqnames_dname_cmp(howl_types_DName a, howl_types_DName b);
int64_t howl_sriqnames_filler_cmp(slop_option_howl_types_DName a, slop_option_howl_types_DName b);
int64_t howl_sriqnames_drole_rank(howl_types_DRole r);
int64_t howl_sriqnames_drole_cmp(howl_types_DRole a, howl_types_DRole b);
int64_t howl_sriqnames_dnames_cmp(slop_list_howl_types_DName a, slop_list_howl_types_DName b);
int64_t howl_sriqnames_dl_rank(howl_types_DlClause c);
int64_t howl_sriqnames_then_cmp(int64_t first, int64_t second);
int64_t howl_sriqnames_dl1_cmp(howl_types_Dl1 x, howl_types_Dl1 y);
int64_t howl_sriqnames_dl2_cmp(howl_types_Dl2 x, howl_types_Dl2 y);
int64_t howl_sriqnames_dl4_cmp(howl_types_Dl4 x, howl_types_Dl4 y);
int64_t howl_sriqnames_roles_cmp(howl_types_DRole a1, howl_types_DRole b1, howl_types_DRole a2, howl_types_DRole b2);
int64_t howl_sriqnames_dl_cmp(howl_types_DlClause a, howl_types_DlClause b);
howl_types_DName howl_sriqnames_rename_name(slop_list_int fresh, howl_types_DName n);
slop_option_howl_types_DName howl_sriqnames_rename_filler(slop_list_int fresh, slop_option_howl_types_DName b);
howl_types_DRole howl_sriqnames_rename_role(slop_list_int subs, howl_types_DRole r);
slop_list_howl_types_DName howl_sriqnames_sort_dnames(slop_arena* arena, slop_list_howl_types_DName xs);
howl_types_DName howl_sriqnames_dname_at(slop_list_howl_types_DName xs, int64_t i);
slop_list_howl_types_DName howl_sriqnames_rename_names(slop_arena* arena, slop_list_int fresh, slop_list_howl_types_DName ns);
howl_types_DlClause howl_sriqnames_rename_clause(slop_arena* arena, slop_list_int fresh, slop_list_int subs, howl_types_DlClause c);
howl_types_DlClause howl_sriqnames_clause_at(slop_list_howl_types_DlClause xs, int64_t i);
howl_types_DlClause howl_sriqnames_renumber_fns(slop_arena* arena, howl_types_DlClause c, int64_t next);
int64_t howl_sriqnames_fn_count(howl_types_DlClause c);
slop_list_int howl_sriqnames_rank_of(slop_arena* arena, slop_list_int order);
slop_list_int howl_sriqnames_concept_order(slop_arena* arena, slop_list_howl_sroiq_SConcept cs);
slop_list_int howl_sriqnames_srole_order(slop_arena* arena, slop_list_howl_types_DRole roles, slop_list_option_howl_types_DName fills);
slop_list_howl_sroiq_SConcept howl_sriqnames_pick_concepts(slop_arena* arena, slop_list_howl_sroiq_SConcept cs, slop_list_int order);
slop_list_howl_types_DRole howl_sriqnames_pick_roles(slop_arena* arena, slop_list_howl_types_DRole rs, slop_list_int order);
slop_list_option_howl_types_DName howl_sriqnames_pick_fills(slop_arena* arena, slop_list_option_howl_types_DName bs, slop_list_int order);
slop_list_option_howl_types_DName howl_sriqnames_rename_fills(slop_arena* arena, slop_list_int fresh, slop_list_option_howl_types_DName bs);
slop_list_howl_types_DlClause howl_sriqnames_rename_clauses(slop_arena* arena, slop_list_int fresh, slop_list_int subs, slop_list_howl_types_DlClause cs);
slop_list_howl_types_DlClause howl_sriqnames_canonical_clauses(slop_arena* arena, slop_list_howl_types_DlClause cs);
int64_t howl_sriqnames_fn_total(slop_list_howl_types_DlClause cs);
slop_list_slop_rdf_rdf_IRI howl_sriqnames_input_classes(slop_arena* arena, howl_owl2_Signature sig);
slop_list_slop_rdf_rdf_IRI howl_sriqnames_input_individuals(slop_arena* arena, howl_owl2_Signature sig);
howl_sriqnames_SriqNormal howl_sriqnames_sriq_names(slop_arena* arena, howl_sriqnormal_S2 s2, howl_owl2_Signature sig, slop_list_howl_owl2_RawAxiom omitted);
howl_types_DRole howl_sriqnames_role_at(slop_list_howl_types_DRole xs, int64_t i);
slop_option_howl_types_DName howl_sriqnames_fill_at(slop_list_option_howl_types_DName xs, int64_t i);
slop_list_howl_owl2_RawAxiom howl_sriqnames_guard_witnesses(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted, howl_sriqelim_S1 s1);
slop_result_howl_sriqnames_SriqNormal_string howl_sriqnames_normalize_after_s1(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted, howl_sriqelim_S1 s1, howl_owl2_Signature sig);
slop_result_howl_sriqnames_SriqNormal_string howl_sriqnames_normalize_after_s0(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted, howl_sriqnormal_S0 s0, howl_owl2_Signature sig, int64_t bound);
slop_result_howl_sriqnames_SriqNormal_string howl_sriqnames_sriq_normalize_bounded(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted, howl_owl2_Signature sig, int64_t bound);
slop_result_howl_sriqnames_SriqNormal_string howl_sriqnames_sriq_normalize(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted, howl_owl2_Signature sig);
slop_string howl_sriqnames_rn(slop_arena* arena, howl_types_DName n);
slop_string howl_sriqnames_rr(slop_arena* arena, howl_types_DRole r);
slop_string howl_sriqnames_rf(slop_arena* arena, slop_option_howl_types_DName b);
slop_string howl_sriqnames_rns(slop_arena* arena, slop_list_howl_types_DName ns);
slop_string howl_sriqnames_rints(slop_arena* arena, slop_list_int xs);
slop_string howl_sriqnames_j(slop_arena* arena, slop_list_string parts);
slop_string howl_sriqnames_render_dl_ids(slop_arena* arena, howl_types_DlClause c);
slop_string howl_sriqnames_table_line(slop_arena* arena, slop_string prefix, int64_t k, slop_string text);
slop_list_string howl_sriqnames_prefixed(slop_arena* arena, slop_string prefix, slop_list_slop_rdf_rdf_IRI is);
slop_list_string howl_sriqnames_render_sriq_normal(slop_arena* arena, howl_sriqnames_SriqNormal n);
uint8_t howl_sriqnames_name_in_range(howl_types_DName n, int64_t nc);
uint8_t howl_sriqnames_names_in_range(slop_list_howl_types_DName ns, int64_t nc);
uint8_t howl_sriqnames_filler_in_range(slop_option_howl_types_DName b, int64_t nc);
uint8_t howl_sriqnames_role_in_range(howl_types_DRole r, int64_t ns);
uint8_t howl_sriqnames_clause_in_range(howl_types_DlClause c, int64_t nc, int64_t ns);
slop_list_string howl_sriqnames_concepts_ordered(slop_arena* arena, slop_list_howl_sroiq_SConcept cs);
slop_list_string howl_sriqnames_sroles_ordered(slop_arena* arena, slop_list_howl_types_DRole rs, slop_list_option_howl_types_DName bs);
slop_list_string howl_sriqnames_clauses_ordered(slop_arena* arena, slop_list_howl_types_DlClause cs);
slop_list_string howl_sriqnames_ids_in_range(slop_arena* arena, howl_sriqnames_SriqNormal n);
uint8_t howl_sriqnames_witness_count_ok(howl_types_DlClause c);
slop_list_int howl_sriqnames_clause_fns(slop_arena* arena, howl_types_DlClause c);
slop_list_string howl_sriqnames_fns_dense(slop_arena* arena, howl_sriqnames_SriqNormal n);
slop_list_string howl_sriqnames_fresh_not_signature(slop_arena* arena, howl_sriqnames_SriqNormal n);
slop_list_string howl_sriqnames_sriq_invariants(slop_arena* arena, howl_sriqnames_SriqNormal n);

typedef struct { slop_list_howl_types_DName xs; } howl_sriqnames__lambda_362_env_t;

static int64_t howl_sriqnames__lambda_362(howl_sriqnames__lambda_362_env_t* _env, int64_t i, int64_t j) { return howl_sriqnames_dname_cmp(howl_sriqnames_dname_at(_env->xs, i), howl_sriqnames_dname_at(_env->xs, j)); }

typedef struct { slop_list_howl_sroiq_SConcept cs; } howl_sriqnames__lambda_368_env_t;

static int64_t howl_sriqnames__lambda_368(howl_sriqnames__lambda_368_env_t* _env, int64_t i, int64_t j) { return howl_sroiq_sc_cmp(howl_sriqnames_sc_at_n(_env->cs, i), howl_sriqnames_sc_at_n(_env->cs, j)); }

typedef struct { slop_list_howl_types_DRole roles; slop_list_option_howl_types_DName fills; } howl_sriqnames__lambda_369_env_t;

static int64_t howl_sriqnames__lambda_369(howl_sriqnames__lambda_369_env_t* _env, int64_t i, int64_t j) { return howl_sriqnames_then_cmp(howl_sriqnames_drole_cmp(howl_sriqnames_role_at(_env->roles, i), howl_sriqnames_role_at(_env->roles, j)), howl_sriqnames_filler_cmp(howl_sriqnames_fill_at(_env->fills, i), howl_sriqnames_fill_at(_env->fills, j))); }

typedef struct { slop_list_howl_types_DlClause cs; } howl_sriqnames__lambda_370_env_t;

static int64_t howl_sriqnames__lambda_370(howl_sriqnames__lambda_370_env_t* _env, int64_t i, int64_t j) { return howl_sriqnames_dl_cmp(howl_sriqnames_clause_at(_env->cs, i), howl_sriqnames_clause_at(_env->cs, j)); }

int64_t howl_sriqnames_int_at(slop_list_int xs, int64_t i) {
    __auto_type _mv_331 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_331.has_value) {
        __auto_type v = _mv_331.value;
        return v;
    } else if (!_mv_331.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

slop_list_int howl_sriqnames_ints_new(slop_arena* arena, int64_t n, int64_t v) {
    {
        __auto_type xs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < n) {
            (void)(({ __auto_type _lst_p = &(xs); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            i = (i + 1);
        }
        return xs;
    }
}

int64_t howl_sriqnames_cmp_int(int64_t a, int64_t b) {
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

howl_sroiq_SConcept howl_sriqnames_sc_at_n(slop_list_howl_sroiq_SConcept xs, int64_t i) {
    __auto_type _mv_332 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_sroiq_SConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_332.has_value) {
        __auto_type v = _mv_332.value;
        return v;
    } else if (!_mv_332.has_value) {
        return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_top });
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqnames_dname_cmp(howl_types_DName a, howl_types_DName b) {
    __auto_type _mv_333 = a;
    switch (_mv_333.tag) {
        case howl_types_DName_dn_class:
        {
            __auto_type ia = _mv_333.data.dn_class;
            __auto_type _mv_334 = b;
            switch (_mv_334.tag) {
                case howl_types_DName_dn_class:
                {
                    __auto_type ib = _mv_334.data.dn_class;
                    return howl_canon_iri_cmp(ia, ib);
                }
                case howl_types_DName_dn_fresh:
                {
                    __auto_type _ = _mv_334.data.dn_fresh;
                    return -1;
                }
            }
            SLOP_UNREACHABLE();
        }
        case howl_types_DName_dn_fresh:
        {
            __auto_type ka = _mv_333.data.dn_fresh;
            __auto_type _mv_335 = b;
            switch (_mv_335.tag) {
                case howl_types_DName_dn_class:
                {
                    __auto_type _ = _mv_335.data.dn_class;
                    return 1;
                }
                case howl_types_DName_dn_fresh:
                {
                    __auto_type kb = _mv_335.data.dn_fresh;
                    return howl_sriqnames_cmp_int(ka, kb);
                }
            }
            SLOP_UNREACHABLE();
        }
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqnames_filler_cmp(slop_option_howl_types_DName a, slop_option_howl_types_DName b) {
    __auto_type _mv_336 = a;
    if (!_mv_336.has_value) {
        __auto_type _mv_337 = b;
        if (!_mv_337.has_value) {
            return 0;
        } else if (_mv_337.has_value) {
            __auto_type _ = _mv_337.value;
            return -1;
        }
        SLOP_UNREACHABLE();
    } else if (_mv_336.has_value) {
        __auto_type x = _mv_336.value;
        __auto_type _mv_338 = b;
        if (!_mv_338.has_value) {
            return 1;
        } else if (_mv_338.has_value) {
            __auto_type y = _mv_338.value;
            return howl_sriqnames_dname_cmp(x, y);
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqnames_drole_rank(howl_types_DRole r) {
    __auto_type _mv_339 = r;
    switch (_mv_339.tag) {
        case howl_types_DRole_dr_prop:
        {
            __auto_type _ = _mv_339.data.dr_prop;
            return 0;
        }
        case howl_types_DRole_dr_bar:
        {
            __auto_type _ = _mv_339.data.dr_bar;
            return 1;
        }
        case howl_types_DRole_dr_sub:
        {
            __auto_type _ = _mv_339.data.dr_sub;
            return 2;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqnames_drole_cmp(howl_types_DRole a, howl_types_DRole b) {
    {
        __auto_type ra = howl_sriqnames_drole_rank(a);
        __auto_type rb = howl_sriqnames_drole_rank(b);
        if (ra != rb) {
            return howl_sriqnames_cmp_int(ra, rb);
        } else {
            __auto_type _mv_340 = a;
            switch (_mv_340.tag) {
                case howl_types_DRole_dr_prop:
                {
                    __auto_type ia = _mv_340.data.dr_prop;
                    __auto_type _mv_341 = b;
                    switch (_mv_341.tag) {
                        case howl_types_DRole_dr_prop:
                        {
                            __auto_type ib = _mv_341.data.dr_prop;
                            return howl_canon_iri_cmp(ia, ib);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_types_DRole_dr_bar:
                {
                    __auto_type ia = _mv_340.data.dr_bar;
                    __auto_type _mv_342 = b;
                    switch (_mv_342.tag) {
                        case howl_types_DRole_dr_bar:
                        {
                            __auto_type ib = _mv_342.data.dr_bar;
                            return howl_canon_iri_cmp(ia, ib);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_types_DRole_dr_sub:
                {
                    __auto_type ka = _mv_340.data.dr_sub;
                    __auto_type _mv_343 = b;
                    switch (_mv_343.tag) {
                        case howl_types_DRole_dr_sub:
                        {
                            __auto_type kb = _mv_343.data.dr_sub;
                            return howl_sriqnames_cmp_int(ka, kb);
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

int64_t howl_sriqnames_dnames_cmp(slop_list_howl_types_DName a, slop_list_howl_types_DName b) {
    {
        __auto_type alen = ((int64_t)(((int64_t)((a).len))));
        __auto_type blen = ((int64_t)(((int64_t)((b).len))));
        __auto_type n = ((alen) < (blen) ? (alen) : (blen));
        int64_t i = 0;
        int64_t r = 0;
        while ((i < n) && (r == 0)) {
            __auto_type _mv_344 = ({ __auto_type _lst = a; size_t _idx = (size_t)i; slop_option_howl_types_DName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_344.has_value) {
                __auto_type x = _mv_344.value;
                __auto_type _mv_345 = ({ __auto_type _lst = b; size_t _idx = (size_t)i; slop_option_howl_types_DName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_345.has_value) {
                    __auto_type y = _mv_345.value;
                    r = howl_sriqnames_dname_cmp(x, y);
                } else if (!_mv_345.has_value) {
                }
            } else if (!_mv_344.has_value) {
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

int64_t howl_sriqnames_dl_rank(howl_types_DlClause c) {
    __auto_type _mv_346 = c;
    switch (_mv_346.tag) {
        case howl_types_DlClause_dl1:
        {
            __auto_type _ = _mv_346.data.dl1;
            return 1;
        }
        case howl_types_DlClause_dl2:
        {
            __auto_type _ = _mv_346.data.dl2;
            return 2;
        }
        case howl_types_DlClause_dl3:
        {
            return 3;
        }
        case howl_types_DlClause_dl4:
        {
            __auto_type _ = _mv_346.data.dl4;
            return 4;
        }
        case howl_types_DlClause_dl5:
        {
            return 5;
        }
        case howl_types_DlClause_dl6:
        {
            return 6;
        }
        case howl_types_DlClause_dl7:
        {
            return 7;
        }
        case howl_types_DlClause_dl8:
        {
            return 8;
        }
        case howl_types_DlClause_dl9:
        {
            return 9;
        }
        case howl_types_DlClause_dl10:
        {
            return 10;
        }
        case howl_types_DlClause_dl11:
        {
            return 11;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqnames_then_cmp(int64_t first, int64_t second) {
    if (first != 0) {
        return first;
    } else {
        return second;
    }
}

int64_t howl_sriqnames_dl1_cmp(howl_types_Dl1 x, howl_types_Dl1 y) {
    return howl_sriqnames_then_cmp(howl_sriqnames_dnames_cmp(x.body, y.body), howl_sriqnames_dnames_cmp(x.head, y.head));
}

int64_t howl_sriqnames_dl2_cmp(howl_types_Dl2 x, howl_types_Dl2 y) {
    return howl_sriqnames_then_cmp(howl_sriqnames_dname_cmp(x.sub, y.sub), howl_sriqnames_then_cmp(howl_sriqnames_drole_cmp(x.role, y.role), howl_sriqnames_then_cmp(howl_sriqnames_cmp_int(x.count, y.count), howl_sriqnames_filler_cmp(x.filler, y.filler))));
}

int64_t howl_sriqnames_dl4_cmp(howl_types_Dl4 x, howl_types_Dl4 y) {
    return howl_sriqnames_then_cmp(howl_sriqnames_dname_cmp(x.sub, y.sub), howl_sriqnames_then_cmp(howl_sriqnames_drole_cmp(x.role, y.role), howl_sriqnames_then_cmp(howl_sriqnames_cmp_int(x.count, y.count), howl_sriqnames_then_cmp(howl_sriqnames_filler_cmp(x.filler, y.filler), howl_sriqnames_drole_cmp(x.srole, y.srole)))));
}

int64_t howl_sriqnames_roles_cmp(howl_types_DRole a1, howl_types_DRole b1, howl_types_DRole a2, howl_types_DRole b2) {
    return howl_sriqnames_then_cmp(howl_sriqnames_drole_cmp(a1, a2), howl_sriqnames_drole_cmp(b1, b2));
}

int64_t howl_sriqnames_dl_cmp(howl_types_DlClause a, howl_types_DlClause b) {
    {
        __auto_type ra = howl_sriqnames_dl_rank(a);
        __auto_type rb = howl_sriqnames_dl_rank(b);
        if (ra != rb) {
            return howl_sriqnames_cmp_int(ra, rb);
        } else {
            __auto_type _mv_347 = a;
            switch (_mv_347.tag) {
                case howl_types_DlClause_dl1:
                {
                    __auto_type x = _mv_347.data.dl1;
                    __auto_type _mv_348 = b;
                    switch (_mv_348.tag) {
                        case howl_types_DlClause_dl1:
                        {
                            __auto_type y = _mv_348.data.dl1;
                            return howl_sriqnames_dl1_cmp(x, y);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_types_DlClause_dl2:
                {
                    __auto_type x = _mv_347.data.dl2;
                    __auto_type _mv_349 = b;
                    switch (_mv_349.tag) {
                        case howl_types_DlClause_dl2:
                        {
                            __auto_type y = _mv_349.data.dl2;
                            return howl_sriqnames_dl2_cmp(x, y);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_types_DlClause_dl3:
                {
                    __auto_type s1 = _mv_347.data.dl3.f0;
                    __auto_type p1 = _mv_347.data.dl3.f1;
                    __auto_type q1 = _mv_347.data.dl3.f2;
                    __auto_type _mv_350 = b;
                    switch (_mv_350.tag) {
                        case howl_types_DlClause_dl3:
                        {
                            __auto_type s2 = _mv_350.data.dl3.f0;
                            __auto_type p2 = _mv_350.data.dl3.f1;
                            __auto_type q2 = _mv_350.data.dl3.f2;
                            return howl_sriqnames_then_cmp(howl_sriqnames_drole_cmp(s1, s2), howl_sriqnames_then_cmp(howl_sriqnames_dname_cmp(p1, p2), howl_sriqnames_dname_cmp(q1, q2)));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_types_DlClause_dl4:
                {
                    __auto_type x = _mv_347.data.dl4;
                    __auto_type _mv_351 = b;
                    switch (_mv_351.tag) {
                        case howl_types_DlClause_dl4:
                        {
                            __auto_type y = _mv_351.data.dl4;
                            return howl_sriqnames_dl4_cmp(x, y);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_types_DlClause_dl5:
                {
                    __auto_type n1 = _mv_347.data.dl5.f0;
                    __auto_type s1 = _mv_347.data.dl5.f1;
                    __auto_type _mv_352 = b;
                    switch (_mv_352.tag) {
                        case howl_types_DlClause_dl5:
                        {
                            __auto_type n2 = _mv_352.data.dl5.f0;
                            __auto_type s2 = _mv_352.data.dl5.f1;
                            return howl_sriqnames_then_cmp(howl_sriqnames_dname_cmp(n1, n2), howl_sriqnames_drole_cmp(s1, s2));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_types_DlClause_dl6:
                {
                    __auto_type s1 = _mv_347.data.dl6.f0;
                    __auto_type n1 = _mv_347.data.dl6.f1;
                    __auto_type _mv_353 = b;
                    switch (_mv_353.tag) {
                        case howl_types_DlClause_dl6:
                        {
                            __auto_type s2 = _mv_353.data.dl6.f0;
                            __auto_type n2 = _mv_353.data.dl6.f1;
                            return howl_sriqnames_then_cmp(howl_sriqnames_drole_cmp(s1, s2), howl_sriqnames_dname_cmp(n1, n2));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_types_DlClause_dl7:
                {
                    __auto_type a1 = _mv_347.data.dl7.f0;
                    __auto_type b1 = _mv_347.data.dl7.f1;
                    __auto_type _mv_354 = b;
                    switch (_mv_354.tag) {
                        case howl_types_DlClause_dl7:
                        {
                            __auto_type a2 = _mv_354.data.dl7.f0;
                            __auto_type b2 = _mv_354.data.dl7.f1;
                            return howl_sriqnames_roles_cmp(a1, b1, a2, b2);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_types_DlClause_dl8:
                {
                    __auto_type a1 = _mv_347.data.dl8.f0;
                    __auto_type b1 = _mv_347.data.dl8.f1;
                    __auto_type _mv_355 = b;
                    switch (_mv_355.tag) {
                        case howl_types_DlClause_dl8:
                        {
                            __auto_type a2 = _mv_355.data.dl8.f0;
                            __auto_type b2 = _mv_355.data.dl8.f1;
                            return howl_sriqnames_roles_cmp(a1, b1, a2, b2);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_types_DlClause_dl9:
                {
                    __auto_type a1 = _mv_347.data.dl9.f0;
                    __auto_type b1 = _mv_347.data.dl9.f1;
                    __auto_type _mv_356 = b;
                    switch (_mv_356.tag) {
                        case howl_types_DlClause_dl9:
                        {
                            __auto_type a2 = _mv_356.data.dl9.f0;
                            __auto_type b2 = _mv_356.data.dl9.f1;
                            return howl_sriqnames_roles_cmp(a1, b1, a2, b2);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_types_DlClause_dl10:
                {
                    __auto_type o1 = _mv_347.data.dl10.f0;
                    __auto_type n1 = _mv_347.data.dl10.f1;
                    __auto_type _mv_357 = b;
                    switch (_mv_357.tag) {
                        case howl_types_DlClause_dl10:
                        {
                            __auto_type o2 = _mv_357.data.dl10.f0;
                            __auto_type n2 = _mv_357.data.dl10.f1;
                            return howl_sriqnames_then_cmp(howl_canon_iri_cmp(o1, o2), howl_sriqnames_dname_cmp(n1, n2));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case howl_types_DlClause_dl11:
                {
                    __auto_type n1 = _mv_347.data.dl11.f0;
                    __auto_type o1 = _mv_347.data.dl11.f1;
                    __auto_type _mv_358 = b;
                    switch (_mv_358.tag) {
                        case howl_types_DlClause_dl11:
                        {
                            __auto_type n2 = _mv_358.data.dl11.f0;
                            __auto_type o2 = _mv_358.data.dl11.f1;
                            return howl_sriqnames_then_cmp(howl_sriqnames_dname_cmp(n1, n2), howl_canon_iri_cmp(o1, o2));
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

howl_types_DName howl_sriqnames_rename_name(slop_list_int fresh, howl_types_DName n) {
    __auto_type _mv_359 = n;
    switch (_mv_359.tag) {
        case howl_types_DName_dn_class:
        {
            __auto_type _ = _mv_359.data.dn_class;
            return n;
        }
        case howl_types_DName_dn_fresh:
        {
            __auto_type k = _mv_359.data.dn_fresh;
            return ((howl_types_DName){ .tag = howl_types_DName_dn_fresh, .data.dn_fresh = ((int64_t)(SLOP_RANGE(int64_t, howl_sriqnames_int_at(fresh, ((int64_t)(k))), 1, 0, 0, 0, "(Int 0 ..) at sriqnames.slop:207:64"))) });
        }
    }
    SLOP_UNREACHABLE();
}

slop_option_howl_types_DName howl_sriqnames_rename_filler(slop_list_int fresh, slop_option_howl_types_DName b) {
    __auto_type _mv_360 = b;
    if (!_mv_360.has_value) {
        return b;
    } else if (_mv_360.has_value) {
        __auto_type n = _mv_360.value;
        return (slop_option_howl_types_DName){.has_value = 1, .value = howl_sriqnames_rename_name(fresh, n)};
    }
    SLOP_UNREACHABLE();
}

howl_types_DRole howl_sriqnames_rename_role(slop_list_int subs, howl_types_DRole r) {
    __auto_type _mv_361 = r;
    switch (_mv_361.tag) {
        case howl_types_DRole_dr_sub:
        {
            __auto_type k = _mv_361.data.dr_sub;
            return ((howl_types_DRole){ .tag = howl_types_DRole_dr_sub, .data.dr_sub = ((int64_t)(SLOP_RANGE(int64_t, howl_sriqnames_int_at(subs, ((int64_t)(k))), 1, 0, 0, 0, "(Int 0 ..) at sriqnames.slop:220:60"))) });
        }
        default: {
            return r;
        }
    }
}

slop_list_howl_types_DName howl_sriqnames_sort_dnames(slop_arena* arena, slop_list_howl_types_DName xs) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ howl_sriqnames__lambda_362_env_t* howl_sriqnames__lambda_362_env = (howl_sriqnames__lambda_362_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqnames__lambda_362_env_t)); *howl_sriqnames__lambda_362_env = (howl_sriqnames__lambda_362_env_t){ .xs = xs }; (slop_closure_t){ (void*)howl_sriqnames__lambda_362, (void*)howl_sriqnames__lambda_362_env }; }));
        __auto_type out = ((slop_list_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t have = 0;
        __auto_type last = ((howl_types_DName){ .tag = howl_types_DName_dn_fresh, .data.dn_fresh = 0 });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type n = howl_sriqnames_dname_at(xs, k);
                    if (!(have) || (howl_sriqnames_dname_cmp(n, last) != 0)) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        last = n;
                        have = 1;
                    }
                }
            }
        }
        return out;
    }
}

howl_types_DName howl_sriqnames_dname_at(slop_list_howl_types_DName xs, int64_t i) {
    __auto_type _mv_363 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_DName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_363.has_value) {
        __auto_type v = _mv_363.value;
        return v;
    } else if (!_mv_363.has_value) {
        return ((howl_types_DName){ .tag = howl_types_DName_dn_fresh, .data.dn_fresh = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_DName howl_sriqnames_rename_names(slop_arena* arena, slop_list_int fresh, slop_list_howl_types_DName ns) {
    {
        __auto_type out = ((slop_list_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnames_rename_name(fresh, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_types_DlClause howl_sriqnames_rename_clause(slop_arena* arena, slop_list_int fresh, slop_list_int subs, howl_types_DlClause c) {
    __auto_type _mv_364 = c;
    switch (_mv_364.tag) {
        case howl_types_DlClause_dl1:
        {
            __auto_type d = _mv_364.data.dl1;
            return ((howl_types_DlClause){ .tag = howl_types_DlClause_dl1, .data.dl1 = ((howl_types_Dl1){.body = howl_sriqnames_sort_dnames(arena, howl_sriqnames_rename_names(arena, fresh, d.body)), .head = howl_sriqnames_sort_dnames(arena, howl_sriqnames_rename_names(arena, fresh, d.head))}) });
        }
        case howl_types_DlClause_dl2:
        {
            __auto_type d = _mv_364.data.dl2;
            return ((howl_types_DlClause){ .tag = howl_types_DlClause_dl2, .data.dl2 = ((howl_types_Dl2){.sub = howl_sriqnames_rename_name(fresh, d.sub), .role = howl_sriqnames_rename_role(subs, d.role), .count = d.count, .filler = howl_sriqnames_rename_filler(fresh, d.filler), .fns = d.fns}) });
        }
        case howl_types_DlClause_dl3:
        {
            __auto_type s = _mv_364.data.dl3.f0;
            __auto_type b1 = _mv_364.data.dl3.f1;
            __auto_type b2 = _mv_364.data.dl3.f2;
            return ((howl_types_DlClause){ .tag = howl_types_DlClause_dl3, .data.dl3 = { .f0 = howl_sriqnames_rename_role(subs, s), .f1 = howl_sriqnames_rename_name(fresh, b1), .f2 = howl_sriqnames_rename_name(fresh, b2) } });
        }
        case howl_types_DlClause_dl4:
        {
            __auto_type d = _mv_364.data.dl4;
            return ((howl_types_DlClause){ .tag = howl_types_DlClause_dl4, .data.dl4 = ((howl_types_Dl4){.sub = howl_sriqnames_rename_name(fresh, d.sub), .role = howl_sriqnames_rename_role(subs, d.role), .count = d.count, .filler = howl_sriqnames_rename_filler(fresh, d.filler), .srole = howl_sriqnames_rename_role(subs, d.srole)}) });
        }
        case howl_types_DlClause_dl5:
        {
            __auto_type b = _mv_364.data.dl5.f0;
            __auto_type s = _mv_364.data.dl5.f1;
            return ((howl_types_DlClause){ .tag = howl_types_DlClause_dl5, .data.dl5 = { .f0 = howl_sriqnames_rename_name(fresh, b), .f1 = howl_sriqnames_rename_role(subs, s) } });
        }
        case howl_types_DlClause_dl6:
        {
            __auto_type s = _mv_364.data.dl6.f0;
            __auto_type b = _mv_364.data.dl6.f1;
            return ((howl_types_DlClause){ .tag = howl_types_DlClause_dl6, .data.dl6 = { .f0 = howl_sriqnames_rename_role(subs, s), .f1 = howl_sriqnames_rename_name(fresh, b) } });
        }
        case howl_types_DlClause_dl7:
        {
            __auto_type a = _mv_364.data.dl7.f0;
            __auto_type b = _mv_364.data.dl7.f1;
            return ((howl_types_DlClause){ .tag = howl_types_DlClause_dl7, .data.dl7 = { .f0 = howl_sriqnames_rename_role(subs, a), .f1 = howl_sriqnames_rename_role(subs, b) } });
        }
        case howl_types_DlClause_dl8:
        {
            __auto_type a = _mv_364.data.dl8.f0;
            __auto_type b = _mv_364.data.dl8.f1;
            return ((howl_types_DlClause){ .tag = howl_types_DlClause_dl8, .data.dl8 = { .f0 = howl_sriqnames_rename_role(subs, a), .f1 = howl_sriqnames_rename_role(subs, b) } });
        }
        case howl_types_DlClause_dl9:
        {
            __auto_type a = _mv_364.data.dl9.f0;
            __auto_type b = _mv_364.data.dl9.f1;
            return ((howl_types_DlClause){ .tag = howl_types_DlClause_dl9, .data.dl9 = { .f0 = howl_sriqnames_rename_role(subs, a), .f1 = howl_sriqnames_rename_role(subs, b) } });
        }
        case howl_types_DlClause_dl10:
        {
            __auto_type o = _mv_364.data.dl10.f0;
            __auto_type b = _mv_364.data.dl10.f1;
            return ((howl_types_DlClause){ .tag = howl_types_DlClause_dl10, .data.dl10 = { .f0 = o, .f1 = howl_sriqnames_rename_name(fresh, b) } });
        }
        case howl_types_DlClause_dl11:
        {
            __auto_type b = _mv_364.data.dl11.f0;
            __auto_type o = _mv_364.data.dl11.f1;
            return ((howl_types_DlClause){ .tag = howl_types_DlClause_dl11, .data.dl11 = { .f0 = howl_sriqnames_rename_name(fresh, b), .f1 = o } });
        }
    }
    SLOP_UNREACHABLE();
}

howl_types_DlClause howl_sriqnames_clause_at(slop_list_howl_types_DlClause xs, int64_t i) {
    __auto_type _mv_365 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_DlClause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_365.has_value) {
        __auto_type v = _mv_365.value;
        return v;
    } else if (!_mv_365.has_value) {
        return ((howl_types_DlClause){ .tag = howl_types_DlClause_dl7, .data.dl7 = { .f0 = ((howl_types_DRole){ .tag = howl_types_DRole_dr_sub, .data.dr_sub = 0 }), .f1 = ((howl_types_DRole){ .tag = howl_types_DRole_dr_sub, .data.dr_sub = 0 }) } });
    }
    SLOP_UNREACHABLE();
}

howl_types_DlClause howl_sriqnames_renumber_fns(slop_arena* arena, howl_types_DlClause c, int64_t next) {
    __auto_type _mv_366 = c;
    switch (_mv_366.tag) {
        case howl_types_DlClause_dl2:
        {
            __auto_type d = _mv_366.data.dl2;
            {
                __auto_type fs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                int64_t i = 0;
                while (i < ((int64_t)(((int64_t)((d.fns).len))))) {
                    ({ __auto_type _lst_p = &(fs); __auto_type _item = (((int64_t)(SLOP_RANGE(int64_t, (next + i), 1, 0, 0, 0, "(Int 0 ..) at sriqnames.slop:297:50")))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    i = (i + 1);
                }
                return ((howl_types_DlClause){ .tag = howl_types_DlClause_dl2, .data.dl2 = ((howl_types_Dl2){.sub = d.sub, .role = d.role, .count = d.count, .filler = d.filler, .fns = fs}) });
            }
        }
        default: {
            return c;
        }
    }
}

int64_t howl_sriqnames_fn_count(howl_types_DlClause c) {
    __auto_type _mv_367 = c;
    switch (_mv_367.tag) {
        case howl_types_DlClause_dl2:
        {
            __auto_type d = _mv_367.data.dl2;
            return ((int64_t)(((int64_t)((d.fns).len))));
        }
        default: {
            return 0;
        }
    }
}

slop_list_int howl_sriqnames_rank_of(slop_arena* arena, slop_list_int order) {
    {
        __auto_type rank = howl_sriqnames_ints_new(arena, ((int64_t)(((int64_t)((order).len)))), 0);
        int64_t k = 0;
        {
            __auto_type _coll = order;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type old = _coll.data[_i];
                (void)(({ __auto_type _set_lst = &(rank); size_t _set_idx = (size_t)(old); __auto_type _set_val = (k); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
                k = (k + 1);
            }
        }
        return rank;
    }
}

slop_list_int howl_sriqnames_concept_order(slop_arena* arena, slop_list_howl_sroiq_SConcept cs) {
    return howl_canon_sort_range(arena, ((int64_t)(((int64_t)((cs).len)))), ({ howl_sriqnames__lambda_368_env_t* howl_sriqnames__lambda_368_env = (howl_sriqnames__lambda_368_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqnames__lambda_368_env_t)); *howl_sriqnames__lambda_368_env = (howl_sriqnames__lambda_368_env_t){ .cs = cs }; (slop_closure_t){ (void*)howl_sriqnames__lambda_368, (void*)howl_sriqnames__lambda_368_env }; }));
}

slop_list_int howl_sriqnames_srole_order(slop_arena* arena, slop_list_howl_types_DRole roles, slop_list_option_howl_types_DName fills) {
    return howl_canon_sort_range(arena, ((int64_t)(((int64_t)((roles).len)))), ({ howl_sriqnames__lambda_369_env_t* howl_sriqnames__lambda_369_env = (howl_sriqnames__lambda_369_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqnames__lambda_369_env_t)); *howl_sriqnames__lambda_369_env = (howl_sriqnames__lambda_369_env_t){ .roles = roles, .fills = fills }; (slop_closure_t){ (void*)howl_sriqnames__lambda_369, (void*)howl_sriqnames__lambda_369_env }; }));
}

slop_list_howl_sroiq_SConcept howl_sriqnames_pick_concepts(slop_arena* arena, slop_list_howl_sroiq_SConcept cs, slop_list_int order) {
    {
        __auto_type out = ((slop_list_howl_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = order;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnames_sc_at_n(cs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_types_DRole howl_sriqnames_pick_roles(slop_arena* arena, slop_list_howl_types_DRole rs, slop_list_int order) {
    {
        __auto_type out = ((slop_list_howl_types_DRole){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = order;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnames_role_at(rs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_option_howl_types_DName howl_sriqnames_pick_fills(slop_arena* arena, slop_list_option_howl_types_DName bs, slop_list_int order) {
    {
        __auto_type out = ((slop_list_option_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = order;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnames_fill_at(bs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_option_howl_types_DName howl_sriqnames_rename_fills(slop_arena* arena, slop_list_int fresh, slop_list_option_howl_types_DName bs) {
    {
        __auto_type out = ((slop_list_option_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = bs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnames_rename_filler(fresh, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_types_DlClause howl_sriqnames_rename_clauses(slop_arena* arena, slop_list_int fresh, slop_list_int subs, slop_list_howl_types_DlClause cs) {
    {
        __auto_type out = ((slop_list_howl_types_DlClause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnames_rename_clause(arena, fresh, subs, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_types_DlClause howl_sriqnames_canonical_clauses(slop_arena* arena, slop_list_howl_types_DlClause cs) {
    {
        __auto_type order = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((cs).len)))), ({ howl_sriqnames__lambda_370_env_t* howl_sriqnames__lambda_370_env = (howl_sriqnames__lambda_370_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqnames__lambda_370_env_t)); *howl_sriqnames__lambda_370_env = (howl_sriqnames__lambda_370_env_t){ .cs = cs }; (slop_closure_t){ (void*)howl_sriqnames__lambda_370, (void*)howl_sriqnames__lambda_370_env }; }));
        __auto_type out = ((slop_list_howl_types_DlClause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t next = 0;
        {
            __auto_type _coll = order;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type c = howl_sriqnames_clause_at(cs, k);
                    __auto_type n = ((int64_t)(((int64_t)((out).len))));
                    if ((n == 0) || (howl_sriqnames_dl_cmp(c, howl_sriqnames_clause_at(out, (n - 1))) != 0)) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnames_renumber_fns(arena, c, next)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        next = (next + howl_sriqnames_fn_count(c));
                    }
                }
            }
        }
        return out;
    }
}

int64_t howl_sriqnames_fn_total(slop_list_howl_types_DlClause cs) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                n = (n + howl_sriqnames_fn_count(c));
            }
        }
        return n;
    }
}

slop_list_slop_rdf_rdf_IRI howl_sriqnames_input_classes(slop_arena* arena, howl_owl2_Signature sig) {
    {
        __auto_type out = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.classes); (slop_list_slop_rdf_rdf_IRI){.data = (slop_rdf_rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!((string_eq(c.value, slop_rdf_vocab_OWL_THING) || string_eq(c.value, slop_rdf_vocab_OWL_NOTHING)))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return howl_canon_sort_iris(arena, out);
    }
}

slop_list_slop_rdf_rdf_IRI howl_sriqnames_input_individuals(slop_arena* arena, howl_owl2_Signature sig) {
    {
        __auto_type out = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.individuals); (slop_list_slop_rdf_rdf_IRI){.data = (slop_rdf_rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return howl_canon_sort_iris(arena, out);
    }
}

howl_sriqnames_SriqNormal howl_sriqnames_sriq_names(slop_arena* arena, howl_sriqnormal_S2 s2, howl_owl2_Signature sig, slop_list_howl_owl2_RawAxiom omitted) {
    {
        __auto_type forder = howl_sriqnames_concept_order(arena, s2.concepts);
        __auto_type fresh = howl_sriqnames_rank_of(arena, forder);
        __auto_type fills = howl_sriqnames_rename_fills(arena, fresh, s2.sfills);
        __auto_type sorder = howl_sriqnames_srole_order(arena, s2.sroles, fills);
        __auto_type subs = howl_sriqnames_rank_of(arena, sorder);
        __auto_type clauses = howl_sriqnames_canonical_clauses(arena, howl_sriqnames_rename_clauses(arena, fresh, subs, s2.clauses));
        return ((howl_sriqnames_SriqNormal){.clauses = clauses, .concepts = howl_sriqnames_pick_concepts(arena, s2.concepts, forder), .sroles = howl_sriqnames_pick_roles(arena, s2.sroles, sorder), .sfills = howl_sriqnames_pick_fills(arena, fills, sorder), .bars = howl_canon_sort_iris(arena, s2.bars), .fns = ((int64_t)(SLOP_RANGE(int64_t, howl_sriqnames_fn_total(clauses), 1, 0, 0, 0, "(Int 0 ..) at sriqnames.slop:434:39"))), .classes = howl_sriqnames_input_classes(arena, sig), .individuals = howl_sriqnames_input_individuals(arena, sig), .omitted = omitted});
    }
}

howl_types_DRole howl_sriqnames_role_at(slop_list_howl_types_DRole xs, int64_t i) {
    __auto_type _mv_371 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_DRole _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_371.has_value) {
        __auto_type v = _mv_371.value;
        return v;
    } else if (!_mv_371.has_value) {
        return ((howl_types_DRole){ .tag = howl_types_DRole_dr_sub, .data.dr_sub = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_option_howl_types_DName howl_sriqnames_fill_at(slop_list_option_howl_types_DName xs, int64_t i) {
    __auto_type _mv_372 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_option_howl_types_DName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_372.has_value) {
        __auto_type v = _mv_372.value;
        return v;
    } else if (!_mv_372.has_value) {
        return (slop_option_howl_types_DName){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_owl2_RawAxiom howl_sriqnames_guard_witnesses(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted, howl_sriqelim_S1 s1) {
    {
        __auto_type out = ((slop_list_howl_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (((int64_t)((s1.omitted).len)) > 0) {
            {
                __auto_type _coll = accepted;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    __auto_type _mv_373 = a;
                    switch (_mv_373.tag) {
                        case howl_owl2_RawAxiom_ra_property_chain:
                        {
                            __auto_type ch = _mv_373.data.ra_property_chain;
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

slop_result_howl_sriqnames_SriqNormal_string howl_sriqnames_normalize_after_s1(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted, howl_sriqelim_S1 s1, howl_owl2_Signature sig) {
    __auto_type _mv_374 = howl_sriqnormal_sriq_s2(arena, s1.axioms);
    if (!_mv_374.is_ok) {
        __auto_type m = _mv_374.data.err;
        return ((slop_result_howl_sriqnames_SriqNormal_string){ .is_ok = false, .data.err = m });
    } else if (_mv_374.is_ok) {
        __auto_type s2 = _mv_374.data.ok;
        return ((slop_result_howl_sriqnames_SriqNormal_string){ .is_ok = true, .data.ok = howl_sriqnames_sriq_names(arena, s2, sig, howl_sriqnames_guard_witnesses(arena, accepted, s1)) });
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_sriqnames_SriqNormal_string howl_sriqnames_normalize_after_s0(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted, howl_sriqnormal_S0 s0, howl_owl2_Signature sig, int64_t bound) {
    __auto_type _mv_375 = howl_sriqelim_sriq_s1(arena, s0, bound);
    if (!_mv_375.is_ok) {
        __auto_type m = _mv_375.data.err;
        return ((slop_result_howl_sriqnames_SriqNormal_string){ .is_ok = false, .data.err = m });
    } else if (_mv_375.is_ok) {
        __auto_type s1 = _mv_375.data.ok;
        return howl_sriqnames_normalize_after_s1(arena, accepted, s1, sig);
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_sriqnames_SriqNormal_string howl_sriqnames_sriq_normalize_bounded(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted, howl_owl2_Signature sig, int64_t bound) {
    __auto_type _mv_376 = howl_sriqnormal_sriq_s0(arena, accepted);
    if (!_mv_376.is_ok) {
        __auto_type m = _mv_376.data.err;
        return ((slop_result_howl_sriqnames_SriqNormal_string){ .is_ok = false, .data.err = m });
    } else if (_mv_376.is_ok) {
        __auto_type s0 = _mv_376.data.ok;
        return howl_sriqnames_normalize_after_s0(arena, accepted, s0, sig, bound);
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_sriqnames_SriqNormal_string howl_sriqnames_sriq_normalize(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted, howl_owl2_Signature sig) {
    return howl_sriqnames_sriq_normalize_bounded(arena, accepted, sig, howl_sriqelim_S1_BOUND);
}

slop_string howl_sriqnames_rn(slop_arena* arena, howl_types_DName n) {
    __auto_type _mv_377 = n;
    switch (_mv_377.tag) {
        case howl_types_DName_dn_class:
        {
            __auto_type i = _mv_377.data.dn_class;
            return i.value;
        }
        case howl_types_DName_dn_fresh:
        {
            __auto_type k = _mv_377.data.dn_fresh;
            return string_concat(arena, SLOP_STR("A"), int_to_string(arena, k));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_sriqnames_rr(slop_arena* arena, howl_types_DRole r) {
    __auto_type _mv_378 = r;
    switch (_mv_378.tag) {
        case howl_types_DRole_dr_prop:
        {
            __auto_type i = _mv_378.data.dr_prop;
            return i.value;
        }
        case howl_types_DRole_dr_bar:
        {
            __auto_type i = _mv_378.data.dr_bar;
            return string_concat(arena, i.value, SLOP_STR("^bar"));
        }
        case howl_types_DRole_dr_sub:
        {
            __auto_type k = _mv_378.data.dr_sub;
            return string_concat(arena, SLOP_STR("S"), int_to_string(arena, k));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_sriqnames_rf(slop_arena* arena, slop_option_howl_types_DName b) {
    __auto_type _mv_379 = b;
    if (!_mv_379.has_value) {
        return SLOP_STR("T");
    } else if (_mv_379.has_value) {
        __auto_type n = _mv_379.value;
        return howl_sriqnames_rn(arena, n);
    }
    SLOP_UNREACHABLE();
}

slop_string howl_sriqnames_rns(slop_arena* arena, slop_list_howl_types_DName ns) {
    {
        __auto_type out = SLOP_STR("");
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                out = string_concat(arena, out, string_concat(arena, SLOP_STR(" "), howl_sriqnames_rn(arena, n)));
            }
        }
        return out;
    }
}

slop_string howl_sriqnames_rints(slop_arena* arena, slop_list_int xs) {
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

slop_string howl_sriqnames_j(slop_arena* arena, slop_list_string parts) {
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

slop_string howl_sriqnames_render_dl_ids(slop_arena* arena, howl_types_DlClause c) {
    {
        __auto_type ps = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_380 = c;
        switch (_mv_380.tag) {
            case howl_types_DlClause_dl1:
            {
                __auto_type d = _mv_380.data.dl1;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL1")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rns(arena, d.body)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rns(arena, d.head)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_DlClause_dl2:
            {
                __auto_type d = _mv_380.data.dl2;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL2")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rn(arena, d.sub)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rr(arena, d.role)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (int_to_string(arena, d.count)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rf(arena, d.filler)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rints(arena, d.fns)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_DlClause_dl3:
            {
                __auto_type s = _mv_380.data.dl3.f0;
                __auto_type a = _mv_380.data.dl3.f1;
                __auto_type b = _mv_380.data.dl3.f2;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL3")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rr(arena, s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rn(arena, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rn(arena, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_DlClause_dl4:
            {
                __auto_type d = _mv_380.data.dl4;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL4")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rn(arena, d.sub)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rr(arena, d.role)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (int_to_string(arena, d.count)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rf(arena, d.filler)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rr(arena, d.srole)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_DlClause_dl5:
            {
                __auto_type b = _mv_380.data.dl5.f0;
                __auto_type s = _mv_380.data.dl5.f1;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL5")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rn(arena, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rr(arena, s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_DlClause_dl6:
            {
                __auto_type s = _mv_380.data.dl6.f0;
                __auto_type b = _mv_380.data.dl6.f1;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL6")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rr(arena, s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rn(arena, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_DlClause_dl7:
            {
                __auto_type a = _mv_380.data.dl7.f0;
                __auto_type b = _mv_380.data.dl7.f1;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL7")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rr(arena, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rr(arena, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_DlClause_dl8:
            {
                __auto_type a = _mv_380.data.dl8.f0;
                __auto_type b = _mv_380.data.dl8.f1;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL8")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rr(arena, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rr(arena, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_DlClause_dl9:
            {
                __auto_type a = _mv_380.data.dl9.f0;
                __auto_type b = _mv_380.data.dl9.f1;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL9")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rr(arena, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rr(arena, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_DlClause_dl10:
            {
                __auto_type o = _mv_380.data.dl10.f0;
                __auto_type b = _mv_380.data.dl10.f1;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL10")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (o.value); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rn(arena, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_DlClause_dl11:
            {
                __auto_type b = _mv_380.data.dl11.f0;
                __auto_type o = _mv_380.data.dl11.f1;
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (SLOP_STR("DL11")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (howl_sriqnames_rn(arena, b)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(ps); __auto_type _item = (o.value); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
        }
        return howl_sriqnames_j(arena, ps);
    }
}

slop_string howl_sriqnames_table_line(slop_arena* arena, slop_string prefix, int64_t k, slop_string text) {
    return string_concat(arena, prefix, string_concat(arena, int_to_string(arena, k), string_concat(arena, SLOP_STR(" = "), text)));
}

slop_list_string howl_sriqnames_prefixed(slop_arena* arena, slop_string prefix, slop_list_slop_rdf_rdf_IRI is) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = is;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (string_concat(arena, prefix, i.value)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_string howl_sriqnames_render_sriq_normal(slop_arena* arena, howl_sriqnames_SriqNormal n) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = n.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnames_render_dl_ids(arena, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = n.concepts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnames_table_line(arena, SLOP_STR("A"), k, howl_sroiq_render_sconcept(arena, c))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                k = (k + 1);
            }
        }
        k = 0;
        {
            __auto_type _coll = n.sroles;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                {
                    __auto_type b = howl_sriqnames_fill_at(n.sfills, k);
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqnames_table_line(arena, SLOP_STR("S"), k, string_concat(arena, howl_sriqnames_rr(arena, r), string_concat(arena, SLOP_STR(" "), howl_sriqnames_rf(arena, b))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    k = (k + 1);
                }
            }
        }
        {
            __auto_type _coll = howl_sriqnames_prefixed(arena, SLOP_STR("bar "), n.bars);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (string_concat(arena, SLOP_STR("fns "), int_to_string(arena, n.fns))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        {
            __auto_type _coll = howl_sriqnames_prefixed(arena, SLOP_STR("class "), n.classes);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = howl_sriqnames_prefixed(arena, SLOP_STR("individual "), n.individuals);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = n.omitted;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (string_concat(arena, SLOP_STR("omitted "), howl_owl2_render_axiom(arena, a))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

uint8_t howl_sriqnames_name_in_range(howl_types_DName n, int64_t nc) {
    __auto_type _mv_381 = n;
    switch (_mv_381.tag) {
        case howl_types_DName_dn_class:
        {
            __auto_type _ = _mv_381.data.dn_class;
            return 1;
        }
        case howl_types_DName_dn_fresh:
        {
            __auto_type k = _mv_381.data.dn_fresh;
            return (((int64_t)(k)) < nc);
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqnames_names_in_range(slop_list_howl_types_DName ns, int64_t nc) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                if (!(howl_sriqnames_name_in_range(n, nc))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t howl_sriqnames_filler_in_range(slop_option_howl_types_DName b, int64_t nc) {
    __auto_type _mv_382 = b;
    if (!_mv_382.has_value) {
        return 1;
    } else if (_mv_382.has_value) {
        __auto_type n = _mv_382.value;
        return howl_sriqnames_name_in_range(n, nc);
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqnames_role_in_range(howl_types_DRole r, int64_t ns) {
    __auto_type _mv_383 = r;
    switch (_mv_383.tag) {
        case howl_types_DRole_dr_sub:
        {
            __auto_type k = _mv_383.data.dr_sub;
            return (((int64_t)(k)) < ns);
        }
        default: {
            return 1;
        }
    }
}

uint8_t howl_sriqnames_clause_in_range(howl_types_DlClause c, int64_t nc, int64_t ns) {
    __auto_type _mv_384 = c;
    switch (_mv_384.tag) {
        case howl_types_DlClause_dl1:
        {
            __auto_type d = _mv_384.data.dl1;
            return (howl_sriqnames_names_in_range(d.body, nc) && howl_sriqnames_names_in_range(d.head, nc));
        }
        case howl_types_DlClause_dl2:
        {
            __auto_type d = _mv_384.data.dl2;
            return ((howl_sriqnames_name_in_range(d.sub, nc)) && (howl_sriqnames_role_in_range(d.role, ns)) && (howl_sriqnames_filler_in_range(d.filler, nc)));
        }
        case howl_types_DlClause_dl3:
        {
            __auto_type r = _mv_384.data.dl3.f0;
            __auto_type a = _mv_384.data.dl3.f1;
            __auto_type b = _mv_384.data.dl3.f2;
            return ((howl_sriqnames_role_in_range(r, ns)) && (howl_sriqnames_name_in_range(a, nc)) && (howl_sriqnames_name_in_range(b, nc)));
        }
        case howl_types_DlClause_dl4:
        {
            __auto_type d = _mv_384.data.dl4;
            return ((howl_sriqnames_name_in_range(d.sub, nc)) && (howl_sriqnames_role_in_range(d.role, ns)) && (howl_sriqnames_filler_in_range(d.filler, nc)) && (howl_sriqnames_role_in_range(d.srole, ns)));
        }
        case howl_types_DlClause_dl5:
        {
            __auto_type b = _mv_384.data.dl5.f0;
            __auto_type r = _mv_384.data.dl5.f1;
            return (howl_sriqnames_name_in_range(b, nc) && howl_sriqnames_role_in_range(r, ns));
        }
        case howl_types_DlClause_dl6:
        {
            __auto_type r = _mv_384.data.dl6.f0;
            __auto_type b = _mv_384.data.dl6.f1;
            return (howl_sriqnames_role_in_range(r, ns) && howl_sriqnames_name_in_range(b, nc));
        }
        case howl_types_DlClause_dl7:
        {
            __auto_type a = _mv_384.data.dl7.f0;
            __auto_type b = _mv_384.data.dl7.f1;
            return (howl_sriqnames_role_in_range(a, ns) && howl_sriqnames_role_in_range(b, ns));
        }
        case howl_types_DlClause_dl8:
        {
            __auto_type a = _mv_384.data.dl8.f0;
            __auto_type b = _mv_384.data.dl8.f1;
            return (howl_sriqnames_role_in_range(a, ns) && howl_sriqnames_role_in_range(b, ns));
        }
        case howl_types_DlClause_dl9:
        {
            __auto_type a = _mv_384.data.dl9.f0;
            __auto_type b = _mv_384.data.dl9.f1;
            return (howl_sriqnames_role_in_range(a, ns) && howl_sriqnames_role_in_range(b, ns));
        }
        case howl_types_DlClause_dl10:
        {
            __auto_type b = _mv_384.data.dl10.f1;
            return howl_sriqnames_name_in_range(b, nc);
        }
        case howl_types_DlClause_dl11:
        {
            __auto_type b = _mv_384.data.dl11.f0;
            return howl_sriqnames_name_in_range(b, nc);
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_string howl_sriqnames_concepts_ordered(slop_arena* arena, slop_list_howl_sroiq_SConcept cs) {
    {
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 1;
        while (i < ((int64_t)(((int64_t)((cs).len))))) {
            if (howl_sroiq_sc_cmp(howl_sriqnames_sc_at_n(cs, (i - 1)), howl_sriqnames_sc_at_n(cs, i)) >= 0) {
                (void)(({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("A ids out of key order at "), int_to_string(arena, i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
            i = (i + 1);
        }
        return bad;
    }
}

slop_list_string howl_sriqnames_sroles_ordered(slop_arena* arena, slop_list_howl_types_DRole rs, slop_list_option_howl_types_DName bs) {
    {
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 1;
        while (i < ((int64_t)(((int64_t)((rs).len))))) {
            if (howl_sriqnames_then_cmp(howl_sriqnames_drole_cmp(howl_sriqnames_role_at(rs, (i - 1)), howl_sriqnames_role_at(rs, i)), howl_sriqnames_filler_cmp(howl_sriqnames_fill_at(bs, (i - 1)), howl_sriqnames_fill_at(bs, i))) >= 0) {
                (void)(({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("S ids out of key order at "), int_to_string(arena, i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
            i = (i + 1);
        }
        return bad;
    }
}

slop_list_string howl_sriqnames_clauses_ordered(slop_arena* arena, slop_list_howl_types_DlClause cs) {
    {
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 1;
        while (i < ((int64_t)(((int64_t)((cs).len))))) {
            if (howl_sriqnames_dl_cmp(howl_sriqnames_clause_at(cs, (i - 1)), howl_sriqnames_clause_at(cs, i)) >= 0) {
                (void)(({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("clauses out of order at "), int_to_string(arena, i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
            i = (i + 1);
        }
        return bad;
    }
}

slop_list_string howl_sriqnames_ids_in_range(slop_arena* arena, howl_sriqnames_SriqNormal n) {
    {
        __auto_type nc = ((int64_t)(((int64_t)((n.concepts).len))));
        __auto_type ns = ((int64_t)(((int64_t)((n.sroles).len))));
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = n.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(howl_sriqnames_clause_in_range(c, nc, ns))) {
                    (void)(({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("an id out of range: "), howl_sriqnames_render_dl_ids(arena, c))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return bad;
    }
}

uint8_t howl_sriqnames_witness_count_ok(howl_types_DlClause c) {
    __auto_type _mv_385 = c;
    switch (_mv_385.tag) {
        case howl_types_DlClause_dl2:
        {
            __auto_type d = _mv_385.data.dl2;
            return (((int64_t)(((int64_t)((d.fns).len)))) == ((int64_t)(d.count)));
        }
        default: {
            return 1;
        }
    }
}

slop_list_int howl_sriqnames_clause_fns(slop_arena* arena, howl_types_DlClause c) {
    __auto_type _mv_386 = c;
    switch (_mv_386.tag) {
        case howl_types_DlClause_dl2:
        {
            __auto_type d = _mv_386.data.dl2;
            return d.fns;
        }
        default: {
            return ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        }
    }
}

slop_list_string howl_sriqnames_fns_dense(slop_arena* arena, howl_sriqnames_SriqNormal n) {
    {
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t next = 0;
        {
            __auto_type _coll = n.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(howl_sriqnames_witness_count_ok(c))) {
                    (void)(({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("a DL2 without one function symbol per witness: "), howl_sriqnames_render_dl_ids(arena, c))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                {
                    __auto_type _coll = howl_sriqnames_clause_fns(arena, c);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type f = _coll.data[_i];
                        if (((int64_t)(f)) != next) {
                            (void)(({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("function symbols not dense: "), howl_sriqnames_render_dl_ids(arena, c))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                        next = (next + 1);
                    }
                }
            }
        }
        if (next != ((int64_t)(n.fns))) {
            (void)(({ __auto_type _lst_p = &(bad); __auto_type _item = (SLOP_STR("the function symbol count disagrees with the clauses")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        return bad;
    }
}

slop_list_string howl_sriqnames_fresh_not_signature(slop_arena* arena, howl_sriqnames_SriqNormal n) {
    {
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = n.concepts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                __auto_type _mv_387 = c;
                switch (_mv_387.tag) {
                    case howl_sroiq_SConcept_sc_name:
                    {
                        __auto_type _ = _mv_387.data.sc_name;
                        ({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("a fresh name for a class name: "), howl_sroiq_render_sconcept(arena, c))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

slop_list_string howl_sriqnames_sriq_invariants(slop_arena* arena, howl_sriqnames_SriqNormal n) {
    {
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = howl_sriqnames_concepts_ordered(arena, n.concepts);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(bad); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = howl_sriqnames_sroles_ordered(arena, n.sroles, n.sfills);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(bad); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = howl_sriqnames_clauses_ordered(arena, n.clauses);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(bad); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = howl_sriqnames_ids_in_range(arena, n);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(bad); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = howl_sriqnames_fns_dense(arena, n);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(bad); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = howl_sriqnames_fresh_not_signature(arena, n);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(bad); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return bad;
    }
}

