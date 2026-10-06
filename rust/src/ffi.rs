//! Raw FFI bindings to the engine and to `csrc_shim.c`.
//!
//! Only three things cross by value, and each is a HAND-WRITTEN MIRROR:
//! `slop_string`, the engine's `types_ReasonerConfig`, and the shim's
//! own `howl_term`. Engine results stay in C behind [`HowlRun`] and are
//! read through accessors (see `csrc_shim.c` for why). The mirrors, and
//! the enum discriminants the accessors return, are asserted against
//! the real ABI in the `layout_guard` test module at the bottom of this
//! file — see the comment there for why that is mandatory rather than
//! fastidious.

use std::os::raw::{c_char, c_int};

/// Length-prefixed string (not null-terminated).
#[repr(C)]
#[derive(Copy, Clone)]
pub struct SlopString {
    pub len: usize,
    pub data: *const c_char,
}

// ---------------------------------------------------------------------------
// HOWL configuration
// ---------------------------------------------------------------------------

#[repr(C)]
#[derive(Copy, Clone, PartialEq, Eq, Debug)]
pub enum Profile {
    El = 0,
    ElPlusPlus = 1,
    HornSriq = 2,
    Sriq = 3,
}

#[repr(C)]
#[derive(Copy, Clone, PartialEq, Eq, Debug)]
pub enum ProfileSelectionTag {
    Auto = 0,
    Explicit = 1,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub union ProfileSelectionData {
    pub explicit: Profile,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct ProfileSelection {
    pub tag: ProfileSelectionTag,
    pub data: ProfileSelectionData,
}

/// Mirror of `types_ReasonerConfig`.
///
/// NOTE THE NARROW INTEGER WIDTHS. SLOP range types lower to the
/// smallest integer that fits: `(Int 1 .. 64)` becomes `uint8_t`,
/// `(Int 64 .. 4096)` and `(Int 0 .. 10000)` become `uint16_t`.
/// Reaching for the obvious `u32`/`usize` here produces a mirror that
/// compiles cleanly on both sides and reads every field after the
/// first mismatch at the wrong offset. The layout guard below is what
/// catches that.
#[repr(C)]
#[derive(Copy, Clone)]
pub struct ReasonerConfig {
    pub worker_count: u8,
    pub channel_buffer: u16,
    pub max_iterations: u16,
    pub selection: ProfileSelection,
    pub strict_profile: u8,
    pub cancel_ptr: i64,
    pub verbose: u8,
}

// ---------------------------------------------------------------------------
// The shim: input, run, and the discriminants its accessors return
// ---------------------------------------------------------------------------

/// Opaque: an encoded input (`howl_input`).
#[repr(C)]
pub struct HowlInput {
    _private: [u8; 0],
}

/// Opaque: a finished run (`howl_run`).
#[repr(C)]
pub struct HowlRun {
    _private: [u8; 0],
}

pub const HOWL_TERM_IRI: u32 = 0;
pub const HOWL_TERM_BLANK: u32 = 1;
pub const HOWL_TERM_LITERAL: u32 = 2;

/// Mirror of the shim's `howl_term`. A null `datatype` or `lang` means
/// absent; strings are borrowed for the call.
#[repr(C)]
#[derive(Copy, Clone)]
pub struct HowlTerm {
    pub kind: u32,
    pub blank: i64,
    pub value: *const c_char,
    pub value_len: usize,
    pub datatype: *const c_char,
    pub datatype_len: usize,
    pub lang: *const c_char,
    pub lang_len: usize,
}

// The C enums' discriminants, as the accessors return them. Each is
// asserted against the engine's own enum in `layout_guard`.
pub const VERDICT_COHERENT: c_int = 0;
pub const VERDICT_INCOHERENT: c_int = 1;
pub const VERDICT_INCONCLUSIVE: c_int = 2;
pub const TERMINATION_FIXPOINT: c_int = 0;
pub const TERMINATION_RESOURCE_LIMIT: c_int = 1;
pub const FAULT_CANCELLED: c_int = 0;
pub const FAULT_INPUT_ERROR: c_int = 1;
pub const FAULT_REFUSED: c_int = 2;
pub const FAULT_UNAVAILABLE: c_int = 3;

extern "C" {
    pub fn howl_default_config() -> ReasonerConfig;

    pub fn howl_input_new() -> *mut HowlInput;
    pub fn howl_input_free(input: *mut HowlInput);
    pub fn howl_input_begin_document(input: *mut HowlInput);
    pub fn howl_input_add_triples(input: *mut HowlInput, terms: *const HowlTerm, n: usize);
    pub fn howl_input_add_turtle(
        input: *mut HowlInput,
        text: *const c_char,
        len: usize,
        message: *mut SlopString,
        line: *mut i64,
        column: *mut i64,
    ) -> c_int;
    pub fn howl_input_attest_import(input: *mut HowlInput, iri: *const c_char, len: usize);

    pub fn howl_run_classify(input: *const HowlInput, config: ReasonerConfig) -> *mut HowlRun;
    pub fn howl_run_free(run: *mut HowlRun);

    pub fn howl_run_ok(run: *const HowlRun) -> c_int;
    pub fn howl_run_fault_tag(run: *const HowlRun) -> c_int;
    pub fn howl_run_fault_message(run: *const HowlRun) -> SlopString;
    pub fn howl_run_fault_profile(run: *const HowlRun) -> c_int;
    pub fn howl_run_refused_len(run: *const HowlRun) -> usize;
    pub fn howl_run_refused(run: *mut HowlRun, i: usize) -> SlopString;

    pub fn howl_run_profile(run: *const HowlRun) -> c_int;
    pub fn howl_run_verdict(run: *const HowlRun) -> c_int;
    pub fn howl_run_inconsistent(run: *const HowlRun) -> c_int;
    pub fn howl_run_termination_tag(run: *const HowlRun) -> c_int;
    pub fn howl_run_resource_limit(run: *const HowlRun) -> i64;
    pub fn howl_run_rounds(run: *const HowlRun) -> i64;
    pub fn howl_run_unsat_len(run: *const HowlRun) -> usize;
    pub fn howl_run_unsat(run: *const HowlRun, i: usize) -> SlopString;
    pub fn howl_run_sub_len(run: *const HowlRun) -> usize;
    pub fn howl_run_sub(run: *mut HowlRun, i: usize) -> SlopString;
    pub fn howl_run_super(run: *mut HowlRun, i: usize) -> SlopString;
    pub fn howl_run_omission_len(run: *const HowlRun) -> usize;
    pub fn howl_run_omission(run: *mut HowlRun, i: usize) -> SlopString;
    pub fn howl_run_report_len(run: *const HowlRun) -> usize;
    pub fn howl_run_report_line(run: *const HowlRun, i: usize) -> SlopString;

    // FFI layout guards (defined in csrc_shim.c) — expose the real C
    // ABI so the mirrors above can be asserted against it.
    pub fn howl_layout_sizeof_reasoner_config() -> usize;
    pub fn howl_layout_offset_cfg_worker_count() -> usize;
    pub fn howl_layout_offset_cfg_channel_buffer() -> usize;
    pub fn howl_layout_offset_cfg_max_iterations() -> usize;
    pub fn howl_layout_offset_cfg_selection() -> usize;
    pub fn howl_layout_offset_cfg_strict_profile() -> usize;
    pub fn howl_layout_offset_cfg_cancel_ptr() -> usize;
    pub fn howl_layout_offset_cfg_verbose() -> usize;
    pub fn howl_layout_fieldsize_cfg_worker_count() -> usize;
    pub fn howl_layout_fieldsize_cfg_channel_buffer() -> usize;
    pub fn howl_layout_fieldsize_cfg_max_iterations() -> usize;
    pub fn howl_layout_fieldsize_cfg_strict_profile() -> usize;
    pub fn howl_layout_fieldsize_cfg_cancel_ptr() -> usize;
    pub fn howl_layout_fieldsize_cfg_verbose() -> usize;
    pub fn howl_layout_sizeof_profile_selection() -> usize;
    pub fn howl_layout_profile_el() -> c_int;
    pub fn howl_layout_profile_el_plus_plus() -> c_int;
    pub fn howl_layout_profile_horn_sriq() -> c_int;
    pub fn howl_layout_profile_sriq() -> c_int;
    pub fn howl_layout_verdict_coherent() -> c_int;
    pub fn howl_layout_verdict_incoherent() -> c_int;
    pub fn howl_layout_verdict_inconclusive() -> c_int;
    pub fn howl_layout_termination_fixpoint() -> c_int;
    pub fn howl_layout_termination_resource_limit() -> c_int;
    pub fn howl_layout_fault_cancelled() -> c_int;
    pub fn howl_layout_fault_input_error() -> c_int;
    pub fn howl_layout_fault_refused() -> c_int;
    pub fn howl_layout_fault_unavailable() -> c_int;
    pub fn howl_layout_sizeof_slop_string() -> usize;
    pub fn howl_layout_offset_string_data() -> usize;
    pub fn howl_layout_sizeof_howl_term() -> usize;
    pub fn howl_layout_offset_term_blank() -> usize;
    pub fn howl_layout_offset_term_value() -> usize;
    pub fn howl_layout_offset_term_value_len() -> usize;
    pub fn howl_layout_offset_term_datatype() -> usize;
    pub fn howl_layout_offset_term_datatype_len() -> usize;
    pub fn howl_layout_offset_term_lang() -> usize;
    pub fn howl_layout_offset_term_lang_len() -> usize;
    pub fn howl_layout_fieldsize_term_kind() -> usize;
}

#[cfg(test)]
mod layout_guard {
    //! Assert the hand-written `#[repr(C)]` mirrors above match the real
    //! C ABI reported by `csrc_shim.c`.
    //!
    //! WHY THIS EXISTS. GROWL 0.6.0 shipped a wrong-offset FFI read: a
    //! dependency added a field to a struct embedded BY VALUE in
    //! another, every field after it shifted, and the Rust mirror was
    //! not updated. Nothing failed loudly — `graph.size()` just
    //! returned a garbage pointer. A mirror is a duplicate of a
    //! definition that lives in another repository and changes without
    //! notice, so it needs a test, not care.
    //!
    //! Offsets matter as much as sizes: two structs can agree on total
    //! size while disagreeing about where the fields sit, and the
    //! by-value embedded `ProfileSelection` is exactly the shape that
    //! makes it happen.

    use super::*;
    use core::mem::{align_of, size_of, size_of_val};

    // Offset helpers. `core::mem::offset_of!` is not stable on the MSRV
    // this crate targets, so the offsets are computed from a
    // zero-initialized instance rather than pulling in a dependency.
    macro_rules! offset_of {
        ($ty:ty, $field:ident) => {{
            let base = core::mem::MaybeUninit::<$ty>::uninit();
            let ptr = base.as_ptr();
            unsafe { core::ptr::addr_of!((*ptr).$field) as usize - ptr as usize }
        }};
    }

    #[test]
    fn reasoner_config_matches_c_abi() {
        unsafe {
            assert_eq!(
                size_of::<ReasonerConfig>(),
                howl_layout_sizeof_reasoner_config(),
                "ReasonerConfig size drifted from the C ABI"
            );
            assert_eq!(
                memoffset_worker_count(),
                howl_layout_offset_cfg_worker_count(),
                "ReasonerConfig.worker_count offset drifted"
            );
            assert_eq!(
                memoffset_channel_buffer(),
                howl_layout_offset_cfg_channel_buffer(),
                "ReasonerConfig.channel_buffer offset drifted"
            );
            assert_eq!(
                memoffset_max_iterations(),
                howl_layout_offset_cfg_max_iterations(),
                "ReasonerConfig.max_iterations offset drifted"
            );
            assert_eq!(
                memoffset_selection(),
                howl_layout_offset_cfg_selection(),
                "ReasonerConfig.selection offset drifted"
            );
            assert_eq!(
                memoffset_strict_profile(),
                howl_layout_offset_cfg_strict_profile(),
                "ReasonerConfig.strict_profile offset drifted"
            );
            // The field after the by-value embedded struct — the exact
            // shape that broke GROWL 0.6.0.
            assert_eq!(
                memoffset_cancel_ptr(),
                howl_layout_offset_cfg_cancel_ptr(),
                "ReasonerConfig.cancel_ptr offset drifted (field after an embedded struct)"
            );
            assert_eq!(
                memoffset_verbose(),
                howl_layout_offset_cfg_verbose(),
                "ReasonerConfig.verbose offset drifted"
            );
        }
    }

    /// Offsets and total size are NOT sufficient on their own.
    ///
    /// Found by deliberately drifting this mirror to check the guard
    /// bites: widening `strict_profile` from `u8` to `u32` leaves every
    /// offset and the struct size unchanged, because the field sits at
    /// 16, `cancel_ptr` is 8-aligned at 24, and the seven bytes between
    /// them are padding. An offset-only guard passes while the Rust
    /// side reads three bytes of padding into the high bits of a
    /// one-byte value.
    #[test]
    fn reasoner_config_field_widths_match_c_abi() {
        // Every discriminant in this struct's enums has a valid zero
        // representation (ProfileSelectionTag::Auto, Profile::El), so a
        // zeroed instance is sound to inspect.
        let c: ReasonerConfig = unsafe { core::mem::zeroed() };
        unsafe {
            assert_eq!(
                size_of_val(&c.worker_count),
                howl_layout_fieldsize_cfg_worker_count(),
                "worker_count width drifted — SLOP (Int 1 .. 64) lowers to uint8_t"
            );
            assert_eq!(
                size_of_val(&c.channel_buffer),
                howl_layout_fieldsize_cfg_channel_buffer(),
                "channel_buffer width drifted — (Int 64 .. 4096) lowers to uint16_t"
            );
            assert_eq!(
                size_of_val(&c.max_iterations),
                howl_layout_fieldsize_cfg_max_iterations(),
                "max_iterations width drifted — (Int 0 .. 10000) lowers to uint16_t"
            );
            assert_eq!(
                size_of_val(&c.strict_profile),
                howl_layout_fieldsize_cfg_strict_profile(),
                "strict_profile width drifted (padding hides this from the offset checks)"
            );
            assert_eq!(
                size_of_val(&c.cancel_ptr),
                howl_layout_fieldsize_cfg_cancel_ptr(),
                "cancel_ptr width drifted"
            );
            assert_eq!(
                size_of_val(&c.verbose),
                howl_layout_fieldsize_cfg_verbose(),
                "verbose width drifted"
            );
        }
    }

    /// Each rung's discriminant, against the C enum: a reordered mirror
    /// keeps its size and silently requests a different calculus.
    #[test]
    fn profile_discriminants_match_c_abi() {
        unsafe {
            assert_eq!(Profile::El as c_int, howl_layout_profile_el());
            assert_eq!(Profile::ElPlusPlus as c_int, howl_layout_profile_el_plus_plus());
            assert_eq!(Profile::HornSriq as c_int, howl_layout_profile_horn_sriq());
            assert_eq!(Profile::Sriq as c_int, howl_layout_profile_sriq());
        }
    }

    /// The discriminants the run accessors return. A reordered verdict
    /// enum is the worst drift there is: `coherent` and `inconclusive`
    /// trade places and a coverage gap reads as a pass.
    #[test]
    fn result_discriminants_match_c_abi() {
        unsafe {
            assert_eq!(VERDICT_COHERENT, howl_layout_verdict_coherent());
            assert_eq!(VERDICT_INCOHERENT, howl_layout_verdict_incoherent());
            assert_eq!(VERDICT_INCONCLUSIVE, howl_layout_verdict_inconclusive());
            assert_eq!(TERMINATION_FIXPOINT, howl_layout_termination_fixpoint());
            assert_eq!(TERMINATION_RESOURCE_LIMIT, howl_layout_termination_resource_limit());
            assert_eq!(FAULT_CANCELLED, howl_layout_fault_cancelled());
            assert_eq!(FAULT_INPUT_ERROR, howl_layout_fault_input_error());
            assert_eq!(FAULT_REFUSED, howl_layout_fault_refused());
            assert_eq!(FAULT_UNAVAILABLE, howl_layout_fault_unavailable());
        }
    }

    #[test]
    fn crossing_structs_match_c_abi() {
        let offsets = [
            (offset_of!(HowlTerm, blank), unsafe { howl_layout_offset_term_blank() }, "blank"),
            (offset_of!(HowlTerm, value), unsafe { howl_layout_offset_term_value() }, "value"),
            (offset_of!(HowlTerm, value_len), unsafe { howl_layout_offset_term_value_len() }, "value_len"),
            (offset_of!(HowlTerm, datatype), unsafe { howl_layout_offset_term_datatype() }, "datatype"),
            (offset_of!(HowlTerm, datatype_len), unsafe { howl_layout_offset_term_datatype_len() }, "datatype_len"),
            (offset_of!(HowlTerm, lang), unsafe { howl_layout_offset_term_lang() }, "lang"),
            (offset_of!(HowlTerm, lang_len), unsafe { howl_layout_offset_term_lang_len() }, "lang_len"),
            (offset_of!(SlopString, data), unsafe { howl_layout_offset_string_data() }, "SlopString.data"),
        ];
        for (rust, c, field) in offsets {
            assert_eq!(rust, c, "HowlTerm.{field} offset drifted");
        }
        // `kind` sits before 8-aligned `blank`, so padding would hide a
        // widened mirror from every offset above.
        let t = HowlTerm {
            kind: 0,
            blank: 0,
            value: core::ptr::null(),
            value_len: 0,
            datatype: core::ptr::null(),
            datatype_len: 0,
            lang: core::ptr::null(),
            lang_len: 0,
        };
        unsafe {
            assert_eq!(size_of::<ProfileSelection>(), howl_layout_sizeof_profile_selection());
            assert_eq!(size_of::<SlopString>(), howl_layout_sizeof_slop_string());
            assert_eq!(size_of::<HowlTerm>(), howl_layout_sizeof_howl_term(), "HowlTerm size drifted");
            assert_eq!(size_of_val(&t.kind), howl_layout_fieldsize_term_kind(), "HowlTerm.kind width drifted");
        }
    }

    /// The default config must survive the crossing unchanged. This is
    /// a live end-to-end check on the mirror: if any field is at the
    /// wrong offset, at least one of these reads garbage.
    #[test]
    fn default_config_crosses_intact() {
        let cfg = unsafe { howl_default_config() };
        assert_eq!(cfg.worker_count, 4, "worker_count");
        assert_eq!(cfg.channel_buffer, 256, "channel_buffer");
        assert_eq!(cfg.max_iterations, 1000, "max_iterations");
        assert_eq!(cfg.strict_profile, 0, "strict_profile must default false");
        assert_eq!(cfg.cancel_ptr, 0, "cancel_ptr");
        // `explicit el`, not `auto`: a default run keeps one cost class
        // (PTIME) and one theory across upgrades (SPEC §5.1).
        assert_eq!(
            cfg.selection.tag,
            ProfileSelectionTag::Explicit,
            "the default selection is explicit"
        );
        assert_eq!(
            unsafe { cfg.selection.data.explicit },
            Profile::El,
            "the default profile is el"
        );
    }

    #[test]
    fn alignment_is_sane() {
        assert!(align_of::<ReasonerConfig>() >= align_of::<i64>());
    }

    fn memoffset_worker_count() -> usize { offset_of!(ReasonerConfig, worker_count) }
    fn memoffset_channel_buffer() -> usize { offset_of!(ReasonerConfig, channel_buffer) }
    fn memoffset_max_iterations() -> usize { offset_of!(ReasonerConfig, max_iterations) }
    fn memoffset_selection() -> usize { offset_of!(ReasonerConfig, selection) }
    fn memoffset_strict_profile() -> usize { offset_of!(ReasonerConfig, strict_profile) }
    fn memoffset_cancel_ptr() -> usize { offset_of!(ReasonerConfig, cancel_ptr) }
    fn memoffset_verbose() -> usize { offset_of!(ReasonerConfig, verbose) }
}
