#!/usr/bin/env python3
"""The differential harness: capability probes, then HOWL against its oracles (SPEC.md §10 item 1).

    python3 corpus/differential.py [--profile P] probes [--update]
    python3 corpus/differential.py [--profile P] fixtures
    python3 corpus/differential.py [--profile P] corpus [--update] [--also] [--timeout SECONDS]
    python3 corpus/differential.py rungs

--profile el (the default) or el++ selects HOWL's rung, the census used for
routing, and the records. Under el++:
  - `probes` runs corpus/fixtures/probes-el++/ (one probe per construct SPEC
    §5.4 adds) and records corpus/oracle-capabilities-el++.txt;
  - `fixtures` adds corpus/fixtures/el++/ and probes-el++/, and ELK gates only
    for constructs BOTH capability records show it passing;
  - `corpus` diffs the el++ projections (corpus/vendor/NAME.el++.ttl, from
    `make materialize-el++`) and records corpus/corpus-differential-el++.txt.

`rungs` runs every materialized v0 projection under el AND el++ and requires
the two reports to be identical but for their `profile` and `rounds` lines:
el ⊂ el++, so on el's language the rungs must agree class for class (§5.4 K5).

`probes` runs corpus/fixtures/probes/ — one small ontology per v0 construct,
each carrying `# construct:` and `# expect:` / `# expect-not:` lines — through
HOWL and both oracles, and records which oracle passes which probe in
corpus/oracle-capabilities.txt. It FAILS if HOWL misses any probe (a HOWL bug),
if HermiT misses any (then there is no confirmed-complete oracle, and nothing
can be certified), or if the recorded capabilities changed. `--update` rewrites
the file, for a deliberate oracle change only; the diff shows what moved.

`fixtures` diffs every v0, hazard and probe fixture HOWL reasons over
completely against HermiT, which gates every one, and against ELK, which gates
only the fixtures it is PROVEN capable of (Constraint b293cf6e):
  - every census construct in the fixture passes all of ELK's probes, and
  - the fixture has no ObjectPropertyRange at all. ELK 0.6.0 claims only
    partial range support, and a handful of passing probes does not make a
    partial implementation complete, so a range-bearing ELK diff is printed
    for information and never gates.
A fixture HOWL does not reason over completely (a capped run, or any
omission) is not comparable and is listed as skipped: it is a lower bound over
a different theory.

`corpus` diffs each MATERIALIZED corpus entry (corpus/vendor/NAME.v0.ttl, from
`make materialize`) against its ROUTED oracle, by the same rule: ELK where it is
probe-capable for every construct and there is no range (GO, EL-GALEN), HermiT
otherwise (RO, OBI). `--also` runs the other oracle too, for information. Each
file must still be its projection (ground sha256 against the pinned .removals),
HOWL must reason over it completely, and the oracle must finish inside the
timeout — a timeout is "no oracle", a failure, never a pass. The outcome is
recorded in corpus/corpus-differential.txt: the evidence M1 (b) rests on.

Reports land in build/differential/ for inspection. Exit 0 when everything
gating is clean, 1 on any failure, 3 when the harness itself cannot run.
"""
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import entdiff  # noqa: E402
import profiles  # noqa: E402

HOWL = os.environ.get("HOWL", os.path.join(ROOT, "build", "howl"))
ORACLE = os.path.join(ROOT, "oracle", "build", "oracle")
# ELK's tripwire: a construct it is known to reject with a warning. If ELK
# processes it silently, the warning capture is dead (oracle/…/Main.java).
TRIPWIRE = os.path.join(ROOT, "corpus", "fixtures", "out-of-profile", "allvalues.ttl")
PROFILE = "el"
CAPABILITIES = os.path.join(HERE, "oracle-capabilities.txt")
OUT = os.path.join(ROOT, "build", "differential")
FIXTURE_DIRS = ("v0", "hazards", "probes")
PROBE_DIR = "probes"
REASONERS = ("hermit", "elk")
RANGE = "ObjectPropertyRange"
OWL = "http://www.w3.org/2002/07/owl#"


class HarnessError(Exception):
    """The harness cannot produce a meaningful answer at all."""


def rel(path):
    return os.path.relpath(path, ROOT)


def name_of(path):
    """`<dir>-<stem>`, the name the goldens and the oracle's reports use."""
    return f"{os.path.basename(os.path.dirname(path))}-{os.path.splitext(os.path.basename(path))[0]}"


def fixtures(*dirs):
    out = []
    for d in dirs:
        base = os.path.join(ROOT, "corpus", "fixtures", d)
        out += sorted(os.path.join(base, f) for f in os.listdir(base) if f.endswith(".ttl"))
    return out


# -- running the reasoners -----------------------------------------------------

def run_howl(files, profile=None):
    """{name: report path}. Every file must yield a report, whatever its verdict."""
    profile = profile or PROFILE
    out = os.path.join(OUT, "howl" if profile == PROFILE else f"howl-{profile}")
    os.makedirs(out, exist_ok=True)
    reports = {}
    for f in files:
        p = subprocess.run([HOWL, "validate", f, "--report", "--profile", profile], capture_output=True, text=True)
        if not p.stdout.startswith("howl-report 2\n"):
            raise HarnessError(f"howl gave no report for {rel(f)} (exit {p.returncode}): {p.stderr.strip()}")
        path = os.path.join(out, name_of(f) + ".report")
        with open(path, "w", encoding="utf-8") as fh:
            fh.write(p.stdout)
        reports[name_of(f)] = path
    return reports


# THE OWL API'S BLIND SPOTS: input it loads as a different theory than HOWL
# reads, or cannot load at all. Both oracles sit behind it (as does `oracle
# convert`), so such input is never diffed — Constraint b293cf6e forbids
# certifying HOWL against a theory the oracle did not process. Each entry was
# found by a conformance test, and each has a HOWL fixture pinning HOWL's own
# answer (golden + acceptance line) in place of the oracle comparison.
#
# 1. OPERANDS OWL 2 READS PAIRWISE, BY POSITION. `AllDisjointClasses (A B A)`
#    makes A disjoint from itself, so A is unsatisfiable. The OWL API stores
#    these operands as a SET and drops the repeat without a warning or an
#    unparsed triple (ELK's DisjointSelf; hazards/disjoint-repeated-member.ttl).
#    Duplicates in intersections, unions or chains change nothing, or are kept.
# 2. AN ANNOTATION ON AN ONTOLOGY ANNOTATION (`_:x a owl:Annotation`). The OWL
#    API's RDF parser leaves its triples unparsed (W3C
#    New-Feature-AnnotationAnnotations-001; hazards/annotated-annotation.ttl).
#    No logical content is lost, but the unparsed-triple refusal is not
#    weakened to admit it.
PAIRWISE_LISTS = ("members", "distinctMembers", "disjointUnionOf")


# HERMIT'S OWN FAULTS: input the OWL API loads faithfully but HermiT cannot
# reason over. Not a blind spot of the shared parser — ELK still runs and
# gates where it is capable — but HermiT's answer is absent, so it cannot
# gate; HOWL's answer on such a fixture is pinned by its own tests and
# golden. Each entry names where HermiT fails (HOWL_ORACLE_TRACE=1).
#
# 1. owl:Thing ⊑ owl:Nothing. HermiT's normalization simplifies the
#    inclusion to an empty ObjectUnionOf, which the OWL API refuses
#    (ExpressionManager.java:454, "operands cannot be null or empty"); seen on
#    W3C WebOnt-Thing-003 and el++/ksc-02.
def hermit_faults(files):
    """{name: why} for the files HermiT itself cannot reason over."""
    from rdflib import Graph, URIRef
    from rdflib.namespace import RDFS
    thing, nothing = URIRef(OWL + "Thing"), URIRef(OWL + "Nothing")
    out = {}
    for f in files:
        g = Graph()
        g.parse(f, format="turtle")
        if (thing, RDFS.subClassOf, nothing) in g:
            out[name_of(f)] = "HermiT fault: owl:Thing ⊑ owl:Nothing normalizes to an empty union"
    return out


def _shape(g, t, seen=()):
    """A structural key for a term: IRIs and literals by value, blank nodes by
    what they say — so two blank nodes spelling the same ∃r.A compare equal,
    as the OWL API compares them."""
    from rdflib import BNode
    if not isinstance(t, BNode) or t in seen:
        return str(t)
    return tuple(sorted((str(p), _shape(g, o, seen + (t,))) for p, o in g.predicate_objects(t)))


def owlapi_blind_spots(g):
    """Why the OWL API cannot load `g` faithfully; empty when it can."""
    from rdflib import OWL, RDF
    from rdflib.collection import Collection
    found = set()
    for _, p, head in g:
        if p in (OWL[n] for n in PAIRWISE_LISTS):
            shapes = [_shape(g, x) for x in Collection(g, head)]
            if len(shapes) != len(set(shapes)):
                found.add(f"repeated operands in {str(p).rsplit('#', 1)[-1]}")
    if (None, RDF.type, OWL.Annotation) in g:
        found.add("an annotation on an annotation")
    return sorted(found)


def lossy_for_oracles(files):
    """{name: why} for the inputs no oracle is compared on (owlapi_blind_spots)."""
    from rdflib import Graph
    out = {}
    for f in files:
        g = Graph()
        g.parse(f, format="turtle")
        spots = owlapi_blind_spots(g)
        if spots:
            out[name_of(f)] = "; ".join(spots)
    return out


def run_oracle(reasoner, files, timeout=None):
    """({name: report path}, {name: failure text}). One JVM for the whole batch."""
    out = os.path.join(OUT, reasoner)
    os.makedirs(out, exist_ok=True)
    for stale in os.listdir(out):
        os.remove(os.path.join(out, stale))
    if not files:
        return {}, {}
    cmd = [ORACLE, "report", "--reasoner", reasoner, "--out", out]
    if reasoner == "elk":
        cmd += ["--tripwire", TRIPWIRE]
    try:
        p = subprocess.run(cmd + files, capture_output=True, text=True, timeout=timeout)
    except subprocess.TimeoutExpired:
        # No oracle within the budget: every file in the batch fails.
        return {}, {name_of(f): f"{reasoner} did not finish within {timeout}s" for f in files}
    # Nothing the oracle program prints goes to stderr, so anything there came
    # from the JVM or a library bypassing the logger — a warning the harness
    # would otherwise diff through.
    if p.stderr.strip():
        raise HarnessError(f"{reasoner} wrote to stderr:\n{p.stderr.strip()}")
    if p.returncode not in (0, 1):
        raise HarnessError(f"{reasoner} exited {p.returncode}:\n{p.stdout.strip()}")
    failures, current = {}, None
    for line in p.stdout.splitlines():
        m = re.match(r"(ok  |FAIL) (\S+?)(?::\s*(.*))?$", line)
        if m:
            current = name_of(m.group(2)) if m.group(1) == "FAIL" else None
            if current:
                failures[current] = m.group(3) or ""
        elif current and line.startswith("  "):
            failures[current] += "\n" + line
    reports = {name_of(f): os.path.join(out, name_of(f) + ".report") for f in files
               if name_of(f) not in failures}
    for n, path in reports.items():
        if not os.path.exists(path):
            raise HarnessError(f"{reasoner} reported ok for {n} but wrote no report")
    return reports, failures


# -- probes ----------------------------------------------------------------

def expectations(path):
    """(construct, [(polarity, kind, args)]) from a probe's header comments."""
    prefix, construct, exps = None, None, []
    with open(path, encoding="utf-8") as fh:
        for line in fh:
            m = re.match(r"@prefix\s+:\s+<([^>]*)>", line)
            if m:
                prefix = m.group(1)
            m = re.match(r"#\s*construct:\s*(.+?)\s*$", line)
            if m:
                construct = m.group(1)
            m = re.match(r"#\s*(expect|expect-not):\s*(.+?)\s*$", line)
            if m:
                exps.append((m.group(1) == "expect", *m.group(2).split(" ", 1)))

    def iri(term):
        if term.startswith(":") and prefix:
            return prefix + term[1:]
        if term.startswith("owl:"):
            return OWL + term[4:]
        raise HarnessError(f"{rel(path)}: cannot expand {term!r}")

    parsed = []
    for positive, kind, *rest in exps:
        args = rest[0].split() if rest else []
        if (kind, len(args)) not in (("sub", 2), ("unsat", 1), ("inconsistent", 0)):
            raise HarnessError(f"{rel(path)}: malformed expectation {kind} {' '.join(args)}")
        parsed.append((positive, kind, [iri(a) for a in args]))
    # A POSITIVE expectation is required: only an entailment that vanishes
    # without the construct shows the construct was processed. A probe of
    # `expect-not` lines alone passes on an oracle that ignores it entirely.
    if construct is None or not any(pos for pos, _, _ in parsed):
        raise HarnessError(f"{rel(path)}: a probe needs `# construct:` and at least one positive `# expect:`")
    return construct, parsed


def holds(report, kind, args):
    """entails-sub semantics over a bottom-compressed report."""
    if report.inconsistent:
        return True
    if kind == "inconsistent":
        return False
    if args[0] in report.unsat:
        return True
    if kind == "unsat":
        return False
    return args[1] in report.subs.get(args[0], ())


# LOAD-BEARING, CHECKED ON EVERY RUN. A probe earns its construct only if its
# expected entailment DEPENDS on it: an oracle that ignored the construct must
# fail the probe. So each probe is run again with its construct's axioms
# deleted, and HOWL and HermiT must BOTH lose at least one positive
# expectation. Probes are written one axiom per line, which is what lets a
# line pattern name "the construct's axioms"; a probe the pattern does not
# touch is a harness error, not a pass.
CONSTRUCT_LINES = {
    "SubClassOf": r"rdfs:subClassOf",
    "EquivalentClasses": r"owl:equivalentClass",
    "ObjectIntersectionOf": r"owl:intersectionOf",
    "ObjectSomeValuesFrom": r"owl:someValuesFrom",
    "DisjointClasses": r"owl:disjointWith|owl:AllDisjointClasses",
    "SubObjectPropertyOf": r"rdfs:subPropertyOf",
    "EquivalentObjectProperties": r"owl:equivalentProperty",
    "ObjectPropertyChain": r"owl:propertyChainAxiom",
    "TransitiveObjectProperty (-> r o r subseteq r)": r"owl:TransitiveProperty",
    "ObjectPropertyDomain": r"rdfs:domain",
    "ObjectPropertyRange": r"rdfs:range",
    "ObjectComplementOf (positive position)": r"owl:complementOf",
    "ClassAssertion": r"^:\w+ a :",
    "ObjectPropertyAssertion": r"^:\w+ :\w+ :\w+ \.",
    # SPEC §5.4's additions, for corpus/fixtures/probes-el++/.
    "ObjectHasValue": r"owl:hasValue",
    "ObjectOneOf (one individual)": r"owl:oneOf",
    "ObjectHasSelf (simple role)": r"owl:hasSelf",
    "ReflexiveObjectProperty": r"owl:ReflexiveProperty",
    "SameIndividual": r"owl:sameAs",
    "DifferentIndividuals": r"owl:differentFrom|owl:AllDifferent",
    "NegativeObjectPropertyAssertion": r"owl:NegativePropertyAssertion",
    "built-in role (bottomObjectProperty)": r"owl:bottomObjectProperty",
}


def without_construct(f, construct):
    """The probe with every line stating its construct deleted, under build/differential/mutants."""
    pattern = CONSTRUCT_LINES.get(construct)
    if pattern is None:
        raise HarnessError(f"{rel(f)}: no deletion pattern for construct {construct!r}")
    with open(f, encoding="utf-8") as fh:
        lines = fh.read().split("\n")
    kept = [l for l in lines if l.startswith(("#", "@")) or not re.search(pattern, l)]
    if len(kept) == len(lines):
        raise HarnessError(f"{rel(f)}: no line states {construct!r}, so load-bearing cannot be checked")
    out = os.path.join(OUT, "mutants", PROBE_DIR, os.path.basename(f))
    os.makedirs(os.path.dirname(out), exist_ok=True)
    with open(out, "w", encoding="utf-8") as fh:
        fh.write("\n".join(kept))
    return out


def missed(report, exps):
    return [f"{'expect' if pos else 'expect-not'} {kind} {' '.join(args)}"
            for pos, kind, args in exps if holds(report, kind, args) != pos]


def cmd_probes(update):
    import census  # needs rdflib; imported here so `fixtures`' parse errors surface first
    files = fixtures(PROBE_DIR)
    exps = {name_of(f): expectations(f) for f in files}
    failed = False
    lossy = lossy_for_oracles(files)
    if lossy:
        # A probe exists to be run by the oracles; one they cannot load is useless.
        raise HarnessError("probes the OWL API cannot load faithfully: "
                           + "; ".join(f"{n} ({why})" for n, why in sorted(lossy.items())))

    for f in files:
        _, in_v0, out_of_profile, _, _ = census.census(f, profile=PROFILE)
        if out_of_profile:
            print(f"FAIL census: {rel(f)} is out of profile: {dict(out_of_profile)}")
            failed = True
        # The label is what routing trusts (`elk_capable`), so it must name a
        # construct the probe actually contains — a mislabelled pass would
        # certify ELK for something it was never shown.
        if exps[name_of(f)][0] not in in_v0:
            print(f"FAIL label: {rel(f)} is labelled {exps[name_of(f)][0]!r}, "
                  f"which census does not find in it ({', '.join(sorted(in_v0))})")
            failed = True

    howl = run_howl(files)
    for n, path in sorted(howl.items()):
        try:
            miss = missed(entdiff.parse(path), exps[n][1])
        except entdiff.Refused as e:
            miss = [f"refused: {e}"]
        if miss:
            print(f"FAIL howl {n}: " + "; ".join(miss))
            failed = True

    # Load-bearing: HOWL and HermiT must both lose a positive expectation
    # when the construct is gone. Run before the capability pass below, which
    # reuses (and clears) the oracle's report directory.
    mutants = {name_of(f): without_construct(f, exps[name_of(f)][0]) for f in files}
    mutant_howl = run_howl(list(mutants.values()))
    mutant_hermit, mutant_failures = run_oracle("hermit", list(mutants.values()))
    for n in sorted(exps):
        positives = [e for e in exps[n][1] if e[0]]
        for who, path in (("howl", mutant_howl.get(n)), ("hermit", mutant_hermit.get(n))):
            if path is None:
                print(f"FAIL load-bearing {who} {n}: the probe without its construct did not load: "
                      f"{mutant_failures.get(n, '').strip().splitlines()[:1]}")
                failed = True
                continue
            try:
                report = entdiff.parse(path)
            except entdiff.Refused as e:
                print(f"FAIL load-bearing {who} {n}: {e}")
                failed = True
                continue
            if all(holds(report, kind, args) for _, kind, args in positives):
                print(f"FAIL load-bearing {who} {n}: every positive expectation survives without "
                      f"{exps[n][0]!r}, so the probe proves nothing about it")
                failed = True

    lines = []
    for r in REASONERS:
        reports, failures = run_oracle(r, files)
        for n in sorted(exps):
            construct = exps[n][0]
            if n in failures:
                verdict, why = "fail", failures[n].strip().splitlines()[0]
            else:
                miss = missed(entdiff.parse(reports[n]), exps[n][1])
                verdict, why = ("fail", "; ".join(miss)) if miss else ("pass", "")
            lines.append(f"{r} {verdict} {n} {construct}")
            if verdict == "fail":
                print(f"{'FAIL' if r == 'hermit' else 'note'} {r} {n}: {why}")
                if r == "hermit":
                    failed = True

    # Sorted by reasoner, then probe — not by the whole line, which would group
    # by verdict and make one probe changing verdict read as two moved lines.
    lines.sort(key=lambda line: line.split(" ")[0::2][:2])
    text = "".join(line + "\n" for line in lines)
    header = ("# Which oracle passes which capability probe. Generated by\n"
              "# `make probes-update` (corpus/differential.py); never edited by hand.\n"
              "# Format: <reasoner> pass|fail <probe> <census construct>\n")
    if update:
        with open(CAPABILITIES, "w", encoding="utf-8") as fh:
            fh.write(header + text)
        print(f"  -> {rel(CAPABILITIES)}")
    else:
        try:
            with open(CAPABILITIES, encoding="utf-8") as fh:
                committed = fh.read()
        except FileNotFoundError:
            committed = None
        if committed != header + text:
            print(f"FAIL {rel(CAPABILITIES)} differs from this run (review, then `make probes-update`)")
            failed = True
    passed = sum(1 for line in lines if line.startswith("elk pass"))
    print(f"  probes: {len(files)}; howl and hermit {'NOT ' if failed else ''}100%; elk {passed}/{len(files)}")
    return 1 if failed else 0


# -- fixture differential --------------------------------------------------

def elk_capable():
    """Constructs ELK passes EVERY probe for. A construct with no probe is not capable.
    Under el++ both records count: el's constructs are el++'s too."""
    passes, fails = set(), set()
    records = [os.path.join(HERE, "oracle-capabilities.txt")]
    if PROFILE != "el":
        records.append(CAPABILITIES)
    for record in records:
        try:
            with open(record, encoding="utf-8") as fh:
                for line in fh:
                    if line.startswith("#") or not line.strip():
                        continue
                    reasoner, verdict, _probe, construct = line.rstrip("\n").split(" ", 3)
                    if reasoner == "elk":
                        (passes if verdict == "pass" else fails).add(construct)
        except FileNotFoundError:
            raise HarnessError(f"{rel(record)} is missing: run `make probes-update` first")
    return passes - fails


def elk_gates(constructs, capable):
    """(does ELK gate?, why not) for an input with these census constructs."""
    uncovered = sorted(set(constructs) - capable)
    if RANGE in constructs:
        return False, RANGE
    if uncovered:
        return False, ", ".join(uncovered)
    return True, ""


CORPUS_RECORD = os.path.join(HERE, "corpus-differential.txt")


def set_profile(p):
    """Point the harness at one rung: HOWL's flag, the census, the records, the fixtures."""
    global PROFILE, CAPABILITIES, CORPUS_RECORD, OUT, FIXTURE_DIRS, PROBE_DIR
    if p not in profiles.BUILT:
        raise HarnessError(f"unknown profile {p} ({profiles.expected()})")
    PROFILE = p
    if p != "el":
        CAPABILITIES = os.path.join(HERE, f"oracle-capabilities-{p}.txt")
        CORPUS_RECORD = os.path.join(HERE, f"corpus-differential-{p}.txt")
        OUT = os.path.join(ROOT, "build", f"differential-{p}")
        FIXTURE_DIRS = ("v0", "hazards", "probes", p, f"probes-{p}")
        PROBE_DIR = f"probes-{p}"


def oracle_entailments_sha(path):
    """sha256 of an oracle report's ENTAILMENT lines only: the header names the
    JVM build, which varies by machine, and must not make the record local."""
    import hashlib
    with open(path, encoding="utf-8") as fh:
        body = [l for l in fh.read().splitlines() if not l.startswith(("oracle-report", "reasoner "))]
    return hashlib.sha256("\n".join(body).encode()).hexdigest()


def cmd_corpus(update, also, timeout):
    import hashlib
    import census
    import project
    from rdflib import Graph
    try:
        import tomllib
    except ModuleNotFoundError:
        import tomli as tomllib
    with open(os.path.join(HERE, "MANIFEST.toml"), "rb") as fh:
        entries = tomllib.load(fh)["ontology"]
    capable = elk_capable()
    plan, failed = [], False
    for e in entries:
        stem = f"{e['name']}-{e['version']}"
        path = project.materialized_path(e, PROFILE)
        if not os.path.exists(path):
            raise HarnessError(f"{rel(path)} is missing: run `make materialize{'' if PROFILE == 'el' else '-' + PROFILE}`")
        # ONE PARSE per entry, shared by the projection check, census's
        # construct routing and the OWL API blind-spot scan.
        g = Graph()
        g.parse(path, format="turtle")
        # The SAME check as `project-verify`: ground triples, blank-node
        # structure and count against the pinned removal list, census 0 out.
        with open(project.removals_path(e, PROFILE), encoding="utf-8") as fh:
            pins = project.pinned_header(fh.read())
        errors = project.check_graph(g, pins, path, PROFILE)
        if errors:
            print(f"  FAIL {stem:<24} the materialized file is not its projection: {'; '.join(errors)} "
                  f"(run `make materialize`)")
            failed = True
            continue
        ground = pins["ground_sha"]
        bnode_sha = pins["bnode_sha"]
        _, in_v0, _, _, _ = census.census(path, graph=g, profile=PROFILE)
        spots = owlapi_blind_spots(g)
        gates_elk, why = elk_gates(set(in_v0), capable)
        routed = "elk" if gates_elk else "hermit"
        plan.append((e, stem, path, routed, why, spots, (ground, bnode_sha)))

    howl = run_howl([p for _, _, p, *_ in plan])
    runs = {}
    for r in REASONERS:
        batch = [p for _, _, p, routed, _, spots, _ in plan if not spots and (routed == r or also)]
        runs[r] = run_oracle(r, batch, timeout) if batch else ({}, {})

    lines = []
    for e, stem, path, routed, why, spots, ground in plan:
        n = name_of(path)
        try:
            h = entdiff.parse(howl[n])
        except entdiff.Refused as err:
            print(f"  FAIL {stem:<24} HOWL's report is not comparable: {err}")
            failed = True
            continue
        if spots:
            print(f"  FAIL {stem:<24} no oracle can load it faithfully ({'; '.join(spots)})")
            failed = True
            continue
        cells, row_failed = [], False
        for r in REASONERS:
            if r != routed and not also:
                continue
            reports, failures = runs[r]
            if n in failures:
                status, bad = "FAILED: " + failures[n].strip().splitlines()[0], True
            else:
                diff = entdiff.compare(h, entdiff.parse(reports[n]))
                status = "clean" if not diff else "MISMATCH " + ", ".join(f"{k} {len(v)}" for k, v in sorted(diff.items()))
                bad = bool(diff)
                if r == routed and not bad:
                    with open(howl[n], "rb") as fh:
                        howl_sha = hashlib.sha256(fh.read()).hexdigest()
                    lines.append(f"{stem} source={e['sha256'][:16]} ground={ground[0][:16]} "
                                 f"bnodes={ground[1][:16]} "
                                 f"howl-report={howl_sha[:16]} oracle={r} "
                                 f"oracle-entailments={oracle_entailments_sha(reports[n])[:16]} "
                                 f"subsumptions={sum(len(v) for v in h.subs.values())} result=clean")
            if r == routed:
                row_failed |= bad
                cells.append(f"{r} {status}")
            else:
                cells.append(f"{r} info ({why or 'not routed'}): {status}")
        failed |= row_failed
        print(f"  {'FAIL' if row_failed else 'ok  '} {stem:<24} " + "   ".join(cells))

    if PROFILE == "el":
        header = ("# The corpus differential (corpus/differential.py corpus): each materialized\n"
                  "# v0 projection, HOWL against its ROUTED oracle, every ordered pair of named\n"
                  "# classes. Generated by `make diff-corpus-update`; never edited by hand. The\n"
                  "# oracle hash covers its entailment lines only, not the JVM-bearing header.\n")
    else:
        header = (f"# The {PROFILE} corpus differential (corpus/differential.py --profile {PROFILE}\n"
                  f"# corpus): each materialized {PROFILE} projection, HOWL under {PROFILE} against its\n"
                  "# ROUTED oracle, every ordered pair of named classes. Generated by\n"
                  "# `make diff-corpus-update`; never edited by hand. The oracle hash covers its\n"
                  "# entailment lines only, not the JVM-bearing header.\n")
    text = header + "".join(l + "\n" for l in lines)
    if update:
        if failed:
            print("  not updating the record while the differential fails")
            return 1
        with open(CORPUS_RECORD, "w", encoding="utf-8") as fh:
            fh.write(text)
        print(f"  -> {rel(CORPUS_RECORD)}")
    elif not failed:
        try:
            with open(CORPUS_RECORD, encoding="utf-8") as fh:
                committed = fh.read()
        except FileNotFoundError:
            committed = None
        if committed != text:
            print(f"  FAIL {rel(CORPUS_RECORD)} differs from this run (review, then `make diff-corpus-update`)")
            failed = True
    print(f"  corpus: {len(plan)} entries: {'ALL CLEAN AGAINST THE ROUTED ORACLE' if not failed else 'DIFFERENTIAL FAILED'}")
    return 1 if failed else 0


def cmd_fixtures():
    import census
    files = fixtures(*FIXTURE_DIRS)
    howl = run_howl(files)
    comparable, skipped, malformed = [], {}, False
    for f in files:
        try:
            entdiff.parse(howl[name_of(f)])
            comparable.append(f)
        except entdiff.Incomplete as e:
            skipped[name_of(f)] = str(e).split(": ", 1)[-1]
        except entdiff.Refused as e:
            # A malformed report is a HOWL failure, never a skip.
            print(f"  FAIL {name_of(f):<44} malformed report: {e}")
            malformed = True

    capable = elk_capable()
    lossy = lossy_for_oracles(comparable)
    faults = hermit_faults(comparable)
    oracle = {r: run_oracle(r, [f for f in comparable if name_of(f) not in lossy
                                and not (r == "hermit" and name_of(f) in faults)]) for r in REASONERS}
    failed = malformed
    for f in comparable:
        n = name_of(f)
        _, in_v0, _, _, _ = census.census(f, profile=PROFILE)
        constructs = set(in_v0)
        gates_elk, why = elk_gates(constructs, capable)
        cells, row_failed = [], False
        if n in lossy:
            print(f"  ok   {n:<44} oracles n/a (OWL API blind spot: {lossy[n]})")
            continue
        if n in faults and not gates_elk:
            # Neither oracle can gate it: HermiT faults and ELK is not
            # capable. That certifies nothing, so it fails rather than pass
            # unchecked; such a fixture needs another oracle or no fault.
            print(f"  FAIL {n:<44} no gating oracle ({faults[n]}; ELK not capable: {why})")
            failed = True
            continue
        for r in REASONERS:
            if r == "hermit" and n in faults:
                cells.append(f"hermit n/a ({faults[n]})")
                continue
            gates = r == "hermit" or gates_elk
            reports, failures = oracle[r]
            if n in failures:
                status = "FAILED: " + failures[n].strip().splitlines()[0]
                bad = True
            else:
                diff = entdiff.compare(entdiff.parse(howl[n]), entdiff.parse(reports[n]))
                status = "ok" if not diff else "MISMATCH " + ", ".join(f"{k} {len(v)}" for k, v in sorted(diff.items()))
                bad = bool(diff)
            if not gates:
                status = f"info ({why}): {status}"
            elif bad:
                row_failed = True
            cells.append(f"{r} {status}")
        failed |= row_failed
        print(f"  {'FAIL' if row_failed else 'ok  '} {n:<44} " + "   ".join(cells))
    for n, why in sorted(skipped.items()):
        print(f"  skip {n:<44} not comparable: {why}")
    print(f"  compared {len(comparable)}, skipped {len(skipped)}: "
          f"{'ALL GATING DIFFS CLEAN' if not failed else 'DIFFERENTIAL FAILED'}")
    return 1 if failed else 0


def strip_rung(path):
    """A report without the two lines that name the rung or count its rounds."""
    with open(path, encoding="utf-8") as fh:
        return [l for l in fh.read().splitlines() if not l.startswith(("profile ", "rounds "))]


def cmd_rungs():
    """el and el++ on every materialized v0 projection: identical reports, profile and rounds aside."""
    vendor = os.path.join(HERE, "vendor")
    files = sorted(os.path.join(vendor, f) for f in os.listdir(vendor) if f.endswith(".v0.ttl"))
    if not files:
        raise HarnessError("no materialized corpus under corpus/vendor/ (run make materialize)")
    el, elpp = run_howl(files, "el"), run_howl(files, "el++")
    failed = False
    for f in files:
        n = name_of(f)
        a, b = strip_rung(el[n]), strip_rung(elpp[n])
        same = a == b
        failed |= not same
        detail = "" if same else f"  ({sum(1 for x, y in zip(a, b) if x != y) + abs(len(a) - len(b))} lines differ)"
        print(f"  {'ok  ' if same else 'FAIL'} {os.path.basename(f):<34} el and el++ "
              f"{'agree' if same else 'DISAGREE'}{detail}")
    print(f"  rungs: {len(files)} projections: {'EL AND EL++ AGREE' if not failed else 'RUNGS DISAGREE'}")
    return 1 if failed else 0


def main(argv):
    try:
        argv = list(argv)
        if "--profile" in argv:
            i = argv.index("--profile")
            if i + 1 >= len(argv):
                raise HarnessError("--profile needs a value")
            set_profile(argv[i + 1])
            del argv[i:i + 2]
        if argv[1:] in (["probes"], ["probes", "--update"]):
            return cmd_probes(update=len(argv) == 3)
        if argv[1:] == ["fixtures"]:
            return cmd_fixtures()
        if argv[1:] == ["rungs"]:
            return cmd_rungs()
        if argv[1:2] == ["corpus"]:
            opts = argv[2:]
            timeout = None
            if "--timeout" in opts:
                i = opts.index("--timeout")
                timeout = int(opts[i + 1])
                del opts[i:i + 2]
            if set(opts) - {"--update", "--also"}:
                raise HarnessError(f"unknown corpus options {sorted(set(opts) - {'--update', '--also'})}")
            return cmd_corpus("--update" in opts, "--also" in opts,
                              timeout if timeout is not None else 4 * 3600)
        print(__doc__.split("\n\n")[1], file=sys.stderr)
        return 3
    except HarnessError as e:
        print(f"HARNESS ERROR {e}")
        return 3


if __name__ == "__main__":
    sys.exit(main(sys.argv))
