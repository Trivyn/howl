#ifndef SLOP_sroiqfss_H
#define SLOP_sroiqfss_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"
#include "slop_sroiq.h"
#include "slop_canon.h"
#include "slop_sriqnames.h"
#include "slop_strlib.h"

#ifndef SLOP_LIST_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_SROIQ_SCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(sroiq_SConcept, slop_list_sroiq_SConcept)
#endif

#ifndef SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(types_RoleId, slop_list_types_RoleId)
#endif

#ifndef SLOP_LIST_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_SROIQ_SAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(sroiq_SAxiom, slop_list_sroiq_SAxiom)
#endif

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_LIST_TYPES_DNAME_DEFINED
#define SLOP_LIST_TYPES_DNAME_DEFINED
#define SLOP_LIST_TYPES_DNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(types_DName, slop_list_types_DName)
#endif

#ifndef SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(sroiq_SConcept, slop_option_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(sroiq_SAxiom, slop_option_sroiq_SAxiom)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_DNAME_DEFINED
#define SLOP_OPTION_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(types_DName, slop_option_types_DName)
#endif

slop_string sroiqfss_angle(slop_arena* arena, slop_string v);
slop_string sroiqfss_call1(slop_arena* arena, slop_string f, slop_string a);
slop_string sroiqfss_call2(slop_arena* arena, slop_string f, slop_string a, slop_string b);
slop_string sroiqfss_call3(slop_arena* arena, slop_string f, slop_string a, slop_string b, slop_string c);
slop_string sroiqfss_joined(slop_arena* arena, slop_list_string parts);
slop_string sroiqfss_junction(slop_arena* arena, slop_string f, slop_list_string parts, slop_string empty);
slop_string sroiqfss_thing(slop_arena* arena);
slop_string sroiqfss_nothing(slop_arena* arena);
slop_string sroiqfss_role_text(slop_arena* arena, types_RoleId r);
slop_list_string sroiqfss_concepts_text(slop_arena* arena, slop_list_sroiq_SConcept atoms, slop_list_sroiq_SConcept cs);
slop_string sroiqfss_concept_text(slop_arena* arena, slop_list_sroiq_SConcept atoms, sroiq_SConcept c);
slop_list_string sroiqfss_roles_text(slop_arena* arena, slop_list_types_RoleId rs);
slop_string sroiqfss_ria_text(slop_arena* arena, sroiq_SRia x);
slop_string sroiqfss_axiom_text(slop_arena* arena, slop_list_sroiq_SConcept atoms, sroiq_SAxiom a);
slop_list_sroiq_SConcept sroiqfss_atoms_in(slop_arena* arena, sroiq_SConcept c);
slop_list_sroiq_SConcept sroiqfss_atoms_in_all(slop_arena* arena, slop_list_sroiq_SConcept cs);
sroiq_SConcept sroiqfss_atom_at(slop_list_sroiq_SConcept xs, int64_t i);
slop_list_sroiq_SConcept sroiqfss_document_atoms(slop_arena* arena, slop_list_sroiq_SAxiom axs);
int64_t sroiqfss_atom_index(slop_list_sroiq_SConcept atoms, sroiq_SConcept c);
slop_string sroiqfss_atom_iri(slop_arena* arena, slop_list_sroiq_SConcept atoms, sroiq_SConcept c);
slop_list_string sroiqfss_declare(slop_arena* arena, slop_string kind, slop_string v);
slop_list_string sroiqfss_role_decls(slop_arena* arena, types_RoleId r);
slop_list_string sroiqfss_concept_decls(slop_arena* arena, slop_list_sroiq_SConcept atoms, sroiq_SConcept c);
slop_list_string sroiqfss_concepts_decls(slop_arena* arena, slop_list_sroiq_SConcept atoms, slop_list_sroiq_SConcept cs);
slop_list_string sroiqfss_append2(slop_arena* arena, slop_list_string a, slop_list_string b);
slop_list_string sroiqfss_axiom_decls(slop_arena* arena, slop_list_sroiq_SConcept atoms, sroiq_SAxiom a);
slop_list_string sroiqfss_unique_sorted(slop_arena* arena, slop_list_string xs);
slop_list_string sroiqfss_document(slop_arena* arena, slop_list_string decls, slop_list_string axioms);
slop_list_string sroiqfss_class_decls(slop_arena* arena, slop_list_rdf_IRI classes);
slop_list_string sroiqfss_fss_axioms(slop_arena* arena, slop_list_rdf_IRI classes, slop_list_sroiq_SAxiom axs);
slop_string sroiqfss_fresh_iri(slop_arena* arena, int64_t k);
int64_t sroiqfss_bar_index(slop_list_rdf_IRI bars, rdf_IRI p);
slop_string sroiqfss_bar_iri(slop_arena* arena, slop_list_rdf_IRI bars, rdf_IRI p);
slop_string sroiqfss_dname_iri(slop_arena* arena, types_DName n);
slop_string sroiqfss_dname_text(slop_arena* arena, types_DName n);
slop_string sroiqfss_drole_iri(slop_arena* arena, slop_list_rdf_IRI bars, types_DRole r);
slop_string sroiqfss_drole_text(slop_arena* arena, slop_list_rdf_IRI bars, types_DRole r);
slop_list_string sroiqfss_dnames_text(slop_arena* arena, slop_list_types_DName ns);
slop_string sroiqfss_filler_text(slop_arena* arena, slop_option_types_DName b);
slop_string sroiqfss_count_text(slop_arena* arena, slop_string f, int64_t n, slop_string role, slop_string filler);
slop_string sroiqfss_clause_text(slop_arena* arena, slop_list_rdf_IRI bars, types_DlClause c);
slop_list_string sroiqfss_dname_decls(slop_arena* arena, types_DName n);
slop_list_string sroiqfss_filler_decls(slop_arena* arena, slop_option_types_DName b);
slop_list_string sroiqfss_drole_decls(slop_arena* arena, slop_list_rdf_IRI bars, types_DRole r);
slop_list_string sroiqfss_dnames_decls(slop_arena* arena, slop_list_types_DName ns);
slop_list_string sroiqfss_clause_decls(slop_arena* arena, slop_list_rdf_IRI bars, types_DlClause c);
slop_list_string sroiqfss_fss_normal(slop_arena* arena, sriqnames_SriqNormal n);

#ifndef SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(sroiq_SConcept, slop_option_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(sroiq_SAxiom, slop_option_sroiq_SAxiom)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_DNAME_DEFINED
#define SLOP_OPTION_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(types_DName, slop_option_types_DName)
#endif


#endif
