# HOWL

**A consequence-based description-logic reasoner in SLOP — sibling to [GROWL](../growl).**

GROWL *materializes* an OWL 2 RL ontology (forward-chaining, edge enrichment). HOWL *classifies* a
description logic — it computes the complete subsumption hierarchy and consistency of a TBox,
including the defined-class subsumptions that RL materialization cannot see. The two compose through
RDF: HOWL classifies → emits inferred `subClassOf` → GROWL materializes/enriches.

- **GR-OWL / H-OWL** — the RL engine and the DL engine. "HOWL = **Horn OWL**" is apt: the first two
  targets (CB-EL, Horn-SHIQ) are Horn fragments.
- **Design:** [`SPEC.md`](./SPEC.md) — approved 2026-08-17.

## Status: scaffolding

The project builds, tests, and verifies. **The reasoning pipeline is not implemented** — `classify`
returns a `Fault`, not a report.

That refusal is deliberate and it is the safety-relevant choice. Every stage exists in skeleton, so a
stub that returned an empty-but-well-formed report would present as full coverage, a reached
fixpoint, and no findings — which the verdict rule reads as a clean **coherent**. Sound,
catastrophically incomplete, and indistinguishable from success at every interface. Until the rules
land, the engine must be unable to express a verdict at all.

| Milestone | Scope | State |
|---|---|---|
| M0 | types, front end, normalization | types done; front end stubbed |
| M1 | CR1–CR7, driver, verdict discipline | verdict + driver shape done; rules stubbed |
| M2a | port amendments A1–A4 | consumer-side, blocking |
| M2b | port adapter | not started |
| M3 | Turtle emission + GROWL round-trip | not started |
| M4 | alignment + minimal repair | not started |

## Build

Mirrors GROWL: a SLOP static library, a separate CLI executable, and a Rust/C FFI layer, depending on
the sibling `../slop-rdf`.

```sh
make          # build the CLI from the committed C in csrc/ — no SLOP toolchain needed
make test     # verdict-discipline and structural-invariant tests
make lib      # static library
make verify   # Z3 contract checking (needs the SLOP toolchain + z3)
make crate-test   # Rust crate, including the FFI layout guards
```

Working on the SLOP sources needs the toolchain:

```sh
make slop-build   # rebuild via slop, refresh include/howl.h
make csrc         # regenerate the committed C — commit the result
```

`csrc/` holds transpiled C so the project builds anywhere a C compiler exists. Regenerate and commit
it whenever SLOP source changes.

## Layout

```
src/
  howl.slop       library root; the verdict rule, stated once
  types.slop      §6.2 data model — tagged nodes, normal form, context-owned saturation
  select.slop     profile detection and calculus dispatch
  normalize.slop  header → decode → gate → normalize → initialize
  saturate.slop   barrier-synchronized semi-naive driver
  classify.slop   hierarchy extraction and findings
  rules/el.slop   CR1–CR7 and the delta-trigger table
  test.slop       test harness
cli/              CLI harness (§9) — exit codes are the verdict table
rust/             FFI layer, with the ABI layout guards
csrc/             transpiled C (committed)
```

## Two things worth knowing before changing anything

**Exit code 0 alone is the pass condition.** `0` coherent, `1` incoherent, `2` inconclusive, `3`
error. A CI job that treats `2` as success reintroduces exactly the hazard the gate exists to
prevent — `2` means *could not check*, not *nothing wrong*. Equally, `2` must not be folded into `1`,
or every ontology with an unsupported construct looks broken and users learn to ignore the gate.

**A finding beats incomplete coverage.** Inference is monotone, so a contradiction derived from part
of an ontology is a contradiction in all of it. An incoherence found under partial coverage is
reported as `1`, not downgraded to `2`. The absence of a finding is what carries no information —
never the presence of one.

## What `slop verify` can and cannot check here

`make verify` discharges **11 contracts, 0 failing**. The boundary is not obvious and was mapped by
probing, so it is written down rather than left to be rediscovered:

| Works | Does not |
|---|---|
| Record fields — **including `Bool`** — and `list-len` | **`or` / `and` in a function BODY** — makes the return value opaque |
| `(@post (implies $result {braced}))` | `(@property ...)` containing `implies` **with braces** — fails to translate |
| `(@post (implies {braced} {$result == X}))` | `const` values — opaque, so `{$result == EXIT_ERROR}` cannot be proved |
| `match` in a `@post`, enum-valued results | `set-elements`, `list-get` — uninterpreted functions |
| `while` loops, with or without `@loop-invariant` | Reasoning **across a call** |

Three consequences worth knowing before writing a contract:

**Expression shape decides provability, and the culprit is `or`/`and` — not the data.** Two functions
with an identical contract, one bodied `(or (. r b) (> (. r n) 0))` and one bodied
`(if (. r b) true (> (. r n) 0))`, differ: the first fails with a counterexample, the second
verifies. A boolean *record field* is perfectly visible to the prover; a boolean *operator* in the
body is what makes the result opaque. `findings-are-incoherent` is written as an `if` for exactly
this reason. Reach for `if` before concluding something is unverifiable.

**There is no interprocedural reasoning.** A callee is an uninterpreted function, so a property that
depends on what a helper returns is unprovable — the counterexample says so literally
(`fn_outcome-is-complete_1=[else -> True]`). `verdict` keeps a *redundant* local coverage check for
exactly this reason. Where the fact must cross a loop rather than a call, `@loop-invariant` carries
it: `saturate` proves `iteration <= max-iterations` that way, even though both calls in its loop are
opaque.

**Prefer a type over a contract where the shape allows it.** `emit-edge` returns an `EdgePair`
record rather than a two-element list, so "both halves exist" is enforced by construction and the
destinations become provable field accesses. As a list it needed `list-get`, which is uninterpreted
— unprovable, and only testable.

**Obligations that cannot be discharged are marked `OWED` in-source, with the reason**, and covered
by test meanwhile. No vacuous contracts: `(list-len $result) >= 0` is true of every possible
implementation and would only make the summary look fuller than it is. Stating a postcondition the
prover cannot discharge is worse than stating none, because it reads as coverage.

The contracts are mutation-tested — removing `verdict`'s coverage check, inverting a `@property`, or
dropping an arm of `findings-are-incoherent` each make `make verify` fail.

## The FFI layout guards

`rust/src/ffi.rs` hand-mirrors C structs the SLOP transpiler generates. Those definitions live in
another repository and change without notice, so the mirrors are asserted against the real ABI in
tests (`make crate-test`) rather than maintained by care.

This is not hypothetical. GROWL 0.6.0 shipped a wrong-offset FFI read: a dependency added a field to
a struct embedded by value in another, every following field shifted, the Rust mirror was not
updated, and `graph.size()` returned a garbage pointer. Nothing failed loudly.

The guards check sizes, offsets, **and field widths**. The last one is not redundant: SLOP range
types lower to narrow integers (`(Int 1 .. 64)` → `uint8_t`), and widening one on the Rust side can
be absorbed entirely by struct padding — leaving every offset and the total size identical while the
Rust side reads padding into the high bits of the value. That gap was found by deliberately drifting
a mirror to check the guards actually bite.

## Read next

[**`SPEC.md`**](./SPEC.md) — the full design: calculus choice, the exact v0 language, data model,
verification posture, the MOOSE port, milestones, and the "when is it actually a DL reasoner?"
threshold. `spec/human/` has PDF renderings, including a 6-page condensed version.
