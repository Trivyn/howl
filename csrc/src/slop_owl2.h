#ifndef SLOP_owl2_H
#define SLOP_owl2_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_canon.h"
#include "slop_types.h"

typedef struct owl2_RawConcept owl2_RawConcept;
typedef struct owl2_RawChain owl2_RawChain;
typedef struct owl2_RawEdge owl2_RawEdge;
typedef struct owl2_RawClassAssertion owl2_RawClassAssertion;
typedef struct owl2_RawDeclaration owl2_RawDeclaration;
typedef struct owl2_RawDisjointUnion owl2_RawDisjointUnion;
typedef struct owl2_RawAxiom owl2_RawAxiom;
typedef struct owl2_Signature owl2_Signature;

typedef enum {
    owl2_CardKind_card_min,
    owl2_CardKind_card_max,
    owl2_CardKind_card_exact
} owl2_CardKind;

typedef enum {
    owl2_PropCharacteristic_prop_functional,
    owl2_PropCharacteristic_prop_inverse_functional,
    owl2_PropCharacteristic_prop_symmetric,
    owl2_PropCharacteristic_prop_asymmetric,
    owl2_PropCharacteristic_prop_reflexive,
    owl2_PropCharacteristic_prop_irreflexive
} owl2_PropCharacteristic;

typedef enum {
    owl2_Disposition_d_in_profile,
    owl2_Disposition_d_inert,
    owl2_Disposition_d_consumed,
    owl2_Disposition_d_out_of_profile
} owl2_Disposition;

#ifndef SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Node, slop_list_types_Node)
#endif

#ifndef SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(types_RoleId, slop_list_types_RoleId)
#endif

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

struct owl2_RawChain {
    slop_list_types_RoleId steps;
    types_RoleId super;
};
typedef struct owl2_RawChain owl2_RawChain;

#ifndef SLOP_OPTION_OWL2_RAWCHAIN_DEFINED
#define SLOP_OPTION_OWL2_RAWCHAIN_DEFINED
SLOP_OPTION_DEFINE(owl2_RawChain, slop_option_owl2_RawChain)
#endif

struct owl2_RawEdge {
    types_RoleId role;
    types_Node from;
    types_Node to;
};
typedef struct owl2_RawEdge owl2_RawEdge;

#ifndef SLOP_OPTION_OWL2_RAWEDGE_DEFINED
#define SLOP_OPTION_OWL2_RAWEDGE_DEFINED
SLOP_OPTION_DEFINE(owl2_RawEdge, slop_option_owl2_RawEdge)
#endif

struct owl2_RawClassAssertion {
    owl2_RawConcept* concept;
    types_Node subject;
};
typedef struct owl2_RawClassAssertion owl2_RawClassAssertion;

#ifndef SLOP_OPTION_OWL2_RAWCLASSASSERTION_DEFINED
#define SLOP_OPTION_OWL2_RAWCLASSASSERTION_DEFINED
SLOP_OPTION_DEFINE(owl2_RawClassAssertion, slop_option_owl2_RawClassAssertion)
#endif

struct owl2_RawDeclaration {
    types_EntityKind kind;
    rdf_IRI entity;
};
typedef struct owl2_RawDeclaration owl2_RawDeclaration;

#ifndef SLOP_OPTION_OWL2_RAWDECLARATION_DEFINED
#define SLOP_OPTION_OWL2_RAWDECLARATION_DEFINED
SLOP_OPTION_DEFINE(owl2_RawDeclaration, slop_option_owl2_RawDeclaration)
#endif

struct owl2_Signature {
    slop_map* classes;
    slop_map* obj_props;
    slop_map* data_props;
    slop_map* annot_props;
    slop_map* individuals;
    slop_map* datatypes;
};
typedef struct owl2_Signature owl2_Signature;

#ifndef SLOP_OPTION_OWL2_SIGNATURE_DEFINED
#define SLOP_OPTION_OWL2_SIGNATURE_DEFINED
SLOP_OPTION_DEFINE(owl2_Signature, slop_option_owl2_Signature)
#endif

#ifndef SLOP_LIST_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_DEFINED
SLOP_LIST_DECLARE(owl2_RawConcept, slop_list_owl2_RawConcept)
#endif

typedef enum {
    owl2_RawConcept_rc_name,
    owl2_RawConcept_rc_thing,
    owl2_RawConcept_rc_nothing,
    owl2_RawConcept_rc_and,
    owl2_RawConcept_rc_some,
    owl2_RawConcept_rc_or,
    owl2_RawConcept_rc_not,
    owl2_RawConcept_rc_all,
    owl2_RawConcept_rc_oneof,
    owl2_RawConcept_rc_has_value,
    owl2_RawConcept_rc_has_self,
    owl2_RawConcept_rc_card,
    owl2_RawConcept_rc_qcard,
    owl2_RawConcept_rc_data,
    owl2_RawConcept_rc_anon
} owl2_RawConcept_tag;

struct owl2_RawConcept {
    owl2_RawConcept_tag tag;
    union {
        types_Node rc_name;
        slop_list_owl2_RawConcept rc_and;
        struct {
            types_RoleId f0;
            owl2_RawConcept* f1;
        } rc_some;
        slop_list_owl2_RawConcept rc_or;
        owl2_RawConcept* rc_not;
        struct {
            types_RoleId f0;
            owl2_RawConcept* f1;
        } rc_all;
        slop_list_types_Node rc_oneof;
        struct {
            types_RoleId f0;
            types_Node f1;
        } rc_has_value;
        types_RoleId rc_has_self;
        struct {
            owl2_CardKind f0;
            types_RoleId f1;
            int64_t f2;
        } rc_card;
        struct {
            owl2_CardKind f0;
            types_RoleId f1;
            int64_t f2;
            owl2_RawConcept* f3;
        } rc_qcard;
        types_InputRef rc_data;
        types_InputRef rc_anon;
    } data;
};
typedef struct owl2_RawConcept owl2_RawConcept;

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_LIST_OWL2_RAWCONCEPT_IMPL_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_IMPL(owl2_RawConcept, slop_list_owl2_RawConcept)
#endif

struct owl2_RawDisjointUnion {
    rdf_IRI class;
    slop_list_owl2_RawConcept members;
};
typedef struct owl2_RawDisjointUnion owl2_RawDisjointUnion;

#ifndef SLOP_OPTION_OWL2_RAWDISJOINTUNION_DEFINED
#define SLOP_OPTION_OWL2_RAWDISJOINTUNION_DEFINED
SLOP_OPTION_DEFINE(owl2_RawDisjointUnion, slop_option_owl2_RawDisjointUnion)
#endif

typedef enum {
    owl2_RawAxiom_ra_sub_class_of,
    owl2_RawAxiom_ra_equivalent_classes,
    owl2_RawAxiom_ra_disjoint_classes,
    owl2_RawAxiom_ra_sub_object_property,
    owl2_RawAxiom_ra_property_chain,
    owl2_RawAxiom_ra_equivalent_properties,
    owl2_RawAxiom_ra_transitive_property,
    owl2_RawAxiom_ra_object_property_domain,
    owl2_RawAxiom_ra_object_property_range,
    owl2_RawAxiom_ra_class_assertion,
    owl2_RawAxiom_ra_object_property_assertion,
    owl2_RawAxiom_ra_declaration,
    owl2_RawAxiom_ra_annotation,
    owl2_RawAxiom_ra_inert_data,
    owl2_RawAxiom_ra_inverse_properties,
    owl2_RawAxiom_ra_property_characteristic,
    owl2_RawAxiom_ra_disjoint_properties,
    owl2_RawAxiom_ra_same_individual,
    owl2_RawAxiom_ra_different_individuals,
    owl2_RawAxiom_ra_negative_assertion,
    owl2_RawAxiom_ra_disjoint_union,
    owl2_RawAxiom_ra_has_key,
    owl2_RawAxiom_ra_data_axiom,
    owl2_RawAxiom_ra_builtin_role,
    owl2_RawAxiom_ra_anonymous_individual,
    owl2_RawAxiom_ra_reserved_vocabulary,
    owl2_RawAxiom_ra_swrl_rule,
    owl2_RawAxiom_ra_unrecognized
} owl2_RawAxiom_tag;

struct owl2_RawAxiom {
    owl2_RawAxiom_tag tag;
    union {
        struct {
            owl2_RawConcept* f0;
            owl2_RawConcept* f1;
        } ra_sub_class_of;
        slop_list_owl2_RawConcept ra_equivalent_classes;
        slop_list_owl2_RawConcept ra_disjoint_classes;
        struct {
            types_RoleId f0;
            types_RoleId f1;
        } ra_sub_object_property;
        owl2_RawChain ra_property_chain;
        slop_list_types_RoleId ra_equivalent_properties;
        types_RoleId ra_transitive_property;
        struct {
            types_RoleId f0;
            owl2_RawConcept* f1;
        } ra_object_property_domain;
        struct {
            types_RoleId f0;
            owl2_RawConcept* f1;
        } ra_object_property_range;
        owl2_RawClassAssertion ra_class_assertion;
        owl2_RawEdge ra_object_property_assertion;
        owl2_RawDeclaration ra_declaration;
        struct {
            types_RoleId f0;
            types_RoleId f1;
        } ra_inverse_properties;
        struct {
            owl2_PropCharacteristic f0;
            types_RoleId f1;
        } ra_property_characteristic;
        slop_list_types_RoleId ra_disjoint_properties;
        slop_list_types_Node ra_same_individual;
        slop_list_types_Node ra_different_individuals;
        owl2_RawEdge ra_negative_assertion;
        owl2_RawDisjointUnion ra_disjoint_union;
        types_InputRef ra_has_key;
        types_InputRef ra_data_axiom;
        types_InputRef ra_builtin_role;
        types_InputRef ra_anonymous_individual;
        types_InputRef ra_reserved_vocabulary;
        types_InputRef ra_swrl_rule;
        types_InputRef ra_unrecognized;
    } data;
};
typedef struct owl2_RawAxiom owl2_RawAxiom;

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawAxiom, slop_list_owl2_RawAxiom)
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

owl2_Disposition owl2_disposition(types_Profile p, owl2_RawAxiom ax);
owl2_Signature owl2_make_signature(slop_arena* arena);
uint8_t owl2_signature_has_class(owl2_Signature sig, rdf_IRI i);
uint8_t owl2_signature_has_object_property(owl2_Signature sig, rdf_IRI i);
uint8_t owl2_signature_has_annotation_property(owl2_Signature sig, rdf_IRI i);
uint8_t owl2_signature_has_data_property(owl2_Signature sig, rdf_IRI i);
int64_t owl2_signature_size(slop_arena* arena, owl2_Signature sig);
uint8_t owl2_is_el_plus_plus(types_Profile p);
owl2_Disposition owl2_when_el_plus_plus(types_Profile p);
uint8_t owl2_is_sriq(types_Profile p);
owl2_Disposition owl2_when_sriq(types_Profile p);
owl2_Disposition owl2_when_el_plus_plus_or_sriq(types_Profile p);
uint8_t owl2_role_in_profile(types_Profile p, types_RoleId r);
uint8_t owl2_roles_in_profile(types_Profile p, slop_list_types_RoleId rs);
uint8_t owl2_concepts_in_profile(types_Profile p, slop_list_owl2_RawConcept cs);
uint8_t owl2_concept_in_profile(types_Profile p, owl2_RawConcept c);
uint8_t owl2_axiom_in_profile(types_Profile p, owl2_RawAxiom ax);
int64_t owl2_concept_tag_rank(owl2_RawConcept c);
int64_t owl2_concept_list_cmp(slop_list_owl2_RawConcept a, slop_list_owl2_RawConcept b);
owl2_RawConcept owl2_concept_at(slop_list_owl2_RawConcept xs, int64_t i);
int64_t owl2_concept_cmp(owl2_RawConcept a, owl2_RawConcept b);
int64_t owl2_card_cmp(owl2_CardKind ka, types_RoleId ra, int64_t na, owl2_CardKind kb, types_RoleId rb, int64_t nb);
int64_t owl2_card_rank(owl2_CardKind k);
int64_t owl2_node_list_cmp(slop_list_types_Node a, slop_list_types_Node b);
slop_string owl2_render_role(slop_arena* arena, types_RoleId r);
slop_string owl2_render_node(types_Node n);
slop_string owl2_render_card_kind(owl2_CardKind k);
slop_string owl2_render_concept_list(slop_arena* arena, slop_list_owl2_RawConcept cs);
slop_string owl2_render_node_list(slop_arena* arena, slop_list_types_Node ns);
slop_string owl2_render_role_list(slop_arena* arena, slop_list_types_RoleId rs);
slop_string owl2_wrap(slop_arena* arena, slop_string head, slop_string body);
slop_string owl2_join2(slop_arena* arena, slop_string a, slop_string b);
slop_string owl2_render_concept(slop_arena* arena, owl2_RawConcept c);
slop_string owl2_render_input_ref(types_InputRef r);
slop_string owl2_render_entity_kind(types_EntityKind k);
slop_string owl2_render_omission(slop_arena* arena, types_Omission o);
slop_string owl2_render_axiom(slop_arena* arena, owl2_RawAxiom ax);
slop_string owl2_render_characteristic(owl2_PropCharacteristic c);
owl2_RawConcept owl2_copy_concept(slop_arena* arena, owl2_RawConcept c);
owl2_RawConcept* owl2_copy_boxed(slop_arena* arena, owl2_RawConcept* p);
slop_list_owl2_RawConcept owl2_copy_concepts(slop_arena* arena, slop_list_owl2_RawConcept cs);
slop_list_types_Node owl2_copy_nodes(slop_arena* arena, slop_list_types_Node ns);
slop_list_types_RoleId owl2_copy_roles(slop_arena* arena, slop_list_types_RoleId rs);
owl2_RawAxiom owl2_copy_raw_axiom(slop_arena* arena, owl2_RawAxiom ax);
owl2_RawAxiom owl2_raw_axiom_at(slop_list_owl2_RawAxiom xs, int64_t i);
slop_list_owl2_RawAxiom owl2_copy_axioms(slop_arena* arena, slop_list_owl2_RawAxiom xs);
owl2_Signature owl2_copy_signature(slop_arena* arena, owl2_Signature sig);
slop_list_owl2_RawConcept owl2_sort_concepts(slop_arena* arena, slop_list_owl2_RawConcept xs);

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCHAIN_DEFINED
#define SLOP_OPTION_OWL2_RAWCHAIN_DEFINED
SLOP_OPTION_DEFINE(owl2_RawChain, slop_option_owl2_RawChain)
#endif

#ifndef SLOP_OPTION_OWL2_RAWEDGE_DEFINED
#define SLOP_OPTION_OWL2_RAWEDGE_DEFINED
SLOP_OPTION_DEFINE(owl2_RawEdge, slop_option_owl2_RawEdge)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCLASSASSERTION_DEFINED
#define SLOP_OPTION_OWL2_RAWCLASSASSERTION_DEFINED
SLOP_OPTION_DEFINE(owl2_RawClassAssertion, slop_option_owl2_RawClassAssertion)
#endif

#ifndef SLOP_OPTION_OWL2_RAWDECLARATION_DEFINED
#define SLOP_OPTION_OWL2_RAWDECLARATION_DEFINED
SLOP_OPTION_DEFINE(owl2_RawDeclaration, slop_option_owl2_RawDeclaration)
#endif

#ifndef SLOP_OPTION_OWL2_RAWDISJOINTUNION_DEFINED
#define SLOP_OPTION_OWL2_RAWDISJOINTUNION_DEFINED
SLOP_OPTION_DEFINE(owl2_RawDisjointUnion, slop_option_owl2_RawDisjointUnion)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_OWL2_SIGNATURE_DEFINED
#define SLOP_OPTION_OWL2_SIGNATURE_DEFINED
SLOP_OPTION_DEFINE(owl2_Signature, slop_option_owl2_Signature)
#endif

#ifndef SLOP_LIST_OWL2_RAWCONCEPT_IMPL_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_IMPL(owl2_RawConcept, slop_list_owl2_RawConcept)
#endif


#endif
