#!/usr/bin/env bash
# Fetch and verify the pinned external ontologies in MANIFEST.toml, then derive
# the Turtle HOWL actually reads.
#
# Hash verification is the point, not a formality: without it a moving PURL
# silently swaps the corpus under a benchmark and nothing announces it.
#
# ONLY THE SOURCE IS PINNED. HOWL reads Turtle alone (SPEC.md §6.1), so each
# verified .owl gets a sibling .ttl converted with rdflib. That .ttl is NOT
# hashed: rdflib's Turtle output is not deterministic (two conversions of RO
# hash differently), and canonical blank-node relabelling — which is — took
# 26 s on RO and 9.3 hours on OBI. MANIFEST.toml pins the converter version
# instead, and this script warns when the installed one differs.
set -euo pipefail

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
VENDOR="$DIR/vendor"
mkdir -p "$VENDOR"

python3 - "$DIR/MANIFEST.toml" "$VENDOR" "$@" <<'PY'
import hashlib, subprocess, sys, os
try:
    import tomllib
except ModuleNotFoundError:
    import tomli as tomllib

manifest, vendor, *want = sys.argv[1:]
spec = tomllib.load(open(manifest, "rb"))
entries = spec["ontology"]
if want:
    entries = [e for e in entries if e["name"] in want]
    missing = set(want) - {e["name"] for e in entries}
    if missing:
        sys.exit(f"unknown ontology: {', '.join(sorted(missing))}")

def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()

def convert(owl):
    """RDF/XML -> Turtle beside the verified source, skipped when up to date."""
    ttl = owl[:-len(".owl")] + ".ttl"
    name = os.path.basename(ttl)
    if os.path.exists(ttl) and os.path.getmtime(ttl) >= os.path.getmtime(owl):
        print(f"  ok       {name} (converted)")
        return
    import rdflib
    pinned = spec.get("converter_rdflib")
    if pinned and rdflib.__version__ != pinned:
        print(f"  !! rdflib {rdflib.__version__} differs from the pinned {pinned}; "
              f"the derived Turtle may differ in content", file=sys.stderr)
    g = rdflib.Graph()
    g.parse(owl, format="xml")
    # Written aside and renamed, so an interrupted conversion never leaves a
    # truncated .ttl whose mtime makes it look current.
    part = ttl + ".part"
    g.serialize(part, format="turtle")
    os.replace(part, ttl)
    print(f"  wrote    {name}  ({len(g):,} triples, rdflib {rdflib.__version__})")

rc = 0
for e in entries:
    dest = os.path.join(vendor, f"{e['name']}-{e['version']}.owl")
    if os.path.exists(dest) and sha256(dest) == e["sha256"]:
        print(f"  ok       {e['name']}-{e['version']} (cached)")
        convert(dest)
        continue
    print(f"  fetching {e['name']}-{e['version']}  ({e['bytes']/1e6:.0f} MB)")
    subprocess.run(["curl", "-sSL", "--fail", "--max-time", "1800",
                    "-o", dest, e["url"]], check=True)
    got = sha256(dest)
    if got != e["sha256"]:
        # Loud, and it does NOT delete the file — inspect it before assuming
        # a bad download. The usual cause is a re-released versioned PURL,
        # which is a corpus-integrity event, not a transient error. Nothing
        # is converted from an unverified source.
        print(f"  !! HASH MISMATCH {e['name']}-{e['version']}\n"
              f"     expected {e['sha256']}\n     got      {got}\n"
              f"     kept at  {dest}", file=sys.stderr)
        rc = 1
        continue
    print(f"  verified {e['name']}-{e['version']}")
    convert(dest)
sys.exit(rc)
PY
