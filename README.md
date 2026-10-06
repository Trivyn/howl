# HOWL

**A consequence-based description-logic reasoner in SLOP — sibling to [GROWL](../growl).**

GROWL *materializes* an OWL 2 RL ontology (forward-chaining, edge enrichment). HOWL *classifies* a
description logic — it computes the complete subsumption hierarchy and consistency of a TBox,
including the defined-class subsumptions that RL materialization cannot see. The two compose through
RDF: HOWL classifies → emits inferred `subClassOf` → GROWL materializes/enriches.

- **GR-OWL / H-OWL** — the RL engine and the DL engine. "HOWL = **Horn OWL**" is apt: the first two
  targets (CB-EL, Horn-SRIQ) are Horn fragments.
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

**Profiles.** `--profile` selects the calculus, one rung per named logic
([SPEC §5](./SPEC.md#5-fragment-roadmap)): `el` (ELH⊥R+ with domain/range and an ABox, plus `¬` in a
superclass, domain or range, which it rewrites into ⊥ axioms — built, and the default on every
surface), `el++` (the OWL 2 EL object fragment — built), `horn-sriq` (Horn-SRIQ) and
`sriq` (the SRIQ object fragment), or `auto` for the cheapest built rung that contains the whole
ontology (else the one omitting the fewest axioms, ties to `el`). A rung that is not built yet
exits 3; it is never quietly run as `el`. The report's second
line names the profile that ran. The Rust crate exposes the same choice as `Config::selection`.

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
| RO 2025-12-17 (11.6k triples) | exit 3 — an inverse property in a property chain faulted the whole document | exit 2, 0 unsatisfiable, 845 omitted |
| OBI 2026-07-27 (118k triples) | exit 1, *inconsistent* — every complex range filler of a role shared one fresh node | exit 2, 0 unsatisfiable, 38,681 subsumptions, 1.0 s (reasoning 0.4 s) |
| GO 2026-07-26 (1.4M triples) | never finished — the header pass scanned lists per triple, and every fact was matched against every axiom | exit 2, 0 unsatisfiable, 1 omitted (one `owl:inverseOf`), 459,329 subsumptions, 13.4 s (reasoning 5.5 s) |

Rule dispatch goes through a premise index, so each rule sees only the axioms it could fire on; OBI's
reasoning went from 172 s to 0.4 s with its report unchanged byte for byte.

**The §12 benchmark: met.** `make bench` times each corpus entry against its routed oracle on
the same machine. Each side gets a median of 5 runs after 1 warm-up, with W = 4. Classification runs
from axioms in hand to taxonomy on both sides: HOWL's gate, normalization, indexing and reasoning,
against the oracle's reasoner creation, consistency check and classification. Parsing and the
RDF-to-axiom mapping (HOWL's decode, the OWL API's parse) are untimed on both sides; HOWL's decode is
reported beside the ratio. Every timed input and report must be the certified ones. Run-to-run spread
is about ±10% (`bench/results.txt`, Apple M3 Ultra):

| Entry | Oracle | HOWL classify | HOWL decode (untimed) | Oracle classify | Ratio | |
|---|---|---|---|---|---|---|
| GO 2026-07-26 | ELK 0.6.0 | 0.38 s (reasoning 0.28 s), 0.57 GB peak | 0.44 s | 0.46 s | 0.84× | **passes** 5× |
| EL-GALEN | ELK 0.6.0 | 0.82 s (reasoning 0.66 s), 0.59 GB peak | 0.07 s | 0.28 s | 2.9× | **passes** 5× |
| OBI 2026-07-27 | HermiT | 0.05 s | 0.03 s | 0.50 s | 0.1× | reported |
| RO 2025-12-17 | HermiT | 0.02 s | 0.002 s | 0.16 s | 0.1× | reported |

ELK's time moves more between benches than HOWL's does: one earlier bench had ELK at 0.58 s (GO) and
0.35 s (EL-GALEN); this one, like most, has 0.47 s and 0.28 s. Each run-to-run range is recorded in
`bench/results.txt`.

M1 slice 6b removed the rules' redundant work: each edge is admitted once, CR2/CR4 walk the smaller
side of their join, and role inclusions are matched through the told role closure rather than
copying every edge under each super-role. slop's faster maps (stored hashes, a
word-at-a-time string hash, slop-lang/slop#205) and HOWL's own triple store (term ids by content, an
SPO index and an rdf:type index, instead of slop-rdf's four-index store) a round barrier that commits in
parallel instead of merging serially, and saturation over nodes renamed to integer ids at its
boundary took S6a's 19.2× (GO) and 30.1× (EL-GALEN) to 5.05× and 6.1× with decode still inside the
window. Moving the window to axioms in hand took them to 5.3× (EL-GALEN) and 1.4× (GO), and
matching role inclusions through the closure cut EL-GALEN's reasoning by 38%. Encoding the input
once, at the boundary (below), made decode faster still.

**Memory.** Peak resident set of one full run, parse to report, W = 4. The oracles' figures are
measured two ways: at their default 32 GB heap, where the JVM's peak mostly reflects how lazily it
collects garbage, and at the smallest heap that still reproduces the certified entailments, which is
what they actually need:

| Entry | HOWL | Oracle, default heap | Oracle, smallest heap |
|---|---|---|---|
| GO | 0.57 GB | ELK 4.1–7.6 GB | ELK 0.9 GB |
| EL-GALEN | 0.59 GB | ELK 1.9 GB | ELK 0.43 GB |
| OBI | 0.10 GB | HermiT 1.4 GB | HermiT 0.24 GB |
| RO | 13 MB | HermiT 0.36 GB | HermiT 0.23 GB |

HOWL was 7.9 GB on GO before its memory work. It now parses each document straight into an encoded
form (a dictionary of owned terms and the triples as ids), frees every phase's working memory as the
phase ends, and frees each saturation round's queues a round later; every report is unchanged. Two
slop runtime changes did the rest: compact collections (#234, a Map's and Set's keys and values
inline in a dense table; GO 2.6 → 1.8 GB) and arena blocks mapped from the OS, so freeing an arena
returns its memory (#235; GO 1.8 → 0.9 GB - macOS had kept freed blocks resident). slop-rdf's
streaming parser now holds one statement's memory at a time rather than the whole document's
(slop-rdf #8; GO's parse 0.85 → 0.47 GB, EL-GALEN's 0.54 → 0.06 GB, OBI 0.24 → 0.14 GB). And the
decoded axioms are copied out of the encoded input, which is freed before the gate runs rather than
held through it (GO 0.91 → 0.6–0.8 GB). Last, each rule call's result list lives only while its
context is joined, in a per-worker arena emptied after each context, rather than to the end of the
round: that was most of a round's memory, ~300 MB in GO's busiest, and with 4 workers a peak that
moved from run to run with how their joins overlapped (GO 0.6–0.8 GB → a steady 0.57 GB, and
reasoning 14% faster). Each phase has its own high-water mark, since the one before it is freed: GO
peaks in decode, EL-GALEN in writing the report, OBI and RO in `prepare`.
Returning memory has a small time cost: later rounds touch fresh pages rather than reusing dirty ones.

| Milestone | Scope | State |
|---|---|---|
| M0 | types, front end, normalization | **done** — 14 fixtures by exit code (`make acceptance`), RO and OBI end to end (`make corpus-acceptance`), §12's accounting / idempotence / freshness invariants and triple-order independence tested |
| M1 | CR1–CR7, driver, verdict discipline | **done** — rules, driver, extraction and premise index done; RO, OBI and GO run end to end; golden reports gate performance changes (`make golden`); every fixture diff-clean against HermiT, and against ELK where probed capable (`make diff-fixtures`); the W3C OWL 2 EL tests and ELK's classification and entailment tests pass wherever HOWL reasons completely and the report can state the answer (`make conformance`); the v0 projections of RO, OBI, GO and EL-GALEN are diff-clean against their routed oracle over every class pair (`make diff-corpus`, recorded in `corpus/corpus-differential.txt`); each round is joined on worker threads and the report is byte-identical at W ∈ {1,2,4,8} for every cap, capped runs included (`make determinism`, `make test-tsan`); the §12 benchmark is **met**: GO 0.84× and EL-GALEN 2.9× ELK, axioms in hand to taxonomy (`make bench`, `bench/results.txt`); the ABox reduction is proved sound and complete ([SPEC §5.3](./SPEC.md#53-the-abox-reduction-is-sound-and-complete)) and checked against HermiT over 400 generated ontologies, and 400 more that use negation in positive positions (`make abox-fuzz`) |
| M2a | port amendments A1–A4 | consumer-side, blocking |
| M2b | port adapter | not started |
| M3 | Turtle emission + GROWL round-trip | not started |
| M4 | alignment + minimal repair | not started |

## On the way to EL++

v0 is **ELH<sub>⊥</sub><sup>R+</sup> with domain and range** — EL with role hierarchies, ⊥, role
composition, and property domains/ranges. It also accepts `¬E` as a superclass, domain or range
(or a conjunct of one), which is outside OWL 2 EL's syntax but not its logic: `C ⊑ ¬E` is
`C ⊓ E ⊑ ⊥`, and v0 rewrites it so before the gate ([SPEC §5.2](./SPEC.md#52-the-exact-v0-language)).
That is BFO's `independent continuant ⊓ ¬spatial region` domain and range. This table tracks the distance from there to EL++,
construct by construct, against both forms of the target: **EL++** the description logic (Baader,
Brandt & Lutz, 2005, extended with ranges and reflexive roles in 2008), and the **OWL 2 EL** profile,
its W3C syntax. The two are not the same list — OWL 2 EL adds `ObjectHasSelf`, keys and the built-in
properties, which the EL++ papers do not define. [§5.2](./SPEC.md#52-the-exact-v0-language) is the
authority for what HOWL does with each.

**done** — reasoned over, and tested; **done (`el++`)** — under `--profile el++` (or `auto`), while
`el` enumerates it as omitted. **not yet** — recognized and enumerated out-of-profile, so a
document using it reports *inconclusive*, never *coherent*. **non-goal** — excluded by
[§14](./SPEC.md#14-non-goals).

| Construct | EL++ | OWL 2 EL | HOWL | What it takes / how it is done |
|---|:-:|:-:|---|---|
| ***Class constructors*** | | | | |
| `owl:Thing`, `owl:Nothing` (⊤, ⊥) | ✓ | ✓ | **done** | |
| `ObjectIntersectionOf` (C ⊓ D) | ✓ | ✓ | **done** | |
| `ObjectSomeValuesFrom` (∃r.C) | ✓ | ✓ | **done** | |
| `ObjectOneOf`, one individual ({a}) | ✓ | ✓ | **done (`el++`)** | Ksc's nominal rules (27)-(29) ([SPEC §5.4](./SPEC.md#54-the-el-calculus)); classes no nominal reaches share one saturation (K6) |
| `ObjectHasValue` (∃r.{a}) | ✓ | ✓ | **done (`el++`)** | ∃r.{a}, through the nominals |
| `ObjectHasSelf` (∃r.Self) | | ✓ | **done (`el++`)** | Ksc's Self rules, on simple roles; complete by [Krö10] Theorem 2 |
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
| `ReflexiveObjectProperty` (ε ⊑ r) | ✓ | ✓ | **done (`el++`)** | ⊤ ⊑ ∃S.Self with S ⊑ r, for a fresh simple S ([SPEC §5.4](./SPEC.md#54-the-el-calculus) K0) |
| `owl:topObjectProperty`, `owl:bottomObjectProperty` | | ✓ | **done (`el++`)** | the empty role as ∃N.⊤ ⊑ ⊥; the universal role as a super-role only, elsewhere still omitted |
| ***Assertions*** | | | | |
| `ClassAssertion` (C(a)) | ✓ | ✓ | **done**† | individual(a) ⊑ C |
| `ObjectPropertyAssertion` (r(a,b)) | ✓ | ✓ | **done**† | direct edges, plus range seeds on the target |
| `SameIndividual`, `DifferentIndividuals` | via {a} | ✓ | **done (`el++`)** | equality: {a} ⊑ {b}, {a} ⊓ {b} ⊑ ⊥ |
| `NegativeObjectPropertyAssertion` | via {a} | ✓ | **done (`el++`)** | {a} ⊓ ∃r.{b} ⊑ ⊥ |
| `HasKey` | | ✓ | not yet | DL-safe over named individuals, and it infers equality; outside `el++` too |
| ***Concrete domains*** | | | | |
| `DataSomeValuesFrom`, `DataHasValue`, `DataOneOf`, `DataIntersectionOf`, data property axioms and assertions, `DatatypeDefinition` | ✓ | ✓ | **non-goal** | the consumer partitions datatype axioms off rather than HOWL growing a concrete domain |

† Sound and complete by the argument in [SPEC §5.3](./SPEC.md#53-the-abox-reduction-is-sound-and-complete)
(M1 (f), reviewed 2026-09-30): a reduction to the published EL++ calculus on a nominal-free CBox and
its range-restriction extension, with the ABox's nominals discharged by a canonical-model argument
(the published completeness for nominals fails, KKS12), plus the steps specific to HOWL's direct-edge
encoding. `make abox-fuzz` checks the code against it: 400 generated ontologies with ABoxes, every one matching HermiT.

**21 of 23 rows done**, 14 under `el` and 7 more under `el++`. What stays open is `HasKey` and
concrete domains (the non-goal), and `owl:topObjectProperty` outside a super-role position. The
`el++` profile is built on Krötzsch's Ksc calculus, the one published proof that covers nominals
together with ⊥, role chains, ranges and Self ([SPEC §5.4](./SPEC.md#54-the-el-calculus)).
Its engine shares one saturation across every class no nominal reaches (§5.4 K6), and reads role
inclusions through the told hierarchy instead of copying each edge to every super-role (K7), so a
nominal-free ontology costs a small multiple of what it costs `el`: on one thread GO reasons in
0.86 s and EL-GALEN in 3.75 s, about 1.5× and 2× `el`. Its rounds are barriers, as `el`'s are, so
phases G and W derive and commit on every worker, over a store sharded by element: at four,
EL-GALEN takes 1.3 s and GO 0.40 s, and at eight 0.90 s and 0.31 s. It stores facts as dense ids, so
EL-GALEN peaks at 0.81 GB on one worker (0.64 GB on four), against `el`'s 0.44 GB, and GO at 0.62 GB,
against 0.57 GB. Select it with `--profile el++`, or let `auto` choose it.

**`el++`'s evidence**, each a `make` target that runs both rungs:
- **Probes:** 9 capability probes, one or more per construct it adds. Each is
  load-bearing: deleting the construct loses the entailment for both HOWL and HermiT. HOWL and
  HermiT pass all 9; ELK passes 3 (`hasValue`, `Self` on the right, reflexive roles), so it gates
  nothing that uses nominals, equality or `Self` on the left.
- **Fixtures:** all 121 that `el++` takes whole, its own included, are diff-clean
  against HermiT, and against ELK where it is probed capable. HermiT cannot reason over
  `owl:Thing ⊑ owl:Nothing` (its normalization builds an empty union), so that fixture is ELK's.
- **Conformance:** 105 W3C and ELK tests are checkable under `el++` (81 under `el`), none failing.
- **Corpus:** the `el++` projections of RO, OBI (keeping its 146 `hasValue` axioms), GO and
  EL-GALEN are diff-clean against their routed oracle over every class pair. On the v0
  projections, `el` and `el++` give identical reports.
- **Fuzzing:** 400 generated ontologies with nominals, `Self`, reflexive roles, equality,
  inequality and negative assertions match HermiT (211 of them inconsistent).
- **Determinism:** reports are byte-identical at every worker count for every round cap from 0 to
  R, which cuts each of phase G, phase W and phase Q.
- **Bench** (`make bench-el++`, informational, W = 4): OBI 0.03× and RO 0.10× HermiT; GO 0.95× and
  EL-GALEN 5.25× ELK (`el`: 0.84× and 2.9×).
`horn-sriq` ([§12](./SPEC.md#12-milestones--acceptance-criteria)) follows; it contains v0 but not
EL++'s nominals.

**Off the path entirely.** These are outside OWL 2 EL, so no progress toward EL++ reaches them; they
are recognized and enumerated like every open row above.

| Construct | Where it lives |
|---|---|
| `ObjectUnionOf`, `ObjectAllValuesFrom`, cardinalities, `DisjointUnion`, `ObjectOneOf` with several members | outside EL entirely — `sriq` (v2); several-member `ObjectOneOf` needs nominals, which no rung plans |
| `ObjectComplementOf` | **done** where it is a superclass, domain or range (or a conjunct of one): rewritten into ⊥ axioms, an exact equivalence. Anywhere else — under `∃`, in a union, on the left — `sriq` (v2) |
| `InverseObjectProperties`, functional / inverse-functional, qualified cardinality | **the largest real gap** — `horn-sriq` (v1) |
| `DisjointObjectProperties`, symmetric / asymmetric / irreflexive | outside OWL 2 EL — `horn-sriq` (v1) |
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
make lib      # static library; its API is include/howl.h, generated by slop from src/howl.slop
make c-example    # the C API: examples/c/classify.c on the litmus, and every entry point under ASan/UBSan
make verify   # Z3 contract checking (needs the SLOP toolchain + z3)
make example      # executable @example blocks: the completion rules, canon, context coverage
make crate-test   # Rust crate: layout guards, API tests, every golden reproduced through it
make crate-package  # the crate as `cargo publish` would package it (dry run, no upload)
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

Every one of these also runs the `el++` rung, on its own inputs and records: `probes` over
`corpus/fixtures/probes-el++/`, `diff-fixtures` adding `corpus/fixtures/el++/`, `conformance` into
`corpus/conformance-status-el++.txt`, `materialize` and `diff-corpus` over the `el++` projections
(`corpus/projections/el++/`, recorded in `corpus/corpus-differential-el++.txt`), plus
`differential.py rungs` (`el` and `el++` must agree on every v0 projection), `abox-fuzz --elpp`,
`determinism --profile el++` and `make bench-el++` (`bench/results-el++.txt`, informational).

Working on the SLOP sources needs the toolchain:

```sh
make slop-build   # rebuild via slop
make csrc         # regenerate the committed C and include/howl.h — commit the result
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
rust/             the `howl` crate: a safe API over the C API, layout guards (rust/README.md)
include/howl.h    the public C API's header, generated by slop from src/howl.slop's `:c-name` functions
examples/c/       a C caller of the API, and its ASan/UBSan test
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
exposed are true but **owed** as contracts ([SPEC §7](./SPEC.md#7-verification--contracts)):
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

## The Rust crate and its layout guards

HOWL's public C API is written in SLOP (the `:c-name` functions in `src/howl.slop`) and slop
generates its header, `include/howl.h`; `examples/c/classify.c` is a complete C caller. `rust/` is
the `howl` crate ([`rust/README.md`](rust/README.md)), which binds that API: `Input`, then
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

## Read next

[**`SPEC.md`**](./SPEC.md) — the full design: calculus choice, the exact v0 language, data model,
verification posture, the MOOSE port, milestones, and the "when is it actually a DL reasoner?"
threshold. `spec/human/` has PDF renderings, including a 6-page condensed version.
