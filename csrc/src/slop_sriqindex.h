#ifndef SLOP_sriqindex_H
#define SLOP_sriqindex_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_sriqclauses.h"
#include "slop_sriqsubsume.h"
#include "slop_canon.h"

typedef struct sriqindex_Entry sriqindex_Entry;
typedef struct sriqindex_SubIndex sriqindex_SubIndex;

#ifndef SLOP_LIST_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_TYPES_CLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Clause, slop_list_types_Clause)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
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
    slop_list_sriqindex_Entry entries;
    int64_t empty;
};
typedef struct sriqindex_SubIndex sriqindex_SubIndex;

#ifndef SLOP_OPTION_SRIQINDEX_SUBINDEX_DEFINED
#define SLOP_OPTION_SRIQINDEX_SUBINDEX_DEFINED
SLOP_OPTION_DEFINE(sriqindex_SubIndex, slop_option_sriqindex_SubIndex)
#endif

int64_t sriqindex_entry_cmp(sriqindex_Entry a, sriqindex_Entry b);
int64_t sriqindex_key_cmp(sriqindex_Entry e, int64_t side, types_Lit l);
sriqindex_Entry sriqindex_entry_at(slop_list_sriqindex_Entry es, int64_t k, sriqindex_Entry fallback);
slop_option_sriqindex_Entry sriqindex_key_of(types_Clause c, int64_t i);
sriqindex_SubIndex sriqindex_sub_index(slop_arena* arena, slop_list_types_Clause xs);
slop_list_sriqindex_Entry sriqindex_sorted_entries(slop_arena* arena, slop_list_sriqindex_Entry raw);
int64_t sriqindex_lower_bound(slop_list_sriqindex_Entry es, int64_t side, types_Lit l, sriqindex_Entry fallback);
uint8_t sriqindex_probe(sriqindex_SubIndex ix, int64_t side, types_Lit l, types_Clause c, int64_t skip);
uint8_t sriqindex_hit(sriqindex_SubIndex ix, sriqindex_Entry e, types_Clause c, int64_t skip);
uint8_t sriqindex_x_subsumes(sriqindex_SubIndex ix, int64_t i, types_Clause c);
uint8_t sriqindex_some_subsumes(sriqindex_SubIndex ix, types_Clause c, int64_t skip);
slop_list_types_Clause sriqindex_distinct(slop_arena* arena, slop_list_types_Clause cs);
types_Clause sriqindex_clause_of(slop_list_types_Clause cs, int64_t k, types_Clause fallback);
slop_list_types_Clause sriqindex_merged(slop_arena* arena, slop_list_types_Clause a, slop_list_types_Clause b);
sriqsubsume_Committed sriqindex_commit_indexed(slop_arena* arena, slop_list_types_Clause ws, slop_list_types_Clause cs);

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


#endif
