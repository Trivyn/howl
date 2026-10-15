#ifndef SLOP_owl2_H
#define SLOP_owl2_H

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
#include "slop_canon.h"
#include "slop_types.h"

typedef struct howl_owl2_RawConcept howl_owl2_RawConcept;
typedef struct howl_owl2_RawChain howl_owl2_RawChain;
typedef struct howl_owl2_RawEdge howl_owl2_RawEdge;
typedef struct howl_owl2_RawClassAssertion howl_owl2_RawClassAssertion;
typedef struct howl_owl2_RawDeclaration howl_owl2_RawDeclaration;
typedef struct howl_owl2_RawDisjointUnion howl_owl2_RawDisjointUnion;
typedef struct howl_owl2_RawAxiom howl_owl2_RawAxiom;
typedef struct howl_owl2_Signature howl_owl2_Signature;

typedef enum {
    howl_owl2_CardKind_card_min,
    howl_owl2_CardKind_card_max,
    howl_owl2_CardKind_card_exact
} howl_owl2_CardKind;

typedef enum {
    howl_owl2_PropCharacteristic_prop_functional,
    howl_owl2_PropCharacteristic_prop_inverse_functional,
    howl_owl2_PropCharacteristic_prop_symmetric,
    howl_owl2_PropCharacteristic_prop_asymmetric,
    howl_owl2_PropCharacteristic_prop_reflexive,
    howl_owl2_PropCharacteristic_prop_irreflexive
} howl_owl2_PropCharacteristic;

typedef enum {
    howl_owl2_Disposition_d_in_profile,
    howl_owl2_Disposition_d_inert,
    howl_owl2_Disposition_d_consumed,
    howl_owl2_Disposition_d_out_of_profile
} howl_owl2_Disposition;

#ifndef SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Node, slop_list_howl_types_Node)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_RoleId, slop_list_howl_types_RoleId)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

struct howl_owl2_RawChain {
    slop_list_howl_types_RoleId steps;
    howl_types_RoleId super;
};
typedef struct howl_owl2_RawChain howl_owl2_RawChain;

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCHAIN_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCHAIN_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawChain, slop_option_howl_owl2_RawChain)
#endif

struct howl_owl2_RawEdge {
    howl_types_RoleId role;
    howl_types_Node from;
    howl_types_Node to;
};
typedef struct howl_owl2_RawEdge howl_owl2_RawEdge;

#ifndef SLOP_OPTION_HOWL_OWL2_RAWEDGE_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWEDGE_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawEdge, slop_option_howl_owl2_RawEdge)
#endif

struct howl_owl2_RawClassAssertion {
    howl_owl2_RawConcept* concept;
    howl_types_Node subject;
};
typedef struct howl_owl2_RawClassAssertion howl_owl2_RawClassAssertion;

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCLASSASSERTION_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCLASSASSERTION_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawClassAssertion, slop_option_howl_owl2_RawClassAssertion)
#endif

struct howl_owl2_RawDeclaration {
    howl_types_EntityKind kind;
    slop_rdf_rdf_IRI entity;
};
typedef struct howl_owl2_RawDeclaration howl_owl2_RawDeclaration;

#ifndef SLOP_OPTION_HOWL_OWL2_RAWDECLARATION_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWDECLARATION_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawDeclaration, slop_option_howl_owl2_RawDeclaration)
#endif

struct howl_owl2_Signature {
    slop_map* classes;
    slop_map* obj_props;
    slop_map* data_props;
    slop_map* annot_props;
    slop_map* individuals;
    slop_map* datatypes;
};
typedef struct howl_owl2_Signature howl_owl2_Signature;

#ifndef SLOP_OPTION_HOWL_OWL2_SIGNATURE_DEFINED
#define SLOP_OPTION_HOWL_OWL2_SIGNATURE_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_Signature, slop_option_howl_owl2_Signature)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_LIST_DECLARE(howl_owl2_RawConcept, slop_list_howl_owl2_RawConcept)
#endif

typedef enum {
    howl_owl2_RawConcept_rc_name,
    howl_owl2_RawConcept_rc_thing,
    howl_owl2_RawConcept_rc_nothing,
    howl_owl2_RawConcept_rc_and,
    howl_owl2_RawConcept_rc_some,
    howl_owl2_RawConcept_rc_or,
    howl_owl2_RawConcept_rc_not,
    howl_owl2_RawConcept_rc_all,
    howl_owl2_RawConcept_rc_oneof,
    howl_owl2_RawConcept_rc_has_value,
    howl_owl2_RawConcept_rc_has_self,
    howl_owl2_RawConcept_rc_card,
    howl_owl2_RawConcept_rc_qcard,
    howl_owl2_RawConcept_rc_data,
    howl_owl2_RawConcept_rc_anon
} howl_owl2_RawConcept_tag;

struct howl_owl2_RawConcept {
    howl_owl2_RawConcept_tag tag;
    union {
        howl_types_Node rc_name;
        slop_list_howl_owl2_RawConcept rc_and;
        struct {
            howl_types_RoleId f0;
            howl_owl2_RawConcept* f1;
        } rc_some;
        slop_list_howl_owl2_RawConcept rc_or;
        howl_owl2_RawConcept* rc_not;
        struct {
            howl_types_RoleId f0;
            howl_owl2_RawConcept* f1;
        } rc_all;
        slop_list_howl_types_Node rc_oneof;
        struct {
            howl_types_RoleId f0;
            howl_types_Node f1;
        } rc_has_value;
        howl_types_RoleId rc_has_self;
        struct {
            howl_owl2_CardKind f0;
            howl_types_RoleId f1;
            int64_t f2;
        } rc_card;
        struct {
            howl_owl2_CardKind f0;
            howl_types_RoleId f1;
            int64_t f2;
            howl_owl2_RawConcept* f3;
        } rc_qcard;
        howl_types_InputRef rc_data;
        howl_types_InputRef rc_anon;
    } data;
};
typedef struct howl_owl2_RawConcept howl_owl2_RawConcept;

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWCONCEPT_IMPL_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_IMPL(howl_owl2_RawConcept, slop_list_howl_owl2_RawConcept)
#endif

struct howl_owl2_RawDisjointUnion {
    slop_rdf_rdf_IRI class;
    slop_list_howl_owl2_RawConcept members;
};
typedef struct howl_owl2_RawDisjointUnion howl_owl2_RawDisjointUnion;

#ifndef SLOP_OPTION_HOWL_OWL2_RAWDISJOINTUNION_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWDISJOINTUNION_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawDisjointUnion, slop_option_howl_owl2_RawDisjointUnion)
#endif

typedef enum {
    howl_owl2_RawAxiom_ra_sub_class_of,
    howl_owl2_RawAxiom_ra_equivalent_classes,
    howl_owl2_RawAxiom_ra_disjoint_classes,
    howl_owl2_RawAxiom_ra_sub_object_property,
    howl_owl2_RawAxiom_ra_property_chain,
    howl_owl2_RawAxiom_ra_equivalent_properties,
    howl_owl2_RawAxiom_ra_transitive_property,
    howl_owl2_RawAxiom_ra_object_property_domain,
    howl_owl2_RawAxiom_ra_object_property_range,
    howl_owl2_RawAxiom_ra_class_assertion,
    howl_owl2_RawAxiom_ra_object_property_assertion,
    howl_owl2_RawAxiom_ra_declaration,
    howl_owl2_RawAxiom_ra_annotation,
    howl_owl2_RawAxiom_ra_inert_data,
    howl_owl2_RawAxiom_ra_inverse_properties,
    howl_owl2_RawAxiom_ra_property_characteristic,
    howl_owl2_RawAxiom_ra_disjoint_properties,
    howl_owl2_RawAxiom_ra_same_individual,
    howl_owl2_RawAxiom_ra_different_individuals,
    howl_owl2_RawAxiom_ra_negative_assertion,
    howl_owl2_RawAxiom_ra_disjoint_union,
    howl_owl2_RawAxiom_ra_has_key,
    howl_owl2_RawAxiom_ra_data_axiom,
    howl_owl2_RawAxiom_ra_builtin_role,
    howl_owl2_RawAxiom_ra_anonymous_individual,
    howl_owl2_RawAxiom_ra_reserved_vocabulary,
    howl_owl2_RawAxiom_ra_swrl_rule,
    howl_owl2_RawAxiom_ra_unrecognized
} howl_owl2_RawAxiom_tag;

struct howl_owl2_RawAxiom {
    howl_owl2_RawAxiom_tag tag;
    union {
        struct {
            howl_owl2_RawConcept* f0;
            howl_owl2_RawConcept* f1;
        } ra_sub_class_of;
        slop_list_howl_owl2_RawConcept ra_equivalent_classes;
        slop_list_howl_owl2_RawConcept ra_disjoint_classes;
        struct {
            howl_types_RoleId f0;
            howl_types_RoleId f1;
        } ra_sub_object_property;
        howl_owl2_RawChain ra_property_chain;
        slop_list_howl_types_RoleId ra_equivalent_properties;
        howl_types_RoleId ra_transitive_property;
        struct {
            howl_types_RoleId f0;
            howl_owl2_RawConcept* f1;
        } ra_object_property_domain;
        struct {
            howl_types_RoleId f0;
            howl_owl2_RawConcept* f1;
        } ra_object_property_range;
        howl_owl2_RawClassAssertion ra_class_assertion;
        howl_owl2_RawEdge ra_object_property_assertion;
        howl_owl2_RawDeclaration ra_declaration;
        struct {
            howl_types_RoleId f0;
            howl_types_RoleId f1;
        } ra_inverse_properties;
        struct {
            howl_owl2_PropCharacteristic f0;
            howl_types_RoleId f1;
        } ra_property_characteristic;
        slop_list_howl_types_RoleId ra_disjoint_properties;
        slop_list_howl_types_Node ra_same_individual;
        slop_list_howl_types_Node ra_different_individuals;
        howl_owl2_RawEdge ra_negative_assertion;
        howl_owl2_RawDisjointUnion ra_disjoint_union;
        howl_types_InputRef ra_has_key;
        howl_types_InputRef ra_data_axiom;
        howl_types_InputRef ra_builtin_role;
        howl_types_InputRef ra_anonymous_individual;
        howl_types_InputRef ra_reserved_vocabulary;
        howl_types_InputRef ra_swrl_rule;
        howl_types_InputRef ra_unrecognized;
    } data;
};
typedef struct howl_owl2_RawAxiom howl_owl2_RawAxiom;

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawAxiom, slop_list_howl_owl2_RawAxiom)
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

howl_owl2_Disposition howl_owl2_disposition(howl_types_Profile p, howl_owl2_RawAxiom ax);
howl_owl2_Signature howl_owl2_make_signature(slop_arena* arena);
uint8_t howl_owl2_signature_has_class(howl_owl2_Signature sig, slop_rdf_rdf_IRI i);
uint8_t howl_owl2_signature_has_object_property(howl_owl2_Signature sig, slop_rdf_rdf_IRI i);
uint8_t howl_owl2_signature_has_annotation_property(howl_owl2_Signature sig, slop_rdf_rdf_IRI i);
uint8_t howl_owl2_signature_has_data_property(howl_owl2_Signature sig, slop_rdf_rdf_IRI i);
int64_t howl_owl2_signature_size(slop_arena* arena, howl_owl2_Signature sig);
uint8_t howl_owl2_is_el_plus_plus(howl_types_Profile p);
howl_owl2_Disposition howl_owl2_when_el_plus_plus(howl_types_Profile p);
uint8_t howl_owl2_is_sriq(howl_types_Profile p);
howl_owl2_Disposition howl_owl2_when_sriq(howl_types_Profile p);
howl_owl2_Disposition howl_owl2_when_el_plus_plus_or_sriq(howl_types_Profile p);
uint8_t howl_owl2_role_in_profile(howl_types_Profile p, howl_types_RoleId r);
uint8_t howl_owl2_roles_in_profile(howl_types_Profile p, slop_list_howl_types_RoleId rs);
uint8_t howl_owl2_concepts_in_profile(howl_types_Profile p, slop_list_howl_owl2_RawConcept cs);
uint8_t howl_owl2_concept_in_profile(howl_types_Profile p, howl_owl2_RawConcept c);
uint8_t howl_owl2_axiom_in_profile(howl_types_Profile p, howl_owl2_RawAxiom ax);
int64_t howl_owl2_concept_tag_rank(howl_owl2_RawConcept c);
int64_t howl_owl2_concept_list_cmp(slop_list_howl_owl2_RawConcept a, slop_list_howl_owl2_RawConcept b);
howl_owl2_RawConcept howl_owl2_concept_at(slop_list_howl_owl2_RawConcept xs, int64_t i);
int64_t howl_owl2_concept_cmp(howl_owl2_RawConcept a, howl_owl2_RawConcept b);
int64_t howl_owl2_card_cmp(howl_owl2_CardKind ka, howl_types_RoleId ra, int64_t na, howl_owl2_CardKind kb, howl_types_RoleId rb, int64_t nb);
int64_t howl_owl2_card_rank(howl_owl2_CardKind k);
int64_t howl_owl2_node_list_cmp(slop_list_howl_types_Node a, slop_list_howl_types_Node b);
slop_string howl_owl2_render_role(slop_arena* arena, howl_types_RoleId r);
slop_string howl_owl2_render_node(howl_types_Node n);
slop_string howl_owl2_render_card_kind(howl_owl2_CardKind k);
slop_string howl_owl2_render_concept_list(slop_arena* arena, slop_list_howl_owl2_RawConcept cs);
slop_string howl_owl2_render_node_list(slop_arena* arena, slop_list_howl_types_Node ns);
slop_string howl_owl2_render_role_list(slop_arena* arena, slop_list_howl_types_RoleId rs);
slop_string howl_owl2_wrap(slop_arena* arena, slop_string head, slop_string body);
slop_string howl_owl2_join2(slop_arena* arena, slop_string a, slop_string b);
slop_string howl_owl2_render_concept(slop_arena* arena, howl_owl2_RawConcept c);
slop_string howl_owl2_render_input_ref(howl_types_InputRef r);
slop_string howl_owl2_render_entity_kind(howl_types_EntityKind k);
slop_string howl_owl2_render_omission(slop_arena* arena, howl_types_Omission o);
slop_string howl_owl2_render_axiom(slop_arena* arena, howl_owl2_RawAxiom ax);
slop_string howl_owl2_render_characteristic(howl_owl2_PropCharacteristic c);
howl_owl2_RawConcept howl_owl2_copy_concept(slop_arena* arena, howl_owl2_RawConcept c);
howl_owl2_RawConcept* howl_owl2_copy_boxed(slop_arena* arena, howl_owl2_RawConcept* p);
slop_list_howl_owl2_RawConcept howl_owl2_copy_concepts(slop_arena* arena, slop_list_howl_owl2_RawConcept cs);
slop_list_howl_types_Node howl_owl2_copy_nodes(slop_arena* arena, slop_list_howl_types_Node ns);
slop_list_howl_types_RoleId howl_owl2_copy_roles(slop_arena* arena, slop_list_howl_types_RoleId rs);
howl_owl2_RawAxiom howl_owl2_copy_raw_axiom(slop_arena* arena, howl_owl2_RawAxiom ax);
howl_owl2_RawAxiom howl_owl2_raw_axiom_at(slop_list_howl_owl2_RawAxiom xs, int64_t i);
slop_list_howl_owl2_RawAxiom howl_owl2_copy_axioms(slop_arena* arena, slop_list_howl_owl2_RawAxiom xs);
howl_owl2_Signature howl_owl2_copy_signature(slop_arena* arena, howl_owl2_Signature sig);
slop_list_howl_owl2_RawConcept howl_owl2_sort_concepts(slop_arena* arena, slop_list_howl_owl2_RawConcept xs);

#define howl_owl2_SRIQ_MAX_COUNT (16)

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCHAIN_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCHAIN_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawChain, slop_option_howl_owl2_RawChain)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWEDGE_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWEDGE_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawEdge, slop_option_howl_owl2_RawEdge)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCLASSASSERTION_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCLASSASSERTION_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawClassAssertion, slop_option_howl_owl2_RawClassAssertion)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWDECLARATION_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWDECLARATION_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawDeclaration, slop_option_howl_owl2_RawDeclaration)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWDISJOINTUNION_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWDISJOINTUNION_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawDisjointUnion, slop_option_howl_owl2_RawDisjointUnion)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_SIGNATURE_DEFINED
#define SLOP_OPTION_HOWL_OWL2_SIGNATURE_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_Signature, slop_option_howl_owl2_Signature)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWCONCEPT_IMPL_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_IMPL(howl_owl2_RawConcept, slop_list_howl_owl2_RawConcept)
#endif


#endif
