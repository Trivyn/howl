/*
 * Classify a Turtle file through HOWL's C API.
 *
 *   make lib
 *   cc -Iinclude examples/c/classify.c build/libhowl.a -lpthread -o classify
 *   ./classify ontology.ttl
 *
 * Exits like `howl validate`: 0 coherent, 1 incoherent, 2 inconclusive
 * (NOT a pass), 3 error.
 */
#include "howl.h"

#include <stdio.h>
#include <stdlib.h>

static char* read_file(const char* path, size_t* len) {
    FILE* f = fopen(path, "rb");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    *len = (size_t)ftell(f);
    rewind(f);
    char* text = malloc(*len ? *len : 1);
    if (text && fread(text, 1, *len, f) != *len) { free(text); text = NULL; }
    fclose(f);
    return text;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s ontology.ttl\n", argv[0]);
        return 3;
    }
    size_t len;
    char* text = read_file(argv[1], &len);
    if (!text) { perror(argv[1]); return 3; }

    howl_Input in = howl_input_new();
    howl_TurtleResult parsed = howl_input_add_turtle(in, (slop_string){ len, text });
    free(text);  /* the input keeps its own copy */
    if (!parsed.ok) {
        fprintf(stderr, "%s:%lld:%lld: %.*s\n", argv[1], (long long)parsed.line,
                (long long)parsed.column, (int)parsed.message.len, parsed.message.data);
        howl_input_free(in);
        return 3;
    }

    howl_Run run = howl_run_classify(in, howl_default_options());
    int code = 3;
    if (howl_run_ok(run)) {
        switch (howl_run_verdict(run)) {
        case types_Verdict_verdict_coherent:     puts("verdict: coherent");     code = 0; break;
        case types_Verdict_verdict_incoherent:   puts("verdict: incoherent");   code = 1; break;
        case types_Verdict_verdict_inconclusive: puts("verdict: inconclusive"); code = 2; break;
        }
        for (int64_t i = 0; i < howl_run_unsat_len(run); i++) {
            slop_string c = howl_run_unsat(run, i);
            printf("unsatisfiable: %.*s\n", (int)c.len, c.data);
        }
        for (int64_t i = 0; i < howl_run_omission_len(run); i++) {
            slop_string o = howl_run_omission(run, i);
            printf("omitted: %.*s\n", (int)o.len, o.data);
        }
        for (int64_t i = 0; i < howl_run_sub_len(run); i++) {
            slop_string sub = howl_run_sub(run, i), sup = howl_run_super(run, i);
            printf("%.*s <= %.*s\n", (int)sub.len, sub.data, (int)sup.len, sup.data);
        }
    } else {
        slop_string m = howl_run_fault_message(run);
        fprintf(stderr, "no result (fault %d): %.*s\n", (int)howl_run_fault(run), (int)m.len, m.data);
    }

    /* Every string the run returned is valid until here. */
    howl_run_free(run);
    howl_input_free(in);
    return code;
}
