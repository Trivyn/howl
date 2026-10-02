#include "../runtime/slop_runtime.h"
#include "slop_kscsat.h"

kscsat_KStore kscsat_new_store(slop_arena* arena, kscids_KscIds ids);
uint8_t kscsat_il_push(slop_arena* arena, slop_map* m, uint32_t k, uint32_t i);
uint8_t kscsat_ri_push(slop_arena* arena, slop_map* m, uint32_t k, uint32_t v, uint32_t i);
types_KElem kscsat_fact_subject(types_KFact f);
uint8_t kscsat_is_safe(kscsat_Base b, types_KElem x);
uint8_t kscsat_store_holds(kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f);
uint8_t kscsat_commit(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f);
slop_option_list_u32 kscsat_id_items(slop_map* m, uint32_t k);
slop_map* kscsat_field_map(kscsat_KStore st, kscsat_Field fd);
uint8_t kscsat_keyed_by_subject(kscsat_Field fd);
slop_list_types_KFact kscsat_field_items(slop_arena* arena, kscsat_KStore st, kscsat_Field fd, types_KElem k);
slop_list_types_KFact kscsat_safe_facts(slop_arena* arena, kscsat_Base b, slop_list_types_KFact xs);
slop_list_types_KFact kscsat_w_items(slop_arena* arena, kscsat_Base b, uint8_t by_subject, types_KElem k, slop_list_types_KFact xs);
slop_list_list_types_KFact kscsat_partners(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, kscsat_Field fd, types_KElem k);
slop_list_types_KFact kscsat_leg_facts(slop_arena* arena, kscids_KscIds ids, uint8_t outward, types_KElem k, uint32_t e, slop_list_u32 is);
slop_list_list_types_KFact kscsat_all_ins(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KElem k);
slop_map* kscsat_side_map(kscsat_KStore st, uint8_t outward);
slop_list_kscsat_RoleLegs kscsat_legs_in_store(slop_arena* arena, kscsat_KStore st, uint8_t outward, types_KElem k, slop_option_kscsat_Under under);
slop_list_kscsat_RoleLegs kscsat_role_legs(slop_arena* arena, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, uint8_t outward, types_KElem k, types_RoleId v);
slop_list_list_u32 kscsat_inst_id_lists(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KElem x);
slop_list_kscsat_Match kscsat_partner_matches(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KElem x, kscpremise_KPartners p);
slop_list_types_KFact kscsat_derive(slop_arena* arena, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f);
types_RoleId kscsat_ksc_dummy_role(void);
uint8_t kscsat_is_bottom_fact(types_KFact f);
uint8_t kscsat_reaches_bottom(slop_option_kscsat_Base base, types_KFact f);
slop_list_types_KFact kscsat_delta_push(slop_arena* na, slop_list_types_KFact l, types_KFact c);
kscsat_RoundOut kscsat_ksc_round(slop_arena* arena, slop_arena* na, slop_arena* ra, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, slop_list_types_KFact delta, uint8_t stop_at_bottom, uint8_t unsat0);
kscsat_RunResult kscsat_run_ksc(slop_arena* arena, kscpremise_KscIndex idx, kscids_KscIds ids, slop_option_kscsat_Base base, slop_list_types_KFact seeds, uint8_t stop_at_bottom, int64_t budget, int64_t cancel);
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

typedef struct { slop_arena* wa; kscpremise_KscIndex idx; kscsat_Base base; int64_t budget; int64_t cancel; slop_list_types_KName classes; slop_list_int chunk; slop_map* out; } kscsat__lambda_870_env_t;

static int64_t kscsat__lambda_870(kscsat__lambda_870_env_t* _env) { return kscsat_run_chunk(_env->wa, _env->idx, _env->base, _env->budget, _env->cancel, _env->classes, _env->chunk, _env->out); }

kscsat_KStore kscsat_new_store(slop_arena* arena, kscids_KscIds ids) {
    return ((kscsat_KStore){.ids = ids, .seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(kscids_CFact, slop_hash_kscids_CFact, slop_eq_kscids_CFact, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .insts = ({ static const slop_map_desc _d = SLOP_MAP_DESC(uint32_t, slop_hash_u32, slop_eq_u32, SLOP_KEY_BITS, kscsat_IdList); slop_map_new_ptr(arena, 0, &_d); }), .noms = ({ static const slop_map_desc _d = SLOP_MAP_DESC(uint32_t, slop_hash_u32, slop_eq_u32, SLOP_KEY_BITS, kscsat_IdList); slop_map_new_ptr(arena, 0, &_d); }), .holders = ({ static const slop_map_desc _d = SLOP_MAP_DESC(uint32_t, slop_hash_u32, slop_eq_u32, SLOP_KEY_BITS, kscsat_IdList); slop_map_new_ptr(arena, 0, &_d); }), .outs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(uint32_t, slop_hash_u32, slop_eq_u32, SLOP_KEY_BITS, kscsat_RoleIds); slop_map_new_ptr(arena, 0, &_d); }), .ins = ({ static const slop_map_desc _d = SLOP_MAP_DESC(uint32_t, slop_hash_u32, slop_eq_u32, SLOP_KEY_BITS, kscsat_RoleIds); slop_map_new_ptr(arena, 0, &_d); }), .noms_at = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .bots = ({ static const slop_map_desc _d = SLOP_SET_DESC(types_KElem, slop_hash_types_KElem, slop_eq_types_KElem, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); })});
}

uint8_t kscsat_il_push(slop_arena* arena, slop_map* m, uint32_t k, uint32_t i) {
    {
        __auto_type items = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(m, &(uint32_t){k}); _ptr ? (slop_option_kscsat_IdList){ .has_value = true, .value = *(kscsat_IdList*)_ptr } : (slop_option_kscsat_IdList){ .has_value = false }; }); _mv.has_value ? ({ __auto_type l = _mv.value; l.items; }) : (((slop_list_u32){ .data = NULL, .len = 0, .cap = 0 })); });
        ({ __auto_type _lst_p = &(items); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ kscsat_IdList _val = ((kscsat_IdList){.items = items}); slop_map_put(arena, m, &(uint32_t){k}, &_val, sizeof(_val)); });
        return 1;
    }
}

uint8_t kscsat_ri_push(slop_arena* arena, slop_map* m, uint32_t k, uint32_t v, uint32_t i) {
    {
        __auto_type rf = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(m, &(uint32_t){k}); _ptr ? (slop_option_kscsat_RoleIds){ .has_value = true, .value = *(kscsat_RoleIds*)_ptr } : (slop_option_kscsat_RoleIds){ .has_value = false }; }); _mv.has_value ? ({ __auto_type r = _mv.value; r; }) : (({ __auto_type fresh = ((kscsat_RoleIds){.by_role = ({ static const slop_map_desc _d = SLOP_MAP_DESC(uint32_t, slop_hash_u32, slop_eq_u32, SLOP_KEY_BITS, kscsat_IdList); slop_map_new_ptr(arena, 0, &_d); })}); ({ ({ kscsat_RoleIds _val = fresh; slop_map_put(arena, m, &(uint32_t){k}, &_val, sizeof(_val)); }); fresh; }); })); });
        return kscsat_il_push(arena, rf.by_role, v, i);
    }
}

types_KElem kscsat_fact_subject(types_KFact f) {
    __auto_type _mv_804 = f;
    switch (_mv_804.tag) {
        case types_KFact_f_inst:
        {
            __auto_type x = _mv_804.data.f_inst.f0;
            return x;
        }
        case types_KFact_f_triple:
        {
            __auto_type x = _mv_804.data.f_triple.f0;
            return x;
        }
        case types_KFact_f_self:
        {
            __auto_type x = _mv_804.data.f_self.f0;
            return x;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t kscsat_is_safe(kscsat_Base b, types_KElem x) {
    return !(slop_map_has(b.unsafe, &(x)));
}

uint8_t kscsat_store_holds(kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f) {
    {
        __auto_type c = kscids_encode_fact(st.ids, f);
        if (slop_map_has(st.seen, &(c))) {
            return 1;
        } else {
            __auto_type _mv_807 = base;
            if (_mv_807.has_value) {
                __auto_type b = _mv_807.value;
                if (slop_map_has(b.g.seen, &(c))) {
                    return 1;
                } else {
                    if (kscsat_is_safe(b, kscsat_fact_subject(f))) {
                        return slop_map_has(b.w.seen, &(c));
                    } else {
                        return 0;
                    }
                }
            } else if (!_mv_807.has_value) {
                return 0;
            }
            SLOP_UNREACHABLE();
        }
    }
}

uint8_t kscsat_commit(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KFact f) {
    if (kscsat_store_holds(st, base, f)) {
        return 0;
    } else {
        {
            __auto_type c = kscids_encode_fact(st.ids, f);
            ({ slop_map_put(arena, st.seen, &(c), NULL, 0); });
            __auto_type _mv_811 = f;
            switch (_mv_811.tag) {
                case types_KFact_f_inst:
                {
                    __auto_type x = _mv_811.data.f_inst.f0;
                    __auto_type y = _mv_811.data.f_inst.f1;
                    kscsat_il_push(arena, st.insts, c.a, c.b);
                    if (ksc_ksc_4(x, y)) {
                        ({ slop_map_put(arena, st.bots, &(x), NULL, 0); });
                    }
                    if (ksc_is_nominal(y)) {
                        ({ slop_map_put(arena, st.noms_at, &(x), NULL, 0); });
                        kscsat_il_push(arena, st.noms, c.a, c.b);
                        kscsat_il_push(arena, st.holders, kscids_elem_id(st.ids, ksc_term_elem(y)), c.a);
                    }
                    break;
                }
                case types_KFact_f_triple:
                {
                    kscsat_ri_push(arena, st.outs, c.a, c.b, c.c);
                    kscsat_ri_push(arena, st.ins, c.c, c.b, c.a);
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
}

slop_option_list_u32 kscsat_id_items(slop_map* m, uint32_t k) {
    __auto_type _mv_815 = ({ void* _ptr = slop_map_get(m, &(uint32_t){k}); _ptr ? (slop_option_kscsat_IdList){ .has_value = true, .value = *(kscsat_IdList*)_ptr } : (slop_option_kscsat_IdList){ .has_value = false }; });
    if (_mv_815.has_value) {
        __auto_type l = _mv_815.value;
        return (slop_option_list_u32){.has_value = 1, .value = l.items};
    } else if (!_mv_815.has_value) {
        return (slop_option_list_u32){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

slop_map* kscsat_field_map(kscsat_KStore st, kscsat_Field fd) {
    __auto_type _mv_816 = fd;
    if (_mv_816 == kscsat_Field_fd_insts) {
        return st.insts;
    } else if (_mv_816 == kscsat_Field_fd_noms) {
        return st.noms;
    } else if (_mv_816 == kscsat_Field_fd_holders) {
        return st.holders;
    }
    SLOP_UNREACHABLE();
}

uint8_t kscsat_keyed_by_subject(kscsat_Field fd) {
    __auto_type _mv_817 = fd;
    if (_mv_817 == kscsat_Field_fd_insts) {
        return 1;
    } else if (_mv_817 == kscsat_Field_fd_noms) {
        return 1;
    } else if (_mv_817 == kscsat_Field_fd_holders) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_list_types_KFact kscsat_field_items(slop_arena* arena, kscsat_KStore st, kscsat_Field fd, types_KElem k) {
    {
        __auto_type out = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_818 = kscsat_id_items(kscsat_field_map(st, fd), kscids_elem_id(st.ids, k));
        if (_mv_818.has_value) {
            __auto_type is = _mv_818.value;
            if (kscsat_keyed_by_subject(fd)) {
                {
                    __auto_type _coll = is;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type i = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = k, .f1 = kscids_id_term(st.ids, i) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            } else {
                __auto_type _mv_819 = k;
                switch (_mv_819.tag) {
                    case types_KElem_e_ind:
                    {
                        __auto_type a = _mv_819.data.e_ind;
                        {
                            __auto_type y = types_nominal_term(a);
                            {
                                __auto_type _coll = is;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type i = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((types_KFact){ .tag = types_KFact_f_inst, .data.f_inst = { .f0 = kscids_id_elem(st.ids, i), .f1 = y } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                        break;
                    }
                    case types_KElem_e_aux:
                    {
                        __auto_type _ = _mv_819.data.e_aux;
                        break;
                    }
                    case types_KElem_e_class:
                    {
                        __auto_type _ = _mv_819.data.e_class;
                        break;
                    }
                }
            }
        } else if (!_mv_818.has_value) {
        }
        return out;
    }
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
        __auto_type _mv_820 = base;
        if (_mv_820.has_value) {
            __auto_type b = _mv_820.value;
            ({ __auto_type _lst_p = &(out); __auto_type _item = (kscsat_field_items(arena, b.g, fd, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            if (kscsat_is_safe(b, k)) {
                ({ __auto_type _lst_p = &(out); __auto_type _item = (kscsat_w_items(arena, b, kscsat_keyed_by_subject(fd), k, kscsat_field_items(arena, b.w, fd, k))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        } else if (!_mv_820.has_value) {
        }
        ({ __auto_type _lst_p = &(out); __auto_type _item = (kscsat_field_items(arena, st, fd, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
}

slop_list_types_KFact kscsat_leg_facts(slop_arena* arena, kscids_KscIds ids, uint8_t outward, types_KElem k, uint32_t e, slop_list_u32 is) {
    {
        __auto_type out = ((slop_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type r = kscids_id_role(ids, e);
        {
            __auto_type _coll = is;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (((outward) ? ((types_KFact){ .tag = types_KFact_f_triple, .data.f_triple = { .f0 = k, .f1 = r, .f2 = kscids_id_elem(ids, i) } }) : ((types_KFact){ .tag = types_KFact_f_triple, .data.f_triple = { .f0 = kscids_id_elem(ids, i), .f1 = r, .f2 = k } }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_list_types_KFact kscsat_all_ins(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KElem k) {
    {
        __auto_type out = ((slop_list_list_types_KFact){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type _mv_821 = base;
        if (_mv_821.has_value) {
            __auto_type b = _mv_821.value;
            {
                __auto_type _coll = kscsat_legs_in_store(arena, b.g, 0, k, ((slop_option_kscsat_Under){.has_value = false}));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type lg = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (lg.facts); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            if (kscsat_is_safe(b, k)) {
                {
                    __auto_type _coll = kscsat_legs_in_store(arena, b.w, 0, k, ((slop_option_kscsat_Under){.has_value = false}));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type lg = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (kscsat_w_items(arena, b, 0, k, lg.facts)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        } else if (!_mv_821.has_value) {
        }
        {
            __auto_type _coll = kscsat_legs_in_store(arena, st, 0, k, ((slop_option_kscsat_Under){.has_value = false}));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type lg = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (lg.facts); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_map* kscsat_side_map(kscsat_KStore st, uint8_t outward) {
    if (outward) {
        return st.outs;
    } else {
        return st.ins;
    }
}

slop_list_kscsat_RoleLegs kscsat_legs_in_store(slop_arena* arena, kscsat_KStore st, uint8_t outward, types_KElem k, slop_option_kscsat_Under under) {
    {
        __auto_type out = ((slop_list_kscsat_RoleLegs){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type ids = st.ids;
        {
            __auto_type kid = kscids_elem_id(ids, k);
            __auto_type _mv_823 = ({ void* _ptr = slop_map_get(kscsat_side_map(st, outward), &(uint32_t){kid}); _ptr ? (slop_option_kscsat_RoleIds){ .has_value = true, .value = *(kscsat_RoleIds*)_ptr } : (slop_option_kscsat_RoleIds){ .has_value = false }; });
            if (_mv_823.has_value) {
                __auto_type rf = _mv_823.value;
                __auto_type _mv_824 = under;
                if (!_mv_824.has_value) {
                    {
                        slop_map* _coll = (slop_map*)rf.by_role;
                        for (size_t _i = 0; _i < _coll->len; _i++) {
                            {
                                uint32_t e = *(uint32_t*)slop_map_key_at(_coll, _i);
                                kscsat_IdList il = *(kscsat_IdList*)slop_map_value_at(_coll, _i);
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (((kscsat_RoleLegs){.role = kscids_id_role(ids, e), .facts = kscsat_leg_facts(arena, ids, outward, k, e, il.items)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            }
                        }
                    }
                } else if (_mv_824.has_value) {
                    __auto_type u = _mv_824.value;
                    {
                        __auto_type subs = kscpremise_role_subs(arena, u.idx, u.v);
                        if (((int64_t)(rf.by_role)->len) <= ((int64_t)((subs).len))) {
                            {
                                slop_map* _coll = (slop_map*)rf.by_role;
                                for (size_t _i = 0; _i < _coll->len; _i++) {
                                    {
                                        uint32_t e = *(uint32_t*)slop_map_key_at(_coll, _i);
                                        kscsat_IdList il = *(kscsat_IdList*)slop_map_value_at(_coll, _i);
                                        {
                                            __auto_type r = kscids_id_role(ids, e);
                                            if (kscpremise_role_under(u.idx, r, u.v)) {
                                                ({ __auto_type _lst_p = &(out); __auto_type _item = (((kscsat_RoleLegs){.role = r, .facts = kscsat_leg_facts(arena, ids, outward, k, e, il.items)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            {
                                __auto_type _coll = subs;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type r = _coll.data[_i];
                                    {
                                        __auto_type e = kscids_role_id(ids, r);
                                        __auto_type _mv_826 = ({ void* _ptr = slop_map_get(rf.by_role, &(uint32_t){e}); _ptr ? (slop_option_kscsat_IdList){ .has_value = true, .value = *(kscsat_IdList*)_ptr } : (slop_option_kscsat_IdList){ .has_value = false }; });
                                        if (_mv_826.has_value) {
                                            __auto_type il = _mv_826.value;
                                            ({ __auto_type _lst_p = &(out); __auto_type _item = (((kscsat_RoleLegs){.role = r, .facts = kscsat_leg_facts(arena, ids, outward, k, e, il.items)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        } else if (!_mv_826.has_value) {
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else if (!_mv_823.has_value) {
            }
        }
        return out;
    }
}

slop_list_kscsat_RoleLegs kscsat_role_legs(slop_arena* arena, kscpremise_KscIndex idx, kscsat_KStore st, slop_option_kscsat_Base base, uint8_t outward, types_KElem k, types_RoleId v) {
    {
        __auto_type out = ((slop_list_kscsat_RoleLegs){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type u = (slop_option_kscsat_Under){.has_value = 1, .value = ((kscsat_Under){.idx = idx, .v = v})};
        __auto_type _mv_827 = base;
        if (_mv_827.has_value) {
            __auto_type b = _mv_827.value;
            {
                __auto_type _coll = kscsat_legs_in_store(arena, b.g, outward, k, u);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type lg = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (lg); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            if (kscsat_is_safe(b, k)) {
                {
                    __auto_type _coll = kscsat_legs_in_store(arena, b.w, outward, k, u);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type lg = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (((kscsat_RoleLegs){.role = lg.role, .facts = kscsat_w_items(arena, b, outward, k, lg.facts)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        } else if (!_mv_827.has_value) {
        }
        {
            __auto_type _coll = kscsat_legs_in_store(arena, st, outward, k, u);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type lg = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (lg); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_list_u32 kscsat_inst_id_lists(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KElem x) {
    {
        __auto_type out = ((slop_list_list_u32){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type xi = kscids_elem_id(st.ids, x);
        __auto_type _mv_828 = base;
        if (_mv_828.has_value) {
            __auto_type b = _mv_828.value;
            __auto_type _mv_829 = kscsat_id_items(b.g.insts, xi);
            if (_mv_829.has_value) {
                __auto_type l = _mv_829.value;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_829.has_value) {
            }
            if (kscsat_is_safe(b, x)) {
                __auto_type _mv_830 = kscsat_id_items(b.w.insts, xi);
                if (_mv_830.has_value) {
                    __auto_type l = _mv_830.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_830.has_value) {
                }
            }
        } else if (!_mv_828.has_value) {
        }
        __auto_type _mv_831 = kscsat_id_items(st.insts, xi);
        if (_mv_831.has_value) {
            __auto_type l = _mv_831.value;
            ({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (!_mv_831.has_value) {
        }
        return out;
    }
}

slop_list_kscsat_Match kscsat_partner_matches(slop_arena* arena, kscsat_KStore st, slop_option_kscsat_Base base, types_KElem x, kscpremise_KPartners p) {
    {
        __auto_type lists = kscsat_inst_id_lists(arena, st, base, x);
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
                            __auto_type i = _coll.data[_i];
                            {
                                __auto_type z = kscids_id_term(st.ids, i);
                                __auto_type _mv_833 = ({ void* _ptr = slop_map_get(p.by_other, &(z)); _ptr ? (slop_option_kscpremise_KList){ .has_value = true, .value = *(kscpremise_KList*)_ptr } : (slop_option_kscpremise_KList){ .has_value = false }; });
                                if (_mv_833.has_value) {
                                    __auto_type axl = _mv_833.value;
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((kscsat_Match){.other = z, .axioms = axl})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                } else if (!_mv_833.has_value) {
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
        __auto_type _mv_834 = f;
        switch (_mv_834.tag) {
            case types_KFact_f_inst:
            {
                __auto_type x = _mv_834.data.f_inst.f0;
                __auto_type y = _mv_834.data.f_inst.f1;
                {
                    __auto_type c = ksc_ksc_3(x, y);
                    if (c.fires) {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
                __auto_type _mv_835 = kscpremise_term_bucket(idx, y);
                if (_mv_835.has_value) {
                    __auto_type bucket = _mv_835.value;
                    {
                        __auto_type _coll = bucket.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ax = _coll.data[_i];
                            __auto_type _mv_836 = ax;
                            switch (_mv_836.tag) {
                                case types_KscAxiom_k_sub:
                                {
                                    __auto_type sy = _mv_836.data.k_sub.f0;
                                    __auto_type sz = _mv_836.data.k_sub.f1;
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
                                    __auto_type v = _mv_836.data.k_some_lhs.f0;
                                    __auto_type a = _mv_836.data.k_some_lhs.f1;
                                    __auto_type z = _mv_836.data.k_some_lhs.f2;
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
                                    __auto_type a = _mv_836.data.k_some_rhs.f0;
                                    __auto_type v = _mv_836.data.k_some_rhs.f1;
                                    __auto_type b = _mv_836.data.k_some_rhs.f2;
                                    __auto_type w = _mv_836.data.k_some_rhs.f3;
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
                                    __auto_type a = _mv_836.data.k_role_assert.f0;
                                    __auto_type v = _mv_836.data.k_role_assert.f1;
                                    __auto_type b = _mv_836.data.k_role_assert.f2;
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
                                    __auto_type a = _mv_836.data.k_self_rhs.f0;
                                    __auto_type v = _mv_836.data.k_self_rhs.f1;
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
                } else if (!_mv_835.has_value) {
                }
                __auto_type _mv_837 = kscpremise_and_partners(idx, y);
                if (_mv_837.has_value) {
                    __auto_type p = _mv_837.value;
                    {
                        __auto_type _coll = kscsat_partner_matches(arena, st, base, x, p);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type m = _coll.data[_i];
                            {
                                __auto_type _coll = m.axioms.items;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type ax = _coll.data[_i];
                                    __auto_type _mv_838 = ax;
                                    switch (_mv_838.tag) {
                                        case types_KscAxiom_k_and:
                                        {
                                            __auto_type a = _mv_838.data.k_and.f0;
                                            __auto_type b = _mv_838.data.k_and.f1;
                                            __auto_type z = _mv_838.data.k_and.f2;
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
                } else if (!_mv_837.has_value) {
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
                __auto_type x = _mv_834.data.f_triple.f0;
                __auto_type e = _mv_834.data.f_triple.f1;
                __auto_type x1 = _mv_834.data.f_triple.f2;
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
                            __auto_type _mv_839 = kscpremise_role_bucket(idx, v);
                            if (_mv_839.has_value) {
                                __auto_type bucket = _mv_839.value;
                                {
                                    __auto_type _coll = bucket.items;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type ax = _coll.data[_i];
                                        __auto_type _mv_840 = ax;
                                        switch (_mv_840.tag) {
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
                                                __auto_type u = _mv_840.data.k_chain.f0;
                                                __auto_type v2 = _mv_840.data.k_chain.f1;
                                                __auto_type w = _mv_840.data.k_chain.f2;
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
                                                __auto_type v2 = _mv_840.data.k_range.f0;
                                                __auto_type d = _mv_840.data.k_range.f1;
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
                            } else if (!_mv_839.has_value) {
                            }
                            __auto_type _mv_841 = kscpremise_ex_partners(idx, v);
                            if (_mv_841.has_value) {
                                __auto_type p = _mv_841.value;
                                {
                                    __auto_type _coll = kscsat_partner_matches(arena, st, base, x1, p);
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type m = _coll.data[_i];
                                        {
                                            __auto_type _coll = m.axioms.items;
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type ax = _coll.data[_i];
                                                __auto_type _mv_842 = ax;
                                                switch (_mv_842.tag) {
                                                    case types_KscAxiom_k_some_lhs:
                                                    {
                                                        __auto_type v2 = _mv_842.data.k_some_lhs.f0;
                                                        __auto_type a = _mv_842.data.k_some_lhs.f1;
                                                        __auto_type z = _mv_842.data.k_some_lhs.f2;
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
                            } else if (!_mv_841.has_value) {
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
                __auto_type x = _mv_834.data.f_self.f0;
                __auto_type v = _mv_834.data.f_self.f1;
                __auto_type _mv_843 = kscpremise_role_bucket(idx, v);
                if (_mv_843.has_value) {
                    __auto_type bucket = _mv_843.value;
                    {
                        __auto_type _coll = bucket.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ax = _coll.data[_i];
                            __auto_type _mv_844 = ax;
                            switch (_mv_844.tag) {
                                case types_KscAxiom_k_some_lhs:
                                {
                                    break;
                                }
                                case types_KscAxiom_k_self_lhs:
                                {
                                    __auto_type v2 = _mv_844.data.k_self_lhs.f0;
                                    __auto_type z = _mv_844.data.k_self_lhs.f1;
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
                                    __auto_type v2 = _mv_844.data.k_role.f0;
                                    __auto_type w = _mv_844.data.k_role.f1;
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
                                    __auto_type u = _mv_844.data.k_chain.f0;
                                    __auto_type v2 = _mv_844.data.k_chain.f1;
                                    __auto_type w = _mv_844.data.k_chain.f2;
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
                                    __auto_type v2 = _mv_844.data.k_range.f0;
                                    __auto_type d = _mv_844.data.k_range.f1;
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
                } else if (!_mv_843.has_value) {
                }
                __auto_type _mv_845 = kscpremise_ex_partners(idx, v);
                if (_mv_845.has_value) {
                    __auto_type p = _mv_845.value;
                    {
                        __auto_type _coll = kscsat_partner_matches(arena, st, base, x, p);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type m = _coll.data[_i];
                            {
                                __auto_type _coll = m.axioms.items;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type ax = _coll.data[_i];
                                    __auto_type _mv_846 = ax;
                                    switch (_mv_846.tag) {
                                        case types_KscAxiom_k_some_lhs:
                                        {
                                            __auto_type v2 = _mv_846.data.k_some_lhs.f0;
                                            __auto_type a = _mv_846.data.k_some_lhs.f1;
                                            __auto_type z = _mv_846.data.k_some_lhs.f2;
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
                } else if (!_mv_845.has_value) {
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
    __auto_type _mv_847 = f;
    switch (_mv_847.tag) {
        case types_KFact_f_inst:
        {
            __auto_type u = _mv_847.data.f_inst.f0;
            __auto_type z = _mv_847.data.f_inst.f1;
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
    __auto_type _mv_848 = base;
    if (_mv_848.has_value) {
        __auto_type b = _mv_848.value;
        __auto_type _mv_849 = f;
        switch (_mv_849.tag) {
            case types_KFact_f_triple:
            {
                __auto_type s = _mv_849.data.f_triple.f2;
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
    } else if (!_mv_848.has_value) {
        _retval = 0;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

slop_list_types_KFact kscsat_delta_push(slop_arena* na, slop_list_types_KFact l, types_KFact c) {
    {
        __auto_type out = l;
        ({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(na, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        return out;
    }
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
                                next = kscsat_delta_push(na, next, c);
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

kscsat_RunResult kscsat_run_ksc(slop_arena* arena, kscpremise_KscIndex idx, kscids_KscIds ids, slop_option_kscsat_Base base, slop_list_types_KFact seeds, uint8_t stop_at_bottom, int64_t budget, int64_t cancel) {
    {
        __auto_type st = kscsat_new_store(arena, ids);
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
            __auto_type _coll = kscsat_field_items(arena, st, kscsat_Field_fd_insts, types_class_elem(q));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                __auto_type _mv_851 = f;
                switch (_mv_851.tag) {
                    case types_KFact_f_inst:
                    {
                        __auto_type y = _mv_851.data.f_inst.f1;
                        __auto_type _mv_852 = y;
                        switch (_mv_852.tag) {
                            case types_KTerm_k_name:
                            {
                                __auto_type n = _mv_852.data.k_name;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (kscnormal_copy_kname(arena, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case types_KTerm_k_nominal:
                            {
                                __auto_type _ = _mv_852.data.k_nominal;
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
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(uint32_t, slop_hash_u32, slop_eq_u32, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type ids = w.ids;
        __auto_type work = ((slop_list_u32){ .data = NULL, .len = 0, .cap = 0 });
        int64_t i = 0;
        {
            __auto_type _coll = start;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                ({ slop_map_put(arena, out, &(x), NULL, 0); });
                {
                    __auto_type xi = kscids_elem_id(ids, x);
                    if (!(slop_map_has(seen, &(uint32_t){xi}))) {
                        ({ slop_map_put(arena, seen, &(uint32_t){xi}, NULL, 0); });
                        ({ __auto_type _lst_p = &(work); __auto_type _item = (xi); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        while (i < ((int64_t)(((int64_t)((work).len))))) {
            __auto_type _mv_856 = ({ __auto_type _lst = work; size_t _idx = (size_t)i; slop_option_u32 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_856.has_value) {
                __auto_type xi = _mv_856.value;
                __auto_type _mv_858 = ({ void* _ptr = slop_map_get(w.ins, &(uint32_t){xi}); _ptr ? (slop_option_kscsat_RoleIds){ .has_value = true, .value = *(kscsat_RoleIds*)_ptr } : (slop_option_kscsat_RoleIds){ .has_value = false }; });
                if (_mv_858.has_value) {
                    __auto_type rf = _mv_858.value;
                    {
                        slop_map* _coll = (slop_map*)rf.by_role;
                        for (size_t _i = 0; _i < _coll->len; _i++) {
                            {
                                uint32_t v = *(uint32_t*)slop_map_key_at(_coll, _i);
                                kscsat_IdList il = *(kscsat_IdList*)slop_map_value_at(_coll, _i);
                                {
                                    __auto_type _coll = il.items;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type pi = _coll.data[_i];
                                        if (!(slop_map_has(seen, &(uint32_t){pi}))) {
                                            ({ slop_map_put(arena, seen, &(uint32_t){pi}, NULL, 0); });
                                            ({ types_KElem _key_861 = (kscids_id_elem(ids, pi)); slop_map_put(arena, out, &_key_861, NULL, 0); });
                                            ({ __auto_type _lst_p = &(work); __auto_type _item = (pi); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if (!_mv_858.has_value) {
                }
            } else if (!_mv_856.has_value) {
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
            __auto_type r = kscsat_run_ksc(scratch, idx, base.g.ids, (slop_option_kscsat_Base){.has_value = 1, .value = base}, qseeds, 1, budget, cancel);
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
    _retval = ((types_ClassAnswer){.cls = q, .shared = 1, .unsat = ((g_unsat) ? 1 : ({ types_KElem _key_862 = (types_class_elem(q)); slop_map_has(base.botreach, &_key_862); })), .subsumers = kscsat_answer_subsumers(arena, base.w, q), .complete = 1, .rounds = 0, .facts = 0});
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
        __auto_type ids = kscids_build_ksc_ids(arena, axioms, classes, idx.individuals);
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
            __auto_type g = kscsat_run_ksc(arena, idx, ids, ((slop_option_kscsat_Base){.has_value = false}), gseeds, 1, n, config.cancel_ptr);
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
                            __auto_type w = kscsat_run_ksc(arena, idx, ids, ((slop_option_kscsat_Base){.has_value = false}), wseeds, 0, (n - g.rounds), config.cancel_ptr);
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
        __auto_type _mv_863 = kscsat_classify_renamed(arena, kscnames_rename_ksc_axioms(arena, nm, axioms), kscnames_rename_classes(arena, nm, classes), config);
        if (!_mv_863.is_ok) {
            __auto_type f = _mv_863.data.err;
            return ((slop_result_types_KscResult_types_Fault){ .is_ok = false, .data.err = f });
        } else if (_mv_863.is_ok) {
            __auto_type r = _mv_863.data.ok;
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
                    __auto_type _mv_864 = ({ __auto_type _lst = classes; size_t _idx = (size_t)i; slop_option_types_KName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_864.has_value) {
                        __auto_type q = _mv_864.value;
                        __auto_type _mv_865 = kscsat_class_run(wa, idx, base, 0, budget, cancel, q);
                        if (_mv_865.has_value) {
                            __auto_type a = _mv_865.value;
                            ({ types_ClassAnswer _val = a; slop_map_put(wa, out, &(int64_t){i}, &_val, sizeof(_val)); });
                        } else if (!_mv_865.has_value) {
                            cancelled = 1;
                        }
                    } else if (!_mv_864.has_value) {
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
            __auto_type _mv_867 = ({ __auto_type _lst = xs; size_t _idx = (size_t)j; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_867.has_value) {
                __auto_type x = _mv_867.value;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_867.has_value) {
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
            __auto_type _mv_868 = thing_run;
            if (!_mv_868.has_value) {
                return ((slop_result_types_KscResult_types_Fault){ .is_ok = false, .data.err = ((types_Fault){ .tag = types_Fault_cancelled }) });
            } else if (_mv_868.has_value) {
                __auto_type thing_answer = _mv_868.value;
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
                                ({ __auto_type _lst_p = &(threads); __auto_type _item = (({ slop_closure_t _spawn_cl = ({ kscsat__lambda_870_env_t* kscsat__lambda_870_env = (kscsat__lambda_870_env_t*)slop_arena_alloc(arena, sizeof(kscsat__lambda_870_env_t)); *kscsat__lambda_870_env = (kscsat__lambda_870_env_t){ .wa = wa, .idx = idx, .base = base, .budget = budget, .cancel = cancel, .classes = classes, .chunk = chunk, .out = out }; (slop_closure_t){ (void*)kscsat__lambda_870, (void*)kscsat__lambda_870_env }; }); slop_thread_int* _spawn_th = slop_arena_alloc(arena, sizeof(slop_thread_int)); _spawn_th->func = _spawn_cl.fn; _spawn_th->env = _spawn_cl.env; _spawn_th->done = false; pthread_create(&_spawn_th->id, NULL, (void*)slop_thread_int_entry, (void*)_spawn_th); _spawn_th; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                            __auto_type _mv_872 = ({ void* _ptr = slop_map_get(shared, &(int64_t){i}); _ptr ? (slop_option_types_ClassAnswer){ .has_value = true, .value = *(types_ClassAnswer*)_ptr } : (slop_option_types_ClassAnswer){ .has_value = false }; });
                            if (_mv_872.has_value) {
                                __auto_type a = _mv_872.value;
                                ({ __auto_type _lst_p = &(answers); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            } else if (!_mv_872.has_value) {
                                {
                                    __auto_type _coll = outs;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type out = _coll.data[_i];
                                        __auto_type _mv_874 = ({ void* _ptr = slop_map_get(out, &(int64_t){i}); _ptr ? (slop_option_types_ClassAnswer){ .has_value = true, .value = *(types_ClassAnswer*)_ptr } : (slop_option_types_ClassAnswer){ .has_value = false }; });
                                        if (_mv_874.has_value) {
                                            __auto_type a = _mv_874.value;
                                            if (!(a.complete)) {
                                                complete = 0;
                                            }
                                            ({ __auto_type _lst_p = &(answers); __auto_type _item = (kscsat_copy_answer(arena, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        } else if (!_mv_874.has_value) {
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

