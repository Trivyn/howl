#ifndef SLOP_sriqabox_H
#define SLOP_sriqabox_H

#include "../runtime/slop_runtime.h"
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

typedef struct sriqabox_Split sriqabox_Split;
typedef struct sriqabox_Folded sriqabox_Folded;
typedef struct sriqabox_Typed sriqabox_Typed;
typedef struct sriqabox_Typing sriqabox_Typing;
typedef struct sriqabox_Inputs sriqabox_Inputs;
typedef struct sriqabox_SplitRun sriqabox_SplitRun;

#ifndef SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_IMPL_DEFINED
SLOP_LIST_DEFINE(uint32_t, slop_list_u32)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_LIST_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawConcept, slop_list_owl2_RawConcept)
#endif

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawAxiom, slop_list_owl2_RawAxiom)
#endif

#ifndef SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Node, slop_list_types_Node)
#endif

#ifndef SLOP_LIST_TYPES_DNAME_DEFINED
#define SLOP_LIST_TYPES_DNAME_DEFINED
#define SLOP_LIST_TYPES_DNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(types_DName, slop_list_types_DName)
#endif

#ifndef SLOP_LIST_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_TYPES_CLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Clause, slop_list_types_Clause)
#endif

#ifndef SLOP_LIST_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_TYPES_SUBPAIR_IMPL_DEFINED
SLOP_LIST_DEFINE(types_SubPair, slop_list_types_SubPair)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_TYPES_DNAME_DEFINED
#define SLOP_OPTION_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(types_DName, slop_option_types_DName)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(types_SubPair, slop_option_types_SubPair)
#endif

struct sriqabox_Split {
    gate_GateResult h;
    gate_GateResult c;
    uint8_t has_c;
};
typedef struct sriqabox_Split sriqabox_Split;

#ifndef SLOP_OPTION_SRIQABOX_SPLIT_DEFINED
#define SLOP_OPTION_SRIQABOX_SPLIT_DEFINED
SLOP_OPTION_DEFINE(sriqabox_Split, slop_option_sriqabox_Split)
#endif

struct sriqabox_Folded {
    sriqclauses_SriqClauses sc;
    slop_list_u32 hidden;
};
typedef struct sriqabox_Folded sriqabox_Folded;

#ifndef SLOP_OPTION_SRIQABOX_FOLDED_DEFINED
#define SLOP_OPTION_SRIQABOX_FOLDED_DEFINED
SLOP_OPTION_DEFINE(sriqabox_Folded, slop_option_sriqabox_Folded)
#endif

struct sriqabox_Typed {
    rdf_IRI ind;
    owl2_RawConcept c;
};
typedef struct sriqabox_Typed sriqabox_Typed;

#ifndef SLOP_OPTION_SRIQABOX_TYPED_DEFINED
#define SLOP_OPTION_SRIQABOX_TYPED_DEFINED
SLOP_OPTION_DEFINE(sriqabox_Typed, slop_option_sriqabox_Typed)
#endif

#ifndef SLOP_LIST_SRIQABOX_TYPED_DEFINED
#define SLOP_LIST_SRIQABOX_TYPED_DEFINED
#define SLOP_LIST_SRIQABOX_TYPED_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqabox_Typed, slop_list_sriqabox_Typed)
#endif

struct sriqabox_Typing {
    rdf_IRI ind;
    slop_list_owl2_RawConcept types;
};
typedef struct sriqabox_Typing sriqabox_Typing;

#ifndef SLOP_OPTION_SRIQABOX_TYPING_DEFINED
#define SLOP_OPTION_SRIQABOX_TYPING_DEFINED
SLOP_OPTION_DEFINE(sriqabox_Typing, slop_option_sriqabox_Typing)
#endif

#ifndef SLOP_LIST_SRIQABOX_TYPING_DEFINED
#define SLOP_LIST_SRIQABOX_TYPING_DEFINED
#define SLOP_LIST_SRIQABOX_TYPING_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqabox_Typing, slop_list_sriqabox_Typing)
#endif

struct sriqabox_Inputs {
    sriqclauses_SriqIds ids;
    sriqref_RefIn h;
    sriqref_RefIn c;
    uint8_t has_c;
    slop_list_owl2_RawAxiom omitted;
};
typedef struct sriqabox_Inputs sriqabox_Inputs;

#ifndef SLOP_OPTION_SRIQABOX_INPUTS_DEFINED
#define SLOP_OPTION_SRIQABOX_INPUTS_DEFINED
SLOP_OPTION_DEFINE(sriqabox_Inputs, slop_option_sriqabox_Inputs)
#endif

struct sriqabox_SplitRun {
    sriqsat_SatResult h;
    sriqsat_SatResult c;
    uint8_t ran_c;
    uint8_t inconsistent;
    uint8_t complete;
    uint8_t finished;
    int64_t rounds;
    uint8_t cancelled;
};
typedef struct sriqabox_SplitRun sriqabox_SplitRun;

#ifndef SLOP_OPTION_SRIQABOX_SPLITRUN_DEFINED
#define SLOP_OPTION_SRIQABOX_SPLITRUN_DEFINED
SLOP_OPTION_DEFINE(sriqabox_SplitRun, slop_option_sriqabox_SplitRun)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef RDF_IRI_HASH_EQ_DEFINED
#define RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_rdf_IRI(const void* key) {
    const rdf_IRI* _k = (const rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_rdf_IRI(const void* a, const void* b) {
    const rdf_IRI* _a = (const rdf_IRI*)a;
    const rdf_IRI* _b = (const rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif

#ifndef SLOP_RESULT_SRIQABOX_FOLDED_STRING_DEFINED
#define SLOP_RESULT_SRIQABOX_FOLDED_STRING_DEFINED
typedef struct { bool is_ok; union { sriqabox_Folded ok; slop_string err; } data; } slop_result_sriqabox_Folded_string;
#endif

#ifndef SLOP_RESULT_SRIQABOX_INPUTS_STRING_DEFINED
#define SLOP_RESULT_SRIQABOX_INPUTS_STRING_DEFINED
typedef struct { bool is_ok; union { sriqabox_Inputs ok; slop_string err; } data; } slop_result_sriqabox_Inputs_string;
#endif

slop_option_rdf_IRI sriqabox_individual_of(types_Node n);
void sriqabox_put_node(slop_map* s, types_Node n);
slop_map* sriqabox_unfoldable(slop_arena* arena, slop_list_owl2_RawAxiom axs);
slop_list_rdf_IRI sriqabox_different_bad(slop_arena* arena, slop_list_types_Node ns);
slop_list_rdf_IRI sriqabox_repeated(slop_arena* arena, slop_list_types_Node ns);
slop_option_rdf_IRI sriqabox_foldable_subject(owl2_RawClassAssertion ca, slop_map* bad);
slop_list_sriqabox_Typed sriqabox_typed_pairs(slop_arena* arena, slop_list_owl2_RawAxiom axs, slop_map* bad);
slop_option_sriqabox_Typed sriqabox_typed_of(owl2_RawAxiom ax, slop_map* bad);
sriqabox_Typed sriqabox_typed_at(slop_list_sriqabox_Typed xs, int64_t k, sriqabox_Typed fallback);
int64_t sriqabox_typed_cmp(sriqabox_Typed a, sriqabox_Typed b);
slop_list_sriqabox_Typing sriqabox_typings(slop_arena* arena, slop_list_sriqabox_Typed pairs);
slop_list_sriqabox_Typed sriqabox_sorted_typed(slop_arena* arena, slop_list_sriqabox_Typed pairs, sriqabox_Typed p0);
slop_list_sriqabox_Typing sriqabox_typings_sorted(slop_arena* arena, slop_list_sriqabox_Typed ps, sriqabox_Typed p0);
int64_t sriqabox_run_end(slop_list_sriqabox_Typed ps, int64_t k, sriqabox_Typed p0);
slop_list_owl2_RawConcept sriqabox_run_types(slop_arena* arena, slop_list_sriqabox_Typed ps, int64_t k, int64_t end, sriqabox_Typed p0);
uint8_t sriqabox_ends_with(slop_list_owl2_RawConcept cs, owl2_RawConcept c);
int64_t sriqabox_types_cmp(slop_list_owl2_RawConcept a, slop_list_owl2_RawConcept b);
sriqabox_Typing sriqabox_typing_at(slop_list_sriqabox_Typing xs, int64_t k, sriqabox_Typing fallback);
slop_map* sriqabox_representatives(slop_arena* arena, slop_list_sriqabox_Typing ts);
int64_t sriqabox_typing_cmp(sriqabox_Typing a, sriqabox_Typing b);
slop_list_sriqabox_Typing sriqabox_sorted_typings(slop_arena* arena, slop_list_sriqabox_Typing ts, sriqabox_Typing t0);
slop_map* sriqabox_first_of_each(slop_arena* arena, slop_list_sriqabox_Typing ts);
uint8_t sriqabox_h_keeps(owl2_RawAxiom ax, slop_map* reps);
slop_option_owl2_RawAxiom sriqabox_c_axiom(slop_arena* arena, owl2_RawAxiom ax, slop_map* bad);
slop_list_types_Node sriqabox_unfoldable_nodes(slop_arena* arena, slop_list_types_Node ns, slop_map* bad);
uint8_t sriqabox_is_assertion(owl2_RawAxiom ax);
owl2_Signature sriqabox_with_individuals(owl2_Signature sig, slop_map* inds);
sriqabox_Split sriqabox_abox_split(slop_arena* arena, gate_GateResult gr);
slop_result_sriqabox_Folded_string sriqabox_fold_clauses(slop_arena* arena, sriqnames_SriqNormal n);
slop_list_u32 sriqabox_hidden_ids(slop_arena* arena, sriqclauses_SriqClauses sc, slop_list_types_DName names);
uint32_t sriqabox_u32_at(slop_list_u32 xs, int64_t k);
int64_t sriqabox_u32_cmp(uint32_t a, uint32_t b);
sriqref_RefIn sriqabox_h_input(slop_arena* arena, sriqabox_Folded f);
sriqref_RefIn sriqabox_consistency_input(sriqref_RefIn in);
slop_result_sriqabox_Inputs_string sriqabox_split_inputs(slop_arena* arena, gate_GateResult gr);
slop_result_sriqabox_Inputs_string sriqabox_split_inputs_bounded(slop_arena* arena, gate_GateResult gr, int64_t bound);
slop_result_sriqabox_Inputs_string sriqabox_inputs_from(slop_arena* arena, sriqabox_Split sp, sriqabox_Folded f, slop_list_owl2_RawAxiom omitted, int64_t bound);
slop_result_sriqabox_Inputs_string sriqabox_c_inputs(slop_arena* arena, sriqabox_Split sp, sriqclauses_SriqIds ids, sriqref_RefIn h, slop_list_owl2_RawAxiom omitted, int64_t bound);
slop_list_owl2_RawAxiom sriqabox_both_omitted(slop_arena* arena, slop_list_owl2_RawAxiom a, slop_list_owl2_RawAxiom b);
uint8_t sriqabox_finished(sriqref_RefStatus s);
sriqabox_SplitRun sriqabox_split_run(slop_arena* arena, sriqabox_Inputs in, sriqsat_SatConfig cfg);
sriqabox_SplitRun sriqabox_split_run_of(slop_arena* arena, sriqref_RefIn h_in, sriqref_RefIn c_in, uint8_t has_c, uint8_t omitted, sriqsat_SatConfig cfg);
sriqabox_SplitRun sriqabox_c_run(slop_arena* arena, sriqsat_SatResult h, uint8_t hdone, sriqref_RefIn c_in, uint8_t omitted, sriqsat_SatConfig cfg);
sriqsat_SatConfig sriqabox_with_fuel(sriqsat_SatConfig cfg, int64_t fuel);
sriqsat_SatConfig sriqabox_sriq_config(int64_t max_rounds, int64_t budget, int64_t cancel);
types_Findings sriqabox_split_findings(slop_arena* arena, sriqctx_Structure st, slop_list_rdf_IRI classes, uint8_t inconsistent);
slop_list_types_Clause sriqabox_set_at_ctx(slop_arena* arena, sriqctx_Structure st, int64_t v);
uint8_t sriqabox_body_within(types_Clause c, int64_t b);
uint8_t sriqabox_is_x_atom(types_Lit l, int64_t b);
int64_t sriqabox_head_class(types_Clause c, int64_t n);
uint8_t sriqabox_unsat_at(slop_arena* arena, sriqctx_Structure st, int64_t b);
slop_list_rdf_IRI sriqabox_unsat_classes(slop_arena* arena, sriqctx_Structure st, slop_list_rdf_IRI classes);
slop_list_types_SubPair sriqabox_taxonomy(slop_arena* arena, sriqctx_Structure st, slop_list_rdf_IRI classes);
slop_list_types_SubPair sriqabox_class_rows(slop_arena* arena, sriqctx_Structure st, slop_list_rdf_IRI classes, int64_t b, int64_t n);
slop_list_int sriqabox_holds_in(slop_arena* arena, sriqctx_Structure st, int64_t v, int64_t b, int64_t n);
types_Node sriqabox_class_at(slop_list_rdf_IRI classes, int64_t a);
slop_list_types_SubPair sriqabox_distinct_pairs(slop_arena* arena, slop_list_types_SubPair ps);

#define sriqabox_SRIQ_CLAUSE_BUDGET (1000000)

#ifndef SLOP_OPTION_SRIQABOX_SPLIT_DEFINED
#define SLOP_OPTION_SRIQABOX_SPLIT_DEFINED
SLOP_OPTION_DEFINE(sriqabox_Split, slop_option_sriqabox_Split)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_SRIQABOX_FOLDED_DEFINED
#define SLOP_OPTION_SRIQABOX_FOLDED_DEFINED
SLOP_OPTION_DEFINE(sriqabox_Folded, slop_option_sriqabox_Folded)
#endif

#ifndef SLOP_OPTION_SRIQABOX_TYPED_DEFINED
#define SLOP_OPTION_SRIQABOX_TYPED_DEFINED
SLOP_OPTION_DEFINE(sriqabox_Typed, slop_option_sriqabox_Typed)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_SRIQABOX_TYPING_DEFINED
#define SLOP_OPTION_SRIQABOX_TYPING_DEFINED
SLOP_OPTION_DEFINE(sriqabox_Typing, slop_option_sriqabox_Typing)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_TYPES_DNAME_DEFINED
#define SLOP_OPTION_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(types_DName, slop_option_types_DName)
#endif

#ifndef SLOP_OPTION_SRIQABOX_INPUTS_DEFINED
#define SLOP_OPTION_SRIQABOX_INPUTS_DEFINED
SLOP_OPTION_DEFINE(sriqabox_Inputs, slop_option_sriqabox_Inputs)
#endif

#ifndef SLOP_OPTION_SRIQABOX_SPLITRUN_DEFINED
#define SLOP_OPTION_SRIQABOX_SPLITRUN_DEFINED
SLOP_OPTION_DEFINE(sriqabox_SplitRun, slop_option_sriqabox_SplitRun)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(types_SubPair, slop_option_types_SubPair)
#endif

#ifndef SLOP_OPTION_TYPES_DLCLAUSE_DEFINED
#define SLOP_OPTION_TYPES_DLCLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_DlClause, slop_option_types_DlClause)
#endif

#ifndef SLOP_LIST_TYPES_DLCLAUSE_DEFINED
#define SLOP_LIST_TYPES_DLCLAUSE_DEFINED
#define SLOP_LIST_TYPES_DLCLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_DlClause, slop_list_types_DlClause)
#endif


#endif
