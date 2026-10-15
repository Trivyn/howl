#ifndef SLOP_sriqorder_H
#define SLOP_sriqorder_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"

typedef struct howl_sriqorder_ConstEntry howl_sriqorder_ConstEntry;
typedef struct howl_sriqorder_SriqOrder howl_sriqorder_SriqOrder;
typedef struct howl_sriqorder_CTerm howl_sriqorder_CTerm;

typedef enum {
    howl_sriqorder_CKind_ck_true,
    howl_sriqorder_CKind_ck_a,
    howl_sriqorder_CKind_ck_p
} howl_sriqorder_CKind;

#ifndef SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_IMPL_DEFINED
SLOP_LIST_DEFINE(uint8_t, slop_list_u8)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_HOWL_TYPES_LIT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Lit, slop_list_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

struct howl_sriqorder_ConstEntry {
    uint32_t base;
    uint32_t parent;
    uint32_t srole;
    uint32_t i;
    uint32_t len;
};
typedef struct howl_sriqorder_ConstEntry howl_sriqorder_ConstEntry;

#ifndef SLOP_OPTION_HOWL_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_OPTION_HOWL_SRIQORDER_CONSTENTRY_DEFINED
SLOP_OPTION_DEFINE(howl_sriqorder_ConstEntry, slop_option_howl_sriqorder_ConstEntry)
#endif

#ifndef SLOP_LIST_HOWL_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_LIST_HOWL_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_LIST_HOWL_SRIQORDER_CONSTENTRY_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqorder_ConstEntry, slop_list_howl_sriqorder_ConstEntry)
#endif

struct howl_sriqorder_SriqOrder {
    slop_list_howl_sriqorder_ConstEntry consts;
    int64_t rank;
};
typedef struct howl_sriqorder_SriqOrder howl_sriqorder_SriqOrder;

#ifndef SLOP_OPTION_HOWL_SRIQORDER_SRIQORDER_DEFINED
#define SLOP_OPTION_HOWL_SRIQORDER_SRIQORDER_DEFINED
SLOP_OPTION_DEFINE(howl_sriqorder_SriqOrder, slop_option_howl_sriqorder_SriqOrder)
#endif

struct howl_sriqorder_CTerm {
    howl_sriqorder_CKind ck;
    howl_types_ATerm a;
    howl_types_Lit p;
};
typedef struct howl_sriqorder_CTerm howl_sriqorder_CTerm;

#ifndef SLOP_OPTION_HOWL_SRIQORDER_CTERM_DEFINED
#define SLOP_OPTION_HOWL_SRIQORDER_CTERM_DEFINED
SLOP_OPTION_DEFINE(howl_sriqorder_CTerm, slop_option_howl_sriqorder_CTerm)
#endif

#ifndef SLOP_LIST_HOWL_SRIQORDER_CTERM_DEFINED
#define SLOP_LIST_HOWL_SRIQORDER_CTERM_DEFINED
#define SLOP_LIST_HOWL_SRIQORDER_CTERM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqorder_CTerm, slop_list_howl_sriqorder_CTerm)
#endif

howl_sriqorder_SriqOrder howl_sriqorder_named_consts(slop_arena* arena, int64_t n);
howl_sriqorder_SriqOrder howl_sriqorder_ranked(howl_sriqorder_SriqOrder ord, int64_t nquery);
howl_sriqorder_ConstEntry howl_sriqorder_aux_const(howl_sriqorder_ConstEntry p, uint32_t pid, uint32_t s, uint32_t i);
howl_sriqorder_ConstEntry howl_sriqorder_const_entry(howl_sriqorder_SriqOrder ord, uint32_t u);
uint8_t howl_sriqorder_fn_gt(uint32_t f, uint32_t g);
int64_t howl_sriqorder_cmp_u32(uint32_t a, uint32_t b);
int64_t howl_sriqorder_letter_cmp(howl_sriqorder_ConstEntry a, howl_sriqorder_ConstEntry b);
int64_t howl_sriqorder_label_cmp(howl_sriqorder_SriqOrder ord, uint32_t a, uint32_t b);
uint8_t howl_sriqorder_const_gt(howl_sriqorder_SriqOrder ord, uint32_t a, uint32_t b);
uint8_t howl_sriqorder_fx_over(howl_sriqorder_SriqOrder ord, uint32_t f, howl_types_ATerm b);
uint8_t howl_sriqorder_fu_over(howl_sriqorder_SriqOrder ord, uint32_t f, uint32_t u, howl_types_ATerm b);
uint8_t howl_sriqorder_aterm_gt(howl_sriqorder_SriqOrder ord, howl_types_ATerm a, howl_types_ATerm b);
uint8_t howl_sriqorder_aterm_same(howl_types_ATerm a, howl_types_ATerm b);
uint8_t howl_sriqorder_aterm_ge(howl_sriqorder_SriqOrder ord, howl_types_ATerm a, howl_types_ATerm b);
uint8_t howl_sriqorder_rank_gt(howl_sriqorder_SriqOrder ord, uint32_t p, uint32_t q);
uint8_t howl_sriqorder_ranked_unary_gt(howl_sriqorder_SriqOrder ord, howl_types_Lit a, howl_types_Lit b);
uint8_t howl_sriqorder_pterm_gt(howl_sriqorder_SriqOrder ord, howl_types_Lit a, howl_types_Lit b);
uint8_t howl_sriqorder_pterm_over_aterm(howl_sriqorder_SriqOrder ord, howl_types_Lit a, howl_types_ATerm s);
howl_sriqorder_CTerm howl_sriqorder_ct_true(void);
howl_sriqorder_CTerm howl_sriqorder_ct_a(howl_types_ATerm s);
howl_sriqorder_CTerm howl_sriqorder_ct_p(howl_types_Lit l);
uint8_t howl_sriqorder_cterm_gt(howl_sriqorder_SriqOrder ord, howl_sriqorder_CTerm s, howl_sriqorder_CTerm t);
uint8_t howl_sriqorder_cterm_same(howl_sriqorder_CTerm s, howl_sriqorder_CTerm t);
slop_list_howl_sriqorder_CTerm howl_sriqorder_lit_ms(slop_arena* arena, howl_types_Lit l);
slop_list_howl_sriqorder_CTerm howl_sriqorder_take_one(slop_arena* arena, slop_list_howl_sriqorder_CTerm xs, howl_sriqorder_CTerm y);
slop_list_howl_sriqorder_CTerm howl_sriqorder_ms_minus(slop_arena* arena, slop_list_howl_sriqorder_CTerm xs, slop_list_howl_sriqorder_CTerm ys);
uint8_t howl_sriqorder_dominated(howl_sriqorder_SriqOrder ord, slop_list_howl_sriqorder_CTerm bs, howl_sriqorder_CTerm a);
uint8_t howl_sriqorder_mul_gt(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_sriqorder_CTerm m1, slop_list_howl_sriqorder_CTerm m2);
uint8_t howl_sriqorder_lit_gt(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_types_Lit l1, howl_types_Lit l2);
uint8_t howl_sriqorder_maximal_at(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Lit ls, int64_t i);
slop_list_u8 howl_sriqorder_max_flags(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Lit ls);

#ifndef SLOP_OPTION_HOWL_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_OPTION_HOWL_SRIQORDER_CONSTENTRY_DEFINED
SLOP_OPTION_DEFINE(howl_sriqorder_ConstEntry, slop_option_howl_sriqorder_ConstEntry)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQORDER_SRIQORDER_DEFINED
#define SLOP_OPTION_HOWL_SRIQORDER_SRIQORDER_DEFINED
SLOP_OPTION_DEFINE(howl_sriqorder_SriqOrder, slop_option_howl_sriqorder_SriqOrder)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQORDER_CTERM_DEFINED
#define SLOP_OPTION_HOWL_SRIQORDER_CTERM_DEFINED
SLOP_OPTION_DEFINE(howl_sriqorder_CTerm, slop_option_howl_sriqorder_CTerm)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif


#endif
