#include "../runtime/slop_runtime.h"
#include "slop_sroiq.h"

sroiq_SConcept* sroiq_box_sc(slop_arena* arena, sroiq_SConcept c);
types_RoleId sroiq_inv_role(types_RoleId r);
uint8_t sroiq_sc_top_p(sroiq_SConcept c);
int64_t sroiq_sc_rank(sroiq_SConcept c);
sroiq_SConcept sroiq_sc_at(slop_list_sroiq_SConcept xs, int64_t i);
int64_t sroiq_sc_list_cmp(slop_list_sroiq_SConcept a, slop_list_sroiq_SConcept b);
int64_t sroiq_int_cmp(int64_t a, int64_t b);
int64_t sroiq_role_then(types_RoleId ra, types_RoleId rb, sroiq_SConcept fa, sroiq_SConcept fb);
int64_t sroiq_sc_cmp(sroiq_SConcept a, sroiq_SConcept b);
int64_t sroiq_role_list_cmp(slop_list_types_RoleId a, slop_list_types_RoleId b);
int64_t sroiq_sa_rank(sroiq_SAxiom a);
int64_t sroiq_sa_cmp(sroiq_SAxiom a, sroiq_SAxiom b);
slop_list_sroiq_SConcept sroiq_sort_sconcepts(slop_arena* arena, slop_list_sroiq_SConcept xs);
sroiq_SConcept sroiq_sc_canon(slop_arena* arena, sroiq_SConcept c);
sroiq_SConcept sroiq_canon_junction(slop_arena* arena, slop_list_sroiq_SConcept xs, uint8_t conj);
sroiq_SAxiom sroiq_sa_at(slop_list_sroiq_SAxiom xs, int64_t i);
slop_list_sroiq_SAxiom sroiq_sort_saxioms(slop_arena* arena, slop_list_sroiq_SAxiom xs);
slop_list_sroiq_SAxiom sroiq_dedupe_saxioms(slop_arena* arena, slop_list_sroiq_SAxiom xs);
slop_string sroiq_render_srole(slop_arena* arena, types_RoleId r);
slop_string sroiq_render_sconcepts(slop_arena* arena, slop_list_sroiq_SConcept xs, slop_string sep);
slop_string sroiq_render_restriction(slop_arena* arena, slop_string head, types_RoleId r, sroiq_SConcept f);
slop_string sroiq_render_sconcept(slop_arena* arena, sroiq_SConcept c);
slop_string sroiq_render_word(slop_arena* arena, slop_list_types_RoleId w);
slop_string sroiq_render_saxiom(slop_arena* arena, sroiq_SAxiom a);

typedef struct { slop_list_sroiq_SConcept xs; } sroiq__lambda_1096_env_t;

static int64_t sroiq__lambda_1096(sroiq__lambda_1096_env_t* _env, int64_t i, int64_t j) { return sroiq_sc_cmp(sroiq_sc_at(_env->xs, i), sroiq_sc_at(_env->xs, j)); }

typedef struct { slop_list_sroiq_SAxiom xs; } sroiq__lambda_1101_env_t;

static int64_t sroiq__lambda_1101(sroiq__lambda_1101_env_t* _env, int64_t i, int64_t j) { return sroiq_sa_cmp(sroiq_sa_at(_env->xs, i), sroiq_sa_at(_env->xs, j)); }

sroiq_SConcept* sroiq_box_sc(slop_arena* arena, sroiq_SConcept c) {
    {
        __auto_type p = ((sroiq_SConcept*)(({ __auto_type _alloc = (sroiq_SConcept*)slop_arena_alloc(arena, sizeof(sroiq_SConcept)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = c;
        return p;
    }
}

types_RoleId sroiq_inv_role(types_RoleId r) {
    __auto_type _mv_1072 = r;
    switch (_mv_1072.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_1072.data.named_role;
            return ((types_RoleId){ .tag = types_RoleId_inverse_role, .data.inverse_role = i });
        }
        case types_RoleId_inverse_role:
        {
            __auto_type i = _mv_1072.data.inverse_role;
            return ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = i });
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_1072.data.fresh_role;
            return r;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t sroiq_sc_top_p(sroiq_SConcept c) {
    __auto_type _mv_1073 = c;
    switch (_mv_1073.tag) {
        case sroiq_SConcept_sc_top:
        {
            return 1;
        }
        default: {
            return 0;
        }
    }
}

int64_t sroiq_sc_rank(sroiq_SConcept c) {
    __auto_type _mv_1074 = c;
    switch (_mv_1074.tag) {
        case sroiq_SConcept_sc_top:
        {
            return 0;
        }
        case sroiq_SConcept_sc_bottom:
        {
            return 1;
        }
        case sroiq_SConcept_sc_name:
        {
            __auto_type _ = _mv_1074.data.sc_name;
            return 2;
        }
        case sroiq_SConcept_sc_nominal:
        {
            __auto_type _ = _mv_1074.data.sc_nominal;
            return 3;
        }
        case sroiq_SConcept_sc_not:
        {
            __auto_type _ = _mv_1074.data.sc_not;
            return 4;
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type _ = _mv_1074.data.sc_and;
            return 5;
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type _ = _mv_1074.data.sc_or;
            return 6;
        }
        case sroiq_SConcept_sc_some:
        {
            return 7;
        }
        case sroiq_SConcept_sc_all:
        {
            return 8;
        }
        case sroiq_SConcept_sc_atleast:
        {
            return 9;
        }
        case sroiq_SConcept_sc_atmost:
        {
            return 10;
        }
        case sroiq_SConcept_sc_self:
        {
            __auto_type _ = _mv_1074.data.sc_self;
            return 11;
        }
    }
    SLOP_UNREACHABLE();
}

sroiq_SConcept sroiq_sc_at(slop_list_sroiq_SConcept xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_1075 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_sroiq_SConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1075.has_value) {
        __auto_type v = _mv_1075.value;
        return v;
    } else if (!_mv_1075.has_value) {
        return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_top });
    }
    SLOP_UNREACHABLE();
}

int64_t sroiq_sc_list_cmp(slop_list_sroiq_SConcept a, slop_list_sroiq_SConcept b) {
    {
        __auto_type alen = ((int64_t)(((int64_t)((a).len))));
        __auto_type blen = ((int64_t)(((int64_t)((b).len))));
        __auto_type n = ((alen) < (blen) ? (alen) : (blen));
        int64_t i = 0;
        int64_t r = 0;
        while ((i < n) && (r == 0)) {
            r = sroiq_sc_cmp(sroiq_sc_at(a, i), sroiq_sc_at(b, i));
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

int64_t sroiq_int_cmp(int64_t a, int64_t b) {
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

int64_t sroiq_role_then(types_RoleId ra, types_RoleId rb, sroiq_SConcept fa, sroiq_SConcept fb) {
    {
        __auto_type rr = canon_role_cmp(ra, rb);
        if (rr != 0) {
            return rr;
        } else {
            return sroiq_sc_cmp(fa, fb);
        }
    }
}

int64_t sroiq_sc_cmp(sroiq_SConcept a, sroiq_SConcept b) {
    {
        __auto_type ka = sroiq_sc_rank(a);
        __auto_type kb = sroiq_sc_rank(b);
        if (ka != kb) {
            return sroiq_int_cmp(ka, kb);
        } else {
            __auto_type _mv_1076 = a;
            switch (_mv_1076.tag) {
                case sroiq_SConcept_sc_top:
                {
                    return 0;
                }
                case sroiq_SConcept_sc_bottom:
                {
                    return 0;
                }
                case sroiq_SConcept_sc_name:
                {
                    __auto_type ia = _mv_1076.data.sc_name;
                    __auto_type _mv_1077 = b;
                    switch (_mv_1077.tag) {
                        case sroiq_SConcept_sc_name:
                        {
                            __auto_type ib = _mv_1077.data.sc_name;
                            return canon_iri_cmp(ia, ib);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_nominal:
                {
                    __auto_type ia = _mv_1076.data.sc_nominal;
                    __auto_type _mv_1078 = b;
                    switch (_mv_1078.tag) {
                        case sroiq_SConcept_sc_nominal:
                        {
                            __auto_type ib = _mv_1078.data.sc_nominal;
                            return canon_iri_cmp(ia, ib);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_not:
                {
                    __auto_type fa = _mv_1076.data.sc_not;
                    __auto_type _mv_1079 = b;
                    switch (_mv_1079.tag) {
                        case sroiq_SConcept_sc_not:
                        {
                            __auto_type fb = _mv_1079.data.sc_not;
                            return sroiq_sc_cmp((*fa), (*fb));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_and:
                {
                    __auto_type xs = _mv_1076.data.sc_and;
                    __auto_type _mv_1080 = b;
                    switch (_mv_1080.tag) {
                        case sroiq_SConcept_sc_and:
                        {
                            __auto_type ys = _mv_1080.data.sc_and;
                            return sroiq_sc_list_cmp(xs, ys);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_or:
                {
                    __auto_type xs = _mv_1076.data.sc_or;
                    __auto_type _mv_1081 = b;
                    switch (_mv_1081.tag) {
                        case sroiq_SConcept_sc_or:
                        {
                            __auto_type ys = _mv_1081.data.sc_or;
                            return sroiq_sc_list_cmp(xs, ys);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_some:
                {
                    __auto_type ra = _mv_1076.data.sc_some.f0;
                    __auto_type fa = _mv_1076.data.sc_some.f1;
                    __auto_type _mv_1082 = b;
                    switch (_mv_1082.tag) {
                        case sroiq_SConcept_sc_some:
                        {
                            __auto_type rb = _mv_1082.data.sc_some.f0;
                            __auto_type fb = _mv_1082.data.sc_some.f1;
                            return sroiq_role_then(ra, rb, (*fa), (*fb));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_all:
                {
                    __auto_type ra = _mv_1076.data.sc_all.f0;
                    __auto_type fa = _mv_1076.data.sc_all.f1;
                    __auto_type _mv_1083 = b;
                    switch (_mv_1083.tag) {
                        case sroiq_SConcept_sc_all:
                        {
                            __auto_type rb = _mv_1083.data.sc_all.f0;
                            __auto_type fb = _mv_1083.data.sc_all.f1;
                            return sroiq_role_then(ra, rb, (*fa), (*fb));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_atleast:
                {
                    __auto_type na = _mv_1076.data.sc_atleast.f0;
                    __auto_type ra = _mv_1076.data.sc_atleast.f1;
                    __auto_type fa = _mv_1076.data.sc_atleast.f2;
                    __auto_type _mv_1084 = b;
                    switch (_mv_1084.tag) {
                        case sroiq_SConcept_sc_atleast:
                        {
                            __auto_type nb = _mv_1084.data.sc_atleast.f0;
                            __auto_type rb = _mv_1084.data.sc_atleast.f1;
                            __auto_type fb = _mv_1084.data.sc_atleast.f2;
                            {
                                __auto_type nn = sroiq_int_cmp(na, nb);
                                if (nn != 0) {
                                    return nn;
                                } else {
                                    return sroiq_role_then(ra, rb, (*fa), (*fb));
                                }
                            }
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_atmost:
                {
                    __auto_type na = _mv_1076.data.sc_atmost.f0;
                    __auto_type ra = _mv_1076.data.sc_atmost.f1;
                    __auto_type fa = _mv_1076.data.sc_atmost.f2;
                    __auto_type _mv_1085 = b;
                    switch (_mv_1085.tag) {
                        case sroiq_SConcept_sc_atmost:
                        {
                            __auto_type nb = _mv_1085.data.sc_atmost.f0;
                            __auto_type rb = _mv_1085.data.sc_atmost.f1;
                            __auto_type fb = _mv_1085.data.sc_atmost.f2;
                            {
                                __auto_type nn = sroiq_int_cmp(na, nb);
                                if (nn != 0) {
                                    return nn;
                                } else {
                                    return sroiq_role_then(ra, rb, (*fa), (*fb));
                                }
                            }
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_self:
                {
                    __auto_type ra = _mv_1076.data.sc_self;
                    __auto_type _mv_1086 = b;
                    switch (_mv_1086.tag) {
                        case sroiq_SConcept_sc_self:
                        {
                            __auto_type rb = _mv_1086.data.sc_self;
                            return canon_role_cmp(ra, rb);
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

int64_t sroiq_role_list_cmp(slop_list_types_RoleId a, slop_list_types_RoleId b) {
    {
        __auto_type alen = ((int64_t)(((int64_t)((a).len))));
        __auto_type blen = ((int64_t)(((int64_t)((b).len))));
        __auto_type n = ((alen) < (blen) ? (alen) : (blen));
        int64_t i = 0;
        int64_t r = 0;
        while ((i < n) && (r == 0)) {
            __auto_type _mv_1087 = ({ __auto_type _lst = a; size_t _idx = (size_t)i; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1087.has_value) {
                __auto_type x = _mv_1087.value;
                __auto_type _mv_1088 = ({ __auto_type _lst = b; size_t _idx = (size_t)i; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1088.has_value) {
                    __auto_type y = _mv_1088.value;
                    r = canon_role_cmp(x, y);
                } else if (!_mv_1088.has_value) {
                }
            } else if (!_mv_1087.has_value) {
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

int64_t sroiq_sa_rank(sroiq_SAxiom a) {
    __auto_type _mv_1089 = a;
    switch (_mv_1089.tag) {
        case sroiq_SAxiom_sa_gci:
        {
            return 0;
        }
        case sroiq_SAxiom_sa_ria:
        {
            __auto_type _ = _mv_1089.data.sa_ria;
            return 1;
        }
        case sroiq_SAxiom_sa_ref:
        {
            __auto_type _ = _mv_1089.data.sa_ref;
            return 2;
        }
        case sroiq_SAxiom_sa_irr:
        {
            __auto_type _ = _mv_1089.data.sa_irr;
            return 3;
        }
        case sroiq_SAxiom_sa_dis:
        {
            return 4;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t sroiq_sa_cmp(sroiq_SAxiom a, sroiq_SAxiom b) {
    {
        __auto_type ka = sroiq_sa_rank(a);
        __auto_type kb = sroiq_sa_rank(b);
        if (ka != kb) {
            return sroiq_int_cmp(ka, kb);
        } else {
            __auto_type _mv_1090 = a;
            switch (_mv_1090.tag) {
                case sroiq_SAxiom_sa_gci:
                {
                    __auto_type la = _mv_1090.data.sa_gci.f0;
                    __auto_type ra = _mv_1090.data.sa_gci.f1;
                    __auto_type _mv_1091 = b;
                    switch (_mv_1091.tag) {
                        case sroiq_SAxiom_sa_gci:
                        {
                            __auto_type lb = _mv_1091.data.sa_gci.f0;
                            __auto_type rb = _mv_1091.data.sa_gci.f1;
                            {
                                __auto_type l = sroiq_sc_cmp((*la), (*lb));
                                if (l != 0) {
                                    return l;
                                } else {
                                    return sroiq_sc_cmp((*ra), (*rb));
                                }
                            }
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SAxiom_sa_ria:
                {
                    __auto_type x = _mv_1090.data.sa_ria;
                    __auto_type _mv_1092 = b;
                    switch (_mv_1092.tag) {
                        case sroiq_SAxiom_sa_ria:
                        {
                            __auto_type y = _mv_1092.data.sa_ria;
                            {
                                __auto_type s = canon_role_cmp(x.super, y.super);
                                if (s != 0) {
                                    return s;
                                } else {
                                    return sroiq_role_list_cmp(x.word, y.word);
                                }
                            }
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SAxiom_sa_ref:
                {
                    __auto_type r = _mv_1090.data.sa_ref;
                    __auto_type _mv_1093 = b;
                    switch (_mv_1093.tag) {
                        case sroiq_SAxiom_sa_ref:
                        {
                            __auto_type q = _mv_1093.data.sa_ref;
                            return canon_role_cmp(r, q);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SAxiom_sa_irr:
                {
                    __auto_type r = _mv_1090.data.sa_irr;
                    __auto_type _mv_1094 = b;
                    switch (_mv_1094.tag) {
                        case sroiq_SAxiom_sa_irr:
                        {
                            __auto_type q = _mv_1094.data.sa_irr;
                            return canon_role_cmp(r, q);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SAxiom_sa_dis:
                {
                    __auto_type r1 = _mv_1090.data.sa_dis.f0;
                    __auto_type r2 = _mv_1090.data.sa_dis.f1;
                    __auto_type _mv_1095 = b;
                    switch (_mv_1095.tag) {
                        case sroiq_SAxiom_sa_dis:
                        {
                            __auto_type q1 = _mv_1095.data.sa_dis.f0;
                            __auto_type q2 = _mv_1095.data.sa_dis.f1;
                            {
                                __auto_type c1 = canon_role_cmp(r1, q1);
                                if (c1 != 0) {
                                    return c1;
                                } else {
                                    return canon_role_cmp(r2, q2);
                                }
                            }
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

slop_list_sroiq_SConcept sroiq_sort_sconcepts(slop_arena* arena, slop_list_sroiq_SConcept xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ sroiq__lambda_1096_env_t* sroiq__lambda_1096_env = (sroiq__lambda_1096_env_t*)slop_arena_alloc(arena, sizeof(sroiq__lambda_1096_env_t)); *sroiq__lambda_1096_env = (sroiq__lambda_1096_env_t){ .xs = xs }; (slop_closure_t){ (void*)sroiq__lambda_1096, (void*)sroiq__lambda_1096_env }; }));
        __auto_type out = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t have = 0;
        __auto_type last = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_top });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                {
                    __auto_type c = sroiq_sc_at(xs, k);
                    if (!(have) || (sroiq_sc_cmp(c, last) != 0)) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        last = c;
                        have = 1;
                    }
                }
            }
        }
        return out;
    }
}

sroiq_SConcept sroiq_sc_canon(slop_arena* arena, sroiq_SConcept c) {
    __auto_type _mv_1097 = c;
    switch (_mv_1097.tag) {
        case sroiq_SConcept_sc_top:
        {
            return c;
        }
        case sroiq_SConcept_sc_bottom:
        {
            return c;
        }
        case sroiq_SConcept_sc_name:
        {
            __auto_type _ = _mv_1097.data.sc_name;
            return c;
        }
        case sroiq_SConcept_sc_nominal:
        {
            __auto_type _ = _mv_1097.data.sc_nominal;
            return c;
        }
        case sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_1097.data.sc_not;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_not, .data.sc_not = sroiq_box_sc(arena, sroiq_sc_canon(arena, (*f))) });
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_1097.data.sc_and;
            return sroiq_canon_junction(arena, xs, 1);
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_1097.data.sc_or;
            return sroiq_canon_junction(arena, xs, 0);
        }
        case sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_1097.data.sc_some.f0;
            __auto_type f = _mv_1097.data.sc_some.f1;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = sroiq_box_sc(arena, sroiq_sc_canon(arena, (*f))) } });
        }
        case sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_1097.data.sc_all.f0;
            __auto_type f = _mv_1097.data.sc_all.f1;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = sroiq_box_sc(arena, sroiq_sc_canon(arena, (*f))) } });
        }
        case sroiq_SConcept_sc_atleast:
        {
            __auto_type n = _mv_1097.data.sc_atleast.f0;
            __auto_type r = _mv_1097.data.sc_atleast.f1;
            __auto_type f = _mv_1097.data.sc_atleast.f2;
            if (n == 1) {
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = sroiq_box_sc(arena, sroiq_sc_canon(arena, (*f))) } });
            } else {
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atleast, .data.sc_atleast = { .f0 = n, .f1 = r, .f2 = sroiq_box_sc(arena, sroiq_sc_canon(arena, (*f))) } });
            }
        }
        case sroiq_SConcept_sc_atmost:
        {
            __auto_type n = _mv_1097.data.sc_atmost.f0;
            __auto_type r = _mv_1097.data.sc_atmost.f1;
            __auto_type f = _mv_1097.data.sc_atmost.f2;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = n, .f1 = r, .f2 = sroiq_box_sc(arena, sroiq_sc_canon(arena, (*f))) } });
        }
        case sroiq_SConcept_sc_self:
        {
            __auto_type r = _mv_1097.data.sc_self;
            __auto_type _mv_1098 = r;
            switch (_mv_1098.tag) {
                case types_RoleId_inverse_role:
                {
                    __auto_type i = _mv_1098.data.inverse_role;
                    return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_self, .data.sc_self = ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = i }) });
                }
                default: {
                    return c;
                }
            }
        }
    }
    SLOP_UNREACHABLE();
}

sroiq_SConcept sroiq_canon_junction(slop_arena* arena, slop_list_sroiq_SConcept xs, uint8_t conj) {
    {
        __auto_type flat = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t zero = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                {
                    __auto_type cx = sroiq_sc_canon(arena, x);
                    __auto_type _mv_1099 = cx;
                    switch (_mv_1099.tag) {
                        case sroiq_SConcept_sc_top:
                        {
                            if (!(conj)) {
                                zero = 1;
                            }
                            break;
                        }
                        case sroiq_SConcept_sc_bottom:
                        {
                            if (conj) {
                                zero = 1;
                            }
                            break;
                        }
                        case sroiq_SConcept_sc_and:
                        {
                            __auto_type ys = _mv_1099.data.sc_and;
                            if (conj) {
                                {
                                    __auto_type _coll = ys;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type y = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(flat); __auto_type _item = (y); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            } else {
                                ({ __auto_type _lst_p = &(flat); __auto_type _item = (cx); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                            break;
                        }
                        case sroiq_SConcept_sc_or:
                        {
                            __auto_type ys = _mv_1099.data.sc_or;
                            if (conj) {
                                ({ __auto_type _lst_p = &(flat); __auto_type _item = (cx); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else {
                                {
                                    __auto_type _coll = ys;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type y = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(flat); __auto_type _item = (y); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                            break;
                        }
                        default: {
                            ({ __auto_type _lst_p = &(flat); __auto_type _item = (cx); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                    }
                }
            }
        }
        if (zero) {
            if (conj) {
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_bottom });
            } else {
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_top });
            }
        } else {
            {
                __auto_type sorted = sroiq_sort_sconcepts(arena, flat);
                if (((int64_t)((sorted).len)) == 0) {
                    if (conj) {
                        return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_top });
                    } else {
                        return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_bottom });
                    }
                } else if (((int64_t)((sorted).len)) == 1) {
                    return sroiq_sc_at(sorted, 0);
                } else {
                    if (conj) {
                        return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_and, .data.sc_and = sorted });
                    } else {
                        return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_or, .data.sc_or = sorted });
                    }
                }
            }
        }
    }
}

sroiq_SAxiom sroiq_sa_at(slop_list_sroiq_SAxiom xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_1100 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_sroiq_SAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1100.has_value) {
        __auto_type v = _mv_1100.value;
        return v;
    } else if (!_mv_1100.has_value) {
        return ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_ref, .data.sa_ref = ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = 0 }) });
    }
    SLOP_UNREACHABLE();
}

slop_list_sroiq_SAxiom sroiq_sort_saxioms(slop_arena* arena, slop_list_sroiq_SAxiom xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ sroiq__lambda_1101_env_t* sroiq__lambda_1101_env = (sroiq__lambda_1101_env_t*)slop_arena_alloc(arena, sizeof(sroiq__lambda_1101_env_t)); *sroiq__lambda_1101_env = (sroiq__lambda_1101_env_t){ .xs = xs }; (slop_closure_t){ (void*)sroiq__lambda_1101, (void*)sroiq__lambda_1101_env }; }));
        __auto_type out = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sroiq_sa_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_sroiq_SAxiom sroiq_dedupe_saxioms(slop_arena* arena, slop_list_sroiq_SAxiom xs) {
    {
        __auto_type out = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t have = 0;
        __auto_type last = ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_ref, .data.sa_ref = ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = 0 }) });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (!(have) || (sroiq_sa_cmp(a, last) != 0)) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    last = a;
                    have = 1;
                }
            }
        }
        return out;
    }
}

slop_string sroiq_render_srole(slop_arena* arena, types_RoleId r) {
    __auto_type _mv_1102 = r;
    switch (_mv_1102.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_1102.data.named_role;
            return i.value;
        }
        case types_RoleId_inverse_role:
        {
            __auto_type i = _mv_1102.data.inverse_role;
            return string_concat(arena, i.value, SLOP_STR("⁻"));
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_1102.data.fresh_role;
            return SLOP_STR("_:fresh-role");
        }
    }
    SLOP_UNREACHABLE();
}

slop_string sroiq_render_sconcepts(slop_arena* arena, slop_list_sroiq_SConcept xs, slop_string sep) {
    {
        __auto_type out = SLOP_STR("");
        uint8_t first = 1;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (!(first)) {
                    out = string_concat(arena, out, sep);
                }
                out = string_concat(arena, out, sroiq_render_sconcept(arena, x));
                first = 0;
            }
        }
        return out;
    }
}

slop_string sroiq_render_restriction(slop_arena* arena, slop_string head, types_RoleId r, sroiq_SConcept f) {
    return string_concat(arena, head, string_concat(arena, sroiq_render_srole(arena, r), string_concat(arena, SLOP_STR("."), sroiq_render_sconcept(arena, f))));
}

slop_string sroiq_render_sconcept(slop_arena* arena, sroiq_SConcept c) {
    __auto_type _mv_1103 = c;
    switch (_mv_1103.tag) {
        case sroiq_SConcept_sc_top:
        {
            return SLOP_STR("⊤");
        }
        case sroiq_SConcept_sc_bottom:
        {
            return SLOP_STR("⊥");
        }
        case sroiq_SConcept_sc_name:
        {
            __auto_type i = _mv_1103.data.sc_name;
            return i.value;
        }
        case sroiq_SConcept_sc_nominal:
        {
            __auto_type i = _mv_1103.data.sc_nominal;
            return string_concat(arena, SLOP_STR("{"), string_concat(arena, i.value, SLOP_STR("}")));
        }
        case sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_1103.data.sc_not;
            return string_concat(arena, SLOP_STR("¬"), sroiq_render_sconcept(arena, (*f)));
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_1103.data.sc_and;
            return string_concat(arena, SLOP_STR("("), string_concat(arena, sroiq_render_sconcepts(arena, xs, SLOP_STR(" ⊓ ")), SLOP_STR(")")));
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_1103.data.sc_or;
            return string_concat(arena, SLOP_STR("("), string_concat(arena, sroiq_render_sconcepts(arena, xs, SLOP_STR(" ⊔ ")), SLOP_STR(")")));
        }
        case sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_1103.data.sc_some.f0;
            __auto_type f = _mv_1103.data.sc_some.f1;
            return sroiq_render_restriction(arena, SLOP_STR("∃"), r, (*f));
        }
        case sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_1103.data.sc_all.f0;
            __auto_type f = _mv_1103.data.sc_all.f1;
            return sroiq_render_restriction(arena, SLOP_STR("∀"), r, (*f));
        }
        case sroiq_SConcept_sc_atleast:
        {
            __auto_type n = _mv_1103.data.sc_atleast.f0;
            __auto_type r = _mv_1103.data.sc_atleast.f1;
            __auto_type f = _mv_1103.data.sc_atleast.f2;
            return sroiq_render_restriction(arena, string_concat(arena, SLOP_STR("≥"), string_concat(arena, int_to_string(arena, n), SLOP_STR(" "))), r, (*f));
        }
        case sroiq_SConcept_sc_atmost:
        {
            __auto_type n = _mv_1103.data.sc_atmost.f0;
            __auto_type r = _mv_1103.data.sc_atmost.f1;
            __auto_type f = _mv_1103.data.sc_atmost.f2;
            return sroiq_render_restriction(arena, string_concat(arena, SLOP_STR("≤"), string_concat(arena, int_to_string(arena, n), SLOP_STR(" "))), r, (*f));
        }
        case sroiq_SConcept_sc_self:
        {
            __auto_type r = _mv_1103.data.sc_self;
            return string_concat(arena, SLOP_STR("∃"), string_concat(arena, sroiq_render_srole(arena, r), SLOP_STR(".Self")));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string sroiq_render_word(slop_arena* arena, slop_list_types_RoleId w) {
    {
        __auto_type out = SLOP_STR("");
        uint8_t first = 1;
        {
            __auto_type _coll = w;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                if (!(first)) {
                    out = string_concat(arena, out, SLOP_STR(" ∘ "));
                }
                out = string_concat(arena, out, sroiq_render_srole(arena, r));
                first = 0;
            }
        }
        return out;
    }
}

slop_string sroiq_render_saxiom(slop_arena* arena, sroiq_SAxiom a) {
    __auto_type _mv_1104 = a;
    switch (_mv_1104.tag) {
        case sroiq_SAxiom_sa_gci:
        {
            __auto_type l = _mv_1104.data.sa_gci.f0;
            __auto_type r = _mv_1104.data.sa_gci.f1;
            return string_concat(arena, sroiq_render_sconcept(arena, (*l)), string_concat(arena, SLOP_STR(" ⊑ "), sroiq_render_sconcept(arena, (*r))));
        }
        case sroiq_SAxiom_sa_ria:
        {
            __auto_type x = _mv_1104.data.sa_ria;
            return string_concat(arena, sroiq_render_word(arena, x.word), string_concat(arena, SLOP_STR(" ⊑ "), sroiq_render_srole(arena, x.super)));
        }
        case sroiq_SAxiom_sa_ref:
        {
            __auto_type r = _mv_1104.data.sa_ref;
            return string_concat(arena, SLOP_STR("Ref("), string_concat(arena, sroiq_render_srole(arena, r), SLOP_STR(")")));
        }
        case sroiq_SAxiom_sa_irr:
        {
            __auto_type r = _mv_1104.data.sa_irr;
            return string_concat(arena, SLOP_STR("Irr("), string_concat(arena, sroiq_render_srole(arena, r), SLOP_STR(")")));
        }
        case sroiq_SAxiom_sa_dis:
        {
            __auto_type r = _mv_1104.data.sa_dis.f0;
            __auto_type s = _mv_1104.data.sa_dis.f1;
            return string_concat(arena, SLOP_STR("Dis("), string_concat(arena, sroiq_render_srole(arena, r), string_concat(arena, SLOP_STR(", "), string_concat(arena, sroiq_render_srole(arena, s), SLOP_STR(")")))));
        }
    }
    SLOP_UNREACHABLE();
}

