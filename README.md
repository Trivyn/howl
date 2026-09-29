# HOWL

**A consequence-based description-logic reasoner in SLOP — sibling to [GROWL](../growl).**

GROWL *materializes* an OWL 2 RL ontology (forward-chaining, edge enrichment). HOWL *classifies* a
description logic — it computes the complete subsumption hierarchy and consistency of a TBox,
including the defined-class subsumptions that RL materialization cannot see. The two compose through
RDF: HOWL classifies → emits inferred `subClassOf` → GROWL materializes/enriches.

- **GR-OWL / H-OWL** — the RL engine and the DL engine. "HOWL = **Horn OWL**" is apt: the first two
  targets (CB-EL, Horn-SHIQ) are Horn fragments.
- **Design:** [`SPEC.md`](./SPEC.md) — approved 2026-08-17.

## Status: Turtle in, classified out

**HOWL derives `Mother ⊑ Parent` from a Turtle document** — the
[§3.1](./SPEC.md#31-the-litmus-test-also-the-v0-acceptance-criterion) litmus, and the line between a
DL reasoner and a materialization engine. It is reachable only through the existential on the
*defining* side, which is what materialization cannot see.

```
$ howl validate corpus/fixtures/v0/litmus.ttl
howl: 10 subsumptions, 0 unsatisfiable, 0 omitted
howl: coherent                                                    # exit 0

$ howl validate corpus/fixtures/hazards/unattested-import.ttl
howl: 6 subsumptions, 0 unsatisfiable, 1 omitted
  omitted: UnresolvedImport(http://example.org/does-not-exist)
howl: INCONCLUSIVE — coverage gaps, this is NOT a pass            # exit 2

$ howl validate corpus/fixtures/out-of-profile/union.ttl --strict
howl: refused (--strict), no report — 1 omitted
  omitted: SubClassOf(http://example.org/t#C ObjectUnionOf(http://example.org/t#A http://example.org/t#B))
                                                                  # exit 2
```

`classify` no longer refuses. It still returns a `Fault` rather than a report when the front end
cannot decode the input, and that is the safety-relevant choice: a `Fault` has no verdict to
misread, an `Outcome` does. Coverage travels from the gate unchanged, so a run with omissions
reports **inconclusive** — never **coherent** — and lists every omission so it can be acted on.
Treat exit 0 alone as the pass condition; a CI job that accepts 2 reintroduces the silent false pass
the gate exists to prevent. Every CLI argument is either honoured or refused with exit 3: `-I FILE`
attests an import (a document with no ontology IRI is refused), `--strict` refuses to run past an
omission, and `--emit`/`--reduce` are refused until M3. `--report` prints the canonical report the
goldens compare, `--max-iterations N` sets the round budget, `--workers N` sets how many threads join
each round (default 4; it never changes the report), and `--timings` prints phase durations on
stderr — never in the report.

**Real ontologies, not just fixtures.** The fixtures all passed while the first two real ontologies
failed, and both failures are fixed and pinned by `make corpus-acceptance`:

| Ontology | Before | Now |
|---|---|---|
| RO 2025-12-17 (11.6k triples) | exit 3 — an inverse property in a property chain faulted the whole document | exit 2, 0 unsatisfiable, 847 omitted |
| OBI 2026-07-27 (118k triples) | exit 1, *inconsistent* — every complex range filler of a role shared one fresh node | exit 2, 0 unsatisfiable, 38,681 subsumptions, 1.0 s (reasoning 0.4 s) |
| GO 2026-07-26 (1.4M triples) | never finished — the header pass scanned lists per triple, and every fact was matched against every axiom | exit 2, 0 unsatisfiable, 1 omitted (one `owl:inverseOf`), 459,329 subsumptions, 13.4 s (reasoning 5.5 s) |

Rule dispatch goes through a premise index, so each rule sees only the axioms it could fire on; OBI's
reasoning went from 172 s to 0.4 s with its report unchanged byte for byte.

**The §12 benchmark: not yet met.** `make bench` times each corpus entry against its routed oracle on
the same machine. Each side gets a median of 5 runs after 1 warm-up, with W = 4. Classification is
HOWL's front end plus reasoning, against the oracle's reasoner creation, consistency check and
classification. Every timed input and report must be the certified ones. Run-to-run spread is about
±10%, and the verdict holds across it (`bench/results.txt`, Apple M3 Ultra):

| Entry | Oracle | HOWL classify | Oracle classify | Ratio | |
|---|---|---|---|---|---|
| GO 2026-07-26 | ELK 0.6.0 | 2.7 s (reasoning 0.5 s), 13 GB peak | 0.48 s | 5.6× | **fails** 5× |
| EL-GALEN | ELK 0.6.0 | 1.8 s (reasoning 1.2 s), 7 GB peak | 0.28 s | 6.4× | **fails** 5× |
| OBI 2026-07-27 | HermiT | 0.19 s | 0.51 s | 0.4× | reported |
| RO 2025-12-17 | HermiT | 0.03 s | 0.16 s | 0.2× | reported |

M1 slice 6b removed the rules' redundant work: CR6 fires once per edge, each edge is admitted once, and
CR2/CR4 walk the smaller side of their join. slop's faster maps (stored hashes, a
word-at-a-time string hash, slop-lang/slop#205) and HOWL's own triple store (term ids by content, an
SPO index and an rdf:type index, instead of slop-rdf's four-index store) a round barrier that commits in
parallel instead of merging serially, and saturation over nodes renamed to integer ids at its
boundary took S6a's 19.2× (GO) and 30.1× (EL-GALEN) to the figures above. What remains is GO's single-threaded front end (~2.2 s) and IRI hashing and comparison in
reasoning.

| Milestone | Scope | State |
|---|---|---|
| M0 | types, front end, normalization | **done** — 14 fixtures by exit code (`make acceptance`), RO and OBI end to end (`make corpus-acceptance`), §12's accounting / idempotence / freshness invariants and triple-order independence tested |
| M1 | CR1–CR7, driver, verdict discipline | rules, driver, extraction and premise index done; RO, OBI and GO run end to end; golden reports gate performance changes (`make golden`); every fixture diff-clean against HermiT, and against ELK where probed capable (`make diff-fixtures`); the W3C OWL 2 EL tests and ELK's classification and entailment tests pass wherever HOWL reasons completely and the report can state the answer (`make conformance`); the v0 projections of RO, OBI, GO and EL-GALEN are diff-clean against their routed oracle over every class pair (`make diff-corpus`, recorded in `corpus/corpus-differential.txt`); each round is joined on worker threads and the report is byte-identical at W ∈ {1,2,4,8} for every cap, capped runs included (`make determinism`, `make test-tsan`); the §12 benchmark runs, and is **not met**: GO 5.6× and EL-GALEN 6.4× ELK (`make bench`, `bench/results.txt`) |
| M2a | port amendments A1–A4 | consumer-side, blocking |
| M2b | port adapter | not started |
| M3 | Turtle emission + GROWL round-trip | not started |
| M4 | alignment + minimal repair | not started |

## On the way to EL++

v0 is **ELH<sub>⊥</sub><sup>R+</sup> with domain and range** — EL with role hierarchies, ⊥, role
composition, and property domains/ranges. This table tracks the distance from there to EL++,
construct by construct, against both forms of the target: **EL++** the description logic (Baader,
Brandt & Lutz, 2005, extended with ranges and reflexive roles in 2008), and the **OWL 2 EL** profile,
its W3C syntax. The two are not the same list — OWL 2 EL adds `ObjectHasSelf`, keys and the built-in
properties, which the EL++ papers do not define. [§5.2](./SPEC.md#52-the-exact-v0-language) is the
authority for what HOWL does with each.

**done** — reasoned over, and tested. **not yet** — recognized and enumerated out-of-profile, so a
document using it reports *inconclusive*, never *coherent*. **non-goal** — excluded by
[§14](./SPEC.md#14-non-goals).

| Construct | EL++ | OWL 2 EL | HOWL | What it takes / how it is done |
|---|:-:|:-:|---|---|
| ***Class constructors*** | | | | |
| `owl:Thing`, `owl:Nothing` (⊤, ⊥) | ✓ | ✓ | **done** | |
| `ObjectIntersectionOf` (C ⊓ D) | ✓ | ✓ | **done** | |
| `ObjectSomeValuesFrom` (∃r.C) | ✓ | ✓ | **done** | |
| `ObjectOneOf`, one individual ({a}) | ✓ | ✓ | not yet | nominal propagation (CEL's CR6), which reaches across contexts and so gives up [§6.6](./SPEC.md#66-parallelism-context-based)'s context independence; [§15 Q3](./SPEC.md#15-open-questions) closed it for the first consumer |
| `ObjectHasValue` (∃r.{a}) | ✓ | ✓ | not yet | lands with nominals |
| `ObjectHasSelf` (∃r.Self) | | ✓ | not yet | completion rules for self-loops, and a completeness citation beyond the EL++ papers |
| ***TBox axioms*** | | | | |
| `SubClassOf` (C ⊑ D) | ✓ | ✓ | **done** | |
| `EquivalentClasses` | ✓ | ✓ | **done** | desugared to GCIs around the canonically least operand |
| `DisjointClasses`, n-ary | ✓ | ✓ | **done** | desugared to pairwise C ⊓ D ⊑ ⊥ |
| ***RBox axioms*** | | | | |
| `SubObjectPropertyOf` (r ⊑ s) | ✓ | ✓ | **done** | |
| `ObjectPropertyChain` (r₁ ∘ … ∘ rₙ ⊑ s) | ✓ | ✓ | **done** | OWL 2 §11.2 regularity is gated; EL++ alone would not require it |
| `EquivalentObjectProperties` | ✓ | ✓ | **done** | desugared to simple inclusions |
| `TransitiveObjectProperty` | ✓ | ✓ | **done** | desugared to r ∘ r ⊑ r |
| `ObjectPropertyDomain` | ✓ | ✓ | **done** | ∃r.⊤ ⊑ C |
| `ObjectPropertyRange` | ✓ | ✓ | **done** | eliminated through fresh X<sub>r,D</sub> (2008); the range/chain condition is gated |
| `ReflexiveObjectProperty` (ε ⊑ r) | ✓ | ✓ | not yet | an r-self-edge in every context, and its interaction with chains |
| `owl:topObjectProperty`, `owl:bottomObjectProperty` | | ✓ | not yet | built-in role semantics; the universal role reaches across contexts, as nominals do |
| ***Assertions*** | | | | |
| `ClassAssertion` (C(a)) | ✓ | ✓ | **done**† | individual(a) ⊑ C |
| `ObjectPropertyAssertion` (r(a,b)) | ✓ | ✓ | **done**† | direct edges, plus range seeds on the target |
| `SameIndividual`, `DifferentIndividuals` | via {a} | ✓ | not yet | equality: {a} ⊑ {b}, {a} ⊓ {b} ⊑ ⊥ — lands with nominals |
| `NegativeObjectPropertyAssertion` | via {a} | ✓ | not yet | {a} ⊓ ∃r.{b} ⊑ ⊥ — lands with nominals |
| `HasKey` | | ✓ | not yet | DL-safe over named individuals, and it infers equality — lands after nominals |
| ***Concrete domains*** | | | | |
| `DataSomeValuesFrom`, `DataHasValue`, `DataOneOf`, `DataIntersectionOf`, data property axioms and assertions, `DatatypeDefinition` | ✓ | ✓ | **non-goal** | the consumer partitions datatype axioms off rather than HOWL growing a concrete domain |

† Implemented and tested, but the reviewed argument that the direct-edge encoding is sound and
complete ([§12](./SPEC.md#12-milestones--acceptance-criteria) M1 (f)) is still owed, so assertions
ship outside the sound-and-complete claim until it lands.

**14 of 23 rows done.** Every open EL++ row traces to one of three things: **nominals** (four rows),
**reflexive roles** (one), and **concrete domains** (the non-goal). OWL 2 EL adds three more:
`ObjectHasSelf`, the built-in properties, and `HasKey`. None of the open rows has a milestone yet —
[§12](./SPEC.md#12-milestones--acceptance-criteria) goes from v0 to Horn-SHIQ, which is incomparable
with EL++ rather than a step toward it.

**Off the path entirely.** These are outside OWL 2 EL, so no progress toward EL++ reaches them; they
are recognized and enumerated like every open row above.

| Construct | Where it lives |
|---|---|
| `ObjectUnionOf`, `ObjectComplementOf`, `ObjectAllValuesFrom`, cardinalities, `DisjointUnion`, `ObjectOneOf` with several members | outside EL entirely — v2 (SROIQ) |
| `InverseObjectProperties`, functional / inverse-functional, qualified cardinality | **the largest real gap** — v1 (Horn-SHIQ) |
| `DisjointObjectProperties`, symmetric / asymmetric / irreflexive | outside OWL 2 EL |
| Anonymous individuals, reserved IRIs as entity names | excluded by OWL 2 EL / forbidden by OWL 2 |
| SWRL rules | **never**, at any rung — unrestricted SWRL is undecidable, and it is in neither OWL 2 DL nor OWL 2 EL |

### What happens to a construct that isn't done

Every recognized construct has exactly one of four dispositions, and the matrix is a catch-all-free
`match` over `RawAxiom` compiled with `-Werror=switch` — so adding a construct without dispositioning
it is a **build error**, not a proofreading exercise. Moving a row to **done** therefore starts at
that `match`.

| Disposition | Meaning | Constructs |
|---|---|---|
| **in v0** | reasoned over | every **done** row above |
| **consumed** | read, yields no axiom | declarations — *not* "ignored": dropping them loses declared-but-unused classes |
| **inert** | semantically empty in OWL 2 | `AnnotationAssertion`, `SubAnnotationPropertyOf`, `AnnotationProperty{Domain,Range}`, the ontology header, axiom-annotation reification |
| **out-of-profile** | recognized, **enumerated**, never silently dropped | every other row above |

**Why "recognized and enumerated" rather than "unsupported".** A rejected axiom lands in
`coverage.omitted` with a canonical `AxiomRef`, which forces the verdict to **inconclusive**. That is
the whole safety property: HOWL will not report *coherent* over an ontology it only partly read. The
corpus pins both directions — all 17 `v0/` fixtures gate clean, and all 15 `out-of-profile/` fixtures
yield at least one omission (`make test`), cross-checked by an independently written census
(`make census`).

**Two conditions, not one.** §5.2's table classifies axiom *forms*; ELH<sub>⊥</sub><sup>R+</sup> also
restricts the *operands* those forms carry. `SubClassOf(A, ObjectUnionOf(B,C))` is an in-profile form
carrying a concept the fragment has no constructor for, so the gate checks both — and a built-in role
is caught wherever it occurs, not only in the shape a fixture happens to use.

## Build

Mirrors GROWL: a SLOP static library, a separate CLI executable, and a Rust/C FFI layer, depending on
the sibling `../slop-rdf`.

```sh
make          # build the CLI from the committed C in csrc/ — no SLOP toolchain needed
make test     # verdict-discipline and structural-invariant tests
make lib      # static library
make verify   # Z3 contract checking (needs the SLOP toolchain + z3)
make example      # executable @example blocks: the completion rules, canon, context coverage
make crate-test   # Rust crate, including the FFI layout guards
make acceptance   # SPEC §12 criteria as CLI exit codes, over the committed fixtures
make test-tsan    # the tests under ThreadSanitizer (every test runs the parallel round)
make determinism  # reports byte-identical at W in {1,2,4,8} for every round cap (fixtures; -corpus for RO/OBI/GO/GALEN)
make bench        # §12 benchmark against the routed oracle; writes bench/results.txt (local, minutes)
make bench-check  # results.txt still names the certified reports, and its verdicts follow
make corpus-acceptance   # RO and OBI end to end (run ./corpus/fetch.sh ro obi first)
```

The differential ([SPEC §10](./SPEC.md#10-testing-strategy) item 1) needs a JDK to run Gradle and
the network once. The wrapper provisions the pinned JDK 21 if the host has none, and `rdflib` 7.6.0
routes fixtures by construct:

```sh
make oracle          # build oracle/, ELK 0.6.0 and HermiT 1.4.5.519 on OWL API 5.1.20
make probes          # capability probes: HOWL and HermiT must pass all; ELK's results are recorded
make diff-fixtures   # HOWL vs HermiT on every fixture, and vs ELK where the probes allow
python3 -m unittest corpus/test_entdiff.py   # the comparator's self-tests
make conformance-fetch   # the pinned W3C OWL 2 and ELK conformance tests (corpus/conformance.sha256)
make conformance         # HOWL against their expected answers
make materialize         # the projected corpus ontologies (after ./corpus/fetch.sh; EL-GALEN needs make oracle)
make diff-corpus         # each against its routed oracle; the record is corpus/corpus-differential.txt
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
oracle/           the differential oracle: ELK and HermiT behind one pinned OWL API (Gradle)
corpus/           pinned ontologies, fixtures, probes, goldens; census, entdiff and the harness
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

`make verify` verifies **36 functions, 0 failing**. Among them, the six loop-free completion
rules each prove a **faithfulness pair**: `sound` (nothing unlicensed is emitted) and `complete`
(nothing licensed is omitted), 13 properties in all, each seen to stop verifying under a mutation of
its rule's body. `make example` runs **15 executable examples**: 6 per rule, 7 on the canonical sort, and
2 on context coverage (the W3C DisjointClasses-002 case). Two guarantees the external conformance suites
exposed are true but **owed** as contracts ([SPEC §7](./SPEC.md#7-verification--contracts)):
- context coverage in `signature-nodes`, which is loops;
- "a class assertion is never set aside" in `decode-class-assertion`, which is blocked by
  [#167](https://github.com/slop-lang/slop/issues/167) (a union inside `ok` loses its tag).

Tests and examples hold both instead. The boundary is not obvious, it is not documented upstream, and every row below
was established by *probing* — writing the minimal pair of functions that differ in one construct and
seeing which verifies. Recorded here so it is not rediscovered a third time.

**Toolchain: slop `main` at or after [#205](https://github.com/slop-lang/slop/pull/205), not yet
in a release.** CR2 and CR4's smaller-side dispatch uses #205's `set-len`, and its map rework
(stored hashes, a word-at-a-time string hash) is most of the M1 slice 6b speedup. The faithfulness pairs need
[#168](https://github.com/slop-lang/slop/pull/168) (`match` binds every payload, at its declared
sort) and [#172](https://github.com/slop-lang/slop/pull/172) (the exact model of a loop-free
push-built result, [#170](https://github.com/slop-lang/slop/issues/170)). On a slop without them
those properties come back unknown or failed; CI's verify step is non-blocking. The parallel round
needs [#173](https://github.com/slop-lang/slop/issues/173) (a call resolves within its module, so
`join` is the thread's and not `strlib`'s). 0.3.0 makes an unmarked parameter read-only
([#180](https://github.com/slop-lang/slop/issues/180)), so slop-rdf must be at or after its
`param-mode-fixes` merge. The
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
| `(Int 0 ..)` fields — interpreted, unlike `set-elements` | Reasoning **across a call** |
| **`@example` — genuinely executes** (0.2.1) | — |

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

Three properties of the toolchain are load-bearing here and none are obvious from the source:

**`(Set T)`/`(Map K V)` are pointers; `(List T)` is a value struct.** Mutating a Set or Map field
reached through a `map-get` copy is visible in the map; `list-push` on a List field of that same copy
updates only the copy's `len`, and if `cap` allows it writes into the shared buffer past the stored
length. This is why `Context` no longer carries a queue, why rules never take an accumulator
parameter, and why `round-commit` writes a queue into its map only after every push.

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
