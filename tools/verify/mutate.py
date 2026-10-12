# usage: mutate.py TREE MUTANTS.py LOG
# Test mutants. For each (name, file, old, new) in MUTANTS.py's MUTANTS: apply it in TREE,
# regenerate the C, run `make test` and then `make golden`, and restore. A mutant is red if
# it does not compile or either target fails; SURVIVED means the tests miss it.
# TREE is a scratch copy of the repository, never the working tree; SLOP_HOME must name the
# toolchain that generates the committed C.
import sys, subprocess, runpy, time
tree, spec, log = sys.argv[1:4]
muts = runpy.run_path(spec)["MUTANTS"]
out = open(log, "a")

def run(cmd, t):
    try:
        p = subprocess.run(cmd, cwd=tree, shell=True, capture_output=True, text=True, timeout=t)
        return p.returncode, p.stdout + p.stderr
    except subprocess.TimeoutExpired:
        return 124, "timeout"

def failing(text):
    # The tests a red run failed, so each verdict says what caught the mutant.
    names = [l[len("[FAIL] "):] for l in text.splitlines() if l.startswith("[FAIL] ")]
    return ("; ".join(n[:60] for n in names[:3]) + (" …" if len(names) > 3 else "")) if names else ""

rc, tail = run("make csrc && make test && make golden", 6000)
if rc != 0:
    out.write("ABORT: the unmutated tree is not green, so no verdict would mean anything\n" + tail[-400:] + "\n")
    sys.exit(1)

for name, f, old, new in muts:
    path = f"{tree}/{f}"
    orig = open(path, encoding="utf-8").read()
    if orig.count(old) != 1:
        out.write(f"{name}: SKIP (pattern count {orig.count(old)})\n"); out.flush(); continue
    open(path, "w", encoding="utf-8").write(orig.replace(old, new))
    t0 = time.time()
    try:
        rc, tail = run("make csrc", 1800)
        if rc != 0:
            verdict = "red (does not compile)"
        else:
            rc, tail = run("make test", 3000)
            if rc != 0 or "Failed: 0" not in tail:
                verdict = f"red (make test: {failing(tail) or tail[-200:]})"
            else:
                rc, tail = run("make golden", 3000)
                verdict = "red (golden)" if rc != 0 else "SURVIVED"
    finally:
        open(path, "w", encoding="utf-8").write(orig)
    out.write(f"{name}: {verdict} [{time.time()-t0:.0f}s]\n"); out.flush()
run("make csrc", 1800)
out.write("done\n"); out.flush()
