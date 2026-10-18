#include "../runtime/slop_runtime.h"
#include "slop_sriqclauses.h"

uint32_t howl_sriqclauses_no_id(void);
int64_t howl_sriqclauses_cmp_int(int64_t a, int64_t b);
howl_types_Lit howl_sriqclauses_lit_at(slop_list_howl_types_Lit xs, int64_t i);
howl_types_Clause howl_sriqclauses_clause_at(slop_list_howl_types_Clause xs, int64_t i, howl_types_Clause fallback);
slop_list_howl_types_Lit howl_sriqclauses_lits1(slop_arena* arena, howl_types_Lit a);
slop_list_howl_types_Lit howl_sriqclauses_lits2(slop_arena* arena, howl_types_Lit a, howl_types_Lit b);
slop_list_howl_types_Clause howl_sriqclauses_one(slop_arena* arena, howl_types_Clause c);
uint8_t howl_sriqclauses_ends_with(slop_list_howl_types_Lit xs, howl_types_Lit l);
slop_list_howl_types_Lit howl_sriqclauses_lit_set(slop_arena* arena, slop_list_howl_types_Lit xs);
howl_types_Clause howl_sriqclauses_make_clause(slop_arena* arena, slop_list_howl_types_Lit body, slop_list_howl_types_Lit head);
int64_t howl_sriqclauses_lits_cmp(slop_list_howl_types_Lit a, slop_list_howl_types_Lit b);
int64_t howl_sriqclauses_clause_cmp(howl_types_Clause a, howl_types_Clause b);
uint8_t howl_sriqclauses_clause_eq(howl_types_Clause a, howl_types_Clause b);
uint8_t howl_sriqclauses_ends_with_clause(slop_list_howl_types_Clause xs, howl_types_Clause c);
slop_list_howl_types_Clause howl_sriqclauses_clause_set(slop_arena* arena, slop_list_howl_types_Clause xs);
slop_list_howl_types_DName howl_sriqclauses_filler_names(slop_arena* arena, howl_types_DName sub, slop_option_howl_types_DName filler);
slop_list_howl_types_DName howl_sriqclauses_names_of(slop_arena* arena, slop_list_howl_types_DName ns);
slop_list_howl_types_DName howl_sriqclauses_dl1_names(slop_arena* arena, howl_types_Dl1 d);
slop_list_howl_types_DName howl_sriqclauses_two_names(slop_arena* arena, howl_types_DName a, howl_types_DName b);
slop_list_howl_types_DName howl_sriqclauses_one_name(slop_arena* arena, howl_types_DName a);
slop_list_howl_types_DName howl_sriqclauses_dl_names(slop_arena* arena, howl_types_DlClause c);
slop_list_howl_types_DRole howl_sriqclauses_roles_of(slop_arena* arena, howl_types_DRole a, slop_option_howl_types_DRole b);
slop_list_howl_types_DRole howl_sriqclauses_dl_roles(slop_arena* arena, howl_types_DlClause c);
slop_list_slop_rdf_rdf_IRI howl_sriqclauses_dl_consts(slop_arena* arena, howl_types_DlClause c);
slop_list_int howl_sriqclauses_dl_fns(slop_arena* arena, howl_types_DlClause c);
slop_rdf_rdf_IRI howl_sriqclauses_iri_at(slop_list_slop_rdf_rdf_IRI xs, int64_t i);
slop_list_slop_rdf_rdf_IRI howl_sriqclauses_distinct_iris(slop_arena* arena, slop_list_slop_rdf_rdf_IRI sorted);
slop_list_slop_rdf_rdf_IRI howl_sriqclauses_props_of(slop_arena* arena, howl_sriqnames_SriqNormal n);
uint8_t howl_sriqclauses_is_top_or_bottom(slop_rdf_rdf_IRI i);
slop_list_slop_rdf_rdf_IRI howl_sriqclauses_classes_of(slop_arena* arena, howl_sriqnames_SriqNormal n);
slop_list_slop_rdf_rdf_IRI howl_sriqclauses_without_top_bottom(slop_arena* arena, slop_list_slop_rdf_rdf_IRI xs);
slop_list_slop_rdf_rdf_IRI howl_sriqclauses_individuals_of(slop_arena* arena, howl_sriqnames_SriqNormal n);
slop_map* howl_sriqclauses_index_from(slop_arena* arena, slop_list_slop_rdf_rdf_IRI xs, int64_t base);
slop_list_howl_types_DName howl_sriqclauses_class_names(slop_arena* arena, slop_list_slop_rdf_rdf_IRI classes, int64_t nfresh);
slop_list_howl_types_DRole howl_sriqclauses_role_names(slop_arena* arena, slop_list_slop_rdf_rdf_IRI props, slop_list_slop_rdf_rdf_IRI bars, int64_t nsub);
howl_sriqclauses_SriqIds howl_sriqclauses_build_sriq_ids(slop_arena* arena, howl_sriqnames_SriqNormal n);
uint32_t howl_sriqclauses_lookup(slop_map* m, slop_rdf_rdf_IRI i);
uint32_t howl_sriqclauses_class_id(howl_sriqclauses_SriqIds ids, howl_types_DName b);
uint32_t howl_sriqclauses_role_id(howl_sriqclauses_SriqIds ids, howl_types_DRole r);
uint32_t howl_sriqclauses_const_id(howl_sriqclauses_SriqIds ids, slop_rdf_rdf_IRI o);
uint8_t howl_sriqclauses_name_covered(howl_sriqclauses_SriqIds ids, howl_types_DName b);
uint8_t howl_sriqclauses_role_covered(howl_sriqclauses_SriqIds ids, howl_types_DRole r);
slop_string howl_sriqclauses_dname_text(slop_arena* arena, howl_types_DName b);
slop_string howl_sriqclauses_drole_text(slop_arena* arena, howl_types_DRole r);
slop_list_string howl_sriqclauses_clause_misses(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DlClause c);
slop_list_string howl_sriqclauses_uncovered(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_sriqnames_SriqNormal n);
slop_list_howl_types_Lit howl_sriqclauses_unary_x(slop_arena* arena, howl_sriqclauses_SriqIds ids, slop_list_howl_types_DName ns);
slop_list_howl_types_Clause howl_sriqclauses_expand_dl1(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Dl1 d);
slop_list_howl_types_Clause howl_sriqclauses_dl2_successor(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Dl2 d, slop_list_howl_types_Lit b1, int64_t f);
slop_list_howl_types_Clause howl_sriqclauses_dl2_successors(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Dl2 d);
uint32_t howl_sriqclauses_fn_at(slop_list_int fs, int64_t i);
slop_list_howl_types_Clause howl_sriqclauses_neq_after(slop_arena* arena, slop_list_howl_types_Lit b1, slop_list_int fs, int64_t i);
slop_list_howl_types_Clause howl_sriqclauses_expand_dl2(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Dl2 d);
slop_list_howl_types_Clause howl_sriqclauses_expand_dl3(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DRole s, howl_types_DName b1, howl_types_DName b2);
howl_types_Clause howl_sriqclauses_dl4_sub(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Dl4 d);
slop_list_howl_types_Lit howl_sriqclauses_dl4_body(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Dl4 d);
slop_list_howl_types_Lit howl_sriqclauses_eq_after(slop_arena* arena, int64_t i, int64_t m);
slop_list_howl_types_Lit howl_sriqclauses_dl4_head(slop_arena* arena, howl_types_Dl4 d);
slop_list_howl_types_Clause howl_sriqclauses_expand_dl4(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Dl4 d);
slop_list_howl_types_Clause howl_sriqclauses_expand_dl5(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DName b, howl_types_DRole s);
slop_list_howl_types_Clause howl_sriqclauses_expand_dl6(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DRole s, howl_types_DName b);
slop_list_howl_types_Clause howl_sriqclauses_expand_dl7(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DRole s1, howl_types_DRole s2);
slop_list_howl_types_Clause howl_sriqclauses_expand_dl8(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DRole s1, howl_types_DRole s2);
slop_list_howl_types_Clause howl_sriqclauses_expand_dl9(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DRole s1, howl_types_DRole s2);
slop_list_howl_types_Clause howl_sriqclauses_expand_dl10(slop_arena* arena, howl_sriqclauses_SriqIds ids, slop_rdf_rdf_IRI o, howl_types_DName b);
slop_list_howl_types_Clause howl_sriqclauses_expand_dl11(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DName b, slop_rdf_rdf_IRI o);
slop_list_howl_types_Clause howl_sriqclauses_expand_clause(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DlClause c);
slop_list_howl_types_Clause howl_sriqclauses_ontology_clauses(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_sriqnames_SriqNormal n);
slop_result_howl_sriqclauses_SriqClauses_string howl_sriqclauses_sriq_clauses(slop_arena* arena, howl_sriqnames_SriqNormal n);
uint8_t howl_sriqclauses_is_x(howl_types_ATerm t);
uint8_t howl_sriqclauses_is_z(howl_types_ATerm t);
uint8_t howl_sriqclauses_is_fx(howl_types_ATerm t);
uint8_t howl_sriqclauses_dl_aterm(howl_types_ATerm t);
uint8_t howl_sriqclauses_dl_body_atom(howl_types_Lit l);
uint8_t howl_sriqclauses_dl_head_lit(howl_types_Lit l);
uint8_t howl_sriqclauses_dl_clause_shape(howl_types_Clause c);
uint8_t howl_sriqclauses_canonical_aterm(howl_types_ATerm t);
uint8_t howl_sriqclauses_canonical_lit(howl_types_Lit l);
uint8_t howl_sriqclauses_lits_canonical(slop_list_howl_types_Lit ls);
uint8_t howl_sriqclauses_clause_canonical(howl_types_Clause c);
uint8_t howl_sriqclauses_aterm_in_range(howl_sriqclauses_SriqIds ids, howl_types_ATerm t);
uint8_t howl_sriqclauses_lit_in_range(howl_sriqclauses_SriqIds ids, howl_types_Lit l);
uint8_t howl_sriqclauses_clause_in_range(howl_sriqclauses_SriqIds ids, howl_types_Clause c);
uint8_t howl_sriqclauses_tables_round_trip(howl_sriqclauses_SriqIds ids);
uint8_t howl_sriqclauses_class_in_place(howl_sriqclauses_SriqIds ids, int64_t i, howl_types_DName b, slop_rdf_rdf_IRI prev);
uint8_t howl_sriqclauses_classes_in_order(howl_sriqclauses_SriqIds ids);
uint8_t howl_sriqclauses_prop_after(howl_types_DRole prev, slop_rdf_rdf_IRI p);
uint8_t howl_sriqclauses_bar_after(howl_types_DRole prev, slop_rdf_rdf_IRI p);
uint8_t howl_sriqclauses_role_in_place(howl_sriqclauses_SriqIds ids, int64_t i, howl_types_DRole r, howl_types_DRole prev);
uint8_t howl_sriqclauses_roles_in_order(howl_sriqclauses_SriqIds ids);
uint8_t howl_sriqclauses_consts_in_order(howl_sriqclauses_SriqIds ids);
slop_list_string howl_sriqclauses_ids_dense(slop_arena* arena, howl_sriqclauses_SriqClauses sc);
slop_string howl_sriqclauses_class_text(slop_arena* arena, howl_sriqclauses_SriqIds ids, uint32_t b);
slop_string howl_sriqclauses_role_text(slop_arena* arena, howl_sriqclauses_SriqIds ids, uint32_t r);
slop_string howl_sriqclauses_const_text(slop_arena* arena, howl_sriqclauses_SriqIds ids, uint32_t u);
slop_string howl_sriqclauses_fsym_text(slop_arena* arena, uint32_t f);
slop_string howl_sriqclauses_applied(slop_arena* arena, slop_string f, slop_string arg);
slop_string howl_sriqclauses_render_aterm(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_ATerm t);
slop_string howl_sriqclauses_infix(slop_arena* arena, slop_string a, slop_string op, slop_string b);
slop_string howl_sriqclauses_render_lit(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Lit l);
slop_string howl_sriqclauses_render_lits(slop_arena* arena, howl_sriqclauses_SriqIds ids, slop_list_howl_types_Lit ls, slop_string sep, slop_string empty);
slop_string howl_sriqclauses_render_clause(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Clause c);
slop_list_string howl_sriqclauses_render_clauses(slop_arena* arena, howl_sriqclauses_SriqClauses sc);

typedef struct { slop_list_howl_types_Lit xs; } howl_sriqclauses__lambda_395_env_t;

static int64_t howl_sriqclauses__lambda_395(howl_sriqclauses__lambda_395_env_t* _env, int64_t i, int64_t j) { return howl_types_lit_cmp(howl_sriqclauses_lit_at(_env->xs, i), howl_sriqclauses_lit_at(_env->xs, j)); }

typedef struct { slop_list_howl_types_Clause xs; howl_types_Clause none_such; } howl_sriqclauses__lambda_396_env_t;

static int64_t howl_sriqclauses__lambda_396(howl_sriqclauses__lambda_396_env_t* _env, int64_t i, int64_t j) { return howl_sriqclauses_clause_cmp(howl_sriqclauses_clause_at(_env->xs, i, _env->none_such), howl_sriqclauses_clause_at(_env->xs, j, _env->none_such)); }

uint32_t howl_sriqclauses_no_id(void) {
    return ((uint32_t)(4294967295));
}

int64_t howl_sriqclauses_cmp_int(int64_t a, int64_t b) {
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

howl_types_Lit howl_sriqclauses_lit_at(slop_list_howl_types_Lit xs, int64_t i) {
    __auto_type _mv_393 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_Lit _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_393.has_value) {
        __auto_type l = _mv_393.value;
        return l;
    } else if (!_mv_393.has_value) {
        return howl_types_atom1(howl_sriqclauses_no_id(), howl_types_at_x());
    }
    SLOP_UNREACHABLE();
}

howl_types_Clause howl_sriqclauses_clause_at(slop_list_howl_types_Clause xs, int64_t i, howl_types_Clause fallback) {
    __auto_type _mv_394 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_Clause _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_394.has_value) {
        __auto_type c = _mv_394.value;
        return c;
    } else if (!_mv_394.has_value) {
        return fallback;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Lit howl_sriqclauses_lits1(slop_arena* arena, howl_types_Lit a) {
    {
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

slop_list_howl_types_Lit howl_sriqclauses_lits2(slop_arena* arena, howl_types_Lit a, howl_types_Lit b) {
    {
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

slop_list_howl_types_Clause howl_sriqclauses_one(slop_arena* arena, howl_types_Clause c) {
    {
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

uint8_t howl_sriqclauses_ends_with(slop_list_howl_types_Lit xs, howl_types_Lit l) {
    {
        __auto_type n = ((int64_t)(((int64_t)((xs).len))));
        return ((n > 0) && howl_types_lit_eq(howl_sriqclauses_lit_at(xs, (n - 1)), l));
    }
}

slop_list_howl_types_Lit howl_sriqclauses_lit_set(slop_arena* arena, slop_list_howl_types_Lit xs) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ howl_sriqclauses__lambda_395_env_t* howl_sriqclauses__lambda_395_env = (howl_sriqclauses__lambda_395_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqclauses__lambda_395_env_t)); *howl_sriqclauses__lambda_395_env = (howl_sriqclauses__lambda_395_env_t){ .xs = xs }; (slop_closure_t){ (void*)howl_sriqclauses__lambda_395, (void*)howl_sriqclauses__lambda_395_env }; }));
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type l = howl_sriqclauses_lit_at(xs, k);
                    if (!(howl_sriqclauses_ends_with(out, l))) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

howl_types_Clause howl_sriqclauses_make_clause(slop_arena* arena, slop_list_howl_types_Lit body, slop_list_howl_types_Lit head) {
    return ((howl_types_Clause){.body = howl_sriqclauses_lit_set(arena, body), .head = howl_sriqclauses_lit_set(arena, head)});
}

int64_t howl_sriqclauses_lits_cmp(slop_list_howl_types_Lit a, slop_list_howl_types_Lit b) {
    {
        __auto_type na = ((int64_t)(((int64_t)((a).len))));
        __auto_type nb = ((int64_t)(((int64_t)((b).len))));
        __auto_type n = ((na) < (nb) ? (na) : (nb));
        int64_t i = 0;
        int64_t r = 0;
        while ((i < n) && (r == 0)) {
            r = howl_types_lit_cmp(howl_sriqclauses_lit_at(a, i), howl_sriqclauses_lit_at(b, i));
            i = (i + 1);
        }
        if (r != 0) {
            return r;
        } else {
            return howl_sriqclauses_cmp_int(na, nb);
        }
    }
}

int64_t howl_sriqclauses_clause_cmp(howl_types_Clause a, howl_types_Clause b) {
    {
        __auto_type c = howl_sriqclauses_lits_cmp(a.body, b.body);
        if (c != 0) {
            return c;
        } else {
            return howl_sriqclauses_lits_cmp(a.head, b.head);
        }
    }
}

uint8_t howl_sriqclauses_clause_eq(howl_types_Clause a, howl_types_Clause b) {
    return (howl_sriqclauses_clause_cmp(a, b) == 0);
}

uint8_t howl_sriqclauses_ends_with_clause(slop_list_howl_types_Clause xs, howl_types_Clause c) {
    {
        __auto_type n = ((int64_t)(((int64_t)((xs).len))));
        return ((n > 0) && howl_sriqclauses_clause_eq(howl_sriqclauses_clause_at(xs, (n - 1), c), c));
    }
}

slop_list_howl_types_Clause howl_sriqclauses_clause_set(slop_arena* arena, slop_list_howl_types_Clause xs) {
    {
        __auto_type none_such = ((howl_types_Clause){.body = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .head = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ howl_sriqclauses__lambda_396_env_t* howl_sriqclauses__lambda_396_env = (howl_sriqclauses__lambda_396_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqclauses__lambda_396_env_t)); *howl_sriqclauses__lambda_396_env = (howl_sriqclauses__lambda_396_env_t){ .xs = xs, .none_such = none_such }; (slop_closure_t){ (void*)howl_sriqclauses__lambda_396, (void*)howl_sriqclauses__lambda_396_env }; }));
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type c = howl_sriqclauses_clause_at(xs, k, none_such);
                    if (!(howl_sriqclauses_ends_with_clause(out, c))) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_types_DName howl_sriqclauses_filler_names(slop_arena* arena, howl_types_DName sub, slop_option_howl_types_DName filler) {
    {
        __auto_type out = ((slop_list_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (sub); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        __auto_type _mv_397 = filler;
        if (_mv_397.has_value) {
            __auto_type b = _mv_397.value;
            ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (!_mv_397.has_value) {
        }
        return out;
    }
}

slop_list_howl_types_DName howl_sriqclauses_names_of(slop_arena* arena, slop_list_howl_types_DName ns) {
    {
        __auto_type out = ((slop_list_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_types_DName howl_sriqclauses_dl1_names(slop_arena* arena, howl_types_Dl1 d) {
    {
        __auto_type out = howl_sriqclauses_names_of(arena, d.body);
        {
            __auto_type _coll = d.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (n); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_types_DName howl_sriqclauses_two_names(slop_arena* arena, howl_types_DName a, howl_types_DName b) {
    {
        __auto_type out = ((slop_list_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

slop_list_howl_types_DName howl_sriqclauses_one_name(slop_arena* arena, howl_types_DName a) {
    {
        __auto_type out = ((slop_list_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

slop_list_howl_types_DName howl_sriqclauses_dl_names(slop_arena* arena, howl_types_DlClause c) {
    __auto_type _mv_398 = c;
    switch (_mv_398.tag) {
        case howl_types_DlClause_dl1:
        {
            __auto_type d = _mv_398.data.dl1;
            return howl_sriqclauses_dl1_names(arena, d);
        }
        case howl_types_DlClause_dl2:
        {
            __auto_type d = _mv_398.data.dl2;
            return howl_sriqclauses_filler_names(arena, d.sub, d.filler);
        }
        case howl_types_DlClause_dl3:
        {
            __auto_type b1 = _mv_398.data.dl3.f1;
            __auto_type b2 = _mv_398.data.dl3.f2;
            return howl_sriqclauses_two_names(arena, b1, b2);
        }
        case howl_types_DlClause_dl4:
        {
            __auto_type d = _mv_398.data.dl4;
            return howl_sriqclauses_filler_names(arena, d.sub, d.filler);
        }
        case howl_types_DlClause_dl5:
        {
            __auto_type b = _mv_398.data.dl5.f0;
            return howl_sriqclauses_one_name(arena, b);
        }
        case howl_types_DlClause_dl6:
        {
            __auto_type b = _mv_398.data.dl6.f1;
            return howl_sriqclauses_one_name(arena, b);
        }
        case howl_types_DlClause_dl7:
        {
            return ((slop_list_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        }
        case howl_types_DlClause_dl8:
        {
            return ((slop_list_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        }
        case howl_types_DlClause_dl9:
        {
            return ((slop_list_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        }
        case howl_types_DlClause_dl10:
        {
            __auto_type b = _mv_398.data.dl10.f1;
            return howl_sriqclauses_one_name(arena, b);
        }
        case howl_types_DlClause_dl11:
        {
            __auto_type b = _mv_398.data.dl11.f0;
            return howl_sriqclauses_one_name(arena, b);
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_DRole howl_sriqclauses_roles_of(slop_arena* arena, howl_types_DRole a, slop_option_howl_types_DRole b) {
    {
        __auto_type out = ((slop_list_howl_types_DRole){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        __auto_type _mv_399 = b;
        if (_mv_399.has_value) {
            __auto_type r = _mv_399.value;
            ({ __auto_type _lst_p = &(out); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (!_mv_399.has_value) {
        }
        return out;
    }
}

slop_list_howl_types_DRole howl_sriqclauses_dl_roles(slop_arena* arena, howl_types_DlClause c) {
    __auto_type _mv_400 = c;
    switch (_mv_400.tag) {
        case howl_types_DlClause_dl1:
        {
            __auto_type _ = _mv_400.data.dl1;
            return ((slop_list_howl_types_DRole){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        }
        case howl_types_DlClause_dl2:
        {
            __auto_type d = _mv_400.data.dl2;
            return howl_sriqclauses_roles_of(arena, d.role, ((slop_option_howl_types_DRole){.has_value = false}));
        }
        case howl_types_DlClause_dl3:
        {
            __auto_type s = _mv_400.data.dl3.f0;
            return howl_sriqclauses_roles_of(arena, s, ((slop_option_howl_types_DRole){.has_value = false}));
        }
        case howl_types_DlClause_dl4:
        {
            __auto_type d = _mv_400.data.dl4;
            return howl_sriqclauses_roles_of(arena, d.role, (slop_option_howl_types_DRole){.has_value = 1, .value = d.srole});
        }
        case howl_types_DlClause_dl5:
        {
            __auto_type s = _mv_400.data.dl5.f1;
            return howl_sriqclauses_roles_of(arena, s, ((slop_option_howl_types_DRole){.has_value = false}));
        }
        case howl_types_DlClause_dl6:
        {
            __auto_type s = _mv_400.data.dl6.f0;
            return howl_sriqclauses_roles_of(arena, s, ((slop_option_howl_types_DRole){.has_value = false}));
        }
        case howl_types_DlClause_dl7:
        {
            __auto_type s1 = _mv_400.data.dl7.f0;
            __auto_type s2 = _mv_400.data.dl7.f1;
            return howl_sriqclauses_roles_of(arena, s1, (slop_option_howl_types_DRole){.has_value = 1, .value = s2});
        }
        case howl_types_DlClause_dl8:
        {
            __auto_type s1 = _mv_400.data.dl8.f0;
            __auto_type s2 = _mv_400.data.dl8.f1;
            return howl_sriqclauses_roles_of(arena, s1, (slop_option_howl_types_DRole){.has_value = 1, .value = s2});
        }
        case howl_types_DlClause_dl9:
        {
            __auto_type s1 = _mv_400.data.dl9.f0;
            __auto_type s2 = _mv_400.data.dl9.f1;
            return howl_sriqclauses_roles_of(arena, s1, (slop_option_howl_types_DRole){.has_value = 1, .value = s2});
        }
        case howl_types_DlClause_dl10:
        {
            return ((slop_list_howl_types_DRole){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        }
        case howl_types_DlClause_dl11:
        {
            return ((slop_list_howl_types_DRole){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_slop_rdf_rdf_IRI howl_sriqclauses_dl_consts(slop_arena* arena, howl_types_DlClause c) {
    {
        __auto_type out = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_401 = c;
        switch (_mv_401.tag) {
            case howl_types_DlClause_dl10:
            {
                __auto_type o = _mv_401.data.dl10.f0;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_types_DlClause_dl11:
            {
                __auto_type o = _mv_401.data.dl11.f1;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            default: {
                break;
            }
        }
        return out;
    }
}

slop_list_int howl_sriqclauses_dl_fns(slop_arena* arena, howl_types_DlClause c) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_402 = c;
        switch (_mv_402.tag) {
            case howl_types_DlClause_dl2:
            {
                __auto_type d = _mv_402.data.dl2;
                {
                    __auto_type _coll = d.fns;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type f = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            default: {
                break;
            }
        }
        return out;
    }
}

slop_rdf_rdf_IRI howl_sriqclauses_iri_at(slop_list_slop_rdf_rdf_IRI xs, int64_t i) {
    __auto_type _mv_403 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_slop_rdf_rdf_IRI _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_403.has_value) {
        __auto_type v = _mv_403.value;
        return v;
    } else if (!_mv_403.has_value) {
        return ((slop_rdf_rdf_IRI){.value = SLOP_STR("")});
    }
    SLOP_UNREACHABLE();
}

slop_list_slop_rdf_rdf_IRI howl_sriqclauses_distinct_iris(slop_arena* arena, slop_list_slop_rdf_rdf_IRI sorted) {
    {
        __auto_type out = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = sorted;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                {
                    __auto_type n = ((int64_t)(((int64_t)((out).len))));
                    if ((n == 0) || (howl_canon_iri_cmp(howl_sriqclauses_iri_at(out, (n - 1)), i) != 0)) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

slop_list_slop_rdf_rdf_IRI howl_sriqclauses_props_of(slop_arena* arena, howl_sriqnames_SriqNormal n) {
    {
        __auto_type ps = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = n.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type _coll = howl_sriqclauses_dl_roles(arena, c);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        __auto_type _mv_404 = r;
                        switch (_mv_404.tag) {
                            case howl_types_DRole_dr_prop:
                            {
                                __auto_type p = _mv_404.data.dr_prop;
                                ({ __auto_type _lst_p = &(ps); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case howl_types_DRole_dr_bar:
                            {
                                __auto_type _ = _mv_404.data.dr_bar;
                                break;
                            }
                            case howl_types_DRole_dr_sub:
                            {
                                __auto_type _ = _mv_404.data.dr_sub;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return howl_sriqclauses_distinct_iris(arena, howl_canon_sort_iris(arena, ps));
    }
}

uint8_t howl_sriqclauses_is_top_or_bottom(slop_rdf_rdf_IRI i) {
    return (string_eq(i.value, slop_rdf_vocab_OWL_THING) || string_eq(i.value, slop_rdf_vocab_OWL_NOTHING));
}

slop_list_slop_rdf_rdf_IRI howl_sriqclauses_classes_of(slop_arena* arena, howl_sriqnames_SriqNormal n) {
    {
        __auto_type cs = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = n.classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(cs); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = n.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type _coll = howl_sriqclauses_dl_names(arena, c);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type b = _coll.data[_i];
                        __auto_type _mv_405 = b;
                        switch (_mv_405.tag) {
                            case howl_types_DName_dn_class:
                            {
                                __auto_type i = _mv_405.data.dn_class;
                                ({ __auto_type _lst_p = &(cs); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case howl_types_DName_dn_fresh:
                            {
                                __auto_type _ = _mv_405.data.dn_fresh;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return howl_sriqclauses_distinct_iris(arena, howl_canon_sort_iris(arena, howl_sriqclauses_without_top_bottom(arena, cs)));
    }
}

slop_list_slop_rdf_rdf_IRI howl_sriqclauses_without_top_bottom(slop_arena* arena, slop_list_slop_rdf_rdf_IRI xs) {
    {
        __auto_type out = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                if (!(howl_sriqclauses_is_top_or_bottom(i))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

slop_list_slop_rdf_rdf_IRI howl_sriqclauses_individuals_of(slop_arena* arena, howl_sriqnames_SriqNormal n) {
    {
        __auto_type is = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = n.individuals;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(is); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = n.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type _coll = howl_sriqclauses_dl_consts(arena, c);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type o = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(is); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return howl_sriqclauses_distinct_iris(arena, howl_canon_sort_iris(arena, is));
    }
}

slop_map* howl_sriqclauses_index_from(slop_arena* arena, slop_list_slop_rdf_rdf_IRI xs, int64_t base) {
    {
        __auto_type m = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_rdf_rdf_IRI, slop_hash_slop_rdf_rdf_IRI, slop_eq_slop_rdf_rdf_IRI, SLOP_KEY_HASHED, uint32_t); slop_map_new_ptr(arena, 0, &_d); });
        int64_t i = base;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ uint32_t _val = ((uint32_t)(i)); slop_map_put(NULL, m, &(x), &_val, sizeof(_val)); }));
                i = (i + 1);
            }
        }
        return m;
    }
}

slop_list_howl_types_DName howl_sriqclauses_class_names(slop_arena* arena, slop_list_slop_rdf_rdf_IRI classes, int64_t nfresh) {
    {
        __auto_type out = ((slop_list_howl_types_DName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_types_DName){ .tag = howl_types_DName_dn_class, .data.dn_class = c })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        while (k < nfresh) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_types_DName){ .tag = howl_types_DName_dn_fresh, .data.dn_fresh = ((int64_t)(SLOP_RANGE(int64_t, k, 1, 0, 0, 0, "(Int 0 ..) at sriqclauses.slop:385:73"))) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            k = (k + 1);
        }
        return out;
    }
}

slop_list_howl_types_DRole howl_sriqclauses_role_names(slop_arena* arena, slop_list_slop_rdf_rdf_IRI props, slop_list_slop_rdf_rdf_IRI bars, int64_t nsub) {
    {
        __auto_type out = ((slop_list_howl_types_DRole){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = props;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_types_DRole){ .tag = howl_types_DRole_dr_prop, .data.dr_prop = p })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = bars;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_types_DRole){ .tag = howl_types_DRole_dr_bar, .data.dr_bar = p })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        while (k < nsub) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_types_DRole){ .tag = howl_types_DRole_dr_sub, .data.dr_sub = ((int64_t)(SLOP_RANGE(int64_t, k, 1, 0, 0, 0, "(Int 0 ..) at sriqclauses.slop:399:71"))) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            k = (k + 1);
        }
        return out;
    }
}

howl_sriqclauses_SriqIds howl_sriqclauses_build_sriq_ids(slop_arena* arena, howl_sriqnames_SriqNormal n) {
    {
        __auto_type classes = howl_sriqclauses_classes_of(arena, n);
        __auto_type consts = howl_sriqclauses_individuals_of(arena, n);
        __auto_type props = howl_sriqclauses_props_of(arena, n);
        __auto_type np = ((int64_t)(((int64_t)((props).len))));
        __auto_type nb = ((int64_t)(((int64_t)((n.bars).len))));
        return ((howl_sriqclauses_SriqIds){.class_ix = howl_sriqclauses_index_from(arena, classes, 0), .prop_ix = howl_sriqclauses_index_from(arena, props, 0), .bar_ix = howl_sriqclauses_index_from(arena, n.bars, np), .const_ix = howl_sriqclauses_index_from(arena, consts, 0), .class_of = howl_sriqclauses_class_names(arena, classes, ((int64_t)(((int64_t)((n.concepts).len))))), .role_of = howl_sriqclauses_role_names(arena, props, n.bars, ((int64_t)(((int64_t)((n.sroles).len))))), .const_of = consts, .nclass = ((int64_t)(((int64_t)((classes).len)))), .sub0 = (np + nb), .nfns = ((int64_t)(n.fns))});
    }
}

uint32_t howl_sriqclauses_lookup(slop_map* m, slop_rdf_rdf_IRI i) {
    __auto_type _mv_408 = ({ void* _ptr = slop_map_get(m, &(i)); _ptr ? (slop_option_u32){ .has_value = true, .value = *(uint32_t*)_ptr } : (slop_option_u32){ .has_value = false }; });
    if (_mv_408.has_value) {
        __auto_type v = _mv_408.value;
        return v;
    } else if (!_mv_408.has_value) {
        return howl_sriqclauses_no_id();
    }
    SLOP_UNREACHABLE();
}

uint32_t howl_sriqclauses_class_id(howl_sriqclauses_SriqIds ids, howl_types_DName b) {
    __auto_type _mv_409 = b;
    switch (_mv_409.tag) {
        case howl_types_DName_dn_class:
        {
            __auto_type i = _mv_409.data.dn_class;
            return howl_sriqclauses_lookup(ids.class_ix, i);
        }
        case howl_types_DName_dn_fresh:
        {
            __auto_type k = _mv_409.data.dn_fresh;
            return ((uint32_t)((ids.nclass + k)));
        }
    }
    SLOP_UNREACHABLE();
}

uint32_t howl_sriqclauses_role_id(howl_sriqclauses_SriqIds ids, howl_types_DRole r) {
    __auto_type _mv_410 = r;
    switch (_mv_410.tag) {
        case howl_types_DRole_dr_prop:
        {
            __auto_type p = _mv_410.data.dr_prop;
            return howl_sriqclauses_lookup(ids.prop_ix, p);
        }
        case howl_types_DRole_dr_bar:
        {
            __auto_type p = _mv_410.data.dr_bar;
            return howl_sriqclauses_lookup(ids.bar_ix, p);
        }
        case howl_types_DRole_dr_sub:
        {
            __auto_type k = _mv_410.data.dr_sub;
            return ((uint32_t)((ids.sub0 + k)));
        }
    }
    SLOP_UNREACHABLE();
}

uint32_t howl_sriqclauses_const_id(howl_sriqclauses_SriqIds ids, slop_rdf_rdf_IRI o) {
    return howl_sriqclauses_lookup(ids.const_ix, o);
}

uint8_t howl_sriqclauses_name_covered(howl_sriqclauses_SriqIds ids, howl_types_DName b) {
    __auto_type _mv_411 = b;
    switch (_mv_411.tag) {
        case howl_types_DName_dn_class:
        {
            __auto_type i = _mv_411.data.dn_class;
            return slop_map_has(ids.class_ix, &(i));
        }
        case howl_types_DName_dn_fresh:
        {
            __auto_type k = _mv_411.data.dn_fresh;
            return ((ids.nclass + k) < ((int64_t)(((int64_t)((ids.class_of).len)))));
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqclauses_role_covered(howl_sriqclauses_SriqIds ids, howl_types_DRole r) {
    __auto_type _mv_413 = r;
    switch (_mv_413.tag) {
        case howl_types_DRole_dr_prop:
        {
            __auto_type p = _mv_413.data.dr_prop;
            return slop_map_has(ids.prop_ix, &(p));
        }
        case howl_types_DRole_dr_bar:
        {
            __auto_type p = _mv_413.data.dr_bar;
            return slop_map_has(ids.bar_ix, &(p));
        }
        case howl_types_DRole_dr_sub:
        {
            __auto_type k = _mv_413.data.dr_sub;
            return ((ids.sub0 + k) < ((int64_t)(((int64_t)((ids.role_of).len)))));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_sriqclauses_dname_text(slop_arena* arena, howl_types_DName b) {
    __auto_type _mv_416 = b;
    switch (_mv_416.tag) {
        case howl_types_DName_dn_class:
        {
            __auto_type i = _mv_416.data.dn_class;
            return i.value;
        }
        case howl_types_DName_dn_fresh:
        {
            __auto_type k = _mv_416.data.dn_fresh;
            return string_concat(arena, SLOP_STR("A"), int_to_string(arena, k));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string howl_sriqclauses_drole_text(slop_arena* arena, howl_types_DRole r) {
    __auto_type _mv_417 = r;
    switch (_mv_417.tag) {
        case howl_types_DRole_dr_prop:
        {
            __auto_type p = _mv_417.data.dr_prop;
            return p.value;
        }
        case howl_types_DRole_dr_bar:
        {
            __auto_type p = _mv_417.data.dr_bar;
            return string_concat(arena, p.value, SLOP_STR("^bar"));
        }
        case howl_types_DRole_dr_sub:
        {
            __auto_type k = _mv_417.data.dr_sub;
            return string_concat(arena, SLOP_STR("S"), int_to_string(arena, k));
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_string howl_sriqclauses_clause_misses(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DlClause c) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = howl_sriqclauses_dl_names(arena, c);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                if (!(howl_sriqclauses_name_covered(ids, b))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (string_concat(arena, SLOP_STR("class "), howl_sriqclauses_dname_text(arena, b))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type _coll = howl_sriqclauses_dl_roles(arena, c);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                if (!(howl_sriqclauses_role_covered(ids, r))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (string_concat(arena, SLOP_STR("role "), howl_sriqclauses_drole_text(arena, r))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type _coll = howl_sriqclauses_dl_consts(arena, c);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                if (!(slop_map_has(ids.const_ix, &(o)))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (string_concat(arena, SLOP_STR("individual "), o.value)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        {
            __auto_type _coll = howl_sriqclauses_dl_fns(arena, c);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                if (f >= ids.nfns) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (string_concat(arena, SLOP_STR("function symbol "), int_to_string(arena, f))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

slop_list_string howl_sriqclauses_uncovered(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_sriqnames_SriqNormal n) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = n.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type _coll = howl_sriqclauses_clause_misses(arena, ids, c);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type m = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (m); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_types_Lit howl_sriqclauses_unary_x(slop_arena* arena, howl_sriqclauses_SriqIds ids, slop_list_howl_types_DName ns) {
    {
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_types_atom1(howl_sriqclauses_class_id(ids, b), howl_types_at_x())); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_types_Clause howl_sriqclauses_expand_dl1(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Dl1 d) {
    return howl_sriqclauses_one(arena, howl_sriqclauses_make_clause(arena, howl_sriqclauses_unary_x(arena, ids, d.body), howl_sriqclauses_unary_x(arena, ids, d.head)));
}

slop_list_howl_types_Clause howl_sriqclauses_dl2_successor(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Dl2 d, slop_list_howl_types_Lit b1, int64_t f) {
    {
        __auto_type fx = howl_types_at_fx(((uint32_t)(f)));
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_419 = d.filler;
        if (_mv_419.has_value) {
            __auto_type b2 = _mv_419.value;
            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqclauses_make_clause(arena, b1, howl_sriqclauses_lits1(arena, howl_types_atom1(howl_sriqclauses_class_id(ids, b2), fx)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (!_mv_419.has_value) {
        }
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqclauses_make_clause(arena, b1, howl_sriqclauses_lits1(arena, howl_types_atom2(howl_sriqclauses_role_id(ids, d.role), howl_types_at_x(), fx)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

slop_list_howl_types_Clause howl_sriqclauses_dl2_successors(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Dl2 d) {
    {
        __auto_type b1 = howl_sriqclauses_lits1(arena, howl_types_atom1(howl_sriqclauses_class_id(ids, d.sub), howl_types_at_x()));
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = d.fns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                {
                    __auto_type _coll = howl_sriqclauses_dl2_successor(arena, ids, d, b1, f);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

uint32_t howl_sriqclauses_fn_at(slop_list_int fs, int64_t i) {
    __auto_type _mv_420 = ({ __auto_type _lst = fs; size_t _idx = (size_t)i; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_420.has_value) {
        __auto_type f = _mv_420.value;
        return ((uint32_t)(f));
    } else if (!_mv_420.has_value) {
        return howl_sriqclauses_no_id();
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Clause howl_sriqclauses_neq_after(slop_arena* arena, slop_list_howl_types_Lit b1, slop_list_int fs, int64_t i) {
    {
        __auto_type fi = howl_types_at_fx(howl_sriqclauses_fn_at(fs, i));
        __auto_type n = ((int64_t)(((int64_t)((fs).len))));
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = (i + 1);
        while (j < n) {
            {
                __auto_type l = howl_types_neq_lit(fi, howl_types_at_fx(howl_sriqclauses_fn_at(fs, j)));
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqclauses_make_clause(arena, b1, howl_sriqclauses_lits1(arena, l))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                j = (j + 1);
            }
        }
        return out;
    }
}

slop_list_howl_types_Clause howl_sriqclauses_expand_dl2(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Dl2 d) {
    {
        __auto_type b1 = howl_sriqclauses_lits1(arena, howl_types_atom1(howl_sriqclauses_class_id(ids, d.sub), howl_types_at_x()));
        __auto_type n = ((int64_t)(((int64_t)((d.fns).len))));
        __auto_type out = howl_sriqclauses_dl2_successors(arena, ids, d);
        int64_t i = 0;
        while (i < n) {
            {
                __auto_type _coll = howl_sriqclauses_neq_after(arena, b1, d.fns, i);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type c = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
            i = (i + 1);
        }
        return out;
    }
}

slop_list_howl_types_Clause howl_sriqclauses_expand_dl3(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DRole s, howl_types_DName b1, howl_types_DName b2) {
    {
        __auto_type z1 = howl_types_at_z(((uint32_t)(1)));
        return howl_sriqclauses_one(arena, howl_sriqclauses_make_clause(arena, howl_sriqclauses_lits2(arena, howl_types_atom2(howl_sriqclauses_role_id(ids, s), z1, howl_types_at_x()), howl_types_atom1(howl_sriqclauses_class_id(ids, b1), howl_types_at_x())), howl_sriqclauses_lits1(arena, howl_types_atom1(howl_sriqclauses_class_id(ids, b2), z1))));
    }
}

howl_types_Clause howl_sriqclauses_dl4_sub(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Dl4 d) {
    {
        __auto_type z1 = howl_types_at_z(((uint32_t)(1)));
        __auto_type sx = howl_types_atom2(howl_sriqclauses_role_id(ids, d.role), z1, howl_types_at_x());
        __auto_type head = howl_sriqclauses_lits1(arena, howl_types_atom2(howl_sriqclauses_role_id(ids, d.srole), z1, howl_types_at_x()));
        __auto_type _mv_421 = d.filler;
        if (_mv_421.has_value) {
            __auto_type b2 = _mv_421.value;
            return howl_sriqclauses_make_clause(arena, howl_sriqclauses_lits2(arena, sx, howl_types_atom1(howl_sriqclauses_class_id(ids, b2), howl_types_at_x())), head);
        } else if (!_mv_421.has_value) {
            return howl_sriqclauses_make_clause(arena, howl_sriqclauses_lits1(arena, sx), head);
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_howl_types_Lit howl_sriqclauses_dl4_body(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Dl4 d) {
    {
        __auto_type sb = howl_sriqclauses_role_id(ids, d.srole);
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 1;
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_types_atom1(howl_sriqclauses_class_id(ids, d.sub), howl_types_at_x())); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        while (i <= (d.count + 1)) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_types_atom2(sb, howl_types_at_x(), howl_types_at_z(((uint32_t)(i))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            i = (i + 1);
        }
        return out;
    }
}

slop_list_howl_types_Lit howl_sriqclauses_eq_after(slop_arena* arena, int64_t i, int64_t m) {
    {
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = (i + 1);
        while (j <= m) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_types_eq_lit(howl_types_at_z(((uint32_t)(i))), howl_types_at_z(((uint32_t)(j))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            j = (j + 1);
        }
        return out;
    }
}

slop_list_howl_types_Lit howl_sriqclauses_dl4_head(slop_arena* arena, howl_types_Dl4 d) {
    {
        __auto_type m = (d.count + 1);
        __auto_type out = ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 1;
        while (i <= m) {
            {
                __auto_type _coll = howl_sriqclauses_eq_after(arena, i, m);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type l = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
            i = (i + 1);
        }
        return out;
    }
}

slop_list_howl_types_Clause howl_sriqclauses_expand_dl4(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Dl4 d) {
    {
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqclauses_dl4_sub(arena, ids, d)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqclauses_make_clause(arena, howl_sriqclauses_dl4_body(arena, ids, d), howl_sriqclauses_dl4_head(arena, d))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

slop_list_howl_types_Clause howl_sriqclauses_expand_dl5(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DName b, howl_types_DRole s) {
    return howl_sriqclauses_one(arena, howl_sriqclauses_make_clause(arena, howl_sriqclauses_lits1(arena, howl_types_atom1(howl_sriqclauses_class_id(ids, b), howl_types_at_x())), howl_sriqclauses_lits1(arena, howl_types_atom2(howl_sriqclauses_role_id(ids, s), howl_types_at_x(), howl_types_at_x()))));
}

slop_list_howl_types_Clause howl_sriqclauses_expand_dl6(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DRole s, howl_types_DName b) {
    return howl_sriqclauses_one(arena, howl_sriqclauses_make_clause(arena, howl_sriqclauses_lits1(arena, howl_types_atom2(howl_sriqclauses_role_id(ids, s), howl_types_at_x(), howl_types_at_x())), howl_sriqclauses_lits1(arena, howl_types_atom1(howl_sriqclauses_class_id(ids, b), howl_types_at_x()))));
}

slop_list_howl_types_Clause howl_sriqclauses_expand_dl7(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DRole s1, howl_types_DRole s2) {
    {
        __auto_type z1 = howl_types_at_z(((uint32_t)(1)));
        return howl_sriqclauses_one(arena, howl_sriqclauses_make_clause(arena, howl_sriqclauses_lits1(arena, howl_types_atom2(howl_sriqclauses_role_id(ids, s1), z1, howl_types_at_x())), howl_sriqclauses_lits1(arena, howl_types_atom2(howl_sriqclauses_role_id(ids, s2), z1, howl_types_at_x()))));
    }
}

slop_list_howl_types_Clause howl_sriqclauses_expand_dl8(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DRole s1, howl_types_DRole s2) {
    {
        __auto_type z1 = howl_types_at_z(((uint32_t)(1)));
        return howl_sriqclauses_one(arena, howl_sriqclauses_make_clause(arena, howl_sriqclauses_lits1(arena, howl_types_atom2(howl_sriqclauses_role_id(ids, s1), z1, howl_types_at_x())), howl_sriqclauses_lits1(arena, howl_types_atom2(howl_sriqclauses_role_id(ids, s2), howl_types_at_x(), z1))));
    }
}

slop_list_howl_types_Clause howl_sriqclauses_expand_dl9(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DRole s1, howl_types_DRole s2) {
    {
        __auto_type z1 = howl_types_at_z(((uint32_t)(1)));
        return howl_sriqclauses_one(arena, howl_sriqclauses_make_clause(arena, howl_sriqclauses_lits2(arena, howl_types_atom2(howl_sriqclauses_role_id(ids, s1), z1, howl_types_at_x()), howl_types_atom2(howl_sriqclauses_role_id(ids, s2), z1, howl_types_at_x())), ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena })));
    }
}

slop_list_howl_types_Clause howl_sriqclauses_expand_dl10(slop_arena* arena, howl_sriqclauses_SriqIds ids, slop_rdf_rdf_IRI o, howl_types_DName b) {
    return howl_sriqclauses_one(arena, howl_sriqclauses_make_clause(arena, ((slop_list_howl_types_Lit){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), howl_sriqclauses_lits1(arena, howl_types_atom1(howl_sriqclauses_class_id(ids, b), howl_types_at_u(howl_sriqclauses_const_id(ids, o))))));
}

slop_list_howl_types_Clause howl_sriqclauses_expand_dl11(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DName b, slop_rdf_rdf_IRI o) {
    return howl_sriqclauses_one(arena, howl_sriqclauses_make_clause(arena, howl_sriqclauses_lits1(arena, howl_types_atom1(howl_sriqclauses_class_id(ids, b), howl_types_at_x())), howl_sriqclauses_lits1(arena, howl_types_eq_lit(howl_types_at_x(), howl_types_at_u(howl_sriqclauses_const_id(ids, o))))));
}

slop_list_howl_types_Clause howl_sriqclauses_expand_clause(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_DlClause c) {
    __auto_type _mv_422 = c;
    switch (_mv_422.tag) {
        case howl_types_DlClause_dl1:
        {
            __auto_type d = _mv_422.data.dl1;
            return howl_sriqclauses_expand_dl1(arena, ids, d);
        }
        case howl_types_DlClause_dl2:
        {
            __auto_type d = _mv_422.data.dl2;
            return howl_sriqclauses_expand_dl2(arena, ids, d);
        }
        case howl_types_DlClause_dl3:
        {
            __auto_type s = _mv_422.data.dl3.f0;
            __auto_type b1 = _mv_422.data.dl3.f1;
            __auto_type b2 = _mv_422.data.dl3.f2;
            return howl_sriqclauses_expand_dl3(arena, ids, s, b1, b2);
        }
        case howl_types_DlClause_dl4:
        {
            __auto_type d = _mv_422.data.dl4;
            return howl_sriqclauses_expand_dl4(arena, ids, d);
        }
        case howl_types_DlClause_dl5:
        {
            __auto_type b = _mv_422.data.dl5.f0;
            __auto_type s = _mv_422.data.dl5.f1;
            return howl_sriqclauses_expand_dl5(arena, ids, b, s);
        }
        case howl_types_DlClause_dl6:
        {
            __auto_type s = _mv_422.data.dl6.f0;
            __auto_type b = _mv_422.data.dl6.f1;
            return howl_sriqclauses_expand_dl6(arena, ids, s, b);
        }
        case howl_types_DlClause_dl7:
        {
            __auto_type s1 = _mv_422.data.dl7.f0;
            __auto_type s2 = _mv_422.data.dl7.f1;
            return howl_sriqclauses_expand_dl7(arena, ids, s1, s2);
        }
        case howl_types_DlClause_dl8:
        {
            __auto_type s1 = _mv_422.data.dl8.f0;
            __auto_type s2 = _mv_422.data.dl8.f1;
            return howl_sriqclauses_expand_dl8(arena, ids, s1, s2);
        }
        case howl_types_DlClause_dl9:
        {
            __auto_type s1 = _mv_422.data.dl9.f0;
            __auto_type s2 = _mv_422.data.dl9.f1;
            return howl_sriqclauses_expand_dl9(arena, ids, s1, s2);
        }
        case howl_types_DlClause_dl10:
        {
            __auto_type o = _mv_422.data.dl10.f0;
            __auto_type b = _mv_422.data.dl10.f1;
            return howl_sriqclauses_expand_dl10(arena, ids, o, b);
        }
        case howl_types_DlClause_dl11:
        {
            __auto_type b = _mv_422.data.dl11.f0;
            __auto_type o = _mv_422.data.dl11.f1;
            return howl_sriqclauses_expand_dl11(arena, ids, b, o);
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_Clause howl_sriqclauses_ontology_clauses(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_sriqnames_SriqNormal n) {
    {
        __auto_type out = ((slop_list_howl_types_Clause){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = n.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                {
                    __auto_type _coll = howl_sriqclauses_expand_clause(arena, ids, c);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return howl_sriqclauses_clause_set(arena, out);
    }
}

slop_result_howl_sriqclauses_SriqClauses_string howl_sriqclauses_sriq_clauses(slop_arena* arena, howl_sriqnames_SriqNormal n) {
    {
        __auto_type ids = howl_sriqclauses_build_sriq_ids(arena, n);
        __auto_type miss = howl_sriqclauses_uncovered(arena, ids, n);
        __auto_type _mv_423 = ({ __auto_type _lst = miss; size_t _idx = (size_t)0; slop_option_string _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_423.has_value) {
            __auto_type m = _mv_423.value;
            return ((slop_result_howl_sriqclauses_SriqClauses_string){ .is_ok = false, .data.err = string_concat(arena, SLOP_STR("the clause boundary has no id for "), m) });
        } else if (!_mv_423.has_value) {
            return ((slop_result_howl_sriqclauses_SriqClauses_string){ .is_ok = true, .data.ok = ((howl_sriqclauses_SriqClauses){.ids = ids, .clauses = howl_sriqclauses_ontology_clauses(arena, ids, n)}) });
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t howl_sriqclauses_is_x(howl_types_ATerm t) {
    return (t.kind == howl_types_AKind_ak_x);
}

uint8_t howl_sriqclauses_is_z(howl_types_ATerm t) {
    return (t.kind == howl_types_AKind_ak_z);
}

uint8_t howl_sriqclauses_is_fx(howl_types_ATerm t) {
    return (t.kind == howl_types_AKind_ak_fx);
}

uint8_t howl_sriqclauses_dl_aterm(howl_types_ATerm t) {
    return ((howl_sriqclauses_is_x(t)) || (howl_sriqclauses_is_z(t)) || (howl_sriqclauses_is_fx(t)) || ((t.kind == howl_types_AKind_ak_u)));
}

uint8_t howl_sriqclauses_dl_body_atom(howl_types_Lit l) {
    {
        __auto_type a = l.t1;
        __auto_type b = l.t2;
        __auto_type _mv_424 = l.form;
        if (_mv_424 == howl_types_LitForm_lf_unary) {
            return howl_sriqclauses_is_x(a);
        } else if (_mv_424 == howl_types_LitForm_lf_binary) {
            return ((howl_sriqclauses_is_x(a) && (howl_sriqclauses_is_x(b) || howl_sriqclauses_is_z(b))) || (howl_sriqclauses_is_z(a) && howl_sriqclauses_is_x(b)));
        } else if (_mv_424 == howl_types_LitForm_lf_eq) {
            return 0;
        } else if (_mv_424 == howl_types_LitForm_lf_neq) {
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t howl_sriqclauses_dl_head_lit(howl_types_Lit l) {
    {
        __auto_type a = l.t1;
        __auto_type b = l.t2;
        __auto_type _mv_425 = l.form;
        if (_mv_425 == howl_types_LitForm_lf_unary) {
            return howl_sriqclauses_dl_aterm(a);
        } else if (_mv_425 == howl_types_LitForm_lf_binary) {
            return ((howl_sriqclauses_is_x(a) && ((howl_sriqclauses_is_x(b)) || (howl_sriqclauses_is_z(b)) || (howl_sriqclauses_is_fx(b)))) || ((howl_sriqclauses_is_z(a) || howl_sriqclauses_is_fx(a)) && howl_sriqclauses_is_x(b)));
        } else if (_mv_425 == howl_types_LitForm_lf_eq) {
            return (howl_sriqclauses_dl_aterm(a) && howl_sriqclauses_dl_aterm(b));
        } else if (_mv_425 == howl_types_LitForm_lf_neq) {
            return (howl_sriqclauses_dl_aterm(a) && howl_sriqclauses_dl_aterm(b));
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t howl_sriqclauses_dl_clause_shape(howl_types_Clause c) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(howl_sriqclauses_dl_body_atom(l))) {
                    ok = 0;
                }
            }
        }
        {
            __auto_type _coll = c.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(howl_sriqclauses_dl_head_lit(l))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t howl_sriqclauses_canonical_aterm(howl_types_ATerm t) {
    {
        __auto_type f = ((int64_t)(t.fsym));
        __auto_type u = ((int64_t)(t.cst));
        __auto_type i = ((int64_t)(t.zi));
        __auto_type _mv_426 = t.kind;
        if (_mv_426 == howl_types_AKind_ak_x) {
            return (((f == 0)) && ((u == 0)) && ((i == 0)));
        } else if (_mv_426 == howl_types_AKind_ak_y) {
            return (((f == 0)) && ((u == 0)) && ((i == 0)));
        } else if (_mv_426 == howl_types_AKind_ak_z) {
            return (((f == 0)) && ((u == 0)) && ((i >= 1)));
        } else if (_mv_426 == howl_types_AKind_ak_fx) {
            return ((u == 0) && (i == 0));
        } else if (_mv_426 == howl_types_AKind_ak_u) {
            return ((f == 0) && (i == 0));
        } else if (_mv_426 == howl_types_AKind_ak_fu) {
            return (i == 0);
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t howl_sriqclauses_canonical_lit(howl_types_Lit l) {
    {
        __auto_type terms = (howl_sriqclauses_canonical_aterm(l.t1) && howl_sriqclauses_canonical_aterm(l.t2));
        __auto_type oriented = ((((int64_t)(l.pred)) == 0) && (howl_types_aterm_cmp(l.t1, l.t2) >= 0));
        __auto_type _mv_427 = l.form;
        if (_mv_427 == howl_types_LitForm_lf_unary) {
            return (terms && howl_types_aterm_eq(l.t2, howl_types_at_x()));
        } else if (_mv_427 == howl_types_LitForm_lf_binary) {
            return terms;
        } else if (_mv_427 == howl_types_LitForm_lf_eq) {
            return (terms && oriented);
        } else if (_mv_427 == howl_types_LitForm_lf_neq) {
            return (terms && oriented);
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t howl_sriqclauses_lits_canonical(slop_list_howl_types_Lit ls) {
    {
        uint8_t ok = 1;
        int64_t i = 0;
        {
            __auto_type _coll = ls;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(howl_sriqclauses_canonical_lit(l))) {
                    ok = 0;
                }
                if ((i > 0) && (howl_types_lit_cmp(howl_sriqclauses_lit_at(ls, (i - 1)), l) >= 0)) {
                    ok = 0;
                }
                i = (i + 1);
            }
        }
        return ok;
    }
}

uint8_t howl_sriqclauses_clause_canonical(howl_types_Clause c) {
    return (howl_sriqclauses_lits_canonical(c.body) && howl_sriqclauses_lits_canonical(c.head));
}

uint8_t howl_sriqclauses_aterm_in_range(howl_sriqclauses_SriqIds ids, howl_types_ATerm t) {
    {
        __auto_type nc = ((int64_t)(((int64_t)((ids.const_of).len))));
        __auto_type f = ((int64_t)(t.fsym));
        __auto_type u = ((int64_t)(t.cst));
        __auto_type _mv_428 = t.kind;
        if (_mv_428 == howl_types_AKind_ak_x) {
            return 1;
        } else if (_mv_428 == howl_types_AKind_ak_y) {
            return 1;
        } else if (_mv_428 == howl_types_AKind_ak_z) {
            return (((int64_t)(t.zi)) >= 1);
        } else if (_mv_428 == howl_types_AKind_ak_fx) {
            return (f < ids.nfns);
        } else if (_mv_428 == howl_types_AKind_ak_u) {
            return (u < nc);
        } else if (_mv_428 == howl_types_AKind_ak_fu) {
            return ((f < ids.nfns) && (u < nc));
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t howl_sriqclauses_lit_in_range(howl_sriqclauses_SriqIds ids, howl_types_Lit l) {
    {
        __auto_type p = ((int64_t)(l.pred));
        __auto_type terms = (howl_sriqclauses_aterm_in_range(ids, l.t1) && howl_sriqclauses_aterm_in_range(ids, l.t2));
        __auto_type _mv_429 = l.form;
        if (_mv_429 == howl_types_LitForm_lf_unary) {
            return (terms && (p < ((int64_t)(((int64_t)((ids.class_of).len))))));
        } else if (_mv_429 == howl_types_LitForm_lf_binary) {
            return (terms && (p < ((int64_t)(((int64_t)((ids.role_of).len))))));
        } else if (_mv_429 == howl_types_LitForm_lf_eq) {
            return (terms && (p == 0));
        } else if (_mv_429 == howl_types_LitForm_lf_neq) {
            return (terms && (p == 0));
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t howl_sriqclauses_clause_in_range(howl_sriqclauses_SriqIds ids, howl_types_Clause c) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = c.body;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(howl_sriqclauses_lit_in_range(ids, l))) {
                    ok = 0;
                }
            }
        }
        {
            __auto_type _coll = c.head;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(howl_sriqclauses_lit_in_range(ids, l))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t howl_sriqclauses_tables_round_trip(howl_sriqclauses_SriqIds ids) {
    {
        uint8_t ok = 1;
        int64_t i = 0;
        {
            __auto_type _coll = ids.class_of;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                if (((int64_t)(howl_sriqclauses_class_id(ids, b))) != i) {
                    ok = 0;
                }
                i = (i + 1);
            }
        }
        i = 0;
        {
            __auto_type _coll = ids.role_of;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                if (((int64_t)(howl_sriqclauses_role_id(ids, r))) != i) {
                    ok = 0;
                }
                i = (i + 1);
            }
        }
        i = 0;
        {
            __auto_type _coll = ids.const_of;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                if (((int64_t)(howl_sriqclauses_const_id(ids, o))) != i) {
                    ok = 0;
                }
                i = (i + 1);
            }
        }
        return ok;
    }
}

uint8_t howl_sriqclauses_class_in_place(howl_sriqclauses_SriqIds ids, int64_t i, howl_types_DName b, slop_rdf_rdf_IRI prev) {
    __auto_type _mv_430 = b;
    switch (_mv_430.tag) {
        case howl_types_DName_dn_class:
        {
            __auto_type c = _mv_430.data.dn_class;
            return ((i < ids.nclass) && ((i == 0) || (howl_canon_iri_cmp(prev, c) < 0)));
        }
        case howl_types_DName_dn_fresh:
        {
            __auto_type _ = _mv_430.data.dn_fresh;
            return 1;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqclauses_classes_in_order(howl_sriqclauses_SriqIds ids) {
    {
        uint8_t ok = 1;
        int64_t i = 0;
        __auto_type prev = ((slop_rdf_rdf_IRI){.value = SLOP_STR("")});
        {
            __auto_type _coll = ids.class_of;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type b = _coll.data[_i];
                if (!(howl_sriqclauses_class_in_place(ids, i, b, prev))) {
                    ok = 0;
                }
                __auto_type _mv_431 = b;
                switch (_mv_431.tag) {
                    case howl_types_DName_dn_class:
                    {
                        __auto_type c = _mv_431.data.dn_class;
                        prev = c;
                        break;
                    }
                    case howl_types_DName_dn_fresh:
                    {
                        __auto_type _ = _mv_431.data.dn_fresh;
                        break;
                    }
                }
                i = (i + 1);
            }
        }
        return ok;
    }
}

uint8_t howl_sriqclauses_prop_after(howl_types_DRole prev, slop_rdf_rdf_IRI p) {
    __auto_type _mv_432 = prev;
    switch (_mv_432.tag) {
        case howl_types_DRole_dr_prop:
        {
            __auto_type q = _mv_432.data.dr_prop;
            return (howl_canon_iri_cmp(q, p) < 0);
        }
        case howl_types_DRole_dr_bar:
        {
            __auto_type _ = _mv_432.data.dr_bar;
            return 0;
        }
        case howl_types_DRole_dr_sub:
        {
            __auto_type _ = _mv_432.data.dr_sub;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqclauses_bar_after(howl_types_DRole prev, slop_rdf_rdf_IRI p) {
    __auto_type _mv_433 = prev;
    switch (_mv_433.tag) {
        case howl_types_DRole_dr_prop:
        {
            __auto_type _ = _mv_433.data.dr_prop;
            return 1;
        }
        case howl_types_DRole_dr_bar:
        {
            __auto_type q = _mv_433.data.dr_bar;
            return (howl_canon_iri_cmp(q, p) < 0);
        }
        case howl_types_DRole_dr_sub:
        {
            __auto_type _ = _mv_433.data.dr_sub;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqclauses_role_in_place(howl_sriqclauses_SriqIds ids, int64_t i, howl_types_DRole r, howl_types_DRole prev) {
    __auto_type _mv_434 = r;
    switch (_mv_434.tag) {
        case howl_types_DRole_dr_prop:
        {
            __auto_type p = _mv_434.data.dr_prop;
            return ((i < ids.sub0) && ((i == 0) || howl_sriqclauses_prop_after(prev, p)));
        }
        case howl_types_DRole_dr_bar:
        {
            __auto_type p = _mv_434.data.dr_bar;
            return ((i < ids.sub0) && ((i == 0) || howl_sriqclauses_bar_after(prev, p)));
        }
        case howl_types_DRole_dr_sub:
        {
            __auto_type _ = _mv_434.data.dr_sub;
            return 1;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqclauses_roles_in_order(howl_sriqclauses_SriqIds ids) {
    {
        uint8_t ok = 1;
        int64_t i = 0;
        __auto_type prev = ((howl_types_DRole){ .tag = howl_types_DRole_dr_sub, .data.dr_sub = 0 });
        {
            __auto_type _coll = ids.role_of;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                if (!(howl_sriqclauses_role_in_place(ids, i, r, prev))) {
                    ok = 0;
                }
                prev = r;
                i = (i + 1);
            }
        }
        return ok;
    }
}

uint8_t howl_sriqclauses_consts_in_order(howl_sriqclauses_SriqIds ids) {
    {
        uint8_t ok = 1;
        int64_t i = 0;
        {
            __auto_type _coll = ids.const_of;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                if ((i > 0) && (howl_canon_iri_cmp(howl_sriqclauses_iri_at(ids.const_of, (i - 1)), o) >= 0)) {
                    ok = 0;
                }
                i = (i + 1);
            }
        }
        return ok;
    }
}

slop_list_string howl_sriqclauses_ids_dense(slop_arena* arena, howl_sriqclauses_SriqClauses sc) {
    {
        __auto_type ids = sc.ids;
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (!(howl_sriqclauses_tables_round_trip(ids))) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (SLOP_STR("a table entry does not look up to its own id")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        if (!(((howl_sriqclauses_classes_in_order(ids)) && (howl_sriqclauses_roles_in_order(ids)) && (howl_sriqclauses_consts_in_order(ids))))) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (SLOP_STR("a table is not in content order")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        {
            __auto_type _coll = sc.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(howl_sriqclauses_clause_in_range(ids, c))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (string_concat(arena, SLOP_STR("an id out of range in "), howl_sriqclauses_render_clause(arena, ids, c))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

slop_string howl_sriqclauses_class_text(slop_arena* arena, howl_sriqclauses_SriqIds ids, uint32_t b) {
    __auto_type _mv_435 = ({ __auto_type _lst = ids.class_of; size_t _idx = (size_t)((int64_t)(b)); slop_option_howl_types_DName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_435.has_value) {
        __auto_type n = _mv_435.value;
        return howl_sriqclauses_dname_text(arena, n);
    } else if (!_mv_435.has_value) {
        return string_concat(arena, SLOP_STR("?class"), int_to_string(arena, ((int64_t)(b))));
    }
    SLOP_UNREACHABLE();
}

slop_string howl_sriqclauses_role_text(slop_arena* arena, howl_sriqclauses_SriqIds ids, uint32_t r) {
    __auto_type _mv_436 = ({ __auto_type _lst = ids.role_of; size_t _idx = (size_t)((int64_t)(r)); slop_option_howl_types_DRole _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_436.has_value) {
        __auto_type n = _mv_436.value;
        return howl_sriqclauses_drole_text(arena, n);
    } else if (!_mv_436.has_value) {
        return string_concat(arena, SLOP_STR("?role"), int_to_string(arena, ((int64_t)(r))));
    }
    SLOP_UNREACHABLE();
}

slop_string howl_sriqclauses_const_text(slop_arena* arena, howl_sriqclauses_SriqIds ids, uint32_t u) {
    __auto_type _mv_437 = ({ __auto_type _lst = ids.const_of; size_t _idx = (size_t)((int64_t)(u)); slop_option_slop_rdf_rdf_IRI _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_437.has_value) {
        __auto_type o = _mv_437.value;
        return o.value;
    } else if (!_mv_437.has_value) {
        return string_concat(arena, SLOP_STR("?const"), int_to_string(arena, ((int64_t)(u))));
    }
    SLOP_UNREACHABLE();
}

slop_string howl_sriqclauses_fsym_text(slop_arena* arena, uint32_t f) {
    return string_concat(arena, SLOP_STR("f"), int_to_string(arena, ((int64_t)(f))));
}

slop_string howl_sriqclauses_applied(slop_arena* arena, slop_string f, slop_string arg) {
    return string_concat(arena, f, string_concat(arena, SLOP_STR("("), string_concat(arena, arg, SLOP_STR(")"))));
}

slop_string howl_sriqclauses_render_aterm(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_ATerm t) {
    __auto_type _mv_438 = t.kind;
    if (_mv_438 == howl_types_AKind_ak_x) {
        return SLOP_STR("x");
    } else if (_mv_438 == howl_types_AKind_ak_y) {
        return SLOP_STR("y");
    } else if (_mv_438 == howl_types_AKind_ak_z) {
        return string_concat(arena, SLOP_STR("z"), int_to_string(arena, ((int64_t)(t.zi))));
    } else if (_mv_438 == howl_types_AKind_ak_fx) {
        return howl_sriqclauses_applied(arena, howl_sriqclauses_fsym_text(arena, t.fsym), SLOP_STR("x"));
    } else if (_mv_438 == howl_types_AKind_ak_u) {
        return howl_sriqclauses_const_text(arena, ids, t.cst);
    } else if (_mv_438 == howl_types_AKind_ak_fu) {
        return howl_sriqclauses_applied(arena, howl_sriqclauses_fsym_text(arena, t.fsym), howl_sriqclauses_const_text(arena, ids, t.cst));
    }
    SLOP_UNREACHABLE();
}

slop_string howl_sriqclauses_infix(slop_arena* arena, slop_string a, slop_string op, slop_string b) {
    return string_concat(arena, a, string_concat(arena, op, b));
}

slop_string howl_sriqclauses_render_lit(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Lit l) {
    {
        __auto_type a = howl_sriqclauses_render_aterm(arena, ids, l.t1);
        __auto_type b = howl_sriqclauses_render_aterm(arena, ids, l.t2);
        __auto_type _mv_439 = l.form;
        if (_mv_439 == howl_types_LitForm_lf_unary) {
            return howl_sriqclauses_applied(arena, howl_sriqclauses_class_text(arena, ids, l.pred), a);
        } else if (_mv_439 == howl_types_LitForm_lf_binary) {
            return howl_sriqclauses_applied(arena, howl_sriqclauses_role_text(arena, ids, l.pred), howl_sriqclauses_infix(arena, a, SLOP_STR(", "), b));
        } else if (_mv_439 == howl_types_LitForm_lf_eq) {
            return howl_sriqclauses_infix(arena, a, SLOP_STR(" ≈ "), b);
        } else if (_mv_439 == howl_types_LitForm_lf_neq) {
            return howl_sriqclauses_infix(arena, a, SLOP_STR(" ≉ "), b);
        }
        SLOP_UNREACHABLE();
    }
}

slop_string howl_sriqclauses_render_lits(slop_arena* arena, howl_sriqclauses_SriqIds ids, slop_list_howl_types_Lit ls, slop_string sep, slop_string empty) {
    {
        __auto_type out = SLOP_STR("");
        uint8_t first = 1;
        {
            __auto_type _coll = ls;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                if (!(first)) {
                    out = string_concat(arena, out, sep);
                }
                out = string_concat(arena, out, howl_sriqclauses_render_lit(arena, ids, l));
                first = 0;
            }
        }
        if (first) {
            return empty;
        } else {
            return out;
        }
    }
}

slop_string howl_sriqclauses_render_clause(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Clause c) {
    return howl_sriqclauses_infix(arena, howl_sriqclauses_render_lits(arena, ids, c.body, SLOP_STR(" ∧ "), SLOP_STR("⊤")), SLOP_STR(" → "), howl_sriqclauses_render_lits(arena, ids, c.head, SLOP_STR(" ∨ "), SLOP_STR("⊥")));
}

slop_list_string howl_sriqclauses_render_clauses(slop_arena* arena, howl_sriqclauses_SriqClauses sc) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = sc.clauses;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqclauses_render_clause(arena, sc.ids, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

