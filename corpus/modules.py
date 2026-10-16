#!/usr/bin/env python3
"""HOWL's ⊥-locality modules against the OWL API's (SPEC §8.4; Track P, P3).

The answer run classifies the syntactic ⊥-locality module of its input for
the classes the queries name (src/locality.slop). This holds HOWL's extractor
to the OWL API's SyntacticLocalityModuleExtractor (ModuleType.BOT), through
the pinned oracle, on every corpus entry and a fixed sample of seeds: 25
single classes and 25 pairs per entry, drawn with a fixed random seed from the
classes HOWL's own `el` report names.

THE CHECK IS CONTAINMENT, NOT EQUALITY. Each module is compared by its
signature (classes, object properties, named individuals; OWL's own vocabulary
left out). HOWL's must contain every symbol of the OWL API's: a symbol the
OWL API keeps and HOWL drops means HOWL judged some axiom local that is not,
which could let a `no` through. HOWL may keep more: it never reads an InputRef
(data axioms, SWRL, keys), so those are never local, and it never empties
OWL's own vocabulary. The extra symbols are counted and shown, not failed.

A module that holds an axiom HOWL cannot read in full (`unreadable` > 0: SWRL,
keys, data axioms, a data range in a class position) may lack the symbols that
axiom names, since HOWL never reads them (SPEC §8.4 L3). Its run is then
incomplete and answers no `no`, and the missing symbols cannot change a `yes`
(L5), so such a seed is counted as `fallback`, not failed.

    python3 corpus/modules.py [ENTRY...]     # default: every entry with a vendor file
    python3 corpus/modules.py --update       # also writes corpus/module-differential.txt

HOWL runs through $HOWL_TEST (default build/howl-test) and the oracle through
oracle/build/oracle. Exit 0 when no seed has a missing symbol, 1 otherwise.
"""
import os
import random
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
VENDOR = os.path.join(ROOT, "corpus", "vendor")
OUT = os.path.join(ROOT, "build", "modules")
RECORD = os.path.join(ROOT, "corpus", "module-differential.txt")
HOWL = os.environ.get("HOWL", os.path.join(ROOT, "build", "howl"))
HOWL_TEST = os.environ.get("HOWL_TEST", os.path.join(ROOT, "build", "howl-test"))
ORACLE = os.path.join(ROOT, "oracle", "build", "oracle")
OWL = "http://www.w3.org/2002/07/owl#"
ENTRIES = ["bfo-core-2024-02-07", "cco-2024-11-06", "ro-2025-12-17", "obi-2026-07-27",
           "go-2026-07-26", "el-galen-2011-04-12"]
SINGLES = 25
PAIRS = 25


def classes_of(path):
    """The classes HOWL's `el` report names (the `sub` lines' subjects), sorted."""
    p = subprocess.run([HOWL, "validate", path, "--profile", "el", "--report"], capture_output=True, text=True)
    out = set()
    for line in p.stdout.splitlines():
        if line.startswith("sub "):
            a = line.split()[1]
            if not a.startswith(OWL):
                out.add(a)
    return sorted(out)


def seeds_for(entry, classes):
    rnd = random.Random("modules:" + entry)
    singles = rnd.sample(classes, min(SINGLES, len(classes)))
    pairs = [" ".join(rnd.sample(classes, 2)) for _ in range(PAIRS)] if len(classes) >= 2 else []
    return singles + pairs


def parse_modules(text, header):
    """{seed line: (axioms, set of symbols)} from either program's output."""
    lines = text.splitlines()
    if not lines or lines[0] != header:
        raise SystemExit(f"not a {header} output: {lines[:1]}")
    out, seed, axioms, unreadable, syms = {}, None, 0, 0, set()
    for line in lines[1:]:
        if line.startswith("seed "):
            seed, axioms, unreadable, syms = line[5:], 0, 0, set()
        elif line.startswith("axioms "):
            axioms = int(line.split()[1])
        elif line.startswith("unreadable "):
            unreadable = int(line.split()[1])
        elif line.startswith("sym "):
            if not line[4:].startswith(OWL):
                syms.add(line[4:])
        elif line == "end":
            out[seed] = (axioms, syms, unreadable)
    return out


def one(entry):
    path = os.path.join(VENDOR, entry + ".ttl")
    if not os.path.exists(path):
        return None, f"skip {entry}: no {path} (run ./corpus/fetch.sh)"
    classes = classes_of(path)
    if not classes:
        return None, f"skip {entry}: no classes in HOWL's report"
    seeds = seeds_for(entry, classes)
    os.makedirs(OUT, exist_ok=True)
    seed_file = os.path.join(OUT, entry + ".seeds")
    with open(seed_file, "w") as f:
        f.write("\n".join(seeds) + "\n")
    h = subprocess.run([HOWL_TEST, "module-dump", path, seed_file], capture_output=True, text=True)
    howl = parse_modules(h.stdout, "howl-modules 1")
    o = subprocess.run([ORACLE, "module", "--seeds", seed_file, "--out", OUT, path], capture_output=True, text=True)
    if o.returncode != 0:
        return None, f"skip {entry}: the oracle refused it: {o.stdout.strip()[:200]}"
    with open(os.path.join(OUT, "vendor-" + entry + ".modules")) as f:
        owlapi = parse_modules(f.read(), "oracle-modules 1")
    missing, fallback, extra_seeds, extra_total, ex = 0, 0, 0, 0, []
    hs, os_, ha, oa = [], [], [], []
    for seed in seeds:
        if seed not in howl or seed not in owlapi:
            raise SystemExit(f"{entry}: no module for seed {seed}")
        (h_ax, h_sym, h_unread), (o_ax, o_sym, _) = howl[seed], owlapi[seed]
        lost = o_sym - h_sym
        more = h_sym - o_sym
        # A module holding an axiom HOWL cannot read in full (L3) may miss
        # symbols that axiom names: its run is then incomplete and answers
        # no `no` (L3, L5). Only a module with every axiom readable must
        # contain the OWL API's.
        if lost and h_unread > 0:
            fallback += 1
        elif lost:
            missing += 1
            print(f"  MISSING {entry} seed {seed}: {len(lost)} symbol(s) the OWL API keeps, e.g. {sorted(lost)[:3]}")
        if more:
            extra_seeds += 1
            extra_total += len(more)
            if len(ex) < 2:
                ex.append(sorted(more)[:3])
        hs.append(len(h_sym)); os_.append(len(o_sym)); ha.append(h_ax); oa.append(o_ax)
    n = len(seeds)
    line = (f"{entry} classes {len(classes)} seeds {n} missing {missing} fallback {fallback} "
            f"larger {extra_seeds} mean-symbols howl {sum(hs)/n:.1f} owlapi {sum(os_)/n:.1f} "
            f"mean-axioms howl {sum(ha)/n:.1f} owlapi {sum(oa)/n:.1f} max-symbols howl {max(hs)} owlapi {max(os_)}")
    if ex:
        print(f"  note {entry}: HOWL keeps more on {extra_seeds} seed(s), e.g. {ex[0]}")
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
        bad = bad or " missing 0 " not in line
    if update:
        with open(RECORD, "w") as f:
            f.write("# corpus/modules.py: HOWL's ⊥-locality modules against the OWL API's (BOT), "
                    "per corpus entry. Regenerate with --update.\n")
            f.write("\n".join(lines) + "\n")
    print("  modules: " + ("A READABLE MODULE LOST A SYMBOL THE OWL API KEEPS" if bad else
                           "EVERY READABLE MODULE CONTAINS THE OWL API'S; THE REST FALL BACK"))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
