#ifndef SLOP_el_H
#define SLOP_el_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"

#ifndef SLOP_LIST_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_TYPES_NORMAXIOM_DEFINED
SLOP_LIST_DEFINE(types_NormAxiom, slop_list_types_NormAxiom)
#endif

#ifndef SLOP_LIST_TYPES_ADDRESSED_DEFINED
#define SLOP_LIST_TYPES_ADDRESSED_DEFINED
SLOP_LIST_DEFINE(types_Addressed, slop_list_types_Addressed)
#endif

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(types_Addressed, slop_option_types_Addressed)
#endif

slop_list_types_Addressed el_apply_el_rules(slop_arena* arena, types_Context ctx, types_Derived incoming, slop_list_types_NormAxiom axioms);

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(types_Addressed, slop_option_types_Addressed)
#endif


#endif
