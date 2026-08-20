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

## Owed

- **Projections.** Each pinned entry needs its v0 projection generated, hashed,
  and recorded beside the source hash. Projection is part of the fixture, never a
  step the benchmark performs on the fly — otherwise neither the numbers nor the
  diff are reproducible.
- **GALEN**, per §12 — and the *variant* is part of the pin, since "GALEN" names
  several ontologies of very different difficulty.
- **Oracle pins.** ELK and HermiT versions, with a capability probe per v0
  construct at harness startup. `java` is available locally. An oracle that fails
  a construct's probe is not an oracle for that construct — ELK and object
  property ranges being the case that matters.
