#ifndef SLOP_canon_H
#define SLOP_canon_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"
#include <string.h>

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_DEFINED
#define SLOP_LIST_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Node, slop_list_types_Node)
#endif

#ifndef SLOP_LIST_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_TYPES_SUBPAIR_IMPL_DEFINED
SLOP_LIST_DEFINE(types_SubPair, slop_list_types_SubPair)
#endif

#ifndef SLOP_LIST_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_TYPES_AXIOMREF_IMPL_DEFINED
SLOP_LIST_DEFINE(types_AxiomRef, slop_list_types_AxiomRef)
#endif

#ifndef SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Omission, slop_list_types_Omission)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(types_SubPair, slop_option_types_SubPair)
#endif

#ifndef SLOP_OPTION_TYPES_AXIOMREF_DEFINED
#define SLOP_OPTION_TYPES_AXIOMREF_DEFINED
SLOP_OPTION_DEFINE(types_AxiomRef, slop_option_types_AxiomRef)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

int64_t canon_string_cmp(slop_string a, slop_string b);
int64_t canon_iri_cmp(rdf_IRI a, rdf_IRI b);
int64_t canon_node_tag_rank(types_Node n);
int64_t canon_node_cmp(types_Node a, types_Node b);
int64_t canon_role_cmp(types_RoleId a, types_RoleId b);
int64_t canon_sub_pair_cmp(types_SubPair a, types_SubPair b);
int64_t canon_entity_kind_rank(types_EntityKind k);
int64_t canon_axiom_ref_cmp(types_AxiomRef a, types_AxiomRef b);
int64_t canon_input_ref_cmp(types_InputRef a, types_InputRef b);
int64_t canon_missing_declaration_cmp(types_MissingDeclaration a, types_MissingDeclaration b);
int64_t canon_omission_cmp(types_Omission a, types_Omission b);
int64_t canon_int_at(slop_list_int xs, int64_t i);
slop_string canon_str_at(slop_list_string xs, int64_t i);
rdf_IRI canon_iri_at(slop_list_rdf_IRI xs, int64_t i);
types_Node canon_node_at(slop_list_types_Node xs, int64_t i);
types_SubPair canon_sub_pair_at(slop_list_types_SubPair xs, int64_t i);
types_AxiomRef canon_axiom_ref_at(slop_list_types_AxiomRef xs, int64_t i);
types_Omission canon_omission_at(slop_list_types_Omission xs, int64_t i);
uint8_t canon_merge_run(slop_list_int src, slop_list_int dst, int64_t lo, int64_t mid, int64_t hi, slop_closure_t cmp);
slop_list_int canon_sort_range(slop_arena* arena, int64_t n, slop_closure_t cmp);
slop_list_string canon_sort_strings(slop_arena* arena, slop_list_string xs);
slop_list_rdf_IRI canon_sort_iris(slop_arena* arena, slop_list_rdf_IRI xs);
slop_list_types_Node canon_sort_nodes(slop_arena* arena, slop_list_types_Node xs);
slop_list_types_SubPair canon_sort_sub_pairs(slop_arena* arena, slop_list_types_SubPair xs);
slop_list_types_AxiomRef canon_sort_axiom_refs(slop_arena* arena, slop_list_types_AxiomRef xs);
slop_list_types_Omission canon_sort_omissions(slop_arena* arena, slop_list_types_Omission xs);

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_NODE_DEFINED
#define SLOP_OPTION_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(types_Node, slop_option_types_Node)
#endif

#ifndef SLOP_OPTION_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(types_SubPair, slop_option_types_SubPair)
#endif

#ifndef SLOP_OPTION_TYPES_AXIOMREF_DEFINED
#define SLOP_OPTION_TYPES_AXIOMREF_DEFINED
SLOP_OPTION_DEFINE(types_AxiomRef, slop_option_types_AxiomRef)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif


#endif
