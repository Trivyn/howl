#include "../runtime/slop_runtime.h"
#include "slop_sriqrbox.h"

int64_t howl_sriqrbox_prop_idx(slop_list_howl_types_RoleId props, howl_types_RoleId r);
uint8_t howl_sriqrbox_prop_new(slop_list_howl_types_RoleId props, howl_types_RoleId r);
howl_types_RoleId howl_sriqrbox_prop_at(slop_list_howl_types_RoleId xs, int64_t i);
slop_list_howl_types_RoleId howl_sriqrbox_sort_props(slop_arena* arena, slop_list_howl_types_RoleId xs);
slop_list_u8 howl_sriqrbox_bools_new(slop_arena* arena, int64_t n);
uint8_t howl_sriqrbox_bool_at(slop_list_u8 m, int64_t i);
howl_types_RoleId howl_sriqrbox_node_role(slop_list_howl_types_RoleId props, int64_t n);
slop_list_int howl_sriqrbox_ints_new(slop_arena* arena, int64_t n, int64_t v);
int64_t howl_sriqrbox_int_at(slop_list_int xs, int64_t i);
int64_t howl_sriqrbox_inv_node(int64_t n);
int64_t howl_sriqrbox_sriq_node(slop_list_howl_types_RoleId props, howl_types_RoleId r);
slop_option_howl_types_RoleId howl_sriqrbox_property_of(howl_types_RoleId r);
slop_list_howl_types_RoleId howl_sriqrbox_ria_roles(slop_arena* arena, howl_owl2_RawAxiom ax);
uint8_t howl_sriqrbox_is_sriq_ria(howl_owl2_RawAxiom ax);
slop_list_howl_types_RoleId howl_sriqrbox_sriq_props(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
howl_sriqrbox_Ria howl_sriqrbox_ria_of(slop_arena* arena, int64_t x, int64_t y);
slop_list_howl_sriqrbox_Ria howl_sriqrbox_no_rias(slop_arena* arena);
slop_list_howl_sriqrbox_Ria howl_sriqrbox_rias_sub(slop_arena* arena, slop_list_howl_types_RoleId props, howl_types_RoleId a, howl_types_RoleId b);
slop_list_howl_sriqrbox_Ria howl_sriqrbox_rias_chain(slop_arena* arena, slop_list_howl_types_RoleId props, howl_owl2_RawChain ch);
slop_list_howl_sriqrbox_Ria howl_sriqrbox_rias_equivalent(slop_arena* arena, slop_list_howl_types_RoleId props, slop_list_howl_types_RoleId rs);
slop_list_howl_sriqrbox_Ria howl_sriqrbox_rias_inverse(slop_arena* arena, slop_list_howl_types_RoleId props, howl_types_RoleId a, howl_types_RoleId b);
slop_list_howl_sriqrbox_Ria howl_sriqrbox_rias_symmetric(slop_arena* arena, slop_list_howl_types_RoleId props, howl_owl2_PropCharacteristic c, howl_types_RoleId r);
slop_list_howl_sriqrbox_Ria howl_sriqrbox_rias_of(slop_arena* arena, slop_list_howl_types_RoleId props, howl_owl2_RawAxiom ax);
slop_list_howl_sriqrbox_Ria howl_sriqrbox_sriq_rias(slop_arena* arena, slop_list_howl_types_RoleId props, slop_list_howl_owl2_RawAxiom axs);
slop_list_int howl_sriqrbox_ria_sources(slop_arena* arena, slop_list_howl_types_RoleId props, slop_list_howl_owl2_RawAxiom axs);
slop_list_int howl_sriqrbox_sriq_nodes(slop_arena* arena, slop_list_howl_types_RoleId props, slop_list_howl_types_RoleId rs);
uint8_t howl_sriqrbox_all_nodes(slop_list_int ns);
howl_sriqrbox_Csr howl_sriqrbox_csr_build(slop_arena* arena, int64_t n, slop_list_int src, slop_list_int dst);
slop_list_int howl_sriqrbox_targets(slop_arena* arena, howl_sriqrbox_Csr g, int64_t v);
slop_list_u8 howl_sriqrbox_csr_reach(slop_arena* arena, howl_sriqrbox_Csr g, int64_t n, slop_list_int starts);
uint8_t howl_sriqrbox_in_both(slop_list_u8 f, slop_list_u8 b, int64_t u);
int64_t howl_sriqrbox_least_prop_in(slop_list_u8 f, slop_list_u8 b, int64_t n);
int64_t howl_sriqrbox_component_rep(slop_list_u8 f, slop_list_u8 b, int64_t m);
uint8_t howl_sriqrbox_mark_component(slop_list_int rep, slop_list_u8 f, slop_list_u8 b, int64_t n, int64_t r);
uint8_t howl_sriqrbox_rep_component(slop_arena* arena, howl_sriqrbox_Csr fwd, howl_sriqrbox_Csr bwd, int64_t n, slop_list_int rep, int64_t v);
slop_list_int howl_sriqrbox_sriq_reps(slop_arena* arena, howl_sriqrbox_Csr fwd, howl_sriqrbox_Csr bwd, int64_t n);
slop_list_int howl_sriqrbox_word_slice(slop_arena* arena, slop_list_int w, int64_t from, int64_t upto);
uint8_t howl_sriqrbox_ints_subset(slop_list_int a, slop_list_int b);
slop_list_int howl_sriqrbox_ria_constraints(slop_arena* arena, slop_list_int w, int64_t s);
slop_list_int howl_sriqrbox_inv_word(slop_arena* arena, slop_list_int w);
slop_list_int howl_sriqrbox_rep_word(slop_arena* arena, slop_list_int w, slop_list_int rep);
slop_list_int howl_sriqrbox_indegrees(slop_arena* arena, howl_sriqrbox_Csr g, int64_t n);
uint8_t howl_sriqrbox_csr_acyclic(slop_arena* arena, howl_sriqrbox_Csr g, int64_t n);
howl_sriqrbox_SriqRbox howl_sriqrbox_sriq_rbox_none(slop_arena* arena);
howl_sriqrbox_Edges howl_sriqrbox_hierarchy_edges(slop_arena* arena, slop_list_howl_sriqrbox_Ria rias);
slop_list_int howl_sriqrbox_composite_seeds(slop_arena* arena, slop_list_howl_types_RoleId props, slop_list_howl_sriqrbox_Ria rias);
howl_sriqrbox_Edges howl_sriqrbox_constraint_edges(slop_arena* arena, slop_list_howl_sriqrbox_Ria rias, slop_list_u8 nonsimple, slop_list_int rep);
howl_sriqrbox_SriqRbox howl_sriqrbox_sriq_rbox(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
slop_list_int howl_sriqrbox_component_ids(slop_arena* arena, howl_sriqrbox_Csr fwd, howl_sriqrbox_Csr bwd, int64_t n);
slop_list_int howl_sriqrbox_sriq_witness(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, howl_sriqrbox_SriqRbox rb);
uint8_t howl_sriqrbox_sriq_role_simple(howl_sriqrbox_SriqRbox rb, howl_types_RoleId r);
uint8_t howl_sriqrbox_is_bottom_role(howl_types_RoleId r);
slop_option_howl_types_RoleId howl_sriqrbox_lesser_role(slop_option_howl_types_RoleId a, slop_option_howl_types_RoleId b);
slop_option_howl_types_RoleId howl_sriqrbox_role_nonsimple(howl_sriqrbox_SriqRbox rb, howl_types_RoleId r);
slop_option_howl_types_RoleId howl_sriqrbox_sriq_concept_nonsimple(howl_sriqrbox_SriqRbox rb, howl_owl2_RawConcept c);
slop_option_howl_types_RoleId howl_sriqrbox_sriq_concepts_nonsimple(howl_sriqrbox_SriqRbox rb, slop_list_howl_owl2_RawConcept cs);
slop_option_howl_types_RoleId howl_sriqrbox_sriq_axiom_nonsimple(howl_sriqrbox_SriqRbox rb, howl_owl2_RawAxiom ax);
uint8_t howl_sriqrbox_sriq_axiom_simple(howl_sriqrbox_SriqRbox rb, howl_owl2_RawAxiom ax);

typedef struct { slop_list_howl_types_RoleId xs; } howl_sriqrbox__lambda_153_env_t;

static int64_t howl_sriqrbox__lambda_153(howl_sriqrbox__lambda_153_env_t* _env, int64_t i, int64_t j) { return howl_canon_role_cmp(howl_sriqrbox_prop_at(_env->xs, i), howl_sriqrbox_prop_at(_env->xs, j)); }

int64_t howl_sriqrbox_prop_idx(slop_list_howl_types_RoleId props, howl_types_RoleId r) {
    {
        int64_t found = -1;
        int64_t i = 0;
        {
            __auto_type _coll = props;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if ((found < 0) && (howl_canon_role_cmp(x, r) == 0)) {
                    found = i;
                }
                i = (i + 1);
            }
        }
        return found;
    }
}

uint8_t howl_sriqrbox_prop_new(slop_list_howl_types_RoleId props, howl_types_RoleId r) {
    return (howl_sriqrbox_prop_idx(props, r) < 0);
}

howl_types_RoleId howl_sriqrbox_prop_at(slop_list_howl_types_RoleId xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_152 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_152.has_value) {
        __auto_type v = _mv_152.value;
        return v;
    } else if (!_mv_152.has_value) {
        return ((howl_types_RoleId){ .tag = howl_types_RoleId_fresh_role, .data.fresh_role = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_RoleId howl_sriqrbox_sort_props(slop_arena* arena, slop_list_howl_types_RoleId xs) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ howl_sriqrbox__lambda_153_env_t* howl_sriqrbox__lambda_153_env = (howl_sriqrbox__lambda_153_env_t*)slop_arena_alloc(arena, sizeof(howl_sriqrbox__lambda_153_env_t)); *howl_sriqrbox__lambda_153_env = (howl_sriqrbox__lambda_153_env_t){ .xs = xs }; (slop_closure_t){ (void*)howl_sriqrbox__lambda_153, (void*)howl_sriqrbox__lambda_153_env }; }));
        __auto_type out = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqrbox_prop_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_u8 howl_sriqrbox_bools_new(slop_arena* arena, int64_t n) {
    {
        __auto_type m = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < n) {
            (void)(({ __auto_type _lst_p = &(m); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            i = (i + 1);
        }
        return m;
    }
}

uint8_t howl_sriqrbox_bool_at(slop_list_u8 m, int64_t i) {
    __auto_type _mv_154 = ({ __auto_type _lst = m; size_t _idx = (size_t)i; slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_154.has_value) {
        __auto_type v = _mv_154.value;
        return v;
    } else if (!_mv_154.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

howl_types_RoleId howl_sriqrbox_node_role(slop_list_howl_types_RoleId props, int64_t n) {
    SLOP_PRE(((n >= 0)), "(>= n 0)");
    {
        __auto_type p = howl_sriqrbox_prop_at(props, (n / 2));
        if ((n % 2) == 0) {
            return p;
        } else {
            __auto_type _mv_155 = p;
            switch (_mv_155.tag) {
                case howl_types_RoleId_named_role:
                {
                    __auto_type i = _mv_155.data.named_role;
                    return ((howl_types_RoleId){ .tag = howl_types_RoleId_inverse_role, .data.inverse_role = i });
                }
                case howl_types_RoleId_inverse_role:
                {
                    __auto_type i = _mv_155.data.inverse_role;
                    return ((howl_types_RoleId){ .tag = howl_types_RoleId_named_role, .data.named_role = i });
                }
                case howl_types_RoleId_fresh_role:
                {
                    __auto_type _ = _mv_155.data.fresh_role;
                    return p;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
}

slop_list_int howl_sriqrbox_ints_new(slop_arena* arena, int64_t n, int64_t v) {
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

int64_t howl_sriqrbox_int_at(slop_list_int xs, int64_t i) {
    __auto_type _mv_156 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_156.has_value) {
        __auto_type v = _mv_156.value;
        return v;
    } else if (!_mv_156.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

int64_t howl_sriqrbox_inv_node(int64_t n) {
    SLOP_PRE(((n >= 0)), "(>= n 0)");
    int64_t _retval = {0};
    if ((n % 2) == 0) {
        _retval = (n + 1);
        goto _slop_post;
    } else {
        _retval = (n - 1);
        goto _slop_post;
    }
    _slop_post: ;
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    return _retval;
}

int64_t howl_sriqrbox_sriq_node(slop_list_howl_types_RoleId props, howl_types_RoleId r) {
    __auto_type _mv_157 = r;
    switch (_mv_157.tag) {
        case howl_types_RoleId_named_role:
        {
            __auto_type _ = _mv_157.data.named_role;
            {
                __auto_type k = howl_sriqrbox_prop_idx(props, r);
                if (k < 0) {
                    return -1;
                } else {
                    return (2 * k);
                }
            }
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type i = _mv_157.data.inverse_role;
            {
                __auto_type k = howl_sriqrbox_prop_idx(props, ((howl_types_RoleId){ .tag = howl_types_RoleId_named_role, .data.named_role = i }));
                if (k < 0) {
                    return -1;
                } else {
                    return ((2 * k) + 1);
                }
            }
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_157.data.fresh_role;
            return -1;
        }
    }
    SLOP_UNREACHABLE();
}

slop_option_howl_types_RoleId howl_sriqrbox_property_of(howl_types_RoleId r) {
    __auto_type _mv_158 = r;
    switch (_mv_158.tag) {
        case howl_types_RoleId_named_role:
        {
            __auto_type _ = _mv_158.data.named_role;
            return (slop_option_howl_types_RoleId){.has_value = 1, .value = r};
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type i = _mv_158.data.inverse_role;
            return (slop_option_howl_types_RoleId){.has_value = 1, .value = ((howl_types_RoleId){ .tag = howl_types_RoleId_named_role, .data.named_role = i })};
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_158.data.fresh_role;
            return (slop_option_howl_types_RoleId){.has_value = false};
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_RoleId howl_sriqrbox_ria_roles(slop_arena* arena, howl_owl2_RawAxiom ax) {
    {
        __auto_type rs = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_159 = ax;
        switch (_mv_159.tag) {
            case howl_owl2_RawAxiom_ra_sub_object_property:
            {
                __auto_type a = _mv_159.data.ra_sub_object_property.f0;
                __auto_type b = _mv_159.data.ra_sub_object_property.f1;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_owl2_RawAxiom_ra_property_chain:
            {
                __auto_type ch = _mv_159.data.ra_property_chain;
                {
                    __auto_type _coll = ch.steps;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type st = _coll.data[_i];
                        ({ __auto_type _lst_p = &(rs); __auto_type _item = (st); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (ch.super); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_owl2_RawAxiom_ra_equivalent_properties:
            {
                __auto_type xs = _mv_159.data.ra_equivalent_properties;
                {
                    __auto_type _coll = xs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        ({ __auto_type _lst_p = &(rs); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case howl_owl2_RawAxiom_ra_inverse_properties:
            {
                __auto_type a = _mv_159.data.ra_inverse_properties.f0;
                __auto_type b = _mv_159.data.ra_inverse_properties.f1;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case howl_owl2_RawAxiom_ra_property_characteristic:
            {
                __auto_type c = _mv_159.data.ra_property_characteristic.f0;
                __auto_type r = _mv_159.data.ra_property_characteristic.f1;
                if (c == howl_owl2_PropCharacteristic_prop_symmetric) {
                    ({ __auto_type _lst_p = &(rs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
                break;
            }
            default: {
                break;
            }
        }
        return rs;
    }
}

uint8_t howl_sriqrbox_is_sriq_ria(howl_owl2_RawAxiom ax) {
    __auto_type _mv_160 = ax;
    switch (_mv_160.tag) {
        case howl_owl2_RawAxiom_ra_sub_object_property:
        {
            return 1;
        }
        case howl_owl2_RawAxiom_ra_property_chain:
        {
            __auto_type _ = _mv_160.data.ra_property_chain;
            return 1;
        }
        case howl_owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type _ = _mv_160.data.ra_equivalent_properties;
            return 1;
        }
        case howl_owl2_RawAxiom_ra_inverse_properties:
        {
            return 1;
        }
        case howl_owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type c = _mv_160.data.ra_property_characteristic.f0;
            return (c == howl_owl2_PropCharacteristic_prop_symmetric);
        }
        default: {
            return 0;
        }
    }
}

slop_list_howl_types_RoleId howl_sriqrbox_sriq_props(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs) {
    {
        __auto_type ps = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                {
                    __auto_type _coll = howl_sriqrbox_ria_roles(arena, ax);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        __auto_type _mv_161 = howl_sriqrbox_property_of(r);
                        if (_mv_161.has_value) {
                            __auto_type pr = _mv_161.value;
                            if (howl_sriqrbox_prop_new(ps, pr)) {
                                ({ __auto_type _lst_p = &(ps); __auto_type _item = (pr); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        } else if (!_mv_161.has_value) {
                        }
                    }
                }
            }
        }
        return howl_sriqrbox_sort_props(arena, ps);
    }
}

howl_sriqrbox_Ria howl_sriqrbox_ria_of(slop_arena* arena, int64_t x, int64_t y) {
    {
        __auto_type w = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(w); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return ((howl_sriqrbox_Ria){.word = w, .super = y});
    }
}

slop_list_howl_sriqrbox_Ria howl_sriqrbox_no_rias(slop_arena* arena) {
    return ((slop_list_howl_sriqrbox_Ria){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
}

slop_list_howl_sriqrbox_Ria howl_sriqrbox_rias_sub(slop_arena* arena, slop_list_howl_types_RoleId props, howl_types_RoleId a, howl_types_RoleId b) {
    {
        __auto_type na = howl_sriqrbox_sriq_node(props, a);
        __auto_type nb = howl_sriqrbox_sriq_node(props, b);
        __auto_type out = ((slop_list_howl_sriqrbox_Ria){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if ((na >= 0) && (nb >= 0)) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqrbox_ria_of(arena, na, nb)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        return out;
    }
}

slop_list_howl_sriqrbox_Ria howl_sriqrbox_rias_chain(slop_arena* arena, slop_list_howl_types_RoleId props, howl_owl2_RawChain ch) {
    {
        __auto_type ns = howl_sriqrbox_sriq_nodes(arena, props, ch.steps);
        __auto_type sup = howl_sriqrbox_sriq_node(props, ch.super);
        __auto_type out = ((slop_list_howl_sriqrbox_Ria){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if ((sup >= 0) && howl_sriqrbox_all_nodes(ns)) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_sriqrbox_Ria){.word = ns, .super = sup})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        return out;
    }
}

slop_list_howl_sriqrbox_Ria howl_sriqrbox_rias_equivalent(slop_arena* arena, slop_list_howl_types_RoleId props, slop_list_howl_types_RoleId rs) {
    {
        __auto_type ns = howl_sriqrbox_sriq_nodes(arena, props, rs);
        __auto_type out = ((slop_list_howl_sriqrbox_Ria){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (howl_sriqrbox_all_nodes(ns)) {
            {
                __auto_type _coll = ns;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type x = _coll.data[_i];
                    {
                        __auto_type _coll = ns;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type y = _coll.data[_i];
                            if (x != y) {
                                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqrbox_ria_of(arena, x, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                        }
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_sriqrbox_Ria howl_sriqrbox_rias_inverse(slop_arena* arena, slop_list_howl_types_RoleId props, howl_types_RoleId a, howl_types_RoleId b) {
    {
        __auto_type na = howl_sriqrbox_sriq_node(props, a);
        __auto_type nb = howl_sriqrbox_sriq_node(props, b);
        __auto_type out = ((slop_list_howl_sriqrbox_Ria){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if ((na >= 0) && (nb >= 0)) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqrbox_ria_of(arena, na, howl_sriqrbox_inv_node(nb))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqrbox_ria_of(arena, howl_sriqrbox_inv_node(nb), na)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        return out;
    }
}

slop_list_howl_sriqrbox_Ria howl_sriqrbox_rias_symmetric(slop_arena* arena, slop_list_howl_types_RoleId props, howl_owl2_PropCharacteristic c, howl_types_RoleId r) {
    {
        __auto_type nr = howl_sriqrbox_sriq_node(props, r);
        __auto_type out = ((slop_list_howl_sriqrbox_Ria){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if ((c == howl_owl2_PropCharacteristic_prop_symmetric) && (nr >= 0)) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqrbox_ria_of(arena, howl_sriqrbox_inv_node(nr), nr)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        return out;
    }
}

slop_list_howl_sriqrbox_Ria howl_sriqrbox_rias_of(slop_arena* arena, slop_list_howl_types_RoleId props, howl_owl2_RawAxiom ax) {
    __auto_type _mv_162 = ax;
    switch (_mv_162.tag) {
        case howl_owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type a = _mv_162.data.ra_sub_object_property.f0;
            __auto_type b = _mv_162.data.ra_sub_object_property.f1;
            return howl_sriqrbox_rias_sub(arena, props, a, b);
        }
        case howl_owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_162.data.ra_property_chain;
            return howl_sriqrbox_rias_chain(arena, props, ch);
        }
        case howl_owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type rs = _mv_162.data.ra_equivalent_properties;
            return howl_sriqrbox_rias_equivalent(arena, props, rs);
        }
        case howl_owl2_RawAxiom_ra_inverse_properties:
        {
            __auto_type a = _mv_162.data.ra_inverse_properties.f0;
            __auto_type b = _mv_162.data.ra_inverse_properties.f1;
            return howl_sriqrbox_rias_inverse(arena, props, a, b);
        }
        case howl_owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type c = _mv_162.data.ra_property_characteristic.f0;
            __auto_type r = _mv_162.data.ra_property_characteristic.f1;
            return howl_sriqrbox_rias_symmetric(arena, props, c, r);
        }
        default: {
            return howl_sriqrbox_no_rias(arena);
        }
    }
}

slop_list_howl_sriqrbox_Ria howl_sriqrbox_sriq_rias(slop_arena* arena, slop_list_howl_types_RoleId props, slop_list_howl_owl2_RawAxiom axs) {
    {
        __auto_type out = ((slop_list_howl_sriqrbox_Ria){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                {
                    __auto_type _coll = howl_sriqrbox_rias_of(arena, props, ax);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

slop_list_int howl_sriqrbox_ria_sources(slop_arena* arena, slop_list_howl_types_RoleId props, slop_list_howl_owl2_RawAxiom axs) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                {
                    __auto_type _coll = howl_sriqrbox_rias_of(arena, props, ax);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (k); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
                k = (k + 1);
            }
        }
        return out;
    }
}

slop_list_int howl_sriqrbox_sriq_nodes(slop_arena* arena, slop_list_howl_types_RoleId props, slop_list_howl_types_RoleId rs) {
    {
        __auto_type ns = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(ns); __auto_type _item = (howl_sriqrbox_sriq_node(props, r)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ns;
    }
}

uint8_t howl_sriqrbox_all_nodes(slop_list_int ns) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = ns;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                if (n < 0) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

howl_sriqrbox_Csr howl_sriqrbox_csr_build(slop_arena* arena, int64_t n, slop_list_int src, slop_list_int dst) {
    {
        __auto_type off = howl_sriqrbox_ints_new(arena, (n + 1), 0);
        __auto_type m = ((int64_t)(((int64_t)((src).len))));
        int64_t i = 0;
        {
            __auto_type _coll = src;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                (void)(({ __auto_type _set_lst = &(off); size_t _set_idx = (size_t)((s + 1)); __auto_type _set_val = ((howl_sriqrbox_int_at(off, (s + 1)) + 1)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
            }
        }
        i = 1;
        while (i <= n) {
            (void)(({ __auto_type _set_lst = &(off); size_t _set_idx = (size_t)(i); __auto_type _set_val = ((howl_sriqrbox_int_at(off, i) + howl_sriqrbox_int_at(off, (i - 1)))); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
            i = (i + 1);
        }
        {
            __auto_type pos = howl_sriqrbox_ints_new(arena, n, 0);
            __auto_type adj = howl_sriqrbox_ints_new(arena, m, 0);
            int64_t k = 0;
            int64_t v = 0;
            while (v < n) {
                (void)(({ __auto_type _set_lst = &(pos); size_t _set_idx = (size_t)(v); __auto_type _set_val = (howl_sriqrbox_int_at(off, v)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
                v = (v + 1);
            }
            while (k < m) {
                {
                    __auto_type s = howl_sriqrbox_int_at(src, k);
                    (void)(({ __auto_type _set_lst = &(adj); size_t _set_idx = (size_t)(howl_sriqrbox_int_at(pos, s)); __auto_type _set_val = (howl_sriqrbox_int_at(dst, k)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
                    (void)(({ __auto_type _set_lst = &(pos); size_t _set_idx = (size_t)(s); __auto_type _set_val = ((howl_sriqrbox_int_at(pos, s) + 1)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
                    k = (k + 1);
                }
            }
            return ((howl_sriqrbox_Csr){.off = off, .adj = adj});
        }
    }
}

slop_list_int howl_sriqrbox_targets(slop_arena* arena, howl_sriqrbox_Csr g, int64_t v) {
    return howl_sriqrbox_word_slice(arena, g.adj, howl_sriqrbox_int_at(g.off, v), howl_sriqrbox_int_at(g.off, (v + 1)));
}

slop_list_u8 howl_sriqrbox_csr_reach(slop_arena* arena, howl_sriqrbox_Csr g, int64_t n, slop_list_int starts) {
    {
        __auto_type seen = howl_sriqrbox_bools_new(arena, n);
        __auto_type queue = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t head = 0;
        {
            __auto_type _coll = starts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                if ((s >= 0) && !(howl_sriqrbox_bool_at(seen, s))) {
                    (void)(({ __auto_type _set_lst = &(seen); size_t _set_idx = (size_t)(s); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
                    (void)(({ __auto_type _lst_p = &(queue); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        while (head < ((int64_t)(((int64_t)((queue).len))))) {
            {
                __auto_type _coll = howl_sriqrbox_targets(arena, g, howl_sriqrbox_int_at(queue, head));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type w = _coll.data[_i];
                    if (!(howl_sriqrbox_bool_at(seen, w))) {
                        (void)(({ __auto_type _set_lst = &(seen); size_t _set_idx = (size_t)(w); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
                        (void)(({ __auto_type _lst_p = &(queue); __auto_type _item = (w); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
            head = (head + 1);
        }
        return seen;
    }
}

uint8_t howl_sriqrbox_in_both(slop_list_u8 f, slop_list_u8 b, int64_t u) {
    return (howl_sriqrbox_bool_at(f, u) && howl_sriqrbox_bool_at(b, u));
}

int64_t howl_sriqrbox_least_prop_in(slop_list_u8 f, slop_list_u8 b, int64_t n) {
    {
        int64_t m = -1;
        int64_t u = 0;
        while (u < n) {
            if (howl_sriqrbox_in_both(f, b, u) && ((m < 0) || ((u / 2) < m))) {
                m = (u / 2);
            }
            u = (u + 1);
        }
        return m;
    }
}

int64_t howl_sriqrbox_component_rep(slop_list_u8 f, slop_list_u8 b, int64_t m) {
    if (howl_sriqrbox_in_both(f, b, (2 * m))) {
        return (2 * m);
    } else {
        return ((2 * m) + 1);
    }
}

uint8_t howl_sriqrbox_mark_component(slop_list_int rep, slop_list_u8 f, slop_list_u8 b, int64_t n, int64_t r) {
    {
        int64_t x = 0;
        while (x < n) {
            if (howl_sriqrbox_in_both(f, b, x)) {
                (void)(({ __auto_type _set_lst = &(rep); size_t _set_idx = (size_t)(x); __auto_type _set_val = (r); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
            }
            x = (x + 1);
        }
        return 1;
    }
}

uint8_t howl_sriqrbox_rep_component(slop_arena* arena, howl_sriqrbox_Csr fwd, howl_sriqrbox_Csr bwd, int64_t n, slop_list_int rep, int64_t v) {
    {
        __auto_type one = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(one); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        {
            __auto_type f = howl_sriqrbox_csr_reach(arena, fwd, n, one);
            __auto_type b = howl_sriqrbox_csr_reach(arena, bwd, n, one);
            return howl_sriqrbox_mark_component(rep, f, b, n, howl_sriqrbox_component_rep(f, b, howl_sriqrbox_least_prop_in(f, b, n)));
        }
    }
}

slop_list_int howl_sriqrbox_sriq_reps(slop_arena* arena, howl_sriqrbox_Csr fwd, howl_sriqrbox_Csr bwd, int64_t n) {
    {
        __auto_type rep = howl_sriqrbox_ints_new(arena, n, -1);
        int64_t v = 0;
        while (v < n) {
            if (howl_sriqrbox_int_at(rep, v) < 0) {
                howl_sriqrbox_rep_component(arena, fwd, bwd, n, rep, v);
            }
            v = (v + 1);
        }
        return rep;
    }
}

slop_list_int howl_sriqrbox_word_slice(slop_arena* arena, slop_list_int w, int64_t from, int64_t upto) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = from;
        while (i < upto) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqrbox_int_at(w, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            i = (i + 1);
        }
        return out;
    }
}

uint8_t howl_sriqrbox_ints_subset(slop_list_int a, slop_list_int b) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = a;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                {
                    uint8_t found = 0;
                    {
                        __auto_type _coll = b;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type y = _coll.data[_i];
                            if (x == y) {
                                found = 1;
                            }
                        }
                    }
                    if (!(found)) {
                        ok = 0;
                    }
                }
            }
        }
        return ok;
    }
}

slop_list_int howl_sriqrbox_ria_constraints(slop_arena* arena, slop_list_int w, int64_t s) {
    {
        __auto_type n = ((int64_t)(((int64_t)((w).len))));
        __auto_type nothing = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (n == 1) {
            {
                __auto_type x = howl_sriqrbox_int_at(w, 0);
                if ((x == s) || (x == howl_sriqrbox_inv_node(s))) {
                    return nothing;
                } else {
                    return w;
                }
            }
        } else if (((n == 2)) && ((howl_sriqrbox_int_at(w, 0) == s)) && ((howl_sriqrbox_int_at(w, 1) == s))) {
            return nothing;
        } else {
            {
                __auto_type r2 = (howl_sriqrbox_int_at(w, 0) == s);
                __auto_type r3 = (howl_sriqrbox_int_at(w, (n - 1)) == s);
                __auto_type tail = howl_sriqrbox_word_slice(arena, w, 1, n);
                __auto_type head = howl_sriqrbox_word_slice(arena, w, 0, (n - 1));
                if (r2 && r3) {
                    if (howl_sriqrbox_ints_subset(head, tail)) {
                        return head;
                    } else {
                        return tail;
                    }
                } else if (r2) {
                    return tail;
                } else if (r3) {
                    return head;
                } else {
                    return w;
                }
            }
        }
    }
}

slop_list_int howl_sriqrbox_inv_word(slop_arena* arena, slop_list_int w) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = (((int64_t)(((int64_t)((w).len)))) - 1);
        while (i >= 0) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqrbox_inv_node(howl_sriqrbox_int_at(w, i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            i = (i - 1);
        }
        return out;
    }
}

slop_list_int howl_sriqrbox_rep_word(slop_arena* arena, slop_list_int w, slop_list_int rep) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = w;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqrbox_int_at(rep, x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_int howl_sriqrbox_indegrees(slop_arena* arena, howl_sriqrbox_Csr g, int64_t n) {
    {
        __auto_type indeg = howl_sriqrbox_ints_new(arena, n, 0);
        {
            __auto_type _coll = g.adj;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type w = _coll.data[_i];
                (void)(({ __auto_type _set_lst = &(indeg); size_t _set_idx = (size_t)(w); __auto_type _set_val = ((howl_sriqrbox_int_at(indeg, w) + 1)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
            }
        }
        return indeg;
    }
}

uint8_t howl_sriqrbox_csr_acyclic(slop_arena* arena, howl_sriqrbox_Csr g, int64_t n) {
    {
        __auto_type indeg = howl_sriqrbox_indegrees(arena, g, n);
        __auto_type queue = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t head = 0;
        int64_t v = 0;
        while (v < n) {
            if (howl_sriqrbox_int_at(indeg, v) == 0) {
                (void)(({ __auto_type _lst_p = &(queue); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
            v = (v + 1);
        }
        while (head < ((int64_t)(((int64_t)((queue).len))))) {
            {
                __auto_type _coll = howl_sriqrbox_targets(arena, g, howl_sriqrbox_int_at(queue, head));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type w = _coll.data[_i];
                    (void)(({ __auto_type _set_lst = &(indeg); size_t _set_idx = (size_t)(w); __auto_type _set_val = ((howl_sriqrbox_int_at(indeg, w) - 1)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
                    if (howl_sriqrbox_int_at(indeg, w) == 0) {
                        (void)(({ __auto_type _lst_p = &(queue); __auto_type _item = (w); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
            head = (head + 1);
        }
        return (head == n);
    }
}

howl_sriqrbox_SriqRbox howl_sriqrbox_sriq_rbox_none(slop_arena* arena) {
    return ((howl_sriqrbox_SriqRbox){.props = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .nonsimple = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .rep = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .rias = ((slop_list_howl_sriqrbox_Ria){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .constraints = ((howl_sriqrbox_Edges){.src = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .dst = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .from = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena })}), .regular = 1});
}

howl_sriqrbox_Edges howl_sriqrbox_hierarchy_edges(slop_arena* arena, slop_list_howl_sriqrbox_Ria rias) {
    {
        __auto_type fs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type fd = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = rias;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ria = _coll.data[_i];
                if (((int64_t)((ria.word).len)) == 1) {
                    {
                        __auto_type x = howl_sriqrbox_int_at(ria.word, 0);
                        __auto_type s = ria.super;
                        (void)(({ __auto_type _lst_p = &(fs); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        (void)(({ __auto_type _lst_p = &(fd); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        (void)(({ __auto_type _lst_p = &(fs); __auto_type _item = (howl_sriqrbox_inv_node(x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        (void)(({ __auto_type _lst_p = &(fd); __auto_type _item = (howl_sriqrbox_inv_node(s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return ((howl_sriqrbox_Edges){.src = fs, .dst = fd, .from = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
    }
}

slop_list_int howl_sriqrbox_composite_seeds(slop_arena* arena, slop_list_howl_types_RoleId props, slop_list_howl_sriqrbox_Ria rias) {
    {
        __auto_type bot = howl_sriqrbox_sriq_node(props, ((howl_types_RoleId){ .tag = howl_types_RoleId_named_role, .data.named_role = ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_BOTTOM_OBJECT_PROPERTY}) }));
        __auto_type seeds = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = rias;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ria = _coll.data[_i];
                if (((int64_t)((ria.word).len)) != 1) {
                    (void)(({ __auto_type _lst_p = &(seeds); __auto_type _item = (ria.super); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    (void)(({ __auto_type _lst_p = &(seeds); __auto_type _item = (howl_sriqrbox_inv_node(ria.super)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        if (bot >= 0) {
            (void)(({ __auto_type _lst_p = &(seeds); __auto_type _item = (bot); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            (void)(({ __auto_type _lst_p = &(seeds); __auto_type _item = (howl_sriqrbox_inv_node(bot)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        return seeds;
    }
}

howl_sriqrbox_Edges howl_sriqrbox_constraint_edges(slop_arena* arena, slop_list_howl_sriqrbox_Ria rias, slop_list_u8 nonsimple, slop_list_int rep) {
    {
        __auto_type cs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type cd = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type cf = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        {
            __auto_type _coll = rias;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ria = _coll.data[_i];
                if ((((int64_t)((ria.word).len)) > 1) || howl_sriqrbox_bool_at(nonsimple, ria.super)) {
                    {
                        __auto_type w = howl_sriqrbox_rep_word(arena, ria.word, rep);
                        __auto_type s = howl_sriqrbox_int_at(rep, ria.super);
                        {
                            __auto_type _coll = howl_sriqrbox_ria_constraints(arena, w, s);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type x = _coll.data[_i];
                                (void)(({ __auto_type _lst_p = &(cs); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                (void)(({ __auto_type _lst_p = &(cd); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                (void)(({ __auto_type _lst_p = &(cf); __auto_type _item = (k); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                        }
                        {
                            __auto_type _coll = howl_sriqrbox_ria_constraints(arena, howl_sriqrbox_inv_word(arena, w), howl_sriqrbox_inv_node(s));
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type x = _coll.data[_i];
                                (void)(({ __auto_type _lst_p = &(cs); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                (void)(({ __auto_type _lst_p = &(cd); __auto_type _item = (howl_sriqrbox_inv_node(s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                (void)(({ __auto_type _lst_p = &(cf); __auto_type _item = (k); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                        }
                    }
                }
                k = (k + 1);
            }
        }
        return ((howl_sriqrbox_Edges){.src = cs, .dst = cd, .from = cf});
    }
}

howl_sriqrbox_SriqRbox howl_sriqrbox_sriq_rbox(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs) {
    {
        __auto_type props = howl_sriqrbox_sriq_props(arena, axs);
        __auto_type n = (2 * ((int64_t)(((int64_t)((props).len)))));
        __auto_type rias = howl_sriqrbox_sriq_rias(arena, props, axs);
        __auto_type h = howl_sriqrbox_hierarchy_edges(arena, rias);
        __auto_type fwd = howl_sriqrbox_csr_build(arena, n, h.src, h.dst);
        __auto_type bwd = howl_sriqrbox_csr_build(arena, n, h.dst, h.src);
        __auto_type nonsimple = howl_sriqrbox_csr_reach(arena, fwd, n, howl_sriqrbox_composite_seeds(arena, props, rias));
        __auto_type rep = howl_sriqrbox_sriq_reps(arena, fwd, bwd, n);
        __auto_type c = howl_sriqrbox_constraint_edges(arena, rias, nonsimple, rep);
        return ((howl_sriqrbox_SriqRbox){.props = props, .nonsimple = nonsimple, .rep = rep, .rias = rias, .constraints = c, .regular = howl_sriqrbox_csr_acyclic(arena, howl_sriqrbox_csr_build(arena, n, c.src, c.dst), n)});
    }
}

slop_list_int howl_sriqrbox_component_ids(slop_arena* arena, howl_sriqrbox_Csr fwd, howl_sriqrbox_Csr bwd, int64_t n) {
    {
        __auto_type ids = howl_sriqrbox_ints_new(arena, n, -1);
        int64_t v = 0;
        while (v < n) {
            if (howl_sriqrbox_int_at(ids, v) < 0) {
                {
                    __auto_type one = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    (void)(({ __auto_type _lst_p = &(one); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    howl_sriqrbox_mark_component(ids, howl_sriqrbox_csr_reach(arena, fwd, n, one), howl_sriqrbox_csr_reach(arena, bwd, n, one), n, v);
                }
            }
            v = (v + 1);
        }
        return ids;
    }
}

slop_list_int howl_sriqrbox_sriq_witness(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, howl_sriqrbox_SriqRbox rb) {
    {
        __auto_type c = rb.constraints;
        __auto_type src = howl_sriqrbox_ria_sources(arena, rb.props, axs);
        __auto_type n = (2 * ((int64_t)(((int64_t)((rb.props).len)))));
        __auto_type fwd = howl_sriqrbox_csr_build(arena, n, c.src, c.dst);
        __auto_type bwd = howl_sriqrbox_csr_build(arena, n, c.dst, c.src);
        __auto_type ids = howl_sriqrbox_component_ids(arena, fwd, bwd, n);
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t e = 0;
        {
            __auto_type _coll = c.src;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type u = _coll.data[_i];
                if (howl_sriqrbox_int_at(ids, u) == howl_sriqrbox_int_at(ids, howl_sriqrbox_int_at(c.dst, e))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_sriqrbox_int_at(src, howl_sriqrbox_int_at(c.from, e))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                e = (e + 1);
            }
        }
        return out;
    }
}

uint8_t howl_sriqrbox_sriq_role_simple(howl_sriqrbox_SriqRbox rb, howl_types_RoleId r) {
    {
        __auto_type nd = howl_sriqrbox_sriq_node(rb.props, r);
        if (nd < 0) {
            __auto_type _mv_163 = howl_sriqrbox_property_of(r);
            if (_mv_163.has_value) {
                __auto_type pr = _mv_163.value;
                return !(howl_sriqrbox_is_bottom_role(pr));
            } else if (!_mv_163.has_value) {
                return 1;
            }
            SLOP_UNREACHABLE();
        } else {
            return !(howl_sriqrbox_bool_at(rb.nonsimple, nd));
        }
    }
}

uint8_t howl_sriqrbox_is_bottom_role(howl_types_RoleId r) {
    __auto_type _mv_164 = r;
    switch (_mv_164.tag) {
        case howl_types_RoleId_named_role:
        {
            __auto_type i = _mv_164.data.named_role;
            return (howl_canon_string_cmp(i.value, slop_rdf_vocab_OWL_BOTTOM_OBJECT_PROPERTY) == 0);
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type i = _mv_164.data.inverse_role;
            return (howl_canon_string_cmp(i.value, slop_rdf_vocab_OWL_BOTTOM_OBJECT_PROPERTY) == 0);
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_164.data.fresh_role;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

slop_option_howl_types_RoleId howl_sriqrbox_lesser_role(slop_option_howl_types_RoleId a, slop_option_howl_types_RoleId b) {
    __auto_type _mv_165 = a;
    if (!_mv_165.has_value) {
        return b;
    } else if (_mv_165.has_value) {
        __auto_type x = _mv_165.value;
        __auto_type _mv_166 = b;
        if (!_mv_166.has_value) {
            return a;
        } else if (_mv_166.has_value) {
            __auto_type y = _mv_166.value;
            if (howl_canon_role_cmp(x, y) <= 0) {
                return a;
            } else {
                return b;
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_option_howl_types_RoleId howl_sriqrbox_role_nonsimple(howl_sriqrbox_SriqRbox rb, howl_types_RoleId r) {
    if (howl_sriqrbox_sriq_role_simple(rb, r)) {
        return (slop_option_howl_types_RoleId){.has_value = false};
    } else {
        return (slop_option_howl_types_RoleId){.has_value = 1, .value = r};
    }
}

slop_option_howl_types_RoleId howl_sriqrbox_sriq_concept_nonsimple(howl_sriqrbox_SriqRbox rb, howl_owl2_RawConcept c) {
    __auto_type _mv_167 = c;
    switch (_mv_167.tag) {
        case howl_owl2_RawConcept_rc_card:
        {
            __auto_type r = _mv_167.data.rc_card.f1;
            return howl_sriqrbox_role_nonsimple(rb, r);
        }
        case howl_owl2_RawConcept_rc_qcard:
        {
            __auto_type r = _mv_167.data.rc_qcard.f1;
            __auto_type f = _mv_167.data.rc_qcard.f3;
            return howl_sriqrbox_lesser_role(howl_sriqrbox_role_nonsimple(rb, r), howl_sriqrbox_sriq_concept_nonsimple(rb, (*f)));
        }
        case howl_owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_167.data.rc_has_self;
            return howl_sriqrbox_role_nonsimple(rb, r);
        }
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_167.data.rc_and;
            return howl_sriqrbox_sriq_concepts_nonsimple(rb, cs);
        }
        case howl_owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_167.data.rc_or;
            return howl_sriqrbox_sriq_concepts_nonsimple(rb, cs);
        }
        case howl_owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_167.data.rc_not;
            return howl_sriqrbox_sriq_concept_nonsimple(rb, (*f));
        }
        case howl_owl2_RawConcept_rc_some:
        {
            __auto_type f = _mv_167.data.rc_some.f1;
            return howl_sriqrbox_sriq_concept_nonsimple(rb, (*f));
        }
        case howl_owl2_RawConcept_rc_all:
        {
            __auto_type f = _mv_167.data.rc_all.f1;
            return howl_sriqrbox_sriq_concept_nonsimple(rb, (*f));
        }
        default: {
            return (slop_option_howl_types_RoleId){.has_value = false};
        }
    }
}

slop_option_howl_types_RoleId howl_sriqrbox_sriq_concepts_nonsimple(howl_sriqrbox_SriqRbox rb, slop_list_howl_owl2_RawConcept cs) {
    {
        slop_option_howl_types_RoleId out = (slop_option_howl_types_RoleId){.has_value = false};
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                out = howl_sriqrbox_lesser_role(out, howl_sriqrbox_sriq_concept_nonsimple(rb, c));
            }
        }
        return out;
    }
}

slop_option_howl_types_RoleId howl_sriqrbox_sriq_axiom_nonsimple(howl_sriqrbox_SriqRbox rb, howl_owl2_RawAxiom ax) {
    __auto_type _mv_168 = ax;
    switch (_mv_168.tag) {
        case howl_owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_168.data.ra_sub_class_of.f0;
            __auto_type r = _mv_168.data.ra_sub_class_of.f1;
            return howl_sriqrbox_lesser_role(howl_sriqrbox_sriq_concept_nonsimple(rb, (*l)), howl_sriqrbox_sriq_concept_nonsimple(rb, (*r)));
        }
        case howl_owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type cs = _mv_168.data.ra_equivalent_classes;
            return howl_sriqrbox_sriq_concepts_nonsimple(rb, cs);
        }
        case howl_owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_168.data.ra_disjoint_classes;
            return howl_sriqrbox_sriq_concepts_nonsimple(rb, cs);
        }
        case howl_owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type c = _mv_168.data.ra_object_property_domain.f1;
            return howl_sriqrbox_sriq_concept_nonsimple(rb, (*c));
        }
        case howl_owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type c = _mv_168.data.ra_object_property_range.f1;
            return howl_sriqrbox_sriq_concept_nonsimple(rb, (*c));
        }
        case howl_owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_168.data.ra_class_assertion;
            return howl_sriqrbox_sriq_concept_nonsimple(rb, (*ca.concept));
        }
        case howl_owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type du = _mv_168.data.ra_disjoint_union;
            return howl_sriqrbox_sriq_concepts_nonsimple(rb, du.members);
        }
        case howl_owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type c = _mv_168.data.ra_property_characteristic.f0;
            __auto_type r = _mv_168.data.ra_property_characteristic.f1;
            if ((c == howl_owl2_PropCharacteristic_prop_functional) || ((c == howl_owl2_PropCharacteristic_prop_inverse_functional) || ((c == howl_owl2_PropCharacteristic_prop_irreflexive) || (c == howl_owl2_PropCharacteristic_prop_asymmetric)))) {
                return howl_sriqrbox_role_nonsimple(rb, r);
            } else {
                return (slop_option_howl_types_RoleId){.has_value = false};
            }
        }
        case howl_owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type rs = _mv_168.data.ra_disjoint_properties;
            {
                slop_option_howl_types_RoleId out = (slop_option_howl_types_RoleId){.has_value = false};
                {
                    __auto_type _coll = rs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        out = howl_sriqrbox_lesser_role(out, howl_sriqrbox_role_nonsimple(rb, r));
                    }
                }
                return out;
            }
        }
        default: {
            return (slop_option_howl_types_RoleId){.has_value = false};
        }
    }
}

uint8_t howl_sriqrbox_sriq_axiom_simple(howl_sriqrbox_SriqRbox rb, howl_owl2_RawAxiom ax) {
    __auto_type _mv_169 = howl_sriqrbox_sriq_axiom_nonsimple(rb, ax);
    if (!_mv_169.has_value) {
        return 1;
    } else if (_mv_169.has_value) {
        __auto_type _ = _mv_169.value;
        return 0;
    }
    SLOP_UNREACHABLE();
}

