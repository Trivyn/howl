#include "../runtime/slop_runtime.h"
#include "slop_kscsat.h"

howl_kscsat_Shard howl_kscsat_new_shard(slop_arena* arena);
howl_kscsat_KStore howl_kscsat_new_store(slop_arena* arena, howl_kscids_KscIds ids, int64_t nshards);
int64_t howl_kscsat_shard_count(howl_kscsat_KStore st);
int64_t howl_kscsat_shard_index(uint32_t k, int64_t n);
howl_kscsat_Shard howl_kscsat_shard_at(howl_kscsat_KStore st, uint32_t k);
slop_list_howl_types_KElem howl_kscsat_store_bots(slop_arena* arena, howl_kscsat_KStore st);
slop_list_howl_kscids_CFact howl_kscsat_store_facts(slop_arena* arena, howl_kscsat_KStore st);
uint8_t howl_kscsat_il_push(slop_arena* arena, slop_map* m, uint32_t k, uint32_t i);
uint8_t howl_kscsat_ri_push(slop_arena* arena, slop_map* m, uint32_t k, uint32_t v, uint32_t i);
howl_types_KElem howl_kscsat_fact_subject(howl_types_KFact f);
uint8_t howl_kscsat_is_safe(howl_kscsat_Base b, howl_types_KElem x);
uint8_t howl_kscsat_holds_coded(howl_kscsat_KStore st, howl_kscids_CFact c);
uint8_t howl_kscsat_store_holds(howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_types_KFact f);
uint8_t howl_kscsat_commit(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_types_KFact f);
slop_option_howl_types_KFact howl_kscsat_commit_coded(slop_arena* arena, howl_kscsat_KStore st, howl_kscids_CFact c);
uint8_t howl_kscsat_file_new(slop_arena* arena, howl_kscsat_KStore st, howl_types_KFact f, howl_kscids_CFact c);
uint8_t howl_kscsat_file_subject(slop_arena* arena, howl_kscsat_Shard sh, howl_types_KFact f, howl_kscids_CFact c);
slop_option_u32 howl_kscsat_other_end(howl_kscsat_KStore st, howl_types_KFact f, howl_kscids_CFact c);
uint8_t howl_kscsat_file_other(slop_arena* arena, howl_kscsat_KStore st, howl_kscids_CFact c, uint32_t h);
slop_option_list_u32 howl_kscsat_id_items(slop_map* m, uint32_t k);
slop_map* howl_kscsat_field_map(howl_kscsat_Shard sh, howl_kscsat_Field fd);
uint8_t howl_kscsat_keyed_by_subject(howl_kscsat_Field fd);
slop_list_howl_types_KFact howl_kscsat_subject_items(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KElem k, slop_list_u32 is);
slop_list_howl_types_KFact howl_kscsat_holder_items(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KElem k, slop_list_u32 is);
slop_list_howl_types_KFact howl_kscsat_field_items(slop_arena* arena, howl_kscsat_KStore st, howl_kscsat_Field fd, howl_types_KElem k);
slop_list_howl_types_KFact howl_kscsat_safe_facts(slop_arena* arena, howl_kscsat_Base b, slop_list_howl_types_KFact xs);
slop_list_howl_types_KFact howl_kscsat_w_items(slop_arena* arena, howl_kscsat_Base b, uint8_t by_subject, howl_types_KElem k, slop_list_howl_types_KFact xs);
slop_list_list_howl_types_KFact howl_kscsat_partners(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_kscsat_Field fd, howl_types_KElem k);
slop_list_howl_types_KFact howl_kscsat_leg_facts(slop_arena* arena, howl_kscids_KscIds ids, uint8_t outward, howl_types_KElem k, uint32_t e, slop_list_u32 is);
slop_list_list_howl_types_KFact howl_kscsat_all_ins(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_types_KElem k);
slop_map* howl_kscsat_side_map(howl_kscsat_Shard sh, uint8_t outward);
slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_every_role(slop_arena* arena, howl_kscids_KscIds ids, uint8_t outward, howl_types_KElem k, howl_kscsat_RoleIds rf);
slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_stored_under(slop_arena* arena, howl_kscids_KscIds ids, uint8_t outward, howl_types_KElem k, howl_kscsat_RoleIds rf, howl_kscsat_Under u);
slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_of_subs(slop_arena* arena, howl_kscids_KscIds ids, uint8_t outward, howl_types_KElem k, howl_kscsat_RoleIds rf, slop_list_howl_types_RoleId subs);
slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_under(slop_arena* arena, howl_kscids_KscIds ids, uint8_t outward, howl_types_KElem k, howl_kscsat_RoleIds rf, howl_kscsat_Under u);
slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_in_store(slop_arena* arena, howl_kscsat_KStore st, uint8_t outward, howl_types_KElem k, slop_option_howl_kscsat_Under under);
slop_list_howl_kscsat_RoleLegs howl_kscsat_push_w_legs(slop_arena* arena, slop_list_howl_kscsat_RoleLegs out, howl_kscsat_Base b, uint8_t outward, howl_types_KElem k, slop_option_howl_kscsat_Under u);
slop_list_howl_kscsat_RoleLegs howl_kscsat_role_legs(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, uint8_t outward, howl_types_KElem k, howl_types_RoleId v);
slop_list_list_u32 howl_kscsat_inst_id_lists(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_types_KElem x);
slop_list_howl_kscsat_Match howl_kscsat_partner_matches(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_types_KElem x, howl_kscpremise_KPartners p);
uint8_t howl_kscsat_emit_concl(howl_kscsat_Deriving* d, howl_ksc_Concl c);
uint8_t howl_kscsat_emit_facts(howl_kscsat_Deriving* d, slop_list_howl_types_KFact xs);
uint8_t howl_kscsat_emit_joins(slop_arena* arena, howl_kscsat_Deriving* d, howl_ksc_JoinRule j, howl_types_KFact f, slop_list_list_howl_types_KFact pss, howl_types_KscAxiom ax);
slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_at(slop_arena* arena, howl_kscsat_Deriving* d, uint8_t outward, howl_types_KElem k, howl_types_RoleId v);
uint8_t howl_kscsat_holds_now(howl_kscsat_Deriving* d, howl_types_KFact f);
slop_list_list_howl_types_KFact howl_kscsat_partners_at(slop_arena* arena, howl_kscsat_Deriving* d, howl_kscsat_Field fd, howl_types_KElem k);
slop_list_howl_kscsat_Match howl_kscsat_matches_at(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KElem x, howl_kscpremise_KPartners p);
howl_types_KscAxiom howl_kscsat_no_axiom(void);
uint8_t howl_kscsat_inst_some_lhs(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_KTerm y, howl_types_RoleId v, howl_types_KName a, howl_types_KName z);
uint8_t howl_kscsat_inst_and_pairs(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KElem x, howl_types_KTerm y, howl_kscpremise_KPartners p);
uint8_t howl_kscsat_inst_equality(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_KTerm y);
uint8_t howl_kscsat_derive_inst(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_KTerm y);
uint8_t howl_kscsat_chain_first(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact fv, howl_types_KElem x, howl_types_RoleId v, howl_types_KElem x1, howl_types_RoleId u, howl_types_RoleId v2, howl_types_RoleId w);
uint8_t howl_kscsat_chain_second(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact fv, howl_types_KElem x, howl_types_RoleId v, howl_types_KElem x1, howl_types_RoleId u, howl_types_RoleId v2, howl_types_RoleId w);
uint8_t howl_kscsat_triple_under(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KElem x, howl_types_RoleId v, howl_types_KElem x1);
uint8_t howl_kscsat_derive_triple(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_RoleId e, howl_types_KElem x1);
uint8_t howl_kscsat_self_chain_first(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_RoleId v, howl_types_RoleId u, howl_types_RoleId v2, howl_types_RoleId w);
uint8_t howl_kscsat_self_chain_second(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_RoleId v, howl_types_RoleId u, howl_types_RoleId v2, howl_types_RoleId w);
uint8_t howl_kscsat_derive_self(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_RoleId v);
slop_list_howl_types_KFact howl_kscsat_derive(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f);
howl_types_RoleId howl_kscsat_ksc_dummy_role(void);
uint8_t howl_kscsat_is_bottom_fact(howl_types_KFact f);
uint8_t howl_kscsat_reaches_bottom(slop_option_howl_kscsat_Base base, howl_types_KFact f);
int64_t howl_kscsat_derive_chunk(slop_arena* wa, slop_arena* ra, howl_kscpremise_KscIndex idx, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, slop_list_howl_types_KFact delta, int64_t lo, int64_t hi, slop_map* out);
int64_t howl_kscsat_round_workers(int64_t workers, int64_t n);
howl_kscsat_Derived howl_kscsat_derive_round(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, slop_list_howl_types_KFact delta, int64_t workers);
howl_kscsat_RoundOut howl_kscsat_ksc_round(slop_arena* arena, slop_arena* na, howl_kscpremise_KscIndex idx, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, slop_list_howl_types_KFact delta, uint8_t stop_at_bottom, uint8_t unsat0, int64_t workers, slop_list_arena_ptr cas);
int64_t howl_kscsat_conclusion_count(howl_kscsat_Derived d);
slop_list_howl_kscids_CFact howl_kscsat_chunk_items(slop_arena* arena, slop_map* out);
howl_kscsat_RoundOut howl_kscsat_commit_serial(slop_arena* arena, slop_arena* na, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_kscsat_Derived d, uint8_t stop_at_bottom, uint8_t unsat0);
uint8_t howl_kscsat_parallel_commit_ok(howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_kscsat_Derived d, uint8_t stop_at_bottom, uint8_t unsat0, int64_t nc);
uint8_t howl_kscsat_any_bottom_coded(howl_kscsat_KStore st, howl_kscsat_Derived d);
int64_t howl_kscsat_committer_of(howl_kscsat_KStore st, uint32_t k, int64_t nc);
uint8_t howl_kscsat_seen_in(howl_kscsat_KStore st, howl_kscids_CFact c);
int64_t howl_kscsat_commit_subjects(slop_arena* ca, slop_arena* sa, howl_kscsat_KStore st, howl_kscsat_Derived d, int64_t k, int64_t nc, slop_map* res);
int64_t howl_kscsat_commit_others(slop_arena* ca, howl_kscsat_KStore st, slop_list_howl_kscsat_Held held, int64_t k, int64_t nc);
howl_kscsat_RoundOut howl_kscsat_commit_parallel(slop_arena* scratch, slop_arena* na, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_kscsat_Derived d, slop_list_arena_ptr cas, int64_t nc, uint8_t unsat0);
slop_arena* howl_kscsat_committer_arena(slop_list_arena_ptr cas, int64_t k);
slop_option_howl_types_KFact howl_kscsat_kept_at(howl_kscsat_Merging* m, int64_t k);
int64_t howl_kscsat_cursor_at(slop_list_int cur, int64_t k);
uint8_t howl_kscsat_take_fact(howl_kscsat_Merging* m, howl_types_KFact f, howl_kscids_CFact c);
uint8_t howl_kscsat_merge_step(howl_kscsat_Merging* m, howl_kscids_CFact c);
howl_kscsat_Merged howl_kscsat_merge_fresh(slop_arena* scratch, slop_arena* na, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_kscsat_Derived d, slop_list_map_ptr ress, int64_t nc, uint8_t unsat0);
howl_kscsat_RunResult howl_kscsat_run_ksc(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscids_KscIds ids, slop_option_howl_kscsat_Base base, slop_list_howl_types_KFact seeds, uint8_t stop_at_bottom, int64_t budget, int64_t cancel, int64_t workers, slop_list_arena_ptr cas);
howl_kscsat_RunResult howl_kscsat_run_result(howl_kscsat_KStore st, int64_t rounds, uint8_t unsat, uint8_t capped, uint8_t cancelled, int64_t facts);
howl_kscsat_RoundOut howl_kscsat_seed_run(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, slop_list_howl_types_KFact seeds);
slop_list_howl_types_KName howl_kscsat_answer_subsumers(slop_arena* arena, howl_kscsat_KStore st, howl_types_KName q);
slop_list_u32 howl_kscsat_queue_ins(howl_kscsat_KStore w, slop_map* seen, slop_map* out, slop_list_u32 work, uint32_t xi);
slop_map* howl_kscsat_backward_closure(slop_arena* arena, howl_kscsat_KStore w, slop_list_howl_types_KElem start);
slop_option_howl_types_ClassAnswer howl_kscsat_class_run(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_Base base, uint8_t g_unsat, int64_t budget, int64_t cancel, howl_types_KName q);
howl_types_ClassAnswer howl_kscsat_shared_answer(slop_arena* arena, howl_kscsat_Base base, uint8_t g_unsat, howl_types_KName q);
slop_option_howl_types_ClassAnswer howl_kscsat_class_answer(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_Base base, uint8_t g_unsat, int64_t budget, int64_t cancel, howl_types_KName q);
slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_classify_renamed(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes, howl_types_ReasonerConfig config);
slop_list_arena_ptr howl_kscsat_ksc_commit_arenas(slop_arena* arena, int64_t w);
howl_types_KscResult howl_kscsat_w_capped(slop_arena* arena, howl_kscsat_RunResult g, howl_kscsat_RunResult w, int64_t n);
slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_phase_w(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscids_KscIds ids, howl_kscsat_RunResult g, slop_list_howl_types_KFact wseeds, slop_list_howl_types_KElem tainted, howl_types_KName thing, slop_list_howl_types_KName classes, howl_types_ReasonerConfig config, slop_list_arena_ptr cas, int64_t n);
slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_classify_phases(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes, howl_types_ReasonerConfig config, slop_list_arena_ptr cas);
slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_ksc_classify(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes, howl_types_ReasonerConfig config);
howl_types_KscResult howl_kscsat_unrename_result(slop_arena* arena, howl_kscnames_KscNames nm, howl_types_KscResult r);
howl_types_KscResult howl_kscsat_g_only(slop_arena* arena, howl_kscsat_RunResult g, uint8_t inconsistent);
howl_types_ClassAnswer howl_kscsat_copy_answer(slop_arena* arena, howl_types_ClassAnswer a);
int64_t howl_kscsat_run_chunk(slop_arena* wa, howl_kscpremise_KscIndex idx, howl_kscsat_Base base, int64_t budget, int64_t cancel, slop_list_howl_types_KName classes, slop_list_int todo, slop_map* out);
slop_list_int howl_kscsat_index_chunk(slop_arena* arena, slop_list_int xs, int64_t lo, int64_t hi);
int64_t howl_kscsat_worker_count_for(int64_t workers, int64_t jobs);
howl_kscsat_Base howl_kscsat_over_w_base(slop_arena* arena, howl_kscsat_RunResult g, howl_kscsat_RunResult w, slop_list_howl_types_KElem tainted);
slop_list_int howl_kscsat_split_safe(slop_arena* arena, howl_kscsat_Base base, slop_list_howl_types_KName classes, slop_map* shared);
howl_kscsat_QRuns howl_kscsat_run_unsafe(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_Base base, int64_t budget, int64_t cancel, slop_list_howl_types_KName classes, slop_list_int todo, int64_t workers);
howl_kscsat_QAnswers howl_kscsat_copy_unsafe(slop_arena* arena, howl_kscsat_QAnswers qa, slop_list_map_ptr outs, int64_t i);
howl_kscsat_QAnswers howl_kscsat_collect_answers(slop_arena* arena, slop_list_howl_types_KName classes, slop_map* shared, slop_list_map_ptr outs, uint8_t complete0);
howl_types_KscResult howl_kscsat_over_w_result(howl_kscsat_RunResult g, howl_kscsat_RunResult w, howl_types_ClassAnswer thing_answer, howl_kscsat_QAnswers qa, int64_t jobs);
slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_answer_over_w(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_RunResult g, howl_kscsat_RunResult w, howl_kscsat_Base base, howl_types_ClassAnswer thing_answer, slop_list_howl_types_KName classes, int64_t budget, int64_t workers, int64_t cancel);
slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_classify_over_w(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_RunResult g, howl_kscsat_RunResult w, slop_list_howl_types_KElem tainted, howl_types_KName thing, slop_list_howl_types_KName classes, int64_t budget, int64_t workers, int64_t cancel);
int64_t howl_kscsat_max_rounds(slop_list_howl_types_ClassAnswer answers);
uint8_t howl_kscsat_answer_holds(howl_types_ClassAnswer a, howl_types_KName b);
slop_list_howl_types_KName howl_kscsat_input_classes(slop_arena* arena, howl_owl2_Signature sig);

typedef struct { slop_arena* wa; slop_arena* ra; howl_kscpremise_KscIndex idx; howl_kscsat_KStore st; slop_option_howl_kscsat_Base base; slop_list_howl_types_KFact delta; int64_t lo; int64_t hi; slop_map* out; } howl_kscsat__lambda_1516_env_t;

static int64_t howl_kscsat__lambda_1516(howl_kscsat__lambda_1516_env_t* _env) { return howl_kscsat_derive_chunk(_env->wa, _env->ra, _env->idx, _env->st, _env->base, _env->delta, _env->lo, _env->hi, _env->out); }

typedef struct { slop_arena* ca; slop_arena* sa; howl_kscsat_KStore st; howl_kscsat_Derived d; int64_t kk; int64_t nc; slop_map* res; } howl_kscsat__lambda_1527_env_t;

static int64_t howl_kscsat__lambda_1527(howl_kscsat__lambda_1527_env_t* _env) { return howl_kscsat_commit_subjects(_env->ca, _env->sa, _env->st, _env->d, _env->kk, _env->nc, _env->res); }

typedef struct { slop_arena* ca; howl_kscsat_KStore st; slop_list_howl_kscsat_Held held; int64_t jj; int64_t nc; } howl_kscsat__lambda_1528_env_t;

static int64_t howl_kscsat__lambda_1528(howl_kscsat__lambda_1528_env_t* _env) { return howl_kscsat_commit_others(_env->ca, _env->st, _env->held, _env->jj, _env->nc); }

typedef struct { slop_arena* wa; howl_kscpremise_KscIndex idx; howl_kscsat_Base base; int64_t budget; int64_t cancel; slop_list_howl_types_KName classes; slop_list_int chunk; slop_map* out; } howl_kscsat__lambda_1559_env_t;

static int64_t howl_kscsat__lambda_1559(howl_kscsat__lambda_1559_env_t* _env) { return howl_kscsat_run_chunk(_env->wa, _env->idx, _env->base, _env->budget, _env->cancel, _env->classes, _env->chunk, _env->out); }

howl_kscsat_Shard howl_kscsat_new_shard(slop_arena* arena) {
    return ((howl_kscsat_Shard){.seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(howl_kscids_CFact, slop_hash_howl_kscids_CFact, slop_eq_howl_kscids_CFact, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .insts = ({ static const slop_map_desc _d = SLOP_MAP_DESC(uint32_t, slop_hash_u32, slop_eq_u32, SLOP_KEY_BITS, howl_kscsat_IdList); slop_map_new_ptr(arena, 0, &_d); }), .noms = ({ static const slop_map_desc _d = SLOP_MAP_DESC(uint32_t, slop_hash_u32, slop_eq_u32, SLOP_KEY_BITS, howl_kscsat_IdList); slop_map_new_ptr(arena, 0, &_d); }), .holders = ({ static const slop_map_desc _d = SLOP_MAP_DESC(uint32_t, slop_hash_u32, slop_eq_u32, SLOP_KEY_BITS, howl_kscsat_IdList); slop_map_new_ptr(arena, 0, &_d); }), .outs = ({ static const slop_map_desc _d = SLOP_MAP_DESC(uint32_t, slop_hash_u32, slop_eq_u32, SLOP_KEY_BITS, howl_kscsat_RoleIds); slop_map_new_ptr(arena, 0, &_d); }), .ins = ({ static const slop_map_desc _d = SLOP_MAP_DESC(uint32_t, slop_hash_u32, slop_eq_u32, SLOP_KEY_BITS, howl_kscsat_RoleIds); slop_map_new_ptr(arena, 0, &_d); }), .noms_at = ({ static const slop_map_desc _d = SLOP_SET_DESC(howl_types_KElem, slop_hash_howl_types_KElem, slop_eq_howl_types_KElem, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); }), .bots = ({ static const slop_map_desc _d = SLOP_SET_DESC(howl_types_KElem, slop_hash_howl_types_KElem, slop_eq_howl_types_KElem, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); })});
}

howl_kscsat_KStore howl_kscsat_new_store(slop_arena* arena, howl_kscids_KscIds ids, int64_t nshards) {
    {
        __auto_type home = howl_kscsat_new_shard(arena);
        __auto_type shards = ((slop_list_howl_kscsat_Shard){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 1;
        (void)(({ __auto_type _lst_p = &(shards); __auto_type _item = (home); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        while (k < nshards) {
            (void)(({ __auto_type _lst_p = &(shards); __auto_type _item = (howl_kscsat_new_shard(arena)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            k = (k + 1);
        }
        return ((howl_kscsat_KStore){.ids = ids, .home = home, .shards = shards});
    }
}

int64_t howl_kscsat_shard_count(howl_kscsat_KStore st) {
    return ((int64_t)(((int64_t)((st.shards).len))));
}

int64_t howl_kscsat_shard_index(uint32_t k, int64_t n) {
    if (n <= 1) {
        return 0;
    } else {
        return (((int64_t)(k)) % n);
    }
}

howl_kscsat_Shard howl_kscsat_shard_at(howl_kscsat_KStore st, uint32_t k) {
    if (howl_kscsat_shard_count(st) <= 1) {
        return st.home;
    } else {
        __auto_type _mv_1462 = ({ __auto_type _lst = st.shards; size_t _idx = (size_t)howl_kscsat_shard_index(k, howl_kscsat_shard_count(st)); slop_option_howl_kscsat_Shard _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1462.has_value) {
            __auto_type sh = _mv_1462.value;
            return sh;
        } else if (!_mv_1462.has_value) {
            return st.home;
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_howl_types_KElem howl_kscsat_store_bots(slop_arena* arena, howl_kscsat_KStore st) {
    {
        __auto_type out = ((slop_list_howl_types_KElem){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.shards;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type sh = _coll.data[_i];
                {
                    __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sh.bots); (slop_list_howl_types_KElem){.data = (howl_types_KElem*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_kscids_CFact howl_kscsat_store_facts(slop_arena* arena, howl_kscsat_KStore st) {
    {
        __auto_type out = ((slop_list_howl_kscids_CFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = st.shards;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type sh = _coll.data[_i];
                {
                    __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sh.seen); (slop_list_howl_kscids_CFact){.data = (howl_kscids_CFact*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (c); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return out;
    }
}

uint8_t howl_kscsat_il_push(slop_arena* arena, slop_map* m, uint32_t k, uint32_t i) {
    {
        __auto_type items = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(m, &(uint32_t){k}); _ptr ? (slop_option_howl_kscsat_IdList){ .has_value = true, .value = *(howl_kscsat_IdList*)_ptr } : (slop_option_howl_kscsat_IdList){ .has_value = false }; }); _mv.has_value ? ({ __auto_type l = _mv.value; l.items; }) : (((slop_list_u32){ .data = NULL, .len = 0, .cap = 0, .arena = arena })); });
        (void)(({ __auto_type _lst_p = &(items); __auto_type _item = (i); slop_arena* _lst_a = (arena); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_a, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        (void)(({ howl_kscsat_IdList _val = ((howl_kscsat_IdList){.items = items}); slop_map_put(arena, m, &(uint32_t){k}, &_val, sizeof(_val)); }));
        return 1;
    }
}

uint8_t howl_kscsat_ri_push(slop_arena* arena, slop_map* m, uint32_t k, uint32_t v, uint32_t i) {
    {
        __auto_type rf = ({ __auto_type _mv = ({ void* _ptr = slop_map_get(m, &(uint32_t){k}); _ptr ? (slop_option_howl_kscsat_RoleIds){ .has_value = true, .value = *(howl_kscsat_RoleIds*)_ptr } : (slop_option_howl_kscsat_RoleIds){ .has_value = false }; }); _mv.has_value ? ({ __auto_type r = _mv.value; r; }) : (({ __auto_type fresh = ((howl_kscsat_RoleIds){.by_role = ({ static const slop_map_desc _d = SLOP_MAP_DESC(uint32_t, slop_hash_u32, slop_eq_u32, SLOP_KEY_BITS, howl_kscsat_IdList); slop_map_new_ptr(arena, 0, &_d); })}); ({ ({ howl_kscsat_RoleIds _val = fresh; slop_map_put(arena, m, &(uint32_t){k}, &_val, sizeof(_val)); }); fresh; }); })); });
        return howl_kscsat_il_push(arena, rf.by_role, v, i);
    }
}

howl_types_KElem howl_kscsat_fact_subject(howl_types_KFact f) {
    __auto_type _mv_1467 = f;
    switch (_mv_1467.tag) {
        case howl_types_KFact_f_inst:
        {
            __auto_type x = _mv_1467.data.f_inst.f0;
            return x;
        }
        case howl_types_KFact_f_triple:
        {
            __auto_type x = _mv_1467.data.f_triple.f0;
            return x;
        }
        case howl_types_KFact_f_self:
        {
            __auto_type x = _mv_1467.data.f_self.f0;
            return x;
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_kscsat_is_safe(howl_kscsat_Base b, howl_types_KElem x) {
    return !(slop_map_has(b.unsafe, &(x)));
}

uint8_t howl_kscsat_holds_coded(howl_kscsat_KStore st, howl_kscids_CFact c) {
    return slop_map_has(howl_kscsat_shard_at(st, c.a).seen, &(c));
}

uint8_t howl_kscsat_store_holds(howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_types_KFact f) {
    {
        __auto_type c = howl_kscids_encode_fact(st.ids, f);
        if (howl_kscsat_holds_coded(st, c)) {
            return 1;
        } else {
            __auto_type _mv_1470 = base;
            if (_mv_1470.has_value) {
                __auto_type b = _mv_1470.value;
                if (howl_kscsat_holds_coded(b.g, c)) {
                    return 1;
                } else {
                    if (howl_kscsat_is_safe(b, howl_kscsat_fact_subject(f))) {
                        return howl_kscsat_holds_coded(b.w, c);
                    } else {
                        return 0;
                    }
                }
            } else if (!_mv_1470.has_value) {
                return 0;
            }
            SLOP_UNREACHABLE();
        }
    }
}

uint8_t howl_kscsat_commit(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_types_KFact f) {
    if (howl_kscsat_store_holds(st, base, f)) {
        return 0;
    } else {
        return howl_kscsat_file_new(arena, st, f, howl_kscids_encode_fact(st.ids, f));
    }
}

slop_option_howl_types_KFact howl_kscsat_commit_coded(slop_arena* arena, howl_kscsat_KStore st, howl_kscids_CFact c) {
    if (howl_kscsat_holds_coded(st, c)) {
        return (slop_option_howl_types_KFact){.has_value = false};
    } else {
        {
            __auto_type f = howl_kscids_decode_fact(st.ids, c);
            howl_kscsat_file_new(arena, st, f, c);
            return (slop_option_howl_types_KFact){.has_value = 1, .value = f};
        }
    }
}

uint8_t howl_kscsat_file_new(slop_arena* arena, howl_kscsat_KStore st, howl_types_KFact f, howl_kscids_CFact c) {
    howl_kscsat_file_subject(arena, howl_kscsat_shard_at(st, c.a), f, c);
    __auto_type _mv_1471 = howl_kscsat_other_end(st, f, c);
    if (_mv_1471.has_value) {
        __auto_type h = _mv_1471.value;
        return howl_kscsat_file_other(arena, st, c, h);
    } else if (!_mv_1471.has_value) {
        return 1;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_kscsat_file_subject(slop_arena* arena, howl_kscsat_Shard sh, howl_types_KFact f, howl_kscids_CFact c) {
    (void)(({ slop_map_put(arena, sh.seen, &(c), NULL, 0); }));
    __auto_type _mv_1473 = f;
    switch (_mv_1473.tag) {
        case howl_types_KFact_f_inst:
        {
            __auto_type x = _mv_1473.data.f_inst.f0;
            __auto_type y = _mv_1473.data.f_inst.f1;
            howl_kscsat_il_push(arena, sh.insts, c.a, c.b);
            if (howl_ksc_ksc_4(x, y)) {
                ({ slop_map_put(arena, sh.bots, &(x), NULL, 0); });
            }
            if (howl_ksc_is_nominal(y)) {
                ({ slop_map_put(arena, sh.noms_at, &(x), NULL, 0); });
                howl_kscsat_il_push(arena, sh.noms, c.a, c.b);
            }
            break;
        }
        case howl_types_KFact_f_triple:
        {
            howl_kscsat_ri_push(arena, sh.outs, c.a, c.b, c.c);
            break;
        }
        case howl_types_KFact_f_self:
        {
            break;
        }
    }
    return 1;
}

slop_option_u32 howl_kscsat_other_end(howl_kscsat_KStore st, howl_types_KFact f, howl_kscids_CFact c) {
    __auto_type _mv_1476 = f;
    switch (_mv_1476.tag) {
        case howl_types_KFact_f_inst:
        {
            __auto_type y = _mv_1476.data.f_inst.f1;
            if (howl_ksc_is_nominal(y)) {
                return (slop_option_u32){.has_value = 1, .value = howl_kscids_elem_id(st.ids, howl_ksc_term_elem(y))};
            } else {
                return (slop_option_u32){.has_value = false};
            }
        }
        case howl_types_KFact_f_triple:
        {
            return (slop_option_u32){.has_value = 1, .value = c.c};
        }
        case howl_types_KFact_f_self:
        {
            return (slop_option_u32){.has_value = false};
        }
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_kscsat_file_other(slop_arena* arena, howl_kscsat_KStore st, howl_kscids_CFact c, uint32_t h) {
    {
        __auto_type sh = howl_kscsat_shard_at(st, h);
        if (c.kind == howl_kscids_triple_kind()) {
            return howl_kscsat_ri_push(arena, sh.ins, h, c.b, c.a);
        } else {
            return howl_kscsat_il_push(arena, sh.holders, h, c.a);
        }
    }
}

slop_option_list_u32 howl_kscsat_id_items(slop_map* m, uint32_t k) {
    __auto_type _mv_1478 = ({ void* _ptr = slop_map_get(m, &(uint32_t){k}); _ptr ? (slop_option_howl_kscsat_IdList){ .has_value = true, .value = *(howl_kscsat_IdList*)_ptr } : (slop_option_howl_kscsat_IdList){ .has_value = false }; });
    if (_mv_1478.has_value) {
        __auto_type l = _mv_1478.value;
        return (slop_option_list_u32){.has_value = 1, .value = l.items};
    } else if (!_mv_1478.has_value) {
        return (slop_option_list_u32){.has_value = false};
    }
    SLOP_UNREACHABLE();
}

slop_map* howl_kscsat_field_map(howl_kscsat_Shard sh, howl_kscsat_Field fd) {
    __auto_type _mv_1479 = fd;
    if (_mv_1479 == howl_kscsat_Field_fd_insts) {
        return sh.insts;
    } else if (_mv_1479 == howl_kscsat_Field_fd_noms) {
        return sh.noms;
    } else if (_mv_1479 == howl_kscsat_Field_fd_holders) {
        return sh.holders;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_kscsat_keyed_by_subject(howl_kscsat_Field fd) {
    __auto_type _mv_1480 = fd;
    if (_mv_1480 == howl_kscsat_Field_fd_insts) {
        return 1;
    } else if (_mv_1480 == howl_kscsat_Field_fd_noms) {
        return 1;
    } else if (_mv_1480 == howl_kscsat_Field_fd_holders) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

slop_list_howl_types_KFact howl_kscsat_subject_items(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KElem k, slop_list_u32 is) {
    {
        __auto_type out = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = is;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = k, .f1 = howl_kscids_id_term(ids, i) } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_howl_types_KFact howl_kscsat_holder_items(slop_arena* arena, howl_kscids_KscIds ids, howl_types_KElem k, slop_list_u32 is) {
    {
        __auto_type out = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1481 = k;
        switch (_mv_1481.tag) {
            case howl_types_KElem_e_ind:
            {
                __auto_type a = _mv_1481.data.e_ind;
                {
                    __auto_type y = howl_types_nominal_term(a);
                    {
                        __auto_type _coll = is;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type i = _coll.data[_i];
                            ({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = howl_kscids_id_elem(ids, i), .f1 = y } })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                break;
            }
            case howl_types_KElem_e_aux:
            {
                __auto_type _ = _mv_1481.data.e_aux;
                break;
            }
            case howl_types_KElem_e_class:
            {
                __auto_type _ = _mv_1481.data.e_class;
                break;
            }
        }
        return out;
    }
}

slop_list_howl_types_KFact howl_kscsat_field_items(slop_arena* arena, howl_kscsat_KStore st, howl_kscsat_Field fd, howl_types_KElem k) {
    {
        __auto_type ki = howl_kscids_elem_id(st.ids, k);
        __auto_type _mv_1482 = howl_kscsat_id_items(howl_kscsat_field_map(howl_kscsat_shard_at(st, ki), fd), ki);
        if (_mv_1482.has_value) {
            __auto_type is = _mv_1482.value;
            if (howl_kscsat_keyed_by_subject(fd)) {
                return howl_kscsat_subject_items(arena, st.ids, k, is);
            } else {
                return howl_kscsat_holder_items(arena, st.ids, k, is);
            }
        } else if (!_mv_1482.has_value) {
            return ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_howl_types_KFact howl_kscsat_safe_facts(slop_arena* arena, howl_kscsat_Base b, slop_list_howl_types_KFact xs) {
    {
        __auto_type out = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = xs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                if (howl_kscsat_is_safe(b, howl_kscsat_fact_subject(f))) {
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

slop_list_howl_types_KFact howl_kscsat_w_items(slop_arena* arena, howl_kscsat_Base b, uint8_t by_subject, howl_types_KElem k, slop_list_howl_types_KFact xs) {
    if (howl_kscsat_is_safe(b, k)) {
        if (by_subject) {
            return xs;
        } else {
            return howl_kscsat_safe_facts(arena, b, xs);
        }
    } else {
        return ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
}

slop_list_list_howl_types_KFact howl_kscsat_partners(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_kscsat_Field fd, howl_types_KElem k) {
    {
        __auto_type out = ((slop_list_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1483 = base;
        if (_mv_1483.has_value) {
            __auto_type b = _mv_1483.value;
            ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_kscsat_field_items(arena, b.g, fd, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            if (howl_kscsat_is_safe(b, k)) {
                ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_kscsat_w_items(arena, b, howl_kscsat_keyed_by_subject(fd), k, howl_kscsat_field_items(arena, b.w, fd, k))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            }
        } else if (!_mv_1483.has_value) {
        }
        (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (howl_kscsat_field_items(arena, st, fd, k)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        return out;
    }
}

slop_list_howl_types_KFact howl_kscsat_leg_facts(slop_arena* arena, howl_kscids_KscIds ids, uint8_t outward, howl_types_KElem k, uint32_t e, slop_list_u32 is) {
    {
        __auto_type out = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type r = howl_kscids_id_role(ids, e);
        {
            __auto_type _coll = is;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((outward) ? ((howl_types_KFact){ .tag = howl_types_KFact_f_triple, .data.f_triple = { .f0 = k, .f1 = r, .f2 = howl_kscids_id_elem(ids, i) } }) : ((howl_types_KFact){ .tag = howl_types_KFact_f_triple, .data.f_triple = { .f0 = howl_kscids_id_elem(ids, i), .f1 = r, .f2 = k } }))); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_list_howl_types_KFact howl_kscsat_all_ins(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_types_KElem k) {
    {
        __auto_type out = ((slop_list_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type _mv_1484 = base;
        if (_mv_1484.has_value) {
            __auto_type b = _mv_1484.value;
            {
                __auto_type _coll = howl_kscsat_legs_in_store(arena, b.g, 0, k, ((slop_option_howl_kscsat_Under){.has_value = false}));
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type lg = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (lg.facts); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            if (howl_kscsat_is_safe(b, k)) {
                {
                    __auto_type _coll = howl_kscsat_legs_in_store(arena, b.w, 0, k, ((slop_option_howl_kscsat_Under){.has_value = false}));
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type lg = _coll.data[_i];
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_kscsat_w_items(arena, b, 0, k, lg.facts)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    }
                }
            }
        } else if (!_mv_1484.has_value) {
        }
        {
            __auto_type _coll = howl_kscsat_legs_in_store(arena, st, 0, k, ((slop_option_howl_kscsat_Under){.has_value = false}));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type lg = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (lg.facts); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_map* howl_kscsat_side_map(howl_kscsat_Shard sh, uint8_t outward) {
    if (outward) {
        return sh.outs;
    } else {
        return sh.ins;
    }
}

slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_every_role(slop_arena* arena, howl_kscids_KscIds ids, uint8_t outward, howl_types_KElem k, howl_kscsat_RoleIds rf) {
    {
        __auto_type out = ((slop_list_howl_kscsat_RoleLegs){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            slop_map* _coll = (slop_map*)rf.by_role;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    uint32_t e = *(uint32_t*)slop_map_key_at(_coll, _i);
                    howl_kscsat_IdList il = *(howl_kscsat_IdList*)slop_map_value_at(_coll, _i);
                    (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_kscsat_RoleLegs){.role = howl_kscids_id_role(ids, e), .facts = howl_kscsat_leg_facts(arena, ids, outward, k, e, il.items)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
            }
        }
        return out;
    }
}

slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_stored_under(slop_arena* arena, howl_kscids_KscIds ids, uint8_t outward, howl_types_KElem k, howl_kscsat_RoleIds rf, howl_kscsat_Under u) {
    {
        __auto_type out = ((slop_list_howl_kscsat_RoleLegs){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            slop_map* _coll = (slop_map*)rf.by_role;
            for (size_t _i = 0; _i < _coll->len; _i++) {
                {
                    uint32_t e = *(uint32_t*)slop_map_key_at(_coll, _i);
                    howl_kscsat_IdList il = *(howl_kscsat_IdList*)slop_map_value_at(_coll, _i);
                    {
                        __auto_type r = howl_kscids_id_role(ids, e);
                        if (howl_kscpremise_role_under(u.idx, r, u.v)) {
                            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_kscsat_RoleLegs){.role = r, .facts = howl_kscsat_leg_facts(arena, ids, outward, k, e, il.items)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_of_subs(slop_arena* arena, howl_kscids_KscIds ids, uint8_t outward, howl_types_KElem k, howl_kscsat_RoleIds rf, slop_list_howl_types_RoleId subs) {
    {
        __auto_type out = ((slop_list_howl_kscsat_RoleLegs){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = subs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                {
                    __auto_type e = howl_kscids_role_id(ids, r);
                    __auto_type _mv_1486 = ({ void* _ptr = slop_map_get(rf.by_role, &(uint32_t){e}); _ptr ? (slop_option_howl_kscsat_IdList){ .has_value = true, .value = *(howl_kscsat_IdList*)_ptr } : (slop_option_howl_kscsat_IdList){ .has_value = false }; });
                    if (_mv_1486.has_value) {
                        __auto_type il = _mv_1486.value;
                        ({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_kscsat_RoleLegs){.role = r, .facts = howl_kscsat_leg_facts(arena, ids, outward, k, e, il.items)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    } else if (!_mv_1486.has_value) {
                    }
                }
            }
        }
        return out;
    }
}

slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_under(slop_arena* arena, howl_kscids_KscIds ids, uint8_t outward, howl_types_KElem k, howl_kscsat_RoleIds rf, howl_kscsat_Under u) {
    {
        __auto_type subs = howl_kscpremise_role_subs(arena, u.idx, u.v);
        if (((int64_t)(rf.by_role)->len) <= ((int64_t)((subs).len))) {
            return howl_kscsat_legs_stored_under(arena, ids, outward, k, rf, u);
        } else {
            return howl_kscsat_legs_of_subs(arena, ids, outward, k, rf, subs);
        }
    }
}

slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_in_store(slop_arena* arena, howl_kscsat_KStore st, uint8_t outward, howl_types_KElem k, slop_option_howl_kscsat_Under under) {
    {
        __auto_type ids = st.ids;
        __auto_type kid = howl_kscids_elem_id(ids, k);
        __auto_type _mv_1488 = ({ void* _ptr = slop_map_get(howl_kscsat_side_map(howl_kscsat_shard_at(st, kid), outward), &(uint32_t){kid}); _ptr ? (slop_option_howl_kscsat_RoleIds){ .has_value = true, .value = *(howl_kscsat_RoleIds*)_ptr } : (slop_option_howl_kscsat_RoleIds){ .has_value = false }; });
        if (!_mv_1488.has_value) {
            return ((slop_list_howl_kscsat_RoleLegs){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        } else if (_mv_1488.has_value) {
            __auto_type rf = _mv_1488.value;
            __auto_type _mv_1489 = under;
            if (!_mv_1489.has_value) {
                return howl_kscsat_legs_every_role(arena, ids, outward, k, rf);
            } else if (_mv_1489.has_value) {
                __auto_type u = _mv_1489.value;
                return howl_kscsat_legs_under(arena, ids, outward, k, rf, u);
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
}

slop_list_howl_kscsat_RoleLegs howl_kscsat_push_w_legs(slop_arena* arena, slop_list_howl_kscsat_RoleLegs out, howl_kscsat_Base b, uint8_t outward, howl_types_KElem k, slop_option_howl_kscsat_Under u) {
    {
        __auto_type o = out;
        {
            __auto_type _coll = howl_kscsat_legs_in_store(arena, b.w, outward, k, u);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type lg = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(o); __auto_type _item = (((howl_kscsat_RoleLegs){.role = lg.role, .facts = howl_kscsat_w_items(arena, b, outward, k, lg.facts)})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return o;
    }
}

slop_list_howl_kscsat_RoleLegs howl_kscsat_role_legs(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, uint8_t outward, howl_types_KElem k, howl_types_RoleId v) {
    {
        __auto_type out = ((slop_list_howl_kscsat_RoleLegs){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type u = (slop_option_howl_kscsat_Under){.has_value = 1, .value = ((howl_kscsat_Under){.idx = idx, .v = v})};
        __auto_type _mv_1490 = base;
        if (_mv_1490.has_value) {
            __auto_type b = _mv_1490.value;
            {
                __auto_type _coll = howl_kscsat_legs_in_store(arena, b.g, outward, k, u);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type lg = _coll.data[_i];
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (lg); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
            if (howl_kscsat_is_safe(b, k)) {
                out = howl_kscsat_push_w_legs(arena, out, b, outward, k, u);
            }
        } else if (!_mv_1490.has_value) {
        }
        {
            __auto_type _coll = howl_kscsat_legs_in_store(arena, st, outward, k, u);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type lg = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (lg); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

slop_list_list_u32 howl_kscsat_inst_id_lists(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_types_KElem x) {
    {
        __auto_type out = ((slop_list_list_u32){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type xi = howl_kscids_elem_id(st.ids, x);
        __auto_type _mv_1491 = base;
        if (_mv_1491.has_value) {
            __auto_type b = _mv_1491.value;
            __auto_type _mv_1492 = howl_kscsat_id_items(howl_kscsat_shard_at(b.g, xi).insts, xi);
            if (_mv_1492.has_value) {
                __auto_type l = _mv_1492.value;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_1492.has_value) {
            }
            if (howl_kscsat_is_safe(b, x)) {
                __auto_type _mv_1493 = howl_kscsat_id_items(howl_kscsat_shard_at(b.w, xi).insts, xi);
                if (_mv_1493.has_value) {
                    __auto_type l = _mv_1493.value;
                    ({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1493.has_value) {
                }
            }
        } else if (!_mv_1491.has_value) {
        }
        __auto_type _mv_1494 = howl_kscsat_id_items(howl_kscsat_shard_at(st, xi).insts, xi);
        if (_mv_1494.has_value) {
            __auto_type l = _mv_1494.value;
            ({ __auto_type _lst_p = &(out); __auto_type _item = (l); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
        } else if (!_mv_1494.has_value) {
        }
        return out;
    }
}

slop_list_howl_kscsat_Match howl_kscsat_partner_matches(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_types_KElem x, howl_kscpremise_KPartners p) {
    {
        __auto_type lists = howl_kscsat_inst_id_lists(arena, st, base, x);
        int64_t nx = 0;
        __auto_type out = ((slop_list_howl_kscsat_Match){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = lists;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type l = _coll.data[_i];
                nx = (nx + ((int64_t)(((int64_t)((l).len)))));
            }
        }
        if (p.count <= nx) {
            {
                slop_map* _coll = (slop_map*)p.by_other;
                for (size_t _i = 0; _i < _coll->len; _i++) {
                    {
                        howl_types_KTerm other = *(howl_types_KTerm*)slop_map_key_at(_coll, _i);
                        howl_kscpremise_KList axl = *(howl_kscpremise_KList*)slop_map_value_at(_coll, _i);
                        if (howl_kscsat_store_holds(st, base, ((howl_types_KFact){ .tag = howl_types_KFact_f_inst, .data.f_inst = { .f0 = x, .f1 = other } }))) {
                            (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_kscsat_Match){.other = other, .axioms = axl})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                        }
                    }
                }
            }
        } else {
            {
                __auto_type _coll = lists;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type l = _coll.data[_i];
                    {
                        __auto_type _coll = l;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type i = _coll.data[_i];
                            {
                                __auto_type z = howl_kscids_id_term(st.ids, i);
                                __auto_type _mv_1496 = ({ void* _ptr = slop_map_get(p.by_other, &(z)); _ptr ? (slop_option_howl_kscpremise_KList){ .has_value = true, .value = *(howl_kscpremise_KList*)_ptr } : (slop_option_howl_kscpremise_KList){ .has_value = false }; });
                                if (_mv_1496.has_value) {
                                    __auto_type axl = _mv_1496.value;
                                    ({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_kscsat_Match){.other = z, .axioms = axl})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                } else if (!_mv_1496.has_value) {
                                }
                            }
                        }
                    }
                }
            }
        }
        return out;
    }
}

uint8_t howl_kscsat_emit_concl(howl_kscsat_Deriving* d, howl_ksc_Concl c) {
    if (c.fires) {
        (void)(({ __auto_type _lst_p = &((*d).out); __auto_type _item = (c.fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
    }
    return 1;
}

uint8_t howl_kscsat_emit_facts(howl_kscsat_Deriving* d, slop_list_howl_types_KFact xs) {
    {
        __auto_type _coll = xs;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type g = _coll.data[_i];
            (void)(({ __auto_type _lst_p = &((*d).out); __auto_type _item = (g); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        }
    }
    return 1;
}

uint8_t howl_kscsat_emit_joins(slop_arena* arena, howl_kscsat_Deriving* d, howl_ksc_JoinRule j, howl_types_KFact f, slop_list_list_howl_types_KFact pss, howl_types_KscAxiom ax) {
    {
        __auto_type _coll = pss;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type ps = _coll.data[_i];
            howl_kscsat_emit_facts(d, howl_ksc_ksc_join(arena, j, f, ps, ax));
        }
    }
    return 1;
}

slop_list_howl_kscsat_RoleLegs howl_kscsat_legs_at(slop_arena* arena, howl_kscsat_Deriving* d, uint8_t outward, howl_types_KElem k, howl_types_RoleId v) {
    return howl_kscsat_role_legs(arena, (*d).idx, (*d).st, (*d).base, outward, k, v);
}

uint8_t howl_kscsat_holds_now(howl_kscsat_Deriving* d, howl_types_KFact f) {
    return howl_kscsat_store_holds((*d).st, (*d).base, f);
}

slop_list_list_howl_types_KFact howl_kscsat_partners_at(slop_arena* arena, howl_kscsat_Deriving* d, howl_kscsat_Field fd, howl_types_KElem k) {
    return howl_kscsat_partners(arena, (*d).st, (*d).base, fd, k);
}

slop_list_howl_kscsat_Match howl_kscsat_matches_at(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KElem x, howl_kscpremise_KPartners p) {
    return howl_kscsat_partner_matches(arena, (*d).st, (*d).base, x, p);
}

howl_types_KscAxiom howl_kscsat_no_axiom(void) {
    return ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_role, .data.k_role = { .f0 = howl_kscsat_ksc_dummy_role(), .f1 = howl_kscsat_ksc_dummy_role() } });
}

uint8_t howl_kscsat_inst_some_lhs(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_KTerm y, howl_types_RoleId v, howl_types_KName a, howl_types_KName z) {
    {
        __auto_type _coll = howl_kscsat_legs_at(arena, d, 0, x, v);
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type lg = _coll.data[_i];
            howl_kscsat_emit_facts(d, howl_ksc_ksc_join(arena, howl_ksc_JoinRule_j7_inst, f, lg.facts, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_some_lhs, .data.k_some_lhs = { .f0 = lg.role, .f1 = a, .f2 = z } })));
        }
    }
    if (howl_kscsat_holds_now(d, ((howl_types_KFact){ .tag = howl_types_KFact_f_self, .data.f_self = { .f0 = x, .f1 = v } }))) {
        howl_kscsat_emit_concl(d, howl_ksc_ksc_8(v, a, z, x, v, x, y));
    }
    return 1;
}

uint8_t howl_kscsat_inst_and_pairs(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KElem x, howl_types_KTerm y, howl_kscpremise_KPartners p) {
    {
        __auto_type _coll = howl_kscsat_matches_at(arena, d, x, p);
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type m = _coll.data[_i];
            {
                __auto_type _coll = m.axioms.items;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ax = _coll.data[_i];
                    __auto_type _mv_1497 = ax;
                    switch (_mv_1497.tag) {
                        case howl_types_KscAxiom_k_and:
                        {
                            __auto_type a = _mv_1497.data.k_and.f0;
                            __auto_type b = _mv_1497.data.k_and.f1;
                            __auto_type z = _mv_1497.data.k_and.f2;
                            if (howl_ksc_is_name(y, a) && howl_types_kterm_eq(m.other, howl_types_name_term(b))) {
                                howl_kscsat_emit_concl(d, howl_ksc_ksc_6(a, b, z, x, y, x, m.other));
                            }
                            if (howl_ksc_is_name(y, b) && howl_types_kterm_eq(m.other, howl_types_name_term(a))) {
                                howl_kscsat_emit_concl(d, howl_ksc_ksc_6(a, b, z, x, m.other, x, y));
                            }
                            break;
                        }
                        case howl_types_KscAxiom_k_sub:
                        {
                            break;
                        }
                        case howl_types_KscAxiom_k_some_lhs:
                        {
                            break;
                        }
                        case howl_types_KscAxiom_k_some_rhs:
                        {
                            break;
                        }
                        case howl_types_KscAxiom_k_self_lhs:
                        {
                            break;
                        }
                        case howl_types_KscAxiom_k_self_rhs:
                        {
                            break;
                        }
                        case howl_types_KscAxiom_k_role:
                        {
                            break;
                        }
                        case howl_types_KscAxiom_k_chain:
                        {
                            break;
                        }
                        case howl_types_KscAxiom_k_range:
                        {
                            break;
                        }
                        case howl_types_KscAxiom_k_role_assert:
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    return 1;
}

uint8_t howl_kscsat_inst_equality(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_KTerm y) {
    {
        __auto_type noax = howl_kscsat_no_axiom();
        if (howl_ksc_is_nominal(y)) {
            howl_kscsat_emit_joins(arena, d, howl_ksc_JoinRule_j27_nom, f, howl_kscsat_partners_at(arena, d, howl_kscsat_Field_fd_insts, x), noax);
            howl_kscsat_emit_joins(arena, d, howl_ksc_JoinRule_j28_nom, f, howl_kscsat_partners_at(arena, d, howl_kscsat_Field_fd_insts, howl_ksc_term_elem(y)), noax);
            howl_kscsat_emit_joins(arena, d, howl_ksc_JoinRule_j29_nom, f, howl_kscsat_all_ins(arena, (*d).st, (*d).base, x), noax);
        }
        howl_kscsat_emit_joins(arena, d, howl_ksc_JoinRule_j27_other, f, howl_kscsat_partners_at(arena, d, howl_kscsat_Field_fd_noms, x), noax);
        if (howl_ksc_is_individual(x)) {
            howl_kscsat_emit_joins(arena, d, howl_ksc_JoinRule_j28_ind, f, howl_kscsat_partners_at(arena, d, howl_kscsat_Field_fd_holders, x), noax);
        }
        return 1;
    }
}

uint8_t howl_kscsat_derive_inst(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_KTerm y) {
    howl_kscsat_emit_concl(d, howl_ksc_ksc_3(x, y));
    __auto_type _mv_1498 = howl_kscpremise_term_bucket((*d).idx, y);
    if (_mv_1498.has_value) {
        __auto_type bucket = _mv_1498.value;
        {
            __auto_type _coll = bucket.items;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1499 = ax;
                switch (_mv_1499.tag) {
                    case howl_types_KscAxiom_k_sub:
                    {
                        __auto_type sy = _mv_1499.data.k_sub.f0;
                        __auto_type sz = _mv_1499.data.k_sub.f1;
                        howl_kscsat_emit_concl(d, howl_ksc_ksc_5(sy, sz, x, y));
                        break;
                    }
                    case howl_types_KscAxiom_k_and:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_some_lhs:
                    {
                        __auto_type v = _mv_1499.data.k_some_lhs.f0;
                        __auto_type a = _mv_1499.data.k_some_lhs.f1;
                        __auto_type z = _mv_1499.data.k_some_lhs.f2;
                        howl_kscsat_inst_some_lhs(arena, d, f, x, y, v, a, z);
                        break;
                    }
                    case howl_types_KscAxiom_k_some_rhs:
                    {
                        __auto_type a = _mv_1499.data.k_some_rhs.f0;
                        __auto_type v = _mv_1499.data.k_some_rhs.f1;
                        __auto_type b = _mv_1499.data.k_some_rhs.f2;
                        __auto_type w = _mv_1499.data.k_some_rhs.f3;
                        howl_kscsat_emit_concl(d, howl_ksc_ksc_9(a, v, b, w, x, y));
                        howl_kscsat_emit_concl(d, howl_ksc_ksc_10(a, v, b, w, x, y));
                        break;
                    }
                    case howl_types_KscAxiom_k_role_assert:
                    {
                        __auto_type a = _mv_1499.data.k_role_assert.f0;
                        __auto_type v = _mv_1499.data.k_role_assert.f1;
                        __auto_type b = _mv_1499.data.k_role_assert.f2;
                        howl_kscsat_emit_concl(d, howl_ksc_ksc_9_assert(a, v, b, x, y));
                        howl_kscsat_emit_concl(d, howl_ksc_ksc_10_assert(a, v, b, x, y));
                        break;
                    }
                    case howl_types_KscAxiom_k_self_rhs:
                    {
                        __auto_type a = _mv_1499.data.k_self_rhs.f0;
                        __auto_type v = _mv_1499.data.k_self_rhs.f1;
                        howl_kscsat_emit_concl(d, howl_ksc_ksc_12(a, v, x, y));
                        break;
                    }
                    case howl_types_KscAxiom_k_self_lhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_role:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_chain:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_range:
                    {
                        break;
                    }
                }
            }
        }
    } else if (!_mv_1498.has_value) {
    }
    __auto_type _mv_1500 = howl_kscpremise_and_partners((*d).idx, y);
    if (_mv_1500.has_value) {
        __auto_type p = _mv_1500.value;
        howl_kscsat_inst_and_pairs(arena, d, x, y, p);
    } else if (!_mv_1500.has_value) {
        1;
    }
    return howl_kscsat_inst_equality(arena, d, f, x, y);
}

uint8_t howl_kscsat_chain_first(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact fv, howl_types_KElem x, howl_types_RoleId v, howl_types_KElem x1, howl_types_RoleId u, howl_types_RoleId v2, howl_types_RoleId w) {
    {
        __auto_type _coll = howl_kscsat_legs_at(arena, d, 1, x1, v2);
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type lg = _coll.data[_i];
            howl_kscsat_emit_facts(d, howl_ksc_ksc_join(arena, howl_ksc_JoinRule_j15_first, fv, lg.facts, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_chain, .data.k_chain = { .f0 = u, .f1 = lg.role, .f2 = w } })));
        }
    }
    if (howl_kscsat_holds_now(d, ((howl_types_KFact){ .tag = howl_types_KFact_f_self, .data.f_self = { .f0 = x1, .f1 = v2 } }))) {
        howl_kscsat_emit_concl(d, howl_ksc_ksc_17(u, v2, w, x, v, x1, x1, v2));
    }
    return 1;
}

uint8_t howl_kscsat_chain_second(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact fv, howl_types_KElem x, howl_types_RoleId v, howl_types_KElem x1, howl_types_RoleId u, howl_types_RoleId v2, howl_types_RoleId w) {
    {
        __auto_type _coll = howl_kscsat_legs_at(arena, d, 0, x, u);
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type lg = _coll.data[_i];
            howl_kscsat_emit_facts(d, howl_ksc_ksc_join(arena, howl_ksc_JoinRule_j15_second, fv, lg.facts, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_chain, .data.k_chain = { .f0 = lg.role, .f1 = v2, .f2 = w } })));
        }
    }
    if (howl_kscsat_holds_now(d, ((howl_types_KFact){ .tag = howl_types_KFact_f_self, .data.f_self = { .f0 = x, .f1 = u } }))) {
        howl_kscsat_emit_concl(d, howl_ksc_ksc_16(u, v2, w, x, u, x, v, x1));
    }
    return 1;
}

uint8_t howl_kscsat_triple_under(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KElem x, howl_types_RoleId v, howl_types_KElem x1) {
    {
        __auto_type fv = ((howl_types_KFact){ .tag = howl_types_KFact_f_triple, .data.f_triple = { .f0 = x, .f1 = v, .f2 = x1 } });
        __auto_type _mv_1501 = howl_kscpremise_role_bucket((*d).idx, v);
        if (_mv_1501.has_value) {
            __auto_type bucket = _mv_1501.value;
            {
                __auto_type _coll = bucket.items;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type ax = _coll.data[_i];
                    __auto_type _mv_1502 = ax;
                    switch (_mv_1502.tag) {
                        case howl_types_KscAxiom_k_some_lhs:
                        {
                            break;
                        }
                        case howl_types_KscAxiom_k_role:
                        {
                            break;
                        }
                        case howl_types_KscAxiom_k_chain:
                        {
                            __auto_type u = _mv_1502.data.k_chain.f0;
                            __auto_type v2 = _mv_1502.data.k_chain.f1;
                            __auto_type w = _mv_1502.data.k_chain.f2;
                            if (howl_types_role_eq(u, v)) {
                                howl_kscsat_chain_first(arena, d, fv, x, v, x1, u, v2, w);
                            }
                            if (howl_types_role_eq(v2, v)) {
                                howl_kscsat_chain_second(arena, d, fv, x, v, x1, u, v2, w);
                            }
                            break;
                        }
                        case howl_types_KscAxiom_k_range:
                        {
                            __auto_type v2 = _mv_1502.data.k_range.f0;
                            __auto_type d2 = _mv_1502.data.k_range.f1;
                            howl_kscsat_emit_concl(d, howl_ksc_ksc_23(v2, d2, x, v, x1));
                            howl_kscsat_emit_concl(d, howl_ksc_ksc_25(v2, d2, x, v, x1));
                            break;
                        }
                        case howl_types_KscAxiom_k_sub:
                        {
                            break;
                        }
                        case howl_types_KscAxiom_k_and:
                        {
                            break;
                        }
                        case howl_types_KscAxiom_k_some_rhs:
                        {
                            break;
                        }
                        case howl_types_KscAxiom_k_self_lhs:
                        {
                            break;
                        }
                        case howl_types_KscAxiom_k_self_rhs:
                        {
                            break;
                        }
                        case howl_types_KscAxiom_k_role_assert:
                        {
                            break;
                        }
                    }
                }
            }
        } else if (!_mv_1501.has_value) {
        }
        __auto_type _mv_1503 = howl_kscpremise_ex_partners((*d).idx, v);
        if (_mv_1503.has_value) {
            __auto_type p = _mv_1503.value;
            {
                __auto_type _coll = howl_kscsat_matches_at(arena, d, x1, p);
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type m = _coll.data[_i];
                    {
                        __auto_type _coll = m.axioms.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type ax = _coll.data[_i];
                            __auto_type _mv_1504 = ax;
                            switch (_mv_1504.tag) {
                                case howl_types_KscAxiom_k_some_lhs:
                                {
                                    __auto_type v2 = _mv_1504.data.k_some_lhs.f0;
                                    __auto_type a = _mv_1504.data.k_some_lhs.f1;
                                    __auto_type z = _mv_1504.data.k_some_lhs.f2;
                                    howl_kscsat_emit_concl(d, howl_ksc_ksc_7(v2, a, z, x, v, x1, x1, m.other));
                                    break;
                                }
                                case howl_types_KscAxiom_k_sub:
                                {
                                    break;
                                }
                                case howl_types_KscAxiom_k_and:
                                {
                                    break;
                                }
                                case howl_types_KscAxiom_k_some_rhs:
                                {
                                    break;
                                }
                                case howl_types_KscAxiom_k_self_lhs:
                                {
                                    break;
                                }
                                case howl_types_KscAxiom_k_self_rhs:
                                {
                                    break;
                                }
                                case howl_types_KscAxiom_k_role:
                                {
                                    break;
                                }
                                case howl_types_KscAxiom_k_chain:
                                {
                                    break;
                                }
                                case howl_types_KscAxiom_k_range:
                                {
                                    break;
                                }
                                case howl_types_KscAxiom_k_role_assert:
                                {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        } else if (!_mv_1503.has_value) {
        }
        return 1;
    }
}

uint8_t howl_kscsat_derive_triple(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_RoleId e, howl_types_KElem x1) {
    howl_kscsat_emit_concl(d, howl_ksc_ksc_2(x, e, x1));
    {
        __auto_type _coll = howl_kscpremise_role_sups(arena, (*d).idx, e);
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type v = _coll.data[_i];
            howl_kscsat_triple_under(arena, d, x, v, x1);
        }
    }
    return howl_kscsat_emit_joins(arena, d, howl_ksc_JoinRule_j29_triple, f, howl_kscsat_partners_at(arena, d, howl_kscsat_Field_fd_noms, x1), howl_kscsat_no_axiom());
}

uint8_t howl_kscsat_self_chain_first(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_RoleId v, howl_types_RoleId u, howl_types_RoleId v2, howl_types_RoleId w) {
    {
        __auto_type _coll = howl_kscsat_legs_at(arena, d, 1, x, v2);
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type lg = _coll.data[_i];
            howl_kscsat_emit_facts(d, howl_ksc_ksc_join(arena, howl_ksc_JoinRule_j16_self, f, lg.facts, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_chain, .data.k_chain = { .f0 = u, .f1 = lg.role, .f2 = w } })));
        }
    }
    if (howl_kscsat_holds_now(d, ((howl_types_KFact){ .tag = howl_types_KFact_f_self, .data.f_self = { .f0 = x, .f1 = v2 } }))) {
        howl_kscsat_emit_concl(d, howl_ksc_ksc_18(u, v2, w, x, v, x, v2));
    }
    return 1;
}

uint8_t howl_kscsat_self_chain_second(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_RoleId v, howl_types_RoleId u, howl_types_RoleId v2, howl_types_RoleId w) {
    {
        __auto_type _coll = howl_kscsat_legs_at(arena, d, 0, x, u);
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type lg = _coll.data[_i];
            howl_kscsat_emit_facts(d, howl_ksc_ksc_join(arena, howl_ksc_JoinRule_j17_self, f, lg.facts, ((howl_types_KscAxiom){ .tag = howl_types_KscAxiom_k_chain, .data.k_chain = { .f0 = lg.role, .f1 = v2, .f2 = w } })));
        }
    }
    if (howl_kscsat_holds_now(d, ((howl_types_KFact){ .tag = howl_types_KFact_f_self, .data.f_self = { .f0 = x, .f1 = u } }))) {
        howl_kscsat_emit_concl(d, howl_ksc_ksc_18(u, v2, w, x, u, x, v));
    }
    return 1;
}

uint8_t howl_kscsat_derive_self(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f, howl_types_KElem x, howl_types_RoleId v) {
    __auto_type _mv_1505 = howl_kscpremise_role_bucket((*d).idx, v);
    if (_mv_1505.has_value) {
        __auto_type bucket = _mv_1505.value;
        {
            __auto_type _coll = bucket.items;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type ax = _coll.data[_i];
                __auto_type _mv_1506 = ax;
                switch (_mv_1506.tag) {
                    case howl_types_KscAxiom_k_some_lhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_self_lhs:
                    {
                        __auto_type v2 = _mv_1506.data.k_self_lhs.f0;
                        __auto_type z = _mv_1506.data.k_self_lhs.f1;
                        howl_kscsat_emit_concl(d, howl_ksc_ksc_11(v2, z, x, v));
                        break;
                    }
                    case howl_types_KscAxiom_k_role:
                    {
                        __auto_type v2 = _mv_1506.data.k_role.f0;
                        __auto_type w = _mv_1506.data.k_role.f1;
                        howl_kscsat_emit_concl(d, howl_ksc_ksc_14(v2, w, x, v));
                        break;
                    }
                    case howl_types_KscAxiom_k_chain:
                    {
                        __auto_type u = _mv_1506.data.k_chain.f0;
                        __auto_type v2 = _mv_1506.data.k_chain.f1;
                        __auto_type w = _mv_1506.data.k_chain.f2;
                        if (howl_types_role_eq(u, v)) {
                            howl_kscsat_self_chain_first(arena, d, f, x, v, u, v2, w);
                        }
                        if (howl_types_role_eq(v2, v)) {
                            howl_kscsat_self_chain_second(arena, d, f, x, v, u, v2, w);
                        }
                        break;
                    }
                    case howl_types_KscAxiom_k_range:
                    {
                        __auto_type v2 = _mv_1506.data.k_range.f0;
                        __auto_type d2 = _mv_1506.data.k_range.f1;
                        howl_kscsat_emit_concl(d, howl_ksc_ksc_24(v2, d2, x, v));
                        howl_kscsat_emit_concl(d, howl_ksc_ksc_26(v2, d2, x, v));
                        break;
                    }
                    case howl_types_KscAxiom_k_sub:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_and:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_some_rhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_self_rhs:
                    {
                        break;
                    }
                    case howl_types_KscAxiom_k_role_assert:
                    {
                        break;
                    }
                }
            }
        }
    } else if (!_mv_1505.has_value) {
    }
    __auto_type _mv_1507 = howl_kscpremise_ex_partners((*d).idx, v);
    if (_mv_1507.has_value) {
        __auto_type p = _mv_1507.value;
        {
            __auto_type _coll = howl_kscsat_matches_at(arena, d, x, p);
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type m = _coll.data[_i];
                {
                    __auto_type _coll = m.axioms.items;
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type ax = _coll.data[_i];
                        __auto_type _mv_1508 = ax;
                        switch (_mv_1508.tag) {
                            case howl_types_KscAxiom_k_some_lhs:
                            {
                                __auto_type v2 = _mv_1508.data.k_some_lhs.f0;
                                __auto_type a = _mv_1508.data.k_some_lhs.f1;
                                __auto_type z = _mv_1508.data.k_some_lhs.f2;
                                howl_kscsat_emit_concl(d, howl_ksc_ksc_8(v2, a, z, x, v, x, m.other));
                                break;
                            }
                            case howl_types_KscAxiom_k_sub:
                            {
                                break;
                            }
                            case howl_types_KscAxiom_k_and:
                            {
                                break;
                            }
                            case howl_types_KscAxiom_k_some_rhs:
                            {
                                break;
                            }
                            case howl_types_KscAxiom_k_self_lhs:
                            {
                                break;
                            }
                            case howl_types_KscAxiom_k_self_rhs:
                            {
                                break;
                            }
                            case howl_types_KscAxiom_k_role:
                            {
                                break;
                            }
                            case howl_types_KscAxiom_k_chain:
                            {
                                break;
                            }
                            case howl_types_KscAxiom_k_range:
                            {
                                break;
                            }
                            case howl_types_KscAxiom_k_role_assert:
                            {
                                break;
                            }
                        }
                    }
                }
            }
        }
    } else if (!_mv_1507.has_value) {
    }
    return 1;
}

slop_list_howl_types_KFact howl_kscsat_derive(slop_arena* arena, howl_kscsat_Deriving* d, howl_types_KFact f) {
    (*d).out = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    __auto_type _mv_1509 = f;
    switch (_mv_1509.tag) {
        case howl_types_KFact_f_inst:
        {
            __auto_type x = _mv_1509.data.f_inst.f0;
            __auto_type y = _mv_1509.data.f_inst.f1;
            howl_kscsat_derive_inst(arena, d, f, x, y);
            break;
        }
        case howl_types_KFact_f_triple:
        {
            __auto_type x = _mv_1509.data.f_triple.f0;
            __auto_type e = _mv_1509.data.f_triple.f1;
            __auto_type x1 = _mv_1509.data.f_triple.f2;
            howl_kscsat_derive_triple(arena, d, f, x, e, x1);
            break;
        }
        case howl_types_KFact_f_self:
        {
            __auto_type x = _mv_1509.data.f_self.f0;
            __auto_type v = _mv_1509.data.f_self.f1;
            howl_kscsat_derive_self(arena, d, f, x, v);
            break;
        }
    }
    return (*d).out;
}

howl_types_RoleId howl_kscsat_ksc_dummy_role(void) {
    return ((howl_types_RoleId){ .tag = howl_types_RoleId_fresh_role, .data.fresh_role = 0 });
}

uint8_t howl_kscsat_is_bottom_fact(howl_types_KFact f) {
    uint8_t _retval = {0};
    __auto_type _mv_1510 = f;
    switch (_mv_1510.tag) {
        case howl_types_KFact_f_inst:
        {
            __auto_type u = _mv_1510.data.f_inst.f0;
            __auto_type z = _mv_1510.data.f_inst.f1;
            _retval = howl_ksc_ksc_4(u, z);
            goto _slop_post;
        }
        case howl_types_KFact_f_triple:
        {
            _retval = 0;
            goto _slop_post;
        }
        case howl_types_KFact_f_self:
        {
            _retval = 0;
            goto _slop_post;
        }
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST((({ __auto_type _mv = f; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case howl_types_KFact_f_inst: { __auto_type u = _mv.data.f_inst.f0; __auto_type z = _mv.data.f_inst.f1; _mr = (_retval == howl_ksc_ksc_4(u, z)); _mm = 1; break; } case howl_types_KFact_f_triple: { _mr = (_retval == 0); _mm = 1; break; } case howl_types_KFact_f_self: { _mr = (_retval == 0); _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; })), "(match f ((f-inst u z) (== $result (ksc-4 u z))) ((f-triple _ _ _) (== $result false)) ((f-self _ _) (== $result false)))");
    return _retval;
}

uint8_t howl_kscsat_reaches_bottom(slop_option_howl_kscsat_Base base, howl_types_KFact f) {
    uint8_t _retval = {0};
    __auto_type _mv_1511 = base;
    if (_mv_1511.has_value) {
        __auto_type b = _mv_1511.value;
        __auto_type _mv_1512 = f;
        switch (_mv_1512.tag) {
            case howl_types_KFact_f_triple:
            {
                __auto_type s = _mv_1512.data.f_triple.f2;
                if (howl_kscsat_is_safe(b, s)) {
                    _retval = slop_map_has(b.botreach, &(s));
                    goto _slop_post;
                } else {
                    _retval = 0;
                    goto _slop_post;
                }
            }
            case howl_types_KFact_f_inst:
            {
                _retval = 0;
                goto _slop_post;
            }
            case howl_types_KFact_f_self:
            {
                _retval = 0;
                goto _slop_post;
            }
        }
        SLOP_UNREACHABLE();
    } else if (!_mv_1511.has_value) {
        _retval = 0;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    return _retval;
}

int64_t howl_kscsat_derive_chunk(slop_arena* wa, slop_arena* ra, howl_kscpremise_KscIndex idx, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, slop_list_howl_types_KFact delta, int64_t lo, int64_t hi, slop_map* out) {
    {
        __auto_type items = ((slop_list_howl_kscids_CFact){ .data = NULL, .len = 0, .cap = 0, .arena = wa });
        __auto_type ids = st.ids;
        __auto_type d = ((howl_kscsat_Deriving*)(({ __auto_type _alloc = (howl_kscsat_Deriving*)slop_arena_alloc(wa, sizeof(howl_kscsat_Deriving)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        int64_t i = lo;
        (*d) = ((howl_kscsat_Deriving){.idx = idx, .st = st, .base = base, .out = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = wa })});
        while (i < hi) {
            __auto_type _mv_1514 = ({ __auto_type _lst = delta; size_t _idx = (size_t)i; slop_option_howl_types_KFact _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1514.has_value) {
                __auto_type f = _mv_1514.value;
                {
                    __auto_type _coll = howl_kscsat_derive(ra, d, f);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        if (!(howl_kscsat_store_holds(st, base, c))) {
                            ({ __auto_type _lst_p = &(items); __auto_type _item = (howl_kscids_encode_fact(ids, c)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                        }
                    }
                }
                howl_saturate_reuse_arena(ra);
            } else if (!_mv_1514.has_value) {
            }
            i = (i + 1);
        }
        (void)(({ howl_kscsat_CFactList _val = ((howl_kscsat_CFactList){.items = items}); slop_map_put(NULL, out, &(int64_t){0}, &_val, sizeof(_val)); }));
        return 0;
    }
}

int64_t howl_kscsat_round_workers(int64_t workers, int64_t n) {
    int64_t _retval = {0};
    _retval = howl_kscsat_worker_count_for(workers, n);
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval >= 1)), "(>= $result 1)");
    return _retval;
}

howl_kscsat_Derived howl_kscsat_derive_round(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, slop_list_howl_types_KFact delta, int64_t workers) {
    {
        __auto_type n = ((int64_t)(((int64_t)((delta).len))));
        __auto_type nw = howl_kscsat_round_workers(workers, ((int64_t)(((int64_t)((delta).len)))));
        __auto_type per = ((((int64_t)(((int64_t)((delta).len)))) + (howl_kscsat_round_workers(workers, ((int64_t)(((int64_t)((delta).len))))) - 1)) / howl_kscsat_round_workers(workers, ((int64_t)(((int64_t)((delta).len))))));
        __auto_type was = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type outs = ((slop_list_map_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type threads = ((slop_list_thread_int_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        while (k < nw) {
            {
                __auto_type wa = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                __auto_type ra = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                __auto_type out = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, howl_kscsat_CFactList); slop_map_new_ptr(wa, 0, &_d); });
                __auto_type lo = (k * per);
                __auto_type hi = (((((k + 1) * per) < n)) ? ((k + 1) * per) : n);
                (void)(({ __auto_type _lst_p = &(was); __auto_type _item = (wa); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(was); __auto_type _item = (ra); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(outs); __auto_type _item = (out); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                if (nw <= 1) {
                    howl_kscsat_derive_chunk(wa, ra, idx, st, base, delta, lo, hi, out);
                } else {
                    (void)(({ __auto_type _lst_p = &(threads); __auto_type _item = (({ slop_arena* _spawn_a = (arena); slop_closure_t _spawn_cl = ({ howl_kscsat__lambda_1516_env_t* howl_kscsat__lambda_1516_env = (howl_kscsat__lambda_1516_env_t*)slop_arena_alloc(_spawn_a, sizeof(howl_kscsat__lambda_1516_env_t)); *howl_kscsat__lambda_1516_env = (howl_kscsat__lambda_1516_env_t){ .wa = wa, .ra = ra, .idx = idx, .st = st, .base = base, .delta = delta, .lo = lo, .hi = hi, .out = out }; (slop_closure_t){ (void*)howl_kscsat__lambda_1516, (void*)howl_kscsat__lambda_1516_env }; }); slop_thread_int* _spawn_th = slop_arena_alloc(_spawn_a, sizeof(slop_thread_int)); *_spawn_th = (slop_thread_int){ .func = _spawn_cl.fn, .env = _spawn_cl.env, .done = false }; slop_thread_start(&_spawn_th->id, (void*)slop_thread_int_entry, (void*)_spawn_th); _spawn_th; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                k = (k + 1);
            }
        }
        {
            __auto_type _coll = threads;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                std_thread_join(t);
            }
        }
        return ((howl_kscsat_Derived){.arenas = was, .outs = outs});
    }
}

howl_kscsat_RoundOut howl_kscsat_ksc_round(slop_arena* arena, slop_arena* na, howl_kscpremise_KscIndex idx, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, slop_list_howl_types_KFact delta, uint8_t stop_at_bottom, uint8_t unsat0, int64_t workers, slop_list_arena_ptr cas) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(65536); _new_arena; });
        __auto_type d = howl_kscsat_derive_round(scratch, idx, st, base, delta, workers);
        __auto_type nc = howl_kscsat_round_workers(((int64_t)(((int64_t)((cas).len)))), howl_kscsat_conclusion_count(d));
        __auto_type ro = ((howl_kscsat_parallel_commit_ok(st, base, d, stop_at_bottom, unsat0, nc)) ? howl_kscsat_commit_parallel(scratch, na, st, base, d, cas, nc, unsat0) : howl_kscsat_commit_serial(arena, na, st, base, d, stop_at_bottom, unsat0));
        {
            __auto_type _coll = d.arenas;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type wa = _coll.data[_i];
                (void)(({ slop_arena_free(wa); free(wa); }));
            }
        }
        (void)(({ slop_arena_free(scratch); free(scratch); }));
        return ro;
    }
}

int64_t howl_kscsat_conclusion_count(howl_kscsat_Derived d) {
    {
        int64_t n = 0;
        {
            __auto_type _coll = d.outs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type out = _coll.data[_i];
                __auto_type _mv_1518 = ({ void* _ptr = slop_map_get(out, &(int64_t){0}); _ptr ? (slop_option_howl_kscsat_CFactList){ .has_value = true, .value = *(howl_kscsat_CFactList*)_ptr } : (slop_option_howl_kscsat_CFactList){ .has_value = false }; });
                if (_mv_1518.has_value) {
                    __auto_type cl = _mv_1518.value;
                    n = (n + ((int64_t)(((int64_t)((cl.items).len)))));
                } else if (!_mv_1518.has_value) {
                }
            }
        }
        return n;
    }
}

slop_list_howl_kscids_CFact howl_kscsat_chunk_items(slop_arena* arena, slop_map* out) {
    __auto_type _mv_1520 = ({ void* _ptr = slop_map_get(out, &(int64_t){0}); _ptr ? (slop_option_howl_kscsat_CFactList){ .has_value = true, .value = *(howl_kscsat_CFactList*)_ptr } : (slop_option_howl_kscsat_CFactList){ .has_value = false }; });
    if (_mv_1520.has_value) {
        __auto_type cl = _mv_1520.value;
        return cl.items;
    } else if (!_mv_1520.has_value) {
        return ((slop_list_howl_kscids_CFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
    }
    SLOP_UNREACHABLE();
}

howl_kscsat_RoundOut howl_kscsat_commit_serial(slop_arena* arena, slop_arena* na, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_kscsat_Derived d, uint8_t stop_at_bottom, uint8_t unsat0) {
    {
        __auto_type next = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = na });
        uint8_t unsat = unsat0;
        int64_t added = 0;
        {
            __auto_type _coll = d.outs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type out = _coll.data[_i];
                {
                    __auto_type _coll = howl_kscsat_chunk_items(arena, out);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        if (!(((stop_at_bottom) ? unsat : 0))) {
                            __auto_type _mv_1521 = howl_kscsat_commit_coded(arena, st, c);
                            if (_mv_1521.has_value) {
                                __auto_type f = _mv_1521.value;
                                ({ __auto_type _lst_p = &(next); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                added = (added + 1);
                                if (howl_kscsat_is_bottom_fact(f)) {
                                    unsat = 1;
                                }
                                if (howl_kscsat_reaches_bottom(base, f)) {
                                    unsat = 1;
                                }
                            } else if (!_mv_1521.has_value) {
                            }
                        }
                    }
                }
            }
        }
        return ((howl_kscsat_RoundOut){.next = next, .added = added, .unsat = unsat});
    }
}

uint8_t howl_kscsat_parallel_commit_ok(howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_kscsat_Derived d, uint8_t stop_at_bottom, uint8_t unsat0, int64_t nc) {
    if (nc <= 1) {
        return 0;
    } else {
        if (!(stop_at_bottom)) {
            return 1;
        } else {
            if (unsat0) {
                return 0;
            } else {
                __auto_type _mv_1522 = base;
                if (_mv_1522.has_value) {
                    __auto_type _ = _mv_1522.value;
                    return 0;
                } else if (!_mv_1522.has_value) {
                    return !(howl_kscsat_any_bottom_coded(st, d));
                }
                SLOP_UNREACHABLE();
            }
        }
    }
}

uint8_t howl_kscsat_any_bottom_coded(howl_kscsat_KStore st, howl_kscsat_Derived d) {
    {
        __auto_type nothing = howl_types_nothing_term();
        uint8_t found = 0;
        {
            __auto_type _coll = d.outs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type out = _coll.data[_i];
                __auto_type _mv_1524 = ({ void* _ptr = slop_map_get(out, &(int64_t){0}); _ptr ? (slop_option_howl_kscsat_CFactList){ .has_value = true, .value = *(howl_kscsat_CFactList*)_ptr } : (slop_option_howl_kscsat_CFactList){ .has_value = false }; });
                if (_mv_1524.has_value) {
                    __auto_type cl = _mv_1524.value;
                    {
                        __auto_type _coll = cl.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            if (c.kind == howl_kscids_inst_kind()) {
                                if (howl_types_kterm_eq(howl_kscids_id_term(st.ids, c.b), nothing)) {
                                    found = 1;
                                }
                            }
                        }
                    }
                } else if (!_mv_1524.has_value) {
                }
            }
        }
        return found;
    }
}

int64_t howl_kscsat_committer_of(howl_kscsat_KStore st, uint32_t k, int64_t nc) {
    return (howl_kscsat_shard_index(k, howl_kscsat_shard_count(st)) % nc);
}

uint8_t howl_kscsat_seen_in(howl_kscsat_KStore st, howl_kscids_CFact c) {
    return slop_map_has(howl_kscsat_shard_at(st, c.a).seen, &(c));
}

int64_t howl_kscsat_commit_subjects(slop_arena* ca, slop_arena* sa, howl_kscsat_KStore st, howl_kscsat_Derived d, int64_t k, int64_t nc, slop_map* res) {
    {
        __auto_type pos = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = sa });
        __auto_type facts = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = sa });
        int64_t p = 0;
        {
            __auto_type _coll = d.outs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type out = _coll.data[_i];
                {
                    __auto_type _coll = howl_kscsat_chunk_items(sa, out);
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type c = _coll.data[_i];
                        if ((howl_kscsat_committer_of(st, c.a, nc) == k) && !(howl_kscsat_seen_in(st, c))) {
                            {
                                __auto_type sh = howl_kscsat_shard_at(st, c.a);
                                __auto_type f = howl_kscids_decode_fact(st.ids, c);
                                howl_kscsat_file_subject(ca, sh, f, c);
                                (void)(({ __auto_type _lst_p = &(pos); __auto_type _item = (p); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                                (void)(({ __auto_type _lst_p = &(facts); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                            }
                        }
                        p = (p + 1);
                    }
                }
            }
        }
        (void)(({ howl_kscsat_Fresh _val = ((howl_kscsat_Fresh){.pos = pos, .facts = facts}); slop_map_put(NULL, res, &(int64_t){0}, &_val, sizeof(_val)); }));
        return 0;
    }
}

int64_t howl_kscsat_commit_others(slop_arena* ca, howl_kscsat_KStore st, slop_list_howl_kscsat_Held held, int64_t k, int64_t nc) {
    {
        __auto_type _coll = held;
        for (size_t _i = 0; _i < _coll.len; _i++) {
            __auto_type h = _coll.data[_i];
            if (howl_kscsat_committer_of(st, h.key, nc) == k) {
                howl_kscsat_file_other(ca, st, h.c, h.key);
            }
        }
    }
    return 0;
}

howl_kscsat_RoundOut howl_kscsat_commit_parallel(slop_arena* scratch, slop_arena* na, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_kscsat_Derived d, slop_list_arena_ptr cas, int64_t nc, uint8_t unsat0) {
    {
        __auto_type sas = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = scratch });
        __auto_type ress = ((slop_list_map_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = scratch });
        __auto_type threads = ((slop_list_thread_int_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = scratch });
        int64_t k = 0;
        while (k < nc) {
            {
                __auto_type sa = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                __auto_type ca = howl_kscsat_committer_arena(cas, k);
                __auto_type res = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, howl_kscsat_Fresh); slop_map_new_ptr(sa, 0, &_d); });
                __auto_type kk = k;
                (void)(({ __auto_type _lst_p = &(sas); __auto_type _item = (sa); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(ress); __auto_type _item = (res); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(threads); __auto_type _item = (({ slop_arena* _spawn_a = (scratch); slop_closure_t _spawn_cl = ({ howl_kscsat__lambda_1527_env_t* howl_kscsat__lambda_1527_env = (howl_kscsat__lambda_1527_env_t*)slop_arena_alloc(_spawn_a, sizeof(howl_kscsat__lambda_1527_env_t)); *howl_kscsat__lambda_1527_env = (howl_kscsat__lambda_1527_env_t){ .ca = ca, .sa = sa, .st = st, .d = d, .kk = kk, .nc = nc, .res = res }; (slop_closure_t){ (void*)howl_kscsat__lambda_1527, (void*)howl_kscsat__lambda_1527_env }; }); slop_thread_int* _spawn_th = slop_arena_alloc(_spawn_a, sizeof(slop_thread_int)); *_spawn_th = (slop_thread_int){ .func = _spawn_cl.fn, .env = _spawn_cl.env, .done = false }; slop_thread_start(&_spawn_th->id, (void*)slop_thread_int_entry, (void*)_spawn_th); _spawn_th; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                k = (k + 1);
            }
        }
        {
            __auto_type _coll = threads;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                std_thread_join(t);
            }
        }
        {
            __auto_type merged = howl_kscsat_merge_fresh(scratch, na, st, base, d, ress, nc, unsat0);
            __auto_type others = ((slop_list_thread_int_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = scratch });
            int64_t j = 0;
            {
                __auto_type _coll = sas;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type sa = _coll.data[_i];
                    (void)(({ slop_arena_free(sa); free(sa); }));
                }
            }
            while (j < nc) {
                {
                    __auto_type ca = howl_kscsat_committer_arena(cas, j);
                    __auto_type held = merged.held;
                    __auto_type jj = j;
                    (void)(({ __auto_type _lst_p = &(others); __auto_type _item = (({ slop_arena* _spawn_a = (scratch); slop_closure_t _spawn_cl = ({ howl_kscsat__lambda_1528_env_t* howl_kscsat__lambda_1528_env = (howl_kscsat__lambda_1528_env_t*)slop_arena_alloc(_spawn_a, sizeof(howl_kscsat__lambda_1528_env_t)); *howl_kscsat__lambda_1528_env = (howl_kscsat__lambda_1528_env_t){ .ca = ca, .st = st, .held = held, .jj = jj, .nc = nc }; (slop_closure_t){ (void*)howl_kscsat__lambda_1528, (void*)howl_kscsat__lambda_1528_env }; }); slop_thread_int* _spawn_th = slop_arena_alloc(_spawn_a, sizeof(slop_thread_int)); *_spawn_th = (slop_thread_int){ .func = _spawn_cl.fn, .env = _spawn_cl.env, .done = false }; slop_thread_start(&_spawn_th->id, (void*)slop_thread_int_entry, (void*)_spawn_th); _spawn_th; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    j = (j + 1);
                }
            }
            {
                __auto_type _coll = others;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type t = _coll.data[_i];
                    std_thread_join(t);
                }
            }
            return merged.out;
        }
    }
}

slop_arena* howl_kscsat_committer_arena(slop_list_arena_ptr cas, int64_t k) {
    __auto_type _mv_1529 = ({ __auto_type _lst = cas; size_t _idx = (size_t)k; slop_option_arena_ptr _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1529.has_value) {
        __auto_type a = _mv_1529.value;
        return a;
    } else if (!_mv_1529.has_value) {
        __auto_type _mv_1530 = ({ __auto_type _lst = cas; size_t _idx = (size_t)0; slop_option_arena_ptr _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (_mv_1530.has_value) {
            __auto_type a = _mv_1530.value;
            return a;
        } else if (!_mv_1530.has_value) {
            return ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(4096); _new_arena; });
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

slop_option_howl_types_KFact howl_kscsat_kept_at(howl_kscsat_Merging* m, int64_t k) {
    __auto_type _mv_1531 = ({ __auto_type _lst = (*m).frs; size_t _idx = (size_t)k; slop_option_howl_kscsat_Fresh _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (!_mv_1531.has_value) {
        return (slop_option_howl_types_KFact){.has_value = false};
    } else if (_mv_1531.has_value) {
        __auto_type fr = _mv_1531.value;
        __auto_type _mv_1532 = ({ __auto_type _lst = (*m).cur; size_t _idx = (size_t)k; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
        if (!_mv_1532.has_value) {
            return (slop_option_howl_types_KFact){.has_value = false};
        } else if (_mv_1532.has_value) {
            __auto_type i = _mv_1532.value;
            __auto_type _mv_1533 = ({ __auto_type _lst = fr.pos; size_t _idx = (size_t)i; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1533.has_value) {
                __auto_type q = _mv_1533.value;
                if (q == (*m).p) {
                    return ({ __auto_type _lst = fr.facts; size_t _idx = (size_t)i; slop_option_howl_types_KFact _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                } else {
                    return (slop_option_howl_types_KFact){.has_value = false};
                }
            } else if (!_mv_1533.has_value) {
                return (slop_option_howl_types_KFact){.has_value = false};
            }
            SLOP_UNREACHABLE();
        }
        SLOP_UNREACHABLE();
    }
    SLOP_UNREACHABLE();
}

int64_t howl_kscsat_cursor_at(slop_list_int cur, int64_t k) {
    __auto_type _mv_1534 = ({ __auto_type _lst = cur; size_t _idx = (size_t)k; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
    if (_mv_1534.has_value) {
        __auto_type i = _mv_1534.value;
        return i;
    } else if (!_mv_1534.has_value) {
        return 0;
    }
    SLOP_UNREACHABLE();
}

uint8_t howl_kscsat_take_fact(howl_kscsat_Merging* m, howl_types_KFact f, howl_kscids_CFact c) {
    (void)(({ __auto_type _lst_p = &((*m).next); __auto_type _item = (f); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
    (*m).added = ((*m).added + 1);
    if (howl_kscsat_is_bottom_fact(f) || howl_kscsat_reaches_bottom((*m).base, f)) {
        (*m).unsat = 1;
    }
    __auto_type _mv_1535 = howl_kscsat_other_end((*m).st, f, c);
    if (_mv_1535.has_value) {
        __auto_type h = _mv_1535.value;
        ({ __auto_type _lst_p = &((*m).held); __auto_type _item = (((howl_kscsat_Held){.key = h, .c = c})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
    } else if (!_mv_1535.has_value) {
    }
    return 1;
}

uint8_t howl_kscsat_merge_step(howl_kscsat_Merging* m, howl_kscids_CFact c) {
    {
        __auto_type k = howl_kscsat_committer_of((*m).st, c.a, (*m).nc);
        __auto_type _mv_1536 = howl_kscsat_kept_at(m, k);
        if (_mv_1536.has_value) {
            __auto_type f = _mv_1536.value;
            howl_kscsat_take_fact(m, f, c);
            ({ __auto_type _set_lst = &((*m).cur); size_t _set_idx = (size_t)(k); __auto_type _set_val = ((howl_kscsat_cursor_at((*m).cur, k) + 1)); bool _set_ok = _set_idx < _set_lst->len; if (_set_ok) { _set_lst->data[_set_idx] = _set_val; } _set_ok; });
        } else if (!_mv_1536.has_value) {
        }
        (*m).p = ((*m).p + 1);
        return 1;
    }
}

howl_kscsat_Merged howl_kscsat_merge_fresh(slop_arena* scratch, slop_arena* na, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, howl_kscsat_Derived d, slop_list_map_ptr ress, int64_t nc, uint8_t unsat0) {
    {
        __auto_type m = ((howl_kscsat_Merging*)(({ __auto_type _alloc = (howl_kscsat_Merging*)slop_arena_alloc(scratch, sizeof(howl_kscsat_Merging)); if (_alloc == NULL) { fprintf(stderr, "SLOP: arena alloc failed at %s:%d\n", __FILE__, __LINE__); abort(); } _alloc; })));
        __auto_type frs = ((slop_list_howl_kscsat_Fresh){ .data = NULL, .len = 0, .cap = 0, .arena = scratch });
        __auto_type cur = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = scratch });
        {
            __auto_type _coll = ress;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type r = _coll.data[_i];
                __auto_type _mv_1538 = ({ void* _ptr = slop_map_get(r, &(int64_t){0}); _ptr ? (slop_option_howl_kscsat_Fresh){ .has_value = true, .value = *(howl_kscsat_Fresh*)_ptr } : (slop_option_howl_kscsat_Fresh){ .has_value = false }; });
                if (_mv_1538.has_value) {
                    __auto_type fr = _mv_1538.value;
                    ({ __auto_type _lst_p = &(frs); __auto_type _item = (fr); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(cur); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1538.has_value) {
                    ({ __auto_type _lst_p = &(frs); __auto_type _item = (((howl_kscsat_Fresh){.pos = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = scratch }), .facts = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = scratch })})); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                    ({ __auto_type _lst_p = &(cur); __auto_type _item = (0); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                }
            }
        }
        (*m) = ((howl_kscsat_Merging){.st = st, .base = base, .nc = nc, .frs = frs, .cur = cur, .next = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = na }), .held = ((slop_list_howl_kscsat_Held){ .data = NULL, .len = 0, .cap = 0, .arena = scratch }), .added = 0, .unsat = unsat0, .p = 0});
        {
            __auto_type _coll = d.outs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type out = _coll.data[_i];
                __auto_type _mv_1540 = ({ void* _ptr = slop_map_get(out, &(int64_t){0}); _ptr ? (slop_option_howl_kscsat_CFactList){ .has_value = true, .value = *(howl_kscsat_CFactList*)_ptr } : (slop_option_howl_kscsat_CFactList){ .has_value = false }; });
                if (_mv_1540.has_value) {
                    __auto_type cl = _mv_1540.value;
                    {
                        __auto_type _coll = cl.items;
                        for (size_t _i = 0; _i < _coll.len; _i++) {
                            __auto_type c = _coll.data[_i];
                            howl_kscsat_merge_step(m, c);
                        }
                    }
                } else if (!_mv_1540.has_value) {
                }
            }
        }
        return ((howl_kscsat_Merged){.out = ((howl_kscsat_RoundOut){.next = (*m).next, .added = (*m).added, .unsat = (*m).unsat}), .held = (*m).held});
    }
}

howl_kscsat_RunResult howl_kscsat_run_ksc(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscids_KscIds ids, slop_option_howl_kscsat_Base base, slop_list_howl_types_KFact seeds, uint8_t stop_at_bottom, int64_t budget, int64_t cancel, int64_t workers, slop_list_arena_ptr cas) {
    SLOP_PRE(((budget >= 0)), "(>= budget 0)");
    howl_kscsat_RunResult _retval = {0};
    {
        __auto_type st = howl_kscsat_new_store(arena, ids, ((int64_t)(((int64_t)((cas).len)))));
        __auto_type seeded = howl_kscsat_seed_run(arena, st, base, seeds);
        __auto_type da = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        __auto_type delta = seeded.next;
        uint8_t unsat = seeded.unsat;
        int64_t facts = seeded.added;
        int64_t rounds = 0;
        uint8_t cancelled = 0;
        uint8_t going = (((int64_t)((seeded.next).len)) > 0);
        if ((stop_at_bottom) ? unsat : 0) {
            delta = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = da });
            going = 0;
        }
        while (going) {
            if (howl_types_cancel_requested(cancel)) {
                cancelled = 1;
            }
            if ((cancelled) ? 1 : (rounds >= budget)) {
                going = 0;
            } else {
                {
                    __auto_type na = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                    __auto_type ro = howl_kscsat_ksc_round(arena, na, idx, st, base, delta, stop_at_bottom, unsat, workers, cas);
                    rounds = (rounds + 1);
                    facts = (facts + ro.added);
                    unsat = ro.unsat;
                    (void)(({ slop_arena_free(da); free(da); }));
                    da = na;
                    delta = ((((stop_at_bottom) ? unsat : 0)) ? ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = da }) : ro.next);
                    going = (((int64_t)((delta).len)) > 0);
                }
            }
        }
        {
            __auto_type capped = (((int64_t)((delta).len)) > 0);
            (void)(({ slop_arena_free(da); free(da); }));
            _retval = howl_kscsat_run_result(st, rounds, unsat, capped, cancelled, facts);
            goto _slop_post;
        }
    }
    _slop_post: ;
    SLOP_POST(((_retval.rounds <= budget)), "(<= (. $result rounds) budget)");
    return _retval;
}

howl_kscsat_RunResult howl_kscsat_run_result(howl_kscsat_KStore st, int64_t rounds, uint8_t unsat, uint8_t capped, uint8_t cancelled, int64_t facts) {
    howl_kscsat_RunResult _retval = {0};
    _retval = ((howl_kscsat_RunResult){.store = st, .rounds = rounds, .unsat = unsat, .capped = capped, .cancelled = cancelled, .facts = facts});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.rounds == rounds)), "(== (. $result rounds) rounds)");
    return _retval;
}

howl_kscsat_RoundOut howl_kscsat_seed_run(slop_arena* arena, howl_kscsat_KStore st, slop_option_howl_kscsat_Base base, slop_list_howl_types_KFact seeds) {
    {
        __auto_type next = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        uint8_t unsat = 0;
        int64_t added = 0;
        {
            __auto_type _coll = seeds;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type s = _coll.data[_i];
                if (howl_kscsat_commit(arena, st, base, s)) {
                    (void)(({ __auto_type _lst_p = &(next); __auto_type _item = (s); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    added = (added + 1);
                    if (howl_kscsat_is_bottom_fact(s)) {
                        unsat = 1;
                    }
                    if (howl_kscsat_reaches_bottom(base, s)) {
                        unsat = 1;
                    }
                }
            }
        }
        return ((howl_kscsat_RoundOut){.next = next, .added = added, .unsat = unsat});
    }
}

slop_list_howl_types_KName howl_kscsat_answer_subsumers(slop_arena* arena, howl_kscsat_KStore st, howl_types_KName q) {
    {
        __auto_type out = ((slop_list_howl_types_KName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = howl_kscsat_field_items(arena, st, howl_kscsat_Field_fd_insts, howl_types_class_elem(q));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type f = _coll.data[_i];
                __auto_type _mv_1541 = f;
                switch (_mv_1541.tag) {
                    case howl_types_KFact_f_inst:
                    {
                        __auto_type y = _mv_1541.data.f_inst.f1;
                        __auto_type _mv_1542 = y;
                        switch (_mv_1542.tag) {
                            case howl_types_KTerm_k_name:
                            {
                                __auto_type n = _mv_1542.data.k_name;
                                ({ __auto_type _lst_p = &(out); __auto_type _item = (howl_kscnormal_copy_kname(arena, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                break;
                            }
                            case howl_types_KTerm_k_nominal:
                            {
                                __auto_type _ = _mv_1542.data.k_nominal;
                                break;
                            }
                        }
                        break;
                    }
                    case howl_types_KFact_f_triple:
                    {
                        break;
                    }
                    case howl_types_KFact_f_self:
                    {
                        break;
                    }
                }
            }
        }
        return out;
    }
}

slop_list_u32 howl_kscsat_queue_ins(howl_kscsat_KStore w, slop_map* seen, slop_map* out, slop_list_u32 work, uint32_t xi) {
    {
        __auto_type ids = w.ids;
        __auto_type wk = work;
        __auto_type _mv_1544 = ({ void* _ptr = slop_map_get(howl_kscsat_shard_at(w, xi).ins, &(uint32_t){xi}); _ptr ? (slop_option_howl_kscsat_RoleIds){ .has_value = true, .value = *(howl_kscsat_RoleIds*)_ptr } : (slop_option_howl_kscsat_RoleIds){ .has_value = false }; });
        if (_mv_1544.has_value) {
            __auto_type rf = _mv_1544.value;
            {
                slop_map* _coll = (slop_map*)rf.by_role;
                for (size_t _i = 0; _i < _coll->len; _i++) {
                    {
                        uint32_t v = *(uint32_t*)slop_map_key_at(_coll, _i);
                        howl_kscsat_IdList il = *(howl_kscsat_IdList*)slop_map_value_at(_coll, _i);
                        {
                            __auto_type _coll = il.items;
                            for (size_t _i = 0; _i < _coll.len; _i++) {
                                __auto_type pi = _coll.data[_i];
                                if (!(slop_map_has(seen, &(uint32_t){pi}))) {
                                    ({ slop_map_put(NULL, seen, &(uint32_t){pi}, NULL, 0); });
                                    ({ howl_types_KElem _key_1547 = (howl_kscids_id_elem(ids, pi)); slop_map_put(NULL, out, &_key_1547, NULL, 0); });
                                    ({ __auto_type _lst_p = &(wk); __auto_type _item = (pi); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                                }
                            }
                        }
                    }
                }
            }
        } else if (!_mv_1544.has_value) {
        }
        return wk;
    }
}

slop_map* howl_kscsat_backward_closure(slop_arena* arena, howl_kscsat_KStore w, slop_list_howl_types_KElem start) {
    {
        __auto_type out = ({ static const slop_map_desc _d = SLOP_SET_DESC(howl_types_KElem, slop_hash_howl_types_KElem, slop_eq_howl_types_KElem, SLOP_KEY_HASHED); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type seen = ({ static const slop_map_desc _d = SLOP_SET_DESC(uint32_t, slop_hash_u32, slop_eq_u32, SLOP_KEY_BITS); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type ids = w.ids;
        __auto_type work = ((slop_list_u32){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = start;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ slop_map_put(NULL, out, &(x), NULL, 0); }));
                {
                    __auto_type xi = howl_kscids_elem_id(ids, x);
                    if (!(slop_map_has(seen, &(uint32_t){xi}))) {
                        (void)(({ slop_map_put(NULL, seen, &(uint32_t){xi}, NULL, 0); }));
                        (void)(({ __auto_type _lst_p = &(work); __auto_type _item = (xi); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        while (i < ((int64_t)(((int64_t)((work).len))))) {
            __auto_type _mv_1551 = ({ __auto_type _lst = work; size_t _idx = (size_t)i; slop_option_u32 _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1551.has_value) {
                __auto_type xi = _mv_1551.value;
                work = howl_kscsat_queue_ins(w, seen, out, work, xi);
            } else if (!_mv_1551.has_value) {
            }
            i = (i + 1);
        }
        return out;
    }
}

slop_option_howl_types_ClassAnswer howl_kscsat_class_run(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_Base base, uint8_t g_unsat, int64_t budget, int64_t cancel, howl_types_KName q) {
    {
        __auto_type scratch = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
        __auto_type qseeds = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = scratch });
        (void)(({ __auto_type _lst_p = &(qseeds); __auto_type _item = (howl_ksc_ksc_q(q).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        {
            __auto_type r = howl_kscsat_run_ksc(scratch, idx, base.g.ids, (slop_option_howl_kscsat_Base){.has_value = 1, .value = base}, qseeds, 1, budget, cancel, 1, ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = scratch }));
            __auto_type ans = ((howl_types_ClassAnswer){.cls = q, .shared = 0, .unsat = ((g_unsat) ? 1 : r.unsat), .subsumers = howl_kscsat_answer_subsumers(arena, r.store, q), .complete = ((r.unsat) ? 1 : !(r.capped)), .rounds = r.rounds, .facts = r.facts});
            (void)(({ slop_arena_free(scratch); free(scratch); }));
            if (r.cancelled) {
                return (slop_option_howl_types_ClassAnswer){.has_value = false};
            } else {
                return (slop_option_howl_types_ClassAnswer){.has_value = 1, .value = ans};
            }
        }
    }
}

howl_types_ClassAnswer howl_kscsat_shared_answer(slop_arena* arena, howl_kscsat_Base base, uint8_t g_unsat, howl_types_KName q) {
    howl_types_ClassAnswer _retval = {0};
    _retval = ((howl_types_ClassAnswer){.cls = q, .shared = 1, .unsat = ((g_unsat) ? 1 : ({ howl_types_KElem _key_1552 = (howl_types_class_elem(q)); slop_map_has(base.botreach, &_key_1552); })), .subsumers = howl_kscsat_answer_subsumers(arena, base.w, q), .complete = 1, .rounds = 0, .facts = 0});
    goto _slop_post;
    _slop_post: ;
    SLOP_POST(((_retval.shared == 1)), "(== (. $result shared) true)");
    SLOP_POST(((_retval.complete == 1)), "(== (. $result complete) true)");
    return _retval;
}

slop_option_howl_types_ClassAnswer howl_kscsat_class_answer(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_Base base, uint8_t g_unsat, int64_t budget, int64_t cancel, howl_types_KName q) {
    if (howl_kscsat_is_safe(base, howl_types_class_elem(q))) {
        return (slop_option_howl_types_ClassAnswer){.has_value = 1, .value = howl_kscsat_shared_answer(arena, base, g_unsat, q)};
    } else {
        return howl_kscsat_class_run(arena, idx, base, g_unsat, budget, cancel, q);
    }
}

slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_classify_renamed(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes, howl_types_ReasonerConfig config) {
    {
        __auto_type cas = howl_kscsat_ksc_commit_arenas(arena, ((int64_t)(config.worker_count)));
        __auto_type r = howl_kscsat_classify_phases(arena, axioms, classes, config, cas);
        {
            __auto_type _coll = cas;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                (void)(({ slop_arena_free(a); free(a); }));
            }
        }
        return r;
    }
}

slop_list_arena_ptr howl_kscsat_ksc_commit_arenas(slop_arena* arena, int64_t w) {
    {
        __auto_type out = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t k = 0;
        if (w > 1) {
            while (k < w) {
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                k = (k + 1);
            }
        }
        return out;
    }
}

howl_types_KscResult howl_kscsat_w_capped(slop_arena* arena, howl_kscsat_RunResult g, howl_kscsat_RunResult w, int64_t n) {
    return ((howl_types_KscResult){.inconsistent = 0, .termination = ((howl_types_Termination){ .tag = howl_types_Termination_resource_limit, .data.resource_limit = n }), .rounds = (g.rounds + w.rounds), .g_rounds = g.rounds, .g_facts = g.facts, .w_rounds = w.rounds, .w_facts = w.facts, .unsafe_count = 0, .answers = ((slop_list_howl_types_ClassAnswer){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
}

slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_phase_w(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscids_KscIds ids, howl_kscsat_RunResult g, slop_list_howl_types_KFact wseeds, slop_list_howl_types_KElem tainted, howl_types_KName thing, slop_list_howl_types_KName classes, howl_types_ReasonerConfig config, slop_list_arena_ptr cas, int64_t n) {
    {
        __auto_type w = howl_kscsat_run_ksc(arena, idx, ids, ((slop_option_howl_kscsat_Base){.has_value = false}), wseeds, 0, (n - g.rounds), config.cancel_ptr, ((int64_t)(config.worker_count)), cas);
        if (w.cancelled) {
            return ((slop_result_howl_types_KscResult_howl_types_Fault){ .is_ok = false, .data.err = ((howl_types_Fault){ .tag = howl_types_Fault_cancelled }) });
        } else if (w.capped) {
            return ((slop_result_howl_types_KscResult_howl_types_Fault){ .is_ok = true, .data.ok = howl_kscsat_w_capped(arena, g, w, n) });
        } else {
            return howl_kscsat_classify_over_w(arena, idx, g, w, tainted, thing, classes, (n - (g.rounds + w.rounds)), ((int64_t)(config.worker_count)), config.cancel_ptr);
        }
    }
}

slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_classify_phases(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes, howl_types_ReasonerConfig config, slop_list_arena_ptr cas) {
    {
        __auto_type idx = howl_kscpremise_build_ksc_index(arena, axioms);
        __auto_type ids = howl_kscids_build_ksc_ids(arena, axioms, classes, idx.individuals);
        __auto_type thing = ((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = ((slop_rdf_rdf_IRI){.value = slop_rdf_vocab_OWL_THING}) });
        __auto_type n = config.max_iterations;
        __auto_type gseeds = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type wseeds = ((slop_list_howl_types_KFact){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type tainted = ((slop_list_howl_types_KElem){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = idx.individuals;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(gseeds); __auto_type _item = (howl_ksc_ksc_1(a).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(wseeds); __auto_type _item = (howl_ksc_ksc_1(a).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(tainted); __auto_type _item = (howl_types_ind_elem(a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        (void)(({ __auto_type _lst_p = &(wseeds); __auto_type _item = (howl_ksc_ksc_q(thing).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(wseeds); __auto_type _item = (howl_ksc_ksc_q(q).fact); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type g = howl_kscsat_run_ksc(arena, idx, ids, ((slop_option_howl_kscsat_Base){.has_value = false}), gseeds, 1, n, config.cancel_ptr, ((int64_t)(config.worker_count)), cas);
            if (g.cancelled) {
                return ((slop_result_howl_types_KscResult_howl_types_Fault){ .is_ok = false, .data.err = ((howl_types_Fault){ .tag = howl_types_Fault_cancelled }) });
            } else if (g.unsat) {
                return ((slop_result_howl_types_KscResult_howl_types_Fault){ .is_ok = true, .data.ok = howl_kscsat_g_only(arena, g, 1) });
            } else if (g.capped) {
                return ((slop_result_howl_types_KscResult_howl_types_Fault){ .is_ok = true, .data.ok = howl_kscsat_g_only(arena, g, 0) });
            } else {
                return howl_kscsat_phase_w(arena, idx, ids, g, wseeds, tainted, thing, classes, config, cas, n);
            }
        }
    }
}

slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_ksc_classify(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes, howl_types_ReasonerConfig config) {
    {
        __auto_type nm = howl_kscnames_build_ksc_names(arena, axioms, classes);
        __auto_type _mv_1553 = howl_kscsat_classify_renamed(arena, howl_kscnames_rename_ksc_axioms(arena, nm, axioms), howl_kscnames_rename_classes(arena, nm, classes), config);
        if (!_mv_1553.is_ok) {
            __auto_type f = _mv_1553.data.err;
            return ((slop_result_howl_types_KscResult_howl_types_Fault){ .is_ok = false, .data.err = f });
        } else if (_mv_1553.is_ok) {
            __auto_type r = _mv_1553.data.ok;
            return ((slop_result_howl_types_KscResult_howl_types_Fault){ .is_ok = true, .data.ok = howl_kscsat_unrename_result(arena, nm, r) });
        }
        SLOP_UNREACHABLE();
    }
}

howl_types_KscResult howl_kscsat_unrename_result(slop_arena* arena, howl_kscnames_KscNames nm, howl_types_KscResult r) {
    {
        __auto_type answers = ((slop_list_howl_types_ClassAnswer){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = r.answers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(answers); __auto_type _item = (howl_kscnames_unrename_answer(arena, nm, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ((howl_types_KscResult){.inconsistent = r.inconsistent, .termination = r.termination, .rounds = r.rounds, .g_rounds = r.g_rounds, .g_facts = r.g_facts, .w_rounds = r.w_rounds, .w_facts = r.w_facts, .unsafe_count = r.unsafe_count, .answers = answers});
    }
}

howl_types_KscResult howl_kscsat_g_only(slop_arena* arena, howl_kscsat_RunResult g, uint8_t inconsistent) {
    return ((howl_types_KscResult){.inconsistent = inconsistent, .termination = ((inconsistent) ? ((howl_types_Termination){ .tag = howl_types_Termination_fixpoint }) : ((howl_types_Termination){ .tag = howl_types_Termination_resource_limit, .data.resource_limit = g.rounds })), .rounds = g.rounds, .g_rounds = g.rounds, .g_facts = g.facts, .w_rounds = 0, .w_facts = 0, .unsafe_count = 0, .answers = ((slop_list_howl_types_ClassAnswer){ .data = NULL, .len = 0, .cap = 0, .arena = arena })});
}

howl_types_ClassAnswer howl_kscsat_copy_answer(slop_arena* arena, howl_types_ClassAnswer a) {
    {
        __auto_type subs = ((slop_list_howl_types_KName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = a.subsumers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type n = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(subs); __auto_type _item = (howl_kscnormal_copy_kname(arena, n)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return ((howl_types_ClassAnswer){.cls = howl_kscnormal_copy_kname(arena, a.cls), .shared = a.shared, .unsat = a.unsat, .subsumers = subs, .complete = a.complete, .rounds = a.rounds, .facts = a.facts});
    }
}

int64_t howl_kscsat_run_chunk(slop_arena* wa, howl_kscpremise_KscIndex idx, howl_kscsat_Base base, int64_t budget, int64_t cancel, slop_list_howl_types_KName classes, slop_list_int todo, slop_map* out) {
    {
        uint8_t cancelled = 0;
        {
            __auto_type _coll = todo;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type i = _coll.data[_i];
                if (howl_types_cancel_requested(cancel)) {
                    cancelled = 1;
                }
                if (!(cancelled)) {
                    __auto_type _mv_1554 = ({ __auto_type _lst = classes; size_t _idx = (size_t)i; slop_option_howl_types_KName _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
                    if (_mv_1554.has_value) {
                        __auto_type q = _mv_1554.value;
                        __auto_type _mv_1555 = howl_kscsat_class_run(wa, idx, base, 0, budget, cancel, q);
                        if (_mv_1555.has_value) {
                            __auto_type a = _mv_1555.value;
                            ({ howl_types_ClassAnswer _val = a; slop_map_put(NULL, out, &(int64_t){i}, &_val, sizeof(_val)); });
                        } else if (!_mv_1555.has_value) {
                            cancelled = 1;
                        }
                    } else if (!_mv_1554.has_value) {
                    }
                }
            }
        }
        if (cancelled) {
            return 1;
        } else {
            return 0;
        }
    }
}

slop_list_int howl_kscsat_index_chunk(slop_arena* arena, slop_list_int xs, int64_t lo, int64_t hi) {
    {
        __auto_type out = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t j = lo;
        while (j < hi) {
            __auto_type _mv_1557 = ({ __auto_type _lst = xs; size_t _idx = (size_t)j; slop_option_int _r = {0}; if (_idx < _lst.len) { _r.has_value = true; _r.value = _lst.data[_idx]; } else { _r.has_value = false; } _r; });
            if (_mv_1557.has_value) {
                __auto_type x = _mv_1557.value;
                ({ __auto_type _lst_p = &(out); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
            } else if (!_mv_1557.has_value) {
            }
            j = (j + 1);
        }
        return out;
    }
}

int64_t howl_kscsat_worker_count_for(int64_t workers, int64_t jobs) {
    int64_t _retval = {0};
    if (workers < 1) {
        _retval = 1;
        goto _slop_post;
    } else {
        if (workers > jobs) {
            if (jobs > 0) {
                _retval = jobs;
                goto _slop_post;
            } else {
                _retval = 1;
                goto _slop_post;
            }
        } else {
            _retval = workers;
            goto _slop_post;
        }
    }
    _slop_post: ;
    SLOP_POST(((_retval >= 1)), "(>= $result 1)");
    return _retval;
}

howl_kscsat_Base howl_kscsat_over_w_base(slop_arena* arena, howl_kscsat_RunResult g, howl_kscsat_RunResult w, slop_list_howl_types_KElem tainted) {
    {
        __auto_type taint = ((slop_list_howl_types_KElem){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = tainted;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type x = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(taint); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        {
            __auto_type _coll = w.store.shards;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type sh = _coll.data[_i];
                {
                    __auto_type _coll = ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sh.noms_at); (slop_list_howl_types_KElem){.data = (howl_types_KElem*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; });
                    for (size_t _i = 0; _i < _coll.len; _i++) {
                        __auto_type x = _coll.data[_i];
                        (void)(({ __auto_type _lst_p = &(taint); __auto_type _item = (x); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                    }
                }
            }
        }
        return ((howl_kscsat_Base){.g = g.store, .w = w.store, .unsafe = howl_kscsat_backward_closure(arena, w.store, taint), .botreach = howl_kscsat_backward_closure(arena, w.store, howl_kscsat_store_bots(arena, w.store))});
    }
}

slop_list_int howl_kscsat_split_safe(slop_arena* arena, howl_kscsat_Base base, slop_list_howl_types_KName classes, slop_map* shared) {
    {
        __auto_type todo = ((slop_list_int){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t i = 0;
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                if (howl_kscsat_is_safe(base, howl_types_class_elem(q))) {
                    (void)(({ howl_types_ClassAnswer _val = howl_kscsat_shared_answer(arena, base, 0, q); slop_map_put(NULL, shared, &(int64_t){i}, &_val, sizeof(_val)); }));
                } else {
                    (void)(({ __auto_type _lst_p = &(todo); __auto_type _item = (i); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                i = (i + 1);
            }
        }
        return todo;
    }
}

howl_kscsat_QRuns howl_kscsat_run_unsafe(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_Base base, int64_t budget, int64_t cancel, slop_list_howl_types_KName classes, slop_list_int todo, int64_t workers) {
    {
        __auto_type nw = howl_kscsat_worker_count_for(workers, ((int64_t)(((int64_t)((todo).len)))));
        __auto_type per = ((((int64_t)(((int64_t)((todo).len)))) + (nw - 1)) / nw);
        __auto_type was = ((slop_list_arena_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type outs = ((slop_list_map_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        __auto_type threads = ((slop_list_thread_int_ptr){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        int64_t cancelled = 0;
        int64_t k = 0;
        while (k < nw) {
            {
                __auto_type wa = ({ slop_arena* _new_arena = malloc(sizeof(slop_arena)); if (!_new_arena) { fprintf(stderr, "SLOP: arena-new malloc failed\n"); abort(); } *_new_arena = slop_arena_new(1048576); _new_arena; });
                __auto_type out = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, howl_types_ClassAnswer); slop_map_new_ptr(wa, 0, &_d); });
                __auto_type chunk = howl_kscsat_index_chunk(wa, todo, (k * per), ((k + 1) * per));
                (void)(({ __auto_type _lst_p = &(was); __auto_type _item = (wa); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                (void)(({ __auto_type _lst_p = &(outs); __auto_type _item = (out); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                if (nw <= 1) {
                    cancelled = (cancelled + howl_kscsat_run_chunk(wa, idx, base, budget, cancel, classes, chunk, out));
                } else {
                    (void)(({ __auto_type _lst_p = &(threads); __auto_type _item = (({ slop_arena* _spawn_a = (arena); slop_closure_t _spawn_cl = ({ howl_kscsat__lambda_1559_env_t* howl_kscsat__lambda_1559_env = (howl_kscsat__lambda_1559_env_t*)slop_arena_alloc(_spawn_a, sizeof(howl_kscsat__lambda_1559_env_t)); *howl_kscsat__lambda_1559_env = (howl_kscsat__lambda_1559_env_t){ .wa = wa, .idx = idx, .base = base, .budget = budget, .cancel = cancel, .classes = classes, .chunk = chunk, .out = out }; (slop_closure_t){ (void*)howl_kscsat__lambda_1559, (void*)howl_kscsat__lambda_1559_env }; }); slop_thread_int* _spawn_th = slop_arena_alloc(_spawn_a, sizeof(slop_thread_int)); *_spawn_th = (slop_thread_int){ .func = _spawn_cl.fn, .env = _spawn_cl.env, .done = false }; slop_thread_start(&_spawn_th->id, (void*)slop_thread_int_entry, (void*)_spawn_th); _spawn_th; })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
                }
                k = (k + 1);
            }
        }
        {
            __auto_type _coll = threads;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type t = _coll.data[_i];
                cancelled = (cancelled + std_thread_join(t));
            }
        }
        return ((howl_kscsat_QRuns){.was = was, .outs = outs, .cancelled = cancelled});
    }
}

howl_kscsat_QAnswers howl_kscsat_copy_unsafe(slop_arena* arena, howl_kscsat_QAnswers qa, slop_list_map_ptr outs, int64_t i) {
    {
        __auto_type r = qa;
        {
            __auto_type _coll = outs;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type out = _coll.data[_i];
                __auto_type _mv_1561 = ({ void* _ptr = slop_map_get(out, &(int64_t){i}); _ptr ? (slop_option_howl_types_ClassAnswer){ .has_value = true, .value = *(howl_types_ClassAnswer*)_ptr } : (slop_option_howl_types_ClassAnswer){ .has_value = false }; });
                if (_mv_1561.has_value) {
                    __auto_type a = _mv_1561.value;
                    if (!(a.complete)) {
                        r.complete = 0;
                    }
                    ({ __auto_type _lst_p = &(r.answers); __auto_type _item = (howl_kscsat_copy_answer(arena, a)); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1561.has_value) {
                }
            }
        }
        return r;
    }
}

howl_kscsat_QAnswers howl_kscsat_collect_answers(slop_arena* arena, slop_list_howl_types_KName classes, slop_map* shared, slop_list_map_ptr outs, uint8_t complete0) {
    {
        __auto_type qa = ((howl_kscsat_QAnswers){.answers = ((slop_list_howl_types_ClassAnswer){ .data = NULL, .len = 0, .cap = 0, .arena = arena }), .complete = complete0});
        int64_t i = 0;
        {
            __auto_type _coll = classes;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type q = _coll.data[_i];
                __auto_type _mv_1563 = ({ void* _ptr = slop_map_get(shared, &(int64_t){i}); _ptr ? (slop_option_howl_types_ClassAnswer){ .has_value = true, .value = *(howl_types_ClassAnswer*)_ptr } : (slop_option_howl_types_ClassAnswer){ .has_value = false }; });
                if (_mv_1563.has_value) {
                    __auto_type a = _mv_1563.value;
                    ({ __auto_type _lst_p = &(qa.answers); __auto_type _item = (a); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; });
                } else if (!_mv_1563.has_value) {
                    qa = howl_kscsat_copy_unsafe(arena, qa, outs, i);
                }
                i = (i + 1);
            }
        }
        return qa;
    }
}

howl_types_KscResult howl_kscsat_over_w_result(howl_kscsat_RunResult g, howl_kscsat_RunResult w, howl_types_ClassAnswer thing_answer, howl_kscsat_QAnswers qa, int64_t jobs) {
    {
        __auto_type qrounds = (((thing_answer.rounds > howl_kscsat_max_rounds(qa.answers))) ? thing_answer.rounds : howl_kscsat_max_rounds(qa.answers));
        __auto_type total = (g.rounds + (w.rounds + qrounds));
        return ((howl_types_KscResult){.inconsistent = thing_answer.unsat, .termination = ((qa.complete) ? ((howl_types_Termination){ .tag = howl_types_Termination_fixpoint }) : ((howl_types_Termination){ .tag = howl_types_Termination_resource_limit, .data.resource_limit = total })), .rounds = total, .g_rounds = g.rounds, .g_facts = g.facts, .w_rounds = w.rounds, .w_facts = w.facts, .unsafe_count = jobs, .answers = qa.answers});
    }
}

slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_answer_over_w(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_RunResult g, howl_kscsat_RunResult w, howl_kscsat_Base base, howl_types_ClassAnswer thing_answer, slop_list_howl_types_KName classes, int64_t budget, int64_t workers, int64_t cancel) {
    {
        __auto_type shared = ({ static const slop_map_desc _d = SLOP_MAP_DESC(int64_t, slop_hash_int, slop_eq_int, SLOP_KEY_BITS, howl_types_ClassAnswer); slop_map_new_ptr(arena, 0, &_d); });
        __auto_type todo = howl_kscsat_split_safe(arena, base, classes, shared);
        __auto_type runs = howl_kscsat_run_unsafe(arena, idx, base, budget, cancel, classes, todo, workers);
        __auto_type qa = howl_kscsat_collect_answers(arena, classes, shared, runs.outs, thing_answer.complete);
        {
            __auto_type _coll = runs.was;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type wa = _coll.data[_i];
                (void)(({ slop_arena_free(wa); free(wa); }));
            }
        }
        if (runs.cancelled > 0) {
            return ((slop_result_howl_types_KscResult_howl_types_Fault){ .is_ok = false, .data.err = ((howl_types_Fault){ .tag = howl_types_Fault_cancelled }) });
        } else {
            return ((slop_result_howl_types_KscResult_howl_types_Fault){ .is_ok = true, .data.ok = howl_kscsat_over_w_result(g, w, thing_answer, qa, ((int64_t)(((int64_t)((todo).len))))) });
        }
    }
}

slop_result_howl_types_KscResult_howl_types_Fault howl_kscsat_classify_over_w(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscsat_RunResult g, howl_kscsat_RunResult w, slop_list_howl_types_KElem tainted, howl_types_KName thing, slop_list_howl_types_KName classes, int64_t budget, int64_t workers, int64_t cancel) {
    {
        __auto_type base = howl_kscsat_over_w_base(arena, g, w, tainted);
        __auto_type _mv_1564 = howl_kscsat_class_answer(arena, idx, base, 0, budget, cancel, thing);
        if (!_mv_1564.has_value) {
            return ((slop_result_howl_types_KscResult_howl_types_Fault){ .is_ok = false, .data.err = ((howl_types_Fault){ .tag = howl_types_Fault_cancelled }) });
        } else if (_mv_1564.has_value) {
            __auto_type thing_answer = _mv_1564.value;
            return howl_kscsat_answer_over_w(arena, idx, g, w, base, thing_answer, classes, budget, workers, cancel);
        }
        SLOP_UNREACHABLE();
    }
}

int64_t howl_kscsat_max_rounds(slop_list_howl_types_ClassAnswer answers) {
    {
        int64_t m = 0;
        {
            __auto_type _coll = answers;
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type a = _coll.data[_i];
                if (a.rounds > m) {
                    m = a.rounds;
                }
            }
        }
        return m;
    }
}

uint8_t howl_kscsat_answer_holds(howl_types_ClassAnswer a, howl_types_KName b) {
    if (a.unsat) {
        return 1;
    } else {
        {
            uint8_t found = 0;
            {
                __auto_type _coll = a.subsumers;
                for (size_t _i = 0; _i < _coll.len; _i++) {
                    __auto_type n = _coll.data[_i];
                    if (howl_types_kname_eq(n, b)) {
                        found = 1;
                    }
                }
            }
            return found;
        }
    }
}

slop_list_howl_types_KName howl_kscsat_input_classes(slop_arena* arena, howl_owl2_Signature sig) {
    {
        __auto_type out = ((slop_list_howl_types_KName){ .data = NULL, .len = 0, .cap = 0, .arena = arena });
        {
            __auto_type _coll = howl_canon_sort_iris(arena, ({ slop_set_elements_result _r = slop_set_elements_raw(arena, sig.classes); (slop_list_slop_rdf_rdf_IRI){.data = (slop_rdf_rdf_IRI*)_r.data, .len = _r.len, .cap = _r.cap, .arena = arena}; }));
            for (size_t _i = 0; _i < _coll.len; _i++) {
                __auto_type c = _coll.data[_i];
                (void)(({ __auto_type _lst_p = &(out); __auto_type _item = (((howl_types_KName){ .tag = howl_types_KName_k_class, .data.k_class = c })); if (_lst_p->len >= _lst_p->cap) { _lst_p->data = (__typeof__(_lst_p->data))slop_list_grow_raw(_lst_p->arena, _lst_p->data, &_lst_p->cap, _lst_p->len, sizeof(*_lst_p->data)); } _lst_p->data[_lst_p->len++] = _item; (void)0; }));
            }
        }
        return out;
    }
}

