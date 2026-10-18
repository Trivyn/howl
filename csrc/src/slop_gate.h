#ifndef SLOP_gate_H
#define SLOP_gate_H

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
#include "slop_types.h"
#include "slop_owl2.h"
#include "slop_canon.h"
#include "slop_sriqrbox.h"

typedef struct howl_gate_GateResult howl_gate_GateResult;
typedef struct howl_gate_NegSplit howl_gate_NegSplit;
typedef struct howl_gate_RboxVerdict howl_gate_RboxVerdict;
typedef struct howl_gate_RangeEntry howl_gate_RangeEntry;
typedef struct howl_gate_EntityRef howl_gate_EntityRef;

#ifndef SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_IMPL_DEFINED
SLOP_LIST_DEFINE(uint8_t, slop_list_u8)
#endif

#ifndef SLOP_OPTION_LIST_INT_DEFINED
#define SLOP_OPTION_LIST_INT_DEFINED
SLOP_OPTION_DEFINE(slop_list_int, slop_option_list_int)
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

#ifndef SLOP_LIST_HOWL_TYPES_OMISSIONCAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSIONCAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSIONCAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_OmissionCause, slop_list_howl_types_OmissionCause)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_RoleId, slop_list_howl_types_RoleId)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawConcept, slop_list_howl_owl2_RawConcept)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_PROFILE_DEFINED
#define SLOP_LIST_HOWL_TYPES_PROFILE_DEFINED
#define SLOP_LIST_HOWL_TYPES_PROFILE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Profile, slop_list_howl_types_Profile)
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

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSIONCAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSIONCAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_OmissionCause, slop_option_howl_types_OmissionCause)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_PROFILE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_PROFILE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Profile, slop_option_howl_types_Profile)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

struct howl_gate_GateResult {
    slop_list_howl_owl2_RawAxiom accepted;
    slop_list_howl_types_Omission omissions;
    slop_list_howl_types_OmissionCause reasons;
    howl_owl2_Signature signature;
};
typedef struct howl_gate_GateResult howl_gate_GateResult;

#ifndef SLOP_OPTION_HOWL_GATE_GATERESULT_DEFINED
#define SLOP_OPTION_HOWL_GATE_GATERESULT_DEFINED
SLOP_OPTION_DEFINE(howl_gate_GateResult, slop_option_howl_gate_GateResult)
#endif

struct howl_gate_NegSplit {
    slop_list_howl_owl2_RawConcept pos;
    slop_list_howl_owl2_RawConcept neg;
};
typedef struct howl_gate_NegSplit howl_gate_NegSplit;

#ifndef SLOP_OPTION_HOWL_GATE_NEGSPLIT_DEFINED
#define SLOP_OPTION_HOWL_GATE_NEGSPLIT_DEFINED
SLOP_OPTION_DEFINE(howl_gate_NegSplit, slop_option_howl_gate_NegSplit)
#endif

typedef enum {
    howl_gate_RboxVerdict_rbox_regular,
    howl_gate_RboxVerdict_rbox_irregular
} howl_gate_RboxVerdict_tag;

struct howl_gate_RboxVerdict {
    howl_gate_RboxVerdict_tag tag;
    union {
        slop_string rbox_irregular;
    } data;
};
typedef struct howl_gate_RboxVerdict howl_gate_RboxVerdict;

#ifndef SLOP_OPTION_HOWL_GATE_RBOXVERDICT_DEFINED
#define SLOP_OPTION_HOWL_GATE_RBOXVERDICT_DEFINED
SLOP_OPTION_DEFINE(howl_gate_RboxVerdict, slop_option_howl_gate_RboxVerdict)
#endif

struct howl_gate_RangeEntry {
    int64_t role;
    howl_owl2_RawConcept filler;
};
typedef struct howl_gate_RangeEntry howl_gate_RangeEntry;

#ifndef SLOP_OPTION_HOWL_GATE_RANGEENTRY_DEFINED
#define SLOP_OPTION_HOWL_GATE_RANGEENTRY_DEFINED
SLOP_OPTION_DEFINE(howl_gate_RangeEntry, slop_option_howl_gate_RangeEntry)
#endif

#ifndef SLOP_LIST_HOWL_GATE_RANGEENTRY_DEFINED
#define SLOP_LIST_HOWL_GATE_RANGEENTRY_DEFINED
#define SLOP_LIST_HOWL_GATE_RANGEENTRY_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_gate_RangeEntry, slop_list_howl_gate_RangeEntry)
#endif

struct howl_gate_EntityRef {
    howl_types_EntityKind kind;
    slop_rdf_rdf_IRI entity;
    howl_owl2_RawAxiom axiom;
};
typedef struct howl_gate_EntityRef howl_gate_EntityRef;

#ifndef SLOP_OPTION_HOWL_GATE_ENTITYREF_DEFINED
#define SLOP_OPTION_HOWL_GATE_ENTITYREF_DEFINED
SLOP_OPTION_DEFINE(howl_gate_EntityRef, slop_option_howl_gate_EntityRef)
#endif

#ifndef SLOP_LIST_HOWL_GATE_ENTITYREF_DEFINED
#define SLOP_LIST_HOWL_GATE_ENTITYREF_DEFINED
#define SLOP_LIST_HOWL_GATE_ENTITYREF_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_gate_EntityRef, slop_list_howl_gate_EntityRef)
#endif

howl_types_InputRef howl_gate_axiom_input_ref(slop_arena* arena, howl_owl2_RawAxiom ax);
slop_option_howl_types_RoleId howl_gate_least_role(slop_list_howl_types_RoleId rs);
howl_owl2_RawAxiom howl_gate_transitive_chain(slop_arena* arena, howl_types_RoleId r);
slop_list_howl_owl2_RawAxiom howl_gate_push_property_star(slop_list_howl_owl2_RawAxiom out, howl_owl2_RawAxiom ax, slop_list_howl_types_RoleId rs);
slop_list_howl_owl2_RawAxiom howl_gate_push_class_star(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, slop_list_howl_owl2_RawConcept cs);
slop_list_howl_owl2_RawAxiom howl_gate_push_pairs_from(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, slop_list_howl_owl2_RawConcept sorted, int64_t i, int64_t n);
slop_list_howl_owl2_RawAxiom howl_gate_push_disjoint_pairs(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, howl_owl2_RawAxiom ax, slop_list_howl_owl2_RawConcept cs);
slop_list_howl_owl2_RawAxiom howl_gate_expand_sugar(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
uint8_t howl_gate_has_negated_conjunct(howl_owl2_RawConcept c);
slop_list_howl_owl2_RawConcept howl_gate_conjuncts(slop_arena* arena, howl_owl2_RawConcept c);
howl_gate_NegSplit howl_gate_negation_split(slop_arena* arena, howl_owl2_RawConcept c);
uint8_t howl_gate_split_rewritable(howl_types_Profile p, howl_gate_NegSplit s);
howl_owl2_RawConcept howl_gate_conjunction(slop_list_howl_owl2_RawConcept cs);
howl_owl2_RawConcept howl_gate_with_conjunct(slop_arena* arena, howl_owl2_RawConcept c, howl_owl2_RawConcept e);
howl_owl2_RawAxiom howl_gate_empty_axiom(slop_arena* arena, howl_owl2_RawConcept c);
slop_option_howl_gate_NegSplit howl_gate_sub_negation_split(slop_arena* arena, howl_types_Profile p, howl_owl2_RawConcept l, howl_owl2_RawConcept r);
slop_option_howl_gate_NegSplit howl_gate_role_negation_split(slop_arena* arena, howl_types_Profile p, howl_types_RoleId r, howl_owl2_RawConcept c);
slop_list_howl_owl2_RawAxiom howl_gate_push_sub_pieces(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, howl_owl2_RawConcept* l, howl_gate_NegSplit s);
slop_list_howl_owl2_RawAxiom howl_gate_push_domain_pieces(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, howl_types_RoleId r, howl_gate_NegSplit s);
slop_list_howl_owl2_RawAxiom howl_gate_push_range_pieces(slop_arena* arena, slop_list_howl_owl2_RawAxiom out, howl_types_RoleId r, howl_gate_NegSplit s);
slop_list_howl_owl2_RawAxiom howl_gate_expand_negation(slop_arena* arena, howl_types_Profile p, slop_list_howl_owl2_RawAxiom axs);
uint8_t howl_gate_is_top_role(howl_types_RoleId r);
uint8_t howl_gate_is_inverse_role(howl_types_RoleId r);
uint8_t howl_gate_roles_have_inverse(slop_list_howl_types_RoleId rs);
uint8_t howl_gate_axiom_has_inverse(howl_owl2_RawAxiom ax);
slop_list_howl_owl2_RawAxiom howl_gate_named_roles_only(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
uint8_t howl_gate_into_top_role(howl_owl2_RawAxiom ax);
slop_list_howl_owl2_RawAxiom howl_gate_drop_top_role_tautologies(slop_arena* arena, howl_types_Profile p, slop_list_howl_owl2_RawAxiom axs);
uint8_t howl_gate_role_listed(slop_list_howl_types_RoleId rs, howl_types_RoleId r);
slop_list_howl_types_RoleId howl_gate_non_simple_roles(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
slop_option_howl_types_RoleId howl_gate_concept_self_nonsimple(slop_list_howl_types_RoleId nonsimple, howl_owl2_RawConcept c);
slop_option_howl_types_RoleId howl_gate_concepts_self_nonsimple(slop_list_howl_types_RoleId nonsimple, slop_list_howl_owl2_RawConcept cs);
slop_option_howl_types_RoleId howl_gate_self_role_nonsimple(slop_list_howl_types_RoleId nonsimple, howl_owl2_RawAxiom ax);
uint8_t howl_gate_self_roles_simple(slop_list_howl_types_RoleId nonsimple, howl_owl2_RawAxiom ax);
howl_owl2_RawConcept* howl_gate_box_c(slop_arena* arena, howl_owl2_RawConcept c);
slop_list_howl_owl2_RawAxiom howl_gate_admitted(slop_arena* arena, howl_types_Profile p, slop_list_howl_owl2_RawAxiom axs);
uint8_t howl_gate_is_rbox_axiom(howl_owl2_RawAxiom ax);
uint8_t howl_gate_axiom_range_ok(slop_list_howl_gate_RangeEntry entries, slop_list_u8 told, int64_t n, slop_list_howl_types_RoleId roles, howl_owl2_RawAxiom ax);
howl_gate_GateResult howl_gate_gate_axioms(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, howl_owl2_Signature sig, slop_list_howl_types_Omission carried, howl_types_Profile p);
howl_types_OmissionCause howl_gate_form_cause(howl_types_Profile p, howl_owl2_RawAxiom ax);
slop_option_howl_types_OmissionCause howl_gate_gate_verdict(slop_arena* arena, howl_types_Profile p, uint8_t sriq, uint8_t rbox_bad, howl_sriqrbox_SriqRbox srb, slop_list_howl_types_RoleId nonsimple, slop_list_howl_gate_RangeEntry ranges, slop_list_u8 told, int64_t nr, slop_list_howl_types_RoleId rroles, howl_owl2_RawAxiom ax);
howl_types_OmissionCause howl_gate_cause_at(slop_list_howl_types_OmissionCause cs, int64_t i);
slop_list_howl_owl2_RawAxiom howl_gate_gate_expand(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, howl_types_Profile p);
uint8_t howl_gate_piece_read(howl_types_Profile p, howl_owl2_RawAxiom ax);
uint8_t howl_gate_piece_omitted(howl_types_Profile p, howl_owl2_RawAxiom ax);
slop_list_howl_owl2_RawAxiom howl_gate_one_axiom(slop_arena* arena, howl_owl2_RawAxiom ax);
uint8_t howl_gate_unread_by_every(slop_arena* arena, howl_owl2_RawAxiom ax, slop_list_howl_types_Profile rungs);
uint8_t howl_gate_module_omissions_shared(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_list_howl_types_Omission carried, slop_list_howl_types_Omission oms, howl_types_Profile p, slop_list_howl_types_Profile rungs);
slop_list_int howl_gate_omission_origins(slop_arena* arena, slop_arena* scratch, slop_list_howl_types_Omission oms, slop_list_howl_owl2_RawAxiom axs, slop_list_int adocs, slop_list_howl_types_Omission carried, slop_list_int cdocs, int64_t documents, howl_types_Profile p);
slop_map* howl_gate_needed_texts(slop_arena* arena, slop_list_howl_types_Omission oms);
slop_map* howl_gate_texts_to_docs(slop_arena* arena, slop_map* needed, slop_list_howl_owl2_RawAxiom axs, slop_list_int adocs, howl_types_Profile p);
slop_list_int howl_gate_insert_ascending(slop_arena* arena, slop_list_int xs, int64_t x);
int64_t howl_gate_nth_doc(slop_map* by_text, slop_string t, int64_t k);
int64_t howl_gate_carried_doc(howl_types_Omission o, slop_list_howl_types_Omission carried, slop_list_int cdocs);
uint8_t howl_gate_rbox_omits(uint8_t sriq, uint8_t rbox_bad, howl_owl2_RawAxiom ax);
slop_list_howl_owl2_RawAxiom howl_gate_sort_axioms(slop_arena* arena, slop_list_howl_owl2_RawAxiom xs);
slop_list_string howl_gate_axiom_texts(slop_arena* arena, slop_list_howl_owl2_RawAxiom xs);
howl_owl2_RawAxiom howl_gate_axiom_at(slop_list_howl_owl2_RawAxiom xs, int64_t i);
int64_t howl_gate_role_idx(slop_list_howl_types_RoleId roles, howl_types_RoleId r);
uint8_t howl_gate_push_role_unique(slop_list_howl_types_RoleId rs, howl_types_RoleId r);
slop_list_howl_types_RoleId howl_gate_collect_rbox_roles(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
slop_list_howl_types_RoleId howl_gate_sort_roles(slop_arena* arena, slop_list_howl_types_RoleId xs);
howl_types_RoleId howl_gate_role_at(slop_list_howl_types_RoleId xs, int64_t i);
slop_list_u8 howl_gate_mat_new(slop_arena* arena, int64_t cells);
uint8_t howl_gate_mat_get(slop_list_u8 m, int64_t i);
uint8_t howl_gate_mat_or_row(slop_list_u8 m, int64_t n, int64_t k, int64_t i);
uint8_t howl_gate_mat_close_through(slop_list_u8 m, int64_t n, int64_t k);
uint8_t howl_gate_mat_close(slop_list_u8 m, int64_t n);
slop_list_u8 howl_gate_told_closure(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_list_howl_types_RoleId roles, int64_t n);
int64_t howl_gate_candidate_size(howl_owl2_RawChain ch, int64_t from, int64_t to);
uint8_t howl_gate_seen_before(slop_list_howl_types_RoleId steps, int64_t from, int64_t i);
uint8_t howl_gate_add_chain_constraints(howl_owl2_RawChain ch, slop_list_howl_types_RoleId roles, int64_t n, slop_list_u8 cmat, int64_t from, int64_t to);
slop_string howl_gate_describe_violation(slop_arena* arena, slop_list_howl_types_RoleId roles, int64_t i, int64_t j);
uint8_t howl_gate_add_dominant_case(howl_owl2_RawChain ch, slop_list_howl_types_RoleId roles, int64_t n, slop_list_u8 cmat, int64_t len, uint8_t left_ok, uint8_t right_ok);
uint8_t howl_gate_add_case_constraints(howl_owl2_RawChain ch, slop_list_howl_types_RoleId roles, int64_t n, slop_list_u8 cmat);
int64_t howl_gate_row_violation(slop_list_u8 cmat, slop_list_u8 told, int64_t n, int64_t i);
howl_gate_RboxVerdict howl_gate_regularity_verdict(slop_arena* arena, slop_list_howl_types_RoleId roles, slop_list_u8 cmat, slop_list_u8 told, int64_t n);
howl_gate_RboxVerdict howl_gate_check_regularity(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
slop_list_howl_gate_RangeEntry howl_gate_collect_ranges(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_list_howl_types_RoleId roles);
uint8_t howl_gate_has_inherited_range(slop_list_howl_gate_RangeEntry entries, slop_list_u8 told, int64_t n, int64_t base, howl_owl2_RawConcept c);
uint8_t howl_gate_chain_range_ok(slop_list_howl_gate_RangeEntry entries, slop_list_u8 told, int64_t n, slop_list_howl_types_RoleId roles, howl_owl2_RawChain ch);
howl_types_AxiomRef howl_gate_axiom_ref_of(slop_arena* arena, howl_owl2_RawAxiom ax);
slop_list_slop_rdf_rdf_IRI howl_gate_collect_concept_classes(slop_arena* arena, howl_owl2_RawConcept c, slop_list_slop_rdf_rdf_IRI acc);
slop_list_howl_gate_EntityRef howl_gate_collect_entity_refs(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
uint8_t howl_gate_entity_ref_declared(howl_owl2_Signature sig, howl_gate_EntityRef e);
uint8_t howl_gate_same_entity(howl_gate_EntityRef a, howl_gate_EntityRef b);
uint8_t howl_gate_has_entity(slop_list_howl_gate_EntityRef seen, howl_gate_EntityRef e);
howl_types_Omission howl_gate_missing_declaration_of(slop_arena* arena, howl_gate_EntityRef e, slop_list_howl_gate_EntityRef refs);
slop_list_howl_types_Omission howl_gate_missing_declarations(slop_arena* arena, howl_owl2_Signature sig, slop_list_howl_gate_EntityRef refs);

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSIONCAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSIONCAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_OmissionCause, slop_option_howl_types_OmissionCause)
#endif

#ifndef SLOP_OPTION_HOWL_GATE_GATERESULT_DEFINED
#define SLOP_OPTION_HOWL_GATE_GATERESULT_DEFINED
SLOP_OPTION_DEFINE(howl_gate_GateResult, slop_option_howl_gate_GateResult)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_GATE_NEGSPLIT_DEFINED
#define SLOP_OPTION_HOWL_GATE_NEGSPLIT_DEFINED
SLOP_OPTION_DEFINE(howl_gate_NegSplit, slop_option_howl_gate_NegSplit)
#endif

#ifndef SLOP_OPTION_HOWL_GATE_RANGEENTRY_DEFINED
#define SLOP_OPTION_HOWL_GATE_RANGEENTRY_DEFINED
SLOP_OPTION_DEFINE(howl_gate_RangeEntry, slop_option_howl_gate_RangeEntry)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_PROFILE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_PROFILE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Profile, slop_option_howl_types_Profile)
#endif

#ifndef SLOP_OPTION_LIST_INT_DEFINED
#define SLOP_OPTION_LIST_INT_DEFINED
SLOP_OPTION_DEFINE(slop_list_int, slop_option_list_int)
#endif

#ifndef SLOP_OPTION_HOWL_GATE_RBOXVERDICT_DEFINED
#define SLOP_OPTION_HOWL_GATE_RBOXVERDICT_DEFINED
SLOP_OPTION_DEFINE(howl_gate_RboxVerdict, slop_option_howl_gate_RboxVerdict)
#endif

#ifndef SLOP_OPTION_HOWL_GATE_ENTITYREF_DEFINED
#define SLOP_OPTION_HOWL_GATE_ENTITYREF_DEFINED
SLOP_OPTION_DEFINE(howl_gate_EntityRef, slop_option_howl_gate_EntityRef)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
SLOP_OPTION_DEFINE(howl_types_AxiomRef, slop_option_howl_types_AxiomRef)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_HOWL_TYPES_AXIOMREF_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_AxiomRef, slop_list_howl_types_AxiomRef)
#endif


#endif
