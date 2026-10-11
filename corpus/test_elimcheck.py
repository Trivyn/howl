"""Unit tests for corpus/elimcheck.py's comparison: the restriction to the input's
class names, and that a restricted comparison still sees a difference there."""
import os
import sys
import unittest

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import elimcheck  # noqa: E402
import entdiff    # noqa: E402

T, N = elimcheck.THING, elimcheck.NOTHING


def report(subs, unsat=(), inconsistent=False):
    return entdiff.Report("oracle", inconsistent, set(unsat), {a: set(b) for a, b in subs.items()}, [])


class RestrictTest(unittest.TestCase):
    def test_keeps_only_the_input_classes(self):
        r = report({"A": {"A", "B", "urn:howl:a:0", T}, "urn:howl:a:0": {"urn:howl:a:0", T}, T: {T}},
                   unsat={"urn:howl:a:1"})
        got = elimcheck.restrict(r, {"A", "B"})
        self.assertEqual(got.subs, {"A": {"A", "B", T}, T: {T}})
        self.assertEqual(got.unsat, set())

    def test_nothing_survives_as_a_target(self):
        r = report({"A": {"A", N}}, unsat={"A"})
        got = elimcheck.restrict(r, {"A"})
        self.assertEqual(got.subs["A"], {"A", N})
        self.assertEqual(got.unsat, {"A"})

    def test_a_fresh_name_difference_is_not_a_mismatch(self):
        a = report({"A": {"A", T, "urn:howl:a:0"}, T: {T}})
        b = report({"A": {"A", T}, T: {T}})
        self.assertFalse(entdiff.compare(elimcheck.restrict(a, {"A"}), elimcheck.restrict(b, {"A"})))

    def test_an_input_class_difference_is(self):
        a = report({"A": {"A", "B", T}, "B": {"B", T}, T: {T}})
        b = report({"A": {"A", T}, "B": {"B", T}, T: {T}})
        self.assertTrue(entdiff.compare(elimcheck.restrict(b, {"A", "B"}), elimcheck.restrict(a, {"A", "B"})))


if __name__ == "__main__":
    unittest.main()


class RefLegsTest(unittest.TestCase):
    """The reference's legs, with ref_report stubbed: a mismatch between strategies or
    against HermiT fails, and n/a fails on the sriq rung's own fixtures only."""

    def setUp(self):
        self.saved = (elimcheck.ref_report, list(elimcheck.REF), elimcheck.WORK)
        elimcheck.REF[:] = list(elimcheck.STRATEGIES)
        elimcheck.WORK = os.path.join(elimcheck.ROOT, "build", "elim", "unittest")
        self.own = os.path.join(elimcheck.ROOT, "corpus", "fixtures", "sriq", "x.ttl")
        self.other = os.path.join(elimcheck.ROOT, "corpus", "fixtures", "el++", "x.ttl")
        self.good = report({"A": {"A", "B", T}, "B": {"B", T}, T: {T}})

    def tearDown(self):
        elimcheck.ref_report, elimcheck.REF[:], elimcheck.WORK = self.saved[0], self.saved[1], self.saved[2]

    def stub(self, by_strategy):
        elimcheck.ref_report = lambda path, st, out: by_strategy[st]

    def legs(self, path, oracle):
        side = {"input": (oracle, None), "s2": (oracle, None)}
        return elimcheck.ref_legs(path, "x", {"A", "B"}, side)

    def test_agreement_passes(self):
        self.stub({st: (self.good, None) for st in elimcheck.STRATEGIES})
        lines, bad = self.legs(self.own, self.good)
        self.assertEqual(bad, 0)
        self.assertEqual(sum(1 for l in lines if l.endswith(": ok")), 4)

    def test_a_strategy_that_disagrees_fails(self):
        weak = report({"A": {"A", T}, "B": {"B", T}, T: {T}})
        self.stub({"trivial": (weak, None), "eager": (self.good, None), "cautious": (self.good, None)})
        lines, bad = self.legs(self.own, self.good)
        self.assertEqual(bad, 1)
        self.assertTrue(any("ref-trivial~cautious: MISMATCH" in l for l in lines))

    def test_hermit_disagreeing_fails(self):
        self.stub({st: (self.good, None) for st in elimcheck.STRATEGIES})
        lines, bad = self.legs(self.own, report({"A": {"A", T}, "B": {"B", T}, T: {T}}))
        self.assertEqual(bad, 2)

    def test_na_fails_on_the_rungs_own_fixtures_only(self):
        na = {st: (None, "n/a: clauses") for st in elimcheck.STRATEGIES}
        self.stub(na)
        _, bad_own = self.legs(self.own, self.good)
        _, bad_other = self.legs(self.other, self.good)
        self.assertEqual(bad_own, 3)
        self.assertEqual(bad_other, 0)

    def test_own_fixture_is_the_sriq_directory(self):
        self.assertTrue(elimcheck.own_fixture(self.own))
        self.assertFalse(elimcheck.own_fixture(self.other))

    def test_no_hermit_side_fails_on_the_rungs_own_fixtures_only(self):
        self.stub({st: (self.good, None) for st in elimcheck.STRATEGIES})
        side = {"input": (None, "HermiT fault"), "s2": (self.good, None)}
        _, bad_own = elimcheck.ref_legs(self.own, "x", {"A", "B"}, side)
        _, bad_other = elimcheck.ref_legs(self.other, "x", {"A", "B"}, side)
        self.assertEqual(bad_own, 1)
        self.assertEqual(bad_other, 0)
