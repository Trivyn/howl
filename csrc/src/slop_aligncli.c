#include "../runtime/slop_runtime.h"
#include "slop_aligncli.h"

int64_t howl_cli_aligncli_peak_mb(void);
slop_string howl_cli_aligncli_arg(uint8_t** argv, int64_t i);
slop_string howl_cli_aligncli_file_source(slop_arena* a, slop_string path);
uint8_t howl_cli_aligncli_parse_into(slop_arena* arena, howl_termstore_Encoded* enc, slop_string path);
slop_option_slop_rdf_rdf_IRI howl_cli_aligncli_ontology_iri_from(howl_termstore_Encoded e, int64_t from);
uint8_t howl_cli_aligncli_all_digits(slop_string s);
slop_option_int howl_cli_aligncli_whole_number(slop_string s);
void howl_cli_aligncli_print_fault(slop_arena* a, howl_types_Fault f);
int64_t howl_cli_aligncli_fault_exit(howl_types_Fault f);
int64_t howl_cli_aligncli_outcome_exit(howl_types_Outcome o);
slop_string howl_cli_aligncli_source_of(slop_arena* a, slop_string path, slop_string override);
int64_t howl_cli_aligncli_align_main(int64_t argc, uint8_t** argv);

typedef struct { slop_arena* arena; howl_termstore_Encoded* enc; } howl_cli_aligncli__lambda_1843_env_t;

static void howl_cli_aligncli__lambda_1843(howl_cli_aligncli__lambda_1843_env_t* _env, slop_rdf_rdf_Triple t) { howl_termstore_encoded_add(_env->arena, _env->enc, t); }

int64_t howl_cli_aligncli_peak_mb(void) {
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

slop_string howl_cli_aligncli_arg(uint8_t** argv, int64_t i) {
    {
        __auto_type p = argv[i];
        return (slop_string){.len = strlen(p), .data = p};
    }
}

slop_string howl_cli_aligncli_file_source(slop_arena* a, slop_string path) {
    {
        slop_string out = SLOP_STR("");
        {
#ifdef _WIN32
 char *abs = _fullpath(NULL, path.data, 0);
#else
 char *abs = realpath(path.data, NULL);
#endif
 if (abs) {
   size_t n = strlen(abs), k = 0;
   char *buf = (char*)slop_arena_alloc(a, 8 + 3*n + 1);
   const char *prefix =
#ifdef _WIN32
     "file:///";
#else
     "file://";
#endif
   size_t pn = strlen(prefix); memcpy(buf, prefix, pn); k = pn;
   for (size_t i = 0; i < n; i++) {
     unsigned char c = (unsigned char)abs[i];
     if (c == '\\') c = '/';
     if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
         (c >= '0' && c <= '9') || c == '-' || c == '.' || c == '_' ||
         c == '~' || c == '/' || c == ':') buf[k++] = (char)c;
     else { static const char hex[] = "0123456789ABCDEF";
            buf[k++] = '%'; buf[k++] = hex[c >> 4]; buf[k++] = hex[c & 15]; }
   }
   buf[k] = 0; out = (slop_string){k, buf}; free(abs);
 }
};
        return out;
    }
}

uint8_t howl_cli_aligncli_parse_into(slop_arena* arena, howl_termstore_Encoded* enc, slop_string path) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
        __auto_type ok = ({ __auto_type _mv = slop_rdf_ttl_parse_ttl_file_for_each_triple(scratch, path, ({ howl_cli_aligncli__lambda_1843_env_t* howl_cli_aligncli__lambda_1843_env = (howl_cli_aligncli__lambda_1843_env_t*)slop_arena_alloc(arena, sizeof(howl_cli_aligncli__lambda_1843_env_t)); *howl_cli_aligncli__lambda_1843_env = (howl_cli_aligncli__lambda_1843_env_t){ .arena = arena, .enc = enc }; (slop_closure_t){ (void*)howl_cli_aligncli__lambda_1843, (void*)howl_cli_aligncli__lambda_1843_env }; })); uint8_t _mr; if (_mv.is_ok) { __auto_type _ = _mv.data.ok; _mr = 1; } else { __auto_type _ = _mv.data.err; _mr = 0; } _mr; });
        (void)(({ slop_arena_free(scratch); free(scratch); }));
        return ok;
    }
}

slop_option_slop_rdf_rdf_IRI howl_cli_aligncli_ontology_iri_from(howl_termstore_Encoded e, int64_t from) {
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
                        __auto_type _mv_1844 = t.predicate;
                        switch (_mv_1844.tag) {
                            case slop_rdf_rdf_Term_term_iri:
                            {
                                __auto_type p = _mv_1844.data.term_iri;
                                if (howl_canon_string_cmp(p.value, slop_rdf_vocab_RDF_TYPE) == 0) {
                                    __auto_type _mv_1845 = t.object;
                                    switch (_mv_1845.tag) {
                                        case slop_rdf_rdf_Term_term_iri:
                                        {
                                            __auto_type o = _mv_1845.data.term_iri;
                                            if (howl_canon_string_cmp(o.value, slop_rdf_vocab_OWL_ONTOLOGY) == 0) {
                                                __auto_type _mv_1846 = t.subject;
                                                switch (_mv_1846.tag) {
                                                    case slop_rdf_rdf_Term_term_iri:
                                                    {
                                                        __auto_type sub = _mv_1846.data.term_iri;
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

uint8_t howl_cli_aligncli_all_digits(slop_string s) {
    {
        uint8_t yes = (string_len(s) > 0);
        int64_t i = 0;
        while (yes && (i < string_len(s))) {
            if (!(std_strlib_is_digit(std_strlib_char_at(s, SLOP_RANGE(int64_t, i, 1, 0, 0, 0, "(Int 0 ..) at aligncli.slop:78:47"))))) {
                yes = 0;
            }
            i = (i + 1);
        }
        return yes;
    }
}

slop_option_int howl_cli_aligncli_whole_number(slop_string s) {
    if (!(howl_cli_aligncli_all_digits(s))) {
        return (slop_option_int){.has_value = false};
    } else {
        __auto_type _mv_1847 = std_strlib_parse_int(s);
        if (_mv_1847.is_ok) {
            __auto_type n = _mv_1847.data.ok;
            if (n >= 0) {
                return (slop_option_int){.has_value = 1, .value = n};
            } else {
                return (slop_option_int){.has_value = false};
            }
        } else if (!_mv_1847.is_ok) {
            __auto_type _ = _mv_1847.data.err;
            return (slop_option_int){.has_value = false};
        }
        SLOP_UNREACHABLE();
    }
}

void howl_cli_aligncli_print_fault(slop_arena* a, howl_types_Fault f) {
    __auto_type _mv_1848 = f;
    switch (_mv_1848.tag) {
        case howl_types_Fault_cancelled:
        {
            printf("%s\n", "howl: cancelled");
            break;
        }
        case howl_types_Fault_input_error:
        {
            __auto_type m = _mv_1848.data.input_error;
            printf("%s", "howl: ");
            printf("%.*s\n", (int)(m).len, (m).data);
            break;
        }
        case howl_types_Fault_unavailable:
        {
            __auto_type p = _mv_1848.data.unavailable;
            printf("%s", "howl: ");
            printf("%.*s\n", (int)(howl_select_unavailable_message(a, p)).len, (howl_select_unavailable_message(a, p)).data);
            break;
        }
        case howl_types_Fault_refused:
        {
            __auto_type os = _mv_1848.data.refused;
            printf("%s", "howl: refused (--strict), no report — ");
            printf("%.*s", (int)(int_to_string(a, ((int64_t)(((int64_t)((os).len)))))).len, (int_to_string(a, ((int64_t)(((int64_t)((os).len)))))).data);
            printf("%s\n", " omitted");
            break;
        }
    }
}

int64_t howl_cli_aligncli_fault_exit(howl_types_Fault f) {
    __auto_type _mv_1849 = f;
    switch (_mv_1849.tag) {
        case howl_types_Fault_cancelled:
        {
            return 2;
        }
        case howl_types_Fault_refused:
        {
            __auto_type _ = _mv_1849.data.refused;
            return 2;
        }
        case howl_types_Fault_input_error:
        {
            __auto_type _ = _mv_1849.data.input_error;
            return 3;
        }
        case howl_types_Fault_unavailable:
        {
            __auto_type _ = _mv_1849.data.unavailable;
            return 3;
        }
    }
    SLOP_UNREACHABLE();
}

int64_t howl_cli_aligncli_outcome_exit(howl_types_Outcome o) {
    __auto_type _mv_1850 = howl_types_verdict(o);
    if (_mv_1850 == howl_types_Verdict_verdict_coherent) {
        return 0;
    } else if (_mv_1850 == howl_types_Verdict_verdict_incoherent) {
        return 1;
    } else if (_mv_1850 == howl_types_Verdict_verdict_inconclusive) {
        return 2;
    }
    SLOP_UNREACHABLE();
}

slop_string howl_cli_aligncli_source_of(slop_arena* a, slop_string path, slop_string override) {
    if (string_len(override) > 0) {
        return override;
    } else {
        return howl_cli_aligncli_file_source(a, path);
    }
}

int64_t howl_cli_aligncli_align_main(int64_t argc, uint8_t** argv) {
    {
        #ifdef SLOP_DEBUG
        SLOP_PRE((268435456) > 0, "with-arena size must be positive");
        #endif
        slop_arena _arena_3 = slop_arena_new(268435456);
        #ifdef SLOP_DEBUG
        SLOP_PRE(_arena_3.base != NULL, "arena allocation failed");
        #endif
        slop_arena* arena = &_arena_3;
        if (argc < 5) {
            printf("%s\n", "howl align-check: expected LEFT.ttl RIGHT.ttl MAPPINGS.ttl");
            {
                int64_t _wa_ret = 3;
                slop_arena_free(&_arena_3);
                return _wa_ret;
            }
        } else {
            {
                __auto_type a = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(16777216); _new_arena; });
                __auto_type enc = howl_termstore_new_encoded(a);
                __auto_type left = howl_cli_aligncli_arg(argv, 2);
                __auto_type right = howl_cli_aligncli_arg(argv, 3);
                __auto_type mapping = howl_cli_aligncli_arg(argv, 4);
                __auto_type left_source = SLOP_STR("");
                __auto_type right_source = SLOP_STR("");
                __auto_type mapping_source = SLOP_STR("");
                __auto_type imports = ((slop_list_string){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                __auto_type resolved = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                __auto_type sources = ((slop_list_slop_rdf_rdf_IRI){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                __auto_type mapping_docs = ((slop_list_u8){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
                __auto_type cfg = howl_types_default_config();
                __auto_type limits = howl_default_repair_options();
                uint8_t repair = 0;
                uint8_t report_mode = 0;
                uint8_t timings = 0;
                uint8_t failed = 0;
                int64_t i = 5;
                int64_t k = 0;
                __auto_type start = slop_now_ms();
                while (i < argc) {
                    {
                        __auto_type flag = howl_cli_aligncli_arg(argv, i);
                        int64_t step = 1;
                        if (string_eq(flag, SLOP_STR("--repair"))) {
                            repair = 1;
                        } else if (string_eq(flag, SLOP_STR("--report"))) {
                            report_mode = 1;
                        } else if (string_eq(flag, SLOP_STR("--strict"))) {
                            cfg.strict_profile = 1;
                        } else if (string_eq(flag, SLOP_STR("--timings"))) {
                            timings = 1;
                        } else if ((string_eq(flag, SLOP_STR("-I"))) || (string_eq(flag, SLOP_STR("--left-source"))) || (string_eq(flag, SLOP_STR("--right-source"))) || (string_eq(flag, SLOP_STR("--mapping-source"))) || (string_eq(flag, SLOP_STR("--profile"))) || (string_eq(flag, SLOP_STR("--workers"))) || (string_eq(flag, SLOP_STR("--max-iterations"))) || (string_eq(flag, SLOP_STR("--conflict-calls"))) || (string_eq(flag, SLOP_STR("--conflict-nodes"))) || (string_eq(flag, SLOP_STR("--hitting-nodes"))) || (string_eq(flag, SLOP_STR("--verification-calls")))) {
                            step = 2;
                            if ((i + 1) >= argc) {
                                printf("%s", "howl align-check: missing value for ");
                                printf("%.*s\n", (int)(flag).len, (flag).data);
                                failed = 1;
                            } else {
                                {
                                    __auto_type value = howl_cli_aligncli_arg(argv, (i + 1));
                                    if (string_eq(flag, SLOP_STR("-I"))) {
                                        (void)(({ __auto_type _lst_p = &(imports); __auto_type _item = (value); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                    } else if (string_eq(flag, SLOP_STR("--left-source"))) {
                                        left_source = value;
                                    } else if (string_eq(flag, SLOP_STR("--right-source"))) {
                                        right_source = value;
                                    } else if (string_eq(flag, SLOP_STR("--mapping-source"))) {
                                        mapping_source = value;
                                    } else if (string_eq(flag, SLOP_STR("--profile"))) {
                                        if (string_eq(value, SLOP_STR("auto"))) {
                                            cfg.selection = ((howl_types_ProfileSelection){ .tag = howl_types_ProfileSelection_slop_auto });
                                        } else {
                                            __auto_type _mv_1851 = howl_select_parse_profile(value);
                                            if (_mv_1851.has_value) {
                                                __auto_type p = _mv_1851.value;
                                                cfg.selection = ((howl_types_ProfileSelection){ .tag = howl_types_ProfileSelection_explicit, .data.explicit = p });
                                            } else if (!_mv_1851.has_value) {
                                                printf("%s\n", "howl align-check: unknown profile");
                                                failed = 1;
                                            }
                                        }
                                    } else {
                                        __auto_type _mv_1852 = howl_cli_aligncli_whole_number(value);
                                        if (!_mv_1852.has_value) {
                                            printf("%s", "howl align-check: invalid number for ");
                                            printf("%.*s\n", (int)(flag).len, (flag).data);
                                            failed = 1;
                                        } else if (_mv_1852.has_value) {
                                            __auto_type n = _mv_1852.value;
                                            if (string_eq(flag, SLOP_STR("--workers"))) {
                                                if ((n >= 1) && (n <= 64)) {
                                                    cfg.worker_count = ((int64_t)(n));
                                                } else {
                                                    printf("%s\n", "howl align-check: --workers must be 1..64");
                                                    failed = 1;
                                                }
                                            } else if (string_eq(flag, SLOP_STR("--max-iterations"))) {
                                                if (n <= 10000) {
                                                    cfg.max_iterations = ((int64_t)(n));
                                                } else {
                                                    printf("%s\n", "howl align-check: --max-iterations must be 0..10000");
                                                    failed = 1;
                                                }
                                            } else if (string_eq(flag, SLOP_STR("--conflict-calls"))) {
                                                limits.conflict_calls = n;
                                            } else if (string_eq(flag, SLOP_STR("--conflict-nodes"))) {
                                                limits.conflict_nodes = n;
                                            } else if (string_eq(flag, SLOP_STR("--hitting-nodes"))) {
                                                limits.hitting_nodes = n;
                                            } else if (string_eq(flag, SLOP_STR("--verification-calls"))) {
                                                limits.verification_calls = n;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            printf("%s", "howl align-check: unknown argument: ");
                            printf("%.*s\n", (int)(flag).len, (flag).data);
                            failed = 1;
                        }
                        i = (i + step);
                    }
                }
                {
                    __auto_type ls = howl_cli_aligncli_source_of(arena, left, left_source);
                    __auto_type rs = howl_cli_aligncli_source_of(arena, right, right_source);
                    __auto_type ms = howl_cli_aligncli_source_of(arena, mapping, mapping_source);
                    if (!((howl_aligninput_source_iri_valid(ls) && (howl_aligninput_source_iri_valid(rs) && howl_aligninput_source_iri_valid(ms))))) {
                        printf("%s\n", "howl align-check: every document needs an absolute source IRI");
                        failed = 1;
                    }
                    if (string_eq(ls, rs) || (string_eq(ls, ms) || string_eq(rs, ms))) {
                        printf("%s\n", "howl align-check: source IRIs must be distinct");
                        failed = 1;
                    }
                    if (!(failed)) {
                        if (!(howl_cli_aligncli_parse_into(a, enc, left))) {
                            printf("%s", "howl align-check: cannot parse ");
                            printf("%.*s\n", (int)(left).len, (left).data);
                            failed = 1;
                        }
                        (void)(({ __auto_type _lst_p = &(sources); __auto_type _item = (((slop_rdf_rdf_IRI){.value = ls})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        (void)(({ __auto_type _lst_p = &(mapping_docs); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        howl_termstore_encoded_next_document(a, enc);
                        if (!(howl_cli_aligncli_parse_into(a, enc, right))) {
                            printf("%s", "howl align-check: cannot parse ");
                            printf("%.*s\n", (int)(right).len, (right).data);
                            failed = 1;
                        }
                        (void)(({ __auto_type _lst_p = &(sources); __auto_type _item = (((slop_rdf_rdf_IRI){.value = rs})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        (void)(({ __auto_type _lst_p = &(mapping_docs); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        howl_termstore_encoded_next_document(a, enc);
                        if (!(howl_cli_aligncli_parse_into(a, enc, mapping))) {
                            printf("%s", "howl align-check: cannot parse ");
                            printf("%.*s\n", (int)(mapping).len, (mapping).data);
                            failed = 1;
                        }
                        (void)(({ __auto_type _lst_p = &(sources); __auto_type _item = (((slop_rdf_rdf_IRI){.value = ms})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        (void)(({ __auto_type _lst_p = &(mapping_docs); __auto_type _item = (1); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                    while (k < ((int64_t)((imports).len))) {
                        __auto_type _mv_1853 = ({ __auto_type _lst = imports; size_t _idx = (size_t)k; slop_option_string _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                        if (_mv_1853.has_value) {
                            __auto_type path = _mv_1853.value;
                            if (!(failed)) {
                                {
                                    __auto_type source = howl_cli_aligncli_file_source(arena, path);
                                    __auto_type from = ((int64_t)(((int64_t)(((*enc).triples).len))));
                                    if (!(howl_aligninput_source_iri_valid(source))) {
                                        printf("%s", "howl align-check: cannot resolve import path ");
                                        printf("%.*s\n", (int)(path).len, (path).data);
                                        failed = 1;
                                    }
                                    {
                                        __auto_type _coll = sources;
                                        for (size_t _i = 0; _i < _coll.len; _i++) {
                                            __auto_type other = _coll.data[_i];
                                            if (string_eq(other.value, source)) {
                                                printf("%s\n", "howl align-check: duplicate import source IRI");
                                                failed = 1;
                                            }
                                        }
                                    }
                                    if (!(failed)) {
                                        howl_termstore_encoded_next_document(a, enc);
                                        if (!(howl_cli_aligncli_parse_into(a, enc, path))) {
                                            printf("%s", "howl align-check: cannot parse import ");
                                            printf("%.*s\n", (int)(path).len, (path).data);
                                            failed = 1;
                                        } else {
                                            __auto_type _mv_1854 = howl_cli_aligncli_ontology_iri_from((*enc), from);
                                            if (!_mv_1854.has_value) {
                                                printf("%s\n", "howl align-check: import declares no owl:Ontology IRI");
                                                failed = 1;
                                            } else if (_mv_1854.has_value) {
                                                __auto_type iri = _mv_1854.value;
                                                ({ __auto_type _lst_p = &(resolved); __auto_type _item = (iri); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                            }
                                        }
                                        ({ __auto_type _lst_p = &(sources); __auto_type _item = (((slop_rdf_rdf_IRI){.value = source})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                        ({ __auto_type _lst_p = &(mapping_docs); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                    }
                                }
                            }
                        } else if (!_mv_1853.has_value) {
                        }
                        k = (k + 1);
                    }
                    if (failed) {
                        {
                            int64_t _wa_ret = 3;
                            slop_arena_free(&_arena_3);
                            return _wa_ret;
                        }
                    } else {
                        {
                            __auto_type parsed = slop_now_ms();
                            __auto_type result = howl_align_encoded(arena, (*enc), resolved, sources, mapping_docs, cfg, repair, limits);
                            __auto_type done = slop_now_ms();
                            if (timings) {
                                {
                                    __auto_type peak = howl_cli_aligncli_peak_mb();
                                    fprintf(stderr, "howl align-check: parse_ms=%lld align_ms=%lld peak_mb=%lld\n", (long long)(parsed-start), (long long)(done-parsed), (long long)peak);;
                                }
                            }
                            __auto_type _mv_1855 = result;
                            if (!_mv_1855.is_ok) {
                                __auto_type f = _mv_1855.data.err;
                                howl_cli_aligncli_print_fault(arena, f);
                                {
                                    int64_t _wa_ret = howl_cli_aligncli_fault_exit(f);
                                    slop_arena_free(&_arena_3);
                                    return _wa_ret;
                                }
                            } else if (_mv_1855.is_ok) {
                                __auto_type aligned = _mv_1855.data.ok;
                                {
                                    __auto_type out = aligned.outcome;
                                    __auto_type code = howl_cli_aligncli_outcome_exit(aligned.outcome);
                                    if (report_mode) {
                                        {
                                            __auto_type _coll = howl_report_report_lines(arena, out);
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type line = _coll.data[_i];
                                                printf("%.*s\n", (int)(line).len, (line).data);
                                            }
                                        }
                                    } else {
                                        __auto_type _mv_1856 = howl_types_verdict(out);
                                        if (_mv_1856 == howl_types_Verdict_verdict_coherent) {
                                            printf("%s\n", "howl align-check: coherent");
                                        } else if (_mv_1856 == howl_types_Verdict_verdict_incoherent) {
                                            printf("%s\n", "howl align-check: INCOHERENT");
                                        } else if (_mv_1856 == howl_types_Verdict_verdict_inconclusive) {
                                            printf("%s\n", "howl align-check: INCONCLUSIVE");
                                        }
                                    }
                                    __auto_type _mv_1857 = aligned.repair;
                                    if (_mv_1857.has_value) {
                                        __auto_type search = _mv_1857.value;
                                        {
                                            __auto_type _coll = howl_alignmentreport_alignment_lines(arena, aligned.mappings, search);
                                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                                __auto_type line = _coll.data[_i];
                                                printf("%.*s\n", (int)(line).len, (line).data);
                                            }
                                        }
                                    } else if (!_mv_1857.has_value) {
                                    }
                                    howl_release_outcome(out);
                                    {
                                        int64_t _wa_ret = code;
                                        slop_arena_free(&_arena_3);
                                        return _wa_ret;
                                    }
                                }
                            }
                            SLOP_UNREACHABLE();
                        }
                    }
                }
            }
        }
        slop_arena_free(arena);
    }
}

