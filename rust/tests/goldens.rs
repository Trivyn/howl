//! The CLI's committed golden reports, reproduced through this crate.
//!
//! `make golden` pins `howl validate F [--profile el++] --report`
//! followed by `exit N`, for every fixture. An `Input` is encoded as the
//! CLI encodes its files and classified by the same engine path, so each
//! golden must come back byte for byte from `Report::lines()` plus the
//! verdict's exit code. A report that differs is a binding bug: the
//! goldens are already certified against the engine.
//!
//! A golden whose source fixture is missing FAILS, as it does in
//! `make golden`: a gate that passes because its input was absent is the
//! false pass this project exists to prevent.

use howl::{Config, Input, Profile, ProfileSelection, Reasoner};
use std::fs;
use std::path::{Path, PathBuf};

fn corpus() -> PathBuf {
    Path::new(env!("CARGO_MANIFEST_DIR")).join("../corpus")
}

/// The golden's text as `make golden` compares it: `$(cat g)`, which
/// drops the trailing newlines.
fn golden(path: &Path) -> String {
    fs::read_to_string(path)
        .unwrap_or_else(|e| panic!("{}: {e}", path.display()))
        .trim_end_matches('\n')
        .to_string()
}

fn report(docs: &[PathBuf], attested: &[&str], selection: ProfileSelection) -> String {
    let mut input = Input::new();
    for d in docs {
        let text = fs::read_to_string(d).unwrap_or_else(|e| panic!("{}: {e}", d.display()));
        input.add_turtle(&text).unwrap_or_else(|e| panic!("{}: {e}", d.display()));
    }
    for iri in attested {
        input.attest_import(iri);
    }
    let config = Config { selection, ..Config::default() };
    let r = Reasoner::with_config(config)
        .classify(&input)
        .unwrap_or_else(|e| panic!("{}: {e}", docs[0].display()));
    format!("{}\nexit {}", r.lines().join("\n"), r.verdict.exit_code())
}

/// Every `*.report` in `dir`, with the fixture it was captured from:
/// `<subdir>-<name>.report` is `fixtures/<subdir>/<name>.ttl`.
fn goldens_in(dir: &str, subdirs: &[&str]) -> Vec<(PathBuf, PathBuf)> {
    let mut out = Vec::new();
    for entry in fs::read_dir(corpus().join("goldens").join(dir)).unwrap() {
        let g = entry.unwrap().path();
        if g.extension().map_or(true, |e| e != "report") {
            continue;
        }
        let name = g.file_stem().unwrap().to_str().unwrap().to_string();
        let src = subdirs.iter().find_map(|d| {
            name.strip_prefix(&format!("{d}-"))
                .map(|n| corpus().join("fixtures").join(d).join(format!("{n}.ttl")))
        });
        match src {
            Some(s) if s.is_file() => out.push((g, s)),
            _ => panic!("ORPHAN {} (no source fixture)", g.display()),
        }
    }
    out.sort();
    out
}

fn check(goldens: &[(PathBuf, PathBuf)], selection: ProfileSelection) {
    let mut failed = Vec::new();
    for (g, src) in goldens {
        let got = report(std::slice::from_ref(src), &[], selection);
        if got != golden(g) {
            failed.push(g.display().to_string());
        }
    }
    assert!(failed.is_empty(), "{} of {} goldens differ:\n{}", failed.len(), goldens.len(), failed.join("\n"));
}

#[test]
fn el_fixture_goldens() {
    let gs = goldens_in("fixtures", &["out-of-profile", "hazards", "v0", "probes", "el++"]);
    // The directory is a wildcard over what exists: a count this low
    // means the goldens moved, not that there is nothing to check.
    assert!(gs.len() >= 100, "only {} fixture goldens found", gs.len());
    check(&gs, ProfileSelection::Explicit(Profile::El));
}

#[test]
fn el_plus_plus_fixture_goldens() {
    let gs = goldens_in("el++", &["v0", "el++"]);
    assert!(gs.len() >= 50, "only {} el++ goldens found", gs.len());
    check(&gs, ProfileSelection::Explicit(Profile::ElPlusPlus));
}

/// `howl validate root.ttl -I imported.ttl --report`: two documents,
/// the second's blank nodes standardized apart, and its ontology IRI
/// attested.
#[test]
fn imports_golden() {
    let dir = corpus().join("fixtures/imports");
    let got = report(
        &[dir.join("root.ttl"), dir.join("imported.ttl")],
        &["http://example.org/imported"],
        ProfileSelection::Explicit(Profile::El),
    );
    assert_eq!(got, golden(&corpus().join("goldens/imports/root.report")));
}
