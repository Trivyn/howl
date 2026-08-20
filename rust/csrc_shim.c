/*
 * Thin C shim for static inline arena functions from slop_runtime.h.
 * These are static inline in the header, so they have no exported
 * symbol. We wrap them here so Rust can link to them.
 */

#include "slop_runtime.h"
#include "slop_types.h"
#include "slop_howl.h"
#include <stddef.h>

/*
 * FFI LAYOUT GUARDS.
 *
 * These expose the REAL C ABI — struct sizes, and the offsets of
 * fields that sit after a by-value embedded struct — so the
 * hand-written Rust mirrors in src/ffi.rs can be asserted against it
 * in tests.
 *
 * This is not defensive boilerplate. A silent drift here is exactly
 * what regressed GROWL 0.6.0: slop-rdf added a 4th index (`pos`) to
 * `index_TripleIndex`, growing `index_IndexedGraph` by 8 bytes, but
 * the Rust `TripleIndex` mirror was not updated — so
 * `IndexedGraph.size` (and `ReasonerSuccess.iterations`) were read at
 * the WRONG OFFSET across the FFI boundary and `graph.size()` returned
 * a garbage pointer. Nothing failed loudly; the numbers were simply
 * wrong.
 *
 * HOWL is more exposed than GROWL was, not less, because the PORT is
 * the deliverable rather than the CLI (SPEC §8.4) — so these guards
 * exist from the first commit rather than being retrofitted after an
 * incident.
 *
 * ReasonerConfig is the sharpest case: SLOP range types lower to
 * NARROW integers — `(Int 1 .. 64)` becomes uint8_t, `(Int 0 .. 10000)`
 * becomes uint16_t — so a Rust mirror that reaches for the obvious
 * u32/usize is wrong in a way that compiles cleanly on both sides.
 */
size_t howl_layout_sizeof_reasoner_config(void)      { return sizeof(types_ReasonerConfig); }
size_t howl_layout_offset_cfg_worker_count(void)     { return offsetof(types_ReasonerConfig, worker_count); }
size_t howl_layout_offset_cfg_channel_buffer(void)   { return offsetof(types_ReasonerConfig, channel_buffer); }
size_t howl_layout_offset_cfg_max_iterations(void)   { return offsetof(types_ReasonerConfig, max_iterations); }
size_t howl_layout_offset_cfg_selection(void)        { return offsetof(types_ReasonerConfig, selection); }
size_t howl_layout_offset_cfg_strict_profile(void)   { return offsetof(types_ReasonerConfig, strict_profile); }
size_t howl_layout_offset_cfg_cancel_ptr(void)       { return offsetof(types_ReasonerConfig, cancel_ptr); }
size_t howl_layout_offset_cfg_verbose(void)          { return offsetof(types_ReasonerConfig, verbose); }

/*
 * FIELD WIDTHS, not just offsets.
 *
 * Sizes and offsets alone are NOT sufficient, and this was found by
 * deliberately drifting a mirror to check the guard bites. Widening
 * `strict_profile` from uint8_t to u32 on the Rust side changes
 * nothing observable: the field sits at offset 16, `cancel_ptr` is
 * 8-aligned at 24, and the seven bytes between them are padding. Every
 * offset and the total size stay identical, so an offset-only guard
 * passes — while the Rust side reads three bytes of padding into the
 * high bits of a value C wrote as one byte.
 *
 * That is the same class of silent wrong-value bug the offsets exist
 * to catch, arriving through the one gap they leave.
 */
size_t howl_layout_fieldsize_cfg_worker_count(void)   { return sizeof(((types_ReasonerConfig*)0)->worker_count); }
size_t howl_layout_fieldsize_cfg_channel_buffer(void) { return sizeof(((types_ReasonerConfig*)0)->channel_buffer); }
size_t howl_layout_fieldsize_cfg_max_iterations(void) { return sizeof(((types_ReasonerConfig*)0)->max_iterations); }
size_t howl_layout_fieldsize_cfg_strict_profile(void) { return sizeof(((types_ReasonerConfig*)0)->strict_profile); }
size_t howl_layout_fieldsize_cfg_cancel_ptr(void)     { return sizeof(((types_ReasonerConfig*)0)->cancel_ptr); }
size_t howl_layout_fieldsize_cfg_verbose(void)        { return sizeof(((types_ReasonerConfig*)0)->verbose); }

size_t howl_layout_sizeof_profile_selection(void)    { return sizeof(types_ProfileSelection); }
size_t howl_layout_sizeof_rdf_term(void)             { return sizeof(rdf_Term); }
size_t howl_layout_sizeof_rdf_triple(void)           { return sizeof(rdf_Triple); }
size_t howl_layout_offset_triple_predicate(void)     { return offsetof(rdf_Triple, predicate); }
size_t howl_layout_offset_triple_object(void)        { return offsetof(rdf_Triple, object); }

slop_arena* howl_arena_new(size_t capacity) {
    slop_arena* a = (slop_arena*)malloc(sizeof(slop_arena));
    if (!a) return NULL;
    *a = slop_arena_new(capacity);
    if (a->base == NULL) {
        free(a);
        return NULL;
    }
    return a;
}

void howl_arena_free(slop_arena* arena) {
    if (!arena) return;
    slop_arena_free(arena);
    free(arena);
}

slop_string howl_intern_string(const char* data, size_t len) {
    return slop_intern_string(data, len);
}
