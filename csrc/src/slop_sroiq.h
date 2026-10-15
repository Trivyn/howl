#ifndef SLOP_sroiq_H
#define SLOP_sroiq_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"
#include "slop_canon.h"

typedef struct howl_sroiq_SConcept howl_sroiq_SConcept;
typedef struct howl_sroiq_SRia howl_sroiq_SRia;
typedef struct howl_sroiq_SAxiom howl_sroiq_SAxiom;

typedef enum {
    howl_sroiq_ElimKind_ek_i_all,
    howl_sroiq_ElimKind_ek_f_all,
    howl_sroiq_ElimKind_ek_i_some,
    howl_sroiq_ElimKind_ek_f_some
} howl_sroiq_ElimKind;

#ifndef SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_RoleId, slop_list_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

struct howl_sroiq_SRia {
    slop_list_howl_types_RoleId word;
    howl_types_RoleId super;
};
typedef struct howl_sroiq_SRia howl_sroiq_SRia;

#ifndef SLOP_OPTION_HOWL_SROIQ_SRIA_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SRIA_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SRia, slop_option_howl_sroiq_SRia)
#endif

typedef enum {
    howl_sroiq_SAxiom_sa_gci,
    howl_sroiq_SAxiom_sa_ria,
    howl_sroiq_SAxiom_sa_ref,
    howl_sroiq_SAxiom_sa_irr,
    howl_sroiq_SAxiom_sa_dis
} howl_sroiq_SAxiom_tag;

struct howl_sroiq_SAxiom {
    howl_sroiq_SAxiom_tag tag;
    union {
        struct {
            howl_sroiq_SConcept* f0;
            howl_sroiq_SConcept* f1;
        } sa_gci;
        howl_sroiq_SRia sa_ria;
        howl_types_RoleId sa_ref;
        howl_types_RoleId sa_irr;
        struct {
            howl_types_RoleId f0;
            howl_types_RoleId f1;
        } sa_dis;
    } data;
};
typedef struct howl_sroiq_SAxiom howl_sroiq_SAxiom;

#ifndef SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SAxiom, slop_option_howl_sroiq_SAxiom)
#endif

#ifndef SLOP_LIST_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sroiq_SAxiom, slop_list_howl_sroiq_SAxiom)
#endif

#ifndef SLOP_LIST_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SCONCEPT_DEFINED
SLOP_LIST_DECLARE(howl_sroiq_SConcept, slop_list_howl_sroiq_SConcept)
#endif

typedef enum {
    howl_sroiq_SConcept_sc_top,
    howl_sroiq_SConcept_sc_bottom,
    howl_sroiq_SConcept_sc_name,
    howl_sroiq_SConcept_sc_nominal,
    howl_sroiq_SConcept_sc_not,
    howl_sroiq_SConcept_sc_and,
    howl_sroiq_SConcept_sc_or,
    howl_sroiq_SConcept_sc_some,
    howl_sroiq_SConcept_sc_all,
    howl_sroiq_SConcept_sc_atleast,
    howl_sroiq_SConcept_sc_atmost,
    howl_sroiq_SConcept_sc_self,
    howl_sroiq_SConcept_sc_elim
} howl_sroiq_SConcept_tag;

struct howl_sroiq_SConcept {
    howl_sroiq_SConcept_tag tag;
    union {
        slop_rdf_rdf_IRI sc_name;
        slop_rdf_rdf_IRI sc_nominal;
        howl_sroiq_SConcept* sc_not;
        slop_list_howl_sroiq_SConcept sc_and;
        slop_list_howl_sroiq_SConcept sc_or;
        struct {
            howl_types_RoleId f0;
            howl_sroiq_SConcept* f1;
        } sc_some;
        struct {
            howl_types_RoleId f0;
            howl_sroiq_SConcept* f1;
        } sc_all;
        struct {
            int64_t f0;
            howl_types_RoleId f1;
            howl_sroiq_SConcept* f2;
        } sc_atleast;
        struct {
            int64_t f0;
            howl_types_RoleId f1;
            howl_sroiq_SConcept* f2;
        } sc_atmost;
        howl_types_RoleId sc_self;
        struct {
            howl_sroiq_ElimKind f0;
            howl_types_RoleId f1;
            howl_sroiq_SConcept* f2;
        } sc_elim;
    } data;
};
typedef struct howl_sroiq_SConcept howl_sroiq_SConcept;

#ifndef SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SConcept, slop_option_howl_sroiq_SConcept)
#endif

#ifndef SLOP_LIST_HOWL_SROIQ_SCONCEPT_IMPL_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SCONCEPT_IMPL_DEFINED
SLOP_LIST_IMPL(howl_sroiq_SConcept, slop_list_howl_sroiq_SConcept)
#endif

howl_sroiq_SConcept* howl_sroiq_box_sc(slop_arena* arena, howl_sroiq_SConcept c);
howl_types_RoleId howl_sroiq_inv_role(howl_types_RoleId r);
uint8_t howl_sroiq_sc_top_p(howl_sroiq_SConcept c);
int64_t howl_sroiq_sc_rank(howl_sroiq_SConcept c);
int64_t howl_sroiq_elim_rank(howl_sroiq_ElimKind k);
howl_sroiq_SConcept howl_sroiq_sc_at(slop_list_howl_sroiq_SConcept xs, int64_t i);
int64_t howl_sroiq_sc_list_cmp(slop_list_howl_sroiq_SConcept a, slop_list_howl_sroiq_SConcept b);
int64_t howl_sroiq_int_cmp(int64_t a, int64_t b);
int64_t howl_sroiq_role_then(howl_types_RoleId ra, howl_types_RoleId rb, howl_sroiq_SConcept fa, howl_sroiq_SConcept fb);
int64_t howl_sroiq_sc_cmp(howl_sroiq_SConcept a, howl_sroiq_SConcept b);
int64_t howl_sroiq_role_list_cmp(slop_list_howl_types_RoleId a, slop_list_howl_types_RoleId b);
int64_t howl_sroiq_sa_rank(howl_sroiq_SAxiom a);
int64_t howl_sroiq_sa_cmp(howl_sroiq_SAxiom a, howl_sroiq_SAxiom b);
slop_list_howl_sroiq_SConcept howl_sroiq_sort_sconcepts(slop_arena* arena, slop_list_howl_sroiq_SConcept xs);
howl_sroiq_SConcept howl_sroiq_sc_canon(slop_arena* arena, howl_sroiq_SConcept c);
howl_sroiq_SConcept howl_sroiq_canon_junction(slop_arena* arena, slop_list_howl_sroiq_SConcept xs, uint8_t conj);
howl_sroiq_SAxiom howl_sroiq_sa_at(slop_list_howl_sroiq_SAxiom xs, int64_t i);
slop_list_howl_sroiq_SAxiom howl_sroiq_sort_saxioms(slop_arena* arena, slop_list_howl_sroiq_SAxiom xs);
slop_list_howl_sroiq_SAxiom howl_sroiq_dedupe_saxioms(slop_arena* arena, slop_list_howl_sroiq_SAxiom xs);
slop_string howl_sroiq_role_key_s(slop_arena* arena, howl_types_RoleId r);
slop_string howl_sroiq_sc_keys(slop_arena* arena, slop_list_howl_sroiq_SConcept xs);
slop_string howl_sroiq_sc_key_r(slop_arena* arena, slop_string head, howl_types_RoleId r, howl_sroiq_SConcept f);
slop_string howl_sroiq_sc_key(slop_arena* arena, howl_sroiq_SConcept c);
slop_string howl_sroiq_elim_tag(howl_sroiq_ElimKind k);
slop_string howl_sroiq_elim_head(howl_sroiq_ElimKind k);
slop_string howl_sroiq_render_srole(slop_arena* arena, howl_types_RoleId r);
slop_string howl_sroiq_render_sconcepts(slop_arena* arena, slop_list_howl_sroiq_SConcept xs, slop_string sep);
slop_string howl_sroiq_render_restriction(slop_arena* arena, slop_string head, howl_types_RoleId r, howl_sroiq_SConcept f);
slop_string howl_sroiq_render_sconcept(slop_arena* arena, howl_sroiq_SConcept c);
slop_string howl_sroiq_render_word(slop_arena* arena, slop_list_howl_types_RoleId w);
slop_string howl_sroiq_render_saxiom(slop_arena* arena, howl_sroiq_SAxiom a);

#ifndef SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SConcept, slop_option_howl_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SRIA_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SRIA_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SRia, slop_option_howl_sroiq_SRia)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SAxiom, slop_option_howl_sroiq_SAxiom)
#endif

#ifndef SLOP_LIST_HOWL_SROIQ_SCONCEPT_IMPL_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SCONCEPT_IMPL_DEFINED
SLOP_LIST_IMPL(howl_sroiq_SConcept, slop_list_howl_sroiq_SConcept)
#endif


#endif
