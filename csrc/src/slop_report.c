#include "../runtime/slop_runtime.h"
#include "slop_report.h"

slop_string report_node_text(slop_arena* arena, types_Node n);
slop_string report_keyed(slop_arena* arena, slop_string key, slop_string text);
slop_string report_verdict_line(types_Outcome o);
slop_string report_termination_line(types_Termination t);
slop_list_string report_report_lines(slop_arena* arena, types_Outcome o);

slop_string report_node_text(slop_arena* arena, types_Node n) {
    __auto_type _mv_608 = n;
    switch (_mv_608.tag) {
        case types_Node_class_node:
        {
            __auto_type i = _mv_608.data.class_node;
            return i.value;
        }
        case types_Node_individual_node:
        {
            __auto_type i = _mv_608.data.individual_node;
            return string_concat(arena, SLOP_STR("{"), string_concat(arena, i.value, SLOP_STR("}")));
        }
        case types_Node_fresh_node:
        {
            __auto_type k = _mv_608.data.fresh_node;
            return string_concat(arena, SLOP_STR("_:fresh"), int_to_string(arena, k));
        }
    }
    SLOP_UNREACHABLE();
}

slop_string report_keyed(slop_arena* arena, slop_string key, slop_string text) {
    return string_concat(arena, key, string_concat(arena, SLOP_STR(" "), text));
}

slop_string report_verdict_line(types_Outcome o) {
    __auto_type _mv_609 = howl_verdict(o);
    if (_mv_609 == howl_Verdict_verdict_coherent) {
        return SLOP_STR("verdict coherent");
    } else if (_mv_609 == howl_Verdict_verdict_incoherent) {
        return SLOP_STR("verdict incoherent");
    } else if (_mv_609 == howl_Verdict_verdict_inconclusive) {
        return SLOP_STR("verdict inconclusive");
    }
    SLOP_UNREACHABLE();
}

slop_string report_termination_line(types_Termination t) {
    __auto_type _mv_610 = t;
    switch (_mv_610.tag) {
        case types_Termination_fixpoint:
        {
            return SLOP_STR("termination fixpoint");
        }
        case types_Termination_resource_limit:
        {
            __auto_type _ = _mv_610.data.resource_limit;
            return SLOP_STR("termination resource-limit");
        }
    }
    SLOP_UNREACHABLE();
}

slop_list_string report_report_lines(slop_arena* arena, types_Outcome o) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0 });
        __auto_type f = o.findings;
        __auto_type omitted = o.coverage.omitted;
        ({ __auto_type _lst_p = &(out); __auto_type _item = (SLOP_STR("howl-report 1")); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (report_verdict_line(o)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (report_termination_line(o.termination)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("rounds"), int_to_string(arena, o.saturation.iteration))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (((f.inconsistent) ? SLOP_STR("inconsistent true") : SLOP_STR("inconsistent false"))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("omitted"), int_to_string(arena, ((int64_t)(((int64_t)((omitted).len))))))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = omitted;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type om = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("omission"), owl2_render_omission(arena, om))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("unsatisfiable"), int_to_string(arena, ((int64_t)(((int64_t)((f.unsatisfiable).len))))))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = f.unsatisfiable;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("unsat"), c.value)); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("subsumptions"), int_to_string(arena, ((int64_t)(((int64_t)((f.subsumptions).len))))))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        {
            __auto_type _coll = f.subsumptions;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type p = _coll.data[_i];
                ({ __auto_type _lst_p = &(out); __auto_type _item = (report_keyed(arena, SLOP_STR("sub"), string_concat(arena, report_node_text(arena, p.sub), string_concat(arena, SLOP_STR(" "), report_node_text(arena, p.super))))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        }
        return out;
    }
}

