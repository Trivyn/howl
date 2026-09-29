#ifndef SLOP_normalize_H
#define SLOP_normalize_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"
#include "slop_owl2.h"
#include "slop_gate.h"
#include "slop_decode.h"
#include "slop_saturate.h"
#include "slop_canon.h"

typedef struct normalize_Decoded normalize_Decoded;
typedef struct normalize_NormResult normalize_NormResult;
typedef struct normalize_NormOutput normalize_NormOutput;
typedef struct normalize_NormState normalize_NormState;
typedef struct normalize_RangeFact normalize_RangeFact;

#ifndef SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_IMPL_DEFINED
SLOP_LIST_DEFINE(uint8_t, slop_list_u8)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawAxiom, slop_list_owl2_RawAxiom)
#endif

#ifndef SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Omission, slop_list_types_Omission)
#endif

#ifndef SLOP_LIST_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_TYPES_NORMAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_NormAxiom, slop_list_types_NormAxiom)
#endif

#ifndef SLOP_LIST_TYPES_LOGICALEDGE_DEFINED
#define SLOP_LIST_TYPES_LOGICALEDGE_DEFINED
#define SLOP_LIST_TYPES_LOGICALEDGE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_LogicalEdge, slop_list_types_LogicalEdge)
#endif

#ifndef SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Node, slop_list_types_Node)
#endif

#ifndef SLOP_LIST_TYPES_ADDRESSED_DEFINED
#define SLOP_LIST_TYPES_ADDRESSED_DEFINED
#define SLOP_LIST_TYPES_ADDRESSED_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Addressed, slop_list_types_Addressed)
#endif

#ifndef SLOP_LIST_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawConcept, slop_list_owl2_RawConcept)
#endif

#ifndef SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(types_RoleId, slop_list_types_RoleId)
#endif

#ifndef SLOP_LIST_RDF_TRIPLE_DEFINED
#define SLOP_LIST_RDF_TRIPLE_DEFINED
#define SLOP_LIST_RDF_TRIPLE_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_Triple, slop_list_rdf_Triple)
#endif

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_LOGICALEDGE_DEFINED
#define SLOP_OPTION_TYPES_LOGICALEDGE_DEFINED
SLOP_OPTION_DEFINE(types_LogicalEdge, slop_option_types_LogicalEdge)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(types_Addressed, slop_option_types_Addressed)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

struct normalize_Decoded {
    slop_list_owl2_RawAxiom axioms;
    owl2_Signature signature;
    slop_list_types_Omission omissions;
};
typedef struct normalize_Decoded normalize_Decoded;

#ifndef SLOP_OPTION_NORMALIZE_DECODED_DEFINED
#define SLOP_OPTION_NORMALIZE_DECODED_DEFINED
SLOP_OPTION_DEFINE(normalize_Decoded, slop_option_normalize_Decoded)
#endif

struct normalize_NormResult {
    slop_list_types_NormAxiom axioms;
    types_Saturation saturation;
    types_Coverage coverage;
    types_Names names;
};
typedef struct normalize_NormResult normalize_NormResult;

#ifndef SLOP_OPTION_NORMALIZE_NORMRESULT_DEFINED
#define SLOP_OPTION_NORMALIZE_NORMRESULT_DEFINED
SLOP_OPTION_DEFINE(normalize_NormResult, slop_option_normalize_NormResult)
#endif

struct normalize_NormOutput {
    slop_list_types_NormAxiom axioms;
    slop_list_types_LogicalEdge edges;
    slop_list_types_Node asserted;
    slop_list_types_Addressed seeds;
    int64_t fresh_count;
};
typedef struct normalize_NormOutput normalize_NormOutput;

#ifndef SLOP_OPTION_NORMALIZE_NORMOUTPUT_DEFINED
#define SLOP_OPTION_NORMALIZE_NORMOUTPUT_DEFINED
SLOP_OPTION_DEFINE(normalize_NormOutput, slop_option_normalize_NormOutput)
#endif

struct normalize_NormState {
    slop_list_types_NormAxiom axioms;
    slop_list_string fresh;
    slop_map* fresh_index;
    slop_list_string fresh_roles;
    slop_map* fresh_role_index;
    slop_map* neg_done;
    slop_map* pos_done;
    slop_list_types_LogicalEdge edges;
    slop_list_types_Node asserted;
};
typedef struct normalize_NormState normalize_NormState;

#ifndef SLOP_OPTION_NORMALIZE_NORMSTATE_DEFINED
#define SLOP_OPTION_NORMALIZE_NORMSTATE_DEFINED
SLOP_OPTION_DEFINE(normalize_NormState, slop_option_normalize_NormState)
#endif

struct normalize_RangeFact {
    int64_t role;
    types_Node filler;
};
typedef struct normalize_RangeFact normalize_RangeFact;

#ifndef SLOP_OPTION_NORMALIZE_RANGEFACT_DEFINED
#define SLOP_OPTION_NORMALIZE_RANGEFACT_DEFINED
SLOP_OPTION_DEFINE(normalize_RangeFact, slop_option_normalize_RangeFact)
#endif

#ifndef SLOP_LIST_NORMALIZE_RANGEFACT_DEFINED
#define SLOP_LIST_NORMALIZE_RANGEFACT_DEFINED
#define SLOP_LIST_NORMALIZE_RANGEFACT_IMPL_DEFINED
SLOP_LIST_DEFINE(normalize_RangeFact, slop_list_normalize_RangeFact)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef TYPES_NODE_HASH_EQ_DEFINED
#define TYPES_NODE_HASH_EQ_DEFINED
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
static inline uint64_t slop_hash_types_Node(const void* key) {
    const types_Node* _k = (const types_Node*)key;
    switch (_k->tag) {
        case types_Node_class_node:
            return slop_hash_rdf_IRI(&_k->data.class_node);
        case types_Node_individual_node:
            return slop_hash_rdf_IRI(&_k->data.individual_node);
        case types_Node_fresh_node:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.fresh_node });
    }
    return 0;
}
static inline bool slop_eq_types_Node(const void* a, const void* b) {
    const types_Node* _a = (const types_Node*)a;
    const types_Node* _b = (const types_Node*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case types_Node_class_node:
            return slop_eq_rdf_IRI(&_a->data.class_node, &_b->data.class_node);
        case types_Node_individual_node:
            return slop_eq_rdf_IRI(&_a->data.individual_node, &_b->data.individual_node);
        case types_Node_fresh_node:
            return _a->data.fresh_node == _b->data.fresh_node;
    }
    return false;
}
#endif

#ifndef SLOP_RESULT_NORMALIZE_DECODED_TYPES_FAULT_DEFINED
#define SLOP_RESULT_NORMALIZE_DECODED_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { normalize_Decoded ok; types_Fault err; } data; } slop_result_normalize_Decoded_types_Fault;
#endif

#ifndef SLOP_RESULT_NORMALIZE_NORMRESULT_TYPES_FAULT_DEFINED
#define SLOP_RESULT_NORMALIZE_NORMRESULT_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { normalize_NormResult ok; types_Fault err; } data; } slop_result_normalize_NormResult_types_Fault;
#endif

normalize_NormState* normalize_new_state(slop_arena* arena);
uint8_t normalize_st_emit(slop_arena* arena, normalize_NormState* p, types_NormAxiom ax);
uint8_t normalize_st_emit_edge(slop_arena* arena, normalize_NormState* p, types_LogicalEdge e);
uint8_t normalize_st_note_asserted(slop_arena* arena, normalize_NormState* p, types_Node n);
int64_t normalize_st_fresh_id(slop_arena* arena, normalize_NormState* p, slop_string text);
int64_t normalize_st_fresh_role_id(slop_arena* arena, normalize_NormState* p, slop_string text);
uint8_t normalize_st_mark_neg(slop_arena* arena, normalize_NormState* p, slop_string text);
uint8_t normalize_st_mark_pos(slop_arena* arena, normalize_NormState* p, slop_string text);
owl2_RawConcept normalize_rc_of_node(types_Node n);
slop_list_owl2_RawConcept normalize_flatten_and(slop_arena* arena, owl2_RawConcept c, slop_list_owl2_RawConcept acc);
slop_string normalize_prefix_text(slop_arena* arena, slop_list_owl2_RawConcept conj, int64_t upto);
types_Node normalize_neg_atom(slop_arena* arena, normalize_NormState* p, owl2_RawConcept c);
types_Node normalize_fold_conjuncts(slop_arena* arena, normalize_NormState* p, slop_list_owl2_RawConcept conj, int64_t n);
types_Node normalize_pos_atom(slop_arena* arena, normalize_NormState* p, owl2_RawConcept c);
uint8_t normalize_emit_inclusion(slop_arena* arena, normalize_NormState* p, slop_list_owl2_RawConcept conj, int64_t n, types_Node target);
uint8_t normalize_normalize_gci(slop_arena* arena, normalize_NormState* p, owl2_RawConcept lhs, owl2_RawConcept rhs);
uint8_t normalize_decompose_chain(slop_arena* arena, normalize_NormState* p, owl2_RawChain ch);
types_RoleId normalize_role_at_n(slop_list_types_RoleId xs, int64_t i);
slop_string normalize_prefix_role_text(slop_arena* arena, slop_list_types_RoleId steps, int64_t upto, types_RoleId super);
slop_string normalize_render_role_name(types_RoleId r);
slop_list_normalize_RangeFact normalize_collect_range_facts(slop_arena* arena, normalize_NormState* p, slop_list_owl2_RawAxiom axs, slop_list_types_RoleId roles);
slop_list_types_Node normalize_ran_t(slop_arena* arena, slop_list_normalize_RangeFact facts, slop_list_u8 told, int64_t n, int64_t r);
uint8_t normalize_mat_get_b(slop_list_u8 m, int64_t i);
slop_string normalize_range_elim_key(slop_arena* arena, types_RoleId r, types_Node d);
slop_string normalize_render_node_name(slop_arena* arena, types_Node n);
uint8_t normalize_eliminate_ranges(slop_arena* arena, normalize_NormState* p, slop_list_normalize_RangeFact facts, slop_list_u8 told, int64_t n, slop_list_types_RoleId roles);
slop_list_types_Addressed normalize_edge_range_seeds(slop_arena* arena, slop_list_types_LogicalEdge edges, slop_list_normalize_RangeFact facts, slop_list_u8 told, int64_t n, slop_list_types_RoleId roles);
uint8_t normalize_normalize_axiom(slop_arena* arena, normalize_NormState* p, owl2_RawAxiom ax);
owl2_RawConcept* normalize_box_rc(slop_arena* arena, owl2_RawConcept c);
normalize_NormOutput normalize_normalize_accepted(slop_arena* arena, slop_list_owl2_RawAxiom axs);
types_Node normalize_ex_stewie(void);
normalize_NormOutput normalize_ex_asserting_stewie(slop_arena* arena);
owl2_Signature normalize_ex_declaring_stewie(slop_arena* arena);
slop_list_types_Node normalize_signature_nodes(slop_arena* arena, owl2_Signature sig, normalize_NormOutput no);
uint8_t normalize_install_seeds(slop_arena* arena, types_Saturation sat, normalize_NormOutput no);
types_NormAxiom normalize_rename_axiom(slop_arena* arena, types_Names names, types_NormAxiom ax);
types_Derived normalize_rename_derived(slop_arena* arena, types_Names names, types_Derived d);
slop_list_types_Node normalize_rename_nodes(slop_arena* arena, types_Names names, slop_list_types_Node ns);
normalize_NormOutput normalize_rename_output(slop_arena* arena, types_Names names, normalize_NormOutput no);
slop_result_normalize_Decoded_types_Fault normalize_decode_document(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved);
normalize_NormResult normalize_normalize_decoded(slop_arena* arena, slop_arena* scratch, normalize_Decoded d);
slop_result_normalize_NormResult_types_Fault normalize_normalize_input(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

#ifndef SLOP_OPTION_NORMALIZE_DECODED_DEFINED
#define SLOP_OPTION_NORMALIZE_DECODED_DEFINED
SLOP_OPTION_DEFINE(normalize_Decoded, slop_option_normalize_Decoded)
#endif

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_NORMALIZE_NORMRESULT_DEFINED
#define SLOP_OPTION_NORMALIZE_NORMRESULT_DEFINED
SLOP_OPTION_DEFINE(normalize_NormResult, slop_option_normalize_NormResult)
#endif

#ifndef SLOP_OPTION_TYPES_LOGICALEDGE_DEFINED
#define SLOP_OPTION_TYPES_LOGICALEDGE_DEFINED
SLOP_OPTION_DEFINE(types_LogicalEdge, slop_option_types_LogicalEdge)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(types_Addressed, slop_option_types_Addressed)
#endif

#ifndef SLOP_OPTION_NORMALIZE_NORMOUTPUT_DEFINED
#define SLOP_OPTION_NORMALIZE_NORMOUTPUT_DEFINED
SLOP_OPTION_DEFINE(normalize_NormOutput, slop_option_normalize_NormOutput)
#endif

#ifndef SLOP_OPTION_NORMALIZE_NORMSTATE_DEFINED
#define SLOP_OPTION_NORMALIZE_NORMSTATE_DEFINED
SLOP_OPTION_DEFINE(normalize_NormState, slop_option_normalize_NormState)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_NORMALIZE_RANGEFACT_DEFINED
#define SLOP_OPTION_NORMALIZE_RANGEFACT_DEFINED
SLOP_OPTION_DEFINE(normalize_RangeFact, slop_option_normalize_RangeFact)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif


#endif
