#!/usr/bin/env bash
# Fetch and verify the pinned external ontologies in MANIFEST.toml.
#
# Hash verification is the point, not a formality: without it a moving PURL
# silently swaps the corpus under a benchmark and nothing announces it.
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

rc = 0
for e in entries:
    dest = os.path.join(vendor, f"{e['name']}-{e['version']}.owl")
    if os.path.exists(dest) and sha256(dest) == e["sha256"]:
        print(f"  ok       {e['name']}-{e['version']} (cached)")
        continue
    print(f"  fetching {e['name']}-{e['version']}  ({e['bytes']/1e6:.0f} MB)")
    subprocess.run(["curl", "-sSL", "--fail", "--max-time", "1800",
                    "-o", dest, e["url"]], check=True)
    got = sha256(dest)
    if got != e["sha256"]:
        # Loud, and it does NOT delete the file — inspect it before assuming
        # a bad download. The usual cause is a re-released versioned PURL,
        # which is a corpus-integrity event, not a transient error.
        print(f"  !! HASH MISMATCH {e['name']}-{e['version']}\n"
              f"     expected {e['sha256']}\n     got      {got}\n"
              f"     kept at  {dest}", file=sys.stderr)
        rc = 1
        continue
    print(f"  verified {e['name']}-{e['version']}")
sys.exit(rc)
PY
