# What HOWL reasons over

[SPEC §5.2](../SPEC.md#52-the-exact-v0-language) is the authority. This page tracks, construct by
construct, what each built profile reasons over, what it reports as omitted, and the evidence for
`el++`. For what an omission means for a verdict, see the [README](../README.md#verdicts-and-exit-codes).

## Distance to EL++

v0 is **ELH<sub>⊥</sub><sup>R+</sup> with domain and range** — EL with role hierarchies, ⊥, role
composition, and property domains/ranges. It also accepts `¬E` as a superclass, domain or range
(or a conjunct of one), which is outside OWL 2 EL's syntax but not its logic: `C ⊑ ¬E` is
`C ⊓ E ⊑ ⊥`, and v0 rewrites it so before the gate ([SPEC §5.2](../SPEC.md#52-the-exact-v0-language)).
That is BFO's `independent continuant ⊓ ¬spatial region` domain and range. This table tracks the distance from there to EL++,
construct by construct, against both forms of the target: **EL++** the description logic (Baader,
Brandt & Lutz, 2005, extended with ranges and reflexive roles in 2008), and the **OWL 2 EL** profile,
its W3C syntax. The two are not the same list — OWL 2 EL adds `ObjectHasSelf`, keys and the built-in
properties, which the EL++ papers do not define. [§5.2](../SPEC.md#52-the-exact-v0-language) is the
authority for what HOWL does with each.

**done** — reasoned over, and tested; **done (`el++`)** — under `--profile el++` (or `auto`), while
`el` enumerates it as omitted. **not yet** — recognized and enumerated out-of-profile, so a
document using it reports *inconclusive*, never *coherent*. **non-goal** — excluded by
[§14](../SPEC.md#14-non-goals).

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
| `DataSomeValuesFrom`, `DataHasValue`, `DataOneOf`, `DataIntersectionOf`, data property axioms and assertions, `DatatypeDefinition` | ✓ | ✓ | **non-goal** | the consumer partitions datatype axioms off rather than HOWL growing a concrete domain |

† Sound and complete by the argument in [SPEC §5.3](../SPEC.md#53-the-abox-reduction-is-sound-and-complete)
(M1 (f), reviewed 2026-09-30): a reduction to the published EL++ calculus on a nominal-free CBox and
its range-restriction extension, with the ABox's nominals discharged by a canonical-model argument
(the published completeness for nominals fails, KKS12), plus the steps specific to HOWL's direct-edge
encoding. `make abox-fuzz` checks the code against it: 400 generated ontologies with ABoxes, every one matching HermiT.

**21 of 23 rows done**, 14 under `el` and 7 more under `el++`. What stays open is `HasKey` and
concrete domains (the non-goal), and `owl:topObjectProperty` outside a super-role position. The
`el++` profile is built on Krötzsch's Ksc calculus, the one published proof that covers nominals
together with ⊥, role chains, ranges and Self ([SPEC §5.4](../SPEC.md#54-the-el-calculus)).
Its engine shares one saturation across every class no nominal reaches (§5.4 K6), and reads role
inclusions through the told hierarchy instead of copying each edge to every super-role (K7), so a
nominal-free ontology costs a small multiple of what it costs `el`. Its rounds are barriers, as
`el`'s are, so phases G and W derive and commit on every worker, over a store sharded by element,
and it stores facts as dense ids. Its timings and memory are in [performance.md](performance.md).
Select it with `--profile el++`, or let `auto` choose it.

## The `el++` profile's evidence

Each is a `make` target that runs both rungs:
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
`horn-sriq` ([§12](../SPEC.md#12-milestones--acceptance-criteria)) follows; it contains v0 but not
EL++'s nominals.

## Off the path entirely

These are outside OWL 2 EL, so no progress toward EL++ reaches them; they
are recognized and enumerated like every open row above.

| Construct | Where it lives |
|---|---|
| `ObjectUnionOf`, `ObjectAllValuesFrom`, cardinalities, `DisjointUnion`, `ObjectOneOf` with several members | outside EL entirely — `sriq` (v2); several-member `ObjectOneOf` needs nominals, which no rung plans |
| `ObjectComplementOf` | **done** where it is a superclass, domain or range (or a conjunct of one): rewritten into ⊥ axioms, an exact equivalence. Anywhere else — under `∃`, in a union, on the left — `sriq` (v2) |
| `InverseObjectProperties`, functional / inverse-functional, qualified cardinality | **the largest real gap** — `horn-sriq` (v1) |
| `DisjointObjectProperties`, symmetric / asymmetric / irreflexive | outside OWL 2 EL — `horn-sriq` (v1) |
| Anonymous individuals, reserved IRIs as entity names | excluded by OWL 2 EL / forbidden by OWL 2 |
| SWRL rules | **never**, at any rung — unrestricted SWRL is undecidable, and it is in neither OWL 2 DL nor OWL 2 EL |

## What happens to a construct that isn't done

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
