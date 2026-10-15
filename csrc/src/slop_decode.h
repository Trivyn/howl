#ifndef SLOP_decode_H
#define SLOP_decode_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_termstore.h"
#include "slop_vocab.h"
#include "slop_owl2.h"
#include "slop_types.h"
#include "slop_strlib.h"
#include "slop_canon.h"

typedef struct howl_decode_ListFault howl_decode_ListFault;
typedef struct howl_decode_Stage0 howl_decode_Stage0;
typedef struct howl_decode_Rebuilt howl_decode_Rebuilt;
typedef struct howl_decode_IndividualTerm howl_decode_IndividualTerm;
typedef struct howl_decode_NodeList howl_decode_NodeList;
typedef struct howl_decode_Stage1 howl_decode_Stage1;
typedef struct howl_decode_Decoding howl_decode_Decoding;
typedef struct howl_decode_DataVocab howl_decode_DataVocab;
typedef struct howl_decode_DataLemma howl_decode_DataLemma;

typedef enum {
    howl_decode_LookupFault_lookup_missing,
    howl_decode_LookupFault_lookup_ambiguous
} howl_decode_LookupFault;

#ifndef SLOP_LIST_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TERM_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_Term, slop_list_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TRIPLE_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_Triple, slop_list_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_LIST_HOWL_TERMSTORE_IDTRIPLE_DEFINED
#define SLOP_LIST_HOWL_TERMSTORE_IDTRIPLE_DEFINED
#define SLOP_LIST_HOWL_TERMSTORE_IDTRIPLE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_termstore_IdTriple, slop_list_howl_termstore_IdTriple)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Omission, slop_list_howl_types_Omission)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Node, slop_list_howl_types_Node)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawConcept, slop_list_howl_owl2_RawConcept)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawAxiom, slop_list_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_RoleId, slop_list_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Triple, slop_option_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_OPTION_HOWL_TERMSTORE_IDTRIPLE_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_IDTRIPLE_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_IdTriple, slop_option_howl_termstore_IdTriple)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ENTITYKIND_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ENTITYKIND_DEFINED
SLOP_OPTION_DEFINE(howl_types_EntityKind, slop_option_howl_types_EntityKind)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_PROPCHARACTERISTIC_DEFINED
#define SLOP_OPTION_HOWL_OWL2_PROPCHARACTERISTIC_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_PropCharacteristic, slop_option_howl_owl2_PropCharacteristic)
#endif

typedef enum {
    howl_decode_ListFault_list_truncated,
    howl_decode_ListFault_list_branching,
    howl_decode_ListFault_list_cyclic
} howl_decode_ListFault_tag;

struct howl_decode_ListFault {
    howl_decode_ListFault_tag tag;
    union {
        slop_string list_truncated;
        slop_string list_branching;
        slop_string list_cyclic;
    } data;
};
typedef struct howl_decode_ListFault howl_decode_ListFault;

#ifndef SLOP_OPTION_HOWL_DECODE_LISTFAULT_DEFINED
#define SLOP_OPTION_HOWL_DECODE_LISTFAULT_DEFINED
SLOP_OPTION_DEFINE(howl_decode_ListFault, slop_option_howl_decode_ListFault)
#endif

struct howl_decode_Stage0 {
    howl_termstore_TermStore dict;
    slop_list_howl_termstore_IdTriple triples;
    slop_list_slop_rdf_rdf_IRI imports_declared;
    slop_list_howl_types_Omission omissions;
    slop_option_slop_rdf_rdf_IRI ontology_iri;
    slop_list_int docs;
    slop_list_int omission_docs;
};
typedef struct howl_decode_Stage0 howl_decode_Stage0;

#ifndef SLOP_OPTION_HOWL_DECODE_STAGE0_DEFINED
#define SLOP_OPTION_HOWL_DECODE_STAGE0_DEFINED
SLOP_OPTION_DEFINE(howl_decode_Stage0, slop_option_howl_decode_Stage0)
#endif

struct howl_decode_Rebuilt {
    slop_list_howl_termstore_IdTriple triples;
    slop_list_int docs;
    slop_option_string fault;
};
typedef struct howl_decode_Rebuilt howl_decode_Rebuilt;

#ifndef SLOP_OPTION_HOWL_DECODE_REBUILT_DEFINED
#define SLOP_OPTION_HOWL_DECODE_REBUILT_DEFINED
SLOP_OPTION_DEFINE(howl_decode_Rebuilt, slop_option_howl_decode_Rebuilt)
#endif

typedef enum {
    howl_decode_IndividualTerm_named_individual,
    howl_decode_IndividualTerm_literal_individual,
    howl_decode_IndividualTerm_anonymous_individual,
    howl_decode_IndividualTerm_reserved_individual
} howl_decode_IndividualTerm_tag;

struct howl_decode_IndividualTerm {
    howl_decode_IndividualTerm_tag tag;
    union {
        slop_rdf_rdf_IRI named_individual;
    } data;
};
typedef struct howl_decode_IndividualTerm howl_decode_IndividualTerm;

#ifndef SLOP_OPTION_HOWL_DECODE_INDIVIDUALTERM_DEFINED
#define SLOP_OPTION_HOWL_DECODE_INDIVIDUALTERM_DEFINED
SLOP_OPTION_DEFINE(howl_decode_IndividualTerm, slop_option_howl_decode_IndividualTerm)
#endif

typedef enum {
    howl_decode_NodeList_all_named,
    howl_decode_NodeList_has_literal,
    howl_decode_NodeList_has_anonymous,
    howl_decode_NodeList_has_reserved
} howl_decode_NodeList_tag;

struct howl_decode_NodeList {
    howl_decode_NodeList_tag tag;
    union {
        slop_list_howl_types_Node all_named;
    } data;
};
typedef struct howl_decode_NodeList howl_decode_NodeList;

#ifndef SLOP_OPTION_HOWL_DECODE_NODELIST_DEFINED
#define SLOP_OPTION_HOWL_DECODE_NODELIST_DEFINED
SLOP_OPTION_DEFINE(howl_decode_NodeList, slop_option_howl_decode_NodeList)
#endif

struct howl_decode_Stage1 {
    slop_list_howl_owl2_RawAxiom axioms;
    howl_owl2_Signature signature;
    int64_t inert;
    slop_list_howl_types_Omission omitted;
    slop_list_int axiom_docs;
    slop_list_int omission_docs;
};
typedef struct howl_decode_Stage1 howl_decode_Stage1;

#ifndef SLOP_OPTION_HOWL_DECODE_STAGE1_DEFINED
#define SLOP_OPTION_HOWL_DECODE_STAGE1_DEFINED
SLOP_OPTION_DEFINE(howl_decode_Stage1, slop_option_howl_decode_Stage1)
#endif

struct howl_decode_DataVocab {
    int64_t rdf_type;
    int64_t data_property;
    int64_t functional;
    int64_t domain;
    int64_t range;
    int64_t sub_property;
    int64_t equivalent;
    int64_t disjoint;
    int64_t top;
    int64_t on_datatype;
};
typedef struct howl_decode_DataVocab howl_decode_DataVocab;

#ifndef SLOP_OPTION_HOWL_DECODE_DATAVOCAB_DEFINED
#define SLOP_OPTION_HOWL_DECODE_DATAVOCAB_DEFINED
SLOP_OPTION_DEFINE(howl_decode_DataVocab, slop_option_howl_decode_DataVocab)
#endif

struct howl_decode_DataLemma {
    slop_map* data;
    slop_map* idle;
    slop_map* tree;
};
typedef struct howl_decode_DataLemma howl_decode_DataLemma;

#ifndef SLOP_OPTION_HOWL_DECODE_DATALEMMA_DEFINED
#define SLOP_OPTION_HOWL_DECODE_DATALEMMA_DEFINED
SLOP_OPTION_DEFINE(howl_decode_DataLemma, slop_option_howl_decode_DataLemma)
#endif

struct howl_decode_Decoding {
    howl_termstore_TermStore ig;
    howl_owl2_Signature sig;
    howl_decode_DataVocab dv;
    howl_decode_DataLemma lemma;
    slop_map* npa_nodes;
    slop_map* npa_parts;
    slop_list_howl_owl2_RawAxiom out;
    int64_t inert;
    slop_list_slop_rdf_rdf_IRI uprops;
    slop_list_string utexts;
    slop_option_string fault;
    slop_list_int docs;
    int64_t pos;
    slop_list_int adocs;
    slop_list_int udocs;
};
typedef struct howl_decode_Decoding howl_decode_Decoding;

#ifndef SLOP_OPTION_HOWL_DECODE_DECODING_DEFINED
#define SLOP_OPTION_HOWL_DECODE_DECODING_DEFINED
SLOP_OPTION_DEFINE(howl_decode_Decoding, slop_option_howl_decode_Decoding)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef SLOP_RDF_RDF_TERM_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_TERM_HASH_EQ_DEFINED
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
#ifndef SLOP_RDF_RDF_BLANKNODE_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_BLANKNODE_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_BlankNode(const void* key) {
    const slop_rdf_rdf_BlankNode* _k = (const slop_rdf_rdf_BlankNode*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&(int64_t){ (int64_t)_k->id }); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_BlankNode(const void* a, const void* b) {
    const slop_rdf_rdf_BlankNode* _a = (const slop_rdf_rdf_BlankNode*)a;
    const slop_rdf_rdf_BlankNode* _b = (const slop_rdf_rdf_BlankNode*)b;
    return true
        && (_a->id == _b->id)
    ;
}
#endif
#ifndef SLOP_RDF_RDF_LITERAL_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_LITERAL_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_Literal(const void* key) {
    const slop_rdf_rdf_Literal* _k = (const slop_rdf_rdf_Literal*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    hash ^= ((_k->datatype).has_value ? slop_hash_combine(1, slop_hash_string(&(_k->datatype).value)) : 0); hash *= 1099511628211ULL;
    hash ^= ((_k->lang).has_value ? slop_hash_combine(1, slop_hash_string(&(_k->lang).value)) : 0); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_Literal(const void* a, const void* b) {
    const slop_rdf_rdf_Literal* _a = (const slop_rdf_rdf_Literal*)a;
    const slop_rdf_rdf_Literal* _b = (const slop_rdf_rdf_Literal*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
        && ((_a->datatype).has_value == (_b->datatype).has_value && (!(_a->datatype).has_value || ((slop_eq_string(&(_a->datatype).value, &(_b->datatype).value)))))
        && ((_a->lang).has_value == (_b->lang).has_value && (!(_a->lang).has_value || ((slop_eq_string(&(_a->lang).value, &(_b->lang).value)))))
    ;
}
#endif
static inline uint64_t slop_hash_slop_rdf_rdf_Term(const void* key) {
    const slop_rdf_rdf_Term* _k = (const slop_rdf_rdf_Term*)key;
    switch (_k->tag) {
        case slop_rdf_rdf_Term_term_iri:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.term_iri);
        case slop_rdf_rdf_Term_term_blank:
            return slop_hash_slop_rdf_rdf_BlankNode(&_k->data.term_blank);
        case slop_rdf_rdf_Term_term_literal:
            return slop_hash_slop_rdf_rdf_Literal(&_k->data.term_literal);
        case slop_rdf_rdf_Term_term_triple:
            return slop_hash_ptr(&_k->data.term_triple);
    }
    return 0;
}
static inline bool slop_eq_slop_rdf_rdf_Term(const void* a, const void* b) {
    const slop_rdf_rdf_Term* _a = (const slop_rdf_rdf_Term*)a;
    const slop_rdf_rdf_Term* _b = (const slop_rdf_rdf_Term*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case slop_rdf_rdf_Term_term_iri:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.term_iri, &_b->data.term_iri);
        case slop_rdf_rdf_Term_term_blank:
            return slop_eq_slop_rdf_rdf_BlankNode(&_a->data.term_blank, &_b->data.term_blank);
        case slop_rdf_rdf_Term_term_literal:
            return slop_eq_slop_rdf_rdf_Literal(&_a->data.term_literal, &_b->data.term_literal);
        case slop_rdf_rdf_Term_term_triple:
            return _a->data.term_triple == _b->data.term_triple;
    }
    return false;
}
#endif

#ifndef HOWL_TERMSTORE_IDTRIPLE_HASH_EQ_DEFINED
#define HOWL_TERMSTORE_IDTRIPLE_HASH_EQ_DEFINED
static inline uint64_t slop_hash_howl_termstore_IdTriple(const void* key) {
    const howl_termstore_IdTriple* _k = (const howl_termstore_IdTriple*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&_k->s); hash *= 1099511628211ULL;
    hash ^= slop_hash_int(&_k->p); hash *= 1099511628211ULL;
    hash ^= slop_hash_int(&_k->o); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_howl_termstore_IdTriple(const void* a, const void* b) {
    const howl_termstore_IdTriple* _a = (const howl_termstore_IdTriple*)a;
    const howl_termstore_IdTriple* _b = (const howl_termstore_IdTriple*)b;
    return true
        && (_a->s == _b->s)
        && (_a->p == _b->p)
        && (_a->o == _b->o)
    ;
}
#endif

#ifndef SLOP_RESULT_SLOP_RDF_RDF_TERM_HOWL_DECODE_LOOKUPFAULT_DEFINED
#define SLOP_RESULT_SLOP_RDF_RDF_TERM_HOWL_DECODE_LOOKUPFAULT_DEFINED
typedef struct { bool is_ok; union { slop_rdf_rdf_Term ok; howl_decode_LookupFault err; } data; } slop_result_slop_rdf_rdf_Term_howl_decode_LookupFault;
#endif

#ifndef SLOP_RESULT_LIST_SLOP_RDF_RDF_TERM_HOWL_DECODE_LISTFAULT_DEFINED
#define SLOP_RESULT_LIST_SLOP_RDF_RDF_TERM_HOWL_DECODE_LISTFAULT_DEFINED
typedef struct { bool is_ok; union { slop_list_slop_rdf_rdf_Term ok; howl_decode_ListFault err; } data; } slop_result_list_slop_rdf_rdf_Term_howl_decode_ListFault;
#endif

#ifndef SLOP_RESULT_HOWL_DECODE_STAGE0_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_DECODE_STAGE0_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_decode_Stage0 ok; howl_types_Fault err; } data; } slop_result_howl_decode_Stage0_howl_types_Fault;
#endif

#ifndef SLOP_RESULT_HOWL_TERMSTORE_IDTRIPLE_STRING_DEFINED
#define SLOP_RESULT_HOWL_TERMSTORE_IDTRIPLE_STRING_DEFINED
typedef struct { bool is_ok; union { howl_termstore_IdTriple ok; slop_string err; } data; } slop_result_howl_termstore_IdTriple_string;
#endif

#ifndef SLOP_RESULT_HOWL_TYPES_ROLEID_STRING_DEFINED
#define SLOP_RESULT_HOWL_TYPES_ROLEID_STRING_DEFINED
typedef struct { bool is_ok; union { howl_types_RoleId ok; slop_string err; } data; } slop_result_howl_types_RoleId_string;
#endif

#ifndef SLOP_RESULT_INT_STRING_DEFINED
#define SLOP_RESULT_INT_STRING_DEFINED
typedef struct { bool is_ok; union { int64_t ok; slop_string err; } data; } slop_result_int_string;
#endif

#ifndef SLOP_RESULT_HOWL_DECODE_NODELIST_STRING_DEFINED
#define SLOP_RESULT_HOWL_DECODE_NODELIST_STRING_DEFINED
typedef struct { bool is_ok; union { howl_decode_NodeList ok; slop_string err; } data; } slop_result_howl_decode_NodeList_string;
#endif

#ifndef SLOP_RESULT_LIST_HOWL_OWL2_RAWCONCEPT_STRING_DEFINED
#define SLOP_RESULT_LIST_HOWL_OWL2_RAWCONCEPT_STRING_DEFINED
typedef struct { bool is_ok; union { slop_list_howl_owl2_RawConcept ok; slop_string err; } data; } slop_result_list_howl_owl2_RawConcept_string;
#endif

#ifndef SLOP_RESULT_HOWL_OWL2_RAWCONCEPT_STRING_DEFINED
#define SLOP_RESULT_HOWL_OWL2_RAWCONCEPT_STRING_DEFINED
typedef struct { bool is_ok; union { howl_owl2_RawConcept ok; slop_string err; } data; } slop_result_howl_owl2_RawConcept_string;
#endif

#ifndef SLOP_RESULT_LIST_HOWL_TYPES_ROLEID_STRING_DEFINED
#define SLOP_RESULT_LIST_HOWL_TYPES_ROLEID_STRING_DEFINED
typedef struct { bool is_ok; union { slop_list_howl_types_RoleId ok; slop_string err; } data; } slop_result_list_howl_types_RoleId_string;
#endif

#ifndef SLOP_RESULT_HOWL_OWL2_RAWAXIOM_STRING_DEFINED
#define SLOP_RESULT_HOWL_OWL2_RAWAXIOM_STRING_DEFINED
typedef struct { bool is_ok; union { howl_owl2_RawAxiom ok; slop_string err; } data; } slop_result_howl_owl2_RawAxiom_string;
#endif

#ifndef SLOP_RESULT_HOWL_DECODE_STAGE1_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_DECODE_STAGE1_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_decode_Stage1 ok; howl_types_Fault err; } data; } slop_result_howl_decode_Stage1_howl_types_Fault;
#endif

slop_rdf_rdf_Term howl_decode_term_at(slop_list_slop_rdf_rdf_Term xs, int64_t i);
slop_rdf_rdf_Triple howl_decode_triple_at(slop_list_slop_rdf_rdf_Triple xs, int64_t i);
howl_termstore_TermStore howl_decode_graph_to_indexed(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples);
slop_result_slop_rdf_rdf_Term_howl_decode_LookupFault howl_decode_one_object(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term subj, slop_rdf_rdf_Term pred);
slop_option_howl_decode_ListFault howl_decode_cell_fault(int64_t nf, int64_t nr);
slop_result_list_slop_rdf_rdf_Term_howl_decode_ListFault howl_decode_rdf_list_checked(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term head);
slop_option_slop_rdf_rdf_IRI howl_decode_term_iri_value(slop_rdf_rdf_Term t);
uint8_t howl_decode_iri_in_list(slop_list_slop_rdf_rdf_IRI xs, slop_rdf_rdf_IRI target);
slop_list_slop_rdf_rdf_IRI howl_decode_collect_imports(slop_arena* arena, howl_termstore_Encoded doc);
int64_t howl_decode_vocab_id(slop_arena* arena, howl_termstore_TermStore dict, slop_string iri);
slop_list_howl_types_Omission howl_decode_unresolved_imports(slop_arena* arena, slop_list_slop_rdf_rdf_IRI declared, slop_list_slop_rdf_rdf_IRI resolved);
uint8_t howl_decode_typed_as(slop_rdf_rdf_Triple t, slop_string type_iri);
slop_list_int howl_decode_typed_ids_in_order(slop_arena* arena, howl_termstore_Encoded doc, slop_string type_iri);
slop_list_int howl_decode_typed_docs_in_order(slop_arena* arena, howl_termstore_Encoded doc, slop_string type_iri);
int64_t howl_decode_import_doc(slop_arena* arena, howl_termstore_Encoded doc, slop_rdf_rdf_IRI target);
slop_list_int howl_decode_import_docs(slop_arena* arena, howl_termstore_Encoded doc, slop_list_howl_types_Omission oms);
uint8_t howl_decode_logical_predicate(slop_string pv);
slop_rdf_rdf_Triple howl_decode_ex_hdr(slop_string p, slop_string o);
uint8_t howl_decode_header_consumable(slop_rdf_rdf_Triple t);
slop_result_howl_decode_Stage0_howl_types_Fault howl_decode_stage0_header(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples, slop_list_slop_rdf_rdf_IRI imports_resolved);
slop_result_howl_decode_Stage0_howl_types_Fault howl_decode_stage0_encoded(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved);
slop_map* howl_decode_id_set(slop_arena* arena, slop_list_int a, slop_list_int b, slop_list_int c);
howl_termstore_TermStore howl_decode_annotated_store(slop_arena* arena, howl_termstore_Encoded doc);
int64_t howl_decode_term_id(howl_termstore_TermStore st, slop_rdf_rdf_Term t);
slop_result_howl_termstore_IdTriple_string howl_decode_rebuild_one(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Term a, slop_rdf_rdf_Term src_pred, slop_rdf_rdf_Term prop_pred, slop_rdf_rdf_Term tgt_pred);
howl_decode_Rebuilt howl_decode_rebuild_candidates(slop_arena* arena, howl_termstore_TermStore st, slop_list_int ax_subjs, slop_list_int ax_docs);
slop_map* howl_decode_asserted_among(slop_arena* arena, slop_list_howl_termstore_IdTriple candidates, howl_termstore_Encoded doc);
slop_result_howl_decode_Stage0_howl_types_Fault howl_decode_stage0_scan(slop_arena* arena, slop_arena* scratch, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports_resolved);
howl_owl2_RawConcept* howl_decode_box_concept(slop_arena* arena, howl_owl2_RawConcept c);
slop_string howl_decode_list_fault_message(howl_decode_ListFault f);
uint8_t howl_decode_has_pred(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term s, slop_string pred_iri);
slop_result_slop_rdf_rdf_Term_howl_decode_LookupFault howl_decode_obj_of(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term s, slop_string pred_iri);
slop_result_howl_types_RoleId_string howl_decode_decode_role(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b);
slop_option_howl_types_RoleId howl_decode_property_expression(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term t);
uint8_t howl_decode_malformed_inverse(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
uint8_t howl_decode_data_property_term(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term t);
uint8_t howl_decode_restriction_on_data(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b);
slop_string howl_decode_data_restriction_pred(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b);
slop_string howl_decode_data_restriction_name(slop_string pred);
slop_string howl_decode_filler_text(slop_arena* arena, slop_rdf_rdf_Term t);
slop_string howl_decode_terms_text(slop_arena* arena, slop_list_slop_rdf_rdf_Term terms);
slop_string howl_decode_on_properties_text(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b);
slop_string howl_decode_nary_text(slop_arena* arena, slop_string name, slop_string props, slop_string fill);
howl_owl2_RawConcept howl_decode_nary_data_restriction(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b);
howl_owl2_RawConcept howl_decode_data_restriction(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b);
slop_result_int_string howl_decode_literal_count(slop_rdf_rdf_Term t);
howl_decode_IndividualTerm howl_decode_individual_term(slop_rdf_rdf_Term tm);
slop_result_howl_decode_NodeList_string howl_decode_decode_node_list(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term head);
slop_result_list_howl_owl2_RawConcept_string howl_decode_decode_concept_list(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term head, int64_t fuel);
slop_result_howl_owl2_RawConcept_string howl_decode_decode_quantified(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b, slop_string filler_pred, uint8_t universal, int64_t fuel);
slop_result_int_string howl_decode_cardinality_count(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b, slop_string count_pred);
slop_result_howl_owl2_RawConcept_string howl_decode_qualified_cardinality(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b, howl_owl2_CardKind kind, howl_types_RoleId r, int64_t n, int64_t fuel);
slop_result_howl_owl2_RawConcept_string howl_decode_decode_cardinality(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b, howl_owl2_CardKind kind, slop_string count_pred, uint8_t qualified, int64_t fuel);
slop_result_howl_owl2_RawConcept_string howl_decode_decode_anon(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term b, int64_t fuel);
slop_result_howl_owl2_RawConcept_string howl_decode_decode_concept(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term t, int64_t fuel);
uint8_t howl_decode_declare_entity(slop_arena* arena, howl_owl2_Signature sig, slop_rdf_rdf_IRI entity, slop_string type_iri);
uint8_t howl_decode_add_builtins(slop_arena* arena, howl_owl2_Signature sig);
howl_owl2_Signature howl_decode_build_signature(slop_arena* arena, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples);
slop_string howl_decode_render_term(slop_arena* arena, slop_rdf_rdf_Term t);
slop_string howl_decode_nt_escape(slop_arena* arena, slop_string s);
slop_string howl_decode_render_triple(slop_arena* arena, slop_rdf_rdf_Triple t);
howl_types_InputRef howl_decode_frag(slop_arena* arena, slop_rdf_rdf_Triple t);
uint8_t howl_decode_is_pred(slop_rdf_rdf_Triple t, slop_string iri);
uint8_t howl_decode_structural_predicate(slop_string p);
uint8_t howl_decode_structural_triple(slop_rdf_rdf_Triple t);
slop_option_howl_types_EntityKind howl_decode_entity_kind_of(slop_string type_iri);
slop_option_howl_owl2_PropCharacteristic howl_decode_characteristic_of(slop_string type_iri);
slop_option_howl_types_RoleId howl_decode_role_of_term(slop_rdf_rdf_Term t);
slop_result_list_howl_types_RoleId_string howl_decode_decode_role_list(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term head);
uint8_t howl_decode_list_has_data(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term head);
slop_result_list_howl_owl2_RawConcept_string howl_decode_binary_concepts(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_option_slop_rdf_rdf_Term howl_decode_members_head(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Term s);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_declaration(slop_arena* arena, slop_rdf_rdf_Triple t, howl_types_EntityKind k);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_all_different(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_all_disjoint_classes(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_all_disjoint_properties(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_typed(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t, slop_rdf_rdf_IRI obj);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_individual_pair(slop_arena* arena, slop_rdf_rdf_Triple t, uint8_t same);
slop_result_howl_owl2_RawAxiom_string howl_decode_negative_object_assertion(slop_arena* arena, slop_rdf_rdf_Triple t, howl_types_RoleId r, slop_rdf_rdf_Term st, slop_rdf_rdf_Term tt);
slop_result_howl_owl2_RawAxiom_string howl_decode_negative_target_individual(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t, slop_rdf_rdf_Term pt, slop_rdf_rdf_Term st);
slop_result_howl_owl2_RawAxiom_string howl_decode_negative_target(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t, slop_rdf_rdf_Term pt, slop_rdf_rdf_Term st);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_negative_assertion(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_class_assertion(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
uint8_t howl_decode_is_reserved_iri(slop_string v);
int64_t howl_decode_property_axiom_kind(howl_owl2_Signature sig, slop_rdf_rdf_Term subj);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_sub_class_of(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_property_chain(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_sub_property(slop_arena* arena, howl_termstore_TermStore g, howl_owl2_Signature sig, slop_rdf_rdf_Triple t);
slop_result_list_howl_types_RoleId_string howl_decode_property_pair(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t, slop_string pred);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_inverse_of(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_domain(slop_arena* arena, howl_termstore_TermStore g, howl_owl2_Signature sig, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_range(slop_arena* arena, howl_termstore_TermStore g, howl_owl2_Signature sig, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_disjoint_union(slop_arena* arena, howl_termstore_TermStore g, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_assertion_between(slop_arena* arena, slop_rdf_rdf_Triple t, howl_types_RoleId r, slop_rdf_rdf_IRI sfrom, slop_rdf_rdf_IRI sto);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_property_assertion(slop_arena* arena, slop_rdf_rdf_Triple t);
slop_result_howl_owl2_RawAxiom_string howl_decode_list_axiom(slop_result_list_howl_owl2_RawConcept_string r, uint8_t disjoint);
slop_result_howl_owl2_RawAxiom_string howl_decode_pair_axiom(slop_result_list_howl_types_RoleId_string r, uint8_t disjoint);
slop_result_howl_owl2_RawAxiom_string howl_decode_decode_axiom(slop_arena* arena, howl_termstore_TermStore g, howl_owl2_Signature sig, slop_rdf_rdf_Triple t);
slop_result_howl_decode_Stage1_howl_types_Fault howl_decode_decode_axioms(slop_arena* arena, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples);
slop_result_howl_decode_Stage1_howl_types_Fault howl_decode_decode_axioms_sourced(slop_arena* arena, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples, slop_list_int docs);
howl_termstore_TermStore howl_decode_decode_store(slop_arena* arena, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples);
slop_list_string howl_decode_queried_predicates(slop_arena* arena);
void howl_decode_push_axiom(howl_decode_Decoding* c, howl_owl2_RawAxiom ax);
uint8_t howl_decode_keep_axiom(howl_decode_Decoding* c, howl_owl2_RawAxiom ax);
uint8_t howl_decode_decode_triple(slop_arena* arena, howl_decode_Decoding* c, howl_termstore_IdTriple it, slop_rdf_rdf_Triple t);
slop_result_howl_decode_Stage1_howl_types_Fault howl_decode_decode_axioms_with(slop_arena* arena, howl_termstore_TermStore ig, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples, slop_list_int docs);
slop_list_int howl_decode_undeclared_docs(slop_arena* arena, slop_list_slop_rdf_rdf_IRI ps, slop_list_int docs, slop_list_howl_types_Omission oms);
slop_option_slop_rdf_rdf_IRI howl_decode_undeclared_predicate(howl_owl2_Signature sig, slop_rdf_rdf_Triple t);
slop_list_howl_types_Omission howl_decode_undeclared_omissions(slop_arena* arena, slop_list_slop_rdf_rdf_IRI ps, slop_list_string texts);
howl_types_Omission howl_decode_undeclared_of(slop_rdf_rdf_IRI p, slop_list_string refs);
howl_decode_DataVocab howl_decode_data_vocab(slop_arena* arena, howl_termstore_TermStore dict);
uint8_t howl_decode_promote_use(howl_decode_DataVocab v, slop_map* used, howl_termstore_IdTriple it);
uint8_t howl_decode_promote_uses(howl_decode_DataVocab v, slop_map* data, slop_map* used, slop_list_howl_termstore_IdTriple triples);
void howl_decode_collect_idle(howl_decode_DataVocab v, slop_map* used, slop_map* idle, int64_t bottom, slop_list_howl_termstore_IdTriple triples);
howl_decode_DataLemma howl_decode_data_lemma(slop_arena* arena, howl_termstore_TermStore dict, howl_owl2_Signature sig, howl_decode_DataVocab v, slop_list_howl_termstore_IdTriple triples);
void howl_decode_mark_data_uses(howl_termstore_TermStore dict, howl_owl2_Signature sig, howl_decode_DataVocab v, slop_map* data, slop_map* used, howl_termstore_IdTriple it);
uint8_t howl_decode_predicate_is_annotation(howl_termstore_TermStore dict, howl_owl2_Signature sig, int64_t p);
void howl_decode_collect_inert_trees(slop_arena* arena, howl_termstore_TermStore dict, howl_decode_DataVocab v, slop_map* idle, slop_map* tree, slop_list_howl_termstore_IdTriple triples);
uint8_t howl_decode_filler_triple(slop_rdf_rdf_Triple t, uint8_t restriction, uint8_t single);
uint8_t howl_decode_id_is_blank(howl_termstore_TermStore dict, int64_t id);
uint8_t howl_decode_inert_data_axiom(howl_decode_DataVocab v, howl_decode_DataLemma lemma, howl_termstore_IdTriple it);
slop_map* howl_decode_negative_assertion_nodes(slop_arena* arena, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples);
slop_map* howl_decode_negative_assertion_parts(slop_arena* arena, howl_termstore_TermStore dict);
uint8_t howl_decode_negative_assertion_part(howl_termstore_IdTriple it, slop_map* nodes, slop_map* parts);
int64_t howl_decode_property_kinds(howl_owl2_Signature sig, slop_rdf_rdf_IRI e);
slop_option_string howl_decode_declaration_conflict(slop_arena* arena, howl_owl2_Signature sig, howl_termstore_TermStore dict, slop_list_howl_termstore_IdTriple triples);

#define howl_decode_CONCEPT_FUEL (64)

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Triple, slop_option_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_OPTION_HOWL_DECODE_LISTFAULT_DEFINED
#define SLOP_OPTION_HOWL_DECODE_LISTFAULT_DEFINED
SLOP_OPTION_DEFINE(howl_decode_ListFault, slop_option_howl_decode_ListFault)
#endif

#ifndef SLOP_OPTION_HOWL_TERMSTORE_IDTRIPLE_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_IDTRIPLE_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_IdTriple, slop_option_howl_termstore_IdTriple)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_HOWL_DECODE_STAGE0_DEFINED
#define SLOP_OPTION_HOWL_DECODE_STAGE0_DEFINED
SLOP_OPTION_DEFINE(howl_decode_Stage0, slop_option_howl_decode_Stage0)
#endif

#ifndef SLOP_OPTION_HOWL_DECODE_REBUILT_DEFINED
#define SLOP_OPTION_HOWL_DECODE_REBUILT_DEFINED
SLOP_OPTION_DEFINE(howl_decode_Rebuilt, slop_option_howl_decode_Rebuilt)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_DECODE_INDIVIDUALTERM_DEFINED
#define SLOP_OPTION_HOWL_DECODE_INDIVIDUALTERM_DEFINED
SLOP_OPTION_DEFINE(howl_decode_IndividualTerm, slop_option_howl_decode_IndividualTerm)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_DECODE_NODELIST_DEFINED
#define SLOP_OPTION_HOWL_DECODE_NODELIST_DEFINED
SLOP_OPTION_DEFINE(howl_decode_NodeList, slop_option_howl_decode_NodeList)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_DECODE_STAGE1_DEFINED
#define SLOP_OPTION_HOWL_DECODE_STAGE1_DEFINED
SLOP_OPTION_DEFINE(howl_decode_Stage1, slop_option_howl_decode_Stage1)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ENTITYKIND_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ENTITYKIND_DEFINED
SLOP_OPTION_DEFINE(howl_types_EntityKind, slop_option_howl_types_EntityKind)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_PROPCHARACTERISTIC_DEFINED
#define SLOP_OPTION_HOWL_OWL2_PROPCHARACTERISTIC_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_PropCharacteristic, slop_option_howl_owl2_PropCharacteristic)
#endif

#ifndef SLOP_OPTION_HOWL_DECODE_DECODING_DEFINED
#define SLOP_OPTION_HOWL_DECODE_DECODING_DEFINED
SLOP_OPTION_DEFINE(howl_decode_Decoding, slop_option_howl_decode_Decoding)
#endif

#ifndef SLOP_OPTION_HOWL_DECODE_DATAVOCAB_DEFINED
#define SLOP_OPTION_HOWL_DECODE_DATAVOCAB_DEFINED
SLOP_OPTION_DEFINE(howl_decode_DataVocab, slop_option_howl_decode_DataVocab)
#endif

#ifndef SLOP_OPTION_HOWL_DECODE_DATALEMMA_DEFINED
#define SLOP_OPTION_HOWL_DECODE_DATALEMMA_DEFINED
SLOP_OPTION_DEFINE(howl_decode_DataLemma, slop_option_howl_decode_DataLemma)
#endif


#endif
