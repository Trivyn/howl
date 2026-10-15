#ifndef SLOP_sroiqfss_H
#define SLOP_sroiqfss_H

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
#include "slop_sroiq.h"
#include "slop_canon.h"
#include "slop_sriqnames.h"
#include "slop_strlib.h"

#ifndef SLOP_LIST_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sroiq_SConcept, slop_list_howl_sroiq_SConcept)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_RoleId, slop_list_howl_types_RoleId)
#endif

#ifndef SLOP_LIST_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sroiq_SAxiom, slop_list_howl_sroiq_SAxiom)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_DNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_DName, slop_list_howl_types_DName)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SConcept, slop_option_howl_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SAxiom, slop_option_howl_sroiq_SAxiom)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_DName, slop_option_howl_types_DName)
#endif

slop_string howl_sroiqfss_angle(slop_arena* arena, slop_string v);
slop_string howl_sroiqfss_call1(slop_arena* arena, slop_string f, slop_string a);
slop_string howl_sroiqfss_call2(slop_arena* arena, slop_string f, slop_string a, slop_string b);
slop_string howl_sroiqfss_call3(slop_arena* arena, slop_string f, slop_string a, slop_string b, slop_string c);
slop_string howl_sroiqfss_joined(slop_arena* arena, slop_list_string parts);
slop_string howl_sroiqfss_junction(slop_arena* arena, slop_string f, slop_list_string parts, slop_string empty);
slop_string howl_sroiqfss_thing(slop_arena* arena);
slop_string howl_sroiqfss_nothing(slop_arena* arena);
slop_string howl_sroiqfss_role_text(slop_arena* arena, howl_types_RoleId r);
slop_list_string howl_sroiqfss_concepts_text(slop_arena* arena, slop_list_howl_sroiq_SConcept atoms, slop_list_howl_sroiq_SConcept cs);
slop_string howl_sroiqfss_concept_text(slop_arena* arena, slop_list_howl_sroiq_SConcept atoms, howl_sroiq_SConcept c);
slop_list_string howl_sroiqfss_roles_text(slop_arena* arena, slop_list_howl_types_RoleId rs);
slop_string howl_sroiqfss_ria_text(slop_arena* arena, howl_sroiq_SRia x);
slop_string howl_sroiqfss_axiom_text(slop_arena* arena, slop_list_howl_sroiq_SConcept atoms, howl_sroiq_SAxiom a);
slop_list_howl_sroiq_SConcept howl_sroiqfss_atoms_in(slop_arena* arena, howl_sroiq_SConcept c);
slop_list_howl_sroiq_SConcept howl_sroiqfss_atoms_in_all(slop_arena* arena, slop_list_howl_sroiq_SConcept cs);
howl_sroiq_SConcept howl_sroiqfss_atom_at(slop_list_howl_sroiq_SConcept xs, int64_t i);
slop_list_howl_sroiq_SConcept howl_sroiqfss_document_atoms(slop_arena* arena, slop_list_howl_sroiq_SAxiom axs);
int64_t howl_sroiqfss_atom_index(slop_list_howl_sroiq_SConcept atoms, howl_sroiq_SConcept c);
slop_string howl_sroiqfss_atom_iri(slop_arena* arena, slop_list_howl_sroiq_SConcept atoms, howl_sroiq_SConcept c);
slop_list_string howl_sroiqfss_declare(slop_arena* arena, slop_string kind, slop_string v);
slop_list_string howl_sroiqfss_role_decls(slop_arena* arena, howl_types_RoleId r);
slop_list_string howl_sroiqfss_concept_decls(slop_arena* arena, slop_list_howl_sroiq_SConcept atoms, howl_sroiq_SConcept c);
slop_list_string howl_sroiqfss_concepts_decls(slop_arena* arena, slop_list_howl_sroiq_SConcept atoms, slop_list_howl_sroiq_SConcept cs);
slop_list_string howl_sroiqfss_append2(slop_arena* arena, slop_list_string a, slop_list_string b);
slop_list_string howl_sroiqfss_axiom_decls(slop_arena* arena, slop_list_howl_sroiq_SConcept atoms, howl_sroiq_SAxiom a);
slop_list_string howl_sroiqfss_unique_sorted(slop_arena* arena, slop_list_string xs);
slop_list_string howl_sroiqfss_document(slop_arena* arena, slop_list_string decls, slop_list_string axioms);
slop_list_string howl_sroiqfss_class_decls(slop_arena* arena, slop_list_slop_rdf_rdf_IRI classes);
slop_list_string howl_sroiqfss_fss_axioms(slop_arena* arena, slop_list_slop_rdf_rdf_IRI classes, slop_list_howl_sroiq_SAxiom axs);
slop_string howl_sroiqfss_fresh_iri(slop_arena* arena, int64_t k);
int64_t howl_sroiqfss_bar_index(slop_list_slop_rdf_rdf_IRI bars, slop_rdf_rdf_IRI p);
slop_string howl_sroiqfss_bar_iri(slop_arena* arena, slop_list_slop_rdf_rdf_IRI bars, slop_rdf_rdf_IRI p);
slop_string howl_sroiqfss_dname_iri(slop_arena* arena, howl_types_DName n);
slop_string howl_sroiqfss_dname_text(slop_arena* arena, howl_types_DName n);
slop_string howl_sroiqfss_drole_iri(slop_arena* arena, slop_list_slop_rdf_rdf_IRI bars, howl_types_DRole r);
slop_string howl_sroiqfss_drole_text(slop_arena* arena, slop_list_slop_rdf_rdf_IRI bars, howl_types_DRole r);
slop_list_string howl_sroiqfss_dnames_text(slop_arena* arena, slop_list_howl_types_DName ns);
slop_string howl_sroiqfss_filler_text(slop_arena* arena, slop_option_howl_types_DName b);
slop_string howl_sroiqfss_count_text(slop_arena* arena, slop_string f, int64_t n, slop_string role, slop_string filler);
slop_string howl_sroiqfss_clause_text(slop_arena* arena, slop_list_slop_rdf_rdf_IRI bars, howl_types_DlClause c);
slop_list_string howl_sroiqfss_dname_decls(slop_arena* arena, howl_types_DName n);
slop_list_string howl_sroiqfss_filler_decls(slop_arena* arena, slop_option_howl_types_DName b);
slop_list_string howl_sroiqfss_drole_decls(slop_arena* arena, slop_list_slop_rdf_rdf_IRI bars, howl_types_DRole r);
slop_list_string howl_sroiqfss_dnames_decls(slop_arena* arena, slop_list_howl_types_DName ns);
slop_list_string howl_sroiqfss_clause_decls(slop_arena* arena, slop_list_slop_rdf_rdf_IRI bars, howl_types_DlClause c);
slop_list_string howl_sroiqfss_fss_normal(slop_arena* arena, howl_sriqnames_SriqNormal n);

#ifndef SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SConcept, slop_option_howl_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SAxiom, slop_option_howl_sroiq_SAxiom)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_DName, slop_option_howl_types_DName)
#endif


#endif
