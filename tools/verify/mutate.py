# usage: mutate.py TREE MUTANTS.py LOG
# Test mutants. For each (name, file, old, new) in MUTANTS.py's MUTANTS: apply it in TREE,
# regenerate the C, run `make test` and then `make golden`, and restore. A mutant is red if
# it does not compile or either target fails; SURVIVED means the tests miss it.
# TREE is a scratch copy of the repository, never the working tree; SLOP_HOME must name the
# toolchain that generates the committed C.
import hashlib, os, signal, sys, subprocess, runpy, time
tree, spec, log = sys.argv[1:4]
# A mutant's `make test` and `make golden` each get MUTATE_TIMEOUT seconds (default 3000). A timeout
# is red: the suite did not pass. A mutant that keeps a run from reaching its fixpoint can take the
# R7 cap test through every cap up to 10,000 rounds, so a short limit keeps such mutants cheap.
LIMIT = int(os.environ.get("MUTATE_TIMEOUT", "3000"))
muts = runpy.run_path(spec)["MUTANTS"]
out = open(log, "a")

def run(cmd, t):
    # In its own process group, so a timeout kills make and the test binary under it, not only the
    # shell: an orphaned howl-test would keep running and skew every later mutant's timing.
    p = subprocess.Popen(cmd, cwd=tree, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                         text=True, start_new_session=True)
    try:
        out, _ = p.communicate(timeout=t)
        return p.returncode, out
    except subprocess.TimeoutExpired:
        os.killpg(p.pid, signal.SIGKILL)
        p.communicate()
        return 124, "timeout"

def csrc_digest():
    # The generated C, so a mutant that never reaches the build (a stray copy of its module, the
    # wrong file) shows as NO-OP rather than as a survivor.
    h = hashlib.sha256()
    for root, _, files in sorted(os.walk(f"{tree}/csrc/src")):
        for name in sorted(files):
            h.update(name.encode()); h.update(open(os.path.join(root, name), "rb").read())
    return h.hexdigest()

def failing(text):
    # The tests a red run failed, so each verdict says what caught the mutant.
    names = [l[len("[FAIL] "):] for l in text.splitlines() if l.startswith("[FAIL] ")]
    return ("; ".join(n[:60] for n in names[:3]) + (" …" if len(names) > 3 else "")) if names else ""

rc, tail = run("make csrc && make test && make golden", 6000)
if rc != 0:
    out.write("ABORT: the unmutated tree is not green, so no verdict would mean anything\n" + tail[-400:] + "\n")
    sys.exit(1)
base = csrc_digest()

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
        elif csrc_digest() == base:
            verdict = "NO-OP (the generated C did not change)"
        else:
            rc, tail = run("make test", LIMIT)
            if rc != 0 or "Failed: 0" not in tail:
                verdict = f"red (make test: {failing(tail) or tail[-200:]})"
            else:
                rc, tail = run("make golden", LIMIT)
                verdict = "red (golden)" if rc != 0 else "SURVIVED"
    finally:
        open(path, "w", encoding="utf-8").write(orig)
    out.write(f"{name}: {verdict} [{time.time()-t0:.0f}s]\n"); out.flush()
run("make csrc", 1800)
out.write("done\n"); out.flush()
