use std::env;
use std::fs;
use std::path::Path;

fn main() {
    let csrc = Path::new("csrc/src");
    let runtime = Path::new("csrc/runtime");

    // Shared rdf/std headers and symbols come from the -sys crates.
    // Vendoring our own copy would collide on duplicate symbols for any
    // consumer that links both.
    let rdf_inc = env::var("DEP_SLOP_RDF_INCLUDE").expect("slop-rdf-sys must be a dependency");
    let std_inc = env::var("DEP_SLOP_STD_INCLUDE").expect("slop-std-sys must be a dependency");

    // HOWL's modules are compiled against its own copy of the runtime
    // header and linked against slop-std-sys's runtime objects, so the two
    // must agree on the runtime ABI. Every generated header checks that at
    // compile time (`SLOP_RUNTIME_ABI`, slop 0.5.0): HOWL's modules include
    // the -sys crates' headers, which `#error` against a runtime header of
    // another ABI. A copy differing only in comments, as 0.5.1's does from
    // 0.5.0's, builds.
    // Every vendored HOWL module (`make crate-vendor` leaves out the
    // shared ones and the CLI and test entry points), in a fixed order.
    let mut sources: Vec<_> = fs::read_dir(csrc)
        .expect("csrc/src (run `make crate-vendor`)")
        .map(|e| e.unwrap().path())
        .filter(|p| p.extension().map_or(false, |x| x == "c"))
        .collect();
    sources.sort();

    let mut build = cc::Build::new();
    // The generated C uses GNU statement expressions and __auto_type, which
    // MSVC's cl.exe rejects; clang-cl accepts them, as in the -sys crates.
    // CC still overrides this.
    build
        .prefer_clang_cl_over_msvc(true)
        .include(runtime)
        .include(csrc)
        .include("include")
        .include(&rdf_inc)
        .include(&std_inc)
        .define("SLOP_ARENA_NO_CAP", None)
        .define("SLOP_INTERN_THREADSAFE", None)
        // The release CLI's flags (Makefile RELEASE_CFLAGS), so the crate
        // runs the engine as built and tested for release. Pinned here
        // rather than taken from the host's profile: a debug build of the
        // host still gets an optimised engine. Measured 2026-10-14 against
        // -O2 and 4096 buckets: 0-3% faster, reports identical.
        .define("SLOP_INTERN_BUCKET_COUNT", Some("65536"))
        .opt_level(3)
        .warnings(false);
    for src in &sources {
        build.file(src);
    }
    // The engine's C includes the public API (src/howl.slop's `:c-name`
    // functions). Only the layout probes are hand-written C: they report
    // include/howl.h's ABI to the mirror guards in src/ffi.rs.
    build.file("layout_probes.c");
    build.compile("howl_c");

    // The runtime threads through pthreads on POSIX and Win32 on Windows.
    if env::var("CARGO_CFG_TARGET_OS").as_deref() != Ok("windows") {
        println!("cargo:rustc-link-lib=pthread");
    }
    println!("cargo:rerun-if-changed=layout_probes.c");
    println!("cargo:rerun-if-changed=include");
    println!("cargo:rerun-if-changed=csrc");
}
