use std::env;
use std::path::Path;

fn main() {
    let csrc = Path::new("csrc/src");
    let runtime = Path::new("csrc/runtime");

    // Shared rdf/std headers and symbols come from the -sys crates.
    // Vendoring our own copy would collide on duplicate symbols for any
    // consumer that links both.
    let rdf_inc = env::var("DEP_SLOP_RDF_INCLUDE").expect("slop-rdf-sys must be a dependency");
    let std_inc = env::var("DEP_SLOP_STD_INCLUDE").expect("slop-std-sys must be a dependency");

    // Only HOWL's own modules.
    let sources = [
        "slop_types.c",
        "slop_el.c",
        "slop_classify.c",
        "slop_saturate.c",
        "slop_select.c",
        "slop_normalize.c",
        "slop_howl.c",
    ];

    let mut build = cc::Build::new();
    build
        .include(runtime)
        .include(csrc)
        .include(&rdf_inc)
        .include(&std_inc)
        .define("SLOP_ARENA_NO_CAP", None)
        .define("SLOP_INTERN_THREADSAFE", None)
        .opt_level(2)
        .warnings(false);
    for src in &sources {
        build.file(csrc.join(src));
    }
    // Keeps the howl_arena_* wrappers and the howl_layout_* ABI probes.
    build.file("csrc_shim.c");
    build.compile("howl_c");

    println!("cargo:rustc-link-lib=pthread");
    println!("cargo:rerun-if-changed=csrc_shim.c");
    for src in &sources {
        println!("cargo:rerun-if-changed={}", csrc.join(src).display());
    }
    println!(
        "cargo:rerun-if-changed={}",
        runtime.join("slop_runtime.h").display()
    );
}
