#ifndef SLOP_kscnames_H
#define SLOP_kscnames_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"

typedef struct kscnames_KscNames kscnames_KscNames;

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_LIST_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_TYPES_KSCAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KscAxiom, slop_list_types_KscAxiom)
#endif

#ifndef SLOP_LIST_TYPES_KNAME_DEFINED
#define SLOP_LIST_TYPES_KNAME_DEFINED
#define SLOP_LIST_TYPES_KNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KName, slop_list_types_KName)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_KNAME_DEFINED
#define SLOP_OPTION_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(types_KName, slop_option_types_KName)
#endif

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

struct kscnames_KscNames {
    slop_map* classes;
    slop_map* roles;
    slop_map* back;
    int64_t class_base;
    int64_t role_base;
};
typedef struct kscnames_KscNames kscnames_KscNames;

#ifndef SLOP_OPTION_KSCNAMES_KSCNAMES_DEFINED
#define SLOP_OPTION_KSCNAMES_KSCNAMES_DEFINED
SLOP_OPTION_DEFINE(kscnames_KscNames, slop_option_kscnames_KscNames)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef RDF_IRI_HASH_EQ_DEFINED
#define RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_rdf_IRI(const void* key) {
    const rdf_IRI* _k = (const rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_rdf_IRI(const void* a, const void* b) {
    const rdf_IRI* _a = (const rdf_IRI*)a;
    const rdf_IRI* _b = (const rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif

uint8_t kscnames_kept_as_iri(rdf_IRI i);
int64_t kscnames_max_fresh_name(types_KName k, int64_t m);
int64_t kscnames_max_fresh_term(types_KTerm t, int64_t m);
int64_t kscnames_max_fresh_role(types_RoleId r, int64_t m);
uint8_t kscnames_note_class(slop_arena* arena, kscnames_KscNames nm, types_KName k);
uint8_t kscnames_note_role(slop_arena* arena, kscnames_KscNames nm, types_RoleId r);
uint8_t kscnames_note_term(slop_arena* arena, kscnames_KscNames nm, types_KTerm t);
kscnames_KscNames kscnames_build_ksc_names(slop_arena* arena, slop_list_types_KscAxiom axioms, slop_list_types_KName classes);
types_KName kscnames_rename_class(kscnames_KscNames nm, types_KName k);
types_KTerm kscnames_rename_term(kscnames_KscNames nm, types_KTerm t);
types_RoleId kscnames_rename_role(kscnames_KscNames nm, types_RoleId r);
types_KscAxiom kscnames_rename_axiom(kscnames_KscNames nm, types_KscAxiom ax);
slop_list_types_KscAxiom kscnames_rename_ksc_axioms(slop_arena* arena, kscnames_KscNames nm, slop_list_types_KscAxiom axioms);
slop_list_types_KName kscnames_rename_classes(slop_arena* arena, kscnames_KscNames nm, slop_list_types_KName classes);
types_KName kscnames_unrename_class(kscnames_KscNames nm, types_KName k);
types_ClassAnswer kscnames_unrename_answer(slop_arena* arena, kscnames_KscNames nm, types_ClassAnswer a);

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_KNAME_DEFINED
#define SLOP_OPTION_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(types_KName, slop_option_types_KName)
#endif

#ifndef SLOP_OPTION_KSCNAMES_KSCNAMES_DEFINED
#define SLOP_OPTION_KSCNAMES_KSCNAMES_DEFINED
SLOP_OPTION_DEFINE(kscnames_KscNames, slop_option_kscnames_KscNames)
#endif

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif


#endif
