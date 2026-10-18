#include "../runtime/slop_runtime.h"
#include "slop_sriqelim.h"


uint8_t howl_sriqelim_nonsimple(howl_sriqrbox_SriqRbox rb, howl_types_RoleId r);
uint8_t howl_sriqelim_role_eq(howl_types_RoleId a, howl_types_RoleId b);
uint8_t howl_sriqelim_ria_complex(howl_sriqrbox_SriqRbox rb, howl_sroiq_SRia x);
howl_types_RoleId howl_sriqelim_role_at(slop_list_howl_types_RoleId w, int64_t i);
slop_list_howl_types_RoleId howl_sriqelim_slice(slop_arena* arena, slop_list_howl_types_RoleId w, int64_t from, int64_t upto);
slop_list_howl_types_RoleId howl_sriqelim_inv_word(slop_arena* arena, slop_list_howl_types_RoleId w);
slop_list_howl_sroiq_SRia howl_sriqelim_rc_of(slop_arena* arena, howl_sriqrbox_SriqRbox rb, howl_sroiq_SAxiom a);
slop_list_howl_sroiq_SRia howl_sriqelim_build_rc(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SAxiom axs);
uint8_t howl_sriqelim_symmetric(slop_list_howl_sroiq_SRia rc, howl_types_RoleId s);
uint8_t howl_sriqelim_holds_role(slop_list_howl_types_RoleId w, howl_types_RoleId s);
howl_sriqelim_S1State* howl_sriqelim_new_s1(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SRia rc, int64_t bound);
uint8_t howl_sriqelim_emit(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SAxiom a);
uint8_t howl_sriqelim_emit_gci(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept l, howl_sroiq_SConcept r);
uint8_t howl_sriqelim_fail(howl_sriqelim_S1State* p, slop_string m);
uint8_t howl_sriqelim_going(howl_sriqelim_S1State* p);
howl_sroiq_SConcept howl_sriqelim_atom(slop_arena* arena, howl_sroiq_ElimKind k, howl_types_RoleId r, howl_sroiq_SConcept f);
howl_sroiq_SConcept howl_sriqelim_label_name(slop_arena* arena, uint8_t forall, howl_types_RoleId r, howl_sroiq_SConcept f);
howl_sroiq_SConcept howl_sriqelim_label(slop_arena* arena, howl_sriqelim_S1State* p, uint8_t forall, howl_types_RoleId r, howl_sroiq_SConcept f);
howl_sroiq_SConcept howl_sriqelim_rewrite(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept c, uint8_t pos);
slop_list_howl_sroiq_SConcept howl_sriqelim_rewrite_each(slop_arena* arena, howl_sriqelim_S1State* p, slop_list_howl_sroiq_SConcept xs, uint8_t pos);
howl_sroiq_SConcept howl_sriqelim_rewrite_all(slop_arena* arena, howl_sriqelim_S1State* p, howl_types_RoleId r, howl_sroiq_SConcept f, uint8_t pos);
howl_sroiq_SConcept howl_sriqelim_rewrite_some(slop_arena* arena, howl_sriqelim_S1State* p, howl_types_RoleId r, howl_sroiq_SConcept f, uint8_t pos);
howl_sroiq_SConcept howl_sriqelim_chain_all(slop_arena* arena, slop_list_howl_types_RoleId w, howl_sroiq_SConcept x);
uint8_t howl_sriqelim_item(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept lhs, slop_list_howl_types_RoleId w, howl_sroiq_SConcept x, howl_types_RoleId s);
uint8_t howl_sriqelim_expand_ria(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept i, howl_types_RoleId s, howl_sroiq_SConcept f, slop_list_howl_types_RoleId w);
uint8_t howl_sriqelim_expand1(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept i, howl_types_RoleId s, howl_sroiq_SConcept f);
uint8_t howl_sriqelim_expand(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept i, howl_types_RoleId s, howl_sroiq_SConcept f);
uint8_t howl_sriqelim_expand_key(slop_arena* arena, howl_sriqelim_S1State* p, howl_sriqelim_Pending e);
howl_sriqelim_Pending howl_sriqelim_pending_at(slop_list_howl_sriqelim_Pending xs, int64_t i);
uint8_t howl_sriqelim_drain(slop_arena* arena, howl_sriqelim_S1State* p);
uint8_t howl_sriqelim_s1_init(slop_arena* arena, howl_sriqelim_S1State* p, slop_list_howl_sroiq_SAxiom axs);
uint8_t howl_sriqelim_is_chain(howl_sroiq_SAxiom a);
howl_sriqelim_S1 howl_sriqelim_guarded(slop_arena* arena, slop_list_howl_sroiq_SAxiom axs, int64_t count);
slop_result_howl_sriqelim_S1_string howl_sriqelim_s1_result(slop_arena* arena, howl_sriqnormal_S0 s0, howl_sriqelim_S1State* p);
slop_result_howl_sriqelim_S1_string howl_sriqelim_sriq_s1(slop_arena* arena, howl_sriqnormal_S0 s0, int64_t bound);
uint8_t howl_sriqelim_is_atom(howl_sroiq_SConcept c);
uint8_t howl_sriqelim_item1_p(howl_sroiq_SConcept l, howl_sroiq_SConcept r);
uint8_t howl_sriqelim_labelled_left(howl_sriqrbox_SriqRbox rb, howl_sroiq_SConcept c, uint8_t pos);
uint8_t howl_sriqelim_labelled_any(howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SConcept cs, uint8_t pos);
uint8_t howl_sriqelim_has_axiom(slop_list_howl_sroiq_SAxiom axs, howl_sroiq_SAxiom a);
howl_sroiq_SAxiom howl_sriqelim_def_gci(slop_arena* arena, howl_sroiq_SConcept l, howl_sroiq_SConcept r);
slop_list_howl_sroiq_SAxiom howl_sriqelim_all_axioms(slop_arena* arena, howl_sroiq_SConcept i, howl_types_RoleId r, howl_sroiq_SConcept c);
slop_list_howl_sroiq_SAxiom howl_sriqelim_some_axioms(slop_arena* arena, howl_sroiq_SConcept f, howl_types_RoleId r, howl_sroiq_SConcept c);
slop_list_howl_sroiq_SAxiom howl_sriqelim_atom_axioms(slop_arena* arena, howl_sroiq_SConcept c);
slop_list_howl_sroiq_SConcept howl_sriqelim_atoms_of(slop_arena* arena, howl_sroiq_SConcept c);
slop_list_howl_sroiq_SConcept howl_sriqelim_append_atoms(slop_arena* arena, slop_list_howl_sroiq_SConcept a, slop_list_howl_sroiq_SConcept b);
slop_list_string howl_sriqelim_axiom_problems(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SAxiom axs, howl_sroiq_SAxiom a);
uint8_t howl_sriqelim_same_axioms(slop_list_howl_sroiq_SAxiom a, slop_list_howl_sroiq_SAxiom b);
slop_list_string howl_sriqelim_guarded_problems(slop_arena* arena, slop_list_howl_sroiq_SAxiom s0_axioms, howl_sriqelim_S1 s1);
slop_list_string howl_sriqelim_sriq_s1_invariants(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SAxiom s0_axioms, howl_sriqelim_S1 s1);

uint8_t howl_sriqelim_nonsimple(howl_sriqrbox_SriqRbox rb, howl_types_RoleId r) {
    return !(howl_sriqrbox_sriq_role_simple(rb, r));
}

uint8_t howl_sriqelim_role_eq(howl_types_RoleId a, howl_types_RoleId b) {
    return (howl_canon_role_cmp(a, b) == 0);
}

uint8_t howl_sriqelim_ria_complex(howl_sriqrbox_SriqRbox rb, howl_sroiq_SRia x) {
    return ((((int64_t)((x.word).len)) > 1) || howl_sriqelim_nonsimple(rb, x.super));
}

howl_types_RoleId howl_sriqelim_role_at(slop_list_howl_types_RoleId w, int64_t i) {
    __auto_type _mv_317 = ({ __auto_type _lst = w; size_t _idx = (size_t)i; slop_option_howl_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_317.has_value) {
        __auto_type r = _mv_317.value;
        return r;
    } else if (!_mv_317.has_value) {
        return ((howl_types_RoleId){ .tag = howl_types_RoleId_fresh_role, .data.fresh_role = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_RoleId howl_sriqelim_slice(slop_arena* arena, slop_list_howl_types_RoleId w, int64_t from, int64_t upto) {
    {
        __auto_type out = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = from;
        while (i < upto) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqelim_role_at(w, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            i = (i + 1);
        }
        return out;
    }
}

slop_list_howl_types_RoleId howl_sriqelim_inv_word(slop_arena* arena, slop_list_howl_types_RoleId w) {
    {
        __auto_type out = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = (((int64_t)(((int64_t)((w).len)))) - 1);
        while (i >= 0) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sroiq_inv_role(howl_sriqelim_role_at(w, i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            i = (i - 1);
        }
        return out;
    }
}

slop_list_howl_sroiq_SRia howl_sriqelim_rc_of(slop_arena* arena, howl_sriqrbox_SriqRbox rb, howl_sroiq_SAxiom a) {
    {
        __auto_type out = ((slop_list_howl_sroiq_SRia){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_318 = a;
        switch (_mv_318.tag) {
            case howl_sroiq_SAxiom_sa_ria:
            {
                __auto_type x = _mv_318.data.sa_ria;
                if (howl_sriqelim_ria_complex(rb, x)) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sroiq_SRia){.word = howl_sriqelim_inv_word(arena, x.word), .super = howl_sroiq_inv_role(x.super)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

slop_list_howl_sroiq_SRia howl_sriqelim_build_rc(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SAxiom axs) {
    {
        __auto_type out = ((slop_list_howl_sroiq_SRia){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    __auto_type _coll = howl_sriqelim_rc_of(arena, rb, a);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

uint8_t howl_sriqelim_symmetric(slop_list_howl_sroiq_SRia rc, howl_types_RoleId s) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = rc;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if ((howl_sriqelim_role_eq(x.super, s)) && ((((int64_t)((x.word).len)) == 1)) && (howl_sriqelim_role_eq(howl_sriqelim_role_at(x.word, 0), howl_sroiq_inv_role(s)))) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t howl_sriqelim_holds_role(slop_list_howl_types_RoleId w, howl_types_RoleId s) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = w;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                if (howl_sriqelim_role_eq(r, s) || howl_sriqelim_role_eq(r, howl_sroiq_inv_role(s))) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

howl_sriqelim_S1State* howl_sriqelim_new_s1(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SRia rc, int64_t bound) {
    {
        __auto_type p = ((howl_sriqelim_S1State*)(({ __auto_type _alloc = (howl_sriqelim_S1State*)slop_arena_alloc(arena, sizeof(howl_sriqelim_S1State)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = ((howl_sriqelim_S1State){.rb = rb, .rc = rc, .out = ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .queue = ((slop_list_howl_sriqelim_Pending){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .count = 0, .bound = bound, .fault = (slop_option_string){.has_value = false}});
        return p;
    }
}

uint8_t howl_sriqelim_emit(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SAxiom a) {
    {
        __auto_type s = (*p);
        (void)(({ __auto_type _lst_p = &(s.out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (*p) = s;
        return 1;
    }
}

uint8_t howl_sriqelim_emit_gci(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept l, howl_sroiq_SConcept r) {
    return howl_sriqelim_emit(arena, p, ((howl_sroiq_SAxiom){ .tag = howl_sroiq_SAxiom_sa_gci, .data.sa_gci = { .f0 = howl_sroiq_box_sc(arena, howl_sroiq_sc_canon(arena, l)), .f1 = howl_sroiq_box_sc(arena, howl_sroiq_sc_canon(arena, r)) } }));
}

uint8_t howl_sriqelim_fail(howl_sriqelim_S1State* p, slop_string m) {
    {
        __auto_type s = (*p);
        s.fault = (slop_option_string){.has_value = 1, .value = m};
        (*p) = s;
        return 0;
    }
}

uint8_t howl_sriqelim_going(howl_sriqelim_S1State* p) {
    return (((*p).count <= (*p).bound) && ({ __auto_type _mv = (*p).fault; _mv.has_value ? ({ __auto_type _ = _mv.value; 0; }) : (1); }));
}

howl_sroiq_SConcept howl_sriqelim_atom(slop_arena* arena, howl_sroiq_ElimKind k, howl_types_RoleId r, howl_sroiq_SConcept f) {
    return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_elim, .data.sc_elim = { .f0 = k, .f1 = r, .f2 = howl_sroiq_box_sc(arena, f) } });
}

howl_sroiq_SConcept howl_sriqelim_label_name(slop_arena* arena, uint8_t forall, howl_types_RoleId r, howl_sroiq_SConcept f) {
    if (forall) {
        return howl_sriqelim_atom(arena, howl_sroiq_ElimKind_ek_i_all, r, f);
    } else {
        return howl_sriqelim_atom(arena, howl_sroiq_ElimKind_ek_f_some, r, f);
    }
}

howl_sroiq_SConcept howl_sriqelim_label(slop_arena* arena, howl_sriqelim_S1State* p, uint8_t forall, howl_types_RoleId r, howl_sroiq_SConcept f) {
    {
        __auto_type name = howl_sriqelim_label_name(arena, forall, r, f);
        __auto_type key = howl_sroiq_sc_key(arena, name);
        if (!(slop_map_has((*p).seen, &(key)))) {
            {
                __auto_type s = (*p);
                (void)(({ slop_map_put(NULL, s.seen, &(key), NULL, 0); }));
                (void)(({ __auto_type _lst_p = &(s.queue); __auto_type _item = (((howl_sriqelim_Pending){.forall = forall, .role = r, .filler = f})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                s.count = (s.count + 1);
                (*p) = s;
            }
        }
        return name;
    }
}

howl_sroiq_SConcept howl_sriqelim_rewrite(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept c, uint8_t pos) {
    __auto_type _mv_321 = c;
    switch (_mv_321.tag) {
        case howl_sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_321.data.sc_not;
            return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_not, .data.sc_not = howl_sroiq_box_sc(arena, howl_sriqelim_rewrite(arena, p, (*f), !(pos))) });
        }
        case howl_sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_321.data.sc_and;
            return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_and, .data.sc_and = howl_sriqelim_rewrite_each(arena, p, xs, pos) });
        }
        case howl_sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_321.data.sc_or;
            return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_or, .data.sc_or = howl_sriqelim_rewrite_each(arena, p, xs, pos) });
        }
        case howl_sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_321.data.sc_some.f0;
            __auto_type f = _mv_321.data.sc_some.f1;
            return howl_sriqelim_rewrite_some(arena, p, r, (*f), pos);
        }
        case howl_sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_321.data.sc_all.f0;
            __auto_type f = _mv_321.data.sc_all.f1;
            return howl_sriqelim_rewrite_all(arena, p, r, (*f), pos);
        }
        case howl_sroiq_SConcept_sc_atleast:
        {
            __auto_type n = _mv_321.data.sc_atleast.f0;
            __auto_type r = _mv_321.data.sc_atleast.f1;
            __auto_type f = _mv_321.data.sc_atleast.f2;
            return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_atleast, .data.sc_atleast = { .f0 = n, .f1 = r, .f2 = howl_sroiq_box_sc(arena, howl_sriqelim_rewrite(arena, p, (*f), pos)) } });
        }
        case howl_sroiq_SConcept_sc_atmost:
        {
            __auto_type n = _mv_321.data.sc_atmost.f0;
            __auto_type r = _mv_321.data.sc_atmost.f1;
            __auto_type f = _mv_321.data.sc_atmost.f2;
            return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = n, .f1 = r, .f2 = howl_sroiq_box_sc(arena, howl_sriqelim_rewrite(arena, p, (*f), !(pos))) } });
        }
        default: {
            return c;
        }
    }
}

slop_list_howl_sroiq_SConcept howl_sriqelim_rewrite_each(slop_arena* arena, howl_sriqelim_S1State* p, slop_list_howl_sroiq_SConcept xs, uint8_t pos) {
    {
        __auto_type out = ((slop_list_howl_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqelim_rewrite(arena, p, x, pos)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_sroiq_SConcept howl_sriqelim_rewrite_all(slop_arena* arena, howl_sriqelim_S1State* p, howl_types_RoleId r, howl_sroiq_SConcept f, uint8_t pos) {
    {
        __auto_type g = howl_sroiq_sc_canon(arena, howl_sriqelim_rewrite(arena, p, f, pos));
        if (pos && howl_sriqelim_nonsimple((*p).rb, r)) {
            return howl_sriqelim_label(arena, p, 1, r, g);
        } else {
            return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = howl_sroiq_box_sc(arena, g) } });
        }
    }
}

howl_sroiq_SConcept howl_sriqelim_rewrite_some(slop_arena* arena, howl_sriqelim_S1State* p, howl_types_RoleId r, howl_sroiq_SConcept f, uint8_t pos) {
    {
        __auto_type g = howl_sroiq_sc_canon(arena, howl_sriqelim_rewrite(arena, p, f, pos));
        if (!(pos) && howl_sriqelim_nonsimple((*p).rb, r)) {
            return howl_sriqelim_label(arena, p, 0, r, g);
        } else {
            return ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = howl_sroiq_box_sc(arena, g) } });
        }
    }
}

howl_sroiq_SConcept howl_sriqelim_chain_all(slop_arena* arena, slop_list_howl_types_RoleId w, howl_sroiq_SConcept x) {
    {
        __auto_type c = x;
        int64_t i = (((int64_t)(((int64_t)((w).len)))) - 1);
        while (i >= 0) {
            c = ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_all, .data.sc_all = { .f0 = howl_sriqelim_role_at(w, i), .f1 = howl_sroiq_box_sc(arena, c) } });
            i = (i - 1);
        }
        return c;
    }
}

uint8_t howl_sriqelim_item(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept lhs, slop_list_howl_types_RoleId w, howl_sroiq_SConcept x, howl_types_RoleId s) {
    if (howl_sriqelim_holds_role(w, s)) {
        return howl_sriqelim_fail(p, SLOP_STR("an RBox the gate should have refused: a RIA into S whose word holds S or inv(S) where no form allows it"));
    } else {
        return howl_sriqelim_emit_gci(arena, p, lhs, howl_sriqelim_rewrite(arena, p, howl_sriqelim_chain_all(arena, w, x), 1));
    }
}

uint8_t howl_sriqelim_expand_ria(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept i, howl_types_RoleId s, howl_sroiq_SConcept f, slop_list_howl_types_RoleId w) {
    {
        __auto_type n = ((int64_t)(((int64_t)((w).len))));
        if ((n == 1) && howl_sriqelim_role_eq(howl_sriqelim_role_at(w, 0), howl_sroiq_inv_role(s))) {
            return 1;
        } else if (((n == 2)) && (howl_sriqelim_role_eq(howl_sriqelim_role_at(w, 0), s)) && (howl_sriqelim_role_eq(howl_sriqelim_role_at(w, 1), s))) {
            return howl_sriqelim_emit_gci(arena, p, f, i);
        } else if ((n >= 2) && howl_sriqelim_role_eq(howl_sriqelim_role_at(w, 0), s)) {
            return howl_sriqelim_item(arena, p, f, howl_sriqelim_slice(arena, w, 1, n), f, s);
        } else if ((n >= 2) && howl_sriqelim_role_eq(howl_sriqelim_role_at(w, (n - 1)), s)) {
            return howl_sriqelim_item(arena, p, i, howl_sriqelim_slice(arena, w, 0, (n - 1)), i, s);
        } else {
            return howl_sriqelim_item(arena, p, i, w, f, s);
        }
    }
}

uint8_t howl_sriqelim_expand1(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept i, howl_types_RoleId s, howl_sroiq_SConcept f) {
    howl_sriqelim_emit_gci(arena, p, i, ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_all, .data.sc_all = { .f0 = s, .f1 = howl_sroiq_box_sc(arena, f) } }));
    {
        __auto_type _coll = (*p).rc;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type x = _coll.data[_i];
            if (howl_sriqelim_role_eq(x.super, s)) {
                howl_sriqelim_expand_ria(arena, p, i, s, f, x.word);
            }
        }
    }
    return 1;
}

uint8_t howl_sriqelim_expand(slop_arena* arena, howl_sriqelim_S1State* p, howl_sroiq_SConcept i, howl_types_RoleId s, howl_sroiq_SConcept f) {
    howl_sriqelim_expand1(arena, p, i, s, f);
    if (howl_sriqelim_symmetric((*p).rc, s)) {
        howl_sriqelim_expand1(arena, p, i, howl_sroiq_inv_role(s), f);
    }
    return 1;
}

uint8_t howl_sriqelim_expand_key(slop_arena* arena, howl_sriqelim_S1State* p, howl_sriqelim_Pending e) {
    {
        __auto_type r = e.role;
        __auto_type c = e.filler;
        if (e.forall) {
            {
                __auto_type i = howl_sriqelim_atom(arena, howl_sroiq_ElimKind_ek_i_all, r, c);
                __auto_type f = howl_sriqelim_atom(arena, howl_sroiq_ElimKind_ek_f_all, r, c);
                howl_sriqelim_emit_gci(arena, p, f, c);
                return howl_sriqelim_expand(arena, p, i, r, f);
            }
        } else {
            {
                __auto_type i = howl_sriqelim_atom(arena, howl_sroiq_ElimKind_ek_i_some, r, c);
                __auto_type f = howl_sriqelim_atom(arena, howl_sroiq_ElimKind_ek_f_some, r, c);
                howl_sriqelim_emit_gci(arena, p, c, i);
                return howl_sriqelim_expand(arena, p, i, howl_sroiq_inv_role(r), f);
            }
        }
    }
}

howl_sriqelim_Pending howl_sriqelim_pending_at(slop_list_howl_sriqelim_Pending xs, int64_t i) {
    __auto_type _mv_322 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_sriqelim_Pending _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_322.has_value) {
        __auto_type e = _mv_322.value;
        return e;
    } else if (!_mv_322.has_value) {
        return ((howl_sriqelim_Pending){.forall = 1, .role = ((howl_types_RoleId){ .tag = howl_types_RoleId_fresh_role, .data.fresh_role = 0 }), .filler = ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_top })});
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_sriqelim_drain(slop_arena* arena, howl_sriqelim_S1State* p) {
    {
        int64_t head = 0;
        while (howl_sriqelim_going(p) && (head < ((int64_t)(((int64_t)(((*p).queue).len)))))) {
            howl_sriqelim_expand_key(arena, p, howl_sriqelim_pending_at((*p).queue, head));
            head = (head + 1);
        }
        return 1;
    }
}

uint8_t howl_sriqelim_s1_init(slop_arena* arena, howl_sriqelim_S1State* p, slop_list_howl_sroiq_SAxiom axs) {
    {
        __auto_type _coll = axs;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type a = _coll.data[_i];
            __auto_type _mv_323 = a;
            switch (_mv_323.tag) {
                case howl_sroiq_SAxiom_sa_ria:
                {
                    __auto_type x = _mv_323.data.sa_ria;
                    if (!(howl_sriqelim_ria_complex((*p).rb, x))) {
                        howl_sriqelim_emit(arena, p, a);
                    }
                    break;
                }
                case howl_sroiq_SAxiom_sa_gci:
                {
                    __auto_type l = _mv_323.data.sa_gci.f0;
                    __auto_type r = _mv_323.data.sa_gci.f1;
                    howl_sriqelim_emit_gci(arena, p, howl_sriqelim_rewrite(arena, p, (*l), 0), howl_sriqelim_rewrite(arena, p, (*r), 1));
                    break;
                }
                default: {
                    howl_sriqelim_emit(arena, p, a);
                    break;
                }
            }
        }
    }
    return 1;
}

uint8_t howl_sriqelim_is_chain(howl_sroiq_SAxiom a) {
    __auto_type _mv_324 = a;
    switch (_mv_324.tag) {
        case howl_sroiq_SAxiom_sa_ria:
        {
            __auto_type x = _mv_324.data.sa_ria;
            return (((int64_t)((x.word).len)) > 1);
        }
        default: {
            return 0;
        }
    }
}

howl_sriqelim_S1 howl_sriqelim_guarded(slop_arena* arena, slop_list_howl_sroiq_SAxiom axs, int64_t count) {
    {
        __auto_type kept = ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type omitted = ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (howl_sriqelim_is_chain(a)) {
                    (void)(({ __auto_type _lst_p = &(omitted); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                } else {
                    (void)(({ __auto_type _lst_p = &(kept); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return ((howl_sriqelim_S1){.axioms = kept, .omitted = omitted, .expansions = ((int64_t)(SLOP_RANGE(int64_t, count, 1, 0, 0, 0, "(Int 0 ..) at sriqelim.slop:383:85")))});
    }
}

slop_result_howl_sriqelim_S1_string howl_sriqelim_s1_result(slop_arena* arena, howl_sriqnormal_S0 s0, howl_sriqelim_S1State* p) {
    {
        __auto_type st = (*p);
        __auto_type _mv_325 = st.fault;
        if (_mv_325.has_value) {
            __auto_type m = _mv_325.value;
            return ((slop_result_howl_sriqelim_S1_string){ .is_ok = false, .data.err = m });
        } else if (!_mv_325.has_value) {
            if (st.count > st.bound) {
                return ((slop_result_howl_sriqelim_S1_string){ .is_ok = true, .data.ok = howl_sriqelim_guarded(arena, s0.axioms, st.count) });
            } else {
                return ((slop_result_howl_sriqelim_S1_string){ .is_ok = true, .data.ok = ((howl_sriqelim_S1){.axioms = howl_sroiq_dedupe_saxioms(arena, howl_sroiq_sort_saxioms(arena, st.out)), .omitted = ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .expansions = ((int64_t)(SLOP_RANGE(int64_t, st.count, 1, 0, 0, 0, "(Int 0 ..) at sriqelim.slop:398:48")))}) });
            }
        }
        SLOP_UNREACHABLE();
    }
}

slop_result_howl_sriqelim_S1_string howl_sriqelim_sriq_s1(slop_arena* arena, howl_sriqnormal_S0 s0, int64_t bound) {
    {
        __auto_type p = howl_sriqelim_new_s1(arena, s0.rbox, howl_sriqelim_build_rc(arena, s0.rbox, s0.axioms), bound);
        howl_sriqelim_s1_init(arena, p, s0.axioms);
        howl_sriqelim_drain(arena, p);
        return howl_sriqelim_s1_result(arena, s0, p);
    }
}

uint8_t howl_sriqelim_is_atom(howl_sroiq_SConcept c) {
    __auto_type _mv_326 = c;
    switch (_mv_326.tag) {
        case howl_sroiq_SConcept_sc_elim:
        {
            return 1;
        }
        default: {
            return 0;
        }
    }
}

uint8_t howl_sriqelim_item1_p(howl_sroiq_SConcept l, howl_sroiq_SConcept r) {
    __auto_type _mv_327 = r;
    switch (_mv_327.tag) {
        case howl_sroiq_SConcept_sc_all:
        {
            __auto_type f = _mv_327.data.sc_all.f1;
            return (howl_sriqelim_is_atom(l) && howl_sriqelim_is_atom((*f)));
        }
        default: {
            return 0;
        }
    }
}

uint8_t howl_sriqelim_labelled_left(howl_sriqrbox_SriqRbox rb, howl_sroiq_SConcept c, uint8_t pos) {
    __auto_type _mv_328 = c;
    switch (_mv_328.tag) {
        case howl_sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_328.data.sc_not;
            return howl_sriqelim_labelled_left(rb, (*f), !(pos));
        }
        case howl_sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_328.data.sc_and;
            return howl_sriqelim_labelled_any(rb, xs, pos);
        }
        case howl_sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_328.data.sc_or;
            return howl_sriqelim_labelled_any(rb, xs, pos);
        }
        case howl_sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_328.data.sc_some.f0;
            __auto_type f = _mv_328.data.sc_some.f1;
            return ((!(pos) && howl_sriqelim_nonsimple(rb, r)) || howl_sriqelim_labelled_left(rb, (*f), pos));
        }
        case howl_sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_328.data.sc_all.f0;
            __auto_type f = _mv_328.data.sc_all.f1;
            return ((pos && howl_sriqelim_nonsimple(rb, r)) || howl_sriqelim_labelled_left(rb, (*f), pos));
        }
        case howl_sroiq_SConcept_sc_atleast:
        {
            __auto_type f = _mv_328.data.sc_atleast.f2;
            return howl_sriqelim_labelled_left(rb, (*f), pos);
        }
        case howl_sroiq_SConcept_sc_atmost:
        {
            __auto_type f = _mv_328.data.sc_atmost.f2;
            return howl_sriqelim_labelled_left(rb, (*f), !(pos));
        }
        default: {
            return 0;
        }
    }
}

uint8_t howl_sriqelim_labelled_any(howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SConcept cs, uint8_t pos) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (howl_sriqelim_labelled_left(rb, c, pos)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t howl_sriqelim_has_axiom(slop_list_howl_sroiq_SAxiom axs, howl_sroiq_SAxiom a) {
    {
        int64_t lo = 0;
        int64_t hi = (((int64_t)(((int64_t)((axs).len)))) - 1);
        uint8_t found = 0;
        while ((lo <= hi) && !(found)) {
            {
                __auto_type mid = ((lo + hi) / 2);
                __auto_type _mv_329 = ({ __auto_type _lst = axs; size_t _idx = (size_t)mid; slop_option_howl_sroiq_SAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (!_mv_329.has_value) {
                    hi = -1;
                } else if (_mv_329.has_value) {
                    __auto_type x = _mv_329.value;
                    {
                        __auto_type d = howl_sroiq_sa_cmp(x, a);
                        if (d == 0) {
                            found = 1;
                        } else if (d < 0) {
                            lo = (mid + 1);
                        } else {
                            hi = (mid - 1);
                        }
                    }
                }
            }
        }
        return found;
    }
}

howl_sroiq_SAxiom howl_sriqelim_def_gci(slop_arena* arena, howl_sroiq_SConcept l, howl_sroiq_SConcept r) {
    return ((howl_sroiq_SAxiom){ .tag = howl_sroiq_SAxiom_sa_gci, .data.sa_gci = { .f0 = howl_sroiq_box_sc(arena, howl_sroiq_sc_canon(arena, l)), .f1 = howl_sroiq_box_sc(arena, howl_sroiq_sc_canon(arena, r)) } });
}

slop_list_howl_sroiq_SAxiom howl_sriqelim_all_axioms(slop_arena* arena, howl_sroiq_SConcept i, howl_types_RoleId r, howl_sroiq_SConcept c) {
    {
        __auto_type f = howl_sriqelim_atom(arena, howl_sroiq_ElimKind_ek_f_all, r, c);
        __auto_type out = ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqelim_def_gci(arena, f, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqelim_def_gci(arena, i, ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = howl_sroiq_box_sc(arena, f) } }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

slop_list_howl_sroiq_SAxiom howl_sriqelim_some_axioms(slop_arena* arena, howl_sroiq_SConcept f, howl_types_RoleId r, howl_sroiq_SConcept c) {
    {
        __auto_type i = howl_sriqelim_atom(arena, howl_sroiq_ElimKind_ek_i_some, r, c);
        __auto_type out = ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqelim_def_gci(arena, c, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqelim_def_gci(arena, i, ((howl_sroiq_SConcept){ .tag = howl_sroiq_SConcept_sc_all, .data.sc_all = { .f0 = howl_sroiq_inv_role(r), .f1 = howl_sroiq_box_sc(arena, f) } }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

slop_list_howl_sroiq_SAxiom howl_sriqelim_atom_axioms(slop_arena* arena, howl_sroiq_SConcept c) {
    __auto_type _mv_330 = c;
    switch (_mv_330.tag) {
        case howl_sroiq_SConcept_sc_elim:
        {
            __auto_type k = _mv_330.data.sc_elim.f0;
            __auto_type r = _mv_330.data.sc_elim.f1;
            __auto_type f = _mv_330.data.sc_elim.f2;
            __auto_type _mv_331 = k;
            if (_mv_331 == howl_sroiq_ElimKind_ek_i_all) {
                return howl_sriqelim_all_axioms(arena, c, r, (*f));
            } else if (_mv_331 == howl_sroiq_ElimKind_ek_f_some) {
                return howl_sriqelim_some_axioms(arena, c, r, (*f));
            } else {
                return ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            }
        }
        default: {
            return ((slop_list_howl_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        }
    }
}

slop_list_howl_sroiq_SConcept howl_sriqelim_atoms_of(slop_arena* arena, howl_sroiq_SConcept c) {
    {
        __auto_type out = ((slop_list_howl_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_332 = c;
        switch (_mv_332.tag) {
            case howl_sroiq_SConcept_sc_elim:
            {
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_sroiq_SConcept_sc_not:
            {
                __auto_type f = _mv_332.data.sc_not;
                {
                    __auto_type _coll = howl_sriqelim_atoms_of(arena, (*f));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case howl_sroiq_SConcept_sc_and:
            {
                __auto_type xs = _mv_332.data.sc_and;
                {
                    __auto_type _coll = xs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type y = _coll.data[_i];
                        {
                            __auto_type _coll = howl_sriqelim_atoms_of(arena, y);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type x = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case howl_sroiq_SConcept_sc_or:
            {
                __auto_type xs = _mv_332.data.sc_or;
                {
                    __auto_type _coll = xs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type y = _coll.data[_i];
                        {
                            __auto_type _coll = howl_sriqelim_atoms_of(arena, y);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type x = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case howl_sroiq_SConcept_sc_some:
            {
                __auto_type f = _mv_332.data.sc_some.f1;
                {
                    __auto_type _coll = howl_sriqelim_atoms_of(arena, (*f));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case howl_sroiq_SConcept_sc_all:
            {
                __auto_type f = _mv_332.data.sc_all.f1;
                {
                    __auto_type _coll = howl_sriqelim_atoms_of(arena, (*f));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case howl_sroiq_SConcept_sc_atleast:
            {
                __auto_type f = _mv_332.data.sc_atleast.f2;
                {
                    __auto_type _coll = howl_sriqelim_atoms_of(arena, (*f));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case howl_sroiq_SConcept_sc_atmost:
            {
                __auto_type f = _mv_332.data.sc_atmost.f2;
                {
                    __auto_type _coll = howl_sriqelim_atoms_of(arena, (*f));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

slop_list_howl_sroiq_SConcept howl_sriqelim_append_atoms(slop_arena* arena, slop_list_howl_sroiq_SConcept a, slop_list_howl_sroiq_SConcept b) {
    {
        __auto_type out = ((slop_list_howl_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = b;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_string howl_sriqelim_axiom_problems(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SAxiom axs, howl_sroiq_SAxiom a) {
    {
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_333 = a;
        switch (_mv_333.tag) {
            case howl_sroiq_SAxiom_sa_ria:
            {
                __auto_type x = _mv_333.data.sa_ria;
                if (howl_sriqelim_ria_complex(rb, x)) {
                    ({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("a complex RIA is left: "), howl_sroiq_render_saxiom(arena, a))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                break;
            }
            case howl_sroiq_SAxiom_sa_gci:
            {
                __auto_type l = _mv_333.data.sa_gci.f0;
                __auto_type r = _mv_333.data.sa_gci.f1;
                if (!(howl_sriqelim_item1_p((*l), (*r))) && (howl_sriqelim_labelled_left(rb, (*l), 0) || howl_sriqelim_labelled_left(rb, (*r), 1))) {
                    ({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("a labelled restriction is left: "), howl_sroiq_render_saxiom(arena, a))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                {
                    __auto_type _coll = howl_sriqelim_append_atoms(arena, howl_sriqelim_atoms_of(arena, (*l)), howl_sriqelim_atoms_of(arena, (*r)));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        {
                            __auto_type _coll = howl_sriqelim_atom_axioms(arena, c);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type want = _coll.data[_i];
                                if (!(howl_sriqelim_has_axiom(axs, want))) {
                                    ({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("an atom without its axioms: "), howl_sroiq_render_sconcept(arena, c))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                }
                break;
            }
            default: {
                break;
            }
        }
        return bad;
    }
}

uint8_t howl_sriqelim_same_axioms(slop_list_howl_sroiq_SAxiom a, slop_list_howl_sroiq_SAxiom b) {
    {
        uint8_t ok = (((int64_t)((a).len)) == ((int64_t)((b).len)));
        int64_t i = 0;
        while (ok && (i < ((int64_t)(((int64_t)((a).len)))))) {
            __auto_type _mv_334 = ({ __auto_type _lst = a; size_t _idx = (size_t)i; slop_option_howl_sroiq_SAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_334.has_value) {
                __auto_type x = _mv_334.value;
                __auto_type _mv_335 = ({ __auto_type _lst = b; size_t _idx = (size_t)i; slop_option_howl_sroiq_SAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_335.has_value) {
                    __auto_type y = _mv_335.value;
                    if (howl_sroiq_sa_cmp(x, y) != 0) {
                        ok = 0;
                    }
                } else if (!_mv_335.has_value) {
                    ok = 0;
                }
            } else if (!_mv_334.has_value) {
                ok = 0;
            }
            i = (i + 1);
        }
        return ok;
    }
}

slop_list_string howl_sriqelim_guarded_problems(slop_arena* arena, slop_list_howl_sroiq_SAxiom s0_axioms, howl_sriqelim_S1 s1) {
    {
        __auto_type want = howl_sriqelim_guarded(arena, s0_axioms, 0);
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (!(howl_sriqelim_same_axioms(want.axioms, s1.axioms))) {
            (void)(({ __auto_type _lst_p = &(bad); __auto_type _item = (SLOP_STR("a guarded run's axioms are not S0 minus its chains")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        if (!(howl_sriqelim_same_axioms(want.omitted, s1.omitted))) {
            (void)(({ __auto_type _lst_p = &(bad); __auto_type _item = (SLOP_STR("a guarded run's omissions are not S0's chains")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        return bad;
    }
}

slop_list_string howl_sriqelim_sriq_s1_invariants(slop_arena* arena, howl_sriqrbox_SriqRbox rb, slop_list_howl_sroiq_SAxiom s0_axioms, howl_sriqelim_S1 s1) {
    if (((int64_t)((s1.omitted).len)) > 0) {
        return howl_sriqelim_guarded_problems(arena, s0_axioms, s1);
    } else {
        {
            __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = s1.axioms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    {
                        __auto_type _coll = howl_sriqelim_axiom_problems(arena, rb, s1.axioms, a);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type b = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(bad); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
            return bad;
        }
    }
}

