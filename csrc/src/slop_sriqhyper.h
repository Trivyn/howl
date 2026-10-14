#ifndef SLOP_sriqhyper_H
#define SLOP_sriqhyper_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"
#include "slop_canon.h"
#include "slop_sriq.h"
#include "slop_sriqref.h"
#include "slop_sriqground.h"

typedef struct sriqhyper_HCtx sriqhyper_HCtx;
typedef struct sriqhyper_OKey sriqhyper_OKey;
typedef struct sriqhyper_HIdx sriqhyper_HIdx;
typedef struct sriqhyper_HOut sriqhyper_HOut;
typedef struct sriqhyper_CPrem sriqhyper_CPrem;
typedef struct sriqhyper_Group sriqhyper_Group;

#ifndef SLOP_LIST_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_LIST_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_list_sriq_Premise, slop_list_list_sriq_Premise)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(sriq_Premise, slop_list_sriq_Premise)
#endif

#ifndef SLOP_OPTION_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_LIST_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(slop_list_sriq_Premise, slop_option_list_sriq_Premise)
#endif

#ifndef SLOP_LIST_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_TYPES_CLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Clause, slop_list_types_Clause)
#endif

#ifndef SLOP_LIST_SRIQREF_DL4_DEFINED
#define SLOP_LIST_SRIQREF_DL4_DEFINED
#define SLOP_LIST_SRIQREF_DL4_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqref_Dl4, slop_list_sriqref_Dl4)
#endif

#ifndef SLOP_OPTION_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(sriq_Premise, slop_option_sriq_Premise)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_SRIQREF_DL4_DEFINED
#define SLOP_OPTION_SRIQREF_DL4_DEFINED
SLOP_OPTION_DEFINE(sriqref_Dl4, slop_option_sriqref_Dl4)
#endif

struct sriqhyper_HCtx {
    uint32_t v;
    uint8_t root;
    slop_list_sriq_Premise dps;
    slop_list_sriq_Premise aps;
    sriqground_PIdx dix;
    sriqground_PIdx oix;
    sriqground_PIdx aix;
};
typedef struct sriqhyper_HCtx sriqhyper_HCtx;

#ifndef SLOP_OPTION_SRIQHYPER_HCTX_DEFINED
#define SLOP_OPTION_SRIQHYPER_HCTX_DEFINED
SLOP_OPTION_DEFINE(sriqhyper_HCtx, slop_option_sriqhyper_HCtx)
#endif

struct sriqhyper_OKey {
    int64_t rank;
    uint32_t pred;
    int64_t oc;
    int64_t i;
};
typedef struct sriqhyper_OKey sriqhyper_OKey;

#ifndef SLOP_OPTION_SRIQHYPER_OKEY_DEFINED
#define SLOP_OPTION_SRIQHYPER_OKEY_DEFINED
SLOP_OPTION_DEFINE(sriqhyper_OKey, slop_option_sriqhyper_OKey)
#endif

#ifndef SLOP_LIST_SRIQHYPER_OKEY_DEFINED
#define SLOP_LIST_SRIQHYPER_OKEY_DEFINED
#define SLOP_LIST_SRIQHYPER_OKEY_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqhyper_OKey, slop_list_sriqhyper_OKey)
#endif

struct sriqhyper_HIdx {
    slop_list_types_Clause bodied;
    slop_list_types_Clause bodiless;
    slop_list_sriqhyper_OKey keys;
    int64_t width;
    slop_list_sriqref_Dl4 dl4s;
};
typedef struct sriqhyper_HIdx sriqhyper_HIdx;

#ifndef SLOP_OPTION_SRIQHYPER_HIDX_DEFINED
#define SLOP_OPTION_SRIQHYPER_HIDX_DEFINED
SLOP_OPTION_DEFINE(sriqhyper_HIdx, slop_option_sriqhyper_HIdx)
#endif

struct sriqhyper_HOut {
    sriqref_Out out;
    int64_t tried;
};
typedef struct sriqhyper_HOut sriqhyper_HOut;

#ifndef SLOP_OPTION_SRIQHYPER_HOUT_DEFINED
#define SLOP_OPTION_SRIQHYPER_HOUT_DEFINED
SLOP_OPTION_DEFINE(sriqhyper_HOut, slop_option_sriqhyper_HOut)
#endif

struct sriqhyper_CPrem {
    uint32_t u;
    sriq_Premise p;
};
typedef struct sriqhyper_CPrem sriqhyper_CPrem;

#ifndef SLOP_OPTION_SRIQHYPER_CPREM_DEFINED
#define SLOP_OPTION_SRIQHYPER_CPREM_DEFINED
SLOP_OPTION_DEFINE(sriqhyper_CPrem, slop_option_sriqhyper_CPrem)
#endif

#ifndef SLOP_LIST_SRIQHYPER_CPREM_DEFINED
#define SLOP_LIST_SRIQHYPER_CPREM_DEFINED
#define SLOP_LIST_SRIQHYPER_CPREM_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqhyper_CPrem, slop_list_sriqhyper_CPrem)
#endif

struct sriqhyper_Group {
    slop_list_sriqhyper_CPrem cps;
};
typedef struct sriqhyper_Group sriqhyper_Group;

#ifndef SLOP_OPTION_SRIQHYPER_GROUP_DEFINED
#define SLOP_OPTION_SRIQHYPER_GROUP_DEFINED
SLOP_OPTION_DEFINE(sriqhyper_Group, slop_option_sriqhyper_Group)
#endif

#ifndef SLOP_LIST_SRIQHYPER_GROUP_DEFINED
#define SLOP_LIST_SRIQHYPER_GROUP_DEFINED
#define SLOP_LIST_SRIQHYPER_GROUP_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqhyper_Group, slop_list_sriqhyper_Group)
#endif

sriqhyper_OKey sriqhyper_okey_at(slop_list_sriqhyper_OKey ks, int64_t k, sriqhyper_OKey fallback);
int64_t sriqhyper_okey_cmp(sriqhyper_OKey a, sriqhyper_OKey b);
sriqhyper_HIdx sriqhyper_h_index(slop_arena* arena, slop_list_types_Clause onto);
int64_t sriqhyper_widest(slop_list_types_Clause onto);
slop_list_sriqref_Dl4 sriqhyper_dl4s_of(slop_arena* arena, slop_list_types_Clause onto);
slop_list_sriqhyper_OKey sriqhyper_okeys_of(slop_arena* arena, types_Clause oc, int64_t n);
slop_list_sriqhyper_OKey sriqhyper_okeys_sorted(slop_arena* arena, slop_list_sriqhyper_OKey raw);
int64_t sriqhyper_okey_lower(slop_list_sriqhyper_OKey ks, sriqhyper_OKey key, sriqhyper_OKey fallback);
int64_t sriqhyper_pair_code(sriqhyper_HIdx hx, sriqhyper_OKey k);
slop_list_int sriqhyper_hyper_pairs(slop_arena* arena, sriqhyper_HIdx hx, slop_list_sriq_Premise ps);
slop_list_int sriqhyper_pairs_of(slop_arena* arena, sriqhyper_HIdx hx, slop_list_sriq_Premise ps, sriqhyper_OKey k0);
slop_list_int sriqhyper_pairs_under(slop_arena* arena, sriqhyper_HIdx hx, int64_t rank, uint32_t pred, sriqhyper_OKey k0);
slop_list_int sriqhyper_codes_set(slop_arena* arena, slop_list_int xs);
int64_t sriqhyper_code_at(slop_list_int xs, int64_t k);
slop_list_sriq_Premise sriqhyper_slot_ix_cands(slop_arena* arena, uint8_t root, types_Lit a, sriqground_PIdx ix);
sriqhyper_HOut sriqhyper_hyper_anchor(slop_arena* arena, sriqref_Env env, sriqhyper_HCtx hc, sriq_HState start, types_Clause oc, int64_t i);
slop_list_sriq_Premise sriqhyper_slot_at(slop_arena* arena, sriqhyper_HCtx hc, types_Clause oc, int64_t i, int64_t j);
sriqhyper_HOut sriqhyper_hyper_product(slop_arena* arena, sriqref_Env env, sriqhyper_HCtx hc, sriq_HState start, types_Clause oc, slop_list_list_sriq_Premise cs);
slop_option_u32 sriqhyper_x_const(types_Lit a, sriq_Premise p);
sriqhyper_CPrem sriqhyper_cprem_at(slop_list_sriqhyper_CPrem xs, int64_t k, sriqhyper_CPrem fallback);
slop_list_sriqhyper_CPrem sriqhyper_by_const(slop_arena* arena, types_Lit a, slop_list_sriq_Premise ps);
slop_list_sriqhyper_CPrem sriqhyper_cprems_sorted(slop_arena* arena, slop_list_sriqhyper_CPrem raw, sriqhyper_CPrem c0);
slop_list_sriq_Premise sriqhyper_with_const(slop_arena* arena, slop_list_sriqhyper_CPrem xs, uint32_t u);
sriqhyper_HOut sriqhyper_hyper_root_groups(slop_arena* arena, sriqref_Env env, sriqhyper_HCtx hc, sriq_HState start, types_Clause oc, slop_list_list_sriq_Premise cs);
sriqhyper_HOut sriqhyper_root_by_const(slop_arena* arena, sriqref_Env env, sriqhyper_HCtx hc, sriq_HState start, types_Clause oc, slop_list_sriqhyper_Group groups, slop_list_sriqhyper_CPrem g0);
slop_list_list_sriq_Premise sriqhyper_slots_for(slop_arena* arena, slop_list_sriqhyper_Group groups, uint32_t u);
sriqhyper_HOut sriqhyper_hyper_indexed(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, sriqhyper_HCtx hc, int64_t room);
sriqhyper_HOut sriqhyper_hyper_code(slop_arena* arena, sriqref_Env env, sriqhyper_HIdx hx, sriqhyper_HCtx hc, sriq_HState start, int64_t code);

#ifndef SLOP_OPTION_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(sriq_Premise, slop_option_sriq_Premise)
#endif

#ifndef SLOP_OPTION_SRIQHYPER_HCTX_DEFINED
#define SLOP_OPTION_SRIQHYPER_HCTX_DEFINED
SLOP_OPTION_DEFINE(sriqhyper_HCtx, slop_option_sriqhyper_HCtx)
#endif

#ifndef SLOP_OPTION_SRIQHYPER_OKEY_DEFINED
#define SLOP_OPTION_SRIQHYPER_OKEY_DEFINED
SLOP_OPTION_DEFINE(sriqhyper_OKey, slop_option_sriqhyper_OKey)
#endif

#ifndef SLOP_OPTION_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(types_Clause, slop_option_types_Clause)
#endif

#ifndef SLOP_OPTION_SRIQREF_DL4_DEFINED
#define SLOP_OPTION_SRIQREF_DL4_DEFINED
SLOP_OPTION_DEFINE(sriqref_Dl4, slop_option_sriqref_Dl4)
#endif

#ifndef SLOP_OPTION_SRIQHYPER_HIDX_DEFINED
#define SLOP_OPTION_SRIQHYPER_HIDX_DEFINED
SLOP_OPTION_DEFINE(sriqhyper_HIdx, slop_option_sriqhyper_HIdx)
#endif

#ifndef SLOP_OPTION_SRIQHYPER_HOUT_DEFINED
#define SLOP_OPTION_SRIQHYPER_HOUT_DEFINED
SLOP_OPTION_DEFINE(sriqhyper_HOut, slop_option_sriqhyper_HOut)
#endif

#ifndef SLOP_OPTION_LIST_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_LIST_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(slop_list_sriq_Premise, slop_option_list_sriq_Premise)
#endif

#ifndef SLOP_OPTION_SRIQHYPER_CPREM_DEFINED
#define SLOP_OPTION_SRIQHYPER_CPREM_DEFINED
SLOP_OPTION_DEFINE(sriqhyper_CPrem, slop_option_sriqhyper_CPrem)
#endif

#ifndef SLOP_OPTION_SRIQHYPER_GROUP_DEFINED
#define SLOP_OPTION_SRIQHYPER_GROUP_DEFINED
SLOP_OPTION_DEFINE(sriqhyper_Group, slop_option_sriqhyper_Group)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_SRIQREF_CAND_DEFINED
#define SLOP_OPTION_SRIQREF_CAND_DEFINED
SLOP_OPTION_DEFINE(sriqref_Cand, slop_option_sriqref_Cand)
#endif

#ifndef SLOP_LIST_SRIQREF_CAND_DEFINED
#define SLOP_LIST_SRIQREF_CAND_DEFINED
#define SLOP_LIST_SRIQREF_CAND_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqref_Cand, slop_list_sriqref_Cand)
#endif


#endif
