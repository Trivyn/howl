#include "../runtime/slop_runtime.h"
#include "slop_kscsat.h"

kscsat_KStore kscsat_new_store(slop_arena* arena);
uint8_t kscsat_fl_push(slop_arena* arena, slop_map* m, types_KElem k, types_KFact f);
uint8_t kscsat_rf_push(slop_arena* arena, slop_map* m, types_KElem k, types_RoleId v, types_KFact f);
types_KElem kscsat_fact_subject(types_KFact f);
uint8_t kscsat_is_safe(kscsat_Base b, types_KElem x);
uint8_t kscsat_store_holds(kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f);
uint8_t kscsat_commit(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f);
slop_list_types_KFact kscsat_fl_items(slop_arena* arena, slop_map* m, types_KElem k);
slop_list_types_KFact kscsat_rf_items(slop_arena* arena, slop_map* m, types_KElem k, types_RoleId v);
slop_map* kscsat_field_map(kscsat_KStore st, kscsat_Field fd);
uint8_t kscsat_keyed_by_subject(kscsat_Field fd);
slop_list_types_KFact kscsat_safe_facts(slop_arena* arena, kscsat_Base b, slop_list_types_KFact xs);
slop_list_types_KFact kscsat_w_items(slop_arena* arena, kscsat_Base b, uint8_t by_subject, types_KElem k, slop_list_types_KFact xs);
slop_list_list_types_KFact kscsat_partners(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, kscsat_Field fd, types_KElem k);
slop_list_list_types_KFact kscsat_role_partners(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, uint8_t outward, types_KElem k, types_RoleId v);
slop_list_types_KFact kscsat_derive(slop_arena* arena, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f);
types_RoleId kscsat_ksc_dummy_role(void);
uint8_t kscsat_is_bottom_fact(types_KFact f);
uint8_t kscsat_reaches_bottom(slop_option_kscsat_Base base, types_KFact f);
kscsat_RunResult kscsat_run_ksc(slop_arena* arena, kscpremise_KscIndex idx, slop_option_kscsat_Base base, slop_list_types_KFact seeds, uint8_t stop_at_bottom);
slop_list_types_KName kscsat_answer_subsumers(slop_arena* arena, kscsat_KStore st, types_KName q);
types_KName kscsat_copy_kname(slop_arena* arena, types_KName n);
slop_map* kscsat_backward_closure(slop_arena* arena, kscsat_KStore w, slop_list_types_KElem start);
kscsat_ClassAnswer kscsat_class_run(slop_arena* arena, kscpremise_KscIndex idx, kscsat_Base base, uint8_t g_unsat, types_KName q);
kscsat_ClassAnswer kscsat_shared_answer(slop_arena* arena, kscsat_Base base, uint8_t g_unsat, types_KName q);
kscsat_ClassAnswer kscsat_class_answer(slop_arena* arena, kscpremise_KscIndex idx, kscsat_Base base, uint8_t g_unsat, types_KName q);
kscsat_KscResult kscsat_ksc_classify(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes);
uint8_t kscsat_answer_holds(kscsat_ClassAnswer a, types_KName b);
slop_list_types_KName kscsat_input_classes(slop_arena* arena, owl2_Signature sig);

kscsat_KStore kscsat_new_store(slop_arena* arena) {
    return ((kscsat_KStore){.seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_KFact, slop_hash_types_KFact, slop_eq_types_KFact, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .insts = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED, kscsat_FactList); slop_map_new_ptr(arena, 0, &_d); }), .noms = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED, kscsat_FactList); slop_map_new_ptr(arena, 0, &_d); }), .holders = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED, kscsat_FactList); slop_map_new_ptr(arena, 0, &_d); }), .outs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED, kscsat_RoleFacts); slop_map_new_ptr(arena, 0, &_d); }), .ins = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED, kscsat_RoleFacts); slop_map_new_ptr(arena, 0, &_d); }), .ins_all = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED, kscsat_FactList); slop_map_new_ptr(arena, 0, &_d); }), .noms_at = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .bots = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); })});
}

uint8_t kscsat_fl_push(slop_arena* arena, slop_map* m, types_KElem k, types_KFact f) {
    {
        __auto_type items = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(m, &(k)); _ptr ? (slop_option_kscsat_FactList){ .has_value = true, .value = *(kscsat_FactList*)_ptr } : (slop_option_kscsat_FactList){ .has_value = false }; }); _mv.has_value ? ({ __auto_type l = _mv.value; l.items; }) : (((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 })); });
        ({ __auto_type _lst_p = &(items); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ kscsat_FactList _val = ((kscsat_FactList){.items = items}); slop_map_put(arena, m, &(k), &_val, sizeof(_val)); });
        return 1;
    }
}

uint8_t kscsat_rf_push(slop_arena* arena, slop_map* m, types_KElem k, types_RoleId v, types_KFact f) {
    {
        __auto_type rf = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(m, &(k)); _ptr ? (slop_option_kscsat_RoleFacts){ .has_value = true, .value = *(kscsat_RoleFacts*)_ptr } : (slop_option_kscsat_RoleFacts){ .has_value = false }; }); _mv.has_value ? ({ __auto_type r = _mv.value; r; }) : (({ __auto_type fresh = ((kscsat_RoleFacts){.by_role = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_RoleId, slop_hash_types_RoleId, slop_eq_types_RoleId, SLOP_KEY_HASHED, kscsat_FactList); slop_map_new_ptr(arena, 0, &_d); })}); ({ ({ kscsat_RoleFacts _val = fresh; slop_map_put(arena, m, &(k), &_val, sizeof(_val)); }); fresh; }); })); });
        __auto_type items = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(rf.by_role, &(v)); _ptr ? (slop_option_kscsat_FactList){ .has_value = true, .value = *(kscsat_FactList*)_ptr } : (slop_option_kscsat_FactList){ .has_value = false }; }); _mv.has_value ? ({ __auto_type l = _mv.value; l.items; }) : (((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 })); });
        ({ __auto_type _lst_p = &(items); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ kscsat_FactList _val = ((kscsat_FactList){.items = items}); slop_map_put(arena, rf.by_role, &(v), &_val, sizeof(_val)); });
        return 1;
    }
}

types_KElem kscsat_fact_subject(types_KFact f) {
    __auto_type _mv_741 = f;
    switch (_mv_741.tag) {
        case types_KFact_f_inst:
        {
            __auto_type x = _mv_741.data.f_inst.f0;
            return x;
        }
        case types_KFact_f_triple:
        {
            __auto_type x = _mv_741.data.f_triple.f0;
            return x;
        }
        case types_KFact_f_self:
        {
            __auto_type x = _mv_741.data.f_self.f0;
            return x;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t kscsat_is_safe(kscsat_Base b, types_KElem x) {
    return !(slop_map_has(b.unsafe, &(x)));
}

uint8_t kscsat_store_holds(kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f) {
    if (slop_map_has(st.seen, &(f))) {
        return 1;
    } else {
        __auto_type _mv_744 = base;
        if (_mv_744.has_value) {
            __auto_type b = _mv_744.value;
            if (slop_map_has(b.g.seen, &(f))) {
                return 1;
            } else {
                if (kscsat_is_safe(b, kscsat_fact_subject(f))) {
                    return slop_map_has(b.w.seen, &(f));
                } else {
                    return 0;
                }
            }
        } else if (!_mv_744.has_value) {
            return 0;
        }
        SLOP_UNREACHABLE();
    }
}

uint8_t kscsat_commit(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f) {
    if (kscsat_store_holds(st, base, f)) {
        return 0;
    } else {
        ({ slop_map_put(arena, st.seen, &(f), NULL, 0); });
        __auto_type _mv_748 = f;
        switch (_mv_748.tag) {
            case types_KFact_f_inst:
            {
                __auto_type x = _mv_748.data.f_inst.f0;
                __auto_type y = _mv_748.data.f_inst.f1;
                kscsat_fl_push(arena, st.insts, x, f);
                if (ksc_ksc_4(x, y)) {
                    ({ slop_map_put(arena, st.bots, &(x), NULL, 0); });
                }
                if (ksc_is_nominal(y)) {
                    ({ slop_map_put(arena, st.noms_at, &(x), NULL, 0); });
                    kscsat_fl_push(arena, st.noms, x, f);
                    kscsat_fl_push(arena, st.holders, ksc_term_elem(y), f);
                }
                break;
            }
            case types_KFact_f_triple:
            {
                __auto_type x = _mv_748.data.f_triple.f0;
                __auto_type v = _mv_748.data.f_triple.f1;
                __auto_type x1 = _mv_748.data.f_triple.f2;
                kscsat_rf_push(arena, st.outs, x, v, f);
                kscsat_rf_push(arena, st.ins, x1, v, f);
                kscsat_fl_push(arena, st.ins_all, x1, f);
                break;
            }
            case types_KFact_f_self:
            {
                break;
            }
        }
        return 1;
    }
}

slop_list_types_KFact kscsat_fl_items(slop_arena* arena, slop_map* m, types_KElem k) {
    __auto_type _mv_752 = ({ void* _ptr = slop_map_get(m, &(k)); _ptr ? (slop_option_kscsat_FactList){ .has_value = true, .value = *(kscsat_FactList*)_ptr } : (slop_option_kscsat_FactList){ .has_value = false }; });
    if (_mv_752.has_value) {
        __auto_type l = _mv_752.value;
        return l.items;
    } else if (!_mv_752.has_value) {
        return ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_list_types_KFact kscsat_rf_items(slop_arena* arena, slop_map* m, types_KElem k, types_RoleId v) {
    __auto_type _mv_754 = ({ void* _ptr = slop_map_get(m, &(k)); _ptr ? (slop_option_kscsat_RoleFacts){ .has_value = true, .value = *(kscsat_RoleFacts*)_ptr } : (slop_option_kscsat_RoleFacts){ .has_value = false }; });
    if (_mv_754.has_value) {
        __auto_type rf = _mv_754.value;
        __auto_type _mv_756 = ({ void* _ptr = slop_map_get(rf.by_role, &(v)); _ptr ? (slop_option_kscsat_FactList){ .has_value = true, .value = *(kscsat_FactList*)_ptr } : (slop_option_kscsat_FactList){ .has_value = false }; });
        if (_mv_756.has_value) {
            __auto_type l = _mv_756.value;
            return l.items;
        } else if (!_mv_756.has_value) {
            return ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_754.has_value) {
        return ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_map* kscsat_field_map(kscsat_KStore st, kscsat_Field fd) {
    __auto_type _mv_757 = fd;
    if (_mv_757 == kscsat_Field_fd_insts) {
        return st.insts;
    } else if (_mv_757 == kscsat_Field_fd_noms) {
        return st.noms;
    } else if (_mv_757 == kscsat_Field_fd_holders) {
        return st.holders;
    } else if (_mv_757 == kscsat_Field_fd_ins_all) {
        return st.ins_all;
    }
    SLOP_UNREACHABLE();
}

uint8_t kscsat_keyed_by_subject(kscsat_Field fd) {
    __auto_type _mv_758 = fd;
    if (_mv_758 == kscsat_Field_fd_insts) {
        return 1;
    } else if (_mv_758 == kscsat_Field_fd_noms) {
        return 1;
    } else if (_mv_758 == kscsat_Field_fd_holders) {
        return 0;
    } else if (_mv_758 == kscsat_Field_fd_ins_all) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_list_types_KFact kscsat_safe_facts(slop_arena* arena, kscsat_Base b, slop_list_types_KFact xs) {
    {
        __auto_type out = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                if (kscsat_is_safe(b, kscsat_fact_subject(f))) {
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        return out;
    }
}

slop_list_types_KFact kscsat_w_items(slop_arena* arena, kscsat_Base b, uint8_t by_subject, types_KElem k, slop_list_types_KFact xs) {
    if (kscsat_is_safe(b, k)) {
        if (by_subject) {
            return xs;
        } else {
            return kscsat_safe_facts(arena, b, xs);
        }
    } else {
        return ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
    }
}

slop_list_list_types_KFact kscsat_partners(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, kscsat_Field fd, types_KElem k) {
    {
        __auto_type out = ((slop_list_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_759 = base;
        if (_mv_759.has_value) {
            __auto_type b = _mv_759.value;
            ({ __auto_type _lst_p = &(out); __auto_type _item = (kscsat_fl_items(arena, kscsat_field_map(b.g, fd), k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (kscsat_w_items(arena, b, kscsat_keyed_by_subject(fd), k, kscsat_fl_items(arena, kscsat_field_map(b.w, fd), k))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (!_mv_759.has_value) {
        }
        ({ __auto_type _lst_p = &(out); __auto_type _item = (kscsat_fl_items(arena, kscsat_field_map(st, fd), k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

slop_list_list_types_KFact kscsat_role_partners(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, uint8_t outward, types_KElem k, types_RoleId v) {
    {
        __auto_type out = ((slop_list_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_760 = base;
        if (_mv_760.has_value) {
            __auto_type b = _mv_760.value;
            ({ __auto_type _lst_p = &(out); __auto_type _item = (kscsat_rf_items(arena, ((outward) ? b.g.outs : b.g.ins), k, v)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (kscsat_w_items(arena, b, outward, k, kscsat_rf_items(arena, ((outward) ? b.w.outs : b.w.ins), k, v))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (!_mv_760.has_value) {
        }
        ({ __auto_type _lst_p = &(out); __auto_type _item = (kscsat_rf_items(arena, ((outward) ? st.outs : st.ins), k, v)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

slop_list_types_KFact kscsat_derive(slop_arena* arena, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f) {
    {
        __auto_type out = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_761 = f;
        switch (_mv_761.tag) {
            case types_KFact_f_inst:
            {
                __auto_type x = _mv_761.data.f_inst.f0;
                __auto_type y = _mv_761.data.f_inst.f1;
                {
                    __auto_type c = ksc_ksc_3(x, y);
                    if (c.fires) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                __auto_type _mv_762 = kscpremise_term_bucket(idx, y);
                if (_mv_762.has_value) {
                    __auto_type bucket = _mv_762.value;
                    {
                        __auto_type _coll = bucket.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ax = _coll.data[_i];
                            __auto_type _mv_763 = ax;
                            switch (_mv_763.tag) {
                                case types_KscAxiom_k_sub:
                                {
                                    __auto_type sy = _mv_763.data.k_sub.f0;
                                    __auto_type sz = _mv_763.data.k_sub.f1;
                                    {
                                        __auto_type c = ksc_ksc_5(sy, sz, x, y);
                                        if (c.fires) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                    break;
                                }
                                case types_KscAxiom_k_and:
                                {
                                    __auto_type a = _mv_763.data.k_and.f0;
                                    __auto_type b = _mv_763.data.k_and.f1;
                                    __auto_type z = _mv_763.data.k_and.f2;
                                    if (ksc_is_name(y, a)) {
                                        if (kscsat_store_holds(st, base, ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = types_name_term(b) } }))) {
                                            {
                                                __auto_type c = ksc_ksc_6(a, b, z, x, y, x, types_name_term(b));
                                                if (c.fires) {
                                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            }
                                        }
                                    }
                                    if (ksc_is_name(y, b)) {
                                        if (kscsat_store_holds(st, base, ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = types_name_term(a) } }))) {
                                            {
                                                __auto_type c = ksc_ksc_6(a, b, z, x, types_name_term(a), x, y);
                                                if (c.fires) {
                                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                                case types_KscAxiom_k_some_lhs:
                                {
                                    __auto_type v = _mv_763.data.k_some_lhs.f0;
                                    __auto_type a = _mv_763.data.k_some_lhs.f1;
                                    __auto_type z = _mv_763.data.k_some_lhs.f2;
                                    {
                                        __auto_type _coll = kscsat_role_partners(arena, st, base, 0, x, v);
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type ps = _coll.data[_i];
                                            {
                                                __auto_type _coll = ksc_join(arena, ksc_JoinRule_j7_inst, f, ps, ax);
                                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                                    __auto_type g = _coll.data[_i];
                                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            }
                                        }
                                    }
                                    if (kscsat_store_holds(st, base, ((types_KFact){ .tag = types_KFact_f_self, .data.f_self = { .f0 = x, .f1 = v } }))) {
                                        {
                                            __auto_type c = ksc_ksc_8(v, a, z, x, v, x, y);
                                            if (c.fires) {
                                                ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                    }
                                    break;
                                }
                                case types_KscAxiom_k_some_rhs:
                                {
                                    __auto_type a = _mv_763.data.k_some_rhs.f0;
                                    __auto_type v = _mv_763.data.k_some_rhs.f1;
                                    __auto_type b = _mv_763.data.k_some_rhs.f2;
                                    __auto_type w = _mv_763.data.k_some_rhs.f3;
                                    {
                                        __auto_type c = ksc_ksc_9(a, v, b, w, x, y);
                                        if (c.fires) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                    {
                                        __auto_type c = ksc_ksc_10(a, v, b, w, x, y);
                                        if (c.fires) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                    break;
                                }
                                case types_KscAxiom_k_role_assert:
                                {
                                    __auto_type a = _mv_763.data.k_role_assert.f0;
                                    __auto_type v = _mv_763.data.k_role_assert.f1;
                                    __auto_type b = _mv_763.data.k_role_assert.f2;
                                    {
                                        __auto_type c = ksc_ksc_9_assert(a, v, b, x, y);
                                        if (c.fires) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                    {
                                        __auto_type c = ksc_ksc_10_assert(a, v, b, x, y);
                                        if (c.fires) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                    break;
                                }
                                case types_KscAxiom_k_self_rhs:
                                {
                                    __auto_type a = _mv_763.data.k_self_rhs.f0;
                                    __auto_type v = _mv_763.data.k_self_rhs.f1;
                                    {
                                        __auto_type c = ksc_ksc_12(a, v, x, y);
                                        if (c.fires) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                    break;
                                }
                                case types_KscAxiom_k_self_lhs:
                                {
                                    break;
                                }
                                case types_KscAxiom_k_role:
                                {
                                    break;
                                }
                                case types_KscAxiom_k_chain:
                                {
                                    break;
                                }
                                case types_KscAxiom_k_range:
                                {
                                    break;
                                }
                            }
                        }
                    }
                } else if (!_mv_762.has_value) {
                }
                {
                    __auto_type noax = ((types_KscAxiom){ .tag = types_KscAxiom_k_role, .data.k_role = { .f0 = kscsat_ksc_dummy_role(), .f1 = kscsat_ksc_dummy_role() } });
                    if (ksc_is_nominal(y)) {
                        {
                            __auto_type _coll = kscsat_partners(arena, st, base, kscsat_Field_fd_insts, x);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ps = _coll.data[_i];
                                {
                                    __auto_type _coll = ksc_join(arena, ksc_JoinRule_j27_nom, f, ps, noax);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type g = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                        {
                            __auto_type _coll = kscsat_partners(arena, st, base, kscsat_Field_fd_insts, ksc_term_elem(y));
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ps = _coll.data[_i];
                                {
                                    __auto_type _coll = ksc_join(arena, ksc_JoinRule_j28_nom, f, ps, noax);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type g = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                        {
                            __auto_type _coll = kscsat_partners(arena, st, base, kscsat_Field_fd_ins_all, x);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ps = _coll.data[_i];
                                {
                                    __auto_type _coll = ksc_join(arena, ksc_JoinRule_j29_nom, f, ps, noax);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type g = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                    {
                        __auto_type _coll = kscsat_partners(arena, st, base, kscsat_Field_fd_noms, x);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ps = _coll.data[_i];
                            {
                                __auto_type _coll = ksc_join(arena, ksc_JoinRule_j27_other, f, ps, noax);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type g = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                    if (ksc_is_individual(x)) {
                        {
                            __auto_type _coll = kscsat_partners(arena, st, base, kscsat_Field_fd_holders, x);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ps = _coll.data[_i];
                                {
                                    __auto_type _coll = ksc_join(arena, ksc_JoinRule_j28_ind, f, ps, noax);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type g = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case types_KFact_f_triple:
            {
                __auto_type x = _mv_761.data.f_triple.f0;
                __auto_type v = _mv_761.data.f_triple.f1;
                __auto_type x1 = _mv_761.data.f_triple.f2;
                {
                    __auto_type c = ksc_ksc_2(x, v, x1);
                    if (c.fires) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                __auto_type _mv_764 = kscpremise_role_bucket(idx, v);
                if (_mv_764.has_value) {
                    __auto_type bucket = _mv_764.value;
                    {
                        __auto_type _coll = bucket.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ax = _coll.data[_i];
                            __auto_type _mv_765 = ax;
                            switch (_mv_765.tag) {
                                case types_KscAxiom_k_some_lhs:
                                {
                                    __auto_type v2 = _mv_765.data.k_some_lhs.f0;
                                    __auto_type a = _mv_765.data.k_some_lhs.f1;
                                    __auto_type z = _mv_765.data.k_some_lhs.f2;
                                    if (kscsat_store_holds(st, base, ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x1, .f1 = types_name_term(a) } }))) {
                                        {
                                            __auto_type c = ksc_ksc_7(v2, a, z, x, v, x1, x1, types_name_term(a));
                                            if (c.fires) {
                                                ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                    }
                                    break;
                                }
                                case types_KscAxiom_k_role:
                                {
                                    __auto_type v2 = _mv_765.data.k_role.f0;
                                    __auto_type w = _mv_765.data.k_role.f1;
                                    {
                                        __auto_type c = ksc_ksc_13(v2, w, x, v, x1);
                                        if (c.fires) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                    break;
                                }
                                case types_KscAxiom_k_chain:
                                {
                                    __auto_type u = _mv_765.data.k_chain.f0;
                                    __auto_type v2 = _mv_765.data.k_chain.f1;
                                    __auto_type w = _mv_765.data.k_chain.f2;
                                    if (types_role_eq(u, v)) {
                                        {
                                            __auto_type _coll = kscsat_role_partners(arena, st, base, 1, x1, v2);
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type ps = _coll.data[_i];
                                                {
                                                    __auto_type _coll = ksc_join(arena, ksc_JoinRule_j15_first, f, ps, ax);
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type g = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                            }
                                        }
                                        if (kscsat_store_holds(st, base, ((types_KFact){ .tag = types_KFact_f_self, .data.f_self = { .f0 = x1, .f1 = v2 } }))) {
                                            {
                                                __auto_type c = ksc_ksc_17(u, v2, w, x, v, x1, x1, v2);
                                                if (c.fires) {
                                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            }
                                        }
                                    }
                                    if (types_role_eq(v2, v)) {
                                        {
                                            __auto_type _coll = kscsat_role_partners(arena, st, base, 0, x, u);
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type ps = _coll.data[_i];
                                                {
                                                    __auto_type _coll = ksc_join(arena, ksc_JoinRule_j15_second, f, ps, ax);
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type g = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                            }
                                        }
                                        if (kscsat_store_holds(st, base, ((types_KFact){ .tag = types_KFact_f_self, .data.f_self = { .f0 = x, .f1 = u } }))) {
                                            {
                                                __auto_type c = ksc_ksc_16(u, v2, w, x, u, x, v, x1);
                                                if (c.fires) {
                                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                                case types_KscAxiom_k_range:
                                {
                                    __auto_type v2 = _mv_765.data.k_range.f0;
                                    __auto_type d = _mv_765.data.k_range.f1;
                                    {
                                        __auto_type c = ksc_ksc_23(v2, d, x, v, x1);
                                        if (c.fires) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                    {
                                        __auto_type c = ksc_ksc_25(v2, d, x, v, x1);
                                        if (c.fires) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                    break;
                                }
                                case types_KscAxiom_k_sub:
                                {
                                    break;
                                }
                                case types_KscAxiom_k_and:
                                {
                                    break;
                                }
                                case types_KscAxiom_k_some_rhs:
                                {
                                    break;
                                }
                                case types_KscAxiom_k_self_lhs:
                                {
                                    break;
                                }
                                case types_KscAxiom_k_self_rhs:
                                {
                                    break;
                                }
                                case types_KscAxiom_k_role_assert:
                                {
                                    break;
                                }
                            }
                        }
                    }
                } else if (!_mv_764.has_value) {
                }
                {
                    __auto_type noax = ((types_KscAxiom){ .tag = types_KscAxiom_k_role, .data.k_role = { .f0 = kscsat_ksc_dummy_role(), .f1 = kscsat_ksc_dummy_role() } });
                    {
                        __auto_type _coll = kscsat_partners(arena, st, base, kscsat_Field_fd_noms, x1);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ps = _coll.data[_i];
                            {
                                __auto_type _coll = ksc_join(arena, ksc_JoinRule_j29_triple, f, ps, noax);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type g = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                }
                break;
            }
            case types_KFact_f_self:
            {
                __auto_type x = _mv_761.data.f_self.f0;
                __auto_type v = _mv_761.data.f_self.f1;
                __auto_type _mv_766 = kscpremise_role_bucket(idx, v);
                if (_mv_766.has_value) {
                    __auto_type bucket = _mv_766.value;
                    {
                        __auto_type _coll = bucket.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ax = _coll.data[_i];
                            __auto_type _mv_767 = ax;
                            switch (_mv_767.tag) {
                                case types_KscAxiom_k_some_lhs:
                                {
                                    __auto_type v2 = _mv_767.data.k_some_lhs.f0;
                                    __auto_type a = _mv_767.data.k_some_lhs.f1;
                                    __auto_type z = _mv_767.data.k_some_lhs.f2;
                                    if (kscsat_store_holds(st, base, ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = types_name_term(a) } }))) {
                                        {
                                            __auto_type c = ksc_ksc_8(v2, a, z, x, v, x, types_name_term(a));
                                            if (c.fires) {
                                                ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                    }
                                    break;
                                }
                                case types_KscAxiom_k_self_lhs:
                                {
                                    __auto_type v2 = _mv_767.data.k_self_lhs.f0;
                                    __auto_type z = _mv_767.data.k_self_lhs.f1;
                                    {
                                        __auto_type c = ksc_ksc_11(v2, z, x, v);
                                        if (c.fires) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                    break;
                                }
                                case types_KscAxiom_k_role:
                                {
                                    __auto_type v2 = _mv_767.data.k_role.f0;
                                    __auto_type w = _mv_767.data.k_role.f1;
                                    {
                                        __auto_type c = ksc_ksc_14(v2, w, x, v);
                                        if (c.fires) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                    break;
                                }
                                case types_KscAxiom_k_chain:
                                {
                                    __auto_type u = _mv_767.data.k_chain.f0;
                                    __auto_type v2 = _mv_767.data.k_chain.f1;
                                    __auto_type w = _mv_767.data.k_chain.f2;
                                    if (types_role_eq(u, v)) {
                                        {
                                            __auto_type _coll = kscsat_role_partners(arena, st, base, 1, x, v2);
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type ps = _coll.data[_i];
                                                {
                                                    __auto_type _coll = ksc_join(arena, ksc_JoinRule_j16_self, f, ps, ax);
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type g = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                            }
                                        }
                                        if (kscsat_store_holds(st, base, ((types_KFact){ .tag = types_KFact_f_self, .data.f_self = { .f0 = x, .f1 = v2 } }))) {
                                            {
                                                __auto_type c = ksc_ksc_18(u, v2, w, x, v, x, v2);
                                                if (c.fires) {
                                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            }
                                        }
                                    }
                                    if (types_role_eq(v2, v)) {
                                        {
                                            __auto_type _coll = kscsat_role_partners(arena, st, base, 0, x, u);
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type ps = _coll.data[_i];
                                                {
                                                    __auto_type _coll = ksc_join(arena, ksc_JoinRule_j17_self, f, ps, ax);
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type g = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
                                                }
                                            }
                                        }
                                        if (kscsat_store_holds(st, base, ((types_KFact){ .tag = types_KFact_f_self, .data.f_self = { .f0 = x, .f1 = u } }))) {
                                            {
                                                __auto_type c = ksc_ksc_18(u, v2, w, x, u, x, v);
                                                if (c.fires) {
                                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                                case types_KscAxiom_k_range:
                                {
                                    __auto_type v2 = _mv_767.data.k_range.f0;
                                    __auto_type d = _mv_767.data.k_range.f1;
                                    {
                                        __auto_type c = ksc_ksc_24(v2, d, x, v);
                                        if (c.fires) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                    {
                                        __auto_type c = ksc_ksc_26(v2, d, x, v);
                                        if (c.fires) {
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                    break;
                                }
                                case types_KscAxiom_k_sub:
                                {
                                    break;
                                }
                                case types_KscAxiom_k_and:
                                {
                                    break;
                                }
                                case types_KscAxiom_k_some_rhs:
                                {
                                    break;
                                }
                                case types_KscAxiom_k_self_rhs:
                                {
                                    break;
                                }
                                case types_KscAxiom_k_role_assert:
                                {
                                    break;
                                }
                            }
                        }
                    }
                } else if (!_mv_766.has_value) {
                }
                break;
            }
        }
        return out;
    }
}

types_RoleId kscsat_ksc_dummy_role(void) {
    return ((types_RoleId){ .tag = types_RoleId_fresh_role, .data.fresh_role = 0 });
}

uint8_t kscsat_is_bottom_fact(types_KFact f) {
    __auto_type _mv_768 = f;
    switch (_mv_768.tag) {
        case types_KFact_f_inst:
        {
            __auto_type u = _mv_768.data.f_inst.f0;
            __auto_type z = _mv_768.data.f_inst.f1;
            return ksc_ksc_4(u, z);
        }
        case types_KFact_f_triple:
        {
            return 0;
        }
        case types_KFact_f_self:
        {
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t kscsat_reaches_bottom(slop_option_kscsat_Base base, types_KFact f) {
    __auto_type _mv_769 = base;
    if (_mv_769.has_value) {
        __auto_type b = _mv_769.value;
        __auto_type _mv_770 = f;
        switch (_mv_770.tag) {
            case types_KFact_f_triple:
            {
                __auto_type s = _mv_770.data.f_triple.f2;
                if (kscsat_is_safe(b, s)) {
                    return slop_map_has(b.botreach, &(s));
                } else {
                    return 0;
                }
            }
            case types_KFact_f_inst:
            {
                return 0;
            }
            case types_KFact_f_self:
            {
                return 0;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_769.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

kscsat_RunResult kscsat_run_ksc(slop_arena* arena, kscpremise_KscIndex idx, slop_option_kscsat_Base base, slop_list_types_KFact seeds, uint8_t stop_at_bottom) {
    {
        __auto_type st = kscsat_new_store(arena);
        __auto_type delta = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        uint8_t unsat = 0;
        int64_t rounds = 0;
        int64_t facts = 0;
        {
            __auto_type _coll = seeds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                if (kscsat_commit(arena, st, base, s)) {
                    ({ __auto_type _lst_p = &(delta); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    facts = (facts + 1);
                    if (kscsat_is_bottom_fact(s)) {
                        unsat = 1;
                    }
                    if (kscsat_reaches_bottom(base, s)) {
                        unsat = 1;
                    }
                }
            }
        }
        while (((int64_t)((delta).len)) > 0) {
            {
                __auto_type next = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
                {
                    __auto_type _coll = delta;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type f = _coll.data[_i];
                        if (!(((stop_at_bottom) ? unsat : 0))) {
                            {
                                __auto_type _coll = kscsat_derive(arena, idx, st, base, f);
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type c = _coll.data[_i];
                                    if (kscsat_commit(arena, st, base, c)) {
                                        ({ __auto_type _lst_p = &(next); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        facts = (facts + 1);
                                        if (kscsat_is_bottom_fact(c)) {
                                            unsat = 1;
                                        }
                                        if (kscsat_reaches_bottom(base, c)) {
                                            unsat = 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                rounds = (rounds + 1);
                if ((stop_at_bottom) ? unsat : 0) {
                    delta = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
                } else {
                    delta = next;
                }
            }
        }
        return ((kscsat_RunResult){.store = st, .rounds = rounds, .unsat = unsat, .facts = facts});
    }
}

slop_list_types_KName kscsat_answer_subsumers(slop_arena* arena, kscsat_KStore st, types_KName q) {
    {
        __auto_type out = ((slop_list_types_KName){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = kscsat_fl_items(arena, st.insts, types_class_elem(q));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                __auto_type _mv_772 = f;
                switch (_mv_772.tag) {
                    case types_KFact_f_inst:
                    {
                        __auto_type y = _mv_772.data.f_inst.f1;
                        __auto_type _mv_773 = y;
                        switch (_mv_773.tag) {
                            case types_KTerm_k_name:
                            {
                                __auto_type n = _mv_773.data.k_name;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (kscsat_copy_kname(arena, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case types_KTerm_k_nominal:
                            {
                                __auto_type _ = _mv_773.data.k_nominal;
                                break;
                            }
                        }
                        break;
                    }
                    case types_KFact_f_triple:
                    {
                        break;
                    }
                    case types_KFact_f_self:
                    {
                        break;
                    }
                }
            }
        }
        return out;
    }
}

types_KName kscsat_copy_kname(slop_arena* arena, types_KName n) {
    __auto_type _mv_774 = n;
    switch (_mv_774.tag) {
        case types_KName_k_class:
        {
            __auto_type i = _mv_774.data.k_class;
            return ((types_KName){ .tag = types_KName_k_class, .data.k_class = types_copy_iri(arena, i) });
        }
        case types_KName_k_fresh:
        {
            __auto_type k = _mv_774.data.k_fresh;
            return ((types_KName){ .tag = types_KName_k_fresh, .data.k_fresh = k });
        }
    }
    SLOP_UNREACHABLE();
}

slop_map* kscsat_backward_closure(slop_arena* arena, kscsat_KStore w, slop_list_types_KElem start) {
    {
        __auto_type out = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type work = ((slop_list_types_KElem){ .data = NULL, .len = 0, .cap = 0 });
        int64_t i = 0;
        {
            __auto_type _coll = start;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (!(slop_map_has(out, &(x)))) {
                    ({ slop_map_put(arena, out, &(x), NULL, 0); });
                    ({ __auto_type _lst_p = &(work); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        while (i < ((int64_t)(((int64_t)((work).len))))) {
            __auto_type _mv_777 = ({ __auto_type _lst = work; size_t _idx = (size_t)i; slop_option_types_KElem _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_777.has_value) {
                __auto_type x = _mv_777.value;
                {
                    __auto_type _coll = kscsat_fl_items(arena, w.ins_all, x);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type f = _coll.data[_i];
                        {
                            __auto_type p = kscsat_fact_subject(f);
                            if (!(slop_map_has(out, &(p)))) {
                                ({ slop_map_put(arena, out, &(p), NULL, 0); });
                                ({ __auto_type _lst_p = &(work); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                }
            } else if (!_mv_777.has_value) {
            }
            i = (i + 1);
        }
        return out;
    }
}

kscsat_ClassAnswer kscsat_class_run(slop_arena* arena, kscpremise_KscIndex idx, kscsat_Base base, uint8_t g_unsat, types_KName q) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        __auto_type qseeds = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(qseeds); __auto_type _item = (ksc_ksc_q(q).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type r = kscsat_run_ksc(scratch, idx, (slop_option_kscsat_Base){.has_value = 1, .value = base}, qseeds, 1);
            __auto_type ans = ((kscsat_ClassAnswer){.cls = q, .shared = 0, .unsat = ((g_unsat) ? 1 : r.unsat), .subsumers = kscsat_answer_subsumers(arena, r.store, q), .rounds = r.rounds, .facts = r.facts});
            ({ slop_arena_free(scratch); free(scratch); });
            return ans;
        }
    }
}

kscsat_ClassAnswer kscsat_shared_answer(slop_arena* arena, kscsat_Base base, uint8_t g_unsat, types_KName q) {
    return ((kscsat_ClassAnswer){.cls = q, .shared = 1, .unsat = ((g_unsat) ? 1 : ({ types_KElem _key_780 = (types_class_elem(q)); slop_map_has(base.botreach, &_key_780); })), .subsumers = kscsat_answer_subsumers(arena, base.w, q), .rounds = 0, .facts = 0});
}

kscsat_ClassAnswer kscsat_class_answer(slop_arena* arena, kscpremise_KscIndex idx, kscsat_Base base, uint8_t g_unsat, types_KName q) {
    if (kscsat_is_safe(base, types_class_elem(q))) {
        return kscsat_shared_answer(arena, base, g_unsat, q);
    } else {
        return kscsat_class_run(arena, idx, base, g_unsat, q);
    }
}

kscsat_KscResult kscsat_ksc_classify(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes) {
    {
        __auto_type idx = kscpremise_build_ksc_index(arena, axioms);
        __auto_type thing = ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = vocab_OWL_THING}) });
        __auto_type gseeds = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type wseeds = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type tainted = ((slop_list_types_KElem){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type answers = ((slop_list_kscsat_ClassAnswer){ .data = NULL, .len = 0, .cap = 0 });
        int64_t unsafe_count = 0;
        {
            __auto_type _coll = idx.individuals;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(gseeds); __auto_type _item = (ksc_ksc_1(a).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(wseeds); __auto_type _item = (ksc_ksc_1(a).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                ({ __auto_type _lst_p = &(tainted); __auto_type _item = (types_ind_elem(a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        ({ __auto_type _lst_p = &(wseeds); __auto_type _item = (ksc_ksc_q(thing).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                ({ __auto_type _lst_p = &(wseeds); __auto_type _item = (ksc_ksc_q(q).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type g = kscsat_run_ksc(arena, idx, ((slop_option_kscsat_Base){.has_value = false}), gseeds, 1);
            __auto_type w = kscsat_run_ksc(arena, idx, ((slop_option_kscsat_Base){.has_value = false}), wseeds, 0);
            {
                __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, w.store.noms_at); (slop_list_types_KElem){.data = (types_KElem*)_r.data, .len = _r.len, .cap = _r.cap}; });
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type x = _coll.data[_i];
                    ({ __auto_type _lst_p = &(tainted); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            {
                __auto_type base = ((kscsat_Base){.g = g.store, .w = w.store, .unsafe = kscsat_backward_closure(arena, w.store, tainted), .botreach = kscsat_backward_closure(arena, w.store, ({ slop_set_elements_result _r = slop_set_elements_raw(arena, w.store.bots); (slop_list_types_KElem){.data = (types_KElem*)_r.data, .len = _r.len, .cap = _r.cap}; }))});
                __auto_type thing_answer = kscsat_class_answer(arena, idx, base, g.unsat, thing);
                {
                    __auto_type _coll = classes;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type q = _coll.data[_i];
                        {
                            __auto_type a = kscsat_class_answer(arena, idx, base, g.unsat, q);
                            if (!(a.shared)) {
                                unsafe_count = (unsafe_count + 1);
                            }
                            ({ __auto_type _lst_p = &(answers); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                return ((kscsat_KscResult){.inconsistent = thing_answer.unsat, .g_rounds = g.rounds, .g_facts = g.facts, .w_rounds = w.rounds, .w_facts = w.facts, .unsafe_count = unsafe_count, .answers = answers});
            }
        }
    }
}

uint8_t kscsat_answer_holds(kscsat_ClassAnswer a, types_KName b) {
    if (a.unsat) {
        return 1;
    } else {
        {
            uint8_t found = 0;
            {
                __auto_type _coll = a.subsumers;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type n = _coll.data[_i];
                    if (types_kname_eq(n, b)) {
                        found = 1;
                    }
                }
            }
            return found;
        }
    }
}

slop_list_types_KName kscsat_input_classes(slop_arena* arena, owl2_Signature sig) {
    {
        __auto_type out = ((slop_list_types_KName){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = canon_sort_iris(arena, ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.classes); (slop_list_rdf_IRI){.data = (rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap}; }));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_KName){ .tag = types_KName_k_class, .data.k_class = c })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

