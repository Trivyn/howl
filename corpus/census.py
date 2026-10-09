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
import os
import sys
from collections import Counter
from rdflib import Graph, RDF, RDFS, OWL, BNode, URIRef, Literal, Namespace
from rdflib.collection import Collection

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import profiles  # noqa: E402

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
    # The n-ary spelling of DisjointClasses. Once filed as a declaration, which
    # hid it from construct routing: a corpus entry whose only disjointness is
    # n-ary looked disjointness-free (caught by the probe label check).
    OWL.AllDisjointClasses: "DisjointClasses",
}
DECL_TYPES = {
    OWL.Class, OWL.ObjectProperty, OWL.NamedIndividual, OWL.AnnotationProperty,
    OWL.DatatypeProperty, RDFS.Datatype, OWL.Ontology, OWL.Restriction,
    OWL.Axiom, OWL.Annotation, RDF.List,
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


def _expression_key(g, t, seen=()):
    """A class expression as a structural key: an IRI by value, a blank node by
    what it says. "The same class expression" of SPEC §5.2's range/composition
    condition is syntactic, so two blank nodes spelling the same ∃r.C match.
    A conjunction is keyed by its members alone, in order, so that the positive
    part of a negated range (below) and a conjunction written out directly
    compare as the same expression. rdf:type is not part of the key: HOWL's
    decoder reads `[ a owl:Restriction ; ... ]` and `[ ... ]` as one concept,
    and a key that told them apart would refuse a chain HOWL accepts."""
    if not isinstance(t, BNode) or t in seen:
        return str(t)
    head = g.value(t, OWL.intersectionOf)
    if head is not None:
        return ("and",) + tuple(_expression_key(g, m, seen + (t,)) for m in Collection(g, head))
    return tuple(sorted((str(p), _expression_key(g, o, seen + (t,)))
                        for p, o in g.predicate_objects(t) if p != RDF.type))


# NEGATION IN POSITIVE POSITIONS (SPEC.md §5.2's negation rewrite). ¬E as the
# whole object of rdfs:subClassOf / rdfs:domain / rdfs:range, or a member of
# the owl:intersectionOf list that is such an object, is rewritten into EL
# (C ⊓ E ⊑ ⊥, ∃r.⊤ ⊓ E ⊑ ⊥, ∃r.E ⊑ ⊥). Anywhere else a complement is out.
POSITIVE_PRED = (RDFS.subClassOf, RDFS.domain, RDFS.range)


def _conjuncts(g, c):
    """c's top-level conjuncts: the members of its intersection, else c."""
    head = g.value(c, OWL.intersectionOf) if isinstance(c, BNode) else None
    return list(Collection(g, head)) if head is not None else [c]


def _only_positive(g, n, own):
    """Is every reference to n the object of a positive predicate, and does n
    say nothing but `own` (its constructor) and rdf:type? A blank node that is
    also, say, the SUBJECT of rdfs:subClassOf sits on the left of that axiom."""
    refs = list(g.subject_predicates(n))
    return (bool(refs) and all(p in POSITIVE_PRED for _, p in refs)
            and all(p in (own, RDF.type) for p in g.predicates(n)))


def positive_complements(g):
    """Complement nodes the negation rewrite takes. A node referenced from
    anywhere else too (a shared blank node) is not one. DELIBERATELY STRICTER
    than HOWL there: HOWL decodes each reference separately and rewrites the
    positive one, but the census gives the complementOf TRIPLE one disposition,
    so it marks it out and a projection drops both axioms. That can only remove
    an axiom HOWL would keep, never keep one HOWL would omit."""
    out = set()
    for c in set(g.subjects(OWL.complementOf, None)):
        if _only_positive(g, c, OWL.complementOf):
            out.add(c)
            continue
        # A member of a positive conjunction: c's one reference is an
        # rdf:first cell of the intersection's list; walk back to its head.
        refs = list(g.subject_predicates(c))
        if len(refs) != 1 or refs[0][1] != RDF.first or not all(
                p in (OWL.complementOf, RDF.type) for p in g.predicates(c)):
            continue
        cell = refs[0][0]
        while True:
            back = list(g.subjects(RDF.rest, cell))
            if len(back) != 1:
                break
            cell = back[0]
        owners = list(g.subjects(OWL.intersectionOf, cell))
        if len(owners) == 1 and _only_positive(g, owners[0], OWL.intersectionOf):
            out.add(c)
    return out


def _tree(g, t, seen=()):
    """Every triple of a class expression's blank-node tree."""
    if not isinstance(t, BNode) or t in seen:
        return
    for p, o in g.predicate_objects(t):
        yield t, p, o
        yield from _tree(g, o, seen + (t,))


def inadmissible_chains(g, sig=None):
    """{(t, list head): reason} for every property chain that is not a v0
    chain: malformed (fewer than two named roles), or violating SPEC §5.2's
    range/composition condition, implemented from the SPEC, not from HOWL:

        for every  r1 o ... o rn  subPropertyOf t :
            every range imposed on t   is also imposed on rn   (the same C)

    where "imposed on" goes up the reflexive-transitive closure of TOLD
    rdfs:subPropertyOf (owl:equivalentProperty read both ways). It is the OWL
    2 EL global restriction on chains and ranges: CR7's composed edge reuses
    the s-edge's target, which was built to satisfy range(rn) only, so a
    range on t that rn does not share would be silently unmet. A chain with a
    non-IRI step (an inverse) is out of profile already and not judged here.

    "Imposed" is judged on the theory AFTER the negation rewrite, as HOWL's gate
    judges it: a range C ⊓ ¬E imposes only C (¬E became the GCI ∃r.E ⊑ ⊥,
    which ranges never touch), and a range that is only ¬E imposes nothing. A
    range the rewrite cannot take (some part of it is out of profile) is left
    as written and imposes its whole filler.
    """
    sig = sig or _base_signature(g)
    positive = sig["positive_complements"]

    def range_keys(c):
        conj = _conjuncts(g, c)
        if not any(m in positive for m in conj) or any(
                classify_triple(sig, *t)[0] == OUT for t in _tree(g, c)):
            return {_expression_key(g, c)}
        kept = [m for m in conj if m not in positive]
        if not kept:
            return set()
        if len(kept) == 1:
            return {_expression_key(g, kept[0])}
        return {("and",) + tuple(_expression_key(g, m) for m in kept)}

    up = {}
    for a, b in g.subject_objects(RDFS.subPropertyOf):
        up.setdefault(a, set()).add(b)
    for a, b in g.subject_objects(OWL.equivalentProperty):
        up.setdefault(a, set()).add(b)
        up.setdefault(b, set()).add(a)
    ranges = {}
    for r, c in g.subject_objects(RDFS.range):
        ranges.setdefault(r, set()).update(range_keys(c))

    def imposed(r):
        seen, todo, out = {r}, [r], set()
        while todo:
            x = todo.pop()
            out |= ranges.get(x, set())
            for y in up.get(x, ()):
                if y not in seen:
                    seen.add(y)
                    todo.append(y)
        return out

    bad = {}
    for t, head in g.subject_objects(OWL.propertyChainAxiom):
        steps = list(Collection(g, head))
        # An inverse step or super-role is out of profile already (its
        # owl:inverseOf triple is a seed, and the chain goes with it). Any
        # OTHER non-IRI operand, or fewer than two steps, is not a v0 chain.
        inverse = lambda x: isinstance(x, BNode) and (x, OWL.inverseOf, None) in g
        if any(inverse(x) for x in steps + [t]):
            continue
        if len(steps) < 2 or not all(isinstance(x, URIRef) for x in steps) or not isinstance(t, URIRef):
            bad[(t, head)] = "ObjectPropertyChain (malformed: fewer than two named roles)"
        # Built-in roles in a chain, which HOWL's gate checks at the role:
        # under el both are out; under el++ the empty role is in, and a
        # chain INTO the universal role is a tautology, dropped before here
        # (classify_triple), so only the universal role as a step is out.
        elif any(x in BUILTIN_ROLES for x in steps + [t]) and (
                sig.get("profile", "el") == "el" or OWL.topObjectProperty in steps):
            bad[(t, head)] = "built-in role (top/bottomObjectProperty)"
        elif not imposed(t) <= imposed(steps[-1]):
            bad[(t, head)] = "ObjectPropertyChain (range/composition condition)"
    return bad


PROFILES = profiles.BUILT


def signature(g, profile="el"):
    """Declared entity sets, needed to disposition a triple in context, for
    one rung: `el` (SPEC.md §5.2) or `el++` (§5.4)."""
    if profile not in PROFILES:
        raise ValueError(f"unknown profile {profile!r}; expected one of {PROFILES}")
    sig = _base_signature(g)
    sig["profile"] = profile
    if profile == "el++":
        sig.update(_el_plus_plus_signature(g))
    sig["inadmissible_chains"] = inadmissible_chains(g, sig)
    return sig


def _non_simple_roles(g):
    """OWL 2 Structural Specification §11.1, over the told RBox: a role is
    composite if it is a built-in, the super-role of a property chain, or
    transitive; non-simple if composite or it has a non-simple sub-role
    (owl:equivalentProperty read both ways). SPEC.md §5.4 admits
    ObjectHasSelf only on a simple role."""
    out = set(BUILTIN_ROLES)
    out |= set(g.subjects(OWL.propertyChainAxiom, None))
    out |= set(g.subjects(RDF.type, OWL.TransitiveProperty))
    up = {}
    for a, b in g.subject_objects(RDFS.subPropertyOf):
        up.setdefault(a, set()).add(b)
    for a, b in g.subject_objects(OWL.equivalentProperty):
        up.setdefault(a, set()).add(b)
        up.setdefault(b, set()).add(a)
    todo = list(out)
    while todo:
        x = todo.pop()
        for y in up.get(x, ()):
            if y not in out:
                out.add(y)
                todo.append(y)
    return out


RESERVED_NS = (str(OWL), str(RDF), str(RDFS), str(SWRL), "http://www.w3.org/2001/XMLSchema#")


def _named(t):
    """A named individual: an IRI outside the reserved namespaces — the same
    five as HOWL's is-reserved-iri (OWL, RDF, RDFS, SWRL, XSD)."""
    return isinstance(t, URIRef) and not str(t).startswith(RESERVED_NS)


def _el_plus_plus_signature(g):
    """What SPEC.md §5.4 adds, read off the graph: which nodes are a
    one-individual oneOf, a Self on a simple role, an all-named AllDifferent,
    and an object-form NegativePropertyAssertion."""
    nonsimple = _non_simple_roles(g)
    one_of = {s for s, h in g.subject_objects(OWL.oneOf)
              if len(members := list(Collection(g, h))) == 1 and _named(members[0])}
    self_simple = {s for s in g.subjects(OWL.hasSelf, None)
                   if (r := g.value(s, OWL.onProperty)) is not None
                   and isinstance(r, URIRef) and r not in nonsimple}
    all_different = {s for s in g.subjects(RDF.type, OWL.AllDifferent)
                     if (ms := [m for h in list(g.objects(s, OWL.members)) + list(g.objects(s, OWL.distinctMembers))
                                for m in Collection(g, h)])
                     and len(ms) >= 2 and all(_named(m) for m in ms)}
    npa = set()
    for x in g.subjects(RDF.type, OWL.NegativePropertyAssertion):
        src = list(g.objects(x, OWL.sourceIndividual))
        prop = list(g.objects(x, OWL.assertionProperty))
        tgt = list(g.objects(x, OWL.targetIndividual))
        if (len(src) == len(prop) == len(tgt) == 1 and not list(g.objects(x, OWL.targetValue))
                and _named(src[0]) and _named(tgt[0]) and isinstance(prop[0], URIRef)
                and prop[0] != OWL.topObjectProperty):
            npa.add(x)
    return {"one_of_single": one_of, "self_simple": self_simple,
            "all_different_named": all_different, "npa_object": npa}


def _base_signature(g):
    """The signature without the chain verdicts, which are judged over it."""
    # The built-in data properties are data properties without a declaration,
    # as HOWL's add-builtins (decode.slop) registers them.
    data = set(g.subjects(RDF.type, OWL.DatatypeProperty)) | {OWL.topDataProperty, OWL.bottomDataProperty}
    return {
        "ann":     set(g.subjects(RDF.type, OWL.AnnotationProperty)),
        "data":    data,
        "obj":     set(g.subjects(RDF.type, OWL.ObjectProperty)),
        "classes": set(g.subjects(RDF.type, OWL.Class)),
        # Restrictions ON A DATA PROPERTY. owl:someValuesFrom is spelled the
        # same for DataSomeValuesFrom as for ObjectSomeValuesFrom; only the
        # restriction's owl:onProperty tells them apart, and a predicate-only
        # table would count the data one as in v0.
        "data_restrictions": {s for s, o in g.subject_objects(OWL.onProperty) if o in data},
        "inadmissible_chains": {},
        "positive_complements": positive_complements(g),
        # AllDisjointClasses nodes with fewer than two members. OWL 2's mapping
        # requires at least two, so such a node is no DisjointClasses axiom;
        # HOWL decodes it as unrecognized (out-of-profile/disjoint-arity.ttl).
        "short_disjoint": {
            s for s in g.subjects(RDF.type, OWL.AllDisjointClasses)
            if len([m for h in g.objects(s, OWL.members) for m in Collection(g, h)]) < 2
        },
    }


def _classify_el_plus_plus(sig, s, p, o):
    """SPEC.md §5.4's additions to the table, or None when §5.2 decides.
    Checked BEFORE §5.2's rules, because they move triples out of OUT."""
    if p == OWL.onProperty and o == OWL.bottomObjectProperty:
        return IN, "built-in role (bottomObjectProperty)"
    if p in (RDFS.subPropertyOf, OWL.equivalentProperty) and OWL.bottomObjectProperty in (s, o) \
            and OWL.topObjectProperty not in (s, o):
        return IN, "built-in role (bottomObjectProperty)"
    # Inclusions into the universal role are tautologies, dropped (§5.4 K0).
    if p == RDFS.subPropertyOf and o == OWL.topObjectProperty:
        return INERT, "inclusion into owl:topObjectProperty (tautology)"
    if p == OWL.propertyChainAxiom and s == OWL.topObjectProperty:
        return INERT, "inclusion into owl:topObjectProperty (tautology)"
    if p == OWL.hasValue and isinstance(o, URIRef) and s not in sig["data_restrictions"]:
        return (IN, "ObjectHasValue") if _named(o) else None
    if p == OWL.oneOf and s in sig["one_of_single"]:
        return IN, "ObjectOneOf (one individual)"
    if p == OWL.hasSelf and s in sig["self_simple"]:
        return IN, "ObjectHasSelf (simple role)"
    if p == RDF.type and o == OWL.ReflexiveProperty and isinstance(s, URIRef) and s not in BUILTIN_ROLES:
        return IN, "ReflexiveObjectProperty"
    if p in (OWL.sameAs, OWL.differentFrom) and _named(s) and _named(o):
        return IN, "SameIndividual" if p == OWL.sameAs else "DifferentIndividuals"
    if p == RDF.type and o == OWL.AllDifferent and s in sig["all_different_named"]:
        return IN, "DifferentIndividuals"
    if p == RDF.type and o == OWL.NegativePropertyAssertion and s in sig["npa_object"]:
        return IN, "NegativeObjectPropertyAssertion"
    return None


def classify_triple(sig, s, p, o):
    """(bucket, construct) for one triple. THE disposition table, in code."""
    if sig.get("profile") == "el++":
        decided = _classify_el_plus_plus(sig, s, p, o)
        if decided is not None:
            return decided
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
    if p == OWL.someValuesFrom and s in sig["data_restrictions"]:
        return OUT, "DataSomeValuesFrom"
    # The property axioms share their spelling between object and data
    # properties; only the operands' declared kind separates them. Read as
    # object-property axioms, OBI's SubDataPropertyOf counted as in v0 while
    # HOWL's gate (rightly) omitted it.
    if p in (RDFS.subPropertyOf, OWL.equivalentProperty) and (s in sig["data"] or o in sig["data"]):
        return OUT, "SubDataPropertyOf / EquivalentDataProperties"
    if p == OWL.propertyChainAxiom and (s, o) in sig["inadmissible_chains"]:
        return OUT, sig["inadmissible_chains"][(s, o)]
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
        if o == OWL.AllDisjointClasses and s in sig["short_disjoint"]:
            return OUT, "AllDisjointClasses with fewer than two members"
        if o in IN_V0_TYPE:
            return IN, IN_V0_TYPE[o]
        # A blank-node object is an anonymous class expression -- the only
        # thing the OWL 2 RDF mapping types a resource with anonymously -- so
        # `:a a [ owl:someValuesFrom ... ]` is a ClassAssertion, not inert.
        if o in sig["classes"] or isinstance(o, (URIRef, BNode)):
            if isinstance(s, BNode):
                return OUT, "anonymous individual"
            return IN, "ClassAssertion"
        return INERT, "other / unrecognized"

    if p in sig["ann"] or p in (RDFS.label, RDFS.comment, RDFS.seeAlso,
                               RDFS.isDefinedBy):
        return INERT, "annotation assertion"
    if p == OWL.complementOf and s in sig["positive_complements"]:
        return IN, "ObjectComplementOf (positive position)"
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


def census(path, fmt=None, graph=None, profile="el"):
    g = graph if graph is not None else Graph()
    if graph is None:
        g.parse(path, format=fmt)
    sig = signature(g, profile)
    buckets = {IN: Counter(), OUT: Counter(), INERT: Counter(), CONSUMED: Counter()}
    for s, p, o in g:
        bucket, construct = classify_triple(sig, s, p, o)
        buckets[bucket][construct] += 1
    return g, buckets[IN], buckets[OUT], buckets[INERT], buckets[CONSUMED]


def report(path, fmt=None, profile="el"):
    g, in_v0, out, inert, consumed = census(path, fmt, profile=profile)
    total = sum(in_v0.values()) + sum(out.values())
    print(f"\n{'='*72}\n{path}\n{'='*72}")
    print(f"  triples: {len(g):,}   logical axioms (approx): {total:,}")
    print(f"\n  IN {'v0' if profile == 'el' else profile:<13} {sum(in_v0.values()):>8,}")
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
    args = sys.argv[1:]
    profile = "el"
    if args[:1] == ["--profile"]:
        profile, args = args[1], args[2:]
    results = []
    for p in args:
        try:
            results.append((p, *report(p, profile=profile)))
        except Exception as e:
            print(f"\n!! {p}: {type(e).__name__}: {e}")
    if len(results) > 1:
        print(f"\n{'='*72}\nSUMMARY — {'v0' if profile == 'el' else profile} fitness\n{'='*72}")
        for p, o, t in results:
            print(f"  {p.split('/')[-1]:<44}"
                  f"{'CLEAN' if o == 0 else f'needs projection ({o:,} axioms)'}")
