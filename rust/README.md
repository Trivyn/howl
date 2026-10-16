# howl-reasoner

Rust bindings for [HOWL](https://github.com/Trivyn/howl), a consequence-based description-logic
reasoner. HOWL classifies a TBox, giving its coherence, its unsatisfiable classes and its full
subsumption hierarchy. That includes the defined-class entailments that OWL 2 RL materialization
cannot see.

The crate builds the engine from vendored C. It needs a C compiler and pthreads, and no SLOP
toolchain. The RDF and runtime C come from [`slop-rdf-sys`](https://crates.io/crates/slop-rdf-sys)
0.6 and [`slop-std-sys`](https://crates.io/crates/slop-std-sys) 0.5.

## Quick start

```sh
cargo add howl-reasoner
```

The library is imported as `howl`:

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
a false one. An attested IRI whose triples were never added passes silently. Attest the ontology
IRI: an import that names its `owl:versionIRI` instead resolves too, as long as the added document
declares that version.

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
- `omission_details()`: the same omissions, in the same order, as `Omission` values. Each has a
  `kind` (the head token, such as `SubClassOf` or `MissingDeclaration`), an `entity_kind` for a
  `MissingDeclaration`, a `document`, and the `text`. `document` is `Document::Input(i)` when the
  `i`-th `add_*` call introduced it (counting from 0), or `None` when no single document did. With a
  background ontology added before your own document, this is how you tell your coverage gaps from
  the background's without a second run.
- `termination` and `rounds`.
- `lines()`: the canonical report, the bytes `howl validate --report` prints, then the probe lines
  when a query was asked.
- `probes`, `probe_inconsistent` and `probe_omissions`: the answers to probe queries (below).
  `probe_omission_details()` places each probe-run omission in an input document
  (`Document::Input(i)`) or a probe document (`Document::Probe(i)`, counting `add_probe_*` calls).

Every list is in the engine's canonical order. The report is identical at every worker count, so it
can be hashed.

The verdict is asymmetric. A finding is definitive at any coverage, because restoring an omitted
axiom can only add conclusions. Only the absence of a finding needs complete coverage.

The library always runs non-strict: an out-of-profile axiom is reported as an omission, never
refused. Asking for a rung that is not built yet (`Sriq`) returns `Fault::ProfileUnavailable`. It
is never run as another rung. `HornSriq` was dropped from the ladder: it is deprecated, always
refused the same way, and kept only so the C enum is not renumbered. `Profile` is
`#[non_exhaustive]`, so a later rung can be added without breaking your matches.

## Probe queries

Ask whether a named class is unsatisfiable, or whether one is subsumed by another, without adding
anything to the report. Classes made up for the purpose go in a probe document, which the main run
never sees:

```rust
use howl::{Answer, Query};

input.add_probe_turtle(r#"
    <urn:probe:1> <http://www.w3.org/2000/01/rdf-schema#subClassOf> [
        a <http://www.w3.org/2002/07/owl#Restriction> ;
        <http://www.w3.org/2002/07/owl#onProperty> <http://example.org/p> ;
        <http://www.w3.org/2002/07/owl#someValuesFrom> <http://www.w3.org/2002/07/owl#Thing> ] .
"#)?;
input.ask_unsatisfiable("urn:probe:1");   // can :p have a value?
input.ask_subsumed("http://example.org/A", "http://example.org/B");

let report = Reasoner::new().classify(&input)?;
for p in &report.probes {
    println!("{:?}: {:?}", p.query, p.answer);
}
```

A second classification answers them: the input, the probe documents, and a class declaration for
every class a query names, so a queried class never needs declaring (any other class a probe
document introduces does, as in any document). The main report is exactly the
report without probes: probe classes never reach `unsatisfiable`, `subsumptions`, `omissions` or
the verdict.

- `report.probes` has each query once, in canonical order.
- `Answer::Yes`: the inclusion is entailed. A `Yes` holds even when the probe run was incomplete.
- `Answer::No`: it is not entailed, and the probe run was complete.
- `Answer::Unknown`: anything else, for example an omission in the probe run
  (`report.probe_omissions`) or the round budget running out.
- `report.probe_inconsistent`: an inconsistent probe run entails everything, so every answer is a
  vacuous `Yes`.

### Answers alone (`howl ask`)

When you need only the answers, `Reasoner::answer` runs the probe run alone, with no main
classification before it, over only the queries' ⊥-locality module: one small classification
instead of two of the whole input. (When the module's run falls short, the whole input is
classified too.) It gives every `Yes` and `No` that `classify` puts in
`report.probes`. Because an omission outside the module no longer counts, it may answer `Yes` or
`No` where `classify` says `Unknown`:

```rust
let answers = Reasoner::new().answer(&input)?;
for p in &answers.probes {
    println!("{:?}: {:?}", p.query, p.answer);
}
```

- `answers.probes`, `answers.inconsistent`, `answers.omissions` and `answers.omission_details()`
  mean what `report.probes`, `report.probe_inconsistent`, `report.probe_omissions` and
  `report.probe_omission_details()` do.
- `answers.profile` is the profile the probe run ran. Under `ProfileSelection::Auto` the probe
  documents can move it. It is `None` when nothing was asked, so nothing ran.
- `answers.lines()` are what `howl ask` prints: `profile P`, then the probe lines.
- There is no verdict: an answer run makes no claim about the ontology's coherence.

## Cancellation

HOWL never reads a clock, so a timeout is the host's job. Pass a `CancelToken` to
`classify_cancellable` (or `answer_cancellable`) and call `cancel()` from your watchdog. The engine checks the token at each
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
term, a Turtle result, a termination, `slop_string`) and its enum values, among them an
omission's entity kind and document source. Tests assert each
mirror's sizes, offsets and field widths, and every enum value, against the generated header
(`layout_probes.c`). The build fails if HOWL's C and the `-sys` crates' C were generated for
different SLOP runtime ABIs: every generated header checks `SLOP_RUNTIME_ABI`.

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
