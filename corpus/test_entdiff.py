"""Self-tests for corpus/entdiff.py: every category fires, and every refusal refuses.

    python3 -m unittest corpus/test_entdiff.py

A comparator that reports "clean" is only evidence if it is known to say
something else when the two sides differ, so each rule has a case that must
make it speak.
"""
import contextlib
import io
import os
import sys
import tempfile
import unittest

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import entdiff  # noqa: E402

T = "http://www.w3.org/2002/07/owl#Thing"
N = "http://www.w3.org/2002/07/owl#Nothing"


def howl(body, termination="fixpoint", omitted="0", counts=True):
    """A HOWL report in report.slop's order, with the counts it would print."""
    unsat = [l for l in body[1:] if l.startswith("unsat ")]
    subs = [l for l in body[1:] if l.startswith("sub ")]
    omissions = [f"omission X{i}" for i in range(int(omitted))]
    if body[:1] == ["inconsistent true"] or unsat:
        verdict = "incoherent"
    elif termination == "fixpoint" and omitted == "0":
        verdict = "coherent"
    else:
        verdict = "inconclusive"
    lines = ["howl-report 1", f"verdict {verdict}", f"termination {termination}", "rounds 3",
             *body[:1], f"omitted {omitted}", *omissions]
    if counts:
        lines += [f"unsatisfiable {len(unsat)}", *unsat, f"subsumptions {len(subs)}", *subs]
    else:
        lines += [*unsat, *subs]
    return "\n".join(lines) + "\n"


def oracle(body):
    return "\n".join(["oracle-report 1", "reasoner hermit 1.4.5.519 owlapi 5.1.20 jvm 21", *body]) + "\n"


# A ⊑ B, both satisfiable, over the signature {A, B, ⊤}.
BASE = ["inconsistent false",
        f"sub A A", f"sub A B", f"sub A {T}",
        f"sub B B", f"sub B {T}",
        f"sub {T} {T}"]


class EntdiffTest(unittest.TestCase):
    def run_diff(self, h, o):
        with tempfile.TemporaryDirectory() as d:
            hp, op = os.path.join(d, "h.report"), os.path.join(d, "o.report")
            with open(hp, "w") as f:
                f.write(h)
            with open(op, "w") as f:
                f.write(o)
            try:
                return entdiff.compare(entdiff.parse(hp), entdiff.parse(op))
            except entdiff.Refused as e:
                return ("REFUSED", str(e))

    def assertRefused(self, result, fragment):
        self.assertIsInstance(result, tuple, f"expected a refusal, got {result!r}")
        self.assertIn(fragment, result[1])

    # -- agreement ---------------------------------------------------------

    def test_identical_is_clean(self):
        self.assertEqual(self.run_diff(howl(BASE), oracle(BASE)), {})

    def test_line_order_does_not_matter(self):
        self.assertEqual(self.run_diff(howl(BASE), oracle([BASE[0], *reversed(BASE[1:])])), {})

    def test_both_inconsistent_compares_nothing_further(self):
        self.assertEqual(self.run_diff(howl(["inconsistent true"]), oracle(["inconsistent true"])), {})

    # -- each category fires -----------------------------------------------

    def test_missing_sub(self):
        h = [l for l in BASE if l != "sub A B"]
        self.assertEqual(self.run_diff(howl(h), oracle(BASE)), {"HOWL-missing sub": ["A B"]})

    def test_extra_sub(self):
        o = [l for l in BASE if l != "sub A B"]
        self.assertEqual(self.run_diff(howl(BASE), oracle(o)), {"HOWL-extra sub": ["A B"]})

    def test_missing_unsat(self):
        o = ["inconsistent false", "unsat A", f"sub A {N}", *BASE[4:]]
        self.assertEqual(self.run_diff(howl(BASE), oracle(o)), {"HOWL-missing unsat": ["A"]})

    def test_extra_unsat(self):
        h = ["inconsistent false", "unsat A", f"sub A {N}", *BASE[4:]]
        self.assertEqual(self.run_diff(howl(h), oracle(BASE)), {"HOWL-extra unsat": ["A"]})

    def test_one_sided_unsat_is_not_expanded_into_pairs(self):
        h = ["inconsistent false", "unsat A", f"sub A {N}", *BASE[4:]]
        diff = self.run_diff(howl(h), oracle(BASE))
        self.assertNotIn("HOWL-missing sub", diff)
        self.assertNotIn("HOWL-extra sub", diff)

    def test_missing_inconsistent(self):
        self.assertEqual(self.run_diff(howl(BASE), oracle(["inconsistent true"])),
                         {"HOWL-missing inconsistent": ["inconsistent true"]})

    def test_extra_inconsistent(self):
        self.assertEqual(self.run_diff(howl(["inconsistent true"]), oracle(BASE)),
                         {"HOWL-extra inconsistent": ["inconsistent true"]})

    def test_signature_oracle_only(self):
        o = [*BASE, "sub C C", f"sub C {T}"]
        self.assertEqual(self.run_diff(howl(BASE), oracle(o)), {"SIGNATURE oracle-only": ["C"]})

    def test_signature_howl_only(self):
        h = [*BASE, "sub C C", f"sub C {T}"]
        self.assertEqual(self.run_diff(howl(h), oracle(BASE)), {"SIGNATURE HOWL-only": ["C"]})

    # -- refusals ----------------------------------------------------------

    def test_refuses_a_capped_run(self):
        self.assertRefused(self.run_diff(howl(BASE, termination="resource-limit"), oracle(BASE)),
                           "termination resource-limit")

    def test_refuses_a_run_with_omissions(self):
        self.assertRefused(self.run_diff(howl(BASE, omitted="1"), oracle(BASE)), "omitted 1")

    def test_only_an_incomplete_run_is_incomplete(self):
        # Drivers skip Incomplete and FAIL every other refusal, so a garbled
        # report must never be classed as merely incomplete.
        with tempfile.TemporaryDirectory() as d:
            cases = {"capped": howl(BASE, termination="resource-limit"),
                     "omitting": howl(BASE, omitted="2"),
                     "garbled": howl([*BASE, "sub A"])}
            for name, text in cases.items():
                path = os.path.join(d, name)
                with open(path, "w") as f:
                    f.write(text)
                with self.assertRaises(entdiff.Refused) as ctx:
                    entdiff.parse(path)
                self.assertEqual(isinstance(ctx.exception, entdiff.Incomplete), name != "garbled", name)

    def test_refuses_a_howl_report_without_termination(self):
        h = howl(BASE).replace("termination fixpoint\n", "")
        self.assertRefused(self.run_diff(h, oracle(BASE)), "termination None")

    def test_refuses_an_omission_count_that_lies(self):
        # `omitted 0` above an omission line: the count decides comparability,
        # so it is checked against the lines it counts before it is believed.
        h = howl(BASE).replace("omitted 0\n", "omitted 0\nomission SubClassOf(A B)\n")
        self.assertRefused(self.run_diff(h, oracle(BASE)), "omitted 0 but 1 omission")

    def test_refuses_a_subsumption_count_that_lies(self):
        h = howl(BASE).replace("subsumptions 6", "subsumptions 5")
        self.assertRefused(self.run_diff(h, oracle(BASE)), "subsumptions 5 but 6 sub")

    def test_refuses_a_missing_count(self):
        self.assertRefused(self.run_diff(howl(BASE, counts=False), oracle(BASE)), "no unsatisfiable line")

    def test_refuses_a_verdict_the_facts_contradict(self):
        # `coherent` over an omission is the false pass itself.
        h = howl(BASE, omitted="1").replace("verdict inconclusive", "verdict coherent")
        self.assertRefused(self.run_diff(h, oracle(BASE)), "verdict coherent but")

    def test_refuses_coherent_over_an_unsatisfiable_class(self):
        h = howl(["inconsistent false", "unsat A", f"sub A {N}", *BASE[4:]]).replace(
            "verdict incoherent", "verdict coherent")
        self.assertRefused(self.run_diff(h, oracle(BASE)), "make it incoherent")

    def test_an_incoherent_partial_run_is_still_only_incomplete(self):
        # A proven contradiction under partial coverage is INCOHERENT (§6.2),
        # and the report is still refused for diffing as incomplete.
        with tempfile.TemporaryDirectory() as d:
            path = os.path.join(d, "h")
            with open(path, "w") as f:
                f.write(howl(["inconsistent false", "unsat A", f"sub A {N}", *BASE[4:]], omitted="1"))
            with self.assertRaises(entdiff.Incomplete):
                entdiff.parse(path)

    def test_refuses_an_exit_line_that_disagrees(self):
        h = howl(BASE) + "exit 1\n"
        self.assertRefused(self.run_diff(h, oracle(BASE)), "exit 1 does not match")
        self.assertEqual(self.run_diff(howl(BASE) + "exit 0\n", oracle(BASE)), {})

    def test_refuses_a_repeated_key(self):
        h = howl(BASE).replace("omitted 0\n", "omitted 0\nomitted 0\n")
        self.assertRefused(self.run_diff(h, oracle(BASE)), "a second omitted line")

    def test_refuses_an_uncompressed_unsat(self):
        o = ["inconsistent false", "unsat A", f"sub A {N}", "sub A B", *BASE[4:]]
        self.assertRefused(self.run_diff(howl(BASE), oracle(o)), "bottom-compressed")

    def test_refuses_nothing_without_unsat(self):
        o = [*BASE, f"sub B {N}"]
        self.assertRefused(self.run_diff(howl(BASE), oracle(o)), "without `unsat B`")

    def test_refuses_a_hierarchy_under_inconsistency(self):
        self.assertRefused(self.run_diff(howl(BASE), oracle(["inconsistent true", "sub A A"])),
                           "no hierarchy")

    def test_refuses_an_unknown_key(self):
        self.assertRefused(self.run_diff(howl(BASE), oracle([*BASE, "subclass A B"])), "unknown line key")

    def test_refuses_a_malformed_sub(self):
        self.assertRefused(self.run_diff(howl(BASE), oracle([*BASE, "sub A"])), "malformed sub")

    def test_refuses_a_non_report(self):
        self.assertRefused(self.run_diff("hello\n", oracle(BASE)), "not a report")

    def test_main_refuses_swapped_arguments(self):
        with tempfile.TemporaryDirectory() as d:
            hp, op = os.path.join(d, "h"), os.path.join(d, "o")
            with open(hp, "w") as f:
                f.write(howl(BASE))
            with open(op, "w") as f:
                f.write(oracle(BASE))
            with contextlib.redirect_stdout(io.StringIO()):
                self.assertEqual(entdiff.main(["entdiff", op, hp]), 3)
                self.assertEqual(entdiff.main(["entdiff", hp, op]), 0)


if __name__ == "__main__":
    unittest.main()
