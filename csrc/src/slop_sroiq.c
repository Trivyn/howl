#include "../runtime/slop_runtime.h"
#include "slop_sroiq.h"

sroiq_SConcept* sroiq_box_sc(slop_arena* arena, sroiq_SConcept c);
types_RoleId sroiq_inv_role(types_RoleId r);
uint8_t sroiq_sc_top_p(sroiq_SConcept c);
int64_t sroiq_sc_rank(sroiq_SConcept c);
int64_t sroiq_elim_rank(sroiq_ElimKind k);
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
slop_string sroiq_role_key_s(slop_arena* arena, types_RoleId r);
slop_string sroiq_sc_keys(slop_arena* arena, slop_list_sroiq_SConcept xs);
slop_string sroiq_sc_key_r(slop_arena* arena, slop_string head, types_RoleId r, sroiq_SConcept f);
slop_string sroiq_sc_key(slop_arena* arena, sroiq_SConcept c);
slop_string sroiq_elim_tag(sroiq_ElimKind k);
slop_string sroiq_elim_head(sroiq_ElimKind k);
slop_string sroiq_render_srole(slop_arena* arena, types_RoleId r);
slop_string sroiq_render_sconcepts(slop_arena* arena, slop_list_sroiq_SConcept xs, slop_string sep);
slop_string sroiq_render_restriction(slop_arena* arena, slop_string head, types_RoleId r, sroiq_SConcept f);
slop_string sroiq_render_sconcept(slop_arena* arena, sroiq_SConcept c);
slop_string sroiq_render_word(slop_arena* arena, slop_list_types_RoleId w);
slop_string sroiq_render_saxiom(slop_arena* arena, sroiq_SAxiom a);

typedef struct { slop_list_sroiq_SConcept xs; } sroiq__lambda_239_env_t;

static int64_t sroiq__lambda_239(sroiq__lambda_239_env_t* _env, int64_t i, int64_t j) { return sroiq_sc_cmp(sroiq_sc_at(_env->xs, i), sroiq_sc_at(_env->xs, j)); }

typedef struct { slop_list_sroiq_SAxiom xs; } sroiq__lambda_244_env_t;

static int64_t sroiq__lambda_244(sroiq__lambda_244_env_t* _env, int64_t i, int64_t j) { return sroiq_sa_cmp(sroiq_sa_at(_env->xs, i), sroiq_sa_at(_env->xs, j)); }

sroiq_SConcept* sroiq_box_sc(slop_arena* arena, sroiq_SConcept c) {
    {
        __auto_type p = ((sroiq_SConcept*)(({ __auto_type _alloc = (sroiq_SConcept*)slop_arena_alloc(arena, sizeof(sroiq_SConcept)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = c;
        return p;
    }
}

types_RoleId sroiq_inv_role(types_RoleId r) {
    __auto_type _mv_213 = r;
    switch (_mv_213.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_213.data.named_role;
            return ((types_RoleId){ .tag = types_RoleId_inverse_role, .data.inverse_role = i });
        }
        case types_RoleId_inverse_role:
        {
            __auto_type i = _mv_213.data.inverse_role;
            return ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = i });
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_213.data.fresh_role;
            return r;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t sroiq_sc_top_p(sroiq_SConcept c) {
    __auto_type _mv_214 = c;
    switch (_mv_214.tag) {
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
    __auto_type _mv_215 = c;
    switch (_mv_215.tag) {
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
            __auto_type _ = _mv_215.data.sc_name;
            return 2;
        }
        case sroiq_SConcept_sc_nominal:
        {
            __auto_type _ = _mv_215.data.sc_nominal;
            return 3;
        }
        case sroiq_SConcept_sc_not:
        {
            __auto_type _ = _mv_215.data.sc_not;
            return 4;
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type _ = _mv_215.data.sc_and;
            return 5;
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type _ = _mv_215.data.sc_or;
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
            __auto_type _ = _mv_215.data.sc_self;
            return 11;
        }
        case sroiq_SConcept_sc_elim:
        {
            return 12;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t sroiq_elim_rank(sroiq_ElimKind k) {
    __auto_type _mv_216 = k;
    if (_mv_216 == sroiq_ElimKind_ek_i_all) {
        return 0;
    } else if (_mv_216 == sroiq_ElimKind_ek_f_all) {
        return 1;
    } else if (_mv_216 == sroiq_ElimKind_ek_i_some) {
        return 2;
    } else if (_mv_216 == sroiq_ElimKind_ek_f_some) {
        return 3;
    }
    SLOP_UNREACHABLE();
}

sroiq_SConcept sroiq_sc_at(slop_list_sroiq_SConcept xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_217 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_sroiq_SConcept _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_217.has_value) {
        __auto_type v = _mv_217.value;
        return v;
    } else if (!_mv_217.has_value) {
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
            __auto_type _mv_218 = a;
            switch (_mv_218.tag) {
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
                    __auto_type ia = _mv_218.data.sc_name;
                    __auto_type _mv_219 = b;
                    switch (_mv_219.tag) {
                        case sroiq_SConcept_sc_name:
                        {
                            __auto_type ib = _mv_219.data.sc_name;
                            return canon_iri_cmp(ia, ib);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_nominal:
                {
                    __auto_type ia = _mv_218.data.sc_nominal;
                    __auto_type _mv_220 = b;
                    switch (_mv_220.tag) {
                        case sroiq_SConcept_sc_nominal:
                        {
                            __auto_type ib = _mv_220.data.sc_nominal;
                            return canon_iri_cmp(ia, ib);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_not:
                {
                    __auto_type fa = _mv_218.data.sc_not;
                    __auto_type _mv_221 = b;
                    switch (_mv_221.tag) {
                        case sroiq_SConcept_sc_not:
                        {
                            __auto_type fb = _mv_221.data.sc_not;
                            return sroiq_sc_cmp((*fa), (*fb));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_and:
                {
                    __auto_type xs = _mv_218.data.sc_and;
                    __auto_type _mv_222 = b;
                    switch (_mv_222.tag) {
                        case sroiq_SConcept_sc_and:
                        {
                            __auto_type ys = _mv_222.data.sc_and;
                            return sroiq_sc_list_cmp(xs, ys);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_or:
                {
                    __auto_type xs = _mv_218.data.sc_or;
                    __auto_type _mv_223 = b;
                    switch (_mv_223.tag) {
                        case sroiq_SConcept_sc_or:
                        {
                            __auto_type ys = _mv_223.data.sc_or;
                            return sroiq_sc_list_cmp(xs, ys);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_some:
                {
                    __auto_type ra = _mv_218.data.sc_some.f0;
                    __auto_type fa = _mv_218.data.sc_some.f1;
                    __auto_type _mv_224 = b;
                    switch (_mv_224.tag) {
                        case sroiq_SConcept_sc_some:
                        {
                            __auto_type rb = _mv_224.data.sc_some.f0;
                            __auto_type fb = _mv_224.data.sc_some.f1;
                            return sroiq_role_then(ra, rb, (*fa), (*fb));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_all:
                {
                    __auto_type ra = _mv_218.data.sc_all.f0;
                    __auto_type fa = _mv_218.data.sc_all.f1;
                    __auto_type _mv_225 = b;
                    switch (_mv_225.tag) {
                        case sroiq_SConcept_sc_all:
                        {
                            __auto_type rb = _mv_225.data.sc_all.f0;
                            __auto_type fb = _mv_225.data.sc_all.f1;
                            return sroiq_role_then(ra, rb, (*fa), (*fb));
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_atleast:
                {
                    __auto_type na = _mv_218.data.sc_atleast.f0;
                    __auto_type ra = _mv_218.data.sc_atleast.f1;
                    __auto_type fa = _mv_218.data.sc_atleast.f2;
                    __auto_type _mv_226 = b;
                    switch (_mv_226.tag) {
                        case sroiq_SConcept_sc_atleast:
                        {
                            __auto_type nb = _mv_226.data.sc_atleast.f0;
                            __auto_type rb = _mv_226.data.sc_atleast.f1;
                            __auto_type fb = _mv_226.data.sc_atleast.f2;
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
                    __auto_type na = _mv_218.data.sc_atmost.f0;
                    __auto_type ra = _mv_218.data.sc_atmost.f1;
                    __auto_type fa = _mv_218.data.sc_atmost.f2;
                    __auto_type _mv_227 = b;
                    switch (_mv_227.tag) {
                        case sroiq_SConcept_sc_atmost:
                        {
                            __auto_type nb = _mv_227.data.sc_atmost.f0;
                            __auto_type rb = _mv_227.data.sc_atmost.f1;
                            __auto_type fb = _mv_227.data.sc_atmost.f2;
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
                    __auto_type ra = _mv_218.data.sc_self;
                    __auto_type _mv_228 = b;
                    switch (_mv_228.tag) {
                        case sroiq_SConcept_sc_self:
                        {
                            __auto_type rb = _mv_228.data.sc_self;
                            return canon_role_cmp(ra, rb);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SConcept_sc_elim:
                {
                    __auto_type ka = _mv_218.data.sc_elim.f0;
                    __auto_type ra = _mv_218.data.sc_elim.f1;
                    __auto_type fa = _mv_218.data.sc_elim.f2;
                    __auto_type _mv_229 = b;
                    switch (_mv_229.tag) {
                        case sroiq_SConcept_sc_elim:
                        {
                            __auto_type kb = _mv_229.data.sc_elim.f0;
                            __auto_type rb = _mv_229.data.sc_elim.f1;
                            __auto_type fb = _mv_229.data.sc_elim.f2;
                            {
                                __auto_type kk = sroiq_int_cmp(sroiq_elim_rank(ka), sroiq_elim_rank(kb));
                                if (kk != 0) {
                                    return kk;
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
            __auto_type _mv_230 = ({ __auto_type _lst = a; size_t _idx = (size_t)i; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_230.has_value) {
                __auto_type x = _mv_230.value;
                __auto_type _mv_231 = ({ __auto_type _lst = b; size_t _idx = (size_t)i; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_231.has_value) {
                    __auto_type y = _mv_231.value;
                    r = canon_role_cmp(x, y);
                } else if (!_mv_231.has_value) {
                }
            } else if (!_mv_230.has_value) {
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
    __auto_type _mv_232 = a;
    switch (_mv_232.tag) {
        case sroiq_SAxiom_sa_gci:
        {
            return 0;
        }
        case sroiq_SAxiom_sa_ria:
        {
            __auto_type _ = _mv_232.data.sa_ria;
            return 1;
        }
        case sroiq_SAxiom_sa_ref:
        {
            __auto_type _ = _mv_232.data.sa_ref;
            return 2;
        }
        case sroiq_SAxiom_sa_irr:
        {
            __auto_type _ = _mv_232.data.sa_irr;
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
            __auto_type _mv_233 = a;
            switch (_mv_233.tag) {
                case sroiq_SAxiom_sa_gci:
                {
                    __auto_type la = _mv_233.data.sa_gci.f0;
                    __auto_type ra = _mv_233.data.sa_gci.f1;
                    __auto_type _mv_234 = b;
                    switch (_mv_234.tag) {
                        case sroiq_SAxiom_sa_gci:
                        {
                            __auto_type lb = _mv_234.data.sa_gci.f0;
                            __auto_type rb = _mv_234.data.sa_gci.f1;
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
                    __auto_type x = _mv_233.data.sa_ria;
                    __auto_type _mv_235 = b;
                    switch (_mv_235.tag) {
                        case sroiq_SAxiom_sa_ria:
                        {
                            __auto_type y = _mv_235.data.sa_ria;
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
                    __auto_type r = _mv_233.data.sa_ref;
                    __auto_type _mv_236 = b;
                    switch (_mv_236.tag) {
                        case sroiq_SAxiom_sa_ref:
                        {
                            __auto_type q = _mv_236.data.sa_ref;
                            return canon_role_cmp(r, q);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SAxiom_sa_irr:
                {
                    __auto_type r = _mv_233.data.sa_irr;
                    __auto_type _mv_237 = b;
                    switch (_mv_237.tag) {
                        case sroiq_SAxiom_sa_irr:
                        {
                            __auto_type q = _mv_237.data.sa_irr;
                            return canon_role_cmp(r, q);
                        }
                        default: {
                            return 0;
                        }
                    }
                }
                case sroiq_SAxiom_sa_dis:
                {
                    __auto_type r1 = _mv_233.data.sa_dis.f0;
                    __auto_type r2 = _mv_233.data.sa_dis.f1;
                    __auto_type _mv_238 = b;
                    switch (_mv_238.tag) {
                        case sroiq_SAxiom_sa_dis:
                        {
                            __auto_type q1 = _mv_238.data.sa_dis.f0;
                            __auto_type q2 = _mv_238.data.sa_dis.f1;
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
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ sroiq__lambda_239_env_t* sroiq__lambda_239_env = (sroiq__lambda_239_env_t*)slop_arena_alloc(arena, sizeof(sroiq__lambda_239_env_t)); *sroiq__lambda_239_env = (sroiq__lambda_239_env_t){ .xs = xs }; (slop_closure_t){ (void*)sroiq__lambda_239, (void*)sroiq__lambda_239_env }; }));
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
    __auto_type _mv_240 = c;
    switch (_mv_240.tag) {
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
            __auto_type _ = _mv_240.data.sc_name;
            return c;
        }
        case sroiq_SConcept_sc_nominal:
        {
            __auto_type _ = _mv_240.data.sc_nominal;
            return c;
        }
        case sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_240.data.sc_not;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_not, .data.sc_not = sroiq_box_sc(arena, sroiq_sc_canon(arena, (*f))) });
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_240.data.sc_and;
            return sroiq_canon_junction(arena, xs, 1);
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_240.data.sc_or;
            return sroiq_canon_junction(arena, xs, 0);
        }
        case sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_240.data.sc_some.f0;
            __auto_type f = _mv_240.data.sc_some.f1;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = sroiq_box_sc(arena, sroiq_sc_canon(arena, (*f))) } });
        }
        case sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_240.data.sc_all.f0;
            __auto_type f = _mv_240.data.sc_all.f1;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = sroiq_box_sc(arena, sroiq_sc_canon(arena, (*f))) } });
        }
        case sroiq_SConcept_sc_atleast:
        {
            __auto_type n = _mv_240.data.sc_atleast.f0;
            __auto_type r = _mv_240.data.sc_atleast.f1;
            __auto_type f = _mv_240.data.sc_atleast.f2;
            if (n == 1) {
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = sroiq_box_sc(arena, sroiq_sc_canon(arena, (*f))) } });
            } else {
                return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atleast, .data.sc_atleast = { .f0 = n, .f1 = r, .f2 = sroiq_box_sc(arena, sroiq_sc_canon(arena, (*f))) } });
            }
        }
        case sroiq_SConcept_sc_atmost:
        {
            __auto_type n = _mv_240.data.sc_atmost.f0;
            __auto_type r = _mv_240.data.sc_atmost.f1;
            __auto_type f = _mv_240.data.sc_atmost.f2;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = n, .f1 = r, .f2 = sroiq_box_sc(arena, sroiq_sc_canon(arena, (*f))) } });
        }
        case sroiq_SConcept_sc_self:
        {
            __auto_type r = _mv_240.data.sc_self;
            __auto_type _mv_241 = r;
            switch (_mv_241.tag) {
                case types_RoleId_inverse_role:
                {
                    __auto_type i = _mv_241.data.inverse_role;
                    return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_self, .data.sc_self = ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = i }) });
                }
                default: {
                    return c;
                }
            }
        }
        case sroiq_SConcept_sc_elim:
        {
            return c;
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
                    __auto_type _mv_242 = cx;
                    switch (_mv_242.tag) {
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
                            __auto_type ys = _mv_242.data.sc_and;
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
                            __auto_type ys = _mv_242.data.sc_or;
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
    __auto_type _mv_243 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_sroiq_SAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_243.has_value) {
        __auto_type v = _mv_243.value;
        return v;
    } else if (!_mv_243.has_value) {
        return ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_ref, .data.sa_ref = ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = 0 }) });
    }
    SLOP_UNREACHABLE();
}

slop_list_sroiq_SAxiom sroiq_sort_saxioms(slop_arena* arena, slop_list_sroiq_SAxiom xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ sroiq__lambda_244_env_t* sroiq__lambda_244_env = (sroiq__lambda_244_env_t*)slop_arena_alloc(arena, sizeof(sroiq__lambda_244_env_t)); *sroiq__lambda_244_env = (sroiq__lambda_244_env_t){ .xs = xs }; (slop_closure_t){ (void*)sroiq__lambda_244, (void*)sroiq__lambda_244_env }; }));
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

slop_string sroiq_role_key_s(slop_arena* arena, types_RoleId r) {
    __auto_type _mv_245 = r;
    switch (_mv_245.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_245.data.named_role;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">")));
        }
        case types_RoleId_inverse_role:
        {
            __auto_type i = _mv_245.data.inverse_role;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">^")));
        }
        case types_RoleId_fresh_role:
        {
            __auto_type k = _mv_245.data.fresh_role;
            return string_concat(arena, SLOP_STR("#"), int_to_string(arena, k));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string sroiq_sc_keys(slop_arena* arena, slop_list_sroiq_SConcept xs) {
    {
        __auto_type out = SLOP_STR("");
        uint8_t first = 1;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (!(first)) {
                    out = string_concat(arena, out, SLOP_STR(","));
                }
                out = string_concat(arena, out, sroiq_sc_key(arena, x));
                first = 0;
            }
        }
        return out;
    }
}

slop_string sroiq_sc_key_r(slop_arena* arena, slop_string head, types_RoleId r, sroiq_SConcept f) {
    return string_concat(arena, head, string_concat(arena, SLOP_STR("("), string_concat(arena, sroiq_role_key_s(arena, r), string_concat(arena, SLOP_STR(","), string_concat(arena, sroiq_sc_key(arena, f), SLOP_STR(")"))))));
}

slop_string sroiq_sc_key(slop_arena* arena, sroiq_SConcept c) {
    __auto_type _mv_246 = c;
    switch (_mv_246.tag) {
        case sroiq_SConcept_sc_top:
        {
            return SLOP_STR("T");
        }
        case sroiq_SConcept_sc_bottom:
        {
            return SLOP_STR("F");
        }
        case sroiq_SConcept_sc_name:
        {
            __auto_type i = _mv_246.data.sc_name;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">")));
        }
        case sroiq_SConcept_sc_nominal:
        {
            __auto_type i = _mv_246.data.sc_nominal;
            return string_concat(arena, SLOP_STR("{<"), string_concat(arena, i.value, SLOP_STR(">}")));
        }
        case sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_246.data.sc_not;
            return string_concat(arena, SLOP_STR("not("), string_concat(arena, sroiq_sc_key(arena, (*f)), SLOP_STR(")")));
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_246.data.sc_and;
            return string_concat(arena, SLOP_STR("and("), string_concat(arena, sroiq_sc_keys(arena, xs), SLOP_STR(")")));
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_246.data.sc_or;
            return string_concat(arena, SLOP_STR("or("), string_concat(arena, sroiq_sc_keys(arena, xs), SLOP_STR(")")));
        }
        case sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_246.data.sc_some.f0;
            __auto_type f = _mv_246.data.sc_some.f1;
            return sroiq_sc_key_r(arena, SLOP_STR("some"), r, (*f));
        }
        case sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_246.data.sc_all.f0;
            __auto_type f = _mv_246.data.sc_all.f1;
            return sroiq_sc_key_r(arena, SLOP_STR("all"), r, (*f));
        }
        case sroiq_SConcept_sc_atleast:
        {
            __auto_type n = _mv_246.data.sc_atleast.f0;
            __auto_type r = _mv_246.data.sc_atleast.f1;
            __auto_type f = _mv_246.data.sc_atleast.f2;
            return sroiq_sc_key_r(arena, string_concat(arena, SLOP_STR("ge"), int_to_string(arena, n)), r, (*f));
        }
        case sroiq_SConcept_sc_atmost:
        {
            __auto_type n = _mv_246.data.sc_atmost.f0;
            __auto_type r = _mv_246.data.sc_atmost.f1;
            __auto_type f = _mv_246.data.sc_atmost.f2;
            return sroiq_sc_key_r(arena, string_concat(arena, SLOP_STR("le"), int_to_string(arena, n)), r, (*f));
        }
        case sroiq_SConcept_sc_self:
        {
            __auto_type r = _mv_246.data.sc_self;
            return string_concat(arena, SLOP_STR("self("), string_concat(arena, sroiq_role_key_s(arena, r), SLOP_STR(")")));
        }
        case sroiq_SConcept_sc_elim:
        {
            __auto_type k = _mv_246.data.sc_elim.f0;
            __auto_type r = _mv_246.data.sc_elim.f1;
            __auto_type f = _mv_246.data.sc_elim.f2;
            return sroiq_sc_key_r(arena, sroiq_elim_tag(k), r, (*f));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string sroiq_elim_tag(sroiq_ElimKind k) {
    __auto_type _mv_247 = k;
    if (_mv_247 == sroiq_ElimKind_ek_i_all) {
        return SLOP_STR("eia");
    } else if (_mv_247 == sroiq_ElimKind_ek_f_all) {
        return SLOP_STR("efa");
    } else if (_mv_247 == sroiq_ElimKind_ek_i_some) {
        return SLOP_STR("eis");
    } else if (_mv_247 == sroiq_ElimKind_ek_f_some) {
        return SLOP_STR("efs");
    }
    SLOP_UNREACHABLE();
}

slop_string sroiq_elim_head(sroiq_ElimKind k) {
    __auto_type _mv_248 = k;
    if (_mv_248 == sroiq_ElimKind_ek_i_all) {
        return SLOP_STR("I[∀");
    } else if (_mv_248 == sroiq_ElimKind_ek_f_all) {
        return SLOP_STR("F[∀");
    } else if (_mv_248 == sroiq_ElimKind_ek_i_some) {
        return SLOP_STR("I[∃");
    } else if (_mv_248 == sroiq_ElimKind_ek_f_some) {
        return SLOP_STR("F[∃");
    }
    SLOP_UNREACHABLE();
}

slop_string sroiq_render_srole(slop_arena* arena, types_RoleId r) {
    __auto_type _mv_249 = r;
    switch (_mv_249.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_249.data.named_role;
            return i.value;
        }
        case types_RoleId_inverse_role:
        {
            __auto_type i = _mv_249.data.inverse_role;
            return string_concat(arena, i.value, SLOP_STR("⁻"));
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_249.data.fresh_role;
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
    __auto_type _mv_250 = c;
    switch (_mv_250.tag) {
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
            __auto_type i = _mv_250.data.sc_name;
            return i.value;
        }
        case sroiq_SConcept_sc_nominal:
        {
            __auto_type i = _mv_250.data.sc_nominal;
            return string_concat(arena, SLOP_STR("{"), string_concat(arena, i.value, SLOP_STR("}")));
        }
        case sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_250.data.sc_not;
            return string_concat(arena, SLOP_STR("¬"), sroiq_render_sconcept(arena, (*f)));
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_250.data.sc_and;
            return string_concat(arena, SLOP_STR("("), string_concat(arena, sroiq_render_sconcepts(arena, xs, SLOP_STR(" ⊓ ")), SLOP_STR(")")));
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_250.data.sc_or;
            return string_concat(arena, SLOP_STR("("), string_concat(arena, sroiq_render_sconcepts(arena, xs, SLOP_STR(" ⊔ ")), SLOP_STR(")")));
        }
        case sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_250.data.sc_some.f0;
            __auto_type f = _mv_250.data.sc_some.f1;
            return sroiq_render_restriction(arena, SLOP_STR("∃"), r, (*f));
        }
        case sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_250.data.sc_all.f0;
            __auto_type f = _mv_250.data.sc_all.f1;
            return sroiq_render_restriction(arena, SLOP_STR("∀"), r, (*f));
        }
        case sroiq_SConcept_sc_atleast:
        {
            __auto_type n = _mv_250.data.sc_atleast.f0;
            __auto_type r = _mv_250.data.sc_atleast.f1;
            __auto_type f = _mv_250.data.sc_atleast.f2;
            return sroiq_render_restriction(arena, string_concat(arena, SLOP_STR("≥"), string_concat(arena, int_to_string(arena, n), SLOP_STR(" "))), r, (*f));
        }
        case sroiq_SConcept_sc_atmost:
        {
            __auto_type n = _mv_250.data.sc_atmost.f0;
            __auto_type r = _mv_250.data.sc_atmost.f1;
            __auto_type f = _mv_250.data.sc_atmost.f2;
            return sroiq_render_restriction(arena, string_concat(arena, SLOP_STR("≤"), string_concat(arena, int_to_string(arena, n), SLOP_STR(" "))), r, (*f));
        }
        case sroiq_SConcept_sc_self:
        {
            __auto_type r = _mv_250.data.sc_self;
            return string_concat(arena, SLOP_STR("∃"), string_concat(arena, sroiq_render_srole(arena, r), SLOP_STR(".Self")));
        }
        case sroiq_SConcept_sc_elim:
        {
            __auto_type k = _mv_250.data.sc_elim.f0;
            __auto_type r = _mv_250.data.sc_elim.f1;
            __auto_type f = _mv_250.data.sc_elim.f2;
            return string_concat(arena, sroiq_render_restriction(arena, sroiq_elim_head(k), r, (*f)), SLOP_STR("]"));
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
    __auto_type _mv_251 = a;
    switch (_mv_251.tag) {
        case sroiq_SAxiom_sa_gci:
        {
            __auto_type l = _mv_251.data.sa_gci.f0;
            __auto_type r = _mv_251.data.sa_gci.f1;
            return string_concat(arena, sroiq_render_sconcept(arena, (*l)), string_concat(arena, SLOP_STR(" ⊑ "), sroiq_render_sconcept(arena, (*r))));
        }
        case sroiq_SAxiom_sa_ria:
        {
            __auto_type x = _mv_251.data.sa_ria;
            return string_concat(arena, sroiq_render_word(arena, x.word), string_concat(arena, SLOP_STR(" ⊑ "), sroiq_render_srole(arena, x.super)));
        }
        case sroiq_SAxiom_sa_ref:
        {
            __auto_type r = _mv_251.data.sa_ref;
            return string_concat(arena, SLOP_STR("Ref("), string_concat(arena, sroiq_render_srole(arena, r), SLOP_STR(")")));
        }
        case sroiq_SAxiom_sa_irr:
        {
            __auto_type r = _mv_251.data.sa_irr;
            return string_concat(arena, SLOP_STR("Irr("), string_concat(arena, sroiq_render_srole(arena, r), SLOP_STR(")")));
        }
        case sroiq_SAxiom_sa_dis:
        {
            __auto_type r = _mv_251.data.sa_dis.f0;
            __auto_type s = _mv_251.data.sa_dis.f1;
            return string_concat(arena, SLOP_STR("Dis("), string_concat(arena, sroiq_render_srole(arena, r), string_concat(arena, SLOP_STR(", "), string_concat(arena, sroiq_render_srole(arena, s), SLOP_STR(")")))));
        }
    }
    SLOP_UNREACHABLE();
}

