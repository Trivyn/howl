#include "../runtime/slop_runtime.h"
#include "slop_main.h"

#define main_EXIT_COHERENT (0)
#define main_EXIT_INCOHERENT (1)
#define main_EXIT_INCONCLUSIVE (2)
#define main_EXIT_ERROR (3)

int64_t main_exit_code_for(slop_result_types_Outcome_types_Fault r);
uint8_t main_parse_into(slop_arena* arena, termstore_Encoded* enc, slop_string path);
slop_option_rdf_IRI main_ontology_iri_from(termstore_Encoded e, int64_t from);
slop_string main_argv_to_string(uint8_t** argv, int64_t index);
void main_print_usage(void);
void main_eprint(slop_string s);
void main_print_timings(slop_arena* arena, int64_t t0, int64_t t1, int64_t t2, int64_t t3, int64_t t4);
int64_t main_peak_mb(void);
void main_print_memory(slop_arena* arena, int64_t m1, int64_t m2, int64_t m3, int64_t m4, int64_t m5);
uint8_t main_all_digits(slop_string s);
slop_result_normalize_Decoded_types_Fault main_decode_held(slop_arena* held, slop_arena* front, termstore_Encoded doc, slop_list_rdf_IRI resolved);
slop_result_howl_Prepared_types_Fault main_prepare_from(slop_arena* arena, slop_arena* held, slop_result_normalize_Decoded_types_Fault d, types_ReasonerConfig config);
slop_result_types_Outcome_types_Fault main_reason_prepared(slop_arena* arena, slop_result_howl_Prepared_types_Fault p, types_ReasonerConfig config);
void main_print_omissions(slop_arena* arena, slop_list_types_Omission os);
int main(int argc, char** _c_argv);

typedef struct { slop_arena* arena; termstore_Encoded* enc; } main__lambda_646_env_t;

static void main__lambda_646(main__lambda_646_env_t* _env, rdf_Triple t) { termstore_encoded_add(_env->arena, _env->enc, t); }

int64_t main_exit_code_for(slop_result_types_Outcome_types_Fault r) {
    int64_t _retval = {0};
    __auto_type _mv_643 = r;
    if (_mv_643.is_ok) {
        __auto_type o = _mv_643.data.ok;
        __auto_type _mv_644 = howl_verdict(o);
        if (_mv_644 == howl_Verdict_verdict_coherent) {
            return 0;
        } else if (_mv_644 == howl_Verdict_verdict_incoherent) {
            return 1;
        } else if (_mv_644 == howl_Verdict_verdict_inconclusive) {
            return 2;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_643.is_ok) {
        __auto_type f = _mv_643.data.err;
        __auto_type _mv_645 = f;
        switch (_mv_645.tag) {
            case types_Fault_cancelled:
            {
                return 2;
            }
            case types_Fault_refused:
            {
                __auto_type _ = _mv_645.data.refused;
                return 2;
            }
            case types_Fault_input_error:
            {
                __auto_type _ = _mv_645.data.input_error;
                return 3;
            }
            case types_Fault_unavailable:
            {
                __auto_type _ = _mv_645.data.unavailable;
                return 3;
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    SLOP_POST(((_retval <= 3)), "(<= $result 3)");
    SLOP_POST((({ __auto_type _mv = r; uint8_t _mr; if (_mv.is_ok) { __auto_type o = _mv.data.ok; _mr = (_retval <= 2); } else { __auto_type f = _mv.data.err; _mr = ({ __auto_type _mv = f; uint8_t _mr = {0}; switch (_mv.tag) { case types_Fault_cancelled: { _mr = (_retval == 2); break; } case types_Fault_refused: { __auto_type _ = _mv.data.refused; _mr = (_retval == 2); break; } case types_Fault_input_error: { __auto_type _ = _mv.data.input_error; _mr = (_retval == 3); break; } case types_Fault_unavailable: { __auto_type _ = _mv.data.unavailable; _mr = (_retval == 3); break; }  } _mr; }); } _mr; })), "(match r ((ok o) (<= $result 2)) ((error f) (match f ((cancelled) (== $result 2)) ((refused _) (== $result 2)) ((input-error _) (== $result 3)) ((unavailable _) (== $result 3)))))");
    return _retval;
}

uint8_t main_parse_into(slop_arena* arena, termstore_Encoded* enc, slop_string path) {
    {
        __auto_type parse = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type ok = ({ __auto_type _mv = ttl_parse_ttl_file_for_each_triple(parse, path, ({ main__lambda_646_env_t* main__lambda_646_env = (main__lambda_646_env_t*)slop_arena_alloc(arena, sizeof(main__lambda_646_env_t)); *main__lambda_646_env = (main__lambda_646_env_t){ .arena = arena, .enc = enc }; (slop_closure_t){ (void*)main__lambda_646, (void*)main__lambda_646_env }; })); uint8_t _mr; if (_mv.is_ok) { __auto_type _ = _mv.data.ok; _mr = 1; } else { __auto_type _ = _mv.data.err; _mr = 0; } _mr; });
        ({ slop_arena_free(parse); free(parse); });
        return ok;
    }
}

slop_option_rdf_IRI main_ontology_iri_from(termstore_Encoded e, int64_t from) {
    {
        slop_option_rdf_IRI found = (slop_option_rdf_IRI){.has_value = false};
        int64_t k = 0;
        {
            __auto_type _coll = e.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (k >= from) {
                    {
                        __auto_type t = termstore_triple_of(e.dict, it);
                        __auto_type _mv_647 = t.predicate;
                        switch (_mv_647.tag) {
                            case rdf_Term_term_iri:
                            {
                                __auto_type p = _mv_647.data.term_iri;
                                if (canon_string_cmp(p.value, vocab_RDF_TYPE) == 0) {
                                    __auto_type _mv_648 = t.object;
                                    switch (_mv_648.tag) {
                                        case rdf_Term_term_iri:
                                        {
                                            __auto_type o = _mv_648.data.term_iri;
                                            if (canon_string_cmp(o.value, vocab_OWL_ONTOLOGY) == 0) {
                                                __auto_type _mv_649 = t.subject;
                                                switch (_mv_649.tag) {
                                                    case rdf_Term_term_iri:
                                                    {
                                                        __auto_type sub = _mv_649.data.term_iri;
                                                        found = (slop_option_rdf_IRI){.has_value = 1, .value = sub};
                                                        break;
                                                    }
                                                    default: {
                                                        break;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        default: {
                                            break;
                                        }
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
                k = (k + 1);
            }
        }
        return found;
    }
}

slop_string main_argv_to_string(uint8_t** argv, int64_t index) {
    {
        __auto_type ptr = argv[index];
        return (slop_string){.len = strlen(ptr), .data = ptr};
    }
}

void main_print_usage(void) {
    printf("%s\n", "HOWL — a consequence-based description-logic reasoner");
    printf("%s\n", "");
    printf("%s\n", "USAGE:");
    printf("%s\n", "  howl validate    <ontology.ttl> [--profile P] [--strict] [--no-imports] [-I FILE]...");
    printf("%s\n", "  howl classify    <ontology.ttl>          (--reduce, --emit: not until M3)");
    printf("%s\n", "");
    printf("%s\n", "  -I FILE    attest FILE as a declared owl:Imports target; repeatable");
    printf("%s\n", "  --profile P  the calculus: el (default), el++, horn-sriq, sriq, or auto;");
    printf("%s\n", "               only el is implemented, and any other rung exits 3");
    printf("%s\n", "  --strict   refuse to run past any omission (exit 2, no report)");
    printf("%s\n", "  --report   print the canonical report instead of the summary");
    printf("%s\n", "  --timings  print phase durations and peak memory on stderr (never part of a report)");
    printf("%s\n", "  --max-iterations N   the round budget, 0..10000 (default 1000)");
    printf("%s\n", "  --workers N          threads joining each round, 1..64 (default 4); never changes the report");
    printf("%s\n", "");
    printf("%s\n", "EXIT CODES:");
    printf("%s\n", "  0  coherent       checked, no incoherence found");
    printf("%s\n", "  1  incoherent     inconsistent, or an unsatisfiable named class");
    printf("%s\n", "  2  inconclusive   could not check completely — NOT a pass");
    printf("%s\n", "  3  error          usage, parse, or I/O failure");
    printf("%s\n", "");
    printf("%s\n", "Treat 0 alone as the pass condition. A CI job that accepts 2");
    printf("%s\n", "reintroduces the silent-false-pass hazard the gate exists to prevent.");
}

void main_eprint(slop_string s) {
    fwrite(s.data, 1, s.len, stderr);;
}

void main_print_timings(slop_arena* arena, int64_t t0, int64_t t1, int64_t t2, int64_t t3, int64_t t4) {
    main_eprint(string_concat(arena, SLOP_STR("timing parse_ms="), string_concat(arena, int_to_string(arena, (t1 - t0)), string_concat(arena, SLOP_STR(" decode_ms="), string_concat(arena, int_to_string(arena, (t2 - t1)), string_concat(arena, SLOP_STR(" prepare_ms="), string_concat(arena, int_to_string(arena, (t3 - t2)), string_concat(arena, SLOP_STR(" reason_ms="), string_concat(arena, int_to_string(arena, (t4 - t3)), string_concat(arena, SLOP_STR(" total_ms="), string_concat(arena, int_to_string(arena, (t4 - t0)), SLOP_STR("\n"))))))))))));
}

int64_t main_peak_mb(void) {
    {
        int64_t mb = 0;
        { struct rusage ru; getrusage(RUSAGE_SELF, &ru);
#ifdef __APPLE__
 mb = (int64_t)(ru.ru_maxrss / 1048576);
#else
 mb = (int64_t)(ru.ru_maxrss / 1024);
#endif
 };
        return mb;
    }
}

void main_print_memory(slop_arena* arena, int64_t m1, int64_t m2, int64_t m3, int64_t m4, int64_t m5) {
    main_eprint(string_concat(arena, SLOP_STR("memory parse_mb="), string_concat(arena, int_to_string(arena, m1), string_concat(arena, SLOP_STR(" decode_mb="), string_concat(arena, int_to_string(arena, m2), string_concat(arena, SLOP_STR(" prepare_mb="), string_concat(arena, int_to_string(arena, m3), string_concat(arena, SLOP_STR(" reason_mb="), string_concat(arena, int_to_string(arena, m4), string_concat(arena, SLOP_STR(" report_mb="), string_concat(arena, int_to_string(arena, m5), SLOP_STR("\n"))))))))))));
}

uint8_t main_all_digits(slop_string s) {
    {
        uint8_t ok = (string_len(s) > 0);
        int64_t i = 0;
        while (ok && (i < string_len(s))) {
            if (!(strlib_is_digit(strlib_char_at(s, i)))) {
                ok = 0;
            }
            i = (i + 1);
        }
        return ok;
    }
}

slop_result_normalize_Decoded_types_Fault main_decode_held(slop_arena* held, slop_arena* front, termstore_Encoded doc, slop_list_rdf_IRI resolved) {
    {
        __auto_type res = howl_own_decoded(held, howl_decode_from(front, doc, resolved));
        ({ slop_arena_free(front); free(front); });
        return res;
    }
}

slop_result_howl_Prepared_types_Fault main_prepare_from(slop_arena* arena, slop_arena* held, slop_result_normalize_Decoded_types_Fault d, types_ReasonerConfig config) {
    {
        __auto_type res = ({ __auto_type _mv = d; slop_result_howl_Prepared_types_Fault _mr; if (_mv.is_ok) { __auto_type dd = _mv.data.ok; _mr = howl_prepare_decoded(arena, dd, config); } else { __auto_type f = _mv.data.err; _mr = ((slop_result_howl_Prepared_types_Fault){ .is_ok = false, .data.err = types_copy_fault(arena, f) }); } _mr; });
        ({ slop_arena_free(held); free(held); });
        return res;
    }
}

slop_result_types_Outcome_types_Fault main_reason_prepared(slop_arena* arena, slop_result_howl_Prepared_types_Fault p, types_ReasonerConfig config) {
    __auto_type _mv_650 = p;
    if (!_mv_650.is_ok) {
        __auto_type f = _mv_650.data.err;
        return ((slop_result_types_Outcome_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_650.is_ok) {
        __auto_type pp = _mv_650.data.ok;
        return howl_reason(arena, pp, config);
    }
    SLOP_UNREACHABLE();
}

void main_print_omissions(slop_arena* arena, slop_list_types_Omission os) {
    {
        __auto_type _coll = os;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type o = _coll.data[_i];
            printf("%s", "  omitted: ");
            printf("%.*s\n", (int)(owl2_render_omission(arena, o)).len, (owl2_render_omission(arena, o)).data);
        }
    }
}

int main(int argc, char** _c_argv) {
    uint8_t** argv = (uint8_t**)_c_argv;
    {
        #ifdef SLOP_DEBUG
        SLOP_PRE((268435456) > 0, "with-arena size must be positive");
        #endif
        slop_arena _arena = slop_arena_new(268435456);
        #ifdef SLOP_DEBUG
        SLOP_PRE(_arena.base != NULL, "arena allocation failed");
        #endif
        slop_arena* arena = &_arena;
        if (argc < 3) {
            main_print_usage();
            {
                int _wa_ret = main_EXIT_ERROR;
                slop_arena_free(arena);
                return _wa_ret;
            }
        } else {
            {
                __auto_type command = main_argv_to_string(argv, 1);
                if (!((string_eq(command, SLOP_STR("validate")) || string_eq(command, SLOP_STR("classify"))))) {
                    printf("%s", "howl: unknown or unimplemented command: ");
                    printf("%.*s\n", (int)(command).len, (command).data);
                    {
                        int _wa_ret = main_EXIT_ERROR;
                        slop_arena_free(arena);
                        return _wa_ret;
                    }
                } else {
                    {
                        __auto_type front = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
                        __auto_type enc = termstore_new_encoded(front);
                        __auto_type resolved = ((slop_list_rdf_IRI){ .data = NULL, .len = 0, .cap = 0 });
                        __auto_type cfg = howl_default_config();
                        uint8_t failed = 0;
                        int64_t i = 3;
                        uint8_t report_mode = 0;
                        uint8_t timings = 0;
                        __auto_type t_start = slop_now_ms();
                        __auto_type input = main_argv_to_string(argv, 2);
                        if (!(main_parse_into(front, enc, input))) {
                            printf("%s", "howl: cannot parse ");
                            printf("%.*s\n", (int)(input).len, (input).data);
                            failed = 1;
                        }
                        while (i < argc) {
                            {
                                __auto_type arg = main_argv_to_string(argv, i);
                                int64_t step = 1;
                                uint8_t known = 0;
                                if (string_eq(arg, SLOP_STR("-I"))) {
                                    known = 1;
                                    step = 2;
                                    if ((i + 1) >= argc) {
                                        printf("%s\n", "howl: -I needs a FILE");
                                        failed = 1;
                                    }
                                    if ((i + 1) < argc) {
                                        {
                                            __auto_type path = main_argv_to_string(argv, (i + 1));
                                            __auto_type from = ((int64_t)(((int64_t)(((*enc).triples).len))));
                                            termstore_encoded_next_document(front, enc);
                                            if (!(main_parse_into(front, enc, path))) {
                                                printf("%s", "howl: cannot parse import ");
                                                printf("%.*s\n", (int)(path).len, (path).data);
                                                failed = 1;
                                            } else {
                                                __auto_type _mv_651 = main_ontology_iri_from((*enc), from);
                                                if (!_mv_651.has_value) {
                                                    printf("%s", "howl: import declares no owl:Ontology IRI, so it attests nothing: ");
                                                    printf("%.*s\n", (int)(path).len, (path).data);
                                                    failed = 1;
                                                } else if (_mv_651.has_value) {
                                                    __auto_type o = _mv_651.value;
                                                    ({ __auto_type _lst_p = &(resolved); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                }
                                            }
                                        }
                                    }
                                }
                                if (string_eq(arg, SLOP_STR("--strict"))) {
                                    known = 1;
                                    cfg.strict_profile = 1;
                                }
                                if (string_eq(arg, SLOP_STR("--no-imports"))) {
                                    known = 1;
                                }
                                if (string_eq(arg, SLOP_STR("--profile"))) {
                                    known = 1;
                                    step = 2;
                                    if ((i + 1) >= argc) {
                                        printf("%s\n", "howl: --profile needs a profile: auto, el, el++, horn-sriq or sriq");
                                        failed = 1;
                                    }
                                    if ((i + 1) < argc) {
                                        {
                                            __auto_type p = main_argv_to_string(argv, (i + 1));
                                            if (string_eq(p, SLOP_STR("auto"))) {
                                                cfg.selection = ((types_ProfileSelection){ .tag = types_ProfileSelection_slop_auto });
                                            } else {
                                                __auto_type _mv_652 = select_parse_profile(p);
                                                if (_mv_652.has_value) {
                                                    __auto_type q = _mv_652.value;
                                                    cfg.selection = ((types_ProfileSelection){ .tag = types_ProfileSelection_explicit, .data.explicit = q });
                                                } else if (!_mv_652.has_value) {
                                                    printf("%s", "howl: unknown profile: ");
                                                    printf("%.*s", (int)(p).len, (p).data);
                                                    printf("%s\n", " (expected auto, el, el++, horn-sriq or sriq)");
                                                    failed = 1;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (string_eq(arg, SLOP_STR("--report"))) {
                                    known = 1;
                                    report_mode = 1;
                                }
                                if (string_eq(arg, SLOP_STR("--timings"))) {
                                    known = 1;
                                    timings = 1;
                                }
                                if (string_eq(arg, SLOP_STR("--max-iterations"))) {
                                    known = 1;
                                    step = 2;
                                    if ((i + 1) >= argc) {
                                        printf("%s\n", "howl: --max-iterations needs N (0..10000)");
                                        failed = 1;
                                    }
                                    if ((i + 1) < argc) {
                                        {
                                            __auto_type v = main_argv_to_string(argv, (i + 1));
                                            if (!(main_all_digits(v))) {
                                                printf("%s\n", "howl: --max-iterations needs a whole number 0..10000");
                                                failed = 1;
                                            } else {
                                                __auto_type _mv_653 = strlib_parse_int(v);
                                                if (_mv_653.is_ok) {
                                                    __auto_type n = _mv_653.data.ok;
                                                    if (n <= 10000) {
                                                        cfg.max_iterations = ((int64_t)(n));
                                                    } else {
                                                        printf("%s\n", "howl: --max-iterations must be 0..10000");
                                                        failed = 1;
                                                    }
                                                } else if (!_mv_653.is_ok) {
                                                    __auto_type _ = _mv_653.data.err;
                                                    printf("%s\n", "howl: --max-iterations needs a whole number 0..10000");
                                                    failed = 1;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (string_eq(arg, SLOP_STR("--workers"))) {
                                    known = 1;
                                    step = 2;
                                    if ((i + 1) >= argc) {
                                        printf("%s\n", "howl: --workers needs N (1..64)");
                                        failed = 1;
                                    }
                                    if ((i + 1) < argc) {
                                        {
                                            __auto_type v = main_argv_to_string(argv, (i + 1));
                                            if (!(main_all_digits(v))) {
                                                printf("%s\n", "howl: --workers needs a whole number 1..64");
                                                failed = 1;
                                            } else {
                                                __auto_type _mv_654 = strlib_parse_int(v);
                                                if (_mv_654.is_ok) {
                                                    __auto_type n = _mv_654.data.ok;
                                                    if ((n >= 1) && (n <= 64)) {
                                                        cfg.worker_count = ((int64_t)(n));
                                                    } else {
                                                        printf("%s\n", "howl: --workers must be 1..64");
                                                        failed = 1;
                                                    }
                                                } else if (!_mv_654.is_ok) {
                                                    __auto_type _ = _mv_654.data.err;
                                                    printf("%s\n", "howl: --workers needs a whole number 1..64");
                                                    failed = 1;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (string_eq(arg, SLOP_STR("--emit")) || string_eq(arg, SLOP_STR("--reduce"))) {
                                    known = 1;
                                    if (string_eq(arg, SLOP_STR("--emit"))) {
                                        step = 2;
                                    }
                                    printf("%s", "howl: ");
                                    printf("%.*s", (int)(arg).len, (arg).data);
                                    printf("%s\n", " is not implemented until M3");
                                    failed = 1;
                                }
                                if (!(known)) {
                                    printf("%s", "howl: unknown argument: ");
                                    printf("%.*s\n", (int)(arg).len, (arg).data);
                                    failed = 1;
                                }
                                i = (i + step);
                            }
                        }
                        if (failed) {
                            {
                                int _wa_ret = main_EXIT_ERROR;
                                slop_arena_free(arena);
                                return _wa_ret;
                            }
                        } else {
                            {
                                __auto_type t_parsed = slop_now_ms();
                                __auto_type m_parsed = main_peak_mb();
                                __auto_type held = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
                                __auto_type decoded = main_decode_held(held, front, (*enc), resolved);
                                __auto_type t_decoded = slop_now_ms();
                                __auto_type m_decoded = main_peak_mb();
                                __auto_type prepared = main_prepare_from(arena, held, decoded, cfg);
                                __auto_type t_prepared = slop_now_ms();
                                __auto_type m_prepared = main_peak_mb();
                                __auto_type result = main_reason_prepared(arena, prepared, cfg);
                                __auto_type t_reasoned = slop_now_ms();
                                __auto_type m_reasoned = main_peak_mb();
                                if (timings) {
                                    main_print_timings(arena, t_start, t_parsed, t_decoded, t_prepared, t_reasoned);
                                }
                                __auto_type _mv_655 = result;
                                if (_mv_655.is_ok) {
                                    __auto_type o = _mv_655.data.ok;
                                    if (report_mode) {
                                        {
                                            __auto_type _coll = report_report_lines(arena, o);
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type l = _coll.data[_i];
                                                printf("%.*s\n", (int)(l).len, (l).data);
                                            }
                                        }
                                    } else {
                                        printf("%s", "howl: ");
                                        printf("%.*s", (int)(int_to_string(arena, ((int64_t)(((int64_t)((o.findings.subsumptions).len)))))).len, (int_to_string(arena, ((int64_t)(((int64_t)((o.findings.subsumptions).len)))))).data);
                                        printf("%s", " subsumptions, ");
                                        printf("%.*s", (int)(int_to_string(arena, ((int64_t)(((int64_t)((o.findings.unsatisfiable).len)))))).len, (int_to_string(arena, ((int64_t)(((int64_t)((o.findings.unsatisfiable).len)))))).data);
                                        printf("%s", " unsatisfiable, ");
                                        printf("%.*s", (int)(int_to_string(arena, ((int64_t)(((int64_t)((o.coverage.omitted).len)))))).len, (int_to_string(arena, ((int64_t)(((int64_t)((o.coverage.omitted).len)))))).data);
                                        printf("%s\n", " omitted");
                                        main_print_omissions(arena, o.coverage.omitted);
                                        __auto_type _mv_656 = howl_verdict(o);
                                        if (_mv_656 == howl_Verdict_verdict_coherent) {
                                            printf("%s\n", "howl: coherent");
                                        } else if (_mv_656 == howl_Verdict_verdict_incoherent) {
                                            printf("%s\n", "howl: INCOHERENT");
                                        } else if (_mv_656 == howl_Verdict_verdict_inconclusive) {
                                            printf("%s\n", "howl: INCONCLUSIVE — coverage gaps, this is NOT a pass");
                                        }
                                    }
                                } else if (!_mv_655.is_ok) {
                                    __auto_type f = _mv_655.data.err;
                                    __auto_type _mv_657 = f;
                                    switch (_mv_657.tag) {
                                        case types_Fault_input_error:
                                        {
                                            __auto_type msg = _mv_657.data.input_error;
                                            printf("%s", "howl: ");
                                            printf("%.*s\n", (int)(msg).len, (msg).data);
                                            break;
                                        }
                                        case types_Fault_cancelled:
                                        {
                                            printf("%s\n", "howl: cancelled");
                                            break;
                                        }
                                        case types_Fault_unavailable:
                                        {
                                            __auto_type p = _mv_657.data.unavailable;
                                            printf("%s", "howl: profile ");
                                            printf("%.*s", (int)(select_profile_name(p)).len, (select_profile_name(p)).data);
                                            printf("%s\n", " is not implemented yet (implemented: el)");
                                            break;
                                        }
                                        case types_Fault_refused:
                                        {
                                            __auto_type os = _mv_657.data.refused;
                                            printf("%s", "howl: refused (--strict), no report — ");
                                            printf("%.*s", (int)(int_to_string(arena, ((int64_t)(((int64_t)((os).len)))))).len, (int_to_string(arena, ((int64_t)(((int64_t)((os).len)))))).data);
                                            printf("%s\n", " omitted");
                                            main_print_omissions(arena, os);
                                            break;
                                        }
                                    }
                                }
                                if (timings) {
                                    main_print_memory(arena, m_parsed, m_decoded, m_prepared, m_reasoned, main_peak_mb());
                                }
                                {
                                    int _wa_ret = main_exit_code_for(result);
                                    slop_arena_free(arena);
                                    return _wa_ret;
                                }
                            }
                        }
                    }
                }
            }
        }
        slop_arena_free(arena);
    }
}

