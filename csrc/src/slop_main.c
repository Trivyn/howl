#include "../runtime/slop_runtime.h"
#include "slop_main.h"

#define main_EXIT_COHERENT (0)
#define main_EXIT_INCOHERENT (1)
#define main_EXIT_INCONCLUSIVE (2)
#define main_EXIT_ERROR (3)

int64_t main_exit_code_for(slop_result_types_Outcome_types_Fault r);
int64_t main_max_blank_in_term(rdf_Term t);
int64_t main_max_blank_id(slop_list_rdf_Triple ts);
rdf_Term main_remap_blank(slop_arena* arena, rdf_Term t, int64_t offset);
slop_option_rdf_IRI main_ontology_iri_of(slop_list_rdf_Triple ts);
slop_string main_argv_to_string(uint8_t** argv, int64_t index);
void main_print_usage(void);
void main_eprint(slop_string s);
void main_print_timings(slop_arena* arena, int64_t t0, int64_t t1, int64_t t2, int64_t t3);
uint8_t main_all_digits(slop_string s);
slop_result_types_Outcome_types_Fault main_reason_prepared(slop_arena* arena, slop_result_howl_Prepared_types_Fault p, types_ReasonerConfig config);
void main_print_omissions(slop_arena* arena, slop_list_types_Omission os);
int main(int argc, char** _c_argv);

int64_t main_exit_code_for(slop_result_types_Outcome_types_Fault r) {
    int64_t _retval = {0};
    __auto_type _mv_521 = r;
    if (_mv_521.is_ok) {
        __auto_type o = _mv_521.data.ok;
        __auto_type _mv_522 = howl_verdict(o);
        if (_mv_522 == howl_Verdict_verdict_coherent) {
            return 0;
        } else if (_mv_522 == howl_Verdict_verdict_incoherent) {
            return 1;
        } else if (_mv_522 == howl_Verdict_verdict_inconclusive) {
            return 2;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_521.is_ok) {
        __auto_type f = _mv_521.data.err;
        __auto_type _mv_523 = f;
        switch (_mv_523.tag) {
            case types_Fault_cancelled:
            {
                return 2;
            }
            case types_Fault_refused:
            {
                __auto_type _ = _mv_523.data.refused;
                return 2;
            }
            case types_Fault_input_error:
            {
                __auto_type _ = _mv_523.data.input_error;
                return 3;
            }
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    SLOP_POST(((_retval <= 3)), "(<= $result 3)");
    SLOP_POST((({ __auto_type _mv = r; uint8_t _mr; if (_mv.is_ok) { __auto_type o = _mv.data.ok; _mr = (_retval <= 2); } else { __auto_type f = _mv.data.err; _mr = ({ __auto_type _mv = f; uint8_t _mr = {0}; switch (_mv.tag) { case types_Fault_cancelled: { _mr = (_retval == 2); break; } case types_Fault_refused: { __auto_type _ = _mv.data.refused; _mr = (_retval == 2); break; } case types_Fault_input_error: { __auto_type _ = _mv.data.input_error; _mr = (_retval == 3); break; }  } _mr; }); } _mr; })), "(match r ((ok o) (<= $result 2)) ((error f) (match f ((cancelled) (== $result 2)) ((refused _) (== $result 2)) ((input-error _) (== $result 3)))))");
    return _retval;
}

int64_t main_max_blank_in_term(rdf_Term t) {
    __auto_type _mv_524 = t;
    switch (_mv_524.tag) {
        case rdf_Term_term_blank:
        {
            __auto_type b = _mv_524.data.term_blank;
            return b.id;
        }
        case rdf_Term_term_iri:
        {
            __auto_type _ = _mv_524.data.term_iri;
            return 0;
        }
        case rdf_Term_term_literal:
        {
            __auto_type _ = _mv_524.data.term_literal;
            return 0;
        }
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_524.data.term_triple;
            {
                __auto_type tr = (*tt);
                return ((main_max_blank_in_term(tr.subject)) > (((main_max_blank_in_term(tr.predicate)) > (main_max_blank_in_term(tr.object)) ? (main_max_blank_in_term(tr.predicate)) : (main_max_blank_in_term(tr.object)))) ? (main_max_blank_in_term(tr.subject)) : (((main_max_blank_in_term(tr.predicate)) > (main_max_blank_in_term(tr.object)) ? (main_max_blank_in_term(tr.predicate)) : (main_max_blank_in_term(tr.object)))));
            }
        }
    }
    SLOP_UNREACHABLE();
}

int64_t main_max_blank_id(slop_list_rdf_Triple ts) {
    {
        int64_t m = 0;
        {
            __auto_type _coll = ts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                m = ((m) > (main_max_blank_in_term(t.subject)) ? (m) : (main_max_blank_in_term(t.subject)));
                m = ((m) > (main_max_blank_in_term(t.predicate)) ? (m) : (main_max_blank_in_term(t.predicate)));
                m = ((m) > (main_max_blank_in_term(t.object)) ? (m) : (main_max_blank_in_term(t.object)));
            }
        }
        return m;
    }
}

rdf_Term main_remap_blank(slop_arena* arena, rdf_Term t, int64_t offset) {
    __auto_type _mv_525 = t;
    switch (_mv_525.tag) {
        case rdf_Term_term_blank:
        {
            __auto_type b = _mv_525.data.term_blank;
            return rdf_make_blank(arena, (b.id + offset));
        }
        case rdf_Term_term_iri:
        {
            __auto_type _ = _mv_525.data.term_iri;
            return t;
        }
        case rdf_Term_term_literal:
        {
            __auto_type _ = _mv_525.data.term_literal;
            return t;
        }
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_525.data.term_triple;
            {
                __auto_type tr = (*tt);
                return rdf_make_triple_term(arena, rdf_make_triple(arena, main_remap_blank(arena, tr.subject, offset), main_remap_blank(arena, tr.predicate, offset), main_remap_blank(arena, tr.object, offset)));
            }
        }
    }
    SLOP_UNREACHABLE();
}

slop_option_rdf_IRI main_ontology_iri_of(slop_list_rdf_Triple ts) {
    {
        slop_option_rdf_IRI found = (slop_option_rdf_IRI){.has_value = false};
        {
            __auto_type _coll = ts;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                __auto_type _mv_526 = t.predicate;
                switch (_mv_526.tag) {
                    case rdf_Term_term_iri:
                    {
                        __auto_type p = _mv_526.data.term_iri;
                        if (canon_string_cmp(p.value, vocab_RDF_TYPE) == 0) {
                            __auto_type _mv_527 = t.object;
                            switch (_mv_527.tag) {
                                case rdf_Term_term_iri:
                                {
                                    __auto_type o = _mv_527.data.term_iri;
                                    if (canon_string_cmp(o.value, vocab_OWL_ONTOLOGY) == 0) {
                                        __auto_type _mv_528 = t.subject;
                                        switch (_mv_528.tag) {
                                            case rdf_Term_term_iri:
                                            {
                                                __auto_type sub = _mv_528.data.term_iri;
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
    printf("%s\n", "  howl validate    <ontology.ttl> [--profile el|auto] [--strict] [--no-imports] [-I FILE]...");
    printf("%s\n", "  howl classify    <ontology.ttl>          (--reduce, --emit: not until M3)");
    printf("%s\n", "");
    printf("%s\n", "  -I FILE    attest FILE as a declared owl:Imports target; repeatable");
    printf("%s\n", "  --strict   refuse to run past any omission (exit 2, no report)");
    printf("%s\n", "  --report   print the canonical report instead of the summary");
    printf("%s\n", "  --timings  print phase durations on stderr (never part of a report)");
    printf("%s\n", "  --max-iterations N   the round budget, 0..10000 (default 1000)");
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

void main_print_timings(slop_arena* arena, int64_t t0, int64_t t1, int64_t t2, int64_t t3) {
    main_eprint(string_concat(arena, SLOP_STR("timing parse_ms="), string_concat(arena, int_to_string(arena, (t1 - t0)), string_concat(arena, SLOP_STR(" prepare_ms="), string_concat(arena, int_to_string(arena, (t2 - t1)), string_concat(arena, SLOP_STR(" reason_ms="), string_concat(arena, int_to_string(arena, (t3 - t2)), string_concat(arena, SLOP_STR(" total_ms="), string_concat(arena, int_to_string(arena, (t3 - t0)), SLOP_STR("\n"))))))))));
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

slop_result_types_Outcome_types_Fault main_reason_prepared(slop_arena* arena, slop_result_howl_Prepared_types_Fault p, types_ReasonerConfig config) {
    __auto_type _mv_529 = p;
    if (!_mv_529.is_ok) {
        __auto_type f = _mv_529.data.err;
        return ((slop_result_types_Outcome_types_Fault){ .is_ok = false, .data.err = f });
    } else if (_mv_529.is_ok) {
        __auto_type pp = _mv_529.data.ok;
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
            return main_EXIT_ERROR;
        } else {
            {
                __auto_type command = main_argv_to_string(argv, 1);
                if (!((string_eq(command, SLOP_STR("validate")) || string_eq(command, SLOP_STR("classify"))))) {
                    printf("%s", "howl: unknown or unimplemented command: ");
                    printf("%.*s\n", (int)(command).len, (command).data);
                    return main_EXIT_ERROR;
                } else {
                    {
                        __auto_type triples = ((slop_list_rdf_Triple){ .data = (rdf_Triple*)slop_arena_alloc(arena, 16 * sizeof(rdf_Triple)), .len = 0, .cap = 16 });
                        __auto_type resolved = ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 });
                        __auto_type cfg = howl_default_config();
                        uint8_t failed = 0;
                        int64_t i = 3;
                        uint8_t report_mode = 0;
                        uint8_t timings = 0;
                        __auto_type t_start = slop_now_ms();
                        __auto_type input = main_argv_to_string(argv, 2);
                        __auto_type _mv_530 = ttl_parse_ttl_file(arena, input);
                        if (!_mv_530.is_ok) {
                            __auto_type _ = _mv_530.data.err;
                            printf("%s", "howl: cannot parse ");
                            printf("%.*s\n", (int)(input).len, (input).data);
                            failed = 1;
                        } else if (_mv_530.is_ok) {
                            __auto_type g = _mv_530.data.ok;
                            {
                                __auto_type _coll = g.triples;
                                for (size_t _i = 0; _i < _coll.len; _i++) {
                                    __auto_type t = _coll.data[_i];
                                    ({ __auto_type _lst_p = &(triples); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
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
                                            __auto_type _mv_531 = ttl_parse_ttl_file(arena, path);
                                            if (!_mv_531.is_ok) {
                                                __auto_type _ = _mv_531.data.err;
                                                printf("%s", "howl: cannot parse import ");
                                                printf("%.*s\n", (int)(path).len, (path).data);
                                                failed = 1;
                                            } else if (_mv_531.is_ok) {
                                                __auto_type ig = _mv_531.data.ok;
                                                __auto_type _mv_532 = main_ontology_iri_of(ig.triples);
                                                if (!_mv_532.has_value) {
                                                    printf("%s", "howl: import declares no owl:Ontology IRI, so it attests nothing: ");
                                                    printf("%.*s\n", (int)(path).len, (path).data);
                                                    failed = 1;
                                                } else if (_mv_532.has_value) {
                                                    __auto_type o = _mv_532.value;
                                                    {
                                                        __auto_type offset = (main_max_blank_id(triples) + 1);
                                                        {
                                                            __auto_type _coll = ig.triples;
                                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                                __auto_type t = _coll.data[_i];
                                                                ({ __auto_type _lst_p = &(triples); __auto_type _item = (rdf_make_triple(arena, main_remap_blank(arena, t.subject, offset), t.predicate, main_remap_blank(arena, t.object, offset))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                            }
                                                        }
                                                        ({ __auto_type _lst_p = &(resolved); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    }
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
                                        printf("%s\n", "howl: --profile needs el or auto");
                                        failed = 1;
                                    }
                                    if ((i + 1) < argc) {
                                        {
                                            __auto_type p = main_argv_to_string(argv, (i + 1));
                                            if (string_eq(p, SLOP_STR("el"))) {
                                                cfg.selection = ((types_ProfileSelection){ .tag = types_ProfileSelection_explicit, .data.explicit = types_Profile_profile_el });
                                            }
                                            if (!((string_eq(p, SLOP_STR("el")) || string_eq(p, SLOP_STR("auto"))))) {
                                                printf("%s", "howl: profile not implemented in v0: ");
                                                printf("%.*s\n", (int)(p).len, (p).data);
                                                failed = 1;
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
                                                __auto_type _mv_533 = strlib_parse_int(v);
                                                if (_mv_533.is_ok) {
                                                    __auto_type n = _mv_533.data.ok;
                                                    if (n <= 10000) {
                                                        cfg.max_iterations = ((int64_t)(n));
                                                    } else {
                                                        printf("%s\n", "howl: --max-iterations must be 0..10000");
                                                        failed = 1;
                                                    }
                                                } else if (!_mv_533.is_ok) {
                                                    __auto_type _ = _mv_533.data.err;
                                                    printf("%s\n", "howl: --max-iterations needs a whole number 0..10000");
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
                            return main_EXIT_ERROR;
                        } else {
                            {
                                __auto_type t_parsed = slop_now_ms();
                                __auto_type prepared = howl_prepare(arena, triples, resolved, cfg);
                                __auto_type t_prepared = slop_now_ms();
                                __auto_type result = main_reason_prepared(arena, prepared, cfg);
                                __auto_type t_reasoned = slop_now_ms();
                                if (timings) {
                                    main_print_timings(arena, t_start, t_parsed, t_prepared, t_reasoned);
                                }
                                __auto_type _mv_534 = result;
                                if (_mv_534.is_ok) {
                                    __auto_type o = _mv_534.data.ok;
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
                                        __auto_type _mv_535 = howl_verdict(o);
                                        if (_mv_535 == howl_Verdict_verdict_coherent) {
                                            printf("%s\n", "howl: coherent");
                                        } else if (_mv_535 == howl_Verdict_verdict_incoherent) {
                                            printf("%s\n", "howl: INCOHERENT");
                                        } else if (_mv_535 == howl_Verdict_verdict_inconclusive) {
                                            printf("%s\n", "howl: INCONCLUSIVE — coverage gaps, this is NOT a pass");
                                        }
                                    }
                                } else if (!_mv_534.is_ok) {
                                    __auto_type f = _mv_534.data.err;
                                    __auto_type _mv_536 = f;
                                    switch (_mv_536.tag) {
                                        case types_Fault_input_error:
                                        {
                                            __auto_type msg = _mv_536.data.input_error;
                                            printf("%s", "howl: ");
                                            printf("%.*s\n", (int)(msg).len, (msg).data);
                                            break;
                                        }
                                        case types_Fault_cancelled:
                                        {
                                            printf("%s\n", "howl: cancelled");
                                            break;
                                        }
                                        case types_Fault_refused:
                                        {
                                            __auto_type os = _mv_536.data.refused;
                                            printf("%s", "howl: refused (--strict), no report — ");
                                            printf("%.*s", (int)(int_to_string(arena, ((int64_t)(((int64_t)((os).len)))))).len, (int_to_string(arena, ((int64_t)(((int64_t)((os).len)))))).data);
                                            printf("%s\n", " omitted");
                                            main_print_omissions(arena, os);
                                            break;
                                        }
                                    }
                                }
                                return main_exit_code_for(result);
                            }
                        }
                    }
                }
            }
        }
        slop_arena_free(arena);
    }
}

