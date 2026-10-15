#ifndef SLOP_naming_H
#define SLOP_naming_H

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
#include "slop_owl2.h"

typedef struct howl_naming_Registry howl_naming_Registry;

#ifndef SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawConcept, slop_list_howl_owl2_RawConcept)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Node, slop_list_howl_types_Node)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_RoleId, slop_list_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

struct howl_naming_Registry {
    slop_list_string fresh;
    slop_map* fresh_index;
    slop_list_string fresh_roles;
    slop_map* fresh_role_index;
    slop_map* neg_done;
    slop_map* pos_done;
};
typedef struct howl_naming_Registry howl_naming_Registry;

#ifndef SLOP_OPTION_HOWL_NAMING_REGISTRY_DEFINED
#define SLOP_OPTION_HOWL_NAMING_REGISTRY_DEFINED
SLOP_OPTION_DEFINE(howl_naming_Registry, slop_option_howl_naming_Registry)
#endif

howl_naming_Registry* howl_naming_new_registry(slop_arena* arena);
int64_t howl_naming_fresh_id(slop_arena* arena, howl_naming_Registry* p, slop_string text);
int64_t howl_naming_fresh_role_id(slop_arena* arena, howl_naming_Registry* p, slop_string text);
uint8_t howl_naming_mark_neg(slop_arena* arena, howl_naming_Registry* p, slop_string text);
uint8_t howl_naming_mark_pos(slop_arena* arena, howl_naming_Registry* p, slop_string text);
uint8_t howl_naming_neg_defined(howl_naming_Registry* p, slop_string text);
uint8_t howl_naming_pos_defined(howl_naming_Registry* p, slop_string text);
int64_t howl_naming_fresh_count(howl_naming_Registry* p);
int64_t howl_naming_fresh_role_count(howl_naming_Registry* p);
slop_list_howl_owl2_RawConcept howl_naming_flatten_and(slop_arena* arena, howl_owl2_RawConcept c, slop_list_howl_owl2_RawConcept acc);
slop_string howl_naming_concept_key(slop_arena* arena, howl_owl2_RawConcept c);
howl_types_Node howl_naming_node_at(slop_list_howl_types_Node xs, int64_t i);
slop_string howl_naming_node_key(slop_arena* arena, howl_types_Node n);
slop_string howl_naming_role_key(slop_arena* arena, howl_types_RoleId r);
slop_string howl_naming_prefix_text(slop_arena* arena, slop_list_howl_owl2_RawConcept conj, int64_t upto);
howl_types_RoleId howl_naming_role_at_n(slop_list_howl_types_RoleId xs, int64_t i);
slop_string howl_naming_prefix_role_text(slop_arena* arena, slop_list_howl_types_RoleId steps, int64_t upto, howl_types_RoleId super);
slop_string howl_naming_render_role_name(slop_arena* arena, howl_types_RoleId r);

#ifndef SLOP_OPTION_HOWL_NAMING_REGISTRY_DEFINED
#define SLOP_OPTION_HOWL_NAMING_REGISTRY_DEFINED
SLOP_OPTION_DEFINE(howl_naming_Registry, slop_option_howl_naming_Registry)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif


#endif
