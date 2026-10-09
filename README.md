# HOWL

**HOWL classifies OWL ontologies.** Given an ontology in Turtle, it computes the complete
subsumption hierarchy, finds every unsatisfiable class, and says whether the ontology is coherent.
That includes the subsumptions that follow from *defined* classes, which forward-chaining (OWL 2 RL)
materialization cannot see:

```turtle
:Parent owl:equivalentClass [ owl:intersectionOf ( :Person [ owl:onProperty :hasChild ; owl:someValuesFrom :Person ] ) ] .
:Mother rdfs:subClassOf     [ owl:intersectionOf ( :Person [ owl:onProperty :hasChild ; owl:someValuesFrom :Person ] ) ] .
```

From these two axioms HOWL derives `Mother ⊑ Parent`. The only route to that conclusion runs through
the existential on `Parent`'s *defining* side, so a rule engine that materializes forward never
finds it.

HOWL is a consequence-based reasoner for the OWL 2 EL family. It is written in
[SLOP](https://github.com/slop-lang/slop) and compiled to C. It is the sibling of
[GROWL](https://github.com/Trivyn/growl), which materializes OWL 2 RL; the two compose through RDF.

## Quick start

Each [GitHub release](https://github.com/Trivyn/howl/releases) has the `howl` binary and the C
library for linux-x86_64 and macos-arm64. From Rust, use the
[`howl-reasoner`](https://crates.io/crates/howl-reasoner) crate ([below](#rust)). Anywhere else,
HOWL builds from the committed C with nothing but a C compiler:

```sh
make                 # builds ./build/howl
./build/howl validate ontology.ttl
./build/howl --version
```

```
$ howl validate corpus/fixtures/v0/litmus.ttl
howl: 10 subsumptions, 0 unsatisfiable, 0 omitted
howl: coherent                                                    # exit 0

$ howl validate corpus/fixtures/v0/negation-superclass.ttl
howl: 11 subsumptions, 1 unsatisfiable, 0 omitted
howl: INCOHERENT                                                  # exit 1

$ howl validate corpus/fixtures/out-of-profile/union.ttl
howl: 7 subsumptions, 0 unsatisfiable, 1 omitted
  omitted: SubClassOf(http://example.org/t#C ObjectUnionOf(http://example.org/t#A http://example.org/t#B))
howl: INCONCLUSIVE — coverage gaps, this is NOT a pass            # exit 2
```

Add `--report` for the full result: the hierarchy, each unsatisfiable class and each omission, one
per line.

An import that isn't supplied is a coverage gap too, and `--strict` turns any gap into a refusal:

```
$ howl validate corpus/fixtures/hazards/unattested-import.ttl
howl: 6 subsumptions, 0 unsatisfiable, 1 omitted
  omitted: UnresolvedImport(http://example.org/does-not-exist)
howl: INCONCLUSIVE — coverage gaps, this is NOT a pass            # exit 2

$ howl validate corpus/fixtures/out-of-profile/union.ttl --strict
howl: refused (--strict), no report — 1 omitted
  omitted: SubClassOf(http://example.org/t#C ObjectUnionOf(http://example.org/t#A http://example.org/t#B))
                                                                  # exit 2
```

## Verdicts and exit codes

| Exit | Verdict | Meaning |
|---|---|---|
| `0` | coherent | Checked completely, and nothing is wrong. **The only pass.** |
| `1` | incoherent | The ontology is inconsistent, or a named class is unsatisfiable. |
| `2` | inconclusive | Something could not be checked: an axiom HOWL does not reason over, an import you did not supply, or the round budget ran out. **Not a pass.** |
| `3` | error | A usage, parse or I/O failure. |

**Treat exit 0 alone as a pass.** A CI job that accepts `2` passes ontologies HOWL never fully
checked. Don't fold `2` into `1` either, or every ontology that uses an unsupported construct looks
broken.

**A finding beats incomplete coverage.** Adding back an omitted axiom can only add conclusions; it
never retracts one. So an incoherence found while part of the ontology was set aside is still an
incoherence, and HOWL reports `1`, not `2`. Only the *absence* of a finding needs complete coverage.

HOWL never silently drops what it cannot reason over. Every such axiom is listed as an omission, and
any omission makes an otherwise clean run inconclusive.

## Using the CLI

```
howl validate <ontology.ttl> [--profile P] [--strict] [--no-imports] [-I FILE]...
                             [--report] [--timings] [--max-iterations N] [--workers N]
howl --version
```

- **`-I FILE`** loads an imported document and attests it. HOWL never fetches anything, so each
  `owl:imports` target must be passed as a file. One that isn't stays an omission
  (`UnresolvedImport`), and the run is inconclusive. The file must declare its `owl:Ontology` IRI,
  and its blank nodes are kept apart from the root document's.
- **`--profile P`** picks the logic to reason in:

  | Profile | Logic | Status |
  |---|---|---|
  | `el` (default) | ELH⊥R+: EL with role hierarchies, ⊥, transitive roles and property chains, domains and ranges, ABox assertions, and `¬` in a superclass, domain or range | built |
  | `el++` | the OWL 2 EL object fragment: `el` plus nominals, `hasValue`, `hasSelf`, reflexive roles, individual equality and inequality, and negative assertions | built |
  | `auto` | the cheapest built profile that covers the whole ontology (else the one omitting the fewest axioms) | built |
  | `sriq` | the SRIQ object fragment with an ABox: `el` plus inverses, `∀`, unions, full negation, qualified cardinalities and every OWL 2 DL property characteristic ([SPEC §5.5](SPEC.md#55-the-sriq-calculus)) | specified, not yet built; asking for it exits 3, and HOWL never runs another profile in its place |

  The report names the profile that ran. Both built profiles run in polynomial time. `horn-sriq`
  was dropped from the plan, since `sriq` covers its language at the same cost; asking for it exits
  3 with a message saying so.
- **`--no-imports`** records that leaving the imports out is deliberate. It changes nothing in the
  result: an unattested import is still an omission, and the run still inconclusive.
- **`--strict`** refuses to run at all if anything would be omitted (exit 2, no report).
- **`--report`** prints the canonical report instead of the summary. It holds nothing that depends
  on the machine or the run (no timings, paths or worker counts), so it is byte-identical across
  runs and worker counts, and safe to hash or diff.
- **`--workers N`** (1–64, default 4) sets the number of worker threads. It never changes the result.
- **`--max-iterations N`** (0–10000, default 1000) caps the reasoning rounds. A run that hits the cap
  is inconclusive, unless it has already found an incoherence (which stands, exit 1).
- **`--timings`** prints phase durations and peak memory to stderr, never into the report.

## What HOWL reasons over

**HOWL tracks OWL 2 EL construct by construct.** Of the 23 rows in
[`docs/coverage.md`](docs/coverage.md), `el++` reasons over 21 and `el` over 14. They are:
- **class constructors:** intersection, existential and `hasValue` restrictions, single-individual
  nominals and `hasSelf`;
- **TBox and RBox axioms:** class and property inclusions, equivalences, disjointness, chains,
  transitivity, domains and ranges, reflexivity, the bottom property, and the top property as a
  super-role;
- **assertions:** class, property, equality, inequality and negative property assertions.

**What HOWL reports as omitted instead:**
- `HasKey`;
- datatypes and data properties (a deliberate non-goal);
- anything outside OWL 2 EL, such as unions, universal restrictions, cardinalities and inverse
  properties. These belong to the planned `sriq` profile.

The construct-by-construct table, and the evidence behind each profile, is in
[`docs/coverage.md`](docs/coverage.md).

## Embedding HOWL

### C

`make lib` builds `build/libhowl.a`, and `make lib dist PLATFORM=<name>` packages it with its header
as `libhowl-<name>.zip`. The API is `include/howl.h`. Link with `-lpthread`.

```c
#include "howl.h"

howl_Input in = howl_input_new();
howl_TurtleResult parsed = howl_input_add_turtle(in, (slop_string){ len, text });
howl_Run run = howl_run_classify(in, howl_default_options());

if (howl_run_ok(run) && howl_run_verdict(run) == types_Verdict_verdict_coherent) {
    /* the only pass */
}
for (int64_t i = 0; i < howl_run_unsat_len(run); i++) {
    slop_string c = howl_run_unsat(run, i);   /* valid until howl_run_free */
}

howl_run_free(run);
howl_input_free(in);
```

[`examples/c/classify.c`](examples/c/classify.c) is a complete program. Things to know:

- **Inputs and runs are opaque handles.** An input can hold several documents (each `add` call is
  one), and each document keeps its own blank nodes. `howl_input_attest_import` plays the role of
  `-I`.
- **Strings.** Every string a run returns stays valid until `howl_run_free`. Strings you pass in are
  copied before the call returns.
- **A run with no result** (`howl_run_ok` is false) says why through `howl_run_fault`: it was
  cancelled, the input was in error, the profile isn't built, or an option was out of range. Its
  verdict reads inconclusive.
- **Cancellation.** Point `options.cancel` at a `uint32_t`. Setting it non-zero stops the run at the
  next round boundary. HOWL never reads a clock, so timeouts are yours.
- **Threads.** Distinct inputs and runs may be used from different threads at once.

The library always runs as the CLI does without `--strict`: an omission is reported, never refused.

### Rust

The [`howl-reasoner`](https://crates.io/crates/howl-reasoner) crate wraps the C API in a safe
interface whose results are owned Rust values. It builds the engine from vendored C, so it needs a C
compiler but no SLOP toolchain.

```sh
cargo add howl-reasoner
```

The crate is imported as `howl` (the name `howl` on crates.io belongs to an unrelated crate):

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

[`rust/README.md`](rust/README.md) covers input, the report, cancellation and threads. The API
reference is on [docs.rs](https://docs.rs/howl-reasoner).

## Performance

Classification time against [ELK](https://github.com/liveontologies/elk-reasoner), the standard
OWL 2 EL reasoner, on two large biomedical ontologies. Measured on an Apple M3 Ultra with 4 workers,
median of 5 runs, and both sides timed from axioms in hand to finished taxonomy:

| Ontology | HOWL `el` | HOWL `el++` | ELK | HOWL peak memory (`el`) |
|---|---|---|---|---|
| Gene Ontology (2026-07-26) | 0.38 s | 0.59 s | 0.46 s | 0.57 GB |
| EL-GALEN | 0.82 s | 1.44 s | 0.28 s | 0.59 GB |

Every timed run reproduced the certified result. Each ontology's in-profile part is checked against
ELK or HermiT over every pair of named classes. The protocol, history and memory figures are in
[`docs/performance.md`](docs/performance.md).

## Status

**Beta.** The `el` and `el++` profiles are built. Their testing:
- **fixtures:** compared with HermiT, and with ELK where ELK is probed capable of the construct;
- **conformance:** the W3C OWL 2 and ELK conformance suites, against their expected answers;
- **real ontologies:** each of four has its in-profile part compared with its routed oracle (ELK or
  HermiT) over every pair of named classes;
- **generated ontologies:** compared with HermiT.

Results are byte-identical across worker counts. `sriq` is next
([SPEC §5.5](SPEC.md#55-the-sriq-calculus)), with BFO and CCO as its target. `howl classify` (Turtle output
of the inferred hierarchy with `--emit`, and `--reduce`) is planned; until then both flags are
refused with exit 3.

## Documentation

- [`docs/coverage.md`](docs/coverage.md): what each profile reasons over, construct by construct
- [`docs/performance.md`](docs/performance.md): benchmarks and memory
- [`docs/verification.md`](docs/verification.md): contract checking, and the guards on the FFI
- [`rust/README.md`](rust/README.md): the Rust crate
- [`CONTRIBUTING.md`](CONTRIBUTING.md): building, testing and changing HOWL
- [`SPEC.md`](SPEC.md): the full design, approved 2026-08-17. `spec/human/` has PDF renderings,
  including a 6-page brief.

## License

[Apache 2.0](LICENSE).
