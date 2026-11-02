#include "../runtime/slop_runtime.h"
#include "slop_alignmentreport.h"

slop_string howl_alignmentreport_boolean(uint8_t b);
slop_string howl_alignmentreport_line(slop_arena* a, slop_string key, slop_string value);
slop_string howl_alignmentreport_phase_line(slop_arena* a, slop_string name, howl_repair_Phase p);
slop_string howl_alignmentreport_indices_text(slop_arena* a, slop_list_int xs);
slop_list_string howl_alignmentreport_alignment_lines(slop_arena* a, slop_list_howl_types_AxiomRef refs, howl_repair_SearchResult s);

slop_string howl_alignmentreport_boolean(uint8_t b) {
    if (b) {
        return SLOP_STR("true");
    } else {
        return SLOP_STR("false");
    }
}

slop_string howl_alignmentreport_line(slop_arena* a, slop_string key, slop_string value) {
    return string_concat(a, key, string_concat(a, SLOP_STR(" "), value));
}

slop_string howl_alignmentreport_phase_line(slop_arena* a, slop_string name, howl_repair_Phase p) {
    return string_concat(a, howl_alignmentreport_line(a, SLOP_STR("search-phase"), name), string_concat(a, howl_alignmentreport_line(a, SLOP_STR(" exhausted"), howl_alignmentreport_boolean(p.exhausted)), string_concat(a, howl_alignmentreport_line(a, SLOP_STR(" capped"), howl_alignmentreport_boolean(p.capped)), howl_alignmentreport_line(a, SLOP_STR(" unresolved"), howl_alignmentreport_boolean(p.unresolved)))));
}

slop_string howl_alignmentreport_indices_text(slop_arena* a, slop_list_int xs) {
    {
        __auto_type text = SLOP_STR("");
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                text = string_concat(a, text, string_concat(a, (((string_len(text) == 0)) ? SLOP_STR("") : SLOP_STR(" ")), int_to_string(a, i)));
            }
        }
        return text;
    }
}

slop_list_string howl_alignmentreport_alignment_lines(slop_arena* a, slop_list_howl_types_AxiomRef refs, howl_repair_SearchResult s) {
    {
        __auto_type out = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = a });
        int64_t i = 0;
        __auto_type c = s.counts;
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (SLOP_STR("howl-repair 1")); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_line(a, SLOP_STR("search-complete"), howl_alignmentreport_boolean(s.complete))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_line(a, SLOP_STR("already-coherent"), howl_alignmentreport_boolean(s.already_coherent))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_line(a, SLOP_STR("unrepairable-by-mappings"), howl_alignmentreport_boolean(s.unrepairable))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_phase_line(a, SLOP_STR("conflicts"), s.conflict_phase)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_phase_line(a, SLOP_STR("hitting-sets"), s.hitting_phase)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_phase_line(a, SLOP_STR("verification"), s.verification_phase)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_line(a, SLOP_STR("preflight-calls"), int_to_string(a, c.preflight_calls))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_line(a, SLOP_STR("conflict-calls"), int_to_string(a, c.conflict_calls))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_line(a, SLOP_STR("conflict-nodes"), int_to_string(a, c.conflict_nodes))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_line(a, SLOP_STR("hitting-nodes"), int_to_string(a, c.hitting_nodes))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_line(a, SLOP_STR("verification-calls"), int_to_string(a, c.verification_calls))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_line(a, SLOP_STR("cache-hits"), int_to_string(a, c.cache_hits))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_line(a, SLOP_STR("search-omitted"), int_to_string(a, ((int64_t)(((int64_t)((s.omissions).len))))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        {
            __auto_type _coll = s.omissions;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type om = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_line(a, SLOP_STR("search-omission"), howl_owl2_render_omission(a, om))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_line(a, SLOP_STR("mappings"), int_to_string(a, ((int64_t)(((int64_t)((refs).len))))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        {
            __auto_type _coll = refs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ref = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (string_concat(a, howl_alignmentreport_line(a, SLOP_STR("mapping"), int_to_string(a, i)), string_concat(a, SLOP_STR(" <"), string_concat(a, ({ __auto_type _mv = ref.source; _mv.has_value ? ({ __auto_type iri = _mv.value; iri.value; }) : (SLOP_STR("")); }), string_concat(a, SLOP_STR("> "), ref.text))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                i = (i + 1);
            }
        }
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_line(a, SLOP_STR("verified-repairs"), int_to_string(a, ((int64_t)(((int64_t)((s.verified).len))))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        {
            __auto_type _coll = s.verified;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_line(a, SLOP_STR("repair"), howl_alignmentreport_indices_text(a, r.items))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_alignmentreport_line(a, SLOP_STR("candidates"), int_to_string(a, ((int64_t)(((int64_t)((s.candidates).len))))))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        {
            __auto_type _coll = s.candidates;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (string_concat(a, howl_alignmentreport_line(a, SLOP_STR("candidate"), howl_repair_candidate_reason_text(r.reason)), string_concat(a, SLOP_STR(" "), howl_alignmentreport_indices_text(a, r.removed)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

