# HOWL test corpus

Three tiers, separated by what they can prove and what it costs to keep them.

```
corpus/
  fixtures/          committed, hand-written, 43 files — the only tier in git
    v0/              one per in-profile construct        (17)
    hazards/         the fail-silent cases               (12)
    out-of-profile/  one per construct the gate must enumerate (14)
  MANIFEST.toml      pinned external ontologies: versioned URL + SHA-256
  fetch.sh           fetch + verify           (`make corpus`)
  census.py          construct census against SPEC.md §5.2
  project.py         v0 projections as removal lists (`make project`)
  projections/       committed — 122 KB total, one file per pinned entry
  vendor/            fetched ontologies — gitignored
```

## Why the fixtures are hand-written

Every file under `fixtures/` pins one behaviour, and its header comment says which
and *why getting it wrong is silent*. They are not illustrations. `hazards/` in
particular is a list of ways a reasoner can look correct while being wrong —
several are drawn from defects found in review rather than invented:

| Fixture | Pins |
|---|---|
| `litmus.ttl` | §3.1 — derives `Mother ⊑ Parent`, or HOWL is a materialization engine |
| `annotation-heavy.ttl` | M0 (a) — a versioned, annotated ontology gates **clean** |
| `unattested-import.ttl` | M0 (b) — a dangling import yields non-empty `coverage.omitted` |
| `declared-unused-class.ttl` | M0 (c) — a declared-but-unmentioned class still gets a context |
| `owl-nothing-present.ttl` | `owl:Nothing` excluded by name, or every ontology self-reports incoherent |
| `abox-disjoint-range.ttl` | the smallest case distinguishing the two ABox encodings |
| `seed-only-entailment.ttl` | seeds must reach **both** the delta and the round-0 snapshot |
| `rbox-regularity-accept.ttl` | the RBox gate must **accept** equivalent simple roles and transitivity |
| `cyclic-hierarchy.ttl` | `A ⊑ B, B ⊑ A` terminates instead of burning the budget |

## The census, and why it is independent

`census.py` classifies every recognized construct as in-v0 / inert / consumed /
out-of-profile, directly from §5.2's disposition table.

**It is deliberately not a wrapper over HOWL's own gate.** If the projection that
guarantees "empty `coverage.omitted`" were produced by the very gate under test,
the acceptance criterion would be self-certifying and check nothing. Built
separately, HOWL's gate *agreeing* with it becomes a real cross-check — and the
two disagreeing is a finding either way.

It is also not assumed correct. Running it over `fixtures/` cross-checks both:
every `v0/` fixture must come back clean and every `out-of-profile/` fixture must
come back with at least one omission. That check has already caught a gap in the
census (built-in roles) and, on its first run against RO, a bug in the census that
is *exactly* M0 acceptance (a) — 350 `owl:annotatedTarget` triples bucketed as
out-of-profile because the literal test ran before the header test.

## Measured fitness

Every real ontology needs projection; none is clean as shipped.

| Ontology | logical axioms | in v0 | out-of-profile | |
|---|---:|---:|---:|---|
| **GO** | 117,791 | 117,790 | **1** | one `owl:inverseOf` — the benchmark target |
| **OBI** | 26,813 | 26,403 | 410 (1.5%) | primary differential entry |
| CCO | 2,939 | 2,697 | 242 (8.2%) | 127 inverses — the M5 gap, measured |
| RO | 1,983 | 1,465 | 518 (26.1%) | the RBox exercise; 25 SWRL rules |
| BFO-core | 266 | 176 | 90 (33.8%) | poor v0 fit; belongs to M5 |

Two things worth knowing before choosing an entry. **BFO is the worst fit despite
being foundational** — projecting it would gut it, so it is an M5 ontology, not a
v0 one. And **RO is where the RBox lives**: 160 property chains and 45 transitive
properties, against CR6/CR7 having no fixtures of their own.

## Usage

```sh
make corpus                     # fetch + verify everything in MANIFEST.toml
./corpus/fetch.sh go            # just one
python3 corpus/census.py FILE…  # construct census
```

## Projections are removal lists, not projected copies

§10 requires each entry's v0 projection to be **pinned in the repo, never computed
on the fly** — otherwise neither the benchmark numbers nor the differential diff
are reproducible. But a projected copy of GO is still ~124 MB, over GitHub's
per-file limit and 50× this repo's entire history.

So `projections/<name>-<version>.removals` records the axioms **removed**:

```
projected theory  ==  pinned source  MINUS  the removal list
```

GO's entire projection is one line:

```
<...obo/BFO_0000050> <owl#inverseOf> <...obo/BFO_0000051> .    # InverseObjectProperties
```

Three properties a projected copy would not have. It is **small** — 122 KB for all
three entries against 135 MB of copies. It is **auditable** — you read exactly
which axioms went and why, which is what §5.1 demands when it says an
out-of-profile axiom must be enumerated, never silently dropped. And it is
**reviewable** — a projection that quietly grows appears in a git diff instead of
hiding inside a large blob.

`make project` regenerates; `make project-verify` re-derives and **fails on
drift**, which is what CI should run.

### Two things the implementation had to get right

**Removal is a closure, not a triple.** An OWL axiom is rarely one triple — a
restriction, union or chain is a blank-node structure. Deleting the seed alone
leaves a dangling reference to a half-deleted structure: not a smaller ontology,
a malformed one. So a blank node's whole description goes, plus whatever points
at it, recursively.

**Determinism had to be built in, not sorted in.** The first version produced a
*different* removal list on every run, because grouping followed graph iteration
order and that depends on parser-assigned blank-node labels. Closures sharing a
triple are now merged into connected components, which is order-independent by
construction; ordering keys render blank nodes uniformly so the unstable labels
cannot re-enter through the back door. A projection that cannot be re-derived is
worse than none — every number taken against it is unreproducible.

### Collateral is reported, never hidden

Removing an out-of-profile conjunct takes its whole intersection with it,
including in-profile existentials nested alongside — you cannot keep half an
intersection. Each removal list reports `in_v0_swept_in` for exactly this:

| Entry | axioms removed | triples | in-v0 swept in |
|---|---:|---:|---:|
| GO | 1 | 1 | **0** |
| RO | 388 | 1,626 | 62 |
| OBI | 383 | 5,828 | **1,243** |
| EL-GALEN | 0 | 0 | 0 |

RO's and OBI's grew in M1 slice 4, when the census learned what HOWL's gate already
refused: RO's 48 property chains that break §5.2's range/composition condition
(with the `owl:Axiom` reifications of three of them — stage 0 would otherwise
rebuild those chains), and OBI's one data-property sub-property axiom. Each then
shrank by two when §5.2 took in negation in positive positions: RO's domain and
range of RO_0001025 (`BFO_0000004 ⊓ ¬BFO_0000006`), and OBI's two
`CL_0000001 ⊑ ¬∃r.E` axioms.

**This changes corpus selection.** OBI looks like a 1.5% out-of-profile entry, but
its projection costs ~4.7% of its in-profile content. GO's costs nothing at all —
which makes it not merely the best benchmark entry but the only one whose
projected theory is essentially the ontology as published.

## The materialized projections and the corpus differential (M1 slice 4)

- **`make materialize`** writes each projected ontology to `vendor/<name>.v0.ttl`
  (not committed). It is pinned by content, not bytes: the file is read back, and
  its ground-triple hash and blank-node count must match the `.removals` header,
  and census must find nothing out of profile in it. `make project-verify`
  re-checks an existing one.
- **Census and HOWL's gate agree** on every entry: HOWL reads each materialized
  file with `omitted 0` (`make corpus-acceptance`). That is the cross-check the
  independent census was built for, and it found three things census had missed
  (above).
- **`make diff-corpus`** diffs each materialized entry against its routed oracle:
  ELK for GO and EL-GALEN, HermiT for the range-bearing RO and OBI. Every ordered
  pair of named classes is compared, and the outcome is recorded in
  `corpus-differential.txt`: all four clean.
- **EL-GALEN** is pinned from the DReW copy of the ELK authors' `EL-GALEN.owl`
  (MANIFEST `provenance`). It is functional syntax, so `fetch.sh` converts it
  with the pinned OWL API (`make oracle` first); that conversion is deterministic,
  so its output is pinned too (`derived_sha256`).
