#ifndef SLOP_locality_H
#define SLOP_locality_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"
#include "slop_owl2.h"
#include "slop_normalize.h"
#include "slop_strlib.h"

typedef struct locality_ModuleOut locality_ModuleOut;

#ifndef SLOP_OPTION_LIST_INT_DEFINED
#define SLOP_OPTION_LIST_INT_DEFINED
SLOP_OPTION_DEFINE(slop_list_int, slop_option_list_int)
#endif

#ifndef SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_IMPL_DEFINED
SLOP_LIST_DEFINE(uint8_t, slop_list_u8)
#endif

#ifndef SLOP_LIST_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_list_rdf_IRI, slop_list_list_rdf_IRI)
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

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_OPTION_LIST_RDF_IRI_DEFINED
#define SLOP_OPTION_LIST_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_list_rdf_IRI, slop_option_list_rdf_IRI)
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

#ifndef SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Node, slop_list_types_Node)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

struct locality_ModuleOut {
    slop_list_owl2_RawAxiom axioms;
    slop_map* symbols;
};
typedef struct locality_ModuleOut locality_ModuleOut;

#ifndef SLOP_OPTION_LOCALITY_MODULEOUT_DEFINED
#define SLOP_OPTION_LOCALITY_MODULEOUT_DEFINED
SLOP_OPTION_DEFINE(locality_ModuleOut, slop_option_locality_ModuleOut)
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

uint8_t locality_iri_out(slop_map* s, rdf_IRI i);
uint8_t locality_owl_own(rdf_IRI i);
uint8_t locality_role_out(slop_map* s, types_RoleId r);
uint8_t locality_name_out(slop_map* s, types_Node n);
uint8_t locality_con_bot(owl2_RawConcept c, slop_map* s);
uint8_t locality_con_top(owl2_RawConcept c, slop_map* s);
uint8_t locality_at_least_one(owl2_CardKind k, int64_t n);
uint8_t locality_min_zero(owl2_CardKind k, int64_t n);
uint8_t locality_at_most(owl2_CardKind k, int64_t n);
uint8_t locality_some_bot(slop_list_owl2_RawConcept cs, slop_map* s);
uint8_t locality_all_bot(slop_list_owl2_RawConcept cs, slop_map* s);
int64_t locality_not_bot(slop_list_owl2_RawConcept cs, slop_map* s);
uint8_t locality_some_top(slop_list_owl2_RawConcept cs, slop_map* s);
uint8_t locality_all_top(slop_list_owl2_RawConcept cs, slop_map* s);
int64_t locality_roles_not_out(slop_list_types_RoleId rs, slop_map* s);
uint8_t locality_axiom_local(owl2_RawAxiom ax, slop_map* s);
slop_list_rdf_IRI locality_axiom_symbols(slop_arena* arena, owl2_RawAxiom ax);
void locality_add_axiom_symbols(owl2_RawAxiom ax, slop_map* out);
void locality_add_concept_symbols(owl2_RawConcept c, slop_map* out);
void locality_add_concepts_symbols(slop_list_owl2_RawConcept cs, slop_map* out);
void locality_add_role(types_RoleId r, slop_map* out);
void locality_add_roles(slop_list_types_RoleId rs, slop_map* out);
void locality_add_node(types_Node n, slop_map* out);
void locality_add_nodes(slop_list_types_Node ns, slop_map* out);
void locality_add_edge(owl2_RawEdge e, slop_map* out);
locality_ModuleOut locality_module_axioms(slop_arena* arena, slop_list_owl2_RawAxiom axs, slop_list_rdf_IRI seed);
slop_list_int locality_admit_symbols(slop_arena* arena, slop_list_rdf_IRI syms, slop_map* s, slop_map* index, slop_list_u8 in_m);
slop_list_list_rdf_IRI locality_symbols_of(slop_arena* arena, slop_list_owl2_RawAxiom axs);
slop_map* locality_symbol_index(slop_arena* arena, slop_list_list_rdf_IRI sigs);
slop_list_owl2_RawAxiom locality_kept(slop_arena* arena, slop_list_owl2_RawAxiom axs, slop_list_u8 in_m);
int64_t locality_int_of(slop_list_int xs, int64_t k);
uint8_t locality_bool_of(slop_list_u8 xs, int64_t k);
owl2_RawAxiom locality_axiom_of(slop_list_owl2_RawAxiom axs, int64_t k);
slop_list_rdf_IRI locality_sym_of(slop_arena* arena, slop_list_list_rdf_IRI sigs, int64_t k);
normalize_Decoded locality_module_decoded(slop_arena* arena, normalize_Decoded d, slop_list_rdf_IRI seed);
owl2_Signature locality_restricted(slop_arena* arena, owl2_Signature sig, slop_map* s);
slop_map* locality_within(slop_arena* arena, slop_map* xs, slop_map* s);

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_LOCALITY_MODULEOUT_DEFINED
#define SLOP_OPTION_LOCALITY_MODULEOUT_DEFINED
SLOP_OPTION_DEFINE(locality_ModuleOut, slop_option_locality_ModuleOut)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_LIST_INT_DEFINED
#define SLOP_OPTION_LIST_INT_DEFINED
SLOP_OPTION_DEFINE(slop_list_int, slop_option_list_int)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_LIST_RDF_IRI_DEFINED
#define SLOP_OPTION_LIST_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_list_rdf_IRI, slop_option_list_rdf_IRI)
#endif


#endif
