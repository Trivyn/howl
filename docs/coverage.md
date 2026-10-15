# What HOWL reasons over

This page lists, construct by construct, what each profile reasons over and what it reports as
omitted. It also collects the evidence for the `el++` profile.
[SPEC §5.2](../SPEC.md#52-the-exact-v0-language) is the authority on what HOWL does with each
construct. For what an omission means for a verdict, see the
[README](../README.md#verdicts-and-exit-codes).

## Distance to EL++

The `el` profile, called v0 in the SPEC, covers **ELH<sub>⊥</sub><sup>R+</sup> with domain and
range**. That is EL with role hierarchies, ⊥, role composition, and property domains and ranges.

It also accepts `¬E` as a superclass, domain or range, or as a conjunct of one. That is outside
OWL 2 EL's syntax but not its logic, because `C ⊑ ¬E` means `C ⊓ E ⊑ ⊥`. HOWL rewrites it that way
before the gate. BFO needs this for its `independent continuant ⊓ ¬spatial region` domain and range.

The table below measures the distance from there to two targets:

- **EL++**, the description logic (Baader, Brandt & Lutz, 2005), extended with ranges and reflexive
  roles in 2008.
- **OWL 2 EL**, the W3C profile. It adds `ObjectHasSelf`, keys and the built-in properties, which
  the EL++ papers do not define.

The HOWL column uses five values:

- **done**: reasoned over and tested.
- **done (`el++`)**: reasoned over under `--profile el++` or `auto`. Under `el` it is reported as
  omitted.
- **not yet**: recognized and reported as omitted, so a document that uses it is *inconclusive*,
  never *coherent*.
- **non-goal**: excluded by [§14](../SPEC.md#14-non-goals).
- **inert, every rung**: set aside by every profile, because leaving it out provably changes no
  answer.

| Construct | EL++ | OWL 2 EL | HOWL | What it takes / how it is done |
|---|:-:|:-:|---|---|
| ***Class constructors*** | | | | |
| `owl:Thing`, `owl:Nothing` (⊤, ⊥) | ✓ | ✓ | **done** | |
| `ObjectIntersectionOf` (C ⊓ D) | ✓ | ✓ | **done** | |
| `ObjectSomeValuesFrom` (∃r.C) | ✓ | ✓ | **done** | |
| `ObjectOneOf`, one individual ({a}) | ✓ | ✓ | **done (`el++`)** | Ksc's nominal rules (27)-(29) ([SPEC §5.4](../SPEC.md#54-the-el-calculus)); classes no nominal reaches share one saturation (K6) |
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
| `ReflexiveObjectProperty` (ε ⊑ r) | ✓ | ✓ | **done (`el++`)** | ⊤ ⊑ ∃S.Self with S ⊑ r, for a fresh simple S ([SPEC §5.4](../SPEC.md#54-the-el-calculus) K0) |
| `owl:topObjectProperty`, `owl:bottomObjectProperty` | | ✓ | **done (`el++`)** | the empty role as ∃N.⊤ ⊑ ⊥; the universal role as a super-role only, elsewhere still omitted |
| ***Assertions*** | | | | |
| `ClassAssertion` (C(a)) | ✓ | ✓ | **done**† | individual(a) ⊑ C |
| `ObjectPropertyAssertion` (r(a,b)) | ✓ | ✓ | **done**† | direct edges, plus range seeds on the target |
| `SameIndividual`, `DifferentIndividuals` | via {a} | ✓ | **done (`el++`)** | equality: {a} ⊑ {b}, {a} ⊓ {b} ⊑ ⊥ |
| `NegativeObjectPropertyAssertion` | via {a} | ✓ | **done (`el++`)** | {a} ⊓ ∃r.{b} ⊑ ⊥ |
| `HasKey` | | ✓ | not yet | DL-safe over named individuals, and it infers equality; outside `el++` too |
| ***Concrete domains*** | | | | |
| Domain, range, sub-property, equivalence, disjointness and functionality axioms of *idle* data properties (neither the property nor any data property below it is used in a class expression, assertion or key) | ✓ | ✓ | **inert, every rung** | the data lemma ([SPEC §5.2](../SPEC.md#52-the-exact-v0-language)): emptying an idle property changes no answer |
| `DataSomeValuesFrom`, `DataHasValue`, `DataOneOf`, `DataIntersectionOf`, data assertions, `DatatypeDefinition`, and the property axioms of data properties that are used | ✓ | ✓ | **non-goal** | the consumer partitions datatype axioms off rather than HOWL growing a concrete domain |

† Sound and complete by the argument in
[SPEC §5.3](../SPEC.md#53-the-abox-reduction-is-sound-and-complete), reviewed 2026-09-30 as M1 (f).
The argument reduces to the published EL++ calculus on a nominal-free CBox and its
range-restriction extension. It discharges the ABox's nominals with a canonical-model argument,
because the published completeness proof for nominals fails (KKS12). It also covers the steps
specific to HOWL's direct-edge encoding. `make abox-fuzz` checks the code against it: 400 generated
ontologies with ABoxes, each matching HermiT.

**21 of the 24 rows are done**: 14 under `el`, and 7 more under `el++`. Still open are `HasKey`,
`owl:topObjectProperty` outside a super-role position, and concrete domains, which are a non-goal.

`el++` is built on Krötzsch's Ksc calculus. It is the one published proof that covers nominals
together with ⊥, role chains, ranges and Self ([SPEC §5.4](../SPEC.md#54-the-el-calculus)). A few
design points keep it close to `el`'s cost:

- One saturation is shared by every class that no nominal reaches (§5.4 K6).
- Role inclusions are read through the told hierarchy, rather than copying each edge to every
  super-role (K7).
- Rounds are barriers, as in `el`, so phases G and W derive and commit on every worker, over a store
  sharded by element.
- Facts are stored as dense ids.

As a result, a nominal-free ontology costs a small multiple of what it costs under `el`. Timings
and memory are in [performance.md](performance.md). Select it with `--profile el++`, or let `auto`
choose it.

## Evidence for the `el++` profile

Each of these is a `make` target that runs both `el` and `el++`.

- **Probes.** There are 9 capability probes, at least one per construct `el++` adds. Each probe
  depends on its construct: deleting the construct loses the entailment for both HOWL and HermiT.
  HOWL and HermiT pass all 9. ELK passes 3 (`hasValue`, `Self` on the right, and reflexive roles),
  so ELK is not used as an oracle for anything involving nominals, equality or `Self` on the left.
- **Fixtures.** All 121 fixtures that `el++` takes whole, including its own, match HermiT, and match
  ELK where ELK is probed capable. HermiT cannot reason over `owl:Thing ⊑ owl:Nothing`, because its
  normalization builds an empty union, so ELK is the oracle for that fixture.
- **Conformance.** 105 W3C and ELK tests can be checked under `el++`, and 81 under `el`. None fail.
- **Corpus.** The `el++` projections of RO, OBI, GO and EL-GALEN match their oracle over every class
  pair. OBI keeps its 146 `hasValue` axioms. On the v0 projections, `el` and `el++` give identical
  reports.
- **Fuzzing.** 400 generated ontologies with nominals, `Self`, reflexive roles, equality,
  inequality and negative assertions match HermiT. 211 of them are inconsistent.
- **Determinism.** Reports are byte-identical at every worker count, for every round cap from 0 to
  R. That range cuts each of phase G, phase W and phase Q.
- **Benchmarks.** `make bench-el++` is informational. The latest figures are in
  [performance.md](performance.md#the-el-profile).

## Outside OWL 2 EL

No progress toward EL++ reaches these constructs. Under `el` and `el++` they are recognized and
reported as omitted, like every open row above.

The `sriq` profile ([SPEC §5.5](../SPEC.md#55-the-sriq-calculus), M5 in
[§12](../SPEC.md#12-milestones--acceptance-criteria)) is built, and selected with `--profile sriq` or
`auto`. It contains v0 but not EL++'s nominals, and it takes every row below marked `sriq`. A run
that exceeds its clause budget is inconclusive, and `auto` then steps down to `el` or `el++`.

| Construct | Where it lives |
|---|---|
| `ObjectUnionOf`, `ObjectAllValuesFrom`, cardinalities, `DisjointUnion` | outside EL entirely; `sriq` ([SPEC §5.5](../SPEC.md#55-the-sriq-calculus)) |
| `ObjectOneOf` with several members | needs class nominals, which `sriq` leaves out. A later `sroiq` rung would take it, and none is planned |
| `ObjectComplementOf` | **done** as a superclass, domain or range, or a conjunct of one, by an exact rewrite into ⊥ axioms. Anywhere else (under `∃`, in a union, on the left) it is `sriq` |
| `InverseObjectProperties`, functional and inverse-functional properties, qualified cardinality | the largest real gap; `sriq` |
| `DisjointObjectProperties`, symmetric, asymmetric and irreflexive properties | outside OWL 2 EL; `sriq` |
| Anonymous individuals, reserved IRIs as entity names | excluded by OWL 2 EL, or forbidden by OWL 2 |
| SWRL rules | never, at any rung. Unrestricted SWRL is undecidable, and it is in neither OWL 2 DL nor OWL 2 EL |

## What happens to a construct that isn't done

Every recognized construct gets exactly one of four dispositions:

| Disposition | Meaning | Constructs |
|---|---|---|
| **in v0** | reasoned over | every **done** row above |
| **consumed** | read, but yields no axiom | declarations. These are not ignored: dropping them would lose classes that are declared but unused |
| **inert** | semantically empty in OWL 2 | `AnnotationAssertion`, `SubAnnotationPropertyOf`, `AnnotationProperty{Domain,Range}`, the ontology header, axiom-annotation reification |
| **out-of-profile** | recognized and reported as omitted, never silently dropped | every other row above |

The dispositions are a `match` over `RawAxiom` with no catch-all arm, compiled with
`-Werror=switch`. Adding a construct without giving it a disposition is a build error. So moving a
row to **done** starts at that `match`.

A triple whose predicate is an undeclared user property fits none of the four. Without a
declaration, HOWL cannot tell whether it is an object, data or annotation assertion. It is reported
as an `UndeclaredProperty(<iri>)` omission, one per property, so it also keeps the run from passing.

**Why omissions are reported rather than skipped.** A rejected axiom lands in `coverage.omitted`
with a canonical `AxiomRef`, which forces the verdict to *inconclusive*. This is the core safety
property: HOWL never reports *coherent* for an ontology it only partly read. `make test` checks both
directions. All 17 `v0/` fixtures pass the gate cleanly, and all 15 `out-of-profile/` fixtures yield
at least one omission. `make census`, written independently, cross-checks this.

**The gate checks operands as well as forms.** §5.2's table classifies axiom forms, but
ELH<sub>⊥</sub><sup>R+</sup> also restricts the operands those forms carry. For example,
`SubClassOf(A, ObjectUnionOf(B,C))` is an in-profile form carrying a concept the fragment cannot
express. The gate checks both. A built-in role is caught wherever it occurs, not only in the shape
a fixture happens to use.
