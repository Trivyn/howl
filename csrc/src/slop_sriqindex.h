#ifndef SLOP_sriqindex_H
#define SLOP_sriqindex_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_sriqclauses.h"
#include "slop_sriqctx.h"
#include "slop_sriqorder.h"
#include "slop_sriq.h"
#include "slop_sriqsubsume.h"
#include "slop_canon.h"

typedef struct howl_sriqindex_Entry howl_sriqindex_Entry;
typedef struct howl_sriqindex_SubIndex howl_sriqindex_SubIndex;
typedef struct howl_sriqindex_FPart howl_sriqindex_FPart;
typedef struct howl_sriqindex_KIdx howl_sriqindex_KIdx;
typedef struct howl_sriqindex_KPair howl_sriqindex_KPair;

#ifndef SLOP_LIST_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Clause, slop_list_howl_types_Clause)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_HOWL_TYPES_LIT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Lit, slop_list_howl_types_Lit)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_Premise, slop_list_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ATERM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ATERM_DEFINED
SLOP_OPTION_DEFINE(howl_types_ATerm, slop_option_howl_types_ATerm)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Premise, slop_option_howl_sriq_Premise)
#endif

struct howl_sriqindex_Entry {
    int64_t side;
    howl_types_Lit lit;
    int64_t i;
};
typedef struct howl_sriqindex_Entry howl_sriqindex_Entry;

#ifndef SLOP_OPTION_HOWL_SRIQINDEX_ENTRY_DEFINED
#define SLOP_OPTION_HOWL_SRIQINDEX_ENTRY_DEFINED
SLOP_OPTION_DEFINE(howl_sriqindex_Entry, slop_option_howl_sriqindex_Entry)
#endif

#ifndef SLOP_LIST_HOWL_SRIQINDEX_ENTRY_DEFINED
#define SLOP_LIST_HOWL_SRIQINDEX_ENTRY_DEFINED
#define SLOP_LIST_HOWL_SRIQINDEX_ENTRY_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqindex_Entry, slop_list_howl_sriqindex_Entry)
#endif

struct howl_sriqindex_SubIndex {
    slop_list_howl_types_Clause xs;
    slop_list_int sigs;
    slop_list_howl_sriqindex_Entry entries;
    int64_t empty;
};
typedef struct howl_sriqindex_SubIndex howl_sriqindex_SubIndex;

#ifndef SLOP_OPTION_HOWL_SRIQINDEX_SUBINDEX_DEFINED
#define SLOP_OPTION_HOWL_SRIQINDEX_SUBINDEX_DEFINED
SLOP_OPTION_DEFINE(howl_sriqindex_SubIndex, slop_option_howl_sriqindex_SubIndex)
#endif

struct howl_sriqindex_FPart {
    howl_types_ATerm t;
    howl_types_Lit lit;
    uint8_t single;
};
typedef struct howl_sriqindex_FPart howl_sriqindex_FPart;

#ifndef SLOP_OPTION_HOWL_SRIQINDEX_FPART_DEFINED
#define SLOP_OPTION_HOWL_SRIQINDEX_FPART_DEFINED
SLOP_OPTION_DEFINE(howl_sriqindex_FPart, slop_option_howl_sriqindex_FPart)
#endif

#ifndef SLOP_LIST_HOWL_SRIQINDEX_FPART_DEFINED
#define SLOP_LIST_HOWL_SRIQINDEX_FPART_DEFINED
#define SLOP_LIST_HOWL_SRIQINDEX_FPART_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqindex_FPart, slop_list_howl_sriqindex_FPart)
#endif

struct howl_sriqindex_KIdx {
    slop_list_howl_types_Lit ground;
    slop_list_howl_sriqindex_FPart fparts;
};
typedef struct howl_sriqindex_KIdx howl_sriqindex_KIdx;

#ifndef SLOP_OPTION_HOWL_SRIQINDEX_KIDX_DEFINED
#define SLOP_OPTION_HOWL_SRIQINDEX_KIDX_DEFINED
SLOP_OPTION_DEFINE(howl_sriqindex_KIdx, slop_option_howl_sriqindex_KIdx)
#endif

struct howl_sriqindex_KPair {
    slop_list_howl_types_Lit k1;
    slop_list_howl_types_Lit k2;
};
typedef struct howl_sriqindex_KPair howl_sriqindex_KPair;

#ifndef SLOP_OPTION_HOWL_SRIQINDEX_KPAIR_DEFINED
#define SLOP_OPTION_HOWL_SRIQINDEX_KPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_sriqindex_KPair, slop_option_howl_sriqindex_KPair)
#endif

int64_t howl_sriqindex_entry_cmp(howl_sriqindex_Entry a, howl_sriqindex_Entry b);
int64_t howl_sriqindex_key_cmp(howl_sriqindex_Entry e, int64_t side, howl_types_Lit l);
howl_sriqindex_Entry howl_sriqindex_entry_at(slop_list_howl_sriqindex_Entry es, int64_t k, howl_sriqindex_Entry fallback);
slop_option_howl_sriqindex_Entry howl_sriqindex_key_of(howl_types_Clause c, int64_t i);
howl_sriqindex_SubIndex howl_sriqindex_sub_index(slop_arena* arena, slop_list_howl_types_Clause xs);
int64_t howl_sriqindex_clause_sig(howl_types_Clause c);
int64_t howl_sriqindex_lit_bit(int64_t side, howl_types_Lit l);
int64_t howl_sriqindex_term_mix(howl_types_ATerm t);
int64_t howl_sriqindex_sig_at(howl_sriqindex_SubIndex ix, int64_t i);
slop_list_howl_sriqindex_Entry howl_sriqindex_sorted_entries(slop_arena* arena, slop_list_howl_sriqindex_Entry raw);
int64_t howl_sriqindex_lower_bound(slop_list_howl_sriqindex_Entry es, int64_t side, howl_types_Lit l, howl_sriqindex_Entry fallback);
uint8_t howl_sriqindex_probe(howl_sriqindex_SubIndex ix, int64_t side, howl_types_Lit l, howl_types_Clause c, int64_t csig, int64_t skip);
uint8_t howl_sriqindex_hit(howl_sriqindex_SubIndex ix, howl_sriqindex_Entry e, howl_types_Clause c, int64_t csig, int64_t skip);
uint8_t howl_sriqindex_x_subsumes(howl_sriqindex_SubIndex ix, int64_t i, howl_types_Clause c);
uint8_t howl_sriqindex_some_subsumes(howl_sriqindex_SubIndex ix, howl_types_Clause c, int64_t skip);
slop_list_howl_types_Clause howl_sriqindex_distinct(slop_arena* arena, slop_list_howl_types_Clause cs);
howl_types_Clause howl_sriqindex_clause_of(slop_list_howl_types_Clause cs, int64_t k, howl_types_Clause fallback);
slop_list_howl_types_Clause howl_sriqindex_merged(slop_arena* arena, slop_list_howl_types_Clause a, slop_list_howl_types_Clause b);
howl_sriqsubsume_Committed howl_sriqindex_commit_indexed(slop_arena* arena, slop_list_howl_types_Clause ws, slop_list_howl_types_Clause cs);
slop_option_howl_types_ATerm howl_sriqindex_fterm_key(howl_types_ATerm t);
howl_sriqindex_FPart howl_sriqindex_fpart_at(slop_list_howl_sriqindex_FPart ps, int64_t k, howl_sriqindex_FPart fallback);
howl_sriqindex_KIdx howl_sriqindex_k_index(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriqctx_Triggers tr, slop_list_howl_types_Clause cs);
howl_sriqindex_KIdx howl_sriqindex_k_index_premises(slop_arena* arena, howl_sriqctx_Triggers tr, slop_list_howl_sriq_Premise ps);
uint8_t howl_sriqindex_unit_premise(howl_sriq_Premise p);
slop_list_howl_types_Lit howl_sriqindex_ground_k2(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriq_SuccSig any, howl_types_Lit l);
uint8_t howl_sriqindex_no_fterm(howl_types_Lit l);
slop_list_howl_sriqindex_FPart howl_sriqindex_fparts_of(slop_arena* arena, howl_types_Lit l, uint8_t single);
uint8_t howl_sriqindex_first_is(slop_list_howl_sriqindex_FPart ps, howl_types_ATerm t);
slop_list_howl_sriqindex_FPart howl_sriqindex_fparts_sorted(slop_arena* arena, slop_list_howl_sriqindex_FPart raw);
int64_t howl_sriqindex_fpart_lower(slop_list_howl_sriqindex_FPart ps, howl_types_ATerm t, howl_sriqindex_FPart fallback);
howl_sriq_KSets howl_sriqindex_k_query(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqindex_KIdx kx, howl_sriq_SuccSig sg);
howl_sriqindex_KPair howl_sriqindex_k_walk(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqindex_KIdx kx, howl_sriq_SuccSig sg, howl_types_ATerm t, howl_sriqindex_FPart p0);

#ifndef SLOP_OPTION_HOWL_SRIQINDEX_ENTRY_DEFINED
#define SLOP_OPTION_HOWL_SRIQINDEX_ENTRY_DEFINED
SLOP_OPTION_DEFINE(howl_sriqindex_Entry, slop_option_howl_sriqindex_Entry)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQINDEX_SUBINDEX_DEFINED
#define SLOP_OPTION_HOWL_SRIQINDEX_SUBINDEX_DEFINED
SLOP_OPTION_DEFINE(howl_sriqindex_SubIndex, slop_option_howl_sriqindex_SubIndex)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQINDEX_FPART_DEFINED
#define SLOP_OPTION_HOWL_SRIQINDEX_FPART_DEFINED
SLOP_OPTION_DEFINE(howl_sriqindex_FPart, slop_option_howl_sriqindex_FPart)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQINDEX_KIDX_DEFINED
#define SLOP_OPTION_HOWL_SRIQINDEX_KIDX_DEFINED
SLOP_OPTION_DEFINE(howl_sriqindex_KIdx, slop_option_howl_sriqindex_KIdx)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ATERM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ATERM_DEFINED
SLOP_OPTION_DEFINE(howl_types_ATerm, slop_option_howl_types_ATerm)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Premise, slop_option_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQINDEX_KPAIR_DEFINED
#define SLOP_OPTION_HOWL_SRIQINDEX_KPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_sriqindex_KPair, slop_option_howl_sriqindex_KPair)
#endif


#endif
