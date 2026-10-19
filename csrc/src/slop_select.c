#include "../runtime/slop_runtime.h"
#include "slop_select.h"

slop_option_howl_types_Profile howl_select_select_profile(howl_types_ProfileSelection selection);
howl_types_Profile howl_select_choose_auto(int64_t out_of_el, int64_t out_of_el_plus_plus, int64_t out_of_sriq);
howl_types_Profile howl_select_choose_auto_low(int64_t out_of_el, int64_t out_of_el_plus_plus);
uint8_t howl_select_profile_implemented(howl_types_Profile p);
uint8_t howl_select_profile_dropped(howl_types_Profile p);
slop_string howl_select_unavailable_message(slop_arena* arena, howl_types_Profile p);
slop_string howl_select_profile_name(howl_types_Profile p);
slop_option_howl_types_Profile howl_select_parse_profile(slop_string s);

slop_option_howl_types_Profile howl_select_select_profile(howl_types_ProfileSelection selection) {
    slop_option_howl_types_Profile _retval = {0};
    __auto_type _mv_1462 = selection;
    switch (_mv_1462.tag) {
        case howl_types_ProfileSelection_slop_auto:
        {
            _retval = (slop_option_howl_types_Profile){.has_value = false};
            goto _slop_post;
        }
        case howl_types_ProfileSelection_explicit:
        {
            __auto_type p = _mv_1462.data.explicit;
            _retval = (slop_option_howl_types_Profile){.has_value = 1, .value = p};
            goto _slop_post;
        }
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST((({ __auto_type _mv = selection; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case howl_types_ProfileSelection_slop_auto: { _mr = ({ __auto_type _mv = _retval; _mv.has_value ? ({ __auto_type _ = _mv.value; 0; }) : (1); }); _mm = 1; break; } case howl_types_ProfileSelection_explicit: { __auto_type p = _mv.data.explicit; _mr = ({ __auto_type _mv = _retval; _mv.has_value ? ({ __auto_type q = _mv.value; (q == p); }) : (0); }); _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; })), "(match selection ((auto) (match $result ((none) true) ((some _) false))) ((explicit p) (match $result ((some q) (== q p)) ((none) false))))");
    return _retval;
}

howl_types_Profile howl_select_choose_auto(int64_t out_of_el, int64_t out_of_el_plus_plus, int64_t out_of_sriq) {
    howl_types_Profile _retval = {0};
    if ((out_of_el <= out_of_el_plus_plus) && (out_of_el <= out_of_sriq)) {
        _retval = howl_types_Profile_profile_el;
        goto _slop_post;
    } else if (out_of_el_plus_plus <= out_of_sriq) {
        _retval = howl_types_Profile_profile_el_plus_plus;
        goto _slop_post;
    } else {
        _retval = howl_types_Profile_profile_sriq;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

howl_types_Profile howl_select_choose_auto_low(int64_t out_of_el, int64_t out_of_el_plus_plus) {
    howl_types_Profile _retval = {0};
    if (out_of_el_plus_plus < out_of_el) {
        _retval = howl_types_Profile_profile_el_plus_plus;
        goto _slop_post;
    } else {
        _retval = howl_types_Profile_profile_el;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

uint8_t howl_select_profile_implemented(howl_types_Profile p) {
    uint8_t _retval = {0};
    __auto_type _mv_1463 = p;
    if (_mv_1463 == howl_types_Profile_profile_el) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_1463 == howl_types_Profile_profile_el_plus_plus) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_1463 == howl_types_Profile_profile_horn_sriq) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_1463 == howl_types_Profile_profile_sriq) {
        _retval = 1;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST(((_retval == ((p(==, howl_types_Profile_profile_el)) || (p(==, howl_types_Profile_profile_el_plus_plus)) || (p(==, howl_types_Profile_profile_sriq))))), "(== $result (or (p == (quote profile-el)) (p == (quote profile-el-plus-plus)) (p == (quote profile-sriq))))");
    return _retval;
}

uint8_t howl_select_profile_dropped(howl_types_Profile p) {
    uint8_t _retval = {0};
    __auto_type _mv_1464 = p;
    if (_mv_1464 == howl_types_Profile_profile_el) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_1464 == howl_types_Profile_profile_el_plus_plus) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_1464 == howl_types_Profile_profile_horn_sriq) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_1464 == howl_types_Profile_profile_sriq) {
        _retval = 0;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST(((_retval == (p == howl_types_Profile_profile_horn_sriq))), "(== $result (== p (quote profile-horn-sriq)))");
    return _retval;
}

slop_string howl_select_unavailable_message(slop_arena* arena, howl_types_Profile p) {
    {
        __auto_type named = string_concat(arena, SLOP_STR("profile "), howl_select_profile_name(p));
        if (howl_select_profile_dropped(p)) {
            return string_concat(arena, named, SLOP_STR(" was dropped; sriq covers its language"));
        } else {
            return string_concat(arena, named, SLOP_STR(" is not implemented yet (implemented: el, el++, sriq)"));
        }
    }
}

slop_string howl_select_profile_name(howl_types_Profile p) {
    __auto_type _mv_1465 = p;
    if (_mv_1465 == howl_types_Profile_profile_el) {
        return SLOP_STR("el");
    } else if (_mv_1465 == howl_types_Profile_profile_el_plus_plus) {
        return SLOP_STR("el++");
    } else if (_mv_1465 == howl_types_Profile_profile_horn_sriq) {
        return SLOP_STR("horn-sriq");
    } else if (_mv_1465 == howl_types_Profile_profile_sriq) {
        return SLOP_STR("sriq");
    }
    SLOP_UNREACHABLE();
}

slop_option_howl_types_Profile howl_select_parse_profile(slop_string s) {
    if (string_eq(s, SLOP_STR("el"))) {
        return (slop_option_howl_types_Profile){.has_value = 1, .value = howl_types_Profile_profile_el};
    } else if (string_eq(s, SLOP_STR("el++"))) {
        return (slop_option_howl_types_Profile){.has_value = 1, .value = howl_types_Profile_profile_el_plus_plus};
    } else if (string_eq(s, SLOP_STR("horn-sriq"))) {
        return (slop_option_howl_types_Profile){.has_value = 1, .value = howl_types_Profile_profile_horn_sriq};
    } else if (string_eq(s, SLOP_STR("sriq"))) {
        return (slop_option_howl_types_Profile){.has_value = 1, .value = howl_types_Profile_profile_sriq};
    } else {
        return (slop_option_howl_types_Profile){.has_value = false};
    }
}

