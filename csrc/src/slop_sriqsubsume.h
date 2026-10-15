#ifndef SLOP_sriqsubsume_H
#define SLOP_sriqsubsume_H

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
#include "slop_canon.h"

typedef struct howl_sriqsubsume_Committed howl_sriqsubsume_Committed;

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

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

struct howl_sriqsubsume_Committed {
    slop_list_howl_types_Clause set;
    slop_list_howl_types_Clause added;
};
typedef struct howl_sriqsubsume_Committed howl_sriqsubsume_Committed;

#ifndef SLOP_OPTION_HOWL_SRIQSUBSUME_COMMITTED_DEFINED
#define SLOP_OPTION_HOWL_SRIQSUBSUME_COMMITTED_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsubsume_Committed, slop_option_howl_sriqsubsume_Committed)
#endif

howl_types_Lit howl_sriqsubsume_no_lit(void);
howl_types_Lit howl_sriqsubsume_lit_at(slop_list_howl_types_Lit xs, int64_t i);
uint8_t howl_sriqsubsume_lits_subset(slop_list_howl_types_Lit a, slop_list_howl_types_Lit b);
uint8_t howl_sriqsubsume_subsumes(howl_types_Clause c, howl_types_Clause d);
uint8_t howl_sriqsubsume_reflexive_eq(howl_types_Lit l);
uint8_t howl_sriqsubsume_eq_of(howl_types_Lit n, howl_types_Lit e);
uint8_t howl_sriqsubsume_has_eq_of(slop_list_howl_types_Lit head, howl_types_Lit n);
uint8_t howl_sriqsubsume_taut_lit(slop_list_howl_types_Lit head, howl_types_Lit l);
uint8_t howl_sriqsubsume_tautology(howl_types_Clause c);
uint8_t howl_sriqsubsume_taut_in(slop_list_howl_types_Lit head);
uint8_t howl_sriqsubsume_in_hat(howl_types_Clause c, slop_list_howl_types_Clause ws);
howl_types_Clause howl_sriqsubsume_clause_at(slop_list_howl_types_Clause xs, int64_t i, howl_types_Clause fallback);
slop_list_howl_types_Clause howl_sriqsubsume_by_content(slop_arena* arena, slop_list_howl_types_Clause xs);
slop_list_howl_types_Clause howl_sriqsubsume_without_subsumed(slop_arena* arena, slop_list_howl_types_Clause ws, howl_types_Clause c);
uint8_t howl_sriqsubsume_holds_clause(slop_list_howl_types_Clause xs, howl_types_Clause c);
howl_sriqsubsume_Committed howl_sriqsubsume_commit_min(slop_arena* arena, slop_list_howl_types_Clause ws, slop_list_howl_types_Clause cs);

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQSUBSUME_COMMITTED_DEFINED
#define SLOP_OPTION_HOWL_SRIQSUBSUME_COMMITTED_DEFINED
SLOP_OPTION_DEFINE(howl_sriqsubsume_Committed, slop_option_howl_sriqsubsume_Committed)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif


#endif
