#!/usr/bin/env python3
"""Generate a v0 projection as a REMOVAL LIST (SPEC.md §10 item 2).

A projection is pinned in the repo, never computed on the fly — otherwise
neither the benchmark numbers nor the differential diff are reproducible. But a
projected COPY of GO would be ~124 MB, over GitHub's per-file limit and 50x this
repo's entire history.

So the projection is stored as the set of axioms REMOVED, not as the result.
That is smaller, and it is better: you can read exactly which axioms were
dropped and why, which is precisely what §5.1 demands when it says an
out-of-profile axiom must be enumerated and never silently dropped. A removal
list also shows up in review — a projection that quietly grows appears in a git
diff instead of hiding inside a large blob.

    projected theory  ==  pinned source  minus  this removal list

Out-of-profile detection is imported from census.py rather than reimplemented:
two definitions would let a projection disagree with the census that certified
it, silently.

Usage:
    python3 corpus/project.py <name>...        write corpus/projections/<name>.removals
    python3 corpus/project.py --verify ...     re-derive and compare, exit 1 on drift
    python3 corpus/project.py --materialize .. write corpus/vendor/<name>.v0.ttl, the
                                               projected ontology itself (not committed)
    ... --profile el++                         the same for el++ (SPEC §5.4): removals in
                                               corpus/projections/el++/, the file
                                               corpus/vendor/<name>.el++.ttl

The MANIFEST's figures (in_v0, out_of_profile, projection_removes) are el's and
are checked only under el; an el++ projection is pinned by its removal list,
whose header states its own counts.

THE MATERIALIZED FILE IS PINNED BY CONTENT, NOT BYTES. It is written as Turtle
by rdflib, whose output is not byte-stable (blank-node nesting and order vary),
exactly like the converted corpus .ttl (AD b25fcbb1). What IS pinned: after
writing, the file is parsed back, and its ground-triple sha256 and blank-node
triple count must equal the .removals header's, and census must find nothing
out of profile in it. N-Triples was rejected: HOWL's parser finds `_:label`s by
linear scan, which is quadratic on GO's 862,029 blank-node triples, and
deterministic labels need canonical relabelling (9.3 h on OBI).
"""
import hashlib, os, re, sys
from rdflib import Graph, BNode, URIRef

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from census import (signature, classify_triple, census, inadmissible_chains,  # noqa: E402
                    OUT, IN, _expression_key)
from rdflib import RDF, OWL   # noqa: E402

try:
    import tomllib
except ModuleNotFoundError:
    import tomli as tomllib

HERE = os.path.dirname(os.path.abspath(__file__))
PROFILE = "el"
PROJ = os.path.join(HERE, "projections")


def set_profile(p):
    """Project for one rung: el (the default, corpus/projections/) or el++."""
    global PROFILE, PROJ
    if p not in ("el", "el++"):
        sys.exit(f"unknown profile {p} (el or el++)")
    PROFILE = p
    PROJ = os.path.join(HERE, "projections") if p == "el" else os.path.join(HERE, "projections", p)


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def removal_closure(g, seeds):
    """Expand each out-of-profile seed to every triple that must go with it.

    An OWL axiom is rarely one triple: a restriction, a union or a chain is a
    blank-node structure. Removing the seed alone would leave a dangling
    reference to a half-deleted structure, which is not a smaller ontology --
    it is a malformed one.

    So: pull in a blank node's whole description when it is an OBJECT, and when
    it is a SUBJECT also pull in whatever points AT it, recursively.
    """
    removed, frontier = set(), list(seeds)
    while frontier:
        t = frontier.pop()
        if t in removed:
            continue
        removed.add(t)
        s, _, o = t
        if isinstance(o, BNode):
            frontier.extend(g.triples((o, None, None)))
        if isinstance(s, BNode):
            frontier.extend(g.triples((s, None, None)))
            frontier.extend(g.triples((None, None, s)))
    return removed


def reification_index(g):
    """{(source, property): [(axiom node, target)]} over every owl:Axiom node."""
    index = {}
    for a in g.subjects(RDF.type, OWL.Axiom):
        src, prop, tgt = (g.value(a, OWL.annotatedSource), g.value(a, OWL.annotatedProperty),
                          g.value(a, OWL.annotatedTarget))
        if src is not None and prop is not None and tgt is not None:
            index.setdefault((src, prop), []).append((a, tgt))
    return index


def orphaned_reifications(g, index, removed):
    """{(source, property): [owl:Axiom closure]} for every reification left
    without a surviving axiom to annotate.

    A REMOVED AXIOM'S REIFICATION MUST GO WITH IT. HOWL's stage 0 rebuilds an
    axiom from its reification (annotatedSource / Property / Target), so a
    projection that drops a chain but keeps the chain's owl:Axiom node hands
    HOWL the chain right back — RO had three. The rule is stated from the
    SURVIVORS, not from the removed triple: a reification of (s, p, ·) is kept
    only if its target still matches some surviving (s, p, o). Matching the
    removed triple instead failed whenever the reified copy differed from it at
    all (an extra annotation on the reified list), and the copy survived. The
    reified target of a blank-node structure is a DIFFERENT blank node after
    parsing, so targets match structurally. Only reifications of an (s, p)
    that lost a triple are considered: a reification-only axiom elsewhere is
    the source's own business, not the projection's.
    """
    touched = {(s, p) for s, p, _ in removed}
    out = {}
    for sp in touched:
        survivors = [o for o in g.objects(*sp) if (sp[0], sp[1], o) not in removed]
        for a, tgt in index.get(sp, ()):
            if not any(tgt == o or (isinstance(o, BNode) and isinstance(tgt, BNode)
                                    and _expression_key(g, o) == _expression_key(g, tgt))
                       for o in survivors):
                out.setdefault(sp, []).append(removal_closure(g, [(a, RDF.type, OWL.Axiom)]))
    return out


def norm_key(triple):
    """Order key with blank nodes rendered uniformly, so it cannot depend on
    parser-assigned labels."""
    return " ".join("_:_" if isinstance(n, BNode) else n.n3() for n in triple)


def closure_digest(closure):
    """Short stable id for a blank-node structure, from its CONTENT.

    Needed because several removed axioms can share a named subject and render
    to an identical anchor line -- three ObjectAllValuesFrom restrictions on one
    class produce three identical rows, which is unreadable and hides which
    structure went. Hashing the closure with blank nodes normalised gives a
    label that distinguishes them and is stable across parses, unlike the
    parser's own blank-node labels.
    """
    norm = sorted(
        " ".join("_:_" if isinstance(n, BNode) else n.n3() for n in t)
        for t in closure)
    return hashlib.sha256("\n".join(norm).encode()).hexdigest()[:8]


def anchor_line(g, triple, construct, closure_size, digest):
    """One readable line per removed axiom, anchored at a NAMED entity.

    Blank-node labels are assigned by the parser and differ run to run, so a
    line naming one would not be stable and the file would churn. The anchor is
    therefore the named subject; the blank structure is summarised by size and
    pinned exactly by the hashes in the header.
    """
    s, p, o = triple
    def r(n):
        return f"<{n}>" if isinstance(n, URIRef) else ("_:_" if isinstance(n, BNode)
                                                       else n.n3())
    extra = f"  (+{closure_size - 1} in blank-node closure)" if closure_size > 1 else ""
    return f"{r(s)} {r(p)} {r(o)} .    # {construct} [{digest}]{extra}"


def project(name, version, src_path, expect_sha):
    got = sha256_file(src_path)
    if got != expect_sha:
        sys.exit(f"!! {name}: source hash mismatch — refusing to project\n"
                 f"   expected {expect_sha}\n   got      {got}")

    g = Graph()
    g.parse(src_path, format="turtle" if src_path.endswith(".ttl") else None)
    sig = signature(g, PROFILE)

    # DETERMINISM. Graph iteration order depends on blank-node labelling, which
    # differs between parses, so grouping seeds in iteration order produced a
    # DIFFERENT removal list on every run -- a projection that cannot be
    # re-derived is worse than none, because every benchmark number and
    # differential diff taken against it is unreproducible.
    #
    # Fixed by construction rather than by sorting the output: closures that
    # share a triple are merged into CONNECTED COMPONENTS, which is independent
    # of the order the seeds were discovered in.
    # CHAINS ARE JUDGED ON WHAT THE PROJECTION KEEPS. §5.2's range/composition
    # condition reads the ranges; a range whose filler is out of profile (a
    # union) is removed with its closure, and a chain that failed only because
    # of that range is admissible in the projected theory. So every other
    # removal is computed first, and chain admissibility is decided on the
    # graph that remains.
    first = dict(sig, inadmissible_chains={})
    other = [t for t in g if classify_triple(first, *t)[0] == OUT]
    kept = Graph()
    dropped = removal_closure(g, other)
    for t in g:
        if t not in dropped:
            kept.add(t)
    sig["inadmissible_chains"] = inadmissible_chains(kept, signature(kept, PROFILE) if PROFILE != "el" else None)

    seeds = []
    n_in = 0
    for s_, p_, o_ in g:
        bucket, construct = classify_triple(sig, s_, p_, o_)
        n_in += bucket == IN
        if bucket == OUT:
            seeds.append(((s_, p_, o_), construct))

    parent = {}
    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x
    def union(a, b):
        ra, rb = find(a), find(b)
        if ra != rb:
            parent[rb] = ra

    closures = []
    for triple, construct in seeds:
        cl = removal_closure(g, [triple])
        closures.append((frozenset(cl), construct))
        for t in cl:
            parent.setdefault(t, t)
        root = next(iter(cl))
        for t in cl:
            union(root, t)

    comps = {}
    for cl, construct in closures:
        r = find(next(iter(cl)))
        entry = comps.setdefault(r, [set(), set()])
        entry[0] |= cl
        entry[1].add(construct)

    # Orphaned reifications join the removed axiom they annotated, so the
    # removal list still counts one axiom, anchored where it was.
    removed_so_far = set().union(*[c for c, _ in comps.values()]) if comps else set()
    owner = {}
    for root, (cl, _) in comps.items():
        for s_, p_, _ in cl:
            owner.setdefault((s_, p_), set()).add(root)
    for sp, extra in orphaned_reifications(g, reification_index(g), removed_so_far).items():
        root = min(owner[sp], key=lambda r: min(norm_key(t) for t in comps[r][0]))
        for cl in extra:
            comps[root][0] |= cl

    groups = []
    for _, (cl, constructs) in comps.items():
        # Anchor on a NAMED subject, chosen by a key that renders blank nodes
        # uniformly -- ordering by raw str() would reintroduce the parser's
        # unstable labels through the back door.
        named = [t for t in cl if isinstance(t[0], URIRef)]
        anchor = min(named or list(cl), key=norm_key)
        groups.append((anchor_line(g, anchor, " + ".join(sorted(constructs)),
                                   len(cl), closure_digest(cl)), cl))

    removed = set().union(*[c for _, c in groups]) if groups else set()

    # Collateral: IN-V0 LOGICAL content swept out because it belonged to a
    # removed blank-node structure. Counting every non-OUT triple here would be
    # meaningless -- rdf:first/rdf:rest and owl:Restriction are the removed
    # axiom's own scaffolding and must go with it. Only in-profile logical
    # axioms are a real loss, because they shrink the theory further than the
    # gate would and weaken the differential comparison. Reported, never hidden.
    collateral = sum(1 for t in removed if classify_triple(sig, *t)[0] == IN)

    projected = [t for t in g if t not in removed]
    ground_sha, bnode_triples = ground_digest(projected)
    bnode_sha = bnode_digest(projected)

    body = "\n".join(sorted(line for line, _ in groups))
    header = (
        f"# HOWL {'v0' if PROFILE == 'el' else PROFILE} projection — REMOVAL LIST\n"
        f"#\n"
        f"# projected theory == pinned source MINUS the axioms below.\n"
        f"#\n"
        f"# source                  {os.path.basename(src_path)}\n"
        f"# source_sha256           {expect_sha}\n"
        f"# source_triples          {len(g):,}\n"
        f"# axioms_removed          {len(groups):,}\n"
        f"# triples_removed         {len(removed):,}\n"
        f"# in_v0_swept_in          {collateral:,}"
        f"{'   <- collateral from blank-node closures' if collateral else ''}\n"
        f"# projected_triples       {len(projected):,}\n"
        f"# projected_ground_sha256 {ground_sha}\n"
        f"# projected_bnode_triples {bnode_triples:,}\n"
        f"# projected_bnode_sha256  {bnode_sha}\n"
        f"#\n"
        f"# The ground hash covers every triple with no blank node on either\n"
        f"# end, which is canonical as it stands. The blank-node hash covers the\n"
        f"# rest, with each blank node named by a hash of its own content\n"
        f"# instead of the parser's label -- label-free without URDNA2015,\n"
        f"# which is impractical at this size.\n"
        f"#\n"
        f"# Anchors are named subjects; blank nodes print as _:_ because parser\n"
        f"# -assigned labels differ run to run and would churn the file.\n"
        f"#\n")
    return {"text": header + "\n" + body + "\n", "axioms": len(groups), "triples": len(removed),
            "collateral": collateral, "in_v0": n_in, "out": len(seeds),
            "projected": projected, "ground_sha": ground_sha, "bnode_triples": bnode_triples,
            "bnode_sha": bnode_sha,
            "namespaces": list(g.namespaces())}


def ground_digest(triples):
    """(sha256 of the sorted ground triples, count of blank-node triples).

    The ground part — no blank node at either end — is canonical without
    relabelling, so it is what pins a projection's content across parses."""
    ground = sorted(f"{s.n3()} {p.n3()} {o.n3()} ."
                    for s, p, o in triples
                    if not isinstance(s, BNode) and not isinstance(o, BNode))
    return hashlib.sha256("\n".join(ground).encode()).hexdigest(), len(triples) - len(ground)


def bnode_digest(triples):
    """sha256 of the BLANK-NODE part, with every blank node named by its content.

    The ground hash says nothing about blank-node structure: rewiring a
    restriction's owl:onProperty or an RDF list keeps both the ground hash
    and the triple count. Here each blank node is named by a hash of what it
    says (its outgoing edges, recursively), so the digest is label-free —
    stable across parses — and changes whenever the structure does. Two blank
    nodes that say exactly the same thing get the same name, which is right:
    they are interchangeable content.
    """
    out = {}
    for s, p, o in triples:
        if isinstance(s, BNode):
            out.setdefault(s, []).append((p, o))
    memo, active = {}, set()

    def name(n):
        if n in memo:
            return memo[n]
        if n in active:                      # a cycle: name it by position only
            return "_:cycle"
        active.add(n)
        parts = sorted(f"{p.n3()} {name(o) if isinstance(o, BNode) else o.n3()}"
                       for p, o in out.get(n, ()))
        active.discard(n)
        memo[n] = "_:" + hashlib.sha256("\n".join(parts).encode()).hexdigest()[:24]
        return memo[n]

    lines = sorted(f"{name(s) if isinstance(s, BNode) else s.n3()} {p.n3()} "
                   f"{name(o) if isinstance(o, BNode) else o.n3()} ."
                   for s, p, o in triples if isinstance(s, BNode) or isinstance(o, BNode))
    return hashlib.sha256("\n".join(lines).encode()).hexdigest()


def pinned_header(removals_text):
    """The content pins a .removals header states for its projected theory."""
    def field(k):
        m = re.search(rf"^# {k}\s+(\S+)", removals_text, re.M)
        return m.group(1).replace(",", "") if m else None
    return {"ground_sha": field("projected_ground_sha256"),
            "bnode_triples": int(field("projected_bnode_triples") or -1),
            "bnode_sha": field("projected_bnode_sha256")}


def check_graph(g, pins, path, profile=None):
    """Errors if the parsed graph `g` is not the pinned projected theory: ground
    triples, blank-node structure and count, and census 0 out of profile."""
    profile = profile or PROFILE
    triples = list(g)
    sha, bnodes = ground_digest(triples)
    errors = []
    if sha != pins["ground_sha"]:
        errors.append(f"ground sha256 {sha[:12]}… is not the projection's {str(pins['ground_sha'])[:12]}…")
    if bnodes != pins["bnode_triples"]:
        errors.append(f"{bnodes:,} blank-node triples, the projection has {pins['bnode_triples']:,}")
    bsha = bnode_digest(triples)
    if bsha != pins["bnode_sha"]:
        errors.append(f"blank-node structure {bsha[:12]}… is not the projection's {str(pins['bnode_sha'])[:12]}…")
    _, _, out, _, _ = census(path, graph=g, profile=profile)
    if out:
        errors.append(f"census finds {sum(out.values()):,} out-of-profile triples: {dict(out.most_common(5))}")
    return errors


def materialized_path(e, profile=None):
    profile = profile or PROFILE
    return os.path.join(HERE, "vendor", f"{e['name']}-{e['version']}.{'v0' if profile == 'el' else profile}.ttl")


def removals_path(e, profile=None):
    profile = profile or PROFILE
    base = os.path.join(HERE, "projections") if profile == "el" else os.path.join(HERE, "projections", profile)
    return os.path.join(base, f"{e['name']}-{e['version']}.removals")


def check_materialized(e, r):
    """Errors in the materialized file, read back from disk: [] when it is the projection."""
    path = materialized_path(e)
    g = Graph()
    g.parse(path, format="turtle")
    return check_graph(g, r, path)


def materialize(e, r):
    """Write the projected ontology as Turtle, aside then renamed, and check it."""
    path = materialized_path(e)
    g = Graph()
    for prefix, ns in r["namespaces"]:
        g.bind(prefix, ns, override=True)
    for t in r["projected"]:
        g.add(t)
    g.serialize(path + ".part", format="turtle")
    os.replace(path + ".part", path)
    return check_materialized(e, r)


def main():
    argv = sys.argv[1:]
    if "--profile" in argv:
        i = argv.index("--profile")
        set_profile(argv[i + 1] if i + 1 < len(argv) else "")
        argv = argv[:i] + argv[i + 2:]
    verify = "--verify" in argv
    materializing = "--materialize" in argv
    args = [a for a in argv if not a.startswith("--")]
    spec = tomllib.load(open(os.path.join(HERE, "MANIFEST.toml"), "rb"))
    entries = [e for e in spec["ontology"] if not args or e["name"] in args]
    os.makedirs(PROJ, exist_ok=True)
    rc = 0
    for e in entries:
        # A functional-syntax source is projected from its PINNED derived
        # Turtle (fetch.sh, derived_sha256): rdflib cannot read the source.
        ofn = e.get("format") == "ofn"
        src = os.path.join(HERE, "vendor", f"{e['name']}-{e['version']}.{'ttl' if ofn else 'owl'}")
        pinned_sha = e["derived_sha256"] if ofn else e["sha256"]
        if not os.path.exists(src):
            if verify:
                # A projection that was never checked is not a verified one.
                print(f"  !! MISSING {e['name']}: {os.path.relpath(src, os.getcwd())} is not fetched "
                      f"(run ./corpus/fetch.sh), so its projection and figures are unchecked", file=sys.stderr)
                rc = 1
            else:
                print(f"  skip     {e['name']} (not fetched — run ./corpus/fetch.sh)")
            continue
        out = os.path.join(PROJ, f"{e['name']}-{e['version']}.removals")
        r = project(e["name"], e["version"], src, pinned_sha)
        text, n_ax, n_tr, coll, n_in, n_out = (r["text"], r["axioms"], r["triples"], r["collateral"],
                                               r["in_v0"], r["out"])
        if materializing:
            # Only ever from the PINNED projection: materializing a drifted
            # one would hand every downstream run a theory nobody reviewed.
            old = open(out).read() if os.path.exists(out) else None
            if old != text:
                print(f"  !! DRIFT {e['name']}-{e['version']}: refusing to materialize a projection "
                      f"that differs from the pinned one (run make project, review the diff)", file=sys.stderr)
                rc = 1
                continue
            errors = materialize(e, r)
            for err in errors:
                print(f"  !! MATERIALIZED {e['name']}: {err}", file=sys.stderr)
            if errors:
                rc = 1
            else:
                print(f"  wrote    {os.path.relpath(materialized_path(e), os.getcwd())}  "
                      f"{len(r['projected']):,} triples, ground {r['ground_sha'][:12]}…, census 0 out")
            continue
        if verify:
            failed = False
            old = open(out).read() if os.path.exists(out) else None
            if old != text:
                print(f"  !! DRIFT {e['name']}-{e['version']}: "
                      f"regenerated projection differs from the pinned one", file=sys.stderr)
                failed = True
            # THE MANIFEST'S FIGURES ARE CLAIMS TOO. Nothing checked them, and
            # RO's in_v0/out_of_profile sat two off the census for a slice.
            # They are el's; an el++ projection's own header pins its counts.
            claimed = {} if PROFILE != "el" else {"in_v0": e["in_v0"], "out_of_profile": e["out_of_profile"],
                       "removed axioms": e["projection_removes"]["axioms"],
                       "removed triples": e["projection_removes"]["triples"],
                       "in_v0_swept_in": e["projection_removes"]["in_v0_swept_in"]}
            actual = {} if PROFILE != "el" else {"in_v0": n_in, "out_of_profile": n_out, "removed axioms": n_ax,
                      "removed triples": n_tr, "in_v0_swept_in": coll}
            for k in claimed:
                if claimed[k] != actual[k]:
                    print(f"  !! MANIFEST {e['name']}: {k} = {claimed[k]}, census says {actual[k]}",
                          file=sys.stderr)
                    failed = True
            # A materialized file, when present, must still be the projection.
            if os.path.exists(materialized_path(e)):
                for err in check_materialized(e, r):
                    print(f"  !! MATERIALIZED {e['name']}: {err}", file=sys.stderr)
                    failed = True
            if failed:
                rc = 1
            else:
                print(f"  ok       {e['name']}-{e['version']} ({n_ax:,} axioms removed)")
        else:
            open(out, "w").write(text)
            print(f"  wrote    {os.path.relpath(out, os.getcwd())}  "
                  f"{n_ax:,} axioms / {n_tr:,} triples removed"
                  f"{f', {coll:,} in-v0 swept in' if coll else ''}")
    sys.exit(rc)


if __name__ == "__main__":
    main()
