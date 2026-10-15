#ifndef SLOP_sriqabox_H
#define SLOP_sriqabox_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"
#include "slop_owl2.h"
#include "slop_canon.h"
#include "slop_gate.h"
#include "slop_sriqnames.h"
#include "slop_sriqelim.h"
#include "slop_sriqclauses.h"
#include "slop_sriqref.h"
#include "slop_sriqctx.h"
#include "slop_sriqsat.h"

typedef struct howl_sriqabox_Split howl_sriqabox_Split;
typedef struct howl_sriqabox_Folded howl_sriqabox_Folded;
typedef struct howl_sriqabox_Typed howl_sriqabox_Typed;
typedef struct howl_sriqabox_Typing howl_sriqabox_Typing;
typedef struct howl_sriqabox_Inputs howl_sriqabox_Inputs;
typedef struct howl_sriqabox_SplitRun howl_sriqabox_SplitRun;

#ifndef SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_IMPL_DEFINED
SLOP_LIST_DEFINE(uint32_t, slop_list_u32)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawConcept, slop_list_howl_owl2_RawConcept)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawAxiom, slop_list_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Node, slop_list_howl_types_Node)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_DNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_DName, slop_list_howl_types_DName)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Clause, slop_list_howl_types_Clause)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_HOWL_TYPES_SUBPAIR_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_SubPair, slop_list_howl_types_SubPair)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_DName, slop_option_howl_types_DName)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_types_SubPair, slop_option_howl_types_SubPair)
#endif

struct howl_sriqabox_Split {
    howl_gate_GateResult h;
    howl_gate_GateResult c;
    uint8_t has_c;
};
typedef struct howl_sriqabox_Split howl_sriqabox_Split;

#ifndef SLOP_OPTION_HOWL_SRIQABOX_SPLIT_DEFINED
#define SLOP_OPTION_HOWL_SRIQABOX_SPLIT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqabox_Split, slop_option_howl_sriqabox_Split)
#endif

struct howl_sriqabox_Folded {
    howl_sriqclauses_SriqClauses sc;
    slop_list_u32 hidden;
};
typedef struct howl_sriqabox_Folded howl_sriqabox_Folded;

#ifndef SLOP_OPTION_HOWL_SRIQABOX_FOLDED_DEFINED
#define SLOP_OPTION_HOWL_SRIQABOX_FOLDED_DEFINED
SLOP_OPTION_DEFINE(howl_sriqabox_Folded, slop_option_howl_sriqabox_Folded)
#endif

struct howl_sriqabox_Typed {
    slop_rdf_rdf_IRI ind;
    howl_owl2_RawConcept c;
};
typedef struct howl_sriqabox_Typed howl_sriqabox_Typed;

#ifndef SLOP_OPTION_HOWL_SRIQABOX_TYPED_DEFINED
#define SLOP_OPTION_HOWL_SRIQABOX_TYPED_DEFINED
SLOP_OPTION_DEFINE(howl_sriqabox_Typed, slop_option_howl_sriqabox_Typed)
#endif

#ifndef SLOP_LIST_HOWL_SRIQABOX_TYPED_DEFINED
#define SLOP_LIST_HOWL_SRIQABOX_TYPED_DEFINED
#define SLOP_LIST_HOWL_SRIQABOX_TYPED_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqabox_Typed, slop_list_howl_sriqabox_Typed)
#endif

struct howl_sriqabox_Typing {
    slop_rdf_rdf_IRI ind;
    slop_list_howl_owl2_RawConcept types;
};
typedef struct howl_sriqabox_Typing howl_sriqabox_Typing;

#ifndef SLOP_OPTION_HOWL_SRIQABOX_TYPING_DEFINED
#define SLOP_OPTION_HOWL_SRIQABOX_TYPING_DEFINED
SLOP_OPTION_DEFINE(howl_sriqabox_Typing, slop_option_howl_sriqabox_Typing)
#endif

#ifndef SLOP_LIST_HOWL_SRIQABOX_TYPING_DEFINED
#define SLOP_LIST_HOWL_SRIQABOX_TYPING_DEFINED
#define SLOP_LIST_HOWL_SRIQABOX_TYPING_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqabox_Typing, slop_list_howl_sriqabox_Typing)
#endif

struct howl_sriqabox_Inputs {
    howl_sriqclauses_SriqIds ids;
    howl_sriqref_RefIn h;
    howl_sriqref_RefIn c;
    uint8_t has_c;
    slop_list_howl_owl2_RawAxiom omitted;
};
typedef struct howl_sriqabox_Inputs howl_sriqabox_Inputs;

#ifndef SLOP_OPTION_HOWL_SRIQABOX_INPUTS_DEFINED
#define SLOP_OPTION_HOWL_SRIQABOX_INPUTS_DEFINED
SLOP_OPTION_DEFINE(howl_sriqabox_Inputs, slop_option_howl_sriqabox_Inputs)
#endif

struct howl_sriqabox_SplitRun {
    howl_sriqsat_SatResult h;
    howl_sriqsat_SatResult c;
    uint8_t ran_c;
    uint8_t inconsistent;
    uint8_t complete;
    uint8_t finished;
    int64_t rounds;
    uint8_t cancelled;
};
typedef struct howl_sriqabox_SplitRun howl_sriqabox_SplitRun;

#ifndef SLOP_OPTION_HOWL_SRIQABOX_SPLITRUN_DEFINED
#define SLOP_OPTION_HOWL_SRIQABOX_SPLITRUN_DEFINED
SLOP_OPTION_DEFINE(howl_sriqabox_SplitRun, slop_option_howl_sriqabox_SplitRun)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif

#ifndef SLOP_RESULT_HOWL_SRIQABOX_FOLDED_STRING_DEFINED
#define SLOP_RESULT_HOWL_SRIQABOX_FOLDED_STRING_DEFINED
typedef struct { bool is_ok; union { howl_sriqabox_Folded ok; slop_string err; } data; } slop_result_howl_sriqabox_Folded_string;
#endif

#ifndef SLOP_RESULT_HOWL_SRIQABOX_INPUTS_STRING_DEFINED
#define SLOP_RESULT_HOWL_SRIQABOX_INPUTS_STRING_DEFINED
typedef struct { bool is_ok; union { howl_sriqabox_Inputs ok; slop_string err; } data; } slop_result_howl_sriqabox_Inputs_string;
#endif

slop_option_slop_rdf_rdf_IRI howl_sriqabox_individual_of(howl_types_Node n);
void howl_sriqabox_put_node(slop_map* s, howl_types_Node n);
slop_map* howl_sriqabox_unfoldable(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
slop_list_slop_rdf_rdf_IRI howl_sriqabox_different_bad(slop_arena* arena, slop_list_howl_types_Node ns);
slop_list_slop_rdf_rdf_IRI howl_sriqabox_repeated(slop_arena* arena, slop_list_howl_types_Node ns);
slop_option_slop_rdf_rdf_IRI howl_sriqabox_foldable_subject(howl_owl2_RawClassAssertion ca, slop_map* bad);
slop_list_howl_sriqabox_Typed howl_sriqabox_typed_pairs(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_map* bad);
slop_option_howl_sriqabox_Typed howl_sriqabox_typed_of(howl_owl2_RawAxiom ax, slop_map* bad);
howl_sriqabox_Typed howl_sriqabox_typed_at(slop_list_howl_sriqabox_Typed xs, int64_t k, howl_sriqabox_Typed fallback);
int64_t howl_sriqabox_typed_cmp(howl_sriqabox_Typed a, howl_sriqabox_Typed b);
slop_list_howl_sriqabox_Typing howl_sriqabox_typings(slop_arena* arena, slop_list_howl_sriqabox_Typed pairs);
slop_list_howl_sriqabox_Typed howl_sriqabox_sorted_typed(slop_arena* arena, slop_list_howl_sriqabox_Typed pairs, howl_sriqabox_Typed p0);
slop_list_howl_sriqabox_Typing howl_sriqabox_typings_sorted(slop_arena* arena, slop_list_howl_sriqabox_Typed ps, howl_sriqabox_Typed p0);
int64_t howl_sriqabox_run_end(slop_list_howl_sriqabox_Typed ps, int64_t k, howl_sriqabox_Typed p0);
slop_list_howl_owl2_RawConcept howl_sriqabox_run_types(slop_arena* arena, slop_list_howl_sriqabox_Typed ps, int64_t k, int64_t end, howl_sriqabox_Typed p0);
uint8_t howl_sriqabox_ends_with(slop_list_howl_owl2_RawConcept cs, howl_owl2_RawConcept c);
int64_t howl_sriqabox_types_cmp(slop_list_howl_owl2_RawConcept a, slop_list_howl_owl2_RawConcept b);
howl_sriqabox_Typing howl_sriqabox_typing_at(slop_list_howl_sriqabox_Typing xs, int64_t k, howl_sriqabox_Typing fallback);
slop_map* howl_sriqabox_representatives(slop_arena* arena, slop_list_howl_sriqabox_Typing ts);
int64_t howl_sriqabox_typing_cmp(howl_sriqabox_Typing a, howl_sriqabox_Typing b);
slop_list_howl_sriqabox_Typing howl_sriqabox_sorted_typings(slop_arena* arena, slop_list_howl_sriqabox_Typing ts, howl_sriqabox_Typing t0);
slop_map* howl_sriqabox_first_of_each(slop_arena* arena, slop_list_howl_sriqabox_Typing ts);
uint8_t howl_sriqabox_h_keeps(howl_owl2_RawAxiom ax, slop_map* reps);
slop_option_howl_owl2_RawAxiom howl_sriqabox_c_axiom(slop_arena* arena, howl_owl2_RawAxiom ax, slop_map* bad);
slop_list_howl_types_Node howl_sriqabox_unfoldable_nodes(slop_arena* arena, slop_list_howl_types_Node ns, slop_map* bad);
uint8_t howl_sriqabox_is_assertion(howl_owl2_RawAxiom ax);
howl_owl2_Signature howl_sriqabox_with_individuals(howl_owl2_Signature sig, slop_map* inds);
howl_sriqabox_Split howl_sriqabox_abox_split(slop_arena* arena, howl_gate_GateResult gr);
slop_result_howl_sriqabox_Folded_string howl_sriqabox_fold_clauses(slop_arena* arena, howl_sriqnames_SriqNormal n);
slop_list_u32 howl_sriqabox_hidden_ids(slop_arena* arena, howl_sriqclauses_SriqClauses sc, slop_list_howl_types_DName names);
uint32_t howl_sriqabox_u32_at(slop_list_u32 xs, int64_t k);
int64_t howl_sriqabox_u32_cmp(uint32_t a, uint32_t b);
howl_sriqref_RefIn howl_sriqabox_h_input(slop_arena* arena, howl_sriqabox_Folded f);
howl_sriqref_RefIn howl_sriqabox_consistency_input(howl_sriqref_RefIn in);
slop_result_howl_sriqabox_Inputs_string howl_sriqabox_split_inputs(slop_arena* arena, howl_gate_GateResult gr);
slop_result_howl_sriqabox_Inputs_string howl_sriqabox_split_inputs_bounded(slop_arena* arena, howl_gate_GateResult gr, int64_t bound);
slop_result_howl_sriqabox_Inputs_string howl_sriqabox_inputs_from(slop_arena* arena, howl_sriqabox_Split sp, howl_sriqabox_Folded f, slop_list_howl_owl2_RawAxiom omitted, int64_t bound);
slop_result_howl_sriqabox_Inputs_string howl_sriqabox_c_inputs(slop_arena* arena, howl_sriqabox_Split sp, howl_sriqclauses_SriqIds ids, howl_sriqref_RefIn h, slop_list_howl_owl2_RawAxiom omitted, int64_t bound);
slop_list_howl_owl2_RawAxiom howl_sriqabox_both_omitted(slop_arena* arena, slop_list_howl_owl2_RawAxiom a, slop_list_howl_owl2_RawAxiom b);
uint8_t howl_sriqabox_finished(howl_sriqref_RefStatus s);
howl_sriqabox_SplitRun howl_sriqabox_split_run(slop_arena* arena, howl_sriqabox_Inputs in, howl_sriqsat_SatConfig cfg);
howl_sriqabox_SplitRun howl_sriqabox_split_run_of(slop_arena* arena, howl_sriqref_RefIn h_in, howl_sriqref_RefIn c_in, uint8_t has_c, uint8_t omitted, howl_sriqsat_SatConfig cfg);
howl_sriqabox_SplitRun howl_sriqabox_c_run(slop_arena* arena, howl_sriqsat_SatResult h, uint8_t hdone, howl_sriqref_RefIn c_in, uint8_t omitted, howl_sriqsat_SatConfig cfg);
howl_sriqsat_SatConfig howl_sriqabox_with_fuel(howl_sriqsat_SatConfig cfg, int64_t fuel);
howl_sriqsat_SatConfig howl_sriqabox_sriq_config(int64_t max_rounds, int64_t budget, int64_t cancel);
howl_types_Findings howl_sriqabox_split_findings(slop_arena* arena, howl_sriqctx_Structure st, slop_list_slop_rdf_rdf_IRI classes, uint8_t inconsistent);
slop_list_howl_types_Clause howl_sriqabox_set_at_ctx(slop_arena* arena, howl_sriqctx_Structure st, int64_t v);
uint8_t howl_sriqabox_body_within(howl_types_Clause c, int64_t b);
uint8_t howl_sriqabox_is_x_atom(howl_types_Lit l, int64_t b);
int64_t howl_sriqabox_head_class(howl_types_Clause c, int64_t n);
uint8_t howl_sriqabox_unsat_at(slop_arena* arena, howl_sriqctx_Structure st, int64_t b);
slop_list_slop_rdf_rdf_IRI howl_sriqabox_unsat_classes(slop_arena* arena, howl_sriqctx_Structure st, slop_list_slop_rdf_rdf_IRI classes);
slop_list_howl_types_SubPair howl_sriqabox_taxonomy(slop_arena* arena, howl_sriqctx_Structure st, slop_list_slop_rdf_rdf_IRI classes);
slop_list_howl_types_SubPair howl_sriqabox_class_rows(slop_arena* arena, howl_sriqctx_Structure st, slop_list_slop_rdf_rdf_IRI classes, int64_t b, int64_t n);
slop_list_int howl_sriqabox_holds_in(slop_arena* arena, howl_sriqctx_Structure st, int64_t v, int64_t b, int64_t n);
howl_types_Node howl_sriqabox_class_at(slop_list_slop_rdf_rdf_IRI classes, int64_t a);
slop_list_howl_types_SubPair howl_sriqabox_distinct_pairs(slop_arena* arena, slop_list_howl_types_SubPair ps);

#ifndef SLOP_OPTION_HOWL_SRIQABOX_SPLIT_DEFINED
#define SLOP_OPTION_HOWL_SRIQABOX_SPLIT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqabox_Split, slop_option_howl_sriqabox_Split)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQABOX_FOLDED_DEFINED
#define SLOP_OPTION_HOWL_SRIQABOX_FOLDED_DEFINED
SLOP_OPTION_DEFINE(howl_sriqabox_Folded, slop_option_howl_sriqabox_Folded)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQABOX_TYPED_DEFINED
#define SLOP_OPTION_HOWL_SRIQABOX_TYPED_DEFINED
SLOP_OPTION_DEFINE(howl_sriqabox_Typed, slop_option_howl_sriqabox_Typed)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQABOX_TYPING_DEFINED
#define SLOP_OPTION_HOWL_SRIQABOX_TYPING_DEFINED
SLOP_OPTION_DEFINE(howl_sriqabox_Typing, slop_option_howl_sriqabox_Typing)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_DName, slop_option_howl_types_DName)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQABOX_INPUTS_DEFINED
#define SLOP_OPTION_HOWL_SRIQABOX_INPUTS_DEFINED
SLOP_OPTION_DEFINE(howl_sriqabox_Inputs, slop_option_howl_sriqabox_Inputs)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQABOX_SPLITRUN_DEFINED
#define SLOP_OPTION_HOWL_SRIQABOX_SPLITRUN_DEFINED
SLOP_OPTION_DEFINE(howl_sriqabox_SplitRun, slop_option_howl_sriqabox_SplitRun)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_types_SubPair, slop_option_howl_types_SubPair)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DlClause, slop_option_howl_types_DlClause)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_DLCLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_DlClause, slop_list_howl_types_DlClause)
#endif


#endif
