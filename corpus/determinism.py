#!/usr/bin/env python3
"""M1 (e): the canonical report is byte-identical at every worker count, capped runs included.

    python3 corpus/determinism.py [--repeat N]            # every committed fixture
    python3 corpus/determinism.py --corpus [--repeat N]   # the materialized corpus projections

For each input, R is read from a default run's `rounds` line. Then for every
cap in {0, 1, R/2, R-1, R, 10000} and every worker count W in {1, 2, 4, 8},
`howl validate FILE --report --max-iterations CAP --workers W` must produce
the same bytes and the same exit code as W = 1.

WHY CAPPED RUNS ARE THE POINT. EL saturation is confluent: a run that reaches
its fixpoint derives the same set whatever the scheduling, so comparing only
complete runs would pass a racing engine. The exposure is a run cut short —
it reports whatever state the rounds reached — so the caps below R are what
this gate is for, and it refuses to pass if none of them ever bites (a gate
whose caps never cut a run has checked only complete runs, SPEC §6.8).

Only caps 1..R-1 count as "cut short": cap 0 runs no round at all, so it never
exercises the parallel join. Each W > 1 run is repeated (--repeat, default 2),
since an intermittent scheduling divergence could pass a single comparison.

Exit 0 when every input agrees at every cap and some cap bit; 1 otherwise.
"""
import hashlib
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
HOWL = os.environ.get("HOWL", os.path.join(ROOT, "build", "howl"))
WORKERS = (1, 2, 4, 8)
UNCAPPED = 10000


def inputs(corpus):
    if corpus:
        vendor = os.path.join(HERE, "vendor")
        files = sorted(os.path.join(vendor, f) for f in os.listdir(vendor) if f.endswith(".v0.ttl"))
        if not files:
            sys.exit("no materialized corpus under corpus/vendor/ (run make materialize)")
        return files
    out = []
    for d in ("v0", "hazards", "probes", "out-of-profile"):
        base = os.path.join(HERE, "fixtures", d)
        out += sorted(os.path.join(base, f) for f in os.listdir(base) if f.endswith(".ttl"))
    return out


def run(path, cap, workers):
    p = subprocess.run([HOWL, "validate", path, "--report", "--max-iterations", str(cap),
                        "--workers", str(workers)], capture_output=True)
    if not p.stdout.startswith(b"howl-report 1\n"):
        sys.exit(f"howl gave no report for {path} (cap {cap}, W {workers}): {p.stderr.decode().strip()}")
    return p.stdout, p.returncode


def binary_sha():
    with open(HOWL, "rb") as fh:
        return hashlib.sha256(fh.read()).hexdigest()


def main(argv):
    corpus = "--corpus" in argv
    repeat = int(argv[argv.index("--repeat") + 1]) if "--repeat" in argv else 2
    failed, bit, checked = False, 0, 0
    # THE BINARY MUST NOT CHANGE UNDER THE RUN. A corpus pass takes minutes;
    # a rebuild of build/howl partway through (a mutation check, say) mixes
    # two engines into one comparison and reports their difference as a
    # worker-count divergence — which is exactly what happened once.
    started = binary_sha()
    for path in inputs(corpus):
        rel = os.path.relpath(path, ROOT)
        base, _ = run(path, UNCAPPED, 1)
        rounds = int(re.search(rb"^rounds (\d+)$", base, re.M).group(1))
        caps = sorted({0, 1, rounds // 2, max(rounds - 1, 0), rounds, UNCAPPED})
        bad = []
        for cap in caps:
            ref = run(path, cap, 1)
            if 1 <= cap < rounds and b"termination resource-limit" in ref[0]:
                bit += 1
            for w in WORKERS[1:]:
                for _ in range(repeat):
                    checked += 1
                    if run(path, cap, w) != ref:
                        bad.append(f"cap {cap}: W={w} differs from W=1")
                        break
        if bad:
            failed = True
            print(f"  FAIL {rel}: " + "; ".join(bad))
        elif corpus:
            print(f"  ok   {rel}  (R={rounds}, caps {caps})")
    if binary_sha() != started:
        print(f"  FAIL {os.path.relpath(HOWL, ROOT)} changed during the run: the comparison mixed two engines")
        failed = True
    if bit == 0:
        print("  FAIL no cap below R ever cut a run short: only complete runs were compared")
        failed = True
    print(f"  {checked} worker-count comparisons, {bit} capped runs that bit: "
          f"{'IDENTICAL AT EVERY WORKER COUNT' if not failed else 'DETERMINISM FAILED'}")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
