# usage: mutverify.py TREE MUTANTS.py LOG
# Contract mutants. For each (name, file, old, new) in MUTANTS.py's MUTANTS: apply it in TREE,
# run `$SLOP verify FILE`, record which contracts fail, and restore. REFUTED names the
# contracts that caught it; VERIFIED means the mutant got past every contract.
# TREE is a scratch copy of the repository, never the working tree. $SLOP defaults to `slop`.
import os, re, runpy, signal, subprocess, sys
signal.signal(signal.SIGTERM, lambda *a: sys.exit(143))
tree, spec, log = sys.argv[1:4]
slop = os.environ.get("SLOP", "slop")
muts = runpy.run_path(spec)["MUTANTS"]
out = open(log, "a")
for name, f, old, new in muts:
    path = f"{tree}/{f}"
    orig = open(path, encoding="utf-8").read()
    if orig.count(old) != 1:
        out.write(f"{name}: SKIP ({orig.count(old)})\n"); out.flush(); continue
    open(path, "w", encoding="utf-8").write(orig.replace(old, new))
    try:
        p = subprocess.run(f"{slop} verify {f}", cwd=tree, shell=True, capture_output=True, text=True, timeout=900)
        t = p.stdout + p.stderr
        bad = re.findall(r"(failed|unknown): ([\w-]+)", t)
        if any(k == "failed" for k, _ in bad):
            v = f"REFUTED by {sorted(set(n for k, n in bad if k == 'failed'))}"
        elif bad:
            v = "UNKNOWN " + str(bad)
        elif p.returncode == 0 and re.search(r"All \d+ contract\(s\) verified|\d+ verified, 0 failed", t):
            v = "VERIFIED (no contract catches it)"
        else:
            # No verdict at all: the verifier did not run, or the mutant does not compile.
            v = f"ERROR (exit {p.returncode}): " + t[-200:].replace("\n", " ")
    except subprocess.TimeoutExpired:
        v = "timeout"
    finally:
        open(path, "w", encoding="utf-8").write(orig)
    out.write(f"{name}: {v}\n"); out.flush()
out.write("done\n")
