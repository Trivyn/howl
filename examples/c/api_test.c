/*
 * HOWL's C API, every entry point, as a C caller drives it. Built by
 * `make c-example` under AddressSanitizer and UndefinedBehaviorSanitizer.
 *
 * For each fixture named on the command line, on both built profiles at
 * W in {1, 2, 4}: the Turtle is added and its buffer freed BEFORE
 * classifying (the input must not borrow it), a second document of
 * triples follows, and the input is classified twice. Every accessor is
 * read; both runs, and every worker count, must give the same report. W = 1
 * matters: there the engine's only commit arena is the run's own, and a
 * run that freed it twice once crashed only under that configuration.
 *
 * Then the refusals: out-of-range options, an unbuilt profile, a term
 * HOWL does not take, and Turtle that does not parse.
 */
#include "howl.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int failures = 0;

#define CHECK(cond, ...) do { if (!(cond)) { failures++; fprintf(stderr, "FAIL: " __VA_ARGS__); fputc('\n', stderr); } } while (0)

static slop_string str(const char* s) { return (slop_string){ strlen(s), s }; }

static char* read_file(const char* path, size_t* len) {
    FILE* f = fopen(path, "rb");
    if (!f) { perror(path); exit(2); }
    fseek(f, 0, SEEK_END);
    *len = (size_t)ftell(f);
    rewind(f);
    char* text = malloc(*len ? *len : 1);
    if (fread(text, 1, *len, f) != *len) { perror(path); exit(2); }
    fclose(f);
    return text;
}

/* The report as one buffer, every accessor read on the way. */
static char* report_of(howl_Run run) {
    size_t cap = 1 << 16, n = 0;
    char* out = malloc(cap);
    for (int64_t i = 0; i < howl_run_report_len(run); i++) {
        slop_string l = howl_run_report_line(run, i);
        while (n + l.len + 2 > cap) out = realloc(out, cap *= 2);
        memcpy(out + n, l.data, l.len);
        n += l.len;
        out[n++] = '\n';
    }
    out[n] = 0;
    size_t touched = 0;
    for (int64_t i = 0; i < howl_run_unsat_len(run); i++) touched += howl_run_unsat(run, i).len;
    for (int64_t i = 0; i < howl_run_sub_len(run); i++)
        touched += howl_run_sub(run, i).len + howl_run_super(run, i).len;
    for (int64_t i = 0; i < howl_run_omission_len(run); i++) touched += howl_run_omission(run, i).len;
    (void)howl_run_termination(run);
    (void)howl_run_rounds(run);
    (void)howl_run_inconsistent(run);
    (void)howl_run_profile(run);
    (void)touched;
    return out;
}

static howl_TermIn iri(const char* v) {
    return (howl_TermIn){ .kind = rdf_TermKind_iri, .value = str(v), .datatype = str(""), .lang = str("") };
}

static howl_Input input_for(const char* path) {
    size_t len;
    char* text = read_file(path, &len);
    howl_Input in = howl_input_new();
    howl_TurtleResult r = howl_input_add_turtle(in, (slop_string){ len, text });
    memset(text, 'x', len);  /* any borrowed byte would now be wrong */
    free(text);
    CHECK(r.ok, "%s does not parse", path);
    /* A second document, with a typed literal and a blank node. */
    howl_input_begin_document(in);
    howl_TermIn lit = { .kind = rdf_TermKind_literal, .value = str("7"),
                        .datatype = str("http://www.w3.org/2001/XMLSchema#integer"), .lang = str("") };
    howl_TermIn b = { .kind = rdf_TermKind_blank, .blank = 0, .value = str(""), .datatype = str(""), .lang = str("") };
    CHECK(howl_input_add_triple(in, iri("http://example.org/api#x"),
                                iri("http://www.w3.org/2000/01/rdf-schema#comment"), lit), "add a literal");
    CHECK(howl_input_add_triple(in, b, iri("http://www.w3.org/2000/01/rdf-schema#label"), lit), "add a blank");
    howl_input_attest_import(in, str("http://example.org/api"));
    return in;
}

static void fixture(const char* path) {
    types_Profile profiles[] = { types_Profile_profile_el, types_Profile_profile_el_plus_plus };
    for (int p = 0; p < 2; p++) {
        char* first = NULL;
        for (int w = 1; w <= 4; w *= 2) {
            howl_Input in = input_for(path);
            howl_Options o = howl_default_options();
            o.profile = profiles[p];
            o.workers = w;
            for (int rep = 0; rep < 2; rep++) {
                howl_Run run = howl_run_classify(in, o);
                CHECK(howl_run_ok(run), "%s: no result (fault %d)", path, (int)howl_run_fault(run));
                CHECK(howl_run_fault(run) == howl_FaultKind_fault_none, "%s: fault on an ok run", path);
                char* rep_text = report_of(run);
                if (!first) first = rep_text;
                else {
                    CHECK(strcmp(first, rep_text) == 0, "%s: report differs at W=%d, profile %d, run %d", path, w, p, rep);
                    free(rep_text);
                }
                howl_run_free(run);
            }
            howl_input_free(in);
        }
        free(first);
    }
}

static void refusals(const char* path) {
    howl_Input in = input_for(path);

    howl_Options o = howl_default_options();
    o.workers = 0;
    howl_Run r = howl_run_classify(in, o);
    CHECK(!howl_run_ok(r) && howl_run_fault(r) == howl_FaultKind_fault_invalid_options, "workers 0 accepted");
    CHECK(howl_run_verdict(r) == types_Verdict_verdict_inconclusive, "a faulted run's verdict is not inconclusive");
    CHECK(howl_run_report_len(r) == 0 && howl_run_sub_len(r) == 0, "a faulted run has lines");
    howl_run_free(r);

    o = howl_default_options();
    o.max_iterations = 10001;
    r = howl_run_classify(in, o);
    CHECK(howl_run_fault(r) == howl_FaultKind_fault_invalid_options, "max_iterations 10001 accepted");
    howl_run_free(r);

    o = howl_default_options();
    o.profile = types_Profile_profile_horn_sriq;
    r = howl_run_classify(in, o);
    CHECK(howl_run_fault(r) == howl_FaultKind_fault_unavailable, "horn-sriq not refused");
    CHECK(howl_run_fault_profile(r) == types_Profile_profile_horn_sriq, "unavailable names another profile");
    howl_run_free(r);

    uint32_t flag = 1;
    o = howl_default_options();
    o.cancel = (int64_t)(uintptr_t)&flag;
    r = howl_run_classify(in, o);
    CHECK(howl_run_fault(r) == howl_FaultKind_fault_cancelled, "a set cancel flag did not cancel");
    howl_run_free(r);
    howl_input_free(in);

    in = howl_input_new();
    howl_TermIn quoted = { .kind = rdf_TermKind_triple, .value = str(""), .datatype = str(""), .lang = str("") };
    CHECK(!howl_input_add_triple(in, quoted, iri("http://example.org/p"), iri("http://example.org/o")),
          "a quoted triple was taken");
    r = howl_run_classify(in, howl_default_options());
    CHECK(howl_run_fault(r) == howl_FaultKind_fault_input_error, "a refused term did not refuse the input");
    howl_run_free(r);
    howl_input_free(in);

    in = howl_input_new();
    howl_TurtleResult t = howl_input_add_turtle(in, str("<http://example.org/a> <http://example.org/b> ."));
    CHECK(!t.ok && t.line >= 1 && t.message.len > 0, "bad Turtle parsed");
    r = howl_run_classify(in, howl_default_options());
    CHECK(howl_run_fault(r) == howl_FaultKind_fault_input_error, "a failed document did not refuse the input");
    /* A run's strings outlive its input: read the message after the input
     * is gone (ASan reports a use-after-free if it was borrowed). */
    howl_input_free(in);
    slop_string m = howl_run_fault_message(r);
    CHECK(m.len > 0 && memchr(m.data, ':', m.len) != NULL, "an input error without its message");
    howl_run_free(r);

    in = howl_input_new();
    howl_TermIn huge = { .kind = rdf_TermKind_blank, .blank = INT64_MAX, .value = str(""), .datatype = str(""), .lang = str("") };
    CHECK(!howl_input_add_triple(in, huge, iri("http://example.org/p"), iri("http://example.org/o")),
          "a blank id near INT64_MAX was taken");
    howl_input_begin_document(in);  /* must not overflow */
    howl_input_free(in);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s fixture.ttl...\n", argv[0]);
        return 2;
    }
    for (int i = 1; i < argc; i++) fixture(argv[i]);
    refusals(argv[1]);
    if (failures) {
        fprintf(stderr, "%d check(s) failed\n", failures);
        return 1;
    }
    printf("C API: %d fixtures x {el, el++} x W in {1,2,4}, twice each; refusals: ok\n", argc - 1);
    return 0;
}
