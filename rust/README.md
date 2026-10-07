# howl

Rust bindings for [HOWL](https://github.com/Trivyn/howl), a consequence-based description-logic
reasoner. HOWL classifies a TBox, giving its coherence, its unsatisfiable classes and its full
subsumption hierarchy. That includes the defined-class entailments that OWL 2 RL materialization
cannot see.

The crate builds the engine from vendored C. It needs a C compiler and pthreads, and no SLOP
toolchain. The RDF and runtime C come from [`slop-rdf-sys`](https://crates.io/crates/slop-rdf-sys)
0.5.0 and [`slop-std-sys`](https://crates.io/crates/slop-std-sys) 0.4.0.

## Quick start

```rust
use howl::{Input, Reasoner, Verdict};

let mut input = Input::new();
input.add_turtle(&std::fs::read_to_string("ontology.ttl")?)?;

let report = Reasoner::new().classify(&input)?;
match report.verdict {
    Verdict::Coherent => println!("coherent"),
    Verdict::Incoherent => println!("unsatisfiable: {:?}", report.unsatisfiable),
    // NOT a pass: something was omitted, or the run stopped early.
    Verdict::Inconclusive => println!("omitted: {:?}", report.omissions),
}
```

## Input

An `Input` holds one or more documents. Each `add_turtle` or `add_triples` call adds one document.
Every document after the first has its blank nodes kept apart from the earlier ones, as
`howl validate ROOT -I IMPORT` does. In `add_triples`, a `Term::Blank` label is scoped to its
document, as in Turtle.

`attest_import(iri)` is the caller's statement that an `owl:imports` target is resolved: its
document has been added. HOWL never fetches anything. A declared import that is not attested is a
coverage gap, so the run is `Inconclusive`. The check catches a forgotten import, but it cannot catch
a false one. An attested IRI whose triples were never added passes silently.

A document that fails to parse returns `Fault::InputError`, and so does every later `classify` of
that input, because the triples before the error were already added.

Choose the profile with `Config::selection`: `ProfileSelection::Explicit(Profile::El)` (the
default), `Explicit(Profile::ElPlusPlus)`, or `Auto`.

## Report

`Reasoner::classify(&input)` returns a `Report` or a `Fault`. Classifying does not consume the
input. The `Report` holds:

- `profile`: the rung that ran (`El` by default; `Auto` picks the cheapest built rung that covers
  the whole ontology).
- `verdict`: computed by the engine, never in Rust.
- `inconsistent` and `unsatisfiable`.
- `subsumptions` as `(sub, super)` pairs.
- `omissions`: what the run did not cover. They are never dropped, and any omission makes an
  otherwise clean run `Inconclusive`.
- `termination` and `rounds`.
- `lines()`: the canonical report, the bytes `howl validate --report` prints.

Every list is in the engine's canonical order. The report is identical at every worker count, so it
can be hashed.

The verdict is asymmetric. A finding is definitive at any coverage, because restoring an omitted
axiom can only add conclusions. Only the absence of a finding needs complete coverage.

The library always runs non-strict: an out-of-profile axiom is reported as an omission, never
refused. Asking for a rung that is not built yet (`HornSriq`, `Sriq`) returns
`Fault::ProfileUnavailable`. It is never run as another rung.

## Cancellation

HOWL never reads a clock, so a timeout is the host's job. Pass a `CancelToken` to
`classify_cancellable` and call `cancel()` from your watchdog. The engine checks the token at each
round boundary and returns `Fault::Cancelled`. A cancelled run carries no partial result, because
where it stopped depends on scheduling.

## Threads

`Reasoner` and `Report` are `Send + Sync`. `Input` is `Send` but not `Sync`. Separate inputs can be
classified concurrently. The engine also runs its own worker threads (`Config::worker_count`).

## The FFI

The crate binds HOWL's public C API. That API is written in SLOP (the `:c-name` functions in
`src/howl.slop`), and slop generates its header, `include/howl.h`. The engine's result never crosses
the FFI as a struct: it stays behind an opaque run handle, and the crate copies it out through the
API's accessors, then frees it. Rust mirrors only the API's small value types (options, an input
term, a Turtle result, a termination, `slop_string`) and its enum values. Tests assert each
mirror's sizes, offsets and field widths, and every enum value, against the generated header
(`layout_probes.c`). `build.rs` refuses to build if HOWL's `slop_runtime.h` differs from the one
`slop-std-sys` ships.

## Minimum Rust version

1.63. The latest `cc` needs a newer Rust, so on 1.63 resolve dependencies with
`CARGO_RESOLVER_INCOMPATIBLE_RUST_VERSIONS=fallback cargo generate-lockfile` on a recent Cargo
first.

## Tests

From the HOWL repository, run `make crate-test`. It vendors the C and runs `cargo test`:

- the layout guards;
- the binding's API tests;
- every committed golden report, reproduced byte for byte through this crate.

## License

Apache-2.0.
