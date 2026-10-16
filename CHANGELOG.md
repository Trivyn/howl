# Changelog

## 0.6.1 — 2026-10-15

The answer run (`Reasoner::answer`, `howl_run_answer`, `howl ask`) no longer classifies the whole
input over an omission the whole input shares. Before, any omission inside the queries' module sent
it to the whole input, which carries the same omission and so could only give the same `unknown`,
after a full classification. A class with a datatype restriction, such as `rdfs:label` exactly 1,
was enough. On CCO with one such class, `howl ask --profile auto --ask-unsat` took 7.1 s and now
takes 0.02 s, with the same answers. Nothing changes shape. Every report golden is byte-identical,
and the slop-std-sys 0.5 / slop-rdf-sys 0.6 ranges are unchanged.

### Changed

- **The module's run answers when every axiom it omits is read by no profile the whole input's run
  could use** (SPEC §8.4 L5). That set is the profile asked for, or el, el++ and sriq under `auto`.
  - Such omissions include a datatype restriction, a data axiom, SWRL and a key, and the decode-level
    omissions (an undeclared property, an unresolved import).
  - The run must reach its fixpoint, without a step-down.
  - Its `yes`es stand, and its omissions rule out a `no`, as the whole input's would.
- **The fallback to the whole input stays** for:
  - a round cap or the clause budget;
  - `auto`'s step-down;
  - an RBox, simple-role or S1-guard omission;
  - an omission another profile could read. Under `auto`, the whole input may choose a profile that
    reads it: for example a union, which `sriq` reads and `el++` omits.
- **A module run with omissions gets a tenth of `sriq`'s clause budget.** When it would not finish,
  the whole input is classified anyway, so the tenth bounds the wasted run. On OBI's `sriq` module
  that wasted run took 25 s of a 30 s answer run; it now takes about 0.7 s more than 0.6.0's 5.5 s.
- **An answer run's omissions are its own run's.** When the module answers, `Answers::omissions`
  and `omission_details` (and the C accessors) list the module's omissions, each with its kind and
  document, rather than the whole input's.
- **Constraint (SPEC §8.4):** the answer run may now give a `yes` where the two-run mode says
  `unknown`, from a run that is not complete. Every such `yes` is sound, since the module is part of
  the input. It still never contradicts a two-run `yes` or `no`, and gives `no` only from a complete
  run.

## 0.6.0 — 2026-10-15

Each omission now says where it came from: its kind and the document that introduced it (issue #67).
A host that loads a background ontology (BFO and CCO, say) before its own document can tell its own
coverage gaps from the background's in one run, instead of classifying the background alone and
diffing omission strings. The C API and the Rust crate only gain: nothing existing changes shape,
the report lines are byte-identical, and the slop-std-sys 0.5 / slop-rdf-sys 0.6 ranges are
unchanged. An `owl:imports` that names an attested ontology's version IRI now resolves (issue
#71).

### Added

- **Omission provenance** (SPEC §8.4, issue #67). Every omission of a classify run, of its probe run
  and of an answer run has three things:
  - its **kind**, the head token of its rendering (`MissingDeclaration`, `UndeclaredProperty`,
    `UnresolvedImport`, `SubClassOf`, `DataAxiom`, `HasKey`, `Unrecognized`, ...);
  - a `MissingDeclaration`'s **entity kind**;
  - its **document**, the index of the document that introduced it in `add` order (from 0), or none
    when no single document did, for example a `MissingDeclaration` cited from two documents. The
    probe run's omissions are placed among the input's documents or the probe documents.
  - An axiom stated in two documents is omitted once per copy under `el` and `el++`, and each copy
    names its own document. `sriq` keeps one copy, which names the first document.
  - The document is provenance beside the coverage, never part of an omission's identity. Omissions
    are compared, ordered, deduplicated and hashed exactly as before.
  - **C API:** `howl_run_omission_kind`, `howl_run_omission_entity_kind`,
    `howl_run_omission_document`; `howl_run_probe_omission_kind`, `_entity_kind`, `_document`,
    `_source`; the enums `types_EntityKind` and `DocumentSource`. Each is total: out of range it
    gives `""`, `entity_class` or -1.
  - **Rust:** `Report::omission_details`, `Report::probe_omission_details`,
    `Answers::omission_details`, each `&[Omission]` in the order of the matching `omissions` list;
    the struct `Omission { kind, entity_kind, document, text }` and the `#[non_exhaustive]` enums
    `EntityKind` and `Document { Input(usize), Probe(usize) }`. All additive.

### Fixed

- **An import by version IRI resolves** (issue #71). OWL 2 lets `owl:imports` name the imported
  ontology's IRI or its version IRI. An import naming the version stayed an `UnresolvedImport`, and
  the run inconclusive, even with the document supplied and attested. Now an attested ontology's
  `owl:versionIRI`, as the supplied documents declare it, counts as attested too, so neither `-I`
  nor a library host has to know which form each importer used. A version IRI declared by an
  ontology nobody attested still resolves nothing. Pinned by the `by-version` import golden.

## 0.5.0 — 2026-10-14

Probe queries can be answered without classifying the whole ontology first: `howl ask`,
`howl_run_answer` and `Reasoner::answer` classify only the queried classes' module. On Core (BFO and
CCO merged), 30 queries take about 1 s, where the two-run mode takes 14 s. HOWL is now generated
with slop 0.5.1, which renames the enum and struct types in `howl.h`, so C callers must update those
names (see Changed). The existing Rust API and the report grammar are unchanged.

### Added

- **Answering probe queries without classifying first** (SPEC §8.4). The answer run is the probe
  run alone, with no main run: usually one classification, of the queries' module, instead of two
  of the whole input. It is additive: nothing existing changes.
  - **It classifies the queries' module first.** This is the syntactic ⊥-locality module (Cuenca
    Grau, Horrocks, Kazakov and Sattler, JAIR 2008), which entails exactly what the ontology entails
    about the queried classes whenever HOWL can read every axiom in it. It is usually far smaller,
    and `auto` picks a profile for the module alone.
  - **It falls back to the whole input** when the module's run is incomplete: an omission inside
    the module, a round cap, or the clause budget. That makes two classifications in that case.
  - **It gives every `yes` and `no` the two-run mode gives.** It also answers where an omission
    outside the module made that mode say `unknown`.
  - **C API:** `howl_run_answer(input, options)`, read with the existing `howl_run_probe_*`
    accessors. The run has no report, its verdict is `inconclusive`, and `howl_run_profile` names
    the profile that answered.
  - **Rust:** `Reasoner::answer` and `answer_cancellable`, returning `Answers` (the profile,
    `probes`, `inconsistent`, `omissions` and `lines()`).
  - **CLI:** `howl ask FILE [--probe F]... --ask-unsat C | --ask-sub A B ...` prints `profile P` and
    the probe lines. It exits 0 when it answered, whatever the answers; 2 if cancelled; 3 on an
    error.

### Changed

- **The Rust crate compiles the engine with the release CLI's flags**: `-O3` and 65,536 intern
  buckets, where it used `-O2` and 4,096. The crate pins these whatever the host's Cargo profile.
  It is 0–3% faster on the corpus, and every report is identical.
- **`howl_run_ok` means the run has a result**, now including an answer run's answers. It is
  unchanged for every `howl_run_classify` run: it is false exactly when the run faulted.
- **The macOS release binary and library are built with Apple clang**, where they used Homebrew
  gcc-14 (a choice inherited from GROWL's CI, never measured).
  - On the corpus, a clang build of the engine runs 14–21% faster than a gcc build (gcc-16 locally,
    release flags), with identical reports.
  - CI's macOS job builds and tests with clang too.
  - Linux and Windows are unchanged (gcc, MinGW gcc).
- **Generated with slop 0.5.1 and slop-rdf 0.6.0.** The crate depends on `slop-std-sys` 0.5 and
  `slop-rdf-sys` 0.6.
  - **Breaking for C callers:** slop 0.5 adds the package to generated C names (slop #360), so
    the enum and struct types in `howl.h` are renamed. `types_Verdict_*`, `types_Profile_*`,
    `types_Termination*`, `probe_QueryKind_*` and `probe_ProbeAnswer_*` gain a `howl_` prefix
    (`howl_types_Verdict_verdict_coherent`), and `rdf_TermKind_*` becomes
    `slop_rdf_rdf_TermKind_*`. Values and layouts are unchanged, as are the `howl_*` functions and
    the Rust API.
  - The crate's `-sys` dependencies are caret ranges again, where they were pinned exactly. Its
    build no longer compares the runtime header byte for byte. Every generated header checks
    `SLOP_RUNTIME_ABI` instead, so C generated for another runtime ABI fails to compile, and a
    header that differs only in comments builds.

### Fixed

- **Turtle: a dot inside a prefix name or blank-node label** (slop-rdf #13). `@prefix j.0:`, as
  rdflib writes it, failed to parse. `_:b.1` was cut to `_:b` and the leftover read as the next
  statement's subject, a silently wrong triple. Both now read as Turtle defines them. A literal in
  subject position is now a parse error (exit 3); it used to be read as a triple.
- **`sriq`: a `DisjointUnion` headed by `owl:Thing` or `owl:Nothing` no longer faults.** The head
  reached the clause boundary as a plain class name, which has no id for a built-in, so a valid
  ontology was refused as an input error. It now lowers to `⊤` or `⊥`, as decode reads those names
  everywhere else: `DisjointUnion(owl:Thing, P, Q)` with P and Q empty is inconsistent, and
  `DisjointUnion(owl:Nothing, P, Q)` makes P and Q unsatisfiable.

## 0.4.0 — 2026-10-14

`sriq` ships: the SRIQ object fragment with an ABox, so inverses, unions, `∀`, full negation and
qualified cardinalities are reasoned over instead of omitted. It runs single-threaded under a clause
budget, and `auto` now chooses among three profiles and steps down when `sriq` passes its budget.
The report grammar, the C ABI and the Rust API are unchanged.

### Added

- **`--profile sriq`** (SPEC §5.5): [Sim12]'s chain elimination, then [TGH21]'s consequence-based
  calculus. It is available from the CLI, `auto`, the C API and the Rust crate.
  - It admits inverses, `∀`, unions, full negation, number restrictions up to 16, Self, every
    property characteristic, disjoint properties, `DisjointUnion`, equality and inequality, and
    negative assertions.
  - Its RBox condition is simple roles over every property expression, the collapse of
    role-equivalence classes, and Simančík's ≺-regularity. A failure omits the whole RBox.
  - Class nominals, datatypes, keys, anonymous individuals and the universal role stay omissions.
  - It classifies BFO-core and CCO with nothing omitted, and each exits 0. Both equal HermiT on
    every pair of named classes.
- **A deterministic clause budget of 500,000** bounds every `sriq` run. A run that passes it is
  inconclusive (`resource-limit`, exit 2), unless it has already found something definitive. The same
  number caps the choices one rule instance may try, so a run whose store stays small cannot spend
  unbounded time on choices it discards. It is not a user option.
- **BFO-core and CCO are in the pinned corpus** (`corpus/MANIFEST.toml`).
  - Both are pinned to an upstream *commit*: BFO-2020 `5ed46876`, and CommonCoreOntologies
    `510dad76` (tag v2.0-2024-11-06). No versioned PURL serves these bytes.
  - Each has `el` and `el++` projections, re-certified against HermiT. Every entry also has a `sriq`
    projection.
- **`sriq`'s evidence:**
  - per-construct probes;
  - the fixture and corpus differentials against HermiT;
  - the W3C and ELK conformance suites (0 FAIL);
  - 400 generated ontologies against HermiT (0 failed);
  - determinism at every cap and worker count.

  A run that stops at the budget is checked as partial but sound: everything it states must hold.

### Changed

- **`auto` chooses among three profiles.** It takes the first of `el`, `el++` and `sriq` that omits
  nothing, else the one that omits fewest. So an ontology with inverses or unions, which 0.3.0 ran
  under `el` or `el++` with omissions, now runs under `sriq`. The report's `profile` line names the
  profile that answered, and the exit codes mean what they did.
- **`auto` steps down.** When it chose `sriq` and the run passes the clause budget with nothing
  definitive, it reruns the input under `el` or `el++`, reports that run, and prints one note on
  stderr. OBI is such an input.
- **`Fault::ProfileUnavailable`'s text** for an unbuilt profile lists `sriq` among the
  implemented profiles.
- **`--workers W` is accepted under `sriq`**, which runs at one worker. The report is the same at
  every W.

### Fixed

- **Every profile: `owl:intersectionOf` (or `unionOf`, `complementOf`, …) on a named class is
  reported, not dropped.** It is OWL 1's way of stating an equivalence, and the OWL 2 mapping does
  not define it. HOWL used to skip such a triple silently, so a run could report coherent while
  ignoring it. It is now an omission, so **a report that was coherent can become inconclusive**. One
  W3C test, `WebOnt-Thing-004` (`owl:Thing owl:oneOf …`), moves from passing to outside the el and
  el++ profiles for this reason.
- **Every profile: an omission that quotes a literal stays on one line.** The literal is escaped as
  N-Triples does it. A literal with a newline, such as an XML literal, used to split the omission
  across lines and break the report's grammar.

### Known limits

- **RO is inconclusive under `sriq`.** One of its runs passes the clause budget. `auto` steps down to
  `el++`, whose run omits RO's inverses and so is inconclusive too. Almost all of RO's stored clauses
  are copies of facts that hold everywhere. Storing them once, and counting the budget on what is
  stored, should bring RO under it; neither is built yet. Running in parallel would not change it.
- **OBI is out of `sriq`'s reach** (SPEC §12, M5 (c)). `--profile sriq` reports it inconclusive, and
  `auto` steps down to `el++`.
- **`sriq`'s performance against HermiT and Sequoia is not yet recorded** (M5 (h)).

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
