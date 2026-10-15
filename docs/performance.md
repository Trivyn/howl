# Performance

Every figure here comes from `make bench` or `make bench-el++` on an Apple M3 Ultra, recorded in
`bench/results.txt` and `bench/results-el++.txt`. Rows marked historical are the exception. Every
timed run reproduced the certified report.

## Real ontologies, not just fixtures

All the fixtures passed while the first real ontologies failed. Each failure is fixed and pinned by
`make corpus-acceptance`:

| Ontology | Before the fix (historical) | When fixed (historical) | Now (`bench/results.txt`, W = 4) |
|---|---|---|---|
| RO 2025-12-17 (11.6k triples) | exit 3: an inverse property in a property chain faulted the whole document | exit 2, 0 unsatisfiable, 845 omitted | 275 subsumptions, 19 ms classify |
| OBI 2026-07-27 (118k triples) | exit 1, *inconsistent*: every complex range filler of a role shared one fresh node | exit 2, 0 unsatisfiable, 38,681 subsumptions, 1.0 s (reasoning 0.4 s) | 508 omitted, 48 ms classify, 0.14 s end to end |
| GO 2026-07-26 (1.4M triples) | never finished: the header pass scanned lists per triple, and every fact was matched against every axiom | exit 2, 0 unsatisfiable, 1 omitted (one `owl:inverseOf`), 459,329 subsumptions, 13.4 s (reasoning 5.5 s) | 0.42 s classify (reasoning 0.30 s), 1.7 s end to end |

Rule dispatch goes through a premise index, so each rule sees only the axioms it could fire on.
That took OBI's reasoning from 172 s to 0.4 s, with its report unchanged byte for byte.

## The §12 benchmark: met

`make bench` times each corpus entry against its oracle on the same machine. The protocol:

- Each side gets the median of 5 runs after 1 warm-up, with 4 workers (W = 4).
- The timed window runs from axioms in hand to taxonomy. For HOWL that is the gate, normalization,
  indexing and reasoning. For the oracle it is reasoner creation, the consistency check and
  classification.
- Parsing and the RDF-to-axiom mapping are untimed on both sides. HOWL's decode time is shown beside
  the ratio anyway.
- Every timed input and report must be the certified one.

HOWL's run-to-run range is within a few percent. The oracles vary more: EL-GALEN's ELK ran
271–352 ms around its 290 ms median. Each range is recorded in `bench/results.txt`.

| Entry | Oracle | HOWL classify | HOWL decode (untimed) | Oracle classify | Ratio | |
|---|---|---|---|---|---|---|
| GO 2026-07-26 | ELK 0.6.0 | 0.42 s (reasoning 0.30 s), 0.57 GB peak | 0.51 s | 0.51 s | 0.84× | **passes** 5× |
| EL-GALEN | ELK 0.6.0 | 0.87 s (reasoning 0.69 s), 0.60 GB peak | 0.08 s | 0.29 s | 3.0× | **passes** 5× |
| OBI 2026-07-27 | HermiT | 0.05 s | 0.04 s | 0.54 s | 0.1× | reported |
| RO 2025-12-17 | HermiT | 0.02 s | 0.003 s | 0.14 s | 0.1× | reported |

ELK's time also moves more between benches than HOWL's. Earlier benches had ELK at 0.46–0.58 s on
GO and 0.28–0.35 s on EL-GALEN. This one, on 0.5.0 (2026-10-14), has 0.51 s and 0.29 s.

### How the ratios came down

At M1 slice 6a, HOWL was 19.2× ELK on GO and 30.1× on EL-GALEN. These changes brought that to 5.05×
and 6.1×, with decode still inside the timed window:

- Slice 6b removed the rules' redundant work. Each edge is admitted once, and CR2 and CR4 walk the
  smaller side of their join.
- slop's faster maps, with stored hashes and a word-at-a-time string hash (slop-lang/slop#205).
- HOWL's own triple store, with term ids by content, an SPO index and an `rdf:type` index, in place
  of slop-rdf's four-index store.
- A round barrier that commits in parallel instead of merging serially.
- Saturation over nodes renamed to integer ids at its boundary.

Moving the timed window to start from axioms in hand then gave 1.4× on GO and 5.3× on EL-GALEN.
Matching role inclusions through the told role closure, rather than copying every edge under each
super-role, cut EL-GALEN's reasoning by 38%. Encoding the input once at the boundary, described
below, made decode faster still.

## Memory

This is the peak resident set of one full run, from parse to report, with 4 workers. The oracles
are measured two ways. At their default 32 GB heap, the JVM's peak mostly reflects how lazily it
collects garbage. At the smallest heap that still reproduces the certified entailments, the figure
shows what they actually need.

| Entry | HOWL | Oracle, default heap | Oracle, smallest heap |
|---|---|---|---|
| GO | 0.57 GB | ELK 4.1–7.6 GB | ELK 0.9 GB |
| EL-GALEN | 0.60 GB | ELK 1.9 GB | ELK 0.43 GB |
| OBI | 0.11 GB | HermiT 1.4 GB | HermiT 0.24 GB |
| RO | 14 MB | HermiT 0.36 GB | HermiT 0.23 GB |

### How memory came down

HOWL used 7.9 GB on GO before its memory work. Every report stayed unchanged through these steps:

- **HOWL's own changes.** Each document is parsed straight into an encoded form: a dictionary of
  owned terms, with the triples as ids. Each phase frees its working memory when it ends, and each
  saturation round's queues are freed one round later.
- **Compact collections** in the slop runtime (#234). Maps and Sets store keys and values inline in
  a dense table. GO went from 2.6 to 1.8 GB.
- **Arena blocks mapped from the OS** (#235), so freeing an arena returns its memory. GO went from
  1.8 to 0.9 GB. macOS had been keeping freed blocks resident.
- **slop-rdf's streaming parser** (slop-rdf #8) holds one statement's memory at a time instead of
  the whole document's. Parse peaks fell from 0.85 to 0.47 GB on GO, 0.54 to 0.06 GB on EL-GALEN,
  and 0.24 to 0.14 GB on OBI.
- **Freeing the encoded input before the gate.** The decoded axioms are copied out of it, so it no
  longer has to be held through the gate. GO went from 0.91 GB to 0.6–0.8 GB.
- **A per-worker arena for rule results.** Each rule call's result list now lives only while its
  context is joined, in an arena emptied after each context, rather than to the end of the round.
  That had been most of a round's memory, about 300 MB in GO's busiest round. With 4 workers the
  peak also varied from run to run, depending on how their joins overlapped. GO now sits at a steady
  0.57 GB instead of 0.6–0.8 GB, and reasons 14% faster.

Since each phase frees the one before it, each phase has its own high-water mark. GO peaks in
decode, EL-GALEN in writing the report, and OBI and RO in `prepare`.

Returning memory has a small time cost, because later rounds touch fresh pages instead of reusing
dirty ones.

## The `el++` profile

`make bench-el++` is informational. §12 sets a threshold for `el` against ELK, and none for
`el++`. With 4 workers (`bench/results-el++.txt`):

| Entry | Oracle | `el++` classify | Ratio | `el` ratio |
|---|---|---|---|---|
| GO | ELK | 0.52 s (reasoning 0.43 s), 0.65 GB peak | 1.2× | 0.84× |
| EL-GALEN | ELK | 1.42 s (reasoning 1.33 s), 0.77 GB peak | 5.2× | 3.0× |
| OBI | HermiT | 0.09 s | 0.03× | 0.1× |
| RO | HermiT | 0.02 s | 0.11× | 0.1× |

ELK took 0.43 s on GO in this run, against 0.51 s in the `el` run. That accounts for most of the
gap between the two GO ratios.

Scaling with workers was measured on reasoning time alone, when the parallel commit landed, with
runs interleaved against the previous engine:

| Workers | GO | EL-GALEN |
|---|---|---|
| 1 | 0.86 s (about 1.5× `el`) | 3.75 s (about 2× `el`) |
| 4 | 0.40 s | 1.3 s |
| 8 | 0.31 s | 0.90 s |

On one worker EL-GALEN peaked at 0.81 GB, against 0.44 GB under `el`. How the engine works is in
[coverage.md](coverage.md) and [SPEC §5.4](../SPEC.md#54-the-el-calculus).
