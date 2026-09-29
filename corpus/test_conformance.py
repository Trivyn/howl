"""Self-tests for corpus/conformance.py's functional-syntax reading.

    python3 -m unittest corpus/test_conformance.py

The reader decides two things a wrong answer could hide behind: whether an
expected axiom is CHECKABLE (named operands) or merely `not-expressible`, and
whether an input is `oracle-lossy` (an operand repeated where OWL 2 reads
operands pairwise, which the OWL API collapses on conversion).
"""
import os
import sys
import tempfile
import unittest

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import conformance  # noqa: E402

HEAD = "Prefix(:=<http://example.org/>)\nPrefix(rdfs:=<http://www.w3.org/2000/01/rdf-schema#>)\nOntology(\n"
A, B = "http://example.org/A", "http://example.org/B"


class FssTest(unittest.TestCase):
    def doc(self, body):
        d = tempfile.mkdtemp()
        path = os.path.join(d, "t.ofn")
        with open(path, "w") as f:
            f.write(HEAD + body + "\n)\n")
        return path

    def test_named_axiom_is_checkable(self):
        self.assertEqual(conformance.read_fss(self.doc("SubClassOf(:A :B)")), [("SubClassOf", [A, B])])

    def test_complex_axiom_is_not(self):
        self.assertEqual(conformance.read_fss(self.doc("SubClassOf(:A ObjectSomeValuesFrom(:r :B))")),
                         [("SubClassOf", None)])

    def test_an_annotated_named_axiom_is_still_checkable(self):
        # Axiom annotations are not operands; a parenthesis inside the
        # literal is not structure.
        path = self.doc('SubClassOf(Annotation(rdfs:comment "x (y)") :A :B)')
        self.assertEqual(conformance.read_fss(path), [("SubClassOf", [A, B])])

    def test_an_axiom_across_lines_is_read_whole(self):
        path = self.doc("SubClassOf(\n  :A\n  :B\n)")
        self.assertEqual(conformance.read_fss(path), [("SubClassOf", [A, B])])

    def test_comment_lines_are_not_axioms(self):
        self.assertEqual(conformance.read_fss(self.doc("# inconsistent\nSubClassOf(:A :B)")),
                         [("SubClassOf", [A, B])])

    def test_repeated_operand_is_lossy(self):
        self.assertEqual(conformance.fss_repeated_operands(self.doc("DisjointClasses(:A :B :A)")),
                         ["DisjointClasses"])

    def test_repeat_spelled_two_ways_is_lossy(self):
        path = self.doc("DisjointClasses(:A <http://example.org/A>)")
        self.assertEqual(conformance.fss_repeated_operands(path), ["DisjointClasses"])

    def test_repeat_across_lines_is_lossy(self):
        path = self.doc("DisjointClasses(\n  :A\n  :B :A)")
        self.assertEqual(conformance.fss_repeated_operands(path), ["DisjointClasses"])

    def test_disjoint_union_class_is_not_an_operand(self):
        # DisjointUnion(C A B): C is the union, not one of the disjoint parts.
        self.assertEqual(conformance.fss_repeated_operands(self.doc("DisjointUnion(:A :A :B)")), [])
        self.assertEqual(conformance.fss_repeated_operands(self.doc("DisjointUnion(:C :A :A)")),
                         ["DisjointUnion"])

    def test_repeats_elsewhere_are_harmless(self):
        # A ⊓ A = A: an intersection's repeat changes nothing.
        path = self.doc("SubClassOf(:C ObjectIntersectionOf(:A :A))\nDisjointClasses(:A :B)")
        self.assertEqual(conformance.fss_repeated_operands(path), [])


if __name__ == "__main__":
    unittest.main()
