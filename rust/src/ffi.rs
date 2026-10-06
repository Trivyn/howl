//! Raw FFI bindings to HOWL's C API.
//!
//! The API is generated: slop writes `include/howl.h` from the `:c-name`
//! functions in `src/howl.slop`, and those functions keep the engine
//! behind opaque handles. Everything here is a HAND-WRITTEN MIRROR of that
//! header, asserted against the real ABI in the `layout_guard` test module
//! at the bottom of this file — see the comment there for why that is
//! mandatory rather than fastidious.
//!
//! C enums are mirrored as `c_int` constants, never as Rust enums: a value
//! the mirror does not know would be undefined behaviour in a Rust enum,
//! and is a loud panic in `lib.rs` instead.

use std::os::raw::{c_char, c_int, c_void};

/// `slop_string`: `len` bytes at `data`, not NUL-terminated.
#[repr(C)]
#[derive(Copy, Clone)]
pub struct SlopString {
    pub len: usize,
    pub data: *const c_char,
}

impl SlopString {
    /// Borrow `s` for the duration of a call.
    pub fn borrow(s: &str) -> SlopString {
        SlopString { len: s.len(), data: s.as_ptr() as *const c_char }
    }
}

/// `howl_Input`: an opaque handle.
#[repr(C)]
#[derive(Copy, Clone)]
pub struct Input {
    pub p: *mut c_void,
}

/// `howl_Run`: an opaque handle.
#[repr(C)]
#[derive(Copy, Clone)]
pub struct Run {
    pub p: *mut c_void,
}

/// `howl_Options`.
#[repr(C)]
#[derive(Copy, Clone)]
pub struct Options {
    pub workers: i64,
    pub max_iterations: i64,
    /// A `PROFILE_*` value (`types_Profile`).
    pub profile: c_int,
    pub auto_select: u8,
    /// The address of a `uint32_t` cancel flag, or 0.
    pub cancel: i64,
}

/// `howl_TermIn`. An empty `datatype` or `lang` is absent.
#[repr(C)]
#[derive(Copy, Clone)]
pub struct TermIn {
    /// A `TERM_*` value (`rdf_TermKind`).
    pub kind: c_int,
    pub blank: i64,
    pub value: SlopString,
    pub datatype: SlopString,
    pub lang: SlopString,
}

/// `howl_TurtleResult`.
#[repr(C)]
#[derive(Copy, Clone)]
pub struct TurtleResult {
    pub ok: u8,
    /// Owned by the input.
    pub message: SlopString,
    pub line: i64,
    pub column: i64,
}

/// `types_Termination`: a tag and, for a resource limit, the round count.
#[repr(C)]
#[derive(Copy, Clone)]
pub struct Termination {
    pub tag: c_int,
    pub resource_limit: i64,
}

// The enum values, in the order `howl_layout_constant` reports them.
pub const VERDICT_COHERENT: c_int = 0;
pub const VERDICT_INCOHERENT: c_int = 1;
pub const VERDICT_INCONCLUSIVE: c_int = 2;
pub const PROFILE_EL: c_int = 0;
pub const PROFILE_EL_PLUS_PLUS: c_int = 1;
pub const PROFILE_HORN_SRIQ: c_int = 2;
pub const PROFILE_SRIQ: c_int = 3;
pub const FAULT_NONE: c_int = 0;
pub const FAULT_CANCELLED: c_int = 1;
pub const FAULT_INPUT_ERROR: c_int = 2;
pub const FAULT_UNAVAILABLE: c_int = 3;
pub const FAULT_INVALID_OPTIONS: c_int = 4;
pub const TERM_IRI: c_int = 0;
pub const TERM_BLANK: c_int = 1;
pub const TERM_LITERAL: c_int = 2;
pub const TERMINATION_FIXPOINT: c_int = 0;
pub const TERMINATION_RESOURCE_LIMIT: c_int = 1;

/// Every constant above, in `howl_layout_constant`'s order.
pub const CONSTANTS: [(&str, c_int); 17] = [
    ("VERDICT_COHERENT", VERDICT_COHERENT),
    ("VERDICT_INCOHERENT", VERDICT_INCOHERENT),
    ("VERDICT_INCONCLUSIVE", VERDICT_INCONCLUSIVE),
    ("PROFILE_EL", PROFILE_EL),
    ("PROFILE_EL_PLUS_PLUS", PROFILE_EL_PLUS_PLUS),
    ("PROFILE_HORN_SRIQ", PROFILE_HORN_SRIQ),
    ("PROFILE_SRIQ", PROFILE_SRIQ),
    ("FAULT_NONE", FAULT_NONE),
    ("FAULT_CANCELLED", FAULT_CANCELLED),
    ("FAULT_INPUT_ERROR", FAULT_INPUT_ERROR),
    ("FAULT_UNAVAILABLE", FAULT_UNAVAILABLE),
    ("FAULT_INVALID_OPTIONS", FAULT_INVALID_OPTIONS),
    ("TERM_IRI", TERM_IRI),
    ("TERM_BLANK", TERM_BLANK),
    ("TERM_LITERAL", TERM_LITERAL),
    ("TERMINATION_FIXPOINT", TERMINATION_FIXPOINT),
    ("TERMINATION_RESOURCE_LIMIT", TERMINATION_RESOURCE_LIMIT),
];

extern "C" {
    pub fn howl_input_new() -> Input;
    pub fn howl_input_free(input: Input);
    pub fn howl_input_begin_document(input: Input);
    pub fn howl_input_add_triple(input: Input, s: TermIn, p: TermIn, o: TermIn) -> u8;
    pub fn howl_input_add_turtle(input: Input, text: SlopString) -> TurtleResult;
    pub fn howl_input_attest_import(input: Input, iri: SlopString);

    pub fn howl_default_options() -> Options;
    pub fn howl_run_classify(input: Input, options: Options) -> Run;
    pub fn howl_run_free(run: Run);

    pub fn howl_run_ok(run: Run) -> u8;
    pub fn howl_run_fault(run: Run) -> c_int;
    pub fn howl_run_fault_message(run: Run) -> SlopString;
    pub fn howl_run_fault_profile(run: Run) -> c_int;
    pub fn howl_run_profile(run: Run) -> c_int;
    pub fn howl_run_verdict(run: Run) -> c_int;
    pub fn howl_run_inconsistent(run: Run) -> u8;
    pub fn howl_run_termination(run: Run) -> Termination;
    pub fn howl_run_rounds(run: Run) -> i64;
    pub fn howl_run_unsat_len(run: Run) -> i64;
    pub fn howl_run_unsat(run: Run, i: i64) -> SlopString;
    pub fn howl_run_sub_len(run: Run) -> i64;
    pub fn howl_run_sub(run: Run, i: i64) -> SlopString;
    pub fn howl_run_super(run: Run, i: i64) -> SlopString;
    pub fn howl_run_omission_len(run: Run) -> i64;
    pub fn howl_run_omission(run: Run, i: i64) -> SlopString;
    pub fn howl_run_report_len(run: Run) -> i64;
    pub fn howl_run_report_line(run: Run, i: i64) -> SlopString;
}

#[cfg(test)]
mod layout_guard {
    //! Assert the hand-written `#[repr(C)]` mirrors above match the real
    //! C ABI of `include/howl.h`, as reported by `layout_probes.c`.
    //!
    //! WHY THIS EXISTS. GROWL 0.6.0 shipped a wrong-offset FFI read: a
    //! dependency added a field to a struct embedded BY VALUE in
    //! another, every field after it shifted, and the Rust mirror was
    //! not updated. Nothing failed loudly — `graph.size()` just
    //! returned a garbage pointer. A mirror is a duplicate of a
    //! definition generated somewhere else, so it needs a test, not care.

    use super::*;
    use core::mem::{size_of, size_of_val, MaybeUninit};

    extern "C" {
        fn howl_layout_sizeof_slop_string() -> usize;
        fn howl_layout_offset_slop_string_data() -> usize;
        fn howl_layout_sizeof_howl_Input() -> usize;
        fn howl_layout_sizeof_howl_Run() -> usize;
        fn howl_layout_sizeof_howl_Options() -> usize;
        fn howl_layout_offset_howl_Options_max_iterations() -> usize;
        fn howl_layout_offset_howl_Options_profile() -> usize;
        fn howl_layout_offset_howl_Options_auto_select() -> usize;
        fn howl_layout_offset_howl_Options_cancel() -> usize;
        fn howl_layout_width_howl_Options_workers() -> usize;
        fn howl_layout_width_howl_Options_profile() -> usize;
        fn howl_layout_width_howl_Options_auto_select() -> usize;
        fn howl_layout_sizeof_howl_TermIn() -> usize;
        fn howl_layout_offset_howl_TermIn_blank() -> usize;
        fn howl_layout_offset_howl_TermIn_value() -> usize;
        fn howl_layout_offset_howl_TermIn_datatype() -> usize;
        fn howl_layout_offset_howl_TermIn_lang() -> usize;
        fn howl_layout_width_howl_TermIn_kind() -> usize;
        fn howl_layout_sizeof_howl_TurtleResult() -> usize;
        fn howl_layout_offset_howl_TurtleResult_message() -> usize;
        fn howl_layout_offset_howl_TurtleResult_line() -> usize;
        fn howl_layout_offset_howl_TurtleResult_column() -> usize;
        fn howl_layout_width_howl_TurtleResult_ok() -> usize;
        fn howl_layout_sizeof_types_Termination() -> usize;
        fn howl_layout_offset_types_Termination_data() -> usize;
        fn howl_layout_width_types_Termination_tag() -> usize;
        fn howl_layout_constant(which: c_int) -> std::os::raw::c_long;
    }

    // `core::mem::offset_of!` is not stable on the MSRV this crate
    // targets, so offsets are computed from an uninitialized instance.
    macro_rules! offset_of {
        ($ty:ty, $field:ident) => {{
            let base = MaybeUninit::<$ty>::uninit();
            let ptr = base.as_ptr();
            unsafe { core::ptr::addr_of!((*ptr).$field) as usize - ptr as usize }
        }};
    }

    macro_rules! width_of {
        ($ty:ty, $field:ident) => {{
            let base = MaybeUninit::<$ty>::uninit();
            let ptr = base.as_ptr();
            size_of_val(unsafe { &*core::ptr::addr_of!((*ptr).$field) })
        }};
    }

    #[test]
    fn structs_match_c_abi() {
        let checks: [(&str, usize, usize); 26] = unsafe {
            [
                ("slop_string", size_of::<SlopString>(), howl_layout_sizeof_slop_string()),
                ("slop_string.data", offset_of!(SlopString, data), howl_layout_offset_slop_string_data()),
                ("howl_Input", size_of::<Input>(), howl_layout_sizeof_howl_Input()),
                ("howl_Run", size_of::<Run>(), howl_layout_sizeof_howl_Run()),
                ("howl_Options", size_of::<Options>(), howl_layout_sizeof_howl_Options()),
                ("howl_Options.max_iterations", offset_of!(Options, max_iterations), howl_layout_offset_howl_Options_max_iterations()),
                ("howl_Options.profile", offset_of!(Options, profile), howl_layout_offset_howl_Options_profile()),
                ("howl_Options.auto_select", offset_of!(Options, auto_select), howl_layout_offset_howl_Options_auto_select()),
                ("howl_Options.cancel", offset_of!(Options, cancel), howl_layout_offset_howl_Options_cancel()),
                ("width howl_Options.workers", width_of!(Options, workers), howl_layout_width_howl_Options_workers()),
                ("width howl_Options.profile", width_of!(Options, profile), howl_layout_width_howl_Options_profile()),
                // One byte before 8-aligned `cancel`: padding would hide a
                // widened mirror from every offset above.
                ("width howl_Options.auto_select", width_of!(Options, auto_select), howl_layout_width_howl_Options_auto_select()),
                ("howl_TermIn", size_of::<TermIn>(), howl_layout_sizeof_howl_TermIn()),
                ("howl_TermIn.blank", offset_of!(TermIn, blank), howl_layout_offset_howl_TermIn_blank()),
                ("howl_TermIn.value", offset_of!(TermIn, value), howl_layout_offset_howl_TermIn_value()),
                ("howl_TermIn.datatype", offset_of!(TermIn, datatype), howl_layout_offset_howl_TermIn_datatype()),
                ("howl_TermIn.lang", offset_of!(TermIn, lang), howl_layout_offset_howl_TermIn_lang()),
                ("width howl_TermIn.kind", width_of!(TermIn, kind), howl_layout_width_howl_TermIn_kind()),
                ("howl_TurtleResult", size_of::<TurtleResult>(), howl_layout_sizeof_howl_TurtleResult()),
                ("howl_TurtleResult.message", offset_of!(TurtleResult, message), howl_layout_offset_howl_TurtleResult_message()),
                ("howl_TurtleResult.line", offset_of!(TurtleResult, line), howl_layout_offset_howl_TurtleResult_line()),
                ("howl_TurtleResult.column", offset_of!(TurtleResult, column), howl_layout_offset_howl_TurtleResult_column()),
                ("width howl_TurtleResult.ok", width_of!(TurtleResult, ok), howl_layout_width_howl_TurtleResult_ok()),
                ("types_Termination", size_of::<Termination>(), howl_layout_sizeof_types_Termination()),
                ("types_Termination.data", offset_of!(Termination, resource_limit), howl_layout_offset_types_Termination_data()),
                ("width types_Termination.tag", width_of!(Termination, tag), howl_layout_width_types_Termination_tag()),
            ]
        };
        for (what, rust, c) in checks {
            assert_eq!(rust, c, "{what} drifted from include/howl.h");
        }
    }

    /// Every enum value the crate reads or writes, against the header.
    #[test]
    fn constants_match_c_abi() {
        for (i, (name, value)) in CONSTANTS.iter().enumerate() {
            let c = unsafe { howl_layout_constant(i as c_int) };
            assert_eq!(*value as std::os::raw::c_long, c, "{name} drifted from include/howl.h");
        }
        assert_eq!(unsafe { howl_layout_constant(CONSTANTS.len() as c_int) }, -1, "a C constant has no mirror");
    }

    /// The default options must survive the crossing unchanged: if any
    /// field is at the wrong offset, at least one of these reads garbage.
    #[test]
    fn default_options_cross_intact() {
        let o = unsafe { howl_default_options() };
        assert_eq!(o.workers, 4, "workers");
        assert_eq!(o.max_iterations, 1000, "max_iterations");
        // `explicit el`, not `auto`: a default run keeps one cost class
        // (PTIME) and one theory across upgrades (SPEC §5.1).
        assert_eq!(o.profile, PROFILE_EL, "the default profile is el");
        assert_eq!(o.auto_select, 0, "the default is explicit");
        assert_eq!(o.cancel, 0, "cancel");
    }
}
