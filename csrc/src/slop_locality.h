#ifndef SLOP_locality_H
#define SLOP_locality_H

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
#include "slop_normalize.h"
#include "slop_strlib.h"

typedef struct howl_locality_ModuleOut howl_locality_ModuleOut;

#ifndef SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_IMPL_DEFINED
SLOP_LIST_DEFINE(uint8_t, slop_list_u8)
#endif

#ifndef SLOP_OPTION_LIST_INT_DEFINED
#define SLOP_OPTION_LIST_INT_DEFINED
SLOP_OPTION_DEFINE(slop_list_int, slop_option_list_int)
#endif

#ifndef SLOP_LIST_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_list_slop_rdf_rdf_IRI, slop_list_list_slop_rdf_rdf_IRI)
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

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_LIST_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_list_slop_rdf_rdf_IRI, slop_option_list_slop_rdf_rdf_IRI)
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

#ifndef SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Node, slop_list_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

struct howl_locality_ModuleOut {
    slop_list_howl_owl2_RawAxiom axioms;
    slop_map* symbols;
    slop_list_u8 in_m;
};
typedef struct howl_locality_ModuleOut howl_locality_ModuleOut;

#ifndef SLOP_OPTION_HOWL_LOCALITY_MODULEOUT_DEFINED
#define SLOP_OPTION_HOWL_LOCALITY_MODULEOUT_DEFINED
SLOP_OPTION_DEFINE(howl_locality_ModuleOut, slop_option_howl_locality_ModuleOut)
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

uint8_t howl_locality_iri_out(slop_map* s, slop_rdf_rdf_IRI i);
uint8_t howl_locality_owl_own(slop_rdf_rdf_IRI i);
uint8_t howl_locality_role_out(slop_map* s, howl_types_RoleId r);
uint8_t howl_locality_name_out(slop_map* s, howl_types_Node n);
uint8_t howl_locality_con_bot(howl_owl2_RawConcept c, slop_map* s);
uint8_t howl_locality_con_top(howl_owl2_RawConcept c, slop_map* s);
uint8_t howl_locality_at_least_one(howl_owl2_CardKind k, int64_t n);
uint8_t howl_locality_min_zero(howl_owl2_CardKind k, int64_t n);
uint8_t howl_locality_at_most(howl_owl2_CardKind k, int64_t n);
uint8_t howl_locality_some_bot(slop_list_howl_owl2_RawConcept cs, slop_map* s);
uint8_t howl_locality_all_bot(slop_list_howl_owl2_RawConcept cs, slop_map* s);
int64_t howl_locality_not_bot(slop_list_howl_owl2_RawConcept cs, slop_map* s);
uint8_t howl_locality_some_top(slop_list_howl_owl2_RawConcept cs, slop_map* s);
uint8_t howl_locality_all_top(slop_list_howl_owl2_RawConcept cs, slop_map* s);
int64_t howl_locality_roles_not_out(slop_list_howl_types_RoleId rs, slop_map* s);
uint8_t howl_locality_axiom_local(howl_owl2_RawAxiom ax, slop_map* s);
slop_list_slop_rdf_rdf_IRI howl_locality_axiom_symbols(slop_arena* arena, howl_owl2_RawAxiom ax);
void howl_locality_add_axiom_symbols(howl_owl2_RawAxiom ax, slop_map* out);
void howl_locality_add_concept_symbols(howl_owl2_RawConcept c, slop_map* out);
void howl_locality_add_concepts_symbols(slop_list_howl_owl2_RawConcept cs, slop_map* out);
void howl_locality_add_role(howl_types_RoleId r, slop_map* out);
void howl_locality_add_roles(slop_list_howl_types_RoleId rs, slop_map* out);
void howl_locality_add_node(howl_types_Node n, slop_map* out);
void howl_locality_add_nodes(slop_list_howl_types_Node ns, slop_map* out);
void howl_locality_add_edge(howl_owl2_RawEdge e, slop_map* out);
uint8_t howl_locality_axiom_readable(howl_owl2_RawAxiom ax);
uint8_t howl_locality_concept_readable(howl_owl2_RawConcept c);
uint8_t howl_locality_concepts_readable(slop_list_howl_owl2_RawConcept cs);
howl_locality_ModuleOut howl_locality_module_axioms(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_list_slop_rdf_rdf_IRI seed);
slop_list_int howl_locality_admit_symbols(slop_arena* arena, slop_list_slop_rdf_rdf_IRI syms, slop_map* s, slop_map* index, slop_list_u8 in_m);
slop_list_list_slop_rdf_rdf_IRI howl_locality_symbols_of(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
slop_map* howl_locality_symbol_index(slop_arena* arena, slop_list_list_slop_rdf_rdf_IRI sigs);
slop_list_howl_owl2_RawAxiom howl_locality_kept(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_list_u8 in_m);
int64_t howl_locality_int_of(slop_list_int xs, int64_t k);
uint8_t howl_locality_bool_of(slop_list_u8 xs, int64_t k);
howl_owl2_RawAxiom howl_locality_axiom_of(slop_list_howl_owl2_RawAxiom axs, int64_t k);
slop_list_slop_rdf_rdf_IRI howl_locality_sym_of(slop_arena* arena, slop_list_list_slop_rdf_rdf_IRI sigs, int64_t k);
howl_normalize_Decoded howl_locality_module_decoded(slop_arena* arena, howl_normalize_Decoded d, slop_list_slop_rdf_rdf_IRI seed);
slop_list_int howl_locality_kept_docs(slop_arena* arena, slop_list_int docs, slop_list_u8 in_m);
howl_owl2_Signature howl_locality_restricted(slop_arena* arena, howl_owl2_Signature sig, slop_map* s);
slop_map* howl_locality_within(slop_arena* arena, slop_map* xs, slop_map* s);

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_HOWL_LOCALITY_MODULEOUT_DEFINED
#define SLOP_OPTION_HOWL_LOCALITY_MODULEOUT_DEFINED
SLOP_OPTION_DEFINE(howl_locality_ModuleOut, slop_option_howl_locality_ModuleOut)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_LIST_INT_DEFINED
#define SLOP_OPTION_LIST_INT_DEFINED
SLOP_OPTION_DEFINE(slop_list_int, slop_option_list_int)
#endif

#ifndef SLOP_OPTION_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_LIST_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_list_slop_rdf_rdf_IRI, slop_option_list_slop_rdf_rdf_IRI)
#endif


#endif
