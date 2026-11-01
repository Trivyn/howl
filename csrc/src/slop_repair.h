#ifndef SLOP_repair_H
#define SLOP_repair_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_canon.h"

typedef struct howl_repair_Check howl_repair_Check;
typedef struct howl_repair_Checked howl_repair_Checked;
typedef struct howl_repair_SearchOptions howl_repair_SearchOptions;
typedef struct howl_repair_MappingSet howl_repair_MappingSet;
typedef struct howl_repair_Candidate howl_repair_Candidate;
typedef struct howl_repair_Phase howl_repair_Phase;
typedef struct howl_repair_SearchCounts howl_repair_SearchCounts;
typedef struct howl_repair_SearchResult howl_repair_SearchResult;
typedef struct howl_repair_Cached howl_repair_Cached;
typedef struct howl_repair_SearchState howl_repair_SearchState;

typedef enum {
    howl_repair_CandidateReason_candidate_budget,
    howl_repair_CandidateReason_candidate_unknown
} howl_repair_CandidateReason;

#ifndef SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Omission, slop_list_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_FAULT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_FAULT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Fault, slop_option_howl_types_Fault)
#endif

struct howl_repair_Check {
    howl_types_Verdict verdict;
    uint8_t complete;
    slop_list_howl_types_Omission omissions;
    howl_types_Termination termination;
};
typedef struct howl_repair_Check howl_repair_Check;

#ifndef SLOP_OPTION_HOWL_REPAIR_CHECK_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_CHECK_DEFINED
SLOP_OPTION_DEFINE(howl_repair_Check, slop_option_howl_repair_Check)
#endif

typedef enum {
    howl_repair_Checked_checked,
    howl_repair_Checked_check_fault
} howl_repair_Checked_tag;

struct howl_repair_Checked {
    howl_repair_Checked_tag tag;
    union {
        howl_repair_Check checked;
        howl_types_Fault check_fault;
    } data;
};
typedef struct howl_repair_Checked howl_repair_Checked;

#ifndef SLOP_OPTION_HOWL_REPAIR_CHECKED_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_CHECKED_DEFINED
SLOP_OPTION_DEFINE(howl_repair_Checked, slop_option_howl_repair_Checked)
#endif

struct howl_repair_SearchOptions {
    int64_t conflict_calls;
    int64_t conflict_nodes;
    int64_t hitting_nodes;
    int64_t verification_calls;
    int64_t cancel;
};
typedef struct howl_repair_SearchOptions howl_repair_SearchOptions;

#ifndef SLOP_OPTION_HOWL_REPAIR_SEARCHOPTIONS_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_SEARCHOPTIONS_DEFINED
SLOP_OPTION_DEFINE(howl_repair_SearchOptions, slop_option_howl_repair_SearchOptions)
#endif

struct howl_repair_MappingSet {
    slop_list_int items;
};
typedef struct howl_repair_MappingSet howl_repair_MappingSet;

#ifndef SLOP_OPTION_HOWL_REPAIR_MAPPINGSET_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_MAPPINGSET_DEFINED
SLOP_OPTION_DEFINE(howl_repair_MappingSet, slop_option_howl_repair_MappingSet)
#endif

#ifndef SLOP_LIST_HOWL_REPAIR_MAPPINGSET_DEFINED
#define SLOP_LIST_HOWL_REPAIR_MAPPINGSET_DEFINED
#define SLOP_LIST_HOWL_REPAIR_MAPPINGSET_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_repair_MappingSet, slop_list_howl_repair_MappingSet)
#endif

struct howl_repair_Candidate {
    slop_list_int removed;
    howl_repair_CandidateReason reason;
};
typedef struct howl_repair_Candidate howl_repair_Candidate;

#ifndef SLOP_OPTION_HOWL_REPAIR_CANDIDATE_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_CANDIDATE_DEFINED
SLOP_OPTION_DEFINE(howl_repair_Candidate, slop_option_howl_repair_Candidate)
#endif

#ifndef SLOP_LIST_HOWL_REPAIR_CANDIDATE_DEFINED
#define SLOP_LIST_HOWL_REPAIR_CANDIDATE_DEFINED
#define SLOP_LIST_HOWL_REPAIR_CANDIDATE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_repair_Candidate, slop_list_howl_repair_Candidate)
#endif

struct howl_repair_Phase {
    uint8_t exhausted;
    uint8_t capped;
    uint8_t unresolved;
};
typedef struct howl_repair_Phase howl_repair_Phase;

#ifndef SLOP_OPTION_HOWL_REPAIR_PHASE_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_PHASE_DEFINED
SLOP_OPTION_DEFINE(howl_repair_Phase, slop_option_howl_repair_Phase)
#endif

struct howl_repair_SearchCounts {
    int64_t preflight_calls;
    int64_t conflict_calls;
    int64_t conflict_nodes;
    int64_t hitting_nodes;
    int64_t verification_calls;
    int64_t cache_hits;
};
typedef struct howl_repair_SearchCounts howl_repair_SearchCounts;

#ifndef SLOP_OPTION_HOWL_REPAIR_SEARCHCOUNTS_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_SEARCHCOUNTS_DEFINED
SLOP_OPTION_DEFINE(howl_repair_SearchCounts, slop_option_howl_repair_SearchCounts)
#endif

struct howl_repair_SearchResult {
    slop_list_howl_repair_MappingSet verified;
    slop_list_howl_repair_Candidate candidates;
    slop_list_howl_repair_MappingSet conflicts;
    howl_repair_Phase conflict_phase;
    howl_repair_Phase hitting_phase;
    howl_repair_Phase verification_phase;
    slop_list_howl_types_Omission omissions;
    howl_repair_SearchCounts counts;
    uint8_t already_coherent;
    uint8_t unrepairable;
    uint8_t complete;
};
typedef struct howl_repair_SearchResult howl_repair_SearchResult;

#ifndef SLOP_OPTION_HOWL_REPAIR_SEARCHRESULT_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_SEARCHRESULT_DEFINED
SLOP_OPTION_DEFINE(howl_repair_SearchResult, slop_option_howl_repair_SearchResult)
#endif

struct howl_repair_Cached {
    slop_list_int removed;
    howl_repair_Check answer;
};
typedef struct howl_repair_Cached howl_repair_Cached;

#ifndef SLOP_OPTION_HOWL_REPAIR_CACHED_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_CACHED_DEFINED
SLOP_OPTION_DEFINE(howl_repair_Cached, slop_option_howl_repair_Cached)
#endif

#ifndef SLOP_LIST_HOWL_REPAIR_CACHED_DEFINED
#define SLOP_LIST_HOWL_REPAIR_CACHED_DEFINED
#define SLOP_LIST_HOWL_REPAIR_CACHED_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_repair_Cached, slop_list_howl_repair_Cached)
#endif

struct howl_repair_SearchState {
    slop_list_howl_repair_Cached cache;
    slop_list_howl_types_Omission omissions;
    howl_repair_SearchCounts counts;
    slop_option_howl_types_Fault fault;
    howl_repair_Phase conflict_phase;
    howl_repair_Phase hitting_phase;
    howl_repair_Phase verification_phase;
};
typedef struct howl_repair_SearchState howl_repair_SearchState;

#ifndef SLOP_OPTION_HOWL_REPAIR_SEARCHSTATE_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_SEARCHSTATE_DEFINED
SLOP_OPTION_DEFINE(howl_repair_SearchState, slop_option_howl_repair_SearchState)
#endif

#ifndef SLOP_RESULT_HOWL_REPAIR_SEARCHRESULT_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_REPAIR_SEARCHRESULT_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_repair_SearchResult ok; howl_types_Fault err; } data; } slop_result_howl_repair_SearchResult_howl_types_Fault;
#endif

slop_string howl_repair_candidate_reason_text(howl_repair_CandidateReason reason);
howl_repair_SearchOptions howl_repair_default_search_options(void);
uint8_t howl_repair_has_index(slop_list_int xs, int64_t x);
uint8_t howl_repair_subset(slop_list_int xs, slop_list_int ys);
int64_t howl_repair_index_at(slop_list_int xs, int64_t i);
slop_list_int howl_repair_indices(slop_arena* arena, int64_t n);
slop_list_int howl_repair_set_add(slop_arena* arena, slop_list_int xs, int64_t x);
slop_list_int howl_repair_remove_index(slop_arena* arena, slop_list_int xs, int64_t x);
slop_list_int howl_repair_difference(slop_arena* arena, slop_list_int xs, slop_list_int ys);
int64_t howl_repair_set_cmp(slop_list_int xs, slop_list_int ys);
slop_list_int howl_repair_set_at(slop_arena* arena, slop_list_howl_repair_MappingSet xs, int64_t i);
uint8_t howl_repair_known_set(slop_list_howl_repair_MappingSet xs, slop_list_int items);
void howl_repair_keep_set(slop_list_howl_repair_MappingSet* xs, slop_list_int items);
slop_list_howl_repair_MappingSet howl_repair_sorted_sets(slop_arena* arena, slop_list_howl_repair_MappingSet xs);
howl_repair_Phase howl_repair_empty_phase(void);
uint8_t howl_repair_phase_complete(howl_repair_Phase p);
uint8_t howl_repair_stopped(howl_repair_SearchState* st, howl_repair_SearchOptions options);
uint8_t howl_repair_good(howl_repair_Check c);
uint8_t howl_repair_bad(howl_repair_Check c);
slop_option_howl_repair_Check howl_repair_ask(slop_arena* arena, howl_repair_SearchState* st, howl_repair_SearchOptions options, int64_t phase, slop_list_int removed, slop_closure_t check);
slop_option_howl_repair_MappingSet howl_repair_find_conflict(slop_list_howl_repair_MappingSet known, slop_list_int retained);
slop_option_howl_repair_MappingSet howl_repair_shrink(slop_arena* arena, howl_repair_SearchState* st, howl_repair_SearchOptions options, slop_list_int all, slop_list_int retained, slop_closure_t check);
void howl_repair_canonical_next(slop_arena* arena, slop_list_howl_repair_MappingSet* queue, int64_t pos, howl_repair_SearchOptions options);
slop_list_howl_repair_MappingSet howl_repair_enumerate_conflicts(slop_arena* arena, howl_repair_SearchState* st, howl_repair_SearchOptions options, slop_list_int all, slop_closure_t check);
uint8_t howl_repair_intersects(slop_list_int a, slop_list_int b);
slop_option_howl_repair_MappingSet howl_repair_unhit(slop_list_howl_repair_MappingSet conflicts, slop_list_int removed);
uint8_t howl_repair_minimal_hit(slop_list_howl_repair_MappingSet conflicts, slop_list_int removed);
slop_list_howl_repair_MappingSet howl_repair_enumerate_hits(slop_arena* arena, howl_repair_SearchState* st, howl_repair_SearchOptions options, slop_list_howl_repair_MappingSet conflicts);
void howl_repair_keep_candidate(slop_list_howl_repair_Candidate* out, slop_list_int removed, howl_repair_CandidateReason reason);
void howl_repair_verify_candidate(slop_arena* arena, howl_repair_SearchState* st, howl_repair_SearchOptions options, slop_list_int removed, slop_list_howl_repair_MappingSet* verified, slop_list_howl_repair_Candidate* candidates, slop_closure_t check);
slop_list_howl_types_Omission howl_repair_sorted_omissions(slop_arena* arena, slop_list_howl_types_Omission xs);
slop_list_howl_repair_Candidate howl_repair_sorted_candidates(slop_arena* arena, slop_list_howl_repair_Candidate xs, slop_list_howl_repair_MappingSet verified);
slop_result_howl_repair_SearchResult_howl_types_Fault howl_repair_search(slop_arena* arena, int64_t n, howl_repair_Check initial, howl_repair_SearchOptions options, slop_closure_t check);

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_HOWL_REPAIR_CHECK_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_CHECK_DEFINED
SLOP_OPTION_DEFINE(howl_repair_Check, slop_option_howl_repair_Check)
#endif

#ifndef SLOP_OPTION_HOWL_REPAIR_CHECKED_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_CHECKED_DEFINED
SLOP_OPTION_DEFINE(howl_repair_Checked, slop_option_howl_repair_Checked)
#endif

#ifndef SLOP_OPTION_HOWL_REPAIR_SEARCHOPTIONS_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_SEARCHOPTIONS_DEFINED
SLOP_OPTION_DEFINE(howl_repair_SearchOptions, slop_option_howl_repair_SearchOptions)
#endif

#ifndef SLOP_OPTION_HOWL_REPAIR_MAPPINGSET_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_MAPPINGSET_DEFINED
SLOP_OPTION_DEFINE(howl_repair_MappingSet, slop_option_howl_repair_MappingSet)
#endif

#ifndef SLOP_OPTION_HOWL_REPAIR_CANDIDATE_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_CANDIDATE_DEFINED
SLOP_OPTION_DEFINE(howl_repair_Candidate, slop_option_howl_repair_Candidate)
#endif

#ifndef SLOP_OPTION_HOWL_REPAIR_PHASE_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_PHASE_DEFINED
SLOP_OPTION_DEFINE(howl_repair_Phase, slop_option_howl_repair_Phase)
#endif

#ifndef SLOP_OPTION_HOWL_REPAIR_SEARCHCOUNTS_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_SEARCHCOUNTS_DEFINED
SLOP_OPTION_DEFINE(howl_repair_SearchCounts, slop_option_howl_repair_SearchCounts)
#endif

#ifndef SLOP_OPTION_HOWL_REPAIR_SEARCHRESULT_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_SEARCHRESULT_DEFINED
SLOP_OPTION_DEFINE(howl_repair_SearchResult, slop_option_howl_repair_SearchResult)
#endif

#ifndef SLOP_OPTION_HOWL_REPAIR_CACHED_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_CACHED_DEFINED
SLOP_OPTION_DEFINE(howl_repair_Cached, slop_option_howl_repair_Cached)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_FAULT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_FAULT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Fault, slop_option_howl_types_Fault)
#endif

#ifndef SLOP_OPTION_HOWL_REPAIR_SEARCHSTATE_DEFINED
#define SLOP_OPTION_HOWL_REPAIR_SEARCHSTATE_DEFINED
SLOP_OPTION_DEFINE(howl_repair_SearchState, slop_option_howl_repair_SearchState)
#endif


#endif
