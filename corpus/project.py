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
    python3 corpus/project.py <name>...     write corpus/projections/<name>.removals
    python3 corpus/project.py --verify ...  re-derive and compare, exit 1 on drift
"""
import hashlib, os, sys
from rdflib import Graph, BNode, URIRef

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from census import signature, classify_triple, OUT, IN   # noqa: E402

try:
    import tomllib
except ModuleNotFoundError:
    import tomli as tomllib

HERE = os.path.dirname(os.path.abspath(__file__))
PROJ = os.path.join(HERE, "projections")


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
    g.parse(src_path)
    sig = signature(g)

    # DETERMINISM. Graph iteration order depends on blank-node labelling, which
    # differs between parses, so grouping seeds in iteration order produced a
    # DIFFERENT removal list on every run -- a projection that cannot be
    # re-derived is worse than none, because every benchmark number and
    # differential diff taken against it is unreproducible.
    #
    # Fixed by construction rather than by sorting the output: closures that
    # share a triple are merged into CONNECTED COMPONENTS, which is independent
    # of the order the seeds were discovered in.
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
    ground = sorted(f"{s.n3()} {p.n3()} {o.n3()} ."
                    for s, p, o in projected
                    if not isinstance(s, BNode) and not isinstance(o, BNode))
    bnode_triples = len(projected) - len(ground)
    ground_sha = hashlib.sha256("\n".join(ground).encode()).hexdigest()

    body = "\n".join(sorted(line for line, _ in groups))
    header = (
        f"# HOWL v0 projection — REMOVAL LIST\n"
        f"#\n"
        f"# projected theory == pinned source MINUS the axioms below.\n"
        f"#\n"
        f"# source                  {name}-{version}.owl\n"
        f"# source_sha256           {expect_sha}\n"
        f"# source_triples          {len(g):,}\n"
        f"# axioms_removed          {len(groups):,}\n"
        f"# triples_removed         {len(removed):,}\n"
        f"# in_v0_swept_in          {collateral:,}"
        f"{'   <- collateral from blank-node closures' if collateral else ''}\n"
        f"# projected_triples       {len(projected):,}\n"
        f"# projected_ground_sha256 {ground_sha}\n"
        f"# projected_bnode_triples {bnode_triples:,}\n"
        f"#\n"
        f"# The ground hash covers every triple with no blank node on either\n"
        f"# end -- the overwhelming majority, and the part that is canonical\n"
        f"# without URDNA2015, which is impractical at this size. Blank-node\n"
        f"# triples are pinned by count plus the source hash and this file.\n"
        f"#\n"
        f"# Anchors are named subjects; blank nodes print as _:_ because parser\n"
        f"# -assigned labels differ run to run and would churn the file.\n"
        f"#\n")
    return header + "\n" + body + "\n", len(groups), len(removed), collateral, n_in, len(seeds)


def main():
    verify = "--verify" in sys.argv
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    spec = tomllib.load(open(os.path.join(HERE, "MANIFEST.toml"), "rb"))
    entries = [e for e in spec["ontology"] if not args or e["name"] in args]
    os.makedirs(PROJ, exist_ok=True)
    rc = 0
    for e in entries:
        src = os.path.join(HERE, "vendor", f"{e['name']}-{e['version']}.owl")
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
        text, n_ax, n_tr, coll, n_in, n_out = project(e["name"], e["version"], src, e["sha256"])
        if verify:
            old = open(out).read() if os.path.exists(out) else None
            if old != text:
                print(f"  !! DRIFT {e['name']}-{e['version']}: "
                      f"regenerated projection differs from the pinned one", file=sys.stderr)
                rc = 1
            # THE MANIFEST'S FIGURES ARE CLAIMS TOO. Nothing checked them, and
            # RO's in_v0/out_of_profile sat two off the census for a slice.
            claimed = {"in_v0": e["in_v0"], "out_of_profile": e["out_of_profile"],
                       "removed axioms": e["projection_removes"]["axioms"],
                       "removed triples": e["projection_removes"]["triples"],
                       "in_v0_swept_in": e["projection_removes"]["in_v0_swept_in"]}
            actual = {"in_v0": n_in, "out_of_profile": n_out, "removed axioms": n_ax,
                      "removed triples": n_tr, "in_v0_swept_in": coll}
            for k in claimed:
                if claimed[k] != actual[k]:
                    print(f"  !! MANIFEST {e['name']}: {k} = {claimed[k]}, census says {actual[k]}",
                          file=sys.stderr)
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
