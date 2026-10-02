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
slop_list_list_types_KFact kscsat_ins_lists(slop_arena* arena, slop_map* m, types_KElem k);
slop_list_list_types_KFact kscsat_all_ins(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KElem k);
slop_list_kscsat_RoleLegs kscsat_legs_at(slop_arena* arena, kscpremise_KscIndex idx, slop_map* m, types_KElem k, types_RoleId v);
slop_list_kscsat_RoleLegs kscsat_role_legs(slop_arena* arena, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, uint8_t outward, types_KElem k, types_RoleId v);
slop_list_kscsat_Match kscsat_partner_matches(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KElem x, kscpremise_KPartners p);
slop_list_types_KFact kscsat_derive(slop_arena* arena, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f);
types_RoleId kscsat_ksc_dummy_role(void);
uint8_t kscsat_is_bottom_fact(types_KFact f);
uint8_t kscsat_reaches_bottom(slop_option_kscsat_Base base, types_KFact f);
kscsat_RoundOut kscsat_ksc_round(slop_arena* arena, slop_arena* na, slop_arena* ra, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, slop_list_types_KFact delta, uint8_t stop_at_bottom, uint8_t unsat0);
kscsat_RunResult kscsat_run_ksc(slop_arena* arena, kscpremise_KscIndex idx, slop_option_kscsat_Base base, slop_list_types_KFact seeds, uint8_t stop_at_bottom, int64_t budget, int64_t cancel);
kscsat_RoundOut kscsat_seed_run(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, slop_list_types_KFact seeds);
slop_list_types_KName kscsat_answer_subsumers(slop_arena* arena, kscsat_KStore st, types_KName q);
slop_map* kscsat_backward_closure(slop_arena* arena, kscsat_KStore w, slop_list_types_KElem start);
slop_option_types_ClassAnswer kscsat_class_run(slop_arena* arena, kscpremise_KscIndex idx, kscsat_Base base, uint8_t g_unsat, int64_t budget, int64_t cancel, types_KName q);
types_ClassAnswer kscsat_shared_answer(slop_arena* arena, kscsat_Base base, uint8_t g_unsat, types_KName q);
slop_option_types_ClassAnswer kscsat_class_answer(slop_arena* arena, kscpremise_KscIndex idx, kscsat_Base base, uint8_t g_unsat, int64_t budget, int64_t cancel, types_KName q);
slop_result_types_KscResult_types_Fault kscsat_classify_renamed(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, types_ReasonerConfig config);
slop_result_types_KscResult_types_Fault kscsat_ksc_classify(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, types_ReasonerConfig config);
types_KscResult kscsat_unrename_result(slop_arena* arena, kscnames_KscNames nm, types_KscResult r);
types_KscResult kscsat_g_only(slop_arena* arena, kscsat_RunResult g, uint8_t inconsistent);
types_ClassAnswer kscsat_copy_answer(slop_arena* arena, types_ClassAnswer a);
int64_t kscsat_run_chunk(slop_arena* wa, kscpremise_KscIndex idx, kscsat_Base base, int64_t budget, int64_t cancel, slop_list_types_KName classes, slop_list_int todo, slop_map* out);
slop_list_int kscsat_index_chunk(slop_arena* arena, slop_list_int xs, int64_t lo, int64_t hi);
int64_t kscsat_worker_count_for(int64_t workers, int64_t jobs);
slop_result_types_KscResult_types_Fault kscsat_classify_over_w(slop_arena* arena, kscpremise_KscIndex idx, kscsat_RunResult g, kscsat_RunResult w, slop_list_types_KElem tainted, types_KName thing, slop_list_types_KName classes, int64_t budget, int64_t workers, int64_t cancel);
int64_t kscsat_max_rounds(slop_list_types_ClassAnswer answers);
uint8_t kscsat_answer_holds(types_ClassAnswer a, types_KName b);
slop_list_types_KName kscsat_input_classes(slop_arena* arena, owl2_Signature sig);

typedef struct { slop_arena* wa; kscpremise_KscIndex idx; kscsat_Base base; int64_t budget; int64_t cancel; slop_list_types_KName classes; slop_list_int chunk; slop_map* out; } kscsat__lambda_842_env_t;

static int64_t kscsat__lambda_842(kscsat__lambda_842_env_t* _env) { return kscsat_run_chunk(_env->wa, _env->idx, _env->base, _env->budget, _env->cancel, _env->classes, _env->chunk, _env->out); }

kscsat_KStore kscsat_new_store(slop_arena* arena) {
    return ((kscsat_KStore){.seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_KFact, slop_hash_types_KFact, slop_eq_types_KFact, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .insts = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED, kscsat_FactList); slop_map_new_ptr(arena, 0, &_d); }), .noms = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED, kscsat_FactList); slop_map_new_ptr(arena, 0, &_d); }), .holders = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED, kscsat_FactList); slop_map_new_ptr(arena, 0, &_d); }), .outs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED, kscsat_RoleFacts); slop_map_new_ptr(arena, 0, &_d); }), .ins = ({ static const slop_map_desc _d = SLOP_MAP_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED, kscsat_RoleFacts); slop_map_new_ptr(arena, 0, &_d); }), .noms_at = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .bots = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); })});
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
    __auto_type _mv_778 = f;
    switch (_mv_778.tag) {
        case types_KFact_f_inst:
        {
            __auto_type x = _mv_778.data.f_inst.f0;
            return x;
        }
        case types_KFact_f_triple:
        {
            __auto_type x = _mv_778.data.f_triple.f0;
            return x;
        }
        case types_KFact_f_self:
        {
            __auto_type x = _mv_778.data.f_self.f0;
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
        __auto_type _mv_781 = base;
        if (_mv_781.has_value) {
            __auto_type b = _mv_781.value;
            if (slop_map_has(b.g.seen, &(f))) {
                return 1;
            } else {
                if (kscsat_is_safe(b, kscsat_fact_subject(f))) {
                    return slop_map_has(b.w.seen, &(f));
                } else {
                    return 0;
                }
            }
        } else if (!_mv_781.has_value) {
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
        __auto_type _mv_785 = f;
        switch (_mv_785.tag) {
            case types_KFact_f_inst:
            {
                __auto_type x = _mv_785.data.f_inst.f0;
                __auto_type y = _mv_785.data.f_inst.f1;
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
                __auto_type x = _mv_785.data.f_triple.f0;
                __auto_type v = _mv_785.data.f_triple.f1;
                __auto_type x1 = _mv_785.data.f_triple.f2;
                kscsat_rf_push(arena, st.outs, x, v, f);
                kscsat_rf_push(arena, st.ins, x1, v, f);
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
    __auto_type _mv_789 = ({ void* _ptr = slop_map_get(m, &(k)); _ptr ? (slop_option_kscsat_FactList){ .has_value = true, .value = *(kscsat_FactList*)_ptr } : (slop_option_kscsat_FactList){ .has_value = false }; });
    if (_mv_789.has_value) {
        __auto_type l = _mv_789.value;
        return l.items;
    } else if (!_mv_789.has_value) {
        return ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_list_types_KFact kscsat_rf_items(slop_arena* arena, slop_map* m, types_KElem k, types_RoleId v) {
    __auto_type _mv_791 = ({ void* _ptr = slop_map_get(m, &(k)); _ptr ? (slop_option_kscsat_RoleFacts){ .has_value = true, .value = *(kscsat_RoleFacts*)_ptr } : (slop_option_kscsat_RoleFacts){ .has_value = false }; });
    if (_mv_791.has_value) {
        __auto_type rf = _mv_791.value;
        __auto_type _mv_793 = ({ void* _ptr = slop_map_get(rf.by_role, &(v)); _ptr ? (slop_option_kscsat_FactList){ .has_value = true, .value = *(kscsat_FactList*)_ptr } : (slop_option_kscsat_FactList){ .has_value = false }; });
        if (_mv_793.has_value) {
            __auto_type l = _mv_793.value;
            return l.items;
        } else if (!_mv_793.has_value) {
            return ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_791.has_value) {
        return ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_map* kscsat_field_map(kscsat_KStore st, kscsat_Field fd) {
    __auto_type _mv_794 = fd;
    if (_mv_794 == kscsat_Field_fd_insts) {
        return st.insts;
    } else if (_mv_794 == kscsat_Field_fd_noms) {
        return st.noms;
    } else if (_mv_794 == kscsat_Field_fd_holders) {
        return st.holders;
    }
    SLOP_UNREACHABLE();
}

uint8_t kscsat_keyed_by_subject(kscsat_Field fd) {
    __auto_type _mv_795 = fd;
    if (_mv_795 == kscsat_Field_fd_insts) {
        return 1;
    } else if (_mv_795 == kscsat_Field_fd_noms) {
        return 1;
    } else if (_mv_795 == kscsat_Field_fd_holders) {
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
        __auto_type _mv_796 = base;
        if (_mv_796.has_value) {
            __auto_type b = _mv_796.value;
            ({ __auto_type _lst_p = &(out); __auto_type _item = (kscsat_fl_items(arena, kscsat_field_map(b.g, fd), k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            ({ __auto_type _lst_p = &(out); __auto_type _item = (kscsat_w_items(arena, b, kscsat_keyed_by_subject(fd), k, kscsat_fl_items(arena, kscsat_field_map(b.w, fd), k))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (!_mv_796.has_value) {
        }
        ({ __auto_type _lst_p = &(out); __auto_type _item = (kscsat_fl_items(arena, kscsat_field_map(st, fd), k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

slop_list_list_types_KFact kscsat_ins_lists(slop_arena* arena, slop_map* m, types_KElem k) {
    {
        __auto_type out = ((slop_list_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_798 = ({ void* _ptr = slop_map_get(m, &(k)); _ptr ? (slop_option_kscsat_RoleFacts){ .has_value = true, .value = *(kscsat_RoleFacts*)_ptr } : (slop_option_kscsat_RoleFacts){ .has_value = false }; });
        if (_mv_798.has_value) {
            __auto_type rf = _mv_798.value;
            {
                slop_map* _coll = (slop_map*)rf.by_role;
                for (size_t _i = 0; _i < _coll->len; _i++) {
                    {
                        types_RoleId v = *(types_RoleId*)slop_map_key_at(_coll, _i);
                        kscsat_FactList fl = *(kscsat_FactList*)slop_map_value_at(_coll, _i);
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (fl.items); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        } else if (!_mv_798.has_value) {
        }
        return out;
    }
}

slop_list_list_types_KFact kscsat_all_ins(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KElem k) {
    {
        __auto_type out = ((slop_list_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_799 = base;
        if (_mv_799.has_value) {
            __auto_type b = _mv_799.value;
            {
                __auto_type _coll = kscsat_ins_lists(arena, b.g.ins, k);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type l = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            {
                __auto_type _coll = kscsat_ins_lists(arena, b.w.ins, k);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type l = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (kscsat_w_items(arena, b, 0, k, l)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        } else if (!_mv_799.has_value) {
        }
        {
            __auto_type _coll = kscsat_ins_lists(arena, st.ins, k);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_kscsat_RoleLegs kscsat_legs_at(slop_arena* arena, kscpremise_KscIndex idx, slop_map* m, types_KElem k, types_RoleId v) {
    {
        __auto_type out = ((slop_list_kscsat_RoleLegs){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_801 = ({ void* _ptr = slop_map_get(m, &(k)); _ptr ? (slop_option_kscsat_RoleFacts){ .has_value = true, .value = *(kscsat_RoleFacts*)_ptr } : (slop_option_kscsat_RoleFacts){ .has_value = false }; });
        if (_mv_801.has_value) {
            __auto_type rf = _mv_801.value;
            {
                __auto_type subs = kscpremise_role_subs(arena, idx, v);
                if (((int64_t)(rf.by_role)->len) <= ((int64_t)((subs).len))) {
                    {
                        slop_map* _coll = (slop_map*)rf.by_role;
                        for (size_t _i = 0; _i < _coll->len; _i++) {
                            {
                                types_RoleId e = *(types_RoleId*)slop_map_key_at(_coll, _i);
                                kscsat_FactList fl = *(kscsat_FactList*)slop_map_value_at(_coll, _i);
                                if (kscpremise_role_under(idx, e, v)) {
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((kscsat_RoleLegs){.role = e, .facts = fl.items})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                } else {
                    {
                        __auto_type _coll = subs;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type e = _coll.data[_i];
                            __auto_type _mv_803 = ({ void* _ptr = slop_map_get(rf.by_role, &(e)); _ptr ? (slop_option_kscsat_FactList){ .has_value = true, .value = *(kscsat_FactList*)_ptr } : (slop_option_kscsat_FactList){ .has_value = false }; });
                            if (_mv_803.has_value) {
                                __auto_type fl = _mv_803.value;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (((kscsat_RoleLegs){.role = e, .facts = fl.items})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else if (!_mv_803.has_value) {
                            }
                        }
                    }
                }
            }
        } else if (!_mv_801.has_value) {
        }
        return out;
    }
}

slop_list_kscsat_RoleLegs kscsat_role_legs(slop_arena* arena, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, uint8_t outward, types_KElem k, types_RoleId v) {
    {
        __auto_type out = ((slop_list_kscsat_RoleLegs){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_804 = base;
        if (_mv_804.has_value) {
            __auto_type b = _mv_804.value;
            {
                __auto_type _coll = kscsat_legs_at(arena, idx, ((outward) ? b.g.outs : b.g.ins), k, v);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type lg = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (lg); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            {
                __auto_type _coll = kscsat_legs_at(arena, idx, ((outward) ? b.w.outs : b.w.ins), k, v);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type lg = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((kscsat_RoleLegs){.role = lg.role, .facts = kscsat_w_items(arena, b, outward, k, lg.facts)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        } else if (!_mv_804.has_value) {
        }
        {
            __auto_type _coll = kscsat_legs_at(arena, idx, ((outward) ? st.outs : st.ins), k, v);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type lg = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (lg); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_kscsat_Match kscsat_partner_matches(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KElem x, kscpremise_KPartners p) {
    {
        __auto_type lists = kscsat_partners(arena, st, base, kscsat_Field_fd_insts, x);
        int64_t nx = 0;
        __auto_type out = ((slop_list_kscsat_Match){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = lists;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                nx = (nx + ((int64_t)(((int64_t)((l).len)))));
            }
        }
        if (p.count <= nx) {
            {
                slop_map* _coll = (slop_map*)p.by_other;
                for (size_t _i = 0; _i < _coll->len; _i++) {
                    {
                        types_KTerm other = *(types_KTerm*)slop_map_key_at(_coll, _i);
                        kscpremise_KList axl = *(kscpremise_KList*)slop_map_value_at(_coll, _i);
                        if (kscsat_store_holds(st, base, ((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = other } }))) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (((kscsat_Match){.other = other, .axioms = axl})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        } else {
            {
                __auto_type _coll = lists;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type l = _coll.data[_i];
                    {
                        __auto_type _coll = l;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type g = _coll.data[_i];
                            __auto_type _mv_805 = g;
                            switch (_mv_805.tag) {
                                case types_KFact_f_inst:
                                {
                                    __auto_type z = _mv_805.data.f_inst.f1;
                                    __auto_type _mv_807 = ({ void* _ptr = slop_map_get(p.by_other, &(z)); _ptr ? (slop_option_kscpremise_KList){ .has_value = true, .value = *(kscpremise_KList*)_ptr } : (slop_option_kscpremise_KList){ .has_value = false }; });
                                    if (_mv_807.has_value) {
                                        __auto_type axl = _mv_807.value;
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (((kscsat_Match){.other = z, .axioms = axl})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    } else if (!_mv_807.has_value) {
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
                }
            }
        }
        return out;
    }
}

slop_list_types_KFact kscsat_derive(slop_arena* arena, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f) {
    {
        __auto_type out = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_808 = f;
        switch (_mv_808.tag) {
            case types_KFact_f_inst:
            {
                __auto_type x = _mv_808.data.f_inst.f0;
                __auto_type y = _mv_808.data.f_inst.f1;
                {
                    __auto_type c = ksc_ksc_3(x, y);
                    if (c.fires) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                __auto_type _mv_809 = kscpremise_term_bucket(idx, y);
                if (_mv_809.has_value) {
                    __auto_type bucket = _mv_809.value;
                    {
                        __auto_type _coll = bucket.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ax = _coll.data[_i];
                            __auto_type _mv_810 = ax;
                            switch (_mv_810.tag) {
                                case types_KscAxiom_k_sub:
                                {
                                    __auto_type sy = _mv_810.data.k_sub.f0;
                                    __auto_type sz = _mv_810.data.k_sub.f1;
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
                                    break;
                                }
                                case types_KscAxiom_k_some_lhs:
                                {
                                    __auto_type v = _mv_810.data.k_some_lhs.f0;
                                    __auto_type a = _mv_810.data.k_some_lhs.f1;
                                    __auto_type z = _mv_810.data.k_some_lhs.f2;
                                    {
                                        __auto_type _coll = kscsat_role_legs(arena, idx, st, base, 0, x, v);
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type lg = _coll.data[_i];
                                            {
                                                __auto_type axe = ((types_KscAxiom){ .tag = types_KscAxiom_k_some_lhs, .data.k_some_lhs = { .f0 = lg.role, .f1 = a, .f2 = z } });
                                                {
                                                    __auto_type _coll = ksc_ksc_join(arena, ksc_JoinRule_j7_inst, f, lg.facts, axe);
                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                        __auto_type g = _coll.data[_i];
                                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
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
                                    __auto_type a = _mv_810.data.k_some_rhs.f0;
                                    __auto_type v = _mv_810.data.k_some_rhs.f1;
                                    __auto_type b = _mv_810.data.k_some_rhs.f2;
                                    __auto_type w = _mv_810.data.k_some_rhs.f3;
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
                                    __auto_type a = _mv_810.data.k_role_assert.f0;
                                    __auto_type v = _mv_810.data.k_role_assert.f1;
                                    __auto_type b = _mv_810.data.k_role_assert.f2;
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
                                    __auto_type a = _mv_810.data.k_self_rhs.f0;
                                    __auto_type v = _mv_810.data.k_self_rhs.f1;
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
                } else if (!_mv_809.has_value) {
                }
                __auto_type _mv_811 = kscpremise_and_partners(idx, y);
                if (_mv_811.has_value) {
                    __auto_type p = _mv_811.value;
                    {
                        __auto_type _coll = kscsat_partner_matches(arena, st, base, x, p);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type m = _coll.data[_i];
                            {
                                __auto_type _coll = m.axioms.items;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type ax = _coll.data[_i];
                                    __auto_type _mv_812 = ax;
                                    switch (_mv_812.tag) {
                                        case types_KscAxiom_k_and:
                                        {
                                            __auto_type a = _mv_812.data.k_and.f0;
                                            __auto_type b = _mv_812.data.k_and.f1;
                                            __auto_type z = _mv_812.data.k_and.f2;
                                            if (ksc_is_name(y, a)) {
                                                if (types_kterm_eq(m.other, types_name_term(b))) {
                                                    {
                                                        __auto_type c = ksc_ksc_6(a, b, z, x, y, x, m.other);
                                                        if (c.fires) {
                                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        }
                                                    }
                                                }
                                            }
                                            if (ksc_is_name(y, b)) {
                                                if (types_kterm_eq(m.other, types_name_term(a))) {
                                                    {
                                                        __auto_type c = ksc_ksc_6(a, b, z, x, m.other, x, y);
                                                        if (c.fires) {
                                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        }
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        case types_KscAxiom_k_sub:
                                        {
                                            break;
                                        }
                                        case types_KscAxiom_k_some_lhs:
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
                                        case types_KscAxiom_k_role_assert:
                                        {
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_811.has_value) {
                }
                {
                    __auto_type noax = ((types_KscAxiom){ .tag = types_KscAxiom_k_role, .data.k_role = { .f0 = kscsat_ksc_dummy_role(), .f1 = kscsat_ksc_dummy_role() } });
                    if (ksc_is_nominal(y)) {
                        {
                            __auto_type _coll = kscsat_partners(arena, st, base, kscsat_Field_fd_insts, x);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ps = _coll.data[_i];
                                {
                                    __auto_type _coll = ksc_ksc_join(arena, ksc_JoinRule_j27_nom, f, ps, noax);
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
                                    __auto_type _coll = ksc_ksc_join(arena, ksc_JoinRule_j28_nom, f, ps, noax);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type g = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        }
                        {
                            __auto_type _coll = kscsat_all_ins(arena, st, base, x);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ps = _coll.data[_i];
                                {
                                    __auto_type _coll = ksc_ksc_join(arena, ksc_JoinRule_j29_nom, f, ps, noax);
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
                                __auto_type _coll = ksc_ksc_join(arena, ksc_JoinRule_j27_other, f, ps, noax);
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
                                    __auto_type _coll = ksc_ksc_join(arena, ksc_JoinRule_j28_ind, f, ps, noax);
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
                __auto_type x = _mv_808.data.f_triple.f0;
                __auto_type e = _mv_808.data.f_triple.f1;
                __auto_type x1 = _mv_808.data.f_triple.f2;
                {
                    __auto_type c = ksc_ksc_2(x, e, x1);
                    if (c.fires) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                {
                    __auto_type _coll = kscpremise_role_sups(arena, idx, e);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type v = _coll.data[_i];
                        {
                            __auto_type fv = ((types_KFact){ .tag = types_KFact_f_triple, .data.f_triple = { .f0 = x, .f1 = v, .f2 = x1 } });
                            __auto_type _mv_813 = kscpremise_role_bucket(idx, v);
                            if (_mv_813.has_value) {
                                __auto_type bucket = _mv_813.value;
                                {
                                    __auto_type _coll = bucket.items;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type ax = _coll.data[_i];
                                        __auto_type _mv_814 = ax;
                                        switch (_mv_814.tag) {
                                            case types_KscAxiom_k_some_lhs:
                                            {
                                                break;
                                            }
                                            case types_KscAxiom_k_role:
                                            {
                                                break;
                                            }
                                            case types_KscAxiom_k_chain:
                                            {
                                                __auto_type u = _mv_814.data.k_chain.f0;
                                                __auto_type v2 = _mv_814.data.k_chain.f1;
                                                __auto_type w = _mv_814.data.k_chain.f2;
                                                if (types_role_eq(u, v)) {
                                                    {
                                                        __auto_type _coll = kscsat_role_legs(arena, idx, st, base, 1, x1, v2);
                                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                                            __auto_type lg = _coll.data[_i];
                                                            {
                                                                __auto_type ax2 = ((types_KscAxiom){ .tag = types_KscAxiom_k_chain, .data.k_chain = { .f0 = u, .f1 = lg.role, .f2 = w } });
                                                                {
                                                                    __auto_type _coll = ksc_ksc_join(arena, ksc_JoinRule_j15_first, fv, lg.facts, ax2);
                                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                                        __auto_type g = _coll.data[_i];
                                                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                                    }
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
                                                        __auto_type _coll = kscsat_role_legs(arena, idx, st, base, 0, x, u);
                                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                                            __auto_type lg = _coll.data[_i];
                                                            {
                                                                __auto_type ax1 = ((types_KscAxiom){ .tag = types_KscAxiom_k_chain, .data.k_chain = { .f0 = lg.role, .f1 = v2, .f2 = w } });
                                                                {
                                                                    __auto_type _coll = ksc_ksc_join(arena, ksc_JoinRule_j15_second, fv, lg.facts, ax1);
                                                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                                                        __auto_type g = _coll.data[_i];
                                                                        ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                                    }
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
                                                __auto_type v2 = _mv_814.data.k_range.f0;
                                                __auto_type d = _mv_814.data.k_range.f1;
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
                            } else if (!_mv_813.has_value) {
                            }
                            __auto_type _mv_815 = kscpremise_ex_partners(idx, v);
                            if (_mv_815.has_value) {
                                __auto_type p = _mv_815.value;
                                {
                                    __auto_type _coll = kscsat_partner_matches(arena, st, base, x1, p);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        {
                                            __auto_type _coll = m.axioms.items;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type ax = _coll.data[_i];
                                                __auto_type _mv_816 = ax;
                                                switch (_mv_816.tag) {
                                                    case types_KscAxiom_k_some_lhs:
                                                    {
                                                        __auto_type v2 = _mv_816.data.k_some_lhs.f0;
                                                        __auto_type a = _mv_816.data.k_some_lhs.f1;
                                                        __auto_type z = _mv_816.data.k_some_lhs.f2;
                                                        {
                                                            __auto_type c = ksc_ksc_7(v2, a, z, x, v, x1, x1, m.other);
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
                                                    case types_KscAxiom_k_role_assert:
                                                    {
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else if (!_mv_815.has_value) {
                            }
                        }
                    }
                }
                {
                    __auto_type noax = ((types_KscAxiom){ .tag = types_KscAxiom_k_role, .data.k_role = { .f0 = kscsat_ksc_dummy_role(), .f1 = kscsat_ksc_dummy_role() } });
                    {
                        __auto_type _coll = kscsat_partners(arena, st, base, kscsat_Field_fd_noms, x1);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ps = _coll.data[_i];
                            {
                                __auto_type _coll = ksc_ksc_join(arena, ksc_JoinRule_j29_triple, f, ps, noax);
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
                __auto_type x = _mv_808.data.f_self.f0;
                __auto_type v = _mv_808.data.f_self.f1;
                __auto_type _mv_817 = kscpremise_role_bucket(idx, v);
                if (_mv_817.has_value) {
                    __auto_type bucket = _mv_817.value;
                    {
                        __auto_type _coll = bucket.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ax = _coll.data[_i];
                            __auto_type _mv_818 = ax;
                            switch (_mv_818.tag) {
                                case types_KscAxiom_k_some_lhs:
                                {
                                    break;
                                }
                                case types_KscAxiom_k_self_lhs:
                                {
                                    __auto_type v2 = _mv_818.data.k_self_lhs.f0;
                                    __auto_type z = _mv_818.data.k_self_lhs.f1;
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
                                    __auto_type v2 = _mv_818.data.k_role.f0;
                                    __auto_type w = _mv_818.data.k_role.f1;
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
                                    __auto_type u = _mv_818.data.k_chain.f0;
                                    __auto_type v2 = _mv_818.data.k_chain.f1;
                                    __auto_type w = _mv_818.data.k_chain.f2;
                                    if (types_role_eq(u, v)) {
                                        {
                                            __auto_type _coll = kscsat_role_legs(arena, idx, st, base, 1, x, v2);
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type lg = _coll.data[_i];
                                                {
                                                    __auto_type ax2 = ((types_KscAxiom){ .tag = types_KscAxiom_k_chain, .data.k_chain = { .f0 = u, .f1 = lg.role, .f2 = w } });
                                                    {
                                                        __auto_type _coll = ksc_ksc_join(arena, ksc_JoinRule_j16_self, f, lg.facts, ax2);
                                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                                            __auto_type g = _coll.data[_i];
                                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        }
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
                                            __auto_type _coll = kscsat_role_legs(arena, idx, st, base, 0, x, u);
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type lg = _coll.data[_i];
                                                {
                                                    __auto_type ax1 = ((types_KscAxiom){ .tag = types_KscAxiom_k_chain, .data.k_chain = { .f0 = lg.role, .f1 = v2, .f2 = w } });
                                                    {
                                                        __auto_type _coll = ksc_ksc_join(arena, ksc_JoinRule_j17_self, f, lg.facts, ax1);
                                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                                            __auto_type g = _coll.data[_i];
                                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        }
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
                                    __auto_type v2 = _mv_818.data.k_range.f0;
                                    __auto_type d = _mv_818.data.k_range.f1;
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
                } else if (!_mv_817.has_value) {
                }
                __auto_type _mv_819 = kscpremise_ex_partners(idx, v);
                if (_mv_819.has_value) {
                    __auto_type p = _mv_819.value;
                    {
                        __auto_type _coll = kscsat_partner_matches(arena, st, base, x, p);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type m = _coll.data[_i];
                            {
                                __auto_type _coll = m.axioms.items;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type ax = _coll.data[_i];
                                    __auto_type _mv_820 = ax;
                                    switch (_mv_820.tag) {
                                        case types_KscAxiom_k_some_lhs:
                                        {
                                            __auto_type v2 = _mv_820.data.k_some_lhs.f0;
                                            __auto_type a = _mv_820.data.k_some_lhs.f1;
                                            __auto_type z = _mv_820.data.k_some_lhs.f2;
                                            {
                                                __auto_type c = ksc_ksc_8(v2, a, z, x, v, x, m.other);
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
                                        case types_KscAxiom_k_role_assert:
                                        {
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_819.has_value) {
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
    uint8_t _retval = {0};
    __auto_type _mv_821 = f;
    switch (_mv_821.tag) {
        case types_KFact_f_inst:
        {
            __auto_type u = _mv_821.data.f_inst.f0;
            __auto_type z = _mv_821.data.f_inst.f1;
            _retval = ksc_ksc_4(u, z);
            goto _slop_post;
        }
        case types_KFact_f_triple:
        {
            _retval = 0;
            goto _slop_post;
        }
        case types_KFact_f_self:
        {
            _retval = 0;
            goto _slop_post;
        }
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST((({ __auto_type _mv = f; uint8_t _mr = {0}; switch (_mv.tag) { case types_KFact_f_inst: { __auto_type u = _mv.data.f_inst; _mr = (_retval == ksc_ksc_4(u, z)); break; } case types_KFact_f_triple: { __auto_type _ = _mv.data.f_triple; _mr = (_retval == 0); break; } case types_KFact_f_self: { __auto_type _ = _mv.data.f_self; _mr = (_retval == 0); break; }  } _mr; })), "(match f ((f-inst u z) (== $result (ksc-4 u z))) ((f-triple _ _ _) (== $result false)) ((f-self _ _) (== $result false)))");
    return _retval;
}

uint8_t kscsat_reaches_bottom(slop_option_kscsat_Base base, types_KFact f) {
    uint8_t _retval = {0};
    __auto_type _mv_822 = base;
    if (_mv_822.has_value) {
        __auto_type b = _mv_822.value;
        __auto_type _mv_823 = f;
        switch (_mv_823.tag) {
            case types_KFact_f_triple:
            {
                __auto_type s = _mv_823.data.f_triple.f2;
                if (kscsat_is_safe(b, s)) {
                    _retval = slop_map_has(b.botreach, &(s));
                    goto _slop_post;
                } else {
                    _retval = 0;
                    goto _slop_post;
                }
            }
            case types_KFact_f_inst:
            {
                _retval = 0;
                goto _slop_post;
            }
            case types_KFact_f_self:
            {
                _retval = 0;
                goto _slop_post;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_822.has_value) {
        _retval = 0;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

kscsat_RoundOut kscsat_ksc_round(slop_arena* arena, slop_arena* na, slop_arena* ra, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, slop_list_types_KFact delta, uint8_t stop_at_bottom, uint8_t unsat0) {
    {
        __auto_type next = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        uint8_t unsat = unsat0;
        int64_t added = 0;
        {
            __auto_type _coll = delta;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                if (!(((stop_at_bottom) ? unsat : 0))) {
                    {
                        __auto_type _coll = kscsat_derive(ra, idx, st, base, f);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            if (kscsat_commit(arena, st, base, c)) {
                                ({ __auto_type _lst_p = &(next); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                added = (added + 1);
                                if (kscsat_is_bottom_fact(c)) {
                                    unsat = 1;
                                }
                                if (kscsat_reaches_bottom(base, c)) {
                                    unsat = 1;
                                }
                            }
                        }
                    }
                    saturate_reuse_arena(ra);
                }
            }
        }
        return ((kscsat_RoundOut){.next = next, .added = added, .unsat = unsat});
    }
}

kscsat_RunResult kscsat_run_ksc(slop_arena* arena, kscpremise_KscIndex idx, slop_option_kscsat_Base base, slop_list_types_KFact seeds, uint8_t stop_at_bottom, int64_t budget, int64_t cancel) {
    {
        __auto_type st = kscsat_new_store(arena);
        __auto_type ra = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        __auto_type seeded = kscsat_seed_run(arena, st, base, seeds);
        __auto_type da = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        __auto_type delta = seeded.next;
        uint8_t unsat = seeded.unsat;
        int64_t facts = seeded.added;
        int64_t rounds = 0;
        uint8_t cancelled = 0;
        uint8_t going = (((int64_t)((seeded.next).len)) > 0);
        if ((stop_at_bottom) ? unsat : 0) {
            delta = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
            going = 0;
        }
        while (going) {
            if (cancel && __atomic_load_n((uint32_t*)(uintptr_t)cancel, __ATOMIC_RELAXED)) { cancelled = 1; };
            if ((cancelled) ? 1 : (rounds >= budget)) {
                going = 0;
            } else {
                {
                    __auto_type na = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                    __auto_type ro = kscsat_ksc_round(arena, na, ra, idx, st, base, delta, stop_at_bottom, unsat);
                    rounds = (rounds + 1);
                    facts = (facts + ro.added);
                    unsat = ro.unsat;
                    ({ slop_arena_free(da); free(da); });
                    da = na;
                    delta = ((((stop_at_bottom) ? unsat : 0)) ? ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 }) : ro.next);
                    going = (((int64_t)((delta).len)) > 0);
                }
            }
        }
        {
            __auto_type capped = (((int64_t)((delta).len)) > 0);
            ({ slop_arena_free(da); free(da); });
            ({ slop_arena_free(ra); free(ra); });
            return ((kscsat_RunResult){.store = st, .rounds = rounds, .unsat = unsat, .capped = capped, .cancelled = cancelled, .facts = facts});
        }
    }
}

kscsat_RoundOut kscsat_seed_run(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, slop_list_types_KFact seeds) {
    {
        __auto_type next = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        uint8_t unsat = 0;
        int64_t added = 0;
        {
            __auto_type _coll = seeds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                if (kscsat_commit(arena, st, base, s)) {
                    ({ __auto_type _lst_p = &(next); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    added = (added + 1);
                    if (kscsat_is_bottom_fact(s)) {
                        unsat = 1;
                    }
                    if (kscsat_reaches_bottom(base, s)) {
                        unsat = 1;
                    }
                }
            }
        }
        return ((kscsat_RoundOut){.next = next, .added = added, .unsat = unsat});
    }
}

slop_list_types_KName kscsat_answer_subsumers(slop_arena* arena, kscsat_KStore st, types_KName q) {
    {
        __auto_type out = ((slop_list_types_KName){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = kscsat_fl_items(arena, st.insts, types_class_elem(q));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                __auto_type _mv_825 = f;
                switch (_mv_825.tag) {
                    case types_KFact_f_inst:
                    {
                        __auto_type y = _mv_825.data.f_inst.f1;
                        __auto_type _mv_826 = y;
                        switch (_mv_826.tag) {
                            case types_KTerm_k_name:
                            {
                                __auto_type n = _mv_826.data.k_name;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (kscnormal_copy_kname(arena, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case types_KTerm_k_nominal:
                            {
                                __auto_type _ = _mv_826.data.k_nominal;
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
            __auto_type _mv_829 = ({ __auto_type _lst = work; size_t _idx = (size_t)i; slop_option_types_KElem _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_829.has_value) {
                __auto_type x = _mv_829.value;
                __auto_type _mv_831 = ({ void* _ptr = slop_map_get(w.ins, &(x)); _ptr ? (slop_option_kscsat_RoleFacts){ .has_value = true, .value = *(kscsat_RoleFacts*)_ptr } : (slop_option_kscsat_RoleFacts){ .has_value = false }; });
                if (_mv_831.has_value) {
                    __auto_type rf = _mv_831.value;
                    {
                        slop_map* _coll = (slop_map*)rf.by_role;
                        for (size_t _i = 0; _i < _coll->len; _i++) {
                            {
                                types_RoleId v = *(types_RoleId*)slop_map_key_at(_coll, _i);
                                kscsat_FactList fl = *(kscsat_FactList*)slop_map_value_at(_coll, _i);
                                {
                                    __auto_type _coll = fl.items;
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
                            }
                        }
                    }
                } else if (!_mv_831.has_value) {
                }
            } else if (!_mv_829.has_value) {
            }
            i = (i + 1);
        }
        return out;
    }
}

slop_option_types_ClassAnswer kscsat_class_run(slop_arena* arena, kscpremise_KscIndex idx, kscsat_Base base, uint8_t g_unsat, int64_t budget, int64_t cancel, types_KName q) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        __auto_type qseeds = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        ({ __auto_type _lst_p = &(qseeds); __auto_type _item = (ksc_ksc_q(q).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type r = kscsat_run_ksc(scratch, idx, (slop_option_kscsat_Base){.has_value = 1, .value = base}, qseeds, 1, budget, cancel);
            __auto_type ans = ((types_ClassAnswer){.cls = q, .shared = 0, .unsat = ((g_unsat) ? 1 : r.unsat), .subsumers = kscsat_answer_subsumers(arena, r.store, q), .complete = ((r.unsat) ? 1 : !(r.capped)), .rounds = r.rounds, .facts = r.facts});
            ({ slop_arena_free(scratch); free(scratch); });
            if (r.cancelled) {
                return (slop_option_types_ClassAnswer){.has_value = false};
            } else {
                return (slop_option_types_ClassAnswer){.has_value = 1, .value = ans};
            }
        }
    }
}

types_ClassAnswer kscsat_shared_answer(slop_arena* arena, kscsat_Base base, uint8_t g_unsat, types_KName q) {
    types_ClassAnswer _retval = {0};
    _retval = ((types_ClassAnswer){.cls = q, .shared = 1, .unsat = ((g_unsat) ? 1 : ({ types_KElem _key_834 = (types_class_elem(q)); slop_map_has(base.botreach, &_key_834); })), .subsumers = kscsat_answer_subsumers(arena, base.w, q), .complete = 1, .rounds = 0, .facts = 0});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.shared == 1)), "(== (. $result shared) true)");
    SLOP_POST(((_retval.complete == 1)), "(== (. $result complete) true)");
    return _retval;
}

slop_option_types_ClassAnswer kscsat_class_answer(slop_arena* arena, kscpremise_KscIndex idx, kscsat_Base base, uint8_t g_unsat, int64_t budget, int64_t cancel, types_KName q) {
    if (kscsat_is_safe(base, types_class_elem(q))) {
        return (slop_option_types_ClassAnswer){.has_value = 1, .value = kscsat_shared_answer(arena, base, g_unsat, q)};
    } else {
        return kscsat_class_run(arena, idx, base, g_unsat, budget, cancel, q);
    }
}

slop_result_types_KscResult_types_Fault kscsat_classify_renamed(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, types_ReasonerConfig config) {
    {
        __auto_type idx = kscpremise_build_ksc_index(arena, axioms);
        __auto_type thing = ((types_KName){ .tag = types_KName_k_class, .data.k_class = ((rdf_IRI){.value = vocab_OWL_THING}) });
        __auto_type n = config.max_iterations;
        __auto_type gseeds = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type wseeds = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type tainted = ((slop_list_types_KElem){ .data = NULL, .len = 0, .cap = 0 });
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
            __auto_type g = kscsat_run_ksc(arena, idx, ((slop_option_kscsat_Base){.has_value = false}), gseeds, 1, n, config.cancel_ptr);
            if (g.cancelled) {
                return ((slop_result_types_KscResult_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_cancelled }) });
            } else {
                if (g.unsat) {
                    return ((slop_result_types_KscResult_types_Fault){ .is_ok = true, .data.ok = kscsat_g_only(arena, g, 1) });
                } else {
                    if (g.capped) {
                        return ((slop_result_types_KscResult_types_Fault){ .is_ok = true, .data.ok = kscsat_g_only(arena, g, 0) });
                    } else {
                        {
                            __auto_type w = kscsat_run_ksc(arena, idx, ((slop_option_kscsat_Base){.has_value = false}), wseeds, 0, (n - g.rounds), config.cancel_ptr);
                            if (w.cancelled) {
                                return ((slop_result_types_KscResult_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_cancelled }) });
                            } else {
                                if (w.capped) {
                                    return ((slop_result_types_KscResult_types_Fault){ .is_ok = true, .data.ok = ((types_KscResult){.inconsistent = 0, .termination = ((types_Termination){ .tag = types_Termination_resource_limit, .data.resource_limit = n }), .rounds = (g.rounds + w.rounds), .g_rounds = g.rounds, .g_facts = g.facts, .w_rounds = w.rounds, .w_facts = w.facts, .unsafe_count = 0, .answers = ((slop_list_types_ClassAnswer){ .data = NULL, .len = 0, .cap = 0 })}) });
                                } else {
                                    return kscsat_classify_over_w(arena, idx, g, w, tainted, thing, classes, (n - (g.rounds + w.rounds)), ((int64_t)(config.worker_count)), config.cancel_ptr);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

slop_result_types_KscResult_types_Fault kscsat_ksc_classify(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes, types_ReasonerConfig config) {
    {
        __auto_type nm = kscnames_build_ksc_names(arena, axioms, classes);
        __auto_type _mv_835 = kscsat_classify_renamed(arena, kscnames_rename_ksc_axioms(arena, nm, axioms), kscnames_rename_classes(arena, nm, classes), config);
        if (!_mv_835.is_ok) {
            __auto_type f = _mv_835.data.err;
            return ((slop_result_types_KscResult_types_Fault){ .is_ok = false, .data.err = f });
        } else if (_mv_835.is_ok) {
            __auto_type r = _mv_835.data.ok;
            return ((slop_result_types_KscResult_types_Fault){ .is_ok = true, .data.ok = kscsat_unrename_result(arena, nm, r) });
        }
        SLOP_UNREACHABLE();
    }
}

types_KscResult kscsat_unrename_result(slop_arena* arena, kscnames_KscNames nm, types_KscResult r) {
    {
        __auto_type answers = ((slop_list_types_ClassAnswer){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = r.answers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(answers); __auto_type _item = (kscnames_unrename_answer(arena, nm, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((types_KscResult){.inconsistent = r.inconsistent, .termination = r.termination, .rounds = r.rounds, .g_rounds = r.g_rounds, .g_facts = r.g_facts, .w_rounds = r.w_rounds, .w_facts = r.w_facts, .unsafe_count = r.unsafe_count, .answers = answers});
    }
}

types_KscResult kscsat_g_only(slop_arena* arena, kscsat_RunResult g, uint8_t inconsistent) {
    return ((types_KscResult){.inconsistent = inconsistent, .termination = ((inconsistent) ? ((types_Termination){ .tag = types_Termination_fixpoint }) : ((types_Termination){ .tag = types_Termination_resource_limit, .data.resource_limit = g.rounds })), .rounds = g.rounds, .g_rounds = g.rounds, .g_facts = g.facts, .w_rounds = 0, .w_facts = 0, .unsafe_count = 0, .answers = ((slop_list_types_ClassAnswer){ .data = NULL, .len = 0, .cap = 0 })});
}

types_ClassAnswer kscsat_copy_answer(slop_arena* arena, types_ClassAnswer a) {
    {
        __auto_type subs = ((slop_list_types_KName){ .data = NULL, .len = 0, .cap = 0 });
        {
            __auto_type _coll = a.subsumers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                ({ __auto_type _lst_p = &(subs); __auto_type _item = (kscnormal_copy_kname(arena, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return ((types_ClassAnswer){.cls = kscnormal_copy_kname(arena, a.cls), .shared = a.shared, .unsat = a.unsat, .subsumers = subs, .complete = a.complete, .rounds = a.rounds, .facts = a.facts});
    }
}

int64_t kscsat_run_chunk(slop_arena* wa, kscpremise_KscIndex idx, kscsat_Base base, int64_t budget, int64_t cancel, slop_list_types_KName classes, slop_list_int todo, slop_map* out) {
    {
        uint8_t cancelled = 0;
        {
            __auto_type _coll = todo;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                if (cancel && __atomic_load_n((uint32_t*)(uintptr_t)cancel, __ATOMIC_RELAXED)) { cancelled = 1; };
                if (!(cancelled)) {
                    __auto_type _mv_836 = ({ __auto_type _lst = classes; size_t _idx = (size_t)i; slop_option_types_KName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_836.has_value) {
                        __auto_type q = _mv_836.value;
                        __auto_type _mv_837 = kscsat_class_run(wa, idx, base, 0, budget, cancel, q);
                        if (_mv_837.has_value) {
                            __auto_type a = _mv_837.value;
                            ({ types_ClassAnswer _val = a; slop_map_put(wa, out, &(int64_t){i}, &_val, sizeof(_val)); });
                        } else if (!_mv_837.has_value) {
                            cancelled = 1;
                        }
                    } else if (!_mv_836.has_value) {
                    }
                }
            }
        }
        if (cancelled) {
            return 1;
        } else {
            return 0;
        }
    }
}

slop_list_int kscsat_index_chunk(slop_arena* arena, slop_list_int xs, int64_t lo, int64_t hi) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0 });
        int64_t j = lo;
        while (j < hi) {
            __auto_type _mv_839 = ({ __auto_type _lst = xs; size_t _idx = (size_t)j; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_839.has_value) {
                __auto_type x = _mv_839.value;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_839.has_value) {
            }
            j = (j + 1);
        }
        return out;
    }
}

int64_t kscsat_worker_count_for(int64_t workers, int64_t jobs) {
    int64_t _retval = {0};
    if (workers < 1) {
        _retval = 1;
        goto _slop_post;
    } else {
        if (workers > jobs) {
            if (jobs > 0) {
                _retval = jobs;
                goto _slop_post;
            } else {
                _retval = 1;
                goto _slop_post;
            }
        } else {
            _retval = workers;
            goto _slop_post;
        }
    }
    _slop_post: ;
    SLOP_POST(((_retval >= 1)), "(>= $result 1)");
    return _retval;
}

slop_result_types_KscResult_types_Fault kscsat_classify_over_w(slop_arena* arena, kscpremise_KscIndex idx, kscsat_RunResult g, kscsat_RunResult w, slop_list_types_KElem tainted, types_KName thing, slop_list_types_KName classes, int64_t budget, int64_t workers, int64_t cancel) {
    {
        __auto_type taint = ((slop_list_types_KElem){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type answers = ((slop_list_types_ClassAnswer){ .data = NULL, .len = 0, .cap = 0 });
        uint8_t complete = 1;
        int64_t cancelled = 0;
        {
            __auto_type _coll = tainted;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(taint); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, w.store.noms_at); (slop_list_types_KElem){.data = (types_KElem*)_r.data, .len = _r.len, .cap = _r.cap}; });
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ __auto_type _lst_p = &(taint); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type base = ((kscsat_Base){.g = g.store, .w = w.store, .unsafe = kscsat_backward_closure(arena, w.store, taint), .botreach = kscsat_backward_closure(arena, w.store, ({ slop_set_elements_result _r = slop_set_elements_raw(arena, w.store.bots); (slop_list_types_KElem){.data = (types_KElem*)_r.data, .len = _r.len, .cap = _r.cap}; }))});
            __auto_type thing_run = kscsat_class_answer(arena, idx, base, 0, budget, cancel, thing);
            __auto_type shared = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, types_ClassAnswer); slop_map_new_ptr(arena, 0, &_d); });
            __auto_type todo = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0 });
            int64_t i = 0;
            __auto_type _mv_840 = thing_run;
            if (!_mv_840.has_value) {
                return ((slop_result_types_KscResult_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_cancelled }) });
            } else if (_mv_840.has_value) {
                __auto_type thing_answer = _mv_840.value;
                if (!(thing_answer.complete)) {
                    complete = 0;
                }
                {
                    __auto_type _coll = classes;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type q = _coll.data[_i];
                        if (kscsat_is_safe(base, types_class_elem(q))) {
                            ({ types_ClassAnswer _val = kscsat_shared_answer(arena, base, 0, q); slop_map_put(arena, shared, &(int64_t){i}, &_val, sizeof(_val)); });
                        } else {
                            ({ __auto_type _lst_p = &(todo); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        i = (i + 1);
                    }
                }
                {
                    __auto_type jobs = ((int64_t)(((int64_t)((todo).len))));
                    __auto_type nw = kscsat_worker_count_for(workers, ((int64_t)(((int64_t)((todo).len)))));
                    __auto_type per = ((((int64_t)(((int64_t)((todo).len)))) + (kscsat_worker_count_for(workers, ((int64_t)(((int64_t)((todo).len))))) - 1)) / kscsat_worker_count_for(workers, ((int64_t)(((int64_t)((todo).len))))));
                    __auto_type was = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0 });
                    __auto_type outs = ((slop_list_map_ptr){ .data = NULL, .len = 0, .cap = 0 });
                    __auto_type threads = ((slop_list_thread_int_ptr){ .data = NULL, .len = 0, .cap = 0 });
                    __auto_type k = 0;
                    while (k < nw) {
                        {
                            __auto_type wa = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                            __auto_type out = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, types_ClassAnswer); slop_map_new_ptr(wa, 0, &_d); });
                            __auto_type chunk = kscsat_index_chunk(wa, todo, (k * per), ((k + 1) * per));
                            ({ __auto_type _lst_p = &(was); __auto_type _item = (wa); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(outs); __auto_type _item = (out); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            if (nw <= 1) {
                                cancelled = (cancelled + kscsat_run_chunk(wa, idx, base, budget, cancel, classes, chunk, out));
                            } else {
                                ({ __auto_type _lst_p = &(threads); __auto_type _item = (({ slop_closure_t _spawn_cl = ({ kscsat__lambda_842_env_t* kscsat__lambda_842_env = (kscsat__lambda_842_env_t*)slop_arena_alloc(arena, sizeof(kscsat__lambda_842_env_t)); *kscsat__lambda_842_env = (kscsat__lambda_842_env_t){ .wa = wa, .idx = idx, .base = base, .budget = budget, .cancel = cancel, .classes = classes, .chunk = chunk, .out = out }; (slop_closure_t){ (void*)kscsat__lambda_842, (void*)kscsat__lambda_842_env }; }); slop_thread_int* _spawn_th = slop_arena_alloc(arena, sizeof(slop_thread_int)); _spawn_th->func = _spawn_cl.fn; _spawn_th->env = _spawn_cl.env; _spawn_th->done = false; pthread_create(&_spawn_th->id, NULL, (void*)slop_thread_int_entry, (void*)_spawn_th); _spawn_th; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                            k = (k + 1);
                        }
                    }
                    {
                        __auto_type _coll = threads;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type t = _coll.data[_i];
                            cancelled = (cancelled + thread_join(t));
                        }
                    }
                    i = 0;
                    {
                        __auto_type _coll = classes;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type q = _coll.data[_i];
                            __auto_type _mv_844 = ({ void* _ptr = slop_map_get(shared, &(int64_t){i}); _ptr ? (slop_option_types_ClassAnswer){ .has_value = true, .value = *(types_ClassAnswer*)_ptr } : (slop_option_types_ClassAnswer){ .has_value = false }; });
                            if (_mv_844.has_value) {
                                __auto_type a = _mv_844.value;
                                ({ __auto_type _lst_p = &(answers); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else if (!_mv_844.has_value) {
                                {
                                    __auto_type _coll = outs;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type out = _coll.data[_i];
                                        __auto_type _mv_846 = ({ void* _ptr = slop_map_get(out, &(int64_t){i}); _ptr ? (slop_option_types_ClassAnswer){ .has_value = true, .value = *(types_ClassAnswer*)_ptr } : (slop_option_types_ClassAnswer){ .has_value = false }; });
                                        if (_mv_846.has_value) {
                                            __auto_type a = _mv_846.value;
                                            if (!(a.complete)) {
                                                complete = 0;
                                            }
                                            ({ __auto_type _lst_p = &(answers); __auto_type _item = (kscsat_copy_answer(arena, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        } else if (!_mv_846.has_value) {
                                        }
                                    }
                                }
                            }
                            i = (i + 1);
                        }
                    }
                    if (cancelled > 0) {
                        {
                            __auto_type _coll = was;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type wa = _coll.data[_i];
                                ({ slop_arena_free(wa); free(wa); });
                            }
                        }
                        return ((slop_result_types_KscResult_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_cancelled }) });
                    } else {
                        {
                            __auto_type _coll = was;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type wa = _coll.data[_i];
                                ({ slop_arena_free(wa); free(wa); });
                            }
                        }
                        {
                            __auto_type qrounds = (((thing_answer.rounds > kscsat_max_rounds(answers))) ? thing_answer.rounds : kscsat_max_rounds(answers));
                            __auto_type total = (g.rounds + (w.rounds + qrounds));
                            return ((slop_result_types_KscResult_types_Fault){ .is_ok = true, .data.ok = ((types_KscResult){.inconsistent = thing_answer.unsat, .termination = ((complete) ? ((types_Termination){ .tag = types_Termination_fixpoint }) : ((types_Termination){ .tag = types_Termination_resource_limit, .data.resource_limit = total })), .rounds = total, .g_rounds = g.rounds, .g_facts = g.facts, .w_rounds = w.rounds, .w_facts = w.facts, .unsafe_count = jobs, .answers = answers}) });
                        }
                    }
                }
            }
            SLOP_UNREACHABLE();
        }
    }
}

int64_t kscsat_max_rounds(slop_list_types_ClassAnswer answers) {
    {
        int64_t m = 0;
        {
            __auto_type _coll = answers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (a.rounds > m) {
                    m = a.rounds;
                }
            }
        }
        return m;
    }
}

uint8_t kscsat_answer_holds(types_ClassAnswer a, types_KName b) {
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

