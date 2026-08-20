//! Raw FFI bindings matching the C types in `howl.h` and `slop_runtime.h`.
//!
//! Every struct here is a HAND-WRITTEN MIRROR of a C struct the SLOP
//! transpiler generates. They are asserted against the real ABI in the
//! `layout_guard` test module at the bottom of this file — see the
//! comment there for why that is mandatory rather than fastidious.

use std::os::raw::c_char;

/// Opaque arena allocator.
#[repr(C)]
pub struct SlopArena {
    _private: [u8; 0],
}

/// Length-prefixed string (not null-terminated).
#[repr(C)]
#[derive(Copy, Clone)]
pub struct SlopString {
    pub len: usize,
    pub data: *const c_char,
}

// ---------------------------------------------------------------------------
// RDF types
// ---------------------------------------------------------------------------

#[repr(C)]
#[derive(Copy, Clone)]
pub struct RdfIri {
    pub value: SlopString,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct RdfBlankNode {
    pub id: i64,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct RdfLiteral {
    pub value: SlopString,
    pub datatype_has_value: bool,
    pub datatype: SlopString,
    pub lang_has_value: bool,
    pub lang: SlopString,
}

#[repr(C)]
#[derive(Copy, Clone, PartialEq, Eq, Debug)]
pub enum RdfTermTag {
    Iri = 0,
    Blank = 1,
    Literal = 2,
    Triple = 3,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub union RdfTermData {
    pub term_iri: RdfIri,
    pub term_blank: RdfBlankNode,
    pub term_literal: RdfLiteral,
    pub term_triple: *mut RdfTriple,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct RdfTerm {
    pub tag: RdfTermTag,
    pub data: RdfTermData,
}

#[repr(C)]
#[derive(Copy, Clone)]
pub struct RdfTriple {
    pub subject: RdfTerm,
    pub predicate: RdfTerm,
    pub object: RdfTerm,
}

// ---------------------------------------------------------------------------
// HOWL configuration
// ---------------------------------------------------------------------------

#[repr(C)]
#[derive(Copy, Clone, PartialEq, Eq, Debug)]
pub enum Profile {
    El = 0,
    HornShiq = 1,
    Sroiq = 2,
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

extern "C" {
    // Arena management (wrappers around static inline runtime functions).
    pub fn howl_arena_new(capacity: usize) -> *mut SlopArena;
    pub fn howl_arena_free(arena: *mut SlopArena);
    pub fn howl_intern_string(data: *const c_char, len: usize) -> SlopString;

    // Public API.
    pub fn howl_default_config() -> ReasonerConfig;

    // FFI layout guards (defined in csrc_shim.c) — expose the real C
    // ABI so the `#[repr(C)]` mirrors above can be asserted against it.
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
    pub fn howl_layout_sizeof_rdf_term() -> usize;
    pub fn howl_layout_sizeof_rdf_triple() -> usize;
    pub fn howl_layout_offset_triple_predicate() -> usize;
    pub fn howl_layout_offset_triple_object() -> usize;
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
    use core::mem::{align_of, size_of};

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

    #[test]
    fn rdf_types_match_c_abi() {
        unsafe {
            assert_eq!(size_of::<ProfileSelection>(), howl_layout_sizeof_profile_selection());
            assert_eq!(size_of::<RdfTerm>(), howl_layout_sizeof_rdf_term());
            assert_eq!(size_of::<RdfTriple>(), howl_layout_sizeof_rdf_triple());
            assert_eq!(memoffset_triple_predicate(), howl_layout_offset_triple_predicate());
            assert_eq!(memoffset_triple_object(), howl_layout_offset_triple_object());
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
        assert_eq!(
            cfg.selection.tag,
            ProfileSelectionTag::Auto,
            "auto is the default selection and is NOT a Profile"
        );
    }

    #[test]
    fn alignment_is_sane() {
        assert!(align_of::<ReasonerConfig>() >= align_of::<i64>());
    }

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

    fn memoffset_worker_count() -> usize { offset_of!(ReasonerConfig, worker_count) }
    fn memoffset_channel_buffer() -> usize { offset_of!(ReasonerConfig, channel_buffer) }
    fn memoffset_max_iterations() -> usize { offset_of!(ReasonerConfig, max_iterations) }
    fn memoffset_selection() -> usize { offset_of!(ReasonerConfig, selection) }
    fn memoffset_strict_profile() -> usize { offset_of!(ReasonerConfig, strict_profile) }
    fn memoffset_cancel_ptr() -> usize { offset_of!(ReasonerConfig, cancel_ptr) }
    fn memoffset_verbose() -> usize { offset_of!(ReasonerConfig, verbose) }
    fn memoffset_triple_predicate() -> usize { offset_of!(RdfTriple, predicate) }
    fn memoffset_triple_object() -> usize { offset_of!(RdfTriple, object) }
}
