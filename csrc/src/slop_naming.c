#include "../runtime/slop_runtime.h"
#include "slop_naming.h"

naming_Registry* naming_new_registry(slop_arena* arena);
int64_t naming_fresh_id(slop_arena* arena, naming_Registry* p, slop_string text);
int64_t naming_fresh_role_id(slop_arena* arena, naming_Registry* p, slop_string text);
uint8_t naming_mark_neg(slop_arena* arena, naming_Registry* p, slop_string text);
uint8_t naming_mark_pos(slop_arena* arena, naming_Registry* p, slop_string text);
uint8_t naming_neg_defined(naming_Registry* p, slop_string text);
uint8_t naming_pos_defined(naming_Registry* p, slop_string text);
int64_t naming_fresh_count(naming_Registry* p);
int64_t naming_fresh_role_count(naming_Registry* p);
slop_list_owl2_RawConcept naming_flatten_and(slop_arena* arena, owl2_RawConcept c, slop_list_owl2_RawConcept acc);
slop_string naming_concept_key(slop_arena* arena, owl2_RawConcept c);
types_Node naming_node_at(slop_list_types_Node xs, int64_t i);
slop_string naming_node_key(slop_arena* arena, types_Node n);
slop_string naming_role_key(slop_arena* arena, types_RoleId r);
slop_string naming_prefix_text(slop_arena* arena, slop_list_owl2_RawConcept conj, int64_t upto);
types_RoleId naming_role_at_n(slop_list_types_RoleId xs, int64_t i);
slop_string naming_prefix_role_text(slop_arena* arena, slop_list_types_RoleId steps, int64_t upto, types_RoleId super);
slop_string naming_render_role_name(slop_arena* arena, types_RoleId r);

naming_Registry* naming_new_registry(slop_arena* arena) {
    {
        __auto_type p = ((naming_Registry*)(({ __auto_type _alloc = (naming_Registry*)slop_arena_alloc(arena, sizeof(naming_Registry)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = ((naming_Registry){.fresh = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .fresh_index = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .fresh_roles = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .fresh_role_index = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(arena, 0, &_d); }), .neg_done = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .pos_done = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); })});
        return p;
    }
}

int64_t naming_fresh_id(slop_arena* arena, naming_Registry* p, slop_string text) {
    __auto_type _mv_181 = ({ void* _ptr = slop_map_get((*p).fresh_index, &(text)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
    if (_mv_181.has_value) {
        __auto_type id = _mv_181.value;
        return ((int64_t)(id));
    } else if (!_mv_181.has_value) {
        {
            __auto_type s = (*p);
            __auto_type id = ((int64_t)(SLOP_RANGE(int64_t, ((int64_t)(((*p).fresh).len)), 1, 0, 0, 0, "(Int 0 ..) at naming.slop:72:36")));
            ({ __auto_type _lst_p = &(s.fresh); __auto_type _item = (text); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ int64_t _val = SLOP_RANGE(int64_t, id, 1, 0, 0, 0, "(Int 0 ..) at naming.slop:75:45"); slop_map_put(NULL, s.fresh_index, &(text), &_val, sizeof(_val)); });
            (*p) = s;
            return SLOP_RANGE(int64_t, id, 1, 0, 0, 0, "(Int 0 ..) at naming.slop:77:13");
        }
    }
    SLOP_UNREACHABLE();
}

int64_t naming_fresh_role_id(slop_arena* arena, naming_Registry* p, slop_string text) {
    __auto_type _mv_184 = ({ void* _ptr = slop_map_get((*p).fresh_role_index, &(text)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; });
    if (_mv_184.has_value) {
        __auto_type id = _mv_184.value;
        return ((int64_t)(id));
    } else if (!_mv_184.has_value) {
        {
            __auto_type s = (*p);
            __auto_type id = ((int64_t)(SLOP_RANGE(int64_t, ((int64_t)(((*p).fresh_roles).len)), 1, 0, 0, 0, "(Int 0 ..) at naming.slop:87:36")));
            ({ __auto_type _lst_p = &(s.fresh_roles); __auto_type _item = (text); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ int64_t _val = SLOP_RANGE(int64_t, id, 1, 0, 0, 0, "(Int 0 ..) at naming.slop:90:50"); slop_map_put(NULL, s.fresh_role_index, &(text), &_val, sizeof(_val)); });
            (*p) = s;
            return SLOP_RANGE(int64_t, id, 1, 0, 0, 0, "(Int 0 ..) at naming.slop:92:13");
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t naming_mark_neg(slop_arena* arena, naming_Registry* p, slop_string text) {
    ({ slop_map_put(NULL, (*p).neg_done, &(text), NULL, 0); });
    return 1;
}

uint8_t naming_mark_pos(slop_arena* arena, naming_Registry* p, slop_string text) {
    ({ slop_map_put(NULL, (*p).pos_done, &(text), NULL, 0); });
    return 1;
}

uint8_t naming_neg_defined(naming_Registry* p, slop_string text) {
    return slop_map_has((*p).neg_done, &(text));
}

uint8_t naming_pos_defined(naming_Registry* p, slop_string text) {
    return slop_map_has((*p).pos_done, &(text));
}

int64_t naming_fresh_count(naming_Registry* p) {
    return ((int64_t)(((int64_t)(((*p).fresh).len))));
}

int64_t naming_fresh_role_count(naming_Registry* p) {
    return ((int64_t)(((int64_t)(((*p).fresh_roles).len))));
}

slop_list_owl2_RawConcept naming_flatten_and(slop_arena* arena, owl2_RawConcept c, slop_list_owl2_RawConcept acc) {
    {
        __auto_type out = acc;
        __auto_type _mv_190 = c;
        switch (_mv_190.tag) {
            case owl2_RawConcept_rc_and:
            {
                __auto_type cs = _mv_190.data.rc_and;
                {
                    __auto_type _coll = cs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        out = naming_flatten_and(arena, x, out);
                    }
                }
                break;
            }
            case owl2_RawConcept_rc_thing:
            {
                break;
            }
            default: {
                ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                break;
            }
        }
        return out;
    }
}

slop_string naming_concept_key(slop_arena* arena, owl2_RawConcept c) {
    __auto_type _mv_191 = c;
    switch (_mv_191.tag) {
        case owl2_RawConcept_rc_thing:
        {
            return SLOP_STR("⊤");
        }
        case owl2_RawConcept_rc_nothing:
        {
            return SLOP_STR("⊥");
        }
        case owl2_RawConcept_rc_name:
        {
            __auto_type n = _mv_191.data.rc_name;
            return naming_node_key(arena, n);
        }
        case owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_191.data.rc_and;
            {
                __auto_type out = SLOP_STR("and(");
                uint8_t first = 1;
                {
                    __auto_type _coll = cs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        if (!(first)) {
                            out = string_concat(arena, out, SLOP_STR(" "));
                        }
                        out = string_concat(arena, out, naming_concept_key(arena, x));
                        first = 0;
                    }
                }
                return string_concat(arena, out, SLOP_STR(")"));
            }
        }
        case owl2_RawConcept_rc_some:
        {
            __auto_type r = _mv_191.data.rc_some.f0;
            __auto_type f = _mv_191.data.rc_some.f1;
            return string_concat(arena, SLOP_STR("some("), string_concat(arena, naming_role_key(arena, r), string_concat(arena, SLOP_STR(" "), string_concat(arena, naming_concept_key(arena, (*f)), SLOP_STR(")")))));
        }
        case owl2_RawConcept_rc_oneof:
        {
            __auto_type ns = _mv_191.data.rc_oneof;
            if (((int64_t)((ns).len)) == 1) {
                return naming_node_key(arena, naming_node_at(ns, 0));
            } else {
                return string_concat(arena, SLOP_STR("!"), owl2_render_concept(arena, c));
            }
        }
        case owl2_RawConcept_rc_has_value:
        {
            __auto_type r = _mv_191.data.rc_has_value.f0;
            __auto_type a = _mv_191.data.rc_has_value.f1;
            return string_concat(arena, SLOP_STR("some("), string_concat(arena, naming_role_key(arena, r), string_concat(arena, SLOP_STR(" "), string_concat(arena, naming_node_key(arena, a), SLOP_STR(")")))));
        }
        case owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_191.data.rc_has_self;
            return string_concat(arena, SLOP_STR("self("), string_concat(arena, naming_role_key(arena, r), SLOP_STR(")")));
        }
        default: {
            return string_concat(arena, SLOP_STR("!"), owl2_render_concept(arena, c));
        }
    }
}

types_Node naming_node_at(slop_list_types_Node xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_192 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_Node _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_192.has_value) {
        __auto_type v = _mv_192.value;
        return v;
    } else if (!_mv_192.has_value) {
        return ((types_Node){ .tag = types_Node_class_node, .data.class_node = ((rdf_IRI){.value = SLOP_STR("")}) });
    }
    SLOP_UNREACHABLE();
}

slop_string naming_node_key(slop_arena* arena, types_Node n) {
    __auto_type _mv_193 = n;
    switch (_mv_193.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_193.data.class_node;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">")));
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_193.data.individual_node;
            return string_concat(arena, SLOP_STR("{<"), string_concat(arena, i.value, SLOP_STR(">}")));
        }
        case types_Node_fresh_node:
        {
            __auto_type k = _mv_193.data.fresh_node;
            return string_concat(arena, SLOP_STR("_:"), int_to_string(arena, k));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string naming_role_key(slop_arena* arena, types_RoleId r) {
    __auto_type _mv_194 = r;
    switch (_mv_194.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_194.data.named_role;
            return string_concat(arena, SLOP_STR("<"), string_concat(arena, i.value, SLOP_STR(">")));
        }
        case types_RoleId_fresh_role:
        {
            __auto_type k = _mv_194.data.fresh_role;
            return string_concat(arena, SLOP_STR("_:r"), int_to_string(arena, k));
        }
        case types_RoleId_inverse_role:
        {
            __auto_type i = _mv_194.data.inverse_role;
            return string_concat(arena, SLOP_STR("^<"), string_concat(arena, i.value, SLOP_STR(">")));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string naming_prefix_text(slop_arena* arena, slop_list_owl2_RawConcept conj, int64_t upto) {
    {
        __auto_type pre = ((slop_list_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < upto) {
            ({ __auto_type _lst_p = &(pre); __auto_type _item = (owl2_concept_at(conj, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            i = (i + 1);
        }
        return naming_concept_key(arena, ((owl2_RawConcept){ .tag = owl2_RawConcept_rc_and, .data.rc_and = pre }));
    }
}

types_RoleId naming_role_at_n(slop_list_types_RoleId xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_195 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_195.has_value) {
        __auto_type v = _mv_195.value;
        return v;
    } else if (!_mv_195.has_value) {
        return ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_string naming_prefix_role_text(slop_arena* arena, slop_list_types_RoleId steps, int64_t upto, types_RoleId super) {
    {
        __auto_type out = string_concat(arena, SLOP_STR("chain "), naming_render_role_name(arena, super));
        int64_t i = 0;
        while (i < upto) {
            out = string_concat(arena, out, string_concat(arena, SLOP_STR(" "), naming_render_role_name(arena, naming_role_at_n(steps, i))));
            i = (i + 1);
        }
        return out;
    }
}

slop_string naming_render_role_name(slop_arena* arena, types_RoleId r) {
    __auto_type _mv_196 = r;
    switch (_mv_196.tag) {
        case types_RoleId_named_role:
        {
            __auto_type i = _mv_196.data.named_role;
            return i.value;
        }
        case types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_196.data.fresh_role;
            return SLOP_STR("_:fresh");
        }
        case types_RoleId_inverse_role:
        {
            __auto_type i = _mv_196.data.inverse_role;
            return string_concat(arena, SLOP_STR("^"), i.value);
        }
    }
    SLOP_UNREACHABLE();
}

