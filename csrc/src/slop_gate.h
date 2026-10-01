#ifndef SLOP_gate_H
#define SLOP_gate_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"
#include "slop_owl2.h"
#include "slop_canon.h"

typedef struct gate_GateResult gate_GateResult;
typedef struct gate_NegSplit gate_NegSplit;
typedef struct gate_RboxVerdict gate_RboxVerdict;
typedef struct gate_RangeEntry gate_RangeEntry;
typedef struct gate_EntityRef gate_EntityRef;

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

#ifndef SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(types_RoleId, slop_list_types_RoleId)
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

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

struct gate_GateResult {
    slop_list_owl2_RawAxiom accepted;
    slop_list_types_Omission omissions;
    owl2_Signature signature;
};
typedef struct gate_GateResult gate_GateResult;

#ifndef SLOP_OPTION_GATE_GATERESULT_DEFINED
#define SLOP_OPTION_GATE_GATERESULT_DEFINED
SLOP_OPTION_DEFINE(gate_GateResult, slop_option_gate_GateResult)
#endif

struct gate_NegSplit {
    slop_list_owl2_RawConcept pos;
    slop_list_owl2_RawConcept neg;
};
typedef struct gate_NegSplit gate_NegSplit;

#ifndef SLOP_OPTION_GATE_NEGSPLIT_DEFINED
#define SLOP_OPTION_GATE_NEGSPLIT_DEFINED
SLOP_OPTION_DEFINE(gate_NegSplit, slop_option_gate_NegSplit)
#endif

typedef enum {
    gate_RboxVerdict_rbox_regular,
    gate_RboxVerdict_rbox_irregular
} gate_RboxVerdict_tag;

struct gate_RboxVerdict {
    gate_RboxVerdict_tag tag;
    union {
        slop_string rbox_irregular;
    } data;
};
typedef struct gate_RboxVerdict gate_RboxVerdict;

#ifndef SLOP_OPTION_GATE_RBOXVERDICT_DEFINED
#define SLOP_OPTION_GATE_RBOXVERDICT_DEFINED
SLOP_OPTION_DEFINE(gate_RboxVerdict, slop_option_gate_RboxVerdict)
#endif

struct gate_RangeEntry {
    int64_t role;
    owl2_RawConcept filler;
};
typedef struct gate_RangeEntry gate_RangeEntry;

#ifndef SLOP_OPTION_GATE_RANGEENTRY_DEFINED
#define SLOP_OPTION_GATE_RANGEENTRY_DEFINED
SLOP_OPTION_DEFINE(gate_RangeEntry, slop_option_gate_RangeEntry)
#endif

#ifndef SLOP_LIST_GATE_RANGEENTRY_DEFINED
#define SLOP_LIST_GATE_RANGEENTRY_DEFINED
#define SLOP_LIST_GATE_RANGEENTRY_IMPL_DEFINED
SLOP_LIST_DEFINE(gate_RangeEntry, slop_list_gate_RangeEntry)
#endif

struct gate_EntityRef {
    types_EntityKind kind;
    rdf_IRI entity;
    owl2_RawAxiom axiom;
};
typedef struct gate_EntityRef gate_EntityRef;

#ifndef SLOP_OPTION_GATE_ENTITYREF_DEFINED
#define SLOP_OPTION_GATE_ENTITYREF_DEFINED
SLOP_OPTION_DEFINE(gate_EntityRef, slop_option_gate_EntityRef)
#endif

#ifndef SLOP_LIST_GATE_ENTITYREF_DEFINED
#define SLOP_LIST_GATE_ENTITYREF_DEFINED
#define SLOP_LIST_GATE_ENTITYREF_IMPL_DEFINED
SLOP_LIST_DEFINE(gate_EntityRef, slop_list_gate_EntityRef)
#endif

types_InputRef gate_axiom_input_ref(slop_arena* arena, owl2_RawAxiom ax);
slop_option_types_RoleId gate_least_role(slop_list_types_RoleId rs);
slop_list_owl2_RawAxiom gate_expand_sugar(slop_arena* arena, slop_list_owl2_RawAxiom axs);
uint8_t gate_has_negated_conjunct(owl2_RawConcept c);
slop_list_owl2_RawConcept gate_conjuncts(slop_arena* arena, owl2_RawConcept c);
gate_NegSplit gate_negation_split(slop_arena* arena, owl2_RawConcept c);
uint8_t gate_split_rewritable(types_Profile p, gate_NegSplit s);
owl2_RawConcept gate_conjunction(slop_list_owl2_RawConcept cs);
owl2_RawConcept gate_with_conjunct(slop_arena* arena, owl2_RawConcept c, owl2_RawConcept e);
owl2_RawAxiom gate_empty_axiom(slop_arena* arena, owl2_RawConcept c);
slop_list_owl2_RawAxiom gate_expand_negation(slop_arena* arena, types_Profile p, slop_list_owl2_RawAxiom axs);
uint8_t gate_is_top_role(types_RoleId r);
uint8_t gate_into_top_role(owl2_RawAxiom ax);
slop_list_owl2_RawAxiom gate_drop_top_role_tautologies(slop_arena* arena, types_Profile p, slop_list_owl2_RawAxiom axs);
uint8_t gate_role_listed(slop_list_types_RoleId rs, types_RoleId r);
slop_list_types_RoleId gate_non_simple_roles(slop_arena* arena, slop_list_owl2_RawAxiom axs);
uint8_t gate_concept_self_roles_simple(slop_list_types_RoleId nonsimple, owl2_RawConcept c);
uint8_t gate_self_roles_simple(slop_list_types_RoleId nonsimple, owl2_RawAxiom ax);
owl2_RawConcept* gate_box_c(slop_arena* arena, owl2_RawConcept c);
uint8_t gate_is_rbox_axiom(owl2_RawAxiom ax);
uint8_t gate_axiom_range_ok(slop_list_gate_RangeEntry entries, slop_list_u8 told, int64_t n, slop_list_types_RoleId roles, owl2_RawAxiom ax);
gate_GateResult gate_gate_axioms(slop_arena* arena, slop_list_owl2_RawAxiom axs, owl2_Signature sig, slop_list_types_Omission carried, types_Profile p);
slop_list_owl2_RawAxiom gate_sort_axioms(slop_arena* arena, slop_list_owl2_RawAxiom xs);
slop_list_string gate_axiom_texts(slop_arena* arena, slop_list_owl2_RawAxiom xs);
owl2_RawAxiom gate_axiom_at(slop_list_owl2_RawAxiom xs, int64_t i);
int64_t gate_role_idx(slop_list_types_RoleId roles, types_RoleId r);
uint8_t gate_push_role_unique(slop_list_types_RoleId rs, types_RoleId r);
slop_list_types_RoleId gate_collect_rbox_roles(slop_arena* arena, slop_list_owl2_RawAxiom axs);
slop_list_types_RoleId gate_sort_roles(slop_arena* arena, slop_list_types_RoleId xs);
types_RoleId gate_role_at(slop_list_types_RoleId xs, int64_t i);
slop_list_u8 gate_mat_new(slop_arena* arena, int64_t cells);
uint8_t gate_mat_get(slop_list_u8 m, int64_t i);
uint8_t gate_mat_close(slop_list_u8 m, int64_t n);
slop_list_u8 gate_told_closure(slop_arena* arena, slop_list_owl2_RawAxiom axs, slop_list_types_RoleId roles, int64_t n);
int64_t gate_candidate_size(owl2_RawChain ch, int64_t from, int64_t to);
uint8_t gate_add_chain_constraints(owl2_RawChain ch, slop_list_types_RoleId roles, int64_t n, slop_list_u8 cmat, int64_t from, int64_t to);
slop_string gate_describe_violation(slop_arena* arena, slop_list_types_RoleId roles, int64_t i, int64_t j);
gate_RboxVerdict gate_check_regularity(slop_arena* arena, slop_list_owl2_RawAxiom axs);
slop_list_gate_RangeEntry gate_collect_ranges(slop_arena* arena, slop_list_owl2_RawAxiom axs, slop_list_types_RoleId roles);
uint8_t gate_has_inherited_range(slop_list_gate_RangeEntry entries, slop_list_u8 told, int64_t n, int64_t base, owl2_RawConcept c);
uint8_t gate_chain_range_ok(slop_list_gate_RangeEntry entries, slop_list_u8 told, int64_t n, slop_list_types_RoleId roles, owl2_RawChain ch);
types_AxiomRef gate_axiom_ref_of(slop_arena* arena, owl2_RawAxiom ax);
slop_list_rdf_IRI gate_collect_concept_classes(slop_arena* arena, owl2_RawConcept c, slop_list_rdf_IRI acc);
slop_list_gate_EntityRef gate_collect_entity_refs(slop_arena* arena, slop_list_owl2_RawAxiom axs);
uint8_t gate_entity_ref_declared(owl2_Signature sig, gate_EntityRef e);
uint8_t gate_same_entity(gate_EntityRef a, gate_EntityRef b);
slop_list_types_Omission gate_missing_declarations(slop_arena* arena, owl2_Signature sig, slop_list_gate_EntityRef refs);

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

#ifndef SLOP_OPTION_GATE_GATERESULT_DEFINED
#define SLOP_OPTION_GATE_GATERESULT_DEFINED
SLOP_OPTION_DEFINE(gate_GateResult, slop_option_gate_GateResult)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_GATE_NEGSPLIT_DEFINED
#define SLOP_OPTION_GATE_NEGSPLIT_DEFINED
SLOP_OPTION_DEFINE(gate_NegSplit, slop_option_gate_NegSplit)
#endif

#ifndef SLOP_OPTION_GATE_RANGEENTRY_DEFINED
#define SLOP_OPTION_GATE_RANGEENTRY_DEFINED
SLOP_OPTION_DEFINE(gate_RangeEntry, slop_option_gate_RangeEntry)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_GATE_RBOXVERDICT_DEFINED
#define SLOP_OPTION_GATE_RBOXVERDICT_DEFINED
SLOP_OPTION_DEFINE(gate_RboxVerdict, slop_option_gate_RboxVerdict)
#endif

#ifndef SLOP_OPTION_GATE_ENTITYREF_DEFINED
#define SLOP_OPTION_GATE_ENTITYREF_DEFINED
SLOP_OPTION_DEFINE(gate_EntityRef, slop_option_gate_EntityRef)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_AXIOMREF_DEFINED
#define SLOP_OPTION_TYPES_AXIOMREF_DEFINED
SLOP_OPTION_DEFINE(types_AxiomRef, slop_option_types_AxiomRef)
#endif

#ifndef SLOP_LIST_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_TYPES_AXIOMREF_IMPL_DEFINED
SLOP_LIST_DEFINE(types_AxiomRef, slop_list_types_AxiomRef)
#endif


#endif
