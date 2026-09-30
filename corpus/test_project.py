"""Self-tests for corpus/project.py and the census rules it projects by.

    python3 -m unittest corpus/test_project.py

Each case is a way a projection could silently differ from the theory it
claims to be: a blank-node change the content pins do not see, a removed
axiom that survives as its reification, a chain removed for a range the
projection itself deletes, a malformed chain counted as in profile.
"""
import hashlib
import os
import sys
import tempfile
import unittest

from rdflib import Graph

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import census   # noqa: E402
import project  # noqa: E402

HEAD = """@prefix :     <http://example.org/t#> .
@prefix owl:  <http://www.w3.org/2002/07/owl#> .
@prefix rdf:  <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
<http://example.org/t> a owl:Ontology .
"""


def graph(text):
    g = Graph()
    g.parse(data=HEAD + text, format="turtle")
    return g


def run_project(text):
    """project() on a temporary source; returns its result record."""
    d = tempfile.mkdtemp()
    path = os.path.join(d, "t.ttl")
    with open(path, "w") as f:
        f.write(HEAD + text)
    with open(path, "rb") as f:
        sha = hashlib.sha256(f.read()).hexdigest()
    return project.project("t", "0", path, sha)


RESTRICTION = """:A a owl:Class . :B a owl:Class . :r a owl:ObjectProperty . :s a owl:ObjectProperty .
:A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:someValuesFrom :B ] .
"""


class BnodeDigestTest(unittest.TestCase):
    def test_label_free(self):
        # Two parses label blank nodes differently; the digest must not care.
        self.assertEqual(project.bnode_digest(list(graph(RESTRICTION))),
                         project.bnode_digest(list(graph(RESTRICTION))))

    def test_sees_a_rewired_restriction(self):
        # Same ground triples, same triple count — only the structure moved.
        rewired = RESTRICTION.replace("owl:onProperty :r", "owl:onProperty :s")
        a, b = list(graph(RESTRICTION)), list(graph(rewired))
        self.assertEqual(project.ground_digest(a), project.ground_digest(b))
        self.assertNotEqual(project.bnode_digest(a), project.bnode_digest(b))


class ReificationTest(unittest.TestCase):
    CHAIN = """:r a owl:ObjectProperty . :s a owl:ObjectProperty . :t a owl:ObjectProperty .
:C a owl:Class . :D a owl:Class .
:t rdfs:range :C . :s rdfs:range :D .
:t owl:propertyChainAxiom ( :r :s ) .
"""

    def test_reified_copy_with_extra_annotation_goes_with_its_axiom(self):
        # The chain breaks §5.2 (range C on t, not on s) and is removed. Its
        # reified copy carries an extra comment on the list head, so it is
        # not structurally equal to the removed list — and must go anyway,
        # since it matches no SURVIVING axiom.
        text = self.CHAIN + """[] a owl:Axiom ; owl:annotatedSource :t ;
    owl:annotatedProperty owl:propertyChainAxiom ;
    owl:annotatedTarget [ rdf:first :r ; rdf:rest ( :s ) ; rdfs:comment "note" ] ;
    rdfs:comment "reified" .
"""
        r = run_project(text)
        kept = Graph()
        for t in r["projected"]:
            kept.add(t)
        from rdflib import OWL, RDF
        self.assertEqual(list(kept.subjects(RDF.type, OWL.Axiom)), [])
        self.assertEqual(list(kept.triples((None, OWL.propertyChainAxiom, None))), [])
        self.assertEqual(r["axioms"], 1)  # one removed axiom, reification included

    def test_reification_of_a_surviving_axiom_stays(self):
        text = """:A a owl:Class . :B a owl:Class .
:A rdfs:subClassOf :B .
[] a owl:Axiom ; owl:annotatedSource :A ; owl:annotatedProperty rdfs:subClassOf ;
   owl:annotatedTarget :B ; rdfs:comment "kept" .
"""
        from rdflib import OWL, RDF
        r = run_project(text)
        kept = Graph()
        for t in r["projected"]:
            kept.add(t)
        self.assertEqual(len(list(kept.subjects(RDF.type, OWL.Axiom))), 1)
        self.assertEqual(r["axioms"], 0)


class ChainTest(unittest.TestCase):
    def test_chain_judged_after_other_removals(self):
        # t's only range the chain's last role lacks is a UNION, which is out
        # of profile and removed with its range triple. In the projected
        # theory the chain is admissible, so it must NOT be removed.
        text = """:r a owl:ObjectProperty . :s a owl:ObjectProperty . :t a owl:ObjectProperty .
:C a owl:Class . :D a owl:Class .
:t rdfs:range [ a owl:Class ; owl:unionOf ( :C :D ) ] .
:t owl:propertyChainAxiom ( :r :s ) .
"""
        from rdflib import OWL
        r = run_project(text)
        chains = [t for t in r["projected"] if t[1] == OWL.propertyChainAxiom]
        self.assertEqual(len(chains), 1)

    def test_one_step_chain_is_out_of_profile(self):
        g = graph(""":r a owl:ObjectProperty . :t a owl:ObjectProperty .
:t owl:propertyChainAxiom ( :r ) .
""")
        _, _, out, _, _ = census.census(None, graph=g)
        self.assertIn("ObjectPropertyChain (malformed: fewer than two named roles)", out)

    def test_inadmissible_chain_is_out_of_profile(self):
        g = graph(ReificationTest.CHAIN)
        _, _, out, _, _ = census.census(None, graph=g)
        self.assertIn("ObjectPropertyChain (range/composition condition)", out)

    def test_inherited_range_on_the_last_role_is_admissible(self):
        # §5.2 quantifies BOTH sides over the told hierarchy: s ⊑ u, range(u)=C.
        g = graph(""":r a owl:ObjectProperty . :s a owl:ObjectProperty . :t a owl:ObjectProperty .
:u a owl:ObjectProperty . :C a owl:Class .
:t rdfs:range :C . :s rdfs:subPropertyOf :u . :u rdfs:range :C .
:t owl:propertyChainAxiom ( :r :s ) .
""")
        self.assertEqual(census.inadmissible_chains(g), {})


class NegationTest(unittest.TestCase):
    """SPEC.md §5.2's negation rewrite, as the census implements it."""
    DECL = """:r a owl:ObjectProperty . :s a owl:ObjectProperty . :t a owl:ObjectProperty .
:A a owl:Class . :B a owl:Class . :C a owl:Class . :X a owl:Class .
"""

    def out_of(self, text):
        _, _, out, _, _ = census.census(None, graph=graph(self.DECL + text))
        return out

    def test_positive_positions_are_in(self):
        for text in (":A rdfs:subClassOf [ owl:complementOf :B ] .",
                     ":A rdfs:subClassOf [ owl:intersectionOf ( :C [ owl:complementOf :B ] ) ] .",
                     ":r rdfs:domain [ owl:intersectionOf ( :C [ owl:complementOf :B ] ) ] .",
                     ":r rdfs:range [ owl:complementOf [ a owl:Restriction ; owl:onProperty :s ; owl:someValuesFrom :B ] ] ."):
            self.assertEqual(sum(self.out_of(text).values()), 0, text)

    def test_other_positions_are_out(self):
        for text in ("[ owl:complementOf :B ] rdfs:subClassOf :A .",
                     ":A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:someValuesFrom [ owl:complementOf :B ] ] .",
                     ":A rdfs:subClassOf [ owl:unionOf ( :C [ owl:complementOf :B ] ) ] .",
                     ":A owl:equivalentClass [ owl:complementOf :B ] .",
                     # one blank node, referenced from a positive AND a negative position
                     "_:n owl:complementOf :B . :A rdfs:subClassOf _:n . _:n rdfs:subClassOf :C .",
                     "_:m owl:intersectionOf ( :C [ owl:complementOf :B ] ) . :A rdfs:subClassOf _:m . _:m rdfs:subClassOf :X ."):
            self.assertIn("ObjectComplementOf", self.out_of(text), text)

    def chains(self, ranges):
        return census.inadmissible_chains(graph(self.DECL + ":t owl:propertyChainAxiom ( :r :s ) .\n" + ranges))

    def test_a_negative_range_imposes_nothing(self):
        self.assertEqual(self.chains(":t rdfs:range [ owl:complementOf :B ] ."), {})

    def test_the_positive_part_is_still_imposed(self):
        both = ":t rdfs:range [ owl:intersectionOf ( :C [ owl:complementOf :B ] ) ] ."
        self.assertEqual(self.chains(both + " :s rdfs:range :C ."), {})
        self.assertEqual(len(self.chains(both)), 1)

    def test_several_positive_conjuncts_match_a_written_conjunction(self):
        self.assertEqual(self.chains(
            ":t rdfs:range [ owl:intersectionOf ( :C :X [ owl:complementOf :B ] ) ] ."
            " :s rdfs:range [ a owl:Class ; owl:intersectionOf ( :C :X ) ] ."), {})

    def test_a_restriction_keys_the_same_with_or_without_its_type(self):
        # HOWL decodes both spellings to one concept, so the chain is admissible.
        self.assertEqual(self.chains(
            ":t rdfs:range [ owl:intersectionOf ( [ a owl:Restriction ; owl:onProperty :r ; owl:someValuesFrom :A ]"
            " [ owl:complementOf :B ] ) ] ."
            " :s rdfs:range [ owl:onProperty :r ; owl:someValuesFrom :A ] ."), {})

    def test_an_unrewritable_range_imposes_its_whole_filler(self):
        self.assertEqual(len(self.chains(
            ":t rdfs:range [ owl:intersectionOf ( :C [ owl:complementOf [ owl:unionOf ( :A :B ) ] ] ) ] ."
            " :s rdfs:range :C .")), 1)


if __name__ == "__main__":
    unittest.main()
