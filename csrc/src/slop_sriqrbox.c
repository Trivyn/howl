#include "../runtime/slop_runtime.h"
#include "slop_sriqrbox.h"

int64_t sriqrbox_prop_idx(slop_list_types_RoleId props, types_RoleId r);
uint8_t sriqrbox_prop_new(slop_list_types_RoleId props, types_RoleId r);
types_RoleId sriqrbox_prop_at(slop_list_types_RoleId xs, int64_t i);
slop_list_types_RoleId sriqrbox_sort_props(slop_arena* arena, slop_list_types_RoleId xs);
slop_list_u8 sriqrbox_bools_new(slop_arena* arena, int64_t n);
uint8_t sriqrbox_bool_at(slop_list_u8 m, int64_t i);
types_RoleId sriqrbox_node_role(slop_list_types_RoleId props, int64_t n);
slop_list_int sriqrbox_ints_new(slop_arena* arena, int64_t n, int64_t v);
int64_t sriqrbox_int_at(slop_list_int xs, int64_t i);
int64_t sriqrbox_inv_node(int64_t n);
int64_t sriqrbox_sriq_node(slop_list_types_RoleId props, types_RoleId r);
slop_option_types_RoleId sriqrbox_property_of(types_RoleId r);
slop_list_types_RoleId sriqrbox_ria_roles(slop_arena* arena, owl2_RawAxiom ax);
uint8_t sriqrbox_is_sriq_ria(owl2_RawAxiom ax);
slop_list_types_RoleId sriqrbox_sriq_props(slop_arena* arena, slop_list_owl2_RawAxiom axs);
sriqrbox_Ria sriqrbox_ria_of(slop_arena* arena, int64_t x, int64_t y);
slop_list_sriqrbox_Ria sriqrbox_sriq_rias(slop_arena* arena, slop_list_types_RoleId props, slop_list_owl2_RawAxiom axs);
slop_list_int sriqrbox_sriq_nodes(slop_arena* arena, slop_list_types_RoleId props, slop_list_types_RoleId rs);
uint8_t sriqrbox_all_nodes(slop_list_int ns);
sriqrbox_Csr sriqrbox_csr_build(slop_arena* arena, int64_t n, slop_list_int src, slop_list_int dst);
slop_list_u8 sriqrbox_csr_reach(slop_arena* arena, sriqrbox_Csr g, int64_t n, slop_list_int starts);
slop_list_int sriqrbox_sriq_reps(slop_arena* arena, sriqrbox_Csr fwd, sriqrbox_Csr bwd, int64_t n);
slop_list_int sriqrbox_word_slice(slop_arena* arena, slop_list_int w, int64_t from, int64_t upto);
uint8_t sriqrbox_ints_subset(slop_list_int a, slop_list_int b);
slop_list_int sriqrbox_ria_constraints(slop_arena* arena, slop_list_int w, int64_t s);
slop_list_int sriqrbox_inv_word(slop_arena* arena, slop_list_int w);
slop_list_int sriqrbox_rep_word(slop_arena* arena, slop_list_int w, slop_list_int rep);
uint8_t sriqrbox_csr_acyclic(slop_arena* arena, sriqrbox_Csr g, int64_t n);
sriqrbox_SriqRbox sriqrbox_sriq_rbox_none(slop_arena* arena);
sriqrbox_SriqRbox sriqrbox_sriq_rbox(slop_arena* arena, slop_list_owl2_RawAxiom axs);
uint8_t sriqrbox_sriq_role_simple(sriqrbox_SriqRbox rb, types_RoleId r);
uint8_t sriqrbox_is_bottom_role(types_RoleId r);
uint8_t sriqrbox_sriq_concept_simple(sriqrbox_SriqRbox rb, owl2_RawConcept c);
uint8_t sriqrbox_sriq_concepts_simple(sriqrbox_SriqRbox rb, slop_list_owl2_RawConcept cs);
uint8_t sriqrbox_sriq_axiom_simple(sriqrbox_SriqRbox rb, owl2_RawAxiom ax);

typedef struct { slop_list_types_RoleId xs; } sriqrbox__lambda_342_env_t;

static int64_t sriqrbox__lambda_342(sriqrbox__lambda_342_env_t* _env, int64_t i, int64_t j) { return canon_role_cmp(sriqrbox_prop_at(_env->xs, i), sriqrbox_prop_at(_env->xs, j)); }

int64_t sriqrbox_prop_idx(slop_list_types_RoleId props, types_RoleId r) {
    {
        int64_t found = -1;
        int64_t i = 0;
        {
            __auto_type _coll = props;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if ((found < 0) && (canon_role_cmp(x, r) == 0)) {
                    found = i;
                }
                i = (i + 1);
            }
        }
        return found;
    }
}

uint8_t sriqrbox_prop_new(slop_list_types_RoleId props, types_RoleId r) {
    return (sriqrbox_prop_idx(props, r) < 0);
}

types_RoleId sriqrbox_prop_at(slop_list_types_RoleId xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_341 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_341.has_value) {
        __auto_type v = _mv_341.value;
        return v;
    } else if (!_mv_341.has_value) {
        return ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_list_types_RoleId sriqrbox_sort_props(slop_arena* arena, slop_list_types_RoleId xs) {
    {
        __auto_type idx = canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ sriqrbox__lambda_342_env_t* sriqrbox__lambda_342_env = (sriqrbox__lambda_342_env_t*)slop_arena_alloc(arena, sizeof(sriqrbox__lambda_342_env_t)); *sriqrbox__lambda_342_env = (sriqrbox__lambda_342_env_t){ .xs = xs }; (slop_closure_t){ (void*)sriqrbox__lambda_342, (void*)sriqrbox__lambda_342_env }; }));
        __auto_type out = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqrbox_prop_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_u8 sriqrbox_bools_new(slop_arena* arena, int64_t n) {
    {
        __auto_type m = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < n) {
            ({ __auto_type _lst_p = &(m); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        return m;
    }
}

uint8_t sriqrbox_bool_at(slop_list_u8 m, int64_t i) {
    __auto_type _mv_343 = ({ __auto_type _lst = m; size_t _idx = (size_t)i; slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_343.has_value) {
        __auto_type v = _mv_343.value;
        return v;
    } else if (!_mv_343.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

types_RoleId sriqrbox_node_role(slop_list_types_RoleId props, int64_t n) {
    SLOP_PRE(((n >= 0)), "(>= n 0)");
    {
        __auto_type p = sriqrbox_prop_at(props, (n / 2));
        if ((n % 2) == 0) {
            return p;
        } else {
            __auto_type _mv_344 = p;
            switch (_mv_344.tag) {
                case types_RoleId_named_role:
                {
                    __auto_type i = _mv_344.data.named_role;
                    return ((types_RoleId){ .tag = types_RoleId_inverse_role, .data.inverse_role = i });
                }
                case types_RoleId_inverse_role:
                {
                    __auto_type i = _mv_344.data.inverse_role;
                    return ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = i });
                }
                case types_RoleId_fresh_role:
                {
                    __auto_type _ = _mv_344.data.fresh_role;
                    return p;
                }
            }
            SLOP_UNREACHABLE();
        }
    }
}

slop_list_int sriqrbox_ints_new(slop_arena* arena, int64_t n, int64_t v) {
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

int64_t sriqrbox_int_at(slop_list_int xs, int64_t i) {
    __auto_type _mv_345 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_345.has_value) {
        __auto_type v = _mv_345.value;
        return v;
    } else if (!_mv_345.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

int64_t sriqrbox_inv_node(int64_t n) {
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

int64_t sriqrbox_sriq_node(slop_list_types_RoleId props, types_RoleId r) {
    __auto_type _mv_346 = r;
    switch (_mv_346.tag) {
        case types_RoleId_named_role:
        {
            __auto_type _ = _mv_346.data.named_role;
            {
                __auto_type k = sriqrbox_prop_idx(props, r);
                if (k < 0) {
                    return -1;
                } else {
                    return (2 * k);
                }
            }
        }
        case types_RoleId_inverse_role:
        {
            __auto_type i = _mv_346.data.inverse_role;
            {
                __auto_type k = sriqrbox_prop_idx(props, ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = i }));
                if (k < 0) {
                    return -1;
                } else {
                    return ((2 * k) + 1);
                }
            }
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_346.data.fresh_role;
            return -1;
        }
    }
    SLOP_UNREACHABLE();
}

slop_option_types_RoleId sriqrbox_property_of(types_RoleId r) {
    __auto_type _mv_347 = r;
    switch (_mv_347.tag) {
        case types_RoleId_named_role:
        {
            __auto_type _ = _mv_347.data.named_role;
            return (slop_option_types_RoleId){.has_value = 1, .value = r};
        }
        case types_RoleId_inverse_role:
        {
            __auto_type i = _mv_347.data.inverse_role;
            return (slop_option_types_RoleId){.has_value = 1, .value = ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = i })};
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_347.data.fresh_role;
            return (slop_option_types_RoleId){.has_value = false};
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_types_RoleId sriqrbox_ria_roles(slop_arena* arena, owl2_RawAxiom ax) {
    {
        __auto_type rs = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_348 = ax;
        switch (_mv_348.tag) {
            case owl2_RawAxiom_ra_sub_object_property:
            {
                __auto_type a = _mv_348.data.ra_sub_object_property.f0;
                __auto_type b = _mv_348.data.ra_sub_object_property.f1;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case owl2_RawAxiom_ra_property_chain:
            {
                __auto_type ch = _mv_348.data.ra_property_chain;
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
            case owl2_RawAxiom_ra_equivalent_properties:
            {
                __auto_type xs = _mv_348.data.ra_equivalent_properties;
                {
                    __auto_type _coll = xs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        ({ __auto_type _lst_p = &(rs); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                break;
            }
            case owl2_RawAxiom_ra_inverse_properties:
            {
                __auto_type a = _mv_348.data.ra_inverse_properties.f0;
                __auto_type b = _mv_348.data.ra_inverse_properties.f1;
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(rs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
            case owl2_RawAxiom_ra_property_characteristic:
            {
                __auto_type c = _mv_348.data.ra_property_characteristic.f0;
                __auto_type r = _mv_348.data.ra_property_characteristic.f1;
                if (c == owl2_PropCharacteristic_prop_symmetric) {
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

uint8_t sriqrbox_is_sriq_ria(owl2_RawAxiom ax) {
    __auto_type _mv_349 = ax;
    switch (_mv_349.tag) {
        case owl2_RawAxiom_ra_sub_object_property:
        {
            return 1;
        }
        case owl2_RawAxiom_ra_property_chain:
        {
            __auto_type _ = _mv_349.data.ra_property_chain;
            return 1;
        }
        case owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type _ = _mv_349.data.ra_equivalent_properties;
            return 1;
        }
        case owl2_RawAxiom_ra_inverse_properties:
        {
            return 1;
        }
        case owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type c = _mv_349.data.ra_property_characteristic.f0;
            return (c == owl2_PropCharacteristic_prop_symmetric);
        }
        default: {
            return 0;
        }
    }
}

slop_list_types_RoleId sriqrbox_sriq_props(slop_arena* arena, slop_list_owl2_RawAxiom axs) {
    {
        __auto_type ps = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                {
                    __auto_type _coll = sriqrbox_ria_roles(arena, ax);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        __auto_type _mv_350 = sriqrbox_property_of(r);
                        if (_mv_350.has_value) {
                            __auto_type pr = _mv_350.value;
                            if (sriqrbox_prop_new(ps, pr)) {
                                ({ __auto_type _lst_p = &(ps); __auto_type _item = (pr); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        } else if (!_mv_350.has_value) {
                        }
                    }
                }
            }
        }
        return sriqrbox_sort_props(arena, ps);
    }
}

sriqrbox_Ria sriqrbox_ria_of(slop_arena* arena, int64_t x, int64_t y) {
    {
        __auto_type w = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(w); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return ((sriqrbox_Ria){.word = w, .super = y});
    }
}

slop_list_sriqrbox_Ria sriqrbox_sriq_rias(slop_arena* arena, slop_list_types_RoleId props, slop_list_owl2_RawAxiom axs) {
    {
        __auto_type out = ((slop_list_sriqrbox_Ria){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_351 = ax;
                switch (_mv_351.tag) {
                    case owl2_RawAxiom_ra_sub_object_property:
                    {
                        __auto_type a = _mv_351.data.ra_sub_object_property.f0;
                        __auto_type b = _mv_351.data.ra_sub_object_property.f1;
                        {
                            __auto_type na = sriqrbox_sriq_node(props, a);
                            __auto_type nb = sriqrbox_sriq_node(props, b);
                            if ((na >= 0) && (nb >= 0)) {
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqrbox_ria_of(arena, na, nb)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        break;
                    }
                    case owl2_RawAxiom_ra_property_chain:
                    {
                        __auto_type ch = _mv_351.data.ra_property_chain;
                        {
                            __auto_type ns = sriqrbox_sriq_nodes(arena, props, ch.steps);
                            __auto_type sup = sriqrbox_sriq_node(props, ch.super);
                            if ((sup >= 0) && sriqrbox_all_nodes(ns)) {
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (((sriqrbox_Ria){.word = ns, .super = sup})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        break;
                    }
                    case owl2_RawAxiom_ra_equivalent_properties:
                    {
                        __auto_type rs = _mv_351.data.ra_equivalent_properties;
                        {
                            __auto_type ns = sriqrbox_sriq_nodes(arena, props, rs);
                            if (sriqrbox_all_nodes(ns)) {
                                {
                                    __auto_type _coll = ns;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type x = _coll.data[_i];
                                        {
                                            __auto_type _coll = ns;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type y = _coll.data[_i];
                                                if (x != y) {
                                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqrbox_ria_of(arena, x, y)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                    case owl2_RawAxiom_ra_inverse_properties:
                    {
                        __auto_type a = _mv_351.data.ra_inverse_properties.f0;
                        __auto_type b = _mv_351.data.ra_inverse_properties.f1;
                        {
                            __auto_type na = sriqrbox_sriq_node(props, a);
                            __auto_type nb = sriqrbox_sriq_node(props, b);
                            if ((na >= 0) && (nb >= 0)) {
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqrbox_ria_of(arena, na, sriqrbox_inv_node(nb))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqrbox_ria_of(arena, sriqrbox_inv_node(nb), na)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                        break;
                    }
                    case owl2_RawAxiom_ra_property_characteristic:
                    {
                        __auto_type c = _mv_351.data.ra_property_characteristic.f0;
                        __auto_type r = _mv_351.data.ra_property_characteristic.f1;
                        if (c == owl2_PropCharacteristic_prop_symmetric) {
                            {
                                __auto_type nr = sriqrbox_sriq_node(props, r);
                                if (nr >= 0) {
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqrbox_ria_of(arena, sriqrbox_inv_node(nr), nr)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        return out;
    }
}

slop_list_int sriqrbox_sriq_nodes(slop_arena* arena, slop_list_types_RoleId props, slop_list_types_RoleId rs) {
    {
        __auto_type ns = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                ({ __auto_type _lst_p = &(ns); __auto_type _item = (sriqrbox_sriq_node(props, r)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ns;
    }
}

uint8_t sriqrbox_all_nodes(slop_list_int ns) {
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

sriqrbox_Csr sriqrbox_csr_build(slop_arena* arena, int64_t n, slop_list_int src, slop_list_int dst) {
    {
        __auto_type off = sriqrbox_ints_new(arena, (n + 1), 0);
        __auto_type m = ((int64_t)(((int64_t)((src).len))));
        int64_t i = 0;
        {
            __auto_type _coll = src;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                ({ __auto_type _set_lst = &(off); size_t _set_idx = (size_t)((s + 1)); __auto_type _set_val = ((sriqrbox_int_at(off, (s + 1)) + 1)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
            }
        }
        i = 1;
        while (i <= n) {
            ({ __auto_type _set_lst = &(off); size_t _set_idx = (size_t)(i); __auto_type _set_val = ((sriqrbox_int_at(off, i) + sriqrbox_int_at(off, (i - 1)))); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
            i = (i + 1);
        }
        {
            __auto_type pos = sriqrbox_ints_new(arena, n, 0);
            __auto_type adj = sriqrbox_ints_new(arena, m, 0);
            int64_t k = 0;
            int64_t v = 0;
            while (v < n) {
                ({ __auto_type _set_lst = &(pos); size_t _set_idx = (size_t)(v); __auto_type _set_val = (sriqrbox_int_at(off, v)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
                v = (v + 1);
            }
            while (k < m) {
                {
                    __auto_type s = sriqrbox_int_at(src, k);
                    ({ __auto_type _set_lst = &(adj); size_t _set_idx = (size_t)(sriqrbox_int_at(pos, s)); __auto_type _set_val = (sriqrbox_int_at(dst, k)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
                    ({ __auto_type _set_lst = &(pos); size_t _set_idx = (size_t)(s); __auto_type _set_val = ((sriqrbox_int_at(pos, s) + 1)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
                    k = (k + 1);
                }
            }
            return ((sriqrbox_Csr){.off = off, .adj = adj});
        }
    }
}

slop_list_u8 sriqrbox_csr_reach(slop_arena* arena, sriqrbox_Csr g, int64_t n, slop_list_int starts) {
    {
        __auto_type seen = sriqrbox_bools_new(arena, n);
        __auto_type queue = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t head = 0;
        {
            __auto_type _coll = starts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                if ((s >= 0) && !(sriqrbox_bool_at(seen, s))) {
                    ({ __auto_type _set_lst = &(seen); size_t _set_idx = (size_t)(s); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
                    ({ __auto_type _lst_p = &(queue); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        while (head < ((int64_t)(((int64_t)((queue).len))))) {
            {
                __auto_type v = sriqrbox_int_at(queue, head);
                head = (head + 1);
                {
                    int64_t e = sriqrbox_int_at(g.off, v);
                    __auto_type stop = sriqrbox_int_at(g.off, (v + 1));
                    while (e < stop) {
                        {
                            __auto_type w = sriqrbox_int_at(g.adj, e);
                            if (!(sriqrbox_bool_at(seen, w))) {
                                ({ __auto_type _set_lst = &(seen); size_t _set_idx = (size_t)(w); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
                                ({ __auto_type _lst_p = &(queue); __auto_type _item = (w); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                            e = (e + 1);
                        }
                    }
                }
            }
        }
        return seen;
    }
}

slop_list_int sriqrbox_sriq_reps(slop_arena* arena, sriqrbox_Csr fwd, sriqrbox_Csr bwd, int64_t n) {
    {
        __auto_type rep = sriqrbox_ints_new(arena, n, -1);
        int64_t v = 0;
        while (v < n) {
            if (sriqrbox_int_at(rep, v) < 0) {
                {
                    __auto_type one = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    ({ __auto_type _lst_p = &(one); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    {
                        __auto_type f = sriqrbox_csr_reach(arena, fwd, n, one);
                        __auto_type b = sriqrbox_csr_reach(arena, bwd, n, one);
                        int64_t m = -1;
                        int64_t u = 0;
                        int64_t x = 0;
                        while (u < n) {
                            if ((sriqrbox_bool_at(f, u)) && (sriqrbox_bool_at(b, u)) && (((m < 0) || ((u / 2) < m)))) {
                                m = (u / 2);
                            }
                            u = (u + 1);
                        }
                        {
                            __auto_type r = (((sriqrbox_bool_at(f, (2 * m)) && sriqrbox_bool_at(b, (2 * m)))) ? (2 * m) : ((2 * m) + 1));
                            while (x < n) {
                                if (sriqrbox_bool_at(f, x) && sriqrbox_bool_at(b, x)) {
                                    ({ __auto_type _set_lst = &(rep); size_t _set_idx = (size_t)(x); __auto_type _set_val = (r); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
                                }
                                x = (x + 1);
                            }
                        }
                    }
                }
            }
            v = (v + 1);
        }
        return rep;
    }
}

slop_list_int sriqrbox_word_slice(slop_arena* arena, slop_list_int w, int64_t from, int64_t upto) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = from;
        while (i < upto) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqrbox_int_at(w, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        return out;
    }
}

uint8_t sriqrbox_ints_subset(slop_list_int a, slop_list_int b) {
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

slop_list_int sriqrbox_ria_constraints(slop_arena* arena, slop_list_int w, int64_t s) {
    {
        __auto_type n = ((int64_t)(((int64_t)((w).len))));
        __auto_type nothing = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (n == 1) {
            {
                __auto_type x = sriqrbox_int_at(w, 0);
                if ((x == s) || (x == sriqrbox_inv_node(s))) {
                    return nothing;
                } else {
                    return w;
                }
            }
        } else if (((n == 2)) && ((sriqrbox_int_at(w, 0) == s)) && ((sriqrbox_int_at(w, 1) == s))) {
            return nothing;
        } else {
            {
                __auto_type r2 = (sriqrbox_int_at(w, 0) == s);
                __auto_type r3 = (sriqrbox_int_at(w, (n - 1)) == s);
                __auto_type tail = sriqrbox_word_slice(arena, w, 1, n);
                __auto_type head = sriqrbox_word_slice(arena, w, 0, (n - 1));
                if (r2 && r3) {
                    if (sriqrbox_ints_subset(head, tail)) {
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

slop_list_int sriqrbox_inv_word(slop_arena* arena, slop_list_int w) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = (((int64_t)(((int64_t)((w).len)))) - 1);
        while (i >= 0) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqrbox_inv_node(sriqrbox_int_at(w, i))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i - 1);
        }
        return out;
    }
}

slop_list_int sriqrbox_rep_word(slop_arena* arena, slop_list_int w, slop_list_int rep) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = w;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (sriqrbox_int_at(rep, x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

uint8_t sriqrbox_csr_acyclic(slop_arena* arena, sriqrbox_Csr g, int64_t n) {
    {
        __auto_type indeg = sriqrbox_ints_new(arena, n, 0);
        __auto_type queue = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t head = 0;
        int64_t done = 0;
        int64_t v = 0;
        {
            __auto_type _coll = g.adj;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type w = _coll.data[_i];
                ({ __auto_type _set_lst = &(indeg); size_t _set_idx = (size_t)(w); __auto_type _set_val = ((sriqrbox_int_at(indeg, w) + 1)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
            }
        }
        while (v < n) {
            if (sriqrbox_int_at(indeg, v) == 0) {
                ({ __auto_type _lst_p = &(queue); __auto_type _item = (v); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
            v = (v + 1);
        }
        while (head < ((int64_t)(((int64_t)((queue).len))))) {
            {
                __auto_type u = sriqrbox_int_at(queue, head);
                head = (head + 1);
                done = (done + 1);
                {
                    int64_t e = sriqrbox_int_at(g.off, u);
                    __auto_type stop = sriqrbox_int_at(g.off, (u + 1));
                    while (e < stop) {
                        {
                            __auto_type w = sriqrbox_int_at(g.adj, e);
                            ({ __auto_type _set_lst = &(indeg); size_t _set_idx = (size_t)(w); __auto_type _set_val = ((sriqrbox_int_at(indeg, w) - 1)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
                            if (sriqrbox_int_at(indeg, w) == 0) {
                                ({ __auto_type _lst_p = &(queue); __auto_type _item = (w); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                            e = (e + 1);
                        }
                    }
                }
            }
        }
        return (done == n);
    }
}

sriqrbox_SriqRbox sriqrbox_sriq_rbox_none(slop_arena* arena) {
    return ((sriqrbox_SriqRbox){.props = ((slop_list_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .nonsimple = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .rep = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .rias = ((slop_list_sriqrbox_Ria){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .regular = 1});
}

sriqrbox_SriqRbox sriqrbox_sriq_rbox(slop_arena* arena, slop_list_owl2_RawAxiom axs) {
    {
        __auto_type props = sriqrbox_sriq_props(arena, axs);
        __auto_type n = (2 * ((int64_t)(((int64_t)((props).len)))));
        __auto_type rias = sriqrbox_sriq_rias(arena, props, axs);
        __auto_type fs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type fd = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seeds = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type cs = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type cd = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = rias;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ria = _coll.data[_i];
                if (((int64_t)((ria.word).len)) == 1) {
                    {
                        __auto_type x = sriqrbox_int_at(ria.word, 0);
                        __auto_type s = ria.super;
                        ({ __auto_type _lst_p = &(fs); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(fd); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(fs); __auto_type _item = (sriqrbox_inv_node(x)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        ({ __auto_type _lst_p = &(fd); __auto_type _item = (sriqrbox_inv_node(s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                } else {
                    ({ __auto_type _lst_p = &(seeds); __auto_type _item = (ria.super); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(seeds); __auto_type _item = (sriqrbox_inv_node(ria.super)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        {
            __auto_type bot = sriqrbox_sriq_node(props, ((types_RoleId){ .tag = types_RoleId_named_role, .data.named_role = ((rdf_IRI){.value = vocab_OWL_BOTTOM_OBJECT_PROPERTY}) }));
            if (bot >= 0) {
                ({ __auto_type _lst_p = &(seeds); __auto_type _item = (bot); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(seeds); __auto_type _item = (sriqrbox_inv_node(bot)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type fwd = sriqrbox_csr_build(arena, n, fs, fd);
            __auto_type bwd = sriqrbox_csr_build(arena, n, fd, fs);
            {
                __auto_type nonsimple = sriqrbox_csr_reach(arena, fwd, n, seeds);
                __auto_type rep = sriqrbox_sriq_reps(arena, fwd, bwd, n);
                {
                    __auto_type _coll = rias;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type ria = _coll.data[_i];
                        if ((((int64_t)((ria.word).len)) > 1) || sriqrbox_bool_at(nonsimple, ria.super)) {
                            {
                                __auto_type w = sriqrbox_rep_word(arena, ria.word, rep);
                                __auto_type s = sriqrbox_int_at(rep, ria.super);
                                {
                                    __auto_type _coll = sriqrbox_ria_constraints(arena, w, s);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type x = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(cs); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        ({ __auto_type _lst_p = &(cd); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                                {
                                    __auto_type _coll = sriqrbox_ria_constraints(arena, sriqrbox_inv_word(arena, w), sriqrbox_inv_node(s));
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type x = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(cs); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        ({ __auto_type _lst_p = &(cd); __auto_type _item = (sriqrbox_inv_node(s)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                }
                return ((sriqrbox_SriqRbox){.props = props, .nonsimple = nonsimple, .rep = rep, .rias = rias, .regular = sriqrbox_csr_acyclic(arena, sriqrbox_csr_build(arena, n, cs, cd), n)});
            }
        }
    }
}

uint8_t sriqrbox_sriq_role_simple(sriqrbox_SriqRbox rb, types_RoleId r) {
    {
        __auto_type nd = sriqrbox_sriq_node(rb.props, r);
        if (nd < 0) {
            __auto_type _mv_352 = sriqrbox_property_of(r);
            if (_mv_352.has_value) {
                __auto_type pr = _mv_352.value;
                return !(sriqrbox_is_bottom_role(pr));
            } else if (!_mv_352.has_value) {
                return 1;
            }
            SLOP_UNREACHABLE();
        } else {
            return !(sriqrbox_bool_at(rb.nonsimple, nd));
        }
    }
}

uint8_t sriqrbox_is_bottom_role(types_RoleId r) {
    __auto_type _mv_353 = r;
    switch (_mv_353.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_353.data.named_role;
            return (canon_string_cmp(i.value, vocab_OWL_BOTTOM_OBJECT_PROPERTY) == 0);
        }
        case types_RoleId_inverse_role:
        {
            __auto_type i = _mv_353.data.inverse_role;
            return (canon_string_cmp(i.value, vocab_OWL_BOTTOM_OBJECT_PROPERTY) == 0);
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_353.data.fresh_role;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t sriqrbox_sriq_concept_simple(sriqrbox_SriqRbox rb, owl2_RawConcept c) {
    __auto_type _mv_354 = c;
    switch (_mv_354.tag) {
        case owl2_RawConcept_rc_card:
        {
            __auto_type r = _mv_354.data.rc_card.f1;
            return sriqrbox_sriq_role_simple(rb, r);
        }
        case owl2_RawConcept_rc_qcard:
        {
            __auto_type r = _mv_354.data.rc_qcard.f1;
            __auto_type f = _mv_354.data.rc_qcard.f3;
            return (sriqrbox_sriq_role_simple(rb, r) && sriqrbox_sriq_concept_simple(rb, (*f)));
        }
        case owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_354.data.rc_has_self;
            return sriqrbox_sriq_role_simple(rb, r);
        }
        case owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_354.data.rc_and;
            return sriqrbox_sriq_concepts_simple(rb, cs);
        }
        case owl2_RawConcept_rc_or:
        {
            __auto_type cs = _mv_354.data.rc_or;
            return sriqrbox_sriq_concepts_simple(rb, cs);
        }
        case owl2_RawConcept_rc_not:
        {
            __auto_type f = _mv_354.data.rc_not;
            return sriqrbox_sriq_concept_simple(rb, (*f));
        }
        case owl2_RawConcept_rc_some:
        {
            __auto_type f = _mv_354.data.rc_some.f1;
            return sriqrbox_sriq_concept_simple(rb, (*f));
        }
        case owl2_RawConcept_rc_all:
        {
            __auto_type f = _mv_354.data.rc_all.f1;
            return sriqrbox_sriq_concept_simple(rb, (*f));
        }
        default: {
            return 1;
        }
    }
}

uint8_t sriqrbox_sriq_concepts_simple(sriqrbox_SriqRbox rb, slop_list_owl2_RawConcept cs) {
    {
        uint8_t ok = 1;
        {
            __auto_type _coll = cs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (!(sriqrbox_sriq_concept_simple(rb, c))) {
                    ok = 0;
                }
            }
        }
        return ok;
    }
}

uint8_t sriqrbox_sriq_axiom_simple(sriqrbox_SriqRbox rb, owl2_RawAxiom ax) {
    __auto_type _mv_355 = ax;
    switch (_mv_355.tag) {
        case owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_355.data.ra_sub_class_of.f0;
            __auto_type r = _mv_355.data.ra_sub_class_of.f1;
            return (sriqrbox_sriq_concept_simple(rb, (*l)) && sriqrbox_sriq_concept_simple(rb, (*r)));
        }
        case owl2_RawAxiom_ra_equivalent_classes:
        {
            __auto_type cs = _mv_355.data.ra_equivalent_classes;
            return sriqrbox_sriq_concepts_simple(rb, cs);
        }
        case owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_355.data.ra_disjoint_classes;
            return sriqrbox_sriq_concepts_simple(rb, cs);
        }
        case owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type c = _mv_355.data.ra_object_property_domain.f1;
            return sriqrbox_sriq_concept_simple(rb, (*c));
        }
        case owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type c = _mv_355.data.ra_object_property_range.f1;
            return sriqrbox_sriq_concept_simple(rb, (*c));
        }
        case owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_355.data.ra_class_assertion;
            return sriqrbox_sriq_concept_simple(rb, (*ca.concept));
        }
        case owl2_RawAxiom_ra_disjoint_union:
        {
            __auto_type du = _mv_355.data.ra_disjoint_union;
            return sriqrbox_sriq_concepts_simple(rb, du.members);
        }
        case owl2_RawAxiom_ra_property_characteristic:
        {
            __auto_type c = _mv_355.data.ra_property_characteristic.f0;
            __auto_type r = _mv_355.data.ra_property_characteristic.f1;
            if ((c == owl2_PropCharacteristic_prop_functional) || ((c == owl2_PropCharacteristic_prop_inverse_functional) || ((c == owl2_PropCharacteristic_prop_irreflexive) || (c == owl2_PropCharacteristic_prop_asymmetric)))) {
                return sriqrbox_sriq_role_simple(rb, r);
            } else {
                return 1;
            }
        }
        case owl2_RawAxiom_ra_disjoint_properties:
        {
            __auto_type rs = _mv_355.data.ra_disjoint_properties;
            {
                uint8_t ok = 1;
                {
                    __auto_type _coll = rs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        if (!(sriqrbox_sriq_role_simple(rb, r))) {
                            ok = 0;
                        }
                    }
                }
                return ok;
            }
        }
        default: {
            return 1;
        }
    }
}

