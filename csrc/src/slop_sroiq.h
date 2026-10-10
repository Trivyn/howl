#ifndef SLOP_sroiq_H
#define SLOP_sroiq_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"
#include "slop_canon.h"

typedef struct sroiq_SConcept sroiq_SConcept;
typedef struct sroiq_SRia sroiq_SRia;
typedef struct sroiq_SAxiom sroiq_SAxiom;

typedef enum {
    sroiq_ElimKind_ek_i_all,
    sroiq_ElimKind_ek_f_all,
    sroiq_ElimKind_ek_i_some,
    sroiq_ElimKind_ek_f_some
} sroiq_ElimKind;

#ifndef SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(types_RoleId, slop_list_types_RoleId)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

struct sroiq_SRia {
    slop_list_types_RoleId word;
    types_RoleId super;
};
typedef struct sroiq_SRia sroiq_SRia;

#ifndef SLOP_OPTION_SROIQ_SRIA_DEFINED
#define SLOP_OPTION_SROIQ_SRIA_DEFINED
SLOP_OPTION_DEFINE(sroiq_SRia, slop_option_sroiq_SRia)
#endif

typedef enum {
    sroiq_SAxiom_sa_gci,
    sroiq_SAxiom_sa_ria,
    sroiq_SAxiom_sa_ref,
    sroiq_SAxiom_sa_irr,
    sroiq_SAxiom_sa_dis
} sroiq_SAxiom_tag;

struct sroiq_SAxiom {
    sroiq_SAxiom_tag tag;
    union {
        struct {
            sroiq_SConcept* f0;
            sroiq_SConcept* f1;
        } sa_gci;
        sroiq_SRia sa_ria;
        types_RoleId sa_ref;
        types_RoleId sa_irr;
        struct {
            types_RoleId f0;
            types_RoleId f1;
        } sa_dis;
    } data;
};
typedef struct sroiq_SAxiom sroiq_SAxiom;

#ifndef SLOP_OPTION_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(sroiq_SAxiom, slop_option_sroiq_SAxiom)
#endif

#ifndef SLOP_LIST_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_SROIQ_SAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(sroiq_SAxiom, slop_list_sroiq_SAxiom)
#endif

#ifndef SLOP_LIST_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_SROIQ_SCONCEPT_DEFINED
SLOP_LIST_DECLARE(sroiq_SConcept, slop_list_sroiq_SConcept)
#endif

typedef enum {
    sroiq_SConcept_sc_top,
    sroiq_SConcept_sc_bottom,
    sroiq_SConcept_sc_name,
    sroiq_SConcept_sc_nominal,
    sroiq_SConcept_sc_not,
    sroiq_SConcept_sc_and,
    sroiq_SConcept_sc_or,
    sroiq_SConcept_sc_some,
    sroiq_SConcept_sc_all,
    sroiq_SConcept_sc_atleast,
    sroiq_SConcept_sc_atmost,
    sroiq_SConcept_sc_self,
    sroiq_SConcept_sc_elim
} sroiq_SConcept_tag;

struct sroiq_SConcept {
    sroiq_SConcept_tag tag;
    union {
        rdf_IRI sc_name;
        rdf_IRI sc_nominal;
        sroiq_SConcept* sc_not;
        slop_list_sroiq_SConcept sc_and;
        slop_list_sroiq_SConcept sc_or;
        struct {
            types_RoleId f0;
            sroiq_SConcept* f1;
        } sc_some;
        struct {
            types_RoleId f0;
            sroiq_SConcept* f1;
        } sc_all;
        struct {
            int64_t f0;
            types_RoleId f1;
            sroiq_SConcept* f2;
        } sc_atleast;
        struct {
            int64_t f0;
            types_RoleId f1;
            sroiq_SConcept* f2;
        } sc_atmost;
        types_RoleId sc_self;
        struct {
            sroiq_ElimKind f0;
            types_RoleId f1;
            sroiq_SConcept* f2;
        } sc_elim;
    } data;
};
typedef struct sroiq_SConcept sroiq_SConcept;

#ifndef SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(sroiq_SConcept, slop_option_sroiq_SConcept)
#endif

#ifndef SLOP_LIST_SROIQ_SCONCEPT_IMPL_DEFINED
#define SLOP_LIST_SROIQ_SCONCEPT_IMPL_DEFINED
SLOP_LIST_IMPL(sroiq_SConcept, slop_list_sroiq_SConcept)
#endif

sroiq_SConcept* sroiq_box_sc(slop_arena* arena, sroiq_SConcept c);
types_RoleId sroiq_inv_role(types_RoleId r);
uint8_t sroiq_sc_top_p(sroiq_SConcept c);
int64_t sroiq_sc_rank(sroiq_SConcept c);
int64_t sroiq_elim_rank(sroiq_ElimKind k);
sroiq_SConcept sroiq_sc_at(slop_list_sroiq_SConcept xs, int64_t i);
int64_t sroiq_sc_list_cmp(slop_list_sroiq_SConcept a, slop_list_sroiq_SConcept b);
int64_t sroiq_int_cmp(int64_t a, int64_t b);
int64_t sroiq_role_then(types_RoleId ra, types_RoleId rb, sroiq_SConcept fa, sroiq_SConcept fb);
int64_t sroiq_sc_cmp(sroiq_SConcept a, sroiq_SConcept b);
int64_t sroiq_role_list_cmp(slop_list_types_RoleId a, slop_list_types_RoleId b);
int64_t sroiq_sa_rank(sroiq_SAxiom a);
int64_t sroiq_sa_cmp(sroiq_SAxiom a, sroiq_SAxiom b);
slop_list_sroiq_SConcept sroiq_sort_sconcepts(slop_arena* arena, slop_list_sroiq_SConcept xs);
sroiq_SConcept sroiq_sc_canon(slop_arena* arena, sroiq_SConcept c);
sroiq_SConcept sroiq_canon_junction(slop_arena* arena, slop_list_sroiq_SConcept xs, uint8_t conj);
sroiq_SAxiom sroiq_sa_at(slop_list_sroiq_SAxiom xs, int64_t i);
slop_list_sroiq_SAxiom sroiq_sort_saxioms(slop_arena* arena, slop_list_sroiq_SAxiom xs);
slop_list_sroiq_SAxiom sroiq_dedupe_saxioms(slop_arena* arena, slop_list_sroiq_SAxiom xs);
slop_string sroiq_role_key_s(slop_arena* arena, types_RoleId r);
slop_string sroiq_sc_keys(slop_arena* arena, slop_list_sroiq_SConcept xs);
slop_string sroiq_sc_key_r(slop_arena* arena, slop_string head, types_RoleId r, sroiq_SConcept f);
slop_string sroiq_sc_key(slop_arena* arena, sroiq_SConcept c);
slop_string sroiq_elim_tag(sroiq_ElimKind k);
slop_string sroiq_elim_head(sroiq_ElimKind k);
slop_string sroiq_render_srole(slop_arena* arena, types_RoleId r);
slop_string sroiq_render_sconcepts(slop_arena* arena, slop_list_sroiq_SConcept xs, slop_string sep);
slop_string sroiq_render_restriction(slop_arena* arena, slop_string head, types_RoleId r, sroiq_SConcept f);
slop_string sroiq_render_sconcept(slop_arena* arena, sroiq_SConcept c);
slop_string sroiq_render_word(slop_arena* arena, slop_list_types_RoleId w);
slop_string sroiq_render_saxiom(slop_arena* arena, sroiq_SAxiom a);

#ifndef SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(sroiq_SConcept, slop_option_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

#ifndef SLOP_OPTION_SROIQ_SRIA_DEFINED
#define SLOP_OPTION_SROIQ_SRIA_DEFINED
SLOP_OPTION_DEFINE(sroiq_SRia, slop_option_sroiq_SRia)
#endif

#ifndef SLOP_OPTION_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(sroiq_SAxiom, slop_option_sroiq_SAxiom)
#endif

#ifndef SLOP_LIST_SROIQ_SCONCEPT_IMPL_DEFINED
#define SLOP_LIST_SROIQ_SCONCEPT_IMPL_DEFINED
SLOP_LIST_IMPL(sroiq_SConcept, slop_list_sroiq_SConcept)
#endif


#endif
