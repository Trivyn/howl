#!/usr/bin/env python3
"""M1 (c): SPEC.md §12's benchmark protocol, HOWL against its routed oracle.

    python3 bench/bench.py [--profile P] run     # time every corpus entry, write bench/results.txt
    python3 bench/bench.py [--profile P] check   # re-read results.txt: pins current, verdicts follow

--profile el++ benchmarks HOWL's el++ rung on the el++ projections against the
oracles corpus/corpus-differential-el++.txt routed and certified, into
bench/results-el++.txt. It is INFORMATIONAL: every verdict is `reported`, since
M1 (c)'s threshold is set for el against ELK and none is set for el++.

`make bench` builds an isolated release binary (build/bench/howl) and runs
`run` with HOWL pointing at it; `build/howl` is never touched.

THE PROTOCOL. Per entry: 1 warm-up and 5 measured runs of each side, W = 4,
the median compared. HOWL runs are separate processes; the oracle's share one
JVM (`oracle bench`), so its measured runs are JIT-warm — the direction that
favours the oracle, never HOWL.

THE BOUNDARY: AXIOMS IN HAND TO TAXONOMY, ON BOTH SIDES. For the oracle it is
create + consistent + classify, over an OWLOntology its untimed parse built:
the OWL API's parse does the text AND the RDF-to-OWL mapping (reification,
lists, class expressions), and ELK loads, normalizes and indexes those axioms
lazily at the first query, HermiT in its constructor - inside the window. For
HOWL it is prepare_ms + reason_ms: gate, normalize, rename, initialize,
premise index, saturation and extraction, over the axioms its untimed parse
and decode built. HOWL's decode (triples to axioms) is the counterpart of the
OWL API's mapping, so it is outside the window as that is; it is recorded
beside it (howl_decode_ms), never hidden. reason_ms alone is recorded, not
gated.

WHICH ORACLE. The routing `make diff-corpus` derived and recorded in
corpus/corpus-differential.txt: ELK for the capability-probed common subset
(GO, EL-GALEN), HermiT for range-bearing entries (RO, OBI). Only ELK-routed
entries are gated, at 5x: §12 sets its threshold against ELK and names none
against a complete oracle, so HermiT's ratio is recorded and not judged.

THE INPUT IS THE CERTIFIED PROJECTION. Before any timing, each file is
checked exactly as `make diff-corpus` checks it (project.check_graph): its
ground triples, blank-node count and blank-node structure against the pinned
projection, which must be the pins the differential recorded. A different
file could give the same answers for less work; this is what rules that out.

EVERY TIMED RUN MUST REPRODUCE THE CERTIFIED ANSWER. Each HOWL report must
hash to the record's `howl-report`, show `termination fixpoint` and
`omitted 0`; each oracle run must hash to its `oracle-entailments`. A timing
is therefore always of the exact input and answer the differential certified
clean, and HOWL cannot look fast by doing less work (§10 item 2).

Exit 0 when every gated entry is within 5x; 1 when any is not, or on any
refusal. `check` exits 1 only when results.txt is inconsistent or stale.
"""
import hashlib
import os
import platform
import re
import statistics
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
HOWL = os.environ.get("HOWL", os.path.join(ROOT, "build", "bench", "howl"))
ORACLE = os.path.join(ROOT, "oracle", "build", "oracle")
TRIPWIRE = os.path.join(ROOT, "corpus", "fixtures", "out-of-profile", "allvalues.ttl")
CORPUS = os.path.join(ROOT, "corpus")
sys.path.insert(0, CORPUS)
import profiles  # noqa: E402
PROFILE = "el"
RECORD = os.path.join(CORPUS, "corpus-differential.txt")
RESULTS = os.path.join(HERE, "results.txt")


def set_profile(p):
    """Benchmark one rung: its certified record, its projections, its results file."""
    global PROFILE, RECORD, RESULTS
    if p not in profiles.BUILT:
        raise Refusal(f"unknown profile {p} ({profiles.expected()})")
    PROFILE = p
    if p != "el":
        RECORD = os.path.join(CORPUS, f"corpus-differential-{p}.txt")
        RESULTS = os.path.join(HERE, f"results-{p}.txt")
SCRATCH = os.path.join(ROOT, "build", "bench")
WORKERS = 4
WARMUP, RUNS = 1, 5
THRESHOLD = 5.0
GATED = "elk"


class Refusal(Exception):
    """A run whose timing would not measure what the protocol says it does."""


# -- the certified record ----------------------------------------------------

def parse_record(text):
    """corpus-differential.txt -> {stem: {field: value}}."""
    out = {}
    for line in text.splitlines():
        if not line.strip() or line.startswith("#"):
            continue
        stem, *fields = line.split()
        out[stem] = dict(f.split("=", 1) for f in fields)
    return out


def vendor_path(stem):
    # project.materialized_path's naming.
    return os.path.join(CORPUS, "vendor", f"{stem}.{'v0' if PROFILE == 'el' else PROFILE}.ttl")


def verify_input(stem, rec, path):
    """Refuse unless `path` is the projection the differential certified,
    by the same content check `make diff-corpus` runs before it compares."""
    sys.path.insert(0, CORPUS)
    import project
    from rdflib import Graph
    base = os.path.join(CORPUS, "projections") if PROFILE == "el" else os.path.join(CORPUS, "projections", PROFILE)
    with open(os.path.join(base, stem + ".removals"), encoding="utf-8") as fh:
        pins = project.pinned_header(fh.read())
    if (str(pins["ground_sha"])[:16], str(pins["bnode_sha"])[:16]) != (rec["ground"], rec["bnodes"]):
        raise Refusal("the projection's pins are not the ones the differential certified: rerun `make diff-corpus`")
    g = Graph()
    g.parse(path, format="turtle")
    errors = project.check_graph(g, pins, path, PROFILE)
    if errors:
        raise Refusal("the file is not the certified projection: " + "; ".join(errors))


# -- HOWL ------------------------------------------------------------------

def parse_timing(stderr):
    m = re.search(r"^timing parse_ms=(\d+) decode_ms=(\d+) prepare_ms=(\d+) reason_ms=(\d+) total_ms=(\d+)$",
                  stderr, re.M)
    if not m:
        raise Refusal(f"no --timings line from howl: {stderr.strip()[:200]}")
    return dict(zip(("parse", "decode", "prepare", "reason", "total"), map(int, m.groups())))


def check_report(report, pin):
    """Refusals for a HOWL report that is not the certified one, or not complete."""
    errors = []
    head = report[:4096].decode("utf-8", "replace")
    if not re.search(r"^termination fixpoint$", head, re.M):
        errors.append("the run did not reach its fixpoint")
    if not re.search(r"^omitted 0$", head, re.M):
        errors.append("coverage.omitted is not empty: the timing would be of a smaller theory")
    sha = hashlib.sha256(report).hexdigest()[:16]
    if sha != pin:
        errors.append(f"report sha {sha} is not the certified {pin}")
    return errors


def peak_bytes(rusage):
    # ru_maxrss is bytes on macOS and kilobytes on Linux.
    return rusage.ru_maxrss if sys.platform == "darwin" else rusage.ru_maxrss * 1024


def run_howl(path, pin):
    os.makedirs(SCRATCH, exist_ok=True)
    out_path, err_path = os.path.join(SCRATCH, "report.out"), os.path.join(SCRATCH, "timings.err")
    with open(out_path, "wb") as out, open(err_path, "wb") as err:
        start = time.perf_counter()
        p = subprocess.Popen([HOWL, "validate", path, "--report", "--timings", "--workers", str(WORKERS),
                              "--profile", PROFILE],
                             stdout=out, stderr=err)
        _, status, rusage = os.wait4(p.pid, 0)
        wall = (time.perf_counter() - start) * 1000.0
        p.returncode = os.waitstatus_to_exitcode(status)
    with open(out_path, "rb") as fh:
        report = fh.read()
    with open(err_path, encoding="utf-8", errors="replace") as fh:
        stderr = fh.read()
    if p.returncode != 0:
        raise Refusal(f"howl exited {p.returncode}: {stderr.strip()[:200]}")
    errors = check_report(report, pin)
    if errors:
        raise Refusal("; ".join(errors))
    t = parse_timing(stderr)
    return {"classify": t["prepare"] + t["reason"], "decode": t["decode"], "reason": t["reason"],
            "e2e": wall, "peak": peak_bytes(rusage)}


# -- the oracle --------------------------------------------------------------

BENCH_LINE = re.compile(r"^bench run=(\d+) (warmup|measured) parse_ms=([\d.]+) create_ms=([\d.]+) "
                        r"consistent_ms=([\d.]+) classify_ms=([\d.]+) extract_ms=([\d.]+) "
                        r"lines=(\d+) entailments=([0-9a-f]{64})$")


def parse_oracle(stdout, pin):
    """`oracle bench` stdout -> (header, [measured runs]). Refuses a FAIL, a
    missing run, or any run whose entailments are not the certified ones."""
    header, runs, seen = None, [], []
    for line in stdout.splitlines():
        if line.startswith("bench-oracle "):
            header = line[len("bench-oracle "):]
        elif line.startswith(("FAIL", "ABORT", "usage")):
            raise Refusal(f"oracle: {line}")
        else:
            m = BENCH_LINE.match(line)
            if not m:
                continue
            parse, create, consistent, classify, extract = map(float, m.groups()[2:7])
            seen.append((int(m.group(1)), m.group(2)))
            if m.group(9)[:16] != pin:
                raise Refusal(f"oracle run {m.group(1)} entailments {m.group(9)[:16]} are not the certified {pin}")
            if m.group(2) == "measured":
                runs.append({"classify": create + consistent + classify,
                             "e2e": parse + create + consistent + classify + extract})
    if header is None:
        raise Refusal("oracle printed no bench-oracle header")
    expected = [(i, "warmup" if i < WARMUP else "measured") for i in range(WARMUP + RUNS)]
    if seen != expected:
        raise Refusal(f"oracle runs were {seen}, expected {WARMUP} warm-up then {RUNS} measured, in order")
    return header, runs


def run_oracle(reasoner, path, pin):
    cmd = [ORACLE, "bench", "--reasoner", reasoner, "--warmup", str(WARMUP), "--runs", str(RUNS)]
    if reasoner == "elk":
        cmd += ["--workers", str(WORKERS), "--tripwire", TRIPWIRE]
    p = subprocess.Popen(cmd + [path], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    out, err = p.communicate()
    # Nothing may reach stderr: the oracle routes every warning to stdout as a
    # FAIL, so stderr output is a JVM or logging path the capture does not see.
    if err.strip():
        raise Refusal(f"oracle wrote to stderr: {err.decode(errors='replace').strip()[:200]}")
    if p.returncode != 0:
        raise Refusal(f"oracle exited {p.returncode}: {out.decode(errors='replace').strip()[-300:]}")
    header, runs = parse_oracle(out.decode(), pin)
    return header, runs


# -- results -----------------------------------------------------------------

def summarize(runs, key):
    xs = [r[key] for r in runs]
    return statistics.median(xs), min(xs), max(xs)


def verdict(oracle, ratio):
    if oracle != GATED or PROFILE != "el":
        return "reported"
    return "pass" if ratio <= THRESHOLD else "FAIL"


def recorded_ratio(howl_ms, oracle_ms):
    """The ratio of the medians AS WRITTEN (whole ms). `run` and `check` both
    judge this exact value, so a rounded ratio can never carry a verdict the
    unrounded one would not (5.04x printed as 5.0 is still a FAIL)."""
    if oracle_ms <= 0:
        raise Refusal("the oracle's median classification rounds to 0 ms: nothing to compare against")
    return howl_ms / oracle_ms


def entry_line(stem, rec, howl_runs, oracle_runs):
    hc, hc_lo, hc_hi = summarize(howl_runs, "classify")
    oc, oc_lo, oc_hi = summarize(oracle_runs, "classify")
    hc, oc = round(hc), round(oc)
    ratio = recorded_ratio(hc, oc)
    fields = [
        ("oracle", rec["oracle"]),
        ("howl-report", rec["howl-report"]),
        ("oracle-entailments", rec["oracle-entailments"]),
        ("howl_classify_ms", str(hc)), ("howl_classify_range", f"{hc_lo:.0f}-{hc_hi:.0f}"),
        ("howl_decode_ms", f"{summarize(howl_runs, 'decode')[0]:.0f}"),
        ("howl_reason_ms", f"{summarize(howl_runs, 'reason')[0]:.0f}"),
        ("howl_e2e_ms", f"{summarize(howl_runs, 'e2e')[0]:.0f}"),
        ("howl_peak_mb", f"{max(r['peak'] for r in howl_runs) / 2**20:.0f}"),
        ("oracle_classify_ms", str(oc)), ("oracle_classify_range", f"{oc_lo:.0f}-{oc_hi:.0f}"),
        ("oracle_e2e_ms", f"{summarize(oracle_runs, 'e2e')[0]:.0f}"),
        ("ratio", f"{ratio:.2f}"),
        ("verdict", verdict(rec["oracle"], ratio)),
    ]
    return f"entry {stem} " + " ".join(f"{k}={v}" for k, v in fields)


def parse_entry(line):
    _, stem, *fields = line.split()
    return stem, dict(f.split("=", 1) for f in fields)


def machine():
    if sys.platform == "darwin":
        q = lambda k: subprocess.run(["sysctl", "-n", k], capture_output=True, text=True).stdout.strip()
        cpu, cores, mem = q("machdep.cpu.brand_string"), q("hw.ncpu"), int(q("hw.memsize") or 0)
    else:
        cpu = next((l.split(":", 1)[1].strip() for l in open("/proc/cpuinfo") if l.startswith("model name")), "?")
        cores = str(os.cpu_count())
        mem = next((int(l.split()[1]) * 1024 for l in open("/proc/meminfo") if l.startswith("MemTotal")), 0)
    return f'machine cpu="{cpu}" cores={cores} memory_gb={mem / 2**30:.0f} os="{platform.platform()}"'


def csrc_digest():
    """The C the binary was built from, independent of commit state."""
    h = hashlib.sha256()
    for d, _, files in sorted(os.walk(os.path.join(ROOT, "csrc"))):
        for f in sorted(files):
            if f.endswith((".c", ".h")):
                h.update(os.path.relpath(os.path.join(d, f), ROOT).encode())
                with open(os.path.join(d, f), "rb") as fh:
                    h.update(hashlib.sha256(fh.read()).digest())
    return h.hexdigest()[:16]


def file_sha(path):
    with open(path, "rb") as fh:
        return hashlib.sha256(fh.read()).hexdigest()[:16]


HEADER = f"""\
# M1 (c): SPEC.md §12's benchmark protocol. Generated by `make bench`; never edited by hand.
# classify: axioms in hand to taxonomy. HOWL prepare_ms + reason_ms (gate through extraction)
#   against the oracle's create + consistent + classify (its indexing included). Untimed on both
#   sides: the parse and the RDF-to-axiom mapping (HOWL's decode, recorded as howl_decode_ms; the
#   OWL API's parse). e2e: HOWL's process wall-clock, parse to report written; the oracle's
#   in-process parse through extraction.
# Median of {RUNS} measured runs after {WARMUP} warm-up; ranges are min-max. Every run reproduced the
#   certified report and entailments pinned below (corpus/corpus-differential.txt).
# Gated: ELK-routed entries, ratio <= {THRESHOLD:.1f}. HermiT-routed (range-bearing) entries are
#   timed and reported: §12 sets no threshold against a complete oracle."""

HEADER_INFORMATIONAL = """\
# The el++ rung's benchmark (bench/bench.py --profile el++). Generated by `make bench-el++`; never
#   edited by hand. INFORMATIONAL: every entry is timed and reported, none is gated, since SPEC
#   §12's threshold is set for el against ELK and none is set for el++.
# The protocol and the classify window are `make bench`'s: HOWL prepare_ms + reason_ms against the
#   oracle's create + consistent + classify; median of the measured runs after a warm-up; ranges
#   are min-max. Every run reproduced the certified report and entailments pinned below
#   (corpus/corpus-differential-el++.txt)."""


def cmd_run():
    with open(RECORD, encoding="utf-8") as fh:
        record = parse_record(fh.read())
    if not os.path.exists(HOWL):
        raise Refusal(f"{os.path.relpath(HOWL, ROOT)} is missing: run `make bench`")
    binary = file_sha(HOWL)
    load_before = os.getloadavg()[0]
    lines, oracle_header = [], None
    for stem, rec in record.items():
        path = vendor_path(stem)
        if not os.path.exists(path):
            raise Refusal(f"{os.path.relpath(path, ROOT)} is missing: run `make materialize`")
        try:
            before = file_sha(path)
            verify_input(stem, rec, path)
            howl_runs = [run_howl(path, rec["howl-report"]) for _ in range(WARMUP + RUNS)][WARMUP:]
            header, oracle_runs = run_oracle(rec["oracle"], path, rec["oracle-entailments"])
            if file_sha(path) != before:
                raise Refusal("the input changed during the run")
        except Refusal as r:
            raise Refusal(f"{stem}: {r}")
        if rec["oracle"] == GATED:
            oracle_header = header
        line = entry_line(stem, rec, howl_runs, oracle_runs)
        print(f"  {line}")
        lines.append(line)
    if file_sha(HOWL) != binary:
        raise Refusal(f"{os.path.relpath(HOWL, ROOT)} changed during the run: the timings mix two binaries")
    # Recorded, not gated: a busy machine inflates both sides unevenly (HOWL
    # runs first), so a result taken under load says so in the file.
    load = f"load_1min before={load_before:.1f} after={os.getloadavg()[0]:.1f}"
    head = [HEADER if PROFILE == "el" else HEADER_INFORMATIONAL, machine() + " " + load,
            f'howl binary={binary} csrc={csrc_digest()} cflags="{os.environ.get("BENCH_CFLAGS", "?")}" '
            f"workers={WORKERS}",
            f"oracle {oracle_header}"]
    with open(RESULTS, "w", encoding="utf-8") as fh:
        fh.write("\n".join(head + lines) + "\n")
    return report(lines)


def report(lines):
    entries = [parse_entry(l) for l in lines]
    failed = [(s, f["ratio"]) for s, f in entries if f["verdict"] == "FAIL"]
    gated = [s for s, f in entries if f["verdict"] != "reported"]
    if PROFILE != "el":
        print(f"  {PROFILE}: {len(entries)} entries timed and reported (informational; no threshold is set)")
        return 0
    if not gated:
        print("  FAIL no entry is gated: M1 (c) was not measured")
        return 1
    if failed:
        print("  M1 (c) NOT MET: " + ", ".join(f"{s} {r}x" for s, r in failed) + f" (threshold {THRESHOLD:.1f}x)")
        return 1
    print(f"  M1 (c) met: every ELK-routed entry within {THRESHOLD:.1f}x")
    return 0


def cmd_check():
    """results.txt is consistent with itself and with the current record."""
    with open(RECORD, encoding="utf-8") as fh:
        record = parse_record(fh.read())
    with open(RESULTS, encoding="utf-8") as fh:
        lines = [l for l in fh.read().splitlines() if l.startswith("entry ")]
    errors = check_results(lines, record)
    for e in errors:
        print(f"  FAIL {e}")
    if errors:
        return 1
    report(lines)
    return 0


def check_results(lines, record):
    errors = []
    seen = set()
    for line in lines:
        stem, f = parse_entry(line)
        seen.add(stem)
        rec = record.get(stem)
        if rec is None:
            errors.append(f"{stem}: not in corpus-differential.txt")
            continue
        for k in ("oracle", "howl-report", "oracle-entailments"):
            if f.get(k) != rec.get(k):
                errors.append(f"{stem}: {k} {f.get(k)} is stale (record says {rec.get(k)}): rerun `make bench`")
        # Written before M1 slice 6b moved the boundary: decode was inside
        # howl_classify_ms, so the ratio is of a different window.
        if "howl_decode_ms" not in f:
            errors.append(f"{stem}: no howl_decode_ms, so measured with decode inside the window: rerun `make bench`")
        ratio = recorded_ratio(int(f["howl_classify_ms"]), int(f["oracle_classify_ms"]))
        if f["ratio"] != f"{ratio:.2f}":
            errors.append(f"{stem}: ratio {f['ratio']} does not follow from the medians ({ratio:.2f})")
        if f["verdict"] != verdict(f["oracle"], ratio):
            errors.append(f"{stem}: verdict {f['verdict']} does not follow from the medians ({ratio:.4f})")
    for stem in sorted(set(record) - seen):
        errors.append(f"{stem}: in the record but not benchmarked")
    return errors


def main(argv):
    argv = list(argv)
    try:
        if "--profile" in argv:
            i = argv.index("--profile")
            set_profile(argv[i + 1] if i + 1 < len(argv) else "")
            del argv[i:i + 2]
    except Refusal as r:
        print(f"  REFUSED {r}")
        return 1
    cmd = argv[1] if len(argv) > 1 else ""
    try:
        if cmd == "run":
            return cmd_run()
        if cmd == "check":
            return cmd_check()
    except Refusal as r:
        print(f"  REFUSED {r}")
        return 1
    print(__doc__.split("\n\n")[1])
    return 3


if __name__ == "__main__":
    sys.exit(main(sys.argv))
