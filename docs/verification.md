# Verification

How HOWL's correctness is checked beyond its tests: Z3 contract checking with `slop verify`, the
SLOP runtime facts the implementation depends on, and the guards on its FFI. The testing strategy
as a whole is [SPEC §10](../SPEC.md#10-testing-strategy); the contracts' posture is
[SPEC §7](../SPEC.md#7-verification--contracts).

## What `slop verify` can and cannot check

`make verify` verifies **89 functions, 0 failing, 0 unknown**. Both round caps are proved:
`saturate`'s budget invariant and result (`iteration <= max-iterations`, el) and `run-ksc`'s
(`rounds <= budget`, el++), each through a checked `@loop-invariant` and the one-round-per-call
contract it rests on. Both loops are written so slop's loop analysis can follow them: cancel-ptr
is read through `cancel-requested`
([#280](https://github.com/slop-lang/slop/issues/280)), el's loop has no `break`, and the calls in
it take counts, not the Saturation. The profile seam's contracts are among the verified: `select-profile` resolves an
explicit request to exactly itself and leaves `auto` to the ontology, `profile-implemented` admits
`el` and `el++` only, `choose-auto` proves `auto`'s three cases (`el` when it omits nothing, else the
rung omitting fewer, ties to `el`), and `default-config` selects `el`; each was seen to fail under a
mutation. Among the verified, the five loop-free completion
rules each prove a **faithfulness pair**: `sound` (nothing unlicensed is emitted) and `complete`
(nothing licensed is omitted), 11 properties in all, each seen to stop verifying under a mutation of
its rule's body. `el++`'s rules (`src/rules/ksc.slop`) go further: 26 per-instance functions for
[Krö10] Fig. 3 and Theorem 2's seed (*) each prove `complete` (fires whenever the body matches) and
`head` (the conclusion is the rule's head over the premises' own terms), the 24 that can decline to
fire also prove `sound` (fires only when the body matches), rule (4)'s ⊥ flag proves its `@post`, and the one join combinator proves
both directions — every fact it returns is a firing instance's head for some partner, and every
partner's firing head is returned — through checked `@loop-invariant`s, completeness over
`(list-visited ps)`. 112 mutants: 111 refuted, each by exactly the contract it targets (one needs
`make verify`'s 120 s timeout), and one unknown, never verified. The per-rule cases are `@example`s
beside the contracts. `make example` runs
**76 executable examples**: 6 per rule, 52 on el++'s rules (each rule firing and not, and the ⊥
flag), 7 on the canonical sort, 2 on context coverage (the W3C DisjointClasses-002 case), 5 in
the decoder and 4 on `auto`'s rule. Two guarantees the external conformance suites
exposed are true but **owed** as contracts ([SPEC §7](../SPEC.md#7-verification--contracts)):
- context coverage in `signature-nodes`, which is loops;
- "a class assertion is never set aside" in `decode-class-assertion`, which is blocked by
  [#167](https://github.com/slop-lang/slop/issues/167) (a union inside `ok` loses its tag).

Tests and examples hold both instead. The boundary is not obvious, it is not documented upstream, and every row below
was established by *probing* — writing the minimal pair of functions that differ in one construct and
seeing which verifies. Recorded here so it is not rediscovered a third time.

**Toolchain: slop 0.4.0 and slop-rdf 0.5.0** (the Rust crate's `slop-std-sys` 0.4.0 and
`slop-rdf-sys` 0.5.0 vendor the same generation). 0.4.0 carries [#278](https://github.com/slop-lang/slop/pull/278), which makes a collection grow in the arena it was made in, with `:arena` for a put
that must grow elsewhere (SLOP facts, below). Since #265 the verifier also proves a range return type
rather than assuming it, which is why the naming registry types its ids `(Int 0 ..)`. el++'s rule contracts need #247 (`list-visited`, which makes the join's completeness
statable), #248 (no trigger patterns on hypotheses; `list-contains` by structure), #251 (a pure
call's record result is one term), and #252 (`@example :eq` on a record result). #244 checks a
postcondition at every return in the generated C, and #243 has the verifier check the contract where
each early return leaves. #235 maps big arena blocks from the OS, so freeing an arena returns its memory (GO's
peak 1.8 → 0.9 GB); #234 stores a Map's and Set's keys and values inline in a dense table (2.6 →
1.8 GB). #217 makes empty collections allocate nothing. CR2 and CR4's smaller-side dispatch uses #205's `set-len`, and its map rework (stored
hashes, a word-at-a-time string hash) is most of the M1 slice 6b speedup. The faithfulness pairs need
[#168](https://github.com/slop-lang/slop/pull/168) (`match` binds every payload, at its declared
sort) and [#172](https://github.com/slop-lang/slop/pull/172) (the exact model of a loop-free
push-built result, [#170](https://github.com/slop-lang/slop/issues/170)). On a slop without them
those properties come back unknown or failed; CI's verify step is non-blocking. The parallel round
needs [#173](https://github.com/slop-lang/slop/issues/173) (a call resolves within its module, so
`join` is the thread's and not `strlib`'s). 0.3.0 makes an unmarked parameter read-only
([#180](https://github.com/slop-lang/slop/issues/180)), so slop-rdf must be at or after its
`param-mode-fixes` merge; the memory figures need its streaming scratch arena (slop-rdf #8). 0.4.0's
`spawn` aborts when a thread cannot start ([#192](https://github.com/slop-lang/slop/issues/192)) and
rejects a `mut` capture ([#193](https://github.com/slop-lang/slop/issues/193)). The
rows below were re-probed on each bump rather than assumed from release notes.

| Works | Does not |
|---|---|
| Record fields — **including `Bool`** — and `list-len` | **`or` / `and` in a function BODY** — makes the return value opaque |
| `(@post (implies {braced} {$result == X}))` | **A quantified `@property` over a result built in a LOOP** — *unknown*: the exact model follows only loop-free bodies |
| **`forall` / `exists` / `list-contains` over a loop-free push-built `$result`** — proved or refuted ([#170](https://github.com/slop-lang/slop/issues/170)) | A premise the prover sees as an opaque predicate (`node-eq`, `set-has`) — equal inputs are not known to give equal answers |
| `match` in a `@post`, enum-valued results | **A loop in the body** — `$result` becomes opaque |
| `while` loops, with or without `@loop-invariant` | **`if` between two `record-new`s** — loses field projection on `$result` ([#70](https://github.com/slop-lang/slop/issues/70), open) |
| A single unconditional `record-new` — fields stay visible | `const` values — opaque, so `{$result == EXIT_ERROR}` cannot be proved |
| A guarded push inside a `match` arm — bounds like `<= 1` prove | `set-elements`, `list-get` — uninterpreted functions |
| `(Int 0 ..)` fields — interpreted, unlike `set-elements` | Reasoning **across a call** nested in an expression — `(record-new T (f (callee x)))` does not see `callee`'s `@post` |
| A callee's `@post` on a **`let`-bound** result, callee in another module included (`copy-decoded`) | — |
| A counted `while` with `@loop-invariant {(list-len out) == i}` — a pushed list's length, across a non-pure call in the body (`copy-axioms`) | — |
| **`@example` — genuinely executes** (0.2.1) | — |
| **Completeness of a `for-each`**, via `(list-visited xs)` in its `@loop-invariant` ([#247](https://github.com/slop-lang/slop/pull/247); el++'s `ksc-join`) | `(list-visited xs)` over a LOCAL list — not followed yet; the source must be a parameter |
| A field projected from a pure call's record result, `(. (f q) fires)`, in a body, an invariant and a post alike ([#251](https://github.com/slop-lang/slop/pull/251)) | — |
| A single-payload `union-new`'s payload ([#249](https://github.com/slop-lang/slop/pull/249)), and a bare `Bool` field as a filter test ([#246](https://github.com/slop-lang/slop/pull/246)) | — |
| `@example :eq f` on a record result ([#252](https://github.com/slop-lang/slop/pull/252)) | — |
| A `set!` local read back as the function's `Int` result, or through a constructor whose `@post` states the field (`run-result`) | The same local in a **`record-new` that is the function's result** — the field is unconstrained, so a true `(. $result rounds) <= budget` fails on a counterexample ([#279](https://github.com/slop-lang/slop/issues/279)) |
| A `c-inline` in a function the loop calls (`cancel-requested`) | **A `c-inline` in the loop body** — every `@loop-invariant` of the loop is *unknown* ([#280](https://github.com/slop-lang/slop/issues/280)); so is a loop with a `break`, or one calling a function handed the Saturation |

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

**Faithfulness is proved against the body's own premise tests.** A rule's `complete` property says:
when the premises hold, the conclusion is among the messages. The premises are stated with the same
`node-eq` / `role-eq` / `set-has` calls the body makes, which the prover treats as opaque
predicates. One consequence is visible in CR2: to the prover, `node-eq(b, a1)` and `node-eq(b, a2)`
do not make `a1` and `a2` equal, so the second side of the self-join states the body's own case
split ("b is not also the first conjunct"). The two sides together cover every premise tuple given
that `node-eq` is equality, which is `node-eq`'s own business. Before 0.2.3 plus #168/#170 none of
this was statable: a quantified property over a push-built result failed outright and broke a
sibling `@post` ([#69](https://github.com/slop-lang/slop/issues/69)), later came back *unknown*, and
`list-contains` could not be proved at all.

**`@example` executes, and it did not before.** The examples complement the proved faithfulness
pairs, and for the four loop rules they are the direct evidence. Through 0.1.2 an example ran only when
every argument was a scalar literal; any fixture call was reported `SKIP (wildcard args)` and then
**counted as a pass**. HOWL's six rule examples reported green while executing nothing, and GROWL's
47 did the same. Fixed in 0.2.1 ([#71](https://github.com/slop-lang/slop/issues/71)): skips are
reported as `unrunnable` and excluded from the pass count. The examples are mutation-tested —
removing CR2's second self-join arm turns one red.

One syntax trap, because it fails confusingly: a list-returning example's expected value is **splat**
as literal elements, so it is `(list <elem> …)` with no type argument and `(list)` for empty. Writing
`(list Addressed)` — the valid empty-list literal in ordinary code — makes the harness treat the type
name as an element.

**Interprocedural reasoning is narrow.** Inside a loop-free push-built body (#172) a callee's
`@post`s and `@property`s are assumed at the call, which is how the edge rules use `emit-edge`'s.
Everywhere else a callee is an uninterpreted function, so a property that depends on what a helper
returns is unprovable — the counterexample says so literally
(`fn_outcome-is-complete_1=[else -> True]`). `verdict` keeps a *redundant* local coverage check for
exactly this reason, and `advance-round` deliberately does **not** restate the round-count contract
that `round-commit` proves. Where the fact must cross a loop rather than a call, `@loop-invariant`
carries it: `saturate` proves `iteration <= max-iterations` that way.

**Prefer a type over a contract where the shape allows it.** `emit-edge` takes a `LogicalEdge` and
returns an `EdgePair`, so "both halves exist" is enforced by construction and each half's destination
is a provable field access. As a list it needed `list-get`, which is uninterpreted — unprovable, and
only testable.

**Obligations that cannot be discharged are marked `OWED` in-source, with the reason**, and covered
by test meanwhile. Two are outstanding: the faithfulness pairs of the **four loop rules** (CR4 and
CR5 on an arriving subsumer, CR7 both ways; `src/rules/el.slop`), whose loops the exact model does not
follow, and the undefined-not-empty rules (`src/classify.slop`). A third — canonical ordering of
`Findings.unsatisfiable` and `subsumptions` — has been **discharged**: `src/canon.slop` supplies a
total order over identities and both lists now sort on the way out. No vacuous contracts stand in:
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

Four properties of the toolchain are load-bearing here and none are obvious from the source:

**`(Set T)`/`(Map K V)` are pointers; `(List T)` is a value struct.** Mutating a Set or Map field
reached through a `map-get` copy is visible in the map; `list-push` on a List field of that same copy
updates only the copy's `len`, and if `cap` allows it writes into the shared buffer past the stored
length. This is why `Context` no longer carries a queue, why rules never take an accumulator
parameter, and why `round-commit` writes a queue into its map only after every push.

**A collection grows in the arena it was made in** (slop
[#278](https://github.com/slop-lang/slop/pull/278), from HOWL's
[#275](https://github.com/slop-lang/slop/issues/275)). `list-new`, `map-new` and `set-new` record
their arena, and `list-push`, `map-put` and `set-put` grow the collection there, whatever arena is in
scope at the push. A put can name another with `:arena a`, and that is required when a thread grows
a collection another thread made: `el`'s parallel commit grows the run's store sets and the
coordinator's queue map from each committer, so those puts name the committer's own arena (`make
test-tsan` reports the race without them). Before #278 growth went to whatever arena the push site
resolved, which put an `el++` worker's results in an arena emptied after every fact.

**Multi-payload union variants compared only their FIRST payload** — fixed in 0.2.1
([#66](https://github.com/slop-lang/slop/issues/66)), verified here by direct test. Through 0.1.2 a
`(Set Derived)` treated `(derived-succ r Y₁)` and `(derived-succ r Y₂)` as **equal**, swallowing
every filler after the first: clean compile, silent under-derivation. The driver still keys its round
delta on `Node`/`RoleId` only, which is no longer a workaround — it is the shape the
commit-at-barrier design wants anyway, since the delta mirrors `Context` field-for-field.

**`set-remove`/`map-remove` could strand still-present keys** — fixed in 0.2.1
([#67](https://github.com/slop-lang/slop/issues/67)). Clearing `occupied` without a tombstone in a
linear-probe table truncated any chain passing through the hole; 10 of 180 surviving keys became
unfindable in a minimal repro. `active` is still rebuilt each barrier rather than pruned, for the
independent reason that §6.4 makes the frontier a pure function of Δₙ₊₁.

**A `Map` or `Set` may not appear in a function signature, and a set element must be an lvalue.**
Neither is documented; the first is an "Unknown type" at check time and the second a "cannot take the
address of an rvalue" at compile time. Both are loud, which is the only reason they are footnotes
rather than entries in the list above.

## The C API, the Rust crate, and the layout guards

HOWL's public C API is written in SLOP (the `:c-name` functions in `src/howl.slop`) and slop
generates its header, `include/howl.h`; `examples/c/classify.c` is a complete C caller. `rust/` is
the `howl` crate ([`rust/README.md`](../rust/README.md)), which binds that API: `Input`, then
`Reasoner::classify`, then an owned `Report` whose verdict comes from the engine. It links the RDF and
runtime C from `slop-rdf-sys` 0.5.0 and `slop-std-sys` 0.4.0 on crates.io. Its input is encoded as
the CLI encodes, so `make crate-test` reproduces every committed golden byte for byte through the
crate.

**The engine's results never cross the FFI as structs.** An `Outcome` embeds a whole `Saturation`
or `KscResult` by value. Those are dozens of engine-internal structs, and they change with every
engine change. So the API's handles are opaque (`(Ptr Void)`), and results are read through its
accessors. Rust mirrors only the API's small value types and enum values, and those mirrors are
asserted against the generated header in tests rather than maintained by care.

This is not hypothetical. GROWL 0.6.0 shipped a wrong-offset FFI read: a dependency added a field to
a struct embedded by value in another, every following field shifted, the Rust mirror was not
updated, and `graph.size()` returned a garbage pointer. Nothing failed loudly.

The guards check sizes, offsets, **field widths** and the enum values the accessors return. The
widths are not redundant. SLOP range types lower to narrow integers (`(Int 1 .. 64)` → `uint8_t`),
and widening one on the Rust side can be absorbed entirely by struct padding. Every offset and the
total size would stay identical while the Rust side reads padding into the high bits of the value.
That gap was found by deliberately drifting a mirror to check the guards actually bite. `build.rs`
also refuses to build if `csrc/runtime/slop_runtime.h` differs from the one `slop-std-sys` ships.
