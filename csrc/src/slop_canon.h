#ifndef SLOP_canon_H
#define SLOP_canon_H

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
#include <string.h>

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Node, slop_list_howl_types_Node)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_HOWL_TYPES_SUBPAIR_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_SubPair, slop_list_howl_types_SubPair)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_HOWL_TYPES_AXIOMREF_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_AxiomRef, slop_list_howl_types_AxiomRef)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Omission, slop_list_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_types_SubPair, slop_option_howl_types_SubPair)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
SLOP_OPTION_DEFINE(howl_types_AxiomRef, slop_option_howl_types_AxiomRef)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

int64_t howl_canon_string_cmp(slop_string a, slop_string b);
int64_t howl_canon_iri_cmp(slop_rdf_rdf_IRI a, slop_rdf_rdf_IRI b);
int64_t howl_canon_node_tag_rank(howl_types_Node n);
int64_t howl_canon_node_cmp(howl_types_Node a, howl_types_Node b);
int64_t howl_canon_role_cmp(howl_types_RoleId a, howl_types_RoleId b);
int64_t howl_canon_sub_pair_cmp(howl_types_SubPair a, howl_types_SubPair b);
int64_t howl_canon_entity_kind_rank(howl_types_EntityKind k);
int64_t howl_canon_axiom_ref_cmp(howl_types_AxiomRef a, howl_types_AxiomRef b);
int64_t howl_canon_input_ref_cmp(howl_types_InputRef a, howl_types_InputRef b);
int64_t howl_canon_missing_declaration_cmp(howl_types_MissingDeclaration a, howl_types_MissingDeclaration b);
int64_t howl_canon_undeclared_property_cmp(howl_types_UndeclaredProperty a, howl_types_UndeclaredProperty b);
int64_t howl_canon_omission_rank(howl_types_Omission o);
int64_t howl_canon_omission_cmp(howl_types_Omission a, howl_types_Omission b);
int64_t howl_canon_int_at(slop_list_int xs, int64_t i);
slop_string howl_canon_str_at(slop_list_string xs, int64_t i);
slop_rdf_rdf_IRI howl_canon_iri_at(slop_list_slop_rdf_rdf_IRI xs, int64_t i);
howl_types_Node howl_canon_node_at(slop_list_howl_types_Node xs, int64_t i);
howl_types_SubPair howl_canon_sub_pair_at(slop_list_howl_types_SubPair xs, int64_t i);
howl_types_AxiomRef howl_canon_axiom_ref_at(slop_list_howl_types_AxiomRef xs, int64_t i);
howl_types_Omission howl_canon_omission_at(slop_list_howl_types_Omission xs, int64_t i);
uint8_t howl_canon_merge_run(slop_list_int src, slop_list_int dst, int64_t lo, int64_t mid, int64_t hi, slop_closure_t cmp);
slop_list_int howl_canon_sort_range(slop_arena* arena, int64_t n, slop_closure_t cmp);
slop_list_string howl_canon_sort_strings(slop_arena* arena, slop_list_string xs);
slop_list_slop_rdf_rdf_IRI howl_canon_sort_iris(slop_arena* arena, slop_list_slop_rdf_rdf_IRI xs);
slop_list_howl_types_Node howl_canon_sort_nodes(slop_arena* arena, slop_list_howl_types_Node xs);
slop_list_howl_types_SubPair howl_canon_sort_sub_pairs(slop_arena* arena, slop_list_howl_types_SubPair xs);
slop_list_howl_types_AxiomRef howl_canon_sort_axiom_refs(slop_arena* arena, slop_list_howl_types_AxiomRef xs);
slop_list_int howl_canon_omission_order(slop_arena* arena, slop_list_howl_types_Omission xs);
slop_list_howl_types_Omission howl_canon_sort_omissions(slop_arena* arena, slop_list_howl_types_Omission xs);

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_types_SubPair, slop_option_howl_types_SubPair)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
SLOP_OPTION_DEFINE(howl_types_AxiomRef, slop_option_howl_types_AxiomRef)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif


#endif
