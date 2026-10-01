#ifndef SLOP_naming_H
#define SLOP_naming_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"
#include "slop_owl2.h"

typedef struct naming_Registry naming_Registry;

#ifndef SLOP_LIST_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(owl2_RawConcept, slop_list_owl2_RawConcept)
#endif

#ifndef SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_DEFINED
#define SLOP_LIST_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(types_RoleId, slop_list_types_RoleId)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif

struct naming_Registry {
    slop_list_string fresh;
    slop_map* fresh_index;
    slop_list_string fresh_roles;
    slop_map* fresh_role_index;
    slop_map* neg_done;
    slop_map* pos_done;
};
typedef struct naming_Registry naming_Registry;

#ifndef SLOP_OPTION_NAMING_REGISTRY_DEFINED
#define SLOP_OPTION_NAMING_REGISTRY_DEFINED
SLOP_OPTION_DEFINE(naming_Registry, slop_option_naming_Registry)
#endif

naming_Registry* naming_new_registry(slop_arena* arena);
int64_t naming_fresh_id(slop_arena* arena, naming_Registry* p, slop_string text);
int64_t naming_fresh_role_id(slop_arena* arena, naming_Registry* p, slop_string text);
uint8_t naming_mark_neg(slop_arena* arena, naming_Registry* p, slop_string text);
uint8_t naming_mark_pos(slop_arena* arena, naming_Registry* p, slop_string text);
uint8_t naming_neg_defined(naming_Registry* p, slop_string text);
uint8_t naming_pos_defined(naming_Registry* p, slop_string text);
int64_t naming_fresh_count(naming_Registry* p);
int64_t naming_fresh_role_count(naming_Registry* p);
slop_list_owl2_RawConcept naming_flatten_and(slop_arena* arena, owl2_RawConcept c, slop_list_owl2_RawConcept acc);
slop_string naming_concept_key(slop_arena* arena, owl2_RawConcept c);
slop_string naming_node_key(slop_arena* arena, types_Node n);
slop_string naming_role_key(slop_arena* arena, types_RoleId r);
slop_string naming_prefix_text(slop_arena* arena, slop_list_owl2_RawConcept conj, int64_t upto);
types_RoleId naming_role_at_n(slop_list_types_RoleId xs, int64_t i);
slop_string naming_prefix_role_text(slop_arena* arena, slop_list_types_RoleId steps, int64_t upto, types_RoleId super);
slop_string naming_render_role_name(types_RoleId r);

#ifndef SLOP_OPTION_NAMING_REGISTRY_DEFINED
#define SLOP_OPTION_NAMING_REGISTRY_DEFINED
SLOP_OPTION_DEFINE(naming_Registry, slop_option_naming_Registry)
#endif

#ifndef SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(owl2_RawConcept, slop_option_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(types_RoleId, slop_option_types_RoleId)
#endif


#endif
