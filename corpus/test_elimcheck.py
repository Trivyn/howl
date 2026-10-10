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
