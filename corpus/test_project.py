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

from rdflib import Graph, URIRef

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


class ElPlusPlusTest(unittest.TestCase):
    """SPEC.md §5.4's language, as the census implements it independently:
    the same rows as src/test.slop's two-rung gate table."""
    DECL = """:r a owl:ObjectProperty . :s a owl:ObjectProperty . :t a owl:ObjectProperty .
:C a owl:Class . :D a owl:Class .
:a a owl:NamedIndividual . :b a owl:NamedIndividual .
"""
    # (label, document, out under el, out under el++)
    ROWS = [
        ("hasValue", ":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasValue :a ] .", True, False),
        ("oneOf of one", ":C owl:equivalentClass [ a owl:Class ; owl:oneOf ( :a ) ] .", True, False),
        ("hasSelf, simple role", ":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasSelf true ] .", True, False),
        ("reflexive role", ":r a owl:ReflexiveProperty .", True, False),
        ("sameAs", ":a owl:sameAs :b .", True, False),
        ("differentFrom", ":a owl:differentFrom :b .", True, False),
        ("AllDifferent", "[] a owl:AllDifferent ; owl:members ( :a :b ) .", True, False),
        ("negative assertion", "[] a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; "
                               "owl:assertionProperty :r ; owl:targetIndividual :b .", True, False),
        ("empty role", ":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty owl:bottomObjectProperty ; "
                       "owl:someValuesFrom owl:Thing ] .", True, False),
        ("inclusion into the universal role", ":r rdfs:subPropertyOf owl:topObjectProperty .", True, False),
        ("chain into the universal role", "owl:topObjectProperty owl:propertyChainAxiom ( :r :s ) .", True, False),
        ("oneOf of two", ":C owl:equivalentClass [ a owl:Class ; owl:oneOf ( :a :b ) ] .", True, True),
        ("hasSelf, transitive role", ":t a owl:TransitiveProperty . :C rdfs:subClassOf "
                                     "[ a owl:Restriction ; owl:onProperty :t ; owl:hasSelf true ] .", True, True),
        ("hasSelf, role above a transitive one", ":t a owl:TransitiveProperty . :t rdfs:subPropertyOf :s . "
                                                 ":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :s ; owl:hasSelf true ] .", True, True),
        ("hasSelf, role above a chain", ":s owl:propertyChainAxiom ( :r :r ) . :C rdfs:subClassOf "
                                        "[ a owl:Restriction ; owl:onProperty :s ; owl:hasSelf true ] .", True, True),
        ("universal role in a restriction", ":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty owl:topObjectProperty ; "
                                            "owl:someValuesFrom :D ] .", True, True),
        ("universal role below another", "owl:topObjectProperty rdfs:subPropertyOf :r .", True, True),
        ("oneOf of a reserved IRI", ":C rdfs:subClassOf [ a owl:Class ; owl:oneOf ( owl:Thing ) ] .", True, True),
        ("hasValue on a reserved IRI", ":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasValue owl:Thing ] .", True, True),
        ("AllDifferent with a reserved IRI", "[] a owl:AllDifferent ; owl:members ( :a owl:Thing ) .", True, True),
        ("sameAs an XSD IRI", "@prefix xsd: <http://www.w3.org/2001/XMLSchema#> . :a owl:sameAs xsd:string .", True, True),
        ("universal role into itself", "owl:topObjectProperty rdfs:subPropertyOf owl:topObjectProperty .", True, False),
        ("functional role", ":r a owl:FunctionalProperty .", True, True),
        ("hasValue, anonymous", ":C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasValue [] ] .", True, True),
        ("sameAs, anonymous", ":a owl:sameAs [] .", True, True),
        ("universal role as a chain step", ":s owl:propertyChainAxiom ( :r owl:topObjectProperty ) .", True, True),
        ("empty role as a chain step", ":s owl:propertyChainAxiom ( :r owl:bottomObjectProperty ) .", True, False),
        ("negative data assertion", ":d a owl:DatatypeProperty . [] a owl:NegativePropertyAssertion ; "
                                    "owl:sourceIndividual :a ; owl:assertionProperty :d ; owl:targetValue \"x\" .", True, True),
    ]

    def out(self, text, profile):
        _, _, out, _, _ = census.census(None, graph=graph(self.DECL + text), profile=profile)
        return sum(out.values()) > 0

    def test_each_construct_under_both_rungs(self):
        for label, text, el_out, elpp_out in self.ROWS:
            with self.subTest(label):
                self.assertEqual(self.out(text, "el"), el_out, "el")
                self.assertEqual(self.out(text, "el++"), elpp_out, "el++")

    def test_unknown_profile_is_refused(self):
        with self.assertRaises(ValueError):
            census.signature(graph(""), "sroiq")


class SriqTest(unittest.TestCase):
    """SPEC.md §5.5's language, as the census implements it independently: the
    rows of src/test.slop's three-rung gate table, as out-or-not per rung.
    The two regularity rows are HOWL's alone: the census has no regularity
    check (as for el), and conformance flags such a refusal by a missing
    census-clean."""
    DECL = ElPlusPlusTest.DECL
    # (label, document, out under el, out under el++, out under sriq)
    ROWS = [
        ('plain EL stays in every rung',
         ':C rdfs:subClassOf :D .', False, False, False),
        ('InverseObjectProperties',
         ':r owl:inverseOf :s .', True, True, False),
        ('a restriction on an inverse',
         ':C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty [ owl:inverseOf :r ] ; owl:someValuesFrom :D ] .', True, True, False),
        ('ObjectAllValuesFrom',
         ':C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:allValuesFrom :D ] .', True, True, False),
        ('ObjectUnionOf with a complement',
         ':C rdfs:subClassOf [ owl:unionOf ( :D [ owl:complementOf :D ] ) ] .', True, True, False),
        ('a complement on the left',
         '[ owl:complementOf :C ] rdfs:subClassOf :D .', True, True, False),
        ('a qualified cardinality, n = 16',
         ':C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:maxQualifiedCardinality 16 ; owl:onClass :D ] .', True, True, False),
        ('a qualified cardinality, n = 17',
         ':C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:maxQualifiedCardinality 17 ; owl:onClass :D ] .', True, True, True),
        ('an unqualified exact cardinality',
         ':C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:cardinality 2 ] .', True, True, False),
        ('a cardinality on a transitive role',
         ':r a owl:TransitiveProperty .\n  :C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:maxCardinality 1 ] .', True, True, True),
        ('a cardinality on the inverse of a transitive role',
         ':r a owl:TransitiveProperty .\n  :C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty [ owl:inverseOf :r ] ; owl:maxCardinality 1 ] .', True, True, True),
        ('FunctionalObjectProperty',
         ':r a owl:FunctionalProperty .', True, True, False),
        ('a functional transitive role',
         ':r a owl:TransitiveProperty , owl:FunctionalProperty .', True, True, True),
        ('InverseFunctionalObjectProperty',
         ':r a owl:InverseFunctionalProperty .', True, True, False),
        ('irreflexive and asymmetric',
         ':r a owl:IrreflexiveProperty , owl:AsymmetricProperty .', True, True, False),
        ('Self on a simple role',
         ':C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasSelf true ] .', True, False, False),
        ('Self on a transitive role',
         ':r a owl:TransitiveProperty .\n  :C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasSelf true ] .', True, True, True),
        ('symmetric and transitive: (R5) and (R4)',
         ':r a owl:SymmetricProperty , owl:TransitiveProperty .', True, True, False),
        ("RO's part_of/has_part: regular only after the collapse",
         ':r a owl:TransitiveProperty . :s a owl:TransitiveProperty . :r owl:inverseOf :s .', True, True, False),
        ('P and P- in one component',
         ':r owl:inverseOf :r . :r a owl:TransitiveProperty .', True, True, False),
        ('DisjointObjectProperties',
         ':r owl:propertyDisjointWith :s .', True, True, False),
        ('DisjointObjectProperties on a transitive role',
         ':r a owl:TransitiveProperty . :r owl:propertyDisjointWith :s .', True, True, True),
        ('DisjointUnion',
         ':C owl:disjointUnionOf ( :D [ owl:complementOf :D ] ) .', True, True, False),
        ('the top role as a super-role is a tautology',
         ':r rdfs:subPropertyOf owl:topObjectProperty .', True, False, False),
        ('an inverse into the top role is a tautology under sriq',
         '[ owl:inverseOf :r ] rdfs:subPropertyOf owl:topObjectProperty .', True, True, False),
        ('the top role elsewhere',
         ':C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty owl:topObjectProperty ; owl:someValuesFrom :D ] .', True, True, True),
        ('the bottom role',
         ':C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty owl:bottomObjectProperty ; owl:someValuesFrom :D ] .', True, False, False),
        ('a cardinality on the bottom role',
         ':C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty owl:bottomObjectProperty ; owl:maxCardinality 1 ] .', True, True, True),
        ('ObjectHasValue: a class nominal',
         ':C rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :r ; owl:hasValue :a ] .', True, False, True),
        ('ObjectOneOf: a class nominal',
         ':C rdfs:subClassOf [ owl:oneOf ( :a ) ] .', True, False, True),
        ('an anonymous individual',
         '_:x :r :a .', True, True, True),
        ('SameIndividual and DifferentIndividuals',
         ':a owl:sameAs :b . :a owl:differentFrom :b .', True, False, False),
        ('a negative object assertion',
         '[ a owl:NegativePropertyAssertion ; owl:sourceIndividual :a ; owl:assertionProperty :r ; owl:targetIndividual :b ] .', True, False, False),
        ('a class assertion with a union',
         ':a a [ owl:unionOf ( :C :D ) ] .', True, True, False),
        ('no range condition under sriq',
         ':s rdfs:range :C . :t rdfs:range :D .\n  :t owl:propertyChainAxiom ( :r :s ) .', True, True, False),
        ('used data stays out',
         ':d a owl:DatatypeProperty . :a :d 1 .', True, True, True),
    ]

    def out(self, text, profile):
        _, _, out, _, _ = census.census(None, graph=graph(self.DECL + text), profile=profile)
        return sum(out.values()) > 0

    def test_no_chain_is_inadmissible_under_sriq(self):
        # project.py asks inadmissible_chains directly, so sriq's answer
        # must not depend on going through signature(): a chain el would
        # omit for its range must stay in a sriq projection.
        g = graph(self.DECL + ":s rdfs:range :C . :t rdfs:range :D .\n:t owl:propertyChainAxiom ( :r :s ) .")
        self.assertNotEqual(census.inadmissible_chains(g, census.signature(g, "el")), {})
        self.assertEqual(census.inadmissible_chains(g, census.signature(g, "sriq")), {})

    def test_each_construct_under_three_rungs(self):
        for label, text, el_out, elpp_out, sriq_out in self.ROWS:
            with self.subTest(label):
                self.assertEqual(self.out(text, "el"), el_out, "el")
                self.assertEqual(self.out(text, "el++"), elpp_out, "el++")
                self.assertEqual(self.out(text, "sriq"), sriq_out, "sriq")


class DataLemmaTest(unittest.TestCase):
    """SPEC.md §5.2's data lemma, as the census implements it independently.

    Each row is the number of OUT-OF-PROFILE triples in both rungs; a set-aside
    axiom is INERT. These mirror test.slop's test-data-lemma, which counts
    HOWL's omissions: the two implementations must agree.
    """
    HEAD_X = "@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .\n:C a owl:Class . :a a owl:NamedIndividual .\n"
    ROWS = [
        ("idle: domain, range, functionality",
         ":d a owl:DatatypeProperty , owl:FunctionalProperty ; rdfs:domain :C ; rdfs:range xsd:integer .", 0),
        ("idle: sub-property, equivalence, disjointness",
         ":d a owl:DatatypeProperty . :e a owl:DatatypeProperty . :f a owl:DatatypeProperty .\n"
         ":d rdfs:subPropertyOf :e ; owl:equivalentProperty :f . :e owl:propertyDisjointWith :f .", 0),
        ("used in an assertion",
         ":d a owl:DatatypeProperty ; rdfs:domain :C . :a :d 1 .", 2),
        ("used below: the super-property is not idle",
         ":p a owl:DatatypeProperty ; rdfs:domain :C .\n"
         ":q a owl:DatatypeProperty ; rdfs:subPropertyOf :p . :a :q 1 .", 3),
        ("disjointness: an idle member suffices, two used ones do not",
         ":u a owl:DatatypeProperty . :v a owl:DatatypeProperty . :i a owl:DatatypeProperty .\n"
         ":u owl:propertyDisjointWith :i . :u owl:propertyDisjointWith :v . :a :u 1 ; :v 2 .", 3),
        ("a DatatypeRestriction range goes with its axiom",
         ":d a owl:DatatypeProperty ; rdfs:range [ a rdfs:Datatype ; owl:onDatatype xsd:short ;\n"
         "  owl:withRestrictions ( [ xsd:minInclusive 0 ] ) ] .", 0),
        ("a sub-property of owl:topDataProperty is a tautology",
         ":d a owl:DatatypeProperty ; rdfs:subPropertyOf owl:topDataProperty .", 0),
        ("a domain on owl:topDataProperty stays",
         "owl:topDataProperty rdfs:domain :C .", 1),
        ("a declared owl:topDataProperty is still never idle",
         "owl:topDataProperty a owl:DatatypeProperty ; rdfs:domain :C .", 1),
        ("a disjointness with owl:topDataProperty stays",
         ":d a owl:DatatypeProperty ; owl:propertyDisjointWith owl:topDataProperty .", 1),
        ("an axiom annotation is not a use (RO annotates RO_0002029's range)",
         ":d a owl:DatatypeProperty ; rdfs:range xsd:integer .\n"
         "[ a owl:Axiom ; owl:annotatedSource :d ; owl:annotatedProperty rdfs:range ;\n"
         "  owl:annotatedTarget xsd:integer ; rdfs:comment \"why\" ] .", 0),
        ("a filler shared with its own reification still goes with its axiom",
         ":d a owl:DatatypeProperty ; rdfs:range _:x .\n"
         "_:x a rdfs:Datatype ; owl:onDatatype xsd:short ; owl:withRestrictions ( [ xsd:minInclusive 0 ] ) .\n"
         "[ a owl:Axiom ; owl:annotatedSource :d ; owl:annotatedProperty rdfs:range ;\n"
         "  owl:annotatedTarget _:x ; rdfs:comment \"why\" ] .", 0),
        ("owl:withRestrictions without owl:onDatatype is not swallowed",
         ":d a owl:DatatypeProperty ; rdfs:domain _:x .\n"
         "_:x a owl:Class ; owl:withRestrictions ( [ xsd:minInclusive 0 ] ) .", 2),
        ("a facet node with a second triple is not swallowed",
         ":d a owl:DatatypeProperty ; rdfs:range [ a rdfs:Datatype ; owl:onDatatype xsd:short ;\n"
         "  owl:withRestrictions ( [ xsd:minInclusive 0 ; owl:someValuesFrom :C ] ) ] .", 1),
        ("a reified-only declaration declares: stage 0 rebuilds it",
         "[ a owl:Axiom ; owl:annotatedSource :d ; owl:annotatedProperty rdf:type ;\n"
         "  owl:annotatedTarget owl:DatatypeProperty ] .\n:d rdfs:range xsd:integer .", 0),
    ]

    def out(self, text, profile):
        _, _, out, _, _ = census.census(None, graph=graph(self.HEAD_X + text), profile=profile)
        return sum(out.values())

    def test_each_row_under_both_rungs(self):
        for label, text, want in self.ROWS:
            with self.subTest(label):
                self.assertEqual(self.out(text, "el"), want, "el")
                self.assertEqual(self.out(text, "el++"), want, "el++")

    def test_a_filler_that_heads_an_axiom_keeps_it(self):
        # Consuming the filler whole dropped the GCI, and with it D's
        # unsatisfiability, with no out-of-profile triple to show for it.
        g = graph(self.HEAD_X + ":D a owl:Class .\n:d a owl:DatatypeProperty ; rdfs:domain _:x .\n"
                  "_:x owl:intersectionOf ( :C :D ) ; rdfs:subClassOf owl:Nothing .")
        sig = census.signature(g)
        self.assertEqual(sig["data_tree"], set())
        _, in_v0, _, _, _ = census.census(None, graph=g)
        self.assertIn("SubClassOf", in_v0)

    def test_a_reified_only_assertion_is_a_use(self):
        # HOWL rebuilds `:a :d "x"` before its lemma, so :d is not idle.
        g = graph(self.HEAD_X + ':d a owl:DatatypeProperty ; rdfs:domain :C .\n'
                  '[ a owl:Axiom ; owl:annotatedSource :a ; owl:annotatedProperty :d ; owl:annotatedTarget "x" ] .')
        self.assertNotIn(URIRef("http://example.org/t#d"), census.signature(g)["data_idle"])

    def test_an_ambiguous_reification_rebuilds_nothing(self):
        # HOWL faults the document (two sources), so nothing is rebuilt.
        g = graph(self.HEAD_X + "[ a owl:Axiom ; owl:annotatedSource :d , :e ;\n"
                  "  owl:annotatedProperty rdfs:range ; owl:annotatedTarget :C ] .")
        self.assertEqual(set(census.decoder_triples(g)) - set(g), set())

    def test_a_shared_filler_is_not_set_aside(self):
        # The range's blank node is also a class assertion's object, so it is
        # referenced twice and decoded as written: only the range is inert.
        g = graph(self.HEAD_X + ":d a owl:DatatypeProperty ; rdfs:range _:x .\n_:x a rdfs:Datatype .\n:b :r _:x .")
        sig = census.signature(g)
        self.assertEqual(sig["data_tree"], set())


if __name__ == "__main__":
    unittest.main()
