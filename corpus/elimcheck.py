#!/usr/bin/env python3
"""The normaliser differential: sriq's normaliser against HermiT (SPEC.md §10).

    python3 corpus/elimcheck.py fixtures            # tracked fixtures (CI)
    python3 corpus/elimcheck.py guarded             # S1's guard tripped on purpose (CI)
    python3 corpus/elimcheck.py corpus [--record]   # BFO-core, CCO (local)
    python3 corpus/elimcheck.py long                # RO and OBI, hours (local, overnight)

For each input, HOWL's test binary prints each normaliser stage as an OWL 2
functional-syntax document (`howl-test sriq-dump STAGE FILE`). The oracle
converts them to Turtle, and HermiT classifies the input and every stage in one
batch. Restricted to the input's class names (with owl:Thing and owl:Nothing),
the classifications must agree, which is what the stages promise:

    input == S0     S0 is a translation, when the gate omitted nothing;
    S0    == S1     [Sim12] Theorem 3: simple-conservative;
    S1    == S2     S2's proof: agrees with its input on the input's signature.

A leg HermiT cannot take (an RBox it refuses, an input it reads lossily) is
reported as n/a, never as a pass. Exit 0 when every leg that ran agrees, 1 on a
mismatch, 3 when the harness itself fails.
"""
import os
import re
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import differential  # noqa: E402
import entdiff       # noqa: E402

ROOT = os.path.dirname(HERE)
TEST_BIN = os.path.join(ROOT, "build", "howl-test")
WORK = os.path.join(ROOT, "build", "elim")
OWL = "http://www.w3.org/2002/07/owl#"
THING, NOTHING = OWL + "Thing", OWL + "Nothing"
STAGES = ("s0", "s1", "s2")
LEGS = (("input", "s0"), ("s0", "s1"), ("s1", "s2"))
# The ontologies HermiT can decide at every stage. RO and OBI are not: each
# one's S1 document was still unclassified after an hour of HermiT
# (2026-10-09), and after six hours in its own JVM (2026-10-10, the `long`
# mode below), so their S1 is checked by the invariants and the determinism
# tests, not by HermiT. HermiT classifies every class of a stage document,
# fresh names included, which is what grows.
CORPUS = ("bfo-core-2024-02-07", "cco-2024-11-06")
RECORD_NOTE = ("# RO and OBI are not run against HermiT: it did not classify their S1 documents "
               "within six hours (2026-10-10, corpus/elim-differential-long.txt); see CORPUS in "
               "corpus/elimcheck.py. S1's invariants "
               "run on every vendored ontology below.")
# S1's invariants (sriq-s1-invariants) run on every vendored ontology, the ones
# beyond HermiT included.
INVARIANT_CORPUS = ("bfo-core-2024-02-07", "cco-2024-11-06", "ro-2025-12-17",
                    "obi-2026-07-27", "go-2026-07-26")


def invariant_lines():
    """S1's invariants on each vendored ontology: (lines, failures)."""
    lines, bad = [], 0
    for n in INVARIANT_CORPUS:
        path = os.path.join(ROOT, "corpus", "vendor", f"{n}.ttl")
        p = subprocess.run([TEST_BIN, "sriq-dump", "s1-invariants", path], capture_output=True, text=True)
        if p.returncode == 0:
            lines.append(f"vendor-{n} s1-invariants: ok")
        else:
            bad += 1
            lines.append(f"vendor-{n} s1-invariants: FAILED: {(p.stdout.strip().splitlines() or ['?'])[0]}")
    return lines, bad
# The long run: the ontologies whose stages HermiT needs hours for. Each
# document gets its own JVM and budget, two at a time, S0s first, so a slow S1
# never holds up the rest; an S2 runs only once its S1 has a report.
# Recorded in corpus/elim-differential-long.txt.
LONG = tuple(os.environ.get("ELIM_LONG_INPUTS", "ro-2025-12-17,obi-2026-07-27").split(","))
LONG_TIMEOUT = int(os.environ.get("ELIM_LONG_TIMEOUT", str(6 * 3600)))  # seconds per document
LONG_WORKERS = int(os.environ.get("ELIM_LONG_WORKERS", "2"))
LONG_XMX = os.environ.get("ELIM_LONG_XMX", "24g")
LONG_RECORD = os.path.join(HERE, "elim-differential-long.txt")
# Fixtures whose S1 labels something, so a bound of 0 trips the guard.
GUARDED = ("el++/ksc-04", "el++/ksc-05", "el++/ksc-14", "el++/ksc-21", "el++/ksc-22", "el++/ksc-23",
           "el++/ksc-27", "el++/ksc-28", "hazards/abox-chain-mixed", "hazards/abox-nary-chain",
           "hazards/chain-prefix-collision", "hazards/role-hierarchy-deep", "probes/chain-binary",
           "probes/chain-nary", "probes/transitive", "sriq/sim12-example1", "v0/negation-chain")
RECORD = os.path.join(HERE, "elim-differential.txt")
CORPUS_TIMEOUT = int(os.environ.get("ELIM_TIMEOUT", "3600"))  # seconds per ontology
# S1's hook refuses a complex RIA until S1 is built (slice 6d); only that
# refusal is a legitimate missing stage. Any other refusal is a HOWL failure.
AWAITING_S1 = "refused: complex role inclusions need chain elimination"
# An input that names something under urn:howl: is out of the dump's scope.
RESERVED = "refused: reserved:"


class HarnessError(Exception):
    pass


BOUND = []  # S1's guard bound for the dump, empty for the default


def dump(stage, path, out):
    """Write one stage's document; None, or why the stage has no document."""
    p = subprocess.run([TEST_BIN, "sriq-dump", stage, path] + BOUND, capture_output=True, text=True)
    if p.returncode != 0:
        return (p.stdout.strip().splitlines() or [p.stderr.strip() or f"exit {p.returncode}"])[-1]
    with open(out, "w", encoding="utf-8") as f:
        f.write(p.stdout)
    return None


def info(path):
    """The gate's counts, and the input's class names from the decoder's signature.

    The class names never come from a stage's own document: a document that
    dropped its declarations would otherwise shrink the comparison to nothing."""
    p = subprocess.run([TEST_BIN, "sriq-dump", "info", path] + BOUND, capture_output=True, text=True)
    if p.returncode != 0:
        raise HarnessError(f"sriq-dump info {path}: {p.stdout.strip() or p.stderr.strip()}")
    out, classes = {}, set()
    for line in p.stdout.splitlines():
        k, _, v = line.partition(" ")
        if k == "class":
            classes.add(v)
        else:
            out[k] = v
    return out, classes


def restrict(report, classes):
    """The report over `classes`, owl:Thing and owl:Nothing only."""
    keep = classes | {THING}
    targets = keep | {NOTHING}
    subs = {a: report.subs[a] & targets for a in report.subs if a in keep}
    return entdiff.Report(report.kind, report.inconsistent, report.unsat & classes, subs, report.meta)


def convert(files):
    """Turtle for each document, through the oracle's pinned OWL API: {path: ttl or None}."""
    out_dir = os.path.join(WORK, "ttl")
    os.makedirs(out_dir, exist_ok=True)
    for stale in os.listdir(out_dir):
        os.remove(os.path.join(out_dir, stale))
    if not files:
        return {}
    p = subprocess.run([differential.ORACLE, "convert", "--out", out_dir] + files, capture_output=True, text=True)
    if p.stderr.strip():
        raise HarnessError(f"convert wrote to stderr:\n{p.stderr.strip()}")
    failed = {m.group(1): m.group(2) for m in re.finditer(r"^FAIL (\S+?): (.*)$", p.stdout, re.M)}
    out = {}
    for f in files:
        ttl = os.path.join(out_dir, os.path.splitext(os.path.basename(f))[0] + ".ttl")
        if f in failed or not os.path.exists(ttl):
            out[f] = (None, failed.get(f, "no Turtle written"))
        else:
            out[f] = (ttl, None)
    return out


NO_ORACLE = "did not finish within"


def check(inputs, timeout=None):
    """Run every leg on every input; (results, mismatches) where results are lines."""
    ofn_dir = os.path.join(WORK, "ofn")
    os.makedirs(ofn_dir, exist_ok=True)
    plan, docs, why = {}, [], {}
    for path in inputs:
        name = differential.name_of(path)
        meta, classes = info(path)
        if BOUND and meta.get("s1-guarded") != "yes":
            raise HarnessError(f"{path}: S1's guard did not trip at bound {BOUND[0]}")
        stages = {}
        for stage in STAGES:
            out = os.path.join(ofn_dir, f"{name}.{stage}.ofn")
            reason = dump(stage, path, out)
            if reason is None:
                stages[stage] = out
                docs.append(out)
            else:
                why[(name, stage)] = reason
        plan[path] = (name, meta, classes, stages)

    # The input leg trusts the oracle on the input itself, so it takes
    # differential.py's own exclusions: what the OWL API reads lossily (a
    # repeated disjointness member, for one) and what HermiT cannot reason over.
    lossy = differential.lossy_for_oracles(inputs)
    faults = differential.hermit_faults(inputs)
    ttl = convert(docs)
    batch = list(inputs) + [t for t, _ in ttl.values() if t]
    # A stage HermiT cannot reason over is excused only when the stage itself
    # carries a known HermiT fault, not because the input did.
    stage_faults = {}
    for t, _ in ttl.values():
        if t:
            stage_faults.update({t: why for n, why in differential.hermit_faults([t]).items()})
    differential.OUT = os.path.join(WORK, "oracle")
    reports, failures = differential.run_oracle("hermit", batch, timeout=timeout)

    def report_of(path):
        n = differential.name_of(path)
        if n in failures or n not in reports:
            return None, failures.get(n, "no report")
        return entdiff.parse(reports[n]), None

    lines, bad = [], 0
    for path in inputs:
        name, meta, classes, stages = plan[path]
        if "s0" not in stages:
            # The file gated (`info` ran), so a missing S0 is HOWL's failure.
            lines.append(f"{name} s0: FAILED: no document: {why.get((name, 's0'), 'not dumped')}")
            bad += 1
            continue
        side = {}
        for stage, doc in stages.items():
            t, err = ttl[doc]
            if t is None:
                lines.append(f"{name} {stage}: FAILED: the oracle refused HOWL's document: {err}")
                bad += 1
                side[stage] = (None, "refused document")
                continue
            r, err = report_of(t)
            if r is None and NO_ORACLE in (err or ""):
                pass  # the oracle's budget, not HOWL: reported as no oracle below
            elif r is None and t not in stage_faults:
                lines.append(f"{name} {stage}: FAILED: HermiT on HOWL's document: {err}")
                bad += 1
            elif r is None:
                err = stage_faults[t]
            elif r is not None and not r.inconsistent and not classes <= r.signature:
                lost = sorted(classes - r.signature)
                lines.append(f"{name} {stage}: FAILED: the document lost {len(lost)} input class(es), e.g. {lost[0]}")
                bad += 1
            side[stage] = (r, err)
        for stage in STAGES:
            reason = why.get((name, stage))
            if reason is not None and not reason.startswith((AWAITING_S1, RESERVED)):
                lines.append(f"{name} {stage}: FAILED: no document: {reason}")
                bad += 1
        if int(meta.get("omitted", "0")) != 0:
            side["input"] = (None, f"the gate omitted {meta.get('omitted')}")
        elif name in lossy:
            side["input"] = (None, f"OWL API blind spot: {lossy[name]}")
        elif name in faults:
            side["input"] = (None, faults[name])
        else:
            r, err = report_of(path)
            if r is None and NO_ORACLE not in (err or ""):
                # Not out of scope, yet HermiT gave no report: nothing certifies the input.
                lines.append(f"{name} input: FAILED: HermiT on the input: {err}")
                bad += 1
            side["input"] = (r, err)
        for a, b in LEGS:
            ra, wa = side.get(a, (None, why.get((name, a), "not dumped")))
            rb, wb = side.get(b, (None, why.get((name, b), "not dumped")))
            if ra is None or rb is None:
                # A timeout on either side is reported as such, never hidden
                # behind the other side's exclusion.
                why_not = next((w for w in (wa, wb) if NO_ORACLE in (w or "")), None) or wa or wb
                if NO_ORACLE in (why_not or ""):
                    # As in differential.py: no oracle within the budget is a
                    # failure, never a pass, though not a mismatch.
                    lines.append(f"{name} {a}~{b}: no oracle ({why_not})")
                    bad += 1
                else:
                    lines.append(f"{name} {a}~{b}: n/a ({why_not})")
                continue
            diff = entdiff.compare(restrict(rb, classes), restrict(ra, classes))
            if (a, b) == ("s0", "s1") and meta.get("s1-guarded") == "yes":
                # A guarded S1 is S0 minus its chains (SPEC §5.5): weaker by
                # design, so only what S0 does not entail is a mismatch.
                diff = {k: v for k, v in diff.items() if "extra" in k}
            if diff:
                bad += 1
                lines.append(f"{name} {a}~{b}: MISMATCH")
                for cat, items in sorted(diff.items()):
                    for item in items[:20]:
                        lines.append(f"  {cat.replace('HOWL', b)}: {item}")
            else:
                lines.append(f"{name} {a}~{b}: ok")
    return lines, bad


def oracle_one(ttl, out_dir, timeout):
    """HermiT on one document in its own JVM and directory: (report or None, why not, seconds).

    differential.run_oracle clears one shared output directory per call, so
    concurrent documents each get their own here."""
    os.makedirs(out_dir, exist_ok=True)
    for stale in os.listdir(out_dir):
        os.remove(os.path.join(out_dir, stale))
    env = dict(os.environ, HOWL_ORACLE_XMX=LONG_XMX)
    start = time.time()
    try:
        p = subprocess.run([differential.ORACLE, "report", "--reasoner", "hermit", "--out", out_dir, ttl],
                           capture_output=True, text=True, timeout=timeout, env=env)
    except subprocess.TimeoutExpired:
        return None, f"hermit {NO_ORACLE} {timeout}s", time.time() - start
    took = time.time() - start
    if p.stderr.strip():
        return None, f"hermit wrote to stderr: {p.stderr.strip().splitlines()[0]}", took
    report = os.path.join(out_dir, differential.name_of(ttl) + ".report")
    if p.returncode not in (0, 1) or not os.path.exists(report):
        return None, (p.stdout.strip().splitlines() or [f"exit {p.returncode}"])[-1], took
    return entdiff.parse(report), None, took


def long_check():
    """RO and OBI: S0~S1 and S1~S2, one JVM per document, two at a time."""
    ofn_dir = os.path.join(WORK, "ofn")
    os.makedirs(ofn_dir, exist_ok=True)
    plan, docs = {}, []
    for n in LONG:
        path = os.path.join(ROOT, "corpus", "vendor", f"{n}.ttl")
        meta, classes = info(path)
        stages = {}
        for stage in ("s0", "s1", "s2"):
            out = os.path.join(ofn_dir, f"vendor-{n}.{stage}.ofn")
            reason = dump(stage, path, out)
            if reason is not None:
                raise HarnessError(f"{n} {stage}: no document: {reason}")
            stages[stage] = out
            docs.append(out)
        plan[n] = (classes, stages)
    ttl = convert(docs)
    for doc, (t, err) in ttl.items():
        if t is None:
            raise HarnessError(f"the oracle refused HOWL's document {doc}: {err}")
    def run(doc):
        return oracle_one(ttl[doc][0], os.path.join(WORK, "oracle", os.path.basename(doc)), LONG_TIMEOUT)

    def s1_then_s2(stages):
        # S2 serves only the s1~s2 leg: without S1's report it would spend its budget for nothing.
        s1 = run(stages["s1"])
        return s1, run(stages["s2"]) if s1[0] is not None else (None, "s1 has no oracle", None)

    with ThreadPoolExecutor(max_workers=LONG_WORKERS) as pool:
        s0 = {n: pool.submit(run, plan[n][1]["s0"]) for n in LONG}
        rest = {n: pool.submit(s1_then_s2, plan[n][1]) for n in LONG}
        results = {}
        for n in LONG:
            stages = plan[n][1]
            results[stages["s0"]] = s0[n].result()
            results[stages["s1"]], results[stages["s2"]] = rest[n].result()
    lines, bad = [], 0
    for n in LONG:
        classes, stages = plan[n]
        for stage in ("s0", "s1", "s2"):
            r, err, took = results[stages[stage]]
            if took is None:
                lines.append(f"vendor-{n} {stage}: not run ({err})")
                continue
            lines.append(f"vendor-{n} {stage}: hermit {took / 3600:.2f} h" + (f" ({err})" if err else ""))
        for a, b in (("s0", "s1"), ("s1", "s2")):
            ra, wa, _ = results[stages[a]]
            rb, wb, _ = results[stages[b]]
            if ra is None or rb is None:
                lines.append(f"vendor-{n} {a}~{b}: no oracle ({wa or wb})")
                bad += 1
                continue
            lost = classes - rb.signature if not rb.inconsistent else set()
            diff = entdiff.compare(restrict(rb, classes), restrict(ra, classes))
            if diff or lost:
                bad += 1
                lines.append(f"vendor-{n} {a}~{b}: MISMATCH")
                for cat, items in sorted(diff.items()):
                    for item in items[:50]:
                        lines.append(f"  {cat.replace('HOWL', b)}: {item}")
                if lost:
                    lines.append(f"  {b} lost {len(lost)} input class(es), e.g. {sorted(lost)[0]}")
            else:
                lines.append(f"vendor-{n} {a}~{b}: ok")
    return lines, bad


def main(argv):
    if len(argv) < 2 or argv[1] not in ("fixtures", "guarded", "corpus", "long"):
        print(__doc__)
        return 3
    global WORK
    WORK = os.path.join(ROOT, "build", "elim", argv[1])  # one work tree per mode
    if argv[1] == "long":
        try:
            lines, bad = long_check()
        except (HarnessError, differential.HarnessError) as e:
            print(f"harness: {e}")
            return 3
        for line in lines:
            print(line)
        if "--record" in argv:
            with open(LONG_RECORD, "w", encoding="utf-8") as f:
                f.write(f"# RO and OBI against HermiT, one JVM per document ({LONG_XMX}, "
                        f"{LONG_TIMEOUT // 3600} h budget each); see `make diff-elim-long`.\n")
                f.write("\n".join(lines) + "\n")
        print(f"{sum(1 for l in lines if l.endswith(': ok'))} ok, {bad} failed, mismatched or no oracle")
        return 1 if bad else 0
    if argv[1] == "fixtures":
        inputs = differential.fixtures(*differential.FIXTURE_DIRS, "el++", "out-of-profile", "sriq")
    elif argv[1] == "guarded":
        # S1's guard tripped on purpose: S0~S1 is then checked one way.
        BOUND.append("0")
        inputs = [os.path.join(ROOT, "corpus", "fixtures", f + ".ttl") for f in GUARDED]
    else:
        inputs = [os.path.join(ROOT, "corpus", "vendor", f"{n}.ttl") for n in CORPUS]
        missing = [f for f in inputs if not os.path.exists(f)]
        if missing:
            print("MISSING " + " ".join(missing) + " (run ./corpus/fetch.sh)")
            return 3
    try:
        if argv[1] == "corpus":
            # One ontology per oracle batch, each with a budget, so a slow one
            # never holds the others hostage. A timeout is "no oracle", never a pass.
            lines, bad = [], 0
            for f in inputs:
                l, b = check([f], timeout=CORPUS_TIMEOUT)
                lines += l
                bad += b
            l, b = invariant_lines()
            lines += l
            bad += b
        else:
            lines, bad = check(inputs)
    except (HarnessError, differential.HarnessError) as e:
        print(f"harness: {e}")
        return 3
    for line in lines:
        print(line)
    if argv[1] == "corpus" and "--record" in argv:
        with open(RECORD, "w", encoding="utf-8") as f:
            f.write(RECORD_NOTE + "\n" + "\n".join(lines) + "\n")
    print(f"{sum(1 for l in lines if l.endswith(': ok'))} ok, {bad} failed or mismatched, "
          f"{sum(1 for l in lines if ': n/a' in l)} n/a, {sum(1 for l in lines if ': no oracle' in l)} no oracle")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
