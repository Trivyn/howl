#include "../runtime/slop_runtime.h"
#include "slop_main.h"

#define howl_cli_main_EXIT_COHERENT (0)
#define howl_cli_main_EXIT_INCOHERENT (1)
#define howl_cli_main_EXIT_INCONCLUSIVE (2)
#define howl_cli_main_EXIT_ERROR (3)

int64_t howl_cli_main_exit_code_for(slop_result_howl_types_Outcome_howl_types_Fault r);
uint8_t howl_cli_main_parse_into(slop_arena* arena, howl_termstore_Encoded* enc, slop_string path);
slop_option_slop_rdf_rdf_IRI howl_cli_main_ontology_iri_from(howl_termstore_Encoded e, int64_t from);
slop_string howl_cli_main_argv_to_string(uint8_t** argv, int64_t index);
uint8_t howl_cli_main_is_version_request(int64_t argc, uint8_t** argv);
void howl_cli_main_print_usage(void);
void howl_cli_main_print_step_down(slop_arena* arena, slop_result_howl_types_Outcome_howl_types_Fault r);
void howl_cli_main_eprint(slop_string s);
void howl_cli_main_print_timings(slop_arena* arena, int64_t t0, int64_t t1, int64_t t2, int64_t t3, int64_t t4);
int64_t howl_cli_main_peak_mb(void);
void howl_cli_main_print_memory(slop_arena* arena, int64_t m1, int64_t m2, int64_t m3, int64_t m4, int64_t m5);
uint8_t howl_cli_main_all_digits(slop_string s);
slop_result_howl_normalize_Decoded_howl_types_Fault howl_cli_main_decode_held(slop_arena* held, slop_arena* front, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI resolved);
slop_result_howl_Prepared_howl_types_Fault howl_cli_main_prepare_from(slop_arena* arena, slop_arena* held, slop_result_howl_normalize_Decoded_howl_types_Fault d, howl_types_ReasonerConfig config);
slop_result_howl_types_Outcome_howl_types_Fault howl_cli_main_reason_prepared(slop_arena* arena, slop_result_howl_Prepared_howl_types_Fault p, howl_types_ReasonerConfig config);
howl_probe_Query howl_cli_main_cli_query(slop_arena* arena, howl_probe_QueryKind kind, slop_string sub, slop_string sup);
slop_option_howl_termstore_Encoded_ptr howl_cli_main_probe_input(slop_arena* arena, howl_termstore_Encoded main, howl_termstore_Encoded probes, slop_list_howl_probe_Query queries);
slop_option_result_howl_probe_Probing_howl_types_Fault howl_cli_main_probe_of(slop_arena* arena, slop_option_howl_termstore_Encoded_ptr doc, slop_list_slop_rdf_rdf_IRI resolved, slop_list_howl_probe_Query queries, howl_types_ReasonerConfig config, slop_result_howl_types_Outcome_howl_types_Fault main);
slop_result_howl_types_Outcome_howl_types_Fault howl_cli_main_with_probe(slop_arena* arena, slop_result_howl_types_Outcome_howl_types_Fault main, slop_option_result_howl_probe_Probing_howl_types_Fault probed);
void howl_cli_main_print_probes(slop_arena* arena, slop_option_result_howl_probe_Probing_howl_types_Fault probed);
uint8_t howl_cli_main_operand(slop_string s);
void howl_cli_main_print_omissions(slop_arena* arena, slop_list_howl_types_Omission os);
int64_t howl_cli_main_validate_run(slop_arena* arena, slop_arena* front, howl_termstore_Encoded* enc, slop_arena* pfront, howl_termstore_Encoded* penc, slop_list_slop_rdf_rdf_IRI resolved, slop_list_howl_probe_Query queries, howl_types_ReasonerConfig cfg, uint8_t report_mode, uint8_t timings, int64_t t_start);
int64_t howl_cli_main_ask_run(slop_arena* arena, slop_arena* front, howl_termstore_Encoded* enc, slop_arena* pfront, howl_termstore_Encoded* penc, slop_list_slop_rdf_rdf_IRI resolved, slop_list_howl_probe_Query queries, howl_types_ReasonerConfig cfg);
void howl_cli_main_print_ask_fault(slop_arena* arena, howl_types_Fault f);
int64_t howl_cli_main_ask_exit_code(slop_result_howl_probe_Probing_howl_types_Fault r);
int main(int argc, char** _c_argv);

typedef struct { slop_arena* arena; howl_termstore_Encoded* enc; } howl_cli_main__lambda_1710_env_t;

static void howl_cli_main__lambda_1710(howl_cli_main__lambda_1710_env_t* _env, slop_rdf_rdf_Triple t) { howl_termstore_encoded_add(_env->arena, _env->enc, t); }

int64_t howl_cli_main_exit_code_for(slop_result_howl_types_Outcome_howl_types_Fault r) {
    int64_t _retval = {0};
    __auto_type _mv_1707 = r;
    if (_mv_1707.is_ok) {
        __auto_type o = _mv_1707.data.ok;
        __auto_type _mv_1708 = howl_types_verdict(o);
        if (_mv_1708 == howl_types_Verdict_verdict_coherent) {
            _retval = 0;
            goto _slop_post;
        } else if (_mv_1708 == howl_types_Verdict_verdict_incoherent) {
            _retval = 1;
            goto _slop_post;
        } else if (_mv_1708 == howl_types_Verdict_verdict_inconclusive) {
            _retval = 2;
            goto _slop_post;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_1707.is_ok) {
        __auto_type f = _mv_1707.data.err;
        __auto_type _mv_1709 = f;
        switch (_mv_1709.tag) {
            case howl_types_Fault_cancelled:
            {
                _retval = 2;
                goto _slop_post;
            }
            case howl_types_Fault_refused:
            {
                __auto_type _ = _mv_1709.data.refused;
                _retval = 2;
                goto _slop_post;
            }
            case howl_types_Fault_input_error:
            {
                __auto_type _ = _mv_1709.data.input_error;
                _retval = 3;
                goto _slop_post;
            }
            case howl_types_Fault_unavailable:
            {
                __auto_type _ = _mv_1709.data.unavailable;
                _retval = 3;
                goto _slop_post;
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    SLOP_POST(((_retval <= 3)), "(<= $result 3)");
    SLOP_POST((({ __auto_type _mv = r; uint8_t _mr; if (_mv.is_ok) { __auto_type o = _mv.data.ok; _mr = (_retval <= 2); } else { __auto_type f = _mv.data.err; _mr = ({ __auto_type _mv = f; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case howl_types_Fault_cancelled: { _mr = (_retval == 2); _mm = 1; break; } case howl_types_Fault_refused: { _mr = (_retval == 2); _mm = 1; break; } case howl_types_Fault_input_error: { _mr = (_retval == 3); _mm = 1; break; } case howl_types_Fault_unavailable: { _mr = (_retval == 3); _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }); } _mr; })), "(match r ((ok o) (<= $result 2)) ((error f) (match f ((cancelled) (== $result 2)) ((refused _) (== $result 2)) ((input-error _) (== $result 3)) ((unavailable _) (== $result 3)))))");
    return _retval;
}

uint8_t howl_cli_main_parse_into(slop_arena* arena, howl_termstore_Encoded* enc, slop_string path) {
    {
        __auto_type parse = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type ok = ({ __auto_type _mv = slop_rdf_ttl_parse_ttl_file_for_each_triple(parse, path, ({ howl_cli_main__lambda_1710_env_t* howl_cli_main__lambda_1710_env = (howl_cli_main__lambda_1710_env_t*)slop_arena_alloc(arena, sizeof(howl_cli_main__lambda_1710_env_t)); *howl_cli_main__lambda_1710_env = (howl_cli_main__lambda_1710_env_t){ .arena = arena, .enc = enc }; (slop_closure_t){ (void*)howl_cli_main__lambda_1710, (void*)howl_cli_main__lambda_1710_env }; })); uint8_t _mr; if (_mv.is_ok) { __auto_type _ = _mv.data.ok; _mr = 1; } else { __auto_type _ = _mv.data.err; _mr = 0; } _mr; });
        (void)(({ slop_arena_free(parse); free(parse); }));
        return ok;
    }
}

slop_option_slop_rdf_rdf_IRI howl_cli_main_ontology_iri_from(howl_termstore_Encoded e, int64_t from) {
    {
        slop_option_slop_rdf_rdf_IRI found = (slop_option_slop_rdf_rdf_IRI){.has_value = false};
        int64_t k = 0;
        {
            __auto_type _coll = e.triples;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type it = _coll.data[_i];
                if (k >= from) {
                    {
                        __auto_type t = howl_termstore_triple_of(e.dict, it);
                        __auto_type _mv_1711 = t.predicate;
                        switch (_mv_1711.tag) {
                            case slop_rdf_rdf_Term_term_iri:
                            {
                                __auto_type p = _mv_1711.data.term_iri;
                                if (howl_canon_string_cmp(p.value, slop_rdf_vocab_RDF_TYPE) == 0) {
                                    __auto_type _mv_1712 = t.object;
                                    switch (_mv_1712.tag) {
                                        case slop_rdf_rdf_Term_term_iri:
                                        {
                                            __auto_type o = _mv_1712.data.term_iri;
                                            if (howl_canon_string_cmp(o.value, slop_rdf_vocab_OWL_ONTOLOGY) == 0) {
                                                __auto_type _mv_1713 = t.subject;
                                                switch (_mv_1713.tag) {
                                                    case slop_rdf_rdf_Term_term_iri:
                                                    {
                                                        __auto_type sub = _mv_1713.data.term_iri;
                                                        found = (slop_option_slop_rdf_rdf_IRI){.has_value = 1, .value = sub};
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

slop_string howl_cli_main_argv_to_string(uint8_t** argv, int64_t index) {
    {
        __auto_type ptr = argv[index];
        return (slop_string){.len = strlen(ptr), .data = ptr};
    }
}

uint8_t howl_cli_main_is_version_request(int64_t argc, uint8_t** argv) {
    if (argc == 2) {
        {
            __auto_type a = howl_cli_main_argv_to_string(argv, 1);
            if (string_eq(a, SLOP_STR("--version"))) {
                return 1;
            } else {
                return string_eq(a, SLOP_STR("-V"));
            }
        }
    } else {
        return 0;
    }
}

void howl_cli_main_print_usage(void) {
    printf("%s\n", "HOWL — a consequence-based description-logic reasoner");
    printf("%s\n", "");
    printf("%s\n", "USAGE:");
    printf("%s\n", "  howl validate    <ontology.ttl> [--profile P] [--strict] [--no-imports] [-I FILE]...");
    printf("%s\n", "  howl classify    <ontology.ttl>          (--reduce, --emit: not until M3)");
    printf("%s\n", "  howl ask         <ontology.ttl> [--profile P] [-I FILE]... [--probe FILE]... --ask-unsat C | --ask-sub A B ...");
    printf("%s\n", "  howl --version");
    printf("%s\n", "");
    printf("%s\n", "  -I FILE    attest FILE as a declared owl:Imports target; repeatable");
    printf("%s\n", "  --profile P  the calculus: el (default), el++, sriq, or auto;");
    printf("%s\n", "               auto runs the first of el, el++, sriq that omits nothing,");
    printf("%s\n", "               else the one omitting fewest; if sriq passes its clause");
    printf("%s\n", "               budget with nothing definitive, auto steps down to el or el++");
    printf("%s\n", "  --strict   refuse to run past any omission (exit 2, no report)");
    printf("%s\n", "  --report   print the canonical report instead of the summary");
    printf("%s\n", "  --timings  print phase durations and peak memory on stderr (never part of a report)");
    printf("%s\n", "  --max-iterations N   the round budget, 0..10000 (default 1000)");
    printf("%s\n", "  --workers N          threads joining each round, 1..64 (default 4); never changes the report");
    printf("%s\n", "  --probe FILE         a probe document: read only by the probe run; repeatable");
    printf("%s\n", "  --ask-unsat C        ask whether class C is unsatisfiable; repeatable");
    printf("%s\n", "  --ask-sub A B        ask whether A is subsumed by B; repeatable");
    printf("%s\n", "                       answered yes, no or unknown by a probe run of their own,");
    printf("%s\n", "                       printed after the report; the report is unchanged");
    printf("%s\n", "  howl ask             answers the queries alone, with no main run or report: it prints");
    printf("%s\n", "                       `profile P` and the probe lines, and exits 0 when it answered");
    printf("%s\n", "                       (whatever the answers), 2 if cancelled, 3 on an error");
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

void howl_cli_main_print_step_down(slop_arena* arena, slop_result_howl_types_Outcome_howl_types_Fault r) {
    __auto_type _mv_1714 = r;
    if (_mv_1714.is_ok) {
        __auto_type o = _mv_1714.data.ok;
        if (o.stepped_down) {
            howl_cli_main_eprint(string_concat(arena, SLOP_STR("howl: auto stepped down from sriq to "), string_concat(arena, howl_select_profile_name(o.profile), SLOP_STR(": sriq's run passed its clause budget with nothing definitive\n"))));
        }
    } else if (!_mv_1714.is_ok) {
        __auto_type _ = _mv_1714.data.err;
    }
}

void howl_cli_main_eprint(slop_string s) {
    fwrite(s.data, 1, s.len, stderr);;
}

void howl_cli_main_print_timings(slop_arena* arena, int64_t t0, int64_t t1, int64_t t2, int64_t t3, int64_t t4) {
    howl_cli_main_eprint(string_concat(arena, SLOP_STR("timing parse_ms="), string_concat(arena, int_to_string(arena, (t1 - t0)), string_concat(arena, SLOP_STR(" decode_ms="), string_concat(arena, int_to_string(arena, (t2 - t1)), string_concat(arena, SLOP_STR(" prepare_ms="), string_concat(arena, int_to_string(arena, (t3 - t2)), string_concat(arena, SLOP_STR(" reason_ms="), string_concat(arena, int_to_string(arena, (t4 - t3)), string_concat(arena, SLOP_STR(" total_ms="), string_concat(arena, int_to_string(arena, (t4 - t0)), SLOP_STR("\n"))))))))))));
}

int64_t howl_cli_main_peak_mb(void) {
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

void howl_cli_main_print_memory(slop_arena* arena, int64_t m1, int64_t m2, int64_t m3, int64_t m4, int64_t m5) {
    howl_cli_main_eprint(string_concat(arena, SLOP_STR("memory parse_mb="), string_concat(arena, int_to_string(arena, m1), string_concat(arena, SLOP_STR(" decode_mb="), string_concat(arena, int_to_string(arena, m2), string_concat(arena, SLOP_STR(" prepare_mb="), string_concat(arena, int_to_string(arena, m3), string_concat(arena, SLOP_STR(" reason_mb="), string_concat(arena, int_to_string(arena, m4), string_concat(arena, SLOP_STR(" report_mb="), string_concat(arena, int_to_string(arena, m5), SLOP_STR("\n"))))))))))));
}

uint8_t howl_cli_main_all_digits(slop_string s) {
    {
        uint8_t ok = (string_len(s) > 0);
        int64_t i = 0;
        while (ok && (i < string_len(s))) {
            if (!(std_strlib_is_digit(std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at main.slop:373:45"))))) {
                ok = 0;
            }
            i = (i + 1);
        }
        return ok;
    }
}

slop_result_howl_normalize_Decoded_howl_types_Fault howl_cli_main_decode_held(slop_arena* held, slop_arena* front, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI resolved) {
    {
        __auto_type res = howl_own_decoded(held, howl_decode_from(front, doc, resolved));
        (void)(({ slop_arena_free(front); free(front); }));
        return res;
    }
}

slop_result_howl_Prepared_howl_types_Fault howl_cli_main_prepare_from(slop_arena* arena, slop_arena* held, slop_result_howl_normalize_Decoded_howl_types_Fault d, howl_types_ReasonerConfig config) {
    {
        __auto_type res = ({ __auto_type _mv = d; slop_result_howl_Prepared_howl_types_Fault _mr; if (_mv.is_ok) { __auto_type dd = _mv.data.ok; _mr = howl_prepare_decoded(arena, dd, config); } else { __auto_type f = _mv.data.err; _mr = ((slop_result_howl_Prepared_howl_types_Fault){ .is_ok = false, .data.err = howl_types_copy_fault(arena, f) }); } _mr; });
        (void)(({ slop_arena_free(held); free(held); }));
        return res;
    }
}

slop_result_howl_types_Outcome_howl_types_Fault howl_cli_main_reason_prepared(slop_arena* arena, slop_result_howl_Prepared_howl_types_Fault p, howl_types_ReasonerConfig config) {
    __auto_type _mv_1715 = p;
    if (!_mv_1715.is_ok) {
        __auto_type f = _mv_1715.data.err;
        return ((slop_result_howl_types_Outcome_howl_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_1715.is_ok) {
        __auto_type pp = _mv_1715.data.ok;
        return howl_reason(arena, pp, config);
    }
    SLOP_UNREACHABLE();
}

howl_probe_Query howl_cli_main_cli_query(slop_arena* arena, howl_probe_QueryKind kind, slop_string sub, slop_string sup) {
    return ((howl_probe_Query){.kind = kind, .sub = ((slop_rdf_rdf_IRI){.value = sub}), .sup = ((slop_rdf_rdf_IRI){.value = sup})});
}

slop_option_howl_termstore_Encoded_ptr howl_cli_main_probe_input(slop_arena* arena, howl_termstore_Encoded main, howl_termstore_Encoded probes, slop_list_howl_probe_Query queries) {
    if (((int64_t)((queries).len)) == 0) {
        return (slop_option_howl_termstore_Encoded_ptr){.has_value = false};
    } else {
        return (slop_option_howl_termstore_Encoded_ptr){.has_value = 1, .value = howl_probe_probe_document(arena, main, probes, queries)};
    }
}

slop_option_result_howl_probe_Probing_howl_types_Fault howl_cli_main_probe_of(slop_arena* arena, slop_option_howl_termstore_Encoded_ptr doc, slop_list_slop_rdf_rdf_IRI resolved, slop_list_howl_probe_Query queries, howl_types_ReasonerConfig config, slop_result_howl_types_Outcome_howl_types_Fault main) {
    __auto_type _mv_1716 = main;
    if (!_mv_1716.is_ok) {
        __auto_type _ = _mv_1716.data.err;
        return (slop_option_result_howl_probe_Probing_howl_types_Fault){.has_value = false};
    } else if (_mv_1716.is_ok) {
        __auto_type _ = _mv_1716.data.ok;
        __auto_type _mv_1717 = doc;
        if (!_mv_1717.has_value) {
            return (slop_option_result_howl_probe_Probing_howl_types_Fault){.has_value = false};
        } else if (_mv_1717.has_value) {
            __auto_type d = _mv_1717.value;
            return (slop_option_result_howl_probe_Probing_howl_types_Fault){.has_value = 1, .value = howl_probe_encoded(arena, (*d), resolved, queries, config, 0)};
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_result_howl_types_Outcome_howl_types_Fault howl_cli_main_with_probe(slop_arena* arena, slop_result_howl_types_Outcome_howl_types_Fault main, slop_option_result_howl_probe_Probing_howl_types_Fault probed) {
    __auto_type _mv_1718 = probed;
    if (!_mv_1718.has_value) {
        return main;
    } else if (_mv_1718.has_value) {
        __auto_type pr = _mv_1718.value;
        __auto_type _mv_1719 = pr;
        if (_mv_1719.is_ok) {
            __auto_type _ = _mv_1719.data.ok;
            return main;
        } else if (!_mv_1719.is_ok) {
            __auto_type f = _mv_1719.data.err;
            return ((slop_result_howl_types_Outcome_howl_types_Fault){ .is_ok = false, .data.err = ({ __auto_type _mv = f; howl_types_Fault _mr = {0}; switch (_mv.tag) { case howl_types_Fault_input_error: { __auto_type m = _mv.data.input_error; _mr = ((howl_types_Fault){ .tag = howl_types_Fault_input_error, .data.input_error = string_concat(arena, SLOP_STR("probe run: "), m) }); break; } default: { _mr = f; break; }  } _mr; }) });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

void howl_cli_main_print_probes(slop_arena* arena, slop_option_result_howl_probe_Probing_howl_types_Fault probed) {
    __auto_type _mv_1720 = probed;
    if (_mv_1720.has_value) {
        __auto_type pr = _mv_1720.value;
        __auto_type _mv_1721 = pr;
        if (_mv_1721.is_ok) {
            __auto_type p = _mv_1721.data.ok;
            {
                __auto_type _coll = howl_report_probe_lines(arena, p);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type l = _coll.data[_i];
                    printf("%.*s\n", (int)(l).len, (l).data);
                }
            }
        } else if (!_mv_1721.is_ok) {
            __auto_type _ = _mv_1721.data.err;
        }
    } else if (!_mv_1720.has_value) {
    }
}

uint8_t howl_cli_main_operand(slop_string s) {
    return ((string_len(s) > 0) && !(std_strlib_starts_with(s, SLOP_STR("-"))));
}

void howl_cli_main_print_omissions(slop_arena* arena, slop_list_howl_types_Omission os) {
    {
        __auto_type _coll = os;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type o = _coll.data[_i];
            printf("%s", "  omitted: ");
            printf("%.*s\n", (int)(howl_owl2_render_omission(arena, o)).len, (howl_owl2_render_omission(arena, o)).data);
        }
    }
}

int64_t howl_cli_main_validate_run(slop_arena* arena, slop_arena* front, howl_termstore_Encoded* enc, slop_arena* pfront, howl_termstore_Encoded* penc, slop_list_slop_rdf_rdf_IRI resolved, slop_list_howl_probe_Query queries, howl_types_ReasonerConfig cfg, uint8_t report_mode, uint8_t timings, int64_t t_start) {
    {
        __auto_type asked = howl_probe_sort_queries(arena, queries);
        __auto_type pdoc = howl_cli_main_probe_input(pfront, (*enc), (*penc), asked);
        __auto_type t_parsed = slop_now_ms();
        __auto_type m_parsed = howl_cli_main_peak_mb();
        __auto_type held = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type decoded = howl_cli_main_decode_held(held, front, (*enc), resolved);
        __auto_type t_decoded = slop_now_ms();
        __auto_type m_decoded = howl_cli_main_peak_mb();
        __auto_type prepared = howl_cli_main_prepare_from(arena, held, decoded, cfg);
        __auto_type t_prepared = slop_now_ms();
        __auto_type m_prepared = howl_cli_main_peak_mb();
        __auto_type reasoned = howl_cli_main_reason_prepared(arena, prepared, cfg);
        __auto_type t_reasoned = slop_now_ms();
        __auto_type m_reasoned = howl_cli_main_peak_mb();
        __auto_type probed = howl_cli_main_probe_of(arena, pdoc, resolved, asked, cfg, reasoned);
        __auto_type result = howl_cli_main_with_probe(arena, reasoned, probed);
        if (timings) {
            howl_cli_main_print_timings(arena, t_start, t_parsed, t_decoded, t_prepared, t_reasoned);
        }
        howl_cli_main_print_step_down(arena, result);
        __auto_type _mv_1722 = result;
        if (_mv_1722.is_ok) {
            __auto_type o = _mv_1722.data.ok;
            if (report_mode) {
                {
                    __auto_type _coll = howl_report_report_lines(arena, o);
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
                howl_cli_main_print_omissions(arena, o.coverage.omitted);
                __auto_type _mv_1723 = howl_types_verdict(o);
                if (_mv_1723 == howl_types_Verdict_verdict_coherent) {
                    printf("%s\n", "howl: coherent");
                } else if (_mv_1723 == howl_types_Verdict_verdict_incoherent) {
                    printf("%s\n", "howl: INCOHERENT");
                } else if (_mv_1723 == howl_types_Verdict_verdict_inconclusive) {
                    printf("%s\n", "howl: INCONCLUSIVE — coverage gaps, this is NOT a pass");
                }
            }
        } else if (!_mv_1722.is_ok) {
            __auto_type f = _mv_1722.data.err;
            __auto_type _mv_1724 = f;
            switch (_mv_1724.tag) {
                case howl_types_Fault_input_error:
                {
                    __auto_type msg = _mv_1724.data.input_error;
                    printf("%s", "howl: ");
                    printf("%.*s\n", (int)(msg).len, (msg).data);
                    break;
                }
                case howl_types_Fault_cancelled:
                {
                    printf("%s\n", "howl: cancelled");
                    break;
                }
                case howl_types_Fault_unavailable:
                {
                    __auto_type p = _mv_1724.data.unavailable;
                    printf("%s", "howl: ");
                    printf("%.*s\n", (int)(howl_select_unavailable_message(arena, p)).len, (howl_select_unavailable_message(arena, p)).data);
                    break;
                }
                case howl_types_Fault_refused:
                {
                    __auto_type os = _mv_1724.data.refused;
                    printf("%s", "howl: refused (--strict), no report — ");
                    printf("%.*s", (int)(int_to_string(arena, ((int64_t)(((int64_t)((os).len)))))).len, (int_to_string(arena, ((int64_t)(((int64_t)((os).len)))))).data);
                    printf("%s\n", " omitted");
                    howl_cli_main_print_omissions(arena, os);
                    break;
                }
            }
        }
        howl_cli_main_print_probes(arena, probed);
        if (timings) {
            howl_cli_main_print_memory(arena, m_parsed, m_decoded, m_prepared, m_reasoned, howl_cli_main_peak_mb());
        }
        return howl_cli_main_exit_code_for(result);
    }
}

int64_t howl_cli_main_ask_run(slop_arena* arena, slop_arena* front, howl_termstore_Encoded* enc, slop_arena* pfront, howl_termstore_Encoded* penc, slop_list_slop_rdf_rdf_IRI resolved, slop_list_howl_probe_Query queries, howl_types_ReasonerConfig cfg) {
    if (((int64_t)((queries).len)) == 0) {
        printf("%s\n", "howl ask: nothing asked; give --ask-unsat C or --ask-sub A B");
        return howl_cli_main_EXIT_ERROR;
    } else {
        {
            __auto_type asked = howl_probe_sort_queries(arena, queries);
            __auto_type doc = howl_probe_probe_document(pfront, (*enc), (*penc), asked);
            __auto_type res = howl_probe_encoded(arena, (*doc), resolved, asked, cfg, 1);
            (void)(({ slop_arena_free(front); free(front); }));
            __auto_type _mv_1725 = res;
            if (_mv_1725.is_ok) {
                __auto_type p = _mv_1725.data.ok;
                {
                    __auto_type _coll = howl_report_answer_lines(arena, p, 1);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type l = _coll.data[_i];
                        printf("%.*s\n", (int)(l).len, (l).data);
                    }
                }
            } else if (!_mv_1725.is_ok) {
                __auto_type f = _mv_1725.data.err;
                howl_cli_main_print_ask_fault(arena, f);
            }
            return howl_cli_main_ask_exit_code(res);
        }
    }
}

void howl_cli_main_print_ask_fault(slop_arena* arena, howl_types_Fault f) {
    __auto_type _mv_1726 = f;
    switch (_mv_1726.tag) {
        case howl_types_Fault_input_error:
        {
            __auto_type msg = _mv_1726.data.input_error;
            printf("%s", "howl: ");
            printf("%.*s\n", (int)(msg).len, (msg).data);
            break;
        }
        case howl_types_Fault_cancelled:
        {
            printf("%s\n", "howl: cancelled");
            break;
        }
        case howl_types_Fault_unavailable:
        {
            __auto_type p = _mv_1726.data.unavailable;
            printf("%s", "howl: ");
            printf("%.*s\n", (int)(howl_select_unavailable_message(arena, p)).len, (howl_select_unavailable_message(arena, p)).data);
            break;
        }
        case howl_types_Fault_refused:
        {
            __auto_type _ = _mv_1726.data.refused;
            printf("%s\n", "howl: refused, no answers");
            break;
        }
    }
}

int64_t howl_cli_main_ask_exit_code(slop_result_howl_probe_Probing_howl_types_Fault r) {
    int64_t _retval = {0};
    __auto_type _mv_1727 = r;
    if (_mv_1727.is_ok) {
        __auto_type _ = _mv_1727.data.ok;
        _retval = 0;
        goto _slop_post;
    } else if (!_mv_1727.is_ok) {
        __auto_type f = _mv_1727.data.err;
        __auto_type _mv_1728 = f;
        switch (_mv_1728.tag) {
            case howl_types_Fault_cancelled:
            {
                _retval = 2;
                goto _slop_post;
            }
            case howl_types_Fault_refused:
            {
                __auto_type _ = _mv_1728.data.refused;
                _retval = 2;
                goto _slop_post;
            }
            case howl_types_Fault_input_error:
            {
                __auto_type _ = _mv_1728.data.input_error;
                _retval = 3;
                goto _slop_post;
            }
            case howl_types_Fault_unavailable:
            {
                __auto_type _ = _mv_1728.data.unavailable;
                _retval = 3;
                goto _slop_post;
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    SLOP_POST(((_retval <= 3)), "(<= $result 3)");
    SLOP_POST((({ __auto_type _mv = r; uint8_t _mr; if (_mv.is_ok) { __auto_type p = _mv.data.ok; _mr = (_retval == 0); } else { __auto_type f = _mv.data.err; _mr = ({ __auto_type _mv = f; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case howl_types_Fault_cancelled: { _mr = (_retval == 2); _mm = 1; break; } case howl_types_Fault_refused: { _mr = (_retval == 2); _mm = 1; break; } case howl_types_Fault_input_error: { _mr = (_retval == 3); _mm = 1; break; } case howl_types_Fault_unavailable: { _mr = (_retval == 3); _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; }); } _mr; })), "(match r ((ok p) (== $result 0)) ((error f) (match f ((cancelled) (== $result 2)) ((refused _) (== $result 2)) ((input-error _) (== $result 3)) ((unavailable _) (== $result 3)))))");
    return _retval;
}

int main(int argc, char** _c_argv) {
    uint8_t** argv = (uint8_t**)_c_argv;
    (void)argc; (void)argv;
    {
        #ifdef SLOP_DEBUG
        SLOP_PRE((268435456) > 0, "with-arena size must be positive");
        #endif
        slop_arena _arena_3 = slop_arena_new(268435456);
        #ifdef SLOP_DEBUG
        SLOP_PRE(_arena_3.base != NULL, "arena allocation failed");
        #endif
        slop_arena* arena = &_arena_3;
        if (howl_cli_main_is_version_request(argc, argv)) {
            printf("howl %s\n", HOWL_VERSION);;
            {
                int _wa_ret = 0;
                slop_arena_free(&_arena_3);
                return _wa_ret;
            }
        } else {
            if (argc < 3) {
                howl_cli_main_print_usage();
                {
                    int _wa_ret = howl_cli_main_EXIT_ERROR;
                    slop_arena_free(&_arena_3);
                    return _wa_ret;
                }
            } else {
                {
                    __auto_type command = howl_cli_main_argv_to_string(argv, 1);
                    if (!((string_eq(command, SLOP_STR("validate")) || (string_eq(command, SLOP_STR("classify")) || string_eq(command, SLOP_STR("ask")))))) {
                        printf("%s", "howl: unknown or unimplemented command: ");
                        printf("%.*s\n", (int)(command).len, (command).data);
                        {
                            int _wa_ret = howl_cli_main_EXIT_ERROR;
                            slop_arena_free(&_arena_3);
                            return _wa_ret;
                        }
                    } else {
                        {
                            __auto_type ask = string_eq(command, SLOP_STR("ask"));
                            __auto_type front = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
                            __auto_type enc = howl_termstore_new_encoded(front);
                            __auto_type resolved = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                            __auto_type cfg = howl_types_default_config();
                            uint8_t failed = 0;
                            int64_t i = 3;
                            uint8_t report_mode = 0;
                            uint8_t timings = 0;
                            __auto_type pfront = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
                            __auto_type penc = howl_termstore_new_encoded(pfront);
                            int64_t pdocs = 0;
                            __auto_type queries = ((slop_list_howl_probe_Query){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                            __auto_type t_start = slop_now_ms();
                            __auto_type input = howl_cli_main_argv_to_string(argv, 2);
                            if (!(howl_cli_main_parse_into(front, enc, input))) {
                                printf("%s", "howl: cannot parse ");
                                printf("%.*s\n", (int)(input).len, (input).data);
                                failed = 1;
                            }
                            while (i < argc) {
                                {
                                    __auto_type arg = howl_cli_main_argv_to_string(argv, i);
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
                                                __auto_type path = howl_cli_main_argv_to_string(argv, (i + 1));
                                                __auto_type from = ((int64_t)(((int64_t)(((*enc).triples).len))));
                                                howl_termstore_encoded_next_document(front, enc);
                                                if (!(howl_cli_main_parse_into(front, enc, path))) {
                                                    printf("%s", "howl: cannot parse import ");
                                                    printf("%.*s\n", (int)(path).len, (path).data);
                                                    failed = 1;
                                                } else {
                                                    __auto_type _mv_1729 = howl_cli_main_ontology_iri_from((*enc), from);
                                                    if (!_mv_1729.has_value) {
                                                        printf("%s", "howl: import declares no owl:Ontology IRI, so it attests nothing: ");
                                                        printf("%.*s\n", (int)(path).len, (path).data);
                                                        failed = 1;
                                                    } else if (_mv_1729.has_value) {
                                                        __auto_type o = _mv_1729.value;
                                                        ({ __auto_type _lst_p = &(resolved); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
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
                                            printf("%s\n", "howl: --profile needs a profile: auto, el, el++ or sriq");
                                            failed = 1;
                                        }
                                        if ((i + 1) < argc) {
                                            {
                                                __auto_type p = howl_cli_main_argv_to_string(argv, (i + 1));
                                                if (string_eq(p, SLOP_STR("auto"))) {
                                                    cfg.selection = ((howl_types_ProfileSelection){ .tag = howl_types_ProfileSelection_slop_auto });
                                                } else {
                                                    __auto_type _mv_1730 = howl_select_parse_profile(p);
                                                    if (_mv_1730.has_value) {
                                                        __auto_type q = _mv_1730.value;
                                                        cfg.selection = ((howl_types_ProfileSelection){ .tag = howl_types_ProfileSelection_explicit, .data.explicit = q });
                                                    } else if (!_mv_1730.has_value) {
                                                        printf("%s", "howl: unknown profile: ");
                                                        printf("%.*s", (int)(p).len, (p).data);
                                                        printf("%s\n", " (expected auto, el, el++ or sriq)");
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
                                    if (string_eq(arg, SLOP_STR("--probe"))) {
                                        known = 1;
                                        step = 2;
                                        if ((i + 1) >= argc) {
                                            printf("%s\n", "howl: --probe needs a FILE");
                                            failed = 1;
                                        } else {
                                            {
                                                __auto_type path = howl_cli_main_argv_to_string(argv, (i + 1));
                                                if (pdocs > 0) {
                                                    howl_termstore_encoded_next_document(pfront, penc);
                                                }
                                                pdocs = (pdocs + 1);
                                                if (!(howl_cli_main_parse_into(pfront, penc, path))) {
                                                    printf("%s", "howl: cannot parse probe document ");
                                                    printf("%.*s\n", (int)(path).len, (path).data);
                                                    failed = 1;
                                                }
                                            }
                                        }
                                    }
                                    if (string_eq(arg, SLOP_STR("--ask-unsat"))) {
                                        known = 1;
                                        step = 2;
                                        if (((i + 1) >= argc) || !(howl_cli_main_operand(howl_cli_main_argv_to_string(argv, (i + 1))))) {
                                            printf("%s\n", "howl: --ask-unsat needs a class IRI");
                                            failed = 1;
                                        } else {
                                            (void)(({ __auto_type _lst_p = &(queries); __auto_type _item = (howl_cli_main_cli_query(arena, howl_probe_QueryKind_query_unsatisfiable, howl_cli_main_argv_to_string(argv, (i + 1)), SLOP_STR(""))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                        }
                                    }
                                    if (string_eq(arg, SLOP_STR("--ask-sub"))) {
                                        known = 1;
                                        step = 3;
                                        if (((i + 2) >= argc) || !((howl_cli_main_operand(howl_cli_main_argv_to_string(argv, (i + 1))) && howl_cli_main_operand(howl_cli_main_argv_to_string(argv, (i + 2)))))) {
                                            printf("%s\n", "howl: --ask-sub needs two class IRIs");
                                            failed = 1;
                                        } else {
                                            (void)(({ __auto_type _lst_p = &(queries); __auto_type _item = (howl_cli_main_cli_query(arena, howl_probe_QueryKind_query_subsumed, howl_cli_main_argv_to_string(argv, (i + 1)), howl_cli_main_argv_to_string(argv, (i + 2)))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                        }
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
                                                __auto_type v = howl_cli_main_argv_to_string(argv, (i + 1));
                                                if (!(howl_cli_main_all_digits(v))) {
                                                    printf("%s\n", "howl: --max-iterations needs a whole number 0..10000");
                                                    failed = 1;
                                                } else {
                                                    __auto_type _mv_1731 = std_strlib_parse_int(v);
                                                    if (_mv_1731.is_ok) {
                                                        __auto_type n = _mv_1731.data.ok;
                                                        if (n <= 10000) {
                                                            cfg.max_iterations = ((int64_t)(n));
                                                        } else {
                                                            printf("%s\n", "howl: --max-iterations must be 0..10000");
                                                            failed = 1;
                                                        }
                                                    } else if (!_mv_1731.is_ok) {
                                                        __auto_type _ = _mv_1731.data.err;
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
                                                __auto_type v = howl_cli_main_argv_to_string(argv, (i + 1));
                                                if (!(howl_cli_main_all_digits(v))) {
                                                    printf("%s\n", "howl: --workers needs a whole number 1..64");
                                                    failed = 1;
                                                } else {
                                                    __auto_type _mv_1732 = std_strlib_parse_int(v);
                                                    if (_mv_1732.is_ok) {
                                                        __auto_type n = _mv_1732.data.ok;
                                                        if ((n >= 1) && (n <= 64)) {
                                                            cfg.worker_count = ((int64_t)(n));
                                                        } else {
                                                            printf("%s\n", "howl: --workers must be 1..64");
                                                            failed = 1;
                                                        }
                                                    } else if (!_mv_1732.is_ok) {
                                                        __auto_type _ = _mv_1732.data.err;
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
                            if (ask && (report_mode || (timings || cfg.strict_profile))) {
                                printf("%s\n", "howl ask: --report, --strict and --timings do not apply to an answer run");
                                failed = 1;
                            }
                            if (failed) {
                                {
                                    int _wa_ret = howl_cli_main_EXIT_ERROR;
                                    slop_arena_free(&_arena_3);
                                    return _wa_ret;
                                }
                            } else if (ask) {
                                {
                                    int _wa_ret = howl_cli_main_ask_run(arena, front, enc, pfront, penc, resolved, queries, cfg);
                                    slop_arena_free(&_arena_3);
                                    return _wa_ret;
                                }
                            } else {
                                {
                                    int _wa_ret = howl_cli_main_validate_run(arena, front, enc, pfront, penc, resolved, queries, cfg, report_mode, timings, t_start);
                                    slop_arena_free(&_arena_3);
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

