# usage: casevac.py TREE LOG FILE...
# Vacuity. For each (@post (implies C P)) or (@property name (implies C P)) in each FILE, add
# its negated twin (implies C (not P)) and run `$SLOP verify FILE` in TREE. If the twin also
# verifies, case C is vacuous: the guard is never true, and the post proves nothing.
# TREE is a scratch copy of the repository, never the working tree. $SLOP defaults to `slop`.
import os, re, subprocess, sys
tree, log = sys.argv[1:3]
slop = os.environ.get("SLOP", "slop")
out = open(log, "a")

def sexp_end(s, i):
    d = 0
    for k in range(i, len(s)):
        if s[k] == '(':
            d += 1
        elif s[k] == ')':
            d -= 1
            if d == 0:
                return k + 1
    raise ValueError

for f in sys.argv[3:]:
    path = f"{tree}/{f}"
    orig = open(path, encoding="utf-8").read()
    for m in re.finditer(r"\(@(?:post|property [\w-]+) \(implies ", orig):
        start = m.start(); end = sexp_end(orig, start)
        imp = orig.index("(implies", start); impend = sexp_end(orig, imp)
        c0 = imp + len("(implies "); c1 = sexp_end(orig, c0) if orig[c0] == '(' else orig.index(' ', c0)
        p0 = c1 + 1; p1 = sexp_end(orig, p0) if orig[p0] == '(' else impend - 1
        C = orig[c0:c1]; P = orig[p0:p1]
        fn = re.findall(r"\n  \(fn ([\w-]+) ", orig[:start])[-1]
        twin = f"\n    (@post (implies {C} (not {P})))"
        open(path, "w", encoding="utf-8").write(orig[:end] + twin + orig[end:])
        try:
            p = subprocess.run(f"{slop} verify {f}", cwd=tree, shell=True, capture_output=True, text=True, timeout=1200)
            t = p.stdout + p.stderr
            st = re.search(rf"(verified|failed|unknown): {re.escape(fn)}(?![\w-])", t)
            v = st.group(1) if st else "no verdict"
        except subprocess.TimeoutExpired:
            v = "timeout"
        finally:
            open(path, "w", encoding="utf-8").write(orig)
        # Only the twin failing for its own function shows the case is live. A verified twin is
        # vacuous; no verdict, unknown or a timeout shows nothing, so it is an error, never a pass.
        verdict = {"failed": "ok (failed)", "verified": "VACUOUS CASE"}.get(v, f"ERROR ({v})")
        out.write(f"{f} {fn} [{C[:70]}]: {verdict}\n"); out.flush()
out.write("done\n")
