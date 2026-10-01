#include "../runtime/slop_runtime.h"
#include "slop_select.h"

types_Profile select_select_profile(types_ProfileSelection selection);
uint8_t select_profile_implemented(types_Profile p);
slop_string select_profile_name(types_Profile p);
slop_option_types_Profile select_parse_profile(slop_string s);

types_Profile select_select_profile(types_ProfileSelection selection) {
    types_Profile _retval = {0};
    __auto_type _mv_597 = selection;
    switch (_mv_597.tag) {
        case types_ProfileSelection_slop_auto:
        {
            return types_Profile_profile_el;
        }
        case types_ProfileSelection_explicit:
        {
            __auto_type p = _mv_597.data.explicit;
            return p;
        }
    }
    SLOP_UNREACHABLE();
    SLOP_POST((({ __auto_type _mv = selection; uint8_t _mr = {0}; switch (_mv.tag) { case types_ProfileSelection_slop_auto: { _mr = (_retval == types_Profile_profile_el); break; } case types_ProfileSelection_explicit: { __auto_type p = _mv.data.explicit; _mr = (_retval == p); break; }  } _mr; })), "(match selection ((auto) (== $result (quote profile-el))) ((explicit p) (== $result p)))");
    return _retval;
}

uint8_t select_profile_implemented(types_Profile p) {
    uint8_t _retval = {0};
    __auto_type _mv_598 = p;
    if (_mv_598 == types_Profile_profile_el) {
        return 1;
    } else if (_mv_598 == types_Profile_profile_el_plus_plus) {
        return 0;
    } else if (_mv_598 == types_Profile_profile_horn_sriq) {
        return 0;
    } else if (_mv_598 == types_Profile_profile_sriq) {
        return 0;
    }
    SLOP_UNREACHABLE();
    SLOP_POST(((_retval == (p == types_Profile_profile_el))), "(== $result (== p (quote profile-el)))");
    return _retval;
}

slop_string select_profile_name(types_Profile p) {
    __auto_type _mv_599 = p;
    if (_mv_599 == types_Profile_profile_el) {
        return SLOP_STR("el");
    } else if (_mv_599 == types_Profile_profile_el_plus_plus) {
        return SLOP_STR("el++");
    } else if (_mv_599 == types_Profile_profile_horn_sriq) {
        return SLOP_STR("horn-sriq");
    } else if (_mv_599 == types_Profile_profile_sriq) {
        return SLOP_STR("sriq");
    }
    SLOP_UNREACHABLE();
}

slop_option_types_Profile select_parse_profile(slop_string s) {
    if (string_eq(s, SLOP_STR("el"))) {
        return (slop_option_types_Profile){.has_value = 1, .value = types_Profile_profile_el};
    } else if (string_eq(s, SLOP_STR("el++"))) {
        return (slop_option_types_Profile){.has_value = 1, .value = types_Profile_profile_el_plus_plus};
    } else if (string_eq(s, SLOP_STR("horn-sriq"))) {
        return (slop_option_types_Profile){.has_value = 1, .value = types_Profile_profile_horn_sriq};
    } else if (string_eq(s, SLOP_STR("sriq"))) {
        return (slop_option_types_Profile){.has_value = 1, .value = types_Profile_profile_sriq};
    } else {
        return (slop_option_types_Profile){.has_value = false};
    }
}

