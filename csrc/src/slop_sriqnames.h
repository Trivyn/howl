#ifndef SLOP_sriqnames_H
#define SLOP_sriqnames_H

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
#include "slop_sroiq.h"
#include "slop_sriqnormal.h"
#include "slop_sriqelim.h"

typedef struct howl_sriqnames_SriqNormal howl_sriqnames_SriqNormal;

#ifndef SLOP_LIST_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_OPTION_HOWL_TYPES_DNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_option_howl_types_DName, slop_list_option_howl_types_DName)
#endif

#ifndef SLOP_OPTION_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(slop_option_howl_types_DName, slop_option_option_howl_types_DName)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_DLCLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_DlClause, slop_list_howl_types_DlClause)
#endif

#ifndef SLOP_LIST_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sroiq_SConcept, slop_list_howl_sroiq_SConcept)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_DROLE_DEFINED
#define SLOP_LIST_HOWL_TYPES_DROLE_DEFINED
#define SLOP_LIST_HOWL_TYPES_DROLE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_DRole, slop_list_howl_types_DRole)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawAxiom, slop_list_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_DNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_DName, slop_list_howl_types_DName)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DlClause, slop_option_howl_types_DlClause)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SConcept, slop_option_howl_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DROLE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DROLE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DRole, slop_option_howl_types_DRole)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_DName, slop_option_howl_types_DName)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

struct howl_sriqnames_SriqNormal {
    slop_list_howl_types_DlClause clauses;
    slop_list_howl_sroiq_SConcept concepts;
    slop_list_howl_types_DRole sroles;
    slop_list_option_howl_types_DName sfills;
    slop_list_slop_rdf_rdf_IRI bars;
    int64_t fns;
    slop_list_slop_rdf_rdf_IRI classes;
    slop_list_slop_rdf_rdf_IRI individuals;
    slop_list_howl_owl2_RawAxiom omitted;
};
typedef struct howl_sriqnames_SriqNormal howl_sriqnames_SriqNormal;

#ifndef SLOP_OPTION_HOWL_SRIQNAMES_SRIQNORMAL_DEFINED
#define SLOP_OPTION_HOWL_SRIQNAMES_SRIQNORMAL_DEFINED
SLOP_OPTION_DEFINE(howl_sriqnames_SriqNormal, slop_option_howl_sriqnames_SriqNormal)
#endif

#ifndef SLOP_RESULT_HOWL_SRIQNAMES_SRIQNORMAL_STRING_DEFINED
#define SLOP_RESULT_HOWL_SRIQNAMES_SRIQNORMAL_STRING_DEFINED
typedef struct { bool is_ok; union { howl_sriqnames_SriqNormal ok; slop_string err; } data; } slop_result_howl_sriqnames_SriqNormal_string;
#endif

int64_t howl_sriqnames_int_at(slop_list_int xs, int64_t i);
slop_list_int howl_sriqnames_ints_new(slop_arena* arena, int64_t n, int64_t v);
int64_t howl_sriqnames_cmp_int(int64_t a, int64_t b);
howl_sroiq_SConcept howl_sriqnames_sc_at_n(slop_list_howl_sroiq_SConcept xs, int64_t i);
int64_t howl_sriqnames_dname_cmp(howl_types_DName a, howl_types_DName b);
int64_t howl_sriqnames_filler_cmp(slop_option_howl_types_DName a, slop_option_howl_types_DName b);
int64_t howl_sriqnames_drole_rank(howl_types_DRole r);
int64_t howl_sriqnames_drole_cmp(howl_types_DRole a, howl_types_DRole b);
int64_t howl_sriqnames_dnames_cmp(slop_list_howl_types_DName a, slop_list_howl_types_DName b);
int64_t howl_sriqnames_dl_rank(howl_types_DlClause c);
int64_t howl_sriqnames_then_cmp(int64_t first, int64_t second);
int64_t howl_sriqnames_dl1_cmp(howl_types_Dl1 x, howl_types_Dl1 y);
int64_t howl_sriqnames_dl2_cmp(howl_types_Dl2 x, howl_types_Dl2 y);
int64_t howl_sriqnames_dl4_cmp(howl_types_Dl4 x, howl_types_Dl4 y);
int64_t howl_sriqnames_roles_cmp(howl_types_DRole a1, howl_types_DRole b1, howl_types_DRole a2, howl_types_DRole b2);
int64_t howl_sriqnames_dl_cmp(howl_types_DlClause a, howl_types_DlClause b);
howl_types_DName howl_sriqnames_rename_name(slop_list_int fresh, howl_types_DName n);
slop_option_howl_types_DName howl_sriqnames_rename_filler(slop_list_int fresh, slop_option_howl_types_DName b);
howl_types_DRole howl_sriqnames_rename_role(slop_list_int subs, howl_types_DRole r);
slop_list_howl_types_DName howl_sriqnames_sort_dnames(slop_arena* arena, slop_list_howl_types_DName xs);
howl_types_DName howl_sriqnames_dname_at(slop_list_howl_types_DName xs, int64_t i);
slop_list_howl_types_DName howl_sriqnames_rename_names(slop_arena* arena, slop_list_int fresh, slop_list_howl_types_DName ns);
howl_types_DlClause howl_sriqnames_rename_clause(slop_arena* arena, slop_list_int fresh, slop_list_int subs, howl_types_DlClause c);
howl_types_DlClause howl_sriqnames_clause_at(slop_list_howl_types_DlClause xs, int64_t i);
howl_types_DlClause howl_sriqnames_renumber_fns(slop_arena* arena, howl_types_DlClause c, int64_t next);
int64_t howl_sriqnames_fn_count(howl_types_DlClause c);
slop_list_int howl_sriqnames_rank_of(slop_arena* arena, slop_list_int order);
slop_list_int howl_sriqnames_concept_order(slop_arena* arena, slop_list_howl_sroiq_SConcept cs);
slop_list_int howl_sriqnames_srole_order(slop_arena* arena, slop_list_howl_types_DRole roles, slop_list_option_howl_types_DName fills);
slop_list_howl_sroiq_SConcept howl_sriqnames_pick_concepts(slop_arena* arena, slop_list_howl_sroiq_SConcept cs, slop_list_int order);
slop_list_howl_types_DRole howl_sriqnames_pick_roles(slop_arena* arena, slop_list_howl_types_DRole rs, slop_list_int order);
slop_list_option_howl_types_DName howl_sriqnames_pick_fills(slop_arena* arena, slop_list_option_howl_types_DName bs, slop_list_int order);
slop_list_option_howl_types_DName howl_sriqnames_rename_fills(slop_arena* arena, slop_list_int fresh, slop_list_option_howl_types_DName bs);
slop_list_howl_types_DlClause howl_sriqnames_rename_clauses(slop_arena* arena, slop_list_int fresh, slop_list_int subs, slop_list_howl_types_DlClause cs);
slop_list_howl_types_DlClause howl_sriqnames_canonical_clauses(slop_arena* arena, slop_list_howl_types_DlClause cs);
int64_t howl_sriqnames_fn_total(slop_list_howl_types_DlClause cs);
slop_list_slop_rdf_rdf_IRI howl_sriqnames_input_classes(slop_arena* arena, howl_owl2_Signature sig);
slop_list_slop_rdf_rdf_IRI howl_sriqnames_input_individuals(slop_arena* arena, howl_owl2_Signature sig);
howl_sriqnames_SriqNormal howl_sriqnames_sriq_names(slop_arena* arena, howl_sriqnormal_S2 s2, howl_owl2_Signature sig, slop_list_howl_owl2_RawAxiom omitted);
howl_types_DRole howl_sriqnames_role_at(slop_list_howl_types_DRole xs, int64_t i);
slop_option_howl_types_DName howl_sriqnames_fill_at(slop_list_option_howl_types_DName xs, int64_t i);
slop_list_howl_owl2_RawAxiom howl_sriqnames_guard_witnesses(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted, howl_sriqelim_S1 s1);
slop_result_howl_sriqnames_SriqNormal_string howl_sriqnames_normalize_after_s1(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted, howl_sriqelim_S1 s1, howl_owl2_Signature sig);
slop_result_howl_sriqnames_SriqNormal_string howl_sriqnames_normalize_after_s0(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted, howl_sriqnormal_S0 s0, howl_owl2_Signature sig, int64_t bound);
slop_result_howl_sriqnames_SriqNormal_string howl_sriqnames_sriq_normalize_bounded(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted, howl_owl2_Signature sig, int64_t bound);
slop_result_howl_sriqnames_SriqNormal_string howl_sriqnames_sriq_normalize(slop_arena* arena, slop_list_howl_owl2_RawAxiom accepted, howl_owl2_Signature sig);
slop_string howl_sriqnames_rn(slop_arena* arena, howl_types_DName n);
slop_string howl_sriqnames_rr(slop_arena* arena, howl_types_DRole r);
slop_string howl_sriqnames_rf(slop_arena* arena, slop_option_howl_types_DName b);
slop_string howl_sriqnames_rns(slop_arena* arena, slop_list_howl_types_DName ns);
slop_string howl_sriqnames_rints(slop_arena* arena, slop_list_int xs);
slop_string howl_sriqnames_j(slop_arena* arena, slop_list_string parts);
slop_string howl_sriqnames_render_dl_ids(slop_arena* arena, howl_types_DlClause c);
slop_string howl_sriqnames_table_line(slop_arena* arena, slop_string prefix, int64_t k, slop_string text);
slop_list_string howl_sriqnames_prefixed(slop_arena* arena, slop_string prefix, slop_list_slop_rdf_rdf_IRI is);
slop_list_string howl_sriqnames_render_sriq_normal(slop_arena* arena, howl_sriqnames_SriqNormal n);
uint8_t howl_sriqnames_name_in_range(howl_types_DName n, int64_t nc);
uint8_t howl_sriqnames_names_in_range(slop_list_howl_types_DName ns, int64_t nc);
uint8_t howl_sriqnames_filler_in_range(slop_option_howl_types_DName b, int64_t nc);
uint8_t howl_sriqnames_role_in_range(howl_types_DRole r, int64_t ns);
uint8_t howl_sriqnames_clause_in_range(howl_types_DlClause c, int64_t nc, int64_t ns);
slop_list_string howl_sriqnames_concepts_ordered(slop_arena* arena, slop_list_howl_sroiq_SConcept cs);
slop_list_string howl_sriqnames_sroles_ordered(slop_arena* arena, slop_list_howl_types_DRole rs, slop_list_option_howl_types_DName bs);
slop_list_string howl_sriqnames_clauses_ordered(slop_arena* arena, slop_list_howl_types_DlClause cs);
slop_list_string howl_sriqnames_ids_in_range(slop_arena* arena, howl_sriqnames_SriqNormal n);
uint8_t howl_sriqnames_witness_count_ok(howl_types_DlClause c);
slop_list_int howl_sriqnames_clause_fns(slop_arena* arena, howl_types_DlClause c);
slop_list_string howl_sriqnames_fns_dense(slop_arena* arena, howl_sriqnames_SriqNormal n);
slop_list_string howl_sriqnames_fresh_not_signature(slop_arena* arena, howl_sriqnames_SriqNormal n);
slop_list_string howl_sriqnames_sriq_invariants(slop_arena* arena, howl_sriqnames_SriqNormal n);

#ifndef SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DlClause, slop_option_howl_types_DlClause)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SConcept, slop_option_howl_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DROLE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DROLE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DRole, slop_option_howl_types_DRole)
#endif

#ifndef SLOP_OPTION_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(slop_option_howl_types_DName, slop_option_option_howl_types_DName)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_DName, slop_option_howl_types_DName)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQNAMES_SRIQNORMAL_DEFINED
#define SLOP_OPTION_HOWL_SRIQNAMES_SRIQNORMAL_DEFINED
SLOP_OPTION_DEFINE(howl_sriqnames_SriqNormal, slop_option_howl_sriqnames_SriqNormal)
#endif


#endif
