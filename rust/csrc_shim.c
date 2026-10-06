/*
 * The C side of the Rust binding.
 *
 * ENGINE RESULTS NEVER CROSS AS STRUCTS. An Outcome embeds its Evidence
 * by value, and Evidence holds a whole Saturation or KscResult: dozens
 * of engine-internal structs whose layout changes with every engine
 * change. Mirroring them in Rust is the GROWL 0.6.0 hazard (below) over
 * the largest surface HOWL has. So the result stays here, behind an
 * opaque handle, and Rust reads it through the accessors at the bottom
 * of this file. They are compiled against the real headers, so a field
 * that moves or changes type is a C compile error, not a silent misread.
 *
 * What does cross by value is small and pinned by the layout guards in
 * src/ffi.rs: `types_ReasonerConfig` (the engine's), `howl_term` (this
 * file's own), and `slop_string`.
 *
 * THE INPUT IS ENCODED AS THE CLI ENCODES IT: one termstore Encoded,
 * each document after the first standardized apart by
 * `encoded-next-document`, exactly as `howl validate ... -I FILE` does,
 * and classified by `howl.classify-encoded`, the CLI's own path as one
 * call. That is what lets the CLI's committed goldens certify this
 * binding's reports byte for byte (rust/tests/goldens.rs).
 */

#include "slop_runtime.h"
#include "slop_types.h"
#include "slop_howl.h"
#include "slop_termstore.h"
#include "slop_report.h"
#include "slop_owl2.h"
#include "slop_ttl.h"
#include "slop_rdf.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/* Arenas                                                             */
/* ------------------------------------------------------------------ */

static slop_arena* shim_arena_new(size_t capacity) {
    slop_arena* a = (slop_arena*)malloc(sizeof(slop_arena));
    if (!a) return NULL;
    *a = slop_arena_new(capacity);
    if (a->base == NULL) {
        free(a);
        return NULL;
    }
    return a;
}

static void shim_arena_free(slop_arena* a) {
    if (!a) return;
    slop_arena_free(a);
    free(a);
}

static slop_string shim_copy(slop_arena* a, const char* data, size_t len) {
    char* buf = len ? (char*)slop_arena_alloc(a, len) : NULL;
    if (len) memcpy(buf, data, len);
    return (slop_string){ .len = len, .data = buf };
}

/* ------------------------------------------------------------------ */
/* Input                                                              */
/* ------------------------------------------------------------------ */

/* A term as Rust hands it over. Strings are borrowed for the duration
 * of the call that receives them; `encoded-add` copies what it keeps.
 * A NULL `datatype` or `lang` means absent. */
#define HOWL_TERM_IRI     0u
#define HOWL_TERM_BLANK   1u
#define HOWL_TERM_LITERAL 2u

typedef struct {
    uint32_t    kind;
    int64_t     blank;
    const char* value;    size_t value_len;
    const char* datatype; size_t datatype_len;
    const char* lang;     size_t lang_len;
} howl_term;

typedef struct howl_input {
    slop_arena*        arena;     /* the Encoded and the attested IRIs */
    termstore_Encoded* enc;
    slop_list_rdf_IRI  imports;
    int64_t            documents;
} howl_input;

howl_input* howl_input_new(void) {
    slop_arena* a = shim_arena_new(16u << 20);
    if (!a) return NULL;
    howl_input* in = (howl_input*)slop_arena_alloc(a, sizeof(howl_input));
    in->arena = a;
    in->enc = termstore_new_encoded(a);
    in->imports = (slop_list_rdf_IRI){ .len = 0, .cap = 0, .data = NULL, .arena = a };
    in->documents = 0;
    return in;
}

void howl_input_free(howl_input* in) {
    if (in) shim_arena_free(in->arena);
}

/* Every document after the first has its blank ids shifted apart. */
void howl_input_begin_document(howl_input* in) {
    if (in->documents > 0) termstore_encoded_next_document(in->arena, in->enc);
    in->documents++;
}

static rdf_Term shim_term(slop_arena* a, const howl_term* t) {
    slop_string v = { .len = t->value_len, .data = t->value };
    switch (t->kind) {
    case HOWL_TERM_IRI:   return rdf_make_iri(a, v);
    case HOWL_TERM_BLANK: return rdf_make_blank(a, t->blank);
    default: {
        slop_option_string dt = { .has_value = false };
        slop_option_string lang = { .has_value = false };
        if (t->datatype) dt = (slop_option_string){ true, { t->datatype_len, t->datatype } };
        if (t->lang) lang = (slop_option_string){ true, { t->lang_len, t->lang } };
        return rdf_make_literal(a, v, dt, lang);
    }
    }
}

/* `terms` holds 3 * n terms: subject, predicate, object per triple. */
void howl_input_add_triples(howl_input* in, const howl_term* terms, size_t n) {
    slop_arena* scratch = shim_arena_new(1u << 20);
    if (!scratch) abort();
    for (size_t i = 0; i < n; i++) {
        const howl_term* t = terms + 3 * i;
        rdf_Triple tr = rdf_make_triple(scratch, shim_term(scratch, t),
                                        shim_term(scratch, t + 1), shim_term(scratch, t + 2));
        termstore_encoded_add(in->arena, in->enc, tr);
    }
    shim_arena_free(scratch);
}

typedef struct { slop_arena* arena; termstore_Encoded* enc; } shim_add_env;

static void shim_add(shim_add_env* env, rdf_Triple t) {
    termstore_encoded_add(env->arena, env->enc, t);
}

/* Stream one Turtle document into the input, as the CLI's `parse-into`
 * does: the parser's memory is a scratch arena freed on return, and only
 * what `encoded-add` copies survives. Returns 1 on success; on failure
 * writes the parser's message (copied into the input's arena) and
 * position, and the triples before the error stay encoded. */
int howl_input_add_turtle(howl_input* in, const char* text, size_t len,
                          slop_string* message, int64_t* line, int64_t* column) {
    if (len == 0) return 1;  /* an empty document has no triples */
    slop_arena* parse = shim_arena_new(16u << 20);
    if (!parse) abort();
    shim_add_env* env = (shim_add_env*)slop_arena_alloc(parse, sizeof(shim_add_env));
    *env = (shim_add_env){ .arena = in->arena, .enc = in->enc };
    slop_closure_t cb = { (void*)shim_add, (void*)env };
    slop_result_int_common_ParseError r =
        ttl_parse_ttl_string_for_each_triple(parse, (slop_string){ len, text }, cb);
    int ok = r.is_ok ? 1 : 0;
    if (!ok) {
        *message = shim_copy(in->arena, r.data.err.message.data, r.data.err.message.len);
        *line = r.data.err.position.line;
        *column = r.data.err.position.column;
    }
    shim_arena_free(parse);
    return ok;
}

/* The caller's closure attestation (SPEC §8.5 A2): an owl:imports IRI it
 * resolved and whose document it added. */
void howl_input_attest_import(howl_input* in, const char* iri, size_t len) {
    rdf_IRI i = { .value = shim_copy(in->arena, iri, len) };
    slop_list_rdf_IRI_push(in->arena, &in->imports, i);
}

/* ------------------------------------------------------------------ */
/* Run                                                                */
/* ------------------------------------------------------------------ */

typedef struct howl_run {
    slop_arena*                           arena;
    slop_result_types_Outcome_types_Fault res;
    howl_Verdict                          verdict;
    slop_list_string                      lines;
} howl_run;

/* The library always runs non-strict (SPEC §8.4): an omission is a
 * report, not a refusal, so `strict_profile` is forced off whatever the
 * caller passed. */
howl_run* howl_run_classify(const howl_input* in, types_ReasonerConfig config) {
    slop_arena* a = shim_arena_new(16u << 20);
    if (!a) return NULL;
    howl_run* r = (howl_run*)slop_arena_alloc(a, sizeof(howl_run));
    memset(r, 0, sizeof(*r));
    r->arena = a;
    config.strict_profile = 0;
    r->res = howl_classify_encoded(a, *in->enc, in->imports, config);
    if (r->res.is_ok) {
        r->verdict = howl_verdict(r->res.data.ok);
        r->lines = report_report_lines(a, r->res.data.ok);
    }
    return r;
}

/* el's store and last queues live in arenas of the engine's own, which
 * the Outcome carries; they go first, then everything copied into ours. */
void howl_run_free(howl_run* r) {
    if (!r) return;
    if (r->res.is_ok) howl_release_outcome(r->res.data.ok);
    shim_arena_free(r->arena);
}

/* Faults (only when !ok) */
int         howl_run_ok(const howl_run* r)            { return r->res.is_ok ? 1 : 0; }
int         howl_run_fault_tag(const howl_run* r)     { return (int)r->res.data.err.tag; }
slop_string howl_run_fault_message(const howl_run* r) { return r->res.data.err.data.input_error; }
int         howl_run_fault_profile(const howl_run* r) { return (int)r->res.data.err.data.unavailable; }
size_t      howl_run_refused_len(const howl_run* r)   { return r->res.data.err.data.refused.len; }
slop_string howl_run_refused(howl_run* r, size_t i) {
    return owl2_render_omission(r->arena, r->res.data.err.data.refused.data[i]);
}

/* The Outcome (only when ok) */
int     howl_run_profile(const howl_run* r)         { return (int)r->res.data.ok.profile; }
int     howl_run_verdict(const howl_run* r)         { return (int)r->verdict; }
int     howl_run_inconsistent(const howl_run* r)    { return r->res.data.ok.findings.inconsistent ? 1 : 0; }
int     howl_run_termination_tag(const howl_run* r) { return (int)r->res.data.ok.termination.tag; }
int64_t howl_run_resource_limit(const howl_run* r)  { return r->res.data.ok.termination.data.resource_limit; }
int64_t howl_run_rounds(const howl_run* r)          { return r->res.data.ok.rounds; }

size_t howl_run_unsat_len(const howl_run* r) { return r->res.data.ok.findings.unsatisfiable.len; }
slop_string howl_run_unsat(const howl_run* r, size_t i) {
    return r->res.data.ok.findings.unsatisfiable.data[i].value;
}

/* Nodes are rendered by the report's own `node-text`, so a pair here and
 * a `sub` line in the report can never disagree. */
size_t howl_run_sub_len(const howl_run* r) { return r->res.data.ok.findings.subsumptions.len; }
slop_string howl_run_sub(howl_run* r, size_t i) {
    return report_node_text(r->arena, r->res.data.ok.findings.subsumptions.data[i].sub);
}
slop_string howl_run_super(howl_run* r, size_t i) {
    return report_node_text(r->arena, r->res.data.ok.findings.subsumptions.data[i].super);
}

/* Omissions are rendered by the report's own `render-omission`. */
size_t howl_run_omission_len(const howl_run* r) { return r->res.data.ok.coverage.omitted.len; }
slop_string howl_run_omission(howl_run* r, size_t i) {
    return owl2_render_omission(r->arena, r->res.data.ok.coverage.omitted.data[i]);
}

size_t      howl_run_report_len(const howl_run* r)            { return r->lines.len; }
slop_string howl_run_report_line(const howl_run* r, size_t i) { return r->lines.data[i]; }

/* ------------------------------------------------------------------ */
/* FFI LAYOUT GUARDS                                                  */
/* ------------------------------------------------------------------ */

/*
 * These expose the REAL C ABI — struct sizes, field offsets and widths,
 * enum discriminants — so the hand-written Rust mirrors in src/ffi.rs
 * can be asserted against it in tests.
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
 */
size_t howl_layout_fieldsize_cfg_worker_count(void)   { return sizeof(((types_ReasonerConfig*)0)->worker_count); }
size_t howl_layout_fieldsize_cfg_channel_buffer(void) { return sizeof(((types_ReasonerConfig*)0)->channel_buffer); }
size_t howl_layout_fieldsize_cfg_max_iterations(void) { return sizeof(((types_ReasonerConfig*)0)->max_iterations); }
size_t howl_layout_fieldsize_cfg_strict_profile(void) { return sizeof(((types_ReasonerConfig*)0)->strict_profile); }
size_t howl_layout_fieldsize_cfg_cancel_ptr(void)     { return sizeof(((types_ReasonerConfig*)0)->cancel_ptr); }
size_t howl_layout_fieldsize_cfg_verbose(void)        { return sizeof(((types_ReasonerConfig*)0)->verbose); }

size_t howl_layout_sizeof_profile_selection(void)    { return sizeof(types_ProfileSelection); }
/* The Profile enum's discriminants, one per rung: a mirror whose variants
 * drift out of the C order still has the right SIZE, and would hand the
 * engine a different rung than the caller named. */
int howl_layout_profile_el(void)                     { return types_Profile_profile_el; }
int howl_layout_profile_el_plus_plus(void)           { return types_Profile_profile_el_plus_plus; }
int howl_layout_profile_horn_sriq(void)              { return types_Profile_profile_horn_sriq; }
int howl_layout_profile_sriq(void)                   { return types_Profile_profile_sriq; }

/* The discriminants Rust reads back from a run. A reordered verdict enum
 * is the worst drift there is: `coherent` and `inconclusive` trade
 * places and a gap reads as a pass. */
int howl_layout_verdict_coherent(void)               { return howl_Verdict_verdict_coherent; }
int howl_layout_verdict_incoherent(void)             { return howl_Verdict_verdict_incoherent; }
int howl_layout_verdict_inconclusive(void)           { return howl_Verdict_verdict_inconclusive; }
int howl_layout_termination_fixpoint(void)           { return types_Termination_fixpoint; }
int howl_layout_termination_resource_limit(void)     { return types_Termination_resource_limit; }
int howl_layout_fault_cancelled(void)                { return types_Fault_cancelled; }
int howl_layout_fault_input_error(void)              { return types_Fault_input_error; }
int howl_layout_fault_refused(void)                  { return types_Fault_refused; }
int howl_layout_fault_unavailable(void)              { return types_Fault_unavailable; }

size_t howl_layout_sizeof_slop_string(void)          { return sizeof(slop_string); }
size_t howl_layout_offset_string_data(void)          { return offsetof(slop_string, data); }

size_t howl_layout_sizeof_howl_term(void)            { return sizeof(howl_term); }
size_t howl_layout_offset_term_blank(void)           { return offsetof(howl_term, blank); }
size_t howl_layout_offset_term_value(void)           { return offsetof(howl_term, value); }
size_t howl_layout_offset_term_value_len(void)       { return offsetof(howl_term, value_len); }
size_t howl_layout_offset_term_datatype(void)        { return offsetof(howl_term, datatype); }
size_t howl_layout_offset_term_datatype_len(void)    { return offsetof(howl_term, datatype_len); }
size_t howl_layout_offset_term_lang(void)            { return offsetof(howl_term, lang); }
size_t howl_layout_offset_term_lang_len(void)        { return offsetof(howl_term, lang_len); }
size_t howl_layout_fieldsize_term_kind(void)         { return sizeof(((howl_term*)0)->kind); }
