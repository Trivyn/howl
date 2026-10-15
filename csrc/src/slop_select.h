#ifndef SLOP_select_H
#define SLOP_select_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_types.h"

#ifndef SLOP_OPTION_HOWL_TYPES_PROFILE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_PROFILE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Profile, slop_option_howl_types_Profile)
#endif

slop_option_howl_types_Profile howl_select_select_profile(howl_types_ProfileSelection selection);
howl_types_Profile howl_select_choose_auto(int64_t out_of_el, int64_t out_of_el_plus_plus, int64_t out_of_sriq);
howl_types_Profile howl_select_choose_auto_low(int64_t out_of_el, int64_t out_of_el_plus_plus);
uint8_t howl_select_profile_implemented(howl_types_Profile p);
uint8_t howl_select_profile_dropped(howl_types_Profile p);
slop_string howl_select_unavailable_message(slop_arena* arena, howl_types_Profile p);
slop_string howl_select_profile_name(howl_types_Profile p);
slop_option_howl_types_Profile howl_select_parse_profile(slop_string s);

#ifndef SLOP_OPTION_HOWL_TYPES_PROFILE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_PROFILE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Profile, slop_option_howl_types_Profile)
#endif


#endif
