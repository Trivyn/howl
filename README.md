# HOWL

**A consequence-based description-logic reasoner in SLOP — sibling to [GROWL](../growl).**

GROWL *materializes* an OWL 2 RL ontology (forward-chaining, edge enrichment). HOWL *classifies* a
description logic — it computes the complete subsumption hierarchy and consistency of a TBox,
including the defined-class subsumptions that RL materialization cannot see. The two compose through
RDF: HOWL classifies → emits inferred `subClassOf` → GROWL materializes/enriches.

- **GR-OWL / H-OWL** — the RL engine and the DL engine. "HOWL = **Horn OWL**" is apt: the first two
  targets (CB-EL, Horn-SHIQ) are Horn fragments.
- **Design:** [`SPEC.md`](./SPEC.md) — approved 2026-08-17.

## Status: the calculus runs; the front end does not

**HOWL derives `Mother ⊑ Parent`** — the [§3.1](./SPEC.md#31-the-litmus-test-also-the-v0-acceptance-criterion)
litmus, and the line between a DL reasoner and a materialization engine. CR1–CR7, the
barrier-synchronized driver, and hierarchy extraction all work, driven from hand-normalized
`NormAxiom` fixtures.

**There is still no front end**, so `classify` returns a `Fault` rather than a report: nothing yet
parses Turtle, gates against [§5.2](./SPEC.md#52-the-exact-v0-language), or normalizes.

That refusal is deliberate and it is the safety-relevant choice, and it outlives the rules landing.
Without the gate there is nothing to populate `coverage.omitted`, so a report handed back now would
present as full coverage, a reached fixpoint, and whatever the rules found — which the verdict rule
reads as a clean **coherent**. Sound, catastrophically incomplete, and indistinguishable from success
at every interface. The engine stays unable to express a verdict until it can also say what it
could not see.

| Milestone | Scope | State |
|---|---|---|
| M0 | types, front end, normalization | types done; front end stubbed |
| M1 | CR1–CR7, driver, verdict discipline | rules + driver + extraction done; litmus green |
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
  test.slop       test harness — verdict discipline, then the reasoning fixtures
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

`make verify` discharges **23 contracts, 0 failing**. The boundary is not obvious, it is not
documented upstream, and every row below was established by *probing* — writing the minimal pair of
functions that differ in one construct and seeing which verifies. Recorded here so it is not
rediscovered a third time.

| Works | Does not |
|---|---|
| Record fields — **including `Bool`** — and `list-len` | **`or` / `and` in a function BODY** — makes the return value opaque |
| `(@post (implies {braced} {$result == X}))` | **`@property` quantifying over a push-built `$result`** — fails outright, *and* makes any `@post` on the same function fail |
| `match` in a `@post`, enum-valued results | **A loop in the body** — `$result` becomes opaque |
| `while` loops, with or without `@loop-invariant` | **`if` between two `record-new`s** — loses field projection on `$result` |
| A single unconditional `record-new` — fields stay visible | `const` values — opaque, so `{$result == EXIT_ERROR}` cannot be proved |
| A guarded push inside a `match` arm — bounds like `<= 1` prove | `set-elements`, `list-get` — uninterpreted functions |
| `(Int 0 ..)` fields — interpreted, unlike `set-elements` | Reasoning **across a call** |

Four consequences worth knowing before writing a contract:

**Expression shape decides provability, and the culprit is `or`/`and` — not the data.** Two functions
with an identical contract, one bodied `(or (. r b) (> (. r n) 0))` and one bodied
`(if (. r b) true (> (. r n) 0))`, differ: the first fails with a counterexample, the second
verifies. A boolean *record field* is perfectly visible to the prover; a boolean *operator* in the
body is what makes the result opaque. `findings-are-incoherent` and `entails-sub` are both written as
`if` chains for exactly this reason. Reach for `if` before concluding something is unverifiable.

**One push site, not two exclusive ones.** `cr-and-on-sub` fires from either conjunct of `B₁ ⊓ B₂ ⊑ A`
and emits at most one message. Written as two branches that each `list-push`, the bound `<= 1` fails
with a two-element counterexample — the checker assumes both can fire. Written as a flag set in either
branch and a single push, it proves. Same semantics, same message count.

**Adding a `@property` can break a `@post` that was passing.** This one is genuinely surprising and
cost real time. A `@property (forall (m $result) …)` over a list built with `list-push` does not
merely go *unknown* — it **fails**, and its presence causes the sibling `@post` on the same function
to fail too. The per-rule faithfulness properties were removed for this reason and the obligation
moved to `OWED` plus fixtures; GROWL's equivalents survive because they come back *unknown*, which is
not a failure.

**There is no interprocedural reasoning.** A callee is an uninterpreted function, so a property that
depends on what a helper returns is unprovable — the counterexample says so literally
(`fn_outcome-is-complete_1=[else -> True]`). `verdict` keeps a *redundant* local coverage check for
exactly this reason, and `advance-round` deliberately does **not** restate the round-count contract
that `round-commit` proves. Where the fact must cross a loop rather than a call, `@loop-invariant`
carries it: `saturate` proves `iteration <= max-iterations` that way.

**Prefer a type over a contract where the shape allows it.** `emit-edge` takes a `LogicalEdge` and
returns an `EdgePair`, so "both halves exist" is enforced by construction and each half's destination
is a provable field access. As a list it needed `list-get`, which is uninterpreted — unprovable, and
only testable.

**Obligations that cannot be discharged are marked `OWED` in-source, with the reason**, and covered
by test meanwhile. Two are outstanding: the per-rule faithfulness pairs (`src/rules/el.slop`) and the
undefined-not-empty rules (`src/classify.slop`). No vacuous contracts stand in:
`(list-len $result) >= 0` is true of every possible implementation and would only make the summary
look fuller than it is. Stating a postcondition the prover cannot discharge is worse than stating
none, because it reads as coverage — and because a red `make verify` destroys the signal from every
contract that *does* hold.

The contracts and tests are mutation-tested. Removing `verdict`'s coverage check, inverting a
`@property`, dropping an arm of `findings-are-incoherent`, skipping the `\ Sₙ` novelty test, dropping
either of CR4's two handlers, failing to commit the seeds into the store, or removing the
`owl:Nothing` exclusion each make a specific gate go red. That last exercise is not ceremonial: it
found that `cr-exists-lhs-on-sub` was covered by **no test at all**, because both the litmus and the
co-arrival fixture happen to let CR4's *other* handler close them. `test-late-subsumer-still-concludes`
exists because of that finding.

## SLOP facts that shaped the implementation

Three properties of the toolchain are load-bearing here and none are obvious from the source:

**`(Set T)`/`(Map K V)` are pointers; `(List T)` is a value struct.** Mutating a Set or Map field
reached through a `map-get` copy is visible in the map; `list-push` on a List field of that same copy
updates only the copy's `len`, and if `cap` allows it writes into the shared buffer past the stored
length. This is why `Context` no longer carries a queue, why rules never take an accumulator
parameter, and why `round-commit` writes a queue into its map only after every push.

**Multi-payload union variants compare only their FIRST payload.** The transpiler registers one
payload type per variant and emits no multi-field branch, so a `(Set Derived)` would treat
`(derived-succ r Y₁)` and `(derived-succ r Y₂)` as **equal** and swallow every filler after the first.
It compiles clean and under-derives in silence. `Derived`, `Concept` and `NormAxiom` are therefore
never Set elements or Map keys — the driver keys its round delta on `Node`/`RoleId` only.

**A `Map` or `Set` may not appear in a function signature, and a set element must be an lvalue.**
Neither is documented; the first is an "Unknown type" at check time and the second a "cannot take the
address of an rvalue" at compile time. Both are loud, which is the only reason they are footnotes
rather than entries in the list above.

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
