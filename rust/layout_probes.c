/*
 * FFI LAYOUT PROBES, compiled only into the Rust crate.
 *
 * HOWL's C API is generated: slop writes include/howl.h from the
 * `:c-name` functions in src/howl.slop. This file reports that header's
 * real ABI - struct sizes, field offsets and widths, and every enum value
 * the crate reads - so the hand-written mirrors in src/ffi.rs can be
 * asserted against it in tests.
 *
 * This is not defensive boilerplate. A silent drift here is exactly what
 * regressed GROWL 0.6.0: slop-rdf added a 4th index (`pos`) to
 * `index_TripleIndex`, growing `index_IndexedGraph` by 8 bytes, but the
 * Rust `TripleIndex` mirror was not updated - so `IndexedGraph.size` was
 * read at the WRONG OFFSET across the FFI boundary and `graph.size()`
 * returned a garbage pointer. Nothing failed loudly.
 *
 * WIDTHS, NOT JUST OFFSETS. A field widened on one side can be absorbed by
 * padding: `howl_Options.auto_select` is one byte before 8-aligned
 * `cancel`, so a wider mirror would leave every offset and the total size
 * unchanged while reading padding into the high bits. That gap was found
 * by deliberately drifting a mirror to check the guards bite.
 */

#include "howl.h"
#include <stddef.h>

#define SIZE(T)          size_t howl_layout_sizeof_##T(void) { return sizeof(T); }
#define OFFSET(T, f)     size_t howl_layout_offset_##T##_##f(void) { return offsetof(T, f); }
#define WIDTH(T, f)      size_t howl_layout_width_##T##_##f(void) { return sizeof(((T*)0)->f); }

SIZE(slop_string)        OFFSET(slop_string, data)
SIZE(howl_Input)
SIZE(howl_Run)
SIZE(howl_Options)       OFFSET(howl_Options, max_iterations) OFFSET(howl_Options, profile)
                         OFFSET(howl_Options, auto_select) OFFSET(howl_Options, cancel)
                         WIDTH(howl_Options, workers) WIDTH(howl_Options, profile) WIDTH(howl_Options, auto_select)
SIZE(howl_TermIn)        OFFSET(howl_TermIn, blank) OFFSET(howl_TermIn, value)
                         OFFSET(howl_TermIn, datatype) OFFSET(howl_TermIn, lang) WIDTH(howl_TermIn, kind)
SIZE(howl_TurtleResult)  OFFSET(howl_TurtleResult, message) OFFSET(howl_TurtleResult, line)
                         OFFSET(howl_TurtleResult, column) WIDTH(howl_TurtleResult, ok)
SIZE(types_Termination)  OFFSET(types_Termination, data) WIDTH(types_Termination, tag)

/* Every enum value the crate reads or writes, in the order of
 * `ffi::CONSTANTS`. A reordered verdict is the worst drift there is:
 * `coherent` and `inconclusive` trade places and a coverage gap reads as
 * a pass. */
long howl_layout_constant(int which) {
    static const long values[] = {
        types_Verdict_verdict_coherent, types_Verdict_verdict_incoherent, types_Verdict_verdict_inconclusive,
        types_Profile_profile_el, types_Profile_profile_el_plus_plus,
        types_Profile_profile_horn_sriq, types_Profile_profile_sriq,
        howl_FaultKind_fault_none, howl_FaultKind_fault_cancelled, howl_FaultKind_fault_input_error,
        howl_FaultKind_fault_unavailable, howl_FaultKind_fault_invalid_options,
        rdf_TermKind_iri, rdf_TermKind_blank, rdf_TermKind_literal,
        types_Termination_fixpoint, types_Termination_resource_limit,
    };
    return (which >= 0 && which < (int)(sizeof values / sizeof values[0])) ? values[which] : -1;
}
