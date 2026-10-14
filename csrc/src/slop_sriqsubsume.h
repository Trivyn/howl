#ifndef SLOP_sriqsubsume_H
#define SLOP_sriqsubsume_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_sriqclauses.h"
#include "slop_canon.h"

typedef struct sriqsubsume_Committed sriqsubsume_Committed;

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

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

struct sriqsubsume_Committed {
    slop_list_types_Clause set;
    slop_list_types_Clause added;
};
typedef struct sriqsubsume_Committed sriqsubsume_Committed;

#ifndef SLOP_OPTION_SRIQSUBSUME_COMMITTED_DEFINED
#define SLOP_OPTION_SRIQSUBSUME_COMMITTED_DEFINED
SLOP_OPTION_DEFINE(sriqsubsume_Committed, slop_option_sriqsubsume_Committed)
#endif

types_Lit sriqsubsume_no_lit(void);
types_Lit sriqsubsume_lit_at(slop_list_types_Lit xs, int64_t i);
uint8_t sriqsubsume_lits_subset(slop_list_types_Lit a, slop_list_types_Lit b);
uint8_t sriqsubsume_subsumes(types_Clause c, types_Clause d);
uint8_t sriqsubsume_reflexive_eq(types_Lit l);
uint8_t sriqsubsume_eq_of(types_Lit n, types_Lit e);
uint8_t sriqsubsume_has_eq_of(slop_list_types_Lit head, types_Lit n);
uint8_t sriqsubsume_taut_lit(slop_list_types_Lit head, types_Lit l);
uint8_t sriqsubsume_tautology(types_Clause c);
uint8_t sriqsubsume_taut_in(slop_list_types_Lit head);
uint8_t sriqsubsume_in_hat(types_Clause c, slop_list_types_Clause ws);
types_Clause sriqsubsume_clause_at(slop_list_types_Clause xs, int64_t i, types_Clause fallback);
slop_list_types_Clause sriqsubsume_by_content(slop_arena* arena, slop_list_types_Clause xs);
slop_list_types_Clause sriqsubsume_without_subsumed(slop_arena* arena, slop_list_types_Clause ws, types_Clause c);
uint8_t sriqsubsume_holds_clause(slop_list_types_Clause xs, types_Clause c);
sriqsubsume_Committed sriqsubsume_commit_min(slop_arena* arena, slop_list_types_Clause ws, slop_list_types_Clause cs);

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_SRIQSUBSUME_COMMITTED_DEFINED
#define SLOP_OPTION_SRIQSUBSUME_COMMITTED_DEFINED
SLOP_OPTION_DEFINE(sriqsubsume_Committed, slop_option_sriqsubsume_Committed)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif


#endif
