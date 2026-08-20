#!/usr/bin/env python3
"""Construct census against HOWL's v0 language (SPEC.md §5.2).

Reports, per ontology, how every recognized OWL construct is disposed of:
in-v0 / inert / consumed / OUT-OF-PROFILE. The out-of-profile column is the
one that matters — an entry with any out-of-profile logical axiom cannot be
used for differential or benchmark comparison without a pinned projection
(§10 item 2), because `coverage.omitted` would be non-empty.

Deliberately an INDEPENDENT implementation of the disposition table. It must
not become a wrapper over HOWL's own gate: if the projection that guarantees
"empty coverage.omitted" is produced by the very gate under test, the
acceptance criterion is self-certifying and checks nothing.
"""
import sys
from collections import Counter
from rdflib import Graph, RDF, RDFS, OWL, BNode, URIRef, Literal, Namespace

SWRL = Namespace("http://www.w3.org/2003/11/swrl#")

# ---- §5.2 disposition table, by RDF surface vocabulary --------------------

# Predicates that carry v0 logical content.
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

# Class-expression vocabulary inside v0.
IN_V0_EXPR = {
    OWL.intersectionOf: "ObjectIntersectionOf",
    OWL.someValuesFrom: "ObjectSomeValuesFrom",
}

# Everything the gate must enumerate as out-of-profile.
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

# rdf:type objects that are out-of-profile property characteristics.
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

# Desugars to v0 content — easy to miss, since the abstract grammar covers it
# but the RDF surface spells it differently (§5.2).
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
    OWL.onClass, OWL.intersectionOf,  # structural; intersectionOf counted above
}


def census(path, fmt=None):
    g = Graph()
    g.parse(path, format=fmt)
    in_v0, out, inert, consumed = Counter(), Counter(), Counter(), Counter()

    # Annotation properties declared by the ontology itself are inert.
    ann_props = set(g.subjects(RDF.type, OWL.AnnotationProperty))
    data_props = set(g.subjects(RDF.type, OWL.DatatypeProperty))
    obj_props = set(g.subjects(RDF.type, OWL.ObjectProperty))
    classes = set(g.subjects(RDF.type, OWL.Class))

    # owl:topObjectProperty / owl:bottomObjectProperty carry built-in role
    # semantics CR1-CR7 do not implement. Treated as ordinary roles, CR3 builds
    # an edge for `A subseteq EXISTS bottomObjectProperty.top` and A is reported
    # SATISFIABLE -- a missed unsatisfiability, i.e. a false pass. Detected here
    # rather than left to the predicate scan below, because they appear as the
    # OBJECT of owl:onProperty, not as a predicate.
    BUILTIN_ROLES = {OWL.topObjectProperty, OWL.bottomObjectProperty}
    for _, _, o in g.triples((None, OWL.onProperty, None)):
        if o in BUILTIN_ROLES:
            out["built-in role (top/bottomObjectProperty)"] += 1

    for s, p, o in g:
        if p == OWL.onProperty and o in BUILTIN_ROLES:
            continue  # already counted above
        if p in (RDFS.subPropertyOf, OWL.equivalentProperty) and (
                s in BUILTIN_ROLES or o in BUILTIN_ROLES):
            out["built-in role (top/bottomObjectProperty)"] += 1
            continue
        # HEADER / REIFICATION FIRST. This ordering is load-bearing, not
        # stylistic: `owl:annotatedTarget` usually carries a Literal, so a
        # literal check placed ahead of this one buckets 350 axiom
        # annotations in RO as "datatype in a logical position" — i.e. it
        # reports a well-formed annotated ontology as one third
        # out-of-profile. That is exactly M0 acceptance (a), and this tool
        # got it wrong on the first attempt.
        if p in HEADER_PRED and p not in IN_V0_EXPR:
            consumed["declaration / header"] += 1
            continue
        if p == OWL.deprecated:
            inert["annotation assertion"] += 1
            continue

        if p == RDF.type:
            if str(o).startswith(str(SWRL)):
                # SWRL rules. NOT in SPEC.md §5.2's disposition table at all,
                # yet present in RO -- a mainstream OBO ontology. They carry
                # logical content v0 cannot process, so out-of-profile is the
                # only safe disposition; silently dropping them is the
                # fail-silent hazard §5.1 exists to prevent.
                out["SWRL rule (NOT IN §5.2 TABLE)"] += 1
                continue
            if o in DECL_TYPES:
                consumed["declaration / header"] += 1
            elif o in OUT_TYPE:
                out[OUT_TYPE[o]] += 1
            elif o in IN_V0_TYPE:
                in_v0[IN_V0_TYPE[o]] += 1
            elif o in classes or isinstance(o, URIRef):
                # ClassAssertion C(a)
                if isinstance(s, BNode):
                    out["anonymous individual"] += 1
                else:
                    in_v0["ClassAssertion"] += 1
            continue

        if p in ann_props or p in (RDFS.label, RDFS.comment, RDFS.seeAlso,
                                   RDFS.isDefinedBy):
            inert["annotation assertion"] += 1
            continue

        if p in OUT_PRED:
            out[OUT_PRED[p]] += 1
            continue

        if p in data_props or isinstance(o, Literal):
            out["datatype / literal in logical position"] += 1
            continue

        if p in IN_V0_EXPR:
            in_v0[IN_V0_EXPR[p]] += 1
            continue

        if p in IN_V0_PRED:
            # domain/range on a DATA property is out-of-profile
            if p in (RDFS.domain, RDFS.range) and s in data_props:
                out["DataPropertyDomain/Range"] += 1
            else:
                in_v0[IN_V0_PRED[p]] += 1
            continue

        if p in HEADER_PRED:
            consumed["declaration / header"] += 1
            continue

        if p in obj_props:
            if isinstance(s, BNode) or isinstance(o, BNode):
                out["anonymous individual"] += 1
            else:
                in_v0["ObjectPropertyAssertion"] += 1
            continue

        inert["other / unrecognized"] += 1

    return g, in_v0, out, inert, consumed


def report(path, fmt=None):
    g, in_v0, out, inert, consumed = census(path, fmt)
    total_logical = sum(in_v0.values()) + sum(out.values())
    print(f"\n{'='*72}\n{path}\n{'='*72}")
    print(f"  triples: {len(g):,}   logical axioms (approx): {total_logical:,}")
    print(f"\n  IN v0            {sum(in_v0.values()):>8,}")
    for k, v in in_v0.most_common():
        print(f"      {k:<52}{v:>8,}")
    print(f"\n  OUT-OF-PROFILE   {sum(out.values()):>8,}", end="")
    if out:
        pct = 100.0 * sum(out.values()) / max(total_logical, 1)
        print(f"   ({pct:.1f}% of logical axioms)")
        for k, v in out.most_common():
            print(f"      {k:<52}{v:>8,}")
    else:
        print("   <- CLEAN, usable without projection")
    print(f"\n  inert            {sum(inert.values()):>8,}")
    print(f"  consumed         {sum(consumed.values()):>8,}")
    return sum(out.values()), total_logical


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
            verdict = "CLEAN" if o == 0 else f"needs projection ({o:,} axioms)"
            print(f"  {p.split('/')[-1]:<44}{verdict}")
