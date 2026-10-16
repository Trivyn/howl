#include "../runtime/slop_runtime.h"
#include "slop_gate.h"

howl_types_InputRef howl_gate_axiom_input_ref(slop_arena* arena, howl_owl2_RawAxiom ax);
slop_option_howl_types_RoleId howl_gate_least_role(slop_list_howl_types_RoleId rs);
howl_owl2_RawAxiom howl_gate_transitive_chain(slop_arena* arena, howl_types_RoleId r);
slop_list_howl_owl2_RawAxiom howl_gate_push_property_star(slop_list_howl_owl2_RawAxiom out, howl_owl2_RawAxiom ax, slop_list_howl_types_RoleId rs);
slop_list_howl_owl2_RawAxiom howl_gate_push_class_star(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, slop_list_howl_owl2_RawConcept cs);
slop_list_howl_owl2_RawAxiom howl_gate_push_pairs_from(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, slop_list_howl_owl2_RawConcept sorted, int64_t i, int64_t n);
slop_list_howl_owl2_RawAxiom howl_gate_push_disjoint_pairs(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, howl_owl2_RawAxiom ax, slop_list_howl_owl2_RawConcept cs);
slop_list_howl_owl2_RawAxiom howl_gate_expand_sugar(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
uint8_t howl_gate_has_negated_conjunct(howl_owl2_RawConcept c);
slop_list_howl_owl2_RawConcept howl_gate_conjuncts(slop_arena* arena, howl_owl2_RawConcept c);
howl_gate_NegSplit howl_gate_negation_split(slop_arena* arena, howl_owl2_RawConcept c);
uint8_t howl_gate_split_rewritable(howl_types_Profile p, howl_gate_NegSplit s);
howl_owl2_RawConcept howl_gate_conjunction(slop_list_howl_owl2_RawConcept cs);
howl_owl2_RawConcept howl_gate_with_conjunct(slop_arena* arena, howl_owl2_RawConcept c, howl_owl2_RawConcept e);
howl_owl2_RawAxiom howl_gate_empty_axiom(slop_arena* arena, howl_owl2_RawConcept c);
slop_option_howl_gate_NegSplit howl_gate_sub_negation_split(slop_arena* arena, howl_types_Profile p, howl_owl2_RawConcept l, howl_owl2_RawConcept r);
slop_option_howl_gate_NegSplit howl_gate_role_negation_split(slop_arena* arena, howl_types_Profile p, howl_types_RoleId r, howl_owl2_RawConcept c);
slop_list_howl_owl2_RawAxiom howl_gate_push_sub_pieces(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, howl_owl2_RawConcept* l, howl_gate_NegSplit s);
slop_list_howl_owl2_RawAxiom howl_gate_push_domain_pieces(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, howl_types_RoleId r, howl_gate_NegSplit s);
slop_list_howl_owl2_RawAxiom howl_gate_push_range_pieces(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, howl_types_RoleId r, howl_gate_NegSplit s);
slop_list_howl_owl2_RawAxiom howl_gate_expand_negation(slop_arena* arena, howl_types_Profile p, slop_list_howl_owl2_RawAxiom axs);
uint8_t howl_gate_is_top_role(howl_types_RoleId r);
uint8_t howl_gate_is_inverse_role(howl_types_RoleId r);
uint8_t howl_gate_roles_have_inverse(slop_list_howl_types_RoleId rs);
uint8_t howl_gate_axiom_has_inverse(howl_owl2_RawAxiom ax);
slop_list_howl_owl2_RawAxiom howl_gate_named_roles_only(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
uint8_t howl_gate_into_top_role(howl_owl2_RawAxiom ax);
slop_list_howl_owl2_RawAxiom howl_gate_drop_top_role_tautologies(slop_arena* arena, howl_types_Profile p, slop_list_howl_owl2_RawAxiom axs);
uint8_t howl_gate_role_listed(slop_list_howl_types_RoleId rs, howl_types_RoleId r);
slop_list_howl_types_RoleId howl_gate_non_simple_roles(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
uint8_t howl_gate_concept_self_roles_simple(slop_list_howl_types_RoleId nonsimple, howl_owl2_RawConcept c);
uint8_t howl_gate_self_roles_simple(slop_list_howl_types_RoleId nonsimple, howl_owl2_RawAxiom ax);
howl_owl2_RawConcept* howl_gate_box_c(slop_arena* arena, howl_owl2_RawConcept c);
slop_list_howl_owl2_RawAxiom howl_gate_admitted(slop_arena* arena, howl_types_Profile p, slop_list_howl_owl2_RawAxiom axs);
uint8_t howl_gate_is_rbox_axiom(howl_owl2_RawAxiom ax);
uint8_t howl_gate_axiom_range_ok(slop_list_howl_gate_RangeEntry entries, slop_list_u8 told, int64_t n, slop_list_howl_types_RoleId roles, howl_owl2_RawAxiom ax);
howl_gate_GateResult howl_gate_gate_axioms(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, howl_owl2_Signature sig, slop_list_howl_types_Omission carried, howl_types_Profile p);
slop_list_howl_owl2_RawAxiom howl_gate_gate_expand(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, howl_types_Profile p);
uint8_t howl_gate_piece_read(howl_types_Profile p, howl_owl2_RawAxiom ax);
uint8_t howl_gate_piece_omitted(howl_types_Profile p, howl_owl2_RawAxiom ax);
slop_list_howl_owl2_RawAxiom howl_gate_one_axiom(slop_arena* arena, howl_owl2_RawAxiom ax);
uint8_t howl_gate_unread_by_every(slop_arena* arena, howl_owl2_RawAxiom ax, slop_list_howl_types_Profile rungs);
uint8_t howl_gate_module_omissions_shared(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_list_howl_types_Omission carried, slop_list_howl_types_Omission oms, howl_types_Profile p, slop_list_howl_types_Profile rungs);
slop_list_int howl_gate_omission_origins(slop_arena* arena, slop_arena* scratch, slop_list_howl_types_Omission oms, slop_list_howl_owl2_RawAxiom axs, slop_list_int adocs, slop_list_howl_types_Omission carried, slop_list_int cdocs, int64_t documents, howl_types_Profile p);
slop_map* howl_gate_needed_texts(slop_arena* arena, slop_list_howl_types_Omission oms);
slop_map* howl_gate_texts_to_docs(slop_arena* arena, slop_map* needed, slop_list_howl_owl2_RawAxiom axs, slop_list_int adocs, howl_types_Profile p);
slop_list_int howl_gate_insert_ascending(slop_arena* arena, slop_list_int xs, int64_t x);
int64_t howl_gate_nth_doc(slop_map* by_text, slop_string t, int64_t k);
int64_t howl_gate_carried_doc(howl_types_Omission o, slop_list_howl_types_Omission carried, slop_list_int cdocs);
uint8_t howl_gate_rbox_omits(uint8_t sriq, uint8_t rbox_bad, howl_owl2_RawAxiom ax);
slop_list_howl_owl2_RawAxiom howl_gate_sort_axioms(slop_arena* arena, slop_list_howl_owl2_RawAxiom xs);
slop_list_string howl_gate_axiom_texts(slop_arena* arena, slop_list_howl_owl2_RawAxiom xs);
howl_owl2_RawAxiom howl_gate_axiom_at(slop_list_howl_owl2_RawAxiom xs, int64_t i);
int64_t howl_gate_role_idx(slop_list_howl_types_RoleId roles, howl_types_RoleId r);
uint8_t howl_gate_push_role_unique(slop_list_howl_types_RoleId rs, howl_types_RoleId r);
slop_list_howl_types_RoleId howl_gate_collect_rbox_roles(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
slop_list_howl_types_RoleId howl_gate_sort_roles(slop_arena* arena, slop_list_howl_types_RoleId xs);
howl_types_RoleId howl_gate_role_at(slop_list_howl_types_RoleId xs, int64_t i);
slop_list_u8 howl_gate_mat_new(slop_arena* arena, int64_t cells);
uint8_t howl_gate_mat_get(slop_list_u8 m, int64_t i);
uint8_t howl_gate_mat_or_row(slop_list_u8 m, int64_t n, int64_t k, int64_t i);
uint8_t howl_gate_mat_close_through(slop_list_u8 m, int64_t n, int64_t k);
uint8_t howl_gate_mat_close(slop_list_u8 m, int64_t n);
slop_list_u8 howl_gate_told_closure(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_list_howl_types_RoleId roles, int64_t n);
int64_t howl_gate_candidate_size(howl_owl2_RawChain ch, int64_t from, int64_t to);
uint8_t howl_gate_seen_before(slop_list_howl_types_RoleId steps, int64_t from, int64_t i);
uint8_t howl_gate_add_chain_constraints(howl_owl2_RawChain ch, slop_list_howl_types_RoleId roles, int64_t n, slop_list_u8 cmat, int64_t from, int64_t to);
slop_string howl_gate_describe_violation(slop_arena* arena, slop_list_howl_types_RoleId roles, int64_t i, int64_t j);
uint8_t howl_gate_add_dominant_case(howl_owl2_RawChain ch, slop_list_howl_types_RoleId roles, int64_t n, slop_list_u8 cmat, int64_t len, uint8_t left_ok, uint8_t right_ok);
uint8_t howl_gate_add_case_constraints(howl_owl2_RawChain ch, slop_list_howl_types_RoleId roles, int64_t n, slop_list_u8 cmat);
int64_t howl_gate_row_violation(slop_list_u8 cmat, slop_list_u8 told, int64_t n, int64_t i);
howl_gate_RboxVerdict howl_gate_regularity_verdict(slop_arena* arena, slop_list_howl_types_RoleId roles, slop_list_u8 cmat, slop_list_u8 told, int64_t n);
howl_gate_RboxVerdict howl_gate_check_regularity(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
slop_list_howl_gate_RangeEntry howl_gate_collect_ranges(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_list_howl_types_RoleId roles);
uint8_t howl_gate_has_inherited_range(slop_list_howl_gate_RangeEntry entries, slop_list_u8 told, int64_t n, int64_t base, howl_owl2_RawConcept c);
uint8_t howl_gate_chain_range_ok(slop_list_howl_gate_RangeEntry entries, slop_list_u8 told, int64_t n, slop_list_howl_types_RoleId roles, howl_owl2_RawChain ch);
howl_types_AxiomRef howl_gate_axiom_ref_of(slop_arena* arena, howl_owl2_RawAxiom ax);
slop_list_slop_rdf_rdf_IRI howl_gate_collect_concept_classes(slop_arena* arena, howl_owl2_RawConcept c, slop_list_slop_rdf_rdf_IRI acc);
slop_list_howl_gate_EntityRef howl_gate_collect_entity_refs(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
uint8_t howl_gate_entity_ref_declared(howl_owl2_Signature sig, howl_gate_EntityRef e);
uint8_t howl_gate_same_entity(howl_gate_EntityRef a, howl_gate_EntityRef b);
uint8_t howl_gate_has_entity(slop_list_howl_gate_EntityRef seen, howl_gate_EntityRef e);
howl_types_Omission howl_gate_missing_declaration_of(slop_arena* arena, howl_gate_EntityRef e, slop_list_howl_gate_EntityRef refs);
slop_list_howl_types_Omission howl_gate_missing_declarations(slop_arena* arena, howl_owl2_Signature sig, slop_list_howl_gate_EntityRef refs);

typedef struct { slop_list_string texts; } howl_gate__lambda_1113_env_t;

static int64_t howl_gate__lambda_1113(howl_gate__lambda_1113_env_t* _env, int64_t i, int64_t j) { return howl_canon_string_cmp(howl_canon_str_at(_env->texts, i), howl_canon_str_at(_env->texts, j)); }

typedef struct { slop_list_howl_types_RoleId xs; } howl_gate__lambda_1116_env_t;

static int64_t howl_gate__lambda_1116(howl_gate__lambda_1116_env_t* _env, int64_t i, int64_t j) { return howl_canon_role_cmp(howl_gate_role_at(_env->xs, i), howl_gate_role_at(_env->xs, j)); }

howl_types_InputRef howl_gate_axiom_input_ref(slop_arena* arena, howl_owl2_RawAxiom ax) {
    {
        slop_option_slop_rdf_rdf_IRI no_source = (slop_option_slop_rdf_rdf_IRI){.has_value = false};
        return ((howl_types_InputRef){ .tag = howl_types_InputRef_owl_axiom, .data.owl_axiom = ((howl_types_AxiomRef){.source = no_source, .text = howl_owl2_render_axiom(arena, ax)}) });
    }
}

slop_option_howl_types_RoleId howl_gate_least_role(slop_list_howl_types_RoleId rs) {
    {
        slop_option_howl_types_RoleId best = (slop_option_howl_types_RoleId){.has_value = false};
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                __auto_type _mv_1072 = best;
                if (!_mv_1072.has_value) {
                    best = (slop_option_howl_types_RoleId){.has_value = 1, .value = r};
                } else if (_mv_1072.has_value) {
                    __auto_type b = _mv_1072.value;
                    if (howl_canon_role_cmp(r, b) < 0) {
                        best = (slop_option_howl_types_RoleId){.has_value = 1, .value = r};
                    }
                }
            }
        }
        return best;
    }
}

howl_owl2_RawAxiom howl_gate_transitive_chain(slop_arena* arena, howl_types_RoleId r) {
    {
        __auto_type steps = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(steps); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(steps); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_property_chain, .data.ra_property_chain = ((howl_owl2_RawChain){.steps = steps, .super = r}) });
    }
}

slop_list_howl_owl2_RawAxiom howl_gate_push_property_star(slop_list_howl_owl2_RawAxiom out, howl_owl2_RawAxiom ax, slop_list_howl_types_RoleId rs) {
    {
        __auto_type o = out;
        if (howl_gate_roles_have_inverse(rs)) {
            (void)(({ __auto_type _lst_p = &(o); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        } else {
            __auto_type _mv_1073 = howl_gate_least_role(rs);
            if (!_mv_1073.has_value) {
            } else if (_mv_1073.has_value) {
                __auto_type hub = _mv_1073.value;
                {
                    __auto_type _coll = rs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type r = _coll.data[_i];
                        if (howl_canon_role_cmp(r, hub) != 0) {
                            ({ __auto_type _lst_p = &(o); __auto_type _item = (((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_sub_object_property, .data.ra_sub_object_property = { .f0 = hub, .f1 = r } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(o); __auto_type _item = (((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_sub_object_property, .data.ra_sub_object_property = { .f0 = r, .f1 = hub } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
            }
        }
        return o;
    }
}

slop_list_howl_owl2_RawAxiom howl_gate_push_class_star(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, slop_list_howl_owl2_RawConcept cs) {
    {
        __auto_type sorted = howl_owl2_sort_concepts(arena, cs);
        __auto_type n = ((int64_t)(((int64_t)((cs).len))));
        __auto_type o = out;
        int64_t i = 1;
        while (i < n) {
            {
                __auto_type hub = howl_owl2_concept_at(sorted, 0);
                __auto_type c = howl_owl2_concept_at(sorted, i);
                (void)(({ __auto_type _lst_p = &(o); __auto_type _item = (((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_sub_class_of, .data.ra_sub_class_of = { .f0 = howl_gate_box_c(arena, hub), .f1 = howl_gate_box_c(arena, c) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(o); __auto_type _item = (((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_sub_class_of, .data.ra_sub_class_of = { .f0 = howl_gate_box_c(arena, c), .f1 = howl_gate_box_c(arena, hub) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                i = (i + 1);
            }
        }
        return o;
    }
}

slop_list_howl_owl2_RawAxiom howl_gate_push_pairs_from(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, slop_list_howl_owl2_RawConcept sorted, int64_t i, int64_t n) {
    {
        __auto_type o = out;
        int64_t j = (i + 1);
        while (j < n) {
            {
                __auto_type pair = ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                (void)(({ __auto_type _lst_p = &(pair); __auto_type _item = (howl_owl2_concept_at(sorted, i)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(pair); __auto_type _item = (howl_owl2_concept_at(sorted, j)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(o); __auto_type _item = (((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_disjoint_classes, .data.ra_disjoint_classes = pair })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                j = (j + 1);
            }
        }
        return o;
    }
}

slop_list_howl_owl2_RawAxiom howl_gate_push_disjoint_pairs(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, howl_owl2_RawAxiom ax, slop_list_howl_owl2_RawConcept cs) {
    {
        __auto_type n = ((int64_t)(((int64_t)((cs).len))));
        __auto_type o = out;
        if (n <= 2) {
            (void)(({ __auto_type _lst_p = &(o); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            return o;
        } else {
            {
                __auto_type sorted = howl_owl2_sort_concepts(arena, cs);
                int64_t i = 0;
                while (i < n) {
                    o = howl_gate_push_pairs_from(arena, o, sorted, i, n);
                    i = (i + 1);
                }
                return o;
            }
        }
    }
}

slop_list_howl_owl2_RawAxiom howl_gate_expand_sugar(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs) {
    {
        __auto_type out = ((slop_list_howl_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1074 = ax;
                switch (_mv_1074.tag) {
                    case howl_owl2_RawAxiom_ra_transitive_property:
                    {
                        __auto_type r = _mv_1074.data.ra_transitive_property;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_gate_transitive_chain(arena, r)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_owl2_RawAxiom_ra_equivalent_properties:
                    {
                        __auto_type rs = _mv_1074.data.ra_equivalent_properties;
                        out = howl_gate_push_property_star(out, ax, rs);
                        break;
                    }
                    case howl_owl2_RawAxiom_ra_equivalent_classes:
                    {
                        __auto_type cs = _mv_1074.data.ra_equivalent_classes;
                        out = howl_gate_push_class_star(arena, out, cs);
                        break;
                    }
                    case howl_owl2_RawAxiom_ra_disjoint_classes:
                    {
                        __auto_type cs = _mv_1074.data.ra_disjoint_classes;
                        out = howl_gate_push_disjoint_pairs(arena, out, ax, cs);
                        break;
                    }
                    default: {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                }
            }
        }
        return out;
    }
}

uint8_t howl_gate_has_negated_conjunct(howl_owl2_RawConcept c) {
    __auto_type _mv_1075 = c;
    switch (_mv_1075.tag) {
        case howl_owl2_RawConcept_rc_not:
        {
            __auto_type _ = _mv_1075.data.rc_not;
            return 1;
        }
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_1075.data.rc_and;
            {
                uint8_t found = 0;
                {
                    __auto_type _coll = cs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        __auto_type _mv_1076 = x;
                        switch (_mv_1076.tag) {
                            case howl_owl2_RawConcept_rc_not:
                            {
                                __auto_type _ = _mv_1076.data.rc_not;
                                found = 1;
                                break;
                            }
                            default: {
                                break;
                            }
                        }
                    }
                }
                return found;
            }
        }
        default: {
            return 0;
        }
    }
}

slop_list_howl_owl2_RawConcept howl_gate_conjuncts(slop_arena* arena, howl_owl2_RawConcept c) {
    {
        __auto_type out = ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1077 = c;
        switch (_mv_1077.tag) {
            case howl_owl2_RawConcept_rc_and:
            {
                __auto_type cs = _mv_1077.data.rc_and;
                {
                    __auto_type _coll = cs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
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

howl_gate_NegSplit howl_gate_negation_split(slop_arena* arena, howl_owl2_RawConcept c) {
    {
        __auto_type pos = ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type neg = ((slop_list_howl_owl2_RawConcept){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = howl_gate_conjuncts(arena, c);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                __auto_type _mv_1078 = x;
                switch (_mv_1078.tag) {
                    case howl_owl2_RawConcept_rc_not:
                    {
                        __auto_type e = _mv_1078.data.rc_not;
                        ({ __auto_type _lst_p = &(neg); __auto_type _item = ((*e)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    default: {
                        ({ __auto_type _lst_p = &(pos); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                }
            }
        }
        return ((howl_gate_NegSplit){.pos = pos, .neg = neg});
    }
}

uint8_t howl_gate_split_rewritable(howl_types_Profile p, howl_gate_NegSplit s) {
    return (((((int64_t)((s.neg).len)) > 0)) && (howl_owl2_concepts_in_profile(p, s.pos)) && (howl_owl2_concepts_in_profile(p, s.neg)));
}

howl_owl2_RawConcept howl_gate_conjunction(slop_list_howl_owl2_RawConcept cs) {
    SLOP_PRE(((((int64_t)((cs).len)) > 0)), "(> (list-len cs) 0)");
    if (((int64_t)((cs).len)) == 1) {
        return howl_owl2_concept_at(cs, 0);
    } else {
        return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_and, .data.rc_and = cs });
    }
}

howl_owl2_RawConcept howl_gate_with_conjunct(slop_arena* arena, howl_owl2_RawConcept c, howl_owl2_RawConcept e) {
    {
        __auto_type cs = howl_gate_conjuncts(arena, c);
        (void)(({ __auto_type _lst_p = &(cs); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_and, .data.rc_and = cs });
    }
}

howl_owl2_RawAxiom howl_gate_empty_axiom(slop_arena* arena, howl_owl2_RawConcept c) {
    return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_sub_class_of, .data.ra_sub_class_of = { .f0 = howl_gate_box_c(arena, c), .f1 = howl_gate_box_c(arena, ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_nothing })) } });
}

slop_option_howl_gate_NegSplit howl_gate_sub_negation_split(slop_arena* arena, howl_types_Profile p, howl_owl2_RawConcept l, howl_owl2_RawConcept r) {
    if (!(howl_gate_has_negated_conjunct(r))) {
        return (slop_option_howl_gate_NegSplit){.has_value = false};
    } else {
        {
            __auto_type s = howl_gate_negation_split(arena, r);
            if (howl_owl2_concept_in_profile(p, l) && howl_gate_split_rewritable(p, s)) {
                return (slop_option_howl_gate_NegSplit){.has_value = 1, .value = s};
            } else {
                return (slop_option_howl_gate_NegSplit){.has_value = false};
            }
        }
    }
}

slop_option_howl_gate_NegSplit howl_gate_role_negation_split(slop_arena* arena, howl_types_Profile p, howl_types_RoleId r, howl_owl2_RawConcept c) {
    if (!(howl_gate_has_negated_conjunct(c))) {
        return (slop_option_howl_gate_NegSplit){.has_value = false};
    } else {
        {
            __auto_type s = howl_gate_negation_split(arena, c);
            if (howl_owl2_role_in_profile(p, r) && howl_gate_split_rewritable(p, s)) {
                return (slop_option_howl_gate_NegSplit){.has_value = 1, .value = s};
            } else {
                return (slop_option_howl_gate_NegSplit){.has_value = false};
            }
        }
    }
}

slop_list_howl_owl2_RawAxiom howl_gate_push_sub_pieces(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, howl_owl2_RawConcept* l, howl_gate_NegSplit s) {
    {
        __auto_type o = out;
        if (((int64_t)((s.pos).len)) > 0) {
            (void)(({ __auto_type _lst_p = &(o); __auto_type _item = (((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_sub_class_of, .data.ra_sub_class_of = { .f0 = l, .f1 = howl_gate_box_c(arena, howl_gate_conjunction(s.pos)) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        {
            __auto_type _coll = s.neg;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(o); __auto_type _item = (howl_gate_empty_axiom(arena, howl_gate_with_conjunct(arena, (*l), e))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return o;
    }
}

slop_list_howl_owl2_RawAxiom howl_gate_push_domain_pieces(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, howl_types_RoleId r, howl_gate_NegSplit s) {
    {
        __auto_type some_r = ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_some, .data.rc_some = { .f0 = r, .f1 = howl_gate_box_c(arena, ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_thing })) } });
        __auto_type o = out;
        if (((int64_t)((s.pos).len)) > 0) {
            (void)(({ __auto_type _lst_p = &(o); __auto_type _item = (((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_object_property_domain, .data.ra_object_property_domain = { .f0 = r, .f1 = howl_gate_box_c(arena, howl_gate_conjunction(s.pos)) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        {
            __auto_type _coll = s.neg;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(o); __auto_type _item = (howl_gate_empty_axiom(arena, howl_gate_with_conjunct(arena, some_r, e))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return o;
    }
}

slop_list_howl_owl2_RawAxiom howl_gate_push_range_pieces(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, howl_types_RoleId r, howl_gate_NegSplit s) {
    {
        __auto_type o = out;
        if (((int64_t)((s.pos).len)) > 0) {
            (void)(({ __auto_type _lst_p = &(o); __auto_type _item = (((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_object_property_range, .data.ra_object_property_range = { .f0 = r, .f1 = howl_gate_box_c(arena, howl_gate_conjunction(s.pos)) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        {
            __auto_type _coll = s.neg;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(o); __auto_type _item = (howl_gate_empty_axiom(arena, ((howl_owl2_RawConcept){ .tag = howl_owl2_RawConcept_rc_some, .data.rc_some = { .f0 = r, .f1 = howl_gate_box_c(arena, e) } }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return o;
    }
}

slop_list_howl_owl2_RawAxiom howl_gate_expand_negation(slop_arena* arena, howl_types_Profile p, slop_list_howl_owl2_RawAxiom axs) {
    {
        __auto_type out = ((slop_list_howl_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1079 = ax;
                switch (_mv_1079.tag) {
                    case howl_owl2_RawAxiom_ra_sub_class_of:
                    {
                        __auto_type l = _mv_1079.data.ra_sub_class_of.f0;
                        __auto_type r = _mv_1079.data.ra_sub_class_of.f1;
                        __auto_type _mv_1080 = howl_gate_sub_negation_split(arena, p, (*l), (*r));
                        if (!_mv_1080.has_value) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        } else if (_mv_1080.has_value) {
                            __auto_type s = _mv_1080.value;
                            out = howl_gate_push_sub_pieces(arena, out, l, s);
                        }
                        break;
                    }
                    case howl_owl2_RawAxiom_ra_object_property_domain:
                    {
                        __auto_type r = _mv_1079.data.ra_object_property_domain.f0;
                        __auto_type c = _mv_1079.data.ra_object_property_domain.f1;
                        __auto_type _mv_1081 = howl_gate_role_negation_split(arena, p, r, (*c));
                        if (!_mv_1081.has_value) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        } else if (_mv_1081.has_value) {
                            __auto_type s = _mv_1081.value;
                            out = howl_gate_push_domain_pieces(arena, out, r, s);
                        }
                        break;
                    }
                    case howl_owl2_RawAxiom_ra_object_property_range:
                    {
                        __auto_type r = _mv_1079.data.ra_object_property_range.f0;
                        __auto_type c = _mv_1079.data.ra_object_property_range.f1;
                        __auto_type _mv_1082 = howl_gate_role_negation_split(arena, p, r, (*c));
                        if (!_mv_1082.has_value) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        } else if (_mv_1082.has_value) {
                            __auto_type s = _mv_1082.value;
                            out = howl_gate_push_range_pieces(arena, out, r, s);
                        }
                        break;
                    }
                    default: {
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                }
            }
        }
        return out;
    }
}

uint8_t howl_gate_is_top_role(howl_types_RoleId r) {
    __auto_type _mv_1083 = r;
    switch (_mv_1083.tag) {
        case howl_types_RoleId_named_role:
        {
            __auto_type i = _mv_1083.data.named_role;
            return (howl_canon_string_cmp(i.value, slop_rdf_vocab_OWL_TOP_OBJECT_PROPERTY) == 0);
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_1083.data.fresh_role;
            return 0;
        }
        case howl_types_RoleId_inverse_role:
        {
            __auto_type _ = _mv_1083.data.inverse_role;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_gate_is_inverse_role(howl_types_RoleId r) {
    __auto_type _mv_1084 = r;
    switch (_mv_1084.tag) {
        case howl_types_RoleId_inverse_role:
        {
            __auto_type _ = _mv_1084.data.inverse_role;
            return 1;
        }
        case howl_types_RoleId_named_role:
        {
            __auto_type _ = _mv_1084.data.named_role;
            return 0;
        }
        case howl_types_RoleId_fresh_role:
        {
            __auto_type _ = _mv_1084.data.fresh_role;
            return 0;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_gate_roles_have_inverse(slop_list_howl_types_RoleId rs) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                if (howl_gate_is_inverse_role(r)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t howl_gate_axiom_has_inverse(howl_owl2_RawAxiom ax) {
    __auto_type _mv_1085 = ax;
    switch (_mv_1085.tag) {
        case howl_owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type a = _mv_1085.data.ra_sub_object_property.f0;
            __auto_type b = _mv_1085.data.ra_sub_object_property.f1;
            return (howl_gate_is_inverse_role(a) || howl_gate_is_inverse_role(b));
        }
        case howl_owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_1085.data.ra_property_chain;
            return (howl_gate_roles_have_inverse(ch.steps) || howl_gate_is_inverse_role(ch.super));
        }
        case howl_owl2_RawAxiom_ra_equivalent_properties:
        {
            __auto_type rs = _mv_1085.data.ra_equivalent_properties;
            return howl_gate_roles_have_inverse(rs);
        }
        case howl_owl2_RawAxiom_ra_transitive_property:
        {
            __auto_type r = _mv_1085.data.ra_transitive_property;
            return howl_gate_is_inverse_role(r);
        }
        case howl_owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type r = _mv_1085.data.ra_object_property_domain.f0;
            return howl_gate_is_inverse_role(r);
        }
        case howl_owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type r = _mv_1085.data.ra_object_property_range.f0;
            return howl_gate_is_inverse_role(r);
        }
        default: {
            return 0;
        }
    }
}

slop_list_howl_owl2_RawAxiom howl_gate_named_roles_only(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs) {
    {
        __auto_type out = ((slop_list_howl_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                if (!(howl_gate_axiom_has_inverse(ax))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

uint8_t howl_gate_into_top_role(howl_owl2_RawAxiom ax) {
    __auto_type _mv_1086 = ax;
    switch (_mv_1086.tag) {
        case howl_owl2_RawAxiom_ra_sub_object_property:
        {
            __auto_type sup = _mv_1086.data.ra_sub_object_property.f1;
            return howl_gate_is_top_role(sup);
        }
        case howl_owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_1086.data.ra_property_chain;
            return howl_gate_is_top_role(ch.super);
        }
        default: {
            return 0;
        }
    }
}

slop_list_howl_owl2_RawAxiom howl_gate_drop_top_role_tautologies(slop_arena* arena, howl_types_Profile p, slop_list_howl_owl2_RawAxiom axs) {
    if (!((howl_owl2_is_el_plus_plus(p) || howl_owl2_is_sriq(p)))) {
        return axs;
    } else {
        {
            __auto_type out = ((slop_list_howl_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = axs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ax = _coll.data[_i];
                    if (!((howl_gate_into_top_role(ax) && (howl_owl2_is_sriq(p) || !(howl_gate_axiom_has_inverse(ax)))))) {
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
            return out;
        }
    }
}

uint8_t howl_gate_role_listed(slop_list_howl_types_RoleId rs, howl_types_RoleId r) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = rs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                if (howl_canon_role_cmp(x, r) == 0) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

slop_list_howl_types_RoleId howl_gate_non_simple_roles(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs) {
    {
        __auto_type out = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t changed = 1;
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_types_RoleId){ .tag = howl_types_RoleId_named_role, .data.named_role = ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_BOTTOM_OBJECT_PROPERTY}) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1087 = ax;
                switch (_mv_1087.tag) {
                    case howl_owl2_RawAxiom_ra_property_chain:
                    {
                        __auto_type ch = _mv_1087.data.ra_property_chain;
                        if (!(howl_gate_role_listed(out, ch.super))) {
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (ch.super); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        while (changed) {
            changed = 0;
            {
                __auto_type _coll = axs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ax = _coll.data[_i];
                    __auto_type _mv_1088 = ax;
                    switch (_mv_1088.tag) {
                        case howl_owl2_RawAxiom_ra_sub_object_property:
                        {
                            __auto_type a = _mv_1088.data.ra_sub_object_property.f0;
                            __auto_type b = _mv_1088.data.ra_sub_object_property.f1;
                            if (howl_gate_role_listed(out, a) && !(howl_gate_role_listed(out, b))) {
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                changed = 1;
                            }
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                }
            }
        }
        return out;
    }
}

uint8_t howl_gate_concept_self_roles_simple(slop_list_howl_types_RoleId nonsimple, howl_owl2_RawConcept c) {
    __auto_type _mv_1089 = c;
    switch (_mv_1089.tag) {
        case howl_owl2_RawConcept_rc_has_self:
        {
            __auto_type r = _mv_1089.data.rc_has_self;
            return !(howl_gate_role_listed(nonsimple, r));
        }
        case howl_owl2_RawConcept_rc_and:
        {
            __auto_type cs = _mv_1089.data.rc_and;
            {
                uint8_t ok = 1;
                {
                    __auto_type _coll = cs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        if (!(howl_gate_concept_self_roles_simple(nonsimple, x))) {
                            ok = 0;
                        }
                    }
                }
                return ok;
            }
        }
        case howl_owl2_RawConcept_rc_some:
        {
            __auto_type f = _mv_1089.data.rc_some.f1;
            return howl_gate_concept_self_roles_simple(nonsimple, (*f));
        }
        default: {
            return 1;
        }
    }
}

uint8_t howl_gate_self_roles_simple(slop_list_howl_types_RoleId nonsimple, howl_owl2_RawAxiom ax) {
    __auto_type _mv_1090 = ax;
    switch (_mv_1090.tag) {
        case howl_owl2_RawAxiom_ra_sub_class_of:
        {
            __auto_type l = _mv_1090.data.ra_sub_class_of.f0;
            __auto_type r = _mv_1090.data.ra_sub_class_of.f1;
            return (howl_gate_concept_self_roles_simple(nonsimple, (*l)) && howl_gate_concept_self_roles_simple(nonsimple, (*r)));
        }
        case howl_owl2_RawAxiom_ra_disjoint_classes:
        {
            __auto_type cs = _mv_1090.data.ra_disjoint_classes;
            {
                uint8_t ok = 1;
                {
                    __auto_type _coll = cs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        if (!(howl_gate_concept_self_roles_simple(nonsimple, x))) {
                            ok = 0;
                        }
                    }
                }
                return ok;
            }
        }
        case howl_owl2_RawAxiom_ra_object_property_domain:
        {
            __auto_type c = _mv_1090.data.ra_object_property_domain.f1;
            return howl_gate_concept_self_roles_simple(nonsimple, (*c));
        }
        case howl_owl2_RawAxiom_ra_object_property_range:
        {
            __auto_type c = _mv_1090.data.ra_object_property_range.f1;
            return howl_gate_concept_self_roles_simple(nonsimple, (*c));
        }
        case howl_owl2_RawAxiom_ra_class_assertion:
        {
            __auto_type ca = _mv_1090.data.ra_class_assertion;
            return howl_gate_concept_self_roles_simple(nonsimple, (*ca.concept));
        }
        default: {
            return 1;
        }
    }
}

howl_owl2_RawConcept* howl_gate_box_c(slop_arena* arena, howl_owl2_RawConcept c) {
    {
        __auto_type p = ((howl_owl2_RawConcept*)(({ __auto_type _alloc = (howl_owl2_RawConcept*)slop_arena_alloc(arena, sizeof(howl_owl2_RawConcept)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        (*p) = c;
        return p;
    }
}

slop_list_howl_owl2_RawAxiom howl_gate_admitted(slop_arena* arena, howl_types_Profile p, slop_list_howl_owl2_RawAxiom axs) {
    {
        __auto_type out = ((slop_list_howl_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                if (howl_owl2_axiom_in_profile(p, ax)) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

uint8_t howl_gate_is_rbox_axiom(howl_owl2_RawAxiom ax) {
    __auto_type _mv_1091 = ax;
    switch (_mv_1091.tag) {
        case howl_owl2_RawAxiom_ra_sub_object_property:
        {
            return 1;
        }
        case howl_owl2_RawAxiom_ra_property_chain:
        {
            __auto_type _ = _mv_1091.data.ra_property_chain;
            return 1;
        }
        default: {
            return 0;
        }
    }
}

uint8_t howl_gate_axiom_range_ok(slop_list_howl_gate_RangeEntry entries, slop_list_u8 told, int64_t n, slop_list_howl_types_RoleId roles, howl_owl2_RawAxiom ax) {
    __auto_type _mv_1092 = ax;
    switch (_mv_1092.tag) {
        case howl_owl2_RawAxiom_ra_property_chain:
        {
            __auto_type ch = _mv_1092.data.ra_property_chain;
            return howl_gate_chain_range_ok(entries, told, n, roles, ch);
        }
        default: {
            return 1;
        }
    }
}

howl_gate_GateResult howl_gate_gate_axioms(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, howl_owl2_Signature sig, slop_list_howl_types_Omission carried, howl_types_Profile p) {
    {
        __auto_type expanded = howl_gate_gate_expand(arena, axs, p);
        __auto_type accepted = ((slop_list_howl_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type omitted = ((slop_list_howl_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = carried;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(omitted); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type rview = howl_gate_named_roles_only(arena, expanded);
            __auto_type sriq = howl_owl2_is_sriq(p);
            __auto_type srb = ((howl_owl2_is_sriq(p)) ? howl_sriqrbox_sriq_rbox(arena, howl_gate_admitted(arena, p, expanded)) : howl_sriqrbox_sriq_rbox_none(arena));
            __auto_type rbox_bad = ((howl_owl2_is_sriq(p)) ? !(srb.regular) : ({ __auto_type _mv = howl_gate_check_regularity(arena, rview); uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case howl_gate_RboxVerdict_rbox_regular: { _mr = 0; _mm = 1; break; } case howl_gate_RboxVerdict_rbox_irregular: { _mr = 1; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }));
            __auto_type rroles = howl_gate_collect_rbox_roles(arena, rview);
            __auto_type nr = ((int64_t)(((int64_t)((rroles).len))));
            __auto_type told = howl_gate_told_closure(arena, rview, rroles, nr);
            __auto_type ranges = howl_gate_collect_ranges(arena, rview, rroles);
            __auto_type nonsimple = ((howl_owl2_is_el_plus_plus(p)) ? howl_gate_non_simple_roles(arena, rview) : ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena }));
            {
                __auto_type _coll = expanded;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ax = _coll.data[_i];
                    __auto_type _mv_1093 = howl_owl2_disposition(p, ax);
                    if (_mv_1093 == howl_owl2_Disposition_d_consumed) {
                    } else if (_mv_1093 == howl_owl2_Disposition_d_inert) {
                    } else if (_mv_1093 == howl_owl2_Disposition_d_in_profile) {
                        if ((howl_owl2_axiom_in_profile(p, ax)) && (!(howl_gate_rbox_omits(sriq, rbox_bad, ax))) && (((sriq) ? howl_sriqrbox_sriq_axiom_simple(srb, ax) : howl_gate_self_roles_simple(nonsimple, ax))) && ((sriq || howl_gate_axiom_range_ok(ranges, told, nr, rroles, ax)))) {
                            ({ __auto_type _lst_p = &(accepted); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        } else {
                            ({ __auto_type _lst_p = &(omitted); __auto_type _item = (((howl_types_Omission){ .tag = howl_types_Omission_out_of_profile, .data.out_of_profile = howl_gate_axiom_input_ref(arena, ax) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    } else if (_mv_1093 == howl_owl2_Disposition_d_out_of_profile) {
                        ({ __auto_type _lst_p = &(omitted); __auto_type _item = (((howl_types_Omission){ .tag = howl_types_Omission_out_of_profile, .data.out_of_profile = howl_gate_axiom_input_ref(arena, ax) })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        }
        {
            __auto_type _coll = howl_gate_missing_declarations(arena, sig, howl_gate_collect_entity_refs(arena, accepted));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(omitted); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ((howl_gate_GateResult){.accepted = howl_gate_sort_axioms(arena, accepted), .omissions = howl_canon_sort_omissions(arena, omitted), .signature = sig});
    }
}

slop_list_howl_owl2_RawAxiom howl_gate_gate_expand(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, howl_types_Profile p) {
    return howl_gate_drop_top_role_tautologies(arena, p, howl_gate_expand_negation(arena, p, howl_gate_expand_sugar(arena, axs)));
}

uint8_t howl_gate_piece_read(howl_types_Profile p, howl_owl2_RawAxiom ax) {
    __auto_type _mv_1094 = howl_owl2_disposition(p, ax);
    if (_mv_1094 == howl_owl2_Disposition_d_in_profile) {
        return howl_owl2_axiom_in_profile(p, ax);
    } else if (_mv_1094 == howl_owl2_Disposition_d_consumed) {
        return 0;
    } else if (_mv_1094 == howl_owl2_Disposition_d_inert) {
        return 0;
    } else if (_mv_1094 == howl_owl2_Disposition_d_out_of_profile) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_gate_piece_omitted(howl_types_Profile p, howl_owl2_RawAxiom ax) {
    __auto_type _mv_1095 = howl_owl2_disposition(p, ax);
    if (_mv_1095 == howl_owl2_Disposition_d_in_profile) {
        return !(howl_owl2_axiom_in_profile(p, ax));
    } else if (_mv_1095 == howl_owl2_Disposition_d_consumed) {
        return 0;
    } else if (_mv_1095 == howl_owl2_Disposition_d_inert) {
        return 0;
    } else if (_mv_1095 == howl_owl2_Disposition_d_out_of_profile) {
        return 1;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_owl2_RawAxiom howl_gate_one_axiom(slop_arena* arena, howl_owl2_RawAxiom ax) {
    {
        __auto_type xs = ((slop_list_howl_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        (void)(({ __auto_type _lst_p = &(xs); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return xs;
    }
}

uint8_t howl_gate_unread_by_every(slop_arena* arena, howl_owl2_RawAxiom ax, slop_list_howl_types_Profile rungs) {
    {
        uint8_t unread = 1;
        {
            __auto_type _coll = rungs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                {
                    __auto_type _coll = howl_gate_gate_expand(arena, howl_gate_one_axiom(arena, ax), r);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type e = _coll.data[_i];
                        if (howl_gate_piece_read(r, e)) {
                            unread = 0;
                        }
                    }
                }
            }
        }
        return unread;
    }
}

uint8_t howl_gate_module_omissions_shared(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_list_howl_types_Omission carried, slop_list_howl_types_Omission oms, howl_types_Profile p, slop_list_howl_types_Profile rungs) {
    {
        __auto_type allowed = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        uint8_t ok = 1;
        {
            __auto_type _coll = carried;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                (void)(({ slop_string _key_1096 = (howl_owl2_render_omission(arena, o)); slop_map_put(NULL, allowed, &_key_1096, NULL, 0); }));
            }
        }
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                if (howl_gate_unread_by_every(arena, ax, rungs)) {
                    {
                        __auto_type _coll = howl_gate_gate_expand(arena, howl_gate_one_axiom(arena, ax), p);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type e = _coll.data[_i];
                            (void)(({ slop_string _key_1097 = (howl_owl2_render_omission(arena, ((howl_types_Omission){ .tag = howl_types_Omission_out_of_profile, .data.out_of_profile = howl_gate_axiom_input_ref(arena, e) }))); slop_map_put(NULL, allowed, &_key_1097, NULL, 0); }));
                        }
                    }
                } else {
                    {
                        __auto_type _coll = howl_gate_gate_expand(arena, howl_gate_one_axiom(arena, ax), p);
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type e = _coll.data[_i];
                            if (howl_gate_piece_omitted(p, e)) {
                                ok = 0;
                            }
                        }
                    }
                }
            }
        }
        {
            __auto_type _coll = oms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                __auto_type _mv_1098 = o;
                switch (_mv_1098.tag) {
                    case howl_types_Omission_out_of_profile:
                    {
                        __auto_type _ = _mv_1098.data.out_of_profile;
                        if (!(({ slop_string _key_1099 = (howl_owl2_render_omission(arena, o)); slop_map_has(allowed, &_key_1099); }))) {
                            ok = 0;
                        }
                        break;
                    }
                    case howl_types_Omission_unresolved_import:
                    {
                        __auto_type _ = _mv_1098.data.unresolved_import;
                        break;
                    }
                    case howl_types_Omission_missing_declaration:
                    {
                        __auto_type _ = _mv_1098.data.missing_declaration;
                        break;
                    }
                    case howl_types_Omission_undeclared_property:
                    {
                        __auto_type _ = _mv_1098.data.undeclared_property;
                        break;
                    }
                }
            }
        }
        return ok;
    }
}

slop_list_int howl_gate_omission_origins(slop_arena* arena, slop_arena* scratch, slop_list_howl_types_Omission oms, slop_list_howl_owl2_RawAxiom axs, slop_list_int adocs, slop_list_howl_types_Omission carried, slop_list_int cdocs, int64_t documents, howl_types_Profile p) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (documents <= 1) {
            {
                __auto_type _coll = oms;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type o = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        } else {
            {
                __auto_type needed = howl_gate_needed_texts(scratch, oms);
                __auto_type by_text = howl_gate_texts_to_docs(scratch, needed, axs, adocs, p);
                __auto_type seen = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED, int64_t); slop_map_new_ptr(scratch, 0, &_d); });
                {
                    __auto_type _coll = oms;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type o = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (({ __auto_type _mv = o; int64_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case howl_types_Omission_out_of_profile: { __auto_type r = _mv.data.out_of_profile; _mr = ({ __auto_type _mv = r; int64_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case howl_types_InputRef_owl_axiom: { __auto_type a = _mv.data.owl_axiom; _mr = ({ __auto_type k = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(seen, &(a.text)); _ptr ? (slop_option_int){ .has_value = true, .value = *(int64_t*)_ptr } : (slop_option_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type n = _mv.value; n; }) : (0); }); ({ ({ int64_t _val = (k + 1); slop_map_put(NULL, seen, &(a.text), &_val, sizeof(_val)); }); howl_gate_nth_doc(by_text, a.text, k); }); }); _mm = 1; break; } case howl_types_InputRef_rdf_fragment: { _mr = -1; _mm = 1; break; } case howl_types_InputRef_synthetic: { _mr = -1; _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }); _mm = 1; break; } case howl_types_Omission_missing_declaration: { __auto_type md = _mv.data.missing_declaration; _mr = ({ int64_t found = -2; ({ ({ __auto_type _coll = md.referring; for (size_t _i = 0; _i < _coll.len; _i++) { __auto_type ar = _coll.data[_i]; ({ __auto_type d = howl_gate_nth_doc(by_text, ar.text, 0); ({ found = ((((found == -2) || (found == d))) ? d : -1); (void)0; }); }); } (void)0; }); (((found == -2)) ? -1 : found); }); }); _mm = 1; break; } case howl_types_Omission_unresolved_import: { _mr = howl_gate_carried_doc(o, carried, cdocs); _mm = 1; break; } case howl_types_Omission_undeclared_property: { _mr = howl_gate_carried_doc(o, carried, cdocs); _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

slop_map* howl_gate_needed_texts(slop_arena* arena, slop_list_howl_types_Omission oms) {
    {
        __auto_type s = ({ static const slop_map_desc _d = SLOP_SET_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        {
            __auto_type _coll = oms;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type o = _coll.data[_i];
                __auto_type _mv_1102 = o;
                switch (_mv_1102.tag) {
                    case howl_types_Omission_out_of_profile:
                    {
                        __auto_type r = _mv_1102.data.out_of_profile;
                        __auto_type _mv_1103 = r;
                        switch (_mv_1103.tag) {
                            case howl_types_InputRef_owl_axiom:
                            {
                                __auto_type a = _mv_1103.data.owl_axiom;
                                ({ slop_map_put(NULL, s, &(a.text), NULL, 0); });
                                break;
                            }
                            case howl_types_InputRef_rdf_fragment:
                            {
                                __auto_type _ = _mv_1103.data.rdf_fragment;
                                break;
                            }
                            case howl_types_InputRef_synthetic:
                            {
                                __auto_type _ = _mv_1103.data.synthetic;
                                break;
                            }
                        }
                        break;
                    }
                    case howl_types_Omission_missing_declaration:
                    {
                        __auto_type md = _mv_1102.data.missing_declaration;
                        {
                            __auto_type _coll = md.referring;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type ar = _coll.data[_i];
                                ({ slop_map_put(NULL, s, &(ar.text), NULL, 0); });
                            }
                        }
                        break;
                    }
                    case howl_types_Omission_unresolved_import:
                    {
                        __auto_type _ = _mv_1102.data.unresolved_import;
                        break;
                    }
                    case howl_types_Omission_undeclared_property:
                    {
                        __auto_type _ = _mv_1102.data.undeclared_property;
                        break;
                    }
                }
            }
        }
        return s;
    }
}

slop_map* howl_gate_texts_to_docs(slop_arena* arena, slop_map* needed, slop_list_howl_owl2_RawAxiom axs, slop_list_int adocs, howl_types_Profile p) {
    {
        __auto_type m = ({ static const slop_map_desc _d = SLOP_MAP_DESC(slop_string, slop_hash_string, slop_eq_string, SLOP_KEY_HASHED, slop_list_int); slop_map_new_ptr(arena, 0, &_d); });
        int64_t k = 0;
        if (((int64_t)(needed)->len) > 0) {
            {
                __auto_type _coll = axs;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ax = _coll.data[_i];
                    {
                        __auto_type d = ({ __auto_type _mv = ({ __auto_type _lst = adocs; size_t _idx = (size_t)k; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; }); _mv.has_value ? ({ __auto_type x = _mv.value; x; }) : (-1); });
                        __auto_type one = ((slop_list_howl_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                        (void)(({ __auto_type _lst_p = &(one); __auto_type _item = (ax); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        {
                            __auto_type _coll = howl_gate_gate_expand(arena, one, p);
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type e = _coll.data[_i];
                                {
                                    __auto_type t = howl_owl2_render_axiom(arena, e);
                                    if (slop_map_has(needed, &(t))) {
                                        (void)(({ slop_list_int _val = howl_gate_insert_ascending(arena, ({ __auto_type _mv = ({ void* _ptr = slop_map_get(m, &(t)); _ptr ? (slop_option_list_int){ .has_value = true, .value = *(slop_list_int*)_ptr } : (slop_option_list_int){ .has_value = false }; }); _mv.has_value ? ({ __auto_type l = _mv.value; l; }) : (((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena })); }), d); slop_map_put(NULL, m, &(t), &_val, sizeof(_val)); }));
                                    }
                                }
                            }
                        }
                        k = (k + 1);
                    }
                }
            }
        }
        return m;
    }
}

slop_list_int howl_gate_insert_ascending(slop_arena* arena, slop_list_int xs, int64_t x) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t put = 0;
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type y = _coll.data[_i];
                if (!(put) && (x < y)) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    put = 1;
                }
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (y); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        if (!(put)) {
            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
        return out;
    }
}

int64_t howl_gate_nth_doc(slop_map* by_text, slop_string t, int64_t k) {
    __auto_type _mv_1110 = ({ void* _ptr = slop_map_get(by_text, &(t)); _ptr ? (slop_option_list_int){ .has_value = true, .value = *(slop_list_int*)_ptr } : (slop_option_list_int){ .has_value = false }; });
    if (_mv_1110.has_value) {
        __auto_type l = _mv_1110.value;
        __auto_type _mv_1111 = ({ __auto_type _lst = l; size_t _idx = (size_t)k; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1111.has_value) {
            __auto_type d = _mv_1111.value;
            return d;
        } else if (!_mv_1111.has_value) {
            return -1;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_1110.has_value) {
        return -1;
    }
    SLOP_UNREACHABLE();
}

int64_t howl_gate_carried_doc(howl_types_Omission o, slop_list_howl_types_Omission carried, slop_list_int cdocs) {
    {
        int64_t found = -1;
        int64_t i = 0;
        {
            __auto_type _coll = carried;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                if (howl_canon_omission_cmp(c, o) == 0) {
                    __auto_type _mv_1112 = ({ __auto_type _lst = cdocs; size_t _idx = (size_t)i; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_1112.has_value) {
                        __auto_type d = _mv_1112.value;
                        found = d;
                    } else if (!_mv_1112.has_value) {
                    }
                }
                i = (i + 1);
            }
        }
        return found;
    }
}

uint8_t howl_gate_rbox_omits(uint8_t sriq, uint8_t rbox_bad, howl_owl2_RawAxiom ax) {
    return (rbox_bad && ((sriq) ? howl_sriqrbox_is_sriq_ria(ax) : howl_gate_is_rbox_axiom(ax)));
}

slop_list_howl_owl2_RawAxiom howl_gate_sort_axioms(slop_arena* arena, slop_list_howl_owl2_RawAxiom xs) {
    {
        __auto_type texts = howl_gate_axiom_texts(arena, xs);
        {
            __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ howl_gate__lambda_1113_env_t* howl_gate__lambda_1113_env = (howl_gate__lambda_1113_env_t*)slop_arena_alloc(arena, sizeof(howl_gate__lambda_1113_env_t)); *howl_gate__lambda_1113_env = (howl_gate__lambda_1113_env_t){ .texts = texts }; (slop_closure_t){ (void*)howl_gate__lambda_1113, (void*)howl_gate__lambda_1113_env }; }));
            __auto_type out = ((slop_list_howl_owl2_RawAxiom){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
            {
                __auto_type _coll = idx;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type k = _coll.data[_i];
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_gate_axiom_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
            return out;
        }
    }
}

slop_list_string howl_gate_axiom_texts(slop_arena* arena, slop_list_howl_owl2_RawAxiom xs) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_owl2_render_axiom(arena, ax)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_owl2_RawAxiom howl_gate_axiom_at(slop_list_howl_owl2_RawAxiom xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_1114 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_owl2_RawAxiom _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1114.has_value) {
        __auto_type v = _mv_1114.value;
        return v;
    } else if (!_mv_1114.has_value) {
        return ((howl_owl2_RawAxiom){ .tag = howl_owl2_RawAxiom_ra_unrecognized, .data.ra_unrecognized = ((howl_types_InputRef){ .tag = howl_types_InputRef_synthetic, .data.synthetic = SLOP_STR("unreachable: axiom index out of range") }) });
    }
    SLOP_UNREACHABLE();
}

int64_t howl_gate_role_idx(slop_list_howl_types_RoleId roles, howl_types_RoleId r) {
    {
        int64_t found = -1;
        int64_t i = 0;
        {
            __auto_type _coll = roles;
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

uint8_t howl_gate_push_role_unique(slop_list_howl_types_RoleId rs, howl_types_RoleId r) {
    return (howl_gate_role_idx(rs, r) < 0);
}

slop_list_howl_types_RoleId howl_gate_collect_rbox_roles(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs) {
    {
        __auto_type rs = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1115 = ax;
                switch (_mv_1115.tag) {
                    case howl_owl2_RawAxiom_ra_sub_object_property:
                    {
                        __auto_type a = _mv_1115.data.ra_sub_object_property.f0;
                        __auto_type b = _mv_1115.data.ra_sub_object_property.f1;
                        if (howl_gate_push_role_unique(rs, a)) {
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        if (howl_gate_push_role_unique(rs, b)) {
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        break;
                    }
                    case howl_owl2_RawAxiom_ra_property_chain:
                    {
                        __auto_type ch = _mv_1115.data.ra_property_chain;
                        {
                            __auto_type _coll = ch.steps;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type st = _coll.data[_i];
                                if (howl_gate_push_role_unique(rs, st)) {
                                    ({ __auto_type _lst_p = &(rs); __auto_type _item = (st); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                        if (howl_gate_push_role_unique(rs, ch.super)) {
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (ch.super); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        break;
                    }
                    case howl_owl2_RawAxiom_ra_object_property_range:
                    {
                        __auto_type r = _mv_1115.data.ra_object_property_range.f0;
                        if (howl_gate_push_role_unique(rs, r)) {
                            ({ __auto_type _lst_p = &(rs); __auto_type _item = (r); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        return howl_gate_sort_roles(arena, rs);
    }
}

slop_list_howl_types_RoleId howl_gate_sort_roles(slop_arena* arena, slop_list_howl_types_RoleId xs) {
    {
        __auto_type idx = howl_canon_sort_range(arena, ((int64_t)(((int64_t)((xs).len)))), ({ howl_gate__lambda_1116_env_t* howl_gate__lambda_1116_env = (howl_gate__lambda_1116_env_t*)slop_arena_alloc(arena, sizeof(howl_gate__lambda_1116_env_t)); *howl_gate__lambda_1116_env = (howl_gate__lambda_1116_env_t){ .xs = xs }; (slop_closure_t){ (void*)howl_gate__lambda_1116, (void*)howl_gate__lambda_1116_env }; }));
        __auto_type out = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type k = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_gate_role_at(xs, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

howl_types_RoleId howl_gate_role_at(slop_list_howl_types_RoleId xs, int64_t i) {
    SLOP_PRE(((i >= 0)), "(>= i 0)");
    SLOP_PRE(((i < ((int64_t)((xs).len)))), "(< i (list-len xs))");
    __auto_type _mv_1117 = ({ __auto_type _lst = xs; size_t _idx = (size_t)i; slop_option_howl_types_RoleId _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1117.has_value) {
        __auto_type v = _mv_1117.value;
        return v;
    } else if (!_mv_1117.has_value) {
        return ((howl_types_RoleId){ .tag = howl_types_RoleId_fresh_role, .data.fresh_role = 0 });
    }
    SLOP_UNREACHABLE();
}

slop_list_u8 howl_gate_mat_new(slop_arena* arena, int64_t cells) {
    {
        __auto_type m = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        while (i < cells) {
            (void)(({ __auto_type _lst_p = &(m); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            i = (i + 1);
        }
        return m;
    }
}

uint8_t howl_gate_mat_get(slop_list_u8 m, int64_t i) {
    __auto_type _mv_1118 = ({ __auto_type _lst = m; size_t _idx = (size_t)i; slop_option_u8 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1118.has_value) {
        __auto_type v = _mv_1118.value;
        return v;
    } else if (!_mv_1118.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_gate_mat_or_row(slop_list_u8 m, int64_t n, int64_t k, int64_t i) {
    {
        int64_t j = 0;
        while (j < n) {
            if (howl_gate_mat_get(m, ((k * n) + j))) {
                (void)(({ __auto_type _set_lst = &(m); size_t _set_idx = (size_t)(((i * n) + j)); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
            }
            j = (j + 1);
        }
        return 1;
    }
}

uint8_t howl_gate_mat_close_through(slop_list_u8 m, int64_t n, int64_t k) {
    {
        int64_t i = 0;
        while (i < n) {
            if (howl_gate_mat_get(m, ((i * n) + k))) {
                howl_gate_mat_or_row(m, n, k, i);
            }
            i = (i + 1);
        }
        return 1;
    }
}

uint8_t howl_gate_mat_close(slop_list_u8 m, int64_t n) {
    {
        int64_t k = 0;
        while (k < n) {
            howl_gate_mat_close_through(m, n, k);
            k = (k + 1);
        }
        return 1;
    }
}

slop_list_u8 howl_gate_told_closure(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_list_howl_types_RoleId roles, int64_t n) {
    {
        __auto_type m = howl_gate_mat_new(arena, (n * n));
        int64_t i = 0;
        while (i < n) {
            (void)(({ __auto_type _set_lst = &(m); size_t _set_idx = (size_t)(((i * n) + i)); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
            i = (i + 1);
        }
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1119 = ax;
                switch (_mv_1119.tag) {
                    case howl_owl2_RawAxiom_ra_sub_object_property:
                    {
                        __auto_type a = _mv_1119.data.ra_sub_object_property.f0;
                        __auto_type b = _mv_1119.data.ra_sub_object_property.f1;
                        {
                            __auto_type ia = howl_gate_role_idx(roles, a);
                            __auto_type ib = howl_gate_role_idx(roles, b);
                            if ((ia >= 0) && (ib >= 0)) {
                                ({ __auto_type _set_lst = &(m); size_t _set_idx = (size_t)(((ia * n) + ib)); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
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
        howl_gate_mat_close(m, n);
        return m;
    }
}

int64_t howl_gate_candidate_size(howl_owl2_RawChain ch, int64_t from, int64_t to) {
    {
        __auto_type steps = ch.steps;
        int64_t count = 0;
        int64_t i = from;
        while (i <= to) {
            if (!(howl_gate_seen_before(steps, from, i))) {
                count = (count + 1);
            }
            i = (i + 1);
        }
        return count;
    }
}

uint8_t howl_gate_seen_before(slop_list_howl_types_RoleId steps, int64_t from, int64_t i) {
    {
        uint8_t dup = 0;
        int64_t j = from;
        while (j < i) {
            if (howl_canon_role_cmp(howl_gate_role_at(steps, j), howl_gate_role_at(steps, i)) == 0) {
                dup = 1;
            }
            j = (j + 1);
        }
        return dup;
    }
}

uint8_t howl_gate_add_chain_constraints(howl_owl2_RawChain ch, slop_list_howl_types_RoleId roles, int64_t n, slop_list_u8 cmat, int64_t from, int64_t to) {
    {
        __auto_type steps = ch.steps;
        __auto_type isup = howl_gate_role_idx(roles, ch.super);
        int64_t i = from;
        while (i <= to) {
            {
                __auto_type ist = howl_gate_role_idx(roles, howl_gate_role_at(steps, i));
                if ((ist >= 0) && (isup >= 0)) {
                    (void)(({ __auto_type _set_lst = &(cmat); size_t _set_idx = (size_t)(((ist * n) + isup)); __auto_type _set_val = (1); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; }));
                }
            }
            i = (i + 1);
        }
        return 1;
    }
}

slop_string howl_gate_describe_violation(slop_arena* arena, slop_list_howl_types_RoleId roles, int64_t i, int64_t j) {
    return string_concat(arena, SLOP_STR("property-chain regularity: "), string_concat(arena, howl_owl2_render_role(arena, howl_gate_role_at(roles, i)), string_concat(arena, SLOP_STR(" must precede "), string_concat(arena, howl_owl2_render_role(arena, howl_gate_role_at(roles, j)), string_concat(arena, SLOP_STR(", but the told hierarchy has "), string_concat(arena, howl_owl2_render_role(arena, howl_gate_role_at(roles, j)), string_concat(arena, SLOP_STR(" sub-property-of "), howl_owl2_render_role(arena, howl_gate_role_at(roles, i)))))))));
}

uint8_t howl_gate_add_dominant_case(howl_owl2_RawChain ch, slop_list_howl_types_RoleId roles, int64_t n, slop_list_u8 cmat, int64_t len, uint8_t left_ok, uint8_t right_ok) {
    {
        __auto_type gen = howl_gate_candidate_size(ch, 0, (len - 1));
        __auto_type lft = ((left_ok) ? howl_gate_candidate_size(ch, 1, (len - 1)) : 1000000);
        __auto_type rgt = ((right_ok) ? howl_gate_candidate_size(ch, 0, (len - 2)) : 1000000);
        if ((lft <= rgt) && (lft <= gen)) {
            return howl_gate_add_chain_constraints(ch, roles, n, cmat, 1, (len - 1));
        } else if (rgt <= gen) {
            return howl_gate_add_chain_constraints(ch, roles, n, cmat, 0, (len - 2));
        } else {
            return howl_gate_add_chain_constraints(ch, roles, n, cmat, 0, (len - 1));
        }
    }
}

uint8_t howl_gate_add_case_constraints(howl_owl2_RawChain ch, slop_list_howl_types_RoleId roles, int64_t n, slop_list_u8 cmat) {
    {
        __auto_type steps = ch.steps;
        __auto_type len = ((int64_t)(((int64_t)((ch.steps).len))));
        __auto_type sup = ch.super;
        if (len < 2) {
            return 1;
        } else {
            {
                __auto_type left_ok = (howl_canon_role_cmp(howl_gate_role_at(steps, 0), sup) == 0);
                __auto_type right_ok = (howl_canon_role_cmp(howl_gate_role_at(steps, (len - 1)), sup) == 0);
                if (((len == 2)) && (left_ok) && (right_ok)) {
                    return 1;
                } else {
                    return howl_gate_add_dominant_case(ch, roles, n, cmat, len, left_ok, right_ok);
                }
            }
        }
    }
}

int64_t howl_gate_row_violation(slop_list_u8 cmat, slop_list_u8 told, int64_t n, int64_t i) {
    {
        int64_t found = -1;
        int64_t j = 0;
        while (j < n) {
            if (((found < 0)) && (howl_gate_mat_get(cmat, ((i * n) + j))) && (howl_gate_mat_get(told, ((j * n) + i)))) {
                found = j;
            }
            j = (j + 1);
        }
        return found;
    }
}

howl_gate_RboxVerdict howl_gate_regularity_verdict(slop_arena* arena, slop_list_howl_types_RoleId roles, slop_list_u8 cmat, slop_list_u8 told, int64_t n) {
    {
        int64_t vi = -1;
        int64_t vj = -1;
        int64_t i = 0;
        while ((vi < 0) && (i < n)) {
            {
                __auto_type j = howl_gate_row_violation(cmat, told, n, i);
                if (j >= 0) {
                    vi = i;
                    vj = j;
                }
                i = (i + 1);
            }
        }
        if (vi < 0) {
            return ((howl_gate_RboxVerdict){ .tag = howl_gate_RboxVerdict_rbox_regular });
        } else {
            return ((howl_gate_RboxVerdict){ .tag = howl_gate_RboxVerdict_rbox_irregular, .data.rbox_irregular = howl_gate_describe_violation(arena, roles, vi, vj) });
        }
    }
}

howl_gate_RboxVerdict howl_gate_check_regularity(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs) {
    {
        __auto_type roles = howl_gate_collect_rbox_roles(arena, axs);
        __auto_type n = ((int64_t)(((int64_t)((roles).len))));
        if (n == 0) {
            return ((howl_gate_RboxVerdict){ .tag = howl_gate_RboxVerdict_rbox_regular });
        } else {
            {
                __auto_type told = howl_gate_told_closure(arena, axs, roles, n);
                __auto_type cmat = howl_gate_mat_new(arena, (n * n));
                {
                    __auto_type _coll = axs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type ax = _coll.data[_i];
                        __auto_type _mv_1120 = ax;
                        switch (_mv_1120.tag) {
                            case howl_owl2_RawAxiom_ra_property_chain:
                            {
                                __auto_type ch = _mv_1120.data.ra_property_chain;
                                howl_gate_add_case_constraints(ch, roles, n, cmat);
                                break;
                            }
                            default: {
                                break;
                            }
                        }
                    }
                }
                howl_gate_mat_close(cmat, n);
                return howl_gate_regularity_verdict(arena, roles, cmat, told, n);
            }
        }
    }
}

slop_list_howl_gate_RangeEntry howl_gate_collect_ranges(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_list_howl_types_RoleId roles) {
    {
        __auto_type out = ((slop_list_howl_gate_RangeEntry){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1121 = ax;
                switch (_mv_1121.tag) {
                    case howl_owl2_RawAxiom_ra_object_property_range:
                    {
                        __auto_type r = _mv_1121.data.ra_object_property_range.f0;
                        __auto_type c = _mv_1121.data.ra_object_property_range.f1;
                        {
                            __auto_type ir = howl_gate_role_idx(roles, r);
                            if (ir >= 0) {
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_gate_RangeEntry){.role = ir, .filler = (*c)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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

uint8_t howl_gate_has_inherited_range(slop_list_howl_gate_RangeEntry entries, slop_list_u8 told, int64_t n, int64_t base, howl_owl2_RawConcept c) {
    {
        uint8_t found = 0;
        {
            __auto_type _coll = entries;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (howl_gate_mat_get(told, ((base * n) + e.role)) && (howl_owl2_concept_cmp(e.filler, c) == 0)) {
                    found = 1;
                }
            }
        }
        return found;
    }
}

uint8_t howl_gate_chain_range_ok(slop_list_howl_gate_RangeEntry entries, slop_list_u8 told, int64_t n, slop_list_howl_types_RoleId roles, howl_owl2_RawChain ch) {
    {
        __auto_type steps = ch.steps;
        __auto_type len = ((int64_t)(((int64_t)((ch.steps).len))));
        __auto_type it = howl_gate_role_idx(roles, ch.super);
        if ((len < 1) || (it < 0)) {
            return 1;
        } else {
            {
                __auto_type ilast = howl_gate_role_idx(roles, howl_gate_role_at(steps, (len - 1)));
                uint8_t ok = 1;
                if (ilast >= 0) {
                    {
                        __auto_type _coll = entries;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type e = _coll.data[_i];
                            if (howl_gate_mat_get(told, ((it * n) + e.role))) {
                                if (!(howl_gate_has_inherited_range(entries, told, n, ilast, e.filler))) {
                                    ok = 0;
                                }
                            }
                        }
                    }
                }
                return ok;
            }
        }
    }
}

howl_types_AxiomRef howl_gate_axiom_ref_of(slop_arena* arena, howl_owl2_RawAxiom ax) {
    {
        slop_option_slop_rdf_rdf_IRI no_source = (slop_option_slop_rdf_rdf_IRI){.has_value = false};
        return ((howl_types_AxiomRef){.source = no_source, .text = howl_owl2_render_axiom(arena, ax)});
    }
}

slop_list_slop_rdf_rdf_IRI howl_gate_collect_concept_classes(slop_arena* arena, howl_owl2_RawConcept c, slop_list_slop_rdf_rdf_IRI acc) {
    {
        __auto_type out = acc;
        __auto_type _mv_1122 = c;
        switch (_mv_1122.tag) {
            case howl_owl2_RawConcept_rc_name:
            {
                __auto_type n = _mv_1122.data.rc_name;
                __auto_type _mv_1123 = n;
                switch (_mv_1123.tag) {
                    case howl_types_Node_class_node:
                    {
                        __auto_type i = _mv_1123.data.class_node;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        break;
                    }
                    case howl_types_Node_individual_node:
                    {
                        __auto_type _ = _mv_1123.data.individual_node;
                        break;
                    }
                    case howl_types_Node_fresh_node:
                    {
                        __auto_type _ = _mv_1123.data.fresh_node;
                        break;
                    }
                }
                break;
            }
            case howl_owl2_RawConcept_rc_and:
            {
                __auto_type cs = _mv_1122.data.rc_and;
                {
                    __auto_type _coll = cs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        out = howl_gate_collect_concept_classes(arena, x, out);
                    }
                }
                break;
            }
            case howl_owl2_RawConcept_rc_some:
            {
                __auto_type f = _mv_1122.data.rc_some.f1;
                out = howl_gate_collect_concept_classes(arena, (*f), out);
                break;
            }
            case howl_owl2_RawConcept_rc_or:
            {
                __auto_type cs = _mv_1122.data.rc_or;
                {
                    __auto_type _coll = cs;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        out = howl_gate_collect_concept_classes(arena, x, out);
                    }
                }
                break;
            }
            case howl_owl2_RawConcept_rc_not:
            {
                __auto_type f = _mv_1122.data.rc_not;
                out = howl_gate_collect_concept_classes(arena, (*f), out);
                break;
            }
            case howl_owl2_RawConcept_rc_all:
            {
                __auto_type f = _mv_1122.data.rc_all.f1;
                out = howl_gate_collect_concept_classes(arena, (*f), out);
                break;
            }
            case howl_owl2_RawConcept_rc_qcard:
            {
                __auto_type f = _mv_1122.data.rc_qcard.f3;
                out = howl_gate_collect_concept_classes(arena, (*f), out);
                break;
            }
            default: {
                break;
            }
        }
        return out;
    }
}

slop_list_howl_gate_EntityRef howl_gate_collect_entity_refs(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs) {
    {
        __auto_type out = ((slop_list_howl_gate_EntityRef){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = axs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                {
                    __auto_type classes = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    __auto_type roles = ((slop_list_howl_types_RoleId){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                    __auto_type _mv_1124 = ax;
                    switch (_mv_1124.tag) {
                        case howl_owl2_RawAxiom_ra_sub_class_of:
                        {
                            __auto_type l = _mv_1124.data.ra_sub_class_of.f0;
                            __auto_type rr = _mv_1124.data.ra_sub_class_of.f1;
                            classes = howl_gate_collect_concept_classes(arena, (*l), classes);
                            classes = howl_gate_collect_concept_classes(arena, (*rr), classes);
                            break;
                        }
                        case howl_owl2_RawAxiom_ra_equivalent_classes:
                        {
                            __auto_type cs = _mv_1124.data.ra_equivalent_classes;
                            {
                                __auto_type _coll = cs;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type x = _coll.data[_i];
                                    classes = howl_gate_collect_concept_classes(arena, x, classes);
                                }
                            }
                            break;
                        }
                        case howl_owl2_RawAxiom_ra_disjoint_classes:
                        {
                            __auto_type cs = _mv_1124.data.ra_disjoint_classes;
                            {
                                __auto_type _coll = cs;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type x = _coll.data[_i];
                                    classes = howl_gate_collect_concept_classes(arena, x, classes);
                                }
                            }
                            break;
                        }
                        case howl_owl2_RawAxiom_ra_object_property_domain:
                        {
                            __auto_type rl = _mv_1124.data.ra_object_property_domain.f0;
                            __auto_type c = _mv_1124.data.ra_object_property_domain.f1;
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (rl); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            classes = howl_gate_collect_concept_classes(arena, (*c), classes);
                            break;
                        }
                        case howl_owl2_RawAxiom_ra_object_property_range:
                        {
                            __auto_type rl = _mv_1124.data.ra_object_property_range.f0;
                            __auto_type c = _mv_1124.data.ra_object_property_range.f1;
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (rl); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            classes = howl_gate_collect_concept_classes(arena, (*c), classes);
                            break;
                        }
                        case howl_owl2_RawAxiom_ra_class_assertion:
                        {
                            __auto_type ca = _mv_1124.data.ra_class_assertion;
                            classes = howl_gate_collect_concept_classes(arena, (*ca.concept), classes);
                            break;
                        }
                        case howl_owl2_RawAxiom_ra_sub_object_property:
                        {
                            __auto_type a = _mv_1124.data.ra_sub_object_property.f0;
                            __auto_type b = _mv_1124.data.ra_sub_object_property.f1;
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        case howl_owl2_RawAxiom_ra_property_chain:
                        {
                            __auto_type ch = _mv_1124.data.ra_property_chain;
                            {
                                __auto_type _coll = ch.steps;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type st = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(roles); __auto_type _item = (st); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (ch.super); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        case howl_owl2_RawAxiom_ra_object_property_assertion:
                        {
                            __auto_type e = _mv_1124.data.ra_object_property_assertion;
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (e.role); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        case howl_owl2_RawAxiom_ra_negative_assertion:
                        {
                            __auto_type e = _mv_1124.data.ra_negative_assertion;
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (e.role); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        case howl_owl2_RawAxiom_ra_property_characteristic:
                        {
                            __auto_type rl = _mv_1124.data.ra_property_characteristic.f1;
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (rl); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        case howl_owl2_RawAxiom_ra_inverse_properties:
                        {
                            __auto_type a = _mv_1124.data.ra_inverse_properties.f0;
                            __auto_type b = _mv_1124.data.ra_inverse_properties.f1;
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            ({ __auto_type _lst_p = &(roles); __auto_type _item = (b); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            break;
                        }
                        case howl_owl2_RawAxiom_ra_equivalent_properties:
                        {
                            __auto_type rs = _mv_1124.data.ra_equivalent_properties;
                            {
                                __auto_type _coll = rs;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type rl = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(roles); __auto_type _item = (rl); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                            break;
                        }
                        case howl_owl2_RawAxiom_ra_disjoint_properties:
                        {
                            __auto_type rs = _mv_1124.data.ra_disjoint_properties;
                            {
                                __auto_type _coll = rs;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type rl = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(roles); __auto_type _item = (rl); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                            break;
                        }
                        case howl_owl2_RawAxiom_ra_disjoint_union:
                        {
                            __auto_type du = _mv_1124.data.ra_disjoint_union;
                            ({ __auto_type _lst_p = &(classes); __auto_type _item = (du.class); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                            {
                                __auto_type _coll = du.members;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type x = _coll.data[_i];
                                    classes = howl_gate_collect_concept_classes(arena, x, classes);
                                }
                            }
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                    {
                        __auto_type _coll = classes;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type i = _coll.data[_i];
                            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_gate_EntityRef){.kind = howl_types_EntityKind_entity_class, .entity = i, .axiom = ax})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                    {
                        __auto_type _coll = roles;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type rl = _coll.data[_i];
                            __auto_type _mv_1125 = rl;
                            switch (_mv_1125.tag) {
                                case howl_types_RoleId_named_role:
                                {
                                    __auto_type i = _mv_1125.data.named_role;
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_gate_EntityRef){.kind = howl_types_EntityKind_entity_object_property, .entity = i, .axiom = ax})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    break;
                                }
                                case howl_types_RoleId_inverse_role:
                                {
                                    __auto_type i = _mv_1125.data.inverse_role;
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_gate_EntityRef){.kind = howl_types_EntityKind_entity_object_property, .entity = i, .axiom = ax})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    break;
                                }
                                case howl_types_RoleId_fresh_role:
                                {
                                    __auto_type _ = _mv_1125.data.fresh_role;
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

uint8_t howl_gate_entity_ref_declared(howl_owl2_Signature sig, howl_gate_EntityRef e) {
    __auto_type _mv_1126 = e.kind;
    if (_mv_1126 == howl_types_EntityKind_entity_class) {
        return howl_owl2_signature_has_class(sig, e.entity);
    } else if (_mv_1126 == howl_types_EntityKind_entity_object_property) {
        return howl_owl2_signature_has_object_property(sig, e.entity);
    } else if (_mv_1126 == howl_types_EntityKind_entity_data_property) {
        return 1;
    } else if (_mv_1126 == howl_types_EntityKind_entity_annotation_property) {
        return 1;
    } else if (_mv_1126 == howl_types_EntityKind_entity_individual) {
        return 1;
    } else if (_mv_1126 == howl_types_EntityKind_entity_datatype) {
        return 1;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_gate_same_entity(howl_gate_EntityRef a, howl_gate_EntityRef b) {
    return ((a.kind == b.kind) && (howl_canon_iri_cmp(a.entity, b.entity) == 0));
}

uint8_t howl_gate_has_entity(slop_list_howl_gate_EntityRef seen, howl_gate_EntityRef e) {
    {
        uint8_t dup = 0;
        {
            __auto_type _coll = seen;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s2 = _coll.data[_i];
                if (howl_gate_same_entity(s2, e)) {
                    dup = 1;
                }
            }
        }
        return dup;
    }
}

howl_types_Omission howl_gate_missing_declaration_of(slop_arena* arena, howl_gate_EntityRef e, slop_list_howl_gate_EntityRef refs) {
    {
        __auto_type refs_for = ((slop_list_howl_types_AxiomRef){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = refs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                if (howl_gate_same_entity(f, e)) {
                    (void)(({ __auto_type _lst_p = &(refs_for); __auto_type _item = (howl_gate_axiom_ref_of(arena, f.axiom)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return ((howl_types_Omission){ .tag = howl_types_Omission_missing_declaration, .data.missing_declaration = ((howl_types_MissingDeclaration){.kind = e.kind, .entity = e.entity, .referring = howl_canon_sort_axiom_refs(arena, refs_for)}) });
    }
}

slop_list_howl_types_Omission howl_gate_missing_declarations(slop_arena* arena, howl_owl2_Signature sig, slop_list_howl_gate_EntityRef refs) {
    {
        __auto_type out = ((slop_list_howl_types_Omission){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type seen = ((slop_list_howl_gate_EntityRef){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = refs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type e = _coll.data[_i];
                if (!(howl_gate_entity_ref_declared(sig, e)) && !(howl_gate_has_entity(seen, e))) {
                    (void)(({ __auto_type _lst_p = &(seen); __auto_type _item = (e); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_gate_missing_declaration_of(arena, e, refs)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

