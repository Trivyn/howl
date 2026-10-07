# Performance

Every figure here is from `make bench` / `make bench-el++` (`bench/results.txt`,
`bench/results-el++.txt`) on an Apple M3 Ultra, unless a row says it is historical. Every timed
run reproduced the certified report.

## Real ontologies, not just fixtures

The fixtures all passed while the first two real ontologies
failed, and both failures are fixed and pinned by `make corpus-acceptance`:

| Ontology | Before the fix (historical) | When fixed (historical) | Now (`bench/results.txt`, W = 4) |
|---|---|---|---|
| RO 2025-12-17 (11.6k triples) | exit 3 — an inverse property in a property chain faulted the whole document | exit 2, 0 unsatisfiable, 845 omitted | 275 subsumptions, 18 ms classify |
| OBI 2026-07-27 (118k triples) | exit 1, *inconsistent* — every complex range filler of a role shared one fresh node | exit 2, 0 unsatisfiable, 38,681 subsumptions, 1.0 s (reasoning 0.4 s) | 508 omitted, 48 ms classify, 0.12 s end to end |
| GO 2026-07-26 (1.4M triples) | never finished — the header pass scanned lists per triple, and every fact was matched against every axiom | exit 2, 0 unsatisfiable, 1 omitted (one `owl:inverseOf`), 459,329 subsumptions, 13.4 s (reasoning 5.5 s) | 0.38 s classify (reasoning 0.28 s), 1.5 s end to end |

Rule dispatch goes through a premise index, so each rule sees only the axioms it could fire on; OBI's
reasoning went from 172 s to 0.4 s with its report unchanged byte for byte.

## The §12 benchmark: met

`make bench` times each corpus entry against its routed oracle on
the same machine. Each side gets a median of 5 runs after 1 warm-up, with W = 4. Classification runs
from axioms in hand to taxonomy on both sides: HOWL's gate, normalization, indexing and reasoning,
against the oracle's reasoner creation, consistency check and classification. Parsing and the
RDF-to-axiom mapping (HOWL's decode, the OWL API's parse) are untimed on both sides; HOWL's decode is
reported beside the ratio. Every timed input and report must be the certified ones. HOWL's run-to-run
range is within a few percent; the oracles' is wider (EL-GALEN's ELK ran 255–352 ms around its
281 ms median). Each range is recorded in `bench/results.txt` (Apple M3 Ultra):

| Entry | Oracle | HOWL classify | HOWL decode (untimed) | Oracle classify | Ratio | |
|---|---|---|---|---|---|---|
| GO 2026-07-26 | ELK 0.6.0 | 0.38 s (reasoning 0.28 s), 0.57 GB peak | 0.44 s | 0.46 s | 0.84× | **passes** 5× |
| EL-GALEN | ELK 0.6.0 | 0.82 s (reasoning 0.66 s), 0.59 GB peak | 0.07 s | 0.28 s | 2.9× | **passes** 5× |
| OBI 2026-07-27 | HermiT | 0.05 s | 0.03 s | 0.50 s | 0.1× | reported |
| RO 2025-12-17 | HermiT | 0.02 s | 0.002 s | 0.16 s | 0.1× | reported |

ELK's time moves more between benches than HOWL's does: one earlier bench had ELK at 0.58 s (GO) and
0.35 s (EL-GALEN); this one, like most, has 0.46 s and 0.28 s. Each run-to-run range is recorded in
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

## Memory

Peak resident set of one full run, parse to report, W = 4. The oracles' figures are
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

## The `el++` profile

`make bench-el++` is informational: §12's threshold is set for `el` against ELK, and none for
`el++`. At W = 4 (`bench/results-el++.txt`): OBI 0.03× and RO 0.10× HermiT; GO 0.95× and EL-GALEN
5.25× ELK (`el`: 0.84× and 2.9×). GO classifies in 0.59 s (reasoning 0.48 s, peak 0.65 GB) and
EL-GALEN in 1.44 s (reasoning 1.34 s, peak 0.77 GB).

How it scales with workers, measured on reasoning time alone when the parallel commit landed (runs
interleaved with the previous engine): on one thread GO reasons in 0.86 s and EL-GALEN in 3.75 s,
about 1.5× and 2× `el`; at four workers EL-GALEN takes 1.3 s and GO 0.40 s, and at eight 0.90 s and
0.31 s. EL-GALEN peaked at 0.81 GB on one worker, against `el`'s 0.44 GB. How the engine gets there is in [coverage.md](coverage.md) and
[SPEC §5.4](../SPEC.md#54-the-el-calculus).
