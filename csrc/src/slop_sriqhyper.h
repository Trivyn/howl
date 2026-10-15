#ifndef SLOP_sriqhyper_H
#define SLOP_sriqhyper_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_canon.h"
#include "slop_sriq.h"
#include "slop_sriqref.h"
#include "slop_sriqground.h"

typedef struct howl_sriqhyper_HCtx howl_sriqhyper_HCtx;
typedef struct howl_sriqhyper_OKey howl_sriqhyper_OKey;
typedef struct howl_sriqhyper_HIdx howl_sriqhyper_HIdx;
typedef struct howl_sriqhyper_HOut howl_sriqhyper_HOut;
typedef struct howl_sriqhyper_CPrem howl_sriqhyper_CPrem;
typedef struct howl_sriqhyper_Group howl_sriqhyper_Group;

#ifndef SLOP_LIST_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_LIST_HOWL_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_list_howl_sriq_Premise, slop_list_list_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_Premise, slop_list_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_LIST_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(slop_list_howl_sriq_Premise, slop_option_list_howl_sriq_Premise)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Clause, slop_list_howl_types_Clause)
#endif

#ifndef SLOP_LIST_HOWL_SRIQREF_DL4_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_DL4_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_DL4_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqref_Dl4, slop_list_howl_sriqref_Dl4)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Premise, slop_option_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_DL4_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_DL4_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Dl4, slop_option_howl_sriqref_Dl4)
#endif

struct howl_sriqhyper_HCtx {
    uint32_t v;
    uint8_t root;
    slop_list_howl_sriq_Premise dps;
    slop_list_howl_sriq_Premise aps;
    howl_sriqground_PIdx dix;
    howl_sriqground_PIdx oix;
    howl_sriqground_PIdx aix;
};
typedef struct howl_sriqhyper_HCtx howl_sriqhyper_HCtx;

#ifndef SLOP_OPTION_HOWL_SRIQHYPER_HCTX_DEFINED
#define SLOP_OPTION_HOWL_SRIQHYPER_HCTX_DEFINED
SLOP_OPTION_DEFINE(howl_sriqhyper_HCtx, slop_option_howl_sriqhyper_HCtx)
#endif

struct howl_sriqhyper_OKey {
    int64_t rank;
    uint32_t pred;
    int64_t oc;
    int64_t i;
};
typedef struct howl_sriqhyper_OKey howl_sriqhyper_OKey;

#ifndef SLOP_OPTION_HOWL_SRIQHYPER_OKEY_DEFINED
#define SLOP_OPTION_HOWL_SRIQHYPER_OKEY_DEFINED
SLOP_OPTION_DEFINE(howl_sriqhyper_OKey, slop_option_howl_sriqhyper_OKey)
#endif

#ifndef SLOP_LIST_HOWL_SRIQHYPER_OKEY_DEFINED
#define SLOP_LIST_HOWL_SRIQHYPER_OKEY_DEFINED
#define SLOP_LIST_HOWL_SRIQHYPER_OKEY_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqhyper_OKey, slop_list_howl_sriqhyper_OKey)
#endif

struct howl_sriqhyper_HIdx {
    slop_list_howl_types_Clause bodied;
    slop_list_howl_types_Clause bodiless;
    slop_list_howl_sriqhyper_OKey keys;
    int64_t width;
    slop_list_howl_sriqref_Dl4 dl4s;
};
typedef struct howl_sriqhyper_HIdx howl_sriqhyper_HIdx;

#ifndef SLOP_OPTION_HOWL_SRIQHYPER_HIDX_DEFINED
#define SLOP_OPTION_HOWL_SRIQHYPER_HIDX_DEFINED
SLOP_OPTION_DEFINE(howl_sriqhyper_HIdx, slop_option_howl_sriqhyper_HIdx)
#endif

struct howl_sriqhyper_HOut {
    howl_sriqref_Out out;
    int64_t tried;
};
typedef struct howl_sriqhyper_HOut howl_sriqhyper_HOut;

#ifndef SLOP_OPTION_HOWL_SRIQHYPER_HOUT_DEFINED
#define SLOP_OPTION_HOWL_SRIQHYPER_HOUT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqhyper_HOut, slop_option_howl_sriqhyper_HOut)
#endif

struct howl_sriqhyper_CPrem {
    uint32_t u;
    howl_sriq_Premise p;
};
typedef struct howl_sriqhyper_CPrem howl_sriqhyper_CPrem;

#ifndef SLOP_OPTION_HOWL_SRIQHYPER_CPREM_DEFINED
#define SLOP_OPTION_HOWL_SRIQHYPER_CPREM_DEFINED
SLOP_OPTION_DEFINE(howl_sriqhyper_CPrem, slop_option_howl_sriqhyper_CPrem)
#endif

#ifndef SLOP_LIST_HOWL_SRIQHYPER_CPREM_DEFINED
#define SLOP_LIST_HOWL_SRIQHYPER_CPREM_DEFINED
#define SLOP_LIST_HOWL_SRIQHYPER_CPREM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqhyper_CPrem, slop_list_howl_sriqhyper_CPrem)
#endif

struct howl_sriqhyper_Group {
    slop_list_howl_sriqhyper_CPrem cps;
};
typedef struct howl_sriqhyper_Group howl_sriqhyper_Group;

#ifndef SLOP_OPTION_HOWL_SRIQHYPER_GROUP_DEFINED
#define SLOP_OPTION_HOWL_SRIQHYPER_GROUP_DEFINED
SLOP_OPTION_DEFINE(howl_sriqhyper_Group, slop_option_howl_sriqhyper_Group)
#endif

#ifndef SLOP_LIST_HOWL_SRIQHYPER_GROUP_DEFINED
#define SLOP_LIST_HOWL_SRIQHYPER_GROUP_DEFINED
#define SLOP_LIST_HOWL_SRIQHYPER_GROUP_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqhyper_Group, slop_list_howl_sriqhyper_Group)
#endif

howl_sriqhyper_OKey howl_sriqhyper_okey_at(slop_list_howl_sriqhyper_OKey ks, int64_t k, howl_sriqhyper_OKey fallback);
int64_t howl_sriqhyper_okey_cmp(howl_sriqhyper_OKey a, howl_sriqhyper_OKey b);
howl_sriqhyper_HIdx howl_sriqhyper_h_index(slop_arena* arena, slop_list_howl_types_Clause onto);
int64_t howl_sriqhyper_widest(slop_list_howl_types_Clause onto);
slop_list_howl_sriqref_Dl4 howl_sriqhyper_dl4s_of(slop_arena* arena, slop_list_howl_types_Clause onto);
slop_list_howl_sriqhyper_OKey howl_sriqhyper_okeys_of(slop_arena* arena, howl_types_Clause oc, int64_t n);
slop_list_howl_sriqhyper_OKey howl_sriqhyper_okeys_sorted(slop_arena* arena, slop_list_howl_sriqhyper_OKey raw);
int64_t howl_sriqhyper_okey_lower(slop_list_howl_sriqhyper_OKey ks, howl_sriqhyper_OKey key, howl_sriqhyper_OKey fallback);
int64_t howl_sriqhyper_pair_code(howl_sriqhyper_HIdx hx, howl_sriqhyper_OKey k);
slop_list_int howl_sriqhyper_hyper_pairs(slop_arena* arena, howl_sriqhyper_HIdx hx, slop_list_howl_sriq_Premise ps);
slop_list_int howl_sriqhyper_pairs_of(slop_arena* arena, howl_sriqhyper_HIdx hx, slop_list_howl_sriq_Premise ps, howl_sriqhyper_OKey k0);
slop_list_int howl_sriqhyper_pairs_under(slop_arena* arena, howl_sriqhyper_HIdx hx, int64_t rank, uint32_t pred, howl_sriqhyper_OKey k0);
slop_list_int howl_sriqhyper_codes_set(slop_arena* arena, slop_list_int xs);
int64_t howl_sriqhyper_code_at(slop_list_int xs, int64_t k);
slop_list_howl_sriq_Premise howl_sriqhyper_slot_ix_cands(slop_arena* arena, uint8_t root, howl_types_Lit a, howl_sriqground_PIdx ix);
howl_sriqhyper_HOut howl_sriqhyper_hyper_anchor(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HCtx hc, howl_sriq_HState start, howl_types_Clause oc, int64_t i);
slop_list_howl_sriq_Premise howl_sriqhyper_slot_at(slop_arena* arena, howl_sriqhyper_HCtx hc, howl_types_Clause oc, int64_t i, int64_t j);
howl_sriqhyper_HOut howl_sriqhyper_hyper_product(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HCtx hc, howl_sriq_HState start, howl_types_Clause oc, slop_list_list_howl_sriq_Premise cs);
slop_option_u32 howl_sriqhyper_x_const(howl_types_Lit a, howl_sriq_Premise p);
howl_sriqhyper_CPrem howl_sriqhyper_cprem_at(slop_list_howl_sriqhyper_CPrem xs, int64_t k, howl_sriqhyper_CPrem fallback);
slop_list_howl_sriqhyper_CPrem howl_sriqhyper_by_const(slop_arena* arena, howl_types_Lit a, slop_list_howl_sriq_Premise ps);
slop_list_howl_sriqhyper_CPrem howl_sriqhyper_cprems_sorted(slop_arena* arena, slop_list_howl_sriqhyper_CPrem raw, howl_sriqhyper_CPrem c0);
slop_list_howl_sriq_Premise howl_sriqhyper_with_const(slop_arena* arena, slop_list_howl_sriqhyper_CPrem xs, uint32_t u);
howl_sriqhyper_HOut howl_sriqhyper_hyper_root_groups(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HCtx hc, howl_sriq_HState start, howl_types_Clause oc, slop_list_list_howl_sriq_Premise cs);
howl_sriqhyper_HOut howl_sriqhyper_root_by_const(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HCtx hc, howl_sriq_HState start, howl_types_Clause oc, slop_list_howl_sriqhyper_Group groups, slop_list_howl_sriqhyper_CPrem g0);
slop_list_list_howl_sriq_Premise howl_sriqhyper_slots_for(slop_arena* arena, slop_list_howl_sriqhyper_Group groups, uint32_t u);
howl_sriqhyper_HOut howl_sriqhyper_hyper_indexed(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HIdx hx, howl_sriqhyper_HCtx hc, int64_t room);
howl_sriqhyper_HOut howl_sriqhyper_hyper_code(slop_arena* arena, howl_sriqref_Env env, howl_sriqhyper_HIdx hx, howl_sriqhyper_HCtx hc, howl_sriq_HState start, int64_t code);

#ifndef SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Premise, slop_option_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQHYPER_HCTX_DEFINED
#define SLOP_OPTION_HOWL_SRIQHYPER_HCTX_DEFINED
SLOP_OPTION_DEFINE(howl_sriqhyper_HCtx, slop_option_howl_sriqhyper_HCtx)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQHYPER_OKEY_DEFINED
#define SLOP_OPTION_HOWL_SRIQHYPER_OKEY_DEFINED
SLOP_OPTION_DEFINE(howl_sriqhyper_OKey, slop_option_howl_sriqhyper_OKey)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_DL4_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_DL4_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Dl4, slop_option_howl_sriqref_Dl4)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQHYPER_HIDX_DEFINED
#define SLOP_OPTION_HOWL_SRIQHYPER_HIDX_DEFINED
SLOP_OPTION_DEFINE(howl_sriqhyper_HIdx, slop_option_howl_sriqhyper_HIdx)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQHYPER_HOUT_DEFINED
#define SLOP_OPTION_HOWL_SRIQHYPER_HOUT_DEFINED
SLOP_OPTION_DEFINE(howl_sriqhyper_HOut, slop_option_howl_sriqhyper_HOut)
#endif

#ifndef SLOP_OPTION_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_LIST_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(slop_list_howl_sriq_Premise, slop_option_list_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQHYPER_CPREM_DEFINED
#define SLOP_OPTION_HOWL_SRIQHYPER_CPREM_DEFINED
SLOP_OPTION_DEFINE(howl_sriqhyper_CPrem, slop_option_howl_sriqhyper_CPrem)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQHYPER_GROUP_DEFINED
#define SLOP_OPTION_HOWL_SRIQHYPER_GROUP_DEFINED
SLOP_OPTION_DEFINE(howl_sriqhyper_Group, slop_option_howl_sriqhyper_Group)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQREF_CAND_DEFINED
#define SLOP_OPTION_HOWL_SRIQREF_CAND_DEFINED
SLOP_OPTION_DEFINE(howl_sriqref_Cand, slop_option_howl_sriqref_Cand)
#endif

#ifndef SLOP_LIST_HOWL_SRIQREF_CAND_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_CAND_DEFINED
#define SLOP_LIST_HOWL_SRIQREF_CAND_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqref_Cand, slop_list_howl_sriqref_Cand)
#endif


#endif
