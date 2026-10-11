#ifndef SLOP_sriqorder_H
#define SLOP_sriqorder_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"

typedef struct sriqorder_ConstEntry sriqorder_ConstEntry;
typedef struct sriqorder_SriqOrder sriqorder_SriqOrder;
typedef struct sriqorder_CTerm sriqorder_CTerm;

typedef enum {
    sriqorder_CKind_ck_true,
    sriqorder_CKind_ck_a,
    sriqorder_CKind_ck_p
} sriqorder_CKind;

#ifndef SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_IMPL_DEFINED
SLOP_LIST_DEFINE(uint8_t, slop_list_u8)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_LIST_TYPES_LIT_DEFINED
#define SLOP_LIST_TYPES_LIT_DEFINED
#define SLOP_LIST_TYPES_LIT_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Lit, slop_list_types_Lit)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

struct sriqorder_ConstEntry {
    uint32_t base;
    uint32_t parent;
    uint32_t srole;
    uint32_t i;
    uint32_t len;
};
typedef struct sriqorder_ConstEntry sriqorder_ConstEntry;

#ifndef SLOP_OPTION_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_OPTION_SRIQORDER_CONSTENTRY_DEFINED
SLOP_OPTION_DEFINE(sriqorder_ConstEntry, slop_option_sriqorder_ConstEntry)
#endif

#ifndef SLOP_LIST_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_LIST_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_LIST_SRIQORDER_CONSTENTRY_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqorder_ConstEntry, slop_list_sriqorder_ConstEntry)
#endif

struct sriqorder_SriqOrder {
    slop_list_sriqorder_ConstEntry consts;
};
typedef struct sriqorder_SriqOrder sriqorder_SriqOrder;

#ifndef SLOP_OPTION_SRIQORDER_SRIQORDER_DEFINED
#define SLOP_OPTION_SRIQORDER_SRIQORDER_DEFINED
SLOP_OPTION_DEFINE(sriqorder_SriqOrder, slop_option_sriqorder_SriqOrder)
#endif

struct sriqorder_CTerm {
    sriqorder_CKind ck;
    types_ATerm a;
    types_Lit p;
};
typedef struct sriqorder_CTerm sriqorder_CTerm;

#ifndef SLOP_OPTION_SRIQORDER_CTERM_DEFINED
#define SLOP_OPTION_SRIQORDER_CTERM_DEFINED
SLOP_OPTION_DEFINE(sriqorder_CTerm, slop_option_sriqorder_CTerm)
#endif

#ifndef SLOP_LIST_SRIQORDER_CTERM_DEFINED
#define SLOP_LIST_SRIQORDER_CTERM_DEFINED
#define SLOP_LIST_SRIQORDER_CTERM_IMPL_DEFINED
SLOP_LIST_DEFINE(sriqorder_CTerm, slop_list_sriqorder_CTerm)
#endif

sriqorder_SriqOrder sriqorder_named_consts(slop_arena* arena, int64_t n);
sriqorder_ConstEntry sriqorder_aux_const(sriqorder_ConstEntry p, uint32_t pid, uint32_t s, uint32_t i);
sriqorder_ConstEntry sriqorder_const_entry(sriqorder_SriqOrder ord, uint32_t u);
uint8_t sriqorder_fn_gt(uint32_t f, uint32_t g);
int64_t sriqorder_cmp_u32(uint32_t a, uint32_t b);
int64_t sriqorder_letter_cmp(sriqorder_ConstEntry a, sriqorder_ConstEntry b);
int64_t sriqorder_label_cmp(sriqorder_SriqOrder ord, uint32_t a, uint32_t b);
uint8_t sriqorder_const_gt(sriqorder_SriqOrder ord, uint32_t a, uint32_t b);
uint8_t sriqorder_fx_over(sriqorder_SriqOrder ord, uint32_t f, types_ATerm b);
uint8_t sriqorder_fu_over(sriqorder_SriqOrder ord, uint32_t f, uint32_t u, types_ATerm b);
uint8_t sriqorder_aterm_gt(sriqorder_SriqOrder ord, types_ATerm a, types_ATerm b);
uint8_t sriqorder_aterm_same(types_ATerm a, types_ATerm b);
uint8_t sriqorder_aterm_ge(sriqorder_SriqOrder ord, types_ATerm a, types_ATerm b);
uint8_t sriqorder_pterm_gt(sriqorder_SriqOrder ord, types_Lit a, types_Lit b);
uint8_t sriqorder_pterm_over_aterm(sriqorder_SriqOrder ord, types_Lit a, types_ATerm s);
sriqorder_CTerm sriqorder_ct_true(void);
sriqorder_CTerm sriqorder_ct_a(types_ATerm s);
sriqorder_CTerm sriqorder_ct_p(types_Lit l);
uint8_t sriqorder_cterm_gt(sriqorder_SriqOrder ord, sriqorder_CTerm s, sriqorder_CTerm t);
uint8_t sriqorder_cterm_same(sriqorder_CTerm s, sriqorder_CTerm t);
slop_list_sriqorder_CTerm sriqorder_lit_ms(slop_arena* arena, types_Lit l);
slop_list_sriqorder_CTerm sriqorder_take_one(slop_arena* arena, slop_list_sriqorder_CTerm xs, sriqorder_CTerm y);
slop_list_sriqorder_CTerm sriqorder_ms_minus(slop_arena* arena, slop_list_sriqorder_CTerm xs, slop_list_sriqorder_CTerm ys);
uint8_t sriqorder_dominated(sriqorder_SriqOrder ord, slop_list_sriqorder_CTerm bs, sriqorder_CTerm a);
uint8_t sriqorder_mul_gt(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_sriqorder_CTerm m1, slop_list_sriqorder_CTerm m2);
uint8_t sriqorder_lit_gt(slop_arena* arena, sriqorder_SriqOrder ord, types_Lit l1, types_Lit l2);
uint8_t sriqorder_maximal_at(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Lit ls, int64_t i);
slop_list_u8 sriqorder_max_flags(slop_arena* arena, sriqorder_SriqOrder ord, slop_list_types_Lit ls);

#ifndef SLOP_OPTION_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_OPTION_SRIQORDER_CONSTENTRY_DEFINED
SLOP_OPTION_DEFINE(sriqorder_ConstEntry, slop_option_sriqorder_ConstEntry)
#endif

#ifndef SLOP_OPTION_SRIQORDER_SRIQORDER_DEFINED
#define SLOP_OPTION_SRIQORDER_SRIQORDER_DEFINED
SLOP_OPTION_DEFINE(sriqorder_SriqOrder, slop_option_sriqorder_SriqOrder)
#endif

#ifndef SLOP_OPTION_SRIQORDER_CTERM_DEFINED
#define SLOP_OPTION_SRIQORDER_CTERM_DEFINED
SLOP_OPTION_DEFINE(sriqorder_CTerm, slop_option_sriqorder_CTerm)
#endif

#ifndef SLOP_OPTION_TYPES_LIT_DEFINED
#define SLOP_OPTION_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(types_Lit, slop_option_types_Lit)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif


#endif
