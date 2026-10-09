#ifndef SLOP_sriqnames_H
#define SLOP_sriqnames_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"
#include "slop_owl2.h"
#include "slop_canon.h"
#include "slop_sroiq.h"
#include "slop_sriqnormal.h"

typedef struct sriqnames_SriqNormal sriqnames_SriqNormal;

#ifndef SLOP_LIST_OPTION_TYPES_DNAME_DEFINED
#define SLOP_LIST_OPTION_TYPES_DNAME_DEFINED
#define SLOP_LIST_OPTION_TYPES_DNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_option_types_DName, slop_list_option_types_DName)
#endif

#ifndef SLOP_OPTION_OPTION_TYPES_DNAME_DEFINED
#define SLOP_OPTION_OPTION_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(slop_option_types_DName, slop_option_option_types_DName)
#endif

#ifndef SLOP_LIST_TYPES_DLCLAUSE_DEFINED
#define SLOP_LIST_TYPES_DLCLAUSE_DEFINED
#define SLOP_LIST_TYPES_DLCLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_DlClause, slop_list_types_DlClause)
#endif

#ifndef SLOP_LIST_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_SROIQ_SCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(sroiq_SConcept, slop_list_sroiq_SConcept)
#endif

#ifndef SLOP_LIST_TYPES_DROLE_DEFINED
#define SLOP_LIST_TYPES_DROLE_DEFINED
#define SLOP_LIST_TYPES_DROLE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_DRole, slop_list_types_DRole)
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

#ifndef SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawAxiom, slop_list_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_DLCLAUSE_DEFINED
#define SLOP_OPTION_TYPES_DLCLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_DlClause, slop_option_types_DlClause)
#endif

#ifndef SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(sroiq_SConcept, slop_option_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_TYPES_DROLE_DEFINED
#define SLOP_OPTION_TYPES_DROLE_DEFINED
SLOP_OPTION_DEFINE(types_DRole, slop_option_types_DRole)
#endif

#ifndef SLOP_OPTION_TYPES_DNAME_DEFINED
#define SLOP_OPTION_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(types_DName, slop_option_types_DName)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif

struct sriqnames_SriqNormal {
    slop_list_types_DlClause clauses;
    slop_list_sroiq_SConcept concepts;
    slop_list_types_DRole sroles;
    slop_list_option_types_DName sfills;
    slop_list_rdf_IRI bars;
    int64_t fns;
    slop_list_rdf_IRI classes;
    slop_list_rdf_IRI individuals;
};
typedef struct sriqnames_SriqNormal sriqnames_SriqNormal;

#ifndef SLOP_OPTION_SRIQNAMES_SRIQNORMAL_DEFINED
#define SLOP_OPTION_SRIQNAMES_SRIQNORMAL_DEFINED
SLOP_OPTION_DEFINE(sriqnames_SriqNormal, slop_option_sriqnames_SriqNormal)
#endif

#ifndef SLOP_RESULT_SRIQNAMES_SRIQNORMAL_STRING_DEFINED
#define SLOP_RESULT_SRIQNAMES_SRIQNORMAL_STRING_DEFINED
typedef struct { bool is_ok; union { sriqnames_SriqNormal ok; slop_string err; } data; } slop_result_sriqnames_SriqNormal_string;
#endif

int64_t sriqnames_int_at(slop_list_int xs, int64_t i);
slop_list_int sriqnames_ints_new(slop_arena* arena, int64_t n, int64_t v);
int64_t sriqnames_cmp_int(int64_t a, int64_t b);
sroiq_SConcept sriqnames_sc_at_n(slop_list_sroiq_SConcept xs, int64_t i);
int64_t sriqnames_dname_cmp(types_DName a, types_DName b);
int64_t sriqnames_filler_cmp(slop_option_types_DName a, slop_option_types_DName b);
int64_t sriqnames_drole_rank(types_DRole r);
int64_t sriqnames_drole_cmp(types_DRole a, types_DRole b);
int64_t sriqnames_dnames_cmp(slop_list_types_DName a, slop_list_types_DName b);
int64_t sriqnames_dl_rank(types_DlClause c);
int64_t sriqnames_then_cmp(int64_t first, int64_t second);
int64_t sriqnames_dl1_cmp(types_Dl1 x, types_Dl1 y);
int64_t sriqnames_dl2_cmp(types_Dl2 x, types_Dl2 y);
int64_t sriqnames_dl4_cmp(types_Dl4 x, types_Dl4 y);
int64_t sriqnames_roles_cmp(types_DRole a1, types_DRole b1, types_DRole a2, types_DRole b2);
int64_t sriqnames_dl_cmp(types_DlClause a, types_DlClause b);
types_DName sriqnames_rename_name(slop_list_int fresh, types_DName n);
slop_option_types_DName sriqnames_rename_filler(slop_list_int fresh, slop_option_types_DName b);
types_DRole sriqnames_rename_role(slop_list_int subs, types_DRole r);
slop_list_types_DName sriqnames_sort_dnames(slop_arena* arena, slop_list_types_DName xs);
types_DName sriqnames_dname_at(slop_list_types_DName xs, int64_t i);
slop_list_types_DName sriqnames_rename_names(slop_arena* arena, slop_list_int fresh, slop_list_types_DName ns);
types_DlClause sriqnames_rename_clause(slop_arena* arena, slop_list_int fresh, slop_list_int subs, types_DlClause c);
types_DlClause sriqnames_clause_at(slop_list_types_DlClause xs, int64_t i);
types_DlClause sriqnames_renumber_fns(slop_arena* arena, types_DlClause c, int64_t next);
int64_t sriqnames_fn_count(types_DlClause c);
slop_list_int sriqnames_rank_of(slop_arena* arena, slop_list_int order);
slop_list_int sriqnames_concept_order(slop_arena* arena, slop_list_sroiq_SConcept cs);
slop_list_int sriqnames_srole_order(slop_arena* arena, slop_list_types_DRole roles, slop_list_option_types_DName fills);
slop_list_sroiq_SConcept sriqnames_pick_concepts(slop_arena* arena, slop_list_sroiq_SConcept cs, slop_list_int order);
slop_list_types_DRole sriqnames_pick_roles(slop_arena* arena, slop_list_types_DRole rs, slop_list_int order);
slop_list_option_types_DName sriqnames_pick_fills(slop_arena* arena, slop_list_option_types_DName bs, slop_list_int order);
slop_list_option_types_DName sriqnames_rename_fills(slop_arena* arena, slop_list_int fresh, slop_list_option_types_DName bs);
slop_list_types_DlClause sriqnames_rename_clauses(slop_arena* arena, slop_list_int fresh, slop_list_int subs, slop_list_types_DlClause cs);
slop_list_types_DlClause sriqnames_canonical_clauses(slop_arena* arena, slop_list_types_DlClause cs);
int64_t sriqnames_fn_total(slop_list_types_DlClause cs);
slop_list_rdf_IRI sriqnames_input_classes(slop_arena* arena, owl2_Signature sig);
slop_list_rdf_IRI sriqnames_input_individuals(slop_arena* arena, owl2_Signature sig);
sriqnames_SriqNormal sriqnames_sriq_names(slop_arena* arena, sriqnormal_S2 s2, owl2_Signature sig);
types_DRole sriqnames_role_at(slop_list_types_DRole xs, int64_t i);
slop_option_types_DName sriqnames_fill_at(slop_list_option_types_DName xs, int64_t i);
slop_result_sriqnames_SriqNormal_string sriqnames_sriq_normalize(slop_arena* arena, slop_list_owl2_RawAxiom accepted, owl2_Signature sig);
slop_string sriqnames_rn(slop_arena* arena, types_DName n);
slop_string sriqnames_rr(slop_arena* arena, types_DRole r);
slop_string sriqnames_rf(slop_arena* arena, slop_option_types_DName b);
slop_string sriqnames_rns(slop_arena* arena, slop_list_types_DName ns);
slop_string sriqnames_rints(slop_arena* arena, slop_list_int xs);
slop_string sriqnames_j(slop_arena* arena, slop_list_string parts);
slop_string sriqnames_render_dl_ids(slop_arena* arena, types_DlClause c);
slop_string sriqnames_table_line(slop_arena* arena, slop_string prefix, int64_t k, slop_string text);
slop_list_string sriqnames_prefixed(slop_arena* arena, slop_string prefix, slop_list_rdf_IRI is);
slop_list_string sriqnames_render_sriq_normal(slop_arena* arena, sriqnames_SriqNormal n);
uint8_t sriqnames_name_in_range(types_DName n, int64_t nc);
uint8_t sriqnames_names_in_range(slop_list_types_DName ns, int64_t nc);
uint8_t sriqnames_filler_in_range(slop_option_types_DName b, int64_t nc);
uint8_t sriqnames_role_in_range(types_DRole r, int64_t ns);
uint8_t sriqnames_clause_in_range(types_DlClause c, int64_t nc, int64_t ns);
slop_list_string sriqnames_concepts_ordered(slop_arena* arena, slop_list_sroiq_SConcept cs);
slop_list_string sriqnames_sroles_ordered(slop_arena* arena, slop_list_types_DRole rs, slop_list_option_types_DName bs);
slop_list_string sriqnames_clauses_ordered(slop_arena* arena, slop_list_types_DlClause cs);
slop_list_string sriqnames_ids_in_range(slop_arena* arena, sriqnames_SriqNormal n);
uint8_t sriqnames_witness_count_ok(types_DlClause c);
slop_list_int sriqnames_clause_fns(slop_arena* arena, types_DlClause c);
slop_list_string sriqnames_fns_dense(slop_arena* arena, sriqnames_SriqNormal n);
slop_list_string sriqnames_fresh_not_signature(slop_arena* arena, sriqnames_SriqNormal n);
slop_list_string sriqnames_sriq_invariants(slop_arena* arena, sriqnames_SriqNormal n);

#ifndef SLOP_OPTION_TYPES_DLCLAUSE_DEFINED
#define SLOP_OPTION_TYPES_DLCLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_DlClause, slop_option_types_DlClause)
#endif

#ifndef SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(sroiq_SConcept, slop_option_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_TYPES_DROLE_DEFINED
#define SLOP_OPTION_TYPES_DROLE_DEFINED
SLOP_OPTION_DEFINE(types_DRole, slop_option_types_DRole)
#endif

#ifndef SLOP_OPTION_OPTION_TYPES_DNAME_DEFINED
#define SLOP_OPTION_OPTION_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(slop_option_types_DName, slop_option_option_types_DName)
#endif

#ifndef SLOP_OPTION_TYPES_DNAME_DEFINED
#define SLOP_OPTION_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(types_DName, slop_option_types_DName)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_SRIQNAMES_SRIQNORMAL_DEFINED
#define SLOP_OPTION_SRIQNAMES_SRIQNORMAL_DEFINED
SLOP_OPTION_DEFINE(sriqnames_SriqNormal, slop_option_sriqnames_SriqNormal)
#endif

#ifndef SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(owl2_RawAxiom, slop_option_owl2_RawAxiom)
#endif


#endif
