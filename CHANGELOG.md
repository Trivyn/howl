# Changelog

## Unreleased

- **`sriq` is built and selectable** (`--profile sriq`, `auto`, the C API, the Rust crate). It runs
  single-threaded under a budget of 500,000 clauses, and a run that passes the budget is
  inconclusive unless it has found something definitive.
  - It classifies BFO-core and CCO with nothing omitted, and each exits 0.
  - **`auto` chooses among three rungs.** It takes the first of `el`, `el++` and `sriq` that omits
    nothing, else the one that omits fewest, so an ontology with inverses or unions now runs
    under `sriq`.
  - **`auto` steps down.** When it chose `sriq` and the run passes the clause budget with nothing
    definitive, it reruns the input under `el` or `el++` and says so on stderr. OBI is such an
    input.
  - **The budget also caps one rule instance's choices** at 500,000, so a run whose store stays
    small cannot spend unbounded time enumerating discarded choices.
  - The report grammar, the C ABI and the Rust API are unchanged. Only `Fault::ProfileUnavailable`'s
    text for an unbuilt rung lists `sriq` among the implemented ones.
- **Fixed, every profile: an omission that quotes a literal stays on one line.** The literal is
  escaped as N-Triples does it. A literal with a newline, such as an XML literal, used to split the
  omission across lines and break the report's grammar.
- **Fixed, every profile: `owl:intersectionOf` (or `unionOf`, `complementOf`, …) on a named class
  is reported, not dropped.** It is OWL 1's way of stating an equivalence, and the OWL 2 mapping does
  not define it. HOWL used to skip such a triple silently, so a run could report coherent while
  ignoring it. It is now an omission, so the run is inconclusive. One W3C test, `WebOnt-Thing-004`
  (`owl:Thing owl:oneOf …`), moves from passing to outside the el and el++ profiles for this reason.
- **`sriq`'s gate is built** and tested, with the census's independent column beside it. It admits
  inverses, `∀`, unions, full negation, number restrictions up to 16, Self, every property
  characteristic, disjoint properties, `DisjointUnion`, equality and inequality, and negative
  assertions. Its RBox condition is simple roles over every property expression, the collapse of
  role-equivalence classes, and Simančík's ≺-regularity; a failure omits the whole RBox.
  - On BFO-core and CCO it omits nothing. On RO and OBI it omits no RBox axiom; what it omits there
    is SWRL, class nominals and used data.
- **BFO-core and CCO are in the pinned corpus** (`corpus/MANIFEST.toml`).
  - Both are pinned to an upstream *commit*: BFO-2020 `5ed46876`, and CommonCoreOntologies
    `510dad76` (tag v2.0-2024-11-06). No versioned PURL serves these bytes.
  - Each has `el` and `el++` projections, re-certified against HermiT.
  - Every entry also has a `sriq` projection (census only, until the engine runs `sriq`). BFO-core's,
    CCO's, GO's and EL-GALEN's are empty.

## 0.3.0 — 2026-10-12

Probe queries ask HOWL whether a class is unsatisfiable, or one class subsumed by another, without
touching the report. An undeclared property is now an omission instead of failing the whole run.
The C API and the Rust crate only gain; nothing existing changes shape.

### Added

- **Probe queries** (SPEC §8.4, issue #68). A caller adds probe documents, which define classes to
  ask about, and queries: is `C` unsatisfiable, is `A ⊑ B`. A second classification answers them,
  over the input, the probe documents and a declaration of every class a query names. The main
  report, verdict and exit code are exactly those of a run without probes: a probe class never
  reaches `unsatisfiable`, the taxonomy, the omissions or the verdict.
  - Answers are `yes` (entailed, whatever the probe run's coverage), `no` (not entailed, by a
    complete probe run) or `unknown`. An inconsistent probe run answers `yes` to everything and
    says so.
  - Each query is answered once, in canonical order. The probe lines (`probes N`,
    `probe-inconsistent`, `probe-omitted`, `probe unsatisfiable C yes`, `probe subsumed A B no`)
    follow the report only when a query was asked, so no existing report changes.
  - **C API:** `howl_input_add_probe_turtle`, `howl_input_begin_probe_document`,
    `howl_input_add_probe_triple`, `howl_input_ask_unsatisfiable`, `howl_input_ask_subsumed`;
    `howl_run_probe_len`, `_kind`, `_sub`, `_sup`, `_answer`, `_inconsistent`, `_omission_len`,
    `_omission`; the enums `probe_QueryKind` and `probe_ProbeAnswer`.
  - **Rust:** `Input::add_probe_turtle`, `add_probe_triples`, `ask_unsatisfiable`, `ask_subsumed`;
    `Report::probes`, `probe_inconsistent`, `probe_omissions`; the types `ProbeAnswer` and the
    `#[non_exhaustive]` enums `Query` and `Answer`. All additive.
  - **CLI:** `--probe FILE`, `--ask-unsat C`, `--ask-sub A B`, each repeatable.
- **Windows builds.** The release has `howl-windows-x86_64.exe` and `libhowl-windows-x86_64.zip`,
  built with MinGW-w64 from the same C, and attached to v0.3.0 after the tag. The Windows CLI writes
  its report with LF line endings, so it is the same bytes as on Linux and macOS.

### Changed

- **An undeclared property is an omission, not an input error** (SPEC §5.2, issue #70). In
  `:B :editorNote "x"` or `:B :seeAlsoClass :A`, with the predicate never declared, HOWL cannot
  tell an annotation from a data or object property assertion. Such a triple used to fail the whole
  run (exit 3). It is now an `UndeclaredProperty(<iri>)` omission, one per property: the rest of the
  document is read, and the run is inconclusive (exit 2). HOWL still does not guess; declaring the
  property clears it. Conflicting declarations are still an input error.

## 0.2.1 — 2026-10-12

A toolchain update. HOWL's answers do not change.

- **Generated with slop 0.4.3 and slop-rdf 0.5.2,** and pinned exactly to `slop-std-sys = "=0.4.3"`
  and `slop-rdf-sys = "=0.5.2"`. slop 0.4.3's runtime keeps gcc from inlining the list-growth slow
  path at every push site, which made the stack frame of a recursive function with many pushes grow
  several times over (a stack overflow in a sibling project's evaluator). clang builds are unchanged.

## 0.2.0 — 2026-10-12

Data restrictions are read as data: a qualified data cardinality (`owl:onDataRange`) no longer fails
the whole run, and data axioms no longer pass for object ones. Idle data properties' axioms are set
aside. One breaking change, in the Rust crate's `Profile`.

### Specified

- **`sriq`**, the SRIQ object fragment with an ABox, is specified in SPEC §5.5. It uses Simančík's
  chain elimination, then Tena Cucala, Cuenca Grau and Horrocks's consequence-based calculus. It is
  not built yet; `--profile sriq` exits 3.

### Changed

- **The data lemma** (SPEC §5.2): the domain, range, functionality, sub-property, equivalence and
  disjointness axioms of a data property that nothing uses are set aside in every profile. "Used"
  means used in a class expression, an assertion or a key, by the property or by any data property
  below it. These axioms provably change no answer, so they are no longer omissions.
  - On CCO, 16 omissions go: 220 → 204 under `el`, 218 → 202 under `el++`.
  - On RO, 5 go, including the 4 lines its range's datatype restriction used to leak.
  - On OBI, 2 go.
  - The RO and OBI projections keep those axioms, and their pins were re-certified against HermiT.
- **`horn-sriq` is dropped from the profile ladder.** On `sriq`'s calculus it would run at the same
  cost, so it would only be a stricter gate.
  - Its value keeps its place in the C `types_Profile` enum and in Rust's `Profile`, so neither is
    renumbered.
  - Asking for it is always refused (`unavailable`, exit 3), and the message names `sriq`.
- **The C API's `howl_run_fault_message`** now says why an `unavailable` run was refused: "was
  dropped", or "is not implemented yet". It used to be empty.
- **Rust (breaking):**
  - `Profile` is `#[non_exhaustive]`.
  - `Profile::HornSriq` is deprecated.
  - `Fault::ProfileUnavailable`'s message for it says it was dropped.

### Fixed

- **Data restrictions and data property axioms on a property that *is* used are now data.**
  - **Accepted as object axioms before.** `DataSomeValuesFrom`, and `owl:equivalentProperty`
    between data properties, were accepted by `el` and `el++`: the first as an existential over a
    "role" whose datatype was taken for a class, the second as role inclusions. Both are now
    omissions. On OBI, 5 such `DataSomeValuesFrom` axioms move from accepted to omitted: 506 → 508
    omissions, because the 3 MissingDeclaration lines they used to cause go away.
  - **Mislabelled before.** `FunctionalDataProperty`, `DisjointDataProperties` and the data
    cardinalities were labelled as their object twins.
  - **Faulted before.** `owl:onDataRange` and `owl:onProperties` faulted the whole document
    (exit 3). They are now omissions.
- **An ambiguous `owl:inverseOf` node is no longer dropped silently.** `_:x owl:inverseOf :p , :q`
  makes no ObjectInverseOf, and no axiom could read it. Both triples vanished, with no axiom and no
  omission, and the document came out coherent. Each is now an omission.

### Changed (reports)

- **`ObjectInverseOf` is represented**: `RoleId` has an inverse arm (SPEC §6.2), for `sriq`. Every
  rung built so far still omits it, but the omission now reads as the axiom it is. Before, it was an
  N-Triples fragment with blank-node labels, and every restriction on an inverse rendered as the
  same constant string. RO's 11 inverse omissions are re-rendered; their count is unchanged.
- **`DisjointUnion`** is read whole and rendered `DisjointUnion(C D₁ … Dₙ)`. It is still an omission.

## 0.1.1 — 2026-10-12

A build fix. HOWL's answers do not change.

- **0.1.0 no longer builds from a fresh resolve.** It asked for `slop-std-sys` and `slop-rdf-sys` with
  a caret, so once slop-std-sys 0.4.2 was published a new build resolved it, and `build.rs`, which
  requires the runtime header to match HOWL's generated C byte for byte, panicked. 0.1.1 is generated
  with slop 0.4.2 and slop-rdf 0.5.1, and pins `slop-std-sys = "=0.4.2"` and
  `slop-rdf-sys = "=0.5.1"` exactly.
- **Windows** (#64). slop 0.4.2's runtime threads through Win32 on Windows. The crate links pthread
  only on other targets, and compiles its C with clang-cl on MSVC targets (`cl.exe` cannot compile the
  generated C), as the -sys crates do. CI builds and tests the crate on Windows, with MSVC and with
  MinGW.

## 0.1.0 — 2026-10-06

The first release. HOWL classifies OWL ontologies: the complete subsumption hierarchy, every
unsatisfiable class, and whether the ontology is coherent, including the subsumptions that follow
from defined classes, which OWL 2 RL materialization cannot see.

### What's in it

- **Two profiles, both polynomial.**
  - `el` (the default): ELH⊥R+ with domains, ranges, ABox assertions, and `¬` in a superclass,
    domain or range.
  - `el++`: the OWL 2 EL object fragment, adding nominals, `hasValue`, `hasSelf`, reflexive roles,
    individual equality and inequality, and negative assertions.
  - `auto` picks the cheapest profile that covers the ontology.
- **The `howl` CLI.**
  - `howl validate` exits 0 (coherent), 1 (incoherent), 2 (inconclusive — not a pass) or 3 (error).
  - Flags: `-I` for attested imports, `--profile`, `--strict`, `--report` (a canonical, hashable
    report), `--workers`, `--max-iterations`, `--timings` and `--version`.
- **A C library.**
  - `libhowl.a` with `include/howl.h`. The API is written in SLOP and its header is generated by
    slop.
  - Inputs and runs are opaque handles. Turtle and triple input, attested imports and cancellation
    are supported. See `examples/c/classify.c`.
- **A Rust crate** in `rust/`, a safe wrapper over the C API, published on crates.io as
  `howl-reasoner` (imported as `howl`).

### What it guarantees

- **Nothing is silently dropped.** Every axiom HOWL does not reason over is listed as an omission,
  and any omission makes an otherwise clean run inconclusive.
- **A finding beats incomplete coverage.** An incoherence found under partial coverage is still
  reported as incoherent.
- **Reports are input-determined.** For a given round cap, the canonical report is byte-identical
  at every worker count, and it never contains a timing, path or worker count.

### Evidence

- **Differential testing:**
  - every fixture against HermiT, and against ELK where ELK is probed capable of the construct.
    The one exception is `owl:Thing ⊑ owl:Nothing`, which HermiT cannot load; it is checked against
    ELK alone;
  - the in-profile part of RO, OBI, the Gene Ontology and EL-GALEN against its routed oracle, over
    every pair of named classes.
- **Conformance:** the W3C OWL 2 and ELK conformance suites, wherever HOWL reasons completely.
- **Fuzzing:** 400 generated ontologies with ABoxes per profile, matched against HermiT.
- **Performance:** `el` classifies within 5× of ELK, the SPEC §12 target. On an Apple M3 Ultra,
  the Gene Ontology runs at 0.84× ELK's time and EL-GALEN at 2.9×. `el++` has no target. It runs
  at 0.95× and 5.25×.
- **Contracts:** 89 functions carry Z3-checked contracts, among them the profile selection, the
  verdict's safety property and each `el++` rule's faithfulness.

### Known limitations

- **Unbuilt profiles.** `horn-sriq` and `sriq` are not built; asking for one exits 3.
- **Omitted constructs.** `HasKey`, datatypes and data properties, and constructs outside OWL 2 EL
  (unions, universal restrictions, cardinalities, inverse properties) are reported as omissions.
- **No `howl classify` yet.** `howl classify` (`--emit`, `--reduce`) is refused until a later
  release.
- **MOOSE port amendments.** The `TBoxReasoner` port amendments (SPEC §8.5) are on the consumer
  side and not delivered here.
- **Contract checking.** `make verify` needs a slop toolchain from before 0.4.0 until
  slop-lang/slop#325 is fixed; the committed C is generated by slop 0.4.0 and slop-rdf 0.5.0.
- **Prebuilt binaries** are for linux-x86_64 and macos-arm64 only. Elsewhere, `make` builds from the
  committed C with any C compiler.
