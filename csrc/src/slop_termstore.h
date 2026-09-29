#ifndef SLOP_termstore_H
#define SLOP_termstore_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"

typedef struct termstore_IdPair termstore_IdPair;
typedef struct termstore_IdTriple termstore_IdTriple;
typedef struct termstore_TermStore termstore_TermStore;

typedef slop_map* termstore_IdSet;

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

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

struct termstore_IdPair {
    int64_t a;
    int64_t b;
};
typedef struct termstore_IdPair termstore_IdPair;

#ifndef SLOP_OPTION_TERMSTORE_IDPAIR_DEFINED
#define SLOP_OPTION_TERMSTORE_IDPAIR_DEFINED
SLOP_OPTION_DEFINE(termstore_IdPair, slop_option_termstore_IdPair)
#endif

#ifndef SLOP_LIST_TERMSTORE_IDPAIR_DEFINED
#define SLOP_LIST_TERMSTORE_IDPAIR_DEFINED
#define SLOP_LIST_TERMSTORE_IDPAIR_IMPL_DEFINED
SLOP_LIST_DEFINE(termstore_IdPair, slop_list_termstore_IdPair)
#endif

struct termstore_IdTriple {
    int64_t s;
    int64_t p;
    int64_t o;
};
typedef struct termstore_IdTriple termstore_IdTriple;

#ifndef SLOP_OPTION_TERMSTORE_IDTRIPLE_DEFINED
#define SLOP_OPTION_TERMSTORE_IDTRIPLE_DEFINED
SLOP_OPTION_DEFINE(termstore_IdTriple, slop_option_termstore_IdTriple)
#endif

#ifndef SLOP_LIST_TERMSTORE_IDTRIPLE_DEFINED
#define SLOP_LIST_TERMSTORE_IDTRIPLE_DEFINED
#define SLOP_LIST_TERMSTORE_IDTRIPLE_IMPL_DEFINED
SLOP_LIST_DEFINE(termstore_IdTriple, slop_list_termstore_IdTriple)
#endif

struct termstore_TermStore {
    slop_map* ids;
    slop_map* quoted;
    slop_map* terms;
    slop_map* spo;
    slop_map* typed;
    int64_t rdf_type;
};
typedef struct termstore_TermStore termstore_TermStore;

#ifndef SLOP_OPTION_TERMSTORE_TERMSTORE_DEFINED
#define SLOP_OPTION_TERMSTORE_TERMSTORE_DEFINED
SLOP_OPTION_DEFINE(termstore_TermStore, slop_option_termstore_TermStore)
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
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
#ifndef RDF_BLANKNODE_HASH_EQ_DEFINED
#define RDF_BLANKNODE_HASH_EQ_DEFINED
static inline uint64_t slop_hash_rdf_BlankNode(const void* key) {
    const rdf_BlankNode* _k = (const rdf_BlankNode*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&(int64_t){ (int64_t)_k->id }); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_rdf_BlankNode(const void* a, const void* b) {
    const rdf_BlankNode* _a = (const rdf_BlankNode*)a;
    const rdf_BlankNode* _b = (const rdf_BlankNode*)b;
    return true
        && (_a->id == _b->id)
    ;
}
#endif
#ifndef RDF_LITERAL_HASH_EQ_DEFINED
#define RDF_LITERAL_HASH_EQ_DEFINED
static inline uint64_t slop_hash_rdf_Literal(const void* key) {
    const rdf_Literal* _k = (const rdf_Literal*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    hash ^= ((_k->datatype).has_value ? slop_hash_combine(1, slop_hash_string(&(_k->datatype).value)) : 0); hash *= 1099511628211ULL;
    hash ^= ((_k->lang).has_value ? slop_hash_combine(1, slop_hash_string(&(_k->lang).value)) : 0); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_rdf_Literal(const void* a, const void* b) {
    const rdf_Literal* _a = (const rdf_Literal*)a;
    const rdf_Literal* _b = (const rdf_Literal*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
        && ((_a->datatype).has_value == (_b->datatype).has_value && (!(_a->datatype).has_value || ((slop_eq_string(&(_a->datatype).value, &(_b->datatype).value)))))
        && ((_a->lang).has_value == (_b->lang).has_value && (!(_a->lang).has_value || ((slop_eq_string(&(_a->lang).value, &(_b->lang).value)))))
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

#ifndef TERMSTORE_IDTRIPLE_HASH_EQ_DEFINED
#define TERMSTORE_IDTRIPLE_HASH_EQ_DEFINED
static inline uint64_t slop_hash_termstore_IdTriple(const void* key) {
    const termstore_IdTriple* _k = (const termstore_IdTriple*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&_k->s); hash *= 1099511628211ULL;
    hash ^= slop_hash_int(&_k->p); hash *= 1099511628211ULL;
    hash ^= slop_hash_int(&_k->o); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_termstore_IdTriple(const void* a, const void* b) {
    const termstore_IdTriple* _a = (const termstore_IdTriple*)a;
    const termstore_IdTriple* _b = (const termstore_IdTriple*)b;
    return true
        && (_a->s == _b->s)
        && (_a->p == _b->p)
        && (_a->o == _b->o)
    ;
}
#endif

#ifndef TERMSTORE_IDPAIR_HASH_EQ_DEFINED
#define TERMSTORE_IDPAIR_HASH_EQ_DEFINED
static inline uint64_t slop_hash_termstore_IdPair(const void* key) {
    const termstore_IdPair* _k = (const termstore_IdPair*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_int(&_k->a); hash *= 1099511628211ULL;
    hash ^= slop_hash_int(&_k->b); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_termstore_IdPair(const void* a, const void* b) {
    const termstore_IdPair* _a = (const termstore_IdPair*)a;
    const termstore_IdPair* _b = (const termstore_IdPair*)b;
    return true
        && (_a->a == _b->a)
        && (_a->b == _b->b)
    ;
}
#endif

int64_t termstore_intern_term(slop_arena* arena, termstore_TermStore st, rdf_Term t);
slop_option_int termstore_lookup_term(termstore_TermStore st, rdf_Term t);
void termstore_typed_put(slop_arena* arena, termstore_TermStore st, int64_t type, int64_t s);
uint8_t termstore_store_insert(slop_arena* arena, termstore_TermStore st, rdf_Triple t);
termstore_TermStore termstore_build_store(slop_arena* arena, slop_list_rdf_Triple triples);
slop_list_rdf_Term termstore_store_objects(slop_arena* arena, termstore_TermStore st, rdf_Term s, rdf_Term p);
slop_list_rdf_Term termstore_store_typed(slop_arena* arena, termstore_TermStore st, rdf_Term type);
uint8_t termstore_store_contains(termstore_TermStore st, rdf_Triple t);
uint8_t termstore_store_has_any(termstore_TermStore st, rdf_Term s, rdf_Term p);

#ifndef SLOP_OPTION_TERMSTORE_IDPAIR_DEFINED
#define SLOP_OPTION_TERMSTORE_IDPAIR_DEFINED
SLOP_OPTION_DEFINE(termstore_IdPair, slop_option_termstore_IdPair)
#endif

#ifndef SLOP_OPTION_TERMSTORE_IDTRIPLE_DEFINED
#define SLOP_OPTION_TERMSTORE_IDTRIPLE_DEFINED
SLOP_OPTION_DEFINE(termstore_IdTriple, slop_option_termstore_IdTriple)
#endif

#ifndef SLOP_OPTION_RDF_TERM_DEFINED
#define SLOP_OPTION_RDF_TERM_DEFINED
SLOP_OPTION_DEFINE(rdf_Term, slop_option_rdf_Term)
#endif

#ifndef SLOP_OPTION_TERMSTORE_IDSET_DEFINED
#define SLOP_OPTION_TERMSTORE_IDSET_DEFINED
SLOP_OPTION_DEFINE(termstore_IdSet, slop_option_termstore_IdSet)
#endif

#ifndef SLOP_OPTION_TERMSTORE_TERMSTORE_DEFINED
#define SLOP_OPTION_TERMSTORE_TERMSTORE_DEFINED
SLOP_OPTION_DEFINE(termstore_TermStore, slop_option_termstore_TermStore)
#endif

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif


#endif
