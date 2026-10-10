#include "../runtime/slop_runtime.h"
#include "slop_select.h"

slop_option_types_Profile select_select_profile(types_ProfileSelection selection);
types_Profile select_choose_auto(int64_t out_of_el, int64_t out_of_el_plus_plus);
uint8_t select_profile_implemented(types_Profile p);
uint8_t select_profile_dropped(types_Profile p);
slop_string select_unavailable_message(slop_arena* arena, types_Profile p);
slop_string select_profile_name(types_Profile p);
slop_option_types_Profile select_parse_profile(slop_string s);

slop_option_types_Profile select_select_profile(types_ProfileSelection selection) {
    slop_option_types_Profile _retval = {0};
    __auto_type _mv_899 = selection;
    switch (_mv_899.tag) {
        case types_ProfileSelection_slop_auto:
        {
            _retval = (slop_option_types_Profile){.has_value = false};
            goto _slop_post;
        }
        case types_ProfileSelection_explicit:
        {
            __auto_type p = _mv_899.data.explicit;
            _retval = (slop_option_types_Profile){.has_value = 1, .value = p};
            goto _slop_post;
        }
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST((({ __auto_type _mv = selection; uint8_t _mr = {0}; int _mm = 0; switch (_mv.tag) { case types_ProfileSelection_slop_auto: { _mr = ({ __auto_type _mv = _retval; _mv.has_value ? ({ __auto_type _ = _mv.value; 0; }) : (1); }); _mm = 1; break; } case types_ProfileSelection_explicit: { __auto_type p = _mv.data.explicit; _mr = ({ __auto_type _mv = _retval; _mv.has_value ? ({ __auto_type q = _mv.value; (q == p); }) : (0); }); _mm = 1; break; }  } if (!_mm) { SLOP_UNREACHABLE(); } _mr; })), "(match selection ((auto) (match $result ((none) true) ((some _) false))) ((explicit p) (match $result ((some q) (== q p)) ((none) false))))");
    return _retval;
}

types_Profile select_choose_auto(int64_t out_of_el, int64_t out_of_el_plus_plus) {
    types_Profile _retval = {0};
    if (out_of_el_plus_plus < out_of_el) {
        _retval = types_Profile_profile_el_plus_plus;
        goto _slop_post;
    } else {
        _retval = types_Profile_profile_el;
        goto _slop_post;
    }
    _slop_post: ;
    return _retval;
}

uint8_t select_profile_implemented(types_Profile p) {
    uint8_t _retval = {0};
    __auto_type _mv_900 = p;
    if (_mv_900 == types_Profile_profile_el) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_900 == types_Profile_profile_el_plus_plus) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_900 == types_Profile_profile_horn_sriq) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_900 == types_Profile_profile_sriq) {
        _retval = 0;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST(((_retval == (p(==, types_Profile_profile_el) || p(==, types_Profile_profile_el_plus_plus)))), "(== $result (or (p == (quote profile-el)) (p == (quote profile-el-plus-plus))))");
    return _retval;
}

uint8_t select_profile_dropped(types_Profile p) {
    uint8_t _retval = {0};
    __auto_type _mv_901 = p;
    if (_mv_901 == types_Profile_profile_el) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_901 == types_Profile_profile_el_plus_plus) {
        _retval = 0;
        goto _slop_post;
    } else if (_mv_901 == types_Profile_profile_horn_sriq) {
        _retval = 1;
        goto _slop_post;
    } else if (_mv_901 == types_Profile_profile_sriq) {
        _retval = 0;
        goto _slop_post;
    }
    SLOP_UNREACHABLE();
    _slop_post: ;
    SLOP_POST(((_retval == (p == types_Profile_profile_horn_sriq))), "(== $result (== p (quote profile-horn-sriq)))");
    return _retval;
}

slop_string select_unavailable_message(slop_arena* arena, types_Profile p) {
    {
        __auto_type named = string_concat(arena, SLOP_STR("profile "), select_profile_name(p));
        if (select_profile_dropped(p)) {
            return string_concat(arena, named, SLOP_STR(" was dropped; sriq covers its language"));
        } else {
            return string_concat(arena, named, SLOP_STR(" is not implemented yet (implemented: el, el++)"));
        }
    }
}

slop_string select_profile_name(types_Profile p) {
    __auto_type _mv_902 = p;
    if (_mv_902 == types_Profile_profile_el) {
        return SLOP_STR("el");
    } else if (_mv_902 == types_Profile_profile_el_plus_plus) {
        return SLOP_STR("el++");
    } else if (_mv_902 == types_Profile_profile_horn_sriq) {
        return SLOP_STR("horn-sriq");
    } else if (_mv_902 == types_Profile_profile_sriq) {
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

