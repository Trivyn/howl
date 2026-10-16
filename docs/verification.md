# Verification

HOWL's tests are backed by three other checks. This page covers them:

- Z3 contract checking with `slop verify`
- the SLOP runtime behaviour the implementation relies on
- the layout guards on the C API and the Rust crate

The overall testing strategy is in [SPEC §10](../SPEC.md#10-testing-strategy), and the policy on
contracts is in [SPEC §7](../SPEC.md#7-verification--contracts).

## Summary

| Check | Result |
|---|---|
| `make verify` | 90 functions verified, 0 failing, 0 unknown (last recorded 2026-10-08) |
| `make example` | 103 executable examples, all passing |
| `el++` rule contracts under mutation | 112 mutants: 111 refuted, 1 unknown, none verified |

CI runs `make verify`, but the step is non-blocking.

This page covers the `el` and `el++` engines. The `sriq` engine's contracts, and what its tests hold
instead, are listed per component in SPEC's verification table under
[§7](../SPEC.md#7-verification--contracts).

## What is proved

**Round caps.** Both saturation loops prove they stop at their budget:

- `saturate` (`el`) proves `iteration <= max-iterations`.
- `run-ksc` (`el++`) proves `rounds <= budget`.

Each proof goes through a checked `@loop-invariant` and a contract that a single call does exactly
one round. Both loops are written so slop's loop analysis can follow them. The cancel flag is read
through a function, `cancel-requested`, rather than inline
([#280](https://github.com/slop-lang/slop/issues/280)). `el`'s loop has no `break`. The functions the
loops call take counts, not the whole `Saturation`.

**Profile selection.** Each of these contracts was also seen to fail under a mutation.

- `select-profile` maps an explicit profile request to exactly that profile, and leaves `auto` to
  the ontology.
- `profile-implemented` accepts `el`, `el++` and `sriq`.
- `profile-dropped` holds for `horn-sriq` and nothing else.
- `choose-auto` proves `auto`'s rule over three rungs. It picks `el` when `el` omits nothing,
  otherwise the rung that omits fewest, with ties going to the earlier rung.
- `choose-auto-low` proves the same rule over `el` and `el++`, for the step-down.
- `default-config` selects `el`, with the clause budget at 500,000.

**The `el` completion rules.** Each of the five loop-free rules proves a faithfulness pair:

- `sound`: nothing is emitted that the rule does not license.
- `complete`: nothing the rule licenses is left out.

That is 11 properties in all. Each one stopped verifying when its rule's body was mutated.

**The `el++` rules** (`src/rules/ksc.slop`) go further. There are 26 per-instance functions, one
for each rule of [Krö10] Fig. 3 that `el++` uses plus Theorem 2's seed (\*).

- All 26 prove `complete`: the rule fires whenever its body matches.
- All 26 prove `head`: the conclusion is the rule's head over the premises' own terms.
- The 24 that can decline to fire also prove `sound`: they fire only when the body matches.
- Rule (4)'s ⊥ flag proves its `@post`.

One join combinator, `ksc-join`, applies rules over stored partners. It proves both directions
through checked `@loop-invariant`s. Every fact it returns is a firing instance's head for some
partner, and every partner's firing head is returned. Completeness is stated over
`(list-visited ps)`, the partners visited so far.

These contracts were tested with 112 mutants. 111 were refuted, each by exactly the contract it
targets. One of those needs `make verify`'s 120-second timeout. The remaining mutant came back
unknown. None verified.

## What is owed

Some guarantees hold but cannot yet be proved. Each is marked `OWED` in the source with the reason,
and tests cover it in the meantime.

Two were found by the external conformance suites ([SPEC §7](../SPEC.md#7-verification--contracts)):

- **Context coverage in `signature-nodes`.** The function is built from loops.
- **"A class assertion is never set aside" in `decode-class-assertion`.** This is blocked by
  [#167](https://github.com/slop-lang/slop/issues/167): a union inside `ok` loses its tag.

Two more are outstanding from the original rules:

- **The faithfulness pairs of the four loop rules** in `src/rules/el.slop`. These are CR4 and CR5 on
  an arriving subsumer, and CR7 in both directions. The prover does not follow their loops, so the
  `@example`s are the direct evidence for them.
- **The undefined-not-empty rules** in `src/classify.slop`.

A third obligation, canonical ordering of `Findings.unsatisfiable` and `subsumptions`, has been
discharged. `src/canon.slop` defines a total order over identities, and both lists are sorted on the
way out.

No vacuous contracts stand in for the owed ones. A postcondition like `(list-len $result) >= 0` is
true of every implementation, so it would only make the summary look fuller. A contract the prover
cannot discharge is worse than none. It reads as coverage, and a red `make verify` hides the signal
from every contract that does hold.

## Mutation testing

The contracts and tests are mutation-tested. Each of these mutations turns a specific check red:

- removing `verdict`'s coverage check
- inverting a `@property`
- dropping an arm of `findings-are-incoherent`
- skipping the `\ Sₙ` novelty test
- dropping either of CR4's two handlers
- not committing the seeds into the store
- removing the `owl:Nothing` exclusion

The last one found a real gap. `cr-exists-lhs-on-sub` was covered by no test at all, because both
the litmus fixture and the co-arrival fixture are also closed by CR4's other handler.
`test-late-subsumer-still-concludes` was added to cover it.

## Examples

`make example` runs 103 `@example` blocks, which sit beside the contracts:

| Where | File | Examples |
|---|---|---|
| `el`'s completion rules | `src/rules/el.slop` | 6 |
| `el++`'s rules, each firing and not firing, and the ⊥ flag | `src/rules/ksc.slop` | 52 |
| `sriq`'s rules, each firing and not firing | `src/rules/sriq.slop` | 17 |
| `sriq`'s contexts | `src/sriqctx.slop` | 4 |
| The canonical sort | `src/canon.slop` | 7 |
| Context coverage, including W3C DisjointClasses-002 | `src/normalize.slop` | 2 |
| The decoder | `src/decode.slop` | 5 |
| Profile selection and `auto`'s rule | `src/select.slop` | 10 |

The examples are mutation-tested too. Removing CR2's second self-join arm turns one red.

**Examples did not always run.** Through slop 0.1.2, an example ran only if every argument was a
scalar literal. Any example that called a fixture was reported `SKIP (wildcard args)` and counted
as a pass. HOWL's six rule examples were green while executing nothing, and GROWL's 47 did the same.
slop 0.2.1 fixed this ([#71](https://github.com/slop-lang/slop/issues/71)). Skipped examples are now
reported as `unrunnable` and left out of the pass count.

**A syntax trap.** In an example, a list result's expected value is written as its literal
elements: `(list <elem> …)` with no type argument, and `(list)` when empty. Writing
`(list Addressed)`, which is the normal empty-list literal in ordinary code, makes the harness treat
the type name as an element.

## What `slop verify` can and cannot prove

None of this is documented upstream. Each item was found by probing: writing two minimal functions
that differ in one construct and seeing which one verifies. Every item was probed again on each
toolchain upgrade rather than taken from release notes. It is written down here so nobody has to
work it out a third time.

### Provable

- Record fields, including `Bool` fields, and `list-len`.
- `(@post (implies {braced} {$result == X}))`.
- `forall`, `exists` and `list-contains` over a `$result` built by pushes in a loop-free body
  ([#170](https://github.com/slop-lang/slop/issues/170)).
- `match` in a `@post`, and enum-valued results.
- `while` loops, with or without a `@loop-invariant`.
- A single unconditional `record-new`. Its fields stay visible.
- A guarded push inside a `match` arm. Bounds like `<= 1` prove.
- `(Int 0 ..)` fields, which are interpreted, unlike `set-elements`.
- A callee's `@post` on a `let`-bound result, including a callee in another module
  (`copy-decoded`).
- A counted `while` with `@loop-invariant {(list-len out) == i}`, tracking a pushed list's length
  across a non-pure call in the body (`copy-axioms`).
- Completeness of a `for-each`, via `(list-visited xs)` in its `@loop-invariant`
  ([#247](https://github.com/slop-lang/slop/pull/247); `ksc-join`).
- A field of a pure call's record result, `(. (f q) fires)`, in a body, an invariant or a post
  ([#251](https://github.com/slop-lang/slop/pull/251)).
- A single-payload `union-new`'s payload ([#249](https://github.com/slop-lang/slop/pull/249)), and a
  bare `Bool` field used as a filter test ([#246](https://github.com/slop-lang/slop/pull/246)).
- `@example :eq f` on a record result ([#252](https://github.com/slop-lang/slop/pull/252)).
- A `set!` local read back as the function's `Int` result, or passed through a constructor whose
  `@post` states the field (`run-result`).
- A `c-inline` inside a function that the loop calls (`cancel-requested`).
- `or` and `and` in a function body.
- An `if` choosing between two `record-new`s. Field projection on `$result` survives
  ([#70](https://github.com/slop-lang/slop/issues/70)).

### Not provable

- **A quantified `@property` over a result built in a loop.** It comes back unknown, flagged
  vacuous, while the same claim as a `@post` with the same `@loop-invariant` proves
  ([#385](https://github.com/slop-lang/slop/issues/385)).
- **A loop in the body.** `$result` becomes opaque.
- **A premise the prover treats as an opaque predicate,** such as `node-eq`. It is not known to be
  equality, so `node-eq(b, a1)` and `node-eq(b, a2)` do not give `a1 == a2`.
- **A `const` defined in the same module.** It is opaque, so `{$result == EXIT_ERROR}` cannot be
  proved. The same `const` imported from another module proves
  ([#380](https://github.com/slop-lang/slop/issues/380)).
- **`list-get`.** It is an uninterpreted function, so even a read straight after a push is unknown
  ([#382](https://github.com/slop-lang/slop/issues/382)).
- **`set-elements`.** It is not linked to `set-has`, so `(list-contains (set-elements s) x)` does
  not follow from `(set-has s x)` ([#383](https://github.com/slop-lang/slop/issues/383)).
- **A call nested inside an expression.** In `(record-new T (f (callee x)))` the prover does not
  see `callee`'s `@post`. Binding the call in a `let` proves
  ([#381](https://github.com/slop-lang/slop/issues/381)).
- **`(list-visited xs)` over a local list.** The list must be a parameter
  ([#263](https://github.com/slop-lang/slop/issues/263)).
- **A `set!` local used in a `record-new` that is the function's result.** The field is
  unconstrained, so a true `(. $result rounds) <= budget` fails with a counterexample
  ([#279](https://github.com/slop-lang/slop/issues/279)).
- **A `c-inline` directly in a loop body.** Every `@loop-invariant` of that loop comes back unknown
  ([#280](https://github.com/slop-lang/slop/issues/280)). The same happens to a loop with a `break`
  or `continue` ([#384](https://github.com/slop-lang/slop/issues/384)), or one that calls a function
  handed the `Saturation`: SLOP has no way to state what a call writes (compare
  [#242](https://github.com/slop-lang/slop/issues/242)).

## Writing contracts that verify

**`or`/`and` in a body no longer need rewriting as `if`.** On earlier slop releases these two
bodies did not verify the same contract. On 0.5.1 both do:

```
(or (. r b) (> (. r n) 0))          ; failed with a counterexample; verifies on 0.5.1
(if (. r b) true (> (. r n) 0))     ; verifies
```

`findings-are-incoherent` and `entails-sub` are written as `if` chains for this reason. They can
stay as they are.

**Push from one place.** `cr-and-on-sub` fires from either conjunct of `B₁ ⊓ B₂ ⊑ A` and emits at
most one message. With a `list-push` in each of two branches, the bound `<= 1` fails with a
two-element counterexample, because the checker assumes both branches can run. Setting a flag in
either branch and pushing once proves. The behaviour is identical.

**Faithfulness is stated with the body's own premise tests.** A rule's `complete` property says
that when the premises hold, the conclusion is among the messages. The premises use the same
`node-eq`, `role-eq` and `set-has` calls as the body, and the prover treats these as opaque. In CR2
this means `node-eq(b, a1)` and `node-eq(b, a2)` do not tell the prover that `a1` equals `a2`. So
the second side of the self-join repeats the body's own case split: "b is not also the first
conjunct". Together the two sides cover every premise tuple, given that `node-eq` is equality.

None of this could be stated before slop 0.2.3 with #168 and #170. A quantified property over a
pushed result first failed outright and broke a sibling `@post`
([#69](https://github.com/slop-lang/slop/issues/69)). Later it came back unknown, and
`list-contains` could not be proved at all.

**Expect little reasoning across calls.** Inside a loop-free body built by pushes (#172), a
callee's `@post`s and `@property`s are assumed at the call. That is how the edge rules use
`emit-edge`'s contracts. Everywhere else a callee is an uninterpreted function, so a property that
depends on a helper's result cannot be proved. The counterexample shows this directly:

```
fn_outcome-is-complete_1=[else -> True]
```

For this reason `verdict` keeps its own redundant coverage check, and `advance-round` does not
restate the round-count contract that `round-commit` proves. When a fact has to cross a loop rather
than a call, a `@loop-invariant` carries it. That is how `saturate` proves its round cap.

**Use a type instead of a contract where you can.** `emit-edge` takes a `LogicalEdge` and returns
an `EdgePair`. "Both halves exist" is then true by construction, and each half's destination is a
provable field access. As a list it needed `list-get`, which is uninterpreted, so it could only be
tested.

## Toolchain

HOWL is generated with **slop 0.5.1** and **slop-rdf 0.6.0**. The Rust crate's `slop-std-sys` 0.5
and `slop-rdf-sys` 0.6 are generated on slop 0.5.0, which has the same runtime ABI
(`SLOP_RUNTIME_ABI` 202601).

On an older slop, the properties that need the changes below come back unknown or failed.

| slop change | What HOWL needs it for |
|---|---|
| [#360](https://github.com/slop-lang/slop/pull/360) (0.5.0) | Generated C names carry their package, so HOWL's are `howl_…` |
| [#278](https://github.com/slop-lang/slop/pull/278) (0.4.0) | A collection grows in the arena it was made in. See below |
| [#192](https://github.com/slop-lang/slop/issues/192), [#193](https://github.com/slop-lang/slop/issues/193) (0.4.0) | `spawn` aborts when a thread cannot start, and rejects a `mut` capture |
| [#180](https://github.com/slop-lang/slop/issues/180) (0.3.0) | An unmarked parameter is read-only. slop-rdf must include its `param-mode-fixes` merge |
| #265 | The verifier proves a range return type instead of assuming it. This is why the naming registry types its ids `(Int 0 ..)` |
| #247, #248, #251, #252 | The `el++` rule contracts: `list-visited` for the join's completeness, no trigger patterns on hypotheses, a pure call's record result as one term, and `@example :eq` on a record result |
| #243, #244 | The verifier checks the contract at each early return, and the generated C checks a postcondition at every return |
| #234, #235 | Memory: Maps and Sets store keys and values inline (GO 2.6 → 1.8 GB), and freeing an arena returns big blocks to the OS (1.8 → 0.9 GB) |
| #217 | Empty collections allocate nothing |
| #205 | `set-len`, used by CR2 and CR4 to walk the smaller side. Its map rework, with stored hashes and a word-at-a-time string hash, is most of the M1 slice 6b speedup |
| [#168](https://github.com/slop-lang/slop/pull/168), [#172](https://github.com/slop-lang/slop/pull/172) | The faithfulness pairs: `match` binds every payload at its declared sort, and the exact model covers a loop-free pushed result ([#170](https://github.com/slop-lang/slop/issues/170)) |
| [#173](https://github.com/slop-lang/slop/issues/173) | The parallel round: a call resolves within its module, so `join` is the thread's and not `strlib`'s |

The memory figures also need slop-rdf's streaming scratch arena (slop-rdf #8).

## SLOP runtime behaviour HOWL relies on

None of these are obvious from the source.

**Sets and Maps are pointers, but Lists are values.** `(Set T)` and `(Map K V)` are pointers, and
`(List T)` is a struct. If you get a record out of a map with `map-get`, changes to its Set or Map
fields show up in the map. A `list-push` on one of its List fields only updates the copy's `len`.
If there is spare capacity, it also writes into the shared buffer past the stored length. This is
why `Context` no longer carries a queue, why rules never take an accumulator parameter, and why
`round-commit` writes a queue into its map only after every push.

**A collection grows in the arena it was made in.** This came from slop
[#278](https://github.com/slop-lang/slop/pull/278), raised by HOWL's
[#275](https://github.com/slop-lang/slop/issues/275). `list-new`, `map-new` and `set-new` record
their arena. `list-push`, `map-put` and `set-put` grow the collection there, whatever arena is in
scope at the push. A put can name a different arena with `:arena a`. That is required when one
thread grows a collection another thread made. `el`'s parallel commit grows the run's store sets
and the coordinator's queue map from each committer, so those puts name the committer's own arena.
Without that, `make test-tsan` reports a race. Before #278, growth went to whatever arena the push
site resolved, which put an `el++` worker's results in an arena that was emptied after every fact.

**Multi-payload union variants used to compare only their first payload.** Through slop 0.1.2, a
`(Set Derived)` treated `(derived-succ r Y₁)` and `(derived-succ r Y₂)` as equal. Every filler after
the first was dropped, with a clean compile and no error. slop 0.2.1 fixed it
([#66](https://github.com/slop-lang/slop/issues/66)), and HOWL has a direct test. The driver still
keys its round delta on `Node` and `RoleId` only. That is no longer a workaround. The delta mirrors
`Context` field for field, which is what the commit-at-barrier design wants.

**`set-remove` and `map-remove` used to lose keys.** They cleared a slot without leaving a
tombstone in a linear-probe table, which cut any probe chain passing through it. In a minimal
repro, 10 of 180 surviving keys became unfindable. slop 0.2.1 fixed it
([#67](https://github.com/slop-lang/slop/issues/67)). `active` is still rebuilt at each barrier
rather than pruned, but for a separate reason: §6.4 makes the frontier a pure function of Δₙ₊₁.

**Two undocumented compile errors.** A `Map` or `Set` cannot appear in a function signature; that
fails at check time with "Unknown type". A set element must be an lvalue; that fails at C compile
time with "cannot take the address of an rvalue". Both fail loudly, so they are easy to diagnose.

## The C API, the Rust crate, and the layout guards

HOWL's public C API is written in SLOP, as the `:c-name` functions in `src/howl.slop`. slop
generates its header, `include/howl.h`. `examples/c/classify.c` is a complete C caller.

`rust/` is the `howl` crate ([`rust/README.md`](../rust/README.md)), which binds that API. You build
an `Input`, call `Reasoner::classify`, and get back an owned `Report` whose verdict comes from the
engine. The crate links the RDF and runtime C from `slop-rdf-sys` 0.6 and `slop-std-sys` 0.5 on
crates.io. It encodes input the same way the CLI does, so `make crate-test` reproduces every
committed golden file byte for byte through the crate.

**Engine results never cross the FFI as structs.** An `Outcome` embeds a whole `Saturation` or
`KscResult` by value. Those are dozens of internal structs that change with every engine change. So
the API's handles are opaque `(Ptr Void)` pointers, and results are read through accessor
functions. The Rust side mirrors only the API's small value types and enum values. Tests check
those mirrors against the generated header.

This has bitten before. GROWL 0.6.0 shipped a wrong-offset FFI read. A dependency added a field to
a struct that was embedded by value in another struct. Every later field shifted, the Rust mirror
was not updated, and `graph.size()` returned a garbage pointer. Nothing failed loudly.

**What the guards check.** They check sizes, offsets, field widths, and the enum values the
accessors return. The width check matters on its own. SLOP range types lower to narrow integers,
for example `(Int 1 .. 64)` becomes `uint8_t`. If the Rust side widens one, struct padding can
absorb the change completely. Every offset and the total size stay the same, while Rust reads
padding into the high bits of the value. This gap was found by deliberately breaking a mirror to
check that the guards catch it.

The build also fails if HOWL's C and the `-sys` crates' C were generated for different SLOP runtime
ABIs. Every generated header checks `SLOP_RUNTIME_ABI` against the runtime header it is compiled
with.
