#include "../runtime/slop_runtime.h"
#include "slop_sriqelim.h"


uint8_t sriqelim_nonsimple(sriqrbox_SriqRbox rb, types_RoleId r);
uint8_t sriqelim_role_eq(types_RoleId a, types_RoleId b);
uint8_t sriqelim_ria_complex(sriqrbox_SriqRbox rb, sroiq_SRia x);
types_RoleId sriqelim_role_at(slop_list_types_RoleId w, int64_t i);
slop_list_types_RoleId sriqelim_slice(slop_arena* arena, slop_list_types_RoleId w, int64_t from, int64_t upto);
slop_list_types_RoleId sriqelim_inv_word(slop_arena* arena, slop_list_types_RoleId w);
slop_list_sroiq_SRia sriqelim_rc_of(slop_arena* arena, sriqrbox_SriqRbox rb, sroiq_SAxiom a);
slop_list_sroiq_SRia sriqelim_build_rc(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_sroiq_SAxiom axs);
uint8_t sriqelim_symmetric(slop_list_sroiq_SRia rc, types_RoleId s);
uint8_t sriqelim_holds_role(slop_list_types_RoleId w, types_RoleId s);
sriqelim_S1State* sriqelim_new_s1(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_sroiq_SRia rc, int64_t bound);
uint8_t sriqelim_emit(slop_arena* arena, sriqelim_S1State* p, sroiq_SAxiom a);
uint8_t sriqelim_emit_gci(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept l, sroiq_SConcept r);
uint8_t sriqelim_fail(sriqelim_S1State* p, slop_string m);
uint8_t sriqelim_going(sriqelim_S1State* p);
sroiq_SConcept sriqelim_atom(slop_arena* arena, sroiq_ElimKind k, types_RoleId r, sroiq_SConcept f);
sroiq_SConcept sriqelim_label_name(slop_arena* arena, uint8_t forall, types_RoleId r, sroiq_SConcept f);
sroiq_SConcept sriqelim_label(slop_arena* arena, sriqelim_S1State* p, uint8_t forall, types_RoleId r, sroiq_SConcept f);
sroiq_SConcept sriqelim_rewrite(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept c, uint8_t pos);
slop_list_sroiq_SConcept sriqelim_rewrite_each(slop_arena* arena, sriqelim_S1State* p, slop_list_sroiq_SConcept xs, uint8_t pos);
sroiq_SConcept sriqelim_rewrite_all(slop_arena* arena, sriqelim_S1State* p, types_RoleId r, sroiq_SConcept f, uint8_t pos);
sroiq_SConcept sriqelim_rewrite_some(slop_arena* arena, sriqelim_S1State* p, types_RoleId r, sroiq_SConcept f, uint8_t pos);
sroiq_SConcept sriqelim_chain_all(slop_arena* arena, slop_list_types_RoleId w, sroiq_SConcept x);
uint8_t sriqelim_item(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept lhs, slop_list_types_RoleId w, sroiq_SConcept x, types_RoleId s);
uint8_t sriqelim_expand_ria(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept i, types_RoleId s, sroiq_SConcept f, slop_list_types_RoleId w);
uint8_t sriqelim_expand1(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept i, types_RoleId s, sroiq_SConcept f);
uint8_t sriqelim_expand(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept i, types_RoleId s, sroiq_SConcept f);
uint8_t sriqelim_expand_key(slop_arena* arena, sriqelim_S1State* p, sriqelim_Pending e);
sriqelim_Pending sriqelim_pending_at(slop_list_sriqelim_Pending xs, int64_t i);
uint8_t sriqelim_drain(slop_arena* arena, sriqelim_S1State* p);
uint8_t sriqelim_s1_init(slop_arena* arena, sriqelim_S1State* p, slop_list_sroiq_SAxiom axs);
uint8_t sriqelim_is_chain(sroiq_SAxiom a);
sriqelim_S1 sriqelim_guarded(slop_arena* arena, slop_list_sroiq_SAxiom axs, int64_t count);
slop_result_sriqelim_S1_string sriqelim_s1_result(slop_arena* arena, sriqnormal_S0 s0, sriqelim_S1State* p);
slop_result_sriqelim_S1_string sriqelim_sriq_s1(slop_arena* arena, sriqnormal_S0 s0, int64_t bound);
uint8_t sriqelim_is_atom(sroiq_SConcept c);
uint8_t sriqelim_item1_p(sroiq_SConcept l, sroiq_SConcept r);
uint8_t sriqelim_labelled_left(sriqrbox_SriqRbox rb, sroiq_SConcept c, uint8_t pos);
uint8_t sriqelim_labelled_any(sriqrbox_SriqRbox rb, slop_list_sroiq_SConcept cs, uint8_t pos);
uint8_t sriqelim_has_axiom(slop_list_sroiq_SAxiom axs, sroiq_SAxiom a);
sroiq_SAxiom sriqelim_def_gci(slop_arena* arena, sroiq_SConcept l, sroiq_SConcept r);
slop_list_sroiq_SAxiom sriqelim_all_axioms(slop_arena* arena, sroiq_SConcept i, types_RoleId r, sroiq_SConcept c);
slop_list_sroiq_SAxiom sriqelim_some_axioms(slop_arena* arena, sroiq_SConcept f, types_RoleId r, sroiq_SConcept c);
slop_list_sroiq_SAxiom sriqelim_atom_axioms(slop_arena* arena, sroiq_SConcept c);
slop_list_sroiq_SConcept sriqelim_atoms_of(slop_arena* arena, sroiq_SConcept c);
slop_list_sroiq_SConcept sriqelim_append_atoms(slop_arena* arena, slop_list_sroiq_SConcept a, slop_list_sroiq_SConcept b);
slop_list_string sriqelim_axiom_problems(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_sroiq_SAxiom axs, sroiq_SAxiom a);
uint8_t sriqelim_same_axioms(slop_list_sroiq_SAxiom a, slop_list_sroiq_SAxiom b);
slop_list_string sriqelim_guarded_problems(slop_arena* arena, slop_list_sroiq_SAxiom s0_axioms, sriqelim_S1 s1);
slop_list_string sriqelim_sriq_s1_invariants(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_sroiq_SAxiom s0_axioms, sriqelim_S1 s1);

uint8_t sriqelim_nonsimple(sriqrbox_SriqRbox rb, types_RoleId r) {
    return !(sriqrbox_sriq_role_simple(rb, r));
}

uint8_t sriqelim_role_eq(types_RoleId a, types_RoleId b) {
    return (canon_role_cmp(a, b) == 0);
}

uint8_t sriqelim_ria_complex(sriqrbox_SriqRbox rb, sroiq_SRia x) {
    return ((((int64_t)((x.word).len)) > 1) || sriqelim_nonsimple(rb, x.super));
}

types_RoleId sriqelim_role_at(slop_list_types_RoleId w, int64_t i) {
    __auto_type _mv_1027 = ({ __auto_type _lst = w; size_t _idx = (size_t)i; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1027.has_value) {
        __auto_type r = _mv_1027.value;
        return r;
    } else if (!_mv_1027.has_value) {
        return ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_list_types_RoleId sriqelim_slice(slop_arena* arena, slop_list_types_RoleId w, int64_t from, int64_t upto) {
    {
        __auto_type out = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = from;
        while (i < upto) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqelim_role_at(w, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        return out;
    }
}

slop_list_types_RoleId sriqelim_inv_word(slop_arena* arena, slop_list_types_RoleId w) {
    {
        __auto_type out = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = (((int64_t)(((int64_t)((w).len)))) - 1);
        while (i >= 0) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sroiq_inv_role(sriqelim_role_at(w, i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i - 1);
        }
        return out;
    }
}

slop_list_sroiq_SRia sriqelim_rc_of(slop_arena* arena, sriqrbox_SriqRbox rb, sroiq_SAxiom a) {
    {
        __auto_type out = ((slop_list_sroiq_SRia){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1028 = a;
        switch (_mv_1028.tag) {
            case sroiq_SAxiom_sa_ria:
            {
                __auto_type x = _mv_1028.data.sa_ria;
                if (sriqelim_ria_complex(rb, x)) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((sroiq_SRia){.word = sriqelim_inv_word(arena, x.word), .super = sroiq_inv_role(x.super)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

slop_list_sroiq_SRia sriqelim_build_rc(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_sroiq_SAxiom axs) {
    {
        __auto_type out = ((slop_list_sroiq_SRia){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                {
                    __auto_type _coll = sriqelim_rc_of(arena, rb, a);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        return out;
    }
}

uint8_t sriqelim_symmetric(slop_list_sroiq_SRia rc, types_RoleId s) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = rc;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if ((sriqelim_role_eq(x.super, s)) && ((((int64_t)((x.word).len)) == 1)) && (sriqelim_role_eq(sriqelim_role_at(x.word, 0), sroiq_inv_role(s)))) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t sriqelim_holds_role(slop_list_types_RoleId w, types_RoleId s) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = w;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                if (sriqelim_role_eq(r, s) || sriqelim_role_eq(r, sroiq_inv_role(s))) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

sriqelim_S1State* sriqelim_new_s1(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_sroiq_SRia rc, int64_t bound) {
    {
        __auto_type p = ((sriqelim_S1State*)(({ __auto_type _alloc = (sriqelim_S1State*)slop_arena_alloc(arena, sizeof(sriqelim_S1State)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = ((sriqelim_S1State){.rb = rb, .rc = rc, .out = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .queue = ((slop_list_sriqelim_Pending){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .count = 0, .bound = bound, .fault = (slop_option_string){.has_value = false}});
        return p;
    }
}

uint8_t sriqelim_emit(slop_arena* arena, sriqelim_S1State* p, sroiq_SAxiom a) {
    {
        __auto_type s = (*p);
        ({ __auto_type _lst_p = &(s.out); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        (*p) = s;
        return 1;
    }
}

uint8_t sriqelim_emit_gci(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept l, sroiq_SConcept r) {
    return sriqelim_emit(arena, p, ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_gci, .data.sa_gci = { .f0 = sroiq_box_sc(arena, sroiq_sc_canon(arena, l)), .f1 = sroiq_box_sc(arena, sroiq_sc_canon(arena, r)) } }));
}

uint8_t sriqelim_fail(sriqelim_S1State* p, slop_string m) {
    {
        __auto_type s = (*p);
        s.fault = (slop_option_string){.has_value = 1, .value = m};
        (*p) = s;
        return 0;
    }
}

uint8_t sriqelim_going(sriqelim_S1State* p) {
    return (((*p).count <= (*p).bound) && ({ __auto_type _mv = (*p).fault; _mv.has_value ? ({ __auto_type _ = _mv.value; 0; }) : (1); }));
}

sroiq_SConcept sriqelim_atom(slop_arena* arena, sroiq_ElimKind k, types_RoleId r, sroiq_SConcept f) {
    return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_elim, .data.sc_elim = { .f0 = k, .f1 = r, .f2 = sroiq_box_sc(arena, f) } });
}

sroiq_SConcept sriqelim_label_name(slop_arena* arena, uint8_t forall, types_RoleId r, sroiq_SConcept f) {
    if (forall) {
        return sriqelim_atom(arena, sroiq_ElimKind_ek_i_all, r, f);
    } else {
        return sriqelim_atom(arena, sroiq_ElimKind_ek_f_some, r, f);
    }
}

sroiq_SConcept sriqelim_label(slop_arena* arena, sriqelim_S1State* p, uint8_t forall, types_RoleId r, sroiq_SConcept f) {
    {
        __auto_type name = sriqelim_label_name(arena, forall, r, f);
        __auto_type key = sroiq_sc_key(arena, name);
        if (!(slop_map_has((*p).seen, &(key)))) {
            {
                __auto_type s = (*p);
                ({ slop_map_put(NULL, s.seen, &(key), NULL, 0); });
                ({ __auto_type _lst_p = &(s.queue); __auto_type _item = (((sriqelim_Pending){.forall = forall, .role = r, .filler = f})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                s.count = (s.count + 1);
                (*p) = s;
            }
        }
        return name;
    }
}

sroiq_SConcept sriqelim_rewrite(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept c, uint8_t pos) {
    __auto_type _mv_1031 = c;
    switch (_mv_1031.tag) {
        case sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_1031.data.sc_not;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_not, .data.sc_not = sroiq_box_sc(arena, sriqelim_rewrite(arena, p, (*f), !(pos))) });
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_1031.data.sc_and;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_and, .data.sc_and = sriqelim_rewrite_each(arena, p, xs, pos) });
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_1031.data.sc_or;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_or, .data.sc_or = sriqelim_rewrite_each(arena, p, xs, pos) });
        }
        case sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_1031.data.sc_some.f0;
            __auto_type f = _mv_1031.data.sc_some.f1;
            return sriqelim_rewrite_some(arena, p, r, (*f), pos);
        }
        case sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_1031.data.sc_all.f0;
            __auto_type f = _mv_1031.data.sc_all.f1;
            return sriqelim_rewrite_all(arena, p, r, (*f), pos);
        }
        case sroiq_SConcept_sc_atleast:
        {
            __auto_type n = _mv_1031.data.sc_atleast.f0;
            __auto_type r = _mv_1031.data.sc_atleast.f1;
            __auto_type f = _mv_1031.data.sc_atleast.f2;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atleast, .data.sc_atleast = { .f0 = n, .f1 = r, .f2 = sroiq_box_sc(arena, sriqelim_rewrite(arena, p, (*f), pos)) } });
        }
        case sroiq_SConcept_sc_atmost:
        {
            __auto_type n = _mv_1031.data.sc_atmost.f0;
            __auto_type r = _mv_1031.data.sc_atmost.f1;
            __auto_type f = _mv_1031.data.sc_atmost.f2;
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_atmost, .data.sc_atmost = { .f0 = n, .f1 = r, .f2 = sroiq_box_sc(arena, sriqelim_rewrite(arena, p, (*f), !(pos))) } });
        }
        default: {
            return c;
        }
    }
}

slop_list_sroiq_SConcept sriqelim_rewrite_each(slop_arena* arena, sriqelim_S1State* p, slop_list_sroiq_SConcept xs, uint8_t pos) {
    {
        __auto_type out = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqelim_rewrite(arena, p, x, pos)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

sroiq_SConcept sriqelim_rewrite_all(slop_arena* arena, sriqelim_S1State* p, types_RoleId r, sroiq_SConcept f, uint8_t pos) {
    {
        __auto_type g = sroiq_sc_canon(arena, sriqelim_rewrite(arena, p, f, pos));
        if (pos && sriqelim_nonsimple((*p).rb, r)) {
            return sriqelim_label(arena, p, 1, r, g);
        } else {
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = sroiq_box_sc(arena, g) } });
        }
    }
}

sroiq_SConcept sriqelim_rewrite_some(slop_arena* arena, sriqelim_S1State* p, types_RoleId r, sroiq_SConcept f, uint8_t pos) {
    {
        __auto_type g = sroiq_sc_canon(arena, sriqelim_rewrite(arena, p, f, pos));
        if (!(pos) && sriqelim_nonsimple((*p).rb, r)) {
            return sriqelim_label(arena, p, 0, r, g);
        } else {
            return ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_some, .data.sc_some = { .f0 = r, .f1 = sroiq_box_sc(arena, g) } });
        }
    }
}

sroiq_SConcept sriqelim_chain_all(slop_arena* arena, slop_list_types_RoleId w, sroiq_SConcept x) {
    {
        __auto_type c = x;
        int64_t i = (((int64_t)(((int64_t)((w).len)))) - 1);
        while (i >= 0) {
            c = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = sriqelim_role_at(w, i), .f1 = sroiq_box_sc(arena, c) } });
            i = (i - 1);
        }
        return c;
    }
}

uint8_t sriqelim_item(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept lhs, slop_list_types_RoleId w, sroiq_SConcept x, types_RoleId s) {
    if (sriqelim_holds_role(w, s)) {
        return sriqelim_fail(p, SLOP_STR("an RBox the gate should have refused: a RIA into S whose word holds S or inv(S) where no form allows it"));
    } else {
        return sriqelim_emit_gci(arena, p, lhs, sriqelim_rewrite(arena, p, sriqelim_chain_all(arena, w, x), 1));
    }
}

uint8_t sriqelim_expand_ria(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept i, types_RoleId s, sroiq_SConcept f, slop_list_types_RoleId w) {
    {
        __auto_type n = ((int64_t)(((int64_t)((w).len))));
        if ((n == 1) && sriqelim_role_eq(sriqelim_role_at(w, 0), sroiq_inv_role(s))) {
            return 1;
        } else if (((n == 2)) && (sriqelim_role_eq(sriqelim_role_at(w, 0), s)) && (sriqelim_role_eq(sriqelim_role_at(w, 1), s))) {
            return sriqelim_emit_gci(arena, p, f, i);
        } else if ((n >= 2) && sriqelim_role_eq(sriqelim_role_at(w, 0), s)) {
            return sriqelim_item(arena, p, f, sriqelim_slice(arena, w, 1, n), f, s);
        } else if ((n >= 2) && sriqelim_role_eq(sriqelim_role_at(w, (n - 1)), s)) {
            return sriqelim_item(arena, p, i, sriqelim_slice(arena, w, 0, (n - 1)), i, s);
        } else {
            return sriqelim_item(arena, p, i, w, f, s);
        }
    }
}

uint8_t sriqelim_expand1(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept i, types_RoleId s, sroiq_SConcept f) {
    sriqelim_emit_gci(arena, p, i, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = s, .f1 = sroiq_box_sc(arena, f) } }));
    {
        __auto_type _coll = (*p).rc;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type x = _coll.data[_i];
            if (sriqelim_role_eq(x.super, s)) {
                sriqelim_expand_ria(arena, p, i, s, f, x.word);
            }
        }
    }
    return 1;
}

uint8_t sriqelim_expand(slop_arena* arena, sriqelim_S1State* p, sroiq_SConcept i, types_RoleId s, sroiq_SConcept f) {
    sriqelim_expand1(arena, p, i, s, f);
    if (sriqelim_symmetric((*p).rc, s)) {
        sriqelim_expand1(arena, p, i, sroiq_inv_role(s), f);
    }
    return 1;
}

uint8_t sriqelim_expand_key(slop_arena* arena, sriqelim_S1State* p, sriqelim_Pending e) {
    {
        __auto_type r = e.role;
        __auto_type c = e.filler;
        if (e.forall) {
            {
                __auto_type i = sriqelim_atom(arena, sroiq_ElimKind_ek_i_all, r, c);
                __auto_type f = sriqelim_atom(arena, sroiq_ElimKind_ek_f_all, r, c);
                sriqelim_emit_gci(arena, p, f, c);
                return sriqelim_expand(arena, p, i, r, f);
            }
        } else {
            {
                __auto_type i = sriqelim_atom(arena, sroiq_ElimKind_ek_i_some, r, c);
                __auto_type f = sriqelim_atom(arena, sroiq_ElimKind_ek_f_some, r, c);
                sriqelim_emit_gci(arena, p, c, i);
                return sriqelim_expand(arena, p, i, sroiq_inv_role(r), f);
            }
        }
    }
}

sriqelim_Pending sriqelim_pending_at(slop_list_sriqelim_Pending xs, int64_t i) {
    __auto_type _mv_1032 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_sriqelim_Pending _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1032.has_value) {
        __auto_type e = _mv_1032.value;
        return e;
    } else if (!_mv_1032.has_value) {
        return ((sriqelim_Pending){.forall = 1, .role = ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = 0 }), .filler = ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_top })});
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqelim_drain(slop_arena* arena, sriqelim_S1State* p) {
    {
        int64_t head = 0;
        while (sriqelim_going(p) && (head < ((int64_t)(((int64_t)(((*p).queue).len)))))) {
            sriqelim_expand_key(arena, p, sriqelim_pending_at((*p).queue, head));
            head = (head + 1);
        }
        return 1;
    }
}

uint8_t sriqelim_s1_init(slop_arena* arena, sriqelim_S1State* p, slop_list_sroiq_SAxiom axs) {
    {
        __auto_type _coll = axs;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type a = _coll.data[_i];
            __auto_type _mv_1033 = a;
            switch (_mv_1033.tag) {
                case sroiq_SAxiom_sa_ria:
                {
                    __auto_type x = _mv_1033.data.sa_ria;
                    if (!(sriqelim_ria_complex((*p).rb, x))) {
                        sriqelim_emit(arena, p, a);
                    }
                    break;
                }
                case sroiq_SAxiom_sa_gci:
                {
                    __auto_type l = _mv_1033.data.sa_gci.f0;
                    __auto_type r = _mv_1033.data.sa_gci.f1;
                    sriqelim_emit_gci(arena, p, sriqelim_rewrite(arena, p, (*l), 0), sriqelim_rewrite(arena, p, (*r), 1));
                    break;
                }
                default: {
                    sriqelim_emit(arena, p, a);
                    break;
                }
            }
        }
    }
    return 1;
}

uint8_t sriqelim_is_chain(sroiq_SAxiom a) {
    __auto_type _mv_1034 = a;
    switch (_mv_1034.tag) {
        case sroiq_SAxiom_sa_ria:
        {
            __auto_type x = _mv_1034.data.sa_ria;
            return (((int64_t)((x.word).len)) > 1);
        }
        default: {
            return 0;
        }
    }
}

sriqelim_S1 sriqelim_guarded(slop_arena* arena, slop_list_sroiq_SAxiom axs, int64_t count) {
    {
        __auto_type kept = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type omitted = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (sriqelim_is_chain(a)) {
                    ({ __auto_type _lst_p = &(omitted); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else {
                    ({ __auto_type _lst_p = &(kept); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return ((sriqelim_S1){.axioms = kept, .omitted = omitted, .expansions = ((int64_t)(SLOP_RANGE(int64_t, count, 1, 0, 0, 0, "(Int 0 ..) at sriqelim.slop:382:85")))});
    }
}

slop_result_sriqelim_S1_string sriqelim_s1_result(slop_arena* arena, sriqnormal_S0 s0, sriqelim_S1State* p) {
    {
        __auto_type st = (*p);
        __auto_type _mv_1035 = st.fault;
        if (_mv_1035.has_value) {
            __auto_type m = _mv_1035.value;
            return ((slop_result_sriqelim_S1_string){ .is_ok = false, .data.err = m });
        } else if (!_mv_1035.has_value) {
            if (st.count > st.bound) {
                return ((slop_result_sriqelim_S1_string){ .is_ok = true, .data.ok = sriqelim_guarded(arena, s0.axioms, st.count) });
            } else {
                return ((slop_result_sriqelim_S1_string){ .is_ok = true, .data.ok = ((sriqelim_S1){.axioms = sroiq_dedupe_saxioms(arena, sroiq_sort_saxioms(arena, st.out)), .omitted = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .expansions = ((int64_t)(SLOP_RANGE(int64_t, st.count, 1, 0, 0, 0, "(Int 0 ..) at sriqelim.slop:397:48")))}) });
            }
        }
        SLOP_UNREACHABLE();
    }
}

slop_result_sriqelim_S1_string sriqelim_sriq_s1(slop_arena* arena, sriqnormal_S0 s0, int64_t bound) {
    {
        __auto_type p = sriqelim_new_s1(arena, s0.rbox, sriqelim_build_rc(arena, s0.rbox, s0.axioms), bound);
        sriqelim_s1_init(arena, p, s0.axioms);
        sriqelim_drain(arena, p);
        return sriqelim_s1_result(arena, s0, p);
    }
}

uint8_t sriqelim_is_atom(sroiq_SConcept c) {
    __auto_type _mv_1036 = c;
    switch (_mv_1036.tag) {
        case sroiq_SConcept_sc_elim:
        {
            return 1;
        }
        default: {
            return 0;
        }
    }
}

uint8_t sriqelim_item1_p(sroiq_SConcept l, sroiq_SConcept r) {
    __auto_type _mv_1037 = r;
    switch (_mv_1037.tag) {
        case sroiq_SConcept_sc_all:
        {
            __auto_type f = _mv_1037.data.sc_all.f1;
            return (sriqelim_is_atom(l) && sriqelim_is_atom((*f)));
        }
        default: {
            return 0;
        }
    }
}

uint8_t sriqelim_labelled_left(sriqrbox_SriqRbox rb, sroiq_SConcept c, uint8_t pos) {
    __auto_type _mv_1038 = c;
    switch (_mv_1038.tag) {
        case sroiq_SConcept_sc_not:
        {
            __auto_type f = _mv_1038.data.sc_not;
            return sriqelim_labelled_left(rb, (*f), !(pos));
        }
        case sroiq_SConcept_sc_and:
        {
            __auto_type xs = _mv_1038.data.sc_and;
            return sriqelim_labelled_any(rb, xs, pos);
        }
        case sroiq_SConcept_sc_or:
        {
            __auto_type xs = _mv_1038.data.sc_or;
            return sriqelim_labelled_any(rb, xs, pos);
        }
        case sroiq_SConcept_sc_some:
        {
            __auto_type r = _mv_1038.data.sc_some.f0;
            __auto_type f = _mv_1038.data.sc_some.f1;
            return ((!(pos) && sriqelim_nonsimple(rb, r)) || sriqelim_labelled_left(rb, (*f), pos));
        }
        case sroiq_SConcept_sc_all:
        {
            __auto_type r = _mv_1038.data.sc_all.f0;
            __auto_type f = _mv_1038.data.sc_all.f1;
            return ((pos && sriqelim_nonsimple(rb, r)) || sriqelim_labelled_left(rb, (*f), pos));
        }
        case sroiq_SConcept_sc_atleast:
        {
            __auto_type f = _mv_1038.data.sc_atleast.f2;
            return sriqelim_labelled_left(rb, (*f), pos);
        }
        case sroiq_SConcept_sc_atmost:
        {
            __auto_type f = _mv_1038.data.sc_atmost.f2;
            return sriqelim_labelled_left(rb, (*f), !(pos));
        }
        default: {
            return 0;
        }
    }
}

uint8_t sriqelim_labelled_any(sriqrbox_SriqRbox rb, slop_list_sroiq_SConcept cs, uint8_t pos) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (sriqelim_labelled_left(rb, c, pos)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t sriqelim_has_axiom(slop_list_sroiq_SAxiom axs, sroiq_SAxiom a) {
    {
        int64_t lo = 0;
        int64_t hi = (((int64_t)(((int64_t)((axs).len)))) - 1);
        uint8_t found = 0;
        while ((lo <= hi) && !(found)) {
            {
                __auto_type mid = ((lo + hi) / 2);
                __auto_type _mv_1039 = ({ __auto_type _lst = axs; size_t _idx = (size_t)mid; slop_option_sroiq_SAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (!_mv_1039.has_value) {
                    hi = -1;
                } else if (_mv_1039.has_value) {
                    __auto_type x = _mv_1039.value;
                    {
                        __auto_type d = sroiq_sa_cmp(x, a);
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

sroiq_SAxiom sriqelim_def_gci(slop_arena* arena, sroiq_SConcept l, sroiq_SConcept r) {
    return ((sroiq_SAxiom){ .tag = sroiq_SAxiom_sa_gci, .data.sa_gci = { .f0 = sroiq_box_sc(arena, sroiq_sc_canon(arena, l)), .f1 = sroiq_box_sc(arena, sroiq_sc_canon(arena, r)) } });
}

slop_list_sroiq_SAxiom sriqelim_all_axioms(slop_arena* arena, sroiq_SConcept i, types_RoleId r, sroiq_SConcept c) {
    {
        __auto_type f = sriqelim_atom(arena, sroiq_ElimKind_ek_f_all, r, c);
        __auto_type out = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqelim_def_gci(arena, f, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqelim_def_gci(arena, i, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = r, .f1 = sroiq_box_sc(arena, f) } }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

slop_list_sroiq_SAxiom sriqelim_some_axioms(slop_arena* arena, sroiq_SConcept f, types_RoleId r, sroiq_SConcept c) {
    {
        __auto_type i = sriqelim_atom(arena, sroiq_ElimKind_ek_i_some, r, c);
        __auto_type out = ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqelim_def_gci(arena, c, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqelim_def_gci(arena, i, ((sroiq_SConcept){ .tag = sroiq_SConcept_sc_all, .data.sc_all = { .f0 = sroiq_inv_role(r), .f1 = sroiq_box_sc(arena, f) } }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

slop_list_sroiq_SAxiom sriqelim_atom_axioms(slop_arena* arena, sroiq_SConcept c) {
    __auto_type _mv_1040 = c;
    switch (_mv_1040.tag) {
        case sroiq_SConcept_sc_elim:
        {
            __auto_type k = _mv_1040.data.sc_elim.f0;
            __auto_type r = _mv_1040.data.sc_elim.f1;
            __auto_type f = _mv_1040.data.sc_elim.f2;
            __auto_type _mv_1041 = k;
            if (_mv_1041 == sroiq_ElimKind_ek_i_all) {
                return sriqelim_all_axioms(arena, c, r, (*f));
            } else if (_mv_1041 == sroiq_ElimKind_ek_f_some) {
                return sriqelim_some_axioms(arena, c, r, (*f));
            } else {
                return ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            }
        }
        default: {
            return ((slop_list_sroiq_SAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        }
    }
}

slop_list_sroiq_SConcept sriqelim_atoms_of(slop_arena* arena, sroiq_SConcept c) {
    {
        __auto_type out = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1042 = c;
        switch (_mv_1042.tag) {
            case sroiq_SConcept_sc_elim:
            {
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case sroiq_SConcept_sc_not:
            {
                __auto_type f = _mv_1042.data.sc_not;
                {
                    __auto_type _coll = sriqelim_atoms_of(arena, (*f));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case sroiq_SConcept_sc_and:
            {
                __auto_type xs = _mv_1042.data.sc_and;
                {
                    __auto_type _coll = xs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type y = _coll.data[_i];
                        {
                            __auto_type _coll = sriqelim_atoms_of(arena, y);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type x = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case sroiq_SConcept_sc_or:
            {
                __auto_type xs = _mv_1042.data.sc_or;
                {
                    __auto_type _coll = xs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type y = _coll.data[_i];
                        {
                            __auto_type _coll = sriqelim_atoms_of(arena, y);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type x = _coll.data[_i];
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
                break;
            }
            case sroiq_SConcept_sc_some:
            {
                __auto_type f = _mv_1042.data.sc_some.f1;
                {
                    __auto_type _coll = sriqelim_atoms_of(arena, (*f));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case sroiq_SConcept_sc_all:
            {
                __auto_type f = _mv_1042.data.sc_all.f1;
                {
                    __auto_type _coll = sriqelim_atoms_of(arena, (*f));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case sroiq_SConcept_sc_atleast:
            {
                __auto_type f = _mv_1042.data.sc_atleast.f2;
                {
                    __auto_type _coll = sriqelim_atoms_of(arena, (*f));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case sroiq_SConcept_sc_atmost:
            {
                __auto_type f = _mv_1042.data.sc_atmost.f2;
                {
                    __auto_type _coll = sriqelim_atoms_of(arena, (*f));
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

slop_list_sroiq_SConcept sriqelim_append_atoms(slop_arena* arena, slop_list_sroiq_SConcept a, slop_list_sroiq_SConcept b) {
    {
        __auto_type out = ((slop_list_sroiq_SConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = b;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_string sriqelim_axiom_problems(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_sroiq_SAxiom axs, sroiq_SAxiom a) {
    {
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1043 = a;
        switch (_mv_1043.tag) {
            case sroiq_SAxiom_sa_ria:
            {
                __auto_type x = _mv_1043.data.sa_ria;
                if (sriqelim_ria_complex(rb, x)) {
                    ({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("a complex RIA is left: "), sroiq_render_saxiom(arena, a))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                break;
            }
            case sroiq_SAxiom_sa_gci:
            {
                __auto_type l = _mv_1043.data.sa_gci.f0;
                __auto_type r = _mv_1043.data.sa_gci.f1;
                if (!(sriqelim_item1_p((*l), (*r))) && (sriqelim_labelled_left(rb, (*l), 0) || sriqelim_labelled_left(rb, (*r), 1))) {
                    ({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("a labelled restriction is left: "), sroiq_render_saxiom(arena, a))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                {
                    __auto_type _coll = sriqelim_append_atoms(arena, sriqelim_atoms_of(arena, (*l)), sriqelim_atoms_of(arena, (*r)));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        {
                            __auto_type _coll = sriqelim_atom_axioms(arena, c);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type want = _coll.data[_i];
                                if (!(sriqelim_has_axiom(axs, want))) {
                                    ({ __auto_type _lst_p = &(bad); __auto_type _item = (string_concat(arena, SLOP_STR("an atom without its axioms: "), sroiq_render_sconcept(arena, c))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

uint8_t sriqelim_same_axioms(slop_list_sroiq_SAxiom a, slop_list_sroiq_SAxiom b) {
    {
        uint8_t ok = (((int64_t)((a).len)) == ((int64_t)((b).len)));
        int64_t i = 0;
        while (ok && (i < ((int64_t)(((int64_t)((a).len)))))) {
            __auto_type _mv_1044 = ({ __auto_type _lst = a; size_t _idx = (size_t)i; slop_option_sroiq_SAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1044.has_value) {
                __auto_type x = _mv_1044.value;
                __auto_type _mv_1045 = ({ __auto_type _lst = b; size_t _idx = (size_t)i; slop_option_sroiq_SAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                if (_mv_1045.has_value) {
                    __auto_type y = _mv_1045.value;
                    if (sroiq_sa_cmp(x, y) != 0) {
                        ok = 0;
                    }
                } else if (!_mv_1045.has_value) {
                    ok = 0;
                }
            } else if (!_mv_1044.has_value) {
                ok = 0;
            }
            i = (i + 1);
        }
        return ok;
    }
}

slop_list_string sriqelim_guarded_problems(slop_arena* arena, slop_list_sroiq_SAxiom s0_axioms, sriqelim_S1 s1) {
    {
        __auto_type want = sriqelim_guarded(arena, s0_axioms, 0);
        __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (!(sriqelim_same_axioms(want.axioms, s1.axioms))) {
            ({ __auto_type _lst_p = &(bad); __auto_type _item = (SLOP_STR("a guarded run's axioms are not S0 minus its chains")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        if (!(sriqelim_same_axioms(want.omitted, s1.omitted))) {
            ({ __auto_type _lst_p = &(bad); __auto_type _item = (SLOP_STR("a guarded run's omissions are not S0's chains")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        return bad;
    }
}

slop_list_string sriqelim_sriq_s1_invariants(slop_arena* arena, sriqrbox_SriqRbox rb, slop_list_sroiq_SAxiom s0_axioms, sriqelim_S1 s1) {
    if (((int64_t)((s1.omitted).len)) > 0) {
        return sriqelim_guarded_problems(arena, s0_axioms, s1);
    } else {
        {
            __auto_type bad = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = s1.axioms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type a = _coll.data[_i];
                    {
                        __auto_type _coll = sriqelim_axiom_problems(arena, rb, s1.axioms, a);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type b = _coll.data[_i];
                            ({ __auto_type _lst_p = &(bad); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
            return bad;
        }
    }
}

