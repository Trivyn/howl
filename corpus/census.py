#!/usr/bin/env python3
"""Construct census against HOWL's v0 language (SPEC.md §5.2).

Classifies every triple as in-v0 / inert / consumed / OUT-OF-PROFILE. The
out-of-profile set is the one that matters: an entry with any out-of-profile
logical axiom cannot be used for differential or benchmark comparison without a
pinned projection (§10 item 2), because `coverage.omitted` would be non-empty.

`classify_triple` is the SINGLE definition of the disposition table, shared with
project.py. Two implementations would let a projection disagree with the census
that certified it, and the disagreement would be silent.

Deliberately an INDEPENDENT implementation, not a wrapper over HOWL's own gate:
if the projection guaranteeing "empty coverage.omitted" were produced by the very
gate under test, the acceptance criterion would be self-certifying.
"""
import sys
from collections import Counter
from rdflib import Graph, RDF, RDFS, OWL, BNode, URIRef, Literal, Namespace

SWRL = Namespace("http://www.w3.org/2003/11/swrl#")

IN_V0_PRED = {
    RDFS.subClassOf: "SubClassOf",
    OWL.equivalentClass: "EquivalentClasses",
    OWL.disjointWith: "DisjointClasses",
    RDFS.subPropertyOf: "SubObjectPropertyOf",
    OWL.propertyChainAxiom: "ObjectPropertyChain",
    OWL.equivalentProperty: "EquivalentObjectProperties",
    RDFS.domain: "ObjectPropertyDomain",
    RDFS.range: "ObjectPropertyRange",
}
IN_V0_EXPR = {
    OWL.intersectionOf: "ObjectIntersectionOf",
    OWL.someValuesFrom: "ObjectSomeValuesFrom",
}
OUT_PRED = {
    OWL.unionOf: "ObjectUnionOf",
    OWL.complementOf: "ObjectComplementOf",
    OWL.allValuesFrom: "ObjectAllValuesFrom",
    OWL.oneOf: "ObjectOneOf (nominals)",
    OWL.hasValue: "ObjectHasValue",
    OWL.hasSelf: "ObjectHasSelf",
    OWL.minCardinality: "cardinality",
    OWL.maxCardinality: "cardinality",
    OWL.cardinality: "cardinality",
    OWL.minQualifiedCardinality: "qualified cardinality",
    OWL.maxQualifiedCardinality: "qualified cardinality",
    OWL.qualifiedCardinality: "qualified cardinality",
    OWL.inverseOf: "InverseObjectProperties",
    OWL.sameAs: "SameIndividual",
    OWL.differentFrom: "DifferentIndividuals",
    OWL.disjointUnionOf: "DisjointUnion",
    OWL.hasKey: "HasKey",
    OWL.propertyDisjointWith: "DisjointObjectProperties",
    OWL.withRestrictions: "DatatypeDefinition",
    OWL.onDatatype: "DatatypeDefinition",
}
OUT_TYPE = {
    OWL.FunctionalProperty: "FunctionalObjectProperty",
    OWL.InverseFunctionalProperty: "InverseFunctionalObjectProperty",
    OWL.SymmetricProperty: "SymmetricObjectProperty",
    OWL.AsymmetricProperty: "AsymmetricObjectProperty",
    OWL.IrreflexiveProperty: "IrreflexiveObjectProperty",
    OWL.ReflexiveProperty: "ReflexiveObjectProperty",
    OWL.AllDifferent: "AllDifferent",
    OWL.NegativePropertyAssertion: "NegativeObjectPropertyAssertion",
    OWL.AllDisjointProperties: "DisjointObjectProperties",
}
# RDF-surface vocabulary the abstract grammar already covers. Failing to decode
# these drops axioms an accepted ontology depends on (SPEC.md §5.2).
IN_V0_TYPE = {
    OWL.TransitiveProperty: "TransitiveObjectProperty (-> r o r subseteq r)",
}
DECL_TYPES = {
    OWL.Class, OWL.ObjectProperty, OWL.NamedIndividual, OWL.AnnotationProperty,
    OWL.DatatypeProperty, RDFS.Datatype, OWL.Ontology, OWL.Restriction,
    OWL.AllDisjointClasses, OWL.Axiom, RDF.List,
}
HEADER_PRED = {
    OWL.imports, OWL.versionIRI, OWL.priorVersion, OWL.versionInfo,
    OWL.annotatedSource, OWL.annotatedProperty, OWL.annotatedTarget,
    RDF.first, RDF.rest, OWL.onProperty, OWL.members, OWL.distinctMembers,
    OWL.onClass,
}
# Built-in role semantics CR1-CR7 do not implement. Treated as ordinary roles,
# CR3 builds an edge for `A subseteq EXISTS bottomObjectProperty.top` and A is
# reported SATISFIABLE -- a missed unsatisfiability, i.e. a false pass.
BUILTIN_ROLES = {OWL.topObjectProperty, OWL.bottomObjectProperty}

OUT, IN, INERT, CONSUMED = "out", "in_v0", "inert", "consumed"


def signature(g):
    """Declared entity sets, needed to disposition a triple in context."""
    return {
        "ann":     set(g.subjects(RDF.type, OWL.AnnotationProperty)),
        "data":    set(g.subjects(RDF.type, OWL.DatatypeProperty)),
        "obj":     set(g.subjects(RDF.type, OWL.ObjectProperty)),
        "classes": set(g.subjects(RDF.type, OWL.Class)),
    }


def classify_triple(sig, s, p, o):
    """(bucket, construct) for one triple. THE disposition table, in code."""
    # Built-in roles first: they appear as the OBJECT of owl:onProperty, so a
    # predicate scan would never see them.
    if p == OWL.onProperty and o in BUILTIN_ROLES:
        return OUT, "built-in role (top/bottomObjectProperty)"
    if p in (RDFS.subPropertyOf, OWL.equivalentProperty) and (
            s in BUILTIN_ROLES or o in BUILTIN_ROLES):
        return OUT, "built-in role (top/bottomObjectProperty)"

    # HEADER / REIFICATION BEFORE THE LITERAL TEST. Load-bearing, not stylistic:
    # owl:annotatedTarget usually carries a Literal, so a literal check placed
    # first buckets 350 axiom annotations in RO as "datatype in a logical
    # position" -- reporting a well-formed annotated ontology as one third
    # out-of-profile. That is exactly M0 acceptance (a), and this tool got it
    # wrong on its first run.
    if p in HEADER_PRED:
        return CONSUMED, "declaration / header"
    if p == OWL.deprecated:
        return INERT, "annotation assertion"

    if p == RDF.type:
        if str(o).startswith(str(SWRL)):
            # SWRL: not OWL, undecidable unrestricted, and present in RO (25
            # rules, 2 of which derive owl:Nothing). Out-of-profile and
            # ENUMERATED -- inert would let an encoded incoherence read as
            # coherent (SPEC.md §5.2).
            return OUT, "SWRL rule"
        if o in DECL_TYPES:
            return CONSUMED, "declaration / header"
        if o in OUT_TYPE:
            return OUT, OUT_TYPE[o]
        if o in IN_V0_TYPE:
            return IN, IN_V0_TYPE[o]
        if o in sig["classes"] or isinstance(o, URIRef):
            if isinstance(s, BNode):
                return OUT, "anonymous individual"
            return IN, "ClassAssertion"
        return INERT, "other / unrecognized"

    if p in sig["ann"] or p in (RDFS.label, RDFS.comment, RDFS.seeAlso,
                               RDFS.isDefinedBy):
        return INERT, "annotation assertion"
    if p in OUT_PRED:
        return OUT, OUT_PRED[p]
    if p in sig["data"] or isinstance(o, Literal):
        return OUT, "datatype / literal in logical position"
    if p in IN_V0_EXPR:
        return IN, IN_V0_EXPR[p]
    if p in IN_V0_PRED:
        if p in (RDFS.domain, RDFS.range) and s in sig["data"]:
            return OUT, "DataPropertyDomain/Range"
        return IN, IN_V0_PRED[p]
    if p in sig["obj"]:
        if isinstance(s, BNode) or isinstance(o, BNode):
            return OUT, "anonymous individual"
        return IN, "ObjectPropertyAssertion"
    return INERT, "other / unrecognized"


def out_of_profile_seeds(g, sig=None):
    """Triples that put an axiom outside v0. The projector's input."""
    sig = sig or signature(g)
    for s, p, o in g:
        bucket, construct = classify_triple(sig, s, p, o)
        if bucket == OUT:
            yield (s, p, o), construct


def census(path, fmt=None, graph=None):
    g = graph if graph is not None else Graph()
    if graph is None:
        g.parse(path, format=fmt)
    sig = signature(g)
    buckets = {IN: Counter(), OUT: Counter(), INERT: Counter(), CONSUMED: Counter()}
    for s, p, o in g:
        bucket, construct = classify_triple(sig, s, p, o)
        buckets[bucket][construct] += 1
    return g, buckets[IN], buckets[OUT], buckets[INERT], buckets[CONSUMED]


def report(path, fmt=None):
    g, in_v0, out, inert, consumed = census(path, fmt)
    total = sum(in_v0.values()) + sum(out.values())
    print(f"\n{'='*72}\n{path}\n{'='*72}")
    print(f"  triples: {len(g):,}   logical axioms (approx): {total:,}")
    print(f"\n  IN v0            {sum(in_v0.values()):>8,}")
    for k, v in in_v0.most_common():
        print(f"      {k:<52}{v:>8,}")
    print(f"\n  OUT-OF-PROFILE   {sum(out.values()):>8,}", end="")
    if out:
        print(f"   ({100.0*sum(out.values())/max(total,1):.1f}% of logical axioms)")
        for k, v in out.most_common():
            print(f"      {k:<52}{v:>8,}")
    else:
        print("   <- CLEAN, usable without projection")
    print(f"\n  inert            {sum(inert.values()):>8,}")
    print(f"  consumed         {sum(consumed.values()):>8,}")
    return sum(out.values()), total


if __name__ == "__main__":
    results = []
    for p in sys.argv[1:]:
        try:
            results.append((p, *report(p)))
        except Exception as e:
            print(f"\n!! {p}: {type(e).__name__}: {e}")
    if len(results) > 1:
        print(f"\n{'='*72}\nSUMMARY — v0 fitness\n{'='*72}")
        for p, o, t in results:
            print(f"  {p.split('/')[-1]:<44}"
                  f"{'CLEAN' if o == 0 else f'needs projection ({o:,} axioms)'}")
