/*
 * HOWL's C API, every entry point, as a C caller drives it. Built by
 * `make c-example` under AddressSanitizer and UndefinedBehaviorSanitizer.
 *
 * For each fixture named on the command line, on every built profile at
 * W in {1, 2, 4}: the Turtle is added and its buffer freed BEFORE
 * classifying (the input must not borrow it), a second document of
 * triples follows, and the input is classified twice. Every accessor is
 * read; both runs, and every worker count, must give the same report. W = 1
 * matters: there the engine's only commit arena is the run's own, and a
 * run that freed it twice once crashed only under that configuration.
 *
 * Then probe queries (SPEC §8.4, issue #68): a probe document as Turtle
 * and another as triples, three queries, and their answers through every
 * probe accessor, on every built profile. Then each omission's kind and
 * document (issue #67), in the main run and the probe run. Every
 * omission's reason (issue #125) must agree with its kind, and name a
 * role exactly when it is a non-simple role.
 *
 * Then the refusals: out-of-range options, the dropped profile, a term
 * HOWL does not take, and Turtle that does not parse.
 */
#include "howl.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int failures = 0;

#define CHECK(cond, ...) do { if (!(cond)) { failures++; fprintf(stderr, "FAIL: " __VA_ARGS__); fputc('\n', stderr); } } while (0)

static slop_string str(const char* s) { return (slop_string){ strlen(s), s }; }
static int msg_is(slop_string m, const char* want) { return m.len == strlen(want) && memcmp(m.data, want, m.len) == 0; }
static int same_str(slop_string a, slop_string b) { return a.len == b.len && memcmp(a.data, b.data, a.len) == 0; }

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

/* An omission's reason agrees with its kind; only a non-simple role names a role. */
static void check_reason(slop_string kind, howl_types_OmissionReason why, slop_string role, const char* run) {
    int undeclared = msg_is(kind, "MissingDeclaration") || msg_is(kind, "UndeclaredProperty");
    CHECK(undeclared == (why == howl_types_OmissionReason_reason_undeclared),
          "%s: a %.*s omission has reason %d", run, (int)kind.len, kind.data, (int)why);
    CHECK(msg_is(kind, "UnresolvedImport") == (why == howl_types_OmissionReason_reason_unresolved_import),
          "%s: a %.*s omission has reason %d", run, (int)kind.len, kind.data, (int)why);
    CHECK(!msg_is(kind, "Unrecognized") || why == howl_types_OmissionReason_reason_unrecognized,
          "%s: an Unrecognized omission has reason %d", run, (int)why);
    CHECK((role.len > 0) == (why == howl_types_OmissionReason_reason_non_simple_role),
          "%s: reason %d with a role of length %zu", run, (int)why, (size_t)role.len);
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
    for (int64_t i = 0; i < howl_run_omission_len(run); i++) {
        touched += howl_run_omission(run, i).len + howl_run_omission_kind(run, i).len
                 + (size_t)howl_run_omission_entity_kind(run, i) + (size_t)(howl_run_omission_document(run, i) + 1);
        check_reason(howl_run_omission_kind(run, i), howl_run_omission_reason(run, i),
                     howl_run_omission_reason_role(run, i), "main run");
    }
    for (int64_t i = 0; i < howl_run_probe_len(run); i++)
        touched += howl_run_probe_sub(run, i).len + howl_run_probe_sup(run, i).len
                 + (size_t)howl_run_probe_kind(run, i) + (size_t)howl_run_probe_answer(run, i);
    for (int64_t i = 0; i < howl_run_probe_omission_len(run); i++) {
        touched += howl_run_probe_omission(run, i).len + howl_run_probe_omission_kind(run, i).len
                 + (size_t)howl_run_probe_omission_entity_kind(run, i) + (size_t)howl_run_probe_omission_source(run, i)
                 + (size_t)(howl_run_probe_omission_document(run, i) + 1);
        check_reason(howl_run_probe_omission_kind(run, i), howl_run_probe_omission_reason(run, i),
                     howl_run_probe_omission_reason_role(run, i), "probe run");
    }
    /* Out of range: empty, entity-class, no document - never a read past the end. */
    CHECK(howl_run_omission_kind(run, -1).len == 0 && howl_run_omission_document(run, howl_run_omission_len(run)) == -1
          && howl_run_probe_omission_source(run, -1) == howl_DocumentSource_document_none
          && howl_run_probe_omission_document(run, howl_run_probe_omission_len(run)) == -1
          && howl_run_omission_entity_kind(run, -1) == howl_types_EntityKind_entity_class
          && howl_run_omission_reason(run, -1) == howl_types_OmissionReason_reason_out_of_profile
          && howl_run_omission_reason_role(run, howl_run_omission_len(run)).len == 0
          && howl_run_probe_omission_reason(run, howl_run_probe_omission_len(run)) == howl_types_OmissionReason_reason_out_of_profile
          && howl_run_probe_omission_reason_role(run, -1).len == 0,
          "an out-of-range omission accessor is not total");
    (void)howl_run_probe_inconsistent(run);
    (void)howl_run_termination(run);
    (void)howl_run_rounds(run);
    (void)howl_run_inconsistent(run);
    (void)howl_run_profile(run);
    (void)touched;
    return out;
}

static howl_TermIn iri(const char* v) {
    return (howl_TermIn){ .kind = slop_rdf_rdf_TermKind_iri, .value = str(v), .datatype = str(""), .lang = str("") };
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
    howl_TermIn lit = { .kind = slop_rdf_rdf_TermKind_literal, .value = str("7"),
                        .datatype = str("http://www.w3.org/2001/XMLSchema#integer"), .lang = str("") };
    howl_TermIn b = { .kind = slop_rdf_rdf_TermKind_blank, .blank = 0, .value = str(""), .datatype = str(""), .lang = str("") };
    CHECK(howl_input_add_triple(in, iri("http://example.org/api#x"),
                                iri("http://www.w3.org/2000/01/rdf-schema#comment"), lit), "add a literal");
    CHECK(howl_input_add_triple(in, b, iri("http://www.w3.org/2000/01/rdf-schema#label"), lit), "add a blank");
    howl_input_attest_import(in, str("http://example.org/api"));
    return in;
}

static void fixture(const char* path) {
    howl_types_Profile profiles[] = { howl_types_Profile_profile_el, howl_types_Profile_profile_el_plus_plus, howl_types_Profile_profile_sriq };
    for (int p = 0; p < 3; p++) {
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

/* `:p`'s two domains are disjoint, so it cannot have a value; `:q` can. */
static const char* PROBE_MAIN =
    "@prefix : <http://example.org/t#> . @prefix owl: <http://www.w3.org/2002/07/owl#> .\n"
    "@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n"
    ":p a owl:ObjectProperty . :q a owl:ObjectProperty .\n"
    ":D a owl:Class . :E a owl:Class . :D owl:disjointWith :E . :p rdfs:domain :D , :E .\n";
static const char* PROBE_DOC =
    "@prefix : <http://example.org/t#> . @prefix owl: <http://www.w3.org/2002/07/owl#> .\n"
    "@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n"
    "<urn:probe:p> rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :p ; owl:someValuesFrom owl:Thing ] .\n"
    "<urn:probe:q> rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :q ; owl:someValuesFrom owl:Thing ] .\n";

static int answer_is(howl_Run r, int64_t i, howl_probe_QueryKind k, const char* sub, const char* sup,
                     howl_probe_ProbeAnswer a) {
    return howl_run_probe_kind(r, i) == k && msg_is(howl_run_probe_sub(r, i), sub)
        && msg_is(howl_run_probe_sup(r, i), sup) && howl_run_probe_answer(r, i) == a;
}

static void probes(void) {
    howl_types_Profile profiles[] = { howl_types_Profile_profile_el, howl_types_Profile_profile_el_plus_plus, howl_types_Profile_profile_sriq };
    for (int p = 0; p < 3; p++) {
        howl_Input in = howl_input_new();
        CHECK(howl_input_add_turtle(in, str(PROBE_MAIN)).ok, "the probe scenario does not parse");
        CHECK(howl_input_add_probe_turtle(in, str(PROBE_DOC)).ok, "the probe document does not parse");
        /* A second probe document, as triples: urn:probe:t is under urn:probe:p. */
        howl_input_begin_probe_document(in);
        CHECK(howl_input_add_probe_triple(in, iri("urn:probe:t"),
                                          iri("http://www.w3.org/2000/01/rdf-schema#subClassOf"),
                                          iri("urn:probe:p")), "add a probe triple");
        howl_input_ask_unsatisfiable(in, str("urn:probe:q"));
        howl_input_ask_unsatisfiable(in, str("urn:probe:p"));
        howl_input_ask_unsatisfiable(in, str("urn:probe:t"));
        howl_input_ask_subsumed(in, str("urn:probe:t"), str("http://example.org/t#D"));
        howl_input_ask_unsatisfiable(in, str("urn:probe:t"));  /* asked twice, answered once */
        howl_Options o = howl_default_options();
        o.profile = profiles[p];
        howl_Run r = howl_run_classify(in, o);
        CHECK(howl_run_ok(r) && howl_run_verdict(r) == howl_types_Verdict_verdict_coherent,
              "profile %d: the main run is not coherent", p);
        CHECK(howl_run_unsat_len(r) == 0, "profile %d: a probe class reached unsatisfiable", p);
        CHECK(howl_run_probe_len(r) == 4, "profile %d: %lld answers", p, (long long)howl_run_probe_len(r));
        CHECK(answer_is(r, 0, howl_probe_QueryKind_query_unsatisfiable, "urn:probe:p", "", howl_probe_ProbeAnswer_answer_yes)
              && answer_is(r, 1, howl_probe_QueryKind_query_unsatisfiable, "urn:probe:q", "", howl_probe_ProbeAnswer_answer_no)
              && answer_is(r, 2, howl_probe_QueryKind_query_unsatisfiable, "urn:probe:t", "", howl_probe_ProbeAnswer_answer_yes)
              && answer_is(r, 3, howl_probe_QueryKind_query_subsumed, "urn:probe:t", "http://example.org/t#D",
                           howl_probe_ProbeAnswer_answer_yes),
              "profile %d: wrong probe answers", p);
        CHECK(!howl_run_probe_inconsistent(r) && howl_run_probe_omission_len(r) == 0,
              "profile %d: the probe run was not clean", p);
        CHECK(howl_run_probe_len(r) >= 0 && howl_run_probe_sub(r, 99).len == 0
              && howl_run_probe_answer(r, 99) == howl_probe_ProbeAnswer_answer_unknown,
              "profile %d: an out-of-range probe answer is not empty and unknown", p);
        /* The answer run (SPEC §8.4): the same answers, with no main run. */
        howl_Run a = howl_run_answer(in, o);
        CHECK(howl_run_ok(a) && howl_run_probe_len(a) == howl_run_probe_len(r),
              "profile %d: the answer run did not answer as classify does", p);
        for (int64_t i = 0; i < howl_run_probe_len(r); i++)
            CHECK(howl_run_probe_kind(a, i) == howl_run_probe_kind(r, i)
                  && howl_run_probe_answer(a, i) == howl_run_probe_answer(r, i)
                  && same_str(howl_run_probe_sub(a, i), howl_run_probe_sub(r, i))
                  && same_str(howl_run_probe_sup(a, i), howl_run_probe_sup(r, i)),
                  "profile %d: answer %lld differs from classify's", p, (long long)i);
        CHECK(howl_run_profile(a) == profiles[p] && howl_run_unsat_len(a) == 0 && howl_run_sub_len(a) == 0
              && howl_run_verdict(a) == howl_types_Verdict_verdict_inconclusive
              && howl_run_report_len(a) == 4 + 4 && msg_is(howl_run_report_line(a, 1), "probes 4"),
              "profile %d: the answer run has a report, or the wrong lines", p);
        free(report_of(a));
        howl_run_free(a);
        free(report_of(r));
        howl_run_free(r);
        howl_input_free(in);
    }
    /* A probe document that faults its run takes the whole run with it,
     * after the main run finished: its outcome must be released, once. */
    {
        howl_Input in = howl_input_new();
        CHECK(howl_input_add_turtle(in, str(PROBE_MAIN)).ok, "the probe scenario does not parse");
        CHECK(howl_input_add_probe_turtle(in, str("<urn:p> a <http://www.w3.org/2002/07/owl#ObjectProperty> , "
                                                  "<http://www.w3.org/2002/07/owl#AnnotationProperty> .")).ok,
              "the faulting probe document does not parse");
        howl_input_ask_unsatisfiable(in, str("urn:P"));
        howl_Run r = howl_run_classify(in, howl_default_options());
        CHECK(!howl_run_ok(r) && howl_run_fault(r) == howl_FaultKind_fault_input_error
              && howl_run_report_len(r) == 0 && howl_run_probe_len(r) == 0,
              "a probe run's fault did not fault the run");
        howl_run_free(r);
        /* The answer run's probe run is the whole run: its fault, unprefixed. */
        howl_Run a = howl_run_answer(in, howl_default_options());
        CHECK(!howl_run_ok(a) && howl_run_fault(a) == howl_FaultKind_fault_input_error
              && howl_run_report_len(a) == 0 && howl_run_probe_len(a) == 0,
              "an answer run's fault did not fault it");
        howl_run_free(a);
        howl_input_free(in);
    }
    /* A query naming an empty IRI refuses the input. */
    howl_Input in = howl_input_new();
    howl_input_ask_subsumed(in, str("http://example.org/t#D"), str(""));
    howl_Run r = howl_run_classify(in, howl_default_options());
    CHECK(howl_run_fault(r) == howl_FaultKind_fault_input_error, "an empty query IRI did not refuse the input");
    howl_run_free(r);
    howl_input_free(in);
}

/* Issue #67: each omission's kind and document. The first document is
 * clean; the second omits a union and uses an undeclared class; the
 * second probe document omits a union of its own. */
static const char* PREFIXES =
    "@prefix : <http://example.org/t#> . @prefix owl: <http://www.w3.org/2002/07/owl#> .\n"
    "@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n";

static howl_TurtleResult add(howl_Input in, int probe, const char* body) {
    char buf[1024];
    snprintf(buf, sizeof buf, "%s%s", PREFIXES, body);
    return probe ? howl_input_add_probe_turtle(in, str(buf)) : howl_input_add_turtle(in, str(buf));
}

static void omission_documents(void) {
    howl_Input in = howl_input_new();
    CHECK(add(in, 0, ":A a owl:Class . :C a owl:Class .").ok, "first document");
    CHECK(add(in, 0, ":A rdfs:subClassOf [ owl:unionOf ( :A :C ) ] . :C rdfs:subClassOf :Z .").ok, "second document");
    CHECK(add(in, 1, "<urn:probe:1> rdfs:subClassOf :A .").ok, "first probe document");
    CHECK(add(in, 1, "<urn:probe:2> rdfs:subClassOf [ owl:unionOf ( :A :C ) ] .").ok, "second probe document");
    howl_input_ask_unsatisfiable(in, str("urn:probe:2"));
    howl_Run r = howl_run_classify(in, howl_default_options());
    CHECK(howl_run_ok(r), "omission documents: no result");
    /* Canonical order: out-of-profile before missing declarations. */
    CHECK(howl_run_omission_len(r) == 2, "omission documents: %d omissions", (int)howl_run_omission_len(r));
    CHECK(msg_is(howl_run_omission_kind(r, 0), "SubClassOf") && howl_run_omission_document(r, 0) == 1,
          "the union is the second document's SubClassOf");
    CHECK(msg_is(howl_run_omission_kind(r, 1), "MissingDeclaration") && howl_run_omission_document(r, 1) == 1
          && howl_run_omission_entity_kind(r, 1) == howl_types_EntityKind_entity_class,
          "the undeclared class is the second document's");
    int probe_union = 0, input_union = 0;
    for (int64_t i = 0; i < howl_run_probe_omission_len(r); i++) {
        if (!msg_is(howl_run_probe_omission_kind(r, i), "SubClassOf")) continue;
        howl_DocumentSource s = howl_run_probe_omission_source(r, i);
        int64_t d = howl_run_probe_omission_document(r, i);
        if (s == howl_DocumentSource_document_probe && d == 1) probe_union++;
        if (s == howl_DocumentSource_document_input && d == 1) input_union++;
    }
    CHECK(probe_union == 1 && input_union == 1, "the probe run places its unions: probe %d, input %d", probe_union, input_union);
    howl_run_free(r);
    howl_input_free(in);
}

static void refusals(const char* path) {
    howl_Input in = input_for(path);

    howl_Options o = howl_default_options();
    o.workers = 0;
    howl_Run r = howl_run_classify(in, o);
    CHECK(!howl_run_ok(r) && howl_run_fault(r) == howl_FaultKind_fault_invalid_options, "workers 0 accepted");
    CHECK(howl_run_verdict(r) == howl_types_Verdict_verdict_inconclusive, "a faulted run's verdict is not inconclusive");
    CHECK(howl_run_report_len(r) == 0 && howl_run_sub_len(r) == 0, "a faulted run has lines");
    howl_run_free(r);

    o = howl_default_options();
    o.max_iterations = 10001;
    r = howl_run_classify(in, o);
    CHECK(howl_run_fault(r) == howl_FaultKind_fault_invalid_options, "max_iterations 10001 accepted");
    howl_run_free(r);

    /* horn-sriq was dropped (SPEC §5): its slot stays in the enum and is
     * refused for good, saying what replaces it. Every other rung is built. */
    o = howl_default_options();
    o.profile = howl_types_Profile_profile_horn_sriq;
    r = howl_run_classify(in, o);
    CHECK(howl_run_fault(r) == howl_FaultKind_fault_unavailable, "horn-sriq not refused");
    CHECK(howl_run_fault_profile(r) == howl_types_Profile_profile_horn_sriq, "unavailable names another profile");
    CHECK(msg_is(howl_run_fault_message(r), "profile horn-sriq was dropped; sriq covers its language"),
          "horn-sriq's refusal does not say it was dropped");
    howl_run_free(r);

    uint32_t flag = 1;
    o = howl_default_options();
    o.cancel = (int64_t)(uintptr_t)&flag;
    r = howl_run_classify(in, o);
    CHECK(howl_run_fault(r) == howl_FaultKind_fault_cancelled, "a set cancel flag did not cancel");
    howl_run_free(r);
    howl_input_free(in);

    in = howl_input_new();
    howl_TermIn quoted = { .kind = slop_rdf_rdf_TermKind_triple, .value = str(""), .datatype = str(""), .lang = str("") };
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
    howl_TermIn huge = { .kind = slop_rdf_rdf_TermKind_blank, .blank = INT64_MAX, .value = str(""), .datatype = str(""), .lang = str("") };
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
    probes();
    omission_documents();
    refusals(argv[1]);
    if (failures) {
        fprintf(stderr, "%d check(s) failed\n", failures);
        return 1;
    }
    printf("C API: %d fixtures x {el, el++, sriq} x W in {1,2,4}, twice each; probes; omission documents; refusals: ok\n", argc - 1);
    return 0;
}
