#ifndef SLOP_kscnames_H
#define SLOP_kscnames_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"

typedef struct howl_kscnames_KscNames howl_kscnames_KscNames;

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KSCAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KscAxiom, slop_list_howl_types_KscAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_KNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_KNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_KNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KName, slop_list_howl_types_KName)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_KName, slop_option_howl_types_KName)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscAxiom, slop_option_howl_types_KscAxiom)
#endif

struct howl_kscnames_KscNames {
    slop_map* classes;
    slop_map* roles;
    slop_map* back;
    int64_t class_base;
    int64_t role_base;
};
typedef struct howl_kscnames_KscNames howl_kscnames_KscNames;

#ifndef SLOP_OPTION_HOWL_KSCNAMES_KSCNAMES_DEFINED
#define SLOP_OPTION_HOWL_KSCNAMES_KSCNAMES_DEFINED
SLOP_OPTION_DEFINE(howl_kscnames_KscNames, slop_option_howl_kscnames_KscNames)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif

uint8_t howl_kscnames_kept_as_iri(slop_rdf_rdf_IRI i);
int64_t howl_kscnames_max_fresh_name(howl_types_KName k, int64_t m);
int64_t howl_kscnames_max_fresh_term(howl_types_KTerm t, int64_t m);
int64_t howl_kscnames_max_fresh_role(howl_types_RoleId r, int64_t m);
uint8_t howl_kscnames_note_class(slop_arena* arena, howl_kscnames_KscNames nm, howl_types_KName k);
uint8_t howl_kscnames_note_role(slop_arena* arena, howl_kscnames_KscNames nm, howl_types_RoleId r);
uint8_t howl_kscnames_note_term(slop_arena* arena, howl_kscnames_KscNames nm, howl_types_KTerm t);
howl_kscnames_KscNames howl_kscnames_build_ksc_names(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes);
howl_types_KName howl_kscnames_rename_class(howl_kscnames_KscNames nm, howl_types_KName k);
howl_types_KTerm howl_kscnames_rename_term(howl_kscnames_KscNames nm, howl_types_KTerm t);
howl_types_RoleId howl_kscnames_rename_role(howl_kscnames_KscNames nm, howl_types_RoleId r);
howl_types_KscAxiom howl_kscnames_rename_axiom(howl_kscnames_KscNames nm, howl_types_KscAxiom ax);
slop_list_howl_types_KscAxiom howl_kscnames_rename_ksc_axioms(slop_arena* arena, howl_kscnames_KscNames nm, slop_list_howl_types_KscAxiom axioms);
slop_list_howl_types_KName howl_kscnames_rename_classes(slop_arena* arena, howl_kscnames_KscNames nm, slop_list_howl_types_KName classes);
howl_types_KName howl_kscnames_unrename_class(howl_kscnames_KscNames nm, howl_types_KName k);
howl_types_ClassAnswer howl_kscnames_unrename_answer(slop_arena* arena, howl_kscnames_KscNames nm, howl_types_ClassAnswer a);

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_KName, slop_option_howl_types_KName)
#endif

#ifndef SLOP_OPTION_HOWL_KSCNAMES_KSCNAMES_DEFINED
#define SLOP_OPTION_HOWL_KSCNAMES_KSCNAMES_DEFINED
SLOP_OPTION_DEFINE(howl_kscnames_KscNames, slop_option_howl_kscnames_KscNames)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscAxiom, slop_option_howl_types_KscAxiom)
#endif


#endif
