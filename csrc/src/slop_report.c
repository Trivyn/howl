#include "../runtime/slop_runtime.h"
#include "slop_report.h"

slop_string report_node_text(slop_arena* arena, types_Node n);
slop_string report_keyed(slop_arena* arena, slop_string key, slop_string text);
slop_string report_verdict_line(types_Outcome o);
slop_string report_termination_line(types_Termination t);
slop_list_string report_probe_lines(slop_arena* arena, probe_Probing p);
slop_list_string report_answer_lines(slop_arena* arena, probe_Probing p, uint8_t ran);
slop_string report_answer_text(slop_arena* arena, probe_Answered a);
slop_string report_answer_name(probe_ProbeAnswer a);
slop_list_string report_report_lines(slop_arena* arena, types_Outcome o);

slop_string report_node_text(slop_arena* arena, types_Node n) {
    __auto_type _mv_1601 = n;
    switch (_mv_1601.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_1601.data.class_node;
            return i.value;
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_1601.data.individual_node;
            return string_concat(arena, SLOP_STR("{"), string_concat(arena, i.value, SLOP_STR("}")));
        }
        case types_Node_fresh_node:
        {
            __auto_type k = _mv_1601.data.fresh_node;
            return string_concat(arena, SLOP_STR("_:fresh"), int_to_string(arena, k));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string report_keyed(slop_arena* arena, slop_string key, slop_string text) {
    return string_concat(arena, key, string_concat(arena, SLOP_STR(" "), text));
}

slop_string report_verdict_line(types_Outcome o) {
    __auto_type _mv_1602 = types_verdict(o);
    if (_mv_1602 == types_Verdict_verdict_coherent) {
        return SLOP_STR("verdict coherent");
    } else if (_mv_1602 == types_Verdict_verdict_incoherent) {
        return SLOP_STR("verdict incoherent");
    } else if (_mv_1602 == types_Verdict_verdict_inconclusive) {
        return SLOP_STR("verdict inconclusive");
    }
    SLOP_UNREACHABLE();
}

slop_string report_termination_line(types_Termination t) {
    __auto_type _mv_1603 = t;
    switch (_mv_1603.tag) {
        case types_Termination_fixpoint:
        {
            return SLOP_STR("termination fixpoint");
        }
        case types_Termination_resource_limit:
        {
            __auto_type _ = _mv_1603.data.resource_limit;
            return SLOP_STR("termination resource-limit");
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_string report_probe_lines(slop_arena* arena, probe_Probing p) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("probes"), int_to_string(arena, ((int64_t)(((int64_t)((p.answers).len))))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (((p.inconsistent) ? SLOP_STR("probe-inconsistent true") : SLOP_STR("probe-inconsistent false"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("probe-omitted"), int_to_string(arena, ((int64_t)(((int64_t)((p.omissions).len))))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = p.omissions;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type om = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("probe-omission"), owl2_render_omission(arena, om))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        {
            __auto_type _coll = p.answers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("probe"), report_answer_text(arena, a))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_list_string report_answer_lines(slop_arena* arena, probe_Probing p, uint8_t ran) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        if (ran) {
            ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("profile"), select_profile_name(p.profile))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        }
        {
            __auto_type _coll = report_probe_lines(arena, p);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

slop_string report_answer_text(slop_arena* arena, probe_Answered a) {
    {
        __auto_type q = a.query;
        __auto_type _mv_1604 = q.kind;
        if (_mv_1604 == probe_QueryKind_query_unsatisfiable) {
            return strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 4 * sizeof(slop_string)), .len = 4, .cap = 4, .arena = arena }; _ll.data[0] = SLOP_STR("unsatisfiable "); _ll.data[1] = q.sub.value; _ll.data[2] = SLOP_STR(" "); _ll.data[3] = report_answer_name(a.answer); _ll; }));
        } else if (_mv_1604 == probe_QueryKind_query_subsumed) {
            return strlib_string_build(arena, ({ slop_list_string _ll = (slop_list_string){ .data = (slop_string*)slop_arena_alloc(arena, 6 * sizeof(slop_string)), .len = 6, .cap = 6, .arena = arena }; _ll.data[0] = SLOP_STR("subsumed "); _ll.data[1] = q.sub.value; _ll.data[2] = SLOP_STR(" "); _ll.data[3] = q.sup.value; _ll.data[4] = SLOP_STR(" "); _ll.data[5] = report_answer_name(a.answer); _ll; }));
        }
        SLOP_UNREACHABLE();
    }
}

slop_string report_answer_name(probe_ProbeAnswer a) {
    __auto_type _mv_1605 = a;
    if (_mv_1605 == probe_ProbeAnswer_answer_yes) {
        return SLOP_STR("yes");
    } else if (_mv_1605 == probe_ProbeAnswer_answer_no) {
        return SLOP_STR("no");
    } else if (_mv_1605 == probe_ProbeAnswer_answer_unknown) {
        return SLOP_STR("unknown");
    }
    SLOP_UNREACHABLE();
}

slop_list_string report_report_lines(slop_arena* arena, types_Outcome o) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type f = o.findings;
        __auto_type omitted = o.coverage.omitted;
        ({ __auto_type _lst_p = &(out); __auto_type _item = (SLOP_STR("howl-report 2")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("profile"), select_profile_name(o.profile))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (report_verdict_line(o)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (report_termination_line(o.termination)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("rounds"), int_to_string(arena, o.rounds))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (((f.inconsistent) ? SLOP_STR("inconsistent true") : SLOP_STR("inconsistent false"))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("omitted"), int_to_string(arena, ((int64_t)(((int64_t)((omitted).len))))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = omitted;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type om = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("omission"), owl2_render_omission(arena, om))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("unsatisfiable"), int_to_string(arena, ((int64_t)(((int64_t)((f.unsatisfiable).len))))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = f.unsatisfiable;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("unsat"), c.value)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("subsumptions"), int_to_string(arena, ((int64_t)(((int64_t)((f.subsumptions).len))))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = f.subsumptions;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("sub"), string_concat(arena, report_node_text(arena, p.sub), string_concat(arena, SLOP_STR(" "), report_node_text(arena, p.super))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

