#ifndef SLOP_termstore_H
#define SLOP_termstore_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"

typedef struct howl_termstore_IdPair howl_termstore_IdPair;
typedef struct howl_termstore_IdTriple howl_termstore_IdTriple;
typedef struct howl_termstore_Objects howl_termstore_Objects;
typedef struct howl_termstore_TermStore howl_termstore_TermStore;
typedef struct howl_termstore_Encoded howl_termstore_Encoded;

typedef slop_map* howl_termstore_IdSet;

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

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Triple, slop_option_slop_rdf_rdf_Triple)
#endif

struct howl_termstore_IdPair {
    int64_t a;
    int64_t b;
};
typedef struct howl_termstore_IdPair howl_termstore_IdPair;

#ifndef SLOP_OPTION_HOWL_TERMSTORE_IDPAIR_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_IDPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_IdPair, slop_option_howl_termstore_IdPair)
#endif

#ifndef SLOP_LIST_HOWL_TERMSTORE_IDPAIR_DEFINED
#define SLOP_LIST_HOWL_TERMSTORE_IDPAIR_DEFINED
#define SLOP_LIST_HOWL_TERMSTORE_IDPAIR_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_termstore_IdPair, slop_list_howl_termstore_IdPair)
#endif

struct howl_termstore_IdTriple {
    int64_t s;
    int64_t p;
    int64_t o;
};
typedef struct howl_termstore_IdTriple howl_termstore_IdTriple;

#ifndef SLOP_OPTION_HOWL_TERMSTORE_IDTRIPLE_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_IDTRIPLE_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_IdTriple, slop_option_howl_termstore_IdTriple)
#endif

#ifndef SLOP_LIST_HOWL_TERMSTORE_IDTRIPLE_DEFINED
#define SLOP_LIST_HOWL_TERMSTORE_IDTRIPLE_DEFINED
#define SLOP_LIST_HOWL_TERMSTORE_IDTRIPLE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_termstore_IdTriple, slop_list_howl_termstore_IdTriple)
#endif

struct howl_termstore_Objects {
    int64_t first;
    slop_map* more;
};
typedef struct howl_termstore_Objects howl_termstore_Objects;

#ifndef SLOP_OPTION_HOWL_TERMSTORE_OBJECTS_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_OBJECTS_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_Objects, slop_option_howl_termstore_Objects)
#endif

struct howl_termstore_TermStore {
    slop_map* ids;
    slop_map* quoted;
    slop_map* terms;
    slop_map* spo;
    slop_map* typed;
    int64_t rdf_type;
};
typedef struct howl_termstore_TermStore howl_termstore_TermStore;

#ifndef SLOP_OPTION_HOWL_TERMSTORE_TERMSTORE_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_TERMSTORE_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_TermStore, slop_option_howl_termstore_TermStore)
#endif

struct howl_termstore_Encoded {
    howl_termstore_TermStore dict;
    slop_list_howl_termstore_IdTriple triples;
    int64_t offset;
    int64_t max_blank;
    slop_list_int starts;
};
typedef struct howl_termstore_Encoded howl_termstore_Encoded;

#ifndef SLOP_OPTION_HOWL_TERMSTORE_ENCODED_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_ENCODED_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_Encoded, slop_option_howl_termstore_Encoded)
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

#ifndef HOWL_TERMSTORE_IDPAIR_HASH_EQ_DEFINED
#define HOWL_TERMSTORE_IDPAIR_HASH_EQ_DEFINED
static inline uint64_t slop_hash_howl_termstore_IdPair(const void* key) {
    const howl_termstore_IdPair* _k = (const howl_termstore_IdPair*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&_k->a); hash *= 1099511628211ULL;
    hash ^= slop_hash_int(&_k->b); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_howl_termstore_IdPair(const void* a, const void* b) {
    const howl_termstore_IdPair* _a = (const howl_termstore_IdPair*)a;
    const howl_termstore_IdPair* _b = (const howl_termstore_IdPair*)b;
    return true
        && (_a->a == _b->a)
        && (_a->b == _b->b)
    ;
}
#endif

int64_t howl_termstore_intern_term(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Term t);
slop_option_int howl_termstore_lookup_term(howl_termstore_TermStore st, slop_rdf_rdf_Term t);
slop_string howl_termstore_copy_string(slop_arena* arena, slop_string s);
slop_option_string howl_termstore_copy_option_string(slop_arena* arena, slop_option_string s);
slop_rdf_rdf_Term howl_termstore_own_plain_term(slop_arena* arena, slop_rdf_rdf_Term t);
slop_rdf_rdf_Term howl_termstore_term_of(howl_termstore_TermStore st, int64_t id);
slop_rdf_rdf_Triple howl_termstore_triple_of(howl_termstore_TermStore st, howl_termstore_IdTriple it);
int64_t howl_termstore_intern_owned(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Term t);
void howl_termstore_typed_put(slop_arena* arena, howl_termstore_TermStore st, int64_t type, int64_t s);
uint8_t howl_termstore_store_insert(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Triple t);
uint8_t howl_termstore_store_insert_ids(slop_arena* arena, howl_termstore_TermStore st, howl_termstore_IdTriple it);
howl_termstore_TermStore howl_termstore_build_store(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples);
howl_termstore_TermStore howl_termstore_empty_store(slop_arena* arena);
howl_termstore_TermStore howl_termstore_store_over(slop_arena* arena, howl_termstore_TermStore dict);
howl_termstore_Encoded* howl_termstore_new_encoded(slop_arena* arena);
slop_list_int howl_termstore_first_start(slop_arena* arena);
int64_t howl_termstore_max_blank_in(slop_rdf_rdf_Term t);
slop_rdf_rdf_Term howl_termstore_shift_blanks(slop_arena* arena, slop_rdf_rdf_Term t, int64_t offset);
void howl_termstore_encoded_add(slop_arena* arena, howl_termstore_Encoded* p, slop_rdf_rdf_Triple t);
void howl_termstore_encoded_next_document(slop_arena* arena, howl_termstore_Encoded* p);
int64_t howl_termstore_doc_at(slop_list_int starts, int64_t i, int64_t cur);
howl_termstore_Encoded howl_termstore_encode_triples(slop_arena* arena, slop_list_slop_rdf_rdf_Triple triples);
slop_list_slop_rdf_rdf_Term howl_termstore_store_objects(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Term s, slop_rdf_rdf_Term p);
int64_t howl_termstore_store_object_count(howl_termstore_TermStore st, slop_rdf_rdf_Term s, slop_rdf_rdf_Term p);
slop_option_slop_rdf_rdf_Term howl_termstore_store_sole_object(howl_termstore_TermStore st, slop_rdf_rdf_Term s, slop_rdf_rdf_Term p);
slop_list_slop_rdf_rdf_Term howl_termstore_store_typed(slop_arena* arena, howl_termstore_TermStore st, slop_rdf_rdf_Term type);
uint8_t howl_termstore_store_contains(howl_termstore_TermStore st, slop_rdf_rdf_Triple t);
uint8_t howl_termstore_store_has_any(howl_termstore_TermStore st, slop_rdf_rdf_Term s, slop_rdf_rdf_Term p);

#ifndef SLOP_OPTION_HOWL_TERMSTORE_IDPAIR_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_IDPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_IdPair, slop_option_howl_termstore_IdPair)
#endif

#ifndef SLOP_OPTION_HOWL_TERMSTORE_IDTRIPLE_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_IDTRIPLE_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_IdTriple, slop_option_howl_termstore_IdTriple)
#endif

#ifndef SLOP_OPTION_HOWL_TERMSTORE_OBJECTS_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_OBJECTS_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_Objects, slop_option_howl_termstore_Objects)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Term, slop_option_slop_rdf_rdf_Term)
#endif

#ifndef SLOP_OPTION_HOWL_TERMSTORE_IDSET_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_IDSET_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_IdSet, slop_option_howl_termstore_IdSet)
#endif

#ifndef SLOP_OPTION_HOWL_TERMSTORE_TERMSTORE_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_TERMSTORE_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_TermStore, slop_option_howl_termstore_TermStore)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Triple, slop_option_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_OPTION_HOWL_TERMSTORE_ENCODED_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_ENCODED_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_Encoded, slop_option_howl_termstore_Encoded)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif


#endif
