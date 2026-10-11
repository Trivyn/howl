#ifndef SLOP_sriqclauses_H
#define SLOP_sriqclauses_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"
#include "slop_canon.h"
#include "slop_sriqnames.h"

typedef struct sriqclauses_SriqIds sriqclauses_SriqIds;
typedef struct sriqclauses_SriqClauses sriqclauses_SriqClauses;

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
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

#ifndef SLOP_LIST_TYPES_DROLE_DEFINED
#define SLOP_LIST_TYPES_DROLE_DEFINED
#define SLOP_LIST_TYPES_DROLE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_DRole, slop_list_types_DRole)
#endif

#ifndef SLOP_LIST_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_TYPES_CLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Clause, slop_list_types_Clause)
#endif

#ifndef SLOP_LIST_TYPES_LIT_DEFINED
#define SLOP_LIST_TYPES_LIT_DEFINED
#define SLOP_LIST_TYPES_LIT_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Lit, slop_list_types_Lit)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_DNAME_DEFINED
#define SLOP_OPTION_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(types_DName, slop_option_types_DName)
#endif

#ifndef SLOP_OPTION_TYPES_DROLE_DEFINED
#define SLOP_OPTION_TYPES_DROLE_DEFINED
SLOP_OPTION_DEFINE(types_DRole, slop_option_types_DRole)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

struct sriqclauses_SriqIds {
    slop_map* class_ix;
    slop_map* prop_ix;
    slop_map* bar_ix;
    slop_map* const_ix;
    slop_list_types_DName class_of;
    slop_list_types_DRole role_of;
    slop_list_rdf_IRI const_of;
    int64_t nclass;
    int64_t sub0;
    int64_t nfns;
};
typedef struct sriqclauses_SriqIds sriqclauses_SriqIds;

#ifndef SLOP_OPTION_SRIQCLAUSES_SRIQIDS_DEFINED
#define SLOP_OPTION_SRIQCLAUSES_SRIQIDS_DEFINED
SLOP_OPTION_DEFINE(sriqclauses_SriqIds, slop_option_sriqclauses_SriqIds)
#endif

struct sriqclauses_SriqClauses {
    sriqclauses_SriqIds ids;
    slop_list_types_Clause clauses;
};
typedef struct sriqclauses_SriqClauses sriqclauses_SriqClauses;

#ifndef SLOP_OPTION_SRIQCLAUSES_SRIQCLAUSES_DEFINED
#define SLOP_OPTION_SRIQCLAUSES_SRIQCLAUSES_DEFINED
SLOP_OPTION_DEFINE(sriqclauses_SriqClauses, slop_option_sriqclauses_SriqClauses)
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

#ifndef SLOP_RESULT_SRIQCLAUSES_SRIQCLAUSES_STRING_DEFINED
#define SLOP_RESULT_SRIQCLAUSES_SRIQCLAUSES_STRING_DEFINED
typedef struct { bool is_ok; union { sriqclauses_SriqClauses ok; slop_string err; } data; } slop_result_sriqclauses_SriqClauses_string;
#endif

uint32_t sriqclauses_no_id(void);
int64_t sriqclauses_cmp_int(int64_t a, int64_t b);
types_Lit sriqclauses_lit_at(slop_list_types_Lit xs, int64_t i);
types_Clause sriqclauses_clause_at(slop_list_types_Clause xs, int64_t i, types_Clause fallback);
slop_list_types_Lit sriqclauses_lits1(slop_arena* arena, types_Lit a);
slop_list_types_Lit sriqclauses_lits2(slop_arena* arena, types_Lit a, types_Lit b);
slop_list_types_Clause sriqclauses_one(slop_arena* arena, types_Clause c);
uint8_t sriqclauses_ends_with(slop_list_types_Lit xs, types_Lit l);
slop_list_types_Lit sriqclauses_lit_set(slop_arena* arena, slop_list_types_Lit xs);
types_Clause sriqclauses_make_clause(slop_arena* arena, slop_list_types_Lit body, slop_list_types_Lit head);
int64_t sriqclauses_lits_cmp(slop_list_types_Lit a, slop_list_types_Lit b);
int64_t sriqclauses_clause_cmp(types_Clause a, types_Clause b);
uint8_t sriqclauses_clause_eq(types_Clause a, types_Clause b);
uint8_t sriqclauses_ends_with_clause(slop_list_types_Clause xs, types_Clause c);
slop_list_types_Clause sriqclauses_clause_set(slop_arena* arena, slop_list_types_Clause xs);
slop_list_types_DName sriqclauses_filler_names(slop_arena* arena, types_DName sub, slop_option_types_DName filler);
slop_list_types_DName sriqclauses_names_of(slop_arena* arena, slop_list_types_DName ns);
slop_list_types_DName sriqclauses_dl1_names(slop_arena* arena, types_Dl1 d);
slop_list_types_DName sriqclauses_two_names(slop_arena* arena, types_DName a, types_DName b);
slop_list_types_DName sriqclauses_one_name(slop_arena* arena, types_DName a);
slop_list_types_DName sriqclauses_dl_names(slop_arena* arena, types_DlClause c);
slop_list_types_DRole sriqclauses_roles_of(slop_arena* arena, types_DRole a, slop_option_types_DRole b);
slop_list_types_DRole sriqclauses_dl_roles(slop_arena* arena, types_DlClause c);
slop_list_rdf_IRI sriqclauses_dl_consts(slop_arena* arena, types_DlClause c);
slop_list_int sriqclauses_dl_fns(slop_arena* arena, types_DlClause c);
rdf_IRI sriqclauses_iri_at(slop_list_rdf_IRI xs, int64_t i);
slop_list_rdf_IRI sriqclauses_distinct_iris(slop_arena* arena, slop_list_rdf_IRI sorted);
slop_list_rdf_IRI sriqclauses_props_of(slop_arena* arena, sriqnames_SriqNormal n);
uint8_t sriqclauses_is_top_or_bottom(rdf_IRI i);
slop_list_rdf_IRI sriqclauses_classes_of(slop_arena* arena, sriqnames_SriqNormal n);
slop_list_rdf_IRI sriqclauses_without_top_bottom(slop_arena* arena, slop_list_rdf_IRI xs);
slop_list_rdf_IRI sriqclauses_individuals_of(slop_arena* arena, sriqnames_SriqNormal n);
slop_map* sriqclauses_index_from(slop_arena* arena, slop_list_rdf_IRI xs, int64_t base);
slop_list_types_DName sriqclauses_class_names(slop_arena* arena, slop_list_rdf_IRI classes, int64_t nfresh);
slop_list_types_DRole sriqclauses_role_names(slop_arena* arena, slop_list_rdf_IRI props, slop_list_rdf_IRI bars, int64_t nsub);
sriqclauses_SriqIds sriqclauses_build_sriq_ids(slop_arena* arena, sriqnames_SriqNormal n);
uint32_t sriqclauses_lookup(slop_map* m, rdf_IRI i);
uint32_t sriqclauses_class_id(sriqclauses_SriqIds ids, types_DName b);
uint32_t sriqclauses_role_id(sriqclauses_SriqIds ids, types_DRole r);
uint32_t sriqclauses_const_id(sriqclauses_SriqIds ids, rdf_IRI o);
uint8_t sriqclauses_name_covered(sriqclauses_SriqIds ids, types_DName b);
uint8_t sriqclauses_role_covered(sriqclauses_SriqIds ids, types_DRole r);
slop_string sriqclauses_dname_text(slop_arena* arena, types_DName b);
slop_string sriqclauses_drole_text(slop_arena* arena, types_DRole r);
slop_list_string sriqclauses_clause_misses(slop_arena* arena, sriqclauses_SriqIds ids, types_DlClause c);
slop_list_string sriqclauses_uncovered(slop_arena* arena, sriqclauses_SriqIds ids, sriqnames_SriqNormal n);
slop_list_types_Lit sriqclauses_unary_x(slop_arena* arena, sriqclauses_SriqIds ids, slop_list_types_DName ns);
slop_list_types_Clause sriqclauses_expand_dl1(slop_arena* arena, sriqclauses_SriqIds ids, types_Dl1 d);
slop_list_types_Clause sriqclauses_dl2_successor(slop_arena* arena, sriqclauses_SriqIds ids, types_Dl2 d, slop_list_types_Lit b1, int64_t f);
slop_list_types_Clause sriqclauses_dl2_successors(slop_arena* arena, sriqclauses_SriqIds ids, types_Dl2 d);
uint32_t sriqclauses_fn_at(slop_list_int fs, int64_t i);
slop_list_types_Clause sriqclauses_neq_after(slop_arena* arena, slop_list_types_Lit b1, slop_list_int fs, int64_t i);
slop_list_types_Clause sriqclauses_expand_dl2(slop_arena* arena, sriqclauses_SriqIds ids, types_Dl2 d);
slop_list_types_Clause sriqclauses_expand_dl3(slop_arena* arena, sriqclauses_SriqIds ids, types_DRole s, types_DName b1, types_DName b2);
types_Clause sriqclauses_dl4_sub(slop_arena* arena, sriqclauses_SriqIds ids, types_Dl4 d);
slop_list_types_Lit sriqclauses_dl4_body(slop_arena* arena, sriqclauses_SriqIds ids, types_Dl4 d);
slop_list_types_Lit sriqclauses_eq_after(slop_arena* arena, int64_t i, int64_t m);
slop_list_types_Lit sriqclauses_dl4_head(slop_arena* arena, types_Dl4 d);
slop_list_types_Clause sriqclauses_expand_dl4(slop_arena* arena, sriqclauses_SriqIds ids, types_Dl4 d);
slop_list_types_Clause sriqclauses_expand_dl5(slop_arena* arena, sriqclauses_SriqIds ids, types_DName b, types_DRole s);
slop_list_types_Clause sriqclauses_expand_dl6(slop_arena* arena, sriqclauses_SriqIds ids, types_DRole s, types_DName b);
slop_list_types_Clause sriqclauses_expand_dl7(slop_arena* arena, sriqclauses_SriqIds ids, types_DRole s1, types_DRole s2);
slop_list_types_Clause sriqclauses_expand_dl8(slop_arena* arena, sriqclauses_SriqIds ids, types_DRole s1, types_DRole s2);
slop_list_types_Clause sriqclauses_expand_dl9(slop_arena* arena, sriqclauses_SriqIds ids, types_DRole s1, types_DRole s2);
slop_list_types_Clause sriqclauses_expand_dl10(slop_arena* arena, sriqclauses_SriqIds ids, rdf_IRI o, types_DName b);
slop_list_types_Clause sriqclauses_expand_dl11(slop_arena* arena, sriqclauses_SriqIds ids, types_DName b, rdf_IRI o);
slop_list_types_Clause sriqclauses_expand_clause(slop_arena* arena, sriqclauses_SriqIds ids, types_DlClause c);
slop_list_types_Clause sriqclauses_ontology_clauses(slop_arena* arena, sriqclauses_SriqIds ids, sriqnames_SriqNormal n);
slop_result_sriqclauses_SriqClauses_string sriqclauses_sriq_clauses(slop_arena* arena, sriqnames_SriqNormal n);
uint8_t sriqclauses_is_x(types_ATerm t);
uint8_t sriqclauses_is_z(types_ATerm t);
uint8_t sriqclauses_is_fx(types_ATerm t);
uint8_t sriqclauses_dl_aterm(types_ATerm t);
uint8_t sriqclauses_dl_body_atom(types_Lit l);
uint8_t sriqclauses_dl_head_lit(types_Lit l);
uint8_t sriqclauses_dl_clause_shape(types_Clause c);
uint8_t sriqclauses_canonical_aterm(types_ATerm t);
uint8_t sriqclauses_canonical_lit(types_Lit l);
uint8_t sriqclauses_lits_canonical(slop_list_types_Lit ls);
uint8_t sriqclauses_clause_canonical(types_Clause c);
uint8_t sriqclauses_aterm_in_range(sriqclauses_SriqIds ids, types_ATerm t);
uint8_t sriqclauses_lit_in_range(sriqclauses_SriqIds ids, types_Lit l);
uint8_t sriqclauses_clause_in_range(sriqclauses_SriqIds ids, types_Clause c);
uint8_t sriqclauses_tables_round_trip(sriqclauses_SriqIds ids);
uint8_t sriqclauses_class_in_place(sriqclauses_SriqIds ids, int64_t i, types_DName b, rdf_IRI prev);
uint8_t sriqclauses_classes_in_order(sriqclauses_SriqIds ids);
uint8_t sriqclauses_prop_after(types_DRole prev, rdf_IRI p);
uint8_t sriqclauses_bar_after(types_DRole prev, rdf_IRI p);
uint8_t sriqclauses_role_in_place(sriqclauses_SriqIds ids, int64_t i, types_DRole r, types_DRole prev);
uint8_t sriqclauses_roles_in_order(sriqclauses_SriqIds ids);
uint8_t sriqclauses_consts_in_order(sriqclauses_SriqIds ids);
slop_list_string sriqclauses_ids_dense(slop_arena* arena, sriqclauses_SriqClauses sc);
slop_string sriqclauses_class_text(slop_arena* arena, sriqclauses_SriqIds ids, uint32_t b);
slop_string sriqclauses_role_text(slop_arena* arena, sriqclauses_SriqIds ids, uint32_t r);
slop_string sriqclauses_const_text(slop_arena* arena, sriqclauses_SriqIds ids, uint32_t u);
slop_string sriqclauses_fsym_text(slop_arena* arena, uint32_t f);
slop_string sriqclauses_applied(slop_arena* arena, slop_string f, slop_string arg);
slop_string sriqclauses_render_aterm(slop_arena* arena, sriqclauses_SriqIds ids, types_ATerm t);
slop_string sriqclauses_infix(slop_arena* arena, slop_string a, slop_string op, slop_string b);
slop_string sriqclauses_render_lit(slop_arena* arena, sriqclauses_SriqIds ids, types_Lit l);
slop_string sriqclauses_render_lits(slop_arena* arena, sriqclauses_SriqIds ids, slop_list_types_Lit ls, slop_string sep, slop_string empty);
slop_string sriqclauses_render_clause(slop_arena* arena, sriqclauses_SriqIds ids, types_Clause c);
slop_list_string sriqclauses_render_clauses(slop_arena* arena, sriqclauses_SriqClauses sc);

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_TYPES_DNAME_DEFINED
#define SLOP_OPTION_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(types_DName, slop_option_types_DName)
#endif

#ifndef SLOP_OPTION_TYPES_DROLE_DEFINED
#define SLOP_OPTION_TYPES_DROLE_DEFINED
SLOP_OPTION_DEFINE(types_DRole, slop_option_types_DRole)
#endif

#ifndef SLOP_OPTION_SRIQCLAUSES_SRIQIDS_DEFINED
#define SLOP_OPTION_SRIQCLAUSES_SRIQIDS_DEFINED
SLOP_OPTION_DEFINE(sriqclauses_SriqIds, slop_option_sriqclauses_SriqIds)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_SRIQCLAUSES_SRIQCLAUSES_DEFINED
#define SLOP_OPTION_SRIQCLAUSES_SRIQCLAUSES_DEFINED
SLOP_OPTION_DEFINE(sriqclauses_SriqClauses, slop_option_sriqclauses_SriqClauses)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif


#endif
