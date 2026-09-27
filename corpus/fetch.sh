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

def convert_ofn(owl, e):
    """Functional syntax -> Turtle through the pinned OWL API, and the result
    checked against derived_sha256: that conversion is deterministic, so its
    output is pinned, not just its converter."""
    ttl = owl[:-len(".owl")] + ".ttl"
    name = os.path.basename(ttl)
    if os.path.exists(ttl) and sha256(ttl) == e["derived_sha256"]:
        print(f"  ok       {name} (converted, derived sha256 matches)")
        return 0
    sys.path.insert(0, os.path.dirname(manifest))
    import conformance
    lossy = conformance.fss_repeated_operands(owl)
    if lossy:
        # The OWL API would collapse these on load, handing HOWL a smaller
        # theory than the source states (differential.owlapi_blind_spots).
        print(f"  !! {name}: repeated pairwise operands in {', '.join(lossy)}; "
              f"the OWL API conversion would be lossy", file=sys.stderr)
        return 1
    oracle = os.path.join(os.path.dirname(os.path.dirname(manifest)), "oracle", "build", "oracle")
    if not os.path.exists(oracle):
        print(f"  !! {name}: needs the oracle to convert functional syntax (run make oracle)",
              file=sys.stderr)
        return 1
    out = ttl + ".d"
    p = subprocess.run([oracle, "convert", "--out", out, owl], capture_output=True, text=True)
    produced = os.path.join(out, name)
    if p.returncode != 0 or p.stderr.strip() or not os.path.exists(produced):
        print(f"  !! {name}: oracle convert failed:\n{p.stdout}{p.stderr}", file=sys.stderr)
        return 1
    got = sha256(produced)
    if got != e["derived_sha256"]:
        print(f"  !! DERIVED HASH MISMATCH {name}\n     expected {e['derived_sha256']}\n"
              f"     got      {got}\n     kept at  {produced}", file=sys.stderr)
        return 1
    os.replace(produced, ttl)
    os.rmdir(out)
    print(f"  wrote    {name}  (OWL API, derived sha256 verified)")
    return 0

def convert(owl, e):
    """The verified source -> Turtle beside it, skipped when up to date."""
    if e.get("format") == "ofn":
        return convert_ofn(owl, e)
    ttl = owl[:-len(".owl")] + ".ttl"
    name = os.path.basename(ttl)
    if os.path.exists(ttl) and os.path.getmtime(ttl) >= os.path.getmtime(owl):
        print(f"  ok       {name} (converted)")
        return 0
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
    return 0

rc = 0
for e in entries:
    dest = os.path.join(vendor, f"{e['name']}-{e['version']}.owl")
    if os.path.exists(dest) and sha256(dest) == e["sha256"]:
        print(f"  ok       {e['name']}-{e['version']} (cached)")
        rc |= convert(dest, e)
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
    rc |= convert(dest, e)
sys.exit(rc)
PY
