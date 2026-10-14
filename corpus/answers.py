#!/usr/bin/env python3
"""The answer run against HermiT on the whole of each corpus ontology (SPEC §8.4; Track P, P3).

`howl ask` classifies the queries' ⊥-locality module, and falls back to the
whole input when the module's run is incomplete. This holds its answers to
HermiT's classification of the WHOLE ontology, the input HOWL was given:

- `yes` must be entailed: HermiT has `sub A B`, or A unsatisfiable, or the
  ontology inconsistent.
- `no` must not be entailed. This is the claim the module makes possible, and
  the one that matters: a wrong `no` is a false negative a caller would act on.
- `unknown` is counted, never failed.

The same queries also go through `howl validate`'s two-run mode, for the answer
counts and times side by side. The answer run must keep every `yes` and `no`
the two-run mode gives (Constraint 499c3842).

Per entry: 15 subsumptions HermiT entails and 15 class pairs drawn with a fixed
random seed (mostly not entailed), all among the classes HermiT's report names.

    python3 corpus/answers.py [ENTRY...]       # default: every entry with a vendor file
    python3 corpus/answers.py --update         # also writes corpus/answer-differential.txt

HOWL runs through $HOWL (default build/howl). HermiT runs through the pinned
oracle; its report is cached in build/answers/. Exit 0 when no answer
contradicts HermiT or drops a two-run yes/no, 1 otherwise.
"""
import os
import random
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
VENDOR = os.path.join(ROOT, "corpus", "vendor")
OUT = os.path.join(ROOT, "build", "answers")
RECORD = os.path.join(ROOT, "corpus", "answer-differential.txt")
HOWL = os.environ.get("HOWL", os.path.join(ROOT, "build", "howl"))
ORACLE = os.path.join(ROOT, "oracle", "build", "oracle")
OWL = "http://www.w3.org/2002/07/owl#"
THING = OWL + "Thing"
ENTRIES = ["bfo-core-2024-02-07", "cco-2024-11-06", "ro-2025-12-17", "obi-2026-07-27",
           "go-2026-07-26", "el-galen-2011-04-12"]
YES, PAIRS = 15, 15
# EL-GALEN is plain EL, inside `el`, so ELK is complete for it and is its routed
# oracle, as in corpus/differential.py; HermiT does not finish it in 30 minutes.
ELK_ENTRIES = {"el-galen-2011-04-12"}
TRIPWIRE = os.path.join(ROOT, "corpus", "fixtures", "out-of-profile", "allvalues.ttl")


def oracle_name(entry):
    return "elk" if entry in ELK_ENTRIES else "hermit"


def hermit(entry, path):
    """The routed oracle's report on the whole file: (inconsistent, {A: supers}, unsat), or None if it refused."""
    reasoner = oracle_name(entry)
    out = os.path.join(OUT, reasoner)
    report = os.path.join(out, "vendor-" + entry + ".report")
    if not os.path.exists(report):
        os.makedirs(out, exist_ok=True)
        cmd = [ORACLE, "report", "--reasoner", reasoner, "--out", out, path]
        if reasoner == "elk":
            cmd[4:4] = ["--tripwire", TRIPWIRE]
        try:
            p = subprocess.run(cmd, capture_output=True, text=True, timeout=1800)
        except subprocess.TimeoutExpired:
            return None, f"{reasoner} did not finish in 30 minutes"
        if p.returncode != 0 or not os.path.exists(report):
            return None, p.stdout.strip()[:300]
    inconsistent, supers, unsat = False, {}, set()
    for line in open(report):
        parts = line.split()
        if line.startswith("inconsistent true"):
            inconsistent = True
        elif parts[:1] == ["sub"]:
            supers.setdefault(parts[1], set()).add(parts[2])
        elif parts[:1] == ["unsat"]:
            unsat.add(parts[1])
    return (inconsistent, supers, unsat), None


def entailed(h, a, b):
    inconsistent, supers, unsat = h
    return inconsistent or a == b or b == THING or a in unsat or b in supers.get(a, ())


def queries_for(entry, h):
    _, supers, _ = h
    classes = sorted(c for c in supers if not c.startswith(OWL))
    if not classes:
        raise SystemExit(f"{entry}: the oracle's report names no class (an inconsistent ontology has no "
                         "hierarchy to draw queries from)")
    rnd = random.Random("answers:" + entry)
    subs = sorted((a, b) for a in classes for b in supers[a] if a != b and not b.startswith(OWL))
    qs = rnd.sample(subs, min(YES, len(subs)))
    qs += [tuple(rnd.sample(classes, 2)) for _ in range(PAIRS)] if len(classes) >= 2 else []
    return qs


def run(args):
    t0 = time.monotonic()
    p = subprocess.run([HOWL] + args, capture_output=True, text=True)
    return p, time.monotonic() - t0


def answers_of(text):
    out = {}
    for line in text.splitlines():
        parts = line.split()
        if parts[:2] == ["probe", "subsumed"]:
            out[(parts[2], parts[3])] = parts[4]
    return out


def one(entry):
    path = os.path.join(VENDOR, entry + ".ttl")
    if not os.path.exists(path):
        return None, f"skip {entry}: no {path} (run ./corpus/fetch.sh)"
    h, why = hermit(entry, path)
    if h is None:
        return None, f"skip {entry}: HermiT gave no report: {why}"
    qs = queries_for(entry, h)
    flags = []
    for a, b in qs:
        flags += ["--ask-sub", a, b]
    ask, t_ask = run(["ask", path, "--profile", "auto"] + flags)
    two, t_two = run(["validate", path, "--profile", "auto", "--report"] + flags)
    a_ans, t_ans = answers_of(ask.stdout), answers_of(two.stdout)
    # Both runs must answer every query: a fault that answers nothing must
    # fail here, not read as `unknown` and pass the comparison vacuously.
    for name, ans, proc in (("howl ask", a_ans, ask), ("the two-run mode", t_ans, two)):
        if any(q not in ans for q in qs):
            return None, (f"FAIL {entry}: {name} answered {len(ans)} of {len(qs)} queries "
                          f"(exit {proc.returncode}): {proc.stdout.strip()[:200]}")
    wrong, dropped = 0, 0
    counts = {"yes": 0, "no": 0, "unknown": 0}
    for q in qs:
        got = a_ans.get(q)
        if got is None:
            raise SystemExit(f"{entry}: no answer to {q} (exit {ask.returncode}): {ask.stdout[:300]}")
        counts[got] += 1
        ent = entailed(h, *q)
        if (got == "yes" and not ent) or (got == "no" and ent):
            wrong += 1
            print(f"  WRONG {entry} {q[0]} ⊑ {q[1]}: howl ask says {got}, {oracle_name(entry)} {'entails' if ent else 'does not'}")
        two_got = t_ans[q]
        if two_got in ("yes", "no") and got != two_got:
            dropped += 1
            print(f"  DROPPED {entry} {q[0]} ⊑ {q[1]}: two-run {two_got}, howl ask {got}")
    tc = {k: sum(1 for q in qs if t_ans.get(q) == k) for k in ("yes", "no", "unknown")}
    profile = ask.stdout.splitlines()[0].split()[1] if ask.stdout.startswith("profile ") else "?"
    line = (f"{entry} oracle {oracle_name(entry)} queries {len(qs)} wrong {wrong} dropped {dropped} "
            f"ask yes {counts['yes']} no {counts['no']} unknown {counts['unknown']} profile {profile} "
            f"two-run yes {tc['yes']} no {tc['no']} unknown {tc['unknown']} "
            f"seconds ask {t_ask:.1f} two-run {t_two:.1f}")
    return line, None


def main(argv):
    update = "--update" in argv
    names = [a for a in argv if not a.startswith("--")] or ENTRIES
    lines, bad = [], False
    for e in names:
        line, skip = one(e)
        if line is None:
            # A skipped entry compared nothing, so the run cannot pass on it.
            print("  " + str(skip))
            bad = True
            continue
        print("  " + line, flush=True)
        lines.append(line)
        bad = bad or " wrong 0 dropped 0 " not in line
    if update:
        with open(RECORD, "w") as f:
            f.write("# corpus/answers.py: howl ask against HermiT on the whole ontology, and against the "
                    "two-run mode. Times are wall seconds on the recording machine. Regenerate with --update.\n")
            f.write("\n".join(lines) + "\n")
    print("  answers: " + ("AN ANSWER CONTRADICTS THE ORACLE OR DROPS A TWO-RUN ANSWER" if bad else
                           "EVERY YES AND NO AGREES WITH THE ROUTED ORACLE AND KEEPS THE TWO-RUN MODE'S"))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
