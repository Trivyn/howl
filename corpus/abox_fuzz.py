#!/usr/bin/env python3
"""A randomized ABox differential: HOWL against HermiT (SPEC.md §5.3, M1 (f)).

    python3 corpus/abox_fuzz.py [--seeds FIRST:LAST] [--update]

§5.3 proves the direct-edge ABox encoding sound and complete for the calculus.
This checks the CODE against that argument, over ontologies nobody wrote by
hand: each seed generates a small v0 ontology — classes, roles, GCIs with
conjunctions and existentials on both sides, disjointness, role inclusions,
property chains, domains and ranges — plus an ABox of class assertions (named
and complex) and role assertions, balanced so that a good share of the
ontologies are inconsistent through their ABox and the rest are compared class
pair by class pair. HOWL and HermiT each report on every one,
and corpus/entdiff.py compares them: consistency, unsatisfiable classes and
every class-pair subsumption.

EVERY GENERATED ONTOLOGY MUST PASS THE GATE. The generator builds only what
§5.2 accepts: roles in a fixed order, with every role inclusion and chain
pointing up it (OWL 2 regularity), and the range/composition condition closed
by construction — whatever range a chain's super-role inherits is also given
to its last role, repeated to a fixpoint. An omission is therefore a generator
bug, reported as a failure, never skipped.

The outcome is written to corpus/abox-fuzz.txt with --update (a deliberate
act, as `make probes-update`); without it the run must reproduce the recorded
counts. Reports land in build/abox-fuzz/ for inspection. Exit 0 when every
ontology is clean, 1 on any mismatch, 3 when the harness cannot run.
"""
import argparse
import os
import random
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
import entdiff  # noqa: E402

HOWL = os.environ.get("HOWL", os.path.join(ROOT, "build", "howl"))
ORACLE = os.path.join(ROOT, "oracle", "build", "oracle")
OUT = os.path.join(ROOT, "build", "abox-fuzz")
RECORD = os.path.join(HERE, "abox-fuzz.txt")
DEFAULT_SEEDS = (1, 400)

PREFIXES = """@prefix :     <http://example.org/fuzz#> .
@prefix owl:  <http://www.w3.org/2002/07/owl#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
"""


class Gen:
    """One ontology's worth of Turtle, from one seed."""

    def __init__(self, seed):
        self.rng = random.Random(seed)
        self.lines = []
        self.nc = self.rng.randint(4, 7)
        self.nr = self.rng.randint(2, 4)
        self.ni = self.rng.randint(2, 5)
        self.classes = [f":C{i}" for i in range(self.nc)]
        self.roles = [f":r{i}" for i in range(self.nr)]   # the regularity order
        self.inds = [f":a{i}" for i in range(self.ni)]

    def cls(self):
        return self.rng.choice(self.classes)

    def some(self, depth=1):
        r, c = self.rng.choice(self.roles), self.concept(depth - 1)
        return f"[ a owl:Restriction ; owl:onProperty {r} ; owl:someValuesFrom {c} ]"

    def concept(self, depth=1):
        """A v0 class expression: a name, or at depth ∃r.C / C ⊓ D."""
        if depth <= 0 or self.rng.random() < 0.5:
            return self.cls()
        if self.rng.random() < 0.6:
            return self.some(depth)
        return f"[ a owl:Class ; owl:intersectionOf ( {self.concept(depth - 1)} {self.concept(depth - 1)} ) ]"

    def tbox(self):
        for _ in range(self.rng.randint(3, 8)):
            self.lines.append(f"{self.concept(2)} rdfs:subClassOf {self.concept(2)} .")
        for _ in range(self.rng.choice((0, 1, 1, 2))):
            a, b = self.rng.sample(self.classes, 2)
            self.lines.append(f"{a} owl:disjointWith {b} .")

    def rbox(self):
        # Inclusions and chains point UP the role order, so a strict order
        # witnessing OWL 2 regularity exists by construction.
        sups = {r: set() for r in self.roles}
        chains = []
        for i, r in enumerate(self.roles):
            for s in self.roles[i + 1:]:
                if self.rng.random() < 0.3:
                    self.lines.append(f"{r} rdfs:subPropertyOf {s} .")
                    sups[r].add(s)
        for i, t in enumerate(self.roles):
            if i >= 1 and self.rng.random() < 0.4:
                below = self.roles[:i]
                n = self.rng.choice((2, 2, 3))
                steps = [self.rng.choice(below) for _ in range(n)]
                chains.append((steps, t))
                self.lines.append(f"{t} owl:propertyChainAxiom ( {' '.join(steps)} ) .")
            if self.rng.random() < 0.15:
                self.lines.append(f"{t} a owl:TransitiveProperty .")
        # Told closure, reflexive.
        up = {r: {r} | sups[r] for r in self.roles}
        changed = True
        while changed:
            changed = False
            for r in self.roles:
                for s in list(up[r]):
                    if not up[s] <= up[r]:
                        up[r] |= up[s]
                        changed = True
        ranges = {r: set() for r in self.roles}
        for r in self.roles:
            if self.rng.random() < 0.4:
                ranges[r].add(self.concept(1) if self.rng.random() < 0.3 else self.cls())
            if self.rng.random() < 0.4:
                self.lines.append(f"{r} rdfs:domain {self.concept(1)} .")

        def inherited(r):
            out = set()
            for s in up[r]:
                out |= ranges[s]
            return out
        # The range/composition condition, closed to a fixpoint: every range a
        # chain's super-role inherits is given to the chain's last role.
        changed = True
        while changed:
            changed = False
            for steps, t in chains:
                missing = inherited(t) - inherited(steps[-1])
                if missing:
                    ranges[steps[-1]] |= missing
                    changed = True
        for r in self.roles:
            for c in sorted(ranges[r]):
                self.lines.append(f"{r} rdfs:range {c} .")
        # Two roles' ranges made disjoint: with edges over both into one target,
        # only the target's single context can bring the two ranges together.
        named = [(r, c) for r in self.roles for c in sorted(ranges[r]) if c in self.classes]
        if len(named) >= 2 and self.rng.random() < 0.5:
            (r1, c1), (r2, c2) = self.rng.sample(named, 2)
            if r1 != r2 and c1 != c2:
                self.lines.append(f"{c1} owl:disjointWith {c2} .")

    def abox(self):
        for _ in range(self.rng.randint(1, 4)):
            self.lines.append(f"{self.rng.choice(self.inds)} a {self.concept(1)} .")
        # Several assertions into ONE target, over different roles: the shape
        # that tells the direct-edge encoding from the existential one (SPEC.md
        # §5.2's identity case), which uniformly random edges rarely draw.
        hub = self.rng.choice(self.inds)
        for _ in range(self.rng.randint(1, 6)):
            a = self.rng.choice(self.inds)
            b = hub if self.rng.random() < 0.5 else self.rng.choice(self.inds)
            self.lines.append(f"{a} {self.rng.choice(self.roles)} {b} .")

    def turtle(self, seed):
        decl = [f"<http://example.org/fuzz/{seed}> a owl:Ontology ."]
        decl += [f"{c} a owl:Class ." for c in self.classes]
        decl += [f"{r} a owl:ObjectProperty ." for r in self.roles]
        decl += [f"{a} a owl:NamedIndividual ." for a in self.inds]
        self.rbox()
        self.tbox()
        self.abox()
        return PREFIXES + "\n" + "\n".join(decl + self.lines) + "\n"


def generate(seeds):
    os.makedirs(os.path.join(OUT, "input"), exist_ok=True)
    files = []
    for seed in range(seeds[0], seeds[1] + 1):
        path = os.path.join(OUT, "input", f"seed{seed:04d}.ttl")
        with open(path, "w", encoding="utf-8") as fh:
            fh.write(Gen(seed).turtle(seed))
        files.append(path)
    return files


def run_howl(files):
    out = os.path.join(OUT, "howl")
    os.makedirs(out, exist_ok=True)
    reports = {}
    for f in files:
        p = subprocess.run([HOWL, "validate", f, "--report"], capture_output=True, text=True)
        path = os.path.join(out, os.path.basename(f)[:-4] + ".report")
        with open(path, "w", encoding="utf-8") as fh:
            fh.write(p.stdout)
        reports[os.path.basename(f)[:-4]] = path
    return reports


def run_hermit(files):
    out = os.path.join(OUT, "hermit")
    os.makedirs(out, exist_ok=True)
    for stale in os.listdir(out):
        os.remove(os.path.join(out, stale))
    p = subprocess.run([ORACLE, "report", "--reasoner", "hermit", "--out", out] + files,
                       capture_output=True, text=True)
    if p.returncode not in (0, 1) or p.stderr.strip():
        raise RuntimeError(f"hermit exited {p.returncode}: {p.stderr.strip() or p.stdout.strip()}")
    reports = {}
    for name in os.listdir(out):
        # The oracle names a report <dir>-<file>; the stem after "input-" is the seed.
        if name.endswith(".report"):
            reports[name[:-7].split("-", 1)[-1]] = os.path.join(out, name)
    return reports


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--seeds", default=f"{DEFAULT_SEEDS[0]}:{DEFAULT_SEEDS[1]}")
    ap.add_argument("--update", action="store_true")
    args = ap.parse_args(argv[1:])
    first, last = (int(x) for x in args.seeds.split(":"))
    for tool in (HOWL, ORACLE):
        if not os.path.exists(tool):
            print(f"  cannot run: {tool} is missing (make cli oracle)")
            return 3
    files = generate((first, last))
    howl = run_howl(files)
    try:
        hermit = run_hermit(files)
    except RuntimeError as e:
        print(f"  cannot run: {e}")
        return 3
    counts = {"clean": 0, "inconsistent": 0, "failed": 0}
    for stem in sorted(howl):
        try:
            h = entdiff.parse(howl[stem])
            if h.kind != "howl":
                raise entdiff.Refused(f"{howl[stem]}: not a HOWL report")
            if stem not in hermit:
                raise entdiff.Refused("HermiT gave no report")
            diff = entdiff.compare(h, entdiff.parse(hermit[stem]))
        except entdiff.Refused as e:
            # Incomplete included: every generated ontology must clear the
            # gate, so an omission is a generator bug, not a skip.
            print(f"  FAIL {stem}: {e}")
            counts["failed"] += 1
            continue
        if diff:
            counts["failed"] += 1
            print(f"  FAIL {stem}: " + "; ".join(f"{k}: {len(v)}" for k, v in sorted(diff.items())))
            continue
        counts["clean"] += 1
        if h.inconsistent:
            counts["inconsistent"] += 1
    line = (f"seeds {first}:{last} ontologies {last - first + 1} clean {counts['clean']} "
            f"of-which-inconsistent {counts['inconsistent']} failed {counts['failed']}")
    print(f"  {line}")
    if args.update:
        with open(RECORD, "w", encoding="utf-8") as fh:
            fh.write("# corpus/abox_fuzz.py outcome (make abox-fuzz). Regenerate with --update.\n")
            fh.write(line + "\n")
    elif os.path.exists(RECORD):
        recorded = [l.strip() for l in open(RECORD, encoding="utf-8") if not l.startswith("#")]
        if recorded and recorded[0] != line and f"seeds {first}:{last} " in recorded[0]:
            print(f"  DRIFT from corpus/abox-fuzz.txt: recorded `{recorded[0]}`")
            return 1
    return 0 if counts["failed"] == 0 else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv))
