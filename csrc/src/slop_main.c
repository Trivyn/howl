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
int main(int argc, char** _c_argv);

int64_t main_exit_code_for(slop_result_types_Outcome_types_Fault r) {
    int64_t _retval = {0};
    __auto_type _mv_443 = r;
    if (_mv_443.is_ok) {
        __auto_type o = _mv_443.data.ok;
        __auto_type _mv_444 = howl_verdict(o);
        if (_mv_444 == howl_Verdict_verdict_coherent) {
            return 0;
        } else if (_mv_444 == howl_Verdict_verdict_incoherent) {
            return 1;
        } else if (_mv_444 == howl_Verdict_verdict_inconclusive) {
            return 2;
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_443.is_ok) {
        __auto_type f = _mv_443.data.err;
        __auto_type _mv_445 = f;
        switch (_mv_445.tag) {
            case types_Fault_cancelled:
            {
                return 2;
            }
            case types_Fault_refused:
            {
                __auto_type _ = _mv_445.data.refused;
                return 2;
            }
            case types_Fault_input_error:
            {
                __auto_type _ = _mv_445.data.input_error;
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
    __auto_type _mv_446 = t;
    switch (_mv_446.tag) {
        case rdf_Term_term_blank:
        {
            __auto_type b = _mv_446.data.term_blank;
            return b.id;
        }
        case rdf_Term_term_iri:
        {
            __auto_type _ = _mv_446.data.term_iri;
            return 0;
        }
        case rdf_Term_term_literal:
        {
            __auto_type _ = _mv_446.data.term_literal;
            return 0;
        }
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_446.data.term_triple;
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
    __auto_type _mv_447 = t;
    switch (_mv_447.tag) {
        case rdf_Term_term_blank:
        {
            __auto_type b = _mv_447.data.term_blank;
            return rdf_make_blank(arena, (b.id + offset));
        }
        case rdf_Term_term_iri:
        {
            __auto_type _ = _mv_447.data.term_iri;
            return t;
        }
        case rdf_Term_term_literal:
        {
            __auto_type _ = _mv_447.data.term_literal;
            return t;
        }
        case rdf_Term_term_triple:
        {
            __auto_type tt = _mv_447.data.term_triple;
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
                __auto_type _mv_448 = t.predicate;
                switch (_mv_448.tag) {
                    case rdf_Term_term_iri:
                    {
                        __auto_type p = _mv_448.data.term_iri;
                        if (canon_string_cmp(p.value, vocab_RDF_TYPE) == 0) {
                            __auto_type _mv_449 = t.object;
                            switch (_mv_449.tag) {
                                case rdf_Term_term_iri:
                                {
                                    __auto_type o = _mv_449.data.term_iri;
                                    if (canon_string_cmp(o.value, vocab_OWL_ONTOLOGY) == 0) {
                                        __auto_type _mv_450 = t.subject;
                                        switch (_mv_450.tag) {
                                            case rdf_Term_term_iri:
                                            {
                                                __auto_type sub = _mv_450.data.term_iri;
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
    printf("%s\n", "  howl validate    <ontology.ttl> [--profile P] [--strict] [-I DIR]");
    printf("%s\n", "  howl classify    <ontology.ttl> [--reduce] [--emit inferred.ttl]");
    printf("%s\n", "  howl unsat       <ontology.ttl>");
    printf("%s\n", "  howl align-check <o1.ttl> <o2.ttl> <mappings.ttl> [--repair]");
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
        if (argc < 2) {
            main_print_usage();
            return main_EXIT_ERROR;
        } else {
            {
                __auto_type command = main_argv_to_string(argv, 1);
                if (string_eq(command, SLOP_STR("--help"))) {
                    main_print_usage();
                    return main_EXIT_ERROR;
                } else {
                    if (argc < 3) {
                        main_print_usage();
                        return main_EXIT_ERROR;
                    } else {
                        {
                            __auto_type triples = ((slop_list_rdf_Triple){ .data = (rdf_Triple*)slop_arena_alloc(arena, 16 * sizeof(rdf_Triple)), .len = 0, .cap = 16 });
                            __auto_type resolved = ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 });
                            uint8_t failed = 0;
                            int64_t i = 2;
                            __auto_type input = main_argv_to_string(argv, 2);
                            __auto_type _mv_451 = ttl_parse_ttl_file(arena, input);
                            if (!_mv_451.is_ok) {
                                __auto_type _ = _mv_451.data.err;
                                printf("%s", "howl: cannot parse ");
                                printf("%.*s\n", (int)(input).len, (input).data);
                                failed = 1;
                            } else if (_mv_451.is_ok) {
                                __auto_type g = _mv_451.data.ok;
                                {
                                    __auto_type _coll = g.triples;
                                    for (size_t _i = 0; _i < _coll.len; _i++) {
                                        __auto_type t = _coll.data[_i];
                                        ({ __auto_type _lst_p = &(triples); __auto_type _item = (t); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                            i = 3;
                            while (i < argc) {
                                {
                                    __auto_type arg = main_argv_to_string(argv, i);
                                    if (string_eq(arg, SLOP_STR("-I")) && ((i + 1) < argc)) {
                                        {
                                            __auto_type path = main_argv_to_string(argv, (i + 1));
                                            __auto_type _mv_452 = ttl_parse_ttl_file(arena, path);
                                            if (!_mv_452.is_ok) {
                                                __auto_type _ = _mv_452.data.err;
                                                printf("%s", "howl: cannot parse import ");
                                                printf("%.*s\n", (int)(path).len, (path).data);
                                                failed = 1;
                                            } else if (_mv_452.is_ok) {
                                                __auto_type ig = _mv_452.data.ok;
                                                {
                                                    __auto_type offset = (main_max_blank_id(triples) + 1);
                                                    {
                                                        __auto_type _coll = ig.triples;
                                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                                            __auto_type t = _coll.data[_i];
                                                            ({ __auto_type _lst_p = &(triples); __auto_type _item = (rdf_make_triple(arena, main_remap_blank(arena, t.subject, offset), t.predicate, main_remap_blank(arena, t.object, offset))); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                        }
                                                    }
                                                    __auto_type _mv_453 = main_ontology_iri_of(ig.triples);
                                                    if (_mv_453.has_value) {
                                                        __auto_type o = _mv_453.value;
                                                        ({ __auto_type _lst_p = &(resolved); __auto_type _item = (o); if (_lst_p->len >= _lst_p->cap) { size_t _new_cap = _lst_p->cap == 0 ? 16 : _lst_p->cap * 2; __typeof__(_lst_p->data) _new_data = (__typeof__(_lst_p->data))slop_arena_alloc(arena, _new_cap * sizeof(*_lst_p->data)); if (_lst_p->len > 0) memcpy(_new_data, _lst_p->data, _lst_p->len * sizeof(*_lst_p->data)); _lst_p->data = _new_data; _lst_p->cap = _new_cap; } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                                    } else if (!_mv_453.has_value) {
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    i = (i + 1);
                                }
                            }
                            if (failed) {
                                return main_EXIT_ERROR;
                            } else {
                                {
                                    __auto_type result = howl_classify(arena, triples, resolved, howl_default_config());
                                    __auto_type _mv_454 = result;
                                    if (_mv_454.is_ok) {
                                        __auto_type o = _mv_454.data.ok;
                                        printf("%s", "howl: ");
                                        printf("%.*s", (int)(int_to_string(arena, ((int64_t)(((int64_t)((o.findings.subsumptions).len)))))).len, (int_to_string(arena, ((int64_t)(((int64_t)((o.findings.subsumptions).len)))))).data);
                                        printf("%s", " subsumptions, ");
                                        printf("%.*s", (int)(int_to_string(arena, ((int64_t)(((int64_t)((o.findings.unsatisfiable).len)))))).len, (int_to_string(arena, ((int64_t)(((int64_t)((o.findings.unsatisfiable).len)))))).data);
                                        printf("%s", " unsatisfiable, ");
                                        printf("%.*s", (int)(int_to_string(arena, ((int64_t)(((int64_t)((o.coverage.omitted).len)))))).len, (int_to_string(arena, ((int64_t)(((int64_t)((o.coverage.omitted).len)))))).data);
                                        printf("%s\n", " omitted");
                                        __auto_type _mv_455 = howl_verdict(o);
                                        if (_mv_455 == howl_Verdict_verdict_coherent) {
                                            printf("%s\n", "howl: coherent");
                                        } else if (_mv_455 == howl_Verdict_verdict_incoherent) {
                                            printf("%s\n", "howl: INCOHERENT");
                                        } else if (_mv_455 == howl_Verdict_verdict_inconclusive) {
                                            printf("%s\n", "howl: INCONCLUSIVE — coverage gaps, this is NOT a pass");
                                        }
                                    } else if (!_mv_454.is_ok) {
                                        __auto_type f = _mv_454.data.err;
                                        __auto_type _mv_456 = f;
                                        switch (_mv_456.tag) {
                                            case types_Fault_input_error:
                                            {
                                                __auto_type msg = _mv_456.data.input_error;
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
                                                __auto_type _ = _mv_456.data.refused;
                                                printf("%s\n", "howl: refused (--strict)");
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
        }
        slop_arena_free(arena);
    }
}

