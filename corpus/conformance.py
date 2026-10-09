#!/usr/bin/env python3
"""External conformance tests: fixed expected answers that neither HOWL nor this project wrote.

    python3 corpus/conformance.py fetch            # download and sha256-verify the pinned sources
    python3 corpus/conformance.py run [--update] [--profile P]   # run HOWL against them

--profile el (the default) or el++ is passed to HOWL and to the census; each
profile has its own record (conformance-status.txt, conformance-status-el++.txt).

The capability probes (corpus/fixtures/probes/) carry expectations written for
HOWL, and the differential compares HOWL with oracles run live. These are the
third leg: answers fixed in someone else's repository. corpus/conformance.sha256
pins both suites.

  w3c  The W3C OWL 2 conformance suite, as HermiT carries it. Every APPROVED
       test in the EL profile under the Direct Semantics that is a consistency
       or an inconsistency test: HOWL's `inconsistent` line must match. The
       suite's entailment tests are not run — their conclusions are almost all
       ABox assertions and property axioms, which HOWL's report does not state.
  elk  ELK's classification tests: an input and the taxonomy ELK's authors
       expect. The input is converted to Turtle by the pinned OWL API
       (`oracle convert`); the taxonomy, transitively reduced as written, is
       closed into the oracle report grammar and compared with HOWL's report by
       corpus/entdiff.py — every ordered pair, bottom-compressed, as the
       differential does.

A test whose premise HOWL does not reason over completely under the profile
(anything omitted) is `outside-<profile>`: not a failure, and not a pass. Each
test's outcome is recorded in the profile's record, and a run whose outcomes
differ from the record FAILS — so a HOWL change that starts omitting a test
shows up instead of quietly shrinking what is checked. A mismatch is never recorded: it fails the
run, and `--update` refuses to write while anything fails.

Exit 0 when every comparable test agrees and the record is unchanged, 1 on any
failure, 3 when the harness cannot run.
"""
import hashlib
import os
import re
import subprocess
import sys
import urllib.request
from collections import defaultdict

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import entdiff  # noqa: E402
import profiles  # noqa: E402

HOWL = os.environ.get("HOWL", os.path.join(ROOT, "build", "howl"))
ORACLE = os.path.join(ROOT, "oracle", "build", "oracle")
PINS = os.path.join(HERE, "conformance.sha256")
PROFILE = "el"
STATUS = os.path.join(HERE, "conformance-status.txt")
VENDOR = os.path.join(HERE, "vendor", "conformance")
OUT = os.path.join(ROOT, "build", "conformance", PROFILE)

OWL = "http://www.w3.org/2002/07/owl#"
THING, NOTHING = OWL + "Thing", OWL + "Nothing"
TEST = "http://www.w3.org/2007/OWL/testOntology#"


class HarnessError(Exception):
    pass


def pins():
    out = []
    with open(PINS, encoding="utf-8") as fh:
        for line in fh:
            if line.startswith("#") or not line.strip():
                continue
            digest, suite, url = line.split()
            out.append((digest, suite, url))
    return out


def local(suite, url):
    return os.path.join(VENDOR, suite, url.rsplit("/", 1)[1])


def sha256(path):
    with open(path, "rb") as fh:
        return hashlib.sha256(fh.read()).hexdigest()


def cmd_fetch():
    bad = 0
    for digest, suite, url in pins():
        path = local(suite, url)
        if os.path.exists(path) and sha256(path) == digest:
            continue
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with urllib.request.urlopen(url) as r:
            data = r.read()
        got = hashlib.sha256(data).hexdigest()
        if got != digest:
            print(f"FAIL {url}: sha256 {got}, pinned {digest}")
            bad += 1
            continue
        with open(path + ".part", "wb") as fh:
            fh.write(data)
        os.replace(path + ".part", path)
    print(f"  {len(pins()) - bad} pinned files verified in {os.path.relpath(VENDOR, ROOT)}")
    return 1 if bad else 0


def verified(suite):
    """The suite's pinned files, refusing any that are missing or changed."""
    files = []
    for digest, s, url in pins():
        if s != suite:
            continue
        path = local(s, url)
        if not os.path.exists(path):
            raise HarnessError(f"{os.path.relpath(path, ROOT)} is missing: run `make conformance-fetch`")
        if sha256(path) != digest:
            raise HarnessError(f"{os.path.relpath(path, ROOT)} does not match its pin")
        files.append(path)
    return files


# -- running ---------------------------------------------------------------

def howl_report(ttl, out_dir):
    """(report path, None) when comparable, else (report path, why it is outside v0).

    WHY is recorded, not just THAT: HOWL's omission kinds, plus `census-clean`
    when the independent census (corpus/census.py) finds nothing out of
    profile. So the record says which of HOWL's own refusals put a test out
    of scope, and flags the ones census does not corroborate — the gate-only
    refusals (an unresolved import, a non-regular role hierarchy) and any
    HOWL omission of something it should have read — for review.
    """
    import census
    p = subprocess.run([HOWL, "validate", ttl, "--report", "--profile", PROFILE], capture_output=True, text=True)
    if not p.stdout.startswith("howl-report 2\n"):
        raise HarnessError(f"howl gave no report for {ttl} (exit {p.returncode}): {p.stderr.strip()}")
    path = os.path.join(out_dir, os.path.splitext(os.path.basename(ttl))[0] + ".report")
    with open(path, "w", encoding="utf-8") as fh:
        fh.write(p.stdout)
    try:
        entdiff.parse(path)
        return path, None
    except entdiff.Incomplete as e:
        if e.reason != "omitted":
            # Nothing here is capped, so a non-fixpoint run is a HOWL fault, not a skip.
            raise HarnessError(str(e))
    except entdiff.Refused as e:
        raise HarnessError(f"malformed HOWL report: {e}")
    kinds = sorted({line.split(" ", 1)[1].split("(", 1)[0]
                    for line in p.stdout.splitlines() if line.startswith("omission ")})
    _, _, out_of_profile, _, _ = census.census(ttl, profile=PROFILE)
    return path, " ".join(kinds + ([] if out_of_profile else ["census-clean"]))


def convert(files, out_dir):
    """Functional syntax to Turtle through the pinned OWL API; {stem: ttl}."""
    os.makedirs(out_dir, exist_ok=True)
    p = subprocess.run([ORACLE, "convert", "--out", out_dir] + files, capture_output=True, text=True)
    if p.stderr.strip() or p.returncode not in (0, 1):
        raise HarnessError(f"oracle convert failed (exit {p.returncode}):\n{p.stdout}{p.stderr}")
    failed = [line for line in p.stdout.splitlines() if line.startswith("FAIL")]
    if failed:
        raise HarnessError("oracle convert refused:\n" + "\n".join(failed))
    return {os.path.splitext(os.path.basename(f))[0]:
            os.path.join(out_dir, os.path.splitext(os.path.basename(f))[0] + ".ttl") for f in files}


def w3c_tests():
    """The Approved EL-profile, Direct-Semantics W3C tests: (graph, [(node, name, premise ttl)])."""
    from rdflib import Graph, Namespace
    T = Namespace(TEST)
    (all_rdf,) = verified("w3c")
    g = Graph()
    g.parse(all_rdf, format="xml")
    out_dir = os.path.join(OUT, "w3c")
    os.makedirs(out_dir, exist_ok=True)
    fs_inputs, cases = [], []
    for t in g.subjects(T.identifier, None):
        if (t, T.profile, T.EL) not in g or (t, T.semantics, T.DIRECT) not in g:
            continue
        if (t, T.status, T.Approved) not in g:
            continue
        name = re.sub(r"[^A-Za-z0-9._-]", "_", str(g.value(t, T.identifier)))
        rdfxml = g.value(t, T.rdfXmlPremiseOntology)
        if rdfxml is not None:
            premise = Graph()
            premise.parse(data=str(rdfxml), format="xml")
            ttl = os.path.join(out_dir, name + ".ttl")
            premise.serialize(ttl, format="turtle")
        else:
            fs = g.value(t, T.fsPremiseOntology)
            if fs is None:
                raise HarnessError(f"w3c {name}: no premise ontology in a syntax the harness reads")
            ofn = os.path.join(out_dir, name + ".ofn")
            with open(ofn, "w", encoding="utf-8") as fh:
                fh.write(str(fs))
            fs_inputs.append(ofn)
            ttl = None
        cases.append((t, name, ttl))
    converted = convert(fs_inputs, os.path.join(out_dir, "converted")) if fs_inputs else {}
    # A functional-syntax premise reaches HOWL through `oracle convert`, which
    # collapses repeated pairwise operands; RDF/XML premises go through rdflib,
    # which keeps every list member.
    lossy = {os.path.splitext(os.path.basename(f))[0]: fss_repeated_operands(f) for f in fs_inputs}
    return g, sorted(((t, n, ttl or converted[n], lossy.get(n)) for t, n, ttl in cases), key=lambda c: c[1])


_W3C = None


def w3c():
    """w3c_tests(), computed once: both W3C suites read the same premises."""
    global _W3C
    if _W3C is None:
        _W3C = w3c_tests()
    return _W3C


def run_w3c():
    """[(name, status, detail)] for the (in)consistency tests: HOWL's `inconsistent` line."""
    from rdflib import Namespace, RDF
    T = Namespace(TEST)
    g, cases = w3c()
    out_dir = os.path.join(OUT, "w3c")
    results = []
    for t, name, ttl, lossy in cases:
        if (t, RDF.type, T.InconsistencyTest) in g:
            expect = True
        elif (t, RDF.type, T.ConsistencyTest) in g:
            expect = False
        else:
            continue
        if lossy:
            results.append((name, "oracle-lossy", "repeated operands in " + " ".join(lossy)))
            continue
        report, outside = howl_report(ttl, out_dir)
        if outside is not None:
            results.append((name, f"outside-{PROFILE}", outside))
            continue
        got = entdiff.parse(report).inconsistent
        if got == expect:
            results.append((name, "ok", ""))
        else:
            results.append((name, "FAIL", f"expected inconsistent {str(expect).lower()}, HOWL says {str(got).lower()}"))
    return results


def conclusion_axioms(text):
    """A W3C conclusion (RDF/XML) as read_fss-style axioms: named SubClassOf /
    EquivalentClasses where the triples say exactly that, else the predicate as
    an inexpressible kind. Declarations and the ontology header are skipped."""
    from rdflib import Graph, RDF, RDFS, OWL, URIRef
    cg = Graph()
    cg.parse(data=text, format="xml")
    decl = {OWL.Class, OWL.ObjectProperty, OWL.DatatypeProperty, OWL.AnnotationProperty,
            OWL.NamedIndividual, OWL.Ontology}
    axioms = []
    for s, p, o in cg:
        if p == RDF.type and o in decl:
            continue
        named = isinstance(s, URIRef) and isinstance(o, URIRef)
        if p == RDFS.subClassOf and named:
            axioms.append(("SubClassOf", [str(s), str(o)]))
        elif p == OWL.equivalentClass and named:
            axioms.append(("EquivalentClasses", [str(s), str(o)]))
        else:
            kind = "ClassAssertion" if p == RDF.type else str(p).rsplit("#", 1)[-1].rsplit("/", 1)[-1]
            axioms.append((kind, None))
    return axioms


def run_w3c_entailment():
    """[(name, status, detail)] for the positive and negative entailment tests."""
    from rdflib import Namespace, RDF
    T = Namespace(TEST)
    g, cases = w3c()
    out_dir = os.path.join(OUT, "w3c")
    results = []
    for t, name, ttl, lossy in cases:
        positive = (t, RDF.type, T.PositiveEntailmentTest) in g
        negative = (t, RDF.type, T.NegativeEntailmentTest) in g
        if not (positive or negative):
            continue
        if lossy:
            results.append((name, "oracle-lossy", "repeated operands in " + " ".join(lossy)))
            continue
        entailed = notentailed = []
        if positive:
            c = g.value(t, T.rdfXmlConclusionOntology)
            entailed = conclusion_axioms(str(c)) if c is not None else [("no-rdfxml-conclusion", None)]
        if negative:
            c = g.value(t, T.rdfXmlNonConclusionOntology)
            notentailed = conclusion_axioms(str(c)) if c is not None else [("no-rdfxml-conclusion", None)]
        report, outside = howl_report(ttl, out_dir)
        if outside is not None:
            results.append((name, f"outside-{PROFILE}", outside))
            continue
        results.append((name, *check_axioms(entdiff.parse(report), entailed, notentailed)))
    return results


def fss_axioms(path):
    """(prefixes, [axiom text]) of a functional-syntax document.

    A SCANNER, NOT A LINE READER: an axiom may span lines, and parentheses
    inside a string literal or an IRI are not structure. `#` comment lines
    (ELK annotates its expectations with them) are dropped first.
    """
    with open(path, encoding="utf-8") as fh:
        text = "\n".join(l for l in fh.read().splitlines() if not l.strip().startswith("#"))
    prefixes = {m.group(1): m.group(2)
                for m in re.finditer(r"Prefix\(\s*([\w.-]*):\s*=\s*<([^>]*)>\s*\)", text)}
    m = re.search(r"\bOntology\(", text)
    if not m:
        raise HarnessError(f"{path}: no Ontology(")
    k, axioms = m.end(), []
    while True:
        while k < len(text) and text[k].isspace():
            k += 1
        if k >= len(text):
            raise HarnessError(f"{path}: Ontology( is never closed")
        if text[k] == ")":
            return prefixes, axioms
        if text[k] == "<":                      # the ontology / version IRI
            k = text.index(">", k) + 1
            continue
        start, depth = k, 0
        while True:
            if k >= len(text):
                raise HarnessError(f"{path}: unbalanced axiom starting {text[start:start + 40]!r}")
            ch = text[k]
            if ch == '"':                       # a literal: skip to its closing quote
                k += 1
                while text[k] != '"':
                    k += 2 if text[k] == "\\" else 1
            elif ch == "<":                     # an IRI
                k = text.index(">", k)
            elif ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
                if depth == 0:
                    axioms.append(" ".join(text[start:k + 1].split()))
                    k += 1
                    break
            k += 1


def split_top(inner):
    """The top-level operands of an axiom's argument text."""
    ops, depth, cur, k = [], 0, "", 0
    while k < len(inner):
        ch = inner[k]
        if ch == '"':
            end = k + 1
            while inner[end] != '"':
                end += 2 if inner[end] == "\\" else 1
            cur += inner[k:end + 1]
            k = end + 1
            continue
        if ch == "<":
            end = inner.index(">", k)
            cur += inner[k:end + 1]
            k = end + 1
            continue
        if ch.isspace() and depth == 0:
            if cur:
                ops.append(cur)
            cur = ""
        else:
            depth += (ch == "(") - (ch == ")")
            cur += ch
        k += 1
    if cur:
        ops.append(cur)
    return ops


def expander(path, prefixes):
    """(iri, canonical): a prefixed name as a full IRI; an operand's text with every name as <IRI>."""
    def iri(term):
        if term.startswith("<") and term.endswith(">"):
            return term[1:-1]
        pfx, sep, local_name = term.partition(":")
        if not sep or pfx not in prefixes:
            raise HarnessError(f"{path}: cannot expand {term!r}")
        return prefixes[pfx] + local_name

    def canonical(op):
        return re.sub(r'"(?:[^"\\]|\\.)*"|<[^>]*>|[A-Za-z_][\w.-]*:[\w.-]*|:[\w.-]*',
                      lambda m: m.group(0) if m.group(0)[0] in '"<' else f"<{iri(m.group(0))}>", op)
    return iri, canonical


def axiom_parts(path, text):
    """(head, operands) with axiom annotations — Annotation(…) operands — removed."""
    m = re.fullmatch(r"(\w+)\((.*)\)", text)
    if not m:
        raise HarnessError(f"{path}: unreadable axiom {text!r}")
    return m.group(1), [o for o in split_top(m.group(2)) if not o.startswith("Annotation(")]


def read_fss(path):
    """The axioms of a functional-syntax document ELK's tests use.

    [(head, iris)]: `iris` lists the operands as full IRIs when every operand
    is a NAMED entity, and is None when any operand is a complex expression —
    so a caller can tell `SubClassOf(:A :B)` from `SubClassOf(:A
    ObjectSomeValuesFrom(:r :B))` without parsing the latter. Axiom
    annotations are not operands: `SubClassOf(Annotation(…) :A :B)` is named.
    """
    prefixes, texts = fss_axioms(path)
    iri, _ = expander(path, prefixes)
    axioms = []
    for text in texts:
        head, ops = axiom_parts(path, text)
        if head == "Declaration":
            d = re.fullmatch(r"(\w+)\((\S+)\)", ops[0]) if len(ops) == 1 else None
            if not d:
                raise HarnessError(f"{path}: unreadable declaration {text!r}")
            axioms.append((f"Declaration:{d.group(1)}", [iri(d.group(2))]))
        elif any("(" in o or o.startswith('"') for o in ops):
            axioms.append((head, None))
        else:
            axioms.append((head, [iri(o) for o in ops]))
    return axioms


PAIRWISE_HEADS = ("DisjointClasses", "DisjointObjectProperties", "DisjointDataProperties",
                  "DifferentIndividuals", "DisjointUnion")


def fss_repeated_operands(path):
    """Axioms in a functional-syntax document that repeat an operand OWL 2 reads
    pairwise — which the OWL API collapses on load (differential.owlapi_blind_spots).
    Operands compare as CANONICAL text, so `:A` and `<http://example.org/A>` are
    the same operand, and an axiom spanning lines is read whole."""
    prefixes, texts = fss_axioms(path)
    _, canonical = expander(path, prefixes)
    found = set()
    for text in texts:
        head, ops = axiom_parts(path, text)
        if head not in PAIRWISE_HEADS:
            continue
        if head == "DisjointUnion":
            ops = ops[1:]  # the union class, then the disjoint operands
        shapes = [canonical(o) for o in ops]
        if len(shapes) != len(set(shapes)):
            found.add(head)
    return sorted(found)


def closed_taxonomy(path):
    """An ELK .taxonomy (functional syntax, transitively reduced) as an oracle report."""
    classes, edges = {THING}, defaultdict(set)
    for head, iris in read_fss(path):
        if head == "ClassAssertion":
            continue  # realization: not part of what HOWL reports
        if head.startswith("Declaration:"):
            if head == "Declaration:Class":
                classes.add(iris[0])
            continue
        if iris is None:
            raise HarnessError(f"{path}: a taxonomy names classes only, not {head} over expressions")
        if head == "SubClassOf":
            a, b = iris
            classes |= {a, b}
            edges[a].add(b)
        elif head == "EquivalentClasses":
            classes |= set(iris)
            for a in iris:
                edges[a] |= set(iris)
        else:
            raise HarnessError(f"{path}: taxonomy axiom {head} is not understood")

    def reach(a):
        # ⊤ is walked too, not just marked: the taxonomy is transitively
        # reduced, so `EquivalentClasses(owl:Thing :C)` is the only place
        # "every class is under C" is written.
        seen, todo = {a, THING}, [a, THING]
        while todo:
            for b in edges[todo.pop()]:
                if b not in seen:
                    seen.add(b)
                    todo.append(b)
        return seen

    lines = ["oracle-report 1", "reasoner elk-expected-taxonomy"]
    if NOTHING in reach(THING):
        return lines + ["inconsistent true"]
    lines.append("inconsistent false")
    body = []
    for a in sorted(classes - {NOTHING}):
        r = reach(a)
        if NOTHING in r:
            body += [f"unsat {a}", f"sub {a} {NOTHING}"]
        else:
            body += [f"sub {a} {b}" for b in sorted(r)]
    return lines + sorted(body)


def run_elk():
    files = verified("elk")
    inputs = sorted(f for f in files if f.endswith(".owl"))
    out_dir = os.path.join(OUT, "elk")
    converted = convert(inputs, os.path.join(out_dir, "converted"))
    os.makedirs(os.path.join(out_dir, "expected"), exist_ok=True)
    results = []
    for f in inputs:
        name = os.path.splitext(os.path.basename(f))[0]
        lossy = fss_repeated_operands(f)
        if lossy:
            # The conversion itself loses these, so HOWL would be judged on a
            # theory the test never stated.
            results.append((name, "oracle-lossy", "repeated operands in " + " ".join(lossy)))
            continue
        report, outside = howl_report(converted[name], out_dir)
        if outside is not None:
            results.append((name, f"outside-{PROFILE}", outside))
            continue
        expected = os.path.join(out_dir, "expected", name + ".report")
        with open(expected, "w", encoding="utf-8") as fh:
            fh.write("\n".join(closed_taxonomy(os.path.splitext(f)[0] + ".taxonomy")) + "\n")
        diff = entdiff.compare(entdiff.parse(report), entdiff.parse(expected))
        if diff:
            detail = "; ".join(f"{k}: {', '.join(v[:3])}{' …' if len(v) > 3 else ''}"
                               for k, v in sorted(diff.items()))
            results.append((name, "FAIL", detail))
        else:
            results.append((name, "ok", ""))
    return results


def entails_named(report, head, iris):
    """Does HOWL's report entail a SubClassOf / EquivalentClasses between named classes?

    entails-sub semantics, as the probes use (differential.holds): inconsistent,
    or the subclass unsatisfiable, or a `sub A B` line — plus the two trivial
    cases a bottom-compressed report does not list, ⊥ ⊑ B and A ⊑ ⊤.
    """
    def sub(a, b):
        if report.inconsistent or a == NOTHING or b == THING or a in report.unsat:
            return True
        return b in report.subs.get(a, ())
    if head == "SubClassOf":
        return sub(*iris)
    return all(sub(a, b) for a in iris for b in iris)


EXPRESSIBLE = ("SubClassOf", "EquivalentClasses")


def check_axioms(report, entailed, notentailed):
    """(status, detail) for one test's expected (non-)entailments over HOWL's report."""
    checked, unchecked, wrong = 0, set(), []
    for polarity, axioms in ((True, entailed), (False, notentailed)):
        for head, iris in axioms:
            if head.startswith("Declaration:"):
                continue
            if head not in EXPRESSIBLE or iris is None:
                unchecked.add(head)
                continue
            checked += 1
            if entails_named(report, head, iris) != polarity:
                wrong.append(f"{'expected' if polarity else 'not expected'}: {head}({' '.join(iris)})")
    if wrong:
        return "FAIL", "; ".join(wrong)
    if not checked:
        return "not-expressible", " ".join(sorted(unchecked))
    return "ok", ("unchecked " + " ".join(sorted(unchecked))) if unchecked else ""


def run_elk_entailment():
    """ELK's entailment queries: the named-class subsumptions among them are checked."""
    files = verified("elk-entailment")
    inputs = sorted(f for f in files if f.endswith(".owl"))
    out_dir = os.path.join(OUT, "elk-entailment")
    converted = convert(inputs, os.path.join(out_dir, "converted"))
    results = []
    for f in inputs:
        name = os.path.splitext(os.path.basename(f))[0]
        lossy = fss_repeated_operands(f)
        if lossy:
            results.append((name, "oracle-lossy", "repeated operands in " + " ".join(lossy)))
            continue
        report, outside = howl_report(converted[name], out_dir)
        if outside is not None:
            results.append((name, f"outside-{PROFILE}", outside))
            continue
        base = os.path.splitext(f)[0]
        entailed = read_fss(base + ".entailed") if os.path.exists(base + ".entailed") else []
        notentailed = read_fss(base + ".notentailed") if os.path.exists(base + ".notentailed") else []
        results.append((name, *check_axioms(entdiff.parse(report), entailed, notentailed)))
    return results


def cmd_run(update):
    results = ([("w3c", *r) for r in run_w3c()] + [("w3c-entailment", *r) for r in run_w3c_entailment()]
               + [("elk", *r) for r in run_elk()] + [("elk-entailment", *r) for r in run_elk_entailment()])
    failed = False
    for suite, name, status, detail in results:
        if status == "FAIL":
            print(f"  FAIL {suite} {name}: {detail}")
            failed = True
    record = "".join(f"{suite} {status} {name}" + (f" {detail}" if detail else "") + "\n"
                     for suite, name, status, detail in results if status != "FAIL")
    header = ("# Outcome of each external conformance test (corpus/conformance.py).\n"
              "# Generated by `make conformance-update`; never edited by hand.\n"
              "# A mismatch is never recorded here: it fails the run.\n"
              f"# Profile: {PROFILE}. outside-{PROFILE} lines carry HOWL's omission kinds, and\n"
              "# `census-clean` when corpus/census.py finds nothing out of profile: review\n"
              "# those by hand.\n"
              "# not-expressible: the expected answer is an axiom HOWL's report does not\n"
              "# state (an individual's type, a property axiom, a complex expression).\n"
              "# oracle-lossy: the input repeats an operand OWL 2 reads pairwise, which the\n"
              "# OWL API collapses on conversion, so the test cannot be posed to HOWL intact.\n")
    if update:
        if failed:
            print("  not updating the record while tests fail")
            return 1
        with open(STATUS, "w", encoding="utf-8") as fh:
            fh.write(header + record)
        print(f"  -> {os.path.relpath(STATUS, ROOT)}")
    else:
        try:
            with open(STATUS, encoding="utf-8") as fh:
                committed = fh.read()
        except FileNotFoundError:
            committed = None
        if committed != header + record:
            print(f"  FAIL {os.path.relpath(STATUS, ROOT)} differs from this run "
                  "(review, then `make conformance-update`)")
            failed = True
    for suite in ("w3c", "w3c-entailment", "elk", "elk-entailment"):
        counts = defaultdict(int)
        for s, _, status, _ in results:
            if s == suite:
                counts[status] += 1
        print(f"  {PROFILE} {suite}: ok {counts['ok']}, outside-{PROFILE} {counts[f'outside-{PROFILE}']}, "
              f"not-expressible {counts['not-expressible']}, oracle-lossy {counts['oracle-lossy']}, "
              f"FAIL {counts['FAIL']}")
    return 1 if failed else 0


def set_profile(p):
    """Point the run at one profile: HOWL's flag, the census, the record, the build directory."""
    global PROFILE, STATUS, OUT
    if p not in profiles.BUILT:
        raise HarnessError(f"unknown profile {p} ({profiles.expected()})")
    PROFILE = p
    STATUS = os.path.join(HERE, "conformance-status.txt" if p == "el" else f"conformance-status-{p}.txt")
    OUT = os.path.join(ROOT, "build", "conformance", p)


def main(argv):
    try:
        args = argv[1:]
        if "--profile" in args:
            i = args.index("--profile")
            if i + 1 >= len(args):
                raise HarnessError("--profile needs a value")
            set_profile(args[i + 1])
            args = args[:i] + args[i + 2:]
        if args == ["fetch"]:
            return cmd_fetch()
        if args in (["run"], ["run", "--update"]):
            return cmd_run(update=len(args) == 2)
        print(__doc__.split("\n\n")[1], file=sys.stderr)
        return 3
    except HarnessError as e:
        print(f"HARNESS ERROR {e}")
        return 3


if __name__ == "__main__":
    sys.exit(main(sys.argv))
