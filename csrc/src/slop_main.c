#include "../runtime/slop_runtime.h"
#include "slop_main.h"

#define main_EXIT_COHERENT (0)
#define main_EXIT_INCOHERENT (1)
#define main_EXIT_INCONCLUSIVE (2)
#define main_EXIT_ERROR (3)

int64_t main_exit_code_for(slop_result_types_Outcome_types_Fault r);
slop_string main_argv_to_string(uint8_t** argv, int64_t index);
void main_print_usage(void);
int main(int argc, char** _c_argv);

int64_t main_exit_code_for(slop_result_types_Outcome_types_Fault r) {
    int64_t _retval = {0};
    __auto_type _mv_11 = r;
    if (_mv_11.is_ok) {
        __auto_type o = _mv_11.data.ok;
        __auto_type _mv_12 = howl_verdict(o);
        if (_mv_12 == howl_Verdict_verdict_coherent) {
            return 0;
        } else if (_mv_12 == howl_Verdict_verdict_incoherent) {
            return 1;
        } else if (_mv_12 == howl_Verdict_verdict_inconclusive) {
            return 2;
        }
    } else if (!_mv_11.is_ok) {
        __auto_type f = _mv_11.data.err;
        __auto_type _mv_13 = f;
        switch (_mv_13.tag) {
            case types_Fault_cancelled:
            {
                return 2;
            }
            case types_Fault_refused:
            {
                __auto_type _ = _mv_13.data.refused;
                return 2;
            }
            case types_Fault_input_error:
            {
                __auto_type _ = _mv_13.data.input_error;
                return 3;
            }
        }
    }
    SLOP_POST(((_retval >= 0)), "(>= $result 0)");
    SLOP_POST(((_retval <= 3)), "(<= $result 3)");
    SLOP_POST((({ __auto_type _mv = r; uint8_t _mr; if (_mv.is_ok) { __auto_type o = _mv.data.ok; _mr = (_retval <= 2); } else { __auto_type f = _mv.data.err; _mr = ({ __auto_type _mv = f; uint8_t _mr = {0}; switch (_mv.tag) { case types_Fault_cancelled: { _mr = (_retval == 2); break; } case types_Fault_refused: { __auto_type _ = _mv.data.refused; _mr = (_retval == 2); break; } case types_Fault_input_error: { __auto_type _ = _mv.data.input_error; _mr = (_retval == 3); break; }  } _mr; }); } _mr; })), "(match r ((ok o) (<= $result 2)) ((error f) (match f ((cancelled) (== $result 2)) ((refused _) (== $result 2)) ((input-error _) (== $result 3)))))");
    return _retval;
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
                    {
                        __auto_type result = howl_classify(arena, ((slop_list_rdf_Triple){ .data = (rdf_Triple*)slop_arena_alloc(arena, 16 * sizeof(rdf_Triple)), .len = 0, .cap = 16 }), ((slop_list_rdf_IRI){ .data = (rdf_IRI*)slop_arena_alloc(arena, 16 * sizeof(rdf_IRI)), .len = 0, .cap = 16 }), howl_default_config());
                        __auto_type _mv_14 = result;
                        if (_mv_14.is_ok) {
                            __auto_type _ = _mv_14.data.ok;
                            printf("%s\n", "howl: unexpected outcome from an unimplemented pipeline");
                        } else if (!_mv_14.is_ok) {
                            __auto_type f = _mv_14.data.err;
                            __auto_type _mv_15 = f;
                            switch (_mv_15.tag) {
                                case types_Fault_input_error:
                                {
                                    __auto_type msg = _mv_15.data.input_error;
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
                                    __auto_type _ = _mv_15.data.refused;
                                    printf("%s\n", "howl: refused (--strict): input carried out-of-profile axioms");
                                    break;
                                }
                            }
                        }
                        return main_exit_code_for(result);
                    }
                }
            }
        }
        slop_arena_free(arena);
    }
}

