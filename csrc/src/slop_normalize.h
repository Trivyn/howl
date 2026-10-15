#ifndef SLOP_normalize_H
#define SLOP_normalize_H

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
#include "slop_gate.h"
#include "slop_decode.h"
#include "slop_termstore.h"
#include "slop_saturate.h"
#include "slop_canon.h"
#include "slop_naming.h"

typedef struct howl_normalize_Decoded howl_normalize_Decoded;
typedef struct howl_normalize_NormResult howl_normalize_NormResult;
typedef struct howl_normalize_NormOutput howl_normalize_NormOutput;
typedef struct howl_normalize_NormState howl_normalize_NormState;
typedef struct howl_normalize_RangeFact howl_normalize_RangeFact;

#ifndef SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_IMPL_DEFINED
SLOP_LIST_DEFINE(uint8_t, slop_list_u8)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawAxiom, slop_list_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Omission, slop_list_howl_types_Omission)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_NORMAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_NormAxiom, slop_list_howl_types_NormAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_LOGICALEDGE_DEFINED
#define SLOP_LIST_HOWL_TYPES_LOGICALEDGE_DEFINED
#define SLOP_LIST_HOWL_TYPES_LOGICALEDGE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_LogicalEdge, slop_list_howl_types_LogicalEdge)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Node, slop_list_howl_types_Node)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ADDRESSED_DEFINED
#define SLOP_LIST_HOWL_TYPES_ADDRESSED_DEFINED
#define SLOP_LIST_HOWL_TYPES_ADDRESSED_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Addressed, slop_list_howl_types_Addressed)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawConcept, slop_list_howl_owl2_RawConcept)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_RoleId, slop_list_howl_types_RoleId)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TRIPLE_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_Triple, slop_list_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_NormAxiom, slop_option_howl_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LOGICALEDGE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LOGICALEDGE_DEFINED
SLOP_OPTION_DEFINE(howl_types_LogicalEdge, slop_option_howl_types_LogicalEdge)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(howl_types_Addressed, slop_option_howl_types_Addressed)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Triple, slop_option_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

struct howl_normalize_Decoded {
    slop_list_howl_owl2_RawAxiom axioms;
    howl_owl2_Signature signature;
    slop_list_howl_types_Omission omissions;
    int64_t documents;
    slop_list_int axiom_docs;
    slop_list_int omission_docs;
};
typedef struct howl_normalize_Decoded howl_normalize_Decoded;

#ifndef SLOP_OPTION_HOWL_NORMALIZE_DECODED_DEFINED
#define SLOP_OPTION_HOWL_NORMALIZE_DECODED_DEFINED
SLOP_OPTION_DEFINE(howl_normalize_Decoded, slop_option_howl_normalize_Decoded)
#endif

struct howl_normalize_NormResult {
    slop_list_howl_types_NormAxiom axioms;
    howl_types_Saturation saturation;
    howl_types_Coverage coverage;
    howl_types_Names names;
};
typedef struct howl_normalize_NormResult howl_normalize_NormResult;

#ifndef SLOP_OPTION_HOWL_NORMALIZE_NORMRESULT_DEFINED
#define SLOP_OPTION_HOWL_NORMALIZE_NORMRESULT_DEFINED
SLOP_OPTION_DEFINE(howl_normalize_NormResult, slop_option_howl_normalize_NormResult)
#endif

struct howl_normalize_NormOutput {
    slop_list_howl_types_NormAxiom axioms;
    slop_list_howl_types_LogicalEdge edges;
    slop_list_howl_types_Node asserted;
    slop_list_howl_types_Addressed seeds;
    int64_t fresh_count;
};
typedef struct howl_normalize_NormOutput howl_normalize_NormOutput;

#ifndef SLOP_OPTION_HOWL_NORMALIZE_NORMOUTPUT_DEFINED
#define SLOP_OPTION_HOWL_NORMALIZE_NORMOUTPUT_DEFINED
SLOP_OPTION_DEFINE(howl_normalize_NormOutput, slop_option_howl_normalize_NormOutput)
#endif

struct howl_normalize_NormState {
    slop_list_howl_types_NormAxiom axioms;
    howl_naming_Registry* registry;
    slop_list_howl_types_LogicalEdge edges;
    slop_list_howl_types_Node asserted;
};
typedef struct howl_normalize_NormState howl_normalize_NormState;

#ifndef SLOP_OPTION_HOWL_NORMALIZE_NORMSTATE_DEFINED
#define SLOP_OPTION_HOWL_NORMALIZE_NORMSTATE_DEFINED
SLOP_OPTION_DEFINE(howl_normalize_NormState, slop_option_howl_normalize_NormState)
#endif

struct howl_normalize_RangeFact {
    int64_t role;
    howl_types_Node filler;
};
typedef struct howl_normalize_RangeFact howl_normalize_RangeFact;

#ifndef SLOP_OPTION_HOWL_NORMALIZE_RANGEFACT_DEFINED
#define SLOP_OPTION_HOWL_NORMALIZE_RANGEFACT_DEFINED
SLOP_OPTION_DEFINE(howl_normalize_RangeFact, slop_option_howl_normalize_RangeFact)
#endif

#ifndef SLOP_LIST_HOWL_NORMALIZE_RANGEFACT_DEFINED
#define SLOP_LIST_HOWL_NORMALIZE_RANGEFACT_DEFINED
#define SLOP_LIST_HOWL_NORMALIZE_RANGEFACT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_normalize_RangeFact, slop_list_howl_normalize_RangeFact)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef HOWL_TYPES_NODE_HASH_EQ_DEFINED
#define HOWL_TYPES_NODE_HASH_EQ_DEFINED
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
static inline uint64_t slop_hash_howl_types_Node(const void* key) {
    const howl_types_Node* _k = (const howl_types_Node*)key;
    switch (_k->tag) {
        case howl_types_Node_class_node:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.class_node);
        case howl_types_Node_individual_node:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.individual_node);
        case howl_types_Node_fresh_node:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.fresh_node });
    }
    return 0;
}
static inline bool slop_eq_howl_types_Node(const void* a, const void* b) {
    const howl_types_Node* _a = (const howl_types_Node*)a;
    const howl_types_Node* _b = (const howl_types_Node*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_Node_class_node:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.class_node, &_b->data.class_node);
        case howl_types_Node_individual_node:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.individual_node, &_b->data.individual_node);
        case howl_types_Node_fresh_node:
            return _a->data.fresh_node == _b->data.fresh_node;
    }
    return false;
}
#endif

#ifndef SLOP_RESULT_HOWL_NORMALIZE_DECODED_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_NORMALIZE_DECODED_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_normalize_Decoded ok; howl_types_Fault err; } data; } slop_result_howl_normalize_Decoded_howl_types_Fault;
#endif

#ifndef SLOP_RESULT_HOWL_NORMALIZE_NORMRESULT_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_NORMALIZE_NORMRESULT_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_normalize_NormResult ok; howl_types_Fault err; } data; } slop_result_howl_normalize_NormResult_howl_types_Fault;
#endif

howl_normalize_NormState* howl_normalize_new_state(slop_arena* arena);
uint8_t howl_normalize_st_emit(slop_arena* arena, howl_normalize_NormState* p, howl_types_NormAxiom ax);
uint8_t howl_normalize_st_emit_edge(slop_arena* arena, howl_normalize_NormState* p, howl_types_LogicalEdge e);
uint8_t howl_normalize_st_note_asserted(slop_arena* arena, howl_normalize_NormState* p, howl_types_Node n);
int64_t howl_normalize_st_fresh_id(slop_arena* arena, howl_normalize_NormState* p, slop_string text);
int64_t howl_normalize_st_fresh_role_id(slop_arena* arena, howl_normalize_NormState* p, slop_string text);
uint8_t howl_normalize_st_mark_neg(slop_arena* arena, howl_normalize_NormState* p, slop_string text);
uint8_t howl_normalize_st_mark_pos(slop_arena* arena, howl_normalize_NormState* p, slop_string text);
howl_owl2_RawConcept howl_normalize_rc_of_node(howl_types_Node n);
howl_types_Node howl_normalize_neg_atom(slop_arena* arena, howl_normalize_NormState* p, howl_owl2_RawConcept c);
howl_types_Node howl_normalize_fold_conjuncts(slop_arena* arena, howl_normalize_NormState* p, slop_list_howl_owl2_RawConcept conj, int64_t n);
howl_types_Node howl_normalize_pos_atom(slop_arena* arena, howl_normalize_NormState* p, howl_owl2_RawConcept c);
uint8_t howl_normalize_emit_inclusion(slop_arena* arena, howl_normalize_NormState* p, slop_list_howl_owl2_RawConcept conj, int64_t n, howl_types_Node target);
uint8_t howl_normalize_normalize_gci(slop_arena* arena, howl_normalize_NormState* p, howl_owl2_RawConcept lhs, howl_owl2_RawConcept rhs);
uint8_t howl_normalize_decompose_chain(slop_arena* arena, howl_normalize_NormState* p, howl_owl2_RawChain ch);
slop_list_howl_normalize_RangeFact howl_normalize_collect_range_facts(slop_arena* arena, howl_normalize_NormState* p, slop_list_howl_owl2_RawAxiom axs, slop_list_howl_types_RoleId roles);
slop_list_howl_types_Node howl_normalize_ran_t(slop_arena* arena, slop_list_howl_normalize_RangeFact facts, slop_list_u8 told, int64_t n, int64_t r);
uint8_t howl_normalize_mat_get_b(slop_list_u8 m, int64_t i);
slop_string howl_normalize_range_elim_key(slop_arena* arena, howl_types_RoleId r, howl_types_Node d);
slop_string howl_normalize_render_node_name(slop_arena* arena, howl_types_Node n);
uint8_t howl_normalize_eliminate_ranges(slop_arena* arena, howl_normalize_NormState* p, slop_list_howl_normalize_RangeFact facts, slop_list_u8 told, int64_t n, slop_list_howl_types_RoleId roles);
slop_list_howl_types_Addressed howl_normalize_edge_range_seeds(slop_arena* arena, slop_list_howl_types_LogicalEdge edges, slop_list_howl_normalize_RangeFact facts, slop_list_u8 told, int64_t n, slop_list_howl_types_RoleId roles);
uint8_t howl_normalize_normalize_axiom(slop_arena* arena, howl_normalize_NormState* p, howl_owl2_RawAxiom ax);
howl_owl2_RawConcept* howl_normalize_box_rc(slop_arena* arena, howl_owl2_RawConcept c);
howl_normalize_NormOutput howl_normalize_normalize_accepted(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
howl_types_Node howl_normalize_ex_stewie(void);
howl_normalize_NormOutput howl_normalize_ex_asserting_stewie(slop_arena* arena);
howl_owl2_Signature howl_normalize_ex_declaring_stewie(slop_arena* arena);
slop_list_howl_types_Node howl_normalize_signature_nodes(slop_arena* arena, howl_owl2_Signature sig, howl_normalize_NormOutput no);
uint8_t howl_normalize_install_seeds(slop_arena* arena, howl_types_Saturation sat, howl_normalize_NormOutput no);
howl_types_NormAxiom howl_normalize_rename_axiom(slop_arena* arena, howl_types_Names names, howl_types_NormAxiom ax);
howl_types_Derived howl_normalize_rename_derived(slop_arena* arena, howl_types_Names names, howl_types_Derived d);
slop_list_howl_types_Node howl_normalize_rename_nodes(slop_arena* arena, howl_types_Names names, slop_list_howl_types_Node ns);
howl_normalize_NormOutput howl_normalize_rename_output(slop_arena* arena, howl_types_Names names, howl_normalize_NormOutput no);
slop_result_howl_normalize_Decoded_howl_types_Fault howl_normalize_decode_document(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved);
slop_result_howl_normalize_Decoded_howl_types_Fault howl_normalize_decode_encoded(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved);
howl_normalize_Decoded howl_normalize_copy_decoded(slop_arena* arena, howl_normalize_Decoded d);
slop_list_int howl_normalize_copy_ints(slop_arena* arena, slop_list_int xs);
howl_normalize_NormResult howl_normalize_normalize_decoded(slop_arena* arena, slop_arena* scratch, howl_normalize_Decoded d);
slop_result_howl_normalize_NormResult_howl_types_Fault howl_normalize_normalize_input(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved, howl_types_ReasonerConfig config);

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_HOWL_NORMALIZE_DECODED_DEFINED
#define SLOP_OPTION_HOWL_NORMALIZE_DECODED_DEFINED
SLOP_OPTION_DEFINE(howl_normalize_Decoded, slop_option_howl_normalize_Decoded)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_NormAxiom, slop_option_howl_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_NORMALIZE_NORMRESULT_DEFINED
#define SLOP_OPTION_HOWL_NORMALIZE_NORMRESULT_DEFINED
SLOP_OPTION_DEFINE(howl_normalize_NormResult, slop_option_howl_normalize_NormResult)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LOGICALEDGE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LOGICALEDGE_DEFINED
SLOP_OPTION_DEFINE(howl_types_LogicalEdge, slop_option_howl_types_LogicalEdge)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(howl_types_Addressed, slop_option_howl_types_Addressed)
#endif

#ifndef SLOP_OPTION_HOWL_NORMALIZE_NORMOUTPUT_DEFINED
#define SLOP_OPTION_HOWL_NORMALIZE_NORMOUTPUT_DEFINED
SLOP_OPTION_DEFINE(howl_normalize_NormOutput, slop_option_howl_normalize_NormOutput)
#endif

#ifndef SLOP_OPTION_HOWL_NORMALIZE_NORMSTATE_DEFINED
#define SLOP_OPTION_HOWL_NORMALIZE_NORMSTATE_DEFINED
SLOP_OPTION_DEFINE(howl_normalize_NormState, slop_option_howl_normalize_NormState)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_NORMALIZE_RANGEFACT_DEFINED
#define SLOP_OPTION_HOWL_NORMALIZE_RANGEFACT_DEFINED
SLOP_OPTION_DEFINE(howl_normalize_RangeFact, slop_option_howl_normalize_RangeFact)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Triple, slop_option_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif


#endif
