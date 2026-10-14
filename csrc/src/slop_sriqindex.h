#ifndef SLOP_sriqindex_H
#define SLOP_sriqindex_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_sriqclauses.h"
#include "slop_sriqctx.h"
#include "slop_sriqorder.h"
#include "slop_sriq.h"
#include "slop_sriqsubsume.h"
#include "slop_canon.h"

typedef struct sriqindex_Entry sriqindex_Entry;
typedef struct sriqindex_SubIndex sriqindex_SubIndex;
typedef struct sriqindex_FPart sriqindex_FPart;
typedef struct sriqindex_KIdx sriqindex_KIdx;
typedef struct sriqindex_KPair sriqindex_KPair;

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

#ifndef SLOP_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(sriq_Premise, slop_list_sriq_Premise)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

#ifndef SLOP_OPTION_TYPES_ATERM_DEFINED
#define SLOP_OPTION_TYPES_ATERM_DEFINED
SLOP_OPTION_DEFINE(types_ATerm, slop_option_types_ATerm)
#endif

#ifndef SLOP_OPTION_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(sriq_Premise, slop_option_sriq_Premise)
#endif

struct sriqindex_Entry {
    int64_t side;
    types_Lit lit;
    int64_t i;
};
typedef struct sriqindex_Entry sriqindex_Entry;

#ifndef SLOP_OPTION_SRIQINDEX_ENTRY_DEFINED
#define SLOP_OPTION_SRIQINDEX_ENTRY_DEFINED
SLOP_OPTION_DEFINE(sriqindex_Entry, slop_option_sriqindex_Entry)
#endif

#ifndef SLOP_LIST_SRIQINDEX_ENTRY_DEFINED
#define SLOP_LIST_SRIQINDEX_ENTRY_DEFINED
#define SLOP_LIST_SRIQINDEX_ENTRY_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqindex_Entry, slop_list_sriqindex_Entry)
#endif

struct sriqindex_SubIndex {
    slop_list_types_Clause xs;
    slop_list_int sigs;
    slop_list_sriqindex_Entry entries;
    int64_t empty;
};
typedef struct sriqindex_SubIndex sriqindex_SubIndex;

#ifndef SLOP_OPTION_SRIQINDEX_SUBINDEX_DEFINED
#define SLOP_OPTION_SRIQINDEX_SUBINDEX_DEFINED
SLOP_OPTION_DEFINE(sriqindex_SubIndex, slop_option_sriqindex_SubIndex)
#endif

struct sriqindex_FPart {
    types_ATerm t;
    types_Lit lit;
    uint8_t single;
};
typedef struct sriqindex_FPart sriqindex_FPart;

#ifndef SLOP_OPTION_SRIQINDEX_FPART_DEFINED
#define SLOP_OPTION_SRIQINDEX_FPART_DEFINED
SLOP_OPTION_DEFINE(sriqindex_FPart, slop_option_sriqindex_FPart)
#endif

#ifndef SLOP_LIST_SRIQINDEX_FPART_DEFINED
#define SLOP_LIST_SRIQINDEX_FPART_DEFINED
#define SLOP_LIST_SRIQINDEX_FPART_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqindex_FPart, slop_list_sriqindex_FPart)
#endif

struct sriqindex_KIdx {
    slop_list_types_Lit ground;
    slop_list_sriqindex_FPart fparts;
};
typedef struct sriqindex_KIdx sriqindex_KIdx;

#ifndef SLOP_OPTION_SRIQINDEX_KIDX_DEFINED
#define SLOP_OPTION_SRIQINDEX_KIDX_DEFINED
SLOP_OPTION_DEFINE(sriqindex_KIdx, slop_option_sriqindex_KIdx)
#endif

struct sriqindex_KPair {
    slop_list_types_Lit k1;
    slop_list_types_Lit k2;
};
typedef struct sriqindex_KPair sriqindex_KPair;

#ifndef SLOP_OPTION_SRIQINDEX_KPAIR_DEFINED
#define SLOP_OPTION_SRIQINDEX_KPAIR_DEFINED
SLOP_OPTION_DEFINE(sriqindex_KPair, slop_option_sriqindex_KPair)
#endif

int64_t sriqindex_entry_cmp(sriqindex_Entry a, sriqindex_Entry b);
int64_t sriqindex_key_cmp(sriqindex_Entry e, int64_t side, types_Lit l);
sriqindex_Entry sriqindex_entry_at(slop_list_sriqindex_Entry es, int64_t k, sriqindex_Entry fallback);
slop_option_sriqindex_Entry sriqindex_key_of(types_Clause c, int64_t i);
sriqindex_SubIndex sriqindex_sub_index(slop_arena* arena, slop_list_types_Clause xs);
int64_t sriqindex_clause_sig(types_Clause c);
int64_t sriqindex_lit_bit(int64_t side, types_Lit l);
int64_t sriqindex_term_mix(types_ATerm t);
int64_t sriqindex_sig_at(sriqindex_SubIndex ix, int64_t i);
slop_list_sriqindex_Entry sriqindex_sorted_entries(slop_arena* arena, slop_list_sriqindex_Entry raw);
int64_t sriqindex_lower_bound(slop_list_sriqindex_Entry es, int64_t side, types_Lit l, sriqindex_Entry fallback);
uint8_t sriqindex_probe(sriqindex_SubIndex ix, int64_t side, types_Lit l, types_Clause c, int64_t csig, int64_t skip);
uint8_t sriqindex_hit(sriqindex_SubIndex ix, sriqindex_Entry e, types_Clause c, int64_t csig, int64_t skip);
uint8_t sriqindex_x_subsumes(sriqindex_SubIndex ix, int64_t i, types_Clause c);
uint8_t sriqindex_some_subsumes(sriqindex_SubIndex ix, types_Clause c, int64_t skip);
slop_list_types_Clause sriqindex_distinct(slop_arena* arena, slop_list_types_Clause cs);
types_Clause sriqindex_clause_of(slop_list_types_Clause cs, int64_t k, types_Clause fallback);
slop_list_types_Clause sriqindex_merged(slop_arena* arena, slop_list_types_Clause a, slop_list_types_Clause b);
sriqsubsume_Committed sriqindex_commit_indexed(slop_arena* arena, slop_list_types_Clause ws, slop_list_types_Clause cs);
slop_option_types_ATerm sriqindex_fterm_key(types_ATerm t);
sriqindex_FPart sriqindex_fpart_at(slop_list_sriqindex_FPart ps, int64_t k, sriqindex_FPart fallback);
sriqindex_KIdx sriqindex_k_index(slop_arena* arena, sriqorder_SriqOrder ord, sriqctx_Triggers tr, slop_list_types_Clause cs);
sriqindex_KIdx sriqindex_k_index_premises(slop_arena* arena, sriqctx_Triggers tr, slop_list_sriq_Premise ps);
uint8_t sriqindex_unit_premise(sriq_Premise p);
slop_list_types_Lit sriqindex_ground_k2(slop_arena* arena, sriqctx_Triggers tr, sriq_SuccSig any, types_Lit l);
uint8_t sriqindex_no_fterm(types_Lit l);
slop_list_sriqindex_FPart sriqindex_fparts_of(slop_arena* arena, types_Lit l, uint8_t single);
uint8_t sriqindex_first_is(slop_list_sriqindex_FPart ps, types_ATerm t);
slop_list_sriqindex_FPart sriqindex_fparts_sorted(slop_arena* arena, slop_list_sriqindex_FPart raw);
int64_t sriqindex_fpart_lower(slop_list_sriqindex_FPart ps, types_ATerm t, sriqindex_FPart fallback);
sriq_KSets sriqindex_k_query(slop_arena* arena, sriqctx_Triggers tr, sriqindex_KIdx kx, sriq_SuccSig sg);
sriqindex_KPair sriqindex_k_walk(slop_arena* arena, sriqctx_Triggers tr, sriqindex_KIdx kx, sriq_SuccSig sg, types_ATerm t, sriqindex_FPart p0);

#ifndef SLOP_OPTION_SRIQINDEX_ENTRY_DEFINED
#define SLOP_OPTION_SRIQINDEX_ENTRY_DEFINED
SLOP_OPTION_DEFINE(sriqindex_Entry, slop_option_sriqindex_Entry)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_SRIQINDEX_SUBINDEX_DEFINED
#define SLOP_OPTION_SRIQINDEX_SUBINDEX_DEFINED
SLOP_OPTION_DEFINE(sriqindex_SubIndex, slop_option_sriqindex_SubIndex)
#endif

#ifndef SLOP_OPTION_SRIQINDEX_FPART_DEFINED
#define SLOP_OPTION_SRIQINDEX_FPART_DEFINED
SLOP_OPTION_DEFINE(sriqindex_FPart, slop_option_sriqindex_FPart)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

#ifndef SLOP_OPTION_SRIQINDEX_KIDX_DEFINED
#define SLOP_OPTION_SRIQINDEX_KIDX_DEFINED
SLOP_OPTION_DEFINE(sriqindex_KIdx, slop_option_sriqindex_KIdx)
#endif

#ifndef SLOP_OPTION_TYPES_ATERM_DEFINED
#define SLOP_OPTION_TYPES_ATERM_DEFINED
SLOP_OPTION_DEFINE(types_ATerm, slop_option_types_ATerm)
#endif

#ifndef SLOP_OPTION_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(sriq_Premise, slop_option_sriq_Premise)
#endif

#ifndef SLOP_OPTION_SRIQINDEX_KPAIR_DEFINED
#define SLOP_OPTION_SRIQINDEX_KPAIR_DEFINED
SLOP_OPTION_DEFINE(sriqindex_KPair, slop_option_sriqindex_KPair)
#endif


#endif
