/* howl.h - Auto-generated FFI header. Do not edit. */
#ifndef HOWL_H
#define HOWL_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Opaque runtime types */
typedef struct slop_arena slop_arena;
typedef struct slop_map slop_map;

/* Runtime value types */
typedef struct { size_t len; const char* data; } slop_string;
typedef struct { bool has_value; slop_string value; } slop_option_string;
typedef struct { void* fn; void* env; } slop_closure_t;

/* Type definitions */
typedef int64_t rdf_BlankNodeId;

struct rdf_BlankNode {
    rdf_BlankNodeId id;
};
typedef struct rdf_BlankNode rdf_BlankNode;

typedef int64_t rdf_GraphSize;

struct rdf_IRI {
    slop_string value;
};
typedef struct rdf_IRI rdf_IRI;

struct rdf_Literal {
    slop_string value;
    slop_option_string datatype;
    slop_option_string lang;
};
typedef struct rdf_Literal rdf_Literal;

typedef enum {
    rdf_TermKind_iri,
    rdf_TermKind_blank,
    rdf_TermKind_literal,
    rdf_TermKind_triple
} rdf_TermKind;

typedef enum {
    rdf_Term_term_iri,
    rdf_Term_term_blank,
    rdf_Term_term_literal,
    rdf_Term_term_triple
} rdf_Term_tag;

typedef enum {
    types_Profile_profile_el,
    types_Profile_profile_horn_shiq,
    types_Profile_profile_sroiq
} types_Profile;

typedef enum {
    types_ProfileSelection_slop_auto,
    types_ProfileSelection_explicit
} types_ProfileSelection_tag;

struct types_ProfileSelection {
    types_ProfileSelection_tag tag;
    union {
        types_Profile explicit;
    } data;
};
typedef struct types_ProfileSelection types_ProfileSelection;

struct types_ReasonerConfig {
    uint8_t worker_count;
    uint16_t channel_buffer;
    uint16_t max_iterations;
    types_ProfileSelection selection;
    uint8_t strict_profile;
    int64_t cancel_ptr;
    uint8_t verbose;
};
typedef struct types_ReasonerConfig types_ReasonerConfig;

struct rdf_Graph {
    slop_list_rdf_Triple triples;
    rdf_GraphSize size;
};
typedef struct rdf_Graph rdf_Graph;

struct rdf_Term {
    rdf_Term_tag tag;
    union {
        rdf_IRI term_iri;
        rdf_BlankNode term_blank;
        rdf_Literal term_literal;
        rdf_Triple* term_triple;
    } data;
};
typedef struct rdf_Term rdf_Term;

struct rdf_Triple {
    rdf_Term subject;
    rdf_Term predicate;
    rdf_Term object;
};
typedef struct rdf_Triple rdf_Triple;

typedef struct { size_t len; size_t cap; rdf_Triple* data; } slop_list_rdf_Triple;

typedef struct { bool has_value; rdf_Term value; } slop_option_rdf_Term;

/* Public API */
types_ReasonerConfig howl_default_config(void);
uint8_t rdf_blank_eq(rdf_BlankNode a, rdf_BlankNode b);
rdf_Graph rdf_graph_add(slop_arena* arena, rdf_Graph g, rdf_Triple t);
rdf_Graph rdf_graph_add_unchecked(slop_arena* arena, rdf_Graph g, rdf_Triple t);
uint8_t rdf_graph_contains(rdf_Graph g, rdf_Triple t);
void rdf_graph_free(rdf_Graph* g);
rdf_Graph rdf_graph_match(slop_arena* arena, rdf_Graph g, slop_option_rdf_Term subject, slop_option_rdf_Term predicate, slop_option_rdf_Term object);
rdf_Graph rdf_graph_remove(slop_arena* arena, rdf_Graph g, rdf_Triple t);
rdf_GraphSize rdf_graph_size(rdf_Graph g);
uint8_t rdf_iri_eq(rdf_IRI a, rdf_IRI b);
uint8_t rdf_literal_eq(rdf_Literal a, rdf_Literal b);
rdf_Term rdf_make_blank(slop_arena* arena, rdf_BlankNodeId id);
rdf_Graph rdf_make_graph(slop_arena* arena);
rdf_Term rdf_make_iri(slop_arena* arena, slop_string value);
rdf_Term rdf_make_literal(slop_arena* arena, slop_string value, slop_option_string datatype, slop_option_string lang);
rdf_Triple rdf_make_triple(slop_arena* arena, rdf_Term subject, rdf_Term predicate, rdf_Term object);
rdf_Term rdf_make_triple_term(slop_arena* arena, rdf_Triple t);
uint8_t rdf_option_string_eq(slop_option_string a, slop_option_string b);
uint8_t rdf_term_eq(rdf_Term a, rdf_Term b);
void rdf_term_free(rdf_Term* t);
rdf_TermKind rdf_term_kind(rdf_Term t);
uint8_t rdf_triple_eq(rdf_Triple a, rdf_Triple b);
void rdf_triple_free(rdf_Triple* t);
rdf_Term rdf_triple_object(rdf_Triple t);
rdf_Term rdf_triple_predicate(rdf_Triple t);
rdf_Term rdf_triple_subject(rdf_Triple t);

#define types_default_config howl_default_config

#ifdef __cplusplus
}
#endif

#endif /* HOWL_H */
