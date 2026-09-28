#ifndef SLOP_decode_H
#define SLOP_decode_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_index.h"
#include "slop_vocab.h"
#include "slop_owl2.h"
#include "slop_types.h"
#include "slop_strlib.h"
#include "slop_canon.h"

typedef struct decode_ListFault decode_ListFault;
typedef struct decode_Stage0 decode_Stage0;
typedef struct decode_Stage1 decode_Stage1;

typedef enum {
    decode_LookupFault_lookup_missing,
    decode_LookupFault_lookup_ambiguous
} decode_LookupFault;

#ifndef SLOP_LIST_RDF_TERM_DEFINED
#define SLOP_LIST_RDF_TERM_DEFINED
#define SLOP_LIST_RDF_TERM_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_Term, slop_list_rdf_Term)
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

#ifndef SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Omission, slop_list_types_Omission)
#endif

#ifndef SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Node, slop_list_types_Node)
#endif

#ifndef SLOP_LIST_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawConcept, slop_list_owl2_RawConcept)
#endif

#ifndef SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawAxiom, slop_list_owl2_RawAxiom)
#endif

#ifndef SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(types_RoleId, slop_list_types_RoleId)
#endif

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_ENTITYKIND_DEFINED
#define SLOP_OPTION_TYPES_ENTITYKIND_DEFINED
SLOP_OPTION_DEFINE(types_EntityKind, slop_option_types_EntityKind)
#endif

#ifndef SLOP_OPTION_OWL2_PROPCHARACTERISTIC_DEFINED
#define SLOP_OPTION_OWL2_PROPCHARACTERISTIC_DEFINED
SLOP_OPTION_DEFINE(owl2_PropCharacteristic, slop_option_owl2_PropCharacteristic)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

typedef enum {
    decode_ListFault_list_truncated,
    decode_ListFault_list_branching,
    decode_ListFault_list_cyclic
} decode_ListFault_tag;

struct decode_ListFault {
    decode_ListFault_tag tag;
    union {
        slop_string list_truncated;
        slop_string list_branching;
        slop_string list_cyclic;
    } data;
};
typedef struct decode_ListFault decode_ListFault;

#ifndef SLOP_OPTION_DECODE_LISTFAULT_DEFINED
#define SLOP_OPTION_DECODE_LISTFAULT_DEFINED
SLOP_OPTION_DEFINE(decode_ListFault, slop_option_decode_ListFault)
#endif

struct decode_Stage0 {
    slop_list_rdf_Triple triples;
    slop_list_rdf_IRI imports_declared;
    slop_list_types_Omission omissions;
    slop_option_rdf_IRI ontology_iri;
};
typedef struct decode_Stage0 decode_Stage0;

#ifndef SLOP_OPTION_DECODE_STAGE0_DEFINED
#define SLOP_OPTION_DECODE_STAGE0_DEFINED
SLOP_OPTION_DEFINE(decode_Stage0, slop_option_decode_Stage0)
#endif

struct decode_Stage1 {
    slop_list_owl2_RawAxiom axioms;
    owl2_Signature signature;
};
typedef struct decode_Stage1 decode_Stage1;

#ifndef SLOP_OPTION_DECODE_STAGE1_DEFINED
#define SLOP_OPTION_DECODE_STAGE1_DEFINED
SLOP_OPTION_DEFINE(decode_Stage1, slop_option_decode_Stage1)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef RDF_TERM_HASH_EQ_DEFINED
#define RDF_TERM_HASH_EQ_DEFINED
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
        && slop_eq_string(&_a->value, &_b->value)
    ;
}
#endif
#ifndef RDF_BLANKNODE_HASH_EQ_DEFINED
#define RDF_BLANKNODE_HASH_EQ_DEFINED
static inline uint64_t slop_hash_rdf_BlankNode(const void* key) {
    const rdf_BlankNode* _k = (const rdf_BlankNode*)key;
    uint64_t hash = 14695981039346656037ULL;
    { int64_t _tmp = (int64_t)_k->id; hash ^= slop_hash_int(&_tmp); hash *= 1099511628211ULL; }
    return hash;
}
static inline bool slop_eq_rdf_BlankNode(const void* a, const void* b) {
    const rdf_BlankNode* _a = (const rdf_BlankNode*)a;
    const rdf_BlankNode* _b = (const rdf_BlankNode*)b;
    return true
        && _a->id == _b->id
    ;
}
#endif
#ifndef RDF_LITERAL_HASH_EQ_DEFINED
#define RDF_LITERAL_HASH_EQ_DEFINED
static inline uint64_t slop_hash_rdf_Literal(const void* key) {
    const rdf_Literal* _k = (const rdf_Literal*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    { const uint8_t* _b = (const uint8_t*)&_k->datatype; for(size_t _i=0; _i<sizeof(_k->datatype); _i++) { hash ^= _b[_i]; hash *= 1099511628211ULL; } }
    { const uint8_t* _b = (const uint8_t*)&_k->lang; for(size_t _i=0; _i<sizeof(_k->lang); _i++) { hash ^= _b[_i]; hash *= 1099511628211ULL; } }
    return hash;
}
static inline bool slop_eq_rdf_Literal(const void* a, const void* b) {
    const rdf_Literal* _a = (const rdf_Literal*)a;
    const rdf_Literal* _b = (const rdf_Literal*)b;
    return true
        && slop_eq_string(&_a->value, &_b->value)
        && memcmp(&_a->datatype, &_b->datatype, sizeof(_a->datatype)) == 0
        && memcmp(&_a->lang, &_b->lang, sizeof(_a->lang)) == 0
    ;
}
#endif
static inline uint64_t slop_hash_rdf_Term(const void* key) {
    const rdf_Term* _k = (const rdf_Term*)key;
    switch (_k->tag) {
        case rdf_Term_term_iri:
            return slop_hash_rdf_IRI(&_k->data.term_iri);
        case rdf_Term_term_blank:
            return slop_hash_rdf_BlankNode(&_k->data.term_blank);
        case rdf_Term_term_literal:
            return slop_hash_rdf_Literal(&_k->data.term_literal);
        case rdf_Term_term_triple:
            return slop_hash_ptr(&_k->data.term_triple);
    }
    return 0;
}
static inline bool slop_eq_rdf_Term(const void* a, const void* b) {
    const rdf_Term* _a = (const rdf_Term*)a;
    const rdf_Term* _b = (const rdf_Term*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case rdf_Term_term_iri:
            return slop_eq_rdf_IRI(&_a->data.term_iri, &_b->data.term_iri);
        case rdf_Term_term_blank:
            return slop_eq_rdf_BlankNode(&_a->data.term_blank, &_b->data.term_blank);
        case rdf_Term_term_literal:
            return slop_eq_rdf_Literal(&_a->data.term_literal, &_b->data.term_literal);
        case rdf_Term_term_triple:
            return _a->data.term_triple == _b->data.term_triple;
    }
    return false;
}
#endif

#ifndef SLOP_RESULT_RDF_TERM_DECODE_LOOKUPFAULT_DEFINED
#define SLOP_RESULT_RDF_TERM_DECODE_LOOKUPFAULT_DEFINED
typedef struct { bool is_ok; union { rdf_Term ok; decode_LookupFault err; } data; } slop_result_rdf_Term_decode_LookupFault;
#endif

#ifndef SLOP_RESULT_LIST_RDF_TERM_DECODE_LISTFAULT_DEFINED
#define SLOP_RESULT_LIST_RDF_TERM_DECODE_LISTFAULT_DEFINED
typedef struct { bool is_ok; union { slop_list_rdf_Term ok; decode_ListFault err; } data; } slop_result_list_rdf_Term_decode_ListFault;
#endif

#ifndef SLOP_RESULT_DECODE_STAGE0_TYPES_FAULT_DEFINED
#define SLOP_RESULT_DECODE_STAGE0_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { decode_Stage0 ok; types_Fault err; } data; } slop_result_decode_Stage0_types_Fault;
#endif

#ifndef SLOP_RESULT_TYPES_ROLEID_STRING_DEFINED
#define SLOP_RESULT_TYPES_ROLEID_STRING_DEFINED
typedef struct { bool is_ok; union { types_RoleId ok; slop_string err; } data; } slop_result_types_RoleId_string;
#endif

#ifndef SLOP_RESULT_INT_STRING_DEFINED
#define SLOP_RESULT_INT_STRING_DEFINED
typedef struct { bool is_ok; union { int64_t ok; slop_string err; } data; } slop_result_int_string;
#endif

#ifndef SLOP_RESULT_LIST_TYPES_NODE_STRING_DEFINED
#define SLOP_RESULT_LIST_TYPES_NODE_STRING_DEFINED
typedef struct { bool is_ok; union { slop_list_types_Node ok; slop_string err; } data; } slop_result_list_types_Node_string;
#endif

#ifndef SLOP_RESULT_LIST_OWL2_RAWCONCEPT_STRING_DEFINED
#define SLOP_RESULT_LIST_OWL2_RAWCONCEPT_STRING_DEFINED
typedef struct { bool is_ok; union { slop_list_owl2_RawConcept ok; slop_string err; } data; } slop_result_list_owl2_RawConcept_string;
#endif

#ifndef SLOP_RESULT_OWL2_RAWCONCEPT_STRING_DEFINED
#define SLOP_RESULT_OWL2_RAWCONCEPT_STRING_DEFINED
typedef struct { bool is_ok; union { owl2_RawConcept ok; slop_string err; } data; } slop_result_owl2_RawConcept_string;
#endif

#ifndef SLOP_RESULT_LIST_TYPES_ROLEID_STRING_DEFINED
#define SLOP_RESULT_LIST_TYPES_ROLEID_STRING_DEFINED
typedef struct { bool is_ok; union { slop_list_types_RoleId ok; slop_string err; } data; } slop_result_list_types_RoleId_string;
#endif

#ifndef SLOP_RESULT_OWL2_RAWAXIOM_STRING_DEFINED
#define SLOP_RESULT_OWL2_RAWAXIOM_STRING_DEFINED
typedef struct { bool is_ok; union { owl2_RawAxiom ok; slop_string err; } data; } slop_result_owl2_RawAxiom_string;
#endif

#ifndef SLOP_RESULT_DECODE_STAGE1_TYPES_FAULT_DEFINED
#define SLOP_RESULT_DECODE_STAGE1_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { decode_Stage1 ok; types_Fault err; } data; } slop_result_decode_Stage1_types_Fault;
#endif

rdf_Term decode_term_at(slop_list_rdf_Term xs, int64_t i);
rdf_Triple decode_triple_at(slop_list_rdf_Triple xs, int64_t i);
index_IndexedGraph decode_graph_to_indexed(slop_arena* arena, slop_list_rdf_Triple triples);
slop_result_rdf_Term_decode_LookupFault decode_one_object(slop_arena* arena, index_IndexedGraph g, rdf_Term subj, rdf_Term pred);
slop_result_list_rdf_Term_decode_ListFault decode_rdf_list_checked(slop_arena* arena, index_IndexedGraph g, rdf_Term head);
slop_option_rdf_IRI decode_term_iri_value(rdf_Term t);
uint8_t decode_iri_in_list(slop_list_rdf_IRI xs, rdf_IRI target);
slop_list_rdf_IRI decode_collect_imports(slop_arena* arena, slop_list_rdf_Triple triples);
slop_list_types_Omission decode_unresolved_imports(slop_arena* arena, slop_list_rdf_IRI declared, slop_list_rdf_IRI resolved);
slop_list_rdf_Term decode_subjects_of_type(slop_arena* arena, index_IndexedGraph g, slop_string type_iri);
uint8_t decode_typed_as(rdf_Triple t, slop_string type_iri);
slop_list_rdf_Term decode_typed_subjects_in_order(slop_arena* arena, slop_list_rdf_Triple triples, slop_string type_iri);
uint8_t decode_logical_predicate(slop_string pv);
rdf_Triple decode_ex_hdr(slop_string p, slop_string o);
uint8_t decode_header_consumable(rdf_Triple t);
slop_result_decode_Stage0_types_Fault decode_stage0_header(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved);
owl2_RawConcept* decode_box_concept(slop_arena* arena, owl2_RawConcept c);
slop_string decode_list_fault_message(decode_ListFault f);
uint8_t decode_has_pred(slop_arena* arena, index_IndexedGraph g, rdf_Term s, slop_string pred_iri);
slop_result_rdf_Term_decode_LookupFault decode_obj_of(slop_arena* arena, index_IndexedGraph g, rdf_Term s, slop_string pred_iri);
slop_result_types_RoleId_string decode_decode_role(slop_arena* arena, index_IndexedGraph g, rdf_Term b);
uint8_t decode_inverse_expression_term(slop_arena* arena, index_IndexedGraph g, rdf_Term t);
uint8_t decode_restriction_on_inverse(slop_arena* arena, index_IndexedGraph g, rdf_Term b);
uint8_t decode_list_has_inverse(slop_arena* arena, index_IndexedGraph g, rdf_Term head);
uint8_t decode_property_axiom_on_inverse(slop_arena* arena, index_IndexedGraph g, slop_string pv, rdf_Triple t);
slop_result_int_string decode_literal_count(rdf_Term t);
slop_result_list_types_Node_string decode_decode_node_list(slop_arena* arena, index_IndexedGraph g, rdf_Term head);
slop_result_list_owl2_RawConcept_string decode_decode_concept_list(slop_arena* arena, index_IndexedGraph g, rdf_Term head, int64_t fuel);
slop_result_owl2_RawConcept_string decode_decode_quantified(slop_arena* arena, index_IndexedGraph g, rdf_Term b, slop_string filler_pred, uint8_t universal, int64_t fuel);
slop_result_owl2_RawConcept_string decode_decode_cardinality(slop_arena* arena, index_IndexedGraph g, rdf_Term b, owl2_CardKind kind, slop_string count_pred, uint8_t qualified, int64_t fuel);
slop_result_owl2_RawConcept_string decode_decode_anon(slop_arena* arena, index_IndexedGraph g, rdf_Term b, int64_t fuel);
slop_result_owl2_RawConcept_string decode_decode_concept(slop_arena* arena, index_IndexedGraph g, rdf_Term t, int64_t fuel);
uint8_t decode_declare_entity(slop_arena* arena, owl2_Signature sig, rdf_IRI entity, slop_string type_iri);
uint8_t decode_add_builtins(slop_arena* arena, owl2_Signature sig);
owl2_Signature decode_build_signature(slop_arena* arena, slop_list_rdf_Triple triples);
slop_string decode_render_term(slop_arena* arena, rdf_Term t);
slop_string decode_render_triple(slop_arena* arena, rdf_Triple t);
types_InputRef decode_frag(slop_arena* arena, rdf_Triple t);
uint8_t decode_is_pred(rdf_Triple t, slop_string iri);
uint8_t decode_structural_predicate(slop_string p);
uint8_t decode_structural_triple(rdf_Triple t);
slop_option_types_EntityKind decode_entity_kind_of(slop_string type_iri);
slop_option_owl2_PropCharacteristic decode_characteristic_of(slop_string type_iri);
slop_option_types_RoleId decode_role_of_term(rdf_Term t);
slop_result_list_types_RoleId_string decode_decode_role_list(slop_arena* arena, index_IndexedGraph g, rdf_Term head);
slop_result_list_owl2_RawConcept_string decode_binary_concepts(slop_arena* arena, index_IndexedGraph g, rdf_Triple t);
slop_option_rdf_Term decode_members_head(slop_arena* arena, index_IndexedGraph g, rdf_Term s);
slop_result_owl2_RawAxiom_string decode_decode_typed(slop_arena* arena, index_IndexedGraph g, rdf_Triple t, rdf_IRI obj);
slop_result_owl2_RawAxiom_string decode_decode_class_assertion(slop_arena* arena, index_IndexedGraph g, rdf_Triple t);
uint8_t decode_is_reserved_iri(slop_string v);
int64_t decode_property_axiom_kind(owl2_Signature sig, rdf_Term subj);
slop_result_owl2_RawAxiom_string decode_decode_axiom(slop_arena* arena, index_IndexedGraph g, owl2_Signature sig, rdf_Triple t);
slop_result_decode_Stage1_types_Fault decode_decode_axioms(slop_arena* arena, slop_list_rdf_Triple triples);
slop_option_string decode_declaration_conflict(slop_arena* arena, owl2_Signature sig, slop_list_rdf_Triple triples);

#define decode_CONCEPT_FUEL (64)

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

#ifndef SLOP_OPTION_DECODE_LISTFAULT_DEFINED
#define SLOP_OPTION_DECODE_LISTFAULT_DEFINED
SLOP_OPTION_DEFINE(decode_ListFault, slop_option_decode_ListFault)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

#ifndef SLOP_OPTION_DECODE_STAGE0_DEFINED
#define SLOP_OPTION_DECODE_STAGE0_DEFINED
SLOP_OPTION_DEFINE(decode_Stage0, slop_option_decode_Stage0)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_DECODE_STAGE1_DEFINED
#define SLOP_OPTION_DECODE_STAGE1_DEFINED
SLOP_OPTION_DEFINE(decode_Stage1, slop_option_decode_Stage1)
#endif

#ifndef SLOP_OPTION_TYPES_ENTITYKIND_DEFINED
#define SLOP_OPTION_TYPES_ENTITYKIND_DEFINED
SLOP_OPTION_DEFINE(types_EntityKind, slop_option_types_EntityKind)
#endif

#ifndef SLOP_OPTION_OWL2_PROPCHARACTERISTIC_DEFINED
#define SLOP_OPTION_OWL2_PROPCHARACTERISTIC_DEFINED
SLOP_OPTION_DEFINE(owl2_PropCharacteristic, slop_option_owl2_PropCharacteristic)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif


#endif
