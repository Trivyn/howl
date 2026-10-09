#!/usr/bin/env python3
"""Compare HOWL's canonical report with an oracle's, as ENTAILMENTS (SPEC.md §10 item 1).

    python3 corpus/entdiff.py HOWL.report ORACLE.report

Both sides are in the same bottom-compressed grammar: `howl validate --report`
(src/report.slop) on one, `oracle report` (oracle/) on the other. For each named
class A: `sub A B` for every named B that subsumes A (A itself and owl:Thing
included) when A is satisfiable, or `unsat A` plus the single `sub A owl:Nothing`
when it is not; an inconsistent ontology is `inconsistent true` and nothing else.
That is §10's "canonicalize both sides to the same bottom-collapsed form", so
the comparison is set difference, and it is linear in the report, not quadratic
in the signature — while still deciding entails-sub(A,B) for EVERY ordered pair:

    entails-sub(A,B)  =  inconsistent  or  A unsat  or  `sub A B`

ONLY A COMPLETE RUN IS COMPARED. A HOWL report that did not reach a fixpoint, or
that omitted any axiom, is a lower bound over a different theory; diffing it
would blame HOWL for what it was never given (§10 item 2). Such a report is
REFUSED (exit 3), never passed and never failed.

Checked in order, and each reported under its own category:
  1. SIGNATURE   the classes each side reports on must be the same set;
  2. consistency both inconsistent: pass, and nothing further is compared;
  3. unsat       HOWL-missing / HOWL-extra unsatisfiable classes;
  4. sub         for classes satisfiable on BOTH sides, HOWL-missing / HOWL-extra
                 subsumers. A class unsatisfiable on one side only is reported
                 once, in 3, and not expanded into the pairs it implies.

Exit 0 clean, 1 on any mismatch, 3 on malformed or refused input.
"""
import os
import sys
from collections import defaultdict

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import profiles  # noqa: E402

NOTHING = "http://www.w3.org/2002/07/owl#Nothing"
SHOWN = 50


class Refused(Exception):
    """Input that cannot be compared: malformed, or not a complete run."""


class Incomplete(Refused):
    """A WELL-FORMED HOWL report of a run that did not finish or omitted axioms.

    The only refusal a driver may treat as "not comparable, skip". Any other
    Refused is a malformed report — a failure, never a skip, or a HOWL
    regression that garbles its output would pass by being skipped.
    `reason` is "termination" or "omitted".
    """
    def __init__(self, message, reason):
        super().__init__(message)
        self.reason = reason


class Report:
    def __init__(self, kind, inconsistent, unsat, subs, meta):
        self.kind = kind                  # "howl" or "oracle"
        self.inconsistent = inconsistent  # bool
        self.unsat = unsat                # set of IRIs
        self.subs = subs                  # dict IRI -> set of IRIs
        self.meta = meta                  # header lines, for the record

    @property
    def signature(self):
        return set(self.subs)


def parse(path):
    try:
        with open(path, encoding="utf-8") as f:
            lines = f.read().splitlines()
    except OSError as e:
        raise Refused(f"{path}: {e.strerror}")
    if not lines:
        raise Refused(f"{path}: empty")
    head = lines[0]
    if head == "howl-report 2":
        kind = "howl"
    elif head == "oracle-report 1":
        kind = "oracle"
    else:
        raise Refused(f"{path}: not a report (first line {head!r})")

    inconsistent = None
    unsat, subs, meta = set(), defaultdict(set), [head]
    single = {}                      # keys that must appear exactly once
    tally = defaultdict(int)         # item lines, to check the counts against
    for n, line in enumerate(lines[1:], start=2):
        key, _, rest = line.partition(" ")
        tally[key] += 1
        if key in ("inconsistent", "termination", "omitted", "unsatisfiable", "subsumptions",
                   "verdict", "exit", "profile"):
            if key in single:
                raise Refused(f"{path}:{n}: a second {key} line")
            single[key] = rest
        if key == "sub":
            a, sp, b = rest.partition(" ")
            if not sp or not a or not b or " " in b:
                raise Refused(f"{path}:{n}: malformed sub line")
            subs[a].add(b)
        elif key == "unsat":
            if not rest or " " in rest:
                raise Refused(f"{path}:{n}: malformed unsat line")
            unsat.add(rest)
        elif key == "inconsistent":
            if rest not in ("true", "false"):
                raise Refused(f"{path}:{n}: malformed inconsistent line")
            inconsistent = rest == "true"
        elif key in ("termination", "omitted", "unsatisfiable", "subsumptions"):
            pass  # checked below, against the lines they count
        elif key in ("verdict", "exit"):
            pass  # checked below, against the facts they summarize
        elif key in ("rounds", "omission", "reasoner", "profile"):
            meta.append(line)
        else:
            raise Refused(f"{path}:{n}: unknown line key {key!r}")

    if inconsistent is None:
        raise Refused(f"{path}: no inconsistent line")
    if kind == "howl":
        # EVERY COUNT MUST MATCH ITS LINES before any of them is believed —
        # above all `omitted`, which decides whether the run is comparable.
        for count_key, item_key in (("omitted", "omission"), ("unsatisfiable", "unsat"),
                                    ("subsumptions", "sub")):
            if count_key not in single:
                raise Refused(f"{path}: no {count_key} line")
            if single[count_key] != str(tally[item_key]):
                raise Refused(f"{path}: {count_key} {single[count_key]} but {tally[item_key]} {item_key} line(s)")
        # A version-2 report states the calculus that ran (SPEC §5.1): its
        # findings are complete for that rung's logic and no other.
        if single.get("profile") not in profiles.RUNGS:
            raise Refused(f"{path}: profile {single.get('profile')!r}")
        termination = single.get("termination")
        if termination not in ("fixpoint", "resource-limit"):
            raise Refused(f"{path}: termination {termination!r}")
        # THE VERDICT MUST FOLLOW FROM THE FACTS (SPEC §6.2): incoherent
        # whenever a contradiction was proven, even under partial coverage;
        # coherent only from a complete run; inconclusive otherwise. Checked
        # BEFORE the completeness refusal, so a partial run's verdict is
        # checked too — a report that says `coherent` over omissions is the
        # false pass everything here exists to catch.
        if inconsistent or unsat:
            expected = "incoherent"
        elif termination == "fixpoint" and single["omitted"] == "0":
            expected = "coherent"
        else:
            expected = "inconclusive"
        if single.get("verdict") != expected:
            raise Refused(f"{path}: verdict {single.get('verdict')} but the report's facts make it {expected}")
        if "exit" in single and single["exit"] != {"coherent": "0", "incoherent": "1", "inconclusive": "2"}[expected]:
            raise Refused(f"{path}: exit {single['exit']} does not match verdict {expected}")
        # THE REFUSAL. Checked here rather than trusted to the caller, so no
        # driver can diff a partial run by forgetting to look.
        if termination != "fixpoint":
            raise Incomplete(f"{path}: termination {termination}: only a run that reached its fixpoint is compared",
                             "termination")
        if single["omitted"] != "0":
            raise Incomplete(f"{path}: omitted {single['omitted']}: HOWL reasoned over a smaller theory than the oracle",
                             "omitted")
    if inconsistent and (unsat or subs):
        raise Refused(f"{path}: an inconsistent report must carry no hierarchy")
    for a in unsat:
        if subs.get(a) != {NOTHING}:
            raise Refused(f"{path}: unsat {a} must be bottom-compressed to the single `sub {a} owl:Nothing`")
    for a, bs in subs.items():
        if NOTHING in bs and a not in unsat:
            raise Refused(f"{path}: `sub {a} owl:Nothing` without `unsat {a}`")
    return Report(kind, inconsistent, unsat, dict(subs), meta)


def compare(howl, oracle):
    """Mismatches as {category: [line, ...]}; empty when the two agree."""
    out = defaultdict(list)
    if howl.inconsistent != oracle.inconsistent:
        side = "HOWL-missing" if oracle.inconsistent else "HOWL-extra"
        out[f"{side} inconsistent"].append("inconsistent true")
        return out
    if howl.inconsistent:
        return out  # every pair is entailed on both sides: nothing to compare

    hs, os_ = howl.signature, oracle.signature
    for a in sorted(os_ - hs):
        out["SIGNATURE oracle-only"].append(a)
    for a in sorted(hs - os_):
        out["SIGNATURE HOWL-only"].append(a)

    for a in sorted(oracle.unsat - howl.unsat):
        out["HOWL-missing unsat"].append(a)
    for a in sorted(howl.unsat - oracle.unsat):
        out["HOWL-extra unsat"].append(a)

    for a in sorted(hs & os_):
        if a in howl.unsat or a in oracle.unsat:
            continue
        for b in sorted(oracle.subs[a] - howl.subs[a]):
            out["HOWL-missing sub"].append(f"{a} {b}")
        for b in sorted(howl.subs[a] - oracle.subs[a]):
            out["HOWL-extra sub"].append(f"{a} {b}")
    return out


def main(argv):
    if len(argv) != 3:
        print("usage: entdiff.py HOWL.report ORACLE.report", file=sys.stderr)
        return 3
    try:
        howl, oracle = parse(argv[1]), parse(argv[2])
        if howl.kind != "howl":
            raise Refused(f"{argv[1]}: expected a HOWL report")
        if oracle.kind != "oracle":
            raise Refused(f"{argv[2]}: expected an oracle report")
    except Refused as e:
        print(f"REFUSED {e}")
        return 3
    diff = compare(howl, oracle)
    if not diff:
        print("clean")
        return 0
    for cat in sorted(diff):
        items = diff[cat]
        print(f"{cat}: {len(items)}")
        for item in items[:SHOWN]:
            print(f"  {item}")
        if len(items) > SHOWN:
            print(f"  ... {len(items) - SHOWN} more")
    return 1


if __name__ == "__main__":
    sys.exit(main(sys.argv))
