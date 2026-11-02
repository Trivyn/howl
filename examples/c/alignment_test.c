/* Public C alignment API smoke test, built by `make c-example`. */
#include "howl.h"

#include <stdio.h>
#include <string.h>

static int failures = 0;
#define CHECK(condition, message) do { if (!(condition)) { fprintf(stderr, "FAIL: %s\n", message); failures++; } } while (0)

static slop_string string(const char* s) { return (slop_string){ strlen(s), s }; }
static int same(slop_string a, const char* b) {
    return a.len == strlen(b) && memcmp(a.data, b, a.len) == 0;
}

static const char* fixed =
    "@prefix : <http://example.org/align#> .\n"
    "@prefix owl: <http://www.w3.org/2002/07/owl#> .\n"
    ":A a owl:Class . :B a owl:Class . :C a owl:Class .\n"
    ":A owl:disjointWith :B .\n";
static const char* mappings =
    "@prefix : <http://example.org/align#> .\n"
    "@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n"
    ":C rdfs:subClassOf :A . :C rdfs:subClassOf :B .\n";
static const char* fixed_source = "http://example.org/source/fixed";
static const char* mapping_source = "http://example.org/source/mappings";

int main(void) {
    howl_Options options = howl_default_options();
    howl_RepairOptions repair_options = howl_default_repair_options();

    /* A rejected name is a caller error, not a poisoned input. */
    howl_Input retry = howl_input_new();
    CHECK(howl_input_add_turtle(retry, string(fixed)).ok, "retry: fixed Turtle parses");
    CHECK(!howl_input_set_document(retry, 0, string("relative/source"), 0), "relative source refused");
    CHECK(!howl_input_set_document(retry, 1, string(fixed_source), 0), "out-of-range index refused");
    howl_Run unnamed = howl_run_align(retry, options, 0, repair_options);
    CHECK(!howl_run_ok(unnamed) && howl_run_fault(unnamed) == howl_FaultKind_fault_input_error,
          "an unnamed document is an input error");
    howl_run_free(unnamed);
    CHECK(howl_input_source_available(retry, string(fixed_source)) &&
          !howl_input_source_available(retry, string("relative/source")),
          "availability query accepts a fresh absolute IRI only");
    CHECK(howl_input_set_document(retry, 0, string(fixed_source), 0), "retry names the same index");
    CHECK(howl_input_add_turtle(retry, string(mappings)).ok, "retry: mapping Turtle parses");
    CHECK(!howl_input_source_available(retry, string(fixed_source)), "a used source is unavailable");
    CHECK(!howl_input_set_document(retry, 1, string(fixed_source), 1), "duplicate source refused");
    CHECK(howl_input_set_document(retry, 1, string(mapping_source), 1), "retry names the duplicate's index");
    howl_Run retried = howl_run_align(retry, options, 0, repair_options);
    CHECK(howl_run_ok(retried), "align succeeds after refused names were retried");
    howl_run_free(retried);
    howl_input_free(retry);

    howl_Input input = howl_input_new();
    CHECK(howl_input_add_turtle(input, string(fixed)).ok, "fixed Turtle parses");
    CHECK(howl_input_set_document(input, 0, string(fixed_source), 0), "fixed document source assigned");
    CHECK(howl_input_add_turtle(input, string(mappings)).ok, "mapping Turtle parses");
    CHECK(howl_input_set_document(input, 1, string(mapping_source), 1), "mapping document source assigned");

    CHECK(repair_options.conflict_calls > 0 && repair_options.conflict_nodes > 0 &&
          repair_options.hitting_nodes > 0 && repair_options.verification_calls > 0,
          "repair defaults allow bounded work");

    howl_Run check = howl_run_align(input, options, 0, repair_options);
    CHECK(howl_run_ok(check), "merged coherence check returns a report");
    CHECK(howl_run_verdict(check) == howl_types_Verdict_verdict_incoherent, "merge is incoherent");
    CHECK(!howl_run_repair_requested(check) && howl_run_repair_len(check) == 0,
          "coherence-only check has no repair search");
    howl_run_free(check);

    howl_Run repaired = howl_run_align(input, options, 1, repair_options);
    CHECK(howl_run_ok(repaired), "repair run returns a report");
    CHECK(howl_run_verdict(repaired) == howl_types_Verdict_verdict_incoherent,
          "repair search preserves merged verdict");
    CHECK(howl_run_repair_requested(repaired) && howl_run_repair_complete(repaired),
          "repair search is complete");
    CHECK(!howl_run_already_coherent(repaired) && !howl_run_unrepairable(repaired),
          "incoherence is repairable by mappings");
    CHECK(howl_run_mapping_len(repaired) == 2 && howl_run_repair_len(repaired) == 2,
          "both mappings and both minimal repairs are returned");
    for (int64_t i = 0; i < howl_run_mapping_len(repaired); i++) {
        CHECK(same(howl_run_mapping_source(repaired, i), mapping_source), "mapping source is preserved");
        CHECK(howl_run_mapping_text(repaired, i).len > 0, "mapping text is canonical and nonempty");
    }
    CHECK(howl_run_repair_size(repaired, 0) == 1 && howl_run_repair_size(repaired, 1) == 1,
          "each repair removes one mapping");
    CHECK(howl_run_repair_mapping(repaired, 0, 0) == 0 && howl_run_repair_mapping(repaired, 1, 0) == 1,
          "repairs follow canonical mapping order");
    CHECK(howl_run_candidate_len(repaired) == 0 && howl_run_search_omission_len(repaired) == 0,
          "complete search has no pending candidate or search omission");
    CHECK(howl_run_search_phase_exhausted(repaired, 0) &&
          howl_run_search_phase_exhausted(repaired, 1) &&
          howl_run_search_phase_exhausted(repaired, 2),
          "every search phase exhausted its work");
    CHECK(howl_run_repair_mapping(repaired, 0, -1) == -1 &&
          howl_run_repair_mapping(repaired, 2, 0) == -1 &&
          howl_run_mapping_text(repaired, 2).len == 0,
          "out-of-range accessors are total");
    howl_run_free(repaired);
    howl_input_free(input);

    return failures ? 1 : 0;
}
