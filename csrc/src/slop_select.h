#ifndef SLOP_select_H
#define SLOP_select_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"

#ifndef SLOP_OPTION_TYPES_PROFILE_DEFINED
#define SLOP_OPTION_TYPES_PROFILE_DEFINED
SLOP_OPTION_DEFINE(types_Profile, slop_option_types_Profile)
#endif

slop_option_types_Profile select_select_profile(types_ProfileSelection selection);
types_Profile select_choose_auto(int64_t out_of_el, int64_t out_of_el_plus_plus);
uint8_t select_profile_implemented(types_Profile p);
slop_string select_profile_name(types_Profile p);
slop_option_types_Profile select_parse_profile(slop_string s);

#ifndef SLOP_OPTION_TYPES_PROFILE_DEFINED
#define SLOP_OPTION_TYPES_PROFILE_DEFINED
SLOP_OPTION_DEFINE(types_Profile, slop_option_types_Profile)
#endif


#endif
