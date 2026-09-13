#include "../runtime/slop_runtime.h"
#include "slop_select.h"

types_Profile select_select_profile(slop_arena* arena, types_ProfileSelection selection);

types_Profile select_select_profile(slop_arena* arena, types_ProfileSelection selection) {
    types_Profile _retval = {0};
    __auto_type _mv_412 = selection;
    switch (_mv_412.tag) {
        case types_ProfileSelection_slop_auto:
        {
            return types_Profile_profile_el;
        }
        case types_ProfileSelection_explicit:
        {
            __auto_type p = _mv_412.data.explicit;
            return p;
        }
    }
    SLOP_UNREACHABLE();
    SLOP_POST((({ __auto_type _mv = selection; uint8_t _mr = {0}; switch (_mv.tag) { case types_ProfileSelection_slop_auto: { _mr = (_retval == types_Profile_profile_el); break; } case types_ProfileSelection_explicit: { __auto_type p = _mv.data.explicit; _mr = (_retval == p); break; }  } _mr; })), "(match selection ((auto) (== $result (quote profile-el))) ((explicit p) (== $result p)))");
    return _retval;
}

